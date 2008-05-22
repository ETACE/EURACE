#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"

#define NUMBER_OF_BANKS 10

int Firm_ask_loan()
{
	int i, connected, j;
	
      connected=0; 

	for (j=0; j< NUMBER_OF_BANKS; j++) 
	{
	    DMARKETMATRIX.array[j]=0;
	} 
	
      while (connected<LINK)
      {

            j=(int)((rand()/RAND_MAX)*NUMBER_OF_BANKS);// choose 'LINK' banks
            DMARKETMATRIX.array[j]=1;
            
            //old code: generate random credit demand 
            //D_LOAN = 100*(rand()/RAND_MAX);
            
            add_loan_request_message(ID, j, EQUITY, TOTAL_DEBT, EXTERNAL_FINANCIAL_NEEDS);
            connected+=1;
      }  
      
	return 0;
}

int Firm_get_loan()
{
	int n, n1, k, i, j, primo;
    int bk = -1;
	double interest, aux;
	double totalcredit_taken=0;

	int bank_id;
    double loan_value;
    double interest_rate;
    double installment_amount;
    double var_per_installment;
    double residual_var;
    double bad_debt;
    int nr_periods_before_repayment;
	
      for (i=0; i<NUMBER_OF_BANKS;i++)
 	{
 	    RATEORDER.array[i]=-1;   //vettore lunghezza number_of_banks
 	} 

	START_LOAN_CONDITIONS_MESSAGE_LOOP
	if (ID == loan_conditions_message->firm_id) 
	{
        bk = loan_conditions_message->bank_id;
        INTEREST.array[bk] = loan_conditions_message->proposed_interest_rate;
		CREDIT_OFFER.array[bk] = loan_conditions_message->amount_offered_credit;
		RATEORDER.array[bk] = loan_conditions_message->bank_id;
		VALUE_AT_RISK.array[bk] = loan_conditions_message->value_at_risk;
		n += 1;
	}
	FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
       
    n1=0;

	for(i=0;i<NUMBER_OF_BANKS-1;i++)
    {
            for(k=i+1; k<NUMBER_OF_BANKS; k++)
            {
            	if (INTEREST.array[i]>INTEREST.array[k]) 
            	{
			     aux=INTEREST.array[i];
	 			 INTEREST.array[i]=INTEREST.array[k];
	 			 INTEREST.array[k]=aux;
	 			 n1=RATEORDER.array[i];
	 			 RATEORDER.array[i]=RATEORDER.array[k];
	 			 RATEORDER.array[k]=n1;
                }
            }
    }
	
	  for(primo=0; primo<NUMBER_OF_BANKS; primo++)
	  {
	     if (DMARKETMATRIX.array[RATEORDER.array[primo]]==1)
	     {
	        credit_accepted = D_LOAN - totalcredit_taken;
	        if (credit_accepted>=CREDIT_OFFER.array[RATEORDER.array[primo]])
	        {
	           credit_accepted=CREDIT_OFFER.array[RATEORDER.array[primo]];
	        }
	
	        totalcredit_taken += credit_accepted;
	        interest = credit_accepted*INTEREST.array[RATEORDER.array[primo]];
	        
		    bank_id = RATEORDER.array[primo];
		    loan_value = credit_accepted;
		    interest_rate = INTEREST.array[RATEORDER.array[primo]];
		    installment_amount = (credit_accepted+interest)/INSTALMENT_NUMBER;
		    var_per_installment = RESIDUAL_VAR.array[RATEORDER.array[primo]][INSTALMENT_NUMBER-1]/INSTALMENT_NUMBER;
		    residual_var = VALUE_AT_RISK.array[RATEORDER.array[primo]]*(CREDIT_OFFER.array[RATEORDER.array[primo]]/credit_accepted);
		    bad_debt = 0.0;
		    nr_periods_before_repayment=INSTALMENT_NUMBER;
		    	
		    add_debt_item(&LOANS, bank_id, loan_value, interest_rate, installment_amount, var_per_installment, residual_var, bad_debt, nr_periods_before_repayment);
		    add_loan_acceptance_message(bank_id, credit_accepted);
		
		    //update the payment_account with the amount of credit obtained
		    PAYMENT_ACCOUNT += credit_accepted;
	     }
	}

	  return 0;
}
