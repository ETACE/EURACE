/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */
 
#ifdef _DEBUG_MODE
    #define ERRCHECK
#else
    #define NDEBUG
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "mboard.h"



/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT) 
#endif


/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5
/** \def START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process bank_account_update messages. */
#define START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP  bank_account_update_message = get_first_bank_account_update_message(); while(bank_account_update_message) {
/** \def FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process bank_account_update messages. */
#define FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP bank_account_update_message = get_next_bank_account_update_message(bank_account_update_message); }
/** \def START_LOAN_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process loan_request messages. */
#define START_LOAN_REQUEST_MESSAGE_LOOP  loan_request_message = get_first_loan_request_message(); while(loan_request_message) {
/** \def FINISH_LOAN_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process loan_request messages. */
#define FINISH_LOAN_REQUEST_MESSAGE_LOOP loan_request_message = get_next_loan_request_message(loan_request_message); }
/** \def START_LOAN_CONDITIONS_MESSAGE_LOOP
 * \brief Start of loop to process loan_conditions messages. */
#define START_LOAN_CONDITIONS_MESSAGE_LOOP  loan_conditions_message = get_first_loan_conditions_message(); while(loan_conditions_message) {
/** \def FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
 * \brief Finish of loop to process loan_conditions messages. */
#define FINISH_LOAN_CONDITIONS_MESSAGE_LOOP loan_conditions_message = get_next_loan_conditions_message(loan_conditions_message); }
/** \def START_LOAN_ACCEPTANCE_MESSAGE_LOOP
 * \brief Start of loop to process loan_acceptance messages. */
#define START_LOAN_ACCEPTANCE_MESSAGE_LOOP  loan_acceptance_message = get_first_loan_acceptance_message(); while(loan_acceptance_message) {
/** \def FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
 * \brief Finish of loop to process loan_acceptance messages. */
#define FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP loan_acceptance_message = get_next_loan_acceptance_message(loan_acceptance_message); }
/** \def START_INSTALLMENT_MESSAGE_LOOP
 * \brief Start of loop to process installment messages. */
#define START_INSTALLMENT_MESSAGE_LOOP  installment_message = get_first_installment_message(); while(installment_message) {
/** \def FINISH_INSTALLMENT_MESSAGE_LOOP
 * \brief Finish of loop to process installment messages. */
#define FINISH_INSTALLMENT_MESSAGE_LOOP installment_message = get_next_installment_message(installment_message); }
/** \def START_BANKRUPTCY_MESSAGE_LOOP
 * \brief Start of loop to process bankruptcy messages. */
#define START_BANKRUPTCY_MESSAGE_LOOP  bankruptcy_message = get_first_bankruptcy_message(); while(bankruptcy_message) {
/** \def FINISH_BANKRUPTCY_MESSAGE_LOOP
 * \brief Finish of loop to process bankruptcy messages. */
#define FINISH_BANKRUPTCY_MESSAGE_LOOP bankruptcy_message = get_next_bankruptcy_message(bankruptcy_message); }
/** \def START_BCE_RETURN_MESSAGE_LOOP
 * \brief Start of loop to process BCE_return messages. */
#define START_BCE_RETURN_MESSAGE_LOOP  BCE_return_message = get_first_BCE_return_message(); while(BCE_return_message) {
/** \def FINISH_BCE_RETURN_MESSAGE_LOOP
 * \brief Finish of loop to process BCE_return messages. */
#define FINISH_BCE_RETURN_MESSAGE_LOOP BCE_return_message = get_next_BCE_return_message(BCE_return_message); }
/** \def START_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process tax_payment messages. */
#define START_TAX_PAYMENT_MESSAGE_LOOP  tax_payment_message = get_first_tax_payment_message(); while(tax_payment_message) {
/** \def FINISH_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process tax_payment messages. */
#define FINISH_TAX_PAYMENT_MESSAGE_LOOP tax_payment_message = get_next_tax_payment_message(tax_payment_message); }
/** \def START_DIVIDEND_PER_SHARE_MESSAGE_LOOP
 * \brief Start of loop to process dividend_per_share messages. */
#define START_DIVIDEND_PER_SHARE_MESSAGE_LOOP  dividend_per_share_message = get_first_dividend_per_share_message(); while(dividend_per_share_message) {
/** \def FINISH_DIVIDEND_PER_SHARE_MESSAGE_LOOP
 * \brief Finish of loop to process dividend_per_share messages. */
#define FINISH_DIVIDEND_PER_SHARE_MESSAGE_LOOP dividend_per_share_message = get_next_dividend_per_share_message(dividend_per_share_message); }
/** \def START_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP
 * \brief Start of loop to process current_mall_stock_info messages. */
#define START_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP  current_mall_stock_info_message = get_first_current_mall_stock_info_message(); while(current_mall_stock_info_message) {
/** \def FINISH_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP
 * \brief Finish of loop to process current_mall_stock_info messages. */
#define FINISH_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP current_mall_stock_info_message = get_next_current_mall_stock_info_message(current_mall_stock_info_message); }
/** \def START_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process order messages. */
#define START_ORDER_MESSAGE_LOOP  order_message = get_first_order_message(); while(order_message) {
/** \def FINISH_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process order messages. */
#define FINISH_ORDER_MESSAGE_LOOP order_message = get_next_order_message(order_message); }
/** \def START_ORDER_STATUS_MESSAGE_LOOP
 * \brief Start of loop to process order_status messages. */
#define START_ORDER_STATUS_MESSAGE_LOOP  order_status_message = get_first_order_status_message(); while(order_status_message) {
/** \def FINISH_ORDER_STATUS_MESSAGE_LOOP
 * \brief Finish of loop to process order_status messages. */
#define FINISH_ORDER_STATUS_MESSAGE_LOOP order_status_message = get_next_order_status_message(order_status_message); }

/** \struct int_array
 * \brief Dynamic array to hold integers.
 *
 * Holds a pointer to an integer array and values for size and memory size.
 */
struct int_array
{
	int size;
	int total_size;
	
	int * array;
};

/** \struct float_array
 * \brief Dynamic array to hold floats.
 *
 * Holds a pointer to an float array and values for size and memory size.
 */
struct float_array
{
	int size;
	int total_size;
	
	float * array;
};

/** \struct double_array
 * \brief Dynamic array to hold doubles.
 *
 * Holds a pointer to a double array and values for size and memory size.
 */
struct double_array
{
	int size;
	int total_size;
	
	double * array;
};

/** \struct char_array
 * \brief Dynamic array to hold chars.
 *
 * Holds a pointer to a char array and values for size and memory size.
 */
struct char_array
{
	int size;
	int total_size;
	
	char * array;
};

/** \typedef struct int_array int_array
 * \brief Typedef for int_array struct.
 */
typedef struct int_array int_array;
/** \typedef struct float_array float_array
 * \brief Typedef for float_array struct.
 */
typedef struct float_array float_array;
/** \typedef struct double_array double_array
 * \brief Typedef for double_array struct.
 */
typedef struct double_array double_array;
/** \typedef struct char_array char_array
 * \brief Typedef for char_array struct.
 */
typedef struct char_array char_array;

/** \struct residual_var_datatype
 * \brief .
 *
 * .
 */
struct residual_var_datatype
{
	double value[10];	/**< Datatype memory variable value of type double. */
};

/** \struct residual_var_datatype_array
 * \brief Dynamic array to hold residual_var_datatypes
 */
struct residual_var_datatype_array
{
	int size;
	int total_size;
	
	struct residual_var_datatype * array;
};

/** \var typedef residual_var_datatype residual_var_datatype
 * \brief Typedef for residual_var_datatype struct.
 */
typedef struct residual_var_datatype residual_var_datatype;
/** \var typedef residual_var_datatype_array residual_var_datatype_array
 * \brief Typedef for residual_var_datatype_array struct.
 */
typedef struct residual_var_datatype_array residual_var_datatype_array;
/** \struct debt_item
 * \brief .
 *
 * .
 */
struct debt_item
{
	int bank_id;	/**< Datatype memory variable bank_id of type int. */
	double loan_value;	/**< Datatype memory variable loan_value of type double. */
	double interest_rate;	/**< Datatype memory variable interest_rate of type double. */
	double installment_amount;	/**< Datatype memory variable installment_amount of type double. */
	double var_per_installment;	/**< Datatype memory variable var_per_installment of type double. */
	double residual_var;	/**< Datatype memory variable residual_var of type double. */
	double bad_debt;	/**< Datatype memory variable bad_debt of type double. */
	int nr_periods_before_repayment;	/**< Datatype memory variable nr_periods_before_repayment of type int. */
};

/** \struct debt_item_array
 * \brief Dynamic array to hold debt_items
 */
struct debt_item_array
{
	int size;
	int total_size;
	
	struct debt_item * array;
};

/** \var typedef debt_item debt_item
 * \brief Typedef for debt_item struct.
 */
typedef struct debt_item debt_item;
/** \var typedef debt_item_array debt_item_array
 * \brief Typedef for debt_item_array struct.
 */
typedef struct debt_item_array debt_item_array;
/** \struct capital_stock_item
 * \brief .
 *
 * .
 */
struct capital_stock_item
{
	double units;	/**< Datatype memory variable units of type double. */
	double purchase_price;	/**< Datatype memory variable purchase_price of type double. */
	double productivity;	/**< Datatype memory variable productivity of type double. */
	double depreciation_units_per_period;	/**< Datatype memory variable depreciation_units_per_period of type double. */
};

/** \struct capital_stock_item_array
 * \brief Dynamic array to hold capital_stock_items
 */
struct capital_stock_item_array
{
	int size;
	int total_size;
	
	struct capital_stock_item * array;
};

/** \var typedef capital_stock_item capital_stock_item
 * \brief Typedef for capital_stock_item struct.
 */
typedef struct capital_stock_item capital_stock_item;
/** \var typedef capital_stock_item_array capital_stock_item_array
 * \brief Typedef for capital_stock_item_array struct.
 */
typedef struct capital_stock_item_array capital_stock_item_array;
/** \struct mall_info
 * \brief .
 *
 * .
 */
struct mall_info
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	double critical_stock;	/**< Datatype memory variable critical_stock of type double. */
	double current_stock;	/**< Datatype memory variable current_stock of type double. */
};

/** \struct mall_info_array
 * \brief Dynamic array to hold mall_infos
 */
struct mall_info_array
{
	int size;
	int total_size;
	
	struct mall_info * array;
};

/** \var typedef mall_info mall_info
 * \brief Typedef for mall_info struct.
 */
typedef struct mall_info mall_info;
/** \var typedef mall_info_array mall_info_array
 * \brief Typedef for mall_info_array struct.
 */
typedef struct mall_info_array mall_info_array;

/** \struct xmachine_memory_Firm
 * \brief Holds memory of xmachine Firm.
 */
struct xmachine_memory_Firm
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	int dmarketmatrix[10];	/**< X-machine memory variable dmarketmatrix of type int. */
	residual_var_datatype residual_var[10];	/**< X-machine memory variable residual_var of type residual_var_datatype. */
	double ebit;	/**< X-machine memory variable ebit of type double. */
	double earnings;	/**< X-machine memory variable earnings of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	double tax_rate_vat;	/**< X-machine memory variable tax_rate_vat of type double. */
	double tax_payment;	/**< X-machine memory variable tax_payment of type double. */
	double net_earnings;	/**< X-machine memory variable net_earnings of type double. */
	double previous_net_earnings;	/**< X-machine memory variable previous_net_earnings of type double. */
	double earnings_per_share;	/**< X-machine memory variable earnings_per_share of type double. */
	double cum_total_sold_quantity;	/**< X-machine memory variable cum_total_sold_quantity of type double. */
	double cum_revenue;	/**< X-machine memory variable cum_revenue of type double. */
	double production_costs;	/**< X-machine memory variable production_costs of type double. */
	int current_shares_outstanding;	/**< X-machine memory variable current_shares_outstanding of type int. */
	double total_payments;	/**< X-machine memory variable total_payments of type double. */
	mall_info_array current_mall_stocks;	/**< X-machine memory variable current_mall_stocks of type mall_info_array. */
	double price;	/**< X-machine memory variable price of type double. */
	double total_interest_payment;	/**< X-machine memory variable total_interest_payment of type double. */
	double total_debt_installment_payment;	/**< X-machine memory variable total_debt_installment_payment of type double. */
	double total_dividend_payment;	/**< X-machine memory variable total_dividend_payment of type double. */
	double current_share_price;	/**< X-machine memory variable current_share_price of type double. */
	double previous_dividend_per_share;	/**< X-machine memory variable previous_dividend_per_share of type double. */
	double current_dividend_per_share;	/**< X-machine memory variable current_dividend_per_share of type double. */
	double previous_earnings_per_share;	/**< X-machine memory variable previous_earnings_per_share of type double. */
	double current_earnings_per_share;	/**< X-machine memory variable current_earnings_per_share of type double. */
	double previous_dividend_per_earnings;	/**< X-machine memory variable previous_dividend_per_earnings of type double. */
	double current_dividend_per_earnings;	/**< X-machine memory variable current_dividend_per_earnings of type double. */
	double debt_earnings_ratio;	/**< X-machine memory variable debt_earnings_ratio of type double. */
	double debt_equity_ratio;	/**< X-machine memory variable debt_equity_ratio of type double. */
	double price_earnings_ratio;	/**< X-machine memory variable price_earnings_ratio of type double. */
	double retained_earnings_ratio;	/**< X-machine memory variable retained_earnings_ratio of type double. */
	double earnings_per_share_ratio_growth;	/**< X-machine memory variable earnings_per_share_ratio_growth of type double. */
	double critical_price_earnings_ratio;	/**< X-machine memory variable critical_price_earnings_ratio of type double. */
	double critical_earnings_per_share_ratio;	/**< X-machine memory variable critical_earnings_per_share_ratio of type double. */
	debt_item_array loans;	/**< X-machine memory variable loans of type debt_item_array. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double total_value_local_inventory;	/**< X-machine memory variable total_value_local_inventory of type double. */
	capital_stock_item_array capital_stock;	/**< X-machine memory variable capital_stock of type capital_stock_item_array. */
	double total_units_capital_stock;	/**< X-machine memory variable total_units_capital_stock of type double. */
	double total_value_capital_stock;	/**< X-machine memory variable total_value_capital_stock of type double. */
	double total_capital_depreciation_value;	/**< X-machine memory variable total_capital_depreciation_value of type double. */
	double total_capital_depreciation_units;	/**< X-machine memory variable total_capital_depreciation_units of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double production_liquidity_needs;	/**< X-machine memory variable production_liquidity_needs of type double. */
	double financial_liquidity_needs;	/**< X-machine memory variable financial_liquidity_needs of type double. */
	double total_financial_needs;	/**< X-machine memory variable total_financial_needs of type double. */
	double external_financial_needs;	/**< X-machine memory variable external_financial_needs of type double. */
	int bankruptcy_state;	/**< X-machine memory variable bankruptcy_state of type int. */
	int financial_crisis_state;	/**< X-machine memory variable financial_crisis_state of type int. */
};

/** \struct xmachine_memory_Firm_holder
 * \brief Holds struct of memory of xmachine Firm.
 */
struct xmachine_memory_Firm_holder
{
	struct xmachine_memory_Firm * agent;	/**< Pointer to X-machine memory Firm. */

	struct xmachine_memory_Firm_holder * prev;	/**< Pointer to previous Firm agent in the list.  */
	struct xmachine_memory_Firm_holder * next;	/**< Pointer to next Firm agent in the list.  */
};

/** \struct xmachine_memory_Firm_holder
 * \brief Holds struct of memory of xmachine Firm.
 */
struct xmachine_memory_Firm_state
{
	struct xmachine_memory_Firm_holder * agents;	/**< Pointer to X-machine memory Firm. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Bank
 * \brief Holds memory of xmachine Bank.
 */
struct xmachine_memory_Bank
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	double cash;	/**< X-machine memory variable cash of type double. */
	double total_credit;	/**< X-machine memory variable total_credit of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double bce_debt;	/**< X-machine memory variable bce_debt of type double. */
	double alfa;	/**< X-machine memory variable alfa of type double. */
	double value_at_risk;	/**< X-machine memory variable value_at_risk of type double. */
	double min_interest;	/**< X-machine memory variable min_interest of type double. */
	double bank_gamma[2];	/**< X-machine memory variable bank_gamma of type double. */
	double profits[2];	/**< X-machine memory variable profits of type double. */
	double bank_lambda;	/**< X-machine memory variable bank_lambda of type double. */
	double bce_interest;	/**< X-machine memory variable bce_interest of type double. */
	double bank_dividend_rate;	/**< X-machine memory variable bank_dividend_rate of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	int number_of_shares;	/**< X-machine memory variable number_of_shares of type int. */
	double debt_period;	/**< X-machine memory variable debt_period of type double. */
	int loan_request_message_found;	/**< X-machine memory variable loan_request_message_found of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
};

/** \struct xmachine_memory_Bank_holder
 * \brief Holds struct of memory of xmachine Bank.
 */
struct xmachine_memory_Bank_holder
{
	struct xmachine_memory_Bank * agent;	/**< Pointer to X-machine memory Bank. */

	struct xmachine_memory_Bank_holder * prev;	/**< Pointer to previous Bank agent in the list.  */
	struct xmachine_memory_Bank_holder * next;	/**< Pointer to next Bank agent in the list.  */
};

/** \struct xmachine_memory_Bank_holder
 * \brief Holds struct of memory of xmachine Bank.
 */
struct xmachine_memory_Bank_state
{
	struct xmachine_memory_Bank_holder * agents;	/**< Pointer to X-machine memory Bank. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Dummy
 * \brief Holds memory of xmachine Dummy.
 */
struct xmachine_memory_Dummy
{
	int id;	/**< X-machine memory variable id of type int. */
};

/** \struct xmachine_memory_Dummy_holder
 * \brief Holds struct of memory of xmachine Dummy.
 */
struct xmachine_memory_Dummy_holder
{
	struct xmachine_memory_Dummy * agent;	/**< Pointer to X-machine memory Dummy. */

	struct xmachine_memory_Dummy_holder * prev;	/**< Pointer to previous Dummy agent in the list.  */
	struct xmachine_memory_Dummy_holder * next;	/**< Pointer to next Dummy agent in the list.  */
};

/** \struct xmachine_memory_Dummy_holder
 * \brief Holds struct of memory of xmachine Dummy.
 */
struct xmachine_memory_Dummy_state
{
	struct xmachine_memory_Dummy_holder * agents;	/**< Pointer to X-machine memory Dummy. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	struct xmachine_memory_Firm * xmachine_Firm;	/**< Pointer to X-machine memory of type Firm.  */
	struct xmachine_memory_Bank * xmachine_Bank;	/**< Pointer to X-machine memory of type Bank.  */
	struct xmachine_memory_Dummy * xmachine_Dummy;	/**< Pointer to X-machine memory of type Dummy.  */
	
	//struct xmachine * prev;	/**< Pointer to previous X-machine in the list.  */
	//struct xmachine * next;	/**< Pointer to next X-machine in the list.  */
};

/** \struct m_bank_account_update
 * \brief Holds message of type bank_account_update_message.
 */
struct m_bank_account_update
{
	int id;	/**< Message memory variable id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double payment_account;	/**< Message memory variable payment_account of type double. */
};

/** \struct m_loan_request
 * \brief Holds message of type loan_request_message.
 */
struct m_loan_request
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double equity;	/**< Message memory variable equity of type double. */
	double total_debt;	/**< Message memory variable total_debt of type double. */
	double external_financial_needs;	/**< Message memory variable external_financial_needs of type double. */
};

/** \struct m_loan_conditions
 * \brief Holds message of type loan_conditions_message.
 */
struct m_loan_conditions
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double proposed_interest_rate;	/**< Message memory variable proposed_interest_rate of type double. */
	double amount_offered_credit;	/**< Message memory variable amount_offered_credit of type double. */
	double value_at_risk;	/**< Message memory variable value_at_risk of type double. */
};

/** \struct m_loan_acceptance
 * \brief Holds message of type loan_acceptance_message.
 */
struct m_loan_acceptance
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double credit_amount_taken;	/**< Message memory variable credit_amount_taken of type double. */
	double loan_total_var;	/**< Message memory variable loan_total_var of type double. */
};

/** \struct m_installment
 * \brief Holds message of type installment_message.
 */
struct m_installment
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double installment_amount;	/**< Message memory variable installment_amount of type double. */
	double interest_amount;	/**< Message memory variable interest_amount of type double. */
	double var_per_installment;	/**< Message memory variable var_per_installment of type double. */
};

/** \struct m_bankruptcy
 * \brief Holds message of type bankruptcy_message.
 */
struct m_bankruptcy
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double bad_debt;	/**< Message memory variable bad_debt of type double. */
	double credit_refunded;	/**< Message memory variable credit_refunded of type double. */
	double residual_var;	/**< Message memory variable residual_var of type double. */
};

/** \struct m_BCE_return
 * \brief Holds message of type BCE_return_message.
 */
struct m_BCE_return
{
	int bce_debt;	/**< Message memory variable bce_debt of type int. */
	int id;	/**< Message memory variable id of type int. */
};

/** \struct m_tax_payment
 * \brief Holds message of type tax_payment_message.
 */
struct m_tax_payment
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double tax_payment;	/**< Message memory variable tax_payment of type double. */
};

/** \struct m_dividend_per_share
 * \brief Holds message of type dividend_per_share_message.
 */
struct m_dividend_per_share
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double current_dividend_per_share;	/**< Message memory variable current_dividend_per_share of type double. */
};

/** \struct m_current_mall_stock_info
 * \brief Holds message of type current_mall_stock_info_message.
 */
struct m_current_mall_stock_info
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double stock;	/**< Message memory variable stock of type double. */
};

/** \struct m_order
 * \brief Holds message of type order_message.
 */
struct m_order
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	int asset_id;	/**< Message memory variable asset_id of type int. */
	double limit_price;	/**< Message memory variable limit_price of type double. */
	int quantity;	/**< Message memory variable quantity of type int. */
};

/** \struct m_order_status
 * \brief Holds message of type order_status_message.
 */
struct m_order_status
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	int asset_id;	/**< Message memory variable asset_id of type int. */
	double price;	/**< Message memory variable price of type double. */
	int quantity;	/**< Message memory variable quantity of type int. */
};

/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm xmachine_memory_Firm;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm_holder xmachine_memory_Firm_holder;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm_state xmachine_memory_Firm_state;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank xmachine_memory_Bank;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank_holder xmachine_memory_Bank_holder;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank_state xmachine_memory_Bank_state;
/** \var typedef xmachine_memory_Dummy xmachine_memory_Dummy
 * \brief Typedef for xmachine_memory_Dummy struct.
 */
typedef struct xmachine_memory_Dummy xmachine_memory_Dummy;
/** \var typedef xmachine_memory_Dummy xmachine_memory_Dummy
 * \brief Typedef for xmachine_memory_Dummy struct.
 */
typedef struct xmachine_memory_Dummy_holder xmachine_memory_Dummy_holder;
/** \var typedef xmachine_memory_Dummy xmachine_memory_Dummy
 * \brief Typedef for xmachine_memory_Dummy struct.
 */
typedef struct xmachine_memory_Dummy_state xmachine_memory_Dummy_state;
/** \typedef m_bank_account_update m_bank_account_update
 * \brief Typedef for m_bank_account_update struct.
 */
typedef struct m_bank_account_update m_bank_account_update;

/** \typedef m_loan_request m_loan_request
 * \brief Typedef for m_loan_request struct.
 */
typedef struct m_loan_request m_loan_request;

/** \typedef m_loan_conditions m_loan_conditions
 * \brief Typedef for m_loan_conditions struct.
 */
typedef struct m_loan_conditions m_loan_conditions;

/** \typedef m_loan_acceptance m_loan_acceptance
 * \brief Typedef for m_loan_acceptance struct.
 */
typedef struct m_loan_acceptance m_loan_acceptance;

/** \typedef m_installment m_installment
 * \brief Typedef for m_installment struct.
 */
typedef struct m_installment m_installment;

/** \typedef m_bankruptcy m_bankruptcy
 * \brief Typedef for m_bankruptcy struct.
 */
typedef struct m_bankruptcy m_bankruptcy;

/** \typedef m_BCE_return m_BCE_return
 * \brief Typedef for m_BCE_return struct.
 */
typedef struct m_BCE_return m_BCE_return;

/** \typedef m_tax_payment m_tax_payment
 * \brief Typedef for m_tax_payment struct.
 */
typedef struct m_tax_payment m_tax_payment;

/** \typedef m_dividend_per_share m_dividend_per_share
 * \brief Typedef for m_dividend_per_share struct.
 */
typedef struct m_dividend_per_share m_dividend_per_share;

/** \typedef m_current_mall_stock_info m_current_mall_stock_info
 * \brief Typedef for m_current_mall_stock_info struct.
 */
typedef struct m_current_mall_stock_info m_current_mall_stock_info;

/** \typedef m_order m_order
 * \brief Typedef for m_order struct.
 */
typedef struct m_order m_order;

/** \typedef m_order_status m_order_status
 * \brief Typedef for m_order_status struct.
 */
typedef struct m_order_status m_order_status;


int Firm_ask_loan(void);
int Firm_Firm_ask_loan_Start_Firm_Credit_Role_Firm_Credit_02_condition(xmachine_memory_Firm *a);
int Firm_get_loan(void);
int Firm_Firm_get_loan_loan_conditions_filter(const void *msg, const void *params);
int Firm_compute_financial_payments(void);
int Firm_compute_income_statement(void);
int Firm_compute_dividends(void);
int Firm_compute_total_financial_payments(void);
int Firm_idle(void);
int Firm_Firm_idle_End_Firm_Financial_Role_Firm_bankruptcy_checked_condition(xmachine_memory_Firm *a);
int Firm_compute_balance_sheet(void);
int Firm_Firm_compute_balance_sheet_current_mall_stock_info_filter(const void *msg, const void *params);
int Firm_compute_total_liquidity_needs(void);
int Firm_compute_and_send_stock_orders(void);
int Firm_Firm_compute_and_send_stock_orders_Firm_End_Credit_Role_0003_condition(xmachine_memory_Firm *a);
int Firm_read_stock_transactions(void);
int Firm_Firm_read_stock_transactions_order_status_filter(const void *msg, const void *params);
int Firm_check_financial_and_bankruptcy_state(void);
int Firm_Firm_check_financial_and_bankruptcy_state_End_Firm_Financial_Role_f1_condition(xmachine_memory_Firm *a);
int Firm_in_bankruptcy(void);
int Firm_Firm_in_bankruptcy_Firm_bankruptcy_checked_end_Firm_dies_condition(xmachine_memory_Firm *a);
int Firm_generate_new_firm(void);
int Firm_not_in_bankruptcy(void);
int Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_not_in_bankruptcy_state_now_check_financial_crisis_condition(xmachine_memory_Firm *a);
int Firm_in_financial_crisis_function(void);
int Firm_Firm_in_financial_crisis_function_Firm_not_in_bankruptcy_state_now_check_financial_crisis_Firm_financial_crisis_ok_condition(xmachine_memory_Firm *a);
int Firm_execute_financial_payments_function(void);
int Firm_idle(void);
int Firm_Firm_idle_Firm_not_in_bankruptcy_state_now_check_financial_crisis_Firm_financial_crisis_ok_condition(xmachine_memory_Firm *a);
int idle(void);
int Firm_idle_Start_Firm_Credit_Role_Start_Firm_Labour_Role_condition(xmachine_memory_Firm *a);
int idle(void);
int Firm_idle_Firm_End_Credit_Role_Start_Firm_Labour_Role_condition(xmachine_memory_Firm *a);
int Bank_decide_credit_conditions(void);
int Bank_Bank_decide_credit_conditions_loan_request_filter(const void *msg, const void *params);
int Bank_give_loan(void);
int Bank_Bank_give_loan_loan_acceptance_filter(const void *msg, const void *params);
int Bank_receive_installment(void);
int Bank_Bank_receive_installment_installment_filter(const void *msg, const void *params);
int Bank_Bank_receive_installment_bankruptcy_filter(const void *msg, const void *params);
int Bank_account_update_deposits(void);
int Bank_Bank_account_update_deposits_bank_account_update_filter(const void *msg, const void *params);
int Bank_accounting(void);
int Bank_Bank_accounting_Bank_05_end_Bank_cycle_condition(xmachine_memory_Bank *a);
int Bank_idle(void);
int Bank_Bank_idle_Bank_05_end_Bank_cycle_condition(xmachine_memory_Bank *a);
int Function_read_send_order_messages(void);
int Function_read_send_bank_messages(void);

/** \struct location
 * \brief Holds location for calculating space partitioning .
 */
struct location
{
	double point;		/**< Point on an axis. */
	
	struct location * next;	/**< Pointer to next location on the list. */
};

/** \struct node_information
 * \brief Holds node information .
 */
struct node_information
{
	int node_id;	/**< Node ID. */
	double partition_data[6];	/**< Defines bounding box. */
	int agents_in_halo;	/**< Number of agents in the halo region. */
	int agent_total;	/**< Total number of agents on the node. */
	struct xmachine * agents;	/**< Pointer to list of X-machines. */
	struct m_bank_account_update * bank_account_update_messages;	/**< Pointer to bank_account_update message list. */
	struct m_loan_request * loan_request_messages;	/**< Pointer to loan_request message list. */
	struct m_loan_conditions * loan_conditions_messages;	/**< Pointer to loan_conditions message list. */
	struct m_loan_acceptance * loan_acceptance_messages;	/**< Pointer to loan_acceptance message list. */
	struct m_installment * installment_messages;	/**< Pointer to installment message list. */
	struct m_bankruptcy * bankruptcy_messages;	/**< Pointer to bankruptcy message list. */
	struct m_BCE_return * BCE_return_messages;	/**< Pointer to BCE_return message list. */
	struct m_tax_payment * tax_payment_messages;	/**< Pointer to tax_payment message list. */
	struct m_dividend_per_share * dividend_per_share_messages;	/**< Pointer to dividend_per_share message list. */
	struct m_current_mall_stock_info * current_mall_stock_info_messages;	/**< Pointer to current_mall_stock_info message list. */
	struct m_order * order_messages;	/**< Pointer to order message list. */
	struct m_order_status * order_status_messages;	/**< Pointer to order_status message list. */
	
	struct node_information * next;	/**< Pointer to next node on the list. */
};


/** \typedef struct location location
 * \brief Typedef for location struct.
 */
typedef struct location location;
/** \typedef struct node_information node_information
 * \brief Typedef for node_information struct.
 */
typedef struct node_information node_information;

/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var m_bank_account_update * temp_bank_account_update_message
* \brief Pointer to m_bank_account_update to initialise linked list. */
m_bank_account_update * temp_bank_account_update_message;
/** \var m_loan_request * temp_loan_request_message
* \brief Pointer to m_loan_request to initialise linked list. */
m_loan_request * temp_loan_request_message;
/** \var m_loan_conditions * temp_loan_conditions_message
* \brief Pointer to m_loan_conditions to initialise linked list. */
m_loan_conditions * temp_loan_conditions_message;
/** \var m_loan_acceptance * temp_loan_acceptance_message
* \brief Pointer to m_loan_acceptance to initialise linked list. */
m_loan_acceptance * temp_loan_acceptance_message;
/** \var m_installment * temp_installment_message
* \brief Pointer to m_installment to initialise linked list. */
m_installment * temp_installment_message;
/** \var m_bankruptcy * temp_bankruptcy_message
* \brief Pointer to m_bankruptcy to initialise linked list. */
m_bankruptcy * temp_bankruptcy_message;
/** \var m_BCE_return * temp_BCE_return_message
* \brief Pointer to m_BCE_return to initialise linked list. */
m_BCE_return * temp_BCE_return_message;
/** \var m_tax_payment * temp_tax_payment_message
* \brief Pointer to m_tax_payment to initialise linked list. */
m_tax_payment * temp_tax_payment_message;
/** \var m_dividend_per_share * temp_dividend_per_share_message
* \brief Pointer to m_dividend_per_share to initialise linked list. */
m_dividend_per_share * temp_dividend_per_share_message;
/** \var m_current_mall_stock_info * temp_current_mall_stock_info_message
* \brief Pointer to m_current_mall_stock_info to initialise linked list. */
m_current_mall_stock_info * temp_current_mall_stock_info_message;
/** \var m_order * temp_order_message
* \brief Pointer to m_order to initialise linked list. */
m_order * temp_order_message;
/** \var m_order_status * temp_order_status_message
* \brief Pointer to m_order_status to initialise linked list. */
m_order_status * temp_order_status_message;
/** \var node_information * temp_node_info
* \brief Pointer to node_information to initialise linked list. */
node_information * temp_node_info;
/** \var char outputpath[100]
* \brief Output path for files. */
char outputpath[100];
/** \var long total_time
* \brief Total time for the simulation run (in seconds) */
double total_time;
/** \var int total_messages
* \brief Total messages sent between nodes for the simulation run */
int total_messages;
/** \var int totalnodes
* \brief Number of nodes */
int totalnodes;
/** \var xmachine ** p_xmachine
* \brief Pointer to first pointer of x-machine memory list */
//xmachine ** p_xmachine;
/** \var xmachine * current_xmachine
* \brief Pointer to current x-machine memory that is being processed */
xmachine * current_xmachine;
/* Pointer to current $agent_name agent */
xmachine_memory_Firm * current_xmachine_Firm;
xmachine_memory_Firm_holder * temp_xmachine_Firm_holder;
xmachine_memory_Firm_holder * current_xmachine_Firm_holder;
xmachine_memory_Firm_state * current_xmachine_Firm_next_state; /* New agents added to this state */
/* Pointer to list of Firm agents in state Start_Firm_Labour_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Start_Firm_Labour_Role;
xmachine_memory_Firm_state * Firm_Start_Firm_Labour_Role_state;
/* Pointer to list of Firm agents in state Firm_financial_crisis_ok state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_financial_crisis_ok;
xmachine_memory_Firm_state * Firm_Firm_financial_crisis_ok_state;
/* Pointer to list of Firm agents in state Firm_not_in_bankruptcy_state_now_check_financial_crisis state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis;
xmachine_memory_Firm_state * Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state;
/* Pointer to list of Firm agents in state end_Firm_cycle state */
//xmachine_memory_Firm * temp_xmachine_Firm_end_Firm_cycle;
xmachine_memory_Firm_state * Firm_end_Firm_cycle_state;
/* Pointer to list of Firm agents in state end_Firm_dies state */
//xmachine_memory_Firm * temp_xmachine_Firm_end_Firm_dies;
xmachine_memory_Firm_state * Firm_end_Firm_dies_state;
/* Pointer to list of Firm agents in state 0003 state */
//xmachine_memory_Firm * temp_xmachine_Firm_0003;
xmachine_memory_Firm_state * Firm_0003_state;
/* Pointer to list of Firm agents in state 02 state */
//xmachine_memory_Firm * temp_xmachine_Firm_02;
xmachine_memory_Firm_state * Firm_02_state;
/* Pointer to list of Firm agents in state Firm_bankruptcy_checked state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankruptcy_checked;
xmachine_memory_Firm_state * Firm_Firm_bankruptcy_checked_state;
/* Pointer to list of Firm agents in state End_Firm_Financial_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_End_Firm_Financial_Role;
xmachine_memory_Firm_state * Firm_End_Firm_Financial_Role_state;
/* Pointer to list of Firm agents in state 004 state */
//xmachine_memory_Firm * temp_xmachine_Firm_004;
xmachine_memory_Firm_state * Firm_004_state;
/* Pointer to list of Firm agents in state 003 state */
//xmachine_memory_Firm * temp_xmachine_Firm_003;
xmachine_memory_Firm_state * Firm_003_state;
/* Pointer to list of Firm agents in state 002 state */
//xmachine_memory_Firm * temp_xmachine_Firm_002;
xmachine_memory_Firm_state * Firm_002_state;
/* Pointer to list of Firm agents in state 001 state */
//xmachine_memory_Firm * temp_xmachine_Firm_001;
xmachine_memory_Firm_state * Firm_001_state;
/* Pointer to list of Firm agents in state f1 state */
//xmachine_memory_Firm * temp_xmachine_Firm_f1;
xmachine_memory_Firm_state * Firm_f1_state;
/* Pointer to list of Firm agents in state Firm_End_Credit_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Credit_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Credit_Role_state;
/* Pointer to list of Firm agents in state Firm_Credit_02 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Credit_02;
xmachine_memory_Firm_state * Firm_Firm_Credit_02_state;
/* Pointer to list of Firm agents in state Start_Firm_Credit_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Start_Firm_Credit_Role;
xmachine_memory_Firm_state * Firm_Start_Firm_Credit_Role_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Bank * current_xmachine_Bank;
xmachine_memory_Bank_holder * temp_xmachine_Bank_holder;
xmachine_memory_Bank_holder * current_xmachine_Bank_holder;
xmachine_memory_Bank_state * current_xmachine_Bank_next_state; /* New agents added to this state */
/* Pointer to list of Bank agents in state end_Bank_cycle state */
//xmachine_memory_Bank * temp_xmachine_Bank_end_Bank_cycle;
xmachine_memory_Bank_state * Bank_end_Bank_cycle_state;
/* Pointer to list of Bank agents in state Bank_05 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_05;
xmachine_memory_Bank_state * Bank_Bank_05_state;
/* Pointer to list of Bank agents in state Bank_04 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_04;
xmachine_memory_Bank_state * Bank_Bank_04_state;
/* Pointer to list of Bank agents in state Bank_03 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_03;
xmachine_memory_Bank_state * Bank_Bank_03_state;
/* Pointer to list of Bank agents in state Bank_02 state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_02;
xmachine_memory_Bank_state * Bank_Bank_02_state;
/* Pointer to list of Bank agents in state Bank_start_credit_market_role state */
//xmachine_memory_Bank * temp_xmachine_Bank_Bank_start_credit_market_role;
xmachine_memory_Bank_state * Bank_Bank_start_credit_market_role_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Dummy * current_xmachine_Dummy;
xmachine_memory_Dummy_holder * temp_xmachine_Dummy_holder;
xmachine_memory_Dummy_holder * current_xmachine_Dummy_holder;
xmachine_memory_Dummy_state * current_xmachine_Dummy_next_state; /* New agents added to this state */
/* Pointer to list of Dummy agents in state 003 state */
//xmachine_memory_Dummy * temp_xmachine_Dummy_003;
xmachine_memory_Dummy_state * Dummy_003_state;
/* Pointer to list of Dummy agents in state 002 state */
//xmachine_memory_Dummy * temp_xmachine_Dummy_002;
xmachine_memory_Dummy_state * Dummy_002_state;
/* Pointer to list of Dummy agents in state 001 state */
//xmachine_memory_Dummy * temp_xmachine_Dummy_001;
xmachine_memory_Dummy_state * Dummy_001_state;


MBt_Board b_bank_account_update;
MBt_Iterator i_bank_account_update;

MBt_Board b_loan_request;
MBt_Iterator i_loan_request;

MBt_Board b_loan_conditions;
MBt_Iterator i_loan_conditions;

MBt_Board b_loan_acceptance;
MBt_Iterator i_loan_acceptance;

MBt_Board b_installment;
MBt_Iterator i_installment;

MBt_Board b_bankruptcy;
MBt_Iterator i_bankruptcy;

MBt_Board b_BCE_return;
MBt_Iterator i_BCE_return;

MBt_Board b_tax_payment;
MBt_Iterator i_tax_payment;

MBt_Board b_dividend_per_share;
MBt_Iterator i_dividend_per_share;

MBt_Board b_current_mall_stock_info;
MBt_Iterator i_current_mall_stock_info;

MBt_Board b_order;
MBt_Iterator i_order;

MBt_Board b_order_status;
MBt_Iterator i_order_status;


/** \var m_bank_account_update * bank_account_update_message
* \brief Pointer to message struct for looping through bank_account_update message list */
m_bank_account_update * bank_account_update_message;
/** \var m_loan_request * loan_request_message
* \brief Pointer to message struct for looping through loan_request message list */
m_loan_request * loan_request_message;
/** \var m_loan_conditions * loan_conditions_message
* \brief Pointer to message struct for looping through loan_conditions message list */
m_loan_conditions * loan_conditions_message;
/** \var m_loan_acceptance * loan_acceptance_message
* \brief Pointer to message struct for looping through loan_acceptance message list */
m_loan_acceptance * loan_acceptance_message;
/** \var m_installment * installment_message
* \brief Pointer to message struct for looping through installment message list */
m_installment * installment_message;
/** \var m_bankruptcy * bankruptcy_message
* \brief Pointer to message struct for looping through bankruptcy message list */
m_bankruptcy * bankruptcy_message;
/** \var m_BCE_return * BCE_return_message
* \brief Pointer to message struct for looping through BCE_return message list */
m_BCE_return * BCE_return_message;
/** \var m_tax_payment * tax_payment_message
* \brief Pointer to message struct for looping through tax_payment message list */
m_tax_payment * tax_payment_message;
/** \var m_dividend_per_share * dividend_per_share_message
* \brief Pointer to message struct for looping through dividend_per_share message list */
m_dividend_per_share * dividend_per_share_message;
/** \var m_current_mall_stock_info * current_mall_stock_info_message
* \brief Pointer to message struct for looping through current_mall_stock_info message list */
m_current_mall_stock_info * current_mall_stock_info_message;
/** \var m_order * order_message
* \brief Pointer to message struct for looping through order message list */
m_order * order_message;
/** \var m_order_status * order_status_message
* \brief Pointer to message struct for looping through order_status message list */
m_order_status * order_status_message;
/** \var node_information ** p_node_info
* \brief Pointer to first pointer of node list */
node_information ** p_node_info;
/** \var node_information * current_node
* \brief Pointer to current node */
node_information * current_node;

/** \var int iteration_loop
* \brief The current iteration number */
int iteration_loop;
/** \var int output_frequency
* \brief Frequency to output results */
int output_frequency;
/** \var int output_offset
* \brief Offset to output results */
int output_offset;
/** \var int next_avaliable_id
* \brief Next avaliable id number for a new agent */
int next_avaliable_id;

/** \def SPINF
* \brief Dummy inf value for space partition data. */
#define SPINF 999999.123456
/** \def RELEASE
* \brief Used to kill an agent via 'return RELEASE;'. */
#define RELEASE 1
/** \def kill_me_now
* \brief Used to kill an agent via 'kill_me_now'. */
#define kill_me_now return 1

void initialise_pointers(void);
void initialise_unit_testing(void);
void add_location(double point, location ** p_location);
void freelocations(location ** p_location);
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz);
void clean_up(int code);
void propagate_agents(void);
void propagate_messages_init(void);
void propagate_messages_complete(void);
void create_partitions(char * filename, int * itno);
void free_node_info(void);
void free_agent(void);
void freexmachines(void);
/* model datatypes */

void init_residual_var_datatype_array(residual_var_datatype_array * array);
void reset_residual_var_datatype_array(residual_var_datatype_array * array);
void free_residual_var_datatype_array(residual_var_datatype_array * array);
void copy_residual_var_datatype_array(residual_var_datatype_array * from, residual_var_datatype_array * to);
void add_residual_var_datatype(residual_var_datatype_array * array, double * value);
void remove_residual_var_datatype(residual_var_datatype_array * array, int index);

void init_debt_item_array(debt_item_array * array);
void reset_debt_item_array(debt_item_array * array);
void free_debt_item_array(debt_item_array * array);
void copy_debt_item_array(debt_item_array * from, debt_item_array * to);
void add_debt_item(debt_item_array * array, int bank_id, double loan_value, double interest_rate, double installment_amount, double var_per_installment, double residual_var, double bad_debt, int nr_periods_before_repayment);
void remove_debt_item(debt_item_array * array, int index);

void init_capital_stock_item_array(capital_stock_item_array * array);
void reset_capital_stock_item_array(capital_stock_item_array * array);
void free_capital_stock_item_array(capital_stock_item_array * array);
void copy_capital_stock_item_array(capital_stock_item_array * from, capital_stock_item_array * to);
void add_capital_stock_item(capital_stock_item_array * array, double units, double purchase_price, double productivity, double depreciation_units_per_period);
void remove_capital_stock_item(capital_stock_item_array * array, int index);

void init_mall_info_array(mall_info_array * array);
void reset_mall_info_array(mall_info_array * array);
void free_mall_info_array(mall_info_array * array);
void copy_mall_info_array(mall_info_array * from, mall_info_array * to);
void add_mall_info(mall_info_array * array, int mall_id, double critical_stock, double current_stock);
void remove_mall_info(mall_info_array * array, int index);


void init_int_array(int_array * array);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void copy_int_array(int_array * from, int_array * to);
//void sort_int_array(int_array array);
//int quicksort_int(int array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
void init_float_array(float_array * array);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void copy_float_array(float_array * from, float_array * to);
//void sort_float_array(float_array array);
//int quicksort_float(float array, int elements);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
void init_double_array(double_array * array);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void copy_double_array(double_array * from, double_array * to);
//void sort_double_array(double_array array);
//int quicksort_double(double array, int elements);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
void init_char_array(char_array * array);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void copy_char_array(char_array * from, char_array * to);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
int idle();
/* xml.c */
void read_int_static_array(char * buffer, int * j, int * int_static_array, int size);
void read_float_static_array(char * buffer, int * j, float * float_static_array, int size);
void read_double_static_array(char * buffer, int * j, double * double_static_array, int size);
void read_char_static_array(char * buffer, int * j, char * char_static_array, int size);
void read_int_dynamic_array(char * buffer, int * j, int_array * int_dynamic_array);
void read_float_dynamic_array(char * buffer, int * j, float_array * float_dynamic_array);
void read_double_dynamic_array(char * buffer, int * j, double_array * double_dynamic_array);
void read_char_dynamic_array(char * buffer, int * j, char_array * char_dynamic_array);

void init_residual_var_datatype(residual_var_datatype * temp);
void init_residual_var_datatype_static_array(residual_var_datatype * array, int size);
void read_residual_var_datatype(char * buffer, int * j, residual_var_datatype * temp_datatype);
void read_residual_var_datatype_dynamic_array(char * buffer, int * j, residual_var_datatype_array * temp_datatype_array);
void read_residual_var_datatype_static_array(char * buffer, int * j, residual_var_datatype * temp_datatype_array, int size);
void write_residual_var_datatype(FILE *file, residual_var_datatype * temp_datatype);
void write_residual_var_datatype_static_array(FILE *file, residual_var_datatype * temp_datatype, int size);
void write_residual_var_datatype_dynamic_array(FILE *file, residual_var_datatype_array * temp_datatype);
void init_debt_item(debt_item * temp);
void init_debt_item_static_array(debt_item * array, int size);
void read_debt_item(char * buffer, int * j, debt_item * temp_datatype);
void read_debt_item_dynamic_array(char * buffer, int * j, debt_item_array * temp_datatype_array);
void read_debt_item_static_array(char * buffer, int * j, debt_item * temp_datatype_array, int size);
void write_debt_item(FILE *file, debt_item * temp_datatype);
void write_debt_item_static_array(FILE *file, debt_item * temp_datatype, int size);
void write_debt_item_dynamic_array(FILE *file, debt_item_array * temp_datatype);
void init_capital_stock_item(capital_stock_item * temp);
void init_capital_stock_item_static_array(capital_stock_item * array, int size);
void read_capital_stock_item(char * buffer, int * j, capital_stock_item * temp_datatype);
void read_capital_stock_item_dynamic_array(char * buffer, int * j, capital_stock_item_array * temp_datatype_array);
void read_capital_stock_item_static_array(char * buffer, int * j, capital_stock_item * temp_datatype_array, int size);
void write_capital_stock_item(FILE *file, capital_stock_item * temp_datatype);
void write_capital_stock_item_static_array(FILE *file, capital_stock_item * temp_datatype, int size);
void write_capital_stock_item_dynamic_array(FILE *file, capital_stock_item_array * temp_datatype);
void init_mall_info(mall_info * temp);
void init_mall_info_static_array(mall_info * array, int size);
void read_mall_info(char * buffer, int * j, mall_info * temp_datatype);
void read_mall_info_dynamic_array(char * buffer, int * j, mall_info_array * temp_datatype_array);
void read_mall_info_static_array(char * buffer, int * j, mall_info * temp_datatype_array, int size);
void write_mall_info(FILE *file, mall_info * temp_datatype);
void write_mall_info_static_array(FILE *file, mall_info * temp_datatype, int size);
void write_mall_info_dynamic_array(FILE *file, mall_info_array * temp_datatype);
void readinitialstates(char * filename, int * itno, double cloud_data[6], 
                       int partition_method, int flag);
void saveiterationdata(int iteration_number);

void free_residual_var_datatype(residual_var_datatype * temp);
void free_residual_var_datatype_static_array(residual_var_datatype * array, int size);
void copy_residual_var_datatype(residual_var_datatype * from, residual_var_datatype * to);
void copy_residual_var_datatype_static_array(residual_var_datatype * from, residual_var_datatype * to, int size);
void free_debt_item(debt_item * temp);
void free_debt_item_static_array(debt_item * array, int size);
void copy_debt_item(debt_item * from, debt_item * to);
void copy_debt_item_static_array(debt_item * from, debt_item * to, int size);
void free_capital_stock_item(capital_stock_item * temp);
void free_capital_stock_item_static_array(capital_stock_item * array, int size);
void copy_capital_stock_item(capital_stock_item * from, capital_stock_item * to);
void copy_capital_stock_item_static_array(capital_stock_item * from, capital_stock_item * to, int size);
void free_mall_info(mall_info * temp);
void free_mall_info_static_array(mall_info * array, int size);
void copy_mall_info(mall_info * from, mall_info * to);
void copy_mall_info_static_array(mall_info * from, mall_info * to, int size);

xmachine_memory_Firm_state * init_Firm_state();
xmachine_memory_Firm * init_Firm_agent();
void free_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * state);
void transition_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * from_state, xmachine_memory_Firm_state * to_state);
void add_Firm_agent_internal(xmachine_memory_Firm * agent, xmachine_memory_Firm_state * state);
void add_Firm_agent(int id, int region_id, int gov_id, int day_of_month_to_act, double payment_account, int bank_id, int dmarketmatrix[], residual_var_datatype residual_var[], double ebit, double earnings, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double net_earnings, double previous_net_earnings, double earnings_per_share, double cum_total_sold_quantity, double cum_revenue, double production_costs, int current_shares_outstanding, double total_payments, mall_info_array * current_mall_stocks, double price, double total_interest_payment, double total_debt_installment_payment, double total_dividend_payment, double current_share_price, double previous_dividend_per_share, double current_dividend_per_share, double previous_earnings_per_share, double current_earnings_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double debt_earnings_ratio, double debt_equity_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, debt_item_array * loans, double total_debt, double total_value_local_inventory, capital_stock_item_array * capital_stock, double total_units_capital_stock, double total_value_capital_stock, double total_capital_depreciation_value, double total_capital_depreciation_units, double total_assets, double equity, double production_liquidity_needs, double financial_liquidity_needs, double total_financial_needs, double external_financial_needs, int bankruptcy_state, int financial_crisis_state);
void unittest_init_Firm_agent();
void unittest_free_Firm_agent();
xmachine_memory_Bank_state * init_Bank_state();
xmachine_memory_Bank * init_Bank_agent();
void free_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * state);
void transition_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * from_state, xmachine_memory_Bank_state * to_state);
void add_Bank_agent_internal(xmachine_memory_Bank * agent, xmachine_memory_Bank_state * state);
void add_Bank_agent(int id, int region_id, int gov_id, double cash, double total_credit, double equity, double bce_debt, double alfa, double value_at_risk, double min_interest, double bank_gamma[], double profits[], double bank_lambda, double bce_interest, double bank_dividend_rate, double tax_rate_corporate, int number_of_shares, double debt_period, int loan_request_message_found, int day_of_month_to_act);
void unittest_init_Bank_agent();
void unittest_free_Bank_agent();
xmachine_memory_Dummy_state * init_Dummy_state();
xmachine_memory_Dummy * init_Dummy_agent();
void free_Dummy_agent(xmachine_memory_Dummy_holder * tmp, xmachine_memory_Dummy_state * state);
void transition_Dummy_agent(xmachine_memory_Dummy_holder * tmp, xmachine_memory_Dummy_state * from_state, xmachine_memory_Dummy_state * to_state);
void add_Dummy_agent_internal(xmachine_memory_Dummy * agent, xmachine_memory_Dummy_state * state);
void add_Dummy_agent(int id);
void unittest_init_Dummy_agent();
void unittest_free_Dummy_agent();

void add_bank_account_update_message(int id, int bank_id, double payment_account);
m_bank_account_update * add_bank_account_update_message_internal(void);
m_bank_account_update * get_first_bank_account_update_message(void);
m_bank_account_update * get_next_bank_account_update_message(m_bank_account_update * current);
void freebank_account_updatemessages(void);
void add_loan_request_message(int firm_id, int bank_id, double equity, double total_debt, double external_financial_needs);
m_loan_request * add_loan_request_message_internal(void);
m_loan_request * get_first_loan_request_message(void);
m_loan_request * get_next_loan_request_message(m_loan_request * current);
void freeloan_requestmessages(void);
void add_loan_conditions_message(int firm_id, int bank_id, double proposed_interest_rate, double amount_offered_credit, double value_at_risk);
m_loan_conditions * add_loan_conditions_message_internal(void);
m_loan_conditions * get_first_loan_conditions_message(void);
m_loan_conditions * get_next_loan_conditions_message(m_loan_conditions * current);
void freeloan_conditionsmessages(void);
void add_loan_acceptance_message(int bank_id, double credit_amount_taken, double loan_total_var);
m_loan_acceptance * add_loan_acceptance_message_internal(void);
m_loan_acceptance * get_first_loan_acceptance_message(void);
m_loan_acceptance * get_next_loan_acceptance_message(m_loan_acceptance * current);
void freeloan_acceptancemessages(void);
void add_installment_message(int bank_id, double installment_amount, double interest_amount, double var_per_installment);
m_installment * add_installment_message_internal(void);
m_installment * get_first_installment_message(void);
m_installment * get_next_installment_message(m_installment * current);
void freeinstallmentmessages(void);
void add_bankruptcy_message(int bank_id, double bad_debt, double credit_refunded, double residual_var);
m_bankruptcy * add_bankruptcy_message_internal(void);
m_bankruptcy * get_first_bankruptcy_message(void);
m_bankruptcy * get_next_bankruptcy_message(m_bankruptcy * current);
void freebankruptcymessages(void);
void add_BCE_return_message(int bce_debt, int id);
m_BCE_return * add_BCE_return_message_internal(void);
m_BCE_return * get_first_BCE_return_message(void);
m_BCE_return * get_next_BCE_return_message(m_BCE_return * current);
void freeBCE_returnmessages(void);
void add_tax_payment_message(int firm_id, int gov_id, double tax_payment);
m_tax_payment * add_tax_payment_message_internal(void);
m_tax_payment * get_first_tax_payment_message(void);
m_tax_payment * get_next_tax_payment_message(m_tax_payment * current);
void freetax_paymentmessages(void);
void add_dividend_per_share_message(int firm_id, double current_dividend_per_share);
m_dividend_per_share * add_dividend_per_share_message_internal(void);
m_dividend_per_share * get_first_dividend_per_share_message(void);
m_dividend_per_share * get_next_dividend_per_share_message(m_dividend_per_share * current);
void freedividend_per_sharemessages(void);
void add_current_mall_stock_info_message(int mall_id, int firm_id, double stock);
m_current_mall_stock_info * add_current_mall_stock_info_message_internal(void);
m_current_mall_stock_info * get_first_current_mall_stock_info_message(void);
m_current_mall_stock_info * get_next_current_mall_stock_info_message(m_current_mall_stock_info * current);
void freecurrent_mall_stock_infomessages(void);
void add_order_message(int trader_id, int asset_id, double limit_price, int quantity);
m_order * add_order_message_internal(void);
m_order * get_first_order_message(void);
m_order * get_next_order_message(m_order * current);
void freeordermessages(void);
void add_order_status_message(int trader_id, int asset_id, double price, int quantity);
m_order_status * add_order_status_message_internal(void);
m_order_status * get_first_order_status_message(void);
m_order_status * get_next_order_status_message(m_order_status * current);
void freeorder_statusmessages(void);

void set_id(int id);
int get_id();
void set_region_id(int region_id);
int get_region_id();
void set_gov_id(int gov_id);
int get_gov_id();
void set_day_of_month_to_act(int day_of_month_to_act);
int get_day_of_month_to_act();
void set_payment_account(double payment_account);
double get_payment_account();
void set_bank_id(int bank_id);
int get_bank_id();
int * get_dmarketmatrix();
residual_var_datatype * get_residual_var();
void set_ebit(double ebit);
double get_ebit();
void set_earnings(double earnings);
double get_earnings();
void set_tax_rate_corporate(double tax_rate_corporate);
double get_tax_rate_corporate();
void set_tax_rate_vat(double tax_rate_vat);
double get_tax_rate_vat();
void set_tax_payment(double tax_payment);
double get_tax_payment();
void set_net_earnings(double net_earnings);
double get_net_earnings();
void set_previous_net_earnings(double previous_net_earnings);
double get_previous_net_earnings();
void set_earnings_per_share(double earnings_per_share);
double get_earnings_per_share();
void set_cum_total_sold_quantity(double cum_total_sold_quantity);
double get_cum_total_sold_quantity();
void set_cum_revenue(double cum_revenue);
double get_cum_revenue();
void set_production_costs(double production_costs);
double get_production_costs();
void set_current_shares_outstanding(int current_shares_outstanding);
int get_current_shares_outstanding();
void set_total_payments(double total_payments);
double get_total_payments();
mall_info_array * get_current_mall_stocks();
void set_price(double price);
double get_price();
void set_total_interest_payment(double total_interest_payment);
double get_total_interest_payment();
void set_total_debt_installment_payment(double total_debt_installment_payment);
double get_total_debt_installment_payment();
void set_total_dividend_payment(double total_dividend_payment);
double get_total_dividend_payment();
void set_current_share_price(double current_share_price);
double get_current_share_price();
void set_previous_dividend_per_share(double previous_dividend_per_share);
double get_previous_dividend_per_share();
void set_current_dividend_per_share(double current_dividend_per_share);
double get_current_dividend_per_share();
void set_previous_earnings_per_share(double previous_earnings_per_share);
double get_previous_earnings_per_share();
void set_current_earnings_per_share(double current_earnings_per_share);
double get_current_earnings_per_share();
void set_previous_dividend_per_earnings(double previous_dividend_per_earnings);
double get_previous_dividend_per_earnings();
void set_current_dividend_per_earnings(double current_dividend_per_earnings);
double get_current_dividend_per_earnings();
void set_debt_earnings_ratio(double debt_earnings_ratio);
double get_debt_earnings_ratio();
void set_debt_equity_ratio(double debt_equity_ratio);
double get_debt_equity_ratio();
void set_price_earnings_ratio(double price_earnings_ratio);
double get_price_earnings_ratio();
void set_retained_earnings_ratio(double retained_earnings_ratio);
double get_retained_earnings_ratio();
void set_earnings_per_share_ratio_growth(double earnings_per_share_ratio_growth);
double get_earnings_per_share_ratio_growth();
void set_critical_price_earnings_ratio(double critical_price_earnings_ratio);
double get_critical_price_earnings_ratio();
void set_critical_earnings_per_share_ratio(double critical_earnings_per_share_ratio);
double get_critical_earnings_per_share_ratio();
debt_item_array * get_loans();
void set_total_debt(double total_debt);
double get_total_debt();
void set_total_value_local_inventory(double total_value_local_inventory);
double get_total_value_local_inventory();
capital_stock_item_array * get_capital_stock();
void set_total_units_capital_stock(double total_units_capital_stock);
double get_total_units_capital_stock();
void set_total_value_capital_stock(double total_value_capital_stock);
double get_total_value_capital_stock();
void set_total_capital_depreciation_value(double total_capital_depreciation_value);
double get_total_capital_depreciation_value();
void set_total_capital_depreciation_units(double total_capital_depreciation_units);
double get_total_capital_depreciation_units();
void set_total_assets(double total_assets);
double get_total_assets();
void set_equity(double equity);
double get_equity();
void set_production_liquidity_needs(double production_liquidity_needs);
double get_production_liquidity_needs();
void set_financial_liquidity_needs(double financial_liquidity_needs);
double get_financial_liquidity_needs();
void set_total_financial_needs(double total_financial_needs);
double get_total_financial_needs();
void set_external_financial_needs(double external_financial_needs);
double get_external_financial_needs();
void set_bankruptcy_state(int bankruptcy_state);
int get_bankruptcy_state();
void set_financial_crisis_state(int financial_crisis_state);
int get_financial_crisis_state();
void set_cash(double cash);
double get_cash();
void set_total_credit(double total_credit);
double get_total_credit();
void set_bce_debt(double bce_debt);
double get_bce_debt();
void set_alfa(double alfa);
double get_alfa();
void set_value_at_risk(double value_at_risk);
double get_value_at_risk();
void set_min_interest(double min_interest);
double get_min_interest();
double * get_bank_gamma();
double * get_profits();
void set_bank_lambda(double bank_lambda);
double get_bank_lambda();
void set_bce_interest(double bce_interest);
double get_bce_interest();
void set_bank_dividend_rate(double bank_dividend_rate);
double get_bank_dividend_rate();
void set_number_of_shares(int number_of_shares);
int get_number_of_shares();
void set_debt_period(double debt_period);
double get_debt_period();
void set_loan_request_message_found(int loan_request_message_found);
int get_loan_request_message_found();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[6], int partitions, int partition_method);

/* messageboard.c */
m_bank_account_update * get_next_message_bank_account_update_in_range(m_bank_account_update * current);
m_loan_request * get_next_message_loan_request_in_range(m_loan_request * current);
m_loan_conditions * get_next_message_loan_conditions_in_range(m_loan_conditions * current);
m_loan_acceptance * get_next_message_loan_acceptance_in_range(m_loan_acceptance * current);
m_installment * get_next_message_installment_in_range(m_installment * current);
m_bankruptcy * get_next_message_bankruptcy_in_range(m_bankruptcy * current);
m_BCE_return * get_next_message_BCE_return_in_range(m_BCE_return * current);
m_tax_payment * get_next_message_tax_payment_in_range(m_tax_payment * current);
m_dividend_per_share * get_next_message_dividend_per_share_in_range(m_dividend_per_share * current);
m_current_mall_stock_info * get_next_message_current_mall_stock_info_in_range(m_current_mall_stock_info * current);
m_order * get_next_message_order_in_range(m_order * current);
m_order_status * get_next_message_order_status_in_range(m_order_status * current);

/* memory.c */
xmachine * add_xmachine(void);
/* timing.c */
double get_time(void);
