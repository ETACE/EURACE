/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include <CUnit/Basic.h>
#include "../header.h"
#include "../some_new_functions.h"
#include "../FinancialAgent_agent_header.h"
#include "../FinancialAgent_aux_header.h"

/*************************** unittest prototypes ***************************/

/* Unit tests for auxiliary functions */
void unittest_random_unif();
void unittest_random_unif_interval();
void unittest_sum();
void unittest_cumsum();
void unittest_cumpdf();
void unittest_draw();
void unittest_ismember();
void unittest_ismember_double();
void unittest_draw_without_replacement();
void unittest1_draw_with_replacement();
void unittest2_draw_with_replacement();

/* Unit tests for GA auxiliary functions */
void unittest_single_point_cross_over();
void unittest1_two_point_cross_over();
void unittest2_two_point_cross_over();
void unittest1_two_point_cross_over_alt();
void unittest2_two_point_cross_over_alt();
void unittest3_two_point_cross_over_alt();
void unittest_mutation();

/* Unit tests for GA functions */
void unittest_GA_selection();
void unittest_GA_reproduction();
void unittest1_GA_mutation();
void unittest2_GA_mutation();
void unittest_GA_election();
void unittest_GA_reinsertion();

void unittest_FinancialAgent_print_public_classifiersystem();


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
    pSuite = CU_add_suite("Suite_AuxiliaryFunctions_unittests", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* add the tests to the suite */
    /* add extra tests using || */
    if(
    	/*
        NULL == CU_add_test(pSuite, "some_new_functions, random_unif(0.0,1.0)\n", unittest_random_unif) ||    		
       	NULL == CU_add_test(pSuite, "some_new_functions, random_unif_interval(0.0,10.0)\n", unittest_random_unif_interval) ||
       	NULL == CU_add_test(pSuite, "some_new_functions, sum", unittest_sum) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, cumsum", unittest_cumsum) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, cumpdf", unittest_cumpdf) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, draw", unittest_draw) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, ismember", unittest_ismember) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, ismember_double", unittest_ismember_double) ||
    	
    	NULL == CU_add_test(pSuite, "some_new_functions, draw_without_replacement", unittest_draw_without_replacement) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, draw_with_replacement, case 1", unittest1_draw_with_replacement) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, draw_with_replacement, case 2", unittest2_draw_with_replacement) ||
    	
    	NULL == CU_add_test(pSuite, "FinancialAgent aux functions, single point cross over", unittest_single_point_cross_over) ||
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, two_point_cross_over, case 1", unittest1_two_point_cross_over) ||
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, two_point_cross_over, case 2", unittest2_two_point_cross_over) ||
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, two_point_cross_over_alt, case 1", unittest1_two_point_cross_over_alt) ||    	
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, two_point_cross_over_alt, case 2", unittest2_two_point_cross_over_alt) ||
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, two_point_cross_over_alt, case 3", unittest3_two_point_cross_over_alt) ||
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, mutation", unittest_mutation) ||
    	
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, GA_selection", unittest_GA_selection) ||
    	
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, GA_reproduction", unittest_GA_reproduction) ||
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, GA_mutation, case 1", unittest1_GA_mutation) ||
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, GA_mutation, case 2", unittest2_GA_mutation) ||   	
    	//NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, GA_election", unittest_GA_election) ||
    	*/
    	NULL == CU_add_test(pSuite, "FinancialAgent_aux_functions, GA_reinsertion", unittest_GA_reinsertion))
        
    	//NULL == CU_add_test(pSuite, "test_print\n", test_print) ||
        //NULL == CU_add_test(pSuite, "FinancialAgent_print_public_classifiersystem\n", unittest_FinancialAgent_print_public_classifiersystem))
        
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
