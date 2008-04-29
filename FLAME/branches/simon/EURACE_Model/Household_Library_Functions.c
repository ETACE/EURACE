#include "header.h"
#include "Household_agent_header.h"
#include "my_library_header.h"

int Household_is_employed()
{
	if(EMPLOYEE_FIRM_ID > -1) return 1;
	else return 0;
}

int Household_is_unemployed()
{
	if(EMPLOYEE_FIRM_ID == -1) return 1;
	else return 0;
}

int Household_on_the_job_search_no()
{
	if(ON_THE_JOB_SEARCH == 0) return 1;
	else return 0;
}

int Household_on_the_job_search_yes()
{
	if(ON_THE_JOB_SEARCH == 1) return 1;
	else return 0;
}

int Household_is_employed_and_on_the_job_search_no()
{
	if(EMPLOYEE_FIRM_ID > -1 && ON_THE_JOB_SEARCH == 0) return 1;
	else return 0;
}

int Household_is_unemployed_or_on_the_job_search_yes()
{
	if(EMPLOYEE_FIRM_ID == -1 || ON_THE_JOB_SEARCH == 1) return 1;
	else return 0;
}




int Household_finish_labour_market()
{
	return 0;
}

int Household_made_unemployed()
{
	return 0;
}

int Household_day_of_month_receive_income_employed()
{
	if (DAY%MONTH == DAY_OF_MONTH_RECEIVE_INCOME && EMPLOYEE_FIRM_ID != -1)
		return 1;
	else
		return 0;
	
}

int Household_rationed()
{
	if (RATIONED==1)
		return 1;
	else
		return 0;
	
}

int Household_not_rationed()
{
	if (RATIONED!=1)
		return 1;
	else
		return 0;
	
}


int Household_day_of_month_receive_income_unemployed()
{
	if (DAY%MONTH==DAY_OF_MONTH_RECEIVE_INCOME&&EMPLOYEE_FIRM_ID==-1)
		return 1;
	else
		return 0;
	
}

int Household_not_day_of_month_receive_income()
{
	if (DAY%MONTH==DAY_OF_MONTH_RECEIVE_INCOME)
		return 0;
	else
		return 1;
	
}

int Household_day_of_week_to_act()
{
	if (DAY%MONTH==DAY_OF_MONTH_TO_ACT)
		return 1;
	else
		return 0;
	
}
int Household_not_day_of_week_to_act()
{
	if (DAY%MONTH==DAY_OF_MONTH_TO_ACT)
		return 0;
	else
		return 1;
	
}


int Household_idle()
{
	return 0;
}
