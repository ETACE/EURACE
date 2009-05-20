/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn void add_bank_account_update_message(int id, int bank_id, double payment_account)
 * \brief Add bank_account_update message by calling internal and processing.
 * \param id Message variable.
 * \param bank_id Message variable.
 * \param payment_account Message variable.
 */
void add_bank_account_update_message(int id, int bank_id, double payment_account)
{
    int rc;
	m_bank_account_update msg;
    
    msg.id = id;
    msg.bank_id = bank_id;
    msg.payment_account = payment_account;
    
    
    rc = MB_AddMessage(b_bank_account_update, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_account_update' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_account_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_account_update* getInternalMessage_bank_account_update(void)
{
    static m_bank_account_update *msg_prev = NULL;
    m_bank_account_update *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_account_update); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_account_update' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_account_update' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_account_update, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_account_update' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_account_update' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_bank_account_update * get_first_bank_account_update_message()
 * \brief Get the first bank_account_update message in the bank_account_update message list.
 * \return The first message in the list.
 */
m_bank_account_update * get_first_bank_account_update_message()
{
	return getInternalMessage_bank_account_update();
}

/** \fn xmachine_message_bank_account_update * get_next_bank_account_update_message(xmachine_message_bank_account_update * current)
 * \brief Get the next bank_account_update message in the bank_account_update message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_account_update * get_next_bank_account_update_message(m_bank_account_update * current)
{
	return getInternalMessage_bank_account_update();
}

/** \fn void add_central_bank_account_update_message(int id, double payment_account)
 * \brief Add central_bank_account_update message by calling internal and processing.
 * \param id Message variable.
 * \param payment_account Message variable.
 */
void add_central_bank_account_update_message(int id, double payment_account)
{
    int rc;
	m_central_bank_account_update msg;
    
    msg.id = id;
    msg.payment_account = payment_account;
    
    
    rc = MB_AddMessage(b_central_bank_account_update, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'central_bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'central_bank_account_update' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'central_bank_account_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_central_bank_account_update* getInternalMessage_central_bank_account_update(void)
{
    static m_central_bank_account_update *msg_prev = NULL;
    m_central_bank_account_update *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_central_bank_account_update); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'central_bank_account_update' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'central_bank_account_update' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_central_bank_account_update, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'central_bank_account_update' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'central_bank_account_update' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_central_bank_account_update * get_first_central_bank_account_update_message()
 * \brief Get the first central_bank_account_update message in the central_bank_account_update message list.
 * \return The first message in the list.
 */
m_central_bank_account_update * get_first_central_bank_account_update_message()
{
	return getInternalMessage_central_bank_account_update();
}

/** \fn xmachine_message_central_bank_account_update * get_next_central_bank_account_update_message(xmachine_message_central_bank_account_update * current)
 * \brief Get the next central_bank_account_update message in the central_bank_account_update message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_central_bank_account_update * get_next_central_bank_account_update_message(m_central_bank_account_update * current)
{
	return getInternalMessage_central_bank_account_update();
}

/** \fn void add_wage_payment_message(int firm_id, int worker_id, double payment, double productivity, double average_specific_skills)
 * \brief Add wage_payment message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param payment Message variable.
 * \param productivity Message variable.
 * \param average_specific_skills Message variable.
 */
void add_wage_payment_message(int firm_id, int worker_id, double payment, double productivity, double average_specific_skills)
{
    int rc;
	m_wage_payment msg;
    
    msg.firm_id = firm_id;
    msg.worker_id = worker_id;
    msg.payment = payment;
    msg.productivity = productivity;
    msg.average_specific_skills = average_specific_skills;
    
    
    rc = MB_AddMessage(b_wage_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'wage_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'wage_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'wage_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_wage_payment* getInternalMessage_wage_payment(void)
{
    static m_wage_payment *msg_prev = NULL;
    m_wage_payment *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_wage_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'wage_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'wage_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_wage_payment, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'wage_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'wage_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_wage_payment * get_first_wage_payment_message()
 * \brief Get the first wage_payment message in the wage_payment message list.
 * \return The first message in the list.
 */
m_wage_payment * get_first_wage_payment_message()
{
	return getInternalMessage_wage_payment();
}

/** \fn xmachine_message_wage_payment * get_next_wage_payment_message(xmachine_message_wage_payment * current)
 * \brief Get the next wage_payment message in the wage_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_wage_payment * get_next_wage_payment_message(m_wage_payment * current)
{
	return getInternalMessage_wage_payment();
}

/** \fn void add_quality_price_info_1_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available)
 * \brief Add quality_price_info_1 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param mall_region_id Message variable.
 * \param firm_id Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 * \param available Message variable.
 */
void add_quality_price_info_1_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available)
{
    int rc;
	m_quality_price_info_1 msg;
    
    msg.mall_id = mall_id;
    msg.mall_region_id = mall_region_id;
    msg.firm_id = firm_id;
    msg.quality = quality;
    msg.price = price;
    msg.available = available;
    
    
    rc = MB_AddMessage(b_quality_price_info_1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'quality_price_info_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_quality_price_info_1* getInternalMessage_quality_price_info_1(void)
{
    static m_quality_price_info_1 *msg_prev = NULL;
    m_quality_price_info_1 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_quality_price_info_1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'quality_price_info_1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'quality_price_info_1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_quality_price_info_1, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'quality_price_info_1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_quality_price_info_1 * get_first_quality_price_info_1_message()
 * \brief Get the first quality_price_info_1 message in the quality_price_info_1 message list.
 * \return The first message in the list.
 */
m_quality_price_info_1 * get_first_quality_price_info_1_message()
{
	return getInternalMessage_quality_price_info_1();
}

/** \fn xmachine_message_quality_price_info_1 * get_next_quality_price_info_1_message(xmachine_message_quality_price_info_1 * current)
 * \brief Get the next quality_price_info_1 message in the quality_price_info_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_quality_price_info_1 * get_next_quality_price_info_1_message(m_quality_price_info_1 * current)
{
	return getInternalMessage_quality_price_info_1();
}

/** \fn void add_quality_price_info_2_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available)
 * \brief Add quality_price_info_2 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param mall_region_id Message variable.
 * \param firm_id Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 * \param available Message variable.
 */
void add_quality_price_info_2_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available)
{
    int rc;
	m_quality_price_info_2 msg;
    
    msg.mall_id = mall_id;
    msg.mall_region_id = mall_region_id;
    msg.firm_id = firm_id;
    msg.quality = quality;
    msg.price = price;
    msg.available = available;
    
    
    rc = MB_AddMessage(b_quality_price_info_2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'quality_price_info_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_quality_price_info_2* getInternalMessage_quality_price_info_2(void)
{
    static m_quality_price_info_2 *msg_prev = NULL;
    m_quality_price_info_2 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_quality_price_info_2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'quality_price_info_2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'quality_price_info_2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_quality_price_info_2, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'quality_price_info_2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_quality_price_info_2 * get_first_quality_price_info_2_message()
 * \brief Get the first quality_price_info_2 message in the quality_price_info_2 message list.
 * \return The first message in the list.
 */
m_quality_price_info_2 * get_first_quality_price_info_2_message()
{
	return getInternalMessage_quality_price_info_2();
}

/** \fn xmachine_message_quality_price_info_2 * get_next_quality_price_info_2_message(xmachine_message_quality_price_info_2 * current)
 * \brief Get the next quality_price_info_2 message in the quality_price_info_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_quality_price_info_2 * get_next_quality_price_info_2_message(m_quality_price_info_2 * current)
{
	return getInternalMessage_quality_price_info_2();
}

/** \fn void add_update_mall_stock_message(int mall_id, int firm_id, double quantity, double quality, double price, double previous_price)
 * \brief Add update_mall_stock message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_id Message variable.
 * \param quantity Message variable.
 * \param quality Message variable.
 * \param price Message variable.
 * \param previous_price Message variable.
 */
void add_update_mall_stock_message(int mall_id, int firm_id, double quantity, double quality, double price, double previous_price)
{
    int rc;
	m_update_mall_stock msg;
    
    msg.mall_id = mall_id;
    msg.firm_id = firm_id;
    msg.quantity = quantity;
    msg.quality = quality;
    msg.price = price;
    msg.previous_price = previous_price;
    
    
    rc = MB_AddMessage(b_update_mall_stock, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'update_mall_stock' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'update_mall_stock' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'update_mall_stock' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_update_mall_stock* getInternalMessage_update_mall_stock(void)
{
    static m_update_mall_stock *msg_prev = NULL;
    m_update_mall_stock *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_update_mall_stock); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'update_mall_stock' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'update_mall_stock' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_update_mall_stock, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'update_mall_stock' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'update_mall_stock' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_update_mall_stock * get_first_update_mall_stock_message()
 * \brief Get the first update_mall_stock message in the update_mall_stock message list.
 * \return The first message in the list.
 */
m_update_mall_stock * get_first_update_mall_stock_message()
{
	return getInternalMessage_update_mall_stock();
}

/** \fn xmachine_message_update_mall_stock * get_next_update_mall_stock_message(xmachine_message_update_mall_stock * current)
 * \brief Get the next update_mall_stock message in the update_mall_stock message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_update_mall_stock * get_next_update_mall_stock_message(m_update_mall_stock * current)
{
	return getInternalMessage_update_mall_stock();
}

/** \fn void add_consumption_request_1_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity)
 * \brief Add consumption_request_1 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param firm_id Message variable.
 * \param quantity Message variable.
 */
void add_consumption_request_1_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity)
{
    int rc;
	m_consumption_request_1 msg;
    
    msg.mall_id = mall_id;
    msg.worker_id = worker_id;
    msg.region_id = region_id;
    msg.firm_id = firm_id;
    msg.quantity = quantity;
    
    
    rc = MB_AddMessage(b_consumption_request_1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'consumption_request_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_consumption_request_1* getInternalMessage_consumption_request_1(void)
{
    static m_consumption_request_1 *msg_prev = NULL;
    m_consumption_request_1 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_consumption_request_1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'consumption_request_1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'consumption_request_1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_consumption_request_1, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'consumption_request_1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_consumption_request_1 * get_first_consumption_request_1_message()
 * \brief Get the first consumption_request_1 message in the consumption_request_1 message list.
 * \return The first message in the list.
 */
m_consumption_request_1 * get_first_consumption_request_1_message()
{
	return getInternalMessage_consumption_request_1();
}

/** \fn xmachine_message_consumption_request_1 * get_next_consumption_request_1_message(xmachine_message_consumption_request_1 * current)
 * \brief Get the next consumption_request_1 message in the consumption_request_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_consumption_request_1 * get_next_consumption_request_1_message(m_consumption_request_1 * current)
{
	return getInternalMessage_consumption_request_1();
}

/** \fn void add_consumption_request_2_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity)
 * \brief Add consumption_request_2 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param firm_id Message variable.
 * \param quantity Message variable.
 */
void add_consumption_request_2_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity)
{
    int rc;
	m_consumption_request_2 msg;
    
    msg.mall_id = mall_id;
    msg.worker_id = worker_id;
    msg.region_id = region_id;
    msg.firm_id = firm_id;
    msg.quantity = quantity;
    
    
    rc = MB_AddMessage(b_consumption_request_2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'consumption_request_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_consumption_request_2* getInternalMessage_consumption_request_2(void)
{
    static m_consumption_request_2 *msg_prev = NULL;
    m_consumption_request_2 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_consumption_request_2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'consumption_request_2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'consumption_request_2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_consumption_request_2, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'consumption_request_2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_consumption_request_2 * get_first_consumption_request_2_message()
 * \brief Get the first consumption_request_2 message in the consumption_request_2 message list.
 * \return The first message in the list.
 */
m_consumption_request_2 * get_first_consumption_request_2_message()
{
	return getInternalMessage_consumption_request_2();
}

/** \fn xmachine_message_consumption_request_2 * get_next_consumption_request_2_message(xmachine_message_consumption_request_2 * current)
 * \brief Get the next consumption_request_2 message in the consumption_request_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_consumption_request_2 * get_next_consumption_request_2_message(m_consumption_request_2 * current)
{
	return getInternalMessage_consumption_request_2();
}

/** \fn void add_accepted_consumption_1_message(int mall_id, int household_id, double offered_consumption_volume, int rationed)
 * \brief Add accepted_consumption_1 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param household_id Message variable.
 * \param offered_consumption_volume Message variable.
 * \param rationed Message variable.
 */
void add_accepted_consumption_1_message(int mall_id, int household_id, double offered_consumption_volume, int rationed)
{
    int rc;
	m_accepted_consumption_1 msg;
    
    msg.mall_id = mall_id;
    msg.household_id = household_id;
    msg.offered_consumption_volume = offered_consumption_volume;
    msg.rationed = rationed;
    
    
    rc = MB_AddMessage(b_accepted_consumption_1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'accepted_consumption_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_accepted_consumption_1* getInternalMessage_accepted_consumption_1(void)
{
    static m_accepted_consumption_1 *msg_prev = NULL;
    m_accepted_consumption_1 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_accepted_consumption_1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'accepted_consumption_1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'accepted_consumption_1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_accepted_consumption_1, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'accepted_consumption_1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_accepted_consumption_1 * get_first_accepted_consumption_1_message()
 * \brief Get the first accepted_consumption_1 message in the accepted_consumption_1 message list.
 * \return The first message in the list.
 */
m_accepted_consumption_1 * get_first_accepted_consumption_1_message()
{
	return getInternalMessage_accepted_consumption_1();
}

/** \fn xmachine_message_accepted_consumption_1 * get_next_accepted_consumption_1_message(xmachine_message_accepted_consumption_1 * current)
 * \brief Get the next accepted_consumption_1 message in the accepted_consumption_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_accepted_consumption_1 * get_next_accepted_consumption_1_message(m_accepted_consumption_1 * current)
{
	return getInternalMessage_accepted_consumption_1();
}

/** \fn void add_accepted_consumption_2_message(int mall_id, int household_id, double offered_consumption_volume, int rationed)
 * \brief Add accepted_consumption_2 message by calling internal and processing.
 * \param mall_id Message variable.
 * \param household_id Message variable.
 * \param offered_consumption_volume Message variable.
 * \param rationed Message variable.
 */
void add_accepted_consumption_2_message(int mall_id, int household_id, double offered_consumption_volume, int rationed)
{
    int rc;
	m_accepted_consumption_2 msg;
    
    msg.mall_id = mall_id;
    msg.household_id = household_id;
    msg.offered_consumption_volume = offered_consumption_volume;
    msg.rationed = rationed;
    
    
    rc = MB_AddMessage(b_accepted_consumption_2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'accepted_consumption_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_accepted_consumption_2* getInternalMessage_accepted_consumption_2(void)
{
    static m_accepted_consumption_2 *msg_prev = NULL;
    m_accepted_consumption_2 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_accepted_consumption_2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'accepted_consumption_2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'accepted_consumption_2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_accepted_consumption_2, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'accepted_consumption_2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_accepted_consumption_2 * get_first_accepted_consumption_2_message()
 * \brief Get the first accepted_consumption_2 message in the accepted_consumption_2 message list.
 * \return The first message in the list.
 */
m_accepted_consumption_2 * get_first_accepted_consumption_2_message()
{
	return getInternalMessage_accepted_consumption_2();
}

/** \fn xmachine_message_accepted_consumption_2 * get_next_accepted_consumption_2_message(xmachine_message_accepted_consumption_2 * current)
 * \brief Get the next accepted_consumption_2 message in the accepted_consumption_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_accepted_consumption_2 * get_next_accepted_consumption_2_message(m_accepted_consumption_2 * current)
{
	return getInternalMessage_accepted_consumption_2();
}

/** \fn void add_sales_message(int mall_id, int firm_id, double revenue, int stock_empty, double current_stock)
 * \brief Add sales message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_id Message variable.
 * \param revenue Message variable.
 * \param stock_empty Message variable.
 * \param current_stock Message variable.
 */
void add_sales_message(int mall_id, int firm_id, double revenue, int stock_empty, double current_stock)
{
    int rc;
	m_sales msg;
    
    msg.mall_id = mall_id;
    msg.firm_id = firm_id;
    msg.revenue = revenue;
    msg.stock_empty = stock_empty;
    msg.current_stock = current_stock;
    
    
    rc = MB_AddMessage(b_sales, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'sales' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sales' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sales' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_sales* getInternalMessage_sales(void)
{
    static m_sales *msg_prev = NULL;
    m_sales *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_sales); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'sales' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'sales' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_sales, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'sales' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sales' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_sales * get_first_sales_message()
 * \brief Get the first sales message in the sales message list.
 * \return The first message in the list.
 */
m_sales * get_first_sales_message()
{
	return getInternalMessage_sales();
}

/** \fn xmachine_message_sales * get_next_sales_message(xmachine_message_sales * current)
 * \brief Get the next sales message in the sales message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_sales * get_next_sales_message(m_sales * current)
{
	return getInternalMessage_sales();
}

/** \fn void add_specific_skill_update_message(int id, int firm_id, double specific_skills)
 * \brief Add specific_skill_update message by calling internal and processing.
 * \param id Message variable.
 * \param firm_id Message variable.
 * \param specific_skills Message variable.
 */
void add_specific_skill_update_message(int id, int firm_id, double specific_skills)
{
    int rc;
	m_specific_skill_update msg;
    
    msg.id = id;
    msg.firm_id = firm_id;
    msg.specific_skills = specific_skills;
    
    
    rc = MB_AddMessage(b_specific_skill_update, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'specific_skill_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'specific_skill_update' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'specific_skill_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_specific_skill_update* getInternalMessage_specific_skill_update(void)
{
    static m_specific_skill_update *msg_prev = NULL;
    m_specific_skill_update *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_specific_skill_update); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'specific_skill_update' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'specific_skill_update' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_specific_skill_update, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'specific_skill_update' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'specific_skill_update' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_specific_skill_update * get_first_specific_skill_update_message()
 * \brief Get the first specific_skill_update message in the specific_skill_update message list.
 * \return The first message in the list.
 */
m_specific_skill_update * get_first_specific_skill_update_message()
{
	return getInternalMessage_specific_skill_update();
}

/** \fn xmachine_message_specific_skill_update * get_next_specific_skill_update_message(xmachine_message_specific_skill_update * current)
 * \brief Get the next specific_skill_update message in the specific_skill_update message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_specific_skill_update * get_next_specific_skill_update_message(m_specific_skill_update * current)
{
	return getInternalMessage_specific_skill_update();
}

/** \fn void add_daily_revenue_to_bank_message(int id, int bank_id, double payment_account)
 * \brief Add daily_revenue_to_bank message by calling internal and processing.
 * \param id Message variable.
 * \param bank_id Message variable.
 * \param payment_account Message variable.
 */
void add_daily_revenue_to_bank_message(int id, int bank_id, double payment_account)
{
    int rc;
	m_daily_revenue_to_bank msg;
    
    msg.id = id;
    msg.bank_id = bank_id;
    msg.payment_account = payment_account;
    
    
    rc = MB_AddMessage(b_daily_revenue_to_bank, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'daily_revenue_to_bank' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'daily_revenue_to_bank' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'daily_revenue_to_bank' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_daily_revenue_to_bank* getInternalMessage_daily_revenue_to_bank(void)
{
    static m_daily_revenue_to_bank *msg_prev = NULL;
    m_daily_revenue_to_bank *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_daily_revenue_to_bank); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'daily_revenue_to_bank' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'daily_revenue_to_bank' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_daily_revenue_to_bank, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'daily_revenue_to_bank' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'daily_revenue_to_bank' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_daily_revenue_to_bank * get_first_daily_revenue_to_bank_message()
 * \brief Get the first daily_revenue_to_bank message in the daily_revenue_to_bank message list.
 * \return The first message in the list.
 */
m_daily_revenue_to_bank * get_first_daily_revenue_to_bank_message()
{
	return getInternalMessage_daily_revenue_to_bank();
}

/** \fn xmachine_message_daily_revenue_to_bank * get_next_daily_revenue_to_bank_message(xmachine_message_daily_revenue_to_bank * current)
 * \brief Get the next daily_revenue_to_bank message in the daily_revenue_to_bank message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_daily_revenue_to_bank * get_next_daily_revenue_to_bank_message(m_daily_revenue_to_bank * current)
{
	return getInternalMessage_daily_revenue_to_bank();
}

/** \fn void add_bank_identity_message(int bank_id)
 * \brief Add bank_identity message by calling internal and processing.
 * \param bank_id Message variable.
 */
void add_bank_identity_message(int bank_id)
{
    int rc;
	m_bank_identity msg;
    
    msg.bank_id = bank_id;
    
    
    rc = MB_AddMessage(b_bank_identity, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_identity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_identity' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_identity' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_identity* getInternalMessage_bank_identity(void)
{
    static m_bank_identity *msg_prev = NULL;
    m_bank_identity *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_identity); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_identity' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_identity' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_identity, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_identity' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_identity' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_bank_identity * get_first_bank_identity_message()
 * \brief Get the first bank_identity message in the bank_identity message list.
 * \return The first message in the list.
 */
m_bank_identity * get_first_bank_identity_message()
{
	return getInternalMessage_bank_identity();
}

/** \fn xmachine_message_bank_identity * get_next_bank_identity_message(xmachine_message_bank_identity * current)
 * \brief Get the next bank_identity message in the bank_identity message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_identity * get_next_bank_identity_message(m_bank_identity * current)
{
	return getInternalMessage_bank_identity();
}

/** \fn void add_loan_request_message(int firm_id, int bank_id, double equity, double total_debt, double external_financial_needs)
 * \brief Add loan_request message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param equity Message variable.
 * \param total_debt Message variable.
 * \param external_financial_needs Message variable.
 */
void add_loan_request_message(int firm_id, int bank_id, double equity, double total_debt, double external_financial_needs)
{
    int rc;
	m_loan_request msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.equity = equity;
    msg.total_debt = total_debt;
    msg.external_financial_needs = external_financial_needs;
    
    
    rc = MB_AddMessage(b_loan_request, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'loan_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_loan_request* getInternalMessage_loan_request(void)
{
    static m_loan_request *msg_prev = NULL;
    m_loan_request *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_loan_request); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'loan_request' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'loan_request' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_loan_request, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'loan_request' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_loan_request * get_first_loan_request_message()
 * \brief Get the first loan_request message in the loan_request message list.
 * \return The first message in the list.
 */
m_loan_request * get_first_loan_request_message()
{
	return getInternalMessage_loan_request();
}

/** \fn xmachine_message_loan_request * get_next_loan_request_message(xmachine_message_loan_request * current)
 * \brief Get the next loan_request message in the loan_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_loan_request * get_next_loan_request_message(m_loan_request * current)
{
	return getInternalMessage_loan_request();
}

/** \fn void add_loan_conditions_message(int firm_id, int bank_id, double proposed_interest_rate, double amount_offered_credit, double value_at_risk)
 * \brief Add loan_conditions message by calling internal and processing.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param proposed_interest_rate Message variable.
 * \param amount_offered_credit Message variable.
 * \param value_at_risk Message variable.
 */
void add_loan_conditions_message(int firm_id, int bank_id, double proposed_interest_rate, double amount_offered_credit, double value_at_risk)
{
    int rc;
	m_loan_conditions msg;
    
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.proposed_interest_rate = proposed_interest_rate;
    msg.amount_offered_credit = amount_offered_credit;
    msg.value_at_risk = value_at_risk;
    
    
    rc = MB_AddMessage(b_loan_conditions, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'loan_conditions' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_conditions' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_conditions' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_loan_conditions* getInternalMessage_loan_conditions(void)
{
    static m_loan_conditions *msg_prev = NULL;
    m_loan_conditions *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_loan_conditions); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'loan_conditions' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'loan_conditions' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_loan_conditions, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'loan_conditions' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_conditions' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_loan_conditions * get_first_loan_conditions_message()
 * \brief Get the first loan_conditions message in the loan_conditions message list.
 * \return The first message in the list.
 */
m_loan_conditions * get_first_loan_conditions_message()
{
	return getInternalMessage_loan_conditions();
}

/** \fn xmachine_message_loan_conditions * get_next_loan_conditions_message(xmachine_message_loan_conditions * current)
 * \brief Get the next loan_conditions message in the loan_conditions message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_loan_conditions * get_next_loan_conditions_message(m_loan_conditions * current)
{
	return getInternalMessage_loan_conditions();
}

/** \fn void add_loan_acceptance_message(int bank_id, double credit_amount_taken, double loan_total_var)
 * \brief Add loan_acceptance message by calling internal and processing.
 * \param bank_id Message variable.
 * \param credit_amount_taken Message variable.
 * \param loan_total_var Message variable.
 */
void add_loan_acceptance_message(int bank_id, double credit_amount_taken, double loan_total_var)
{
    int rc;
	m_loan_acceptance msg;
    
    msg.bank_id = bank_id;
    msg.credit_amount_taken = credit_amount_taken;
    msg.loan_total_var = loan_total_var;
    
    
    rc = MB_AddMessage(b_loan_acceptance, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'loan_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acceptance' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_acceptance' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_loan_acceptance* getInternalMessage_loan_acceptance(void)
{
    static m_loan_acceptance *msg_prev = NULL;
    m_loan_acceptance *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_loan_acceptance); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'loan_acceptance' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'loan_acceptance' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_loan_acceptance, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'loan_acceptance' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acceptance' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_loan_acceptance * get_first_loan_acceptance_message()
 * \brief Get the first loan_acceptance message in the loan_acceptance message list.
 * \return The first message in the list.
 */
m_loan_acceptance * get_first_loan_acceptance_message()
{
	return getInternalMessage_loan_acceptance();
}

/** \fn xmachine_message_loan_acceptance * get_next_loan_acceptance_message(xmachine_message_loan_acceptance * current)
 * \brief Get the next loan_acceptance message in the loan_acceptance message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_loan_acceptance * get_next_loan_acceptance_message(m_loan_acceptance * current)
{
	return getInternalMessage_loan_acceptance();
}

/** \fn void add_installment_message(int bank_id, double installment_amount, double interest_amount, double var_per_installment)
 * \brief Add installment message by calling internal and processing.
 * \param bank_id Message variable.
 * \param installment_amount Message variable.
 * \param interest_amount Message variable.
 * \param var_per_installment Message variable.
 */
void add_installment_message(int bank_id, double installment_amount, double interest_amount, double var_per_installment)
{
    int rc;
	m_installment msg;
    
    msg.bank_id = bank_id;
    msg.installment_amount = installment_amount;
    msg.interest_amount = interest_amount;
    msg.var_per_installment = var_per_installment;
    
    
    rc = MB_AddMessage(b_installment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'installment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'installment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'installment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_installment* getInternalMessage_installment(void)
{
    static m_installment *msg_prev = NULL;
    m_installment *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_installment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'installment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'installment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_installment, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'installment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'installment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_installment * get_first_installment_message()
 * \brief Get the first installment message in the installment message list.
 * \return The first message in the list.
 */
m_installment * get_first_installment_message()
{
	return getInternalMessage_installment();
}

/** \fn xmachine_message_installment * get_next_installment_message(xmachine_message_installment * current)
 * \brief Get the next installment message in the installment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_installment * get_next_installment_message(m_installment * current)
{
	return getInternalMessage_installment();
}

/** \fn void add_bankruptcy_message(int bank_id, double bad_debt, double credit_refunded, double residual_var)
 * \brief Add bankruptcy message by calling internal and processing.
 * \param bank_id Message variable.
 * \param bad_debt Message variable.
 * \param credit_refunded Message variable.
 * \param residual_var Message variable.
 */
void add_bankruptcy_message(int bank_id, double bad_debt, double credit_refunded, double residual_var)
{
    int rc;
	m_bankruptcy msg;
    
    msg.bank_id = bank_id;
    msg.bad_debt = bad_debt;
    msg.credit_refunded = credit_refunded;
    msg.residual_var = residual_var;
    
    
    rc = MB_AddMessage(b_bankruptcy, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bankruptcy' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bankruptcy* getInternalMessage_bankruptcy(void)
{
    static m_bankruptcy *msg_prev = NULL;
    m_bankruptcy *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bankruptcy); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bankruptcy' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bankruptcy' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bankruptcy, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bankruptcy' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_bankruptcy * get_first_bankruptcy_message()
 * \brief Get the first bankruptcy message in the bankruptcy message list.
 * \return The first message in the list.
 */
m_bankruptcy * get_first_bankruptcy_message()
{
	return getInternalMessage_bankruptcy();
}

/** \fn xmachine_message_bankruptcy * get_next_bankruptcy_message(xmachine_message_bankruptcy * current)
 * \brief Get the next bankruptcy message in the bankruptcy message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bankruptcy * get_next_bankruptcy_message(m_bankruptcy * current)
{
	return getInternalMessage_bankruptcy();
}

/** \fn void add_BCE_return_message(int bce_debt, int id)
 * \brief Add BCE_return message by calling internal and processing.
 * \param bce_debt Message variable.
 * \param id Message variable.
 */
void add_BCE_return_message(int bce_debt, int id)
{
    int rc;
	m_BCE_return msg;
    
    msg.bce_debt = bce_debt;
    msg.id = id;
    
    
    rc = MB_AddMessage(b_BCE_return, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'BCE_return' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'BCE_return' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'BCE_return' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_BCE_return* getInternalMessage_BCE_return(void)
{
    static m_BCE_return *msg_prev = NULL;
    m_BCE_return *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_BCE_return); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'BCE_return' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'BCE_return' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_BCE_return, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'BCE_return' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'BCE_return' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_BCE_return * get_first_BCE_return_message()
 * \brief Get the first BCE_return message in the BCE_return message list.
 * \return The first message in the list.
 */
m_BCE_return * get_first_BCE_return_message()
{
	return getInternalMessage_BCE_return();
}

/** \fn xmachine_message_BCE_return * get_next_BCE_return_message(xmachine_message_BCE_return * current)
 * \brief Get the next BCE_return message in the BCE_return message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_BCE_return * get_next_BCE_return_message(m_BCE_return * current)
{
	return getInternalMessage_BCE_return();
}

/** \fn void add_bank_interest_payment_message(double bank_interest_amount)
 * \brief Add bank_interest_payment message by calling internal and processing.
 * \param bank_interest_amount Message variable.
 */
void add_bank_interest_payment_message(double bank_interest_amount)
{
    int rc;
	m_bank_interest_payment msg;
    
    msg.bank_interest_amount = bank_interest_amount;
    
    
    rc = MB_AddMessage(b_bank_interest_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_interest_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_interest_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_interest_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_interest_payment* getInternalMessage_bank_interest_payment(void)
{
    static m_bank_interest_payment *msg_prev = NULL;
    m_bank_interest_payment *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_interest_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_interest_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_interest_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_interest_payment, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_interest_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_interest_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_bank_interest_payment * get_first_bank_interest_payment_message()
 * \brief Get the first bank_interest_payment message in the bank_interest_payment message list.
 * \return The first message in the list.
 */
m_bank_interest_payment * get_first_bank_interest_payment_message()
{
	return getInternalMessage_bank_interest_payment();
}

/** \fn xmachine_message_bank_interest_payment * get_next_bank_interest_payment_message(xmachine_message_bank_interest_payment * current)
 * \brief Get the next bank_interest_payment message in the bank_interest_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_interest_payment * get_next_bank_interest_payment_message(m_bank_interest_payment * current)
{
	return getInternalMessage_bank_interest_payment();
}

/** \fn void add_accountInterest_message(int bank_id, double interest)
 * \brief Add accountInterest message by calling internal and processing.
 * \param bank_id Message variable.
 * \param interest Message variable.
 */
void add_accountInterest_message(int bank_id, double interest)
{
    int rc;
	m_accountInterest msg;
    
    msg.bank_id = bank_id;
    msg.interest = interest;
    
    
    rc = MB_AddMessage(b_accountInterest, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'accountInterest' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accountInterest' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accountInterest' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_accountInterest* getInternalMessage_accountInterest(void)
{
    static m_accountInterest *msg_prev = NULL;
    m_accountInterest *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_accountInterest); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'accountInterest' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'accountInterest' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_accountInterest, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'accountInterest' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accountInterest' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_accountInterest * get_first_accountInterest_message()
 * \brief Get the first accountInterest message in the accountInterest message list.
 * \return The first message in the list.
 */
m_accountInterest * get_first_accountInterest_message()
{
	return getInternalMessage_accountInterest();
}

/** \fn xmachine_message_accountInterest * get_next_accountInterest_message(xmachine_message_accountInterest * current)
 * \brief Get the next accountInterest message in the accountInterest message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_accountInterest * get_next_accountInterest_message(m_accountInterest * current)
{
	return getInternalMessage_accountInterest();
}

/** \fn void add_dividend_per_share_message(int firm_id, double current_dividend_per_share)
 * \brief Add dividend_per_share message by calling internal and processing.
 * \param firm_id Message variable.
 * \param current_dividend_per_share Message variable.
 */
void add_dividend_per_share_message(int firm_id, double current_dividend_per_share)
{
    int rc;
	m_dividend_per_share msg;
    
    msg.firm_id = firm_id;
    msg.current_dividend_per_share = current_dividend_per_share;
    
    
    rc = MB_AddMessage(b_dividend_per_share, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'dividend_per_share' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_per_share' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'dividend_per_share' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_dividend_per_share* getInternalMessage_dividend_per_share(void)
{
    static m_dividend_per_share *msg_prev = NULL;
    m_dividend_per_share *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_dividend_per_share); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'dividend_per_share' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'dividend_per_share' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_dividend_per_share, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'dividend_per_share' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_per_share' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_dividend_per_share * get_first_dividend_per_share_message()
 * \brief Get the first dividend_per_share message in the dividend_per_share message list.
 * \return The first message in the list.
 */
m_dividend_per_share * get_first_dividend_per_share_message()
{
	return getInternalMessage_dividend_per_share();
}

/** \fn xmachine_message_dividend_per_share * get_next_dividend_per_share_message(xmachine_message_dividend_per_share * current)
 * \brief Get the next dividend_per_share message in the dividend_per_share message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_dividend_per_share * get_next_dividend_per_share_message(m_dividend_per_share * current)
{
	return getInternalMessage_dividend_per_share();
}

/** \fn void add_bankruptcy_illiquidity_message(int firm_id)
 * \brief Add bankruptcy_illiquidity message by calling internal and processing.
 * \param firm_id Message variable.
 */
void add_bankruptcy_illiquidity_message(int firm_id)
{
    int rc;
	m_bankruptcy_illiquidity msg;
    
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_bankruptcy_illiquidity, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bankruptcy_illiquidity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bankruptcy_illiquidity* getInternalMessage_bankruptcy_illiquidity(void)
{
    static m_bankruptcy_illiquidity *msg_prev = NULL;
    m_bankruptcy_illiquidity *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bankruptcy_illiquidity); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bankruptcy_illiquidity' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bankruptcy_illiquidity, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bankruptcy_illiquidity' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_bankruptcy_illiquidity * get_first_bankruptcy_illiquidity_message()
 * \brief Get the first bankruptcy_illiquidity message in the bankruptcy_illiquidity message list.
 * \return The first message in the list.
 */
m_bankruptcy_illiquidity * get_first_bankruptcy_illiquidity_message()
{
	return getInternalMessage_bankruptcy_illiquidity();
}

/** \fn xmachine_message_bankruptcy_illiquidity * get_next_bankruptcy_illiquidity_message(xmachine_message_bankruptcy_illiquidity * current)
 * \brief Get the next bankruptcy_illiquidity message in the bankruptcy_illiquidity message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bankruptcy_illiquidity * get_next_bankruptcy_illiquidity_message(m_bankruptcy_illiquidity * current)
{
	return getInternalMessage_bankruptcy_illiquidity();
}

/** \fn void add_bankruptcy_insolvency_message(int firm_id)
 * \brief Add bankruptcy_insolvency message by calling internal and processing.
 * \param firm_id Message variable.
 */
void add_bankruptcy_insolvency_message(int firm_id)
{
    int rc;
	m_bankruptcy_insolvency msg;
    
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_bankruptcy_insolvency, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bankruptcy_insolvency' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bankruptcy_insolvency* getInternalMessage_bankruptcy_insolvency(void)
{
    static m_bankruptcy_insolvency *msg_prev = NULL;
    m_bankruptcy_insolvency *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bankruptcy_insolvency); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bankruptcy_insolvency' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bankruptcy_insolvency' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bankruptcy_insolvency, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bankruptcy_insolvency' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_bankruptcy_insolvency * get_first_bankruptcy_insolvency_message()
 * \brief Get the first bankruptcy_insolvency message in the bankruptcy_insolvency message list.
 * \return The first message in the list.
 */
m_bankruptcy_insolvency * get_first_bankruptcy_insolvency_message()
{
	return getInternalMessage_bankruptcy_insolvency();
}

/** \fn xmachine_message_bankruptcy_insolvency * get_next_bankruptcy_insolvency_message(xmachine_message_bankruptcy_insolvency * current)
 * \brief Get the next bankruptcy_insolvency message in the bankruptcy_insolvency message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bankruptcy_insolvency * get_next_bankruptcy_insolvency_message(m_bankruptcy_insolvency * current)
{
	return getInternalMessage_bankruptcy_insolvency();
}

/** \fn void add_gov_bond_message(double amount)
 * \brief Add gov_bond message by calling internal and processing.
 * \param amount Message variable.
 */
void add_gov_bond_message(double amount)
{
    int rc;
	m_gov_bond msg;
    
    msg.amount = amount;
    
    
    rc = MB_AddMessage(b_gov_bond, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'gov_bond' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_bond' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_bond' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_gov_bond* getInternalMessage_gov_bond(void)
{
    static m_gov_bond *msg_prev = NULL;
    m_gov_bond *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_gov_bond); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'gov_bond' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'gov_bond' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_gov_bond, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'gov_bond' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_bond' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_gov_bond * get_first_gov_bond_message()
 * \brief Get the first gov_bond message in the gov_bond message list.
 * \return The first message in the list.
 */
m_gov_bond * get_first_gov_bond_message()
{
	return getInternalMessage_gov_bond();
}

/** \fn xmachine_message_gov_bond * get_next_gov_bond_message(xmachine_message_gov_bond * current)
 * \brief Get the next gov_bond message in the gov_bond message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_gov_bond * get_next_gov_bond_message(m_gov_bond * current)
{
	return getInternalMessage_gov_bond();
}

/** \fn void add_productivity_message(int IGfirm_id, double cap_productivity, double cap_good_price)
 * \brief Add productivity message by calling internal and processing.
 * \param IGfirm_id Message variable.
 * \param cap_productivity Message variable.
 * \param cap_good_price Message variable.
 */
void add_productivity_message(int IGfirm_id, double cap_productivity, double cap_good_price)
{
    int rc;
	m_productivity msg;
    
    msg.IGfirm_id = IGfirm_id;
    msg.cap_productivity = cap_productivity;
    msg.cap_good_price = cap_good_price;
    
    
    rc = MB_AddMessage(b_productivity, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'productivity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'productivity' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'productivity' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_productivity* getInternalMessage_productivity(void)
{
    static m_productivity *msg_prev = NULL;
    m_productivity *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_productivity); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'productivity' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'productivity' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_productivity, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'productivity' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'productivity' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_productivity * get_first_productivity_message()
 * \brief Get the first productivity message in the productivity message list.
 * \return The first message in the list.
 */
m_productivity * get_first_productivity_message()
{
	return getInternalMessage_productivity();
}

/** \fn xmachine_message_productivity * get_next_productivity_message(xmachine_message_productivity * current)
 * \brief Get the next productivity message in the productivity message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_productivity * get_next_productivity_message(m_productivity * current)
{
	return getInternalMessage_productivity();
}

/** \fn void add_capital_good_request_message(int firm_id, double capital_good_demand)
 * \brief Add capital_good_request message by calling internal and processing.
 * \param firm_id Message variable.
 * \param capital_good_demand Message variable.
 */
void add_capital_good_request_message(int firm_id, double capital_good_demand)
{
    int rc;
	m_capital_good_request msg;
    
    msg.firm_id = firm_id;
    msg.capital_good_demand = capital_good_demand;
    
    
    rc = MB_AddMessage(b_capital_good_request, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'capital_good_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_request' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_capital_good_request* getInternalMessage_capital_good_request(void)
{
    static m_capital_good_request *msg_prev = NULL;
    m_capital_good_request *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_capital_good_request); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'capital_good_request' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'capital_good_request' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_capital_good_request, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'capital_good_request' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_request' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_capital_good_request * get_first_capital_good_request_message()
 * \brief Get the first capital_good_request message in the capital_good_request message list.
 * \return The first message in the list.
 */
m_capital_good_request * get_first_capital_good_request_message()
{
	return getInternalMessage_capital_good_request();
}

/** \fn xmachine_message_capital_good_request * get_next_capital_good_request_message(xmachine_message_capital_good_request * current)
 * \brief Get the next capital_good_request message in the capital_good_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_capital_good_request * get_next_capital_good_request_message(m_capital_good_request * current)
{
	return getInternalMessage_capital_good_request();
}

/** \fn void add_capital_good_profit_distribution_message(double capital_good_profit_shares)
 * \brief Add capital_good_profit_distribution message by calling internal and processing.
 * \param capital_good_profit_shares Message variable.
 */
void add_capital_good_profit_distribution_message(double capital_good_profit_shares)
{
    int rc;
	m_capital_good_profit_distribution msg;
    
    msg.capital_good_profit_shares = capital_good_profit_shares;
    
    
    rc = MB_AddMessage(b_capital_good_profit_distribution, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'capital_good_profit_distribution' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_capital_good_profit_distribution* getInternalMessage_capital_good_profit_distribution(void)
{
    static m_capital_good_profit_distribution *msg_prev = NULL;
    m_capital_good_profit_distribution *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_capital_good_profit_distribution); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'capital_good_profit_distribution' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'capital_good_profit_distribution' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_capital_good_profit_distribution, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'capital_good_profit_distribution' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_capital_good_profit_distribution * get_first_capital_good_profit_distribution_message()
 * \brief Get the first capital_good_profit_distribution message in the capital_good_profit_distribution message list.
 * \return The first message in the list.
 */
m_capital_good_profit_distribution * get_first_capital_good_profit_distribution_message()
{
	return getInternalMessage_capital_good_profit_distribution();
}

/** \fn xmachine_message_capital_good_profit_distribution * get_next_capital_good_profit_distribution_message(xmachine_message_capital_good_profit_distribution * current)
 * \brief Get the next capital_good_profit_distribution message in the capital_good_profit_distribution message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_capital_good_profit_distribution * get_next_capital_good_profit_distribution_message(m_capital_good_profit_distribution * current)
{
	return getInternalMessage_capital_good_profit_distribution();
}

/** \fn void add_capital_good_delivery_message(int firm_id, double capital_good_delivery_volume, double productivity, double capital_good_price)
 * \brief Add capital_good_delivery message by calling internal and processing.
 * \param firm_id Message variable.
 * \param capital_good_delivery_volume Message variable.
 * \param productivity Message variable.
 * \param capital_good_price Message variable.
 */
void add_capital_good_delivery_message(int firm_id, double capital_good_delivery_volume, double productivity, double capital_good_price)
{
    int rc;
	m_capital_good_delivery msg;
    
    msg.firm_id = firm_id;
    msg.capital_good_delivery_volume = capital_good_delivery_volume;
    msg.productivity = productivity;
    msg.capital_good_price = capital_good_price;
    
    
    rc = MB_AddMessage(b_capital_good_delivery, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'capital_good_delivery' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_capital_good_delivery* getInternalMessage_capital_good_delivery(void)
{
    static m_capital_good_delivery *msg_prev = NULL;
    m_capital_good_delivery *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_capital_good_delivery); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'capital_good_delivery' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'capital_good_delivery' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_capital_good_delivery, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'capital_good_delivery' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_delivery' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_capital_good_delivery * get_first_capital_good_delivery_message()
 * \brief Get the first capital_good_delivery message in the capital_good_delivery message list.
 * \return The first message in the list.
 */
m_capital_good_delivery * get_first_capital_good_delivery_message()
{
	return getInternalMessage_capital_good_delivery();
}

/** \fn xmachine_message_capital_good_delivery * get_next_capital_good_delivery_message(xmachine_message_capital_good_delivery * current)
 * \brief Get the next capital_good_delivery message in the capital_good_delivery message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_capital_good_delivery * get_next_capital_good_delivery_message(m_capital_good_delivery * current)
{
	return getInternalMessage_capital_good_delivery();
}

/** \fn void add_dividend_message(double dividend)
 * \brief Add dividend message by calling internal and processing.
 * \param dividend Message variable.
 */
void add_dividend_message(double dividend)
{
    int rc;
	m_dividend msg;
    
    msg.dividend = dividend;
    
    
    rc = MB_AddMessage(b_dividend, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'dividend' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'dividend' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_dividend* getInternalMessage_dividend(void)
{
    static m_dividend *msg_prev = NULL;
    m_dividend *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_dividend); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'dividend' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'dividend' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_dividend, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'dividend' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_dividend * get_first_dividend_message()
 * \brief Get the first dividend message in the dividend message list.
 * \return The first message in the list.
 */
m_dividend * get_first_dividend_message()
{
	return getInternalMessage_dividend();
}

/** \fn xmachine_message_dividend * get_next_dividend_message(xmachine_message_dividend * current)
 * \brief Get the next dividend message in the dividend message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_dividend * get_next_dividend_message(m_dividend * current)
{
	return getInternalMessage_dividend();
}

/** \fn void add_pay_capital_goods_message(int firm_id, double capital_bill)
 * \brief Add pay_capital_goods message by calling internal and processing.
 * \param firm_id Message variable.
 * \param capital_bill Message variable.
 */
void add_pay_capital_goods_message(int firm_id, double capital_bill)
{
    int rc;
	m_pay_capital_goods msg;
    
    msg.firm_id = firm_id;
    msg.capital_bill = capital_bill;
    
    
    rc = MB_AddMessage(b_pay_capital_goods, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'pay_capital_goods' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_pay_capital_goods* getInternalMessage_pay_capital_goods(void)
{
    static m_pay_capital_goods *msg_prev = NULL;
    m_pay_capital_goods *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_pay_capital_goods); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'pay_capital_goods' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'pay_capital_goods' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_pay_capital_goods, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'pay_capital_goods' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pay_capital_goods' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_pay_capital_goods * get_first_pay_capital_goods_message()
 * \brief Get the first pay_capital_goods message in the pay_capital_goods message list.
 * \return The first message in the list.
 */
m_pay_capital_goods * get_first_pay_capital_goods_message()
{
	return getInternalMessage_pay_capital_goods();
}

/** \fn xmachine_message_pay_capital_goods * get_next_pay_capital_goods_message(xmachine_message_pay_capital_goods * current)
 * \brief Get the next pay_capital_goods message in the pay_capital_goods message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_pay_capital_goods * get_next_pay_capital_goods_message(m_pay_capital_goods * current)
{
	return getInternalMessage_pay_capital_goods();
}

/** \fn void add_vacancies_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5)
 * \brief Add vacancies message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param firm_wage_offer_for_skill_1 Message variable.
 * \param firm_wage_offer_for_skill_2 Message variable.
 * \param firm_wage_offer_for_skill_3 Message variable.
 * \param firm_wage_offer_for_skill_4 Message variable.
 * \param firm_wage_offer_for_skill_5 Message variable.
 */
void add_vacancies_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5)
{
    int rc;
	m_vacancies msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.firm_wage_offer_for_skill_1 = firm_wage_offer_for_skill_1;
    msg.firm_wage_offer_for_skill_2 = firm_wage_offer_for_skill_2;
    msg.firm_wage_offer_for_skill_3 = firm_wage_offer_for_skill_3;
    msg.firm_wage_offer_for_skill_4 = firm_wage_offer_for_skill_4;
    msg.firm_wage_offer_for_skill_5 = firm_wage_offer_for_skill_5;
    
    
    rc = MB_AddMessage(b_vacancies, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'vacancies' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_vacancies* getInternalMessage_vacancies(void)
{
    static m_vacancies *msg_prev = NULL;
    m_vacancies *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_vacancies); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'vacancies' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'vacancies' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_vacancies, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'vacancies' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_vacancies * get_first_vacancies_message()
 * \brief Get the first vacancies message in the vacancies message list.
 * \return The first message in the list.
 */
m_vacancies * get_first_vacancies_message()
{
	return getInternalMessage_vacancies();
}

/** \fn xmachine_message_vacancies * get_next_vacancies_message(xmachine_message_vacancies * current)
 * \brief Get the next vacancies message in the vacancies message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_vacancies * get_next_vacancies_message(m_vacancies * current)
{
	return getInternalMessage_vacancies();
}

/** \fn void add_vacancies2_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5)
 * \brief Add vacancies2 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param firm_wage_offer_for_skill_1 Message variable.
 * \param firm_wage_offer_for_skill_2 Message variable.
 * \param firm_wage_offer_for_skill_3 Message variable.
 * \param firm_wage_offer_for_skill_4 Message variable.
 * \param firm_wage_offer_for_skill_5 Message variable.
 */
void add_vacancies2_message(int firm_id, int region_id, double firm_wage_offer_for_skill_1, double firm_wage_offer_for_skill_2, double firm_wage_offer_for_skill_3, double firm_wage_offer_for_skill_4, double firm_wage_offer_for_skill_5)
{
    int rc;
	m_vacancies2 msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.firm_wage_offer_for_skill_1 = firm_wage_offer_for_skill_1;
    msg.firm_wage_offer_for_skill_2 = firm_wage_offer_for_skill_2;
    msg.firm_wage_offer_for_skill_3 = firm_wage_offer_for_skill_3;
    msg.firm_wage_offer_for_skill_4 = firm_wage_offer_for_skill_4;
    msg.firm_wage_offer_for_skill_5 = firm_wage_offer_for_skill_5;
    
    
    rc = MB_AddMessage(b_vacancies2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'vacancies2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_vacancies2* getInternalMessage_vacancies2(void)
{
    static m_vacancies2 *msg_prev = NULL;
    m_vacancies2 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_vacancies2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'vacancies2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'vacancies2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_vacancies2, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'vacancies2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_vacancies2 * get_first_vacancies2_message()
 * \brief Get the first vacancies2 message in the vacancies2 message list.
 * \return The first message in the list.
 */
m_vacancies2 * get_first_vacancies2_message()
{
	return getInternalMessage_vacancies2();
}

/** \fn xmachine_message_vacancies2 * get_next_vacancies2_message(xmachine_message_vacancies2 * current)
 * \brief Get the next vacancies2 message in the vacancies2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_vacancies2 * get_next_vacancies2_message(m_vacancies2 * current)
{
	return getInternalMessage_vacancies2();
}

/** \fn void add_firing_message(int firm_id, int worker_id)
 * \brief Add firing message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 */
void add_firing_message(int firm_id, int worker_id)
{
    int rc;
	m_firing msg;
    
    msg.firm_id = firm_id;
    msg.worker_id = worker_id;
    
    
    rc = MB_AddMessage(b_firing, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firing' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firing' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firing* getInternalMessage_firing(void)
{
    static m_firing *msg_prev = NULL;
    m_firing *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firing); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firing' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firing' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firing, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firing' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firing' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_firing * get_first_firing_message()
 * \brief Get the first firing message in the firing message list.
 * \return The first message in the list.
 */
m_firing * get_first_firing_message()
{
	return getInternalMessage_firing();
}

/** \fn xmachine_message_firing * get_next_firing_message(xmachine_message_firing * current)
 * \brief Get the next firing message in the firing message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firing * get_next_firing_message(m_firing * current)
{
	return getInternalMessage_firing();
}

/** \fn void add_job_application_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill)
 * \brief Add job_application message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 */
void add_job_application_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill)
{
    int rc;
	m_job_application msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.specific_skill = specific_skill;
    
    
    rc = MB_AddMessage(b_job_application, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_application' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_application* getInternalMessage_job_application(void)
{
    static m_job_application *msg_prev = NULL;
    m_job_application *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_application); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_application' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_application' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_application, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_application' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_job_application * get_first_job_application_message()
 * \brief Get the first job_application message in the job_application message list.
 * \return The first message in the list.
 */
m_job_application * get_first_job_application_message()
{
	return getInternalMessage_job_application();
}

/** \fn xmachine_message_job_application * get_next_job_application_message(xmachine_message_job_application * current)
 * \brief Get the next job_application message in the job_application message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_application * get_next_job_application_message(m_job_application * current)
{
	return getInternalMessage_job_application();
}

/** \fn void add_job_application2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill)
 * \brief Add job_application2 message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 */
void add_job_application2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill)
{
    int rc;
	m_job_application2 msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.specific_skill = specific_skill;
    
    
    rc = MB_AddMessage(b_job_application2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_application2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_application2* getInternalMessage_job_application2(void)
{
    static m_job_application2 *msg_prev = NULL;
    m_job_application2 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_application2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_application2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_application2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_application2, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_application2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_job_application2 * get_first_job_application2_message()
 * \brief Get the first job_application2 message in the job_application2 message list.
 * \return The first message in the list.
 */
m_job_application2 * get_first_job_application2_message()
{
	return getInternalMessage_job_application2();
}

/** \fn xmachine_message_job_application2 * get_next_job_application2_message(xmachine_message_job_application2 * current)
 * \brief Get the next job_application2 message in the job_application2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_application2 * get_next_job_application2_message(m_job_application2 * current)
{
	return getInternalMessage_job_application2();
}

/** \fn void add_job_offer_message(int firm_id, int worker_id, int region_id, double wage_offer)
 * \brief Add job_offer message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param wage_offer Message variable.
 */
void add_job_offer_message(int firm_id, int worker_id, int region_id, double wage_offer)
{
    int rc;
	m_job_offer msg;
    
    msg.firm_id = firm_id;
    msg.worker_id = worker_id;
    msg.region_id = region_id;
    msg.wage_offer = wage_offer;
    
    
    rc = MB_AddMessage(b_job_offer, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_offer' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_offer* getInternalMessage_job_offer(void)
{
    static m_job_offer *msg_prev = NULL;
    m_job_offer *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_offer); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_offer' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_offer' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_offer, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_offer' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_job_offer * get_first_job_offer_message()
 * \brief Get the first job_offer message in the job_offer message list.
 * \return The first message in the list.
 */
m_job_offer * get_first_job_offer_message()
{
	return getInternalMessage_job_offer();
}

/** \fn xmachine_message_job_offer * get_next_job_offer_message(xmachine_message_job_offer * current)
 * \brief Get the next job_offer message in the job_offer message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_offer * get_next_job_offer_message(m_job_offer * current)
{
	return getInternalMessage_job_offer();
}

/** \fn void add_job_offer2_message(int firm_id, int worker_id, int region_id, double wage_offer)
 * \brief Add job_offer2 message by calling internal and processing.
 * \param firm_id Message variable.
 * \param worker_id Message variable.
 * \param region_id Message variable.
 * \param wage_offer Message variable.
 */
void add_job_offer2_message(int firm_id, int worker_id, int region_id, double wage_offer)
{
    int rc;
	m_job_offer2 msg;
    
    msg.firm_id = firm_id;
    msg.worker_id = worker_id;
    msg.region_id = region_id;
    msg.wage_offer = wage_offer;
    
    
    rc = MB_AddMessage(b_job_offer2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_offer2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_offer2* getInternalMessage_job_offer2(void)
{
    static m_job_offer2 *msg_prev = NULL;
    m_job_offer2 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_offer2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_offer2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_offer2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_offer2, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_offer2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_job_offer2 * get_first_job_offer2_message()
 * \brief Get the first job_offer2 message in the job_offer2 message list.
 * \return The first message in the list.
 */
m_job_offer2 * get_first_job_offer2_message()
{
	return getInternalMessage_job_offer2();
}

/** \fn xmachine_message_job_offer2 * get_next_job_offer2_message(xmachine_message_job_offer2 * current)
 * \brief Get the next job_offer2 message in the job_offer2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_offer2 * get_next_job_offer2_message(m_job_offer2 * current)
{
	return getInternalMessage_job_offer2();
}

/** \fn void add_job_acceptance_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill)
 * \brief Add job_acceptance message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 */
void add_job_acceptance_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill)
{
    int rc;
	m_job_acceptance msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.specific_skill = specific_skill;
    
    
    rc = MB_AddMessage(b_job_acceptance, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_acceptance* getInternalMessage_job_acceptance(void)
{
    static m_job_acceptance *msg_prev = NULL;
    m_job_acceptance *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_acceptance); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_acceptance' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_acceptance' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_acceptance, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_acceptance' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_job_acceptance * get_first_job_acceptance_message()
 * \brief Get the first job_acceptance message in the job_acceptance message list.
 * \return The first message in the list.
 */
m_job_acceptance * get_first_job_acceptance_message()
{
	return getInternalMessage_job_acceptance();
}

/** \fn xmachine_message_job_acceptance * get_next_job_acceptance_message(xmachine_message_job_acceptance * current)
 * \brief Get the next job_acceptance message in the job_acceptance message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_acceptance * get_next_job_acceptance_message(m_job_acceptance * current)
{
	return getInternalMessage_job_acceptance();
}

/** \fn void add_job_acceptance2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill)
 * \brief Add job_acceptance2 message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param specific_skill Message variable.
 */
void add_job_acceptance2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill)
{
    int rc;
	m_job_acceptance2 msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.specific_skill = specific_skill;
    
    
    rc = MB_AddMessage(b_job_acceptance2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'job_acceptance2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_job_acceptance2* getInternalMessage_job_acceptance2(void)
{
    static m_job_acceptance2 *msg_prev = NULL;
    m_job_acceptance2 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_job_acceptance2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'job_acceptance2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'job_acceptance2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_job_acceptance2, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'job_acceptance2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_job_acceptance2 * get_first_job_acceptance2_message()
 * \brief Get the first job_acceptance2 message in the job_acceptance2 message list.
 * \return The first message in the list.
 */
m_job_acceptance2 * get_first_job_acceptance2_message()
{
	return getInternalMessage_job_acceptance2();
}

/** \fn xmachine_message_job_acceptance2 * get_next_job_acceptance2_message(xmachine_message_job_acceptance2 * current)
 * \brief Get the next job_acceptance2 message in the job_acceptance2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_job_acceptance2 * get_next_job_acceptance2_message(m_job_acceptance2 * current)
{
	return getInternalMessage_job_acceptance2();
}

/** \fn void add_quitting_message(int worker_id, int firm_id)
 * \brief Add quitting message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 */
void add_quitting_message(int worker_id, int firm_id)
{
    int rc;
	m_quitting msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_quitting, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'quitting' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_quitting* getInternalMessage_quitting(void)
{
    static m_quitting *msg_prev = NULL;
    m_quitting *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_quitting); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'quitting' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'quitting' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_quitting, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'quitting' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_quitting * get_first_quitting_message()
 * \brief Get the first quitting message in the quitting message list.
 * \return The first message in the list.
 */
m_quitting * get_first_quitting_message()
{
	return getInternalMessage_quitting();
}

/** \fn xmachine_message_quitting * get_next_quitting_message(xmachine_message_quitting * current)
 * \brief Get the next quitting message in the quitting message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_quitting * get_next_quitting_message(m_quitting * current)
{
	return getInternalMessage_quitting();
}

/** \fn void add_quitting2_message(int worker_id, int firm_id)
 * \brief Add quitting2 message by calling internal and processing.
 * \param worker_id Message variable.
 * \param firm_id Message variable.
 */
void add_quitting2_message(int worker_id, int firm_id)
{
    int rc;
	m_quitting2 msg;
    
    msg.worker_id = worker_id;
    msg.firm_id = firm_id;
    
    
    rc = MB_AddMessage(b_quitting2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'quitting2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_quitting2* getInternalMessage_quitting2(void)
{
    static m_quitting2 *msg_prev = NULL;
    m_quitting2 *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_quitting2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'quitting2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'quitting2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_quitting2, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'quitting2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_quitting2 * get_first_quitting2_message()
 * \brief Get the first quitting2 message in the quitting2 message list.
 * \return The first message in the list.
 */
m_quitting2 * get_first_quitting2_message()
{
	return getInternalMessage_quitting2();
}

/** \fn xmachine_message_quitting2 * get_next_quitting2_message(xmachine_message_quitting2 * current)
 * \brief Get the next quitting2 message in the quitting2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_quitting2 * get_next_quitting2_message(m_quitting2 * current)
{
	return getInternalMessage_quitting2();
}

/** \fn void add_unemployment_notification_message(int gov_id, double last_labour_income)
 * \brief Add unemployment_notification message by calling internal and processing.
 * \param gov_id Message variable.
 * \param last_labour_income Message variable.
 */
void add_unemployment_notification_message(int gov_id, double last_labour_income)
{
    int rc;
	m_unemployment_notification msg;
    
    msg.gov_id = gov_id;
    msg.last_labour_income = last_labour_income;
    
    
    rc = MB_AddMessage(b_unemployment_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'unemployment_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'unemployment_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_unemployment_notification* getInternalMessage_unemployment_notification(void)
{
    static m_unemployment_notification *msg_prev = NULL;
    m_unemployment_notification *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_unemployment_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'unemployment_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'unemployment_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_unemployment_notification, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'unemployment_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_unemployment_notification * get_first_unemployment_notification_message()
 * \brief Get the first unemployment_notification message in the unemployment_notification message list.
 * \return The first message in the list.
 */
m_unemployment_notification * get_first_unemployment_notification_message()
{
	return getInternalMessage_unemployment_notification();
}

/** \fn xmachine_message_unemployment_notification * get_next_unemployment_notification_message(xmachine_message_unemployment_notification * current)
 * \brief Get the next unemployment_notification message in the unemployment_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_unemployment_notification * get_next_unemployment_notification_message(m_unemployment_notification * current)
{
	return getInternalMessage_unemployment_notification();
}

/** \fn void add_policy_announcement_message(int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double unemployment_benefit_pct, double hh_subsidy_payment, double firm_subsidy_payment, double hh_transfer_payment, double firm_transfer_payment)
 * \brief Add policy_announcement message by calling internal and processing.
 * \param gov_id Message variable.
 * \param tax_rate_corporate Message variable.
 * \param tax_rate_hh_labour Message variable.
 * \param tax_rate_hh_capital Message variable.
 * \param tax_rate_vat Message variable.
 * \param unemployment_benefit_pct Message variable.
 * \param hh_subsidy_payment Message variable.
 * \param firm_subsidy_payment Message variable.
 * \param hh_transfer_payment Message variable.
 * \param firm_transfer_payment Message variable.
 */
void add_policy_announcement_message(int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double unemployment_benefit_pct, double hh_subsidy_payment, double firm_subsidy_payment, double hh_transfer_payment, double firm_transfer_payment)
{
    int rc;
	m_policy_announcement msg;
    
    msg.gov_id = gov_id;
    msg.tax_rate_corporate = tax_rate_corporate;
    msg.tax_rate_hh_labour = tax_rate_hh_labour;
    msg.tax_rate_hh_capital = tax_rate_hh_capital;
    msg.tax_rate_vat = tax_rate_vat;
    msg.unemployment_benefit_pct = unemployment_benefit_pct;
    msg.hh_subsidy_payment = hh_subsidy_payment;
    msg.firm_subsidy_payment = firm_subsidy_payment;
    msg.hh_transfer_payment = hh_transfer_payment;
    msg.firm_transfer_payment = firm_transfer_payment;
    
    
    rc = MB_AddMessage(b_policy_announcement, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'policy_announcement' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_announcement' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_policy_announcement* getInternalMessage_policy_announcement(void)
{
    static m_policy_announcement *msg_prev = NULL;
    m_policy_announcement *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_policy_announcement); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'policy_announcement' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'policy_announcement' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_policy_announcement, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'policy_announcement' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_announcement' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_policy_announcement * get_first_policy_announcement_message()
 * \brief Get the first policy_announcement message in the policy_announcement message list.
 * \return The first message in the list.
 */
m_policy_announcement * get_first_policy_announcement_message()
{
	return getInternalMessage_policy_announcement();
}

/** \fn xmachine_message_policy_announcement * get_next_policy_announcement_message(xmachine_message_policy_announcement * current)
 * \brief Get the next policy_announcement message in the policy_announcement message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_policy_announcement * get_next_policy_announcement_message(m_policy_announcement * current)
{
	return getInternalMessage_policy_announcement();
}

/** \fn void add_tax_payment_message(int gov_id, double tax_payment)
 * \brief Add tax_payment message by calling internal and processing.
 * \param gov_id Message variable.
 * \param tax_payment Message variable.
 */
void add_tax_payment_message(int gov_id, double tax_payment)
{
    int rc;
	m_tax_payment msg;
    
    msg.gov_id = gov_id;
    msg.tax_payment = tax_payment;
    
    
    rc = MB_AddMessage(b_tax_payment, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'tax_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_payment' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'tax_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_tax_payment* getInternalMessage_tax_payment(void)
{
    static m_tax_payment *msg_prev = NULL;
    m_tax_payment *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_tax_payment); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'tax_payment' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'tax_payment' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_tax_payment, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'tax_payment' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_payment' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_tax_payment * get_first_tax_payment_message()
 * \brief Get the first tax_payment message in the tax_payment message list.
 * \return The first message in the list.
 */
m_tax_payment * get_first_tax_payment_message()
{
	return getInternalMessage_tax_payment();
}

/** \fn xmachine_message_tax_payment * get_next_tax_payment_message(xmachine_message_tax_payment * current)
 * \brief Get the next tax_payment message in the tax_payment message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_tax_payment * get_next_tax_payment_message(m_tax_payment * current)
{
	return getInternalMessage_tax_payment();
}

/** \fn void add_hh_transfer_notification_message(int gov_id)
 * \brief Add hh_transfer_notification message by calling internal and processing.
 * \param gov_id Message variable.
 */
void add_hh_transfer_notification_message(int gov_id)
{
    int rc;
	m_hh_transfer_notification msg;
    
    msg.gov_id = gov_id;
    
    
    rc = MB_AddMessage(b_hh_transfer_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'hh_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_hh_transfer_notification* getInternalMessage_hh_transfer_notification(void)
{
    static m_hh_transfer_notification *msg_prev = NULL;
    m_hh_transfer_notification *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_hh_transfer_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'hh_transfer_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'hh_transfer_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_hh_transfer_notification, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'hh_transfer_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_hh_transfer_notification * get_first_hh_transfer_notification_message()
 * \brief Get the first hh_transfer_notification message in the hh_transfer_notification message list.
 * \return The first message in the list.
 */
m_hh_transfer_notification * get_first_hh_transfer_notification_message()
{
	return getInternalMessage_hh_transfer_notification();
}

/** \fn xmachine_message_hh_transfer_notification * get_next_hh_transfer_notification_message(xmachine_message_hh_transfer_notification * current)
 * \brief Get the next hh_transfer_notification message in the hh_transfer_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_hh_transfer_notification * get_next_hh_transfer_notification_message(m_hh_transfer_notification * current)
{
	return getInternalMessage_hh_transfer_notification();
}

/** \fn void add_hh_subsidy_notification_message(int gov_id)
 * \brief Add hh_subsidy_notification message by calling internal and processing.
 * \param gov_id Message variable.
 */
void add_hh_subsidy_notification_message(int gov_id)
{
    int rc;
	m_hh_subsidy_notification msg;
    
    msg.gov_id = gov_id;
    
    
    rc = MB_AddMessage(b_hh_subsidy_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'hh_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_hh_subsidy_notification* getInternalMessage_hh_subsidy_notification(void)
{
    static m_hh_subsidy_notification *msg_prev = NULL;
    m_hh_subsidy_notification *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_hh_subsidy_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'hh_subsidy_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'hh_subsidy_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_hh_subsidy_notification, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'hh_subsidy_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_hh_subsidy_notification * get_first_hh_subsidy_notification_message()
 * \brief Get the first hh_subsidy_notification message in the hh_subsidy_notification message list.
 * \return The first message in the list.
 */
m_hh_subsidy_notification * get_first_hh_subsidy_notification_message()
{
	return getInternalMessage_hh_subsidy_notification();
}

/** \fn xmachine_message_hh_subsidy_notification * get_next_hh_subsidy_notification_message(xmachine_message_hh_subsidy_notification * current)
 * \brief Get the next hh_subsidy_notification message in the hh_subsidy_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_hh_subsidy_notification * get_next_hh_subsidy_notification_message(m_hh_subsidy_notification * current)
{
	return getInternalMessage_hh_subsidy_notification();
}

/** \fn void add_firm_transfer_notification_message(int gov_id)
 * \brief Add firm_transfer_notification message by calling internal and processing.
 * \param gov_id Message variable.
 */
void add_firm_transfer_notification_message(int gov_id)
{
    int rc;
	m_firm_transfer_notification msg;
    
    msg.gov_id = gov_id;
    
    
    rc = MB_AddMessage(b_firm_transfer_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_transfer_notification* getInternalMessage_firm_transfer_notification(void)
{
    static m_firm_transfer_notification *msg_prev = NULL;
    m_firm_transfer_notification *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_transfer_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_transfer_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_transfer_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_transfer_notification, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_transfer_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_firm_transfer_notification * get_first_firm_transfer_notification_message()
 * \brief Get the first firm_transfer_notification message in the firm_transfer_notification message list.
 * \return The first message in the list.
 */
m_firm_transfer_notification * get_first_firm_transfer_notification_message()
{
	return getInternalMessage_firm_transfer_notification();
}

/** \fn xmachine_message_firm_transfer_notification * get_next_firm_transfer_notification_message(xmachine_message_firm_transfer_notification * current)
 * \brief Get the next firm_transfer_notification message in the firm_transfer_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_transfer_notification * get_next_firm_transfer_notification_message(m_firm_transfer_notification * current)
{
	return getInternalMessage_firm_transfer_notification();
}

/** \fn void add_firm_subsidy_notification_message(int gov_id)
 * \brief Add firm_subsidy_notification message by calling internal and processing.
 * \param gov_id Message variable.
 */
void add_firm_subsidy_notification_message(int gov_id)
{
    int rc;
	m_firm_subsidy_notification msg;
    
    msg.gov_id = gov_id;
    
    
    rc = MB_AddMessage(b_firm_subsidy_notification, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_subsidy_notification* getInternalMessage_firm_subsidy_notification(void)
{
    static m_firm_subsidy_notification *msg_prev = NULL;
    m_firm_subsidy_notification *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_subsidy_notification); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_subsidy_notification' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_subsidy_notification' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_subsidy_notification, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_subsidy_notification' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_firm_subsidy_notification * get_first_firm_subsidy_notification_message()
 * \brief Get the first firm_subsidy_notification message in the firm_subsidy_notification message list.
 * \return The first message in the list.
 */
m_firm_subsidy_notification * get_first_firm_subsidy_notification_message()
{
	return getInternalMessage_firm_subsidy_notification();
}

/** \fn xmachine_message_firm_subsidy_notification * get_next_firm_subsidy_notification_message(xmachine_message_firm_subsidy_notification * current)
 * \brief Get the next firm_subsidy_notification message in the firm_subsidy_notification message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_subsidy_notification * get_next_firm_subsidy_notification_message(m_firm_subsidy_notification * current)
{
	return getInternalMessage_firm_subsidy_notification();
}

/** \fn void add_firm_send_data_message(int firm_id, int region_id, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double cum_revenue, double capital_costs, double net_earnings, double total_debt, double total_assets, double equity, double price, double price_last_month, double total_supply, double cum_total_sold_quantity, double output, double planned_output, int age, double firm_productivity, double firm_productivity_progress)
 * \brief Add firm_send_data message by calling internal and processing.
 * \param firm_id Message variable.
 * \param region_id Message variable.
 * \param vacancies Message variable.
 * \param employees Message variable.
 * \param employees_skill_1 Message variable.
 * \param employees_skill_2 Message variable.
 * \param employees_skill_3 Message variable.
 * \param employees_skill_4 Message variable.
 * \param employees_skill_5 Message variable.
 * \param average_wage Message variable.
 * \param average_s_skill Message variable.
 * \param average_s_skill_1 Message variable.
 * \param average_s_skill_2 Message variable.
 * \param average_s_skill_3 Message variable.
 * \param average_s_skill_4 Message variable.
 * \param average_s_skill_5 Message variable.
 * \param cum_revenue Message variable.
 * \param capital_costs Message variable.
 * \param net_earnings Message variable.
 * \param total_debt Message variable.
 * \param total_assets Message variable.
 * \param equity Message variable.
 * \param price Message variable.
 * \param price_last_month Message variable.
 * \param total_supply Message variable.
 * \param cum_total_sold_quantity Message variable.
 * \param output Message variable.
 * \param planned_output Message variable.
 * \param age Message variable.
 * \param firm_productivity Message variable.
 * \param firm_productivity_progress Message variable.
 */
void add_firm_send_data_message(int firm_id, int region_id, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double cum_revenue, double capital_costs, double net_earnings, double total_debt, double total_assets, double equity, double price, double price_last_month, double total_supply, double cum_total_sold_quantity, double output, double planned_output, int age, double firm_productivity, double firm_productivity_progress)
{
    int rc;
	m_firm_send_data msg;
    
    msg.firm_id = firm_id;
    msg.region_id = region_id;
    msg.vacancies = vacancies;
    msg.employees = employees;
    msg.employees_skill_1 = employees_skill_1;
    msg.employees_skill_2 = employees_skill_2;
    msg.employees_skill_3 = employees_skill_3;
    msg.employees_skill_4 = employees_skill_4;
    msg.employees_skill_5 = employees_skill_5;
    msg.average_wage = average_wage;
    msg.average_s_skill = average_s_skill;
    msg.average_s_skill_1 = average_s_skill_1;
    msg.average_s_skill_2 = average_s_skill_2;
    msg.average_s_skill_3 = average_s_skill_3;
    msg.average_s_skill_4 = average_s_skill_4;
    msg.average_s_skill_5 = average_s_skill_5;
    msg.cum_revenue = cum_revenue;
    msg.capital_costs = capital_costs;
    msg.net_earnings = net_earnings;
    msg.total_debt = total_debt;
    msg.total_assets = total_assets;
    msg.equity = equity;
    msg.price = price;
    msg.price_last_month = price_last_month;
    msg.total_supply = total_supply;
    msg.cum_total_sold_quantity = cum_total_sold_quantity;
    msg.output = output;
    msg.planned_output = planned_output;
    msg.age = age;
    msg.firm_productivity = firm_productivity;
    msg.firm_productivity_progress = firm_productivity_progress;
    
    
    rc = MB_AddMessage(b_firm_send_data, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_send_data' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_send_data' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_send_data* getInternalMessage_firm_send_data(void)
{
    static m_firm_send_data *msg_prev = NULL;
    m_firm_send_data *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_send_data); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_send_data' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_send_data' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_send_data, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_send_data' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_send_data' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_firm_send_data * get_first_firm_send_data_message()
 * \brief Get the first firm_send_data message in the firm_send_data message list.
 * \return The first message in the list.
 */
m_firm_send_data * get_first_firm_send_data_message()
{
	return getInternalMessage_firm_send_data();
}

/** \fn xmachine_message_firm_send_data * get_next_firm_send_data_message(xmachine_message_firm_send_data * current)
 * \brief Get the next firm_send_data message in the firm_send_data message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_send_data * get_next_firm_send_data_message(m_firm_send_data * current)
{
	return getInternalMessage_firm_send_data();
}

/** \fn void add_household_send_data_message(int household_id, int region_id, int general_skill, int employment_status, double wage, double specific_skill)
 * \brief Add household_send_data message by calling internal and processing.
 * \param household_id Message variable.
 * \param region_id Message variable.
 * \param general_skill Message variable.
 * \param employment_status Message variable.
 * \param wage Message variable.
 * \param specific_skill Message variable.
 */
void add_household_send_data_message(int household_id, int region_id, int general_skill, int employment_status, double wage, double specific_skill)
{
    int rc;
	m_household_send_data msg;
    
    msg.household_id = household_id;
    msg.region_id = region_id;
    msg.general_skill = general_skill;
    msg.employment_status = employment_status;
    msg.wage = wage;
    msg.specific_skill = specific_skill;
    
    
    rc = MB_AddMessage(b_household_send_data, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'household_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_send_data' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_send_data' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_household_send_data* getInternalMessage_household_send_data(void)
{
    static m_household_send_data *msg_prev = NULL;
    m_household_send_data *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_household_send_data); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'household_send_data' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'household_send_data' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_household_send_data, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'household_send_data' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_send_data' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_household_send_data * get_first_household_send_data_message()
 * \brief Get the first household_send_data message in the household_send_data message list.
 * \return The first message in the list.
 */
m_household_send_data * get_first_household_send_data_message()
{
	return getInternalMessage_household_send_data();
}

/** \fn xmachine_message_household_send_data * get_next_household_send_data_message(xmachine_message_household_send_data * current)
 * \brief Get the next household_send_data message in the household_send_data message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_household_send_data * get_next_household_send_data_message(m_household_send_data * current)
{
	return getInternalMessage_household_send_data();
}

/** \fn void add_mall_data_message(int mall_id, int firm_region, int household_region, double export_volume, double export_value, double export_previous_value)
 * \brief Add mall_data message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_region Message variable.
 * \param household_region Message variable.
 * \param export_volume Message variable.
 * \param export_value Message variable.
 * \param export_previous_value Message variable.
 */
void add_mall_data_message(int mall_id, int firm_region, int household_region, double export_volume, double export_value, double export_previous_value)
{
    int rc;
	m_mall_data msg;
    
    msg.mall_id = mall_id;
    msg.firm_region = firm_region;
    msg.household_region = household_region;
    msg.export_volume = export_volume;
    msg.export_value = export_value;
    msg.export_previous_value = export_previous_value;
    
    
    rc = MB_AddMessage(b_mall_data, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'mall_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mall_data' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mall_data' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_mall_data* getInternalMessage_mall_data(void)
{
    static m_mall_data *msg_prev = NULL;
    m_mall_data *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_mall_data); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'mall_data' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'mall_data' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_mall_data, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'mall_data' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mall_data' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_mall_data * get_first_mall_data_message()
 * \brief Get the first mall_data message in the mall_data message list.
 * \return The first message in the list.
 */
m_mall_data * get_first_mall_data_message()
{
	return getInternalMessage_mall_data();
}

/** \fn xmachine_message_mall_data * get_next_mall_data_message(xmachine_message_mall_data * current)
 * \brief Get the next mall_data message in the mall_data message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_mall_data * get_next_mall_data_message(m_mall_data * current)
{
	return getInternalMessage_mall_data();
}

/** \fn void add_eurostat_send_specific_skills_message(int region_id, double specific_skill_1, double specific_skill_2, double specific_skill_3, double specific_skill_4, double specific_skill_5, double productivity_progress)
 * \brief Add eurostat_send_specific_skills message by calling internal and processing.
 * \param region_id Message variable.
 * \param specific_skill_1 Message variable.
 * \param specific_skill_2 Message variable.
 * \param specific_skill_3 Message variable.
 * \param specific_skill_4 Message variable.
 * \param specific_skill_5 Message variable.
 * \param productivity_progress Message variable.
 */
void add_eurostat_send_specific_skills_message(int region_id, double specific_skill_1, double specific_skill_2, double specific_skill_3, double specific_skill_4, double specific_skill_5, double productivity_progress)
{
    int rc;
	m_eurostat_send_specific_skills msg;
    
    msg.region_id = region_id;
    msg.specific_skill_1 = specific_skill_1;
    msg.specific_skill_2 = specific_skill_2;
    msg.specific_skill_3 = specific_skill_3;
    msg.specific_skill_4 = specific_skill_4;
    msg.specific_skill_5 = specific_skill_5;
    msg.productivity_progress = productivity_progress;
    
    
    rc = MB_AddMessage(b_eurostat_send_specific_skills, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'eurostat_send_specific_skills' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_eurostat_send_specific_skills* getInternalMessage_eurostat_send_specific_skills(void)
{
    static m_eurostat_send_specific_skills *msg_prev = NULL;
    m_eurostat_send_specific_skills *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_eurostat_send_specific_skills); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'eurostat_send_specific_skills' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_eurostat_send_specific_skills, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'eurostat_send_specific_skills' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_eurostat_send_specific_skills * get_first_eurostat_send_specific_skills_message()
 * \brief Get the first eurostat_send_specific_skills message in the eurostat_send_specific_skills message list.
 * \return The first message in the list.
 */
m_eurostat_send_specific_skills * get_first_eurostat_send_specific_skills_message()
{
	return getInternalMessage_eurostat_send_specific_skills();
}

/** \fn xmachine_message_eurostat_send_specific_skills * get_next_eurostat_send_specific_skills_message(xmachine_message_eurostat_send_specific_skills * current)
 * \brief Get the next eurostat_send_specific_skills message in the eurostat_send_specific_skills message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_eurostat_send_specific_skills * get_next_eurostat_send_specific_skills_message(m_eurostat_send_specific_skills * current)
{
	return getInternalMessage_eurostat_send_specific_skills();
}

/** \fn void add_mean_wage_for_government_message(int gov_id, double mean_wage)
 * \brief Add mean_wage_for_government message by calling internal and processing.
 * \param gov_id Message variable.
 * \param mean_wage Message variable.
 */
void add_mean_wage_for_government_message(int gov_id, double mean_wage)
{
    int rc;
	m_mean_wage_for_government msg;
    
    msg.gov_id = gov_id;
    msg.mean_wage = mean_wage;
    
    
    rc = MB_AddMessage(b_mean_wage_for_government, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'mean_wage_for_government' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mean_wage_for_government' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mean_wage_for_government' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_mean_wage_for_government* getInternalMessage_mean_wage_for_government(void)
{
    static m_mean_wage_for_government *msg_prev = NULL;
    m_mean_wage_for_government *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_mean_wage_for_government); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'mean_wage_for_government' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'mean_wage_for_government' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_mean_wage_for_government, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'mean_wage_for_government' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mean_wage_for_government' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_mean_wage_for_government * get_first_mean_wage_for_government_message()
 * \brief Get the first mean_wage_for_government message in the mean_wage_for_government message list.
 * \return The first message in the list.
 */
m_mean_wage_for_government * get_first_mean_wage_for_government_message()
{
	return getInternalMessage_mean_wage_for_government();
}

/** \fn xmachine_message_mean_wage_for_government * get_next_mean_wage_for_government_message(xmachine_message_mean_wage_for_government * current)
 * \brief Get the next mean_wage_for_government message in the mean_wage_for_government message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_mean_wage_for_government * get_next_mean_wage_for_government_message(m_mean_wage_for_government * current)
{
	return getInternalMessage_mean_wage_for_government();
}

/** \fn void add_data_for_government_message(int region_id, double gdp, double mean_wage)
 * \brief Add data_for_government message by calling internal and processing.
 * \param region_id Message variable.
 * \param gdp Message variable.
 * \param mean_wage Message variable.
 */
void add_data_for_government_message(int region_id, double gdp, double mean_wage)
{
    int rc;
	m_data_for_government msg;
    
    msg.region_id = region_id;
    msg.gdp = gdp;
    msg.mean_wage = mean_wage;
    
    
    rc = MB_AddMessage(b_data_for_government, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'data_for_government' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'data_for_government' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'data_for_government' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_data_for_government* getInternalMessage_data_for_government(void)
{
    static m_data_for_government *msg_prev = NULL;
    m_data_for_government *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_data_for_government); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'data_for_government' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'data_for_government' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_data_for_government, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'data_for_government' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'data_for_government' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_data_for_government * get_first_data_for_government_message()
 * \brief Get the first data_for_government message in the data_for_government message list.
 * \return The first message in the list.
 */
m_data_for_government * get_first_data_for_government_message()
{
	return getInternalMessage_data_for_government();
}

/** \fn xmachine_message_data_for_government * get_next_data_for_government_message(xmachine_message_data_for_government * current)
 * \brief Get the next data_for_government message in the data_for_government message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_data_for_government * get_next_data_for_government_message(m_data_for_government * current)
{
	return getInternalMessage_data_for_government();
}

/** \fn void add_firm_balance_sheet_message(double payment_account, double total_value_local_inventory, double total_value_capital_stock, double total_debt, int current_shares_outstanding, double cum_revenue, double labour_costs, double capital_costs, double tax_payment, double total_debt_installment_payment, double total_interest_payment, double total_dividend_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
 * \brief Add firm_balance_sheet message by calling internal and processing.
 * \param payment_account Message variable.
 * \param total_value_local_inventory Message variable.
 * \param total_value_capital_stock Message variable.
 * \param total_debt Message variable.
 * \param current_shares_outstanding Message variable.
 * \param cum_revenue Message variable.
 * \param labour_costs Message variable.
 * \param capital_costs Message variable.
 * \param tax_payment Message variable.
 * \param total_debt_installment_payment Message variable.
 * \param total_interest_payment Message variable.
 * \param total_dividend_payment Message variable.
 * \param total_assets Message variable.
 * \param total_liabilities Message variable.
 * \param total_income Message variable.
 * \param total_expenses Message variable.
 */
void add_firm_balance_sheet_message(double payment_account, double total_value_local_inventory, double total_value_capital_stock, double total_debt, int current_shares_outstanding, double cum_revenue, double labour_costs, double capital_costs, double tax_payment, double total_debt_installment_payment, double total_interest_payment, double total_dividend_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
{
    int rc;
	m_firm_balance_sheet msg;
    
    msg.payment_account = payment_account;
    msg.total_value_local_inventory = total_value_local_inventory;
    msg.total_value_capital_stock = total_value_capital_stock;
    msg.total_debt = total_debt;
    msg.current_shares_outstanding = current_shares_outstanding;
    msg.cum_revenue = cum_revenue;
    msg.labour_costs = labour_costs;
    msg.capital_costs = capital_costs;
    msg.tax_payment = tax_payment;
    msg.total_debt_installment_payment = total_debt_installment_payment;
    msg.total_interest_payment = total_interest_payment;
    msg.total_dividend_payment = total_dividend_payment;
    msg.total_assets = total_assets;
    msg.total_liabilities = total_liabilities;
    msg.total_income = total_income;
    msg.total_expenses = total_expenses;
    
    
    rc = MB_AddMessage(b_firm_balance_sheet, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'firm_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_firm_balance_sheet* getInternalMessage_firm_balance_sheet(void)
{
    static m_firm_balance_sheet *msg_prev = NULL;
    m_firm_balance_sheet *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_firm_balance_sheet); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'firm_balance_sheet' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'firm_balance_sheet' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_firm_balance_sheet, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'firm_balance_sheet' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_balance_sheet' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_firm_balance_sheet * get_first_firm_balance_sheet_message()
 * \brief Get the first firm_balance_sheet message in the firm_balance_sheet message list.
 * \return The first message in the list.
 */
m_firm_balance_sheet * get_first_firm_balance_sheet_message()
{
	return getInternalMessage_firm_balance_sheet();
}

/** \fn xmachine_message_firm_balance_sheet * get_next_firm_balance_sheet_message(xmachine_message_firm_balance_sheet * current)
 * \brief Get the next firm_balance_sheet message in the firm_balance_sheet message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_firm_balance_sheet * get_next_firm_balance_sheet_message(m_firm_balance_sheet * current)
{
	return getInternalMessage_firm_balance_sheet();
}

/** \fn void add_household_balance_sheet_message(double payment_account, double gov_bond_holdings, int nr_gov_bonds, int nr_firm_shares, double wage, double gov_interest, double stock_sales, double cum_total_dividends, double monthly_consumption_expenditure, double tax_payment, double stock_purchases, double total_assets, double total_liabilities, double total_income, double total_expenses)
 * \brief Add household_balance_sheet message by calling internal and processing.
 * \param payment_account Message variable.
 * \param gov_bond_holdings Message variable.
 * \param nr_gov_bonds Message variable.
 * \param nr_firm_shares Message variable.
 * \param wage Message variable.
 * \param gov_interest Message variable.
 * \param stock_sales Message variable.
 * \param cum_total_dividends Message variable.
 * \param monthly_consumption_expenditure Message variable.
 * \param tax_payment Message variable.
 * \param stock_purchases Message variable.
 * \param total_assets Message variable.
 * \param total_liabilities Message variable.
 * \param total_income Message variable.
 * \param total_expenses Message variable.
 */
void add_household_balance_sheet_message(double payment_account, double gov_bond_holdings, int nr_gov_bonds, int nr_firm_shares, double wage, double gov_interest, double stock_sales, double cum_total_dividends, double monthly_consumption_expenditure, double tax_payment, double stock_purchases, double total_assets, double total_liabilities, double total_income, double total_expenses)
{
    int rc;
	m_household_balance_sheet msg;
    
    msg.payment_account = payment_account;
    msg.gov_bond_holdings = gov_bond_holdings;
    msg.nr_gov_bonds = nr_gov_bonds;
    msg.nr_firm_shares = nr_firm_shares;
    msg.wage = wage;
    msg.gov_interest = gov_interest;
    msg.stock_sales = stock_sales;
    msg.cum_total_dividends = cum_total_dividends;
    msg.monthly_consumption_expenditure = monthly_consumption_expenditure;
    msg.tax_payment = tax_payment;
    msg.stock_purchases = stock_purchases;
    msg.total_assets = total_assets;
    msg.total_liabilities = total_liabilities;
    msg.total_income = total_income;
    msg.total_expenses = total_expenses;
    
    
    rc = MB_AddMessage(b_household_balance_sheet, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'household_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_balance_sheet' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_household_balance_sheet* getInternalMessage_household_balance_sheet(void)
{
    static m_household_balance_sheet *msg_prev = NULL;
    m_household_balance_sheet *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_household_balance_sheet); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'household_balance_sheet' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'household_balance_sheet' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_household_balance_sheet, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'household_balance_sheet' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_balance_sheet' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_household_balance_sheet * get_first_household_balance_sheet_message()
 * \brief Get the first household_balance_sheet message in the household_balance_sheet message list.
 * \return The first message in the list.
 */
m_household_balance_sheet * get_first_household_balance_sheet_message()
{
	return getInternalMessage_household_balance_sheet();
}

/** \fn xmachine_message_household_balance_sheet * get_next_household_balance_sheet_message(xmachine_message_household_balance_sheet * current)
 * \brief Get the next household_balance_sheet message in the household_balance_sheet message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_household_balance_sheet * get_next_household_balance_sheet_message(m_household_balance_sheet * current)
{
	return getInternalMessage_household_balance_sheet();
}

/** \fn void add_igfirm_balance_sheet_message(double payment_account, double total_debt, int current_shares_outstanding, double cum_revenue, double labour_costs, double energy_costs, double tax_payment, double total_debt_installment_payment, double total_interest_payment, double total_dividend_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
 * \brief Add igfirm_balance_sheet message by calling internal and processing.
 * \param payment_account Message variable.
 * \param total_debt Message variable.
 * \param current_shares_outstanding Message variable.
 * \param cum_revenue Message variable.
 * \param labour_costs Message variable.
 * \param energy_costs Message variable.
 * \param tax_payment Message variable.
 * \param total_debt_installment_payment Message variable.
 * \param total_interest_payment Message variable.
 * \param total_dividend_payment Message variable.
 * \param total_assets Message variable.
 * \param total_liabilities Message variable.
 * \param total_income Message variable.
 * \param total_expenses Message variable.
 */
void add_igfirm_balance_sheet_message(double payment_account, double total_debt, int current_shares_outstanding, double cum_revenue, double labour_costs, double energy_costs, double tax_payment, double total_debt_installment_payment, double total_interest_payment, double total_dividend_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
{
    int rc;
	m_igfirm_balance_sheet msg;
    
    msg.payment_account = payment_account;
    msg.total_debt = total_debt;
    msg.current_shares_outstanding = current_shares_outstanding;
    msg.cum_revenue = cum_revenue;
    msg.labour_costs = labour_costs;
    msg.energy_costs = energy_costs;
    msg.tax_payment = tax_payment;
    msg.total_debt_installment_payment = total_debt_installment_payment;
    msg.total_interest_payment = total_interest_payment;
    msg.total_dividend_payment = total_dividend_payment;
    msg.total_assets = total_assets;
    msg.total_liabilities = total_liabilities;
    msg.total_income = total_income;
    msg.total_expenses = total_expenses;
    
    
    rc = MB_AddMessage(b_igfirm_balance_sheet, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'igfirm_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'igfirm_balance_sheet' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'igfirm_balance_sheet' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_igfirm_balance_sheet* getInternalMessage_igfirm_balance_sheet(void)
{
    static m_igfirm_balance_sheet *msg_prev = NULL;
    m_igfirm_balance_sheet *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_igfirm_balance_sheet); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'igfirm_balance_sheet' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'igfirm_balance_sheet' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_igfirm_balance_sheet, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'igfirm_balance_sheet' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'igfirm_balance_sheet' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_igfirm_balance_sheet * get_first_igfirm_balance_sheet_message()
 * \brief Get the first igfirm_balance_sheet message in the igfirm_balance_sheet message list.
 * \return The first message in the list.
 */
m_igfirm_balance_sheet * get_first_igfirm_balance_sheet_message()
{
	return getInternalMessage_igfirm_balance_sheet();
}

/** \fn xmachine_message_igfirm_balance_sheet * get_next_igfirm_balance_sheet_message(xmachine_message_igfirm_balance_sheet * current)
 * \brief Get the next igfirm_balance_sheet message in the igfirm_balance_sheet message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_igfirm_balance_sheet * get_next_igfirm_balance_sheet_message(m_igfirm_balance_sheet * current)
{
	return getInternalMessage_igfirm_balance_sheet();
}

/** \fn void add_bank_balance_sheet_message(double cash, double total_credit, double deposits, double ecb_debt, double firm_loan_installments, double firm_interest_payments, double firm_loan_issues, double ecb_interest_payment, double dividend_payment, double tax_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
 * \brief Add bank_balance_sheet message by calling internal and processing.
 * \param cash Message variable.
 * \param total_credit Message variable.
 * \param deposits Message variable.
 * \param ecb_debt Message variable.
 * \param firm_loan_installments Message variable.
 * \param firm_interest_payments Message variable.
 * \param firm_loan_issues Message variable.
 * \param ecb_interest_payment Message variable.
 * \param dividend_payment Message variable.
 * \param tax_payment Message variable.
 * \param total_assets Message variable.
 * \param total_liabilities Message variable.
 * \param total_income Message variable.
 * \param total_expenses Message variable.
 */
void add_bank_balance_sheet_message(double cash, double total_credit, double deposits, double ecb_debt, double firm_loan_installments, double firm_interest_payments, double firm_loan_issues, double ecb_interest_payment, double dividend_payment, double tax_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
{
    int rc;
	m_bank_balance_sheet msg;
    
    msg.cash = cash;
    msg.total_credit = total_credit;
    msg.deposits = deposits;
    msg.ecb_debt = ecb_debt;
    msg.firm_loan_installments = firm_loan_installments;
    msg.firm_interest_payments = firm_interest_payments;
    msg.firm_loan_issues = firm_loan_issues;
    msg.ecb_interest_payment = ecb_interest_payment;
    msg.dividend_payment = dividend_payment;
    msg.tax_payment = tax_payment;
    msg.total_assets = total_assets;
    msg.total_liabilities = total_liabilities;
    msg.total_income = total_income;
    msg.total_expenses = total_expenses;
    
    
    rc = MB_AddMessage(b_bank_balance_sheet, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'bank_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_bank_balance_sheet* getInternalMessage_bank_balance_sheet(void)
{
    static m_bank_balance_sheet *msg_prev = NULL;
    m_bank_balance_sheet *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_bank_balance_sheet); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'bank_balance_sheet' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'bank_balance_sheet' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_bank_balance_sheet, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'bank_balance_sheet' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_balance_sheet' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_bank_balance_sheet * get_first_bank_balance_sheet_message()
 * \brief Get the first bank_balance_sheet message in the bank_balance_sheet message list.
 * \return The first message in the list.
 */
m_bank_balance_sheet * get_first_bank_balance_sheet_message()
{
	return getInternalMessage_bank_balance_sheet();
}

/** \fn xmachine_message_bank_balance_sheet * get_next_bank_balance_sheet_message(xmachine_message_bank_balance_sheet * current)
 * \brief Get the next bank_balance_sheet message in the bank_balance_sheet message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_bank_balance_sheet * get_next_bank_balance_sheet_message(m_bank_balance_sheet * current)
{
	return getInternalMessage_bank_balance_sheet();
}

/** \fn void add_gov_balance_sheet_message(double payment_account, double value_bonds_outstanding, int nr_bonds_outstanding, double monthly_tax_revenues, double total_bond_financing, double monthly_investment_expenditure, double monthly_consumption_expenditure, double monthly_benefit_payment, double monthly_subsidy_payment, double monthly_transfer_payment, double monthly_bond_interest_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
 * \brief Add gov_balance_sheet message by calling internal and processing.
 * \param payment_account Message variable.
 * \param value_bonds_outstanding Message variable.
 * \param nr_bonds_outstanding Message variable.
 * \param monthly_tax_revenues Message variable.
 * \param total_bond_financing Message variable.
 * \param monthly_investment_expenditure Message variable.
 * \param monthly_consumption_expenditure Message variable.
 * \param monthly_benefit_payment Message variable.
 * \param monthly_subsidy_payment Message variable.
 * \param monthly_transfer_payment Message variable.
 * \param monthly_bond_interest_payment Message variable.
 * \param total_assets Message variable.
 * \param total_liabilities Message variable.
 * \param total_income Message variable.
 * \param total_expenses Message variable.
 */
void add_gov_balance_sheet_message(double payment_account, double value_bonds_outstanding, int nr_bonds_outstanding, double monthly_tax_revenues, double total_bond_financing, double monthly_investment_expenditure, double monthly_consumption_expenditure, double monthly_benefit_payment, double monthly_subsidy_payment, double monthly_transfer_payment, double monthly_bond_interest_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
{
    int rc;
	m_gov_balance_sheet msg;
    
    msg.payment_account = payment_account;
    msg.value_bonds_outstanding = value_bonds_outstanding;
    msg.nr_bonds_outstanding = nr_bonds_outstanding;
    msg.monthly_tax_revenues = monthly_tax_revenues;
    msg.total_bond_financing = total_bond_financing;
    msg.monthly_investment_expenditure = monthly_investment_expenditure;
    msg.monthly_consumption_expenditure = monthly_consumption_expenditure;
    msg.monthly_benefit_payment = monthly_benefit_payment;
    msg.monthly_subsidy_payment = monthly_subsidy_payment;
    msg.monthly_transfer_payment = monthly_transfer_payment;
    msg.monthly_bond_interest_payment = monthly_bond_interest_payment;
    msg.total_assets = total_assets;
    msg.total_liabilities = total_liabilities;
    msg.total_income = total_income;
    msg.total_expenses = total_expenses;
    
    
    rc = MB_AddMessage(b_gov_balance_sheet, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'gov_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_gov_balance_sheet* getInternalMessage_gov_balance_sheet(void)
{
    static m_gov_balance_sheet *msg_prev = NULL;
    m_gov_balance_sheet *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_gov_balance_sheet); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'gov_balance_sheet' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'gov_balance_sheet' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_gov_balance_sheet, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'gov_balance_sheet' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'gov_balance_sheet' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_gov_balance_sheet * get_first_gov_balance_sheet_message()
 * \brief Get the first gov_balance_sheet message in the gov_balance_sheet message list.
 * \return The first message in the list.
 */
m_gov_balance_sheet * get_first_gov_balance_sheet_message()
{
	return getInternalMessage_gov_balance_sheet();
}

/** \fn xmachine_message_gov_balance_sheet * get_next_gov_balance_sheet_message(xmachine_message_gov_balance_sheet * current)
 * \brief Get the next gov_balance_sheet message in the gov_balance_sheet message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_gov_balance_sheet * get_next_gov_balance_sheet_message(m_gov_balance_sheet * current)
{
	return getInternalMessage_gov_balance_sheet();
}

/** \fn void add_ecb_balance_sheet_message(double gov_bond_holdings, int nr_gov_bonds, double total_ecb_debt, double payment_account_private_sector, double payment_account_public_sector, double fiat_money, double bank_interest, double gov_interest, double gov_bond_purchase, double dividend_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
 * \brief Add ecb_balance_sheet message by calling internal and processing.
 * \param gov_bond_holdings Message variable.
 * \param nr_gov_bonds Message variable.
 * \param total_ecb_debt Message variable.
 * \param payment_account_private_sector Message variable.
 * \param payment_account_public_sector Message variable.
 * \param fiat_money Message variable.
 * \param bank_interest Message variable.
 * \param gov_interest Message variable.
 * \param gov_bond_purchase Message variable.
 * \param dividend_payment Message variable.
 * \param total_assets Message variable.
 * \param total_liabilities Message variable.
 * \param total_income Message variable.
 * \param total_expenses Message variable.
 */
void add_ecb_balance_sheet_message(double gov_bond_holdings, int nr_gov_bonds, double total_ecb_debt, double payment_account_private_sector, double payment_account_public_sector, double fiat_money, double bank_interest, double gov_interest, double gov_bond_purchase, double dividend_payment, double total_assets, double total_liabilities, double total_income, double total_expenses)
{
    int rc;
	m_ecb_balance_sheet msg;
    
    msg.gov_bond_holdings = gov_bond_holdings;
    msg.nr_gov_bonds = nr_gov_bonds;
    msg.total_ecb_debt = total_ecb_debt;
    msg.payment_account_private_sector = payment_account_private_sector;
    msg.payment_account_public_sector = payment_account_public_sector;
    msg.fiat_money = fiat_money;
    msg.bank_interest = bank_interest;
    msg.gov_interest = gov_interest;
    msg.gov_bond_purchase = gov_bond_purchase;
    msg.dividend_payment = dividend_payment;
    msg.total_assets = total_assets;
    msg.total_liabilities = total_liabilities;
    msg.total_income = total_income;
    msg.total_expenses = total_expenses;
    
    
    rc = MB_AddMessage(b_ecb_balance_sheet, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'ecb_balance_sheet' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_ecb_balance_sheet* getInternalMessage_ecb_balance_sheet(void)
{
    static m_ecb_balance_sheet *msg_prev = NULL;
    m_ecb_balance_sheet *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_ecb_balance_sheet); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'ecb_balance_sheet' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'ecb_balance_sheet' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_ecb_balance_sheet, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'ecb_balance_sheet' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'ecb_balance_sheet' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_ecb_balance_sheet * get_first_ecb_balance_sheet_message()
 * \brief Get the first ecb_balance_sheet message in the ecb_balance_sheet message list.
 * \return The first message in the list.
 */
m_ecb_balance_sheet * get_first_ecb_balance_sheet_message()
{
	return getInternalMessage_ecb_balance_sheet();
}

/** \fn xmachine_message_ecb_balance_sheet * get_next_ecb_balance_sheet_message(xmachine_message_ecb_balance_sheet * current)
 * \brief Get the next ecb_balance_sheet message in the ecb_balance_sheet message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_ecb_balance_sheet * get_next_ecb_balance_sheet_message(m_ecb_balance_sheet * current)
{
	return getInternalMessage_ecb_balance_sheet();
}

