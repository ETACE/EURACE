/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */
#include <CUnit/Basic.h>
#include "../header.h"

/*************************** unittest prototypes ***************************/
void unittest_random_unif();
void unittest_random_unif_interval();
void unittest_sum();
void unittest_cumsum();
void unittest_cumpdf();
void unittest_draw();
void unittest_ismember();
void unittest_draw_without_replacement();
void unittest_draw_with_replacement();
void unittest_single_point_cross_over();
void unittest_two_point_cross_over();
void unittest_two_point_cross_over_alt();
void unittest_mutation();

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
        NULL == CU_add_test(pSuite, "some_new_functions, random_unif(0.0,1.0)\n", unittest_random_unif) ||    		
       	NULL == CU_add_test(pSuite, "some_new_functions, random_unif_interval(0.0,10.0)\n", unittest_random_unif_interval) ||
       	NULL == CU_add_test(pSuite, "some_new_functions, sum", unittest_sum)  ||
    	NULL == CU_add_test(pSuite, "some_new_functions, cumsum", unittest_cumsum) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, cumpdf", unittest_cumpdf) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, draw", unittest_draw) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, ismember", unittest_ismember) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, draw_without_replacement", unittest_draw_without_replacement) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, draw_with_replacement", unittest_draw_with_replacement) ||
    	NULL == CU_add_test(pSuite, "some_new_functions, single_point_cross_over", unittest_single_point_cross_over))
    	//NULL == CU_add_test(pSuite, "some_new_functions, two_point_cross_over", unittest_two_point_cross_over) ||
    	//NULL == CU_add_test(pSuite, "some_new_functions, two_point_cross_over_alt", unittest_two_point_cross_over) ||
    	//NULL == CU_add_test(pSuite, "some_new_functions, mutation", unittest_mutation))
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
