#include <CUnit/Basic.h>

#include "../../header.h"
#include "../../Mall_agent_header.h"
#include "../../my_library_header.h"

/************Mall ********************************/

/************ Unit tests ********************************/
/*
 * \fn: void unittest_Mall_reset_export_data()
 * \brief: Unit test for: Mall_reset_export_data.
 * Status: Tested OK (NOTE: requires NO_REGIONS=2)
 */
void unittest_Mall_reset_export_data()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Mall_reset_export_data();
    
    /***** Variables: Memory post-conditions *****/
    //CU_ASSERT_DOUBLE_EQUAL(, 0.0, 1e-3);
    //CU_ASSERT_EQUAL();
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[0], 0.0, 1e-3);   //[0][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[1], 0.0, 1e-3); //[0][1]
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[2], 0.0, 1e-3); //[1][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[3], 0.0, 1e-3);   //[1][1]

	
    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Mall_reset_export_data()
 * \brief: Unit test for: Mall_reset_export_data.
 * Status: Tested OK
 */
void unittest_Mall_add_export_data()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	//Mall_add_export_data(int firm_region, int household_region, double transaction_value);
	
	Mall_add_export_data(1, 1, 1.0);
	Mall_add_export_data(1, 2, 100.0);
	Mall_add_export_data(2, 1, 100.0);
	Mall_add_export_data(2, 2, 1.0);
	
    /***** Variables: Memory post-conditions *****/
    //CU_ASSERT_DOUBLE_EQUAL(, 0.0, 1e-3);
    //CU_ASSERT_EQUAL();
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[0], 1.0, 1e-3);   //[0][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[1], 100.0, 1e-3); //[0][1]
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[2], 100.0, 1e-3); //[1][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[3], 1.0, 1e-3);   //[1][1]

	
    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Mall_reset_export_data()
 * \brief: Unit test for: Mall_reset_export_data.
 * Status: Not tested
 */
void unittest_Mall_send_export_data()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	ID=1;
	EXPORT_MATRIX[0]=1.0;
	EXPORT_MATRIX[1]=2.0;
	EXPORT_MATRIX[2]=2.0;
	EXPORT_MATRIX[3]=1.0;
	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Mall_send_export_data();
    
    /***** Variables: Memory post-conditions *****/
    //CU_ASSERT_DOUBLE_EQUAL(, 0.0, 1e-3);
    //CU_ASSERT_EQUAL();

	
    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
