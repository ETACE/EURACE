/* $Id: create.c 769 2008-03-28 10:35:42Z lsc $ */
/*!
 * \file parallel/create.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Mar 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Parallel implementation of MB_Create()
 * 
 */
#include "mb_parallel.h"

static int MBI_AddPendingCreate(MBt_Board *mb_ptr, size_t msgsize);
static int newBoardObj(MBt_handle *mb, size_t);

/* datatype used only in this file */
struct boardData_t {
    MBt_Board handle;
    size_t    msgsize;
};

int MB_Create(MBt_Board *mb_ptr, size_t msgsize) {
    
    int rc;
    MBt_Board mb;
    struct boardData_t bdata;
    
    /* check for invalid input size */
    if ((int)msgsize <= 0) return MB_ERR_INVALID;
    
    /* if called within a transaction block */
    if (MBI_STATUS_inTransaction == MB_TRUE)
    {
        return MBI_AddPendingCreate(mb_ptr, msgsize);
    }
    
    /* create board object */
    rc = newBoardObj(&mb, msgsize);
    assert(rc == MB_SUCCESS);
    
    #ifdef MB_CONFIG_NOCHECKS
        return MB_SUCCESS;
    #endif
        
    /* Make sure all processors have same msgsize and handle
     * for this board
     */
    if (MASTERNODE) 
    {
        bdata.handle  = mb;
        bdata.msgsize = msgsize;
    }
    
    MPI_Bcast(&bdata, (int)sizeof(struct boardData_t), MPI_BYTE, 0, MBI_CommWorld);
    
    if (!MASTERNODE && (bdata.handle != mb || bdata.msgsize != msgsize))
    {
        MBI_Abort(MB_ERR_USER, "Mismatching MB_Create() calls");
    }
    
    return rc;
}

static int MBI_AddPendingCreate(MBt_Board *mb_ptr, size_t msgsize) {
    
    MBIt_pendingCreate_node *current;
    
    /* allocate required memory for arg node */
    current = (MBIt_pendingCreate_node *)malloc(sizeof(MBIt_pendingCreate_node));
    assert(current != NULL);
    if (errno != 0 || current == NULL)
    {
        return MB_ERR_MEMALLOC;
    }
    
    /* store arguments to pending MB_Create */
    current->msgsize = msgsize;
    current->mb_ptr  = mb_ptr;
   
    /* append to list */
    current->next = MBI_PENDING_Create_list;
    MBI_PENDING_Create_list = current;
    
    /* increment counter */
    MBI_PENDING_Create_count++;
    
    /* set return MB handle to PENDING */
    *mb_ptr = MB_PENDING_MBOARD;
    
    /* return successfully */
    return MB_SUCCESS;
}

static int newBoardObj(MBt_Board *mb_ptr, size_t msgsize) {
    
    int rc;
    OM_key_t rc_om;
    MBIt_Board *mb_obj;
    
    /* allocate message board object */
    mb_obj = (MBIt_Board *)malloc(sizeof(MBIt_Board));
    assert(mb_obj != NULL);
    if (errno != 0 || mb_obj == NULL) /* on error */
    {
        return MB_ERR_MEMALLOC;
    }
    
    mb_obj->locked = MB_FALSE; /* initialise lock */
    
    /* allocate pooled list */
    rc = pl_create(&(mb_obj->data), msgsize, MB_CONFIG_PARALLEL_POOLSIZE);
    if (rc != PL_SUCCESS)
    {
        free(mb_obj);
        if (rc == PL_ERR_MALLOC) return MB_ERR_MEMALLOC;
        else return MB_ERR_INTERNAL;
    }
    
    /* register new mboard object */
    assert(MBI_OM_mboard != NULL);
    assert(MBI_OM_mboard->type == OM_TYPE_MBOARD);
    rc_om = MBI_objmap_push(MBI_OM_mboard, (void*)mb_obj);
    if (rc_om > OM_MAX_INDEX)
    {
        if (rc_om == OM_ERR_MEMALLOC)
        {
            return MB_ERR_MEMALLOC;
        }
        else
        {
            return MB_ERR_INTERNAL;
        }
    }
    
    /* assign handle to new mboard */
    *mb_ptr  = (MBt_Board)rc_om;
    
    return MB_SUCCESS;
}

int MBI_PerformAllPendingCreates(void) {
    
    int i, rc, count, errfound;
    MBt_Board *mbs;
    size_t    *msgsizes;
    struct boardData_t *bdata;
    MBIt_pendingCreate_node *current, *prev;
    
    if (0 == MBI_PENDING_Create_count)
    {
        assert(MBI_PENDING_Create_list == NULL);
        return MB_SUCCESS;
    }
    else
    {
        assert(MBI_PENDING_Create_list != NULL);
    }
    
    /* initialise control vars and allocate memory */
    count = MBI_PENDING_Create_count;
    mbs   = (MBt_Board *)malloc(sizeof(MBt_Board) * count);
    bdata = (struct boardData_t *)malloc(sizeof(struct boardData_t) * count);
    msgsizes = (size_t *)malloc(sizeof(size_t) * count);
    
    if (mbs == NULL || bdata == NULL || msgsizes == NULL)
    {
        free(mbs);
        free(bdata);
        free(msgsizes);
        return MB_ERR_MEMALLOC;
    }
    
    /* create board objects */
    i = 0;
    current = MBI_PENDING_Create_list;
    while (current)
    {
        /* create board object */
        msgsizes[i] = current->msgsize;
        rc = newBoardObj(&mbs[i], current->msgsize);
        assert(rc == MB_SUCCESS);
        
        /* write to user's handle */
        *(current->mb_ptr) = mbs[i];
        
        /* delete node and proceed */
        prev = current;
        current = current->next;
        free(prev);
        
        i++;
    }
    assert(i == count);
    
    #ifndef MB_CONFIG_NOCHECKS
        
        if (MASTERNODE)
        {
            for (i = 0; i < count; i++)
            {
                bdata[i].handle  = mbs[i];
                bdata[i].msgsize = msgsizes[i];
            }
        }
        
        MPI_Bcast(bdata, (int)sizeof(struct boardData_t) * count, 
                  MPI_BYTE, 0, MBI_CommWorld);
        
        if (!MASTERNODE)
        {
            errfound = 0;
            for (i = 0; i < count; i++)
            {
                /* handle and msgsize must match (and appear in the same order) */
                if (bdata[i].handle != mbs[i] || bdata[i].msgsize != msgsizes[i])
                {
                    errfound++;
                }
            }
            if (0 != errfound)
            {
                MBI_Abort(MB_ERR_USER, "Mismatching MB_Create() calls");
            }
        }
        
    #endif /*ifndef MB_CONFIG_NOCHECKS*/
    
    free(mbs);
    free(bdata);
    free(msgsizes);
    
    return MB_SUCCESS;
}
