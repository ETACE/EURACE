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


int Firm_compute_dividends()
{
    
    
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
    
    //TOTAL_DIVIDEND_PAYMENT = TOTAL_DIVIDEND_PAYMENT * (EARNINGS_PER_SHARE/PREVIOUS_EARNINGS_PER_SHARE);


    if (NET_EARNINGS > 0.0 )
        TOTAL_DIVIDEND_PAYMENT =  DIVIDEND_RATE*NET_EARNINGS; 
    else
    TOTAL_DIVIDEND_PAYMENT=0.0;
    
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

    TOTAL_ASSETS = PAYMENT_ACCOUNT + TOTAL_VALUE_CAPITAL_STOCK + TOTAL_VALUE_LOCAL_INVENTORY;
        
    PLANNED_TOTAL_ASSETS = PAYMENT_ACCOUNT  + PLANNED_VALUE_CAPITAL_STOCK +  TOTAL_VALUE_LOCAL_INVENTORY;
    
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
    FINANCIAL_LIQUIDITY_NEEDS = TOTAL_INTEREST_PAYMENT + TOTAL_DEBT_INSTALLMENT_PAYMENT + TAX_PAYMENT + TOTAL_DIVIDEND_PAYMENT;

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
			i--;
			if(LOANS.size==0)
			break;
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

            //decrease payment_account with the total_dividend_payment
            PAYMENT_ACCOUNT -= TOTAL_DIVIDEND_PAYMENT;
        }   
        
        
    return 0;
}
