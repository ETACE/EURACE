/**
 * \file  xml.c
 * \brief Holds xml reading and writing functions.
 */

#include "header.h"

/** \fn void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag)
 * \brief Read initial X-machine memory starting values from a file.
 * \param filename The path to the file.
 * \param itno Pointer to the iteration number.
 * \param agent_list List of agents in the model to be constructed by this function.
 * \param cloud_data Max and min x,y,z coordinates of agents.
 * \param flag Flag for whether to check space partitions.
 */
void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = ' ';
	char buffer[10000];
	char agentname[1000];
	
	/* Variables for dealing with variables which are arrays */
	char arraydata[10000];
	int array_k=0, j=0, arraycount=0;
	
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
	int in_tag, in_itno, in_agent, in_name, in_environment;
	int in_assets;
	int in_posx;
	int in_posy;
	int in_id;
	int in_wealth;
	int in_belief;
	int in_portfolio;
	int in_pendingOrders;
	int in_assetsowned;


	/* Variables for initial state data */
	Asset_array * assets;
	double posx;
	double posy;
	int id;
	double wealth;
	Belief * belief;
	Portfolio * portfolio;
	Order_array * pendingOrders;
	Asset_array * assetsowned;

	//Asset * current_assets;
	//Order * current_pendingOrders;
	//Asset * current_assetsowned;

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
	in_assets = 0;
	in_posx = 0;
	in_posy = 0;
	in_id = 0;
	in_wealth = 0;
	in_belief = 0;
	in_portfolio = 0;
	in_pendingOrders = 0;
	in_assetsowned = 0;


	/* Default variables for memory */
	/* Not implemented static arrays */
	//current_assets = (Asset *)malloc(sizeof(Asset));
	posx = 0.0;
	posy = 0.0;
	id = 0;
	wealth = 0.0;
	//current_pendingOrders = (Order *)malloc(sizeof(Order));
	//current_assetsowned = (Asset *)malloc(sizeof(Asset));



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
			if(strcmp(buffer, "/name") == 0) in_name = 0;
			if(strcmp(buffer, "environment") == 0) in_environment = 1;
			if(strcmp(buffer, "/environment") == 0) in_environment = 0;
			if(strcmp(buffer, "xagent") == 0) in_agent = 1;
			if(strcmp(buffer, "/xagent") == 0)
			{
				in_agent = 0;
				
				if(strcmp(agentname, "Eurostat") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_Eurostat_agent(assets, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}
					else if (
					    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
					    ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
					)
					{
					    p_xmachine = &(current_node->agents);
					    add_Eurostat_agent(assets, posx, posy);
					}
				}
				else if(strcmp(agentname, "Household") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}
					else if (
					    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
					    ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
					)
					{
					    p_xmachine = &(current_node->agents);
					    add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, posx, posy);
					}
				}
				else if(strcmp(agentname, "ClearingHouse") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_ClearingHouse_agent(id, assets, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}
					else if (
					    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
					    ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
					)
					{
					    p_xmachine = &(current_node->agents);
					    add_ClearingHouse_agent(id, assets, posx, posy);
					}
				}
				else
				{
					printf("Warning: agent name undefined - '%s'\n", agentname);
				}
				

				
				/* Reset xagent variables */
				/* Not implemented static arrays */
				posx = 0.0;
				posy = 0.0;
				id = 0;
				wealth = 0.0;
			}
			if(strcmp(buffer, "assets") == 0) in_assets = 1;
			if(strcmp(buffer, "/assets") == 0) in_assets = 0;
			if(strcmp(buffer, "posx") == 0) in_posx = 1;
			if(strcmp(buffer, "/posx") == 0) in_posx = 0;
			if(strcmp(buffer, "posy") == 0) in_posy = 1;
			if(strcmp(buffer, "/posy") == 0) in_posy = 0;
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
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
			else
			{
				if(in_assets)
				{
					assets = init_Asset_array();
					
					j = 1;
					arraycount = 0;
					
					while(buffer[j] == '{')
					{
						
						add_Asset(assets, 0, 0, 0.0);
						
						array_k = 0;
						j++;
						while(buffer[j] != ',')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						assets->array[arraycount]->issuer = atoi(arraydata);
						array_k = 0;
						j++;
						while(buffer[j] != ',')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						assets->array[arraycount]->quantity = atoi(arraydata);
						array_k = 0;
						j++;
						while(buffer[j] != '}')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						assets->array[arraycount]->lastPrice = atof(arraydata);
						arraycount++;
						j++;
						if(buffer[j] == ',') j += 2;
					}
				}
				if(in_posx) posx = atof(buffer);
				if(in_posy) posy = atof(buffer);
				if(in_id) id = atoi(buffer);
				if(in_wealth) wealth = atof(buffer);
				if(in_belief)
				{
					j = 0;
					belief = (Belief *)malloc(sizeof(Belief));
					belief->assetsExpectedPriceReturns = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->assetsExpectedPriceReturns = atof(arraydata);
					belief->assetsExpectedTotalReturns = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->assetsExpectedTotalReturns = atof(arraydata);
					belief->assetsExpectedCashFlowYield = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->assetsExpectedCashFlowYield = atof(arraydata);
					belief->volatility = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->volatility = atof(arraydata);
					belief->forwardWindow = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->forwardWindow = atoi(arraydata);
					belief->backwordWindow = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->backwordWindow = atoi(arraydata);
					belief->binsNumber = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->binsNumber = atoi(arraydata);
					belief->randomReturnWeigth = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->randomReturnWeigth = atof(arraydata);
					belief->fundametalReturnWeigth = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->fundametalReturnWeigth = atof(arraydata);
					belief->chartistReturnWeigth = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->chartistReturnWeigth = atof(arraydata);
					belief->holdingPeriodToForwardW = 0;
					array_k = 0;
					j++;
					while(buffer[j] != '}')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->holdingPeriodToForwardW = atoi(arraydata);
				}
				if(in_portfolio)
				{
					j = 0;
					portfolio = (Portfolio *)malloc(sizeof(Portfolio));
					portfolio->bankAccount = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != '}')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					portfolio->bankAccount = atof(arraydata);
				}
				if(in_pendingOrders)
				{
					pendingOrders = init_Order_array();
					
					j = 1;
					arraycount = 0;
					
					while(buffer[j] == '{')
					{
						
						add_Order(pendingOrders, 0, 0, 0.0, 0);
						
						array_k = 0;
						j++;
						while(buffer[j] != ',')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						pendingOrders->array[arraycount]->issuer = atoi(arraydata);
						array_k = 0;
						j++;
						while(buffer[j] != ',')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						pendingOrders->array[arraycount]->quantity = atoi(arraydata);
						array_k = 0;
						j++;
						while(buffer[j] != ',')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						pendingOrders->array[arraycount]->price = atof(arraydata);
						array_k = 0;
						j++;
						while(buffer[j] != '}')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						pendingOrders->array[arraycount]->assetId = atoi(arraydata);
						arraycount++;
						j++;
						if(buffer[j] == ',') j += 2;
					}
				}
				if(in_assetsowned)
				{
					assetsowned = init_Asset_array();
					
					j = 1;
					arraycount = 0;
					
					while(buffer[j] == '{')
					{
						
						add_Asset(assetsowned, 0, 0, 0.0);
						
						array_k = 0;
						j++;
						while(buffer[j] != ',')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						assetsowned->array[arraycount]->issuer = atoi(arraydata);
						array_k = 0;
						j++;
						while(buffer[j] != ',')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						assetsowned->array[arraycount]->quantity = atoi(arraydata);
						array_k = 0;
						j++;
						while(buffer[j] != '}')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						assetsowned->array[arraycount]->lastPrice = atof(arraydata);
						arraycount++;
						j++;
						if(buffer[j] == ',') j += 2;
					}
				}
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
	/* Close the file */
	fclose(file);
	/* Free temp data structures */
	//free(current_assets);
//free(current_pendingOrders);
//free(current_assetsowned);

}

/** \fn void saveiterationdata_binary(int iteration_number)
 * \brief Save X-machine memory to a binary file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata_binary(int iteration_number)
{
	/* Pointer to file */
	FILE *file;
	char data[100];
    int i;
	int agentcount = 0;
	xmachine_memory_Eurostat * current_Eurostat;
	xmachine_memory_Household * current_Household;
	xmachine_memory_ClearingHouse * current_ClearingHouse;

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

/** \fn void saveiterationdata(int iteration_number)
 * \brief Save X-machine memory to a file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata(int iteration_number)
{
	/* Pointer to file */
	FILE *file;
	char data[100];
	int i;
	xmachine_memory_Eurostat * current_Eurostat;
	xmachine_memory_Household * current_Household;
	xmachine_memory_ClearingHouse * current_ClearingHouse;
	
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
			fputs("<assets>", file);
			fputs("{", file);
			for(i = 0; i < current_Eurostat->assets->size; i++)
			{
				fputs("{", file);
				sprintf(data, "%i", current_Eurostat->assets->array[i]->issuer);
				fputs(data, file);
				fputs(", ", file);
				sprintf(data, "%i", current_Eurostat->assets->array[i]->quantity);
				fputs(data, file);
				fputs(", ", file);
				sprintf(data, "%f", current_Eurostat->assets->array[i]->lastPrice);
				fputs(data, file);
				fputs("}", file);
				if(i < current_Eurostat->assets->size - 1) fputs(", ", file);
			}
			fputs("}", file);
			fputs("</assets>\n", file);
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
			fputs("{", file);
			sprintf(data, "%f", current_Household->belief->assetsExpectedPriceReturns);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->belief->assetsExpectedTotalReturns);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->belief->assetsExpectedCashFlowYield);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->belief->volatility);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->belief->forwardWindow);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->belief->backwordWindow);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->belief->binsNumber);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->belief->randomReturnWeigth);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->belief->fundametalReturnWeigth);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->belief->chartistReturnWeigth);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->belief->holdingPeriodToForwardW);
			fputs(data, file);
			fputs("}", file);
			fputs("</belief>\n", file);
			fputs("<portfolio>", file);
			fputs("{", file);
			sprintf(data, "%f", current_Household->portfolio->bankAccount);
			fputs(data, file);
			fputs("}", file);
			fputs("</portfolio>\n", file);
			fputs("<pendingOrders>", file);
			fputs("{", file);
			for(i = 0; i < current_Household->pendingOrders->size; i++)
			{
				fputs("{", file);
				sprintf(data, "%i", current_Household->pendingOrders->array[i]->issuer);
				fputs(data, file);
				fputs(", ", file);
				sprintf(data, "%i", current_Household->pendingOrders->array[i]->quantity);
				fputs(data, file);
				fputs(", ", file);
				sprintf(data, "%f", current_Household->pendingOrders->array[i]->price);
				fputs(data, file);
				fputs(", ", file);
				sprintf(data, "%i", current_Household->pendingOrders->array[i]->assetId);
				fputs(data, file);
				fputs("}", file);
				if(i < current_Household->pendingOrders->size - 1) fputs(", ", file);
			}
			fputs("}", file);
			fputs("</pendingOrders>\n", file);
			fputs("<assetsowned>", file);
			fputs("{", file);
			for(i = 0; i < current_Household->assetsowned->size; i++)
			{
				fputs("{", file);
				sprintf(data, "%i", current_Household->assetsowned->array[i]->issuer);
				fputs(data, file);
				fputs(", ", file);
				sprintf(data, "%i", current_Household->assetsowned->array[i]->quantity);
				fputs(data, file);
				fputs(", ", file);
				sprintf(data, "%f", current_Household->assetsowned->array[i]->lastPrice);
				fputs(data, file);
				fputs("}", file);
				if(i < current_Household->assetsowned->size - 1) fputs(", ", file);
			}
			fputs("}", file);
			fputs("</assetsowned>\n", file);
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
			fputs("{", file);
			for(i = 0; i < current_ClearingHouse->assets->size; i++)
			{
				fputs("{", file);
				sprintf(data, "%i", current_ClearingHouse->assets->array[i]->issuer);
				fputs(data, file);
				fputs(", ", file);
				sprintf(data, "%i", current_ClearingHouse->assets->array[i]->quantity);
				fputs(data, file);
				fputs(", ", file);
				sprintf(data, "%f", current_ClearingHouse->assets->array[i]->lastPrice);
				fputs(data, file);
				fputs("}", file);
				if(i < current_ClearingHouse->assets->size - 1) fputs(", ", file);
			}
			fputs("}", file);
			fputs("</assets>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_ClearingHouse->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_ClearingHouse->posy);
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
