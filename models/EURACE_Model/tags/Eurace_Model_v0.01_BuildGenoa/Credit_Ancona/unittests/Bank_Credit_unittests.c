#include <CUnit/Basic.h>
#include "header.h"
#include "../Bank_agent_header.h"
//#include "my_library_header.h"

/************Bank Role: Credit Market********************************/

/************ Unit tests ********************************/

	void unittest_Bank_decide_credit_conditions()
	{
//	    /************* At start of unit test, add one agent **************/
		add_Bank_agent_internal(init_Bank_agent(), init_Bank_state());
		//current_xmachine = *p_xmachine;
//
//		/***** Variables: Memory pre-conditions **************************/
//		<var_name1>=0.0;
//		<var_name2>=0;
        ID = 1;
        BCE_DEBT = 0;
        VAR = 10;
        EQUITY = 30;
        MIN_INTEREST = 2;
        OMEGA.array[0] = 0.05;
        OMEGA.array[1] = 0.06;


//
//      /***** Messages: pre-conditions **********************************/
		add_loan_request_message(50,10,5,2,1);
//
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
	    free_agent();
//     /************* At end of unit tests, free all Messages **********/
	    free_messages();
	}
