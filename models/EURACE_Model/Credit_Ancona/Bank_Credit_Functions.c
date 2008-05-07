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
			e = loan_request_message->current_equity;
			d = loan_request_message->current_debt;
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
			add_loan_conditions_message(i, credit_allowed, loan_request_message->firm_id, ID, r*(c/credit_allowed));
		}
		FINISH_LOAN_REQUEST_MESSAGE_LOOP
	}
	return 0;
}

int Bank_receive_deposits()
{
	double passive_interest; 
	START_HOUSEHOLD_DEPOSIT_MESSAGE_LOOP
	if (ID == household_deposit_message->bank_id) 
	{
         CASH += household_deposit_message->money_deposited;

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

       FINISH_HOUSEHOLD_DEPOSIT_MESSAGE_LOOP
		
      
	return 0;
}

int Bank_return_deposits()
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

int Bank_receive_dividend_payment()
{
	START_TOTAL_DIVIDEND_MESSAGE_LOOP
	if (ID == total_dividend_message->bank_id) 
	{
		//update the bank account of firm:
		//total_dividend_message->firm_id
		//bank decreases bank account with:
		//total_dividend_message->total_dividend_payment
	}	
	FINISH_TOTAL_DIVIDEND_MESSAGE_LOOP
		
	return 0;
}
	
		
int Bank_receive_instalment()
{
	START_INSTALMENT_MESSAGE_LOOP
	if (ID == instalment_message->bank_id) 
	{
		CASH +=instalment_message->instalment_amount;
            CASH +=instalment_message->credit_refunded;
            PROFITS[0] += instalment_message->interest;
            PROFITS[0] -= instalment_message->bad_debt;
            EQUITY += instalment_message->interest;
            EQUITY -= instalment_message->bad_debt;
            VAR -= instalment_message->var_per_instalment;
            VAR -= instalment_message->residual_var;
	}
	
      FINISH_INSTALMENT_MESSAGE_LOOP
	
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

int Bank_bank_accounting()
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


