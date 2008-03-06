/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include "header.h"
#include <CUnit/Basic.h>

/*************************** unittest prototypes ***************************/
void unittest_sum();
void unittest_cumsum();
void unittest_cumpdf();
void unittest_draw();
void unittest_ismember();
void unittest_draw_without_replacement();
void unittest_draw_with_replacement();
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
    pSuite = CU_add_suite("Suite_Household_unittests", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* add the tests to the suite */
    /* add extra tests using || */
    if(
       	NULL == CU_add_test(pSuite, "some_new_functions, sum", unittest_sum) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, cumsum", unittest_cumsum) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, cumpdf", unittest_cumpdf) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, draw", unittest_draw) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, ismember", unittest_ismember) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, draw_without_replacement", unittest_draw_without_replacement) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, draw_with_replacement", unittest_draw_with_replacement) )    	    	
    	//NULL == CU_add_test(pSuite, "Household_send_rule_performance", unittest_Household_send_rule_performance) ||
    	//NULL == CU_add_test(pSuite, "Household_read_all_performances", unittest_Household_read_all_performances) ||
    	//NULL == CU_add_test(pSuite, "Household_select_rule", unittest1_Household_select_rule) ||
    	//NULL == CU_add_test(pSuite, "Household_select_rule", unittest2_Household_select_rule) ||
    	//NULL == CU_add_test(pSuite, "Household_retrieve_rule_details", unittest_Household_retrieve_rule_details) ||
        //NULL == CU_add_test(pSuite, "Household_apply_rule", unittest_Household_apply_rule) ||
        //NULL == CU_add_test(pSuite, "Household_read_transaction", unittest_Household_read_transaction) ||
        //NULL == CU_add_test(pSuite, "Household_read_and_update_ruledetailsystem", unittest_Household_read_and_update_ruledetailsystem) ||
        //NULL == CU_add_test(pSuite, "Household_reset_private_classifiersystem", unittest_Household_reset_private_classifiersystem) ||
        //NULL == CU_add_test(pSuite, "FinancialAgent_daily_reset_public_classifiersystem", unittest_FinancialAgent_daily_reset_public_classifiersystem) ||
        //NULL == CU_add_test(pSuite, "FinancialAgent_read_rule_performance_and_update_classifiersystem", unittest_FinancialAgent_read_rule_performance_and_update_classifiersystem) ||
        //NULL == CU_add_test(pSuite, "FinancialAgent_send_all_performances", unittest_FinancialAgent_send_all_performances) ||
        //NULL == CU_add_test(pSuite, "FinancialAgent_update_ruledetailsystem", unittest_FinancialAgent_update_ruledetailsystem) ||
        //NULL == CU_add_test(pSuite, "FinancialAgent_updateGA", unittest_FinancialAgent_updateGA) ||
        //NULL == CU_add_test(pSuite, "FinancialAgent_send_ruledetailsystem", unittest_FinancialAgent_send_ruledetailsystem) ||
        //NULL == CU_add_test(pSuite, "FinancialAgent_reset_public_classifiersystem", unittest_FinancialAgent_reset_public_classifiersystem))
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
