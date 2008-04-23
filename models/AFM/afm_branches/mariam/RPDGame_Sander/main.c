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
	//xmachine * temp_free_xmachine;
	//xmachine **agent_list;
	xmachine_memory_GamePlayer * temp_xmachine_GamePlayer;
	xmachine_memory_GameSolver * temp_xmachine_GameSolver;
	
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


	printf("FLAME Application: Iterated Prisoners Dilemma Game \n");





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

	
	current_xmachine_GamePlayer = *GamePlayer_01_state;
	while(current_xmachine_GamePlayer)
	{
		temp_xmachine_GamePlayer = current_xmachine_GamePlayer->next;
		
		
			i = post_my_strategy();
			
			if(i == 1)
			{
				free_GamePlayer_agent(current_xmachine_GamePlayer, GamePlayer_01_state);
			}
			else
			{
				transition_GamePlayer_agent(current_xmachine_GamePlayer, GamePlayer_01_state, GamePlayer_02_state);
			}
		
		
		current_xmachine_GamePlayer = temp_xmachine_GamePlayer;
	}

    rc = MB_SyncStart(b_strategy_i_use);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'strategy_i_use' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'strategy_i_use' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'strategy_i_use' board is locked\n");
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




	rc = MB_SyncComplete(b_strategy_i_use);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'strategy_i_use' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'strategy_i_use' board is invalid\n");
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
	
	
	rc = MB_Iterator_Create(b_strategy_i_use, &i_strategy_i_use);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'strategy_i_use'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'strategy_i_use' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'strategy_i_use' board is locked\n");
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
	
	current_xmachine_GameSolver = *GameSolver_01_state;
	while(current_xmachine_GameSolver)
	{
		temp_xmachine_GameSolver = current_xmachine_GameSolver->next;
		
		
			i = ipd_game_within_players();
			
			if(i == 1)
			{
				free_GameSolver_agent(current_xmachine_GameSolver, GameSolver_01_state);
			}
			else
			{
				transition_GameSolver_agent(current_xmachine_GameSolver, GameSolver_01_state, GameSolver_02_state);
			}
		
		
		current_xmachine_GameSolver = temp_xmachine_GameSolver;
	}


    rc = MB_Iterator_Delete(&i_strategy_i_use);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'strategy_i_use' iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'strategy_i_use' iterator is invalid\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif



	
	current_xmachine_GameSolver = *GameSolver_02_state;
	while(current_xmachine_GameSolver)
	{
		temp_xmachine_GameSolver = current_xmachine_GameSolver->next;
		
		
			i = actual_game();
			
			if(i == 1)
			{
				free_GameSolver_agent(current_xmachine_GameSolver, GameSolver_02_state);
			}
			else
			{
				transition_GameSolver_agent(current_xmachine_GameSolver, GameSolver_02_state, GameSolver_03_state);
			}
		
		
		current_xmachine_GameSolver = temp_xmachine_GameSolver;
	}




	
	current_xmachine_GameSolver = *GameSolver_03_state;
	while(current_xmachine_GameSolver)
	{
		temp_xmachine_GameSolver = current_xmachine_GameSolver->next;
		
		
			i = find_optimum_strategies();
			
			if(i == 1)
			{
				free_GameSolver_agent(current_xmachine_GameSolver, GameSolver_03_state);
			}
			else
			{
				transition_GameSolver_agent(current_xmachine_GameSolver, GameSolver_03_state, GameSolver_04_state);
			}
		
		
		current_xmachine_GameSolver = temp_xmachine_GameSolver;
	}




	
	current_xmachine_GameSolver = *GameSolver_04_state;
	while(current_xmachine_GameSolver)
	{
		temp_xmachine_GameSolver = current_xmachine_GameSolver->next;
		
		
			i = applyGA();
			
			if(i == 1)
			{
				free_GameSolver_agent(current_xmachine_GameSolver, GameSolver_04_state);
			}
			else
			{
				transition_GameSolver_agent(current_xmachine_GameSolver, GameSolver_04_state, GameSolver_05_state);
			}
		
		
		current_xmachine_GameSolver = temp_xmachine_GameSolver;
	}




	
	current_xmachine_GameSolver = *GameSolver_05_state;
	while(current_xmachine_GameSolver)
	{
		temp_xmachine_GameSolver = current_xmachine_GameSolver->next;
		
		
			i = update_strategies();
			
			if(i == 1)
			{
				free_GameSolver_agent(current_xmachine_GameSolver, GameSolver_05_state);
			}
			else
			{
				transition_GameSolver_agent(current_xmachine_GameSolver, GameSolver_05_state, GameSolver_06_state);
			}
		
		
		current_xmachine_GameSolver = temp_xmachine_GameSolver;
	}





    rc = MB_Clear(b_strategy_i_use);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'strategy_i_use' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'strategy_i_use' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'strategy_i_use' board is locked\n");
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
	/* Move agents to their start states */

	current_xmachine_GamePlayer = *GamePlayer_02_state;
	while(current_xmachine_GamePlayer)
	{
		temp_xmachine_GamePlayer = current_xmachine_GamePlayer->next;
		transition_GamePlayer_agent(current_xmachine_GamePlayer, GamePlayer_02_state, GamePlayer_01_state);
	
		current_xmachine_GamePlayer = temp_xmachine_GamePlayer;
	}

	current_xmachine_GameSolver = *GameSolver_06_state;
	while(current_xmachine_GameSolver)
	{
		temp_xmachine_GameSolver = current_xmachine_GameSolver->next;
		transition_GameSolver_agent(current_xmachine_GameSolver, GameSolver_06_state, GameSolver_01_state);
	
		current_xmachine_GameSolver = temp_xmachine_GameSolver;
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
