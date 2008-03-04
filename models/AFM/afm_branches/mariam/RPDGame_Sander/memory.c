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
	temp_strategy_i_use_message = NULL;
	p_strategy_i_use_message = &temp_strategy_i_use_message;
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
	p_strategy_i_use_message = &current_node->strategy_i_use_messages;
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

	current->xmachine_GamePlayer = NULL;
	current->xmachine_GameSolver = NULL;
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



void init_strategy_state(strategy_state * temp)
{
	init_int_static_array((*temp).starting_state, 4);
	(*temp).state_name = 0;
	init_int_static_array((*temp).state_ifcooperate, 4);
	init_int_static_array((*temp).state_ifdefect, 4);

}

void init_strategy_state_static_array(strategy_state * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_strategy_state(&array[i]);
}

void free_strategy_state(strategy_state * temp)
{

}

void free_strategy_state_static_array(strategy_state * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_strategy_state(&array[i]);
}

void copy_strategy_state(strategy_state * from, strategy_state * to)
{
	memcpy((*to).starting_state, (*from).starting_state, 4*sizeof(int));
	(*to).state_name = (*from).state_name;
	memcpy((*to).state_ifcooperate, (*from).state_ifcooperate, 4*sizeof(int));
	memcpy((*to).state_ifdefect, (*from).state_ifdefect, 4*sizeof(int));
}

void copy_strategy_state_static_array(strategy_state * from, strategy_state * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_strategy_state(&from[i], &to[i]);
	}
}


void init_payoff_elements(payoff_elements * temp)
{
	init_int_static_array((*temp).payoffs, 2);

}

void init_payoff_elements_static_array(payoff_elements * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_payoff_elements(&array[i]);
}

void free_payoff_elements(payoff_elements * temp)
{

}

void free_payoff_elements_static_array(payoff_elements * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_payoff_elements(&array[i]);
}

void copy_payoff_elements(payoff_elements * from, payoff_elements * to)
{
	memcpy((*to).payoffs, (*from).payoffs, 2*sizeof(int));
}

void copy_payoff_elements_static_array(payoff_elements * from, payoff_elements * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_payoff_elements(&from[i], &to[i]);
	}
}


void init_strategy_data(strategy_data * temp)
{
	(*temp).strategy_id = 0;
	(*temp).strategy_perf = 0.0;

}

void init_strategy_data_static_array(strategy_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_strategy_data(&array[i]);
}

void free_strategy_data(strategy_data * temp)
{

}

void free_strategy_data_static_array(strategy_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_strategy_data(&array[i]);
}

void copy_strategy_data(strategy_data * from, strategy_data * to)
{
	(*to).strategy_id = (*from).strategy_id;
	(*to).strategy_perf = (*from).strategy_perf;
}

void copy_strategy_data_static_array(strategy_data * from, strategy_data * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_strategy_data(&from[i], &to[i]);
	}
}


void init_complete_strategy(complete_strategy * temp)
{
	init_strategy_state_array(&(*temp).strategy_path);

}

void init_complete_strategy_static_array(complete_strategy * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_complete_strategy(&array[i]);
}

void free_complete_strategy(complete_strategy * temp)
{
	free_strategy_state_array(&(*temp).strategy_path);

}

void free_complete_strategy_static_array(complete_strategy * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_complete_strategy(&array[i]);
}

void copy_complete_strategy(complete_strategy * from, complete_strategy * to)
{
	copy_strategy_state_array(&(*from).strategy_path, &(*to).strategy_path);
}

void copy_complete_strategy_static_array(complete_strategy * from, complete_strategy * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_complete_strategy(&from[i], &to[i]);
	}
}


void init_columns(columns * temp)
{
	init_payoff_elements_array(&(*temp).opponents);

}

void init_columns_static_array(columns * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_columns(&array[i]);
}

void free_columns(columns * temp)
{
	free_payoff_elements_array(&(*temp).opponents);

}

void free_columns_static_array(columns * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_columns(&array[i]);
}

void copy_columns(columns * from, columns * to)
{
	copy_payoff_elements_array(&(*from).opponents, &(*to).opponents);
}

void copy_columns_static_array(columns * from, columns * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_columns(&from[i], &to[i]);
	}
}


void init_player_list_element(player_list_element * temp)
{
	(*temp).player_id = 0;
	(*temp).strategy_id = 0;
	(*temp).previous_move = 0;
	(*temp).present_state = 0;

}

void init_player_list_element_static_array(player_list_element * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_player_list_element(&array[i]);
}

void free_player_list_element(player_list_element * temp)
{

}

void free_player_list_element_static_array(player_list_element * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_player_list_element(&array[i]);
}

void copy_player_list_element(player_list_element * from, player_list_element * to)
{
	(*to).player_id = (*from).player_id;
	(*to).strategy_id = (*from).strategy_id;
	(*to).previous_move = (*from).previous_move;
	(*to).present_state = (*from).present_state;
}

void copy_player_list_element_static_array(player_list_element * from, player_list_element * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_player_list_element(&from[i], &to[i]);
	}
}



xmachine_memory_GamePlayer * init_GamePlayer_agent()
{
	xmachine_memory_GamePlayer * current = (xmachine_memory_GamePlayer *)malloc(sizeof(xmachine_memory_GamePlayer));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->strategy_used = 0;
	current->previous_performance = 0;
	current->present_state = 0;
	current->iradius = 0.0;
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_GamePlayer_agent(xmachine_memory_GamePlayer * tmp)
{
	
}

void add_GamePlayer_agent_internal(xmachine_memory_GamePlayer * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_GamePlayer = current;
}

/** \fn void add_GamePlayer_agent(int id, int strategy_used, int previous_performance, int present_state, double iradius, double posx, double posy)
 * \brief Add GamePlayer X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param strategy_used Variable for the X-machine memory.
 * \param previous_performance Variable for the X-machine memory.
 * \param present_state Variable for the X-machine memory.
 * \param iradius Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_GamePlayer_agent(int id, int strategy_used, int previous_performance, int present_state, double iradius, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_GamePlayer * current;
	
	init_GamePlayer_agent(current);
	new_xmachine->xmachine_GamePlayer = current;
	
	current->id = id;
	current->strategy_used = strategy_used;
	current->previous_performance = previous_performance;
	current->present_state = present_state;
	current->iradius = iradius;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_GameSolver * init_GameSolver_agent()
{
	xmachine_memory_GameSolver * current = (xmachine_memory_GameSolver *)malloc(sizeof(xmachine_memory_GameSolver));
	CHECK_POINTER(current);
	
	init_complete_strategy_static_array(current->strategy_list, 30);
	init_complete_strategy_static_array(current->new_children, 10);
	current->nragents = 0;
	init_int_array(&current->automata_id);
	init_int_array(&current->players);
	init_int_static_array(current->player_one_state, 4);
	init_int_static_array(current->player_two_state, 4);
	current->player_one_move = 0;
	current->player_two_move = 0;
	init_strategy_data_static_array(current->strategy_performance, 30);
	init_complete_strategy_static_array(current->offspring, 2);
	init_columns_array(&current->rows);
	init_player_list_element_array(&current->player_list);
	current->iradius = 0.0;
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_GameSolver_agent(xmachine_memory_GameSolver * tmp)
{
	free_complete_strategy_static_array(tmp->strategy_list, 30);
	free_complete_strategy_static_array(tmp->new_children, 10);
	free_int_array(&tmp->automata_id);
	free_int_array(&tmp->players);
	free_strategy_data_static_array(tmp->strategy_performance, 30);
	free_complete_strategy_static_array(tmp->offspring, 2);
	free_columns_array(&tmp->rows);
	free_player_list_element_array(&tmp->player_list);
	
}

void add_GameSolver_agent_internal(xmachine_memory_GameSolver * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_GameSolver = current;
}

/** \fn void add_GameSolver_agent(complete_strategy ** strategy_list, complete_strategy ** new_children, int nragents, int_array * automata_id, int_array * players, int player_one_state[], int player_two_state[], int player_one_move, int player_two_move, strategy_data ** strategy_performance, complete_strategy ** offspring, columns_array * rows, player_list_element_array * player_list, double iradius, double posx, double posy)
 * \brief Add GameSolver X-machine to the current being used X-machine list.
 * \param strategy_list Variable for the X-machine memory.
 * \param new_children Variable for the X-machine memory.
 * \param nragents Variable for the X-machine memory.
 * \param automata_id Variable for the X-machine memory.
 * \param players Variable for the X-machine memory.
 * \param player_one_state Variable for the X-machine memory.
 * \param player_two_state Variable for the X-machine memory.
 * \param player_one_move Variable for the X-machine memory.
 * \param player_two_move Variable for the X-machine memory.
 * \param strategy_performance Variable for the X-machine memory.
 * \param offspring Variable for the X-machine memory.
 * \param rows Variable for the X-machine memory.
 * \param player_list Variable for the X-machine memory.
 * \param iradius Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_GameSolver_agent(complete_strategy strategy_list[], complete_strategy new_children[], int nragents, int_array * automata_id, int_array * players, int player_one_state[], int player_two_state[], int player_one_move, int player_two_move, strategy_data strategy_performance[], complete_strategy offspring[], columns_array * rows, player_list_element_array * player_list, double iradius, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_GameSolver * current;
	
	init_GameSolver_agent(current);
	new_xmachine->xmachine_GameSolver = current;
	
	copy_complete_strategy_static_array(strategy_list, current->strategy_list, 30);
	copy_complete_strategy_static_array(new_children, current->new_children, 10);
	current->nragents = nragents;
	copy_int_array(automata_id, &current->automata_id);
	copy_int_array(players, &current->players);
	memcpy(current->player_one_state, player_one_state, 4*sizeof(int));
	memcpy(current->player_two_state, player_two_state, 4*sizeof(int));
	current->player_one_move = player_one_move;
	current->player_two_move = player_two_move;
	copy_strategy_data_static_array(strategy_performance, current->strategy_performance, 30);
	copy_complete_strategy_static_array(offspring, current->offspring, 2);
	copy_columns_array(rows, &current->rows);
	copy_player_list_element_array(player_list, &current->player_list);
	current->iradius = iradius;
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
			if(head->xmachine_GamePlayer)
			{
				free_GamePlayer_agent(head->xmachine_GamePlayer);
				free(head->xmachine_GamePlayer);
			}
			if(head->xmachine_GameSolver)
			{
				free_GameSolver_agent(head->xmachine_GameSolver);
				free(head->xmachine_GameSolver);
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
		if(head->xmachine_GamePlayer)
		{
			free_GamePlayer_agent(head->xmachine_GamePlayer);
			free(head->xmachine_GamePlayer);
		}
		if(head->xmachine_GameSolver)
		{
			free_GameSolver_agent(head->xmachine_GameSolver);
			free(head->xmachine_GameSolver);
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
	if(current_xmachine->xmachine_GamePlayer) (*current_xmachine->xmachine_GamePlayer).id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_GamePlayer) return (*current_xmachine->xmachine_GamePlayer).id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_strategy_used(int strategy_used) 
 * \brief Set strategy_used memory variable for current X-machine.
 * \param strategy_used New value for variable.
 */
void set_strategy_used(int strategy_used)
{
	if(current_xmachine->xmachine_GamePlayer) (*current_xmachine->xmachine_GamePlayer).strategy_used = strategy_used;
}

/** \fn int get_strategy_used()
 * \brief Get strategy_used memory variable from current X-machine.
 * \return Value for variable.
 */
int get_strategy_used()
{
	if(current_xmachine->xmachine_GamePlayer) return (*current_xmachine->xmachine_GamePlayer).strategy_used;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_previous_performance(int previous_performance) 
 * \brief Set previous_performance memory variable for current X-machine.
 * \param previous_performance New value for variable.
 */
void set_previous_performance(int previous_performance)
{
	if(current_xmachine->xmachine_GamePlayer) (*current_xmachine->xmachine_GamePlayer).previous_performance = previous_performance;
}

/** \fn int get_previous_performance()
 * \brief Get previous_performance memory variable from current X-machine.
 * \return Value for variable.
 */
int get_previous_performance()
{
	if(current_xmachine->xmachine_GamePlayer) return (*current_xmachine->xmachine_GamePlayer).previous_performance;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_present_state(int present_state) 
 * \brief Set present_state memory variable for current X-machine.
 * \param present_state New value for variable.
 */
void set_present_state(int present_state)
{
	if(current_xmachine->xmachine_GamePlayer) (*current_xmachine->xmachine_GamePlayer).present_state = present_state;
}

/** \fn int get_present_state()
 * \brief Get present_state memory variable from current X-machine.
 * \return Value for variable.
 */
int get_present_state()
{
	if(current_xmachine->xmachine_GamePlayer) return (*current_xmachine->xmachine_GamePlayer).present_state;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_iradius(double iradius) 
 * \brief Set iradius memory variable for current X-machine.
 * \param iradius New value for variable.
 */
void set_iradius(double iradius)
{
	if(current_xmachine->xmachine_GamePlayer) (*current_xmachine->xmachine_GamePlayer).iradius = iradius;
	if(current_xmachine->xmachine_GameSolver) (*current_xmachine->xmachine_GameSolver).iradius = iradius;
}

/** \fn double get_iradius()
 * \brief Get iradius memory variable from current X-machine.
 * \return Value for variable.
 */
double get_iradius()
{
	if(current_xmachine->xmachine_GamePlayer) return (*current_xmachine->xmachine_GamePlayer).iradius;
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).iradius;

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
	if(current_xmachine->xmachine_GamePlayer) (*current_xmachine->xmachine_GamePlayer).posx = posx;
	if(current_xmachine->xmachine_GameSolver) (*current_xmachine->xmachine_GameSolver).posx = posx;
}

/** \fn double get_posx()
 * \brief Get posx memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posx()
{
	if(current_xmachine->xmachine_GamePlayer) return (*current_xmachine->xmachine_GamePlayer).posx;
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).posx;

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
	if(current_xmachine->xmachine_GamePlayer) (*current_xmachine->xmachine_GamePlayer).posy = posy;
	if(current_xmachine->xmachine_GameSolver) (*current_xmachine->xmachine_GameSolver).posy = posy;
}

/** \fn double get_posy()
 * \brief Get posy memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posy()
{
	if(current_xmachine->xmachine_GamePlayer) return (*current_xmachine->xmachine_GamePlayer).posy;
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).posy;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn complete_strategy get_strategy_list()
 * \brief Get strategy_list memory variable from current X-machine.
 * \return Value for variable.
 */
complete_strategy * get_strategy_list()
{
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).strategy_list;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn complete_strategy get_new_children()
 * \brief Get new_children memory variable from current X-machine.
 * \return Value for variable.
 */
complete_strategy * get_new_children()
{
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).new_children;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_nragents(int nragents) 
 * \brief Set nragents memory variable for current X-machine.
 * \param nragents New value for variable.
 */
void set_nragents(int nragents)
{
	if(current_xmachine->xmachine_GameSolver) (*current_xmachine->xmachine_GameSolver).nragents = nragents;
}

/** \fn int get_nragents()
 * \brief Get nragents memory variable from current X-machine.
 * \return Value for variable.
 */
int get_nragents()
{
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).nragents;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn int_array get_automata_id()
 * \brief Get automata_id memory variable from current X-machine.
 * \return Value for variable.
 */
int_array * get_automata_id()
{
	if(current_xmachine->xmachine_GameSolver) return &(*current_xmachine->xmachine_GameSolver).automata_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn int_array get_players()
 * \brief Get players memory variable from current X-machine.
 * \return Value for variable.
 */
int_array * get_players()
{
	if(current_xmachine->xmachine_GameSolver) return &(*current_xmachine->xmachine_GameSolver).players;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn int get_player_one_state()
 * \brief Get player_one_state memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_player_one_state()
{
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).player_one_state;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn int get_player_two_state()
 * \brief Get player_two_state memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_player_two_state()
{
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).player_two_state;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_player_one_move(int player_one_move) 
 * \brief Set player_one_move memory variable for current X-machine.
 * \param player_one_move New value for variable.
 */
void set_player_one_move(int player_one_move)
{
	if(current_xmachine->xmachine_GameSolver) (*current_xmachine->xmachine_GameSolver).player_one_move = player_one_move;
}

/** \fn int get_player_one_move()
 * \brief Get player_one_move memory variable from current X-machine.
 * \return Value for variable.
 */
int get_player_one_move()
{
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).player_one_move;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_player_two_move(int player_two_move) 
 * \brief Set player_two_move memory variable for current X-machine.
 * \param player_two_move New value for variable.
 */
void set_player_two_move(int player_two_move)
{
	if(current_xmachine->xmachine_GameSolver) (*current_xmachine->xmachine_GameSolver).player_two_move = player_two_move;
}

/** \fn int get_player_two_move()
 * \brief Get player_two_move memory variable from current X-machine.
 * \return Value for variable.
 */
int get_player_two_move()
{
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).player_two_move;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn strategy_data get_strategy_performance()
 * \brief Get strategy_performance memory variable from current X-machine.
 * \return Value for variable.
 */
strategy_data * get_strategy_performance()
{
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).strategy_performance;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn complete_strategy get_offspring()
 * \brief Get offspring memory variable from current X-machine.
 * \return Value for variable.
 */
complete_strategy * get_offspring()
{
	if(current_xmachine->xmachine_GameSolver) return (*current_xmachine->xmachine_GameSolver).offspring;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn columns_array get_rows()
 * \brief Get rows memory variable from current X-machine.
 * \return Value for variable.
 */
columns_array * get_rows()
{
	if(current_xmachine->xmachine_GameSolver) return &(*current_xmachine->xmachine_GameSolver).rows;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn player_list_element_array get_player_list()
 * \brief Get player_list memory variable from current X-machine.
 * \return Value for variable.
 */
player_list_element_array * get_player_list()
{
	if(current_xmachine->xmachine_GameSolver) return &(*current_xmachine->xmachine_GameSolver).player_list;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    if (current_xmachine->xmachine_GamePlayer) value = current_xmachine->xmachine_GamePlayer->;
    if (current_xmachine->xmachine_GameSolver) value = current_xmachine->xmachine_GameSolver->;

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    if (current_xmachine->xmachine_GamePlayer) value = current_xmachine->xmachine_GamePlayer->id;
    if (current_xmachine->xmachine_GameSolver) value = current_xmachine->xmachine_GameSolver->;

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    if (current_xmachine->xmachine_GamePlayer) value = current_xmachine->xmachine_GamePlayer->posx;
    if (current_xmachine->xmachine_GameSolver) value = current_xmachine->xmachine_GameSolver->posx;

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    if (current_xmachine->xmachine_GamePlayer) value = current_xmachine->xmachine_GamePlayer->posy; 
    if (current_xmachine->xmachine_GameSolver) value = current_xmachine->xmachine_GameSolver->posy; 

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
	current->strategy_i_use_messages = NULL;


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
	freestrategy_i_usemessages();
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
		if(current_xmachine->xmachine_GamePlayer != NULL)
		{
			x_xmachine = current_xmachine->xmachine_GamePlayer->posx;
			y_xmachine = current_xmachine->xmachine_GamePlayer->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_GameSolver != NULL)
		{
			x_xmachine = current_xmachine->xmachine_GameSolver->posx;
			y_xmachine = current_xmachine->xmachine_GameSolver->posy;
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

/* Functions for the strategy_state datatype */
/** \fn strategy_state_array * init_strategy_state_array()
 * \brief Allocate memory for a dynamic strategy_state array.
 * \return strategy_state_array Pointer to the new dynamic strategy_state array.
 */
void init_strategy_state_array(strategy_state_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (strategy_state *)malloc(ARRAY_BLOCK_SIZE * sizeof(strategy_state));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_strategy_state_array(strategy_state_array* array)
* \brief Reset the strategy_state array to hold nothing.
* \param array Pointer to the dynamic strategy_state array.
*/
void reset_strategy_state_array(strategy_state_array * array)
{
	(*array).size = 0;
}

/** \fn void free_strategy_state_array(strategy_state_array * array)
* \brief Free the memory of a dynamic strategy_state array.
* \param array Pointer to the dynamic strategy_state array.
*/
void free_strategy_state_array(strategy_state_array * array)
{
	free((*array).array);
}

void copy_strategy_state_array(strategy_state_array * from, strategy_state_array * to)
{
	int i;
	
	//to = init_strategy_state_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_strategy_state(to, (*from).array[i].starting_state, (*from).array[i].state_name, (*from).array[i].state_ifcooperate, (*from).array[i].state_ifdefect);
	}
}

/** \fn void add_strategy_state(strategy_state_array * array, int starting_state, int state_name, int state_ifcooperate, int state_ifdefect)
* \brief Add an strategy_state to the dynamic strategy_state array.
* \param array Pointer to the dynamic strategy_state array.
* \param new_int The strategy_state to add
*/
void add_strategy_state(strategy_state_array * array, int * starting_state, int state_name, int * state_ifcooperate, int * state_ifdefect)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (strategy_state *)realloc((*array).array, ((*array).total_size * sizeof(strategy_state)));
	}
	init_strategy_state(&(*array).array[(*array).size]);
	if(starting_state != NULL) memcpy((*array).array[(*array).size].starting_state, starting_state, 4*sizeof(int));
	(*array).array[(*array).size].state_name = state_name;
	if(state_ifcooperate != NULL) memcpy((*array).array[(*array).size].state_ifcooperate, state_ifcooperate, 4*sizeof(int));
	if(state_ifdefect != NULL) memcpy((*array).array[(*array).size].state_ifdefect, state_ifdefect, 4*sizeof(int));

	(*array).size++;
}

/** \fn void remove_strategy_state(strategy_state_array * array, int index)
 * \brief Remove an strategy_state from a dynamic strategy_state array.
 * \param array Pointer to the dynamic strategy_state array.
 * \param index The index of the strategy_state to remove.
 */
void remove_strategy_state(strategy_state_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_strategy_state(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_strategy_state(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the payoff_elements datatype */
/** \fn payoff_elements_array * init_payoff_elements_array()
 * \brief Allocate memory for a dynamic payoff_elements array.
 * \return payoff_elements_array Pointer to the new dynamic payoff_elements array.
 */
void init_payoff_elements_array(payoff_elements_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (payoff_elements *)malloc(ARRAY_BLOCK_SIZE * sizeof(payoff_elements));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_payoff_elements_array(payoff_elements_array* array)
* \brief Reset the payoff_elements array to hold nothing.
* \param array Pointer to the dynamic payoff_elements array.
*/
void reset_payoff_elements_array(payoff_elements_array * array)
{
	(*array).size = 0;
}

/** \fn void free_payoff_elements_array(payoff_elements_array * array)
* \brief Free the memory of a dynamic payoff_elements array.
* \param array Pointer to the dynamic payoff_elements array.
*/
void free_payoff_elements_array(payoff_elements_array * array)
{
	free((*array).array);
}

void copy_payoff_elements_array(payoff_elements_array * from, payoff_elements_array * to)
{
	int i;
	
	//to = init_payoff_elements_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_payoff_elements(to, (*from).array[i].payoffs);
	}
}

/** \fn void add_payoff_elements(payoff_elements_array * array, int payoffs)
* \brief Add an payoff_elements to the dynamic payoff_elements array.
* \param array Pointer to the dynamic payoff_elements array.
* \param new_int The payoff_elements to add
*/
void add_payoff_elements(payoff_elements_array * array, int * payoffs)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (payoff_elements *)realloc((*array).array, ((*array).total_size * sizeof(payoff_elements)));
	}
	init_payoff_elements(&(*array).array[(*array).size]);
	if(payoffs != NULL) memcpy((*array).array[(*array).size].payoffs, payoffs, 2*sizeof(int));

	(*array).size++;
}

/** \fn void remove_payoff_elements(payoff_elements_array * array, int index)
 * \brief Remove an payoff_elements from a dynamic payoff_elements array.
 * \param array Pointer to the dynamic payoff_elements array.
 * \param index The index of the payoff_elements to remove.
 */
void remove_payoff_elements(payoff_elements_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_payoff_elements(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_payoff_elements(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the strategy_data datatype */
/** \fn strategy_data_array * init_strategy_data_array()
 * \brief Allocate memory for a dynamic strategy_data array.
 * \return strategy_data_array Pointer to the new dynamic strategy_data array.
 */
void init_strategy_data_array(strategy_data_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (strategy_data *)malloc(ARRAY_BLOCK_SIZE * sizeof(strategy_data));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_strategy_data_array(strategy_data_array* array)
* \brief Reset the strategy_data array to hold nothing.
* \param array Pointer to the dynamic strategy_data array.
*/
void reset_strategy_data_array(strategy_data_array * array)
{
	(*array).size = 0;
}

/** \fn void free_strategy_data_array(strategy_data_array * array)
* \brief Free the memory of a dynamic strategy_data array.
* \param array Pointer to the dynamic strategy_data array.
*/
void free_strategy_data_array(strategy_data_array * array)
{
	free((*array).array);
}

void copy_strategy_data_array(strategy_data_array * from, strategy_data_array * to)
{
	int i;
	
	//to = init_strategy_data_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_strategy_data(to, (*from).array[i].strategy_id, (*from).array[i].strategy_perf);
	}
}

/** \fn void add_strategy_data(strategy_data_array * array, int strategy_id, double strategy_perf)
* \brief Add an strategy_data to the dynamic strategy_data array.
* \param array Pointer to the dynamic strategy_data array.
* \param new_int The strategy_data to add
*/
void add_strategy_data(strategy_data_array * array, int strategy_id, double strategy_perf)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (strategy_data *)realloc((*array).array, ((*array).total_size * sizeof(strategy_data)));
	}
	init_strategy_data(&(*array).array[(*array).size]);
	(*array).array[(*array).size].strategy_id = strategy_id;
	(*array).array[(*array).size].strategy_perf = strategy_perf;

	(*array).size++;
}

/** \fn void remove_strategy_data(strategy_data_array * array, int index)
 * \brief Remove an strategy_data from a dynamic strategy_data array.
 * \param array Pointer to the dynamic strategy_data array.
 * \param index The index of the strategy_data to remove.
 */
void remove_strategy_data(strategy_data_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_strategy_data(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_strategy_data(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the complete_strategy datatype */
/** \fn complete_strategy_array * init_complete_strategy_array()
 * \brief Allocate memory for a dynamic complete_strategy array.
 * \return complete_strategy_array Pointer to the new dynamic complete_strategy array.
 */
void init_complete_strategy_array(complete_strategy_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (complete_strategy *)malloc(ARRAY_BLOCK_SIZE * sizeof(complete_strategy));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_complete_strategy_array(complete_strategy_array* array)
* \brief Reset the complete_strategy array to hold nothing.
* \param array Pointer to the dynamic complete_strategy array.
*/
void reset_complete_strategy_array(complete_strategy_array * array)
{
	(*array).size = 0;
}

/** \fn void free_complete_strategy_array(complete_strategy_array * array)
* \brief Free the memory of a dynamic complete_strategy array.
* \param array Pointer to the dynamic complete_strategy array.
*/
void free_complete_strategy_array(complete_strategy_array * array)
{
	free((*array).array);
}

void copy_complete_strategy_array(complete_strategy_array * from, complete_strategy_array * to)
{
	int i;
	
	//to = init_complete_strategy_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_complete_strategy(to, &(*from).array[i].strategy_path);
	}
}

/** \fn void add_complete_strategy(complete_strategy_array * array, strategy_state_array * strategy_path)
* \brief Add an complete_strategy to the dynamic complete_strategy array.
* \param array Pointer to the dynamic complete_strategy array.
* \param new_int The complete_strategy to add
*/
void add_complete_strategy(complete_strategy_array * array, strategy_state_array * strategy_path)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (complete_strategy *)realloc((*array).array, ((*array).total_size * sizeof(complete_strategy)));
	}
	init_complete_strategy(&(*array).array[(*array).size]);
	if(strategy_path != NULL) copy_strategy_state_array(strategy_path, &(*array).array[(*array).size].strategy_path);

	(*array).size++;
}

/** \fn void remove_complete_strategy(complete_strategy_array * array, int index)
 * \brief Remove an complete_strategy from a dynamic complete_strategy array.
 * \param array Pointer to the dynamic complete_strategy array.
 * \param index The index of the complete_strategy to remove.
 */
void remove_complete_strategy(complete_strategy_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_complete_strategy(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_complete_strategy(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the columns datatype */
/** \fn columns_array * init_columns_array()
 * \brief Allocate memory for a dynamic columns array.
 * \return columns_array Pointer to the new dynamic columns array.
 */
void init_columns_array(columns_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (columns *)malloc(ARRAY_BLOCK_SIZE * sizeof(columns));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_columns_array(columns_array* array)
* \brief Reset the columns array to hold nothing.
* \param array Pointer to the dynamic columns array.
*/
void reset_columns_array(columns_array * array)
{
	(*array).size = 0;
}

/** \fn void free_columns_array(columns_array * array)
* \brief Free the memory of a dynamic columns array.
* \param array Pointer to the dynamic columns array.
*/
void free_columns_array(columns_array * array)
{
	free((*array).array);
}

void copy_columns_array(columns_array * from, columns_array * to)
{
	int i;
	
	//to = init_columns_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_columns(to, &(*from).array[i].opponents);
	}
}

/** \fn void add_columns(columns_array * array, payoff_elements_array * opponents)
* \brief Add an columns to the dynamic columns array.
* \param array Pointer to the dynamic columns array.
* \param new_int The columns to add
*/
void add_columns(columns_array * array, payoff_elements_array * opponents)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (columns *)realloc((*array).array, ((*array).total_size * sizeof(columns)));
	}
	init_columns(&(*array).array[(*array).size]);
	if(opponents != NULL) copy_payoff_elements_array(opponents, &(*array).array[(*array).size].opponents);

	(*array).size++;
}

/** \fn void remove_columns(columns_array * array, int index)
 * \brief Remove an columns from a dynamic columns array.
 * \param array Pointer to the dynamic columns array.
 * \param index The index of the columns to remove.
 */
void remove_columns(columns_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_columns(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_columns(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the player_list_element datatype */
/** \fn player_list_element_array * init_player_list_element_array()
 * \brief Allocate memory for a dynamic player_list_element array.
 * \return player_list_element_array Pointer to the new dynamic player_list_element array.
 */
void init_player_list_element_array(player_list_element_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (player_list_element *)malloc(ARRAY_BLOCK_SIZE * sizeof(player_list_element));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_player_list_element_array(player_list_element_array* array)
* \brief Reset the player_list_element array to hold nothing.
* \param array Pointer to the dynamic player_list_element array.
*/
void reset_player_list_element_array(player_list_element_array * array)
{
	(*array).size = 0;
}

/** \fn void free_player_list_element_array(player_list_element_array * array)
* \brief Free the memory of a dynamic player_list_element array.
* \param array Pointer to the dynamic player_list_element array.
*/
void free_player_list_element_array(player_list_element_array * array)
{
	free((*array).array);
}

void copy_player_list_element_array(player_list_element_array * from, player_list_element_array * to)
{
	int i;
	
	//to = init_player_list_element_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_player_list_element(to, (*from).array[i].player_id, (*from).array[i].strategy_id, (*from).array[i].previous_move, (*from).array[i].present_state);
	}
}

/** \fn void add_player_list_element(player_list_element_array * array, int player_id, int strategy_id, int previous_move, int present_state)
* \brief Add an player_list_element to the dynamic player_list_element array.
* \param array Pointer to the dynamic player_list_element array.
* \param new_int The player_list_element to add
*/
void add_player_list_element(player_list_element_array * array, int player_id, int strategy_id, int previous_move, int present_state)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (player_list_element *)realloc((*array).array, ((*array).total_size * sizeof(player_list_element)));
	}
	init_player_list_element(&(*array).array[(*array).size]);
	(*array).array[(*array).size].player_id = player_id;
	(*array).array[(*array).size].strategy_id = strategy_id;
	(*array).array[(*array).size].previous_move = previous_move;
	(*array).array[(*array).size].present_state = present_state;

	(*array).size++;
}

/** \fn void remove_player_list_element(player_list_element_array * array, int index)
 * \brief Remove an player_list_element from a dynamic player_list_element array.
 * \param array Pointer to the dynamic player_list_element array.
 * \param index The index of the player_list_element to remove.
 */
void remove_player_list_element(player_list_element_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_player_list_element(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_player_list_element(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}

