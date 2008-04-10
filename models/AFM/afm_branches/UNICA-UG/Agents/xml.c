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


/** \fn void read_Order(char * buffer, int * j, Order * temp_datatype)
 * \brief Reads Order datatype.
 */
void read_Order(char * buffer, int * j, Order * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).issuer = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).issuer = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quantity = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atoi(arraydata);
	(*j)++;
	(*temp_datatype).price = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).price = atof(arraydata);
	(*j)++;
	(*temp_datatype).assetId = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).assetId = atoi(arraydata);
	(*j)++;
}

void read_Order_dynamic_array(char * buffer, int * j, Order_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Order(temp_datatype_array, 0, 0, 0.0, 0);
			read_Order(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Order_static_array(char * buffer, int * j, Order * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Order(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_Belief(char * buffer, int * j, Belief * temp_datatype)
 * \brief Reads Belief datatype.
 */
void read_Belief(char * buffer, int * j, Belief * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).expectedPriceReturns = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).expectedPriceReturns = atof(arraydata);
	(*j)++;
	(*temp_datatype).expectedTotalReturns = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).expectedTotalReturns = atof(arraydata);
	(*j)++;
	(*temp_datatype).expectedCashFlowYield = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).expectedCashFlowYield = atof(arraydata);
	(*j)++;
	(*temp_datatype).volatility = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).volatility = atof(arraydata);
	(*j)++;
}

void read_Belief_dynamic_array(char * buffer, int * j, Belief_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Belief(temp_datatype_array, 0.0, 0.0, 0.0, 0.0);
			read_Belief(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Belief_static_array(char * buffer, int * j, Belief * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Belief(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_Asset(char * buffer, int * j, Asset * temp_datatype)
 * \brief Reads Asset datatype.
 */
void read_Asset(char * buffer, int * j, Asset * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).issuer = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).issuer = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quantity = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atoi(arraydata);
	(*j)++;
	(*temp_datatype).lastPrice = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).lastPrice = atof(arraydata);
	(*j)++;
}

void read_Asset_dynamic_array(char * buffer, int * j, Asset_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Asset(temp_datatype_array, 0, 0, 0.0);
			read_Asset(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Asset_static_array(char * buffer, int * j, Asset * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Asset(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_Portfolio(char * buffer, int * j, Portfolio * temp_datatype)
 * \brief Reads Portfolio datatype.
 */
void read_Portfolio(char * buffer, int * j, Portfolio * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).bankAccount = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).bankAccount = atof(arraydata);
	(*j)++;
}

void read_Portfolio_dynamic_array(char * buffer, int * j, Portfolio_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Portfolio(temp_datatype_array, 0.0);
			read_Portfolio(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Portfolio_static_array(char * buffer, int * j, Portfolio * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Portfolio(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
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
void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], 
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
	int j=0;

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
	int in_Eurostat_agent;
	int in_Household_agent;
	int in_ClearingHouse_agent;
	int in_Firm_agent;

	int in_id;
	int in_assets;
	int in_range;
	int in_posx;
	int in_posy;
	int in_wealth;
	int in_belief;
	int in_portfolio;
	int in_pendingOrders;
	int in_assetsowned;
	int in_forwardWindow;
	int in_backwordWindow;
	int in_binsNumber;
	int in_randomReturnWeigth;
	int in_fundametalReturnWeigth;
	int in_chartistReturnWeigth;
	int in_holdingPeriodToForwardW;
	int in_current_shares_outstanding;
	int in_total_dividend_payment;
	int in_bank_account;
	int in_equity;


	/* Variables for initial state data */
//	int id;
//	Asset_array * assets;
//	double range;
//	double posx;
//	double posy;
//	double wealth;
//	Belief * belief;
//	Portfolio * portfolio;
//	Order_array * pendingOrders;
//	Asset_array * assetsowned;
//	int forwardWindow;
//	int backwordWindow;
//	int binsNumber;
//	double randomReturnWeigth;
//	double fundametalReturnWeigth;
//	double chartistReturnWeigth;
//	int holdingPeriodToForwardW;
//	int current_shares_outstanding;
//	double total_dividend_payment;
//	double bank_account;
//	double equity;


	xmachine_memory_Eurostat * current_Eurostat_agent;
	xmachine_memory_Household * current_Household_agent;
	xmachine_memory_ClearingHouse * current_ClearingHouse_agent;
	xmachine_memory_Firm * current_Firm_agent;


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
	in_Eurostat_agent = 0;
	in_Household_agent = 0;
	in_ClearingHouse_agent = 0;
	in_Firm_agent = 0;
	in_id = 0;
	in_assets = 0;
	in_range = 0;
	in_posx = 0;
	in_posy = 0;
	in_wealth = 0;
	in_belief = 0;
	in_portfolio = 0;
	in_pendingOrders = 0;
	in_assetsowned = 0;
	in_forwardWindow = 0;
	in_backwordWindow = 0;
	in_binsNumber = 0;
	in_randomReturnWeigth = 0;
	in_fundametalReturnWeigth = 0;
	in_chartistReturnWeigth = 0;
	in_holdingPeriodToForwardW = 0;
	in_current_shares_outstanding = 0;
	in_total_dividend_payment = 0;
	in_bank_account = 0;
	in_equity = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	assets = init_Asset_array();
//	range = 0.0;
//	posx = 0.0;
//	posy = 0.0;
//	wealth = 0.0;
//	belief = init_Belief();
//	portfolio = init_Portfolio();
//	pendingOrders = init_Order_array();
//	assetsowned = init_Asset_array();
//	forwardWindow = 0;
//	backwordWindow = 0;
//	binsNumber = 0;
//	randomReturnWeigth = 0.0;
//	fundametalReturnWeigth = 0.0;
//	chartistReturnWeigth = 0.0;
//	holdingPeriodToForwardW = 0;
//	current_shares_outstanding = 0;
//	total_dividend_payment = 0.0;
//	bank_account = 0.0;
//	equity = 0.0;







	if(partition_method==geometric) printf("xml: Geometric partitioning\n");
	else if(partition_method==other) printf("xml: Round-robin partitioning\n");
	else printf("xml: Error - invalid partitioning method\n");


	/* Set p_xmachine to the agent list passed in then new agents are added to this list 
	 * Will be set to agent list for specific node is space partitions are already known (flag=1)
	 */ 
	p_xmachine = agent_list;
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
					if(strcmp(agentname, "Eurostat") == 0)
					{
						current_Eurostat_agent = init_Eurostat_agent();
						in_Eurostat_agent = 1;
					}
					else if(strcmp(agentname, "Household") == 0)
					{
						current_Household_agent = init_Household_agent();
						in_Household_agent = 1;
					}
					else if(strcmp(agentname, "ClearingHouse") == 0)
					{
						current_ClearingHouse_agent = init_ClearingHouse_agent();
						in_ClearingHouse_agent = 1;
					}
					else if(strcmp(agentname, "Firm") == 0)
					{
						current_Firm_agent = init_Firm_agent();
						in_Firm_agent = 1;
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
				in_Eurostat_agent = 0;
in_Household_agent = 0;
in_ClearingHouse_agent = 0;
in_Firm_agent = 0;

				
				if(strcmp(agentname, "Eurostat") == 0)
				{
					posx = current_Eurostat_agent->posx;
					posy = current_Eurostat_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Eurostat_agent(id, assets, range, posx, posy);
						add_Eurostat_agent_internal(current_Eurostat_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_Eurostat_agent(id, assets, range, posx, posy);
								add_Eurostat_agent_internal(current_Eurostat_agent);
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

								p_xmachine = &(current_node->agents);
								//add_Eurostat_agent(id, assets, range, posx, posy);
								add_Eurostat_agent_internal(current_Eurostat_agent);

								current_Eurostat_agent->posx = xcentre;
								current_Eurostat_agent->posy = ycentre;
								current_Eurostat_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Household") == 0)
				{
					posx = current_Household_agent->posx;
					posy = current_Household_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, forwardWindow, backwordWindow, binsNumber, randomReturnWeigth, fundametalReturnWeigth, chartistReturnWeigth, holdingPeriodToForwardW, range, posx, posy);
						add_Household_agent_internal(current_Household_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, forwardWindow, backwordWindow, binsNumber, randomReturnWeigth, fundametalReturnWeigth, chartistReturnWeigth, holdingPeriodToForwardW, range, posx, posy);
								add_Household_agent_internal(current_Household_agent);
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

								p_xmachine = &(current_node->agents);
								//add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, forwardWindow, backwordWindow, binsNumber, randomReturnWeigth, fundametalReturnWeigth, chartistReturnWeigth, holdingPeriodToForwardW, range, posx, posy);
								add_Household_agent_internal(current_Household_agent);

								current_Household_agent->posx = xcentre;
								current_Household_agent->posy = ycentre;
								current_Household_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "ClearingHouse") == 0)
				{
					posx = current_ClearingHouse_agent->posx;
					posy = current_ClearingHouse_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_ClearingHouse_agent(id, assets, range, posx, posy);
						add_ClearingHouse_agent_internal(current_ClearingHouse_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_ClearingHouse_agent(id, assets, range, posx, posy);
								add_ClearingHouse_agent_internal(current_ClearingHouse_agent);
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

								p_xmachine = &(current_node->agents);
								//add_ClearingHouse_agent(id, assets, range, posx, posy);
								add_ClearingHouse_agent_internal(current_ClearingHouse_agent);

								current_ClearingHouse_agent->posx = xcentre;
								current_ClearingHouse_agent->posy = ycentre;
								current_ClearingHouse_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Firm") == 0)
				{
					posx = current_Firm_agent->posx;
					posy = current_Firm_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Firm_agent(id, current_shares_outstanding, total_dividend_payment, bank_account, equity, range, posx, posy);
						add_Firm_agent_internal(current_Firm_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_Firm_agent(id, current_shares_outstanding, total_dividend_payment, bank_account, equity, range, posx, posy);
								add_Firm_agent_internal(current_Firm_agent);
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

								p_xmachine = &(current_node->agents);
								//add_Firm_agent(id, current_shares_outstanding, total_dividend_payment, bank_account, equity, range, posx, posy);
								add_Firm_agent_internal(current_Firm_agent);

								current_Firm_agent->posx = xcentre;
								current_Firm_agent->posy = ycentre;
								current_Firm_agent->range = rrange;

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
////				range = 0.0;
//				posx = 0.0;
//				posy = 0.0;
//				wealth = 0.0;
//////////				forwardWindow = 0;
//				backwordWindow = 0;
//				binsNumber = 0;
//				randomReturnWeigth = 0.0;
//				fundametalReturnWeigth = 0.0;
//				chartistReturnWeigth = 0.0;
//				holdingPeriodToForwardW = 0;
//				current_shares_outstanding = 0;
//				total_dividend_payment = 0.0;
//				bank_account = 0.0;
//				equity = 0.0;

	}
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "assets") == 0) in_assets = 1;
			if(strcmp(buffer, "/assets") == 0) in_assets = 0;
			if(strcmp(buffer, "range") == 0) in_range = 1;
			if(strcmp(buffer, "/range") == 0) in_range = 0;
			if(strcmp(buffer, "posx") == 0) in_posx = 1;
			if(strcmp(buffer, "/posx") == 0) in_posx = 0;
			if(strcmp(buffer, "posy") == 0) in_posy = 1;
			if(strcmp(buffer, "/posy") == 0) in_posy = 0;
			if(strcmp(buffer, "wealth") == 0) in_wealth = 1;
			if(strcmp(buffer, "/wealth") == 0) in_wealth = 0;
			if(strcmp(buffer, "belief") == 0) in_belief = 1;
			if(strcmp(buffer, "/belief") == 0) in_belief = 0;
			if(strcmp(buffer, "portfolio") == 0) in_portfolio = 1;
			if(strcmp(buffer, "/portfolio") == 0) in_portfolio = 0;
			if(strcmp(buffer, "pendingOrders") == 0) in_pendingOrders = 1;
			if(strcmp(buffer, "/pendingOrders") == 0) in_pendingOrders = 0;
			if(strcmp(buffer, "assetsowned") == 0) in_assetsowned = 1;
			if(strcmp(buffer, "/assetsowned") == 0) in_assetsowned = 0;
			if(strcmp(buffer, "forwardWindow") == 0) in_forwardWindow = 1;
			if(strcmp(buffer, "/forwardWindow") == 0) in_forwardWindow = 0;
			if(strcmp(buffer, "backwordWindow") == 0) in_backwordWindow = 1;
			if(strcmp(buffer, "/backwordWindow") == 0) in_backwordWindow = 0;
			if(strcmp(buffer, "binsNumber") == 0) in_binsNumber = 1;
			if(strcmp(buffer, "/binsNumber") == 0) in_binsNumber = 0;
			if(strcmp(buffer, "randomReturnWeigth") == 0) in_randomReturnWeigth = 1;
			if(strcmp(buffer, "/randomReturnWeigth") == 0) in_randomReturnWeigth = 0;
			if(strcmp(buffer, "fundametalReturnWeigth") == 0) in_fundametalReturnWeigth = 1;
			if(strcmp(buffer, "/fundametalReturnWeigth") == 0) in_fundametalReturnWeigth = 0;
			if(strcmp(buffer, "chartistReturnWeigth") == 0) in_chartistReturnWeigth = 1;
			if(strcmp(buffer, "/chartistReturnWeigth") == 0) in_chartistReturnWeigth = 0;
			if(strcmp(buffer, "holdingPeriodToForwardW") == 0) in_holdingPeriodToForwardW = 1;
			if(strcmp(buffer, "/holdingPeriodToForwardW") == 0) in_holdingPeriodToForwardW = 0;
			if(strcmp(buffer, "current_shares_outstanding") == 0) in_current_shares_outstanding = 1;
			if(strcmp(buffer, "/current_shares_outstanding") == 0) in_current_shares_outstanding = 0;
			if(strcmp(buffer, "total_dividend_payment") == 0) in_total_dividend_payment = 1;
			if(strcmp(buffer, "/total_dividend_payment") == 0) in_total_dividend_payment = 0;
			if(strcmp(buffer, "bank_account") == 0) in_bank_account = 1;
			if(strcmp(buffer, "/bank_account") == 0) in_bank_account = 0;
			if(strcmp(buffer, "equity") == 0) in_equity = 1;
			if(strcmp(buffer, "/equity") == 0) in_equity = 0;


			
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
			
			if(in_itno) *itno = atoi(buffer);
			if(in_name) strcpy(agentname, buffer);
			if(in_environment)
			{
			}
			else if(in_Eurostat_agent == 1)
			{
				if(in_id) current_Eurostat_agent->id = atoi(buffer);
				if(in_assets)
				{
					j = 0;
					read_Asset_dynamic_array(buffer, &j, &current_Eurostat_agent->assets);
				}
				if(in_range) current_Eurostat_agent->range = atof(buffer);
				if(in_posx) current_Eurostat_agent->posx = atof(buffer);
				if(in_posy) current_Eurostat_agent->posy = atof(buffer);
			}else if(in_Household_agent == 1)
			{
				if(in_id) current_Household_agent->id = atoi(buffer);
				if(in_wealth) current_Household_agent->wealth = atof(buffer);
				if(in_belief)
				{
					j = 0;
					read_Belief(buffer, &j, &current_Household_agent->belief);
				}
				if(in_portfolio)
				{
					j = 0;
					read_Portfolio(buffer, &j, &current_Household_agent->portfolio);
				}
				if(in_pendingOrders)
				{
					j = 0;
					read_Order_dynamic_array(buffer, &j, &current_Household_agent->pendingOrders);
				}
				if(in_assetsowned)
				{
					j = 0;
					read_Asset_dynamic_array(buffer, &j, &current_Household_agent->assetsowned);
				}
				if(in_forwardWindow) current_Household_agent->forwardWindow = atoi(buffer);
				if(in_backwordWindow) current_Household_agent->backwordWindow = atoi(buffer);
				if(in_binsNumber) current_Household_agent->binsNumber = atoi(buffer);
				if(in_randomReturnWeigth) current_Household_agent->randomReturnWeigth = atof(buffer);
				if(in_fundametalReturnWeigth) current_Household_agent->fundametalReturnWeigth = atof(buffer);
				if(in_chartistReturnWeigth) current_Household_agent->chartistReturnWeigth = atof(buffer);
				if(in_holdingPeriodToForwardW) current_Household_agent->holdingPeriodToForwardW = atoi(buffer);
				if(in_range) current_Household_agent->range = atof(buffer);
				if(in_posx) current_Household_agent->posx = atof(buffer);
				if(in_posy) current_Household_agent->posy = atof(buffer);
			}else if(in_ClearingHouse_agent == 1)
			{
				if(in_id) current_ClearingHouse_agent->id = atoi(buffer);
				if(in_assets)
				{
					j = 0;
					read_Asset_dynamic_array(buffer, &j, &current_ClearingHouse_agent->assets);
				}
				if(in_range) current_ClearingHouse_agent->range = atof(buffer);
				if(in_posx) current_ClearingHouse_agent->posx = atof(buffer);
				if(in_posy) current_ClearingHouse_agent->posy = atof(buffer);
			}else if(in_Firm_agent == 1)
			{
				if(in_id) current_Firm_agent->id = atoi(buffer);
				if(in_current_shares_outstanding) current_Firm_agent->current_shares_outstanding = atoi(buffer);
				if(in_total_dividend_payment) current_Firm_agent->total_dividend_payment = atof(buffer);
				if(in_bank_account) current_Firm_agent->bank_account = atof(buffer);
				if(in_equity) current_Firm_agent->equity = atof(buffer);
				if(in_range) current_Firm_agent->range = atof(buffer);
				if(in_posx) current_Firm_agent->posx = atof(buffer);
				if(in_posy) current_Firm_agent->posy = atof(buffer);
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
////	free_Asset_array(assets);
//////////	free_Belief_datatype(belief);
//	free_Portfolio_datatype(portfolio);
//	free_Order_array(pendingOrders);
//	free_Asset_array(assetsowned);
//////////////////////
}

/** \fn void saveiterationdata_binary(int iteration_number)
 * \brief Save X-machine memory to a binary file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata_binary(int iteration_number)
{
	/* Pointer to file */
	FILE *file;
	char data[1000];
	int i;
	int agentcount = 0;
	xmachine_memory_Eurostat * current_Eurostat;
	xmachine_memory_Household * current_Household;
	xmachine_memory_ClearingHouse * current_ClearingHouse;
	xmachine_memory_Firm * current_Firm;

	sprintf(data, "%s%i.binary", outputpath, iteration_number);
	file = fopen(data, "wb");
	/* iteration number*/
	fwrite(&iteration_number ,sizeof(int), 1, file);
	/* number of xagent memories written (update at end)*/
	fwrite(&i ,sizeof(int), 1, file);
	
	current_node = *p_node_info;
	while(current_node)
	{
	p_xmachine = &current_node->agents;
	current_xmachine = *p_xmachine;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_Eurostat != NULL)
		{
			current_Eurostat = current_xmachine->xmachine_Eurostat;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Household != NULL)
		{
			current_Household = current_xmachine->xmachine_Household;
			agentcount++;
		}
		else if(current_xmachine->xmachine_ClearingHouse != NULL)
		{
			current_ClearingHouse = current_xmachine->xmachine_ClearingHouse;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Firm != NULL)
		{
			current_Firm = current_xmachine->xmachine_Firm;
			agentcount++;
		}
		
		current_xmachine = current_xmachine->next;
	}
		current_node = current_node->next;
	}
	
	/* update agent count\n", file);*/
	fseek(file,sizeof(int)*1,SEEK_SET);
	fwrite(&agentcount,sizeof(int),1,file);
	
	/* Close the file */
	fclose(file);
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

/** \fn void write_Order(FILE *file, Order * temp_datatype)
 * \brief Writes Order datatype.
 */
void write_Order(FILE *file, Order * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).issuer);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).assetId);
	fputs(data, file);
	fputs("}", file);
}

void write_Order_static_array(FILE *file, Order * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Order(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Order_dynamic_array(FILE *file, Order_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_Order(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_Belief(FILE *file, Belief * temp_datatype)
 * \brief Writes Belief datatype.
 */
void write_Belief(FILE *file, Belief * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).expectedPriceReturns);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).expectedTotalReturns);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).expectedCashFlowYield);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).volatility);
	fputs(data, file);
	fputs("}", file);
}

void write_Belief_static_array(FILE *file, Belief * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Belief(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Belief_dynamic_array(FILE *file, Belief_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_Belief(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_Asset(FILE *file, Asset * temp_datatype)
 * \brief Writes Asset datatype.
 */
void write_Asset(FILE *file, Asset * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).issuer);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).lastPrice);
	fputs(data, file);
	fputs("}", file);
}

void write_Asset_static_array(FILE *file, Asset * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Asset(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Asset_dynamic_array(FILE *file, Asset_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_Asset(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_Portfolio(FILE *file, Portfolio * temp_datatype)
 * \brief Writes Portfolio datatype.
 */
void write_Portfolio(FILE *file, Portfolio * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).bankAccount);
	fputs(data, file);
	fputs("}", file);
}

void write_Portfolio_static_array(FILE *file, Portfolio * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Portfolio(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Portfolio_dynamic_array(FILE *file, Portfolio_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_Portfolio(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
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
	xmachine_memory_Eurostat * current_Eurostat;
	xmachine_memory_Household * current_Household;
	xmachine_memory_ClearingHouse * current_ClearingHouse;
	xmachine_memory_Firm * current_Firm;
	
	sprintf(data, "%s%i.xml", outputpath, iteration_number);
	file = fopen(data, "w");
	fputs("<states>\n<itno>", file);
	sprintf(data, "%i", iteration_number);
	fputs(data, file);
	fputs("</itno>\n", file);
	fputs("<environment>\n" , file);
	fputs("</environment>\n" , file);


	current_node = *p_node_info;
	while(current_node)
	{
		p_xmachine = &current_node->agents;
		current_xmachine = *p_xmachine;
	while(current_xmachine)
	{
		fputs("<xagent>\n" , file);
		if(current_xmachine->xmachine_Eurostat != NULL)
		{
			current_Eurostat = current_xmachine->xmachine_Eurostat;
			fputs("<name>Eurostat</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Eurostat->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<assets>", file);
			write_Asset_dynamic_array(file, &current_Eurostat->assets);
			fputs("</assets>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Eurostat->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Eurostat->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Eurostat->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Household != NULL)
		{
			current_Household = current_xmachine->xmachine_Household;
			fputs("<name>Household</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Household->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<wealth>", file);
			sprintf(data, "%f", current_Household->wealth);
			fputs(data, file);
			fputs("</wealth>\n", file);
			fputs("<belief>", file);
			write_Belief(file, &current_Household->belief);
			fputs("</belief>\n", file);
			fputs("<portfolio>", file);
			write_Portfolio(file, &current_Household->portfolio);
			fputs("</portfolio>\n", file);
			fputs("<pendingOrders>", file);
			write_Order_dynamic_array(file, &current_Household->pendingOrders);
			fputs("</pendingOrders>\n", file);
			fputs("<assetsowned>", file);
			write_Asset_dynamic_array(file, &current_Household->assetsowned);
			fputs("</assetsowned>\n", file);
			fputs("<forwardWindow>", file);
			sprintf(data, "%i", current_Household->forwardWindow);
			fputs(data, file);
			fputs("</forwardWindow>\n", file);
			fputs("<backwordWindow>", file);
			sprintf(data, "%i", current_Household->backwordWindow);
			fputs(data, file);
			fputs("</backwordWindow>\n", file);
			fputs("<binsNumber>", file);
			sprintf(data, "%i", current_Household->binsNumber);
			fputs(data, file);
			fputs("</binsNumber>\n", file);
			fputs("<randomReturnWeigth>", file);
			sprintf(data, "%f", current_Household->randomReturnWeigth);
			fputs(data, file);
			fputs("</randomReturnWeigth>\n", file);
			fputs("<fundametalReturnWeigth>", file);
			sprintf(data, "%f", current_Household->fundametalReturnWeigth);
			fputs(data, file);
			fputs("</fundametalReturnWeigth>\n", file);
			fputs("<chartistReturnWeigth>", file);
			sprintf(data, "%f", current_Household->chartistReturnWeigth);
			fputs(data, file);
			fputs("</chartistReturnWeigth>\n", file);
			fputs("<holdingPeriodToForwardW>", file);
			sprintf(data, "%i", current_Household->holdingPeriodToForwardW);
			fputs(data, file);
			fputs("</holdingPeriodToForwardW>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Household->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Household->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Household->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_ClearingHouse != NULL)
		{
			current_ClearingHouse = current_xmachine->xmachine_ClearingHouse;
			fputs("<name>ClearingHouse</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_ClearingHouse->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<assets>", file);
			write_Asset_dynamic_array(file, &current_ClearingHouse->assets);
			fputs("</assets>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_ClearingHouse->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_ClearingHouse->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_ClearingHouse->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Firm != NULL)
		{
			current_Firm = current_xmachine->xmachine_Firm;
			fputs("<name>Firm</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Firm->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<current_shares_outstanding>", file);
			sprintf(data, "%i", current_Firm->current_shares_outstanding);
			fputs(data, file);
			fputs("</current_shares_outstanding>\n", file);
			fputs("<total_dividend_payment>", file);
			sprintf(data, "%f", current_Firm->total_dividend_payment);
			fputs(data, file);
			fputs("</total_dividend_payment>\n", file);
			fputs("<bank_account>", file);
			sprintf(data, "%f", current_Firm->bank_account);
			fputs(data, file);
			fputs("</bank_account>\n", file);
			fputs("<equity>", file);
			sprintf(data, "%f", current_Firm->equity);
			fputs(data, file);
			fputs("</equity>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Firm->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Firm->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Firm->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
	
		fputs("</xagent>\n", file);
		
		current_xmachine = current_xmachine->next;
	}
			current_node = current_node->next;
	}
fputs("</states>\n" , file);
	
	/* Close the file */
	fclose(file);
	
	next_avaliable_id++;
}
