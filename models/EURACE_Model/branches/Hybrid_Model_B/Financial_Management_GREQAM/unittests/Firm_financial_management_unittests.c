#include <CUnit/Basic.h>

#include "../../header.h"
#include "../../Firm_agent_header.h"
#include "../../my_library_header.h"

/************Firm Role: Financial Management Role ********************************/

/************ Unit tests ********************************/
/*
 * \fn: void unittest1_Firm_bankruptcy_insolvency_procedure()
 * \brief: Unit test for: Firm_bankruptcy_insolvency_procedure.
 * Status: NOT Tested
 */
void unittest1_Firm_bankruptcy_insolvency_procedure()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Firm_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	WRITE_OFF_RATIO = 0.33333;
	TARGET_LEVERAGE_RATIO = 1.25;	
	TOTAL_ASSETS = 120.0;
	TOTAL_DEBT = 150.0;	
	PAYMENT_ACCOUNT = 120.0;
	IPO_AMOUNT =0.0;
	
	/***** Messages: initialize message boards **********************************/
/*
	rc = MB_Create(&b_<message>, sizeof(m_<message>));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create '<message>' board\n");
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
*/
	/***** Messages: pre-conditions **********************************/
    //add_<message>_message();
    	    
    /***** Message: Adding message iterators ***************************************/
/*
	rc = MB_Iterator_Create(b_<message>, &i_<message>);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for '<message>'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: '<message>' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: '<message>' board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}
*/	    	    
    /***** Function evaluation ***************************************/
	Firm_bankruptcy_insolvency_procedure();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(IPO_AMOUNT, 24.0, 1e-3);

	
    /***** Messages: Message post-conditions *****/
	//start a reading loop
/*
	START_BANKRUPTCY_MESSAGE_LOOP
	     //CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->credit_refunded, value);
	     //CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->bad_debt, value, 1e-3);
	FINISH_BANKRUPTCY_MESSAGE_LOOP
*/	
    /************* At end of unit test, free the agent **************/
	unittest_free_Firm_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest2_Firm_bankruptcy_insolvency_procedure()
 * \brief: Unit test for: Firm_bankruptcy_insolvency_procedure.
 * Status: NOT Tested
 */
void unittest2_Firm_bankruptcy_insolvency_procedure()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Firm_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	WRITE_OFF_RATIO = 0.33333;
	TARGET_LEVERAGE_RATIO = 2.0;
	TOTAL_ASSETS = 120.0;
	TOTAL_DEBT = 150.0;
	PAYMENT_ACCOUNT = 120.0;
	IPO_AMOUNT =0.0;
	
	/***** Messages: initialize message boards **********************************/
/*
	rc = MB_Create(&b_<message>, sizeof(m_<message>));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create '<message>' board\n");
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
*/
	/***** Messages: pre-conditions **********************************/
    //add_<message>_message();
    	    
    /***** Message: Adding message iterators ***************************************/
/*
	rc = MB_Iterator_Create(b_<message>, &i_<message>);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for '<message>'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: '<message>' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: '<message>' board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}
*/	    	    
    /***** Function evaluation ***************************************/
	Firm_bankruptcy_insolvency_procedure();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(IPO_AMOUNT, 0.0, 1e-3);

	
    /***** Messages: Message post-conditions *****/
	//start a reading loop
/*
	START_BANKRUPTCY_MESSAGE_LOOP
	     //CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->credit_refunded, value);
	     //CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->bad_debt, value, 1e-3);
	FINISH_BANKRUPTCY_MESSAGE_LOOP
*/	
    /************* At end of unit test, free the agent **************/
	unittest_free_Firm_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest3_Firm_bankruptcy_insolvency_procedure()
 * \brief: Unit test for: Firm_bankruptcy_insolvency_procedure.
 * Status: NOT Tested
 */
void unittest3_Firm_bankruptcy_insolvency_procedure()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Firm_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	WRITE_OFF_RATIO = 0.33333;
	TARGET_LEVERAGE_RATIO = 4.0;
	TOTAL_ASSETS = 120.0;
	TOTAL_DEBT = 150.0;
	PAYMENT_ACCOUNT = 120.0;
	IPO_AMOUNT =0.0;
	
	/***** Messages: initialize message boards **********************************/
/*
	rc = MB_Create(&b_<message>, sizeof(m_<message>));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create '<message>' board\n");
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
*/
	/***** Messages: pre-conditions **********************************/
    //add_<message>_message();
    	    
    /***** Message: Adding message iterators ***************************************/
/*
	rc = MB_Iterator_Create(b_<message>, &i_<message>);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for '<message>'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: '<message>' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: '<message>' board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}
*/	    	    
    /***** Function evaluation ***************************************/
	Firm_bankruptcy_insolvency_procedure();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(IPO_AMOUNT, 0.0, 1e-3);

	
    /***** Messages: Message post-conditions *****/
	//start a reading loop
/*
	START_BANKRUPTCY_MESSAGE_LOOP
	     //CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->credit_refunded, value);
	     //CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->bad_debt, value, 1e-3);
	FINISH_BANKRUPTCY_MESSAGE_LOOP
*/	
    /************* At end of unit test, free the agent **************/
	unittest_free_Firm_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

