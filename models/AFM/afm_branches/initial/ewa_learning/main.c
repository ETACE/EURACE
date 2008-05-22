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
	//xmachine_memory_Household * temp_xmachine_Household;
	//xmachine_memory_FinancialAgent * temp_xmachine_FinancialAgent;
	
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


	printf("FLAME Application: Financial Market Model - EWA \n");





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

	
	current_xmachine_FinancialAgent_holder = FinancialAgent_start_FinancialAgent_state->agents;
	while(current_xmachine_FinancialAgent_holder)
	{
		temp_xmachine_FinancialAgent_holder = current_xmachine_FinancialAgent_holder->next;
		current_xmachine_FinancialAgent = current_xmachine_FinancialAgent_holder->agent;
		current_xmachine_FinancialAgent_next_state = FinancialAgent_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_FinancialAgent = current_xmachine_FinancialAgent;
		
		if(FinancialAgent_FinancialAgent_apply_GA_start_FinancialAgent_01_condition(current_xmachine_FinancialAgent))
		{
		
		
		
			i = FinancialAgent_apply_GA();
			
		
		
			if(i == 1)
			{
				free_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_start_FinancialAgent_state);
			}
			else
			{
				transition_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_start_FinancialAgent_state, FinancialAgent_01_state);
			}
		}
		
		current_xmachine_FinancialAgent = NULL;
		
		current_xmachine_FinancialAgent_holder = temp_xmachine_FinancialAgent_holder;
	}



	
	current_xmachine_FinancialAgent_holder = FinancialAgent_start_FinancialAgent_state->agents;
	while(current_xmachine_FinancialAgent_holder)
	{
		temp_xmachine_FinancialAgent_holder = current_xmachine_FinancialAgent_holder->next;
		current_xmachine_FinancialAgent = current_xmachine_FinancialAgent_holder->agent;
		current_xmachine_FinancialAgent_next_state = FinancialAgent_end_GA_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_FinancialAgent = current_xmachine_FinancialAgent;
		
		if(FinancialAgent_idle_start_FinancialAgent_end_GA_condition(current_xmachine_FinancialAgent))
		{
		
		
		
			i = idle();
			
		
		
			if(i == 1)
			{
				free_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_start_FinancialAgent_state);
			}
			else
			{
				transition_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_start_FinancialAgent_state, FinancialAgent_end_GA_state);
			}
		}
		
		current_xmachine_FinancialAgent = NULL;
		
		current_xmachine_FinancialAgent_holder = temp_xmachine_FinancialAgent_holder;
	}



	
	current_xmachine_Household_holder = Household_start_Household_EWA_Learning_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_reset_private_classifiersystem_start_Household_EWA_Learning_01_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_reset_private_classifiersystem();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_start_Household_EWA_Learning_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_start_Household_EWA_Learning_state, Household_01_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	
	current_xmachine_Household_holder = Household_start_Household_EWA_Learning_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_GA_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_idle_start_Household_EWA_Learning_end_GA_condition(current_xmachine_Household))
		{
		
		
		
			i = idle();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_start_Household_EWA_Learning_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_start_Household_EWA_Learning_state, Household_end_GA_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}




	
	current_xmachine_FinancialAgent_holder = FinancialAgent_01_state->agents;
	while(current_xmachine_FinancialAgent_holder)
	{
		temp_xmachine_FinancialAgent_holder = current_xmachine_FinancialAgent_holder->next;
		current_xmachine_FinancialAgent = current_xmachine_FinancialAgent_holder->agent;
		current_xmachine_FinancialAgent_next_state = FinancialAgent_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_FinancialAgent = current_xmachine_FinancialAgent;
		
		
		
		
		
			i = FinancialAgent_reset_public_classifiersystem();
			
		
		
			if(i == 1)
			{
				free_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_01_state);
			}
			else
			{
				transition_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_01_state, FinancialAgent_02_state);
			}
		
		
		current_xmachine_FinancialAgent = NULL;
		
		current_xmachine_FinancialAgent_holder = temp_xmachine_FinancialAgent_holder;
	}




	
	current_xmachine_FinancialAgent_holder = FinancialAgent_02_state->agents;
	while(current_xmachine_FinancialAgent_holder)
	{
		temp_xmachine_FinancialAgent_holder = current_xmachine_FinancialAgent_holder->next;
		current_xmachine_FinancialAgent = current_xmachine_FinancialAgent_holder->agent;
		current_xmachine_FinancialAgent_next_state = FinancialAgent_end_GA_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_FinancialAgent = current_xmachine_FinancialAgent;
		
		
		
		
		
			i = FinancialAgent_send_rule_details();
			
		
		
			if(i == 1)
			{
				free_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_02_state);
			}
			else
			{
				transition_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_02_state, FinancialAgent_end_GA_state);
			}
		
		
		current_xmachine_FinancialAgent = NULL;
		
		current_xmachine_FinancialAgent_holder = temp_xmachine_FinancialAgent_holder;
	}


    rc = MB_SyncStart(b_rule_details);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'rule_details' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_details' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'rule_details' board is locked\n");
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



	
	current_xmachine_FinancialAgent_holder = FinancialAgent_end_GA_state->agents;
	while(current_xmachine_FinancialAgent_holder)
	{
		temp_xmachine_FinancialAgent_holder = current_xmachine_FinancialAgent_holder->next;
		current_xmachine_FinancialAgent = current_xmachine_FinancialAgent_holder->agent;
		current_xmachine_FinancialAgent_next_state = FinancialAgent_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_FinancialAgent = current_xmachine_FinancialAgent;
		
		
		
		
		
			i = FinancialAgent_reset_public_classifiersystem();
			
		
		
			if(i == 1)
			{
				free_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_end_GA_state);
			}
			else
			{
				transition_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_end_GA_state, FinancialAgent_03_state);
			}
		
		
		current_xmachine_FinancialAgent = NULL;
		
		current_xmachine_FinancialAgent_holder = temp_xmachine_FinancialAgent_holder;
	}



	rc = MB_SyncComplete(b_rule_details);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'rule_details' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_details' board is invalid\n");
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
	
	
	current_xmachine_Household_holder = Household_01_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_GA_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
		rc = MB_Iterator_Create(b_rule_details, &i_rule_details);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'rule_details'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'rule_details' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'rule_details' board is locked\n");
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
		
		
			i = Household_read_and_update_rule_details();
			
		
		    rc = MB_Iterator_Delete(&i_rule_details);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'rule_details' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'rule_details' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_01_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01_state, Household_end_GA_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}




	
	current_xmachine_Household_holder = Household_end_GA_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_send_rule_performance_end_GA_02_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_send_rule_performance();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_end_GA_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_end_GA_state, Household_02_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}


    rc = MB_SyncStart(b_rule_performance);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'rule_performance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_performance' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'rule_performance' board is locked\n");
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


	
	current_xmachine_Household_holder = Household_end_GA_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_Household_EWA_Learning_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_idle_end_GA_end_Household_EWA_Learning_condition(current_xmachine_Household))
		{
		
		
		
			i = idle();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_end_GA_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_end_GA_state, Household_end_Household_EWA_Learning_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}




	rc = MB_SyncComplete(b_rule_performance);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'rule_performance' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_performance' board is invalid\n");
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
	
	
	current_xmachine_FinancialAgent_holder = FinancialAgent_03_state->agents;
	while(current_xmachine_FinancialAgent_holder)
	{
		temp_xmachine_FinancialAgent_holder = current_xmachine_FinancialAgent_holder->next;
		current_xmachine_FinancialAgent = current_xmachine_FinancialAgent_holder->agent;
		current_xmachine_FinancialAgent_next_state = FinancialAgent_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_FinancialAgent = current_xmachine_FinancialAgent;
		
		
		
		
		
		rc = MB_Iterator_Create(b_rule_performance, &i_rule_performance);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'rule_performance'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'rule_performance' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'rule_performance' board is locked\n");
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
		
		
			i = FinancialAgent_read_rule_performance_and_update_classifiersystem();
			
		
		    rc = MB_Iterator_Delete(&i_rule_performance);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'rule_performance' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'rule_performance' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_03_state);
			}
			else
			{
				transition_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_03_state, FinancialAgent_04_state);
			}
		
		
		current_xmachine_FinancialAgent = NULL;
		
		current_xmachine_FinancialAgent_holder = temp_xmachine_FinancialAgent_holder;
	}




	
	current_xmachine_FinancialAgent_holder = FinancialAgent_04_state->agents;
	while(current_xmachine_FinancialAgent_holder)
	{
		temp_xmachine_FinancialAgent_holder = current_xmachine_FinancialAgent_holder->next;
		current_xmachine_FinancialAgent = current_xmachine_FinancialAgent_holder->agent;
		current_xmachine_FinancialAgent_next_state = FinancialAgent_end_FinancialAgent_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_FinancialAgent = current_xmachine_FinancialAgent;
		
		
		
		
		
			i = FinancialAgent_send_all_performances();
			
		
		
			if(i == 1)
			{
				free_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_04_state);
			}
			else
			{
				transition_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_04_state, FinancialAgent_end_FinancialAgent_state);
			}
		
		
		current_xmachine_FinancialAgent = NULL;
		
		current_xmachine_FinancialAgent_holder = temp_xmachine_FinancialAgent_holder;
	}


    rc = MB_SyncStart(b_new_performances);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'new_performances' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_performances' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'new_performances' board is locked\n");
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



	rc = MB_SyncComplete(b_new_performances);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'new_performances' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_performances' board is invalid\n");
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
		rc = MB_Iterator_Create(b_new_performances, &i_new_performances);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'new_performances'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'new_performances' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'new_performances' board is locked\n");
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
		
		
			i = Household_read_all_performances();
			
		
		    rc = MB_Iterator_Delete(&i_new_performances);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'new_performances' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'new_performances' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
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




	
	current_xmachine_Household_holder = Household_03_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_Household_EWA_Learning_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_FinancialAgent = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
			i = Household_select_rule();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_03_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_03_state, Household_end_Household_EWA_Learning_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}





    rc = MB_Clear(b_rule_performance);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'rule_performance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_performance' board is invalid\n");
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

    rc = MB_Clear(b_new_performances);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'new_performances' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_performances' board is invalid\n");
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

    rc = MB_Clear(b_rule_details);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'rule_details' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_details' board is invalid\n");
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

	if(iteration_loop%output_frequency == 0)
	{
		saveiterationdata(iteration_loop);
	}

	/*printf("Household_03_state->count = %d\n", Household_03_state->count);*/
	Household_03_state->count = 0;

	/*printf("Household_02_state->count = %d\n", Household_02_state->count);*/
	Household_02_state->count = 0;

	/*printf("Household_end_Household_EWA_Learning_state->count = %d\n", Household_end_Household_EWA_Learning_state->count);*/
	Household_end_Household_EWA_Learning_state->count = 0;

	/*printf("Household_01_state->count = %d\n", Household_01_state->count);*/
	Household_01_state->count = 0;

	/*printf("Household_end_GA_state->count = %d\n", Household_end_GA_state->count);*/
	Household_end_GA_state->count = 0;

	/*printf("Household_start_Household_EWA_Learning_state->count = %d\n", Household_start_Household_EWA_Learning_state->count);*/
	Household_start_Household_EWA_Learning_state->count = 0;

	/*printf("FinancialAgent_end_FinancialAgent_state->count = %d\n", FinancialAgent_end_FinancialAgent_state->count);*/
	FinancialAgent_end_FinancialAgent_state->count = 0;

	/*printf("FinancialAgent_04_state->count = %d\n", FinancialAgent_04_state->count);*/
	FinancialAgent_04_state->count = 0;

	/*printf("FinancialAgent_03_state->count = %d\n", FinancialAgent_03_state->count);*/
	FinancialAgent_03_state->count = 0;

	/*printf("FinancialAgent_02_state->count = %d\n", FinancialAgent_02_state->count);*/
	FinancialAgent_02_state->count = 0;

	/*printf("FinancialAgent_01_state->count = %d\n", FinancialAgent_01_state->count);*/
	FinancialAgent_01_state->count = 0;

	/*printf("FinancialAgent_end_GA_state->count = %d\n", FinancialAgent_end_GA_state->count);*/
	FinancialAgent_end_GA_state->count = 0;

	/*printf("FinancialAgent_start_FinancialAgent_state->count = %d\n", FinancialAgent_start_FinancialAgent_state->count);*/
	FinancialAgent_start_FinancialAgent_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_Household_holder = Household_end_Household_EWA_Learning_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		transition_Household_agent(current_xmachine_Household_holder, Household_end_Household_EWA_Learning_state, Household_start_Household_EWA_Learning_state);
	
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}

	current_xmachine_FinancialAgent_holder = FinancialAgent_end_FinancialAgent_state->agents;
	while(current_xmachine_FinancialAgent_holder)
	{
		temp_xmachine_FinancialAgent_holder = current_xmachine_FinancialAgent_holder->next;
		transition_FinancialAgent_agent(current_xmachine_FinancialAgent_holder, FinancialAgent_end_FinancialAgent_state, FinancialAgent_start_FinancialAgent_state);
	
		current_xmachine_FinancialAgent_holder = temp_xmachine_FinancialAgent_holder;
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
