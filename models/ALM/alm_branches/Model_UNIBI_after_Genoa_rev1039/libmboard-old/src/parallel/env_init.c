/* $Id: env_init.c 769 2008-03-28 10:35:42Z lsc $ */
/*!
 * \file parallel/env_init.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Mar 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * As the MB_Env_Init() is the routine that must be called in every
 * program that uses libmboard, we place the definitions of all
 * global variables (defined in mboard.h) in this file.
 * 
 * \brief Parallel implementation of MB_Env_Init()
 * 
 */

#include "mb_parallel.h"
#include <time.h>

/* ---- Initialise global variables (Defined as extern in mb_common.h) ---- */
/*! \brief 'initialised' environment flag */
int MBI_STATUS_initialised   = MB_FALSE; 
/*! \brief 'finalised' environment flag */
int MBI_STATUS_finalised     = MB_FALSE; 
/*! \brief flag indicating if code control currently in transaction block */
int MBI_STATUS_inTransaction = MB_FALSE;
/*! \brief reference to MessageBoard ObjectMap */
MBIt_objmap *MBI_OM_mboard   = NULL;  
/*! \brief reference to Iterator ObjectMap */
MBIt_objmap *MBI_OM_iterator = NULL;   

/*! \brief number of pending MB_Create() */
int MBI_PENDING_Create_count = 0;
/*! \brief linked list storing arguments for pending MB_Create()s */
MBIt_pendingCreate_node *MBI_PENDING_Create_list = NULL;
/*! \brief Our world communicator for MPI Communication */
MPI_Comm MBI_CommWorld;
/*! \brief MPI Task ID */
int MBI_CommRank;
/*! \brief Number of MPI Tasks */
int MBI_CommSize;
/*!
 * \brief Initialises the libmboard environment
 * \ingroup MB_API
 * 
 * 
 * ObjectMaps needed to hash MessageBoards (::MBI_OM_mboard) and Iterators 
 * (::MBI_OM_iterator) are instantiated and assigned to the global reference.
 * 
 * The environment status flags are set, and the RNG seeded with the time.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_MEMALLOC (error allocating memory for ObjectMaps)
 *  - ::MB_ERR_ENV (libmboard environment already started)
 *  - ::MB_ERR_MPI (MPI Environment not yet initialised)
 */
int MB_Env_Init(void) {
    
    int flag;
    
    /* Check if environment already initialised */
    if (MBI_STATUS_initialised == MB_TRUE) return MB_ERR_ENV;
    
    /* Check if MPI environment has been initialised */
    MPI_Initialized(&flag);
    if (!flag) return MB_ERR_MPI;
    
    /* Set up our communicator */
    MPI_Comm_dup(MPI_COMM_WORLD, &MBI_CommWorld);
    MPI_Comm_rank(MBI_CommWorld, &MBI_CommRank);
    MPI_Comm_size(MBI_CommWorld, &MBI_CommSize);
    
    /* seed rng */
    srand((unsigned)time(NULL)); 
    
    /* Allocate object maps */
    MBI_OM_mboard   = (MBIt_objmap*)MBI_objmap_new();
    MBI_OM_iterator = (MBIt_objmap*)MBI_objmap_new();
    if (!MBI_OM_mboard || !MBI_OM_iterator) 
    {   /* if allocation failed, release mem and return with error */
        MBI_objmap_destroy(&MBI_OM_mboard);
        MBI_objmap_destroy(&MBI_OM_iterator);
        return MB_ERR_MEMALLOC;
    }
    else
    {   /* set type */
        MBI_OM_mboard   ->type = OM_TYPE_MBOARD;
        MBI_OM_iterator ->type = OM_TYPE_ITERATOR;
    }
    
    /* set initialised status and return */
    MBI_STATUS_initialised = MB_TRUE;
    return MB_SUCCESS;
}
