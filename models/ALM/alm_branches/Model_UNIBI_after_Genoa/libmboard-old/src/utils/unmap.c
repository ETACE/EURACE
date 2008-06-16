/* $Id: unmap.c 687 2008-02-27 16:57:25Z lsc $ */
/*!
 * \file unmap.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief wrapper routines for mapping Handles to object pointers
 * 
 */

#include "mboard.h"
#include "mb_utils.h"
#include "mb_common.h"
#include "objmap.h"
#include <assert.h>

/* kindly request that the compiler inline these routines */
/* #pragma inline (MBI_getMBoardRef);   */
/* #pragma inline (MBI_getIteratorRef); */


/*! 
 * \brief wrapper routine for mapping MessageBoard handle to object reference 
 * \param[in] mb MessageBoard handle
 * \return pointer to MessageBoard object (\c NULL if handle invalid)
 * 
 * Performs the necessary assertions (if compiled in debug mode) and obtains
 * the associated board reference from the appropriate ObjectMap.
 */
void * MBI_getMBoardRef(MBt_Board mb) {
    
    /* make sure mboard object map valid */
    assert(MBI_OM_mboard != NULL);
    assert((int)MBI_OM_mboard->type == OM_TYPE_MBOARD);
    
    /* return object mapped to mb handle */
    return MBI_objmap_getobj(MBI_OM_mboard, (OM_key_t)mb);

}


/*! 
 * \brief wrapper routine for mapping Iterator handle to object reference 
 * \param[in] iter Iterator handle
 * \return pointer to Iterator object (\c NULL if handle invalid)
 * 
 * Performs the necessary assertions (if compiled in debug mode) and obtains
 * the associated Iterator reference from the appropriate ObjectMap.
 */
void * MBI_getIteratorRef(MBt_Iterator iter) {
    
    /* make sure mboard object map valid */
    assert(MBI_OM_iterator != NULL);
    assert((int)MBI_OM_iterator->type == OM_TYPE_ITERATOR);
    
    /* return object mapped to mb handle */
    return MBI_objmap_getobj(MBI_OM_iterator, (OM_key_t)iter);

}
