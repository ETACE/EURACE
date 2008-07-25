#include "../header.h"
#include "../Bank_agent_header.h"
#include "../my_library_header.h"

int Bank_decide_credit_conditions()
{
	double e, c, d, r, i;
	double bankruptcy_prob;
	double credit_allowed;
	
	
//	for(int j=0;j<2;j++)
//	printf("\n gamma values %d, %f", ID, BANK_GAMMA[j]);
	if(BCE_DEBT==0.0) 
	{
	
	//	loan_request_message=get_first_loan_request_message();         WHAT DOES IT MEAN????
		//printf(" lending bank %f \n", loan_request_message);
		//while(loan_request_message)
	//	{
		//	printf("\n abc");
		//	loan_request_message=get_next_loan_request_message(loan_request_message);
	//	}
		
		START_LOAN_REQUEST_MESSAGE_LOOP
	    	e = loan_request_message->equity;
			d = loan_request_message->total_debt;
			c = loan_request_message->external_financial_needs;
			bankruptcy_prob = 1-exp(-(d+c)/e);
			r = bankruptcy_prob*c/e;
		//	printf("\n bankruptcy %f, r %f", bankruptcy_prob, r );
			if ( VALUE_AT_RISK+r <= ALFA*EQUITY ) 
			{
				credit_allowed = c;
				//printf("value at risk %f \n",credit_allowed);
			}
			else 
			{
				credit_allowed = (ALFA*EQUITY - VALUE_AT_RISK)/bankruptcy_prob;
				//printf(" chi sfora %d var %f  \n",ID, VALUE_AT_RISK+r ;
			}
			i = MIN_INTEREST + BANK_GAMMA[0]*r*(((double)rand()/(double)RAND_MAX)*0.01);//VALUTARE IL RUMORE
		//	printf(" interesse proposto %f, bank %d firm %d \n", i, ID, loan_request_message->firm_id);
		//	printf("\n bank adding loan message ");
			add_loan_conditions_message(loan_request_message->firm_id, ID, i, credit_allowed,  r*(c/credit_allowed));
		FINISH_LOAN_REQUEST_MESSAGE_LOOP
	}
	
	return 0;
}


int Bank_account_update_deposits()
{
	 	
      START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
      if (bank_account_update_message->bank_id==ID)
        {
         CASH += bank_account_update_message->payment_account;  //CHECK DUMMY!!!!
        }
      FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP

      if ( BCE_DEBT != 0 ) 
		{
			
             if(CASH>=fabs(BCE_DEBT))
             {
                 CASH-=fabs(BCE_DEBT);
                 BCE_DEBT=0.0;
             }
 
             if(CASH<fabs(BCE_DEBT))
             {
                 BCE_DEBT-=CASH;
                 CASH=0.0;
             }

             // add_central_bank_account_update_message(BCE_DEBT, ID);
		//	printf("\n %d cash %f, bce_debt %f", ID,CASH,BCE_DEBT);
		}
      
	return 0;
}

int Bank_receive_installment()
{
	//printf("\n %d cash %f before , equity %f", ID,CASH, EQUITY);
	START_INSTALLMENT_MESSAGE_LOOP
		if(installment_message->bank_id==ID)
		{
		//	printf("my msg");
		CASH +=installment_message->installment_amount;
        PROFITS[0] += installment_message->interest_amount;
        TOTAL_CREDIT-=installment_message->installment_amount;//printf("%d - profits ****** %f\n", ID, PROFITS[0]);
        EQUITY += installment_message->interest_amount;
      //  printf("bank %d equity %f int.amount %f\n", ID, EQUITY, installment_message->interest_amount);
        VALUE_AT_RISK -= installment_message->var_per_installment;
        //printf("%d cash %f after, equity %f\n", ID,CASH, EQUITY);
		}

	FINISH_INSTALLMENT_MESSAGE_LOOP

    START_BANKRUPTCY_MESSAGE_LOOP
		if(bankruptcy_message->bank_id==ID)
		{
		//	printf("bankrupt my msg");
       CASH +=bankruptcy_message->credit_refunded;
       EQUITY -= bankruptcy_message->bad_debt;
       TOTAL_CREDIT-=(bankruptcy_message->credit_refunded+bankruptcy_message->bad_debt);
       PROFITS[0] -= bankruptcy_message->bad_debt;
       VALUE_AT_RISK -= bankruptcy_message->residual_var;
		}

    FINISH_BANKRUPTCY_MESSAGE_LOOP
 /*   if(ID==5)
    {
	printf("\n %d cash %f, equity %f", ID,CASH, EQUITY);
	for(int i=0;i<2;i++)
		printf("\n--> %f", PROFITS[i]);
    }
    */
   // if (TOTAL_CREDIT<0.0)
    //printf("errore total credit negativo ++++*********** \n");
    
    
      return 0;
}

int Bank_give_loan()
{
	
	START_LOAN_ACCEPTANCE_MESSAGE_LOOP
		if(loan_acceptance_message->bank_id==ID)
		{
			CASH -= loan_acceptance_message->credit_amount_taken;
			VALUE_AT_RISK+=loan_acceptance_message->loan_total_var;
            TOTAL_CREDIT+=loan_acceptance_message->credit_amount_taken;           
        //    printf("bank %d total credit %f  \n", ID, TOTAL_CREDIT);
			if (CASH<0.0) 
			{
				BCE_DEBT += fabs(CASH);  
              // printf("bank %d debito BCE %f CASH %f \n", ID, BCE_DEBT, CASH);   
                //  add_central_bank_account_update_message(BCE_DEBT,ID);
				CASH = 0.0;
			}
		}

	FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
	
	
	return 0;
}

int Bank_accounting()
{

     double q, c, gro, tax_bank, total_dividends, dividend_per_share;   

     if (PROFITS[1]!=0)
     {
        gro=( (PROFITS[0]-PROFITS[1])/PROFITS[1] );
     }

     else  
     gro=0;
 
     PROFITS[1]=PROFITS[0]; //update
     q=BANK_GAMMA[0]; 
     c=BANK_GAMMA[1];
     BANK_GAMMA[1]=	q;
     BANK_GAMMA[0]=(q+(BANK_LAMBDA*(q-c)*gro)+(((double)rand()/(double)RAND_MAX)*0.01));
 
     if (BANK_GAMMA[0]<0.02)
     {
         BANK_GAMMA[0]=0.02;
     }

     // tax and dividends payment
     if (PROFITS[0]>0)
     {
        // printf("profitti %f \n", PROFITS[0]);             
         tax_bank = TAX_RATE_CORPORATE*PROFITS[0]; 
         PROFITS[0] -= tax_bank;
         EQUITY -= tax_bank;  
         CASH -= tax_bank; 
         add_tax_payment_message(ID, GOV_ID, tax_bank);  
         total_dividends = BANK_DIVIDEND_RATE*PROFITS[0];  
         dividend_per_share = total_dividends/NUMBER_OF_SHARES; 
        // printf("total_dividend %f tax bank %f \n", total_dividends, tax_bank);
        // PROFITS[0] -= total_dividends;
         EQUITY -= total_dividends;     
         CASH -= total_dividends;      
         add_dividend_per_share_message(ID, dividend_per_share);                  
     }
 
     if (CASH < 0) //if money is not enough, increase BCE debt
     {
         BCE_DEBT -= CASH;
         CASH = 0.0;
     }
    
    // printf("bank %d equity %f cash %f bce %f \n", ID, EQUITY, CASH, BCE_DEBT);
     PROFITS[0]=0;  //update
     
	
      return 0;
}

int Bank_idle()
{
	return 0;
}


