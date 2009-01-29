#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
//#include "../Firm_Library_Functions.h"


/************Firm Role: Credit Market Role ********************************/

/*
 * \fn: Firm_apply_for_loans()
 * \brief: This function sends a loan_request_message.
 */
int Firm_apply_for_loans()
{
	
    //add_loan_request_message(firm_id, bank_id, external_financial_needs, total_assets, total_debt);
     // add_loan_request_message(ID, BANK_ID, EXTERNAL_FINANCIAL_NEEDS, PLANNED_TOTAL_ASSETS, TOTAL_DEBT);

	add_loan_request_message(ID, BANK_ID, EXTERNAL_FINANCIAL_NEEDS,TOTAL_ASSETS, TOTAL_DEBT);
	
   return 0;
}

/*
 * \fn: Firm_read_loan_offers_send_loan_acceptance()
 * \brief: This function reads loan_conditions_messages from the bank. The firm sends out a loan_acceptance_message.
 */
int Firm_read_loan_acceptance()
{

  int bank_id, credit_id;
  double loan_value;
  double interest_rate;
  double interest_payment;
  double debt_installment_payment;
  int nr_periods_before_maturity;

	START_LOAN_ACCEPTANCE_MESSAGE_LOOP

		TOTAL_EXTERNAL_FINANCING_OBTAINED = loan_acceptance_message->credit_amount_taken;
		
            
        //Increase payment_account with the credit_amount_taken
        PAYMENT_ACCOUNT += TOTAL_EXTERNAL_FINANCING_OBTAINED;
            
        //Decrease external_financial_needs with the credit_amount_taken
        EXTERNAL_FINANCIAL_NEEDS -= TOTAL_EXTERNAL_FINANCING_OBTAINED;

		if(TOTAL_EXTERNAL_FINANCING_OBTAINED > 0.0)
		{
			//double_array LOANS              	  : dynamic array of structs with each struct a loan_item
            //struct debt_item
            //int bank_id                       : bank at which the loan was obtained
            //double loan_value                 : total value of the loan remaining
            //double interest_rate              : interest for this loan
            //double interest_payment           : interest to be paid this period
            //double debt_installment_payment   : installment payment per period
            //int nr_periods_before_maturity    : nr of periods to go before the loan has to be fully repaid

	        bank_id = loan_acceptance_message->bank_id;
	        credit_id = loan_acceptance_message-> credit_id;
	        loan_value = TOTAL_EXTERNAL_FINANCING_OBTAINED;
	        interest_rate = loan_acceptance_message->interest_rate;
           	interest_payment = interest_rate * loan_value;
           	debt_installment_payment = loan_value/PERIODS_TO_REPAY_LOANS;
           	nr_periods_before_maturity = PERIODS_TO_REPAY_LOANS+1; //Standard 4 periods to repay debt
           	
           	//printf("Firm_Credit_Function, line 68: Adding a loan\n");
            add_debt_item(&LOANS, bank_id, credit_id, loan_value, interest_rate, interest_payment, debt_installment_payment, nr_periods_before_maturity);            
		}
	    //printf("Firm_Credit_Function, line 71: LOANS.size=%d\n", LOANS.size);

	if(EXTERNAL_FINANCIAL_NEEDS > 0.0)
	{
		//printf("EXTERNAL_FINANCIAL_NEEDS==0.0\n");
	//Check if obtained financing is sufficent to satisfy financial obligations

		if(PAYMENT_ACCOUNT - FINANCIAL_LIQUIDITY_NEEDS<0.0)
		{

		
			//If true the cancel payments in the following order:
			//1. Dividends 2. Debt installment 3. taxes and interests
		
			if(PAYMENT_ACCOUNT<(TOTAL_INTEREST_PAYMENT  + TAX_PAYMENT))
			{

				//printf("CASE 1: No liquidity left\n");

				TOTAL_DIVIDEND_PAYMENT=0.0;
				TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
				TOTAL_INTEREST_PAYMENT =0.0;
				TAX_PAYMENT =0;
			}

			if(PAYMENT_ACCOUNT<(TOTAL_INTEREST_PAYMENT + TOTAL_DEBT_INSTALLMENT_PAYMENT + TAX_PAYMENT))
			{
				//printf("CASE 2: Tax and interest can be paid\n");
				TOTAL_DIVIDEND_PAYMENT=0.0;
				TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;

			}

			if(PAYMENT_ACCOUNT<(TOTAL_INTEREST_PAYMENT + TOTAL_DEBT_INSTALLMENT_PAYMENT + TAX_PAYMENT+TOTAL_DIVIDEND_PAYMENT))
			{
				//printf("CASE 3: no dividends are paid\n");
				TOTAL_DIVIDEND_PAYMENT=0.0;

			}
			//No financial resources for production left
			FINANCIAL_RESOURCES_FOR_PRODUCTION =0.0;


		}else
		{
			//printf("PAYMENT_ACCOUNT - FINANCIAL_LIQUIDITY_NEEDS==0.0\n");
			//if false then the remaining amount can be used for production	
			FINANCIAL_RESOURCES_FOR_PRODUCTION = PAYMENT_ACCOUNT - FINANCIAL_LIQUIDITY_NEEDS;	

		}


	}else
	{

	FINANCIAL_RESOURCES_FOR_PRODUCTION = PAYMENT_ACCOUNT - FINANCIAL_LIQUIDITY_NEEDS;
	//printf("EXTERNAL_FINANCIAL_NEEDS==0.0\n");

	}
	FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
	
//printf("FINANCIAL_RESOURCES_FOR_PRODUCTION  (PL_PC %f)%f\n", PLANNED_PRODUCTION_COSTS,FINANCIAL_RESOURCES_FOR_PRODUCTION);

	
    return 0;
}
