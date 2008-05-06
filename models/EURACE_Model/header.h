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
#include <time.h>
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
/** \def START_WAGE_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process wage_payment messages. */
#define START_WAGE_PAYMENT_MESSAGE_LOOP  wage_payment_message = get_first_wage_payment_message(); while(wage_payment_message) {
/** \def FINISH_WAGE_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process wage_payment messages. */
#define FINISH_WAGE_PAYMENT_MESSAGE_LOOP wage_payment_message = get_next_wage_payment_message(wage_payment_message); }
/** \def START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP
 * \brief Start of loop to process quality_price_info_1 messages. */
#define START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP  quality_price_info_1_message = get_first_quality_price_info_1_message(); while(quality_price_info_1_message) {
/** \def FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP
 * \brief Finish of loop to process quality_price_info_1 messages. */
#define FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP quality_price_info_1_message = get_next_quality_price_info_1_message(quality_price_info_1_message); }
/** \def START_QUALITY_PRICE_INFO_2_MESSAGE_LOOP
 * \brief Start of loop to process quality_price_info_2 messages. */
#define START_QUALITY_PRICE_INFO_2_MESSAGE_LOOP  quality_price_info_2_message = get_first_quality_price_info_2_message(); while(quality_price_info_2_message) {
/** \def FINISH_QUALITY_PRICE_INFO_2_MESSAGE_LOOP
 * \brief Finish of loop to process quality_price_info_2 messages. */
#define FINISH_QUALITY_PRICE_INFO_2_MESSAGE_LOOP quality_price_info_2_message = get_next_quality_price_info_2_message(quality_price_info_2_message); }
/** \def START_UPDATE_MALL_STOCK_MESSAGE_LOOP
 * \brief Start of loop to process update_mall_stock messages. */
#define START_UPDATE_MALL_STOCK_MESSAGE_LOOP  update_mall_stock_message = get_first_update_mall_stock_message(); while(update_mall_stock_message) {
/** \def FINISH_UPDATE_MALL_STOCK_MESSAGE_LOOP
 * \brief Finish of loop to process update_mall_stock messages. */
#define FINISH_UPDATE_MALL_STOCK_MESSAGE_LOOP update_mall_stock_message = get_next_update_mall_stock_message(update_mall_stock_message); }
/** \def START_CONSUMPTION_REQUEST_1_MESSAGE_LOOP
 * \brief Start of loop to process consumption_request_1 messages. */
#define START_CONSUMPTION_REQUEST_1_MESSAGE_LOOP  consumption_request_1_message = get_first_consumption_request_1_message(); while(consumption_request_1_message) {
/** \def FINISH_CONSUMPTION_REQUEST_1_MESSAGE_LOOP
 * \brief Finish of loop to process consumption_request_1 messages. */
#define FINISH_CONSUMPTION_REQUEST_1_MESSAGE_LOOP consumption_request_1_message = get_next_consumption_request_1_message(consumption_request_1_message); }
/** \def START_CONSUMPTION_REQUEST_2_MESSAGE_LOOP
 * \brief Start of loop to process consumption_request_2 messages. */
#define START_CONSUMPTION_REQUEST_2_MESSAGE_LOOP  consumption_request_2_message = get_first_consumption_request_2_message(); while(consumption_request_2_message) {
/** \def FINISH_CONSUMPTION_REQUEST_2_MESSAGE_LOOP
 * \brief Finish of loop to process consumption_request_2 messages. */
#define FINISH_CONSUMPTION_REQUEST_2_MESSAGE_LOOP consumption_request_2_message = get_next_consumption_request_2_message(consumption_request_2_message); }
/** \def START_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP
 * \brief Start of loop to process accepted_consumption_1 messages. */
#define START_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP  accepted_consumption_1_message = get_first_accepted_consumption_1_message(); while(accepted_consumption_1_message) {
/** \def FINISH_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP
 * \brief Finish of loop to process accepted_consumption_1 messages. */
#define FINISH_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP accepted_consumption_1_message = get_next_accepted_consumption_1_message(accepted_consumption_1_message); }
/** \def START_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP
 * \brief Start of loop to process accepted_consumption_2 messages. */
#define START_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP  accepted_consumption_2_message = get_first_accepted_consumption_2_message(); while(accepted_consumption_2_message) {
/** \def FINISH_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP
 * \brief Finish of loop to process accepted_consumption_2 messages. */
#define FINISH_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP accepted_consumption_2_message = get_next_accepted_consumption_2_message(accepted_consumption_2_message); }
/** \def START_SALES_MESSAGE_LOOP
 * \brief Start of loop to process sales messages. */
#define START_SALES_MESSAGE_LOOP  sales_message = get_first_sales_message(); while(sales_message) {
/** \def FINISH_SALES_MESSAGE_LOOP
 * \brief Finish of loop to process sales messages. */
#define FINISH_SALES_MESSAGE_LOOP sales_message = get_next_sales_message(sales_message); }
/** \def START_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP
 * \brief Start of loop to process current_mall_stock_info messages. */
#define START_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP  current_mall_stock_info_message = get_first_current_mall_stock_info_message(); while(current_mall_stock_info_message) {
/** \def FINISH_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP
 * \brief Finish of loop to process current_mall_stock_info messages. */
#define FINISH_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP current_mall_stock_info_message = get_next_current_mall_stock_info_message(current_mall_stock_info_message); }
/** \def START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process specific_skill_update messages. */
#define START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP  specific_skill_update_message = get_first_specific_skill_update_message(); while(specific_skill_update_message) {
/** \def FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process specific_skill_update messages. */
#define FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP specific_skill_update_message = get_next_specific_skill_update_message(specific_skill_update_message); }
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
/** \def START_INTEREST_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process interest_payment messages. */
#define START_INTEREST_PAYMENT_MESSAGE_LOOP  interest_payment_message = get_first_interest_payment_message(); while(interest_payment_message) {
/** \def FINISH_INTEREST_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process interest_payment messages. */
#define FINISH_INTEREST_PAYMENT_MESSAGE_LOOP interest_payment_message = get_next_interest_payment_message(interest_payment_message); }
/** \def START_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process debt_installment_payment messages. */
#define START_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP  debt_installment_payment_message = get_first_debt_installment_payment_message(); while(debt_installment_payment_message) {
/** \def FINISH_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process debt_installment_payment messages. */
#define FINISH_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP debt_installment_payment_message = get_next_debt_installment_payment_message(debt_installment_payment_message); }
/** \def START_PRODUCTIVITY_MESSAGE_LOOP
 * \brief Start of loop to process productivity messages. */
#define START_PRODUCTIVITY_MESSAGE_LOOP  productivity_message = get_first_productivity_message(); while(productivity_message) {
/** \def FINISH_PRODUCTIVITY_MESSAGE_LOOP
 * \brief Finish of loop to process productivity messages. */
#define FINISH_PRODUCTIVITY_MESSAGE_LOOP productivity_message = get_next_productivity_message(productivity_message); }
/** \def START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process capital_good_request messages. */
#define START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP  capital_good_request_message = get_first_capital_good_request_message(); while(capital_good_request_message) {
/** \def FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process capital_good_request messages. */
#define FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP capital_good_request_message = get_next_capital_good_request_message(capital_good_request_message); }
/** \def START_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP
 * \brief Start of loop to process capital_good_profit_distribution messages. */
#define START_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP  capital_good_profit_distribution_message = get_first_capital_good_profit_distribution_message(); while(capital_good_profit_distribution_message) {
/** \def FINISH_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP
 * \brief Finish of loop to process capital_good_profit_distribution messages. */
#define FINISH_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP capital_good_profit_distribution_message = get_next_capital_good_profit_distribution_message(capital_good_profit_distribution_message); }
/** \def START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
 * \brief Start of loop to process capital_good_delivery messages. */
#define START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP  capital_good_delivery_message = get_first_capital_good_delivery_message(); while(capital_good_delivery_message) {
/** \def FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
 * \brief Finish of loop to process capital_good_delivery messages. */
#define FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP capital_good_delivery_message = get_next_capital_good_delivery_message(capital_good_delivery_message); }
/** \def START_DIVIDEND_MESSAGE_LOOP
 * \brief Start of loop to process dividend messages. */
#define START_DIVIDEND_MESSAGE_LOOP  dividend_message = get_first_dividend_message(); while(dividend_message) {
/** \def FINISH_DIVIDEND_MESSAGE_LOOP
 * \brief Finish of loop to process dividend messages. */
#define FINISH_DIVIDEND_MESSAGE_LOOP dividend_message = get_next_dividend_message(dividend_message); }
/** \def START_PAY_CAPITAL_GOODS_MESSAGE_LOOP
 * \brief Start of loop to process pay_capital_goods messages. */
#define START_PAY_CAPITAL_GOODS_MESSAGE_LOOP  pay_capital_goods_message = get_first_pay_capital_goods_message(); while(pay_capital_goods_message) {
/** \def FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP
 * \brief Finish of loop to process pay_capital_goods messages. */
#define FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP pay_capital_goods_message = get_next_pay_capital_goods_message(pay_capital_goods_message); }
/** \def START_VACANCIES_MESSAGE_LOOP
 * \brief Start of loop to process vacancies messages. */
#define START_VACANCIES_MESSAGE_LOOP  vacancies_message = get_first_vacancies_message(); while(vacancies_message) {
/** \def FINISH_VACANCIES_MESSAGE_LOOP
 * \brief Finish of loop to process vacancies messages. */
#define FINISH_VACANCIES_MESSAGE_LOOP vacancies_message = get_next_vacancies_message(vacancies_message); }
/** \def START_VACANCIES2_MESSAGE_LOOP
 * \brief Start of loop to process vacancies2 messages. */
#define START_VACANCIES2_MESSAGE_LOOP  vacancies2_message = get_first_vacancies2_message(); while(vacancies2_message) {
/** \def FINISH_VACANCIES2_MESSAGE_LOOP
 * \brief Finish of loop to process vacancies2 messages. */
#define FINISH_VACANCIES2_MESSAGE_LOOP vacancies2_message = get_next_vacancies2_message(vacancies2_message); }
/** \def START_FIRING_MESSAGE_LOOP
 * \brief Start of loop to process firing messages. */
#define START_FIRING_MESSAGE_LOOP  firing_message = get_first_firing_message(); while(firing_message) {
/** \def FINISH_FIRING_MESSAGE_LOOP
 * \brief Finish of loop to process firing messages. */
#define FINISH_FIRING_MESSAGE_LOOP firing_message = get_next_firing_message(firing_message); }
/** \def START_JOB_APPLICATION_MESSAGE_LOOP
 * \brief Start of loop to process job_application messages. */
#define START_JOB_APPLICATION_MESSAGE_LOOP  job_application_message = get_first_job_application_message(); while(job_application_message) {
/** \def FINISH_JOB_APPLICATION_MESSAGE_LOOP
 * \brief Finish of loop to process job_application messages. */
#define FINISH_JOB_APPLICATION_MESSAGE_LOOP job_application_message = get_next_job_application_message(job_application_message); }
/** \def START_JOB_APPLICATION2_MESSAGE_LOOP
 * \brief Start of loop to process job_application2 messages. */
#define START_JOB_APPLICATION2_MESSAGE_LOOP  job_application2_message = get_first_job_application2_message(); while(job_application2_message) {
/** \def FINISH_JOB_APPLICATION2_MESSAGE_LOOP
 * \brief Finish of loop to process job_application2 messages. */
#define FINISH_JOB_APPLICATION2_MESSAGE_LOOP job_application2_message = get_next_job_application2_message(job_application2_message); }
/** \def START_JOB_OFFER_MESSAGE_LOOP
 * \brief Start of loop to process job_offer messages. */
#define START_JOB_OFFER_MESSAGE_LOOP  job_offer_message = get_first_job_offer_message(); while(job_offer_message) {
/** \def FINISH_JOB_OFFER_MESSAGE_LOOP
 * \brief Finish of loop to process job_offer messages. */
#define FINISH_JOB_OFFER_MESSAGE_LOOP job_offer_message = get_next_job_offer_message(job_offer_message); }
/** \def START_JOB_OFFER2_MESSAGE_LOOP
 * \brief Start of loop to process job_offer2 messages. */
#define START_JOB_OFFER2_MESSAGE_LOOP  job_offer2_message = get_first_job_offer2_message(); while(job_offer2_message) {
/** \def FINISH_JOB_OFFER2_MESSAGE_LOOP
 * \brief Finish of loop to process job_offer2 messages. */
#define FINISH_JOB_OFFER2_MESSAGE_LOOP job_offer2_message = get_next_job_offer2_message(job_offer2_message); }
/** \def START_JOB_ACCEPTANCE_MESSAGE_LOOP
 * \brief Start of loop to process job_acceptance messages. */
#define START_JOB_ACCEPTANCE_MESSAGE_LOOP  job_acceptance_message = get_first_job_acceptance_message(); while(job_acceptance_message) {
/** \def FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP
 * \brief Finish of loop to process job_acceptance messages. */
#define FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP job_acceptance_message = get_next_job_acceptance_message(job_acceptance_message); }
/** \def START_JOB_ACCEPTANCE2_MESSAGE_LOOP
 * \brief Start of loop to process job_acceptance2 messages. */
#define START_JOB_ACCEPTANCE2_MESSAGE_LOOP  job_acceptance2_message = get_first_job_acceptance2_message(); while(job_acceptance2_message) {
/** \def FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP
 * \brief Finish of loop to process job_acceptance2 messages. */
#define FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP job_acceptance2_message = get_next_job_acceptance2_message(job_acceptance2_message); }
/** \def START_APPLICATION_REJECTION_MESSAGE_LOOP
 * \brief Start of loop to process application_rejection messages. */
#define START_APPLICATION_REJECTION_MESSAGE_LOOP  application_rejection_message = get_first_application_rejection_message(); while(application_rejection_message) {
/** \def FINISH_APPLICATION_REJECTION_MESSAGE_LOOP
 * \brief Finish of loop to process application_rejection messages. */
#define FINISH_APPLICATION_REJECTION_MESSAGE_LOOP application_rejection_message = get_next_application_rejection_message(application_rejection_message); }
/** \def START_APPLICATION_REJECTION2_MESSAGE_LOOP
 * \brief Start of loop to process application_rejection2 messages. */
#define START_APPLICATION_REJECTION2_MESSAGE_LOOP  application_rejection2_message = get_first_application_rejection2_message(); while(application_rejection2_message) {
/** \def FINISH_APPLICATION_REJECTION2_MESSAGE_LOOP
 * \brief Finish of loop to process application_rejection2 messages. */
#define FINISH_APPLICATION_REJECTION2_MESSAGE_LOOP application_rejection2_message = get_next_application_rejection2_message(application_rejection2_message); }
/** \def START_QUITTING_MESSAGE_LOOP
 * \brief Start of loop to process quitting messages. */
#define START_QUITTING_MESSAGE_LOOP  quitting_message = get_first_quitting_message(); while(quitting_message) {
/** \def FINISH_QUITTING_MESSAGE_LOOP
 * \brief Finish of loop to process quitting messages. */
#define FINISH_QUITTING_MESSAGE_LOOP quitting_message = get_next_quitting_message(quitting_message); }
/** \def START_QUITTING2_MESSAGE_LOOP
 * \brief Start of loop to process quitting2 messages. */
#define START_QUITTING2_MESSAGE_LOOP  quitting2_message = get_first_quitting2_message(); while(quitting2_message) {
/** \def FINISH_QUITTING2_MESSAGE_LOOP
 * \brief Finish of loop to process quitting2 messages. */
#define FINISH_QUITTING2_MESSAGE_LOOP quitting2_message = get_next_quitting2_message(quitting2_message); }
/** \def START_FIRM_SEND_DATA_MESSAGE_LOOP
 * \brief Start of loop to process firm_send_data messages. */
#define START_FIRM_SEND_DATA_MESSAGE_LOOP  firm_send_data_message = get_first_firm_send_data_message(); while(firm_send_data_message) {
/** \def FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
 * \brief Finish of loop to process firm_send_data messages. */
#define FINISH_FIRM_SEND_DATA_MESSAGE_LOOP firm_send_data_message = get_next_firm_send_data_message(firm_send_data_message); }
/** \def START_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP
 * \brief Start of loop to process household_send_data messages. */
#define START_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP  household_send_data_message = get_first_household_send_data_message(); while(household_send_data_message) {
/** \def FINISH_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP
 * \brief Finish of loop to process household_send_data messages. */
#define FINISH_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP household_send_data_message = get_next_household_send_data_message(household_send_data_message); }
/** \def START_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
 * \brief Start of loop to process market_research_send_specific_skills messages. */
#define START_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP  market_research_send_specific_skills_message = get_first_market_research_send_specific_skills_message(); while(market_research_send_specific_skills_message) {
/** \def FINISH_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
 * \brief Finish of loop to process market_research_send_specific_skills messages. */
#define FINISH_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP market_research_send_specific_skills_message = get_next_market_research_send_specific_skills_message(market_research_send_specific_skills_message); }
/** \def START_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process tax_payment messages. */
#define START_TAX_PAYMENT_MESSAGE_LOOP  tax_payment_message = get_first_tax_payment_message(); while(tax_payment_message) {
/** \def FINISH_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process tax_payment messages. */
#define FINISH_TAX_PAYMENT_MESSAGE_LOOP tax_payment_message = get_next_tax_payment_message(tax_payment_message); }
/** \def START_DIVIDEND_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process dividend_payment messages. */
#define START_DIVIDEND_PAYMENT_MESSAGE_LOOP  dividend_payment_message = get_first_dividend_payment_message(); while(dividend_payment_message) {
/** \def FINISH_DIVIDEND_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process dividend_payment messages. */
#define FINISH_DIVIDEND_PAYMENT_MESSAGE_LOOP dividend_payment_message = get_next_dividend_payment_message(dividend_payment_message); }
/** \def START_STOCK_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process stock_order messages. */
#define START_STOCK_ORDER_MESSAGE_LOOP  stock_order_message = get_first_stock_order_message(); while(stock_order_message) {
/** \def FINISH_STOCK_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process stock_order messages. */
#define FINISH_STOCK_ORDER_MESSAGE_LOOP stock_order_message = get_next_stock_order_message(stock_order_message); }
/** \def START_STOCK_TRANSACTION_MESSAGE_LOOP
 * \brief Start of loop to process stock_transaction messages. */
#define START_STOCK_TRANSACTION_MESSAGE_LOOP  stock_transaction_message = get_first_stock_transaction_message(); while(stock_transaction_message) {
/** \def FINISH_STOCK_TRANSACTION_MESSAGE_LOOP
 * \brief Finish of loop to process stock_transaction messages. */
#define FINISH_STOCK_TRANSACTION_MESSAGE_LOOP stock_transaction_message = get_next_stock_transaction_message(stock_transaction_message); }
/** \def START_BOND_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process bond_order messages. */
#define START_BOND_ORDER_MESSAGE_LOOP  bond_order_message = get_first_bond_order_message(); while(bond_order_message) {
/** \def FINISH_BOND_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process bond_order messages. */
#define FINISH_BOND_ORDER_MESSAGE_LOOP bond_order_message = get_next_bond_order_message(bond_order_message); }
/** \def START_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Start of loop to process bond_transaction messages. */
#define START_BOND_TRANSACTION_MESSAGE_LOOP  bond_transaction_message = get_first_bond_transaction_message(); while(bond_transaction_message) {
/** \def FINISH_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Finish of loop to process bond_transaction messages. */
#define FINISH_BOND_TRANSACTION_MESSAGE_LOOP bond_transaction_message = get_next_bond_transaction_message(bond_transaction_message); }
/** \def START_GOV_BOND_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process gov_bond_order messages. */
#define START_GOV_BOND_ORDER_MESSAGE_LOOP  gov_bond_order_message = get_first_gov_bond_order_message(); while(gov_bond_order_message) {
/** \def FINISH_GOV_BOND_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process gov_bond_order messages. */
#define FINISH_GOV_BOND_ORDER_MESSAGE_LOOP gov_bond_order_message = get_next_gov_bond_order_message(gov_bond_order_message); }
/** \def START_GOV_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Start of loop to process gov_bond_transaction messages. */
#define START_GOV_BOND_TRANSACTION_MESSAGE_LOOP  gov_bond_transaction_message = get_first_gov_bond_transaction_message(); while(gov_bond_transaction_message) {
/** \def FINISH_GOV_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Finish of loop to process gov_bond_transaction messages. */
#define FINISH_GOV_BOND_TRANSACTION_MESSAGE_LOOP gov_bond_transaction_message = get_next_gov_bond_transaction_message(gov_bond_transaction_message); }

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

/** \struct portfolio
 * \brief .
 *
 * .
 */
struct portfolio
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	int shares;	/**< Datatype memory variable shares of type int. */
};

/** \struct portfolio_array
 * \brief Dynamic array to hold portfolios
 */
struct portfolio_array
{
	int size;
	int total_size;
	
	struct portfolio * array;
};

/** \var typedef portfolio portfolio
 * \brief Typedef for portfolio struct.
 */
typedef struct portfolio portfolio;
/** \var typedef portfolio_array portfolio_array
 * \brief Typedef for portfolio_array struct.
 */
typedef struct portfolio_array portfolio_array;
/** \struct consumption_goods_offer
 * \brief .
 *
 * .
 */
struct consumption_goods_offer
{
	int id;	/**< Datatype memory variable id of type int. */
	double quality;	/**< Datatype memory variable quality of type double. */
	double price;	/**< Datatype memory variable price of type double. */
};

/** \struct consumption_goods_offer_array
 * \brief Dynamic array to hold consumption_goods_offers
 */
struct consumption_goods_offer_array
{
	int size;
	int total_size;
	
	struct consumption_goods_offer * array;
};

/** \var typedef consumption_goods_offer consumption_goods_offer
 * \brief Typedef for consumption_goods_offer struct.
 */
typedef struct consumption_goods_offer consumption_goods_offer;
/** \var typedef consumption_goods_offer_array consumption_goods_offer_array
 * \brief Typedef for consumption_goods_offer_array struct.
 */
typedef struct consumption_goods_offer_array consumption_goods_offer_array;
/** \struct consumption_request
 * \brief .
 *
 * .
 */
struct consumption_request
{
	int worker_id;	/**< Datatype memory variable worker_id of type int. */
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double quantity;	/**< Datatype memory variable quantity of type double. */
};

/** \struct consumption_request_array
 * \brief Dynamic array to hold consumption_requests
 */
struct consumption_request_array
{
	int size;
	int total_size;
	
	struct consumption_request * array;
};

/** \var typedef consumption_request consumption_request
 * \brief Typedef for consumption_request struct.
 */
typedef struct consumption_request consumption_request;
/** \var typedef consumption_request_array consumption_request_array
 * \brief Typedef for consumption_request_array struct.
 */
typedef struct consumption_request_array consumption_request_array;
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
/** \struct mall_quality_price_info
 * \brief .
 *
 * .
 */
struct mall_quality_price_info
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	int mall_region_id;	/**< Datatype memory variable mall_region_id of type int. */
	double quality;	/**< Datatype memory variable quality of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	int available;	/**< Datatype memory variable available of type int. */
};

/** \struct mall_quality_price_info_array
 * \brief Dynamic array to hold mall_quality_price_infos
 */
struct mall_quality_price_info_array
{
	int size;
	int total_size;
	
	struct mall_quality_price_info * array;
};

/** \var typedef mall_quality_price_info mall_quality_price_info
 * \brief Typedef for mall_quality_price_info struct.
 */
typedef struct mall_quality_price_info mall_quality_price_info;
/** \var typedef mall_quality_price_info_array mall_quality_price_info_array
 * \brief Typedef for mall_quality_price_info_array struct.
 */
typedef struct mall_quality_price_info_array mall_quality_price_info_array;
/** \struct mall_stock
 * \brief .
 *
 * .
 */
struct mall_stock
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double stock;	/**< Datatype memory variable stock of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	double quality;	/**< Datatype memory variable quality of type double. */
};

/** \struct mall_stock_array
 * \brief Dynamic array to hold mall_stocks
 */
struct mall_stock_array
{
	int size;
	int total_size;
	
	struct mall_stock * array;
};

/** \var typedef mall_stock mall_stock
 * \brief Typedef for mall_stock struct.
 */
typedef struct mall_stock mall_stock;
/** \var typedef mall_stock_array mall_stock_array
 * \brief Typedef for mall_stock_array struct.
 */
typedef struct mall_stock_array mall_stock_array;
/** \struct delivery_volume_per_mall
 * \brief .
 *
 * .
 */
struct delivery_volume_per_mall
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	double quantity;	/**< Datatype memory variable quantity of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	double quality;	/**< Datatype memory variable quality of type double. */
};

/** \struct delivery_volume_per_mall_array
 * \brief Dynamic array to hold delivery_volume_per_malls
 */
struct delivery_volume_per_mall_array
{
	int size;
	int total_size;
	
	struct delivery_volume_per_mall * array;
};

/** \var typedef delivery_volume_per_mall delivery_volume_per_mall
 * \brief Typedef for delivery_volume_per_mall struct.
 */
typedef struct delivery_volume_per_mall delivery_volume_per_mall;
/** \var typedef delivery_volume_per_mall_array delivery_volume_per_mall_array
 * \brief Typedef for delivery_volume_per_mall_array struct.
 */
typedef struct delivery_volume_per_mall_array delivery_volume_per_mall_array;
/** \struct logit_firm_id
 * \brief .
 *
 * .
 */
struct logit_firm_id
{
	double logit;	/**< Datatype memory variable logit of type double. */
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
};

/** \struct logit_firm_id_array
 * \brief Dynamic array to hold logit_firm_ids
 */
struct logit_firm_id_array
{
	int size;
	int total_size;
	
	struct logit_firm_id * array;
};

/** \var typedef logit_firm_id logit_firm_id
 * \brief Typedef for logit_firm_id struct.
 */
typedef struct logit_firm_id logit_firm_id;
/** \var typedef logit_firm_id_array logit_firm_id_array
 * \brief Typedef for logit_firm_id_array struct.
 */
typedef struct logit_firm_id_array logit_firm_id_array;
/** \struct sales_in_mall
 * \brief .
 *
 * .
 */
struct sales_in_mall
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double sales;	/**< Datatype memory variable sales of type double. */
};

/** \struct sales_in_mall_array
 * \brief Dynamic array to hold sales_in_malls
 */
struct sales_in_mall_array
{
	int size;
	int total_size;
	
	struct sales_in_mall * array;
};

/** \var typedef sales_in_mall sales_in_mall
 * \brief Typedef for sales_in_mall struct.
 */
typedef struct sales_in_mall sales_in_mall;
/** \var typedef sales_in_mall_array sales_in_mall_array
 * \brief Typedef for sales_in_mall_array struct.
 */
typedef struct sales_in_mall_array sales_in_mall_array;
/** \struct ordered_quantity
 * \brief .
 *
 * .
 */
struct ordered_quantity
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. *