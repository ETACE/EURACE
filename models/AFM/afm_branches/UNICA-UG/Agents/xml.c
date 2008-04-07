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
	
	/* Variables for dealing with variables which are arrays */
	char arraydata[10000];
	int array_k=0, j=0, arraycount=0;

/* Things for round-robin partitioning */
	int agent_count;
	int number_partitions;
	int geometric=1;
	int other=2;
	double 	xmax=0,xmin=0,ymax=0,ymin=0,
		xcentre=0,ycentre=0,
		rrange=1.5;
	
	
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
	int id;
	Asset_array * assets;
	double range;
	double posx;
	double posy;
	double wealth;
	Belief * belief;
	Portfolio * portfolio;
	Order_array * pendingOrders;
	Asset_array * assetsowned;
	int forwardWindow;
	int backwordWindow;
	int binsNumber;
	double randomReturnWeigth;
	double fundametalReturnWeigth;
	double chartistReturnWeigth;
	int holdingPeriodToForwardW;
	int current_shares_outstanding;
	double total_dividend_payment;
	double bank_account;
	double equity;

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
	id = 0;

//current_assets = (Asset *)malloc(sizeof(Asset));
//CHECK_POINTER(current_assets);
	range = 0.0;
	posx = 0.0;
	posy = 0.0;
	wealth = 0.0;

//current_pendingOrders = (Order *)malloc(sizeof(Order));
//CHECK_POINTER(current_pendingOrders);

//current_assetsowned = (Asset *)malloc(sizeof(Asset));
//CHECK_POINTER(current_assetsowned);
	forwardWindow = 0;
	backwordWindow = 0;
	binsNumber = 0;
	randomReturnWeigth = 0.0;
	fundametalReturnWeigth = 0.0;
	chartistReturnWeigth = 0.0;
	holdingPeriodToForwardW = 0;
	current_shares_outstanding = 0;
	total_dividend_payment = 0.0;
	bank_account = 0.0;
	equity = 0.0;







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
						add_Eurostat_agent(id, assets, range, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}

					else if (flag != 0)
					{
					    if(partition_method == geometric) {
					        if (
    				    	    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
    					        ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
        					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
        					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
        					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
        					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
        					)
        					{
        					    p_xmachine = &(current_node->agents);
        					    add_Eurostat_agent(id, assets, range, posx, posy);
        					} 
	    				}
	    				else if (partition_method == other){
	    				    if (agent_count % number_partitions == 0) {
                    			/* Compute centre of partition */
		                       	xmin=current_node->partition_data[0];
                        		xmax=current_node->partition_data[1];
                       			ymin=current_node->partition_data[2];
                       			ymax=current_node->partition_data[3];

			                    xcentre=xmin+(xmax-xmin)/2.0;
                    			ycentre=ymin+(ymax-ymin)/2.0;
                    			rrange=1.5;

                    			p_xmachine = &(current_node->agents);
                    			add_Eurostat_agent(id, assets, range, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_range(rrange);

					        }
    					    ++agent_count;
					    } /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Household") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, forwardWindow, backwordWindow, binsNumber, randomReturnWeigth, fundametalReturnWeigth, chartistReturnWeigth, holdingPeriodToForwardW, range, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}

					else if (flag != 0)
					{
					    if(partition_method == geometric) {
					        if (
    				    	    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
    					        ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
        					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
        					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
        					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
        					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
        					)
        					{
        					    p_xmachine = &(current_node->agents);
        					    add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, forwardWindow, backwordWindow, binsNumber, randomReturnWeigth, fundametalReturnWeigth, chartistReturnWeigth, holdingPeriodToForwardW, range, posx, posy);
        					} 
	    				}
	    				else if (partition_method == other){
	    				    if (agent_count % number_partitions == 0) {
                    			/* Compute centre of partition */
		                       	xmin=current_node->partition_data[0];
                        		xmax=current_node->partition_data[1];
                       			ymin=current_node->partition_data[2];
                       			ymax=current_node->partition_data[3];

			                    xcentre=xmin+(xmax-xmin)/2.0;
                    			ycentre=ymin+(ymax-ymin)/2.0;
                    			rrange=1.5;

                    			p_xmachine = &(current_node->agents);
                    			add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, forwardWindow, backwordWindow, binsNumber, randomReturnWeigth, fundametalReturnWeigth, chartistReturnWeigth, holdingPeriodToForwardW, range, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_range(rrange);

					        }
    					    ++agent_count;
					    } /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "ClearingHouse") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_ClearingHouse_agent(id, assets, range, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}

					else if (flag != 0)
					{
					    if(partition_method == geometric) {
					        if (
    				    	    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
    					        ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
        					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
        					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
        					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
        					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
        					)
        					{
        					    p_xmachine = &(current_node->agents);
        					    add_ClearingHouse_agent(id, assets, range, posx, posy);
        					} 
	    				}
	    				else if (partition_method == other){
	    				    if (agent_count % number_partitions == 0) {
                    			/* Compute centre of partition */
		                       	xmin=current_node->partition_data[0];
                        		xmax=current_node->partition_data[1];
                       			ymin=current_node->partition_data[2];
                       			ymax=current_node->partition_data[3];

			                    xcentre=xmin+(xmax-xmin)/2.0;
                    			ycentre=ymin+(ymax-ymin)/2.0;
                    			rrange=1.5;

                    			p_xmachine = &(current_node->agents);
                    			add_ClearingHouse_agent(id, assets, range, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_range(rrange);

					        }
    					    ++agent_count;
					    } /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Firm") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_Firm_agent(id, current_shares_outstanding, total_dividend_payment, bank_account, equity, range, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}

					else if (flag != 0)
					{
					    if(partition_method == geometric) {
					        if (
    				    	    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
    					        ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
        					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
        					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
        					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
        					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
        					)
        					{
        					    p_xmachine = &(current_node->agents);
        					    add_Firm_agent(id, current_shares_outstanding, total_dividend_payment, bank_account, equity, range, posx, posy);
        					} 
	    				}
	    				else if (partition_method == other){
	    				    if (agent_count % number_partitions == 0) {
                    			/* Compute centre of partition */
		                       	xmin=current_node->partition_data[0];
                        		xmax=current_node->partition_data[1];
                       			ymin=current_node->partition_data[2];
                       			ymax=current_node->partition_data[3];

			                    xcentre=xmin+(xmax-xmin)/2.0;
                    			ycentre=ymin+(ymax-ymin)/2.0;
                    			rrange=1.5;

                    			p_xmachine = &(current_node->agents);
                    			add_Firm_agent(id, current_shares_outstanding, total_dividend_payment, bank_account, equity, range, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_range(rrange);

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
				id = 0;
				range = 0.0;
				posx = 0.0;
				posy = 0.0;
				wealth = 0.0;
				forwardWindow = 0;
				backwordWindow = 0;
				binsNumber = 0;
				randomReturnWeigth = 0.0;
				fundametalReturnWeigth = 0.0;
				chartistReturnWeigth = 0.0;
				holdingPeriodToForwardW = 0;
				current_shares_outstanding = 0;
				total_dividend_payment = 0.0;
				bank_account = 0.0;
				equity = 0.0;
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
			else
			{
				if(in_id) id = atoi(buffer);
				if(in_assets)
				{
					assets = init_Asset_array();
					
                    CHECK_POINTER(assets);
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
				if(in_range) range = atof(buffer);
				if(in_posx) posx = atof(buffer);
				if(in_posy) posy = atof(buffer);
				if(in_wealth) wealth = atof(buffer);
				if(in_belief)
				{
					j = 0;
					belief = (Belief *)malloc(sizeof(Belief));
					CHECK_POINTER(expectedPriceReturns);
					belief->expectedPriceReturns = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->expectedPriceReturns = atof(arraydata);
					CHECK_POINTER(expectedTotalReturns);
					belief->expectedTotalReturns = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->expectedTotalReturns = atof(arraydata);
					CHECK_POINTER(expectedCashFlowYield);
					belief->expectedCashFlowYield = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->expectedCashFlowYield = atof(arraydata);
					CHECK_POINTER(volatility);
					belief->volatility = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != '}')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					belief->volatility = atof(arraydata);
				}
				if(in_portfolio)
				{
					j = 0;
					portfolio = (Portfolio *)malloc(sizeof(Portfolio));
					CHECK_POINTER(bankAccount);
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
					
                    CHECK_POINTER(pendingOrders);
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
					
                    CHECK_POINTER(assetsowned);
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
				if(in_forwardWindow) forwardWindow = atoi(buffer);
				if(in_backwordWindow) backwordWindow = atoi(buffer);
				if(in_binsNumber) binsNumber = atoi(buffer);
				if(in_randomReturnWeigth) randomReturnWeigth = atof(buffer);
				if(in_fundametalReturnWeigth) fundametalReturnWeigth = atof(buffer);
				if(in_chartistReturnWeigth) chartistReturnWeigth = atof(buffer);
				if(in_holdingPeriodToForwardW) holdingPeriodToForwardW = atoi(buffer);
				if(in_current_shares_outstanding) current_shares_outstanding = atoi(buffer);
				if(in_total_dividend_payment) total_dividend_payment = atof(buffer);
				if(in_bank_account) bank_account = atof(buffer);
				if(in_equity) equity = atof(buffer);
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
			fputs("{", file);
			sprintf(data, "%f", current_Household->belief->expectedPriceReturns);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->belief->expectedTotalReturns);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->belief->expectedCashFlowYield);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->belief->volatility);
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
