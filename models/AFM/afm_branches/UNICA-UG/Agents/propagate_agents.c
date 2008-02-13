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
    AGENT_Eurostat, \
    AGENT_Household, \
    AGENT_ClearingHouse, \
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

    xmachine_memory_Eurostat *agent_Eurostat_list; 

    xmachine_memory_Household *agent_Household_list; 

    xmachine_memory_ClearingHouse *agent_ClearingHouse_list; 




    /* ---- determine which agents should be moved ---------------- */
    
    /* loop through agent list */
    prev_xmachine = NULL;
    remove_agent = 0;
    current_xmachine = current_node->agents;
    while(current_xmachine)
    {
        next_xmachine = current_xmachine->next;
        
        if(current_xmachine->xmachine_Eurostat != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Eurostat->posx;
			y_xmachine = current_xmachine->xmachine_Eurostat->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_Eurostat;
		}
        
        else if(current_xmachine->xmachine_Household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Household->posx;
			y_xmachine = current_xmachine->xmachine_Household->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_Household;
		}
        
        else if(current_xmachine->xmachine_ClearingHouse != NULL)
		{
			x_xmachine = current_xmachine->xmachine_ClearingHouse->posx;
			y_xmachine = current_xmachine->xmachine_ClearingHouse->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_ClearingHouse;
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

                    if (agent_type == AGENT_Eurostat)
                    {
                        node_info->Eurostat_agent_no ++;
                        current_xmachine->next = node_info->Eurostat_agents;
                        node_info->Eurostat_agents = current_xmachine;
                    }

                    else if (agent_type == AGENT_Household)
                    {
                        node_info->Household_agent_no ++;
                        current_xmachine->next = node_info->Household_agents;
                        node_info->Household_agents = current_xmachine;
                    }

                    else if (agent_type == AGENT_ClearingHouse)
                    {
                        node_info->ClearingHouse_agent_no ++;
                        current_xmachine->next = node_info->ClearingHouse_agents;
                        node_info->ClearingHouse_agents = current_xmachine;
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

        outcount += node_info->Eurostat_agent_no;

        outcount += node_info->Household_agent_no;

        outcount += node_info->ClearingHouse_agent_no;


        /* build output buffer */
        if (outcount > 0)
        {
            /* mem requirements for agent_count_list array */
            bufsize += sizeof(int) * AGENT_TYPE_COUNT;

            /* for each message type */

            /* mem requirements for Eurostat agents */
            bufsize += sizeof(xmachine_memory_Eurostat) * \
                       node_info->Eurostat_agent_no;

            /* mem requirements for Household agents */
            bufsize += sizeof(xmachine_memory_Household) * \
                       node_info->Household_agent_no;

            /* mem requirements for ClearingHouse agents */
            bufsize += sizeof(xmachine_memory_ClearingHouse) * \
                       node_info->ClearingHouse_agent_no;


            /* allocate required memory */
            outbuf[i] = (void *) malloc(bufsize);

            /* assign array pointers to relevant points in buffer */
            agent_count_list = (int *) outbuf[i];

    
            agent_count_list[AGENT_Eurostat]  = node_info->Eurostat_agent_no;
            agent_Eurostat_list = (xmachine_memory_Eurostat *) \
                 &agent_count_list[AGENT_TYPE_COUNT];
    

        
            agent_count_list[AGENT_Household] = node_info->Household_agent_no;
            agent_Household_list = (xmachine_memory_Household *) \
                 &agent_Eurostat_list[agent_count_list[AGENT_Eurostat]];
    

        
            agent_count_list[AGENT_ClearingHouse] = node_info->ClearingHouse_agent_no;
            agent_ClearingHouse_list = (xmachine_memory_ClearingHouse *) \
                 &agent_Household_list[agent_count_list[AGENT_Household]];
    


            /* traverse agent list and populate buffer */

            j = 0;
            temp_xmachine = node_info->Eurostat_agents;
            while (temp_xmachine)
            {
    
                agent_Eurostat_list[j].assets = temp_xmachine->xmachine_Eurostat->assets;
    
                agent_Eurostat_list[j].posx = temp_xmachine->xmachine_Eurostat->posx;
    
                agent_Eurostat_list[j].posy = temp_xmachine->xmachine_Eurostat->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->Eurostat_agents;
            freexmachines();
            node_info->Eurostat_agent_no = 0;


            j = 0;
            temp_xmachine = node_info->Household_agents;
            while (temp_xmachine)
            {
    
                agent_Household_list[j].id = temp_xmachine->xmachine_Household->id;
    
                agent_Household_list[j].wealth = temp_xmachine->xmachine_Household->wealth;
    
                agent_Household_list[j].belief = temp_xmachine->xmachine_Household->belief;
    
                agent_Household_list[j].portfolio = temp_xmachine->xmachine_Household->portfolio;
    
                agent_Household_list[j].pendingOrders = temp_xmachine->xmachine_Household->pendingOrders;
    
                agent_Household_list[j].assetsowned = temp_xmachine->xmachine_Household->assetsowned;
    
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
            temp_xmachine = node_info->ClearingHouse_agents;
            while (temp_xmachine)
            {
    
                agent_ClearingHouse_list[j].id = temp_xmachine->xmachine_ClearingHouse->id;
    
                agent_ClearingHouse_list[j].assets = temp_xmachine->xmachine_ClearingHouse->assets;
    
                agent_ClearingHouse_list[j].posx = temp_xmachine->xmachine_ClearingHouse->posx;
    
                agent_ClearingHouse_list[j].posy = temp_xmachine->xmachine_ClearingHouse->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->ClearingHouse_agents;
            freexmachines();
            node_info->ClearingHouse_agent_no = 0;


            
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

    
        agent_Eurostat_list = (xmachine_memory_Eurostat *) \
             &agent_count_list[AGENT_TYPE_COUNT];
    

    
        agent_Household_list = (xmachine_memory_Household *) \
             &agent_Eurostat_list[agent_count_list[AGENT_Eurostat]];
    

    
        agent_ClearingHouse_list = (xmachine_memory_ClearingHouse *) \
             &agent_Household_list[agent_count_list[AGENT_Household]];
    

        
        /* process received messages */

        for (i = 0; i < agent_count_list[AGENT_Eurostat]; i++)
        {
            add_Eurostat_agent( \
    
                    agent_Eurostat_list[i].assets, \
    
                    agent_Eurostat_list[i].posx, \
    
                    agent_Eurostat_list[i].posy \
    
                    );

        }

        for (i = 0; i < agent_count_list[AGENT_Household]; i++)
        {
            add_Household_agent( \
    
                    agent_Household_list[i].id, \
    
                    agent_Household_list[i].wealth, \
    
                    agent_Household_list[i].belief, \
    
                    agent_Household_list[i].portfolio, \
    
                    agent_Household_list[i].pendingOrders, \
    
                    agent_Household_list[i].assetsowned, \
    
                    agent_Household_list[i].posx, \
    
                    agent_Household_list[i].posy \
    
                    );

        }

        for (i = 0; i < agent_count_list[AGENT_ClearingHouse]; i++)
        {
            add_ClearingHouse_agent( \
    
                    agent_ClearingHouse_list[i].id, \
    
                    agent_ClearingHouse_list[i].assets, \
    
                    agent_ClearingHouse_list[i].posx, \
    
                    agent_ClearingHouse_list[i].posy \
    
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
