/* $Id: syncstartgroup.c 687 2008-02-27 16:57:25Z lsc $ */
/*!
 * \file serial/syncstartgroup.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Serial implementation of MB_SyncStartGroup()
 * 
 */

#include "mb_serial.h"

/*!
 * \brief Synchronises the content of the board across all processes
 * \ingroup MB_API
 * \param[in] mb_array Reference to array of MessageBoard Handles
 * \param[in] count Number of elements in array
 * 
 * In this serial version, we do nothing anything apart from locking the 
 * message boards.
 * 
 * If any of the given boards is invalid or locked, locking 
 * will not be done for any of the boards, and the routine will return 
 * immediately with the ::MB_ERR_INVALID or ::MB_ERR_LOCKED status.
 * 
 * Synchronisation of null boards (::MB_NULL_BOARD) is valid and will return 
 * successfully.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID  (Invalid board)
 * 
 */
int MB_SyncStartGroup(MBt_Board *mb_array, int count) {
    
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
        if (board[i] == NULL) /* if board invalid */
        {
            /* clean up and quit with error */
            free(board);
            return MB_ERR_INVALID;
        }
        else if (board[i]->locked == MB_TRUE)
        {
            /* clean up and quit with error */
            free(board);
            return MB_ERR_LOCKED;
        }
    }
    
    /* if all boards are valid, lock all and quit successfully */
    for (i = 0; i < count; i++) 
    {
        if (board[i] != NULL) board[i]->locked = MB_TRUE;
    }
    free(board);
    
    /* return success */
    return MB_SUCCESS;
}
