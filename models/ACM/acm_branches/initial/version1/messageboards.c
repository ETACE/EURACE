/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn void add_loan_request_message(double current_equity, double current_debt, double credit_demand, int firm_id, int bank_id)
 * \brief Add loan_request message by calling internal and processing.
 * \param current_equity Message variable.
 * \param current_debt Message variable.
 * \param credit_demand Message variable.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 */
void add_loan_request_message(double current_equity, double current_debt, double credit_demand, int firm_id, int bank_id)
{
    int rc;
	m_loan_request msg;
    
    msg.current_equity = current_equity;
    msg.current_debt = current_debt;
    msg.credit_demand = credit_demand;
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    
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
       }
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
            }
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
       }
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

/** \fn void add_loan_conditions_message(double proposed_interest_rate, double amount_offered_credit, int firm_id, int bank_id, double var)
 * \brief Add loan_conditions message by calling internal and processing.
 * \param proposed_interest_rate Message variable.
 * \param amount_offered_credit Message variable.
 * \param firm_id Message variable.
 * \param bank_id Message variable.
 * \param var Message variable.
 */
void add_loan_conditions_message(double proposed_interest_rate, double amount_offered_credit, int firm_id, int bank_id, double var)
{
    int rc;
	m_loan_conditions msg;
    
    msg.proposed_interest_rate = proposed_interest_rate;
    msg.amount_offered_credit = amount_offered_credit;
    msg.firm_id = firm_id;
    msg.bank_id = bank_id;
    msg.var = var;
    
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
       }
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
            }
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
       }
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

/** \fn void add_household_deposit_message(double money_deposited, int bank_id, int household_id)
 * \brief Add household_deposit message by calling internal and processing.
 * \param money_deposited Message variable.
 * \param bank_id Message variable.
 * \param household_id Message variable.
 */
void add_household_deposit_message(double money_deposited, int bank_id, int household_id)
{
    int rc;
	m_household_deposit msg;
    
    msg.money_deposited = money_deposited;
    msg.bank_id = bank_id;
    msg.household_id = household_id;
    
    rc = MB_AddMessage(b_household_deposit, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'household_deposit' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_deposit' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_deposit' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif
}

inline static m_household_deposit* getInternalMessage_household_deposit(void)
{
    static m_household_deposit *msg_prev = NULL;
    m_household_deposit *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_household_deposit); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'household_deposit' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'household_deposit' Iterator has not been created?\n");
                    break;
            }
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_household_deposit, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'household_deposit' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_deposit' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
       }
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_household_deposit * get_first_household_deposit_message()
 * \brief Get the first household_deposit message in the household_deposit message list.
 * \return The first message in the list.
 */
m_household_deposit * get_first_household_deposit_message()
{
	return getInternalMessage_household_deposit();
}

/** \fn xmachine_message_household_deposit * get_next_household_deposit_message(xmachine_message_household_deposit * current)
 * \brief Get the next household_deposit message in the household_deposit message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_household_deposit * get_next_household_deposit_message(m_household_deposit * current)
{
	return getInternalMessage_household_deposit();
}

/** \fn void add_money_withdraw_request_message(double money_withdraw_request, int bank_id, int household_id)
 * \brief Add money_withdraw_request message by calling internal and processing.
 * \param money_withdraw_request Message variable.
 * \param bank_id Message variable.
 * \param household_id Message variable.
 */
void add_money_withdraw_request_message(double money_withdraw_request, int bank_id, int household_id)
{
    int rc;
	m_money_withdraw_request msg;
    
    msg.money_withdraw_request = money_withdraw_request;
    msg.bank_id = bank_id;
    msg.household_id = household_id;
    
    rc = MB_AddMessage(b_money_withdraw_request, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'money_withdraw_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'money_withdraw_request' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'money_withdraw_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif
}

inline static m_money_withdraw_request* getInternalMessage_money_withdraw_request(void)
{
    static m_money_withdraw_request *msg_prev = NULL;
    m_money_withdraw_request *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_money_withdraw_request); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'money_withdraw_request' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'money_withdraw_request' Iterator has not been created?\n");
                    break;
            }
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_money_withdraw_request, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'money_withdraw_request' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'money_withdraw_request' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
       }
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_money_withdraw_request * get_first_money_withdraw_request_message()
 * \brief Get the first money_withdraw_request message in the money_withdraw_request message list.
 * \return The first message in the list.
 */
m_money_withdraw_request * get_first_money_withdraw_request_message()
{
	return getInternalMessage_money_withdraw_request();
}

/** \fn xmachine_message_money_withdraw_request * get_next_money_withdraw_request_message(xmachine_message_money_withdraw_request * current)
 * \brief Get the next money_withdraw_request message in the money_withdraw_request message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_money_withdraw_request * get_next_money_withdraw_request_message(m_money_withdraw_request * current)
{
	return getInternalMessage_money_withdraw_request();
}

/** \fn void add_loan_acceptance_message(double credit_amount_taken, int bank_id)
 * \brief Add loan_acceptance message by calling internal and processing.
 * \param credit_amount_taken Message variable.
 * \param bank_id Message variable.
 */
void add_loan_acceptance_message(double credit_amount_taken, int bank_id)
{
    int rc;
	m_loan_acceptance msg;
    
    msg.credit_amount_taken = credit_amount_taken;
    msg.bank_id = bank_id;
    
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
       }
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
            }
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
       }
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

/** \fn void add_installment_message(double installment, double interest, int bank_id, double var_per_installment)
 * \brief Add installment message by calling internal and processing.
 * \param installment Message variable.
 * \param interest Message variable.
 * \param bank_id Message variable.
 * \param var_per_installment Message variable.
 */
void add_installment_message(double installment, double interest, int bank_id, double var_per_installment)
{
    int rc;
	m_installment msg;
    
    msg.installment = installment;
    msg.interest = interest;
    msg.bank_id = bank_id;
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
       }
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
            }
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
       }
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

/** \fn void add_withdrawal_allowed_message(double withdrawal_allowed, int household_id)
 * \brief Add withdrawal_allowed message by calling internal and processing.
 * \param withdrawal_allowed Message variable.
 * \param household_id Message variable.
 */
void add_withdrawal_allowed_message(double withdrawal_allowed, int household_id)
{
    int rc;
	m_withdrawal_allowed msg;
    
    msg.withdrawal_allowed = withdrawal_allowed;
    msg.household_id = household_id;
    
    rc = MB_AddMessage(b_withdrawal_allowed, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'withdrawal_allowed' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'withdrawal_allowed' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'withdrawal_allowed' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif
}

inline static m_withdrawal_allowed* getInternalMessage_withdrawal_allowed(void)
{
    static m_withdrawal_allowed *msg_prev = NULL;
    m_withdrawal_allowed *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_withdrawal_allowed); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'withdrawal_allowed' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'withdrawal_allowed' Iterator has not been created?\n");
                    break;
            }
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_withdrawal_allowed, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'withdrawal_allowed' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'withdrawal_allowed' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
       }
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_withdrawal_allowed * get_first_withdrawal_allowed_message()
 * \brief Get the first withdrawal_allowed message in the withdrawal_allowed message list.
 * \return The first message in the list.
 */
m_withdrawal_allowed * get_first_withdrawal_allowed_message()
{
	return getInternalMessage_withdrawal_allowed();
}

/** \fn xmachine_message_withdrawal_allowed * get_next_withdrawal_allowed_message(xmachine_message_withdrawal_allowed * current)
 * \brief Get the next withdrawal_allowed message in the withdrawal_allowed message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_withdrawal_allowed * get_next_withdrawal_allowed_message(m_withdrawal_allowed * current)
{
	return getInternalMessage_withdrawal_allowed();
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
       }
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
            }
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
       }
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

