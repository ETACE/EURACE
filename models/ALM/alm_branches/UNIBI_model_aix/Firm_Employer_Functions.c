#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"



/************************************ Firm agent functions ************************************/

/* Function condition functions */

int day_of_month_to_act()
{
	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT) return 1;
	else return 0;
}

int not_day_of_month_to_act()
{
	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT) return 0;
	else return 1;
}

int same_workers()
{
	if(NO_EMPLOYEES == EMPLOYEES_NEEDED) return 1;
	else return 0;
}

int less_workers_needed()
{
	if(NO_EMPLOYEES > EMPLOYEES_NEEDED) return 1;
	else return 0;
}

int more_workers_needed()
{
	if(NO_EMPLOYEES < EMPLOYEES_NEEDED) return 1;
	else return 0;
}




int Firm_finish_labour_market_first_round()
{
	return 0;
}


int Firm_start_labour_market()
{
	return 0;
}


int Firm_idle()
{
	return 0;
}



/*************************************Firm Role: Labour Market*********************************/

/** \fn Firm_receive_data()
 * \brief Firms receive the data messages from the Market Research*/
int Firm_receive_data()
{
					
	/* If day of month to act... */
	
		
	START_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
		
		/*Specific skills of the domestic region*/
		if(market_research_send_specific_skills_message->region_id == REGION_ID)
		{
			/*If there is no employee with general skill level 1 resp. 2-5*/
			if(NO_EMPLOYEES_SKILL_1 == 0)
			{
				AVERAGE_S_SKILL_OF_1 = 						market_research_send_specific_skills_message->
				specific_skill_1;
			}

			if(NO_EMPLOYEES_SKILL_2 == 0)
			{
				AVERAGE_S_SKILL_OF_2 = 						market_research_send_specific_skills_message->
				specific_skill_2;
			}

			if(NO_EMPLOYEES_SKILL_3 == 0)
			{
				AVERAGE_S_SKILL_OF_3 = 						market_research_send_specific_skills_message->
				specific_skill_3;
			}

			if(NO_EMPLOYEES_SKILL_4 == 0)
			{
				AVERAGE_S_SKILL_OF_4 = 						market_research_send_specific_skills_message->
				specific_skill_4;
			}

			if(NO_EMPLOYEES_SKILL_5 == 0)
			{
				AVERAGE_S_SKILL_OF_5 = 						market_research_send_specific_skills_message->
				specific_skill_5;
			}
		}

		FINISH_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP

		return 0;

}

/** \fn Firm_calculate_specific_skills_and_wage_offer()
 * \brief Firms calculate the specific skills for each general skill group 
 * and the according wage offer*/
int Firm_calculate_specific_skills_and_wage_offer()
{
	
	/*Sum up the specific skills of each general skill group (1-5): for average*/
	double sum_1 = 0;
	double sum_2 = 0;
	double sum_3 = 0;
	double sum_4 = 0;
	double sum_5 = 0;
	
	/*For every employee*/
	for(int n = 0; n < EMPLOYEES.size; n++)
	{
		/*general skill levels 1-5*/
		switch(EMPLOYEES.array[n].general_skill)
		{
		case 1:/*If employee has general skill level 1 add specific skill to sum1*/
			sum_1 = sum_1 + EMPLOYEES.array[n].specific_skill;
			break;

		case 2:
			sum_2 = sum_2 + EMPLOYEES.array[n].specific_skill;
			break;

		case 3:
			sum_3 = sum_3 + EMPLOYEES.array[n].specific_skill;
			break;

		case 4:
			sum_4 = sum_4 + EMPLOYEES.array[n].specific_skill;
			break;

		case 5:/*If employee has general skill level 5 add specific skill to sum5*/
			sum_5 = sum_5 + EMPLOYEES.array[n].specific_skill;
			break;
		}
	}

	/*for each general skill group: calculate the average specific skills*/
	for(int m = 1; m < 6;m++)
	{
		switch(m)
		{
		/*If skill level 1*/
		case 1:
			/*If there are employees with general skill level 1*/
			if(NO_EMPLOYEES_SKILL_1 > 0)
			{	
				/*Calculate average specific skill of skill group 1*/
				AVERAGE_S_SKILL_OF_1 = sum_1/NO_EMPLOYEES_SKILL_1;
			}
			
			/*Skill Group 1 gets the basic wage offer*/
			WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER;
			break;
		
		case 2:
			if(NO_EMPLOYEES_SKILL_2 > 0)
			{
				AVERAGE_S_SKILL_OF_2 = sum_2/NO_EMPLOYEES_SKILL_2;	
			}
			
			/*The other skill groups get a higher wage offer depending on the 					productivity (specific skill)*/
			WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER*AVERAGE_S_SKILL_OF_2/
				AVERAGE_S_SKILL_OF_1;
			break;

		case 3:
			if(NO_EMPLOYEES_SKILL_3 > 0)
			{
				AVERAGE_S_SKILL_OF_3 = sum_3/NO_EMPLOYEES_SKILL_3;	
			}
			
			WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER*AVERAGE_S_SKILL_OF_3/
				AVERAGE_S_SKILL_OF_1;
			break;

		case 4:
			if(NO_EMPLOYEES_SKILL_4 > 0)
			{
				AVERAGE_S_SKILL_OF_4 = sum_4/NO_EMPLOYEES_SKILL_4;	
			}
			
			WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER*AVERAGE_S_SKILL_OF_4/
				AVERAGE_S_SKILL_OF_1;
			break;

		case 5:/*If there are employees with skill level 5*/
			if(NO_EMPLOYEES_SKILL_5 > 0)
			{
				/*Calculate average specific skill of skill group 5*/
				AVERAGE_S_SKILL_OF_5 = sum_5/NO_EMPLOYEES_SKILL_5;	
			}
			
			WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER*AVERAGE_S_SKILL_OF_5/
				AVERAGE_S_SKILL_OF_1;
			break;		
		}
	}
	
	return 0;
}



/** \fn Firm_send_vacancies()
 * \brief Firms post vacancies and wage offer and send vacancies message
 */
int Firm_send_vacancies()
{
								
	 /*If more employees needed then send vacancies */
	if(EMPLOYEES_NEEDED > NO_EMPLOYEES)
	{
		/*Number of Vacancies/additional employees wanted*/
		VACANCIES = EMPLOYEES_NEEDED - NO_EMPLOYEES;

		/*For every skill group send vacancy message with the correspondent wage 				offer*/
		for(int m = 1; m < 6;m++)
		{	
			switch(m)
			{
			case 1:/*If skill level 1 send wage offer for skill group 1*/
				add_vacancies_message(ID, REGION_ID, VACANCIES,m,
				WAGE_OFFER_FOR_SKILL_1, MSGDATA);
				break;
			

			case 2:
				add_vacancies_message(ID, REGION_ID, VACANCIES,m,
				WAGE_OFFER_FOR_SKILL_2, MSGDATA);
				break;

			case 3:
				add_vacancies_message(ID, REGION_ID, VACANCIES,m,
				WAGE_OFFER_FOR_SKILL_3, MSGDATA);
				break;

			case 4:
				add_vacancies_message(ID, REGION_ID, VACANCIES,m,
				WAGE_OFFER_FOR_SKILL_4, MSGDATA);
				break;

			case 5:/*If skill level 5 send wage offer for skill group 5*/
				add_vacancies_message(ID, REGION_ID, VACANCIES,m,
				WAGE_OFFER_FOR_SKILL_5, MSGDATA);
				break;
			}		
		}			
	}
	
	return 0;
}



/** \fn Firm_send_redundancies()
 * \brief Firms have to dismiss employees. Therefore the send firing_messages:
 */
int Firm_send_redundancies()
{
	 
	/*If less employees needed then send redundencies */
	if(EMPLOYEES_NEEDED < NO_EMPLOYEES)
	{
		VACANCIES = 0;
		
		/*sorting employees: highest specific skills first*/
		/*int a, b;
		employee * first_employee, * second_employee;
		employee * temp_employee = (employee *)malloc(sizeof(employee));*/

		/* Using a bubble sort */
		/*for(a = 0; a<(EMPLOYEES.size-1); a++)
		{
			for(b=0; b<(EMPLOYEES.size-1)-a; b++) 
			{
				first_employee = &EMPLOYEES.array[b+1];
				second_employee = &EMPLOYEES.array[b];*/
		
				/* Comparing the values between neighbours */
				/*if(first_employee.specific_skill > 
				   second_employee.specific_skill)
				{*/
					/* Swap neighbours */
					/** temp_employee = * second_employee;
					* second_employee = * first_employee;
					* first_employee = * temp_employee;
				}
			}
		}*/

		/*sorting employees: highest specific skills first*/
		qsort(EMPLOYEES.array, EMPLOYEES.size, sizeof(employee),
			employee_list_rank_specific_skills_function);
		
		/*For the number of redundencies*/
		int j;
		for(int i = 0; i < (NO_EMPLOYEES - EMPLOYEES_NEEDED); i++)
		{	
			/*Firing: by chance*/
			j = random_int(0,(EMPLOYEES.size-1));
			add_firing_message(ID, EMPLOYEES.array[j].id, MSGDATA);

			/*Firing: lowest specific skill*/
			/*j = EMPLOYEES.size-1;
			add_firing_message(ID, EMPLOYEES.array[j].id, MSGDATA);*/
		
			switch(EMPLOYEES.array[j].general_skill)
			{
				/*If employee have had skill level 1 reduce the number of 						employees with skill level 1 by 1*/
				case 1:
					NO_EMPLOYEES_SKILL_1--;
					break;
					
				case 2:
					NO_EMPLOYEES_SKILL_2--;
					break;

				case 3:
					NO_EMPLOYEES_SKILL_3--;
					break;

				case 4:
					NO_EMPLOYEES_SKILL_4--;
					break;
				/*If employee have had skill level 5 reduce the number of 						employees with skill level 5 by 1*/
				case 5:
					NO_EMPLOYEES_SKILL_5--;
					break;
			}
			
			remove_employee(&EMPLOYEES, j);
			NO_EMPLOYEES--;
		}
		
		//NO_EMPLOYEES = EMPLOYEES_NEEDED;
	}
	
	
	return 0;
}




/** \fn Firm_read_job_applications_send_offer_or_rejection()
 * \brief Read job applications, rank, and send job offers and rejections
 */
int Firm_read_job_applications_send_job_offer_or_rejection()
{
	/* Create a job application dynamic array */
	job_application_array job_application_list; 
	init_job_application_array(&job_application_list);
	
	/* If day of month to act... */

	START_JOB_APPLICATION_MESSAGE_LOOP
		
		/* Read job application messages for this Firm */
		if(job_application_message->firm_id == ID)
		{
			/*Add application to a list (array)*/
			add_job_application(&job_application_list, 
			job_application_message->worker_id,
			job_application_message->region_id,
			job_application_message->general_skill, 
			job_application_message->specific_skill);
		}

	FINISH_JOB_APPLICATION_MESSAGE_LOOP

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

	/*Shuffle applications before sorting: If two or more applications are equal then 			they will be ranked by chance*/
	/*int i,k;
	job_application * i_job_application, * k_job_application;
	job_application * temp_job_application = (job_application *)malloc(sizeof
	(job_application));

	for(i = 0; i < (job_application_list.size);i++)
	{
		k = random_int(i, (job_application_list.size-1));

		i_job_application = &job_application_list.array[i];
		k_job_application = &job_application_list.array[k];*/

			/* Swap neighbours */
			/** temp_job_application = * i_job_application;
			* i_job_application = * k_job_application;
			* k_job_application = * temp_job_application;
	}

	free(temp_job_application);*/


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


	/*Rank job applications (function from my_library_functions) */
	//sort_job_application_list(&job_application_list);

	qsort(job_application_list.array, job_application_list.size, 
	sizeof(job_application), job_application_list_rank_general_skill_function);

	int i;
	/*For each job application message... */
	for(i = 0; i < (job_application_list.size); i++)
	{
		/*A firm cannot send more job offers than it has vacancies to fill*/
		if(i < VACANCIES)
		{
			/*For the different skill levels */
			switch(job_application_list.array[i].general_skill)
			{
			/*If general skill level is 1 send job offer with wage offer for 					general skill level 1*/
			case 1:
				add_job_offer_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_1, MSGDATA);
				break;
			case 2:
				add_job_offer_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_2, MSGDATA);
				break;
			case 3:
				add_job_offer_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_3, MSGDATA);
				break;
			case 4:
				add_job_offer_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_4, MSGDATA);
				break;
			/*If general skill level is 5 send job offer with wage offer for 					general skill level 5*/
			case 5:
				add_job_offer_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_5, MSGDATA);
				break;
			}
		}
		
		/* If no vacancies left then send a job rejection message */
		else
		{
			add_application_rejection_message(ID, 
			job_application_list.array[i].worker_id, MSGDATA);
		}
	}
		
	
	/* Free the job application dynamic array */
	free_job_application_array(&job_application_list);
	
		
	return 0;
}



/** \fn Firm_read_job_responses()
 * \brief Read job responses and add employees
 */
int Firm_read_job_responses()
{			
	/* If day of month to act... */
	
	START_JOB_ACCEPTANCE_MESSAGE_LOOP
		
		/* Read job acceptance messages for this Firm */
		if(job_acceptance_message->firm_id == ID)
		{
			
			/*Add employee to employee list */
			VACANCIES--;
			NO_EMPLOYEES++;

			switch(job_acceptance_message->general_skill)
			{
				/*If new employee has general skill level 1*/
				case 1:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id, 							WAGE_OFFER_FOR_SKILL_1, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);

					NO_EMPLOYEES_SKILL_1++;
					break;
			
				case 2:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id, 							WAGE_OFFER_FOR_SKILL_2, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);

					NO_EMPLOYEES_SKILL_2++;
					break;
			
				case 3:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id, 							WAGE_OFFER_FOR_SKILL_3, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);

					NO_EMPLOYEES_SKILL_3++;
					break;
			
				case 4:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id, 							WAGE_OFFER_FOR_SKILL_4, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);
					
					NO_EMPLOYEES_SKILL_4++;
					break;
				/*If new employee has general skill level 5*/
				case 5:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id, 							WAGE_OFFER_FOR_SKILL_5, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);
					
					NO_EMPLOYEES_SKILL_5++;
					break;
			}			
		}

	FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP

	
			
	return 0;
}

int Firm_read_job_quitting()
{
	/*Firms have to read quitting messages every day*/
	START_QUITTING_MESSAGE_LOOP
		/*Read quittings for this firm*/
		if(quitting_message->firm_id == ID)
		{
			int i=0;
			/*Control employees if one of them wants to quit*/
			for(i=0; i < (EMPLOYEES.size);i++)
			{
				if(quitting_message->worker_id == EMPLOYEES.array[i].id)
				{	
					int temp_skill = 0;
					temp_skill = EMPLOYEES.array[i].general_skill;
					/*remove that employee from the list*/
					remove_employee(&EMPLOYEES,i);
							
					VACANCIES++;
					NO_EMPLOYEES--;

					switch(temp_skill)
					{
						/*If the former employee have had general skill 						level 1 */
						case 1:
							NO_EMPLOYEES_SKILL_1--;
							break;
						
						case 2:
							NO_EMPLOYEES_SKILL_2--;
							break;

						case 3:
							NO_EMPLOYEES_SKILL_3--;
							break;

						case 4:
							NO_EMPLOYEES_SKILL_4--;
							break;
						/*If the former employee have had general skill 						level 5 */
						case 5:
							NO_EMPLOYEES_SKILL_5--;
							break;
					}
				}
			}		
		}

	FINISH_QUITTING_MESSAGE_LOOP
	
	return 0;
}


/** \fn Firm_update_wage_offer()
 * \brief Firms update wage_offer to get more applications
 */
int Firm_update_wage_offer()
{
		
	/*If there are "a lot" of vacancies still open...*/	
	if(VACANCIES > MIN_VACANCY)  
	{
		WAGE_OFFER = WAGE_OFFER*(1+wage_update);

		WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER_FOR_SKILL_1*(1+wage_update);
		WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER_FOR_SKILL_2*(1+wage_update);
		WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER_FOR_SKILL_3*(1+wage_update);
		WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER_FOR_SKILL_4*(1+wage_update);
		WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER_FOR_SKILL_5*(1+wage_update);	
	}
	
	return 0;
}



/** \fn Firm_send_vacancies_2()
 * \brief Firms which  did not fill all vacancies post vacancies and wage offer and send vacancies message
 */
int Firm_send_vacancies_2()
{
	/* If day of month to act... */
	
	/* If vacancies left */
	if(VACANCIES > 0)
	{
		/*For every general skill level (1-5)*/
		for(int m = 1; m < 6;m++)
		{
			switch(m)
			{
				/*If general skill level 1 send wage offer for general 						skill level 1*/
				case 1:
					add_vacancies2_message(ID, REGION_ID, VACANCIES,m,
					WAGE_OFFER_FOR_SKILL_1, MSGDATA);
					break;

				case 2:
					add_vacancies2_message(ID, REGION_ID, VACANCIES,m,
					WAGE_OFFER_FOR_SKILL_2, MSGDATA);
					break;

				case 3:
					add_vacancies2_message(ID, REGION_ID, VACANCIES,m,
					WAGE_OFFER_FOR_SKILL_3, MSGDATA);
					break;

				case 4:
					add_vacancies2_message(ID, REGION_ID, VACANCIES,m,
					WAGE_OFFER_FOR_SKILL_4, MSGDATA);
					break;
				/*If general skill level 5 send wage offer for general 						skill level 5*/
				case 5:
					add_vacancies2_message(ID, REGION_ID, VACANCIES,m,
					WAGE_OFFER_FOR_SKILL_5, MSGDATA);
					break;
			}	
		}		
	}	
	
	
	return 0;
}




/** \fn Firm_read_job_applications_send_offer_or_rejection()_2
 * \brief Read job applications, rank, and send job offers and rejections
 */
int Firm_read_job_applications_send_job_offer_or_rejection_2()
{
	/* Create a job application dynamic array */
	job_application_array job_application_list;
	init_job_application_array(&job_application_list);

	/* If day of month to act... */
	
	START_JOB_APPLICATION2_MESSAGE_LOOP

		/* Read job application messages for this Firm and add to the list*/
		if(job_application2_message->firm_id == ID)
		{
			add_job_application(&job_application_list, 
			job_application2_message->worker_id,
			job_application2_message->region_id, 
			job_application2_message->general_skill, 
			job_application2_message->specific_skill);
		}

	FINISH_JOB_APPLICATION2_MESSAGE_LOOP

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

	/*Shuffle applications before sorting: If two or more applications are equal then 			they will be ranked by chance*/
	/*int i,k;
	job_application * i_job_application, * k_job_application;
	job_application * temp_job_application = (job_application *)malloc(sizeof
	(job_application));

	for(i = 0; i < (job_application_list.size);i++)
	{
		k = random_int(i, (job_application_list.size-1));

		i_job_application = &job_application_list.array[i];
		k_job_application = &job_application_list.array[k];*/

			/* Swap neighbours */
			/** temp_job_application = * i_job_application;
			* i_job_application = * k_job_application;
			* k_job_application = * temp_job_application;
	}

	free(temp_job_application);*/


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

	
	/* Rank job applications (function from my_library_functions) */
	//sort_job_application_list(&job_application_list);
	
	qsort(job_application_list.array, job_application_list.size, 
	sizeof(job_application), job_application_list_rank_general_skill_function);
	
	int i;
	/*For each job application message... */
	for(i = 0; i < job_application_list.size; i++)
	{
		/* A firm cannot send more job offers than it has vacancies to fill */
		if(i < VACANCIES)
		{
			switch(job_application_list.array[i].general_skill)
			{
			/*If applicant has general skill level 1 send job offer with wage 					for skill group 1*/
			case 1:
				add_job_offer2_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_1, MSGDATA);
				break;	
			case 2:
				add_job_offer2_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_2, MSGDATA);
				break;
			case 3:
				add_job_offer2_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_3, MSGDATA);
				break;
			case 4:
				add_job_offer2_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_4, MSGDATA);
				break;
			/*If applicant has general skill level 5 send job offer with wage 					for skill group 5*/
			case 5:
				add_job_offer2_message(ID, job_application_list.array[i]
				.worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_5, MSGDATA);
				break;
			}
		}
		/* If no vacancies left then send a job rejection message */
		else
		{
			add_application_rejection2_message(ID, 
			job_application_list.array[i].worker_id, MSGDATA);
		}
	}	
	
	/* Free the job application dynamic array */
		free_job_application_array(&job_application_list);
	
	return 0;
}



/** \fn Firm_read_job_responses_2()
 * \brief Read job responses and add employees
 */
int Firm_read_job_responses_2()
{
	/* If day of month to act... */
	
	START_JOB_ACCEPTANCE2_MESSAGE_LOOP

		/* Read job acceptance messages for this Firm */
		if(job_acceptance2_message->firm_id == ID)
		{
			/*Add employee to employee list*/ 
			
			VACANCIES--;
			NO_EMPLOYEES++;

			switch(job_acceptance2_message->general_skill)
			{
				/*If new employees has general skill level 1*/
				case 1:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id, 							WAGE_OFFER_FOR_SKILL_1, 
					job_acceptance2_message->general_skill, 						job_acceptance2_message->specific_skill);
					
					NO_EMPLOYEES_SKILL_1++;
					break;
			
				case 2:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id, 							WAGE_OFFER_FOR_SKILL_2, 
					job_acceptance2_message->general_skill, 						job_acceptance2_message->specific_skill);

					NO_EMPLOYEES_SKILL_2++;
					break;
			
				case 3:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id, 							WAGE_OFFER_FOR_SKILL_3, 
					job_acceptance2_message->general_skill, 						job_acceptance2_message->specific_skill);

					NO_EMPLOYEES_SKILL_3++;
					break;
			
				case 4:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id, 							WAGE_OFFER_FOR_SKILL_4, 
					job_acceptance2_message->general_skill, 						job_acceptance2_message->specific_skill);

					NO_EMPLOYEES_SKILL_4++;
					break;
				/*If new employees has general skill level 5*/
				case 5:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id, 							WAGE_OFFER_FOR_SKILL_5, 
					job_acceptance2_message->general_skill, 						job_acceptance2_message->specific_skill);

					NO_EMPLOYEES_SKILL_5++;
					break;
			}
		}

	FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP
	
		
	return 0;
}

int Firm_read_job_quitting_2()
{
	/*Firms have to read quitting messages every day*/
	START_QUITTING2_MESSAGE_LOOP
		/*Read quittings for this firm*/
		if(quitting2_message->firm_id == ID)
		{
			int i;
			/*Control every employee if he wants to quit*/
			for(i=0; i < (EMPLOYEES.size);i++)
			{
				if(quitting2_message->worker_id == EMPLOYEES.array[i].id)
				{	
					int temp_skill = 0;
					temp_skill = EMPLOYEES.array[i].general_skill;
					/*remove this former employee from the list*/
					remove_employee(&EMPLOYEES,i);
						
					VACANCIES++;
					NO_EMPLOYEES--;

					switch(temp_skill)
					{
						/*If the former employee have had general skill 						level 1*/
						case 1:
							NO_EMPLOYEES_SKILL_1--;
							break;
						
						case 2:
							NO_EMPLOYEES_SKILL_2--;
							break;

						case 3:
							NO_EMPLOYEES_SKILL_3--;
							break;

						case 4:
							NO_EMPLOYEES_SKILL_4--;
							break;
						/*If the former employee have had general skill 						level 5*/
						case 5:
							NO_EMPLOYEES_SKILL_5--;
							break;
					}
				}
			}
			
		}

	FINISH_QUITTING2_MESSAGE_LOOP
	
	return 0;
}


/** \fn Firm_update_wage_offer_2()
 * \brief Firms update wage_offer to get more applications in next iteration
 */
int Firm_update_wage_offer_2()
{
	int i;
	int j = 0;

	/*Average  general skill at the end of one day*/
	for(i = 0; i < (EMPLOYEES.size); i++)
	{
		j += EMPLOYEES.array[i].general_skill;	
	}
	
	if(NO_EMPLOYEES > 0)
	{
		AVERAGE_G_SKILL = (double)((double)j/(double)NO_EMPLOYEES);
	}
	

	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT)
	{	
		if(VACANCIES > 0) 
		{
			//WAGE_OFFER = WAGE_OFFER*(1 + wage_update);
			
		}

	}

	return 0;
}




