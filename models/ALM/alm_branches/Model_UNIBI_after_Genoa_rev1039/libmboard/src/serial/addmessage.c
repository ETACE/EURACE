/* $Id: addmessage.c 755 2008-03-19 16:08:26Z lsc $ */
/*!
 * \file serial/addmessage.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Serial implementation of MB_AddMessage()
 * 
 */
#include "mb_serial.h"
#include <string.h>

/*!
 * \brief Adds a message to the MessageBoard
 * \ingroup MB_API
 * \param[in] mb MessageBoard handle
 * \param[in] msg Address of the message to be added
 * 
 * The message data is copied into a data node in the message board. Upon 
 * completion, users are free to modify, reuse, or deallocate their copy of 
 * the message. Not only will this be less susceptible to bugs, it also 
 * gives us more control over memory management.
 * 
 * We were unable to use the pooled-list data structure in the 
 * intended manner (where entries form a linked-list) as we cannot 
 * know the datatype for each message at compile-time and therefore
 * cannot dereference and assign the 'next' pointers.
 * 
 * Elements will have to be accessed using pl_getnode() which can be
 * less optimised for full traversals. Not ideal, but at least we
 * still enjoy the benefits of memory pooling.
 * 
 * \note We use \c memcpy to copy message data which makes endianness an
 * issue if run on heterogenous systems.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS 
 *  - ::MB_ERR_INVALID (invalid or null board given) 
 *  - ::MB_ERR_MEMALLOC (error allocating memory for expanding memory pool)
 *  - ::MB_ERR_LOCKED (message board is locked for synchronisation)
 *  - ::MB_ERR_INTERNAL (possible bug. Recompile and run in debug mode for hints)
 */
int MB_AddMessage(MBt_Board mb, void *msg) {
    
    int rc;
    
    void *ptr_new;
    
    pooled_list *pl;
    MBIt_Board  *board;
    
    /* if message board is null */
    if (mb == MB_NULL_MBOARD) return MB_ERR_INVALID;
    
    /* if message pointer is null */
    if (!msg) return MB_ERR_INVALID;
    
    /* map handle to object */
    board = (MBIt_Board *)MBI_getMBoardRef(mb);
    if (board == NULL) return MB_ERR_INVALID;

    /* do not add message if board is locked */
    if (board->locked == MB_TRUE) return MB_ERR_LOCKED;
    
    /* get access to internal data */
    pl = board->data;
    assert(pl != NULL);
    
    
    /* Cr@p.. pooled list can't be used as initially intended. 
     * From within library, we won't know the type for each message, 
     * which means we can't assign references to msg->next.
     * 
     * For now, we use pooled list without assigning "next" pointers:
     *  - we won't be able to traverse the nodes as a list, however,
     *    we still get the benefits of memory pooling.
     *    Traversing it will be a pain though :(
     */
    
    /* create new node in pooled list */
    rc = pl_newnode(pl, &ptr_new);
    if (rc == PL_ERR_MALLOC) return MB_ERR_MEMALLOC;
    if (rc != PL_SUCCESS) return MB_ERR_INTERNAL;
    
    /* copy data into mboard node */
    memcpy(ptr_new, msg, (size_t)pl->elem_size);
    
    return MB_SUCCESS;
    
}
