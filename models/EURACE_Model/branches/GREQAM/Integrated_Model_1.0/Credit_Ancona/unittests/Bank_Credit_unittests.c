#include <CUnit/Basic.h>
#include "../../header.h"
#include "../../Bank_agent_header.h"
//#include "my_library_header.h"

/************Bank Role: Credit Market********************************/

/************ Unit tests ********************************/

	void unittest_Bank_decide_credit_conditions()
	{
//	    /************* At start of unit test, add one agent **************/
		//add_Bank_agent_internal(init_Bank_agent(), init_Bank_state());
		//current_xmachine = *p_xmachine;
		int rc;
		unittest_init_Bank_agent();
//
//		/***** Variables: Memory pre-conditions **************************/
//		<var_name1>=0.0;
//		<var_name2>=0;
        ID = 1;
        BCE_DEBT = 0;
        VALUE_AT_RISK = 10;
        EQUITY = 30;
        MIN_INTEREST = 2;
        BANK_GAMMA[0] = 0.05;
        BANK_GAMMA[1] = 0.06;

        rc = MB_Create(&b_loan_request, sizeof(m_loan_request));
        	    #ifdef ERRCHECK
        	    if (rc != MB_SUCCESS)
        	    {
        	       fprintf(stderr, "ERROR: Could not create 'loan_request' board\n");
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

//
//      /***** Messages: pre-conditions **********************************/
		add_loan_request_message(50,10,5,2,1);
//
		    
		rc = MB_Iterator_CreateFiltered(b_loan_request, &i_loan_request, &Bank_Bank_decide_credit_conditions_loan_request_filter, current_xmachine_Bank);
				
		if (rc != MB_SUCCESS)
				{
				   fprintf(stderr, "ERROR: Could not create Iterator for 'loan_request'\n");
				   switch(rc) {
				       case MB_ERR_INVALID:
				           fprintf(stderr, "\t reason: 'loan_request' board is invalid\n");
				           break;
				       case MB_ERR_LOCKED:
			               fprintf(stderr, "\t reason: 'loan_request' board is locked\n");
			               break;
			           case MB_ERR_MEMALLOC:
			               fprintf(stderr, "\t reason: out of memory\n");
			               break;
			           case MB_ERR_INTERNAL:
			               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			               break;
				   }
				}
				
//	    /***** Function evaluation ***************************************/
        Bank_decide_credit_conditions();
//	    
//	    /***** Variables: Memory post-conditions *************************/
//		CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//		CU_ASSERT_EQUAL(<var_name2>, <value>);
//		
//     /***** Messages: post-conditions **********************************/
	 	START_LOAN_CONDITIONS_MESSAGE_LOOP
	    	CU_ASSERT_DOUBLE_EQUAL(loan_conditions_message->amount_offered_credit, 1.2959, 1e-5);
//	 		CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
		FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
//	
//	    /************* At end of unit test, free the agent **************/
	    //free_agent();
		unittest_free_Bank_agent();
//     /************* At end of unit tests, free all Messages **********/
	    free_messages();
	}
