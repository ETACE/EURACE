/*
 * Sander: 25/06/07
 * - Added:
 *  Household function for computation of consumption out of monthly income
 *
 * Sander: 21/06/07
 * - Replacements:
 * householdid -> household_id
 * firmid -> firm_id
 * bankid -> bank_id
 *
 * Sander: 19/06/07
 * -Added:
 *  The firm now has an income account and a payment account (we need a savings account as well?)
 *  -- all income streams enter in the income_account
 *  -- all outflow streams are paid from the payment_account
 *
 *
 * Sander: 09/06/07
 * - Replacements:
 * external_payout -> financial_reserves
 * repay -> debt_repayments
 *
 * - Added some variables:
 * financial_reserves
 * share_repurchase_value
 * share_repurchase_units
 * current_total_shares
 * target_total_shares
 * earn_pshare_ratio_growth=get_earn_pshare_ratio_growth(); 
 *
 * - Edits:
 * Fixed the share repurchase decision
 */


#include <header.h>

/** \def no_firms_to_apply_to
 * \brief The number of firms for workers to apply to. */
#define no_firms_to_apply_to 10

/** \def no_firms_to_buy_from
 * \brief The number of firms for workers to buy goods from. */
#define no_firms_to_buy_from 10

/** \def no_firms
 * \brief The number of firms. */
#define no_firms 10
#define QUARTER 60
#define critcal_priceearnratio 1

/** \fn void bubble_sort(int * id, double * wage, int length)
 * \brief Uses bubble sorting algorithm to sort worker list by wage
 * \param id Pointer to the list of worker ids.
 * \param wage Pointer to the associated list of worker wages.
 * \param length Length of the lists.
 */
void bubble_sort(int * id, double * wage, int length)
{
    int i, j, tmpid;
    double tmpwage;

    /* Using bubble sorts nested loops */
    for(i=0; i<(length-1); i++)
    {
        for(j=0; j<(length-1)-i; j++)
        {
            /* Comparing the wages between neighbours */
            if(*(wage+j+1) < *(wage+j))
            {
                /* Check for end of list */
                if(*(wage+j+1) != 0)
                {
                    /* Swap worker id and wage to move
                       cheaper workers to the top of the list */
                    tmpwage = *(wage+j);
                    tmpid = *(id+j);
                    *(wage+j) = *(wage+j+1);
                    *(id+j) = *(id+j+1);
                    *(wage+j+1) = tmpwage;
                    *(id+j+1) = tmpid;
                }
            }
        }
    }
}

/** \fn double random_unif()
 * \brief Returns a random number between 0 and 1 (inclusive)
 */
double random_unif()
{
    return ((double)rand()/(double)RAND_MAX);
}

///agent Firm
//financial management role
//Firm_financial_policy_planning
int Firm_calculate_income_payout()
{

    int a=0;///CHECK!!!*******************

    xmachine_memory_Firm * xmemory = current_xmachine->xmachine_Firm;

    //double_array revenues</name></var>
    //double total_revenue= get_total_revenue();
    //double net_revenue= get_net_revenue();
/*  printf("op before: %f",get_operational_cost());

    int * wage=current_xmachine->xmachine_Firm->operational_cost;

    set_operational_cost(1);

    printf("op before: %f",*wage);
*/

    double income_account=get_income_account();
    double payment_account=get_payment_account();
    double total_revenue=0.0;
    double costs=0.0;
    double net_revenue=0.0;

    double operational_costs=0.0; /*Operational costs: wages + inputs */
    double total_wage_payments=get_total_wage_payments();
    double total_input_payments=get_total_input_payments();
    double interest_payments=0.0;

    double total_earnings=0.0;
    double net_earnings=0.0;
    double tax_rate_profits=get_tax_rate_profits();
    double pretax_profit=0.0;
    double tax_provision=0.0;
    double div_payments=get_div_payments();

    double retained_earnings=0.0;
    double current_debt=get_current_debt();
    double debt_interest_rate=get_debt_interest_rate();
    double interest_payments=0.0;
    double debt_repayments=0.0;

    double share_repurchase_value=0.0;
    double share_repurchase_units=0.0;
    int target_total_shares=0.0;
    int current_total_shares=get_current_total_shares();

    double total_financial_needs=0.0;
    double financial_needs=0.0;
    double add_financial_needs=0.0;
    double financial_reserves=get_financial_reserves();
    
    double target_loans=0.0;
    double target_equity=0.0;
    double bonds_issue_target=0.0;
    double stocks_issue_target=0.0;
    
    double price=get_price(); /*Sander: this should be the firm share price of firm_id!! */
    double max_debt=0,0;
    double div_earn_ratio=get_div_earn_ratio();
    double debt_earn_ratio=get_debt_earn_ratio();
    double div_pshare_ratio=get_div_pshare_ratio();
    double earn_psratio=get_earn_pshare_ratio();
    double price_earn_ratio= get_price_earn_ratio();

    double retained_earn_ratio = get_retained_earn_ratio();             /*retained earnings ratio: retained earnings divided by net earnings*/
    double earn_pshare_ratio_growth=get_earn_pshare_ratio_growth();     /*critical value for the growth rate of the EPS ratio (this is set by the firm)*/
    double critical_earn_pshare_ratio=0.0;                              /*target growth rate of the EPS ratio (this follows from the critical value set by the firm)*/
    double critical_price_earn_ratio=get_critical_price_earn_ratio();   /*critical value of the PE ratio (this is set by the firm)*/


    //step 1: compute total revenue from sales and total costs of sales
    for(a=0;a<QUARTER;a++)
    {
        total_revenue+=xmemory->revenues[a];
        costs+=xmemory->sales_costs[a];
    }

    //step2: compute net revenue
    net_revenue=total_revenue-costs;
    income_account += net_revenue;

    //step 3: compute operational costs
    operational_costs=total_wage_payments+total_input_payments;
    payment_account -= operational_costs;

    //Wage payment messages to workers
    //Payment messages for other inputs

    //step 4:
    interest_payments=min(debt_interest_rate * current_debt,net_revenue-operational_costs);

    //Interest payment message to bank
    add_interest_payment_message(firm_id, bank_id, interest_payments, range, x, y, z);
    payment_account -= interest_payments;
    
    //if interest_payments exceed the resources available, the current debt is increased automatically to finance the interest payments
    target_loans=current_debt+max(0,debt_interest_rate*current_debt-interest_payments);

    //step 5: earnings
    total_earnings=net_revenue-operational_costs-interest_payments;

    //step6: tax payments
    pretax_profit=max(0,total_earnings);
    tax_provision=tax_rate_profit*pretax_profit;

    //Tax payment message to government
      add_tax_payment_message(firm_id, tax_provision, range, x, y, z);
      payment_account -= tax_provision;
    
    //step7: net earnings
    net_earnings=total_earnings-tax_provision;
    earn_pshare_ratio=net_earnings/current_total_shares;

    //step8: dividend payments. Goal: maintain a constant dividend to earnings ratio
    div_payments=max(div_pshare_ratio*current_total_shares,div_earn_ratio*net_earnings);
    div_pshare_ratio= div_payments/current_total_shares;
    div_earn_ratio = div_payments/net_earnings;
    financial_reserves=net_earnings-div_payments;

    //Dividend payment message to shareholders (the per share dividends)
      add_div_payment_message(firm_id, div_pshare_ratio, range, x, y, z);

    //step9 : retained earnings and investment decision
    retained_earnings = retained_earn_ratio * (net_earnings-div_payments);
    financial_reserves=(1-retained_earn_ratio)*(net_earnings-div_payments);
    retained_earn_ratio = retained_earnings/net_earnings;

    //step 10: share repurchase decision
    // share_repurchase is the total number of shares to repurchase
    // repurchase_value is the total value of the share repurchase operation

    /* SETTING 1: Price-to-earnings-ratio as a target for share repurchases  
     * If the price-to-earnings-ratio drops below a critical value, firm buys back shares
     * NOTE: Number of shares to buy back is an integer!
     * {C-CODE}
     *  price_earn_ratio=price/net_earnings;
     *  if (price_earn_ratio<critical_price_earn_ratio)
     *   {
     *       repurchase_value = /* THIS NEED TO BE MODELLED: What is the value of repurchase_value? */
     *       share_repurchase_units= (int)(repurchase_value/price);
     *   }

    /*SETTING 2: Earnings-per-share growth rate as a target for share repurchases    
    * The critical value of the earnings_per_share_ratio is defined as growth in the current level.
    */
    critical_earn_pshare_ratio=(1+earn_pshare_ratio_growth)* earn_pshare_ratio; /*The target eps ratio */
    earn_pshare_ratio= net_earnings/current_total_shares;                       /*The current eps ratio */
    target_total_shares=net_earnings/critical_earn_pshare_ratio;                /*The target nr of shares to obtain the target eps ratio */

    /* Sander: This should be ok, we compute the share_repurchase as a buying operation
     * so the sign should be -- (according to the convention for limit orders).
     * If the target nr of shares is lower than the current supply of shares, perform a buyback:
     * target - current <0 (buy back)
     * target - current >0 (do nothing, since nr of outstanding shares is below the target level,
     *                      and the eps ratio is above the critical value).
     */
    if(target_total_shares<current_total_shares)
    {
        share_repurchase=target_total_shares - current_total_shares;
        share_repurchase_value = price*share_repurchase;
    }
    
    //step 11: debt repayment decision
    debt_repayments=current_debt;
    financial_reserves=net_earnings-div_payments-retained_earnings-share_repurchase-debt_repayments;

    //Debt repayment message to bank:
    add_debt_repayment_message(firm_id, bank_id, debt_repayments, range, x, y, z);
    payment_account -= debt_repayments;
    
    //step 12: determination of total financial needs
    financing_needs=operational_costs+interest_payments+tax_provision+div_payments+retained_earnings+repurchase+debt_repayments;
    add_financing_needs=net_revenue-financing_needs;
    
    //step 13: determination of the level of new loans and new equity
    max_debt=debt_earnings_ratio*net_earnings;
    //two conditions in eg46,47

    if(add_financing_needs<=max_debt)
    {
        target_loans=add_financing_needs;
        target_equity=0;
    }
    if(add_financing_needs>max_debt)
    {
        target_loans=max_debt;
        target_equity=add_financing_needs-max_debt;
    }
    // determining payout parameters from empirical data

    //step 9b: retained earnings determined from empirical data

    //step 13b: loans determined from empirical data


    //step 13b: bonds issuing determined from empirical data

    //step 13b: equity issuing determined from empirical data

    /* Reset the mall id array */
    //int_array(xmemory->mall_id);
    
    //Set all financial variables:
    set_income_account(income_account);
    set_payment_account(payment_account);
    set_total_revenue(total_revenue);
    set_net_revenue(net_revenue);
    set_operational_costs(operational_costs);
    set_interest_payments(interest_payments);

    set_total_earnings(total_earnings);
    set_net_earnings(net_earnings);
    set_pretax_profit(pretax_profit);
    set_tax_provision(tax_provision);
    set_div_payments(div_payments);

    set_retained_earnings(retained_earnings);
    set_debt_repayments(debt_repayments);
    
    set_share_repurchase_value(share_repurchase_value);
    set_share_repurchase_units(share_repurchase_units);
    set_target_total_shares(target_total_shares);

    set_total_financial_needs(total_financial_needs);
    set_financial_needs(financial_needs);
    set_add_financial_needs(add_financial_needs);
    set_financial_reserves(financial_reserves);
    
    set_target_loans(target_loans);
    set_target_equity(target_equity);
    set_bonds_issue_target(bonds_issue_target);
    set_stocks_issue_target(stock_issue_target);

    set_max_debt(max_debt);
    set_div_earn_ratio(div_earn_ratio);
    set_debt_earn_ratio(debt_earn_ratio);
    set_div_pshareratio(div_pshare_ratio);
    set_earn_pshare_ratio(earn_pshare_ratio);
    set_price_earn_ratio(price_earnings_ratio);
    set_retained_earn_ratio(retained_earn_ratio);
    
    set_critical_price_earn_ratio(critical_price_earn_ratio);
    set_critical_earn_pshare_ratio(critical_earn_pshare_ratio);
    
    return 0;
}


int FirmCalculateFinancialPolicies()
{
    return 0;
}

/// asset market role
int FirmCalculateFirmStockOrders()
{
    return 0;
}

int FirmCalculateFirmBondOrders()
{
    return 0;
}

int FirmUpdateOutstandingAssets()
{
    return 0;
}

/// credit market role
int FirmApplyForBankLoan()
{
    return 0;
}



///agent Clearing house
// role asset marhet role
int ClearingHouseComputeTransactions()
{
    return 0;
}

///agent LimitOrderBook
//role asset market role
int LimitOrderBookComputeTransactions()
{
    return 0;
}

///agent government
///role Tax collector


 //////////////////////


/********************************************************************************
 * EXAMPLE: sending messages
 * add_<messagename>_message(<var1>, <var2>, <var3>, ..., range, x, y, z);
 ********************************************************************************/

/********************************************************************************
 * EXAMPLE: reading messages
 * <messagename>_message = get_first_<messagename>_message()
 * while(<messagename>_message)
 * {
 *    local_variable = <messagename>_message-><varname>;
 *
 *    <messagename>_message = get_next_<messagename>_message(<messagename>_message)
 * }
 *********************************************************************************/


