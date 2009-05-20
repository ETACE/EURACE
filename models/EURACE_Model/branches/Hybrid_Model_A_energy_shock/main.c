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
	//xmachine_memory_Household * temp_xmachine_Household;
	//xmachine_memory_Mall * temp_xmachine_Mall;
	//xmachine_memory_IGFirm * temp_xmachine_IGFirm;
	//xmachine_memory_Eurostat * temp_xmachine_Eurostat;
	//xmachine_memory_Bank * temp_xmachine_Bank;
	//xmachine_memory_Government * temp_xmachine_Government;
	//xmachine_memory_Central_Bank * temp_xmachine_Central_Bank;
	//xmachine_memory_Clearinghouse * temp_xmachine_Clearinghouse;

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
/*printf("Initial states: %s\n", inputpath);*/

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
/*printf("Ouput dir: %s\n", outputpath);*/


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
				/* Find offset, separated by the char '+' */
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
       readinitialstates(inputpath, outputpath, p_iteration_number, cloud_data, partition_method, 0);
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
		/* Flush stdout to keep user updated on progress */
		fflush(stdout);
		
		/* START OF ITERATION */

	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_send_policy_announcements\n");
	current_xmachine_Government_holder = Government_start_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_Gov_Start_Bond_Market_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(FLAME_condition_Government_Government_send_policy_announcements_start_Government_Gov_Start_Bond_Market(current_xmachine_Government))
		{

		

			i = Government_send_policy_announcements();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_start_Government_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_start_Government_state, Government_Gov_Start_Bond_Market_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_send_policy_announcements\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_send_data\n");
	current_xmachine_Eurostat_holder = Eurostat_start_Eurostat_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_send_data_start_Eurostat_01(current_xmachine_Eurostat))
		{

		

			i = Eurostat_send_data();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_start_Eurostat_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_start_Eurostat_state, Eurostat_01_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_send_data\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start ClearingHouse_receive_info_dummy\n");
	current_xmachine_Clearinghouse_holder = Clearinghouse_start_Clearinghouse_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		current_xmachine_Clearinghouse = current_xmachine_Clearinghouse_holder->agent;
		current_xmachine_Clearinghouse_next_state = Clearinghouse_RECEIVEDINFOSTOCK_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Clearinghouse = current_xmachine_Clearinghouse;

		

		

			i = ClearingHouse_receive_info_dummy();

		

			if(i == 1)
			{
				free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_start_Clearinghouse_state);
			}
			else
			{
				transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_start_Clearinghouse_state, Clearinghouse_RECEIVEDINFOSTOCK_state);
			}
		

		current_xmachine_Clearinghouse = NULL;

		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish ClearingHouse_receive_info_dummy\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_idle\n");
	current_xmachine_Government_holder = Government_start_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_Gov_Start_Bond_Market_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(FLAME_condition_Government_Government_idle_start_Government_Gov_Start_Bond_Market(current_xmachine_Government))
		{

		

			i = Government_idle();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_start_Government_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_start_Government_state, Government_Gov_Start_Bond_Market_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Bank_holder = Bank_start_Bank_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_start_credit_market_role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		if(FLAME_condition_Bank_idle_start_Bank_Bank_start_credit_market_role(current_xmachine_Bank))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_start_Bank_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_start_Bank_state, Bank_Bank_start_credit_market_role_state);
			}
		}

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_idle\n");
	current_xmachine_Eurostat_holder = Eurostat_start_Eurostat_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_idle_start_Eurostat_01(current_xmachine_Eurostat))
		{

		

			i = Eurostat_idle();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_start_Eurostat_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_start_Eurostat_state, Eurostat_01_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_idle\n");
	current_xmachine_IGFirm_holder = IGFirm_start_IGFirm_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_Start_IGFirm_Productivity_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		if(FLAME_condition_IGFirm_IGFirm_idle_start_IGFirm_Start_IGFirm_Productivity(current_xmachine_IGFirm))
		{

		

			i = IGFirm_idle();

		

			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_start_IGFirm_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_start_IGFirm_state, IGFirm_Start_IGFirm_Productivity_state);
			}
		}

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Mall_holder = Mall_start_Mall_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		if(FLAME_condition_Mall_idle_start_Mall_01(current_xmachine_Mall))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Mall_agent(current_xmachine_Mall_holder, Mall_start_Mall_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_start_Mall_state, Mall_01_state);
			}
		}

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Mall_reset_export_data\n");
	current_xmachine_Mall_holder = Mall_start_Mall_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		if(FLAME_condition_Mall_Mall_reset_export_data_start_Mall_01(current_xmachine_Mall))
		{

		

			i = Mall_reset_export_data();

		

			if(i == 1)
			{
				free_Mall_agent(current_xmachine_Mall_holder, Mall_start_Mall_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_start_Mall_state, Mall_01_state);
			}
		}

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Mall_reset_export_data\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_start_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_Household_Start_Policy_Data_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_start_Household_Household_Start_Policy_Data(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_start_Household_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_start_Household_state, Household_Household_Start_Policy_Data_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_start_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_is_active_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_start_Firm_Firm_is_active(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state, Firm_Firm_is_active_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_policy_announcement_1();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_policy_announcement)\n");
    rc = MB_SyncStart(b_policy_announcement);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_policy_announcement)\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_bankruptcy_idle_counter\n");
	current_xmachine_Firm_holder = Firm_start_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_not_active_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_bankruptcy_idle_counter_start_Firm_Firm_not_active(current_xmachine_Firm))
		{

		

			i = Firm_bankruptcy_idle_counter();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state, Firm_Firm_not_active_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_bankruptcy_idle_counter\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_bond_market_dummy\n");
	current_xmachine_Government_holder = Government_Gov_Start_Bond_Market_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(FLAME_condition_Government_Government_bond_market_dummy_Gov_Start_Bond_Market_01(current_xmachine_Government))
		{

		

			i = Government_bond_market_dummy();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Bond_Market_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Bond_Market_state, Government_01_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_bond_market_dummy\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_gov_bond)\n");
    rc = MB_SyncStart(b_gov_bond);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_gov_bond)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'gov_bond' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_bond' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_bond' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_bankruptcy_illiquidity_procedure\n");
	current_xmachine_Firm_holder = Firm_Firm_not_active_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_bankrupty_state_1_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_bankruptcy_illiquidity_procedure_Firm_not_active_Firm_bankrupty_state_1(current_xmachine_Firm))
		{

		

			i = Firm_bankruptcy_illiquidity_procedure();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_active_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_active_state, Firm_Firm_bankrupty_state_1_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_bankruptcy_illiquidity_procedure\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_bankruptcy_insolvency_procedure\n");
	current_xmachine_Firm_holder = Firm_Firm_not_active_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_bankrupty_state_1_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_bankruptcy_insolvency_procedure_Firm_not_active_Firm_bankrupty_state_1(current_xmachine_Firm))
		{

		

			i = Firm_bankruptcy_insolvency_procedure();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_active_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_active_state, Firm_Firm_bankrupty_state_1_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_bankruptcy_insolvency_procedure\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start ClearingHouse_receive_orders_and_run_dummy\n");
	current_xmachine_Clearinghouse_holder = Clearinghouse_RECEIVEDINFOSTOCK_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		current_xmachine_Clearinghouse = current_xmachine_Clearinghouse_holder->agent;
		current_xmachine_Clearinghouse_next_state = Clearinghouse_COMPUTEDPRICES_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Clearinghouse = current_xmachine_Clearinghouse;

		

		

			i = ClearingHouse_receive_orders_and_run_dummy();

		

			if(i == 1)
			{
				free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_RECEIVEDINFOSTOCK_state);
			}
			else
			{
				transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_RECEIVEDINFOSTOCK_state, Clearinghouse_COMPUTEDPRICES_state);
			}
		

		current_xmachine_Clearinghouse = NULL;

		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish ClearingHouse_receive_orders_and_run_dummy\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_idle\n");
	current_xmachine_Government_holder = Government_Gov_Start_Bond_Market_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(FLAME_condition_Government_Government_idle_Gov_Start_Bond_Market_01(current_xmachine_Government))
		{

		

			i = Government_idle();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Bond_Market_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Bond_Market_state, Government_01_state);
			}
		}

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_idle\n");
	current_xmachine_Eurostat_holder = Eurostat_01_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_Start_Monthly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_idle_01_Eurostat_Start_Monthly_Loop(current_xmachine_Eurostat))
		{

		

			i = Eurostat_idle();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_01_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_01_state, Eurostat_Eurostat_Start_Monthly_Loop_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_Firm_is_active_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Start_Macro_Data_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_Firm_is_active_Firm_Start_Macro_Data(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_is_active_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_is_active_state, Firm_Firm_Start_Macro_Data_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_policy_announcement)\n");
	rc = MB_SyncComplete(b_policy_announcement);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_policy_announcement)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_policy_announcement, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_policy_announcement, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_policy_announcement, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_policy_announcement_composite_params);
	FLAME_m_policy_announcement_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_policy_announcements\n");
	current_xmachine_Firm_holder = Firm_Firm_is_active_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Start_Macro_Data_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data(current_xmachine_Firm))
		{

		
		rc = MB_Iterator_CreateFiltered(b_policy_announcement, &i_policy_announcement, &FLAME_filter_Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data_policy_announcement, current_xmachine_Firm);
		
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
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_is_active_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_is_active_state, Firm_Firm_Start_Macro_Data_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_policy_announcements\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_eurostat_send_specific_skills_2();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_eurostat_send_specific_skills)\n");
    rc = MB_SyncStart(b_eurostat_send_specific_skills);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_eurostat_send_specific_skills)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'eurostat_send_specific_skills' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_read_policy_announcements\n");
	current_xmachine_Household_holder = Household_start_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_Household_Start_Policy_Data_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data(current_xmachine_Household))
		{

		
		rc = MB_Iterator_CreateFiltered(b_policy_announcement, &i_policy_announcement, &FLAME_filter_Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data_policy_announcement, current_xmachine_Household);
		
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
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
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
				transition_Household_agent(current_xmachine_Household_holder, Household_start_Household_state, Household_Household_Start_Policy_Data_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_read_policy_announcements\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_read_policy_announcements\n");
	current_xmachine_IGFirm_holder = IGFirm_start_IGFirm_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_Start_IGFirm_Productivity_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		if(FLAME_condition_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity(current_xmachine_IGFirm))
		{

		
		rc = MB_Iterator_CreateFiltered(b_policy_announcement, &i_policy_announcement, &FLAME_filter_IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity_policy_announcement, current_xmachine_IGFirm);
		
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
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_policy_announcement);
		

			i = IGFirm_read_policy_announcements();

		
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
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_start_IGFirm_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_start_IGFirm_state, IGFirm_Start_IGFirm_Productivity_state);
			}
		}

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_read_policy_announcements\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_read_policy_announcements\n");
	current_xmachine_Bank_holder = Bank_start_Bank_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_start_credit_market_role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		if(FLAME_condition_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role(current_xmachine_Bank))
		{

		
		rc = MB_Iterator_CreateFiltered(b_policy_announcement, &i_policy_announcement, &FLAME_filter_Bank_Bank_read_policy_announcements_start_Bank_Bank_start_credit_market_role_policy_announcement, current_xmachine_Bank);
		
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
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		MB_Iterator_Randomise(i_policy_announcement);
		

			i = Bank_read_policy_announcements();

		
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
				free_Bank_agent(current_xmachine_Bank_holder, Bank_start_Bank_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_start_Bank_state, Bank_Bank_start_credit_market_role_state);
			}
		}

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_read_policy_announcements\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_communicate_identity\n");
	current_xmachine_Bank_holder = Bank_Bank_start_credit_market_role_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		

			i = Bank_communicate_identity();

		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_start_credit_market_role_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_start_credit_market_role_state, Bank_Bank_01_state);
			}
		

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_communicate_identity\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_identity)\n");
    rc = MB_SyncStart(b_bank_identity);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_identity)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'bank_identity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_identity' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_identity' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start ClearingHouse_send_asset_information_dummy\n");
	current_xmachine_Clearinghouse_holder = Clearinghouse_COMPUTEDPRICES_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		current_xmachine_Clearinghouse = current_xmachine_Clearinghouse_holder->agent;
		current_xmachine_Clearinghouse_next_state = Clearinghouse_end_Clearinghouse_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Clearinghouse = current_xmachine_Clearinghouse;

		

		

			i = ClearingHouse_send_asset_information_dummy();

		

			if(i == 1)
			{
				free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_COMPUTEDPRICES_state);
			}
			else
			{
				transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_COMPUTEDPRICES_state, Clearinghouse_end_Clearinghouse_state);
			}
		

		current_xmachine_Clearinghouse = NULL;

		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish ClearingHouse_send_asset_information_dummy\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_idle\n");
	current_xmachine_IGFirm_holder = IGFirm_Start_IGFirm_Productivity_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		if(FLAME_condition_IGFirm_IGFirm_idle_Start_IGFirm_Productivity_01(current_xmachine_IGFirm))
		{

		

			i = IGFirm_idle();

		

			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_Start_IGFirm_Productivity_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_Start_IGFirm_Productivity_state, IGFirm_01_state);
			}
		}

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_update_productivity_price\n");
	current_xmachine_IGFirm_holder = IGFirm_Start_IGFirm_Productivity_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		if(FLAME_condition_IGFirm_IGFirm_update_productivity_price_Start_IGFirm_Productivity_01(current_xmachine_IGFirm))
		{

		

			i = IGFirm_update_productivity_price();

		

			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_Start_IGFirm_Productivity_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_Start_IGFirm_Productivity_state, IGFirm_01_state);
			}
		}

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_update_productivity_price\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_Household_Start_Policy_Data_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_Household_Start_Financial_Market_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_Household_Start_Policy_Data_Household_Start_Financial_Market_Role(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Policy_Data_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Policy_Data_state, Household_Household_Start_Financial_Market_Role_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_receive_data\n");
	current_xmachine_Household_holder = Household_Household_Start_Policy_Data_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_Household_Start_Financial_Market_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_receive_data_Household_Start_Policy_Data_Household_Start_Financial_Market_Role(current_xmachine_Household))
		{

		

			i = Household_receive_data();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Policy_Data_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Policy_Data_state, Household_Household_Start_Financial_Market_Role_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_receive_data\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Macro_Data_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Macro_Data_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_Firm_Start_Macro_Data_Firm_End_Macro_Data(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Macro_Data_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Macro_Data_state, Firm_Firm_End_Macro_Data_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_Firm_bankrupty_state_1_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_bankrupty_state_3_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_Firm_bankrupty_state_1_Firm_bankrupty_state_3(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_1_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_1_state, Firm_Firm_bankrupty_state_3_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_and_send_stock_orders_dummy\n");
	current_xmachine_Firm_holder = Firm_Firm_bankrupty_state_1_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_bankrupty_state_2_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_compute_and_send_stock_orders_dummy_Firm_bankrupty_state_1_Firm_bankrupty_state_2(current_xmachine_Firm))
		{

		

			i = Firm_compute_and_send_stock_orders_dummy();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_1_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_1_state, Firm_Firm_bankrupty_state_2_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_and_send_stock_orders_dummy\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_eurostat_send_specific_skills)\n");
	rc = MB_SyncComplete(b_eurostat_send_specific_skills);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_eurostat_send_specific_skills)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'eurostat_send_specific_skills' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_eurostat_send_specific_skills, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_eurostat_send_specific_skills, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_eurostat_send_specific_skills, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_eurostat_send_specific_skills_composite_params);
	FLAME_m_eurostat_send_specific_skills_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_receive_data\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Macro_Data_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Macro_Data_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data(current_xmachine_Firm))
		{

		
		rc = MB_Iterator_CreateFiltered(b_eurostat_send_specific_skills, &i_eurostat_send_specific_skills, &FLAME_filter_Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data_eurostat_send_specific_skills, current_xmachine_Firm);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'eurostat_send_specific_skills'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is locked\n");
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
		MB_Iterator_Randomise(i_eurostat_send_specific_skills);
		

			i = Firm_receive_data();

		
		    rc = MB_Iterator_Delete(&i_eurostat_send_specific_skills);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'eurostat_send_specific_skills' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Macro_Data_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Macro_Data_state, Firm_Firm_End_Macro_Data_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_receive_data\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_gov_bond)\n");
	rc = MB_SyncComplete(b_gov_bond);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_gov_bond)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'gov_bond' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_bond' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Central_Bank_read_bond_update\n");
	current_xmachine_Central_Bank_holder = Central_Bank_start_Central_Bank_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		current_xmachine_Central_Bank = current_xmachine_Central_Bank_holder->agent;
		current_xmachine_Central_Bank_next_state = Central_Bank_00_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Central_Bank = current_xmachine_Central_Bank;

		

		
		
		rc = MB_Iterator_Create(b_gov_bond, &i_gov_bond);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'gov_bond'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'gov_bond' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'gov_bond' board is locked\n");
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
		MB_Iterator_Randomise(i_gov_bond);
		

			i = Central_Bank_read_bond_update();

		
		    rc = MB_Iterator_Delete(&i_gov_bond);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'gov_bond' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'gov_bond' iterator is invalid\n");
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
				transition_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_start_Central_Bank_state, Central_Bank_00_state);
			}
		

		current_xmachine_Central_Bank = NULL;

		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Central_Bank_read_bond_update\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_send_quality_price_info\n");
	current_xmachine_IGFirm_holder = IGFirm_01_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		

		

			i = IGFirm_send_quality_price_info();

		

			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_01_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_01_state, IGFirm_02_state);
			}
		

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_send_quality_price_info\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_productivity)\n");
    rc = MB_SyncStart(b_productivity);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_productivity)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'productivity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'productivity' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'productivity' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_send_accountInterest\n");
	current_xmachine_Bank_holder = Bank_Bank_01_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		

			i = Bank_send_accountInterest();

		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_01_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_01_state, Bank_Bank_02_state);
			}
		

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_send_accountInterest\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_financial_market_dummy\n");
	current_xmachine_Household_holder = Household_Household_Start_Financial_Market_Role_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_Household_Start_Labour_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_financial_market_dummy();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Financial_Market_Role_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Financial_Market_Role_state, Household_Household_Start_Labour_Role_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_financial_market_dummy\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_info_dummy\n");
	current_xmachine_Firm_holder = Firm_Firm_End_Macro_Data_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Start_Producer_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_info_dummy();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Macro_Data_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Macro_Data_state, Firm_Firm_Start_Producer_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_info_dummy\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_stock_transactions_dummy\n");
	current_xmachine_Firm_holder = Firm_Firm_bankrupty_state_2_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_bankrupty_state_3_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_read_stock_transactions_dummy();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_2_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_2_state, Firm_Firm_bankrupty_state_3_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_stock_transactions_dummy\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_Household_Start_Labour_Role_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_01a_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_Household_Start_Labour_Role_01a(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Labour_Role_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Labour_Role_state, Household_01a_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_reset_bankruptcy_flags\n");
	current_xmachine_Firm_holder = Firm_Firm_bankrupty_state_3_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_end_Firm_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_reset_bankruptcy_flags();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_3_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_3_state, Firm_end_Firm_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_reset_bankruptcy_flags\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_set_quantities_zero\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Producer_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_00b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_set_quantities_zero_Firm_Start_Producer_Role_00b(current_xmachine_Firm))
		{

		

			i = Firm_set_quantities_zero();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Producer_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Producer_Role_state, Firm_00b_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_set_quantities_zero\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_calc_production_quantity\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Producer_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_calc_production_quantity_Firm_Start_Producer_Role_01(current_xmachine_Firm))
		{

		

			i = Firm_calc_production_quantity();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Producer_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Producer_Role_state, Firm_01_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_calc_production_quantity\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_productivity)\n");
	rc = MB_SyncComplete(b_productivity);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_productivity)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'productivity' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'productivity' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_calc_input_demands\n");
	current_xmachine_Firm_holder = Firm_01_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_productivity, &i_productivity);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'productivity'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'productivity' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'productivity' board is locked\n");
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
		MB_Iterator_Randomise(i_productivity);
		

			i = Firm_calc_input_demands();

		
		    rc = MB_Iterator_Delete(&i_productivity);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'productivity' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'productivity' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_01_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_01_state, Firm_02_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_calc_input_demands\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_total_liquidity_needs\n");
	current_xmachine_Firm_holder = Firm_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Start_Credit_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_compute_total_liquidity_needs();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_02_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_02_state, Firm_Firm_Start_Credit_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_total_liquidity_needs\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_External_Financing_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_Firm_Start_Credit_Role_Firm_End_External_Financing(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Credit_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Credit_Role_state, Firm_Firm_End_External_Financing_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_identity)\n");
	rc = MB_SyncComplete(b_bank_identity);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_identity)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'bank_identity' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_identity' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_ask_loan\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Credit_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_ask_loan_Firm_Start_Credit_Role_Firm_Credit_02(current_xmachine_Firm))
		{

		
		
		rc = MB_Iterator_Create(b_bank_identity, &i_bank_identity);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bank_identity'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bank_identity' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bank_identity' board is locked\n");
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
		MB_Iterator_Randomise(i_bank_identity);
		

			i = Firm_ask_loan();

		
		    rc = MB_Iterator_Delete(&i_bank_identity);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bank_identity' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bank_identity' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Credit_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Credit_Role_state, Firm_Firm_Credit_02_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_ask_loan\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_loan_request_8();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_request)\n");
    rc = MB_SyncStart(b_loan_request);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_request)\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_request)\n");
	rc = MB_SyncComplete(b_loan_request);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_request)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_loan_request, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_loan_request, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_loan_request, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_loan_request_composite_params);
	FLAME_m_loan_request_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_decide_credit_conditions\n");
	current_xmachine_Bank_holder = Bank_Bank_02_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		
		rc = MB_Iterator_CreateFiltered(b_loan_request, &i_loan_request, &FLAME_filter_Bank_Bank_decide_credit_conditions_Bank_02_Bank_03_loan_request, current_xmachine_Bank);
		
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
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_02_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_02_state, Bank_Bank_03_state);
			}
		

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_decide_credit_conditions\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_loan_conditions_9();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_conditions)\n");
    rc = MB_SyncStart(b_loan_conditions);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_conditions)\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_conditions)\n");
	rc = MB_SyncComplete(b_loan_conditions);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_conditions)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_loan_conditions, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_loan_conditions, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_loan_conditions, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_loan_conditions_composite_params);
	FLAME_m_loan_conditions_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_get_loan\n");
	current_xmachine_Firm_holder = Firm_Firm_Credit_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Credit_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		rc = MB_Iterator_CreateFiltered(b_loan_conditions, &i_loan_conditions, &FLAME_filter_Firm_Firm_get_loan_Firm_Credit_02_Firm_End_Credit_Role_loan_conditions, current_xmachine_Firm);
		
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_get_loan\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_loan_acceptance_10();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_loan_acceptance)\n");
    rc = MB_SyncStart(b_loan_acceptance);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_loan_acceptance)\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_Firm_End_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_External_Financing_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_Firm_End_Credit_Role_Firm_End_External_Financing(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Credit_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Credit_Role_state, Firm_Firm_End_External_Financing_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_and_send_stock_orders_dummy\n");
	current_xmachine_Firm_holder = Firm_Firm_End_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_0003_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_compute_and_send_stock_orders_dummy_Firm_End_Credit_Role_0003(current_xmachine_Firm))
		{

		

			i = Firm_compute_and_send_stock_orders_dummy();

		

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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_and_send_stock_orders_dummy\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_loan_acceptance)\n");
	rc = MB_SyncComplete(b_loan_acceptance);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_loan_acceptance)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_loan_acceptance, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_loan_acceptance, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_loan_acceptance, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_loan_acceptance_composite_params);
	FLAME_m_loan_acceptance_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_give_loan\n");
	current_xmachine_Bank_holder = Bank_Bank_03_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		
		rc = MB_Iterator_CreateFiltered(b_loan_acceptance, &i_loan_acceptance, &FLAME_filter_Bank_Bank_give_loan_Bank_03_Bank_04_loan_acceptance, current_xmachine_Bank);
		
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
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_03_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_03_state, Bank_Bank_04_state);
			}
		

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_give_loan\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_bankruptcy_16();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bankruptcy)\n");
    rc = MB_SyncStart(b_bankruptcy);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bankruptcy)\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_stock_transactions_dummy\n");
	current_xmachine_Firm_holder = Firm_0003_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_End_Firm_Financial_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_read_stock_transactions_dummy();

		

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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_stock_transactions_dummy\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_check_financial_and_bankruptcy_state\n");
	current_xmachine_Firm_holder = Firm_End_Firm_Financial_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_bankruptcy_checked_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_check_financial_and_bankruptcy_state();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_End_Firm_Financial_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_End_Firm_Financial_Role_state, Firm_Firm_bankruptcy_checked_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_check_financial_and_bankruptcy_state\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_set_bankruptcy_illiquidity\n");
	current_xmachine_Firm_holder = Firm_Firm_bankruptcy_checked_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Financial_Management_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_set_bankruptcy_illiquidity_Firm_bankruptcy_checked_Firm_End_Financial_Management_Role(current_xmachine_Firm))
		{

		

			i = Firm_set_bankruptcy_illiquidity();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankruptcy_checked_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankruptcy_checked_state, Firm_Firm_End_Financial_Management_Role_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_set_bankruptcy_illiquidity\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bankruptcy_illiquidity)\n");
    rc = MB_SyncStart(b_bankruptcy_illiquidity);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bankruptcy_illiquidity)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'bankruptcy_illiquidity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_not_in_bankruptcy\n");
	current_xmachine_Firm_holder = Firm_Firm_bankruptcy_checked_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_checks_financial_crisis_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_checks_financial_crisis(current_xmachine_Firm))
		{

		

			i = Firm_not_in_bankruptcy();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankruptcy_checked_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankruptcy_checked_state, Firm_Firm_checks_financial_crisis_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_not_in_bankruptcy\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_Firm_checks_financial_crisis_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_External_Financing_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_Firm_checks_financial_crisis_Firm_End_External_Financing(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_checks_financial_crisis_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_checks_financial_crisis_state, Firm_Firm_End_External_Financing_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_in_financial_crisis\n");
	current_xmachine_Firm_holder = Firm_Firm_checks_financial_crisis_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_External_Financing_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_in_financial_crisis_Firm_checks_financial_crisis_Firm_End_External_Financing(current_xmachine_Firm))
		{

		

			i = Firm_in_financial_crisis();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_checks_financial_crisis_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_checks_financial_crisis_state, Firm_Firm_End_External_Financing_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_in_financial_crisis\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_execute_financial_payments\n");
	current_xmachine_Firm_holder = Firm_Firm_End_External_Financing_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Start_Public_Sector_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_execute_financial_payments();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_External_Financing_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_External_Financing_state, Firm_Firm_Start_Public_Sector_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_execute_financial_payments\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_installment_16();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_installment)\n");
    rc = MB_SyncStart(b_installment);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_installment)\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_subsidy_notification\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Public_Sector_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_005_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_subsidy_notification();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Public_Sector_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Public_Sector_Role_state, Firm_005_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_subsidy_notification\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bankruptcy)\n");
	rc = MB_SyncComplete(b_bankruptcy);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bankruptcy)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_bankruptcy, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_bankruptcy, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_bankruptcy, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_bankruptcy_composite_params);
	FLAME_m_bankruptcy_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_installment)\n");
	rc = MB_SyncComplete(b_installment);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_installment)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_installment, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_installment, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_installment, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_installment_composite_params);
	FLAME_m_installment_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_receive_installment\n");
	current_xmachine_Bank_holder = Bank_Bank_04_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		
		rc = MB_Iterator_CreateFiltered(b_installment, &i_installment, &FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_installment, current_xmachine_Bank);
		
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
		
		rc = MB_Iterator_CreateFiltered(b_bankruptcy, &i_bankruptcy, &FLAME_filter_Bank_Bank_receive_installment_Bank_04_Bank_05_bankruptcy, current_xmachine_Bank);
		
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
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_04_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_04_state, Bank_Bank_05_state);
			}
		

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_receive_installment\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_transfer_notification\n");
	current_xmachine_Firm_holder = Firm_005_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Financial_Management_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_transfer_notification();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_005_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_005_state, Firm_Firm_End_Financial_Management_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_transfer_notification\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_calc_production_quantity_2\n");
	current_xmachine_Firm_holder = Firm_Firm_End_Financial_Management_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Start_Labour_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_calc_production_quantity_2();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Financial_Management_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Financial_Management_state, Firm_Firm_Start_Labour_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_calc_production_quantity_2\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_calculate_specific_skills_and_wage_offer\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Labour_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_011_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_calculate_specific_skills_and_wage_offer();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Labour_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Labour_Role_state, Firm_011_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_calculate_specific_skills_and_wage_offer\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_redundancies\n");
	current_xmachine_Firm_holder = Firm_011_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_03ccc_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_send_redundancies_011_03ccc(current_xmachine_Firm))
		{

		

			i = Firm_send_redundancies();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_011_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_011_state, Firm_03ccc_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_redundancies\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_idle\n");
	current_xmachine_Firm_holder = Firm_011_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_03ccc_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_idle_011_03ccc(current_xmachine_Firm))
		{

		

			i = Firm_idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_011_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_011_state, Firm_03ccc_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_idle\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_random_redundancies\n");
	current_xmachine_Firm_holder = Firm_03ccc_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_04ccc_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_random_redundancies();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_03ccc_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_03ccc_state, Firm_04ccc_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_random_redundancies\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_firing_22();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firing)\n");
    rc = MB_SyncStart(b_firing);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firing)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'firing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firing' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firing' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_vacancies\n");
	current_xmachine_Firm_holder = Firm_04ccc_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_send_vacancies_04ccc_03(current_xmachine_Firm))
		{

		

			i = Firm_send_vacancies();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_04ccc_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_04ccc_state, Firm_03_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_vacancies\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_vacancies)\n");
    rc = MB_SyncStart(b_vacancies);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_vacancies)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'vacancies' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_04ccc_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_03c_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_04ccc_03c(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_04ccc_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_04ccc_state, Firm_03c_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firing)\n");
	rc = MB_SyncComplete(b_firing);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firing)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'firing' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firing' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_firing, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_firing, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_firing, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_firing_composite_params);
	FLAME_m_firing_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_read_firing_messages\n");
	current_xmachine_Household_holder = Household_Household_Start_Labour_Role_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_01d_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d(current_xmachine_Household))
		{

		
		rc = MB_Iterator_CreateFiltered(b_firing, &i_firing, &FLAME_filter_Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_firing, current_xmachine_Household);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'firing'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'firing' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firing' board is locked\n");
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
		MB_Iterator_Randomise(i_firing);
		

			i = Household_read_firing_messages();

		
		    rc = MB_Iterator_Delete(&i_firing);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'firing' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'firing' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Labour_Role_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Labour_Role_state, Household_01d_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_read_firing_messages\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_01d_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_01d_06(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_01d_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01d_state, Household_06_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_01d_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_01a_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_01d_01a(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_01d_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01d_state, Household_01a_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_vacancies)\n");
	rc = MB_SyncComplete(b_vacancies);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_vacancies)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'vacancies' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_UNEMPLOYED_read_job_vacancies_and_send_applications\n");
	current_xmachine_Household_holder = Household_01a_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		
		
		rc = MB_Iterator_Create(b_vacancies, &i_vacancies);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'vacancies'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'vacancies' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'vacancies' board is locked\n");
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
		MB_Iterator_Randomise(i_vacancies);
		

			i = Household_UNEMPLOYED_read_job_vacancies_and_send_applications();

		
		    rc = MB_Iterator_Delete(&i_vacancies);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'vacancies' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'vacancies' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_01a_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01a_state, Household_01_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_UNEMPLOYED_read_job_vacancies_and_send_applications\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_application)\n");
    rc = MB_SyncStart(b_job_application);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_application)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'job_application' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_application)\n");
	rc = MB_SyncComplete(b_job_application);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_application)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'job_application' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_job_applications_send_job_offer_or_rejection\n");
	current_xmachine_Firm_holder = Firm_03_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_job_application, &i_job_application);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_application'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_application' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_application' board is locked\n");
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
		MB_Iterator_Randomise(i_job_application);
		

			i = Firm_read_job_applications_send_job_offer_or_rejection();

		
		    rc = MB_Iterator_Delete(&i_job_application);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_application' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_application' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_03_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_03_state, Firm_04_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_job_applications_send_job_offer_or_rejection\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_offer)\n");
    rc = MB_SyncStart(b_job_offer);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_offer)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'job_offer' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_offer)\n");
	rc = MB_SyncComplete(b_job_offer);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_offer)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'job_offer' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_read_job_offers_send_response\n");
	current_xmachine_Household_holder = Household_01_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		
		
		rc = MB_Iterator_Create(b_job_offer, &i_job_offer);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_offer'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_offer' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_offer' board is locked\n");
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
		MB_Iterator_Randomise(i_job_offer);
		

			i = Household_read_job_offers_send_response();

		
		    rc = MB_Iterator_Delete(&i_job_offer);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_offer' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_offer' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_01_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01_state, Household_02_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_read_job_offers_send_response\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_quitting)\n");
    rc = MB_SyncStart(b_quitting);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_quitting)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'quitting' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
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

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_acceptance)\n");
    rc = MB_SyncStart(b_job_acceptance);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_acceptance)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'job_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_read_application_rejection_update_wage_reservation\n");
	current_xmachine_Household_holder = Household_02_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_02_03(current_xmachine_Household))
		{

		

			i = Household_read_application_rejection_update_wage_reservation();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_02_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_02_state, Household_03_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_read_application_rejection_update_wage_reservation\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_finish_labour_market\n");
	current_xmachine_Household_holder = Household_02_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_finish_labour_market_02_06(current_xmachine_Household))
		{

		

			i = Household_finish_labour_market();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_02_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_02_state, Household_06_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_finish_labour_market\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_acceptance)\n");
	rc = MB_SyncComplete(b_job_acceptance);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_acceptance)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'job_acceptance' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_job_responses\n");
	current_xmachine_Firm_holder = Firm_04_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_05a_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_job_acceptance, &i_job_acceptance);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_acceptance'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_acceptance' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_acceptance' board is locked\n");
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
		MB_Iterator_Randomise(i_job_acceptance);
		

			i = Firm_read_job_responses();

		
		    rc = MB_Iterator_Delete(&i_job_acceptance);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_acceptance' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_acceptance' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_04_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_04_state, Firm_05a_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_job_responses\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_quitting)\n");
	rc = MB_SyncComplete(b_quitting);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_quitting)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'quitting' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_job_quitting\n");
	current_xmachine_Firm_holder = Firm_00b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_09c_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_quitting, &i_quitting);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'quitting'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'quitting' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
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
		MB_Iterator_Randomise(i_quitting);
		

			i = Firm_read_job_quitting();

		
		    rc = MB_Iterator_Delete(&i_quitting);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'quitting' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'quitting' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_00b_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_00b_state, Firm_09c_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_job_quitting\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_job_quitting\n");
	current_xmachine_Firm_holder = Firm_03c_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_03d_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_quitting, &i_quitting);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'quitting'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'quitting' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
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
		MB_Iterator_Randomise(i_quitting);
		

			i = Firm_read_job_quitting();

		
		    rc = MB_Iterator_Delete(&i_quitting);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'quitting' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'quitting' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_03c_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_03c_state, Firm_03d_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_job_quitting\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_quitting)\n");
    rc = MB_SyncStart(b_quitting);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_quitting)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'quitting' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_finish_labour_market_first_round\n");
	current_xmachine_Firm_holder = Firm_03d_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_09a_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_finish_labour_market_first_round_03d_09a(current_xmachine_Firm))
		{

		

			i = Firm_finish_labour_market_first_round();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_03d_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_03d_state, Firm_09a_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_finish_labour_market_first_round\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_start_labour_market\n");
	current_xmachine_Firm_holder = Firm_03d_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_start_labour_market_03d_06(current_xmachine_Firm))
		{

		

			i = Firm_start_labour_market();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_03d_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_03d_state, Firm_06_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_start_labour_market\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_quitting)\n");
	rc = MB_SyncComplete(b_quitting);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_quitting)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'quitting' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_job_quitting\n");
	current_xmachine_Firm_holder = Firm_05a_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_05b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_quitting, &i_quitting);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'quitting'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'quitting' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
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
		MB_Iterator_Randomise(i_quitting);
		

			i = Firm_read_job_quitting();

		
		    rc = MB_Iterator_Delete(&i_quitting);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'quitting' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'quitting' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_05a_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_05a_state, Firm_05b_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_job_quitting\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_update_wage_offer\n");
	current_xmachine_Firm_holder = Firm_05b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_update_wage_offer_05b_06(current_xmachine_Firm))
		{

		

			i = Firm_update_wage_offer();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_05b_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_05b_state, Firm_06_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_update_wage_offer\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_finish_labour_market_first_round\n");
	current_xmachine_Firm_holder = Firm_05b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_09a_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_finish_labour_market_first_round_05b_09a(current_xmachine_Firm))
		{

		

			i = Firm_finish_labour_market_first_round();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_05b_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_05b_state, Firm_09a_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_finish_labour_market_first_round\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_vacancies_2\n");
	current_xmachine_Firm_holder = Firm_06_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_07_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_vacancies_2();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_06_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_06_state, Firm_07_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_vacancies_2\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_vacancies2)\n");
    rc = MB_SyncStart(b_vacancies2);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_vacancies2)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'vacancies2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies2' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_vacancies2)\n");
	rc = MB_SyncComplete(b_vacancies2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_vacancies2)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'vacancies2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies2' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2\n");
	current_xmachine_Household_holder = Household_03_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		
		
		rc = MB_Iterator_Create(b_vacancies2, &i_vacancies2);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'vacancies2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'vacancies2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'vacancies2' board is locked\n");
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
		MB_Iterator_Randomise(i_vacancies2);
		

			i = Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2();

		
		    rc = MB_Iterator_Delete(&i_vacancies2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'vacancies2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'vacancies2' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_03_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_03_state, Household_04_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_application2)\n");
    rc = MB_SyncStart(b_job_application2);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_application2)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'job_application2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application2' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_application2)\n");
	rc = MB_SyncComplete(b_job_application2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_application2)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'job_application2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application2' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_job_applications_send_job_offer_or_rejection_2\n");
	current_xmachine_Firm_holder = Firm_07_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_08_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_job_application2, &i_job_application2);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_application2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_application2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_application2' board is locked\n");
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
		MB_Iterator_Randomise(i_job_application2);
		

			i = Firm_read_job_applications_send_job_offer_or_rejection_2();

		
		    rc = MB_Iterator_Delete(&i_job_application2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_application2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_application2' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_07_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_07_state, Firm_08_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_job_applications_send_job_offer_or_rejection_2\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_offer2)\n");
    rc = MB_SyncStart(b_job_offer2);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_offer2)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'job_offer2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer2' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_offer2)\n");
	rc = MB_SyncComplete(b_job_offer2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_offer2)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'job_offer2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer2' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_read_job_offers_send_response_2\n");
	current_xmachine_Household_holder = Household_04_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		
		
		rc = MB_Iterator_Create(b_job_offer2, &i_job_offer2);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_offer2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_offer2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_offer2' board is locked\n");
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
		MB_Iterator_Randomise(i_job_offer2);
		

			i = Household_read_job_offers_send_response_2();

		
		    rc = MB_Iterator_Delete(&i_job_offer2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_offer2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_offer2' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_04_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_04_state, Household_05_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_read_job_offers_send_response_2\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_quitting2)\n");
    rc = MB_SyncStart(b_quitting2);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_quitting2)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'quitting2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting2' board is locked\n");
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

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_job_acceptance2)\n");
    rc = MB_SyncStart(b_job_acceptance2);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_job_acceptance2)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'job_acceptance2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance2' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_05_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_05_06(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_05_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_05_state, Household_06_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_read_application_rejection_update_wage_reservation_2\n");
	current_xmachine_Household_holder = Household_05_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_read_application_rejection_update_wage_reservation_2_05_06(current_xmachine_Household))
		{

		

			i = Household_read_application_rejection_update_wage_reservation_2();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_05_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_05_state, Household_06_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_read_application_rejection_update_wage_reservation_2\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_job_acceptance2)\n");
	rc = MB_SyncComplete(b_job_acceptance2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_job_acceptance2)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'job_acceptance2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance2' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_job_responses_2\n");
	current_xmachine_Firm_holder = Firm_08_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_09a_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_job_acceptance2, &i_job_acceptance2);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'job_acceptance2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'job_acceptance2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_acceptance2' board is locked\n");
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
		MB_Iterator_Randomise(i_job_acceptance2);
		

			i = Firm_read_job_responses_2();

		
		    rc = MB_Iterator_Delete(&i_job_acceptance2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'job_acceptance2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'job_acceptance2' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_08_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_08_state, Firm_09a_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_job_responses_2\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_quitting2)\n");
	rc = MB_SyncComplete(b_quitting2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_quitting2)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'quitting2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_job_quitting_2\n");
	current_xmachine_Firm_holder = Firm_09c_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Start_Seller_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_quitting2, &i_quitting2);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'quitting2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'quitting2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quitting2' board is locked\n");
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
		MB_Iterator_Randomise(i_quitting2);
		

			i = Firm_read_job_quitting_2();

		
		    rc = MB_Iterator_Delete(&i_quitting2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'quitting2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'quitting2' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_09c_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_09c_state, Firm_Firm_Start_Seller_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_job_quitting_2\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_quitting2)\n");
    rc = MB_SyncStart(b_quitting2);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_quitting2)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'quitting2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting2' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_quitting2)\n");
	rc = MB_SyncComplete(b_quitting2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_quitting2)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'quitting2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_read_job_quitting_2\n");
	current_xmachine_Firm_holder = Firm_09a_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_09b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		
		rc = MB_Iterator_Create(b_quitting2, &i_quitting2);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'quitting2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'quitting2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quitting2' board is locked\n");
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
		MB_Iterator_Randomise(i_quitting2);
		

			i = Firm_read_job_quitting_2();

		
		    rc = MB_Iterator_Delete(&i_quitting2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'quitting2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'quitting2' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_09a_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_09a_state, Firm_09b_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_read_job_quitting_2\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_idle\n");
	current_xmachine_Firm_holder = Firm_09b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_10_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_idle_09b_10(current_xmachine_Firm))
		{

		

			i = Firm_idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_09b_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_09b_state, Firm_10_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_update_wage_offer_2\n");
	current_xmachine_Firm_holder = Firm_09b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_10_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_update_wage_offer_2_09b_10(current_xmachine_Firm))
		{

		

			i = Firm_update_wage_offer_2();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_09b_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_09b_state, Firm_10_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_update_wage_offer_2\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_mean_wage_specific_skills\n");
	current_xmachine_Firm_holder = Firm_10_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Labour_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_compute_mean_wage_specific_skills();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_10_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_10_state, Firm_Firm_End_Labour_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_mean_wage_specific_skills\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_capital_demand\n");
	current_xmachine_Firm_holder = Firm_Firm_End_Labour_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_11a_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_capital_demand();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Labour_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Labour_Role_state, Firm_11a_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_capital_demand\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_capital_good_request)\n");
    rc = MB_SyncStart(b_capital_good_request);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_capital_good_request)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'capital_good_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_request' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_request' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_capital_good_request)\n");
	rc = MB_SyncComplete(b_capital_good_request);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_capital_good_request)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'capital_good_request' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_request' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_send_capital_good\n");
	current_xmachine_IGFirm_holder = IGFirm_02_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		

		
		
		rc = MB_Iterator_Create(b_capital_good_request, &i_capital_good_request);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'capital_good_request'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'capital_good_request' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'capital_good_request' board is locked\n");
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
		MB_Iterator_Randomise(i_capital_good_request);
		

			i = IGFirm_send_capital_good();

		
		    rc = MB_Iterator_Delete(&i_capital_good_request);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'capital_good_request' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'capital_good_request' iterator is invalid\n");
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
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_02_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_02_state, IGFirm_03_state);
			}
		

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_send_capital_good\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_capital_good_delivery_40();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_capital_good_delivery)\n");
    rc = MB_SyncStart(b_capital_good_delivery);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_capital_good_delivery)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'capital_good_delivery' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_capital_good_delivery)\n");
	rc = MB_SyncComplete(b_capital_good_delivery);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_capital_good_delivery)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'capital_good_delivery' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_capital_good_delivery, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_capital_good_delivery, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_capital_good_delivery, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_capital_good_delivery_composite_params);
	FLAME_m_capital_good_delivery_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_receive_capital_goods\n");
	current_xmachine_Firm_holder = Firm_11a_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_11b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		rc = MB_Iterator_CreateFiltered(b_capital_good_delivery, &i_capital_good_delivery, &FLAME_filter_Firm_Firm_receive_capital_goods_11a_11b_capital_good_delivery, current_xmachine_Firm);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'capital_good_delivery'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'capital_good_delivery' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'capital_good_delivery' board is locked\n");
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
		MB_Iterator_Randomise(i_capital_good_delivery);
		

			i = Firm_receive_capital_goods();

		
		    rc = MB_Iterator_Delete(&i_capital_good_delivery);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'capital_good_delivery' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'capital_good_delivery' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_11a_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_11a_state, Firm_11b_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_receive_capital_goods\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_execute_production\n");
	current_xmachine_Firm_holder = Firm_11b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_11_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_execute_production();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_11b_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_11b_state, Firm_11_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_execute_production\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_calc_pay_costs\n");
	current_xmachine_Firm_holder = Firm_11_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_12_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_calc_pay_costs();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_11_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_11_state, Firm_12_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_calc_pay_costs\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_pay_capital_goods)\n");
    rc = MB_SyncStart(b_pay_capital_goods);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_pay_capital_goods)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'pay_capital_goods' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_goods_to_mall\n");
	current_xmachine_Firm_holder = Firm_12_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Start_Seller_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_goods_to_mall();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_12_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_12_state, Firm_Firm_Start_Seller_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_goods_to_mall\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_update_mall_stock)\n");
    rc = MB_SyncStart(b_update_mall_stock);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_update_mall_stock)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'update_mall_stock' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'update_mall_stock' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'update_mall_stock' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_pay_capital_goods)\n");
	rc = MB_SyncComplete(b_pay_capital_goods);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_pay_capital_goods)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'pay_capital_goods' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_receive_payment\n");
	current_xmachine_IGFirm_holder = IGFirm_03_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		

		
		
		rc = MB_Iterator_Create(b_pay_capital_goods, &i_pay_capital_goods);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'pay_capital_goods'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'pay_capital_goods' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'pay_capital_goods' board is locked\n");
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
		MB_Iterator_Randomise(i_pay_capital_goods);
		

			i = IGFirm_receive_payment();

		
		    rc = MB_Iterator_Delete(&i_pay_capital_goods);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'pay_capital_goods' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'pay_capital_goods' iterator is invalid\n");
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
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_03_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_03_state, IGFirm_04_state);
			}
		

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_receive_payment\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_pay_taxes\n");
	current_xmachine_IGFirm_holder = IGFirm_04_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_04b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		if(FLAME_condition_IGFirm_IGFirm_pay_taxes_04_04b(current_xmachine_IGFirm))
		{

		

			i = IGFirm_pay_taxes();

		

			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_04_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_04_state, IGFirm_04b_state);
			}
		}

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_pay_taxes\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_idle\n");
	current_xmachine_IGFirm_holder = IGFirm_04_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_end_IGFirm_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		if(FLAME_condition_IGFirm_IGFirm_idle_04_end_IGFirm(current_xmachine_IGFirm))
		{

		

			i = IGFirm_idle();

		

			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_04_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_04_state, IGFirm_end_IGFirm_state);
			}
		}

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bankruptcy_illiquidity)\n");
	rc = MB_SyncComplete(b_bankruptcy_illiquidity);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bankruptcy_illiquidity)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'bankruptcy_illiquidity' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_update_mall_stock)\n");
	rc = MB_SyncComplete(b_update_mall_stock);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_update_mall_stock)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'update_mall_stock' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'update_mall_stock' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Mall_update_mall_stock\n");
	current_xmachine_Mall_holder = Mall_01_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		

		
		
		rc = MB_Iterator_Create(b_update_mall_stock, &i_update_mall_stock);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'update_mall_stock'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'update_mall_stock' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'update_mall_stock' board is locked\n");
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
		MB_Iterator_Randomise(i_update_mall_stock);
		
		
		rc = MB_Iterator_Create(b_bankruptcy_illiquidity, &i_bankruptcy_illiquidity);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bankruptcy_illiquidity'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is locked\n");
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
		MB_Iterator_Randomise(i_bankruptcy_illiquidity);
		

			i = Mall_update_mall_stock();

		
		    rc = MB_Iterator_Delete(&i_update_mall_stock);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'update_mall_stock' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'update_mall_stock' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_bankruptcy_illiquidity);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bankruptcy_illiquidity' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' iterator is invalid\n");
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
				free_Mall_agent(current_xmachine_Mall_holder, Mall_01_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_01_state, Mall_02_state);
			}
		

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Mall_update_mall_stock\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start IGFirm_dividend_payment\n");
	current_xmachine_IGFirm_holder = IGFirm_04b_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_end_IGFirm_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;

		if(FLAME_condition_IGFirm_IGFirm_dividend_payment_04b_end_IGFirm(current_xmachine_IGFirm))
		{

		

			i = IGFirm_dividend_payment();

		

			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_04b_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_04b_state, IGFirm_end_IGFirm_state);
			}
		}

		current_xmachine_IGFirm = NULL;

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish IGFirm_dividend_payment\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_dividend_per_share)\n");
    rc = MB_SyncStart(b_dividend_per_share);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_dividend_per_share)\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Mall_send_quality_price_info_1\n");
	current_xmachine_Mall_holder = Mall_02_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		

		

			i = Mall_send_quality_price_info_1();

		

			if(i == 1)
			{
				free_Mall_agent(current_xmachine_Mall_holder, Mall_02_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_02_state, Mall_03_state);
			}
		

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Mall_send_quality_price_info_1\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_dividend_per_share)\n");
	rc = MB_SyncComplete(b_dividend_per_share);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_dividend_per_share)\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_receive_dividends\n");
	current_xmachine_Household_holder = Household_06_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_06b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		
		
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
		

			i = Household_receive_dividends();

		
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
				free_Household_agent(current_xmachine_Household_holder, Household_06_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06_state, Household_06b_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_receive_dividends\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_06b_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_06c_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_06b_06c(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_06b_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06b_state, Household_06c_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_06b_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_09_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_06b_09(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_06b_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06b_state, Household_09_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_send_subsidy_notification\n");
	current_xmachine_Household_holder = Household_06c_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_06d_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_send_subsidy_notification();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_06c_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06c_state, Household_06d_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_send_subsidy_notification\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_send_transfer_notification\n");
	current_xmachine_Household_holder = Household_06d_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_06e_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_send_transfer_notification();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_06d_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06d_state, Household_06e_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_send_transfer_notification\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_wage_payment_50();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_wage_payment)\n");
    rc = MB_SyncStart(b_wage_payment);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_wage_payment)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'wage_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'wage_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'wage_payment' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_send_unemployment_benefit_notification\n");
	current_xmachine_Household_holder = Household_06e_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_08_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_send_unemployment_benefit_notification_06e_08(current_xmachine_Household))
		{

		

			i = Household_send_unemployment_benefit_notification();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_06e_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06e_state, Household_08_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_send_unemployment_benefit_notification\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_wage_payment)\n");
	rc = MB_SyncComplete(b_wage_payment);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_wage_payment)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'wage_payment' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'wage_payment' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_wage_payment, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_wage_payment, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_wage_payment, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_wage_payment_composite_params);
	FLAME_m_wage_payment_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_receive_wage\n");
	current_xmachine_Household_holder = Household_06e_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_07_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_receive_wage_06e_07(current_xmachine_Household))
		{

		
		rc = MB_Iterator_CreateFiltered(b_wage_payment, &i_wage_payment, &FLAME_filter_Household_Household_receive_wage_06e_07_wage_payment, current_xmachine_Household);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'wage_payment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'wage_payment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'wage_payment' board is locked\n");
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
		MB_Iterator_Randomise(i_wage_payment);
		

			i = Household_receive_wage();

		
		    rc = MB_Iterator_Delete(&i_wage_payment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'wage_payment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'wage_payment' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_06e_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06e_state, Household_07_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_receive_wage\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_update_specific_skills\n");
	current_xmachine_Household_holder = Household_07_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_08_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_update_specific_skills();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_07_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_07_state, Household_08_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_update_specific_skills\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_send_tax_payment\n");
	current_xmachine_Household_holder = Household_08_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_08b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_send_tax_payment();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_08_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_08_state, Household_08b_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_send_tax_payment\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_determine_consumption_budget\n");
	current_xmachine_Household_holder = Household_08b_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_09_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_determine_consumption_budget();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_08b_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_08b_state, Household_09_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_determine_consumption_budget\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_quality_price_info_1_54();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_quality_price_info_1)\n");
    rc = MB_SyncStart(b_quality_price_info_1);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_quality_price_info_1)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'quality_price_info_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_shifting_consumption_day\n");
	current_xmachine_Household_holder = Household_09_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_15_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_shifting_consumption_day_09_15(current_xmachine_Household))
		{

		

			i = Household_shifting_consumption_day();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_09_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_09_state, Household_15_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_shifting_consumption_day\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_quality_price_info_1)\n");
	rc = MB_SyncComplete(b_quality_price_info_1);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_quality_price_info_1)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'quality_price_info_1' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_quality_price_info_1, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_quality_price_info_1, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_quality_price_info_1, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_quality_price_info_1_composite_params);
	FLAME_m_quality_price_info_1_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_rank_and_buy_goods_1\n");
	current_xmachine_Household_holder = Household_09_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_09b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_rank_and_buy_goods_1_09_09b(current_xmachine_Household))
		{

		
		rc = MB_Iterator_CreateFiltered(b_quality_price_info_1, &i_quality_price_info_1, &FLAME_filter_Household_Household_rank_and_buy_goods_1_09_09b_quality_price_info_1, current_xmachine_Household);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'quality_price_info_1'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'quality_price_info_1' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quality_price_info_1' board is locked\n");
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
		MB_Iterator_Randomise(i_quality_price_info_1);
		

			i = Household_rank_and_buy_goods_1();

		
		    rc = MB_Iterator_Delete(&i_quality_price_info_1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'quality_price_info_1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'quality_price_info_1' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_09_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_09_state, Household_09b_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_rank_and_buy_goods_1\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_consumption_request_1_55();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_consumption_request_1)\n");
    rc = MB_SyncStart(b_consumption_request_1);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_consumption_request_1)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'consumption_request_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_1' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_09_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_15_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_09_15(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_09_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_09_state, Household_15_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_consumption_request_1)\n");
	rc = MB_SyncComplete(b_consumption_request_1);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_consumption_request_1)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'consumption_request_1' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_1' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_consumption_request_1, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_consumption_request_1, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_consumption_request_1, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_consumption_request_1_composite_params);
	FLAME_m_consumption_request_1_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Mall_update_mall_stocks_sales_rationing_1\n");
	current_xmachine_Mall_holder = Mall_03_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		

		
		rc = MB_Iterator_CreateFiltered(b_consumption_request_1, &i_consumption_request_1, &FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_1_03_04_consumption_request_1, current_xmachine_Mall);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'consumption_request_1'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'consumption_request_1' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'consumption_request_1' board is locked\n");
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
		MB_Iterator_Randomise(i_consumption_request_1);
		

			i = Mall_update_mall_stocks_sales_rationing_1();

		
		    rc = MB_Iterator_Delete(&i_consumption_request_1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'consumption_request_1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'consumption_request_1' iterator is invalid\n");
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
				free_Mall_agent(current_xmachine_Mall_holder, Mall_03_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_03_state, Mall_04_state);
			}
		

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Mall_update_mall_stocks_sales_rationing_1\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_09b_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_10_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_09b_10(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_09b_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_09b_state, Household_10_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_back_shifting_consumption_day\n");
	current_xmachine_Household_holder = Household_09b_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_10_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_back_shifting_consumption_day_09b_10(current_xmachine_Household))
		{

		

			i = Household_back_shifting_consumption_day();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_09b_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_09b_state, Household_10_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_back_shifting_consumption_day\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_accepted_consumption_1_56();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_accepted_consumption_1)\n");
    rc = MB_SyncStart(b_accepted_consumption_1);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_accepted_consumption_1)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'accepted_consumption_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_accepted_consumption_1)\n");
	rc = MB_SyncComplete(b_accepted_consumption_1);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_accepted_consumption_1)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'accepted_consumption_1' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_accepted_consumption_1, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_accepted_consumption_1, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_accepted_consumption_1, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_accepted_consumption_1_composite_params);
	FLAME_m_accepted_consumption_1_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_receive_goods_read_rationing\n");
	current_xmachine_Household_holder = Household_10_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_11_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		
		rc = MB_Iterator_CreateFiltered(b_accepted_consumption_1, &i_accepted_consumption_1, &FLAME_filter_Household_Household_receive_goods_read_rationing_10_11_accepted_consumption_1, current_xmachine_Household);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'accepted_consumption_1'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'accepted_consumption_1' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is locked\n");
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
		MB_Iterator_Randomise(i_accepted_consumption_1);
		

			i = Household_receive_goods_read_rationing();

		
		    rc = MB_Iterator_Delete(&i_accepted_consumption_1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'accepted_consumption_1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'accepted_consumption_1' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_10_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_10_state, Household_11_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_receive_goods_read_rationing\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_quality_price_info_2_57();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_quality_price_info_2)\n");
    rc = MB_SyncStart(b_quality_price_info_2);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_quality_price_info_2)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'quality_price_info_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_quality_price_info_2)\n");
	rc = MB_SyncComplete(b_quality_price_info_2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_quality_price_info_2)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'quality_price_info_2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_quality_price_info_2, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_quality_price_info_2, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_quality_price_info_2, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_quality_price_info_2_composite_params);
	FLAME_m_quality_price_info_2_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_rank_and_buy_goods_2\n");
	current_xmachine_Household_holder = Household_11_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_12_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_rank_and_buy_goods_2_11_12(current_xmachine_Household))
		{

		
		rc = MB_Iterator_CreateFiltered(b_quality_price_info_2, &i_quality_price_info_2, &FLAME_filter_Household_Household_rank_and_buy_goods_2_11_12_quality_price_info_2, current_xmachine_Household);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'quality_price_info_2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'quality_price_info_2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quality_price_info_2' board is locked\n");
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
		MB_Iterator_Randomise(i_quality_price_info_2);
		

			i = Household_rank_and_buy_goods_2();

		
		    rc = MB_Iterator_Delete(&i_quality_price_info_2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'quality_price_info_2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'quality_price_info_2' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_11_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_11_state, Household_12_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_rank_and_buy_goods_2\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_consumption_request_2_58();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_consumption_request_2)\n");
    rc = MB_SyncStart(b_consumption_request_2);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_consumption_request_2)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'consumption_request_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_2' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_set_values_zero\n");
	current_xmachine_Household_holder = Household_11_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_14_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_set_values_zero_11_14(current_xmachine_Household))
		{

		

			i = Household_set_values_zero();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_11_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_11_state, Household_14_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_set_values_zero\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_consumption_request_2)\n");
	rc = MB_SyncComplete(b_consumption_request_2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_consumption_request_2)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'consumption_request_2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_2' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_consumption_request_2, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_consumption_request_2, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_consumption_request_2, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_consumption_request_2_composite_params);
	FLAME_m_consumption_request_2_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Mall_update_mall_stocks_sales_rationing_2\n");
	current_xmachine_Mall_holder = Mall_04_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		

		
		rc = MB_Iterator_CreateFiltered(b_consumption_request_2, &i_consumption_request_2, &FLAME_filter_Mall_Mall_update_mall_stocks_sales_rationing_2_04_05_consumption_request_2, current_xmachine_Mall);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'consumption_request_2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'consumption_request_2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'consumption_request_2' board is locked\n");
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
		MB_Iterator_Randomise(i_consumption_request_2);
		

			i = Mall_update_mall_stocks_sales_rationing_2();

		
		    rc = MB_Iterator_Delete(&i_consumption_request_2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'consumption_request_2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'consumption_request_2' iterator is invalid\n");
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
				free_Mall_agent(current_xmachine_Mall_holder, Mall_04_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_04_state, Mall_05_state);
			}
		

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Mall_update_mall_stocks_sales_rationing_2\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_accepted_consumption_2_59();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_accepted_consumption_2)\n");
    rc = MB_SyncStart(b_accepted_consumption_2);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_accepted_consumption_2)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'accepted_consumption_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Mall_pay_firm\n");
	current_xmachine_Mall_holder = Mall_05_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_05a_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		

		

			i = Mall_pay_firm();

		

			if(i == 1)
			{
				free_Mall_agent(current_xmachine_Mall_holder, Mall_05_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_05_state, Mall_05a_state);
			}
		

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Mall_pay_firm\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_sales_60();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_sales)\n");
    rc = MB_SyncStart(b_sales);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_sales)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'sales' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sales' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sales' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_accepted_consumption_2)\n");
	rc = MB_SyncComplete(b_accepted_consumption_2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_accepted_consumption_2)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'accepted_consumption_2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_accepted_consumption_2, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_accepted_consumption_2, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_accepted_consumption_2, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_accepted_consumption_2_composite_params);
	FLAME_m_accepted_consumption_2_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_receive_goods_read_rationing_2\n");
	current_xmachine_Household_holder = Household_12_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_14_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		
		rc = MB_Iterator_CreateFiltered(b_accepted_consumption_2, &i_accepted_consumption_2, &FLAME_filter_Household_Household_receive_goods_read_rationing_2_12_14_accepted_consumption_2, current_xmachine_Household);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'accepted_consumption_2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'accepted_consumption_2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is locked\n");
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
		MB_Iterator_Randomise(i_accepted_consumption_2);
		

			i = Household_receive_goods_read_rationing_2();

		
		    rc = MB_Iterator_Delete(&i_accepted_consumption_2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'accepted_consumption_2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'accepted_consumption_2' iterator is invalid\n");
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
				free_Household_agent(current_xmachine_Household_holder, Household_12_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_12_state, Household_14_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_receive_goods_read_rationing_2\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_handle_leftover_budget\n");
	current_xmachine_Household_holder = Household_14_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_15_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		

		

			i = Household_handle_leftover_budget();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_14_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_14_state, Household_15_state);
			}
		

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_handle_leftover_budget\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_sales)\n");
	rc = MB_SyncComplete(b_sales);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_sales)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'sales' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sales' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_sales, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_sales, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_sales, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_sales_composite_params);
	FLAME_m_sales_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_calc_revenue\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Seller_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Seller_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		
		rc = MB_Iterator_CreateFiltered(b_sales, &i_sales, &FLAME_filter_Firm_Firm_calc_revenue_Firm_Start_Seller_Role_Firm_End_Seller_Role_sales, current_xmachine_Firm);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'sales'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'sales' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'sales' board is locked\n");
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
		MB_Iterator_Randomise(i_sales);
		

			i = Firm_calc_revenue();

		
		    rc = MB_Iterator_Delete(&i_sales);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'sales' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'sales' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Seller_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Seller_Role_state, Firm_Firm_End_Seller_Role_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_calc_revenue\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_specific_skill_update_61();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_specific_skill_update)\n");
    rc = MB_SyncStart(b_specific_skill_update);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_specific_skill_update)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'specific_skill_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'specific_skill_update' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'specific_skill_update' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_send_data_to_Eurostat\n");
	current_xmachine_Household_holder = Household_15_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_Household_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_send_data_to_Eurostat_15_end_Household(current_xmachine_Household))
		{

		

			i = Household_send_data_to_Eurostat();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_15_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_15_state, Household_end_Household_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_send_data_to_Eurostat\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_household_balance_sheet)\n");
    rc = MB_SyncStart(b_household_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_household_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'household_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board is locked\n");
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

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_household_send_data)\n");
    rc = MB_SyncStart(b_household_send_data);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_household_send_data)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'household_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_send_data' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_send_data' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Household_idle\n");
	current_xmachine_Household_holder = Household_15_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_Household_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;

		if(FLAME_condition_Household_Household_idle_15_end_Household(current_xmachine_Household))
		{

		

			i = Household_idle();

		

			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_15_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_15_state, Household_end_Household_state);
			}
		}

		current_xmachine_Household = NULL;

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Household_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_Firm_End_Seller_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_14_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_Firm_End_Seller_Role_14(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Seller_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Seller_Role_state, Firm_14_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_specific_skill_update)\n");
	rc = MB_SyncComplete(b_specific_skill_update);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_specific_skill_update)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'specific_skill_update' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'specific_skill_update' board is invalid\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_specific_skill_update, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_specific_skill_update, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_specific_skill_update, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_specific_skill_update_composite_params);
	FLAME_m_specific_skill_update_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_update_specific_skills_of_workers\n");
	current_xmachine_Firm_holder = Firm_Firm_End_Seller_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_14_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14(current_xmachine_Firm))
		{

		
		rc = MB_Iterator_CreateFiltered(b_specific_skill_update, &i_specific_skill_update, &FLAME_filter_Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_specific_skill_update, current_xmachine_Firm);
		
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'specific_skill_update'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'specific_skill_update' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'specific_skill_update' board is locked\n");
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
		MB_Iterator_Randomise(i_specific_skill_update);
		

			i = Firm_update_specific_skills_of_workers();

		
		    rc = MB_Iterator_Delete(&i_specific_skill_update);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'specific_skill_update' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'specific_skill_update' iterator is invalid\n");
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Seller_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Seller_Role_state, Firm_14_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_update_specific_skills_of_workers\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_sales_statistics\n");
	current_xmachine_Firm_holder = Firm_14_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Start_Financial_Management_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_compute_sales_statistics_14_Firm_Start_Financial_Management_Role(current_xmachine_Firm))
		{

		

			i = Firm_compute_sales_statistics();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_14_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_14_state, Firm_Firm_Start_Financial_Management_Role_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_sales_statistics\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_14_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Financial_Management_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_14_Firm_End_Financial_Management_Role(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_14_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_14_state, Firm_Firm_End_Financial_Management_Role_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_financial_payments\n");
	current_xmachine_Firm_holder = Firm_Firm_Start_Financial_Management_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_001_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_compute_financial_payments();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Financial_Management_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Financial_Management_Role_state, Firm_001_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_financial_payments\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_income_statement\n");
	current_xmachine_Firm_holder = Firm_001_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_002_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_income_statement\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_dividends\n");
	current_xmachine_Firm_holder = Firm_002_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_003_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_dividends\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_total_financial_payments\n");
	current_xmachine_Firm_holder = Firm_003_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_004_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_total_financial_payments\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_compute_balance_sheet\n");
	current_xmachine_Firm_holder = Firm_004_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_Bankruptcy_check_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_compute_balance_sheet();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_004_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_004_state, Firm_Firm_Bankruptcy_check_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_compute_balance_sheet\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_set_bankruptcy_insolvency\n");
	current_xmachine_Firm_holder = Firm_Firm_Bankruptcy_check_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Financial_Management_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_set_bankruptcy_insolvency_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role(current_xmachine_Firm))
		{

		

			i = Firm_set_bankruptcy_insolvency();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Bankruptcy_check_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Bankruptcy_check_state, Firm_Firm_End_Financial_Management_Role_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_set_bankruptcy_insolvency\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bankruptcy_insolvency)\n");
    rc = MB_SyncStart(b_bankruptcy_insolvency);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bankruptcy_insolvency)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'bankruptcy_insolvency' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_Firm_Bankruptcy_check_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_Firm_End_Financial_Management_Role_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Bankruptcy_check_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Bankruptcy_check_state, Firm_Firm_End_Financial_Management_Role_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_data_to_Eurostat\n");
	current_xmachine_Firm_holder = Firm_Firm_End_Financial_Management_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_15_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_Firm_send_data_to_Eurostat_Firm_End_Financial_Management_Role_15(current_xmachine_Firm))
		{

		

			i = Firm_send_data_to_Eurostat();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Financial_Management_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Financial_Management_Role_state, Firm_15_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_data_to_Eurostat\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firm_balance_sheet)\n");
    rc = MB_SyncStart(b_firm_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firm_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'firm_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is locked\n");
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

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firm_send_data)\n");
    rc = MB_SyncStart(b_firm_send_data);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firm_send_data)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'firm_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_send_data' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_send_data' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Firm_holder = Firm_Firm_End_Financial_Management_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_15_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		if(FLAME_condition_Firm_idle_Firm_End_Financial_Management_Role_15(current_xmachine_Firm))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Financial_Management_Role_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Financial_Management_Role_state, Firm_15_state);
			}
		}

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bankruptcy_insolvency)\n");
	rc = MB_SyncComplete(b_bankruptcy_insolvency);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bankruptcy_insolvency)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'bankruptcy_insolvency' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Mall_read_insolvency_bankruptcy\n");
	current_xmachine_Mall_holder = Mall_05a_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		

		
		
		rc = MB_Iterator_Create(b_bankruptcy_insolvency, &i_bankruptcy_insolvency);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bankruptcy_insolvency'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is locked\n");
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
		MB_Iterator_Randomise(i_bankruptcy_insolvency);
		

			i = Mall_read_insolvency_bankruptcy();

		
		    rc = MB_Iterator_Delete(&i_bankruptcy_insolvency);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bankruptcy_insolvency' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' iterator is invalid\n");
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
				free_Mall_agent(current_xmachine_Mall_holder, Mall_05a_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_05a_state, Mall_06_state);
			}
		

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Mall_read_insolvency_bankruptcy\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Mall_send_export_data\n");
	current_xmachine_Mall_holder = Mall_06_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_end_Mall_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		if(FLAME_condition_Mall_Mall_send_export_data_06_end_Mall(current_xmachine_Mall))
		{

		

			i = Mall_send_export_data();

		

			if(i == 1)
			{
				free_Mall_agent(current_xmachine_Mall_holder, Mall_06_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_06_state, Mall_end_Mall_state);
			}
		}

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Mall_send_export_data\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_mall_data)\n");
    rc = MB_SyncStart(b_mall_data);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_mall_data)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'mall_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mall_data' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mall_data' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Mall_holder = Mall_06_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_end_Mall_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;

		if(FLAME_condition_Mall_idle_06_end_Mall(current_xmachine_Mall))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Mall_agent(current_xmachine_Mall_holder, Mall_06_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_06_state, Mall_end_Mall_state);
			}
		}

		current_xmachine_Mall = NULL;

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_receive_stock_info_dummy\n");
	current_xmachine_Firm_holder = Firm_15_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_16_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_receive_stock_info_dummy();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_15_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_15_state, Firm_16_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_receive_stock_info_dummy\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Firm_send_payments_to_bank\n");
	current_xmachine_Firm_holder = Firm_16_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_end_Firm_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;

		

		

			i = Firm_send_payments_to_bank();

		

			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_16_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_16_state, Firm_end_Firm_state);
			}
		

		current_xmachine_Firm = NULL;

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Firm_send_payments_to_bank\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_bank_account_update_72();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_account_update)\n");
    rc = MB_SyncStart(b_bank_account_update);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_account_update)\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_mall_data)\n");
	rc = MB_SyncComplete(b_mall_data);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_mall_data)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'mall_data' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mall_data' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_household_send_data)\n");
	rc = MB_SyncComplete(b_household_send_data);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_household_send_data)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'household_send_data' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_send_data' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firm_send_data)\n");
	rc = MB_SyncComplete(b_firm_send_data);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firm_send_data)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'firm_send_data' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_send_data' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_calculate_data\n");
	current_xmachine_Eurostat_holder = Eurostat_01_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_Start_Monthly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_calculate_data_01_Eurostat_Start_Monthly_Loop(current_xmachine_Eurostat))
		{

		
		
		rc = MB_Iterator_Create(b_firm_send_data, &i_firm_send_data);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'firm_send_data'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'firm_send_data' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_send_data' board is locked\n");
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
		MB_Iterator_Randomise(i_firm_send_data);
		
		
		rc = MB_Iterator_Create(b_household_send_data, &i_household_send_data);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'household_send_data'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'household_send_data' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'household_send_data' board is locked\n");
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
		MB_Iterator_Randomise(i_household_send_data);
		
		
		rc = MB_Iterator_Create(b_mall_data, &i_mall_data);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'mall_data'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'mall_data' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'mall_data' board is locked\n");
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
		MB_Iterator_Randomise(i_mall_data);
		

			i = Eurostat_calculate_data();

		
		    rc = MB_Iterator_Delete(&i_firm_send_data);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'firm_send_data' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'firm_send_data' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_household_send_data);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'household_send_data' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'household_send_data' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_mall_data);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'mall_data' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'mall_data' iterator is invalid\n");
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
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_01_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_01_state, Eurostat_Eurostat_Start_Monthly_Loop_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_calculate_data\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_account_update)\n");
	rc = MB_SyncComplete(b_bank_account_update);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_account_update)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_bank_account_update, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_bank_account_update, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_bank_account_update, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_bank_account_update_composite_params);
	FLAME_m_bank_account_update_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_account_update_deposits\n");
	current_xmachine_Bank_holder = Bank_Bank_05_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		

		
		rc = MB_Iterator_CreateFiltered(b_bank_account_update, &i_bank_account_update, &FLAME_filter_Bank_Bank_account_update_deposits_Bank_05_Bank_06_bank_account_update, current_xmachine_Bank);
		
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
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_05_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_05_state, Bank_Bank_06_state);
			}
		

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_account_update_deposits\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_idle\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_Monthly_Loop_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_Start_Quarterly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Monthly_Loop_Eurostat_Start_Quarterly_Loop(current_xmachine_Eurostat))
		{

		

			i = Eurostat_idle();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Monthly_Loop_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Monthly_Loop_state, Eurostat_Eurostat_Start_Quarterly_Loop_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_store_history_monthly\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_Monthly_Loop_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_store_history_monthly_Eurostat_Start_Monthly_Loop_02(current_xmachine_Eurostat))
		{

		

			i = Eurostat_store_history_monthly();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Monthly_Loop_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Monthly_Loop_state, Eurostat_02_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_store_history_monthly\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_accounting\n");
	current_xmachine_Bank_holder = Bank_Bank_06_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_Bank_07_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		if(FLAME_condition_Bank_Bank_accounting_Bank_06_Bank_07(current_xmachine_Bank))
		{

		

			i = Bank_accounting();

		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_06_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_06_state, Bank_Bank_07_state);
			}
		}

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_accounting\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_tax_payment_74();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_tax_payment)\n");
    rc = MB_SyncStart(b_tax_payment);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_tax_payment)\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_idle\n");
	current_xmachine_Bank_holder = Bank_Bank_06_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_end_Bank_cycle_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		if(FLAME_condition_Bank_Bank_idle_Bank_06_end_Bank_cycle(current_xmachine_Bank))
		{

		

			i = Bank_idle();

		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_06_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_06_state, Bank_end_Bank_cycle_state);
			}
		}

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_compute_growth_rates_monthly\n");
	current_xmachine_Eurostat_holder = Eurostat_02_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_Start_Quarterly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		

		

			i = Eurostat_compute_growth_rates_monthly();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_02_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_02_state, Eurostat_Eurostat_Start_Quarterly_Loop_state);
			}
		

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_compute_growth_rates_monthly\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_send_data_to_Eurostat\n");
	current_xmachine_Bank_holder = Bank_Bank_07_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_end_Bank_cycle_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		if(FLAME_condition_Bank_Bank_send_data_to_Eurostat_Bank_07_end_Bank_cycle(current_xmachine_Bank))
		{

		

			i = Bank_send_data_to_Eurostat();

		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_07_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_07_state, Bank_end_Bank_cycle_state);
			}
		}

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_send_data_to_Eurostat\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_balance_sheet)\n");
    rc = MB_SyncStart(b_bank_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'bank_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Bank_idle\n");
	current_xmachine_Bank_holder = Bank_Bank_07_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_end_Bank_cycle_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;

		if(FLAME_condition_Bank_Bank_idle_Bank_07_end_Bank_cycle(current_xmachine_Bank))
		{

		

			i = Bank_idle();

		

			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_07_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_07_state, Bank_end_Bank_cycle_state);
			}
		}

		current_xmachine_Bank = NULL;

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Bank_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_idle\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_Quarterly_Loop_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_Start_EndOfYear_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_Quarterly_Loop_Eurostat_Start_EndOfYear_Loop(current_xmachine_Eurostat))
		{

		

			i = Eurostat_idle();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Quarterly_Loop_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Quarterly_Loop_state, Eurostat_Eurostat_Start_EndOfYear_Loop_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_store_history_quarterly\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_Quarterly_Loop_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_store_history_quarterly_Eurostat_Start_Quarterly_Loop_04(current_xmachine_Eurostat))
		{

		

			i = Eurostat_store_history_quarterly();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Quarterly_Loop_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Quarterly_Loop_state, Eurostat_04_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_store_history_quarterly\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_tax_payment)\n");
	rc = MB_SyncComplete(b_tax_payment);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_tax_payment)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_tax_payment, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_tax_payment, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_tax_payment, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_tax_payment_composite_params);
	FLAME_m_tax_payment_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_read_tax_payments\n");
	current_xmachine_Government_holder = Government_01_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		
		rc = MB_Iterator_CreateFiltered(b_tax_payment, &i_tax_payment, &FLAME_filter_Government_Government_read_tax_payments_01_02_tax_payment, current_xmachine_Government);
		
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_read_tax_payments\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_firm_subsidy_notification_75();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firm_subsidy_notification)\n");
    rc = MB_SyncStart(b_firm_subsidy_notification);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firm_subsidy_notification)\n");
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

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_hh_subsidy_notification_75();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_hh_subsidy_notification)\n");
    rc = MB_SyncStart(b_hh_subsidy_notification);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_hh_subsidy_notification)\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_compute_growth_rates_quarterly\n");
	current_xmachine_Eurostat_holder = Eurostat_04_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		

		

			i = Eurostat_compute_growth_rates_quarterly();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_04_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_04_state, Eurostat_05_state);
			}
		

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_compute_growth_rates_quarterly\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firm_subsidy_notification)\n");
	rc = MB_SyncComplete(b_firm_subsidy_notification);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firm_subsidy_notification)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_firm_subsidy_notification, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_firm_subsidy_notification, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_firm_subsidy_notification, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_firm_subsidy_notification_composite_params);
	FLAME_m_firm_subsidy_notification_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_hh_subsidy_notification)\n");
	rc = MB_SyncComplete(b_hh_subsidy_notification);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_hh_subsidy_notification)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_hh_subsidy_notification, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_hh_subsidy_notification, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_hh_subsidy_notification, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_hh_subsidy_notification_composite_params);
	FLAME_m_hh_subsidy_notification_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_read_subsidy_notifications\n");
	current_xmachine_Government_holder = Government_02_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		
		rc = MB_Iterator_CreateFiltered(b_hh_subsidy_notification, &i_hh_subsidy_notification, &FLAME_filter_Government_Government_read_subsidy_notifications_02_03_hh_subsidy_notification, current_xmachine_Government);
		
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
		
		rc = MB_Iterator_CreateFiltered(b_firm_subsidy_notification, &i_firm_subsidy_notification, &FLAME_filter_Government_Government_read_subsidy_notifications_02_03_firm_subsidy_notification, current_xmachine_Government);
		
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_read_subsidy_notifications\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_firm_transfer_notification_76();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firm_transfer_notification)\n");
    rc = MB_SyncStart(b_firm_transfer_notification);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firm_transfer_notification)\n");
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

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_hh_transfer_notification_76();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_hh_transfer_notification)\n");
    rc = MB_SyncStart(b_hh_transfer_notification);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_hh_transfer_notification)\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_measure_recession\n");
	current_xmachine_Eurostat_holder = Eurostat_05_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_Start_EndOfYear_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		

		

			i = Eurostat_measure_recession();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_05_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_05_state, Eurostat_Eurostat_Start_EndOfYear_Loop_state);
			}
		

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_measure_recession\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firm_transfer_notification)\n");
	rc = MB_SyncComplete(b_firm_transfer_notification);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firm_transfer_notification)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_firm_transfer_notification, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_firm_transfer_notification, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_firm_transfer_notification, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_firm_transfer_notification_composite_params);
	FLAME_m_firm_transfer_notification_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_hh_transfer_notification)\n");
	rc = MB_SyncComplete(b_hh_transfer_notification);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_hh_transfer_notification)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_hh_transfer_notification, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_hh_transfer_notification, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_hh_transfer_notification, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_hh_transfer_notification_composite_params);
	FLAME_m_hh_transfer_notification_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_read_transfer_notifications\n");
	current_xmachine_Government_holder = Government_03_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		
		rc = MB_Iterator_CreateFiltered(b_hh_transfer_notification, &i_hh_transfer_notification, &FLAME_filter_Government_Government_read_transfer_notifications_03_04_hh_transfer_notification, current_xmachine_Government);
		
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
		
		rc = MB_Iterator_CreateFiltered(b_firm_transfer_notification, &i_firm_transfer_notification, &FLAME_filter_Government_Government_read_transfer_notifications_03_04_firm_transfer_notification, current_xmachine_Government);
		
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_read_transfer_notifications\n");

// new
if(FLAME_USE_FILTERS_IN_SYNC) FLAME_build_filter_param_unemployment_notification_77();
//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_unemployment_notification)\n");
    rc = MB_SyncStart(b_unemployment_notification);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_unemployment_notification)\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_send_data_to_government\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_EndOfYear_Loop_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_check_flows_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_send_data_to_government_Eurostat_Start_EndOfYear_Loop_Eurostat_check_flows(current_xmachine_Eurostat))
		{

		

			i = Eurostat_send_data_to_government();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_EndOfYear_Loop_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_EndOfYear_Loop_state, Eurostat_Eurostat_check_flows_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_send_data_to_government\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_data_for_government)\n");
    rc = MB_SyncStart(b_data_for_government);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_data_for_government)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'data_for_government' board\n");
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
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_idle\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_EndOfYear_Loop_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_check_flows_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_Eurostat_check_flows(current_xmachine_Eurostat))
		{

		

			i = Eurostat_idle();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_EndOfYear_Loop_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_EndOfYear_Loop_state, Eurostat_Eurostat_check_flows_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_unemployment_notification)\n");
	rc = MB_SyncComplete(b_unemployment_notification);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_unemployment_notification)\n");
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
    
    if(FLAME_USE_FILTERS_IN_SYNC) {
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_Function_Assign(b_unemployment_notification, MB_NULL_FUNCTION, NULL, 0)\n");
    rc = MB_Function_Assign(b_unemployment_notification, MB_NULL_FUNCTION, NULL, 0);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_Function_Assign(b_unemployment_notification, MB_NULL_FUNCTION, NULL, 0)\n");
	if ( rc != MB_SUCCESS )
	{
		fprintf(stderr, "Error while assigning NULL function to board\n");

		/* check value of rc to determine reason of failure. Handle error */
		/* don't continue if error can't be handled */
		exit(1);
	}
	/* Free memory used for filter composite params */
	free(FLAME_m_unemployment_notification_composite_params);
	FLAME_m_unemployment_notification_composite_params = NULL; }
	
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_read_unemployment_benefit_notifications\n");
	current_xmachine_Government_holder = Government_04_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_04b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		
		rc = MB_Iterator_CreateFiltered(b_unemployment_notification, &i_unemployment_notification, &FLAME_filter_Government_Government_read_unemployment_benefit_notifications_04_04b_unemployment_notification, current_xmachine_Government);
		
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
				transition_Government_agent(current_xmachine_Government_holder, Government_04_state, Government_04b_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_read_unemployment_benefit_notifications\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_send_data_to_Eurostat\n");
	current_xmachine_Government_holder = Government_04b_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_Gov_Start_Monthly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		

		

			i = Government_send_data_to_Eurostat();

		

			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_04b_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_04b_state, Government_Gov_Start_Monthly_Loop_state);
			}
		

		current_xmachine_Government = NULL;

		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_send_data_to_Eurostat\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_check_flows_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_check_stocks_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_idle_Eurostat_check_flows_Eurostat_check_stocks(current_xmachine_Eurostat))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_check_flows_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_check_flows_state, Eurostat_Eurostat_check_stocks_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_monthly_budget_accounting\n");
	current_xmachine_Government_holder = Government_Gov_Start_Monthly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(FLAME_condition_Government_Government_monthly_budget_accounting_Gov_Start_Monthly_Loop_05(current_xmachine_Government))
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_monthly_budget_accounting\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_idle\n");
	current_xmachine_Government_holder = Government_Gov_Start_Monthly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_Gov_Start_Yearly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(FLAME_condition_Government_Government_idle_Gov_Start_Monthly_Loop_Gov_Start_Yearly_Loop(current_xmachine_Government))
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_idle\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_monthly_resetting\n");
	current_xmachine_Government_holder = Government_05_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_06_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_monthly_resetting\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_send_account_update\n");
	current_xmachine_Government_holder = Government_06_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_Gov_Start_Yearly_Loop_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_send_account_update\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_gov_balance_sheet)\n");
    rc = MB_SyncStart(b_gov_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_gov_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'gov_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is locked\n");
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

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_central_bank_account_update)\n");
    rc = MB_SyncStart(b_central_bank_account_update);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_central_bank_account_update)\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_yearly_budget_accounting\n");
	current_xmachine_Government_holder = Government_Gov_Start_Yearly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_07_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(FLAME_condition_Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_07(current_xmachine_Government))
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_yearly_budget_accounting\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Government_holder = Government_Gov_Start_Yearly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_end_Government_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;

		if(FLAME_condition_Government_idle_Gov_Start_Yearly_Loop_end_Government(current_xmachine_Government))
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_central_bank_account_update)\n");
	rc = MB_SyncComplete(b_central_bank_account_update);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_central_bank_account_update)\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Central_Bank_read_account_update\n");
	current_xmachine_Central_Bank_holder = Central_Bank_00_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		current_xmachine_Central_Bank = current_xmachine_Central_Bank_holder->agent;
		current_xmachine_Central_Bank_next_state = Central_Bank_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
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
				free_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_00_state);
			}
			else
			{
				transition_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_00_state, Central_Bank_01_state);
			}
		

		current_xmachine_Central_Bank = NULL;

		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Central_Bank_read_account_update\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Central_Bank_send_data_to_Eurostat\n");
	current_xmachine_Central_Bank_holder = Central_Bank_01_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		current_xmachine_Central_Bank = current_xmachine_Central_Bank_holder->agent;
		current_xmachine_Central_Bank_next_state = Central_Bank_end_Central_Bank_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Central_Bank = current_xmachine_Central_Bank;

		if(FLAME_condition_Central_Bank_Central_Bank_send_data_to_Eurostat_01_end_Central_Bank(current_xmachine_Central_Bank))
		{

		

			i = Central_Bank_send_data_to_Eurostat();

		

			if(i == 1)
			{
				free_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_01_state);
			}
			else
			{
				transition_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_01_state, Central_Bank_end_Central_Bank_state);
			}
		}

		current_xmachine_Central_Bank = NULL;

		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Central_Bank_send_data_to_Eurostat\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_ecb_balance_sheet)\n");
    rc = MB_SyncStart(b_ecb_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_ecb_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'ecb_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is locked\n");
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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Central_Bank_holder = Central_Bank_01_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		current_xmachine_Central_Bank = current_xmachine_Central_Bank_holder->agent;
		current_xmachine_Central_Bank_next_state = Central_Bank_end_Central_Bank_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Central_Bank = current_xmachine_Central_Bank;

		if(FLAME_condition_Central_Bank_idle_01_end_Central_Bank(current_xmachine_Central_Bank))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_01_state);
			}
			else
			{
				transition_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_01_state, Central_Bank_end_Central_Bank_state);
			}
		}

		current_xmachine_Central_Bank = NULL;

		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_data_for_government)\n");
	rc = MB_SyncComplete(b_data_for_government);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_data_for_government)\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_read_data_from_Eurostat\n");
	current_xmachine_Government_holder = Government_07_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_08_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_read_data_from_Eurostat\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_set_policy\n");
	current_xmachine_Government_holder = Government_08_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_09_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_set_policy\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_ecb_balance_sheet)\n");
	rc = MB_SyncComplete(b_ecb_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_ecb_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'ecb_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_gov_balance_sheet)\n");
	rc = MB_SyncComplete(b_gov_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_gov_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'gov_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_balance_sheet)\n");
	rc = MB_SyncComplete(b_bank_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'bank_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_household_balance_sheet)\n");
	rc = MB_SyncComplete(b_household_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_household_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'household_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firm_balance_sheet)\n");
	rc = MB_SyncComplete(b_firm_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firm_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'firm_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_check_flow_consistency\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_check_flows_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_Eurostat_check_stocks_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_check_flow_consistency_Eurostat_check_flows_Eurostat_check_stocks(current_xmachine_Eurostat))
		{

		
		
		rc = MB_Iterator_Create(b_firm_balance_sheet, &i_firm_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'firm_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'firm_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_firm_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_household_balance_sheet, &i_household_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'household_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'household_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'household_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_household_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_igfirm_balance_sheet, &i_igfirm_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'igfirm_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'igfirm_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'igfirm_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_igfirm_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_bank_balance_sheet, &i_bank_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bank_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bank_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_bank_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_gov_balance_sheet, &i_gov_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'gov_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'gov_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_gov_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_ecb_balance_sheet, &i_ecb_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'ecb_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_ecb_balance_sheet);
		

			i = Eurostat_check_flow_consistency();

		
		    rc = MB_Iterator_Delete(&i_firm_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'firm_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'firm_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_household_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'household_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'household_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_igfirm_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'igfirm_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'igfirm_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_bank_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bank_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bank_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_gov_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'gov_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'gov_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_ecb_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'ecb_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'ecb_balance_sheet' iterator is invalid\n");
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
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_check_flows_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_check_flows_state, Eurostat_Eurostat_check_stocks_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_check_flow_consistency\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_ecb_balance_sheet)\n");
    rc = MB_SyncStart(b_ecb_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_ecb_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'ecb_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is locked\n");
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

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_gov_balance_sheet)\n");
    rc = MB_SyncStart(b_gov_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_gov_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'gov_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is locked\n");
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

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_bank_balance_sheet)\n");
    rc = MB_SyncStart(b_bank_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_bank_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'bank_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is locked\n");
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

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_household_balance_sheet)\n");
    rc = MB_SyncStart(b_household_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_household_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'household_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board is locked\n");
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

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_firm_balance_sheet)\n");
    rc = MB_SyncStart(b_firm_balance_sheet);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_firm_balance_sheet)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'firm_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is locked\n");
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



	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Government_yearly_resetting\n");
	current_xmachine_Government_holder = Government_09_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_end_Government_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
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
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Government_yearly_resetting\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start idle\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_check_stocks_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_end_Eurostat_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_idle_Eurostat_check_stocks_end_Eurostat(current_xmachine_Eurostat))
		{

		

			i = idle();

		

			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_check_stocks_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_check_stocks_state, Eurostat_end_Eurostat_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish idle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_ecb_balance_sheet)\n");
	rc = MB_SyncComplete(b_ecb_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_ecb_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'ecb_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_gov_balance_sheet)\n");
	rc = MB_SyncComplete(b_gov_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_gov_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'gov_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_bank_balance_sheet)\n");
	rc = MB_SyncComplete(b_bank_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_bank_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'bank_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_household_balance_sheet)\n");
	rc = MB_SyncComplete(b_household_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_household_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'household_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_firm_balance_sheet)\n");
	rc = MB_SyncComplete(b_firm_balance_sheet);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_firm_balance_sheet)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'firm_balance_sheet' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is invalid\n");
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
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start Eurostat_check_stock_consistency\n");
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_check_stocks_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_end_Eurostat_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Central_Bank = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;

		if(FLAME_condition_Eurostat_Eurostat_check_stock_consistency_Eurostat_check_stocks_end_Eurostat(current_xmachine_Eurostat))
		{

		
		
		rc = MB_Iterator_Create(b_firm_balance_sheet, &i_firm_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'firm_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'firm_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_firm_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_household_balance_sheet, &i_household_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'household_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'household_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'household_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_household_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_igfirm_balance_sheet, &i_igfirm_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'igfirm_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'igfirm_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'igfirm_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_igfirm_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_bank_balance_sheet, &i_bank_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bank_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bank_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_bank_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_gov_balance_sheet, &i_gov_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'gov_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'gov_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_gov_balance_sheet);
		
		
		rc = MB_Iterator_Create(b_ecb_balance_sheet, &i_ecb_balance_sheet);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'ecb_balance_sheet'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is locked\n");
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
		MB_Iterator_Randomise(i_ecb_balance_sheet);
		

			i = Eurostat_check_stock_consistency();

		
		    rc = MB_Iterator_Delete(&i_firm_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'firm_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'firm_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_household_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'household_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'household_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_igfirm_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'igfirm_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'igfirm_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_bank_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bank_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bank_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_gov_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'gov_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'gov_balance_sheet' iterator is invalid\n");
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
		
		    rc = MB_Iterator_Delete(&i_ecb_balance_sheet);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'ecb_balance_sheet' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'ecb_balance_sheet' iterator is invalid\n");
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
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_check_stocks_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_check_stocks_state, Eurostat_end_Eurostat_state);
			}
		}

		current_xmachine_Eurostat = NULL;

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish Eurostat_check_stock_consistency\n");




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

    rc = MB_Clear(b_wage_payment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'wage_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'wage_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'wage_payment' board is locked\n");
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

    rc = MB_Clear(b_quality_price_info_1);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'quality_price_info_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board is locked\n");
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

    rc = MB_Clear(b_quality_price_info_2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'quality_price_info_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board is locked\n");
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

    rc = MB_Clear(b_update_mall_stock);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'update_mall_stock' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'update_mall_stock' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'update_mall_stock' board is locked\n");
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

    rc = MB_Clear(b_consumption_request_1);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'consumption_request_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_1' board is locked\n");
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

    rc = MB_Clear(b_consumption_request_2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'consumption_request_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_2' board is locked\n");
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

    rc = MB_Clear(b_accepted_consumption_1);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'accepted_consumption_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is locked\n");
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

    rc = MB_Clear(b_accepted_consumption_2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'accepted_consumption_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is locked\n");
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

    rc = MB_Clear(b_sales);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'sales' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sales' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sales' board is locked\n");
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

    rc = MB_Clear(b_specific_skill_update);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'specific_skill_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'specific_skill_update' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'specific_skill_update' board is locked\n");
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

    rc = MB_Clear(b_daily_revenue_to_bank);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'daily_revenue_to_bank' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'daily_revenue_to_bank' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'daily_revenue_to_bank' board is locked\n");
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

    rc = MB_Clear(b_bank_identity);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bank_identity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_identity' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_identity' board is locked\n");
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

    rc = MB_Clear(b_bank_interest_payment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bank_interest_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_interest_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_interest_payment' board is locked\n");
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

    rc = MB_Clear(b_accountInterest);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'accountInterest' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accountInterest' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accountInterest' board is locked\n");
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

    rc = MB_Clear(b_bankruptcy_illiquidity);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bankruptcy_illiquidity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is locked\n");
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

    rc = MB_Clear(b_bankruptcy_insolvency);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bankruptcy_insolvency' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is locked\n");
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

    rc = MB_Clear(b_gov_bond);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'gov_bond' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_bond' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_bond' board is locked\n");
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

    rc = MB_Clear(b_productivity);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'productivity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'productivity' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'productivity' board is locked\n");
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

    rc = MB_Clear(b_capital_good_request);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'capital_good_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_request' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_request' board is locked\n");
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

    rc = MB_Clear(b_capital_good_profit_distribution);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'capital_good_profit_distribution' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is locked\n");
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

    rc = MB_Clear(b_capital_good_delivery);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'capital_good_delivery' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board is locked\n");
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

    rc = MB_Clear(b_dividend);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'dividend' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'dividend' board is locked\n");
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

    rc = MB_Clear(b_pay_capital_goods);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'pay_capital_goods' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board is locked\n");
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

    rc = MB_Clear(b_vacancies);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'vacancies' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies' board is locked\n");
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

    rc = MB_Clear(b_vacancies2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'vacancies2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies2' board is locked\n");
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

    rc = MB_Clear(b_firing);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'firing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firing' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firing' board is locked\n");
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

    rc = MB_Clear(b_job_application);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_application' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application' board is locked\n");
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

    rc = MB_Clear(b_job_application2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_application2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application2' board is locked\n");
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

    rc = MB_Clear(b_job_offer);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_offer' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer' board is locked\n");
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

    rc = MB_Clear(b_job_offer2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_offer2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer2' board is locked\n");
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

    rc = MB_Clear(b_job_acceptance);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance' board is locked\n");
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

    rc = MB_Clear(b_job_acceptance2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'job_acceptance2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance2' board is locked\n");
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

    rc = MB_Clear(b_quitting);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'quitting' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
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

    rc = MB_Clear(b_quitting2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'quitting2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting2' board is locked\n");
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

    rc = MB_Clear(b_firm_send_data);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'firm_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_send_data' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_send_data' board is locked\n");
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

    rc = MB_Clear(b_household_send_data);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'household_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_send_data' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_send_data' board is locked\n");
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

    rc = MB_Clear(b_mall_data);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'mall_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mall_data' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mall_data' board is locked\n");
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

    rc = MB_Clear(b_eurostat_send_specific_skills);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'eurostat_send_specific_skills' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is locked\n");
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

    rc = MB_Clear(b_mean_wage_for_government);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'mean_wage_for_government' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mean_wage_for_government' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mean_wage_for_government' board is locked\n");
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

    rc = MB_Clear(b_firm_balance_sheet);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'firm_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is locked\n");
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

    rc = MB_Clear(b_household_balance_sheet);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'household_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board is locked\n");
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

    rc = MB_Clear(b_igfirm_balance_sheet);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'igfirm_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'igfirm_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'igfirm_balance_sheet' board is locked\n");
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

    rc = MB_Clear(b_bank_balance_sheet);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bank_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is locked\n");
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

    rc = MB_Clear(b_gov_balance_sheet);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'gov_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is locked\n");
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

    rc = MB_Clear(b_ecb_balance_sheet);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'ecb_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is locked\n");
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

	/*printf("Firm_Firm_Start_Macro_Data_state->count = %d\n", Firm_Firm_Start_Macro_Data_state->count);*/
	Firm_Firm_Start_Macro_Data_state->count = 0;

	/*printf("Firm_10_state->count = %d\n", Firm_10_state->count);*/
	Firm_10_state->count = 0;

	/*printf("Firm_09b_state->count = %d\n", Firm_09b_state->count);*/
	Firm_09b_state->count = 0;

	/*printf("Firm_08_state->count = %d\n", Firm_08_state->count);*/
	Firm_08_state->count = 0;

	/*printf("Firm_07_state->count = %d\n", Firm_07_state->count);*/
	Firm_07_state->count = 0;

	/*printf("Firm_09a_state->count = %d\n", Firm_09a_state->count);*/
	Firm_09a_state->count = 0;

	/*printf("Firm_06_state->count = %d\n", Firm_06_state->count);*/
	Firm_06_state->count = 0;

	/*printf("Firm_03d_state->count = %d\n", Firm_03d_state->count);*/
	Firm_03d_state->count = 0;

	/*printf("Firm_03c_state->count = %d\n", Firm_03c_state->count);*/
	Firm_03c_state->count = 0;

	/*printf("Firm_09c_state->count = %d\n", Firm_09c_state->count);*/
	Firm_09c_state->count = 0;

	/*printf("Firm_05b_state->count = %d\n", Firm_05b_state->count);*/
	Firm_05b_state->count = 0;

	/*printf("Firm_05a_state->count = %d\n", Firm_05a_state->count);*/
	Firm_05a_state->count = 0;

	/*printf("Firm_04_state->count = %d\n", Firm_04_state->count);*/
	Firm_04_state->count = 0;

	/*printf("Firm_03ccc_state->count = %d\n", Firm_03ccc_state->count);*/
	Firm_03ccc_state->count = 0;

	/*printf("Firm_03_state->count = %d\n", Firm_03_state->count);*/
	Firm_03_state->count = 0;

	/*printf("Firm_04ccc_state->count = %d\n", Firm_04ccc_state->count);*/
	Firm_04ccc_state->count = 0;

	/*printf("Firm_011_state->count = %d\n", Firm_011_state->count);*/
	Firm_011_state->count = 0;

	/*printf("Firm_Firm_End_Macro_Data_state->count = %d\n", Firm_Firm_End_Macro_Data_state->count);*/
	Firm_Firm_End_Macro_Data_state->count = 0;

	/*printf("Firm_16_state->count = %d\n", Firm_16_state->count);*/
	Firm_16_state->count = 0;

	/*printf("Firm_15_state->count = %d\n", Firm_15_state->count);*/
	Firm_15_state->count = 0;

	/*printf("Firm_end_Firm_state->count = %d\n", Firm_end_Firm_state->count);*/
	Firm_end_Firm_state->count = 0;

	/*printf("Firm_Firm_bankrupty_state_3_state->count = %d\n", Firm_Firm_bankrupty_state_3_state->count);*/
	Firm_Firm_bankrupty_state_3_state->count = 0;

	/*printf("Firm_Firm_bankrupty_state_2_state->count = %d\n", Firm_Firm_bankrupty_state_2_state->count);*/
	Firm_Firm_bankrupty_state_2_state->count = 0;

	/*printf("Firm_Firm_is_active_state->count = %d\n", Firm_Firm_is_active_state->count);*/
	Firm_Firm_is_active_state->count = 0;

	/*printf("Firm_start_Firm_state->count = %d\n", Firm_start_Firm_state->count);*/
	Firm_start_Firm_state->count = 0;

	/*printf("Firm_Firm_bankrupty_state_1_state->count = %d\n", Firm_Firm_bankrupty_state_1_state->count);*/
	Firm_Firm_bankrupty_state_1_state->count = 0;

	/*printf("Firm_Firm_not_active_state->count = %d\n", Firm_Firm_not_active_state->count);*/
	Firm_Firm_not_active_state->count = 0;

	/*printf("Firm_005_state->count = %d\n", Firm_005_state->count);*/
	Firm_005_state->count = 0;

	/*printf("Firm_Firm_Start_Public_Sector_Role_state->count = %d\n", Firm_Firm_Start_Public_Sector_Role_state->count);*/
	Firm_Firm_Start_Public_Sector_Role_state->count = 0;

	/*printf("Firm_Firm_End_External_Financing_state->count = %d\n", Firm_Firm_End_External_Financing_state->count);*/
	Firm_Firm_End_External_Financing_state->count = 0;

	/*printf("Firm_Firm_checks_financial_crisis_state->count = %d\n", Firm_Firm_checks_financial_crisis_state->count);*/
	Firm_Firm_checks_financial_crisis_state->count = 0;

	/*printf("Firm_Firm_bankruptcy_checked_state->count = %d\n", Firm_Firm_bankruptcy_checked_state->count);*/
	Firm_Firm_bankruptcy_checked_state->count = 0;

	/*printf("Firm_End_Firm_Financial_Role_state->count = %d\n", Firm_End_Firm_Financial_Role_state->count);*/
	Firm_End_Firm_Financial_Role_state->count = 0;

	/*printf("Firm_0003_state->count = %d\n", Firm_0003_state->count);*/
	Firm_0003_state->count = 0;

	/*printf("Firm_Firm_Bankruptcy_check_state->count = %d\n", Firm_Firm_Bankruptcy_check_state->count);*/
	Firm_Firm_Bankruptcy_check_state->count = 0;

	/*printf("Firm_004_state->count = %d\n", Firm_004_state->count);*/
	Firm_004_state->count = 0;

	/*printf("Firm_003_state->count = %d\n", Firm_003_state->count);*/
	Firm_003_state->count = 0;

	/*printf("Firm_002_state->count = %d\n", Firm_002_state->count);*/
	Firm_002_state->count = 0;

	/*printf("Firm_001_state->count = %d\n", Firm_001_state->count);*/
	Firm_001_state->count = 0;

	/*printf("Firm_Firm_End_Credit_Role_state->count = %d\n", Firm_Firm_End_Credit_Role_state->count);*/
	Firm_Firm_End_Credit_Role_state->count = 0;

	/*printf("Firm_Firm_Credit_02_state->count = %d\n", Firm_Firm_Credit_02_state->count);*/
	Firm_Firm_Credit_02_state->count = 0;

	/*printf("Firm_Firm_Start_Credit_Role_state->count = %d\n", Firm_Firm_Start_Credit_Role_state->count);*/
	Firm_Firm_Start_Credit_Role_state->count = 0;

	/*printf("Firm_Firm_Start_Financial_Management_Role_state->count = %d\n", Firm_Firm_Start_Financial_Management_Role_state->count);*/
	Firm_Firm_Start_Financial_Management_Role_state->count = 0;

	/*printf("Firm_Firm_End_Financial_Management_Role_state->count = %d\n", Firm_Firm_End_Financial_Management_Role_state->count);*/
	Firm_Firm_End_Financial_Management_Role_state->count = 0;

	/*printf("Firm_14_state->count = %d\n", Firm_14_state->count);*/
	Firm_14_state->count = 0;

	/*printf("Firm_Firm_End_Seller_Role_state->count = %d\n", Firm_Firm_End_Seller_Role_state->count);*/
	Firm_Firm_End_Seller_Role_state->count = 0;

	/*printf("Firm_Firm_Start_Seller_Role_state->count = %d\n", Firm_Firm_Start_Seller_Role_state->count);*/
	Firm_Firm_Start_Seller_Role_state->count = 0;

	/*printf("Firm_12_state->count = %d\n", Firm_12_state->count);*/
	Firm_12_state->count = 0;

	/*printf("Firm_11_state->count = %d\n", Firm_11_state->count);*/
	Firm_11_state->count = 0;

	/*printf("Firm_11b_state->count = %d\n", Firm_11b_state->count);*/
	Firm_11b_state->count = 0;

	/*printf("Firm_11a_state->count = %d\n", Firm_11a_state->count);*/
	Firm_11a_state->count = 0;

	/*printf("Firm_Firm_End_Labour_Role_state->count = %d\n", Firm_Firm_End_Labour_Role_state->count);*/
	Firm_Firm_End_Labour_Role_state->count = 0;

	/*printf("Firm_Firm_Start_Labour_Role_state->count = %d\n", Firm_Firm_Start_Labour_Role_state->count);*/
	Firm_Firm_Start_Labour_Role_state->count = 0;

	/*printf("Firm_Firm_End_Financial_Management_state->count = %d\n", Firm_Firm_End_Financial_Management_state->count);*/
	Firm_Firm_End_Financial_Management_state->count = 0;

	/*printf("Firm_02_state->count = %d\n", Firm_02_state->count);*/
	Firm_02_state->count = 0;

	/*printf("Firm_00b_state->count = %d\n", Firm_00b_state->count);*/
	Firm_00b_state->count = 0;

	/*printf("Firm_01_state->count = %d\n", Firm_01_state->count);*/
	Firm_01_state->count = 0;

	/*printf("Firm_Firm_Start_Producer_Role_state->count = %d\n", Firm_Firm_Start_Producer_Role_state->count);*/
	Firm_Firm_Start_Producer_Role_state->count = 0;

	/*printf("Household_end_Household_state->count = %d\n", Household_end_Household_state->count);*/
	Household_end_Household_state->count = 0;

	/*printf("Household_Household_Start_Policy_Data_state->count = %d\n", Household_Household_Start_Policy_Data_state->count);*/
	Household_Household_Start_Policy_Data_state->count = 0;

	/*printf("Household_start_Household_state->count = %d\n", Household_start_Household_state->count);*/
	Household_start_Household_state->count = 0;

	/*printf("Household_08b_state->count = %d\n", Household_08b_state->count);*/
	Household_08b_state->count = 0;

	/*printf("Household_08_state->count = %d\n", Household_08_state->count);*/
	Household_08_state->count = 0;

	/*printf("Household_07_state->count = %d\n", Household_07_state->count);*/
	Household_07_state->count = 0;

	/*printf("Household_06e_state->count = %d\n", Household_06e_state->count);*/
	Household_06e_state->count = 0;

	/*printf("Household_06d_state->count = %d\n", Household_06d_state->count);*/
	Household_06d_state->count = 0;

	/*printf("Household_06c_state->count = %d\n", Household_06c_state->count);*/
	Household_06c_state->count = 0;

	/*printf("Household_06b_state->count = %d\n", Household_06b_state->count);*/
	Household_06b_state->count = 0;

	/*printf("Household_05_state->count = %d\n", Household_05_state->count);*/
	Household_05_state->count = 0;

	/*printf("Household_04_state->count = %d\n", Household_04_state->count);*/
	Household_04_state->count = 0;

	/*printf("Household_03_state->count = %d\n", Household_03_state->count);*/
	Household_03_state->count = 0;

	/*printf("Household_02_state->count = %d\n", Household_02_state->count);*/
	Household_02_state->count = 0;

	/*printf("Household_06_state->count = %d\n", Household_06_state->count);*/
	Household_06_state->count = 0;

	/*printf("Household_01_state->count = %d\n", Household_01_state->count);*/
	Household_01_state->count = 0;

	/*printf("Household_01a_state->count = %d\n", Household_01a_state->count);*/
	Household_01a_state->count = 0;

	/*printf("Household_01d_state->count = %d\n", Household_01d_state->count);*/
	Household_01d_state->count = 0;

	/*printf("Household_Household_Start_Labour_Role_state->count = %d\n", Household_Household_Start_Labour_Role_state->count);*/
	Household_Household_Start_Labour_Role_state->count = 0;

	/*printf("Household_Household_Start_Financial_Market_Role_state->count = %d\n", Household_Household_Start_Financial_Market_Role_state->count);*/
	Household_Household_Start_Financial_Market_Role_state->count = 0;

	/*printf("Household_12_state->count = %d\n", Household_12_state->count);*/
	Household_12_state->count = 0;

	/*printf("Household_14_state->count = %d\n", Household_14_state->count);*/
	Household_14_state->count = 0;

	/*printf("Household_11_state->count = %d\n", Household_11_state->count);*/
	Household_11_state->count = 0;

	/*printf("Household_10_state->count = %d\n", Household_10_state->count);*/
	Household_10_state->count = 0;

	/*printf("Household_09b_state->count = %d\n", Household_09b_state->count);*/
	Household_09b_state->count = 0;

	/*printf("Household_15_state->count = %d\n", Household_15_state->count);*/
	Household_15_state->count = 0;

	/*printf("Household_09_state->count = %d\n", Household_09_state->count);*/
	Household_09_state->count = 0;

	/*printf("Mall_end_Mall_state->count = %d\n", Mall_end_Mall_state->count);*/
	Mall_end_Mall_state->count = 0;

	/*printf("Mall_06_state->count = %d\n", Mall_06_state->count);*/
	Mall_06_state->count = 0;

	/*printf("Mall_05a_state->count = %d\n", Mall_05a_state->count);*/
	Mall_05a_state->count = 0;

	/*printf("Mall_05_state->count = %d\n", Mall_05_state->count);*/
	Mall_05_state->count = 0;

	/*printf("Mall_04_state->count = %d\n", Mall_04_state->count);*/
	Mall_04_state->count = 0;

	/*printf("Mall_03_state->count = %d\n", Mall_03_state->count);*/
	Mall_03_state->count = 0;

	/*printf("Mall_02_state->count = %d\n", Mall_02_state->count);*/
	Mall_02_state->count = 0;

	/*printf("Mall_01_state->count = %d\n", Mall_01_state->count);*/
	Mall_01_state->count = 0;

	/*printf("Mall_start_Mall_state->count = %d\n", Mall_start_Mall_state->count);*/
	Mall_start_Mall_state->count = 0;

	/*printf("IGFirm_start_IGFirm_state->count = %d\n", IGFirm_start_IGFirm_state->count);*/
	IGFirm_start_IGFirm_state->count = 0;

	/*printf("IGFirm_end_IGFirm_state->count = %d\n", IGFirm_end_IGFirm_state->count);*/
	IGFirm_end_IGFirm_state->count = 0;

	/*printf("IGFirm_04b_state->count = %d\n", IGFirm_04b_state->count);*/
	IGFirm_04b_state->count = 0;

	/*printf("IGFirm_04_state->count = %d\n", IGFirm_04_state->count);*/
	IGFirm_04_state->count = 0;

	/*printf("IGFirm_03_state->count = %d\n", IGFirm_03_state->count);*/
	IGFirm_03_state->count = 0;

	/*printf("IGFirm_02_state->count = %d\n", IGFirm_02_state->count);*/
	IGFirm_02_state->count = 0;

	/*printf("IGFirm_01_state->count = %d\n", IGFirm_01_state->count);*/
	IGFirm_01_state->count = 0;

	/*printf("IGFirm_Start_IGFirm_Productivity_state->count = %d\n", IGFirm_Start_IGFirm_Productivity_state->count);*/
	IGFirm_Start_IGFirm_Productivity_state->count = 0;

	/*printf("Eurostat_end_Eurostat_state->count = %d\n", Eurostat_end_Eurostat_state->count);*/
	Eurostat_end_Eurostat_state->count = 0;

	/*printf("Eurostat_Eurostat_check_stocks_state->count = %d\n", Eurostat_Eurostat_check_stocks_state->count);*/
	Eurostat_Eurostat_check_stocks_state->count = 0;

	/*printf("Eurostat_Eurostat_check_flows_state->count = %d\n", Eurostat_Eurostat_check_flows_state->count);*/
	Eurostat_Eurostat_check_flows_state->count = 0;

	/*printf("Eurostat_Eurostat_Start_EndOfYear_Loop_state->count = %d\n", Eurostat_Eurostat_Start_EndOfYear_Loop_state->count);*/
	Eurostat_Eurostat_Start_EndOfYear_Loop_state->count = 0;

	/*printf("Eurostat_05_state->count = %d\n", Eurostat_05_state->count);*/
	Eurostat_05_state->count = 0;

	/*printf("Eurostat_04_state->count = %d\n", Eurostat_04_state->count);*/
	Eurostat_04_state->count = 0;

	/*printf("Eurostat_Eurostat_Start_Quarterly_Loop_state->count = %d\n", Eurostat_Eurostat_Start_Quarterly_Loop_state->count);*/
	Eurostat_Eurostat_Start_Quarterly_Loop_state->count = 0;

	/*printf("Eurostat_02_state->count = %d\n", Eurostat_02_state->count);*/
	Eurostat_02_state->count = 0;

	/*printf("Eurostat_Eurostat_Start_Monthly_Loop_state->count = %d\n", Eurostat_Eurostat_Start_Monthly_Loop_state->count);*/
	Eurostat_Eurostat_Start_Monthly_Loop_state->count = 0;

	/*printf("Eurostat_01_state->count = %d\n", Eurostat_01_state->count);*/
	Eurostat_01_state->count = 0;

	/*printf("Eurostat_start_Eurostat_state->count = %d\n", Eurostat_start_Eurostat_state->count);*/
	Eurostat_start_Eurostat_state->count = 0;

	/*printf("Bank_start_Bank_state->count = %d\n", Bank_start_Bank_state->count);*/
	Bank_start_Bank_state->count = 0;

	/*printf("Bank_end_Bank_cycle_state->count = %d\n", Bank_end_Bank_cycle_state->count);*/
	Bank_end_Bank_cycle_state->count = 0;

	/*printf("Bank_Bank_07_state->count = %d\n", Bank_Bank_07_state->count);*/
	Bank_Bank_07_state->count = 0;

	/*printf("Bank_Bank_06_state->count = %d\n", Bank_Bank_06_state->count);*/
	Bank_Bank_06_state->count = 0;

	/*printf("Bank_Bank_05_state->count = %d\n", Bank_Bank_05_state->count);*/
	Bank_Bank_05_state->count = 0;

	/*printf("Bank_Bank_04_state->count = %d\n", Bank_Bank_04_state->count);*/
	Bank_Bank_04_state->count = 0;

	/*printf("Bank_Bank_03_state->count = %d\n", Bank_Bank_03_state->count);*/
	Bank_Bank_03_state->count = 0;

	/*printf("Bank_Bank_02_state->count = %d\n", Bank_Bank_02_state->count);*/
	Bank_Bank_02_state->count = 0;

	/*printf("Bank_Bank_01_state->count = %d\n", Bank_Bank_01_state->count);*/
	Bank_Bank_01_state->count = 0;

	/*printf("Bank_Bank_start_credit_market_role_state->count = %d\n", Bank_Bank_start_credit_market_role_state->count);*/
	Bank_Bank_start_credit_market_role_state->count = 0;

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

	/*printf("Government_04b_state->count = %d\n", Government_04b_state->count);*/
	Government_04b_state->count = 0;

	/*printf("Government_04_state->count = %d\n", Government_04_state->count);*/
	Government_04_state->count = 0;

	/*printf("Government_03_state->count = %d\n", Government_03_state->count);*/
	Government_03_state->count = 0;

	/*printf("Government_02_state->count = %d\n", Government_02_state->count);*/
	Government_02_state->count = 0;

	/*printf("Government_start_Government_state->count = %d\n", Government_start_Government_state->count);*/
	Government_start_Government_state->count = 0;

	/*printf("Government_01_state->count = %d\n", Government_01_state->count);*/
	Government_01_state->count = 0;

	/*printf("Government_Gov_Start_Bond_Market_state->count = %d\n", Government_Gov_Start_Bond_Market_state->count);*/
	Government_Gov_Start_Bond_Market_state->count = 0;

	/*printf("Central_Bank_start_Central_Bank_state->count = %d\n", Central_Bank_start_Central_Bank_state->count);*/
	Central_Bank_start_Central_Bank_state->count = 0;

	/*printf("Central_Bank_end_Central_Bank_state->count = %d\n", Central_Bank_end_Central_Bank_state->count);*/
	Central_Bank_end_Central_Bank_state->count = 0;

	/*printf("Central_Bank_01_state->count = %d\n", Central_Bank_01_state->count);*/
	Central_Bank_01_state->count = 0;

	/*printf("Central_Bank_00_state->count = %d\n", Central_Bank_00_state->count);*/
	Central_Bank_00_state->count = 0;

	/*printf("Clearinghouse_end_Clearinghouse_state->count = %d\n", Clearinghouse_end_Clearinghouse_state->count);*/
	Clearinghouse_end_Clearinghouse_state->count = 0;

	/*printf("Clearinghouse_COMPUTEDPRICES_state->count = %d\n", Clearinghouse_COMPUTEDPRICES_state->count);*/
	Clearinghouse_COMPUTEDPRICES_state->count = 0;

	/*printf("Clearinghouse_RECEIVEDINFOSTOCK_state->count = %d\n", Clearinghouse_RECEIVEDINFOSTOCK_state->count);*/
	Clearinghouse_RECEIVEDINFOSTOCK_state->count = 0;

	/*printf("Clearinghouse_start_Clearinghouse_state->count = %d\n", Clearinghouse_start_Clearinghouse_state->count);*/
	Clearinghouse_start_Clearinghouse_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_Firm_holder = Firm_end_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		transition_Firm_agent(current_xmachine_Firm_holder, Firm_end_Firm_state, Firm_start_Firm_state);

		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}

	current_xmachine_Household_holder = Household_end_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		transition_Household_agent(current_xmachine_Household_holder, Household_end_Household_state, Household_start_Household_state);

		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}

	current_xmachine_Mall_holder = Mall_end_Mall_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		transition_Mall_agent(current_xmachine_Mall_holder, Mall_end_Mall_state, Mall_start_Mall_state);

		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}

	current_xmachine_IGFirm_holder = IGFirm_end_IGFirm_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_end_IGFirm_state, IGFirm_start_IGFirm_state);

		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}

	current_xmachine_Eurostat_holder = Eurostat_end_Eurostat_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_end_Eurostat_state, Eurostat_start_Eurostat_state);

		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}

	current_xmachine_Bank_holder = Bank_end_Bank_cycle_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		transition_Bank_agent(current_xmachine_Bank_holder, Bank_end_Bank_cycle_state, Bank_start_Bank_state);

		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
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

	current_xmachine_Clearinghouse_holder = Clearinghouse_end_Clearinghouse_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_end_Clearinghouse_state, Clearinghouse_start_Clearinghouse_state);

		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
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
