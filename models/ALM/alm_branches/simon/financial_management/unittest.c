/*
 *  unittest.c
 *  Test suite for the colony formation model
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// CUnit header
#include <CUnit/Basic.h>

// Model header
#include "header.h"

/*
 * The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 *
 */
int init_suite1(void)
{
    initialise_pointers();
    /* Create dummy space partition */
    add_node(0, -SPINF, SPINF, -SPINF, SPINF, -SPINF, SPINF);
    current_node = *p_node_info;
    /* Pointer agent list to this dummy s.p. */
    p_xmachine = &current_node->agents;
    /* For each message type point message list to this dummy s.p. */
    p_tax_payment_message = &current_node->tax_payment_messages;
    
    /* Add agent we want to test */
    add_Firm_agent();
    
    return 0;
}

/*
 * The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 *
 */
int clean_suite1(void)
{
   return 0;
}

/* 
 * Initialise minimal amount of framework required for the tests
 *
 */

/*
void initialise() 
{
    initialise_pointers();
    add_node(0, -SPINF, SPINF, -SPINF, SPINF, -SPINF, SPINF);
    current_node = *p_node_info;
    p_location_message = &current_node->location_messages;
    p_xmachine = &current_node->agents; 
}*/


/* 
 * The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 *
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* add extra tests using || */
   
   //if (NULL == CU_add_test(pSuite, "test_next_id", test_next_id) ||
/*      if(NULL == CU_add_test(pSuite, "test_start_new_cycle_postion", test_start_new_cycle_postion) ||
       NULL == CU_add_test(pSuite, "test_g0", test_g0) ||
       NULL == CU_add_test(pSuite, "test_nong0", test_nong0) ||
       NULL == CU_add_test(pSuite, "test_differentiate_stem_z", test_differentiate_stem_z) ||
       NULL == CU_add_test(pSuite, "test_migrate", test_migrate))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
*/
   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
