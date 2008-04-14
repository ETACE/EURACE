#include "../header.h"
#include "../Bank_agent_header.h"
#include "../my_library_header.h"


/************Bank Role: Credit market********************************/

int Bank_read_loan_request_send_offers()
{
	START_LOAN_REQUEST_MESSAGE_LOOP
		if(loan_request_message->bank_id==ID)
		{
			//Set offer equal to demanded credit:
			AMOUNT_CREDIT_OFFER=loan_request_message->credit_amount;
			
			//Send loan conditions: the bank always accepts the loan request
		    //add_loan_conditions_message(bank_id, firm_id, proposed_interest_rate, amount_credit_offer, MSGDATA);
			add_loan_conditions_message(ID, loan_request_message->firm_id, PROPOSED_INTEREST_RATE, loan_request_message->credit_amount, MSGDATA);
		}
	FINISH_LOAN_REQUEST_MESSAGE_LOOP
	
	return 0;
}

int Bank_read_loan_acceptance()
{
	START_LOAN_ACCEPTANCE_MESSAGE_LOOP
		if(loan_acceptance_message->bank_id==ID)
		{
			//Update the firm's bankaccount with the demanded credit:
			ACCOUNT[loan_acceptance_message->firm_id]=loan_acceptance_message->credit_taken;
		}
	FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
	
	return 0;
}

int Bank_read_interest_payments()
{
	int firm_id;
	
	START_INTEREST_PAYMENT_MESSAGE_LOOP
		if(interest_payment_message->bank_id==ID)
		{
			//update the firm's bank account
			//firm_id = interest_payment_message->firm_id;
			//ACCOUNT[firm_id] -= interest_payment_message->interest_payment;
		}
	FINISH_INTEREST_PAYMENT_MESSAGE_LOOP
	
	return 0;
}

int Bank_read_debt_installment_payments()
{
	int firm_id;
	
	START_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
		if(debt_installment_payment_message->bank_id==ID)
		{
			//update the firm's bank account
			//firm_id = debt_installment_payment_message->firm_id;
			//ACCOUNT[firm_id] -= debt_installment_payment_message->debt_installment_payment;
		}
	FINISH_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
	
	return 0;
}