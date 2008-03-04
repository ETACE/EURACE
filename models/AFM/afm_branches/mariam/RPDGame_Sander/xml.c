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


/** \fn void read_strategy_state(char * buffer, int * j, strategy_state * temp_datatype)
 * \brief Reads strategy_state datatype.
 */
void read_strategy_state(char * buffer, int * j, strategy_state * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		read_int_static_array(buffer, j, (*temp_datatype).starting_state, 4);
	}
	
	(*j)++;
	(*temp_datatype).state_name = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).state_name = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		read_int_static_array(buffer, j, (*temp_datatype).state_ifcooperate, 4);
	}
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		read_int_static_array(buffer, j, (*temp_datatype).state_ifdefect, 4);
	}
	
	(*j)++;
}

void read_strategy_state_dynamic_array(char * buffer, int * j, strategy_state_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_strategy_state(temp_datatype_array, NULL, 0, NULL, NULL);
			read_strategy_state(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_strategy_state_static_array(char * buffer, int * j, strategy_state * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_strategy_state(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_payoff_elements(char * buffer, int * j, payoff_elements * temp_datatype)
 * \brief Reads payoff_elements datatype.
 */
void read_payoff_elements(char * buffer, int * j, payoff_elements * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		read_int_static_array(buffer, j, (*temp_datatype).payoffs, 2);
	}
	
	(*j)++;
}

void read_payoff_elements_dynamic_array(char * buffer, int * j, payoff_elements_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_payoff_elements(temp_datatype_array, NULL);
			read_payoff_elements(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_payoff_elements_static_array(char * buffer, int * j, payoff_elements * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_payoff_elements(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_strategy_data(char * buffer, int * j, strategy_data * temp_datatype)
 * \brief Reads strategy_data datatype.
 */
void read_strategy_data(char * buffer, int * j, strategy_data * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).strategy_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).strategy_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).strategy_perf = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).strategy_perf = atof(arraydata);
	(*j)++;
}

void read_strategy_data_dynamic_array(char * buffer, int * j, strategy_data_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_strategy_data(temp_datatype_array, 0, 0.0);
			read_strategy_data(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_strategy_data_static_array(char * buffer, int * j, strategy_data * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_strategy_data(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_complete_strategy(char * buffer, int * j, complete_strategy * temp_datatype)
 * \brief Reads complete_strategy datatype.
 */
void read_complete_strategy(char * buffer, int * j, complete_strategy * temp_datatype)
{
	
	(*j)++;
	
	while(buffer[*j] != '{') (*j)++;

	read_strategy_state_dynamic_array(buffer, j, &(*temp_datatype).strategy_path);
	
	(*j)++;
}

void read_complete_strategy_dynamic_array(char * buffer, int * j, complete_strategy_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_complete_strategy(temp_datatype_array, NULL);
			read_complete_strategy(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_complete_strategy_static_array(char * buffer, int * j, complete_strategy * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_complete_strategy(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_columns(char * buffer, int * j, columns * temp_datatype)
 * \brief Reads columns datatype.
 */
void read_columns(char * buffer, int * j, columns * temp_datatype)
{
	
	(*j)++;
	
	while(buffer[*j] != '{') (*j)++;

	read_payoff_elements_dynamic_array(buffer, j, &(*temp_datatype).opponents);
	
	(*j)++;
}

void read_columns_dynamic_array(char * buffer, int * j, columns_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_columns(temp_datatype_array, NULL);
			read_columns(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_columns_static_array(char * buffer, int * j, columns * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_columns(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_player_list_element(char * buffer, int * j, player_list_element * temp_datatype)
 * \brief Reads player_list_element datatype.
 */
void read_player_list_element(char * buffer, int * j, player_list_element * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).player_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).player_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).strategy_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).strategy_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).previous_move = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).previous_move = atoi(arraydata);
	(*j)++;
	(*temp_datatype).present_state = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).present_state = atoi(arraydata);
	(*j)++;
}

void read_player_list_element_dynamic_array(char * buffer, int * j, player_list_element_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_player_list_element(temp_datatype_array, 0, 0, 0, 0);
			read_player_list_element(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_player_list_element_static_array(char * buffer, int * j, player_list_element * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_player_list_element(buffer, j, &temp_datatype_array[arraycount]);
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
	int in_GamePlayer_agent;
	int in_GameSolver_agent;

	int in_id;
	int in_strategy_used;
	int in_previous_performance;
	int in_present_state;
	int in_iradius;
	int in_posx;
	int in_posy;
	int in_strategy_list;
	int in_new_children;
	int in_nragents;
	int in_automata_id;
	int in_players;
	int in_player_one_state;
	int in_player_two_state;
	int in_player_one_move;
	int in_player_two_move;
	int in_strategy_performance;
	int in_offspring;
	int in_rows;
	int in_player_list;


	/* Variables for initial state data */
//	int id;
//	int strategy_used;
//	int previous_performance;
//	int present_state;
//	double iradius;
//	double posx;
//	double posy;
//	complete_strategy ** strategy_list;
//	complete_strategy ** new_children;
//	int nragents;
//	int_array * automata_id;
//	int_array * players;
//	int player_one_state[4];
//	int player_two_state[4];
//	int player_one_move;
//	int player_two_move;
//	strategy_data ** strategy_performance;
//	complete_strategy ** offspring;
//	columns_array * rows;
//	player_list_element_array * player_list;


	xmachine_memory_GamePlayer * current_GamePlayer_agent;
	xmachine_memory_GameSolver * current_GameSolver_agent;


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
	in_GamePlayer_agent = 0;
	in_GameSolver_agent = 0;
	in_id = 0;
	in_strategy_used = 0;
	in_previous_performance = 0;
	in_present_state = 0;
	in_iradius = 0;
	in_posx = 0;
	in_posy = 0;
	in_strategy_list = 0;
	in_new_children = 0;
	in_nragents = 0;
	in_automata_id = 0;
	in_players = 0;
	in_player_one_state = 0;
	in_player_two_state = 0;
	in_player_one_move = 0;
	in_player_two_move = 0;
	in_strategy_performance = 0;
	in_offspring = 0;
	in_rows = 0;
	in_player_list = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	strategy_used = 0;
//	previous_performance = 0;
//	present_state = 0;
//	iradius = 0.0;
//	posx = 0.0;
//	posy = 0.0;
//	strategy_list = init_complete_strategy_static_array(30);
//	new_children = init_complete_strategy_static_array(10);
//	nragents = 0;
//	automata_id = init_int_array();
//	players = init_int_array();
//////	player_one_move = 0;
//	player_two_move = 0;
//	strategy_performance = init_strategy_data_static_array(30);
//	offspring = init_complete_strategy_static_array(2);
//	rows = init_columns_array();
//	player_list = init_player_list_element_array();







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
					if(strcmp(agentname, "GamePlayer") == 0)
					{
						current_GamePlayer_agent = init_GamePlayer_agent();
						in_GamePlayer_agent = 1;
					}
					else if(strcmp(agentname, "GameSolver") == 0)
					{
						current_GameSolver_agent = init_GameSolver_agent();
						in_GameSolver_agent = 1;
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
				in_GamePlayer_agent = 0;
in_GameSolver_agent = 0;

				
				if(strcmp(agentname, "GamePlayer") == 0)
				{
					posx = current_GamePlayer_agent->posx;
					posy = current_GamePlayer_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_GamePlayer_agent(id, strategy_used, previous_performance, present_state, iradius, posx, posy);
						add_GamePlayer_agent_internal(current_GamePlayer_agent);
						
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
								//add_GamePlayer_agent(id, strategy_used, previous_performance, present_state, iradius, posx, posy);
								add_GamePlayer_agent_internal(current_GamePlayer_agent);
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
								//add_GamePlayer_agent(id, strategy_used, previous_performance, present_state, iradius, posx, posy);
								add_GamePlayer_agent_internal(current_GamePlayer_agent);

								current_GamePlayer_agent->posx = xcentre;
								current_GamePlayer_agent->posy = ycentre;
								current_GamePlayer_agent-> = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "GameSolver") == 0)
				{
					posx = current_GameSolver_agent->posx;
					posy = current_GameSolver_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_GameSolver_agent(strategy_list, new_children, nragents, automata_id, players, player_one_state, player_two_state, player_one_move, player_two_move, strategy_performance, offspring, rows, player_list, iradius, posx, posy);
						add_GameSolver_agent_internal(current_GameSolver_agent);
						
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
								//add_GameSolver_agent(strategy_list, new_children, nragents, automata_id, players, player_one_state, player_two_state, player_one_move, player_two_move, strategy_performance, offspring, rows, player_list, iradius, posx, posy);
								add_GameSolver_agent_internal(current_GameSolver_agent);
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
								//add_GameSolver_agent(strategy_list, new_children, nragents, automata_id, players, player_one_state, player_two_state, player_one_move, player_two_move, strategy_performance, offspring, rows, player_list, iradius, posx, posy);
								add_GameSolver_agent_internal(current_GameSolver_agent);

								current_GameSolver_agent->posx = xcentre;
								current_GameSolver_agent->posy = ycentre;
								current_GameSolver_agent-> = rrange;

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
//				strategy_used = 0;
//				previous_performance = 0;
//				present_state = 0;
//				iradius = 0.0;
//				posx = 0.0;
//				posy = 0.0;
//////				nragents = 0;
//////////				player_one_move = 0;
//				player_two_move = 0;
////////
	}
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "strategy_used") == 0) in_strategy_used = 1;
			if(strcmp(buffer, "/strategy_used") == 0) in_strategy_used = 0;
			if(strcmp(buffer, "previous_performance") == 0) in_previous_performance = 1;
			if(strcmp(buffer, "/previous_performance") == 0) in_previous_performance = 0;
			if(strcmp(buffer, "present_state") == 0) in_present_state = 1;
			if(strcmp(buffer, "/present_state") == 0) in_present_state = 0;
			if(strcmp(buffer, "iradius") == 0) in_iradius = 1;
			if(strcmp(buffer, "/iradius") == 0) in_iradius = 0;
			if(strcmp(buffer, "posx") == 0) in_posx = 1;
			if(strcmp(buffer, "/posx") == 0) in_posx = 0;
			if(strcmp(buffer, "posy") == 0) in_posy = 1;
			if(strcmp(buffer, "/posy") == 0) in_posy = 0;
			if(strcmp(buffer, "strategy_list") == 0) in_strategy_list = 1;
			if(strcmp(buffer, "/strategy_list") == 0) in_strategy_list = 0;
			if(strcmp(buffer, "new_children") == 0) in_new_children = 1;
			if(strcmp(buffer, "/new_children") == 0) in_new_children = 0;
			if(strcmp(buffer, "nragents") == 0) in_nragents = 1;
			if(strcmp(buffer, "/nragents") == 0) in_nragents = 0;
			if(strcmp(buffer, "automata_id") == 0) in_automata_id = 1;
			if(strcmp(buffer, "/automata_id") == 0) in_automata_id = 0;
			if(strcmp(buffer, "players") == 0) in_players = 1;
			if(strcmp(buffer, "/players") == 0) in_players = 0;
			if(strcmp(buffer, "player_one_state") == 0) in_player_one_state = 1;
			if(strcmp(buffer, "/player_one_state") == 0) in_player_one_state = 0;
			if(strcmp(buffer, "player_two_state") == 0) in_player_two_state = 1;
			if(strcmp(buffer, "/player_two_state") == 0) in_player_two_state = 0;
			if(strcmp(buffer, "player_one_move") == 0) in_player_one_move = 1;
			if(strcmp(buffer, "/player_one_move") == 0) in_player_one_move = 0;
			if(strcmp(buffer, "player_two_move") == 0) in_player_two_move = 1;
			if(strcmp(buffer, "/player_two_move") == 0) in_player_two_move = 0;
			if(strcmp(buffer, "strategy_performance") == 0) in_strategy_performance = 1;
			if(strcmp(buffer, "/strategy_performance") == 0) in_strategy_performance = 0;
			if(strcmp(buffer, "offspring") == 0) in_offspring = 1;
			if(strcmp(buffer, "/offspring") == 0) in_offspring = 0;
			if(strcmp(buffer, "rows") == 0) in_rows = 1;
			if(strcmp(buffer, "/rows") == 0) in_rows = 0;
			if(strcmp(buffer, "player_list") == 0) in_player_list = 1;
			if(strcmp(buffer, "/player_list") == 0) in_player_list = 0;


			
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
			else if(in_GamePlayer_agent == 1)
			{
				if(in_id) current_GamePlayer_agent->id = atoi(buffer);
				if(in_strategy_used) current_GamePlayer_agent->strategy_used = atoi(buffer);
				if(in_previous_performance) current_GamePlayer_agent->previous_performance = atoi(buffer);
				if(in_present_state) current_GamePlayer_agent->present_state = atoi(buffer);
				if(in_iradius) current_GamePlayer_agent->iradius = atof(buffer);
				if(in_posx) current_GamePlayer_agent->posx = atof(buffer);
				if(in_posy) current_GamePlayer_agent->posy = atof(buffer);
			}else if(in_GameSolver_agent == 1)
			{
				if(in_strategy_list)
				{
					j = 0;
					read_complete_strategy_static_array(buffer, &j, current_GameSolver_agent->strategy_list, 30);
				}
				if(in_new_children)
				{
					j = 0;
					read_complete_strategy_static_array(buffer, &j, current_GameSolver_agent->new_children, 10);
				}
				if(in_nragents) current_GameSolver_agent->nragents = atoi(buffer);
				if(in_automata_id)
				{
					j = 0;
					read_int_dynamic_array(buffer, &j, &current_GameSolver_agent->automata_id);
				}
				if(in_players)
				{
					j = 0;
					read_int_dynamic_array(buffer, &j, &current_GameSolver_agent->players);
				}
				if(in_player_one_state)
				{
					j = 0;
					read_int_static_array(buffer, &j, current_GameSolver_agent->player_one_state, 4);
				}
				if(in_player_two_state)
				{
					j = 0;
					read_int_static_array(buffer, &j, current_GameSolver_agent->player_two_state, 4);
				}
				if(in_player_one_move) current_GameSolver_agent->player_one_move = atoi(buffer);
				if(in_player_two_move) current_GameSolver_agent->player_two_move = atoi(buffer);
				if(in_strategy_performance)
				{
					j = 0;
					read_strategy_data_static_array(buffer, &j, current_GameSolver_agent->strategy_performance, 30);
				}
				if(in_offspring)
				{
					j = 0;
					read_complete_strategy_static_array(buffer, &j, current_GameSolver_agent->offspring, 2);
				}
				if(in_rows)
				{
					j = 0;
					read_columns_dynamic_array(buffer, &j, &current_GameSolver_agent->rows);
				}
				if(in_player_list)
				{
					j = 0;
					read_player_list_element_dynamic_array(buffer, &j, &current_GameSolver_agent->player_list);
				}
				if(in_iradius) current_GameSolver_agent->iradius = atof(buffer);
				if(in_posx) current_GameSolver_agent->posx = atof(buffer);
				if(in_posy) current_GameSolver_agent->posy = atof(buffer);
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
////////////////	free_complete_strategy_static_array(strategy_list, 30);
//	free_complete_strategy_static_array(new_children, 10);
////	free_int_array(automata_id);
//	free_int_array(players);
//////////	free_strategy_data_static_array(strategy_performance, 30);
//	free_complete_strategy_static_array(offspring, 2);
//	free_columns_array(rows);
//	free_player_list_element_array(player_list);

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
	xmachine_memory_GamePlayer * current_GamePlayer;
	xmachine_memory_GameSolver * current_GameSolver;
	/*complete_strategy * strategy_list;*/
	/*complete_strategy * new_children;*/
	/*int * player_one_state;*/
	/*int * player_two_state;*/
	/*strategy_data * strategy_performance;*/
	/*complete_strategy * offspring;*/

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
		if(current_xmachine->xmachine_GamePlayer != NULL)
		{
			current_GamePlayer = current_xmachine->xmachine_GamePlayer;
			agentcount++;
		}
		else if(current_xmachine->xmachine_GameSolver != NULL)
		{
			current_GameSolver = current_xmachine->xmachine_GameSolver;
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

/** \fn void write_strategy_state(FILE *file, strategy_state * temp_datatype)
 * \brief Writes strategy_state datatype.
 */
void write_strategy_state(FILE *file, strategy_state * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	write_int_static_array(file, (*temp_datatype).starting_state, 4);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).state_name);
	fputs(data, file);
	fputs(", ", file);	write_int_static_array(file, (*temp_datatype).state_ifcooperate, 4);
	fputs(", ", file);	write_int_static_array(file, (*temp_datatype).state_ifdefect, 4);
	fputs("}", file);
}

void write_strategy_state_static_array(FILE *file, strategy_state * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_strategy_state(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_strategy_state_dynamic_array(FILE *file, strategy_state_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_strategy_state(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_payoff_elements(FILE *file, payoff_elements * temp_datatype)
 * \brief Writes payoff_elements datatype.
 */
void write_payoff_elements(FILE *file, payoff_elements * temp_datatype)
{
	
	
	fputs("{", file);
	write_int_static_array(file, (*temp_datatype).payoffs, 2);
	fputs("}", file);
}

void write_payoff_elements_static_array(FILE *file, payoff_elements * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_payoff_elements(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_payoff_elements_dynamic_array(FILE *file, payoff_elements_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_payoff_elements(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_strategy_data(FILE *file, strategy_data * temp_datatype)
 * \brief Writes strategy_data datatype.
 */
void write_strategy_data(FILE *file, strategy_data * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).strategy_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).strategy_perf);
	fputs(data, file);
	fputs("}", file);
}

void write_strategy_data_static_array(FILE *file, strategy_data * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_strategy_data(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_strategy_data_dynamic_array(FILE *file, strategy_data_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_strategy_data(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_complete_strategy(FILE *file, complete_strategy * temp_datatype)
 * \brief Writes complete_strategy datatype.
 */
void write_complete_strategy(FILE *file, complete_strategy * temp_datatype)
{
	
	
	fputs("{", file);
	write_strategy_state_dynamic_array(file, &(*temp_datatype).strategy_path);
	fputs("}", file);
}

void write_complete_strategy_static_array(FILE *file, complete_strategy * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_complete_strategy(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_complete_strategy_dynamic_array(FILE *file, complete_strategy_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_complete_strategy(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_columns(FILE *file, columns * temp_datatype)
 * \brief Writes columns datatype.
 */
void write_columns(FILE *file, columns * temp_datatype)
{
	
	
	fputs("{", file);
	write_payoff_elements_dynamic_array(file, &(*temp_datatype).opponents);
	fputs("}", file);
}

void write_columns_static_array(FILE *file, columns * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_columns(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_columns_dynamic_array(FILE *file, columns_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_columns(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_player_list_element(FILE *file, player_list_element * temp_datatype)
 * \brief Writes player_list_element datatype.
 */
void write_player_list_element(FILE *file, player_list_element * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).player_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).strategy_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).previous_move);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).present_state);
	fputs(data, file);
	fputs("}", file);
}

void write_player_list_element_static_array(FILE *file, player_list_element * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_player_list_element(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_player_list_element_dynamic_array(FILE *file, player_list_element_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_player_list_element(file, &(*temp_datatype).array[i]);
		
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
	xmachine_memory_GamePlayer * current_GamePlayer;
	xmachine_memory_GameSolver * current_GameSolver;
	//int_array * automata_id;
	//int_array * players;
	
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
		if(current_xmachine->xmachine_GamePlayer != NULL)
		{
			current_GamePlayer = current_xmachine->xmachine_GamePlayer;
			fputs("<name>GamePlayer</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_GamePlayer->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<strategy_used>", file);
			sprintf(data, "%i", current_GamePlayer->strategy_used);
			fputs(data, file);
			fputs("</strategy_used>\n", file);
			fputs("<previous_performance>", file);
			sprintf(data, "%i", current_GamePlayer->previous_performance);
			fputs(data, file);
			fputs("</previous_performance>\n", file);
			fputs("<present_state>", file);
			sprintf(data, "%i", current_GamePlayer->present_state);
			fputs(data, file);
			fputs("</present_state>\n", file);
			fputs("<iradius>", file);
			sprintf(data, "%f", current_GamePlayer->iradius);
			fputs(data, file);
			fputs("</iradius>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_GamePlayer->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_GamePlayer->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_GameSolver != NULL)
		{
			current_GameSolver = current_xmachine->xmachine_GameSolver;
			fputs("<name>GameSolver</name>\n", file);
			fputs("<strategy_list>", file);
			write_complete_strategy_static_array(file, current_GameSolver->strategy_list, 30);
			fputs("</strategy_list>\n", file);
			fputs("<new_children>", file);
			write_complete_strategy_static_array(file, current_GameSolver->new_children, 10);
			fputs("</new_children>\n", file);
			fputs("<nragents>", file);
			sprintf(data, "%i", current_GameSolver->nragents);
			fputs(data, file);
			fputs("</nragents>\n", file);
			fputs("<automata_id>", file);
			write_int_dynamic_array(file, &current_GameSolver->automata_id);
			fputs("</automata_id>\n", file);
			fputs("<players>", file);
			write_int_dynamic_array(file, &current_GameSolver->players);
			fputs("</players>\n", file);
			fputs("<player_one_state>", file);
			write_int_static_array(file, current_GameSolver->player_one_state, 4);
			fputs("</player_one_state>\n", file);
			fputs("<player_two_state>", file);
			write_int_static_array(file, current_GameSolver->player_two_state, 4);
			fputs("</player_two_state>\n", file);
			fputs("<player_one_move>", file);
			sprintf(data, "%i", current_GameSolver->player_one_move);
			fputs(data, file);
			fputs("</player_one_move>\n", file);
			fputs("<player_two_move>", file);
			sprintf(data, "%i", current_GameSolver->player_two_move);
			fputs(data, file);
			fputs("</player_two_move>\n", file);
			fputs("<strategy_performance>", file);
			write_strategy_data_static_array(file, current_GameSolver->strategy_performance, 30);
			fputs("</strategy_performance>\n", file);
			fputs("<offspring>", file);
			write_complete_strategy_static_array(file, current_GameSolver->offspring, 2);
			fputs("</offspring>\n", file);
			fputs("<rows>", file);
			write_columns_dynamic_array(file, &current_GameSolver->rows);
			fputs("</rows>\n", file);
			fputs("<player_list>", file);
			write_player_list_element_dynamic_array(file, &current_GameSolver->player_list);
			fputs("</player_list>\n", file);
			fputs("<iradius>", file);
			sprintf(data, "%f", current_GameSolver->iradius);
			fputs(data, file);
			fputs("</iradius>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_GameSolver->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_GameSolver->posy);
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
