/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn void add_rule_performance_message(int rule_id, double rule_performance)
 * \brief Add rule_performance message by calling internal and processing.
 * \param rule_id Message variable.
 * \param rule_performance Message variable.
 */
void add_rule_performance_message(int rule_id, double rule_performance)
{
    int rc;
	m_rule_performance msg;
    
    msg.rule_id = rule_id;
    msg.rule_performance = rule_performance;
    
    rc = MB_AddMessage(b_rule_performance, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'rule_performance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_performance' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'rule_performance' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif
}

inline static m_rule_performance* getInternalMessage_rule_performance(void)
{
    static m_rule_performance *msg_prev = NULL;
    m_rule_performance *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_rule_performance); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'rule_performance' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'rule_performance' Iterator has not been created?\n");
                    break;
            }
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_rule_performance, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'rule_performance' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_performance' Iterator has not been created?\n");
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

/** \fn xmachine_message_rule_performance * get_first_rule_performance_message()
 * \brief Get the first rule_performance message in the rule_performance message list.
 * \return The first message in the list.
 */
m_rule_performance * get_first_rule_performance_message()
{
	return getInternalMessage_rule_performance();
}

/** \fn xmachine_message_rule_performance * get_next_rule_performance_message(xmachine_message_rule_performance * current)
 * \brief Get the next rule_performance message in the rule_performance message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_rule_performance * get_next_rule_performance_message(m_rule_performance * current)
{
	return getInternalMessage_rule_performance();
}

/** \fn void add_new_performances_message(int rule_id, double avg_performance)
 * \brief Add new_performances message by calling internal and processing.
 * \param rule_id Message variable.
 * \param avg_performance Message variable.
 */
void add_new_performances_message(int rule_id, double avg_performance)
{
    int rc;
	m_new_performances msg;
    
    msg.rule_id = rule_id;
    msg.avg_performance = avg_performance;
    
    rc = MB_AddMessage(b_new_performances, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'new_performances' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_performances' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'new_performances' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif
}

inline static m_new_performances* getInternalMessage_new_performances(void)
{
    static m_new_performances *msg_prev = NULL;
    m_new_performances *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_new_performances); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'new_performances' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'new_performances' Iterator has not been created?\n");
                    break;
            }
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_new_performances, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'new_performances' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'new_performances' Iterator has not been created?\n");
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

/** \fn xmachine_message_new_performances * get_first_new_performances_message()
 * \brief Get the first new_performances message in the new_performances message list.
 * \return The first message in the list.
 */
m_new_performances * get_first_new_performances_message()
{
	return getInternalMessage_new_performances();
}

/** \fn xmachine_message_new_performances * get_next_new_performances_message(xmachine_message_new_performances * current)
 * \brief Get the next new_performances message in the new_performances message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_new_performances * get_next_new_performances_message(m_new_performances * current)
{
	return getInternalMessage_new_performances();
}

/** \fn void add_rule_details_message(int rule_id, double parameters)
 * \brief Add rule_details message by calling internal and processing.
 * \param rule_id Message variable.
 * \param parameters Message variable.
 */
void add_rule_details_message(int rule_id, double parameters[])
{
    int rc;
	m_rule_details msg;
    
    msg.rule_id = rule_id;
    msg.parameters = parameters;
    
    rc = MB_AddMessage(b_rule_details, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'rule_details' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_details' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'rule_details' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif
}

inline static m_rule_details* getInternalMessage_rule_details(void)
{
    static m_rule_details *msg_prev = NULL;
    m_rule_details *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_rule_details); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'rule_details' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'rule_details' Iterator has not been created?\n");
                    break;
            }
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_rule_details, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'rule_details' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'rule_details' Iterator has not been created?\n");
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

/** \fn xmachine_message_rule_details * get_first_rule_details_message()
 * \brief Get the first rule_details message in the rule_details message list.
 * \return The first message in the list.
 */
m_rule_details * get_first_rule_details_message()
{
	return getInternalMessage_rule_details();
}

/** \fn xmachine_message_rule_details * get_next_rule_details_message(xmachine_message_rule_details * current)
 * \brief Get the next rule_details message in the rule_details message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_rule_details * get_next_rule_details_message(m_rule_details * current)
{
	return getInternalMessage_rule_details();
}

