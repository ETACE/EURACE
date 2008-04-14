/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn xmachine_message_tax_payment * add_tax_payment_message_internal()
 * \brief Add tax_payment message to the local message list.
 * \return The added message.
 */
xmachine_message_tax_payment * add_tax_payment_message_internal()
{
	xmachine_message_tax_payment * current = (xmachine_message_tax_payment *)malloc(sizeof(xmachine_message_tax_payment));
	CHECK_POINTER(current);

	current->next = *p_tax_payment_message;
	*p_tax_payment_message = current;
	
	return current;
}

/** \fn void process_tax_payment_message(xmachine_message_tax_payment * current)
 * \brief Process tax_payment message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_tax_payment_message(xmachine_message_tax_payment * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_tax_payment * temp_send_message;
	
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
				p_tax_payment_message = &node_info->tax_payment_messages;
				temp_send_message = add_tax_payment_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->gov_id = current->gov_id;
				temp_send_message->tax_payment = current->tax_payment;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_tax_payment_message = &current_node->tax_payment_messages;
	}
}

/** \fn void add_tax_payment_message(int firm_id, int gov_id, double tax_payment, double range, double x, double y, double z)
 * \brief Add tax_payment message by calling internal and processing.
 * \param firm_id Message variable.
 * \param gov_id Message variable.
 * \param tax_payment Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_tax_payment_message(int firm_id, int gov_id, double tax_payment, double range, double x, double y, double z)
{

	p_tax_payment_message = &current_node->tax_payment_messages;
	xmachine_message_tax_payment * tmp = add_tax_payment_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->gov_id = gov_id;
	tmp->tax_payment = tax_payment;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_tax_payment_message(tmp);
}

xmachine_message_tax_payment * get_next_message_tax_payment_in_range(xmachine_message_tax_payment * current)
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_tax_payment * get_first_tax_payment_message()
 * \brief Get the first tax_payment message in the tax_payment message list.
 * \return The first message in the list.
 */
xmachine_message_tax_payment * get_first_tax_payment_message()
{
	return get_next_message_tax_payment_in_range(*p_tax_payment_message);
}

/** \fn xmachine_message_tax_payment * get_next_tax_payment_message(xmachine_message_tax_payment * current)
 * \brief Get the next tax_payment message in the tax_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_tax_payment * get_next_tax_payment_message(xmachine_message_tax_payment * current)
{
	return get_next_message_tax_payment_in_range(current->next);
}

/** \fn void freetax_paymentmessages()
 * \brief Free the tax_payment message list.
 */
void freetax_paymentmessages()
{
	xmachine_message_tax_payment * tmp, * head;
	head = *p_tax_payment_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_tax_payment_message = NULL;
}

/** \fn xmachine_message_interest_payment * add_interest_payment_message_internal()
 * \brief Add interest_payment message to the local message list.
 * \return The added message.
 */
xmachine_message_interest_payment * add_interest_payment_message_internal()
{
	xmachine_message_interest_payment * current = (xmachine_message_interest_payment *)malloc(sizeof(xmachine_message_interest_payment));
	CHECK_POINTER(current);

	current->next = *p_interest_payment_message;
	*p_interest_payment_message = current;
	
	return current;
}

/** \fn void process_interest_payment_message(xmachine_message_interest_payment * current)
 * \brief Process interest_payment message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_interest_payment_message(xmachine_message_interest_payment * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_interest_payment * temp_send_message;
	
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
				p_interest_payment_message = &node_info->interest_payment_messages;
				temp_send_message = add_interest_payment_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->bank_id = current->bank_id;
				temp_send_message->interest_payment = current->interest_payment;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_interest_payment_message = &current_node->interest_payment_messages;
	}
}

/** \fn void add_interest_payment_message(int firm_id, int bank_id, double interest_payment, double range, double x, double y, double z)
 * \brief Add interest_payment message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param interest_payment Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_interest_payment_message(int firm_id, int bank_id, double interest_payment, double range, double x, double y, double z)
{

	p_interest_payment_message = &current_node->interest_payment_messages;
	xmachine_message_interest_payment * tmp = add_interest_payment_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->bank_id = bank_id;
	tmp->interest_payment = interest_payment;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_interest_payment_message(tmp);
}

xmachine_message_interest_payment * get_next_message_interest_payment_in_range(xmachine_message_interest_payment * current)
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_interest_payment * get_first_interest_payment_message()
 * \brief Get the first interest_payment message in the interest_payment message list.
 * \return The first message in the list.
 */
xmachine_message_interest_payment * get_first_interest_payment_message()
{
	return get_next_message_interest_payment_in_range(*p_interest_payment_message);
}

/** \fn xmachine_message_interest_payment * get_next_interest_payment_message(xmachine_message_interest_payment * current)
 * \brief Get the next interest_payment message in the interest_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_interest_payment * get_next_interest_payment_message(xmachine_message_interest_payment * current)
{
	return get_next_message_interest_payment_in_range(current->next);
}

/** \fn void freeinterest_paymentmessages()
 * \brief Free the interest_payment message list.
 */
void freeinterest_paymentmessages()
{
	xmachine_message_interest_payment * tmp, * head;
	head = *p_interest_payment_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_interest_payment_message = NULL;
}

/** \fn xmachine_message_debt_installment_payment * add_debt_installment_payment_message_internal()
 * \brief Add debt_installment_payment message to the local message list.
 * \return The added message.
 */
xmachine_message_debt_installment_payment * add_debt_installment_payment_message_internal()
{
	xmachine_message_debt_installment_payment * current = (xmachine_message_debt_installment_payment *)malloc(sizeof(xmachine_message_debt_installment_payment));
	CHECK_POINTER(current);

	current->next = *p_debt_installment_payment_message;
	*p_debt_installment_payment_message = current;
	
	return current;
}

/** \fn void process_debt_installment_payment_message(xmachine_message_debt_installment_payment * current)
 * \brief Process debt_installment_payment message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_debt_installment_payment_message(xmachine_message_debt_installment_payment * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_debt_installment_payment * temp_send_message;
	
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
				p_debt_installment_payment_message = &node_info->debt_installment_payment_messages;
				temp_send_message = add_debt_installment_payment_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->bank_id = current->bank_id;
				temp_send_message->debt_installment_payment = current->debt_installment_payment;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
	}
}

/** \fn void add_debt_installment_payment_message(int firm_id, int bank_id, double debt_installment_payment, double range, double x, double y, double z)
 * \brief Add debt_installment_payment message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param debt_installment_payment Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_debt_installment_payment_message(int firm_id, int bank_id, double debt_installment_payment, double range, double x, double y, double z)
{

	p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
	xmachine_message_debt_installment_payment * tmp = add_debt_installment_payment_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->bank_id = bank_id;
	tmp->debt_installment_payment = debt_installment_payment;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_debt_installment_payment_message(tmp);
}

xmachine_message_debt_installment_payment * get_next_message_debt_installment_payment_in_range(xmachine_message_debt_installment_payment * current)
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_debt_installment_payment * get_first_debt_installment_payment_message()
 * \brief Get the first debt_installment_payment message in the debt_installment_payment message list.
 * \return The first message in the list.
 */
xmachine_message_debt_installment_payment * get_first_debt_installment_payment_message()
{
	return get_next_message_debt_installment_payment_in_range(*p_debt_installment_payment_message);
}

/** \fn xmachine_message_debt_installment_payment * get_next_debt_installment_payment_message(xmachine_message_debt_installment_payment * current)
 * \brief Get the next debt_installment_payment message in the debt_installment_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_debt_installment_payment * get_next_debt_installment_payment_message(xmachine_message_debt_installment_payment * current)
{
	return get_next_message_debt_installment_payment_in_range(current->next);
}

/** \fn void freedebt_installment_paymentmessages()
 * \brief Free the debt_installment_payment message list.
 */
void freedebt_installment_paymentmessages()
{
	xmachine_message_debt_installment_payment * tmp, * head;
	head = *p_debt_installment_payment_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_debt_installment_payment_message = NULL;
}

/** \fn xmachine_message_dividend_payment * add_dividend_payment_message_internal()
 * \brief Add dividend_payment message to the local message list.
 * \return The added message.
 */
xmachine_message_dividend_payment * add_dividend_payment_message_internal()
{
	xmachine_message_dividend_payment * current = (xmachine_message_dividend_payment *)malloc(sizeof(xmachine_message_dividend_payment));
	CHECK_POINTER(current);

	current->next = *p_dividend_payment_message;
	*p_dividend_payment_message = current;
	
	return current;
}

/** \fn void process_dividend_payment_message(xmachine_message_dividend_payment * current)
 * \brief Process dividend_payment message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_dividend_payment_message(xmachine_message_dividend_payment * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_dividend_payment * temp_send_message;
	
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
				p_dividend_payment_message = &node_info->dividend_payment_messages;
				temp_send_message = add_dividend_payment_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->current_dividend_per_share = current->current_dividend_per_share;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_dividend_payment_message = &current_node->dividend_payment_messages;
	}
}

/** \fn void add_dividend_payment_message(int firm_id, double current_dividend_per_share, double range, double x, double y, double z)
 * \brief Add dividend_payment message by calling internal and processing.
 * \param firm_id Message variable.
 * \param current_dividend_per_share Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_dividend_payment_message(int firm_id, double current_dividend_per_share, double range, double x, double y, double z)
{

	p_dividend_payment_message = &current_node->dividend_payment_messages;
	xmachine_message_dividend_payment * tmp = add_dividend_payment_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->current_dividend_per_share = current_dividend_per_share;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_dividend_payment_message(tmp);
}

xmachine_message_dividend_payment * get_next_message_dividend_payment_in_range(xmachine_message_dividend_payment * current)
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_dividend_payment * get_first_dividend_payment_message()
 * \brief Get the first dividend_payment message in the dividend_payment message list.
 * \return The first message in the list.
 */
xmachine_message_dividend_payment * get_first_dividend_payment_message()
{
	return get_next_message_dividend_payment_in_range(*p_dividend_payment_message);
}

/** \fn xmachine_message_dividend_payment * get_next_dividend_payment_message(xmachine_message_dividend_payment * current)
 * \brief Get the next dividend_payment message in the dividend_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_dividend_payment * get_next_dividend_payment_message(xmachine_message_dividend_payment * current)
{
	return get_next_message_dividend_payment_in_range(current->next);
}

/** \fn void freedividend_paymentmessages()
 * \brief Free the dividend_payment message list.
 */
void freedividend_paymentmessages()
{
	xmachine_message_dividend_payment * tmp, * head;
	head = *p_dividend_payment_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_dividend_payment_message = NULL;
}

/** \fn xmachine_message_loan_request * add_loan_request_message_internal()
 * \brief Add loan_request message to the local message list.
 * \return The added message.
 */
xmachine_message_loan_request * add_loan_request_message_internal()
{
	xmachine_message_loan_request * current = (xmachine_message_loan_request *)malloc(sizeof(xmachine_message_loan_request));
	CHECK_POINTER(current);

	current->next = *p_loan_request_message;
	*p_loan_request_message = current;
	
	return current;
}

/** \fn void process_loan_request_message(xmachine_message_loan_request * current)
 * \brief Process loan_request message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_loan_request_message(xmachine_message_loan_request * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_loan_request * temp_send_message;
	
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
				p_loan_request_message = &node_info->loan_request_messages;
				temp_send_message = add_loan_request_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->bank_id = current->bank_id;
				temp_send_message->credit_amount = current->credit_amount;
				temp_send_message->total_assets = current->total_assets;
				temp_send_message->total_debt = current->total_debt;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_loan_request_message = &current_node->loan_request_messages;
	}
}

/** \fn void add_loan_request_message(int firm_id, int bank_id, double credit_amount, double total_assets, double total_debt, double range, double x, double y, double z)
 * \brief Add loan_request message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param credit_amount Message variable.
 * \param total_assets Message variable.
 * \param total_debt Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_loan_request_message(int firm_id, int bank_id, double credit_amount, double total_assets, double total_debt, double range, double x, double y, double z)
{

	p_loan_request_message = &current_node->loan_request_messages;
	xmachine_message_loan_request * tmp = add_loan_request_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->bank_id = bank_id;
	tmp->credit_amount = credit_amount;
	tmp->total_assets = total_assets;
	tmp->total_debt = total_debt;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_loan_request_message(tmp);
}

xmachine_message_loan_request * get_next_message_loan_request_in_range(xmachine_message_loan_request * current)
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_loan_request * get_first_loan_request_message()
 * \brief Get the first loan_request message in the loan_request message list.
 * \return The first message in the list.
 */
xmachine_message_loan_request * get_first_loan_request_message()
{
	return get_next_message_loan_request_in_range(*p_loan_request_message);
}

/** \fn xmachine_message_loan_request * get_next_loan_request_message(xmachine_message_loan_request * current)
 * \brief Get the next loan_request message in the loan_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_loan_request * get_next_loan_request_message(xmachine_message_loan_request * current)
{
	return get_next_message_loan_request_in_range(current->next);
}

/** \fn void freeloan_requestmessages()
 * \brief Free the loan_request message list.
 */
void freeloan_requestmessages()
{
	xmachine_message_loan_request * tmp, * head;
	head = *p_loan_request_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_loan_request_message = NULL;
}

/** \fn xmachine_message_loan_conditions * add_loan_conditions_message_internal()
 * \brief Add loan_conditions message to the local message list.
 * \return The added message.
 */
xmachine_message_loan_conditions * add_loan_conditions_message_internal()
{
	xmachine_message_loan_conditions * current = (xmachine_message_loan_conditions *)malloc(sizeof(xmachine_message_loan_conditions));
	CHECK_POINTER(current);

	current->next = *p_loan_conditions_message;
	*p_loan_conditions_message = current;
	
	return current;
}

/** \fn void process_loan_conditions_message(xmachine_message_loan_conditions * current)
 * \brief Process loan_conditions message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_loan_conditions_message(xmachine_message_loan_conditions * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_loan_conditions * temp_send_message;
	
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
				p_loan_conditions_message = &node_info->loan_conditions_messages;
				temp_send_message = add_loan_conditions_message_internal();
				
				temp_send_message->bank_id = current->bank_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->proposed_interest_rate = current->proposed_interest_rate;
				temp_send_message->amount_credit_offer = current->amount_credit_offer;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_loan_conditions_message = &current_node->loan_conditions_messages;
	}
}

/** \fn void add_loan_conditions_message(int bank_id, int firm_id, double proposed_interest_rate, double amount_credit_offer, double range, double x, double y, double z)
 * \brief Add loan_conditions message by calling internal and processing.
 * \param bank_id Message variable.
 * \param firm_id Message variable.
 * \param proposed_interest_rate Message variable.
 * \param amount_credit_offer Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_loan_conditions_message(int bank_id, int firm_id, double proposed_interest_rate, double amount_credit_offer, double range, double x, double y, double z)
{

	p_loan_conditions_message = &current_node->loan_conditions_messages;
	xmachine_message_loan_conditions * tmp = add_loan_conditions_message_internal();
	
	tmp->bank_id = bank_id;
	tmp->firm_id = firm_id;
	tmp->proposed_interest_rate = proposed_interest_rate;
	tmp->amount_credit_offer = amount_credit_offer;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_loan_conditions_message(tmp);
}

xmachine_message_loan_conditions * get_next_message_loan_conditions_in_range(xmachine_message_loan_conditions * current)
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_loan_conditions * get_first_loan_conditions_message()
 * \brief Get the first loan_conditions message in the loan_conditions message list.
 * \return The first message in the list.
 */
xmachine_message_loan_conditions * get_first_loan_conditions_message()
{
	return get_next_message_loan_conditions_in_range(*p_loan_conditions_message);
}

/** \fn xmachine_message_loan_conditions * get_next_loan_conditions_message(xmachine_message_loan_conditions * current)
 * \brief Get the next loan_conditions message in the loan_conditions message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_loan_conditions * get_next_loan_conditions_message(xmachine_message_loan_conditions * current)
{
	return get_next_message_loan_conditions_in_range(current->next);
}

/** \fn void freeloan_conditionsmessages()
 * \brief Free the loan_conditions message list.
 */
void freeloan_conditionsmessages()
{
	xmachine_message_loan_conditions * tmp, * head;
	head = *p_loan_conditions_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_loan_conditions_message = NULL;
}

/** \fn xmachine_message_loan_acceptance * add_loan_acceptance_message_internal()
 * \brief Add loan_acceptance message to the local message list.
 * \return The added message.
 */
xmachine_message_loan_acceptance * add_loan_acceptance_message_internal()
{
	xmachine_message_loan_acceptance * current = (xmachine_message_loan_acceptance *)malloc(sizeof(xmachine_message_loan_acceptance));
	CHECK_POINTER(current);

	current->next = *p_loan_acceptance_message;
	*p_loan_acceptance_message = current;
	
	return current;
}

/** \fn void process_loan_acceptance_message(xmachine_message_loan_acceptance * current)
 * \brief Process loan_acceptance message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_loan_acceptance_message(xmachine_message_loan_acceptance * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_loan_acceptance * temp_send_message;
	
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
				p_loan_acceptance_message = &node_info->loan_acceptance_messages;
				temp_send_message = add_loan_acceptance_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->bank_id = current->bank_id;
				temp_send_message->credit_amount_taken = current->credit_amount_taken;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_loan_acceptance_message = &current_node->loan_acceptance_messages;
	}
}

/** \fn void add_loan_acceptance_message(int firm_id, int bank_id, double credit_amount_taken, double range, double x, double y, double z)
 * \brief Add loan_acceptance message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param credit_amount_taken Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_loan_acceptance_message(int firm_id, int bank_id, double credit_amount_taken, double range, double x, double y, double z)
{

	p_loan_acceptance_message = &current_node->loan_acceptance_messages;
	xmachine_message_loan_acceptance * tmp = add_loan_acceptance_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->bank_id = bank_id;
	tmp->credit_amount_taken = credit_amount_taken;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_loan_acceptance_message(tmp);
}

xmachine_message_loan_acceptance * get_next_message_loan_acceptance_in_range(xmachine_message_loan_acceptance * current)
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_loan_acceptance * get_first_loan_acceptance_message()
 * \brief Get the first loan_acceptance message in the loan_acceptance message list.
 * \return The first message in the list.
 */
xmachine_message_loan_acceptance * get_first_loan_acceptance_message()
{
	return get_next_message_loan_acceptance_in_range(*p_loan_acceptance_message);
}

/** \fn xmachine_message_loan_acceptance * get_next_loan_acceptance_message(xmachine_message_loan_acceptance * current)
 * \brief Get the next loan_acceptance message in the loan_acceptance message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_loan_acceptance * get_next_loan_acceptance_message(xmachine_message_loan_acceptance * current)
{
	return get_next_message_loan_acceptance_in_range(current->next);
}

/** \fn void freeloan_acceptancemessages()
 * \brief Free the loan_acceptance message list.
 */
void freeloan_acceptancemessages()
{
	xmachine_message_loan_acceptance * tmp, * head;
	head = *p_loan_acceptance_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_loan_acceptance_message = NULL;
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
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
				temp_send_message->govbond_id = current->govbond_id;
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

/** \fn void add_gov_bond_order_message(int trader_id, int govbond_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
 * \brief Add gov_bond_order message by calling internal and processing.
 * \param trader_id Message variable.
 * \param govbond_id Message variable.
 * \param limit_price Message variable.
 * \param limit_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_gov_bond_order_message(int trader_id, int govbond_id, double limit_price, double limit_quantity, double range, double x, double y, double z)
{

	p_gov_bond_order_message = &current_node->gov_bond_order_messages;
	xmachine_message_gov_bond_order * tmp = add_gov_bond_order_message_internal();
	
	tmp->trader_id = trader_id;
	tmp->govbond_id = govbond_id;
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
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
				temp_send_message->govbond_id = current->govbond_id;
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

/** \fn void add_gov_bond_transaction_message(int trader_id, int govbond_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
 * \brief Add gov_bond_transaction message by calling internal and processing.
 * \param trader_id Message variable.
 * \param govbond_id Message variable.
 * \param transaction_price Message variable.
 * \param transaction_quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_gov_bond_transaction_message(int trader_id, int govbond_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z)
{

	p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
	xmachine_message_gov_bond_transaction * tmp = add_gov_bond_transaction_message_internal();
	
	tmp->trader_id = trader_id;
	tmp->govbond_id = govbond_id;
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
	if(current_xmachine->xmachine_Bank)
	{
		x = (double)current_xmachine->xmachine_Bank->posx;
		y = (double)current_xmachine->xmachine_Bank->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
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

