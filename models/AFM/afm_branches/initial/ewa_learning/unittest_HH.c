/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include "header.h"
#include <CUnit/Basic.h>

/*************************** unittest prototypes ***************************/
void unittest_Household_send_rule_performance();
void unittest_Household_read_all_performances();
void unittest1_Household_select_rule();
void unittest2_Household_select_rule();
void unittest_Household_apply_rule();
void unittest_Household_read_and_update_rule_details();
void unittest_Household_reset_private_classifiersystem();

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
    	NULL == CU_add_test(pSuite, "Household_send_rule_performance", unittest_Household_send_rule_performance) ||
    	NULL == CU_add_test(pSuite, "Household_read_all_performances", unittest_Household_read_all_performances) ||
    	NULL == CU_add_test(pSuite, "Household_select_rule", unittest1_Household_select_rule))
    	//NULL == CU_add_test(pSuite, "Household_select_rule", unittest2_Household_select_rule) ||
        //NULL == CU_add_test(pSuite, "Household_apply_rule", unittest_Household_apply_rule) ||
        //NULL == CU_add_test(pSuite, "Household_read_and_update_rule_details", unittest_Household_read_and_update_rule_details) ||
        //NULL == CU_add_test(pSuite, "Household_reset_private_classifiersystem", unittest_Household_reset_private_classifiersystem))
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
