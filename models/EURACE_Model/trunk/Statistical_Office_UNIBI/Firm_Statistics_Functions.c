/** \fn Firm_send_data_to_Eurostat()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Firm_send_data_to_Eurostat()
{
	
	add_firm_send_data_message(ID, REGION_ID, VACANCIES, 
	NO_EMPLOYEES, NO_EMPLOYEES_SKILL_1, 
	NO_EMPLOYEES_SKILL_2, NO_EMPLOYEES_SKILL_3, NO_EMPLOYEES_SKILL_4,
	NO_EMPLOYEES_SKILL_5, 
	MEAN_WAGE, MEAN_SPECIFIC_SKILLS, AVERAGE_S_SKILL_OF_1, 
	AVERAGE_S_SKILL_OF_2, AVERAGE_S_SKILL_OF_3,
	AVERAGE_S_SKILL_OF_4, AVERAGE_S_SKILL_OF_5);
		

	return 0;
}

int Firm_send_payments_to_bank()
{
	add_bank_account_update_message(PAYMENT_ACCOUNT);
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
