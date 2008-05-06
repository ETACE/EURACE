/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

int Bank_Bank_accounting_04_05_condition(xmachine_memory_Bank *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Bank_Bank_idle_04_05_condition(xmachine_memory_Bank *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}
