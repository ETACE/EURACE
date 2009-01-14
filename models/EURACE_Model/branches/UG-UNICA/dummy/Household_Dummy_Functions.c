#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"

int Household_labour_good_market_dummy() {
	
	/* aggiornare il payment account, inviare il bank_account_update alla banca	*/
	
	CONSUMPTION_BUDGET = 0;
	
    add_bank_account_update_message(ID, BANK_ID, PAYMENT_ACCOUNT);
    
    return 0;
	
}

