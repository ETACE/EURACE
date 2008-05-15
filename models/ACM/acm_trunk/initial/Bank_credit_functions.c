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
		if (ID == loan_request_message->bank_id) 
		{
			e = loan_request_message->current_equity;
			d = loan_request_message->current_debt;
			c = loan_request_message->credit_demand;
			bankruptcy_prob = 1-exp(-(d+c)/e);
			r = bankruptcy_prob*c;
			if ( VAR+r <= ALFA*EQUITY ) 
			{
				credit_allowed = c;
			}
			else 
			{
				credit_allowed = (ALFA*EQUITY - VAR)/bankruptcy_prob;
			}
			i = MIN_INTEREST + GAMMA[0]*r;
			
			//add_loan_conditions_message(interest_rate, credit_allowed, firm_id, ID, r*(c/credit_allowed));
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
		if ( BCE_DEBT == 0 ) 
		{
			CASH += household_deposit_message->money_deposited;
		}
		else 
		{
			passive_interest = household_deposit_message->money_deposited*pow(MIN_INTEREST, DEBT_PERIOD);
			if ( BCE_DEBT > household_deposit_message->money_deposited- passive_interest) 
			{
				BCE_DEBT -= household_deposit_message->money_deposited;
				PROFITS[0] -= passive_interest;
			}
			else 
			{
				CASH += (household_deposit_message->money_deposited - passive_interest) - BCE_DEBT;
				PROFITS[0] -= BCE_DEBT*pow(MIN_INTEREST, DEBT_PERIOD);
				BCE_DEBT = 0;
			}
		}
	}
	FINISH_HOUSEHOLD_DEPOSIT_MESSAGE_LOOP
	
	return 0;
}

int Bank_return_deposits()
{
	double wr; 
	if ( BCE_DEBT == 0 ) 
	{
		START_MONEY_WITHDRAW_REQUEST_MESSAGE_LOOP
		if (ID == money_withdraw_request_message->bank_id) 
		{
			wr = money_withdraw_request_message->money_withdraw_request;
			CASH -= wr;
			if ( CASH < 0 ) 
			{
				/*    BCE_INTEREST += -CASH*min_interest;  */
				BCE_DEBT += -CASH;    /*  *(1+min_interest);  */
				DEBT_PERIOD = 1;
				CASH = 0;
			}
			add_withdrawal_allowed_message(wr, money_withdraw_request_message->household_id);
		}
		FINISH_MONEY_WITHDRAW_REQUEST_MESSAGE_LOOP
	}
	return 0;
}

int Bank_receive_installment()
{
	START_INSTALLMENT_MESSAGE_LOOP
	if (ID == installment_message->bank_id) 
	{
		CASH +=installment_message->installment;
		PROFITS[0] += installment_message->interest;
		EQUITY += installment_message->interest;
		VAR -= installment_message->var_per_installment;
	}
	FINISH_INSTALLMENT_MESSAGE_LOOP
	//next message
	START_BANKRUPTCY_MESSAGE_LOOP
	if (ID == bankruptcy_message->bank_id) 
	{
		CASH +=bankruptcy_message->credit_refunded;
		PROFITS[0] -= bankruptcy_message->bad_debt;
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
			/*    BCE_INTEREST += -CASH*min_interest;  */
			BCE_DEBT += -CASH;    /*  *(1+min_interest);  */
			DEBT_PERIOD = 1;
			CASH = 0;
		}
	}
	FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
	return 0;
}
