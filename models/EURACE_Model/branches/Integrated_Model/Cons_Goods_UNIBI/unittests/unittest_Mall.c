#include <CUnit/Basic.h>
#include "../../header.h"
#include "../../Mall_agent_header.h"
#include "../../my_library_header.h"
#include "../Mall_aux_header.h"

void unittest_Mall_update_mall_stock()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	
 		reset_mall_stock_array(&CURRENT_STOCK);
    	add_mall_stock(&CURRENT_STOCK, 2, 1, 50.0,1.5,1.0,1.0);
   		add_mall_stock(&CURRENT_STOCK, 3, 1, 40.0,1.5,1.0,1.0);
	

	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_update_mall_stock, sizeof(m_update_mall_stock));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'update_mall_stock' board\n");
    	       switch(rc) {
    	           case MB_ERR_INVALID:
    	               fprintf(stderr, "\t reason: Invalid message size\n");
    	               break;
    	           case MB_ERR_MEMALLOC:
    	               fprintf(stderr, "\t reason: out of memory\n");
    	               break;
    	           case MB_ERR_INTERNAL:
    	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
    	               break;
    	       }
    	    }
    	    #endif
    	    
    	    /***** Messages: initialize message boards **********************************/

    	    	rc = MB_Create(&b_bankruptcy_illiquidity, sizeof(m_bankruptcy_illiquidity));
    	        	    #ifdef ERRCHECK
    	        	    if (rc != MB_SUCCESS)
    	        	    {
    	        	       fprintf(stderr, "ERROR: Could not create 'bankruptcy_illiquidity' board\n");
    	        	       switch(rc) {
    	        	           case MB_ERR_INVALID:
    	        	               fprintf(stderr, "\t reason: Invalid message size\n");
    	        	               break;
    	        	           case MB_ERR_MEMALLOC:
    	        	               fprintf(stderr, "\t reason: out of memory\n");
    	        	               break;
    	        	           case MB_ERR_INTERNAL:
    	        	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
    	        	               break;
    	        	       }
    	        	    }
    	        	    #endif
    	        	 
    	        	    
	/***** Messages: pre-conditions **********************************/
   add_update_mall_stock_message(1,2,20.0,1.0,2.0,1.5);
   add_update_mall_stock_message(1,3,10.0,1.0,2.0,1.5);
   
    	    
    /***** Message: Adding message iterators ***************************************/
	rc = MB_Iterator_Create(b_bankruptcy_illiquidity, &i_bankruptcy_illiquidity);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'bankruptcy_illiquidity'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'update_mall_stock board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}
	
	rc = MB_Iterator_Create(b_update_mall_stock, &i_update_mall_stock);
				
		if (rc != MB_SUCCESS)
				{
				   fprintf(stderr, "ERROR: Could not create Iterator for 'update_mall_stock'\n");
				   switch(rc) {
				       case MB_ERR_INVALID:
				           fprintf(stderr, "\t reason: 'update_mall_stock' board is invalid\n");
				           break;
				       case MB_ERR_LOCKED:
			               fprintf(stderr, "\t reason: 'update_mall_stock board is locked\n");
			               break;
			           case MB_ERR_MEMALLOC:
			               fprintf(stderr, "\t reason: out of memory\n");
			               break;
			           case MB_ERR_INTERNAL:
			               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			               break;
				   }
				}

    /***** Function evaluation ***************************************/
	Mall_update_mall_stock();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_EQUAL(CURRENT_STOCK.array[0].firm_id, 2);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[0].stock, 70, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[0].price, 2.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[0].previous_price, 1.5, 1e-3);
	
	CU_ASSERT_EQUAL(CURRENT_STOCK.array[1].firm_id, 3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[1].stock, 50, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[1].price, 2.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[1].previous_price, 1.5, 1e-3);
  
    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * Case 2: 1 firm is in bancruptcy
 * 
 * */
void unittest_Mall_update_mall_stock_2()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	
 		reset_mall_stock_array(&CURRENT_STOCK);
    	add_mall_stock(&CURRENT_STOCK, 2, 1, 50.0,1.5,1.0,1.0);
   		add_mall_stock(&CURRENT_STOCK, 3, 1, 40.0,1.5,1.0,1.0);
	

	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_update_mall_stock, sizeof(m_update_mall_stock));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'update_mall_stock' board\n");
    	       switch(rc) {
    	           case MB_ERR_INVALID:
    	               fprintf(stderr, "\t reason: Invalid message size\n");
    	               break;
    	           case MB_ERR_MEMALLOC:
    	               fprintf(stderr, "\t reason: out of memory\n");
    	               break;
    	           case MB_ERR_INTERNAL:
    	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
    	               break;
    	       }
    	    }
    	    #endif
    	    
    	    /***** Messages: initialize message boards **********************************/

    	    	rc = MB_Create(&b_bankruptcy_illiquidity, sizeof(m_bankruptcy_illiquidity));
    	        	    #ifdef ERRCHECK
    	        	    if (rc != MB_SUCCESS)
    	        	    {
    	        	       fprintf(stderr, "ERROR: Could not create 'bankruptcy_illiquidity' board\n");
    	        	       switch(rc) {
    	        	           case MB_ERR_INVALID:
    	        	               fprintf(stderr, "\t reason: Invalid message size\n");
    	        	               break;
    	        	           case MB_ERR_MEMALLOC:
    	        	               fprintf(stderr, "\t reason: out of memory\n");
    	        	               break;
    	        	           case MB_ERR_INTERNAL:
    	        	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
    	        	               break;
    	        	       }
    	        	    }
    	        	    #endif
    	        	 
    	        	    
	/***** Messages: pre-conditions **********************************/
   add_update_mall_stock_message(1,2,20.0,1.0,2.0,1.5);
   add_bankruptcy_illiquidity_message(3);
   
    	    
    /***** Message: Adding message iterators ***************************************/
	rc = MB_Iterator_Create(b_bankruptcy_illiquidity, &i_bankruptcy_illiquidity);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'bankruptcy_illiquidity'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'update_mall_stock board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}
	
	rc = MB_Iterator_Create(b_update_mall_stock, &i_update_mall_stock);
				
		if (rc != MB_SUCCESS)
				{
				   fprintf(stderr, "ERROR: Could not create Iterator for 'update_mall_stock'\n");
				   switch(rc) {
				       case MB_ERR_INVALID:
				           fprintf(stderr, "\t reason: 'update_mall_stock' board is invalid\n");
				           break;
				       case MB_ERR_LOCKED:
			               fprintf(stderr, "\t reason: 'update_mall_stock board is locked\n");
			               break;
			           case MB_ERR_MEMALLOC:
			               fprintf(stderr, "\t reason: out of memory\n");
			               break;
			           case MB_ERR_INTERNAL:
			               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			               break;
				   }
				}

    /***** Function evaluation ***************************************/
	Mall_update_mall_stock();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_EQUAL(CURRENT_STOCK.array[0].firm_id, 2);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[0].stock, 70, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[0].price, 2.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[0].previous_price, 1.5, 1e-3);
	
	CU_ASSERT_EQUAL(CURRENT_STOCK.array[1].firm_id, 3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[1].stock, 0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[1].price, 0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[1].previous_price, 0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CURRENT_STOCK.array[1].quality, 0, 1e-3);
    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Mall_send_quality_price_info_1()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Mall_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	
		ID  = 1;
		REGION_ID = 1;

		reset_mall_stock_array(&CURRENT_STOCK);
	    add_mall_stock(&CURRENT_STOCK, 2, 1, 50.0,2.5,2.0,1.0);
	   	add_mall_stock(&CURRENT_STOCK, 3, 1, 0.0,1.5,1.4,1.0);
	
	/***** Messages: initialize message boards **********************************/

	rc = MB_Create(&b_quality_price_info_1, sizeof(m_quality_price_info_1));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'quality_price_info_1' board\n");
    	       switch(rc) {
    	           case MB_ERR_INVALID:
    	               fprintf(stderr, "\t reason: Invalid message size\n");
    	               break;
    	           case MB_ERR_MEMALLOC:
    	               fprintf(stderr, "\t reason: out of memory\n");
    	               break;
    	           case MB_ERR_INTERNAL:
    	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
    	               break;
    	       }
    	    }
    	    #endif
	
    	    Mall_send_quality_price_info_1();    
    	    
    /***** Message: Adding message iterators ***************************************/
    rc = MB_Iterator_Create(b_quality_price_info_1, &i_quality_price_info_1);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for '<message>'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'quality_price_info_1' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'quality_price_info_1' board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}

    /***** Function evaluation ***************************************/
	
    


     /***** Messages: Message post-conditions *****/
	//start a reading loop

    START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP
    	if(quality_price_info_1_message->firm_id == 2)
    	{
	     CU_ASSERT_EQUAL(quality_price_info_1_message->mall_region_id, 1);
	     CU_ASSERT_DOUBLE_EQUAL(quality_price_info_1_message->price, 2.5, 1e-3);
	     CU_ASSERT_DOUBLE_EQUAL(quality_price_info_1_message->quality, 2.0, 1e-3);
	     CU_ASSERT_EQUAL(quality_price_info_1_message->available, 1);
    	}
    
    if(quality_price_info_1_message->firm_id ==3)
        	{
    	     CU_ASSERT_EQUAL(quality_price_info_1_message->mall_region_id, 1);
    	     CU_ASSERT_DOUBLE_EQUAL(quality_price_info_1_message->price, 1.5, 1e-3);
    	     CU_ASSERT_DOUBLE_EQUAL(quality_price_info_1_message->quality, 1.4, 1e-3);
    	     CU_ASSERT_EQUAL(quality_price_info_1_message->available, 0);
        	}
	FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Mall_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
