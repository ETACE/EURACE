/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

/** \fn void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
 * \brief Create memory to hold agent filter variables for every agent using the filter on the current node.
 * \param agent_number The number of agent types.
 * \param agent_count List of the number of agents of each agent type.
 * \param agent_struct_size The struct size needed for each agent type.
 * \param cparam_size The size of the memory created.
 * \return Pointer to the created memory.
 */
void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
{
	/* Pointer to the memory created that is going to be returned */
	void *data;
	/* Variable used in for loops */
	int i;
	/* Variable to hold total size of memory required for agent structures */
	size_t total_param_size = 0;

	/* For each agent type add required memory for agent structures */
	for(i = 0; i < agent_number; i++)
	{
		total_param_size += agent_count[i] * agent_struct_size[i];
	}

	//assert(count > 0);
	//assert(total_param_size > 0);
	/* Does libmboard free this memory? */
	
	/* Allocate required memory, where memory holds the number
	 * of each agent type, in order, and the total required
	 * memory for agent structures */
	data = malloc(agent_number*sizeof(int) + total_param_size);
	/* Make the memory size parameter equal to the actual memory size */
	*cparam_size = agent_number*sizeof(int) + total_param_size;
	/* Assert that the created memory was successfully created and not null */
	assert(data != NULL);

	/* Return the pointer to the created memory */
	return data;
}


/** \fn int FLAME_condition_Firm_Firm_calc_production_quantity_Firm_Start_Producer_Role_01(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_calc_production_quantity_Firm_Start_Producer_Role_01(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_set_quantities_zero_Firm_Start_Producer_Role_00b(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_set_quantities_zero_Firm_Start_Producer_Role_00b(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_14_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_14_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->last_day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_compute_sales_statistics_14_Firm_Start_Financial_Management_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_compute_sales_statistics_14_Firm_Start_Financial_Management_Role(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->last_day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_End_Seller_Role_14(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_End_Seller_Role_14(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_ask_loan_Firm_Start_Credit_Role_Firm_Credit_02(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_ask_loan_Firm_Start_Credit_Role_Firm_Credit_02(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_set_bankruptcy_insolvency_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_set_bankruptcy_insolvency_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
{
	if((a->equity < 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
{
	if((a->equity >= 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_compute_and_send_stock_orders_dummy_Firm_End_Credit_Role_0003(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_compute_and_send_stock_orders_dummy_Firm_End_Credit_Role_0003(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_set_bankruptcy_illiquidity_Firm_bankruptcy_checked_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_set_bankruptcy_illiquidity_Firm_bankruptcy_checked_Firm_End_Financial_Management_Role(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_illiquidity_state == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_in_financial_crisis_Firm_checks_financial_crisis_Firm_End_External_Financing(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_in_financial_crisis_Firm_checks_financial_crisis_Firm_End_External_Financing(xmachine_memory_Firm *a)
{
	if((a->financial_crisis_state == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_checks_financial_crisis(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_checks_financial_crisis(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_illiquidity_state == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_checks_financial_crisis_Firm_End_External_Financing(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_checks_financial_crisis_Firm_End_External_Financing(xmachine_memory_Firm *a)
{
	if((a->financial_crisis_state == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_Start_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_Start_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_End_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_End_Credit_Role_Firm_End_External_Financing(xmachine_memory_Firm *a)
{
	if(!(a->external_financial_needs > 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_bankruptcy_insolvency_procedure_Firm_not_active_Firm_bankrupty_state_1(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_bankruptcy_insolvency_procedure_Firm_not_active_Firm_bankrupty_state_1(xmachine_memory_Firm *a)
{
	if((a->bankruptcy_insolvency_state == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_bankruptcy_illiquidity_procedure_Firm_not_active_Firm_bankrupty_state_1(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_bankruptcy_illiquidity_procedure_Firm_not_active_Firm_bankrupty_state_1(xmachine_memory_Firm *a)
{
	if(((a->bankruptcy_illiquidity_state == 1) && (a->bankruptcy_insolvency_state == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_bankruptcy_idle_counter_start_Firm_Firm_not_active(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_bankruptcy_idle_counter_start_Firm_Firm_not_active(xmachine_memory_Firm *a)
{
	if((a->active == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_start_Firm_Firm_is_active(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_start_Firm_Firm_is_active(xmachine_memory_Firm *a)
{
	if((a->active == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_compute_and_send_stock_orders_dummy_Firm_bankrupty_state_1_Firm_bankrupty_state_2(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_compute_and_send_stock_orders_dummy_Firm_bankrupty_state_1_Firm_bankrupty_state_2(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs > 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_bankrupty_state_1_Firm_bankrupty_state_3(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_bankrupty_state_1_Firm_bankrupty_state_3(xmachine_memory_Firm *a)
{
	if((a->external_financial_needs <= 0.0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_send_vacancies_04ccc_03(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_send_vacancies_04ccc_03(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_send_redundancies_011_03ccc(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_send_redundancies_011_03ccc(xmachine_memory_Firm *a)
{
	if((a->no_employees > a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_011_03ccc(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_011_03ccc(xmachine_memory_Firm *a)
{
	if((a->no_employees <= a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_start_labour_market_03d_06(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_start_labour_market_03d_06(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_finish_labour_market_first_round_03d_09a(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_finish_labour_market_first_round_03d_09a(xmachine_memory_Firm *a)
{
	if(!(a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_finish_labour_market_first_round_05b_09a(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_finish_labour_market_first_round_05b_09a(xmachine_memory_Firm *a)
{
	if((a->no_employees == a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_update_wage_offer_05b_06(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_update_wage_offer_05b_06(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_update_wage_offer_2_09b_10(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_update_wage_offer_2_09b_10(xmachine_memory_Firm *a)
{
	if((a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_idle_09b_10(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_idle_09b_10(xmachine_memory_Firm *a)
{
	if(!(a->no_employees < a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_04ccc_03c(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_04ccc_03c(xmachine_memory_Firm *a)
{
	if((a->no_employees == a->employees_needed)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_is_active_Firm_Start_Macro_Data(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_is_active_Firm_Start_Macro_Data(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data(xmachine_memory_Firm *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_Start_Macro_Data_Firm_End_Macro_Data(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_Start_Macro_Data_Firm_End_Macro_Data(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_Firm_send_data_to_Eurostat_Firm_End_Financial_Management_Role_15(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_Firm_send_data_to_Eurostat_Firm_End_Financial_Management_Role_15(xmachine_memory_Firm *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Firm_idle_Firm_End_Financial_Management_Role_15(xmachine_memory_Firm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Firm_idle_Firm_End_Financial_Management_Role_15(xmachine_memory_Firm *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_09_15(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_09_15(xmachine_memory_Household *a)
{
	if(!(iteration_loop%5 == a->day_of_week_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_rank_and_buy_goods_1_09_09b(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_rank_and_buy_goods_1_09_09b(xmachine_memory_Household *a)
{
	if(((iteration_loop%5 == a->day_of_week_to_act) && (a->weekly_budget <= a->payment_account))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_set_values_zero_11_14(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_set_values_zero_11_14(xmachine_memory_Household *a)
{
	if((a->rationed != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_rank_and_buy_goods_2_11_12(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_rank_and_buy_goods_2_11_12(xmachine_memory_Household *a)
{
	if((a->rationed == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_back_shifting_consumption_day_09b_10(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_back_shifting_consumption_day_09b_10(xmachine_memory_Household *a)
{
	if((a->flag_consumption_shifting == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_09b_10(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_09b_10(xmachine_memory_Household *a)
{
	if((a->flag_consumption_shifting != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_shifting_consumption_day_09_15(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_shifting_consumption_day_09_15(xmachine_memory_Household *a)
{
	if(((iteration_loop%5 == a->day_of_week_to_act) && (a->excess_weekly_budget > 0.0000001))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_01d_01a(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_01d_01a(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_Household_Start_Labour_Role_01a(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_Household_Start_Labour_Role_01a(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_01d_06(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_01d_06(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_finish_labour_market_02_06(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_finish_labour_market_02_06(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_02_03(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_02_03(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_2_05_06(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_2_05_06(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_05_06(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_05_06(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_06b_09(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_06b_09(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == a->day_of_month_receive_income)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_06b_06c(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_06b_06c(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == a->day_of_month_receive_income)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_receive_wage_06e_07(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_receive_wage_06e_07(xmachine_memory_Household *a)
{
	if((a->employee_firm_id != -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_send_unemployment_benefit_notification_06e_08(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_send_unemployment_benefit_notification_06e_08(xmachine_memory_Household *a)
{
	if((a->employee_firm_id == -1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_start_Household_Household_Start_Policy_Data(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_start_Household_Household_Start_Policy_Data(xmachine_memory_Household *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data(xmachine_memory_Household *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_receive_data_Household_Start_Policy_Data_Household_Start_Financial_Market_Role(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_receive_data_Household_Start_Policy_Data_Household_Start_Financial_Market_Role(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_Household_Start_Policy_Data_Household_Start_Financial_Market_Role(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_Household_Start_Policy_Data_Household_Start_Financial_Market_Role(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_send_data_to_Eurostat_15_end_Household(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_send_data_to_Eurostat_15_end_Household(xmachine_memory_Household *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Household_Household_idle_15_end_Household(xmachine_memory_Household *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Household_Household_idle_15_end_Household(xmachine_memory_Household *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_Mall_reset_export_data_start_Mall_01(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_Mall_reset_export_data_start_Mall_01(xmachine_memory_Mall *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_idle_start_Mall_01(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_idle_start_Mall_01(xmachine_memory_Mall *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_Mall_send_export_data_06_end_Mall(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_Mall_send_export_data_06_end_Mall(xmachine_memory_Mall *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Mall_idle_06_end_Mall(xmachine_memory_Mall *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Mall_idle_06_end_Mall(xmachine_memory_Mall *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_update_productivity_price_Start_IGFirm_Productivity_01(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_update_productivity_price_Start_IGFirm_Productivity_01(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_idle_Start_IGFirm_Productivity_01(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_idle_Start_IGFirm_Productivity_01(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_pay_taxes_04_04b(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_pay_taxes_04_04b(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_dividend_payment_04b_end_IGFirm(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_dividend_payment_04b_end_IGFirm(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_idle_04_end_IGFirm(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_idle_04_end_IGFirm(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_idle_start_IGFirm_Start_IGFirm_Productivity(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_idle_start_IGFirm_Start_IGFirm_Productivity(xmachine_memory_IGFirm *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity(xmachine_memory_IGFirm *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity(xmachine_memory_IGFirm *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_send_data_start_Eurostat_01(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_send_data_start_Eurostat_01(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_start_Eurostat_01(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_start_Eurostat_01(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%20 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%20 == 0) || (a->switch_datastorage == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_calculate_data_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_calculate_data_01_Eurostat_Start_Monthly_Loop(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%20 == 0) && (a->switch_datastorage == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_store_history_monthly_Eurostat_Start_Monthly_Loop_02(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_store_history_monthly_Eurostat_Start_Monthly_Loop_02(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%20 == 0) && (a->switch_datastorage == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Monthly_Loop_Eurostat_Start_Quarterly_Loop(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Monthly_Loop_Eurostat_Start_Quarterly_Loop(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%20 == 0) || (a->switch_datastorage == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_store_history_quarterly_Eurostat_Start_Quarterly_Loop_04(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_store_history_quarterly_Eurostat_Start_Quarterly_Loop_04(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%60 == 0) && (a->switch_datastorage == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Quarterly_Loop_Eurostat_Start_EndOfYear_Loop(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Quarterly_Loop_Eurostat_Start_EndOfYear_Loop(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%60 == 0) || (a->switch_datastorage == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_Eurostat_check_flows(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_Eurostat_check_flows(xmachine_memory_Eurostat *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_send_data_to_government_Eurostat_Start_EndOfYear_Loop_Eurostat_check_flows(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_send_data_to_government_Eurostat_Start_EndOfYear_Loop_Eurostat_check_flows(xmachine_memory_Eurostat *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_check_flow_consistency_Eurostat_check_flows_Eurostat_check_stocks(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_check_flow_consistency_Eurostat_check_flows_Eurostat_check_stocks(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%1 == 0) && (SWITCH_FLOW_CONSISTENCY_CHECK == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_idle_Eurostat_check_flows_Eurostat_check_stocks(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_idle_Eurostat_check_flows_Eurostat_check_stocks(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%1 == 0) || (SWITCH_FLOW_CONSISTENCY_CHECK == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_Eurostat_check_stock_consistency_Eurostat_check_stocks_end_Eurostat(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_Eurostat_check_stock_consistency_Eurostat_check_stocks_end_Eurostat(xmachine_memory_Eurostat *a)
{
	if(((iteration_loop%20 == 0) && (SWITCH_STOCK_CONSISTENCY_CHECK == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Eurostat_idle_Eurostat_check_stocks_end_Eurostat(xmachine_memory_Eurostat *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Eurostat_idle_Eurostat_check_stocks_end_Eurostat(xmachine_memory_Eurostat *a)
{
	if((!(iteration_loop%20 == 0) || (SWITCH_STOCK_CONSISTENCY_CHECK == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_accounting_Bank_06_Bank_07(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_accounting_Bank_06_Bank_07(xmachine_memory_Bank *a)
{
	if((iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_idle_Bank_06_end_Bank_cycle(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_idle_Bank_06_end_Bank_cycle(xmachine_memory_Bank *a)
{
	if(!(iteration_loop%20 == a->day_of_month_to_act)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_send_data_to_Eurostat_Bank_07_end_Bank_cycle(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_send_data_to_Eurostat_Bank_07_end_Bank_cycle(xmachine_memory_Bank *a)
{
	if(((iteration_loop%20 == 0) && (SWITCH_STOCK_CONSISTENCY_CHECK == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_idle_Bank_07_end_Bank_cycle(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_idle_Bank_07_end_Bank_cycle(xmachine_memory_Bank *a)
{
	if((!(iteration_loop%20 == 0) || (SWITCH_STOCK_CONSISTENCY_CHECK == 0))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_idle_start_Bank_Bank_start_credit_market_role(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_idle_start_Bank_Bank_start_credit_market_role(xmachine_memory_Bank *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role(xmachine_memory_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role(xmachine_memory_Bank *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_bond_market_dummy_Gov_Start_Bond_Market_01(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_bond_market_dummy_Gov_Start_Bond_Market_01(xmachine_memory_Government *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_idle_Gov_Start_Bond_Market_01(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_idle_Gov_Start_Bond_Market_01(xmachine_memory_Government *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_idle_start_Government_Gov_Start_Bond_Market(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_idle_start_Government_Gov_Start_Bond_Market(xmachine_memory_Government *a)
{
	if(!(iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_send_policy_announcements_start_Government_Gov_Start_Bond_Market(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_send_policy_announcements_start_Government_Gov_Start_Bond_Market(xmachine_memory_Government *a)
{
	if((iteration_loop%240 == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_idle_Gov_Start_Monthly_Loop_Gov_Start_Yearly_Loop(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_idle_Gov_Start_Monthly_Loop_Gov_Start_Yearly_Loop(xmachine_memory_Government *a)
{
	if(!(iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_monthly_budget_accounting_Gov_Start_Monthly_Loop_05(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_monthly_budget_accounting_Gov_Start_Monthly_Loop_05(xmachine_memory_Government *a)
{
	if((iteration_loop%20 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_idle_Gov_Start_Yearly_Loop_end_Government(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_idle_Gov_Start_Yearly_Loop_end_Government(xmachine_memory_Government *a)
{
	if(!(iteration_loop%240 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_07(xmachine_memory_Government *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_07(xmachine_memory_Government *a)
{
	if((iteration_loop%240 == 0)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Central_Bank_Central_Bank_send_data_to_Eurostat_01_end_Central_Bank(xmachine_memory_Central_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Central_Bank_Central_Bank_send_data_to_Eurostat_01_end_Central_Bank(xmachine_memory_Central_Bank *a)
{
	if(((iteration_loop%20 == 0) && (SWITCH_STOCK_CONSISTENCY_CHECK == 1))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Central_Bank_idle_01_end_Central_Bank(xmachine_memory_Central_Bank *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Central_Bank_idle_01_end_Central_Bank(xmachine_memory_Central_Bank *a)
{
	if((!(iteration_loop%20 == 0) || (SWITCH_STOCK_CONSISTENCY_CHECK == 0))) return 1;
	else return 0;
}



/** \fn int FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_capital_good_delivery *m = (m_capital_good_delivery*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_sales *m = (m_sales*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_specific_skill_update *m = (m_specific_skill_update*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_loan_conditions *m = (m_loan_conditions*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->id == m->firm_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data_policy_announcement(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data_policy_announcement(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data_eurostat_send_specific_skills(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data_eurostat_send_specific_skills(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_eurostat_send_specific_skills *m = (m_eurostat_send_specific_skills*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Firm *a = (xmachine_memory_Firm *)params;

	/* The filter */
	if((a->region_id == m->region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_rank_and_buy_goods_1_09_09b_quality_price_info_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_rank_and_buy_goods_1_09_09b_quality_price_info_1(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_quality_price_info_1 *m = (m_quality_price_info_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->region_id == m->mall_region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_accepted_consumption_1 *m = (m_accepted_consumption_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->household_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_quality_price_info_2 *m = (m_quality_price_info_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->region_id == m->mall_region_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_accepted_consumption_2 *m = (m_accepted_consumption_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->household_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_firing *m = (m_firing*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->worker_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_wage_payment *m = (m_wage_payment*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->id == m->worker_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data_policy_announcement(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data_policy_announcement(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Household *a = (xmachine_memory_Household *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_consumption_request_1 *m = (m_consumption_request_1*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Mall *a = (xmachine_memory_Mall *)params;

	/* The filter */
	if((a->id == m->mall_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_consumption_request_2 *m = (m_consumption_request_2*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Mall *a = (xmachine_memory_Mall *)params;

	/* The filter */
	if((a->id == m->mall_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity_policy_announcement(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity_policy_announcement(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_IGFirm *a = (xmachine_memory_IGFirm *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_02_Bank_03_loan_request(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_02_Bank_03_loan_request(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_loan_request *m = (m_loan_request*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_loan_acceptance *m = (m_loan_acceptance*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_installment(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_installment(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_installment *m = (m_installment*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_bankruptcy(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_bankruptcy(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_bankruptcy *m = (m_bankruptcy*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_bank_account_update *m = (m_bank_account_update*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->id == m->bank_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role_policy_announcement(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role_policy_announcement(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Bank *a = (xmachine_memory_Bank *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_tax_payments_01_02_tax_payment(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_tax_payments_01_02_tax_payment(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_tax_payment *m = (m_tax_payment*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_hh_subsidy_notification *m = (m_hh_subsidy_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_firm_subsidy_notification *m = (m_firm_subsidy_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_hh_transfer_notification *m = (m_hh_transfer_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_firm_transfer_notification *m = (m_firm_transfer_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/** \fn int FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_04b_unemployment_notification(const void *msg, const void *params)
 * \brief The filter function for a message input used in serial for each agent.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent memory.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_04b_unemployment_notification(const void *msg, const void *params)
{
	/* Cast the message pointer to the correct message type */
	m_unemployment_notification *m = (m_unemployment_notification*)msg;
	/* Cast the params pointer to the correct agent type */
	xmachine_memory_Government *a = (xmachine_memory_Government *)params;

	/* The filter */
	if((a->id == m->gov_id)) return 1;
	else return 0;
}

/* Filter handling functions for message type bank_account_update for input layer 72 */

/** \struct FLAME_param_Bank_bank_account_update_72
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Bank_bank_account_update_72
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_bank_account_update *m = (m_bank_account_update*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Bank_bank_account_update_72 *a = (struct FLAME_param_Bank_bank_account_update_72 *)params;

	/* The filter */
	if((a->id == m->bank_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_bank_account_update_72(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_bank_account_update_72(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_bank_account_update_72\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Bank_bank_account_update_72);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_bank_account_update_72()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_bank_account_update_72()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Bank_Bank_05_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Bank_bank_account_update_72);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_bank_account_update_72() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_bank_account_update_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_bank_account_update_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Bank_holder = Bank_Bank_05_state->agents;
	while(current_xmachine_Bank_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Bank\tid\t%i\n", i, current_xmachine_Bank_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Bank_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_bank_account_update_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Bank", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_bank_account_update_72);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_bank_account_update, f_handle, FLAME_m_bank_account_update_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type wage_payment for input layer 50 */

/** \struct FLAME_param_Household_wage_payment_50
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Household_wage_payment_50
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_wage_payment *m = (m_wage_payment*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Household_wage_payment_50 *a = (struct FLAME_param_Household_wage_payment_50 *)params;

	/* The filter */
	if((a->id == m->worker_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_wage_payment_50(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_wage_payment_50(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_wage_payment_50\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Household_wage_payment_50);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_wage_payment_50()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_wage_payment_50()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Household_06e_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Household_wage_payment_50);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_wage_payment_50() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_wage_payment_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_wage_payment_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Household_holder = Household_06e_state->agents;
	while(current_xmachine_Household_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Household\tid\t%i\n", i, current_xmachine_Household_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Household_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_wage_payment_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Household", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_wage_payment_50);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_wage_payment, f_handle, FLAME_m_wage_payment_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type quality_price_info_1 for input layer 54 */

/** \struct FLAME_param_Household_quality_price_info_1_54
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Household_quality_price_info_1_54
{
	int region_id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Household_Household_rank_and_buy_goods_1_09_09b_quality_price_info_1_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_rank_and_buy_goods_1_09_09b_quality_price_info_1_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_quality_price_info_1 *m = (m_quality_price_info_1*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Household_quality_price_info_1_54 *a = (struct FLAME_param_Household_quality_price_info_1_54 *)params;

	/* The filter */
	if((a->region_id == m->mall_region_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Household_Household_rank_and_buy_goods_1_09_09b_quality_price_info_1_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_quality_price_info_1_54(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_quality_price_info_1_54(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_quality_price_info_1_54\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tregion_id=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Household_Household_rank_and_buy_goods_1_09_09b_quality_price_info_1_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Household_quality_price_info_1_54);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_quality_price_info_1_54()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_quality_price_info_1_54()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Household_09_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Household_quality_price_info_1_54);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_quality_price_info_1_54() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_quality_price_info_1_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_quality_price_info_1_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Household_holder = Household_09_state->agents;
	while(current_xmachine_Household_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Household\tregion_id\t%i\n", i, current_xmachine_Household_holder->agent->region_id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Household_holder->agent->region_id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_quality_price_info_1_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Household", i);
		
		printf("\tregion_id=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_quality_price_info_1_54);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_quality_price_info_1, f_handle, FLAME_m_quality_price_info_1_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type quality_price_info_2 for input layer 57 */

/** \struct FLAME_param_Household_quality_price_info_2_57
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Household_quality_price_info_2_57
{
	int region_id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_quality_price_info_2 *m = (m_quality_price_info_2*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Household_quality_price_info_2_57 *a = (struct FLAME_param_Household_quality_price_info_2_57 *)params;

	/* The filter */
	if((a->region_id == m->mall_region_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_quality_price_info_2_57(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_quality_price_info_2_57(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_quality_price_info_2_57\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tregion_id=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Household_quality_price_info_2_57);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_quality_price_info_2_57()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_quality_price_info_2_57()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Household_11_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Household_quality_price_info_2_57);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_quality_price_info_2_57() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_quality_price_info_2_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_quality_price_info_2_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Household_holder = Household_11_state->agents;
	while(current_xmachine_Household_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Household\tregion_id\t%i\n", i, current_xmachine_Household_holder->agent->region_id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Household_holder->agent->region_id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_quality_price_info_2_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Household", i);
		
		printf("\tregion_id=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_quality_price_info_2_57);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_quality_price_info_2, f_handle, FLAME_m_quality_price_info_2_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type consumption_request_1 for input layer 55 */

/** \struct FLAME_param_Mall_consumption_request_1_55
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Mall_consumption_request_1_55
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_consumption_request_1 *m = (m_consumption_request_1*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Mall_consumption_request_1_55 *a = (struct FLAME_param_Mall_consumption_request_1_55 *)params;

	/* The filter */
	if((a->id == m->mall_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_consumption_request_1_55(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_consumption_request_1_55(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_consumption_request_1_55\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Mall_consumption_request_1_55);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_consumption_request_1_55()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_consumption_request_1_55()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Mall_03_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Mall_consumption_request_1_55);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_consumption_request_1_55() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_consumption_request_1_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_consumption_request_1_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Mall_holder = Mall_03_state->agents;
	while(current_xmachine_Mall_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Mall\tid\t%i\n", i, current_xmachine_Mall_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Mall_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_consumption_request_1_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Mall", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_consumption_request_1_55);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_consumption_request_1, f_handle, FLAME_m_consumption_request_1_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type consumption_request_2 for input layer 58 */

/** \struct FLAME_param_Mall_consumption_request_2_58
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Mall_consumption_request_2_58
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_consumption_request_2 *m = (m_consumption_request_2*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Mall_consumption_request_2_58 *a = (struct FLAME_param_Mall_consumption_request_2_58 *)params;

	/* The filter */
	if((a->id == m->mall_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_consumption_request_2_58(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_consumption_request_2_58(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_consumption_request_2_58\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Mall_consumption_request_2_58);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_consumption_request_2_58()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_consumption_request_2_58()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Mall_04_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Mall_consumption_request_2_58);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_consumption_request_2_58() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_consumption_request_2_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_consumption_request_2_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Mall_holder = Mall_04_state->agents;
	while(current_xmachine_Mall_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Mall\tid\t%i\n", i, current_xmachine_Mall_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Mall_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_consumption_request_2_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Mall", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_consumption_request_2_58);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_consumption_request_2, f_handle, FLAME_m_consumption_request_2_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type accepted_consumption_1 for input layer 56 */

/** \struct FLAME_param_Household_accepted_consumption_1_56
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Household_accepted_consumption_1_56
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_accepted_consumption_1 *m = (m_accepted_consumption_1*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Household_accepted_consumption_1_56 *a = (struct FLAME_param_Household_accepted_consumption_1_56 *)params;

	/* The filter */
	if((a->id == m->household_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_accepted_consumption_1_56(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_accepted_consumption_1_56(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_accepted_consumption_1_56\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Household_accepted_consumption_1_56);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_accepted_consumption_1_56()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_accepted_consumption_1_56()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Household_10_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Household_accepted_consumption_1_56);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_accepted_consumption_1_56() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_accepted_consumption_1_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_accepted_consumption_1_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Household_holder = Household_10_state->agents;
	while(current_xmachine_Household_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Household\tid\t%i\n", i, current_xmachine_Household_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Household_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_accepted_consumption_1_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Household", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_accepted_consumption_1_56);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_accepted_consumption_1, f_handle, FLAME_m_accepted_consumption_1_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type accepted_consumption_2 for input layer 59 */

/** \struct FLAME_param_Household_accepted_consumption_2_59
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Household_accepted_consumption_2_59
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_accepted_consumption_2 *m = (m_accepted_consumption_2*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Household_accepted_consumption_2_59 *a = (struct FLAME_param_Household_accepted_consumption_2_59 *)params;

	/* The filter */
	if((a->id == m->household_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_accepted_consumption_2_59(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_accepted_consumption_2_59(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_accepted_consumption_2_59\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Household_accepted_consumption_2_59);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_accepted_consumption_2_59()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_accepted_consumption_2_59()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Household_12_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Household_accepted_consumption_2_59);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_accepted_consumption_2_59() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_accepted_consumption_2_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_accepted_consumption_2_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Household_holder = Household_12_state->agents;
	while(current_xmachine_Household_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Household\tid\t%i\n", i, current_xmachine_Household_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Household_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_accepted_consumption_2_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Household", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_accepted_consumption_2_59);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_accepted_consumption_2, f_handle, FLAME_m_accepted_consumption_2_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type sales for input layer 60 */

/** \struct FLAME_param_Firm_sales_60
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Firm_sales_60
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_sales *m = (m_sales*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Firm_sales_60 *a = (struct FLAME_param_Firm_sales_60 *)params;

	/* The filter */
	if((a->id == m->firm_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_sales_60(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_sales_60(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_sales_60\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Firm_sales_60);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_sales_60()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_sales_60()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Firm_Firm_Start_Seller_Role_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Firm_sales_60);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_sales_60() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_sales_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_sales_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Firm_holder = Firm_Firm_Start_Seller_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Firm\tid\t%i\n", i, current_xmachine_Firm_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Firm_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_sales_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Firm", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_sales_60);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_sales, f_handle, FLAME_m_sales_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type specific_skill_update for input layer 61 */

/** \struct FLAME_param_Firm_specific_skill_update_61
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Firm_specific_skill_update_61
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_specific_skill_update *m = (m_specific_skill_update*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Firm_specific_skill_update_61 *a = (struct FLAME_param_Firm_specific_skill_update_61 *)params;

	/* The filter */
	if((a->id == m->firm_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_specific_skill_update_61(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_specific_skill_update_61(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_specific_skill_update_61\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Firm_specific_skill_update_61);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_specific_skill_update_61()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_specific_skill_update_61()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Firm_Firm_End_Seller_Role_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Firm_specific_skill_update_61);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_specific_skill_update_61() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_specific_skill_update_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_specific_skill_update_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Firm_holder = Firm_Firm_End_Seller_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Firm\tid\t%i\n", i, current_xmachine_Firm_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Firm_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_specific_skill_update_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Firm", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_specific_skill_update_61);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_specific_skill_update, f_handle, FLAME_m_specific_skill_update_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type loan_request for input layer 8 */

/** \struct FLAME_param_Bank_loan_request_8
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Bank_loan_request_8
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_02_Bank_03_loan_request_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_02_Bank_03_loan_request_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_loan_request *m = (m_loan_request*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Bank_loan_request_8 *a = (struct FLAME_param_Bank_loan_request_8 *)params;

	/* The filter */
	if((a->id == m->bank_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_02_Bank_03_loan_request_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_loan_request_8(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_loan_request_8(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_loan_request_8\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_02_Bank_03_loan_request_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Bank_loan_request_8);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_loan_request_8()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_loan_request_8()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Bank_Bank_02_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Bank_loan_request_8);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_loan_request_8() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_loan_request_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_loan_request_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Bank_holder = Bank_Bank_02_state->agents;
	while(current_xmachine_Bank_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Bank\tid\t%i\n", i, current_xmachine_Bank_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Bank_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_loan_request_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Bank", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_loan_request_8);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_loan_request, f_handle, FLAME_m_loan_request_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type loan_conditions for input layer 9 */

/** \struct FLAME_param_Firm_loan_conditions_9
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Firm_loan_conditions_9
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_loan_conditions *m = (m_loan_conditions*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Firm_loan_conditions_9 *a = (struct FLAME_param_Firm_loan_conditions_9 *)params;

	/* The filter */
	if((a->id == m->firm_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_loan_conditions_9(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_loan_conditions_9(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_loan_conditions_9\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Firm_loan_conditions_9);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_loan_conditions_9()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_loan_conditions_9()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Firm_Firm_Credit_02_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Firm_loan_conditions_9);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_loan_conditions_9() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_loan_conditions_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_loan_conditions_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Firm_holder = Firm_Firm_Credit_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Firm\tid\t%i\n", i, current_xmachine_Firm_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Firm_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_loan_conditions_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Firm", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_loan_conditions_9);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_loan_conditions, f_handle, FLAME_m_loan_conditions_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type loan_acceptance for input layer 10 */

/** \struct FLAME_param_Bank_loan_acceptance_10
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Bank_loan_acceptance_10
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_loan_acceptance *m = (m_loan_acceptance*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Bank_loan_acceptance_10 *a = (struct FLAME_param_Bank_loan_acceptance_10 *)params;

	/* The filter */
	if((a->id == m->bank_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_loan_acceptance_10(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_loan_acceptance_10(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_loan_acceptance_10\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Bank_loan_acceptance_10);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_loan_acceptance_10()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_loan_acceptance_10()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Bank_Bank_03_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Bank_loan_acceptance_10);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_loan_acceptance_10() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_loan_acceptance_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_loan_acceptance_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Bank_holder = Bank_Bank_03_state->agents;
	while(current_xmachine_Bank_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Bank\tid\t%i\n", i, current_xmachine_Bank_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Bank_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_loan_acceptance_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Bank", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_loan_acceptance_10);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_loan_acceptance, f_handle, FLAME_m_loan_acceptance_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type installment for input layer 16 */

/** \struct FLAME_param_Bank_installment_16
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Bank_installment_16
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_installment_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_installment_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_installment *m = (m_installment*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Bank_installment_16 *a = (struct FLAME_param_Bank_installment_16 *)params;

	/* The filter */
	if((a->id == m->bank_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_installment_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_installment_16(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_installment_16(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_installment_16\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_installment_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Bank_installment_16);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_installment_16()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_installment_16()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Bank_Bank_04_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Bank_installment_16);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_installment_16() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_installment_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_installment_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Bank_holder = Bank_Bank_04_state->agents;
	while(current_xmachine_Bank_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Bank\tid\t%i\n", i, current_xmachine_Bank_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Bank_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_installment_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Bank", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_installment_16);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_installment, f_handle, FLAME_m_installment_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type bankruptcy for input layer 16 */

/** \struct FLAME_param_Bank_bankruptcy_16
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Bank_bankruptcy_16
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_bankruptcy_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_bankruptcy_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_bankruptcy *m = (m_bankruptcy*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Bank_bankruptcy_16 *a = (struct FLAME_param_Bank_bankruptcy_16 *)params;

	/* The filter */
	if((a->id == m->bank_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_bankruptcy_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_bankruptcy_16(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_bankruptcy_16(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_bankruptcy_16\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_bankruptcy_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Bank_bankruptcy_16);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_bankruptcy_16()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_bankruptcy_16()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Bank_Bank_04_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Bank_bankruptcy_16);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_bankruptcy_16() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_bankruptcy_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_bankruptcy_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Bank_holder = Bank_Bank_04_state->agents;
	while(current_xmachine_Bank_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Bank\tid\t%i\n", i, current_xmachine_Bank_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Bank_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_bankruptcy_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Bank", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_bankruptcy_16);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_bankruptcy, f_handle, FLAME_m_bankruptcy_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type capital_good_delivery for input layer 40 */

/** \struct FLAME_param_Firm_capital_good_delivery_40
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Firm_capital_good_delivery_40
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_capital_good_delivery *m = (m_capital_good_delivery*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Firm_capital_good_delivery_40 *a = (struct FLAME_param_Firm_capital_good_delivery_40 *)params;

	/* The filter */
	if((a->id == m->firm_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_capital_good_delivery_40(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_capital_good_delivery_40(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_capital_good_delivery_40\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Firm_capital_good_delivery_40);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_capital_good_delivery_40()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_capital_good_delivery_40()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Firm_11a_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Firm_capital_good_delivery_40);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_capital_good_delivery_40() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_capital_good_delivery_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_capital_good_delivery_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Firm_holder = Firm_11a_state->agents;
	while(current_xmachine_Firm_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Firm\tid\t%i\n", i, current_xmachine_Firm_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Firm_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_capital_good_delivery_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Firm", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_capital_good_delivery_40);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_capital_good_delivery, f_handle, FLAME_m_capital_good_delivery_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type firing for input layer 22 */

/** \struct FLAME_param_Household_firing_22
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Household_firing_22
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_firing *m = (m_firing*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Household_firing_22 *a = (struct FLAME_param_Household_firing_22 *)params;

	/* The filter */
	if((a->id == m->worker_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_firing_22(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_firing_22(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_firing_22\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Household_firing_22);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_firing_22()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_firing_22()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Household_Household_Start_Labour_Role_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Household_firing_22);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_firing_22() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_firing_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_firing_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Household_holder = Household_Household_Start_Labour_Role_state->agents;
	while(current_xmachine_Household_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Household\tid\t%i\n", i, current_xmachine_Household_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Household_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_firing_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Household", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_firing_22);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_firing, f_handle, FLAME_m_firing_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type unemployment_notification for input layer 77 */

/** \struct FLAME_param_Government_unemployment_notification_77
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Government_unemployment_notification_77
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_04b_unemployment_notification_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_04b_unemployment_notification_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_unemployment_notification *m = (m_unemployment_notification*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Government_unemployment_notification_77 *a = (struct FLAME_param_Government_unemployment_notification_77 *)params;

	/* The filter */
	if((a->id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_04b_unemployment_notification_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_unemployment_notification_77(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_unemployment_notification_77(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_unemployment_notification_77\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_04b_unemployment_notification_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Government_unemployment_notification_77);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_unemployment_notification_77()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_unemployment_notification_77()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Government_04_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Government_unemployment_notification_77);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_unemployment_notification_77() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_unemployment_notification_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_unemployment_notification_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Government_holder = Government_04_state->agents;
	while(current_xmachine_Government_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Government\tid\t%i\n", i, current_xmachine_Government_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Government_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Government_holder = current_xmachine_Government_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_unemployment_notification_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Government", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_unemployment_notification_77);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_unemployment_notification, f_handle, FLAME_m_unemployment_notification_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type policy_announcement for input layer 1 */

/** \struct FLAME_param_Firm_policy_announcement_1
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Firm_policy_announcement_1
{
	int gov_id; /**< Agent memory variable required for the input filter */
};

/** \struct FLAME_param_Household_policy_announcement_1
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Household_policy_announcement_1
{
	int gov_id; /**< Agent memory variable required for the input filter */
};

/** \struct FLAME_param_IGFirm_policy_announcement_1
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_IGFirm_policy_announcement_1
{
	int gov_id; /**< Agent memory variable required for the input filter */
};

/** \struct FLAME_param_Bank_policy_announcement_1
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Bank_policy_announcement_1
{
	int gov_id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data_policy_announcement_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data_policy_announcement_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Firm_policy_announcement_1 *a = (struct FLAME_param_Firm_policy_announcement_1 *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data_policy_announcement_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_filter_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data_policy_announcement_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data_policy_announcement_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Household_policy_announcement_1 *a = (struct FLAME_param_Household_policy_announcement_1 *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data_policy_announcement_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_filter_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity_policy_announcement_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity_policy_announcement_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_IGFirm_policy_announcement_1 *a = (struct FLAME_param_IGFirm_policy_announcement_1 *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity_policy_announcement_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role_policy_announcement_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role_policy_announcement_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_policy_announcement *m = (m_policy_announcement*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Bank_policy_announcement_1 *a = (struct FLAME_param_Bank_policy_announcement_1 *)params;

	/* The filter */
	if((a->gov_id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role_policy_announcement_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_policy_announcement_1(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_policy_announcement_1(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_policy_announcement_1\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[4];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 4; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tgov_id=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data_policy_announcement_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Firm_policy_announcement_1);
	}
	
	for(i = 0; i < agent_count[1]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tgov_id=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data_policy_announcement_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Household_policy_announcement_1);
	}
	
	for(i = 0; i < agent_count[2]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tgov_id=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity_policy_announcement_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_IGFirm_policy_announcement_1);
	}
	
	for(i = 0; i < agent_count[3]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tgov_id=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role_policy_announcement_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Bank_policy_announcement_1);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_policy_announcement_1()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_policy_announcement_1()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[4];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[4];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 4; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Firm_Firm_is_active_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Firm_policy_announcement_1);
	/* Add agent type state count to total agent type count */
	agent_count[1] += Household_start_Household_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[1] = sizeof(struct FLAME_param_Household_policy_announcement_1);
	/* Add agent type state count to total agent type count */
	agent_count[2] += IGFirm_start_IGFirm_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[2] = sizeof(struct FLAME_param_IGFirm_policy_announcement_1);
	/* Add agent type state count to total agent type count */
	agent_count[3] += Bank_start_Bank_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[3] = sizeof(struct FLAME_param_Bank_policy_announcement_1);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_policy_announcement_1() - agent_number = %d\n", 4);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 4; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_policy_announcement_composite_params = cparams_create(4, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_policy_announcement_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 4; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Firm_holder = Firm_Firm_is_active_state->agents;
	while(current_xmachine_Firm_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Firm\tgov_id\t%i\n", i, current_xmachine_Firm_holder->agent->gov_id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Firm_holder->agent->gov_id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}
	
	current_xmachine_Household_holder = Household_start_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Household\tgov_id\t%i\n", i, current_xmachine_Household_holder->agent->gov_id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Household_holder->agent->gov_id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}
	
	current_xmachine_IGFirm_holder = IGFirm_start_IGFirm_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] IGFirm\tgov_id\t%i\n", i, current_xmachine_IGFirm_holder->agent->gov_id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_IGFirm_holder->agent->gov_id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
	}
	
	current_xmachine_Bank_holder = Bank_start_Bank_state->agents;
	while(current_xmachine_Bank_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Bank\tgov_id\t%i\n", i, current_xmachine_Bank_holder->agent->gov_id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Bank_holder->agent->gov_id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_policy_announcement_composite_params;
	for(i = 0; i < 4; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Firm", i);
		
		printf("\tgov_id=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	
	for(i = 0; i < agent_count[1]; i++)
	{
		printf("\t*** [%d] Household", i);
		
		printf("\tgov_id=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	
	for(i = 0; i < agent_count[2]; i++)
	{
		printf("\t*** [%d] IGFirm", i);
		
		printf("\tgov_id=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	
	for(i = 0; i < agent_count[3]; i++)
	{
		printf("\t*** [%d] Bank", i);
		
		printf("\tgov_id=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_policy_announcement_1);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_policy_announcement, f_handle, FLAME_m_policy_announcement_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type tax_payment for input layer 74 */

/** \struct FLAME_param_Government_tax_payment_74
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Government_tax_payment_74
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Government_Government_read_tax_payments_01_02_tax_payment_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_tax_payments_01_02_tax_payment_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_tax_payment *m = (m_tax_payment*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Government_tax_payment_74 *a = (struct FLAME_param_Government_tax_payment_74 *)params;

	/* The filter */
	if((a->id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Government_Government_read_tax_payments_01_02_tax_payment_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_tax_payment_74(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_tax_payment_74(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_tax_payment_74\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Government_Government_read_tax_payments_01_02_tax_payment_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Government_tax_payment_74);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_tax_payment_74()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_tax_payment_74()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Government_01_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Government_tax_payment_74);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_tax_payment_74() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_tax_payment_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_tax_payment_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Government_holder = Government_01_state->agents;
	while(current_xmachine_Government_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Government\tid\t%i\n", i, current_xmachine_Government_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Government_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Government_holder = current_xmachine_Government_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_tax_payment_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Government", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_tax_payment_74);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_tax_payment, f_handle, FLAME_m_tax_payment_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type hh_transfer_notification for input layer 76 */

/** \struct FLAME_param_Government_hh_transfer_notification_76
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Government_hh_transfer_notification_76
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_hh_transfer_notification *m = (m_hh_transfer_notification*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Government_hh_transfer_notification_76 *a = (struct FLAME_param_Government_hh_transfer_notification_76 *)params;

	/* The filter */
	if((a->id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_hh_transfer_notification_76(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_hh_transfer_notification_76(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_hh_transfer_notification_76\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Government_hh_transfer_notification_76);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_hh_transfer_notification_76()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_hh_transfer_notification_76()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Government_03_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Government_hh_transfer_notification_76);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_hh_transfer_notification_76() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_hh_transfer_notification_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_hh_transfer_notification_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Government_holder = Government_03_state->agents;
	while(current_xmachine_Government_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Government\tid\t%i\n", i, current_xmachine_Government_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Government_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Government_holder = current_xmachine_Government_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_hh_transfer_notification_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Government", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_hh_transfer_notification_76);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_hh_transfer_notification, f_handle, FLAME_m_hh_transfer_notification_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type hh_subsidy_notification for input layer 75 */

/** \struct FLAME_param_Government_hh_subsidy_notification_75
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Government_hh_subsidy_notification_75
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_hh_subsidy_notification *m = (m_hh_subsidy_notification*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Government_hh_subsidy_notification_75 *a = (struct FLAME_param_Government_hh_subsidy_notification_75 *)params;

	/* The filter */
	if((a->id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_hh_subsidy_notification_75(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_hh_subsidy_notification_75(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_hh_subsidy_notification_75\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Government_hh_subsidy_notification_75);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_hh_subsidy_notification_75()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_hh_subsidy_notification_75()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Government_02_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Government_hh_subsidy_notification_75);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_hh_subsidy_notification_75() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_hh_subsidy_notification_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_hh_subsidy_notification_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Government_holder = Government_02_state->agents;
	while(current_xmachine_Government_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Government\tid\t%i\n", i, current_xmachine_Government_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Government_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Government_holder = current_xmachine_Government_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_hh_subsidy_notification_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Government", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_hh_subsidy_notification_75);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_hh_subsidy_notification, f_handle, FLAME_m_hh_subsidy_notification_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type firm_transfer_notification for input layer 76 */

/** \struct FLAME_param_Government_firm_transfer_notification_76
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Government_firm_transfer_notification_76
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_firm_transfer_notification *m = (m_firm_transfer_notification*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Government_firm_transfer_notification_76 *a = (struct FLAME_param_Government_firm_transfer_notification_76 *)params;

	/* The filter */
	if((a->id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_firm_transfer_notification_76(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_firm_transfer_notification_76(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_firm_transfer_notification_76\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Government_firm_transfer_notification_76);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_firm_transfer_notification_76()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_firm_transfer_notification_76()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Government_03_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Government_firm_transfer_notification_76);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_firm_transfer_notification_76() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_firm_transfer_notification_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_firm_transfer_notification_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Government_holder = Government_03_state->agents;
	while(current_xmachine_Government_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Government\tid\t%i\n", i, current_xmachine_Government_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Government_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Government_holder = current_xmachine_Government_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_firm_transfer_notification_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Government", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_firm_transfer_notification_76);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_firm_transfer_notification, f_handle, FLAME_m_firm_transfer_notification_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type firm_subsidy_notification for input layer 75 */

/** \struct FLAME_param_Government_firm_subsidy_notification_75
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Government_firm_subsidy_notification_75
{
	int id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_firm_subsidy_notification *m = (m_firm_subsidy_notification*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Government_firm_subsidy_notification_75 *a = (struct FLAME_param_Government_firm_subsidy_notification_75 *)params;

	/* The filter */
	if((a->id == m->gov_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_firm_subsidy_notification_75(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_firm_subsidy_notification_75(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_firm_subsidy_notification_75\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Government_firm_subsidy_notification_75);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_firm_subsidy_notification_75()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_firm_subsidy_notification_75()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Government_02_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Government_firm_subsidy_notification_75);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_firm_subsidy_notification_75() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_firm_subsidy_notification_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_firm_subsidy_notification_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Government_holder = Government_02_state->agents;
	while(current_xmachine_Government_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Government\tid\t%i\n", i, current_xmachine_Government_holder->agent->id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Government_holder->agent->id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Government_holder = current_xmachine_Government_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_firm_subsidy_notification_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Government", i);
		
		printf("\tid=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_firm_subsidy_notification_75);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_firm_subsidy_notification, f_handle, FLAME_m_firm_subsidy_notification_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}
/* Filter handling functions for message type eurostat_send_specific_skills for input layer 2 */

/** \struct FLAME_param_Firm_eurostat_send_specific_skills_2
 * \brief Structure to hold the variables from an agent type for an input filter.
 */
struct FLAME_param_Firm_eurostat_send_specific_skills_2
{
	int region_id; /**< Agent memory variable required for the input filter */
};


/** \fn int FLAME_filter_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data_eurostat_send_specific_skills_sync(const void *msg, const void *params)
 * \brief The filter function for a message input used by libmboard in parallel.
 * \param msg The pointer to the message to be filtered.
 * \param params The pointer to the agent filter variable structure.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_filter_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data_eurostat_send_specific_skills_sync(const void *msg, const void *params)
{
	/* Variable used for the return code */
	int rc;
	/* Cast the message pointer to the correct message type */
	m_eurostat_send_specific_skills *m = (m_eurostat_send_specific_skills*)msg;
	/* Cast the params pointer to the correct agent filter variable structure */
	struct FLAME_param_Firm_eurostat_send_specific_skills_2 *a = (struct FLAME_param_Firm_eurostat_send_specific_skills_2 *)params;

	/* The filter */
	if((a->region_id == m->region_id)) rc = 1;
	else rc = 0;
	
	/* Testing code */
	/*
	printf("FLAME_filter_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data_eurostat_send_specific_skills_sync rc=%d\n", rc);*/
	
	/* Return the result of the filter */
	return rc;
}

/** \fn int FLAME_sync_filter_eurostat_send_specific_skills_2(const void *m, const void *composite_params)
 * \brief The composite filter function for a message input used by libmboard in parallel.
 * \param m The pointer to the message to be filtered.
 * \param composite_params The pointer to the composite agent filter variable structures.
 * \return The success (1) or failure (0) of the filter on the message.
 */
int FLAME_sync_filter_eurostat_send_specific_skills_2(const void *m, const void *composite_params)
{
	/* Testing code */
	/*
	printf("**** FLAME_sync_filter_eurostat_send_specific_skills_2\n");*/

	/* Variable used in for loops */
	int i;
	/* Pointer used to traverse composite params */
	char *ptr;
	/* List to hold the number of each agent type */
	int agent_count[1];
	/* Variable used for the return code */
	int rc;

	/* Assert that the composite params is valid and not null */
	assert(composite_params != NULL);
	/* Make ptr point to the start of composite params */
	ptr = (char *)composite_params;
	/* For each agent type record the number of agents
	 * and advance the traversal pointer */
	for(i = 0; i < 1; i++)
	{
		/* Testing code */
		/*printf("\tagent_count[%d] = %d\n", i, *(int*)ptr);*/
		
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}

	/* For each agent type agent */
	
	for(i = 0; i < agent_count[0]; i++)
	{
		/* Test code */
		/*printf("\t[%d] $agent_name", i);*/
		
		/* Test code */
		/*printf("\tregion_id=%i", *(int*)ptr);
		ptr += sizeof(int);*/
		/*printf("\n");*/
		
		/* For each function apply input filter.
		 * If filter successful return success immediately  */
		rc = FLAME_filter_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data_eurostat_send_specific_skills_sync(m, (void*)ptr);
		if ( rc == 1) return rc;
		
		
		/* Advance traversal pointer */
		ptr += sizeof(struct FLAME_param_Firm_eurostat_send_specific_skills_2);
	}
	

	/* If no filter is successful then return failure */
	return 0;
}

/** \fn int FLAME_build_filter_param_eurostat_send_specific_skills_2()
 * \brief Populate the parameters for a filter sync.
 * \return The return code, only returns 0 for success.
 */
int FLAME_build_filter_param_eurostat_send_specific_skills_2()
{
	/* Pointer to traverse parameter memory */
	char *ptr;
	/* Pointer to add agent type count to created memory */
	int  *ptr_count;
	/* List to hold counts of each agent type */
	int agent_count[1];
	/* List to hold the structure size of agent type filter variables */
	size_t agent_struct_size[1];
	/* The total parameter memory size */
	size_t cparam_size = 0;
	/* Variable used in for loops */
	int i;
	/* Variable used for the return code */
	int rc;
	/* TODO */
	int count = 0;
	/* Variable to point to a libmboard function */
    MBt_Function f_handle;
    /* Pointers for each filter variable type */
	int * int_pointer;
	

	/* For each agent type initialise number and structure size to be zero */
	for(i = 0; i < 1; i++)
	{
		agent_count[i] = 0;
		agent_struct_size[i] = 0;
	}

	/* Loop though all previous states of each agent type that hold agents that could use this filter */
	/* Add agent type state count to total agent type count */
	agent_count[0] += Firm_Firm_Start_Macro_Data_state->count;
	/* Make agent type struct size equal to the agent type filter variable structure size */
	agent_struct_size[0] = sizeof(struct FLAME_param_Firm_eurostat_send_specific_skills_2);
	

	/* Testing code */
	
	/*printf("FLAME_build_filter_param_eurostat_send_specific_skills_2() - agent_number = %d\n", 1);*/

	/* For each agent type add agent count to total agent count */
	for(i = 0; i < 1; i++)
	{
		count += agent_count[i];
	}

	/* Allocate memory required for the composite params */
	FLAME_m_eurostat_send_specific_skills_composite_params = cparams_create(1, agent_count, agent_struct_size, &cparam_size);
	/* Make the traversal pointer point to the start of the composite params */
	ptr = (char *)FLAME_m_eurostat_send_specific_skills_composite_params;
	/* For every agent type make the pointer value equal to the
	 * agent type count and advance the pointer on by the size of the value 
	 */
	for(i = 0; i < 1; i++)
	{
		ptr_count = (int*)ptr;
		*ptr_count = agent_count[i];
		ptr += sizeof(int);
	}
	/* For each agent in each state */
	
	current_xmachine_Firm_holder = Firm_Firm_Start_Macro_Data_state->agents;
	while(current_xmachine_Firm_holder)
	{
		/* For each filter variable add value to the composite params */
		
		/* Testing code */
		/*printf("[%d] Firm\tregion_id\t%i\n", i, current_xmachine_Firm_holder->agent->region_id);*/
		/* Point the correct type pointer to the traversal pointer */
		int_pointer = (int*)ptr;
		/* Make the pointer value equal to the agent variable value */
		*int_pointer = current_xmachine_Firm_holder->agent->region_id;
		/* Advance the traversal pointer */
		ptr += sizeof(int);
		/* Point to next agent in state list */
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}
	

	/* Testing code */
	/*ptr = (char *)FLAME_m_eurostat_send_specific_skills_composite_params;
	for(i = 0; i < 1; i++)
	{
		printf("\t*** agent_count[%d] = %d\n", i, *(int*)ptr);
		agent_count[i] = *(int*)ptr;
		ptr += sizeof(int);
	}
	
	for(i = 0; i < agent_count[0]; i++)
	{
		printf("\t*** [%d] Firm", i);
		
		printf("\tregion_id=%i", *(int*)ptr);
		ptr += sizeof(int);
		printf("\n");
	}
	*/

	/* Testing code */
	/*printf("cparam_size = %lu\n", cparam_size);*/

	/* Register the sync filter function with libmboard */
	rc = MB_Function_Register(&f_handle, &FLAME_sync_filter_eurostat_send_specific_skills_2);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while registering function\n");
		exit(1);
	}

	/* Assign filter function to board, assuming mboard has been created */
	rc = MB_Function_Assign(b_eurostat_send_specific_skills, f_handle, FLAME_m_eurostat_send_specific_skills_composite_params, cparam_size);
	if ( rc != MB_SUCCESS )
	{
		/* If failure write error message and quit */
		fprintf(stderr, "Error while assigning function to board\n");
		exit(1);
	}

	/* Return success return code */
	return 0;
}

