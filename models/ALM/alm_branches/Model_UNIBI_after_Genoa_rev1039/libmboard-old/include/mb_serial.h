/* $Id: mb_serial.h 751 2008-03-18 13:17:01Z lsc $ */
/*!
 * \file mb_serial.h
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Header file used by serial implementation
 * 
 * Uncomment the definition of \c MB_CONFIG_RECYCLE_MEMPOOL in this file 
 * to use pl_recycle() instead of pl_reset() when clearing MessageBoards 
 * with MB_Clear()
 * 
 */

#ifndef MB_SERIAL_H_
#define MB_SERIAL_H_

#include "mboard.h"
#include "mb_common.h"
#include "mb_utils.h"

/* Uncomment to use pl_recycle() instead of pl_reset() */
/* #define MB_CONFIG_RECYCLE_MEMPOOL */


#endif /*MB_SERIAL_H_*/
