/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

int Firm_Firm_ask_loan_Start_Firm_Credit_Role_Firm_Credit_02_condition(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0.0)) return 1;
	else return 0;
}

int Firm_Firm_get_loan_loan_conditions_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_loan_conditions *m = (m_loan_conditions*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->id == m->firm_id)) return 1;
	else return 0;
}

int Firm_Firm_idle_End_Firm_Financial_Role_Firm_bankruptcy_checked_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_compute_balance_sheet_current_mall_stock_info_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_current_mall_stock_info *m = (m_current_mall_stock_info*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->id == m->firm_id)) return 1;
	else return 0;
}

int Firm_Firm_compute_and_send_stock_orders_Firm_End_Credit_Role_0003_condition(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0.0)) return 1;
	else return 0;
}

int Firm_Firm_read_stock_transactions_order_status_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_order_status *m = (m_order_status*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->id == m->trader_id)) return 1;
	else return 0;
}

int Firm_Firm_check_financial_and_bankruptcy_state_End_Firm_Financial_Role_f1_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_in_bankruptcy_Firm_bankruptcy_checked_end_Firm_dies_condition(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_state == 1)) return 1;
	else return 0;
}

int Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_not_in_bankruptcy_state_now_check_financial_crisis_condition(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_state == 0)) return 1;
	else return 0;
}

int Firm_Firm_in_financial_crisis_function_Firm_not_in_bankruptcy_state_now_check_financial_crisis_Firm_financial_crisis_ok_condition(xmachine_memory_Firm *a)
{
	if((a->financial_crisis_state == 1)) return 1;
	else return 0;
}

int Firm_Firm_idle_Firm_not_in_bankruptcy_state_now_check_financial_crisis_Firm_financial_crisis_ok_condition(xmachine_memory_Firm *a)
{
	if((a->financial_crisis_state == 0)) return 1;
	else return 0;
}

int Firm_idle_Start_Firm_Credit_Role_Start_Firm_Labour_Role_condition(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0)) return 1;
	else return 0;
}

int Firm_idle_Firm_End_Credit_Role_Start_Firm_Labour_Role_condition(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0)) return 1;
	else return 0;
}

int Bank_Bank_decide_credit_conditions_loan_request_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_loan_request *m = (m_loan_request*)msg;
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	if((a->id == m->bank_id)) return 1;
	else return 0;
}

int Bank_Bank_give_loan_loan_acceptance_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_loan_acceptance *m = (m_loan_acceptance*)msg;
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	if((a->id == m->bank_id)) return 1;
	else return 0;
}

int Bank_Bank_receive_installment_installment_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_installment *m = (m_installment*)msg;
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	if((a->id == m->bank_id)) return 1;
	else return 0;
}

int Bank_Bank_receive_installment_bankruptcy_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_bankruptcy *m = (m_bankruptcy*)msg;
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	if((a->id == m->bank_id)) return 1;
	else return 0;
}

int Bank_Bank_account_update_deposits_bank_account_update_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_bank_account_update *m = (m_bank_account_update*)msg;
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	if((a->id == m->bank_id)) return 1;
	else return 0;
}

int Bank_Bank_accounting_Bank_05_end_Bank_cycle_condition(xmachine_memory_Bank *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Bank_Bank_idle_Bank_05_end_Bank_cycle_condition(xmachine_memory_Bank *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}
