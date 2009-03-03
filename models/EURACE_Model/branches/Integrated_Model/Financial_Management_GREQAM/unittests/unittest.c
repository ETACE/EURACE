/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include "../../header.h"
#include <CUnit/Basic.h>

/*************************** unittest prototypes ***************************/

void unittest_Firm_compute_financial_payments();

void unittest_Firm_compute_dividends();
void unittest_Firm_compute_income_statement();
void unittest_Firm_compute_total_financial_payments();
void unittest_Firm_compute_balance_sheet();
void unittest_Firm_compute_total_liquidity_needs();

void unittest1_Firm_check_financial_and_bankruptcy_state();
void unittest2_Firm_check_financial_and_bankruptcy_state();

void unittest_Firm_in_financial_crisis();
void unittest1_Firm_execute_financial_payments();
void unittest2_Firm_execute_financial_payments();
void unittest_Firm_bankruptcy_idle_counter();
void unittest_Firm_bankruptcy_illiquidity_procedure();

void unittest_Firm_reset_bankruptcy_flags();
//void unittest_Firm_compute_and_send_stock_orders();
//void unittest_Firm_read_stock_transactions();

void unittest_Firm_set_bankruptcy_illiquidity(); //uses define
void unittest_Firm_set_bankruptcy_insolvency(); //uses define
void unittest1_Firm_bankruptcy_insolvency_procedure(); //uses define
void unittest2_Firm_bankruptcy_insolvency_procedure(); //uses define
void unittest3_Firm_bankruptcy_insolvency_procedure(); //uses define

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
/*
        NULL == CU_add_test(pSuite, "Firm_compute_financial_payments", unittest_Firm_compute_financial_payments) ||
        NULL == CU_add_test(pSuite, "Firm_compute_dividends", unittest_Firm_compute_dividends) ||
        NULL == CU_add_test(pSuite, "Firm_compute_income_statement", unittest_Firm_compute_income_statement) ||
        NULL == CU_add_test(pSuite, "Firm_compute_total_financial_payments", unittest_Firm_compute_total_financial_payments) ||
        NULL == CU_add_test(pSuite, "Firm_compute_balance_sheet", unittest_Firm_compute_balance_sheet) ||
        NULL == CU_add_test(pSuite, "Firm_compute_total_liquidity_needs", unittest_Firm_compute_total_liquidity_needs) ||
        NULL == CU_add_test(pSuite, "Firm_check_financial_and_bankruptcy_state, Case 1", unittest1_Firm_check_financial_and_bankruptcy_state) ||
        NULL == CU_add_test(pSuite, "Firm_check_financial_and_bankruptcy_state, Case 2", unittest2_Firm_check_financial_and_bankruptcy_state) ||
        NULL == CU_add_test(pSuite, "Firm_in_financial_crisis", unittest_Firm_in_financial_crisis) ||

        NULL == CU_add_test(pSuite, "Firm_execute_financial_payments, Case 1", unittest1_Firm_execute_financial_payments) ||
        NULL == CU_add_test(pSuite, "Firm_execute_financial_payments, Case 2", unittest2_Firm_execute_financial_payments))
/*
        NULL == CU_add_test(pSuite, "Firm_bankruptcy_idle_counter", unittest_Firm_bankruptcy_idle_counter) ||
        NULL == CU_add_test(pSuite, "Firm_bankruptcy_illiquidity_procedure", unittest_Firm_bankruptcy_illiquidity_procedure) ||
        NULL == CU_add_test(pSuite, "Firm_reset_bankruptcy_flags", unittest_Firm_reset_bankruptcy_flags))
*/
        //NULL == CU_add_test(pSuite, "Firm_compute_and_send_stock_orders", unittest_Firm_compute_and_send_stock_orders) ||
        //NULL == CU_add_test(pSuite, "Firm_read_stock_transactions", unittest_Firm_read_stock_transactions))
        //NULL == CU_add_test(pSuite, "Firm_set_bankruptcy_illiquidity", unittest_Firm_set_bankruptcy_illiquidity) ||
        //NULL == CU_add_test(pSuite, "Firm_set_bankruptcy_insolvency", unittest_Firm_set_bankruptcy_insolvency) ||

    	//NULL == CU_add_test(pSuite, "Firm_bankruptcy_insolvency_procedure, Case 1", unittest1_Firm_bankruptcy_insolvency_procedure))// ||
        //NULL == CU_add_test(pSuite, "Firm_bankruptcy_insolvency_procedure, Case 2", unittest2_Firm_bankruptcy_insolvency_procedure) ||            
        //NULL == CU_add_test(pSuite, "Firm_bankruptcy_insolvency_procedure, Case 3", unittest3_Firm_bankruptcy_insolvency_procedure))          
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
