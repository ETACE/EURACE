/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include "../../header.h"
#include <CUnit/Basic.h>

/*************************** unittest prototypes ***************************/
void unittest_Firm_execute_production();
void unittest_Firm_execute_production_1();
void unittest_Firm_execute_production_2();
void unittest_Firm_calc_production_quantity_1();
void unittest_Firm_calc_production_quantity_2();
void unittest_Firm_calc_production_quantity_3();
void unittest_Firm_receive_capital_goods();
void unittest_Firm_calc_pay_costs();
void unittest_Firm_calc_input_demands();
void unittest_Firm_calc_input_demands_2();
void unittest_Firm_calc_input_demands_3();
void unittest_Firm_calc_input_demands_4();
void unittest_Firm_calc_input_demands_5();
void unittest_Firm_calc_production_quantity_II();
void unittest_Firm_calc_production_quantity_II_2();
void unittest_Firm_calc_production_quantity_II_3();
void unittest_Firm_calc_input_demands_II();
void unittest_Firm_calc_input_demands_II_2();
void unittest_Firm_send_goods_to_mall();
void unittest_Firm_send_goods_to_mall_2();
void unittest_Firm_send_goods_to_mall_3();
void unittest_Firm_send_goods_to_mall_4();
void unittest_Firm_calc_revenue();
void unittest_Firm_compute_sales_statistics();
void unittest_Firm_update_specific_skills_of_worker();
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
    
<<<<<<< .mine
    if(NULL == CU_add_test(pSuite, "Firm_execute_production Case 1",unittest_Firm_execute_production) ||
    		NULL == CU_add_test(pSuite, "Firm_execute_production Case 2",unittest_Firm_execute_production_1)||
    		NULL == CU_add_test(pSuite, "Firm_execute_production Case 3",unittest_Firm_execute_production_2)||
    		NULL == CU_add_test(pSuite, "Firm_calc_production_quantity(), Case 1",unittest_Firm_calc_production_quantity_1) ||
    		NULL == CU_add_test(pSuite, "Firm_calc_production_quantity(), Case 2",unittest_Firm_calc_production_quantity_2) || 
    		NULL == CU_add_test(pSuite, "Firm_calc_production_quantity() Case 3",unittest_Firm_calc_production_quantity_3)||
    		NULL == CU_add_test(pSuite, "Firm_receive_capital_goods",unittest_Firm_receive_capital_goods)||
NULL == CU_add_test(pSuite, "Firm_calc_pay_costs()",unittest_Firm_calc_pay_costs)|| 
NULL == CU_add_test(pSuite, "Firm_calc_input_demands Case 1",unittest_Firm_calc_input_demands)||
NULL == CU_add_test(pSuite, "Firm_calc_input_demands Case 2",unittest_Firm_calc_input_demands_2)|| 
NULL == CU_add_test(pSuite, "Firm_calc_input_demands Case 3",unittest_Firm_calc_input_demands_3)||
NULL == CU_add_test(pSuite, "Firm_calc_input_demands Case 4",unittest_Firm_calc_input_demands_4)|| 
NULL == CU_add_test(pSuite, "Firm_calc_input_demands Case 5",unittest_Firm_calc_input_demands_5)||
NULL == CU_add_test(pSuite,  "Firm_calc_production_quantity Case 1",unittest_Firm_calc_production_quantity_II)||
NULL == CU_add_test(pSuite,  "Firm_calc_production_quantity_2 Case 2",unittest_Firm_calc_production_quantity_II_2)||
NULL == CU_add_test(pSuite,  "Firm_calc_production_quantity_2 Case 3",unittest_Firm_calc_production_quantity_II_3)||
NULL == CU_add_test(pSuite,  "Firm_calc_input_demands_2 Case 1",unittest_Firm_calc_input_demands_II)||
NULL == CU_add_test(pSuite,  "Firm_calc_input_demands_2 Case 2",unittest_Firm_calc_input_demands_II_2)||
NULL == CU_add_test(pSuite,  "Firm_send_goods_to_mall Case 1",unittest_Firm_send_goods_to_mall)||
NULL == CU_add_test(pSuite,  "Firm_send_goods_to_mall Case 2",unittest_Firm_send_goods_to_mall_2)||
NULL == CU_add_test(pSuite,  "Firm_send_goods_to_mall Case 3",unittest_Firm_send_goods_to_mall_3)||
NULL == CU_add_test(pSuite,  "Firm_send_goods_to_mall Case 4",unittest_Firm_send_goods_to_mall_4)||
NULL == CU_add_test(pSuite,  "Firm_calc_revenue",unittest_Firm_calc_revenue)||
NULL == CU_add_test(pSuite,  "Firm_compute_sales_statistics",unittest_Firm_compute_sales_statistics)||
NULL == CU_add_test(pSuite,  "Firm_update_specific_skills_of_worker",unittest_Firm_update_specific_skills_of_worker))

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
