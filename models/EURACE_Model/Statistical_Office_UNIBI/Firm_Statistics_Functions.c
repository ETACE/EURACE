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

