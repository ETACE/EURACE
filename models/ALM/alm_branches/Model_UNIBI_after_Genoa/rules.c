/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

int Firm_Firm_set_quantities_zero_00_00b_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_calc_production_quantity_2_End_Firm_Credit_Role_Firm_Finish_Finacial_Management_condition(xmachine_memory_Firm *a)
{
	if(!(a->financial_resources_for_production >= a->planned_production_costs)) return 1;
	else return 0;
}

int Firm_Firm_idle_End_Firm_Credit_Role_Firm_Finish_Finacial_Management_condition(xmachine_memory_Firm *a)
{
	if((a->financial_resources_for_production >= a->planned_production_costs)) return 1;
	else return 0;
}

int Firm_Firm_receive_capital_goods_capital_good_delivery_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_capital_good_delivery *m = (m_capital_good_delivery*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->id == m->firm_id)) return 1;
	else return 0;
}

int Firm_Firm_calc_revenue_sales_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_sales *m = (m_sales*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->id == m->firm_id)) return 1;
	else return 0;
}

int Firm_Firm_compute_sales_statitics_13b_13c_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_update_specific_skills_of_workers_13c_14_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_update_specific_skills_of_workers_specific_skill_update_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_specific_skill_update *m = (m_specific_skill_update*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->id == m->firm_id)) return 1;
	else return 0;
}

int Firm_Firm_idle_13b_14_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_apply_for_loans_Start_Firm_Credit_Role_21_condition(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0.0)) return 1;
	else return 0;
}

int Firm_Firm_read_loan_acceptance_loan_acceptance_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_loan_acceptance *m = (m_loan_acceptance*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->id == m->firm_id)) return 1;
	else return 0;
}

int Firm_Firm_idle_Start_Firm_Credit_Role_Firm_Finish_Finacial_Management_condition(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0)) return 1;
	else return 0;
}

int Firm_Firm_compute_financial_payments_00_001_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_send_vacancies_Start_Firm_Labour_Role_03_condition(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_send_redundancies_Start_Firm_Labour_Role_03c_condition(xmachine_memory_Firm *a)
{
	if((a->no_employees > a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_idle_Start_Firm_Labour_Role_03c_condition(xmachine_memory_Firm *a)
{
	if((a->no_employees == a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_start_labour_market_03d_06_condition(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_finish_labour_market_first_round_03d_09a_condition(xmachine_memory_Firm *a)
{
	if(!(a->no_employees < a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_finish_labour_market_first_round_05b_09a_condition(xmachine_memory_Firm *a)
{
	if((a->no_employees == a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_update_wage_offer_05b_06_condition(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_update_wage_offer_2_09b_10_condition(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_idle_09b_10_condition(xmachine_memory_Firm *a)
{
	if(!(a->no_employees < a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_idle_start_Firm_Start_Firm_Macro_Data_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Firm_Firm_read_tax_rates_start_Firm_Start_Firm_Macro_Data_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Firm_Firm_receive_data_Start_Firm_Macro_Data_00_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Firm_Firm_idle_Start_Firm_Macro_Data_00_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Firm_Firm_send_data_to_Eurostat_14_15_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 19)) return 1;
	else return 0;
}

int Firm_Firm_idle_14_15_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == 19)) return 1;
	else return 0;
}

int Household_Household_idle_06b_09_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_receive_income)) return 1;
	else return 0;
}

int Household_Household_idle_06b_06c_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == a->day_of_month_receive_income)) return 1;
	else return 0;
}

int Household_Household_receive_wage_06c_07_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}

int Household_Household_receive_wage_wage_payment_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_wage_payment *m = (m_wage_payment*)msg;
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	if((a->id == m->worker_id)) return 1;
	else return 0;
}

int Household_Household_receive_unemployment_benefits_06c_08_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}

int Household_Household_receive_unemployment_benefits_unemployment_benefit_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_unemployment_benefit *m = (m_unemployment_benefit*)msg;
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

int Household_Household_idle_09_15_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}

int Household_Household_rank_and_buy_goods_1_09_10_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}

int Household_Household_rank_and_buy_goods_1_quality_price_info_1_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_quality_price_info_1 *m = (m_quality_price_info_1*)msg;
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	if((a->region_id == m->mall_region_id)) return 1;
	else return 0;
}

int Household_Household_receive_goods_read_rationing_accepted_consumption_1_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_accepted_consumption_1 *m = (m_accepted_consumption_1*)msg;
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	if((a->id == m->household_id)) return 1;
	else return 0;
}

int Household_Household_set_values_zero_11_14_condition(xmachine_memory_Household *a)
{
	if((a->rationed != 1)) return 1;
	else return 0;
}

int Household_Household_rank_and_buy_goods_2_11_12_condition(xmachine_memory_Household *a)
{
	if((a->rationed == 1)) return 1;
	else return 0;
}

int Household_Household_rank_and_buy_goods_2_quality_price_info_2_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_quality_price_info_2 *m = (m_quality_price_info_2*)msg;
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	if((a->region_id == m->mall_region_id)) return 1;
	else return 0;
}

int Household_Household_receive_goods_read_rationing_2_accepted_consumption_2_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_accepted_consumption_2 *m = (m_accepted_consumption_2*)msg;
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	if((a->id == m->household_id)) return 1;
	else return 0;
}

int Household_Household_read_firing_messages_Start_Household_Labour_Role_01d_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}

int Household_Household_idle_01d_01a_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}

int Household_Household_idle_Start_Household_Labour_Role_01a_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}

int Household_Household_on_the_job_search_decision_01d_01b_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}

int Household_Household_OTJS_read_job_vacancies_and_send_applications_01b_01_condition(xmachine_memory_Household *a)
{
	if((a->on_the_job_search == 1)) return 1;
	else return 0;
}

int Household_Household_idle_01b_06_condition(xmachine_memory_Household *a)
{
	if((a->on_the_job_search != 1)) return 1;
	else return 0;
}

int Household_Household_finish_labour_market_02_06_condition(xmachine_memory_Household *a)
{
	if(((a->employee_firm_id != -1) && (a->on_the_job_search != 1))) return 1;
	else return 0;
}

int Household_Household_read_application_rejection_update_wage_reservation_02_03_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}

int Household_Household_OTJS_read_job_vacancies_and_send_applications_2_02_04_condition(xmachine_memory_Household *a)
{
	if((a->on_the_job_search == 1)) return 1;
	else return 0;
}

int Household_Household_read_application_rejection_update_wage_reservation_2_05_06_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}

int Household_Household_idle_05_06_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}

int Household_Household_idle_start_Household_Start_Household_Tax_Data_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Household_Household_read_tax_rates_start_Household_Start_Household_Tax_Data_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Household_Household_receive_data_Start_Household_Tax_Data_Start_Household_Labour_Role_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Household_Household_idle_Start_Household_Tax_Data_Start_Household_Labour_Role_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Household_Household_send_data_to_Eurostat_15_end_Household_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 19)) return 1;
	else return 0;
}

int Household_Household_idle_15_end_Household_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 19)) return 1;
	else return 0;
}

int Mall_Mall_update_mall_stock_update_mall_stock_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_update_mall_stock *m = (m_update_mall_stock*)msg;
	xmachine_memory_Mall *a = (xmachine_memory_Mall *)params;

	if((a->id == m->mall_id)) return 1;
	else return 0;
}

int Mall_Mall_update_mall_stocks_sales_rationing_1_consumption_request_1_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_consumption_request_1 *m = (m_consumption_request_1*)msg;
	xmachine_memory_Mall *a = (xmachine_memory_Mall *)params;

	if((a->id == m->mall_id)) return 1;
	else return 0;
}

int Mall_Mall_update_mall_stocks_sales_rationing_2_consumption_request_2_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_consumption_request_2 *m = (m_consumption_request_2*)msg;
	xmachine_memory_Mall *a = (xmachine_memory_Mall *)params;

	if((a->id == m->mall_id)) return 1;
	else return 0;
}

int IGFirm_IGFirm_update_productivity_price_Start_IGFirm_Productivity_01_condition(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int IGFirm_IGFirm_idle_Start_IGFirm_Productivity_01_condition(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int IGFirm_IGFirm_pay_taxes_04_04b_condition(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int IGFirm_IGFirm_dividend_payment_04b_end_IGFirm_condition(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int IGFirm_IGFirm_idle_04_end_IGFirm_condition(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int IGFirm_IGFirm_idle_start_IGFirm_Start_IGFirm_Productivity_condition(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}

int IGFirm_IGFirm_read_tax_rates_start_IGFirm_Start_IGFirm_Productivity_condition(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Eurostat_Eurostat_Initialization_start_Eurostat_Start_Eurostat_Tax_Data_condition(xmachine_memory_Eurostat *a)
{
	if((iteration_loop == 1)) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_start_Eurostat_Start_Eurostat_Tax_Data_condition(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop == 1)) return 1;
	else return 0;
}

int Eurostat_Eurostat_read_tax_rates_Start_Eurostat_Tax_Data_Start_Eurostat_Firm_Data_condition(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_Start_Eurostat_Tax_Data_Start_Eurostat_Firm_Data_condition(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Eurostat_Eurostat_send_data_Start_Eurostat_Firm_Data_01_condition(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_Start_Eurostat_Firm_Data_01_condition(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Eurostat_Eurostat_calculate_data_01_end_Eurostat_condition(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%20 == 19)) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_01_end_Eurostat_condition(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%20 == 19)) return 1;
	else return 0;
}

int Government_Government_idle_start_Government_00_condition(xmachine_memory_Government *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Government_Government_send_tax_rates_start_Government_00_condition(xmachine_memory_Government *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Government_Government_idle_00_01_condition(xmachine_memory_Government *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Government_Government_read_tax_payment_tax_payment_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_tax_payment *m = (m_tax_payment*)msg;
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	if((a->id == m->gov_id)) return 1;
	else return 0;
}
