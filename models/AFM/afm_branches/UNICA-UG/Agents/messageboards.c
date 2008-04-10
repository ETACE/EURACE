/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn xmachine_message_order * add_order_message_internal()
 * \brief Add order message to the local message list.
 * \return The added message.
 */
xmachine_message_order * add_order_message_internal()
{
	xmachine_message_order * current = (xmachine_message_order *)malloc(sizeof(xmachine_message_order));
	CHECK_POINTER(current);

	current->next = *p_order_message;
	*p_order_message = current;
	
	return current;
}

/** \fn void process_order_message(xmachine_message_order * current)
 * \brief Process order message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_order_message(xmachine_message_order * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_order * temp_send_message;
	
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
				p_order_message = &node_info->order_messages;
				temp_send_message = add_order_message_internal();
				
				temp_send_message->issuer = current->issuer;
				temp_send_message->assetId = current->assetId;
				temp_send_message->limitPrice = current->limitPrice;
				temp_send_message->quantity = current->quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_order_message = &current_node->order_messages;
	}
}

/** \fn void add_order_message(int issuer, int assetId, double limitPrice, int quantity, double range, double x, double y, double z)
 * \brief Add order message by calling internal and processing.
 * \param issuer Message variable.
 * \param assetId Message variable.
 * \param limitPrice Message variable.
 * \param quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_order_message(int issuer, int assetId, double limitPrice, int quantity, double range, double x, double y, double z)
{

	p_order_message = &current_node->order_messages;
	xmachine_message_order * tmp = add_order_message_internal();
	
	tmp->issuer = issuer;
	tmp->assetId = assetId;
	tmp->limitPrice = limitPrice;
	tmp->quantity = quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_order_message(tmp);
}

xmachine_message_order * get_next_message_order_in_range(xmachine_message_order * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Eurostat)
	{
		x = (double)current_xmachine->xmachine_Eurostat->posx;
		y = (double)current_xmachine->xmachine_Eurostat->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouse)
	{
		x = (double)current_xmachine->xmachine_ClearingHouse->posx;
		y = (double)current_xmachine->xmachine_ClearingHouse->posy;
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

/** \fn xmachine_message_order * get_first_order_message()
 * \brief Get the first order message in the order message list.
 * \return The first message in the list.
 */
xmachine_message_order * get_first_order_message()
{
	return get_next_message_order_in_range(*p_order_message);
}

/** \fn xmachine_message_order * get_next_order_message(xmachine_message_order * current)
 * \brief Get the next order message in the order message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_order * get_next_order_message(xmachine_message_order * current)
{
	return get_next_message_order_in_range(current->next);
}

/** \fn void freeordermessages()
 * \brief Free the order message list.
 */
void freeordermessages()
{
	xmachine_message_order * tmp, * head;
	head = *p_order_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_order_message = NULL;
}

/** \fn xmachine_message_orderStatus * add_orderStatus_message_internal()
 * \brief Add orderStatus message to the local message list.
 * \return The added message.
 */
xmachine_message_orderStatus * add_orderStatus_message_internal()
{
	xmachine_message_orderStatus * current = (xmachine_message_orderStatus *)malloc(sizeof(xmachine_message_orderStatus));
	CHECK_POINTER(current);

	current->next = *p_orderStatus_message;
	*p_orderStatus_message = current;
	
	return current;
}

/** \fn void process_orderStatus_message(xmachine_message_orderStatus * current)
 * \brief Process orderStatus message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_orderStatus_message(xmachine_message_orderStatus * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_orderStatus * temp_send_message;
	
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
				p_orderStatus_message = &node_info->orderStatus_messages;
				temp_send_message = add_orderStatus_message_internal();
				
				temp_send_message->issuer = current->issuer;
				temp_send_message->assetId = current->assetId;
				temp_send_message->price = current->price;
				temp_send_message->quantity = current->quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_orderStatus_message = &current_node->orderStatus_messages;
	}
}

/** \fn void add_orderStatus_message(int issuer, int assetId, double price, int quantity, double range, double x, double y, double z)
 * \brief Add orderStatus message by calling internal and processing.
 * \param issuer Message variable.
 * \param assetId Message variable.
 * \param price Message variable.
 * \param quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_orderStatus_message(int issuer, int assetId, double price, int quantity, double range, double x, double y, double z)
{

	p_orderStatus_message = &current_node->orderStatus_messages;
	xmachine_message_orderStatus * tmp = add_orderStatus_message_internal();
	
	tmp->issuer = issuer;
	tmp->assetId = assetId;
	tmp->price = price;
	tmp->quantity = quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_orderStatus_message(tmp);
}

xmachine_message_orderStatus * get_next_message_orderStatus_in_range(xmachine_message_orderStatus * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Eurostat)
	{
		x = (double)current_xmachine->xmachine_Eurostat->posx;
		y = (double)current_xmachine->xmachine_Eurostat->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouse)
	{
		x = (double)current_xmachine->xmachine_ClearingHouse->posx;
		y = (double)current_xmachine->xmachine_ClearingHouse->posy;
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

/** \fn xmachine_message_orderStatus * get_first_orderStatus_message()
 * \brief Get the first orderStatus message in the orderStatus message list.
 * \return The first message in the list.
 */
xmachine_message_orderStatus * get_first_orderStatus_message()
{
	return get_next_message_orderStatus_in_range(*p_orderStatus_message);
}

/** \fn xmachine_message_orderStatus * get_next_orderStatus_message(xmachine_message_orderStatus * current)
 * \brief Get the next orderStatus message in the orderStatus message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_orderStatus * get_next_orderStatus_message(xmachine_message_orderStatus * current)
{
	return get_next_message_orderStatus_in_range(current->next);
}

/** \fn void freeorderStatusmessages()
 * \brief Free the orderStatus message list.
 */
void freeorderStatusmessages()
{
	xmachine_message_orderStatus * tmp, * head;
	head = *p_orderStatus_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_orderStatus_message = NULL;
}

/** \fn xmachine_message_asset * add_asset_message_internal()
 * \brief Add asset message to the local message list.
 * \return The added message.
 */
xmachine_message_asset * add_asset_message_internal()
{
	xmachine_message_asset * current = (xmachine_message_asset *)malloc(sizeof(xmachine_message_asset));
	CHECK_POINTER(current);

	current->next = *p_asset_message;
	*p_asset_message = current;
	
	return current;
}

/** \fn void process_asset_message(xmachine_message_asset * current)
 * \brief Process asset message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_asset_message(xmachine_message_asset * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_asset * temp_send_message;
	
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
				p_asset_message = &node_info->asset_messages;
				temp_send_message = add_asset_message_internal();
				
				temp_send_message->issuer = current->issuer;
				temp_send_message->price = current->price;
				temp_send_message->quantity = current->quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_asset_message = &current_node->asset_messages;
	}
}

/** \fn void add_asset_message(int issuer, double price, int quantity, double range, double x, double y, double z)
 * \brief Add asset message by calling internal and processing.
 * \param issuer Message variable.
 * \param price Message variable.
 * \param quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_asset_message(int issuer, double price, int quantity, double range, double x, double y, double z)
{

	p_asset_message = &current_node->asset_messages;
	xmachine_message_asset * tmp = add_asset_message_internal();
	
	tmp->issuer = issuer;
	tmp->price = price;
	tmp->quantity = quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_asset_message(tmp);
}

xmachine_message_asset * get_next_message_asset_in_range(xmachine_message_asset * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Eurostat)
	{
		x = (double)current_xmachine->xmachine_Eurostat->posx;
		y = (double)current_xmachine->xmachine_Eurostat->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouse)
	{
		x = (double)current_xmachine->xmachine_ClearingHouse->posx;
		y = (double)current_xmachine->xmachine_ClearingHouse->posy;
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

/** \fn xmachine_message_asset * get_first_asset_message()
 * \brief Get the first asset message in the asset message list.
 * \return The first message in the list.
 */
xmachine_message_asset * get_first_asset_message()
{
	return get_next_message_asset_in_range(*p_asset_message);
}

/** \fn xmachine_message_asset * get_next_asset_message(xmachine_message_asset * current)
 * \brief Get the next asset message in the asset message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_asset * get_next_asset_message(xmachine_message_asset * current)
{
	return get_next_message_asset_in_range(current->next);
}

/** \fn void freeassetmessages()
 * \brief Free the asset message list.
 */
void freeassetmessages()
{
	xmachine_message_asset * tmp, * head;
	head = *p_asset_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_asset_message = NULL;
}

/** \fn xmachine_message_infoAsset * add_infoAsset_message_internal()
 * \brief Add infoAsset message to the local message list.
 * \return The added message.
 */
xmachine_message_infoAsset * add_infoAsset_message_internal()
{
	xmachine_message_infoAsset * current = (xmachine_message_infoAsset *)malloc(sizeof(xmachine_message_infoAsset));
	CHECK_POINTER(current);

	current->next = *p_infoAsset_message;
	*p_infoAsset_message = current;
	
	return current;
}

/** \fn void process_infoAsset_message(xmachine_message_infoAsset * current)
 * \brief Process infoAsset message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_infoAsset_message(xmachine_message_infoAsset * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_infoAsset * temp_send_message;
	
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
				p_infoAsset_message = &node_info->infoAsset_messages;
				temp_send_message = add_infoAsset_message_internal();
				
				temp_send_message->issuer = current->issuer;
				temp_send_message->price = current->price;
				temp_send_message->quantity = current->quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_infoAsset_message = &current_node->infoAsset_messages;
	}
}

/** \fn void add_infoAsset_message(int issuer, double price, int quantity, double range, double x, double y, double z)
 * \brief Add infoAsset message by calling internal and processing.
 * \param issuer Message variable.
 * \param price Message variable.
 * \param quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_infoAsset_message(int issuer, double price, int quantity, double range, double x, double y, double z)
{

	p_infoAsset_message = &current_node->infoAsset_messages;
	xmachine_message_infoAsset * tmp = add_infoAsset_message_internal();
	
	tmp->issuer = issuer;
	tmp->price = price;
	tmp->quantity = quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_infoAsset_message(tmp);
}

xmachine_message_infoAsset * get_next_message_infoAsset_in_range(xmachine_message_infoAsset * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Eurostat)
	{
		x = (double)current_xmachine->xmachine_Eurostat->posx;
		y = (double)current_xmachine->xmachine_Eurostat->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_ClearingHouse)
	{
		x = (double)current_xmachine->xmachine_ClearingHouse->posx;
		y = (double)current_xmachine->xmachine_ClearingHouse->posy;
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

/** \fn xmachine_message_infoAsset * get_first_infoAsset_message()
 * \brief Get the first infoAsset message in the infoAsset message list.
 * \return The first message in the list.
 */
xmachine_message_infoAsset * get_first_infoAsset_message()
{
	return get_next_message_infoAsset_in_range(*p_infoAsset_message);
}

/** \fn xmachine_message_infoAsset * get_next_infoAsset_message(xmachine_message_infoAsset * current)
 * \brief Get the next infoAsset message in the infoAsset message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_infoAsset * get_next_infoAsset_message(xmachine_message_infoAsset * current)
{
	return get_next_message_infoAsset_in_range(current->next);
}

/** \fn void freeinfoAssetmessages()
 * \brief Free the infoAsset message list.
 */
void freeinfoAssetmessages()
{
	xmachine_message_infoAsset * tmp, * head;
	head = *p_infoAsset_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_infoAsset_message = NULL;
}

