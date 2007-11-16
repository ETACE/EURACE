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
	int iteration_number;
	int iteration_total;
	int * p_iteration_number;
	xmachine * temp_free_xmachine;
	xmachine **agent_list;
	/* Ratio for calculating time in milliseconds */
    /* (lsc) changed from long to double
     * if "long", time_ratio == 0 when CLOCKS_PER_SEC > 1000
     */
	double time_ratio = 1000.0/CLOCKS_PER_SEC;
	/* Particle cloud data */
	double cloud_data[6];

/* For partition method. Makes geometric (-g flag) the default but may be overridden with -r for round-robin */
	int partition_method=1;


	
	/* Don't use binary output as default */
	use_binary_output = 0;
	/* Output frequency is 1 as default */
	output_frequency = 1;
	/* Set random seed */
/*	srand(time(NULL)); */
	
	/* Initialise pointers */
	initialise_pointers();
	p_iteration_number = &iteration_number;
		


	printf("FLAME Application: Financial Market Model \n");





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
		/* Use binary format for results */
		if(strcmp(argv[i],"-b") == 0) use_binary_output = 1;
		if(use_binary_output) printf("Using binary output for results\n");
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

       agent_list = p_xmachine;
       readinitialstates(inputpath, p_iteration_number, agent_list, cloud_data, partition_method, 0);
       /* Generate partitions */
       generate_partitions(cloud_data,totalnodes,partition_method);
       save_partition_data();
 





    /* Partition data */
    partition_data(totalnodes, agent_list, cloud_data, partition_method);




		i = 0;
		current_node = *p_node_info;
		while(current_node)
		{
			printf("No of agents on partition %d: %d\n", current_node->node_id, current_node->agent_total);
			i += current_node->agent_total;
			current_node = current_node->next;
		}
		printf("Agent total check: %d\n", i);

        /* restore current_node pointer */
		current_node = *p_node_info;


	
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
    randomisexagent();
	
	for(iteration_loop=iteration_number+1; iteration_loop < iteration_number+iteration_total+1; iteration_loop++)
	{
		interval = clock();
		/* Print out iteration number */
		printf("Iteration - %d\n", iteration_loop);
		/* START OF ITERATION */

/* Start of communications layer loop */
	
		current_node = *p_node_info;
		while(current_node)
		{
				
			p_WagePayment_message = &current_node->WagePayment_messages;
				
			p_DividendPayment_message = &current_node->DividendPayment_messages;
				
			p_BondCouponPayment_message = &current_node->BondCouponPayment_messages;
				
			p_firm_bond_order_message = &current_node->firm_bond_order_messages;
				
			p_firm_stock_order_message = &current_node->firm_stock_order_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
			p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;
				
			p_rule_performance_message = &current_node->rule_performance_messages;
				
			p_all_performances_message = &current_node->all_performances_messages;
				
			p_rule_details_request_message = &current_node->rule_details_request_messages;
				
			p_rule_details_message = &current_node->rule_details_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_send_rule_performance_message();
			}
			
			/* If agent is freed */
			if(i == 1)
			{
				temp_free_xmachine = current_xmachine->next;
				free_agent();
				current_xmachine = temp_free_xmachine;
			}
			else
			{
				current_xmachine = current_xmachine->next;
			}
		}
	
	
        randomisexagent();  /* randomise x-agents while waiting for communication to complete */
        
			
		current_node = current_node->next;
		}
			
/* End of communications layer loop */

/* Start of communications layer loop */
	
		current_node = *p_node_info;
		while(current_node)
		{
				
			p_WagePayment_message = &current_node->WagePayment_messages;
				
			p_DividendPayment_message = &current_node->DividendPayment_messages;
				
			p_BondCouponPayment_message = &current_node->BondCouponPayment_messages;
				
			p_firm_bond_order_message = &current_node->firm_bond_order_messages;
				
			p_firm_stock_order_message = &current_node->firm_stock_order_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
			p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;
				
			p_rule_performance_message = &current_node->rule_performance_messages;
				
			p_all_performances_message = &current_node->all_performances_messages;
				
			p_rule_details_request_message = &current_node->rule_details_request_messages;
				
			p_rule_details_message = &current_node->rule_details_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_FinancialAdvisor != NULL)
			{
				i = FinancialAgent_read_rule_performance_message();
			}
			
			/* If agent is freed */
			if(i == 1)
			{
				temp_free_xmachine = current_xmachine->next;
				free_agent();
				current_xmachine = temp_free_xmachine;
			}
			else
			{
				current_xmachine = current_xmachine->next;
			}
		}
	
	
        randomisexagent();  /* randomise x-agents while waiting for communication to complete */
        
			
		current_node = current_node->next;
		}
			
/* End of communications layer loop */

/* Start of communications layer loop */
	
		current_node = *p_node_info;
		while(current_node)
		{
				
			p_WagePayment_message = &current_node->WagePayment_messages;
				
			p_DividendPayment_message = &current_node->DividendPayment_messages;
				
			p_BondCouponPayment_message = &current_node->BondCouponPayment_messages;
				
			p_firm_bond_order_message = &current_node->firm_bond_order_messages;
				
			p_firm_stock_order_message = &current_node->firm_stock_order_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
			p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;
				
			p_rule_performance_message = &current_node->rule_performance_messages;
				
			p_all_performances_message = &current_node->all_performances_messages;
				
			p_rule_details_request_message = &current_node->rule_details_request_messages;
				
			p_rule_details_message = &current_node->rule_details_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_reads_all_performances_messages();
			}
			
			/* If agent is freed */
			if(i == 1)
			{
				temp_free_xmachine = current_xmachine->next;
				free_agent();
				current_xmachine = temp_free_xmachine;
			}
			else
			{
				current_xmachine = current_xmachine->next;
			}
		}
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_select_rule();
			}
			
			/* If agent is freed */
			if(i == 1)
			{
				temp_free_xmachine = current_xmachine->next;
				free_agent();
				current_xmachine = temp_free_xmachine;
			}
			else
			{
				current_xmachine = current_xmachine->next;
			}
		}
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_apply_selected_rule();
			}
			
			/* If agent is freed */
			if(i == 1)
			{
				temp_free_xmachine = current_xmachine->next;
				free_agent();
				current_xmachine = temp_free_xmachine;
			}
			else
			{
				current_xmachine = current_xmachine->next;
			}
		}
	
	
        randomisexagent();  /* randomise x-agents while waiting for communication to complete */
        
			
		current_node = current_node->next;
		}
			
/* End of communications layer loop */

/* Start of communications layer loop */
	
		current_node = *p_node_info;
		while(current_node)
		{
				
			p_WagePayment_message = &current_node->WagePayment_messages;
				
			p_DividendPayment_message = &current_node->DividendPayment_messages;
				
			p_BondCouponPayment_message = &current_node->BondCouponPayment_messages;
				
			p_firm_bond_order_message = &current_node->firm_bond_order_messages;
				
			p_firm_stock_order_message = &current_node->firm_stock_order_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
			p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;
				
			p_rule_performance_message = &current_node->rule_performance_messages;
				
			p_all_performances_message = &current_node->all_performances_messages;
				
			p_rule_details_request_message = &current_node->rule_details_request_messages;
				
			p_rule_details_message = &current_node->rule_details_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_ClearingHouseMechanism != NULL)
			{
				i = Clearinghouse_read_order_messages();
			}
			
			/* If agent is freed */
			if(i == 1)
			{
				temp_free_xmachine = current_xmachine->next;
				free_agent();
				current_xmachine = temp_free_xmachine;
			}
			else
			{
				current_xmachine = current_xmachine->next;
			}
		}
	
	
        randomisexagent();  /* randomise x-agents while waiting for communication to complete */
        
			
		current_node = current_node->next;
		}
			
/* End of communications layer loop */

/* Start of communications layer loop */
	
		current_node = *p_node_info;
		while(current_node)
		{
				
			p_WagePayment_message = &current_node->WagePayment_messages;
				
			p_DividendPayment_message = &current_node->DividendPayment_messages;
				
			p_BondCouponPayment_message = &current_node->BondCouponPayment_messages;
				
			p_firm_bond_order_message = &current_node->firm_bond_order_messages;
				
			p_firm_stock_order_message = &current_node->firm_stock_order_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
			p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;
				
			p_rule_performance_message = &current_node->rule_performance_messages;
				
			p_all_performances_message = &current_node->all_performances_messages;
				
			p_rule_details_request_message = &current_node->rule_details_request_messages;
				
			p_rule_details_message = &current_node->rule_details_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_FinancialAdvisor != NULL)
			{
				i = FinancialAgent_update_classifiersystem();
			}
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_read_transaction_message();
			}
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_retrieve_rule_details();
			}
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_EWA_learning();
			}
			
			/* If agent is freed */
			if(i == 1)
			{
				temp_free_xmachine = current_xmachine->next;
				free_agent();
				current_xmachine = temp_free_xmachine;
			}
			else
			{
				current_xmachine = current_xmachine->next;
			}
		}
	
	
        randomisexagent();  /* randomise x-agents while waiting for communication to complete */
        
			
		current_node = current_node->next;
		}
			
/* End of communications layer loop */



		if(iteration_loop%output_frequency == 0)
		{
			if(use_binary_output) saveiterationdata_binary(iteration_loop);
			else saveiterationdata(iteration_loop);
		}		current_node = *p_node_info;
		while(current_node)
		{
		p_WagePayment_message = &current_node->WagePayment_messages;
		freeWagePaymentmessages();
		p_DividendPayment_message = &current_node->DividendPayment_messages;
		freeDividendPaymentmessages();
		p_BondCouponPayment_message = &current_node->BondCouponPayment_messages;
		freeBondCouponPaymentmessages();
		p_firm_bond_order_message = &current_node->firm_bond_order_messages;
		freefirm_bond_ordermessages();
		p_firm_stock_order_message = &current_node->firm_stock_order_messages;
		freefirm_stock_ordermessages();
		p_gov_bond_order_message = &current_node->gov_bond_order_messages;
		freegov_bond_ordermessages();
		p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;
		freefirm_bond_transactionmessages();
		p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
		freegov_bond_transactionmessages();
		p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;
		freefirm_stock_transactionmessages();
		p_rule_performance_message = &current_node->rule_performance_messages;
		freerule_performancemessages();
		p_all_performances_message = &current_node->all_performances_messages;
		freeall_performancesmessages();
		p_rule_details_request_message = &current_node->rule_details_request_messages;
		freerule_details_requestmessages();
		p_rule_details_message = &current_node->rule_details_messages;
		freerule_detailsmessages();
		p_xmachine = &current_node->agents;
		/* Calculate if any agents need to jump S.P. */
		propagate_agents();
		current_node = current_node->next;
		}
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
	
	/* Exit successfully by returning zero to Operating System */
	return 0;
}
