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
    MESSAGE_order, \
    MESSAGE_orderStatus, \
    MESSAGE_asset, \
    MESSAGE_infoAsset, \
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



    /* pointers to temp element and array for order message */
    xmachine_message_order *message_order_temp;
    xmachine_message_order_data *message_order_list;

    /* pointers to temp element and array for orderStatus message */
    xmachine_message_orderStatus *message_orderStatus_temp;
    xmachine_message_orderStatus_data *message_orderStatus_list;

    /* pointers to temp element and array for asset message */
    xmachine_message_asset *message_asset_temp;
    xmachine_message_asset_data *message_asset_list;

    /* pointers to temp element and array for infoAsset message */
    xmachine_message_infoAsset *message_infoAsset_temp;
    xmachine_message_infoAsset_data *message_infoAsset_list;


    /* ------------ Allocate Required Memory ----------------- */
    
    /* Memory for MPI send/receive requests */
    in_req  = (MPI_Request *)malloc(sizeof(MPI_Request) * totalnodes);
    out_req = (MPI_Request *)malloc(sizeof(MPI_Request) * totalnodes);

    /* Memory for buffer arrays */
    inbuf  = (void **)malloc(sizeof(void *) * totalnodes);
    outbuf = (void **)malloc(sizeof(void *) * totalnodes);
    

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

        outcount += node_info->order_message_no;

        outcount += node_info->orderStatus_message_no;

        outcount += node_info->asset_message_no;

        outcount += node_info->infoAsset_message_no;


        
        /* build output buffer */
        if (outcount > 0)
        {
            /* mem requirements for message_count_list array */
            bufsize += sizeof(int) * MESSAGE_TYPE_COUNT;

            /* get total mem requirements for all messages */

            bufsize += sizeof(xmachine_message_order_data) * \
                       node_info->order_message_no;

            bufsize += sizeof(xmachine_message_orderStatus_data) * \
                       node_info->orderStatus_message_no;

            bufsize += sizeof(xmachine_message_asset_data) * \
                       node_info->asset_message_no;

            bufsize += sizeof(xmachine_message_infoAsset_data) * \
                       node_info->infoAsset_message_no;


            /* allocate required memory */
            outbuf[i] = (void *) malloc(bufsize);

            /* -- assign array pointers to relevant points in buffer -- */

            /* for message count list */
            message_count_list = (int *) outbuf[i];


            /* For order message list */
            message_count_list[MESSAGE_order] = node_info->order_message_no;
            message_order_list = (xmachine_message_order_data *)\
                           &message_count_list[MESSAGE_TYPE_COUNT];
            

            /* For orderStatus message list */
            message_count_list[MESSAGE_orderStatus] = node_info->orderStatus_message_no;
            message_orderStatus_list = (xmachine_message_orderStatus_data *)\
                    &message_order_list[message_count_list[MESSAGE_order]];
            

            /* For asset message list */
            message_count_list[MESSAGE_asset] = node_info->asset_message_no;
            message_asset_list = (xmachine_message_asset_data *)\
                    &message_orderStatus_list[message_count_list[MESSAGE_orderStatus]];
            

            /* For infoAsset message list */
            message_count_list[MESSAGE_infoAsset] = node_info->infoAsset_message_no;
            message_infoAsset_list = (xmachine_message_infoAsset_data *)\
                    &message_asset_list[message_count_list[MESSAGE_asset]];
            


            
            /* -- traverse message list and populate buffer -- */

                /* for order message */            
                message_order_temp = node_info->order_messages;
                j = 0;
                while (message_order_temp)
                {
                    
                    message_order_list[j].issuer = message_order_temp->issuer;
                    message_order_list[j].assetId = message_order_temp->assetId;
                    message_order_list[j].limitPrice = message_order_temp->limitPrice;
                    message_order_list[j].quantity = message_order_temp->quantity;
                    message_order_list[j].range = message_order_temp->range;
                    message_order_list[j].x = message_order_temp->x;
                    message_order_list[j].y = message_order_temp->y;
                    message_order_list[j].z = message_order_temp->z;

                    message_order_temp = message_order_temp->next;
                    j++;
                }
                p_order_message = &node_info->order_messages;
                freeordermessages();
                node_info->order_message_no = 0;
                p_order_message = &current_node->order_messages;


                /* for orderStatus message */            
                message_orderStatus_temp = node_info->orderStatus_messages;
                j = 0;
                while (message_orderStatus_temp)
                {
                    
                    message_orderStatus_list[j].issuer = message_orderStatus_temp->issuer;
                    message_orderStatus_list[j].assetId = message_orderStatus_temp->assetId;
                    message_orderStatus_list[j].price = message_orderStatus_temp->price;
                    message_orderStatus_list[j].quantity = message_orderStatus_temp->quantity;
                    message_orderStatus_list[j].range = message_orderStatus_temp->range;
                    message_orderStatus_list[j].x = message_orderStatus_temp->x;
                    message_orderStatus_list[j].y = message_orderStatus_temp->y;
                    message_orderStatus_list[j].z = message_orderStatus_temp->z;

                    message_orderStatus_temp = message_orderStatus_temp->next;
                    j++;
                }
                p_orderStatus_message = &node_info->orderStatus_messages;
                freeorderStatusmessages();
                node_info->orderStatus_message_no = 0;
                p_orderStatus_message = &current_node->orderStatus_messages;


                /* for asset message */            
                message_asset_temp = node_info->asset_messages;
                j = 0;
                while (message_asset_temp)
                {
                    
                    message_asset_list[j].issuer = message_asset_temp->issuer;
                    message_asset_list[j].price = message_asset_temp->price;
                    message_asset_list[j].quantity = message_asset_temp->quantity;
                    message_asset_list[j].range = message_asset_temp->range;
                    message_asset_list[j].x = message_asset_temp->x;
                    message_asset_list[j].y = message_asset_temp->y;
                    message_asset_list[j].z = message_asset_temp->z;

                    message_asset_temp = message_asset_temp->next;
                    j++;
                }
                p_asset_message = &node_info->asset_messages;
                freeassetmessages();
                node_info->asset_message_no = 0;
                p_asset_message = &current_node->asset_messages;


                /* for infoAsset message */            
                message_infoAsset_temp = node_info->infoAsset_messages;
                j = 0;
                while (message_infoAsset_temp)
                {
                    
                    message_infoAsset_list[j].issuer = message_infoAsset_temp->issuer;
                    message_infoAsset_list[j].price = message_infoAsset_temp->price;
                    message_infoAsset_list[j].quantity = message_infoAsset_temp->quantity;
                    message_infoAsset_list[j].range = message_infoAsset_temp->range;
                    message_infoAsset_list[j].x = message_infoAsset_temp->x;
                    message_infoAsset_list[j].y = message_infoAsset_temp->y;
                    message_infoAsset_list[j].z = message_infoAsset_temp->z;

                    message_infoAsset_temp = message_infoAsset_temp->next;
                    j++;
                }
                p_infoAsset_message = &node_info->infoAsset_messages;
                freeinfoAssetmessages();
                node_info->infoAsset_message_no = 0;
                p_infoAsset_message = &current_node->infoAsset_messages;


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

    xmachine_message_order *message_order_temp;
    xmachine_message_order_data *message_order_list; 

    xmachine_message_orderStatus *message_orderStatus_temp;
    xmachine_message_orderStatus_data *message_orderStatus_list; 

    xmachine_message_asset *message_asset_temp;
    xmachine_message_asset_data *message_asset_list; 

    xmachine_message_infoAsset *message_infoAsset_temp;
    xmachine_message_infoAsset_data *message_infoAsset_list; 


    
    
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


        /* For order message list */
        message_order_list = (xmachine_message_order_data *)\
               &message_count_list[MESSAGE_TYPE_COUNT];
        

        /* For orderStatus message list */
        message_orderStatus_list = (xmachine_message_orderStatus_data *)\
               &message_order_list[message_count_list[MESSAGE_order]];
        

        /* For asset message list */
        message_asset_list = (xmachine_message_asset_data *)\
               &message_orderStatus_list[message_count_list[MESSAGE_orderStatus]];
        

        /* For infoAsset message list */
        message_infoAsset_list = (xmachine_message_infoAsset_data *)\
               &message_asset_list[message_count_list[MESSAGE_asset]];
        

        
        /* process received messages */

        for (i = 0; i < message_count_list[MESSAGE_order]; i++)
        {
            message_order_temp = (xmachine_message_order *)add_order_message_internal();

            message_order_temp->issuer = message_order_list[i].issuer;

            message_order_temp->assetId = message_order_list[i].assetId;

            message_order_temp->limitPrice = message_order_list[i].limitPrice;

            message_order_temp->quantity = message_order_list[i].quantity;

            message_order_temp->range = message_order_list[i].range;

            message_order_temp->x = message_order_list[i].x;

            message_order_temp->y = message_order_list[i].y;

            message_order_temp->z = message_order_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_orderStatus]; i++)
        {
            message_orderStatus_temp = (xmachine_message_orderStatus *)add_orderStatus_message_internal();

            message_orderStatus_temp->issuer = message_orderStatus_list[i].issuer;

            message_orderStatus_temp->assetId = message_orderStatus_list[i].assetId;

            message_orderStatus_temp->price = message_orderStatus_list[i].price;

            message_orderStatus_temp->quantity = message_orderStatus_list[i].quantity;

            message_orderStatus_temp->range = message_orderStatus_list[i].range;

            message_orderStatus_temp->x = message_orderStatus_list[i].x;

            message_orderStatus_temp->y = message_orderStatus_list[i].y;

            message_orderStatus_temp->z = message_orderStatus_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_asset]; i++)
        {
            message_asset_temp = (xmachine_message_asset *)add_asset_message_internal();

            message_asset_temp->issuer = message_asset_list[i].issuer;

            message_asset_temp->price = message_asset_list[i].price;

            message_asset_temp->quantity = message_asset_list[i].quantity;

            message_asset_temp->range = message_asset_list[i].range;

            message_asset_temp->x = message_asset_list[i].x;

            message_asset_temp->y = message_asset_list[i].y;

            message_asset_temp->z = message_asset_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_infoAsset]; i++)
        {
            message_infoAsset_temp = (xmachine_message_infoAsset *)add_infoAsset_message_internal();

            message_infoAsset_temp->issuer = message_infoAsset_list[i].issuer;

            message_infoAsset_temp->price = message_infoAsset_list[i].price;

            message_infoAsset_temp->quantity = message_infoAsset_list[i].quantity;

            message_infoAsset_temp->range = message_infoAsset_list[i].range;

            message_infoAsset_temp->x = message_infoAsset_list[i].x;

            message_infoAsset_temp->y = message_infoAsset_list[i].y;

            message_infoAsset_temp->z = message_infoAsset_list[i].z;

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
