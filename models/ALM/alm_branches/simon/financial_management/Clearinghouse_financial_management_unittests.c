#include <CUnit/Basic.h>

#include "header.h"
#include "Clearinghouse_agent_header.h"
#include "my_library_header.h"

/************Clearinghouse Role: Financial Management Role ********************************/

/************ Unit tests ********************************/

void unittest_Clearinghouse_read_stock_orders()
{
    /************* At start of unit test, add one agent **************/
	add_Clearinghouse_agent(.......);

	/***** Variables: Memory pre-conditions **************************/
	<var_name1>=0.0;
	<var_name2>=0;
	
    /***** Function evaluation ***************************************/
	Clearinghouse_read_stock_orders();
    
    /***** Variables: Memory post-conditions *************************/
	CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
	CU_ASSERT_EQUAL(<var_name2>, <value>);
	
    /***** Messages send *********************************************/
 	START_STOCK_ORDER_MESSAGE_LOOP 
 		//stock_order_message(id, bond_id, limit_price, limit_quantity, MSGDATA);
 		CU_ASSERT_EQUAL(stock_order_message->id, <value>);
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
	add_Clearinghouse_agent(.......);

	/***** Variables: Memory pre-conditions **************************/
	<var_name1>=0.0;
	<var_name2>=0;
	
    /***** Function evaluation ***************************************/
	Clearinghouse_compute_stock_transactions();
    
    /***** Variables: Memory post-conditions *************************/
	CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
	CU_ASSERT_EQUAL(<var_name2>, <value>);
	
    /***** Messages send *********************************************/

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Clearinghouse_send_stock_transactions()
{
    /************* At start of unit test, add one agent **************/
	add_Clearinghouse_agent(.......);

	/***** Variables: Memory pre-conditions **************************/
	<var_name1>=0.0;
	<var_name2>=0;
	
    /***** Function evaluation ***************************************/
	Clearinghouse_send_stock_transactions();
    
    /***** Variables: Memory post-conditions *************************/
	CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
	CU_ASSERT_EQUAL(<var_name2>, <value>);
	
    /***** Messages send *********************************************/
 	START_STOCK_TRANSACTION_MESSAGE_LOOP 
 		//stock_transaction_message(id, bond_id, limit_price, limit_quantity, MSGDATA);
 		CU_ASSERT_EQUAL(stock_transaction_message->id, <value>);
 		CU_ASSERT_EQUAL(stock_transaction_message->stock_id, <value>);
    	CU_ASSERT_DOUBLE_EQUAL(stock_transaction_message->limit_price, <value>, 1e-3);
 		CU_ASSERT_DOUBLE_EQUAL(stock_transaction_message->limit_quantity, <value>, 1e-3);
	FINISH_STOCK_TRANSACTION_MESSAGE_LOOP

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}
