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
    int i;
    
    //double PAYMENT_ACCOUNT            : account out of which payments are made

    //double_array LOANS                : dynamic array of structs with each struct a loan_item
    //struct debt_item
    //int bank_id                       : bank at which the loan was obtained
    //double loan_value                 : total value of the loan remaining
    //double interest_rate              : interest for this loan
    //double interest_payment           : interest to be paid this period
    //double debt_installment_payment   : installment payment per period
    //int nr_periods_before_maturity    : nr of periods to go before the loan has to be fully repaid

    TOTAL_INTEREST_PAYMENT=0.0;
    TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;

    for (i=0; i<LOANS.size; i++)
    {
        if(LOANS.array[i].loan_value < 0.0)
        printf("\n ERROR in function Firm_compute_financial_payments: loan_value is NEGATIVE: %f.\n", LOANS.array[i].loan_value);

        //step 1: compute total interest payments
        TOTAL_INTEREST_PAYMENT += LOANS.array[i].interest_rate * LOANS.array[i].loan_value;
                
        //step 2: compute total debt installment payments
        TOTAL_DEBT_INSTALLMENT_PAYMENT += LOANS.array[i].installment_amount;
    }

    #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG)
    { 
        printf("\n\n Firm_compute_financial_payments ID: %d",ID);
        printf("\n\t TOTAL_INTEREST_PAYMENT: %f TOTAL_DEBT_INSTALLMENT_PAYMENT: %f",TOTAL_INTEREST_PAYMENT,TOTAL_DEBT_INSTALLMENT_PAYMENT);
        getchar();
     }    
    #endif
    
    return 0;
}

/*
 * \fn Firm_compute_income_statement()
 * \brief Function to compute the income statement of the firm.
 */
int Firm_compute_income_statement()
  
{
    //  #ifndef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif
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

    #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    { 
        printf("\n\n Firm_compute_income_statement ID: %d",ID);
        printf("\n\t CUM_REVENUE: %f CALC_PRODUCTION_COSTS: %f",CUM_REVENUE,CALC_PRODUCTION_COSTS);
        printf("\n\t TOTAL_INTEREST_PAYMENT: %f EARNINGS: %f",TOTAL_INTEREST_PAYMENT,EARNINGS);
        printf("\n\t TAX_PAYMENT: %f NET_EARNINGS: %f",TAX_PAYMENT,NET_EARNINGS);
        getchar();
    }    
    #endif
    
    // #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firms_income_statement.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f %f",DAY,ID,CUM_REVENUE,CALC_PRODUCTION_COSTS,TOTAL_INTEREST_PAYMENT);
        fprintf(file1," %f %f %f",EARNINGS,TAX_PAYMENT,NET_EARNINGS);
        fclose(file1);
        free(filename);
    }    
   // #endif
    
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
    if (PREVIOUS_EARNINGS_PER_SHARE>0.0)
        TOTAL_DIVIDEND_PAYMENT *= (EARNINGS_PER_SHARE/PREVIOUS_EARNINGS_PER_SHARE)
                                   *(CURRENT_SHARES_OUTSTANDING/PREVIOUS_SHARES_OUTSTANDING);

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
    
    if(TOTAL_DIVIDEND_PAYMENT<1e-6 && NET_EARNINGS>0.0)
    {
        TOTAL_DIVIDEND_PAYMENT = CONST_DIVIDEND_EARNINGS_RATIO * NET_EARNINGS;
        //printf("\n In Firm_compute_dividends: setting TOTAL_DIVIDEND_PAYMENT = %2.4f\n", TOTAL_DIVIDEND_PAYMENT):
    }
    
    //Always check:
    if (EARNINGS<0.0)
        TOTAL_DIVIDEND_PAYMENT = 0.0;
    
    //Continue with computation of ratios
    PREVIOUS_DIVIDEND_PER_SHARE = CURRENT_DIVIDEND_PER_SHARE;
    
    if (CURRENT_SHARES_OUTSTANDING>0)
        CURRENT_DIVIDEND_PER_SHARE = TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING;
    else CURRENT_DIVIDEND_PER_SHARE = 0.0;
    
    PREVIOUS_DIVIDEND_PER_EARNINGS = CURRENT_DIVIDEND_PER_EARNINGS;
    
    if (NET_EARNINGS>0.0)
        CURRENT_DIVIDEND_PER_EARNINGS = TOTAL_DIVIDEND_PAYMENT/NET_EARNINGS;
    else
        CURRENT_DIVIDEND_PER_EARNINGS = 0.0;

    #ifndef _DEBUG_MODE         
    if (PRINT_DEBUG)
    { 
        printf("\n\n Firm_compute_dividends ID: %d",ID);
        printf("\n\t NET_EARNINGS: %f TOTAL_DIVIDEND_PAYMENT: %f",NET_EARNINGS,TOTAL_DIVIDEND_PAYMENT);
        getchar();
    }
    #endif
    
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
            + TOTAL_DIVIDEND_PAYMENT + TAX_PAYMENT + CALC_PRODUCTION_COSTS;

    #ifndef _DEBUG_MODE         
    if (PRINT_DEBUG)
    { 
        printf("\n\n Firm_compute_total_financial_payments ID: %d",ID);
        printf("\n\t TOTAL_PAYMENTS: %f",TOTAL_PAYMENTS);
        getchar();
    }    
    #endif
            
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
    int i;

      
    //compute the equity of the firm
    //TOTAL_ASSETS=
    //+ PAYMENT_ACCOUNT: remaining cash holdings of the firm
    //+ TOTAL_VALUE_CAPITAL_STOCK: estimated value of the capital stock (this is determined in the capital goods market role)
    //+ TOTAL_VALUE_LOCAL_INVENTORY: value of all the local inventory stocks held at the malls        

    //TOTAL_VALUE_LOCAL_INVENTORY: estimated value of local inventory stocks at current mall prices
    //We loop over the malls and sum the value of all local inventory stocks

    TOTAL_VALUE_LOCAL_INVENTORY=0.0;
    for (i=0; i<CURRENT_MALL_STOCKS.size; i++)
    {
        TOTAL_VALUE_LOCAL_INVENTORY += PRICE*CURRENT_MALL_STOCKS.array[i].current_stock;
        //When malls have different current_price use this code:
        //TOTAL_VALUE_LOCAL_INVENTORY += CURRENT_MALL_STOCKS.array[i].current_price * CURRENT_MALL_STOCKS.array[i].current_stock;
    }

    if POLICY_EXP1
        TOTAL_VALUE_LOCAL_INVENTORY=0.0;

    TOTAL_ASSETS = PAYMENT_ACCOUNT + TOTAL_VALUE_CAPITAL_STOCK
            + TOTAL_VALUE_LOCAL_INVENTORY;

    EQUITY = TOTAL_ASSETS - TOTAL_DEBT;

    if (EQUITY>0.0)
        DEBT_EQUITY_RATIO = TOTAL_DEBT/EQUITY;
    else DEBT_EQUITY_RATIO = 0.0;
    
    if(NET_EARNINGS>0.0)
        DEBT_EARNINGS_RATIO = TOTAL_DEBT/NET_EARNINGS;
    else DEBT_EARNINGS_RATIO = 0.0;
    
    #ifndef _DEBUG_MODE
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    { 
        printf("\n\n Firm_compute_balance_sheet ID: %d",ID);
        printf("\n\t PAYMENT_ACCOUNT: %f TOTAL_VALUE_CAPITAL_STOCK: %f",PAYMENT_ACCOUNT,TOTAL_VALUE_CAPITAL_STOCK);
        printf("\n\t TOTAL_VALUE_LOCAL_INVENTORY: %f TOTAL_ASSETS: %f",TOTAL_VALUE_LOCAL_INVENTORY,TOTAL_ASSETS);
        printf("\n\t EQUITY: %f DEBT: %f",EQUITY,TOTAL_DEBT);
        getchar();
    }   
    #endif

  
                                                             
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

    #ifndef _DEBUG_MODE
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n Firm_compute_total_liquidity_needs ID: %d",ID);
        printf("\n\t PRODUCTION_LIQUIDITY_NEEDS %f",PRODUCTION_LIQUIDITY_NEEDS);
        printf("\n\t TOTAL_DEBT_INSTALLMENT_PAYMENT %f TOTAL_INTEREST_PAYMENT %f",TOTAL_DEBT_INSTALLMENT_PAYMENT, TOTAL_INTEREST_PAYMENT);
        printf("\n\t TAX_PAYMENT %f FINANCIAL_LIQUIDITY_NEEDS %f",TAX_PAYMENT, FINANCIAL_LIQUIDITY_NEEDS);
        printf("\n\t PRODUCTION_LIQUIDITY_NEEDS %f",PRODUCTION_LIQUIDITY_NEEDS);
        printf("\n\t TOTAL_DIVIDEND_PAYMENT %f TOTAL_FINANCIAL_NEEDS %f",TOTAL_DIVIDEND_PAYMENT,TOTAL_FINANCIAL_NEEDS);
    
        printf("\n\t PAYMENT_ACCOUNT %f EXTERNAL_FINANCIAL_NEEDS %f",PAYMENT_ACCOUNT,EXTERNAL_FINANCIAL_NEEDS);
        getchar();
    }
    #endif    
    
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

    #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG)
    {
        printf("\n Firm_check_financial_and_bankruptcy_state ID: %d",ID);
        printf("\n\t BANKRUPTCY_ILLIQUIDITY_STATE: %d FINANCIAL_CRISIS_STATE: %d",BANKRUPTCY_ILLIQUIDITY_STATE,FINANCIAL_CRISIS_STATE);
    }
    #endif
        
    return 0;
}

/*
 * \fn Firm_set_bankruptcy_illiquidity()
 * \brief Function to set the type of bankruptcy to illiquidity, set the active flag to 0,
 *  start the bankruptcy idle counter, and then go to end_Firm state.
 */
int Firm_set_bankruptcy_illiquidity()
{
     FILE *file1;
    char *filename;
    //Set active flag to 0
    ACTIVE=0;
    
    //Start the idle counter
    BANKRUPTCY_IDLE_COUNTER = CONST_BANKRUPTCY_IDLE_PERIOD;
    
    //Set type of bankruptcy
    //Type 1: illiquidity
    BANKRUPTCY_INSOLVENCY_STATE  = 0;
    BANKRUPTCY_ILLIQUIDITY_STATE = 1;
    
    TOTAL_VALUE_LOCAL_INVENTORY = 0.0;
    
    #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\n Firm_set_bankruptcy_illiquidity ID: %d",ID);
        printf("\n\t ACTIVE: %d BANKRUPTCY_IDLE_COUNTER: %d",ACTIVE,BANKRUPTCY_IDLE_COUNTER);
        printf("\n\t BANKRUPTCY_ILLIQUIDITY_STATE: %d BANKRUPTCY_INSOLVENCY_STATE: %d",BANKRUPTCY_ILLIQUIDITY_STATE,BANKRUPTCY_INSOLVENCY_STATE);
    }
    #endif                    
    
    //send msg to malls
    add_bankruptcy_illiquidity_message(ID);
    
    if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firms_bankruptcies.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f %f %d",DAY,ID,PAYMENT_ACCOUNT,TOTAL_DEBT,EQUITY,-1);
        fclose(file1);
        free(filename);
    }    
        
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

    #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\n Firm_in_financial_crisis ID: %d",ID);
        printf("\n\t former TOTAL_DIVIDEND_PAYMENT: %f",TOTAL_DIVIDEND_PAYMENT);
    }
    #endif
    
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

    #ifndef _DEBUG_MODE
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {               
        printf("\n\t new TOTAL_DIVIDEND_PAYMENT: %f",TOTAL_DIVIDEND_PAYMENT);
        printf("\n\t new FINANCIAL_CRISIS_STATE: %d BANKRUPTCY_STATE: %d",FINANCIAL_CRISIS_STATE,BANKRUPTCY_STATE);
        getchar();
    }
    #endif
    
     return 0;
}

/*
 * \fn Firm_not_in_bankruptcy()
 * \brief Idle function to transit from state Firm_bankruptcy_checked to state Firm_checks_financial_crisis.
 */
int Firm_not_in_bankruptcy()
{   
    #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG) printf("\n\n Firm_not_in_bankruptcy");
    #endif
        
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
    char * filename="";
    FILE * file1=NULL;
    int i;
    double temp_interest=0.0;
    
    //step 1: actual tax_payment to government
    add_tax_payment_message(GOV_ID, TAX_PAYMENT);
    PAYMENT_ACCOUNT -= TAX_PAYMENT;

     if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/firms_tax_payments.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f %f",DAY,ID,EARNINGS,TAX_RATE_CORPORATE,TAX_PAYMENT);
            fclose(file1);
            free(filename);
        }  
    //step 2: actual interest_payments and installment_payments
    //Sending installment_message to banks at which the firm has a loan 

    #ifndef _DEBUG_MODE
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n Firm_execute_financial_payments ID: %d",ID);
        printf("\n\t (before) PAYMENT_ACCOUNT: %f TOTAL_DEBT: %f",PAYMENT_ACCOUNT,TOTAL_DEBT);
    }
    #endif
    
    TOTAL_DEBT=0.0;
    for (i=LOANS.size-1; i>-1; i--)
    {
        //decrease payment_account with the interest_payment
        //the if-condition prevents an interest payment in the first period in which the loan is obtained
        // CONST_INSTALLMENT_PERIODS = 24 months by default

        //If 1<=nr_periods_before_maturity<CONST_INSTALLMENT_PERIODS+1:
        //* decrease nr_periods_before_maturity with 1
        //* add loan value to total_debt
        //* decrease residual_var with var_per_installment
        //* decrease loan_value and payment account with installment amount
        //* send message to bank
        if ((LOANS.array[i].nr_periods_before_repayment>=1)&&(LOANS.array[i].nr_periods_before_repayment<CONST_INSTALLMENT_PERIODS+1))
        {
            //printf("\n Loan item %d: nr_periods_before_repayment=%d\n", i, LOANS.array[i].nr_periods_before_repayment);

            LOANS.array[i].nr_periods_before_repayment -= 1;

            //Add loan_value to the current total debt
            TOTAL_DEBT += LOANS.array[i].loan_value;
            //printf("\n Loan item %d: adding debt value =%2.2f\n", i, LOANS.array[i].loan_value);
            //printf("\n TOTAL_DEBT=%2.2f\n", TOTAL_DEBT);

                
            //decrease the residual_var of the loan with the var_per_installment:
            LOANS.array[i].residual_var -= LOANS.array[i].var_per_installment;

            #ifndef _DEBUG_MODE
            if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
            {
                printf("\n\t repayment LOAN: %d",i);
                printf("\n\t installment_amount: %f interest_amount: %f remaining loan_value: %f",LOANS.array[i].installment_amount,temp_interest,LOANS.array[i].loan_value);
                printf("\n\t (after) PAYMENT_ACCOUNT: %f TOTAL_DEBT: %f",PAYMENT_ACCOUNT,TOTAL_DEBT);
            }
            #endif
            
            //pay interest            
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
    
            //Sending debt_installment_payment_msg to all banks at which the firm has a loan
            //Note: this message is to be separated from the general bank_account_update_message send at the end of the period
            //to the firm's deposit bank (the banks at which the firm has loans is a different one than the bank at which the firm has deposits).
    
            //add_installment_message(bank_id, installment_amount, interest_amount, var_per_installment)
            add_installment_message(LOANS.array[i].bank_id,
                    LOANS.array[i].installment_amount, temp_interest,
                    LOANS.array[i].var_per_installment);        
        }
        //If nr_periods_before_maturity==CONST_INSTALLMENT_PERIODS+1:
        //* decrease with 1
        //* add value to total debt
        else if (LOANS.array[i].nr_periods_before_repayment==CONST_INSTALLMENT_PERIODS+1)
        {
            //printf("\n Loan item %d: nr_periods_before_repayment=%d\n", i, LOANS.array[i].nr_periods_before_repayment);

            LOANS.array[i].nr_periods_before_repayment -= 1;
            
            //Add loan_value to the current total debt
            TOTAL_DEBT += LOANS.array[i].loan_value;
            //printf("\n Loan item %d: adding debt value =%2.2f\n", i, LOANS.array[i].loan_value);
            //printf("\n TOTAL_DEBT=%2.2f\n", TOTAL_DEBT);
        }
        //If nr_periods_before_maturity<0:
        //* this should give an error
        else if (LOANS.array[i].nr_periods_before_repayment<0)
        {
            printf("\n Loan item %d: nr_periods_before_repayment=%d\n", i, LOANS.array[i].nr_periods_before_repayment);
            printf("\n Firm: %d, Bank: %d\n", ID, LOANS.array[i].bank_id);
            printf("\n ERROR in function Firm_execute_financial_payments, line 482: nr_periods_before_repayment<0. \n");
        }

        //If nr_periods_before_maturity == 0
        //* remove the loan item.
        if (LOANS.array[i].nr_periods_before_repayment==0)
        {
            //printf("\n Loan item %d: nr_periods_before_repayment=%d\n", i, LOANS.array[i].nr_periods_before_repayment);
            remove_debt_item(&LOANS, i);
        }
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
    FILE *file1;
    char *filename;
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
    
        if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firms_bankruptcies.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f %f %d",DAY,ID,PAYMENT_ACCOUNT,TOTAL_DEBT,EQUITY,-11);
        fclose(file1);
        free(filename);
    }    

        
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
    int i;
    double target_debt, bad_debt, credit_refunded, residual_var;
    double write_off_ratio, target_equity, ipo_amount;
  
    #ifndef _DEBUG_MODE  
        char * filename;
        FILE * file1;
    #endif

    #ifndef _DEBUG_MODE
    if (PRINT_LOG)
    {
        //Start an empty string for the filename
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        
        //Concatenate
        strcpy(filename, "debug_bankruptcy.txt");
        //Open a file pointer: FILE * file 
        file1 = fopen(filename,"a");
        
        printf("_____In file Firm_Financial_Management_Functions.c, , line 578: Function Firm function Firm_bankruptcy_insolvency_procedure()\n");
        fprintf(file1,"IT %d ID %d EQUITY %f\n",DAY,ID,EQUITY);
        
        //close the file pointer: FILE * file 
        fclose(file1);
        free(filename);
    }
    #endif
    
    //Effect on credit market
    
    
//printf("\n Firm_bankruptcy_insolvency_procedure BANKRUPTCY_IDLE_COUNTER %d",BANKRUPTCY_IDLE_COUNTER);

if (BANKRUPTCY_IDLE_COUNTER == CONST_BANKRUPTCY_IDLE_PERIOD - 1)
{
                            
   
    //Renegotiating debt: refunding credit, computing bad debt
     TOTAL_ASSETS = TOTAL_VALUE_CAPITAL_STOCK + PAYMENT_ACCOUNT;
    //Set the target debt
    target_debt = DEBT_RESCALING_FACTOR*TOTAL_ASSETS;

    for (i=0; i<LOANS.size; i++)
    {
        residual_var = LOANS.array[i].var_per_installment
                * LOANS.array[i].nr_periods_before_repayment;

        //step 1: refunding credit
        //the credit_refunded is that part of the loan which can be refunded using the payment_account
        //credit_refunded = (PAYMENT_ACCOUNT/TOTAL_DEBT)*LOANS.array[i].loan_value;
        //PAYMENT_ACCOUNT -= credit_refunded;
        //TOTAL_ASSETS -= credit_refunded;
        credit_refunded = 0;  // credit_refunded is not more used 
        
        //step 2: computing bad debt
        write_off_ratio = (TOTAL_DEBT - target_debt)/TOTAL_DEBT;
        bad_debt = write_off_ratio*LOANS.array[i].loan_value;
        
        //the credit_remaining is that part of the debt which is not written off
        //credit_remaining = (1-write_off_ratio)*LOANS.array[i].loan_value

        //step 3: send the bankruptcy_message to write off part of the debt
        //add_bankruptcy_message(firm_id, bank_id, bad_debt, credit_refunded, residual_var);
        
        add_bankruptcy_message(ID, LOANS.array[i].bank_id, bad_debt,
        credit_refunded, write_off_ratio*residual_var);        
                
   }
   TOTAL_DEBT = target_debt;
   reset_debt_item_array(&LOANS);
   
    target_equity = (1/TARGET_LEVERAGE_RATIO) * target_debt;
    ipo_amount = max(0,target_equity + target_debt - TOTAL_ASSETS);
     EXTERNAL_FINANCIAL_NEEDS = max(0,ipo_amount);
}   
    //Check that after refunding credit the payment account is depleted:
    /*if (PAYMENT_ACCOUNT>1e-6)
	{
        printf("\n ERROR in Firm_bankruptcy_insolvency_procedure:"
                " payment_account not depleted after refunding credit. \n"
                "PAYMENT_ACCOUNT=%f\n", PAYMENT_ACCOUNT);
	} */   
    //Effect on financial market
    //Wiping out all existing shareholders by cancelling their shares
    
    //Set the IPO_AMOUNT to raise:
   
  
    #ifndef _DEBUG_MODE
    if(PRINT_DEBUG)
    {
        printf("\n In function Firm_bankruptcy_insolvency_procedure:\n"
            "DEBT_RESCALING_FACTOR = %2.2f\n"
            "TARGET_LEVERAGE_RATIO = %2.2f\n"
            "TARGET_LIQUIDITY_RATIO = %2.2f\n"
            "target_debt = %2.2f\n"
            "target_equity = %2.2f\n"
            "ipo_amount = %2.2f\n"
            "EXTERNAL_FINANCIAL_NEEDS = %2.2f\n",
            DEBT_RESCALING_FACTOR, TARGET_LEVERAGE_RATIO, TARGET_LIQUIDITY_RATIO,
            target_debt, target_equity, ipo_amount, EXTERNAL_FINANCIAL_NEEDS);
    }
    #endif
    
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
    
    //add a bankruptcy_message for households only, with bank_id=0 so no bank will ever read it:
     add_bankruptcy_message(ID, 0, 0.0, 0.0, 0.0);
                
    //Effect on credit market   
    //Renegotiating debt not needed
    
    //Effect on financial market:
    //Shareholders retain their shares.
    
    //Set the IPO_AMOUNT to raise:
    ipo_amount = TARGET_LIQUIDITY_RATIO*(FINANCIAL_LIQUIDITY_NEEDS - PAYMENT_ACCOUNT);

    //To use already implemented functions, we use the EXTERNAL_FINANCIAL_NEEDS to send the share emmission
    EXTERNAL_FINANCIAL_NEEDS = max(0.0,ipo_amount);
    
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
     FILE *file1;
    char *filename;
    #ifndef _DEBUG_MODE
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\n Firm_reset_bankruptcy_flags ID: %d",ID);
        printf("\n\t BANKRUPTCY_IDLE_COUNTER: %d EXTERNAL_FINANCIAL_NEEDS: %f",BANKRUPTCY_IDLE_COUNTER,EXTERNAL_FINANCIAL_NEEDS);
    }
    #endif
    
    //Add conditions for resetting the active flag to 1:
    if ((BANKRUPTCY_IDLE_COUNTER<=0)&&(EXTERNAL_FINANCIAL_NEEDS<=0.0))
    {
        ACTIVE=1;
        BANKRUPTCY_INSOLVENCY_STATE  = 0;
        BANKRUPTCY_ILLIQUIDITY_STATE = 0;
        
        TOTAL_ASSETS = PAYMENT_ACCOUNT + TOTAL_VALUE_CAPITAL_STOCK + TOTAL_VALUE_LOCAL_INVENTORY;
        EQUITY = TOTAL_ASSETS - TOTAL_DEBT;
        
      if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firms_bankruptcies.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f %f %d",DAY,ID,PAYMENT_ACCOUNT,TOTAL_DEBT,EQUITY,0);
        fclose(file1);
        free(filename);
    }    
    }

    #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\t BANKRUPTCY_INSOLVENCY_STATE: %d BANKRUPTCY_ILLIQUIDITY_STATE: %d",BANKRUPTCY_INSOLVENCY_STATE,BANKRUPTCY_ILLIQUIDITY_STATE);
        getchar();
    }
    #endif   
    
    
    return 0;
}

/*
 * \fn Firm_compute_and_send_stock_orders()
 * \brief Function to send order_messages to the clearinghouse (share emission or repurchase).
 */
int Firm_compute_and_send_stock_orders()
{
    //Note: This function only runs if EXTERNAL_FINANCIAL_NEEDS>0.0

    double limit_price=CURRENT_SHARE_PRICE*0.99;
    
    //If the quantity is fractional, take the ceiling, such that EXTERNAL_FINANCIAL_NEEDS are met.
    int quantity = -1*ceil(EXTERNAL_FINANCIAL_NEEDS/limit_price);
    
   add_order_message(ID, ID, limit_price, quantity);

    #ifndef _DEBUG_MODE
    if (PRINT_DEBUG)
    {
        printf("\n\n Firm_compute_and_send_stock_orders ID: %d",ID);
        printf("\n\t EXTERNAL_FINANCIAL_NEEDS: %f limit_price: %f quantity: %d",EXTERNAL_FINANCIAL_NEEDS,limit_price,quantity);       
        getchar();             
    }
    #endif
    
    return 0;
}

/*
 * \fn Firm_read_stock_transactions()
 * \brief Function to read order_status messages from the clearinghouse, and update the firm's trading account.
 */
int Firm_read_stock_transactions()
{
     FILE *file1;
     char *filename;
    double finances;
    
    //Before updating the share count
    PREVIOUS_SHARES_OUTSTANDING = CURRENT_SHARES_OUTSTANDING;
     if (EXTERNAL_FINANCIAL_NEEDS < 0.0)
    {
    EXTERNAL_FINANCIAL_NEEDS = 0.0;
    }

    #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG) 
    {
        printf("\n\n Firm_read_stock_transactions ID: %d",ID);
        printf("\n\t EXTERNAL_FINANCIAL_NEEDS: %f PAYMENT_ACCOUNT: %f",EXTERNAL_FINANCIAL_NEEDS,PAYMENT_ACCOUNT);
    }
    #endif
    
    START_ORDER_STATUS_MESSAGE_LOOP
    if (ID == order_status_message->trader_id)
    {
        //Finances obtained: positive quantity is demand (buying), negative quantity is supply (selling)
        finances = (-1)*order_status_message->price
                * order_status_message->quantity;
    
        CURRENT_SHARES_OUTSTANDING += (-1)*order_status_message->quantity;
    
        //Increase payment account with the finances obtained
        PAYMENT_ACCOUNT += finances;
    
        //Decrease external financial needs with the finances obtained
        EXTERNAL_FINANCIAL_NEEDS -= finances;
        
        #ifndef _DEBUG_MODE
        if (PRINT_DEBUG) 
        {
            printf("\n\t price: %f quantity: %d",order_status_message->price,order_status_message->quantity);
            printf("\n\t PREVIOUS_SHARES_OUTSTANDING: %d CURRENT_SHARES_OUTSTANDING: %d",PREVIOUS_SHARES_OUTSTANDING,CURRENT_SHARES_OUTSTANDING);
            printf("\n\t EXTERNAL_FINANCIAL_NEEDS: %f PAYMENT_ACCOUNT: %f",EXTERNAL_FINANCIAL_NEEDS,PAYMENT_ACCOUNT);
        }
        #endif
    }
    FINISH_ORDER_STATUS_MESSAGE_LOOP
    
    if (PRINT_DEBUG_FILE_EXP1)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/firms_stock_transactions.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %d %d %f",DAY,ID,PREVIOUS_SHARES_OUTSTANDING,CURRENT_SHARES_OUTSTANDING,finances);
            fclose(file1);
            free(filename);
        }
    
    
    return 0;
}
