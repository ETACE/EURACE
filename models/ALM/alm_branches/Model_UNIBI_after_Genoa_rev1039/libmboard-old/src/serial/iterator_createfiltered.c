/* $Id: iterator_createfiltered.c 760 2008-03-20 14:40:48Z lsc $ */
/*!
 * \file serial/iterator_createfiltered.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Serial implementation of MB_Iterator_CreateFiltered()
 * 
 */

#include "mb_serial.h"
#include <string.h> /* for memcpy() */

/*!
 * \brief Creates a filtered Iterator for accessing a selection of messages 
 *        in the MessageBoard
 * \ingroup MB_API
 * \param[in] mb MessageBoard handle
 * \param[out] itr_ptr Address of Iterator Handle
 * \param[in] filterFunc Pointer to user-defined filter function
 * \param[in] filterFuncParams Pointer to input data that will be passed into \c filterFunc 
 * 
 * The Iterator object is allocated and populated with references to 
 * messages that gets accepted by \c filterFunc. The Iterator is then registered 
 * with the ::MBI_OM_iterator and the reference ID returned by ObjectMap 
 * is then written to \c itr_ptr as the handle.
 * 
 * We expect \c filterFunc() to return a \c 0 if a message is to be rejected,
 * and a non-zero \c int if it is to be accepted.
 * 
 * References to messages are stored within a pooled_list and traversed as 
 * a linked list. The memory block size for the Iterator pooled_list is chosen to
 * be half that of the default MessageBoard block size.
 * 
 * Message references are stored in the same order they appear in the board.
 * 
 * \note We only store pointers to message objects within the Iterator, and
 *       not the actual messages. These pointers will be invalid if the 
 *       MessageBoard is deleted of modified. Checking the validity of 
 *       messages each time it is accessed would be too great an overhead.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS 
 *  - ::MB_ERR_INVALID (invalid or null board given) 
 *  - ::MB_ERR_MEMALLOC (error allocating memory for Iterator object or pooled_list)
 *  - ::MB_ERR_LOCKED (\c mb is locked)
 *  - ::MB_ERR_INTERNAL (possible bug. Recompile and run in debug mode for hints)
 */
int MB_Iterator_CreateFiltered(MBt_Board mb, MBt_Iterator *itr_ptr, \
        int (*filterFunc)(const void *msg, const void *params), \
        void *filterFuncParams ) {
    
    int rc, mcount;
    OM_key_t rc_om;
    void *obj;
    void *new;
    MBIt_Board *board;
    MBIt_Iterator *iter;
    pl_address_node *pl_itr;
    
    /* Check for NULL message board */
    if (mb == MB_NULL_MBOARD) return MB_ERR_INVALID;
    
    /* get ptr to board */
    board = (MBIt_Board*)MBI_getMBoardRef(mb);
    if (board == NULL) return MB_ERR_INVALID;
    mcount = (int)board->data->count_current;
    
    /* check if board is locked */
    if (board->locked != MB_FALSE) return MB_ERR_LOCKED;
    
    /* Allocate Iterator object */
    errno = 0;
    iter = (MBIt_Iterator*)malloc(sizeof(MBIt_Iterator));
    assert(iter != NULL);
    if (errno != 0 || iter == NULL) return MB_ERR_MEMALLOC;
    
    /* assign mb handle to iterator */
    iter->mb = mb;
    iter->msgsize = (int)board->data->elem_size;
    iter->cursor = NULL;
    iter->iterating = 0;
    
    /* allocate memory for address list */
    /* use pool sizes half of that of MBoards */
    rc = pl_create(&(iter->data), sizeof(void *), MB_CONFIG_SERIAL_POOLSIZE / 2);
    if (rc != PL_SUCCESS)
    {
        free(iter);
        if (rc == PL_ERR_MALLOC) return MB_ERR_MEMALLOC;
        else return MB_ERR_INTERNAL;
    }
    
    /* populate iterator */
    assert(board->data != NULL);
    for (pl_itr = PL_ITERATOR(board->data); pl_itr; pl_itr = pl_itr->next)
    {
        /* get reference to message object */
        obj = PL_NODEDATA(pl_itr);
        assert(obj != NULL);
        
        /* run filter on message */
        rc = (*filterFunc)(obj, filterFuncParams);
        
        /* don't add if rejected by filter */
        if (0 == rc) continue;
        
        /* add message reference to iterator */
        rc = pl_newnode(iter->data, &new);
        assert(new != NULL);
        memcpy(new, &obj, sizeof(void *));
    }
    
    /* register iter object */
    rc_om = MBI_objmap_push(MBI_OM_iterator, (void*)iter);
    if (rc_om > OM_MAX_INDEX)
    {
        if (rc_om == OM_ERR_MEMALLOC)
        {
            return MB_ERR_MEMALLOC;
        }
        else
        {
            return MB_ERR_INTERNAL;
        }
    }
    
    /* assign return pointer */
    *itr_ptr  = (MBt_Iterator)rc_om;
    
    return MB_SUCCESS;
}
