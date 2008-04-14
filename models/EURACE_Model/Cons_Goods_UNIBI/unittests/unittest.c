/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include "header.h"
#include <CUnit/Basic.h>

/*************************** unittest prototypes ***************************/
void unittest_Firm_calc_production_quantity();
void unittest_Firm_calc_input_demands();
void unittest_Firm_calc_production_quantity_2();
void unittest_Firm_calc_input_demands_2();
void unittest_Firm_send_capital_demand();
void unittest_Firm_calc_pay_costs();
void unittest_Firm_send_goods_to_mall();
void unittest_Firm_calc_revenue();
void unittest_Firm_update_specific_skills_of_workers();
void unittest_Firm_send_data_to_Market_Research();
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
    	NULL == CU_add_test(pSuite, "Firm_calc_production_quantity", unittest_Firm_calc_production_quantity))
    	//NULL == CU_add_test(pSuite, "Firm_calc_input_demands", unittest_Firm_calc_input_demands)  ||
    	//NULL == CU_add_test(pSuite, "Firm_calc_production_quantity_2", unittest_Firm_calc_production_quantity_2)  ||
    	//NULL == CU_add_test(pSuite, "Firm_calc_input_demands_2", unittest_Firm_calc_input_demands_2)  ||
    	//NULL == CU_add_test(pSuite, "Firm_send_capital_demand", unittest_Firm_send_capital_demand)  ||
    	//NULL == CU_add_test(pSuite, "Firm_calc_pay_costs", unittest_Firm_calc_pay_costs)  ||
    	//NULL == CU_add_test(pSuite, "Firm_send_goods_to_mall", unittest_Firm_send_goods_to_mall)  ||
    	//NULL == CU_add_test(pSuite, "Firm_calc_revenue", unittest_Firm_calc_revenue)  ||
    	//NULL == CU_add_test(pSuite, "Firm_update_specific_skills_of_workers", unittest_Firm_update_specific_skills_of_workers)  ||
    	//NULL == CU_add_test(pSuite, "Firm_send_data_to_Market_Research", unittest_Firm_send_data_to_Market_Research))
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
