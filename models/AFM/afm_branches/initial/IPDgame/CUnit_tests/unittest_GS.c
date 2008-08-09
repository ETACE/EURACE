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
void unittest_GameSolver_play_tournament();
void unittest_GameSolver_play_game();
void unittest_GameSolver_apply_GA();

void unittest_GameSolver_read_rule_performance_update_classifiersystem();
void unittest_GameSolver_send_all_performances();
void unittest_GameSolver_send_rule_details();

void unittest_GameSolver_reset_public_classifiersystem();
void unittest_GameSolver_print_public_classifiersystem();

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
    pSuite = CU_add_suite("Suite_GameSolverFunctions_unittests", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* add the tests to the suite */
    /* add extra tests using || */
    if(
            NULL == CU_add_test(pSuite, "GameSolver_play_tournament\n", unittest_GameSolver_play_tournament) ||
            NULL == CU_add_test(pSuite, "GameSolver_play_game\n", unittest_GameSolver_play_game) ||    		
            NULL == CU_add_test(pSuite, "GameSolver_apply_GA\n", unittest_GameSolver_apply_GA) ||
            NULL == CU_add_test(pSuite, "GameSolver_read_rule_performance_update_classifiersystem\n", unittest_GameSolver_read_rule_performance_update_classifiersystem) ||    		
            NULL == CU_add_test(pSuite, "GameSolver_send_all_performances\n", unittest_GameSolver_send_all_performances) ||    		
            NULL == CU_add_test(pSuite, "GameSolver_send_rule_details\n", unittest_GameSolver_send_rule_details) ||    		
            NULL == CU_add_test(pSuite, "GameSolver_print_public_classifiersystem\n", unittest_GameSolver_print_public_classifiersystem) ||
            NULL == CU_add_test(pSuite, "GameSolver_reset_public_classifiersystem\n", unittest_GameSolver_reset_public_classifiersystem))
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
