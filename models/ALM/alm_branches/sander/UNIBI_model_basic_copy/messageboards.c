/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn xmachine_message_vacancies * add_vacancies_message_internal()
 * \brief Add vacancies message to the local message list.
 * \return The added message.
 */
xmachine_message_vacancies * add_vacancies_message_internal()
{
	xmachine_message_vacancies * current = (xmachine_message_vacancies *)malloc(sizeof(xmachine_message_vacancies));
	CHECK_POINTER(current);

	current->next = *p_vacancies_message;
	*p_vacancies_message = current;
	
	return current;
}

/** \fn void process_vacancies_message(xmachine_message_vacancies * current)
 * \brief Process vacancies message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_vacancies_message(xmachine_message_vacancies * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_vacancies * temp_send_message;
	
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
				p_vacancies_message = &node_info->vacancies_messages;
				temp_send_message = add_vacancies_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->firm_vacancies = current->firm_vacancies;
				temp_send_message->skill_group = current->skill_group;
				temp_send_message->firm_wage_offer = current->firm_wage_offer;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_vacancies_message = &current_node->vacancies_messages;
	}
}

/** \fn void add_vacancies_message(int firm_id, int region_id, int firm_vacancies, int skill_group, double firm_wage_offer, double range, double x, double y, double z)
 * \brief Add vacancies message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param firm_vacancies Message variable.
 * \param skill_group Message variable.
 * \param firm_wage_offer Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_vacancies_message(int firm_id, int region_id, int firm_vacancies, int skill_group, double firm_wage_offer, double range, double x, double y, double z)
{

	p_vacancies_message = &current_node->vacancies_messages;
	xmachine_message_vacancies * tmp = add_vacancies_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->region_id = region_id;
	tmp->firm_vacancies = firm_vacancies;
	tmp->skill_group = skill_group;
	tmp->firm_wage_offer = firm_wage_offer;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_vacancies_message(tmp);
}

xmachine_message_vacancies * get_next_message_vacancies_in_range(xmachine_message_vacancies * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_vacancies * get_first_vacancies_message()
 * \brief Get the first vacancies message in the vacancies message list.
 * \return The first message in the list.
 */
xmachine_message_vacancies * get_first_vacancies_message()
{
	return get_next_message_vacancies_in_range(*p_vacancies_message);
}

/** \fn xmachine_message_vacancies * get_next_vacancies_message(xmachine_message_vacancies * current)
 * \brief Get the next vacancies message in the vacancies message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_vacancies * get_next_vacancies_message(xmachine_message_vacancies * current)
{
	return get_next_message_vacancies_in_range(current->next);
}

/** \fn void freevacanciesmessages()
 * \brief Free the vacancies message list.
 */
void freevacanciesmessages()
{
	xmachine_message_vacancies * tmp, * head;
	head = *p_vacancies_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_vacancies_message = NULL;
}

/** \fn xmachine_message_vacancies2 * add_vacancies2_message_internal()
 * \brief Add vacancies2 message to the local message list.
 * \return The added message.
 */
xmachine_message_vacancies2 * add_vacancies2_message_internal()
{
	xmachine_message_vacancies2 * current = (xmachine_message_vacancies2 *)malloc(sizeof(xmachine_message_vacancies2));
	CHECK_POINTER(current);

	current->next = *p_vacancies2_message;
	*p_vacancies2_message = current;
	
	return current;
}

/** \fn void process_vacancies2_message(xmachine_message_vacancies2 * current)
 * \brief Process vacancies2 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_vacancies2_message(xmachine_message_vacancies2 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_vacancies2 * temp_send_message;
	
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
				p_vacancies2_message = &node_info->vacancies2_messages;
				temp_send_message = add_vacancies2_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->firm_vacancies = current->firm_vacancies;
				temp_send_message->skill_group = current->skill_group;
				temp_send_message->firm_wage_offer = current->firm_wage_offer;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_vacancies2_message = &current_node->vacancies2_messages;
	}
}

/** \fn void add_vacancies2_message(int firm_id, int region_id, int firm_vacancies, int skill_group, double firm_wage_offer, double range, double x, double y, double z)
 * \brief Add vacancies2 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param firm_vacancies Message variable.
 * \param skill_group Message variable.
 * \param firm_wage_offer Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_vacancies2_message(int firm_id, int region_id, int firm_vacancies, int skill_group, double firm_wage_offer, double range, double x, double y, double z)
{

	p_vacancies2_message = &current_node->vacancies2_messages;
	xmachine_message_vacancies2 * tmp = add_vacancies2_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->region_id = region_id;
	tmp->firm_vacancies = firm_vacancies;
	tmp->skill_group = skill_group;
	tmp->firm_wage_offer = firm_wage_offer;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_vacancies2_message(tmp);
}

xmachine_message_vacancies2 * get_next_message_vacancies2_in_range(xmachine_message_vacancies2 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_vacancies2 * get_first_vacancies2_message()
 * \brief Get the first vacancies2 message in the vacancies2 message list.
 * \return The first message in the list.
 */
xmachine_message_vacancies2 * get_first_vacancies2_message()
{
	return get_next_message_vacancies2_in_range(*p_vacancies2_message);
}

/** \fn xmachine_message_vacancies2 * get_next_vacancies2_message(xmachine_message_vacancies2 * current)
 * \brief Get the next vacancies2 message in the vacancies2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_vacancies2 * get_next_vacancies2_message(xmachine_message_vacancies2 * current)
{
	return get_next_message_vacancies2_in_range(current->next);
}

/** \fn void freevacancies2messages()
 * \brief Free the vacancies2 message list.
 */
void freevacancies2messages()
{
	xmachine_message_vacancies2 * tmp, * head;
	head = *p_vacancies2_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_vacancies2_message = NULL;
}

/** \fn xmachine_message_firing * add_firing_message_internal()
 * \brief Add firing message to the local message list.
 * \return The added message.
 */
xmachine_message_firing * add_firing_message_internal()
{
	xmachine_message_firing * current = (xmachine_message_firing *)malloc(sizeof(xmachine_message_firing));
	CHECK_POINTER(current);

	current->next = *p_firing_message;
	*p_firing_message = current;
	
	return current;
}

/** \fn void process_firing_message(xmachine_message_firing * current)
 * \brief Process firing message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_firing_message(xmachine_message_firing * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_firing * temp_send_message;
	
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
				p_firing_message = &node_info->firing_messages;
				temp_send_message = add_firing_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_firing_message = &current_node->firing_messages;
	}
}

/** \fn void add_firing_message(int firm_id, int worker_id, double range, double x, double y, double z)
 * \brief Add firing message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_firing_message(int firm_id, int worker_id, double range, double x, double y, double z)
{

	p_firing_message = &current_node->firing_messages;
	xmachine_message_firing * tmp = add_firing_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->worker_id = worker_id;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_firing_message(tmp);
}

xmachine_message_firing * get_next_message_firing_in_range(xmachine_message_firing * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_firing * get_first_firing_message()
 * \brief Get the first firing message in the firing message list.
 * \return The first message in the list.
 */
xmachine_message_firing * get_first_firing_message()
{
	return get_next_message_firing_in_range(*p_firing_message);
}

/** \fn xmachine_message_firing * get_next_firing_message(xmachine_message_firing * current)
 * \brief Get the next firing message in the firing message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_firing * get_next_firing_message(xmachine_message_firing * current)
{
	return get_next_message_firing_in_range(current->next);
}

/** \fn void freefiringmessages()
 * \brief Free the firing message list.
 */
void freefiringmessages()
{
	xmachine_message_firing * tmp, * head;
	head = *p_firing_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_firing_message = NULL;
}

/** \fn xmachine_message_job_application * add_job_application_message_internal()
 * \brief Add job_application message to the local message list.
 * \return The added message.
 */
xmachine_message_job_application * add_job_application_message_internal()
{
	xmachine_message_job_application * current = (xmachine_message_job_application *)malloc(sizeof(xmachine_message_job_application));
	CHECK_POINTER(current);

	current->next = *p_job_application_message;
	*p_job_application_message = current;
	
	return current;
}

/** \fn void process_job_application_message(xmachine_message_job_application * current)
 * \brief Process job_application message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_job_application_message(xmachine_message_job_application * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_job_application * temp_send_message;
	
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
				p_job_application_message = &node_info->job_application_messages;
				temp_send_message = add_job_application_message_internal();
				
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->general_skill = current->general_skill;
				temp_send_message->specific_skill = current->specific_skill;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_job_application_message = &current_node->job_application_messages;
	}
}

/** \fn void add_job_application_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z)
 * \brief Add job_application message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_job_application_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z)
{

	p_job_application_message = &current_node->job_application_messages;
	xmachine_message_job_application * tmp = add_job_application_message_internal();
	
	tmp->worker_id = worker_id;
	tmp->firm_id = firm_id;
	tmp->region_id = region_id;
	tmp->general_skill = general_skill;
	tmp->specific_skill = specific_skill;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_job_application_message(tmp);
}

xmachine_message_job_application * get_next_message_job_application_in_range(xmachine_message_job_application * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_job_application * get_first_job_application_message()
 * \brief Get the first job_application message in the job_application message list.
 * \return The first message in the list.
 */
xmachine_message_job_application * get_first_job_application_message()
{
	return get_next_message_job_application_in_range(*p_job_application_message);
}

/** \fn xmachine_message_job_application * get_next_job_application_message(xmachine_message_job_application * current)
 * \brief Get the next job_application message in the job_application message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_job_application * get_next_job_application_message(xmachine_message_job_application * current)
{
	return get_next_message_job_application_in_range(current->next);
}

/** \fn void freejob_applicationmessages()
 * \brief Free the job_application message list.
 */
void freejob_applicationmessages()
{
	xmachine_message_job_application * tmp, * head;
	head = *p_job_application_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_job_application_message = NULL;
}

/** \fn xmachine_message_job_application2 * add_job_application2_message_internal()
 * \brief Add job_application2 message to the local message list.
 * \return The added message.
 */
xmachine_message_job_application2 * add_job_application2_message_internal()
{
	xmachine_message_job_application2 * current = (xmachine_message_job_application2 *)malloc(sizeof(xmachine_message_job_application2));
	CHECK_POINTER(current);

	current->next = *p_job_application2_message;
	*p_job_application2_message = current;
	
	return current;
}

/** \fn void process_job_application2_message(xmachine_message_job_application2 * current)
 * \brief Process job_application2 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_job_application2_message(xmachine_message_job_application2 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_job_application2 * temp_send_message;
	
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
				p_job_application2_message = &node_info->job_application2_messages;
				temp_send_message = add_job_application2_message_internal();
				
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->general_skill = current->general_skill;
				temp_send_message->specific_skill = current->specific_skill;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_job_application2_message = &current_node->job_application2_messages;
	}
}

/** \fn void add_job_application2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z)
 * \brief Add job_application2 message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_job_application2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z)
{

	p_job_application2_message = &current_node->job_application2_messages;
	xmachine_message_job_application2 * tmp = add_job_application2_message_internal();
	
	tmp->worker_id = worker_id;
	tmp->firm_id = firm_id;
	tmp->region_id = region_id;
	tmp->general_skill = general_skill;
	tmp->specific_skill = specific_skill;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_job_application2_message(tmp);
}

xmachine_message_job_application2 * get_next_message_job_application2_in_range(xmachine_message_job_application2 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_job_application2 * get_first_job_application2_message()
 * \brief Get the first job_application2 message in the job_application2 message list.
 * \return The first message in the list.
 */
xmachine_message_job_application2 * get_first_job_application2_message()
{
	return get_next_message_job_application2_in_range(*p_job_application2_message);
}

/** \fn xmachine_message_job_application2 * get_next_job_application2_message(xmachine_message_job_application2 * current)
 * \brief Get the next job_application2 message in the job_application2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_job_application2 * get_next_job_application2_message(xmachine_message_job_application2 * current)
{
	return get_next_message_job_application2_in_range(current->next);
}

/** \fn void freejob_application2messages()
 * \brief Free the job_application2 message list.
 */
void freejob_application2messages()
{
	xmachine_message_job_application2 * tmp, * head;
	head = *p_job_application2_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_job_application2_message = NULL;
}

/** \fn xmachine_message_job_offer * add_job_offer_message_internal()
 * \brief Add job_offer message to the local message list.
 * \return The added message.
 */
xmachine_message_job_offer * add_job_offer_message_internal()
{
	xmachine_message_job_offer * current = (xmachine_message_job_offer *)malloc(sizeof(xmachine_message_job_offer));
	CHECK_POINTER(current);

	current->next = *p_job_offer_message;
	*p_job_offer_message = current;
	
	return current;
}

/** \fn void process_job_offer_message(xmachine_message_job_offer * current)
 * \brief Process job_offer message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_job_offer_message(xmachine_message_job_offer * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_job_offer * temp_send_message;
	
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
				p_job_offer_message = &node_info->job_offer_messages;
				temp_send_message = add_job_offer_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->wage_offer = current->wage_offer;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_job_offer_message = &current_node->job_offer_messages;
	}
}

/** \fn void add_job_offer_message(int firm_id, int worker_id, int region_id, double wage_offer, double range, double x, double y, double z)
 * \brief Add job_offer message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param wage_offer Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_job_offer_message(int firm_id, int worker_id, int region_id, double wage_offer, double range, double x, double y, double z)
{

	p_job_offer_message = &current_node->job_offer_messages;
	xmachine_message_job_offer * tmp = add_job_offer_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->worker_id = worker_id;
	tmp->region_id = region_id;
	tmp->wage_offer = wage_offer;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_job_offer_message(tmp);
}

xmachine_message_job_offer * get_next_message_job_offer_in_range(xmachine_message_job_offer * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_job_offer * get_first_job_offer_message()
 * \brief Get the first job_offer message in the job_offer message list.
 * \return The first message in the list.
 */
xmachine_message_job_offer * get_first_job_offer_message()
{
	return get_next_message_job_offer_in_range(*p_job_offer_message);
}

/** \fn xmachine_message_job_offer * get_next_job_offer_message(xmachine_message_job_offer * current)
 * \brief Get the next job_offer message in the job_offer message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_job_offer * get_next_job_offer_message(xmachine_message_job_offer * current)
{
	return get_next_message_job_offer_in_range(current->next);
}

/** \fn void freejob_offermessages()
 * \brief Free the job_offer message list.
 */
void freejob_offermessages()
{
	xmachine_message_job_offer * tmp, * head;
	head = *p_job_offer_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_job_offer_message = NULL;
}

/** \fn xmachine_message_job_offer2 * add_job_offer2_message_internal()
 * \brief Add job_offer2 message to the local message list.
 * \return The added message.
 */
xmachine_message_job_offer2 * add_job_offer2_message_internal()
{
	xmachine_message_job_offer2 * current = (xmachine_message_job_offer2 *)malloc(sizeof(xmachine_message_job_offer2));
	CHECK_POINTER(current);

	current->next = *p_job_offer2_message;
	*p_job_offer2_message = current;
	
	return current;
}

/** \fn void process_job_offer2_message(xmachine_message_job_offer2 * current)
 * \brief Process job_offer2 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_job_offer2_message(xmachine_message_job_offer2 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_job_offer2 * temp_send_message;
	
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
				p_job_offer2_message = &node_info->job_offer2_messages;
				temp_send_message = add_job_offer2_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->wage_offer = current->wage_offer;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_job_offer2_message = &current_node->job_offer2_messages;
	}
}

/** \fn void add_job_offer2_message(int firm_id, int worker_id, int region_id, double wage_offer, double range, double x, double y, double z)
 * \brief Add job_offer2 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param wage_offer Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_job_offer2_message(int firm_id, int worker_id, int region_id, double wage_offer, double range, double x, double y, double z)
{

	p_job_offer2_message = &current_node->job_offer2_messages;
	xmachine_message_job_offer2 * tmp = add_job_offer2_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->worker_id = worker_id;
	tmp->region_id = region_id;
	tmp->wage_offer = wage_offer;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_job_offer2_message(tmp);
}

xmachine_message_job_offer2 * get_next_message_job_offer2_in_range(xmachine_message_job_offer2 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_job_offer2 * get_first_job_offer2_message()
 * \brief Get the first job_offer2 message in the job_offer2 message list.
 * \return The first message in the list.
 */
xmachine_message_job_offer2 * get_first_job_offer2_message()
{
	return get_next_message_job_offer2_in_range(*p_job_offer2_message);
}

/** \fn xmachine_message_job_offer2 * get_next_job_offer2_message(xmachine_message_job_offer2 * current)
 * \brief Get the next job_offer2 message in the job_offer2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_job_offer2 * get_next_job_offer2_message(xmachine_message_job_offer2 * current)
{
	return get_next_message_job_offer2_in_range(current->next);
}

/** \fn void freejob_offer2messages()
 * \brief Free the job_offer2 message list.
 */
void freejob_offer2messages()
{
	xmachine_message_job_offer2 * tmp, * head;
	head = *p_job_offer2_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_job_offer2_message = NULL;
}

/** \fn xmachine_message_job_acceptance * add_job_acceptance_message_internal()
 * \brief Add job_acceptance message to the local message list.
 * \return The added message.
 */
xmachine_message_job_acceptance * add_job_acceptance_message_internal()
{
	xmachine_message_job_acceptance * current = (xmachine_message_job_acceptance *)malloc(sizeof(xmachine_message_job_acceptance));
	CHECK_POINTER(current);

	current->next = *p_job_acceptance_message;
	*p_job_acceptance_message = current;
	
	return current;
}

/** \fn void process_job_acceptance_message(xmachine_message_job_acceptance * current)
 * \brief Process job_acceptance message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_job_acceptance_message(xmachine_message_job_acceptance * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_job_acceptance * temp_send_message;
	
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
				p_job_acceptance_message = &node_info->job_acceptance_messages;
				temp_send_message = add_job_acceptance_message_internal();
				
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->general_skill = current->general_skill;
				temp_send_message->specific_skill = current->specific_skill;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_job_acceptance_message = &current_node->job_acceptance_messages;
	}
}

/** \fn void add_job_acceptance_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z)
 * \brief Add job_acceptance message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_job_acceptance_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z)
{

	p_job_acceptance_message = &current_node->job_acceptance_messages;
	xmachine_message_job_acceptance * tmp = add_job_acceptance_message_internal();
	
	tmp->worker_id = worker_id;
	tmp->firm_id = firm_id;
	tmp->region_id = region_id;
	tmp->general_skill = general_skill;
	tmp->specific_skill = specific_skill;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_job_acceptance_message(tmp);
}

xmachine_message_job_acceptance * get_next_message_job_acceptance_in_range(xmachine_message_job_acceptance * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_job_acceptance * get_first_job_acceptance_message()
 * \brief Get the first job_acceptance message in the job_acceptance message list.
 * \return The first message in the list.
 */
xmachine_message_job_acceptance * get_first_job_acceptance_message()
{
	return get_next_message_job_acceptance_in_range(*p_job_acceptance_message);
}

/** \fn xmachine_message_job_acceptance * get_next_job_acceptance_message(xmachine_message_job_acceptance * current)
 * \brief Get the next job_acceptance message in the job_acceptance message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_job_acceptance * get_next_job_acceptance_message(xmachine_message_job_acceptance * current)
{
	return get_next_message_job_acceptance_in_range(current->next);
}

/** \fn void freejob_acceptancemessages()
 * \brief Free the job_acceptance message list.
 */
void freejob_acceptancemessages()
{
	xmachine_message_job_acceptance * tmp, * head;
	head = *p_job_acceptance_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_job_acceptance_message = NULL;
}

/** \fn xmachine_message_job_acceptance2 * add_job_acceptance2_message_internal()
 * \brief Add job_acceptance2 message to the local message list.
 * \return The added message.
 */
xmachine_message_job_acceptance2 * add_job_acceptance2_message_internal()
{
	xmachine_message_job_acceptance2 * current = (xmachine_message_job_acceptance2 *)malloc(sizeof(xmachine_message_job_acceptance2));
	CHECK_POINTER(current);

	current->next = *p_job_acceptance2_message;
	*p_job_acceptance2_message = current;
	
	return current;
}

/** \fn void process_job_acceptance2_message(xmachine_message_job_acceptance2 * current)
 * \brief Process job_acceptance2 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_job_acceptance2_message(xmachine_message_job_acceptance2 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_job_acceptance2 * temp_send_message;
	
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
				p_job_acceptance2_message = &node_info->job_acceptance2_messages;
				temp_send_message = add_job_acceptance2_message_internal();
				
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->general_skill = current->general_skill;
				temp_send_message->specific_skill = current->specific_skill;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_job_acceptance2_message = &current_node->job_acceptance2_messages;
	}
}

/** \fn void add_job_acceptance2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z)
 * \brief Add job_acceptance2 message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_job_acceptance2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z)
{

	p_job_acceptance2_message = &current_node->job_acceptance2_messages;
	xmachine_message_job_acceptance2 * tmp = add_job_acceptance2_message_internal();
	
	tmp->worker_id = worker_id;
	tmp->firm_id = firm_id;
	tmp->region_id = region_id;
	tmp->general_skill = general_skill;
	tmp->specific_skill = specific_skill;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_job_acceptance2_message(tmp);
}

xmachine_message_job_acceptance2 * get_next_message_job_acceptance2_in_range(xmachine_message_job_acceptance2 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_job_acceptance2 * get_first_job_acceptance2_message()
 * \brief Get the first job_acceptance2 message in the job_acceptance2 message list.
 * \return The first message in the list.
 */
xmachine_message_job_acceptance2 * get_first_job_acceptance2_message()
{
	return get_next_message_job_acceptance2_in_range(*p_job_acceptance2_message);
}

/** \fn xmachine_message_job_acceptance2 * get_next_job_acceptance2_message(xmachine_message_job_acceptance2 * current)
 * \brief Get the next job_acceptance2 message in the job_acceptance2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_job_acceptance2 * get_next_job_acceptance2_message(xmachine_message_job_acceptance2 * current)
{
	return get_next_message_job_acceptance2_in_range(current->next);
}

/** \fn void freejob_acceptance2messages()
 * \brief Free the job_acceptance2 message list.
 */
void freejob_acceptance2messages()
{
	xmachine_message_job_acceptance2 * tmp, * head;
	head = *p_job_acceptance2_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_job_acceptance2_message = NULL;
}

/** \fn xmachine_message_application_rejection * add_application_rejection_message_internal()
 * \brief Add application_rejection message to the local message list.
 * \return The added message.
 */
xmachine_message_application_rejection * add_application_rejection_message_internal()
{
	xmachine_message_application_rejection * current = (xmachine_message_application_rejection *)malloc(sizeof(xmachine_message_application_rejection));
	CHECK_POINTER(current);

	current->next = *p_application_rejection_message;
	*p_application_rejection_message = current;
	
	return current;
}

/** \fn void process_application_rejection_message(xmachine_message_application_rejection * current)
 * \brief Process application_rejection message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_application_rejection_message(xmachine_message_application_rejection * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_application_rejection * temp_send_message;
	
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
				p_application_rejection_message = &node_info->application_rejection_messages;
				temp_send_message = add_application_rejection_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_application_rejection_message = &current_node->application_rejection_messages;
	}
}

/** \fn void add_application_rejection_message(int firm_id, int worker_id, double range, double x, double y, double z)
 * \brief Add application_rejection message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_application_rejection_message(int firm_id, int worker_id, double range, double x, double y, double z)
{

	p_application_rejection_message = &current_node->application_rejection_messages;
	xmachine_message_application_rejection * tmp = add_application_rejection_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->worker_id = worker_id;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_application_rejection_message(tmp);
}

xmachine_message_application_rejection * get_next_message_application_rejection_in_range(xmachine_message_application_rejection * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_application_rejection * get_first_application_rejection_message()
 * \brief Get the first application_rejection message in the application_rejection message list.
 * \return The first message in the list.
 */
xmachine_message_application_rejection * get_first_application_rejection_message()
{
	return get_next_message_application_rejection_in_range(*p_application_rejection_message);
}

/** \fn xmachine_message_application_rejection * get_next_application_rejection_message(xmachine_message_application_rejection * current)
 * \brief Get the next application_rejection message in the application_rejection message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_application_rejection * get_next_application_rejection_message(xmachine_message_application_rejection * current)
{
	return get_next_message_application_rejection_in_range(current->next);
}

/** \fn void freeapplication_rejectionmessages()
 * \brief Free the application_rejection message list.
 */
void freeapplication_rejectionmessages()
{
	xmachine_message_application_rejection * tmp, * head;
	head = *p_application_rejection_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_application_rejection_message = NULL;
}

/** \fn xmachine_message_application_rejection2 * add_application_rejection2_message_internal()
 * \brief Add application_rejection2 message to the local message list.
 * \return The added message.
 */
xmachine_message_application_rejection2 * add_application_rejection2_message_internal()
{
	xmachine_message_application_rejection2 * current = (xmachine_message_application_rejection2 *)malloc(sizeof(xmachine_message_application_rejection2));
	CHECK_POINTER(current);

	current->next = *p_application_rejection2_message;
	*p_application_rejection2_message = current;
	
	return current;
}

/** \fn void process_application_rejection2_message(xmachine_message_application_rejection2 * current)
 * \brief Process application_rejection2 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_application_rejection2_message(xmachine_message_application_rejection2 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_application_rejection2 * temp_send_message;
	
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
				p_application_rejection2_message = &node_info->application_rejection2_messages;
				temp_send_message = add_application_rejection2_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_application_rejection2_message = &current_node->application_rejection2_messages;
	}
}

/** \fn void add_application_rejection2_message(int firm_id, int worker_id, double range, double x, double y, double z)
 * \brief Add application_rejection2 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_application_rejection2_message(int firm_id, int worker_id, double range, double x, double y, double z)
{

	p_application_rejection2_message = &current_node->application_rejection2_messages;
	xmachine_message_application_rejection2 * tmp = add_application_rejection2_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->worker_id = worker_id;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_application_rejection2_message(tmp);
}

xmachine_message_application_rejection2 * get_next_message_application_rejection2_in_range(xmachine_message_application_rejection2 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_application_rejection2 * get_first_application_rejection2_message()
 * \brief Get the first application_rejection2 message in the application_rejection2 message list.
 * \return The first message in the list.
 */
xmachine_message_application_rejection2 * get_first_application_rejection2_message()
{
	return get_next_message_application_rejection2_in_range(*p_application_rejection2_message);
}

/** \fn xmachine_message_application_rejection2 * get_next_application_rejection2_message(xmachine_message_application_rejection2 * current)
 * \brief Get the next application_rejection2 message in the application_rejection2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_application_rejection2 * get_next_application_rejection2_message(xmachine_message_application_rejection2 * current)
{
	return get_next_message_application_rejection2_in_range(current->next);
}

/** \fn void freeapplication_rejection2messages()
 * \brief Free the application_rejection2 message list.
 */
void freeapplication_rejection2messages()
{
	xmachine_message_application_rejection2 * tmp, * head;
	head = *p_application_rejection2_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_application_rejection2_message = NULL;
}

/** \fn xmachine_message_quitting * add_quitting_message_internal()
 * \brief Add quitting message to the local message list.
 * \return The added message.
 */
xmachine_message_quitting * add_quitting_message_internal()
{
	xmachine_message_quitting * current = (xmachine_message_quitting *)malloc(sizeof(xmachine_message_quitting));
	CHECK_POINTER(current);

	current->next = *p_quitting_message;
	*p_quitting_message = current;
	
	return current;
}

/** \fn void process_quitting_message(xmachine_message_quitting * current)
 * \brief Process quitting message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_quitting_message(xmachine_message_quitting * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_quitting * temp_send_message;
	
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
				p_quitting_message = &node_info->quitting_messages;
				temp_send_message = add_quitting_message_internal();
				
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_quitting_message = &current_node->quitting_messages;
	}
}

/** \fn void add_quitting_message(int worker_id, int firm_id, double range, double x, double y, double z)
 * \brief Add quitting message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_quitting_message(int worker_id, int firm_id, double range, double x, double y, double z)
{

	p_quitting_message = &current_node->quitting_messages;
	xmachine_message_quitting * tmp = add_quitting_message_internal();
	
	tmp->worker_id = worker_id;
	tmp->firm_id = firm_id;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_quitting_message(tmp);
}

xmachine_message_quitting * get_next_message_quitting_in_range(xmachine_message_quitting * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_quitting * get_first_quitting_message()
 * \brief Get the first quitting message in the quitting message list.
 * \return The first message in the list.
 */
xmachine_message_quitting * get_first_quitting_message()
{
	return get_next_message_quitting_in_range(*p_quitting_message);
}

/** \fn xmachine_message_quitting * get_next_quitting_message(xmachine_message_quitting * current)
 * \brief Get the next quitting message in the quitting message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_quitting * get_next_quitting_message(xmachine_message_quitting * current)
{
	return get_next_message_quitting_in_range(current->next);
}

/** \fn void freequittingmessages()
 * \brief Free the quitting message list.
 */
void freequittingmessages()
{
	xmachine_message_quitting * tmp, * head;
	head = *p_quitting_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_quitting_message = NULL;
}

/** \fn xmachine_message_quitting2 * add_quitting2_message_internal()
 * \brief Add quitting2 message to the local message list.
 * \return The added message.
 */
xmachine_message_quitting2 * add_quitting2_message_internal()
{
	xmachine_message_quitting2 * current = (xmachine_message_quitting2 *)malloc(sizeof(xmachine_message_quitting2));
	CHECK_POINTER(current);

	current->next = *p_quitting2_message;
	*p_quitting2_message = current;
	
	return current;
}

/** \fn void process_quitting2_message(xmachine_message_quitting2 * current)
 * \brief Process quitting2 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_quitting2_message(xmachine_message_quitting2 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_quitting2 * temp_send_message;
	
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
				p_quitting2_message = &node_info->quitting2_messages;
				temp_send_message = add_quitting2_message_internal();
				
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_quitting2_message = &current_node->quitting2_messages;
	}
}

/** \fn void add_quitting2_message(int worker_id, int firm_id, double range, double x, double y, double z)
 * \brief Add quitting2 message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_quitting2_message(int worker_id, int firm_id, double range, double x, double y, double z)
{

	p_quitting2_message = &current_node->quitting2_messages;
	xmachine_message_quitting2 * tmp = add_quitting2_message_internal();
	
	tmp->worker_id = worker_id;
	tmp->firm_id = firm_id;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_quitting2_message(tmp);
}

xmachine_message_quitting2 * get_next_message_quitting2_in_range(xmachine_message_quitting2 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_quitting2 * get_first_quitting2_message()
 * \brief Get the first quitting2 message in the quitting2 message list.
 * \return The first message in the list.
 */
xmachine_message_quitting2 * get_first_quitting2_message()
{
	return get_next_message_quitting2_in_range(*p_quitting2_message);
}

/** \fn xmachine_message_quitting2 * get_next_quitting2_message(xmachine_message_quitting2 * current)
 * \brief Get the next quitting2 message in the quitting2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_quitting2 * get_next_quitting2_message(xmachine_message_quitting2 * current)
{
	return get_next_message_quitting2_in_range(current->next);
}

/** \fn void freequitting2messages()
 * \brief Free the quitting2 message list.
 */
void freequitting2messages()
{
	xmachine_message_quitting2 * tmp, * head;
	head = *p_quitting2_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_quitting2_message = NULL;
}

/** \fn xmachine_message_productivity * add_productivity_message_internal()
 * \brief Add productivity message to the local message list.
 * \return The added message.
 */
xmachine_message_productivity * add_productivity_message_internal()
{
	xmachine_message_productivity * current = (xmachine_message_productivity *)malloc(sizeof(xmachine_message_productivity));
	CHECK_POINTER(current);

	current->next = *p_productivity_message;
	*p_productivity_message = current;
	
	return current;
}

/** \fn void process_productivity_message(xmachine_message_productivity * current)
 * \brief Process productivity message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_productivity_message(xmachine_message_productivity * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_productivity * temp_send_message;
	
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
				p_productivity_message = &node_info->productivity_messages;
				temp_send_message = add_productivity_message_internal();
				
				temp_send_message->IGfirm_id = current->IGfirm_id;
				temp_send_message->cap_productivity = current->cap_productivity;
				temp_send_message->cap_good_price = current->cap_good_price;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_productivity_message = &current_node->productivity_messages;
	}
}

/** \fn void add_productivity_message(int IGfirm_id, double cap_productivity, double cap_good_price, double range, double x, double y, double z)
 * \brief Add productivity message by calling internal and processing.
 * \param IGfirm_id Message variable.
 * \param cap_productivity Message variable.
 * \param cap_good_price Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_productivity_message(int IGfirm_id, double cap_productivity, double cap_good_price, double range, double x, double y, double z)
{

	p_productivity_message = &current_node->productivity_messages;
	xmachine_message_productivity * tmp = add_productivity_message_internal();
	
	tmp->IGfirm_id = IGfirm_id;
	tmp->cap_productivity = cap_productivity;
	tmp->cap_good_price = cap_good_price;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_productivity_message(tmp);
}

xmachine_message_productivity * get_next_message_productivity_in_range(xmachine_message_productivity * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_productivity * get_first_productivity_message()
 * \brief Get the first productivity message in the productivity message list.
 * \return The first message in the list.
 */
xmachine_message_productivity * get_first_productivity_message()
{
	return get_next_message_productivity_in_range(*p_productivity_message);
}

/** \fn xmachine_message_productivity * get_next_productivity_message(xmachine_message_productivity * current)
 * \brief Get the next productivity message in the productivity message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_productivity * get_next_productivity_message(xmachine_message_productivity * current)
{
	return get_next_message_productivity_in_range(current->next);
}

/** \fn void freeproductivitymessages()
 * \brief Free the productivity message list.
 */
void freeproductivitymessages()
{
	xmachine_message_productivity * tmp, * head;
	head = *p_productivity_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_productivity_message = NULL;
}

/** \fn xmachine_message_capital_good_request * add_capital_good_request_message_internal()
 * \brief Add capital_good_request message to the local message list.
 * \return The added message.
 */
xmachine_message_capital_good_request * add_capital_good_request_message_internal()
{
	xmachine_message_capital_good_request * current = (xmachine_message_capital_good_request *)malloc(sizeof(xmachine_message_capital_good_request));
	CHECK_POINTER(current);

	current->next = *p_capital_good_request_message;
	*p_capital_good_request_message = current;
	
	return current;
}

/** \fn void process_capital_good_request_message(xmachine_message_capital_good_request * current)
 * \brief Process capital_good_request message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_capital_good_request_message(xmachine_message_capital_good_request * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_capital_good_request * temp_send_message;
	
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
				p_capital_good_request_message = &node_info->capital_good_request_messages;
				temp_send_message = add_capital_good_request_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->capital_good_demand = current->capital_good_demand;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_capital_good_request_message = &current_node->capital_good_request_messages;
	}
}

/** \fn void add_capital_good_request_message(int firm_id, double capital_good_demand, double range, double x, double y, double z)
 * \brief Add capital_good_request message by calling internal and processing.
 * \param firm_id Message variable.
 * \param capital_good_demand Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_capital_good_request_message(int firm_id, double capital_good_demand, double range, double x, double y, double z)
{

	p_capital_good_request_message = &current_node->capital_good_request_messages;
	xmachine_message_capital_good_request * tmp = add_capital_good_request_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->capital_good_demand = capital_good_demand;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_capital_good_request_message(tmp);
}

xmachine_message_capital_good_request * get_next_message_capital_good_request_in_range(xmachine_message_capital_good_request * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_capital_good_request * get_first_capital_good_request_message()
 * \brief Get the first capital_good_request message in the capital_good_request message list.
 * \return The first message in the list.
 */
xmachine_message_capital_good_request * get_first_capital_good_request_message()
{
	return get_next_message_capital_good_request_in_range(*p_capital_good_request_message);
}

/** \fn xmachine_message_capital_good_request * get_next_capital_good_request_message(xmachine_message_capital_good_request * current)
 * \brief Get the next capital_good_request message in the capital_good_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_capital_good_request * get_next_capital_good_request_message(xmachine_message_capital_good_request * current)
{
	return get_next_message_capital_good_request_in_range(current->next);
}

/** \fn void freecapital_good_requestmessages()
 * \brief Free the capital_good_request message list.
 */
void freecapital_good_requestmessages()
{
	xmachine_message_capital_good_request * tmp, * head;
	head = *p_capital_good_request_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_capital_good_request_message = NULL;
}

/** \fn xmachine_message_capital_good_profit_distribution * add_capital_good_profit_distribution_message_internal()
 * \brief Add capital_good_profit_distribution message to the local message list.
 * \return The added message.
 */
xmachine_message_capital_good_profit_distribution * add_capital_good_profit_distribution_message_internal()
{
	xmachine_message_capital_good_profit_distribution * current = (xmachine_message_capital_good_profit_distribution *)malloc(sizeof(xmachine_message_capital_good_profit_distribution));
	CHECK_POINTER(current);

	current->next = *p_capital_good_profit_distribution_message;
	*p_capital_good_profit_distribution_message = current;
	
	return current;
}

/** \fn void process_capital_good_profit_distribution_message(xmachine_message_capital_good_profit_distribution * current)
 * \brief Process capital_good_profit_distribution message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_capital_good_profit_distribution_message(xmachine_message_capital_good_profit_distribution * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_capital_good_profit_distribution * temp_send_message;
	
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
				p_capital_good_profit_distribution_message = &node_info->capital_good_profit_distribution_messages;
				temp_send_message = add_capital_good_profit_distribution_message_internal();
				
				temp_send_message->capital_good_profit_shares = current->capital_good_profit_shares;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
	}
}

/** \fn void add_capital_good_profit_distribution_message(double capital_good_profit_shares, double range, double x, double y, double z)
 * \brief Add capital_good_profit_distribution message by calling internal and processing.
 * \param capital_good_profit_shares Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_capital_good_profit_distribution_message(double capital_good_profit_shares, double range, double x, double y, double z)
{

	p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
	xmachine_message_capital_good_profit_distribution * tmp = add_capital_good_profit_distribution_message_internal();
	
	tmp->capital_good_profit_shares = capital_good_profit_shares;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_capital_good_profit_distribution_message(tmp);
}

xmachine_message_capital_good_profit_distribution * get_next_message_capital_good_profit_distribution_in_range(xmachine_message_capital_good_profit_distribution * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_capital_good_profit_distribution * get_first_capital_good_profit_distribution_message()
 * \brief Get the first capital_good_profit_distribution message in the capital_good_profit_distribution message list.
 * \return The first message in the list.
 */
xmachine_message_capital_good_profit_distribution * get_first_capital_good_profit_distribution_message()
{
	return get_next_message_capital_good_profit_distribution_in_range(*p_capital_good_profit_distribution_message);
}

/** \fn xmachine_message_capital_good_profit_distribution * get_next_capital_good_profit_distribution_message(xmachine_message_capital_good_profit_distribution * current)
 * \brief Get the next capital_good_profit_distribution message in the capital_good_profit_distribution message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_capital_good_profit_distribution * get_next_capital_good_profit_distribution_message(xmachine_message_capital_good_profit_distribution * current)
{
	return get_next_message_capital_good_profit_distribution_in_range(current->next);
}

/** \fn void freecapital_good_profit_distributionmessages()
 * \brief Free the capital_good_profit_distribution message list.
 */
void freecapital_good_profit_distributionmessages()
{
	xmachine_message_capital_good_profit_distribution * tmp, * head;
	head = *p_capital_good_profit_distribution_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_capital_good_profit_distribution_message = NULL;
}

/** \fn xmachine_message_capital_good_delivery * add_capital_good_delivery_message_internal()
 * \brief Add capital_good_delivery message to the local message list.
 * \return The added message.
 */
xmachine_message_capital_good_delivery * add_capital_good_delivery_message_internal()
{
	xmachine_message_capital_good_delivery * current = (xmachine_message_capital_good_delivery *)malloc(sizeof(xmachine_message_capital_good_delivery));
	CHECK_POINTER(current);

	current->next = *p_capital_good_delivery_message;
	*p_capital_good_delivery_message = current;
	
	return current;
}

/** \fn void process_capital_good_delivery_message(xmachine_message_capital_good_delivery * current)
 * \brief Process capital_good_delivery message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_capital_good_delivery_message(xmachine_message_capital_good_delivery * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_capital_good_delivery * temp_send_message;
	
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
				p_capital_good_delivery_message = &node_info->capital_good_delivery_messages;
				temp_send_message = add_capital_good_delivery_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->capital_good_delivery_volume = current->capital_good_delivery_volume;
				temp_send_message->productivity = current->productivity;
				temp_send_message->capital_good_price = current->capital_good_price;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
	}
}

/** \fn void add_capital_good_delivery_message(int firm_id, double capital_good_delivery_volume, double productivity, double capital_good_price, double range, double x, double y, double z)
 * \brief Add capital_good_delivery message by calling internal and processing.
 * \param firm_id Message variable.
 * \param capital_good_delivery_volume Message variable.
 * \param productivity Message variable.
 * \param capital_good_price Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_capital_good_delivery_message(int firm_id, double capital_good_delivery_volume, double productivity, double capital_good_price, double range, double x, double y, double z)
{

	p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
	xmachine_message_capital_good_delivery * tmp = add_capital_good_delivery_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->capital_good_delivery_volume = capital_good_delivery_volume;
	tmp->productivity = productivity;
	tmp->capital_good_price = capital_good_price;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_capital_good_delivery_message(tmp);
}

xmachine_message_capital_good_delivery * get_next_message_capital_good_delivery_in_range(xmachine_message_capital_good_delivery * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_capital_good_delivery * get_first_capital_good_delivery_message()
 * \brief Get the first capital_good_delivery message in the capital_good_delivery message list.
 * \return The first message in the list.
 */
xmachine_message_capital_good_delivery * get_first_capital_good_delivery_message()
{
	return get_next_message_capital_good_delivery_in_range(*p_capital_good_delivery_message);
}

/** \fn xmachine_message_capital_good_delivery * get_next_capital_good_delivery_message(xmachine_message_capital_good_delivery * current)
 * \brief Get the next capital_good_delivery message in the capital_good_delivery message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_capital_good_delivery * get_next_capital_good_delivery_message(xmachine_message_capital_good_delivery * current)
{
	return get_next_message_capital_good_delivery_in_range(current->next);
}

/** \fn void freecapital_good_deliverymessages()
 * \brief Free the capital_good_delivery message list.
 */
void freecapital_good_deliverymessages()
{
	xmachine_message_capital_good_delivery * tmp, * head;
	head = *p_capital_good_delivery_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_capital_good_delivery_message = NULL;
}

/** \fn xmachine_message_wage_payment * add_wage_payment_message_internal()
 * \brief Add wage_payment message to the local message list.
 * \return The added message.
 */
xmachine_message_wage_payment * add_wage_payment_message_internal()
{
	xmachine_message_wage_payment * current = (xmachine_message_wage_payment *)malloc(sizeof(xmachine_message_wage_payment));
	CHECK_POINTER(current);

	current->next = *p_wage_payment_message;
	*p_wage_payment_message = current;
	
	return current;
}

/** \fn void process_wage_payment_message(xmachine_message_wage_payment * current)
 * \brief Process wage_payment message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_wage_payment_message(xmachine_message_wage_payment * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_wage_payment * temp_send_message;
	
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
				p_wage_payment_message = &node_info->wage_payment_messages;
				temp_send_message = add_wage_payment_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->payment = current->payment;
				temp_send_message->productivity = current->productivity;
				temp_send_message->average_specific_skills = current->average_specific_skills;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_wage_payment_message = &current_node->wage_payment_messages;
	}
}

/** \fn void add_wage_payment_message(int firm_id, int worker_id, double payment, double productivity, double average_specific_skills, double range, double x, double y, double z)
 * \brief Add wage_payment message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param payment Message variable.
 * \param productivity Message variable.
 * \param average_specific_skills Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_wage_payment_message(int firm_id, int worker_id, double payment, double productivity, double average_specific_skills, double range, double x, double y, double z)
{

	p_wage_payment_message = &current_node->wage_payment_messages;
	xmachine_message_wage_payment * tmp = add_wage_payment_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->worker_id = worker_id;
	tmp->payment = payment;
	tmp->productivity = productivity;
	tmp->average_specific_skills = average_specific_skills;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_wage_payment_message(tmp);
}

xmachine_message_wage_payment * get_next_message_wage_payment_in_range(xmachine_message_wage_payment * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_wage_payment * get_first_wage_payment_message()
 * \brief Get the first wage_payment message in the wage_payment message list.
 * \return The first message in the list.
 */
xmachine_message_wage_payment * get_first_wage_payment_message()
{
	return get_next_message_wage_payment_in_range(*p_wage_payment_message);
}

/** \fn xmachine_message_wage_payment * get_next_wage_payment_message(xmachine_message_wage_payment * current)
 * \brief Get the next wage_payment message in the wage_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_wage_payment * get_next_wage_payment_message(xmachine_message_wage_payment * current)
{
	return get_next_message_wage_payment_in_range(current->next);
}

/** \fn void freewage_paymentmessages()
 * \brief Free the wage_payment message list.
 */
void freewage_paymentmessages()
{
	xmachine_message_wage_payment * tmp, * head;
	head = *p_wage_payment_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_wage_payment_message = NULL;
}

/** \fn xmachine_message_quality_price_info_1 * add_quality_price_info_1_message_internal()
 * \brief Add quality_price_info_1 message to the local message list.
 * \return The added message.
 */
xmachine_message_quality_price_info_1 * add_quality_price_info_1_message_internal()
{
	xmachine_message_quality_price_info_1 * current = (xmachine_message_quality_price_info_1 *)malloc(sizeof(xmachine_message_quality_price_info_1));
	CHECK_POINTER(current);

	current->next = *p_quality_price_info_1_message;
	*p_quality_price_info_1_message = current;
	
	return current;
}

/** \fn void process_quality_price_info_1_message(xmachine_message_quality_price_info_1 * current)
 * \brief Process quality_price_info_1 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_quality_price_info_1_message(xmachine_message_quality_price_info_1 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_quality_price_info_1 * temp_send_message;
	
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
				p_quality_price_info_1_message = &node_info->quality_price_info_1_messages;
				temp_send_message = add_quality_price_info_1_message_internal();
				
				temp_send_message->mall_id = current->mall_id;
				temp_send_message->mall_region_id = current->mall_region_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->quality = current->quality;
				temp_send_message->price = current->price;
				temp_send_message->available = current->available;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
	}
}

/** \fn void add_quality_price_info_1_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available, double range, double x, double y, double z)
 * \brief Add quality_price_info_1 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param mall_region_id Message variable.
 * \param firm_id Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 * \param available Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_quality_price_info_1_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available, double range, double x, double y, double z)
{

	p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
	xmachine_message_quality_price_info_1 * tmp = add_quality_price_info_1_message_internal();
	
	tmp->mall_id = mall_id;
	tmp->mall_region_id = mall_region_id;
	tmp->firm_id = firm_id;
	tmp->quality = quality;
	tmp->price = price;
	tmp->available = available;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_quality_price_info_1_message(tmp);
}

xmachine_message_quality_price_info_1 * get_next_message_quality_price_info_1_in_range(xmachine_message_quality_price_info_1 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_quality_price_info_1 * get_first_quality_price_info_1_message()
 * \brief Get the first quality_price_info_1 message in the quality_price_info_1 message list.
 * \return The first message in the list.
 */
xmachine_message_quality_price_info_1 * get_first_quality_price_info_1_message()
{
	return get_next_message_quality_price_info_1_in_range(*p_quality_price_info_1_message);
}

/** \fn xmachine_message_quality_price_info_1 * get_next_quality_price_info_1_message(xmachine_message_quality_price_info_1 * current)
 * \brief Get the next quality_price_info_1 message in the quality_price_info_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_quality_price_info_1 * get_next_quality_price_info_1_message(xmachine_message_quality_price_info_1 * current)
{
	return get_next_message_quality_price_info_1_in_range(current->next);
}

/** \fn void freequality_price_info_1messages()
 * \brief Free the quality_price_info_1 message list.
 */
void freequality_price_info_1messages()
{
	xmachine_message_quality_price_info_1 * tmp, * head;
	head = *p_quality_price_info_1_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_quality_price_info_1_message = NULL;
}

/** \fn xmachine_message_quality_price_info_2 * add_quality_price_info_2_message_internal()
 * \brief Add quality_price_info_2 message to the local message list.
 * \return The added message.
 */
xmachine_message_quality_price_info_2 * add_quality_price_info_2_message_internal()
{
	xmachine_message_quality_price_info_2 * current = (xmachine_message_quality_price_info_2 *)malloc(sizeof(xmachine_message_quality_price_info_2));
	CHECK_POINTER(current);

	current->next = *p_quality_price_info_2_message;
	*p_quality_price_info_2_message = current;
	
	return current;
}

/** \fn void process_quality_price_info_2_message(xmachine_message_quality_price_info_2 * current)
 * \brief Process quality_price_info_2 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_quality_price_info_2_message(xmachine_message_quality_price_info_2 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_quality_price_info_2 * temp_send_message;
	
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
				p_quality_price_info_2_message = &node_info->quality_price_info_2_messages;
				temp_send_message = add_quality_price_info_2_message_internal();
				
				temp_send_message->mall_id = current->mall_id;
				temp_send_message->mall_region_id = current->mall_region_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->quality = current->quality;
				temp_send_message->price = current->price;
				temp_send_message->available = current->available;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
	}
}

/** \fn void add_quality_price_info_2_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available, double range, double x, double y, double z)
 * \brief Add quality_price_info_2 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param mall_region_id Message variable.
 * \param firm_id Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 * \param available Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_quality_price_info_2_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available, double range, double x, double y, double z)
{

	p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
	xmachine_message_quality_price_info_2 * tmp = add_quality_price_info_2_message_internal();
	
	tmp->mall_id = mall_id;
	tmp->mall_region_id = mall_region_id;
	tmp->firm_id = firm_id;
	tmp->quality = quality;
	tmp->price = price;
	tmp->available = available;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_quality_price_info_2_message(tmp);
}

xmachine_message_quality_price_info_2 * get_next_message_quality_price_info_2_in_range(xmachine_message_quality_price_info_2 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_quality_price_info_2 * get_first_quality_price_info_2_message()
 * \brief Get the first quality_price_info_2 message in the quality_price_info_2 message list.
 * \return The first message in the list.
 */
xmachine_message_quality_price_info_2 * get_first_quality_price_info_2_message()
{
	return get_next_message_quality_price_info_2_in_range(*p_quality_price_info_2_message);
}

/** \fn xmachine_message_quality_price_info_2 * get_next_quality_price_info_2_message(xmachine_message_quality_price_info_2 * current)
 * \brief Get the next quality_price_info_2 message in the quality_price_info_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_quality_price_info_2 * get_next_quality_price_info_2_message(xmachine_message_quality_price_info_2 * current)
{
	return get_next_message_quality_price_info_2_in_range(current->next);
}

/** \fn void freequality_price_info_2messages()
 * \brief Free the quality_price_info_2 message list.
 */
void freequality_price_info_2messages()
{
	xmachine_message_quality_price_info_2 * tmp, * head;
	head = *p_quality_price_info_2_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_quality_price_info_2_message = NULL;
}

/** \fn xmachine_message_update_mall_stock * add_update_mall_stock_message_internal()
 * \brief Add update_mall_stock message to the local message list.
 * \return The added message.
 */
xmachine_message_update_mall_stock * add_update_mall_stock_message_internal()
{
	xmachine_message_update_mall_stock * current = (xmachine_message_update_mall_stock *)malloc(sizeof(xmachine_message_update_mall_stock));
	CHECK_POINTER(current);

	current->next = *p_update_mall_stock_message;
	*p_update_mall_stock_message = current;
	
	return current;
}

/** \fn void process_update_mall_stock_message(xmachine_message_update_mall_stock * current)
 * \brief Process update_mall_stock message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_update_mall_stock_message(xmachine_message_update_mall_stock * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_update_mall_stock * temp_send_message;
	
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
				p_update_mall_stock_message = &node_info->update_mall_stock_messages;
				temp_send_message = add_update_mall_stock_message_internal();
				
				temp_send_message->mall_id = current->mall_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->quantity = current->quantity;
				temp_send_message->quality = current->quality;
				temp_send_message->price = current->price;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_update_mall_stock_message = &current_node->update_mall_stock_messages;
	}
}

/** \fn void add_update_mall_stock_message(int mall_id, int firm_id, double quantity, double quality, double price, double range, double x, double y, double z)
 * \brief Add update_mall_stock message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_id Message variable.
 * \param quantity Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_update_mall_stock_message(int mall_id, int firm_id, double quantity, double quality, double price, double range, double x, double y, double z)
{

	p_update_mall_stock_message = &current_node->update_mall_stock_messages;
	xmachine_message_update_mall_stock * tmp = add_update_mall_stock_message_internal();
	
	tmp->mall_id = mall_id;
	tmp->firm_id = firm_id;
	tmp->quantity = quantity;
	tmp->quality = quality;
	tmp->price = price;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_update_mall_stock_message(tmp);
}

xmachine_message_update_mall_stock * get_next_message_update_mall_stock_in_range(xmachine_message_update_mall_stock * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_update_mall_stock * get_first_update_mall_stock_message()
 * \brief Get the first update_mall_stock message in the update_mall_stock message list.
 * \return The first message in the list.
 */
xmachine_message_update_mall_stock * get_first_update_mall_stock_message()
{
	return get_next_message_update_mall_stock_in_range(*p_update_mall_stock_message);
}

/** \fn xmachine_message_update_mall_stock * get_next_update_mall_stock_message(xmachine_message_update_mall_stock * current)
 * \brief Get the next update_mall_stock message in the update_mall_stock message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_update_mall_stock * get_next_update_mall_stock_message(xmachine_message_update_mall_stock * current)
{
	return get_next_message_update_mall_stock_in_range(current->next);
}

/** \fn void freeupdate_mall_stockmessages()
 * \brief Free the update_mall_stock message list.
 */
void freeupdate_mall_stockmessages()
{
	xmachine_message_update_mall_stock * tmp, * head;
	head = *p_update_mall_stock_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_update_mall_stock_message = NULL;
}

/** \fn xmachine_message_consumption_request_1 * add_consumption_request_1_message_internal()
 * \brief Add consumption_request_1 message to the local message list.
 * \return The added message.
 */
xmachine_message_consumption_request_1 * add_consumption_request_1_message_internal()
{
	xmachine_message_consumption_request_1 * current = (xmachine_message_consumption_request_1 *)malloc(sizeof(xmachine_message_consumption_request_1));
	CHECK_POINTER(current);

	current->next = *p_consumption_request_1_message;
	*p_consumption_request_1_message = current;
	
	return current;
}

/** \fn void process_consumption_request_1_message(xmachine_message_consumption_request_1 * current)
 * \brief Process consumption_request_1 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_consumption_request_1_message(xmachine_message_consumption_request_1 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_consumption_request_1 * temp_send_message;
	
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
				p_consumption_request_1_message = &node_info->consumption_request_1_messages;
				temp_send_message = add_consumption_request_1_message_internal();
				
				temp_send_message->mall_id = current->mall_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->quantity = current->quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_consumption_request_1_message = &current_node->consumption_request_1_messages;
	}
}

/** \fn void add_consumption_request_1_message(int mall_id, int worker_id, int firm_id, double quantity, double range, double x, double y, double z)
 * \brief Add consumption_request_1 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_consumption_request_1_message(int mall_id, int worker_id, int firm_id, double quantity, double range, double x, double y, double z)
{

	p_consumption_request_1_message = &current_node->consumption_request_1_messages;
	xmachine_message_consumption_request_1 * tmp = add_consumption_request_1_message_internal();
	
	tmp->mall_id = mall_id;
	tmp->worker_id = worker_id;
	tmp->firm_id = firm_id;
	tmp->quantity = quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_consumption_request_1_message(tmp);
}

xmachine_message_consumption_request_1 * get_next_message_consumption_request_1_in_range(xmachine_message_consumption_request_1 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_consumption_request_1 * get_first_consumption_request_1_message()
 * \brief Get the first consumption_request_1 message in the consumption_request_1 message list.
 * \return The first message in the list.
 */
xmachine_message_consumption_request_1 * get_first_consumption_request_1_message()
{
	return get_next_message_consumption_request_1_in_range(*p_consumption_request_1_message);
}

/** \fn xmachine_message_consumption_request_1 * get_next_consumption_request_1_message(xmachine_message_consumption_request_1 * current)
 * \brief Get the next consumption_request_1 message in the consumption_request_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_consumption_request_1 * get_next_consumption_request_1_message(xmachine_message_consumption_request_1 * current)
{
	return get_next_message_consumption_request_1_in_range(current->next);
}

/** \fn void freeconsumption_request_1messages()
 * \brief Free the consumption_request_1 message list.
 */
void freeconsumption_request_1messages()
{
	xmachine_message_consumption_request_1 * tmp, * head;
	head = *p_consumption_request_1_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_consumption_request_1_message = NULL;
}

/** \fn xmachine_message_consumption_request_2 * add_consumption_request_2_message_internal()
 * \brief Add consumption_request_2 message to the local message list.
 * \return The added message.
 */
xmachine_message_consumption_request_2 * add_consumption_request_2_message_internal()
{
	xmachine_message_consumption_request_2 * current = (xmachine_message_consumption_request_2 *)malloc(sizeof(xmachine_message_consumption_request_2));
	CHECK_POINTER(current);

	current->next = *p_consumption_request_2_message;
	*p_consumption_request_2_message = current;
	
	return current;
}

/** \fn void process_consumption_request_2_message(xmachine_message_consumption_request_2 * current)
 * \brief Process consumption_request_2 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_consumption_request_2_message(xmachine_message_consumption_request_2 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_consumption_request_2 * temp_send_message;
	
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
				p_consumption_request_2_message = &node_info->consumption_request_2_messages;
				temp_send_message = add_consumption_request_2_message_internal();
				
				temp_send_message->mall_id = current->mall_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->quantity = current->quantity;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_consumption_request_2_message = &current_node->consumption_request_2_messages;
	}
}

/** \fn void add_consumption_request_2_message(int mall_id, int worker_id, int firm_id, double quantity, double range, double x, double y, double z)
 * \brief Add consumption_request_2 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param quantity Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_consumption_request_2_message(int mall_id, int worker_id, int firm_id, double quantity, double range, double x, double y, double z)
{

	p_consumption_request_2_message = &current_node->consumption_request_2_messages;
	xmachine_message_consumption_request_2 * tmp = add_consumption_request_2_message_internal();
	
	tmp->mall_id = mall_id;
	tmp->worker_id = worker_id;
	tmp->firm_id = firm_id;
	tmp->quantity = quantity;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_consumption_request_2_message(tmp);
}

xmachine_message_consumption_request_2 * get_next_message_consumption_request_2_in_range(xmachine_message_consumption_request_2 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_consumption_request_2 * get_first_consumption_request_2_message()
 * \brief Get the first consumption_request_2 message in the consumption_request_2 message list.
 * \return The first message in the list.
 */
xmachine_message_consumption_request_2 * get_first_consumption_request_2_message()
{
	return get_next_message_consumption_request_2_in_range(*p_consumption_request_2_message);
}

/** \fn xmachine_message_consumption_request_2 * get_next_consumption_request_2_message(xmachine_message_consumption_request_2 * current)
 * \brief Get the next consumption_request_2 message in the consumption_request_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_consumption_request_2 * get_next_consumption_request_2_message(xmachine_message_consumption_request_2 * current)
{
	return get_next_message_consumption_request_2_in_range(current->next);
}

/** \fn void freeconsumption_request_2messages()
 * \brief Free the consumption_request_2 message list.
 */
void freeconsumption_request_2messages()
{
	xmachine_message_consumption_request_2 * tmp, * head;
	head = *p_consumption_request_2_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_consumption_request_2_message = NULL;
}

/** \fn xmachine_message_accepted_consumption_1 * add_accepted_consumption_1_message_internal()
 * \brief Add accepted_consumption_1 message to the local message list.
 * \return The added message.
 */
xmachine_message_accepted_consumption_1 * add_accepted_consumption_1_message_internal()
{
	xmachine_message_accepted_consumption_1 * current = (xmachine_message_accepted_consumption_1 *)malloc(sizeof(xmachine_message_accepted_consumption_1));
	CHECK_POINTER(current);

	current->next = *p_accepted_consumption_1_message;
	*p_accepted_consumption_1_message = current;
	
	return current;
}

/** \fn void process_accepted_consumption_1_message(xmachine_message_accepted_consumption_1 * current)
 * \brief Process accepted_consumption_1 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_accepted_consumption_1_message(xmachine_message_accepted_consumption_1 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_accepted_consumption_1 * temp_send_message;
	
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
				p_accepted_consumption_1_message = &node_info->accepted_consumption_1_messages;
				temp_send_message = add_accepted_consumption_1_message_internal();
				
				temp_send_message->mall_id = current->mall_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->offered_consumption_volume = current->offered_consumption_volume;
				temp_send_message->rationed = current->rationed;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
	}
}

/** \fn void add_accepted_consumption_1_message(int mall_id, int worker_id, double offered_consumption_volume, int rationed, double range, double x, double y, double z)
 * \brief Add accepted_consumption_1 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param worker_id Message variable.
 * \param offered_consumption_volume Message variable.
 * \param rationed Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_accepted_consumption_1_message(int mall_id, int worker_id, double offered_consumption_volume, int rationed, double range, double x, double y, double z)
{

	p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
	xmachine_message_accepted_consumption_1 * tmp = add_accepted_consumption_1_message_internal();
	
	tmp->mall_id = mall_id;
	tmp->worker_id = worker_id;
	tmp->offered_consumption_volume = offered_consumption_volume;
	tmp->rationed = rationed;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_accepted_consumption_1_message(tmp);
}

xmachine_message_accepted_consumption_1 * get_next_message_accepted_consumption_1_in_range(xmachine_message_accepted_consumption_1 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_accepted_consumption_1 * get_first_accepted_consumption_1_message()
 * \brief Get the first accepted_consumption_1 message in the accepted_consumption_1 message list.
 * \return The first message in the list.
 */
xmachine_message_accepted_consumption_1 * get_first_accepted_consumption_1_message()
{
	return get_next_message_accepted_consumption_1_in_range(*p_accepted_consumption_1_message);
}

/** \fn xmachine_message_accepted_consumption_1 * get_next_accepted_consumption_1_message(xmachine_message_accepted_consumption_1 * current)
 * \brief Get the next accepted_consumption_1 message in the accepted_consumption_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_accepted_consumption_1 * get_next_accepted_consumption_1_message(xmachine_message_accepted_consumption_1 * current)
{
	return get_next_message_accepted_consumption_1_in_range(current->next);
}

/** \fn void freeaccepted_consumption_1messages()
 * \brief Free the accepted_consumption_1 message list.
 */
void freeaccepted_consumption_1messages()
{
	xmachine_message_accepted_consumption_1 * tmp, * head;
	head = *p_accepted_consumption_1_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_accepted_consumption_1_message = NULL;
}

/** \fn xmachine_message_accepted_consumption_2 * add_accepted_consumption_2_message_internal()
 * \brief Add accepted_consumption_2 message to the local message list.
 * \return The added message.
 */
xmachine_message_accepted_consumption_2 * add_accepted_consumption_2_message_internal()
{
	xmachine_message_accepted_consumption_2 * current = (xmachine_message_accepted_consumption_2 *)malloc(sizeof(xmachine_message_accepted_consumption_2));
	CHECK_POINTER(current);

	current->next = *p_accepted_consumption_2_message;
	*p_accepted_consumption_2_message = current;
	
	return current;
}

/** \fn void process_accepted_consumption_2_message(xmachine_message_accepted_consumption_2 * current)
 * \brief Process accepted_consumption_2 message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_accepted_consumption_2_message(xmachine_message_accepted_consumption_2 * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_accepted_consumption_2 * temp_send_message;
	
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
				p_accepted_consumption_2_message = &node_info->accepted_consumption_2_messages;
				temp_send_message = add_accepted_consumption_2_message_internal();
				
				temp_send_message->mall_id = current->mall_id;
				temp_send_message->worker_id = current->worker_id;
				temp_send_message->offered_consumption_volume = current->offered_consumption_volume;
				temp_send_message->rationed = current->rationed;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
	}
}

/** \fn void add_accepted_consumption_2_message(int mall_id, int worker_id, double offered_consumption_volume, int rationed, double range, double x, double y, double z)
 * \brief Add accepted_consumption_2 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param worker_id Message variable.
 * \param offered_consumption_volume Message variable.
 * \param rationed Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_accepted_consumption_2_message(int mall_id, int worker_id, double offered_consumption_volume, int rationed, double range, double x, double y, double z)
{

	p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
	xmachine_message_accepted_consumption_2 * tmp = add_accepted_consumption_2_message_internal();
	
	tmp->mall_id = mall_id;
	tmp->worker_id = worker_id;
	tmp->offered_consumption_volume = offered_consumption_volume;
	tmp->rationed = rationed;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_accepted_consumption_2_message(tmp);
}

xmachine_message_accepted_consumption_2 * get_next_message_accepted_consumption_2_in_range(xmachine_message_accepted_consumption_2 * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_accepted_consumption_2 * get_first_accepted_consumption_2_message()
 * \brief Get the first accepted_consumption_2 message in the accepted_consumption_2 message list.
 * \return The first message in the list.
 */
xmachine_message_accepted_consumption_2 * get_first_accepted_consumption_2_message()
{
	return get_next_message_accepted_consumption_2_in_range(*p_accepted_consumption_2_message);
}

/** \fn xmachine_message_accepted_consumption_2 * get_next_accepted_consumption_2_message(xmachine_message_accepted_consumption_2 * current)
 * \brief Get the next accepted_consumption_2 message in the accepted_consumption_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_accepted_consumption_2 * get_next_accepted_consumption_2_message(xmachine_message_accepted_consumption_2 * current)
{
	return get_next_message_accepted_consumption_2_in_range(current->next);
}

/** \fn void freeaccepted_consumption_2messages()
 * \brief Free the accepted_consumption_2 message list.
 */
void freeaccepted_consumption_2messages()
{
	xmachine_message_accepted_consumption_2 * tmp, * head;
	head = *p_accepted_consumption_2_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_accepted_consumption_2_message = NULL;
}

/** \fn xmachine_message_sales * add_sales_message_internal()
 * \brief Add sales message to the local message list.
 * \return The added message.
 */
xmachine_message_sales * add_sales_message_internal()
{
	xmachine_message_sales * current = (xmachine_message_sales *)malloc(sizeof(xmachine_message_sales));
	CHECK_POINTER(current);

	current->next = *p_sales_message;
	*p_sales_message = current;
	
	return current;
}

/** \fn void process_sales_message(xmachine_message_sales * current)
 * \brief Process sales message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_sales_message(xmachine_message_sales * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_sales * temp_send_message;
	
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
				p_sales_message = &node_info->sales_messages;
				temp_send_message = add_sales_message_internal();
				
				temp_send_message->mall_id = current->mall_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->revenue = current->revenue;
				temp_send_message->stock_empty = current->stock_empty;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_sales_message = &current_node->sales_messages;
	}
}

/** \fn void add_sales_message(int mall_id, int firm_id, double revenue, int stock_empty, double range, double x, double y, double z)
 * \brief Add sales message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_id Message variable.
 * \param revenue Message variable.
 * \param stock_empty Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_sales_message(int mall_id, int firm_id, double revenue, int stock_empty, double range, double x, double y, double z)
{

	p_sales_message = &current_node->sales_messages;
	xmachine_message_sales * tmp = add_sales_message_internal();
	
	tmp->mall_id = mall_id;
	tmp->firm_id = firm_id;
	tmp->revenue = revenue;
	tmp->stock_empty = stock_empty;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_sales_message(tmp);
}

xmachine_message_sales * get_next_message_sales_in_range(xmachine_message_sales * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_sales * get_first_sales_message()
 * \brief Get the first sales message in the sales message list.
 * \return The first message in the list.
 */
xmachine_message_sales * get_first_sales_message()
{
	return get_next_message_sales_in_range(*p_sales_message);
}

/** \fn xmachine_message_sales * get_next_sales_message(xmachine_message_sales * current)
 * \brief Get the next sales message in the sales message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_sales * get_next_sales_message(xmachine_message_sales * current)
{
	return get_next_message_sales_in_range(current->next);
}

/** \fn void freesalesmessages()
 * \brief Free the sales message list.
 */
void freesalesmessages()
{
	xmachine_message_sales * tmp, * head;
	head = *p_sales_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_sales_message = NULL;
}

/** \fn xmachine_message_pay_capital_goods * add_pay_capital_goods_message_internal()
 * \brief Add pay_capital_goods message to the local message list.
 * \return The added message.
 */
xmachine_message_pay_capital_goods * add_pay_capital_goods_message_internal()
{
	xmachine_message_pay_capital_goods * current = (xmachine_message_pay_capital_goods *)malloc(sizeof(xmachine_message_pay_capital_goods));
	CHECK_POINTER(current);

	current->next = *p_pay_capital_goods_message;
	*p_pay_capital_goods_message = current;
	
	return current;
}

/** \fn void process_pay_capital_goods_message(xmachine_message_pay_capital_goods * current)
 * \brief Process pay_capital_goods message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_pay_capital_goods_message(xmachine_message_pay_capital_goods * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_pay_capital_goods * temp_send_message;
	
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
				p_pay_capital_goods_message = &node_info->pay_capital_goods_messages;
				temp_send_message = add_pay_capital_goods_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->capital_bill = current->capital_bill;
				temp_send_message->share_net_investments = current->share_net_investments;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
	}
}

/** \fn void add_pay_capital_goods_message(int firm_id, double capital_bill, double share_net_investments, double range, double x, double y, double z)
 * \brief Add pay_capital_goods message by calling internal and processing.
 * \param firm_id Message variable.
 * \param capital_bill Message variable.
 * \param share_net_investments Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_pay_capital_goods_message(int firm_id, double capital_bill, double share_net_investments, double range, double x, double y, double z)
{

	p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
	xmachine_message_pay_capital_goods * tmp = add_pay_capital_goods_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->capital_bill = capital_bill;
	tmp->share_net_investments = share_net_investments;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_pay_capital_goods_message(tmp);
}

xmachine_message_pay_capital_goods * get_next_message_pay_capital_goods_in_range(xmachine_message_pay_capital_goods * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_pay_capital_goods * get_first_pay_capital_goods_message()
 * \brief Get the first pay_capital_goods message in the pay_capital_goods message list.
 * \return The first message in the list.
 */
xmachine_message_pay_capital_goods * get_first_pay_capital_goods_message()
{
	return get_next_message_pay_capital_goods_in_range(*p_pay_capital_goods_message);
}

/** \fn xmachine_message_pay_capital_goods * get_next_pay_capital_goods_message(xmachine_message_pay_capital_goods * current)
 * \brief Get the next pay_capital_goods message in the pay_capital_goods message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_pay_capital_goods * get_next_pay_capital_goods_message(xmachine_message_pay_capital_goods * current)
{
	return get_next_message_pay_capital_goods_in_range(current->next);
}

/** \fn void freepay_capital_goodsmessages()
 * \brief Free the pay_capital_goods message list.
 */
void freepay_capital_goodsmessages()
{
	xmachine_message_pay_capital_goods * tmp, * head;
	head = *p_pay_capital_goods_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_pay_capital_goods_message = NULL;
}

/** \fn xmachine_message_current_mall_stock_info * add_current_mall_stock_info_message_internal()
 * \brief Add current_mall_stock_info message to the local message list.
 * \return The added message.
 */
xmachine_message_current_mall_stock_info * add_current_mall_stock_info_message_internal()
{
	xmachine_message_current_mall_stock_info * current = (xmachine_message_current_mall_stock_info *)malloc(sizeof(xmachine_message_current_mall_stock_info));
	CHECK_POINTER(current);

	current->next = *p_current_mall_stock_info_message;
	*p_current_mall_stock_info_message = current;
	
	return current;
}

/** \fn void process_current_mall_stock_info_message(xmachine_message_current_mall_stock_info * current)
 * \brief Process current_mall_stock_info message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_current_mall_stock_info_message(xmachine_message_current_mall_stock_info * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_current_mall_stock_info * temp_send_message;
	
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
				p_current_mall_stock_info_message = &node_info->current_mall_stock_info_messages;
				temp_send_message = add_current_mall_stock_info_message_internal();
				
				temp_send_message->mall_id = current->mall_id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->stock = current->stock;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
	}
}

/** \fn void add_current_mall_stock_info_message(int mall_id, int firm_id, double stock, double range, double x, double y, double z)
 * \brief Add current_mall_stock_info message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_id Message variable.
 * \param stock Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_current_mall_stock_info_message(int mall_id, int firm_id, double stock, double range, double x, double y, double z)
{

	p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
	xmachine_message_current_mall_stock_info * tmp = add_current_mall_stock_info_message_internal();
	
	tmp->mall_id = mall_id;
	tmp->firm_id = firm_id;
	tmp->stock = stock;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_current_mall_stock_info_message(tmp);
}

xmachine_message_current_mall_stock_info * get_next_message_current_mall_stock_info_in_range(xmachine_message_current_mall_stock_info * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_current_mall_stock_info * get_first_current_mall_stock_info_message()
 * \brief Get the first current_mall_stock_info message in the current_mall_stock_info message list.
 * \return The first message in the list.
 */
xmachine_message_current_mall_stock_info * get_first_current_mall_stock_info_message()
{
	return get_next_message_current_mall_stock_info_in_range(*p_current_mall_stock_info_message);
}

/** \fn xmachine_message_current_mall_stock_info * get_next_current_mall_stock_info_message(xmachine_message_current_mall_stock_info * current)
 * \brief Get the next current_mall_stock_info message in the current_mall_stock_info message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_current_mall_stock_info * get_next_current_mall_stock_info_message(xmachine_message_current_mall_stock_info * current)
{
	return get_next_message_current_mall_stock_info_in_range(current->next);
}

/** \fn void freecurrent_mall_stock_infomessages()
 * \brief Free the current_mall_stock_info message list.
 */
void freecurrent_mall_stock_infomessages()
{
	xmachine_message_current_mall_stock_info * tmp, * head;
	head = *p_current_mall_stock_info_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_current_mall_stock_info_message = NULL;
}

/** \fn xmachine_message_specific_skill_update * add_specific_skill_update_message_internal()
 * \brief Add specific_skill_update message to the local message list.
 * \return The added message.
 */
xmachine_message_specific_skill_update * add_specific_skill_update_message_internal()
{
	xmachine_message_specific_skill_update * current = (xmachine_message_specific_skill_update *)malloc(sizeof(xmachine_message_specific_skill_update));
	CHECK_POINTER(current);

	current->next = *p_specific_skill_update_message;
	*p_specific_skill_update_message = current;
	
	return current;
}

/** \fn void process_specific_skill_update_message(xmachine_message_specific_skill_update * current)
 * \brief Process specific_skill_update message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_specific_skill_update_message(xmachine_message_specific_skill_update * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_specific_skill_update * temp_send_message;
	
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
				p_specific_skill_update_message = &node_info->specific_skill_update_messages;
				temp_send_message = add_specific_skill_update_message_internal();
				
				temp_send_message->id = current->id;
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->specific_skills = current->specific_skills;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_specific_skill_update_message = &current_node->specific_skill_update_messages;
	}
}

/** \fn void add_specific_skill_update_message(int id, int firm_id, double specific_skills, double range, double x, double y, double z)
 * \brief Add specific_skill_update message by calling internal and processing.
 * \param id Message variable.
 * \param firm_id Message variable.
 * \param specific_skills Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_specific_skill_update_message(int id, int firm_id, double specific_skills, double range, double x, double y, double z)
{

	p_specific_skill_update_message = &current_node->specific_skill_update_messages;
	xmachine_message_specific_skill_update * tmp = add_specific_skill_update_message_internal();
	
	tmp->id = id;
	tmp->firm_id = firm_id;
	tmp->specific_skills = specific_skills;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_specific_skill_update_message(tmp);
}

xmachine_message_specific_skill_update * get_next_message_specific_skill_update_in_range(xmachine_message_specific_skill_update * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_specific_skill_update * get_first_specific_skill_update_message()
 * \brief Get the first specific_skill_update message in the specific_skill_update message list.
 * \return The first message in the list.
 */
xmachine_message_specific_skill_update * get_first_specific_skill_update_message()
{
	return get_next_message_specific_skill_update_in_range(*p_specific_skill_update_message);
}

/** \fn xmachine_message_specific_skill_update * get_next_specific_skill_update_message(xmachine_message_specific_skill_update * current)
 * \brief Get the next specific_skill_update message in the specific_skill_update message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_specific_skill_update * get_next_specific_skill_update_message(xmachine_message_specific_skill_update * current)
{
	return get_next_message_specific_skill_update_in_range(current->next);
}

/** \fn void freespecific_skill_updatemessages()
 * \brief Free the specific_skill_update message list.
 */
void freespecific_skill_updatemessages()
{
	xmachine_message_specific_skill_update * tmp, * head;
	head = *p_specific_skill_update_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_specific_skill_update_message = NULL;
}

/** \fn xmachine_message_firm_send_data * add_firm_send_data_message_internal()
 * \brief Add firm_send_data message to the local message list.
 * \return The added message.
 */
xmachine_message_firm_send_data * add_firm_send_data_message_internal()
{
	xmachine_message_firm_send_data * current = (xmachine_message_firm_send_data *)malloc(sizeof(xmachine_message_firm_send_data));
	CHECK_POINTER(current);

	current->next = *p_firm_send_data_message;
	*p_firm_send_data_message = current;
	
	return current;
}

/** \fn void process_firm_send_data_message(xmachine_message_firm_send_data * current)
 * \brief Process firm_send_data message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_firm_send_data_message(xmachine_message_firm_send_data * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_firm_send_data * temp_send_message;
	
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
				p_firm_send_data_message = &node_info->firm_send_data_messages;
				temp_send_message = add_firm_send_data_message_internal();
				
				temp_send_message->firm_id = current->firm_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->vacancies = current->vacancies;
				temp_send_message->employees = current->employees;
				temp_send_message->employees_skill_1 = current->employees_skill_1;
				temp_send_message->employees_skill_2 = current->employees_skill_2;
				temp_send_message->employees_skill_3 = current->employees_skill_3;
				temp_send_message->employees_skill_4 = current->employees_skill_4;
				temp_send_message->employees_skill_5 = current->employees_skill_5;
				temp_send_message->average_wage = current->average_wage;
				temp_send_message->average_s_skill = current->average_s_skill;
				temp_send_message->average_s_skill_1 = current->average_s_skill_1;
				temp_send_message->average_s_skill_2 = current->average_s_skill_2;
				temp_send_message->average_s_skill_3 = current->average_s_skill_3;
				temp_send_message->average_s_skill_4 = current->average_s_skill_4;
				temp_send_message->average_s_skill_5 = current->average_s_skill_5;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_firm_send_data_message = &current_node->firm_send_data_messages;
	}
}

/** \fn void add_firm_send_data_message(int firm_id, int region_id, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double range, double x, double y, double z)
 * \brief Add firm_send_data message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param vacancies Message variable.
 * \param employees Message variable.
 * \param employees_skill_1 Message variable.
 * \param employees_skill_2 Message variable.
 * \param employees_skill_3 Message variable.
 * \param employees_skill_4 Message variable.
 * \param employees_skill_5 Message variable.
 * \param average_wage Message variable.
 * \param average_s_skill Message variable.
 * \param average_s_skill_1 Message variable.
 * \param average_s_skill_2 Message variable.
 * \param average_s_skill_3 Message variable.
 * \param average_s_skill_4 Message variable.
 * \param average_s_skill_5 Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_firm_send_data_message(int firm_id, int region_id, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double range, double x, double y, double z)
{

	p_firm_send_data_message = &current_node->firm_send_data_messages;
	xmachine_message_firm_send_data * tmp = add_firm_send_data_message_internal();
	
	tmp->firm_id = firm_id;
	tmp->region_id = region_id;
	tmp->vacancies = vacancies;
	tmp->employees = employees;
	tmp->employees_skill_1 = employees_skill_1;
	tmp->employees_skill_2 = employees_skill_2;
	tmp->employees_skill_3 = employees_skill_3;
	tmp->employees_skill_4 = employees_skill_4;
	tmp->employees_skill_5 = employees_skill_5;
	tmp->average_wage = average_wage;
	tmp->average_s_skill = average_s_skill;
	tmp->average_s_skill_1 = average_s_skill_1;
	tmp->average_s_skill_2 = average_s_skill_2;
	tmp->average_s_skill_3 = average_s_skill_3;
	tmp->average_s_skill_4 = average_s_skill_4;
	tmp->average_s_skill_5 = average_s_skill_5;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_firm_send_data_message(tmp);
}

xmachine_message_firm_send_data * get_next_message_firm_send_data_in_range(xmachine_message_firm_send_data * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_firm_send_data * get_first_firm_send_data_message()
 * \brief Get the first firm_send_data message in the firm_send_data message list.
 * \return The first message in the list.
 */
xmachine_message_firm_send_data * get_first_firm_send_data_message()
{
	return get_next_message_firm_send_data_in_range(*p_firm_send_data_message);
}

/** \fn xmachine_message_firm_send_data * get_next_firm_send_data_message(xmachine_message_firm_send_data * current)
 * \brief Get the next firm_send_data message in the firm_send_data message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_firm_send_data * get_next_firm_send_data_message(xmachine_message_firm_send_data * current)
{
	return get_next_message_firm_send_data_in_range(current->next);
}

/** \fn void freefirm_send_datamessages()
 * \brief Free the firm_send_data message list.
 */
void freefirm_send_datamessages()
{
	xmachine_message_firm_send_data * tmp, * head;
	head = *p_firm_send_data_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_firm_send_data_message = NULL;
}

/** \fn xmachine_message_household_send_data * add_household_send_data_message_internal()
 * \brief Add household_send_data message to the local message list.
 * \return The added message.
 */
xmachine_message_household_send_data * add_household_send_data_message_internal()
{
	xmachine_message_household_send_data * current = (xmachine_message_household_send_data *)malloc(sizeof(xmachine_message_household_send_data));
	CHECK_POINTER(current);

	current->next = *p_household_send_data_message;
	*p_household_send_data_message = current;
	
	return current;
}

/** \fn void process_household_send_data_message(xmachine_message_household_send_data * current)
 * \brief Process household_send_data message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_household_send_data_message(xmachine_message_household_send_data * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_household_send_data * temp_send_message;
	
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
				p_household_send_data_message = &node_info->household_send_data_messages;
				temp_send_message = add_household_send_data_message_internal();
				
				temp_send_message->household_id = current->household_id;
				temp_send_message->region_id = current->region_id;
				temp_send_message->general_skill = current->general_skill;
				temp_send_message->employment_status = current->employment_status;
				temp_send_message->wage = current->wage;
				temp_send_message->specific_skill = current->specific_skill;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_household_send_data_message = &current_node->household_send_data_messages;
	}
}

/** \fn void add_household_send_data_message(int household_id, int region_id, int general_skill, int employment_status, double wage, double specific_skill, double range, double x, double y, double z)
 * \brief Add household_send_data message by calling internal and processing.
 * \param household_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param employment_status Message variable.
 * \param wage Message variable.
 * \param specific_skill Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_household_send_data_message(int household_id, int region_id, int general_skill, int employment_status, double wage, double specific_skill, double range, double x, double y, double z)
{

	p_household_send_data_message = &current_node->household_send_data_messages;
	xmachine_message_household_send_data * tmp = add_household_send_data_message_internal();
	
	tmp->household_id = household_id;
	tmp->region_id = region_id;
	tmp->general_skill = general_skill;
	tmp->employment_status = employment_status;
	tmp->wage = wage;
	tmp->specific_skill = specific_skill;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_household_send_data_message(tmp);
}

xmachine_message_household_send_data * get_next_message_household_send_data_in_range(xmachine_message_household_send_data * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_household_send_data * get_first_household_send_data_message()
 * \brief Get the first household_send_data message in the household_send_data message list.
 * \return The first message in the list.
 */
xmachine_message_household_send_data * get_first_household_send_data_message()
{
	return get_next_message_household_send_data_in_range(*p_household_send_data_message);
}

/** \fn xmachine_message_household_send_data * get_next_household_send_data_message(xmachine_message_household_send_data * current)
 * \brief Get the next household_send_data message in the household_send_data message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_household_send_data * get_next_household_send_data_message(xmachine_message_household_send_data * current)
{
	return get_next_message_household_send_data_in_range(current->next);
}

/** \fn void freehousehold_send_datamessages()
 * \brief Free the household_send_data message list.
 */
void freehousehold_send_datamessages()
{
	xmachine_message_household_send_data * tmp, * head;
	head = *p_household_send_data_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_household_send_data_message = NULL;
}

/** \fn xmachine_message_market_research_send_specific_skills * add_market_research_send_specific_skills_message_internal()
 * \brief Add market_research_send_specific_skills message to the local message list.
 * \return The added message.
 */
xmachine_message_market_research_send_specific_skills * add_market_research_send_specific_skills_message_internal()
{
	xmachine_message_market_research_send_specific_skills * current = (xmachine_message_market_research_send_specific_skills *)malloc(sizeof(xmachine_message_market_research_send_specific_skills));
	CHECK_POINTER(current);

	current->next = *p_market_research_send_specific_skills_message;
	*p_market_research_send_specific_skills_message = current;
	
	return current;
}

/** \fn void process_market_research_send_specific_skills_message(xmachine_message_market_research_send_specific_skills * current)
 * \brief Process market_research_send_specific_skills message to calculate if it needs to be sent to another node.
 * \param current The message to be processed.
 */
void process_market_research_send_specific_skills_message(xmachine_message_market_research_send_specific_skills * current)
{
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double max_mess_dist;
	int in_halo_region = 0;
	node_information * node_info;
	xmachine_message_market_research_send_specific_skills * temp_send_message;
	
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
				p_market_research_send_specific_skills_message = &node_info->market_research_send_specific_skills_messages;
				temp_send_message = add_market_research_send_specific_skills_message_internal();
				
				temp_send_message->region_id = current->region_id;
				temp_send_message->specific_skill_1 = current->specific_skill_1;
				temp_send_message->specific_skill_2 = current->specific_skill_2;
				temp_send_message->specific_skill_3 = current->specific_skill_3;
				temp_send_message->specific_skill_4 = current->specific_skill_4;
				temp_send_message->specific_skill_5 = current->specific_skill_5;
				temp_send_message->range = current->range;
				temp_send_message->x = current->x;
				temp_send_message->y = current->y;
				temp_send_message->z = current->z;
			}
			node_info = node_info->next;
		}
		
		p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
	}
}

/** \fn void add_market_research_send_specific_skills_message(int region_id, double specific_skill_1, double specific_skill_2, double specific_skill_3, double specific_skill_4, double specific_skill_5, double range, double x, double y, double z)
 * \brief Add market_research_send_specific_skills message by calling internal and processing.
 * \param region_id Message variable.
 * \param specific_skill_1 Message variable.
 * \param specific_skill_2 Message variable.
 * \param specific_skill_3 Message variable.
 * \param specific_skill_4 Message variable.
 * \param specific_skill_5 Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_market_research_send_specific_skills_message(int region_id, double specific_skill_1, double specific_skill_2, double specific_skill_3, double specific_skill_4, double specific_skill_5, double range, double x, double y, double z)
{

	p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
	xmachine_message_market_research_send_specific_skills * tmp = add_market_research_send_specific_skills_message_internal();
	
	tmp->region_id = region_id;
	tmp->specific_skill_1 = specific_skill_1;
	tmp->specific_skill_2 = specific_skill_2;
	tmp->specific_skill_3 = specific_skill_3;
	tmp->specific_skill_4 = specific_skill_4;
	tmp->specific_skill_5 = specific_skill_5;
	tmp->range = range;
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	
	/* Check if agent in halo region */
	process_market_research_send_specific_skills_message(tmp);
}

xmachine_message_market_research_send_specific_skills * get_next_message_market_research_send_specific_skills_in_range(xmachine_message_market_research_send_specific_skills * current)
{
	double x = 0.0, y = 0.0, z = 0.0;
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	while(current)
	{
		if( ((x - current->x)*(x - current->x)+(y - current->y)*(y - current->y)) <= current->range*current->range ) return current;
		else current = current->next;
	}
	
	return current;
}

/** \fn xmachine_message_market_research_send_specific_skills * get_first_market_research_send_specific_skills_message()
 * \brief Get the first market_research_send_specific_skills message in the market_research_send_specific_skills message list.
 * \return The first message in the list.
 */
xmachine_message_market_research_send_specific_skills * get_first_market_research_send_specific_skills_message()
{
	return get_next_message_market_research_send_specific_skills_in_range(*p_market_research_send_specific_skills_message);
}

/** \fn xmachine_message_market_research_send_specific_skills * get_next_market_research_send_specific_skills_message(xmachine_message_market_research_send_specific_skills * current)
 * \brief Get the next market_research_send_specific_skills message in the market_research_send_specific_skills message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
xmachine_message_market_research_send_specific_skills * get_next_market_research_send_specific_skills_message(xmachine_message_market_research_send_specific_skills * current)
{
	return get_next_message_market_research_send_specific_skills_in_range(current->next);
}

/** \fn void freemarket_research_send_specific_skillsmessages()
 * \brief Free the market_research_send_specific_skills message list.
 */
void freemarket_research_send_specific_skillsmessages()
{
	xmachine_message_market_research_send_specific_skills * tmp, * head;
	head = *p_market_research_send_specific_skills_message;
	
	while(head)
	{
		tmp = head->next;
		
		free(head);
		head = tmp;
	}
	
	*p_market_research_send_specific_skills_message = NULL;
}

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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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
	
	
	if(current_xmachine->xmachine_Firm)
	{
		x = (double)current_xmachine->xmachine_Firm->posx;
		y = (double)current_xmachine->xmachine_Firm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Household)
	{
		x = (double)current_xmachine->xmachine_Household->posx;
		y = (double)current_xmachine->xmachine_Household->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Mall)
	{
		x = (double)current_xmachine->xmachine_Mall->posx;
		y = (double)current_xmachine->xmachine_Mall->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_IGFirm)
	{
		x = (double)current_xmachine->xmachine_IGFirm->posx;
		y = (double)current_xmachine->xmachine_IGFirm->posy;
		z = 0.0;
	}
	if(current_xmachine->xmachine_Market_Research)
	{
		x = (double)current_xmachine->xmachine_Market_Research->posx;
		y = (double)current_xmachine->xmachine_Market_Research->posy;
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

