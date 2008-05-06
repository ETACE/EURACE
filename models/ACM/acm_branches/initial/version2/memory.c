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
	//temp_xmachine_Firm_04 = NULL;
	Firm_04_state = init_Firm_state();//&temp_xmachine_Firm_04;
	//temp_xmachine_Firm_03 = NULL;
	Firm_03_state = init_Firm_state();//&temp_xmachine_Firm_03;
	//temp_xmachine_Firm_02 = NULL;
	Firm_02_state = init_Firm_state();//&temp_xmachine_Firm_02;
	//temp_xmachine_Firm_01 = NULL;
	Firm_01_state = init_Firm_state();//&temp_xmachine_Firm_01;
	//temp_xmachine_Firm_firm_start = NULL;
	Firm_firm_start_state = init_Firm_state();//&temp_xmachine_Firm_firm_start;
	//temp_xmachine_Bank_05 = NULL;
	Bank_05_state = init_Bank_state();//&temp_xmachine_Bank_05;
	//temp_xmachine_Bank_04 = NULL;
	Bank_04_state = init_Bank_state();//&temp_xmachine_Bank_04;
	//temp_xmachine_Bank_03 = NULL;
	Bank_03_state = init_Bank_state();//&temp_xmachine_Bank_03;
	//temp_xmachine_Bank_02 = NULL;
	Bank_02_state = init_Bank_state();//&temp_xmachine_Bank_02;
	//temp_xmachine_Bank_01 = NULL;
	Bank_01_state = init_Bank_state();//&temp_xmachine_Bank_01;
	//temp_xmachine_Bank_Bank_start = NULL;
	Bank_Bank_start_state = init_Bank_state();//&temp_xmachine_Bank_Bank_start;
	//temp_xmachine_Household_01 = NULL;
	Household_01_state = init_Household_state();//&temp_xmachine_Household_01;
	//temp_xmachine_Household_HH_start = NULL;
	Household_HH_start_state = init_Household_state();//&temp_xmachine_Household_HH_start;
	

    rc = MB_Create(&b_loan_request, sizeof(m_loan_request));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'loan_request' board\n");
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

    rc = MB_Create(&b_loan_conditions, sizeof(m_loan_conditions));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'loan_conditions' board\n");
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

    rc = MB_Create(&b_household_deposit, sizeof(m_household_deposit));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'household_deposit' board\n");
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

    rc = MB_Create(&b_money_withdraw_request, sizeof(m_money_withdraw_request));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'money_withdraw_request' board\n");
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

    rc = MB_Create(&b_loan_acceptance, sizeof(m_loan_acceptance));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'loan_acceptance' board\n");
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

    rc = MB_Create(&b_installment, sizeof(m_installment));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'installment' board\n");
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

    rc = MB_Create(&b_withdrawal_allowed, sizeof(m_withdrawal_allowed));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'withdrawal_allowed' board\n");
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

    rc = MB_Create(&b_bankruptcy, sizeof(m_bankruptcy));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not create 'bankruptcy' board\n");
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
	//p_loan_request_message = &current_node->loan_request_messages;
	//p_loan_conditions_message = &current_node->loan_conditions_messages;
	//p_household_deposit_message = &current_node->household_deposit_messages;
	//p_money_withdraw_request_message = &current_node->money_withdraw_request_messages;
	//p_loan_acceptance_message = &current_node->loan_acceptance_messages;
	//p_installment_message = &current_node->installment_messages;
	//p_withdrawal_allowed_message = &current_node->withdrawal_allowed_messages;
	//p_bankruptcy_message = &current_node->bankruptcy_messages;
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
	init_double_array(&current->interest);
	init_double_array(&current->credit_offer);
	init_int_array(&current->contacted_bank);
	current->total_debt = 0.0;
	current->asset = 0.0;
	current->credit_demand = 0.0;
	init_double_array(&current->installment_amount);
	current->installment_number = 0;
	current->loans_number = 0;
	init_double_array(&current->outstanding_debt);
	init_int_array(&current->lending_bank_id);
	init_double_array(&current->interest_amount);
	current->bankruptcy_state = 0;
	current->total_resources = 0.0;
	init_double_array(&current->residual_variable);
	init_double_array(&current->variable_per_installment);
	init_double_array(&current->value_at_risk);
	init_double_array(&current->interest_left);
	current->current_equity = 0.0;
	current->current_debt = 0.0;
	
	return current;
}

void free_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_double_array(&tmp->agent->interest);
	free_double_array(&tmp->agent->credit_offer);
	free_int_array(&tmp->agent->contacted_bank);
	free_double_array(&tmp->agent->installment_amount);
	free_double_array(&tmp->agent->outstanding_debt);
	free_int_array(&tmp->agent->lending_bank_id);
	free_double_array(&tmp->agent->interest_amount);
	free_double_array(&tmp->agent->residual_variable);
	free_double_array(&tmp->agent->variable_per_installment);
	free_double_array(&tmp->agent->value_at_risk);
	free_double_array(&tmp->agent->interest_left);
	
	
	free(tmp->agent);
	free(tmp);
}

void free_Firm_agents()
{
/*	while(*Firm_04_state)
	{
		free_Firm_agent(*Firm_04_state, Firm_04_state);
	}
	while(*Firm_03_state)
	{
		free_Firm_agent(*Firm_03_state, Firm_03_state);
	}
	while(*Firm_02_state)
	{
		free_Firm_agent(*Firm_02_state, Firm_02_state);
	}
	while(*Firm_01_state)
	{
		free_Firm_agent(*Firm_01_state, Firm_01_state);
	}
	while(*Firm_firm_start_state)
	{
		free_Firm_agent(*Firm_firm_start_state, Firm_firm_start_state);
	}
*/}

void free_Firm_states()
{
	free(Firm_04_state);
	free(Firm_03_state);
	free(Firm_02_state);
	free(Firm_01_state);
	free(Firm_firm_start_state);
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

/** \fn void add_Firm_agent(int id, double_array * interest, double_array * credit_offer, int_array * contacted_bank, double total_debt, double asset, double credit_demand, double_array * installment_amount, int installment_number, int loans_number, double_array * outstanding_debt, int_array * lending_bank_id, double_array * interest_amount, int bankruptcy_state, double total_resources, double_array * residual_variable, double_array * variable_per_installment, double_array * value_at_risk, double_array * interest_left, double current_equity, double current_debt)
 * \brief Add Firm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param interest Variable for the X-machine memory.
 * \param credit_offer Variable for the X-machine memory.
 * \param contacted_bank Variable for the X-machine memory.
 * \param total_debt Variable for the X-machine memory.
 * \param asset Variable for the X-machine memory.
 * \param credit_demand Variable for the X-machine memory.
 * \param installment_amount Variable for the X-machine memory.
 * \param installment_number Variable for the X-machine memory.
 * \param loans_number Variable for the X-machine memory.
 * \param outstanding_debt Variable for the X-machine memory.
 * \param lending_bank_id Variable for the X-machine memory.
 * \param interest_amount Variable for the X-machine memory.
 * \param bankruptcy_state Variable for the X-machine memory.
 * \param total_resources Variable for the X-machine memory.
 * \param residual_variable Variable for the X-machine memory.
 * \param variable_per_installment Variable for the X-machine memory.
 * \param value_at_risk Variable for the X-machine memory.
 * \param interest_left Variable for the X-machine memory.
 * \param current_equity Variable for the X-machine memory.
 * \param current_debt Variable for the X-machine memory.
 */
void add_Firm_agent(int id, double_array * interest, double_array * credit_offer, int_array * contacted_bank, double total_debt, double asset, double credit_demand, double_array * installment_amount, int installment_number, int loans_number, double_array * outstanding_debt, int_array * lending_bank_id, double_array * interest_amount, int bankruptcy_state, double total_resources, double_array * residual_variable, double_array * variable_per_installment, double_array * value_at_risk, double_array * interest_left, double current_equity, double current_debt)
{
	xmachine_memory_Firm * current;
	
	current = init_Firm_agent();
	add_Firm_agent_internal(current, current_xmachine_Firm_next_state);
	
	current->id = id;
	copy_double_array(interest, &current->interest);
	copy_double_array(credit_offer, &current->credit_offer);
	copy_int_array(contacted_bank, &current->contacted_bank);
	current->total_debt = total_debt;
	current->asset = asset;
	current->credit_demand = credit_demand;
	copy_double_array(installment_amount, &current->installment_amount);
	current->installment_number = installment_number;
	current->loans_number = loans_number;
	copy_double_array(outstanding_debt, &current->outstanding_debt);
	copy_int_array(lending_bank_id, &current->lending_bank_id);
	copy_double_array(interest_amount, &current->interest_amount);
	current->bankruptcy_state = bankruptcy_state;
	current->total_resources = total_resources;
	copy_double_array(residual_variable, &current->residual_variable);
	copy_double_array(variable_per_installment, &current->variable_per_installment);
	copy_double_array(value_at_risk, &current->value_at_risk);
	copy_double_array(interest_left, &current->interest_left);
	current->current_equity = current_equity;
	current->current_debt = current_debt;
}

xmachine_memory_Bank_state * init_Bank_state()
{
	xmachine_memory_Bank_state * current = (xmachine_memory_Bank_state *)malloc(sizeof(xmachine_memory_Bank_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Bank * init_Bank_agent()
{
	xmachine_memory_Bank * current = (xmachine_memory_Bank *)malloc(sizeof(xmachine_memory_Bank));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->cash = 0.0;
	current->total_credit = 0.0;
	current->equity = 0.0;
	current->bce_debt = 0.0;
	current->alfa = 0.0;
	current->variable = 0.0;
	current->min_interest = 0.0;
	init_double_static_array(current->gamma, 2);
	init_double_static_array(current->profits, 2);
	current->lambda = 0.0;
	current->bce_interest = 0.0;
	current->debt_period = 0.0;
	current->loan_request_message_found = 0;
	current->day_of_month_to_act = 0;
	
	return current;
}

void free_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	
	
	free(tmp->agent);
	free(tmp);
}

void free_Bank_agents()
{
/*	while(*Bank_05_state)
	{
		free_Bank_agent(*Bank_05_state, Bank_05_state);
	}
	while(*Bank_04_state)
	{
		free_Bank_agent(*Bank_04_state, Bank_04_state);
	}
	while(*Bank_03_state)
	{
		free_Bank_agent(*Bank_03_state, Bank_03_state);
	}
	while(*Bank_02_state)
	{
		free_Bank_agent(*Bank_02_state, Bank_02_state);
	}
	while(*Bank_01_state)
	{
		free_Bank_agent(*Bank_01_state, Bank_01_state);
	}
	while(*Bank_Bank_start_state)
	{
		free_Bank_agent(*Bank_Bank_start_state, Bank_Bank_start_state);
	}
*/}

void free_Bank_states()
{
	free(Bank_05_state);
	free(Bank_04_state);
	free(Bank_03_state);
	free(Bank_02_state);
	free(Bank_01_state);
	free(Bank_Bank_start_state);
}

void transition_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * from_state, xmachine_memory_Bank_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Bank_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Bank_agent_internal(xmachine_memory_Bank * agent, xmachine_memory_Bank_state * state)
{
	xmachine_memory_Bank_holder * current = (xmachine_memory_Bank_holder *)malloc(sizeof(xmachine_memory_Bank_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;
}

/** \fn void add_Bank_agent(int id, double cash, double total_credit, double equity, double bce_debt, double alfa, double variable, double min_interest, double gamma[], double profits[], double lambda, double bce_interest, double debt_period, int loan_request_message_found, int day_of_month_to_act)
 * \brief Add Bank X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param cash Variable for the X-machine memory.
 * \param total_credit Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param bce_debt Variable for the X-machine memory.
 * \param alfa Variable for the X-machine memory.
 * \param variable Variable for the X-machine memory.
 * \param min_interest Variable for the X-machine memory.
 * \param gamma Variable for the X-machine memory.
 * \param profits Variable for the X-machine memory.
 * \param lambda Variable for the X-machine memory.
 * \param bce_interest Variable for the X-machine memory.
 * \param debt_period Variable for the X-machine memory.
 * \param loan_request_message_found Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 */
void add_Bank_agent(int id, double cash, double total_credit, double equity, double bce_debt, double alfa, double variable, double min_interest, double gamma[], double profits[], double lambda, double bce_interest, double debt_period, int loan_request_message_found, int day_of_month_to_act)
{
	xmachine_memory_Bank * current;
	
	current = init_Bank_agent();
	add_Bank_agent_internal(current, current_xmachine_Bank_next_state);
	
	current->id = id;
	current->cash = cash;
	current->total_credit = total_credit;
	current->equity = equity;
	current->bce_debt = bce_debt;
	current->alfa = alfa;
	current->variable = variable;
	current->min_interest = min_interest;
	memcpy(current->gamma, gamma, 2*sizeof(double));
	memcpy(current->profits, profits, 2*sizeof(double));
	current->lambda = lambda;
	current->bce_interest = bce_interest;
	current->debt_period = debt_period;
	current->loan_request_message_found = loan_request_message_found;
	current->day_of_month_to_act = day_of_month_to_act;
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
	current->total_deposit = 0.0;
	current->bank_account = 0;
	
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

void free_Household_agents()
{
/*	while(*Household_01_state)
	{
		free_Household_agent(*Household_01_state, Household_01_state);
	}
	while(*Household_HH_start_state)
	{
		free_Household_agent(*Household_HH_start_state, Household_HH_start_state);
	}
*/}

void free_Household_states()
{
	free(Household_01_state);
	free(Household_HH_start_state);
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

/** \fn void add_Household_agent(int id, double total_deposit, int bank_account)
 * \brief Add Household X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param total_deposit Variable for the X-machine memory.
 * \param bank_account Variable for the X-machine memory.
 */
void add_Household_agent(int id, double total_deposit, int bank_account)
{
	xmachine_memory_Household * current;
	
	current = init_Household_agent();
	add_Household_agent_internal(current, current_xmachine_Household_next_state);
	
	current->id = id;
	current->total_deposit = total_deposit;
	current->bank_account = bank_account;
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
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).id = id;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).id = id;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).id;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).id;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn double_array get_interest()
 * \brief Get interest memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_interest()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).interest;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double_array get_credit_offer()
 * \brief Get credit_offer memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_credit_offer()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).credit_offer;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn int_array get_contacted_bank()
 * \brief Get contacted_bank memory variable from current X-machine.
 * \return Value for variable.
 */
int_array * get_contacted_bank()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).contacted_bank;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_debt(double total_debt) 
 * \brief Set total_debt memory variable for current X-machine.
 * \param total_debt New value for variable.
 */
void set_total_debt(double total_debt)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_debt = total_debt;
}

/** \fn double get_total_debt()
 * \brief Get total_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_debt()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_asset(double asset) 
 * \brief Set asset memory variable for current X-machine.
 * \param asset New value for variable.
 */
void set_asset(double asset)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).asset = asset;
}

/** \fn double get_asset()
 * \brief Get asset memory variable from current X-machine.
 * \return Value for variable.
 */
double get_asset()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).asset;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_credit_demand(double credit_demand) 
 * \brief Set credit_demand memory variable for current X-machine.
 * \param credit_demand New value for variable.
 */
void set_credit_demand(double credit_demand)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).credit_demand = credit_demand;
}

/** \fn double get_credit_demand()
 * \brief Get credit_demand memory variable from current X-machine.
 * \return Value for variable.
 */
double get_credit_demand()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).credit_demand;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double_array get_installment_amount()
 * \brief Get installment_amount memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_installment_amount()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).installment_amount;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_installment_number(int installment_number) 
 * \brief Set installment_number memory variable for current X-machine.
 * \param installment_number New value for variable.
 */
void set_installment_number(int installment_number)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).installment_number = installment_number;
}

/** \fn int get_installment_number()
 * \brief Get installment_number memory variable from current X-machine.
 * \return Value for variable.
 */
int get_installment_number()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).installment_number;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_loans_number(int loans_number) 
 * \brief Set loans_number memory variable for current X-machine.
 * \param loans_number New value for variable.
 */
void set_loans_number(int loans_number)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).loans_number = loans_number;
}

/** \fn int get_loans_number()
 * \brief Get loans_number memory variable from current X-machine.
 * \return Value for variable.
 */
int get_loans_number()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).loans_number;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn double_array get_outstanding_debt()
 * \brief Get outstanding_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_outstanding_debt()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).outstanding_debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn int_array get_lending_bank_id()
 * \brief Get lending_bank_id memory variable from current X-machine.
 * \return Value for variable.
 */
int_array * get_lending_bank_id()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).lending_bank_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double_array get_interest_amount()
 * \brief Get interest_amount memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_interest_amount()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).interest_amount;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_bankruptcy_state(int bankruptcy_state) 
 * \brief Set bankruptcy_state memory variable for current X-machine.
 * \param bankruptcy_state New value for variable.
 */
void set_bankruptcy_state(int bankruptcy_state)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).bankruptcy_state = bankruptcy_state;
}

/** \fn int get_bankruptcy_state()
 * \brief Get bankruptcy_state memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bankruptcy_state()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).bankruptcy_state;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_total_resources(double total_resources) 
 * \brief Set total_resources memory variable for current X-machine.
 * \param total_resources New value for variable.
 */
void set_total_resources(double total_resources)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_resources = total_resources;
}

/** \fn double get_total_resources()
 * \brief Get total_resources memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_resources()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_resources;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double_array get_residual_variable()
 * \brief Get residual_variable memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_residual_variable()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).residual_variable;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double_array get_variable_per_installment()
 * \brief Get variable_per_installment memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_variable_per_installment()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).variable_per_installment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double_array get_value_at_risk()
 * \brief Get value_at_risk memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_value_at_risk()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).value_at_risk;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double_array get_interest_left()
 * \brief Get interest_left memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_interest_left()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).interest_left;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_current_equity(double current_equity) 
 * \brief Set current_equity memory variable for current X-machine.
 * \param current_equity New value for variable.
 */
void set_current_equity(double current_equity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_equity = current_equity;
}

/** \fn double get_current_equity()
 * \brief Get current_equity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_equity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_equity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_debt(double current_debt) 
 * \brief Set current_debt memory variable for current X-machine.
 * \param current_debt New value for variable.
 */
void set_current_debt(double current_debt)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_debt = current_debt;
}

/** \fn double get_current_debt()
 * \brief Get current_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_debt()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_cash(double cash) 
 * \brief Set cash memory variable for current X-machine.
 * \param cash New value for variable.
 */
void set_cash(double cash)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).cash = cash;
}

/** \fn double get_cash()
 * \brief Get cash memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cash()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).cash;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_credit(double total_credit) 
 * \brief Set total_credit memory variable for current X-machine.
 * \param total_credit New value for variable.
 */
void set_total_credit(double total_credit)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).total_credit = total_credit;
}

/** \fn double get_total_credit()
 * \brief Get total_credit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_credit()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).total_credit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_equity(double equity) 
 * \brief Set equity memory variable for current X-machine.
 * \param equity New value for variable.
 */
void set_equity(double equity)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).equity = equity;
}

/** \fn double get_equity()
 * \brief Get equity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_equity()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).equity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_bce_debt(double bce_debt) 
 * \brief Set bce_debt memory variable for current X-machine.
 * \param bce_debt New value for variable.
 */
void set_bce_debt(double bce_debt)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).bce_debt = bce_debt;
}

/** \fn double get_bce_debt()
 * \brief Get bce_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bce_debt()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).bce_debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_alfa(double alfa) 
 * \brief Set alfa memory variable for current X-machine.
 * \param alfa New value for variable.
 */
void set_alfa(double alfa)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).alfa = alfa;
}

/** \fn double get_alfa()
 * \brief Get alfa memory variable from current X-machine.
 * \return Value for variable.
 */
double get_alfa()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).alfa;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_variable(double variable) 
 * \brief Set variable memory variable for current X-machine.
 * \param variable New value for variable.
 */
void set_variable(double variable)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).variable = variable;
}

/** \fn double get_variable()
 * \brief Get variable memory variable from current X-machine.
 * \return Value for variable.
 */
double get_variable()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).variable;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_min_interest(double min_interest) 
 * \brief Set min_interest memory variable for current X-machine.
 * \param min_interest New value for variable.
 */
void set_min_interest(double min_interest)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).min_interest = min_interest;
}

/** \fn double get_min_interest()
 * \brief Get min_interest memory variable from current X-machine.
 * \return Value for variable.
 */
double get_min_interest()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).min_interest;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double get_gamma()
 * \brief Get gamma memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_gamma()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).gamma;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_profits()
 * \brief Get profits memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_profits()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).profits;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_lambda(double lambda) 
 * \brief Set lambda memory variable for current X-machine.
 * \param lambda New value for variable.
 */
void set_lambda(double lambda)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).lambda = lambda;
}

/** \fn double get_lambda()
 * \brief Get lambda memory variable from current X-machine.
 * \return Value for variable.
 */
double get_lambda()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).lambda;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_bce_interest(double bce_interest) 
 * \brief Set bce_interest memory variable for current X-machine.
 * \param bce_interest New value for variable.
 */
void set_bce_interest(double bce_interest)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).bce_interest = bce_interest;
}

/** \fn double get_bce_interest()
 * \brief Get bce_interest memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bce_interest()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).bce_interest;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_debt_period(double debt_period) 
 * \brief Set debt_period memory variable for current X-machine.
 * \param debt_period New value for variable.
 */
void set_debt_period(double debt_period)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).debt_period = debt_period;
}

/** \fn double get_debt_period()
 * \brief Get debt_period memory variable from current X-machine.
 * \return Value for variable.
 */
double get_debt_period()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).debt_period;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_loan_request_message_found(int loan_request_message_found) 
 * \brief Set loan_request_message_found memory variable for current X-machine.
 * \param loan_request_message_found New value for variable.
 */
void set_loan_request_message_found(int loan_request_message_found)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).loan_request_message_found = loan_request_message_found;
}

/** \fn int get_loan_request_message_found()
 * \brief Get loan_request_message_found memory variable from current X-machine.
 * \return Value for variable.
 */
int get_loan_request_message_found()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).loan_request_message_found;

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
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).day_of_month_to_act = day_of_month_to_act;
}

/** \fn int get_day_of_month_to_act()
 * \brief Get day_of_month_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_to_act()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).day_of_month_to_act;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_total_deposit(double total_deposit) 
 * \brief Set total_deposit memory variable for current X-machine.
 * \param total_deposit New value for variable.
 */
void set_total_deposit(double total_deposit)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).total_deposit = total_deposit;
}

/** \fn double get_total_deposit()
 * \brief Get total_deposit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_deposit()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).total_deposit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_bank_account(int bank_account) 
 * \brief Set bank_account memory variable for current X-machine.
 * \param bank_account New value for variable.
 */
void set_bank_account(int bank_account)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).bank_account = bank_account;
}

/** \fn int get_bank_account()
 * \brief Get bank_account memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bank_account()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).bank_account;

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
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->;*/
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->;*/
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;*/

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->id;*/
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->id;*/
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->id;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->;*/
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->;*/
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->;*/ 
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->;*/ 
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;*/ 

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
	current->loan_request_messages = NULL;
	current->loan_conditions_messages = NULL;
	current->household_deposit_messages = NULL;
	current->money_withdraw_request_messages = NULL;
	current->loan_acceptance_messages = NULL;
	current->installment_messages = NULL;
	current->withdrawal_allowed_messages = NULL;
	current->bankruptcy_messages = NULL;


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
	free_Firm_states();
	free_Bank_states();
	free_Household_states();
	
	
	/* Free message boards */

	rc = MB_Delete(&b_loan_request);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	rc = MB_Delete(&b_loan_conditions);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_conditions' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_conditions' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_conditions' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	rc = MB_Delete(&b_household_deposit);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'household_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_deposit' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	rc = MB_Delete(&b_money_withdraw_request);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'money_withdraw_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'money_withdraw_request' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'money_withdraw_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	rc = MB_Delete(&b_loan_acceptance);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acceptance' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_acceptance' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	rc = MB_Delete(&b_installment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'installment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'installment' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'installment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	rc = MB_Delete(&b_withdrawal_allowed);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'withdrawal_allowed' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'withdrawal_allowed' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'withdrawal_allowed' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

	rc = MB_Delete(&b_bankruptcy);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'bankruptcy' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
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
		if(current_xmachine->xmachine_Firm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Firm->;
			y_xmachine = current_xmachine->xmachine_Firm->;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Bank->;
			y_xmachine = current_xmachine->xmachine_Bank->;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Household->;
			y_xmachine = current_xmachine->xmachine_Household->;
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


