/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn void add_strategy_i_use_message(int player_id, int strategy_id, int previous_move, int present_state, double range, double x, double y, double z)
 * \brief Add strategy_i_use message by calling internal and processing.
 * \param player_id Message variable.
 * \param strategy_id Message variable.
 * \param previous_move Message variable.
 * \param present_state Message variable.
 * \param range Message variable.
 * \param x Message variable.
 * \param y Message variable.
 * \param z Message variable.
 */
void add_strategy_i_use_message(int player_id, int strategy_id, int previous_move, int present_state, double range, double x, double y, double z)
{
    int rc;
	m_strategy_i_use msg;
    
    msg.player_id = player_id;
    msg.strategy_id = strategy_id;
    msg.previous_move = previous_move;
    msg.present_state = present_state;
    msg.range = range;
    msg.x = x;
    msg.y = y;
    msg.z = z;
    
    rc = MB_AddMessage(b_strategy_i_use, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'strategy_i_use' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'strategy_i_use' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'strategy_i_use' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
       }
    }
    #endif
}

inline static m_strategy_i_use* getInternalMessage_strategy_i_use(void)
{
    static m_strategy_i_use *msg_prev = NULL;
    m_strategy_i_use *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_strategy_i_use); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'strategy_i_use' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'strategy_i_use' Iterator has not been created?\n");
                    break;
            }
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_strategy_i_use, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'strategy_i_use' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'strategy_i_use' Iterator has not been created?\n");
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

/** \fn xmachine_message_strategy_i_use * get_first_strategy_i_use_message()
 * \brief Get the first strategy_i_use message in the strategy_i_use message list.
 * \return The first message in the list.
 */
m_strategy_i_use * get_first_strategy_i_use_message()
{
	return getInternalMessage_strategy_i_use();
}

/** \fn xmachine_message_strategy_i_use * get_next_strategy_i_use_message(xmachine_message_strategy_i_use * current)
 * \brief Get the next strategy_i_use message in the strategy_i_use message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_strategy_i_use * get_next_strategy_i_use_message(m_strategy_i_use * current)
{
	return getInternalMessage_strategy_i_use();
}

