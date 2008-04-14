#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
#include "../Firm_Library_Functions.h"


/************Firm Role: Credit Market Role ********************************/

/*
 * \fn: Firm_apply_for_loans()
 * \brief: This function sends a loan_request_message.
 */
int Firm_apply_for_loans()
{
    /*TESTING*/
    int bank_id=2;
    
    //add_loan_request_message(firm_id, bank_id, external_financial_needs, total_assets, total_debt, MSGDATA);
      add_loan_request_message(ID, bank_id, EXTERNAL_FINANCIAL_NEEDS, TOTAL_ASSETS, TOTAL_DEBT, MSGDATA);

   return 0;
}

/*
 * \fn: Firm_read_loan_offers_send_loan_acceptance()
 * \brief: This function reads loan_conditions_messages from the bank. The firm sends out a loan_acceptance_message.
 */
int Firm_read_loan_offers_send_loan_acceptance()
{
	double credit_amount_taken;
	
    START_LOAN_CONDITIONS_MESSAGE_LOOP
        if(loan_conditions_message->firm_id==ID)
        {
            //loan_conditions_message(bank_id, firm_id, proposed_interest_rate, amount_credit_offer, MSGDATA);
            //loan_conditions_message->proposed_interest_rate;
            //loan_conditions_message->amount_credit_offer;
            
            //Now send out an acceptance message: the firm always accepts the credit offered by bank 2
            //add_loan_acceptance_message(firm_id, bank_id, credit_amount_taken, MSGDATA);
        	credit_amount_taken = loan_conditions_message->amount_credit_offer;
            add_loan_acceptance_message(ID, loan_conditions_message->bank_id, credit_amount_taken, MSGDATA);
            
            PAYMENT_ACCOUNT += credit_amount_taken;
        }
    FINISH_LOAN_CONDITIONS_MESSAGE_LOOP

    return 0;
}

