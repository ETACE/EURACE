/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn xmachine_message_rule_performance * add_rule_performance_message_internal()
 * \brief Add rule_performance message to the local message list.
 * \return The added message.
 */
xmachine_message_rule_performance * add_rule_performance_message_internal()
{
	xmachine_message_rule_performance * current = (xmachine_message_rule_performance *)malloc(sizeof(xmachine_message_rule_performance));
	CHECK_POINTER(current);

	current->next = *p_rule_performance_message;
	*p_rule_performance_message = current;
	
	return current;
}

/** \fn void process_rule_performance_message(xmachine_message_rule_performance * current)
 * \brief Process rule_performance message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_rule_performance_message(xmachine_message_rule_performance * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_rule_performance * temp_send_message;
	
	max_mess_dist = (double)current->range;
	x = current->x;
	y = current->y;
	z = current->z;
	
	/* Check x-axis halo region */
	if((current_node->partition_data[0] != -SPINF && x <= (current_node->partition_data[0]+max_mess_dist)) ||
	   (current_node->partition_data[1] !=  SPINF && x >= (current_node->partition_data[1]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check y-axis halo region */
	if((current_node->partition_data[2] != -SPINF && y <= (current_node->partition_data[2]+max_mess_dist)) ||
	   (current_node->partition_data[3] !=  SPINF && y >= (current_node->partition_data[3]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check z-axis halo region (if used) */
	
	
	if(in_halo_region)
	{
		node_info = *p_node_info;
		while(node_info)
		{
			if(node_info->node_id != current_node->node_id &&
			node_info->partition_data[0]-max_mess_dist < x && node_info->partition_data[1]+max_mess_dist > x &&
			node_info->partition_data[2]-max_mess_dist < y && node_info->partition_data[3]+max_mess_dist > y)
			{
				p_rule_performance_message = &node_info->rule_performance_messages;
				temp_send_message = add_rule_performance_message_internal();
				
				temp_send_message->current_rule = current->current_rule;
				temp_send_message->rule_performance = current->rule_performance;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_rule_performance_message = &current_node->rule_performance_messages;
	}
}

/** \fn void add_rule_performance_message(int current_rule, double rule_performance, double range, double x, double y, double z)
 * \brief Add rule_performance message by calling internal and processing.
 * \param current_rule Message variable.
 * \param rule_performance Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_rule_performance_message(int current_rule, double rule_performance, double range, double x, double y, double z)
{

	p_rule_performance_message = &current_node->rule_performance_messages;
	xmachine_message_rule_performance * tmp = add_rule_performance_message_internal();
	
	tmp->current_rule = current_rule;
	tmp->rule_performance = rule_performance;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_rule_performance_message(tmp);
}

xmachine_message_rule_performance * get_next_message_rule_performance_in_range(xmachine_message_rule_performance * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Clearinghouse)
	{
		x = (double)current_xmachine->xmachine_Clearinghouse->posx;
		y = (double)current_xmachine->xmachine_Clearinghouse->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAgent)
	{
		x = (double)current_xmachine->xmachine_FinancialAgent->posx;
		y = (double)current_xmachine->xmachine_FinancialAgent->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_rule_performance * get_first_rule_performance_message()
 * \brief Get the first rule_performance message in the rule_performance message list.
 * \return The first message in the list.
 */
xmachine_message_rule_performance * get_first_rule_performance_message()
{
	return get_next_message_rule_performance_in_range(*p_rule_performance_message);
}

/** \fn xmachine_message_rule_performance * get_next_rule_performance_message(xmachine_message_rule_performance * current)
 * \brief Get the next rule_performance message in the rule_performance message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_rule_performance * get_next_rule_performance_message(xmachine_message_rule_performance * current)
{
	return get_next_message_rule_performance_in_range(current->next);
}

/** \fn void freerule_performancemessages()
 * \brief Free the rule_performance message list.
 */
void freerule_performancemessages()
{
	xmachine_message_rule_performance * tmp, * head;
	head = *p_rule_performance_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_rule_performance_message = NULL;
}

/** \fn xmachine_message_new_performances * add_new_performances_message_internal()
 * \brief Add new_performances message to the local message list.
 * \return The added message.
 */
xmachine_message_new_performances * add_new_performances_message_internal()
{
	xmachine_message_new_performances * current = (xmachine_message_new_performances *)malloc(sizeof(xmachine_message_new_performances));
	CHECK_POINTER(current);

	current->next = *p_new_performances_message;
	*p_new_performances_message = current;
	
	return current;
}

/** \fn void process_new_performances_message(xmachine_message_new_performances * current)
 * \brief Process new_performances message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_new_performances_message(xmachine_message_new_performances * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_new_performances * temp_send_message;
	
	max_mess_dist = (double)current->range;
	x = current->x;
	y = current->y;
	z = current->z;
	
	/* Check x-axis halo region */
	if((current_node->partition_data[0] != -SPINF && x <= (current_node->partition_data[0]+max_mess_dist)) ||
	   (current_node->partition_data[1] !=  SPINF && x >= (current_node->partition_data[1]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check y-axis halo region */
	if((current_node->partition_data[2] != -SPINF && y <= (current_node->partition_data[2]+max_mess_dist)) ||
	   (current_node->partition_data[3] !=  SPINF && y >= (current_node->partition_data[3]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check z-axis halo region (if used) */
	
	
	if(in_halo_region)
	{
		node_info = *p_node_info;
		while(node_info)
		{
			if(node_info->node_id != current_node->node_id &&
			node_info->partition_data[0]-max_mess_dist < x && node_info->partition_data[1]+max_mess_dist > x &&
			node_info->partition_data[2]-max_mess_dist < y && node_info->partition_data[3]+max_mess_dist > y)
			{
				p_new_performances_message = &node_info->new_performances_messages;
				temp_send_message = add_new_performances_message_internal();
				
				temp_send_message->avg_performance = current->avg_performance;
				temp_send_message->rule_id = current->rule_id;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_new_performances_message = &current_node->new_performances_messages;
	}
}

/** \fn void add_new_performances_message(double avg_performance, int rule_id, double range, double x, double y, double z)
 * \brief Add new_performances message by calling internal and processing.
 * \param avg_performance Message variable.
 * \param rule_id Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_new_performances_message(double avg_performance, int rule_id, double range, double x, double y, double z)
{

	p_new_performances_message = &current_node->new_performances_messages;
	xmachine_message_new_performances * tmp = add_new_performances_message_internal();
	
	tmp->avg_performance = avg_performance;
	tmp->rule_id = rule_id;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_new_performances_message(tmp);
}

xmachine_message_new_performances * get_next_message_new_performances_in_range(xmachine_message_new_performances * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Clearinghouse)
	{
		x = (double)current_xmachine->xmachine_Clearinghouse->posx;
		y = (double)current_xmachine->xmachine_Clearinghouse->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAgent)
	{
		x = (double)current_xmachine->xmachine_FinancialAgent->posx;
		y = (double)current_xmachine->xmachine_FinancialAgent->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_new_performances * get_first_new_performances_message()
 * \brief Get the first new_performances message in the new_performances message list.
 * \return The first message in the list.
 */
xmachine_message_new_performances * get_first_new_performances_message()
{
	return get_next_message_new_performances_in_range(*p_new_performances_message);
}

/** \fn xmachine_message_new_performances * get_next_new_performances_message(xmachine_message_new_performances * current)
 * \brief Get the next new_performances message in the new_performances message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_new_performances * get_next_new_performances_message(xmachine_message_new_performances * current)
{
	return get_next_message_new_performances_in_range(current->next);
}

/** \fn void freenew_performancesmessages()
 * \brief Free the new_performances message list.
 */
void freenew_performancesmessages()
{
	xmachine_message_new_performances * tmp, * head;
	head = *p_new_performances_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_new_performances_message = NULL;
}

/** \fn xmachine_message_new_rule_details * add_new_rule_details_message_internal()
 * \brief Add new_rule_details message to the local message list.
 * \return The added message.
 */
xmachine_message_new_rule_details * add_new_rule_details_message_internal()
{
	xmachine_message_new_rule_details * current = (xmachine_message_new_rule_details *)malloc(sizeof(xmachine_message_new_rule_details));
	CHECK_POINTER(current);

	current->next = *p_new_rule_details_message;
	*p_new_rule_details_message = current;
	
	return current;
}

/** \fn void process_new_rule_details_message(xmachine_message_new_rule_details * current)
 * \brief Process new_rule_details message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_new_rule_details_message(xmachine_message_new_rule_details * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_new_rule_details * temp_send_message;
	
	max_mess_dist = (double)current->range;
	x = current->x;
	y = current->y;
	z = current->z;
	
	/* Check x-axis halo region */
	if((current_node->partition_data[0] != -SPINF && x <= (current_node->partition_data[0]+max_mess_dist)) ||
	   (current_node->partition_data[1] !=  SPINF && x >= (current_node->partition_data[1]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check y-axis halo region */
	if((current_node->partition_data[2] != -SPINF && y <= (current_node->partition_data[2]+max_mess_dist)) ||
	   (current_node->partition_data[3] !=  SPINF && y >= (current_node->partition_data[3]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check z-axis halo region (if used) */
	
	
	if(in_halo_region)
	{
		node_info = *p_node_info;
		while(node_info)
		{
			if(node_info->node_id != current_node->node_id &&
			node_info->partition_data[0]-max_mess_dist < x && node_info->partition_data[1]+max_mess_dist > x &&
			node_info->partition_data[2]-max_mess_dist < y && node_info->partition_data[3]+max_mess_dist > y)
			{
				p_new_rule_details_message = &node_info->new_rule_details_messages;
				temp_send_message = add_new_rule_details_message_internal();
				
				temp_send_message->rule_id = current->rule_id;
				temp_send_message->parameter = current->parameter;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_new_rule_details_message = &current_node->new_rule_details_messages;
	}
}

/** \fn void add_new_rule_details_message(int rule_id, double parameter, double range, double x, double y, double z)
 * \brief Add new_rule_details message by calling internal and processing.
 * \param rule_id Message variable.
 * \param parameter Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_new_rule_details_message(int rule_id, double parameter, double range, double x, double y, double z)
{

	p_new_rule_details_message = &current_node->new_rule_details_messages;
	xmachine_message_new_rule_details * tmp = add_new_rule_details_message_internal();
	
	tmp->rule_id = rule_id;
	tmp->parameter = parameter;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_new_rule_details_message(tmp);
}

xmachine_message_new_rule_details * get_next_message_new_rule_details_in_range(xmachine_message_new_rule_details * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Clearinghouse)
	{
		x = (double)current_xmachine->xmachine_Clearinghouse->posx;
		y = (double)current_xmachine->xmachine_Clearinghouse->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAgent)
	{
		x = (double)current_xmachine->xmachine_FinancialAgent->posx;
		y = (double)current_xmachine->xmachine_FinancialAgent->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_new_rule_details * get_first_new_rule_details_message()
 * \brief Get the first new_rule_details message in the new_rule_details message list.
 * \return The first message in the list.
 */
xmachine_message_new_rule_details * get_first_new_rule_details_message()
{
	return get_next_message_new_rule_details_in_range(*p_new_rule_details_message);
}

/** \fn xmachine_message_new_rule_details * get_next_new_rule_details_message(xmachine_message_new_rule_details * current)
 * \brief Get the next new_rule_details message in the new_rule_details message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_new_rule_details * get_next_new_rule_details_message(xmachine_message_new_rule_details * current)
{
	return get_next_message_new_rule_details_in_range(current->next);
}

/** \fn void freenew_rule_detailsmessages()
 * \brief Free the new_rule_details message list.
 */
void freenew_rule_detailsmessages()
{
	xmachine_message_new_rule_details * tmp, * head;
	head = *p_new_rule_details_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_new_rule_details_message = NULL;
}

/** \fn xmachine_message_stock_order * add_stock_order_message_internal()
 * \brief Add stock_order message to the local message list.
 * \return The added message.
 */
xmachine_message_stock_order * add_stock_order_message_internal()
{
	xmachine_message_stock_order * current = (xmachine_message_stock_order *)malloc(sizeof(xmachine_message_stock_order));
	CHECK_POINTER(current);

	current->next = *p_stock_order_message;
	*p_stock_order_message = current;
	
	return current;
}

/** \fn void process_stock_order_message(xmachine_message_stock_order * current)
 * \brief Process stock_order message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_stock_order_message(xmachine_message_stock_order * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_stock_order * temp_send_message;
	
	max_mess_dist = (double)current->range;
	x = current->x;
	y = current->y;
	z = current->z;
	
	/* Check x-axis halo region */
	if((current_node->partition_data[0] != -SPINF && x <= (current_node->partition_data[0]+max_mess_dist)) ||
	   (current_node->partition_data[1] !=  SPINF && x >= (current_node->partition_data[1]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check y-axis halo region */
	if((current_node->partition_data[2] != -SPINF && y <= (current_node->partition_data[2]+max_mess_dist)) ||
	   (current_node->partition_data[3] !=  SPINF && y >= (current_node->partition_data[3]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check z-axis halo region (if used) */
	
	
	if(in_halo_region)
	{
		node_info = *p_node_info;
		while(node_info)
		{
			if(node_info->node_id != current_node->node_id &&
			node_info->partition_data[0]-max_mess_dist < x && node_info->partition_data[1]+max_mess_dist > x &&
			node_info->partition_data[2]-max_mess_dist < y && node_info->partition_data[3]+max_mess_dist > y)
			{
				p_stock_order_message = &node_info->stock_order_messages;
				temp_send_message = add_stock_order_message_internal();
				
				temp_send_message->trader_id = current->trader_id;
				temp_send_message->stock_id = current->stock_id;
				temp_send_message->limit_price = current->limit_price;
				temp_send_message->limit_quantity = current->limit_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_stock_order_message = &current_node->stock_order_messages;
	}
}

/** \fn void add_stock_order_message(int trader_id, int stock_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
 * \brief Add stock_order message by calling internal and processing.
 * \param trader_id Message variable.
 * \param stock_id Message variable.
 * \param limit_price Message variable.
 * \param limit_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_stock_order_message(int trader_id, int stock_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
{

	p_stock_order_message = &current_node->stock_order_messages;
	xmachine_message_stock_order * tmp = add_stock_order_message_internal();
	
	tmp->trader_id = trader_id;
	tmp->stock_id = stock_id;
	tmp->limit_price = limit_price;
	tmp->limit_quantity = limit_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_stock_order_message(tmp);
}

xmachine_message_stock_order * get_next_message_stock_order_in_range(xmachine_message_stock_order * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Clearinghouse)
	{
		x = (double)current_xmachine->xmachine_Clearinghouse->posx;
		y = (double)current_xmachine->xmachine_Clearinghouse->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAgent)
	{
		x = (double)current_xmachine->xmachine_FinancialAgent->posx;
		y = (double)current_xmachine->xmachine_FinancialAgent->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_stock_order * get_first_stock_order_message()
 * \brief Get the first stock_order message in the stock_order message list.
 * \return The first message in the list.
 */
xmachine_message_stock_order * get_first_stock_order_message()
{
	return get_next_message_stock_order_in_range(*p_stock_order_message);
}

/** \fn xmachine_message_stock_order * get_next_stock_order_message(xmachine_message_stock_order * current)
 * \brief Get the next stock_order message in the stock_order message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_stock_order * get_next_stock_order_message(xmachine_message_stock_order * current)
{
	return get_next_message_stock_order_in_range(current->next);
}

/** \fn void freestock_ordermessages()
 * \brief Free the stock_order message list.
 */
void freestock_ordermessages()
{
	xmachine_message_stock_order * tmp, * head;
	head = *p_stock_order_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_stock_order_message = NULL;
}

/** \fn xmachine_message_stock_transaction * add_stock_transaction_message_internal()
 * \brief Add stock_transaction message to the local message list.
 * \return The added message.
 */
xmachine_message_stock_transaction * add_stock_transaction_message_internal()
{
	xmachine_message_stock_transaction * current = (xmachine_message_stock_transaction *)malloc(sizeof(xmachine_message_stock_transaction));
	CHECK_POINTER(current);

	current->next = *p_stock_transaction_message;
	*p_stock_transaction_message = current;
	
	return current;
}

/** \fn void process_stock_transaction_message(xmachine_message_stock_transaction * current)
 * \brief Process stock_transaction message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_stock_transaction_message(xmachine_message_stock_transaction * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_stock_transaction * temp_send_message;
	
	max_mess_dist = (double)current->range;
	x = current->x;
	y = current->y;
	z = current->z;
	
	/* Check x-axis halo region */
	if((current_node->partition_data[0] != -SPINF && x <= (current_node->partition_data[0]+max_mess_dist)) ||
	   (current_node->partition_data[1] !=  SPINF && x >= (current_node->partition_data[1]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check y-axis halo region */
	if((current_node->partition_data[2] != -SPINF && y <= (current_node->partition_data[2]+max_mess_dist)) ||
	   (current_node->partition_data[3] !=  SPINF && y >= (current_node->partition_data[3]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check z-axis halo region (if used) */
	
	
	if(in_halo_region)
	{
		node_info = *p_node_info;
		while(node_info)
		{
			if(node_info->node_id != current_node->node_id &&
			node_info->partition_data[0]-max_mess_dist < x && node_info->partition_data[1]+max_mess_dist > x &&
			node_info->partition_data[2]-max_mess_dist < y && node_info->partition_data[3]+max_mess_dist > y)
			{
				p_stock_transaction_message = &node_info->stock_transaction_messages;
				temp_send_message = add_stock_transaction_message_internal();
				
				temp_send_message->trader_id = current->trader_id;
				temp_send_message->stock_id = current->stock_id;
				temp_send_message->transaction_price = current->transaction_price;
				temp_send_message->transaction_quantity = current->transaction_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_stock_transaction_message = &current_node->stock_transaction_messages;
	}
}

/** \fn void add_stock_transaction_message(int trader_id, int stock_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
 * \brief Add stock_transaction message by calling internal and processing.
 * \param trader_id Message variable.
 * \param stock_id Message variable.
 * \param transaction_price Message variable.
 * \param transaction_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_stock_transaction_message(int trader_id, int stock_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
{

	p_stock_transaction_message = &current_node->stock_transaction_messages;
	xmachine_message_stock_transaction * tmp = add_stock_transaction_message_internal();
	
	tmp->trader_id = trader_id;
	tmp->stock_id = stock_id;
	tmp->transaction_price = transaction_price;
	tmp->transaction_quantity = transaction_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_stock_transaction_message(tmp);
}

xmachine_message_stock_transaction * get_next_message_stock_transaction_in_range(xmachine_message_stock_transaction * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Clearinghouse)
	{
		x = (double)current_xmachine->xmachine_Clearinghouse->posx;
		y = (double)current_xmachine->xmachine_Clearinghouse->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAgent)
	{
		x = (double)current_xmachine->xmachine_FinancialAgent->posx;
		y = (double)current_xmachine->xmachine_FinancialAgent->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_stock_transaction * get_first_stock_transaction_message()
 * \brief Get the first stock_transaction message in the stock_transaction message list.
 * \return The first message in the list.
 */
xmachine_message_stock_transaction * get_first_stock_transaction_message()
{
	return get_next_message_stock_transaction_in_range(*p_stock_transaction_message);
}

/** \fn xmachine_message_stock_transaction * get_next_stock_transaction_message(xmachine_message_stock_transaction * current)
 * \brief Get the next stock_transaction message in the stock_transaction message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_stock_transaction * get_next_stock_transaction_message(xmachine_message_stock_transaction * current)
{
	return get_next_message_stock_transaction_in_range(current->next);
}

/** \fn void freestock_transactionmessages()
 * \brief Free the stock_transaction message list.
 */
void freestock_transactionmessages()
{
	xmachine_message_stock_transaction * tmp, * head;
	head = *p_stock_transaction_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_stock_transaction_message = NULL;
}

/** \fn xmachine_message_bond_order * add_bond_order_message_internal()
 * \brief Add bond_order message to the local message list.
 * \return The added message.
 */
xmachine_message_bond_order * add_bond_order_message_internal()
{
	xmachine_message_bond_order * current = (xmachine_message_bond_order *)malloc(sizeof(xmachine_message_bond_order));
	CHECK_POINTER(current);

	current->next = *p_bond_order_message;
	*p_bond_order_message = current;
	
	return current;
}

/** \fn void process_bond_order_message(xmachine_message_bond_order * current)
 * \brief Process bond_order message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_bond_order_message(xmachine_message_bond_order * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_bond_order * temp_send_message;
	
	max_mess_dist = (double)current->range;
	x = current->x;
	y = current->y;
	z = current->z;
	
	/* Check x-axis halo region */
	if((current_node->partition_data[0] != -SPINF && x <= (current_node->partition_data[0]+max_mess_dist)) ||
	   (current_node->partition_data[1] !=  SPINF && x >= (current_node->partition_data[1]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check y-axis halo region */
	if((current_node->partition_data[2] != -SPINF && y <= (current_node->partition_data[2]+max_mess_dist)) ||
	   (current_node->partition_data[3] !=  SPINF && y >= (current_node->partition_data[3]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check z-axis halo region (if used) */
	
	
	if(in_halo_region)
	{
		node_info = *p_node_info;
		while(node_info)
		{
			if(node_info->node_id != current_node->node_id &&
			node_info->partition_data[0]-max_mess_dist < x && node_info->partition_data[1]+max_mess_dist > x &&
			node_info->partition_data[2]-max_mess_dist < y && node_info->partition_data[3]+max_mess_dist > y)
			{
				p_bond_order_message = &node_info->bond_order_messages;
				temp_send_message = add_bond_order_message_internal();
				
				temp_send_message->trader_id = current->trader_id;
				temp_send_message->bond_id = current->bond_id;
				temp_send_message->limit_price = current->limit_price;
				temp_send_message->limit_quantity = current->limit_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_bond_order_message = &current_node->bond_order_messages;
	}
}

/** \fn void add_bond_order_message(int trader_id, int bond_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
 * \brief Add bond_order message by calling internal and processing.
 * \param trader_id Message variable.
 * \param bond_id Message variable.
 * \param limit_price Message variable.
 * \param limit_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_bond_order_message(int trader_id, int bond_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
{

	p_bond_order_message = &current_node->bond_order_messages;
	xmachine_message_bond_order * tmp = add_bond_order_message_internal();
	
	tmp->trader_id = trader_id;
	tmp->bond_id = bond_id;
	tmp->limit_price = limit_price;
	tmp->limit_quantity = limit_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_bond_order_message(tmp);
}

xmachine_message_bond_order * get_next_message_bond_order_in_range(xmachine_message_bond_order * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Clearinghouse)
	{
		x = (double)current_xmachine->xmachine_Clearinghouse->posx;
		y = (double)current_xmachine->xmachine_Clearinghouse->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAgent)
	{
		x = (double)current_xmachine->xmachine_FinancialAgent->posx;
		y = (double)current_xmachine->xmachine_FinancialAgent->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_bond_order * get_first_bond_order_message()
 * \brief Get the first bond_order message in the bond_order message list.
 * \return The first message in the list.
 */
xmachine_message_bond_order * get_first_bond_order_message()
{
	return get_next_message_bond_order_in_range(*p_bond_order_message);
}

/** \fn xmachine_message_bond_order * get_next_bond_order_message(xmachine_message_bond_order * current)
 * \brief Get the next bond_order message in the bond_order message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_bond_order * get_next_bond_order_message(xmachine_message_bond_order * current)
{
	return get_next_message_bond_order_in_range(current->next);
}

/** \fn void freebond_ordermessages()
 * \brief Free the bond_order message list.
 */
void freebond_ordermessages()
{
	xmachine_message_bond_order * tmp, * head;
	head = *p_bond_order_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_bond_order_message = NULL;
}

/** \fn xmachine_message_bond_transaction * add_bond_transaction_message_internal()
 * \brief Add bond_transaction message to the local message list.
 * \return The added message.
 */
xmachine_message_bond_transaction * add_bond_transaction_message_internal()
{
	xmachine_message_bond_transaction * current = (xmachine_message_bond_transaction *)malloc(sizeof(xmachine_message_bond_transaction));
	CHECK_POINTER(current);

	current->next = *p_bond_transaction_message;
	*p_bond_transaction_message = current;
	
	return current;
}

/** \fn void process_bond_transaction_message(xmachine_message_bond_transaction * current)
 * \brief Process bond_transaction message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_bond_transaction_message(xmachine_message_bond_transaction * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_bond_transaction * temp_send_message;
	
	max_mess_dist = (double)current->range;
	x = current->x;
	y = current->y;
	z = current->z;
	
	/* Check x-axis halo region */
	if((current_node->partition_data[0] != -SPINF && x <= (current_node->partition_data[0]+max_mess_dist)) ||
	   (current_node->partition_data[1] !=  SPINF && x >= (current_node->partition_data[1]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check y-axis halo region */
	if((current_node->partition_data[2] != -SPINF && y <= (current_node->partition_data[2]+max_mess_dist)) ||
	   (current_node->partition_data[3] !=  SPINF && y >= (current_node->partition_data[3]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check z-axis halo region (if used) */
	
	
	if(in_halo_region)
	{
		node_info = *p_node_info;
		while(node_info)
		{
			if(node_info->node_id != current_node->node_id &&
			node_info->partition_data[0]-max_mess_dist < x && node_info->partition_data[1]+max_mess_dist > x &&
			node_info->partition_data[2]-max_mess_dist < y && node_info->partition_data[3]+max_mess_dist > y)
			{
				p_bond_transaction_message = &node_info->bond_transaction_messages;
				temp_send_message = add_bond_transaction_message_internal();
				
				temp_send_message->trader_id = current->trader_id;
				temp_send_message->bond_id = current->bond_id;
				temp_send_message->transaction_price = current->transaction_price;
				temp_send_message->transaction_quantity = current->transaction_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_bond_transaction_message = &current_node->bond_transaction_messages;
	}
}

/** \fn void add_bond_transaction_message(int trader_id, int bond_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
 * \brief Add bond_transaction message by calling internal and processing.
 * \param trader_id Message variable.
 * \param bond_id Message variable.
 * \param transaction_price Message variable.
 * \param transaction_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_bond_transaction_message(int trader_id, int bond_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
{

	p_bond_transaction_message = &current_node->bond_transaction_messages;
	xmachine_message_bond_transaction * tmp = add_bond_transaction_message_internal();
	
	tmp->trader_id = trader_id;
	tmp->bond_id = bond_id;
	tmp->transaction_price = transaction_price;
	tmp->transaction_quantity = transaction_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_bond_transaction_message(tmp);
}

xmachine_message_bond_transaction * get_next_message_bond_transaction_in_range(xmachine_message_bond_transaction * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Clearinghouse)
	{
		x = (double)current_xmachine->xmachine_Clearinghouse->posx;
		y = (double)current_xmachine->xmachine_Clearinghouse->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAgent)
	{
		x = (double)current_xmachine->xmachine_FinancialAgent->posx;
		y = (double)current_xmachine->xmachine_FinancialAgent->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_bond_transaction * get_first_bond_transaction_message()
 * \brief Get the first bond_transaction message in the bond_transaction message list.
 * \return The first message in the list.
 */
xmachine_message_bond_transaction * get_first_bond_transaction_message()
{
	return get_next_message_bond_transaction_in_range(*p_bond_transaction_message);
}

/** \fn xmachine_message_bond_transaction * get_next_bond_transaction_message(xmachine_message_bond_transaction * current)
 * \brief Get the next bond_transaction message in the bond_transaction message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_bond_transaction * get_next_bond_transaction_message(xmachine_message_bond_transaction * current)
{
	return get_next_message_bond_transaction_in_range(current->next);
}

/** \fn void freebond_transactionmessages()
 * \brief Free the bond_transaction message list.
 */
void freebond_transactionmessages()
{
	xmachine_message_bond_transaction * tmp, * head;
	head = *p_bond_transaction_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_bond_transaction_message = NULL;
}

/** \fn xmachine_message_gov_bond_order * add_gov_bond_order_message_internal()
 * \brief Add gov_bond_order message to the local message list.
 * \return The added message.
 */
xmachine_message_gov_bond_order * add_gov_bond_order_message_internal()
{
	xmachine_message_gov_bond_order * current = (xmachine_message_gov_bond_order *)malloc(sizeof(xmachine_message_gov_bond_order));
	CHECK_POINTER(current);

	current->next = *p_gov_bond_order_message;
	*p_gov_bond_order_message = current;
	
	return current;
}

/** \fn void process_gov_bond_order_message(xmachine_message_gov_bond_order * current)
 * \brief Process gov_bond_order message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_gov_bond_order_message(xmachine_message_gov_bond_order * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_gov_bond_order * temp_send_message;
	
	max_mess_dist = (double)current->range;
	x = current->x;
	y = current->y;
	z = current->z;
	
	/* Check x-axis halo region */
	if((current_node->partition_data[0] != -SPINF && x <= (current_node->partition_data[0]+max_mess_dist)) ||
	   (current_node->partition_data[1] !=  SPINF && x >= (current_node->partition_data[1]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check y-axis halo region */
	if((current_node->partition_data[2] != -SPINF && y <= (current_node->partition_data[2]+max_mess_dist)) ||
	   (current_node->partition_data[3] !=  SPINF && y >= (current_node->partition_data[3]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check z-axis halo region (if used) */
	
	
	if(in_halo_region)
	{
		node_info = *p_node_info;
		while(node_info)
		{
			if(node_info->node_id != current_node->node_id &&
			node_info->partition_data[0]-max_mess_dist < x && node_info->partition_data[1]+max_mess_dist > x &&
			node_info->partition_data[2]-max_mess_dist < y && node_info->partition_data[3]+max_mess_dist > y)
			{
				p_gov_bond_order_message = &node_info->gov_bond_order_messages;
				temp_send_message = add_gov_bond_order_message_internal();
				
				temp_send_message->trader_id = current->trader_id;
				temp_send_message->gov_bond_id = current->gov_bond_id;
				temp_send_message->limit_price = current->limit_price;
				temp_send_message->limit_quantity = current->limit_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_gov_bond_order_message = &current_node->gov_bond_order_messages;
	}
}

/** \fn void add_gov_bond_order_message(int trader_id, int gov_bond_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
 * \brief Add gov_bond_order message by calling internal and processing.
 * \param trader_id Message variable.
 * \param gov_bond_id Message variable.
 * \param limit_price Message variable.
 * \param limit_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_gov_bond_order_message(int trader_id, int gov_bond_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
{

	p_gov_bond_order_message = &current_node->gov_bond_order_messages;
	xmachine_message_gov_bond_order * tmp = add_gov_bond_order_message_internal();
	
	tmp->trader_id = trader_id;
	tmp->gov_bond_id = gov_bond_id;
	tmp->limit_price = limit_price;
	tmp->limit_quantity = limit_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_gov_bond_order_message(tmp);
}

xmachine_message_gov_bond_order * get_next_message_gov_bond_order_in_range(xmachine_message_gov_bond_order * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Clearinghouse)
	{
		x = (double)current_xmachine->xmachine_Clearinghouse->posx;
		y = (double)current_xmachine->xmachine_Clearinghouse->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAgent)
	{
		x = (double)current_xmachine->xmachine_FinancialAgent->posx;
		y = (double)current_xmachine->xmachine_FinancialAgent->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_gov_bond_order * get_first_gov_bond_order_message()
 * \brief Get the first gov_bond_order message in the gov_bond_order message list.
 * \return The first message in the list.
 */
xmachine_message_gov_bond_order * get_first_gov_bond_order_message()
{
	return get_next_message_gov_bond_order_in_range(*p_gov_bond_order_message);
}

/** \fn xmachine_message_gov_bond_order * get_next_gov_bond_order_message(xmachine_message_gov_bond_order * current)
 * \brief Get the next gov_bond_order message in the gov_bond_order message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_gov_bond_order * get_next_gov_bond_order_message(xmachine_message_gov_bond_order * current)
{
	return get_next_message_gov_bond_order_in_range(current->next);
}

/** \fn void freegov_bond_ordermessages()
 * \brief Free the gov_bond_order message list.
 */
void freegov_bond_ordermessages()
{
	xmachine_message_gov_bond_order * tmp, * head;
	head = *p_gov_bond_order_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_gov_bond_order_message = NULL;
}

/** \fn xmachine_message_gov_bond_transaction * add_gov_bond_transaction_message_internal()
 * \brief Add gov_bond_transaction message to the local message list.
 * \return The added message.
 */
xmachine_message_gov_bond_transaction * add_gov_bond_transaction_message_internal()
{
	xmachine_message_gov_bond_transaction * current = (xmachine_message_gov_bond_transaction *)malloc(sizeof(xmachine_message_gov_bond_transaction));
	CHECK_POINTER(current);

	current->next = *p_gov_bond_transaction_message;
	*p_gov_bond_transaction_message = current;
	
	return current;
}

/** \fn void process_gov_bond_transaction_message(xmachine_message_gov_bond_transaction * current)
 * \brief Process gov_bond_transaction message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_gov_bond_transaction_message(xmachine_message_gov_bond_transaction * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_gov_bond_transaction * temp_send_message;
	
	max_mess_dist = (double)current->range;
	x = current->x;
	y = current->y;
	z = current->z;
	
	/* Check x-axis halo region */
	if((current_node->partition_data[0] != -SPINF && x <= (current_node->partition_data[0]+max_mess_dist)) ||
	   (current_node->partition_data[1] !=  SPINF && x >= (current_node->partition_data[1]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check y-axis halo region */
	if((current_node->partition_data[2] != -SPINF && y <= (current_node->partition_data[2]+max_mess_dist)) ||
	   (current_node->partition_data[3] !=  SPINF && y >= (current_node->partition_data[3]-max_mess_dist)))
	{ in_halo_region = 1; }
	/* Check z-axis halo region (if used) */
	
	
	if(in_halo_region)
	{
		node_info = *p_node_info;
		while(node_info)
		{
			if(node_info->node_id != current_node->node_id &&
			node_info->partition_data[0]-max_mess_dist < x && node_info->partition_data[1]+max_mess_dist > x &&
			node_info->partition_data[2]-max_mess_dist < y && node_info->partition_data[3]+max_mess_dist > y)
			{
				p_gov_bond_transaction_message = &node_info->gov_bond_transaction_messages;
				temp_send_message = add_gov_bond_transaction_message_internal();
				
				temp_send_message->trader_id = current->trader_id;
				temp_send_message->gov_bond_id = current->gov_bond_id;
				temp_send_message->transaction_price = current->transaction_price;
				temp_send_message->transaction_quantity = current->transaction_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
	}
}

/** \fn void add_gov_bond_transaction_message(int trader_id, int gov_bond_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
 * \brief Add gov_bond_transaction message by calling internal and processing.
 * \param trader_id Message variable.
 * \param gov_bond_id Message variable.
 * \param transaction_price Message variable.
 * \param transaction_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_gov_bond_transaction_message(int trader_id, int gov_bond_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
{

	p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
	xmachine_message_gov_bond_transaction * tmp = add_gov_bond_transaction_message_internal();
	
	tmp->trader_id = trader_id;
	tmp->gov_bond_id = gov_bond_id;
	tmp->transaction_price = transaction_price;
	tmp->transaction_quantity = transaction_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_gov_bond_transaction_message(tmp);
}

xmachine_message_gov_bond_transaction * get_next_message_gov_bond_transaction_in_range(xmachine_message_gov_bond_transaction * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Clearinghouse)
	{
		x = (double)current_xmachine->xmachine_Clearinghouse->posx;
		y = (double)current_xmachine->xmachine_Clearinghouse->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAgent)
	{
		x = (double)current_xmachine->xmachine_FinancialAgent->posx;
		y = (double)current_xmachine->xmachine_FinancialAgent->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_gov_bond_transaction * get_first_gov_bond_transaction_message()
 * \brief Get the first gov_bond_transaction message in the gov_bond_transaction message list.
 * \return The first message in the list.
 */
xmachine_message_gov_bond_transaction * get_first_gov_bond_transaction_message()
{
	return get_next_message_gov_bond_transaction_in_range(*p_gov_bond_transaction_message);
}

/** \fn xmachine_message_gov_bond_transaction * get_next_gov_bond_transaction_message(xmachine_message_gov_bond_transaction * current)
 * \brief Get the next gov_bond_transaction message in the gov_bond_transaction message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_gov_bond_transaction * get_next_gov_bond_transaction_message(xmachine_message_gov_bond_transaction * current)
{
	return get_next_message_gov_bond_transaction_in_range(current->next);
}

/** \fn void freegov_bond_transactionmessages()
 * \brief Free the gov_bond_transaction message list.
 */
void freegov_bond_transactionmessages()
{
	xmachine_message_gov_bond_transaction * tmp, * head;
	head = *p_gov_bond_transaction_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_gov_bond_transaction_message = NULL;
}

