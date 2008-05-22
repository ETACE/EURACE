#include "header.h"
#include "Bank_agent_header.h"
#include "my_library_header.h"

int Bank_decide_credit_conditions()
{
	double e, c, d, r, i;
	double bankruptcy_prob;
	double credit_allowed;
	if (BCE_DEBT == 0) 
	{
		START_LOAN_REQUEST_MESSAGE_LOOP
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
		FINISH_LOAN_REQUEST_MESSAGE_LOOP
	}
	return 0;
}


int Bank_account_update_deposits()
{
	 	
      START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
         CASH += bank_account_update_message->payment_account;
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

int Bank_receive_installment()
{
	START_INSTALLMENT_MESSAGE_LOOP

		CASH +=installment_message->installment_amount_paid;
        PROFITS[0] += installment_message->interest;
        EQUITY += installment_message->interest;
        VAR -= installment_message->var_per_instalment;

	FINISH_INSTALLMENT_MESSAGE_LOOP

    START_BANKRUPTCY_MESSAGE_LOOP

       CASH +=bankruptcy_message->credit_refunded;
       EQUITY -= bankruptcy_message->bad_debt;
       PROFITS[0] -= bankruptcy_message->bad_debt;
       VAR -= bankruptcy_message->residual_var;

    FINISH_BANKRUPTCY_MESSAGE_LOOP
	
      return 0;
}

int Bank_give_loan()
{
	START_LOAN_ACCEPTANCE_MESSAGE_LOOP

		CASH -= loan_acceptance_message->credit_amount_taken;
		if ( CASH < 0 ) 
		{
			BCE_DEBT += fabs(CASH);    
                  add_BCE_request_message(BCE_DEBT,ID);
			CASH = 0;
		}

	FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
	return 0;
}

int Bank_accounting()
{

     double q, c, gro, tax_bank, total_dividends, dividend_per_share;   

     if (PROFIT[1]!=0)
     {
        gro=(PROFIT[0]-PROFIT[1])/PROFIT[1]);
     }

     else  
     gro=0;
 
     PROFIT[1]=PROFIT[0]; //update
     q=OMEGA[0]; 
     c=OMEGA[1];
     OMEGA[0]=q+lambda*(q-c)*gro+(rand()/RAND_MAX)*0.01;
 
     if (OMEGA[0]<0.02)
     {
         OMEGA[0]=0.02;
     }

     // tax and dividends payment
     if (PROFIT[0]>0)
     {
         tax_bank = TAX_RATE_CORPORATE*PROFIT[0];
         PROFIT[0] -= tax_bank;
         EQUITY -= tax_bank;
         CASH -= tax_bank;
         add_tax_payment_message(ID, GOV_ID, tax_bank);  
         total_dividends = DIVIDEND_RATE*PROFIT[0];
         dividend_per_share = total_dividends/NUMBER_OF_SHARES; 
         PROFIT[0] -= total_dividends;
         EQUITY -= total_dividends;
         CASH -= total_dividends;
         add_dividend_per_share_message(ID, dividend_per_share);                  
     }
 
     if (CASH < 0) //if money is not enough, increase BCE debt
     {
         BCE_DEBT -= CASH;
         CASH = 0;
     }
     
     PROFIT[0]=0;  //update

      return 0;
}
