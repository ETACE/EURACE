#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"
#include "math.h"


/************Firm Role: Financial Management Role ********************************/

/*
 * \fn: int Firm_compute_income_statement()
 * \brief: This function computes the income statement of the firm.
 */
int Firm_compute_income_statement()
{
	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{
		//was: EARNINGS = CUM_TOTAL_SOLD_QUANTITY*PRICE - COSTS;
		EBIT= CUM_TOTAL_SOLD_QUANTITY*PRICE - COSTS;		
		
		//update the cash holdings
		PAYMENT_ACCOUNT += CUM_TOTAL_SOLD_QUANTITY*PRICE;
	}

	return 0;
}

/*
 * \fn: int Firm_compute_balance_sheet()
 * \brief: This function computes the balance sheet of the firm:
 *  - debt_installment_payments
 *  - total_debt_installment_payment
 *  - interest_payments
 *  - tax_payment
 *  - total_dividend_payment
 *  - value_capital_stock
 *  - value_inventory_stock
 *  - equity
 */	
int Firm_compute_balance_sheet()
{
	double debt_installment_payment;
	int bank_id;
	double sum;

	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{
		//double PAYMENT_ACCOUNT: account out of which payments are made, to be separated from the income_account on which current sale receipts are incoming
		//CASH_HOLDINGS: equal to payment_account???? Cash holdings is a ambiguous term.

		//double TOTAL_DEBT_PAYMENT
		//double TOTAL_INTEREST_PAYMENT
		//double_array DEBT_INSTALLMENT_PAYMENTS		

		//struct DEBT_INSTALL_PAYMENTS		: array of structs with each struct a loan
		//int bank_id						: bank at which the loan was obtained
		//double loan_value					: total value of the loan remaining
		//double interest_rate				: interest for this loan
		//double interest_payment			: interest to be paid this period
		//double debt_installment_payment	: installment payment per period
		//int nr_periods_before_maturity 	: nr of periods to go before the loan has to be fully repaid

		//compute total debt installment payments
		TOTAL_DEBT_INSTALLMENT_PAYMENT =0;
		for (i=0; i<imax;i++)
		{
			//add to total
			TOTAL_DEBT_INSTALLMENT_PAYMENT += DEBT_INSTALLMENT_PAYMENTS->array[i]->debt_installment_payment;
		}

		//compute TOTAL_INTEREST_PAYMENT
		imax = DEBT_INSTALLMENT_PAYMENTS->size;
		TOTAL_INTEREST_PAYMENT =0;
		for (i=0; i<imax;i++)
		{
			DEBT_INSTALLMENT_PAYMENTS->array[i]->interest_payment = DEBT_INSTALLMENT_PAYMENTS->array[i]->interest_rate * DEBT_INSTALL_PAYMENTS->array[i]->loan_value;							

			//add to total
			TOTAL_INTEREST_PAYMENT += DEBT_INSTALLMENT_PAYMENTS->array[i]->interest_payment;
		}
		
		//continue balance sheet
		EARNINGS = EBIT - TOTAL_INTEREST_PAYMENT;
		TAX_PAYMENT = TAX_RATE_CORPORATE * EARNINGS;
		NET_EARNINGS = EARNINGS - TAX_PAYMENT;
		
		//Actual payment of tax_payment
		add_tax_payment_message(ID, gov_id, TAX_PAYMENT,MSGDATA);
		
		//Actual payment of interest_payment and debt_installment_payment
		if (PAYMENT_ACCOUNT < TOTAL_DEBT_PAYMENT)
		{
			//Code: transform debt into equity
			//Code: debt is repaid partially
			//Code: compute debt remaining to be paid

			PAYMENT_ACCOUNT = 0;
		}
		else
		{
			//Sending interest_payment_msg to all banks at which the firm has a loan 
			imax = DEBT_INSTALLMENT_PAYMENTS->size;
			for (i=0; i<imax;i++)
			{
				//subtract the interest_payment from the payment_account
				PAYMENT_ACCOUNT -= DEBT_INSTALLMENT_PAYMENTS->array[i]->interest_payment;

				//tell the bank I paid
				add_interest_payment_message(ID, bank_id, DEBT_INSTALLMENT_PAYMENTS->array[i]->interest_payment,MSGDATA);
			}
			
			//Sending debt_installment_payment_msg to all banks at which the firm has a loan
			for (i=0; i<imax;i++)
			{
				//pay the installment from the payment_account
				PAYMENT_ACCOUNT -= DEBT_INSTALLMENT_PAYMENTS->array[i]->debt_installment_payment;

				//decrease the value of the loan with the debt_install_payment:
				DEBT_INSTALLMENT_PAYMENTS->array[i]->loan_value -= DEBT_INSTALLMENT_PAYMENTS->array[i]->debt_installment_payment;

				//decrease the value of the nr_periods_before_maturity
				DEBT_INSTALLMENT_PAYMENTS->array[i]->nr_periods_before_maturity -= 1;
				
				//tell the bank I paid
				debt_installment_payment = DEBT_INSTALLMENT_PAYMENTS->array[i]->debt_installment_payment;
				bank_id = DEBT_INSTALLMENT_PAYMENTS->array[i]->bank_id;				
				add_debt_installment_payment_message(ID, bank_id, debt_installment_payment, MSGDATA);
			}
		}

		//total_dividend_payment
		//compute dividend_per_share
		//add_dividend_message(ID, dividend_per_share, MSGDATA);

		//compute the equity of the firm
		//1. PAYMENT_ACCOUNT: cash holdings of the firm
		//2. VALUE_CAPITAL_STOCK: estimated value of capital stock
		//3. VALUE_LOCAL_INVENTORY
		
		
		//The capital stock is heterogeneous.
		//struct VALUE_CAPITAL_STOCK				: array of structs with each struct a purchased quantity of capital stock
		//double depreciation_value_per_period		: we assume that the capital stock depreciates with a fixed value in each period.
		//int nr_periods_before_total_depreciation  : after some periods the capital stock is completely depreciated
		//double current_value
		
		//We loop over all elements and update the current_value for each item of capital stock
		imax = VALUE_CAPITAL_STOCK->size;
		for (i=0;i<imax;i++)
		{
			VALUE_CAPITAL_STOCK->array[i]->current_value -= VALUE_CAPITAL_STOCK->array[i]->depreciation_value_per_period;
			VALUE_CAPITAL_STOCK->array[i]->nr_periods_before_total_depreciation -= 1;
			if (VALUE_CAPITAL_STOCK->array[i]->nr_periods_before_total_depreciation==0)
			{
				remove_array(VALUE_CAPITAL_STOCK, i); //the period of full depreciation has been reached
			}
		}

		//VALUE_LOCAL_INVENTORY: estimated value of local inventory stocks at current mall prices
		//We loop over all malls and sum the value of all local inventory stocks
		imax = CURRENT_MALL_STOCKS->size;
		sum=0;
		for (i=0;i<imax;i++)
		{
			sum += PRICE*CURRENT_MALL_STOCKS->array[i]->current_stock;
			//When malls have different current_price use this code:
			//sum += CURRENT_MALL_STOCKS->array[i]->current_price * CURRENT_MALL_STOCKS->array[i]->current_stock;
		}
		VALUE_LOCAL_INVENTORY=sum;

		EQUITY = PAYMENT_ACCOUNT + VALUE_CAPITAL_STOCK + VALUE_LOCAL_INVENTORY;
	}

	return 0;
}

