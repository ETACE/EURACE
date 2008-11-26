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

/** \fn void add_tax_payment_message(int firm_id, int gov_id, double tax_payment)
 * \brief Add tax_payment message by calling internal and processing.
 * \param firm_id Message variable.
 * \param gov_id Message variable.
 * \param tax_payment Message variable.
 */
void add_tax_payment_message(int firm_id, int gov_id, double tax_payment)
{
    int rc;
	m_tax_payment msg;
    
    msg.firm_id = firm_id;
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

/** \fn void add_current_mall_stock_info_message(int mall_id, int firm_id, double stock)
 * \brief Add current_mall_stock_info message by calling internal and processing.
 * \param mall_id Message variable.
 * \param firm_id Message variable.
 * \param stock Message variable.
 */
void add_current_mall_stock_info_message(int mall_id, int firm_id, double stock)
{
    int rc;
	m_current_mall_stock_info msg;
    
    msg.mall_id = mall_id;
    msg.firm_id = firm_id;
    msg.stock = stock;
    
    
    rc = MB_AddMessage(b_current_mall_stock_info, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'current_mall_stock_info' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is locked\n");
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

inline static m_current_mall_stock_info* getInternalMessage_current_mall_stock_info(void)
{
    static m_current_mall_stock_info *msg_prev = NULL;
    m_current_mall_stock_info *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_current_mall_stock_info); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'current_mall_stock_info' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'current_mall_stock_info' Iterator has not been created?\n");
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
    rc = MB_Iterator_GetMessage(i_current_mall_stock_info, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'current_mall_stock_info' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' Iterator has not been created?\n");
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

/** \fn xmachine_message_current_mall_stock_info * get_first_current_mall_stock_info_message()
 * \brief Get the first current_mall_stock_info message in the current_mall_stock_info message list.
 * \return The first message in the list.
 */
m_current_mall_stock_info * get_first_current_mall_stock_info_message()
{
	return getInternalMessage_current_mall_stock_info();
}

/** \fn xmachine_message_current_mall_stock_info * get_next_current_mall_stock_info_message(xmachine_message_current_mall_stock_info * current)
 * \brief Get the next current_mall_stock_info message in the current_mall_stock_info message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_current_mall_stock_info * get_next_current_mall_stock_info_message(m_current_mall_stock_info * current)
{
	return getInternalMessage_current_mall_stock_info();
}

/** \fn void add_order_message(int trader_id, int asset_id, double limit_price, int quantity)
 * \brief Add order message by calling internal and processing.
 * \param trader_id Message variable.
 * \param asset_id Message variable.
 * \param limit_price Message variable.
 * \param quantity Message variable.
 */
void add_order_message(int trader_id, int asset_id, double limit_price, int quantity)
{
    int rc;
	m_order msg;
    
    msg.trader_id = trader_id;
    msg.asset_id = asset_id;
    msg.limit_price = limit_price;
    msg.quantity = quantity;
    
    
    rc = MB_AddMessage(b_order, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order' board is locked\n");
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

inline static m_order* getInternalMessage_order(void)
{
    static m_order *msg_prev = NULL;
    m_order *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_order); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'order' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'order' Iterator has not been created?\n");
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
    rc = MB_Iterator_GetMessage(i_order, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'order' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order' Iterator has not been created?\n");
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

/** \fn xmachine_message_order * get_first_order_message()
 * \brief Get the first order message in the order message list.
 * \return The first message in the list.
 */
m_order * get_first_order_message()
{
	return getInternalMessage_order();
}

/** \fn xmachine_message_order * get_next_order_message(xmachine_message_order * current)
 * \brief Get the next order message in the order message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_order * get_next_order_message(m_order * current)
{
	return getInternalMessage_order();
}

/** \fn void add_order_status_message(int trader_id, int asset_id, double price, int quantity)
 * \brief Add order_status message by calling internal and processing.
 * \param trader_id Message variable.
 * \param asset_id Message variable.
 * \param price Message variable.
 * \param quantity Message variable.
 */
void add_order_status_message(int trader_id, int asset_id, double price, int quantity)
{
    int rc;
	m_order_status msg;
    
    msg.trader_id = trader_id;
    msg.asset_id = asset_id;
    msg.price = price;
    msg.quantity = quantity;
    
    
    rc = MB_AddMessage(b_order_status, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'order_status' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order_status' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order_status' board is locked\n");
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

inline static m_order_status* getInternalMessage_order_status(void)
{
    static m_order_status *msg_prev = NULL;
    m_order_status *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_order_status); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'order_status' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'order_status' Iterator has not been created?\n");
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
    rc = MB_Iterator_GetMessage(i_order_status, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'order_status' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order_status' Iterator has not been created?\n");
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

/** \fn xmachine_message_order_status * get_first_order_status_message()
 * \brief Get the first order_status message in the order_status message list.
 * \return The first message in the list.
 */
m_order_status * get_first_order_status_message()
{
	return getInternalMessage_order_status();
}

/** \fn xmachine_message_order_status * get_next_order_status_message(xmachine_message_order_status * current)
 * \brief Get the next order_status message in the order_status message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_order_status * get_next_order_status_message(m_order_status * current)
{
	return getInternalMessage_order_status();
}

