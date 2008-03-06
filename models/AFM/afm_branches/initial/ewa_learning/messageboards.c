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
				
				temp_send_message->rule_id = current->rule_id;
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

/** \fn void add_rule_performance_message(int rule_id, double rule_performance, double range, double x, double y, double z)
 * \brief Add rule_performance message by calling internal and processing.
 * \param rule_id Message variable.
 * \param rule_performance Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_rule_performance_message(int rule_id, double rule_performance, double range, double x, double y, double z)
{

	p_rule_performance_message = &current_node->rule_performance_messages;
	xmachine_message_rule_performance * tmp = add_rule_performance_message_internal();
	
	tmp->rule_id = rule_id;
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
				memcpy(temp_send_message->parameters, current->parameters, 10*sizeof(double));
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

/** \fn void add_new_rule_details_message(int rule_id, double parameters, double range, double x, double y, double z)
 * \brief Add new_rule_details message by calling internal and processing.
 * \param rule_id Message variable.
 * \param parameters Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_new_rule_details_message(int rule_id, double parameters[], double range, double x, double y, double z)
{

	p_new_rule_details_message = &current_node->new_rule_details_messages;
	xmachine_message_new_rule_details * tmp = add_new_rule_details_message_internal();
	
	tmp->rule_id = rule_id;
	memcpy(tmp->parameters, parameters, 10*sizeof(double));
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

