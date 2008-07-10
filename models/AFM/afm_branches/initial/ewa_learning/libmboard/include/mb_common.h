/* $Id: mb_common.h 755 2008-03-19 16:08:26Z lsc $ */
/*!
 * \file mb_common.h
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Header file common to both serial and parallel implementation
 * 
 */

#ifndef MB_COMMON_H_
#define MB_COMMON_H_

#include "objmap.h"
#include "pooled_list.h"
#include <errno.h>
#include <assert.h>
#include <stdlib.h>

/* status variables (initialised and documented in env_init.c) */
extern int MBI_STATUS_initialised;
extern int MBI_STATUS_finalised;

/*! \brief Number of elements per memory block
 * 
 * This value is passed as \c pool_size to pl_create() when 
 * MessageBoards are created using MB_Create() .
 * 
 * This value (halved) is also used when creating an Filtered
 * Iterator (MB_Iterator_CreateFiltered()).
 */
#define MB_CONFIG_POOLSIZE    100
#define MB_CONFIG_SERIAL_POOLSIZE    MB_CONFIG_POOLSIZE
#define MB_CONFIG_PARALLEL_POOLSIZE  MB_CONFIG_POOLSIZE


/*! \brief Data structure of a MessageBoard instance */
typedef struct {
    /*! \brief flag indicating 'locked' status */
    int locked;
    /*! \brief pooled-list to hold messages */
    pooled_list *data;
} MBIt_Board;

/*! \brief Data structure of an Iterator instance */
typedef struct {
    /*! \brief size of message being referenced */
    int msgsize; 
    /*! \brief flag to indicate if iteration has started */
    int iterating; 
    /*! \brief handle to corresponding MessageBoard */
    MBt_Board mb;  

    /*! \brief pooled-list to hold MBIt_addrnode which references messages */
    pooled_list *data;
    /*! \brief pointer to current address node */
    pl_address_node *cursor;

} MBIt_Iterator;

/* ---- Object Maps ----- */
/*! \brief Constant representing Object Type: MessageBoard */
#define OM_TYPE_MBOARD    (0x0a000001)
/*! \brief Constant representing Object Type: Iterator */
#define OM_TYPE_ITERATOR  (0x0a000002)

/* (initialised and documented in env_init.c) */
extern MBIt_objmap *MBI_OM_mboard;
extern MBIt_objmap *MBI_OM_iterator;

#endif /*MB_COMMON_H_*/
