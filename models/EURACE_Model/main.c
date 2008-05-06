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
	//xmachine_memory_Household * temp_xmachine_Household;
	//xmachine_memory_Mall * temp_xmachine_Mall;
	//xmachine_memory_IGFirm * temp_xmachine_IGFirm;
	//xmachine_memory_Eurostat * temp_xmachine_Eurostat;
	//xmachine_memory_Clearinghouse * temp_xmachine_Clearinghouse;
	//xmachine_memory_Bank * temp_xmachine_Bank;
	//xmachine_memory_Government * temp_xmachine_Government;
	
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


	printf("FLAME Application: Financial_Market \n");





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
       }
    }
    #endif
	
	
	current_xmachine_Government_holder = Government_start_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		current_xmachine_Government = current_xmachine_Government_holder->agent;
		current_xmachine_Government_next_state = Government_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Government = current_xmachine_Government;
		
		
		
		
		
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
		   }
		}
		#endif
		
		
			i = Government_read_tax_payment();
			
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Government_agent(current_xmachine_Government_holder, Government_start_Government_state);
			}
			else
			{
				transition_Government_agent(current_xmachine_Government_holder, Government_start_Government_state, Government_end_state);
			}
		
		
		current_xmachine_Government = NULL;
		
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}



	rc = MB_SyncComplete(b_interest_payment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'interest_payment' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interest_payment' board is invalid\n");
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
	
	
	current_xmachine_Bank_holder = Bank_start_Bank_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;
		
		
		
		
		
		rc = MB_Iterator_Create(b_interest_payment, &i_interest_payment);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'interest_payment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'interest_payment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'interest_payment' board is locked\n");
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
		
		
			i = Bank_read_interest_payments();
			
		
		    rc = MB_Iterator_Delete(&i_interest_payment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'interest_payment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'interest_payment' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Bank_agent(current_xmachine_Bank_holder, Bank_start_Bank_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_start_Bank_state, Bank_01_state);
			}
		
		
		current_xmachine_Bank = NULL;
		
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}



	
	current_xmachine_Eurostat_holder = Eurostat_start_Market_Research_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;
		
		if(Eurostat_Market_Research_idle_start_Market_Research_01_condition(current_xmachine_Eurostat))
		{
		
		
		
			i = Market_Research_idle();
			
		
		
			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_start_Market_Research_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_start_Market_Research_state, Eurostat_01_state);
			}
		}
		
		current_xmachine_Eurostat = NULL;
		
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}



	
	current_xmachine_Eurostat_holder = Eurostat_start_Market_Research_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;
		
		if(Eurostat_Market_Research_Initialization_start_Market_Research_01_condition(current_xmachine_Eurostat))
		{
		
		
		
			i = Market_Research_Initialization();
			
		
		
			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_start_Market_Research_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_start_Market_Research_state, Eurostat_01_state);
			}
		}
		
		current_xmachine_Eurostat = NULL;
		
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}



	
	current_xmachine_IGFirm_holder = IGFirm_start_IGFirm_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;
		
		if(IGFirm_IGFirm_idle_start_IGFirm_01_condition(current_xmachine_IGFirm))
		{
		
		
		
			i = IGFirm_idle();
			
		
		
			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_start_IGFirm_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_start_IGFirm_state, IGFirm_01_state);
			}
		}
		
		current_xmachine_IGFirm = NULL;
		
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}



	
	current_xmachine_IGFirm_holder = IGFirm_start_IGFirm_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_IGFirm = current_xmachine_IGFirm;
		
		if(IGFirm_IGFirm_update_productivity_price_start_IGFirm_01_condition(current_xmachine_IGFirm))
		{
		
		
		
			i = IGFirm_update_productivity_price();
			
		
		
			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_start_IGFirm_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_start_IGFirm_state, IGFirm_01_state);
			}
		}
		
		current_xmachine_IGFirm = NULL;
		
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}



	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;
		
		
		
		
		
			i = Mall_send_current_stocks();
			
		
		
			if(i == 1)
			{
				free_Mall_agent(current_xmachine_Mall_holder, Mall_start_Mall_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_start_Mall_state, Mall_01_state);
			}
		
		
		current_xmachine_Mall = NULL;
		
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
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
       }
    }
    #endif


	
	current_xmachine_Household_holder = Household_start_Household_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_idle_start_Household_01a_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_idle();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_start_Household_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_start_Household_state, Household_01a_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	
	current_xmachine_Firm_holder = Firm_start_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_00_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_idle_start_Firm_00_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_idle();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state, Firm_00_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	rc = MB_SyncComplete(b_debt_installment_payment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'debt_installment_payment' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'debt_installment_payment' board is invalid\n");
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Bank = current_xmachine_Bank;
		
		
		
		
		
		rc = MB_Iterator_Create(b_debt_installment_payment, &i_debt_installment_payment);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'debt_installment_payment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'debt_installment_payment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'debt_installment_payment' board is locked\n");
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
		
		
			i = Bank_read_debt_installment_payments();
			
		
		    rc = MB_Iterator_Delete(&i_debt_installment_payment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'debt_installment_payment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'debt_installment_payment' iterator is invalid\n");
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



	
	current_xmachine_Eurostat_holder = Eurostat_01_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;
		
		if(Eurostat_Market_Research_idle_01_02_condition(current_xmachine_Eurostat))
		{
		
		
		
			i = Market_Research_idle();
			
		
		
			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_01_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_01_state, Eurostat_02_state);
			}
		}
		
		current_xmachine_Eurostat = NULL;
		
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}



	
	current_xmachine_Eurostat_holder = Eurostat_01_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;
		
		if(Eurostat_Market_Research_send_data_01_02_condition(current_xmachine_Eurostat))
		{
		
		
		
			i = Market_Research_send_data();
			
		
		
			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_01_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_01_state, Eurostat_02_state);
			}
		}
		
		current_xmachine_Eurostat = NULL;
		
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}


    rc = MB_SyncStart(b_market_research_send_specific_skills);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'market_research_send_specific_skills' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'market_research_send_specific_skills' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'market_research_send_specific_skills' board is locked\n");
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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


    rc = MB_SyncStart(b_productivity);
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
       }
    }
    #endif



	
	current_xmachine_Eurostat_holder = Eurostat_02_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;
		
		if(Eurostat_Market_Research_idle_02_end_condition(current_xmachine_Eurostat))
		{
		
		
		
			i = Market_Research_idle();
			
		
		
			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_02_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_02_state, Eurostat_end_state);
			}
		}
		
		current_xmachine_Eurostat = NULL;
		
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}



	rc = MB_SyncComplete(b_market_research_send_specific_skills);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'market_research_send_specific_skills' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'market_research_send_specific_skills' board is invalid\n");
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
	
	
	current_xmachine_Firm_holder = Firm_start_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_00_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_receive_data_start_Firm_00_condition(current_xmachine_Firm))
		{
		
		
		
		rc = MB_Iterator_Create(b_market_research_send_specific_skills, &i_market_research_send_specific_skills);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'market_research_send_specific_skills'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'market_research_send_specific_skills' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'market_research_send_specific_skills' board is locked\n");
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
		
		
			i = Firm_receive_data();
			
		
		    rc = MB_Iterator_Delete(&i_market_research_send_specific_skills);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'market_research_send_specific_skills' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'market_research_send_specific_skills' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state, Firm_00_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	
	current_xmachine_Firm_holder = Firm_00_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_compute_income_statement_00_001_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_compute_income_statement();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_00_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_00_state, Firm_001_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}



	
	current_xmachine_Firm_holder = Firm_00_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_set_quantities_zero_00_00b_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_set_quantities_zero();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_00_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_00_state, Firm_00b_state);
			}
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_compute_financial_payments();
			
		
		
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
       }
    }
    #endif
	
	
	current_xmachine_Firm_holder = Firm_002_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
		rc = MB_Iterator_Create(b_current_mall_stock_info, &i_current_mall_stock_info);
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
		   }
		}
		#endif
		
		
			i = Firm_calc_production_quantity();
			
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_002_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_002_state, Firm_01_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	rc = MB_SyncComplete(b_productivity);
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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




	
	current_xmachine_Firm_holder = Firm_02_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_compute_balance_sheet();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_02_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_02_state, Firm_003_state);
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_check_solvency();
			
		
		
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




	
	current_xmachine_Firm_holder = Firm_004_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_20_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_compute_financial_needs();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_004_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_004_state, Firm_20_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	
	current_xmachine_Firm_holder = Firm_20_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_27_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_idle_20_27_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_idle();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_20_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_20_state, Firm_27_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}



	
	current_xmachine_Firm_holder = Firm_20_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_21_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_apply_for_loans_20_21_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_apply_for_loans();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_20_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_20_state, Firm_21_state);
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
       }
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		
		
			i = Bank_read_loan_request_send_offers();
			
		
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
				free_Bank_agent(current_xmachine_Bank_holder, Bank_02_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_02_state, Bank_03_state);
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
	
	
	current_xmachine_Firm_holder = Firm_21_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_22_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		
		
			i = Firm_read_loan_offers_send_loan_acceptance();
			
		
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
				free_Firm_agent(current_xmachine_Firm_holder, Firm_21_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_21_state, Firm_22_state);
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
	
	
	current_xmachine_Bank_holder = Bank_03_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		current_xmachine_Bank = current_xmachine_Bank_holder->agent;
		current_xmachine_Bank_next_state = Bank_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		
		
			i = Bank_read_loan_acceptance();
			
		
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
				free_Bank_agent(current_xmachine_Bank_holder, Bank_03_state);
			}
			else
			{
				transition_Bank_agent(current_xmachine_Bank_holder, Bank_03_state, Bank_04_state);
			}
		
		
		current_xmachine_Bank = NULL;
		
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}



	
	current_xmachine_Firm_holder = Firm_22_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_23_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_compute_and_send_bond_orders_22_23_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_compute_and_send_bond_orders();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_22_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_22_state, Firm_23_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_bond_order);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'bond_order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bond_order' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bond_order' board is locked\n");
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


	
	current_xmachine_Firm_holder = Firm_22_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_27_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_idle_22_27_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_idle();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_22_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_22_state, Firm_27_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	rc = MB_SyncComplete(b_bond_order);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'bond_order' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bond_order' board is invalid\n");
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
	
	
	current_xmachine_Clearinghouse_holder = Clearinghouse_start_Clearinghouse_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		current_xmachine_Clearinghouse = current_xmachine_Clearinghouse_holder->agent;
		current_xmachine_Clearinghouse_next_state = Clearinghouse_01_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Clearinghouse = current_xmachine_Clearinghouse;
		
		
		
		
		
		rc = MB_Iterator_Create(b_bond_order, &i_bond_order);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bond_order'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bond_order' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bond_order' board is locked\n");
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
		
		
			i = Clearinghouse_read_bond_orders();
			
		
		    rc = MB_Iterator_Delete(&i_bond_order);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bond_order' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bond_order' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_start_Clearinghouse_state);
			}
			else
			{
				transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_start_Clearinghouse_state, Clearinghouse_01_state);
			}
		
		
		current_xmachine_Clearinghouse = NULL;
		
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}




	
	current_xmachine_Clearinghouse_holder = Clearinghouse_01_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		current_xmachine_Clearinghouse = current_xmachine_Clearinghouse_holder->agent;
		current_xmachine_Clearinghouse_next_state = Clearinghouse_02_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Clearinghouse = current_xmachine_Clearinghouse;
		
		
		
		
		
			i = Clearinghouse_compute_bond_transactions();
			
		
		
			if(i == 1)
			{
				free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_01_state);
			}
			else
			{
				transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_01_state, Clearinghouse_02_state);
			}
		
		
		current_xmachine_Clearinghouse = NULL;
		
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}




	
	current_xmachine_Clearinghouse_holder = Clearinghouse_02_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		current_xmachine_Clearinghouse = current_xmachine_Clearinghouse_holder->agent;
		current_xmachine_Clearinghouse_next_state = Clearinghouse_03_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Clearinghouse = current_xmachine_Clearinghouse;
		
		
		
		
		
			i = Clearinghouse_send_bond_transactions();
			
		
		
			if(i == 1)
			{
				free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_02_state);
			}
			else
			{
				transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_02_state, Clearinghouse_03_state);
			}
		
		
		current_xmachine_Clearinghouse = NULL;
		
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}


    rc = MB_SyncStart(b_bond_transaction);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'bond_transaction' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bond_transaction' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bond_transaction' board is locked\n");
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



	rc = MB_SyncComplete(b_bond_transaction);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'bond_transaction' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bond_transaction' board is invalid\n");
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
	
	
	current_xmachine_Firm_holder = Firm_23_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_24_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
		rc = MB_Iterator_Create(b_bond_transaction, &i_bond_transaction);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'bond_transaction'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'bond_transaction' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bond_transaction' board is locked\n");
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
		
		
			i = Firm_read_bond_transactions();
			
		
		    rc = MB_Iterator_Delete(&i_bond_transaction);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'bond_transaction' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'bond_transaction' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_23_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_23_state, Firm_24_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	
	current_xmachine_Firm_holder = Firm_24_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_25_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_compute_and_send_stock_orders_24_25_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_compute_and_send_stock_orders();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_24_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_24_state, Firm_25_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_stock_order);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'stock_order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'stock_order' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'stock_order' board is locked\n");
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


	
	current_xmachine_Firm_holder = Firm_24_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_27_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_idle_24_27_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_idle();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_24_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_24_state, Firm_27_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	rc = MB_SyncComplete(b_stock_order);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'stock_order' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'stock_order' board is invalid\n");
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
	
	
	current_xmachine_Clearinghouse_holder = Clearinghouse_03_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		current_xmachine_Clearinghouse = current_xmachine_Clearinghouse_holder->agent;
		current_xmachine_Clearinghouse_next_state = Clearinghouse_04_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Clearinghouse = current_xmachine_Clearinghouse;
		
		
		
		
		
		rc = MB_Iterator_Create(b_stock_order, &i_stock_order);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'stock_order'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'stock_order' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'stock_order' board is locked\n");
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
		
		
			i = Clearinghouse_read_stock_orders();
			
		
		    rc = MB_Iterator_Delete(&i_stock_order);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'stock_order' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'stock_order' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_03_state);
			}
			else
			{
				transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_03_state, Clearinghouse_04_state);
			}
		
		
		current_xmachine_Clearinghouse = NULL;
		
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}




	
	current_xmachine_Clearinghouse_holder = Clearinghouse_04_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		current_xmachine_Clearinghouse = current_xmachine_Clearinghouse_holder->agent;
		current_xmachine_Clearinghouse_next_state = Clearinghouse_05_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Clearinghouse = current_xmachine_Clearinghouse;
		
		
		
		
		
			i = Clearinghouse_compute_stock_transactions();
			
		
		
			if(i == 1)
			{
				free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_04_state);
			}
			else
			{
				transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_04_state, Clearinghouse_05_state);
			}
		
		
		current_xmachine_Clearinghouse = NULL;
		
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}




	
	current_xmachine_Clearinghouse_holder = Clearinghouse_05_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		current_xmachine_Clearinghouse = current_xmachine_Clearinghouse_holder->agent;
		current_xmachine_Clearinghouse_next_state = Clearinghouse_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Clearinghouse = current_xmachine_Clearinghouse;
		
		
		
		
		
			i = Clearinghouse_send_stock_transactions();
			
		
		
			if(i == 1)
			{
				free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_05_state);
			}
			else
			{
				transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_05_state, Clearinghouse_end_state);
			}
		
		
		current_xmachine_Clearinghouse = NULL;
		
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}


    rc = MB_SyncStart(b_stock_transaction);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'stock_transaction' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'stock_transaction' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'stock_transaction' board is locked\n");
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



	rc = MB_SyncComplete(b_stock_transaction);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'stock_transaction' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'stock_transaction' board is invalid\n");
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
	
	
	current_xmachine_Firm_holder = Firm_25_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_26_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
		rc = MB_Iterator_Create(b_stock_transaction, &i_stock_transaction);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'stock_transaction'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'stock_transaction' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'stock_transaction' board is locked\n");
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
		
		
			i = Firm_read_stock_transactions();
			
		
		    rc = MB_Iterator_Delete(&i_stock_transaction);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'stock_transaction' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'stock_transaction' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_25_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_25_state, Firm_26_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	
	current_xmachine_Firm_holder = Firm_26_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_27_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_idle_26_27_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_idle();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_26_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_26_state, Firm_27_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}



	
	current_xmachine_Firm_holder = Firm_26_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_261_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_calc_production_quantity_2_26_261_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_calc_production_quantity_2();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_26_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_26_state, Firm_261_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	
	current_xmachine_Firm_holder = Firm_261_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_27_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_execute_financial_payments();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_261_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_261_state, Firm_27_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	
	current_xmachine_Firm_holder = Firm_27_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_28_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_calculate_specific_skills_and_wage_offer();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_27_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_27_state, Firm_28_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	
	current_xmachine_Firm_holder = Firm_28_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_idle_28_03c_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_idle();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_28_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_28_state, Firm_03c_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}



	
	current_xmachine_Firm_holder = Firm_28_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_send_redundancies_28_03c_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_send_redundancies();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_28_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_28_state, Firm_03c_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_firing);
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
       }
    }
    #endif


	
	current_xmachine_Firm_holder = Firm_28_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_send_vacancies_28_03_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_send_vacancies();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_28_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_28_state, Firm_03_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_vacancies);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_firing);
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
       }
    }
    #endif
	
	
	current_xmachine_Household_holder = Household_start_Household_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_read_firing_messages_start_Household_01d_condition(current_xmachine_Household))
		{
		
		
		
		rc = MB_Iterator_Create(b_firing, &i_firing);
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
		   }
		}
		#endif
		
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_start_Household_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_start_Household_state, Household_01d_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}




	
	current_xmachine_Household_holder = Household_01d_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_01b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_on_the_job_search_decision_01d_01b_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_on_the_job_search_decision();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_01d_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01d_state, Household_01b_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_made_unemployed_01d_01a_condition(current_xmachine_Household))
		{
		
		
		
		rc = MB_Iterator_Create(b_firing, &i_firing);
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
		   }
		}
		#endif
		
		
			i = Household_made_unemployed();
			
		
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
		       }
		    }
		    #endif
		
		
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




	
	current_xmachine_Household_holder = Household_01b_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_on_the_job_search_no_01b_06_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_on_the_job_search_no();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_01b_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01b_state, Household_06_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	
	current_xmachine_Household_holder = Household_01b_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_01e_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_on_the_job_search_yes_01b_01e_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_on_the_job_search_yes();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_01b_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01b_state, Household_01e_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	rc = MB_SyncComplete(b_vacancies);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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




	
	current_xmachine_Household_holder = Household_01e_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
			i = Household_OTJS_read_job_vacancies_and_send_applications();
			
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_01e_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_01e_state, Household_01_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}


    rc = MB_SyncStart(b_job_application);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_job_application);
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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


    rc = MB_SyncStart(b_job_offer);
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
       }
    }
    #endif

    rc = MB_SyncStart(b_application_rejection);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'application_rejection' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'application_rejection' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'application_rejection' board is locked\n");
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



	rc = MB_SyncComplete(b_job_offer);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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


    rc = MB_SyncStart(b_job_acceptance);
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
       }
    }
    #endif

    rc = MB_SyncStart(b_quitting);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_application_rejection);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'application_rejection' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'application_rejection' board is invalid\n");
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_read_application_rejection_update_wage_reservation_02_03_condition(current_xmachine_Household))
		{
		
		
		
		rc = MB_Iterator_Create(b_application_rejection, &i_application_rejection);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'application_rejection'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'application_rejection' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'application_rejection' board is locked\n");
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
		
		
			i = Household_read_application_rejection_update_wage_reservation();
			
		
		    rc = MB_Iterator_Delete(&i_application_rejection);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'application_rejection' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'application_rejection' iterator is invalid\n");
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
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_finish_labour_market_02_06_condition(current_xmachine_Household))
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



	rc = MB_SyncComplete(b_quitting);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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



	rc = MB_SyncComplete(b_job_acceptance);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_finish_labour_market_first_round_03d_09a_condition(current_xmachine_Firm))
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_start_labour_market_03d_06_condition(current_xmachine_Firm))
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_update_wage_offer_05b_06_condition(current_xmachine_Firm))
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_finish_labour_market_first_round_05b_09a_condition(current_xmachine_Firm))
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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


    rc = MB_SyncStart(b_vacancies2);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_vacancies2);
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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



	
	current_xmachine_Household_holder = Household_02_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_OTJS_read_job_vacancies_and_send_applications_2_02_04_condition(current_xmachine_Household))
		{
		
		
		
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
		   }
		}
		#endif
		
		
			i = Household_OTJS_read_job_vacancies_and_send_applications_2();
			
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_02_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_02_state, Household_04_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}


    rc = MB_SyncStart(b_job_application2);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_job_application2);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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


    rc = MB_SyncStart(b_job_offer2);
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
       }
    }
    #endif

    rc = MB_SyncStart(b_application_rejection2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'application_rejection2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'application_rejection2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'application_rejection2' board is locked\n");
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



	rc = MB_SyncComplete(b_job_offer2);
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
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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


    rc = MB_SyncStart(b_job_acceptance2);
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
       }
    }
    #endif

    rc = MB_SyncStart(b_quitting2);
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
       }
    }
    #endif



	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_idle_05_06_condition(current_xmachine_Household))
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



	rc = MB_SyncComplete(b_application_rejection2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'application_rejection2' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'application_rejection2' board is invalid\n");
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_read_application_rejection_update_wage_reservation_2_05_06_condition(current_xmachine_Household))
		{
		
		
		
		rc = MB_Iterator_Create(b_application_rejection2, &i_application_rejection2);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'application_rejection2'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'application_rejection2' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'application_rejection2' board is locked\n");
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
		
		
			i = Household_read_application_rejection_update_wage_reservation_2();
			
		
		    rc = MB_Iterator_Delete(&i_application_rejection2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'application_rejection2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'application_rejection2' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
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



	rc = MB_SyncComplete(b_quitting2);
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
       }
    }
    #endif
	
	
	current_xmachine_Firm_holder = Firm_09c_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_13_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_09c_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_09c_state, Firm_13_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}



	rc = MB_SyncComplete(b_job_acceptance2);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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




	
	current_xmachine_Household_holder = Household_06_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_receive_unemployment_benefits_06_08_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_receive_unemployment_benefits();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_06_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06_state, Household_08_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	
	current_xmachine_Household_holder = Household_06_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_idle_06_09_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_idle();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_06_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06_state, Household_09_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_idle_09b_10_condition(current_xmachine_Firm))
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_update_wage_offer_2_09b_10_condition(current_xmachine_Firm))
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




	
	current_xmachine_Firm_holder = Firm_10_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_send_capital_demand();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_10_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_10_state, Firm_11_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_capital_good_request);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_capital_good_request);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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


    rc = MB_SyncStart(b_capital_good_delivery);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_capital_good_delivery);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
		rc = MB_Iterator_Create(b_capital_good_delivery, &i_capital_good_delivery);
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
		   }
		}
		#endif
		
		
			i = Firm_calc_pay_costs();
			
		
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
		       }
		    }
		    #endif
		
		
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


    rc = MB_SyncStart(b_wage_payment);
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
       }
    }
    #endif

    rc = MB_SyncStart(b_pay_capital_goods);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_pay_capital_goods);
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
       }
    }
    #endif
	
	
	current_xmachine_IGFirm_holder = IGFirm_03_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		current_xmachine_IGFirm = current_xmachine_IGFirm_holder->agent;
		current_xmachine_IGFirm_next_state = IGFirm_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_03_state);
			}
			else
			{
				transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_03_state, IGFirm_end_state);
			}
		
		
		current_xmachine_IGFirm = NULL;
		
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}


    rc = MB_SyncStart(b_capital_good_profit_distribution);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'capital_good_profit_distribution' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is locked\n");
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


	rc = MB_SyncComplete(b_wage_payment);
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
       }
    }
    #endif
	
	
	current_xmachine_Household_holder = Household_06_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_receive_wage_06_07_condition(current_xmachine_Household))
		{
		
		
		
		rc = MB_Iterator_Create(b_wage_payment, &i_wage_payment);
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
		   }
		}
		#endif
		
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_06_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_06_state, Household_07_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	
	current_xmachine_Firm_holder = Firm_12_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_13_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
			i = Firm_send_goods_to_mall();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_12_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_12_state, Firm_13_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_update_mall_stock);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_update_mall_stock);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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
		   }
		}
		#endif
		
		
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
		       }
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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


    rc = MB_SyncStart(b_specific_skill_update);
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
       }
    }
    #endif



	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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


    rc = MB_SyncStart(b_quality_price_info_1);
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
       }
    }
    #endif


	
	current_xmachine_Household_holder = Household_08_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
			i = Household_determine_consumption_budget();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_08_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_08_state, Household_09_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}




	rc = MB_SyncComplete(b_quality_price_info_1);
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
       }
    }
    #endif
	
	
	current_xmachine_Household_holder = Household_09_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_rank_and_buy_goods_1_09_10_condition(current_xmachine_Household))
		{
		
		
		
		rc = MB_Iterator_Create(b_quality_price_info_1, &i_quality_price_info_1);
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
		   }
		}
		#endif
		
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_09_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_09_state, Household_10_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}


    rc = MB_SyncStart(b_consumption_request_1);
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
       }
    }
    #endif


	rc = MB_SyncComplete(b_capital_good_profit_distribution);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'capital_good_profit_distribution' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is invalid\n");
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
	
	rc = MB_SyncComplete(b_dividend_payment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'dividend_payment' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_payment' board is invalid\n");
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_receicve_dividends_09_15_condition(current_xmachine_Household))
		{
		
		
		
		rc = MB_Iterator_Create(b_dividend_payment, &i_dividend_payment);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'dividend_payment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'dividend_payment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'dividend_payment' board is locked\n");
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
		
		
		rc = MB_Iterator_Create(b_capital_good_profit_distribution, &i_capital_good_profit_distribution);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'capital_good_profit_distribution'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is locked\n");
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
		
		
			i = Household_receicve_dividends();
			
		
		    rc = MB_Iterator_Delete(&i_dividend_payment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'dividend_payment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'dividend_payment' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_capital_good_profit_distribution);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'capital_good_profit_distribution' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
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




	rc = MB_SyncComplete(b_consumption_request_1);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;
		
		
		
		
		
		rc = MB_Iterator_Create(b_consumption_request_1, &i_consumption_request_1);
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
		   }
		}
		#endif
		
		
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
		       }
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


    rc = MB_SyncStart(b_quality_price_info_2);
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
       }
    }
    #endif

    rc = MB_SyncStart(b_accepted_consumption_1);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_accepted_consumption_1);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
		rc = MB_Iterator_Create(b_accepted_consumption_1, &i_accepted_consumption_1);
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
		   }
		}
		#endif
		
		
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
		       }
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




	rc = MB_SyncComplete(b_quality_price_info_2);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_rank_and_buy_goods_2_11_12_condition(current_xmachine_Household))
		{
		
		
		
		rc = MB_Iterator_Create(b_quality_price_info_2, &i_quality_price_info_2);
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
		   }
		}
		#endif
		
		
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
		       }
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


    rc = MB_SyncStart(b_consumption_request_2);
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
       }
    }
    #endif


	
	current_xmachine_Household_holder = Household_11_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_13_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_idle_11_13_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_idle();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_11_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_11_state, Household_13_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}




	rc = MB_SyncComplete(b_consumption_request_2);
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
       }
    }
    #endif
	
	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;
		
		
		
		
		
		rc = MB_Iterator_Create(b_consumption_request_2, &i_consumption_request_2);
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
		   }
		}
		#endif
		
		
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
		       }
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


    rc = MB_SyncStart(b_accepted_consumption_2);
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
       }
    }
    #endif



	
	current_xmachine_Mall_holder = Mall_05_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		current_xmachine_Mall = current_xmachine_Mall_holder->agent;
		current_xmachine_Mall_next_state = Mall_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Mall = current_xmachine_Mall;
		
		
		
		
		
			i = Mall_pay_firm();
			
		
		
			if(i == 1)
			{
				free_Mall_agent(current_xmachine_Mall_holder, Mall_05_state);
			}
			else
			{
				transition_Mall_agent(current_xmachine_Mall_holder, Mall_05_state, Mall_end_state);
			}
		
		
		current_xmachine_Mall = NULL;
		
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}


    rc = MB_SyncStart(b_sales);
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
       }
    }
    #endif


	rc = MB_SyncComplete(b_accepted_consumption_2);
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
       }
    }
    #endif
	
	
	current_xmachine_Household_holder = Household_12_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_13_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
		rc = MB_Iterator_Create(b_accepted_consumption_2, &i_accepted_consumption_2);
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
		   }
		}
		#endif
		
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_12_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_12_state, Household_13_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}




	
	current_xmachine_Household_holder = Household_13_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		
		
		
		
		rc = MB_Iterator_Create(b_dividend_payment, &i_dividend_payment);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'dividend_payment'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'dividend_payment' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'dividend_payment' board is locked\n");
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
		
		
		rc = MB_Iterator_Create(b_capital_good_profit_distribution, &i_capital_good_profit_distribution);
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not create Iterator for 'capital_good_profit_distribution'\n");
		   switch(rc) {
		       case MB_ERR_INVALID:
		           fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is invalid\n");
		           break;
		       case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is locked\n");
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
		
		
			i = Household_receicve_dividends();
			
		
		    rc = MB_Iterator_Delete(&i_dividend_payment);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'dividend_payment' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'dividend_payment' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_capital_good_profit_distribution);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'capital_good_profit_distribution' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_13_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_13_state, Household_14_state);
			}
		
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	rc = MB_SyncComplete(b_sales);
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
       }
    }
    #endif
	
	
	current_xmachine_Firm_holder = Firm_13_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_13b_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		
		
		
		
		rc = MB_Iterator_Create(b_sales, &i_sales);
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
		   }
		}
		#endif
		
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_13_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_13_state, Firm_13b_state);
			}
		
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
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



	
	current_xmachine_Firm_holder = Firm_13b_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_idle_13b_14_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_idle();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_13b_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_13b_state, Firm_14_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}



	rc = MB_SyncComplete(b_specific_skill_update);
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
       }
    }
    #endif
	
	
	current_xmachine_Firm_holder = Firm_13b_state->agents;
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
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_update_specific_skills_of_workers_13b_14_condition(current_xmachine_Firm))
		{
		
		
		
		rc = MB_Iterator_Create(b_specific_skill_update, &i_specific_skill_update);
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
		   }
		}
		#endif
		
		
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_13b_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_13b_state, Firm_14_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}




	
	current_xmachine_Household_holder = Household_15_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_idle_15_end_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_idle();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_15_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_15_state, Household_end_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}



	
	current_xmachine_Household_holder = Household_15_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		current_xmachine_Household = current_xmachine_Household_holder->agent;
		current_xmachine_Household_next_state = Household_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Household = current_xmachine_Household;
		
		if(Household_Household_send_data_to_Market_Research_15_end_condition(current_xmachine_Household))
		{
		
		
		
			i = Household_send_data_to_Market_Research();
			
		
		
			if(i == 1)
			{
				free_Household_agent(current_xmachine_Household_holder, Household_15_state);
			}
			else
			{
				transition_Household_agent(current_xmachine_Household_holder, Household_15_state, Household_end_state);
			}
		}
		
		current_xmachine_Household = NULL;
		
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}


    rc = MB_SyncStart(b_household_send_data);
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
       }
    }
    #endif


	
	current_xmachine_Firm_holder = Firm_14_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_idle_14_end_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_idle();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_14_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_14_state, Firm_end_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}



	
	current_xmachine_Firm_holder = Firm_14_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		current_xmachine_Firm = current_xmachine_Firm_holder->agent;
		current_xmachine_Firm_next_state = Firm_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Firm = current_xmachine_Firm;
		
		if(Firm_Firm_send_data_to_Market_Research_14_end_condition(current_xmachine_Firm))
		{
		
		
		
			i = Firm_send_data_to_Market_Research();
			
		
		
			if(i == 1)
			{
				free_Firm_agent(current_xmachine_Firm_holder, Firm_14_state);
			}
			else
			{
				transition_Firm_agent(current_xmachine_Firm_holder, Firm_14_state, Firm_end_state);
			}
		}
		
		current_xmachine_Firm = NULL;
		
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}


    rc = MB_SyncStart(b_firm_send_data);
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
       }
    }
    #endif



	rc = MB_SyncComplete(b_firm_send_data);
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
       }
    }
    #endif
	
	rc = MB_SyncComplete(b_household_send_data);
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
       }
    }
    #endif
	
	
	current_xmachine_Eurostat_holder = Eurostat_02_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		current_xmachine_Eurostat = current_xmachine_Eurostat_holder->agent;
		current_xmachine_Eurostat_next_state = Eurostat_end_state;
		/* For backwards compatability set current_xmachine */
		current_xmachine->xmachine_Firm = NULL;
		current_xmachine->xmachine_Household = NULL;
		current_xmachine->xmachine_Mall = NULL;
		current_xmachine->xmachine_IGFirm = NULL;
		current_xmachine->xmachine_Eurostat = NULL;
		current_xmachine->xmachine_Clearinghouse = NULL;
		current_xmachine->xmachine_Bank = NULL;
		current_xmachine->xmachine_Government = NULL;
		current_xmachine->xmachine_Eurostat = current_xmachine_Eurostat;
		
		if(Eurostat_Market_Research_calculate_data_02_end_condition(current_xmachine_Eurostat))
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
		   }
		}
		#endif
		
		
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
		   }
		}
		#endif
		
		
			i = Market_Research_calculate_data();
			
		
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
		       }
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
		       }
		    }
		    #endif
		
		
			if(i == 1)
			{
				free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_02_state);
			}
			else
			{
				transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_02_state, Eurostat_end_state);
			}
		}
		
		current_xmachine_Eurostat = NULL;
		
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}





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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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

    rc = MB_Clear(b_interest_payment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'interest_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'interest_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'interest_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Clear(b_debt_installment_payment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'debt_installment_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'debt_installment_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'debt_installment_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
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
       }
    }
    #endif

    rc = MB_Clear(b_application_rejection);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'application_rejection' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'application_rejection' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'application_rejection' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Clear(b_application_rejection2);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'application_rejection2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'application_rejection2' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'application_rejection2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
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
       }
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
       }
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
       }
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
       }
    }
    #endif

    rc = MB_Clear(b_market_research_send_specific_skills);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'market_research_send_specific_skills' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'market_research_send_specific_skills' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'market_research_send_specific_skills' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
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
       }
    }
    #endif

    rc = MB_Clear(b_dividend_payment);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'dividend_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_payment' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'dividend_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Clear(b_stock_order);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'stock_order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'stock_order' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'stock_order' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Clear(b_stock_transaction);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'stock_transaction' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'stock_transaction' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'stock_transaction' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Clear(b_bond_order);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bond_order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bond_order' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bond_order' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Clear(b_bond_transaction);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'bond_transaction' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bond_transaction' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bond_transaction' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Clear(b_gov_bond_order);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'gov_bond_order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_bond_order' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_bond_order' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif

    rc = MB_Clear(b_gov_bond_transaction);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not clear 'gov_bond_transaction' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_bond_transaction' board is invalid\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_bond_transaction' board is locked\n");
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

	/*printf("Firm_11_state->count = %d\n", Firm_11_state->count);*/
	Firm_11_state->count = 0;

	/*printf("Firm_25_state->count = %d\n", Firm_25_state->count);*/
	Firm_25_state->count = 0;

	/*printf("Firm_24_state->count = %d\n", Firm_24_state->count);*/
	Firm_24_state->count = 0;

	/*printf("Firm_23_state->count = %d\n", Firm_23_state->count);*/
	Firm_23_state->count = 0;

	/*printf("Firm_end_state->count = %d\n", Firm_end_state->count);*/
	Firm_end_state->count = 0;

	/*printf("Firm_start_Firm_state->count = %d\n", Firm_start_Firm_state->count);*/
	Firm_start_Firm_state->count = 0;

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

	/*printf("Firm_09c_state->count = %d\n", Firm_09c_state->count);*/
	Firm_09c_state->count = 0;

	/*printf("Firm_05b_state->count = %d\n", Firm_05b_state->count);*/
	Firm_05b_state->count = 0;

	/*printf("Firm_05a_state->count = %d\n", Firm_05a_state->count);*/
	Firm_05a_state->count = 0;

	/*printf("Firm_04_state->count = %d\n", Firm_04_state->count);*/
	Firm_04_state->count = 0;

	/*printf("Firm_03c_state->count = %d\n", Firm_03c_state->count);*/
	Firm_03c_state->count = 0;

	/*printf("Firm_03_state->count = %d\n", Firm_03_state->count);*/
	Firm_03_state->count = 0;

	/*printf("Firm_28_state->count = %d\n", Firm_28_state->count);*/
	Firm_28_state->count = 0;

	/*printf("Firm_004_state->count = %d\n", Firm_004_state->count);*/
	Firm_004_state->count = 0;

	/*printf("Firm_003_state->count = %d\n", Firm_003_state->count);*/
	Firm_003_state->count = 0;

	/*printf("Firm_001_state->count = %d\n", Firm_001_state->count);*/
	Firm_001_state->count = 0;

	/*printf("Firm_27_state->count = %d\n", Firm_27_state->count);*/
	Firm_27_state->count = 0;

	/*printf("Firm_22_state->count = %d\n", Firm_22_state->count);*/
	Firm_22_state->count = 0;

	/*printf("Firm_21_state->count = %d\n", Firm_21_state->count);*/
	Firm_21_state->count = 0;

	/*printf("Firm_20_state->count = %d\n", Firm_20_state->count);*/
	Firm_20_state->count = 0;

	/*printf("Firm_14_state->count = %d\n", Firm_14_state->count);*/
	Firm_14_state->count = 0;

	/*printf("Firm_13b_state->count = %d\n", Firm_13b_state->count);*/
	Firm_13b_state->count = 0;

	/*printf("Firm_13_state->count = %d\n", Firm_13_state->count);*/
	Firm_13_state->count = 0;

	/*printf("Firm_12_state->count = %d\n", Firm_12_state->count);*/
	Firm_12_state->count = 0;

	/*printf("Firm_261_state->count = %d\n", Firm_261_state->count);*/
	Firm_261_state->count = 0;

	/*printf("Firm_26_state->count = %d\n", Firm_26_state->count);*/
	Firm_26_state->count = 0;

	/*printf("Firm_02_state->count = %d\n", Firm_02_state->count);*/
	Firm_02_state->count = 0;

	/*printf("Firm_00b_state->count = %d\n", Firm_00b_state->count);*/
	Firm_00b_state->count = 0;

	/*printf("Firm_00_state->count = %d\n", Firm_00_state->count);*/
	Firm_00_state->count = 0;

	/*printf("Firm_01_state->count = %d\n", Firm_01_state->count);*/
	Firm_01_state->count = 0;

	/*printf("Firm_002_state->count = %d\n", Firm_002_state->count);*/
	Firm_002_state->count = 0;

	/*printf("Household_end_state->count = %d\n", Household_end_state->count);*/
	Household_end_state->count = 0;

	/*printf("Household_05_state->count = %d\n", Household_05_state->count);*/
	Household_05_state->count = 0;

	/*printf("Household_04_state->count = %d\n", Household_04_state->count);*/
	Household_04_state->count = 0;

	/*printf("Household_03_state->count = %d\n", Household_03_state->count);*/
	Household_03_state->count = 0;

	/*printf("Household_02_state->count = %d\n", Household_02_state->count);*/
	Household_02_state->count = 0;

	/*printf("Household_01b_state->count = %d\n", Household_01b_state->count);*/
	Household_01b_state->count = 0;

	/*printf("Household_01_state->count = %d\n", Household_01_state->count);*/
	Household_01_state->count = 0;

	/*printf("Household_01e_state->count = %d\n", Household_01e_state->count);*/
	Household_01e_state->count = 0;

	/*printf("Household_01a_state->count = %d\n", Household_01a_state->count);*/
	Household_01a_state->count = 0;

	/*printf("Household_01d_state->count = %d\n", Household_01d_state->count);*/
	Household_01d_state->count = 0;

	/*printf("Household_start_Household_state->count = %d\n", Household_start_Household_state->count);*/
	Household_start_Household_state->count = 0;

	/*printf("Household_14_state->count = %d\n", Household_14_state->count);*/
	Household_14_state->count = 0;

	/*printf("Household_12_state->count = %d\n", Household_12_state->count);*/
	Household_12_state->count = 0;

	/*printf("Household_13_state->count = %d\n", Household_13_state->count);*/
	Household_13_state->count = 0;

	/*printf("Household_11_state->count = %d\n", Household_11_state->count);*/
	Household_11_state->count = 0;

	/*printf("Household_10_state->count = %d\n", Household_10_state->count);*/
	Household_10_state->count = 0;

	/*printf("Household_15_state->count = %d\n", Household_15_state->count);*/
	Household_15_state->count = 0;

	/*printf("Household_08_state->count = %d\n", Household_08_state->count);*/
	Household_08_state->count = 0;

	/*printf("Household_07_state->count = %d\n", Household_07_state->count);*/
	Household_07_state->count = 0;

	/*printf("Household_09_state->count = %d\n", Household_09_state->count);*/
	Household_09_state->count = 0;

	/*printf("Household_06_state->count = %d\n", Household_06_state->count);*/
	Household_06_state->count = 0;

	/*printf("Mall_end_state->count = %d\n", Mall_end_state->count);*/
	Mall_end_state->count = 0;

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

	/*printf("IGFirm_end_state->count = %d\n", IGFirm_end_state->count);*/
	IGFirm_end_state->count = 0;

	/*printf("IGFirm_03_state->count = %d\n", IGFirm_03_state->count);*/
	IGFirm_03_state->count = 0;

	/*printf("IGFirm_02_state->count = %d\n", IGFirm_02_state->count);*/
	IGFirm_02_state->count = 0;

	/*printf("IGFirm_01_state->count = %d\n", IGFirm_01_state->count);*/
	IGFirm_01_state->count = 0;

	/*printf("IGFirm_start_IGFirm_state->count = %d\n", IGFirm_start_IGFirm_state->count);*/
	IGFirm_start_IGFirm_state->count = 0;

	/*printf("Eurostat_end_state->count = %d\n", Eurostat_end_state->count);*/
	Eurostat_end_state->count = 0;

	/*printf("Eurostat_02_state->count = %d\n", Eurostat_02_state->count);*/
	Eurostat_02_state->count = 0;

	/*printf("Eurostat_01_state->count = %d\n", Eurostat_01_state->count);*/
	Eurostat_01_state->count = 0;

	/*printf("Eurostat_start_Market_Research_state->count = %d\n", Eurostat_start_Market_Research_state->count);*/
	Eurostat_start_Market_Research_state->count = 0;

	/*printf("Clearinghouse_end_state->count = %d\n", Clearinghouse_end_state->count);*/
	Clearinghouse_end_state->count = 0;

	/*printf("Clearinghouse_05_state->count = %d\n", Clearinghouse_05_state->count);*/
	Clearinghouse_05_state->count = 0;

	/*printf("Clearinghouse_04_state->count = %d\n", Clearinghouse_04_state->count);*/
	Clearinghouse_04_state->count = 0;

	/*printf("Clearinghouse_03_state->count = %d\n", Clearinghouse_03_state->count);*/
	Clearinghouse_03_state->count = 0;

	/*printf("Clearinghouse_02_state->count = %d\n", Clearinghouse_02_state->count);*/
	Clearinghouse_02_state->count = 0;

	/*printf("Clearinghouse_01_state->count = %d\n", Clearinghouse_01_state->count);*/
	Clearinghouse_01_state->count = 0;

	/*printf("Clearinghouse_start_Clearinghouse_state->count = %d\n", Clearinghouse_start_Clearinghouse_state->count);*/
	Clearinghouse_start_Clearinghouse_state->count = 0;

	/*printf("Bank_04_state->count = %d\n", Bank_04_state->count);*/
	Bank_04_state->count = 0;

	/*printf("Bank_03_state->count = %d\n", Bank_03_state->count);*/
	Bank_03_state->count = 0;

	/*printf("Bank_02_state->count = %d\n", Bank_02_state->count);*/
	Bank_02_state->count = 0;

	/*printf("Bank_01_state->count = %d\n", Bank_01_state->count);*/
	Bank_01_state->count = 0;

	/*printf("Bank_start_Bank_state->count = %d\n", Bank_start_Bank_state->count);*/
	Bank_start_Bank_state->count = 0;

	/*printf("Government_end_state->count = %d\n", Government_end_state->count);*/
	Government_end_state->count = 0;

	/*printf("Government_start_Government_state->count = %d\n", Government_start_Government_state->count);*/
	Government_start_Government_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_Firm_holder = Firm_end_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		transition_Firm_agent(current_xmachine_Firm_holder, Firm_end_state, Firm_start_Firm_state);
	
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}

	current_xmachine_Household_holder = Household_end_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		transition_Household_agent(current_xmachine_Household_holder, Household_end_state, Household_start_Household_state);
	
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}

	current_xmachine_Mall_holder = Mall_end_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		transition_Mall_agent(current_xmachine_Mall_holder, Mall_end_state, Mall_start_Mall_state);
	
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}

	current_xmachine_IGFirm_holder = IGFirm_end_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		transition_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_end_state, IGFirm_start_IGFirm_state);
	
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}

	current_xmachine_Eurostat_holder = Eurostat_end_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		transition_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_end_state, Eurostat_start_Market_Research_state);
	
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}

	current_xmachine_Clearinghouse_holder = Clearinghouse_end_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		transition_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_end_state, Clearinghouse_start_Clearinghouse_state);
	
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}

	current_xmachine_Bank_holder = Bank_04_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		transition_Bank_agent(current_xmachine_Bank_holder, Bank_04_state, Bank_start_Bank_state);
	
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}

	current_xmachine_Government_holder = Government_end_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		transition_Government_agent(current_xmachine_Government_holder, Government_end_state, Government_start_Government_state);
	
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
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
