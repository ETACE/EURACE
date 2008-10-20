#include "../header.h"
#include "../IGFirm_agent_header.h"
#include "../my_library_header.h"


/** \fn IGFirm_read_tax_rates()
 * \brief IGFirms reads the tax_rates_messages from Governments
 */
int IGFirm_read_tax_rates()
{
	//Message send by Government:
	START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP			
		if(policy_announcement_message->gov_id == GOV_ID)
		{
			TAX_RATE_CORPORATE = policy_announcement_message->tax_rate_corporate;
			TAX_RATE_VAT = policy_announcement_message->tax_rate_vat;
			TRANSFER_PAYMENT = policy_announcement_message->transfer_payment;
			SUBSIDY_PAYMENT = policy_announcement_message->subsidy_payment;
		}
	FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP

	return 0;
}
