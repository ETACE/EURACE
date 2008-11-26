#include "../header.h"
#include "../Central_Bank_agent_header.h"
#include "../my_library_header.h"



/************Central_Bank Role: manage accounts for Governments and commercial banks********************************/

int Central_Bank_read_account_update()
{
	int id;

	START_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
	
		id = central_bank_account_update_message->id;
		CB_ACCOUNTS[id] += central_bank_account_update_message->payment_account;
	
	FINISH_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
	return 0;
}
