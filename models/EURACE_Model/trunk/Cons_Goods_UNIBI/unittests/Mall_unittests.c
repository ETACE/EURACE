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
	EXPORT_MATRIX[2]=3.0;
	EXPORT_MATRIX[3]=4.0;
	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Mall_send_export_data();
    
    /***** Variables: Memory post-conditions *****/
    START_MALL_DATA_MESSAGE_LOOP
    //mall_data_message(ID, firm_region, household_region, value);

    if (mall_data_message->firm_region==1 && mall_data_message->household_region==1)
	{
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->value, 1.0, 1e-3);
	}
    if (mall_data_message->firm_region==1 && mall_data_message->household_region==2)
	{
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->value, 2.0, 1e-3);
	}
	if (mall_data_message->firm_region==2 && mall_data_message->household_region==1)
	{
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->value, 3.0, 1e-3);
	}
	if (mall_data_message->firm_region==2 && mall_data_message->household_region==2)
	{
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->value, 4.0, 1e-3);
	}
	FINISH_MALL_DATA_MESSAGE_LOOP
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
