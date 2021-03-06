#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
#include "Labour_aux_headers.h"


/*************************************Firm Role: Labour Market*********************************/

/** \fn Firm_calculate_specific_skills_and_wage_offer()
 * \brief: 
	- Firm calculates the average specific skills for each general skill group. 
	- Firm determines the wage offer for each general skill group.*/
int Firm_calculate_specific_skills_and_wage_offer()
{
	int n;
	int m;
	
    char * filename;
    FILE * file1;
	
	/*Sum up the specific skills of employees  for each general skill group (1-5): for average*/
	double sum_1 = 0;
	double sum_2 = 0;
	double sum_3 = 0;
	double sum_4 = 0;
	double sum_5 = 0;

	/*For every employee*/
	for(n = 0; n < EMPLOYEES.size; n++)
	{
		/*Explore the general skill level (1-5) of each employee*/
		switch(EMPLOYEES.array[n].general_skill)
		{
			/*If employee has general skill level 1 add specific skill to sum1*/
			case 1:
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

			/*If employee has general skill level 5 add specific skill to sum5*/
			case 5:
			sum_5 = sum_5 + EMPLOYEES.array[n].specific_skill;
			break;
		}
	}

	/*For each general skill group: Calculate the average specific skills.*/
	for(m = 1; m < 6;m++)
	{
		switch(m)
		{
			/*If skill level 1: Calculate the average specific skills of general skill group 1.*/
			case 1:
				/*If there are employees with general skill level 1.*/
				if(NO_EMPLOYEES_SKILL_1 > 0)
				{   
					/*Calculate average specific skill of skill group 1*/
					AVERAGE_S_SKILL_OF_1 = sum_1/NO_EMPLOYEES_SKILL_1;
				}

				/*Wage offer determination: Basic wage offer per unit of specific skills times the minimum of 
				the average specific skill of general skill group 1 or technology.*/
				WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER* min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1);
				break;
			

			case 2:
				if(NO_EMPLOYEES_SKILL_2 > 0)
				{
					AVERAGE_S_SKILL_OF_2 = sum_2/NO_EMPLOYEES_SKILL_2;  
				}

				/*The other skill groups get a higher wage offer depending on the   productivity (specific skill)*/
				WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_2);
				break;
			

			case 3:
				if(NO_EMPLOYEES_SKILL_3 > 0)
				{
					AVERAGE_S_SKILL_OF_3 = sum_3/NO_EMPLOYEES_SKILL_3;  
				}

				WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_3);
				break;
			

			case 4:
				if(NO_EMPLOYEES_SKILL_4 > 0)
				{
					AVERAGE_S_SKILL_OF_4 = sum_4/NO_EMPLOYEES_SKILL_4;  
				}

				WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_4);
				break;
			

			/*If skill level 5: Calculate the average specific skills of general skill group 5.*/
			case 5:
				if(NO_EMPLOYEES_SKILL_5 > 0)
				{
					/*Calculate average specific skill of skill group 5*/
					AVERAGE_S_SKILL_OF_5 = sum_5/NO_EMPLOYEES_SKILL_5;  
				}
			
				/*Wage offer determination: Basic wage offer per unit of specific skills times the minimum of 
				the average specific skill of general skill group 5 or technology.*/
				WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5);
				break;  
		}
	}
	
	 if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firm_calculate_wage_offer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f",DAY,ID,WAGE_OFFER);
        fclose(file1);
        free(filename);
    }    
	

	return 0;
}



/** \fn Firm_send_vacancies()
 * \brief: 
	- Firm sends vacancies message if the number of employees is smaller than the number of needed employees.
	- Vacancies include Firm_ID, Region_ID, and different wage offers for each general skill group.
 */
int Firm_send_vacancies()
{
       
	/*Number of Vacancies/additional employees wanted*/
	VACANCIES = EMPLOYEES_NEEDED - NO_EMPLOYEES;
	
   

	/*Send vacancies message with different wage offers for each general skill group.*/
	add_vacancies_message(ID, 
	REGION_ID, 
	WAGE_OFFER_FOR_SKILL_1, 
	WAGE_OFFER_FOR_SKILL_2, 
	WAGE_OFFER_FOR_SKILL_3, 
	WAGE_OFFER_FOR_SKILL_4, 
	WAGE_OFFER_FOR_SKILL_5);
	

	return 0;
}



/** \fn Firm_send_redundancies()
 * \brief: 
	- Firm send firing messages if the number of employees is higher than the number of needed employees.
	- Market driven dismissals.
 */
int Firm_send_redundancies()
{
	int j;
	int i;
	int no_redundancies;
	
	VACANCIES = 0;

	/*If firm wants to dismiss employees with lowest specific skills first.*/
	/*sorting employees: highest specific skills first*/
	//qsort(EMPLOYEES.array, EMPLOYEES.size, sizeof(employee),
	//employee_list_rank_specific_skills_function);
		
	/*If firm wants to dismiss employees with lowest general skills first.*/
	/*sorting employees: highest genral skills first*/
	//qsort(EMPLOYEES.array, EMPLOYEES.size, sizeof(employee),
	//employee_list_rank_general_skill_function);


	/*Determine the number of redundencies.*/
	no_redundancies = NO_EMPLOYEES - EMPLOYEES_NEEDED;

	for(i = 0; i < no_redundancies; i++)
	{   
		/*1. Option: Firing by chance*/
		j = random_int(0,(EMPLOYEES.size-1));
		add_firing_message(ID, EMPLOYEES.array[j].id);

		/*2/3. Option: Firing employees with lowest specific(2)/genral skill(3)*/
		/*j = EMPLOYEES.size-1;
		add_firing_message(ID, EMPLOYEES.array[j].id);*/
			
		/*Explore the genral skill level of dismissed employee.*/
		switch(EMPLOYEES.array[j].general_skill)
		{
			/*If dismissed employee has skill level 1 reduce the number of employees with skill level 1 by 1.*/
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
					
			/*If dismissed employee has skill level 5 reduce the number of employees with skill level 5 by 1.*/
			case 5:
				NO_EMPLOYEES_SKILL_5--;
				break;
		}
			
		/*Remove the employee from the list.*/
		remove_employee(&EMPLOYEES, j);
		/*Reduce the overall number of employees by 1.*/
		NO_EMPLOYEES--;
	}
	
	return 0;
}



/** \fn Firm_send_random_redundancies()
* \brief: 
	- Firm dismisses a small randomly determined fraction of employees. 
	- Interpretation: employee quits, employer is not satisfied....
	- Not market driven.
*/
int Firm_send_random_redundancies()
{
	int i;
	int j;
	int random_num;
	int no_redundancies;
	char * filename;
    FILE * file1;

	/*Determine the fraction of employyes who will be dismissed.*/
	random_num = random_int(LOWER_BOUND_FIRING,UPPER_BOUND_FIRING);
	
	/*Translate this fraction into an absolute number.*/
	no_redundancies = (random_num*NO_EMPLOYEES)/100;

	/*Round up the number of redundancies to the next integer.*/
	if((((random_num*NO_EMPLOYEES)%100) < 100) && (((random_num*NO_EMPLOYEES)%100)>0))
	{
		no_redundancies = no_redundancies+1;
	}

	/*Employees are fired randomly.*/
	for(i = 0; i < no_redundancies; i++)
	{  
		/*Firing: by chance*/
		j = random_int(0,(EMPLOYEES.size-1));
		add_firing_message(ID, EMPLOYEES.array[j].id);

		switch(EMPLOYEES.array[j].general_skill)
		{
			/*If dismissed employee has skill level 5 reduce the number of employees with skill level 1 by 1.*/
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
				
			/*If dismissed employee has skill level 5 reduce the number of employees with skill level 5 by 1.*/
			case 5:
				NO_EMPLOYEES_SKILL_5--;
				break;
		}
		
		/*Remove the employee from the list.*/
		remove_employee(&EMPLOYEES, j);
		/*Reduce the overall number of employees by 1.*/
		NO_EMPLOYEES--;
	}
	
	if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firms_send_rndredundancies.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %d %d",DAY,ID,NO_EMPLOYEES,EMPLOYEES_NEEDED);
        fclose(file1);
        free(filename);
    } 
	
 
	return 0;
} 



/** \fn Firm_read_job_applications_send_offer_or_rejection()
 * \brief: 
	- Firm reads job applications. 
	- Firm sends job offers.
		1: If number of applicants is smaller than the number of vacancies: send job offer to each applicant.
		2: If number of applicant is higher than the number of vacancies: use logit model.
			Applicants with higher general skills have a higher probability to receive a job offer.
 */
int Firm_read_job_applications_send_job_offer_or_rejection()
{
	int i;
	int j;
	int k;
	int no_applications;
     char * filename;
     FILE * file1;

	/* Create a job application dynamic array */
	job_application_array job_application_list; 
	init_job_application_array(&job_application_list);

	START_JOB_APPLICATION_MESSAGE_LOOP

		/* Read job application messages for this Firm */
		if(job_application_message->firm_id == ID)
		{
			/*Add application to application list.*/
			add_job_application(&job_application_list, 
			job_application_message->worker_id,
			job_application_message->region_id,
			job_application_message->general_skill, 
			job_application_message->specific_skill);
		}

	FINISH_JOB_APPLICATION_MESSAGE_LOOP


	no_applications = job_application_list.size;
	
	if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/Firm_read_job_appl.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %d",DAY,ID,no_applications);
        fclose(file1);
        free(filename);
    } 

	/*Sort the applications. Highest general skills first.*/
	/*qsort(job_application_list.array, job_application_list.size, 
	sizeof(job_application), job_application_list_rank_general_skill_function);*/

	/*Case 1: Number of Vacancies is equal or higher than number of applications:
	each applicant gets a job offer*/   
	if(no_applications <= VACANCIES)
	{	
		for(i = 0; i < (job_application_list.size); i++)
		{
			/*For the different skill levels of the applicants. */
			switch(job_application_list.array[i].general_skill)
			{
				/*If applicant has general skill level 1 send job offer with wage offer for general skill level 1.*/
				case 1:
					add_job_offer_message(ID, 
					job_application_list.array[i].worker_id, 
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_1);
					break;
					
				case 2:
					add_job_offer_message(ID, 
					job_application_list.array[i].worker_id,
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_2);
					break;

				case 3:
					add_job_offer_message(ID,
					job_application_list.array[i].worker_id,
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_3);
					break;

				case 4:
					add_job_offer_message(ID, 
					job_application_list.array[i].worker_id,
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_4);
					break;

				/*If applicant has general skill level 1 send job offer with wage offer for general skill level 5.*/
				case 5:
					add_job_offer_message(ID, 
					job_application_list.array[i].worker_id,
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_5);
					break;
			}

		}

	}
	/*Case 2: Number of Vacancies is smaller  than number of applications:
	firm choose applicants using a logit model*/
	else
	{
		/*For each vacancy to fill...*/
		for(i = 0; i< VACANCIES; i++)
		{
			/*Create temporary array to store logits of the applicants.*/
			logit_array  logit_applications_list;
			init_logit_array(&logit_applications_list);

			/*Variables for the logit*/
			double denominator_logit = 0;
			double logit = 0.0;
			double sum_of_logits;
			double random_number;

			/*For each vacancy to fill sum up the logits of all (remaining) applicants.*/
			for(j = 0; j< job_application_list.size;j++)
			{
				/*logit = exp(x*general_skill + y* specific skills):
				x and y are sensivity parameters and determine the effect of the skills on the value of the logit*/
				denominator_logit+= exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + 					LOGIT_PARAMETER_SPECIFIC_SKILLS*job_application_list.array[j].specific_skill);   
			}

			/*The denominator of the logit model has to be greater than 0.*/   
			if(denominator_logit>0)
			{
				/*For each vacancy calculate the logit for each (remaining) applicant according to his general/specific skills.*/
				for(j = 0; j< job_application_list.size;j++)
				{
					logit = exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + 		
					LOGIT_PARAMETER_SPECIFIC_SKILLS*job_application_list.array[j].specific_skill)/ denominator_logit;

					/*Store the applicant_id and the corresponding logit in a list.*/
					add_logit(&logit_applications_list, 
					100*logit,job_application_list.array[j].worker_id,
					job_application_list.array[j].general_skill);
				}
			}
			
			/*This draws a random number*/
			random_number =  (double)random_int(0,100);

			sum_of_logits = 0;
			for(j = 0; j< logit_applications_list.size;j++)
			{
				sum_of_logits += logit_applications_list.array[j].logit_value;

				/*Check if the random number is smaller than the (cumulative) sum of logits over (remaining applicants):
				If the value of the applicants logit is high the probability that the random number is smaller than the sum of
				logits is also high.*/
				if(random_number<sum_of_logits)
				{
					/*If condition is true, the firm chooses that worker and 
					send a job offer with the corresponding wage offer   */ 
					switch(logit_applications_list.array[j].general_skill)
					{
						/*If the applicant has general skill level 1 send job offer with wage offer for general skill level 1*/
						case 1:
							add_job_offer_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_1);
							break;
							
						case 2:
							add_job_offer_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_2);
							break;

						case 3:
							add_job_offer_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_3);
							break;

						case 4:
							add_job_offer_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_4);
							break;

						/*If the applicant has general skill level 1 send job offer with wage offer for general skill level 5*/
						case 5:
							add_job_offer_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_5);
							break;
					}

					/*The chosen worker has to be removed from the application list*/
					for(k = 0; k< job_application_list.size;k++)
					{
						if(job_application_list.array[k].worker_id == logit_applications_list.array[j].worker_id)
						{
							remove_job_application(&job_application_list,k);
							break;
						}
					}
					
					/*If one job offer was sent stop traversing the application list and go to the next vacancy.*/
					break;  
				}
			}
			/* Free the job application dynamic array */
			free_logit_array(&logit_applications_list);
		}
	}
	/* Free the job application dynamic array */
	free_job_application_array(&job_application_list);

	return 0;
}



/** \fn Firm_read_job_responses()
 * \brief:
	- Firm reads job responses and add employees.
 */
int Firm_read_job_responses()
{   
    char * filename;
    FILE * file1;
    
	START_JOB_ACCEPTANCE_MESSAGE_LOOP

		/* Read job acceptance messages for this Firm */
		if(job_acceptance_message->firm_id == ID)
		{
			/*Add employee to employee list, increase the number of overall employees by 1 
			and decrease the number of vacancies.*/
			NO_EMPLOYEES++;
			VACANCIES--;

			/*Explore the general skill level of the new worker.*/
			switch(job_acceptance_message->general_skill)
			{
				/*If new employee has general skill level 1 add him to the employee list and increase the number of 
				employees with general skill level 1 by 1.*/
				case 1:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  WAGE_OFFER_FOR_SKILL_1, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);

					NO_EMPLOYEES_SKILL_1++;
					break;

				case 2:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  WAGE_OFFER_FOR_SKILL_2, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);

					NO_EMPLOYEES_SKILL_2++;
					break;

				case 3:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  WAGE_OFFER_FOR_SKILL_3, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);

					NO_EMPLOYEES_SKILL_3++;
					break;

				case 4:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  WAGE_OFFER_FOR_SKILL_4, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);

					NO_EMPLOYEES_SKILL_4++;
					break;
					
				/*If new employee has general skill level 5 add him to the employee list and increase the number of 
				employees with general skill level 5 by 1.*/
				case 5:
					add_employee(&EMPLOYEES, 
					job_acceptance_message->worker_id,
					job_acceptance_message->region_id,  WAGE_OFFER_FOR_SKILL_5, 
					job_acceptance_message->general_skill, 
					job_acceptance_message->specific_skill);

					NO_EMPLOYEES_SKILL_5++;
					break;
			}   
		}

	FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP
	
		if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/Firm_read_job_responses.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %d %d",DAY,ID,NO_EMPLOYEES,VACANCIES);
        fclose(file1);
        free(filename);
    } 

	return 0;
}



/** \fn Firm_update_wage_offer()
 * \brief: 
	- Firm increases the basic wage_offer to get more applications in the next round if there are unfilled vacancies left.
 */
int Firm_update_wage_offer()
{
   char * filename;
   FILE * file1;
    double wage_old  = 0.0;
	/*If there are "a lot" of vacancies still open...*/ 
	
	wage_old = WAGE_OFFER;
	if(VACANCIES > MIN_VACANCY)  
	{
		/*Update the basic wage offer.*/
		WAGE_OFFER = WAGE_OFFER*(1+WAGE_UPDATE);

		/*Update the general skill dependend wage offers.*/
		WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER_FOR_SKILL_1*(1+WAGE_UPDATE);
		WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER_FOR_SKILL_2*(1+WAGE_UPDATE);
		WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER_FOR_SKILL_3*(1+WAGE_UPDATE);
		WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER_FOR_SKILL_4*(1+WAGE_UPDATE);
		WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER_FOR_SKILL_5*(1+WAGE_UPDATE);
	}
	
  if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firms_update_wage_offer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %d %f %f",DAY,ID,VACANCIES,wage_old,WAGE_OFFER);
        fclose(file1);
        free(filename);
    }    

return 0;
}



/** \fn Firm_send_vacancies_2()
 * \brief: 
	- Firms which  did not fill all vacancies post vacancies and wage offer and send vacancies message
 */
int Firm_send_vacancies_2()
{

	/* If vacancies left */
	if(VACANCIES > 0)
	{
		/*For every general skill level (1-5)*/		
		add_vacancies2_message(ID, 
		REGION_ID, 
		WAGE_OFFER_FOR_SKILL_1, 
		WAGE_OFFER_FOR_SKILL_2, 
		WAGE_OFFER_FOR_SKILL_3, 
		WAGE_OFFER_FOR_SKILL_4, 
		WAGE_OFFER_FOR_SKILL_5);
	}   

	return 0;
}




/** \fn Firm_read_job_applications_send_offer_or_rejection_2()
 * \brief: 
	- Firm reads job applications. 
	- Firm sends job offers.
		1: If number of applicants is smaller than the number of vacancies: send job offer to each applicant.
		2: If number of applicant is higher than the number of vacancies: use logit model.
			Applicants with higher general skills have a higher probability to receive a job offer.
 */
int Firm_read_job_applications_send_job_offer_or_rejection_2()
{
	int i;
	int j;
	int k;
	int no_applications;
	char * filename;
    FILE * file1;

	/* Create a job application dynamic array */
	job_application_array job_application_list; 
	init_job_application_array(&job_application_list);

	START_JOB_APPLICATION2_MESSAGE_LOOP

		/* Read job application messages for this Firm */
		if(job_application2_message->firm_id == ID)
		{
			/*Add application to application list.*/
			add_job_application(&job_application_list, 
			job_application2_message->worker_id,
			job_application2_message->region_id,
			job_application2_message->general_skill, 
			job_application2_message->specific_skill);
		}

	FINISH_JOB_APPLICATION2_MESSAGE_LOOP


	no_applications = job_application_list.size;
	
	if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/Firm_read_job_appl2.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %d",DAY,ID,no_applications);
        fclose(file1);
        free(filename);
    } 

	/*Sort the applications. Highest general skills first.*/
	/*qsort(job_application_list.array, job_application_list.size, 
	sizeof(job_application), job_application_list_rank_general_skill_function);*/

	/*Case 1: Number of Vacancies is equal or higher than number of applications:
	each applicant gets a job offer*/   
	if(no_applications <= VACANCIES)
	{	
		for(i = 0; i < (job_application_list.size); i++)
		{
			/*For the different skill levels of the applicants. */
			switch(job_application_list.array[i].general_skill)
			{
				/*If applicant has general skill level 1 send job offer with wage offer for general skill level 1.*/
				case 1:
					add_job_offer2_message(ID, 
					job_application_list.array[i].worker_id, 
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_1);
					break;
					
				case 2:
					add_job_offer2_message(ID, 
					job_application_list.array[i].worker_id,
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_2);
					break;

				case 3:
					add_job_offer2_message(ID,
					job_application_list.array[i].worker_id,
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_3);
					break;

				case 4:
					add_job_offer2_message(ID, 
					job_application_list.array[i].worker_id,
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_4);
					break;

				/*If applicant has general skill level 1 send job offer with wage offer for general skill level 5.*/
				case 5:
					add_job_offer2_message(ID, 
					job_application_list.array[i].worker_id,
					REGION_ID, 
					WAGE_OFFER_FOR_SKILL_5);
					break;
			}

		}

	}
	/*Case 2: Number of Vacancies is smaller  than number of applications:
	firm choose applicants using a logit model*/
	else
	{
		/*For each vacancy to fill...*/
		for(i = 0; i< VACANCIES; i++)
		{
			/*Create temporary array to store logits of the applicants.*/
			logit_array  logit_applications_list;
			init_logit_array(&logit_applications_list);

			/*Variables for the logit*/
			double denominator_logit = 0;
			double logit = 0.0;
			double sum_of_logits;
			double random_number;

			/*For each vacancy to fill sum up the logits of all (remaining) applicants.*/
			for(j = 0; j< job_application_list.size;j++)
			{
				/*logit = exp(x*general_skill + y* specific skills):
				x and y are sensivity parameters and determine the effect of the skills on the value of the logit*/
				denominator_logit+= exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + 					LOGIT_PARAMETER_SPECIFIC_SKILLS*job_application_list.array[j].specific_skill);   
			}

			/*The denominator of the logit model has to be greater than 0.*/   
			if(denominator_logit>0)
			{
				/*For each vacancy calculate the logit for each (remaining) applicant according to his general/specific skills.*/
				for(j = 0; j< job_application_list.size;j++)
				{
					logit = exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + 		
					LOGIT_PARAMETER_SPECIFIC_SKILLS*job_application_list.array[j].specific_skill)/ denominator_logit;

					/*Store the applicant_id and the corresponding logit in a list.*/
					add_logit(&logit_applications_list, 
					100*logit,job_application_list.array[j].worker_id,
					job_application_list.array[j].general_skill);
				}
			}
			
			/*This draws a random number*/
			random_number =  (double)random_int(0,100);

			sum_of_logits = 0;
			for(j = 0; j< logit_applications_list.size;j++)
			{
				sum_of_logits += logit_applications_list.array[j].logit_value;

				/*Check if the random number is smaller than the (cumulative) sum of logits over (remaining applicants):
				If the value of the applicants logit is high the probability that the random number is smaller than the sum of
				logits is also high.*/
				if(random_number<sum_of_logits)
				{
					/*If condition is true, the firm chooses that worker and 
					send a job offer with the corresponding wage offer   */ 
					switch(logit_applications_list.array[j].general_skill)
					{
						/*If the applicant has general skill level 1 send job offer with wage offer for general skill level 1*/
						case 1:
							add_job_offer2_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_1);
							break;
							
						case 2:
							add_job_offer2_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_2);
							break;

						case 3:
							add_job_offer2_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_3);
							break;

						case 4:
							add_job_offer2_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_4);
							break;

						/*If the applicant has general skill level 1 send job offer with wage offer for general skill level 5*/
						case 5:
							add_job_offer2_message(ID, 
							logit_applications_list.array[j].worker_id,
							REGION_ID, 
							WAGE_OFFER_FOR_SKILL_5);
							break;
					}

					/*The chosen worker has to be removed from the application list*/
					for(k = 0; k< job_application_list.size;k++)
					{
						if(job_application_list.array[k].worker_id == logit_applications_list.array[j].worker_id)
						{
							remove_job_application(&job_application_list,k);
							break;
						}
					}
					
					/*If one job offer was sent stop traversing the application list and go to the next vacancy.*/
					break;  
				}
			}
			/* Free the job application dynamic array */
			free_logit_array(&logit_applications_list);
		}
	}
	/* Free the job application dynamic array */
	free_job_application_array(&job_application_list);

	return 0;
}



/** \fn Firm_read_job_responses_2()
 * \brief:
	- Firm reads job responses and add employees.
 */
int Firm_read_job_responses_2()
{   
    char * filename;
    FILE * file1;
    
	START_JOB_ACCEPTANCE2_MESSAGE_LOOP

		/* Read job acceptance messages for this Firm */
		if(job_acceptance2_message->firm_id == ID)
		{
			/*Add employee to employee list, increase the number of overall employees by 1 
			and decrease the number of vacancies.*/
			NO_EMPLOYEES++;
			VACANCIES--;

			/*Explore the general skill level of the new worker.*/
			switch(job_acceptance2_message->general_skill)
			{
				/*If new employee has general skill level 1 add him to the employee list and increase the number of 
				employees with general skill level 1 by 1.*/
				case 1:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  WAGE_OFFER_FOR_SKILL_1, 
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill);

					NO_EMPLOYEES_SKILL_1++;
					break;

				case 2:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  WAGE_OFFER_FOR_SKILL_2, 
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill);

					NO_EMPLOYEES_SKILL_2++;
					break;

				case 3:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  WAGE_OFFER_FOR_SKILL_3, 
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill);

					NO_EMPLOYEES_SKILL_3++;
					break;

				case 4:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  WAGE_OFFER_FOR_SKILL_4, 
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill);

					NO_EMPLOYEES_SKILL_4++;
					break;
					
				/*If new employee has general skill level 5 add him to the employee list and increase the number of 
				employees with general skill level 5 by 1.*/
				case 5:
					add_employee(&EMPLOYEES, 
					job_acceptance2_message->worker_id,
					job_acceptance2_message->region_id,  WAGE_OFFER_FOR_SKILL_5, 
					job_acceptance2_message->general_skill, 
					job_acceptance2_message->specific_skill);

					NO_EMPLOYEES_SKILL_5++;
					break;
			}   
		}

	FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP

    if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/Firm_read_job_responses2.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %d %d %d",DAY,ID,NO_EMPLOYEES,VACANCIES);
        fclose(file1);
        free(filename);
    } 

	return 0;
}



/** \fn Firm_update_wage_offer_2()
 * \brief: 
	- Firm increases the basic wage_offer to get more applications in the next month if there are unfilled vacancies left.
 */
int Firm_update_wage_offer_2()
{
	/*If there are "a lot" of vacancies still open...*/ 
	//if(VACANCIES > MIN_VACANCY)  
	//{
		/*Update the basic wage offer.*/
		//WAGE_OFFER = WAGE_OFFER*(1+WAGE_UPDATE);

		/*Update the general skill dependend wage offers.*/
		//WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER_FOR_SKILL_1*(1+WAGE_UPDATE);
		//WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER_FOR_SKILL_2*(1+WAGE_UPDATE);
		//WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER_FOR_SKILL_3*(1+WAGE_UPDATE);
		//WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER_FOR_SKILL_4*(1+WAGE_UPDATE);
		//WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER_FOR_SKILL_5*(1+WAGE_UPDATE);
	//} 

	return 0;
}



/** \fn Firm_compute_mean_wage_specific_skills()
 * \brief: 
	- Firm computes the mean wage, mean specific skills and mean general skills of the workforce
 */
int Firm_compute_mean_wage_specific_skills()
{
	int i;
	double ave_wage =0.0;
	double ave_specific_skills =0.0;
	double ave_general_skills =0.0;

	/*Sum up the wage and the specific skills of each worker.*/
	for(i=0;i<EMPLOYEES.size;i++)
	{
		ave_wage+=EMPLOYEES.array[i].wage;
		ave_specific_skills += EMPLOYEES.array[i].specific_skill;
		ave_general_skills += EMPLOYEES.array[i].general_skill;
	}

	/*If the firm has no employees*/
	double no_employees = (double) NO_EMPLOYEES;
	if(no_employees==0)
	{
		MEAN_WAGE = WAGE_OFFER;
		MEAN_SPECIFIC_SKILLS = AVERAGE_S_SKILL_OF_1;
	}
	/*If the firm has  employees calculate the mean wage and mean specific skills.*/
	else
	{
		MEAN_WAGE = ave_wage /( no_employees);
		MEAN_SPECIFIC_SKILLS =ave_specific_skills/no_employees;
		AVERAGE_G_SKILL = ave_general_skills/no_employees;
	}
	
	
	return 0;
}


/************************************ Firm agent auxiliary functions ************************************/

int Firm_finish_labour_market_first_round()
{
	return 0;
}

int Firm_start_labour_market()
{
	return 0;
}

int Firm_read_job_quitting()
{

	return 0;
}

int Firm_read_job_quitting_2()
{

	return 0;
}


