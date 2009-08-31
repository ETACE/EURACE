#include "../header.h"
#include "../IGFirm_agent_header.h"
#include "../my_library_header.h"


/** \fn Firm_send_data_to_Eurostat()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int IGFirm_send_data_to_Eurostat()
{


	//Increase the age of the firm in months
	AGE++;
	
	add_firm_send_data_message(ID, REGION_ID, VACANCIES, NO_EMPLOYEES,
		NO_EMPLOYEES_SKILL_1, NO_EMPLOYEES_SKILL_2, NO_EMPLOYEES_SKILL_3, 	
		NO_EMPLOYEES_SKILL_4,NO_EMPLOYEES_SKILL_5, 		MEAN_WAGE, MEAN_SPECIFIC_SKILLS,
		AVERAGE_S_SKILL_OF_1, AVERAGE_S_SKILL_OF_2, AVERAGE_S_SKILL_OF_3, AVERAGE_S_SKILL_OF_4, 
		AVERAGE_S_SKILL_OF_5,
		0, 0,	0, 0, 0,0, 0, 0, 0, 0, 0, 0,0, 0,0);

	//printf("In Firm_send_data: Firm %d OUTPUT: %.2f\n", ID, OUTPUT);
	//printf("In Firm_send_data: Firm %d PLANNED_OUTPUT: %.2f\n", ID, PLANNED_OUTPUT);

	return 0;
}


int IGFirm_send_payments_to_bank()
{
	
	/*add_bank_account_update_message(ID, BANK_ID, PAYMENT_ACCOUNT);
	if(PAYMENT_ACCOUNT<0)
		printf("PAYMENT_ACCOUNT of Firm %d:  %f \n",ID,PAYMENT_ACCOUNT);*/
	
	return 0;
}



/** \fn IGFirm_read_policy_announcements()
 * \brief IGFirms reads the policy_announcement_messages from Governments
 */
int IGFirm_read_policy_announcements()
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

	return 0;
}


/** \fn Firm_receive_data()
 * \brief Firms receive the data messages from the Eurostat*/
int IGFirm_receive_data()
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
					
//printf("IGFIRM: eurostat_send_specific_skills_message->productivity_progress %f \n",eurostat_send_specific_skills_message->productivity_progress);

					/*if(eurostat_send_specific_skills_message->productivity_progress > 0)
					{
						int i;
						for(i = 0; i< EMPLOYEES.size; i++)
						{				
							EMPLOYEES.array[i].wage = EMPLOYEES.array[i].wage*(1+ 	
							eurostat_send_specific_skills_message->productivity_progress);
						}
		
						for(i = 0; i< RESEARCH_EMPLOYEES.size; i++)
						{				
							RESEARCH_EMPLOYEES.array[i].wage = RESEARCH_EMPLOYEES.array[i].wage*(1+ 
							eurostat_send_specific_skills_message->productivity_progress);
							
							WAGE_OFFER_FOR_RD = WAGE_OFFER_FOR_RD
							*(1+0.5*eurostat_send_specific_skills_message->productivity_progress);
						}
					}*/		
				}
			
		}
		FINISH_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
		
		return 0;
}

