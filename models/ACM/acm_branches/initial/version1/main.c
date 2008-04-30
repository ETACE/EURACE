/**
 * \file  main.c
 * \brief Holds main function of the program.
 */

#include "header.h"

/** \fn int main(int argc, char * argv[])
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char * argv[])
{
	/* Timing variables */
	clock_t start, stop, interval;
	FILE *file;
	char data[100];
	char logfilepath[100];
	char inputpath[100];
	int lastd = 0;
	int i;
	int rc;
	int iteration_number;
	int iteration_total;
	int * p_iteration_number;
	/* For backwards compatabilty allocate current_xmachine */
	current_xmachine = (xmachine *)malloc(sizeof(xmachine));
	CHECK_POINTER(current_xmachine);
	//xmachine_memory_Firm * temp_xmachine_Firm;
	//xmachine_memory_Bank * temp_xmachine_Bank;
	//xmachine_memory_Household * temp_xmachine_Household;
	
	/* Ratio for calculating time in milliseconds */
    /* (lsc) changed from long to double
     * if "long", time_ratio == 0 when CLOCKS_PER_SEC > 1000
     */
	double time_ratio = 1000.0/CLOCKS_PER_SEC;
	/* Particle cloud data */
	double cloud_data[6];

/* For partition method. Makes geometric (-g flag) the default but may be overridden with -r for round-robin */
	int partition_method=1;


	
	/* Output frequency is 1 as default */
	output_frequency = 1;
	/* Set random seed */
/*	srand(time(NULL)); */
	
	
    
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
            default: break;
	   }
	   
	}
	#endif
	
	/* Initialise pointers */
	initialise_pointers();
	p_iteration_number = &iteration_number;


	printf("FLAME Application: Credit_Market \n");





if(argc < 2)
	{

		printf("Usage: %s <number of iterations> [<states_directory>]/<init_state> <partitions> [-r | -g ]\n",argv[0]);



		exit(0);
	}
	iteration_total = atoi(argv[1]);
printf("Iterations: %i\n", iteration_total);
	
	/* Read initial states of x-machines */
	if(argc < 3)
	{
		printf("Need two parameters\n");
		exit(0);
	}
	strcpy(inputpath, argv[2]);
printf("Initial states: %s\n", inputpath);
	
	i = 0;
	while(inputpath[i] != '\0')
	{
		/* For windows directories */
		if(inputpath[i] == '\\') lastd=i;
		/* For unix directories */
		if(inputpath[i] == '/') lastd=i;
		i++;
	}
	strcpy(outputpath, inputpath);
	outputpath[lastd+1] = '\0';
printf("Ouput dir: %s\n", outputpath);
	

	/* Read number of space partitions (1 by default) */
	totalnodes = 1;
	if(argc > 3)
	{
		totalnodes = atoi(argv[3]);
	}
	

	i = 3;
	while(argc > i)
	{
		if(strcmp(argv[i],"-f") == 0)
		{
			if(argc > (i+1))
			{
				output_frequency = atoi(argv[(i+1)]);
				printf("Using output frequency of: %i\n", output_frequency);
				i++;
			}
			else
			{
				printf("Output frequency number not defined\n");
				exit(0);
			}
		}
		/* Partitioning method: -g = geometric, -r = round-robin */
		if(strcmp(argv[i],"-g") == 0) partition_method = 1;
		if(strcmp(argv[i],"-r") == 0) partition_method = 2;
		i++;
	}
	
	/* Read initial data into p_xmachine  */

       //agent_list = p_xmachine;
       readinitialstates(inputpath, p_iteration_number, cloud_data, partition_method, 0);
       /* Generate partitions */
//       generate_partitions(cloud_data,totalnodes,partition_method);
//       save_partition_data();
 





    /* Partition data */
    /* stc: no partitions in serial */
	//partition_data(totalnodes, agent_list, cloud_data, partition_method);




		/*i = 0;
		current_node = *p_node_info;
		while(current_node)
		{
			printf("No of agents on partition %d: %d\n", current_node->node_id, current_node->agent_total);
			i += current_node->agent_total;
			current_node = current_node->next;
		}
		printf("Agent total check: %d\n", i);*/

        /* restore current_node pointer */
		//current_node = *p_node_info;


	
	/* Start log file (now so that xvisualiser can read straight away) */

	/* Write log file */
	sprintf(logfilepath, "%slog.xml", outputpath);
	file = fopen(logfilepath, "w");
	fputs("<model_run>\n", file);
	fputs("<codetype>", file);
	fputs("serial", file);

	fputs("</codetype>\n", file);
	fputs("<nodes>", file);
	sprintf(data, "%i", totalnodes);
	fputs(data, file);
	fputs("</nodes>\n", file);
	fputs("<!-- warning: time in milliseconds (seems to jump in 15/16ms) -->\n", file);
	fclose(file);

	/* Start timing */
	start = clock();

    /* pre-randomise agents for first iteration */
    //randomisexagent();
	
	for(iteration_loop=iteration_number+1; iteration_loop < iteration_number+iteration_total+1; iteration_loop++)
	{
		interval = clock();
		/* Print out iteration number */
		printf("Iteration - %d\n", iteration_loop);
		/* START OF ITERATION */

	
	current_xmachine_Household_holder = Household_01_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
			i = Household_put_money();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_01_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01_state, Household_02_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}


    rc = MB_SyncStart(b_household_deposit);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'household_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_deposit' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_deposit' board is locked\n");
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


	
	current_xmachine_Firm_holder = Firm_01_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_ask_loan();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_01_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_01_state, Firm_02_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_loan_request);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'loan_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request' board is locked\n");
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



	
	current_xmachine_Household_holder = Household_02_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
			i = Household_choose_bank();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_02_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_02_state, Household_03_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	rc = MB_SyncComplete(b_loan_request);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'loan_request' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request' board is invalid\n");
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
	
	
	current_xmachine_Bank_holder = Bank_01_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;
		
		
		
		
		
		rc = MB_Iterator_Create(b_loan_request, &i_loan_request);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'loan_request'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'loan_request' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_request' board is locked\n");
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
		
		
			i = Bank_decide_credit_conditions();
			
		
		    rc = MB_Iterator_Delete(&i_loan_request);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'loan_request' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'loan_request' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_01_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_01_state, Bank_02_state);
			}
		
		
		current_xmachine_Bank = NULL;
		
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}


    rc = MB_SyncStart(b_loan_conditions);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'loan_conditions' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_conditions' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_conditions' board is locked\n");
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



	
	current_xmachine_Household_holder = Household_03_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
			i = Household_withdraw_request();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_03_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_03_state, Household_04_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}


    rc = MB_SyncStart(b_money_withdraw_request);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'money_withdraw_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'money_withdraw_request' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'money_withdraw_request' board is locked\n");
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


	rc = MB_SyncComplete(b_household_deposit);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'household_deposit' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_deposit' board is invalid\n");
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
	
	
	current_xmachine_Bank_holder = Bank_02_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;
		
		
		
		
		
		rc = MB_Iterator_Create(b_household_deposit, &i_household_deposit);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'household_deposit'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'household_deposit' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'household_deposit' board is locked\n");
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
		
		
			i = Bank_receive_deposits();
			
		
		    rc = MB_Iterator_Delete(&i_household_deposit);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'household_deposit' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'household_deposit' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_02_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_02_state, Bank_03_state);
			}
		
		
		current_xmachine_Bank = NULL;
		
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}



	rc = MB_SyncComplete(b_loan_conditions);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'loan_conditions' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_conditions' board is invalid\n");
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
	
	
	current_xmachine_Firm_holder = Firm_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
		rc = MB_Iterator_Create(b_loan_conditions, &i_loan_conditions);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'loan_conditions'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'loan_conditions' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_conditions' board is locked\n");
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
		
		
			i = Firm_get_loan();
			
		
		    rc = MB_Iterator_Delete(&i_loan_conditions);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'loan_conditions' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'loan_conditions' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_02_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_02_state, Firm_03_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_loan_acceptance);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'loan_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acceptance' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_acceptance' board is locked\n");
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



	rc = MB_SyncComplete(b_money_withdraw_request);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'money_withdraw_request' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'money_withdraw_request' board is invalid\n");
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
	
	
	current_xmachine_Bank_holder = Bank_03_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;
		
		
		
		
		
		rc = MB_Iterator_Create(b_money_withdraw_request, &i_money_withdraw_request);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'money_withdraw_request'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'money_withdraw_request' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'money_withdraw_request' board is locked\n");
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
		
		
			i = Bank_return_deposits();
			
		
		    rc = MB_Iterator_Delete(&i_money_withdraw_request);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'money_withdraw_request' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'money_withdraw_request' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_03_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_03_state, Bank_04_state);
			}
		
		
		current_xmachine_Bank = NULL;
		
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}


    rc = MB_SyncStart(b_withdrawal_allowed);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'withdrawal_allowed' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'withdrawal_allowed' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'withdrawal_allowed' board is locked\n");
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


	
	current_xmachine_Firm_holder = Firm_03_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_pay_interest_installment();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_03_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_03_state, Firm_04_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_installment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'installment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'installment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'installment' board is locked\n");
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

    rc = MB_SyncStart(b_bankruptcy);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'bankruptcy' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
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



	rc = MB_SyncComplete(b_withdrawal_allowed);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'withdrawal_allowed' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'withdrawal_allowed' board is invalid\n");
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
	
	
	current_xmachine_Household_holder = Household_04_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
		rc = MB_Iterator_Create(b_withdrawal_allowed, &i_withdrawal_allowed);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'withdrawal_allowed'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'withdrawal_allowed' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'withdrawal_allowed' board is locked\n");
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
		
		
			i = Household_withdraw();
			
		
		    rc = MB_Iterator_Delete(&i_withdrawal_allowed);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'withdrawal_allowed' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'withdrawal_allowed' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_04_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_04_state, Household_05_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	rc = MB_SyncComplete(b_installment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'installment' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'installment' board is invalid\n");
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
	
	rc = MB_SyncComplete(b_bankruptcy);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'bankruptcy' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy' board is invalid\n");
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
	
	
	current_xmachine_Bank_holder = Bank_04_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;
		
		
		
		
		
		rc = MB_Iterator_Create(b_installment, &i_installment);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'installment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'installment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'installment' board is locked\n");
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
		
		
		rc = MB_Iterator_Create(b_bankruptcy, &i_bankruptcy);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bankruptcy'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bankruptcy' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
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
		
		
			i = Bank_receive_installment();
			
		
		    rc = MB_Iterator_Delete(&i_installment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'installment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'installment' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_bankruptcy);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bankruptcy' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bankruptcy' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_04_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_04_state, Bank_05_state);
			}
		
		
		current_xmachine_Bank = NULL;
		
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}




	rc = MB_SyncComplete(b_loan_acceptance);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'loan_acceptance' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acceptance' board is invalid\n");
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
	
	
	current_xmachine_Bank_holder = Bank_05_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;
		
		
		
		
		
		rc = MB_Iterator_Create(b_loan_acceptance, &i_loan_acceptance);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'loan_acceptance'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'loan_acceptance' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_acceptance' board is locked\n");
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
		
		
			i = Bank_give_loan();
			
		
		    rc = MB_Iterator_Delete(&i_loan_acceptance);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'loan_acceptance' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'loan_acceptance' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_05_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_05_state, Bank_06_state);
			}
		
		
		current_xmachine_Bank = NULL;
		
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}





    rc = MB_Clear(b_loan_request);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'loan_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request' board is invalid\n");
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

    rc = MB_Clear(b_loan_conditions);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'loan_conditions' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_conditions' board is invalid\n");
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

    rc = MB_Clear(b_household_deposit);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'household_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_deposit' board is invalid\n");
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

    rc = MB_Clear(b_money_withdraw_request);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'money_withdraw_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'money_withdraw_request' board is invalid\n");
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

    rc = MB_Clear(b_loan_acceptance);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'loan_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acceptance' board is invalid\n");
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

    rc = MB_Clear(b_installment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'installment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'installment' board is invalid\n");
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

    rc = MB_Clear(b_withdrawal_allowed);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'withdrawal_allowed' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'withdrawal_allowed' board is invalid\n");
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

    rc = MB_Clear(b_bankruptcy);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bankruptcy' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy' board is invalid\n");
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

	if(iteration_loop%output_frequency == 0)
	{
		saveiterationdata(iteration_loop);
	}

	/*printf("Firm_04_state->count = %d\n", Firm_04_state->count);*/
	Firm_04_state->count = 0;

	/*printf("Firm_03_state->count = %d\n", Firm_03_state->count);*/
	Firm_03_state->count = 0;

	/*printf("Firm_02_state->count = %d\n", Firm_02_state->count);*/
	Firm_02_state->count = 0;

	/*printf("Firm_01_state->count = %d\n", Firm_01_state->count);*/
	Firm_01_state->count = 0;

	/*printf("Bank_06_state->count = %d\n", Bank_06_state->count);*/
	Bank_06_state->count = 0;

	/*printf("Bank_05_state->count = %d\n", Bank_05_state->count);*/
	Bank_05_state->count = 0;

	/*printf("Bank_04_state->count = %d\n", Bank_04_state->count);*/
	Bank_04_state->count = 0;

	/*printf("Bank_03_state->count = %d\n", Bank_03_state->count);*/
	Bank_03_state->count = 0;

	/*printf("Bank_02_state->count = %d\n", Bank_02_state->count);*/
	Bank_02_state->count = 0;

	/*printf("Bank_01_state->count = %d\n", Bank_01_state->count);*/
	Bank_01_state->count = 0;

	/*printf("Household_05_state->count = %d\n", Household_05_state->count);*/
	Household_05_state->count = 0;

	/*printf("Household_04_state->count = %d\n", Household_04_state->count);*/
	Household_04_state->count = 0;

	/*printf("Household_03_state->count = %d\n", Household_03_state->count);*/
	Household_03_state->count = 0;

	/*printf("Household_02_state->count = %d\n", Household_02_state->count);*/
	Household_02_state->count = 0;

	/*printf("Household_01_state->count = %d\n", Household_01_state->count);*/
	Household_01_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_Firm_holder = Firm_04_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		transition_Firm_agent(current_xmachine_Firm_holder, Firm_04_state, Firm_01_state);
	
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}

	current_xmachine_Bank_holder = Bank_06_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		transition_Bank_agent(current_xmachine_Bank_holder, Bank_06_state, Bank_01_state);
	
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}

	current_xmachine_Household_holder = Household_05_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		transition_Household_agent(current_xmachine_Household_holder, Household_05_state, Household_01_state);
	
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}


		/* Calculate if any agents need to jump S.P. */
		propagate_agents();
	/* Save iteration time to log file */

		file = fopen(logfilepath, "a");
		fputs("<iteration><no>", file);
		sprintf(data, "%i", iteration_loop);
		fputs(data, file);
		fputs("</no><time>", file);
        /* (lsc) Changed casting from "long" to "double"
         * In different systems, clock_t can be either integer or floating point. Casting to 
         * double ensures that arithmetic and printing operations work properly on all systems
         * regardless of underlying representation 
         */
		sprintf(data, "%ld", (long)(((double)clock()*time_ratio)-((double)interval*time_ratio)));
		fputs(data, file);
		fputs("</time></iteration>\n", file);
		fclose(file);

	}
	
	/* Stop timing and print total time */
	stop = clock();
    /* (lsc) Changed casting from "long" to "double"
     * In different systems, clock_t can be either integer or floating point. Casting to 
     * double ensures that arithmetic and printing operations work properly on all systems
     * regardless of underlying representation 
     */
	total_time = ((double)stop*time_ratio) - ((double)start*time_ratio);
	printf("Execution time - %ld:%02ld:%ld [mins:secs:msecs]\n", total_time/60000, ((total_time/1000)%60), total_time%1000);
	
	clean_up(0);
	rc = MB_Env_Finalise();
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not finalise MB environment\n");
       switch(rc) {
           case MB_ERR_ENV:
               fprintf(stderr, "\t reason: MB environment not yet started?\n");
               break;
       }
    }
    #endif
    
	/* Exit successfully by returning zero to Operating System */
	return 0;
}
