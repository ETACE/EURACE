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
		//In the future: if we want to include sales_costs
		//SALES_COSTS = 0;
		//EBIT = CUM_REVENUES - SALES_COSTS
		EBIT = CUM_REVENUES; //net revenues = receipts - sales_costs;		
		
		//update the cash holdings
		PAYMENT_ACCOUNT += EBIT;
	}

	return 0;
}

/*
 * \fn: int Firm_compute_balance_sheet()
 * \brief: This function computes the balance sheet of the firm at the END of the accounting period (month).
 * The firm makes the actual payments by setting these values:
 *  - total_debt_installment_payment
 *  - total_interest_payments
 *  - tax_payment
 *  - total_dividend_payment
 *  - value_capital_stock
 *  - value_inventory_stock
 *  - equity
 */	
int Firm_compute_balance_sheet()
{
	double sum;

	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{
		//double PAYMENT_ACCOUNT: account out of which payments are made, to be separated from the income_account on which current sale receipts are incoming
		//CASH_HOLDINGS: equal to payment_account???? Cash holdings is an ambiguous term.

		//double_array LOANS				: dynamic array of structs with each struct a loan_item
		//struct loan_item
		//int bank_id						: bank at which the loan was obtained
		//double loan_value					: total value of the loan remaining
		//double interest_rate				: interest for this loan
		//double interest_payment			: interest to be paid this period
		//double debt_installment_payment	: installment payment per period
		//int nr_periods_before_maturity 	: nr of periods to go before the loan has to be fully repaid

		//step 1: compute total interest payments
		TOTAL_INTEREST_PAYMENT =0;
		imax = LOANS->size;
		for (i=0; i<imax;i++)
		{
			LOANS->array[i]->interest_payment = LOANS->array[i]->interest_rate * LOANS->array[i]->loan_value;							

			//add to total
			TOTAL_INTEREST_PAYMENT += LOANS->array[i]->interest_payment;
		}
		
		//step 2: compute total debt installment payments
		TOTAL_DEBT_INSTALLMENT_PAYMENT =0;
		for (i=0; i<imax;i++)
		{
			//add to total
			TOTAL_DEBT_INSTALLMENT_PAYMENT += LOANS->array[i]->debt_installment_payment;
		}
						
		//step 3: continue balance sheet (net earnings, earnings per share)
		EARNINGS = EBIT - TOTAL_INTEREST_PAYMENT;
		TAX_PAYMENT = TAX_RATE_CORPORATE * EARNINGS;
		PREVIOUS_NET_EARNINGS = NET_EARNINGS;
		NET_EARNINGS = EARNINGS - TAX_PAYMENT;
	    EARNINGS_PER_SHARE_RATIO = NET_EARNINGS/CURRENT_SHARES_OUTSTANDING;

		//step 4: actual tax_payment to government
		add_tax_payment_message(ID, gov_id, TAX_PAYMENT,MSGDATA);

		//step 5: actual interest_payments and debt_installment_payments
		if (PAYMENT_ACCOUNT < TOTAL_DEBT_INSTALLMENT_PAYMENT)
		{
			//Code: transform debt into equity
			//Code: debt is repaid partially
			//Code: compute debt remaining to be paid

			PAYMENT_ACCOUNT = 0;
		}
		else
		{
			//Sending interest_payment_msg to all banks at which the firm has a loan 
			imax = LOANS->size;
			for (i=0; i<imax;i++)
			{
				//decrease payment_account with the interest_payment
				PAYMENT_ACCOUNT -= LOANS->array[i]->interest_payment;

				//tell the bank I paid
				add_interest_payment_message(ID, bank_id, LOANS->array[i]->interest_payment,MSGDATA);
			}
			
			//Sending debt_installment_payment_msg to all banks at which the firm has a loan
			for (i=0; i<imax;i++)
			{
				//decrease payment_account with the installment payment
				PAYMENT_ACCOUNT -= LOANS->array[i]->debt_installment_payment;

				//decrease the value of the loan with the debt_installment_payment:
				LOANS->array[i]->loan_value -= LOANS->array[i]->debt_installment_payment;

				//decrease the value of the nr_periods_before_maturity
				LOANS->array[i]->nr_periods_before_maturity -= 1;

				//tell the bank I paid
				add_debt_installment_payment_message(ID, LOANS->array[i]->bank_id, LOANS->array[i]->debt_installment_payment, MSGDATA);

				//if nr_periods_before_maturity == 0, remove the loan item
				if (LOANS->array[i]->nr_periods_before_maturity==0)
				{
					remove_loan_item(LOANS, i);
				}
			}
		}

		//step 6: determine total_dividend_payment
		//option 1: total divided payment remains constant
		//TOTAL_DIVIDEND_PAYMENT *= 1;
		
		//option 2: total divided payment increases with same ratio as earnings
		//this is very dangerous, since earnings may fluctuate violently
		//TOTAL_DIVIDEND_PAYMENT *= NET_EARNINGS/PREVIOUS_NET_EARNINGS;
		
		//option 3: keep dividend per share constant
		//total divided payment increases with same ratio as current_shares_outstanding
		//TOTAL_DIVIDEND_PAYMENT *= CURRENT_SHARES_OUTSTANDING/PREVIOUS_SHARES_OUTSTANDING;

		//option 4: keep earnings per share constant
		//total divided payment increases with same ratio as earnings per share
		//if current_shares_outstanding remains constant, this keeps earnings per share constant
		TOTAL_DIVIDEND_PAYMENT *= EARNINGS_PER_SHARE_RATIO;

		//step 7: continue balance sheet (data pertaining to the period that just ended)
		PREVIOUS_DIVIDEND_PER_SHARE = CURRENT_DIVIDEND_PER_SHARE;
		CURRENT_DIVIDEND_PER_SHARE = TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING;
		PREVIOUS_DIVIDEND_PER_EARNINGS = CURRENT_DIVIDEND_PER_EARNINGS;
		CURRENT_DIVIDEND_PER_EARNINGS = TOTAL_DIVIDEND_PAYMENT/EARNINGS;
		
		//add dividend_payment_msg to shareholders (dividend per share)		
		add_dividend_payment_message(ID, CURRENT_DIVIDEND_PER_SHARE, MSGDATA);

		//decrease payment_account with the total_dividend_payment
		PAYMENT_ACCOUNT -= TOTAL_DIVIDEND_PAYMENT;

		//step 8: compute the equity of the firm
		//EQUITY=
		//+ PAYMENT_ACCOUNT: remaining cash holdings of the firm
		//+ TOTAL_VALUE_CAPITAL_STOCK: estimated value of the capital stock
		//+ TOTAL_VALUE_LOCAL_INVENTORY: value of all the local inventory stocks held at the malls
		
		//The capital stock is heterogeneous.
		//struct VALUE_CAPITAL_STOCK				: dynamic array of capital_stock_item; each item is a struct of a certain purchased quantity of capital stock
		//double current_value						: current value of the item
		//double depreciation_value_per_period		: we assume that the capital stock depreciates with a fixed value in each period.
		//int nr_periods_before_total_depreciation  : after some periods the capital stock is completely depreciated

		
		//We loop over all capital stock items and update the current_value
		imax = VALUE_CAPITAL_STOCK->size;
		TOTAL_VALUE_CAPITAL_STOCK=0;
		for (i=0;i<imax;i++)
		{
			//decrease the value of each installment of capital by its own depreciation value
			VALUE_CAPITAL_STOCK->array[i]->current_value -= VALUE_CAPITAL_STOCK->array[i]->depreciation_value_per_period;
			VALUE_CAPITAL_STOCK->array[i]->nr_periods_before_total_depreciation -= 1;
			
			//update the current value of the capital stock:
			TOTAL_VALUE_CAPITAL_STOCK += VALUE_CAPITAL_STOCK->array[i]->current_value;

			//if the period of full depreciation has been reached: remove the capital_stock_item
			if (VALUE_CAPITAL_STOCK->array[i]->nr_periods_before_total_depreciation==0)
			{
				remove_capital_stock_item(VALUE_CAPITAL_STOCK, i);
			}
		}
		
		//TOTAL_VALUE_LOCAL_INVENTORY: estimated value of local inventory stocks at current mall prices
		//We loop over the malls and sum the value of all local inventory stocks
		imax = CURRENT_MALL_STOCKS->size;
		sum=0.0;
		for (i=0;i<imax;i++)
		{
			sum += PRICE*CURRENT_MALL_STOCKS->array[i]->current_stock;
			//When malls have different current_price use this code:
			//sum += CURRENT_MALL_STOCKS->array[i]->current_price * CURRENT_MALL_STOCKS->array[i]->current_stock;
		}
		TOTAL_VALUE_LOCAL_INVENTORY=sum;

		EQUITY = PAYMENT_ACCOUNT + TOTAL_VALUE_CAPITAL_STOCK + TOTAL_VALUE_LOCAL_INVENTORY;
	}

	return 0;
}

/*
 * \fn: int Firm_compute_payout_policy()
 * \brief: This function computes the planned payout policy and the financial needs for the upcoming production cycle
 * The values computed in this function are only planned values, not fixed, since the payout policy
 * can be subject to revision if it turns out to be insupportable by the obtained financial resources.
 */
int Firm_compute_payout_policy()
{
	//step 9: compute planned_total_interest_payment for upcoming production cycle
	PLANNED_TOTAL_INTEREST_PAYMENT =0;
	imax = LOANS->size;
	for (i=0; i<imax;i++)
	{
		LOANS->array[i]->interest_payment = LOANS->array[i]->interest_rate * LOANS->array[i]->loan_value;							

		//add to total
		PLANNED_TOTAL_INTEREST_PAYMENT += LOANS->array[i]->interest_payment;
	}
	
	//step 10: compute planned_total_debt_installment_payment for upcoming production cycle
	PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT =0;
	for (i=0; i<imax;i++)
	{
		//add to total
		PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT += LOANS->array[i]->debt_installment_payment;
	}
	
	//step 11: compute planned_total_dividend_payment.
	//Goal: maintain a constant dividend to earnings ratio
	//But: do not decrease the dividend per share ratio.
	if (CURRENT_DIVIDEND_PER_EARNINGS < PREVIOUS_DIVIDEND_PER_EARNINGS)
	{
		//D_{t} = (D_{t-1}/E_{t-1})*E_{t}
		PLANNED_TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_EARNINGS * NET_EARNINGS;
		
		//do not decrease the dividend per share ratio
		if (PLANNED_TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING < CURRENT_DIVIDEND_PER_SHARE)
		{
			TOTAL_DIVIDEND_PAYMENT = CURRENT_DIVIDEND_PER_SHARE * CURRENT_SHARES_OUTSTANDING;
		}
		else
			{
				TOTAL_DIVIDEND_PAYMENT = PLANNED_TOTAL_DIVIDEND_PAYMENT;
			}
	}
	else
	{
		//keep the dividend per share ratio
		TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_SHARE*CURRENT_SHARES_OUTSTANDING;
	}
	
	//re-compute the final dividend per share ratio, given the total_dividend_payment
	CURRENT_DIVIDEND_PER_SHARE = TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING;
	CURRENT_DIVIDEND_PER_EARNINGS = TOTAL_DIVIDEND_PAYMENT/EARNINGS;
	
	//step 12: set financial_needs for the upcoming production cycle
	//The total production costs (costs = labor_costs + capital_costs) come from the function Firm_calc_pay_costs
	TOTAL_FINANCIAL_NEEDS = PLANNED_TOTAL_INTEREST_PAYMENT + PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT + TOTAL_DIVIDEND_PAYMENT + PRODUCTION_COSTS;
	
	//Check if external financing is needed.
	if (TOTAL_FINANCIAL_NEEDS < PAYMENT_ACCOUNT)
	{
		INTERNAL_FINANCIAL_NEEDS = TOTAL_FINANCIAL_NEEDS;
		EXTERNAL_FINANCIAL_NEEDS = 0;
	}
	else
		{
			INTERNAL_FINANCIAL_NEEDS = PAYMENT_ACCOUNT;
			EXTERNAL_FINANCIAL_NEEDS = TOTAL_FINANCIAL_NEEDS - PAYMENT_ACCOUNT;
		}
	return 0;
}


/*
 * \fn: Firm_apply_for_credit()
 * \brief: This function sends a credit_demand_message
 */
int Firm_apply_for_credit()
{
   add_credit_demand_message(ID, bank_id, EXTERNAL_FINANCIAL_NEEDS);

   return 0;
}

/*
 * \fn: Firm_issue_equity()
 * \brief: This function sends a firm_stock_order_message to the clearinghouse.
 */
int Firm_issue_equity()
{
	limit_quantity = (int) -1*EXTERNAL_FINANCIAL_NEEDS/SHARE_PRICE;

	//Firm tries to sell stock_units shares:
	add_stock_order_message(ID, clearinghouse_id, limit_price, limit_quantity, stock_id)

	return 0;
}
