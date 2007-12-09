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
    MESSAGE_WagePayment, \
    MESSAGE_DividendPayment, \
    MESSAGE_BondCouponPayment, \
    MESSAGE_firm_bond_order, \
    MESSAGE_firm_stock_order, \
    MESSAGE_gov_bond_order, \
    MESSAGE_firm_bond_transaction, \
    MESSAGE_gov_bond_transaction, \
    MESSAGE_firm_stock_transaction, \
    MESSAGE_rule_performance, \
    MESSAGE_all_performances, \
    MESSAGE_ruledetailsystem, \
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



    /* pointers to temp element and array for WagePayment message */
    xmachine_message_WagePayment *message_WagePayment_temp;
    xmachine_message_WagePayment_data *message_WagePayment_list;

    /* pointers to temp element and array for DividendPayment message */
    xmachine_message_DividendPayment *message_DividendPayment_temp;
    xmachine_message_DividendPayment_data *message_DividendPayment_list;

    /* pointers to temp element and array for BondCouponPayment message */
    xmachine_message_BondCouponPayment *message_BondCouponPayment_temp;
    xmachine_message_BondCouponPayment_data *message_BondCouponPayment_list;

    /* pointers to temp element and array for firm_bond_order message */
    xmachine_message_firm_bond_order *message_firm_bond_order_temp;
    xmachine_message_firm_bond_order_data *message_firm_bond_order_list;

    /* pointers to temp element and array for firm_stock_order message */
    xmachine_message_firm_stock_order *message_firm_stock_order_temp;
    xmachine_message_firm_stock_order_data *message_firm_stock_order_list;

    /* pointers to temp element and array for gov_bond_order message */
    xmachine_message_gov_bond_order *message_gov_bond_order_temp;
    xmachine_message_gov_bond_order_data *message_gov_bond_order_list;

    /* pointers to temp element and array for firm_bond_transaction message */
    xmachine_message_firm_bond_transaction *message_firm_bond_transaction_temp;
    xmachine_message_firm_bond_transaction_data *message_firm_bond_transaction_list;

    /* pointers to temp element and array for gov_bond_transaction message */
    xmachine_message_gov_bond_transaction *message_gov_bond_transaction_temp;
    xmachine_message_gov_bond_transaction_data *message_gov_bond_transaction_list;

    /* pointers to temp element and array for firm_stock_transaction message */
    xmachine_message_firm_stock_transaction *message_firm_stock_transaction_temp;
    xmachine_message_firm_stock_transaction_data *message_firm_stock_transaction_list;

    /* pointers to temp element and array for rule_performance message */
    xmachine_message_rule_performance *message_rule_performance_temp;
    xmachine_message_rule_performance_data *message_rule_performance_list;

    /* pointers to temp element and array for all_performances message */
    xmachine_message_all_performances *message_all_performances_temp;
    xmachine_message_all_performances_data *message_all_performances_list;

    /* pointers to temp element and array for ruledetailsystem message */
    xmachine_message_ruledetailsystem *message_ruledetailsystem_temp;
    xmachine_message_ruledetailsystem_data *message_ruledetailsystem_list;


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

        outcount += node_info->WagePayment_message_no;

        outcount += node_info->DividendPayment_message_no;

        outcount += node_info->BondCouponPayment_message_no;

        outcount += node_info->firm_bond_order_message_no;

        outcount += node_info->firm_stock_order_message_no;

        outcount += node_info->gov_bond_order_message_no;

        outcount += node_info->firm_bond_transaction_message_no;

        outcount += node_info->gov_bond_transaction_message_no;

        outcount += node_info->firm_stock_transaction_message_no;

        outcount += node_info->rule_performance_message_no;

        outcount += node_info->all_performances_message_no;

        outcount += node_info->ruledetailsystem_message_no;


        
        /* build output buffer */
        if (outcount > 0)
        {
            /* mem requirements for message_count_list array */
            bufsize += sizeof(int) * MESSAGE_TYPE_COUNT;

            /* get total mem requirements for all messages */

            bufsize += sizeof(xmachine_message_WagePayment_data) * \
                       node_info->WagePayment_message_no;

            bufsize += sizeof(xmachine_message_DividendPayment_data) * \
                       node_info->DividendPayment_message_no;

            bufsize += sizeof(xmachine_message_BondCouponPayment_data) * \
                       node_info->BondCouponPayment_message_no;

            bufsize += sizeof(xmachine_message_firm_bond_order_data) * \
                       node_info->firm_bond_order_message_no;

            bufsize += sizeof(xmachine_message_firm_stock_order_data) * \
                       node_info->firm_stock_order_message_no;

            bufsize += sizeof(xmachine_message_gov_bond_order_data) * \
                       node_info->gov_bond_order_message_no;

            bufsize += sizeof(xmachine_message_firm_bond_transaction_data) * \
                       node_info->firm_bond_transaction_message_no;

            bufsize += sizeof(xmachine_message_gov_bond_transaction_data) * \
                       node_info->gov_bond_transaction_message_no;

            bufsize += sizeof(xmachine_message_firm_stock_transaction_data) * \
                       node_info->firm_stock_transaction_message_no;

            bufsize += sizeof(xmachine_message_rule_performance_data) * \
                       node_info->rule_performance_message_no;

            bufsize += sizeof(xmachine_message_all_performances_data) * \
                       node_info->all_performances_message_no;

            bufsize += sizeof(xmachine_message_ruledetailsystem_data) * \
                       node_info->ruledetailsystem_message_no;


            /* allocate required memory */
            outbuf[i] = (void *) malloc(bufsize);

            /* -- assign array pointers to relevant points in buffer -- */

            /* for message count list */
            message_count_list = (int *) outbuf[i];


            /* For WagePayment message list */
            message_count_list[MESSAGE_WagePayment] = node_info->WagePayment_message_no;
            message_WagePayment_list = (xmachine_message_WagePayment_data *)\
                           &message_count_list[MESSAGE_TYPE_COUNT];
            

            /* For DividendPayment message list */
            message_count_list[MESSAGE_DividendPayment] = node_info->DividendPayment_message_no;
            message_DividendPayment_list = (xmachine_message_DividendPayment_data *)\
                    &message_WagePayment_list[message_count_list[MESSAGE_WagePayment]];
            

            /* For BondCouponPayment message list */
            message_count_list[MESSAGE_BondCouponPayment] = node_info->BondCouponPayment_message_no;
            message_BondCouponPayment_list = (xmachine_message_BondCouponPayment_data *)\
                    &message_DividendPayment_list[message_count_list[MESSAGE_DividendPayment]];
            

            /* For firm_bond_order message list */
            message_count_list[MESSAGE_firm_bond_order] = node_info->firm_bond_order_message_no;
            message_firm_bond_order_list = (xmachine_message_firm_bond_order_data *)\
                    &message_BondCouponPayment_list[message_count_list[MESSAGE_BondCouponPayment]];
            

            /* For firm_stock_order message list */
            message_count_list[MESSAGE_firm_stock_order] = node_info->firm_stock_order_message_no;
            message_firm_stock_order_list = (xmachine_message_firm_stock_order_data *)\
                    &message_firm_bond_order_list[message_count_list[MESSAGE_firm_bond_order]];
            

            /* For gov_bond_order message list */
            message_count_list[MESSAGE_gov_bond_order] = node_info->gov_bond_order_message_no;
            message_gov_bond_order_list = (xmachine_message_gov_bond_order_data *)\
                    &message_firm_stock_order_list[message_count_list[MESSAGE_firm_stock_order]];
            

            /* For firm_bond_transaction message list */
            message_count_list[MESSAGE_firm_bond_transaction] = node_info->firm_bond_transaction_message_no;
            message_firm_bond_transaction_list = (xmachine_message_firm_bond_transaction_data *)\
                    &message_gov_bond_order_list[message_count_list[MESSAGE_gov_bond_order]];
            

            /* For gov_bond_transaction message list */
            message_count_list[MESSAGE_gov_bond_transaction] = node_info->gov_bond_transaction_message_no;
            message_gov_bond_transaction_list = (xmachine_message_gov_bond_transaction_data *)\
                    &message_firm_bond_transaction_list[message_count_list[MESSAGE_firm_bond_transaction]];
            

            /* For firm_stock_transaction message list */
            message_count_list[MESSAGE_firm_stock_transaction] = node_info->firm_stock_transaction_message_no;
            message_firm_stock_transaction_list = (xmachine_message_firm_stock_transaction_data *)\
                    &message_gov_bond_transaction_list[message_count_list[MESSAGE_gov_bond_transaction]];
            

            /* For rule_performance message list */
            message_count_list[MESSAGE_rule_performance] = node_info->rule_performance_message_no;
            message_rule_performance_list = (xmachine_message_rule_performance_data *)\
                    &message_firm_stock_transaction_list[message_count_list[MESSAGE_firm_stock_transaction]];
            

            /* For all_performances message list */
            message_count_list[MESSAGE_all_performances] = node_info->all_performances_message_no;
            message_all_performances_list = (xmachine_message_all_performances_data *)\
                    &message_rule_performance_list[message_count_list[MESSAGE_rule_performance]];
            

            /* For ruledetailsystem message list */
            message_count_list[MESSAGE_ruledetailsystem] = node_info->ruledetailsystem_message_no;
            message_ruledetailsystem_list = (xmachine_message_ruledetailsystem_data *)\
                    &message_all_performances_list[message_count_list[MESSAGE_all_performances]];
            


            
            /* -- traverse message list and populate buffer -- */

                /* for WagePayment message */            
                message_WagePayment_temp = node_info->WagePayment_messages;
                j = 0;
                while (message_WagePayment_temp)
                {
                    
                    message_WagePayment_list[j].range = message_WagePayment_temp->range;
                    message_WagePayment_list[j].x = message_WagePayment_temp->x;
                    message_WagePayment_list[j].y = message_WagePayment_temp->y;
                    message_WagePayment_list[j].z = message_WagePayment_temp->z;

                    message_WagePayment_temp = message_WagePayment_temp->next;
                    j++;
                }
                p_WagePayment_message = &node_info->WagePayment_messages;
                freeWagePaymentmessages();
                node_info->WagePayment_message_no = 0;
                p_WagePayment_message = &current_node->WagePayment_messages;


                /* for DividendPayment message */            
                message_DividendPayment_temp = node_info->DividendPayment_messages;
                j = 0;
                while (message_DividendPayment_temp)
                {
                    
                    message_DividendPayment_list[j].range = message_DividendPayment_temp->range;
                    message_DividendPayment_list[j].x = message_DividendPayment_temp->x;
                    message_DividendPayment_list[j].y = message_DividendPayment_temp->y;
                    message_DividendPayment_list[j].z = message_DividendPayment_temp->z;

                    message_DividendPayment_temp = message_DividendPayment_temp->next;
                    j++;
                }
                p_DividendPayment_message = &node_info->DividendPayment_messages;
                freeDividendPaymentmessages();
                node_info->DividendPayment_message_no = 0;
                p_DividendPayment_message = &current_node->DividendPayment_messages;


                /* for BondCouponPayment message */            
                message_BondCouponPayment_temp = node_info->BondCouponPayment_messages;
                j = 0;
                while (message_BondCouponPayment_temp)
                {
                    
                    message_BondCouponPayment_list[j].range = message_BondCouponPayment_temp->range;
                    message_BondCouponPayment_list[j].x = message_BondCouponPayment_temp->x;
                    message_BondCouponPayment_list[j].y = message_BondCouponPayment_temp->y;
                    message_BondCouponPayment_list[j].z = message_BondCouponPayment_temp->z;

                    message_BondCouponPayment_temp = message_BondCouponPayment_temp->next;
                    j++;
                }
                p_BondCouponPayment_message = &node_info->BondCouponPayment_messages;
                freeBondCouponPaymentmessages();
                node_info->BondCouponPayment_message_no = 0;
                p_BondCouponPayment_message = &current_node->BondCouponPayment_messages;


                /* for firm_bond_order message */            
                message_firm_bond_order_temp = node_info->firm_bond_order_messages;
                j = 0;
                while (message_firm_bond_order_temp)
                {
                    
                    message_firm_bond_order_list[j].household_id = message_firm_bond_order_temp->household_id;
                    message_firm_bond_order_list[j].firm_id = message_firm_bond_order_temp->firm_id;
                    message_firm_bond_order_list[j].limit_price = message_firm_bond_order_temp->limit_price;
                    message_firm_bond_order_list[j].limit_quantity = message_firm_bond_order_temp->limit_quantity;
                    message_firm_bond_order_list[j].range = message_firm_bond_order_temp->range;
                    message_firm_bond_order_list[j].x = message_firm_bond_order_temp->x;
                    message_firm_bond_order_list[j].y = message_firm_bond_order_temp->y;
                    message_firm_bond_order_list[j].z = message_firm_bond_order_temp->z;

                    message_firm_bond_order_temp = message_firm_bond_order_temp->next;
                    j++;
                }
                p_firm_bond_order_message = &node_info->firm_bond_order_messages;
                freefirm_bond_ordermessages();
                node_info->firm_bond_order_message_no = 0;
                p_firm_bond_order_message = &current_node->firm_bond_order_messages;


                /* for firm_stock_order message */            
                message_firm_stock_order_temp = node_info->firm_stock_order_messages;
                j = 0;
                while (message_firm_stock_order_temp)
                {
                    
                    message_firm_stock_order_list[j].household_id = message_firm_stock_order_temp->household_id;
                    message_firm_stock_order_list[j].firm_id = message_firm_stock_order_temp->firm_id;
                    message_firm_stock_order_list[j].limit_price = message_firm_stock_order_temp->limit_price;
                    message_firm_stock_order_list[j].limit_quantity = message_firm_stock_order_temp->limit_quantity;
                    message_firm_stock_order_list[j].range = message_firm_stock_order_temp->range;
                    message_firm_stock_order_list[j].x = message_firm_stock_order_temp->x;
                    message_firm_stock_order_list[j].y = message_firm_stock_order_temp->y;
                    message_firm_stock_order_list[j].z = message_firm_stock_order_temp->z;

                    message_firm_stock_order_temp = message_firm_stock_order_temp->next;
                    j++;
                }
                p_firm_stock_order_message = &node_info->firm_stock_order_messages;
                freefirm_stock_ordermessages();
                node_info->firm_stock_order_message_no = 0;
                p_firm_stock_order_message = &current_node->firm_stock_order_messages;


                /* for gov_bond_order message */            
                message_gov_bond_order_temp = node_info->gov_bond_order_messages;
                j = 0;
                while (message_gov_bond_order_temp)
                {
                    
                    message_gov_bond_order_list[j].household_id = message_gov_bond_order_temp->household_id;
                    message_gov_bond_order_list[j].gov_id = message_gov_bond_order_temp->gov_id;
                    message_gov_bond_order_list[j].limit_price = message_gov_bond_order_temp->limit_price;
                    message_gov_bond_order_list[j].limit_quantity = message_gov_bond_order_temp->limit_quantity;
                    message_gov_bond_order_list[j].range = message_gov_bond_order_temp->range;
                    message_gov_bond_order_list[j].x = message_gov_bond_order_temp->x;
                    message_gov_bond_order_list[j].y = message_gov_bond_order_temp->y;
                    message_gov_bond_order_list[j].z = message_gov_bond_order_temp->z;

                    message_gov_bond_order_temp = message_gov_bond_order_temp->next;
                    j++;
                }
                p_gov_bond_order_message = &node_info->gov_bond_order_messages;
                freegov_bond_ordermessages();
                node_info->gov_bond_order_message_no = 0;
                p_gov_bond_order_message = &current_node->gov_bond_order_messages;


                /* for firm_bond_transaction message */            
                message_firm_bond_transaction_temp = node_info->firm_bond_transaction_messages;
                j = 0;
                while (message_firm_bond_transaction_temp)
                {
                    
                    message_firm_bond_transaction_list[j].household_id = message_firm_bond_transaction_temp->household_id;
                    message_firm_bond_transaction_list[j].firm_id = message_firm_bond_transaction_temp->firm_id;
                    message_firm_bond_transaction_list[j].transaction_price = message_firm_bond_transaction_temp->transaction_price;
                    message_firm_bond_transaction_list[j].transaction_quantity = message_firm_bond_transaction_temp->transaction_quantity;
                    message_firm_bond_transaction_list[j].range = message_firm_bond_transaction_temp->range;
                    message_firm_bond_transaction_list[j].x = message_firm_bond_transaction_temp->x;
                    message_firm_bond_transaction_list[j].y = message_firm_bond_transaction_temp->y;
                    message_firm_bond_transaction_list[j].z = message_firm_bond_transaction_temp->z;

                    message_firm_bond_transaction_temp = message_firm_bond_transaction_temp->next;
                    j++;
                }
                p_firm_bond_transaction_message = &node_info->firm_bond_transaction_messages;
                freefirm_bond_transactionmessages();
                node_info->firm_bond_transaction_message_no = 0;
                p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;


                /* for gov_bond_transaction message */            
                message_gov_bond_transaction_temp = node_info->gov_bond_transaction_messages;
                j = 0;
                while (message_gov_bond_transaction_temp)
                {
                    
                    message_gov_bond_transaction_list[j].household_id = message_gov_bond_transaction_temp->household_id;
                    message_gov_bond_transaction_list[j].gov_id = message_gov_bond_transaction_temp->gov_id;
                    message_gov_bond_transaction_list[j].transaction_price = message_gov_bond_transaction_temp->transaction_price;
                    message_gov_bond_transaction_list[j].transaction_quantity = message_gov_bond_transaction_temp->transaction_quantity;
                    message_gov_bond_transaction_list[j].range = message_gov_bond_transaction_temp->range;
                    message_gov_bond_transaction_list[j].x = message_gov_bond_transaction_temp->x;
                    message_gov_bond_transaction_list[j].y = message_gov_bond_transaction_temp->y;
                    message_gov_bond_transaction_list[j].z = message_gov_bond_transaction_temp->z;

                    message_gov_bond_transaction_temp = message_gov_bond_transaction_temp->next;
                    j++;
                }
                p_gov_bond_transaction_message = &node_info->gov_bond_transaction_messages;
                freegov_bond_transactionmessages();
                node_info->gov_bond_transaction_message_no = 0;
                p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;


                /* for firm_stock_transaction message */            
                message_firm_stock_transaction_temp = node_info->firm_stock_transaction_messages;
                j = 0;
                while (message_firm_stock_transaction_temp)
                {
                    
                    message_firm_stock_transaction_list[j].household_id = message_firm_stock_transaction_temp->household_id;
                    message_firm_stock_transaction_list[j].firm_id = message_firm_stock_transaction_temp->firm_id;
                    message_firm_stock_transaction_list[j].transaction_price = message_firm_stock_transaction_temp->transaction_price;
                    message_firm_stock_transaction_list[j].transaction_quantity = message_firm_stock_transaction_temp->transaction_quantity;
                    message_firm_stock_transaction_list[j].range = message_firm_stock_transaction_temp->range;
                    message_firm_stock_transaction_list[j].x = message_firm_stock_transaction_temp->x;
                    message_firm_stock_transaction_list[j].y = message_firm_stock_transaction_temp->y;
                    message_firm_stock_transaction_list[j].z = message_firm_stock_transaction_temp->z;

                    message_firm_stock_transaction_temp = message_firm_stock_transaction_temp->next;
                    j++;
                }
                p_firm_stock_transaction_message = &node_info->firm_stock_transaction_messages;
                freefirm_stock_transactionmessages();
                node_info->firm_stock_transaction_message_no = 0;
                p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;


                /* for rule_performance message */            
                message_rule_performance_temp = node_info->rule_performance_messages;
                j = 0;
                while (message_rule_performance_temp)
                {
                    
                    message_rule_performance_list[j].current_rule = message_rule_performance_temp->current_rule;
                    message_rule_performance_list[j].rule_performance = message_rule_performance_temp->rule_performance;
                    message_rule_performance_list[j].range = message_rule_performance_temp->range;
                    message_rule_performance_list[j].x = message_rule_performance_temp->x;
                    message_rule_performance_list[j].y = message_rule_performance_temp->y;
                    message_rule_performance_list[j].z = message_rule_performance_temp->z;

                    message_rule_performance_temp = message_rule_performance_temp->next;
                    j++;
                }
                p_rule_performance_message = &node_info->rule_performance_messages;
                freerule_performancemessages();
                node_info->rule_performance_message_no = 0;
                p_rule_performance_message = &current_node->rule_performance_messages;


                /* for all_performances message */            
                message_all_performances_temp = node_info->all_performances_messages;
                j = 0;
                while (message_all_performances_temp)
                {
                    
                    message_all_performances_list[j].performances = message_all_performances_temp->performances;
                    message_all_performances_list[j].range = message_all_performances_temp->range;
                    message_all_performances_list[j].x = message_all_performances_temp->x;
                    message_all_performances_list[j].y = message_all_performances_temp->y;
                    message_all_performances_list[j].z = message_all_performances_temp->z;

                    message_all_performances_temp = message_all_performances_temp->next;
                    j++;
                }
                p_all_performances_message = &node_info->all_performances_messages;
                freeall_performancesmessages();
                node_info->all_performances_message_no = 0;
                p_all_performances_message = &current_node->all_performances_messages;


                /* for ruledetailsystem message */            
                message_ruledetailsystem_temp = node_info->ruledetailsystem_messages;
                j = 0;
                while (message_ruledetailsystem_temp)
                {
                    
                    message_ruledetailsystem_list[j].parameters = message_ruledetailsystem_temp->parameters;
                    message_ruledetailsystem_list[j].range = message_ruledetailsystem_temp->range;
                    message_ruledetailsystem_list[j].x = message_ruledetailsystem_temp->x;
                    message_ruledetailsystem_list[j].y = message_ruledetailsystem_temp->y;
                    message_ruledetailsystem_list[j].z = message_ruledetailsystem_temp->z;

                    message_ruledetailsystem_temp = message_ruledetailsystem_temp->next;
                    j++;
                }
                p_ruledetailsystem_message = &node_info->ruledetailsystem_messages;
                freeruledetailsystemmessages();
                node_info->ruledetailsystem_message_no = 0;
                p_ruledetailsystem_message = &current_node->ruledetailsystem_messages;


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

    xmachine_message_WagePayment *message_WagePayment_temp;
    xmachine_message_WagePayment_data *message_WagePayment_list; 

    xmachine_message_DividendPayment *message_DividendPayment_temp;
    xmachine_message_DividendPayment_data *message_DividendPayment_list; 

    xmachine_message_BondCouponPayment *message_BondCouponPayment_temp;
    xmachine_message_BondCouponPayment_data *message_BondCouponPayment_list; 

    xmachine_message_firm_bond_order *message_firm_bond_order_temp;
    xmachine_message_firm_bond_order_data *message_firm_bond_order_list; 

    xmachine_message_firm_stock_order *message_firm_stock_order_temp;
    xmachine_message_firm_stock_order_data *message_firm_stock_order_list; 

    xmachine_message_gov_bond_order *message_gov_bond_order_temp;
    xmachine_message_gov_bond_order_data *message_gov_bond_order_list; 

    xmachine_message_firm_bond_transaction *message_firm_bond_transaction_temp;
    xmachine_message_firm_bond_transaction_data *message_firm_bond_transaction_list; 

    xmachine_message_gov_bond_transaction *message_gov_bond_transaction_temp;
    xmachine_message_gov_bond_transaction_data *message_gov_bond_transaction_list; 

    xmachine_message_firm_stock_transaction *message_firm_stock_transaction_temp;
    xmachine_message_firm_stock_transaction_data *message_firm_stock_transaction_list; 

    xmachine_message_rule_performance *message_rule_performance_temp;
    xmachine_message_rule_performance_data *message_rule_performance_list; 

    xmachine_message_all_performances *message_all_performances_temp;
    xmachine_message_all_performances_data *message_all_performances_list; 

    xmachine_message_ruledetailsystem *message_ruledetailsystem_temp;
    xmachine_message_ruledetailsystem_data *message_ruledetailsystem_list; 


    
    
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


        /* For WagePayment message list */
        message_WagePayment_list = (xmachine_message_WagePayment_data *)\
               &message_count_list[MESSAGE_TYPE_COUNT];
        

        /* For DividendPayment message list */
        message_DividendPayment_list = (xmachine_message_DividendPayment_data *)\
               &message_WagePayment_list[message_count_list[MESSAGE_WagePayment]];
        

        /* For BondCouponPayment message list */
        message_BondCouponPayment_list = (xmachine_message_BondCouponPayment_data *)\
               &message_DividendPayment_list[message_count_list[MESSAGE_DividendPayment]];
        

        /* For firm_bond_order message list */
        message_firm_bond_order_list = (xmachine_message_firm_bond_order_data *)\
               &message_BondCouponPayment_list[message_count_list[MESSAGE_BondCouponPayment]];
        

        /* For firm_stock_order message list */
        message_firm_stock_order_list = (xmachine_message_firm_stock_order_data *)\
               &message_firm_bond_order_list[message_count_list[MESSAGE_firm_bond_order]];
        

        /* For gov_bond_order message list */
        message_gov_bond_order_list = (xmachine_message_gov_bond_order_data *)\
               &message_firm_stock_order_list[message_count_list[MESSAGE_firm_stock_order]];
        

        /* For firm_bond_transaction message list */
        message_firm_bond_transaction_list = (xmachine_message_firm_bond_transaction_data *)\
               &message_gov_bond_order_list[message_count_list[MESSAGE_gov_bond_order]];
        

        /* For gov_bond_transaction message list */
        message_gov_bond_transaction_list = (xmachine_message_gov_bond_transaction_data *)\
               &message_firm_bond_transaction_list[message_count_list[MESSAGE_firm_bond_transaction]];
        

        /* For firm_stock_transaction message list */
        message_firm_stock_transaction_list = (xmachine_message_firm_stock_transaction_data *)\
               &message_gov_bond_transaction_list[message_count_list[MESSAGE_gov_bond_transaction]];
        

        /* For rule_performance message list */
        message_rule_performance_list = (xmachine_message_rule_performance_data *)\
               &message_firm_stock_transaction_list[message_count_list[MESSAGE_firm_stock_transaction]];
        

        /* For all_performances message list */
        message_all_performances_list = (xmachine_message_all_performances_data *)\
               &message_rule_performance_list[message_count_list[MESSAGE_rule_performance]];
        

        /* For ruledetailsystem message list */
        message_ruledetailsystem_list = (xmachine_message_ruledetailsystem_data *)\
               &message_all_performances_list[message_count_list[MESSAGE_all_performances]];
        

        
        /* process received messages */

        for (i = 0; i < message_count_list[MESSAGE_WagePayment]; i++)
        {
            message_WagePayment_temp = (xmachine_message_WagePayment *)add_WagePayment_message_internal();

            message_WagePayment_temp->range = message_WagePayment_list[i].range;

            message_WagePayment_temp->x = message_WagePayment_list[i].x;

            message_WagePayment_temp->y = message_WagePayment_list[i].y;

            message_WagePayment_temp->z = message_WagePayment_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_DividendPayment]; i++)
        {
            message_DividendPayment_temp = (xmachine_message_DividendPayment *)add_DividendPayment_message_internal();

            message_DividendPayment_temp->range = message_DividendPayment_list[i].range;

            message_DividendPayment_temp->x = message_DividendPayment_list[i].x;

            message_DividendPayment_temp->y = message_DividendPayment_list[i].y;

            message_DividendPayment_temp->z = message_DividendPayment_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_BondCouponPayment]; i++)
        {
            message_BondCouponPayment_temp = (xmachine_message_BondCouponPayment *)add_BondCouponPayment_message_internal();

            message_BondCouponPayment_temp->range = message_BondCouponPayment_list[i].range;

            message_BondCouponPayment_temp->x = message_BondCouponPayment_list[i].x;

            message_BondCouponPayment_temp->y = message_BondCouponPayment_list[i].y;

            message_BondCouponPayment_temp->z = message_BondCouponPayment_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_firm_bond_order]; i++)
        {
            message_firm_bond_order_temp = (xmachine_message_firm_bond_order *)add_firm_bond_order_message_internal();

            message_firm_bond_order_temp->household_id = message_firm_bond_order_list[i].household_id;

            message_firm_bond_order_temp->firm_id = message_firm_bond_order_list[i].firm_id;

            message_firm_bond_order_temp->limit_price = message_firm_bond_order_list[i].limit_price;

            message_firm_bond_order_temp->limit_quantity = message_firm_bond_order_list[i].limit_quantity;

            message_firm_bond_order_temp->range = message_firm_bond_order_list[i].range;

            message_firm_bond_order_temp->x = message_firm_bond_order_list[i].x;

            message_firm_bond_order_temp->y = message_firm_bond_order_list[i].y;

            message_firm_bond_order_temp->z = message_firm_bond_order_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_firm_stock_order]; i++)
        {
            message_firm_stock_order_temp = (xmachine_message_firm_stock_order *)add_firm_stock_order_message_internal();

            message_firm_stock_order_temp->household_id = message_firm_stock_order_list[i].household_id;

            message_firm_stock_order_temp->firm_id = message_firm_stock_order_list[i].firm_id;

            message_firm_stock_order_temp->limit_price = message_firm_stock_order_list[i].limit_price;

            message_firm_stock_order_temp->limit_quantity = message_firm_stock_order_list[i].limit_quantity;

            message_firm_stock_order_temp->range = message_firm_stock_order_list[i].range;

            message_firm_stock_order_temp->x = message_firm_stock_order_list[i].x;

            message_firm_stock_order_temp->y = message_firm_stock_order_list[i].y;

            message_firm_stock_order_temp->z = message_firm_stock_order_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_gov_bond_order]; i++)
        {
            message_gov_bond_order_temp = (xmachine_message_gov_bond_order *)add_gov_bond_order_message_internal();

            message_gov_bond_order_temp->household_id = message_gov_bond_order_list[i].household_id;

            message_gov_bond_order_temp->gov_id = message_gov_bond_order_list[i].gov_id;

            message_gov_bond_order_temp->limit_price = message_gov_bond_order_list[i].limit_price;

            message_gov_bond_order_temp->limit_quantity = message_gov_bond_order_list[i].limit_quantity;

            message_gov_bond_order_temp->range = message_gov_bond_order_list[i].range;

            message_gov_bond_order_temp->x = message_gov_bond_order_list[i].x;

            message_gov_bond_order_temp->y = message_gov_bond_order_list[i].y;

            message_gov_bond_order_temp->z = message_gov_bond_order_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_firm_bond_transaction]; i++)
        {
            message_firm_bond_transaction_temp = (xmachine_message_firm_bond_transaction *)add_firm_bond_transaction_message_internal();

            message_firm_bond_transaction_temp->household_id = message_firm_bond_transaction_list[i].household_id;

            message_firm_bond_transaction_temp->firm_id = message_firm_bond_transaction_list[i].firm_id;

            message_firm_bond_transaction_temp->transaction_price = message_firm_bond_transaction_list[i].transaction_price;

            message_firm_bond_transaction_temp->transaction_quantity = message_firm_bond_transaction_list[i].transaction_quantity;

            message_firm_bond_transaction_temp->range = message_firm_bond_transaction_list[i].range;

            message_firm_bond_transaction_temp->x = message_firm_bond_transaction_list[i].x;

            message_firm_bond_transaction_temp->y = message_firm_bond_transaction_list[i].y;

            message_firm_bond_transaction_temp->z = message_firm_bond_transaction_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_gov_bond_transaction]; i++)
        {
            message_gov_bond_transaction_temp = (xmachine_message_gov_bond_transaction *)add_gov_bond_transaction_message_internal();

            message_gov_bond_transaction_temp->household_id = message_gov_bond_transaction_list[i].household_id;

            message_gov_bond_transaction_temp->gov_id = message_gov_bond_transaction_list[i].gov_id;

            message_gov_bond_transaction_temp->transaction_price = message_gov_bond_transaction_list[i].transaction_price;

            message_gov_bond_transaction_temp->transaction_quantity = message_gov_bond_transaction_list[i].transaction_quantity;

            message_gov_bond_transaction_temp->range = message_gov_bond_transaction_list[i].range;

            message_gov_bond_transaction_temp->x = message_gov_bond_transaction_list[i].x;

            message_gov_bond_transaction_temp->y = message_gov_bond_transaction_list[i].y;

            message_gov_bond_transaction_temp->z = message_gov_bond_transaction_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_firm_stock_transaction]; i++)
        {
            message_firm_stock_transaction_temp = (xmachine_message_firm_stock_transaction *)add_firm_stock_transaction_message_internal();

            message_firm_stock_transaction_temp->household_id = message_firm_stock_transaction_list[i].household_id;

            message_firm_stock_transaction_temp->firm_id = message_firm_stock_transaction_list[i].firm_id;

            message_firm_stock_transaction_temp->transaction_price = message_firm_stock_transaction_list[i].transaction_price;

            message_firm_stock_transaction_temp->transaction_quantity = message_firm_stock_transaction_list[i].transaction_quantity;

            message_firm_stock_transaction_temp->range = message_firm_stock_transaction_list[i].range;

            message_firm_stock_transaction_temp->x = message_firm_stock_transaction_list[i].x;

            message_firm_stock_transaction_temp->y = message_firm_stock_transaction_list[i].y;

            message_firm_stock_transaction_temp->z = message_firm_stock_transaction_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_rule_performance]; i++)
        {
            message_rule_performance_temp = (xmachine_message_rule_performance *)add_rule_performance_message_internal();

            message_rule_performance_temp->current_rule = message_rule_performance_list[i].current_rule;

            message_rule_performance_temp->rule_performance = message_rule_performance_list[i].rule_performance;

            message_rule_performance_temp->range = message_rule_performance_list[i].range;

            message_rule_performance_temp->x = message_rule_performance_list[i].x;

            message_rule_performance_temp->y = message_rule_performance_list[i].y;

            message_rule_performance_temp->z = message_rule_performance_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_all_performances]; i++)
        {
            message_all_performances_temp = (xmachine_message_all_performances *)add_all_performances_message_internal();

            message_all_performances_temp->performances = message_all_performances_list[i].performances;

            message_all_performances_temp->range = message_all_performances_list[i].range;

            message_all_performances_temp->x = message_all_performances_list[i].x;

            message_all_performances_temp->y = message_all_performances_list[i].y;

            message_all_performances_temp->z = message_all_performances_list[i].z;

        }

        for (i = 0; i < message_count_list[MESSAGE_ruledetailsystem]; i++)
        {
            message_ruledetailsystem_temp = (xmachine_message_ruledetailsystem *)add_ruledetailsystem_message_internal();

            message_ruledetailsystem_temp->parameters = message_ruledetailsystem_list[i].parameters;

            message_ruledetailsystem_temp->range = message_ruledetailsystem_list[i].range;

            message_ruledetailsystem_temp->x = message_ruledetailsystem_list[i].x;

            message_ruledetailsystem_temp->y = message_ruledetailsystem_list[i].y;

            message_ruledetailsystem_temp->z = message_ruledetailsystem_list[i].z;

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
