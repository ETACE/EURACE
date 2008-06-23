/* $Id: env_finalise.c 769 2008-03-28 10:35:42Z lsc $ */
/*!
 * \file parallel/env_finalise.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Mar 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Parallel implementation of MB_Env_Finalise()
 * 
 */

#include "mb_parallel.h"

/*!
 * \brief Finalises the libmboard environment
 * \ingroup MB_API
 * 
 * 
 * ObjectMaps (::MBI_OM_mboard and ::MBI_OM_iterator) are destroyed, and the 
 * \c MBI_STATUS_* flags are set.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_ENV (libmboard environment not yet started or already finalised)
 */
int MB_Env_Finalise(void) {
    
    /* Check if environment not initialised */
    if (MBI_STATUS_initialised != MB_TRUE) return MB_ERR_ENV;
    if (MBI_STATUS_finalised == MB_TRUE) return MB_ERR_ENV;
    
    /* deallocate Object Maps */
    MBI_objmap_destroy(&MBI_OM_mboard);
    MBI_objmap_destroy(&MBI_OM_iterator);
    
    /* free our MPI_Communicator */
    MPI_Comm_free(&MBI_CommWorld);
    
    /* set initialised status and return */
    MBI_STATUS_finalised   = MB_TRUE;
    MBI_STATUS_initialised = MB_FALSE;
    return MB_SUCCESS;
}
