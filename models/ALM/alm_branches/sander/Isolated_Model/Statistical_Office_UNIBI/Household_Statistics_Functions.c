#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"



/************************************ Household agent functions ************************************/
/*************************************Household Role: Statistics *********************************/


int Household_receive_data()
{

return 0;

}


/** \fn Household_read_tax_rates()
 * \brief Household reads the tax_rates_messages from Governments
 */
int Household_read_tax_rates()
{

	//Message send by Government:
	START_GOVERNMENT_TAX_RATES_MESSAGE_LOOP			
		if(government_tax_rates_message->gov_id == GOV_ID)
		{
			TAX_RATE_HH_LABOUR = government_tax_rates_message->tax_rate_hh_labour;
			TAX_RATE_HH_CAPITAL = government_tax_rates_message->tax_rate_hh_capital;
		}
	FINISH_GOVERNMENT_TAX_RATES_MESSAGE_LOOP

	return 0;
}


/** \fn Household_send_data_to_Market_Research()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Household_send_data_to_Eurostat()
{	
	add_household_send_data_message(ID, REGION_ID, GENERAL_SKILL,EMPLOYEE_FIRM_ID,
	WAGE, SPECIFIC_SKILL);
		
	return 0;
}

