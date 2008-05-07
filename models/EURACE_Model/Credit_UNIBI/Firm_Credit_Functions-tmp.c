#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"


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
            
            //D_LOAN = 100*(rand()/RAND_MAX);  /* generate random credit demand */
            
            //add_loan_request_message(firm_id, bank_id, equity, total_debt, credit_demand);
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
	      
      for (i=0; i<NUMBER_OF_BANKS;i++)
 	{
 	    RATEORDER.array[i]=-1;   //vettore lunghezza number_of_banks
 	} 
      
    
	START_LOAN_CONDITIONS_MESSAGE_LOOP
	//loan_conditions_message(firm_id, bank_id, proposed_interest_rate, amount_offered_credit, value_at_risk);
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
            credit_accepted = EXTERNAL_FINANCIAL_NEEDS;
            if (credit_accepted>=CREDIT_OFFER.array[RATEORDER.array[primo]])
            {
               credit_accepted=CREDIT_OFFER.array[RATEORDER.array[primo]];
            }
            EXTERNAL_FINANCIAL_NEEDS -= credit_accepted;
            interest = credit_accepted*INTEREST.array[RATEORDER.array[primo]];
            
            //This still needs to be merged with FinMan Code
            OUTSTANDING_DEBT.array[RATEORDER.array[primo]][INSTALLMENT_NUMBER-1] = credit_accepted+interest;		          
            INSTALLMENT_AMOUNT.array[RATEORDER.array[primo]][INSTALLMENT_NUMBER-1] = (credit_accepted+interest)/INSTALLMENT_NUMBER;
            INTEREST_AMOUNT.array[RATEORDER.array[primo]][INSTALLMENT_NUMBER-1] = interest/INSTALLMENT_NUMBER;
            RESIDUAL_VAR.array[RATEORDER.array[primo]][INSTALLMENT_NUMBER-1] = VALUE_AT_RISK.array[RATEORDER.array[primo]]*(CREDIT_OFFER.array[RATEORDER.array[primo]]/credit_accepted);
            VAR_PER_INSTALLMENT.array[RATEORDER.array[primo]][INSTALLMENT_NUMBER-1] =RESIDUAL_VAR.array[RATEORDER.array[primo]][INSTALLMENT_NUMBER-1]/INSTALLMENT_NUMBER;

            //add_loan_acceptance_message(firm_id, bank_id, credit_amount_taken);
            add_loan_acceptance_message(ID, RATEORDER.array[primo], credit_accepted);
         }
      }


      return 0;
}

//Sander: This function needs to be reviewed and merged into FinMan code
int Firm_pay_interest_installment()
{
	double bad_debt, credit_refunded;
	int i, j, k;
	double total_installments = 0;
	double individual_var;
	double individual_debt;
	
      TOTAL_DEBT=0;

	for ( i = 0; i < NUMBER_OF_BANKS; i++ ) 
	{
            for (j=0; j<INSTALLMENT_NUMBER; j++)
            {
                total_installments+=(INSTALLMENT_AMOUNT.array[i][j]+INTEREST_AMOUNT.array[i][j]);
                TOTAL_DEBT += OUTSTANDING_DEBT.array[i][j];
            }

	}


	if ( TOTAL_RESOURCES >= total_installments ) 
	{
		for ( i = 0; i < NUMBER_OF_BANKS; i++ ) 
            {
                for (j=0; j<INSTALLMENT_NUMBER; j++)
                {
			  c = INSTALLMENT_AMOUNT.array[i][j];
			  r = INTEREST_AMOUNT.array[i][j];
			  v = VAR_PER_INSTALLMENT.array[i][j];
			  TOTAL_RESOURCES -= (c+r);
			  OUTSTANDING_DEBT.array[i][j] -= c;
			  INTEREST_LEFT.array[i] -= r;
			  RESIDUAL_VAR.array[i] -= v;
			  EQUITY -= r; //Sander: was ASSET -=r
			  bad_debt=0; 
			  credit_refunded=0; 
              individual_var=0; 
                    
              
             //add_installment_message(c, r, i, v, bad, a, individual_var);      
             //add_installment_message(bank_id, installment_amount_paid, interest, var_per_installment, bad_debt, credit_refunded, residual_var);
              add_installment_message(bank_id, INSTALLMENT_AMOUNT.array[i][j], INTEREST_AMOUNT.array[i][j], VAR_PER_INSTALLMENT.array[i][j], bad_debt, credit_refunded, individual_var);
		    }

	          for (k=1; k<INSTALLMENT_NUMBER; k++)//sposta di un periodo
                {       
                    OUTSTANDING_DEBT.array[i][k-1]=OUTSTANDING_DEBT.array[i][k]; 
                    VAR_PER_INSTALLMENT.array[i][k-1]=VAR_PER_INSTALLMENT.array[i][k]; 
                    INTEREST_AMOUNT.array[i][k-1]=INTEREST_AMOUNT.array[i][k];
                }
            }
      }				
			

	else 
	{
		for ( i = 0; i < NUMBER_OF_BANKS; i++ )
            {
                for (j=0; j<INSTALLMENT_NUMBER; j++)
                {
                	individual_debt+=OUTSTANDING_DEBT.array[i][j];
                    individual_var+=VAR_PER_INSTALLMENT.array[i][j];
                    a=EQUITY*(individual_debt/TOTAL_DEBT); //Sander: was ASSET
                    bad_debt=individual_debt-a;
                    c=0;
                    r=0;
                    v=0;
                    
                    //add_installment_message(c, r, i, v, bad, a, individual_var);      
                    //add_installment_message(bank_id, installment_amount_paid, interest, var_per_installment, bad_debt, credit_refunded, residual_var);
                     add_installment_message(bank_id, INSTALLMENT_AMOUNT.array[i][j], INTEREST_AMOUNT.array[i][j], VAR_PER_INSTALLMENT.array[i][j], bad_debt, credit_refunded, individual_var);

                    individual_debt=0;
                    individual_var=0;                 
                }
            }
	 	
		//Sander: why do we need these lines?
            EQUITY=0;	
            TOTAL_DEBT=0;
	}

	return 0;
}


