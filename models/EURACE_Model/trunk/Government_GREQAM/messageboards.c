/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


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

