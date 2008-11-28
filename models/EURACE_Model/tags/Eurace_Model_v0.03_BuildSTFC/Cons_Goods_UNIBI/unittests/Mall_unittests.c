#include <CUnit/Basic.h>

#include "../../header.h"
#include "../../Mall_agent_header.h"
#include "../../my_library_header.h"

/************Mall ********************************/
#define NO_REGIONS 2 //number of regions (hard-coded here)

/************ Unit tests ********************************/
/*
 * \fn: void unittest_Mall_update_mall_stock()
 * \brief: Unit test for: Mall_update_mall_stock.
 * Status: Not Tested
 */
void unittest_Mall_update_mall_stock()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Mall_update_mall_stock();
    
    /***** Variables: Memory post-conditions *****/
	//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
	
	
/*
 * \fn: void unittest_Mall_send_quality_price_info_1()
 * \brief: Unit test for: Mall_send_quality_price_info_1.
 * Status: Not Tested
 */
void unittest_Mall_send_quality_price_info_1()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Mall_send_quality_price_info_1();
    
    /***** Variables: Memory post-conditions *****/
	//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
	
/*
 * \fn: void unittest_Mall_update_mall_stocks_sales_rationing_1()
 * \brief: Unit test for: Mall_update_mall_stocks_sales_rationing_1.
 * Status: Not Tested
 */
void unittest_Mall_update_mall_stocks_sales_rationing_1()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Mall_update_mall_stocks_sales_rationing_1();
    
    /***** Variables: Memory post-conditions *****/
	//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
	

/*
 * \fn: void unittest_Mall_update_mall_stocks_sales_rationing_2()
 * \brief: Unit test for: Mall_update_mall_stocks_sales_rationing_2.
 * Status: Not Tested
 */
void unittest_Mall_update_mall_stocks_sales_rationing_2()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Mall_update_mall_stocks_sales_rationing_2();
    
    /***** Variables: Memory post-conditions *****/
	//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
	

/*
 * \fn: void unittest_Mall_pay_firm()
 * \brief: Unit test for: Mall_pay_firm.
 * Status: Not Tested
 */
void unittest_Mall_pay_firm()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Mall_pay_firm();
    
    /***** Variables: Memory post-conditions *****/
	//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}


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
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_VOLUME_MATRIX[0], 0.0, 1e-3); //[0][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_VOLUME_MATRIX[1], 0.0, 1e-3); //[0][1]
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_VOLUME_MATRIX[2], 0.0, 1e-3); //[1][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_VOLUME_MATRIX[3], 0.0, 1e-3); //[1][1]

	CU_ASSERT_DOUBLE_EQUAL(EXPORT_VALUE_MATRIX[0], 0.0, 1e-3); //[0][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_VALUE_MATRIX[1], 0.0, 1e-3); //[0][1]
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_VALUE_MATRIX[2], 0.0, 1e-3); //[1][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_VALUE_MATRIX[3], 0.0, 1e-3); //[1][1]

	CU_ASSERT_DOUBLE_EQUAL(EXPORT_PREVIOUS_VALUE_MATRIX[0], 0.0, 1e-3); //[0][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_PREVIOUS_VALUE_MATRIX[1], 0.0, 1e-3); //[0][1]
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_PREVIOUS_VALUE_MATRIX[2], 0.0, 1e-3); //[1][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_PREVIOUS_VALUE_MATRIX[3], 0.0, 1e-3); //[1][1]

    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Mall_add_export_data()
 * \brief: Unit test for: Mall_add_export_data.
 * Status: Tested OK
 * Tests if the mall_export_data is correctly added to memory.
 */
void unittest_Mall_add_export_data()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	//Mall_add_export_data(int firm_region, int household_region, double export_volume, double export_value, double export_previous_value);
	Mall_add_export_data(1, 1,   1.0,   1.0,   1.0);
	Mall_add_export_data(1, 2, 100.0, 100.0, 100.0);
	Mall_add_export_data(2, 1, 100.0, 100.0, 100.0);
	Mall_add_export_data(2, 2,   1.0,   1.0,   1.0);
	
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_VOLUME_MATRIX[0], 1.0, 1e-3); //[0][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_VOLUME_MATRIX[1], 100.0, 1e-3); //[0][1]
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_VOLUME_MATRIX[2], 100.0, 1e-3); //[1][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_VOLUME_MATRIX[3], 1.0, 1e-3); //[1][1]

	CU_ASSERT_DOUBLE_EQUAL(EXPORT_VALUE_MATRIX[0], 1.0, 1e-3); //[0][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_VALUE_MATRIX[1], 100.0, 1e-3); //[0][1]
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_VALUE_MATRIX[2], 100.0, 1e-3); //[1][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_VALUE_MATRIX[3], 1.0, 1e-3); //[1][1]

	CU_ASSERT_DOUBLE_EQUAL(EXPORT_PREVIOUS_VALUE_MATRIX[0], 1.0, 1e-3); //[0][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_PREVIOUS_VALUE_MATRIX[1], 100.0, 1e-3); //[0][1]
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_PREVIOUS_VALUE_MATRIX[2], 100.0, 1e-3); //[1][0]
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_PREVIOUS_VALUE_MATRIX[3], 1.0, 1e-3); //[1][1]

	
    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Mall_reset_export_data()
 * \brief: Unit test for: Mall_reset_export_data.
 * Status: Not tested
 * Tests if the mall_data_message is correctly send.
 */
void unittest_Mall_send_export_data()
{
	int rc;

    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	ID=1;
	EXPORT_VOLUME_MATRIX[0]=1.0;
	EXPORT_VOLUME_MATRIX[1]=2.0;
	EXPORT_VOLUME_MATRIX[2]=3.0;
	EXPORT_VOLUME_MATRIX[3]=4.0;
	
	EXPORT_VALUE_MATRIX[0]=1.0;
	EXPORT_VALUE_MATRIX[1]=2.0;
	EXPORT_VALUE_MATRIX[2]=3.0;
	EXPORT_VALUE_MATRIX[3]=4.0;

	EXPORT_PREVIOUS_VALUE_MATRIX[0]=1.0;
	EXPORT_PREVIOUS_VALUE_MATRIX[1]=2.0;
	EXPORT_PREVIOUS_VALUE_MATRIX[2]=3.0;
	EXPORT_PREVIOUS_VALUE_MATRIX[3]=4.0;

	/***** Messages: pre-conditions **********************************/
    
	/***** Messages: initialize message boards **********************************/
	rc = MB_Create(&b_mall_data, sizeof(m_mall_data));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'mall_data' board\n");
    	       switch(rc) {
    	           case MB_ERR_INVALID:
    	               fprintf(stderr, "\t reason: Invalid message size\n");
    	               break;
    	           case MB_ERR_MEMALLOC:
    	               fprintf(stderr, "\t reason: out of memory\n");
    	               break;
    	           case MB_ERR_INTERNAL:
    	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
    	               break;
    	       }
    	    }
    	    #endif

	/***** Messages: pre-conditions **********************************/
    	    
    /***** Adding message iterators ***************************************/
    rc = MB_Iterator_Create(b_mall_data, &i_mall_data);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'mall_data'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'mall_data' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'mall_data' board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}

    /***** Function evaluation ***************************************/
	Mall_send_export_data();
    
    /***** Variables: Memory post-conditions *****/

    START_MALL_DATA_MESSAGE_LOOP
    printf("\n firm_region=%d, household_region=%d\n", mall_data_message->firm_region, mall_data_message->household_region);

    //mall_data_message(ID, firm_region, household_region, export_volume, export_value, export_previous_value);    
    if (mall_data_message->firm_region==1 && mall_data_message->household_region==1)
	{
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_volume, 1.0, 1e-3);
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_value, 1.0, 1e-3);
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_previous_value, 1.0, 1e-3);
	}
    if (mall_data_message->firm_region==1 && mall_data_message->household_region==2)
	{
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_volume, 2.0, 1e-3);
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_value, 2.0, 1e-3);
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_previous_value, 3.0, 1e-3);
	}
	if (mall_data_message->firm_region==2 && mall_data_message->household_region==1)
	{
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_volume, 3.0, 1e-3);
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_value, 3.0, 1e-3);
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_previous_value, 3.0, 1e-3);
	}
	if (mall_data_message->firm_region==2 && mall_data_message->household_region==2)
	{
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_volume, 4.0, 1e-3);
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_value, 4.0, 1e-3);
    	CU_ASSERT_DOUBLE_EQUAL(mall_data_message->export_previous_value, 4.0, 1e-3);
	}
	FINISH_MALL_DATA_MESSAGE_LOOP

	
    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
