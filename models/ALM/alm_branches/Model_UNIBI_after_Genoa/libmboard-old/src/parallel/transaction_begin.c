/* $Id: transaction_begin.c 769 2008-03-28 10:35:42Z lsc $ */
/*!
 * \file parallel/transaction_begin.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Mar 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Parallel implementation of MB_Transaction_Begin()
 * 
 */

#include "mb_parallel.h"

int MB_Transaction_Begin(void) {
    
    /* set control flag */
    MBI_STATUS_inTransaction = MB_TRUE;
    
    return MB_SUCCESS;
}
