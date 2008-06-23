/* $Id: abort.c 769 2008-03-28 10:35:42Z lsc $ */
/*!
 * \file parallel/abort.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Mar 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Error management routines
 * 
 */
#include "mb_parallel.h"
#include <stdio.h>

void MBI_Abort(int rc, char * message) {
    
    /* TODO: free all data in boards */
    /* TODO: free all iterators */
    /* NOTE: Freeing memory here would be in vain since memory will only
     * be freed on the node that calls this routine. All other nodes
     * will be terminated by MPI_Abort() and leak memory (unless handled by MPI lib)!!!
     */

   fprintf(stderr, "LIBMBOARD ERROR ON P%d: ", MBI_CommRank);
   fprintf(stderr, message);
   fprintf(stderr, "\n***** ABORTING RUN *****\n\n");

    
    /* terminate all procs */
    MPI_Abort(MBI_CommWorld, rc);
}
