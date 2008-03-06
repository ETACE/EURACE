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
	temp_rule_performance_message = NULL;
	p_rule_performance_message = &temp_rule_performance_message;
	temp_new_performances_message = NULL;
	p_new_performances_message = &temp_new_performances_message;
	temp_rule_details_message = NULL;
	p_rule_details_message = &temp_rule_details_message;
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
	p_rule_performance_message = &current_node->rule_performance_messages;
	p_new_performances_message = &current_node->new_performances_messages;
	p_rule_details_message = &current_node->rule_details_messages;
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

	current->xmachine_Household = NULL;
	current->xmachine_FinancialAgent = NULL;
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



void init_EWAParameterStruct(EWAParameterStruct * temp)
{
	(*temp).EWA_rho = 0.0;
	(*temp).EWA_phi = 0.0;
	(*temp).EWA_delta = 0.0;
	(*temp).EWA_beta = 0.0;

}

void init_EWAParameterStruct_static_array(EWAParameterStruct * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_EWAParameterStruct(&array[i]);
}

void free_EWAParameterStruct(EWAParameterStruct * temp)
{

}

void free_EWAParameterStruct_static_array(EWAParameterStruct * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_EWAParameterStruct(&array[i]);
}

void copy_EWAParameterStruct(EWAParameterStruct * from, EWAParameterStruct * to)
{
	(*to).EWA_rho = (*from).EWA_rho;
	(*to).EWA_phi = (*from).EWA_phi;
	(*to).EWA_delta = (*from).EWA_delta;
	(*to).EWA_beta = (*from).EWA_beta;
}

void copy_EWAParameterStruct_static_array(EWAParameterStruct * from, EWAParameterStruct * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_EWAParameterStruct(&from[i], &to[i]);
	}
}


void init_PublicClassifierRule(PublicClassifierRule * temp)
{
	(*temp).id = 0;
	(*temp).counter = 0;
	(*temp).performance = 0.0;
	(*temp).avg_performance = 0.0;
	init_double_static_array((*temp).parameters, 10);

}

void init_PublicClassifierRule_static_array(PublicClassifierRule * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_PublicClassifierRule(&array[i]);
}

void free_PublicClassifierRule(PublicClassifierRule * temp)
{

}

void free_PublicClassifierRule_static_array(PublicClassifierRule * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_PublicClassifierRule(&array[i]);
}

void copy_PublicClassifierRule(PublicClassifierRule * from, PublicClassifierRule * to)
{
	(*to).id = (*from).id;
	(*to).counter = (*from).counter;
	(*to).performance = (*from).performance;
	(*to).avg_performance = (*from).avg_performance;
	memcpy((*to).parameters, (*from).parameters, 10*sizeof(double));
}

void copy_PublicClassifierRule_static_array(PublicClassifierRule * from, PublicClassifierRule * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_PublicClassifierRule(&from[i], &to[i]);
	}
}


void init_PrivateClassifierRule(PrivateClassifierRule * temp)
{
	(*temp).id = 0;
	(*temp).my_performance = 0.0;
	(*temp).avg_performance = 0.0;
	(*temp).attraction = 0.0;
	(*temp).choiceprob = 0.0;
	init_double_static_array((*temp).parameters, 10);

}

void init_PrivateClassifierRule_static_array(PrivateClassifierRule * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_PrivateClassifierRule(&array[i]);
}

void free_PrivateClassifierRule(PrivateClassifierRule * temp)
{

}

void free_PrivateClassifierRule_static_array(PrivateClassifierRule * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_PrivateClassifierRule(&array[i]);
}

void copy_PrivateClassifierRule(PrivateClassifierRule * from, PrivateClassifierRule * to)
{
	(*to).id = (*from).id;
	(*to).my_performance = (*from).my_performance;
	(*to).avg_performance = (*from).avg_performance;
	(*to).attraction = (*from).attraction;
	(*to).choiceprob = (*from).choiceprob;
	memcpy((*to).parameters, (*from).parameters, 10*sizeof(double));
}

void copy_PrivateClassifierRule_static_array(PrivateClassifierRule * from, PrivateClassifierRule * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_PrivateClassifierRule(&from[i], &to[i]);
	}
}


void init_SimplePublicClassifierSystem(SimplePublicClassifierSystem * temp)
{
	(*temp).nr_rules = 0;
	init_PublicClassifierRule_static_array((*temp).ruletable, 100);

}

void init_SimplePublicClassifierSystem_static_array(SimplePublicClassifierSystem * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_SimplePublicClassifierSystem(&array[i]);
}

void free_SimplePublicClassifierSystem(SimplePublicClassifierSystem * temp)
{
	free_PublicClassifierRule_static_array((*temp).ruletable, 100);

}

void free_SimplePublicClassifierSystem_static_array(SimplePublicClassifierSystem * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_SimplePublicClassifierSystem(&array[i]);
}

void copy_SimplePublicClassifierSystem(SimplePublicClassifierSystem * from, SimplePublicClassifierSystem * to)
{
	(*to).nr_rules = (*from).nr_rules;
	copy_PublicClassifierRule_static_array((*from).ruletable, (*to).ruletable, 100);
}

void copy_SimplePublicClassifierSystem_static_array(SimplePublicClassifierSystem * from, SimplePublicClassifierSystem * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_SimplePublicClassifierSystem(&from[i], &to[i]);
	}
}


void init_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem * temp)
{
	(*temp).nr_rules = 0;
	(*temp).experience = 0.0;
	(*temp).current_rule = 0;
	init_PrivateClassifierRule_static_array((*temp).ruletable, 100);

}

void init_SimplePrivateClassifierSystem_static_array(SimplePrivateClassifierSystem * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_SimplePrivateClassifierSystem(&array[i]);
}

void free_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem * temp)
{
	free_PrivateClassifierRule_static_array((*temp).ruletable, 100);

}

void free_SimplePrivateClassifierSystem_static_array(SimplePrivateClassifierSystem * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_SimplePrivateClassifierSystem(&array[i]);
}

void copy_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem * from, SimplePrivateClassifierSystem * to)
{
	(*to).nr_rules = (*from).nr_rules;
	(*to).experience = (*from).experience;
	(*to).current_rule = (*from).current_rule;
	copy_PrivateClassifierRule_static_array((*from).ruletable, (*to).ruletable, 100);
}

void copy_SimplePrivateClassifierSystem_static_array(SimplePrivateClassifierSystem * from, SimplePrivateClassifierSystem * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_SimplePrivateClassifierSystem(&from[i], &to[i]);
	}
}


void init_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem * temp)
{
	(*temp).nr_types = 0;
	init_int_array(&(*temp).nr_rules_per_type);
	(*temp).nr_rules = 0;
	init_PublicClassifierRule_static_array((*temp).ruletable, 100);

}

void init_ComplexPublicClassifierSystem_static_array(ComplexPublicClassifierSystem * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_ComplexPublicClassifierSystem(&array[i]);
}

void free_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem * temp)
{
	free_int_array(&(*temp).nr_rules_per_type);
	free_PublicClassifierRule_static_array((*temp).ruletable, 100);

}

void free_ComplexPublicClassifierSystem_static_array(ComplexPublicClassifierSystem * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_ComplexPublicClassifierSystem(&array[i]);
}

void copy_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem * from, ComplexPublicClassifierSystem * to)
{
	(*to).nr_types = (*from).nr_types;
	copy_int_array(&(*from).nr_rules_per_type, &(*to).nr_rules_per_type);
	(*to).nr_rules = (*from).nr_rules;
	copy_PublicClassifierRule_static_array((*from).ruletable, (*to).ruletable, 100);
}

void copy_ComplexPublicClassifierSystem_static_array(ComplexPublicClassifierSystem * from, ComplexPublicClassifierSystem * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_ComplexPublicClassifierSystem(&from[i], &to[i]);
	}
}


void init_ComplexPrivateClassifierSystem(ComplexPrivateClassifierSystem * temp)
{
	(*temp).nr_types = 0;
	init_int_array(&(*temp).nr_rules_per_type);
	(*temp).nr_rules = 0;
	(*temp).experience = 0.0;
	(*temp).current_rule = 0;
	init_PrivateClassifierRule_static_array((*temp).ruletable, 100);

}

void init_ComplexPrivateClassifierSystem_static_array(ComplexPrivateClassifierSystem * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_ComplexPrivateClassifierSystem(&array[i]);
}

void free_ComplexPrivateClassifierSystem(ComplexPrivateClassifierSystem * temp)
{
	free_int_array(&(*temp).nr_rules_per_type);
	free_PrivateClassifierRule_static_array((*temp).ruletable, 100);

}

void free_ComplexPrivateClassifierSystem_static_array(ComplexPrivateClassifierSystem * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_ComplexPrivateClassifierSystem(&array[i]);
}

void copy_ComplexPrivateClassifierSystem(ComplexPrivateClassifierSystem * from, ComplexPrivateClassifierSystem * to)
{
	(*to).nr_types = (*from).nr_types;
	copy_int_array(&(*from).nr_rules_per_type, &(*to).nr_rules_per_type);
	(*to).nr_rules = (*from).nr_rules;
	(*to).experience = (*from).experience;
	(*to).current_rule = (*from).current_rule;
	copy_PrivateClassifierRule_static_array((*from).ruletable, (*to).ruletable, 100);
}

void copy_ComplexPrivateClassifierSystem_static_array(ComplexPrivateClassifierSystem * from, ComplexPrivateClassifierSystem * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_ComplexPrivateClassifierSystem(&from[i], &to[i]);
	}
}



xmachine_memory_Household * init_Household_agent()
{
	xmachine_memory_Household * current = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
	CHECK_POINTER(current);
	
	current->id = 0;
	init_EWAParameterStruct(&current->EWA_parameters);
	init_SimplePrivateClassifierSystem(&current->classifiersystem);
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_Household_agent(xmachine_memory_Household * tmp)
{
	free_EWAParameterStruct(&tmp->EWA_parameters);
	free_SimplePrivateClassifierSystem(&tmp->classifiersystem);
	
}

void add_Household_agent_internal(xmachine_memory_Household * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Household = current;
}

/** \fn void add_Household_agent(int id, EWAParameterStruct * EWA_parameters, SimplePrivateClassifierSystem * classifiersystem, double posx, double posy)
 * \brief Add Household X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param EWA_parameters Variable for the X-machine memory.
 * \param classifiersystem Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Household_agent(int id, EWAParameterStruct EWA_parameters, SimplePrivateClassifierSystem classifiersystem, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Household * current;
	
	init_Household_agent(current);
	new_xmachine->xmachine_Household = current;
	
	current->id = id;
	copy_EWAParameterStruct(&EWA_parameters, &current->EWA_parameters);
	copy_SimplePrivateClassifierSystem(&classifiersystem, &current->classifiersystem);
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_FinancialAgent * init_FinancialAgent_agent()
{
	xmachine_memory_FinancialAgent * current = (xmachine_memory_FinancialAgent *)malloc(sizeof(xmachine_memory_FinancialAgent));
	CHECK_POINTER(current);
	
	current->day_of_month_to_act = 0;
	current->day = 0;
	current->month = 0;
	init_SimplePublicClassifierSystem(&current->classifiersystem);
	current->posx = 0.0;
	current->posy = 0.0;
	
	return current;
}

void free_FinancialAgent_agent(xmachine_memory_FinancialAgent * tmp)
{
	free_SimplePublicClassifierSystem(&tmp->classifiersystem);
	
}

void add_FinancialAgent_agent_internal(xmachine_memory_FinancialAgent * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_FinancialAgent = current;
}

/** \fn void add_FinancialAgent_agent(int day_of_month_to_act, int day, int month, SimplePublicClassifierSystem * classifiersystem, double posx, double posy)
 * \brief Add FinancialAgent X-machine to the current being used X-machine list.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param day Variable for the X-machine memory.
 * \param month Variable for the X-machine memory.
 * \param classifiersystem Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_FinancialAgent_agent(int day_of_month_to_act, int day, int month, SimplePublicClassifierSystem classifiersystem, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_FinancialAgent * current;
	
	init_FinancialAgent_agent(current);
	new_xmachine->xmachine_FinancialAgent = current;
	
	current->day_of_month_to_act = day_of_month_to_act;
	current->day = day;
	current->month = month;
	copy_SimplePublicClassifierSystem(&classifiersystem, &current->classifiersystem);
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
			if(head->xmachine_Household)
			{
				free_Household_agent(head->xmachine_Household);
				free(head->xmachine_Household);
			}
			if(head->xmachine_FinancialAgent)
			{
				free_FinancialAgent_agent(head->xmachine_FinancialAgent);
				free(head->xmachine_FinancialAgent);
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
		if(head->xmachine_Household)
		{
			free_Household_agent(head->xmachine_Household);
			free(head->xmachine_Household);
		}
		if(head->xmachine_FinancialAgent)
		{
			free_FinancialAgent_agent(head->xmachine_FinancialAgent);
			free(head->xmachine_FinancialAgent);
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
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn EWAParameterStruct get_EWA_parameters()
 * \brief Get EWA_parameters memory variable from current X-machine.
 * \return Value for variable.
 */
EWAParameterStruct * get_EWA_parameters()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).EWA_parameters;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn SimplePrivateClassifierSystem get_classifiersystem()
 * \brief Get classifiersystem memory variable from current X-machine.
 * \return Value for variable.
 */
SimplePrivateClassifierSystem * get_classifiersystem()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).classifiersystem;
	if(current_xmachine->xmachine_FinancialAgent) return &(*current_xmachine->xmachine_FinancialAgent).classifiersystem;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_posx(double posx) 
 * \brief Set posx memory variable for current X-machine.
 * \param posx New value for variable.
 */
void set_posx(double posx)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).posx = posx;
	if(current_xmachine->xmachine_FinancialAgent) (*current_xmachine->xmachine_FinancialAgent).posx = posx;
}

/** \fn double get_posx()
 * \brief Get posx memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posx()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).posx;
	if(current_xmachine->xmachine_FinancialAgent) return (*current_xmachine->xmachine_FinancialAgent).posx;

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
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).posy = posy;
	if(current_xmachine->xmachine_FinancialAgent) (*current_xmachine->xmachine_FinancialAgent).posy = posy;
}

/** \fn double get_posy()
 * \brief Get posy memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posy()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).posy;
	if(current_xmachine->xmachine_FinancialAgent) return (*current_xmachine->xmachine_FinancialAgent).posy;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_day_of_month_to_act(int day_of_month_to_act) 
 * \brief Set day_of_month_to_act memory variable for current X-machine.
 * \param day_of_month_to_act New value for variable.
 */
void set_day_of_month_to_act(int day_of_month_to_act)
{
	if(current_xmachine->xmachine_FinancialAgent) (*current_xmachine->xmachine_FinancialAgent).day_of_month_to_act = day_of_month_to_act;
}

/** \fn int get_day_of_month_to_act()
 * \brief Get day_of_month_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_to_act()
{
	if(current_xmachine->xmachine_FinancialAgent) return (*current_xmachine->xmachine_FinancialAgent).day_of_month_to_act;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day(int day) 
 * \brief Set day memory variable for current X-machine.
 * \param day New value for variable.
 */
void set_day(int day)
{
	if(current_xmachine->xmachine_FinancialAgent) (*current_xmachine->xmachine_FinancialAgent).day = day;
}

/** \fn int get_day()
 * \brief Get day memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day()
{
	if(current_xmachine->xmachine_FinancialAgent) return (*current_xmachine->xmachine_FinancialAgent).day;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_month(int month) 
 * \brief Set month memory variable for current X-machine.
 * \param month New value for variable.
 */
void set_month(int month)
{
	if(current_xmachine->xmachine_FinancialAgent) (*current_xmachine->xmachine_FinancialAgent).month = month;
}

/** \fn int get_month()
 * \brief Get month memory variable from current X-machine.
 * \return Value for variable.
 */
int get_month()
{
	if(current_xmachine->xmachine_FinancialAgent) return (*current_xmachine->xmachine_FinancialAgent).month;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;
    if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->;

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->id;
    if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->;

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->posx;
    if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->posx;

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->posy; 
    if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->posy; 

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
	current->rule_performance_messages = NULL;
	current->new_performances_messages = NULL;
	current->rule_details_messages = NULL;


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
	freerule_performancemessages();	freenew_performancesmessages();	freerule_detailsmessages();
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
		if(current_xmachine->xmachine_Household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Household->posx;
			y_xmachine = current_xmachine->xmachine_Household->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_FinancialAgent != NULL)
		{
			x_xmachine = current_xmachine->xmachine_FinancialAgent->posx;
			y_xmachine = current_xmachine->xmachine_FinancialAgent->posy;
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

/* Functions for the EWAParameterStruct datatype */
/** \fn EWAParameterStruct_array * init_EWAParameterStruct_array()
 * \brief Allocate memory for a dynamic EWAParameterStruct array.
 * \return EWAParameterStruct_array Pointer to the new dynamic EWAParameterStruct array.
 */
void init_EWAParameterStruct_array(EWAParameterStruct_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (EWAParameterStruct *)malloc(ARRAY_BLOCK_SIZE * sizeof(EWAParameterStruct));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_EWAParameterStruct_array(EWAParameterStruct_array* array)
* \brief Reset the EWAParameterStruct array to hold nothing.
* \param array Pointer to the dynamic EWAParameterStruct array.
*/
void reset_EWAParameterStruct_array(EWAParameterStruct_array * array)
{
	(*array).size = 0;
}

/** \fn void free_EWAParameterStruct_array(EWAParameterStruct_array * array)
* \brief Free the memory of a dynamic EWAParameterStruct array.
* \param array Pointer to the dynamic EWAParameterStruct array.
*/
void free_EWAParameterStruct_array(EWAParameterStruct_array * array)
{
	free((*array).array);
}

void copy_EWAParameterStruct_array(EWAParameterStruct_array * from, EWAParameterStruct_array * to)
{
	int i;
	
	//to = init_EWAParameterStruct_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_EWAParameterStruct(to, (*from).array[i].EWA_rho, (*from).array[i].EWA_phi, (*from).array[i].EWA_delta, (*from).array[i].EWA_beta);
	}
}

/** \fn void add_EWAParameterStruct(EWAParameterStruct_array * array, double EWA_rho, double EWA_phi, double EWA_delta, double EWA_beta)
* \brief Add an EWAParameterStruct to the dynamic EWAParameterStruct array.
* \param array Pointer to the dynamic EWAParameterStruct array.
* \param new_int The EWAParameterStruct to add
*/
void add_EWAParameterStruct(EWAParameterStruct_array * array, double EWA_rho, double EWA_phi, double EWA_delta, double EWA_beta)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (EWAParameterStruct *)realloc((*array).array, ((*array).total_size * sizeof(EWAParameterStruct)));
	}
	init_EWAParameterStruct(&(*array).array[(*array).size]);
	(*array).array[(*array).size].EWA_rho = EWA_rho;
	(*array).array[(*array).size].EWA_phi = EWA_phi;
	(*array).array[(*array).size].EWA_delta = EWA_delta;
	(*array).array[(*array).size].EWA_beta = EWA_beta;

	(*array).size++;
}

/** \fn void remove_EWAParameterStruct(EWAParameterStruct_array * array, int index)
 * \brief Remove an EWAParameterStruct from a dynamic EWAParameterStruct array.
 * \param array Pointer to the dynamic EWAParameterStruct array.
 * \param index The index of the EWAParameterStruct to remove.
 */
void remove_EWAParameterStruct(EWAParameterStruct_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_EWAParameterStruct(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_EWAParameterStruct(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the PublicClassifierRule datatype */
/** \fn PublicClassifierRule_array * init_PublicClassifierRule_array()
 * \brief Allocate memory for a dynamic PublicClassifierRule array.
 * \return PublicClassifierRule_array Pointer to the new dynamic PublicClassifierRule array.
 */
void init_PublicClassifierRule_array(PublicClassifierRule_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (PublicClassifierRule *)malloc(ARRAY_BLOCK_SIZE * sizeof(PublicClassifierRule));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_PublicClassifierRule_array(PublicClassifierRule_array* array)
* \brief Reset the PublicClassifierRule array to hold nothing.
* \param array Pointer to the dynamic PublicClassifierRule array.
*/
void reset_PublicClassifierRule_array(PublicClassifierRule_array * array)
{
	(*array).size = 0;
}

/** \fn void free_PublicClassifierRule_array(PublicClassifierRule_array * array)
* \brief Free the memory of a dynamic PublicClassifierRule array.
* \param array Pointer to the dynamic PublicClassifierRule array.
*/
void free_PublicClassifierRule_array(PublicClassifierRule_array * array)
{
	free((*array).array);
}

void copy_PublicClassifierRule_array(PublicClassifierRule_array * from, PublicClassifierRule_array * to)
{
	int i;
	
	//to = init_PublicClassifierRule_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_PublicClassifierRule(to, (*from).array[i].id, (*from).array[i].counter, (*from).array[i].performance, (*from).array[i].avg_performance, (*from).array[i].parameters);
	}
}

/** \fn void add_PublicClassifierRule(PublicClassifierRule_array * array, int id, int counter, double performance, double avg_performance, double parameters)
* \brief Add an PublicClassifierRule to the dynamic PublicClassifierRule array.
* \param array Pointer to the dynamic PublicClassifierRule array.
* \param new_int The PublicClassifierRule to add
*/
void add_PublicClassifierRule(PublicClassifierRule_array * array, int id, int counter, double performance, double avg_performance, double * parameters)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (PublicClassifierRule *)realloc((*array).array, ((*array).total_size * sizeof(PublicClassifierRule)));
	}
	init_PublicClassifierRule(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].counter = counter;
	(*array).array[(*array).size].performance = performance;
	(*array).array[(*array).size].avg_performance = avg_performance;
	if(parameters != NULL) memcpy((*array).array[(*array).size].parameters, parameters, 10*sizeof(double));

	(*array).size++;
}

/** \fn void remove_PublicClassifierRule(PublicClassifierRule_array * array, int index)
 * \brief Remove an PublicClassifierRule from a dynamic PublicClassifierRule array.
 * \param array Pointer to the dynamic PublicClassifierRule array.
 * \param index The index of the PublicClassifierRule to remove.
 */
void remove_PublicClassifierRule(PublicClassifierRule_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_PublicClassifierRule(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_PublicClassifierRule(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the PrivateClassifierRule datatype */
/** \fn PrivateClassifierRule_array * init_PrivateClassifierRule_array()
 * \brief Allocate memory for a dynamic PrivateClassifierRule array.
 * \return PrivateClassifierRule_array Pointer to the new dynamic PrivateClassifierRule array.
 */
void init_PrivateClassifierRule_array(PrivateClassifierRule_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (PrivateClassifierRule *)malloc(ARRAY_BLOCK_SIZE * sizeof(PrivateClassifierRule));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_PrivateClassifierRule_array(PrivateClassifierRule_array* array)
* \brief Reset the PrivateClassifierRule array to hold nothing.
* \param array Pointer to the dynamic PrivateClassifierRule array.
*/
void reset_PrivateClassifierRule_array(PrivateClassifierRule_array * array)
{
	(*array).size = 0;
}

/** \fn void free_PrivateClassifierRule_array(PrivateClassifierRule_array * array)
* \brief Free the memory of a dynamic PrivateClassifierRule array.
* \param array Pointer to the dynamic PrivateClassifierRule array.
*/
void free_PrivateClassifierRule_array(PrivateClassifierRule_array * array)
{
	free((*array).array);
}

void copy_PrivateClassifierRule_array(PrivateClassifierRule_array * from, PrivateClassifierRule_array * to)
{
	int i;
	
	//to = init_PrivateClassifierRule_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_PrivateClassifierRule(to, (*from).array[i].id, (*from).array[i].my_performance, (*from).array[i].avg_performance, (*from).array[i].attraction, (*from).array[i].choiceprob, (*from).array[i].parameters);
	}
}

/** \fn void add_PrivateClassifierRule(PrivateClassifierRule_array * array, int id, double my_performance, double avg_performance, double attraction, double choiceprob, double parameters)
* \brief Add an PrivateClassifierRule to the dynamic PrivateClassifierRule array.
* \param array Pointer to the dynamic PrivateClassifierRule array.
* \param new_int The PrivateClassifierRule to add
*/
void add_PrivateClassifierRule(PrivateClassifierRule_array * array, int id, double my_performance, double avg_performance, double attraction, double choiceprob, double * parameters)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (PrivateClassifierRule *)realloc((*array).array, ((*array).total_size * sizeof(PrivateClassifierRule)));
	}
	init_PrivateClassifierRule(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].my_performance = my_performance;
	(*array).array[(*array).size].avg_performance = avg_performance;
	(*array).array[(*array).size].attraction = attraction;
	(*array).array[(*array).size].choiceprob = choiceprob;
	if(parameters != NULL) memcpy((*array).array[(*array).size].parameters, parameters, 10*sizeof(double));

	(*array).size++;
}

/** \fn void remove_PrivateClassifierRule(PrivateClassifierRule_array * array, int index)
 * \brief Remove an PrivateClassifierRule from a dynamic PrivateClassifierRule array.
 * \param array Pointer to the dynamic PrivateClassifierRule array.
 * \param index The index of the PrivateClassifierRule to remove.
 */
void remove_PrivateClassifierRule(PrivateClassifierRule_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_PrivateClassifierRule(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_PrivateClassifierRule(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the SimplePublicClassifierSystem datatype */
/** \fn SimplePublicClassifierSystem_array * init_SimplePublicClassifierSystem_array()
 * \brief Allocate memory for a dynamic SimplePublicClassifierSystem array.
 * \return SimplePublicClassifierSystem_array Pointer to the new dynamic SimplePublicClassifierSystem array.
 */
void init_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (SimplePublicClassifierSystem *)malloc(ARRAY_BLOCK_SIZE * sizeof(SimplePublicClassifierSystem));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array* array)
* \brief Reset the SimplePublicClassifierSystem array to hold nothing.
* \param array Pointer to the dynamic SimplePublicClassifierSystem array.
*/
void reset_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array * array)
{
	(*array).size = 0;
}

/** \fn void free_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array * array)
* \brief Free the memory of a dynamic SimplePublicClassifierSystem array.
* \param array Pointer to the dynamic SimplePublicClassifierSystem array.
*/
void free_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array * array)
{
	free((*array).array);
}

void copy_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array * from, SimplePublicClassifierSystem_array * to)
{
	int i;
	
	//to = init_SimplePublicClassifierSystem_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_SimplePublicClassifierSystem(to, (*from).array[i].nr_rules, (*from).array[i].ruletable);
	}
}

/** \fn void add_SimplePublicClassifierSystem(SimplePublicClassifierSystem_array * array, int nr_rules, PublicClassifierRule * ruletable)
* \brief Add an SimplePublicClassifierSystem to the dynamic SimplePublicClassifierSystem array.
* \param array Pointer to the dynamic SimplePublicClassifierSystem array.
* \param new_int The SimplePublicClassifierSystem to add
*/
void add_SimplePublicClassifierSystem(SimplePublicClassifierSystem_array * array, int nr_rules, PublicClassifierRule * ruletable)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (SimplePublicClassifierSystem *)realloc((*array).array, ((*array).total_size * sizeof(SimplePublicClassifierSystem)));
	}
	init_SimplePublicClassifierSystem(&(*array).array[(*array).size]);
	(*array).array[(*array).size].nr_rules = nr_rules;
	if(ruletable != NULL) copy_PublicClassifierRule_static_array(ruletable, (*array).array[(*array).size].ruletable, 100);

	(*array).size++;
}

/** \fn void remove_SimplePublicClassifierSystem(SimplePublicClassifierSystem_array * array, int index)
 * \brief Remove an SimplePublicClassifierSystem from a dynamic SimplePublicClassifierSystem array.
 * \param array Pointer to the dynamic SimplePublicClassifierSystem array.
 * \param index The index of the SimplePublicClassifierSystem to remove.
 */
void remove_SimplePublicClassifierSystem(SimplePublicClassifierSystem_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_SimplePublicClassifierSystem(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_SimplePublicClassifierSystem(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the SimplePrivateClassifierSystem datatype */
/** \fn SimplePrivateClassifierSystem_array * init_SimplePrivateClassifierSystem_array()
 * \brief Allocate memory for a dynamic SimplePrivateClassifierSystem array.
 * \return SimplePrivateClassifierSystem_array Pointer to the new dynamic SimplePrivateClassifierSystem array.
 */
void init_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (SimplePrivateClassifierSystem *)malloc(ARRAY_BLOCK_SIZE * sizeof(SimplePrivateClassifierSystem));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array* array)
* \brief Reset the SimplePrivateClassifierSystem array to hold nothing.
* \param array Pointer to the dynamic SimplePrivateClassifierSystem array.
*/
void reset_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array * array)
{
	(*array).size = 0;
}

/** \fn void free_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array * array)
* \brief Free the memory of a dynamic SimplePrivateClassifierSystem array.
* \param array Pointer to the dynamic SimplePrivateClassifierSystem array.
*/
void free_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array * array)
{
	free((*array).array);
}

void copy_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array * from, SimplePrivateClassifierSystem_array * to)
{
	int i;
	
	//to = init_SimplePrivateClassifierSystem_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_SimplePrivateClassifierSystem(to, (*from).array[i].nr_rules, (*from).array[i].experience, (*from).array[i].current_rule, (*from).array[i].ruletable);
	}
}

/** \fn void add_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem_array * array, int nr_rules, double experience, int current_rule, PrivateClassifierRule * ruletable)
* \brief Add an SimplePrivateClassifierSystem to the dynamic SimplePrivateClassifierSystem array.
* \param array Pointer to the dynamic SimplePrivateClassifierSystem array.
* \param new_int The SimplePrivateClassifierSystem to add
*/
void add_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem_array * array, int nr_rules, double experience, int current_rule, PrivateClassifierRule * ruletable)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (SimplePrivateClassifierSystem *)realloc((*array).array, ((*array).total_size * sizeof(SimplePrivateClassifierSystem)));
	}
	init_SimplePrivateClassifierSystem(&(*array).array[(*array).size]);
	(*array).array[(*array).size].nr_rules = nr_rules;
	(*array).array[(*array).size].experience = experience;
	(*array).array[(*array).size].current_rule = current_rule;
	if(ruletable != NULL) copy_PrivateClassifierRule_static_array(ruletable, (*array).array[(*array).size].ruletable, 100);

	(*array).size++;
}

/** \fn void remove_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem_array * array, int index)
 * \brief Remove an SimplePrivateClassifierSystem from a dynamic SimplePrivateClassifierSystem array.
 * \param array Pointer to the dynamic SimplePrivateClassifierSystem array.
 * \param index The index of the SimplePrivateClassifierSystem to remove.
 */
void remove_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_SimplePrivateClassifierSystem(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_SimplePrivateClassifierSystem(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the ComplexPublicClassifierSystem datatype */
/** \fn ComplexPublicClassifierSystem_array * init_ComplexPublicClassifierSystem_array()
 * \brief Allocate memory for a dynamic ComplexPublicClassifierSystem array.
 * \return ComplexPublicClassifierSystem_array Pointer to the new dynamic ComplexPublicClassifierSystem array.
 */
void init_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (ComplexPublicClassifierSystem *)malloc(ARRAY_BLOCK_SIZE * sizeof(ComplexPublicClassifierSystem));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array* array)
* \brief Reset the ComplexPublicClassifierSystem array to hold nothing.
* \param array Pointer to the dynamic ComplexPublicClassifierSystem array.
*/
void reset_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array * array)
{
	(*array).size = 0;
}

/** \fn void free_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array * array)
* \brief Free the memory of a dynamic ComplexPublicClassifierSystem array.
* \param array Pointer to the dynamic ComplexPublicClassifierSystem array.
*/
void free_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array * array)
{
	free((*array).array);
}

void copy_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array * from, ComplexPublicClassifierSystem_array * to)
{
	int i;
	
	//to = init_ComplexPublicClassifierSystem_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_ComplexPublicClassifierSystem(to, (*from).array[i].nr_types, &(*from).array[i].nr_rules_per_type, (*from).array[i].nr_rules, (*from).array[i].ruletable);
	}
}

/** \fn void add_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem_array * array, int nr_types, int_array nr_rules_per_type, int nr_rules, PublicClassifierRule * ruletable)
* \brief Add an ComplexPublicClassifierSystem to the dynamic ComplexPublicClassifierSystem array.
* \param array Pointer to the dynamic ComplexPublicClassifierSystem array.
* \param new_int The ComplexPublicClassifierSystem to add
*/
void add_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem_array * array, int nr_types, int_array * nr_rules_per_type, int nr_rules, PublicClassifierRule * ruletable)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (ComplexPublicClassifierSystem *)realloc((*array).array, ((*array).total_size * sizeof(ComplexPublicClassifierSystem)));
	}
	init_ComplexPublicClassifierSystem(&(*array).array[(*array).size]);
	(*array).array[(*array).size].nr_types = nr_types;
	if(nr_rules_per_type != NULL) copy_int_array(nr_rules_per_type, &(*array).array[(*array).size].nr_rules_per_type);
	(*array).array[(*array).size].nr_rules = nr_rules;
	if(ruletable != NULL) copy_PublicClassifierRule_static_array(ruletable, (*array).array[(*array).size].ruletable, 100);

	(*array).size++;
}

/** \fn void remove_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem_array * array, int index)
 * \brief Remove an ComplexPublicClassifierSystem from a dynamic ComplexPublicClassifierSystem array.
 * \param array Pointer to the dynamic ComplexPublicClassifierSystem array.
 * \param index The index of the ComplexPublicClassifierSystem to remove.
 */
void remove_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_ComplexPublicClassifierSystem(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_ComplexPublicClassifierSystem(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the ComplexPrivateClassifierSystem datatype */
/** \fn ComplexPrivateClassifierSystem_array * init_ComplexPrivateClassifierSystem_array()
 * \brief Allocate memory for a dynamic ComplexPrivateClassifierSystem array.
 * \return ComplexPrivateClassifierSystem_array Pointer to the new dynamic ComplexPrivateClassifierSystem array.
 */
void init_ComplexPrivateClassifierSystem_array(ComplexPrivateClassifierSystem_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (ComplexPrivateClassifierSystem *)malloc(ARRAY_BLOCK_SIZE * sizeof(ComplexPrivateClassifierSystem));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_ComplexPrivateClassifierSystem_array(ComplexPrivateClassifierSystem_array* array)
* \brief Reset the ComplexPrivateClassifierSystem array to hold nothing.
* \param array Pointer to the dynamic ComplexPrivateClassifierSystem array.
*/
void reset_ComplexPrivateClassifierSystem_array(ComplexPrivateClassifierSystem_array * array)
{
	(*array).size = 0;
}

/** \fn void free_ComplexPrivateClassifierSystem_array(ComplexPrivateClassifierSystem_array * array)
* \brief Free the memory of a dynamic ComplexPrivateClassifierSystem array.
* \param array Pointer to the dynamic ComplexPrivateClassifierSystem array.
*/
void free_ComplexPrivateClassifierSystem_array(ComplexPrivateClassifierSystem_array * array)
{
	free((*array).array);
}

void copy_ComplexPrivateClassifierSystem_array(ComplexPrivateClassifierSystem_array * from, ComplexPrivateClassifierSystem_array * to)
{
	int i;
	
	//to = init_ComplexPrivateClassifierSystem_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_ComplexPrivateClassifierSystem(to, (*from).array[i].nr_types, &(*from).array[i].nr_rules_per_type, (*from).array[i].nr_rules, (*from).array[i].experience, (*from).array[i].current_rule, (*from).array[i].ruletable);
	}
}

/** \fn void add_ComplexPrivateClassifierSystem(ComplexPrivateClassifierSystem_array * array, int nr_types, int_array nr_rules_per_type, int nr_rules, double experience, int current_rule, PrivateClassifierRule * ruletable)
* \brief Add an ComplexPrivateClassifierSystem to the dynamic ComplexPrivateClassifierSystem array.
* \param array Pointer to the dynamic ComplexPrivateClassifierSystem array.
* \param new_int The ComplexPrivateClassifierSystem to add
*/
void add_ComplexPrivateClassifierSystem(ComplexPrivateClassifierSystem_array * array, int nr_types, int_array * nr_rules_per_type, int nr_rules, double experience, int current_rule, PrivateClassifierRule * ruletable)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (ComplexPrivateClassifierSystem *)realloc((*array).array, ((*array).total_size * sizeof(ComplexPrivateClassifierSystem)));
	}
	init_ComplexPrivateClassifierSystem(&(*array).array[(*array).size]);
	(*array).array[(*array).size].nr_types = nr_types;
	if(nr_rules_per_type != NULL) copy_int_array(nr_rules_per_type, &(*array).array[(*array).size].nr_rules_per_type);
	(*array).array[(*array).size].nr_rules = nr_rules;
	(*array).array[(*array).size].experience = experience;
	(*array).array[(*array).size].current_rule = current_rule;
	if(ruletable != NULL) copy_PrivateClassifierRule_static_array(ruletable, (*array).array[(*array).size].ruletable, 100);

	(*array).size++;
}

/** \fn void remove_ComplexPrivateClassifierSystem(ComplexPrivateClassifierSystem_array * array, int index)
 * \brief Remove an ComplexPrivateClassifierSystem from a dynamic ComplexPrivateClassifierSystem array.
 * \param array Pointer to the dynamic ComplexPrivateClassifierSystem array.
 * \param index The index of the ComplexPrivateClassifierSystem to remove.
 */
void remove_ComplexPrivateClassifierSystem(ComplexPrivateClassifierSystem_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_ComplexPrivateClassifierSystem(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_ComplexPrivateClassifierSystem(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}

