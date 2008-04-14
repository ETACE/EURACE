#include "../header.h"
#include "../Government_agent_header.h"
#include "../my_library_header.h"


/************Government Role: Finance********************************/

int Government_read_tax_payment()
{
	START_TAX_PAYMENT_MESSAGE_LOOP
		if(tax_payment->gov_id==ID)
		{
			//PROCESS TAX PAYMENT	
		}
	FINISH_TAX_PAYMENT_MESSAGE_LOOP
	
	return 0;
}