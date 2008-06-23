/* $Id: synctestgroup.c 687 2008-02-27 16:57:25Z lsc $ */
/*!
 * \file serial/synctestgroup.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Serial implementation of MB_SyncTestGroup()
 * 
 */

#include "mb_serial.h"

/*!
 * \brief Inspects the completion status of synchronisation for a group of boards
 * \ingroup MB_API
 * \param[in] mb_array Reference to array of MessageBoard Handle
 * \param[out] flag_array address or array where return values can be written to
 * \param[in] count Number of elements in array
 * 
 * In this serial version, we always write ::MB_TRUE to every \c flag
 * as synchronisation is assumed to be completed immediately after it 
 * started.
 * 
 * Testing a null board (::MB_NULL_MBOARD) or one that is not being 
 * synchronised will also result in a ::MB_TRUE flag
 * 
 * If any of the given boards is invalid, the routine will return immediately 
 * with the ::MB_ERR_INVALID status. No tests will be performed, and all flags 
 * will be set to ::MB_FALSE.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID  (Invalid board)
 * 
 */
int MB_SyncTestGroup(MBt_Board *mb_array, int *flag_array, int count) {
    
    int i, j;
    MBIt_Board *board;
    /* nothing much to do for serial version
     * - if any of the boards are invalid, set all flags to false and
     *   return with appropriate error
     * - else, set all flags to true. (assume sync completed instantaneously)
     */
    
    if (count <= 0) return MB_ERR_INVALID;

    /* loop thru mb_array to look for invalid boards */
    for (i = 0; i < count; i++)
    {       
        /* MB_NULL_MBOARD considered valid board */
        if (mb_array[i] == MB_NULL_MBOARD) continue;
        
        board = (MBIt_Board *)MBI_getMBoardRef(mb_array[i]);
        if (board == NULL) /* invalid board found */
        {
            /* set all flags to MB_FALSE */
            for (j = 0; j < count; j++) flag_array[j] = MB_FALSE;
            
            return MB_ERR_INVALID;
        }
    }
    
    /* set all flags to MB_TRUE */
    for (i = 0; i < count; i++) flag_array[i] = MB_TRUE;
    return MB_SUCCESS;
}
