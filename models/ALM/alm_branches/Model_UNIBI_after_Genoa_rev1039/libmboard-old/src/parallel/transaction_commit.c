/* $Id: transaction_commit.c 769 2008-03-28 10:35:42Z lsc $ */
/*!
 * \file parallel/transaction_commit.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Mar 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Parallel implementation of MB_Transaction_Commit()
 * 
 */

#include "mb_parallel.h"

int MB_Transaction_Commit(void) {
    
    int rc;
    /* check if we are in transaction block */
    if (MBI_STATUS_inTransaction != MB_TRUE) return MB_ERR_INVALID;
    
    /* Perform all pending MB Creates */
    rc = MBI_PerformAllPendingCreates();
    
    /* ---------- Perform all pending MB Syncs ---------- */
    
    
    /* leave transaction block */
    MBI_STATUS_inTransaction = MB_FALSE;
    
    return MB_SUCCESS;
}
