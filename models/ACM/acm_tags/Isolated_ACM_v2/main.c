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
	double start, stop, interval;
	FILE *file;
	char data[100];
	char logfilepath[1000];
	char inputpath[1000];
	char * c;
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
	//xmachine_memory_Dummy * temp_xmachine_Dummy;

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
           default:
               fprintf(stderr, "\t MB_Env_Init returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }

	   
       exit(rc);

	}
	#endif

	/* Initialise pointers */
	initialise_pointers();
	p_iteration_number = &iteration_number;


	printf("FLAME Application: Eurace \n");





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
	lastd = -1;
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
				output_offset = 0;
				/* Find offset, seperated by the char '+' */
				c = strchr(argv[(i+1)], '+');
				if(c == NULL)
				{
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d\n", output_frequency);
				}
				else
				{
					output_offset = atoi(argv[(i+1)]+(c-argv[(i+1)])+1);
					argv[(i+1)][c-argv[(i+1)]] = 0;
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d with offset %d\n", output_frequency, output_offset);
				}

				if(output_frequency == 0)
				{
					printf("Output frequency cannot be zero\n");
					exit(0);
				}

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
       generate_partitions(cloud_data,totalnodes,partition_method);
       save_partition_data();






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

	/* print timer into */
	fputs("<!-- <time> unit: milliseconds -->\n", file);

	sprintf(data, "unspecified");
	
	fputs("<!-- <time> timer resolution: ", file);
	fputs(data, file);
	fputs(")-->\n", file);

	start = get_time();
	stop = get_time();
	sprintf(data, "%.2e ms", (stop - start) * 1000.0);
	fputs("<!-- <time> timer overhead: ~", file);
	fputs(data, file);
	fputs(")-->\n", file);


	fclose(file);

	/* Start timing */
	start = get_time();

    /* pre-randomise agents for first iteration */
    //randomisexagent();

	for(iteration_loop=iteration_number+1; iteration_loop < iteration_number+iteration_total+1; iteration_loop++)
	{
		interval = get_time();
		/* Print out iteration number */
		fprintf(stdout, "Iteration - %d\n", iteration_loop);
		/* START OF ITERATION */


	current_xmachine_Firm_holder = Firm_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Start_Firm_Credit_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_compute_total_liquidity_needs();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_02_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_02_state, Firm_Start_Firm_Credit_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}





	current_xmachine_Firm_holder = Firm_Start_Firm_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Start_Firm_Labour_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_idle_Start_Firm_Credit_Role_Start_Firm_Labour_Role_condition(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Start_Firm_Credit_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Start_Firm_Credit_Role_state, Firm_Start_Firm_Labour_Role_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	current_xmachine_Firm_holder = Firm_Start_Firm_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Credit_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_ask_loan_Start_Firm_Credit_Role_Firm_Credit_02_condition(current_xmachine_Firm))
		{

		

			i = Firm_ask_loan();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Start_Firm_Credit_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Start_Firm_Credit_Role_state, Firm_Firm_Credit_02_state);
			}
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif



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
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	

	current_xmachine_Bank_holder = Bank_Bank_start_credit_market_role_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		
		rc = MB_Iterator_CreateFiltered(b_loan_request, &i_loan_request, &Bank_Bank_decide_credit_conditions_loan_request_filter, current_xmachine_Bank);
		
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
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_loan_request);
		

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
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_start_credit_market_role_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_start_credit_market_role_state, Bank_Bank_02_state);
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif



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
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	

	current_xmachine_Firm_holder = Firm_Firm_Credit_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Credit_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		rc = MB_Iterator_CreateFiltered(b_loan_conditions, &i_loan_conditions, &Firm_Firm_get_loan_loan_conditions_filter, current_xmachine_Firm);
		
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
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_loan_conditions);
		

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
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Credit_02_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Credit_02_state, Firm_Firm_End_Credit_Role_state);
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif



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
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	

	current_xmachine_Bank_holder = Bank_Bank_02_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		
		rc = MB_Iterator_CreateFiltered(b_loan_acceptance, &i_loan_acceptance, &Bank_Bank_give_loan_loan_acceptance_filter, current_xmachine_Bank);
		
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
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_loan_acceptance);
		

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
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_02_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_02_state, Bank_Bank_03_state);
			}
		

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}




	current_xmachine_Firm_holder = Firm_Firm_End_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Start_Firm_Labour_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_idle_Firm_End_Credit_Role_Start_Firm_Labour_Role_condition(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Credit_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Credit_Role_state, Firm_Start_Firm_Labour_Role_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	current_xmachine_Firm_holder = Firm_Firm_End_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_0003_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_compute_and_send_stock_orders_Firm_End_Credit_Role_0003_condition(current_xmachine_Firm))
		{

		

			i = Firm_compute_and_send_stock_orders();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Credit_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Credit_Role_state, Firm_0003_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_order);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif



	rc = MB_SyncComplete(b_order);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'order' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	

	current_xmachine_Dummy_holder = Dummy_001_state->agents;
	while(current_xmachine_Dummy_holder)
	{
		temp_xmachine_Dummy_holder = current_xmachine_Dummy_holder->next;
		current_xmachine_Dummy = current_xmachine_Dummy_holder->agent;
		current_xmachine_Dummy_next_state = Dummy_002_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Dummy = current_xmachine_Dummy;

		

		
		
		rc = MB_Iterator_Create(b_order, &i_order);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'order'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'order' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'order' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_order);
		

			i = Function_read_send_order_messages();

		
		    rc = MB_Iterator_Delete(&i_order);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'order' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'order' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Dummy_agent(current_xmachine_Dummy_holder, Dummy_001_state);
			}
			else
			{
				transition_Dummy_agent(current_xmachine_Dummy_holder, Dummy_001_state, Dummy_002_state);
			}
		

		current_xmachine_Dummy = NULL;

		current_xmachine_Dummy_holder = temp_xmachine_Dummy_holder;
	}


    rc = MB_SyncStart(b_current_mall_stock_info);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'current_mall_stock_info' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

    rc = MB_SyncStart(b_order_status);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'order_status' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order_status' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order_status' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif



	rc = MB_SyncComplete(b_order_status);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'order_status' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order_status' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	

	current_xmachine_Firm_holder = Firm_0003_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_End_Firm_Financial_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		rc = MB_Iterator_CreateFiltered(b_order_status, &i_order_status, &Firm_Firm_read_stock_transactions_order_status_filter, current_xmachine_Firm);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'order_status'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'order_status' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'order_status' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_order_status);
		

			i = Firm_read_stock_transactions();

		
		    rc = MB_Iterator_Delete(&i_order_status);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'order_status' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'order_status' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_0003_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_0003_state, Firm_End_Firm_Financial_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}





	current_xmachine_Firm_holder = Firm_End_Firm_Financial_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_f1_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_check_financial_and_bankruptcy_state_End_Firm_Financial_Role_f1_condition(current_xmachine_Firm))
		{

		

			i = Firm_check_financial_and_bankruptcy_state();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_End_Firm_Financial_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_End_Firm_Financial_Role_state, Firm_f1_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	current_xmachine_Firm_holder = Firm_End_Firm_Financial_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_bankruptcy_checked_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_idle_End_Firm_Financial_Role_Firm_bankruptcy_checked_condition(current_xmachine_Firm))
		{

		

			i = Firm_idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_End_Firm_Financial_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_End_Firm_Financial_Role_state, Firm_Firm_bankruptcy_checked_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}





	current_xmachine_Firm_holder = Firm_f1_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_001_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_compute_financial_payments();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_f1_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_f1_state, Firm_001_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}





	current_xmachine_Firm_holder = Firm_001_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_002_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_compute_income_statement();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_001_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_001_state, Firm_002_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}





	current_xmachine_Firm_holder = Firm_002_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_003_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_compute_dividends();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_002_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_002_state, Firm_003_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}





	current_xmachine_Firm_holder = Firm_003_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_004_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_compute_total_financial_payments();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_003_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_003_state, Firm_004_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	rc = MB_SyncComplete(b_current_mall_stock_info);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'current_mall_stock_info' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	

	current_xmachine_Firm_holder = Firm_004_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_bankruptcy_checked_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		rc = MB_Iterator_CreateFiltered(b_current_mall_stock_info, &i_current_mall_stock_info, &Firm_Firm_compute_balance_sheet_current_mall_stock_info_filter, current_xmachine_Firm);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'current_mall_stock_info'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'current_mall_stock_info' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_current_mall_stock_info);
		

			i = Firm_compute_balance_sheet();

		
		    rc = MB_Iterator_Delete(&i_current_mall_stock_info);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'current_mall_stock_info' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'current_mall_stock_info' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_004_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_004_state, Firm_Firm_bankruptcy_checked_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}





	current_xmachine_Firm_holder = Firm_Firm_bankruptcy_checked_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_not_in_bankruptcy_state_now_check_financial_crisis_condition(current_xmachine_Firm))
		{

		

			i = Firm_not_in_bankruptcy();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankruptcy_checked_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankruptcy_checked_state, Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	current_xmachine_Firm_holder = Firm_Firm_bankruptcy_checked_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_end_Firm_dies_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_in_bankruptcy_Firm_bankruptcy_checked_end_Firm_dies_condition(current_xmachine_Firm))
		{

		

			i = Firm_in_bankruptcy();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankruptcy_checked_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankruptcy_checked_state, Firm_end_Firm_dies_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif




	current_xmachine_Firm_holder = Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_financial_crisis_ok_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_idle_Firm_not_in_bankruptcy_state_now_check_financial_crisis_Firm_financial_crisis_ok_condition(current_xmachine_Firm))
		{

		

			i = Firm_idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state, Firm_Firm_financial_crisis_ok_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	current_xmachine_Firm_holder = Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_financial_crisis_ok_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_in_financial_crisis_function_Firm_not_in_bankruptcy_state_now_check_financial_crisis_Firm_financial_crisis_ok_condition(current_xmachine_Firm))
		{

		

			i = Firm_in_financial_crisis_function();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state, Firm_Firm_financial_crisis_ok_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	current_xmachine_Firm_holder = Firm_end_Firm_dies_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_end_Firm_cycle_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_generate_new_firm();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_end_Firm_dies_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_end_Firm_dies_state, Firm_end_Firm_cycle_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}





	current_xmachine_Firm_holder = Firm_Firm_financial_crisis_ok_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Start_Firm_Labour_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_execute_financial_payments_function();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_financial_crisis_ok_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_financial_crisis_ok_state, Firm_Start_Firm_Labour_Role_state);
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

    rc = MB_SyncStart(b_tax_payment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'tax_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'tax_payment' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

    rc = MB_SyncStart(b_dividend_per_share);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'dividend_per_share' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_per_share' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'dividend_per_share' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif



	rc = MB_SyncComplete(b_tax_payment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'tax_payment' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_payment' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	
	rc = MB_SyncComplete(b_dividend_per_share);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'dividend_per_share' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_per_share' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	

	current_xmachine_Dummy_holder = Dummy_002_state->agents;
	while(current_xmachine_Dummy_holder)
	{
		temp_xmachine_Dummy_holder = current_xmachine_Dummy_holder->next;
		current_xmachine_Dummy = current_xmachine_Dummy_holder->agent;
		current_xmachine_Dummy_next_state = Dummy_003_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Dummy = current_xmachine_Dummy;

		

		
		
		rc = MB_Iterator_Create(b_tax_payment, &i_tax_payment);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'tax_payment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'tax_payment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'tax_payment' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_tax_payment);
		
		
		rc = MB_Iterator_Create(b_dividend_per_share, &i_dividend_per_share);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'dividend_per_share'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'dividend_per_share' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'dividend_per_share' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_dividend_per_share);
		

			i = Function_read_send_bank_messages();

		
		    rc = MB_Iterator_Delete(&i_tax_payment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'tax_payment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'tax_payment' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_dividend_per_share);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'dividend_per_share' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'dividend_per_share' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Dummy_agent(current_xmachine_Dummy_holder, Dummy_002_state);
			}
			else
			{
				transition_Dummy_agent(current_xmachine_Dummy_holder, Dummy_002_state, Dummy_003_state);
			}
		

		current_xmachine_Dummy = NULL;

		current_xmachine_Dummy_holder = temp_xmachine_Dummy_holder;
	}


    rc = MB_SyncStart(b_bank_account_update);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_account_update' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_account_update' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


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
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
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
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	

	current_xmachine_Bank_holder = Bank_Bank_03_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		
		rc = MB_Iterator_CreateFiltered(b_installment, &i_installment, &Bank_Bank_receive_installment_installment_filter, current_xmachine_Bank);
		
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
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_installment);
		
		rc = MB_Iterator_CreateFiltered(b_bankruptcy, &i_bankruptcy, &Bank_Bank_receive_installment_bankruptcy_filter, current_xmachine_Bank);
		
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
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_bankruptcy);
		

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
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
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
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_03_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_03_state, Bank_Bank_04_state);
			}
		

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}




	rc = MB_SyncComplete(b_bank_account_update);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'bank_account_update' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_account_update' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
	

	current_xmachine_Bank_holder = Bank_Bank_04_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		
		rc = MB_Iterator_CreateFiltered(b_bank_account_update, &i_bank_account_update, &Bank_Bank_account_update_deposits_bank_account_update_filter, current_xmachine_Bank);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bank_account_update'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bank_account_update' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bank_account_update' board is locked\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_bank_account_update);
		

			i = Bank_account_update_deposits();

		
		    rc = MB_Iterator_Delete(&i_bank_account_update);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bank_account_update' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bank_account_update' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_04_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_04_state, Bank_Bank_05_state);
			}
		

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}





	current_xmachine_Bank_holder = Bank_Bank_05_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_end_Bank_cycle_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		if(Bank_Bank_idle_Bank_05_end_Bank_cycle_condition(current_xmachine_Bank))
		{

		

			i = Bank_idle();

		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_05_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_05_state, Bank_end_Bank_cycle_state);
			}
		}

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}




	current_xmachine_Bank_holder = Bank_Bank_05_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_end_Bank_cycle_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Dummy = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		if(Bank_Bank_accounting_Bank_05_end_Bank_cycle_condition(current_xmachine_Bank))
		{

		

			i = Bank_accounting();

		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_05_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_05_state, Bank_end_Bank_cycle_state);
			}
		}

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}





    rc = MB_Clear(b_bank_account_update);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_account_update' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_account_update' board is locked\n");
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
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
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
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
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
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
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
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
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
           default:
               fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

    rc = MB_Clear(b_BCE_return);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'BCE_return' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'BCE_return' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'BCE_return' board is locked\n");
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

    rc = MB_Clear(b_dividend_per_share);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'dividend_per_share' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_per_share' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'dividend_per_share' board is locked\n");
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

    rc = MB_Clear(b_current_mall_stock_info);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'current_mall_stock_info' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is locked\n");
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

    rc = MB_Clear(b_order);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order' board is locked\n");
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

    rc = MB_Clear(b_order_status);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'order_status' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order_status' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order_status' board is locked\n");
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

	if(iteration_loop%output_frequency == output_offset)
	{
		saveiterationdata(iteration_loop);
	}

	/*printf("Firm_Start_Firm_Labour_Role_state->count = %d\n", Firm_Start_Firm_Labour_Role_state->count);*/
	Firm_Start_Firm_Labour_Role_state->count = 0;

	/*printf("Firm_Firm_financial_crisis_ok_state->count = %d\n", Firm_Firm_financial_crisis_ok_state->count);*/
	Firm_Firm_financial_crisis_ok_state->count = 0;

	/*printf("Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state->count = %d\n", Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state->count);*/
	Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state->count = 0;

	/*printf("Firm_end_Firm_cycle_state->count = %d\n", Firm_end_Firm_cycle_state->count);*/
	Firm_end_Firm_cycle_state->count = 0;

	/*printf("Firm_end_Firm_dies_state->count = %d\n", Firm_end_Firm_dies_state->count);*/
	Firm_end_Firm_dies_state->count = 0;

	/*printf("Firm_0003_state->count = %d\n", Firm_0003_state->count);*/
	Firm_0003_state->count = 0;

	/*printf("Firm_02_state->count = %d\n", Firm_02_state->count);*/
	Firm_02_state->count = 0;

	/*printf("Firm_Firm_bankruptcy_checked_state->count = %d\n", Firm_Firm_bankruptcy_checked_state->count);*/
	Firm_Firm_bankruptcy_checked_state->count = 0;

	/*printf("Firm_End_Firm_Financial_Role_state->count = %d\n", Firm_End_Firm_Financial_Role_state->count);*/
	Firm_End_Firm_Financial_Role_state->count = 0;

	/*printf("Firm_004_state->count = %d\n", Firm_004_state->count);*/
	Firm_004_state->count = 0;

	/*printf("Firm_003_state->count = %d\n", Firm_003_state->count);*/
	Firm_003_state->count = 0;

	/*printf("Firm_002_state->count = %d\n", Firm_002_state->count);*/
	Firm_002_state->count = 0;

	/*printf("Firm_001_state->count = %d\n", Firm_001_state->count);*/
	Firm_001_state->count = 0;

	/*printf("Firm_f1_state->count = %d\n", Firm_f1_state->count);*/
	Firm_f1_state->count = 0;

	/*printf("Firm_Firm_End_Credit_Role_state->count = %d\n", Firm_Firm_End_Credit_Role_state->count);*/
	Firm_Firm_End_Credit_Role_state->count = 0;

	/*printf("Firm_Firm_Credit_02_state->count = %d\n", Firm_Firm_Credit_02_state->count);*/
	Firm_Firm_Credit_02_state->count = 0;

	/*printf("Firm_Start_Firm_Credit_Role_state->count = %d\n", Firm_Start_Firm_Credit_Role_state->count);*/
	Firm_Start_Firm_Credit_Role_state->count = 0;

	/*printf("Bank_end_Bank_cycle_state->count = %d\n", Bank_end_Bank_cycle_state->count);*/
	Bank_end_Bank_cycle_state->count = 0;

	/*printf("Bank_Bank_05_state->count = %d\n", Bank_Bank_05_state->count);*/
	Bank_Bank_05_state->count = 0;

	/*printf("Bank_Bank_04_state->count = %d\n", Bank_Bank_04_state->count);*/
	Bank_Bank_04_state->count = 0;

	/*printf("Bank_Bank_03_state->count = %d\n", Bank_Bank_03_state->count);*/
	Bank_Bank_03_state->count = 0;

	/*printf("Bank_Bank_02_state->count = %d\n", Bank_Bank_02_state->count);*/
	Bank_Bank_02_state->count = 0;

	/*printf("Bank_Bank_start_credit_market_role_state->count = %d\n", Bank_Bank_start_credit_market_role_state->count);*/
	Bank_Bank_start_credit_market_role_state->count = 0;

	/*printf("Dummy_003_state->count = %d\n", Dummy_003_state->count);*/
	Dummy_003_state->count = 0;

	/*printf("Dummy_002_state->count = %d\n", Dummy_002_state->count);*/
	Dummy_002_state->count = 0;

	/*printf("Dummy_001_state->count = %d\n", Dummy_001_state->count);*/
	Dummy_001_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_Firm_holder = Firm_end_Firm_cycle_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		transition_Firm_agent(current_xmachine_Firm_holder, Firm_end_Firm_cycle_state, Firm_02_state);

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}

	current_xmachine_Firm_holder = Firm_Start_Firm_Labour_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		transition_Firm_agent(current_xmachine_Firm_holder, Firm_Start_Firm_Labour_Role_state, Firm_02_state);

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}

	current_xmachine_Bank_holder = Bank_end_Bank_cycle_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		transition_Bank_agent(current_xmachine_Bank_holder, Bank_end_Bank_cycle_state, Bank_Bank_start_credit_market_role_state);

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}

	current_xmachine_Dummy_holder = Dummy_003_state->agents;
	while(current_xmachine_Dummy_holder)
	{
		temp_xmachine_Dummy_holder = current_xmachine_Dummy_holder->next;
		transition_Dummy_agent(current_xmachine_Dummy_holder, Dummy_003_state, Dummy_001_state);

		current_xmachine_Dummy_holder = temp_xmachine_Dummy_holder;
	}


		/* Calculate if any agents need to jump S.P. */
		/* propagate_agents(); */
	/* Save iteration time to log file */

		file = fopen(logfilepath, "a");
		fputs("<iteration><no>", file);
		sprintf(data, "%i", iteration_loop);
		fputs(data, file);
		fputs("</no><time>", file);
		sprintf(data, "%d", (int)((get_time() - interval) * 1000) );
		fputs(data, file);
		fputs("</time></iteration>\n", file);
		fclose(file);

	}

	/* Stop timing and print total time */
	stop = get_time();
	total_time = stop - start;
	printf("Execution time - %d:%02d:%03d [mins:secs:msecs]\n",
       (int)(total_time/60), ((int)total_time)%60, (((int)(total_time * 1000.0)) % 1000));

	clean_up(0);

	/* Exit successfully by returning zero to Operating System */
	return 0;
}
