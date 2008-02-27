#include "header.h"
#include "Bank_agent_header.h"
#include "my_library_header.h"
#include "math.h"

/************Bank Role: Credit market********************************/

int Bank_read_loan_request_send_offers()
{
	START_LOAN_REQUEST_MESSAGE_LOOP
		if(loan_request_message->bank_id==ID)
		{
			//Send loan conditions: the bank always accepts the loan request
		    //add_loan_conditions_message(bank_id, firm_id, proposed_interest_rate, amount_credit_offer, MSGDATA);
			add_loan_conditions_message(ID, loan_request_message->firm_id, 0.01, loan_request_message->credit_amount, MSGDATA);
		}
	FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
	
	return 0;
}