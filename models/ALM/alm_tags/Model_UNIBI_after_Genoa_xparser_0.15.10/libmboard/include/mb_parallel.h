/* $Id: mb_parallel.h 751 2008-03-18 13:17:01Z lsc $ */
/*!
 * \file mb_parallel.h
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Header file used by parallel implementation
 * 
 */

#ifndef MB_PARALLEL_H_
#define MB_PARALLEL_H_

#include "mboard.h"
#include "mb_utils.h"
#include "mb_common.h"

#include <mpi.h>

#define MASTERNODE (0 == MBI_CommRank)

/* uncomment to skip expensive checks. */
/* #define MB_CONFIG_NOCHECKS */

/* MPI Tags for communication */
#define MBI_TAG_CREATE   (0x88000001)

/* datatypes for storing params for pending creates */
typedef struct t_MBIt_pendingCreate_node {
    
    /* params for MB_Create */
    size_t     msgsize;
    MBt_Board *mb_ptr;
    
    /* pointer to next node */
    struct t_MBIt_pendingCreate_node *next;
} MBIt_pendingCreate_node;


/* global variables (initialised and documented in env_init.c) */
extern int MBI_STATUS_inTransaction;
extern int MBI_PENDING_Create_count;
extern MBIt_pendingCreate_node *MBI_PENDING_Create_list;
extern MPI_Comm MBI_CommWorld;
extern int MBI_CommRank;
extern int MBI_CommSize;

/* implemented in create.c */
int MBI_PerformAllPendingCreates(void);

/* implemented in abort.c */
void MBI_Abort(int rc, char * message);

#endif /*MB_PARALLEL_H_*/
