/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"

void free_messages()
{
	int rc;
	
	
	    rc = MB_Clear(b_central_bank_account_update);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'central_bank_account_update' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'central_bank_account_update' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'central_bank_account_update' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_tax_payment);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'tax_payment' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'tax_payment' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'tax_payment' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_data_for_government);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'data_for_government' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'data_for_government' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'data_for_government' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_policy_announcement);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'policy_announcement' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'policy_announcement' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_unemployment_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'unemployment_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'unemployment_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'unemployment_notification' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_hh_transfer_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'hh_transfer_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_hh_subsidy_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'hh_subsidy_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_firm_transfer_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'firm_transfer_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_firm_subsidy_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'firm_subsidy_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
}



/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
	int rc;
    //temp_xmachine = NULL;
	//p_xmachine = &temp_xmachine;
	//temp_xmachine_Household_end_Household = NULL;
	Household_end_Household_state = init_Household_state();//&temp_xmachine_Household_end_Household;
	//temp_xmachine_Household_04 = NULL;
	Household_04_state = init_Household_state();//&temp_xmachine_Household_04;
	//temp_xmachine_Household_03 = NULL;
	Household_03_state = init_Household_state();//&temp_xmachine_Household_03;
	//temp_xmachine_Household_02 = NULL;
	Household_02_state = init_Household_state();//&temp_xmachine_Household_02;
	//temp_xmachine_Household_01 = NULL;
	Household_01_state = init_Household_state();//&temp_xmachine_Household_01;
	//temp_xmachine_Household_start_Household = NULL;
	Household_start_Household_state = init_Household_state();//&temp_xmachine_Household_start_Household;
	//temp_xmachine_Firm_end_Firm = NULL;
	Firm_end_Firm_state = init_Firm_state();//&temp_xmachine_Firm_end_Firm;
	//temp_xmachine_Firm_03 = NULL;
	Firm_03_state = init_Firm_state();//&temp_xmachine_Firm_03;
	//temp_xmachine_Firm_02 = NULL;
	Firm_02_state = init_Firm_state();//&temp_xmachine_Firm_02;
	//temp_xmachine_Firm_01 = NULL;
	Firm_01_state = init_Firm_state();//&temp_xmachine_Firm_01;
	//temp_xmachine_Firm_start_Firm = NULL;
	Firm_start_Firm_state = init_Firm_state();//&temp_xmachine_Firm_start_Firm;
	//temp_xmachine_Government_end_Government = NULL;
	Government_end_Government_state = init_Government_state();//&temp_xmachine_Government_end_Government;
	//temp_xmachine_Government_09 = NULL;
	Government_09_state = init_Government_state();//&temp_xmachine_Government_09;
	//temp_xmachine_Government_08 = NULL;
	Government_08_state = init_Government_state();//&temp_xmachine_Government_08;
	//temp_xmachine_Government_07 = NULL;
	Government_07_state = init_Government_state();//&temp_xmachine_Government_07;
	//temp_xmachine_Government_06 = NULL;
	Government_06_state = init_Government_state();//&temp_xmachine_Government_06;
	//temp_xmachine_Government_05 = NULL;
	Government_05_state = init_Government_state();//&temp_xmachine_Government_05;
	//temp_xmachine_Government_Gov_Start_Yearly_Loop = NULL;
	Government_Gov_Start_Yearly_Loop_state = init_Government_state();//&temp_xmachine_Government_Gov_Start_Yearly_Loop;
	//temp_xmachine_Government_Gov_Start_Monthly_Loop = NULL;
	Government_Gov_Start_Monthly_Loop_state = init_Government_state();//&temp_xmachine_Government_Gov_Start_Monthly_Loop;
	//temp_xmachine_Government_04 = NULL;
	Government_04_state = init_Government_state();//&temp_xmachine_Government_04;
	//temp_xmachine_Government_03 = NULL;
	Government_03_state = init_Government_state();//&temp_xmachine_Government_03;
	//temp_xmachine_Government_02 = NULL;
	Government_02_state = init_Government_state();//&temp_xmachine_Government_02;
	//temp_xmachine_Government_01 = NULL;
	Government_01_state = init_Government_state();//&temp_xmachine_Government_01;
	//temp_xmachine_Government_start_Government = NULL;
	Government_start_Government_state = init_Government_state();//&temp_xmachine_Government_start_Government;
	//temp_xmachine_Central_Bank_end_Central_Bank = NULL;
	Central_Bank_end_Central_Bank_state = init_Central_Bank_state();//&temp_xmachine_Central_Bank_end_Central_Bank;
	//temp_xmachine_Central_Bank_start_Central_Bank = NULL;
	Central_Bank_start_Central_Bank_state = init_Central_Bank_state();//&temp_xmachine_Central_Bank_start_Central_Bank;


	    rc = MB_Create(&b_central_bank_account_update, sizeof(m_central_bank_account_update));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'central_bank_account_update' board\n");
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
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_tax_payment, sizeof(m_tax_payment));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'tax_payment' board\n");
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
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_data_for_government, sizeof(m_data_for_government));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'data_for_government' board\n");
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
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_policy_announcement, sizeof(m_policy_announcement));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'policy_announcement' board\n");
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
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_unemployment_notification, sizeof(m_unemployment_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'unemployment_notification' board\n");
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
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_hh_transfer_notification, sizeof(m_hh_transfer_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'hh_transfer_notification' board\n");
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
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_hh_subsidy_notification, sizeof(m_hh_subsidy_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'hh_subsidy_notification' board\n");
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
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_firm_transfer_notification, sizeof(m_firm_transfer_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'firm_transfer_notification' board\n");
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
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_firm_subsidy_notification, sizeof(m_firm_subsidy_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'firm_subsidy_notification' board\n");
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
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
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
	int rc;
	
	rc = MB_Env_Init();
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Failed to initialise Message Board environment\n");
	   switch(rc) {
	       case MB_ERR_MPI:
	           fprintf(stderr, "\t reason: MPI library not initialised\n");
	           break;
	       case MB_ERR_MEMALLOC:
	           fprintf(stderr, "\t reason: out of memory\n");
	           break;
	       default:
               fprintf(stderr, "\t MB_Env_Init returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
	   
	}
	#endif
	
	initialise_pointers();
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
	current->day_of_month_receive_income = 0;
	current->day_of_month_receive_benefit = 0;
	
	return current;
}

void free_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Household_agent()
{
	current_xmachine_Household = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
	CHECK_POINTER(current);
	
		current_xmachine_Household->id = 0;
		current_xmachine_Household->day_of_month_receive_income = 0;
		current_xmachine_Household->day_of_month_receive_benefit = 0;
		
}

void unittest_free_Household_agent()
{
	
	free(current_xmachine_Household);
}

void free_Household_agents()
{
	current_xmachine_Household_holder = Household_end_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_end_Household_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_04_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_04_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_03_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_03_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_02_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_02_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_01_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_01_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_start_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_start_Household_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
}

void free_Household_states()
{
	free(Household_end_Household_state);
	free(Household_04_state);
	free(Household_03_state);
	free(Household_02_state);
	free(Household_01_state);
	free(Household_start_Household_state);
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

/** \fn void add_Household_agent(int id, int day_of_month_receive_income, int day_of_month_receive_benefit)
 * \brief Add Household X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param day_of_month_receive_income Variable for the X-machine memory.
 * \param day_of_month_receive_benefit Variable for the X-machine memory.
 */
void add_Household_agent(int id, int day_of_month_receive_income, int day_of_month_receive_benefit)
{
	xmachine_memory_Household * current;
	
	current = init_Household_agent();
	add_Household_agent_internal(current, current_xmachine_Household_next_state);
	
	current->id = id;
	current->day_of_month_receive_income = day_of_month_receive_income;
	current->day_of_month_receive_benefit = day_of_month_receive_benefit;
}

xmachine_memory_Firm_state * init_Firm_state()
{
	xmachine_memory_Firm_state * current = (xmachine_memory_Firm_state *)malloc(sizeof(xmachine_memory_Firm_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Firm * init_Firm_agent()
{
	xmachine_memory_Firm * current = (xmachine_memory_Firm *)malloc(sizeof(xmachine_memory_Firm));
	CHECK_POINTER(current);
	
	current->id = 0;
	
	return current;
}

void free_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Firm_agent()
{
	current_xmachine_Firm = (xmachine_memory_Firm *)malloc(sizeof(xmachine_memory_Firm));
	CHECK_POINTER(current);
	
		current_xmachine_Firm->id = 0;
		
}

void unittest_free_Firm_agent()
{
	
	free(current_xmachine_Firm);
}

void free_Firm_agents()
{
	current_xmachine_Firm_holder = Firm_end_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_end_Firm_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_03_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_03_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_02_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_01_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_01_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_start_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
}

void free_Firm_states()
{
	free(Firm_end_Firm_state);
	free(Firm_03_state);
	free(Firm_02_state);
	free(Firm_01_state);
	free(Firm_start_Firm_state);
}

void transition_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * from_state, xmachine_memory_Firm_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Firm_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Firm_agent_internal(xmachine_memory_Firm * agent, xmachine_memory_Firm_state * state)
{
	xmachine_memory_Firm_holder * current = (xmachine_memory_Firm_holder *)malloc(sizeof(xmachine_memory_Firm_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Firm_agent(int id)
 * \brief Add Firm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 */
void add_Firm_agent(int id)
{
	xmachine_memory_Firm * current;
	
	current = init_Firm_agent();
	add_Firm_agent_internal(current, current_xmachine_Firm_next_state);
	
	current->id = id;
}

xmachine_memory_Government_state * init_Government_state()
{
	xmachine_memory_Government_state * current = (xmachine_memory_Government_state *)malloc(sizeof(xmachine_memory_Government_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Government * init_Government_agent()
{
	xmachine_memory_Government * current = (xmachine_memory_Government *)malloc(sizeof(xmachine_memory_Government));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->payment_account = 0.0;
	init_int_static_array(current->list_of_regions, 1);
	current->unemployment_benefit_pct = 0.0;
	current->tax_rate_corporate = 0.0;
	current->tax_rate_hh_labour = 0.0;
	current->tax_rate_hh_capital = 0.0;
	current->tax_rate_vat = 0.0;
	current->monthly_tax_revenues = 0.0;
	current->yearly_tax_revenues = 0.0;
	current->monthly_unemployment_benefit_payment = 0.0;
	current->yearly_unemployment_benefit_payment = 0.0;
	current->hh_transfer_payment = 0.0;
	current->firm_transfer_payment = 0.0;
	current->monthly_transfer_payment = 0.0;
	current->yearly_transfer_payment = 0.0;
	current->hh_subsidy_payment = 0.0;
	current->firm_subsidy_payment = 0.0;
	current->monthly_subsidy_payment = 0.0;
	current->yearly_subsidy_payment = 0.0;
	current->monthly_bond_coupon_payment = 0.0;
	current->yearly_bond_coupon_payment = 0.0;
	current->gov_interest_rate = 0.0;
	current->yearly_interest_payment = 0.0;
	current->yearly_gov_investment = 0.0;
	current->yearly_gov_consumption = 0.0;
	current->total_income = 0.0;
	current->total_expenditure = 0.0;
	current->total_debt = 0.0;
	current->budget_deficit = 0.0;
	current->total_money_financing = 0.0;
	current->total_bond_financing = 0.0;
	current->country_wide_mean_wage = 0.0;
	current->num_unemployed = 0;
	current->gdp = 0.0;
	current->gdp_growth = 0.0;
	current->gdp_forecast = 0.0;
	current->total_income_forecast = 0.0;
	current->total_expenditure_forecast = 0.0;
	current->budget_forecast = 0.0;
	
	return current;
}

void free_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Government_agent()
{
	current_xmachine_Government = (xmachine_memory_Government *)malloc(sizeof(xmachine_memory_Government));
	CHECK_POINTER(current);
	
		current_xmachine_Government->id = 0;
		current_xmachine_Government->payment_account = 0.0;
		init_int_static_array(current_xmachine_Government->list_of_regions, 1);
		current_xmachine_Government->unemployment_benefit_pct = 0.0;
		current_xmachine_Government->tax_rate_corporate = 0.0;
		current_xmachine_Government->tax_rate_hh_labour = 0.0;
		current_xmachine_Government->tax_rate_hh_capital = 0.0;
		current_xmachine_Government->tax_rate_vat = 0.0;
		current_xmachine_Government->monthly_tax_revenues = 0.0;
		current_xmachine_Government->yearly_tax_revenues = 0.0;
		current_xmachine_Government->monthly_unemployment_benefit_payment = 0.0;
		current_xmachine_Government->yearly_unemployment_benefit_payment = 0.0;
		current_xmachine_Government->hh_transfer_payment = 0.0;
		current_xmachine_Government->firm_transfer_payment = 0.0;
		current_xmachine_Government->monthly_transfer_payment = 0.0;
		current_xmachine_Government->yearly_transfer_payment = 0.0;
		current_xmachine_Government->hh_subsidy_payment = 0.0;
		current_xmachine_Government->firm_subsidy_payment = 0.0;
		current_xmachine_Government->monthly_subsidy_payment = 0.0;
		current_xmachine_Government->yearly_subsidy_payment = 0.0;
		current_xmachine_Government->monthly_bond_coupon_payment = 0.0;
		current_xmachine_Government->yearly_bond_coupon_payment = 0.0;
		current_xmachine_Government->gov_interest_rate = 0.0;
		current_xmachine_Government->yearly_interest_payment = 0.0;
		current_xmachine_Government->yearly_gov_investment = 0.0;
		current_xmachine_Government->yearly_gov_consumption = 0.0;
		current_xmachine_Government->total_income = 0.0;
		current_xmachine_Government->total_expenditure = 0.0;
		current_xmachine_Government->total_debt = 0.0;
		current_xmachine_Government->budget_deficit = 0.0;
		current_xmachine_Government->total_money_financing = 0.0;
		current_xmachine_Government->total_bond_financing = 0.0;
		current_xmachine_Government->country_wide_mean_wage = 0.0;
		current_xmachine_Government->num_unemployed = 0;
		current_xmachine_Government->gdp = 0.0;
		current_xmachine_Government->gdp_growth = 0.0;
		current_xmachine_Government->gdp_forecast = 0.0;
		current_xmachine_Government->total_income_forecast = 0.0;
		current_xmachine_Government->total_expenditure_forecast = 0.0;
		current_xmachine_Government->budget_forecast = 0.0;
		
}

void unittest_free_Government_agent()
{
	
	free(current_xmachine_Government);
}

void free_Government_agents()
{
	current_xmachine_Government_holder = Government_end_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_end_Government_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_09_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_09_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_08_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_08_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_07_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_07_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_06_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_06_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_05_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_05_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_Gov_Start_Yearly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Yearly_Loop_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_Gov_Start_Monthly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Monthly_Loop_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_04_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_04_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_03_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_03_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_02_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_02_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_01_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_01_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_start_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_start_Government_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
}

void free_Government_states()
{
	free(Government_end_Government_state);
	free(Government_09_state);
	free(Government_08_state);
	free(Government_07_state);
	free(Government_06_state);
	free(Government_05_state);
	free(Government_Gov_Start_Yearly_Loop_state);
	free(Government_Gov_Start_Monthly_Loop_state);
	free(Government_04_state);
	free(Government_03_state);
	free(Government_02_state);
	free(Government_01_state);
	free(Government_start_Government_state);
}

void transition_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * from_state, xmachine_memory_Government_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Government_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Government_agent_internal(xmachine_memory_Government * agent, xmachine_memory_Government_state * state)
{
	xmachine_memory_Government_holder * current = (xmachine_memory_Government_holder *)malloc(sizeof(xmachine_memory_Government_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Government_agent(int id, double payment_account, int list_of_regions[], double unemployment_benefit_pct, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double monthly_tax_revenues, double yearly_tax_revenues, double monthly_unemployment_benefit_payment, double yearly_unemployment_benefit_payment, double hh_transfer_payment, double firm_transfer_payment, double monthly_transfer_payment, double yearly_transfer_payment, double hh_subsidy_payment, double firm_subsidy_payment, double monthly_subsidy_payment, double yearly_subsidy_payment, double monthly_bond_coupon_payment, double yearly_bond_coupon_payment, double gov_interest_rate, double yearly_interest_payment, double yearly_gov_investment, double yearly_gov_consumption, double total_income, double total_expenditure, double total_debt, double budget_deficit, double total_money_financing, double total_bond_financing, double country_wide_mean_wage, int num_unemployed, double gdp, double gdp_growth, double gdp_forecast, double total_income_forecast, double total_expenditure_forecast, double budget_forecast)
 * \brief Add Government X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param payment_account Variable for the X-machine memory.
 * \param list_of_regions Variable for the X-machine memory.
 * \param unemployment_benefit_pct Variable for the X-machine memory.
 * \param tax_rate_corporate Variable for the X-machine memory.
 * \param tax_rate_hh_labour Variable for the X-machine memory.
 * \param tax_rate_hh_capital Variable for the X-machine memory.
 * \param tax_rate_vat Variable for the X-machine memory.
 * \param monthly_tax_revenues Variable for the X-machine memory.
 * \param yearly_tax_revenues Variable for the X-machine memory.
 * \param monthly_unemployment_benefit_payment Variable for the X-machine memory.
 * \param yearly_unemployment_benefit_payment Variable for the X-machine memory.
 * \param hh_transfer_payment Variable for the X-machine memory.
 * \param firm_transfer_payment Variable for the X-machine memory.
 * \param monthly_transfer_payment Variable for the X-machine memory.
 * \param yearly_transfer_payment Variable for the X-machine memory.
 * \param hh_subsidy_payment Variable for the X-machine memory.
 * \param firm_subsidy_payment Variable for the X-machine memory.
 * \param monthly_subsidy_payment Variable for the X-machine memory.
 * \param yearly_subsidy_payment Variable for the X-machine memory.
 * \param monthly_bond_coupon_payment Variable for the X-machine memory.
 * \param yearly_bond_coupon_payment Variable for the X-machine memory.
 * \param gov_interest_rate Variable for the X-machine memory.
 * \param yearly_interest_payment Variable for the X-machine memory.
 * \param yearly_gov_investment Variable for the X-machine memory.
 * \param yearly_gov_consumption Variable for the X-machine memory.
 * \param total_income Variable for the X-machine memory.
 * \param total_expenditure Variable for the X-machine memory.
 * \param total_debt Variable for the X-machine memory.
 * \param budget_deficit Variable for the X-machine memory.
 * \param total_money_financing Variable for the X-machine memory.
 * \param total_bond_financing Variable for the X-machine memory.
 * \param country_wide_mean_wage Variable for the X-machine memory.
 * \param num_unemployed Variable for the X-machine memory.
 * \param gdp Variable for the X-machine memory.
 * \param gdp_growth Variable for the X-machine memory.
 * \param gdp_forecast Variable for the X-machine memory.
 * \param total_income_forecast Variable for the X-machine memory.
 * \param total_expenditure_forecast Variable for the X-machine memory.
 * \param budget_forecast Variable for the X-machine memory.
 */
void add_Government_agent(int id, double payment_account, int list_of_regions[], double unemployment_benefit_pct, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double monthly_tax_revenues, double yearly_tax_revenues, double monthly_unemployment_benefit_payment, double yearly_unemployment_benefit_payment, double hh_transfer_payment, double firm_transfer_payment, double monthly_transfer_payment, double yearly_transfer_payment, double hh_subsidy_payment, double firm_subsidy_payment, double monthly_subsidy_payment, double yearly_subsidy_payment, double monthly_bond_coupon_payment, double yearly_bond_coupon_payment, double gov_interest_rate, double yearly_interest_payment, double yearly_gov_investment, double yearly_gov_consumption, double total_income, double total_expenditure, double total_debt, double budget_deficit, double total_money_financing, double total_bond_financing, double country_wide_mean_wage, int num_unemployed, double gdp, double gdp_growth, double gdp_forecast, double total_income_forecast, double total_expenditure_forecast, double budget_forecast)
{
	xmachine_memory_Government * current;
	
	current = init_Government_agent();
	add_Government_agent_internal(current, current_xmachine_Government_next_state);
	
	current->id = id;
	current->payment_account = payment_account;
	memcpy(current->list_of_regions, list_of_regions, 1*sizeof(int));
	current->unemployment_benefit_pct = unemployment_benefit_pct;
	current->tax_rate_corporate = tax_rate_corporate;
	current->tax_rate_hh_labour = tax_rate_hh_labour;
	current->tax_rate_hh_capital = tax_rate_hh_capital;
	current->tax_rate_vat = tax_rate_vat;
	current->monthly_tax_revenues = monthly_tax_revenues;
	current->yearly_tax_revenues = yearly_tax_revenues;
	current->monthly_unemployment_benefit_payment = monthly_unemployment_benefit_payment;
	current->yearly_unemployment_benefit_payment = yearly_unemployment_benefit_payment;
	current->hh_transfer_payment = hh_transfer_payment;
	current->firm_transfer_payment = firm_transfer_payment;
	current->monthly_transfer_payment = monthly_transfer_payment;
	current->yearly_transfer_payment = yearly_transfer_payment;
	current->hh_subsidy_payment = hh_subsidy_payment;
	current->firm_subsidy_payment = firm_subsidy_payment;
	current->monthly_subsidy_payment = monthly_subsidy_payment;
	current->yearly_subsidy_payment = yearly_subsidy_payment;
	current->monthly_bond_coupon_payment = monthly_bond_coupon_payment;
	current->yearly_bond_coupon_payment = yearly_bond_coupon_payment;
	current->gov_interest_rate = gov_interest_rate;
	current->yearly_interest_payment = yearly_interest_payment;
	current->yearly_gov_investment = yearly_gov_investment;
	current->yearly_gov_consumption = yearly_gov_consumption;
	current->total_income = total_income;
	current->total_expenditure = total_expenditure;
	current->total_debt = total_debt;
	current->budget_deficit = budget_deficit;
	current->total_money_financing = total_money_financing;
	current->total_bond_financing = total_bond_financing;
	current->country_wide_mean_wage = country_wide_mean_wage;
	current->num_unemployed = num_unemployed;
	current->gdp = gdp;
	current->gdp_growth = gdp_growth;
	current->gdp_forecast = gdp_forecast;
	current->total_income_forecast = total_income_forecast;
	current->total_expenditure_forecast = total_expenditure_forecast;
	current->budget_forecast = budget_forecast;
}

xmachine_memory_Central_Bank_state * init_Central_Bank_state()
{
	xmachine_memory_Central_Bank_state * current = (xmachine_memory_Central_Bank_state *)malloc(sizeof(xmachine_memory_Central_Bank_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Central_Bank * init_Central_Bank_agent()
{
	xmachine_memory_Central_Bank * current = (xmachine_memory_Central_Bank *)malloc(sizeof(xmachine_memory_Central_Bank));
	CHECK_POINTER(current);
	
	init_double_static_array(current->bank_accounts, 30);
	init_double_static_array(current->gov_accounts, 30);
	
	return current;
}

void free_Central_Bank_agent(xmachine_memory_Central_Bank_holder * tmp, xmachine_memory_Central_Bank_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Central_Bank_agent()
{
	current_xmachine_Central_Bank = (xmachine_memory_Central_Bank *)malloc(sizeof(xmachine_memory_Central_Bank));
	CHECK_POINTER(current);
	
		init_double_static_array(current_xmachine_Central_Bank->bank_accounts, 30);
		init_double_static_array(current_xmachine_Central_Bank->gov_accounts, 30);
		
}

void unittest_free_Central_Bank_agent()
{
	
	free(current_xmachine_Central_Bank);
}

void free_Central_Bank_agents()
{
	current_xmachine_Central_Bank_holder = Central_Bank_end_Central_Bank_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		free_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_end_Central_Bank_state);
		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
	}
	current_xmachine_Central_Bank_holder = Central_Bank_start_Central_Bank_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		free_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_start_Central_Bank_state);
		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
	}
}

void free_Central_Bank_states()
{
	free(Central_Bank_end_Central_Bank_state);
	free(Central_Bank_start_Central_Bank_state);
}

void transition_Central_Bank_agent(xmachine_memory_Central_Bank_holder * tmp, xmachine_memory_Central_Bank_state * from_state, xmachine_memory_Central_Bank_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Central_Bank_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Central_Bank_agent_internal(xmachine_memory_Central_Bank * agent, xmachine_memory_Central_Bank_state * state)
{
	xmachine_memory_Central_Bank_holder * current = (xmachine_memory_Central_Bank_holder *)malloc(sizeof(xmachine_memory_Central_Bank_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Central_Bank_agent(double bank_accounts[], double gov_accounts[])
 * \brief Add Central_Bank X-machine to the current being used X-machine list.
 * \param bank_accounts Variable for the X-machine memory.
 * \param gov_accounts Variable for the X-machine memory.
 */
void add_Central_Bank_agent(double bank_accounts[], double gov_accounts[])
{
	xmachine_memory_Central_Bank * current;
	
	current = init_Central_Bank_agent();
	add_Central_Bank_agent_internal(current, current_xmachine_Central_Bank_next_state);
	
	memcpy(current->bank_accounts, bank_accounts, 30*sizeof(double));
	memcpy(current->gov_accounts, gov_accounts, 30*sizeof(double));
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	free_Household_agents();
	free_Firm_agents();
	free_Government_agents();
	free_Central_Bank_agents();
	
}


/** \fn void set_id(int id) 
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(int id)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).id = id;
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).id = id;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).id;
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).id;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day_of_month_receive_income(int day_of_month_receive_income) 
 * \brief Set day_of_month_receive_income memory variable for current X-machine.
 * \param day_of_month_receive_income New value for variable.
 */
void set_day_of_month_receive_income(int day_of_month_receive_income)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).day_of_month_receive_income = day_of_month_receive_income;
}

/** \fn int get_day_of_month_receive_income()
 * \brief Get day_of_month_receive_income memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_receive_income()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).day_of_month_receive_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day_of_month_receive_benefit(int day_of_month_receive_benefit) 
 * \brief Set day_of_month_receive_benefit memory variable for current X-machine.
 * \param day_of_month_receive_benefit New value for variable.
 */
void set_day_of_month_receive_benefit(int day_of_month_receive_benefit)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).day_of_month_receive_benefit = day_of_month_receive_benefit;
}

/** \fn int get_day_of_month_receive_benefit()
 * \brief Get day_of_month_receive_benefit memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_receive_benefit()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).day_of_month_receive_benefit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_payment_account(double payment_account) 
 * \brief Set payment_account memory variable for current X-machine.
 * \param payment_account New value for variable.
 */
void set_payment_account(double payment_account)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).payment_account = payment_account;
}

/** \fn double get_payment_account()
 * \brief Get payment_account memory variable from current X-machine.
 * \return Value for variable.
 */
double get_payment_account()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).payment_account;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn int get_list_of_regions()
 * \brief Get list_of_regions memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_list_of_regions()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).list_of_regions;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_unemployment_benefit_pct(double unemployment_benefit_pct) 
 * \brief Set unemployment_benefit_pct memory variable for current X-machine.
 * \param unemployment_benefit_pct New value for variable.
 */
void set_unemployment_benefit_pct(double unemployment_benefit_pct)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).unemployment_benefit_pct = unemployment_benefit_pct;
}

/** \fn double get_unemployment_benefit_pct()
 * \brief Get unemployment_benefit_pct memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_benefit_pct()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).unemployment_benefit_pct;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate_corporate(double tax_rate_corporate) 
 * \brief Set tax_rate_corporate memory variable for current X-machine.
 * \param tax_rate_corporate New value for variable.
 */
void set_tax_rate_corporate(double tax_rate_corporate)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).tax_rate_corporate = tax_rate_corporate;
}

/** \fn double get_tax_rate_corporate()
 * \brief Get tax_rate_corporate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_corporate()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).tax_rate_corporate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate_hh_labour(double tax_rate_hh_labour) 
 * \brief Set tax_rate_hh_labour memory variable for current X-machine.
 * \param tax_rate_hh_labour New value for variable.
 */
void set_tax_rate_hh_labour(double tax_rate_hh_labour)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).tax_rate_hh_labour = tax_rate_hh_labour;
}

/** \fn double get_tax_rate_hh_labour()
 * \brief Get tax_rate_hh_labour memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_hh_labour()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).tax_rate_hh_labour;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate_hh_capital(double tax_rate_hh_capital) 
 * \brief Set tax_rate_hh_capital memory variable for current X-machine.
 * \param tax_rate_hh_capital New value for variable.
 */
void set_tax_rate_hh_capital(double tax_rate_hh_capital)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).tax_rate_hh_capital = tax_rate_hh_capital;
}

/** \fn double get_tax_rate_hh_capital()
 * \brief Get tax_rate_hh_capital memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_hh_capital()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).tax_rate_hh_capital;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate_vat(double tax_rate_vat) 
 * \brief Set tax_rate_vat memory variable for current X-machine.
 * \param tax_rate_vat New value for variable.
 */
void set_tax_rate_vat(double tax_rate_vat)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).tax_rate_vat = tax_rate_vat;
}

/** \fn double get_tax_rate_vat()
 * \brief Get tax_rate_vat memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_vat()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).tax_rate_vat;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_tax_revenues(double monthly_tax_revenues) 
 * \brief Set monthly_tax_revenues memory variable for current X-machine.
 * \param monthly_tax_revenues New value for variable.
 */
void set_monthly_tax_revenues(double monthly_tax_revenues)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_tax_revenues = monthly_tax_revenues;
}

/** \fn double get_monthly_tax_revenues()
 * \brief Get monthly_tax_revenues memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_tax_revenues()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_tax_revenues;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_tax_revenues(double yearly_tax_revenues) 
 * \brief Set yearly_tax_revenues memory variable for current X-machine.
 * \param yearly_tax_revenues New value for variable.
 */
void set_yearly_tax_revenues(double yearly_tax_revenues)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_tax_revenues = yearly_tax_revenues;
}

/** \fn double get_yearly_tax_revenues()
 * \brief Get yearly_tax_revenues memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_tax_revenues()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_tax_revenues;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_unemployment_benefit_payment(double monthly_unemployment_benefit_payment) 
 * \brief Set monthly_unemployment_benefit_payment memory variable for current X-machine.
 * \param monthly_unemployment_benefit_payment New value for variable.
 */
void set_monthly_unemployment_benefit_payment(double monthly_unemployment_benefit_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_unemployment_benefit_payment = monthly_unemployment_benefit_payment;
}

/** \fn double get_monthly_unemployment_benefit_payment()
 * \brief Get monthly_unemployment_benefit_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_unemployment_benefit_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_unemployment_benefit_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_unemployment_benefit_payment(double yearly_unemployment_benefit_payment) 
 * \brief Set yearly_unemployment_benefit_payment memory variable for current X-machine.
 * \param yearly_unemployment_benefit_payment New value for variable.
 */
void set_yearly_unemployment_benefit_payment(double yearly_unemployment_benefit_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_unemployment_benefit_payment = yearly_unemployment_benefit_payment;
}

/** \fn double get_yearly_unemployment_benefit_payment()
 * \brief Get yearly_unemployment_benefit_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_unemployment_benefit_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_unemployment_benefit_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_hh_transfer_payment(double hh_transfer_payment) 
 * \brief Set hh_transfer_payment memory variable for current X-machine.
 * \param hh_transfer_payment New value for variable.
 */
void set_hh_transfer_payment(double hh_transfer_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).hh_transfer_payment = hh_transfer_payment;
}

/** \fn double get_hh_transfer_payment()
 * \brief Get hh_transfer_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_hh_transfer_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).hh_transfer_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_transfer_payment(double firm_transfer_payment) 
 * \brief Set firm_transfer_payment memory variable for current X-machine.
 * \param firm_transfer_payment New value for variable.
 */
void set_firm_transfer_payment(double firm_transfer_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).firm_transfer_payment = firm_transfer_payment;
}

/** \fn double get_firm_transfer_payment()
 * \brief Get firm_transfer_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_transfer_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).firm_transfer_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_transfer_payment(double monthly_transfer_payment) 
 * \brief Set monthly_transfer_payment memory variable for current X-machine.
 * \param monthly_transfer_payment New value for variable.
 */
void set_monthly_transfer_payment(double monthly_transfer_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_transfer_payment = monthly_transfer_payment;
}

/** \fn double get_monthly_transfer_payment()
 * \brief Get monthly_transfer_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_transfer_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_transfer_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_transfer_payment(double yearly_transfer_payment) 
 * \brief Set yearly_transfer_payment memory variable for current X-machine.
 * \param yearly_transfer_payment New value for variable.
 */
void set_yearly_transfer_payment(double yearly_transfer_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_transfer_payment = yearly_transfer_payment;
}

/** \fn double get_yearly_transfer_payment()
 * \brief Get yearly_transfer_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_transfer_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_transfer_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_hh_subsidy_payment(double hh_subsidy_payment) 
 * \brief Set hh_subsidy_payment memory variable for current X-machine.
 * \param hh_subsidy_payment New value for variable.
 */
void set_hh_subsidy_payment(double hh_subsidy_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).hh_subsidy_payment = hh_subsidy_payment;
}

/** \fn double get_hh_subsidy_payment()
 * \brief Get hh_subsidy_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_hh_subsidy_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).hh_subsidy_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_subsidy_payment(double firm_subsidy_payment) 
 * \brief Set firm_subsidy_payment memory variable for current X-machine.
 * \param firm_subsidy_payment New value for variable.
 */
void set_firm_subsidy_payment(double firm_subsidy_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).firm_subsidy_payment = firm_subsidy_payment;
}

/** \fn double get_firm_subsidy_payment()
 * \brief Get firm_subsidy_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_subsidy_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).firm_subsidy_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_subsidy_payment(double monthly_subsidy_payment) 
 * \brief Set monthly_subsidy_payment memory variable for current X-machine.
 * \param monthly_subsidy_payment New value for variable.
 */
void set_monthly_subsidy_payment(double monthly_subsidy_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_subsidy_payment = monthly_subsidy_payment;
}

/** \fn double get_monthly_subsidy_payment()
 * \brief Get monthly_subsidy_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_subsidy_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_subsidy_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_subsidy_payment(double yearly_subsidy_payment) 
 * \brief Set yearly_subsidy_payment memory variable for current X-machine.
 * \param yearly_subsidy_payment New value for variable.
 */
void set_yearly_subsidy_payment(double yearly_subsidy_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_subsidy_payment = yearly_subsidy_payment;
}

/** \fn double get_yearly_subsidy_payment()
 * \brief Get yearly_subsidy_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_subsidy_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_subsidy_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_bond_coupon_payment(double monthly_bond_coupon_payment) 
 * \brief Set monthly_bond_coupon_payment memory variable for current X-machine.
 * \param monthly_bond_coupon_payment New value for variable.
 */
void set_monthly_bond_coupon_payment(double monthly_bond_coupon_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_bond_coupon_payment = monthly_bond_coupon_payment;
}

/** \fn double get_monthly_bond_coupon_payment()
 * \brief Get monthly_bond_coupon_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_bond_coupon_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_bond_coupon_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_bond_coupon_payment(double yearly_bond_coupon_payment) 
 * \brief Set yearly_bond_coupon_payment memory variable for current X-machine.
 * \param yearly_bond_coupon_payment New value for variable.
 */
void set_yearly_bond_coupon_payment(double yearly_bond_coupon_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_bond_coupon_payment = yearly_bond_coupon_payment;
}

/** \fn double get_yearly_bond_coupon_payment()
 * \brief Get yearly_bond_coupon_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_bond_coupon_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_bond_coupon_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gov_interest_rate(double gov_interest_rate) 
 * \brief Set gov_interest_rate memory variable for current X-machine.
 * \param gov_interest_rate New value for variable.
 */
void set_gov_interest_rate(double gov_interest_rate)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gov_interest_rate = gov_interest_rate;
}

/** \fn double get_gov_interest_rate()
 * \brief Get gov_interest_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gov_interest_rate()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gov_interest_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_interest_payment(double yearly_interest_payment) 
 * \brief Set yearly_interest_payment memory variable for current X-machine.
 * \param yearly_interest_payment New value for variable.
 */
void set_yearly_interest_payment(double yearly_interest_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_interest_payment = yearly_interest_payment;
}

/** \fn double get_yearly_interest_payment()
 * \brief Get yearly_interest_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_interest_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_interest_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_gov_investment(double yearly_gov_investment) 
 * \brief Set yearly_gov_investment memory variable for current X-machine.
 * \param yearly_gov_investment New value for variable.
 */
void set_yearly_gov_investment(double yearly_gov_investment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_gov_investment = yearly_gov_investment;
}

/** \fn double get_yearly_gov_investment()
 * \brief Get yearly_gov_investment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_gov_investment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_gov_investment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_gov_consumption(double yearly_gov_consumption) 
 * \brief Set yearly_gov_consumption memory variable for current X-machine.
 * \param yearly_gov_consumption New value for variable.
 */
void set_yearly_gov_consumption(double yearly_gov_consumption)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_gov_consumption = yearly_gov_consumption;
}

/** \fn double get_yearly_gov_consumption()
 * \brief Get yearly_gov_consumption memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_gov_consumption()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_gov_consumption;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_income(double total_income) 
 * \brief Set total_income memory variable for current X-machine.
 * \param total_income New value for variable.
 */
void set_total_income(double total_income)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_income = total_income;
}

/** \fn double get_total_income()
 * \brief Get total_income memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_income()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_expenditure(double total_expenditure) 
 * \brief Set total_expenditure memory variable for current X-machine.
 * \param total_expenditure New value for variable.
 */
void set_total_expenditure(double total_expenditure)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_expenditure = total_expenditure;
}

/** \fn double get_total_expenditure()
 * \brief Get total_expenditure memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_expenditure()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_expenditure;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_debt(double total_debt) 
 * \brief Set total_debt memory variable for current X-machine.
 * \param total_debt New value for variable.
 */
void set_total_debt(double total_debt)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_debt = total_debt;
}

/** \fn double get_total_debt()
 * \brief Get total_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_debt()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_budget_deficit(double budget_deficit) 
 * \brief Set budget_deficit memory variable for current X-machine.
 * \param budget_deficit New value for variable.
 */
void set_budget_deficit(double budget_deficit)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).budget_deficit = budget_deficit;
}

/** \fn double get_budget_deficit()
 * \brief Get budget_deficit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_budget_deficit()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).budget_deficit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_money_financing(double total_money_financing) 
 * \brief Set total_money_financing memory variable for current X-machine.
 * \param total_money_financing New value for variable.
 */
void set_total_money_financing(double total_money_financing)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_money_financing = total_money_financing;
}

/** \fn double get_total_money_financing()
 * \brief Get total_money_financing memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_money_financing()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_money_financing;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_bond_financing(double total_bond_financing) 
 * \brief Set total_bond_financing memory variable for current X-machine.
 * \param total_bond_financing New value for variable.
 */
void set_total_bond_financing(double total_bond_financing)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_bond_financing = total_bond_financing;
}

/** \fn double get_total_bond_financing()
 * \brief Get total_bond_financing memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_bond_financing()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_bond_financing;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_country_wide_mean_wage(double country_wide_mean_wage) 
 * \brief Set country_wide_mean_wage memory variable for current X-machine.
 * \param country_wide_mean_wage New value for variable.
 */
void set_country_wide_mean_wage(double country_wide_mean_wage)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).country_wide_mean_wage = country_wide_mean_wage;
}

/** \fn double get_country_wide_mean_wage()
 * \brief Get country_wide_mean_wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_country_wide_mean_wage()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).country_wide_mean_wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_num_unemployed(int num_unemployed) 
 * \brief Set num_unemployed memory variable for current X-machine.
 * \param num_unemployed New value for variable.
 */
void set_num_unemployed(int num_unemployed)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).num_unemployed = num_unemployed;
}

/** \fn int get_num_unemployed()
 * \brief Get num_unemployed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_num_unemployed()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).num_unemployed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_gdp(double gdp) 
 * \brief Set gdp memory variable for current X-machine.
 * \param gdp New value for variable.
 */
void set_gdp(double gdp)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gdp = gdp;
}

/** \fn double get_gdp()
 * \brief Get gdp memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gdp()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gdp;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gdp_growth(double gdp_growth) 
 * \brief Set gdp_growth memory variable for current X-machine.
 * \param gdp_growth New value for variable.
 */
void set_gdp_growth(double gdp_growth)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gdp_growth = gdp_growth;
}

/** \fn double get_gdp_growth()
 * \brief Get gdp_growth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gdp_growth()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gdp_growth;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gdp_forecast(double gdp_forecast) 
 * \brief Set gdp_forecast memory variable for current X-machine.
 * \param gdp_forecast New value for variable.
 */
void set_gdp_forecast(double gdp_forecast)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gdp_forecast = gdp_forecast;
}

/** \fn double get_gdp_forecast()
 * \brief Get gdp_forecast memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gdp_forecast()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gdp_forecast;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_income_forecast(double total_income_forecast) 
 * \brief Set total_income_forecast memory variable for current X-machine.
 * \param total_income_forecast New value for variable.
 */
void set_total_income_forecast(double total_income_forecast)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_income_forecast = total_income_forecast;
}

/** \fn double get_total_income_forecast()
 * \brief Get total_income_forecast memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_income_forecast()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_income_forecast;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_expenditure_forecast(double total_expenditure_forecast) 
 * \brief Set total_expenditure_forecast memory variable for current X-machine.
 * \param total_expenditure_forecast New value for variable.
 */
void set_total_expenditure_forecast(double total_expenditure_forecast)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_expenditure_forecast = total_expenditure_forecast;
}

/** \fn double get_total_expenditure_forecast()
 * \brief Get total_expenditure_forecast memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_expenditure_forecast()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_expenditure_forecast;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_budget_forecast(double budget_forecast) 
 * \brief Set budget_forecast memory variable for current X-machine.
 * \param budget_forecast New value for variable.
 */
void set_budget_forecast(double budget_forecast)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).budget_forecast = budget_forecast;
}

/** \fn double get_budget_forecast()
 * \brief Get budget_forecast memory variable from current X-machine.
 * \return Value for variable.
 */
double get_budget_forecast()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).budget_forecast;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double get_bank_accounts()
 * \brief Get bank_accounts memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_bank_accounts()
{
	if(current_xmachine->xmachine_Central_Bank) return (*current_xmachine->xmachine_Central_Bank).bank_accounts;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_gov_accounts()
 * \brief Get gov_accounts memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_gov_accounts()
{
	if(current_xmachine->xmachine_Central_Bank) return (*current_xmachine->xmachine_Central_Bank).gov_accounts;

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
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->;*/
    /*if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->;*/
    /*if (current_xmachine->xmachine_Central_Bank) value = current_xmachine->xmachine_Central_Bank->;*/

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
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->id;*/
    /*if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->id;*/
    /*if (current_xmachine->xmachine_Central_Bank) value = current_xmachine->xmachine_Central_Bank->;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->0.0;*/
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->0.0;*/
    /*if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->0.0;*/
    /*if (current_xmachine->xmachine_Central_Bank) value = current_xmachine->xmachine_Central_Bank->0.0;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->0.0;*/ 
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->0.0;*/ 
    /*if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->0.0;*/ 
    /*if (current_xmachine->xmachine_Central_Bank) value = current_xmachine->xmachine_Central_Bank->0.0;*/ 

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
	current->central_bank_account_update_messages = NULL;
	current->tax_payment_messages = NULL;
	current->data_for_government_messages = NULL;
	current->policy_announcement_messages = NULL;
	current->unemployment_notification_messages = NULL;
	current->hh_transfer_notification_messages = NULL;
	current->hh_subsidy_notification_messages = NULL;
	current->firm_transfer_notification_messages = NULL;
	current->firm_subsidy_notification_messages = NULL;


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
	freexmachines();
	/* Free space partitions linked list */
	free_node_info();
	/* Free agent states */
	free_Household_states();
	free_Firm_states();
	free_Government_states();
	free_Central_Bank_states();
	
	
	/* Free message boards */

	rc = MB_Delete(&b_central_bank_account_update);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'central_bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'central_bank_account_update' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'central_bank_account_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_tax_payment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'tax_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_payment' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'tax_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_data_for_government);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'data_for_government' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'data_for_government' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'data_for_government' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_policy_announcement);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'policy_announcement' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_announcement' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_unemployment_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'unemployment_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'unemployment_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_hh_transfer_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'hh_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_hh_subsidy_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'hh_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_firm_transfer_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'firm_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_firm_subsidy_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'firm_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif


    rc = MB_Env_Finalise();
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not finalise MB environment\n");
       switch(rc) {
           case MB_ERR_ENV:
               fprintf(stderr, "\t reason: MB environment not yet started?\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Env_Finalise returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	

	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<totaltime>", file);
	sprintf(data, "%d", (int)(total_time * 1000.0) % 1000);
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
			x_xmachine = current_xmachine->xmachine_Household->0.0;
			y_xmachine = current_xmachine->xmachine_Household->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Firm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Firm->0.0;
			y_xmachine = current_xmachine->xmachine_Firm->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Government != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Government->0.0;
			y_xmachine = current_xmachine->xmachine_Government->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Central_Bank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Central_Bank->0.0;
			y_xmachine = current_xmachine->xmachine_Central_Bank->0.0;
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


/** \fn int idle()
 * \brief an idle function for use by agents.
 */
int idle()
{
	return 0;
}
