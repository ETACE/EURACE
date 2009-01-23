/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

int Firm_Firm_calc_production_quantity_Firm_Start_Producer_Role_01_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_set_quantities_zero_Firm_Start_Producer_Role_00b_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
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

int Firm_idle_14_Firm_End_Financial_Management_Role_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->last_day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_compute_sales_statistics_14_Firm_Start_Financial_Management_Role_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->last_day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_condition(xmachine_memory_Firm *a)
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

int Firm_idle_Firm_End_Seller_Role_14_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}

int Firm_Firm_ask_loan_Firm_Start_Credit_Role_Firm_Credit_02_condition(xmachine_memory_Firm *a)
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

int Firm_Firm_set_bankruptcy_insolvency_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role_condition(xmachine_memory_Firm *a)
{
	if((a->equity < 0.0)) return 1;
	else return 0;
}

int Firm_idle_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role_condition(xmachine_memory_Firm *a)
{
	if((a->equity >= 0.0)) return 1;
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

int Firm_Firm_set_bankruptcy_illiquidity_Firm_bankruptcy_checked_Firm_End_Financial_Management_Role_condition(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_illiquidity_state == 1)) return 1;
	else return 0;
}

int Firm_Firm_in_financial_crisis_Firm_checks_financial_crisis_Firm_End_External_Financing_condition(xmachine_memory_Firm *a)
{
	if((a->financial_crisis_state == 1)) return 1;
	else return 0;
}

int Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_checks_financial_crisis_condition(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_illiquidity_state == 0)) return 1;
	else return 0;
}

int Firm_idle_Firm_checks_financial_crisis_Firm_End_External_Financing_condition(xmachine_memory_Firm *a)
{
	if((a->financial_crisis_state == 0)) return 1;
	else return 0;
}

int Firm_idle_Firm_Start_Credit_Role_Firm_End_External_Financing_condition(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0)) return 1;
	else return 0;
}

int Firm_idle_Firm_End_Credit_Role_Firm_End_External_Financing_condition(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0)) return 1;
	else return 0;
}

int Firm_Firm_bankruptcy_insolvency_procedure_Firm_not_active_Firm_bankrupty_state_1_condition(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_insolvency_state == 1)) return 1;
	else return 0;
}

int Firm_Firm_bankruptcy_illiquidity_procedure_Firm_not_active_Firm_bankrupty_state_1_condition(xmachine_memory_Firm *a)
{
	if(((a->bankruptcy_illiquidity_state == 1) && (a->bankruptcy_insolvency_state == 0))) return 1;
	else return 0;
}

int Firm_Firm_bankruptcy_idle_counter_start_Firm_Firm_not_active_condition(xmachine_memory_Firm *a)
{
	if((a->active == 0)) return 1;
	else return 0;
}

int Firm_idle_start_Firm_Firm_is_active_condition(xmachine_memory_Firm *a)
{
	if((a->active == 1)) return 1;
	else return 0;
}

int Firm_Firm_compute_and_send_stock_orders_Firm_bankrupty_state_1_Firm_bankrupty_state_2_condition(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0.0)) return 1;
	else return 0;
}

int Firm_idle_Firm_bankrupty_state_1_Firm_bankrupty_state_3_condition(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs <= 0.0)) return 1;
	else return 0;
}

int Firm_Firm_receive_stock_info_infoAssetCH_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_infoAssetCH *m = (m_infoAssetCH*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->id == m->asset_id)) return 1;
	else return 0;
}

int Firm_Firm_send_vacancies_011_03_condition(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_send_redundancies_011_03c_condition(xmachine_memory_Firm *a)
{
	if((a->no_employees > a->employees_needed)) return 1;
	else return 0;
}

int Firm_Firm_idle_011_03c_condition(xmachine_memory_Firm *a)
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

int Firm_idle_Firm_is_active_Firm_Start_Macro_Data_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Firm_Firm_read_policy_announcements_policy_announcement_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

int Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}

int Firm_Firm_receive_data_eurostat_send_specific_skills_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_eurostat_send_specific_skills *m = (m_eurostat_send_specific_skills*)msg;
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	if((a->region_id == m->region_id)) return 1;
	else return 0;
}

int Firm_idle_Firm_Start_Macro_Data_Firm_End_Macro_Data_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}

int Firm_Firm_send_data_to_Eurostat_Firm_End_Financial_Management_Role_15_condition(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Firm_idle_Firm_End_Financial_Management_Role_15_condition(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
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

int Household_Household_stock_beliefs_formation_CHOOSE_TO_TRADE_OR_NOT_BOND_BELIEF_FORMATION_condition(xmachine_memory_Household *a)
{
	if((a->strategy != 0)) return 1;
	else return 0;
}

int Household_Household_bond_beliefs_formation_BOND_BELIEF_FORMATION_SEND_ORDERS_condition(xmachine_memory_Household *a)
{
	if((a->strategy != 0)) return 1;
	else return 0;
}

int Household_Household_does_not_trading_CHOOSE_TO_TRADE_OR_NOT_Household_Start_Labour_Role_condition(xmachine_memory_Household *a)
{
	if((a->strategy == 0)) return 1;
	else return 0;
}

int Household_Household_update_its_portfolio_order_status_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_order_status *m = (m_order_status*)msg;
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	if((a->id == m->trader_id)) return 1;
	else return 0;
}

int Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}

int Household_Household_idle_01d_01a_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}

int Household_Household_idle_Household_Start_Labour_Role_01a_condition(xmachine_memory_Household *a)
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

int Household_Household_receive_wage_06e_07_condition(xmachine_memory_Household *a)
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

int Household_Household_send_unemployment_benefit_notification_06e_08_condition(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}

int Household_Household_idle_start_Household_Household_Start_Policy_Data_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Household_Household_read_policy_announcements_policy_announcement_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

int Household_Household_receive_data_Household_Start_Policy_Data_Household_Start_Financial_Market_Role_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}

int Household_Household_idle_Household_Start_Policy_Data_Household_Start_Financial_Market_Role_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}

int Household_Household_send_data_to_Eurostat_15_end_Household_condition(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Household_Household_idle_15_end_Household_condition(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Mall_Mall_reset_export_data_start_Mall_01_condition(xmachine_memory_Mall *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}

int Mall_idle_start_Mall_01_condition(xmachine_memory_Mall *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
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

int Mall_Mall_send_export_data_06_end_Mall_condition(xmachine_memory_Mall *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}

int Mall_idle_06_end_Mall_condition(xmachine_memory_Mall *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
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
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}

int IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity_condition(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}

int IGFirm_IGFirm_read_policy_announcements_policy_announcement_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	xmachine_memory_IGFirm *a = (xmachine_memory_IGFirm *)params;

	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

int Eurostat_Eurostat_Initialization_start_Eurostat_Eurostat_Start_Policy_Data_condition(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%240000000 == 1)) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_start_Eurostat_Eurostat_Start_Policy_Data_condition(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%240000000 == 1)) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_Eurostat_Start_Policy_Data_Eurostat_Start_Firm_Data_condition(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Eurostat_Eurostat_read_policy_announcements_Eurostat_Start_Policy_Data_Eurostat_Start_Firm_Data_condition(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Eurostat_Eurostat_send_data_Eurostat_Start_Firm_Data_01_condition(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_Eurostat_Start_Firm_Data_01_condition(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_01_Eurostat_Start_Monthly_Loop_condition(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%20 == 0) || (a->switch_datastorage == 0))) return 1;
	else return 0;
}

int Eurostat_Eurostat_calculate_data_01_Eurostat_Start_Monthly_Loop_condition(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%20 == 0) && (a->switch_datastorage == 1))) return 1;
	else return 0;
}

int Eurostat_Eurostat_store_history_monthly_Eurostat_Start_Monthly_Loop_02_condition(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%20 == 0) && (a->switch_datastorage == 1))) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_Eurostat_Start_Monthly_Loop_Eurostat_Start_Quarterly_Loop_condition(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%20 == 0) || (a->switch_datastorage == 0))) return 1;
	else return 0;
}

int Eurostat_Eurostat_store_history_quarterly_Eurostat_Start_Quarterly_Loop_04_condition(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%60 == 0) && (a->switch_datastorage == 1))) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_Eurostat_Start_Quarterly_Loop_Eurostat_Start_EndOfYear_Loop_condition(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%60 == 0) || (a->switch_datastorage == 0))) return 1;
	else return 0;
}

int Eurostat_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_end_Eurostat_condition(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}

int Eurostat_Eurostat_send_data_to_government_Eurostat_Start_EndOfYear_Loop_end_Eurostat_condition(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%240 == 0)) return 1;
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

int Government_Government_update_its_portfolio_order_status_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_order_status *m = (m_order_status*)msg;
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	if((a->id == m->trader_id)) return 1;
	else return 0;
}

int Government_Government_receive_info_bond_infoAssetCH_filter(const void *msg, const void *params)
{
	/* cast data to proper type */
	m_infoAssetCH *m = (m_infoAssetCH*)msg;
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	if((a->id == m->asset_id)) return 1;
	else return 0;
}

int Government_Government_idle_start_Government_Gov_Start_Bond_Market_condition(xmachine_memory_Government *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}

int Government_Government_send_policy_announcements_start_Government_Gov_Start_Bond_Market_condition(xmachine_memory_Government *a)
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
