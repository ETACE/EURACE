#include "header.h"
#include "Clearinghouse_agent_header.h"
#include "my_library_header.h"

/*
 * \fn: int Clearinghouse_read_stock_orders()
 * \brief: reads stock_order msgs and stores them in memory vars.
 * To test, we simply copy the limit_price and limit_quantity from the traders order msg and set the mem vars to these values.
 */
int Clearinghouse_read_stock_orders()
{
	START_STOCK_ORDER_MESSAGE_LOOP 
		//stock_order_message(trader_id, bond_id, limit_price, limit_quantity, MSGDATA);
		TRADER_ID = stock_order_message->trader_id
		STOCK_ID = stock_order_message->stock_id
		LIMIT_PRICE = stock_order_message->limit_price
		LIMIT_QUANTITY = stock_order_message->limit_quantity
	FINISH_STOCK_ORDER_MESSAGE_LOOP
	
	return 0;
}

/*
 * \fn: int Clearinghouse_compute_stock_transactions()
 * \brief: Computes stock transactions.
 */
int Clearinghouse_compute_stock_transactions()
{
	
	
	return 0;
}

/*
 * \fn: int Clearinghouse_send_stock_transactions()
 * \brief: Sends stock transaction msgs.
 */
int Clearinghouse_send_stock_transactions()
{
	//stock_transaction_message(trader_id, stock_id, limit_price, limit_quantity, MSGDATA);
	add_stock_transaction_message(TRADER_ID, STOCK_ID, LIMIT_PRICE, LIMIT_QUANTITY, MSGDATA);

	return 0;
}
