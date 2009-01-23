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
	char buffer[100000];
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
	double posx=0.0, posy=0.0, posz=0.0;
	
	
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
	int in_Household_agent;
	int in_Firm_agent;
	int in_Government_agent;
	int in_Central_Bank_agent;

	int in_id;
	int in_day_of_month_receive_income;
	int in_day_of_month_receive_benefit;
	int in_payment_account;
	int in_list_of_regions;
	int in_unemployment_benefit_pct;
	int in_tax_rate_corporate;
	int in_tax_rate_hh_labour;
	int in_tax_rate_hh_capital;
	int in_tax_rate_vat;
	int in_monthly_tax_revenues;
	int in_yearly_tax_revenues;
	int in_monthly_unemployment_benefit_payment;
	int in_yearly_unemployment_benefit_payment;
	int in_hh_transfer_payment;
	int in_firm_transfer_payment;
	int in_monthly_transfer_payment;
	int in_yearly_transfer_payment;
	int in_hh_subsidy_payment;
	int in_firm_subsidy_payment;
	int in_monthly_subsidy_payment;
	int in_yearly_subsidy_payment;
	int in_monthly_bond_coupon_payment;
	int in_yearly_bond_coupon_payment;
	int in_gov_interest_rate;
	int in_yearly_interest_payment;
	int in_yearly_gov_investment;
	int in_yearly_gov_consumption;
	int in_total_income;
	int in_total_expenditure;
	int in_total_debt;
	int in_budget_deficit;
	int in_total_money_financing;
	int in_total_bond_financing;
	int in_country_wide_mean_wage;
	int in_num_unemployed;
	int in_gdp;
	int in_gdp_growth;
	int in_gdp_forecast;
	int in_total_income_forecast;
	int in_total_expenditure_forecast;
	int in_budget_forecast;
	int in_bank_accounts;
	int in_gov_accounts;

	int in_gov_policy_unemployment_benefit_pct;
	int in_gov_policy_money_financing_fraction;
	int in_gov_policy_gdp_fraction_consumption;
	int in_gov_policy_gdp_fraction_investment;

	/* Variables for initial state data */
//	int id;
//	int day_of_month_receive_income;
//	int day_of_month_receive_benefit;
//	double payment_account;
//	int list_of_regions[1];
//	double unemployment_benefit_pct;
//	double tax_rate_corporate;
//	double tax_rate_hh_labour;
//	double tax_rate_hh_capital;
//	double tax_rate_vat;
//	double monthly_tax_revenues;
//	double yearly_tax_revenues;
//	double monthly_unemployment_benefit_payment;
//	double yearly_unemployment_benefit_payment;
//	double hh_transfer_payment;
//	double firm_transfer_payment;
//	double monthly_transfer_payment;
//	double yearly_transfer_payment;
//	double hh_subsidy_payment;
//	double firm_subsidy_payment;
//	double monthly_subsidy_payment;
//	double yearly_subsidy_payment;
//	double monthly_bond_coupon_payment;
//	double yearly_bond_coupon_payment;
//	double gov_interest_rate;
//	double yearly_interest_payment;
//	double yearly_gov_investment;
//	double yearly_gov_consumption;
//	double total_income;
//	double total_expenditure;
//	double total_debt;
//	double budget_deficit;
//	double total_money_financing;
//	double total_bond_financing;
//	double country_wide_mean_wage;
//	int num_unemployed;
//	double gdp;
//	double gdp_growth;
//	double gdp_forecast;
//	double total_income_forecast;
//	double total_expenditure_forecast;
//	double budget_forecast;
//	double bank_accounts[30];
//	double gov_accounts[30];


	xmachine_memory_Household * current_Household_agent;
	xmachine_memory_Firm * current_Firm_agent;
	xmachine_memory_Government * current_Government_agent;
	xmachine_memory_Central_Bank * current_Central_Bank_agent;


	/* Open config file to read-only */
	if((file = fopen(filename, "r"))==NULL)
	{
		printf("error opening initial states\n");
		exit(0);
	}
	/* Initialise variables */
    *itno = 0;
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
	in_Household_agent = 0;
	in_Firm_agent = 0;
	in_Government_agent = 0;
	in_Central_Bank_agent = 0;
	in_id = 0;
	in_day_of_month_receive_income = 0;
	in_day_of_month_receive_benefit = 0;
	in_payment_account = 0;
	in_list_of_regions = 0;
	in_unemployment_benefit_pct = 0;
	in_tax_rate_corporate = 0;
	in_tax_rate_hh_labour = 0;
	in_tax_rate_hh_capital = 0;
	in_tax_rate_vat = 0;
	in_monthly_tax_revenues = 0;
	in_yearly_tax_revenues = 0;
	in_monthly_unemployment_benefit_payment = 0;
	in_yearly_unemployment_benefit_payment = 0;
	in_hh_transfer_payment = 0;
	in_firm_transfer_payment = 0;
	in_monthly_transfer_payment = 0;
	in_yearly_transfer_payment = 0;
	in_hh_subsidy_payment = 0;
	in_firm_subsidy_payment = 0;
	in_monthly_subsidy_payment = 0;
	in_yearly_subsidy_payment = 0;
	in_monthly_bond_coupon_payment = 0;
	in_yearly_bond_coupon_payment = 0;
	in_gov_interest_rate = 0;
	in_yearly_interest_payment = 0;
	in_yearly_gov_investment = 0;
	in_yearly_gov_consumption = 0;
	in_total_income = 0;
	in_total_expenditure = 0;
	in_total_debt = 0;
	in_budget_deficit = 0;
	in_total_money_financing = 0;
	in_total_bond_financing = 0;
	in_country_wide_mean_wage = 0;
	in_num_unemployed = 0;
	in_gdp = 0;
	in_gdp_growth = 0;
	in_gdp_forecast = 0;
	in_total_income_forecast = 0;
	in_total_expenditure_forecast = 0;
	in_budget_forecast = 0;
	in_bank_accounts = 0;
	in_gov_accounts = 0;
	in_gov_policy_unemployment_benefit_pct = 0;
	in_gov_policy_money_financing_fraction = 0;
	in_gov_policy_gdp_fraction_consumption = 0;
	in_gov_policy_gdp_fraction_investment = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	day_of_month_receive_income = 0;
//	day_of_month_receive_benefit = 0;
//	payment_account = 0.0;
////	unemployment_benefit_pct = 0.0;
//	tax_rate_corporate = 0.0;
//	tax_rate_hh_labour = 0.0;
//	tax_rate_hh_capital = 0.0;
//	tax_rate_vat = 0.0;
//	monthly_tax_revenues = 0.0;
//	yearly_tax_revenues = 0.0;
//	monthly_unemployment_benefit_payment = 0.0;
//	yearly_unemployment_benefit_payment = 0.0;
//	hh_transfer_payment = 0.0;
//	firm_transfer_payment = 0.0;
//	monthly_transfer_payment = 0.0;
//	yearly_transfer_payment = 0.0;
//	hh_subsidy_payment = 0.0;
//	firm_subsidy_payment = 0.0;
//	monthly_subsidy_payment = 0.0;
//	yearly_subsidy_payment = 0.0;
//	monthly_bond_coupon_payment = 0.0;
//	yearly_bond_coupon_payment = 0.0;
//	gov_interest_rate = 0.0;
//	yearly_interest_payment = 0.0;
//	yearly_gov_investment = 0.0;
//	yearly_gov_consumption = 0.0;
//	total_income = 0.0;
//	total_expenditure = 0.0;
//	total_debt = 0.0;
//	budget_deficit = 0.0;
//	total_money_financing = 0.0;
//	total_bond_financing = 0.0;
//	country_wide_mean_wage = 0.0;
//	num_unemployed = 0;
//	gdp = 0.0;
//	gdp_growth = 0.0;
//	gdp_forecast = 0.0;
//	total_income_forecast = 0.0;
//	total_expenditure_forecast = 0.0;
//	budget_forecast = 0.0;
////
	gov_policy_unemployment_benefit_pct = 0.0;
	gov_policy_money_financing_fraction = 0.0;
	gov_policy_gdp_fraction_consumption = 0.0;
	gov_policy_gdp_fraction_investment = 0.0;






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
					if(strcmp(agentname, "Household") == 0)
					{
						current_Household_agent = init_Household_agent();
						in_Household_agent = 1;
					}
					else if(strcmp(agentname, "Firm") == 0)
					{
						current_Firm_agent = init_Firm_agent();
						in_Firm_agent = 1;
					}
					else if(strcmp(agentname, "Government") == 0)
					{
						current_Government_agent = init_Government_agent();
						in_Government_agent = 1;
					}
					else if(strcmp(agentname, "Central_Bank") == 0)
					{
						current_Central_Bank_agent = init_Central_Bank_agent();
						in_Central_Bank_agent = 1;
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
				in_Household_agent = 0;
in_Firm_agent = 0;
in_Government_agent = 0;
in_Central_Bank_agent = 0;

				
				if(strcmp(agentname, "Household") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Household_agent(id, day_of_month_receive_income, day_of_month_receive_benefit);
						add_Household_agent_internal(current_Household_agent, Household_start_Household_state);
						
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
								//add_Household_agent(id, day_of_month_receive_income, day_of_month_receive_benefit);
								add_Household_agent_internal(current_Household_agent, Household_start_Household_state);
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
								//add_Household_agent(id, day_of_month_receive_income, day_of_month_receive_benefit);
								add_Household_agent_internal(current_Household_agent, Household_start_Household_state);

								/*current_Household_agent->0.0 = xcentre;
								current_Household_agent->0.0 = ycentre;
								current_Household_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Firm") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Firm_agent(id);
						add_Firm_agent_internal(current_Firm_agent, Firm_start_Firm_state);
						
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
								//add_Firm_agent(id);
								add_Firm_agent_internal(current_Firm_agent, Firm_start_Firm_state);
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
								//add_Firm_agent(id);
								add_Firm_agent_internal(current_Firm_agent, Firm_start_Firm_state);

								/*current_Firm_agent->0.0 = xcentre;
								current_Firm_agent->0.0 = ycentre;
								current_Firm_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Government") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Government_agent(id, payment_account, list_of_regions, unemployment_benefit_pct, tax_rate_corporate, tax_rate_hh_labour, tax_rate_hh_capital, tax_rate_vat, monthly_tax_revenues, yearly_tax_revenues, monthly_unemployment_benefit_payment, yearly_unemployment_benefit_payment, hh_transfer_payment, firm_transfer_payment, monthly_transfer_payment, yearly_transfer_payment, hh_subsidy_payment, firm_subsidy_payment, monthly_subsidy_payment, yearly_subsidy_payment, monthly_bond_coupon_payment, yearly_bond_coupon_payment, gov_interest_rate, yearly_interest_payment, yearly_gov_investment, yearly_gov_consumption, total_income, total_expenditure, total_debt, budget_deficit, total_money_financing, total_bond_financing, country_wide_mean_wage, num_unemployed, gdp, gdp_growth, gdp_forecast, total_income_forecast, total_expenditure_forecast, budget_forecast);
						add_Government_agent_internal(current_Government_agent, Government_start_Government_state);
						
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
								//add_Government_agent(id, payment_account, list_of_regions, unemployment_benefit_pct, tax_rate_corporate, tax_rate_hh_labour, tax_rate_hh_capital, tax_rate_vat, monthly_tax_revenues, yearly_tax_revenues, monthly_unemployment_benefit_payment, yearly_unemployment_benefit_payment, hh_transfer_payment, firm_transfer_payment, monthly_transfer_payment, yearly_transfer_payment, hh_subsidy_payment, firm_subsidy_payment, monthly_subsidy_payment, yearly_subsidy_payment, monthly_bond_coupon_payment, yearly_bond_coupon_payment, gov_interest_rate, yearly_interest_payment, yearly_gov_investment, yearly_gov_consumption, total_income, total_expenditure, total_debt, budget_deficit, total_money_financing, total_bond_financing, country_wide_mean_wage, num_unemployed, gdp, gdp_growth, gdp_forecast, total_income_forecast, total_expenditure_forecast, budget_forecast);
								add_Government_agent_internal(current_Government_agent, Government_start_Government_state);
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
								//add_Government_agent(id, payment_account, list_of_regions, unemployment_benefit_pct, tax_rate_corporate, tax_rate_hh_labour, tax_rate_hh_capital, tax_rate_vat, monthly_tax_revenues, yearly_tax_revenues, monthly_unemployment_benefit_payment, yearly_unemployment_benefit_payment, hh_transfer_payment, firm_transfer_payment, monthly_transfer_payment, yearly_transfer_payment, hh_subsidy_payment, firm_subsidy_payment, monthly_subsidy_payment, yearly_subsidy_payment, monthly_bond_coupon_payment, yearly_bond_coupon_payment, gov_interest_rate, yearly_interest_payment, yearly_gov_investment, yearly_gov_consumption, total_income, total_expenditure, total_debt, budget_deficit, total_money_financing, total_bond_financing, country_wide_mean_wage, num_unemployed, gdp, gdp_growth, gdp_forecast, total_income_forecast, total_expenditure_forecast, budget_forecast);
								add_Government_agent_internal(current_Government_agent, Government_start_Government_state);

								/*current_Government_agent->0.0 = xcentre;
								current_Government_agent->0.0 = ycentre;
								current_Government_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Central_Bank") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Central_Bank_agent(bank_accounts, gov_accounts);
						add_Central_Bank_agent_internal(current_Central_Bank_agent, Central_Bank_start_Central_Bank_state);
						
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
								//add_Central_Bank_agent(bank_accounts, gov_accounts);
								add_Central_Bank_agent_internal(current_Central_Bank_agent, Central_Bank_start_Central_Bank_state);
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
								//add_Central_Bank_agent(bank_accounts, gov_accounts);
								add_Central_Bank_agent_internal(current_Central_Bank_agent, Central_Bank_start_Central_Bank_state);

								/*current_Central_Bank_agent->0.0 = xcentre;
								current_Central_Bank_agent->0.0 = ycentre;
								current_Central_Bank_agent-> = rrange;*/

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
//				day_of_month_receive_income = 0;
//				day_of_month_receive_benefit = 0;
//				payment_account = 0.0;
////				unemployment_benefit_pct = 0.0;
//				tax_rate_corporate = 0.0;
//				tax_rate_hh_labour = 0.0;
//				tax_rate_hh_capital = 0.0;
//				tax_rate_vat = 0.0;
//				monthly_tax_revenues = 0.0;
//				yearly_tax_revenues = 0.0;
//				monthly_unemployment_benefit_payment = 0.0;
//				yearly_unemployment_benefit_payment = 0.0;
//				hh_transfer_payment = 0.0;
//				firm_transfer_payment = 0.0;
//				monthly_transfer_payment = 0.0;
//				yearly_transfer_payment = 0.0;
//				hh_subsidy_payment = 0.0;
//				firm_subsidy_payment = 0.0;
//				monthly_subsidy_payment = 0.0;
//				yearly_subsidy_payment = 0.0;
//				monthly_bond_coupon_payment = 0.0;
//				yearly_bond_coupon_payment = 0.0;
//				gov_interest_rate = 0.0;
//				yearly_interest_payment = 0.0;
//				yearly_gov_investment = 0.0;
//				yearly_gov_consumption = 0.0;
//				total_income = 0.0;
//				total_expenditure = 0.0;
//				total_debt = 0.0;
//				budget_deficit = 0.0;
//				total_money_financing = 0.0;
//				total_bond_financing = 0.0;
//				country_wide_mean_wage = 0.0;
//				num_unemployed = 0;
//				gdp = 0.0;
//				gdp_growth = 0.0;
//				gdp_forecast = 0.0;
//				total_income_forecast = 0.0;
//				total_expenditure_forecast = 0.0;
//				budget_forecast = 0.0;
////
	}
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "day_of_month_receive_income") == 0) in_day_of_month_receive_income = 1;
			if(strcmp(buffer, "/day_of_month_receive_income") == 0) in_day_of_month_receive_income = 0;
			if(strcmp(buffer, "day_of_month_receive_benefit") == 0) in_day_of_month_receive_benefit = 1;
			if(strcmp(buffer, "/day_of_month_receive_benefit") == 0) in_day_of_month_receive_benefit = 0;
			if(strcmp(buffer, "payment_account") == 0) in_payment_account = 1;
			if(strcmp(buffer, "/payment_account") == 0) in_payment_account = 0;
			if(strcmp(buffer, "list_of_regions") == 0) in_list_of_regions = 1;
			if(strcmp(buffer, "/list_of_regions") == 0) in_list_of_regions = 0;
			if(strcmp(buffer, "unemployment_benefit_pct") == 0) in_unemployment_benefit_pct = 1;
			if(strcmp(buffer, "/unemployment_benefit_pct") == 0) in_unemployment_benefit_pct = 0;
			if(strcmp(buffer, "tax_rate_corporate") == 0) in_tax_rate_corporate = 1;
			if(strcmp(buffer, "/tax_rate_corporate") == 0) in_tax_rate_corporate = 0;
			if(strcmp(buffer, "tax_rate_hh_labour") == 0) in_tax_rate_hh_labour = 1;
			if(strcmp(buffer, "/tax_rate_hh_labour") == 0) in_tax_rate_hh_labour = 0;
			if(strcmp(buffer, "tax_rate_hh_capital") == 0) in_tax_rate_hh_capital = 1;
			if(strcmp(buffer, "/tax_rate_hh_capital") == 0) in_tax_rate_hh_capital = 0;
			if(strcmp(buffer, "tax_rate_vat") == 0) in_tax_rate_vat = 1;
			if(strcmp(buffer, "/tax_rate_vat") == 0) in_tax_rate_vat = 0;
			if(strcmp(buffer, "monthly_tax_revenues") == 0) in_monthly_tax_revenues = 1;
			if(strcmp(buffer, "/monthly_tax_revenues") == 0) in_monthly_tax_revenues = 0;
			if(strcmp(buffer, "yearly_tax_revenues") == 0) in_yearly_tax_revenues = 1;
			if(strcmp(buffer, "/yearly_tax_revenues") == 0) in_yearly_tax_revenues = 0;
			if(strcmp(buffer, "monthly_unemployment_benefit_payment") == 0) in_monthly_unemployment_benefit_payment = 1;
			if(strcmp(buffer, "/monthly_unemployment_benefit_payment") == 0) in_monthly_unemployment_benefit_payment = 0;
			if(strcmp(buffer, "yearly_unemployment_benefit_payment") == 0) in_yearly_unemployment_benefit_payment = 1;
			if(strcmp(buffer, "/yearly_unemployment_benefit_payment") == 0) in_yearly_unemployment_benefit_payment = 0;
			if(strcmp(buffer, "hh_transfer_payment") == 0) in_hh_transfer_payment = 1;
			if(strcmp(buffer, "/hh_transfer_payment") == 0) in_hh_transfer_payment = 0;
			if(strcmp(buffer, "firm_transfer_payment") == 0) in_firm_transfer_payment = 1;
			if(strcmp(buffer, "/firm_transfer_payment") == 0) in_firm_transfer_payment = 0;
			if(strcmp(buffer, "monthly_transfer_payment") == 0) in_monthly_transfer_payment = 1;
			if(strcmp(buffer, "/monthly_transfer_payment") == 0) in_monthly_transfer_payment = 0;
			if(strcmp(buffer, "yearly_transfer_payment") == 0) in_yearly_transfer_payment = 1;
			if(strcmp(buffer, "/yearly_transfer_payment") == 0) in_yearly_transfer_payment = 0;
			if(strcmp(buffer, "hh_subsidy_payment") == 0) in_hh_subsidy_payment = 1;
			if(strcmp(buffer, "/hh_subsidy_payment") == 0) in_hh_subsidy_payment = 0;
			if(strcmp(buffer, "firm_subsidy_payment") == 0) in_firm_subsidy_payment = 1;
			if(strcmp(buffer, "/firm_subsidy_payment") == 0) in_firm_subsidy_payment = 0;
			if(strcmp(buffer, "monthly_subsidy_payment") == 0) in_monthly_subsidy_payment = 1;
			if(strcmp(buffer, "/monthly_subsidy_payment") == 0) in_monthly_subsidy_payment = 0;
			if(strcmp(buffer, "yearly_subsidy_payment") == 0) in_yearly_subsidy_payment = 1;
			if(strcmp(buffer, "/yearly_subsidy_payment") == 0) in_yearly_subsidy_payment = 0;
			if(strcmp(buffer, "monthly_bond_coupon_payment") == 0) in_monthly_bond_coupon_payment = 1;
			if(strcmp(buffer, "/monthly_bond_coupon_payment") == 0) in_monthly_bond_coupon_payment = 0;
			if(strcmp(buffer, "yearly_bond_coupon_payment") == 0) in_yearly_bond_coupon_payment = 1;
			if(strcmp(buffer, "/yearly_bond_coupon_payment") == 0) in_yearly_bond_coupon_payment = 0;
			if(strcmp(buffer, "gov_interest_rate") == 0) in_gov_interest_rate = 1;
			if(strcmp(buffer, "/gov_interest_rate") == 0) in_gov_interest_rate = 0;
			if(strcmp(buffer, "yearly_interest_payment") == 0) in_yearly_interest_payment = 1;
			if(strcmp(buffer, "/yearly_interest_payment") == 0) in_yearly_interest_payment = 0;
			if(strcmp(buffer, "yearly_gov_investment") == 0) in_yearly_gov_investment = 1;
			if(strcmp(buffer, "/yearly_gov_investment") == 0) in_yearly_gov_investment = 0;
			if(strcmp(buffer, "yearly_gov_consumption") == 0) in_yearly_gov_consumption = 1;
			if(strcmp(buffer, "/yearly_gov_consumption") == 0) in_yearly_gov_consumption = 0;
			if(strcmp(buffer, "total_income") == 0) in_total_income = 1;
			if(strcmp(buffer, "/total_income") == 0) in_total_income = 0;
			if(strcmp(buffer, "total_expenditure") == 0) in_total_expenditure = 1;
			if(strcmp(buffer, "/total_expenditure") == 0) in_total_expenditure = 0;
			if(strcmp(buffer, "total_debt") == 0) in_total_debt = 1;
			if(strcmp(buffer, "/total_debt") == 0) in_total_debt = 0;
			if(strcmp(buffer, "budget_deficit") == 0) in_budget_deficit = 1;
			if(strcmp(buffer, "/budget_deficit") == 0) in_budget_deficit = 0;
			if(strcmp(buffer, "total_money_financing") == 0) in_total_money_financing = 1;
			if(strcmp(buffer, "/total_money_financing") == 0) in_total_money_financing = 0;
			if(strcmp(buffer, "total_bond_financing") == 0) in_total_bond_financing = 1;
			if(strcmp(buffer, "/total_bond_financing") == 0) in_total_bond_financing = 0;
			if(strcmp(buffer, "country_wide_mean_wage") == 0) in_country_wide_mean_wage = 1;
			if(strcmp(buffer, "/country_wide_mean_wage") == 0) in_country_wide_mean_wage = 0;
			if(strcmp(buffer, "num_unemployed") == 0) in_num_unemployed = 1;
			if(strcmp(buffer, "/num_unemployed") == 0) in_num_unemployed = 0;
			if(strcmp(buffer, "gdp") == 0) in_gdp = 1;
			if(strcmp(buffer, "/gdp") == 0) in_gdp = 0;
			if(strcmp(buffer, "gdp_growth") == 0) in_gdp_growth = 1;
			if(strcmp(buffer, "/gdp_growth") == 0) in_gdp_growth = 0;
			if(strcmp(buffer, "gdp_forecast") == 0) in_gdp_forecast = 1;
			if(strcmp(buffer, "/gdp_forecast") == 0) in_gdp_forecast = 0;
			if(strcmp(buffer, "total_income_forecast") == 0) in_total_income_forecast = 1;
			if(strcmp(buffer, "/total_income_forecast") == 0) in_total_income_forecast = 0;
			if(strcmp(buffer, "total_expenditure_forecast") == 0) in_total_expenditure_forecast = 1;
			if(strcmp(buffer, "/total_expenditure_forecast") == 0) in_total_expenditure_forecast = 0;
			if(strcmp(buffer, "budget_forecast") == 0) in_budget_forecast = 1;
			if(strcmp(buffer, "/budget_forecast") == 0) in_budget_forecast = 0;
			if(strcmp(buffer, "bank_accounts") == 0) in_bank_accounts = 1;
			if(strcmp(buffer, "/bank_accounts") == 0) in_bank_accounts = 0;
			if(strcmp(buffer, "gov_accounts") == 0) in_gov_accounts = 1;
			if(strcmp(buffer, "/gov_accounts") == 0) in_gov_accounts = 0;

			if(strcmp(buffer, "gov_policy_unemployment_benefit_pct") == 0) in_gov_policy_unemployment_benefit_pct = 1;
			if(strcmp(buffer, "/gov_policy_unemployment_benefit_pct") == 0) in_gov_policy_unemployment_benefit_pct = 0;
			if(strcmp(buffer, "gov_policy_money_financing_fraction") == 0) in_gov_policy_money_financing_fraction = 1;
			if(strcmp(buffer, "/gov_policy_money_financing_fraction") == 0) in_gov_policy_money_financing_fraction = 0;
			if(strcmp(buffer, "gov_policy_gdp_fraction_consumption") == 0) in_gov_policy_gdp_fraction_consumption = 1;
			if(strcmp(buffer, "/gov_policy_gdp_fraction_consumption") == 0) in_gov_policy_gdp_fraction_consumption = 0;
			if(strcmp(buffer, "gov_policy_gdp_fraction_investment") == 0) in_gov_policy_gdp_fraction_investment = 1;
			if(strcmp(buffer, "/gov_policy_gdp_fraction_investment") == 0) in_gov_policy_gdp_fraction_investment = 0;

			
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
				if(in_gov_policy_unemployment_benefit_pct) gov_policy_unemployment_benefit_pct = atof(buffer);
				if(in_gov_policy_money_financing_fraction) gov_policy_money_financing_fraction = atof(buffer);
				if(in_gov_policy_gdp_fraction_consumption) gov_policy_gdp_fraction_consumption = atof(buffer);
				if(in_gov_policy_gdp_fraction_investment) gov_policy_gdp_fraction_investment = atof(buffer);
			}
			else if(in_Household_agent == 1)
			{
				if(in_id) current_Household_agent->id = atoi(buffer);
				if(in_day_of_month_receive_income) current_Household_agent->day_of_month_receive_income = atoi(buffer);
				if(in_day_of_month_receive_benefit) current_Household_agent->day_of_month_receive_benefit = atoi(buffer);
			}
			else if(in_Firm_agent == 1)
			{
				if(in_id) current_Firm_agent->id = atoi(buffer);
			}
			else if(in_Government_agent == 1)
			{
				if(in_id) current_Government_agent->id = atoi(buffer);
				if(in_payment_account) current_Government_agent->payment_account = atof(buffer);
				if(in_list_of_regions) read_int_static_array(buffer, &j, current_Government_agent->list_of_regions, 1);
				if(in_unemployment_benefit_pct) current_Government_agent->unemployment_benefit_pct = atof(buffer);
				if(in_tax_rate_corporate) current_Government_agent->tax_rate_corporate = atof(buffer);
				if(in_tax_rate_hh_labour) current_Government_agent->tax_rate_hh_labour = atof(buffer);
				if(in_tax_rate_hh_capital) current_Government_agent->tax_rate_hh_capital = atof(buffer);
				if(in_tax_rate_vat) current_Government_agent->tax_rate_vat = atof(buffer);
				if(in_monthly_tax_revenues) current_Government_agent->monthly_tax_revenues = atof(buffer);
				if(in_yearly_tax_revenues) current_Government_agent->yearly_tax_revenues = atof(buffer);
				if(in_monthly_unemployment_benefit_payment) current_Government_agent->monthly_unemployment_benefit_payment = atof(buffer);
				if(in_yearly_unemployment_benefit_payment) current_Government_agent->yearly_unemployment_benefit_payment = atof(buffer);
				if(in_hh_transfer_payment) current_Government_agent->hh_transfer_payment = atof(buffer);
				if(in_firm_transfer_payment) current_Government_agent->firm_transfer_payment = atof(buffer);
				if(in_monthly_transfer_payment) current_Government_agent->monthly_transfer_payment = atof(buffer);
				if(in_yearly_transfer_payment) current_Government_agent->yearly_transfer_payment = atof(buffer);
				if(in_hh_subsidy_payment) current_Government_agent->hh_subsidy_payment = atof(buffer);
				if(in_firm_subsidy_payment) current_Government_agent->firm_subsidy_payment = atof(buffer);
				if(in_monthly_subsidy_payment) current_Government_agent->monthly_subsidy_payment = atof(buffer);
				if(in_yearly_subsidy_payment) current_Government_agent->yearly_subsidy_payment = atof(buffer);
				if(in_monthly_bond_coupon_payment) current_Government_agent->monthly_bond_coupon_payment = atof(buffer);
				if(in_yearly_bond_coupon_payment) current_Government_agent->yearly_bond_coupon_payment = atof(buffer);
				if(in_gov_interest_rate) current_Government_agent->gov_interest_rate = atof(buffer);
				if(in_yearly_interest_payment) current_Government_agent->yearly_interest_payment = atof(buffer);
				if(in_yearly_gov_investment) current_Government_agent->yearly_gov_investment = atof(buffer);
				if(in_yearly_gov_consumption) current_Government_agent->yearly_gov_consumption = atof(buffer);
				if(in_total_income) current_Government_agent->total_income = atof(buffer);
				if(in_total_expenditure) current_Government_agent->total_expenditure = atof(buffer);
				if(in_total_debt) current_Government_agent->total_debt = atof(buffer);
				if(in_budget_deficit) current_Government_agent->budget_deficit = atof(buffer);
				if(in_total_money_financing) current_Government_agent->total_money_financing = atof(buffer);
				if(in_total_bond_financing) current_Government_agent->total_bond_financing = atof(buffer);
				if(in_country_wide_mean_wage) current_Government_agent->country_wide_mean_wage = atof(buffer);
				if(in_num_unemployed) current_Government_agent->num_unemployed = atoi(buffer);
				if(in_gdp) current_Government_agent->gdp = atof(buffer);
				if(in_gdp_growth) current_Government_agent->gdp_growth = atof(buffer);
				if(in_gdp_forecast) current_Government_agent->gdp_forecast = atof(buffer);
				if(in_total_income_forecast) current_Government_agent->total_income_forecast = atof(buffer);
				if(in_total_expenditure_forecast) current_Government_agent->total_expenditure_forecast = atof(buffer);
				if(in_budget_forecast) current_Government_agent->budget_forecast = atof(buffer);
			}
			else if(in_Central_Bank_agent == 1)
			{
				if(in_bank_accounts) read_double_static_array(buffer, &j, current_Central_Bank_agent->bank_accounts, 30);
				if(in_gov_accounts) read_double_static_array(buffer, &j, current_Central_Bank_agent->gov_accounts, 30);
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
////////////////////////////////////////////////////////////////////////////////////////
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
	
	fputs("{", file);
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



void write_Household_agent(FILE *file, xmachine_memory_Household * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Household</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<day_of_month_receive_income>", file);
	sprintf(data, "%i", current->day_of_month_receive_income);
	fputs(data, file);
	fputs("</day_of_month_receive_income>\n", file);
		fputs("<day_of_month_receive_benefit>", file);
	sprintf(data, "%i", current->day_of_month_receive_benefit);
	fputs(data, file);
	fputs("</day_of_month_receive_benefit>\n", file);
		
	fputs("</xagent>\n", file);
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
		
	fputs("</xagent>\n", file);
}

void write_Government_agent(FILE *file, xmachine_memory_Government * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Government</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<payment_account>", file);
	sprintf(data, "%f", current->payment_account);
	fputs(data, file);
	fputs("</payment_account>\n", file);
		fputs("<list_of_regions>", file);
	write_int_static_array(file, current->list_of_regions, 1);
	fputs("</list_of_regions>\n", file);
		fputs("<unemployment_benefit_pct>", file);
	sprintf(data, "%f", current->unemployment_benefit_pct);
	fputs(data, file);
	fputs("</unemployment_benefit_pct>\n", file);
		fputs("<tax_rate_corporate>", file);
	sprintf(data, "%f", current->tax_rate_corporate);
	fputs(data, file);
	fputs("</tax_rate_corporate>\n", file);
		fputs("<tax_rate_hh_labour>", file);
	sprintf(data, "%f", current->tax_rate_hh_labour);
	fputs(data, file);
	fputs("</tax_rate_hh_labour>\n", file);
		fputs("<tax_rate_hh_capital>", file);
	sprintf(data, "%f", current->tax_rate_hh_capital);
	fputs(data, file);
	fputs("</tax_rate_hh_capital>\n", file);
		fputs("<tax_rate_vat>", file);
	sprintf(data, "%f", current->tax_rate_vat);
	fputs(data, file);
	fputs("</tax_rate_vat>\n", file);
		fputs("<monthly_tax_revenues>", file);
	sprintf(data, "%f", current->monthly_tax_revenues);
	fputs(data, file);
	fputs("</monthly_tax_revenues>\n", file);
		fputs("<yearly_tax_revenues>", file);
	sprintf(data, "%f", current->yearly_tax_revenues);
	fputs(data, file);
	fputs("</yearly_tax_revenues>\n", file);
		fputs("<monthly_unemployment_benefit_payment>", file);
	sprintf(data, "%f", current->monthly_unemployment_benefit_payment);
	fputs(data, file);
	fputs("</monthly_unemployment_benefit_payment>\n", file);
		fputs("<yearly_unemployment_benefit_payment>", file);
	sprintf(data, "%f", current->yearly_unemployment_benefit_payment);
	fputs(data, file);
	fputs("</yearly_unemployment_benefit_payment>\n", file);
		fputs("<hh_transfer_payment>", file);
	sprintf(data, "%f", current->hh_transfer_payment);
	fputs(data, file);
	fputs("</hh_transfer_payment>\n", file);
		fputs("<firm_transfer_payment>", file);
	sprintf(data, "%f", current->firm_transfer_payment);
	fputs(data, file);
	fputs("</firm_transfer_payment>\n", file);
		fputs("<monthly_transfer_payment>", file);
	sprintf(data, "%f", current->monthly_transfer_payment);
	fputs(data, file);
	fputs("</monthly_transfer_payment>\n", file);
		fputs("<yearly_transfer_payment>", file);
	sprintf(data, "%f", current->yearly_transfer_payment);
	fputs(data, file);
	fputs("</yearly_transfer_payment>\n", file);
		fputs("<hh_subsidy_payment>", file);
	sprintf(data, "%f", current->hh_subsidy_payment);
	fputs(data, file);
	fputs("</hh_subsidy_payment>\n", file);
		fputs("<firm_subsidy_payment>", file);
	sprintf(data, "%f", current->firm_subsidy_payment);
	fputs(data, file);
	fputs("</firm_subsidy_payment>\n", file);
		fputs("<monthly_subsidy_payment>", file);
	sprintf(data, "%f", current->monthly_subsidy_payment);
	fputs(data, file);
	fputs("</monthly_subsidy_payment>\n", file);
		fputs("<yearly_subsidy_payment>", file);
	sprintf(data, "%f", current->yearly_subsidy_payment);
	fputs(data, file);
	fputs("</yearly_subsidy_payment>\n", file);
		fputs("<monthly_bond_coupon_payment>", file);
	sprintf(data, "%f", current->monthly_bond_coupon_payment);
	fputs(data, file);
	fputs("</monthly_bond_coupon_payment>\n", file);
		fputs("<yearly_bond_coupon_payment>", file);
	sprintf(data, "%f", current->yearly_bond_coupon_payment);
	fputs(data, file);
	fputs("</yearly_bond_coupon_payment>\n", file);
		fputs("<gov_interest_rate>", file);
	sprintf(data, "%f", current->gov_interest_rate);
	fputs(data, file);
	fputs("</gov_interest_rate>\n", file);
		fputs("<yearly_interest_payment>", file);
	sprintf(data, "%f", current->yearly_interest_payment);
	fputs(data, file);
	fputs("</yearly_interest_payment>\n", file);
		fputs("<yearly_gov_investment>", file);
	sprintf(data, "%f", current->yearly_gov_investment);
	fputs(data, file);
	fputs("</yearly_gov_investment>\n", file);
		fputs("<yearly_gov_consumption>", file);
	sprintf(data, "%f", current->yearly_gov_consumption);
	fputs(data, file);
	fputs("</yearly_gov_consumption>\n", file);
		fputs("<total_income>", file);
	sprintf(data, "%f", current->total_income);
	fputs(data, file);
	fputs("</total_income>\n", file);
		fputs("<total_expenditure>", file);
	sprintf(data, "%f", current->total_expenditure);
	fputs(data, file);
	fputs("</total_expenditure>\n", file);
		fputs("<total_debt>", file);
	sprintf(data, "%f", current->total_debt);
	fputs(data, file);
	fputs("</total_debt>\n", file);
		fputs("<budget_deficit>", file);
	sprintf(data, "%f", current->budget_deficit);
	fputs(data, file);
	fputs("</budget_deficit>\n", file);
		fputs("<total_money_financing>", file);
	sprintf(data, "%f", current->total_money_financing);
	fputs(data, file);
	fputs("</total_money_financing>\n", file);
		fputs("<total_bond_financing>", file);
	sprintf(data, "%f", current->total_bond_financing);
	fputs(data, file);
	fputs("</total_bond_financing>\n", file);
		fputs("<country_wide_mean_wage>", file);
	sprintf(data, "%f", current->country_wide_mean_wage);
	fputs(data, file);
	fputs("</country_wide_mean_wage>\n", file);
		fputs("<num_unemployed>", file);
	sprintf(data, "%i", current->num_unemployed);
	fputs(data, file);
	fputs("</num_unemployed>\n", file);
		fputs("<gdp>", file);
	sprintf(data, "%f", current->gdp);
	fputs(data, file);
	fputs("</gdp>\n", file);
		fputs("<gdp_growth>", file);
	sprintf(data, "%f", current->gdp_growth);
	fputs(data, file);
	fputs("</gdp_growth>\n", file);
		fputs("<gdp_forecast>", file);
	sprintf(data, "%f", current->gdp_forecast);
	fputs(data, file);
	fputs("</gdp_forecast>\n", file);
		fputs("<total_income_forecast>", file);
	sprintf(data, "%f", current->total_income_forecast);
	fputs(data, file);
	fputs("</total_income_forecast>\n", file);
		fputs("<total_expenditure_forecast>", file);
	sprintf(data, "%f", current->total_expenditure_forecast);
	fputs(data, file);
	fputs("</total_expenditure_forecast>\n", file);
		fputs("<budget_forecast>", file);
	sprintf(data, "%f", current->budget_forecast);
	fputs(data, file);
	fputs("</budget_forecast>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Central_Bank_agent(FILE *file, xmachine_memory_Central_Bank * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Central_Bank</name>\n", file);
		fputs("<bank_accounts>", file);
	write_double_static_array(file, current->bank_accounts, 30);
	fputs("</bank_accounts>\n", file);
		fputs("<gov_accounts>", file);
	write_double_static_array(file, current->gov_accounts, 30);
	fputs("</gov_accounts>\n", file);
		
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
	
	sprintf(data, "%s%i.xml", outputpath, iteration_number);
	file = fopen(data, "w");
	fputs("<states>\n<itno>", file);
	sprintf(data, "%i", iteration_number);
	fputs(data, file);
	fputs("</itno>\n", file);
	fputs("<environment>\n" , file);
	fputs("<gov_policy_unemployment_benefit_pct>", file);
	sprintf(data, "%f", gov_policy_unemployment_benefit_pct);
	fputs(data, file);
	fputs("</gov_policy_unemployment_benefit_pct>\n", file);
	fputs("<gov_policy_money_financing_fraction>", file);
	sprintf(data, "%f", gov_policy_money_financing_fraction);
	fputs(data, file);
	fputs("</gov_policy_money_financing_fraction>\n", file);
	fputs("<gov_policy_gdp_fraction_consumption>", file);
	sprintf(data, "%f", gov_policy_gdp_fraction_consumption);
	fputs(data, file);
	fputs("</gov_policy_gdp_fraction_consumption>\n", file);
	fputs("<gov_policy_gdp_fraction_investment>", file);
	sprintf(data, "%f", gov_policy_gdp_fraction_investment);
	fputs(data, file);
	fputs("</gov_policy_gdp_fraction_investment>\n", file);
	fputs("</environment>\n" , file);

//	current_xmachine = *p_xmachine;
// todo loop through all agent types

current_xmachine_Household_holder = Household_end_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		write_Household_agent(file, current_xmachine_Household_holder->agent);
		
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}

current_xmachine_Firm_holder = Firm_end_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		write_Firm_agent(file, current_xmachine_Firm_holder->agent);
		
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}

current_xmachine_Government_holder = Government_end_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		write_Government_agent(file, current_xmachine_Government_holder->agent);
		
		current_xmachine_Government_holder = current_xmachine_Government_holder->next;
	}

current_xmachine_Central_Bank_holder = Central_Bank_end_Central_Bank_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		write_Central_Bank_agent(file, current_xmachine_Central_Bank_holder->agent);
		
		current_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
	}
	
fputs("</states>\n" , file);
	
	/* Close the file */
	fclose(file);
	
	next_avaliable_id++;
}
