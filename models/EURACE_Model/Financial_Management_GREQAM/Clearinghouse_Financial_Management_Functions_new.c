#include "../header.h"
#include "../Clearinghouse_agent_header.h"
#include "../my_library_header.h"

/*
 * \fn: int Clearinghouse_read_stock_orders()
 * \brief: reads stock_order msgs and stores them in memory vars.
 * To test, we simply copy the limit_price and limit_quantity from the traders order msg and set the mem vars to these values.
 */
int Clearinghouse_read_stock_orders()
{
	START_STOCK_ORDER_MESSAGE_LOOP 
		//stock_order_message(trader_id, bond_id, limit_price, limit_quantity, MSGDATA);
		TRADER_ID = stock_order_message->trader_id;
		STOCK_ID = stock_order_message->stock_id;
		LIMIT_PRICE = stock_order_message->limit_price;
		LIMIT_QUANTITY = stock_order_message->limit_quantity;
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
	//stock_transaction_message(trader_id, stock_id, transaction_price, transaction_quantity, MSGDATA);
	add_stock_transaction_message(TRADER_ID, STOCK_ID, TRANSACTION_PRICE, TRANSACTION_QUANTITY, MSGDATA);

	return 0;
}


/*
 * \fn: int Clearinghouse_read_bond_orders()
 * \brief: reads bond_order msgs and stores them in memory vars.
 * To test, we simply copy the limit_price and limit_quantity from the traders order msg and set the mem vars to these values.
 */
int Clearinghouse_read_bond_orders()
{
	START_BOND_ORDER_MESSAGE_LOOP 
		//bond_order_message(trader_id, bond_id, limit_price, limit_quantity, MSGDATA);
		TRADER_ID = bond_order_message->trader_id;
		BOND_ID = bond_order_message->bond_id;
		LIMIT_PRICE = bond_order_message->limit_price;
		LIMIT_QUANTITY = bond_order_message->limit_quantity;
	FINISH_BOND_ORDER_MESSAGE_LOOP
	
	return 0;
}

/*
 * \fn: int Clearinghouse_compute_bond_transactions()
 * \brief: Computes bond transactions.
 */
int Clearinghouse_compute_bond_transactions()
{
	
	
	return 0;
}

/*
 * \fn: int Clearinghouse_send_bond_transactions()
 * \brief: Sends bond transaction msgs.
 */
int Clearinghouse_send_bond_transactions()
{
	//bond_transaction_message(trader_id, bond_id, transaction_price, transaction_quantity, MSGDATA);
	add_bond_transaction_message(TRADER_ID, BOND_ID, TRANSACTION_PRICE, TRANSACTION_QUANTITY, MSGDATA);

	return 0;
}

/*
 * \fn: int Clearinghouse_read_gov_gov_bond_orders()
 * \brief: reads gov_bond_order msgs and stores them in memory vars.
 * To test, we simply copy the limit_price and limit_quantity from the traders order msg and set the mem vars to these values.
 */
int Clearinghouse_read_gov_bond_orders()
{
	START_GOV_BOND_ORDER_MESSAGE_LOOP 
		//gov_bond_order_message(trader_id, gov_bond_id, limit_price, limit_quantity, MSGDATA);
		TRADER_ID = gov_bond_order_message->trader_id;
		GOV_BOND_ID = gov_bond_order_message->gov_bond_id;
		LIMIT_PRICE = gov_bond_order_message->limit_price;
		LIMIT_QUANTITY = gov_bond_order_message->limit_quantity;
	FINISH_GOV_BOND_ORDER_MESSAGE_LOOP
	
	return 0;
}

/*
 * \fn: int Clearinghouse_compute_gov_bond_transactions()
 * \brief: Computes gov_bond transactions.
 */
int Clearinghouse_compute_gov_bond_transactions()
{
	
	
	return 0;
}

/*
 * \fn: int Clearinghouse_send_gov_bond_transactions()
 * \brief: Sends gov_bond transaction msgs.
 */
int Clearinghouse_send_gov_bond_transactions()
{
	//gov_bond_transaction_message(trader_id, gov_bond_id, transaction_price, transaction_quantity, MSGDATA);
	add_gov_bond_transaction_message(TRADER_ID, GOV_BOND_ID, TRANSACTION_PRICE, TRANSACTION_QUANTITY, MSGDATA);

	return 0;
}
