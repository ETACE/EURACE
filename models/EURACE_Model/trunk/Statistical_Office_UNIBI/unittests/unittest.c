/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include "../../header.h"
#include <CUnit/Basic.h>

/*************************** unittest prototypes ***************************/
void unittest_Eurostat_store_history_monthly();
void unittest_Eurostat_store_history_quarterly();
void unittest_Eurostat_compute_growth_rates_monthly();
void unittest_Eurostat_compute_growth_rates_quarterly();
void unittest_Eurostat_firm_creation();
void unittest_Eurostat_measure_recession();
void unittest_Eurostat_measure_export();
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
    pSuite = CU_add_suite("Suite_Eurostat_unittests", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* add the tests to the suite */
    /* add extra tests using || */
    
    if(
/*
    	NULL == CU_add_test(pSuite, "Eurostat_store_history_monthly", unittest_Eurostat_store_history_monthly) ||
    	NULL == CU_add_test(pSuite, "Eurostat_store_history_quarterly", unittest_Eurostat_store_history_quarterly) ||
    	NULL == CU_add_test(pSuite, "Eurostat_compute_growth_rates_monthly", unittest_Eurostat_compute_growth_rates_monthly) ||
    	NULL == CU_add_test(pSuite, "Eurostat_compute_growth_rates_quarterly", unittest_Eurostat_compute_growth_rates_quarterly) ||
    	NULL == CU_add_test(pSuite, "Eurostat_firm_creation", unittest_Eurostat_firm_creation) ||
    	NULL == CU_add_test(pSuite, "Eurostat_measure_recession", unittest_Eurostat_measure_recession) ||
*/
    	NULL == CU_add_test(pSuite, "Eurostat_measure_export", unittest_Eurostat_measure_export))
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
