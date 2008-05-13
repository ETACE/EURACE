#include "header.h"
#include "Bank_agent_header.h"
#include "my_library_header.h"


int Bank_check_loan_request_message ()
{
START_LOAN_REQUEST_MESSAGE_LOOP
if (ID == loan_request_message->bank_id)
  loan_request_message_found=1;
FINISH_LOAN_REQUEST_MESSAGE_LOOP

}




int Bank_decide_credit_conditions()
{
	double e, c, d, r, i;
	double bankruptcy_prob;
	double credit_allowed;
	if (BCE_DEBT == 0) 
	{
		START_LOAN_REQUEST_MESSAGE_LOOP
		if (ID == loan_request_message->bank_id) 
		{
			e = loan_request_message->equity;
			d = loan_request_message->total_debt;
			c = loan_request_message->credit_demand;
			bankruptcy_prob = 1-exp(-(d+c)/e);
			r = bankruptcy_prob*c/e;
			if ( VAR+r <= ALFA*EQUITY ) 
			{
				credit_allowed = c;
			}
			else 
			{
				credit_allowed = (ALFA*EQUITY - VAR)/bankruptcy_prob;
			}
			i = MIN_INTEREST + OMEGA[0]*r;
			add_loan_conditions_message(loan_request_message->firm_id, ID, i, credit_allowed,  r*(c/credit_allowed));
		}
		FINISH_LOAN_REQUEST_MESSAGE_LOOP
	}
	return 0;
}


int Bank_account_update_deposits()
{
	 	
      START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
	if (ID == bank_account_update_message->bank_id) 
	{
         CASH += bank_account_update_message->payment_account;
         
	}

      FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
		
      

            if ( BCE_DEBT != 0 ) 
		{
			
                          if(CASH>=fabs(BCE_DEBT))
                          {
                                CASH-=fabs(BCE_DEBT);
                                BCE_DEBT=0.;
                          }
 
                          if(CASH<fabs(BCE_DEBT))
                          {
                               BCE_DEBT-=CASH;
                               CASH=0.;
                          }

                          add_BCE_return_message(BCE_DEBT, ID);

		}
      
	return 0;
}





/*int Bank_receive_deposits_firm()  //AGGIORNARE I NOMI!!!!
{
	double passive_interest; 
	START_DAILY_REVENUE_TO_BANK_MESSAGE_LOOP
	if (ID == daily_revenue_to_bank_message->bank_id) 
	{
         CASH += daily_revenue_to_bank_message->revenue_per_day;
      }
		

       FINISH_DAILY_REVENUE_TO_BANK_MESSAGE_LOOP
	
            if ( BCE_DEBT != 0 ) 
		{
			
                          if(CASH>=fabs(BCE_DEBT))
                          {
                                CASH-=fabs(BCE_DEBT);
                                BCE_DEBT=0.;
                          }
 
                          if(CASH<fabs(BCE_DEBT))
                          {
                               BCE_DEBT-=CASH;
                               CASH=0.;
                          }

                          add_BCE_return_message(BCE_DEBT, ID);



		}	
      
	return 0;
}
*/

/*int Bank_return_deposits()
{
	double wr, q;  
	
		START_MONEY_WITHDRAW_REQUEST_MESSAGE_LOOP
		if (ID == money_withdraw_request_message->bank_id) 
		{
			wr = money_withdraw_request_message->money_request;
                  if ( EQUITY >= 0 )
                  {
                      if ( CASH >=wr ) 
                      {
                           CASH -= wr;
                      }

                      if (CASH<wr)
                      {  
                         add_BCE_request_message(wr-CASH, ID);
                         BCE_DEBT+=wr-CASH; 
                         CASH=0;  
                      }

                   add_withdrawal_allowed_message(wr, money_withdraw_request_message->household_id);

                  }			

                  if ( EQUITY<0)
                  {
                     add_withdrawal_allowed_message(0, money_withdraw_request_message->household_id); 
                     q=fabs(EQUITY)*(1+(rand()/RAND_MAX))*10; 
                     add_BCE_request_message(q, ID); 
                     BCE_DEBT+=q; 
                  }

			
		}
		FINISH_MONEY_WITHDRAW_REQUEST_MESSAGE_LOOP
	
	return 0;
}
*/


int Bank_receive_installment()
{
	START_INSTALLMENT_MESSAGE_LOOP
	if (ID == installment_message->bank_id) 
	{
		CASH +=installment_message->installment_amount_paid;
        PROFITS.array[0] += installment_message->interest;
        EQUITY += installment_message->interest;
        VAR -= installment_message->var_per_instalment;
            
	}
	FINISH_INSTALLMENT_MESSAGE_LOOP

    START_BANKRUPTCY_MESSAGE_LOOP
   	if (ID == bankruptcy_message->bank_id)
    {
       CASH +=bankruptcy_message->credit_refunded;
       EQUITY -= bankruptcy_message->bad_debt;
       VAR -= bankruptcy_message->residual_var;
    }
    FINISH_BANKRUPTCY_MESSAGE_LOOP
	
      return 0;
}

int Bank_give_loan()
{
	START_LOAN_ACCEPTANCE_MESSAGE_LOOP
	if (ID == loan_acceptance_message->bank_id) 
	{
		CASH -= loan_acceptance_message->credit_amount_taken;
		if ( CASH < 0 ) 
		{
			BCE_DEBT += fabs(CASH);    
                  add_BCE_request_message(BCE_DEBT,ID);
			CASH = 0;
		}
	}

	FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
	return 0;
}

int Bank_accounting()
{

     double q, c, gro;   

     if (PROFIT[1]!=0)
     {
        gro=(PROFIT[0]-PROFIT[1])/PROFIT[1]);
     }

     else  
     gro=0;
  
     PROFIT[1]=PROFIT[0]; 
     PROFIT[0]=0; 
     q=OMEGA[0]; 
     c=OMEGA[1];
     OMEGA[0]=q+lambda*(q-c)*gro+(rand()/RAND_MAX)*0.01;
 
     if (OMEGA[0]<0.02)
     {
        OMEGA[0]=0.02;
     }


      return 0;
}


