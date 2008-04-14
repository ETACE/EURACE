#include <CUnit/Basic.h>

#include "header.h"
#include "Clearinghouse_agent_header.h"
#include "my_library_header.h"

/************Clearinghouse Role: Financial Role ********************************/

/************ Unit tests ********************************/
void unittest_Clearinghouse_read_stock_orders()
{
    /************* At start of unit test, add one agent **************/
	add_Clearinghouse_agent_internal(init_Clearinghouse_agent());
	current_xmachine = *p_xmachine;

	/***** Variables: Memory pre-conditions **************************/
	
    /***** Function evaluation ***************************************/
	Clearinghouse_read_stock_orders();
    
    /***** Variables: Memory post-conditions *************************/
	
    /***** Messages: post-conditions *********************************/
 	START_STOCK_ORDER_MESSAGE_LOOP 
 		//stock_order_message(trader_id, stock_id, limit_price, limit_quantity, MSGDATA);
 		CU_ASSERT_EQUAL(stock_order_message->trader_id, <value>);
 		CU_ASSERT_EQUAL(stock_order_message->stock_id, <value>);
    	CU_ASSERT_DOUBLE_EQUAL(stock_order_message->limit_price, <value>, 1e-3);
 		CU_ASSERT_DOUBLE_EQUAL(stock_order_message->limit_quantity, <value>, 1e-3);
	FINISH_STOCK_ORDER_MESSAGE_LOOP

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Clearinghouse_compute_stock_transactions()
{
    /************* At start of unit test, add one agent **************/
	add_Clearinghouse_agent_internal(init_Clearinghouse_agent());
	current_xmachine = *p_xmachine;

	/***** Variables: Memory pre-conditions **************************/
	ID=1;
	TRADER_ID=0;
	STOCK_ID=0;
	LIMIT_PRICE=0.0;
	LIMIT_QUANTITY=0.0;
	
	/***** Messages input *********************************************/
	add_stock_order_message(1, 2, 1.0, 2.0, MSGDATA);
	
    /***** Function evaluation ***************************************/
	Clearinghouse_compute_stock_transactions();
    
    /***** Variables: Memory post-conditions *************************/

	/***** Messages: post-conditions *********************************/
 	START_STOCK_ORDER_MESSAGE_LOOP
		CU_ASSERT_EQUAL(stock_order_message->trader_id, 1);
		CU_ASSERT_EQUAL(stock_order_message->stock_id, 2);
		CU_ASSERT_DOUBLE_EQUAL(stock_order_message->limit_price, 1.0, 1e-3);
		CU_ASSERT_DOUBLE_EQUAL(stock_order_message->limit_quantity, 2.0, 1e-3);
	FINISH_STOCK_ORDER_MESSAGE_LOOP

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Clearinghouse_send_stock_transactions()
{
    /************* At start of unit test, add one agent **************/
	add_Clearinghouse_agent_internal(init_Clearinghouse_agent());
	current_xmachine = *p_xmachine;

	/***** Variables: Memory pre-conditions **************************/
	ID=1;
	TRADER_ID=2;
	STOCK_ID=3;
	LIMIT_PRICE=1.0;
	LIMIT_QUANTITY=2.0;
	
    /***** Function evaluation ***************************************/
	Clearinghouse_send_stock_transactions();
    
    /***** Variables: Memory post-conditions *************************/
	//CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
	//CU_ASSERT_EQUAL(<var_name2>, <value>);
	
    /***** Messages: post-conditions *********************************/
 	START_STOCK_TRANSACTION_MESSAGE_LOOP 
 		//stock_transaction_message(trader_id, stock_id, limit_price, limit_quantity, MSGDATA);
 		CU_ASSERT_EQUAL(stock_transaction_message->trader_id, 2);
 		CU_ASSERT_EQUAL(stock_transaction_message->stock_id, 3);
    	CU_ASSERT_DOUBLE_EQUAL(stock_transaction_message->limit_price, 1.0, 1e-3);
 		CU_ASSERT_DOUBLE_EQUAL(stock_transaction_message->limit_quantity, 2.0, 1e-3);
	FINISH_STOCK_TRANSACTION_MESSAGE_LOOP

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
