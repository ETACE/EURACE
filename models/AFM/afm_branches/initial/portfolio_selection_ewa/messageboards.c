/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn xmachine_message_WagePayment * add_WagePayment_message_internal()
 * \brief Add WagePayment message to the local message list.
 * \return The added message.
 */
xmachine_message_WagePayment * add_WagePayment_message_internal()
{
	xmachine_message_WagePayment * current = (xmachine_message_WagePayment *)malloc(sizeof(xmachine_message_WagePayment));
	CHECK_POINTER(current);

	current->next = *p_WagePayment_message;
	*p_WagePayment_message = current;
	
	return current;
}

/** \fn void process_WagePayment_message(xmachine_message_WagePayment * current)
 * \brief Process WagePayment message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_WagePayment_message(xmachine_message_WagePayment * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_WagePayment * temp_send_message;
	
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
				p_WagePayment_message = &node_info->WagePayment_messages;
				temp_send_message = add_WagePayment_message_internal();
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_WagePayment_message = &current_node->WagePayment_messages;
	}
}

/** \fn void add_WagePayment_message(double range, double x, double y, double z)
 * \brief Add WagePayment message by calling internal and processing.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_WagePayment_message(double range, double x, double y, double z)
{

	p_WagePayment_message = &current_node->WagePayment_messages;
	xmachine_message_WagePayment * tmp = add_WagePayment_message_internal();
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_WagePayment_message(tmp);
}

xmachine_message_WagePayment * get_next_message_WagePayment_in_range(xmachine_message_WagePayment * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_WagePayment * get_first_WagePayment_message()
 * \brief Get the first WagePayment message in the WagePayment message list.
 * \return The first message in the list.
 */
xmachine_message_WagePayment * get_first_WagePayment_message()
{
	return get_next_message_WagePayment_in_range(*p_WagePayment_message);
}

/** \fn xmachine_message_WagePayment * get_next_WagePayment_message(xmachine_message_WagePayment * current)
 * \brief Get the next WagePayment message in the WagePayment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_WagePayment * get_next_WagePayment_message(xmachine_message_WagePayment * current)
{
	return get_next_message_WagePayment_in_range(current->next);
}

/** \fn void freeWagePaymentmessages()
 * \brief Free the WagePayment message list.
 */
void freeWagePaymentmessages()
{
	xmachine_message_WagePayment * tmp, * head;
	head = *p_WagePayment_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_WagePayment_message = NULL;
}

/** \fn xmachine_message_DividendPayment * add_DividendPayment_message_internal()
 * \brief Add DividendPayment message to the local message list.
 * \return The added message.
 */
xmachine_message_DividendPayment * add_DividendPayment_message_internal()
{
	xmachine_message_DividendPayment * current = (xmachine_message_DividendPayment *)malloc(sizeof(xmachine_message_DividendPayment));
	CHECK_POINTER(current);

	current->next = *p_DividendPayment_message;
	*p_DividendPayment_message = current;
	
	return current;
}

/** \fn void process_DividendPayment_message(xmachine_message_DividendPayment * current)
 * \brief Process DividendPayment message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_DividendPayment_message(xmachine_message_DividendPayment * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_DividendPayment * temp_send_message;
	
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
				p_DividendPayment_message = &node_info->DividendPayment_messages;
				temp_send_message = add_DividendPayment_message_internal();
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_DividendPayment_message = &current_node->DividendPayment_messages;
	}
}

/** \fn void add_DividendPayment_message(double range, double x, double y, double z)
 * \brief Add DividendPayment message by calling internal and processing.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_DividendPayment_message(double range, double x, double y, double z)
{

	p_DividendPayment_message = &current_node->DividendPayment_messages;
	xmachine_message_DividendPayment * tmp = add_DividendPayment_message_internal();
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_DividendPayment_message(tmp);
}

xmachine_message_DividendPayment * get_next_message_DividendPayment_in_range(xmachine_message_DividendPayment * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_DividendPayment * get_first_DividendPayment_message()
 * \brief Get the first DividendPayment message in the DividendPayment message list.
 * \return The first message in the list.
 */
xmachine_message_DividendPayment * get_first_DividendPayment_message()
{
	return get_next_message_DividendPayment_in_range(*p_DividendPayment_message);
}

/** \fn xmachine_message_DividendPayment * get_next_DividendPayment_message(xmachine_message_DividendPayment * current)
 * \brief Get the next DividendPayment message in the DividendPayment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_DividendPayment * get_next_DividendPayment_message(xmachine_message_DividendPayment * current)
{
	return get_next_message_DividendPayment_in_range(current->next);
}

/** \fn void freeDividendPaymentmessages()
 * \brief Free the DividendPayment message list.
 */
void freeDividendPaymentmessages()
{
	xmachine_message_DividendPayment * tmp, * head;
	head = *p_DividendPayment_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_DividendPayment_message = NULL;
}

/** \fn xmachine_message_BondCouponPayment * add_BondCouponPayment_message_internal()
 * \brief Add BondCouponPayment message to the local message list.
 * \return The added message.
 */
xmachine_message_BondCouponPayment * add_BondCouponPayment_message_internal()
{
	xmachine_message_BondCouponPayment * current = (xmachine_message_BondCouponPayment *)malloc(sizeof(xmachine_message_BondCouponPayment));
	CHECK_POINTER(current);

	current->next = *p_BondCouponPayment_message;
	*p_BondCouponPayment_message = current;
	
	return current;
}

/** \fn void process_BondCouponPayment_message(xmachine_message_BondCouponPayment * current)
 * \brief Process BondCouponPayment message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_BondCouponPayment_message(xmachine_message_BondCouponPayment * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_BondCouponPayment * temp_send_message;
	
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
				p_BondCouponPayment_message = &node_info->BondCouponPayment_messages;
				temp_send_message = add_BondCouponPayment_message_internal();
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_BondCouponPayment_message = &current_node->BondCouponPayment_messages;
	}
}

/** \fn void add_BondCouponPayment_message(double range, double x, double y, double z)
 * \brief Add BondCouponPayment message by calling internal and processing.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_BondCouponPayment_message(double range, double x, double y, double z)
{

	p_BondCouponPayment_message = &current_node->BondCouponPayment_messages;
	xmachine_message_BondCouponPayment * tmp = add_BondCouponPayment_message_internal();
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_BondCouponPayment_message(tmp);
}

xmachine_message_BondCouponPayment * get_next_message_BondCouponPayment_in_range(xmachine_message_BondCouponPayment * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_BondCouponPayment * get_first_BondCouponPayment_message()
 * \brief Get the first BondCouponPayment message in the BondCouponPayment message list.
 * \return The first message in the list.
 */
xmachine_message_BondCouponPayment * get_first_BondCouponPayment_message()
{
	return get_next_message_BondCouponPayment_in_range(*p_BondCouponPayment_message);
}

/** \fn xmachine_message_BondCouponPayment * get_next_BondCouponPayment_message(xmachine_message_BondCouponPayment * current)
 * \brief Get the next BondCouponPayment message in the BondCouponPayment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_BondCouponPayment * get_next_BondCouponPayment_message(xmachine_message_BondCouponPayment * current)
{
	return get_next_message_BondCouponPayment_in_range(current->next);
}

/** \fn void freeBondCouponPaymentmessages()
 * \brief Free the BondCouponPayment message list.
 */
void freeBondCouponPaymentmessages()
{
	xmachine_message_BondCouponPayment * tmp, * head;
	head = *p_BondCouponPayment_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_BondCouponPayment_message = NULL;
}

/** \fn xmachine_message_firm_bond_order * add_firm_bond_order_message_internal()
 * \brief Add firm_bond_order message to the local message list.
 * \return The added message.
 */
xmachine_message_firm_bond_order * add_firm_bond_order_message_internal()
{
	xmachine_message_firm_bond_order * current = (xmachine_message_firm_bond_order *)malloc(sizeof(xmachine_message_firm_bond_order));
	CHECK_POINTER(current);

	current->next = *p_firm_bond_order_message;
	*p_firm_bond_order_message = current;
	
	return current;
}

/** \fn void process_firm_bond_order_message(xmachine_message_firm_bond_order * current)
 * \brief Process firm_bond_order message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_firm_bond_order_message(xmachine_message_firm_bond_order * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_firm_bond_order * temp_send_message;
	
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
				p_firm_bond_order_message = &node_info->firm_bond_order_messages;
				temp_send_message = add_firm_bond_order_message_internal();
				temp_send_message->household_id = current->household_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->limit_price = current->limit_price;
				temp_send_message->limit_quantity = current->limit_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_firm_bond_order_message = &current_node->firm_bond_order_messages;
	}
}

/** \fn void add_firm_bond_order_message(int household_id, int firm_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
 * \brief Add firm_bond_order message by calling internal and processing.
 * \param household_id Message variable.
 * \param firm_id Message variable.
 * \param limit_price Message variable.
 * \param limit_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_firm_bond_order_message(int household_id, int firm_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
{

	p_firm_bond_order_message = &current_node->firm_bond_order_messages;
	xmachine_message_firm_bond_order * tmp = add_firm_bond_order_message_internal();
	tmp->household_id = household_id;
	tmp->firm_id = firm_id;
	tmp->limit_price = limit_price;
	tmp->limit_quantity = limit_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_firm_bond_order_message(tmp);
}

xmachine_message_firm_bond_order * get_next_message_firm_bond_order_in_range(xmachine_message_firm_bond_order * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_firm_bond_order * get_first_firm_bond_order_message()
 * \brief Get the first firm_bond_order message in the firm_bond_order message list.
 * \return The first message in the list.
 */
xmachine_message_firm_bond_order * get_first_firm_bond_order_message()
{
	return get_next_message_firm_bond_order_in_range(*p_firm_bond_order_message);
}

/** \fn xmachine_message_firm_bond_order * get_next_firm_bond_order_message(xmachine_message_firm_bond_order * current)
 * \brief Get the next firm_bond_order message in the firm_bond_order message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_firm_bond_order * get_next_firm_bond_order_message(xmachine_message_firm_bond_order * current)
{
	return get_next_message_firm_bond_order_in_range(current->next);
}

/** \fn void freefirm_bond_ordermessages()
 * \brief Free the firm_bond_order message list.
 */
void freefirm_bond_ordermessages()
{
	xmachine_message_firm_bond_order * tmp, * head;
	head = *p_firm_bond_order_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_firm_bond_order_message = NULL;
}

/** \fn xmachine_message_firm_stock_order * add_firm_stock_order_message_internal()
 * \brief Add firm_stock_order message to the local message list.
 * \return The added message.
 */
xmachine_message_firm_stock_order * add_firm_stock_order_message_internal()
{
	xmachine_message_firm_stock_order * current = (xmachine_message_firm_stock_order *)malloc(sizeof(xmachine_message_firm_stock_order));
	CHECK_POINTER(current);

	current->next = *p_firm_stock_order_message;
	*p_firm_stock_order_message = current;
	
	return current;
}

/** \fn void process_firm_stock_order_message(xmachine_message_firm_stock_order * current)
 * \brief Process firm_stock_order message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_firm_stock_order_message(xmachine_message_firm_stock_order * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_firm_stock_order * temp_send_message;
	
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
				p_firm_stock_order_message = &node_info->firm_stock_order_messages;
				temp_send_message = add_firm_stock_order_message_internal();
				temp_send_message->household_id = current->household_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->limit_price = current->limit_price;
				temp_send_message->limit_quantity = current->limit_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_firm_stock_order_message = &current_node->firm_stock_order_messages;
	}
}

/** \fn void add_firm_stock_order_message(int household_id, int firm_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
 * \brief Add firm_stock_order message by calling internal and processing.
 * \param household_id Message variable.
 * \param firm_id Message variable.
 * \param limit_price Message variable.
 * \param limit_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_firm_stock_order_message(int household_id, int firm_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
{

	p_firm_stock_order_message = &current_node->firm_stock_order_messages;
	xmachine_message_firm_stock_order * tmp = add_firm_stock_order_message_internal();
	tmp->household_id = household_id;
	tmp->firm_id = firm_id;
	tmp->limit_price = limit_price;
	tmp->limit_quantity = limit_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_firm_stock_order_message(tmp);
}

xmachine_message_firm_stock_order * get_next_message_firm_stock_order_in_range(xmachine_message_firm_stock_order * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_firm_stock_order * get_first_firm_stock_order_message()
 * \brief Get the first firm_stock_order message in the firm_stock_order message list.
 * \return The first message in the list.
 */
xmachine_message_firm_stock_order * get_first_firm_stock_order_message()
{
	return get_next_message_firm_stock_order_in_range(*p_firm_stock_order_message);
}

/** \fn xmachine_message_firm_stock_order * get_next_firm_stock_order_message(xmachine_message_firm_stock_order * current)
 * \brief Get the next firm_stock_order message in the firm_stock_order message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_firm_stock_order * get_next_firm_stock_order_message(xmachine_message_firm_stock_order * current)
{
	return get_next_message_firm_stock_order_in_range(current->next);
}

/** \fn void freefirm_stock_ordermessages()
 * \brief Free the firm_stock_order message list.
 */
void freefirm_stock_ordermessages()
{
	xmachine_message_firm_stock_order * tmp, * head;
	head = *p_firm_stock_order_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_firm_stock_order_message = NULL;
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
				temp_send_message->household_id = current->household_id;
				temp_send_message->gov_id = current->gov_id;
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

/** \fn void add_gov_bond_order_message(int household_id, int gov_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
 * \brief Add gov_bond_order message by calling internal and processing.
 * \param household_id Message variable.
 * \param gov_id Message variable.
 * \param limit_price Message variable.
 * \param limit_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_gov_bond_order_message(int household_id, int gov_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
{

	p_gov_bond_order_message = &current_node->gov_bond_order_messages;
	xmachine_message_gov_bond_order * tmp = add_gov_bond_order_message_internal();
	tmp->household_id = household_id;
	tmp->gov_id = gov_id;
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
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
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

/** \fn xmachine_message_firm_bond_transaction * add_firm_bond_transaction_message_internal()
 * \brief Add firm_bond_transaction message to the local message list.
 * \return The added message.
 */
xmachine_message_firm_bond_transaction * add_firm_bond_transaction_message_internal()
{
	xmachine_message_firm_bond_transaction * current = (xmachine_message_firm_bond_transaction *)malloc(sizeof(xmachine_message_firm_bond_transaction));
	CHECK_POINTER(current);

	current->next = *p_firm_bond_transaction_message;
	*p_firm_bond_transaction_message = current;
	
	return current;
}

/** \fn void process_firm_bond_transaction_message(xmachine_message_firm_bond_transaction * current)
 * \brief Process firm_bond_transaction message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_firm_bond_transaction_message(xmachine_message_firm_bond_transaction * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_firm_bond_transaction * temp_send_message;
	
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
				p_firm_bond_transaction_message = &node_info->firm_bond_transaction_messages;
				temp_send_message = add_firm_bond_transaction_message_internal();
				temp_send_message->household_id = current->household_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->transaction_price = current->transaction_price;
				temp_send_message->transaction_quantity = current->transaction_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;
	}
}

/** \fn void add_firm_bond_transaction_message(int household_id, int firm_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
 * \brief Add firm_bond_transaction message by calling internal and processing.
 * \param household_id Message variable.
 * \param firm_id Message variable.
 * \param transaction_price Message variable.
 * \param transaction_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_firm_bond_transaction_message(int household_id, int firm_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
{

	p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;
	xmachine_message_firm_bond_transaction * tmp = add_firm_bond_transaction_message_internal();
	tmp->household_id = household_id;
	tmp->firm_id = firm_id;
	tmp->transaction_price = transaction_price;
	tmp->transaction_quantity = transaction_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_firm_bond_transaction_message(tmp);
}

xmachine_message_firm_bond_transaction * get_next_message_firm_bond_transaction_in_range(xmachine_message_firm_bond_transaction * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_firm_bond_transaction * get_first_firm_bond_transaction_message()
 * \brief Get the first firm_bond_transaction message in the firm_bond_transaction message list.
 * \return The first message in the list.
 */
xmachine_message_firm_bond_transaction * get_first_firm_bond_transaction_message()
{
	return get_next_message_firm_bond_transaction_in_range(*p_firm_bond_transaction_message);
}

/** \fn xmachine_message_firm_bond_transaction * get_next_firm_bond_transaction_message(xmachine_message_firm_bond_transaction * current)
 * \brief Get the next firm_bond_transaction message in the firm_bond_transaction message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_firm_bond_transaction * get_next_firm_bond_transaction_message(xmachine_message_firm_bond_transaction * current)
{
	return get_next_message_firm_bond_transaction_in_range(current->next);
}

/** \fn void freefirm_bond_transactionmessages()
 * \brief Free the firm_bond_transaction message list.
 */
void freefirm_bond_transactionmessages()
{
	xmachine_message_firm_bond_transaction * tmp, * head;
	head = *p_firm_bond_transaction_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_firm_bond_transaction_message = NULL;
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
				temp_send_message->household_id = current->household_id;
				temp_send_message->gov_id = current->gov_id;
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

/** \fn void add_gov_bond_transaction_message(int household_id, int gov_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
 * \brief Add gov_bond_transaction message by calling internal and processing.
 * \param household_id Message variable.
 * \param gov_id Message variable.
 * \param transaction_price Message variable.
 * \param transaction_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_gov_bond_transaction_message(int household_id, int gov_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
{

	p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
	xmachine_message_gov_bond_transaction * tmp = add_gov_bond_transaction_message_internal();
	tmp->household_id = household_id;
	tmp->gov_id = gov_id;
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
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
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

/** \fn xmachine_message_firm_stock_transaction * add_firm_stock_transaction_message_internal()
 * \brief Add firm_stock_transaction message to the local message list.
 * \return The added message.
 */
xmachine_message_firm_stock_transaction * add_firm_stock_transaction_message_internal()
{
	xmachine_message_firm_stock_transaction * current = (xmachine_message_firm_stock_transaction *)malloc(sizeof(xmachine_message_firm_stock_transaction));
	CHECK_POINTER(current);

	current->next = *p_firm_stock_transaction_message;
	*p_firm_stock_transaction_message = current;
	
	return current;
}

/** \fn void process_firm_stock_transaction_message(xmachine_message_firm_stock_transaction * current)
 * \brief Process firm_stock_transaction message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_firm_stock_transaction_message(xmachine_message_firm_stock_transaction * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_firm_stock_transaction * temp_send_message;
	
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
				p_firm_stock_transaction_message = &node_info->firm_stock_transaction_messages;
				temp_send_message = add_firm_stock_transaction_message_internal();
				temp_send_message->household_id = current->household_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->transaction_price = current->transaction_price;
				temp_send_message->transaction_quantity = current->transaction_quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;
	}
}

/** \fn void add_firm_stock_transaction_message(int household_id, int firm_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
 * \brief Add firm_stock_transaction message by calling internal and processing.
 * \param household_id Message variable.
 * \param firm_id Message variable.
 * \param transaction_price Message variable.
 * \param transaction_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_firm_stock_transaction_message(int household_id, int firm_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
{

	p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;
	xmachine_message_firm_stock_transaction * tmp = add_firm_stock_transaction_message_internal();
	tmp->household_id = household_id;
	tmp->firm_id = firm_id;
	tmp->transaction_price = transaction_price;
	tmp->transaction_quantity = transaction_quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_firm_stock_transaction_message(tmp);
}

xmachine_message_firm_stock_transaction * get_next_message_firm_stock_transaction_in_range(xmachine_message_firm_stock_transaction * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_firm_stock_transaction * get_first_firm_stock_transaction_message()
 * \brief Get the first firm_stock_transaction message in the firm_stock_transaction message list.
 * \return The first message in the list.
 */
xmachine_message_firm_stock_transaction * get_first_firm_stock_transaction_message()
{
	return get_next_message_firm_stock_transaction_in_range(*p_firm_stock_transaction_message);
}

/** \fn xmachine_message_firm_stock_transaction * get_next_firm_stock_transaction_message(xmachine_message_firm_stock_transaction * current)
 * \brief Get the next firm_stock_transaction message in the firm_stock_transaction message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_firm_stock_transaction * get_next_firm_stock_transaction_message(xmachine_message_firm_stock_transaction * current)
{
	return get_next_message_firm_stock_transaction_in_range(current->next);
}

/** \fn void freefirm_stock_transactionmessages()
 * \brief Free the firm_stock_transaction message list.
 */
void freefirm_stock_transactionmessages()
{
	xmachine_message_firm_stock_transaction * tmp, * head;
	head = *p_firm_stock_transaction_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_firm_stock_transaction_message = NULL;
}

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
				temp_send_message->nr_selected_rule = current->nr_selected_rule;
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

/** \fn void add_rule_performance_message(int nr_selected_rule, double rule_performance, double range, double x, double y, double z)
 * \brief Add rule_performance message by calling internal and processing.
 * \param nr_selected_rule Message variable.
 * \param rule_performance Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_rule_performance_message(int nr_selected_rule, double rule_performance, double range, double x, double y, double z)
{

	p_rule_performance_message = &current_node->rule_performance_messages;
	xmachine_message_rule_performance * tmp = add_rule_performance_message_internal();
	tmp->nr_selected_rule = nr_selected_rule;
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
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
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

/** \fn xmachine_message_all_performances * add_all_performances_message_internal()
 * \brief Add all_performances message to the local message list.
 * \return The added message.
 */
xmachine_message_all_performances * add_all_performances_message_internal()
{
	xmachine_message_all_performances * current = (xmachine_message_all_performances *)malloc(sizeof(xmachine_message_all_performances));
	CHECK_POINTER(current);

	current->next = *p_all_performances_message;
	*p_all_performances_message = current;
	
	return current;
}

/** \fn void process_all_performances_message(xmachine_message_all_performances * current)
 * \brief Process all_performances message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_all_performances_message(xmachine_message_all_performances * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_all_performances * temp_send_message;
	
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
				p_all_performances_message = &node_info->all_performances_messages;
				temp_send_message = add_all_performances_message_internal();
				temp_send_message->performances = current->performances;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_all_performances_message = &current_node->all_performances_messages;
	}
}

/** \fn void add_all_performances_message(double performances, double range, double x, double y, double z)
 * \brief Add all_performances message by calling internal and processing.
 * \param performances Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_all_performances_message(double performances, double range, double x, double y, double z)
{

	p_all_performances_message = &current_node->all_performances_messages;
	xmachine_message_all_performances * tmp = add_all_performances_message_internal();
	tmp->performances = performances;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_all_performances_message(tmp);
}

xmachine_message_all_performances * get_next_message_all_performances_in_range(xmachine_message_all_performances * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_all_performances * get_first_all_performances_message()
 * \brief Get the first all_performances message in the all_performances message list.
 * \return The first message in the list.
 */
xmachine_message_all_performances * get_first_all_performances_message()
{
	return get_next_message_all_performances_in_range(*p_all_performances_message);
}

/** \fn xmachine_message_all_performances * get_next_all_performances_message(xmachine_message_all_performances * current)
 * \brief Get the next all_performances message in the all_performances message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_all_performances * get_next_all_performances_message(xmachine_message_all_performances * current)
{
	return get_next_message_all_performances_in_range(current->next);
}

/** \fn void freeall_performancesmessages()
 * \brief Free the all_performances message list.
 */
void freeall_performancesmessages()
{
	xmachine_message_all_performances * tmp, * head;
	head = *p_all_performances_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_all_performances_message = NULL;
}

/** \fn xmachine_message_rule_details_request * add_rule_details_request_message_internal()
 * \brief Add rule_details_request message to the local message list.
 * \return The added message.
 */
xmachine_message_rule_details_request * add_rule_details_request_message_internal()
{
	xmachine_message_rule_details_request * current = (xmachine_message_rule_details_request *)malloc(sizeof(xmachine_message_rule_details_request));
	CHECK_POINTER(current);

	current->next = *p_rule_details_request_message;
	*p_rule_details_request_message = current;
	
	return current;
}

/** \fn void process_rule_details_request_message(xmachine_message_rule_details_request * current)
 * \brief Process rule_details_request message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_rule_details_request_message(xmachine_message_rule_details_request * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_rule_details_request * temp_send_message;
	
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
				p_rule_details_request_message = &node_info->rule_details_request_messages;
				temp_send_message = add_rule_details_request_message_internal();
				temp_send_message->household_id = current->household_id;
				temp_send_message->selected_rule_number = current->selected_rule_number;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_rule_details_request_message = &current_node->rule_details_request_messages;
	}
}

/** \fn void add_rule_details_request_message(int household_id, int selected_rule_number, double range, double x, double y, double z)
 * \brief Add rule_details_request message by calling internal and processing.
 * \param household_id Message variable.
 * \param selected_rule_number Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_rule_details_request_message(int household_id, int selected_rule_number, double range, double x, double y, double z)
{

	p_rule_details_request_message = &current_node->rule_details_request_messages;
	xmachine_message_rule_details_request * tmp = add_rule_details_request_message_internal();
	tmp->household_id = household_id;
	tmp->selected_rule_number = selected_rule_number;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_rule_details_request_message(tmp);
}

xmachine_message_rule_details_request * get_next_message_rule_details_request_in_range(xmachine_message_rule_details_request * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_rule_details_request * get_first_rule_details_request_message()
 * \brief Get the first rule_details_request message in the rule_details_request message list.
 * \return The first message in the list.
 */
xmachine_message_rule_details_request * get_first_rule_details_request_message()
{
	return get_next_message_rule_details_request_in_range(*p_rule_details_request_message);
}

/** \fn xmachine_message_rule_details_request * get_next_rule_details_request_message(xmachine_message_rule_details_request * current)
 * \brief Get the next rule_details_request message in the rule_details_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_rule_details_request * get_next_rule_details_request_message(xmachine_message_rule_details_request * current)
{
	return get_next_message_rule_details_request_in_range(current->next);
}

/** \fn void freerule_details_requestmessages()
 * \brief Free the rule_details_request message list.
 */
void freerule_details_requestmessages()
{
	xmachine_message_rule_details_request * tmp, * head;
	head = *p_rule_details_request_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_rule_details_request_message = NULL;
}

/** \fn xmachine_message_ruledetailsystem * add_ruledetailsystem_message_internal()
 * \brief Add ruledetailsystem message to the local message list.
 * \return The added message.
 */
xmachine_message_ruledetailsystem * add_ruledetailsystem_message_internal()
{
	xmachine_message_ruledetailsystem * current = (xmachine_message_ruledetailsystem *)malloc(sizeof(xmachine_message_ruledetailsystem));
	CHECK_POINTER(current);

	current->next = *p_ruledetailsystem_message;
	*p_ruledetailsystem_message = current;
	
	return current;
}

/** \fn void process_ruledetailsystem_message(xmachine_message_ruledetailsystem * current)
 * \brief Process ruledetailsystem message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_ruledetailsystem_message(xmachine_message_ruledetailsystem * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_ruledetailsystem * temp_send_message;
	
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
				p_ruledetailsystem_message = &node_info->ruledetailsystem_messages;
				temp_send_message = add_ruledetailsystem_message_internal();
				temp_send_message->parameters = current->parameters;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_ruledetailsystem_message = &current_node->ruledetailsystem_messages;
	}
}

/** \fn void add_ruledetailsystem_message(double parameters, double range, double x, double y, double z)
 * \brief Add ruledetailsystem message by calling internal and processing.
 * \param parameters Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_ruledetailsystem_message(double parameters, double range, double x, double y, double z)
{

	p_ruledetailsystem_message = &current_node->ruledetailsystem_messages;
	xmachine_message_ruledetailsystem * tmp = add_ruledetailsystem_message_internal();
	tmp->parameters = parameters;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;


	/* Check if agent in halo region */
	process_ruledetailsystem_message(tmp);
}

xmachine_message_ruledetailsystem * get_next_message_ruledetailsystem_in_range(xmachine_message_ruledetailsystem * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouseMechanism)
	{
		x = (double)current_xmachine->xmachine_ClearingHouseMechanism->posx;
		y = (double)current_xmachine->xmachine_ClearingHouseMechanism->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_LimitOrderBook)
	{
		x = (double)current_xmachine->xmachine_LimitOrderBook->posx;
		y = (double)current_xmachine->xmachine_LimitOrderBook->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Government)
	{
		x = (double)current_xmachine->xmachine_Government->posx;
		y = (double)current_xmachine->xmachine_Government->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_FinancialAdvisor)
	{
		x = (double)current_xmachine->xmachine_FinancialAdvisor->posx;
		y = (double)current_xmachine->xmachine_FinancialAdvisor->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_ruledetailsystem * get_first_ruledetailsystem_message()
 * \brief Get the first ruledetailsystem message in the ruledetailsystem message list.
 * \return The first message in the list.
 */
xmachine_message_ruledetailsystem * get_first_ruledetailsystem_message()
{
	return get_next_message_ruledetailsystem_in_range(*p_ruledetailsystem_message);
}

/** \fn xmachine_message_ruledetailsystem * get_next_ruledetailsystem_message(xmachine_message_ruledetailsystem * current)
 * \brief Get the next ruledetailsystem message in the ruledetailsystem message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_ruledetailsystem * get_next_ruledetailsystem_message(xmachine_message_ruledetailsystem * current)
{
	return get_next_message_ruledetailsystem_in_range(current->next);
}

/** \fn void freeruledetailsystemmessages()
 * \brief Free the ruledetailsystem message list.
 */
void freeruledetailsystemmessages()
{
	xmachine_message_ruledetailsystem * tmp, * head;
	head = *p_ruledetailsystem_message;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_ruledetailsystem_message = NULL;
}

