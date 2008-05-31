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
		


	printf("FLAME Application: Labour \n");





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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Mall != NULL)
			{
				i = Mall_send_current_stocks();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_IGFirm != NULL)
			{
				i = IGFirm_update_productivity_price();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_calc_production_quantity();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_calc_input_demands();
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
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_compute_payout_policy();
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
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_apply_for_loans();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Bank != NULL)
			{
				i = Bank_read_loan_request_send_offers();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_read_loan_offers_send_loan_acceptance();
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
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_compute_and_send_bond_orders();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Clearinghouse != NULL)
			{
				i = Clearinghouse_read_bond_orders();
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
		
			if(current_xmachine->xmachine_Clearinghouse != NULL)
			{
				i = Clearinghouse_compute_bond_transactions();
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
		
			if(current_xmachine->xmachine_Clearinghouse != NULL)
			{
				i = Clearinghouse_send_bond_transactions();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_read_bond_transactions();
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
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_compute_and_send_stock_orders();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Clearinghouse != NULL)
			{
				i = Clearinghouse_read_stock_orders();
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
		
			if(current_xmachine->xmachine_Clearinghouse != NULL)
			{
				i = Clearinghouse_compute_stock_transactions();
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
		
			if(current_xmachine->xmachine_Clearinghouse != NULL)
			{
				i = Clearinghouse_send_stock_transactions();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_read_stock_transactions();
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
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_calc_production_quantity_2();
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
		
			if(current_xmachine->xmachine_Market_Research != NULL)
			{
				i = Market_Research_send_data();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_send_redundancies();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_read_firing_messages();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_calculate_specific_skills_and_wage_offer();
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
				i = Household_on_the_job_search_Yes_or_No();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_send_vacancies();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_read_job_vacancies_and_send_applications();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_read_job_applications_send_job_offer_or_rejection();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_read_job_offers_send_response();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_read_job_responses();
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
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_update_wage_offer();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_read_application_rejection_update_wage_reservation();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_send_vacancies_2();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_read_job_vacancies_and_send_applications_2();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_read_job_applications_send_job_offer_or_rejection_2();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_read_job_offers_send_response_2();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_read_job_responses_2();
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
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_send_capital_demand();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_IGFirm != NULL)
			{
				i = IGFirm_send_capital_good();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_calc_pay_costs();
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
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_send_goods_to_mall();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Mall != NULL)
			{
				i = Mall_update_mall_stock();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Mall != NULL)
			{
				i = Mall_send_quality_price_info_1();
			}
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_receive_wage();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_rank_and_buy_goods_1();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Mall != NULL)
			{
				i = Mall_update_mall_stocks_sales_rationing_1();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_rank_and_buy_goods_2();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Mall != NULL)
			{
				i = Mall_update_mall_stocks_sales_rationing_2();
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
		
			if(current_xmachine->xmachine_Mall != NULL)
			{
				i = Mall_pay_firm();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_compute_and_send_gov_bond_orders();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Clearinghouse != NULL)
			{
				i = Clearinghouse_read_gov_bond_orders();
			}
		
			if(current_xmachine->xmachine_IGFirm != NULL)
			{
				i = IGFirm_receive_payment();
			}
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_read_rationing();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_calc_revenue();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Clearinghouse != NULL)
			{
				i = Clearinghouse_compute_gov_bond_transactions();
			}
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_handle_leftover_budget();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_update_specific_skills_of_workers();
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
		
			if(current_xmachine->xmachine_Clearinghouse != NULL)
			{
				i = Clearinghouse_send_gov_bond_transactions();
			}
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_send_data_to_Market_Research();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_compute_income_statement();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_send_data_to_Market_Research();
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
				
			p_vacancies_message = &current_node->vacancies_messages;
				
			p_vacancies2_message = &current_node->vacancies2_messages;
				
			p_firing_message = &current_node->firing_messages;
				
			p_job_application_message = &current_node->job_application_messages;
				
			p_job_application2_message = &current_node->job_application2_messages;
				
			p_job_offer_message = &current_node->job_offer_messages;
				
			p_job_offer2_message = &current_node->job_offer2_messages;
				
			p_job_acceptance_message = &current_node->job_acceptance_messages;
				
			p_job_acceptance2_message = &current_node->job_acceptance2_messages;
				
			p_application_rejection_message = &current_node->application_rejection_messages;
				
			p_application_rejection2_message = &current_node->application_rejection2_messages;
				
			p_quitting_message = &current_node->quitting_messages;
				
			p_quitting2_message = &current_node->quitting2_messages;
				
			p_productivity_message = &current_node->productivity_messages;
				
			p_capital_good_request_message = &current_node->capital_good_request_messages;
				
			p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
				
			p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
				
			p_wage_payment_message = &current_node->wage_payment_messages;
				
			p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
				
			p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
				
			p_update_mall_stock_message = &current_node->update_mall_stock_messages;
				
			p_consumption_request_1_message = &current_node->consumption_request_1_messages;
				
			p_consumption_request_2_message = &current_node->consumption_request_2_messages;
				
			p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
				
			p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
				
			p_sales_message = &current_node->sales_messages;
				
			p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
				
			p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
				
			p_specific_skill_update_message = &current_node->specific_skill_update_messages;
				
			p_firm_send_data_message = &current_node->firm_send_data_messages;
				
			p_household_send_data_message = &current_node->household_send_data_messages;
				
			p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
				
			p_tax_payment_message = &current_node->tax_payment_messages;
				
			p_interest_payment_message = &current_node->interest_payment_messages;
				
			p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
				
			p_dividend_payment_message = &current_node->dividend_payment_messages;
				
			p_loan_request_message = &current_node->loan_request_messages;
				
			p_loan_conditions_message = &current_node->loan_conditions_messages;
				
			p_loan_acceptance_message = &current_node->loan_acceptance_messages;
				
			p_stock_order_message = &current_node->stock_order_messages;
				
			p_stock_transaction_message = &current_node->stock_transaction_messages;
				
			p_bond_order_message = &current_node->bond_order_messages;
				
			p_bond_transaction_message = &current_node->bond_transaction_messages;
				
			p_gov_bond_order_message = &current_node->gov_bond_order_messages;
				
			p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
				
		p_xmachine = &current_node->agents;
	
	
	
		/* Loop through x-machines */
		current_xmachine = *p_xmachine;
		while(current_xmachine)
		{
			i = 0;
		
			if(current_xmachine->xmachine_Market_Research != NULL)
			{
				i = Market_Research_calculate_data();
			}
		
			if(current_xmachine->xmachine_Household != NULL)
			{
				i = Household_read_application_rejection_update_wage_reservation_2();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_read_gov_bond_transactions();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_compute_balance_sheet();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_calc_input_demands_2();
			}
		
			if(current_xmachine->xmachine_Firm != NULL)
			{
				i = Firm_update_wage_offer_2();
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
		p_vacancies_message = &current_node->vacancies_messages;
		freevacanciesmessages();
		p_vacancies2_message = &current_node->vacancies2_messages;
		freevacancies2messages();
		p_firing_message = &current_node->firing_messages;
		freefiringmessages();
		p_job_application_message = &current_node->job_application_messages;
		freejob_applicationmessages();
		p_job_application2_message = &current_node->job_application2_messages;
		freejob_application2messages();
		p_job_offer_message = &current_node->job_offer_messages;
		freejob_offermessages();
		p_job_offer2_message = &current_node->job_offer2_messages;
		freejob_offer2messages();
		p_job_acceptance_message = &current_node->job_acceptance_messages;
		freejob_acceptancemessages();
		p_job_acceptance2_message = &current_node->job_acceptance2_messages;
		freejob_acceptance2messages();
		p_application_rejection_message = &current_node->application_rejection_messages;
		freeapplication_rejectionmessages();
		p_application_rejection2_message = &current_node->application_rejection2_messages;
		freeapplication_rejection2messages();
		p_quitting_message = &current_node->quitting_messages;
		freequittingmessages();
		p_quitting2_message = &current_node->quitting2_messages;
		freequitting2messages();
		p_productivity_message = &current_node->productivity_messages;
		freeproductivitymessages();
		p_capital_good_request_message = &current_node->capital_good_request_messages;
		freecapital_good_requestmessages();
		p_capital_good_profit_distribution_message = &current_node->capital_good_profit_distribution_messages;
		freecapital_good_profit_distributionmessages();
		p_capital_good_delivery_message = &current_node->capital_good_delivery_messages;
		freecapital_good_deliverymessages();
		p_wage_payment_message = &current_node->wage_payment_messages;
		freewage_paymentmessages();
		p_quality_price_info_1_message = &current_node->quality_price_info_1_messages;
		freequality_price_info_1messages();
		p_quality_price_info_2_message = &current_node->quality_price_info_2_messages;
		freequality_price_info_2messages();
		p_update_mall_stock_message = &current_node->update_mall_stock_messages;
		freeupdate_mall_stockmessages();
		p_consumption_request_1_message = &current_node->consumption_request_1_messages;
		freeconsumption_request_1messages();
		p_consumption_request_2_message = &current_node->consumption_request_2_messages;
		freeconsumption_request_2messages();
		p_accepted_consumption_1_message = &current_node->accepted_consumption_1_messages;
		freeaccepted_consumption_1messages();
		p_accepted_consumption_2_message = &current_node->accepted_consumption_2_messages;
		freeaccepted_consumption_2messages();
		p_sales_message = &current_node->sales_messages;
		freesalesmessages();
		p_pay_capital_goods_message = &current_node->pay_capital_goods_messages;
		freepay_capital_goodsmessages();
		p_current_mall_stock_info_message = &current_node->current_mall_stock_info_messages;
		freecurrent_mall_stock_infomessages();
		p_specific_skill_update_message = &current_node->specific_skill_update_messages;
		freespecific_skill_updatemessages();
		p_firm_send_data_message = &current_node->firm_send_data_messages;
		freefirm_send_datamessages();
		p_household_send_data_message = &current_node->household_send_data_messages;
		freehousehold_send_datamessages();
		p_market_research_send_specific_skills_message = &current_node->market_research_send_specific_skills_messages;
		freemarket_research_send_specific_skillsmessages();
		p_tax_payment_message = &current_node->tax_payment_messages;
		freetax_paymentmessages();
		p_interest_payment_message = &current_node->interest_payment_messages;
		freeinterest_paymentmessages();
		p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
		freedebt_installment_paymentmessages();
		p_dividend_payment_message = &current_node->dividend_payment_messages;
		freedividend_paymentmessages();
		p_loan_request_message = &current_node->loan_request_messages;
		freeloan_requestmessages();
		p_loan_conditions_message = &current_node->loan_conditions_messages;
		freeloan_conditionsmessages();
		p_loan_acceptance_message = &current_node->loan_acceptance_messages;
		freeloan_acceptancemessages();
		p_stock_order_message = &current_node->stock_order_messages;
		freestock_ordermessages();
		p_stock_transaction_message = &current_node->stock_transaction_messages;
		freestock_transactionmessages();
		p_bond_order_message = &current_node->bond_order_messages;
		freebond_ordermessages();
		p_bond_transaction_message = &current_node->bond_transaction_messages;
		freebond_transactionmessages();
		p_gov_bond_order_message = &current_node->gov_bond_order_messages;
		freegov_bond_ordermessages();
		p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
		freegov_bond_transactionmessages();
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
