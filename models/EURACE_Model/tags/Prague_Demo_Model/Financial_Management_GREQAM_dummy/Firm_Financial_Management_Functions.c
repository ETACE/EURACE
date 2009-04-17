#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"

/************Firm Role: Financial Management Role ********************************/

/*
 * \fn Firm_compute_financial_payments()
 * \brief Function to compute the prior financial commitments of the firm: interests, installments, taxes.
 * 
 * The firm computes the commitments by setting these values:
 *  - total_debt_installment_payment
 *  - total_interest_payments
 */
int Firm_compute_financial_payments()
{
    int imax;
    int i;
    double interest_payment =0.0;
    
    //double PAYMENT_ACCOUNT            : account out of which payments are made

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
    for (i=0; i<imax; i++)
    {
        interest_payment = LOANS.array[i].interest_rate
                * LOANS.array[i].loan_value;

        //add to total
        TOTAL_INTEREST_PAYMENT += interest_payment;
    }

    //step 2: compute total debt installment payments
    TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
    TOTAL_DEBT=0.0;
    for (i=0; i<imax; i++)
    {
        //compute current total debt
        TOTAL_DEBT += LOANS.array[i].loan_value;

        //add debt_installment_payment to total installment payment
        TOTAL_DEBT_INSTALLMENT_PAYMENT += LOANS.array[i].installment_amount;
    }

    return 0;
}

/*
 * \fn Firm_compute_income_statement()
 * \brief Function to compute the income statement of the firm.
 */
int Firm_compute_income_statement()
{
    //In the future: if we want to include sales_costs
    //SALES_COSTS = 0;

    // compute net earnings
    EARNINGS = CUM_REVENUE - TOTAL_INTEREST_PAYMENT - CALC_PRODUCTION_COSTS;

    if (EARNINGS>0.0)
        TAX_PAYMENT = TAX_RATE_CORPORATE * EARNINGS;
    else
        TAX_PAYMENT = 0.0;
    
    PREVIOUS_NET_EARNINGS = NET_EARNINGS;
    NET_EARNINGS = EARNINGS - TAX_PAYMENT;

    //continue balance sheet (data pertaining to the period that just ended)
    PREVIOUS_EARNINGS_PER_SHARE = EARNINGS_PER_SHARE;
    
    if (CURRENT_SHARES_OUTSTANDING>0)
        EARNINGS_PER_SHARE = NET_EARNINGS/CURRENT_SHARES_OUTSTANDING;

    return 0;
}

/*
 * \fn Firm_compute_dividends()
 * \brief Function to compute the total dividend payout of the firm.
 */
int Firm_compute_dividends()
{

    //option 2: total dividend payment increases with same ratio as net earnings
    //This is very dangerous, since earnings may fluctuate violently
    //TOTAL_DIVIDEND_PAYMENT *= NET_EARNINGS/PREVIOUS_NET_EARNINGS;

    //option 3: keep dividend per share constant
    //total divided payment increases with same ratio as current_shares_outstanding
    //TOTAL_DIVIDEND_PAYMENT *= CURRENT_SHARES_OUTSTANDING/PREVIOUS_SHARES_OUTSTANDING;

    //option 4: keep earnings per share constant
    //total divided payment increases with same ratio as earnings per share
    //this keeps earnings per share constant
  //  if (PREVIOUS_EARNINGS_PER_SHARE>0.0)
    //    TOTAL_DIVIDEND_PAYMENT *= (EARNINGS_PER_SHARE/PREVIOUS_EARNINGS_PER_SHARE)
      //                             *(CURRENT_SHARES_OUTSTANDING/PREVIOUS_SHARES_OUTSTANDING);

    //option 5: keep dividend to earnings ratio constant (dont let it fall), but do not decrease the dividend per share ratio.
    /*
     if (CURRENT_DIVIDEND_PER_EARNINGS < PREVIOUS_DIVIDEND_PER_EARNINGS)
     {
         //Maintain the dividend to earnings ratio
         //D_{t} = (D_{t-1}/E_{t-1})*E_{t}
         TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_EARNINGS * NET_EARNINGS;
         
         //But do not decrease the dividend per share ratio
         if (TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING < CURRENT_DIVIDEND_PER_SHARE)
            TOTAL_DIVIDEND_PAYMENT = CURRENT_DIVIDEND_PER_SHARE * CURRENT_SHARES_OUTSTANDING;
     }
     else
     {
         //the dividend to earnings ratio did not decrease
         //else keep the dividend per share ratio constant
         TOTAL_DIVIDEND_PAYMENT = PREVIOUS_DIVIDEND_PER_SHARE*CURRENT_SHARES_OUTSTANDING;
     }
     */

    //option 6: replace the total divided payment by the same amount in share repurchases
    // This option should be conditional on the current share price being "historically" low
    /*
     if(CURRENT_STOCK_PRICE LOW)
     {
         TOTAL_STOCK_REPURCHASE = TOTAL_DIVIDEND_PAYMENT;
         TOTAL_DIVIDEND_PAYMENT =0.0;
         
         //Number of shares repurchased (stock buying order)
         NR_STOCK_REPURCHASE = TOTAL_STOCK_REPURCHASE/CURRENT_STOCK_PRICE;
     }
     */

    //Determine total_dividend_payment when it is zero, and there are positive net earnings.
    //Set total divided payment equal to some dividend-earnings ratio (a parameter)
    
 
        TOTAL_DIVIDEND_PAYMENT = CONST_DIVIDEND_EARNINGS_RATIO * EARNINGS;
        //printf("\n In Firm_compute_dividends: setting TOTAL_DIVIDEND_PAYMENT = %2.4f\n", TOTAL_DIVIDEND_PAYMENT):
    
        
    //Always check:
    if (EARNINGS<0.0)
        TOTAL_DIVIDEND_PAYMENT = 0.0;
    
    //Continue with computation of ratios
    PREVIOUS_DIVIDEND_PER_SHARE = CURRENT_DIVIDEND_PER_SHARE;
    
    if (CURRENT_SHARES_OUTSTANDING>0)
        CURRENT_DIVIDEND_PER_SHARE = TOTAL_DIVIDEND_PAYMENT
                /CURRENT_SHARES_OUTSTANDING;
    else CURRENT_DIVIDEND_PER_SHARE = 0.0;
    
    PREVIOUS_DIVIDEND_PER_EARNINGS = CURRENT_DIVIDEND_PER_EARNINGS;
    
    if (NET_EARNINGS>0.0)
        CURRENT_DIVIDEND_PER_EARNINGS = TOTAL_DIVIDEND_PAYMENT/NET_EARNINGS;
    else
        CURRENT_DIVIDEND_PER_EARNINGS = 0.0;
    
    return 0;
}

/*
 * \fn Firm_compute_total_financial_payments()
 * \brief Function to compute the total financial payments of the firm: interest, installments, taxes, production costs, dividends.
 * 
 *  - total_interest_payment
 *  - total_debt_installment_payment
 *  - total_dividend_payment
 *  - tax_payment
 *  - production_costs
 */
int Firm_compute_total_financial_payments()
{
    //This variable is not used anywhere: it is the sum of financial_liquidity_needs and production_liquidity_needs
    //but excluding the tax_payments. The tax_payments do not need to be financed since we assume they can always be paid out of earnings. 
    TOTAL_PAYMENTS = TOTAL_INTEREST_PAYMENT + TOTAL_DEBT_INSTALLMENT_PAYMENT
            + TOTAL_DIVIDEND_PAYMENT + TAX_PAYMENT + PRODUCTION_COSTS;
    return 0;
}

/*
 * \fn Firm_compute_balance_sheet()
 * \brief Function to compute the balance sheet of the firm.
 * We compute these values:
 *  - total_value_capital_stock
 *  - total_value_inventory_stock
 *  - total_assets
 *  - equity
 */
int Firm_compute_balance_sheet()
{
    double sum;
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
    for (i=0; i<imax; i++)
    {
        sum += PRICE*CURRENT_MALL_STOCKS.array[i].current_stock;
        //When malls have different current_price use this code:
        //sum += CURRENT_MALL_STOCKS.array[i].current_price * CURRENT_MALL_STOCKS.array[i].current_stock;
    }
    TOTAL_VALUE_LOCAL_INVENTORY=sum;

    TOTAL_ASSETS = PAYMENT_ACCOUNT + TOTAL_VALUE_CAPITAL_STOCK
            + TOTAL_VALUE_LOCAL_INVENTORY;

    EQUITY = TOTAL_ASSETS - TOTAL_DEBT;

    if (EQUITY>0.0)
        DEBT_EQUITY_RATIO = TOTAL_DEBT/EQUITY;
    else DEBT_EQUITY_RATIO = 0.0;
    
    if (NET_EARNINGS>0.0)
        DEBT_EARNINGS_RATIO = TOTAL_DEBT/NET_EARNINGS;
    else DEBT_EARNINGS_RATIO = 0.0;
    
    return 0;
}

/*
 * \fn Firm_compute_total_liquidity_needs()
 * \brief Function to compute the total liquidity needs for executing payments.
 * The values computed in this function:
 *  - financial_liquidity_needs: to finance prior commitments + dividend payment
 *  - production_liquidity_needs: to finance production costs
 * The payout policy can be subject to revision if it turns out to be insupportable by the obtained financial resources.
 */
int Firm_compute_total_liquidity_needs()
{
    //step 12B: set production and payout financial_needs
    PRODUCTION_LIQUIDITY_NEEDS = PLANNED_PRODUCTION_COSTS;
    FINANCIAL_LIQUIDITY_NEEDS = TOTAL_INTEREST_PAYMENT
            + TOTAL_DEBT_INSTALLMENT_PAYMENT + TAX_PAYMENT;

    //step 12C:
    //Check if additional external financial needs are required for total financial needs (direct payable and delayed payable)    
    TOTAL_FINANCIAL_NEEDS = PRODUCTION_LIQUIDITY_NEEDS
            + FINANCIAL_LIQUIDITY_NEEDS + TOTAL_DIVIDEND_PAYMENT;

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
 * \fn Firm_check_financial_and_bankruptcy_state()
 * \brief Function that checks the balance sheet and sets flags for the bankruptcy- or financial crisis state.
 */
int Firm_check_financial_and_bankruptcy_state()
{

    BANKRUPTCY_ILLIQUIDITY_STATE=0;
    FINANCIAL_CRISIS_STATE=0;

    //Check bankrupcy condition
    if (PAYMENT_ACCOUNT < TOTAL_FINANCIAL_NEEDS)
    {
        //Code: check if payment account is also less than financial payments
        if (PAYMENT_ACCOUNT < TOTAL_INTEREST_PAYMENT
                + TOTAL_DEBT_INSTALLMENT_PAYMENT + TAX_PAYMENT)
        {
            BANKRUPTCY_ILLIQUIDITY_STATE=1;
        }
        if (PAYMENT_ACCOUNT >= TOTAL_INTEREST_PAYMENT
                + TOTAL_DEBT_INSTALLMENT_PAYMENT + TAX_PAYMENT)
        {
            //Financial crisis condition
            FINANCIAL_CRISIS_STATE=1;
        }
    }
    return 0;
}

/*
 * \fn Firm_set_bankruptcy_illiquidity()
 * \brief Function to set the type of bankruptcy to illiquidity, set the active flag to 0,
 *  start the bankruptcy idle counter, and then go to end_Firm state.
 */
int Firm_set_bankruptcy_illiquidity()
{
    //Set active flag to 0
    ACTIVE=0;
    
    //Start the idle counter
    BANKRUPTCY_IDLE_COUNTER = CONST_BANKRUPTCY_IDLE_PERIOD;
    
    //Set type of bankruptcy
    //Type 1: illiquidity
    BANKRUPTCY_INSOLVENCY_STATE  = 0;
    BANKRUPTCY_ILLIQUIDITY_STATE = 1;
    
    TOTAL_VALUE_LOCAL_INVENTORY = 0.0;
    
    //send msg to malls
    add_bankruptcy_illiquidity_message(ID);
        
    return 0;
}

/*
 * \fn Firm_in_financial_crisis()
 * \brief Function to resolve the financial crisis by lowering dividends.
 */
int Firm_in_financial_crisis()
{
    double payment_account_after_compulsory_payments;

    //Try to resolve the crisis

    //Recompute dividend
    //Set TOTAL_DIVIDEND_PAYMENT
    payment_account_after_compulsory_payments = PAYMENT_ACCOUNT
            - (TOTAL_INTEREST_PAYMENT + TOTAL_DEBT_INSTALLMENT_PAYMENT
                    + TAX_PAYMENT);
    TOTAL_DIVIDEND_PAYMENT = max(0, payment_account_after_compulsory_payments
            - PLANNED_PRODUCTION_COSTS);

    //Set flag if resolved:
    if (PAYMENT_ACCOUNT >= TOTAL_INTEREST_PAYMENT
            + TOTAL_DEBT_INSTALLMENT_PAYMENT + TAX_PAYMENT
            + TOTAL_DIVIDEND_PAYMENT)
    {
        FINANCIAL_CRISIS_STATE=0;
        BANKRUPTCY_STATE=0;
    }
    else
        //If not resolved: payment account remains below total needs
        //Code should never reach this point
         printf("\nERROR in Firm_in_financial_crisis: financial crisis not resolved. \n");

     return 0;
}

/*
 * \fn Firm_not_in_bankruptcy()
 * \brief Idle function to transit from state Firm_bankruptcy_checked to state Firm_checks_financial_crisis.
 */
int Firm_not_in_bankruptcy()
{   
    return 0;
}

/*
 * \fn Firm_execute_financial_payments()
 * \brief Function to execute financial payments:
 *  - tax_payment
 *  - total_debt_installment_payment
 *  - total_interest_payments
 *  - total_dividend_payment
 * All payments are subtracted from the payment account.
 * After this, all that is left over on the payment account can be used to pay for factor inputs for production.
 */
int Firm_execute_financial_payments()
{

    //No bankruptcy
    int i;
    double temp_interest=0.0;
    
    //step 1: actual tax_payment to government
    add_tax_payment_message(GOV_ID, TAX_PAYMENT);
    PAYMENT_ACCOUNT -= TAX_PAYMENT;

    //step 2: actual interest_payments and installment_payments
    //Sending installment_message to banks at which the firm has a loan 
    
    TOTAL_DEBT=0.0;
    for (i=LOANS.size-1; i>-1; i--)
    {
        //decrease payment_account with the interest_payment
        //the if-condition prevents an interest payment in the first period in which the loan is obtained
        // CONST_INSTALLMENT_PERIODS = 24 months by default
        if(LOANS.array[i].nr_periods_before_repayment!=CONST_INSTALLMENT_PERIODS+1)
        {
            
            temp_interest=LOANS.array[i].interest_rate*LOANS.array[i].loan_value;
            PAYMENT_ACCOUNT -= temp_interest;
    
            //decrease payment_account with the installment payment
            PAYMENT_ACCOUNT -= LOANS.array[i].installment_amount;
    
            //decrease the value of the loan with the debt_installment_payment:
            LOANS.array[i].loan_value -= LOANS.array[i].installment_amount;
            
            //printf("Now subtracted debt_installment_payment from loan_value: %f (new value:%f).\n", LOANS.array[i].debt_installment_payment, LOANS.array[i].loan_value);

            //check that the loan value does not go negative:
            if(LOANS.array[i].loan_value < -1e-3)
            {
                printf("\n ERROR in function Firm_execute_financial_payments, line 421:"
                 "loan value = %2.5f,"
                 "installment_amount = %2.5f."
                 "Corrected negative loan value to zero. \n", LOANS.array[i].loan_value, LOANS.array[i].installment_amount);
    
                LOANS.array[i].loan_value =0.0;
            }

            //compute current total debt
            TOTAL_DEBT += LOANS.array[i].loan_value;
    
            //decrease the residual_var of the loan with the var_per_installment:
            LOANS.array[i].residual_var -= LOANS.array[i].var_per_installment;
    
            //Sending debt_installment_payment_msg to all banks at which the firm has a loan
            //Note: this message is to be separated from the general bank_account_update_message send at the end of the period
            //to the firm's deposit bank (the banks at which the firm has loans is a different one than the bank at which the firm has deposits).
    
            //add_installment_message(bank_id, installment_amount, interest_amount, var_per_installment)
            add_installment_message(LOANS.array[i].bank_id,
                    LOANS.array[i].installment_amount, temp_interest,
                    LOANS.array[i].var_per_installment);
        }
        
        //If nr_periods_before_maturity == 0, remove the loan item
        if (LOANS.array[i].nr_periods_before_repayment==0)
        {
            printf("\n Loan item %d: nr_periods_before_repayment==0\n", i);
            printf("\n Firm: %d, Bank: %d\n", ID, LOANS.array[i].bank_id);
        }

        if (LOANS.array[i].nr_periods_before_repayment==1)
        {
            //printf("\n Removing loan item %d\n", i);
            remove_debt_item(&LOANS, i);
        }
        else
        {
            LOANS.array[i].nr_periods_before_repayment -= 1;
        }
        if (LOANS.array[i].nr_periods_before_repayment<0)
            printf("\n ERROR in function Firm_execute_financial_payments, line 456: nr_periods_before_repayment is -1. \n");
    }
    
    //step 3: actual dividend payments
    //Actual bank account updates are send to the bank at end of day when the firm sends its bank_update message 

    //add dividend_per_share_msg(firm_id, current_dividend_per_share) to shareholders (dividend per share)     
    CURRENT_DIVIDEND_PER_SHARE = TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING;
    add_dividend_per_share_message(ID, CURRENT_DIVIDEND_PER_SHARE);

    //decrease payment_account with the total_dividend_payment
    PAYMENT_ACCOUNT -= TOTAL_DIVIDEND_PAYMENT;

    return 0;
}

/*
 * \fn Firm_set_bankruptcy_insolvency()
 * \brief Function to set the type of bankruptcy to insolvency, set the active flag to 0,
 *  start the bankruptcy idle counter, and then go to end_Firm state.
 *  
 */
int Firm_set_bankruptcy_insolvency()
{
    //Set active flag to 0
    ACTIVE=0;
    
    //Start the idle counter
    BANKRUPTCY_IDLE_COUNTER = CONST_BANKRUPTCY_IDLE_PERIOD;
    
    //Set type of bankruptcy
    //Type 2: insolvency
    BANKRUPTCY_INSOLVENCY_STATE  = 1;
    BANKRUPTCY_ILLIQUIDITY_STATE = 0;
    
    TOTAL_VALUE_LOCAL_INVENTORY = 0.0;
    
    //send msg to malls
    add_bankruptcy_insolvency_message(ID);
        
    return 0;
}

/*
 * \fn Firm_bankruptcy_insolvency_procedure()
 * \brief Function to process the bankruptcy condition in case of insolvency.
 *  Send a bankruptcy_message to all banks at which the firm has a loan.
 *  Write-off bad debt on the balance sheet of the bank.
 *  Raise new equity by a issuing nes shares on the AFM, following a target leverage ratio (target debt/target equity).
 */
int Firm_bankruptcy_insolvency_procedure()
{
    int i, imax;
    double target_debt, bad_debt, credit_refunded, residual_var;
    double write_off_ratio, target_equity, ipo_amount;
    
    //Effect on credit market
    TOTAL_ASSETS = TOTAL_VALUE_CAPITAL_STOCK;

    //Set the target debt
     target_debt = DEBT_RESCALING_FACTOR*TOTAL_ASSETS;
    
    //Renegotiating debt: refunding credit, computing bad debt
    imax = LOANS.size;
    for (i=0; i<imax; i++)
    {
        residual_var = LOANS.array[i].var_per_installment
                * LOANS.array[i].nr_periods_before_repayment;

        //step 1: refunding credit
        //the credit_refunded is that part of the loan which can be refunded using the payment_account
        credit_refunded = (PAYMENT_ACCOUNT/TOTAL_DEBT)*LOANS.array[i].loan_value;
        PAYMENT_ACCOUNT -= credit_refunded;
        TOTAL_ASSETS -= credit_refunded;
        
        //step 2: computing bad debt
        write_off_ratio = (TOTAL_DEBT - target_debt)/TOTAL_DEBT;
        bad_debt = write_off_ratio*LOANS.array[i].loan_value;
        
        //the credit_remaining is that part of the debt which is not written off
        //credit_remaining = (1-write_off_ratio)*LOANS.array[i].loan_value

        //step 3: send the bankruptcy_message to write off part of the debt
        //add_bankruptcy_message(bank_id, bad_debt, credit_refunded, residual_var);
        add_bankruptcy_message(LOANS.array[i].bank_id, bad_debt,
                credit_refunded, residual_var);
    }
    
    //Check that after refunding credit the payment account is depleted:
    if (PAYMENT_ACCOUNT>0)
        printf("\n ERROR in Firm_bankruptcy_insolvency_procedure:"
                " payment_account not depleted after refunding credit. \n");
    
    //Effect on financial market
    //Wiping out all existing shareholders by cancelling their shares
    
    //Set the IPO_AMOUNT to raise:
    target_equity = (1/TARGET_LEVERAGE_RATIO) * target_debt;
    ipo_amount = target_equity + target_debt - TOTAL_ASSETS;
    
    
    //To use already implemented functions, we use the EXTERNAL_FINANCIAL_NEEDS to send the share emmission
    EXTERNAL_FINANCIAL_NEEDS = max(0,ipo_amount);

    printf("\n In function Firm_bankruptcy_insolvency_procedure:\n"
            "target_debt = %2.2f\n"
            "TARGET_LEVERAGE_RATIO = %2.2f\n"
            "ipo_amount = %2.2f\n"
            "EXTERNAL_FINANCIAL_NEEDS = %2.2f\n",
            target_debt, TARGET_LEVERAGE_RATIO, ipo_amount, EXTERNAL_FINANCIAL_NEEDS);

    //Effect on investment goods market
    //Left-over capital
    
    //Effect on labour market
    //Firing all employees --> see Firm_bankruptcy_procedures
    for (i=0;i<EMPLOYEES.size;i++)
            add_firing_message(ID, EMPLOYEES.array[i].id);
        
    //Effect on consumption goods market
    //Option 1: all local inventory stock is lost
    //Option 2: send back local inventory stock to factory
    //Option 3: fire-sales at local outlet malls at discount prices
    
    //Now recompute the balance sheet after the IPO

    return 0;
}

/*
 * \fn Firm_bankruptcy_illiquidity_procedure()
 * \brief Function to process the bankruptcy condition in case of illiquidity.
 *  There is no write-off of bad debt on the balance sheet of the banks.
 *  Raise new equity by a issuing new shares on the AFM according to a target liquidity ratio.
 */
int Firm_bankruptcy_illiquidity_procedure()
{   
    int i;
    double ipo_amount;
    
    //Effect on credit market   
    //Renegotiating debt not needed
    
    //Effect on financial market:
    //Shareholders retain their shares.
    
    //Set the IPO_AMOUNT to raise:
    ipo_amount = TARGET_LIQUIDITY_RATIO*(FINANCIAL_LIQUIDITY_NEEDS - PAYMENT_ACCOUNT);

    //To use already implemented functions, we use the EXTERNAL_FINANCIAL_NEEDS to send the share emmission
    EXTERNAL_FINANCIAL_NEEDS = max(0,ipo_amount);
    
    //Effect on investment goods market
    //Left-over capital
    
    //Effect on labour market
    //Firing all employees --> see Firm_bankruptcy_procedures
    for (i=0;i<EMPLOYEES.size;i++)
            add_firing_message(ID, EMPLOYEES.array[i].id);
        
    //Effect on consumption goods market
    //Option 1: all local inventory stock is lost
    //Option 2: send back local inventory stock to factory
    //Option 3: fire-sales at local outlet malls at discount prices
    
    //Now recompute the balance sheet after the IPO

    return 0;
}

/*
 * \fn Firm_bankruptcy_idle_counter()
 * \brief Function to decrease the bankruptcy_idle_counter.
 *  Note that a negative count means the financing condition has not been yet satisfied at the end of the default idle period.
 */
int Firm_bankruptcy_idle_counter()
{   
    BANKRUPTCY_IDLE_COUNTER -= 1;
        
    return 0;
}

/*
 * \fn Firm_reset_bankruptcy_flags()
 * \brief Function to reset the bankruptcy flags.
 */
int Firm_reset_bankruptcy_flags()
{
    //Add conditions for resetting the active flag to 1:
    if ((BANKRUPTCY_IDLE_COUNTER<=0)&&(EXTERNAL_FINANCIAL_NEEDS<=0.0))
    {
        ACTIVE=1;
        BANKRUPTCY_INSOLVENCY_STATE  = 0;
        BANKRUPTCY_ILLIQUIDITY_STATE = 0;
    }
        
    return 0;
}

/*
 * \fn Firm_compute_and_send_stock_orders()
 * \brief Function to send order_messages to the clearinghouse (share emission or repurchase).
 */
int Firm_compute_and_send_stock_orders_dummy()
{
    return 0;
}

/*
 * \fn Firm_read_stock_transactions()
 * \brief Function to read order_status messages from the clearinghouse, and update the firm's trading account.
 */
int Firm_read_stock_transactions_dummy()
{
    
    //Short-cut for Hybrid model:
    //Assume:
    //All external financial needs are satisfied by the asset market
    PAYMENT_ACCOUNT += EXTERNAL_FINANCIAL_NEEDS;
    EXTERNAL_FINANCIAL_NEEDS =0.0;
    
    
    return 0;
}
