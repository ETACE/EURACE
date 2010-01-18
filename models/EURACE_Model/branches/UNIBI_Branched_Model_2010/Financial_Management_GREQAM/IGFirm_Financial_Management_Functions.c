#include "../header.h"
#include "../IGFirm_agent_header.h"
#include "../my_library_header.h"

/************IGFirm Role: Financial Management Role ********************************/

/*
 * \fn IGFirm_compute_financial_payments()
 * \brief Function to compute the prior financial commitments of the IGFirm: interests, installments, taxes.
 * 
 * The IGFirm computes the commitments by setting these values:
 *  - total_debt_installment_payment
 *  - total_interest_payments
 */
int IGFirm_compute_financial_payments()
{
    
    return 0;
}

/*
 * \fn IGFirm_compute_income_statement()
 * \brief Function to compute the income statement of the IGFirm.
 */
int IGFirm_compute_income_statement()
  
{
    
    return 0;
}

/*
 * \fn IGFirm_compute_dividends()
 * \brief Function to compute the total dividend payout of the IGFirm.
 */
int IGFirm_compute_dividends()
{

    
    return 0;
}

/*
 * \fn IGFirm_compute_total_financial_payments()
 * \brief Function to compute the total financial payments of the IGFirm: interest, installments, taxes, production costs, dividends.
 * 
 *  - total_interest_payment
 *  - total_debt_installment_payment
 *  - total_dividend_payment
 *  - tax_payment
 *  - production_costs
 */
int IGFirm_compute_total_financial_payments()
{
            
    return 0;
}

/*
 * \fn IGFirm_compute_balance_sheet()
 * \brief Function to compute the balance sheet of the IGFirm.
 * We compute these values:
 *  - total_value_capital_stock
 *  - total_value_inventory_stock
 *  - total_assets
 *  - equity
 */
int IGFirm_compute_balance_sheet()
{
    
                                                             
    return 0;
}

/*
 * \fn IGFirm_compute_total_liquidity_needs()
 * \brief Function to compute the total liquidity needs for executing payments.
 * The values computed in this function:
 *  - financial_liquidity_needs: to finance prior commitments + dividend payment
 *  - production_liquidity_needs: to finance production costs
 * The payout policy can be subject to revision if it turns out to be insupportable by the obtained financial resources.
 */
int IGFirm_compute_total_liquidity_needs()
{
    
    return 0;
}

/*
 * \fn IGFirm_check_financial_and_bankruptcy_state()
 * \brief Function that checks the balance sheet and sets flags for the bankruptcy- or financial crisis state.
 */
int IGFirm_check_financial_and_bankruptcy_state()
{

        
    return 0;
}

/*
 * \fn IGFirm_set_bankruptcy_illiquidity()
 * \brief Function to set the type of bankruptcy to illiquidity, set the active flag to 0,
 *  start the bankruptcy idle counter, and then go to end_IGFirm state.
 */
int IGFirm_set_bankruptcy_illiquidity()
{
        
    return 0;
}

/*
 * \fn IGFirm_in_financial_crisis()
 * \brief Function to resolve the financial crisis by lowering dividends.
 */
int IGFirm_in_financial_crisis()
{
    
     return 0;
}

/*
 * \fn IGFirm_not_in_bankruptcy()
 * \brief Idle function to transit from state IGFirm_bankruptcy_checked to state IGFirm_checks_financial_crisis.
 */
int IGFirm_not_in_bankruptcy()
{   
        
    return 0;
}

/*
 * \fn IGFirm_execute_financial_payments()
 * \brief Function to execute financial payments:
 *  - tax_payment
 *  - total_debt_installment_payment
 *  - total_interest_payments
 *  - total_dividend_payment
 * All payments are subtracted from the payment account.
 * After this, all that is left over on the payment account can be used to pay for factor inputs for production.
 */
int IGFirm_execute_financial_payments()
{

    
    return 0;
}

/*
 * \fn IGFirm_set_bankruptcy_insolvency()
 * \brief Function to set the type of bankruptcy to insolvency, set the active flag to 0,
 *  start the bankruptcy idle counter, and then go to end_IGFirm state.
 *  
 */
int IGFirm_set_bankruptcy_insolvency()
{
        
    return 0;
}

/*
 * \fn IGFirm_bankruptcy_insolvency_procedure()
 * \brief Function to process the bankruptcy condition in case of insolvency.
 *  Send a bankruptcy_message to all banks at which the IGFirm has a loan.
 *  Write-off bad debt on the balance sheet of the bank.
 *  Raise new equity by a issuing nes shares on the AFM, following a target leverage ratio (target debt/target equity).
 */
int IGFirm_bankruptcy_insolvency_procedure()
{
    
    return 0;
}

/*
 * \fn IGFirm_bankruptcy_illiquidity_procedure()
 * \brief Function to process the bankruptcy condition in case of illiquidity.
 *  There is no write-off of bad debt on the balance sheet of the banks.
 *  Raise new equity by a issuing new shares on the AFM according to a target liquidity ratio.
 */
int IGFirm_bankruptcy_illiquidity_procedure()
{   
    
    return 0;
}

/*
 * \fn IGFirm_bankruptcy_idle_counter()
 * \brief Function to decrease the bankruptcy_idle_counter.
 *  Note that a negative count means the financing condition has not been yet satisfied at the end of the default idle period.
 */
int IGFirm_bankruptcy_idle_counter()
{   
        
    return 0;
}

/*
 * \fn IGFirm_reset_bankruptcy_flags()
 * \brief Function to reset the bankruptcy flags.
 */
int IGFirm_reset_bankruptcy_flags()
{
    
    return 0;
}

/*
 * \fn IGFirm_compute_and_send_stock_orders()
 * \brief Function to send order_messages to the clearinghouse (share emission or repurchase).
 */
int IGFirm_compute_and_send_stock_orders()
{
    
    return 0;
}


int IGFirm_compute_and_send_stock_orders_bankruptcy()
{
    
    return 0;
}

/*
 * \fn IGFirm_read_stock_transactions()
 * \brief Function to read order_status messages from the clearinghouse, and update the IGFirm's trading account.
 */
int IGFirm_read_stock_transactions()
{
    
    
    return 0;
}
