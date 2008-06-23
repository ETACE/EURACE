/* $Id: synccompletegroup.c 687 2008-02-27 16:57:25Z lsc $ */
/*!
 * \file serial/synccompletegroup.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Serial implementation of MB_SyncCompleteGroup()
 * 
 */

#include "mb_serial.h"


/*!
 * \brief Completes the synchronisation of a group of boards
 * \ingroup MB_API
 * \param[in] mb_array Reference to array of MessageBoard Handles
 * \param[in] count Number of elements in array
 * 
 * In this serial version, we do nothing anything apart from unlocking the 
 * message boards as synchronisation is assumed to be completed immediately after it 
 * started.
 * 
 * If any of the given boards is invalid, the routine will return immediately 
 * with the ::MB_ERR_INVALID status. No tests will be performed, and all flags 
 * will be set to ::MB_FALSE.
 * 
 * Synchronisation of null boards (::MB_NULL_MBOARD) is valid, and will 
 * return immediately with ::MB_SUCCESS
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID  (Invalid board)
 *  - ::MB_ERR_MEMALLOC (error allocating memory for temporary data)
 * 
 */
int MB_SyncCompleteGroup(MBt_Board *mb_array, int count) {
    
    int i;
    MBIt_Board **board;
    
    if (count <= 0) return MB_ERR_INVALID;
    
    /* allocate memory for board ref array */
    errno = 0;
    board = (MBIt_Board **)malloc(sizeof(MBIt_Board *) * count);
    assert(board != NULL);
    if (errno != 0 || board == NULL) return MB_ERR_MEMALLOC;
    
    /* map board handles to object references */
    for (i = 0; i < count; i++)
    {
        /* null boards accepted. do nothing with them */
        if (mb_array[i] == MB_NULL_MBOARD)
        {
            board[i] = NULL;
            continue;
        }
        
        board[i] = (MBIt_Board *)MBI_getMBoardRef(mb_array[i]);
        if (board[i] == NULL || board[i]->locked != MB_TRUE )
        {
            /* clean up and quit with error */
            free(board);
            return MB_ERR_INVALID;
        }

    }
    
    /* if all boards are valid, lock all and quit successfully */
    for (i = 0; i < count; i++) 
    {
        if (board[i] != NULL) board[i]->locked = MB_FALSE;
    }
    free(board);
    
    /* return success */
    return MB_SUCCESS;
}
