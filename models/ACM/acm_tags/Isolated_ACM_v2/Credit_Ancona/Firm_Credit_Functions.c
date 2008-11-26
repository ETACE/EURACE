#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"

#define CONST_NUMBER_OF_BANKS 10
//#define NUMBER_OF_BANKS_TO_APPLY 3
//#define PERIODS_TO_REPAY_LOANS 12



int Firm_ask_loan()
{
    if (EXTERNAL_FINANCIAL_NEEDS>0.0)
    {
	  int connected, j;

      connected=0; 

	  for (j=0;j<CONST_NUMBER_OF_BANKS;j++) 
	  {
	    	DMARKETMATRIX[j]=0;
	  } 
	
	//Create bank network for this firm
	  while(connected<NUMBER_OF_BANKS_TO_APPLY)
	  {
	        j= rand() % CONST_NUMBER_OF_BANKS ;// choose banks
            DMARKETMATRIX[j]=1;
	        add_loan_request_message(ID, j, EQUITY, TOTAL_DEBT, EXTERNAL_FINANCIAL_NEEDS);
	        connected++;	     
	  }
    }
	
   
	return 0;
}


int Firm_get_loan()
{
	int n, n1, k, i, primo;
    int bk = -1;

    int rate_order_array[CONST_NUMBER_OF_BANKS]; //constant size static array
    double interest_array[CONST_NUMBER_OF_BANKS]; //constant size static array
    double credit_offer_array[CONST_NUMBER_OF_BANKS]; //constant size static array
    double value_at_risk_array[CONST_NUMBER_OF_BANKS]; //constant size static array
    
    
    double aux;
    double credit_demand;
    double credit_accepted;
    double total_credit_taken=0;

	int bank_id;
    double loan_value;
    double interest_rate;
    double interest_amount;
    double installment_amount;
    double var_per_installment;
    double residual_var;
    double bad_debt;
    int nr_periods_before_repayment;
	
     
    for (i=0; i<CONST_NUMBER_OF_BANKS;i++)
 	{
 	    rate_order_array[i]=-1;   //vettore lunghezza number_of_banks
 	    interest_array[i]=0.0;
 	    credit_offer_array[i]=0.0; //constant size static array
    	value_at_risk_array[i]=0.0; 
 	} 

    //Read messages
    n=0;

	START_LOAN_CONDITIONS_MESSAGE_LOOP
      if (loan_conditions_message->firm_id==ID)
      {
        bk = loan_conditions_message->bank_id;
    
        interest_array[bk] = loan_conditions_message->proposed_interest_rate;   //ATTENZIONE al meno 1!!!!!
        credit_offer_array[bk] = loan_conditions_message->amount_offered_credit;
		rate_order_array[bk] = loan_conditions_message->bank_id;
		value_at_risk_array[bk] = loan_conditions_message->value_at_risk;
	
		n += 1;
	
      }
     
	FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
       
	//Sorting of the rate_order_array
    n1=0;
    
  
    //SORTING
	for(i=0;i<CONST_NUMBER_OF_BANKS-1;i++)
    {
            for(k=i+1; k<CONST_NUMBER_OF_BANKS; k++)
            {       
            	if (interest_array[i]>interest_array[k]) 
            	{
			     aux=interest_array[i];
	 			 interest_array[i]=interest_array[k];
	 			 interest_array[k]=aux;
	 			 n1=rate_order_array[i];
	 			 rate_order_array[i]=rate_order_array[k];
	 			 rate_order_array[k]=n1;
                }
                
            }
    }
    
   
	
	//Travers the banks according to the order in the rate_order_array,
	//check if bank in DMARKETMATRIX==1
	//obtain a loan if credit_demand >= credit_offer
	
	
	
	for(primo=0; primo<CONST_NUMBER_OF_BANKS; primo++)
	{
              
	    if (rate_order_array[primo]!=-1)// && interest_array[primo]!=0.0)
	     {
	     	credit_demand = EXTERNAL_FINANCIAL_NEEDS - total_credit_taken;
	        
            if (credit_demand >= credit_offer_array[rate_order_array[primo]])
	        {
	           credit_accepted = credit_offer_array[rate_order_array[primo]];
	     
	        }
	        
            if (credit_demand < credit_offer_array[rate_order_array[primo]])
	        {
                              credit_accepted=credit_demand;
            }
	        
	        
	        total_credit_taken += credit_accepted;        		    
		    bank_id = rate_order_array[primo];
		    loan_value = credit_accepted;
		    interest_rate = interest_array[primo];
		    installment_amount = credit_accepted/CONST_INSTALLMENT_PERIODS;
		    interest_amount=interest_rate*installment_amount;
	
		    
            if (credit_accepted>0.0)
		    {
                var_per_installment = value_at_risk_array[rate_order_array[primo]]*(credit_offer_array[rate_order_array[primo]]/credit_accepted);//RESIDUAL_VAR[rate_order_array[primo]].value[CONST_INSTALLMENT_PERIODS-1]/CONST_INSTALLMENT_PERIODS; //rate_order_array[primo]][CONST_INSTALLMENT_PERIODS-1]/CONST_INSTALLMENT_PERIODS;
            }
            else var_per_installment=0.0;
            
            residual_var =var_per_installment*CONST_INSTALLMENT_PERIODS;// value_at_risk_array[rate_order_array[primo]]*(credit_offer_array[rate_order_array[primo]]/credit_accepted);
		    bad_debt = 0.0;
		    nr_periods_before_repayment=CONST_INSTALLMENT_PERIODS;
	    	//ADD LOAN
            if (credit_accepted>0.0)
		    add_debt_item(&LOANS, bank_id, loan_value, interest_rate, installment_amount, var_per_installment, residual_var, bad_debt, nr_periods_before_repayment);
		 
		 
		 if (credit_accepted>0.0)
		 {
		    add_loan_acceptance_message(bank_id, credit_accepted, residual_var);
	 
         }
		    //update the payment_account with the amount of credit obtained
		    PAYMENT_ACCOUNT += credit_accepted;
	
	     }
		        
	}
	
	if (PAYMENT_ACCOUNT >= TOTAL_FINANCIAL_NEEDS)
        {        	
            //printf("Firm_financial_needs, External financing: case 1.");
            EXTERNAL_FINANCIAL_NEEDS = 0.0;                   
        }
        else
        {
        	//external financing needed
        	EXTERNAL_FINANCIAL_NEEDS = TOTAL_FINANCIAL_NEEDS - PAYMENT_ACCOUNT;
        }
	
	
	return 0;
}

int Firm_not_in_bankruptcy()
{return 0;
}

int Firm_idle()
{
	return 0;
}

