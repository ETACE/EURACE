#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"


/* Function condition functions */

int Firm_day_of_month_to_act()
{
	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT) return 1;
	else return 0;
}

int Firm_not_day_of_month_to_act()
{
	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT) return 0;
	else return 1;
}

int Firm_idle()
{
	return 0;
}


int Firm_is_external_financial_needs()
{
	if(EXTERNAL_FINANCIAL_NEEDS > pow(10,-5) ) return 1;
	else return 0;
}

int Firm_no_external_financial_needs()
{
	if(EXTERNAL_FINANCIAL_NEEDS > pow(10,-5) ) return 0;
	else return 1;
}
