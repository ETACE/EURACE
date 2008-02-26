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

#define SURFACE_WIDTH 			500.0
// keratinocyte cell types
#define K_TYPE_STEM     	 	0
#define K_TYPE_TA       	 	1
#define K_TYPE_COMM     	 	2
#define K_TYPE_CORN				3
#define K_TYPE_HACAT			4

/*
 * The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 *
 */
int init_suite1(void)
{
	initialise_pointers();
	add_node(0, -SPINF, SPINF, -SPINF, SPINF, -SPINF, SPINF);
	current_node = *p_node_info;
	p_location_message = &current_node->location_messages;
	p_xmachine = &current_node->agents;	
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
 * Tests for keratinocyte_check_agent_id()
 * REMOVED: agent ids are now char arrays not integers
 */
/*void test_next_id() 
{
	const int ID = 10;
	//initialise();

	CU_ASSERT_EQUAL(last_agent_id, -1); 
	
	// add agent with id = 10
	add_keratinocyte_agent(ID, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	0, SURFACE_WIDTH);
	current_xmachine = *p_xmachine;	
	
	output_location(0);
	keratinocyte_check_agent_id();
	
	CU_ASSERT_EQUAL(last_agent_id, ID); 
}*/

/*
 * Tests for keratinocyte_cycle() and related
 * 
 */

void test_start_new_cycle_postion() 
{
	int pos;
	double nonr[1] = {0.2};
	char_array * id_temp;
	
	//initialise();
	
	// add agent with type stem
	id_temp = init_char_array();
	add_char(id_temp, '1');
	add_keratinocyte_agent(id_temp, K_TYPE_STEM, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	current_xmachine = *p_xmachine;
	
	//set_non_random(&nonr[0], 1);
	pos = start_new_cycle_postion();
	
	CU_ASSERT_EQUAL(pos, 6); 
}

void test_g0() 
{
	const int CYCLE = 10;
	const int CONTACT_INHIB_TICKS = 10;
	char_array * id_temp;
	//initialise();
	
	calcium_level = 0.1;
	
	// add agent with 5 bonds in x-y plane, no z bonds, not on edge of substrate
	id_temp = init_char_array();
	add_char(id_temp, '1');
	add_keratinocyte_agent(id_temp, 10, 10, 0, 0, 0, 0, 0, 5, 0, 0, CYCLE, 0, 0, CONTACT_INHIB_TICKS, 0, 0, 0);	
	current_xmachine = *p_xmachine;

	cycle();	
	
	CU_ASSERT_EQUAL(get_cycle(), CYCLE); 
	CU_ASSERT_EQUAL(get_contact_inhibited_ticks(), CONTACT_INHIB_TICKS+1);
}

void test_nong0() 
{
	const int CYCLE = 10;
	const int CONTACT_INHIB_TICKS = 10;
	char_array * id_temp;
	//initialise();
	
	calcium_level = 0.1;
	
	// add agent with 1 bonds in x-y plane, no z bonds, not on edge of substrate
	id_temp = init_char_array();
	add_char(id_temp, '1');
	add_keratinocyte_agent(id_temp, K_TYPE_STEM, 10, 10, 0, 0, 0, 0, 1, 0, 0, CYCLE, 0, CONTACT_INHIB_TICKS, 0, 0, 0, 0);	
	current_xmachine = *p_xmachine;

	cycle();	
	
	CU_ASSERT_EQUAL(get_cycle(), CYCLE+1); 
	CU_ASSERT_EQUAL(get_contact_inhibited_ticks(), 0);
}

/*
 * Tests for keratinocyte_differentiate()
 * 
 */
void test_differentiate_stem_z() 
{
	//initialise();
	char_array * id_temp;
	id_temp = init_char_array();
	add_char(id_temp, '1');
	add_keratinocyte_agent(id_temp, K_TYPE_STEM, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);	
	current_xmachine = *p_xmachine;
	
	differentiate();	
	
	CU_ASSERT_EQUAL(get_type(), K_TYPE_TA); 
}

/*
 * Tests for keratinocyte_migrate()
 * 
 */
 
void test_migrate() 
{
    const double DIR = 3.925; // roughly 225 degrees to x axis
    const double MOTILITY = 1.0;
   	char_array * id_temp;
   	// to prevent dir being changed in migrate
   	double nonr[1] = {0.2};
	//set_non_random(&nonr[0], 1);
	
	//initialise();
	calcium_level = 0.1;
	
	// add agent at x=zero y=zero heading of the both x and y edges at 0,0
	id_temp = init_char_array();
	add_char(id_temp, '1');
	add_keratinocyte_agent(id_temp, K_TYPE_TA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, MOTILITY, DIR, 0);	
	current_xmachine = *p_xmachine;

	migrate();	
	
	// test that we are still on the substrate
	CU_ASSERT(get_x() > 0);
	CU_ASSERT(get_y() > 0);	
} 


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
   	if(NULL == CU_add_test(pSuite, "test_start_new_cycle_postion", test_start_new_cycle_postion) ||
   	   NULL == CU_add_test(pSuite, "test_g0", test_g0) ||
   	   NULL == CU_add_test(pSuite, "test_nong0", test_nong0) ||
	   NULL == CU_add_test(pSuite, "test_differentiate_stem_z", test_differentiate_stem_z) ||
   	   NULL == CU_add_test(pSuite, "test_migrate", test_migrate))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
   
   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
