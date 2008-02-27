#include <CUnit/Basic.h>

#include "header.h"
#include "Bank_agent_header.h"
#include "my_library_header.h"

/************Bank Role: Financial Management Role ********************************/

/************ Unit tests ********************************/

void unittest_Bank_read_loan_request_send_offers()
{
    /************* At start of unit test, add one agent **************/
	add_Bank_agent(.......);

	/***** Variables: Memory pre-conditions **************************/
	<var_name1>=0.0;
	<var_name2>=0;
	
    /***** Function evaluation ***************************************/
	Bank_read_loan_request_send_offers();
    
    /***** Variables: Memory post-conditions *************************/
	CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
	CU_ASSERT_EQUAL(<var_name2>, <value>);
	
    /***** Messages send *********************************************/
	START_LOAN_REQUEST_MESSAGE_LOOP
		if(loan_request_message->bank_id==ID)
		{
			//Send loan conditions: the bank always accepts the loan request
		    //add_loan_conditions_message(bank_id, firm_id, proposed_interest_rate, amount_credit_offer, MSGDATA);
	 		CU_ASSERT_EQUAL(loan_conditions_message->bank_id, <value>);
	 		CU_ASSERT_EQUAL(loan_conditions_message->firm_id, <value>);
	    	CU_ASSERT_DOUBLE_EQUAL(loan_conditions_message->proposed_interest_rate, <value>, 1e-3);
	 		CU_ASSERT_DOUBLE_EQUAL(loan_conditions_message->amount_credit_offer, <value>, 1e-3);
		}
	FINISH_LOAN_CONDITIONS_MESSAGE_LOOP

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}