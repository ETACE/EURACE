/**
 * \file  xml.c
 * \brief Holds xml reading and writing functions.
 */

#include "header.h"

/** \fn void read_int_static_array(char * buffer, int * j, int ** int_static_array)
 * \brief Reads integer static array.
 */
void read_int_static_array(char * buffer, int * j, int * int_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		int_static_array[arraycount] = atoi(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_float_static_array(char * buffer, int * (*j), int ** float_static_array)
 * \brief Reads float static array.
 */
void read_float_static_array(char * buffer, int * j, float * float_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		float_static_array[arraycount] = atof(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_double_static_array(char * buffer, int * (*j), int ** double_static_array)
 * \brief Reads double static array.
 */
void read_double_static_array(char * buffer, int * j, double * double_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		double_static_array[arraycount] = atof(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_char_static_array(char * buffer, int * (*j), int ** char_static_array)
 * \brief Reads char static array.
 */
void read_char_static_array(char * buffer, int * j, char * char_static_array, int size)
{
	while(buffer[(*j)] != '\0')
	{
		/* Add check here for buffer overrun */
		char_static_array[(*j)] = buffer[(*j)];
		
		(*j)++;
	}
	
	(*j)++;
}

/** \fn void read_int_dynamic_array(char * buffer, int * (*j), int ** int_dynamic_array)
 * \brief Reads integer dynamic array.
 */
void read_int_dynamic_array(char * buffer, int * j, int_array * int_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		add_int(int_dynamic_array, atoi(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_float_dynamic_array(char * buffer, int * (*j), int ** float_dynamic_array)
 * \brief Reads float dynamic array.
 */
void read_float_dynamic_array(char * buffer, int * j, float_array * float_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		add_float(float_dynamic_array, atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_double_dynamic_array(char * buffer, int * (*j), int ** double_dynamic_array)
 * \brief Reads double dynamic array.
 */
void read_double_dynamic_array(char * buffer, int * j, double_array * double_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		add_double(double_dynamic_array, atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_char_dynamic_array(char * buffer, int * (*j), int ** char_dynamic_array)
 * \brief Reads char dynamic array.
 */
void read_char_dynamic_array(char * buffer, int * j, char_array * char_dynamic_array)
{
	while(buffer[(*j)] != '\0' && buffer[(*j)] != ',' && buffer[(*j)] != '}')
	{
		add_char(char_dynamic_array, buffer[(*j)]);
		(*j)++;
	}
}


/** \fn void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag)
 * \brief Read initial X-machine memory starting values from a file.
 * \param filename The path to the file.
 * \param itno Pointer to the iteration number.
 * \param agent_list List of agents in the model to be constructed by this function.
 * \param cloud_data Max and min x,y,z coordinates of agents.
 * \param partition_method Identifies partitioning method: 1 = geometric, 2 = round-robin
 * \param flag Flag for whether to check space partitions.
 */
void readinitialstates(char * filename, int * itno, double cloud_data[6], 
					   int partition_method, int flag)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = ' ';
	char buffer[10000];
	char agentname[1000];
	//char arraydata[10000];
	//int array_k=0, arraycount=0;
	int j;

/* Things for round-robin partitioning */
	int agent_count;
	int number_partitions;
	int geometric=1;
	int other=2;
	double 	xmax=0,xmin=0,ymax=0,ymin=0,
		xcentre=0,ycentre=0,
		rrange=1.5;
	double posx, posy, posz;
	
	
	/* Cloud data array initialisation */
	cloud_data[0] = SPINF; cloud_data[1] = -SPINF;
	cloud_data[2] = SPINF; cloud_data[3] = -SPINF;
	cloud_data[4] = SPINF; cloud_data[5] = -SPINF;
	
	/* Temporary node and head of associated agent list to allow adding agents */
	node_information temp_node;

	/* Pointer to x-memory for initial state data */
	/*xmachine * current_xmachine;*/
	/* Variables for checking tags */
	int reading, i;
	int in_tag, in_itno, in_agent, in_name, in_environment, in_memory, in_functions;
	int in_Firm_agent;
	int in_Bank_agent;
	int in_Household_agent;

	int in_id;
	int in_interest;
	int in_credit_offer;
	int in_contacted_bank;
	int in_total_debt;
	int in_asset;
	int in_credit_demand;
	int in_installment_amount;
	int in_installment_number;
	int in_loans_number;
	int in_outstanding_debt;
	int in_lending_bank_id;
	int in_interest_amount;
	int in_bankruptcy_state;
	int in_total_resources;
	int in_residual_variable;
	int in_variable_per_installment;
	int in_value_at_risk;
	int in_interest_left;
	int in_current_equity;
	int in_current_debt;
	int in_cash;
	int in_total_credit;
	int in_equity;
	int in_bce_debt;
	int in_alfa;
	int in_variable;
	int in_min_interest;
	int in_gamma;
	int in_profits;
	int in_lambda;
	int in_bce_interest;
	int in_debt_period;
	int in_loan_request_message_found;
	int in_total_deposit;
	int in_bank_account;


	/* Variables for initial state data */
//	int id;
//	double_array * interest;
//	double_array * credit_offer;
//	int_array * contacted_bank;
//	double total_debt;
//	double asset;
//	double credit_demand;
//	double_array * installment_amount;
//	int installment_number;
//	int loans_number;
//	double_array * outstanding_debt;
//	int_array * lending_bank_id;
//	double_array * interest_amount;
//	int bankruptcy_state;
//	double total_resources;
//	double_array * residual_variable;
//	double_array * variable_per_installment;
//	double_array * value_at_risk;
//	double_array * interest_left;
//	double current_equity;
//	double current_debt;
//	double cash;
//	double total_credit;
//	double equity;
//	double bce_debt;
//	double alfa;
//	double variable;
//	double min_interest;
//	double gamma[2];
//	double profits[2];
//	double lambda;
//	double bce_interest;
//	double debt_period;
//	int loan_request_message_found;
//	double total_deposit;
//	int bank_account;


	xmachine_memory_Firm * current_Firm_agent;
	xmachine_memory_Bank * current_Bank_agent;
	xmachine_memory_Household * current_Household_agent;


	/* Open config file to read-only */
	if((file = fopen(filename, "r"))==NULL)
	{
		printf("error opening initial states\n");
		exit(0);
	}
	/* Initialise variables */
	/* TODO: initialise static arrays with zero for each element? */
	next_avaliable_id = -1;
	reading = 1;
	i = 0;
	in_tag = 0;
	in_itno = 0;
	in_agent = 0;
	in_name = 0;
	in_environment = 0;
	in_memory = 0;
	in_functions = 0;
	in_Firm_agent = 0;
	in_Bank_agent = 0;
	in_Household_agent = 0;
	in_id = 0;
	in_interest = 0;
	in_credit_offer = 0;
	in_contacted_bank = 0;
	in_total_debt = 0;
	in_asset = 0;
	in_credit_demand = 0;
	in_installment_amount = 0;
	in_installment_number = 0;
	in_loans_number = 0;
	in_outstanding_debt = 0;
	in_lending_bank_id = 0;
	in_interest_amount = 0;
	in_bankruptcy_state = 0;
	in_total_resources = 0;
	in_residual_variable = 0;
	in_variable_per_installment = 0;
	in_value_at_risk = 0;
	in_interest_left = 0;
	in_current_equity = 0;
	in_current_debt = 0;
	in_cash = 0;
	in_total_credit = 0;
	in_equity = 0;
	in_bce_debt = 0;
	in_alfa = 0;
	in_variable = 0;
	in_min_interest = 0;
	in_gamma = 0;
	in_profits = 0;
	in_lambda = 0;
	in_bce_interest = 0;
	in_debt_period = 0;
	in_loan_request_message_found = 0;
	in_total_deposit = 0;
	in_bank_account = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	interest = init_double_array();
//	credit_offer = init_double_array();
//	contacted_bank = init_int_array();
//	total_debt = 0.0;
//	asset = 0.0;
//	credit_demand = 0.0;
//	installment_amount = init_double_array();
//	installment_number = 0;
//	loans_number = 0;
//	outstanding_debt = init_double_array();
//	lending_bank_id = init_int_array();
//	interest_amount = init_double_array();
//	bankruptcy_state = 0;
//	total_resources = 0.0;
//	residual_variable = init_double_array();
//	variable_per_installment = init_double_array();
//	value_at_risk = init_double_array();
//	interest_left = init_double_array();
//	current_equity = 0.0;
//	current_debt = 0.0;
//	cash = 0.0;
//	total_credit = 0.0;
//	equity = 0.0;
//	bce_debt = 0.0;
//	alfa = 0.0;
//	variable = 0.0;
//	min_interest = 0.0;
//////	lambda = 0.0;
//	bce_interest = 0.0;
//	debt_period = 0.0;
//	loan_request_message_found = 0;
//	total_deposit = 0.0;
//	bank_account = 0;







	if(partition_method==geometric) printf("xml: Geometric partitioning\n");
	else if(partition_method==other) printf("xml: Round-robin partitioning\n");
	else printf("xml: Error - invalid partitioning method\n");


	/* Set p_xmachine to the agent list passed in then new agents are added to this list 
	 * Will be set to agent list for specific node is space partitions are already known (flag=1)
	 */ 
	//p_xmachine = agent_list;
	/* If we're reading without knowing partitions already then use the dummy current node (it's not in the list of nodes)*/
	if (flag == 0) current_node = &temp_node;
	
	/* Read file until end of xml */
	while(reading==1)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		
		/* If the end of a tag */
		if(c == '>')
		{
			/* Place 0 at end of buffer to make chars a string */
			buffer[i] = 0;
			
			if(strcmp(buffer, "states") == 0) reading = 1;
			if(strcmp(buffer, "/states") == 0) reading = 0;
			if(strcmp(buffer, "itno") == 0) in_itno = 1;
			if(strcmp(buffer, "/itno") == 0) in_itno = 0;
			if(strcmp(buffer, "name") == 0) in_name = 1;
			if(strcmp(buffer, "/name") == 0)
			{
				in_name = 0;
				
				if(in_agent && !in_memory && !in_functions)
				{
					/*printf("in agent: %s\n", agentname);*/
					if(strcmp(agentname, "Firm") == 0)
					{
						current_Firm_agent = init_Firm_agent();
						in_Firm_agent = 1;
					}
					else if(strcmp(agentname, "Bank") == 0)
					{
						current_Bank_agent = init_Bank_agent();
						in_Bank_agent = 1;
					}
					else if(strcmp(agentname, "Household") == 0)
					{
						current_Household_agent = init_Household_agent();
						in_Household_agent = 1;
					}

				}
			}
			if(strcmp(buffer, "environment") == 0) in_environment = 1;
			if(strcmp(buffer, "/environment") == 0) in_environment = 0;
			if(strcmp(buffer, "memory") == 0) in_memory = 1;
			if(strcmp(buffer, "/memory") == 0) in_memory = 0;
			if(strcmp(buffer, "functions") == 0) in_functions = 1;
			if(strcmp(buffer, "/functions") == 0) in_functions = 0;
			if(strcmp(buffer, "xagent") == 0) in_agent = 1;
			if(strcmp(buffer, "/xagent") == 0)
			{
				in_agent = 0;
				in_Firm_agent = 0;
in_Bank_agent = 0;
in_Household_agent = 0;

				
				if(strcmp(agentname, "Firm") == 0)
				{
					/*posx = current_Firm_agent->;
					posy = current_Firm_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Firm_agent(id, interest, credit_offer, contacted_bank, total_debt, asset, credit_demand, installment_amount, installment_number, loans_number, outstanding_debt, lending_bank_id, interest_amount, bankruptcy_state, total_resources, residual_variable, variable_per_installment, value_at_risk, interest_left, current_equity, current_debt);
						add_Firm_agent_internal(current_Firm_agent, Firm_firm_start_state);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}

					else if (flag != 0)
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								//p_xmachine = &(current_node->agents);
								//add_Firm_agent(id, interest, credit_offer, contacted_bank, total_debt, asset, credit_demand, installment_amount, installment_number, loans_number, outstanding_debt, lending_bank_id, interest_amount, bankruptcy_state, total_resources, residual_variable, variable_per_installment, value_at_risk, interest_left, current_equity, current_debt);
								add_Firm_agent_internal(current_Firm_agent, Firm_firm_start_state);
							} 
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								//p_xmachine = &(current_node->agents);
								//add_Firm_agent(id, interest, credit_offer, contacted_bank, total_debt, asset, credit_demand, installment_amount, installment_number, loans_number, outstanding_debt, lending_bank_id, interest_amount, bankruptcy_state, total_resources, residual_variable, variable_per_installment, value_at_risk, interest_left, current_equity, current_debt);
								add_Firm_agent_internal(current_Firm_agent, Firm_firm_start_state);

								/*current_Firm_agent-> = xcentre;
								current_Firm_agent-> = ycentre;
								current_Firm_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Bank") == 0)
				{
					/*posx = current_Bank_agent->;
					posy = current_Bank_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Bank_agent(id, cash, total_credit, equity, bce_debt, alfa, variable, min_interest, gamma, profits, lambda, bce_interest, debt_period, loan_request_message_found);
						add_Bank_agent_internal(current_Bank_agent, Bank_Bank_start_state);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}

					else if (flag != 0)
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								//p_xmachine = &(current_node->agents);
								//add_Bank_agent(id, cash, total_credit, equity, bce_debt, alfa, variable, min_interest, gamma, profits, lambda, bce_interest, debt_period, loan_request_message_found);
								add_Bank_agent_internal(current_Bank_agent, Bank_Bank_start_state);
							} 
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								//p_xmachine = &(current_node->agents);
								//add_Bank_agent(id, cash, total_credit, equity, bce_debt, alfa, variable, min_interest, gamma, profits, lambda, bce_interest, debt_period, loan_request_message_found);
								add_Bank_agent_internal(current_Bank_agent, Bank_Bank_start_state);

								/*current_Bank_agent-> = xcentre;
								current_Bank_agent-> = ycentre;
								current_Bank_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Household") == 0)
				{
					/*posx = current_Household_agent->;
					posy = current_Household_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Household_agent(id, total_deposit, bank_account);
						add_Household_agent_internal(current_Household_agent, Household_HH_start_state);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}

					else if (flag != 0)
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								//p_xmachine = &(current_node->agents);
								//add_Household_agent(id, total_deposit, bank_account);
								add_Household_agent_internal(current_Household_agent, Household_HH_start_state);
							} 
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								//p_xmachine = &(current_node->agents);
								//add_Household_agent(id, total_deposit, bank_account);
								add_Household_agent_internal(current_Household_agent, Household_HH_start_state);

								/*current_Household_agent-> = xcentre;
								current_Household_agent-> = ycentre;
								current_Household_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else
				{
					printf("Warning: agent name undefined - '%s'\n", agentname);
				}
				

				
				/* Reset xagent variables */
				/* Not implemented static arrays */
//				id = 0;
////////				total_debt = 0.0;
//				asset = 0.0;
//				credit_demand = 0.0;
////				installment_number = 0;
//				loans_number = 0;
////////				bankruptcy_state = 0;
//				total_resources = 0.0;
//////////				current_equity = 0.0;
//				current_debt = 0.0;
//				cash = 0.0;
//				total_credit = 0.0;
//				equity = 0.0;
//				bce_debt = 0.0;
//				alfa = 0.0;
//				variable = 0.0;
//				min_interest = 0.0;
//////				lambda = 0.0;
//				bce_interest = 0.0;
//				debt_period = 0.0;
//				loan_request_message_found = 0;
//				total_deposit = 0.0;
//				bank_account = 0;

	}
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "interest") == 0) in_interest = 1;
			if(strcmp(buffer, "/interest") == 0) in_interest = 0;
			if(strcmp(buffer, "credit_offer") == 0) in_credit_offer = 1;
			if(strcmp(buffer, "/credit_offer") == 0) in_credit_offer = 0;
			if(strcmp(buffer, "contacted_bank") == 0) in_contacted_bank = 1;
			if(strcmp(buffer, "/contacted_bank") == 0) in_contacted_bank = 0;
			if(strcmp(buffer, "total_debt") == 0) in_total_debt = 1;
			if(strcmp(buffer, "/total_debt") == 0) in_total_debt = 0;
			if(strcmp(buffer, "asset") == 0) in_asset = 1;
			if(strcmp(buffer, "/asset") == 0) in_asset = 0;
			if(strcmp(buffer, "credit_demand") == 0) in_credit_demand = 1;
			if(strcmp(buffer, "/credit_demand") == 0) in_credit_demand = 0;
			if(strcmp(buffer, "installment_amount") == 0) in_installment_amount = 1;
			if(strcmp(buffer, "/installment_amount") == 0) in_installment_amount = 0;
			if(strcmp(buffer, "installment_number") == 0) in_installment_number = 1;
			if(strcmp(buffer, "/installment_number") == 0) in_installment_number = 0;
			if(strcmp(buffer, "loans_number") == 0) in_loans_number = 1;
			if(strcmp(buffer, "/loans_number") == 0) in_loans_number = 0;
			if(strcmp(buffer, "outstanding_debt") == 0) in_outstanding_debt = 1;
			if(strcmp(buffer, "/outstanding_debt") == 0) in_outstanding_debt = 0;
			if(strcmp(buffer, "lending_bank_id") == 0) in_lending_bank_id = 1;
			if(strcmp(buffer, "/lending_bank_id") == 0) in_lending_bank_id = 0;
			if(strcmp(buffer, "interest_amount") == 0) in_interest_amount = 1;
			if(strcmp(buffer, "/interest_amount") == 0) in_interest_amount = 0;
			if(strcmp(buffer, "bankruptcy_state") == 0) in_bankruptcy_state = 1;
			if(strcmp(buffer, "/bankruptcy_state") == 0) in_bankruptcy_state = 0;
			if(strcmp(buffer, "total_resources") == 0) in_total_resources = 1;
			if(strcmp(buffer, "/total_resources") == 0) in_total_resources = 0;
			if(strcmp(buffer, "residual_variable") == 0) in_residual_variable = 1;
			if(strcmp(buffer, "/residual_variable") == 0) in_residual_variable = 0;
			if(strcmp(buffer, "variable_per_installment") == 0) in_variable_per_installment = 1;
			if(strcmp(buffer, "/variable_per_installment") == 0) in_variable_per_installment = 0;
			if(strcmp(buffer, "value_at_risk") == 0) in_value_at_risk = 1;
			if(strcmp(buffer, "/value_at_risk") == 0) in_value_at_risk = 0;
			if(strcmp(buffer, "interest_left") == 0) in_interest_left = 1;
			if(strcmp(buffer, "/interest_left") == 0) in_interest_left = 0;
			if(strcmp(buffer, "current_equity") == 0) in_current_equity = 1;
			if(strcmp(buffer, "/current_equity") == 0) in_current_equity = 0;
			if(strcmp(buffer, "current_debt") == 0) in_current_debt = 1;
			if(strcmp(buffer, "/current_debt") == 0) in_current_debt = 0;
			if(strcmp(buffer, "cash") == 0) in_cash = 1;
			if(strcmp(buffer, "/cash") == 0) in_cash = 0;
			if(strcmp(buffer, "total_credit") == 0) in_total_credit = 1;
			if(strcmp(buffer, "/total_credit") == 0) in_total_credit = 0;
			if(strcmp(buffer, "equity") == 0) in_equity = 1;
			if(strcmp(buffer, "/equity") == 0) in_equity = 0;
			if(strcmp(buffer, "bce_debt") == 0) in_bce_debt = 1;
			if(strcmp(buffer, "/bce_debt") == 0) in_bce_debt = 0;
			if(strcmp(buffer, "alfa") == 0) in_alfa = 1;
			if(strcmp(buffer, "/alfa") == 0) in_alfa = 0;
			if(strcmp(buffer, "variable") == 0) in_variable = 1;
			if(strcmp(buffer, "/variable") == 0) in_variable = 0;
			if(strcmp(buffer, "min_interest") == 0) in_min_interest = 1;
			if(strcmp(buffer, "/min_interest") == 0) in_min_interest = 0;
			if(strcmp(buffer, "gamma") == 0) in_gamma = 1;
			if(strcmp(buffer, "/gamma") == 0) in_gamma = 0;
			if(strcmp(buffer, "profits") == 0) in_profits = 1;
			if(strcmp(buffer, "/profits") == 0) in_profits = 0;
			if(strcmp(buffer, "lambda") == 0) in_lambda = 1;
			if(strcmp(buffer, "/lambda") == 0) in_lambda = 0;
			if(strcmp(buffer, "bce_interest") == 0) in_bce_interest = 1;
			if(strcmp(buffer, "/bce_interest") == 0) in_bce_interest = 0;
			if(strcmp(buffer, "debt_period") == 0) in_debt_period = 1;
			if(strcmp(buffer, "/debt_period") == 0) in_debt_period = 0;
			if(strcmp(buffer, "loan_request_message_found") == 0) in_loan_request_message_found = 1;
			if(strcmp(buffer, "/loan_request_message_found") == 0) in_loan_request_message_found = 0;
			if(strcmp(buffer, "total_deposit") == 0) in_total_deposit = 1;
			if(strcmp(buffer, "/total_deposit") == 0) in_total_deposit = 0;
			if(strcmp(buffer, "bank_account") == 0) in_bank_account = 1;
			if(strcmp(buffer, "/bank_account") == 0) in_bank_account = 0;


			
			/* End of tag and reset buffer */
			in_tag = 0;
			i = 0;
		}
		/* If start of tag */
		else if(c == '<')
		{
			/* Place /0 at end of buffer to end numbers */
			buffer[i] = 0;
			/* Flag in tag */
			in_tag = 1;
			j = 0;
			
			if(in_itno) *itno = atoi(buffer);
			if(in_name) strcpy(agentname, buffer);
			if(in_environment)
			{
			}
			else if(in_Firm_agent == 1)
			{
				if(in_id) current_Firm_agent->id = atoi(buffer);
				if(in_interest) read_double_dynamic_array(buffer, &j, &current_Firm_agent->interest);
				if(in_credit_offer) read_double_dynamic_array(buffer, &j, &current_Firm_agent->credit_offer);
				if(in_contacted_bank) read_int_dynamic_array(buffer, &j, &current_Firm_agent->contacted_bank);
				if(in_total_debt) current_Firm_agent->total_debt = atof(buffer);
				if(in_asset) current_Firm_agent->asset = atof(buffer);
				if(in_credit_demand) current_Firm_agent->credit_demand = atof(buffer);
				if(in_installment_amount) read_double_dynamic_array(buffer, &j, &current_Firm_agent->installment_amount);
				if(in_installment_number) current_Firm_agent->installment_number = atoi(buffer);
				if(in_loans_number) current_Firm_agent->loans_number = atoi(buffer);
				if(in_outstanding_debt) read_double_dynamic_array(buffer, &j, &current_Firm_agent->outstanding_debt);
				if(in_lending_bank_id) read_int_dynamic_array(buffer, &j, &current_Firm_agent->lending_bank_id);
				if(in_interest_amount) read_double_dynamic_array(buffer, &j, &current_Firm_agent->interest_amount);
				if(in_bankruptcy_state) current_Firm_agent->bankruptcy_state = atoi(buffer);
				if(in_total_resources) current_Firm_agent->total_resources = atof(buffer);
				if(in_residual_variable) read_double_dynamic_array(buffer, &j, &current_Firm_agent->residual_variable);
				if(in_variable_per_installment) read_double_dynamic_array(buffer, &j, &current_Firm_agent->variable_per_installment);
				if(in_value_at_risk) read_double_dynamic_array(buffer, &j, &current_Firm_agent->value_at_risk);
				if(in_interest_left) read_double_dynamic_array(buffer, &j, &current_Firm_agent->interest_left);
				if(in_current_equity) current_Firm_agent->current_equity = atof(buffer);
				if(in_current_debt) current_Firm_agent->current_debt = atof(buffer);
			}
			else if(in_Bank_agent == 1)
			{
				if(in_id) current_Bank_agent->id = atoi(buffer);
				if(in_cash) current_Bank_agent->cash = atof(buffer);
				if(in_total_credit) current_Bank_agent->total_credit = atof(buffer);
				if(in_equity) current_Bank_agent->equity = atof(buffer);
				if(in_bce_debt) current_Bank_agent->bce_debt = atof(buffer);
				if(in_alfa) current_Bank_agent->alfa = atof(buffer);
				if(in_variable) current_Bank_agent->variable = atof(buffer);
				if(in_min_interest) current_Bank_agent->min_interest = atof(buffer);
				if(in_gamma) read_double_static_array(buffer, &j, current_Bank_agent->gamma, 2);
				if(in_profits) read_double_static_array(buffer, &j, current_Bank_agent->profits, 2);
				if(in_lambda) current_Bank_agent->lambda = atof(buffer);
				if(in_bce_interest) current_Bank_agent->bce_interest = atof(buffer);
				if(in_debt_period) current_Bank_agent->debt_period = atof(buffer);
				if(in_loan_request_message_found) current_Bank_agent->loan_request_message_found = atoi(buffer);
			}
			else if(in_Household_agent == 1)
			{
				if(in_id) current_Household_agent->id = atoi(buffer);
				if(in_total_deposit) current_Household_agent->total_deposit = atof(buffer);
				if(in_bank_account) current_Household_agent->bank_account = atoi(buffer);
			}
			
			/* Reset buffer */
			i = 0;
		}
		/* If in tag put read char into buffer */
		else if(in_tag)
		{
			buffer[i] = c;
			i++;
		}
		/* If in data read char into buffer */
		else
		{
			buffer[i] = c;
			i++;
		}
	}
	/* Make sure cloud data makes sense if any of x,y,z coords were all the same */
	if ( partition_method == geometric ) {
		if ( cloud_data[0] == cloud_data[1] ) {
			cloud_data[0] = -SPINF;
			cloud_data[1] = SPINF;
		}
		if ( cloud_data[2] == cloud_data[3] ) {
			cloud_data[2] = -SPINF;
			cloud_data[3] = SPINF;
		}
		if ( cloud_data[4] == cloud_data[5] ) {
			cloud_data[4] = -SPINF;
			cloud_data[5] = SPINF;
		}
	}

	/* Close the file */
	fclose(file);
	/* Free temp data structures */
////	free_double_array(interest);
//	free_double_array(credit_offer);
//	free_int_array(contacted_bank);
////////	free_double_array(installment_amount);
//////	free_double_array(outstanding_debt);
//	free_int_array(lending_bank_id);
//	free_double_array(interest_amount);
//////	free_double_array(residual_variable);
//	free_double_array(variable_per_installment);
//	free_double_array(value_at_risk);
//	free_double_array(interest_left);
//////////////////////////////////
}

/** \fn void write_int_static_array(FILE *file, $name * temp)
 * \brief Writes int.
 */
void write_int_static_array(FILE *file, int * temp, int size)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%i", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_static_array(FILE *file, float * temp)
 * \brief Writes float.
 */
void write_float_static_array(FILE *file, float * temp, int size)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_static_array(FILE *file, double * temp)
 * \brief Writes double.
 */
void write_double_static_array(FILE *file, double * temp, int size)
{
	int i;
	char data[1000];
	
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_static_array(FILE *file, char * temp)
 * \brief Writes char.
 */
void write_char_static_array(FILE *file, char * temp, int size)
{
	int i;
	char data[1000];
	
	//fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%c", temp[i]);
		fputs(data, file);
		//if(i < size-1) fputs(", ", file);
	}
	//fputs("}", file);
}

/** \fn void write_int_dynamic_array(FILE *file, int_array* temp)
 * \brief Writes int.
 */
void write_int_dynamic_array(FILE *file, int_array * temp)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%i", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_dynamic_array(FILE *file, float_array* temp)
 * \brief Writes float.
 */
void write_float_dynamic_array(FILE *file, float_array * temp)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_dynamic_array(FILE *file, double_array* temp)
 * \brief Writes double.
 */
void write_double_dynamic_array(FILE *file, double_array * temp)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_dynamic_array(FILE *file, char_array* temp)
 * \brief Writes char.
 */
void write_char_dynamic_array(FILE *file, char_array * temp)
{
	int i;
	char data[1000];
	
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%c", (*temp).array[i]);
		fputs(data, file);
	}
}



void write_Firm_agent(FILE *file, xmachine_memory_Firm * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Firm</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<interest>", file);
	write_double_dynamic_array(file, &current->interest);
	fputs("</interest>\n", file);
		fputs("<credit_offer>", file);
	write_double_dynamic_array(file, &current->credit_offer);
	fputs("</credit_offer>\n", file);
		fputs("<contacted_bank>", file);
	write_int_dynamic_array(file, &current->contacted_bank);
	fputs("</contacted_bank>\n", file);
		fputs("<total_debt>", file);
	sprintf(data, "%f", current->total_debt);
	fputs(data, file);
	fputs("</total_debt>\n", file);
		fputs("<asset>", file);
	sprintf(data, "%f", current->asset);
	fputs(data, file);
	fputs("</asset>\n", file);
		fputs("<credit_demand>", file);
	sprintf(data, "%f", current->credit_demand);
	fputs(data, file);
	fputs("</credit_demand>\n", file);
		fputs("<installment_amount>", file);
	write_double_dynamic_array(file, &current->installment_amount);
	fputs("</installment_amount>\n", file);
		fputs("<installment_number>", file);
	sprintf(data, "%i", current->installment_number);
	fputs(data, file);
	fputs("</installment_number>\n", file);
		fputs("<loans_number>", file);
	sprintf(data, "%i", current->loans_number);
	fputs(data, file);
	fputs("</loans_number>\n", file);
		fputs("<outstanding_debt>", file);
	write_double_dynamic_array(file, &current->outstanding_debt);
	fputs("</outstanding_debt>\n", file);
		fputs("<lending_bank_id>", file);
	write_int_dynamic_array(file, &current->lending_bank_id);
	fputs("</lending_bank_id>\n", file);
		fputs("<interest_amount>", file);
	write_double_dynamic_array(file, &current->interest_amount);
	fputs("</interest_amount>\n", file);
		fputs("<bankruptcy_state>", file);
	sprintf(data, "%i", current->bankruptcy_state);
	fputs(data, file);
	fputs("</bankruptcy_state>\n", file);
		fputs("<total_resources>", file);
	sprintf(data, "%f", current->total_resources);
	fputs(data, file);
	fputs("</total_resources>\n", file);
		fputs("<residual_variable>", file);
	write_double_dynamic_array(file, &current->residual_variable);
	fputs("</residual_variable>\n", file);
		fputs("<variable_per_installment>", file);
	write_double_dynamic_array(file, &current->variable_per_installment);
	fputs("</variable_per_installment>\n", file);
		fputs("<value_at_risk>", file);
	write_double_dynamic_array(file, &current->value_at_risk);
	fputs("</value_at_risk>\n", file);
		fputs("<interest_left>", file);
	write_double_dynamic_array(file, &current->interest_left);
	fputs("</interest_left>\n", file);
		fputs("<current_equity>", file);
	sprintf(data, "%f", current->current_equity);
	fputs(data, file);
	fputs("</current_equity>\n", file);
		fputs("<current_debt>", file);
	sprintf(data, "%f", current->current_debt);
	fputs(data, file);
	fputs("</current_debt>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Bank_agent(FILE *file, xmachine_memory_Bank * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Bank</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<cash>", file);
	sprintf(data, "%f", current->cash);
	fputs(data, file);
	fputs("</cash>\n", file);
		fputs("<total_credit>", file);
	sprintf(data, "%f", current->total_credit);
	fputs(data, file);
	fputs("</total_credit>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<bce_debt>", file);
	sprintf(data, "%f", current->bce_debt);
	fputs(data, file);
	fputs("</bce_debt>\n", file);
		fputs("<alfa>", file);
	sprintf(data, "%f", current->alfa);
	fputs(data, file);
	fputs("</alfa>\n", file);
		fputs("<variable>", file);
	sprintf(data, "%f", current->variable);
	fputs(data, file);
	fputs("</variable>\n", file);
		fputs("<min_interest>", file);
	sprintf(data, "%f", current->min_interest);
	fputs(data, file);
	fputs("</min_interest>\n", file);
		fputs("<gamma>", file);
	write_double_static_array(file, current->gamma, 2);
	fputs("</gamma>\n", file);
		fputs("<profits>", file);
	write_double_static_array(file, current->profits, 2);
	fputs("</profits>\n", file);
		fputs("<lambda>", file);
	sprintf(data, "%f", current->lambda);
	fputs(data, file);
	fputs("</lambda>\n", file);
		fputs("<bce_interest>", file);
	sprintf(data, "%f", current->bce_interest);
	fputs(data, file);
	fputs("</bce_interest>\n", file);
		fputs("<debt_period>", file);
	sprintf(data, "%f", current->debt_period);
	fputs(data, file);
	fputs("</debt_period>\n", file);
		fputs("<loan_request_message_found>", file);
	sprintf(data, "%i", current->loan_request_message_found);
	fputs(data, file);
	fputs("</loan_request_message_found>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Household_agent(FILE *file, xmachine_memory_Household * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Household</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<total_deposit>", file);
	sprintf(data, "%f", current->total_deposit);
	fputs(data, file);
	fputs("</total_deposit>\n", file);
		fputs("<bank_account>", file);
	sprintf(data, "%i", current->bank_account);
	fputs(data, file);
	fputs("</bank_account>\n", file);
		
	fputs("</xagent>\n", file);
}


/** \fn void saveiterationdata(int iteration_number)
 * \brief Save X-machine memory to a file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata(int iteration_number)
{
	/* Pointer to file */
	FILE *file;
	char data[1000];
	//double_array * interest;
	//double_array * credit_offer;
	//int_array * contacted_bank;
	//double_array * installment_amount;
	//double_array * outstanding_debt;
	//int_array * lending_bank_id;
	//double_array * interest_amount;
	//double_array * residual_variable;
	//double_array * variable_per_installment;
	//double_array * value_at_risk;
	//double_array * interest_left;
	
	sprintf(data, "%s%i.xml", outputpath, iteration_number);
	file = fopen(data, "w");
	fputs("<states>\n<itno>", file);
	sprintf(data, "%i", iteration_number);
	fputs(data, file);
	fputs("</itno>\n", file);
	fputs("<environment>\n" , file);
	fputs("</environment>\n" , file);

//	current_xmachine = *p_xmachine;
// todo loop through all agent types

current_xmachine_Firm_holder = Firm_04_state->agents;
	while(current_xmachine_Firm_holder)
	{
		write_Firm_agent(file, current_xmachine_Firm_holder->agent);
		
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}

current_xmachine_Bank_holder = Bank_05_state->agents;
	while(current_xmachine_Bank_holder)
	{
		write_Bank_agent(file, current_xmachine_Bank_holder->agent);
		
		current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
	}

current_xmachine_Household_holder = Household_01_state->agents;
	while(current_xmachine_Household_holder)
	{
		write_Household_agent(file, current_xmachine_Household_holder->agent);
		
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}
	
fputs("</states>\n" , file);
	
	/* Close the file */
	fclose(file);
	
	next_avaliable_id++;
}
