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
    AGENT_GamePlayer, \
    AGENT_GameSolver, \
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

    xmachine_memory_GamePlayer *agent_GamePlayer_list; 

    xmachine_memory_GameSolver *agent_GameSolver_list; 




    /* ---- determine which agents should be moved ---------------- */
    
    /* loop through agent list */
    prev_xmachine = NULL;
    remove_agent = 0;
    current_xmachine = current_node->agents;
    while(current_xmachine)
    {
        next_xmachine = current_xmachine->next;
        
        if(current_xmachine->xmachine_GamePlayer != NULL)
		{
			x_xmachine = current_xmachine->xmachine_GamePlayer->posx;
			y_xmachine = current_xmachine->xmachine_GamePlayer->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_GamePlayer;
		}
        
        else if(current_xmachine->xmachine_GameSolver != NULL)
		{
			x_xmachine = current_xmachine->xmachine_GameSolver->posx;
			y_xmachine = current_xmachine->xmachine_GameSolver->posy;
            
            z_xmachine = 0.0;

			agent_type = AGENT_GameSolver;
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

                    if (agent_type == AGENT_GamePlayer)
                    {
                        node_info->GamePlayer_agent_no ++;
                        current_xmachine->next = node_info->GamePlayer_agents;
                        node_info->GamePlayer_agents = current_xmachine;
                    }

                    else if (agent_type == AGENT_GameSolver)
                    {
                        node_info->GameSolver_agent_no ++;
                        current_xmachine->next = node_info->GameSolver_agents;
                        node_info->GameSolver_agents = current_xmachine;
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

        outcount += node_info->GamePlayer_agent_no;

        outcount += node_info->GameSolver_agent_no;


        /* build output buffer */
        if (outcount > 0)
        {
            /* mem requirements for agent_count_list array */
            bufsize += sizeof(int) * AGENT_TYPE_COUNT;

            /* for each message type */

            /* mem requirements for GamePlayer agents */
            bufsize += sizeof(xmachine_memory_GamePlayer) * \
                       node_info->GamePlayer_agent_no;

            /* mem requirements for GameSolver agents */
            bufsize += sizeof(xmachine_memory_GameSolver) * \
                       node_info->GameSolver_agent_no;


            /* allocate required memory */
            outbuf[i] = (void *) malloc(bufsize);

            /* assign array pointers to relevant points in buffer */
            agent_count_list = (int *) outbuf[i];

    
            agent_count_list[AGENT_GamePlayer]  = node_info->GamePlayer_agent_no;
            agent_GamePlayer_list = (xmachine_memory_GamePlayer *) \
                 &agent_count_list[AGENT_TYPE_COUNT];
    

        
            agent_count_list[AGENT_GameSolver] = node_info->GameSolver_agent_no;
            agent_GameSolver_list = (xmachine_memory_GameSolver *) \
                 &agent_GamePlayer_list[agent_count_list[AGENT_GamePlayer]];
    


            /* traverse agent list and populate buffer */

            j = 0;
            temp_xmachine = node_info->GamePlayer_agents;
            while (temp_xmachine)
            {
    
                agent_GamePlayer_list[j].id = temp_xmachine->xmachine_GamePlayer->id;
    
                agent_GamePlayer_list[j].strategy_used = temp_xmachine->xmachine_GamePlayer->strategy_used;
    
                agent_GamePlayer_list[j].previous_performance = temp_xmachine->xmachine_GamePlayer->previous_performance;
    
                agent_GamePlayer_list[j].present_state = temp_xmachine->xmachine_GamePlayer->present_state;
    
                agent_GamePlayer_list[j].iradius = temp_xmachine->xmachine_GamePlayer->iradius;
    
                agent_GamePlayer_list[j].posx = temp_xmachine->xmachine_GamePlayer->posx;
    
                agent_GamePlayer_list[j].posy = temp_xmachine->xmachine_GamePlayer->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->GamePlayer_agents;
            freexmachines();
            node_info->GamePlayer_agent_no = 0;


            j = 0;
            temp_xmachine = node_info->GameSolver_agents;
            while (temp_xmachine)
            {
    
                agent_GameSolver_list[j].strategy_list = temp_xmachine->xmachine_GameSolver->strategy_list;
    
                agent_GameSolver_list[j].new_children = temp_xmachine->xmachine_GameSolver->new_children;
    
                agent_GameSolver_list[j].nragents = temp_xmachine->xmachine_GameSolver->nragents;
    
                agent_GameSolver_list[j].automata_id = temp_xmachine->xmachine_GameSolver->automata_id;
    
                agent_GameSolver_list[j].players = temp_xmachine->xmachine_GameSolver->players;
    
                agent_GameSolver_list[j].player_one_state = temp_xmachine->xmachine_GameSolver->player_one_state;
    
                agent_GameSolver_list[j].player_two_state = temp_xmachine->xmachine_GameSolver->player_two_state;
    
                agent_GameSolver_list[j].player_one_move = temp_xmachine->xmachine_GameSolver->player_one_move;
    
                agent_GameSolver_list[j].player_two_move = temp_xmachine->xmachine_GameSolver->player_two_move;
    
                agent_GameSolver_list[j].strategy_performance = temp_xmachine->xmachine_GameSolver->strategy_performance;
    
                agent_GameSolver_list[j].offspring = temp_xmachine->xmachine_GameSolver->offspring;
    
                agent_GameSolver_list[j].rows = temp_xmachine->xmachine_GameSolver->rows;
    
                agent_GameSolver_list[j].player_list = temp_xmachine->xmachine_GameSolver->player_list;
    
                agent_GameSolver_list[j].iradius = temp_xmachine->xmachine_GameSolver->iradius;
    
                agent_GameSolver_list[j].posx = temp_xmachine->xmachine_GameSolver->posx;
    
                agent_GameSolver_list[j].posy = temp_xmachine->xmachine_GameSolver->posy;
    

                temp_xmachine = temp_xmachine->next;
                j++;
            }
            /* free list early to conserve memory */
            p_xmachine = &node_info->GameSolver_agents;
            freexmachines();
            node_info->GameSolver_agent_no = 0;


            
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

    
        agent_GamePlayer_list = (xmachine_memory_GamePlayer *) \
             &agent_count_list[AGENT_TYPE_COUNT];
    

    
        agent_GameSolver_list = (xmachine_memory_GameSolver *) \
             &agent_GamePlayer_list[agent_count_list[AGENT_GamePlayer]];
    

        
        /* process received messages */

        for (i = 0; i < agent_count_list[AGENT_GamePlayer]; i++)
        {
            add_GamePlayer_agent( \
    
                    agent_GamePlayer_list[i].id, \
    
                    agent_GamePlayer_list[i].strategy_used, \
    
                    agent_GamePlayer_list[i].previous_performance, \
    
                    agent_GamePlayer_list[i].present_state, \
    
                    agent_GamePlayer_list[i].iradius, \
    
                    agent_GamePlayer_list[i].posx, \
    
                    agent_GamePlayer_list[i].posy \
    
                    );

        }

        for (i = 0; i < agent_count_list[AGENT_GameSolver]; i++)
        {
            add_GameSolver_agent( \
    
                    agent_GameSolver_list[i].strategy_list, \
    
                    agent_GameSolver_list[i].new_children, \
    
                    agent_GameSolver_list[i].nragents, \
    
                    agent_GameSolver_list[i].automata_id, \
    
                    agent_GameSolver_list[i].players, \
    
                    agent_GameSolver_list[i].player_one_state, \
    
                    agent_GameSolver_list[i].player_two_state, \
    
                    agent_GameSolver_list[i].player_one_move, \
    
                    agent_GameSolver_list[i].player_two_move, \
    
                    agent_GameSolver_list[i].strategy_performance, \
    
                    agent_GameSolver_list[i].offspring, \
    
                    agent_GameSolver_list[i].rows, \
    
                    agent_GameSolver_list[i].player_list, \
    
                    agent_GameSolver_list[i].iradius, \
    
                    agent_GameSolver_list[i].posx, \
    
                    agent_GameSolver_list[i].posy \
    
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
