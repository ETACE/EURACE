#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"

/** \fn Firm_send_data_to_Eurostat()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Firm_send_data_to_Eurostat()
{

	/*Determine the productivity of the firm. It is the minimum of TECHNOLOGY and MEAN-SPECIFIC-SKILLS
	Calculates the productivity progress and sends it to eurostat*/
	if(DAY%20 == 0)
	{

		FIRM_PRODUCTIVITY_LAST_YEAR = FIRM_PRODUCTIVITY;

		if(MEAN_SPECIFIC_SKILLS >= TECHNOLOGY)
		{
			FIRM_PRODUCTIVITY = TECHNOLOGY;
		}
		else
		{
			FIRM_PRODUCTIVITY = MEAN_SPECIFIC_SKILLS;
		}


		FIRM_PRODUCTIVITY_PROGRESS = FIRM_PRODUCTIVITY/FIRM_PRODUCTIVITY_LAST_YEAR -1;

	}

	//Increase the age of the firm in months
	AGE++;
	
	add_firm_send_data_message(ID, REGION_ID, VACANCIES, NO_EMPLOYEES,
		NO_EMPLOYEES_SKILL_1, NO_EMPLOYEES_SKILL_2, NO_EMPLOYEES_SKILL_3, 	
		NO_EMPLOYEES_SKILL_4,NO_EMPLOYEES_SKILL_5, 		MEAN_WAGE, MEAN_SPECIFIC_SKILLS,
		AVERAGE_S_SKILL_OF_1, AVERAGE_S_SKILL_OF_2, AVERAGE_S_SKILL_OF_3, AVERAGE_S_SKILL_OF_4, 
		AVERAGE_S_SKILL_OF_5,
		CUM_REVENUE, CAPITAL_COSTS,	NET_EARNINGS, TOTAL_DEBT, TOTAL_ASSETS, EQUITY,
		PRICE, PRICE_LAST_MONTH, TOTAL_SUPPLY, CUM_TOTAL_SOLD_QUANTITY, OUTPUT, PLANNED_OUTPUT, 
		AGE,FIRM_PRODUCTIVITY_PROGRESS, FIRM_PRODUCTIVITY);

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

/** \fn Firm_read_policy_announcements()
 * \brief Firms reads the policy_announcements from Governments
 */
int Firm_read_policy_announcements()
{

	//Message send by Government:
	START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP			
		//Filter: 
		if(policy_announcement_message->gov_id == GOV_ID)
		{
			TAX_RATE_CORPORATE = policy_announcement_message->tax_rate_corporate;
			TAX_RATE_VAT = policy_announcement_message->tax_rate_vat;
			TRANSFER_PAYMENT = policy_announcement_message->firm_transfer_payment;
			SUBSIDY_PAYMENT = policy_announcement_message->firm_subsidy_payment;
		}
	FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP



	/*int i;
	for(i=0; i<EMPLOYEES.size;i++)
	{
	EMPLOYEES.array[i].wage=EMPLOYEES.array[i].wage*1.01;
	
	}
WAGE_OFFER*=1.01;
WAGE_OFFER_FOR_SKILL_1*=1.01;
WAGE_OFFER_FOR_SKILL_2*=1.01;
WAGE_OFFER_FOR_SKILL_3*=1.01;
WAGE_OFFER_FOR_SKILL_4*=1.01;
WAGE_OFFER_FOR_SKILL_5*=1.01;*/
	
	return 0;
}

/** \fn Firm_send_subsidy_notification()
 * \brief This function sends a message to the government in case the Firm applies for a subsidy. 
 */
int Firm_send_subsidy_notification()
{
	/*Add subsidy message */
	add_firm_subsidy_notification_message(GOV_ID);
	PAYMENT_ACCOUNT += SUBSIDY_PAYMENT;
		
	return 0;		
}

/** \fn Firm_send_transfer_notification()
 * \brief This function sends a message to the government in case the Firm applies for a transfer. 
 */
int Firm_send_transfer_notification()
{
	/*Add transfer message */
	add_firm_transfer_notification_message(GOV_ID);
	PAYMENT_ACCOUNT += TRANSFER_PAYMENT;
		
	return 0;		
}

/** \fn Firm_receive_data()
 * \brief Firms receive the data messages from the Eurostat*/
int Firm_receive_data()
{

				
	/* If day of month to act... */
	
		
	START_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
		
		/*Specific skills of the domestic region*/
		//Filter: 
		if(eurostat_send_specific_skills_message->region_id == REGION_ID)
		{
			/*If there is no employee with general skill level 1 resp. 2-5*/
			
			
				AVERAGE_S_SKILL_OF_1 = 	eurostat_send_specific_skills_message->
				specific_skill_1;
			

			
			
				AVERAGE_S_SKILL_OF_2 = 	eurostat_send_specific_skills_message->
				specific_skill_2;
			

			
				AVERAGE_S_SKILL_OF_3 = 	eurostat_send_specific_skills_message->
				specific_skill_3;
			

			
			
				AVERAGE_S_SKILL_OF_4 = 	eurostat_send_specific_skills_message->
				specific_skill_4;
			

			
			
				AVERAGE_S_SKILL_OF_5 = 	eurostat_send_specific_skills_message->
				specific_skill_5;

				/*Updates wage_offer and wages regarding the productivity progress*/
				if(DAY%20 == 1)
				{
					if(ID <= 2)
						printf("eurostat_send_specific_skills_message->productivity_progress %f \n",eurostat_send_specific_skills_message->productivity_progress);

					if(eurostat_send_specific_skills_message->productivity_progress > 0)
					{
						//WAGE_OFFER = WAGE_OFFER*(1+ 
						//eurostat_send_specific_skills_message->productivity_progress);
		
						int i;
						for(i = 0; i< EMPLOYEES.size; i++)
						{				
							EMPLOYEES.array[i].wage = EMPLOYEES.array[i].wage*(1+ 	
							eurostat_send_specific_skills_message->productivity_progress);
						}
					}		
				}
			
		}
		FINISH_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
		
		return 0;
}
