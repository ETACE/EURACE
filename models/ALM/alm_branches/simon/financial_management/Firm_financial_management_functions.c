#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"


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
 * \brief: This function computes the balance sheet of the firm at the END of an accounting period (typically a month).
 * The firm makes the actual payments by setting these values:
 *  - total_debt_installment_payment
 *  - total_interest_payments
 *  - tax_payment
 *  - total_dividend_payment
 * The payments are all subtracted from the payment account.
 * 
 * In addition, we compute these values:
 *  - value_capital_stock
 *  - value_inventory_stock
 *  - total_asset_value
 */ 
int Firm_compute_balance_sheet()
{
    double sum;
    int imax;
    int i;

    if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
    {
        //double PAYMENT_ACCOUNT: account out of which payments are made, to be separated from the income_account on which current sale receipts are incoming
        //CASH_HOLDINGS: equal to payment_account???? Cash holdings is an ambiguous term.

        //double_array LOANS                : dynamic array of structs with each struct a loan_item
        //struct loan_item
        //int bank_id                       : bank at which the loan was obtained
        //double loan_value                 : total value of the loan remaining
        //double interest_rate              : interest for this loan
        //double interest_payment           : interest to be paid this period
        //double debt_installment_payment   : installment payment per period
        //int nr_periods_before_maturity    : nr of periods to go before the loan has to be fully repaid

        //step 1: compute total interest payments
        TOTAL_INTEREST_PAYMENT=0.0;
        imax = LOANS.size;
        for (i=0; i<imax;i++)
        {
            LOANS.array[i].interest_payment = LOANS.array[i].interest_rate * LOANS.array[i].loan_value;                         

            //add to total
            TOTAL_INTEREST_PAYMENT += LOANS.array[i].interest_payment;
        }
        
        //consistency check
        if(PLANNED_TOTAL_INTEREST_PAYMENT != TOTAL_INTEREST_PAYMENT)
        {
            printf("\nError: planned total interest payment is not equal to total interest payment.\n Did you set the same option for the planned and actual payments?");
        }
        
        //step 2: compute total debt installment payments
        TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
        TOTAL_DEBT=0.0;
        for (i=0; i<imax;i++)
        {
            //compute current total debt
            TOTAL_DEBT += LOANS.array[i].loan_value;
            
            //add debt_installment_payment to total installment payment
            TOTAL_DEBT_INSTALLMENT_PAYMENT += LOANS.array[i].debt_installment_payment;
        }
        //consistency check
        if(PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT != TOTAL_DEBT_INSTALLMENT_PAYMENT)
        {
            printf("\nError: planned total debt installment payment is not equal to total debt installment payment.\n Did you set the same option for the planned and actualpayments?");
        }
                        
        //step 3: continue balance sheet (net earnings, earnings per share)
        EARNINGS = EBIT - TOTAL_INTEREST_PAYMENT;
        
        //Here: should debt_installment_payments be subtracted from earnings before taxes are paid, or after?
        //They are of course liabilities, but debt installment payments are one of many payouts.
        
        TAX_PAYMENT = TAX_RATE_CORPORATE * EARNINGS;
        PREVIOUS_NET_EARNINGS = NET_EARNINGS;
        NET_EARNINGS = EARNINGS - TAX_PAYMENT;
        EARNINGS_PER_SHARE_RATIO = NET_EARNINGS/CURRENT_SHARES_OUTSTANDING;

        //step 4: actual tax_payment to government
        add_tax_payment_message(ID, GOV_ID, TAX_PAYMENT, MSGDATA);

        //step 5: actual interest_payments and debt_installment_payments
        //printf("\n Checking: PAYMENT_ACCOUNT > TOTAL_DEBT_INSTALLMENT_PAYMENT: %f>%f \n", PAYMENT_ACCOUNT, TOTAL_DEBT_INSTALLMENT_PAYMENT);
        if (PAYMENT_ACCOUNT < TOTAL_DEBT_INSTALLMENT_PAYMENT)
        {
            //Code: transform debt into equity
            //Code: debt is repaid partially
            //Code: compute debt remaining to be paid

            PAYMENT_ACCOUNT = 0.0;
        }
        else
        {
            //Sending interest_payment_msg to all banks at which the firm has a loan 
            imax = LOANS.size;
            for (i=0; i<imax;i++)
            {
                //decrease payment_account with the interest_payment
                PAYMENT_ACCOUNT -= LOANS.array[i].interest_payment;

                //tell the bank I paid
                add_interest_payment_message(ID, BANK_ID, LOANS.array[i].interest_payment,MSGDATA);
            }
            
            //Sending debt_installment_payment_msg to all banks at which the firm has a loan
            for (i=0; i<imax;i++)
            {
                //decrease payment_account with the installment payment
                PAYMENT_ACCOUNT -= LOANS.array[i].debt_installment_payment;

                //decrease the value of the loan with the debt_installment_payment:
                LOANS.array[i].loan_value -= LOANS.array[i].debt_installment_payment;
                //printf("Now subtracted debt_installment_payment from loan_value: %f (new value:%f).\n", LOANS.array[i].debt_installment_payment, LOANS.array[i].loan_value);
                
                //decrease the value of the nr_periods_before_maturity
                LOANS.array[i].nr_periods_before_maturity -= 1;

                //tell the bank I paid
                add_debt_installment_payment_message(ID, LOANS.array[i].bank_id, LOANS.array[i].debt_installment_payment, MSGDATA);

                //if nr_periods_before_maturity == 0, remove the loan item
                if (LOANS.array[i].nr_periods_before_maturity==0)
                {
                    remove_debt_item(&LOANS, i);
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

        //option 5: keep dividend to earnings ratio constant (dont let it fall), but do not decrease the dividend per share ratio.
/*
        if (CURRENT_DIVIDEND_PER_EARNINGS < PREVIOUS_DIVIDEND_PER_EARNINGS)
        {
            //Maintain the dividend to earnings ratio
            //D_{t} = (D_{t-1}/E_{t-1})*E_{t}
            TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_EARNINGS * NET_EARNINGS;
            
            //But do not decrease the dividend per share ratio
            if (TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING < CURRENT_DIVIDEND_PER_SHARE)
            {
                TOTAL_DIVIDEND_PAYMENT = CURRENT_DIVIDEND_PER_SHARE * CURRENT_SHARES_OUTSTANDING;
            }
        }
        else
        {
            //the dividend to earnings ratio did not decrease
            //else keep the dividend per share ratio constant
            TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_SHARE*CURRENT_SHARES_OUTSTANDING;
        }
*/

        //consistency check
        if(PLANNED_TOTAL_DIVIDEND_PAYMENT != TOTAL_DIVIDEND_PAYMENT)
        {
            printf("\nError: planned total dividend payment is not equal to total dividend payment.\n Did you set the same option for the planned and actual payments?");
        }

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
        //TOTAL_ASSETS=
        //+ PAYMENT_ACCOUNT: remaining cash holdings of the firm
        //+ TOTAL_VALUE_CAPITAL_STOCK: estimated value of the capital stock
        //+ TOTAL_VALUE_LOCAL_INVENTORY: value of all the local inventory stocks held at the malls
        
        //The capital stock is heterogeneous.
        //struct VALUE_CAPITAL_STOCK                : dynamic array of capital_stock_item; each item is a struct of a certain purchased quantity of capital stock
        //double current_value                      : current value of the item
        //double depreciation_value_per_period      : we assume that the capital stock depreciates with a fixed value in each period.
        //int nr_periods_before_total_depreciation  : after some periods the capital stock is completely depreciated

        
        //We loop over all capital stock items and update the current_value
        imax = VALUE_CAPITAL_STOCK.size;
        TOTAL_VALUE_CAPITAL_STOCK=0;
        for (i=0;i<imax;i++)
        {
            //decrease the value of each installment of capital by its own depreciation value
            VALUE_CAPITAL_STOCK.array[i].current_value -= VALUE_CAPITAL_STOCK.array[i].depreciation_value_per_period;
            VALUE_CAPITAL_STOCK.array[i].nr_periods_before_total_depreciation -= 1;
            
            //update the current value of the capital stock:
            TOTAL_VALUE_CAPITAL_STOCK += VALUE_CAPITAL_STOCK.array[i].current_value;

            //if the period of full depreciation has been reached: remove the capital_stock_item
            if (VALUE_CAPITAL_STOCK.array[i].nr_periods_before_total_depreciation==0)
            {
                remove_capital_stock_item(&VALUE_CAPITAL_STOCK, i);
            }
        }
        
        //TOTAL_VALUE_LOCAL_INVENTORY: estimated value of local inventory stocks at current mall prices
        //We loop over the malls and sum the value of all local inventory stocks
        imax = CURRENT_MALL_STOCKS.size;
        sum=0.0;
        for (i=0;i<imax;i++)
        {
            sum += PRICE*CURRENT_MALL_STOCKS.array[i].current_stock;
            //When malls have different current_price use this code:
            //sum += CURRENT_MALL_STOCKS.array[i].current_price * CURRENT_MALL_STOCKS.array[i].current_stock;
        }
        TOTAL_VALUE_LOCAL_INVENTORY=sum;

        TOTAL_ASSETS = PAYMENT_ACCOUNT + TOTAL_VALUE_CAPITAL_STOCK + TOTAL_VALUE_LOCAL_INVENTORY;
        //printf("\nTOTAL_ASSETS in functions.c file: %f\n", TOTAL_ASSETS);
    }

    return 0;
}

/*
 * \fn: int Firm_compute_payout_policy()
 * \brief: This function computes the planned payout policy and the financial needs for the upcoming production cycle.
 * The values computed in this function are only planned values, not fixed, since the payout policy
 * can be subject to revision if it turns out to be unsupportable by the obtained financial resources.
 */
int Firm_compute_payout_policy()
{
    int imax;
    int i;
    //step 9: compute planned_total_interest_payment for upcoming production cycle
    PLANNED_TOTAL_INTEREST_PAYMENT=0.0;
    imax = LOANS.size;
    for (i=0; i<imax;i++)
    {
        LOANS.array[i].interest_payment = LOANS.array[i].interest_rate * LOANS.array[i].loan_value;                         

        //add to total
        PLANNED_TOTAL_INTEREST_PAYMENT += LOANS.array[i].interest_payment;
    }
    
    //step 10: compute planned_total_debt_installment_payment for upcoming production cycle
    PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
    for (i=0; i<imax;i++)
    {
        //add to total
        PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT += LOANS.array[i].debt_installment_payment;
    }
    
    //step 11: compute planned_total_dividend_payment.

    //option 1: total divided payment remains constant
    //PLANNED_TOTAL_DIVIDEND_PAYMENT *= 1;
    
    //option 2: total divided payment increases with same ratio as earnings
    //this is very dangerous, since earnings may fluctuate violently
    //PLANNED_TOTAL_DIVIDEND_PAYMENT *= NET_EARNINGS/PREVIOUS_NET_EARNINGS;
    
    //option 3: keep dividend per share constant
    //total divided payment increases with same ratio as current_shares_outstanding
    //PLANNED_TOTAL_DIVIDEND_PAYMENT *= CURRENT_SHARES_OUTSTANDING/PREVIOUS_SHARES_OUTSTANDING;

    //option 4: keep earnings per share constant
    //total divided payment increases with same ratio as earnings per share
    //if current_shares_outstanding remains constant, this keeps earnings per share constant
    PLANNED_TOTAL_DIVIDEND_PAYMENT *= EARNINGS_PER_SHARE_RATIO;

    //option 5: keep dividend to earnings ratio constant (dont let it fall), but do not decrease the dividend per share ratio.
/*
    if (CURRENT_DIVIDEND_PER_EARNINGS < PREVIOUS_DIVIDEND_PER_EARNINGS)
    {
        //Maintain the dividend to earnings ratio
        //D_{t} = (D_{t-1}/E_{t-1})*E_{t}
        PLANNED_TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_EARNINGS * NET_EARNINGS;
        
        //But do not decrease the dividend per share ratio
        if (PLANNED_TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING < CURRENT_DIVIDEND_PER_SHARE)
        {
            PLANNED_TOTAL_DIVIDEND_PAYMENT = CURRENT_DIVIDEND_PER_SHARE * CURRENT_SHARES_OUTSTANDING;
        }
    }
    else
    {
        //the dividend to earnings ratio did not decrease
        //else keep the dividend per share ratio constant
        PLANNED_TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_SHARE*CURRENT_SHARES_OUTSTANDING;
    }
*/  
    //step 12: set financial_needs for the upcoming production cycle
    //The total production costs (costs = labor_costs + capital_costs) come from the function Firm_calc_pay_costs
    TOTAL_FINANCIAL_NEEDS = PLANNED_TOTAL_INTEREST_PAYMENT + PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT + PLANNED_TOTAL_DIVIDEND_PAYMENT + PRODUCTION_COSTS;
    //printf("\n Checking: TOTAL_FINANCIAL_NEEDS=%f+%f+%f+%f=%f \n", PLANNED_TOTAL_INTEREST_PAYMENT, PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT, PLANNED_TOTAL_DIVIDEND_PAYMENT, PRODUCTION_COSTS, TOTAL_FINANCIAL_NEEDS);
    
    //Check if external financing is needed.
    
    if (PAYMENT_ACCOUNT>0)
    {
    	//printf("\n Checking: TOTAL_FINANCIAL_NEEDS < PAYMENT_ACCOUNT \n", TOTAL_FINANCIAL_NEEDS, PAYMENT_ACCOUNT);
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
    }
	else //Here: negative payment_account needs to be financed as well by a bank credit
	        {
				//printf("\n Checking: payment_account is negative due to dividend payment, this needs to be financed by credit or equity.\n");
				//printf("\n PAYMENT_ACCOUNT=%f\n", PAYMENT_ACCOUNT);
				EXTERNAL_FINANCIAL_NEEDS = TOTAL_FINANCIAL_NEEDS - PAYMENT_ACCOUNT;
	        }
    
    //printf("\n Checking: INTERNAL_FINANCIAL_NEEDS=%f\n", INTERNAL_FINANCIAL_NEEDS);
    //printf("\n Checking: EXTERNAL_FINANCIAL_NEEDS=%f\n", EXTERNAL_FINANCIAL_NEEDS);
    RETAINED_EARNINGS_RATIO = INTERNAL_FINANCIAL_NEEDS/NET_EARNINGS;
    
    return 0;
}


/*
 * \fn: Firm_apply_for_loans()
 * \brief: This function sends a loan_request_message.
 */
int Firm_apply_for_loans()
{
   add_loan_request_message(ID, bank_id, EXTERNAL_FINANCIAL_NEEDS, TOTAL_ASSETS, TOTAL_DEBT, MSGDATA);

   return 0;
}

/*
 * \fn: Firm_read_loan_offers_send_loan_acceptance()
 * \brief: This function reads loan_conditions_messages from the bank. The firm sends out a loan_acceptance_message.
 */
int Firm_read_loan_offers_send_loan_acceptance()
{
	START_LOAN_CONDITIONS_MESSAGE_LOOP
		if(loan_conditions_message->firm_id==ID)
		{
			//loan_conditions_message(bank_id, firm_id, proposed_interest_rate, amount_credit_offer, MSGDATA);
			//loan_conditions_message->proposed_interest_rate;
			//loan_conditions_message->amount_credit_offer;
			//Now send out acceptance messages: the firm always accepts the credit offered by bank
			//add_loan_acceptance_message(firm_id, bank_id, CREDIT_AMOUNT_TAKEN);
			
			add_loan_acceptance_message(ID, loan_conditions_message->bank_id, loan_conditions_message->amount_credit_offer);
		}
	FINISH_LOAN_CONDITIONS_MESSAGE_LOOP

	return 0;
}

/*
 * \fn: Firm_compute_and_send_bond_orders()
 * \brief: This function computes the firm's bond orders and sends a bond_order_message to the clearinghouse.
 */
int Firm_compute_and_send_bond_orders()
{
	//add_bond_message(ID, bond_id, limit_price, limit_quantity, MSGDATA);
	
    return 0;
}

/*
 * \fn: Firm_read_bond_transactions()
 * \brief: This function reads a bond_transaction_message from the clearinghouse, and updates the firm's trading account.
 */
int Firm_read_bond_transactions()
{
	START_BOND_TRANSACTION_MESSAGE_LOOP
	if(bond_transaction_message->trader_id==ID)
	{
		//bond_transaction_message->bond_id
		//bond_transaction_message->limit_price
		//bond_transaction_message->limit_quantity
	}
	FINISH_BOND_TRANSACTION_MESSAGE_LOOP
    return 0;
}


/*
 * \fn: Firm_compute_and_send_stock_orders()
 * \brief: This function computes the firm's stock orders (share emmision) and sends a stock_order_message to the clearinghouse.
 */
int Firm_compute_and_send_stock_orders()
{
    double limit_quantity = (int) -1*EXTERNAL_FINANCIAL_NEEDS/CURRENT_SHARE_PRICE;

    //Firm tries to sell stock_units shares:
    add_stock_order_message(ID, stock_id, limit_price, limit_quantity, MSGDATA);

    return 0;
}

/*
 * \fn: Firm_read_stock_transactions()
 * \brief: This function reads a stock_transaction_message from the clearinghouse, and updates the firm's trading account.
 */
int Firm_read_stock_transactions()
{
	START_STOCK_TRANSACTION_MESSAGE_LOOP
	if(stock_transaction_message->trader_id==ID)
	{
		//stock_transaction_message->stock_id
		//stock_transaction_message->limit_price
		//stock_transaction_message->limit_quantity
	}
	FINISH_STOCK_TRANSACTION_MESSAGE_LOOP
    return 0;
}
