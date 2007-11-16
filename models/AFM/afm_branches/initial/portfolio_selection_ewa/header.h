/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT) 
#endif



/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5
/** \def e START_WAGEPAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process WagePayment messages. */
#define START_WAGEPAYMENT_MESSAGE_LOOP  WagePayment_message = get_first_WagePayment_message(); while(WagePayment_message) {
/** \def FINISH_WAGEPAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process WagePayment messages. */
#define FINISH_WAGEPAYMENT_MESSAGE_LOOP WagePayment_message = get_next_WagePayment_message(WagePayment_message); }
/** \def e START_DIVIDENDPAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process DividendPayment messages. */
#define START_DIVIDENDPAYMENT_MESSAGE_LOOP  DividendPayment_message = get_first_DividendPayment_message(); while(DividendPayment_message) {
/** \def FINISH_DIVIDENDPAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process DividendPayment messages. */
#define FINISH_DIVIDENDPAYMENT_MESSAGE_LOOP DividendPayment_message = get_next_DividendPayment_message(DividendPayment_message); }
/** \def e START_BONDCOUPONPAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process BondCouponPayment messages. */
#define START_BONDCOUPONPAYMENT_MESSAGE_LOOP  BondCouponPayment_message = get_first_BondCouponPayment_message(); while(BondCouponPayment_message) {
/** \def FINISH_BONDCOUPONPAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process BondCouponPayment messages. */
#define FINISH_BONDCOUPONPAYMENT_MESSAGE_LOOP BondCouponPayment_message = get_next_BondCouponPayment_message(BondCouponPayment_message); }
/** \def e START_FIRM_BOND_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process firm_bond_order messages. */
#define START_FIRM_BOND_ORDER_MESSAGE_LOOP  firm_bond_order_message = get_first_firm_bond_order_message(); while(firm_bond_order_message) {
/** \def FINISH_FIRM_BOND_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process firm_bond_order messages. */
#define FINISH_FIRM_BOND_ORDER_MESSAGE_LOOP firm_bond_order_message = get_next_firm_bond_order_message(firm_bond_order_message); }
/** \def e START_FIRM_STOCK_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process firm_stock_order messages. */
#define START_FIRM_STOCK_ORDER_MESSAGE_LOOP  firm_stock_order_message = get_first_firm_stock_order_message(); while(firm_stock_order_message) {
/** \def FINISH_FIRM_STOCK_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process firm_stock_order messages. */
#define FINISH_FIRM_STOCK_ORDER_MESSAGE_LOOP firm_stock_order_message = get_next_firm_stock_order_message(firm_stock_order_message); }
/** \def e START_GOV_BOND_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process gov_bond_order messages. */
#define START_GOV_BOND_ORDER_MESSAGE_LOOP  gov_bond_order_message = get_first_gov_bond_order_message(); while(gov_bond_order_message) {
/** \def FINISH_GOV_BOND_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process gov_bond_order messages. */
#define FINISH_GOV_BOND_ORDER_MESSAGE_LOOP gov_bond_order_message = get_next_gov_bond_order_message(gov_bond_order_message); }
/** \def e START_FIRM_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Start of loop to process firm_bond_transaction messages. */
#define START_FIRM_BOND_TRANSACTION_MESSAGE_LOOP  firm_bond_transaction_message = get_first_firm_bond_transaction_message(); while(firm_bond_transaction_message) {
/** \def FINISH_FIRM_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Finish of loop to process firm_bond_transaction messages. */
#define FINISH_FIRM_BOND_TRANSACTION_MESSAGE_LOOP firm_bond_transaction_message = get_next_firm_bond_transaction_message(firm_bond_transaction_message); }
/** \def e START_GOV_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Start of loop to process gov_bond_transaction messages. */
#define START_GOV_BOND_TRANSACTION_MESSAGE_LOOP  gov_bond_transaction_message = get_first_gov_bond_transaction_message(); while(gov_bond_transaction_message) {
/** \def FINISH_GOV_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Finish of loop to process gov_bond_transaction messages. */
#define FINISH_GOV_BOND_TRANSACTION_MESSAGE_LOOP gov_bond_transaction_message = get_next_gov_bond_transaction_message(gov_bond_transaction_message); }
/** \def e START_FIRM_STOCK_TRANSACTION_MESSAGE_LOOP
 * \brief Start of loop to process firm_stock_transaction messages. */
#define START_FIRM_STOCK_TRANSACTION_MESSAGE_LOOP  firm_stock_transaction_message = get_first_firm_stock_transaction_message(); while(firm_stock_transaction_message) {
/** \def FINISH_FIRM_STOCK_TRANSACTION_MESSAGE_LOOP
 * \brief Finish of loop to process firm_stock_transaction messages. */
#define FINISH_FIRM_STOCK_TRANSACTION_MESSAGE_LOOP firm_stock_transaction_message = get_next_firm_stock_transaction_message(firm_stock_transaction_message); }
/** \def e START_RULE_PERFORMANCE_MESSAGE_LOOP
 * \brief Start of loop to process rule_performance messages. */
#define START_RULE_PERFORMANCE_MESSAGE_LOOP  rule_performance_message = get_first_rule_performance_message(); while(rule_performance_message) {
/** \def FINISH_RULE_PERFORMANCE_MESSAGE_LOOP
 * \brief Finish of loop to process rule_performance messages. */
#define FINISH_RULE_PERFORMANCE_MESSAGE_LOOP rule_performance_message = get_next_rule_performance_message(rule_performance_message); }
/** \def e START_ALL_PERFORMANCES_MESSAGE_LOOP
 * \brief Start of loop to process all_performances messages. */
#define START_ALL_PERFORMANCES_MESSAGE_LOOP  all_performances_message = get_first_all_performances_message(); while(all_performances_message) {
/** \def FINISH_ALL_PERFORMANCES_MESSAGE_LOOP
 * \brief Finish of loop to process all_performances messages. */
#define FINISH_ALL_PERFORMANCES_MESSAGE_LOOP all_performances_message = get_next_all_performances_message(all_performances_message); }
/** \def e START_RULE_DETAILS_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process rule_details_request messages. */
#define START_RULE_DETAILS_REQUEST_MESSAGE_LOOP  rule_details_request_message = get_first_rule_details_request_message(); while(rule_details_request_message) {
/** \def FINISH_RULE_DETAILS_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process rule_details_request messages. */
#define FINISH_RULE_DETAILS_REQUEST_MESSAGE_LOOP rule_details_request_message = get_next_rule_details_request_message(rule_details_request_message); }
/** \def e START_RULE_DETAILS_MESSAGE_LOOP
 * \brief Start of loop to process rule_details messages. */
#define START_RULE_DETAILS_MESSAGE_LOOP  rule_details_message = get_first_rule_details_message(); while(rule_details_message) {
/** \def FINISH_RULE_DETAILS_MESSAGE_LOOP
 * \brief Finish of loop to process rule_details messages. */
#define FINISH_RULE_DETAILS_MESSAGE_LOOP rule_details_message = get_next_rule_details_message(rule_details_message); }

/** \struct AssetPortfolioType
 * \brief AssetportfolioType structs are used by the Household.
 *
 * AssetportfolioType structs are used by the Household.
 */
struct AssetPortfolioType
{
	int performance_history;
	int_array firmstocks;
	int_array firm_id;
	double_array current_price;
	double_array best_ask_price;
	double_array best_bid_price;
	double_array nr_units;
	int_array firmbonds;
	int_array firmbonds_firm_id;
	double_array firmbonds_current_price;
	double_array firmbonds_best_ask_price;
	double_array firmbonds_best_bid_price;
	double_array firmbonds_nr_units;
	int_array govbonds;
	int_array govbonds_gov_id;
	double_array govbonds_current_price;
	double_array govbonds_best_ask_price;
	double_array govbonds_best_bid_price;
	double_array govbonds_nr_units;
};

/** \struct AssetPortfolioType_array
 * \brief Dynamic array to hold AssetPortfolioTypes
 */
struct AssetPortfolioType_array
{
	int size;
	int total_size;
	
	struct AssetPortfolioType ** array;
};

/** \struct PrivateClassifierSystem
 * \brief Datatype for the private classifier system inside each agent.  !Subject to change!.
 *
 * Datatype for the private classifier system inside each agent.  !Subject to change!.
 */
struct PrivateClassifierSystem
{
	int ids;
	double experience;
	int current_rule;
	double my_performance;
	double avgperformance;
	double attraction;
	double choiceprob;
	int nr_selected_rule;
};

/** \struct PrivateClassifierSystem_array
 * \brief Dynamic array to hold PrivateClassifierSystems
 */
struct PrivateClassifierSystem_array
{
	int size;
	int total_size;
	
	struct PrivateClassifierSystem ** array;
};

/** \struct PublicClassifierSystem
 * \brief Datatype for the central classifier system. !Subject to change!.
 *
 * Datatype for the central classifier system. !Subject to change!.
 */
struct PublicClassifierSystem
{
	int counter;
	double performance;
	double avgperformance;
	double performance_history;
};

/** \struct PublicClassifierSystem_array
 * \brief Dynamic array to hold PublicClassifierSystems
 */
struct PublicClassifierSystem_array
{
	int size;
	int total_size;
	
	struct PublicClassifierSystem ** array;
};

/** \struct RuleDataType
 * \brief The datatype for rules. Refer to rule_creation.m. !Subject to change!.
 *
 * The datatype for rules. Refer to rule_creation.m. !Subject to change!.
 */
struct RuleDataType
{
	char class;
	int id;
	int performance;
	int counter;
	int avgperformance;
	int my_performance;
	int attraction;
	int choiceprob;
};

/** \struct RuleDataType_array
 * \brief Dynamic array to hold RuleDataTypes
 */
struct RuleDataType_array
{
	int size;
	int total_size;
	
	struct RuleDataType ** array;
};

/** \struct DBFinancialAssets
 * \brief .
 *
 * .
 */
struct DBFinancialAssets
{
};

/** \struct DBFinancialAssets_array
 * \brief Dynamic array to hold DBFinancialAssetss
 */
struct DBFinancialAssets_array
{
	int size;
	int total_size;
	
	struct DBFinancialAssets ** array;
};

/** \struct BondDataType
 * \brief All Bonds have the following datatype. Refer to bond_creation.m.
 *
 * All Bonds have the following datatype. Refer to bond_creation.m.
 */
struct BondDataType
{
	char class;
	int id;
};

/** \struct BondDataType_array
 * \brief Dynamic array to hold BondDataTypes
 */
struct BondDataType_array
{
	int size;
	int total_size;
	
	struct BondDataType ** array;
};

/** \struct StockDataType
 * \brief All stocks have a data type StockDataType. Refer to file stock_creation.m.
 *
 * All stocks have a data type StockDataType. Refer to file stock_creation.m.
 */
struct StockDataType
{
	char class;
	int id;
	int NrOutStandingShares;
	int NrOutStandingShares(1:Parameters.NrDaysInitialization);
	double price;
	int Book_intraday_transaction;
	int dividends;
	int dividends(1:Parameters.NrMonthsInitialization);
};

/** \struct StockDataType_array
 * \brief Dynamic array to hold StockDataTypes
 */
struct StockDataType_array
{
	int size;
	int total_size;
	
	struct StockDataType ** array;
};

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

/** \var typedef AssetPortfolioType AssetPortfolioType
 * \brief Typedef for AssetPortfolioType struct.
 */
typedef struct AssetPortfolioType AssetPortfolioType;
/** \var typedef AssetPortfolioType_array AssetPortfolioType_array
 * \brief Typedef for AssetPortfolioType_array struct.
 */
typedef struct AssetPortfolioType_array AssetPortfolioType_array;
/** \var typedef PrivateClassifierSystem PrivateClassifierSystem
 * \brief Typedef for PrivateClassifierSystem struct.
 */
typedef struct PrivateClassifierSystem PrivateClassifierSystem;
/** \var typedef PrivateClassifierSystem_array PrivateClassifierSystem_array
 * \brief Typedef for PrivateClassifierSystem_array struct.
 */
typedef struct PrivateClassifierSystem_array PrivateClassifierSystem_array;
/** \var typedef PublicClassifierSystem PublicClassifierSystem
 * \brief Typedef for PublicClassifierSystem struct.
 */
typedef struct PublicClassifierSystem PublicClassifierSystem;
/** \var typedef PublicClassifierSystem_array PublicClassifierSystem_array
 * \brief Typedef for PublicClassifierSystem_array struct.
 */
typedef struct PublicClassifierSystem_array PublicClassifierSystem_array;
/** \var typedef RuleDataType RuleDataType
 * \brief Typedef for RuleDataType struct.
 */
typedef struct RuleDataType RuleDataType;
/** \var typedef RuleDataType_array RuleDataType_array
 * \brief Typedef for RuleDataType_array struct.
 */
typedef struct RuleDataType_array RuleDataType_array;
/** \var typedef DBFinancialAssets DBFinancialAssets
 * \brief Typedef for DBFinancialAssets struct.
 */
typedef struct DBFinancialAssets DBFinancialAssets;
/** \var typedef DBFinancialAssets_array DBFinancialAssets_array
 * \brief Typedef for DBFinancialAssets_array struct.
 */
typedef struct DBFinancialAssets_array DBFinancialAssets_array;
/** \var typedef BondDataType BondDataType
 * \brief Typedef for BondDataType struct.
 */
typedef struct BondDataType BondDataType;
/** \var typedef BondDataType_array BondDataType_array
 * \brief Typedef for BondDataType_array struct.
 */
typedef struct BondDataType_array BondDataType_array;
/** \var typedef StockDataType StockDataType
 * \brief Typedef for StockDataType struct.
 */
typedef struct StockDataType StockDataType;
/** \var typedef StockDataType_array StockDataType_array
 * \brief Typedef for StockDataType_array struct.
 */
typedef struct StockDataType_array StockDataType_array;

/** \struct xmachine_memory_Household
 * \brief Holds memory of xmachine Household.
 */
struct xmachine_memory_Household
{
	int household_id;	/**< X-machine memory variable household_id of type int. */
	PrivateClassifierSystem * agent_classifiersystem;	/**< X-machine memory variable agent_classifiersystem of type PrivateClassifierSystem. */
	double asset_budget;	/**< X-machine memory variable asset_budget of type double. */
	AssetPortfolioType * current_assetportfolio;	/**< X-machine memory variable current_assetportfolio of type AssetPortfolioType. */
	AssetPortfolioType * prescribed_assetportfolio;	/**< X-machine memory variable prescribed_assetportfolio of type AssetPortfolioType. */
	int nr_selected_rule;	/**< X-machine memory variable nr_selected_rule of type int. */
	double current_rule_performance;	/**< X-machine memory variable current_rule_performance of type double. */
	double EWA_rho;	/**< X-machine memory variable EWA_rho of type double. */
	double EWA_phi;	/**< X-machine memory variable EWA_phi of type double. */
	double EWA_delta;	/**< X-machine memory variable EWA_delta of type double. */
	double EWA_beta;	/**< X-machine memory variable EWA_beta of type double. */
	double prescribed_asset_value;	/**< X-machine memory variable prescribed_asset_value of type double. */
	double asset_budget;	/**< X-machine memory variable asset_budget of type double. */
	double iradius;	/**< X-machine memory variable iradius of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Firm
 * \brief Holds memory of xmachine Firm.
 */
struct xmachine_memory_Firm
{
	double_array * revenues;	/**< X-machine memory variable revenues of type double_array. */
	double_array * sales_costs;	/**< X-machine memory variable sales_costs of type double_array. */
	double total_revenue;	/**< X-machine memory variable total_revenue of type double. */
	double net_revenue;	/**< X-machine memory variable net_revenue of type double. */
	double operational_cost;	/**< X-machine memory variable operational_cost of type double. */
	double total_wage_payments;	/**< X-machine memory variable total_wage_payments of type double. */
	double total_input_payments;	/**< X-machine memory variable total_input_payments of type double. */
	double interest_payments;	/**< X-machine memory variable interest_payments of type double. */
	double total_earnings;	/**< X-machine memory variable total_earnings of type double. */
	double tax_rate_profits;	/**< X-machine memory variable tax_rate_profits of type double. */
	double pretax_profit;	/**< X-machine memory variable pretax_profit of type double. */
	double tax_provision;	/**< X-machine memory variable tax_provision of type double. */
	double net_earnings;	/**< X-machine memory variable net_earnings of type double. */
	double div_payments;	/**< X-machine memory variable div_payments of type double. */
	double retained_earnings;	/**< X-machine memory variable retained_earnings of type double. */
	double current_debt;	/**< X-machine memory variable current_debt of type double. */
	double debt_interest_rate;	/**< X-machine memory variable debt_interest_rate of type double. */
	double debt_repayments;	/**< X-machine memory variable debt_repayments of type double. */
	double share_repurchase_value;	/**< X-machine memory variable share_repurchase_value of type double. */
	int share_repurchase_units;	/**< X-machine memory variable share_repurchase_units of type int. */
	int target_total_shares;	/**< X-machine memory variable target_total_shares of type int. */
	int current_total_shares;	/**< X-machine memory variable current_total_shares of type int. */
	double total_financial_needs;	/**< X-machine memory variable total_financial_needs of type double. */
	double financial_needs;	/**< X-machine memory variable financial_needs of type double. */
	double add_financial_needs;	/**< X-machine memory variable add_financial_needs of type double. */
	double financial_reserves;	/**< X-machine memory variable financial_reserves of type double. */
	double target_loans;	/**< X-machine memory variable target_loans of type double. */
	double target_equity;	/**< X-machine memory variable target_equity of type double. */
	double bonds_issue_target;	/**< X-machine memory variable bonds_issue_target of type double. */
	double stocks_issue_target;	/**< X-machine memory variable stocks_issue_target of type double. */
	double price;	/**< X-machine memory variable price of type double. */
	double max_debt;	/**< X-machine memory variable max_debt of type double. */
	double div_earn_ratio;	/**< X-machine memory variable div_earn_ratio of type double. */
	double debt_earn_ratio;	/**< X-machine memory variable debt_earn_ratio of type double. */
	double div_pshare_ratio;	/**< X-machine memory variable div_pshare_ratio of type double. */
	double earn_pshare_ratio;	/**< X-machine memory variable earn_pshare_ratio of type double. */
	double price_earn_ratio;	/**< X-machine memory variable price_earn_ratio of type double. */
	double retained_earn_ratio;	/**< X-machine memory variable retained_earn_ratio of type double. */
	double earn_pshare_ratio_growth;	/**< X-machine memory variable earn_pshare_ratio_growth of type double. */
	double critical_price_earn_ratio;	/**< X-machine memory variable critical_price_earn_ratio of type double. */
	double critical_earn_pshare_ratio;	/**< X-machine memory variable critical_earn_pshare_ratio of type double. */
	double iradius;	/**< X-machine memory variable iradius of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Bank
 * \brief Holds memory of xmachine Bank.
 */
struct xmachine_memory_Bank
{
	int id;	/**< X-machine memory variable id of type int. */
	double iradius;	/**< X-machine memory variable iradius of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_ClearingHouseMechanism
 * \brief Holds memory of xmachine ClearingHouseMechanism.
 */
struct xmachine_memory_ClearingHouseMechanism
{
	int id;	/**< X-machine memory variable id of type int. */
	double iradius;	/**< X-machine memory variable iradius of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_LimitOrderBook
 * \brief Holds memory of xmachine LimitOrderBook.
 */
struct xmachine_memory_LimitOrderBook
{
	double re;	/**< X-machine memory variable re of type double. */
	double iradius;	/**< X-machine memory variable iradius of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Government
 * \brief Holds memory of xmachine Government.
 */
struct xmachine_memory_Government
{
	double rj;	/**< X-machine memory variable rj of type double. */
	double iradius;	/**< X-machine memory variable iradius of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_FinancialAdvisor
 * \brief Holds memory of xmachine FinancialAdvisor.
 */
struct xmachine_memory_FinancialAdvisor
{
	PublicClassifierSystem * central_classifiersystem;	/**< X-machine memory variable central_classifiersystem of type PublicClassifierSystem. */
	double iradius;	/**< X-machine memory variable iradius of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	struct xmachine_memory_Household * xmachine_Household;	/**< Pointer to X-machine memory of type Household.  */
	struct xmachine_memory_Firm * xmachine_Firm;	/**< Pointer to X-machine memory of type Firm.  */
	struct xmachine_memory_Bank * xmachine_Bank;	/**< Pointer to X-machine memory of type Bank.  */
	struct xmachine_memory_ClearingHouseMechanism * xmachine_ClearingHouseMechanism;	/**< Pointer to X-machine memory of type ClearingHouseMechanism.  */
	struct xmachine_memory_LimitOrderBook * xmachine_LimitOrderBook;	/**< Pointer to X-machine memory of type LimitOrderBook.  */
	struct xmachine_memory_Government * xmachine_Government;	/**< Pointer to X-machine memory of type Government.  */
	struct xmachine_memory_FinancialAdvisor * xmachine_FinancialAdvisor;	/**< Pointer to X-machine memory of type FinancialAdvisor.  */
	
	struct xmachine * next;	/**< Pointer to next X-machine in the list.  */
};

/** \struct xmachine_message_WagePayment
 * \brief Holds message of type WagePayment_message.
 */
struct xmachine_message_WagePayment
{
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_WagePayment * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_DividendPayment
 * \brief Holds message of type DividendPayment_message.
 */
struct xmachine_message_DividendPayment
{
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_DividendPayment * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_BondCouponPayment
 * \brief Holds message of type BondCouponPayment_message.
 */
struct xmachine_message_BondCouponPayment
{
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_BondCouponPayment * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_firm_bond_order
 * \brief Holds message of type firm_bond_order_message.
 */
struct xmachine_message_firm_bond_order
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double limit_price;	/**< Message memory variable limit_price of type double. */
	double limit_quantity;	/**< Message memory variable limit_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_firm_bond_order * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_firm_stock_order
 * \brief Holds message of type firm_stock_order_message.
 */
struct xmachine_message_firm_stock_order
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double limit_price;	/**< Message memory variable limit_price of type double. */
	double limit_quantity;	/**< Message memory variable limit_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_firm_stock_order * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_gov_bond_order
 * \brief Holds message of type gov_bond_order_message.
 */
struct xmachine_message_gov_bond_order
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double limit_price;	/**< Message memory variable limit_price of type double. */
	double limit_quantity;	/**< Message memory variable limit_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_gov_bond_order * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_firm_bond_transaction
 * \brief Holds message of type firm_bond_transaction_message.
 */
struct xmachine_message_firm_bond_transaction
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double transaction_price;	/**< Message memory variable transaction_price of type double. */
	double transaction_quantity;	/**< Message memory variable transaction_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_firm_bond_transaction * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_gov_bond_transaction
 * \brief Holds message of type gov_bond_transaction_message.
 */
struct xmachine_message_gov_bond_transaction
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double transaction_price;	/**< Message memory variable transaction_price of type double. */
	double transaction_quantity;	/**< Message memory variable transaction_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_gov_bond_transaction * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_firm_stock_transaction
 * \brief Holds message of type firm_stock_transaction_message.
 */
struct xmachine_message_firm_stock_transaction
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double transaction_price;	/**< Message memory variable transaction_price of type double. */
	double transaction_quantity;	/**< Message memory variable transaction_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_firm_stock_transaction * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_rule_performance
 * \brief Holds message of type rule_performance_message.
 */
struct xmachine_message_rule_performance
{
	int nr_selected_rule;	/**< Message memory variable nr_selected_rule of type int. */
	double rule_performance;	/**< Message memory variable rule_performance of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_rule_performance * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_all_performances
 * \brief Holds message of type all_performances_message.
 */
struct xmachine_message_all_performances
{
	double performances;	/**< Message memory variable performances of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_all_performances * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_rule_details_request
 * \brief Holds message of type rule_details_request_message.
 */
struct xmachine_message_rule_details_request
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int selected_rule_number;	/**< Message memory variable selected_rule_number of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_rule_details_request * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_rule_details
 * \brief Holds message of type rule_details_message.
 */
struct xmachine_message_rule_details
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int selected_rule_number;	/**< Message memory variable selected_rule_number of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_rule_details * next;	/**< Pointer to next message in the list. */
};


/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household xmachine_memory_Household;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm xmachine_memory_Firm;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank xmachine_memory_Bank;
/** \var typedef xmachine_memory_ClearingHouseMechanism xmachine_memory_ClearingHouseMechanism
 * \brief Typedef for xmachine_memory_ClearingHouseMechanism struct.
 */
typedef struct xmachine_memory_ClearingHouseMechanism xmachine_memory_ClearingHouseMechanism;
/** \var typedef xmachine_memory_LimitOrderBook xmachine_memory_LimitOrderBook
 * \brief Typedef for xmachine_memory_LimitOrderBook struct.
 */
typedef struct xmachine_memory_LimitOrderBook xmachine_memory_LimitOrderBook;
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government xmachine_memory_Government;
/** \var typedef xmachine_memory_FinancialAdvisor xmachine_memory_FinancialAdvisor
 * \brief Typedef for xmachine_memory_FinancialAdvisor struct.
 */
typedef struct xmachine_memory_FinancialAdvisor xmachine_memory_FinancialAdvisor;
/** \typedef xmachine_message_WagePayment xmachine_message_WagePayment
 * \brief Typedef for xmachine_message_WagePayment struct.
 */
typedef struct xmachine_message_WagePayment xmachine_message_WagePayment;

/** \typedef xmachine_message_DividendPayment xmachine_message_DividendPayment
 * \brief Typedef for xmachine_message_DividendPayment struct.
 */
typedef struct xmachine_message_DividendPayment xmachine_message_DividendPayment;

/** \typedef xmachine_message_BondCouponPayment xmachine_message_BondCouponPayment
 * \brief Typedef for xmachine_message_BondCouponPayment struct.
 */
typedef struct xmachine_message_BondCouponPayment xmachine_message_BondCouponPayment;

/** \typedef xmachine_message_firm_bond_order xmachine_message_firm_bond_order
 * \brief Typedef for xmachine_message_firm_bond_order struct.
 */
typedef struct xmachine_message_firm_bond_order xmachine_message_firm_bond_order;

/** \typedef xmachine_message_firm_stock_order xmachine_message_firm_stock_order
 * \brief Typedef for xmachine_message_firm_stock_order struct.
 */
typedef struct xmachine_message_firm_stock_order xmachine_message_firm_stock_order;

/** \typedef xmachine_message_gov_bond_order xmachine_message_gov_bond_order
 * \brief Typedef for xmachine_message_gov_bond_order struct.
 */
typedef struct xmachine_message_gov_bond_order xmachine_message_gov_bond_order;

/** \typedef xmachine_message_firm_bond_transaction xmachine_message_firm_bond_transaction
 * \brief Typedef for xmachine_message_firm_bond_transaction struct.
 */
typedef struct xmachine_message_firm_bond_transaction xmachine_message_firm_bond_transaction;

/** \typedef xmachine_message_gov_bond_transaction xmachine_message_gov_bond_transaction
 * \brief Typedef for xmachine_message_gov_bond_transaction struct.
 */
typedef struct xmachine_message_gov_bond_transaction xmachine_message_gov_bond_transaction;

/** \typedef xmachine_message_firm_stock_transaction xmachine_message_firm_stock_transaction
 * \brief Typedef for xmachine_message_firm_stock_transaction struct.
 */
typedef struct xmachine_message_firm_stock_transaction xmachine_message_firm_stock_transaction;

/** \typedef xmachine_message_rule_performance xmachine_message_rule_performance
 * \brief Typedef for xmachine_message_rule_performance struct.
 */
typedef struct xmachine_message_rule_performance xmachine_message_rule_performance;

/** \typedef xmachine_message_all_performances xmachine_message_all_performances
 * \brief Typedef for xmachine_message_all_performances struct.
 */
typedef struct xmachine_message_all_performances xmachine_message_all_performances;

/** \typedef xmachine_message_rule_details_request xmachine_message_rule_details_request
 * \brief Typedef for xmachine_message_rule_details_request struct.
 */
typedef struct xmachine_message_rule_details_request xmachine_message_rule_details_request;

/** \typedef xmachine_message_rule_details xmachine_message_rule_details
 * \brief Typedef for xmachine_message_rule_details struct.
 */
typedef struct xmachine_message_rule_details xmachine_message_rule_details;


int Household_send_rule_performance_message(void);
int Household_reads_all_performances_messages(void);
int Household_select_rule(void);
int Household_EWA_learning(void);
int Household_retrieve_rule_details(void);
int Household_apply_selected_rule(void);
int Household_read_transaction_message(void);
int Clearinghouse_read_order_messages(void);
int FinancialAgent_read_rule_performance_message(void);
int FinancialAgent_update_classifiersystem(void);

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
	struct xmachine_message_WagePayment * WagePayment_messages;	/**< Pointer to WagePayment message list. */
	struct xmachine_message_DividendPayment * DividendPayment_messages;	/**< Pointer to DividendPayment message list. */
	struct xmachine_message_BondCouponPayment * BondCouponPayment_messages;	/**< Pointer to BondCouponPayment message list. */
	struct xmachine_message_firm_bond_order * firm_bond_order_messages;	/**< Pointer to firm_bond_order message list. */
	struct xmachine_message_firm_stock_order * firm_stock_order_messages;	/**< Pointer to firm_stock_order message list. */
	struct xmachine_message_gov_bond_order * gov_bond_order_messages;	/**< Pointer to gov_bond_order message list. */
	struct xmachine_message_firm_bond_transaction * firm_bond_transaction_messages;	/**< Pointer to firm_bond_transaction message list. */
	struct xmachine_message_gov_bond_transaction * gov_bond_transaction_messages;	/**< Pointer to gov_bond_transaction message list. */
	struct xmachine_message_firm_stock_transaction * firm_stock_transaction_messages;	/**< Pointer to firm_stock_transaction message list. */
	struct xmachine_message_rule_performance * rule_performance_messages;	/**< Pointer to rule_performance message list. */
	struct xmachine_message_all_performances * all_performances_messages;	/**< Pointer to all_performances message list. */
	struct xmachine_message_rule_details_request * rule_details_request_messages;	/**< Pointer to rule_details_request message list. */
	struct xmachine_message_rule_details * rule_details_messages;	/**< Pointer to rule_details message list. */
	
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

/** \var xmachine_message_WagePayment * temp_WagePayment_message
* \brief Pointer to xmachine_message_WagePayment to initialise linked list. */
xmachine_message_WagePayment * temp_WagePayment_message;
/** \var xmachine_message_DividendPayment * temp_DividendPayment_message
* \brief Pointer to xmachine_message_DividendPayment to initialise linked list. */
xmachine_message_DividendPayment * temp_DividendPayment_message;
/** \var xmachine_message_BondCouponPayment * temp_BondCouponPayment_message
* \brief Pointer to xmachine_message_BondCouponPayment to initialise linked list. */
xmachine_message_BondCouponPayment * temp_BondCouponPayment_message;
/** \var xmachine_message_firm_bond_order * temp_firm_bond_order_message
* \brief Pointer to xmachine_message_firm_bond_order to initialise linked list. */
xmachine_message_firm_bond_order * temp_firm_bond_order_message;
/** \var xmachine_message_firm_stock_order * temp_firm_stock_order_message
* \brief Pointer to xmachine_message_firm_stock_order to initialise linked list. */
xmachine_message_firm_stock_order * temp_firm_stock_order_message;
/** \var xmachine_message_gov_bond_order * temp_gov_bond_order_message
* \brief Pointer to xmachine_message_gov_bond_order to initialise linked list. */
xmachine_message_gov_bond_order * temp_gov_bond_order_message;
/** \var xmachine_message_firm_bond_transaction * temp_firm_bond_transaction_message
* \brief Pointer to xmachine_message_firm_bond_transaction to initialise linked list. */
xmachine_message_firm_bond_transaction * temp_firm_bond_transaction_message;
/** \var xmachine_message_gov_bond_transaction * temp_gov_bond_transaction_message
* \brief Pointer to xmachine_message_gov_bond_transaction to initialise linked list. */
xmachine_message_gov_bond_transaction * temp_gov_bond_transaction_message;
/** \var xmachine_message_firm_stock_transaction * temp_firm_stock_transaction_message
* \brief Pointer to xmachine_message_firm_stock_transaction to initialise linked list. */
xmachine_message_firm_stock_transaction * temp_firm_stock_transaction_message;
/** \var xmachine_message_rule_performance * temp_rule_performance_message
* \brief Pointer to xmachine_message_rule_performance to initialise linked list. */
xmachine_message_rule_performance * temp_rule_performance_message;
/** \var xmachine_message_all_performances * temp_all_performances_message
* \brief Pointer to xmachine_message_all_performances to initialise linked list. */
xmachine_message_all_performances * temp_all_performances_message;
/** \var xmachine_message_rule_details_request * temp_rule_details_request_message
* \brief Pointer to xmachine_message_rule_details_request to initialise linked list. */
xmachine_message_rule_details_request * temp_rule_details_request_message;
/** \var xmachine_message_rule_details * temp_rule_details_message
* \brief Pointer to xmachine_message_rule_details to initialise linked list. */
xmachine_message_rule_details * temp_rule_details_message;
/** \var node_information * temp_node_info
* \brief Pointer to node_information to initialise linked list. */
node_information * temp_node_info;
/** \var char outputpath[100]
* \brief Output path for files. */
char outputpath[100];
/** \var long total_time
* \brief Total time for the simulation run */
long total_time;
/** \var int total_messages
* \brief Total messages sent between nodes for the simulation run */
int total_messages;
/** \var int totalnodes
* \brief Number of nodes */
int totalnodes;
/** \var xmachine ** p_xmachine
* \brief Pointer to first pointer of x-machine memory list */
xmachine ** p_xmachine;
/** \var xmachine * current_xmachine
* \brief Pointer to current x-machine memory that is being processed */
xmachine * current_xmachine;

/** \var xmachine_message_WagePayment ** p_WagePayment_message
* \brief Pointer to first pointer of WagePayment message list */
xmachine_message_WagePayment ** p_WagePayment_message;
/** \var xmachine_message_DividendPayment ** p_DividendPayment_message
* \brief Pointer to first pointer of DividendPayment message list */
xmachine_message_DividendPayment ** p_DividendPayment_message;
/** \var xmachine_message_BondCouponPayment ** p_BondCouponPayment_message
* \brief Pointer to first pointer of BondCouponPayment message list */
xmachine_message_BondCouponPayment ** p_BondCouponPayment_message;
/** \var xmachine_message_firm_bond_order ** p_firm_bond_order_message
* \brief Pointer to first pointer of firm_bond_order message list */
xmachine_message_firm_bond_order ** p_firm_bond_order_message;
/** \var xmachine_message_firm_stock_order ** p_firm_stock_order_message
* \brief Pointer to first pointer of firm_stock_order message list */
xmachine_message_firm_stock_order ** p_firm_stock_order_message;
/** \var xmachine_message_gov_bond_order ** p_gov_bond_order_message
* \brief Pointer to first pointer of gov_bond_order message list */
xmachine_message_gov_bond_order ** p_gov_bond_order_message;
/** \var xmachine_message_firm_bond_transaction ** p_firm_bond_transaction_message
* \brief Pointer to first pointer of firm_bond_transaction message list */
xmachine_message_firm_bond_transaction ** p_firm_bond_transaction_message;
/** \var xmachine_message_gov_bond_transaction ** p_gov_bond_transaction_message
* \brief Pointer to first pointer of gov_bond_transaction message list */
xmachine_message_gov_bond_transaction ** p_gov_bond_transaction_message;
/** \var xmachine_message_firm_stock_transaction ** p_firm_stock_transaction_message
* \brief Pointer to first pointer of firm_stock_transaction message list */
xmachine_message_firm_stock_transaction ** p_firm_stock_transaction_message;
/** \var xmachine_message_rule_performance ** p_rule_performance_message
* \brief Pointer to first pointer of rule_performance message list */
xmachine_message_rule_performance ** p_rule_performance_message;
/** \var xmachine_message_all_performances ** p_all_performances_message
* \brief Pointer to first pointer of all_performances message list */
xmachine_message_all_performances ** p_all_performances_message;
/** \var xmachine_message_rule_details_request ** p_rule_details_request_message
* \brief Pointer to first pointer of rule_details_request message list */
xmachine_message_rule_details_request ** p_rule_details_request_message;
/** \var xmachine_message_rule_details ** p_rule_details_message
* \brief Pointer to first pointer of rule_details message list */
xmachine_message_rule_details ** p_rule_details_message;

/** \var xmachine_message_WagePayment * WagePayment_message
* \brief Pointer to message struct for looping through WagePayment message list */
xmachine_message_WagePayment * WagePayment_message;
/** \var xmachine_message_DividendPayment * DividendPayment_message
* \brief Pointer to message struct for looping through DividendPayment message list */
xmachine_message_DividendPayment * DividendPayment_message;
/** \var xmachine_message_BondCouponPayment * BondCouponPayment_message
* \brief Pointer to message struct for looping through BondCouponPayment message list */
xmachine_message_BondCouponPayment * BondCouponPayment_message;
/** \var xmachine_message_firm_bond_order * firm_bond_order_message
* \brief Pointer to message struct for looping through firm_bond_order message list */
xmachine_message_firm_bond_order * firm_bond_order_message;
/** \var xmachine_message_firm_stock_order * firm_stock_order_message
* \brief Pointer to message struct for looping through firm_stock_order message list */
xmachine_message_firm_stock_order * firm_stock_order_message;
/** \var xmachine_message_gov_bond_order * gov_bond_order_message
* \brief Pointer to message struct for looping through gov_bond_order message list */
xmachine_message_gov_bond_order * gov_bond_order_message;
/** \var xmachine_message_firm_bond_transaction * firm_bond_transaction_message
* \brief Pointer to message struct for looping through firm_bond_transaction message list */
xmachine_message_firm_bond_transaction * firm_bond_transaction_message;
/** \var xmachine_message_gov_bond_transaction * gov_bond_transaction_message
* \brief Pointer to message struct for looping through gov_bond_transaction message list */
xmachine_message_gov_bond_transaction * gov_bond_transaction_message;
/** \var xmachine_message_firm_stock_transaction * firm_stock_transaction_message
* \brief Pointer to message struct for looping through firm_stock_transaction message list */
xmachine_message_firm_stock_transaction * firm_stock_transaction_message;
/** \var xmachine_message_rule_performance * rule_performance_message
* \brief Pointer to message struct for looping through rule_performance message list */
xmachine_message_rule_performance * rule_performance_message;
/** \var xmachine_message_all_performances * all_performances_message
* \brief Pointer to message struct for looping through all_performances message list */
xmachine_message_all_performances * all_performances_message;
/** \var xmachine_message_rule_details_request * rule_details_request_message
* \brief Pointer to message struct for looping through rule_details_request message list */
xmachine_message_rule_details_request * rule_details_request_message;
/** \var xmachine_message_rule_details * rule_details_message
* \brief Pointer to message struct for looping through rule_details message list */
xmachine_message_rule_details * rule_details_message;
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
/** \var int use_binary_output
* \brief Tag to save results in a binary file */
int use_binary_output;
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
void add_location(double point, location ** p_location);
void freelocations(location ** p_location);
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz);
void clean_up(int code);
void propagate_agents(void);
void propagate_messages_init(void);
void propagate_messages_complete(void);
void create_partitions(char * filename, int * itno);
void free_node_info(void);
void randomisexagent(void);
void free_agent(void);
void freexmachines(void);
/* model datatypes */

AssetPortfolioType_array * init_AssetPortfolioType_array();
void reset_AssetPortfolioType_array(AssetPortfolioType_array * array);
void free_AssetPortfolioType_array(AssetPortfolioType_array * array);
void add_AssetPortfolioType(AssetPortfolioType_array * array, int performance_history, int_array firmstocks, int_array firm_id, double_array current_price, double_array best_ask_price, double_array best_bid_price, double_array nr_units, int_array firmbonds, int_array firmbonds_firm_id, double_array firmbonds_current_price, double_array firmbonds_best_ask_price, double_array firmbonds_best_bid_price, double_array firmbonds_nr_units, int_array govbonds, int_array govbonds_gov_id, double_array govbonds_current_price, double_array govbonds_best_ask_price, double_array govbonds_best_bid_price, double_array govbonds_nr_units);
void remove_AssetPortfolioType(AssetPortfolioType_array * array, int index);

PrivateClassifierSystem_array * init_PrivateClassifierSystem_array();
void reset_PrivateClassifierSystem_array(PrivateClassifierSystem_array * array);
void free_PrivateClassifierSystem_array(PrivateClassifierSystem_array * array);
void add_PrivateClassifierSystem(PrivateClassifierSystem_array * array, int ids, double experience, int current_rule, double my_performance, double avgperformance, double attraction, double choiceprob, int nr_selected_rule);
void remove_PrivateClassifierSystem(PrivateClassifierSystem_array * array, int index);

PublicClassifierSystem_array * init_PublicClassifierSystem_array();
void reset_PublicClassifierSystem_array(PublicClassifierSystem_array * array);
void free_PublicClassifierSystem_array(PublicClassifierSystem_array * array);
void add_PublicClassifierSystem(PublicClassifierSystem_array * array, int counter, double performance, double avgperformance, double performance_history);
void remove_PublicClassifierSystem(PublicClassifierSystem_array * array, int index);

RuleDataType_array * init_RuleDataType_array();
void reset_RuleDataType_array(RuleDataType_array * array);
void free_RuleDataType_array(RuleDataType_array * array);
void add_RuleDataType(RuleDataType_array * array, char class, int id, int performance, int counter, int avgperformance, int my_performance, int attraction, int choiceprob);
void remove_RuleDataType(RuleDataType_array * array, int index);

DBFinancialAssets_array * init_DBFinancialAssets_array();
void reset_DBFinancialAssets_array(DBFinancialAssets_array * array);
void free_DBFinancialAssets_array(DBFinancialAssets_array * array);
void add_DBFinancialAssets(DBFinancialAssets_array * array);
void remove_DBFinancialAssets(DBFinancialAssets_array * array, int index);

BondDataType_array * init_BondDataType_array();
void reset_BondDataType_array(BondDataType_array * array);
void free_BondDataType_array(BondDataType_array * array);
void add_BondDataType(BondDataType_array * array, char class, int id);
void remove_BondDataType(BondDataType_array * array, int index);

StockDataType_array * init_StockDataType_array();
void reset_StockDataType_array(StockDataType_array * array);
void free_StockDataType_array(StockDataType_array * array);
void add_StockDataType(StockDataType_array * array, char class, int id, int NrOutStandingShares, int NrOutStandingShares(1:Parameters.NrDaysInitialization), double price, int Book_intraday_transaction, int dividends, int dividends(1:Parameters.NrMonthsInitialization));
void remove_StockDataType(StockDataType_array * array, int index);


int_array * init_int_array(void);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void sort_int_array(int_array * array);
int quicksort_int(int * array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
float_array * init_float_array(void);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void sort_float_array(float_array * array);
int quicksort_float(float * array, int elements);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
double_array * init_double_array(void);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void sort_double_array(double_array * array);
int quicksort_double(double * array, int elements);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
char_array * init_char_array(void);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
/* xml.c */
void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], 
                       int partition_method, int flag);
void saveiterationdata_binary(int iteration_number);
void saveiterationdata(int iteration_number);

void add_Household_agent(int household_id, PrivateClassifierSystem * agent_classifiersystem, double asset_budget, AssetPortfolioType * current_assetportfolio, AssetPortfolioType * prescribed_assetportfolio, int nr_selected_rule, double current_rule_performance, double EWA_rho, double EWA_phi, double EWA_delta, double EWA_beta, double prescribed_asset_value, double asset_budget, double iradius, double posx, double posy);
void add_Firm_agent(double_array * revenues, double_array * sales_costs, double total_revenue, double net_revenue, double operational_cost, double total_wage_payments, double total_input_payments, double interest_payments, double total_earnings, double tax_rate_profits, double pretax_profit, double tax_provision, double net_earnings, double div_payments, double retained_earnings, double current_debt, double debt_interest_rate, double debt_repayments, double share_repurchase_value, int share_repurchase_units, int target_total_shares, int current_total_shares, double total_financial_needs, double financial_needs, double add_financial_needs, double financial_reserves, double target_loans, double target_equity, double bonds_issue_target, double stocks_issue_target, double price, double max_debt, double div_earn_ratio, double debt_earn_ratio, double div_pshare_ratio, double earn_pshare_ratio, double price_earn_ratio, double retained_earn_ratio, double earn_pshare_ratio_growth, double critical_price_earn_ratio, double critical_earn_pshare_ratio, double iradius, double posx, double posy);
void add_Bank_agent(int id, double iradius, double posx, double posy);
void add_ClearingHouseMechanism_agent(int id, double iradius, double posx, double posy);
void add_LimitOrderBook_agent(double re, double iradius, double posx, double posy);
void add_Government_agent(double rj, double iradius, double posx, double posy);
void add_FinancialAdvisor_agent(PublicClassifierSystem * central_classifiersystem, double iradius, double posx, double posy);

void add_WagePayment_message(double range, double x, double y, double z);
xmachine_message_WagePayment * add_WagePayment_message_internal(void);
xmachine_message_WagePayment * get_first_WagePayment_message(void);
xmachine_message_WagePayment * get_next_WagePayment_message(xmachine_message_WagePayment * current);
void freeWagePaymentmessages(void);
void add_DividendPayment_message(double range, double x, double y, double z);
xmachine_message_DividendPayment * add_DividendPayment_message_internal(void);
xmachine_message_DividendPayment * get_first_DividendPayment_message(void);
xmachine_message_DividendPayment * get_next_DividendPayment_message(xmachine_message_DividendPayment * current);
void freeDividendPaymentmessages(void);
void add_BondCouponPayment_message(double range, double x, double y, double z);
xmachine_message_BondCouponPayment * add_BondCouponPayment_message_internal(void);
xmachine_message_BondCouponPayment * get_first_BondCouponPayment_message(void);
xmachine_message_BondCouponPayment * get_next_BondCouponPayment_message(xmachine_message_BondCouponPayment * current);
void freeBondCouponPaymentmessages(void);
void add_firm_bond_order_message(int household_id, int firm_id, double limit_price, double limit_quantity, double range, double x, double y, double z);
xmachine_message_firm_bond_order * add_firm_bond_order_message_internal(void);
xmachine_message_firm_bond_order * get_first_firm_bond_order_message(void);
xmachine_message_firm_bond_order * get_next_firm_bond_order_message(xmachine_message_firm_bond_order * current);
void freefirm_bond_ordermessages(void);
void add_firm_stock_order_message(int household_id, int firm_id, double limit_price, double limit_quantity, double range, double x, double y, double z);
xmachine_message_firm_stock_order * add_firm_stock_order_message_internal(void);
xmachine_message_firm_stock_order * get_first_firm_stock_order_message(void);
xmachine_message_firm_stock_order * get_next_firm_stock_order_message(xmachine_message_firm_stock_order * current);
void freefirm_stock_ordermessages(void);
void add_gov_bond_order_message(int household_id, int gov_id, double limit_price, double limit_quantity, double range, double x, double y, double z);
xmachine_message_gov_bond_order * add_gov_bond_order_message_internal(void);
xmachine_message_gov_bond_order * get_first_gov_bond_order_message(void);
xmachine_message_gov_bond_order * get_next_gov_bond_order_message(xmachine_message_gov_bond_order * current);
void freegov_bond_ordermessages(void);
void add_firm_bond_transaction_message(int household_id, int firm_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z);
xmachine_message_firm_bond_transaction * add_firm_bond_transaction_message_internal(void);
xmachine_message_firm_bond_transaction * get_first_firm_bond_transaction_message(void);
xmachine_message_firm_bond_transaction * get_next_firm_bond_transaction_message(xmachine_message_firm_bond_transaction * current);
void freefirm_bond_transactionmessages(void);
void add_gov_bond_transaction_message(int household_id, int gov_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z);
xmachine_message_gov_bond_transaction * add_gov_bond_transaction_message_internal(void);
xmachine_message_gov_bond_transaction * get_first_gov_bond_transaction_message(void);
xmachine_message_gov_bond_transaction * get_next_gov_bond_transaction_message(xmachine_message_gov_bond_transaction * current);
void freegov_bond_transactionmessages(void);
void add_firm_stock_transaction_message(int household_id, int firm_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z);
xmachine_message_firm_stock_transaction * add_firm_stock_transaction_message_internal(void);
xmachine_message_firm_stock_transaction * get_first_firm_stock_transaction_message(void);
xmachine_message_firm_stock_transaction * get_next_firm_stock_transaction_message(xmachine_message_firm_stock_transaction * current);
void freefirm_stock_transactionmessages(void);
void add_rule_performance_message(int nr_selected_rule, double rule_performance, double range, double x, double y, double z);
xmachine_message_rule_performance * add_rule_performance_message_internal(void);
xmachine_message_rule_performance * get_first_rule_performance_message(void);
xmachine_message_rule_performance * get_next_rule_performance_message(xmachine_message_rule_performance * current);
void freerule_performancemessages(void);
void add_all_performances_message(double performances, double range, double x, double y, double z);
xmachine_message_all_performances * add_all_performances_message_internal(void);
xmachine_message_all_performances * get_first_all_performances_message(void);
xmachine_message_all_performances * get_next_all_performances_message(xmachine_message_all_performances * current);
void freeall_performancesmessages(void);
void add_rule_details_request_message(int household_id, int selected_rule_number, double range, double x, double y, double z);
xmachine_message_rule_details_request * add_rule_details_request_message_internal(void);
xmachine_message_rule_details_request * get_first_rule_details_request_message(void);
xmachine_message_rule_details_request * get_next_rule_details_request_message(xmachine_message_rule_details_request * current);
void freerule_details_requestmessages(void);
void add_rule_details_message(int household_id, int selected_rule_number, double range, double x, double y, double z);
xmachine_message_rule_details * add_rule_details_message_internal(void);
xmachine_message_rule_details * get_first_rule_details_message(void);
xmachine_message_rule_details * get_next_rule_details_message(xmachine_message_rule_details * current);
void freerule_detailsmessages(void);

void set_household_id(int household_id);
int get_household_id(void);
PrivateClassifierSystem * get_agent_classifiersystem(void);
void set_asset_budget(double asset_budget);
double get_asset_budget(void);
AssetPortfolioType * get_current_assetportfolio(void);
AssetPortfolioType * get_prescribed_assetportfolio(void);
void set_nr_selected_rule(int nr_selected_rule);
int get_nr_selected_rule(void);
void set_current_rule_performance(double current_rule_performance);
double get_current_rule_performance(void);
void set_EWA_rho(double EWA_rho);
double get_EWA_rho(void);
void set_EWA_phi(double EWA_phi);
double get_EWA_phi(void);
void set_EWA_delta(double EWA_delta);
double get_EWA_delta(void);
void set_EWA_beta(double EWA_beta);
double get_EWA_beta(void);
void set_prescribed_asset_value(double prescribed_asset_value);
double get_prescribed_asset_value(void);
void set_iradius(double iradius);
double get_iradius(void);
void set_posx(double posx);
double get_posx(void);
void set_posy(double posy);
double get_posy(void);
double_array * get_revenues(void);
double_array * get_sales_costs(void);
void set_total_revenue(double total_revenue);
double get_total_revenue(void);
void set_net_revenue(double net_revenue);
double get_net_revenue(void);
void set_operational_cost(double operational_cost);
double get_operational_cost(void);
void set_total_wage_payments(double total_wage_payments);
double get_total_wage_payments(void);
void set_total_input_payments(double total_input_payments);
double get_total_input_payments(void);
void set_interest_payments(double interest_payments);
double get_interest_payments(void);
void set_total_earnings(double total_earnings);
double get_total_earnings(void);
void set_tax_rate_profits(double tax_rate_profits);
double get_tax_rate_profits(void);
void set_pretax_profit(double pretax_profit);
double get_pretax_profit(void);
void set_tax_provision(double tax_provision);
double get_tax_provision(void);
void set_net_earnings(double net_earnings);
double get_net_earnings(void);
void set_div_payments(double div_payments);
double get_div_payments(void);
void set_retained_earnings(double retained_earnings);
double get_retained_earnings(void);
void set_current_debt(double current_debt);
double get_current_debt(void);
void set_debt_interest_rate(double debt_interest_rate);
double get_debt_interest_rate(void);
void set_debt_repayments(double debt_repayments);
double get_debt_repayments(void);
void set_share_repurchase_value(double share_repurchase_value);
double get_share_repurchase_value(void);
void set_share_repurchase_units(int share_repurchase_units);
int get_share_repurchase_units(void);
void set_target_total_shares(int target_total_shares);
int get_target_total_shares(void);
void set_current_total_shares(int current_total_shares);
int get_current_total_shares(void);
void set_total_financial_needs(double total_financial_needs);
double get_total_financial_needs(void);
void set_financial_needs(double financial_needs);
double get_financial_needs(void);
void set_add_financial_needs(double add_financial_needs);
double get_add_financial_needs(void);
void set_financial_reserves(double financial_reserves);
double get_financial_reserves(void);
void set_target_loans(double target_loans);
double get_target_loans(void);
void set_target_equity(double target_equity);
double get_target_equity(void);
void set_bonds_issue_target(double bonds_issue_target);
double get_bonds_issue_target(void);
void set_stocks_issue_target(double stocks_issue_target);
double get_stocks_issue_target(void);
void set_price(double price);
double get_price(void);
void set_max_debt(double max_debt);
double get_max_debt(void);
void set_div_earn_ratio(double div_earn_ratio);
double get_div_earn_ratio(void);
void set_debt_earn_ratio(double debt_earn_ratio);
double get_debt_earn_ratio(void);
void set_div_pshare_ratio(double div_pshare_ratio);
double get_div_pshare_ratio(void);
void set_earn_pshare_ratio(double earn_pshare_ratio);
double get_earn_pshare_ratio(void);
void set_price_earn_ratio(double price_earn_ratio);
double get_price_earn_ratio(void);
void set_retained_earn_ratio(double retained_earn_ratio);
double get_retained_earn_ratio(void);
void set_earn_pshare_ratio_growth(double earn_pshare_ratio_growth);
double get_earn_pshare_ratio_growth(void);
void set_critical_price_earn_ratio(double critical_price_earn_ratio);
double get_critical_price_earn_ratio(void);
void set_critical_earn_pshare_ratio(double critical_earn_pshare_ratio);
double get_critical_earn_pshare_ratio(void);
void set_id(int id);
int get_id(void);
void set_re(double re);
double get_re(void);
void set_rj(double rj);
double get_rj(void);
PublicClassifierSystem * get_central_classifiersystem(void);
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[6], int partitions, int partition_method);

/* messageboard.c */
xmachine_message_WagePayment * get_next_message_WagePayment_in_range(xmachine_message_WagePayment * current);
xmachine_message_DividendPayment * get_next_message_DividendPayment_in_range(xmachine_message_DividendPayment * current);
xmachine_message_BondCouponPayment * get_next_message_BondCouponPayment_in_range(xmachine_message_BondCouponPayment * current);
xmachine_message_firm_bond_order * get_next_message_firm_bond_order_in_range(xmachine_message_firm_bond_order * current);
xmachine_message_firm_stock_order * get_next_message_firm_stock_order_in_range(xmachine_message_firm_stock_order * current);
xmachine_message_gov_bond_order * get_next_message_gov_bond_order_in_range(xmachine_message_gov_bond_order * current);
xmachine_message_firm_bond_transaction * get_next_message_firm_bond_transaction_in_range(xmachine_message_firm_bond_transaction * current);
xmachine_message_gov_bond_transaction * get_next_message_gov_bond_transaction_in_range(xmachine_message_gov_bond_transaction * current);
xmachine_message_firm_stock_transaction * get_next_message_firm_stock_transaction_in_range(xmachine_message_firm_stock_transaction * current);
xmachine_message_rule_performance * get_next_message_rule_performance_in_range(xmachine_message_rule_performance * current);
xmachine_message_all_performances * get_next_message_all_performances_in_range(xmachine_message_all_performances * current);
xmachine_message_rule_details_request * get_next_message_rule_details_request_in_range(xmachine_message_rule_details_request * current);
xmachine_message_rule_details * get_next_message_rule_details_in_range(xmachine_message_rule_details * current);

/* memory.c */
xmachine * add_xmachine(void);
