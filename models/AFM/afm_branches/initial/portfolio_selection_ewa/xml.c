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
	int in_household_id;
	int in_agent_classifiersystem;
	int in_asset_budget;
	int in_current_assetportfolio;
	int in_prescribed_assetportfolio;
	int in_nr_selected_rule;
	int in_current_rule_performance;
	int in_EWA_rho;
	int in_EWA_phi;
	int in_EWA_delta;
	int in_EWA_beta;
	int in_prescribed_asset_value;
	int in_iradius;
	int in_posx;
	int in_posy;
	int in_revenues;
	int in_sales_costs;
	int in_total_revenue;
	int in_net_revenue;
	int in_operational_cost;
	int in_total_wage_payments;
	int in_total_input_payments;
	int in_interest_payments;
	int in_total_earnings;
	int in_tax_rate_profits;
	int in_pretax_profit;
	int in_tax_provision;
	int in_net_earnings;
	int in_div_payments;
	int in_retained_earnings;
	int in_current_debt;
	int in_debt_interest_rate;
	int in_debt_repayments;
	int in_share_repurchase_value;
	int in_share_repurchase_units;
	int in_target_total_shares;
	int in_current_total_shares;
	int in_total_financial_needs;
	int in_financial_needs;
	int in_add_financial_needs;
	int in_financial_reserves;
	int in_target_loans;
	int in_target_equity;
	int in_bonds_issue_target;
	int in_stocks_issue_target;
	int in_price;
	int in_max_debt;
	int in_div_earn_ratio;
	int in_debt_earn_ratio;
	int in_div_pshare_ratio;
	int in_earn_pshare_ratio;
	int in_price_earn_ratio;
	int in_retained_earn_ratio;
	int in_earn_pshare_ratio_growth;
	int in_critical_price_earn_ratio;
	int in_critical_earn_pshare_ratio;
	int in_id;
	int in_re;
	int in_rj;
	int in_central_classifiersystem;


	/* Variables for initial state data */
	int household_id;
	PrivateClassifierSystem * agent_classifiersystem;
	double asset_budget;
	AssetPortfolioType * current_assetportfolio;
	AssetPortfolioType * prescribed_assetportfolio;
	int nr_selected_rule;
	double current_rule_performance;
	double EWA_rho;
	double EWA_phi;
	double EWA_delta;
	double EWA_beta;
	double prescribed_asset_value;
	double iradius;
	double posx;
	double posy;
	double_array * revenues;
	double_array * sales_costs;
	double total_revenue;
	double net_revenue;
	double operational_cost;
	double total_wage_payments;
	double total_input_payments;
	double interest_payments;
	double total_earnings;
	double tax_rate_profits;
	double pretax_profit;
	double tax_provision;
	double net_earnings;
	double div_payments;
	double retained_earnings;
	double current_debt;
	double debt_interest_rate;
	double debt_repayments;
	double share_repurchase_value;
	int share_repurchase_units;
	int target_total_shares;
	int current_total_shares;
	double total_financial_needs;
	double financial_needs;
	double add_financial_needs;
	double financial_reserves;
	double target_loans;
	double target_equity;
	double bonds_issue_target;
	double stocks_issue_target;
	double price;
	double max_debt;
	double div_earn_ratio;
	double debt_earn_ratio;
	double div_pshare_ratio;
	double earn_pshare_ratio;
	double price_earn_ratio;
	double retained_earn_ratio;
	double earn_pshare_ratio_growth;
	double critical_price_earn_ratio;
	double critical_earn_pshare_ratio;
	int id;
	double re;
	double rj;
	PublicClassifierSystem * central_classifiersystem;


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
	in_household_id = 0;
	in_agent_classifiersystem = 0;
	in_asset_budget = 0;
	in_current_assetportfolio = 0;
	in_prescribed_assetportfolio = 0;
	in_nr_selected_rule = 0;
	in_current_rule_performance = 0;
	in_EWA_rho = 0;
	in_EWA_phi = 0;
	in_EWA_delta = 0;
	in_EWA_beta = 0;
	in_prescribed_asset_value = 0;
	in_iradius = 0;
	in_posx = 0;
	in_posy = 0;
	in_revenues = 0;
	in_sales_costs = 0;
	in_total_revenue = 0;
	in_net_revenue = 0;
	in_operational_cost = 0;
	in_total_wage_payments = 0;
	in_total_input_payments = 0;
	in_interest_payments = 0;
	in_total_earnings = 0;
	in_tax_rate_profits = 0;
	in_pretax_profit = 0;
	in_tax_provision = 0;
	in_net_earnings = 0;
	in_div_payments = 0;
	in_retained_earnings = 0;
	in_current_debt = 0;
	in_debt_interest_rate = 0;
	in_debt_repayments = 0;
	in_share_repurchase_value = 0;
	in_share_repurchase_units = 0;
	in_target_total_shares = 0;
	in_current_total_shares = 0;
	in_total_financial_needs = 0;
	in_financial_needs = 0;
	in_add_financial_needs = 0;
	in_financial_reserves = 0;
	in_target_loans = 0;
	in_target_equity = 0;
	in_bonds_issue_target = 0;
	in_stocks_issue_target = 0;
	in_price = 0;
	in_max_debt = 0;
	in_div_earn_ratio = 0;
	in_debt_earn_ratio = 0;
	in_div_pshare_ratio = 0;
	in_earn_pshare_ratio = 0;
	in_price_earn_ratio = 0;
	in_retained_earn_ratio = 0;
	in_earn_pshare_ratio_growth = 0;
	in_critical_price_earn_ratio = 0;
	in_critical_earn_pshare_ratio = 0;
	in_id = 0;
	in_re = 0;
	in_rj = 0;
	in_central_classifiersystem = 0;


	/* Default variables for memory */
	/* Not implemented static arrays */
	household_id = 0;
	asset_budget = 0.0;
	nr_selected_rule = 0;
	current_rule_performance = 0.0;
	EWA_rho = 0.0;
	EWA_phi = 0.0;
	EWA_delta = 0.0;
	EWA_beta = 0.0;
	prescribed_asset_value = 0.0;
	iradius = 0.0;
	posx = 0.0;
	posy = 0.0;
	total_revenue = 0.0;
	net_revenue = 0.0;
	operational_cost = 0.0;
	total_wage_payments = 0.0;
	total_input_payments = 0.0;
	interest_payments = 0.0;
	total_earnings = 0.0;
	tax_rate_profits = 0.0;
	pretax_profit = 0.0;
	tax_provision = 0.0;
	net_earnings = 0.0;
	div_payments = 0.0;
	retained_earnings = 0.0;
	current_debt = 0.0;
	debt_interest_rate = 0.0;
	debt_repayments = 0.0;
	share_repurchase_value = 0.0;
	share_repurchase_units = 0;
	target_total_shares = 0;
	current_total_shares = 0;
	total_financial_needs = 0.0;
	financial_needs = 0.0;
	add_financial_needs = 0.0;
	financial_reserves = 0.0;
	target_loans = 0.0;
	target_equity = 0.0;
	bonds_issue_target = 0.0;
	stocks_issue_target = 0.0;
	price = 0.0;
	max_debt = 0.0;
	div_earn_ratio = 0.0;
	debt_earn_ratio = 0.0;
	div_pshare_ratio = 0.0;
	earn_pshare_ratio = 0.0;
	price_earn_ratio = 0.0;
	retained_earn_ratio = 0.0;
	earn_pshare_ratio_growth = 0.0;
	critical_price_earn_ratio = 0.0;
	critical_earn_pshare_ratio = 0.0;
	id = 0;
	re = 0.0;
	rj = 0.0;







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
				
				if(strcmp(agentname, "Household") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_Household_agent(household_id, agent_classifiersystem, asset_budget, current_assetportfolio, prescribed_assetportfolio, nr_selected_rule, current_rule_performance, EWA_rho, EWA_phi, EWA_delta, EWA_beta, prescribed_asset_value, asset_budget, iradius, posx, posy);
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
        					    add_Household_agent(household_id, agent_classifiersystem, asset_budget, current_assetportfolio, prescribed_assetportfolio, nr_selected_rule, current_rule_performance, EWA_rho, EWA_phi, EWA_delta, EWA_beta, prescribed_asset_value, asset_budget, iradius, posx, posy);
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
                    			add_Household_agent(household_id, agent_classifiersystem, asset_budget, current_assetportfolio, prescribed_assetportfolio, nr_selected_rule, current_rule_performance, EWA_rho, EWA_phi, EWA_delta, EWA_beta, prescribed_asset_value, asset_budget, iradius, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_(rrange);

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
						add_Firm_agent(revenues, sales_costs, total_revenue, net_revenue, operational_cost, total_wage_payments, total_input_payments, interest_payments, total_earnings, tax_rate_profits, pretax_profit, tax_provision, net_earnings, div_payments, retained_earnings, current_debt, debt_interest_rate, debt_repayments, share_repurchase_value, share_repurchase_units, target_total_shares, current_total_shares, total_financial_needs, financial_needs, add_financial_needs, financial_reserves, target_loans, target_equity, bonds_issue_target, stocks_issue_target, price, max_debt, div_earn_ratio, debt_earn_ratio, div_pshare_ratio, earn_pshare_ratio, price_earn_ratio, retained_earn_ratio, earn_pshare_ratio_growth, critical_price_earn_ratio, critical_earn_pshare_ratio, iradius, posx, posy);
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
        					    add_Firm_agent(revenues, sales_costs, total_revenue, net_revenue, operational_cost, total_wage_payments, total_input_payments, interest_payments, total_earnings, tax_rate_profits, pretax_profit, tax_provision, net_earnings, div_payments, retained_earnings, current_debt, debt_interest_rate, debt_repayments, share_repurchase_value, share_repurchase_units, target_total_shares, current_total_shares, total_financial_needs, financial_needs, add_financial_needs, financial_reserves, target_loans, target_equity, bonds_issue_target, stocks_issue_target, price, max_debt, div_earn_ratio, debt_earn_ratio, div_pshare_ratio, earn_pshare_ratio, price_earn_ratio, retained_earn_ratio, earn_pshare_ratio_growth, critical_price_earn_ratio, critical_earn_pshare_ratio, iradius, posx, posy);
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
                    			add_Firm_agent(revenues, sales_costs, total_revenue, net_revenue, operational_cost, total_wage_payments, total_input_payments, interest_payments, total_earnings, tax_rate_profits, pretax_profit, tax_provision, net_earnings, div_payments, retained_earnings, current_debt, debt_interest_rate, debt_repayments, share_repurchase_value, share_repurchase_units, target_total_shares, current_total_shares, total_financial_needs, financial_needs, add_financial_needs, financial_reserves, target_loans, target_equity, bonds_issue_target, stocks_issue_target, price, max_debt, div_earn_ratio, debt_earn_ratio, div_pshare_ratio, earn_pshare_ratio, price_earn_ratio, retained_earn_ratio, earn_pshare_ratio_growth, critical_price_earn_ratio, critical_earn_pshare_ratio, iradius, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_(rrange);

					        }
    					    ++agent_count;
					    } /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Bank") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_Bank_agent(id, iradius, posx, posy);
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
        					    add_Bank_agent(id, iradius, posx, posy);
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
                    			add_Bank_agent(id, iradius, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_(rrange);

					        }
    					    ++agent_count;
					    } /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "ClearingHouseMechanism") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_ClearingHouseMechanism_agent(id, iradius, posx, posy);
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
        					    add_ClearingHouseMechanism_agent(id, iradius, posx, posy);
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
                    			add_ClearingHouseMechanism_agent(id, iradius, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_(rrange);

					        }
    					    ++agent_count;
					    } /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "LimitOrderBook") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_LimitOrderBook_agent(re, iradius, posx, posy);
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
        					    add_LimitOrderBook_agent(re, iradius, posx, posy);
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
                    			add_LimitOrderBook_agent(re, iradius, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_(rrange);

					        }
    					    ++agent_count;
					    } /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Government") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_Government_agent(rj, iradius, posx, posy);
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
        					    add_Government_agent(rj, iradius, posx, posy);
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
                    			add_Government_agent(rj, iradius, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_(rrange);

					        }
    					    ++agent_count;
					    } /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "FinancialAdvisor") == 0)
				{
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_FinancialAdvisor_agent(central_classifiersystem, iradius, posx, posy);
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
        					    add_FinancialAdvisor_agent(central_classifiersystem, iradius, posx, posy);
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
                    			add_FinancialAdvisor_agent(central_classifiersystem, iradius, posx, posy);

                    			set_posx(xcentre);
                    			set_posy(ycentre);
                    			set_(rrange);

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
				household_id = 0;
				asset_budget = 0.0;
				nr_selected_rule = 0;
				current_rule_performance = 0.0;
				EWA_rho = 0.0;
				EWA_phi = 0.0;
				EWA_delta = 0.0;
				EWA_beta = 0.0;
				prescribed_asset_value = 0.0;
				iradius = 0.0;
				posx = 0.0;
				posy = 0.0;
				total_revenue = 0.0;
				net_revenue = 0.0;
				operational_cost = 0.0;
				total_wage_payments = 0.0;
				total_input_payments = 0.0;
				interest_payments = 0.0;
				total_earnings = 0.0;
				tax_rate_profits = 0.0;
				pretax_profit = 0.0;
				tax_provision = 0.0;
				net_earnings = 0.0;
				div_payments = 0.0;
				retained_earnings = 0.0;
				current_debt = 0.0;
				debt_interest_rate = 0.0;
				debt_repayments = 0.0;
				share_repurchase_value = 0.0;
				share_repurchase_units = 0;
				target_total_shares = 0;
				current_total_shares = 0;
				total_financial_needs = 0.0;
				financial_needs = 0.0;
				add_financial_needs = 0.0;
				financial_reserves = 0.0;
				target_loans = 0.0;
				target_equity = 0.0;
				bonds_issue_target = 0.0;
				stocks_issue_target = 0.0;
				price = 0.0;
				max_debt = 0.0;
				div_earn_ratio = 0.0;
				debt_earn_ratio = 0.0;
				div_pshare_ratio = 0.0;
				earn_pshare_ratio = 0.0;
				price_earn_ratio = 0.0;
				retained_earn_ratio = 0.0;
				earn_pshare_ratio_growth = 0.0;
				critical_price_earn_ratio = 0.0;
				critical_earn_pshare_ratio = 0.0;
				id = 0;
				re = 0.0;
				rj = 0.0;
			}
			if(strcmp(buffer, "household_id") == 0) in_household_id = 1;
			if(strcmp(buffer, "/household_id") == 0) in_household_id = 0;
			if(strcmp(buffer, "agent_classifiersystem") == 0) in_agent_classifiersystem = 1;
			if(strcmp(buffer, "/agent_classifiersystem") == 0) in_agent_classifiersystem = 0;
			if(strcmp(buffer, "asset_budget") == 0) in_asset_budget = 1;
			if(strcmp(buffer, "/asset_budget") == 0) in_asset_budget = 0;
			if(strcmp(buffer, "current_assetportfolio") == 0) in_current_assetportfolio = 1;
			if(strcmp(buffer, "/current_assetportfolio") == 0) in_current_assetportfolio = 0;
			if(strcmp(buffer, "prescribed_assetportfolio") == 0) in_prescribed_assetportfolio = 1;
			if(strcmp(buffer, "/prescribed_assetportfolio") == 0) in_prescribed_assetportfolio = 0;
			if(strcmp(buffer, "nr_selected_rule") == 0) in_nr_selected_rule = 1;
			if(strcmp(buffer, "/nr_selected_rule") == 0) in_nr_selected_rule = 0;
			if(strcmp(buffer, "current_rule_performance") == 0) in_current_rule_performance = 1;
			if(strcmp(buffer, "/current_rule_performance") == 0) in_current_rule_performance = 0;
			if(strcmp(buffer, "EWA_rho") == 0) in_EWA_rho = 1;
			if(strcmp(buffer, "/EWA_rho") == 0) in_EWA_rho = 0;
			if(strcmp(buffer, "EWA_phi") == 0) in_EWA_phi = 1;
			if(strcmp(buffer, "/EWA_phi") == 0) in_EWA_phi = 0;
			if(strcmp(buffer, "EWA_delta") == 0) in_EWA_delta = 1;
			if(strcmp(buffer, "/EWA_delta") == 0) in_EWA_delta = 0;
			if(strcmp(buffer, "EWA_beta") == 0) in_EWA_beta = 1;
			if(strcmp(buffer, "/EWA_beta") == 0) in_EWA_beta = 0;
			if(strcmp(buffer, "prescribed_asset_value") == 0) in_prescribed_asset_value = 1;
			if(strcmp(buffer, "/prescribed_asset_value") == 0) in_prescribed_asset_value = 0;
			if(strcmp(buffer, "iradius") == 0) in_iradius = 1;
			if(strcmp(buffer, "/iradius") == 0) in_iradius = 0;
			if(strcmp(buffer, "posx") == 0) in_posx = 1;
			if(strcmp(buffer, "/posx") == 0) in_posx = 0;
			if(strcmp(buffer, "posy") == 0) in_posy = 1;
			if(strcmp(buffer, "/posy") == 0) in_posy = 0;
			if(strcmp(buffer, "revenues") == 0) in_revenues = 1;
			if(strcmp(buffer, "/revenues") == 0) in_revenues = 0;
			if(strcmp(buffer, "sales_costs") == 0) in_sales_costs = 1;
			if(strcmp(buffer, "/sales_costs") == 0) in_sales_costs = 0;
			if(strcmp(buffer, "total_revenue") == 0) in_total_revenue = 1;
			if(strcmp(buffer, "/total_revenue") == 0) in_total_revenue = 0;
			if(strcmp(buffer, "net_revenue") == 0) in_net_revenue = 1;
			if(strcmp(buffer, "/net_revenue") == 0) in_net_revenue = 0;
			if(strcmp(buffer, "operational_cost") == 0) in_operational_cost = 1;
			if(strcmp(buffer, "/operational_cost") == 0) in_operational_cost = 0;
			if(strcmp(buffer, "total_wage_payments") == 0) in_total_wage_payments = 1;
			if(strcmp(buffer, "/total_wage_payments") == 0) in_total_wage_payments = 0;
			if(strcmp(buffer, "total_input_payments") == 0) in_total_input_payments = 1;
			if(strcmp(buffer, "/total_input_payments") == 0) in_total_input_payments = 0;
			if(strcmp(buffer, "interest_payments") == 0) in_interest_payments = 1;
			if(strcmp(buffer, "/interest_payments") == 0) in_interest_payments = 0;
			if(strcmp(buffer, "total_earnings") == 0) in_total_earnings = 1;
			if(strcmp(buffer, "/total_earnings") == 0) in_total_earnings = 0;
			if(strcmp(buffer, "tax_rate_profits") == 0) in_tax_rate_profits = 1;
			if(strcmp(buffer, "/tax_rate_profits") == 0) in_tax_rate_profits = 0;
			if(strcmp(buffer, "pretax_profit") == 0) in_pretax_profit = 1;
			if(strcmp(buffer, "/pretax_profit") == 0) in_pretax_profit = 0;
			if(strcmp(buffer, "tax_provision") == 0) in_tax_provision = 1;
			if(strcmp(buffer, "/tax_provision") == 0) in_tax_provision = 0;
			if(strcmp(buffer, "net_earnings") == 0) in_net_earnings = 1;
			if(strcmp(buffer, "/net_earnings") == 0) in_net_earnings = 0;
			if(strcmp(buffer, "div_payments") == 0) in_div_payments = 1;
			if(strcmp(buffer, "/div_payments") == 0) in_div_payments = 0;
			if(strcmp(buffer, "retained_earnings") == 0) in_retained_earnings = 1;
			if(strcmp(buffer, "/retained_earnings") == 0) in_retained_earnings = 0;
			if(strcmp(buffer, "current_debt") == 0) in_current_debt = 1;
			if(strcmp(buffer, "/current_debt") == 0) in_current_debt = 0;
			if(strcmp(buffer, "debt_interest_rate") == 0) in_debt_interest_rate = 1;
			if(strcmp(buffer, "/debt_interest_rate") == 0) in_debt_interest_rate = 0;
			if(strcmp(buffer, "debt_repayments") == 0) in_debt_repayments = 1;
			if(strcmp(buffer, "/debt_repayments") == 0) in_debt_repayments = 0;
			if(strcmp(buffer, "share_repurchase_value") == 0) in_share_repurchase_value = 1;
			if(strcmp(buffer, "/share_repurchase_value") == 0) in_share_repurchase_value = 0;
			if(strcmp(buffer, "share_repurchase_units") == 0) in_share_repurchase_units = 1;
			if(strcmp(buffer, "/share_repurchase_units") == 0) in_share_repurchase_units = 0;
			if(strcmp(buffer, "target_total_shares") == 0) in_target_total_shares = 1;
			if(strcmp(buffer, "/target_total_shares") == 0) in_target_total_shares = 0;
			if(strcmp(buffer, "current_total_shares") == 0) in_current_total_shares = 1;
			if(strcmp(buffer, "/current_total_shares") == 0) in_current_total_shares = 0;
			if(strcmp(buffer, "total_financial_needs") == 0) in_total_financial_needs = 1;
			if(strcmp(buffer, "/total_financial_needs") == 0) in_total_financial_needs = 0;
			if(strcmp(buffer, "financial_needs") == 0) in_financial_needs = 1;
			if(strcmp(buffer, "/financial_needs") == 0) in_financial_needs = 0;
			if(strcmp(buffer, "add_financial_needs") == 0) in_add_financial_needs = 1;
			if(strcmp(buffer, "/add_financial_needs") == 0) in_add_financial_needs = 0;
			if(strcmp(buffer, "financial_reserves") == 0) in_financial_reserves = 1;
			if(strcmp(buffer, "/financial_reserves") == 0) in_financial_reserves = 0;
			if(strcmp(buffer, "target_loans") == 0) in_target_loans = 1;
			if(strcmp(buffer, "/target_loans") == 0) in_target_loans = 0;
			if(strcmp(buffer, "target_equity") == 0) in_target_equity = 1;
			if(strcmp(buffer, "/target_equity") == 0) in_target_equity = 0;
			if(strcmp(buffer, "bonds_issue_target") == 0) in_bonds_issue_target = 1;
			if(strcmp(buffer, "/bonds_issue_target") == 0) in_bonds_issue_target = 0;
			if(strcmp(buffer, "stocks_issue_target") == 0) in_stocks_issue_target = 1;
			if(strcmp(buffer, "/stocks_issue_target") == 0) in_stocks_issue_target = 0;
			if(strcmp(buffer, "price") == 0) in_price = 1;
			if(strcmp(buffer, "/price") == 0) in_price = 0;
			if(strcmp(buffer, "max_debt") == 0) in_max_debt = 1;
			if(strcmp(buffer, "/max_debt") == 0) in_max_debt = 0;
			if(strcmp(buffer, "div_earn_ratio") == 0) in_div_earn_ratio = 1;
			if(strcmp(buffer, "/div_earn_ratio") == 0) in_div_earn_ratio = 0;
			if(strcmp(buffer, "debt_earn_ratio") == 0) in_debt_earn_ratio = 1;
			if(strcmp(buffer, "/debt_earn_ratio") == 0) in_debt_earn_ratio = 0;
			if(strcmp(buffer, "div_pshare_ratio") == 0) in_div_pshare_ratio = 1;
			if(strcmp(buffer, "/div_pshare_ratio") == 0) in_div_pshare_ratio = 0;
			if(strcmp(buffer, "earn_pshare_ratio") == 0) in_earn_pshare_ratio = 1;
			if(strcmp(buffer, "/earn_pshare_ratio") == 0) in_earn_pshare_ratio = 0;
			if(strcmp(buffer, "price_earn_ratio") == 0) in_price_earn_ratio = 1;
			if(strcmp(buffer, "/price_earn_ratio") == 0) in_price_earn_ratio = 0;
			if(strcmp(buffer, "retained_earn_ratio") == 0) in_retained_earn_ratio = 1;
			if(strcmp(buffer, "/retained_earn_ratio") == 0) in_retained_earn_ratio = 0;
			if(strcmp(buffer, "earn_pshare_ratio_growth") == 0) in_earn_pshare_ratio_growth = 1;
			if(strcmp(buffer, "/earn_pshare_ratio_growth") == 0) in_earn_pshare_ratio_growth = 0;
			if(strcmp(buffer, "critical_price_earn_ratio") == 0) in_critical_price_earn_ratio = 1;
			if(strcmp(buffer, "/critical_price_earn_ratio") == 0) in_critical_price_earn_ratio = 0;
			if(strcmp(buffer, "critical_earn_pshare_ratio") == 0) in_critical_earn_pshare_ratio = 1;
			if(strcmp(buffer, "/critical_earn_pshare_ratio") == 0) in_critical_earn_pshare_ratio = 0;
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "re") == 0) in_re = 1;
			if(strcmp(buffer, "/re") == 0) in_re = 0;
			if(strcmp(buffer, "rj") == 0) in_rj = 1;
			if(strcmp(buffer, "/rj") == 0) in_rj = 0;
			if(strcmp(buffer, "central_classifiersystem") == 0) in_central_classifiersystem = 1;
			if(strcmp(buffer, "/central_classifiersystem") == 0) in_central_classifiersystem = 0;


			
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
				if(in_household_id) household_id = atoi(buffer);
				if(in_agent_classifiersystem)
				{
					j = 0;
					agent_classifiersystem = (PrivateClassifierSystem *)malloc(sizeof(PrivateClassifierSystem));
					CHECK_POINTER(ids);
					agent_classifiersystem->ids = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					agent_classifiersystem->ids = atoi(arraydata);
					CHECK_POINTER(experience);
					agent_classifiersystem->experience = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					agent_classifiersystem->experience = atof(arraydata);
					CHECK_POINTER(current_rule);
					agent_classifiersystem->current_rule = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					agent_classifiersystem->current_rule = atoi(arraydata);
					CHECK_POINTER(my_performance);
					agent_classifiersystem->my_performance = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					agent_classifiersystem->my_performance = atof(arraydata);
					CHECK_POINTER(avgperformance);
					agent_classifiersystem->avgperformance = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					agent_classifiersystem->avgperformance = atof(arraydata);
					CHECK_POINTER(attraction);
					agent_classifiersystem->attraction = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					agent_classifiersystem->attraction = atof(arraydata);
					CHECK_POINTER(choiceprob);
					agent_classifiersystem->choiceprob = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					agent_classifiersystem->choiceprob = atof(arraydata);
					CHECK_POINTER(nr_selected_rule);
					agent_classifiersystem->nr_selected_rule = 0;
					array_k = 0;
					j++;
					while(buffer[j] != '}')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					agent_classifiersystem->nr_selected_rule = atoi(arraydata);
				}
				if(in_asset_budget) asset_budget = atof(buffer);
				if(in_current_assetportfolio)
				{
					j = 0;
					current_assetportfolio = (AssetPortfolioType *)malloc(sizeof(AssetPortfolioType));
					CHECK_POINTER(performance_history);
					current_assetportfolio->performance_history = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->performance_history = atoi(arraydata);
					CHECK_POINTER(firmstocks);
					current_assetportfolio->firmstocks = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->firmstocks = atoi(arraydata);
					CHECK_POINTER(firm_id);
					current_assetportfolio->firm_id = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->firm_id = atoi(arraydata);
					CHECK_POINTER(current_price);
					current_assetportfolio->current_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->current_price = atof(arraydata);
					CHECK_POINTER(best_ask_price);
					current_assetportfolio->best_ask_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->best_ask_price = atof(arraydata);
					CHECK_POINTER(best_bid_price);
					current_assetportfolio->best_bid_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->best_bid_price = atof(arraydata);
					CHECK_POINTER(nr_units);
					current_assetportfolio->nr_units = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->nr_units = atof(arraydata);
					CHECK_POINTER(firmbonds);
					current_assetportfolio->firmbonds = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->firmbonds = atoi(arraydata);
					CHECK_POINTER(firmbonds_firm_id);
					current_assetportfolio->firmbonds_firm_id = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->firmbonds_firm_id = atoi(arraydata);
					CHECK_POINTER(firmbonds_current_price);
					current_assetportfolio->firmbonds_current_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->firmbonds_current_price = atof(arraydata);
					CHECK_POINTER(firmbonds_best_ask_price);
					current_assetportfolio->firmbonds_best_ask_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->firmbonds_best_ask_price = atof(arraydata);
					CHECK_POINTER(firmbonds_best_bid_price);
					current_assetportfolio->firmbonds_best_bid_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->firmbonds_best_bid_price = atof(arraydata);
					CHECK_POINTER(firmbonds_nr_units);
					current_assetportfolio->firmbonds_nr_units = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->firmbonds_nr_units = atof(arraydata);
					CHECK_POINTER(govbonds);
					current_assetportfolio->govbonds = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->govbonds = atoi(arraydata);
					CHECK_POINTER(govbonds_gov_id);
					current_assetportfolio->govbonds_gov_id = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->govbonds_gov_id = atoi(arraydata);
					CHECK_POINTER(govbonds_current_price);
					current_assetportfolio->govbonds_current_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->govbonds_current_price = atof(arraydata);
					CHECK_POINTER(govbonds_best_ask_price);
					current_assetportfolio->govbonds_best_ask_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->govbonds_best_ask_price = atof(arraydata);
					CHECK_POINTER(govbonds_best_bid_price);
					current_assetportfolio->govbonds_best_bid_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->govbonds_best_bid_price = atof(arraydata);
					CHECK_POINTER(govbonds_nr_units);
					current_assetportfolio->govbonds_nr_units = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != '}')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					current_assetportfolio->govbonds_nr_units = atof(arraydata);
				}
				if(in_prescribed_assetportfolio)
				{
					j = 0;
					prescribed_assetportfolio = (AssetPortfolioType *)malloc(sizeof(AssetPortfolioType));
					CHECK_POINTER(performance_history);
					prescribed_assetportfolio->performance_history = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->performance_history = atoi(arraydata);
					CHECK_POINTER(firmstocks);
					prescribed_assetportfolio->firmstocks = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->firmstocks = atoi(arraydata);
					CHECK_POINTER(firm_id);
					prescribed_assetportfolio->firm_id = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->firm_id = atoi(arraydata);
					CHECK_POINTER(current_price);
					prescribed_assetportfolio->current_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->current_price = atof(arraydata);
					CHECK_POINTER(best_ask_price);
					prescribed_assetportfolio->best_ask_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->best_ask_price = atof(arraydata);
					CHECK_POINTER(best_bid_price);
					prescribed_assetportfolio->best_bid_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->best_bid_price = atof(arraydata);
					CHECK_POINTER(nr_units);
					prescribed_assetportfolio->nr_units = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->nr_units = atof(arraydata);
					CHECK_POINTER(firmbonds);
					prescribed_assetportfolio->firmbonds = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->firmbonds = atoi(arraydata);
					CHECK_POINTER(firmbonds_firm_id);
					prescribed_assetportfolio->firmbonds_firm_id = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->firmbonds_firm_id = atoi(arraydata);
					CHECK_POINTER(firmbonds_current_price);
					prescribed_assetportfolio->firmbonds_current_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->firmbonds_current_price = atof(arraydata);
					CHECK_POINTER(firmbonds_best_ask_price);
					prescribed_assetportfolio->firmbonds_best_ask_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->firmbonds_best_ask_price = atof(arraydata);
					CHECK_POINTER(firmbonds_best_bid_price);
					prescribed_assetportfolio->firmbonds_best_bid_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->firmbonds_best_bid_price = atof(arraydata);
					CHECK_POINTER(firmbonds_nr_units);
					prescribed_assetportfolio->firmbonds_nr_units = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->firmbonds_nr_units = atof(arraydata);
					CHECK_POINTER(govbonds);
					prescribed_assetportfolio->govbonds = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->govbonds = atoi(arraydata);
					CHECK_POINTER(govbonds_gov_id);
					prescribed_assetportfolio->govbonds_gov_id = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->govbonds_gov_id = atoi(arraydata);
					CHECK_POINTER(govbonds_current_price);
					prescribed_assetportfolio->govbonds_current_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->govbonds_current_price = atof(arraydata);
					CHECK_POINTER(govbonds_best_ask_price);
					prescribed_assetportfolio->govbonds_best_ask_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->govbonds_best_ask_price = atof(arraydata);
					CHECK_POINTER(govbonds_best_bid_price);
					prescribed_assetportfolio->govbonds_best_bid_price = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->govbonds_best_bid_price = atof(arraydata);
					CHECK_POINTER(govbonds_nr_units);
					prescribed_assetportfolio->govbonds_nr_units = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != '}')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					prescribed_assetportfolio->govbonds_nr_units = atof(arraydata);
				}
				if(in_nr_selected_rule) nr_selected_rule = atoi(buffer);
				if(in_current_rule_performance) current_rule_performance = atof(buffer);
				if(in_EWA_rho) EWA_rho = atof(buffer);
				if(in_EWA_phi) EWA_phi = atof(buffer);
				if(in_EWA_delta) EWA_delta = atof(buffer);
				if(in_EWA_beta) EWA_beta = atof(buffer);
				if(in_prescribed_asset_value) prescribed_asset_value = atof(buffer);
				if(in_iradius) iradius = atof(buffer);
				if(in_posx) posx = atof(buffer);
				if(in_posy) posy = atof(buffer);
				if(in_revenues)
				{
					j = 1;
					arraycount = 0;
					revenues = init_double_array();
					while(buffer[j] != '}')
					{
						array_k = 0;
						while(buffer[j] != ',' && buffer[j] != '}')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						add_double(revenues, atof(arraydata));
						arraycount++;
						if(buffer[j] != '}') j++;
					}
				}
				if(in_sales_costs)
				{
					j = 1;
					arraycount = 0;
					sales_costs = init_double_array();
					while(buffer[j] != '}')
					{
						array_k = 0;
						while(buffer[j] != ',' && buffer[j] != '}')
						{
							arraydata[array_k] = buffer[j];
							array_k++;
							j++;
						}
						arraydata[array_k] = 0;
						add_double(sales_costs, atof(arraydata));
						arraycount++;
						if(buffer[j] != '}') j++;
					}
				}
				if(in_total_revenue) total_revenue = atof(buffer);
				if(in_net_revenue) net_revenue = atof(buffer);
				if(in_operational_cost) operational_cost = atof(buffer);
				if(in_total_wage_payments) total_wage_payments = atof(buffer);
				if(in_total_input_payments) total_input_payments = atof(buffer);
				if(in_interest_payments) interest_payments = atof(buffer);
				if(in_total_earnings) total_earnings = atof(buffer);
				if(in_tax_rate_profits) tax_rate_profits = atof(buffer);
				if(in_pretax_profit) pretax_profit = atof(buffer);
				if(in_tax_provision) tax_provision = atof(buffer);
				if(in_net_earnings) net_earnings = atof(buffer);
				if(in_div_payments) div_payments = atof(buffer);
				if(in_retained_earnings) retained_earnings = atof(buffer);
				if(in_current_debt) current_debt = atof(buffer);
				if(in_debt_interest_rate) debt_interest_rate = atof(buffer);
				if(in_debt_repayments) debt_repayments = atof(buffer);
				if(in_share_repurchase_value) share_repurchase_value = atof(buffer);
				if(in_share_repurchase_units) share_repurchase_units = atoi(buffer);
				if(in_target_total_shares) target_total_shares = atoi(buffer);
				if(in_current_total_shares) current_total_shares = atoi(buffer);
				if(in_total_financial_needs) total_financial_needs = atof(buffer);
				if(in_financial_needs) financial_needs = atof(buffer);
				if(in_add_financial_needs) add_financial_needs = atof(buffer);
				if(in_financial_reserves) financial_reserves = atof(buffer);
				if(in_target_loans) target_loans = atof(buffer);
				if(in_target_equity) target_equity = atof(buffer);
				if(in_bonds_issue_target) bonds_issue_target = atof(buffer);
				if(in_stocks_issue_target) stocks_issue_target = atof(buffer);
				if(in_price) price = atof(buffer);
				if(in_max_debt) max_debt = atof(buffer);
				if(in_div_earn_ratio) div_earn_ratio = atof(buffer);
				if(in_debt_earn_ratio) debt_earn_ratio = atof(buffer);
				if(in_div_pshare_ratio) div_pshare_ratio = atof(buffer);
				if(in_earn_pshare_ratio) earn_pshare_ratio = atof(buffer);
				if(in_price_earn_ratio) price_earn_ratio = atof(buffer);
				if(in_retained_earn_ratio) retained_earn_ratio = atof(buffer);
				if(in_earn_pshare_ratio_growth) earn_pshare_ratio_growth = atof(buffer);
				if(in_critical_price_earn_ratio) critical_price_earn_ratio = atof(buffer);
				if(in_critical_earn_pshare_ratio) critical_earn_pshare_ratio = atof(buffer);
				if(in_id) id = atoi(buffer);
				if(in_re) re = atof(buffer);
				if(in_rj) rj = atof(buffer);
				if(in_central_classifiersystem)
				{
					j = 0;
					central_classifiersystem = (PublicClassifierSystem *)malloc(sizeof(PublicClassifierSystem));
					CHECK_POINTER(counter);
					central_classifiersystem->counter = 0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					central_classifiersystem->counter = atoi(arraydata);
					CHECK_POINTER(performance);
					central_classifiersystem->performance = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					central_classifiersystem->performance = atof(arraydata);
					CHECK_POINTER(avgperformance);
					central_classifiersystem->avgperformance = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != ',')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					central_classifiersystem->avgperformance = atof(arraydata);
					CHECK_POINTER(performance_history);
					central_classifiersystem->performance_history = 0.0;
					array_k = 0;
					j++;
					while(buffer[j] != '}')
					{
						arraydata[array_k] = buffer[j];
						array_k++;
						j++;
					}
					arraydata[array_k] = 0;
					central_classifiersystem->performance_history = atof(arraydata);
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
	xmachine_memory_Household * current_Household;
	xmachine_memory_Firm * current_Firm;
	xmachine_memory_Bank * current_Bank;
	xmachine_memory_ClearingHouseMechanism * current_ClearingHouseMechanism;
	xmachine_memory_LimitOrderBook * current_LimitOrderBook;
	xmachine_memory_Government * current_Government;
	xmachine_memory_FinancialAdvisor * current_FinancialAdvisor;

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
		if(current_xmachine->xmachine_Household != NULL)
		{
			current_Household = current_xmachine->xmachine_Household;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Firm != NULL)
		{
			current_Firm = current_xmachine->xmachine_Firm;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			current_Bank = current_xmachine->xmachine_Bank;
			agentcount++;
		}
		else if(current_xmachine->xmachine_ClearingHouseMechanism != NULL)
		{
			current_ClearingHouseMechanism = current_xmachine->xmachine_ClearingHouseMechanism;
			agentcount++;
		}
		else if(current_xmachine->xmachine_LimitOrderBook != NULL)
		{
			current_LimitOrderBook = current_xmachine->xmachine_LimitOrderBook;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Government != NULL)
		{
			current_Government = current_xmachine->xmachine_Government;
			agentcount++;
		}
		else if(current_xmachine->xmachine_FinancialAdvisor != NULL)
		{
			current_FinancialAdvisor = current_xmachine->xmachine_FinancialAdvisor;
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
	xmachine_memory_Household * current_Household;
	xmachine_memory_Firm * current_Firm;
	xmachine_memory_Bank * current_Bank;
	xmachine_memory_ClearingHouseMechanism * current_ClearingHouseMechanism;
	xmachine_memory_LimitOrderBook * current_LimitOrderBook;
	xmachine_memory_Government * current_Government;
	xmachine_memory_FinancialAdvisor * current_FinancialAdvisor;
	//double_array * revenues;
	//double_array * sales_costs;
	
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
		if(current_xmachine->xmachine_Household != NULL)
		{
			current_Household = current_xmachine->xmachine_Household;
			fputs("<name>Household</name>\n", file);
			fputs("<household_id>", file);
			sprintf(data, "%i", current_Household->household_id);
			fputs(data, file);
			fputs("</household_id>\n", file);
			fputs("<agent_classifiersystem>", file);
			fputs("{", file);
			sprintf(data, "%i", current_Household->agent_classifiersystem->ids);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->agent_classifiersystem->experience);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->agent_classifiersystem->current_rule);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->agent_classifiersystem->my_performance);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->agent_classifiersystem->avgperformance);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->agent_classifiersystem->attraction);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->agent_classifiersystem->choiceprob);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->agent_classifiersystem->nr_selected_rule);
			fputs(data, file);
			fputs("}", file);
			fputs("</agent_classifiersystem>\n", file);
			fputs("<asset_budget>", file);
			sprintf(data, "%f", current_Household->asset_budget);
			fputs(data, file);
			fputs("</asset_budget>\n", file);
			fputs("<current_assetportfolio>", file);
			fputs("{", file);
			sprintf(data, "%i", current_Household->current_assetportfolio->performance_history);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->current_assetportfolio->firmstocks);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->current_assetportfolio->firm_id);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->current_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->best_ask_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->best_bid_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->nr_units);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->current_assetportfolio->firmbonds);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->current_assetportfolio->firmbonds_firm_id);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->firmbonds_current_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->firmbonds_best_ask_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->firmbonds_best_bid_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->firmbonds_nr_units);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->current_assetportfolio->govbonds);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->current_assetportfolio->govbonds_gov_id);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->govbonds_current_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->govbonds_best_ask_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->govbonds_best_bid_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->current_assetportfolio->govbonds_nr_units);
			fputs(data, file);
			fputs("}", file);
			fputs("</current_assetportfolio>\n", file);
			fputs("<prescribed_assetportfolio>", file);
			fputs("{", file);
			sprintf(data, "%i", current_Household->prescribed_assetportfolio->performance_history);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->prescribed_assetportfolio->firmstocks);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->prescribed_assetportfolio->firm_id);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->current_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->best_ask_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->best_bid_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->nr_units);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->prescribed_assetportfolio->firmbonds);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->prescribed_assetportfolio->firmbonds_firm_id);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->firmbonds_current_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->firmbonds_best_ask_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->firmbonds_best_bid_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->firmbonds_nr_units);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->prescribed_assetportfolio->govbonds);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%i", current_Household->prescribed_assetportfolio->govbonds_gov_id);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->govbonds_current_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->govbonds_best_ask_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->govbonds_best_bid_price);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_Household->prescribed_assetportfolio->govbonds_nr_units);
			fputs(data, file);
			fputs("}", file);
			fputs("</prescribed_assetportfolio>\n", file);
			fputs("<nr_selected_rule>", file);
			sprintf(data, "%i", current_Household->nr_selected_rule);
			fputs(data, file);
			fputs("</nr_selected_rule>\n", file);
			fputs("<current_rule_performance>", file);
			sprintf(data, "%f", current_Household->current_rule_performance);
			fputs(data, file);
			fputs("</current_rule_performance>\n", file);
			fputs("<EWA_rho>", file);
			sprintf(data, "%f", current_Household->EWA_rho);
			fputs(data, file);
			fputs("</EWA_rho>\n", file);
			fputs("<EWA_phi>", file);
			sprintf(data, "%f", current_Household->EWA_phi);
			fputs(data, file);
			fputs("</EWA_phi>\n", file);
			fputs("<EWA_delta>", file);
			sprintf(data, "%f", current_Household->EWA_delta);
			fputs(data, file);
			fputs("</EWA_delta>\n", file);
			fputs("<EWA_beta>", file);
			sprintf(data, "%f", current_Household->EWA_beta);
			fputs(data, file);
			fputs("</EWA_beta>\n", file);
			fputs("<prescribed_asset_value>", file);
			sprintf(data, "%f", current_Household->prescribed_asset_value);
			fputs(data, file);
			fputs("</prescribed_asset_value>\n", file);
			fputs("<asset_budget>", file);
			sprintf(data, "%f", current_Household->asset_budget);
			fputs(data, file);
			fputs("</asset_budget>\n", file);
			fputs("<iradius>", file);
			sprintf(data, "%f", current_Household->iradius);
			fputs(data, file);
			fputs("</iradius>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Household->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Household->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Firm != NULL)
		{
			current_Firm = current_xmachine->xmachine_Firm;
			fputs("<name>Firm</name>\n", file);
			fputs("<revenues>", file);
			//revenues = current_Firm->revenues;
			fputs("{", file);
			for(i=0; i<current_Firm->revenues->size; i++)
			{
				sprintf(data, "%f", current_Firm->revenues->array[i]);
				fputs(data, file);
				
				if(i < (current_Firm->revenues->size-1)) fputs(", ", file);
			}
			fputs("}", file);
			fputs("</revenues>\n", file);
			fputs("<sales_costs>", file);
			//sales_costs = current_Firm->sales_costs;
			fputs("{", file);
			for(i=0; i<current_Firm->sales_costs->size; i++)
			{
				sprintf(data, "%f", current_Firm->sales_costs->array[i]);
				fputs(data, file);
				
				if(i < (current_Firm->sales_costs->size-1)) fputs(", ", file);
			}
			fputs("}", file);
			fputs("</sales_costs>\n", file);
			fputs("<total_revenue>", file);
			sprintf(data, "%f", current_Firm->total_revenue);
			fputs(data, file);
			fputs("</total_revenue>\n", file);
			fputs("<net_revenue>", file);
			sprintf(data, "%f", current_Firm->net_revenue);
			fputs(data, file);
			fputs("</net_revenue>\n", file);
			fputs("<operational_cost>", file);
			sprintf(data, "%f", current_Firm->operational_cost);
			fputs(data, file);
			fputs("</operational_cost>\n", file);
			fputs("<total_wage_payments>", file);
			sprintf(data, "%f", current_Firm->total_wage_payments);
			fputs(data, file);
			fputs("</total_wage_payments>\n", file);
			fputs("<total_input_payments>", file);
			sprintf(data, "%f", current_Firm->total_input_payments);
			fputs(data, file);
			fputs("</total_input_payments>\n", file);
			fputs("<interest_payments>", file);
			sprintf(data, "%f", current_Firm->interest_payments);
			fputs(data, file);
			fputs("</interest_payments>\n", file);
			fputs("<total_earnings>", file);
			sprintf(data, "%f", current_Firm->total_earnings);
			fputs(data, file);
			fputs("</total_earnings>\n", file);
			fputs("<tax_rate_profits>", file);
			sprintf(data, "%f", current_Firm->tax_rate_profits);
			fputs(data, file);
			fputs("</tax_rate_profits>\n", file);
			fputs("<pretax_profit>", file);
			sprintf(data, "%f", current_Firm->pretax_profit);
			fputs(data, file);
			fputs("</pretax_profit>\n", file);
			fputs("<tax_provision>", file);
			sprintf(data, "%f", current_Firm->tax_provision);
			fputs(data, file);
			fputs("</tax_provision>\n", file);
			fputs("<net_earnings>", file);
			sprintf(data, "%f", current_Firm->net_earnings);
			fputs(data, file);
			fputs("</net_earnings>\n", file);
			fputs("<div_payments>", file);
			sprintf(data, "%f", current_Firm->div_payments);
			fputs(data, file);
			fputs("</div_payments>\n", file);
			fputs("<retained_earnings>", file);
			sprintf(data, "%f", current_Firm->retained_earnings);
			fputs(data, file);
			fputs("</retained_earnings>\n", file);
			fputs("<current_debt>", file);
			sprintf(data, "%f", current_Firm->current_debt);
			fputs(data, file);
			fputs("</current_debt>\n", file);
			fputs("<debt_interest_rate>", file);
			sprintf(data, "%f", current_Firm->debt_interest_rate);
			fputs(data, file);
			fputs("</debt_interest_rate>\n", file);
			fputs("<debt_repayments>", file);
			sprintf(data, "%f", current_Firm->debt_repayments);
			fputs(data, file);
			fputs("</debt_repayments>\n", file);
			fputs("<share_repurchase_value>", file);
			sprintf(data, "%f", current_Firm->share_repurchase_value);
			fputs(data, file);
			fputs("</share_repurchase_value>\n", file);
			fputs("<share_repurchase_units>", file);
			sprintf(data, "%i", current_Firm->share_repurchase_units);
			fputs(data, file);
			fputs("</share_repurchase_units>\n", file);
			fputs("<target_total_shares>", file);
			sprintf(data, "%i", current_Firm->target_total_shares);
			fputs(data, file);
			fputs("</target_total_shares>\n", file);
			fputs("<current_total_shares>", file);
			sprintf(data, "%i", current_Firm->current_total_shares);
			fputs(data, file);
			fputs("</current_total_shares>\n", file);
			fputs("<total_financial_needs>", file);
			sprintf(data, "%f", current_Firm->total_financial_needs);
			fputs(data, file);
			fputs("</total_financial_needs>\n", file);
			fputs("<financial_needs>", file);
			sprintf(data, "%f", current_Firm->financial_needs);
			fputs(data, file);
			fputs("</financial_needs>\n", file);
			fputs("<add_financial_needs>", file);
			sprintf(data, "%f", current_Firm->add_financial_needs);
			fputs(data, file);
			fputs("</add_financial_needs>\n", file);
			fputs("<financial_reserves>", file);
			sprintf(data, "%f", current_Firm->financial_reserves);
			fputs(data, file);
			fputs("</financial_reserves>\n", file);
			fputs("<target_loans>", file);
			sprintf(data, "%f", current_Firm->target_loans);
			fputs(data, file);
			fputs("</target_loans>\n", file);
			fputs("<target_equity>", file);
			sprintf(data, "%f", current_Firm->target_equity);
			fputs(data, file);
			fputs("</target_equity>\n", file);
			fputs("<bonds_issue_target>", file);
			sprintf(data, "%f", current_Firm->bonds_issue_target);
			fputs(data, file);
			fputs("</bonds_issue_target>\n", file);
			fputs("<stocks_issue_target>", file);
			sprintf(data, "%f", current_Firm->stocks_issue_target);
			fputs(data, file);
			fputs("</stocks_issue_target>\n", file);
			fputs("<price>", file);
			sprintf(data, "%f", current_Firm->price);
			fputs(data, file);
			fputs("</price>\n", file);
			fputs("<max_debt>", file);
			sprintf(data, "%f", current_Firm->max_debt);
			fputs(data, file);
			fputs("</max_debt>\n", file);
			fputs("<div_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->div_earn_ratio);
			fputs(data, file);
			fputs("</div_earn_ratio>\n", file);
			fputs("<debt_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->debt_earn_ratio);
			fputs(data, file);
			fputs("</debt_earn_ratio>\n", file);
			fputs("<div_pshare_ratio>", file);
			sprintf(data, "%f", current_Firm->div_pshare_ratio);
			fputs(data, file);
			fputs("</div_pshare_ratio>\n", file);
			fputs("<earn_pshare_ratio>", file);
			sprintf(data, "%f", current_Firm->earn_pshare_ratio);
			fputs(data, file);
			fputs("</earn_pshare_ratio>\n", file);
			fputs("<price_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->price_earn_ratio);
			fputs(data, file);
			fputs("</price_earn_ratio>\n", file);
			fputs("<retained_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->retained_earn_ratio);
			fputs(data, file);
			fputs("</retained_earn_ratio>\n", file);
			fputs("<earn_pshare_ratio_growth>", file);
			sprintf(data, "%f", current_Firm->earn_pshare_ratio_growth);
			fputs(data, file);
			fputs("</earn_pshare_ratio_growth>\n", file);
			fputs("<critical_price_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->critical_price_earn_ratio);
			fputs(data, file);
			fputs("</critical_price_earn_ratio>\n", file);
			fputs("<critical_earn_pshare_ratio>", file);
			sprintf(data, "%f", current_Firm->critical_earn_pshare_ratio);
			fputs(data, file);
			fputs("</critical_earn_pshare_ratio>\n", file);
			fputs("<iradius>", file);
			sprintf(data, "%f", current_Firm->iradius);
			fputs(data, file);
			fputs("</iradius>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Firm->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Firm->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			current_Bank = current_xmachine->xmachine_Bank;
			fputs("<name>Bank</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Bank->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<iradius>", file);
			sprintf(data, "%f", current_Bank->iradius);
			fputs(data, file);
			fputs("</iradius>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Bank->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Bank->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_ClearingHouseMechanism != NULL)
		{
			current_ClearingHouseMechanism = current_xmachine->xmachine_ClearingHouseMechanism;
			fputs("<name>ClearingHouseMechanism</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_ClearingHouseMechanism->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<iradius>", file);
			sprintf(data, "%f", current_ClearingHouseMechanism->iradius);
			fputs(data, file);
			fputs("</iradius>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_ClearingHouseMechanism->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_ClearingHouseMechanism->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_LimitOrderBook != NULL)
		{
			current_LimitOrderBook = current_xmachine->xmachine_LimitOrderBook;
			fputs("<name>LimitOrderBook</name>\n", file);
			fputs("<re>", file);
			sprintf(data, "%f", current_LimitOrderBook->re);
			fputs(data, file);
			fputs("</re>\n", file);
			fputs("<iradius>", file);
			sprintf(data, "%f", current_LimitOrderBook->iradius);
			fputs(data, file);
			fputs("</iradius>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_LimitOrderBook->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_LimitOrderBook->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Government != NULL)
		{
			current_Government = current_xmachine->xmachine_Government;
			fputs("<name>Government</name>\n", file);
			fputs("<rj>", file);
			sprintf(data, "%f", current_Government->rj);
			fputs(data, file);
			fputs("</rj>\n", file);
			fputs("<iradius>", file);
			sprintf(data, "%f", current_Government->iradius);
			fputs(data, file);
			fputs("</iradius>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Government->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Government->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_FinancialAdvisor != NULL)
		{
			current_FinancialAdvisor = current_xmachine->xmachine_FinancialAdvisor;
			fputs("<name>FinancialAdvisor</name>\n", file);
			fputs("<central_classifiersystem>", file);
			fputs("{", file);
			sprintf(data, "%i", current_FinancialAdvisor->central_classifiersystem->counter);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_FinancialAdvisor->central_classifiersystem->performance);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_FinancialAdvisor->central_classifiersystem->avgperformance);
			fputs(data, file);
			fputs(", ", file);
			sprintf(data, "%f", current_FinancialAdvisor->central_classifiersystem->performance_history);
			fputs(data, file);
			fputs("}", file);
			fputs("</central_classifiersystem>\n", file);
			fputs("<iradius>", file);
			sprintf(data, "%f", current_FinancialAdvisor->iradius);
			fputs(data, file);
			fputs("</iradius>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_FinancialAdvisor->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_FinancialAdvisor->posy);
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
