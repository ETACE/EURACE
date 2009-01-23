/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

int Household_Household_idle_start_Household_01_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Household_Household_read_policy_announcements_start_Household_01_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Household_Household_idle_04_end_Household_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_receive_income)) return 1;
	else return 0;
}

int Household_Household_send_unemployment_benefit_notification_04_end_Household_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == a->day_of_month_receive_income)) return 1;
	else return 0;
}

int Firm_Firm_idle_start_Firm_01_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Firm_Firm_read_policy_announcements_start_Firm_01_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Government_Government_idle_start_Government_01_condition(xmachine_memory_Government *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Government_Government_send_policy_announcements_start_Government_01_condition(xmachine_memory_Government *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Government_Government_read_tax_payments_tax_payment_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_tax_payment *m = (m_tax_payment*)msg;
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	if((a->id == m->gov_id)) return 1;
	else return 0;
}

int Government_Government_read_subsidy_notifications_hh_subsidy_notification_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_hh_subsidy_notification *m = (m_hh_subsidy_notification*)msg;
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	if((a->id == m->gov_id)) return 1;
	else return 0;
}

int Government_Government_read_subsidy_notifications_firm_subsidy_notification_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_firm_subsidy_notification *m = (m_firm_subsidy_notification*)msg;
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	if((a->id == m->gov_id)) return 1;
	else return 0;
}

int Government_Government_read_transfer_notifications_hh_transfer_notification_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_hh_transfer_notification *m = (m_hh_transfer_notification*)msg;
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	if((a->id == m->gov_id)) return 1;
	else return 0;
}

int Government_Government_read_transfer_notifications_firm_transfer_notification_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_firm_transfer_notification *m = (m_firm_transfer_notification*)msg;
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	if((a->id == m->gov_id)) return 1;
	else return 0;
}

int Government_Government_read_unemployment_benefit_notifications_unemployment_notification_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_unemployment_notification *m = (m_unemployment_notification*)msg;
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	if((a->id == m->gov_id)) return 1;
	else return 0;
}

int Government_Government_idle_Gov_Start_Monthly_Loop_Gov_Start_Yearly_Loop_condition(xmachine_memory_Government *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Government_Government_monthly_budget_accounting_Gov_Start_Monthly_Loop_05_condition(xmachine_memory_Government *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Government_idle_Gov_Start_Yearly_Loop_end_Government_condition(xmachine_memory_Government *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_07_condition(xmachine_memory_Government *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}
