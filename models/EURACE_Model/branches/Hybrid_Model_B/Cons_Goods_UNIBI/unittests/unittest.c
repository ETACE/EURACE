/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include "../../header.h"
#include <CUnit/Basic.h>


/*************************** unittest prototypes ***************************/
void unittest_Mall_update_mall_stock();
void unittest_Mall_send_quality_price_info_1();
void unittest_Mall_update_mall_stocks_sales_rationing_1();
void unittest_Mall_update_mall_stocks_sales_rationing_2();
void unittest_Mall_pay_firm();

void unittest_Mall_reset_export_data();
void unittest_Mall_add_export_data();
void unittest_Mall_send_export_data();

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
    pSuite = CU_add_suite("Suite_Mall_unittests", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* add the tests to the suite */
    /* add extra tests using || */
    
    if(
       	//NULL == CU_add_test(pSuite, "Mall_update_mall_stock", unittest_Mall_update_mall_stock))
        //NULL == CU_add_test(pSuite, "Mall_send_quality_price_info_1", unittest_Mall_send_quality_price_info_1))
      	//NULL == CU_add_test(pSuite, "Mall_update_mall_stocks_sales_rationing_1", unittest_Mall_update_mall_stocks_sales_rationing_1))
        //NULL == CU_add_test(pSuite, "Mall_update_mall_stocks_sales_rationing_2", unittest_Mall_update_mall_stocks_sales_rationing_2))
    	//NULL == CU_add_test(pSuite, "Mall_pay_firm", unittest_Mall_pay_firm))
/*    		
    	NULL == CU_add_test(pSuite, "Mall_reset_export_data", unittest_Mall_reset_export_data) ||
        NULL == CU_add_test(pSuite, "Mall_add_export_data", unittest_Mall_add_export_data) ||
    	NULL == CU_add_test(pSuite, "Mall_send_export_data", unittest_Mall_send_export_data))
*/
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
