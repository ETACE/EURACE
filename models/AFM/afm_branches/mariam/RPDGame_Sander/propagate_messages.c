/* $Id$ */
/**
 * \file propagate_messages.c
 * \brief Propagate messages across nodes.
 *
 * \note  
 *       Modified version of propagate_messages(). Uses non-blocking 
 *       communication to avoid deadlocks, and customised buffering 
 *       strategies to reduce memory requirements. 
 *
 *       Routine is split into propagate_messages_init() and
 *       propagate_messages_complete() so that non-dependent computation  
 *       may be overlapped with the communication.
 */
 
#include "header.h"

/* ========== Declaration of required constants =================== */

/** Enumerated identifier for each message type */
enum { \
    MESSAGE_strategy_i_use, \
    MESSAGE_TYPE_COUNT \
};

/** message tag used for propagating messages */
#define TAG 12


/* ========== Declaration of file level global vars ================ */

/** buffer space for packed message received from each node */
void ** inbuf;
/** buffer space for packed message sent to each node */
void ** outbuf;

/** Input MPI_Request array */
MPI_Request *in_req;
/** Output MPI_Request array */
MPI_Request *out_req;


/* ========== Begin function implementation ======================== */

/** \fn void propagate_messages_init()
 * \brief Initiate propagation of messages between nodes using non-blocking communication routines.
 *
 * \author LS Chin (CCLRC)
 * \date March 2007
 */
 
void propagate_messages_init() {
    
    /* ------------ Begin Variable declarations -------------- */
    int i, j, outcount, bufsize;
    int *message_count_list;
    int probed;

    MPI_Status status;
    node_information * node_info;



    /* pointers to temp element and array for strategy_i_use message */
    xmachine_message_strategy_i_use *message_strategy_i_use_temp;
    xmachine_message_strategy_i_use_data *message_strategy_i_use_list;


    /* ------------ Allocate Required Memory ----------------- */
    
    /* Memory for MPI send/receive requests */
    in_req  = (MPI_Request *)malloc(sizeof(MPI_Request) * totalnodes);
	CHECK_POINTER(in_req);
    out_req = (MPI_Request *)malloc(sizeof(MPI_Request) * totalnodes);
	CHECK_POINTER(out_req);
    /* Memory for buffer arrays */
    inbuf  = (void **)malloc(sizeof(void *) * totalnodes);
	CHECK_POINTER(inbuf)
    outbuf = (void **)malloc(sizeof(void *) * totalnodes);
	CHECK_POINTER(outbuf);
    

    /* -------- Fill send buffers and post non-blocking sends ---- */
    
    /* iterate through node list */
    node_info = *p_node_info;

    while(node_info)
    {
        i = node_info->node_id;
        /* don't send messages to self */
        if (i == node_number)
        {
            outbuf[i] = NULL;
            out_req[i] = MPI_REQUEST_NULL;
            node_info = node_info->next;
            continue;
        }
        
        bufsize = 0;
        outcount = 0;

        /* accumulate message count of all messages */

        outcount += node_info->strategy_i_use_message_no;


        
        /* build output buffer */
        if (outcount > 0)
        {
            /* mem requirements for message_count_list array */
            bufsize += sizeof(int) * MESSAGE_TYPE_COUNT;

            /* get total mem requirements for all messages */

            bufsize += sizeof(xmachine_message_strategy_i_use_data) * \
                       node_info->strategy_i_use_message_no;


            /* allocate required memory */
            outbuf[i] = (void *) malloc(bufsize);

            /* -- assign array pointers to relevant points in buffer -- */

            /* for message count list */
            message_count_list = (int *) outbuf[i];


            /* For strategy_i_use message list */
            message_count_list[MESSAGE_strategy_i_use] = node_info->strategy_i_use_message_no;
            message_strategy_i_use_list = (xmachine_message_strategy_i_use_data *)\
                           &message_count_list[MESSAGE_TYPE_COUNT];
            


            
            /* -- traverse message list and populate buffer -- */

                /* for strategy_i_use message */            
                message_strategy_i_use_temp = node_info->strategy_i_use_messages;
                j = 0;
                while (message_strategy_i_use_temp)
                {
                    
                    message_strategy_i_use_list[j].player_id = message_strategy_i_use_temp->player_id;
                    message_strategy_i_use_list[j].strategy_id = message_strategy_i_use_temp->strategy_id;
                    message_strategy_i_use_list[j].previous_move = message_strategy_i_use_temp->previous_move;
                    message_strategy_i_use_list[j].present_state = message_strategy_i_use_temp->present_state;
                    message_strategy_i_use_list[j].range = message_strategy_i_use_temp->range;
                    message_strategy_i_use_list[j].x = message_strategy_i_use_temp->x;
                    message_strategy_i_use_list[j].y = message_strategy_i_use_temp->y;
                    message_strategy_i_use_list[j].z = message_strategy_i_use_temp->z;

                    message_strategy_i_use_temp = message_strategy_i_use_temp->next;
                    j++;
                }
                p_strategy_i_use_message = &node_info->strategy_i_use_messages;
                freestrategy_i_usemessages();
                node_info->strategy_i_use_message_no = 0;
                p_strategy_i_use_message = &current_node->strategy_i_use_messages;


        }
        else /* nothing to send */
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
        /* probe from next node id */
        i = (i + 1) % totalnodes;
        
        /* probe incoming messages for bufsize */
        MPI_Probe(i, TAG, MPI_COMM_WORLD, &status);

        /* get bufsize */
        MPI_Get_count(&status, MPI_BYTE, &bufsize);

        /* allocate memory for recv buffer */
        if (bufsize > 0)
        {
            inbuf[i] = (void *)malloc(bufsize); 
        }
        else
        {
            inbuf[i] = NULL;
        }

        /* post non-blocking receive */
        MPI_Irecv(inbuf[i], bufsize, MPI_BYTE, i, TAG, \
                MPI_COMM_WORLD, &in_req[i]);

        probed ++;
    }
    
}


/** \fn void propagate_messages_complete()
 * \brief Complete propagation of messages between nodes
 *
 * \author LS Chin (CCLRC)
 * \date March 2007
 */
void propagate_messages_complete() {

    /* ------------ Begin Variable declarations -------------- */
    int i, j, bufsize, sender;
    int *message_count_list;
    MPI_Status status;
    
    /* pointers to temporary messages. One set for each message type  */

    xmachine_message_strategy_i_use *message_strategy_i_use_temp;
    xmachine_message_strategy_i_use_data *message_strategy_i_use_list; 


    
    
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
        message_count_list = (int *)inbuf[sender];


        /* For strategy_i_use message list */
        message_strategy_i_use_list = (xmachine_message_strategy_i_use_data *)\
               &message_count_list[MESSAGE_TYPE_COUNT];
        

        
        /* process received messages */

        for (i = 0; i < message_count_list[MESSAGE_strategy_i_use]; i++)
        {
            message_strategy_i_use_temp = (xmachine_message_strategy_i_use *)add_strategy_i_use_message_internal();

            message_strategy_i_use_temp->player_id = message_strategy_i_use_list[i].player_id;

            message_strategy_i_use_temp->strategy_id = message_strategy_i_use_list[i].strategy_id;

            message_strategy_i_use_temp->previous_move = message_strategy_i_use_list[i].previous_move;

            message_strategy_i_use_temp->present_state = message_strategy_i_use_list[i].present_state;

            message_strategy_i_use_temp->range = message_strategy_i_use_list[i].range;

            message_strategy_i_use_temp->x = message_strategy_i_use_list[i].x;

            message_strategy_i_use_temp->y = message_strategy_i_use_list[i].y;

            message_strategy_i_use_temp->z = message_strategy_i_use_list[i].z;

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
