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
	        j= rand() % CONST_NUMBER_OF_BANKS ;// choose 'LINK' banks
	      //printf("j %d \n", j);
            DMARKETMATRIX[j]=1;
	        add_loan_request_message(ID, j, EQUITY, TOTAL_DEBT, EXTERNAL_FINANCIAL_NEEDS);
	        connected++;	     
	  }
    }
	

	/*if(ID==2)
	{
    //printf("second%d %f", ID,PRODUCTION_COSTS);
	//printf("\n dmatriricx ");
	for(int i=0;i<10;i++)
	{
		printf("%d ", DMARKETMATRIX[i]);
	}  
    printf("\n");
    } 
    */   
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
	//printf("\n //////////// 4payment account %f extrenalfinances need %f",PAYMENT_ACCOUNT, EXTERNAL_FINANCIAL_NEEDS);
     
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
       // printf("\n bank %d \n", bk);
        interest_array[bk] = loan_conditions_message->proposed_interest_rate;   //ATTENZIONE al meno 1!!!!!
        credit_offer_array[bk] = loan_conditions_message->amount_offered_credit;
		rate_order_array[bk] = loan_conditions_message->bank_id;
		value_at_risk_array[bk] = loan_conditions_message->value_at_risk;
		//printf("msg %f %d \n",interest_array[bk],rate_order_array[bk] );
		n += 1;
		//printf("\nReceive loan ...............");
      }
     
	FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
       
	//Sorting of the rate_order_array
    n1=0;
    
  /*  if(ID==2)
    {
  // 	printf("/BeforePrintfing for %d ", ID);
    
    for(int j=0;j<CONST_NUMBER_OF_BANKS;j++)
    {
    //	printf("\n %d, %f,%f ,%f", rate_order_array[j], interest_array[j], credit_offer_array[j], value_at_risk_array[j]); //constant size static array
 
    }
    }
    */
    
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
    
   // for(i=0;i<CONST_NUMBER_OF_BANKS;i++)
    //{
   //    printf(" interesse proposto %f, firm %d bank %d \n", interest_array[i], ID, rate_order_array[i]);
   // }
   
   /* 
    if(ID==2)
    {
 //   printf("Printfing for %d ", ID);
    
    for(int j=0;j<CONST_NUMBER_OF_BANKS;j++)
    {
    //	printf("\n %d, %f,%f ,%f", rate_order_array[j], interest_array[j], credit_offer_array[j], value_at_risk_array[j]); //constant size static array
 
    }
    }
	*/
	
	//Travers the banks according to the order in the rate_order_array,
	//check if bank in DMARKETMATRIX==1
	//obtain a loan if credit_demand >= credit_offer
	
	
	
	for(primo=0; primo<CONST_NUMBER_OF_BANKS; primo++)
	{
            //DMARKETMATRIX[rate_order_array[primo]]==1     
	    if (rate_order_array[primo]!=-1)// && interest_array[primo]!=0.0)
	     {
	     	credit_demand = EXTERNAL_FINANCIAL_NEEDS - total_credit_taken;
	        
            if (credit_demand >= credit_offer_array[rate_order_array[primo]])
	        {
	           credit_accepted = credit_offer_array[rate_order_array[primo]];
	           //printf(" firm %d bank %d credit accepted %f \n", ID, rate_order_array[primo], credit_accepted);
	        }
	        
            if (credit_demand < credit_offer_array[rate_order_array[primo]])
	        {
                              credit_accepted=credit_demand;
            }
	        
	     //   printf("\n************* %f", credit_accepted);
	        
	        total_credit_taken += credit_accepted;
	        		    
		    bank_id = rate_order_array[primo];
		    loan_value = credit_accepted;
		    interest_rate = interest_array[primo];
		    
		    installment_amount = credit_accepted/CONST_INSTALLMENT_PERIODS;
		    interest_amount=interest_rate*installment_amount;
		//    printf("interest amount %f int %f inst %f \n", interest_amount, interest_rate, installment_amount);
		    
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
	//	     printf("firm %d bank %d credito %f var %f \n", ID, bank_id, credit_accepted, var_per_installment); 
         }
		    //update the payment_account with the amount of credit obtained
		    PAYMENT_ACCOUNT += credit_accepted;
		 //  printf("\n %d payment account %f", ID, PAYMENT_ACCOUNT);
	     }
	    // else 
	    // printf("\n NO");
	    //if (ID==2)
	    //printf(" firm %d %d bank %d \n", ID, DMARKETMATRIX[rate_order_array[primo]], rate_order_array[primo]);
	        
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
	
	
	
	//if(ID==2)
	//printf("fourth");
//	printf("\n  4payment account %f extrenalfinances need %f",PAYMENT_ACCOUNT, EXTERNAL_FINANCIAL_NEEDS);
	return 0;
}
/*
int Firm_not_in_bankruptcy()
{return 0;
}

int Firm_idle()
{
	return 0;
}
*/
