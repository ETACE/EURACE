#include "../header.h"
#include "../Central_Bank_agent_header.h"
#include "../my_library_header.h"


/************Central_Bank Role: Finance********************************/


int Central_Bank_read_account_update()
{
	int gov_id;

	START_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
	
		gov_id = account_update_message->id;
		gov_accounts[gov_id]+= central_bank_account_update_message->payment_account;
	
	FINISH_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
	return 0;
}
