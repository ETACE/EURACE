/* $Id$ */
/**
 * \file propagate_agents.c
 * \brief Propagate agents that require migration across nodes.
 *
 * \note  
 *       Modified version of propagate_agents(). Uses non-blocking 
 *       communication to avoid deadlocks, and customised buffering 
 *       strategies to reduce memory requirements. 
 *
 *       While not implemented here, routine can be easily split up into
 *       propagate_agents_init() and propagate_agents_complete() to allow
 *       for overlapping of computation with agent propagation.
 *
 *       Algorithm for moving agents from main list to outbound list has
 *       also been modified (simplified?) 
 */
 
 
#include "header.h"

/* ========== Declaration of required constants =================== */

/** Enumerated identifier for each agent type */
enum { \
    AGENT_Household, \
    AGENT_Firm, \
    AGENT_Bank, \
    AGENT_ClearingHouse, \
    AGENT_LimitOrderBook, \
    AGENT_Government, \
    AGENT_FinancialAgent, \
    AGENT_TYPE_COUNT
};

/** message tag used for propagating agents */
#define TAG 11



/* ========== Begin implementation code =========================== */

/** \fn void propagate_agents()
 * \brief Check agent positions and migrate agents that are to be moved to 
 *        different nodes.
 * 
 * \author LS Chin (CCLRC)
 * \date March 2007
 */
void propagate_agents() {

    /* ------------ Begin Variable declarations -------------- */

	int agent_type = 0;
    int remove_agent;
    int sender, outcount;
    int *agent_count_list;
    int probed, i, j, bufsize;
    node_information *node_info;
	xmachine *prev_xmachine, *next_xmachine;
	double x_xmachine = 0.0, y_xmachine = 0.0, z_xmachine = 0.0;
    
    
    /* variables used for MPI calls */
    MPI_Status  status;
    MPI_Request * in_req;
    MPI_Request * out_req;
    
    /* buffer space for packed agents from/to each PE */
    void ** inbuf;
    void ** outbuf;

    /* pointers to temporary agents */

    xmachine_memory_Household *agent_Household_list; 

    xmachine_memory_Firm *agent_Firm_list; 

    xmachine_memory_Bank *agent_Bank_list; 

    xmachine_memory_ClearingHouse *agent_ClearingHouse_list; 

    xmachine_memory_LimitOrderBook *agent_LimitOrderBook_list; 

    xmachine_memory_Government *agent_Government_list; 

    xmachine_memory_FinancialAgent *agent_FinancialAgent_list; 




    /* ---- determine which agents should be moved ---------------- */
    
    /* loop through agent list */
    prev_xmachine = NULL;
    remove_agent = 0;
    current_xmachine = current_node->agents;
    while(current_xmachine)
    {
        next_xmachine = current_xmachine->next;
        
        if(current_xmachine->xmachine_Household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Household->posx;
			y_xmachine = current_xmachine->xmachine_Household->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_Household;
		}
        
        else if(current_xmachine->xmachine_Firm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Firm->posx;
			y_xmachine = current_xmachine->xmachine_Firm->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_Firm;
		}
        
        else if(current_xmachine->xmachine_Bank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Bank->posx;
			y_xmachine = current_xmachine->xmachine_Bank->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_Bank;
		}
        
        else if(current_xmachine->xmachine_ClearingHouse != NULL)
		{
			x_xmachine = current_xmachine->xmachine_ClearingHouse->posx;
			y_xmachine = current_xmachine->xmachine_ClearingHouse->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_ClearingHouse;
		}
        
        else if(current_xmachine->xmachine_LimitOrderBook != NULL)
		{
			x_xmachine = current_xmachine->xmachine_LimitOrderBook->posx;
			y_xmachine = current_xmachine->xmachine_LimitOrderBook->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_LimitOrderBook;
		}
        
        else if(current_xmachine->xmachine_Government != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Government->posx;
			y_xmachine = current_xmachine->xmachine_Government->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_Government;
		}
        
        else if(current_xmachine->xmachine_FinancialAgent != NULL)
		{
			x_xmachine = current_xmachine->xmachine_FinancialAgent->posx;
			y_xmachine = current_xmachine->xmachine_FinancialAgent->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_FinancialAgent;
		}


        /* if any agent is located beyond our partition data, move it */
        if ( 
           x_xmachine < current_node->partition_data[0] ||
		   x_xmachine > current_node->partition_data[1] ||
		   y_xmachine < current_node->partition_data[2] ||
		   y_xmachine > current_node->partition_data[3] ||
		   z_xmachine < current_node->partition_data[4] ||
		   z_xmachine > current_node->partition_data[5] )
        {
            /* determine which node we should move agent to */
            
            /* loop through node list */
            node_info = *p_node_info;
            while(node_info)
            {
                if (node_info->node_id == node_number)
                { /* skip my own node */
                    node_info = node_info->next;
                    continue;
                }
                
                /* should agent be in this node? */
                if (
                    x_xmachine > node_info->partition_data[0] &&
                    x_xmachine < node_info->partition_data[1] &&
                    y_xmachine > node_info->partition_data[2] &&
		            y_xmachine < node_info->partition_data[3] &&
		            z_xmachine > node_info->partition_data[4] &&
		            z_xmachine < node_info->partition_data[5] )
                {
                    /* move agent to target node */

                    if (agent_type == AGENT_Household)
                    {
                        node_info->Household_agent_no ++;
                        current_xmachine->next = node_info->Household_agents;
                        node_info->Household_agents = current_xmachine;
                    }

                    else if (agent_type == AGENT_Firm)
                    {
                        node_info->Firm_agent_no ++;
                        current_xmachine->next = node_info->Firm_agents;
                        node_info->Firm_agents = current_xmachine;
                    }

                    else if (agent_type == AGENT_Bank)
                    {
                        node_info->Bank_agent_no ++;
                        current_xmachine->next = node_info->Bank_agents;
                        node_info->Bank_agents = current_xmachine;
                    }

                    else if (agent_type == AGENT_ClearingHouse)
                    {
                        node_info->ClearingHouse_agent_no ++;
                        current_xmachine->next = node_info->ClearingHouse_agents;
                        node_info->ClearingHouse_agents = current_xmachine;
                    }

                    else if (agent_type == AGENT_LimitOrderBook)
                    {
                        node_info->LimitOrderBook_agent_no ++;
                        current_xmachine->next = node_info->LimitOrderBook_agents;
                        node_info->LimitOrderBook_agents = current_xmachine;
                    }

                    else if (agent_type == AGENT_Government)
                    {
                        node_info->Government_agent_no ++;
                        current_xmachine->next = node_info->Government_agents;
                        node_info->Government_agents = current_xmachine;
                    }

                    else if (agent_type == AGENT_FinancialAgent)
                    {
                        node_info->FinancialAgent_agent_no ++;
                        current_xmachine->next = node_info->FinancialAgent_agents;
                        node_info->FinancialAgent_agents = current_xmachine;
                    }

                    
                    /* flag agent for removal from current node */
                    remove_agent = 1;
                    
                    /* no need to traverse the node list further */
                    node_info = NULL;
                }
                else
                {  /* continue searching */
                    node_info = node_info->next;
                }
            }   

        }

        /* remove agent from current node if necessary */
        if (remove_agent) 
        {
            remove_agent = 0; /* reset value */
            
            /* decrement agent count */
            current_node->agent_total --;
            
            /* if first agent is removed */
            if (prev_xmachine == NULL)
            {  
                current_node->agents = next_xmachine;
            }
            else
            {
                prev_xmachine->next = next_xmachine;
            }
        }
        else
        {
            prev_xmachine = current_xmachine;
        }

        /* move on to next agent in list */
        current_xmachine = next_xmachine;
    }
    
   
    
    /* ------------ Allocate Required Memory ----------------- */
    
    /* MPI related dynamic memory requirements */
    in_req  = (MPI_Request *)malloc(sizeof(MPI_Request) * totalnodes);
    out_req = (MPI_Request *)malloc(sizeof(MPI_Request) * totalnodes);

    /* Memory for buffer arrays */
    inbuf  = (void **)malloc(sizeof(void *) * totalnodes);
    outbuf = (void **)malloc(sizeof(void *) * totalnodes);


    /* ------ fill send buffers and post non-blocking sends ------ */
    node_info = *p_node_info;
    while(node_info)
    {
        i = node_info->node_id;
        if (i == node_number)
        {
            outbuf[i] = NULL;
            out_req[i] = MPI_REQUEST_NULL;
            node_info = node_info->next;
            continue;
        }
        
        bufsize = 0;
        outcount = 0;

        /* for each agent type */

        outcount += node_info->Household_agent_no;

        outcount += node_info->Firm_agent_no;

        outcount += node_info->Bank_agent_no;

        outcount += node_info->ClearingHouse_agent_no;

        outcount += node_info->LimitOrderBook_agent_no;

        outcount += node_info->Government_agent_no;

        outcount += node_info->FinancialAgent_agent_no;


        /* build output buffer */
        if (outcount > 0)
        {
            /* mem requirements for agent_count_list array */
            bufsize += sizeof(int) * AGENT_TYPE_COUNT;

            /* for each message type */

            /* mem requirements for Household agents */
            bufsize += sizeof(xmachine_memory_Household) * \
                       node_info->Household_agent_no;

            /* mem requirements for Firm agents */
            bufsize += sizeof(xmachine_memory_Firm) * \
                       node_info->Firm_agent_no;

            /* mem requirements for Bank agents */
            bufsize += sizeof(xmachine_memory_Bank) * \
                       node_info->Bank_agent_no;

            /* mem requirements for ClearingHouse agents */
            bufsize += sizeof(xmachine_memory_ClearingHouse) * \
                       node_info->ClearingHouse_agent_no;

            /* mem requirements for LimitOrderBook agents */
            bufsize += sizeof(xmachine_memory_LimitOrderBook) * \
                       node_info->LimitOrderBook_agent_no;

            /* mem requirements for Government agents */
            bufsize += sizeof(xmachine_memory_Government) * \
                       node_info->Government_agent_no;

            /* mem requirements for FinancialAgent agents */
            bufsize += sizeof(xmachine_memory_FinancialAgent) * \
                       node_info->FinancialAgent_agent_no;


            /* allocate required memory */
            outbuf[i] = (void *) malloc(bufsize);

            /* assign array pointers to relevant points in buffer */
            agent_count_list = (int *) outbuf[i];

    
            agent_count_list[AGENT_Household]  = node_info->Household_agent_no;
            agent_Household_list = (xmachine_memory_Household *) \
                 &agent_count_list[AGENT_TYPE_COUNT];
    

        
            agent_count_list[AGENT_Firm] = node_info->Firm_agent_no;
            agent_Firm_list = (xmachine_memory_Firm *) \
                 &agent_Household_list[agent_count_list[AGENT_Household]];
    

        
            agent_count_list[AGENT_Bank] = node_info->Bank_agent_no;
            agent_Bank_list = (xmachine_memory_Bank *) \
                 &agent_Firm_list[agent_count_list[AGENT_Firm]];
    

        
            agent_count_list[AGENT_ClearingHouse] = node_info->ClearingHouse_agent_no;
            agent_ClearingHouse_list = (xmachine_memory_ClearingHouse *) \
                 &agent_Bank_list[agent_count_list[AGENT_Bank]];
    

        
            agent_count_list[AGENT_LimitOrderBook] = node_info->LimitOrderBook_agent_no;
            agent_LimitOrderBook_list = (xmachine_memory_LimitOrderBook *) \
                 &agent_ClearingHouse_list[agent_count_list[AGENT_ClearingHouse]];
    

        
            agent_count_list[AGENT_Government] = node_info->Government_agent_no;
            agent_Government_list = (xmachine_memory_Government *) \
                 &agent_LimitOrderBook_list[agent_count_list[AGENT_LimitOrderBook]];
    

        
            agent_count_list[AGENT_FinancialAgent] = node_info->FinancialAgent_agent_no;
            agent_FinancialAgent_list = (xmachine_memory_FinancialAgent *) \
                 &agent_Government_list[agent_count_list[AGENT_Government]];
    


            /* traverse agent list and populate buffer */

            j = 0;
            temp_xmachine = node_info->Household_agents;
            while (temp_xmachine)
            {
    
                agent_Household_list[j].id = temp_xmachine->xmachine_Household->id;
    
                agent_Household_list[j].privateclassifiersystem = temp_xmachine->xmachine_Household->privateclassifiersystem;
    
                agent_Household_list[j].current_assetportfolio = temp_xmachine->xmachine_Household->current_assetportfolio;
    
                agent_Household_list[j].prescribed_assetportfolio = temp_xmachine->xmachine_Household->prescribed_assetportfolio;
    
                agent_Household_list[j].asset_budget = temp_xmachine->xmachine_Household->asset_budget;
    
                agent_Household_list[j].range = temp_xmachine->xmachine_Household->range;
    
                agent_Household_list[j].posx = temp_xmachine->xmachine_Household->posx;
    
                agent_Household_list[j].posy = temp_xmachine->xmachine_Household->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->Household_agents;
            freexmachines();
            node_info->Household_agent_no = 0;


            j = 0;
            temp_xmachine = node_info->Firm_agents;
            while (temp_xmachine)
            {
    
                agent_Firm_list[j].id = temp_xmachine->xmachine_Firm->id;
    
                agent_Firm_list[j].revenues = temp_xmachine->xmachine_Firm->revenues;
    
                agent_Firm_list[j].sales_costs = temp_xmachine->xmachine_Firm->sales_costs;
    
                agent_Firm_list[j].total_revenue = temp_xmachine->xmachine_Firm->total_revenue;
    
                agent_Firm_list[j].net_revenue = temp_xmachine->xmachine_Firm->net_revenue;
    
                agent_Firm_list[j].operational_cost = temp_xmachine->xmachine_Firm->operational_cost;
    
                agent_Firm_list[j].total_wage_payments = temp_xmachine->xmachine_Firm->total_wage_payments;
    
                agent_Firm_list[j].total_input_payments = temp_xmachine->xmachine_Firm->total_input_payments;
    
                agent_Firm_list[j].interest_payments = temp_xmachine->xmachine_Firm->interest_payments;
    
                agent_Firm_list[j].total_earnings = temp_xmachine->xmachine_Firm->total_earnings;
    
                agent_Firm_list[j].tax_rate_profits = temp_xmachine->xmachine_Firm->tax_rate_profits;
    
                agent_Firm_list[j].pretax_profit = temp_xmachine->xmachine_Firm->pretax_profit;
    
                agent_Firm_list[j].tax_provision = temp_xmachine->xmachine_Firm->tax_provision;
    
                agent_Firm_list[j].net_earnings = temp_xmachine->xmachine_Firm->net_earnings;
    
                agent_Firm_list[j].div_payments = temp_xmachine->xmachine_Firm->div_payments;
    
                agent_Firm_list[j].retained_earnings = temp_xmachine->xmachine_Firm->retained_earnings;
    
                agent_Firm_list[j].current_debt = temp_xmachine->xmachine_Firm->current_debt;
    
                agent_Firm_list[j].debt_interest_rate = temp_xmachine->xmachine_Firm->debt_interest_rate;
    
                agent_Firm_list[j].debt_repayments = temp_xmachine->xmachine_Firm->debt_repayments;
    
                agent_Firm_list[j].share_repurchase_value = temp_xmachine->xmachine_Firm->share_repurchase_value;
    
                agent_Firm_list[j].share_repurchase_units = temp_xmachine->xmachine_Firm->share_repurchase_units;
    
                agent_Firm_list[j].target_total_shares = temp_xmachine->xmachine_Firm->target_total_shares;
    
                agent_Firm_list[j].current_total_shares = temp_xmachine->xmachine_Firm->current_total_shares;
    
                agent_Firm_list[j].total_financial_needs = temp_xmachine->xmachine_Firm->total_financial_needs;
    
                agent_Firm_list[j].financial_needs = temp_xmachine->xmachine_Firm->financial_needs;
    
                agent_Firm_list[j].add_financial_needs = temp_xmachine->xmachine_Firm->add_financial_needs;
    
                agent_Firm_list[j].financial_reserves = temp_xmachine->xmachine_Firm->financial_reserves;
    
                agent_Firm_list[j].target_loans = temp_xmachine->xmachine_Firm->target_loans;
    
                agent_Firm_list[j].target_equity = temp_xmachine->xmachine_Firm->target_equity;
    
                agent_Firm_list[j].bonds_issue_target = temp_xmachine->xmachine_Firm->bonds_issue_target;
    
                agent_Firm_list[j].stocks_issue_target = temp_xmachine->xmachine_Firm->stocks_issue_target;
    
                agent_Firm_list[j].price = temp_xmachine->xmachine_Firm->price;
    
                agent_Firm_list[j].max_debt = temp_xmachine->xmachine_Firm->max_debt;
    
                agent_Firm_list[j].div_earn_ratio = temp_xmachine->xmachine_Firm->div_earn_ratio;
    
                agent_Firm_list[j].debt_earn_ratio = temp_xmachine->xmachine_Firm->debt_earn_ratio;
    
                agent_Firm_list[j].div_pshare_ratio = temp_xmachine->xmachine_Firm->div_pshare_ratio;
    
                agent_Firm_list[j].earn_pshare_ratio = temp_xmachine->xmachine_Firm->earn_pshare_ratio;
    
                agent_Firm_list[j].price_earn_ratio = temp_xmachine->xmachine_Firm->price_earn_ratio;
    
                agent_Firm_list[j].retained_earn_ratio = temp_xmachine->xmachine_Firm->retained_earn_ratio;
    
                agent_Firm_list[j].earn_pshare_ratio_growth = temp_xmachine->xmachine_Firm->earn_pshare_ratio_growth;
    
                agent_Firm_list[j].critical_price_earn_ratio = temp_xmachine->xmachine_Firm->critical_price_earn_ratio;
    
                agent_Firm_list[j].critical_earn_pshare_ratio = temp_xmachine->xmachine_Firm->critical_earn_pshare_ratio;
    
                agent_Firm_list[j].range = temp_xmachine->xmachine_Firm->range;
    
                agent_Firm_list[j].posx = temp_xmachine->xmachine_Firm->posx;
    
                agent_Firm_list[j].posy = temp_xmachine->xmachine_Firm->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->Firm_agents;
            freexmachines();
            node_info->Firm_agent_no = 0;


            j = 0;
            temp_xmachine = node_info->Bank_agents;
            while (temp_xmachine)
            {
    
                agent_Bank_list[j].id = temp_xmachine->xmachine_Bank->id;
    
                agent_Bank_list[j].ra = temp_xmachine->xmachine_Bank->ra;
    
                agent_Bank_list[j].range = temp_xmachine->xmachine_Bank->range;
    
                agent_Bank_list[j].posx = temp_xmachine->xmachine_Bank->posx;
    
                agent_Bank_list[j].posy = temp_xmachine->xmachine_Bank->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->Bank_agents;
            freexmachines();
            node_info->Bank_agent_no = 0;


            j = 0;
            temp_xmachine = node_info->ClearingHouse_agents;
            while (temp_xmachine)
            {
    
                agent_ClearingHouse_list[j].id = temp_xmachine->xmachine_ClearingHouse->id;
    
                agent_ClearingHouse_list[j].rg = temp_xmachine->xmachine_ClearingHouse->rg;
    
                agent_ClearingHouse_list[j].range = temp_xmachine->xmachine_ClearingHouse->range;
    
                agent_ClearingHouse_list[j].posx = temp_xmachine->xmachine_ClearingHouse->posx;
    
                agent_ClearingHouse_list[j].posy = temp_xmachine->xmachine_ClearingHouse->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->ClearingHouse_agents;
            freexmachines();
            node_info->ClearingHouse_agent_no = 0;


            j = 0;
            temp_xmachine = node_info->LimitOrderBook_agents;
            while (temp_xmachine)
            {
    
                agent_LimitOrderBook_list[j].id = temp_xmachine->xmachine_LimitOrderBook->id;
    
                agent_LimitOrderBook_list[j].re = temp_xmachine->xmachine_LimitOrderBook->re;
    
                agent_LimitOrderBook_list[j].range = temp_xmachine->xmachine_LimitOrderBook->range;
    
                agent_LimitOrderBook_list[j].posx = temp_xmachine->xmachine_LimitOrderBook->posx;
    
                agent_LimitOrderBook_list[j].posy = temp_xmachine->xmachine_LimitOrderBook->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->LimitOrderBook_agents;
            freexmachines();
            node_info->LimitOrderBook_agent_no = 0;


            j = 0;
            temp_xmachine = node_info->Government_agents;
            while (temp_xmachine)
            {
    
                agent_Government_list[j].id = temp_xmachine->xmachine_Government->id;
    
                agent_Government_list[j].rj = temp_xmachine->xmachine_Government->rj;
    
                agent_Government_list[j].range = temp_xmachine->xmachine_Government->range;
    
                agent_Government_list[j].posx = temp_xmachine->xmachine_Government->posx;
    
                agent_Government_list[j].posy = temp_xmachine->xmachine_Government->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->Government_agents;
            freexmachines();
            node_info->Government_agent_no = 0;


            j = 0;
            temp_xmachine = node_info->FinancialAgent_agents;
            while (temp_xmachine)
            {
    
                agent_FinancialAgent_list[j].id = temp_xmachine->xmachine_FinancialAgent->id;
    
                agent_FinancialAgent_list[j].publicclassifiersystem = temp_xmachine->xmachine_FinancialAgent->publicclassifiersystem;
    
                agent_FinancialAgent_list[j].range = temp_xmachine->xmachine_FinancialAgent->range;
    
                agent_FinancialAgent_list[j].posx = temp_xmachine->xmachine_FinancialAgent->posx;
    
                agent_FinancialAgent_list[j].posy = temp_xmachine->xmachine_FinancialAgent->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->FinancialAgent_agents;
            freexmachines();
            node_info->FinancialAgent_agent_no = 0;


            
            /* Reset xmachine pointer */
            p_xmachine = &current_node->agents;

        }
        else
        {
            outbuf[i] = NULL;
        }
        
        /* post non-blocking send */
        MPI_Issend(outbuf[i], bufsize, MPI_BYTE, i, TAG, \
                MPI_COMM_WORLD, &out_req[i]);

        /* select next node */
        node_info = node_info->next;
    }
    
    
    
    /* ----- Prepare and post non-blocking receives ------------ */
    
    /* we expect (totalnodes - 1) incoming messages */
    probed = 0;
    inbuf[node_number] = NULL;
    in_req[node_number] = MPI_REQUEST_NULL;
    i = node_number;
    while (probed < (totalnodes - 1))
    {
        /* probe from next node id  */
        i = (i + 1) % totalnodes;

        /* probe incoming messages for bufsize */
        MPI_Probe(i, TAG, MPI_COMM_WORLD, &status);

        /* get bufsize */
        MPI_Get_count(&status, MPI_BYTE, &bufsize);

        if (bufsize > 0)
        {
            inbuf[i] = (void *)malloc(bufsize);
        }
        else
        {
            inbuf[i]  = NULL;
        }
        
        /* post non-blocking receive */
        MPI_Irecv(inbuf[i], bufsize, MPI_BYTE, i, TAG, \
                MPI_COMM_WORLD, &in_req[i]);
        
        probed ++;
    }

    
    /* NOTE: routine can be split up here if we want to separate 
     *       into _init() and _complete(). Some of the variables
     *       would have to be declared as global within this file.
     *       (as implemenented in propagate_messages.c)
     */
    
    
    /* ----- Complete and process pending receives ------------------ */

    /* process received messages */
    /* instead of a Waitall, use Waitany so that we may overlap data 
       handling time with other pending receives */
    for (j = 0; j < totalnodes - 1; j++)
    {
        /* wait for any receive to complete */
        MPI_Waitany(totalnodes, in_req, &sender, &status);

        /* determine size of message */
        MPI_Get_count(&status, MPI_BYTE, &bufsize);

        /* if size = 0, there's nothing for us to do */
        if (bufsize == 0) continue;

        /* Assign array pointers to apropriate locations in buffer */
        agent_count_list = (int *) inbuf[sender];
        /* for each message type */

    
        agent_Household_list = (xmachine_memory_Household *) \
             &agent_count_list[AGENT_TYPE_COUNT];
    

    
        agent_Firm_list = (xmachine_memory_Firm *) \
             &agent_Household_list[agent_count_list[AGENT_Household]];
    

    
        agent_Bank_list = (xmachine_memory_Bank *) \
             &agent_Firm_list[agent_count_list[AGENT_Firm]];
    

    
        agent_ClearingHouse_list = (xmachine_memory_ClearingHouse *) \
             &agent_Bank_list[agent_count_list[AGENT_Bank]];
    

    
        agent_LimitOrderBook_list = (xmachine_memory_LimitOrderBook *) \
             &agent_ClearingHouse_list[agent_count_list[AGENT_ClearingHouse]];
    

    
        agent_Government_list = (xmachine_memory_Government *) \
             &agent_LimitOrderBook_list[agent_count_list[AGENT_LimitOrderBook]];
    

    
        agent_FinancialAgent_list = (xmachine_memory_FinancialAgent *) \
             &agent_Government_list[agent_count_list[AGENT_Government]];
    

        
        /* process received messages */

        for (i = 0; i < agent_count_list[AGENT_Household]; i++)
        {
            add_Household_agent( \
    
                    agent_Household_list[i].id, \
    
                    agent_Household_list[i].privateclassifiersystem, \
    
                    agent_Household_list[i].current_assetportfolio, \
    
                    agent_Household_list[i].prescribed_assetportfolio, \
    
                    agent_Household_list[i].asset_budget, \
    
                    agent_Household_list[i].range, \
    
                    agent_Household_list[i].posx, \
    
                    agent_Household_list[i].posy \
    
                    );

        }

        for (i = 0; i < agent_count_list[AGENT_Firm]; i++)
        {
            add_Firm_agent( \
    
                    agent_Firm_list[i].id, \
    
                    agent_Firm_list[i].revenues, \
    
                    agent_Firm_list[i].sales_costs, \
    
                    agent_Firm_list[i].total_revenue, \
    
                    agent_Firm_list[i].net_revenue, \
    
                    agent_Firm_list[i].operational_cost, \
    
                    agent_Firm_list[i].total_wage_payments, \
    
                    agent_Firm_list[i].total_input_payments, \
    
                    agent_Firm_list[i].interest_payments, \
    
                    agent_Firm_list[i].total_earnings, \
    
                    agent_Firm_list[i].tax_rate_profits, \
    
                    agent_Firm_list[i].pretax_profit, \
    
                    agent_Firm_list[i].tax_provision, \
    
                    agent_Firm_list[i].net_earnings, \
    
                    agent_Firm_list[i].div_payments, \
    
                    agent_Firm_list[i].retained_earnings, \
    
                    agent_Firm_list[i].current_debt, \
    
                    agent_Firm_list[i].debt_interest_rate, \
    
                    agent_Firm_list[i].debt_repayments, \
    
                    agent_Firm_list[i].share_repurchase_value, \
    
                    agent_Firm_list[i].share_repurchase_units, \
    
                    agent_Firm_list[i].target_total_shares, \
    
                    agent_Firm_list[i].current_total_shares, \
    
                    agent_Firm_list[i].total_financial_needs, \
    
                    agent_Firm_list[i].financial_needs, \
    
                    agent_Firm_list[i].add_financial_needs, \
    
                    agent_Firm_list[i].financial_reserves, \
    
                    agent_Firm_list[i].target_loans, \
    
                    agent_Firm_list[i].target_equity, \
    
                    agent_Firm_list[i].bonds_issue_target, \
    
                    agent_Firm_list[i].stocks_issue_target, \
    
                    agent_Firm_list[i].price, \
    
                    agent_Firm_list[i].max_debt, \
    
                    agent_Firm_list[i].div_earn_ratio, \
    
                    agent_Firm_list[i].debt_earn_ratio, \
    
                    agent_Firm_list[i].div_pshare_ratio, \
    
                    agent_Firm_list[i].earn_pshare_ratio, \
    
                    agent_Firm_list[i].price_earn_ratio, \
    
                    agent_Firm_list[i].retained_earn_ratio, \
    
                    agent_Firm_list[i].earn_pshare_ratio_growth, \
    
                    agent_Firm_list[i].critical_price_earn_ratio, \
    
                    agent_Firm_list[i].critical_earn_pshare_ratio, \
    
                    agent_Firm_list[i].range, \
    
                    agent_Firm_list[i].posx, \
    
                    agent_Firm_list[i].posy \
    
                    );

        }

        for (i = 0; i < agent_count_list[AGENT_Bank]; i++)
        {
            add_Bank_agent( \
    
                    agent_Bank_list[i].id, \
    
                    agent_Bank_list[i].ra, \
    
                    agent_Bank_list[i].range, \
    
                    agent_Bank_list[i].posx, \
    
                    agent_Bank_list[i].posy \
    
                    );

        }

        for (i = 0; i < agent_count_list[AGENT_ClearingHouse]; i++)
        {
            add_ClearingHouse_agent( \
    
                    agent_ClearingHouse_list[i].id, \
    
                    agent_ClearingHouse_list[i].rg, \
    
                    agent_ClearingHouse_list[i].range, \
    
                    agent_ClearingHouse_list[i].posx, \
    
                    agent_ClearingHouse_list[i].posy \
    
                    );

        }

        for (i = 0; i < agent_count_list[AGENT_LimitOrderBook]; i++)
        {
            add_LimitOrderBook_agent( \
    
                    agent_LimitOrderBook_list[i].id, \
    
                    agent_LimitOrderBook_list[i].re, \
    
                    agent_LimitOrderBook_list[i].range, \
    
                    agent_LimitOrderBook_list[i].posx, \
    
                    agent_LimitOrderBook_list[i].posy \
    
                    );

        }

        for (i = 0; i < agent_count_list[AGENT_Government]; i++)
        {
            add_Government_agent( \
    
                    agent_Government_list[i].id, \
    
                    agent_Government_list[i].rj, \
    
                    agent_Government_list[i].range, \
    
                    agent_Government_list[i].posx, \
    
                    agent_Government_list[i].posy \
    
                    );

        }

        for (i = 0; i < agent_count_list[AGENT_FinancialAgent]; i++)
        {
            add_FinancialAgent_agent( \
    
                    agent_FinancialAgent_list[i].id, \
    
                    agent_FinancialAgent_list[i].publicclassifiersystem, \
    
                    agent_FinancialAgent_list[i].range, \
    
                    agent_FinancialAgent_list[i].posx, \
    
                    agent_FinancialAgent_list[i].posy \
    
                    );

        }

        
        free(inbuf[sender]);
    }
    
    free(inbuf);
    free(in_req);
    
    
    
    /* ------- Complete non-blocking sends ----------------------- */
    
    /* wait for all non-blocking sends to complete */
    MPI_Waitall(totalnodes, out_req, MPI_STATUSES_IGNORE);
    
    /* free allocated send buffers */
    for(i = 0; i < totalnodes; i++)
    {
        if (outbuf[i]) free(outbuf[i]);
    }
    free(outbuf);
    free(out_req);

}
