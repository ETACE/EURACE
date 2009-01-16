/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include "../../header.h"
#include <CUnit/Basic.h>

/*************************** unittest prototypes ***************************/
/*
void unittest_Firm_compute_income_statement();
void unittest_Firm_compute_balance_sheet();

void unittest_Firm_compute_financial_payments(); //To create
void unittest_Firm_compute_dividends(); //To create
void unittest_Firm_compute_total_financial_payments(); //To create
void unittest_Firm_compute_total_liquidity_needs(); //To create
void unittest_Firm_check_financial_and_bankruptcy_state(); //To create
void unittest_Firm_in_bankruptcy(); //To create
*/
void unittest1_Firm_bankruptcy_insolvency_procedure();
void unittest2_Firm_bankruptcy_insolvency_procedure();
void unittest3_Firm_bankruptcy_insolvency_procedure();
/*
void unittest1_Firm_bankruptcy_illiquidity_procedure();
void unittest_Firm_bankruptcy_idle_counter(); //To create
void unittest_Firm_in_financial_crisis(); //To create
void unittest_Firm_execute_financial_payments(); //To create
void unittest_Firm_compute_and_send_stock_orders(); //To create
void unittest_Firm_read_stock_transactions(); //To create
*/

//OLD UNIT TESTS
/*
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
*/
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
   		NULL == CU_add_test(pSuite, "Firm_bankruptcy_insolvency_procedure, Case 1", unittest1_Firm_bankruptcy_insolvency_procedure) ||
    	NULL == CU_add_test(pSuite, "Firm_bankruptcy_insolvency_procedure, Case 2", unittest2_Firm_bankruptcy_insolvency_procedure) ||    		
        NULL == CU_add_test(pSuite, "Firm_bankruptcy_insolvency_procedure, Case 3", unittest3_Firm_bankruptcy_insolvency_procedure))
    	//NULL == CU_add_test(pSuite, "Firm_compute_income_statement", unittest_Firm_compute_income_statement))
    	//NULL == CU_add_test(pSuite, "Firm_compute_balance_sheet", unittest_Firm_compute_balance_sheet) ||
    	//NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 1", unittest1_Firm_compute_payout_policy)  ||
    	//NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 2", unittest2_Firm_compute_payout_policy)  ||
    	//NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 3", unittest3_Firm_compute_payout_policy)  ||
    	//NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 4", unittest4_Firm_compute_payout_policy)  ||
    	//NULL == CU_add_test(pSuite, "Firm_compute_payout_policy, External financing: case 5", unittest5_Firm_compute_payout_policy)  ||
    	//NULL == CU_add_test(pSuite, "Firm_apply_for_loans", unittest_Firm_apply_for_loans))
        //NULL == CU_add_test(pSuite, "Firm_read_loan_offers_send_loan_acceptance", unittest_Firm_read_loan_offers_send_loan_acceptance) ||
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
