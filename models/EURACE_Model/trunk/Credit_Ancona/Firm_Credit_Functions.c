#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"

#define CONST_NUMBER_OF_BANKS 10
#define NUMBER_OF_BANKS_TO_APPLY 3
#define CONST_INSTALLMENT_PERIODS 12
#define LINK 3


int Firm_ask_loan()
{
	int i, connected, j;

    connected=0; 

    //This line not needed: we fill the array anyway...
	for (j=0; j< NUMBER_OF_BANKS_TO_APPLY; j++) 
	{
		DMARKETMATRIX[j]=0;
	} 
	
	//Create bank network for this firm
	while (connected<LINK)
	{
	      j=(int)((rand()/RAND_MAX)*CONST_NUMBER_OF_BANKS);// choose 'LINK' banks
	      DMARKETMATRIX[j]=1;
	                    
	      add_loan_request_message(ID, j, EQUITY, TOTAL_DEBT, EXTERNAL_FINANCIAL_NEEDS);
	      connected+=1;
	}  
      
	return 0;
}

int Firm_get_loan()
{
	int n, n1, k, i, j, primo;
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
    double installment_amount;
    double var_per_installment;
    double residual_var;
    double bad_debt;
    int nr_periods_before_repayment;
	
    //This is not needed, we fill the array anyway, so why need to set it to -1? 
    for (i=0; i<NUMBER_OF_BANKS_TO_APPLY;i++)
 	{
 	    rate_order_array[i]=-1;   //vettore lunghezza number_of_banks
 	} 

    //Read messages
    n=0;
	START_LOAN_CONDITIONS_MESSAGE_LOOP

        bk = loan_conditions_message->bank_id;
        interest_array[bk] = loan_conditions_message->proposed_interest_rate;
		credit_offer_array[bk] = loan_conditions_message->amount_offered_credit;
		rate_order_array[bk] = loan_conditions_message->bank_id;
		value_at_risk_array[bk] = loan_conditions_message->value_at_risk;
		n += 1;

	FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
       
	//Sorting of the rate_order_array
    n1=0;
	for(i=0;i<NUMBER_OF_BANKS_TO_APPLY-1;i++)
    {
            for(k=i+1; k<NUMBER_OF_BANKS_TO_APPLY; k++)
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
	for(primo=0; primo<NUMBER_OF_BANKS_TO_APPLY; primo++)
	{
		//Why is there this check ? Is not each bank in rate_order_array also in DMARKETMATRIX?
	     if (DMARKETMATRIX[rate_order_array[primo]]==1)
	     {
	        credit_demand = EXTERNAL_FINANCIAL_NEEDS - total_credit_taken;
	        if (credit_demand >= credit_offer_array[rate_order_array[primo]])
	        {
	           credit_accepted = credit_offer_array[rate_order_array[primo]];
	        }
	
	        total_credit_taken += credit_accepted;
	        		    
		    bank_id = rate_order_array[primo];
		    loan_value = credit_accepted;
		    interest_rate = interest_array[rate_order_array[primo]];
		    installment_amount = credit_accepted/CONST_INSTALLMENT_PERIODS;
		    var_per_installment = RESIDUAL_VAR[rate_order_array[primo]].value[CONST_INSTALLMENT_PERIODS-1]/CONST_INSTALLMENT_PERIODS; //rate_order_array[primo]][CONST_INSTALLMENT_PERIODS-1]/CONST_INSTALLMENT_PERIODS;
		    
		    residual_var = value_at_risk_array[rate_order_array[primo]]*(credit_offer_array[rate_order_array[primo]]/credit_accepted);
		    bad_debt = 0.0;
		    nr_periods_before_repayment=CONST_INSTALLMENT_PERIODS;
		    	
		    add_debt_item(&LOANS, bank_id, loan_value, interest_rate, installment_amount, var_per_installment, residual_var, bad_debt, nr_periods_before_repayment);
		    add_loan_acceptance_message(bank_id, credit_accepted);
		
		    //update the payment_account with the amount of credit obtained
		    PAYMENT_ACCOUNT += credit_accepted;
	     }
	}

	return 0;
}

