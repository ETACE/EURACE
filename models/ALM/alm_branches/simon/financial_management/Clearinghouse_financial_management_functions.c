#include "header.h"
#include "Clearinghouse_agent_header.h"
#include "my_library_header.h"

int Clearinghouse_read_stock_orders()
{
	START_STOCK_ORDER_MESSAGE_LOOP 
		//stock_order_message(id, bond_id, limit_price, limit_quantity, MSGDATA);
		//stock_order_message->id
		//stock_order_message->stock_id
		//stock_order_message->limit_price
		//stock_order_message->limit_quantity
	FINISH_STOCK_ORDER_MESSAGE_LOOP
	
	return 0;
}

int Clearinghouse_compute_stock_transactions()
{
	
	
	return 0;
}

int Clearinghouse_send_stock_transactions()
{
 	START_STOCK_TRANSACTION_MESSAGE_LOOP 
 		//stock_transaction_message(id, bond_id, limit_price, limit_quantity, MSGDATA);
 		//stock_transaction_message->id
 		//stock_transaction_message->stock_id
    	//stock_transaction_message->limit_price
 		//stock_transaction_message->limit_quantity
	FINISH_STOCK_TRANSACTION_MESSAGE_LOOP

	return 0;
}
