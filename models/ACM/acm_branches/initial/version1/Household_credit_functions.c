#include "header.h"
#include "Household_agent_header.h"
#include "my_library_header.h"



int Household_put_money()
{
	double deposit = rand()/((double)RAND_MAX+1);  /* generate random deposit */
	TOTAL_DEPOSIT = deposit;
	add_household_deposit_message(deposit, BANK_ACCOUNT, ID);

	return 0;
}

int Household_choose_bank()
{
	BANK_ACCOUNT = rand()%NUMBER_OF_BANKS;
	return 0;
}
int Household_withdraw()
{
	double w; 
	START_WITHDRAWAL_ALLOWED_MESSAGE_LOOP
	if (ID == withdrawal_allowed_message->household_id) 
	{
		w = withdrawal_allowed_message->withdrawal_allowed;
		TOTAL_DEPOSIT -= w;
	}
	FINISH_WITHDRAWAL_ALLOWED_MESSAGE_LOOP
	return 0;
}

int Household_withdraw_request()
{
	double withdraw= rand()/((double)RAND_MAX+1);  /* generate random deposit */
	if ( withdraw > TOTAL_DEPOSIT) 
	withdraw = TOTAL_DEPOSIT;
	add_money_withdraw_request_message(withdraw, BANK_ACCOUNT, ID);

	return 0;
}

