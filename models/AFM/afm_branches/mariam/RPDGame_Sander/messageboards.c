/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn xmachine_message_strategy_i_use * add_strategy_i_use_message_internal()
 * \brief Add strategy_i_use message to the local message list.
 * \return The added message.
 */
xmachine_message_strategy_i_use * add_strategy_i_use_message_internal()
{
	xmachine_message_strategy_i_use * current = (xmachine_message_strategy_i_use *)malloc(sizeof(xmachine_message_strategy_i_use));
	CHECK_POINTER(current);

	current->next = *p_strategy_i_use_message;
	*p_strategy_i_use_message = current;
	
	return current;
}

/** \fn void process_strategy_i_use_message(xmachine_message_strategy_i_use * current)
 * \brief Process strategy_i_use message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_strategy_i_use_message(xmachine_message_strategy_i_use * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_strategy_i_use * temp_send_message;
	
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
				p_strategy_i_use_message = &node_info->strategy_i_use_messages;
				temp_send_message = add_strategy_i_use_message_internal();
				
				temp_send_message->player_id = current->player_id;
				temp_send_message->strategy_id = current->strategy_id;
				temp_send_message->previous_move = current->previous_move;
				temp_send_message->present_state = current->present_state;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_strategy_i_use_message = &current_node->strategy_i_use_messages;
	}
}

/** \fn void add_strategy_i_use_message(int player_id, int strategy_id, int previous_move, int present_state, double range, double x, double y, double z)
 * \brief Add strategy_i_use message by calling internal and processing.
 * \param player_id Message variable.
 * \param strategy_id Message variable.
 * \param previous_move Message variable.
 * \param present_state Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_strategy_i_use_message(int player_id, int strategy_id, int previous_move, int present_state, double range, double x, double y, double z)
{

	p_strategy_i_use_message = &current_node->strategy_i_use_messages;
	xmachine_message_strategy_i_use * tmp = add_strategy_i_use_message_internal();
	
	tmp->player_id = player_id;
	tmp->strategy_id = strategy_id;
	tmp->previous_move = previous_move;
	tmp->present_state = present_state;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_strategy_i_use_message(tmp);
}

xmachine_message_strategy_i_use * get_next_message_strategy_i_use_in_range(xmachine_message_strategy_i_use * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_GamePlayer)
	{
		x = (double)current_xmachine->xmachine_GamePlayer->posx;
		y = (double)current_xmachine->xmachine_GamePlayer->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_GameSolver)
	{
		x = (double)current_xmachine->xmachine_GameSolver->posx;
		y = (double)current_xmachine->xmachine_GameSolver->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_strategy_i_use * get_first_strategy_i_use_message()
 * \brief Get the first strategy_i_use message in the strategy_i_use message list.
 * \return The first message in the list.
 */
xmachine_message_strategy_i_use * get_first_strategy_i_use_message()
{
	return get_next_message_strategy_i_use_in_range(*p_strategy_i_use_message);
}

/** \fn xmachine_message_strategy_i_use * get_next_strategy_i_use_message(xmachine_message_strategy_i_use * current)
 * \brief Get the next strategy_i_use message in the strategy_i_use message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_strategy_i_use * get_next_strategy_i_use_message(xmachine_message_strategy_i_use * current)
{
	return get_next_message_strategy_i_use_in_range(current->next);
}

/** \fn void freestrategy_i_usemessages()
 * \brief Free the strategy_i_use message list.
 */
void freestrategy_i_usemessages()
{
	xmachine_message_strategy_i_use * tmp, * head;
	head = *p_strategy_i_use_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_strategy_i_use_message = NULL;
}

