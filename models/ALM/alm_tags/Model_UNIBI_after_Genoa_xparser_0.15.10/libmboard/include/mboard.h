/* $Id: mboard.h 760 2008-03-20 14:40:48Z lsc $ */
/*!
 * \file mboard.h
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief This should be the only header file that has to 
 *        be included by libmboard users
 * \warning This library is currently not thread-safe
 * \warning This library is designed to work only on homogenous systems
 * 
 */
/*!
 * \mainpage Message Board Libary
 * 
 * (intro text and stuff here ...)
 * \todo When in debug mode, print useful messages if we know what is wrong
 *       instead of just using \c assert()
 * \todo Make the library thread-safe
 * \todo Implement parallel version
 * \todo Use automake/autoconf instead of custom Makefiles
 * \todo \c CUnit should be a dependency, not bundled with libmboard. Also add \c MPI 
 *       as dependency \c libmboard_p.
 * \todo Set up unit tests for parallel (might require some restructuring of /tests)
 * \todo Include code examples in doxygen comments
 */

/*!\ifnot userdoc 
 * \defgroup MB_API MessageBoard API
 * 
 * MessageBoard routines exposed to users.
 * \endif
 */
/*!\if userdoc 
 * \defgroup FUNC MessageBoard API Routines
 * 
 * Routines to create and use MessageBoards
 * \endif
 */
/*!\if userdoc 
 * \defgroup  RC Return Codes
 * 
 * All MessageBoard routines return an integer return code. It is recommended
 * that users check the return code for all calls, and include sufficient 
 * error handling if the call return an error code.
 * 
 * The following are possible return codes and their description.
 * \endif
 */
/*!\if userdoc 
 * \defgroup DT Datatypes
 * 
 * Datatypes provided by the API
 * \endif
 */
/*!\if userdoc 
 * \defgroup CONST Constants
 * 
 * Constants defined by the API
 * \endif
 */


#ifndef MBOARD_H_
#define MBOARD_H_

#include <stddef.h>
#include <limits.h>
#include "objmap.h"

/*! 
 * \var MBt_handle
 * \ingroup MB_API
 * \ingroup DT
 * \brief maping of opaque object handle to internal representation
 */
typedef OM_key_t MBt_handle; 

/* ========== DATATYPES ========== */

/*!
 * \var MBt_Board
 * \ingroup MB_API
 * \ingroup DT
 * \brief Handle for representing a MessageBoard
 */
typedef MBt_handle MBt_Board;

/*!
 * \var MBt_Iterator
 * \ingroup MB_API
 * \ingroup DT
 * \brief Handle for representing an Iterator
 */
typedef MBt_handle MBt_Iterator;


/* ========== User Routines ========== */

/* Initialise libmboard environment */
int MB_Env_Init(void);

/* Terminate libmboard environment */
int MB_Env_Finalise(void);

/* Indicate whether MPI_Env_Init has been called */
int MB_Env_Initialised(void);

/* Indicate whether MPI_Env_Finalised has been called */
int MB_Env_Finalised(void);

/* Create a new message board */
int MB_Create(MBt_Board *mb_ptr, size_t msgsize);

/* Add message to board */
int MB_AddMessage(MBt_Board mb, void *msg);

/* Clear all messages in board */
int MB_Clear (MBt_Board mb);

/* Delete board and free allocated memory */
int MB_Delete(MBt_Board *mb_ptr);

/* Create a message iterator */
int MB_Iterator_Create(MBt_Board mb, MBt_Iterator *itr_ptr);

/* Create a sorted message iterator */
int MB_Iterator_CreateSorted(MBt_Board mb, MBt_Iterator *itr_ptr, 
    int (*cmpFunc)(const void *msg1, const void *msg2) );

/* Create a filtered message iterator */
int MB_Iterator_CreateFiltered(MBt_Board mb, MBt_Iterator *itr_ptr, 
        int (*filterFunc)(const void *msg, const void *params), 
        void *filterFuncParams );

/* Create a filtered and sorted message iterator */
int MB_Iterator_CreateFilteredSorted(MBt_Board mb, MBt_Iterator *itr_ptr, 
        int (*filterFunc)(const void *msg, const void *params), 
        void *filterFuncParams, 
        int (*cmpFunc)(const void *msg1, const void *msg2) );

/* Delete an iterator */
int MB_Iterator_Delete(MBt_Iterator *itr_ptr);

/* Get next message from iterator */
int MB_Iterator_GetMessage(MBt_Iterator itr, void **msg_ptr);

/* Rewind Iterator */
int MB_Iterator_Rewind(MBt_Iterator itr);

/* Randomise an Iterator */
int MB_Iterator_Randomise(MBt_Iterator itr);

/* Initiate non-blocking synchronisation of message board */
int MB_SyncStart(MBt_Board mb);

/* Initiate non-blocking synchronisation of a group of message boards */
int MB_SyncStartGroup(MBt_Board *mb_array, int count);

/* Non-blocking routine to test synchronisation completion of message board  */
int MB_SyncTest(MBt_Board mb, int *flag);

/* Non-blocking routine to test synchronisation completion of message board group */
int MB_SyncTestGroup(MBt_Board *mb_array, int *flag_array, int count);

/* Complete non-blocking synchronisation of message board */
int MB_SyncComplete(MBt_Board mb);

/* Complete non-blocking synchronisation of message board group */
int MB_SyncCompleteGroup(MBt_Board *mb_array, int count);

/* Begin transaction block */
int MB_Transaction_Begin(void);

/* Commit transaction block */
int MB_Transaction_Commit(void);

/* =========== Constants ================= */



/*!
 * \def MB_NULL_MBOARD
 * \ingroup MB_API
 * \ingroup CONST
 * \brief Null Message Board
 */
#define MB_NULL_MBOARD     (MBt_Board)OM_NULL_INDEX

/*!
 * \def MB_NULL_ITERATOR
 * \ingroup MB_API
 * \ingroup CONST
 * \brief Null Iterator
 */
#define MB_NULL_ITERATOR   (MBt_Iterator)OM_NULL_INDEX

/*!
 * \def MB_PENDING_MBOARD
 * \ingroup MB_API
 * \ingroup CONST
 * \brief Message Board handle pending end of transaction
 */
#define MB_PENDING_MBOARD  (MBt_Board)OM_DUMMY_INDEX_1

/*!
 * \def MB_TRUE
 * \ingroup MB_API
 * \ingroup CONST
 * \brief Internal representation of TRUE (logical)
 */

#define MB_TRUE 1
/*!
 * \def MB_FALSE
 * \ingroup MB_API
 * \ingroup CONST
 * \brief Internal representation of FALSE (logical)
 */
#define MB_FALSE -1

/* ========== RETURN TYPES ========== */

/*!
 * \def MB_SUCCESS
 * \ingroup MB_API
 * \ingroup RC
 * \brief Return Code: Success
 * 
 * Specifies a successful execution
 */
#define MB_SUCCESS     0

/*!
 * \def MB_ERR_MEMALLOC
 * \ingroup MB_API
 * \ingroup RC
 * \brief Return Code: Memory allocation error
 * 
 * Failed to allocate required memory.
 */
#define MB_ERR_MEMALLOC 1

/*!
 * \def MB_ERR_INVALID
 * \ingroup MB_API
 * \ingroup RC
 * \brief Return Code: Input error
 * 
 * One or more of the given input is invalid
 */
#define MB_ERR_INVALID  2 

/*!
 * \def MB_ERR_LOCKED
 * \ingroup MB_API
 * \ingroup RC
 * \brief Return Code: Object locked
 * 
 * Operation cannot proceed due to object being locked by another process
 */
#define MB_ERR_LOCKED   3 

/*!
 * \def MB_ERR_MPI
 * \ingroup MB_API
 * \ingroup RC
 * \brief Return Code: MPI Error
 * 
 * An MPI related error has occured. 
 */
#define MB_ERR_MPI 4

/*!
 * \def MB_ERR_ENV
 * \ingroup MB_API
 * \ingroup RC
 * \brief Return Code: Environment Error
 * 
 * Specifies error due uninitalised or invalid environment state 
 */
#define MB_ERR_ENV      5 

/*!
 * \def MB_ERR_INTERNAL
 * \ingroup MB_API
 * \ingroup RC
 * \brief Return Code: Internal Error
 * 
 * Specifies internal implementation error. 
 * 
 * To identify the problem, try recompiling libmboard in debug mode, relink
 * your application, and check and assertion 
 */
#define MB_ERR_INTERNAL 6   

/*!
 * \def MB_ERR_USER
 * \ingroup MB_API
 * \ingroup RC
 * \brief Return Code: User Error
 * 
 * Specifies error due to something the user has done (or not done). See 
 * documentation or any output message for details.
 */
#define MB_ERR_USER 7   

/*!
 * \def MB_ERR_NOT_IMPLEMENTED
 * \ingroup MB_API
 * \ingroup RC
 * \brief Return Code: Not Implemented
 * 
 * Requested operation has not been implemented
 * 
 */
#define MB_ERR_NOT_IMPLEMENTED 100



#endif /*MBOARD_H_*/


/* =================== BEGIN USER DOCUMENTATION =========================== */
/* -- Doxygen comments below will be used only in the User Documentation -- */

/*!\if userdoc
 * \fn MB_Env_Init(void)
 * \ingroup FUNC
 * \brief Initialises the libmboard environment
 * 
 * This routine has to be called before any other libmboard routines 
 * (apart for MB_Env_Initialised() and MB_Env_Finalised()).
 * 
 * The libmboard environment should not be re-initialised once it
 * has been finalised.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_MPI (MPI Environment not yet started)
 *  - ::MB_ERR_ENV (libmboard environment already started)
 *  - ::MB_ERR_MALLOC (unable to allocate required memory)
 * 
 * \endif
 */

/*!\if userdoc
 * \fn MB_Env_Finalise (void)
 * \ingroup FUNC
 * \brief Finalises the libmboard environment
 * 
 * This should be the last libmboard routine called within a program 
 * (apart for MB_Env_Initialised() and MB_Env_Finalised()).
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_ENV (libmboard environment not yet started, or already finalised)
 * 
 * \endif
 */

/*!\if userdoc
 * \fn MB_Env_Initialised (void)
 * \ingroup FUNC
 * \brief Indicates whether MB_Env_Init() has been called successfully
 * 
 * This routine will return ::MB_SUCCESS if the environment has been initialised, 
 * or ::MB_ERR_ENV otherwise.
 * 
 *  Possible return codes:
 *  - ::MB_SUCCESS 
 *  - ::MB_ERR_ENV (libmboard environment was not successfully set up, 
 *                 or, has already been finalised)
 * 
 * \endif
 */

/*!\if userdoc
 * \fn MB_Env_Finalised(void)
 * \ingroup FUNC
 * \brief Indicates whether MB_Env_Finalise() has been called
 * 
 * This routine will return ::MB_SUCCESS if the environment has been finalised, 
 * or ::MB_ERR_ENV otherwise.
 * 
 *  Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_ENV (libmboard environment has not been finalised)
 * 
 * \endif
 */

/*!\if userdoc
 * \fn MB_Create(MBt_Board *mb_ptr, size_t msgsize)
 * \ingroup FUNC
 * \brief Instantiates a new MessageBoard
 * \param[out] mb_ptr Address of MessageBoard handle
 * \param[in] msgsize Size of message that this MessageBoard will be used for
 * 
 * Creates a new board for storing messages of size \c msgsize and returns a 
 * handle to the board via \c mb_ptr .
 *  
 * In the parallel version, this routine is blocking and will return when 
 * all processes have issued and completed the call. This effectively 
 * synchronises all processes. It is the users' responsibility to ensure 
 * that all processes issue the call (with the same values of \c msgsize) 
 * to prevent deadlocks.
 * 
 * If this routine returns with an error, \c mb_ptr will remain unchanged.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c msgsize is invalid)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example:
 * \include ex_mb_create.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_AddMessage(MBt_Board mb, void *msg)
 * \ingroup FUNC
 * \brief Adds a message to the MessageBoard
 * \param[in] mb MessageBoard handle
 * \param[in] msg Address of the message to be added
 * 
 * Messages added to the board must be of the size specified
 * during the creation of the board. Adding messages of a different size
 * may not cause an error code to be returned, but will lead to unexpected
 * behavior and possible segmentation faults.
 * 
 * The message data is cloned and stored in the message board. Users are
 * free to modify, reuse, or deallocate their copy of the message after
 * this routine has completed.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is null or invalid)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_LOCKED (\c mb is locked by another process)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example:
 * \include ex_mb_addmessage.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Clear(MBt_Board mb)
 * \ingroup FUNC
 * \brief Clears the MessageBoard
 * \param[in] mb MessageBoard handle
 * 
 * Deletes all messages from the board. Once cleared, the board can be reused
 * for adding messages of the same type.
 * 
 * Once a board is cleared, all Iterators associated with the board is no longer
 * valid and has to be recreated. It is the users' responsibility to ensure 
 * that invalidated Iterators are not used.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is null or invalid)
 *  - ::MB_ERR_LOCKED (\c mb is locked by another process)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example:
 * \include ex_mb_clear.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Delete(MBt_Board *mb_ptr)
 * \ingroup FUNC
 * \brief Deletes a MessageBoard
 * \param[in,out] mb_ptr Address of MessageBoard handle
 * 
 * Upon successful deletion, the handle referenced by \c mb_ptr will be set 
 * to ::MB_NULL_MBOARD . This handle can be reused when creating a new board.
 * 
 * If an error occurs, \c mb_ptr will remain unchanged.
 * 
 * If a null board (::MB_NULL_MBOARD) is passed in, the routine will return 
 * immediately with ::MB_SUCCESS
 * 
 * Once a board is deleted, all Iterators associated with the board is no longer
 * valid. It is the users' responsibility to ensure that invalidated Iterators 
 * are not used.
 * 
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is invalid)
 *  - ::MB_ERR_LOCKED (\c mb is locked by another process)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example:
 * \include ex_mb_delete.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Iterator_Create(MBt_Board mb, MBt_Iterator *itr_ptr)
 * \ingroup FUNC
 * \brief Creates a new Iterator for accessing messages in board \c mb
 * \param[in] mb MessageBoard handle
 * \param[out] itr_ptr Address of Iterator Handle
 * 
 * Upon successful creation of Iterator, the routine  
 * returns a handle to the Iterator via \c itr_ptr .
 *  
 * Attempts to create an Iterator against a null board (::MB_NULL_MBOARD) will 
 * result in an ::MB_ERR_INVALID error.
 * 
 * If this routine returns with an error, \c itr_ptr will remain unchanged.
 * 
 * \warning The Iterator will remain valid as long as the board it was created for
 * is not modified, cleared or deleted. Reading messages from an invalid 
 * Iterator will lead to undefined behaviour and possible segmentation 
 * faults. It is the users' responsibility to ensure that only valid Iterators 
 * are used.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is null or invalid)
 *  - ::MB_ERR_LOCKED (\c mb is locked by another process)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example:
 * \include ex_mb_it_create.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Iterator_CreateSorted(MBt_Board mb, MBt_Iterator *itr_ptr, int (*cmpFunc)(const void *msg1, const void *msg2))
 * \ingroup FUNC
 * \brief Creates a new Iterator for accessing sorted messages in board \c mb
 * \param[in] mb MessageBoard handle
 * \param[out] itr_ptr Address of Iterator Handle
 * \param[in] cmpFunc Pointer to user-defined comparison function
 * 
 * Creates a new Iterator for accessing messages in board \c mb, and 
 * returns a handle to the iterator via \c itr_ptr. This Iterator will allow 
 * users to retrieve ordered messages from \c mb without modifying the board
 * itself.
 * 
 * The user-defined comparison function (\c cmpFunc) must return an integer 
 * less than, equal to, or greater than zero if the first message is 
 * considered to be respectively less than, equal to, or greater than the 
 * second. In short:
 *  - <tt>0 if (msg1 == msg2)</tt>
 *  - <tt>< 0 if (msg1 < msg2)</tt>
 *  - <tt>> 0 if (msg1 > msg2)</tt>
 *  
 * If two members compare as equal, their order in the sorted Iterator is undefined.
 * 
 * Attempts to create an Iterator against a null board (::MB_NULL_MBOARD) will 
 * result in an ::MB_ERR_INVALID error.
 * 
 * If this routine returns with an error, \c itr_ptr will remain unchanged.
 * 
 * \warning The Iterator will remain valid as long as the board it was created for
 * is not modified, cleared or deleted. Reading messages from an invalid 
 * Iterator will lead to undefined behaviour and possible segmentation 
 * faults. It is the users' responsibility to ensure that Iterators are
 * not invalidated before they are used.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is null or invalid)
 *  - ::MB_ERR_LOCKED (\c mb is locked by another process)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example:
 * \include ex_mb_it_create_s.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Iterator_CreateFiltered(MBt_Board mb, MBt_Iterator *itr_ptr, int (*filterFunc)(const void *msg, const void *params), void *filterFuncParams )
 * \ingroup FUNC
 * \brief Creates a new Iterator for accessing a selection of messages 
 *        in board \c mb 
 * \param[in] mb MessageBoard handle
 * \param[out] itr_ptr Address of Iterator Handle
 * \param[in] filterFunc Pointer to user-defined filter function
 * \param[in] filterFuncParams Pointer to input data that will be passed into \c filterFunc 
 * 
 * Creates a new Iterator for accessing messages in board \c mb, and 
 * returns a handle to the iterator via \c itr_ptr. This Iterator will allow 
 * users to retrieve a filtered selection of messages from \c mb without modifying the board
 * itself.
 * 
 * The user-defined filter function (\c filterFunc) must return \c 0 if a message is to be
 * rejected by the filter, or \c 1 if it is to be accepted.
 * 
 * The \c filterFuncParam argument allows users to pass on additional information
 * to \c filterFunc (see example code below). Users may use\c NULL in place of 
 * \c filterFuncParam if \c filterFunc does not require additional information.
 * 
 * Attempts to create an Iterator against a null board (::MB_NULL_MBOARD) will 
 * result in an ::MB_ERR_INVALID error.
 * 
 * If this routine returns with an error, \c itr_ptr will remain unchanged.
 * 
 * \warning The Iterator will remain valid as long as the board it was created for
 * is not modified, cleared or deleted. Reading messages from an invalid 
 * Iterator will lead to undefined behaviour and possible segmentation 
 * faults. It is the users' responsibility to ensure that Iterators are
 * not invalidated before they are used.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is null or invalid)
 *  - ::MB_ERR_LOCKED (\c mb is locked by another process)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example:
 * \include ex_mb_it_create_f.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Iterator_CreateFilteredSorted(MBt_Board mb, MBt_Iterator *itr_ptr, int (*filterFunc)(const void *msg, const void *params), void *filterFuncParams, int (*cmpFunc)(const void *msg1, const void *msg2))
 * \ingroup FUNC
 * \brief Instantiates a new Iterator for accessing a sorted selection of 
 *        messages in board \c mb 
 * \param[in] mb MessageBoard handle
 * \param[out] itr_ptr Address of Iterator Handle
 * \param[in] filterFunc Pointer to user-defined filter function
 * \param[in] filterFuncParams Pointer to input data that will be passed into \c filterFunc 
 * \param[in] cmpFunc Pointer to user-defined compariosn function
 *  
 * Creates a new Iterator for accessing messages in board \c mb, and 
 * returns a handle to the iterator via \c itr_ptr. This Iterator will allow 
 * users to retrieve a filtered selection of ordered messages from \c mb 
 * without modifying the board itself.
 * 
 * The user-defined filter function (\c filterFunc) must return \c 0 if a message is to be
 * rejected by the filter, or \c 1 if it is to be accepted.
 * 
 * The \c filterFuncParam argument allows users to pass on additional information
 * to \c filterFunc (see example code below). Users may use\c NULL in place of 
 * \c filterFuncParam if \c filterFunc does not require additional information.
 * 
 * The user-defined comparison function (\c cmpFunc) must return an integer 
 * less than, equal to, or greater than zero if the first message is 
 * considered to be respectively less than, equal to, or greater than the 
 * second. In short:
 *  - <tt>0 if (msg1 == msg2)</tt>
 *  - <tt>\< 0 if (msg1 \< msg2)</tt>
 *  - <tt>\> 0 if (msg1 \> msg2)</tt>
 * 
 * Attempts to create an Iterator against a null board (::MB_NULL_MBOARD) will 
 * result in an ::MB_ERR_INVALID error.
 * 
 * If this routine returns with an error, \c itr_ptr will remain unchanged.
 * 
 * \warning The Iterator will remain valid as long as the board it was created for
 * is not modified, cleared or deleted. Reading messages from an invalid 
 * Iterator will lead to undefined behaviour and possible segmentation 
 * faults. It is the users' responsibility to ensure that Iterators are
 * not invalidated before they are used.
 *
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is null or invalid)
 *  - ::MB_ERR_LOCKED (\c mb is locked by another process)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example:
 * \include ex_mb_it_create_fs.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Iterator_Delete(MBt_Iterator *itr_ptr)
 * \ingroup FUNC
 * \brief Deletes an Iterator
 * \param[in,out] itr_ptr Address of Iterator Handle
 * 
 * Upon successful deletion, the handle referenced by \c itr_ptr will be set 
 * to ::MB_NULL_ITERATOR . This handle can be reused when creating a new 
 * Iterator of any kind.
 * 
 * If an error occurs, \c itr_ptr will remain unchanged.
 * 
 * If a null Iterator (::MB_NULL_ITERATOR) is passed in, the routine will return 
 * immediately with ::MB_SUCCESS
 * 
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c itr is invalid)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example:
 * \include ex_mb_it_delete.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Iterator_GetMessage(MBt_Iterator itr, void **msg_ptr)
 * \ingroup FUNC
 * \brief Returns next available message from Iterator
 * \param[in] itr Iterator Handle
 * \param[out] msg_ptr Address where reference to message will be written to
 * 
 * After a successful call to the routine, \c msg_ptr will be assigned with 
 * the reference to a newly allocated memory block containing the message 
 * data. It is the user's responsibility to free the memory associated with the 
 * returned msg.
 *
 * When there are no more messages to return, \c msg_ptr will be assigned with
 * \c NULL and the routine shall complete with the ::MB_SUCCESS return code.
 *
 * Any attempts to get a message from a null Iterator (::MB_NULL_ITERATOR) will 
 * result in an ::MB_ERR_INVALID error.
 * 
 * In the event of an error, msg will be assigned \c NULL and the routine shall
 * return with an appropriate error code.
 * 
 * \warning If the given Iterator is invalidated due to a deleted/cleared board, the
 * data returned by this routine will not be valid. 
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c itr is null of invalid)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 * 
 * Usage example:
 * \include ex_mb_it_getmessage.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Iterator_Rewind(MBt_Iterator itr)
 * \ingroup FUNC
 * \brief Rewinds an Iterator
 * \param[in] itr Iterator Handle
 * 
 * Resets the internal counters such that the next MB_Iterator_GetMessage() 
 * call on the given Iterator will obtain the first message in the list 
 * (or \c NULL if the Iterator is empty).
 * 
 * Rewinding a null Iterator (::MB_NULL_ITERATOR) will result in an 
 * ::MB_ERR_INVALID error.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c itr is null or invalid)
 * 
 * Usage example:
 * \include ex_mb_it_rewind.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_Iterator_Randomise(MBt_Iterator itr)
 * \ingroup FUNC
 * \brief Randomises the order of entries in an Iterator
 * \param[in] itr Iterator Handle
 * 
 * Apart from randomising the order of entries in the Iterator, this routine 
 * will also reset the internal counters leading to an effect similar to that
 * of MB_Iterator_Rewind().
 * 
 * Randomising a null Iterator (::MB_NULL_ITERATOR) will result in an 
 * ::MB_ERR_INVALID error.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c itr is null or invalid)
 * 
 * Usage example:
 * \include ex_mb_it_randomise.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_SyncStart(MBt_Board mb)
 * \ingroup FUNC
 * \brief Synchronises the content of the board across all processes
 * \param[in] mb MessageBoard Handle
 * 
 * This is a non-blocking routine which returns immediately after 
 * locking the message board and intialising the synchronisation 
 * process. The board should not be modified, cleared, or deleted 
 * until the synchronisation process is completed using either
 * MB_SyncComplete() or MB_SyncCompleteGroup() .
 * 
 * In the serial version, this routine would not do 
 * anything apart from locking the message board. 
 * 
 * Synchronisation of a null board (::MB_NULL_MBOARD) is valid, and will 
 * return immediately with ::MB_SUCCESS
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is invalid)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 *  - ::MB_ERR_LOCKED (\c mb is locked by another process)
 * 
 * Usage example:
 * \include ex_mb_sync.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_SyncStartGroup(MBt_Board *mb_array, int count)
 * \ingroup FUNC
 * \brief Synchronises the content of the board across all processes
 * \param[in] mb_array Reference to array of MessageBoard Handles
 * \param[in] count Number of elements in array
 * 
 * This is a non-blocking routine which returns immediately after 
 * locking the message boards and intialising the synchronisation 
 * process. The boards should not be modified, cleared, or deleted 
 * until the synchronisation process is completed using either
 * MB_SyncComplete() or MB_SyncCompleteGroup() .
 * 
 * In the serial version, this routine would not do 
 * anything apart from locking the message boards. 
 * 
 * If any of the given boards is invalid or locked, synchronisation 
 * will not be performed for any of the boards, and the routine will return 
 * immediately with the ::MB_ERR_INVALID or ::MB_ERR_LOCKED status.
 * 
 * Synchronisation of null boards (::MB_NULL_BOARD) is valid and will return 
 * successfully.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (one or more of the boards in \c mb_array is invalid)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 *  - ::MB_ERR_LOCKED (one or more of the boards in \c mb_array  is locked by another process)
 * 
 * Usage example:
 * \include ex_mb_syncgroup.c
 * \endif
 */

/*!\if userdoc
 * \fn MB_SyncTest(MBt_Board mb, int *flag)
 * \ingroup FUNC
 * \brief Inspects the completion status of a board synchronisation
 * \param[in] mb MessageBoard Handle
 * \param[out] flag address where return value will be written to
 * 
 * This routine is non-blocking, and will return immediately after setting the
 * \c flag value to either ::MB_TRUE or ::MB_FALSE depending on the 
 * synchronisation completion status.
 * 
 * Testing a null board (::MB_NULL_MBOARD) or one that is not being 
 * synchronised will always return with the ::MB_TRUE flag and ::MB_SUCCESS 
 * return code.
 * 
 * In the serial version, this routine will always return ::MB_TRUE as
 * synchronisation is assumed to be completed immediately after it started.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is invalid)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example: see MB_SyncStart()
 * \endif
 */

/*!\if userdoc
 * \fn MB_SyncTestGroup(MBt_Board *mb_array, int *flag_array, int count)
 * \ingroup FUNC
 * \brief Inspects the completion status of synchronisation for a group of boards
 * \param[in] mb_array Reference to array of MessageBoard Handle
 * \param[out] flag_array address or array where return values will be written to
 * \param[in] count Number of elements in array
 * 
 * This routine is non-blocking, and will return immediately after setting 
 * the \c flag_array values. Each element in \c flag_array will be set to 
 * either ::MB_TRUE or ::MB_FALSE depending on the synchronisation completion 
 * status of the corresponding board in \c mb_array.
 * 
 * If any of the given boards is invalid, the routine will return immediately 
 * with the ::MB_ERR_INVALID status. No tests will be performed, and all flags 
 * will be set to ::MB_FALSE.
 * 
 * Testing a null board (::MB_NULL_MBOARD) or one that is not being 
 * synchronised will always return with the ::MB_TRUE flag and ::MB_SUCCESS 
 * return code.
 * 
 * In the serial version, this routine will always return ::MB_TRUE for all
 * entries as synchronisation is assumed to be completed immediately after it 
 * started.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (one or more of the boards in \c mb_array is invalid)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example: see MB_SyncStartGroup()
 * \endif
 */

/*!\if userdoc
 * \fn MB_SyncComplete(MBt_Board mb)
 * \ingroup FUNC
 * \brief Completes the synchronisation of a board
 * \param[in] mb MessageBoard Handle
 * 
 * This routine will block until the synchronisation of the board has
 * completed. Upon successful execution of this routine, the board
 * will be unlocked and ready for access.
 * 
 * In the serial version, this routine would not do 
 * anything apart from unlocking the message board. 
 * 
 * Synchronisation of a null board (::MB_NULL_MBOARD) is valid, and will 
 * return immediately with ::MB_SUCCESS
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (\c mb is invalid)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example: see MB_SyncStart()
 * \endif
 */

/*!\if userdoc
 * \fn MB_SyncCompleteGroup(MBt_Board *mb_array, int count)
 * \ingroup FUNC
 * \brief Completes the synchronisation of a group of boards
 * \param[in] mb_array Reference to array of MessageBoard Handles
 * \param[in] count Number of elements in array
 * 
 * This routine will block until the synchronisation of the all boards have
 * completed. Upon successful execution of this routine, the boards
 * will be unlocked and ready for access.
 * 
 * In the serial version, this routine would not do 
 * anything apart from unlocking the boards. 
 * 
 * If any of the given boards is invalid, the routine will return immediately 
 * with the ::MB_ERR_INVALID status. No tests will be performed, and all flags 
 * will be set to ::MB_FALSE.
 * 
 * Synchronisation of null boards (::MB_NULL_BOARD) is valid and will return 
 * successfully.
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID (one or more of the boards in \c mb_array is invalid)
 *  - ::MB_ERR_MEMALLOC (unable to allocate required memory)
 *  - ::MB_ERR_INTERNAL (internal error, possibly a bug)
 * 
 * Usage example: see MB_SyncStartGroup()
 * \endif
 */

