/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include "header.h"
#include <CUnit/Basic.h>

/*************************** unittest prototypes ***************************/
void unittest_Firm_compute_income_statement();
void unittest_Firm_compute_balance_sheet();

void unittest1_Firm_compute_payout_policy();
void unittest2_Firm_compute_payout_policy();
void unittest3_Firm_compute_payout_policy();
void unittest4_Firm_compute_payout_policy();
void unittest5_Firm_compute_payout_policy();

void unittest_Firm_apply_for_loans();
void unittest_Firm_read_loan_offers_send_loan_acceptance();
void unittest_Firm_issue_equity();
void unittest_Firm_compute_stock_orders();
void unittest_Firm_compute_bond_orders();
void unittest_Firm_update_outstanding_shares();

void unittest_Household_financial_planning();
void unittest_Household_compute_gross_income();
void unittest_Household_compute_monthly_taxes();
void unittest_Household_compute_net_income();
void unittest_Household_compute_asset_wealth();
void unittest_Household_compute_total_budget();
void unittest_Household_compute_cash_on_hand();
void unittest_Household_update_asset_portfolio();
void unittest_Household_compute_cash_on_hands();
void unittest_Household_compute_consumption_budget();
void unittest_Household_compute_financial_needs_daily();
void unittest_Household_compute_financial_needs_monthly();
void unittest_Household_entry_decision();
void unittest_Household_compute_asset_budget();
void unittest_Household_compute_firm_stock_orders();
void unittest_Household_read_transaction_message();
void unittest_Household_compute_government_bond_orders();
void unittest_Household_compute_firm_bond_orders();

void unittest_Clearinghouse_read_stock_orders();
void unittest_Clearinghouse_compute_stock_transactions();
void unittest_Clearinghouse_send_stock_transactions();

void unittest_Bank_read_loan_request_send_offers();
/*************************** end prototypes ***************************/

int init_suite1(void)
{
    return 0;
}

int clean_suite1(void)
{
    return 0;
}

/** \fn int main(int argc, char * argv[])
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char * argv[])
{
    CU_pSuite pSuite = NULL;
    
    /* Init FLAME */
    initialise_unit_testing();
    
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    
    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_Firm_unittests", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* add the tests to the suite */
    /* add extra tests using || */
    
    if(
    	NULL == CU_add_test(pSuite, "Firm_compute_income_statement", unittest_Firm_compute_income_statement))
    	NULL == CU_add_test(pSuite, "Firm_compute_balance_sheet", unittest_Firm_compute_balance_sheet)  ||
    	NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 1", unittest1_Firm_compute_payout_policy)  ||
    	NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 2", unittest2_Firm_compute_payout_policy)  ||
    	NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 3", unittest3_Firm_compute_payout_policy)  ||
    	NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 4", unittest4_Firm_compute_payout_policy)  ||
    	NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 5", unittest5_Firm_compute_payout_policy)  ||
    	NULL == CU_add_test(pSuite, "Firm_apply_for_loans", unittest_Firm_apply_for_loans) ||
        NULL == CU_add_test(pSuite, "Firm_read_loan_offers_send_loan_acceptance", unittest_Firm_read_loan_offers_send_loan_acceptance) ||
    	NULL == CU_add_test(pSuite, "Bank_read_loan_request_send_offers", unittest_Bank_read_loan_request_send_offers))
        
    	//NULL == CU_add_test(pSuite, "Firm_issue_equity", unittest_Firm_issue_equity) ||
        //NULL == CU_add_test(pSuite, "Firm_compute_stock_orders", unittest_Firm_compute_stock_orders) ||
        //NULL == CU_add_test(pSuite, "Firm_compute_bond_orders", unittest_Firm_compute_bond_orders) ||
        //NULL == CU_add_test(pSuite, "Firm_update_outstanding_shares", unittest_Firm_update_outstanding_shares) || 
    	//NULL == CU_add_test(pSuite, "Clearinghouse_read_stock_orders", unittest_Clearinghouse_read_stock_orders) ||
    	//NULL == CU_add_test(pSuite, "Clearinghouse_compute_stock_transactions", unittest_Clearinghouse_compute_stock_transactions) ||
    	//NULL == CU_add_test(pSuite, "Clearinghouse_send_stock_transactions", unittest_Clearinghouse_send_stock_transactions) ||
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    /* Free FLAME */
    clean_up(0);
    
    return CU_get_error();
}
