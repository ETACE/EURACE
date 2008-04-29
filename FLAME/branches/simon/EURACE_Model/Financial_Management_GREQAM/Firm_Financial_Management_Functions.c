#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
#include "../Firm_Library_Functions.h"


/************Firm Role: Financial Management Role ********************************/


/*
 * \fn: int Firm_compute_income_statement()
 * \brief: This function computes the income statement of the firm.
 */
int Firm_compute_income_statement()
{
    //In the future: if we want to include sales_costs
    //SALES_COSTS = 0;
    //EBIT = CUM_REVENUE - SALES_COSTS
    EBIT = CUM_REVENUE; //net revenues = receipts - sales_costs;       
    
    //update the cash holdings
    PAYMENT_ACCOUNT += EBIT;
    
    //Reset the counters
    CUM_TOTAL_SOLD_QUANTITY = 0.0;
    CUM_REVENUE = 0.0;        
    
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
    //EARNINGS -= TOTAL_DEBT_INSTALLMENT_PAYMENT;
    	
    TAX_PAYMENT = TAX_RATE_CORPORATE * EARNINGS;
    PREVIOUS_NET_EARNINGS = NET_EARNINGS;
    NET_EARNINGS = EARNINGS - TAX_PAYMENT;
    
    //debt_installment_payments subtracted from earnings after taxes
    NET_EARNINGS -= TOTAL_DEBT_INSTALLMENT_PAYMENT;
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
    
    //option 2: total dividend payment increases with same ratio as earnings
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
    //+ TOTAL_VALUE_CAPITAL_STOCK: estimated value of the capital stock (this is determined in the capital goods market role)
    //+ TOTAL_VALUE_LOCAL_INVENTORY: value of all the local inventory stocks held at the malls        
    
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
    //step 12A:
    PLANNED_CUM_REVENUE = PRICE*PLANNED_PRODUCTION_QUANTITY;
    
    //step 12B: set direct and delayed financial_needs for the upcoming production cycle
    DIRECT_FINANCIAL_NEEDS = PLANNED_PRODUCTION_COSTS;
    DELAYED_FINANCIAL_NEEDS = PLANNED_TOTAL_INTEREST_PAYMENT + PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT + PLANNED_TOTAL_DIVIDEND_PAYMENT;

    //step 12C:
    //Check if additional external financing is required for total financial needs (direct payable and delayed payable)    
    TOTAL_FINANCIAL_NEEDS =  DIRECT_FINANCIAL_NEEDS + DELAYED_FINANCIAL_NEEDS;

    //step 12D:
    //Check if external financing is needed

    //CASE 1: No external financing needed
        if (PAYMENT_ACCOUNT >= (DIRECT_FINANCIAL_NEEDS + DELAYED_FINANCIAL_NEEDS))
        {
        	DIRECT_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=0;
        	DELAYED_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=0;
        	
            //printf("Firm_compute_payout_policy, External financing: case 1.");
        	INTERNAL_FINANCIAL_NEEDS = DIRECT_FINANCIAL_NEEDS + DELAYED_FINANCIAL_NEEDS;
            EXTERNAL_FINANCIAL_NEEDS = 0;                   
        }
        
    //CASE 2: No external financing needed: direct is paid by payment account, delayed is paid by (payment - direct + cum_revenues)
        if ( (PAYMENT_ACCOUNT >= DIRECT_FINANCIAL_NEEDS)
            &&((PAYMENT_ACCOUNT - DIRECT_FINANCIAL_NEEDS + PLANNED_CUM_REVENUE) >= DELAYED_FINANCIAL_NEEDS)
            &&(PAYMENT_ACCOUNT < (DIRECT_FINANCIAL_NEEDS + DELAYED_FINANCIAL_NEEDS)) )
        {
           	DIRECT_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=0;
            DELAYED_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=0;

            //printf("Firm_compute_payout_policy, External financing: case 2.");
        	INTERNAL_FINANCIAL_NEEDS = DIRECT_FINANCIAL_NEEDS + DELAYED_FINANCIAL_NEEDS;
            EXTERNAL_FINANCIAL_NEEDS = 0;            
        } 
        
    //CASE 3: External financing needed for direct payments, not for delayed payments
        if ( (PAYMENT_ACCOUNT < DIRECT_FINANCIAL_NEEDS) &&
             ((PAYMENT_ACCOUNT - DIRECT_FINANCIAL_NEEDS + PLANNED_CUM_REVENUE) >= DELAYED_FINANCIAL_NEEDS))
        {
           	DIRECT_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=1;
            DELAYED_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=0;

            //printf("Firm_compute_payout_policy, External financing: case 3.");
            INTERNAL_FINANCIAL_NEEDS = PAYMENT_ACCOUNT;
            EXTERNAL_FINANCIAL_NEEDS = DIRECT_FINANCIAL_NEEDS - PAYMENT_ACCOUNT;
        }
                
    //CASE 4: External financing needed for delayed payments, not for direct payments
        if ( (PAYMENT_ACCOUNT >= DIRECT_FINANCIAL_NEEDS) &&
             ((PAYMENT_ACCOUNT - DIRECT_FINANCIAL_NEEDS + PLANNED_CUM_REVENUE) < DELAYED_FINANCIAL_NEEDS))
        {
           	DIRECT_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=0;
            DELAYED_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=1;

            //printf("Firm_compute_payout_policy, External financing: case 4.");
        	INTERNAL_FINANCIAL_NEEDS = DIRECT_FINANCIAL_NEEDS;
            EXTERNAL_FINANCIAL_NEEDS = DELAYED_FINANCIAL_NEEDS - (PAYMENT_ACCOUNT+PLANNED_CUM_REVENUE-DIRECT_FINANCIAL_NEEDS);
        }
        
    //CASE 5: External financing is needed to pay for both the direct and delayed payments
        if ( (PAYMENT_ACCOUNT < DIRECT_FINANCIAL_NEEDS) &&
             ((PAYMENT_ACCOUNT - DIRECT_FINANCIAL_NEEDS + PLANNED_CUM_REVENUE) < DELAYED_FINANCIAL_NEEDS))
        {
           	DIRECT_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=1;
            DELAYED_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING=1;

            //printf("Firm_compute_payout_policy, External financing: case 5.");
            INTERNAL_FINANCIAL_NEEDS = PAYMENT_ACCOUNT;
            EXTERNAL_FINANCIAL_NEEDS = DIRECT_FINANCIAL_NEEDS + DELAYED_FINANCIAL_NEEDS - (PAYMENT_ACCOUNT + PLANNED_CUM_REVENUE);            
        }
    
    //printf("\n Checking: INTERNAL_FINANCIAL_NEEDS=%f\n", INTERNAL_FINANCIAL_NEEDS);
    //printf("\n Checking: EXTERNAL_FINANCIAL_NEEDS=%f\n", EXTERNAL_FINANCIAL_NEEDS);
    RETAINED_EARNINGS_RATIO = INTERNAL_FINANCIAL_NEEDS/NET_EARNINGS;
    
    return 0;
}
