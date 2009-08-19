#include "../header.h"
#include "../IGFirm_agent_header.h"
#include "../my_library_header.h"



/************Firm Role: Financial Management Role ********************************/


/*
 * \fn: int IGFirm_financial_payments()
 * \brief: This function computes the income statement of the firm.
 * 
 * The firm computes the actual payments by setting these values:
 *  - total_debt_installment_payment
 *  - total_interest_payments
 *  - tax_payment
 *  - total_dividend_payment
 * The payments are all subtracted from the payment account.
 */
int IGFirm_compute_financial_payments()
{

	printf("IN FUNCTION:IGFirm_compute_financial_payments() \n");
	printf("************************************************** \n");
printf("Last day: %d \n", LAST_DAY_OF_MONTH_TO_ACT);
	double interest_payment;
    	int imax;
    	int i;

    	//double PAYMENT_ACCOUNT: account out of which payments are made, to be separated from the 
	//income_account on which current sale receipts are incoming

    	//double_array LOANS                : dynamic array of structs with each struct a loan_item
    	//struct debt_item
    	//int bank_id                       : bank at which the loan was obtained
    	//double loan_value                 : total value of the loan remaining
    	//double interest_rate              : interest for this loan
    	//double interest_payment           : interest to be paid this period
    	//double debt_installment_payment   : installment payment per period
    	//int nr_periods_before_maturity    : nr of periods to go before the loan has to be fully 
						//repaid

    	//step 1: compute total interest payments
    	TOTAL_INTEREST_PAYMENT=0.0;
    	imax = LOANS.size;
    	//printf("Firm_Financial_Management_Function, line 42: LOANS.size=%d\n", imax);
    
    	for (i=0; i<imax;i++)
    	{
        	interest_payment = LOANS.array[i].interest_rate * 
		LOANS.array[i].loan_value;                         

        	//add to total
        	TOTAL_INTEREST_PAYMENT += interest_payment;

        	LOANS.array[i].interest_payment = interest_payment; 
    	}
    
    	//step 2: compute total debt installment payments
    	TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
    	TOTAL_DEBT=0.0;
    	for (i=0; i<imax;i++)
    	{
       		//printf("Firm_Financial_Management_Function, line 58: Adding loan values to total 
		//debt\n");
        	//compute current total debt
        	TOTAL_DEBT += LOANS.array[i].loan_value;
        
        	//add debt_installment_payment to total installment payment
        	TOTAL_DEBT_INSTALLMENT_PAYMENT += LOANS.array[i].installment_amount;
    	}

	printf("TOTAL_INTEREST_PAYMENT %f \n",TOTAL_INTEREST_PAYMENT);
	printf("TOTAL_DEBT %f \n",TOTAL_DEBT);
	printf("TOTAL_DEBT_INSTALLMENT_PAYMENT %f \n",TOTAL_DEBT_INSTALLMENT_PAYMENT);
	printf("**************************************************************** \n");

	
	
    return 0;
}

/*
 * \fn: int IGFirm_compute_income_statement()
 * \brief: This function computes the income statement of the firm.
 */
int IGFirm_compute_income_statement()
{
	printf("IN FUNCTION: IGFirm_compute_income_statement() \n");
	printf("***********************************************\n");
	
	//In the future: if we want to include sales_costs
    	//SALES_COSTS = 0;
   
    	// compute net earnings
    	EARNINGS = CUM_REVENUES - TOTAL_INTEREST_PAYMENT - PRODUCTION_COSTS;

	printf("EARNINGS %f \n",EARNINGS);
	printf("CUM_REVENUES %f \n",CUM_REVENUES);
	printf("TOTAL_INTEREST_PAYMENT %f \n",TOTAL_INTEREST_PAYMENT);
	printf("PRODUCTION_COSTS %f \n",PRODUCTION_COSTS);
	
	
	
 	if(EARNINGS>0)
	{	
    		TAX_PAYMENT = TAX_RATE_CORPORATE * EARNINGS;
	}
    	else
	{ 
		TAX_PAYMENT = 0;
	}
	
	PREVIOUS_NET_EARNINGS = NET_EARNINGS;
    	NET_EARNINGS = EARNINGS - TAX_PAYMENT;

	 //continue balance sheet (data pertaining to the period that just ended)	
	if (CURRENT_SHARES_OUTSTANDING>0)
    	{
        	PREVIOUS_EARNINGS_PER_SHARE = EARNINGS_PER_SHARE;
        	EARNINGS_PER_SHARE = NET_EARNINGS/CURRENT_SHARES_OUTSTANDING;
    	}

       	PREVIOUS_DIVIDEND_PER_SHARE = CURRENT_DIVIDEND_PER_SHARE;
       	CURRENT_DIVIDEND_PER_SHARE = TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING;

    	if (EARNINGS>0.0)
    	{
       	 	PREVIOUS_DIVIDEND_PER_EARNINGS = CURRENT_DIVIDEND_PER_EARNINGS;
       		CURRENT_DIVIDEND_PER_EARNINGS = TOTAL_DIVIDEND_PAYMENT/EARNINGS;
    	}

	printf("PREVIOUS_NET_EARNINGS %f \n",PREVIOUS_NET_EARNINGS);
	printf("NET_EARNINGS %f \n",NET_EARNINGS);
	printf("TAX_RATE_CORPORATE %f \n",TAX_RATE_CORPORATE);
	printf("TAX_PAYMENT %f \n",TAX_PAYMENT);
	printf("*************************************************\n");

   
	
    return 0;
}


int IGFirm_compute_dividends()
{
	printf("IN FUNCTION: IGFirm_compute_dividends()\n");
	printf("**********************************************\n");

	//Determine total_dividend_payment
	//option 1: total divided payment remains constant
	//TOTAL_DIVIDEND_PAYMENT *= 1;
	
	//option 2: total dividend payment increases with same ratio as net earnings
	//This is very dangerous, since earnings may fluctuate violently
	//TOTAL_DIVIDEND_PAYMENT *= NET_EARNINGS/PREVIOUS_NET_EARNINGS;
	
	//option 3: keep dividend per share constant
	//total divided payment increases with same ratio as current_shares_outstanding
	//TOTAL_DIVIDEND_PAYMENT *= CURRENT_SHARES_OUTSTANDING/PREVIOUS_SHARES_OUTSTANDING;
	
	//option 4: keep earnings per share constant
	//total divided payment increases with same ratio as earnings per share
	//if current_shares_outstanding remains constant, this keeps earnings per share constant
	
	//TOTAL_DIVIDEND_PAYMENT = TOTAL_DIVIDEND_PAYMENT * (EARNINGS_PER_SHARE/
	//PREVIOUS_EARNINGS_PER_SHARE);


	if (NET_EARNINGS > 0.0 )
	{
		TOTAL_DIVIDEND_PAYMENT =  DIVIDEND_RATE*NET_EARNINGS;
	} 
	else
	{
		TOTAL_DIVIDEND_PAYMENT=0;
	}
	
	//option 5: keep dividend to earnings ratio constant (dont let it fall), but do not 
	//decrease the dividend per share ratio.
	/*
	    if (CURRENT_DIVIDEND_PER_EARNINGS < PREVIOUS_DIVIDEND_PER_EARNINGS)
	    {
	        //Maintain the dividend to earnings ratio
	        //D_{t} = (D_{t-1}/E_{t-1})*E_{t}
	        TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_EARNINGS * NET_EARNINGS;
	        
	        //But do not decrease the dividend per share ratio
	        if (TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING < CURRENT_DIVIDEND_PER_SHARE)
	        {
	            	TOTAL_DIVIDEND_PAYMENT = CURRENT_DIVIDEND_PER_SHARE * 
			CURRENT_SHARES_OUTSTANDING;
	        }
	    }
	    else
	    {
	        //the dividend to earnings ratio did not decrease
	        //else keep the dividend per share ratio constant
	        TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_SHARE*CURRENT_SHARES_OUTSTANDING;
	    }
	*/

	


	printf("NET_EARNINGS %f \n",NET_EARNINGS);
	printf("CURRENT_SHARES_OUTSTANDING %d \n",CURRENT_SHARES_OUTSTANDING);
	printf("TOTAL_DIVIDEND_PAYMENT %f \n",TOTAL_DIVIDEND_PAYMENT);
	printf("PREVIOUS_EARNINGS_PER_SHARE %f \n",PREVIOUS_EARNINGS_PER_SHARE);
	printf("EARNINGS_PER_SHARE %f \n",EARNINGS_PER_SHARE);
	printf("PREVIOUS_DIVIDEND_PER_SHARE %f \n",PREVIOUS_DIVIDEND_PER_SHARE);
	printf("CURRENT_DIVIDEND_PER_SHARE %f \n",CURRENT_DIVIDEND_PER_SHARE);
	printf("**********************************************\n");	
    return 0;
}

int IGFirm_compute_total_financial_payments()
{
	printf("IN FUNCTION: IGFirm_compute_total_financial_payments()\n");
	printf("*********************************************************\n");
	
	//This variable is not used anywhere: it is the sum of financial_liquidity_needs and 
	//production_liquidity_needs
	//but excluding the tax_payments. The tax_payments do not need to be financed since we 
	//assume they can always be paid out of earnings. 
	TOTAL_PAYMENTS = TOTAL_INTEREST_PAYMENT + TOTAL_DEBT_INSTALLMENT_PAYMENT + 		
	TOTAL_DIVIDEND_PAYMENT + TAX_PAYMENT + PLANNED_PRODUCTION_COSTS;

	printf("TOTAL_INTEREST_PAYMENT %f \n",TOTAL_INTEREST_PAYMENT);
	printf("TOTAL_DEBT_INSTALLMENT_PAYMENT %f \n",TOTAL_DEBT_INSTALLMENT_PAYMENT);
	printf("TOTAL_DIVIDEND_PAYMENT %f \n",TOTAL_DIVIDEND_PAYMENT);
	printf("TAX_PAYMENT %f \n",TAX_PAYMENT);
	printf("PLANNED_PRODUCTION_COSTS %f \n",PLANNED_PRODUCTION_COSTS);
	printf("TOTAL_PAYMENTS %f \n",TOTAL_PAYMENTS);
	printf("*********************************************************\n");

	return 0;
}

/*
 * \fn: int Firm_compute_balance_sheet()
 * \brief: This function computes the balance sheet of the firm at the END of an accounting period,
 * (typically this is a month). The computation of the balance sheet occurs after all payments have been made.
 * In addition, we compute these values:
 *  - value_capital_stock
 *  - value_inventory_stock
 *  - total_asset_value
 */ 
int IGFirm_compute_balance_sheet()
{
	printf("IN FUNCTION: IGFirm_compute_balance_sheet() \n");
	printf("************************************************ \n");
    
    	//compute the equity of the firm
    	//TOTAL_ASSETS=
    	//+ PAYMENT_ACCOUNT: remaining cash holdings of the firm
    	//+ TOTAL_VALUE_LOCAL_INVENTORY: value of all the local inventory stocks 
    

    	//TOTAL_VALUE_LOCAL_INVENTORY: estimated value of local inventory stocks at current 
	//prices	

    	TOTAL_VALUE_LOCAL_INVENTORY= CAPITAL_GOOD_STORE*CAPITAL_GOOD_PRICE;
	TOTAL_UNITS_LOCAL_INVENTORY = CAPITAL_GOOD_STORE;

    	TOTAL_ASSETS = PAYMENT_ACCOUNT /*+TOTAL_VALUE_CAPITAL_STOCK*/
	+ TOTAL_VALUE_LOCAL_INVENTORY;
		
	PLANNED_TOTAL_ASSETS = PAYMENT_ACCOUNT  /*+ PLANNED_VALUE_CAPITAL_STOCK*/+  		
	TOTAL_VALUE_LOCAL_INVENTORY;
	
    	EQUITY = TOTAL_ASSETS - TOTAL_DEBT;

	printf("TOTAL_UNITS_LOCAL_INVENTORY %f \n",TOTAL_UNITS_LOCAL_INVENTORY);
    	printf("TOTAL_VALUE_LOCAL_INVENTORY %f \n",TOTAL_VALUE_LOCAL_INVENTORY);	
	printf("PAYMENT_ACCOUNT %f \n",PAYMENT_ACCOUNT);
	printf("TOTAL_ASSETS %f \n",TOTAL_ASSETS);
	printf("TOTAL_DEBT %f \n",TOTAL_DEBT);
	printf("EQUITY %f \n",EQUITY);
    	printf("************************************************ \n");
  
    return 0;
}

/*
 * \fn: int Firm_compute_financial_needs()
 * \brief: This function computes the financial needs for executing the payments.
 * The values computed in this function refer to:
 *  - the payouts from the previous production period
 * The payout policy can be subject to revision if it turns out to be unsupportable by the obtained financial resources.
 */
int IGFirm_compute_total_liquidity_needs()
{	printf("IN FUNCTION: IGFirm_compute_total_liquidity_needs() \n");
	printf("*************************************************** \n");
	
	PRODUCTION_LIQUIDITY_NEEDS = PLANNED_PRODUCTION_COSTS;
    	FINANCIAL_LIQUIDITY_NEEDS = TOTAL_INTEREST_PAYMENT + TOTAL_DEBT_INSTALLMENT_PAYMENT + 	
	TAX_PAYMENT + TOTAL_DIVIDEND_PAYMENT;
	
	printf("PLANNED_PRODUCTION_COSTS %f  = \n",PLANNED_PRODUCTION_COSTS);
	printf("PRODUCTION_LIQUIDITY_NEEDS %f \n",PRODUCTION_LIQUIDITY_NEEDS);
	printf("\n");
	printf("FINANCIAL_LIQUIDITY_NEEDS %f = \n",FINANCIAL_LIQUIDITY_NEEDS);
	printf("TOTAL_INTEREST_PAYMENT %f  + \n",TOTAL_INTEREST_PAYMENT);
	printf("TOTAL_DEBT_INSTALLMENT_PAYMENT %f  + \n",TOTAL_DEBT_INSTALLMENT_PAYMENT);
	printf("TAX_PAYMENT %f  + \n",TAX_PAYMENT);
	printf("TOTAL_DIVIDEND_PAYMENT %f \n",TOTAL_DIVIDEND_PAYMENT);

	printf("\n");
	
    	
    	//Check if additional external financial needs are required for total financial needs 	
	//(direct payable and delayed payable)    
    	TOTAL_FINANCIAL_NEEDS =  PRODUCTION_LIQUIDITY_NEEDS + FINANCIAL_LIQUIDITY_NEEDS;

	printf("PAYMENT_ACCOUNT %f  > or < \n",PAYMENT_ACCOUNT);
	printf("TOTAL_FINANCIAL_NEEDS %f  = PRODUCTION_LIQUIDITY_NEEDS + FINANCIAL_LIQUIDITY_NEEDS\n",TOTAL_FINANCIAL_NEEDS);

    	
    	//Check if external financing is needed

    	//CASE 1: No external financing needed
        if (PAYMENT_ACCOUNT >= TOTAL_FINANCIAL_NEEDS)
        {        	
            //printf("Firm_financial_needs, External financing: case 1.");
            EXTERNAL_FINANCIAL_NEEDS = 0.0;                   
        }
        else
        {
        	//external financing needed
        	EXTERNAL_FINANCIAL_NEEDS = TOTAL_FINANCIAL_NEEDS - PAYMENT_ACCOUNT;
        }
	
	
	printf("EXTERNAL_FINANCIAL_NEEDS %f \n",EXTERNAL_FINANCIAL_NEEDS);
	printf("********************************************************* \n");
 
 
    return 0;
}


/*
 * The firm executes the actual payments over the previous period's profits:
 *  - total_debt_installment_payment
 *  - total_interest_payments
 *  - tax_payment
 * The payments are all subtracted from the payment account.
 */
int IGFirm_execute_financial_payments()
{	
	printf("IN FUNCTION: IGFirm_execute_financial_payments()\n");
	printf("**************************************************\n");

	int imax;
	int i;	
	double debt_installment = 0.0;
	double interest_payment = 0.0;
	
	//step 1: actual tax_payment to government
	
	if (TAX_PAYMENT>0.0)
	{
		add_tax_payment_message(GOV_ID, TAX_PAYMENT);
		PAYMENT_ACCOUNT -= TAX_PAYMENT;
	}

	printf("PAYMENT_ACCOUNT  %f -  \n",PAYMENT_ACCOUNT);
	printf("TAX_PAYMENT  %f - \n",TAX_PAYMENT);

	//step 2: actual interest_payments and installment_payments

	
	//Sending installment_message to banks at which the firm has a loan 

	
   	 imax = LOANS.size;
   	 for (i=0; i<imax;i++)
	 {
		    //decrease payment_account with the interest_payment
			if(LOANS.array[i].nr_periods_before_repayment!=PERIODS_TO_REPAY_LOANS+1)
		    	{
			 
				if(TOTAL_INTEREST_PAYMENT>0)
				{
					PAYMENT_ACCOUNT -= LOANS.array[i].interest_payment;
					add_interest_payment_message(ID,
					LOANS.array[i].bank_id,LOANS.array[i].interest_payment);
					interest_payment+=LOANS.array[i].interest_payment;
				}
			
				if(TOTAL_DEBT_INSTALLMENT_PAYMENT>0)	
				{	
		        	//decrease payment_account with the installment payment
		        	PAYMENT_ACCOUNT -= LOANS.array[i].installment_amount;
		        	debt_installment+=LOANS.array[i].installment_amount;
			
		        	//decrease the value of the loan with the debt_installment_payment:
		        	LOANS.array[i].loan_value -= LOANS.array[i].installment_amount;
		       
		        	//decrease the value of the nr_periods_before_repayment
		   	
			
		        	//Sending debt_installment_payment_msg to all banks at which the 
				//firm has a loan
		       
		        	add_debt_installment_payment_message(ID,
				LOANS.array[i].bank_id,LOANS.array[i].credit_id, 
				LOANS.array[i].installment_amount);
				}	
			}
		        //If nr_periods_before_maturity == 0, remove the loan item
		        if (LOANS.array[i].nr_periods_before_repayment==0)
		        {
		            remove_debt_item(&LOANS, i);
				i--;
				if(LOANS.size==0)
				break;
		        }
			else
			{
			    	LOANS.array[i].nr_periods_before_repayment -= 1;
			}
	  }

	
	printf("TOTAL_INTEREST_PAYMENT %f  - \n",TOTAL_INTEREST_PAYMENT);
	printf("TOTAL_DEBT_INSTALLMENT_PAYMENT %f  -  \n",TOTAL_DEBT_INSTALLMENT_PAYMENT);
	

		//step 3: actual dividend payments
 	    	//Actual payments to the bank are paid at end of day when the firm sends its 
		//bank_update message 

        	//add dividend_per_share_msg(firm_id, current_dividend_per_share) to shareholders 
		//(dividend per share)     
		if(TOTAL_DIVIDEND_PAYMENT>0)
		{
			
			add_dividend_per_share_message(ID, CURRENT_DIVIDEND_PER_SHARE);

	        //decrease payment_account with the total_dividend_payment
	        PAYMENT_ACCOUNT -= TOTAL_DIVIDEND_PAYMENT;
		
		}

		
	
	printf("TOTAL_DIVIDEND_PAYMENT %f  = \n",TOTAL_DIVIDEND_PAYMENT);
	printf("PAYMENT_ACCOUNT %f \n",PAYMENT_ACCOUNT);
	printf("************************************************** \n");
	
		
    return 0;
}
