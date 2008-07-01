/* $Id: mb_utils.h 675 2008-02-26 15:25:33Z lsc $ */
/*!
 * \file mb_utils.h
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Header file for utility routines (used by both serial and
 *        parallel implementations)
 * 
 */

#ifndef MB_UTILS_H_
#define MB_UTILS_H_

/* ----- Internal datatypes ----- */


/* ------ Routines internal to libmboard ----- */
/* from unmap.c */

/* Dereference Mboard Handle */
void * MBI_getMBoardRef(MBt_Board mb);

/* Dereference Iterartor Handle */
void * MBI_getIteratorRef(MBt_Iterator iter);


#endif /*MB_UTILS_H_*/
