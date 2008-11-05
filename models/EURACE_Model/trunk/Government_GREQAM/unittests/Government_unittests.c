#include <CUnit/Basic.h>
//#include "../../header.h"
//#include "../../Government_agent_header.h"

#include "../header.h"
#include "../Government_agent_header.h"
#include "../../my_library_header.h"

/************Government: Public Sector Role ********************************/

/************ Unit tests ********************************/

/*
 * \fn: void unittest_Government_send_policy_announcements()
 * \brief: Unit tests for: Government_send_policy_announcements
 * Status: NOT Tested
 */
void unittest_Government_send_policy_announcements()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_policy_announcement, sizeof(m_policy_announcement));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'policy_announcement' board\n");
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

	rc = MB_Iterator_Create(b_policy_announcement, &i_policy_announcement);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'policy_announcement'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'policy_announcement' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
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
	Government_send_policy_announcements();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/
	//start a reading loop

	START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
	     //CU_ASSERT_EQUAL(policy_announcement_message->var, value);
	     //CU_ASSERT_DOUBLE_EQUAL(policy_announcement_message->var, value, 1e-3);
	FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Government_read_tax_payments()
 * \brief: Unit tests for: Government_read_tax_payments
 * Status: NOT Tested
 */
void unittest_Government_read_tax_payments()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	ID=1;
	
	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_tax_payment, sizeof(m_tax_payment));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'tax_payment' board\n");
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
     add_tax_payment_message(ID, 100.0);
    	    
    /***** Adding message iterators ***************************************/

	rc = MB_Iterator_Create(b_tax_payment, &i_tax_payment);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'tax_payment'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'tax_payment' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'tax_payment' board is locked\n");
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
	Government_read_tax_payments();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Government_read_unemployment_benefit_notifications()
 * \brief: Unit tests for: Government_read_unemployment_benefit_notifications
 * Status: NOT Tested
 */
void unittest_Government_read_unemployment_benefit_notifications()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	ID=1;
	
	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_unemployment_notification, sizeof(m_unemployment_notification));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'unemployment_notification' board\n");
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
     //add_unemployment_notification_message(gov_id,last_labour_income);
     add_unemployment_notification_message(ID, 100.0);
    	    
    /***** Adding message iterators ***************************************/

	rc = MB_Iterator_Create(b_unemployment_notification, &i_unemployment_notification);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'unemployment_notification'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'unemployment_notification' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'unemployment_notification' board is locked\n");
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
	Government_read_unemployment_benefit_notifications();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/

    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Government_read_transfer_notifications()
 * \brief: Unit tests for: Government_read_transfer_notifications
 * Status: NOT Tested
 */
void unittest_Government_read_transfer_notifications()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	ID=1;
	
	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_hh_transfer_notification, sizeof(m_hh_transfer_notification));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'transfer_notification' board\n");
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
     add_hh_transfer_notification_message(ID);
    	    
    /***** Adding message iterators ***************************************/

	rc = MB_Iterator_Create(b_hh_transfer_notification, &i_hh_transfer_notification);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'transfer_notification'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'transfer_notification' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'transfer_notification' board is locked\n");
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
	Government_read_transfer_notifications();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/

    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Government_read_subsidy_notifications()
 * \brief: Unit tests for: Government_read_subsidy_notifications
 * Status: NOT Tested
 */
void unittest_Government_read_subsidy_notifications()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	ID=1;
	
	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_hh_subsidy_notification, sizeof(m_hh_subsidy_notification));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'subsidy_notification' board\n");
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
     add_hh_subsidy_notification_message(ID);
    	    
    /***** Adding message iterators ***************************************/

	rc = MB_Iterator_Create(b_hh_subsidy_notification, &i_hh_subsidy_notification);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'subsidy_notification'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'subsidy_notification' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'subsidy_notification' board is locked\n");
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
	Government_read_subsidy_notifications();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/

    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Government_budget_accounting()
 * \brief: Unit tests for: Government_budget_accounting
 * Status: NOT Tested
 */
void unittest_Government_budget_accounting()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: initialize message boards **********************************/

	/***** Messages: pre-conditions **********************************/
    	    
    /***** Adding message iterators ***************************************/

    /***** Function evaluation ***************************************/
	Government_budget_accounting();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/

    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Government_read_data_from_Eurostat()
 * \brief: Unit tests for: Government_read_data_from_Eurostat
 * Status: NOT Tested
 */
void unittest_Government_read_data_from_Eurostat()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	ID=1;

	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_data_for_government, sizeof(m_data_for_government));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'data_for_government' board\n");
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
     //add_data_for_government_message(gov_id, region_id, gdp, mean_wage);
     add_data_for_government_message(ID, 1, 10.0, 1.0);
     
    /***** Adding message iterators ***************************************/

	rc = MB_Iterator_Create(b_data_for_government, &i_data_for_government);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'data_for_government'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'data_for_government' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'data_for_government' board is locked\n");
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
	Government_read_data_from_Eurostat();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/
	//start a reading loop

	START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
	     //CU_ASSERT_EQUAL(data_for_government_message->var, value);
	     //CU_ASSERT_DOUBLE_EQUAL(data_for_government_message->var, value, 1e-3);
	FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Government_send_account_update()
 * \brief: Unit tests for: Government_send_account_update
 * Status: NOT Tested
 */
void unittest_Government_send_account_update()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_central_bank_account_update, sizeof(m_central_bank_account_update));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'central_bank_account_update' board\n");
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

	rc = MB_Iterator_Create(b_central_bank_account_update, &i_central_bank_account_update);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'central_bank_account_update'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'central_bank_account_update' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'central_bank_account_update' board is locked\n");
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
	Government_send_account_update();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/
	//start a reading loop

	START_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
	     //CU_ASSERT_EQUAL(central_bank_account_update_message->var, value);
	     //CU_ASSERT_DOUBLE_EQUAL(central_bank_account_update_message->var, value, 1e-3);
	FINISH_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Government_set_policy()
 * \brief: Unit tests for: Government_set_policy
 * Status: NOT Tested
 */
void unittest_Government_set_policy()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: initialize message boards **********************************/

	/***** Messages: pre-conditions **********************************/
    	    
    /***** Adding message iterators ***************************************/
    
    /***** Function evaluation ***************************************/
	Government_set_policy();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Government_yearly_resetting()
 * \brief: Unit tests for: Government_yearly_resetting
 * Status: NOT Tested
 */
void unittest_Government_yearly_resetting()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Government_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: initialize message boards **********************************/

	/***** Messages: pre-conditions **********************************/
    	    
    /***** Adding message iterators ***************************************/
    	    
    /***** Function evaluation ***************************************/
	Government_yearly_resetting();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);

    /***** Variables: Message post-conditions *****/
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Government_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
