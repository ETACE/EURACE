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
    int rc;
	//temp_xmachine = NULL;
	//p_xmachine = &temp_xmachine;
	//temp_xmachine_Household_03 = NULL;
	Household_03_state = init_Household_state();//&temp_xmachine_Household_03;
	//temp_xmachine_Household_02 = NULL;
	Household_02_state = init_Household_state();//&temp_xmachine_Household_02;
	//temp_xmachine_Household_end_Household_EWA_Learning = NULL;
	Household_end_Household_EWA_Learning_state = init_Household_state();//&temp_xmachine_Household_end_Household_EWA_Learning;
	//temp_xmachine_Household_01 = NULL;
	Household_01_state = init_Household_state();//&temp_xmachine_Household_01;
	//temp_xmachine_Household_end_GA = NULL;
	Household_end_GA_state = init_Household_state();//&temp_xmachine_Household_end_GA;
	//temp_xmachine_Household_start_Household_EWA_Learning = NULL;
	Household_start_Household_EWA_Learning_state = init_Household_state();//&temp_xmachine_Household_start_Household_EWA_Learning;
	//temp_xmachine_FinancialAgent_end_FinancialAgent = NULL;
	FinancialAgent_end_FinancialAgent_state = init_FinancialAgent_state();//&temp_xmachine_FinancialAgent_end_FinancialAgent;
	//temp_xmachine_FinancialAgent_04 = NULL;
	FinancialAgent_04_state = init_FinancialAgent_state();//&temp_xmachine_FinancialAgent_04;
	//temp_xmachine_FinancialAgent_03 = NULL;
	FinancialAgent_03_state = init_FinancialAgent_state();//&temp_xmachine_FinancialAgent_03;
	//temp_xmachine_FinancialAgent_02 = NULL;
	FinancialAgent_02_state = init_FinancialAgent_state();//&temp_xmachine_FinancialAgent_02;
	//temp_xmachine_FinancialAgent_01 = NULL;
	FinancialAgent_01_state = init_FinancialAgent_state();//&temp_xmachine_FinancialAgent_01;
	//temp_xmachine_FinancialAgent_end_GA = NULL;
	FinancialAgent_end_GA_state = init_FinancialAgent_state();//&temp_xmachine_FinancialAgent_end_GA;
	//temp_xmachine_FinancialAgent_start_FinancialAgent = NULL;
	FinancialAgent_start_FinancialAgent_state = init_FinancialAgent_state();//&temp_xmachine_FinancialAgent_start_FinancialAgent;
	

    rc = MB_Create(&b_rule_performance, sizeof(m_rule_performance));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'rule_performance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: Invalid message size\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Create(&b_new_performances, sizeof(m_new_performances));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'new_performances' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: Invalid message size\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Create(&b_rule_details, sizeof(m_rule_details));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'rule_details' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: Invalid message size\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif
	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/** \fn void initialise_unit_testing()
 * \brief Initialises framework for unit testing.
 */
void initialise_unit_testing()
{
	initialise_pointers();
	//add_node(0, -SPINF, SPINF, -SPINF, SPINF, -SPINF, SPINF);
	//current_node = *p_node_info;
	//p_xmachine = &current_node->agents;
	//current_xmachine = *p_xmachine;
	// todo fix pointer to current agent types
	//p_rule_performance_message = &current_node->rule_performance_messages;
	//p_new_performances_message = &current_node->new_performances_messages;
	//p_rule_details_message = &current_node->rule_details_messages;
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


void init_GAParameterStruct(GAParameterStruct * temp)
{
	(*temp).prob_cross = 0.0;
	(*temp).prob_mut = 0.0;
	(*temp).string_size = 0;
	(*temp).pop_size = 0;
	(*temp).reproduction_proportion = 0.0;
	(*temp).single_point_cross_over = 0;
	(*temp).election = 0;
	init_double_static_array((*temp).stepsize, 10);
	init_double_static_array((*temp).min_values, 10);
	init_double_static_array((*temp).max_values, 10);

}

void init_GAParameterStruct_static_array(GAParameterStruct * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_GAParameterStruct(&array[i]);
}

void free_GAParameterStruct(GAParameterStruct * temp)
{

}

void free_GAParameterStruct_static_array(GAParameterStruct * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_GAParameterStruct(&array[i]);
}

void copy_GAParameterStruct(GAParameterStruct * from, GAParameterStruct * to)
{
	(*to).prob_cross = (*from).prob_cross;
	(*to).prob_mut = (*from).prob_mut;
	(*to).string_size = (*from).string_size;
	(*to).pop_size = (*from).pop_size;
	(*to).reproduction_proportion = (*from).reproduction_proportion;
	(*to).single_point_cross_over = (*from).single_point_cross_over;
	(*to).election = (*from).election;
	memcpy((*to).stepsize, (*from).stepsize, 10*sizeof(double));
	memcpy((*to).min_values, (*from).min_values, 10*sizeof(double));
	memcpy((*to).max_values, (*from).max_values, 10*sizeof(double));
}

void copy_GAParameterStruct_static_array(GAParameterStruct * from, GAParameterStruct * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_GAParameterStruct(&from[i], &to[i]);
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



xmachine_memory_Household_state * init_Household_state()
{
	xmachine_memory_Household_state * current = (xmachine_memory_Household_state *)malloc(sizeof(xmachine_memory_Household_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Household * init_Household_agent()
{
	xmachine_memory_Household * current = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->day_of_month_to_act = 0;
	init_EWAParameterStruct(&current->EWA_parameters);
	init_SimplePrivateClassifierSystem(&current->private_classifiersystem);
	
	return current;
}

void free_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_EWAParameterStruct(&tmp->agent->EWA_parameters);
	free_SimplePrivateClassifierSystem(&tmp->agent->private_classifiersystem);
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Household_agent()
{
	current_xmachine_Household = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
	CHECK_POINTER(current);
	
		current_xmachine_Household->id = 0;
		current_xmachine_Household->day_of_month_to_act = 0;
		init_EWAParameterStruct(&current_xmachine_Household->EWA_parameters);
		init_SimplePrivateClassifierSystem(&current_xmachine_Household->private_classifiersystem);
		
}

void unittest_free_Household_agent()
{
	free_EWAParameterStruct(&current_xmachine_Household->EWA_parameters);
	free_SimplePrivateClassifierSystem(&current_xmachine_Household->private_classifiersystem);
	
	free(current_xmachine_Household);
}

void free_Household_agents()
{
/*	while(*Household_03_state)
	{
		free_Household_agent(*Household_03_state, Household_03_state);
	}
	while(*Household_02_state)
	{
		free_Household_agent(*Household_02_state, Household_02_state);
	}
	while(*Household_end_Household_EWA_Learning_state)
	{
		free_Household_agent(*Household_end_Household_EWA_Learning_state, Household_end_Household_EWA_Learning_state);
	}
	while(*Household_01_state)
	{
		free_Household_agent(*Household_01_state, Household_01_state);
	}
	while(*Household_end_GA_state)
	{
		free_Household_agent(*Household_end_GA_state, Household_end_GA_state);
	}
	while(*Household_start_Household_EWA_Learning_state)
	{
		free_Household_agent(*Household_start_Household_EWA_Learning_state, Household_start_Household_EWA_Learning_state);
	}
*/}

void free_Household_states()
{
	free(Household_03_state);
	free(Household_02_state);
	free(Household_end_Household_EWA_Learning_state);
	free(Household_01_state);
	free(Household_end_GA_state);
	free(Household_start_Household_EWA_Learning_state);
}

void transition_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * from_state, xmachine_memory_Household_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Household_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Household_agent_internal(xmachine_memory_Household * agent, xmachine_memory_Household_state * state)
{
	xmachine_memory_Household_holder * current = (xmachine_memory_Household_holder *)malloc(sizeof(xmachine_memory_Household_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;
}

/** \fn void add_Household_agent(int id, int day_of_month_to_act, EWAParameterStruct * EWA_parameters, SimplePrivateClassifierSystem * private_classifiersystem)
 * \brief Add Household X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param EWA_parameters Variable for the X-machine memory.
 * \param private_classifiersystem Variable for the X-machine memory.
 */
void add_Household_agent(int id, int day_of_month_to_act, EWAParameterStruct EWA_parameters, SimplePrivateClassifierSystem private_classifiersystem)
{
	xmachine_memory_Household * current;
	
	current = init_Household_agent();
	add_Household_agent_internal(current, current_xmachine_Household_next_state);
	
	current->id = id;
	current->day_of_month_to_act = day_of_month_to_act;
	copy_EWAParameterStruct(&EWA_parameters, &current->EWA_parameters);
	copy_SimplePrivateClassifierSystem(&private_classifiersystem, &current->private_classifiersystem);
}

xmachine_memory_FinancialAgent_state * init_FinancialAgent_state()
{
	xmachine_memory_FinancialAgent_state * current = (xmachine_memory_FinancialAgent_state *)malloc(sizeof(xmachine_memory_FinancialAgent_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_FinancialAgent * init_FinancialAgent_agent()
{
	xmachine_memory_FinancialAgent * current = (xmachine_memory_FinancialAgent *)malloc(sizeof(xmachine_memory_FinancialAgent));
	CHECK_POINTER(current);
	
	current->id = 0;
	init_EWAParameterStruct(&current->EWA_parameters);
	init_SimplePublicClassifierSystem(&current->public_classifiersystem);
	init_GAParameterStruct(&current->GA_parameters);
	
	return current;
}

void free_FinancialAgent_agent(xmachine_memory_FinancialAgent_holder * tmp, xmachine_memory_FinancialAgent_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_EWAParameterStruct(&tmp->agent->EWA_parameters);
	free_SimplePublicClassifierSystem(&tmp->agent->public_classifiersystem);
	free_GAParameterStruct(&tmp->agent->GA_parameters);
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_FinancialAgent_agent()
{
	current_xmachine_FinancialAgent = (xmachine_memory_FinancialAgent *)malloc(sizeof(xmachine_memory_FinancialAgent));
	CHECK_POINTER(current);
	
		current_xmachine_FinancialAgent->id = 0;
		init_EWAParameterStruct(&current_xmachine_FinancialAgent->EWA_parameters);
		init_SimplePublicClassifierSystem(&current_xmachine_FinancialAgent->public_classifiersystem);
		init_GAParameterStruct(&current_xmachine_FinancialAgent->GA_parameters);
		
}

void unittest_free_FinancialAgent_agent()
{
	free_EWAParameterStruct(&current_xmachine_FinancialAgent->EWA_parameters);
	free_SimplePublicClassifierSystem(&current_xmachine_FinancialAgent->public_classifiersystem);
	free_GAParameterStruct(&current_xmachine_FinancialAgent->GA_parameters);
	
	free(current_xmachine_FinancialAgent);
}

void free_FinancialAgent_agents()
{
/*	while(*FinancialAgent_end_FinancialAgent_state)
	{
		free_FinancialAgent_agent(*FinancialAgent_end_FinancialAgent_state, FinancialAgent_end_FinancialAgent_state);
	}
	while(*FinancialAgent_04_state)
	{
		free_FinancialAgent_agent(*FinancialAgent_04_state, FinancialAgent_04_state);
	}
	while(*FinancialAgent_03_state)
	{
		free_FinancialAgent_agent(*FinancialAgent_03_state, FinancialAgent_03_state);
	}
	while(*FinancialAgent_02_state)
	{
		free_FinancialAgent_agent(*FinancialAgent_02_state, FinancialAgent_02_state);
	}
	while(*FinancialAgent_01_state)
	{
		free_FinancialAgent_agent(*FinancialAgent_01_state, FinancialAgent_01_state);
	}
	while(*FinancialAgent_end_GA_state)
	{
		free_FinancialAgent_agent(*FinancialAgent_end_GA_state, FinancialAgent_end_GA_state);
	}
	while(*FinancialAgent_start_FinancialAgent_state)
	{
		free_FinancialAgent_agent(*FinancialAgent_start_FinancialAgent_state, FinancialAgent_start_FinancialAgent_state);
	}
*/}

void free_FinancialAgent_states()
{
	free(FinancialAgent_end_FinancialAgent_state);
	free(FinancialAgent_04_state);
	free(FinancialAgent_03_state);
	free(FinancialAgent_02_state);
	free(FinancialAgent_01_state);
	free(FinancialAgent_end_GA_state);
	free(FinancialAgent_start_FinancialAgent_state);
}

void transition_FinancialAgent_agent(xmachine_memory_FinancialAgent_holder * tmp, xmachine_memory_FinancialAgent_state * from_state, xmachine_memory_FinancialAgent_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_FinancialAgent_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_FinancialAgent_agent_internal(xmachine_memory_FinancialAgent * agent, xmachine_memory_FinancialAgent_state * state)
{
	xmachine_memory_FinancialAgent_holder * current = (xmachine_memory_FinancialAgent_holder *)malloc(sizeof(xmachine_memory_FinancialAgent_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;
}

/** \fn void add_FinancialAgent_agent(int id, EWAParameterStruct * EWA_parameters, SimplePublicClassifierSystem * public_classifiersystem, GAParameterStruct * GA_parameters)
 * \brief Add FinancialAgent X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param EWA_parameters Variable for the X-machine memory.
 * \param public_classifiersystem Variable for the X-machine memory.
 * \param GA_parameters Variable for the X-machine memory.
 */
void add_FinancialAgent_agent(int id, EWAParameterStruct EWA_parameters, SimplePublicClassifierSystem public_classifiersystem, GAParameterStruct GA_parameters)
{
	xmachine_memory_FinancialAgent * current;
	
	current = init_FinancialAgent_agent();
	add_FinancialAgent_agent_internal(current, current_xmachine_FinancialAgent_next_state);
	
	current->id = id;
	copy_EWAParameterStruct(&EWA_parameters, &current->EWA_parameters);
	copy_SimplePublicClassifierSystem(&public_classifiersystem, &current->public_classifiersystem);
	copy_GAParameterStruct(&GA_parameters, &current->GA_parameters);
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	
}


/** \fn void set_id(int id) 
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(int id)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).id = id;
	if(current_xmachine->xmachine_FinancialAgent) (*current_xmachine->xmachine_FinancialAgent).id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).id;
	if(current_xmachine->xmachine_FinancialAgent) return (*current_xmachine->xmachine_FinancialAgent).id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day_of_month_to_act(int day_of_month_to_act) 
 * \brief Set day_of_month_to_act memory variable for current X-machine.
 * \param day_of_month_to_act New value for variable.
 */
void set_day_of_month_to_act(int day_of_month_to_act)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).day_of_month_to_act = day_of_month_to_act;
}

/** \fn int get_day_of_month_to_act()
 * \brief Get day_of_month_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_to_act()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).day_of_month_to_act;

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
	if(current_xmachine->xmachine_FinancialAgent) return &(*current_xmachine->xmachine_FinancialAgent).EWA_parameters;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn SimplePrivateClassifierSystem get_private_classifiersystem()
 * \brief Get private_classifiersystem memory variable from current X-machine.
 * \return Value for variable.
 */
SimplePrivateClassifierSystem * get_private_classifiersystem()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).private_classifiersystem;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn SimplePublicClassifierSystem get_public_classifiersystem()
 * \brief Get public_classifiersystem memory variable from current X-machine.
 * \return Value for variable.
 */
SimplePublicClassifierSystem * get_public_classifiersystem()
{
	if(current_xmachine->xmachine_FinancialAgent) return &(*current_xmachine->xmachine_FinancialAgent).public_classifiersystem;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn GAParameterStruct get_GA_parameters()
 * \brief Get GA_parameters memory variable from current X-machine.
 * \return Value for variable.
 */
GAParameterStruct * get_GA_parameters()
{
	if(current_xmachine->xmachine_FinancialAgent) return &(*current_xmachine->xmachine_FinancialAgent).GA_parameters;

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
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;*/
    /*if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->;*/

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->id;*/
    /*if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->id;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;*/
    /*if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;*/ 
    /*if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->;*/ 

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

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
    int rc;
	FILE *file;
	char data[100];
	
	free(current_xmachine);
	/* Free x-machine memory */
	freexmachines(); //TODO
	current_node->agent_total = 0;
	/* Free space partitions linked list */
	free_node_info();
	/* Free agent states */
	free_Household_states();
	free_FinancialAgent_states();
	
	
	/* Free message boards */

	rc = MB_Delete(&b_rule_performance);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'rule_performance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_performance' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'rule_performance' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	rc = MB_Delete(&b_new_performances);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'new_performances' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_performances' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'new_performances' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	rc = MB_Delete(&b_rule_details);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'rule_details' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_details' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'rule_details' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	

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
/*	node_information * node_info;
	xmachine * before_xmachine, * temp_xmachine;
	xmachine ** p_temp_xmachine;
	double x_xmachine, y_xmachine, z_xmachine;
	current_xmachine = *p_xmachine;
	before_xmachine = NULL;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_Household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Household->;
			y_xmachine = current_xmachine->xmachine_Household->;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_FinancialAgent != NULL)
		{
			x_xmachine = current_xmachine->xmachine_FinancialAgent->;
			y_xmachine = current_xmachine->xmachine_FinancialAgent->;
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
                    // Remove agent
                    if(before_xmachine) before_xmachine->next = current_xmachine->next;
                    else *p_xmachine = current_xmachine->next;
                    current_node->agent_total--;
                    // Add agent
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
		}*/
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
/* Functions for the GAParameterStruct datatype */
/** \fn GAParameterStruct_array * init_GAParameterStruct_array()
 * \brief Allocate memory for a dynamic GAParameterStruct array.
 * \return GAParameterStruct_array Pointer to the new dynamic GAParameterStruct array.
 */
void init_GAParameterStruct_array(GAParameterStruct_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (GAParameterStruct *)malloc(ARRAY_BLOCK_SIZE * sizeof(GAParameterStruct));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_GAParameterStruct_array(GAParameterStruct_array* array)
* \brief Reset the GAParameterStruct array to hold nothing.
* \param array Pointer to the dynamic GAParameterStruct array.
*/
void reset_GAParameterStruct_array(GAParameterStruct_array * array)
{
	(*array).size = 0;
}

/** \fn void free_GAParameterStruct_array(GAParameterStruct_array * array)
* \brief Free the memory of a dynamic GAParameterStruct array.
* \param array Pointer to the dynamic GAParameterStruct array.
*/
void free_GAParameterStruct_array(GAParameterStruct_array * array)
{
	free((*array).array);
}

void copy_GAParameterStruct_array(GAParameterStruct_array * from, GAParameterStruct_array * to)
{
	int i;
	
	//to = init_GAParameterStruct_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_GAParameterStruct(to, (*from).array[i].prob_cross, (*from).array[i].prob_mut, (*from).array[i].string_size, (*from).array[i].pop_size, (*from).array[i].reproduction_proportion, (*from).array[i].single_point_cross_over, (*from).array[i].election, (*from).array[i].stepsize, (*from).array[i].min_values, (*from).array[i].max_values);
	}
}

/** \fn void add_GAParameterStruct(GAParameterStruct_array * array, double prob_cross, double prob_mut, int string_size, int pop_size, double reproduction_proportion, int single_point_cross_over, int election, double stepsize, double min_values, double max_values)
* \brief Add an GAParameterStruct to the dynamic GAParameterStruct array.
* \param array Pointer to the dynamic GAParameterStruct array.
* \param new_int The GAParameterStruct to add
*/
void add_GAParameterStruct(GAParameterStruct_array * array, double prob_cross, double prob_mut, int string_size, int pop_size, double reproduction_proportion, int single_point_cross_over, int election, double * stepsize, double * min_values, double * max_values)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (GAParameterStruct *)realloc((*array).array, ((*array).total_size * sizeof(GAParameterStruct)));
	}
	init_GAParameterStruct(&(*array).array[(*array).size]);
	(*array).array[(*array).size].prob_cross = prob_cross;
	(*array).array[(*array).size].prob_mut = prob_mut;
	(*array).array[(*array).size].string_size = string_size;
	(*array).array[(*array).size].pop_size = pop_size;
	(*array).array[(*array).size].reproduction_proportion = reproduction_proportion;
	(*array).array[(*array).size].single_point_cross_over = single_point_cross_over;
	(*array).array[(*array).size].election = election;
	if(stepsize != NULL) memcpy((*array).array[(*array).size].stepsize, stepsize, 10*sizeof(double));
	if(min_values != NULL) memcpy((*array).array[(*array).size].min_values, min_values, 10*sizeof(double));
	if(max_values != NULL) memcpy((*array).array[(*array).size].max_values, max_values, 10*sizeof(double));

	(*array).size++;
}

/** \fn void remove_GAParameterStruct(GAParameterStruct_array * array, int index)
 * \brief Remove an GAParameterStruct from a dynamic GAParameterStruct array.
 * \param array Pointer to the dynamic GAParameterStruct array.
 * \param index The index of the GAParameterStruct to remove.
 */
void remove_GAParameterStruct(GAParameterStruct_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_GAParameterStruct(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_GAParameterStruct(&(*array).array[i+1], &(*array).array[i]);
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

