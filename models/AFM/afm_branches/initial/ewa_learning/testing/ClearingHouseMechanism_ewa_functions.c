/*********************************
 * ClearingHouseMecahnism_ewa_functions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *********************************
 * History:
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 *********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#include "ClearingHouseMechanism_agent_header.h"
#include "mylibraryheader.h"


/* DEP: The Clearinghouse or Limit-Order Agent reads the message.
 * The personal message includes the household_id, so the response should include the household_id as well.
 */
int Clearinghouse_read_order_messages()
{
/* 1. Reading all firm_stock_order_messages: */
/* firm_stock_order_message = get_first_firm_stock_order_message()
 * while(firm_stock_order_message)
 * {
 *    household_id = firm_stock_order_message->household_id;
 *    firm_id = firm_stock_order_message->firm_id;
 *    limit_price = firm_stock_order_message->limit_price;
 *    limit_quantity = firm_stock_order_message->limit_quantity;
 *
 *    {C-CODE: PROCESSING THE ORDER: ADDING IT TO A LIST OF ORDERS?}
 *
 *    firm_stock_order_message = get_next_firm_stock_order_message(firm_stock_order_message)
 * }
 */
 
/* 2. Reading all firm_bond_order_messages: */
/* firm_bond_order_message = get_first_firm_bond_order_message()
 * while(firm_bond_order_message)
 * {
 *    household_id = firm_bond_order_message->household_id;
 *    firm_id = firm_bond_order_message->firm_id;
 *    limit_price = firm_bond_order_message->limit_price;
 *    limit_quantity = firm_bond_order_message->limit_quantity;
 *
 *    {C-CODE: PROCESSING THE ORDER: ADDING IT TO A LIST OF ORDERS?}
 *
 *    firm_bond_order_message = get_next_firm_bond_order_message(firm_bond_order_message)
 * }
 */

/* 3. Reading all gov_bond_order_messages: */
/* gov_bond_order_message = get_first_gov_bond_order_message()
 * while(gov_bond_order_message)
 * {
 *    household_id = gov_bond_order_message->household_id;
 *    gov_id = gov_bond_order_message->gov_id;
 *    limit_price = gov_bond_order_message->limit_price;
 *    limit_quantity = gov_bond_order_message->limit_quantity;
 *
 *    {C-CODE: PROCESSING THE ORDER: ADDING IT TO A LIST OF ORDERS?}
 *
 *    gov_bond_order_message = get_next_gov_bond_order_message(gov_bond_order_message)
 * }
 */

/* 4. Processing all orders, computing transaction prices and quantities*/
/* Clearinghouse runs all clearinghouse mechanisms: one per asset.*/
/* Limit-order Agent runs all limit-order book mechanisms: one per asset.*/

/*    {C-CODE: RUNNING CLEARINGHOUSE MECHANISM ON THE LIST OF ORDERS} */

/*    {C-CODE: RUNNING LIMIT-ORDER BOOK MECHANISM ON THE LIST OF ORDERS} */

/* 5. Sending back transactions messages*/

    add_firm_stock_transaction_message(household_id, firm_id, transaction_price, transaction_quantity,range,x,y,z);
    add_firm_bond_transaction_message(household_id, firm_id, transaction_price, transaction_quantity,range,x,y,z);
    add_gov_bond_transaction_message(household_id, gov_id, transaction_price, transaction_quantity,range,x,y,z);

    return 0;
} 