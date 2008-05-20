#include "../header.h"
#include "../Eurostat_agent_header.h"
#include "../my_library_header.h"

/** \fn Eurostat_Initialization()
 * \brief Eurostat initialization.
 */
int Eurostat_Initialization()
{
	/*Create data content of REGION_FIRM/HOUSEHOLD_DATA at the beginning of the first day. 		The first firms will send the data at the end of the first day and the other firms at the 		end of their activation days*/	
		
		
	for(int i = 1; i <= NO_REGIONS; i++)
	{
		add_firm_data(&REGION_FIRM_DATA,
		i,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		
		add_household_data(&REGION_HOUSEHOLD_DATA,
		i,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1);
	}
	
	return 0;
		
}

/** \fn Eurostat_send_data()
 * \brief Eurostat send data: specific skills ...
 */
int Eurostat_send_data()
{
	/*First of every month*/
	
	/*Send the data*/
	for(int i = 0; i < REGION_HOUSEHOLD_DATA.size; i++)
	{
		add_market_research_send_specific_skills_message(
		REGION_HOUSEHOLD_DATA.array[i].region_id, 	
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1, 
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2,
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3, 
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4, 
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5);

	//printf("SEND %f \n",REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5);
	}
	
	return 0;
}


/** \fn Eurostat_calculate_data
 * \brief Eurostat receive micro data and calculates macro data
 */
int Eurostat_calculate_data()
{
		
	/*delete the content of the memmory variables in order to store the data for the 			new month*/
	
	EMPLOYED = 0;
	EMPLOYED_SKILL_1 = 0;
	EMPLOYED_SKILL_2 = 0;
	EMPLOYED_SKILL_3 = 0;
	EMPLOYED_SKILL_4 = 0;
	EMPLOYED_SKILL_5 = 0;
	UNEMPLOYED = 0;		

	UNEMPLOYMENT_RATE = 0.0;
	UNEMPLOYMENT_RATE_SKILL_1 = 0.0;
	UNEMPLOYMENT_RATE_SKILL_2 = 0.0;
	UNEMPLOYMENT_RATE_SKILL_3 = 0.0;
	UNEMPLOYMENT_RATE_SKILL_4 = 0.0;
	UNEMPLOYMENT_RATE_SKILL_5 = 0.0;

	AVERAGE_WAGE = 0.0;
	AVERAGE_WAGE_SKILL_1 = 0.0;
	AVERAGE_WAGE_SKILL_2 = 0.0;
	AVERAGE_WAGE_SKILL_3 = 0.0;
	AVERAGE_WAGE_SKILL_4 = 0.0;
	AVERAGE_WAGE_SKILL_5 = 0.0;

	AVERAGE_S_SKILL = 0.0;
	AVERAGE_S_SKILL_1 = 0.0;
	AVERAGE_S_SKILL_2 = 0.0;
	AVERAGE_S_SKILL_3 = 0.0;
	AVERAGE_S_SKILL_4 = 0.0;
	AVERAGE_S_SKILL_5 = 0.0;

	NO_VACANCIES = 0.0;
	NO_EMPLOYEES = 0.0;
	NO_EMPLOYEES_SKILL_1 = 0.0;
	NO_EMPLOYEES_SKILL_2 = 0.0;
	NO_EMPLOYEES_SKILL_3 = 0.0;
	NO_EMPLOYEES_SKILL_4 = 0.0;
	NO_EMPLOYEES_SKILL_5 = 0.0;

	FIRM_AVERAGE_WAGE = 0.0;

	FIRM_AVERAGE_S_SKILL = 0.0;
	FIRM_AVERAGE_S_SKILL_1 = 0.0;
	FIRM_AVERAGE_S_SKILL_2 = 0.0;
	FIRM_AVERAGE_S_SKILL_3 = 0.0;
	FIRM_AVERAGE_S_SKILL_4 = 0.0;
	FIRM_AVERAGE_S_SKILL_5 = 0.0;


	/*delete the content of the data arrays in order to store the data for the new 			month*/
	//free(REGION_HOUSEHOLD_DATA);
	//free(REGION_FIRM_DATA);
	
	for(int j = 0; j < REGION_FIRM_DATA.size; j++)
	{
		remove_firm_data(&REGION_FIRM_DATA, j);
		j--;
	}
	
	for(int m = 0; m < REGION_HOUSEHOLD_DATA.size; m++)
	{
		remove_household_data(&REGION_HOUSEHOLD_DATA, m);
		m--;
	}


	for(int i = 1; i <= NO_REGIONS; i++)
	{
		add_firm_data(&REGION_FIRM_DATA,
		i,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		
		add_household_data(&REGION_HOUSEHOLD_DATA,
		i,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	}
	

	START_FIRM_SEND_DATA_MESSAGE_LOOP
	
		/*Store the region data of the firms*/
		for(int i = 0; i < REGION_FIRM_DATA.size; i++)
		{
			if(firm_send_data_message->region_id == 
		   	REGION_FIRM_DATA.array[i].region_id)
			{
				REGION_FIRM_DATA.array[i].firms += 1;
				NO_FIRMS++;

				REGION_FIRM_DATA.array[i].vacancies += 
					firm_send_data_message->vacancies;
				NO_VACANCIES += firm_send_data_message->vacancies;;

				REGION_FIRM_DATA.array[i].employees += 
					firm_send_data_message->employees;
				NO_EMPLOYEES += firm_send_data_message->employees;

				REGION_FIRM_DATA.array[i].employees_skill_1 += 
					firm_send_data_message->employees_skill_1;
				NO_EMPLOYEES_SKILL_1 += 
					firm_send_data_message->employees_skill_1;

				REGION_FIRM_DATA.array[i].employees_skill_2 += 
					firm_send_data_message->employees_skill_2;
				NO_EMPLOYEES_SKILL_2 += 
					firm_send_data_message->employees_skill_2;

				REGION_FIRM_DATA.array[i].employees_skill_3 += 
					firm_send_data_message->employees_skill_3;
				NO_EMPLOYEES_SKILL_3 += 
					firm_send_data_message->employees_skill_3;

				REGION_FIRM_DATA.array[i].employees_skill_4 += 
					firm_send_data_message->employees_skill_4;
				NO_EMPLOYEES_SKILL_4 += 
					firm_send_data_message->employees_skill_4;
		
				REGION_FIRM_DATA.array[i].employees_skill_5 += 
					firm_send_data_message->employees_skill_5;
				NO_EMPLOYEES_SKILL_5 += 
					firm_send_data_message->employees_skill_5;


				/********sum of wages of the firms++++++++*/
				REGION_FIRM_DATA.array[i].average_wage += 
					firm_send_data_message->average_wage*
					firm_send_data_message->employees;
				FIRM_AVERAGE_WAGE += firm_send_data_message->average_wage*
					firm_send_data_message->employees;


				/********sum of specific skills of the firms++++++++*/
				REGION_FIRM_DATA.array[i].average_s_skill += 
					firm_send_data_message->average_s_skill*
					firm_send_data_message->employees;
				FIRM_AVERAGE_S_SKILL += 
					firm_send_data_message->average_s_skill*
					firm_send_data_message->employees;


				REGION_FIRM_DATA.array[i].average_s_skill_1 +=
					firm_send_data_message->average_s_skill_1*
					firm_send_data_message->employees_skill_1;
				FIRM_AVERAGE_S_SKILL_1 +=
					firm_send_data_message->average_s_skill_1*
					firm_send_data_message->employees_skill_1;


				REGION_FIRM_DATA.array[i].average_s_skill_2 +=
					firm_send_data_message->average_s_skill_2*
					firm_send_data_message->employees_skill_2;
				FIRM_AVERAGE_S_SKILL_2 +=
					firm_send_data_message->average_s_skill_2*
					firm_send_data_message->employees_skill_2;

		
				REGION_FIRM_DATA.array[i].average_s_skill_3 +=
					firm_send_data_message->average_s_skill_3*
					firm_send_data_message->employees_skill_3;
				FIRM_AVERAGE_S_SKILL_3 +=
					firm_send_data_message->average_s_skill_3*
					firm_send_data_message->employees_skill_3;


				REGION_FIRM_DATA.array[i].average_s_skill_4 +=
					firm_send_data_message->average_s_skill_4*
					firm_send_data_message->employees_skill_4;
				FIRM_AVERAGE_S_SKILL_4 +=
					firm_send_data_message->average_s_skill_4*
					firm_send_data_message->employees_skill_4;

				
				REGION_FIRM_DATA.array[i].average_s_skill_5 +=
					firm_send_data_message->average_s_skill_5*
					firm_send_data_message->employees_skill_5;
				FIRM_AVERAGE_S_SKILL_5 +=
					firm_send_data_message->average_s_skill_5*
					firm_send_data_message->employees_skill_5;

			}
		}	

	FINISH_FIRM_SEND_DATA_MESSAGE_LOOP

   	/*Create the REGIONAL data which is needed for controlling the results or sending 			back to the Firms*/

	for(int i = 0; i < REGION_FIRM_DATA.size; i++)
	{
		/*********************WAGES************************/
		if(REGION_FIRM_DATA.array[i].employees > 0)
		{
			REGION_FIRM_DATA.array[i].average_wage = 
			REGION_FIRM_DATA.array[i].average_wage/
			REGION_FIRM_DATA.array[i].employees;
		}


		/*****************SPECIFIC SKILLS*********************/
		if(REGION_FIRM_DATA.array[i].employees > 0)
		{
			REGION_FIRM_DATA.array[i].average_s_skill =
			REGION_FIRM_DATA.array[i].average_s_skill/
			REGION_FIRM_DATA.array[i].employees;
		}

		if(REGION_FIRM_DATA.array[i].employees_skill_1 > 0)
		{
			REGION_FIRM_DATA.array[i].average_s_skill_1 =
			REGION_FIRM_DATA.array[i].average_s_skill_1/
			REGION_FIRM_DATA.array[i].employees_skill_1;
		}

		if(REGION_FIRM_DATA.array[i].employees_skill_2 > 0)
		{
			REGION_FIRM_DATA.array[i].average_s_skill_2 =
			REGION_FIRM_DATA.array[i].average_s_skill_2/
			REGION_FIRM_DATA.array[i].employees_skill_2;
		}


		if(REGION_FIRM_DATA.array[i].employees_skill_3 > 0)
		{
			REGION_FIRM_DATA.array[i].average_s_skill_3 =
			REGION_FIRM_DATA.array[i].average_s_skill_3/
			REGION_FIRM_DATA.array[i].employees_skill_3;
		}


		if(REGION_FIRM_DATA.array[i].employees_skill_4 > 0)
		{
			REGION_FIRM_DATA.array[i].average_s_skill_4 =
			REGION_FIRM_DATA.array[i].average_s_skill_4/
			REGION_FIRM_DATA.array[i].employees_skill_4;
		}

		if(REGION_FIRM_DATA.array[i].employees_skill_5 > 0)
		{
			REGION_FIRM_DATA.array[i].average_s_skill_5 =
			REGION_FIRM_DATA.array[i].average_s_skill_5/
			REGION_FIRM_DATA.array[i].employees_skill_5;
		}

   	}

	
	/*Create the GLOBAL data which is needed for controlling the results or sending 		back to the Households*/
	
	/*********************WAGES****************/
	if(NO_EMPLOYEES > 0)
	{
		FIRM_AVERAGE_WAGE = FIRM_AVERAGE_WAGE/(double)NO_EMPLOYEES;
	}

	
	/*****************SPECIFIC_SKILLS******************/
	if(NO_EMPLOYEES > 0)
	{
		FIRM_AVERAGE_S_SKILL = FIRM_AVERAGE_S_SKILL/(double)NO_EMPLOYEES;
	}

	if(NO_EMPLOYEES_SKILL_1 > 0)
	{
		FIRM_AVERAGE_S_SKILL_1 = FIRM_AVERAGE_S_SKILL_1/
					(double)NO_EMPLOYEES_SKILL_1;
	}

	if(NO_EMPLOYEES_SKILL_2 > 0)
	{
		FIRM_AVERAGE_S_SKILL_2 = FIRM_AVERAGE_S_SKILL_2/
					(double)NO_EMPLOYEES_SKILL_2;
	}

	if(NO_EMPLOYEES_SKILL_3 > 0)
	{
		FIRM_AVERAGE_S_SKILL_3 = FIRM_AVERAGE_S_SKILL_3/
					(double)NO_EMPLOYEES_SKILL_3;
	}

	if(NO_EMPLOYEES_SKILL_4 > 0)
	{
		FIRM_AVERAGE_S_SKILL_4 = FIRM_AVERAGE_S_SKILL_4/
					(double)NO_EMPLOYEES_SKILL_4;
	}

	if(NO_EMPLOYEES_SKILL_5 > 0)
	{
		FIRM_AVERAGE_S_SKILL_5 = FIRM_AVERAGE_S_SKILL_5/
					(double)NO_EMPLOYEES_SKILL_5;
	}

	
	



	START_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP

		/*Store the global/region data of the households*/
		for(int i = 0; i < REGION_HOUSEHOLD_DATA.size; i++)
		{
			if(household_send_data_message->region_id == 
		   	REGION_HOUSEHOLD_DATA.array[i].region_id)
			{

				if(DAY == 20)
				{
					NUM_HOUSEHOLDS++;
				}

				REGION_HOUSEHOLD_DATA.array[i].no_households++;

				REGION_HOUSEHOLD_DATA.array[i].average_wage +=
				household_send_data_message->wage;
				AVERAGE_WAGE = AVERAGE_WAGE + 
				household_send_data_message->wage;

				REGION_HOUSEHOLD_DATA.array[i].average_s_skill +=
				household_send_data_message->specific_skill;
				AVERAGE_S_SKILL = AVERAGE_S_SKILL + 
				household_send_data_message->specific_skill;

				/*(Region) data is subdivided by general skill level*/
				switch(household_send_data_message->general_skill)
				{  
			   	case 1:/*General skill level 1*/
				if(household_send_data_message->employment_status != -1)
				{
					REGION_HOUSEHOLD_DATA.array[i].employed++;
					REGION_HOUSEHOLD_DATA.array[i]
					.employed_skill_1++;
					EMPLOYED_SKILL_1++;
					EMPLOYED++;
				}
				else
				{
					REGION_HOUSEHOLD_DATA.array[i].unemployed++;
					UNEMPLOYED++;
				}

				if(DAY == 20)
				{	
					NO_HOUSEHOLDS_SKILL_1++;
				}

				REGION_HOUSEHOLD_DATA.array[i].no_households_skill_1++;

				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1 =
				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1 +
				household_send_data_message->wage;

				AVERAGE_WAGE_SKILL_1 = AVERAGE_WAGE_SKILL_1 + 
				household_send_data_message->wage;

				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1 =
				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1 +
				household_send_data_message->specific_skill;

				AVERAGE_S_SKILL_1 = AVERAGE_S_SKILL_1 + 
				household_send_data_message->specific_skill;
				break;

			   	case 2:/*General skill level 2*/
				if(household_send_data_message->employment_status != -1)
				{
					REGION_HOUSEHOLD_DATA.array[i].employed++;
					REGION_HOUSEHOLD_DATA.array[i]
					.employed_skill_2++;
					EMPLOYED_SKILL_2++;
					EMPLOYED++;
				}
				else
				{
					REGION_HOUSEHOLD_DATA.array[i].unemployed++;
					UNEMPLOYED++;
				}		
		
				if(DAY == 20)
				{	
					NO_HOUSEHOLDS_SKILL_2++;
				}
				
				REGION_HOUSEHOLD_DATA.array[i].no_households_skill_2++;
				
				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2 =
				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2 +
				household_send_data_message->wage;

				AVERAGE_WAGE_SKILL_2 = AVERAGE_WAGE_SKILL_2 + 
				household_send_data_message->wage;

				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2 =
				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2 +
				household_send_data_message->specific_skill;

				AVERAGE_S_SKILL_2 = AVERAGE_S_SKILL_2 + 
				household_send_data_message->specific_skill;
				break;

			   	case 3:/*General skill level 3*/
				if(household_send_data_message->employment_status != -1)
				{
					REGION_HOUSEHOLD_DATA.array[i].employed++;
					REGION_HOUSEHOLD_DATA.array[i]
					.employed_skill_3++;
					EMPLOYED_SKILL_3++;
					EMPLOYED++;
				}
				else
				{
					REGION_HOUSEHOLD_DATA.array[i].unemployed++;
					UNEMPLOYED++;
				}
		
				if(DAY == 20)
				{
					NO_HOUSEHOLDS_SKILL_3++;
				}

				REGION_HOUSEHOLD_DATA.array[i].no_households_skill_3++;

				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3 =
				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3 +
				household_send_data_message->wage;

				AVERAGE_WAGE_SKILL_3 = AVERAGE_WAGE_SKILL_3 + 
				household_send_data_message->wage;

				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3 =
				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3 +
				household_send_data_message->specific_skill;

				AVERAGE_S_SKILL_3 = AVERAGE_S_SKILL_3 + 
				household_send_data_message->specific_skill;
				break;

			   	case 4:/*General skill level 4*/
				if(household_send_data_message->employment_status != -1)
				{
					REGION_HOUSEHOLD_DATA.array[i].employed++;
					REGION_HOUSEHOLD_DATA.array[i]
					.employed_skill_4++;
					EMPLOYED_SKILL_4++;
					EMPLOYED++;
				}
				else
				{
					REGION_HOUSEHOLD_DATA.array[i].unemployed++;
					UNEMPLOYED++;
				}
				
				if(DAY == 20)
				{
					NO_HOUSEHOLDS_SKILL_4++;
				}

				REGION_HOUSEHOLD_DATA.array[i].no_households_skill_4++;

				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4 =
				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4 +
				household_send_data_message->wage;

				AVERAGE_WAGE_SKILL_4 = AVERAGE_WAGE_SKILL_4 + 
				household_send_data_message->wage;

				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4 =
				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4 +
				household_send_data_message->specific_skill;

				AVERAGE_S_SKILL_4 = AVERAGE_S_SKILL_4 + 
				household_send_data_message->specific_skill;
				break;
			
			   	case 5:/*General skill level 5*/
				if(household_send_data_message->employment_status != -1)
				{
					REGION_HOUSEHOLD_DATA.array[i].employed++;
					REGION_HOUSEHOLD_DATA.array[i]
					.employed_skill_5++;
					EMPLOYED_SKILL_5++;
					EMPLOYED++;
				}
				else
				{
					REGION_HOUSEHOLD_DATA.array[i].unemployed++;
					UNEMPLOYED++;
				}
	
				if(DAY == 20)
				{
					NO_HOUSEHOLDS_SKILL_5++;
				}

				REGION_HOUSEHOLD_DATA.array[i].no_households_skill_5++;

				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5 =
				REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5 +
				household_send_data_message->wage;

				AVERAGE_WAGE_SKILL_5 = AVERAGE_WAGE_SKILL_5 + 
				household_send_data_message->wage;

				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5 =
				REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5 +
				household_send_data_message->specific_skill;

				AVERAGE_S_SKILL_5 = AVERAGE_S_SKILL_5 + 
				household_send_data_message->specific_skill;
				break;
				}
			}
		}

	FINISH_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP

	/*Create the REGIONAL data which is needed for controlling the results or sending 			back to the Households*/
	for(int i = 0; i < REGION_HOUSEHOLD_DATA.size; i++)
	{

		/**************UNEMPLOYMENT-RATE******************/
		REGION_HOUSEHOLD_DATA.array[i].unemployment_rate = 
		1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed/
		(double)REGION_HOUSEHOLD_DATA.array[i].no_households;

		REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_1 =
		1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_1/
		(double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_1;

		REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_2 =
		1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_2/
		(double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_2;

		REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_3 =
		1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_3/
		(double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_3;

		REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_4 =
		1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_4/
		(double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_4;

		REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_5 =
		1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_5/
		(double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_5;
	

	
		/*******************WAGES*************************/
		if(REGION_HOUSEHOLD_DATA.array[i].employed > 0)
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage = 
			REGION_HOUSEHOLD_DATA.array[i].average_wage/
			REGION_HOUSEHOLD_DATA.array[i].employed;
		}
		else
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage = 0;
		}

		if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_1 > 0)
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1 = 
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1/
			REGION_HOUSEHOLD_DATA.array[i].employed_skill_1;
		}
		else
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1 = 0;
		}	

		if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_2 > 0)
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2 = 
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2/
			REGION_HOUSEHOLD_DATA.array[i].employed_skill_2;
		}
		else
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2 = 0;
		}

		if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_3 > 0)
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3 = 
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3/
			REGION_HOUSEHOLD_DATA.array[i].employed_skill_3;
		}
		else
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3 = 0;
		}

		if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_4 > 0)
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4 = 
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4/
			REGION_HOUSEHOLD_DATA.array[i].employed_skill_4;
		}
		else
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4 = 0;
		}

		if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_5 > 0)
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5 = 
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5/
			REGION_HOUSEHOLD_DATA.array[i].employed_skill_5;
		}
		else
		{
			REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5 = 0;
		}

		/*******************SPECIFIC SKILLS**********************/
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill = 
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill/
		REGION_HOUSEHOLD_DATA.array[i].no_households;

		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1 =
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1/
		REGION_HOUSEHOLD_DATA.array[i].no_households_skill_1;

		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2 =
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2/
		REGION_HOUSEHOLD_DATA.array[i].no_households_skill_2;

		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3 =
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3/
		REGION_HOUSEHOLD_DATA.array[i].no_households_skill_3;

		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4 =
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4/
		REGION_HOUSEHOLD_DATA.array[i].no_households_skill_4;
	
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5 =
		REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5/
		REGION_HOUSEHOLD_DATA.array[i].no_households_skill_5;	
	}



	/*Create the GLOBAL data which is needed for controlling the results or sending 		back to the Households*/

	/*******************UNEMPLOYMENT RATE**********************/
	UNEMPLOYMENT_RATE = 1 - (double)EMPLOYED/(double)NUM_HOUSEHOLDS;
	UNEMPLOYMENT_RATE_SKILL_1 = 1 - (double)EMPLOYED_SKILL_1/
					(double)NO_HOUSEHOLDS_SKILL_1;
	UNEMPLOYMENT_RATE_SKILL_2 = 1 - (double)EMPLOYED_SKILL_2/
					(double)NO_HOUSEHOLDS_SKILL_2;
	UNEMPLOYMENT_RATE_SKILL_3 = 1 - (double)EMPLOYED_SKILL_3/
					(double)NO_HOUSEHOLDS_SKILL_3;
	UNEMPLOYMENT_RATE_SKILL_4 = 1 - (double)EMPLOYED_SKILL_4/
					(double)NO_HOUSEHOLDS_SKILL_4;
	UNEMPLOYMENT_RATE_SKILL_5 = 1 - (double)EMPLOYED_SKILL_5/
					(double)NO_HOUSEHOLDS_SKILL_5;


	/*******************WAGES**********************/

	if(EMPLOYED > 0)
	{
		AVERAGE_WAGE = AVERAGE_WAGE/(double)EMPLOYED;
	}
	else
	{
		AVERAGE_WAGE = 0;
	}

	if(EMPLOYED_SKILL_1 > 0)
	{
		AVERAGE_WAGE_SKILL_1 = AVERAGE_WAGE_SKILL_1/(double)EMPLOYED_SKILL_1;
	}
	else
	{
		AVERAGE_WAGE_SKILL_1 = 0;
	}

	if(EMPLOYED_SKILL_2 > 0)
	{
		AVERAGE_WAGE_SKILL_2 = AVERAGE_WAGE_SKILL_2/(double)EMPLOYED_SKILL_2;
	}
	else
	{
		AVERAGE_WAGE_SKILL_2 = 0;
	}

	if(EMPLOYED_SKILL_3 > 0)
	{
		AVERAGE_WAGE_SKILL_3 = AVERAGE_WAGE_SKILL_3/(double)EMPLOYED_SKILL_3;
	}
	else
	{
		AVERAGE_WAGE_SKILL_3 = 0;
	}

	if(EMPLOYED_SKILL_4 > 0)
	{
		AVERAGE_WAGE_SKILL_4 = AVERAGE_WAGE_SKILL_4/(double)EMPLOYED_SKILL_4;
	}
	else
	{
		AVERAGE_WAGE_SKILL_4 = 0;
	}

	if(EMPLOYED_SKILL_5 > 0)
	{
		AVERAGE_WAGE_SKILL_5 = AVERAGE_WAGE_SKILL_5/(double)EMPLOYED_SKILL_5;
	}
	else
	{
		AVERAGE_WAGE_SKILL_5 = 0;
	}


	/*******************SPECIFIC SKILLS**********************/
	AVERAGE_S_SKILL = AVERAGE_S_SKILL/(double)NUM_HOUSEHOLDS;
	AVERAGE_S_SKILL_1 = AVERAGE_S_SKILL_1/(double)NO_HOUSEHOLDS_SKILL_1;
	AVERAGE_S_SKILL_2 = AVERAGE_S_SKILL_2/(double)NO_HOUSEHOLDS_SKILL_2;
	AVERAGE_S_SKILL_3 = AVERAGE_S_SKILL_3/(double)NO_HOUSEHOLDS_SKILL_3;
	AVERAGE_S_SKILL_4 = AVERAGE_S_SKILL_4/(double)NO_HOUSEHOLDS_SKILL_4;
	AVERAGE_S_SKILL_5 = AVERAGE_S_SKILL_5/(double)NO_HOUSEHOLDS_SKILL_5;

	return 0;
}

/** \fn Eurostat_read_tax_rates()
 * \brief Eurostat reads tax_rates_msg from all governments and stores this data.
 */
int Eurostat_read_tax_rates()
{
	START_GOVERNMENT_TAX_RATES_MESSAGE_LOOP
	for (i=0; i<GOVERNMENT_TAX_RATES.size; i++)
	{
		if(government_tax_rates_message->gov_id == GOVERNMENT_TAX_RATES.array[i].id)
		{
			GOVERNMENT_TAX_RATES.array[i].tax_rate_corporate = government_tax_rates_message->tax_rate_corporate;
			GOVERNMENT_TAX_RATES.array[i].tax_rate_hh_labour = government_tax_rates_message->tax_rate_hh_labour;
			GOVERNMENT_TAX_RATES.array[i].tax_rate_hh_capital = government_tax_rates_message->tax_rate_hh_capital;
			GOVERNMENT_TAX_RATES.array[i].tax_rate_vat = government_tax_rates_message->tax_rate_vat;
			break;
		}
	}
	FINISH_GOVERNMENT_TAX_RATES_MESSAGE_LOOP
	
	return 0;
}
