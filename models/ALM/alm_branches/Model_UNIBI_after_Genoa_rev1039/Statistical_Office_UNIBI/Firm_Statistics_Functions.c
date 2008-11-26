#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"

int Firm_update_general_skills()
{

if(CHANGE_IN_SKILL_DISTRIBUTION == 1)
{
START_GENERAL_SKILL_UPDATE_MESSAGE_LOOP
for(int i=0; i < EMPLOYEES.size;i++)
{

if(EMPLOYEES.array[i].id==general_skill_update_message->id)
{
EMPLOYEES.array[i].general_skill = general_skill_update_message->general_skills;
break;
}



}


FINISH_GENERAL_SKILL_UPDATE_MESSAGE_LOOP

NO_EMPLOYEES_SKILL_1= 0;
NO_EMPLOYEES_SKILL_2= 0;
NO_EMPLOYEES_SKILL_3= 0;
NO_EMPLOYEES_SKILL_4= 0;
NO_EMPLOYEES_SKILL_5= 0;

for(int i=0; i < EMPLOYEES.size;i++)
{
if(EMPLOYEES.array[i].general_skill==1)
NO_EMPLOYEES_SKILL_1++;
if(EMPLOYEES.array[i].general_skill==2)
NO_EMPLOYEES_SKILL_2++;
if(EMPLOYEES.array[i].general_skill==3)
NO_EMPLOYEES_SKILL_3++;
if(EMPLOYEES.array[i].general_skill==4)
NO_EMPLOYEES_SKILL_4++;
if(EMPLOYEES.array[i].general_skill==5)
NO_EMPLOYEES_SKILL_5++;
}

}
return 0;
}

/** \fn Firm_send_data_to_Eurostat()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Firm_send_data_to_Eurostat()
{
	//Increase the age of the firm in months
	AGE++;
	
	add_firm_send_data_message(ID, REGION_ID, VACANCIES, NO_EMPLOYEES,
	NO_EMPLOYEES_SKILL_1, NO_EMPLOYEES_SKILL_2, NO_EMPLOYEES_SKILL_3, NO_EMPLOYEES_SKILL_4,	NO_EMPLOYEES_SKILL_5, 
	MEAN_WAGE, MEAN_SPECIFIC_SKILLS,
	AVERAGE_S_SKILL_OF_1, AVERAGE_S_SKILL_OF_2, AVERAGE_S_SKILL_OF_3, AVERAGE_S_SKILL_OF_4, AVERAGE_S_SKILL_OF_5,
	CUM_REVENUE, CAPITAL_COSTS,CAPITAL_COSTS/ACTUAL_CAP_PRICE,	NET_EARNINGS, TOTAL_DEBT, TOTAL_ASSETS, EQUITY,
	PRICE,TOTAL_SUPPLY,CUM_TOTAL_SOLD_QUANTITY, OUTPUT, PLANNED_OUTPUT,REAL_EXPORTS,NOMINAL_EXPORTS);

	//printf("In Firm_send_data: Firm %d OUTPUT: %.2f\n", ID, OUTPUT);
	//printf("In Firm_send_data: Firm %d PLANNED_OUTPUT: %.2f\n", ID, PLANNED_OUTPUT);

	return 0;
}

int Firm_send_payments_to_bank()
{
	
	add_bank_account_update_message(ID, BANK_ID, PAYMENT_ACCOUNT);
	if(PAYMENT_ACCOUNT<0)
		printf("PAYMENT_ACCOUNT of Firm %d:  %f \n",ID,PAYMENT_ACCOUNT);
	
	return 0;
}

/** \fn Firm_read_tax_rates()
 * \brief Firms reads the tax_rates_messages from Governments
 */
int Firm_read_tax_rates()
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

/** \fn Firm_receive_data()
 * \brief Firms receive the data messages from the Eurostat*/
int Firm_receive_data()
{

				
	/* If day of month to act... */
	
		
	START_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
		
		/*Specific skills of the domestic region*/
		if(eurostat_send_specific_skills_message->region_id == REGION_ID)
		{
			/*If there is no employee with general skill level 1 resp. 2-5*/
			if(NO_EMPLOYEES_SKILL_1 == 0)
			{
				AVERAGE_S_SKILL_OF_1 = 						eurostat_send_specific_skills_message->
				specific_skill_1;
			}

			if(NO_EMPLOYEES_SKILL_2 == 0)
			{
				AVERAGE_S_SKILL_OF_2 = 						eurostat_send_specific_skills_message->
				specific_skill_2;
			}

			if(NO_EMPLOYEES_SKILL_3 == 0)
			{
				AVERAGE_S_SKILL_OF_3 = 						eurostat_send_specific_skills_message->
				specific_skill_3;
			}

			if(NO_EMPLOYEES_SKILL_4 == 0)
			{
				AVERAGE_S_SKILL_OF_4 = 						eurostat_send_specific_skills_message->
				specific_skill_4;
			}

			if(NO_EMPLOYEES_SKILL_5 == 0)
			{
				AVERAGE_S_SKILL_OF_5 = 						eurostat_send_specific_skills_message->
				specific_skill_5;
			}
		}
		FINISH_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
		
		return 0;
}
