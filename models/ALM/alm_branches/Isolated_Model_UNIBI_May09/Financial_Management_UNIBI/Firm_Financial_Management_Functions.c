#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"

/************Firm Role: Financial Management Role ********************************/


/*
 * \fn: int Firm_financial_payments()
 * \brief: This function computes the income statement of the firm.
 * 
 * The firm computes the actual payments by setting these values:
 *  - total_debt_installment_payment
 *  - total_interest_payments
 *  - tax_payment
 *  - total_dividend_payment
 * The payments are all subtracted from the payment account.
 */
int Firm_compute_financial_payments()
{


    double interest_payment;
    int imax;
    int i;

    //double PAYMENT_ACCOUNT: account out of which payments are made, to be separated from the income_account on which current sale receipts are incoming

    //double_array LOANS                : dynamic array of structs with each struct a loan_item
    //struct debt_item
    //int bank_id                       : bank at which the loan was obtained
    //double loan_value                 : total value of the loan remaining
    //double interest_rate              : interest for this loan
    //double interest_payment           : interest to be paid this period
    //double debt_installment_payment   : installment payment per period
    //int nr_periods_before_maturity    : nr of periods to go before the loan has to be fully repaid

    //step 1: compute total interest payments
    TOTAL_INTEREST_PAYMENT=0.0;
    imax = LOANS.size;
    //printf("Firm_Financial_Management_Function, line 42: LOANS.size=%d\n", imax);
    
    for (i=0; i<imax;i++)
    {
        interest_payment = LOANS.array[i].interest_rate * LOANS.array[i].loan_value;                         

        //add to total
        TOTAL_INTEREST_PAYMENT += interest_payment;

        LOANS.array[i].interest_payment = interest_payment; 
    }
    
    //step 2: compute total debt installment payments
    TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
    TOTAL_DEBT=0.0;
    for (i=0; i<imax;i++)
    {
        //printf("Firm_Financial_Management_Function, line 58: Adding loan values to total debt\n");
        //compute current total debt
        TOTAL_DEBT += LOANS.array[i].loan_value;
        
        //add debt_installment_payment to total installment payment
        TOTAL_DEBT_INSTALLMENT_PAYMENT += LOANS.array[i].installment_amount;
    }
    
    
    
    return 0;
}

/*
 * \fn: int Firm_compute_income_statement()
 * \brief: This function computes the income statement of the firm.
 */
int Firm_compute_income_statement()
{
    
    
    //In the future: if we want to include sales_costs
    //SALES_COSTS = 0;
   
    // compute net earnings
    EARNINGS = CUM_REVENUE - TOTAL_INTEREST_PAYMENT - CALC_PRODUCTION_COSTS;
    
 if(EARNINGS>0.0) 
    TAX_PAYMENT = TAX_RATE_CORPORATE * EARNINGS;
    else
     TAX_PAYMENT = 0;

    PREVIOUS_NET_EARNINGS = NET_EARNINGS;
    NET_EARNINGS = EARNINGS - TAX_PAYMENT;

	add_double(&LAST_NET_EARNINGS,NET_EARNINGS);
	

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
        
    
    return 0;
}

/*
 * \fn: int Firm_compute_dividend_accruals()
 * \brief: This function computes a money stock that is put aside for the dividend payment on eanrings for the current year.  
 */
int Firm_compute_dividend_accruals()
{

	
	int i;
	double mean_earnings;
	

	mean_earnings = 0.0;

	for(i=0; i <LAST_NET_EARNINGS.size;i++)
	{	if(ID==1)
		{
		printf("EARNINGS: Period %d Amount: %f\n",(12-i),LAST_NET_EARNINGS.array[i]);
		}		
	mean_earnings += LAST_NET_EARNINGS.array[i];	
	}

	mean_earnings= mean_earnings/ LAST_NET_EARNINGS.size;

	//dividend_share = mean_earnings* DIVIDEND_RATE;

	
	if(ID==1)
	{
	printf(" MEAN EARNINGS %f\n",mean_earnings);
	
	printf("LAST ACCRUALS %f\n", ACCRUALS);
	}

	/*SIMON*/
	
	ADDITIONAL_ACCRUALS = NET_EARNINGS* DIVIDEND_RATE;
	DIVIDEND_ACCRUALS += ADDITIONAL_ACCRUALS;
	if(ID==1)
	{
	printf("DIVIDEND_ACCRUALS %f\n", DIVIDEND_ACCRUALS);
	printf("ADDITIONAL_ACCRUALS %f\n", ADDITIONAL_ACCRUALS);
	}
	if(ADDITIONAL_ACCRUALS < 0)
	{
		PAYMENT_ACCOUNT += min(ACCRUALS,-ADDITIONAL_ACCRUALS);
		ACCRUALS -= min(ACCRUALS,-ADDITIONAL_ACCRUALS);
		if(ID==1)
		{
		printf("ADDITIONAL ACCRUALS NEGATIVE");
		printf("ACCRUALS %f\n", ACCRUALS);
		}
	}
		

		//PAYMENT_ACCOUNT += DIVIDEND_ACCRUALS;
		//ACCRUALS -= DIVIDEND_ACCRUALS;
		//DIVIDEND_ACCRUALS = 0;
		//ADDITIONAL_ACCRUALS = 0.0;
		
		
		if(ID==1)
		{
		printf("CASE 1:\n");
		printf("ACCRUALS %f\n", ACCRUALS);
		printf("DIVIDEND_ACCRUALS %f\n", DIVIDEND_ACCRUALS);
		printf("ADDITIONAL_ACCRUALS %f\n", ADDITIONAL_ACCRUALS);
		}
	
	
	
	
	

return 0;
}


/*
 * \fn: int Firm_compute_dividend_accruals()
 * \brief: This function subtracts the accruals from the payment account
 */
int Firm_update_accruals()
{

	// Add additional accruals to the accrual stock and decrease the payment account
	
	if(DIVIDEND_ACCRUALS<0.0)
	{

	ACCRUALS+= max(0,ADDITIONAL_ACCRUALS+DIVIDEND_ACCRUALS);
	PAYMENT_ACCOUNT - max(0,ADDITIONAL_ACCRUALS+DIVIDEND_ACCRUALS);
	}else
	{
	ACCRUALS+= max(0,ADDITIONAL_ACCRUALS);
	PAYMENT_ACCOUNT - max(0,ADDITIONAL_ACCRUALS);

	}	
		
		
			if(ID==1)
			printf(" VERRECHNUNG:ACCRUALS%f   \n",ACCRUALS);

return 0;
}


/*
 * \fn: int Firm_compute_dividends()
 * \brief: This function computes the total dividend amount for the next year and the monthly pay out. The dividends are simply the accruals for dividends collected over the last year.
 */
int Firm_compute_dividends()
{
   /*1: print the printf-statements*/
	
	 int i;
	// Compute the dividends paid out in 12 monthly pieces
	if(DIVIDEND_ACCRUALS > 0)
	{
		TOTAL_DIVIDEND_PAYMENT = DIVIDEND_ACCRUALS/12; 
		if(ID==1)
		printf("1:TOTAL_DIVIDEND_PAYMENT %f\n",TOTAL_DIVIDEND_PAYMENT);
	}
	else
	{
		TOTAL_DIVIDEND_PAYMENT = 0;
		if(ID==1)
		printf("2:TOTAL_DIVIDEND_PAYMENT %f\n",TOTAL_DIVIDEND_PAYMENT);
	}

	//Resetting the DIVIDEND_ACCRUALS counter:
	DIVIDEND_ACCRUALS =0.0;

	//Delete the monthly earnings 
	for(i=0; i <LAST_NET_EARNINGS.size;i++)
	{
		remove_double(&LAST_NET_EARNINGS,0);
		i--;
	}    

	/*1: print the printf-statements*/
	if(ID==1)
	{
		printf("NET_EARNINGS %f \n",NET_EARNINGS);
		printf("CURRENT_SHARES_OUTSTANDING %d \n",CURRENT_SHARES_OUTSTANDING);
		printf("TOTAL_DIVIDEND_PAYMENT %f \n",TOTAL_DIVIDEND_PAYMENT);
		printf("PREVIOUS_EARNINGS_PER_SHARE %f \n",PREVIOUS_EARNINGS_PER_SHARE);
		printf("EARNINGS_PER_SHARE %f \n",EARNINGS_PER_SHARE);
		printf("PREVIOUS_DIVIDEND_PER_SHARE %f \n",PREVIOUS_DIVIDEND_PER_SHARE);
		printf("CURRENT_DIVIDEND_PER_SHARE %f \n",CURRENT_DIVIDEND_PER_SHARE);
		printf("****************************************************************************\n");
	}	
    return 0;

    return 0;
}

int Firm_compute_total_financial_payments()
{
    
    //This variable is not used anywhere: it is the sum of financial_liquidity_needs and production_liquidity_needs
    //but excluding the tax_payments. The tax_payments do not need to be financed since we assume they can always be paid out of earnings. 
    TOTAL_PAYMENTS = TOTAL_INTEREST_PAYMENT + TOTAL_DEBT_INSTALLMENT_PAYMENT + TOTAL_DIVIDEND_PAYMENT + TAX_PAYMENT + PLANNED_PRODUCTION_COSTS;

    
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
int Firm_compute_balance_sheet()
{
    double sum, sum_1;
    int imax;
    int i;

    //compute the equity of the firm
    //TOTAL_ASSETS=
    //+ PAYMENT_ACCOUNT: remaining cash holdings of the firm
    //+ TOTAL_VALUE_CAPITAL_STOCK: estimated value of the capital stock (this is determined in the capital goods market role)
    //+ TOTAL_VALUE_LOCAL_INVENTORY: value of all the local inventory stocks held at the malls        
    
    

    //TOTAL_VALUE_LOCAL_INVENTORY: estimated value of local inventory stocks at current mall prices
    //We loop over the malls and sum the value of all local inventory stocks
    imax = CURRENT_MALL_STOCKS.size;
    sum=0.0;
    sum_1=0.0;
    
    for (i=0;i<imax;i++)
    {
        sum += PRICE*CURRENT_MALL_STOCKS.array[i].current_stock;
        sum_1+=CURRENT_MALL_STOCKS.array[i].current_stock;
        //When malls have different current_price use this code:
        //sum += CURRENT_MALL_STOCKS.array[i].current_price * CURRENT_MALL_STOCKS.array[i].current_stock;
    }
    TOTAL_VALUE_LOCAL_INVENTORY=sum;
    TOTAL_UNITS_LOCAL_INVENTORY = sum_1;

    TOTAL_ASSETS = PAYMENT_ACCOUNT + TOTAL_VALUE_CAPITAL_STOCK + TOTAL_VALUE_LOCAL_INVENTORY+ACCRUALS ;
        
    PLANNED_TOTAL_ASSETS = PAYMENT_ACCOUNT  + PLANNED_VALUE_CAPITAL_STOCK +  TOTAL_VALUE_LOCAL_INVENTORY+ACCRUALS ;
    
    EQUITY = TOTAL_ASSETS - TOTAL_DEBT;
    
    //printf("\nTOTAL_ASSETS in functions.c file: %f\n", TOTAL_ASSETS);

  
    return 0;
}

/*
 * \fn: int Firm_compute_financial_needs()
 * \brief: This function computes the financial needs for executing the payments.
 * The values computed in this function refer to:
 *  - the payouts from the previous production period
 * The payout policy can be subject to revision if it turns out to be unsupportable by the obtained financial resources.
 */
int Firm_compute_total_liquidity_needs()
{
 
    //step 12B: set production and payout financial_needs
	PRODUCTION_LIQUIDITY_NEEDS = PLANNED_PRODUCTION_COSTS;
    	FINANCIAL_LIQUIDITY_NEEDS = TOTAL_INTEREST_PAYMENT + TOTAL_DEBT_INSTALLMENT_PAYMENT + 	
	TAX_PAYMENT + max(0,ADDITIONAL_ACCRUALS+min(0,DIVIDEND_ACCRUALS));

    //step 12C:
    //Check if additional external financial needs are required for total financial needs (direct payable and delayed payable)    
    TOTAL_FINANCIAL_NEEDS =  PRODUCTION_LIQUIDITY_NEEDS + FINANCIAL_LIQUIDITY_NEEDS;

    //step 12D:
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
 
    return 0;
}


/*
 * The firm executes the actual payments over the previous period's profits:
 *  - total_debt_installment_payment
 *  - total_interest_payments
 *  - tax_payment
 * The payments are all subtracted from the payment account.
 */
int Firm_execute_financial_payments()
{   

    int imax;
    int i;
    //printf("PAYMENT_ACCOUNT firm %d %f\n",ID,PAYMENT_ACCOUNT);

    
    double debt_installment = 0.0;
    double interest_payment = 0.0;
    
    //step 1: actual tax_payment to government
    
    if (TAX_PAYMENT>0.0)
    {
        add_tax_payment_message(GOV_ID, TAX_PAYMENT);
        PAYMENT_ACCOUNT -= TAX_PAYMENT;
    }
    //step 2: actual interest_payments and installment_payments

    
    //Sending installment_message to banks at which the firm has a loan 

    
     imax = LOANS.size;
     for (i=0; i<imax;i++)
     {
            //decrease payment_account with the interest_payment
            if(LOANS.array[i].nr_periods_before_repayment!=PERIODS_TO_REPAY_LOANS+1)
            {
             
                if(TOTAL_INTEREST_PAYMENT>0.0)
                {
                    PAYMENT_ACCOUNT -= LOANS.array[i].interest_payment;
                    add_interest_payment_message(ID,LOANS.array[i].bank_id,LOANS.array[i].interest_payment);
                    interest_payment+=LOANS.array[i].interest_payment;
                }
            
                if(TOTAL_DEBT_INSTALLMENT_PAYMENT>0.0)    
                {   
                    //decrease payment_account with the installment payment
                    PAYMENT_ACCOUNT -= LOANS.array[i].installment_amount;
                    debt_installment+=LOANS.array[i].installment_amount;
            
                    //decrease the value of the loan with the debt_installment_payment:
                    LOANS.array[i].loan_value -= LOANS.array[i].installment_amount;
               
                    //decrease the value of the nr_periods_before_repayment
            
            
                    //Sending debt_installment_payment_msg to all banks at which the firm has a loan
               
                    add_debt_installment_payment_message(ID,LOANS.array[i].bank_id,LOANS.array[i].credit_id, LOANS.array[i].installment_amount);
                }   
            }
                //If nr_periods_before_maturity == 0, remove the loan item
                if (LOANS.array[i].nr_periods_before_repayment==0)
                {
                    remove_debt_item(&LOANS, i);
                }
                else
                {
                    LOANS.array[i].nr_periods_before_repayment -= 1;
                }
      }

	

       //step 3: actual dividend payments
        //Actual payments to the bank are paid at end of day when the firm sends its bank_update message 

        //add dividend_per_share_msg(firm_id, current_dividend_per_share) to shareholders (dividend per share)     
        if(TOTAL_DIVIDEND_PAYMENT>0.0)
        {
            add_dividend_per_share_message(ID, CURRENT_DIVIDEND_PER_SHARE);

            //decrease accruals with the total_dividend_payment
            ACCRUALS -= TOTAL_DIVIDEND_PAYMENT;
        }   
        
        
    return 0;
}
