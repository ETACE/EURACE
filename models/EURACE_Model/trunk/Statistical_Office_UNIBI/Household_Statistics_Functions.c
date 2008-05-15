#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"



/************************************ Household agent functions ************************************/
/*************************************Household Role: Statistics *********************************/

/** \fn Household_receive_data()
 * \brief Household receives data messages from Eurostat*/
int Household_receive_data()
{
	//Message send by Government:
		START_GOVERNMENT_TAX_RATES_MESSAGE_LOOP			
			if(government_tax_rates_message->gov_id == GOV_ID)
			{
				TAX_RATE_CORPORATE = government_tax_rates_message->tax_rate_corporate;
				TAX_RATE_HH_LABOUR = government_tax_rates_message->tax_rate_hh_labour;
				TAX_RATE_HH_CAPITAL = government_tax_rates_message->tax_rate_hh_capital;
				TAX_RATE_VAT = government_tax_rates_message->tax_rate_vat;
			}
		FINISH_GOVERNMENT_TAX_RATES_MESSAGE_LOOP


		return 0;
}
