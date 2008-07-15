#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"



/************************************ Household agent functions ************************************/
/*************************************Household Role: Statistics *********************************/


int Household_receive_data()
{

START_EUROSTAT_SEND_PRICE_INDEX_MESSAGE_LOOP

PRICE_INDEX = eurostat_send_price_index_message->price_index;

FINISH_EUROSTAT_SEND_PRICE_INDEX_MESSAGE_LOOP

if(DAY==41)
{
	PRICE_INDEX_BASE_PERIOD= PRICE_INDEX;
}


if(DAY<41)
{
	COMMUTING_COSTS_PRICE_LEVEL_WEIGHT = 1;
}else
{
	COMMUTING_COSTS_PRICE_LEVEL_WEIGHT = PRICE_INDEX/PRICE_INDEX_BASE_PERIOD;
	
}



	
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

