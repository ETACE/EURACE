/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"

/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
	temp_xmachine = NULL;
	p_xmachine = &temp_xmachine;
	temp_vacancies_message = NULL;
	p_vacancies_message = &temp_vacancies_message;
	temp_vacancies2_message = NULL;
	p_vacancies2_message = &temp_vacancies2_message;
	temp_firing_message = NULL;
	p_firing_message = &temp_firing_message;
	temp_job_application_message = NULL;
	p_job_application_message = &temp_job_application_message;
	temp_job_application2_message = NULL;
	p_job_application2_message = &temp_job_application2_message;
	temp_job_offer_message = NULL;
	p_job_offer_message = &temp_job_offer_message;
	temp_job_offer2_message = NULL;
	p_job_offer2_message = &temp_job_offer2_message;
	temp_job_acceptance_message = NULL;
	p_job_acceptance_message = &temp_job_acceptance_message;
	temp_job_acceptance2_message = NULL;
	p_job_acceptance2_message = &temp_job_acceptance2_message;
	temp_application_rejection_message = NULL;
	p_application_rejection_message = &temp_application_rejection_message;
	temp_application_rejection2_message = NULL;
	p_application_rejection2_message = &temp_application_rejection2_message;
	temp_quitting_message = NULL;
	p_quitting_message = &temp_quitting_message;
	temp_quitting2_message = NULL;
	p_quitting2_message = &temp_quitting2_message;
	temp_productivity_message = NULL;
	p_productivity_message = &temp_productivity_message;
	temp_capital_good_request_message = NULL;
	p_capital_good_request_message = &temp_capital_good_request_message;
	temp_capital_good_profit_distribution_message = NULL;
	p_capital_good_profit_distribution_message = &temp_capital_good_profit_distribution_message;
	temp_capital_good_delivery_message = NULL;
	p_capital_good_delivery_message = &temp_capital_good_delivery_message;
	temp_wage_payment_message = NULL;
	p_wage_payment_message = &temp_wage_payment_message;
	temp_quality_price_info_1_message = NULL;
	p_quality_price_info_1_message = &temp_quality_price_info_1_message;
	temp_quality_price_info_2_message = NULL;
	p_quality_price_info_2_message = &temp_quality_price_info_2_message;
	temp_update_mall_stock_message = NULL;
	p_update_mall_stock_message = &temp_update_mall_stock_message;
	temp_consumption_request_1_message = NULL;
	p_consumption_request_1_message = &temp_consumption_request_1_message;
	temp_consumption_request_2_message = NULL;
	p_consumption_request_2_message = &temp_consumption_request_2_message;
	temp_accepted_consumption_1_message = NULL;
	p_accepted_consumption_1_message = &temp_accepted_consumption_1_message;
	temp_accepted_consumption_2_message = NULL;
	p_accepted_consumption_2_message = &temp_accepted_consumption_2_message;
	temp_sales_message = NULL;
	p_sales_message = &temp_sales_message;
	temp_pay_capital_goods_message = NULL;
	p_pay_capital_goods_message = &temp_pay_capital_goods_message;
	temp_current_mall_stock_info_message = NULL;
	p_current_mall_stock_info_message = &temp_current_mall_stock_info_message;
	temp_specific_skill_update_message = NULL;
	p_specific_skill_update_message = &temp_specific_skill_update_message;
	temp_firm_send_data_message = NULL;
	p_firm_send_data_message = &temp_firm_send_data_message;
	temp_household_send_data_message = NULL;
	p_household_send_data_message = &temp_household_send_data_message;
	temp_market_research_send_specific_skills_message = NULL;
	p_market_research_send_specific_skills_message = &temp_market_research_send_specific_skills_message;
	temp_tax_payment_message = NULL;
	p_tax_payment_message = &temp_tax_payment_message;
	temp_interest_payment_message = NULL;
	p_interest_payment_message = &temp_interest_payment_message;
	temp_debt_installment_payment_message = NULL;
	p_debt_installment_payment_message = &temp_debt_installment_payment_message;
	temp_dividend_payment_message = NULL;
	p_dividend_payment_message = &temp_dividend_payment_message;
	temp_loan_request_message = NULL;
	p_loan_request_message = &temp_loan_request_message;
	temp_loan_conditions_message = NULL;
	p_loan_conditions_message = &temp_loan_conditions_message;
	temp_loan_acceptance_message = NULL;
	p_loan_acceptance_message = &temp_loan_acceptance_message;
	temp_stock_order_message = NULL;
	p_stock_order_message = &temp_stock_order_message;
	temp_stock_transaction_message = NULL;
	p_stock_transaction_message = &temp_stock_transaction_message;
	temp_bond_order_message = NULL;
	p_bond_order_message = &temp_bond_order_message;
	temp_bond_transaction_message = NULL;
	p_bond_transaction_message = &temp_bond_transaction_message;
	temp_gov_bond_order_message = NULL;
	p_gov_bond_order_message = &temp_gov_bond_order_message;
	temp_gov_bond_transaction_message = NULL;
	p_gov_bond_transaction_message = &temp_gov_bond_transaction_message;
	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/** \fn void initialise_unit_testing()
 * \brief Initialises framework for unit testing.
 */
void initialise_unit_testing()
{
	initialise_pointers();
	add_node(0, -SPINF, SPINF, -SPINF, SPINF, -SPINF, SPINF);
	current_node = *p_node_info;
	p_xmachine = &current_node->agents;
	current_xmachine = *p_xmachine;
	p_vacancies_message = &current_node->vacancies_messages;
	p_vacancies2_message = &current_node->vacancies2_messages;
	p_firing_message = &current_node->firing_messages;
	p_job_application_message = &current_node->job_application_messages;
	p_job_application2_message = &current_node->job_application2_messages;
	p_job_offer_message = &current_node->job_offer_messages;
	p_job_offer2_message = &current_node->job_offer2_messages;
	p_job_acceptance_message = &current_node->job_acceptance_messages;
	p_job_acceptance2_message = &current_node->job_acceptance2_messages;
	p_application_rejection_message = &current_node->application_rejection_messages;
	p_application_rejection2_message = &current_node->application_rejection2_messages;
	p_quitting_message = &current_node->quitting_messages;
	p_quitting2_message = &current_node->quitting2_messages;
	p_productivity_message = &current_node->productivity_messages;
	p_capital_good_request_message = &current_node->capital_good_request_messages;
	p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
	p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
	p_wage_payment_message = &current_node->wage_payment_messages;
	p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
	p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
	p_update_mall_stock_message = &current_node->update_mall_stock_messages;
	p_consumption_request_1_message = &current_node->consumption_request_1_messages;
	p_consumption_request_2_message = &current_node->consumption_request_2_messages;
	p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
	p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
	p_sales_message = &current_node->sales_messages;
	p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
	p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
	p_specific_skill_update_message = &current_node->specific_skill_update_messages;
	p_firm_send_data_message = &current_node->firm_send_data_messages;
	p_household_send_data_message = &current_node->household_send_data_messages;
	p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
	p_tax_payment_message = &current_node->tax_payment_messages;
	p_interest_payment_message = &current_node->interest_payment_messages;
	p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
	p_dividend_payment_message = &current_node->dividend_payment_messages;
	p_loan_request_message = &current_node->loan_request_messages;
	p_loan_conditions_message = &current_node->loan_conditions_messages;
	p_loan_acceptance_message = &current_node->loan_acceptance_messages;
	p_stock_order_message = &current_node->stock_order_messages;
	p_stock_transaction_message = &current_node->stock_transaction_messages;
	p_bond_order_message = &current_node->bond_order_messages;
	p_bond_transaction_message = &current_node->bond_transaction_messages;
	p_gov_bond_order_message = &current_node->gov_bond_order_messages;
	p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
}

/* add_location */
/** \fn void add_location(double point, location ** p_location)
 * \brief Adds a location in order into the location list.
 * \param point Position of an agent.
 * \param p_location Pointer Pointer to the location list.
 */
void add_location(double point, location ** p_location)
{
	location * current = *p_location;
	location * tmp = NULL;
	location * newlocation = NULL;
	int found = 0;
	
	while(found == 0)
	{
		if(current == NULL) found = 1;
		else if(point > current->point) found = 1;
		else
		{
			tmp = current;
			current = current->next;
		}
	}
	
	newlocation = (location *)malloc(sizeof(location));
	CHECK_POINTER(newlocation);	
	if(tmp)
	{
		tmp->next = newlocation;
	}
	else
	{
		*p_location = newlocation;
	}
	
	newlocation->next = current;
	newlocation->point = point;
}

/* freelocations */
/** \fn void freelocations(location ** p_location)
 * \brief Free locations from the location list.
 * \param p_location Pointer Pointer to the location list.
 */
void freelocations(location ** p_location)
{
	location * head = *p_location;
	location * tmp = NULL;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_location = NULL;
}

/* add_xmachine */
/** \fn xmachine * add_xmachine()
 * \brief Add an X-machine to the current being used X-machine list.
 * \return Pointer to the added X-machine.
 */
xmachine * add_xmachine()
{
	xmachine * current = (xmachine *)malloc(sizeof(xmachine));
	CHECK_POINTER(current);

	current->xmachine_Firm = NULL;
	current->xmachine_Household = NULL;
	current->xmachine_Mall = NULL;
	current->xmachine_IGFirm = NULL;
	current->xmachine_Market_Research = NULL;
	current->xmachine_Clearinghouse = NULL;
	current->xmachine_Bank = NULL;
	current->next = *p_xmachine;
	*p_xmachine = current;
	
	current_node->agent_total++;

/* add by cg for round-robin so that set_ has something to point at */
	//current_xmachine = current;
	
	return current;
}

void init_int_static_array(int * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) array[i] = 0;
}

void init_float_static_array(float * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_double_static_array(double* array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_char_static_array(char * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) array[i] = '\0';
}



void init_employee(employee * temp)
{
	(*temp).id = 0;
	(*temp).region_id = 0;
	(*temp).wage = 0.0;
	(*temp).general_skill = 0;
	(*temp).specific_skill = 0.0;

}

void init_employee_static_array(employee * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_employee(&array[i]);
}

void free_employee(employee * temp)
{

}

void free_employee_static_array(employee * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_employee(&array[i]);
}

void copy_employee(employee * from, employee * to)
{
	(*to).id = (*from).id;
	(*to).region_id = (*from).region_id;
	(*to).wage = (*from).wage;
	(*to).general_skill = (*from).general_skill;
	(*to).specific_skill = (*from).specific_skill;
}

void copy_employee_static_array(employee * from, employee * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_employee(&from[i], &to[i]);
	}
}


void init_vacancy(vacancy * temp)
{
	(*temp).firm_id = 0;
	(*temp).region_id = 0;
	(*temp).wage_offer = 0.0;

}

void init_vacancy_static_array(vacancy * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_vacancy(&array[i]);
}

void free_vacancy(vacancy * temp)
{

}

void free_vacancy_static_array(vacancy * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_vacancy(&array[i]);
}

void copy_vacancy(vacancy * from, vacancy * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).region_id = (*from).region_id;
	(*to).wage_offer = (*from).wage_offer;
}

void copy_vacancy_static_array(vacancy * from, vacancy * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_vacancy(&from[i], &to[i]);
	}
}


void init_job_application(job_application * temp)
{
	(*temp).worker_id = 0;
	(*temp).region_id = 0;
	(*temp).general_skill = 0;
	(*temp).specific_skill = 0.0;

}

void init_job_application_static_array(job_application * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_job_application(&array[i]);
}

void free_job_application(job_application * temp)
{

}

void free_job_application_static_array(job_application * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_job_application(&array[i]);
}

void copy_job_application(job_application * from, job_application * to)
{
	(*to).worker_id = (*from).worker_id;
	(*to).region_id = (*from).region_id;
	(*to).general_skill = (*from).general_skill;
	(*to).specific_skill = (*from).specific_skill;
}

void copy_job_application_static_array(job_application * from, job_application * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_job_application(&from[i], &to[i]);
	}
}


void init_job_offer(job_offer * temp)
{
	(*temp).firm_id = 0;
	(*temp).region_id = 0;
	(*temp).wage_offer = 0.0;

}

void init_job_offer_static_array(job_offer * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_job_offer(&array[i]);
}

void free_job_offer(job_offer * temp)
{

}

void free_job_offer_static_array(job_offer * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_job_offer(&array[i]);
}

void copy_job_offer(job_offer * from, job_offer * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).region_id = (*from).region_id;
	(*to).wage_offer = (*from).wage_offer;
}

void copy_job_offer_static_array(job_offer * from, job_offer * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_job_offer(&from[i], &to[i]);
	}
}


void init_consumption_goods_offer(consumption_goods_offer * temp)
{
	(*temp).id = 0;
	(*temp).quality = 0.0;
	(*temp).price = 0.0;

}

void init_consumption_goods_offer_static_array(consumption_goods_offer * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_consumption_goods_offer(&array[i]);
}

void free_consumption_goods_offer(consumption_goods_offer * temp)
{

}

void free_consumption_goods_offer_static_array(consumption_goods_offer * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_consumption_goods_offer(&array[i]);
}

void copy_consumption_goods_offer(consumption_goods_offer * from, consumption_goods_offer * to)
{
	(*to).id = (*from).id;
	(*to).quality = (*from).quality;
	(*to).price = (*from).price;
}

void copy_consumption_goods_offer_static_array(consumption_goods_offer * from, consumption_goods_offer * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_consumption_goods_offer(&from[i], &to[i]);
	}
}


void init_consumption_request(consumption_request * temp)
{
	(*temp).worker_id = 0;
	(*temp).firm_id = 0;
	(*temp).quantity = 0.0;

}

void init_consumption_request_static_array(consumption_request * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_consumption_request(&array[i]);
}

void free_consumption_request(consumption_request * temp)
{

}

void free_consumption_request_static_array(consumption_request * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_consumption_request(&array[i]);
}

void copy_consumption_request(consumption_request * from, consumption_request * to)
{
	(*to).worker_id = (*from).worker_id;
	(*to).firm_id = (*from).firm_id;
	(*to).quantity = (*from).quantity;
}

void copy_consumption_request_static_array(consumption_request * from, consumption_request * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_consumption_request(&from[i], &to[i]);
	}
}


void init_mall_info(mall_info * temp)
{
	(*temp).mall_id = 0;
	(*temp).critical_stock = 0.0;
	(*temp).current_stock = 0.0;

}

void init_mall_info_static_array(mall_info * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_mall_info(&array[i]);
}

void free_mall_info(mall_info * temp)
{

}

void free_mall_info_static_array(mall_info * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_mall_info(&array[i]);
}

void copy_mall_info(mall_info * from, mall_info * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).critical_stock = (*from).critical_stock;
	(*to).current_stock = (*from).current_stock;
}

void copy_mall_info_static_array(mall_info * from, mall_info * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_mall_info(&from[i], &to[i]);
	}
}


void init_mall_quality_price_info(mall_quality_price_info * temp)
{
	(*temp).mall_id = 0;
	(*temp).firm_id = 0;
	(*temp).mall_region_id = 0;
	(*temp).quality = 0.0;
	(*temp).price = 0.0;
	(*temp).available = 0;

}

void init_mall_quality_price_info_static_array(mall_quality_price_info * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_mall_quality_price_info(&array[i]);
}

void free_mall_quality_price_info(mall_quality_price_info * temp)
{

}

void free_mall_quality_price_info_static_array(mall_quality_price_info * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_mall_quality_price_info(&array[i]);
}

void copy_mall_quality_price_info(mall_quality_price_info * from, mall_quality_price_info * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).firm_id = (*from).firm_id;
	(*to).mall_region_id = (*from).mall_region_id;
	(*to).quality = (*from).quality;
	(*to).price = (*from).price;
	(*to).available = (*from).available;
}

void copy_mall_quality_price_info_static_array(mall_quality_price_info * from, mall_quality_price_info * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_mall_quality_price_info(&from[i], &to[i]);
	}
}


void init_mall_stock(mall_stock * temp)
{
	(*temp).firm_id = 0;
	(*temp).stock = 0.0;
	(*temp).price = 0.0;
	(*temp).quality = 0.0;

}

void init_mall_stock_static_array(mall_stock * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_mall_stock(&array[i]);
}

void free_mall_stock(mall_stock * temp)
{

}

void free_mall_stock_static_array(mall_stock * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_mall_stock(&array[i]);
}

void copy_mall_stock(mall_stock * from, mall_stock * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).stock = (*from).stock;
	(*to).price = (*from).price;
	(*to).quality = (*from).quality;
}

void copy_mall_stock_static_array(mall_stock * from, mall_stock * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_mall_stock(&from[i], &to[i]);
	}
}


void init_delivery_volume_per_mall(delivery_volume_per_mall * temp)
{
	(*temp).mall_id = 0;
	(*temp).quantity = 0.0;
	(*temp).price = 0.0;
	(*temp).quality = 0.0;

}

void init_delivery_volume_per_mall_static_array(delivery_volume_per_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_delivery_volume_per_mall(&array[i]);
}

void free_delivery_volume_per_mall(delivery_volume_per_mall * temp)
{

}

void free_delivery_volume_per_mall_static_array(delivery_volume_per_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_delivery_volume_per_mall(&array[i]);
}

void copy_delivery_volume_per_mall(delivery_volume_per_mall * from, delivery_volume_per_mall * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).quantity = (*from).quantity;
	(*to).price = (*from).price;
	(*to).quality = (*from).quality;
}

void copy_delivery_volume_per_mall_static_array(delivery_volume_per_mall * from, delivery_volume_per_mall * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_delivery_volume_per_mall(&from[i], &to[i]);
	}
}


void init_logit_firm_id(logit_firm_id * temp)
{
	(*temp).logit = 0.0;
	(*temp).firm_id = 0;

}

void init_logit_firm_id_static_array(logit_firm_id * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_logit_firm_id(&array[i]);
}

void free_logit_firm_id(logit_firm_id * temp)
{

}

void free_logit_firm_id_static_array(logit_firm_id * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_logit_firm_id(&array[i]);
}

void copy_logit_firm_id(logit_firm_id * from, logit_firm_id * to)
{
	(*to).logit = (*from).logit;
	(*to).firm_id = (*from).firm_id;
}

void copy_logit_firm_id_static_array(logit_firm_id * from, logit_firm_id * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_logit_firm_id(&from[i], &to[i]);
	}
}


void init_sales_in_mall(sales_in_mall * temp)
{
	(*temp).firm_id = 0;
	(*temp).sales = 0.0;

}

void init_sales_in_mall_static_array(sales_in_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_sales_in_mall(&array[i]);
}

void free_sales_in_mall(sales_in_mall * temp)
{

}

void free_sales_in_mall_static_array(sales_in_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_sales_in_mall(&array[i]);
}

void copy_sales_in_mall(sales_in_mall * from, sales_in_mall * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).sales = (*from).sales;
}

void copy_sales_in_mall_static_array(sales_in_mall * from, sales_in_mall * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_sales_in_mall(&from[i], &to[i]);
	}
}


void init_ordered_quantity(ordered_quantity * temp)
{
	(*temp).firm_id = 0;
	(*temp).quantity = 0.0;
	(*temp).price = 0.0;

}

void init_ordered_quantity_static_array(ordered_quantity * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_ordered_quantity(&array[i]);
}

void free_ordered_quantity(ordered_quantity * temp)
{

}

void free_ordered_quantity_static_array(ordered_quantity * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_ordered_quantity(&array[i]);
}

void copy_ordered_quantity(ordered_quantity * from, ordered_quantity * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).quantity = (*from).quantity;
	(*to).price = (*from).price;
}

void copy_ordered_quantity_static_array(ordered_quantity * from, ordered_quantity * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_ordered_quantity(&from[i], &to[i]);
	}
}


void init_received_quantities(received_quantities * temp)
{
	(*temp).firm_id = 0;
	(*temp).quantity = 0.0;

}

void init_received_quantities_static_array(received_quantities * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_received_quantities(&array[i]);
}

void free_received_quantities(received_quantities * temp)
{

}

void free_received_quantities_static_array(received_quantities * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_received_quantities(&array[i]);
}

void copy_received_quantities(received_quantities * from, received_quantities * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).quantity = (*from).quantity;
}

void copy_received_quantities_static_array(received_quantities * from, received_quantities * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_received_quantities(&from[i], &to[i]);
	}
}


void init_sold_quantities_per_mall(sold_quantities_per_mall * temp)
{
	(*temp).mall_id = 0;
	(*temp).sold_quantity = 0.0;
	(*temp).stock_empty = 0;
	(*temp).estimated_demand = 0.0;

}

void init_sold_quantities_per_mall_static_array(sold_quantities_per_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_sold_quantities_per_mall(&array[i]);
}

void free_sold_quantities_per_mall(sold_quantities_per_mall * temp)
{

}

void free_sold_quantities_per_mall_static_array(sold_quantities_per_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_sold_quantities_per_mall(&array[i]);
}

void copy_sold_quantities_per_mall(sold_quantities_per_mall * from, sold_quantities_per_mall * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).sold_quantity = (*from).sold_quantity;
	(*to).stock_empty = (*from).stock_empty;
	(*to).estimated_demand = (*from).estimated_demand;
}

void copy_sold_quantities_per_mall_static_array(sold_quantities_per_mall * from, sold_quantities_per_mall * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_sold_quantities_per_mall(&from[i], &to[i]);
	}
}


void init_sales_statistics(sales_statistics * temp)
{
	(*temp).mall_id = 0;
	(*temp).period = 0;
	(*temp).sales = 0.0;

}

void init_sales_statistics_static_array(sales_statistics * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_sales_statistics(&array[i]);
}

void free_sales_statistics(sales_statistics * temp)
{

}

void free_sales_statistics_static_array(sales_statistics * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_sales_statistics(&array[i]);
}

void copy_sales_statistics(sales_statistics * from, sales_statistics * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).period = (*from).period;
	(*to).sales = (*from).sales;
}

void copy_sales_statistics_static_array(sales_statistics * from, sales_statistics * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_sales_statistics(&from[i], &to[i]);
	}
}


void init_debt_item(debt_item * temp)
{
	(*temp).bank_id = 0;
	(*temp).loan_value = 0.0;
	(*temp).interest_rate = 0.0;
	(*temp).interest_payment = 0.0;
	(*temp).debt_installment_payment = 0.0;
	(*temp).nr_periods_before_maturity = 0;

}

void init_debt_item_static_array(debt_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_debt_item(&array[i]);
}

void free_debt_item(debt_item * temp)
{

}

void free_debt_item_static_array(debt_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_debt_item(&array[i]);
}

void copy_debt_item(debt_item * from, debt_item * to)
{
	(*to).bank_id = (*from).bank_id;
	(*to).loan_value = (*from).loan_value;
	(*to).interest_rate = (*from).interest_rate;
	(*to).interest_payment = (*from).interest_payment;
	(*to).debt_installment_payment = (*from).debt_installment_payment;
	(*to).nr_periods_before_maturity = (*from).nr_periods_before_maturity;
}

void copy_debt_item_static_array(debt_item * from, debt_item * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_debt_item(&from[i], &to[i]);
	}
}


void init_capital_stock_item(capital_stock_item * temp)
{
	(*temp).units = 0.0;
	(*temp).purchase_price = 0.0;
	(*temp).productivity = 0.0;
	(*temp).depreciation_units_per_period = 0.0;

}

void init_capital_stock_item_static_array(capital_stock_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_capital_stock_item(&array[i]);
}

void free_capital_stock_item(capital_stock_item * temp)
{

}

void free_capital_stock_item_static_array(capital_stock_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_capital_stock_item(&array[i]);
}

void copy_capital_stock_item(capital_stock_item * from, capital_stock_item * to)
{
	(*to).units = (*from).units;
	(*to).purchase_price = (*from).purchase_price;
	(*to).productivity = (*from).productivity;
	(*to).depreciation_units_per_period = (*from).depreciation_units_per_period;
}

void copy_capital_stock_item_static_array(capital_stock_item * from, capital_stock_item * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_capital_stock_item(&from[i], &to[i]);
	}
}


void init_household_data(household_data * temp)
{
	(*temp).region_id = 0;
	(*temp).no_households = 0;
	(*temp).no_households_skill_1 = 0;
	(*temp).no_households_skill_2 = 0;
	(*temp).no_households_skill_3 = 0;
	(*temp).no_households_skill_4 = 0;
	(*temp).no_households_skill_5 = 0;
	(*temp).employed = 0;
	(*temp).employed_skill_1 = 0;
	(*temp).employed_skill_2 = 0;
	(*temp).employed_skill_3 = 0;
	(*temp).employed_skill_4 = 0;
	(*temp).employed_skill_5 = 0;
	(*temp).unemployed = 0;
	(*temp).unemployment_rate = 0.0;
	(*temp).unemployment_rate_skill_1 = 0.0;
	(*temp).unemployment_rate_skill_2 = 0.0;
	(*temp).unemployment_rate_skill_3 = 0.0;
	(*temp).unemployment_rate_skill_4 = 0.0;
	(*temp).unemployment_rate_skill_5 = 0.0;
	(*temp).average_wage = 0.0;
	(*temp).average_wage_skill_1 = 0.0;
	(*temp).average_wage_skill_2 = 0.0;
	(*temp).average_wage_skill_3 = 0.0;
	(*temp).average_wage_skill_4 = 0.0;
	(*temp).average_wage_skill_5 = 0.0;
	(*temp).average_s_skill = 0.0;
	(*temp).average_s_skill_1 = 0.0;
	(*temp).average_s_skill_2 = 0.0;
	(*temp).average_s_skill_3 = 0.0;
	(*temp).average_s_skill_4 = 0.0;
	(*temp).average_s_skill_5 = 0.0;

}

void init_household_data_static_array(household_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_household_data(&array[i]);
}

void free_household_data(household_data * temp)
{

}

void free_household_data_static_array(household_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_household_data(&array[i]);
}

void copy_household_data(household_data * from, household_data * to)
{
	(*to).region_id = (*from).region_id;
	(*to).no_households = (*from).no_households;
	(*to).no_households_skill_1 = (*from).no_households_skill_1;
	(*to).no_households_skill_2 = (*from).no_households_skill_2;
	(*to).no_households_skill_3 = (*from).no_households_skill_3;
	(*to).no_households_skill_4 = (*from).no_households_skill_4;
	(*to).no_households_skill_5 = (*from).no_households_skill_5;
	(*to).employed = (*from).employed;
	(*to).employed_skill_1 = (*from).employed_skill_1;
	(*to).employed_skill_2 = (*from).employed_skill_2;
	(*to).employed_skill_3 = (*from).employed_skill_3;
	(*to).employed_skill_4 = (*from).employed_skill_4;
	(*to).employed_skill_5 = (*from).employed_skill_5;
	(*to).unemployed = (*from).unemployed;
	(*to).unemployment_rate = (*from).unemployment_rate;
	(*to).unemployment_rate_skill_1 = (*from).unemployment_rate_skill_1;
	(*to).unemployment_rate_skill_2 = (*from).unemployment_rate_skill_2;
	(*to).unemployment_rate_skill_3 = (*from).unemployment_rate_skill_3;
	(*to).unemployment_rate_skill_4 = (*from).unemployment_rate_skill_4;
	(*to).unemployment_rate_skill_5 = (*from).unemployment_rate_skill_5;
	(*to).average_wage = (*from).average_wage;
	(*to).average_wage_skill_1 = (*from).average_wage_skill_1;
	(*to).average_wage_skill_2 = (*from).average_wage_skill_2;
	(*to).average_wage_skill_3 = (*from).average_wage_skill_3;
	(*to).average_wage_skill_4 = (*from).average_wage_skill_4;
	(*to).average_wage_skill_5 = (*from).average_wage_skill_5;
	(*to).average_s_skill = (*from).average_s_skill;
	(*to).average_s_skill_1 = (*from).average_s_skill_1;
	(*to).average_s_skill_2 = (*from).average_s_skill_2;
	(*to).average_s_skill_3 = (*from).average_s_skill_3;
	(*to).average_s_skill_4 = (*from).average_s_skill_4;
	(*to).average_s_skill_5 = (*from).average_s_skill_5;
}

void copy_household_data_static_array(household_data * from, household_data * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_household_data(&from[i], &to[i]);
	}
}


void init_firm_data(firm_data * temp)
{
	(*temp).region_id = 0;
	(*temp).firms = 0;
	(*temp).vacancies = 0;
	(*temp).employees = 0;
	(*temp).employees_skill_1 = 0;
	(*temp).employees_skill_2 = 0;
	(*temp).employees_skill_3 = 0;
	(*temp).employees_skill_4 = 0;
	(*temp).employees_skill_5 = 0;
	(*temp).average_wage = 0.0;
	(*temp).average_wage_skill_1 = 0.0;
	(*temp).average_wage_skill_2 = 0.0;
	(*temp).average_wage_skill_3 = 0.0;
	(*temp).average_wage_skill_4 = 0.0;
	(*temp).average_wage_skill_5 = 0.0;
	(*temp).average_s_skill = 0.0;
	(*temp).average_s_skill_1 = 0.0;
	(*temp).average_s_skill_2 = 0.0;
	(*temp).average_s_skill_3 = 0.0;
	(*temp).average_s_skill_4 = 0.0;
	(*temp).average_s_skill_5 = 0.0;

}

void init_firm_data_static_array(firm_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_firm_data(&array[i]);
}

void free_firm_data(firm_data * temp)
{

}

void free_firm_data_static_array(firm_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_firm_data(&array[i]);
}

void copy_firm_data(firm_data * from, firm_data * to)
{
	(*to).region_id = (*from).region_id;
	(*to).firms = (*from).firms;
	(*to).vacancies = (*from).vacancies;
	(*to).employees = (*from).employees;
	(*to).employees_skill_1 = (*from).employees_skill_1;
	(*to).employees_skill_2 = (*from).employees_skill_2;
	(*to).employees_skill_3 = (*from).employees_skill_3;
	(*to).employees_skill_4 = (*from).employees_skill_4;
	(*to).employees_skill_5 = (*from).employees_skill_5;
	(*to).average_wage = (*from).average_wage;
	(*to).average_wage_skill_1 = (*from).average_wage_skill_1;
	(*to).average_wage_skill_2 = (*from).average_wage_skill_2;
	(*to).average_wage_skill_3 = (*from).average_wage_skill_3;
	(*to).average_wage_skill_4 = (*from).average_wage_skill_4;
	(*to).average_wage_skill_5 = (*from).average_wage_skill_5;
	(*to).average_s_skill = (*from).average_s_skill;
	(*to).average_s_skill_1 = (*from).average_s_skill_1;
	(*to).average_s_skill_2 = (*from).average_s_skill_2;
	(*to).average_s_skill_3 = (*from).average_s_skill_3;
	(*to).average_s_skill_4 = (*from).average_s_skill_4;
	(*to).average_s_skill_5 = (*from).average_s_skill_5;
}

void copy_firm_data_static_array(firm_data * from, firm_data * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_firm_data(&from[i], &to[i]);
	}
}



xmachine_memory_Firm * init_Firm_agent()
{
	xmachine_memory_Firm * current = (xmachine_memory_Firm *)malloc(sizeof(xmachine_memory_Firm));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	init_employee_array(&current->employees);
	current->wage_offer = 0.0;
	current->technology = 0.0;
	current->no_employees = 0;
	current->no_employees_skill_1 = 0;
	current->no_employees_skill_2 = 0;
	current->no_employees_skill_3 = 0;
	current->no_employees_skill_4 = 0;
	current->no_employees_skill_5 = 0;
	current->vacancies = 0;
	current->average_g_skill = 0.0;
	current->average_s_skill_of_1 = 0.0;
	current->average_s_skill_of_2 = 0.0;
	current->average_s_skill_of_3 = 0.0;
	current->average_s_skill_of_4 = 0.0;
	current->average_s_skill_of_5 = 0.0;
	current->wage_offer_for_skill_1 = 0.0;
	current->wage_offer_for_skill_2 = 0.0;
	current->wage_offer_for_skill_3 = 0.0;
	current->wage_offer_for_skill_4 = 0.0;
	current->wage_offer_for_skill_5 = 0.0;
	current->wage_update_was_made = 0;
	current->share_net_investments = 0.0;
	current->mean_wage = 0.0;
	current->needed_capital_stock = 0.0;
	current->actual_cap_price = 0.0;
	current->mean_specific_skills = 0.0;
	current->planned_production_quantity = 0.0;
	current->production_quantity = 0.0;
	current->unit_costs = 0.0;
	current->planned_production_costs = 0.0;
	current->production_costs = 0.0;
	current->revenue_per_day = 0.0;
	current->technological_frontier = 0.0;
	current->cum_revenue = 0.0;
	current->out_of_stock_costs = 0.0;
	init_sales_statistics_array(&current->malls_sales_statistics);
	current->quality = 0.0;
	current->price = 0.0;
	current->price_last_month = 0.0;
	init_capital_stock_item_array(&current->capital_stock);
	current->total_units_capital_stock = 0.0;
	current->total_value_capital_stock = 0.0;
	current->total_capital_depreciation_value = 0.0;
	current->total_capital_depreciation_units = 0.0;
	current->employees_needed = 0;
	init_sold_quantities_per_mall_array(&current->sold_quantities);
	current->total_sold_quantity = 0.0;
	current->cum_total_sold_quantity = 0.0;
	init_delivery_volume_per_mall_array(&current->delivery_volume);
	init_delivery_volume_per_mall_array(&current->planned_delivery_volume);
	init_mall_info_array(&current->current_mall_stocks);
	current->demand_capital_stock = 0.0;
	init_double_array(&current->last_planned_production_quantities);
	current->day_of_month_to_act = 0;
	current->gov_id = 0;
	current->bank_id = 0;
	current->ebit = 0.0;
	current->payment_account = 0.0;
	current->earnings = 0.0;
	current->tax_rate_corporate = 0.0;
	current->tax_payment = 0.0;
	current->net_earnings = 0.0;
	current->previous_net_earnings = 0.0;
	init_debt_item_array(&current->loans);
	current->total_interest_payment = 0.0;
	current->total_debt_installment_payment = 0.0;
	current->total_debt = 0.0;
	current->total_dividend_payment = 0.0;
	current->total_value_local_inventory = 0.0;
	current->total_assets = 0.0;
	current->planned_cum_revenue = 0.0;
	current->planned_total_interest_payment = 0.0;
	current->planned_total_debt_installment_payment = 0.0;
	current->planned_total_dividend_payment = 0.0;
	current->direct_financial_needs = 0.0;
	current->delayed_financial_needs = 0.0;
	current->total_financial_needs = 0.0;
	current->internal_financial_needs = 0.0;
	current->external_financial_needs = 0.0;
	current->total_external_financing_obtained = 0.0;
	current->direct_financial_needs_require_external_financing = 0;
	current->delayed_financial_needs_require_external_financing = 0;
	current->current_share_price = 0.0;
	current->current_shares_outstanding = 0.0;
	current->previous_dividend_per_share = 0.0;
	current->current_dividend_per_share = 0.0;
	current->previous_dividend_per_earnings = 0.0;
	current->current_dividend_per_earnings = 0.0;
	current->earnings_per_share_ratio = 0.0;
	current->debt_earnings_ratio = 0.0;
	current->price_earnings_ratio = 0.0;
	current->retained_earnings_ratio = 0.0;
	current->earnings_per_share_ratio_growth = 0.0;
	current->critical_price_earnings_ratio = 0.0;
	current->critical_earnings_per_share_ratio = 0.0;
	current->target_loans = 0.0;
	current->target_equity = 0.0;
	current->bonds_issue_target = 0.0;
	current->stocks_issue_target = 0.0;
	current->range = 0.0;
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_Firm_agent(xmachine_memory_Firm * tmp)
{
	free_employee_array(&tmp->employees);
	free_sales_statistics_array(&tmp->malls_sales_statistics);
	free_capital_stock_item_array(&tmp->capital_stock);
	free_sold_quantities_per_mall_array(&tmp->sold_quantities);
	free_delivery_volume_per_mall_array(&tmp->delivery_volume);
	free_delivery_volume_per_mall_array(&tmp->planned_delivery_volume);
	free_mall_info_array(&tmp->current_mall_stocks);
	free_double_array(&tmp->last_planned_production_quantities);
	free_debt_item_array(&tmp->loans);
	
}

void add_Firm_agent_internal(xmachine_memory_Firm * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Firm = current;
}

/** \fn void add_Firm_agent(int id, int region_id, employee_array * employees, double wage_offer, double technology, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, int vacancies, double average_g_skill, double average_s_skill_of_1, double average_s_skill_of_2, double average_s_skill_of_3, double average_s_skill_of_4, double average_s_skill_of_5, double wage_offer_for_skill_1, double wage_offer_for_skill_2, double wage_offer_for_skill_3, double wage_offer_for_skill_4, double wage_offer_for_skill_5, int wage_update_was_made, double share_net_investments, double mean_wage, double needed_capital_stock, double actual_cap_price, double mean_specific_skills, double planned_production_quantity, double production_quantity, double unit_costs, double planned_production_costs, double production_costs, double revenue_per_day, double technological_frontier, double cum_revenue, double out_of_stock_costs, sales_statistics_array * malls_sales_statistics, double quality, double price, double price_last_month, capital_stock_item_array * capital_stock, double total_units_capital_stock, double total_value_capital_stock, double total_capital_depreciation_value, double total_capital_depreciation_units, int employees_needed, sold_quantities_per_mall_array * sold_quantities, double total_sold_quantity, double cum_total_sold_quantity, delivery_volume_per_mall_array * delivery_volume, delivery_volume_per_mall_array * planned_delivery_volume, mall_info_array * current_mall_stocks, double demand_capital_stock, double_array * last_planned_production_quantities, int day_of_month_to_act, int gov_id, int bank_id, double ebit, double payment_account, double earnings, double tax_rate_corporate, double tax_payment, double net_earnings, double previous_net_earnings, debt_item_array * loans, double total_interest_payment, double total_debt_installment_payment, double total_debt, double total_dividend_payment, double total_value_local_inventory, double total_assets, double planned_cum_revenue, double planned_total_interest_payment, double planned_total_debt_installment_payment, double planned_total_dividend_payment, double direct_financial_needs, double delayed_financial_needs, double total_financial_needs, double internal_financial_needs, double external_financial_needs, double total_external_financing_obtained, int direct_financial_needs_require_external_financing, int delayed_financial_needs_require_external_financing, double current_share_price, double current_shares_outstanding, double previous_dividend_per_share, double current_dividend_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double earnings_per_share_ratio, double debt_earnings_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, double target_loans, double target_equity, double bonds_issue_target, double stocks_issue_target, double range, double posx, double posy)
 * \brief Add Firm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param employees Variable for the X-machine memory.
 * \param wage_offer Variable for the X-machine memory.
 * \param technology Variable for the X-machine memory.
 * \param no_employees Variable for the X-machine memory.
 * \param no_employees_skill_1 Variable for the X-machine memory.
 * \param no_employees_skill_2 Variable for the X-machine memory.
 * \param no_employees_skill_3 Variable for the X-machine memory.
 * \param no_employees_skill_4 Variable for the X-machine memory.
 * \param no_employees_skill_5 Variable for the X-machine memory.
 * \param vacancies Variable for the X-machine memory.
 * \param average_g_skill Variable for the X-machine memory.
 * \param average_s_skill_of_1 Variable for the X-machine memory.
 * \param average_s_skill_of_2 Variable for the X-machine memory.
 * \param average_s_skill_of_3 Variable for the X-machine memory.
 * \param average_s_skill_of_4 Variable for the X-machine memory.
 * \param average_s_skill_of_5 Variable for the X-machine memory.
 * \param wage_offer_for_skill_1 Variable for the X-machine memory.
 * \param wage_offer_for_skill_2 Variable for the X-machine memory.
 * \param wage_offer_for_skill_3 Variable for the X-machine memory.
 * \param wage_offer_for_skill_4 Variable for the X-machine memory.
 * \param wage_offer_for_skill_5 Variable for the X-machine memory.
 * \param wage_update_was_made Variable for the X-machine memory.
 * \param share_net_investments Variable for the X-machine memory.
 * \param mean_wage Variable for the X-machine memory.
 * \param needed_capital_stock Variable for the X-machine memory.
 * \param actual_cap_price Variable for the X-machine memory.
 * \param mean_specific_skills Variable for the X-machine memory.
 * \param planned_production_quantity Variable for the X-machine memory.
 * \param production_quantity Variable for the X-machine memory.
 * \param unit_costs Variable for the X-machine memory.
 * \param planned_production_costs Variable for the X-machine memory.
 * \param production_costs Variable for the X-machine memory.
 * \param revenue_per_day Variable for the X-machine memory.
 * \param technological_frontier Variable for the X-machine memory.
 * \param cum_revenue Variable for the X-machine memory.
 * \param out_of_stock_costs Variable for the X-machine memory.
 * \param malls_sales_statistics Variable for the X-machine memory.
 * \param quality Variable for the X-machine memory.
 * \param price Variable for the X-machine memory.
 * \param price_last_month Variable for the X-machine memory.
 * \param capital_stock Variable for the X-machine memory.
 * \param total_units_capital_stock Variable for the X-machine memory.
 * \param total_value_capital_stock Variable for the X-machine memory.
 * \param total_capital_depreciation_value Variable for the X-machine memory.
 * \param total_capital_depreciation_units Variable for the X-machine memory.
 * \param employees_needed Variable for the X-machine memory.
 * \param sold_quantities Variable for the X-machine memory.
 * \param total_sold_quantity Variable for the X-machine memory.
 * \param cum_total_sold_quantity Variable for the X-machine memory.
 * \param delivery_volume Variable for the X-machine memory.
 * \param planned_delivery_volume Variable for the X-machine memory.
 * \param current_mall_stocks Variable for the X-machine memory.
 * \param demand_capital_stock Variable for the X-machine memory.
 * \param last_planned_production_quantities Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param gov_id Variable for the X-machine memory.
 * \param bank_id Variable for the X-machine memory.
 * \param ebit Variable for the X-machine memory.
 * \param payment_account Variable for the X-machine memory.
 * \param earnings Variable for the X-machine memory.
 * \param tax_rate_corporate Variable for the X-machine memory.
 * \param tax_payment Variable for the X-machine memory.
 * \param net_earnings Variable for the X-machine memory.
 * \param previous_net_earnings Variable for the X-machine memory.
 * \param loans Variable for the X-machine memory.
 * \param total_interest_payment Variable for the X-machine memory.
 * \param total_debt_installment_payment Variable for the X-machine memory.
 * \param total_debt Variable for the X-machine memory.
 * \param total_dividend_payment Variable for the X-machine memory.
 * \param total_value_local_inventory Variable for the X-machine memory.
 * \param total_assets Variable for the X-machine memory.
 * \param planned_cum_revenue Variable for the X-machine memory.
 * \param planned_total_interest_payment Variable for the X-machine memory.
 * \param planned_total_debt_installment_payment Variable for the X-machine memory.
 * \param planned_total_dividend_payment Variable for the X-machine memory.
 * \param direct_financial_needs Variable for the X-machine memory.
 * \param delayed_financial_needs Variable for the X-machine memory.
 * \param total_financial_needs Variable for the X-machine memory.
 * \param internal_financial_needs Variable for the X-machine memory.
 * \param external_financial_needs Variable for the X-machine memory.
 * \param total_external_financing_obtained Variable for the X-machine memory.
 * \param direct_financial_needs_require_external_financing Variable for the X-machine memory.
 * \param delayed_financial_needs_require_external_financing Variable for the X-machine memory.
 * \param current_share_price Variable for the X-machine memory.
 * \param current_shares_outstanding Variable for the X-machine memory.
 * \param previous_dividend_per_share Variable for the X-machine memory.
 * \param current_dividend_per_share Variable for the X-machine memory.
 * \param previous_dividend_per_earnings Variable for the X-machine memory.
 * \param current_dividend_per_earnings Variable for the X-machine memory.
 * \param earnings_per_share_ratio Variable for the X-machine memory.
 * \param debt_earnings_ratio Variable for the X-machine memory.
 * \param price_earnings_ratio Variable for the X-machine memory.
 * \param retained_earnings_ratio Variable for the X-machine memory.
 * \param earnings_per_share_ratio_growth Variable for the X-machine memory.
 * \param critical_price_earnings_ratio Variable for the X-machine memory.
 * \param critical_earnings_per_share_ratio Variable for the X-machine memory.
 * \param target_loans Variable for the X-machine memory.
 * \param target_equity Variable for the X-machine memory.
 * \param bonds_issue_target Variable for the X-machine memory.
 * \param stocks_issue_target Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Firm_agent(int id, int region_id, employee_array * employees, double wage_offer, double technology, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, int vacancies, double average_g_skill, double average_s_skill_of_1, double average_s_skill_of_2, double average_s_skill_of_3, double average_s_skill_of_4, double average_s_skill_of_5, double wage_offer_for_skill_1, double wage_offer_for_skill_2, double wage_offer_for_skill_3, double wage_offer_for_skill_4, double wage_offer_for_skill_5, int wage_update_was_made, double share_net_investments, double mean_wage, double needed_capital_stock, double actual_cap_price, double mean_specific_skills, double planned_production_quantity, double production_quantity, double unit_costs, double planned_production_costs, double production_costs, double revenue_per_day, double technological_frontier, double cum_revenue, double out_of_stock_costs, sales_statistics_array * malls_sales_statistics, double quality, double price, double price_last_month, capital_stock_item_array * capital_stock, double total_units_capital_stock, double total_value_capital_stock, double total_capital_depreciation_value, double total_capital_depreciation_units, int employees_needed, sold_quantities_per_mall_array * sold_quantities, double total_sold_quantity, double cum_total_sold_quantity, delivery_volume_per_mall_array * delivery_volume, delivery_volume_per_mall_array * planned_delivery_volume, mall_info_array * current_mall_stocks, double demand_capital_stock, double_array * last_planned_production_quantities, int day_of_month_to_act, int gov_id, int bank_id, double ebit, double payment_account, double earnings, double tax_rate_corporate, double tax_payment, double net_earnings, double previous_net_earnings, debt_item_array * loans, double total_interest_payment, double total_debt_installment_payment, double total_debt, double total_dividend_payment, double total_value_local_inventory, double total_assets, double planned_cum_revenue, double planned_total_interest_payment, double planned_total_debt_installment_payment, double planned_total_dividend_payment, double direct_financial_needs, double delayed_financial_needs, double total_financial_needs, double internal_financial_needs, double external_financial_needs, double total_external_financing_obtained, int direct_financial_needs_require_external_financing, int delayed_financial_needs_require_external_financing, double current_share_price, double current_shares_outstanding, double previous_dividend_per_share, double current_dividend_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double earnings_per_share_ratio, double debt_earnings_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, double target_loans, double target_equity, double bonds_issue_target, double stocks_issue_target, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Firm * current;
	
	init_Firm_agent(current);
	new_xmachine->xmachine_Firm = current;
	
	current->id = id;
	current->region_id = region_id;
	copy_employee_array(employees, &current->employees);
	current->wage_offer = wage_offer;
	current->technology = technology;
	current->no_employees = no_employees;
	current->no_employees_skill_1 = no_employees_skill_1;
	current->no_employees_skill_2 = no_employees_skill_2;
	current->no_employees_skill_3 = no_employees_skill_3;
	current->no_employees_skill_4 = no_employees_skill_4;
	current->no_employees_skill_5 = no_employees_skill_5;
	current->vacancies = vacancies;
	current->average_g_skill = average_g_skill;
	current->average_s_skill_of_1 = average_s_skill_of_1;
	current->average_s_skill_of_2 = average_s_skill_of_2;
	current->average_s_skill_of_3 = average_s_skill_of_3;
	current->average_s_skill_of_4 = average_s_skill_of_4;
	current->average_s_skill_of_5 = average_s_skill_of_5;
	current->wage_offer_for_skill_1 = wage_offer_for_skill_1;
	current->wage_offer_for_skill_2 = wage_offer_for_skill_2;
	current->wage_offer_for_skill_3 = wage_offer_for_skill_3;
	current->wage_offer_for_skill_4 = wage_offer_for_skill_4;
	current->wage_offer_for_skill_5 = wage_offer_for_skill_5;
	current->wage_update_was_made = wage_update_was_made;
	current->share_net_investments = share_net_investments;
	current->mean_wage = mean_wage;
	current->needed_capital_stock = needed_capital_stock;
	current->actual_cap_price = actual_cap_price;
	current->mean_specific_skills = mean_specific_skills;
	current->planned_production_quantity = planned_production_quantity;
	current->production_quantity = production_quantity;
	current->unit_costs = unit_costs;
	current->planned_production_costs = planned_production_costs;
	current->production_costs = production_costs;
	current->revenue_per_day = revenue_per_day;
	current->technological_frontier = technological_frontier;
	current->cum_revenue = cum_revenue;
	current->out_of_stock_costs = out_of_stock_costs;
	copy_sales_statistics_array(malls_sales_statistics, &current->malls_sales_statistics);
	current->quality = quality;
	current->price = price;
	current->price_last_month = price_last_month;
	copy_capital_stock_item_array(capital_stock, &current->capital_stock);
	current->total_units_capital_stock = total_units_capital_stock;
	current->total_value_capital_stock = total_value_capital_stock;
	current->total_capital_depreciation_value = total_capital_depreciation_value;
	current->total_capital_depreciation_units = total_capital_depreciation_units;
	current->employees_needed = employees_needed;
	copy_sold_quantities_per_mall_array(sold_quantities, &current->sold_quantities);
	current->total_sold_quantity = total_sold_quantity;
	current->cum_total_sold_quantity = cum_total_sold_quantity;
	copy_delivery_volume_per_mall_array(delivery_volume, &current->delivery_volume);
	copy_delivery_volume_per_mall_array(planned_delivery_volume, &current->planned_delivery_volume);
	copy_mall_info_array(current_mall_stocks, &current->current_mall_stocks);
	current->demand_capital_stock = demand_capital_stock;
	copy_double_array(last_planned_production_quantities, &current->last_planned_production_quantities);
	current->day_of_month_to_act = day_of_month_to_act;
	current->gov_id = gov_id;
	current->bank_id = bank_id;
	current->ebit = ebit;
	current->payment_account = payment_account;
	current->earnings = earnings;
	current->tax_rate_corporate = tax_rate_corporate;
	current->tax_payment = tax_payment;
	current->net_earnings = net_earnings;
	current->previous_net_earnings = previous_net_earnings;
	copy_debt_item_array(loans, &current->loans);
	current->total_interest_payment = total_interest_payment;
	current->total_debt_installment_payment = total_debt_installment_payment;
	current->total_debt = total_debt;
	current->total_dividend_payment = total_dividend_payment;
	current->total_value_local_inventory = total_value_local_inventory;
	current->total_assets = total_assets;
	current->planned_cum_revenue = planned_cum_revenue;
	current->planned_total_interest_payment = planned_total_interest_payment;
	current->planned_total_debt_installment_payment = planned_total_debt_installment_payment;
	current->planned_total_dividend_payment = planned_total_dividend_payment;
	current->direct_financial_needs = direct_financial_needs;
	current->delayed_financial_needs = delayed_financial_needs;
	current->total_financial_needs = total_financial_needs;
	current->internal_financial_needs = internal_financial_needs;
	current->external_financial_needs = external_financial_needs;
	current->total_external_financing_obtained = total_external_financing_obtained;
	current->direct_financial_needs_require_external_financing = direct_financial_needs_require_external_financing;
	current->delayed_financial_needs_require_external_financing = delayed_financial_needs_require_external_financing;
	current->current_share_price = current_share_price;
	current->current_shares_outstanding = current_shares_outstanding;
	current->previous_dividend_per_share = previous_dividend_per_share;
	current->current_dividend_per_share = current_dividend_per_share;
	current->previous_dividend_per_earnings = previous_dividend_per_earnings;
	current->current_dividend_per_earnings = current_dividend_per_earnings;
	current->earnings_per_share_ratio = earnings_per_share_ratio;
	current->debt_earnings_ratio = debt_earnings_ratio;
	current->price_earnings_ratio = price_earnings_ratio;
	current->retained_earnings_ratio = retained_earnings_ratio;
	current->earnings_per_share_ratio_growth = earnings_per_share_ratio_growth;
	current->critical_price_earnings_ratio = critical_price_earnings_ratio;
	current->critical_earnings_per_share_ratio = critical_earnings_per_share_ratio;
	current->target_loans = target_loans;
	current->target_equity = target_equity;
	current->bonds_issue_target = bonds_issue_target;
	current->stocks_issue_target = stocks_issue_target;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_Household * init_Household_agent()
{
	xmachine_memory_Household * current = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	init_int_array(&current->neighboring_region_ids);
	current->wage = 0.0;
	current->wage_reservation = 0.0;
	current->general_skill = 0;
	current->on_the_job_search = 0;
	current->number_applications = 0;
	current->specific_skill = 0.0;
	current->employee_firm_id = 0;
	current->employer_region_id = 0;
	current->budget = 0.0;
	current->week_of_month = 0;
	current->weekly_budget = 0.0;
	current->expenditures = 0.0;
	current->received_dividend_cap = 0.0;
	current->received_dividend_cons = 0.0;
	current->savings = 0.0;
	init_double_array(&current->last_income);
	current->rationed = 0;
	current->mall_completely_sold_out = 0;
	init_ordered_quantity_static_array(current->order_quantity, 2);
	init_received_quantities_static_array(current->received_quantity, 2);
	current->day_of_month_to_act = 0;
	current->day_of_week_to_act = 0;
	current->range = 0.0;
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_Household_agent(xmachine_memory_Household * tmp)
{
	free_int_array(&tmp->neighboring_region_ids);
	free_double_array(&tmp->last_income);
	free_ordered_quantity_static_array(tmp->order_quantity, 2);
	free_received_quantities_static_array(tmp->received_quantity, 2);
	
}

void add_Household_agent_internal(xmachine_memory_Household * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Household = current;
}

/** \fn void add_Household_agent(int id, int region_id, int_array * neighboring_region_ids, double wage, double wage_reservation, int general_skill, int on_the_job_search, int number_applications, double specific_skill, int employee_firm_id, int employer_region_id, double budget, int week_of_month, double weekly_budget, double expenditures, double received_dividend_cap, double received_dividend_cons, double savings, double_array * last_income, int rationed, int mall_completely_sold_out, ordered_quantity ** order_quantity, received_quantities ** received_quantity, int day_of_month_to_act, int day_of_week_to_act, double range, double posx, double posy)
 * \brief Add Household X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param neighboring_region_ids Variable for the X-machine memory.
 * \param wage Variable for the X-machine memory.
 * \param wage_reservation Variable for the X-machine memory.
 * \param general_skill Variable for the X-machine memory.
 * \param on_the_job_search Variable for the X-machine memory.
 * \param number_applications Variable for the X-machine memory.
 * \param specific_skill Variable for the X-machine memory.
 * \param employee_firm_id Variable for the X-machine memory.
 * \param employer_region_id Variable for the X-machine memory.
 * \param budget Variable for the X-machine memory.
 * \param week_of_month Variable for the X-machine memory.
 * \param weekly_budget Variable for the X-machine memory.
 * \param expenditures Variable for the X-machine memory.
 * \param received_dividend_cap Variable for the X-machine memory.
 * \param received_dividend_cons Variable for the X-machine memory.
 * \param savings Variable for the X-machine memory.
 * \param last_income Variable for the X-machine memory.
 * \param rationed Variable for the X-machine memory.
 * \param mall_completely_sold_out Variable for the X-machine memory.
 * \param order_quantity Variable for the X-machine memory.
 * \param received_quantity Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param day_of_week_to_act Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Household_agent(int id, int region_id, int_array * neighboring_region_ids, double wage, double wage_reservation, int general_skill, int on_the_job_search, int number_applications, double specific_skill, int employee_firm_id, int employer_region_id, double budget, int week_of_month, double weekly_budget, double expenditures, double received_dividend_cap, double received_dividend_cons, double savings, double_array * last_income, int rationed, int mall_completely_sold_out, ordered_quantity order_quantity[], received_quantities received_quantity[], int day_of_month_to_act, int day_of_week_to_act, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Household * current;
	
	init_Household_agent(current);
	new_xmachine->xmachine_Household = current;
	
	current->id = id;
	current->region_id = region_id;
	copy_int_array(neighboring_region_ids, &current->neighboring_region_ids);
	current->wage = wage;
	current->wage_reservation = wage_reservation;
	current->general_skill = general_skill;
	current->on_the_job_search = on_the_job_search;
	current->number_applications = number_applications;
	current->specific_skill = specific_skill;
	current->employee_firm_id = employee_firm_id;
	current->employer_region_id = employer_region_id;
	current->budget = budget;
	current->week_of_month = week_of_month;
	current->weekly_budget = weekly_budget;
	current->expenditures = expenditures;
	current->received_dividend_cap = received_dividend_cap;
	current->received_dividend_cons = received_dividend_cons;
	current->savings = savings;
	copy_double_array(last_income, &current->last_income);
	current->rationed = rationed;
	current->mall_completely_sold_out = mall_completely_sold_out;
	copy_ordered_quantity_static_array(order_quantity, current->order_quantity, 2);
	copy_received_quantities_static_array(received_quantity, current->received_quantity, 2);
	current->day_of_month_to_act = day_of_month_to_act;
	current->day_of_week_to_act = day_of_week_to_act;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_Mall * init_Mall_agent()
{
	xmachine_memory_Mall * current = (xmachine_memory_Mall *)malloc(sizeof(xmachine_memory_Mall));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	init_mall_stock_array(&current->current_stock);
	init_sales_in_mall_array(&current->firm_revenues);
	current->total_supply = 0.0;
	current->range = 0.0;
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_Mall_agent(xmachine_memory_Mall * tmp)
{
	free_mall_stock_array(&tmp->current_stock);
	free_sales_in_mall_array(&tmp->firm_revenues);
	
}

void add_Mall_agent_internal(xmachine_memory_Mall * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Mall = current;
}

/** \fn void add_Mall_agent(int id, int region_id, mall_stock_array * current_stock, sales_in_mall_array * firm_revenues, double total_supply, double range, double posx, double posy)
 * \brief Add Mall X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param current_stock Variable for the X-machine memory.
 * \param firm_revenues Variable for the X-machine memory.
 * \param total_supply Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Mall_agent(int id, int region_id, mall_stock_array * current_stock, sales_in_mall_array * firm_revenues, double total_supply, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Mall * current;
	
	init_Mall_agent(current);
	new_xmachine->xmachine_Mall = current;
	
	current->id = id;
	current->region_id = region_id;
	copy_mall_stock_array(current_stock, &current->current_stock);
	copy_sales_in_mall_array(firm_revenues, &current->firm_revenues);
	current->total_supply = total_supply;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_IGFirm * init_IGFirm_agent()
{
	xmachine_memory_IGFirm * current = (xmachine_memory_IGFirm *)malloc(sizeof(xmachine_memory_IGFirm));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	current->productivity = 0.0;
	current->innovation_probability = 0;
	current->productivity_progress = 0.0;
	current->capital_good_price = 0.0;
	current->revenue_per_day = 0.0;
	current->day_of_month_to_act = 0;
	current->range = 0.0;
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_IGFirm_agent(xmachine_memory_IGFirm * tmp)
{
	
}

void add_IGFirm_agent_internal(xmachine_memory_IGFirm * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_IGFirm = current;
}

/** \fn void add_IGFirm_agent(int id, int region_id, double productivity, int innovation_probability, double productivity_progress, double capital_good_price, double revenue_per_day, int day_of_month_to_act, double range, double posx, double posy)
 * \brief Add IGFirm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param productivity Variable for the X-machine memory.
 * \param innovation_probability Variable for the X-machine memory.
 * \param productivity_progress Variable for the X-machine memory.
 * \param capital_good_price Variable for the X-machine memory.
 * \param revenue_per_day Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_IGFirm_agent(int id, int region_id, double productivity, int innovation_probability, double productivity_progress, double capital_good_price, double revenue_per_day, int day_of_month_to_act, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_IGFirm * current;
	
	init_IGFirm_agent(current);
	new_xmachine->xmachine_IGFirm = current;
	
	current->id = id;
	current->region_id = region_id;
	current->productivity = productivity;
	current->innovation_probability = innovation_probability;
	current->productivity_progress = productivity_progress;
	current->capital_good_price = capital_good_price;
	current->revenue_per_day = revenue_per_day;
	current->day_of_month_to_act = day_of_month_to_act;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_Market_Research * init_Market_Research_agent()
{
	xmachine_memory_Market_Research * current = (xmachine_memory_Market_Research *)malloc(sizeof(xmachine_memory_Market_Research));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	current->no_regions = 0;
	current->num_households = 0;
	current->no_households_skill_1 = 0;
	current->no_households_skill_2 = 0;
	current->no_households_skill_3 = 0;
	current->no_households_skill_4 = 0;
	current->no_households_skill_5 = 0;
	current->employed = 0;
	current->employed_skill_1 = 0;
	current->employed_skill_2 = 0;
	current->employed_skill_3 = 0;
	current->employed_skill_4 = 0;
	current->employed_skill_5 = 0;
	current->unemployed = 0;
	current->unemployment_rate = 0.0;
	current->unemployment_rate_skill_1 = 0.0;
	current->unemployment_rate_skill_2 = 0.0;
	current->unemployment_rate_skill_3 = 0.0;
	current->unemployment_rate_skill_4 = 0.0;
	current->unemployment_rate_skill_5 = 0.0;
	current->average_wage = 0.0;
	current->average_wage_skill_1 = 0.0;
	current->average_wage_skill_2 = 0.0;
	current->average_wage_skill_3 = 0.0;
	current->average_wage_skill_4 = 0.0;
	current->average_wage_skill_5 = 0.0;
	current->average_s_skill = 0.0;
	current->average_s_skill_1 = 0.0;
	current->average_s_skill_2 = 0.0;
	current->average_s_skill_3 = 0.0;
	current->average_s_skill_4 = 0.0;
	current->average_s_skill_5 = 0.0;
	current->no_firms = 0;
	current->no_vacancies = 0;
	current->no_employees = 0;
	current->no_employees_skill_1 = 0;
	current->no_employees_skill_2 = 0;
	current->no_employees_skill_3 = 0;
	current->no_employees_skill_4 = 0;
	current->no_employees_skill_5 = 0;
	current->firm_average_wage = 0.0;
	current->firm_average_wage_skill_1 = 0.0;
	current->firm_average_wage_skill_2 = 0.0;
	current->firm_average_wage_skill_3 = 0.0;
	current->firm_average_wage_skill_4 = 0.0;
	current->firm_average_wage_skill_5 = 0.0;
	current->firm_average_s_skill = 0.0;
	current->firm_average_s_skill_1 = 0.0;
	current->firm_average_s_skill_2 = 0.0;
	current->firm_average_s_skill_3 = 0.0;
	current->firm_average_s_skill_4 = 0.0;
	current->firm_average_s_skill_5 = 0.0;
	init_firm_data_array(&current->region_firm_data);
	init_household_data_array(&current->region_household_data);
	current->day_of_month_to_act = 0;
	current->range = 0.0;
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_Market_Research_agent(xmachine_memory_Market_Research * tmp)
{
	free_firm_data_array(&tmp->region_firm_data);
	free_household_data_array(&tmp->region_household_data);
	
}

void add_Market_Research_agent_internal(xmachine_memory_Market_Research * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Market_Research = current;
}

/** \fn void add_Market_Research_agent(int id, int region_id, int no_regions, int num_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, int no_firms, int no_vacancies, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, double firm_average_wage, double firm_average_wage_skill_1, double firm_average_wage_skill_2, double firm_average_wage_skill_3, double firm_average_wage_skill_4, double firm_average_wage_skill_5, double firm_average_s_skill, double firm_average_s_skill_1, double firm_average_s_skill_2, double firm_average_s_skill_3, double firm_average_s_skill_4, double firm_average_s_skill_5, firm_data_array * region_firm_data, household_data_array * region_household_data, int day_of_month_to_act, double range, double posx, double posy)
 * \brief Add Market_Research X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param no_regions Variable for the X-machine memory.
 * \param num_households Variable for the X-machine memory.
 * \param no_households_skill_1 Variable for the X-machine memory.
 * \param no_households_skill_2 Variable for the X-machine memory.
 * \param no_households_skill_3 Variable for the X-machine memory.
 * \param no_households_skill_4 Variable for the X-machine memory.
 * \param no_households_skill_5 Variable for the X-machine memory.
 * \param employed Variable for the X-machine memory.
 * \param employed_skill_1 Variable for the X-machine memory.
 * \param employed_skill_2 Variable for the X-machine memory.
 * \param employed_skill_3 Variable for the X-machine memory.
 * \param employed_skill_4 Variable for the X-machine memory.
 * \param employed_skill_5 Variable for the X-machine memory.
 * \param unemployed Variable for the X-machine memory.
 * \param unemployment_rate Variable for the X-machine memory.
 * \param unemployment_rate_skill_1 Variable for the X-machine memory.
 * \param unemployment_rate_skill_2 Variable for the X-machine memory.
 * \param unemployment_rate_skill_3 Variable for the X-machine memory.
 * \param unemployment_rate_skill_4 Variable for the X-machine memory.
 * \param unemployment_rate_skill_5 Variable for the X-machine memory.
 * \param average_wage Variable for the X-machine memory.
 * \param average_wage_skill_1 Variable for the X-machine memory.
 * \param average_wage_skill_2 Variable for the X-machine memory.
 * \param average_wage_skill_3 Variable for the X-machine memory.
 * \param average_wage_skill_4 Variable for the X-machine memory.
 * \param average_wage_skill_5 Variable for the X-machine memory.
 * \param average_s_skill Variable for the X-machine memory.
 * \param average_s_skill_1 Variable for the X-machine memory.
 * \param average_s_skill_2 Variable for the X-machine memory.
 * \param average_s_skill_3 Variable for the X-machine memory.
 * \param average_s_skill_4 Variable for the X-machine memory.
 * \param average_s_skill_5 Variable for the X-machine memory.
 * \param no_firms Variable for the X-machine memory.
 * \param no_vacancies Variable for the X-machine memory.
 * \param no_employees Variable for the X-machine memory.
 * \param no_employees_skill_1 Variable for the X-machine memory.
 * \param no_employees_skill_2 Variable for the X-machine memory.
 * \param no_employees_skill_3 Variable for the X-machine memory.
 * \param no_employees_skill_4 Variable for the X-machine memory.
 * \param no_employees_skill_5 Variable for the X-machine memory.
 * \param firm_average_wage Variable for the X-machine memory.
 * \param firm_average_wage_skill_1 Variable for the X-machine memory.
 * \param firm_average_wage_skill_2 Variable for the X-machine memory.
 * \param firm_average_wage_skill_3 Variable for the X-machine memory.
 * \param firm_average_wage_skill_4 Variable for the X-machine memory.
 * \param firm_average_wage_skill_5 Variable for the X-machine memory.
 * \param firm_average_s_skill Variable for the X-machine memory.
 * \param firm_average_s_skill_1 Variable for the X-machine memory.
 * \param firm_average_s_skill_2 Variable for the X-machine memory.
 * \param firm_average_s_skill_3 Variable for the X-machine memory.
 * \param firm_average_s_skill_4 Variable for the X-machine memory.
 * \param firm_average_s_skill_5 Variable for the X-machine memory.
 * \param region_firm_data Variable for the X-machine memory.
 * \param region_household_data Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Market_Research_agent(int id, int region_id, int no_regions, int num_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, int no_firms, int no_vacancies, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, double firm_average_wage, double firm_average_wage_skill_1, double firm_average_wage_skill_2, double firm_average_wage_skill_3, double firm_average_wage_skill_4, double firm_average_wage_skill_5, double firm_average_s_skill, double firm_average_s_skill_1, double firm_average_s_skill_2, double firm_average_s_skill_3, double firm_average_s_skill_4, double firm_average_s_skill_5, firm_data_array * region_firm_data, household_data_array * region_household_data, int day_of_month_to_act, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Market_Research * current;
	
	init_Market_Research_agent(current);
	new_xmachine->xmachine_Market_Research = current;
	
	current->id = id;
	current->region_id = region_id;
	current->no_regions = no_regions;
	current->num_households = num_households;
	current->no_households_skill_1 = no_households_skill_1;
	current->no_households_skill_2 = no_households_skill_2;
	current->no_households_skill_3 = no_households_skill_3;
	current->no_households_skill_4 = no_households_skill_4;
	current->no_households_skill_5 = no_households_skill_5;
	current->employed = employed;
	current->employed_skill_1 = employed_skill_1;
	current->employed_skill_2 = employed_skill_2;
	current->employed_skill_3 = employed_skill_3;
	current->employed_skill_4 = employed_skill_4;
	current->employed_skill_5 = employed_skill_5;
	current->unemployed = unemployed;
	current->unemployment_rate = unemployment_rate;
	current->unemployment_rate_skill_1 = unemployment_rate_skill_1;
	current->unemployment_rate_skill_2 = unemployment_rate_skill_2;
	current->unemployment_rate_skill_3 = unemployment_rate_skill_3;
	current->unemployment_rate_skill_4 = unemployment_rate_skill_4;
	current->unemployment_rate_skill_5 = unemployment_rate_skill_5;
	current->average_wage = average_wage;
	current->average_wage_skill_1 = average_wage_skill_1;
	current->average_wage_skill_2 = average_wage_skill_2;
	current->average_wage_skill_3 = average_wage_skill_3;
	current->average_wage_skill_4 = average_wage_skill_4;
	current->average_wage_skill_5 = average_wage_skill_5;
	current->average_s_skill = average_s_skill;
	current->average_s_skill_1 = average_s_skill_1;
	current->average_s_skill_2 = average_s_skill_2;
	current->average_s_skill_3 = average_s_skill_3;
	current->average_s_skill_4 = average_s_skill_4;
	current->average_s_skill_5 = average_s_skill_5;
	current->no_firms = no_firms;
	current->no_vacancies = no_vacancies;
	current->no_employees = no_employees;
	current->no_employees_skill_1 = no_employees_skill_1;
	current->no_employees_skill_2 = no_employees_skill_2;
	current->no_employees_skill_3 = no_employees_skill_3;
	current->no_employees_skill_4 = no_employees_skill_4;
	current->no_employees_skill_5 = no_employees_skill_5;
	current->firm_average_wage = firm_average_wage;
	current->firm_average_wage_skill_1 = firm_average_wage_skill_1;
	current->firm_average_wage_skill_2 = firm_average_wage_skill_2;
	current->firm_average_wage_skill_3 = firm_average_wage_skill_3;
	current->firm_average_wage_skill_4 = firm_average_wage_skill_4;
	current->firm_average_wage_skill_5 = firm_average_wage_skill_5;
	current->firm_average_s_skill = firm_average_s_skill;
	current->firm_average_s_skill_1 = firm_average_s_skill_1;
	current->firm_average_s_skill_2 = firm_average_s_skill_2;
	current->firm_average_s_skill_3 = firm_average_s_skill_3;
	current->firm_average_s_skill_4 = firm_average_s_skill_4;
	current->firm_average_s_skill_5 = firm_average_s_skill_5;
	copy_firm_data_array(region_firm_data, &current->region_firm_data);
	copy_household_data_array(region_household_data, &current->region_household_data);
	current->day_of_month_to_act = day_of_month_to_act;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_Clearinghouse * init_Clearinghouse_agent()
{
	xmachine_memory_Clearinghouse * current = (xmachine_memory_Clearinghouse *)malloc(sizeof(xmachine_memory_Clearinghouse));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->trader_id = 0;
	current->stock_id = 0;
	current->bond_id = 0;
	current->gov_bond_id = 0;
	current->limit_price = 0.0;
	current->limit_quantity = 0.0;
	current->range = 0.0;
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_Clearinghouse_agent(xmachine_memory_Clearinghouse * tmp)
{
	
}

void add_Clearinghouse_agent_internal(xmachine_memory_Clearinghouse * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Clearinghouse = current;
}

/** \fn void add_Clearinghouse_agent(int id, int trader_id, int stock_id, int bond_id, int gov_bond_id, double limit_price, double limit_quantity, double range, double posx, double posy)
 * \brief Add Clearinghouse X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param trader_id Variable for the X-machine memory.
 * \param stock_id Variable for the X-machine memory.
 * \param bond_id Variable for the X-machine memory.
 * \param gov_bond_id Variable for the X-machine memory.
 * \param limit_price Variable for the X-machine memory.
 * \param limit_quantity Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Clearinghouse_agent(int id, int trader_id, int stock_id, int bond_id, int gov_bond_id, double limit_price, double limit_quantity, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Clearinghouse * current;
	
	init_Clearinghouse_agent(current);
	new_xmachine->xmachine_Clearinghouse = current;
	
	current->id = id;
	current->trader_id = trader_id;
	current->stock_id = stock_id;
	current->bond_id = bond_id;
	current->gov_bond_id = gov_bond_id;
	current->limit_price = limit_price;
	current->limit_quantity = limit_quantity;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_Bank * init_Bank_agent()
{
	xmachine_memory_Bank * current = (xmachine_memory_Bank *)malloc(sizeof(xmachine_memory_Bank));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->proposed_interest_rate = 0.0;
	current->amount_credit_offer = 0.0;
	current->range = 0.0;
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_Bank_agent(xmachine_memory_Bank * tmp)
{
	
}

void add_Bank_agent_internal(xmachine_memory_Bank * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Bank = current;
}

/** \fn void add_Bank_agent(int id, double proposed_interest_rate, double amount_credit_offer, double range, double posx, double posy)
 * \brief Add Bank X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param proposed_interest_rate Variable for the X-machine memory.
 * \param amount_credit_offer Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Bank_agent(int id, double proposed_interest_rate, double amount_credit_offer, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Bank * current;
	
	init_Bank_agent(current);
	new_xmachine->xmachine_Bank = current;
	
	current->id = id;
	current->proposed_interest_rate = proposed_interest_rate;
	current->amount_credit_offer = amount_credit_offer;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void free_agent()
 * \brief Free the currently being used X-machine.
 */
/* free_agent */
void free_agent()
{
	xmachine * head = *p_xmachine;
	xmachine * tmp = NULL;
	
	while(head)
	{
		if(head == current_xmachine)
		{
			if(tmp) tmp->next = head->next;
			else *p_xmachine = head->next;
			if(head->xmachine_Firm)
			{
				free_Firm_agent(head->xmachine_Firm);
				free(head->xmachine_Firm);
			}
			if(head->xmachine_Household)
			{
				free_Household_agent(head->xmachine_Household);
				free(head->xmachine_Household);
			}
			if(head->xmachine_Mall)
			{
				free_Mall_agent(head->xmachine_Mall);
				free(head->xmachine_Mall);
			}
			if(head->xmachine_IGFirm)
			{
				free_IGFirm_agent(head->xmachine_IGFirm);
				free(head->xmachine_IGFirm);
			}
			if(head->xmachine_Market_Research)
			{
				free_Market_Research_agent(head->xmachine_Market_Research);
				free(head->xmachine_Market_Research);
			}
			if(head->xmachine_Clearinghouse)
			{
				free_Clearinghouse_agent(head->xmachine_Clearinghouse);
				free(head->xmachine_Clearinghouse);
			}
			if(head->xmachine_Bank)
			{
				free_Bank_agent(head->xmachine_Bank);
				free(head->xmachine_Bank);
			}
		free(head);
		head = NULL;
	}
	else
	{
		tmp = head;
		head = tmp->next;
	}
}
	
	current_node->agent_total--;
}

/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	xmachine * head = *p_xmachine;
	xmachine * tmp = NULL;
	
	while(head)
	{
		tmp = head->next;
		if(head->xmachine_Firm)
		{
			free_Firm_agent(head->xmachine_Firm);
			free(head->xmachine_Firm);
		}
		if(head->xmachine_Household)
		{
			free_Household_agent(head->xmachine_Household);
			free(head->xmachine_Household);
		}
		if(head->xmachine_Mall)
		{
			free_Mall_agent(head->xmachine_Mall);
			free(head->xmachine_Mall);
		}
		if(head->xmachine_IGFirm)
		{
			free_IGFirm_agent(head->xmachine_IGFirm);
			free(head->xmachine_IGFirm);
		}
		if(head->xmachine_Market_Research)
		{
			free_Market_Research_agent(head->xmachine_Market_Research);
			free(head->xmachine_Market_Research);
		}
		if(head->xmachine_Clearinghouse)
		{
			free_Clearinghouse_agent(head->xmachine_Clearinghouse);
			free(head->xmachine_Clearinghouse);
		}
		if(head->xmachine_Bank)
		{
			free_Bank_agent(head->xmachine_Bank);
			free(head->xmachine_Bank);
		}
		free(head);
		head = tmp;
	}
	
	*p_xmachine = NULL;
}


/** \fn void set_id(int id) 
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(int id)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).id = id;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).id = id;
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).id = id;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).id = id;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).id = id;
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).id = id;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).id;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).id;
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).id;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).id;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).id;
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).id;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_region_id(int region_id) 
 * \brief Set region_id memory variable for current X-machine.
 * \param region_id New value for variable.
 */
void set_region_id(int region_id)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).region_id = region_id;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).region_id = region_id;
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).region_id = region_id;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).region_id = region_id;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).region_id = region_id;
}

/** \fn int get_region_id()
 * \brief Get region_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_region_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).region_id;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).region_id;
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).region_id;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).region_id;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).region_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn employee_array get_employees()
 * \brief Get employees memory variable from current X-machine.
 * \return Value for variable.
 */
employee_array * get_employees()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).employees;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_wage_offer(double wage_offer) 
 * \brief Set wage_offer memory variable for current X-machine.
 * \param wage_offer New value for variable.
 */
void set_wage_offer(double wage_offer)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer = wage_offer;
}

/** \fn double get_wage_offer()
 * \brief Get wage_offer memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_technology(double technology) 
 * \brief Set technology memory variable for current X-machine.
 * \param technology New value for variable.
 */
void set_technology(double technology)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).technology = technology;
}

/** \fn double get_technology()
 * \brief Get technology memory variable from current X-machine.
 * \return Value for variable.
 */
double get_technology()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).technology;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_no_employees(int no_employees) 
 * \brief Set no_employees memory variable for current X-machine.
 * \param no_employees New value for variable.
 */
void set_no_employees(int no_employees)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees = no_employees;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_employees = no_employees;
}

/** \fn int get_no_employees()
 * \brief Get no_employees memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_employees;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_1(int no_employees_skill_1) 
 * \brief Set no_employees_skill_1 memory variable for current X-machine.
 * \param no_employees_skill_1 New value for variable.
 */
void set_no_employees_skill_1(int no_employees_skill_1)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_1 = no_employees_skill_1;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_employees_skill_1 = no_employees_skill_1;
}

/** \fn int get_no_employees_skill_1()
 * \brief Get no_employees_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_1()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_1;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_employees_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_2(int no_employees_skill_2) 
 * \brief Set no_employees_skill_2 memory variable for current X-machine.
 * \param no_employees_skill_2 New value for variable.
 */
void set_no_employees_skill_2(int no_employees_skill_2)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_2 = no_employees_skill_2;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_employees_skill_2 = no_employees_skill_2;
}

/** \fn int get_no_employees_skill_2()
 * \brief Get no_employees_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_2()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_2;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_employees_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_3(int no_employees_skill_3) 
 * \brief Set no_employees_skill_3 memory variable for current X-machine.
 * \param no_employees_skill_3 New value for variable.
 */
void set_no_employees_skill_3(int no_employees_skill_3)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_3 = no_employees_skill_3;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_employees_skill_3 = no_employees_skill_3;
}

/** \fn int get_no_employees_skill_3()
 * \brief Get no_employees_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_3()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_3;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_employees_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_4(int no_employees_skill_4) 
 * \brief Set no_employees_skill_4 memory variable for current X-machine.
 * \param no_employees_skill_4 New value for variable.
 */
void set_no_employees_skill_4(int no_employees_skill_4)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_4 = no_employees_skill_4;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_employees_skill_4 = no_employees_skill_4;
}

/** \fn int get_no_employees_skill_4()
 * \brief Get no_employees_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_4()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_4;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_employees_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_5(int no_employees_skill_5) 
 * \brief Set no_employees_skill_5 memory variable for current X-machine.
 * \param no_employees_skill_5 New value for variable.
 */
void set_no_employees_skill_5(int no_employees_skill_5)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_5 = no_employees_skill_5;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_employees_skill_5 = no_employees_skill_5;
}

/** \fn int get_no_employees_skill_5()
 * \brief Get no_employees_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_5()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_5;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_employees_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_vacancies(int vacancies) 
 * \brief Set vacancies memory variable for current X-machine.
 * \param vacancies New value for variable.
 */
void set_vacancies(int vacancies)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).vacancies = vacancies;
}

/** \fn int get_vacancies()
 * \brief Get vacancies memory variable from current X-machine.
 * \return Value for variable.
 */
int get_vacancies()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).vacancies;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_average_g_skill(double average_g_skill) 
 * \brief Set average_g_skill memory variable for current X-machine.
 * \param average_g_skill New value for variable.
 */
void set_average_g_skill(double average_g_skill)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_g_skill = average_g_skill;
}

/** \fn double get_average_g_skill()
 * \brief Get average_g_skill memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_g_skill()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_g_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_1(double average_s_skill_of_1) 
 * \brief Set average_s_skill_of_1 memory variable for current X-machine.
 * \param average_s_skill_of_1 New value for variable.
 */
void set_average_s_skill_of_1(double average_s_skill_of_1)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_1 = average_s_skill_of_1;
}

/** \fn double get_average_s_skill_of_1()
 * \brief Get average_s_skill_of_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_1()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_2(double average_s_skill_of_2) 
 * \brief Set average_s_skill_of_2 memory variable for current X-machine.
 * \param average_s_skill_of_2 New value for variable.
 */
void set_average_s_skill_of_2(double average_s_skill_of_2)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_2 = average_s_skill_of_2;
}

/** \fn double get_average_s_skill_of_2()
 * \brief Get average_s_skill_of_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_2()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_3(double average_s_skill_of_3) 
 * \brief Set average_s_skill_of_3 memory variable for current X-machine.
 * \param average_s_skill_of_3 New value for variable.
 */
void set_average_s_skill_of_3(double average_s_skill_of_3)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_3 = average_s_skill_of_3;
}

/** \fn double get_average_s_skill_of_3()
 * \brief Get average_s_skill_of_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_3()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_4(double average_s_skill_of_4) 
 * \brief Set average_s_skill_of_4 memory variable for current X-machine.
 * \param average_s_skill_of_4 New value for variable.
 */
void set_average_s_skill_of_4(double average_s_skill_of_4)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_4 = average_s_skill_of_4;
}

/** \fn double get_average_s_skill_of_4()
 * \brief Get average_s_skill_of_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_4()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_5(double average_s_skill_of_5) 
 * \brief Set average_s_skill_of_5 memory variable for current X-machine.
 * \param average_s_skill_of_5 New value for variable.
 */
void set_average_s_skill_of_5(double average_s_skill_of_5)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_5 = average_s_skill_of_5;
}

/** \fn double get_average_s_skill_of_5()
 * \brief Get average_s_skill_of_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_5()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_1(double wage_offer_for_skill_1) 
 * \brief Set wage_offer_for_skill_1 memory variable for current X-machine.
 * \param wage_offer_for_skill_1 New value for variable.
 */
void set_wage_offer_for_skill_1(double wage_offer_for_skill_1)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_1 = wage_offer_for_skill_1;
}

/** \fn double get_wage_offer_for_skill_1()
 * \brief Get wage_offer_for_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_1()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_2(double wage_offer_for_skill_2) 
 * \brief Set wage_offer_for_skill_2 memory variable for current X-machine.
 * \param wage_offer_for_skill_2 New value for variable.
 */
void set_wage_offer_for_skill_2(double wage_offer_for_skill_2)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_2 = wage_offer_for_skill_2;
}

/** \fn double get_wage_offer_for_skill_2()
 * \brief Get wage_offer_for_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_2()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_3(double wage_offer_for_skill_3) 
 * \brief Set wage_offer_for_skill_3 memory variable for current X-machine.
 * \param wage_offer_for_skill_3 New value for variable.
 */
void set_wage_offer_for_skill_3(double wage_offer_for_skill_3)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_3 = wage_offer_for_skill_3;
}

/** \fn double get_wage_offer_for_skill_3()
 * \brief Get wage_offer_for_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_3()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_4(double wage_offer_for_skill_4) 
 * \brief Set wage_offer_for_skill_4 memory variable for current X-machine.
 * \param wage_offer_for_skill_4 New value for variable.
 */
void set_wage_offer_for_skill_4(double wage_offer_for_skill_4)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_4 = wage_offer_for_skill_4;
}

/** \fn double get_wage_offer_for_skill_4()
 * \brief Get wage_offer_for_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_4()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_5(double wage_offer_for_skill_5) 
 * \brief Set wage_offer_for_skill_5 memory variable for current X-machine.
 * \param wage_offer_for_skill_5 New value for variable.
 */
void set_wage_offer_for_skill_5(double wage_offer_for_skill_5)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_5 = wage_offer_for_skill_5;
}

/** \fn double get_wage_offer_for_skill_5()
 * \brief Get wage_offer_for_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_5()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_update_was_made(int wage_update_was_made) 
 * \brief Set wage_update_was_made memory variable for current X-machine.
 * \param wage_update_was_made New value for variable.
 */
void set_wage_update_was_made(int wage_update_was_made)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_update_was_made = wage_update_was_made;
}

/** \fn int get_wage_update_was_made()
 * \brief Get wage_update_was_made memory variable from current X-machine.
 * \return Value for variable.
 */
int get_wage_update_was_made()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_update_was_made;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_share_net_investments(double share_net_investments) 
 * \brief Set share_net_investments memory variable for current X-machine.
 * \param share_net_investments New value for variable.
 */
void set_share_net_investments(double share_net_investments)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).share_net_investments = share_net_investments;
}

/** \fn double get_share_net_investments()
 * \brief Get share_net_investments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_share_net_investments()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).share_net_investments;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_mean_wage(double mean_wage) 
 * \brief Set mean_wage memory variable for current X-machine.
 * \param mean_wage New value for variable.
 */
void set_mean_wage(double mean_wage)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).mean_wage = mean_wage;
}

/** \fn double get_mean_wage()
 * \brief Get mean_wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_mean_wage()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).mean_wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_needed_capital_stock(double needed_capital_stock) 
 * \brief Set needed_capital_stock memory variable for current X-machine.
 * \param needed_capital_stock New value for variable.
 */
void set_needed_capital_stock(double needed_capital_stock)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).needed_capital_stock = needed_capital_stock;
}

/** \fn double get_needed_capital_stock()
 * \brief Get needed_capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
double get_needed_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).needed_capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_actual_cap_price(double actual_cap_price) 
 * \brief Set actual_cap_price memory variable for current X-machine.
 * \param actual_cap_price New value for variable.
 */
void set_actual_cap_price(double actual_cap_price)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).actual_cap_price = actual_cap_price;
}

/** \fn double get_actual_cap_price()
 * \brief Get actual_cap_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_actual_cap_price()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).actual_cap_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_mean_specific_skills(double mean_specific_skills) 
 * \brief Set mean_specific_skills memory variable for current X-machine.
 * \param mean_specific_skills New value for variable.
 */
void set_mean_specific_skills(double mean_specific_skills)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).mean_specific_skills = mean_specific_skills;
}

/** \fn double get_mean_specific_skills()
 * \brief Get mean_specific_skills memory variable from current X-machine.
 * \return Value for variable.
 */
double get_mean_specific_skills()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).mean_specific_skills;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_production_quantity(double planned_production_quantity) 
 * \brief Set planned_production_quantity memory variable for current X-machine.
 * \param planned_production_quantity New value for variable.
 */
void set_planned_production_quantity(double planned_production_quantity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_production_quantity = planned_production_quantity;
}

/** \fn double get_planned_production_quantity()
 * \brief Get planned_production_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_production_quantity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_production_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_production_quantity(double production_quantity) 
 * \brief Set production_quantity memory variable for current X-machine.
 * \param production_quantity New value for variable.
 */
void set_production_quantity(double production_quantity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).production_quantity = production_quantity;
}

/** \fn double get_production_quantity()
 * \brief Get production_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_production_quantity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).production_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unit_costs(double unit_costs) 
 * \brief Set unit_costs memory variable for current X-machine.
 * \param unit_costs New value for variable.
 */
void set_unit_costs(double unit_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).unit_costs = unit_costs;
}

/** \fn double get_unit_costs()
 * \brief Get unit_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unit_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).unit_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_production_costs(double planned_production_costs) 
 * \brief Set planned_production_costs memory variable for current X-machine.
 * \param planned_production_costs New value for variable.
 */
void set_planned_production_costs(double planned_production_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_production_costs = planned_production_costs;
}

/** \fn double get_planned_production_costs()
 * \brief Get planned_production_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_production_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_production_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_production_costs(double production_costs) 
 * \brief Set production_costs memory variable for current X-machine.
 * \param production_costs New value for variable.
 */
void set_production_costs(double production_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).production_costs = production_costs;
}

/** \fn double get_production_costs()
 * \brief Get production_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_production_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).production_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_revenue_per_day(double revenue_per_day) 
 * \brief Set revenue_per_day memory variable for current X-machine.
 * \param revenue_per_day New value for variable.
 */
void set_revenue_per_day(double revenue_per_day)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).revenue_per_day = revenue_per_day;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).revenue_per_day = revenue_per_day;
}

/** \fn double get_revenue_per_day()
 * \brief Get revenue_per_day memory variable from current X-machine.
 * \return Value for variable.
 */
double get_revenue_per_day()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).revenue_per_day;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).revenue_per_day;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_technological_frontier(double technological_frontier) 
 * \brief Set technological_frontier memory variable for current X-machine.
 * \param technological_frontier New value for variable.
 */
void set_technological_frontier(double technological_frontier)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).technological_frontier = technological_frontier;
}

/** \fn double get_technological_frontier()
 * \brief Get technological_frontier memory variable from current X-machine.
 * \return Value for variable.
 */
double get_technological_frontier()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).technological_frontier;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_cum_revenue(double cum_revenue) 
 * \brief Set cum_revenue memory variable for current X-machine.
 * \param cum_revenue New value for variable.
 */
void set_cum_revenue(double cum_revenue)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).cum_revenue = cum_revenue;
}

/** \fn double get_cum_revenue()
 * \brief Get cum_revenue memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cum_revenue()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).cum_revenue;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_out_of_stock_costs(double out_of_stock_costs) 
 * \brief Set out_of_stock_costs memory variable for current X-machine.
 * \param out_of_stock_costs New value for variable.
 */
void set_out_of_stock_costs(double out_of_stock_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).out_of_stock_costs = out_of_stock_costs;
}

/** \fn double get_out_of_stock_costs()
 * \brief Get out_of_stock_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_out_of_stock_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).out_of_stock_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn sales_statistics_array get_malls_sales_statistics()
 * \brief Get malls_sales_statistics memory variable from current X-machine.
 * \return Value for variable.
 */
sales_statistics_array * get_malls_sales_statistics()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).malls_sales_statistics;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_quality(double quality) 
 * \brief Set quality memory variable for current X-machine.
 * \param quality New value for variable.
 */
void set_quality(double quality)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).quality = quality;
}

/** \fn double get_quality()
 * \brief Get quality memory variable from current X-machine.
 * \return Value for variable.
 */
double get_quality()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).quality;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_price(double price) 
 * \brief Set price memory variable for current X-machine.
 * \param price New value for variable.
 */
void set_price(double price)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).price = price;
}

/** \fn double get_price()
 * \brief Get price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_price_last_month(double price_last_month) 
 * \brief Set price_last_month memory variable for current X-machine.
 * \param price_last_month New value for variable.
 */
void set_price_last_month(double price_last_month)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).price_last_month = price_last_month;
}

/** \fn double get_price_last_month()
 * \brief Get price_last_month memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price_last_month()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).price_last_month;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn capital_stock_item_array get_capital_stock()
 * \brief Get capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
capital_stock_item_array * get_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_units_capital_stock(double total_units_capital_stock) 
 * \brief Set total_units_capital_stock memory variable for current X-machine.
 * \param total_units_capital_stock New value for variable.
 */
void set_total_units_capital_stock(double total_units_capital_stock)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_units_capital_stock = total_units_capital_stock;
}

/** \fn double get_total_units_capital_stock()
 * \brief Get total_units_capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_units_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_units_capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_value_capital_stock(double total_value_capital_stock) 
 * \brief Set total_value_capital_stock memory variable for current X-machine.
 * \param total_value_capital_stock New value for variable.
 */
void set_total_value_capital_stock(double total_value_capital_stock)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_value_capital_stock = total_value_capital_stock;
}

/** \fn double get_total_value_capital_stock()
 * \brief Get total_value_capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_value_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_value_capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_capital_depreciation_value(double total_capital_depreciation_value) 
 * \brief Set total_capital_depreciation_value memory variable for current X-machine.
 * \param total_capital_depreciation_value New value for variable.
 */
void set_total_capital_depreciation_value(double total_capital_depreciation_value)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_capital_depreciation_value = total_capital_depreciation_value;
}

/** \fn double get_total_capital_depreciation_value()
 * \brief Get total_capital_depreciation_value memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_capital_depreciation_value()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_capital_depreciation_value;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_capital_depreciation_units(double total_capital_depreciation_units) 
 * \brief Set total_capital_depreciation_units memory variable for current X-machine.
 * \param total_capital_depreciation_units New value for variable.
 */
void set_total_capital_depreciation_units(double total_capital_depreciation_units)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_capital_depreciation_units = total_capital_depreciation_units;
}

/** \fn double get_total_capital_depreciation_units()
 * \brief Get total_capital_depreciation_units memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_capital_depreciation_units()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_capital_depreciation_units;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_employees_needed(int employees_needed) 
 * \brief Set employees_needed memory variable for current X-machine.
 * \param employees_needed New value for variable.
 */
void set_employees_needed(int employees_needed)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).employees_needed = employees_needed;
}

/** \fn int get_employees_needed()
 * \brief Get employees_needed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employees_needed()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).employees_needed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn sold_quantities_per_mall_array get_sold_quantities()
 * \brief Get sold_quantities memory variable from current X-machine.
 * \return Value for variable.
 */
sold_quantities_per_mall_array * get_sold_quantities()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).sold_quantities;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_sold_quantity(double total_sold_quantity) 
 * \brief Set total_sold_quantity memory variable for current X-machine.
 * \param total_sold_quantity New value for variable.
 */
void set_total_sold_quantity(double total_sold_quantity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_sold_quantity = total_sold_quantity;
}

/** \fn double get_total_sold_quantity()
 * \brief Get total_sold_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_sold_quantity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_sold_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_cum_total_sold_quantity(double cum_total_sold_quantity) 
 * \brief Set cum_total_sold_quantity memory variable for current X-machine.
 * \param cum_total_sold_quantity New value for variable.
 */
void set_cum_total_sold_quantity(double cum_total_sold_quantity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).cum_total_sold_quantity = cum_total_sold_quantity;
}

/** \fn double get_cum_total_sold_quantity()
 * \brief Get cum_total_sold_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cum_total_sold_quantity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).cum_total_sold_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn delivery_volume_per_mall_array get_delivery_volume()
 * \brief Get delivery_volume memory variable from current X-machine.
 * \return Value for variable.
 */
delivery_volume_per_mall_array * get_delivery_volume()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).delivery_volume;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn delivery_volume_per_mall_array get_planned_delivery_volume()
 * \brief Get planned_delivery_volume memory variable from current X-machine.
 * \return Value for variable.
 */
delivery_volume_per_mall_array * get_planned_delivery_volume()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).planned_delivery_volume;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn mall_info_array get_current_mall_stocks()
 * \brief Get current_mall_stocks memory variable from current X-machine.
 * \return Value for variable.
 */
mall_info_array * get_current_mall_stocks()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).current_mall_stocks;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_demand_capital_stock(double demand_capital_stock) 
 * \brief Set demand_capital_stock memory variable for current X-machine.
 * \param demand_capital_stock New value for variable.
 */
void set_demand_capital_stock(double demand_capital_stock)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).demand_capital_stock = demand_capital_stock;
}

/** \fn double get_demand_capital_stock()
 * \brief Get demand_capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
double get_demand_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).demand_capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double_array get_last_planned_production_quantities()
 * \brief Get last_planned_production_quantities memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_last_planned_production_quantities()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).last_planned_production_quantities;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_day_of_month_to_act(int day_of_month_to_act) 
 * \brief Set day_of_month_to_act memory variable for current X-machine.
 * \param day_of_month_to_act New value for variable.
 */
void set_day_of_month_to_act(int day_of_month_to_act)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).day_of_month_to_act = day_of_month_to_act;
}

/** \fn int get_day_of_month_to_act()
 * \brief Get day_of_month_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_to_act()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).day_of_month_to_act;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).day_of_month_to_act;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).day_of_month_to_act;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).day_of_month_to_act;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_gov_id(int gov_id) 
 * \brief Set gov_id memory variable for current X-machine.
 * \param gov_id New value for variable.
 */
void set_gov_id(int gov_id)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).gov_id = gov_id;
}

/** \fn int get_gov_id()
 * \brief Get gov_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_gov_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).gov_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_bank_id(int bank_id) 
 * \brief Set bank_id memory variable for current X-machine.
 * \param bank_id New value for variable.
 */
void set_bank_id(int bank_id)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).bank_id = bank_id;
}

/** \fn int get_bank_id()
 * \brief Get bank_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bank_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).bank_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_ebit(double ebit) 
 * \brief Set ebit memory variable for current X-machine.
 * \param ebit New value for variable.
 */
void set_ebit(double ebit)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).ebit = ebit;
}

/** \fn double get_ebit()
 * \brief Get ebit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_ebit()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).ebit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_payment_account(double payment_account) 
 * \brief Set payment_account memory variable for current X-machine.
 * \param payment_account New value for variable.
 */
void set_payment_account(double payment_account)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).payment_account = payment_account;
}

/** \fn double get_payment_account()
 * \brief Get payment_account memory variable from current X-machine.
 * \return Value for variable.
 */
double get_payment_account()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).payment_account;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_earnings(double earnings) 
 * \brief Set earnings memory variable for current X-machine.
 * \param earnings New value for variable.
 */
void set_earnings(double earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).earnings = earnings;
}

/** \fn double get_earnings()
 * \brief Get earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate_corporate(double tax_rate_corporate) 
 * \brief Set tax_rate_corporate memory variable for current X-machine.
 * \param tax_rate_corporate New value for variable.
 */
void set_tax_rate_corporate(double tax_rate_corporate)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).tax_rate_corporate = tax_rate_corporate;
}

/** \fn double get_tax_rate_corporate()
 * \brief Get tax_rate_corporate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_corporate()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).tax_rate_corporate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_payment(double tax_payment) 
 * \brief Set tax_payment memory variable for current X-machine.
 * \param tax_payment New value for variable.
 */
void set_tax_payment(double tax_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).tax_payment = tax_payment;
}

/** \fn double get_tax_payment()
 * \brief Get tax_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).tax_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_net_earnings(double net_earnings) 
 * \brief Set net_earnings memory variable for current X-machine.
 * \param net_earnings New value for variable.
 */
void set_net_earnings(double net_earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).net_earnings = net_earnings;
}

/** \fn double get_net_earnings()
 * \brief Get net_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_net_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).net_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_previous_net_earnings(double previous_net_earnings) 
 * \brief Set previous_net_earnings memory variable for current X-machine.
 * \param previous_net_earnings New value for variable.
 */
void set_previous_net_earnings(double previous_net_earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).previous_net_earnings = previous_net_earnings;
}

/** \fn double get_previous_net_earnings()
 * \brief Get previous_net_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_previous_net_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).previous_net_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn debt_item_array get_loans()
 * \brief Get loans memory variable from current X-machine.
 * \return Value for variable.
 */
debt_item_array * get_loans()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).loans;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_interest_payment(double total_interest_payment) 
 * \brief Set total_interest_payment memory variable for current X-machine.
 * \param total_interest_payment New value for variable.
 */
void set_total_interest_payment(double total_interest_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_interest_payment = total_interest_payment;
}

/** \fn double get_total_interest_payment()
 * \brief Get total_interest_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_interest_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_interest_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_debt_installment_payment(double total_debt_installment_payment) 
 * \brief Set total_debt_installment_payment memory variable for current X-machine.
 * \param total_debt_installment_payment New value for variable.
 */
void set_total_debt_installment_payment(double total_debt_installment_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_debt_installment_payment = total_debt_installment_payment;
}

/** \fn double get_total_debt_installment_payment()
 * \brief Get total_debt_installment_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_debt_installment_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_debt_installment_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_debt(double total_debt) 
 * \brief Set total_debt memory variable for current X-machine.
 * \param total_debt New value for variable.
 */
void set_total_debt(double total_debt)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_debt = total_debt;
}

/** \fn double get_total_debt()
 * \brief Get total_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_debt()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_dividend_payment(double total_dividend_payment) 
 * \brief Set total_dividend_payment memory variable for current X-machine.
 * \param total_dividend_payment New value for variable.
 */
void set_total_dividend_payment(double total_dividend_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_dividend_payment = total_dividend_payment;
}

/** \fn double get_total_dividend_payment()
 * \brief Get total_dividend_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_dividend_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_dividend_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_value_local_inventory(double total_value_local_inventory) 
 * \brief Set total_value_local_inventory memory variable for current X-machine.
 * \param total_value_local_inventory New value for variable.
 */
void set_total_value_local_inventory(double total_value_local_inventory)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_value_local_inventory = total_value_local_inventory;
}

/** \fn double get_total_value_local_inventory()
 * \brief Get total_value_local_inventory memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_value_local_inventory()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_value_local_inventory;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_assets(double total_assets) 
 * \brief Set total_assets memory variable for current X-machine.
 * \param total_assets New value for variable.
 */
void set_total_assets(double total_assets)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_assets = total_assets;
}

/** \fn double get_total_assets()
 * \brief Get total_assets memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_assets()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_assets;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_cum_revenue(double planned_cum_revenue) 
 * \brief Set planned_cum_revenue memory variable for current X-machine.
 * \param planned_cum_revenue New value for variable.
 */
void set_planned_cum_revenue(double planned_cum_revenue)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_cum_revenue = planned_cum_revenue;
}

/** \fn double get_planned_cum_revenue()
 * \brief Get planned_cum_revenue memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_cum_revenue()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_cum_revenue;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_total_interest_payment(double planned_total_interest_payment) 
 * \brief Set planned_total_interest_payment memory variable for current X-machine.
 * \param planned_total_interest_payment New value for variable.
 */
void set_planned_total_interest_payment(double planned_total_interest_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_total_interest_payment = planned_total_interest_payment;
}

/** \fn double get_planned_total_interest_payment()
 * \brief Get planned_total_interest_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_total_interest_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_total_interest_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_total_debt_installment_payment(double planned_total_debt_installment_payment) 
 * \brief Set planned_total_debt_installment_payment memory variable for current X-machine.
 * \param planned_total_debt_installment_payment New value for variable.
 */
void set_planned_total_debt_installment_payment(double planned_total_debt_installment_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_total_debt_installment_payment = planned_total_debt_installment_payment;
}

/** \fn double get_planned_total_debt_installment_payment()
 * \brief Get planned_total_debt_installment_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_total_debt_installment_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_total_debt_installment_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_total_dividend_payment(double planned_total_dividend_payment) 
 * \brief Set planned_total_dividend_payment memory variable for current X-machine.
 * \param planned_total_dividend_payment New value for variable.
 */
void set_planned_total_dividend_payment(double planned_total_dividend_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_total_dividend_payment = planned_total_dividend_payment;
}

/** \fn double get_planned_total_dividend_payment()
 * \brief Get planned_total_dividend_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_total_dividend_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_total_dividend_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_direct_financial_needs(double direct_financial_needs) 
 * \brief Set direct_financial_needs memory variable for current X-machine.
 * \param direct_financial_needs New value for variable.
 */
void set_direct_financial_needs(double direct_financial_needs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).direct_financial_needs = direct_financial_needs;
}

/** \fn double get_direct_financial_needs()
 * \brief Get direct_financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_direct_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).direct_financial_needs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_delayed_financial_needs(double delayed_financial_needs) 
 * \brief Set delayed_financial_needs memory variable for current X-machine.
 * \param delayed_financial_needs New value for variable.
 */
void set_delayed_financial_needs(double delayed_financial_needs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).delayed_financial_needs = delayed_financial_needs;
}

/** \fn double get_delayed_financial_needs()
 * \brief Get delayed_financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_delayed_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).delayed_financial_needs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_financial_needs(double total_financial_needs) 
 * \brief Set total_financial_needs memory variable for current X-machine.
 * \param total_financial_needs New value for variable.
 */
void set_total_financial_needs(double total_financial_needs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_financial_needs = total_financial_needs;
}

/** \fn double get_total_financial_needs()
 * \brief Get total_financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_financial_needs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_internal_financial_needs(double internal_financial_needs) 
 * \brief Set internal_financial_needs memory variable for current X-machine.
 * \param internal_financial_needs New value for variable.
 */
void set_internal_financial_needs(double internal_financial_needs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).internal_financial_needs = internal_financial_needs;
}

/** \fn double get_internal_financial_needs()
 * \brief Get internal_financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_internal_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).internal_financial_needs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_external_financial_needs(double external_financial_needs) 
 * \brief Set external_financial_needs memory variable for current X-machine.
 * \param external_financial_needs New value for variable.
 */
void set_external_financial_needs(double external_financial_needs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).external_financial_needs = external_financial_needs;
}

/** \fn double get_external_financial_needs()
 * \brief Get external_financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_external_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).external_financial_needs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_external_financing_obtained(double total_external_financing_obtained) 
 * \brief Set total_external_financing_obtained memory variable for current X-machine.
 * \param total_external_financing_obtained New value for variable.
 */
void set_total_external_financing_obtained(double total_external_financing_obtained)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_external_financing_obtained = total_external_financing_obtained;
}

/** \fn double get_total_external_financing_obtained()
 * \brief Get total_external_financing_obtained memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_external_financing_obtained()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_external_financing_obtained;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_direct_financial_needs_require_external_financing(int direct_financial_needs_require_external_financing) 
 * \brief Set direct_financial_needs_require_external_financing memory variable for current X-machine.
 * \param direct_financial_needs_require_external_financing New value for variable.
 */
void set_direct_financial_needs_require_external_financing(int direct_financial_needs_require_external_financing)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).direct_financial_needs_require_external_financing = direct_financial_needs_require_external_financing;
}

/** \fn int get_direct_financial_needs_require_external_financing()
 * \brief Get direct_financial_needs_require_external_financing memory variable from current X-machine.
 * \return Value for variable.
 */
int get_direct_financial_needs_require_external_financing()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).direct_financial_needs_require_external_financing;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_delayed_financial_needs_require_external_financing(int delayed_financial_needs_require_external_financing) 
 * \brief Set delayed_financial_needs_require_external_financing memory variable for current X-machine.
 * \param delayed_financial_needs_require_external_financing New value for variable.
 */
void set_delayed_financial_needs_require_external_financing(int delayed_financial_needs_require_external_financing)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).delayed_financial_needs_require_external_financing = delayed_financial_needs_require_external_financing;
}

/** \fn int get_delayed_financial_needs_require_external_financing()
 * \brief Get delayed_financial_needs_require_external_financing memory variable from current X-machine.
 * \return Value for variable.
 */
int get_delayed_financial_needs_require_external_financing()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).delayed_financial_needs_require_external_financing;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_current_share_price(double current_share_price) 
 * \brief Set current_share_price memory variable for current X-machine.
 * \param current_share_price New value for variable.
 */
void set_current_share_price(double current_share_price)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_share_price = current_share_price;
}

/** \fn double get_current_share_price()
 * \brief Get current_share_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_share_price()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_share_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_shares_outstanding(double current_shares_outstanding) 
 * \brief Set current_shares_outstanding memory variable for current X-machine.
 * \param current_shares_outstanding New value for variable.
 */
void set_current_shares_outstanding(double current_shares_outstanding)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_shares_outstanding = current_shares_outstanding;
}

/** \fn double get_current_shares_outstanding()
 * \brief Get current_shares_outstanding memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_shares_outstanding()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_shares_outstanding;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_previous_dividend_per_share(double previous_dividend_per_share) 
 * \brief Set previous_dividend_per_share memory variable for current X-machine.
 * \param previous_dividend_per_share New value for variable.
 */
void set_previous_dividend_per_share(double previous_dividend_per_share)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).previous_dividend_per_share = previous_dividend_per_share;
}

/** \fn double get_previous_dividend_per_share()
 * \brief Get previous_dividend_per_share memory variable from current X-machine.
 * \return Value for variable.
 */
double get_previous_dividend_per_share()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).previous_dividend_per_share;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_dividend_per_share(double current_dividend_per_share) 
 * \brief Set current_dividend_per_share memory variable for current X-machine.
 * \param current_dividend_per_share New value for variable.
 */
void set_current_dividend_per_share(double current_dividend_per_share)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_dividend_per_share = current_dividend_per_share;
}

/** \fn double get_current_dividend_per_share()
 * \brief Get current_dividend_per_share memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_dividend_per_share()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_dividend_per_share;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_previous_dividend_per_earnings(double previous_dividend_per_earnings) 
 * \brief Set previous_dividend_per_earnings memory variable for current X-machine.
 * \param previous_dividend_per_earnings New value for variable.
 */
void set_previous_dividend_per_earnings(double previous_dividend_per_earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).previous_dividend_per_earnings = previous_dividend_per_earnings;
}

/** \fn double get_previous_dividend_per_earnings()
 * \brief Get previous_dividend_per_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_previous_dividend_per_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).previous_dividend_per_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_dividend_per_earnings(double current_dividend_per_earnings) 
 * \brief Set current_dividend_per_earnings memory variable for current X-machine.
 * \param current_dividend_per_earnings New value for variable.
 */
void set_current_dividend_per_earnings(double current_dividend_per_earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_dividend_per_earnings = current_dividend_per_earnings;
}

/** \fn double get_current_dividend_per_earnings()
 * \brief Get current_dividend_per_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_dividend_per_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_dividend_per_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_earnings_per_share_ratio(double earnings_per_share_ratio) 
 * \brief Set earnings_per_share_ratio memory variable for current X-machine.
 * \param earnings_per_share_ratio New value for variable.
 */
void set_earnings_per_share_ratio(double earnings_per_share_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).earnings_per_share_ratio = earnings_per_share_ratio;
}

/** \fn double get_earnings_per_share_ratio()
 * \brief Get earnings_per_share_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earnings_per_share_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).earnings_per_share_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_debt_earnings_ratio(double debt_earnings_ratio) 
 * \brief Set debt_earnings_ratio memory variable for current X-machine.
 * \param debt_earnings_ratio New value for variable.
 */
void set_debt_earnings_ratio(double debt_earnings_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).debt_earnings_ratio = debt_earnings_ratio;
}

/** \fn double get_debt_earnings_ratio()
 * \brief Get debt_earnings_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_debt_earnings_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).debt_earnings_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_price_earnings_ratio(double price_earnings_ratio) 
 * \brief Set price_earnings_ratio memory variable for current X-machine.
 * \param price_earnings_ratio New value for variable.
 */
void set_price_earnings_ratio(double price_earnings_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).price_earnings_ratio = price_earnings_ratio;
}

/** \fn double get_price_earnings_ratio()
 * \brief Get price_earnings_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price_earnings_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).price_earnings_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_retained_earnings_ratio(double retained_earnings_ratio) 
 * \brief Set retained_earnings_ratio memory variable for current X-machine.
 * \param retained_earnings_ratio New value for variable.
 */
void set_retained_earnings_ratio(double retained_earnings_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).retained_earnings_ratio = retained_earnings_ratio;
}

/** \fn double get_retained_earnings_ratio()
 * \brief Get retained_earnings_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_retained_earnings_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).retained_earnings_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_earnings_per_share_ratio_growth(double earnings_per_share_ratio_growth) 
 * \brief Set earnings_per_share_ratio_growth memory variable for current X-machine.
 * \param earnings_per_share_ratio_growth New value for variable.
 */
void set_earnings_per_share_ratio_growth(double earnings_per_share_ratio_growth)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).earnings_per_share_ratio_growth = earnings_per_share_ratio_growth;
}

/** \fn double get_earnings_per_share_ratio_growth()
 * \brief Get earnings_per_share_ratio_growth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earnings_per_share_ratio_growth()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).earnings_per_share_ratio_growth;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_critical_price_earnings_ratio(double critical_price_earnings_ratio) 
 * \brief Set critical_price_earnings_ratio memory variable for current X-machine.
 * \param critical_price_earnings_ratio New value for variable.
 */
void set_critical_price_earnings_ratio(double critical_price_earnings_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).critical_price_earnings_ratio = critical_price_earnings_ratio;
}

/** \fn double get_critical_price_earnings_ratio()
 * \brief Get critical_price_earnings_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_critical_price_earnings_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).critical_price_earnings_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_critical_earnings_per_share_ratio(double critical_earnings_per_share_ratio) 
 * \brief Set critical_earnings_per_share_ratio memory variable for current X-machine.
 * \param critical_earnings_per_share_ratio New value for variable.
 */
void set_critical_earnings_per_share_ratio(double critical_earnings_per_share_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).critical_earnings_per_share_ratio = critical_earnings_per_share_ratio;
}

/** \fn double get_critical_earnings_per_share_ratio()
 * \brief Get critical_earnings_per_share_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_critical_earnings_per_share_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).critical_earnings_per_share_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_target_loans(double target_loans) 
 * \brief Set target_loans memory variable for current X-machine.
 * \param target_loans New value for variable.
 */
void set_target_loans(double target_loans)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).target_loans = target_loans;
}

/** \fn double get_target_loans()
 * \brief Get target_loans memory variable from current X-machine.
 * \return Value for variable.
 */
double get_target_loans()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).target_loans;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_target_equity(double target_equity) 
 * \brief Set target_equity memory variable for current X-machine.
 * \param target_equity New value for variable.
 */
void set_target_equity(double target_equity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).target_equity = target_equity;
}

/** \fn double get_target_equity()
 * \brief Get target_equity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_target_equity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).target_equity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_bonds_issue_target(double bonds_issue_target) 
 * \brief Set bonds_issue_target memory variable for current X-machine.
 * \param bonds_issue_target New value for variable.
 */
void set_bonds_issue_target(double bonds_issue_target)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).bonds_issue_target = bonds_issue_target;
}

/** \fn double get_bonds_issue_target()
 * \brief Get bonds_issue_target memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bonds_issue_target()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).bonds_issue_target;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_stocks_issue_target(double stocks_issue_target) 
 * \brief Set stocks_issue_target memory variable for current X-machine.
 * \param stocks_issue_target New value for variable.
 */
void set_stocks_issue_target(double stocks_issue_target)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).stocks_issue_target = stocks_issue_target;
}

/** \fn double get_stocks_issue_target()
 * \brief Get stocks_issue_target memory variable from current X-machine.
 * \return Value for variable.
 */
double get_stocks_issue_target()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).stocks_issue_target;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_range(double range) 
 * \brief Set range memory variable for current X-machine.
 * \param range New value for variable.
 */
void set_range(double range)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).range = range;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).range = range;
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).range = range;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).range = range;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).range = range;
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).range = range;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).range = range;
}

/** \fn double get_range()
 * \brief Get range memory variable from current X-machine.
 * \return Value for variable.
 */
double get_range()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).range;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).range;
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).range;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).range;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).range;
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).range;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).range;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_posx(double posx) 
 * \brief Set posx memory variable for current X-machine.
 * \param posx New value for variable.
 */
void set_posx(double posx)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).posx = posx;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).posx = posx;
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).posx = posx;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).posx = posx;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).posx = posx;
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).posx = posx;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).posx = posx;
}

/** \fn double get_posx()
 * \brief Get posx memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posx()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).posx;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).posx;
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).posx;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).posx;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).posx;
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).posx;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).posx;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_posy(double posy) 
 * \brief Set posy memory variable for current X-machine.
 * \param posy New value for variable.
 */
void set_posy(double posy)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).posy = posy;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).posy = posy;
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).posy = posy;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).posy = posy;
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).posy = posy;
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).posy = posy;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).posy = posy;
}

/** \fn double get_posy()
 * \brief Get posy memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posy()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).posy;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).posy;
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).posy;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).posy;
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).posy;
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).posy;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).posy;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn int_array get_neighboring_region_ids()
 * \brief Get neighboring_region_ids memory variable from current X-machine.
 * \return Value for variable.
 */
int_array * get_neighboring_region_ids()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).neighboring_region_ids;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_wage(double wage) 
 * \brief Set wage memory variable for current X-machine.
 * \param wage New value for variable.
 */
void set_wage(double wage)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).wage = wage;
}

/** \fn double get_wage()
 * \brief Get wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_reservation(double wage_reservation) 
 * \brief Set wage_reservation memory variable for current X-machine.
 * \param wage_reservation New value for variable.
 */
void set_wage_reservation(double wage_reservation)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).wage_reservation = wage_reservation;
}

/** \fn double get_wage_reservation()
 * \brief Get wage_reservation memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_reservation()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).wage_reservation;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_general_skill(int general_skill) 
 * \brief Set general_skill memory variable for current X-machine.
 * \param general_skill New value for variable.
 */
void set_general_skill(int general_skill)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).general_skill = general_skill;
}

/** \fn int get_general_skill()
 * \brief Get general_skill memory variable from current X-machine.
 * \return Value for variable.
 */
int get_general_skill()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).general_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_on_the_job_search(int on_the_job_search) 
 * \brief Set on_the_job_search memory variable for current X-machine.
 * \param on_the_job_search New value for variable.
 */
void set_on_the_job_search(int on_the_job_search)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).on_the_job_search = on_the_job_search;
}

/** \fn int get_on_the_job_search()
 * \brief Get on_the_job_search memory variable from current X-machine.
 * \return Value for variable.
 */
int get_on_the_job_search()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).on_the_job_search;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_number_applications(int number_applications) 
 * \brief Set number_applications memory variable for current X-machine.
 * \param number_applications New value for variable.
 */
void set_number_applications(int number_applications)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).number_applications = number_applications;
}

/** \fn int get_number_applications()
 * \brief Get number_applications memory variable from current X-machine.
 * \return Value for variable.
 */
int get_number_applications()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).number_applications;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_specific_skill(double specific_skill) 
 * \brief Set specific_skill memory variable for current X-machine.
 * \param specific_skill New value for variable.
 */
void set_specific_skill(double specific_skill)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).specific_skill = specific_skill;
}

/** \fn double get_specific_skill()
 * \brief Get specific_skill memory variable from current X-machine.
 * \return Value for variable.
 */
double get_specific_skill()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).specific_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_employee_firm_id(int employee_firm_id) 
 * \brief Set employee_firm_id memory variable for current X-machine.
 * \param employee_firm_id New value for variable.
 */
void set_employee_firm_id(int employee_firm_id)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).employee_firm_id = employee_firm_id;
}

/** \fn int get_employee_firm_id()
 * \brief Get employee_firm_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employee_firm_id()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).employee_firm_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employer_region_id(int employer_region_id) 
 * \brief Set employer_region_id memory variable for current X-machine.
 * \param employer_region_id New value for variable.
 */
void set_employer_region_id(int employer_region_id)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).employer_region_id = employer_region_id;
}

/** \fn int get_employer_region_id()
 * \brief Get employer_region_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employer_region_id()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).employer_region_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_budget(double budget) 
 * \brief Set budget memory variable for current X-machine.
 * \param budget New value for variable.
 */
void set_budget(double budget)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).budget = budget;
}

/** \fn double get_budget()
 * \brief Get budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_budget()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_week_of_month(int week_of_month) 
 * \brief Set week_of_month memory variable for current X-machine.
 * \param week_of_month New value for variable.
 */
void set_week_of_month(int week_of_month)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).week_of_month = week_of_month;
}

/** \fn int get_week_of_month()
 * \brief Get week_of_month memory variable from current X-machine.
 * \return Value for variable.
 */
int get_week_of_month()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).week_of_month;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_weekly_budget(double weekly_budget) 
 * \brief Set weekly_budget memory variable for current X-machine.
 * \param weekly_budget New value for variable.
 */
void set_weekly_budget(double weekly_budget)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).weekly_budget = weekly_budget;
}

/** \fn double get_weekly_budget()
 * \brief Get weekly_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_weekly_budget()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).weekly_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_expenditures(double expenditures) 
 * \brief Set expenditures memory variable for current X-machine.
 * \param expenditures New value for variable.
 */
void set_expenditures(double expenditures)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).expenditures = expenditures;
}

/** \fn double get_expenditures()
 * \brief Get expenditures memory variable from current X-machine.
 * \return Value for variable.
 */
double get_expenditures()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).expenditures;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_received_dividend_cap(double received_dividend_cap) 
 * \brief Set received_dividend_cap memory variable for current X-machine.
 * \param received_dividend_cap New value for variable.
 */
void set_received_dividend_cap(double received_dividend_cap)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).received_dividend_cap = received_dividend_cap;
}

/** \fn double get_received_dividend_cap()
 * \brief Get received_dividend_cap memory variable from current X-machine.
 * \return Value for variable.
 */
double get_received_dividend_cap()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).received_dividend_cap;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_received_dividend_cons(double received_dividend_cons) 
 * \brief Set received_dividend_cons memory variable for current X-machine.
 * \param received_dividend_cons New value for variable.
 */
void set_received_dividend_cons(double received_dividend_cons)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).received_dividend_cons = received_dividend_cons;
}

/** \fn double get_received_dividend_cons()
 * \brief Get received_dividend_cons memory variable from current X-machine.
 * \return Value for variable.
 */
double get_received_dividend_cons()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).received_dividend_cons;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_savings(double savings) 
 * \brief Set savings memory variable for current X-machine.
 * \param savings New value for variable.
 */
void set_savings(double savings)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).savings = savings;
}

/** \fn double get_savings()
 * \brief Get savings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_savings()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).savings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double_array get_last_income()
 * \brief Get last_income memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_last_income()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).last_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_rationed(int rationed) 
 * \brief Set rationed memory variable for current X-machine.
 * \param rationed New value for variable.
 */
void set_rationed(int rationed)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).rationed = rationed;
}

/** \fn int get_rationed()
 * \brief Get rationed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_rationed()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).rationed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_mall_completely_sold_out(int mall_completely_sold_out) 
 * \brief Set mall_completely_sold_out memory variable for current X-machine.
 * \param mall_completely_sold_out New value for variable.
 */
void set_mall_completely_sold_out(int mall_completely_sold_out)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).mall_completely_sold_out = mall_completely_sold_out;
}

/** \fn int get_mall_completely_sold_out()
 * \brief Get mall_completely_sold_out memory variable from current X-machine.
 * \return Value for variable.
 */
int get_mall_completely_sold_out()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).mall_completely_sold_out;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn ordered_quantity get_order_quantity()
 * \brief Get order_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
ordered_quantity * get_order_quantity()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).order_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn received_quantities get_received_quantity()
 * \brief Get received_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
received_quantities * get_received_quantity()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).received_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_day_of_week_to_act(int day_of_week_to_act) 
 * \brief Set day_of_week_to_act memory variable for current X-machine.
 * \param day_of_week_to_act New value for variable.
 */
void set_day_of_week_to_act(int day_of_week_to_act)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).day_of_week_to_act = day_of_week_to_act;
}

/** \fn int get_day_of_week_to_act()
 * \brief Get day_of_week_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_week_to_act()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).day_of_week_to_act;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn mall_stock_array get_current_stock()
 * \brief Get current_stock memory variable from current X-machine.
 * \return Value for variable.
 */
mall_stock_array * get_current_stock()
{
	if(current_xmachine->xmachine_Mall) return &(*current_xmachine->xmachine_Mall).current_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn sales_in_mall_array get_firm_revenues()
 * \brief Get firm_revenues memory variable from current X-machine.
 * \return Value for variable.
 */
sales_in_mall_array * get_firm_revenues()
{
	if(current_xmachine->xmachine_Mall) return &(*current_xmachine->xmachine_Mall).firm_revenues;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_supply(double total_supply) 
 * \brief Set total_supply memory variable for current X-machine.
 * \param total_supply New value for variable.
 */
void set_total_supply(double total_supply)
{
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).total_supply = total_supply;
}

/** \fn double get_total_supply()
 * \brief Get total_supply memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_supply()
{
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).total_supply;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_productivity(double productivity) 
 * \brief Set productivity memory variable for current X-machine.
 * \param productivity New value for variable.
 */
void set_productivity(double productivity)
{
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).productivity = productivity;
}

/** \fn double get_productivity()
 * \brief Get productivity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_productivity()
{
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).productivity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_innovation_probability(int innovation_probability) 
 * \brief Set innovation_probability memory variable for current X-machine.
 * \param innovation_probability New value for variable.
 */
void set_innovation_probability(int innovation_probability)
{
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).innovation_probability = innovation_probability;
}

/** \fn int get_innovation_probability()
 * \brief Get innovation_probability memory variable from current X-machine.
 * \return Value for variable.
 */
int get_innovation_probability()
{
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).innovation_probability;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_productivity_progress(double productivity_progress) 
 * \brief Set productivity_progress memory variable for current X-machine.
 * \param productivity_progress New value for variable.
 */
void set_productivity_progress(double productivity_progress)
{
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).productivity_progress = productivity_progress;
}

/** \fn double get_productivity_progress()
 * \brief Get productivity_progress memory variable from current X-machine.
 * \return Value for variable.
 */
double get_productivity_progress()
{
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).productivity_progress;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_capital_good_price(double capital_good_price) 
 * \brief Set capital_good_price memory variable for current X-machine.
 * \param capital_good_price New value for variable.
 */
void set_capital_good_price(double capital_good_price)
{
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).capital_good_price = capital_good_price;
}

/** \fn double get_capital_good_price()
 * \brief Get capital_good_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_capital_good_price()
{
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).capital_good_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_no_regions(int no_regions) 
 * \brief Set no_regions memory variable for current X-machine.
 * \param no_regions New value for variable.
 */
void set_no_regions(int no_regions)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_regions = no_regions;
}

/** \fn int get_no_regions()
 * \brief Get no_regions memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_regions()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_regions;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_num_households(int num_households) 
 * \brief Set num_households memory variable for current X-machine.
 * \param num_households New value for variable.
 */
void set_num_households(int num_households)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).num_households = num_households;
}

/** \fn int get_num_households()
 * \brief Get num_households memory variable from current X-machine.
 * \return Value for variable.
 */
int get_num_households()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).num_households;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_1(int no_households_skill_1) 
 * \brief Set no_households_skill_1 memory variable for current X-machine.
 * \param no_households_skill_1 New value for variable.
 */
void set_no_households_skill_1(int no_households_skill_1)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_households_skill_1 = no_households_skill_1;
}

/** \fn int get_no_households_skill_1()
 * \brief Get no_households_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_1()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_households_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_2(int no_households_skill_2) 
 * \brief Set no_households_skill_2 memory variable for current X-machine.
 * \param no_households_skill_2 New value for variable.
 */
void set_no_households_skill_2(int no_households_skill_2)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_households_skill_2 = no_households_skill_2;
}

/** \fn int get_no_households_skill_2()
 * \brief Get no_households_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_2()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_households_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_3(int no_households_skill_3) 
 * \brief Set no_households_skill_3 memory variable for current X-machine.
 * \param no_households_skill_3 New value for variable.
 */
void set_no_households_skill_3(int no_households_skill_3)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_households_skill_3 = no_households_skill_3;
}

/** \fn int get_no_households_skill_3()
 * \brief Get no_households_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_3()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_households_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_4(int no_households_skill_4) 
 * \brief Set no_households_skill_4 memory variable for current X-machine.
 * \param no_households_skill_4 New value for variable.
 */
void set_no_households_skill_4(int no_households_skill_4)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_households_skill_4 = no_households_skill_4;
}

/** \fn int get_no_households_skill_4()
 * \brief Get no_households_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_4()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_households_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_5(int no_households_skill_5) 
 * \brief Set no_households_skill_5 memory variable for current X-machine.
 * \param no_households_skill_5 New value for variable.
 */
void set_no_households_skill_5(int no_households_skill_5)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_households_skill_5 = no_households_skill_5;
}

/** \fn int get_no_households_skill_5()
 * \brief Get no_households_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_5()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_households_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed(int employed) 
 * \brief Set employed memory variable for current X-machine.
 * \param employed New value for variable.
 */
void set_employed(int employed)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).employed = employed;
}

/** \fn int get_employed()
 * \brief Get employed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).employed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_1(int employed_skill_1) 
 * \brief Set employed_skill_1 memory variable for current X-machine.
 * \param employed_skill_1 New value for variable.
 */
void set_employed_skill_1(int employed_skill_1)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).employed_skill_1 = employed_skill_1;
}

/** \fn int get_employed_skill_1()
 * \brief Get employed_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_1()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).employed_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_2(int employed_skill_2) 
 * \brief Set employed_skill_2 memory variable for current X-machine.
 * \param employed_skill_2 New value for variable.
 */
void set_employed_skill_2(int employed_skill_2)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).employed_skill_2 = employed_skill_2;
}

/** \fn int get_employed_skill_2()
 * \brief Get employed_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_2()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).employed_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_3(int employed_skill_3) 
 * \brief Set employed_skill_3 memory variable for current X-machine.
 * \param employed_skill_3 New value for variable.
 */
void set_employed_skill_3(int employed_skill_3)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).employed_skill_3 = employed_skill_3;
}

/** \fn int get_employed_skill_3()
 * \brief Get employed_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_3()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).employed_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_4(int employed_skill_4) 
 * \brief Set employed_skill_4 memory variable for current X-machine.
 * \param employed_skill_4 New value for variable.
 */
void set_employed_skill_4(int employed_skill_4)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).employed_skill_4 = employed_skill_4;
}

/** \fn int get_employed_skill_4()
 * \brief Get employed_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_4()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).employed_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_5(int employed_skill_5) 
 * \brief Set employed_skill_5 memory variable for current X-machine.
 * \param employed_skill_5 New value for variable.
 */
void set_employed_skill_5(int employed_skill_5)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).employed_skill_5 = employed_skill_5;
}

/** \fn int get_employed_skill_5()
 * \brief Get employed_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_5()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).employed_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_unemployed(int unemployed) 
 * \brief Set unemployed memory variable for current X-machine.
 * \param unemployed New value for variable.
 */
void set_unemployed(int unemployed)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).unemployed = unemployed;
}

/** \fn int get_unemployed()
 * \brief Get unemployed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_unemployed()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).unemployed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_unemployment_rate(double unemployment_rate) 
 * \brief Set unemployment_rate memory variable for current X-machine.
 * \param unemployment_rate New value for variable.
 */
void set_unemployment_rate(double unemployment_rate)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).unemployment_rate = unemployment_rate;
}

/** \fn double get_unemployment_rate()
 * \brief Get unemployment_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).unemployment_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_1(double unemployment_rate_skill_1) 
 * \brief Set unemployment_rate_skill_1 memory variable for current X-machine.
 * \param unemployment_rate_skill_1 New value for variable.
 */
void set_unemployment_rate_skill_1(double unemployment_rate_skill_1)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_1 = unemployment_rate_skill_1;
}

/** \fn double get_unemployment_rate_skill_1()
 * \brief Get unemployment_rate_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_1()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_2(double unemployment_rate_skill_2) 
 * \brief Set unemployment_rate_skill_2 memory variable for current X-machine.
 * \param unemployment_rate_skill_2 New value for variable.
 */
void set_unemployment_rate_skill_2(double unemployment_rate_skill_2)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_2 = unemployment_rate_skill_2;
}

/** \fn double get_unemployment_rate_skill_2()
 * \brief Get unemployment_rate_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_2()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_3(double unemployment_rate_skill_3) 
 * \brief Set unemployment_rate_skill_3 memory variable for current X-machine.
 * \param unemployment_rate_skill_3 New value for variable.
 */
void set_unemployment_rate_skill_3(double unemployment_rate_skill_3)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_3 = unemployment_rate_skill_3;
}

/** \fn double get_unemployment_rate_skill_3()
 * \brief Get unemployment_rate_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_3()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_4(double unemployment_rate_skill_4) 
 * \brief Set unemployment_rate_skill_4 memory variable for current X-machine.
 * \param unemployment_rate_skill_4 New value for variable.
 */
void set_unemployment_rate_skill_4(double unemployment_rate_skill_4)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_4 = unemployment_rate_skill_4;
}

/** \fn double get_unemployment_rate_skill_4()
 * \brief Get unemployment_rate_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_4()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_5(double unemployment_rate_skill_5) 
 * \brief Set unemployment_rate_skill_5 memory variable for current X-machine.
 * \param unemployment_rate_skill_5 New value for variable.
 */
void set_unemployment_rate_skill_5(double unemployment_rate_skill_5)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_5 = unemployment_rate_skill_5;
}

/** \fn double get_unemployment_rate_skill_5()
 * \brief Get unemployment_rate_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_5()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).unemployment_rate_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage(double average_wage) 
 * \brief Set average_wage memory variable for current X-machine.
 * \param average_wage New value for variable.
 */
void set_average_wage(double average_wage)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_wage = average_wage;
}

/** \fn double get_average_wage()
 * \brief Get average_wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_1(double average_wage_skill_1) 
 * \brief Set average_wage_skill_1 memory variable for current X-machine.
 * \param average_wage_skill_1 New value for variable.
 */
void set_average_wage_skill_1(double average_wage_skill_1)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_wage_skill_1 = average_wage_skill_1;
}

/** \fn double get_average_wage_skill_1()
 * \brief Get average_wage_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_1()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_wage_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_2(double average_wage_skill_2) 
 * \brief Set average_wage_skill_2 memory variable for current X-machine.
 * \param average_wage_skill_2 New value for variable.
 */
void set_average_wage_skill_2(double average_wage_skill_2)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_wage_skill_2 = average_wage_skill_2;
}

/** \fn double get_average_wage_skill_2()
 * \brief Get average_wage_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_2()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_wage_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_3(double average_wage_skill_3) 
 * \brief Set average_wage_skill_3 memory variable for current X-machine.
 * \param average_wage_skill_3 New value for variable.
 */
void set_average_wage_skill_3(double average_wage_skill_3)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_wage_skill_3 = average_wage_skill_3;
}

/** \fn double get_average_wage_skill_3()
 * \brief Get average_wage_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_3()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_wage_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_4(double average_wage_skill_4) 
 * \brief Set average_wage_skill_4 memory variable for current X-machine.
 * \param average_wage_skill_4 New value for variable.
 */
void set_average_wage_skill_4(double average_wage_skill_4)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_wage_skill_4 = average_wage_skill_4;
}

/** \fn double get_average_wage_skill_4()
 * \brief Get average_wage_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_4()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_wage_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_5(double average_wage_skill_5) 
 * \brief Set average_wage_skill_5 memory variable for current X-machine.
 * \param average_wage_skill_5 New value for variable.
 */
void set_average_wage_skill_5(double average_wage_skill_5)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_wage_skill_5 = average_wage_skill_5;
}

/** \fn double get_average_wage_skill_5()
 * \brief Get average_wage_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_5()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_wage_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill(double average_s_skill) 
 * \brief Set average_s_skill memory variable for current X-machine.
 * \param average_s_skill New value for variable.
 */
void set_average_s_skill(double average_s_skill)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_s_skill = average_s_skill;
}

/** \fn double get_average_s_skill()
 * \brief Get average_s_skill memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_s_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_1(double average_s_skill_1) 
 * \brief Set average_s_skill_1 memory variable for current X-machine.
 * \param average_s_skill_1 New value for variable.
 */
void set_average_s_skill_1(double average_s_skill_1)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_s_skill_1 = average_s_skill_1;
}

/** \fn double get_average_s_skill_1()
 * \brief Get average_s_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_1()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_s_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_2(double average_s_skill_2) 
 * \brief Set average_s_skill_2 memory variable for current X-machine.
 * \param average_s_skill_2 New value for variable.
 */
void set_average_s_skill_2(double average_s_skill_2)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_s_skill_2 = average_s_skill_2;
}

/** \fn double get_average_s_skill_2()
 * \brief Get average_s_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_2()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_s_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_3(double average_s_skill_3) 
 * \brief Set average_s_skill_3 memory variable for current X-machine.
 * \param average_s_skill_3 New value for variable.
 */
void set_average_s_skill_3(double average_s_skill_3)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_s_skill_3 = average_s_skill_3;
}

/** \fn double get_average_s_skill_3()
 * \brief Get average_s_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_3()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_s_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_4(double average_s_skill_4) 
 * \brief Set average_s_skill_4 memory variable for current X-machine.
 * \param average_s_skill_4 New value for variable.
 */
void set_average_s_skill_4(double average_s_skill_4)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_s_skill_4 = average_s_skill_4;
}

/** \fn double get_average_s_skill_4()
 * \brief Get average_s_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_4()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_s_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_5(double average_s_skill_5) 
 * \brief Set average_s_skill_5 memory variable for current X-machine.
 * \param average_s_skill_5 New value for variable.
 */
void set_average_s_skill_5(double average_s_skill_5)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).average_s_skill_5 = average_s_skill_5;
}

/** \fn double get_average_s_skill_5()
 * \brief Get average_s_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_5()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).average_s_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_no_firms(int no_firms) 
 * \brief Set no_firms memory variable for current X-machine.
 * \param no_firms New value for variable.
 */
void set_no_firms(int no_firms)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_firms = no_firms;
}

/** \fn int get_no_firms()
 * \brief Get no_firms memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_firms()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_firms;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_vacancies(int no_vacancies) 
 * \brief Set no_vacancies memory variable for current X-machine.
 * \param no_vacancies New value for variable.
 */
void set_no_vacancies(int no_vacancies)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).no_vacancies = no_vacancies;
}

/** \fn int get_no_vacancies()
 * \brief Get no_vacancies memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_vacancies()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).no_vacancies;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_firm_average_wage(double firm_average_wage) 
 * \brief Set firm_average_wage memory variable for current X-machine.
 * \param firm_average_wage New value for variable.
 */
void set_firm_average_wage(double firm_average_wage)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_wage = firm_average_wage;
}

/** \fn double get_firm_average_wage()
 * \brief Get firm_average_wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_1(double firm_average_wage_skill_1) 
 * \brief Set firm_average_wage_skill_1 memory variable for current X-machine.
 * \param firm_average_wage_skill_1 New value for variable.
 */
void set_firm_average_wage_skill_1(double firm_average_wage_skill_1)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_1 = firm_average_wage_skill_1;
}

/** \fn double get_firm_average_wage_skill_1()
 * \brief Get firm_average_wage_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_1()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_2(double firm_average_wage_skill_2) 
 * \brief Set firm_average_wage_skill_2 memory variable for current X-machine.
 * \param firm_average_wage_skill_2 New value for variable.
 */
void set_firm_average_wage_skill_2(double firm_average_wage_skill_2)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_2 = firm_average_wage_skill_2;
}

/** \fn double get_firm_average_wage_skill_2()
 * \brief Get firm_average_wage_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_2()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_3(double firm_average_wage_skill_3) 
 * \brief Set firm_average_wage_skill_3 memory variable for current X-machine.
 * \param firm_average_wage_skill_3 New value for variable.
 */
void set_firm_average_wage_skill_3(double firm_average_wage_skill_3)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_3 = firm_average_wage_skill_3;
}

/** \fn double get_firm_average_wage_skill_3()
 * \brief Get firm_average_wage_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_3()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_4(double firm_average_wage_skill_4) 
 * \brief Set firm_average_wage_skill_4 memory variable for current X-machine.
 * \param firm_average_wage_skill_4 New value for variable.
 */
void set_firm_average_wage_skill_4(double firm_average_wage_skill_4)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_4 = firm_average_wage_skill_4;
}

/** \fn double get_firm_average_wage_skill_4()
 * \brief Get firm_average_wage_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_4()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_5(double firm_average_wage_skill_5) 
 * \brief Set firm_average_wage_skill_5 memory variable for current X-machine.
 * \param firm_average_wage_skill_5 New value for variable.
 */
void set_firm_average_wage_skill_5(double firm_average_wage_skill_5)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_5 = firm_average_wage_skill_5;
}

/** \fn double get_firm_average_wage_skill_5()
 * \brief Get firm_average_wage_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_5()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_wage_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill(double firm_average_s_skill) 
 * \brief Set firm_average_s_skill memory variable for current X-machine.
 * \param firm_average_s_skill New value for variable.
 */
void set_firm_average_s_skill(double firm_average_s_skill)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_s_skill = firm_average_s_skill;
}

/** \fn double get_firm_average_s_skill()
 * \brief Get firm_average_s_skill memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_s_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_1(double firm_average_s_skill_1) 
 * \brief Set firm_average_s_skill_1 memory variable for current X-machine.
 * \param firm_average_s_skill_1 New value for variable.
 */
void set_firm_average_s_skill_1(double firm_average_s_skill_1)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_1 = firm_average_s_skill_1;
}

/** \fn double get_firm_average_s_skill_1()
 * \brief Get firm_average_s_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_1()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_2(double firm_average_s_skill_2) 
 * \brief Set firm_average_s_skill_2 memory variable for current X-machine.
 * \param firm_average_s_skill_2 New value for variable.
 */
void set_firm_average_s_skill_2(double firm_average_s_skill_2)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_2 = firm_average_s_skill_2;
}

/** \fn double get_firm_average_s_skill_2()
 * \brief Get firm_average_s_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_2()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_3(double firm_average_s_skill_3) 
 * \brief Set firm_average_s_skill_3 memory variable for current X-machine.
 * \param firm_average_s_skill_3 New value for variable.
 */
void set_firm_average_s_skill_3(double firm_average_s_skill_3)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_3 = firm_average_s_skill_3;
}

/** \fn double get_firm_average_s_skill_3()
 * \brief Get firm_average_s_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_3()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_4(double firm_average_s_skill_4) 
 * \brief Set firm_average_s_skill_4 memory variable for current X-machine.
 * \param firm_average_s_skill_4 New value for variable.
 */
void set_firm_average_s_skill_4(double firm_average_s_skill_4)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_4 = firm_average_s_skill_4;
}

/** \fn double get_firm_average_s_skill_4()
 * \brief Get firm_average_s_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_4()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_5(double firm_average_s_skill_5) 
 * \brief Set firm_average_s_skill_5 memory variable for current X-machine.
 * \param firm_average_s_skill_5 New value for variable.
 */
void set_firm_average_s_skill_5(double firm_average_s_skill_5)
{
	if(current_xmachine->xmachine_Market_Research) (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_5 = firm_average_s_skill_5;
}

/** \fn double get_firm_average_s_skill_5()
 * \brief Get firm_average_s_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_5()
{
	if(current_xmachine->xmachine_Market_Research) return (*current_xmachine->xmachine_Market_Research).firm_average_s_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn firm_data_array get_region_firm_data()
 * \brief Get region_firm_data memory variable from current X-machine.
 * \return Value for variable.
 */
firm_data_array * get_region_firm_data()
{
	if(current_xmachine->xmachine_Market_Research) return &(*current_xmachine->xmachine_Market_Research).region_firm_data;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn household_data_array get_region_household_data()
 * \brief Get region_household_data memory variable from current X-machine.
 * \return Value for variable.
 */
household_data_array * get_region_household_data()
{
	if(current_xmachine->xmachine_Market_Research) return &(*current_xmachine->xmachine_Market_Research).region_household_data;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_trader_id(int trader_id) 
 * \brief Set trader_id memory variable for current X-machine.
 * \param trader_id New value for variable.
 */
void set_trader_id(int trader_id)
{
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).trader_id = trader_id;
}

/** \fn int get_trader_id()
 * \brief Get trader_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_trader_id()
{
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).trader_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_stock_id(int stock_id) 
 * \brief Set stock_id memory variable for current X-machine.
 * \param stock_id New value for variable.
 */
void set_stock_id(int stock_id)
{
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).stock_id = stock_id;
}

/** \fn int get_stock_id()
 * \brief Get stock_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_stock_id()
{
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).stock_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_bond_id(int bond_id) 
 * \brief Set bond_id memory variable for current X-machine.
 * \param bond_id New value for variable.
 */
void set_bond_id(int bond_id)
{
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).bond_id = bond_id;
}

/** \fn int get_bond_id()
 * \brief Get bond_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bond_id()
{
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).bond_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_gov_bond_id(int gov_bond_id) 
 * \brief Set gov_bond_id memory variable for current X-machine.
 * \param gov_bond_id New value for variable.
 */
void set_gov_bond_id(int gov_bond_id)
{
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).gov_bond_id = gov_bond_id;
}

/** \fn int get_gov_bond_id()
 * \brief Get gov_bond_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_gov_bond_id()
{
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).gov_bond_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_limit_price(double limit_price) 
 * \brief Set limit_price memory variable for current X-machine.
 * \param limit_price New value for variable.
 */
void set_limit_price(double limit_price)
{
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).limit_price = limit_price;
}

/** \fn double get_limit_price()
 * \brief Get limit_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_limit_price()
{
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).limit_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_limit_quantity(double limit_quantity) 
 * \brief Set limit_quantity memory variable for current X-machine.
 * \param limit_quantity New value for variable.
 */
void set_limit_quantity(double limit_quantity)
{
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).limit_quantity = limit_quantity;
}

/** \fn double get_limit_quantity()
 * \brief Get limit_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_limit_quantity()
{
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).limit_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_proposed_interest_rate(double proposed_interest_rate) 
 * \brief Set proposed_interest_rate memory variable for current X-machine.
 * \param proposed_interest_rate New value for variable.
 */
void set_proposed_interest_rate(double proposed_interest_rate)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).proposed_interest_rate = proposed_interest_rate;
}

/** \fn double get_proposed_interest_rate()
 * \brief Get proposed_interest_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_proposed_interest_rate()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).proposed_interest_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_amount_credit_offer(double amount_credit_offer) 
 * \brief Set amount_credit_offer memory variable for current X-machine.
 * \param amount_credit_offer New value for variable.
 */
void set_amount_credit_offer(double amount_credit_offer)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).amount_credit_offer = amount_credit_offer;
}

/** \fn double get_amount_credit_offer()
 * \brief Get amount_credit_offer memory variable from current X-machine.
 * \return Value for variable.
 */
double get_amount_credit_offer()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).amount_credit_offer;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->range;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->range;
    if (current_xmachine->xmachine_Mall) value = current_xmachine->xmachine_Mall->range;
    if (current_xmachine->xmachine_IGFirm) value = current_xmachine->xmachine_IGFirm->range;
    if (current_xmachine->xmachine_Market_Research) value = current_xmachine->xmachine_Market_Research->range;
    if (current_xmachine->xmachine_Clearinghouse) value = current_xmachine->xmachine_Clearinghouse->range;
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->range;

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->id;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->id;
    if (current_xmachine->xmachine_Mall) value = current_xmachine->xmachine_Mall->id;
    if (current_xmachine->xmachine_IGFirm) value = current_xmachine->xmachine_IGFirm->id;
    if (current_xmachine->xmachine_Market_Research) value = current_xmachine->xmachine_Market_Research->id;
    if (current_xmachine->xmachine_Clearinghouse) value = current_xmachine->xmachine_Clearinghouse->id;
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->id;

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->posx;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->posx;
    if (current_xmachine->xmachine_Mall) value = current_xmachine->xmachine_Mall->posx;
    if (current_xmachine->xmachine_IGFirm) value = current_xmachine->xmachine_IGFirm->posx;
    if (current_xmachine->xmachine_Market_Research) value = current_xmachine->xmachine_Market_Research->posx;
    if (current_xmachine->xmachine_Clearinghouse) value = current_xmachine->xmachine_Clearinghouse->posx;
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->posx;

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->posy; 
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->posy; 
    if (current_xmachine->xmachine_Mall) value = current_xmachine->xmachine_Mall->posy; 
    if (current_xmachine->xmachine_IGFirm) value = current_xmachine->xmachine_IGFirm->posy; 
    if (current_xmachine->xmachine_Market_Research) value = current_xmachine->xmachine_Market_Research->posy; 
    if (current_xmachine->xmachine_Clearinghouse) value = current_xmachine->xmachine_Clearinghouse->posy; 
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->posy; 

    return value;
}
/** \fn double agent_get_z()
 * \brief Fixed routine to get the z coordinate from current X-machine
  * \return Value of z coordinate
  */
double agent_get_z()
{
    double value = 0.0;

    return value;
}
/** \fn void randomisexagent()
 * \brief Randomise the current X-machine list.
 * 
 * \author LS Chin (CCLRC)
 * \date March 2007
 */
void randomisexagent() {

    int i, rnd;
    int xm_count;
    xmachine *current;
    xmachine **address_list;
    
    xm_count = current_node->agent_total;

    /* allocate mem for dynamic temp array */
    address_list = (xmachine **)malloc(sizeof(xmachine *) * xm_count);
	CHECK_POINTER(address_list);

    p_xmachine = &current_node->agents;
    
    /* populate address list */
    i = 0;
    current = *p_xmachine;
    while(current)
    {
        address_list[i] = current;
        current = current->next;
        i++;
    }

    /* randomise address list */
    for (i = xm_count - 1; i > 0; i--)
    {
        /* get random number */
        rnd = (int)((double)i * rand() / (RAND_MAX + 1.0));

        if (rnd == i) continue;

        /* use 'current' as temp var to swap addresses */
        current = address_list[i];
        address_list[i] = address_list[rnd];
        address_list[rnd] = current;
    }

    /* build new xmachine list from randomised address list */
    *p_xmachine = NULL;
    for (i = 0; i < xm_count; i++)
    {
        address_list[i]->next = *p_xmachine;
        *p_xmachine = address_list[i];
    }

    free(address_list);
}


/** \fn void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
 * \brief Add a node to the node list.
 * \param node_id The node ID.
 * \param minx The minumum value on the x-axis of the bounding volume.
 * \param maxx The maximum value on the x-axis of the bounding volume.
 * \param miny The minumum value on the y-axis of the bounding volume.
 * \param maxy The maximum value on the y-axis of the bounding volume.
 * \param minz The minumum value on the z-axis of the bounding volume.
 * \param maxz The maximum value on the z-axis of the bounding volume.
 */
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
{
	node_information * current = *p_node_info;
	node_information * tmp = NULL;
	
	while(current)
	{
		tmp = current;
		current = current->next;
	}
	
	current = (node_information *)malloc(sizeof(node_information));
		CHECK_POINTER(current);

	if(tmp)
	{
		tmp->next = current;
	}
	else
	{
		*p_node_info = current;
	}
	
	current->next = NULL;
	current->node_id = node_id;
	current->agents_in_halo = 0;
	current->agent_total = 0;
	current->agents = NULL;
	current->vacancies_messages = NULL;
	current->vacancies2_messages = NULL;
	current->firing_messages = NULL;
	current->job_application_messages = NULL;
	current->job_application2_messages = NULL;
	current->job_offer_messages = NULL;
	current->job_offer2_messages = NULL;
	current->job_acceptance_messages = NULL;
	current->job_acceptance2_messages = NULL;
	current->application_rejection_messages = NULL;
	current->application_rejection2_messages = NULL;
	current->quitting_messages = NULL;
	current->quitting2_messages = NULL;
	current->productivity_messages = NULL;
	current->capital_good_request_messages = NULL;
	current->capital_good_profit_distribution_messages = NULL;
	current->capital_good_delivery_messages = NULL;
	current->wage_payment_messages = NULL;
	current->quality_price_info_1_messages = NULL;
	current->quality_price_info_2_messages = NULL;
	current->update_mall_stock_messages = NULL;
	current->consumption_request_1_messages = NULL;
	current->consumption_request_2_messages = NULL;
	current->accepted_consumption_1_messages = NULL;
	current->accepted_consumption_2_messages = NULL;
	current->sales_messages = NULL;
	current->pay_capital_goods_messages = NULL;
	current->current_mall_stock_info_messages = NULL;
	current->specific_skill_update_messages = NULL;
	current->firm_send_data_messages = NULL;
	current->household_send_data_messages = NULL;
	current->market_research_send_specific_skills_messages = NULL;
	current->tax_payment_messages = NULL;
	current->interest_payment_messages = NULL;
	current->debt_installment_payment_messages = NULL;
	current->dividend_payment_messages = NULL;
	current->loan_request_messages = NULL;
	current->loan_conditions_messages = NULL;
	current->loan_acceptance_messages = NULL;
	current->stock_order_messages = NULL;
	current->stock_transaction_messages = NULL;
	current->bond_order_messages = NULL;
	current->bond_transaction_messages = NULL;
	current->gov_bond_order_messages = NULL;
	current->gov_bond_transaction_messages = NULL;


	current->partition_data[0] = minx;
	current->partition_data[1] = maxx;
	current->partition_data[2] = miny;
	current->partition_data[3] = maxy;
	current->partition_data[4] = minz;
	current->partition_data[5] = maxz;
}

/**\fn void free_node_info()
 * \brief Free the node list.
 */
void free_node_info()
{
	node_information * tmp, * head;
	head = *p_node_info;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_node_info = NULL;
}

/**\fn void free_messages()
 * \brief Frees all the message lists (of the current node if in serial).
 */
void free_messages()
{
	freevacanciesmessages();	freevacancies2messages();	freefiringmessages();	freejob_applicationmessages();	freejob_application2messages();	freejob_offermessages();	freejob_offer2messages();	freejob_acceptancemessages();	freejob_acceptance2messages();	freeapplication_rejectionmessages();	freeapplication_rejection2messages();	freequittingmessages();	freequitting2messages();	freeproductivitymessages();	freecapital_good_requestmessages();	freecapital_good_profit_distributionmessages();	freecapital_good_deliverymessages();	freewage_paymentmessages();	freequality_price_info_1messages();	freequality_price_info_2messages();	freeupdate_mall_stockmessages();	freeconsumption_request_1messages();	freeconsumption_request_2messages();	freeaccepted_consumption_1messages();	freeaccepted_consumption_2messages();	freesalesmessages();	freepay_capital_goodsmessages();	freecurrent_mall_stock_infomessages();	freespecific_skill_updatemessages();	freefirm_send_datamessages();	freehousehold_send_datamessages();	freemarket_research_send_specific_skillsmessages();	freetax_paymentmessages();	freeinterest_paymentmessages();	freedebt_installment_paymentmessages();	freedividend_paymentmessages();	freeloan_requestmessages();	freeloan_conditionsmessages();	freeloan_acceptancemessages();	freestock_ordermessages();	freestock_transactionmessages();	freebond_ordermessages();	freebond_transactionmessages();	freegov_bond_ordermessages();	freegov_bond_transactionmessages();
}

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
	FILE *file;
	char data[100];
	
	
	/* Free x-machine memory */

	current_node = *p_node_info;
	while(current_node)
	{
		p_xmachine = &current_node->agents;

	freexmachines();
	current_node->agent_total = 0;

		current_node = current_node->next;
	}

	/* Free space partitions linked list */
	free_node_info();
	

	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<totaltime>", file);
	sprintf(data, "%ld", total_time);
	fputs(data, file);
	fputs("</totaltime>\n", file);
	/*fputs("<totalmessages>", file);
	sprintf(data, "%i", total_messages);
	fputs(data, file);
	fputs("</totalmessages>", file);*/
	fputs("</model_run>", file);
	fclose(file);

	
	if(code != 0)
	{
		printf("*** Error: ");
		if(code == 100) printf("cannot handle specified number of space partitions");
		if(code == 101) printf("could not find number of space partitions config in file");
		
		printf(" ***");
		exit(0);
	}
}


/** \fn void propagate_agents()
 * \brief Check agent positions to see if any need to be moved to a another node.
 */
void propagate_agents()
{
	node_information * node_info;
	xmachine * before_xmachine, * temp_xmachine;
	xmachine ** p_temp_xmachine;
	double x_xmachine, y_xmachine, z_xmachine;
	current_xmachine = *p_xmachine;
	before_xmachine = NULL;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_Firm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Firm->posx;
			y_xmachine = current_xmachine->xmachine_Firm->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Household->posx;
			y_xmachine = current_xmachine->xmachine_Household->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Mall != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Mall->posx;
			y_xmachine = current_xmachine->xmachine_Mall->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_IGFirm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_IGFirm->posx;
			y_xmachine = current_xmachine->xmachine_IGFirm->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Market_Research != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Market_Research->posx;
			y_xmachine = current_xmachine->xmachine_Market_Research->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Clearinghouse != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Clearinghouse->posx;
			y_xmachine = current_xmachine->xmachine_Clearinghouse->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Bank->posx;
			y_xmachine = current_xmachine->xmachine_Bank->posy;
			z_xmachine = 0.0;
		}
		
		if(x_xmachine < current_node->partition_data[0] ||
		   x_xmachine > current_node->partition_data[1] ||
		   y_xmachine < current_node->partition_data[2] ||
		   y_xmachine > current_node->partition_data[3] ||
		   z_xmachine < current_node->partition_data[4] ||
		   z_xmachine > current_node->partition_data[5])
		{
			node_info = *p_node_info;
			while(node_info)
			{
				if(node_info->node_id != current_node->node_id &&
				node_info->partition_data[0] < x_xmachine && node_info->partition_data[1] > x_xmachine &&
				node_info->partition_data[2] < y_xmachine && node_info->partition_data[3] > y_xmachine &&
				node_info->partition_data[4] < z_xmachine && node_info->partition_data[5] > z_xmachine)
				{
                    /* Remove agent */
                    if(before_xmachine) before_xmachine->next = current_xmachine->next;
                    else *p_xmachine = current_xmachine->next;
                    current_node->agent_total--;
                    /* Add agent */
                    p_temp_xmachine = &node_info->agents;
                    temp_xmachine = *p_temp_xmachine;
                    current_xmachine->next = temp_xmachine;
                    *p_temp_xmachine = current_xmachine;
                    node_info->agent_total++;
                    node_info = NULL;
				}
				else node_info = node_info->next;
				}
			}
			else before_xmachine = current_xmachine;
			
			if(before_xmachine) current_xmachine = before_xmachine->next;
			else current_xmachine = NULL;
		}
}


/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
void init_int_array(int_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (int *)malloc(ARRAY_BLOCK_SIZE * sizeof(int));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_int_array(int_array * array)
{
	(*array).size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_int_array(int_array * array)
{
	free((*array).array);
}

void copy_int_array(int_array * from, int_array * to)
{
	int i;
	//to = init_int_array();
	
	for (i = 0; i < (*from).size; i++)
	{
		add_int(to, (*from).array[i]);
	}
}

/** \fn void sort_int_array(int_array * array)
* \brief Sort the elements of a dynamic integer array with smallest first.
* \param array Pointer to the dynamic integer array.
*/
/*void sort_int_array(int_array * array)
{
	int i, j, temp;
	
	for(i=0; i<((*array).size-1); i++)
	{
		for(j=0; j<((*array).size-1)-i; j++) 
		{
			if(*((*array).array+j+1) < *((*array).array+j))
			{
                temp = *((*array).(*array)+j); 
                *((*array).array+j) = *((*array).array+j+1);
                *((*array).array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_int(int *array, int elements)
 *  \brief Sorts the elements of the integer array in ascending order.
 *  \param Pointer to integer array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_int(int array, int elements)
{
	#define  LEVEL  1000
	int  pivot, begin[LEVEL], end[LEVEL], i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_int(int_array * array, int new_int)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (int *)realloc((*array).array, ((*array).total_size * sizeof(int)));
	}
	(*array).array[(*array).size] = new_int;
	(*array).size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_int(int_array * array, int index)
{
	int i;
	
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_int_array(int_array * array)
 * \brief Print the elements of a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 */
void print_int_array(int_array * array)
{
	int i;
	
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %d", i, (*array).array[i]);
	}
}

/** \fn float_array * init_float_array()
 * \brief Allocate memory for a dynamic float array.
 * \return float_array Pointer to the new dynamic float array.
 */
void init_float_array(float_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (float *)malloc(ARRAY_BLOCK_SIZE * sizeof(float));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_float_array(float_array * array)
* \brief Reset the float array to hold nothing.
* \param array Pointer to the dynamic float array.
*/
void reset_float_array(float_array * array)
{
	(*array).size = 0;
}

/** \fn void free_float_array(float_array * array)
* \brief Free the memory of a dynamic float array.
* \param array Pointer to the dynamic float array.
*/
void free_float_array(float_array * array)
{
	free((*array).array);
}

void copy_float_array(float_array * from, float_array * to)
{
	int i;
	//to = init_float_array();
	
	for (i = 0; i < (*from).size; i++)
	{
		add_float(to, (*from).array[i]);
	}
}

/** \fn void sort_float_array(float_array * array)
* \brief Sort the elements of a dynamic float array with smallest first.
* \param array Pointer to the dynamic float array.
*/
/*void sort_float_array(float_array array)
{
	int i, j;
	float temp;
	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++) 
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j); 
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_float(float *array, int elements)
 *  \brief Sorts the elements of the float array in ascending order.
 *  \param Pointer to float array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_float(float array, int elements)
{
	#define  LEVEL  1000
	int i=0, left, right ;
	float pivot, begin[LEVEL], end[LEVEL];
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_float(float_array * array, float new_float)
* \brief Add an floateger to the dynamic float array.
* \param array Pointer to the dynamic float array.
* \param new_float The float to add
*/
void add_float(float_array * array, float new_float)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (float *)realloc((*array).array, ((*array).total_size * sizeof(float)));
	}
	(*array).array[(*array).size] = new_float;
	(*array).size++;
}

/** \fn void remove_float(float_array * array, int index)
 * \brief Remove an floateger from a dynamic float array.
 * \param array Pointer to the dynamic float array.
 * \param index The index of the float to remove.
 */
void remove_float(float_array * array, int index)
{
	int i;
	
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_float_array(float_array * array)
 * \brief Print the elements of a dynamic float array.
 * \param array Pointer to the dynamic float array.
 */
void print_float_array(float_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prfloats */
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn double_array * init_double_array()
 * \brief Allocate memory for a dynamic double array.
 * \return double_array Pointer to the new dynamic double array.
 */
void init_double_array(double_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (double *)malloc(ARRAY_BLOCK_SIZE * sizeof(double));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_double_array(double_array * array)
* \brief Reset the double array to hold nothing.
* \param array Pointer to the dynamic double array.
*/
void reset_double_array(double_array * array)
{
	(*array).size = 0;
}

/** \fn void free_double_array(double_array * array)
 * \brief Free the memory of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void free_double_array(double_array * array)
{
	free((*array).array);
}

void copy_double_array(double_array * from, double_array * to)
{
	int i;
	//to = init_double_array();
	
	for (i = 0; i < (*from).size; i++)
	{
		add_double(to, (*from).array[i]);
	}
}

/** \fn void sort_double_array(double_array * array)
 * \brief Sort the elements of a dynamic double array with smallest first.
 * \param array Pointer to the dynamic double array.
 */
/*void sort_double_array(double_array array)
{
	int i, j;
	double temp;
	
	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++) 
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j); 
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_double(double *array, int elements)
 *  \brief Sorts the elements of the double array in ascending order.
 *  \param Pointer to double array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_double(double array, int elements)
{
	#define  LEVEL  1000
	double pivot, begin[LEVEL], end[LEVEL];
	int  i=0, left, right ; 
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_double(double_array * array, double new_double)
 * \brief Add an double to the dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param new_double The double to add
 */
void add_double(double_array * array, double new_double)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (double *)realloc((*array).array, ((*array).total_size * sizeof(double)));
	}
	(*array).array[(*array).size] = new_double;
	(*array).size++;
}

/** \fn void remove_double(double_array * array, int index)
 * \brief Remove an double from a dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param index The index of the double to remove.
 */
void remove_double(double_array * array, int index)
{
	int i;
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_double_array(double_array * array)
 * \brief Print the elements of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void print_double_array(double_array * array)
{
	int i;
	
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn char_array * init_char_array()
 * \brief Allocate memory for a dynamic char array.
 * \return char_array Pointer to the new dynamic char array.
 */
void init_char_array(char_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (char *)malloc(ARRAY_BLOCK_SIZE * sizeof(char));
	CHECK_POINTER((*array).array);
	(*array).array[0] = '\0';
}

/** \fn void reset_char_array(char_array * array)
* \brief Reset the char array to hold nothing.
* \param array Pointer to the dynamic char array.
*/
void reset_char_array(char_array * array)
{
	(*array).size = 0;
}

/** \fn void free_char_array(char_array * array)
 * \brief Free the memory of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void free_char_array(char_array * array)
{
	free((*array).array);
}

void copy_char_array(char_array * from, char_array * to)
{
	int i;
	
	for (i = 0; i < (*from).size; i++)
	{
		add_char(to, (*from).array[i]);
	}
}

/** \fn void add_char(char_array * array, char new_char)
 * \brief Add an char to the dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param new_char The char to add
 */
void add_char(char_array * array, char new_char)
{
	if((*array).size + 1 == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (char *)realloc((*array).array, ((*array).total_size * sizeof(char)));
	}
	(*array).array[(*array).size] = new_char;
	(*array).array[(*array).size + 1] = '\0';
	(*array).size++;
}

/** \fn void remove_char(char_array * array, int index)
 * \brief Remove an char from a dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param index The index of the char to remove.
 */
void remove_char(char_array * array, int index)
{
	int i;
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn char * copy_array_to_str(char_array * array)
 * \brief Return pointer to string from a char_array.
 * \param array Pointer to the dynamic integer array.
 * \return char Pointer to the new string.
 */
char * copy_array_to_str(char_array * array)
{
	char * new_string = (char *)malloc( ((*array).size + 1) * sizeof(char));
	CHECK_POINTER(new_string);
	return strcpy(new_string, (*array).array);
}

/** \fn void print_char_array(char_array * array)
 * \brief Print the elements of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void print_char_array(char_array * array)
{
	printf("%s", (*array).array);
}

/* Functions for the employee datatype */
/** \fn employee_array * init_employee_array()
 * \brief Allocate memory for a dynamic employee array.
 * \return employee_array Pointer to the new dynamic employee array.
 */
void init_employee_array(employee_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (employee *)malloc(ARRAY_BLOCK_SIZE * sizeof(employee));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_employee_array(employee_array* array)
* \brief Reset the employee array to hold nothing.
* \param array Pointer to the dynamic employee array.
*/
void reset_employee_array(employee_array * array)
{
	(*array).size = 0;
}

/** \fn void free_employee_array(employee_array * array)
* \brief Free the memory of a dynamic employee array.
* \param array Pointer to the dynamic employee array.
*/
void free_employee_array(employee_array * array)
{
	free((*array).array);
}

void copy_employee_array(employee_array * from, employee_array * to)
{
	int i;
	
	//to = init_employee_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_employee(to, (*from).array[i].id, (*from).array[i].region_id, (*from).array[i].wage, (*from).array[i].general_skill, (*from).array[i].specific_skill);
	}
}

/** \fn void add_employee(employee_array * array, int id, int region_id, double wage, int general_skill, double specific_skill)
* \brief Add an employee to the dynamic employee array.
* \param array Pointer to the dynamic employee array.
* \param new_int The employee to add
*/
void add_employee(employee_array * array, int id, int region_id, double wage, int general_skill, double specific_skill)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (employee *)realloc((*array).array, ((*array).total_size * sizeof(employee)));
	}
	init_employee(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].wage = wage;
	(*array).array[(*array).size].general_skill = general_skill;
	(*array).array[(*array).size].specific_skill = specific_skill;

	(*array).size++;
}

/** \fn void remove_employee(employee_array * array, int index)
 * \brief Remove an employee from a dynamic employee array.
 * \param array Pointer to the dynamic employee array.
 * \param index The index of the employee to remove.
 */
void remove_employee(employee_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_employee(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_employee(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the vacancy datatype */
/** \fn vacancy_array * init_vacancy_array()
 * \brief Allocate memory for a dynamic vacancy array.
 * \return vacancy_array Pointer to the new dynamic vacancy array.
 */
void init_vacancy_array(vacancy_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (vacancy *)malloc(ARRAY_BLOCK_SIZE * sizeof(vacancy));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_vacancy_array(vacancy_array* array)
* \brief Reset the vacancy array to hold nothing.
* \param array Pointer to the dynamic vacancy array.
*/
void reset_vacancy_array(vacancy_array * array)
{
	(*array).size = 0;
}

/** \fn void free_vacancy_array(vacancy_array * array)
* \brief Free the memory of a dynamic vacancy array.
* \param array Pointer to the dynamic vacancy array.
*/
void free_vacancy_array(vacancy_array * array)
{
	free((*array).array);
}

void copy_vacancy_array(vacancy_array * from, vacancy_array * to)
{
	int i;
	
	//to = init_vacancy_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_vacancy(to, (*from).array[i].firm_id, (*from).array[i].region_id, (*from).array[i].wage_offer);
	}
}

/** \fn void add_vacancy(vacancy_array * array, int firm_id, int region_id, double wage_offer)
* \brief Add an vacancy to the dynamic vacancy array.
* \param array Pointer to the dynamic vacancy array.
* \param new_int The vacancy to add
*/
void add_vacancy(vacancy_array * array, int firm_id, int region_id, double wage_offer)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (vacancy *)realloc((*array).array, ((*array).total_size * sizeof(vacancy)));
	}
	init_vacancy(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].wage_offer = wage_offer;

	(*array).size++;
}

/** \fn void remove_vacancy(vacancy_array * array, int index)
 * \brief Remove an vacancy from a dynamic vacancy array.
 * \param array Pointer to the dynamic vacancy array.
 * \param index The index of the vacancy to remove.
 */
void remove_vacancy(vacancy_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_vacancy(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_vacancy(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the job_application datatype */
/** \fn job_application_array * init_job_application_array()
 * \brief Allocate memory for a dynamic job_application array.
 * \return job_application_array Pointer to the new dynamic job_application array.
 */
void init_job_application_array(job_application_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (job_application *)malloc(ARRAY_BLOCK_SIZE * sizeof(job_application));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_job_application_array(job_application_array* array)
* \brief Reset the job_application array to hold nothing.
* \param array Pointer to the dynamic job_application array.
*/
void reset_job_application_array(job_application_array * array)
{
	(*array).size = 0;
}

/** \fn void free_job_application_array(job_application_array * array)
* \brief Free the memory of a dynamic job_application array.
* \param array Pointer to the dynamic job_application array.
*/
void free_job_application_array(job_application_array * array)
{
	free((*array).array);
}

void copy_job_application_array(job_application_array * from, job_application_array * to)
{
	int i;
	
	//to = init_job_application_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_job_application(to, (*from).array[i].worker_id, (*from).array[i].region_id, (*from).array[i].general_skill, (*from).array[i].specific_skill);
	}
}

/** \fn void add_job_application(job_application_array * array, int worker_id, int region_id, int general_skill, double specific_skill)
* \brief Add an job_application to the dynamic job_application array.
* \param array Pointer to the dynamic job_application array.
* \param new_int The job_application to add
*/
void add_job_application(job_application_array * array, int worker_id, int region_id, int general_skill, double specific_skill)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (job_application *)realloc((*array).array, ((*array).total_size * sizeof(job_application)));
	}
	init_job_application(&(*array).array[(*array).size]);
	(*array).array[(*array).size].worker_id = worker_id;
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].general_skill = general_skill;
	(*array).array[(*array).size].specific_skill = specific_skill;

	(*array).size++;
}

/** \fn void remove_job_application(job_application_array * array, int index)
 * \brief Remove an job_application from a dynamic job_application array.
 * \param array Pointer to the dynamic job_application array.
 * \param index The index of the job_application to remove.
 */
void remove_job_application(job_application_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_job_application(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_job_application(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the job_offer datatype */
/** \fn job_offer_array * init_job_offer_array()
 * \brief Allocate memory for a dynamic job_offer array.
 * \return job_offer_array Pointer to the new dynamic job_offer array.
 */
void init_job_offer_array(job_offer_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (job_offer *)malloc(ARRAY_BLOCK_SIZE * sizeof(job_offer));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_job_offer_array(job_offer_array* array)
* \brief Reset the job_offer array to hold nothing.
* \param array Pointer to the dynamic job_offer array.
*/
void reset_job_offer_array(job_offer_array * array)
{
	(*array).size = 0;
}

/** \fn void free_job_offer_array(job_offer_array * array)
* \brief Free the memory of a dynamic job_offer array.
* \param array Pointer to the dynamic job_offer array.
*/
void free_job_offer_array(job_offer_array * array)
{
	free((*array).array);
}

void copy_job_offer_array(job_offer_array * from, job_offer_array * to)
{
	int i;
	
	//to = init_job_offer_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_job_offer(to, (*from).array[i].firm_id, (*from).array[i].region_id, (*from).array[i].wage_offer);
	}
}

/** \fn void add_job_offer(job_offer_array * array, int firm_id, int region_id, double wage_offer)
* \brief Add an job_offer to the dynamic job_offer array.
* \param array Pointer to the dynamic job_offer array.
* \param new_int The job_offer to add
*/
void add_job_offer(job_offer_array * array, int firm_id, int region_id, double wage_offer)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (job_offer *)realloc((*array).array, ((*array).total_size * sizeof(job_offer)));
	}
	init_job_offer(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].wage_offer = wage_offer;

	(*array).size++;
}

/** \fn void remove_job_offer(job_offer_array * array, int index)
 * \brief Remove an job_offer from a dynamic job_offer array.
 * \param array Pointer to the dynamic job_offer array.
 * \param index The index of the job_offer to remove.
 */
void remove_job_offer(job_offer_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_job_offer(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_job_offer(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the consumption_goods_offer datatype */
/** \fn consumption_goods_offer_array * init_consumption_goods_offer_array()
 * \brief Allocate memory for a dynamic consumption_goods_offer array.
 * \return consumption_goods_offer_array Pointer to the new dynamic consumption_goods_offer array.
 */
void init_consumption_goods_offer_array(consumption_goods_offer_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (consumption_goods_offer *)malloc(ARRAY_BLOCK_SIZE * sizeof(consumption_goods_offer));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_consumption_goods_offer_array(consumption_goods_offer_array* array)
* \brief Reset the consumption_goods_offer array to hold nothing.
* \param array Pointer to the dynamic consumption_goods_offer array.
*/
void reset_consumption_goods_offer_array(consumption_goods_offer_array * array)
{
	(*array).size = 0;
}

/** \fn void free_consumption_goods_offer_array(consumption_goods_offer_array * array)
* \brief Free the memory of a dynamic consumption_goods_offer array.
* \param array Pointer to the dynamic consumption_goods_offer array.
*/
void free_consumption_goods_offer_array(consumption_goods_offer_array * array)
{
	free((*array).array);
}

void copy_consumption_goods_offer_array(consumption_goods_offer_array * from, consumption_goods_offer_array * to)
{
	int i;
	
	//to = init_consumption_goods_offer_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_consumption_goods_offer(to, (*from).array[i].id, (*from).array[i].quality, (*from).array[i].price);
	}
}

/** \fn void add_consumption_goods_offer(consumption_goods_offer_array * array, int id, double quality, double price)
* \brief Add an consumption_goods_offer to the dynamic consumption_goods_offer array.
* \param array Pointer to the dynamic consumption_goods_offer array.
* \param new_int The consumption_goods_offer to add
*/
void add_consumption_goods_offer(consumption_goods_offer_array * array, int id, double quality, double price)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (consumption_goods_offer *)realloc((*array).array, ((*array).total_size * sizeof(consumption_goods_offer)));
	}
	init_consumption_goods_offer(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].quality = quality;
	(*array).array[(*array).size].price = price;

	(*array).size++;
}

/** \fn void remove_consumption_goods_offer(consumption_goods_offer_array * array, int index)
 * \brief Remove an consumption_goods_offer from a dynamic consumption_goods_offer array.
 * \param array Pointer to the dynamic consumption_goods_offer array.
 * \param index The index of the consumption_goods_offer to remove.
 */
void remove_consumption_goods_offer(consumption_goods_offer_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_consumption_goods_offer(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_consumption_goods_offer(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the consumption_request datatype */
/** \fn consumption_request_array * init_consumption_request_array()
 * \brief Allocate memory for a dynamic consumption_request array.
 * \return consumption_request_array Pointer to the new dynamic consumption_request array.
 */
void init_consumption_request_array(consumption_request_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (consumption_request *)malloc(ARRAY_BLOCK_SIZE * sizeof(consumption_request));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_consumption_request_array(consumption_request_array* array)
* \brief Reset the consumption_request array to hold nothing.
* \param array Pointer to the dynamic consumption_request array.
*/
void reset_consumption_request_array(consumption_request_array * array)
{
	(*array).size = 0;
}

/** \fn void free_consumption_request_array(consumption_request_array * array)
* \brief Free the memory of a dynamic consumption_request array.
* \param array Pointer to the dynamic consumption_request array.
*/
void free_consumption_request_array(consumption_request_array * array)
{
	free((*array).array);
}

void copy_consumption_request_array(consumption_request_array * from, consumption_request_array * to)
{
	int i;
	
	//to = init_consumption_request_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_consumption_request(to, (*from).array[i].worker_id, (*from).array[i].firm_id, (*from).array[i].quantity);
	}
}

/** \fn void add_consumption_request(consumption_request_array * array, int worker_id, int firm_id, double quantity)
* \brief Add an consumption_request to the dynamic consumption_request array.
* \param array Pointer to the dynamic consumption_request array.
* \param new_int The consumption_request to add
*/
void add_consumption_request(consumption_request_array * array, int worker_id, int firm_id, double quantity)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (consumption_request *)realloc((*array).array, ((*array).total_size * sizeof(consumption_request)));
	}
	init_consumption_request(&(*array).array[(*array).size]);
	(*array).array[(*array).size].worker_id = worker_id;
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].quantity = quantity;

	(*array).size++;
}

/** \fn void remove_consumption_request(consumption_request_array * array, int index)
 * \brief Remove an consumption_request from a dynamic consumption_request array.
 * \param array Pointer to the dynamic consumption_request array.
 * \param index The index of the consumption_request to remove.
 */
void remove_consumption_request(consumption_request_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_consumption_request(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_consumption_request(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the mall_info datatype */
/** \fn mall_info_array * init_mall_info_array()
 * \brief Allocate memory for a dynamic mall_info array.
 * \return mall_info_array Pointer to the new dynamic mall_info array.
 */
void init_mall_info_array(mall_info_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (mall_info *)malloc(ARRAY_BLOCK_SIZE * sizeof(mall_info));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_mall_info_array(mall_info_array* array)
* \brief Reset the mall_info array to hold nothing.
* \param array Pointer to the dynamic mall_info array.
*/
void reset_mall_info_array(mall_info_array * array)
{
	(*array).size = 0;
}

/** \fn void free_mall_info_array(mall_info_array * array)
* \brief Free the memory of a dynamic mall_info array.
* \param array Pointer to the dynamic mall_info array.
*/
void free_mall_info_array(mall_info_array * array)
{
	free((*array).array);
}

void copy_mall_info_array(mall_info_array * from, mall_info_array * to)
{
	int i;
	
	//to = init_mall_info_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_mall_info(to, (*from).array[i].mall_id, (*from).array[i].critical_stock, (*from).array[i].current_stock);
	}
}

/** \fn void add_mall_info(mall_info_array * array, int mall_id, double critical_stock, double current_stock)
* \brief Add an mall_info to the dynamic mall_info array.
* \param array Pointer to the dynamic mall_info array.
* \param new_int The mall_info to add
*/
void add_mall_info(mall_info_array * array, int mall_id, double critical_stock, double current_stock)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (mall_info *)realloc((*array).array, ((*array).total_size * sizeof(mall_info)));
	}
	init_mall_info(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].critical_stock = critical_stock;
	(*array).array[(*array).size].current_stock = current_stock;

	(*array).size++;
}

/** \fn void remove_mall_info(mall_info_array * array, int index)
 * \brief Remove an mall_info from a dynamic mall_info array.
 * \param array Pointer to the dynamic mall_info array.
 * \param index The index of the mall_info to remove.
 */
void remove_mall_info(mall_info_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_mall_info(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_mall_info(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the mall_quality_price_info datatype */
/** \fn mall_quality_price_info_array * init_mall_quality_price_info_array()
 * \brief Allocate memory for a dynamic mall_quality_price_info array.
 * \return mall_quality_price_info_array Pointer to the new dynamic mall_quality_price_info array.
 */
void init_mall_quality_price_info_array(mall_quality_price_info_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (mall_quality_price_info *)malloc(ARRAY_BLOCK_SIZE * sizeof(mall_quality_price_info));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_mall_quality_price_info_array(mall_quality_price_info_array* array)
* \brief Reset the mall_quality_price_info array to hold nothing.
* \param array Pointer to the dynamic mall_quality_price_info array.
*/
void reset_mall_quality_price_info_array(mall_quality_price_info_array * array)
{
	(*array).size = 0;
}

/** \fn void free_mall_quality_price_info_array(mall_quality_price_info_array * array)
* \brief Free the memory of a dynamic mall_quality_price_info array.
* \param array Pointer to the dynamic mall_quality_price_info array.
*/
void free_mall_quality_price_info_array(mall_quality_price_info_array * array)
{
	free((*array).array);
}

void copy_mall_quality_price_info_array(mall_quality_price_info_array * from, mall_quality_price_info_array * to)
{
	int i;
	
	//to = init_mall_quality_price_info_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_mall_quality_price_info(to, (*from).array[i].mall_id, (*from).array[i].firm_id, (*from).array[i].mall_region_id, (*from).array[i].quality, (*from).array[i].price, (*from).array[i].available);
	}
}

/** \fn void add_mall_quality_price_info(mall_quality_price_info_array * array, int mall_id, int firm_id, int mall_region_id, double quality, double price, int available)
* \brief Add an mall_quality_price_info to the dynamic mall_quality_price_info array.
* \param array Pointer to the dynamic mall_quality_price_info array.
* \param new_int The mall_quality_price_info to add
*/
void add_mall_quality_price_info(mall_quality_price_info_array * array, int mall_id, int firm_id, int mall_region_id, double quality, double price, int available)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (mall_quality_price_info *)realloc((*array).array, ((*array).total_size * sizeof(mall_quality_price_info)));
	}
	init_mall_quality_price_info(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].mall_region_id = mall_region_id;
	(*array).array[(*array).size].quality = quality;
	(*array).array[(*array).size].price = price;
	(*array).array[(*array).size].available = available;

	(*array).size++;
}

/** \fn void remove_mall_quality_price_info(mall_quality_price_info_array * array, int index)
 * \brief Remove an mall_quality_price_info from a dynamic mall_quality_price_info array.
 * \param array Pointer to the dynamic mall_quality_price_info array.
 * \param index The index of the mall_quality_price_info to remove.
 */
void remove_mall_quality_price_info(mall_quality_price_info_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_mall_quality_price_info(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_mall_quality_price_info(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the mall_stock datatype */
/** \fn mall_stock_array * init_mall_stock_array()
 * \brief Allocate memory for a dynamic mall_stock array.
 * \return mall_stock_array Pointer to the new dynamic mall_stock array.
 */
void init_mall_stock_array(mall_stock_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (mall_stock *)malloc(ARRAY_BLOCK_SIZE * sizeof(mall_stock));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_mall_stock_array(mall_stock_array* array)
* \brief Reset the mall_stock array to hold nothing.
* \param array Pointer to the dynamic mall_stock array.
*/
void reset_mall_stock_array(mall_stock_array * array)
{
	(*array).size = 0;
}

/** \fn void free_mall_stock_array(mall_stock_array * array)
* \brief Free the memory of a dynamic mall_stock array.
* \param array Pointer to the dynamic mall_stock array.
*/
void free_mall_stock_array(mall_stock_array * array)
{
	free((*array).array);
}

void copy_mall_stock_array(mall_stock_array * from, mall_stock_array * to)
{
	int i;
	
	//to = init_mall_stock_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_mall_stock(to, (*from).array[i].firm_id, (*from).array[i].stock, (*from).array[i].price, (*from).array[i].quality);
	}
}

/** \fn void add_mall_stock(mall_stock_array * array, int firm_id, double stock, double price, double quality)
* \brief Add an mall_stock to the dynamic mall_stock array.
* \param array Pointer to the dynamic mall_stock array.
* \param new_int The mall_stock to add
*/
void add_mall_stock(mall_stock_array * array, int firm_id, double stock, double price, double quality)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (mall_stock *)realloc((*array).array, ((*array).total_size * sizeof(mall_stock)));
	}
	init_mall_stock(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].stock = stock;
	(*array).array[(*array).size].price = price;
	(*array).array[(*array).size].quality = quality;

	(*array).size++;
}

/** \fn void remove_mall_stock(mall_stock_array * array, int index)
 * \brief Remove an mall_stock from a dynamic mall_stock array.
 * \param array Pointer to the dynamic mall_stock array.
 * \param index The index of the mall_stock to remove.
 */
void remove_mall_stock(mall_stock_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_mall_stock(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_mall_stock(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the delivery_volume_per_mall datatype */
/** \fn delivery_volume_per_mall_array * init_delivery_volume_per_mall_array()
 * \brief Allocate memory for a dynamic delivery_volume_per_mall array.
 * \return delivery_volume_per_mall_array Pointer to the new dynamic delivery_volume_per_mall array.
 */
void init_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (delivery_volume_per_mall *)malloc(ARRAY_BLOCK_SIZE * sizeof(delivery_volume_per_mall));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_delivery_volume_per_mall_array(delivery_volume_per_mall_array* array)
* \brief Reset the delivery_volume_per_mall array to hold nothing.
* \param array Pointer to the dynamic delivery_volume_per_mall array.
*/
void reset_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array)
{
	(*array).size = 0;
}

/** \fn void free_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array)
* \brief Free the memory of a dynamic delivery_volume_per_mall array.
* \param array Pointer to the dynamic delivery_volume_per_mall array.
*/
void free_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array)
{
	free((*array).array);
}

void copy_delivery_volume_per_mall_array(delivery_volume_per_mall_array * from, delivery_volume_per_mall_array * to)
{
	int i;
	
	//to = init_delivery_volume_per_mall_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_delivery_volume_per_mall(to, (*from).array[i].mall_id, (*from).array[i].quantity, (*from).array[i].price, (*from).array[i].quality);
	}
}

/** \fn void add_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int mall_id, double quantity, double price, double quality)
* \brief Add an delivery_volume_per_mall to the dynamic delivery_volume_per_mall array.
* \param array Pointer to the dynamic delivery_volume_per_mall array.
* \param new_int The delivery_volume_per_mall to add
*/
void add_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int mall_id, double quantity, double price, double quality)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (delivery_volume_per_mall *)realloc((*array).array, ((*array).total_size * sizeof(delivery_volume_per_mall)));
	}
	init_delivery_volume_per_mall(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].quantity = quantity;
	(*array).array[(*array).size].price = price;
	(*array).array[(*array).size].quality = quality;

	(*array).size++;
}

/** \fn void remove_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int index)
 * \brief Remove an delivery_volume_per_mall from a dynamic delivery_volume_per_mall array.
 * \param array Pointer to the dynamic delivery_volume_per_mall array.
 * \param index The index of the delivery_volume_per_mall to remove.
 */
void remove_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_delivery_volume_per_mall(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_delivery_volume_per_mall(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the logit_firm_id datatype */
/** \fn logit_firm_id_array * init_logit_firm_id_array()
 * \brief Allocate memory for a dynamic logit_firm_id array.
 * \return logit_firm_id_array Pointer to the new dynamic logit_firm_id array.
 */
void init_logit_firm_id_array(logit_firm_id_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (logit_firm_id *)malloc(ARRAY_BLOCK_SIZE * sizeof(logit_firm_id));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_logit_firm_id_array(logit_firm_id_array* array)
* \brief Reset the logit_firm_id array to hold nothing.
* \param array Pointer to the dynamic logit_firm_id array.
*/
void reset_logit_firm_id_array(logit_firm_id_array * array)
{
	(*array).size = 0;
}

/** \fn void free_logit_firm_id_array(logit_firm_id_array * array)
* \brief Free the memory of a dynamic logit_firm_id array.
* \param array Pointer to the dynamic logit_firm_id array.
*/
void free_logit_firm_id_array(logit_firm_id_array * array)
{
	free((*array).array);
}

void copy_logit_firm_id_array(logit_firm_id_array * from, logit_firm_id_array * to)
{
	int i;
	
	//to = init_logit_firm_id_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_logit_firm_id(to, (*from).array[i].logit, (*from).array[i].firm_id);
	}
}

/** \fn void add_logit_firm_id(logit_firm_id_array * array, double logit, int firm_id)
* \brief Add an logit_firm_id to the dynamic logit_firm_id array.
* \param array Pointer to the dynamic logit_firm_id array.
* \param new_int The logit_firm_id to add
*/
void add_logit_firm_id(logit_firm_id_array * array, double logit, int firm_id)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (logit_firm_id *)realloc((*array).array, ((*array).total_size * sizeof(logit_firm_id)));
	}
	init_logit_firm_id(&(*array).array[(*array).size]);
	(*array).array[(*array).size].logit = logit;
	(*array).array[(*array).size].firm_id = firm_id;

	(*array).size++;
}

/** \fn void remove_logit_firm_id(logit_firm_id_array * array, int index)
 * \brief Remove an logit_firm_id from a dynamic logit_firm_id array.
 * \param array Pointer to the dynamic logit_firm_id array.
 * \param index The index of the logit_firm_id to remove.
 */
void remove_logit_firm_id(logit_firm_id_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_logit_firm_id(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_logit_firm_id(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the sales_in_mall datatype */
/** \fn sales_in_mall_array * init_sales_in_mall_array()
 * \brief Allocate memory for a dynamic sales_in_mall array.
 * \return sales_in_mall_array Pointer to the new dynamic sales_in_mall array.
 */
void init_sales_in_mall_array(sales_in_mall_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (sales_in_mall *)malloc(ARRAY_BLOCK_SIZE * sizeof(sales_in_mall));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_sales_in_mall_array(sales_in_mall_array* array)
* \brief Reset the sales_in_mall array to hold nothing.
* \param array Pointer to the dynamic sales_in_mall array.
*/
void reset_sales_in_mall_array(sales_in_mall_array * array)
{
	(*array).size = 0;
}

/** \fn void free_sales_in_mall_array(sales_in_mall_array * array)
* \brief Free the memory of a dynamic sales_in_mall array.
* \param array Pointer to the dynamic sales_in_mall array.
*/
void free_sales_in_mall_array(sales_in_mall_array * array)
{
	free((*array).array);
}

void copy_sales_in_mall_array(sales_in_mall_array * from, sales_in_mall_array * to)
{
	int i;
	
	//to = init_sales_in_mall_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_sales_in_mall(to, (*from).array[i].firm_id, (*from).array[i].sales);
	}
}

/** \fn void add_sales_in_mall(sales_in_mall_array * array, int firm_id, double sales)
* \brief Add an sales_in_mall to the dynamic sales_in_mall array.
* \param array Pointer to the dynamic sales_in_mall array.
* \param new_int The sales_in_mall to add
*/
void add_sales_in_mall(sales_in_mall_array * array, int firm_id, double sales)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (sales_in_mall *)realloc((*array).array, ((*array).total_size * sizeof(sales_in_mall)));
	}
	init_sales_in_mall(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].sales = sales;

	(*array).size++;
}

/** \fn void remove_sales_in_mall(sales_in_mall_array * array, int index)
 * \brief Remove an sales_in_mall from a dynamic sales_in_mall array.
 * \param array Pointer to the dynamic sales_in_mall array.
 * \param index The index of the sales_in_mall to remove.
 */
void remove_sales_in_mall(sales_in_mall_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_sales_in_mall(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_sales_in_mall(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the ordered_quantity datatype */
/** \fn ordered_quantity_array * init_ordered_quantity_array()
 * \brief Allocate memory for a dynamic ordered_quantity array.
 * \return ordered_quantity_array Pointer to the new dynamic ordered_quantity array.
 */
void init_ordered_quantity_array(ordered_quantity_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (ordered_quantity *)malloc(ARRAY_BLOCK_SIZE * sizeof(ordered_quantity));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_ordered_quantity_array(ordered_quantity_array* array)
* \brief Reset the ordered_quantity array to hold nothing.
* \param array Pointer to the dynamic ordered_quantity array.
*/
void reset_ordered_quantity_array(ordered_quantity_array * array)
{
	(*array).size = 0;
}

/** \fn void free_ordered_quantity_array(ordered_quantity_array * array)
* \brief Free the memory of a dynamic ordered_quantity array.
* \param array Pointer to the dynamic ordered_quantity array.
*/
void free_ordered_quantity_array(ordered_quantity_array * array)
{
	free((*array).array);
}

void copy_ordered_quantity_array(ordered_quantity_array * from, ordered_quantity_array * to)
{
	int i;
	
	//to = init_ordered_quantity_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_ordered_quantity(to, (*from).array[i].firm_id, (*from).array[i].quantity, (*from).array[i].price);
	}
}

/** \fn void add_ordered_quantity(ordered_quantity_array * array, int firm_id, double quantity, double price)
* \brief Add an ordered_quantity to the dynamic ordered_quantity array.
* \param array Pointer to the dynamic ordered_quantity array.
* \param new_int The ordered_quantity to add
*/
void add_ordered_quantity(ordered_quantity_array * array, int firm_id, double quantity, double price)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (ordered_quantity *)realloc((*array).array, ((*array).total_size * sizeof(ordered_quantity)));
	}
	init_ordered_quantity(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].quantity = quantity;
	(*array).array[(*array).size].price = price;

	(*array).size++;
}

/** \fn void remove_ordered_quantity(ordered_quantity_array * array, int index)
 * \brief Remove an ordered_quantity from a dynamic ordered_quantity array.
 * \param array Pointer to the dynamic ordered_quantity array.
 * \param index The index of the ordered_quantity to remove.
 */
void remove_ordered_quantity(ordered_quantity_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_ordered_quantity(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_ordered_quantity(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the received_quantities datatype */
/** \fn received_quantities_array * init_received_quantities_array()
 * \brief Allocate memory for a dynamic received_quantities array.
 * \return received_quantities_array Pointer to the new dynamic received_quantities array.
 */
void init_received_quantities_array(received_quantities_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (received_quantities *)malloc(ARRAY_BLOCK_SIZE * sizeof(received_quantities));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_received_quantities_array(received_quantities_array* array)
* \brief Reset the received_quantities array to hold nothing.
* \param array Pointer to the dynamic received_quantities array.
*/
void reset_received_quantities_array(received_quantities_array * array)
{
	(*array).size = 0;
}

/** \fn void free_received_quantities_array(received_quantities_array * array)
* \brief Free the memory of a dynamic received_quantities array.
* \param array Pointer to the dynamic received_quantities array.
*/
void free_received_quantities_array(received_quantities_array * array)
{
	free((*array).array);
}

void copy_received_quantities_array(received_quantities_array * from, received_quantities_array * to)
{
	int i;
	
	//to = init_received_quantities_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_received_quantities(to, (*from).array[i].firm_id, (*from).array[i].quantity);
	}
}

/** \fn void add_received_quantities(received_quantities_array * array, int firm_id, double quantity)
* \brief Add an received_quantities to the dynamic received_quantities array.
* \param array Pointer to the dynamic received_quantities array.
* \param new_int The received_quantities to add
*/
void add_received_quantities(received_quantities_array * array, int firm_id, double quantity)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (received_quantities *)realloc((*array).array, ((*array).total_size * sizeof(received_quantities)));
	}
	init_received_quantities(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].quantity = quantity;

	(*array).size++;
}

/** \fn void remove_received_quantities(received_quantities_array * array, int index)
 * \brief Remove an received_quantities from a dynamic received_quantities array.
 * \param array Pointer to the dynamic received_quantities array.
 * \param index The index of the received_quantities to remove.
 */
void remove_received_quantities(received_quantities_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_received_quantities(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_received_quantities(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the sold_quantities_per_mall datatype */
/** \fn sold_quantities_per_mall_array * init_sold_quantities_per_mall_array()
 * \brief Allocate memory for a dynamic sold_quantities_per_mall array.
 * \return sold_quantities_per_mall_array Pointer to the new dynamic sold_quantities_per_mall array.
 */
void init_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (sold_quantities_per_mall *)malloc(ARRAY_BLOCK_SIZE * sizeof(sold_quantities_per_mall));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_sold_quantities_per_mall_array(sold_quantities_per_mall_array* array)
* \brief Reset the sold_quantities_per_mall array to hold nothing.
* \param array Pointer to the dynamic sold_quantities_per_mall array.
*/
void reset_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array)
{
	(*array).size = 0;
}

/** \fn void free_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array)
* \brief Free the memory of a dynamic sold_quantities_per_mall array.
* \param array Pointer to the dynamic sold_quantities_per_mall array.
*/
void free_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array)
{
	free((*array).array);
}

void copy_sold_quantities_per_mall_array(sold_quantities_per_mall_array * from, sold_quantities_per_mall_array * to)
{
	int i;
	
	//to = init_sold_quantities_per_mall_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_sold_quantities_per_mall(to, (*from).array[i].mall_id, (*from).array[i].sold_quantity, (*from).array[i].stock_empty, (*from).array[i].estimated_demand);
	}
}

/** \fn void add_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int mall_id, double sold_quantity, int stock_empty, double estimated_demand)
* \brief Add an sold_quantities_per_mall to the dynamic sold_quantities_per_mall array.
* \param array Pointer to the dynamic sold_quantities_per_mall array.
* \param new_int The sold_quantities_per_mall to add
*/
void add_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int mall_id, double sold_quantity, int stock_empty, double estimated_demand)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (sold_quantities_per_mall *)realloc((*array).array, ((*array).total_size * sizeof(sold_quantities_per_mall)));
	}
	init_sold_quantities_per_mall(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].sold_quantity = sold_quantity;
	(*array).array[(*array).size].stock_empty = stock_empty;
	(*array).array[(*array).size].estimated_demand = estimated_demand;

	(*array).size++;
}

/** \fn void remove_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int index)
 * \brief Remove an sold_quantities_per_mall from a dynamic sold_quantities_per_mall array.
 * \param array Pointer to the dynamic sold_quantities_per_mall array.
 * \param index The index of the sold_quantities_per_mall to remove.
 */
void remove_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_sold_quantities_per_mall(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_sold_quantities_per_mall(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the sales_statistics datatype */
/** \fn sales_statistics_array * init_sales_statistics_array()
 * \brief Allocate memory for a dynamic sales_statistics array.
 * \return sales_statistics_array Pointer to the new dynamic sales_statistics array.
 */
void init_sales_statistics_array(sales_statistics_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (sales_statistics *)malloc(ARRAY_BLOCK_SIZE * sizeof(sales_statistics));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_sales_statistics_array(sales_statistics_array* array)
* \brief Reset the sales_statistics array to hold nothing.
* \param array Pointer to the dynamic sales_statistics array.
*/
void reset_sales_statistics_array(sales_statistics_array * array)
{
	(*array).size = 0;
}

/** \fn void free_sales_statistics_array(sales_statistics_array * array)
* \brief Free the memory of a dynamic sales_statistics array.
* \param array Pointer to the dynamic sales_statistics array.
*/
void free_sales_statistics_array(sales_statistics_array * array)
{
	free((*array).array);
}

void copy_sales_statistics_array(sales_statistics_array * from, sales_statistics_array * to)
{
	int i;
	
	//to = init_sales_statistics_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_sales_statistics(to, (*from).array[i].mall_id, (*from).array[i].period, (*from).array[i].sales);
	}
}

/** \fn void add_sales_statistics(sales_statistics_array * array, int mall_id, int period, double sales)
* \brief Add an sales_statistics to the dynamic sales_statistics array.
* \param array Pointer to the dynamic sales_statistics array.
* \param new_int The sales_statistics to add
*/
void add_sales_statistics(sales_statistics_array * array, int mall_id, int period, double sales)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (sales_statistics *)realloc((*array).array, ((*array).total_size * sizeof(sales_statistics)));
	}
	init_sales_statistics(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].period = period;
	(*array).array[(*array).size].sales = sales;

	(*array).size++;
}

/** \fn void remove_sales_statistics(sales_statistics_array * array, int index)
 * \brief Remove an sales_statistics from a dynamic sales_statistics array.
 * \param array Pointer to the dynamic sales_statistics array.
 * \param index The index of the sales_statistics to remove.
 */
void remove_sales_statistics(sales_statistics_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_sales_statistics(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_sales_statistics(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the debt_item datatype */
/** \fn debt_item_array * init_debt_item_array()
 * \brief Allocate memory for a dynamic debt_item array.
 * \return debt_item_array Pointer to the new dynamic debt_item array.
 */
void init_debt_item_array(debt_item_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (debt_item *)malloc(ARRAY_BLOCK_SIZE * sizeof(debt_item));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_debt_item_array(debt_item_array* array)
* \brief Reset the debt_item array to hold nothing.
* \param array Pointer to the dynamic debt_item array.
*/
void reset_debt_item_array(debt_item_array * array)
{
	(*array).size = 0;
}

/** \fn void free_debt_item_array(debt_item_array * array)
* \brief Free the memory of a dynamic debt_item array.
* \param array Pointer to the dynamic debt_item array.
*/
void free_debt_item_array(debt_item_array * array)
{
	free((*array).array);
}

void copy_debt_item_array(debt_item_array * from, debt_item_array * to)
{
	int i;
	
	//to = init_debt_item_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_debt_item(to, (*from).array[i].bank_id, (*from).array[i].loan_value, (*from).array[i].interest_rate, (*from).array[i].interest_payment, (*from).array[i].debt_installment_payment, (*from).array[i].nr_periods_before_maturity);
	}
}

/** \fn void add_debt_item(debt_item_array * array, int bank_id, double loan_value, double interest_rate, double interest_payment, double debt_installment_payment, int nr_periods_before_maturity)
* \brief Add an debt_item to the dynamic debt_item array.
* \param array Pointer to the dynamic debt_item array.
* \param new_int The debt_item to add
*/
void add_debt_item(debt_item_array * array, int bank_id, double loan_value, double interest_rate, double interest_payment, double debt_installment_payment, int nr_periods_before_maturity)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (debt_item *)realloc((*array).array, ((*array).total_size * sizeof(debt_item)));
	}
	init_debt_item(&(*array).array[(*array).size]);
	(*array).array[(*array).size].bank_id = bank_id;
	(*array).array[(*array).size].loan_value = loan_value;
	(*array).array[(*array).size].interest_rate = interest_rate;
	(*array).array[(*array).size].interest_payment = interest_payment;
	(*array).array[(*array).size].debt_installment_payment = debt_installment_payment;
	(*array).array[(*array).size].nr_periods_before_maturity = nr_periods_before_maturity;

	(*array).size++;
}

/** \fn void remove_debt_item(debt_item_array * array, int index)
 * \brief Remove an debt_item from a dynamic debt_item array.
 * \param array Pointer to the dynamic debt_item array.
 * \param index The index of the debt_item to remove.
 */
void remove_debt_item(debt_item_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_debt_item(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_debt_item(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the capital_stock_item datatype */
/** \fn capital_stock_item_array * init_capital_stock_item_array()
 * \brief Allocate memory for a dynamic capital_stock_item array.
 * \return capital_stock_item_array Pointer to the new dynamic capital_stock_item array.
 */
void init_capital_stock_item_array(capital_stock_item_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (capital_stock_item *)malloc(ARRAY_BLOCK_SIZE * sizeof(capital_stock_item));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_capital_stock_item_array(capital_stock_item_array* array)
* \brief Reset the capital_stock_item array to hold nothing.
* \param array Pointer to the dynamic capital_stock_item array.
*/
void reset_capital_stock_item_array(capital_stock_item_array * array)
{
	(*array).size = 0;
}

/** \fn void free_capital_stock_item_array(capital_stock_item_array * array)
* \brief Free the memory of a dynamic capital_stock_item array.
* \param array Pointer to the dynamic capital_stock_item array.
*/
void free_capital_stock_item_array(capital_stock_item_array * array)
{
	free((*array).array);
}

void copy_capital_stock_item_array(capital_stock_item_array * from, capital_stock_item_array * to)
{
	int i;
	
	//to = init_capital_stock_item_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_capital_stock_item(to, (*from).array[i].units, (*from).array[i].purchase_price, (*from).array[i].productivity, (*from).array[i].depreciation_units_per_period);
	}
}

/** \fn void add_capital_stock_item(capital_stock_item_array * array, double units, double purchase_price, double productivity, double depreciation_units_per_period)
* \brief Add an capital_stock_item to the dynamic capital_stock_item array.
* \param array Pointer to the dynamic capital_stock_item array.
* \param new_int The capital_stock_item to add
*/
void add_capital_stock_item(capital_stock_item_array * array, double units, double purchase_price, double productivity, double depreciation_units_per_period)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (capital_stock_item *)realloc((*array).array, ((*array).total_size * sizeof(capital_stock_item)));
	}
	init_capital_stock_item(&(*array).array[(*array).size]);
	(*array).array[(*array).size].units = units;
	(*array).array[(*array).size].purchase_price = purchase_price;
	(*array).array[(*array).size].productivity = productivity;
	(*array).array[(*array).size].depreciation_units_per_period = depreciation_units_per_period;

	(*array).size++;
}

/** \fn void remove_capital_stock_item(capital_stock_item_array * array, int index)
 * \brief Remove an capital_stock_item from a dynamic capital_stock_item array.
 * \param array Pointer to the dynamic capital_stock_item array.
 * \param index The index of the capital_stock_item to remove.
 */
void remove_capital_stock_item(capital_stock_item_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_capital_stock_item(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_capital_stock_item(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the household_data datatype */
/** \fn household_data_array * init_household_data_array()
 * \brief Allocate memory for a dynamic household_data array.
 * \return household_data_array Pointer to the new dynamic household_data array.
 */
void init_household_data_array(household_data_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (household_data *)malloc(ARRAY_BLOCK_SIZE * sizeof(household_data));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_household_data_array(household_data_array* array)
* \brief Reset the household_data array to hold nothing.
* \param array Pointer to the dynamic household_data array.
*/
void reset_household_data_array(household_data_array * array)
{
	(*array).size = 0;
}

/** \fn void free_household_data_array(household_data_array * array)
* \brief Free the memory of a dynamic household_data array.
* \param array Pointer to the dynamic household_data array.
*/
void free_household_data_array(household_data_array * array)
{
	free((*array).array);
}

void copy_household_data_array(household_data_array * from, household_data_array * to)
{
	int i;
	
	//to = init_household_data_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_household_data(to, (*from).array[i].region_id, (*from).array[i].no_households, (*from).array[i].no_households_skill_1, (*from).array[i].no_households_skill_2, (*from).array[i].no_households_skill_3, (*from).array[i].no_households_skill_4, (*from).array[i].no_households_skill_5, (*from).array[i].employed, (*from).array[i].employed_skill_1, (*from).array[i].employed_skill_2, (*from).array[i].employed_skill_3, (*from).array[i].employed_skill_4, (*from).array[i].employed_skill_5, (*from).array[i].unemployed, (*from).array[i].unemployment_rate, (*from).array[i].unemployment_rate_skill_1, (*from).array[i].unemployment_rate_skill_2, (*from).array[i].unemployment_rate_skill_3, (*from).array[i].unemployment_rate_skill_4, (*from).array[i].unemployment_rate_skill_5, (*from).array[i].average_wage, (*from).array[i].average_wage_skill_1, (*from).array[i].average_wage_skill_2, (*from).array[i].average_wage_skill_3, (*from).array[i].average_wage_skill_4, (*from).array[i].average_wage_skill_5, (*from).array[i].average_s_skill, (*from).array[i].average_s_skill_1, (*from).array[i].average_s_skill_2, (*from).array[i].average_s_skill_3, (*from).array[i].average_s_skill_4, (*from).array[i].average_s_skill_5);
	}
}

/** \fn void add_household_data(household_data_array * array, int region_id, int no_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5)
* \brief Add an household_data to the dynamic household_data array.
* \param array Pointer to the dynamic household_data array.
* \param new_int The household_data to add
*/
void add_household_data(household_data_array * array, int region_id, int no_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (household_data *)realloc((*array).array, ((*array).total_size * sizeof(household_data)));
	}
	init_household_data(&(*array).array[(*array).size]);
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].no_households = no_households;
	(*array).array[(*array).size].no_households_skill_1 = no_households_skill_1;
	(*array).array[(*array).size].no_households_skill_2 = no_households_skill_2;
	(*array).array[(*array).size].no_households_skill_3 = no_households_skill_3;
	(*array).array[(*array).size].no_households_skill_4 = no_households_skill_4;
	(*array).array[(*array).size].no_households_skill_5 = no_households_skill_5;
	(*array).array[(*array).size].employed = employed;
	(*array).array[(*array).size].employed_skill_1 = employed_skill_1;
	(*array).array[(*array).size].employed_skill_2 = employed_skill_2;
	(*array).array[(*array).size].employed_skill_3 = employed_skill_3;
	(*array).array[(*array).size].employed_skill_4 = employed_skill_4;
	(*array).array[(*array).size].employed_skill_5 = employed_skill_5;
	(*array).array[(*array).size].unemployed = unemployed;
	(*array).array[(*array).size].unemployment_rate = unemployment_rate;
	(*array).array[(*array).size].unemployment_rate_skill_1 = unemployment_rate_skill_1;
	(*array).array[(*array).size].unemployment_rate_skill_2 = unemployment_rate_skill_2;
	(*array).array[(*array).size].unemployment_rate_skill_3 = unemployment_rate_skill_3;
	(*array).array[(*array).size].unemployment_rate_skill_4 = unemployment_rate_skill_4;
	(*array).array[(*array).size].unemployment_rate_skill_5 = unemployment_rate_skill_5;
	(*array).array[(*array).size].average_wage = average_wage;
	(*array).array[(*array).size].average_wage_skill_1 = average_wage_skill_1;
	(*array).array[(*array).size].average_wage_skill_2 = average_wage_skill_2;
	(*array).array[(*array).size].average_wage_skill_3 = average_wage_skill_3;
	(*array).array[(*array).size].average_wage_skill_4 = average_wage_skill_4;
	(*array).array[(*array).size].average_wage_skill_5 = average_wage_skill_5;
	(*array).array[(*array).size].average_s_skill = average_s_skill;
	(*array).array[(*array).size].average_s_skill_1 = average_s_skill_1;
	(*array).array[(*array).size].average_s_skill_2 = average_s_skill_2;
	(*array).array[(*array).size].average_s_skill_3 = average_s_skill_3;
	(*array).array[(*array).size].average_s_skill_4 = average_s_skill_4;
	(*array).array[(*array).size].average_s_skill_5 = average_s_skill_5;

	(*array).size++;
}

/** \fn void remove_household_data(household_data_array * array, int index)
 * \brief Remove an household_data from a dynamic household_data array.
 * \param array Pointer to the dynamic household_data array.
 * \param index The index of the household_data to remove.
 */
void remove_household_data(household_data_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_household_data(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_household_data(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the firm_data datatype */
/** \fn firm_data_array * init_firm_data_array()
 * \brief Allocate memory for a dynamic firm_data array.
 * \return firm_data_array Pointer to the new dynamic firm_data array.
 */
void init_firm_data_array(firm_data_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (firm_data *)malloc(ARRAY_BLOCK_SIZE * sizeof(firm_data));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_firm_data_array(firm_data_array* array)
* \brief Reset the firm_data array to hold nothing.
* \param array Pointer to the dynamic firm_data array.
*/
void reset_firm_data_array(firm_data_array * array)
{
	(*array).size = 0;
}

/** \fn void free_firm_data_array(firm_data_array * array)
* \brief Free the memory of a dynamic firm_data array.
* \param array Pointer to the dynamic firm_data array.
*/
void free_firm_data_array(firm_data_array * array)
{
	free((*array).array);
}

void copy_firm_data_array(firm_data_array * from, firm_data_array * to)
{
	int i;
	
	//to = init_firm_data_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_firm_data(to, (*from).array[i].region_id, (*from).array[i].firms, (*from).array[i].vacancies, (*from).array[i].employees, (*from).array[i].employees_skill_1, (*from).array[i].employees_skill_2, (*from).array[i].employees_skill_3, (*from).array[i].employees_skill_4, (*from).array[i].employees_skill_5, (*from).array[i].average_wage, (*from).array[i].average_wage_skill_1, (*from).array[i].average_wage_skill_2, (*from).array[i].average_wage_skill_3, (*from).array[i].average_wage_skill_4, (*from).array[i].average_wage_skill_5, (*from).array[i].average_s_skill, (*from).array[i].average_s_skill_1, (*from).array[i].average_s_skill_2, (*from).array[i].average_s_skill_3, (*from).array[i].average_s_skill_4, (*from).array[i].average_s_skill_5);
	}
}

/** \fn void add_firm_data(firm_data_array * array, int region_id, int firms, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5)
* \brief Add an firm_data to the dynamic firm_data array.
* \param array Pointer to the dynamic firm_data array.
* \param new_int The firm_data to add
*/
void add_firm_data(firm_data_array * array, int region_id, int firms, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (firm_data *)realloc((*array).array, ((*array).total_size * sizeof(firm_data)));
	}
	init_firm_data(&(*array).array[(*array).size]);
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].firms = firms;
	(*array).array[(*array).size].vacancies = vacancies;
	(*array).array[(*array).size].employees = employees;
	(*array).array[(*array).size].employees_skill_1 = employees_skill_1;
	(*array).array[(*array).size].employees_skill_2 = employees_skill_2;
	(*array).array[(*array).size].employees_skill_3 = employees_skill_3;
	(*array).array[(*array).size].employees_skill_4 = employees_skill_4;
	(*array).array[(*array).size].employees_skill_5 = employees_skill_5;
	(*array).array[(*array).size].average_wage = average_wage;
	(*array).array[(*array).size].average_wage_skill_1 = average_wage_skill_1;
	(*array).array[(*array).size].average_wage_skill_2 = average_wage_skill_2;
	(*array).array[(*array).size].average_wage_skill_3 = average_wage_skill_3;
	(*array).array[(*array).size].average_wage_skill_4 = average_wage_skill_4;
	(*array).array[(*array).size].average_wage_skill_5 = average_wage_skill_5;
	(*array).array[(*array).size].average_s_skill = average_s_skill;
	(*array).array[(*array).size].average_s_skill_1 = average_s_skill_1;
	(*array).array[(*array).size].average_s_skill_2 = average_s_skill_2;
	(*array).array[(*array).size].average_s_skill_3 = average_s_skill_3;
	(*array).array[(*array).size].average_s_skill_4 = average_s_skill_4;
	(*array).array[(*array).size].average_s_skill_5 = average_s_skill_5;

	(*array).size++;
}

/** \fn void remove_firm_data(firm_data_array * array, int index)
 * \brief Remove an firm_data from a dynamic firm_data array.
 * \param array Pointer to the dynamic firm_data array.
 * \param index The index of the firm_data to remove.
 */
void remove_firm_data(firm_data_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_firm_data(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_firm_data(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}

