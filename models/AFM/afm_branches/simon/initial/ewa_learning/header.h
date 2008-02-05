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
/** \def e START_FIRM_BOND_ORDERS_MESSAGE_LOOP
 * \brief Start of loop to process firm_bond_orders messages. */
#define START_FIRM_BOND_ORDERS_MESSAGE_LOOP  firm_bond_orders_message = get_first_firm_bond_orders_message(); while(firm_bond_orders_message) {
/** \def FINISH_FIRM_BOND_ORDERS_MESSAGE_LOOP
 * \brief Finish of loop to process firm_bond_orders messages. */
#define FINISH_FIRM_BOND_ORDERS_MESSAGE_LOOP firm_bond_orders_message = get_next_firm_bond_orders_message(firm_bond_orders_message); }
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
/** \def e START_FA_RULE_PERFORMANCE_MESSAGE_LOOP
 * \brief Start of loop to process fa_rule_performance messages. */
#define START_FA_RULE_PERFORMANCE_MESSAGE_LOOP  fa_rule_performance_message = get_first_fa_rule_performance_message(); while(fa_rule_performance_message) {
/** \def FINISH_FA_RULE_PERFORMANCE_MESSAGE_LOOP
 * \brief Finish of loop to process fa_rule_performance messages. */
#define FINISH_FA_RULE_PERFORMANCE_MESSAGE_LOOP fa_rule_performance_message = get_next_fa_rule_performance_message(fa_rule_performance_message); }
/** \def e START_RULEDETAILSYSTEM_MESSAGE_LOOP
 * \brief Start of loop to process ruledetailsystem messages. */
#define START_RULEDETAILSYSTEM_MESSAGE_LOOP  ruledetailsystem_message = get_first_ruledetailsystem_message(); while(ruledetailsystem_message) {
/** \def FINISH_RULEDETAILSYSTEM_MESSAGE_LOOP
 * \brief Finish of loop to process ruledetailsystem messages. */
#define FINISH_RULEDETAILSYSTEM_MESSAGE_LOOP ruledetailsystem_message = get_next_ruledetailsystem_message(ruledetailsystem_message); }

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

/** \struct string
 * \brief ˆ=.
 *
 * ˆ=.
 */
struct string
{
	char_array * stringname;	/**< Datatype memory variable stringname of type char_array. */
};

/** \struct string_array
 * \brief Dynamic array to hold strings
 */
struct string_array
{
	int size;
	int total_size;
	
	struct string ** array;
};

/** \var typedef string string
 * \brief Typedef for string struct.
 */
typedef struct string string;
/** \var typedef string_array string_array
 * \brief Typedef for string_array struct.
 */
typedef struct string_array string_array;
/** \struct stringlist
 * \brief ¸=.
 *
 * ¸=.
 */
struct stringlist
{
	string_array * stringlistname;	/**< Datatype memory variable stringlistname of type string_array. */
};

/** \struct stringlist_array
 * \brief Dynamic array to hold stringlists
 */
struct stringlist_array
{
	int size;
	int total_size;
	
	struct stringlist ** array;
};

/** \var typedef stringlist stringlist
 * \brief Typedef for stringlist struct.
 */
typedef struct stringlist stringlist;
/** \var typedef stringlist_array stringlist_array
 * \brief Typedef for stringlist_array struct.
 */
typedef struct stringlist_array stringlist_array;
/** \struct word
 * \brief PiI.
 *
 * PiI.
 */
struct word
{
	char_array * wordname;	/**< Datatype memory variable wordname of type char_array. */
};

/** \struct word_array
 * \brief Dynamic array to hold words
 */
struct word_array
{
	int size;
	int total_size;
	
	struct word ** array;
};

/** \var typedef word word
 * \brief Typedef for word struct.
 */
typedef struct word word;
/** \var typedef word_array word_array
 * \brief Typedef for word_array struct.
 */
typedef struct word_array word_array;
/** \struct wordlist
 * \brief =.
 *
 * =.
 */
struct wordlist
{
	word_array * wordlistname;	/**< Datatype memory variable wordlistname of type word_array. */
};

/** \struct wordlist_array
 * \brief Dynamic array to hold wordlists
 */
struct wordlist_array
{
	int size;
	int total_size;
	
	struct wordlist ** array;
};

/** \var typedef wordlist wordlist
 * \brief Typedef for wordlist struct.
 */
typedef struct wordlist wordlist;
/** \var typedef wordlist_array wordlist_array
 * \brief Typedef for wordlist_array struct.
 */
typedef struct wordlist_array wordlist_array;
/** \struct int2D
 * \brief =.
 *
 * =.
 */
struct int2D
{
	int_array * int2Dname;	/**< Datatype memory variable int2Dname of type int_array. */
};

/** \struct int2D_array
 * \brief Dynamic array to hold int2Ds
 */
struct int2D_array
{
	int size;
	int total_size;
	
	struct int2D ** array;
};

/** \var typedef int2D int2D
 * \brief Typedef for int2D struct.
 */
typedef struct int2D int2D;
/** \var typedef int2D_array int2D_array
 * \brief Typedef for int2D_array struct.
 */
typedef struct int2D_array int2D_array;
/** \struct double2D
 * \brief  =.
 *
 *  =.
 */
struct double2D
{
	double_array * double2Dname;	/**< Datatype memory variable double2Dname of type double_array. */
};

/** \struct double2D_array
 * \brief Dynamic array to hold double2Ds
 */
struct double2D_array
{
	int size;
	int total_size;
	
	struct double2D ** array;
};

/** \var typedef double2D double2D
 * \brief Typedef for double2D struct.
 */
typedef struct double2D double2D;
/** \var typedef double2D_array double2D_array
 * \brief Typedef for double2D_array struct.
 */
typedef struct double2D_array double2D_array;
/** \struct RuleDetailSystem
 * \brief Datatype for all rule details.  !Subject to change!.
 *
 * Datatype for all rule details.  !Subject to change!.
 */
struct RuleDetailSystem
{
	int_array * nr_params_per_type;	/**< Datatype memory variable nr_params_per_type of type int_array. */
	int_array * nr_params;	/**< Datatype memory variable nr_params of type int_array. */
	double2D_array * parameters;	/**< Datatype memory variable parameters of type double2D_array. */
	wordlist * myfunctionnames;	/**< Datatype memory variable myfunctionnames of type wordlist. */
};

/** \struct RuleDetailSystem_array
 * \brief Dynamic array to hold RuleDetailSystems
 */
struct RuleDetailSystem_array
{
	int size;
	int total_size;
	
	struct RuleDetailSystem ** array;
};

/** \var typedef RuleDetailSystem RuleDetailSystem
 * \brief Typedef for RuleDetailSystem struct.
 */
typedef struct RuleDetailSystem RuleDetailSystem;
/** \var typedef RuleDetailSystem_array RuleDetailSystem_array
 * \brief Typedef for RuleDetailSystem_array struct.
 */
typedef struct RuleDetailSystem_array RuleDetailSystem_array;
/** \struct PublicClassifierSystem
 * \brief Datatype for the central classifier system. !Subject to change!.
 *
 * Datatype for the central classifier system. !Subject to change!.
 */
struct PublicClassifierSystem
{
	int nr_types;	/**< Datatype memory variable nr_types of type int. */
	int_array * nr_rules_per_type;	/**< Datatype memory variable nr_rules_per_type of type int_array. */
	int nr_rules;	/**< Datatype memory variable nr_rules of type int. */
	int_array * ids;	/**< Datatype memory variable ids of type int_array. */
	int_array * rule_type;	/**< Datatype memory variable rule_type of type int_array. */
	int_array * counter;	/**< Datatype memory variable counter of type int_array. */
	double_array * performance;	/**< Datatype memory variable performance of type double_array. */
	double_array * avgperformance;	/**< Datatype memory variable avgperformance of type double_array. */
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

/** \var typedef PublicClassifierSystem PublicClassifierSystem
 * \brief Typedef for PublicClassifierSystem struct.
 */
typedef struct PublicClassifierSystem PublicClassifierSystem;
/** \var typedef PublicClassifierSystem_array PublicClassifierSystem_array
 * \brief Typedef for PublicClassifierSystem_array struct.
 */
typedef struct PublicClassifierSystem_array PublicClassifierSystem_array;
/** \struct PrivateClassifierSystem
 * \brief Datatype for the private classifier system inside each agent.  !Subject to change!.
 *
 * Datatype for the private classifier system inside each agent.  !Subject to change!.
 */
struct PrivateClassifierSystem
{
	int nr_types;	/**< Datatype memory variable nr_types of type int. */
	int_array * nr_rules_per_type;	/**< Datatype memory variable nr_rules_per_type of type int_array. */
	int nr_rules;	/**< Datatype memory variable nr_rules of type int. */
	int_array * ids;	/**< Datatype memory variable ids of type int_array. */
	int_array * rule_type;	/**< Datatype memory variable rule_type of type int_array. */
	double EWA_rho;	/**< Datatype memory variable EWA_rho of type double. */
	double EWA_phi;	/**< Datatype memory variable EWA_phi of type double. */
	double EWA_delta;	/**< Datatype memory variable EWA_delta of type double. */
	double EWA_beta;	/**< Datatype memory variable EWA_beta of type double. */
	int experience;	/**< Datatype memory variable experience of type int. */
	int current_rule;	/**< Datatype memory variable current_rule of type int. */
	double my_performance;	/**< Datatype memory variable my_performance of type double. */
	double_array * avgperformance;	/**< Datatype memory variable avgperformance of type double_array. */
	double_array * attraction;	/**< Datatype memory variable attraction of type double_array. */
	double_array * choiceprob;	/**< Datatype memory variable choiceprob of type double_array. */
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

/** \var typedef PrivateClassifierSystem PrivateClassifierSystem
 * \brief Typedef for PrivateClassifierSystem struct.
 */
typedef struct PrivateClassifierSystem PrivateClassifierSystem;
/** \var typedef PrivateClassifierSystem_array PrivateClassifierSystem_array
 * \brief Typedef for PrivateClassifierSystem_array struct.
 */
typedef struct PrivateClassifierSystem_array PrivateClassifierSystem_array;
/** \struct StockDataType
 * \brief All stocks have a data type StockDataType. Refer to file stock_creation.m.
 *
 * All stocks have a data type StockDataType. Refer to file stock_creation.m.
 */
struct StockDataType
{
	char class[5];	/**< Datatype memory variable class of type char. */
	int id[5];	/**< Datatype memory variable id of type int. */
	int_array * NrOutStandingShares;	/**< Datatype memory variable NrOutStandingShares of type int_array. */
	double price;	/**< Datatype memory variable price of type double. */
	int Book_intraday_transaction;	/**< Datatype memory variable Book_intraday_transaction of type int. */
	int_array * dividends;	/**< Datatype memory variable dividends of type int_array. */
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

/** \var typedef StockDataType StockDataType
 * \brief Typedef for StockDataType struct.
 */
typedef struct StockDataType StockDataType;
/** \var typedef StockDataType_array StockDataType_array
 * \brief Typedef for StockDataType_array struct.
 */
typedef struct StockDataType_array StockDataType_array;
/** \struct BondDataType
 * \brief All Bonds have the following datatype. Refer to bond_creation.m.
 *
 * All Bonds have the following datatype. Refer to bond_creation.m.
 */
struct BondDataType
{
	char class[5];	/**< Datatype memory variable class of type char. */
	int id[5];	/**< Datatype memory variable id of type int. */
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

/** \var typedef BondDataType BondDataType
 * \brief Typedef for BondDataType struct.
 */
typedef struct BondDataType BondDataType;
/** \var typedef BondDataType_array BondDataType_array
 * \brief Typedef for BondDataType_array struct.
 */
typedef struct BondDataType_array BondDataType_array;
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

/** \var typedef DBFinancialAssets DBFinancialAssets
 * \brief Typedef for DBFinancialAssets struct.
 */
typedef struct DBFinancialAssets DBFinancialAssets;
/** \var typedef DBFinancialAssets_array DBFinancialAssets_array
 * \brief Typedef for DBFinancialAssets_array struct.
 */
typedef struct DBFinancialAssets_array DBFinancialAssets_array;
/** \struct Asset
 * \brief Datatype for asset structures.
 *
 * Datatype for asset structures.
 */
struct Asset
{
	int_array * ids;	/**< Datatype memory variable ids of type int_array. */
	int_array * nr_units;	/**< Datatype memory variable nr_units of type int_array. */
	double_array * current_price;	/**< Datatype memory variable current_price of type double_array. */
	double_array * best_ask_price;	/**< Datatype memory variable best_ask_price of type double_array. */
	double_array * best_bid_price;	/**< Datatype memory variable best_bid_price of type double_array. */
};

/** \struct Asset_array
 * \brief Dynamic array to hold Assets
 */
struct Asset_array
{
	int size;
	int total_size;
	
	struct Asset ** array;
};

/** \var typedef Asset Asset
 * \brief Typedef for Asset struct.
 */
typedef struct Asset Asset;
/** \var typedef Asset_array Asset_array
 * \brief Typedef for Asset_array struct.
 */
typedef struct Asset_array Asset_array;
/** \struct AssetPortfolio
 * \brief Assetportfolio structs are used by the Household.
 *
 * Assetportfolio structs are used by the Household.
 */
struct AssetPortfolio
{
	double_array * performance_history;	/**< Datatype memory variable performance_history of type double_array. */
	Asset * firm_stocks;	/**< Datatype memory variable firm_stocks of type Asset. */
	Asset * firm_bonds;	/**< Datatype memory variable firm_bonds of type Asset. */
	Asset * gov_bonds;	/**< Datatype memory variable gov_bonds of type Asset. */
};

/** \struct AssetPortfolio_array
 * \brief Dynamic array to hold AssetPortfolios
 */
struct AssetPortfolio_array
{
	int size;
	int total_size;
	
	struct AssetPortfolio ** array;
};

/** \var typedef AssetPortfolio AssetPortfolio
 * \brief Typedef for AssetPortfolio struct.
 */
typedef struct AssetPortfolio AssetPortfolio;
/** \var typedef AssetPortfolio_array AssetPortfolio_array
 * \brief Typedef for AssetPortfolio_array struct.
 */
typedef struct AssetPortfolio_array AssetPortfolio_array;

/** \struct xmachine_memory_Household
 * \brief Holds memory of xmachine Household.
 */
struct xmachine_memory_Household
{
	int id;	/**< X-machine memory variable id of type int. */
	PrivateClassifierSystem * privateclassifiersystem;	/**< X-machine memory variable privateclassifiersystem of type PrivateClassifierSystem. */
	AssetPortfolio * current_assetportfolio;	/**< X-machine memory variable current_assetportfolio of type AssetPortfolio. */
	AssetPortfolio * prescribed_assetportfolio;	/**< X-machine memory variable prescribed_assetportfolio of type AssetPortfolio. */
	double asset_budget;	/**< X-machine memory variable asset_budget of type double. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Firm
 * \brief Holds memory of xmachine Firm.
 */
struct xmachine_memory_Firm
{
	int id;	/**< X-machine memory variable id of type int. */
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
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Bank
 * \brief Holds memory of xmachine Bank.
 */
struct xmachine_memory_Bank
{
	int id;	/**< X-machine memory variable id of type int. */
	double ra;	/**< X-machine memory variable ra of type double. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_ClearingHouse
 * \brief Holds memory of xmachine ClearingHouse.
 */
struct xmachine_memory_ClearingHouse
{
	int id;	/**< X-machine memory variable id of type int. */
	double rg;	/**< X-machine memory variable rg of type double. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_LimitOrderBook
 * \brief Holds memory of xmachine LimitOrderBook.
 */
struct xmachine_memory_LimitOrderBook
{
	int id;	/**< X-machine memory variable id of type int. */
	double re;	/**< X-machine memory variable re of type double. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Government
 * \brief Holds memory of xmachine Government.
 */
struct xmachine_memory_Government
{
	int id;	/**< X-machine memory variable id of type int. */
	double rj;	/**< X-machine memory variable rj of type double. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_FinancialAgent
 * \brief Holds memory of xmachine FinancialAgent.
 */
struct xmachine_memory_FinancialAgent
{
	int id;	/**< X-machine memory variable id of type int. */
	PublicClassifierSystem * publicclassifiersystem;	/**< X-machine memory variable publicclassifiersystem of type PublicClassifierSystem. */
	double range;	/**< X-machine memory variable range of type double. */
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
	struct xmachine_memory_ClearingHouse * xmachine_ClearingHouse;	/**< Pointer to X-machine memory of type ClearingHouse.  */
	struct xmachine_memory_LimitOrderBook * xmachine_LimitOrderBook;	/**< Pointer to X-machine memory of type LimitOrderBook.  */
	struct xmachine_memory_Government * xmachine_Government;	/**< Pointer to X-machine memory of type Government.  */
	struct xmachine_memory_FinancialAgent * xmachine_FinancialAgent;	/**< Pointer to X-machine memory of type FinancialAgent.  */
	
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


/** \struct xmachine_message_firm_bond_orders
 * \brief Holds message of type firm_bond_orders_message.
 */
struct xmachine_message_firm_bond_orders
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double limit_price;	/**< Message memory variable limit_price of type double. */
	double limit_quantity;	/**< Message memory variable limit_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_firm_bond_orders * next;	/**< Pointer to next message in the list. */
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
	int current_rule;	/**< Message memory variable current_rule of type int. */
	double rule_performance;	/**< Message memory variable rule_performance of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_rule_performance * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_fa_rule_performance
 * \brief Holds message of type fa_rule_performance_message.
 */
struct xmachine_message_fa_rule_performance
{
	int rule;	/**< Message memory variable rule of type int. */
	double rule_performance;	/**< Message memory variable rule_performance of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_fa_rule_performance * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_ruledetailsystem
 * \brief Holds message of type ruledetailsystem_message.
 */
struct xmachine_message_ruledetailsystem
{
	double2D_array * parameters;	/**< Message memory variable parameters of type double2D_array. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_ruledetailsystem * next;	/**< Pointer to next message in the list. */
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
/** \var typedef xmachine_memory_ClearingHouse xmachine_memory_ClearingHouse
 * \brief Typedef for xmachine_memory_ClearingHouse struct.
 */
typedef struct xmachine_memory_ClearingHouse xmachine_memory_ClearingHouse;
/** \var typedef xmachine_memory_LimitOrderBook xmachine_memory_LimitOrderBook
 * \brief Typedef for xmachine_memory_LimitOrderBook struct.
 */
typedef struct xmachine_memory_LimitOrderBook xmachine_memory_LimitOrderBook;
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government xmachine_memory_Government;
/** \var typedef xmachine_memory_FinancialAgent xmachine_memory_FinancialAgent
 * \brief Typedef for xmachine_memory_FinancialAgent struct.
 */
typedef struct xmachine_memory_FinancialAgent xmachine_memory_FinancialAgent;
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

/** \typedef xmachine_message_firm_bond_orders xmachine_message_firm_bond_orders
 * \brief Typedef for xmachine_message_firm_bond_orders struct.
 */
typedef struct xmachine_message_firm_bond_orders xmachine_message_firm_bond_orders;

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

/** \typedef xmachine_message_fa_rule_performance xmachine_message_fa_rule_performance
 * \brief Typedef for xmachine_message_fa_rule_performance struct.
 */
typedef struct xmachine_message_fa_rule_performance xmachine_message_fa_rule_performance;

/** \typedef xmachine_message_ruledetailsystem xmachine_message_ruledetailsystem
 * \brief Typedef for xmachine_message_ruledetailsystem struct.
 */
typedef struct xmachine_message_ruledetailsystem xmachine_message_ruledetailsystem;


int HouseholdCalculateGrossIncome(void);
int HouseholdCalculateMonthlyTaxes(void);
int HouseholdCalculateNetIncome(void);
int HouseholdCalculateTotalBudget(void);
int HouseholdCalculateAssetWealth(void);
int HouseholdCalculateCashOnHands(void);
int HouseholdCalculateConsumptionBudget(void);
int HouseholdCalculateFinancialNeedsMonthly(void);
int HouseholdUpdateAssetPortfolio(void);
int HouseholdCalculateFinancialNeedsDaily(void);
int HouseholdEntryDecision(void);
int HouseholdCalculateAssetBudget(void);
int HouseholdCalculateFirmBondOrders(void);
int HouseholdCalculateGovernmentBondOrders(void);
int HouseholdCalculateFirmStockOrders(void);
int Every_period(void);
int Household_send_rule_performance_message(void);
int Household_read_all_performances_message(void);
int Household_select_rule(void);
int Household_retrieve_rule_details(void);
int Household_apply_rule(void);
int Household_read_ruledetailsystem_message(void);
int Household_update_ruledetailsystem(void);
int Household_reset_private_classifiersystem(void);
int FirmCalculateIncomeStatement(void);
int FirmCalculateFinancialPolicies(void);
int FirmCalculateFirmStockOrders(void);
int FirmCalculateFirmBondOrders(void);
int FirmUpdateOutstandingAssets(void);
int FirmApplyForBankLoan(void);
int ClearingHouseComputeTransactions(void);
int LimitOrderBookComputeTransactions(void);
int FinancialAgent_daily_reset_public_classifiersystem(void);
int FinancialAgent_read_rule_performance_message(void);
int FinancialAgent_update_classifiersystem(void);
int FinancialAgent_send_all_performances_message(void);
int Every_100_periods(void);
int FinancialAgent_apply_GA(void);
int FinancialAgent_update_ruledetailsystem(void);
int FinancialAgent_reset_public_classifiersystem(void);
int FinancialAgent_send_ruledetailsystem_message(void);

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
	struct xmachine_message_firm_bond_orders * firm_bond_orders_messages;	/**< Pointer to firm_bond_orders message list. */
	struct xmachine_message_firm_stock_order * firm_stock_order_messages;	/**< Pointer to firm_stock_order message list. */
	struct xmachine_message_gov_bond_order * gov_bond_order_messages;	/**< Pointer to gov_bond_order message list. */
	struct xmachine_message_firm_bond_transaction * firm_bond_transaction_messages;	/**< Pointer to firm_bond_transaction message list. */
	struct xmachine_message_gov_bond_transaction * gov_bond_transaction_messages;	/**< Pointer to gov_bond_transaction message list. */
	struct xmachine_message_firm_stock_transaction * firm_stock_transaction_messages;	/**< Pointer to firm_stock_transaction message list. */
	struct xmachine_message_rule_performance * rule_performance_messages;	/**< Pointer to rule_performance message list. */
	struct xmachine_message_fa_rule_performance * fa_rule_performance_messages;	/**< Pointer to fa_rule_performance message list. */
	struct xmachine_message_ruledetailsystem * ruledetailsystem_messages;	/**< Pointer to ruledetailsystem message list. */
	
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
/** \var xmachine_message_firm_bond_orders * temp_firm_bond_orders_message
* \brief Pointer to xmachine_message_firm_bond_orders to initialise linked list. */
xmachine_message_firm_bond_orders * temp_firm_bond_orders_message;
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
/** \var xmachine_message_fa_rule_performance * temp_fa_rule_performance_message
* \brief Pointer to xmachine_message_fa_rule_performance to initialise linked list. */
xmachine_message_fa_rule_performance * temp_fa_rule_performance_message;
/** \var xmachine_message_ruledetailsystem * temp_ruledetailsystem_message
* \brief Pointer to xmachine_message_ruledetailsystem to initialise linked list. */
xmachine_message_ruledetailsystem * temp_ruledetailsystem_message;
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
/** \var xmachine_message_firm_bond_orders ** p_firm_bond_orders_message
* \brief Pointer to first pointer of firm_bond_orders message list */
xmachine_message_firm_bond_orders ** p_firm_bond_orders_message;
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
/** \var xmachine_message_fa_rule_performance ** p_fa_rule_performance_message
* \brief Pointer to first pointer of fa_rule_performance message list */
xmachine_message_fa_rule_performance ** p_fa_rule_performance_message;
/** \var xmachine_message_ruledetailsystem ** p_ruledetailsystem_message
* \brief Pointer to first pointer of ruledetailsystem message list */
xmachine_message_ruledetailsystem ** p_ruledetailsystem_message;

/** \var xmachine_message_WagePayment * WagePayment_message
* \brief Pointer to message struct for looping through WagePayment message list */
xmachine_message_WagePayment * WagePayment_message;
/** \var xmachine_message_DividendPayment * DividendPayment_message
* \brief Pointer to message struct for looping through DividendPayment message list */
xmachine_message_DividendPayment * DividendPayment_message;
/** \var xmachine_message_BondCouponPayment * BondCouponPayment_message
* \brief Pointer to message struct for looping through BondCouponPayment message list */
xmachine_message_BondCouponPayment * BondCouponPayment_message;
/** \var xmachine_message_firm_bond_orders * firm_bond_orders_message
* \brief Pointer to message struct for looping through firm_bond_orders message list */
xmachine_message_firm_bond_orders * firm_bond_orders_message;
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
/** \var xmachine_message_fa_rule_performance * fa_rule_performance_message
* \brief Pointer to message struct for looping through fa_rule_performance message list */
xmachine_message_fa_rule_performance * fa_rule_performance_message;
/** \var xmachine_message_ruledetailsystem * ruledetailsystem_message
* \brief Pointer to message struct for looping through ruledetailsystem message list */
xmachine_message_ruledetailsystem * ruledetailsystem_message;
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

string_array * init_string_array();
void reset_string_array(string_array * array);
void free_string_array(string_array * array);
void copy_string_array(string_array * from, string_array * to);
void add_string(string_array * array, char_array * stringname);
void remove_string(string_array * array, int index);

stringlist_array * init_stringlist_array();
void reset_stringlist_array(stringlist_array * array);
void free_stringlist_array(stringlist_array * array);
void copy_stringlist_array(stringlist_array * from, stringlist_array * to);
void add_stringlist(stringlist_array * array, string_array * stringlistname);
void remove_stringlist(stringlist_array * array, int index);

word_array * init_word_array();
void reset_word_array(word_array * array);
void free_word_array(word_array * array);
void copy_word_array(word_array * from, word_array * to);
void add_word(word_array * array, char_array * wordname);
void remove_word(word_array * array, int index);

wordlist_array * init_wordlist_array();
void reset_wordlist_array(wordlist_array * array);
void free_wordlist_array(wordlist_array * array);
void copy_wordlist_array(wordlist_array * from, wordlist_array * to);
void add_wordlist(wordlist_array * array, word_array * wordlistname);
void remove_wordlist(wordlist_array * array, int index);

int2D_array * init_int2D_array();
void reset_int2D_array(int2D_array * array);
void free_int2D_array(int2D_array * array);
void copy_int2D_array(int2D_array * from, int2D_array * to);
void add_int2D(int2D_array * array, int_array * int2Dname);
void remove_int2D(int2D_array * array, int index);

double2D_array * init_double2D_array();
void reset_double2D_array(double2D_array * array);
void free_double2D_array(double2D_array * array);
void copy_double2D_array(double2D_array * from, double2D_array * to);
void add_double2D(double2D_array * array, double_array * double2Dname);
void remove_double2D(double2D_array * array, int index);

RuleDetailSystem_array * init_RuleDetailSystem_array();
void reset_RuleDetailSystem_array(RuleDetailSystem_array * array);
void free_RuleDetailSystem_array(RuleDetailSystem_array * array);
void copy_RuleDetailSystem_array(RuleDetailSystem_array * from, RuleDetailSystem_array * to);
void add_RuleDetailSystem(RuleDetailSystem_array * array, int_array * nr_params_per_type, int_array * nr_params, double2D_array * parameters, wordlist * myfunctionnames);
void remove_RuleDetailSystem(RuleDetailSystem_array * array, int index);

PublicClassifierSystem_array * init_PublicClassifierSystem_array();
void reset_PublicClassifierSystem_array(PublicClassifierSystem_array * array);
void free_PublicClassifierSystem_array(PublicClassifierSystem_array * array);
void copy_PublicClassifierSystem_array(PublicClassifierSystem_array * from, PublicClassifierSystem_array * to);
void add_PublicClassifierSystem(PublicClassifierSystem_array * array, int nr_types, int_array * nr_rules_per_type, int nr_rules, int_array * ids, int_array * rule_type, int_array * counter, double_array * performance, double_array * avgperformance);
void remove_PublicClassifierSystem(PublicClassifierSystem_array * array, int index);

PrivateClassifierSystem_array * init_PrivateClassifierSystem_array();
void reset_PrivateClassifierSystem_array(PrivateClassifierSystem_array * array);
void free_PrivateClassifierSystem_array(PrivateClassifierSystem_array * array);
void copy_PrivateClassifierSystem_array(PrivateClassifierSystem_array * from, PrivateClassifierSystem_array * to);
void add_PrivateClassifierSystem(PrivateClassifierSystem_array * array, int nr_types, int_array * nr_rules_per_type, int nr_rules, int_array * ids, int_array * rule_type, double EWA_rho, double EWA_phi, double EWA_delta, double EWA_beta, int experience, int current_rule, double my_performance, double_array * avgperformance, double_array * attraction, double_array * choiceprob);
void remove_PrivateClassifierSystem(PrivateClassifierSystem_array * array, int index);

StockDataType_array * init_StockDataType_array();
void reset_StockDataType_array(StockDataType_array * array);
void free_StockDataType_array(StockDataType_array * array);
void copy_StockDataType_array(StockDataType_array * from, StockDataType_array * to);
void add_StockDataType(StockDataType_array * array, char * class, int * id, int_array * NrOutStandingShares, double price, int Book_intraday_transaction, int_array * dividends);
void remove_StockDataType(StockDataType_array * array, int index);

BondDataType_array * init_BondDataType_array();
void reset_BondDataType_array(BondDataType_array * array);
void free_BondDataType_array(BondDataType_array * array);
void copy_BondDataType_array(BondDataType_array * from, BondDataType_array * to);
void add_BondDataType(BondDataType_array * array, char * class, int * id);
void remove_BondDataType(BondDataType_array * array, int index);

DBFinancialAssets_array * init_DBFinancialAssets_array();
void reset_DBFinancialAssets_array(DBFinancialAssets_array * array);
void free_DBFinancialAssets_array(DBFinancialAssets_array * array);
void copy_DBFinancialAssets_array(DBFinancialAssets_array * from, DBFinancialAssets_array * to);
void add_DBFinancialAssets(DBFinancialAssets_array * array);
void remove_DBFinancialAssets(DBFinancialAssets_array * array, int index);

Asset_array * init_Asset_array();
void reset_Asset_array(Asset_array * array);
void free_Asset_array(Asset_array * array);
void copy_Asset_array(Asset_array * from, Asset_array * to);
void add_Asset(Asset_array * array, int_array * ids, int_array * nr_units, double_array * current_price, double_array * best_ask_price, double_array * best_bid_price);
void remove_Asset(Asset_array * array, int index);

AssetPortfolio_array * init_AssetPortfolio_array();
void reset_AssetPortfolio_array(AssetPortfolio_array * array);
void free_AssetPortfolio_array(AssetPortfolio_array * array);
void copy_AssetPortfolio_array(AssetPortfolio_array * from, AssetPortfolio_array * to);
void add_AssetPortfolio(AssetPortfolio_array * array, double_array * performance_history, Asset * firm_stocks, Asset * firm_bonds, Asset * gov_bonds);
void remove_AssetPortfolio(AssetPortfolio_array * array, int index);


int_array * init_int_array(void);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void copy_int_array(int_array * from, int_array * to);
void sort_int_array(int_array * array);
int quicksort_int(int * array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
float_array * init_float_array(void);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void copy_float_array(float_array * from, float_array * to);
void sort_float_array(float_array * array);
int quicksort_float(float * array, int elements);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
double_array * init_double_array(void);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void copy_double_array(double_array * from, double_array * to);
void sort_double_array(double_array * array);
int quicksort_double(double * array, int elements);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
char_array * init_char_array(void);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void copy_char_array(char_array * from, char_array * to);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
/* xml.c */
void read_int_static_array(char * buffer, int * j, int * int_static_array, int size);
void read_float_static_array(char * buffer, int * j, float * float_static_array, int size);
void read_double_static_array(char * buffer, int * j, double * double_static_array, int size);
void read_char_static_array(char * buffer, int * j, char * char_static_array, int size);
void read_int_dynamic_array(char * buffer, int * j, int_array * int_dynamic_array);
void read_float_dynamic_array(char * buffer, int * j, float_array * float_dynamic_array);
void read_double_dynamic_array(char * buffer, int * j, double_array * double_dynamic_array);
void read_char_dynamic_array(char * buffer, int * j, char_array * char_dynamic_array);

string * init_string();
string ** init_string_static_array(int size);
void read_string(char * buffer, int * j, string * temp_datatype);
void read_string_dynamic_array(char * buffer, int * j, string_array * temp_datatype_array);
void read_string_static_array(char * buffer, int * j, string ** temp_datatype_array, int size);
void write_string(FILE *file, string * temp_datatype);
void write_string_static_array(FILE *file, string ** temp_datatype, int size);
void write_string_dynamic_array(FILE *file, string_array * temp_datatype);
stringlist * init_stringlist();
stringlist ** init_stringlist_static_array(int size);
void read_stringlist(char * buffer, int * j, stringlist * temp_datatype);
void read_stringlist_dynamic_array(char * buffer, int * j, stringlist_array * temp_datatype_array);
void read_stringlist_static_array(char * buffer, int * j, stringlist ** temp_datatype_array, int size);
void write_stringlist(FILE *file, stringlist * temp_datatype);
void write_stringlist_static_array(FILE *file, stringlist ** temp_datatype, int size);
void write_stringlist_dynamic_array(FILE *file, stringlist_array * temp_datatype);
word * init_word();
word ** init_word_static_array(int size);
void read_word(char * buffer, int * j, word * temp_datatype);
void read_word_dynamic_array(char * buffer, int * j, word_array * temp_datatype_array);
void read_word_static_array(char * buffer, int * j, word ** temp_datatype_array, int size);
void write_word(FILE *file, word * temp_datatype);
void write_word_static_array(FILE *file, word ** temp_datatype, int size);
void write_word_dynamic_array(FILE *file, word_array * temp_datatype);
wordlist * init_wordlist();
wordlist ** init_wordlist_static_array(int size);
void read_wordlist(char * buffer, int * j, wordlist * temp_datatype);
void read_wordlist_dynamic_array(char * buffer, int * j, wordlist_array * temp_datatype_array);
void read_wordlist_static_array(char * buffer, int * j, wordlist ** temp_datatype_array, int size);
void write_wordlist(FILE *file, wordlist * temp_datatype);
void write_wordlist_static_array(FILE *file, wordlist ** temp_datatype, int size);
void write_wordlist_dynamic_array(FILE *file, wordlist_array * temp_datatype);
int2D * init_int2D();
int2D ** init_int2D_static_array(int size);
void read_int2D(char * buffer, int * j, int2D * temp_datatype);
void read_int2D_dynamic_array(char * buffer, int * j, int2D_array * temp_datatype_array);
void read_int2D_static_array(char * buffer, int * j, int2D ** temp_datatype_array, int size);
void write_int2D(FILE *file, int2D * temp_datatype);
void write_int2D_static_array(FILE *file, int2D ** temp_datatype, int size);
void write_int2D_dynamic_array(FILE *file, int2D_array * temp_datatype);
double2D * init_double2D();
double2D ** init_double2D_static_array(int size);
void read_double2D(char * buffer, int * j, double2D * temp_datatype);
void read_double2D_dynamic_array(char * buffer, int * j, double2D_array * temp_datatype_array);
void read_double2D_static_array(char * buffer, int * j, double2D ** temp_datatype_array, int size);
void write_double2D(FILE *file, double2D * temp_datatype);
void write_double2D_static_array(FILE *file, double2D ** temp_datatype, int size);
void write_double2D_dynamic_array(FILE *file, double2D_array * temp_datatype);
RuleDetailSystem * init_RuleDetailSystem();
RuleDetailSystem ** init_RuleDetailSystem_static_array(int size);
void read_RuleDetailSystem(char * buffer, int * j, RuleDetailSystem * temp_datatype);
void read_RuleDetailSystem_dynamic_array(char * buffer, int * j, RuleDetailSystem_array * temp_datatype_array);
void read_RuleDetailSystem_static_array(char * buffer, int * j, RuleDetailSystem ** temp_datatype_array, int size);
void write_RuleDetailSystem(FILE *file, RuleDetailSystem * temp_datatype);
void write_RuleDetailSystem_static_array(FILE *file, RuleDetailSystem ** temp_datatype, int size);
void write_RuleDetailSystem_dynamic_array(FILE *file, RuleDetailSystem_array * temp_datatype);
PublicClassifierSystem * init_PublicClassifierSystem();
PublicClassifierSystem ** init_PublicClassifierSystem_static_array(int size);
void read_PublicClassifierSystem(char * buffer, int * j, PublicClassifierSystem * temp_datatype);
void read_PublicClassifierSystem_dynamic_array(char * buffer, int * j, PublicClassifierSystem_array * temp_datatype_array);
void read_PublicClassifierSystem_static_array(char * buffer, int * j, PublicClassifierSystem ** temp_datatype_array, int size);
void write_PublicClassifierSystem(FILE *file, PublicClassifierSystem * temp_datatype);
void write_PublicClassifierSystem_static_array(FILE *file, PublicClassifierSystem ** temp_datatype, int size);
void write_PublicClassifierSystem_dynamic_array(FILE *file, PublicClassifierSystem_array * temp_datatype);
PrivateClassifierSystem * init_PrivateClassifierSystem();
PrivateClassifierSystem ** init_PrivateClassifierSystem_static_array(int size);
void read_PrivateClassifierSystem(char * buffer, int * j, PrivateClassifierSystem * temp_datatype);
void read_PrivateClassifierSystem_dynamic_array(char * buffer, int * j, PrivateClassifierSystem_array * temp_datatype_array);
void read_PrivateClassifierSystem_static_array(char * buffer, int * j, PrivateClassifierSystem ** temp_datatype_array, int size);
void write_PrivateClassifierSystem(FILE *file, PrivateClassifierSystem * temp_datatype);
void write_PrivateClassifierSystem_static_array(FILE *file, PrivateClassifierSystem ** temp_datatype, int size);
void write_PrivateClassifierSystem_dynamic_array(FILE *file, PrivateClassifierSystem_array * temp_datatype);
StockDataType * init_StockDataType();
StockDataType ** init_StockDataType_static_array(int size);
void read_StockDataType(char * buffer, int * j, StockDataType * temp_datatype);
void read_StockDataType_dynamic_array(char * buffer, int * j, StockDataType_array * temp_datatype_array);
void read_StockDataType_static_array(char * buffer, int * j, StockDataType ** temp_datatype_array, int size);
void write_StockDataType(FILE *file, StockDataType * temp_datatype);
void write_StockDataType_static_array(FILE *file, StockDataType ** temp_datatype, int size);
void write_StockDataType_dynamic_array(FILE *file, StockDataType_array * temp_datatype);
BondDataType * init_BondDataType();
BondDataType ** init_BondDataType_static_array(int size);
void read_BondDataType(char * buffer, int * j, BondDataType * temp_datatype);
void read_BondDataType_dynamic_array(char * buffer, int * j, BondDataType_array * temp_datatype_array);
void read_BondDataType_static_array(char * buffer, int * j, BondDataType ** temp_datatype_array, int size);
void write_BondDataType(FILE *file, BondDataType * temp_datatype);
void write_BondDataType_static_array(FILE *file, BondDataType ** temp_datatype, int size);
void write_BondDataType_dynamic_array(FILE *file, BondDataType_array * temp_datatype);
DBFinancialAssets * init_DBFinancialAssets();
DBFinancialAssets ** init_DBFinancialAssets_static_array(int size);
void read_DBFinancialAssets(char * buffer, int * j, DBFinancialAssets * temp_datatype);
void read_DBFinancialAssets_dynamic_array(char * buffer, int * j, DBFinancialAssets_array * temp_datatype_array);
void read_DBFinancialAssets_static_array(char * buffer, int * j, DBFinancialAssets ** temp_datatype_array, int size);
void write_DBFinancialAssets(FILE *file, DBFinancialAssets * temp_datatype);
void write_DBFinancialAssets_static_array(FILE *file, DBFinancialAssets ** temp_datatype, int size);
void write_DBFinancialAssets_dynamic_array(FILE *file, DBFinancialAssets_array * temp_datatype);
Asset * init_Asset();
Asset ** init_Asset_static_array(int size);
void read_Asset(char * buffer, int * j, Asset * temp_datatype);
void read_Asset_dynamic_array(char * buffer, int * j, Asset_array * temp_datatype_array);
void read_Asset_static_array(char * buffer, int * j, Asset ** temp_datatype_array, int size);
void write_Asset(FILE *file, Asset * temp_datatype);
void write_Asset_static_array(FILE *file, Asset ** temp_datatype, int size);
void write_Asset_dynamic_array(FILE *file, Asset_array * temp_datatype);
AssetPortfolio * init_AssetPortfolio();
AssetPortfolio ** init_AssetPortfolio_static_array(int size);
void read_AssetPortfolio(char * buffer, int * j, AssetPortfolio * temp_datatype);
void read_AssetPortfolio_dynamic_array(char * buffer, int * j, AssetPortfolio_array * temp_datatype_array);
void read_AssetPortfolio_static_array(char * buffer, int * j, AssetPortfolio ** temp_datatype_array, int size);
void write_AssetPortfolio(FILE *file, AssetPortfolio * temp_datatype);
void write_AssetPortfolio_static_array(FILE *file, AssetPortfolio ** temp_datatype, int size);
void write_AssetPortfolio_dynamic_array(FILE *file, AssetPortfolio_array * temp_datatype);
void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], 
                       int partition_method, int flag);
void saveiterationdata_binary(int iteration_number);
void saveiterationdata(int iteration_number);

void free_string_static_array(string ** temp, int size);
void free_string_datatype(string * temp);
void copy_string_datatype(string * from, string * to);
void copy_string_static_array(string ** from, string ** to, int size);
void free_stringlist_static_array(stringlist ** temp, int size);
void free_stringlist_datatype(stringlist * temp);
void copy_stringlist_datatype(stringlist * from, stringlist * to);
void copy_stringlist_static_array(stringlist ** from, stringlist ** to, int size);
void free_word_static_array(word ** temp, int size);
void free_word_datatype(word * temp);
void copy_word_datatype(word * from, word * to);
void copy_word_static_array(word ** from, word ** to, int size);
void free_wordlist_static_array(wordlist ** temp, int size);
void free_wordlist_datatype(wordlist * temp);
void copy_wordlist_datatype(wordlist * from, wordlist * to);
void copy_wordlist_static_array(wordlist ** from, wordlist ** to, int size);
void free_int2D_static_array(int2D ** temp, int size);
void free_int2D_datatype(int2D * temp);
void copy_int2D_datatype(int2D * from, int2D * to);
void copy_int2D_static_array(int2D ** from, int2D ** to, int size);
void free_double2D_static_array(double2D ** temp, int size);
void free_double2D_datatype(double2D * temp);
void copy_double2D_datatype(double2D * from, double2D * to);
void copy_double2D_static_array(double2D ** from, double2D ** to, int size);
void free_RuleDetailSystem_static_array(RuleDetailSystem ** temp, int size);
void free_RuleDetailSystem_datatype(RuleDetailSystem * temp);
void copy_RuleDetailSystem_datatype(RuleDetailSystem * from, RuleDetailSystem * to);
void copy_RuleDetailSystem_static_array(RuleDetailSystem ** from, RuleDetailSystem ** to, int size);
void free_PublicClassifierSystem_static_array(PublicClassifierSystem ** temp, int size);
void free_PublicClassifierSystem_datatype(PublicClassifierSystem * temp);
void copy_PublicClassifierSystem_datatype(PublicClassifierSystem * from, PublicClassifierSystem * to);
void copy_PublicClassifierSystem_static_array(PublicClassifierSystem ** from, PublicClassifierSystem ** to, int size);
void free_PrivateClassifierSystem_static_array(PrivateClassifierSystem ** temp, int size);
void free_PrivateClassifierSystem_datatype(PrivateClassifierSystem * temp);
void copy_PrivateClassifierSystem_datatype(PrivateClassifierSystem * from, PrivateClassifierSystem * to);
void copy_PrivateClassifierSystem_static_array(PrivateClassifierSystem ** from, PrivateClassifierSystem ** to, int size);
void free_StockDataType_static_array(StockDataType ** temp, int size);
void free_StockDataType_datatype(StockDataType * temp);
void copy_StockDataType_datatype(StockDataType * from, StockDataType * to);
void copy_StockDataType_static_array(StockDataType ** from, StockDataType ** to, int size);
void free_BondDataType_static_array(BondDataType ** temp, int size);
void free_BondDataType_datatype(BondDataType * temp);
void copy_BondDataType_datatype(BondDataType * from, BondDataType * to);
void copy_BondDataType_static_array(BondDataType ** from, BondDataType ** to, int size);
void free_DBFinancialAssets_static_array(DBFinancialAssets ** temp, int size);
void free_DBFinancialAssets_datatype(DBFinancialAssets * temp);
void copy_DBFinancialAssets_datatype(DBFinancialAssets * from, DBFinancialAssets * to);
void copy_DBFinancialAssets_static_array(DBFinancialAssets ** from, DBFinancialAssets ** to, int size);
void free_Asset_static_array(Asset ** temp, int size);
void free_Asset_datatype(Asset * temp);
void copy_Asset_datatype(Asset * from, Asset * to);
void copy_Asset_static_array(Asset ** from, Asset ** to, int size);
void free_AssetPortfolio_static_array(AssetPortfolio ** temp, int size);
void free_AssetPortfolio_datatype(AssetPortfolio * temp);
void copy_AssetPortfolio_datatype(AssetPortfolio * from, AssetPortfolio * to);
void copy_AssetPortfolio_static_array(AssetPortfolio ** from, AssetPortfolio ** to, int size);

xmachine_memory_Household * init_Household_agent();
void add_Household_agent_internal(xmachine_memory_Household * current);
void add_Household_agent(int id, PrivateClassifierSystem * privateclassifiersystem, AssetPortfolio * current_assetportfolio, AssetPortfolio * prescribed_assetportfolio, double asset_budget, double range, double posx, double posy);
xmachine_memory_Firm * init_Firm_agent();
void add_Firm_agent_internal(xmachine_memory_Firm * current);
void add_Firm_agent(int id, double_array * revenues, double_array * sales_costs, double total_revenue, double net_revenue, double operational_cost, double total_wage_payments, double total_input_payments, double interest_payments, double total_earnings, double tax_rate_profits, double pretax_profit, double tax_provision, double net_earnings, double div_payments, double retained_earnings, double current_debt, double debt_interest_rate, double debt_repayments, double share_repurchase_value, int share_repurchase_units, int target_total_shares, int current_total_shares, double total_financial_needs, double financial_needs, double add_financial_needs, double financial_reserves, double target_loans, double target_equity, double bonds_issue_target, double stocks_issue_target, double price, double max_debt, double div_earn_ratio, double debt_earn_ratio, double div_pshare_ratio, double earn_pshare_ratio, double price_earn_ratio, double retained_earn_ratio, double earn_pshare_ratio_growth, double critical_price_earn_ratio, double critical_earn_pshare_ratio, double range, double posx, double posy);
xmachine_memory_Bank * init_Bank_agent();
void add_Bank_agent_internal(xmachine_memory_Bank * current);
void add_Bank_agent(int id, double ra, double range, double posx, double posy);
xmachine_memory_ClearingHouse * init_ClearingHouse_agent();
void add_ClearingHouse_agent_internal(xmachine_memory_ClearingHouse * current);
void add_ClearingHouse_agent(int id, double rg, double range, double posx, double posy);
xmachine_memory_LimitOrderBook * init_LimitOrderBook_agent();
void add_LimitOrderBook_agent_internal(xmachine_memory_LimitOrderBook * current);
void add_LimitOrderBook_agent(int id, double re, double range, double posx, double posy);
xmachine_memory_Government * init_Government_agent();
void add_Government_agent_internal(xmachine_memory_Government * current);
void add_Government_agent(int id, double rj, double range, double posx, double posy);
xmachine_memory_FinancialAgent * init_FinancialAgent_agent();
void add_FinancialAgent_agent_internal(xmachine_memory_FinancialAgent * current);
void add_FinancialAgent_agent(int id, PublicClassifierSystem * publicclassifiersystem, double range, double posx, double posy);

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
void add_firm_bond_orders_message(int household_id, int firm_id, double limit_price, double limit_quantity, double range, double x, double y, double z);
xmachine_message_firm_bond_orders * add_firm_bond_orders_message_internal(void);
xmachine_message_firm_bond_orders * get_first_firm_bond_orders_message(void);
xmachine_message_firm_bond_orders * get_next_firm_bond_orders_message(xmachine_message_firm_bond_orders * current);
void freefirm_bond_ordersmessages(void);
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
void add_rule_performance_message(int current_rule, double rule_performance, double range, double x, double y, double z);
xmachine_message_rule_performance * add_rule_performance_message_internal(void);
xmachine_message_rule_performance * get_first_rule_performance_message(void);
xmachine_message_rule_performance * get_next_rule_performance_message(xmachine_message_rule_performance * current);
void freerule_performancemessages(void);
void add_fa_rule_performance_message(int rule, double rule_performance, double range, double x, double y, double z);
xmachine_message_fa_rule_performance * add_fa_rule_performance_message_internal(void);
xmachine_message_fa_rule_performance * get_first_fa_rule_performance_message(void);
xmachine_message_fa_rule_performance * get_next_fa_rule_performance_message(xmachine_message_fa_rule_performance * current);
void freefa_rule_performancemessages(void);
void add_ruledetailsystem_message(double2D_array * parameters, double range, double x, double y, double z);
xmachine_message_ruledetailsystem * add_ruledetailsystem_message_internal(void);
xmachine_message_ruledetailsystem * get_first_ruledetailsystem_message(void);
xmachine_message_ruledetailsystem * get_next_ruledetailsystem_message(xmachine_message_ruledetailsystem * current);
void freeruledetailsystemmessages(void);

void set_id(int id);
int get_id(void);
PrivateClassifierSystem * get_privateclassifiersystem(void);
AssetPortfolio * get_current_assetportfolio(void);
AssetPortfolio * get_prescribed_assetportfolio(void);
void set_asset_budget(double asset_budget);
double get_asset_budget(void);
void set_range(double range);
double get_range(void);
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
void set_ra(double ra);
double get_ra(void);
void set_rg(double rg);
double get_rg(void);
void set_re(double re);
double get_re(void);
void set_rj(double rj);
double get_rj(void);
PublicClassifierSystem * get_publicclassifiersystem(void);
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
xmachine_message_firm_bond_orders * get_next_message_firm_bond_orders_in_range(xmachine_message_firm_bond_orders * current);
xmachine_message_firm_stock_order * get_next_message_firm_stock_order_in_range(xmachine_message_firm_stock_order * current);
xmachine_message_gov_bond_order * get_next_message_gov_bond_order_in_range(xmachine_message_gov_bond_order * current);
xmachine_message_firm_bond_transaction * get_next_message_firm_bond_transaction_in_range(xmachine_message_firm_bond_transaction * current);
xmachine_message_gov_bond_transaction * get_next_message_gov_bond_transaction_in_range(xmachine_message_gov_bond_transaction * current);
xmachine_message_firm_stock_transaction * get_next_message_firm_stock_transaction_in_range(xmachine_message_firm_stock_transaction * current);
xmachine_message_rule_performance * get_next_message_rule_performance_in_range(xmachine_message_rule_performance * current);
xmachine_message_fa_rule_performance * get_next_message_fa_rule_performance_in_range(xmachine_message_fa_rule_performance * current);
xmachine_message_ruledetailsystem * get_next_message_ruledetailsystem_in_range(xmachine_message_ruledetailsystem * current);

/* memory.c */
xmachine * add_xmachine(void);
