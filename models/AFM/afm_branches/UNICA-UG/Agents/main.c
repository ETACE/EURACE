/**
 * \file  main.c
 * \brief Holds main function of the program.
 */

#include "header.h"

/** \fn int main(int argc, char ** argv)
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char ** argv)
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
	double totalwealth=0;
	double precwealth=0;
	int totalq;
	double totalcash;
	double preccash;
	/* Ratio for calculating time in milliseconds */
    /* (lsc) changed from long to double
     * if "long", time_ratio == 0 when CLOCKS_PER_SEC > 1000
     */
	double time_ratio = 1000.0/CLOCKS_PER_SEC;
	/* Particle cloud data */
	double cloud_data[6];

	rnd=newRandom();
	/* Don't use binary output as default */
	use_binary_output = 0;
	/* Output frequency is 1 as default */
	output_frequency = 1;
	/* Set random seed */
	srand(time(NULL));
	
	/* Initialise pointers */
	initialise_pointers();
	p_iteration_number = &iteration_number;
		if(argc < 2)
	{
		printf("No arguments defined\n");
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
		i++;
	}
	
	/* Read initial data into p_xmachine  */

       agent_list = p_xmachine;
       readinitialstates(inputpath, p_iteration_number, agent_list, cloud_data, 0);
       /* Generate partitions */
       generate_partitions(cloud_data,totalnodes);
       save_partition_data();
 





    /* Partition data */
    partition_data(totalnodes, agent_list, cloud_data);




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
	 totalcash=0.0;
	for(iteration_loop=iteration_number+1; iteration_loop < iteration_number+iteration_total+1; iteration_loop++)
	{   printf("differenza %f numassets=%d  cash  %f cash prec %f\n",totalwealth-precwealth,totalq,totalcash,preccash);
	    totalq=0;
	   if(totalcash<0) getchar();
        precwealth=totalwealth;
        //printf("differenza cash %f ",(totalcash-preccash));
        preccash=totalcash;
        totalcash=0.0;
		interval = clock();
		/* Print out iteration number */
		printf("Iteration - %d\n", iteration_loop);
		/* START OF ITERATION */

		current_node = *p_node_info;
		while(current_node)
		{
		p_order_message = &current_node->order_messages;
		p_orderStatus_message = &current_node->orderStatus_messages;
		p_asset_message = &current_node->asset_messages;
		p_infoAsset_message = &current_node->infoAsset_messages;
		p_xmachine = &current_node->agents;

		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
			if(current_xmachine->xmachine_Eurostat != NULL)
			{
				i = sendAssetInformationEURO();
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
		current_node = *p_node_info;
		while(current_node)
		{
		p_order_message = &current_node->order_messages;
		p_orderStatus_message = &current_node->orderStatus_messages;
		p_asset_message = &current_node->asset_messages;
		p_infoAsset_message = &current_node->infoAsset_messages;
		p_xmachine = &current_node->agents;

		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
			if(current_xmachine->xmachine_ClearingHouse != NULL)
			{
				i = receiveAssetInformation();
			}
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = selectStrategy();
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
		current_node = *p_node_info;
		while(current_node)
		{
		p_order_message = &current_node->order_messages;
		p_orderStatus_message = &current_node->orderStatus_messages;
		p_asset_message = &current_node->asset_messages;
		p_infoAsset_message = &current_node->infoAsset_messages;
		p_xmachine = &current_node->agents;

		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
			if(current_xmachine->xmachine_ClearingHouse != NULL)
			{
				i = receiveOrdersAndRun();
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
			if(current_xmachine->xmachine_ClearingHouse != NULL)
			{
				i = sendAssetInformation();
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
		current_node = *p_node_info;
		while(current_node)
		{
		p_order_message = &current_node->order_messages;
		p_orderStatus_message = &current_node->orderStatus_messages;
		p_asset_message = &current_node->asset_messages;
		p_infoAsset_message = &current_node->infoAsset_messages;
		p_xmachine = &current_node->agents;

		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = receiveAssetInformationHouse();
				
			}
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = updateTrader();
				totalwealth=totalwealth+get_wealth();
				totalq=totalq+totalassetsowned();
				totalcash=totalcash+cashowned();
			}
			if(current_xmachine->xmachine_Eurostat != NULL)
			{
				i = receiveAssetInformationEURO();
			
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
		if(iteration_loop%output_frequency == 0)
		{
			if(use_binary_output) saveiterationdata_binary(iteration_loop);
			else saveiterationdata(iteration_loop);
		}		current_node = *p_node_info;
		while(current_node)
		{
		p_order_message = &current_node->order_messages;
		freeordermessages();
		p_orderStatus_message = &current_node->orderStatus_messages;
		freeorderStatusmessages();
		p_asset_message = &current_node->asset_messages;
		freeassetmessages();
		p_infoAsset_message = &current_node->infoAsset_messages;
		freeinfoAssetmessages();
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
