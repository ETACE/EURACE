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
	//xmachine_memory_Household * temp_xmachine_Household;
	//xmachine_memory_Firm * temp_xmachine_Firm;
	//xmachine_memory_Government * temp_xmachine_Government;
	//xmachine_memory_Central_Bank * temp_xmachine_Central_Bank;

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


	printf("FLAME Application: Government \n");





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
		fprintf(stdout, "Iteration - %d\n", iteration_loop);fflush(stdout);
		/* START OF ITERATION */


	current_xmachine_Government_holder = Government_start_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(Government_Government_send_policy_announcements_start_Government_01_condition(current_xmachine_Government))
		{

		

			i = Government_send_policy_announcements();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_start_Government_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_start_Government_state, Government_01_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}


    rc = MB_SyncStart(b_policy_announcement);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'policy_announcement' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_announcement' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
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



	current_xmachine_Government_holder = Government_start_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(Government_Government_idle_start_Government_01_condition(current_xmachine_Government))
		{

		

			i = Government_idle();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_start_Government_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_start_Government_state, Government_01_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}




	current_xmachine_Firm_holder = Firm_start_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_idle_start_Firm_01_condition(current_xmachine_Firm))
		{

		

			i = Firm_idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state, Firm_01_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	current_xmachine_Household_holder = Household_start_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(Household_Household_idle_start_Household_01_condition(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_start_Household_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_start_Household_state, Household_01_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}




	rc = MB_SyncComplete(b_policy_announcement);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'policy_announcement' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_announcement' board is invalid\n");
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
	

	current_xmachine_Firm_holder = Firm_start_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(Firm_Firm_read_policy_announcements_start_Firm_01_condition(current_xmachine_Firm))
		{

		
		
		rc = MB_Iterator_Create(b_policy_announcement, &i_policy_announcement);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'policy_announcement'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'policy_announcement' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
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
		MB_Iterator_Randomise(i_policy_announcement);
		

			i = Firm_read_policy_announcements();

		
		    rc = MB_Iterator_Delete(&i_policy_announcement);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'policy_announcement' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'policy_announcement' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state, Firm_01_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	current_xmachine_Household_holder = Household_start_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(Household_Household_read_policy_announcements_start_Household_01_condition(current_xmachine_Household))
		{

		
		
		rc = MB_Iterator_Create(b_policy_announcement, &i_policy_announcement);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'policy_announcement'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'policy_announcement' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
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
		MB_Iterator_Randomise(i_policy_announcement);
		

			i = Household_read_policy_announcements();

		
		    rc = MB_Iterator_Delete(&i_policy_announcement);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'policy_announcement' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'policy_announcement' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_start_Household_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_start_Household_state, Household_01_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}





	current_xmachine_Firm_holder = Firm_01_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_tax_payment();

		

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




	current_xmachine_Household_holder = Household_01_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_send_tax_payment();

		

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
	

	current_xmachine_Government_holder = Government_01_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		
		rc = MB_Iterator_CreateFiltered(b_tax_payment, &i_tax_payment, &Government_Government_read_tax_payments_tax_payment_filter, current_xmachine_Government);
		
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
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_tax_payment);
		

			i = Government_read_tax_payments();

		
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
		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_01_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_01_state, Government_02_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}




	current_xmachine_Firm_holder = Firm_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_subsidy_notification();

		

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


    rc = MB_SyncStart(b_firm_subsidy_notification);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'firm_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is locked\n");
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



	current_xmachine_Household_holder = Household_02_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_send_subsidy_notification();

		

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


    rc = MB_SyncStart(b_hh_subsidy_notification);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'hh_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is locked\n");
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



	rc = MB_SyncComplete(b_hh_subsidy_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'hh_subsidy_notification' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is invalid\n");
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
	
	rc = MB_SyncComplete(b_firm_subsidy_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'firm_subsidy_notification' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is invalid\n");
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
	

	current_xmachine_Government_holder = Government_02_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		
		rc = MB_Iterator_CreateFiltered(b_hh_subsidy_notification, &i_hh_subsidy_notification, &Government_Government_read_subsidy_notifications_hh_subsidy_notification_filter, current_xmachine_Government);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'hh_subsidy_notification'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is locked\n");
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
		MB_Iterator_Randomise(i_hh_subsidy_notification);
		
		rc = MB_Iterator_CreateFiltered(b_firm_subsidy_notification, &i_firm_subsidy_notification, &Government_Government_read_subsidy_notifications_firm_subsidy_notification_filter, current_xmachine_Government);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'firm_subsidy_notification'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is locked\n");
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
		MB_Iterator_Randomise(i_firm_subsidy_notification);
		

			i = Government_read_subsidy_notifications();

		
		    rc = MB_Iterator_Delete(&i_hh_subsidy_notification);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'hh_subsidy_notification' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'hh_subsidy_notification' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_firm_subsidy_notification);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'firm_subsidy_notification' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'firm_subsidy_notification' iterator is invalid\n");
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
				free_Government_agent(current_xmachine_Government_holder, Government_02_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_02_state, Government_03_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}




	current_xmachine_Firm_holder = Firm_03_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_end_Firm_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_transfer_notification();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_03_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_03_state, Firm_end_Firm_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_firm_transfer_notification);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'firm_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is locked\n");
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



	current_xmachine_Household_holder = Household_03_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_send_transfer_notification();

		

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


    rc = MB_SyncStart(b_hh_transfer_notification);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'hh_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is locked\n");
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



	rc = MB_SyncComplete(b_hh_transfer_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'hh_transfer_notification' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is invalid\n");
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
	
	rc = MB_SyncComplete(b_firm_transfer_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'firm_transfer_notification' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is invalid\n");
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
	

	current_xmachine_Government_holder = Government_03_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		
		rc = MB_Iterator_CreateFiltered(b_hh_transfer_notification, &i_hh_transfer_notification, &Government_Government_read_transfer_notifications_hh_transfer_notification_filter, current_xmachine_Government);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'hh_transfer_notification'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'hh_transfer_notification' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is locked\n");
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
		MB_Iterator_Randomise(i_hh_transfer_notification);
		
		rc = MB_Iterator_CreateFiltered(b_firm_transfer_notification, &i_firm_transfer_notification, &Government_Government_read_transfer_notifications_firm_transfer_notification_filter, current_xmachine_Government);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'firm_transfer_notification'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'firm_transfer_notification' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is locked\n");
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
		MB_Iterator_Randomise(i_firm_transfer_notification);
		

			i = Government_read_transfer_notifications();

		
		    rc = MB_Iterator_Delete(&i_hh_transfer_notification);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'hh_transfer_notification' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'hh_transfer_notification' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_firm_transfer_notification);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'firm_transfer_notification' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'firm_transfer_notification' iterator is invalid\n");
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
				free_Government_agent(current_xmachine_Government_holder, Government_03_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_03_state, Government_04_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}




	current_xmachine_Household_holder = Household_04_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_Household_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(Household_Household_send_unemployment_benefit_notification_04_end_Household_condition(current_xmachine_Household))
		{

		

			i = Household_send_unemployment_benefit_notification();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_04_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_04_state, Household_end_Household_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}


    rc = MB_SyncStart(b_unemployment_notification);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'unemployment_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_notification' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'unemployment_notification' board is locked\n");
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



	current_xmachine_Household_holder = Household_04_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_Household_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(Household_Household_idle_04_end_Household_condition(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_04_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_04_state, Household_end_Household_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}




	rc = MB_SyncComplete(b_unemployment_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'unemployment_notification' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_notification' board is invalid\n");
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
	

	current_xmachine_Government_holder = Government_04_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_Gov_Start_Monthly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		
		rc = MB_Iterator_CreateFiltered(b_unemployment_notification, &i_unemployment_notification, &Government_Government_read_unemployment_benefit_notifications_unemployment_notification_filter, current_xmachine_Government);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'unemployment_notification'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'unemployment_notification' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'unemployment_notification' board is locked\n");
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
		MB_Iterator_Randomise(i_unemployment_notification);
		

			i = Government_read_unemployment_benefit_notifications();

		
		    rc = MB_Iterator_Delete(&i_unemployment_notification);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'unemployment_notification' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'unemployment_notification' iterator is invalid\n");
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
				free_Government_agent(current_xmachine_Government_holder, Government_04_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_04_state, Government_Gov_Start_Monthly_Loop_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}





	current_xmachine_Government_holder = Government_Gov_Start_Monthly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(Government_Government_monthly_budget_accounting_Gov_Start_Monthly_Loop_05_condition(current_xmachine_Government))
		{

		

			i = Government_monthly_budget_accounting();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Monthly_Loop_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Monthly_Loop_state, Government_05_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}




	current_xmachine_Government_holder = Government_Gov_Start_Monthly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_Gov_Start_Yearly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(Government_Government_idle_Gov_Start_Monthly_Loop_Gov_Start_Yearly_Loop_condition(current_xmachine_Government))
		{

		

			i = Government_idle();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Monthly_Loop_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Monthly_Loop_state, Government_Gov_Start_Yearly_Loop_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}





	current_xmachine_Government_holder = Government_05_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		

			i = Government_monthly_resetting();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_05_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_05_state, Government_06_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}





	current_xmachine_Government_holder = Government_06_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_Gov_Start_Yearly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		

			i = Government_send_account_update();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_06_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_06_state, Government_Gov_Start_Yearly_Loop_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}


    rc = MB_SyncStart(b_central_bank_account_update);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'central_bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'central_bank_account_update' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'central_bank_account_update' board is locked\n");
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



	rc = MB_SyncComplete(b_central_bank_account_update);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'central_bank_account_update' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'central_bank_account_update' board is invalid\n");
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
	

	current_xmachine_Central_Bank_holder = Central_Bank_start_Central_Bank_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		current_xmachine_Central_Bank = current_xmachine_Central_Bank_holder->agent;
		current_xmachine_Central_Bank_next_state = Central_Bank_end_Central_Bank_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Central_Bank = current_xmachine_Central_Bank;

		

		
		
		rc = MB_Iterator_Create(b_central_bank_account_update, &i_central_bank_account_update);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'central_bank_account_update'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'central_bank_account_update' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'central_bank_account_update' board is locked\n");
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
		MB_Iterator_Randomise(i_central_bank_account_update);
		

			i = Central_Bank_read_account_update();

		
		    rc = MB_Iterator_Delete(&i_central_bank_account_update);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'central_bank_account_update' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'central_bank_account_update' iterator is invalid\n");
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
				free_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_start_Central_Bank_state);
			}
			else
			{
				transition_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_start_Central_Bank_state, Central_Bank_end_Central_Bank_state);
			}
		

		current_xmachine_Central_Bank = NULL;

		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
	}




	current_xmachine_Government_holder = Government_Gov_Start_Yearly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_07_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_07_condition(current_xmachine_Government))
		{

		

			i = Government_yearly_budget_accounting();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Yearly_Loop_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Yearly_Loop_state, Government_07_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}




	current_xmachine_Government_holder = Government_Gov_Start_Yearly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_end_Government_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(Government_idle_Gov_Start_Yearly_Loop_end_Government_condition(current_xmachine_Government))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Yearly_Loop_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Yearly_Loop_state, Government_end_Government_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}




	rc = MB_SyncComplete(b_data_for_government);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'data_for_government' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'data_for_government' board is invalid\n");
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
	

	current_xmachine_Government_holder = Government_07_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_08_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		
		
		rc = MB_Iterator_Create(b_data_for_government, &i_data_for_government);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'data_for_government'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'data_for_government' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'data_for_government' board is locked\n");
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
		MB_Iterator_Randomise(i_data_for_government);
		

			i = Government_read_data_from_Eurostat();

		
		    rc = MB_Iterator_Delete(&i_data_for_government);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'data_for_government' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'data_for_government' iterator is invalid\n");
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
				free_Government_agent(current_xmachine_Government_holder, Government_07_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_07_state, Government_08_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}





	current_xmachine_Government_holder = Government_08_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_09_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		

			i = Government_set_policy();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_08_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_08_state, Government_09_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}





	current_xmachine_Government_holder = Government_09_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_end_Government_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		

			i = Government_yearly_resetting();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_09_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_09_state, Government_end_Government_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}





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

	if(iteration_loop%output_frequency == output_offset)
	{
		saveiterationdata(iteration_loop);
	}

	/*printf("Household_end_Household_state->count = %d\n", Household_end_Household_state->count);*/
	Household_end_Household_state->count = 0;

	/*printf("Household_04_state->count = %d\n", Household_04_state->count);*/
	Household_04_state->count = 0;

	/*printf("Household_03_state->count = %d\n", Household_03_state->count);*/
	Household_03_state->count = 0;

	/*printf("Household_02_state->count = %d\n", Household_02_state->count);*/
	Household_02_state->count = 0;

	/*printf("Household_01_state->count = %d\n", Household_01_state->count);*/
	Household_01_state->count = 0;

	/*printf("Household_start_Household_state->count = %d\n", Household_start_Household_state->count);*/
	Household_start_Household_state->count = 0;

	/*printf("Firm_end_Firm_state->count = %d\n", Firm_end_Firm_state->count);*/
	Firm_end_Firm_state->count = 0;

	/*printf("Firm_03_state->count = %d\n", Firm_03_state->count);*/
	Firm_03_state->count = 0;

	/*printf("Firm_02_state->count = %d\n", Firm_02_state->count);*/
	Firm_02_state->count = 0;

	/*printf("Firm_01_state->count = %d\n", Firm_01_state->count);*/
	Firm_01_state->count = 0;

	/*printf("Firm_start_Firm_state->count = %d\n", Firm_start_Firm_state->count);*/
	Firm_start_Firm_state->count = 0;

	/*printf("Government_end_Government_state->count = %d\n", Government_end_Government_state->count);*/
	Government_end_Government_state->count = 0;

	/*printf("Government_09_state->count = %d\n", Government_09_state->count);*/
	Government_09_state->count = 0;

	/*printf("Government_08_state->count = %d\n", Government_08_state->count);*/
	Government_08_state->count = 0;

	/*printf("Government_07_state->count = %d\n", Government_07_state->count);*/
	Government_07_state->count = 0;

	/*printf("Government_06_state->count = %d\n", Government_06_state->count);*/
	Government_06_state->count = 0;

	/*printf("Government_05_state->count = %d\n", Government_05_state->count);*/
	Government_05_state->count = 0;

	/*printf("Government_Gov_Start_Yearly_Loop_state->count = %d\n", Government_Gov_Start_Yearly_Loop_state->count);*/
	Government_Gov_Start_Yearly_Loop_state->count = 0;

	/*printf("Government_Gov_Start_Monthly_Loop_state->count = %d\n", Government_Gov_Start_Monthly_Loop_state->count);*/
	Government_Gov_Start_Monthly_Loop_state->count = 0;

	/*printf("Government_04_state->count = %d\n", Government_04_state->count);*/
	Government_04_state->count = 0;

	/*printf("Government_03_state->count = %d\n", Government_03_state->count);*/
	Government_03_state->count = 0;

	/*printf("Government_02_state->count = %d\n", Government_02_state->count);*/
	Government_02_state->count = 0;

	/*printf("Government_01_state->count = %d\n", Government_01_state->count);*/
	Government_01_state->count = 0;

	/*printf("Government_start_Government_state->count = %d\n", Government_start_Government_state->count);*/
	Government_start_Government_state->count = 0;

	/*printf("Central_Bank_end_Central_Bank_state->count = %d\n", Central_Bank_end_Central_Bank_state->count);*/
	Central_Bank_end_Central_Bank_state->count = 0;

	/*printf("Central_Bank_start_Central_Bank_state->count = %d\n", Central_Bank_start_Central_Bank_state->count);*/
	Central_Bank_start_Central_Bank_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_Household_holder = Household_end_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		transition_Household_agent(current_xmachine_Household_holder, Household_end_Household_state, Household_start_Household_state);

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}

	current_xmachine_Firm_holder = Firm_end_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		transition_Firm_agent(current_xmachine_Firm_holder, Firm_end_Firm_state, Firm_start_Firm_state);

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}

	current_xmachine_Government_holder = Government_end_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		transition_Government_agent(current_xmachine_Government_holder, Government_end_Government_state, Government_start_Government_state);

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}

	current_xmachine_Central_Bank_holder = Central_Bank_end_Central_Bank_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		transition_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_end_Central_Bank_state, Central_Bank_start_Central_Bank_state);

		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
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
