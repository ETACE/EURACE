#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"


/************Firm Role: Credit Market Role ********************************/

/*
 * \fn: Firm_apply_for_loans()
 * \brief: This function sends a loan_request_message.
 */
int Firm_apply_for_loans()
{

	printf("Start Firm_apply_for_loans() \n");
    /*TESTING*/
    int bank_id=2;
    
    //add_loan_request_message(firm_id, bank_id, external_financial_needs, total_assets, total_debt);
      add_loan_request_message(ID, bank_id, EXTERNAL_FINANCIAL_NEEDS, TOTAL_ASSETS, TOTAL_DEBT);
	
	printf("End Firm_apply_for_loans()\n");
   return 0;
}

/*
 * \fn: Firm_read_loan_offers_send_loan_acceptance()
 * \brief: This function reads loan_conditions_messages from the bank. The firm sends out a loan_acceptance_message.
 */
int Firm_read_loan_offers_send_loan_acceptance()
{
	printf("Start Firm_read_loan_offers_send_loan_acceptance() \n");
	double credit_amount_taken;
    int bank_id;
    double loan_value;
    double interest_rate;
    double interest_payment;
    double debt_installment_payment;
   	int nr_periods_before_maturity;

    START_LOAN_CONDITIONS_MESSAGE_LOOP
        if(loan_conditions_message->firm_id==ID)
        {
            //loan_conditions_message(bank_id, firm_id, proposed_interest_rate, amount_credit_offer);
            //loan_conditions_message->proposed_interest_rate;
            //loan_conditions_message->amount_credit_offer;
            
            //Now send out an acceptance message: the firm always accepts the credit offered by bank 2
            //add_loan_acceptance_message(firm_id, bank_id, credit_amount_taken);
        	credit_amount_taken = loan_conditions_message->amount_credit_offer;
            add_loan_acceptance_message(ID, loan_conditions_message->bank_id, credit_amount_taken);
            
            //Increase payment_account with the credit_amount_taken
            PAYMENT_ACCOUNT += credit_amount_taken;
            
            //Decrease external_financial_needs with the credit_amount_taken
            EXTERNAL_FINANCIAL_NEEDS -= credit_amount_taken;
            
            //double_array LOANS                : dynamic array of structs with each struct a loan_item
            //struct debt_item
            //int bank_id                       : bank at which the loan was obtained
            //double loan_value                 : total value of the loan remaining
            //double interest_rate              : interest for this loan
            //double interest_payment           : interest to be paid this period
            //double debt_installment_payment   : installment payment per period
            //int nr_periods_before_maturity    : nr of periods to go before the loan has to be fully repaid

            //add_debt_item(&LOANS, bank_id, loan_value, interest_rate, interest_payment, debt_installment_payment, nr_periods_before_maturity)
            bank_id = loan_conditions_message->bank_id;
            loan_value = credit_amount_taken;
           	interest_rate = loan_conditions_message->proposed_interest_rate;
           	interest_payment = interest_rate * loan_value;
           	debt_installment_payment = loan_value/4;
           	nr_periods_before_maturity = 4; //Standard 4 periods to repay debt
           	
            add_debt_item(&LOANS, bank_id, loan_value, interest_rate, interest_payment, debt_installment_payment, nr_periods_before_maturity);            
        }
    FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
	printf("Finish Firm_read_loan_offers_send_loan_acceptance() \n");
    return 0;
}
