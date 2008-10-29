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
	START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP			
		if(policy_announcement_message->gov_id == GOV_ID)
		{
			TAX_RATE_HH_LABOUR = policy_announcement_message->tax_rate_hh_labour;
			TAX_RATE_HH_CAPITAL = policy_announcement_message->tax_rate_hh_capital;
			UNEMPLOYMENT_BENEFIT_PCT =  policy_announcement_message->unemployment_benefit_pct;
			TRANSFER_PAYMENT = policy_announcement_message->transfer_payment;
			SUBSIDY_PAYMENT = policy_announcement_message->subsidy_payment;
		}
	FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP

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

