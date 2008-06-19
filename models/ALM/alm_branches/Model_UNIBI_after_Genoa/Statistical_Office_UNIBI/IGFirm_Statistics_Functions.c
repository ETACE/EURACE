#include "../header.h"
#include "../IGFirm_agent_header.h"
#include "../my_library_header.h"




/** \fn IGFirm_send_data_to_Eurostat()
 * \brief IGFirms send data to Market Research: controlling results and creating macro data
 */
int IGFirm_send_data_to_Eurostat()
{
	return 0;
}


/** \fn IGFirm_read_tax_rates()
 * \brief IGFirms reads the tax_rates_messages from Governments
 */
int IGFirm_read_tax_rates()
{
	//Message send by Government:
	START_GOVERNMENT_TAX_RATES_MESSAGE_LOOP			
		if(government_tax_rates_message->gov_id == GOV_ID)
		{
			TAX_RATE_CORPORATE = government_tax_rates_message->tax_rate_corporate;
			TAX_RATE_VAT = government_tax_rates_message->tax_rate_vat;
		}
	FINISH_GOVERNMENT_TAX_RATES_MESSAGE_LOOP

	return 0;
}


/** \fn IGFirm_receive_data()
 * \brief IGFirms receive the data messages from the Eurostat*/
int IGFirm_receive_data()
{
	return 0;
}
