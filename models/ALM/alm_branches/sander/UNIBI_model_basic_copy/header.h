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
/** \def e START_VACANCIES_MESSAGE_LOOP
 * \brief Start of loop to process vacancies messages. */
#define START_VACANCIES_MESSAGE_LOOP  vacancies_message = get_first_vacancies_message(); while(vacancies_message) {
/** \def FINISH_VACANCIES_MESSAGE_LOOP
 * \brief Finish of loop to process vacancies messages. */
#define FINISH_VACANCIES_MESSAGE_LOOP vacancies_message = get_next_vacancies_message(vacancies_message); }
/** \def e START_VACANCIES2_MESSAGE_LOOP
 * \brief Start of loop to process vacancies2 messages. */
#define START_VACANCIES2_MESSAGE_LOOP  vacancies2_message = get_first_vacancies2_message(); while(vacancies2_message) {
/** \def FINISH_VACANCIES2_MESSAGE_LOOP
 * \brief Finish of loop to process vacancies2 messages. */
#define FINISH_VACANCIES2_MESSAGE_LOOP vacancies2_message = get_next_vacancies2_message(vacancies2_message); }
/** \def e START_FIRING_MESSAGE_LOOP
 * \brief Start of loop to process firing messages. */
#define START_FIRING_MESSAGE_LOOP  firing_message = get_first_firing_message(); while(firing_message) {
/** \def FINISH_FIRING_MESSAGE_LOOP
 * \brief Finish of loop to process firing messages. */
#define FINISH_FIRING_MESSAGE_LOOP firing_message = get_next_firing_message(firing_message); }
/** \def e START_JOB_APPLICATION_MESSAGE_LOOP
 * \brief Start of loop to process job_application messages. */
#define START_JOB_APPLICATION_MESSAGE_LOOP  job_application_message = get_first_job_application_message(); while(job_application_message) {
/** \def FINISH_JOB_APPLICATION_MESSAGE_LOOP
 * \brief Finish of loop to process job_application messages. */
#define FINISH_JOB_APPLICATION_MESSAGE_LOOP job_application_message = get_next_job_application_message(job_application_message); }
/** \def e START_JOB_APPLICATION2_MESSAGE_LOOP
 * \brief Start of loop to process job_application2 messages. */
#define START_JOB_APPLICATION2_MESSAGE_LOOP  job_application2_message = get_first_job_application2_message(); while(job_application2_message) {
/** \def FINISH_JOB_APPLICATION2_MESSAGE_LOOP
 * \brief Finish of loop to process job_application2 messages. */
#define FINISH_JOB_APPLICATION2_MESSAGE_LOOP job_application2_message = get_next_job_application2_message(job_application2_message); }
/** \def e START_JOB_OFFER_MESSAGE_LOOP
 * \brief Start of loop to process job_offer messages. */
#define START_JOB_OFFER_MESSAGE_LOOP  job_offer_message = get_first_job_offer_message(); while(job_offer_message) {
/** \def FINISH_JOB_OFFER_MESSAGE_LOOP
 * \brief Finish of loop to process job_offer messages. */
#define FINISH_JOB_OFFER_MESSAGE_LOOP job_offer_message = get_next_job_offer_message(job_offer_message); }
/** \def e START_JOB_OFFER2_MESSAGE_LOOP
 * \brief Start of loop to process job_offer2 messages. */
#define START_JOB_OFFER2_MESSAGE_LOOP  job_offer2_message = get_first_job_offer2_message(); while(job_offer2_message) {
/** \def FINISH_JOB_OFFER2_MESSAGE_LOOP
 * \brief Finish of loop to process job_offer2 messages. */
#define FINISH_JOB_OFFER2_MESSAGE_LOOP job_offer2_message = get_next_job_offer2_message(job_offer2_message); }
/** \def e START_JOB_ACCEPTANCE_MESSAGE_LOOP
 * \brief Start of loop to process job_acceptance messages. */
#define START_JOB_ACCEPTANCE_MESSAGE_LOOP  job_acceptance_message = get_first_job_acceptance_message(); while(job_acceptance_message) {
/** \def FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP
 * \brief Finish of loop to process job_acceptance messages. */
#define FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP job_acceptance_message = get_next_job_acceptance_message(job_acceptance_message); }
/** \def e START_JOB_ACCEPTANCE2_MESSAGE_LOOP
 * \brief Start of loop to process job_acceptance2 messages. */
#define START_JOB_ACCEPTANCE2_MESSAGE_LOOP  job_acceptance2_message = get_first_job_acceptance2_message(); while(job_acceptance2_message) {
/** \def FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP
 * \brief Finish of loop to process job_acceptance2 messages. */
#define FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP job_acceptance2_message = get_next_job_acceptance2_message(job_acceptance2_message); }
/** \def e START_APPLICATION_REJECTION_MESSAGE_LOOP
 * \brief Start of loop to process application_rejection messages. */
#define START_APPLICATION_REJECTION_MESSAGE_LOOP  application_rejection_message = get_first_application_rejection_message(); while(application_rejection_message) {
/** \def FINISH_APPLICATION_REJECTION_MESSAGE_LOOP
 * \brief Finish of loop to process application_rejection messages. */
#define FINISH_APPLICATION_REJECTION_MESSAGE_LOOP application_rejection_message = get_next_application_rejection_message(application_rejection_message); }
/** \def e START_APPLICATION_REJECTION2_MESSAGE_LOOP
 * \brief Start of loop to process application_rejection2 messages. */
#define START_APPLICATION_REJECTION2_MESSAGE_LOOP  application_rejection2_message = get_first_application_rejection2_message(); while(application_rejection2_message) {
/** \def FINISH_APPLICATION_REJECTION2_MESSAGE_LOOP
 * \brief Finish of loop to process application_rejection2 messages. */
#define FINISH_APPLICATION_REJECTION2_MESSAGE_LOOP application_rejection2_message = get_next_application_rejection2_message(application_rejection2_message); }
/** \def e START_QUITTING_MESSAGE_LOOP
 * \brief Start of loop to process quitting messages. */
#define START_QUITTING_MESSAGE_LOOP  quitting_message = get_first_quitting_message(); while(quitting_message) {
/** \def FINISH_QUITTING_MESSAGE_LOOP
 * \brief Finish of loop to process quitting messages. */
#define FINISH_QUITTING_MESSAGE_LOOP quitting_message = get_next_quitting_message(quitting_message); }
/** \def e START_QUITTING2_MESSAGE_LOOP
 * \brief Start of loop to process quitting2 messages. */
#define START_QUITTING2_MESSAGE_LOOP  quitting2_message = get_first_quitting2_message(); while(quitting2_message) {
/** \def FINISH_QUITTING2_MESSAGE_LOOP
 * \brief Finish of loop to process quitting2 messages. */
#define FINISH_QUITTING2_MESSAGE_LOOP quitting2_message = get_next_quitting2_message(quitting2_message); }
/** \def e START_PRODUCTIVITY_MESSAGE_LOOP
 * \brief Start of loop to process productivity messages. */
#define START_PRODUCTIVITY_MESSAGE_LOOP  productivity_message = get_first_productivity_message(); while(productivity_message) {
/** \def FINISH_PRODUCTIVITY_MESSAGE_LOOP
 * \brief Finish of loop to process productivity messages. */
#define FINISH_PRODUCTIVITY_MESSAGE_LOOP productivity_message = get_next_productivity_message(productivity_message); }
/** \def e START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process capital_good_request messages. */
#define START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP  capital_good_request_message = get_first_capital_good_request_message(); while(capital_good_request_message) {
/** \def FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process capital_good_request messages. */
#define FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP capital_good_request_message = get_next_capital_good_request_message(capital_good_request_message); }
/** \def e START_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP
 * \brief Start of loop to process capital_good_profit_distribution messages. */
#define START_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP  capital_good_profit_distribution_message = get_first_capital_good_profit_distribution_message(); while(capital_good_profit_distribution_message) {
/** \def FINISH_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP
 * \brief Finish of loop to process capital_good_profit_distribution messages. */
#define FINISH_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP capital_good_profit_distribution_message = get_next_capital_good_profit_distribution_message(capital_good_profit_distribution_message); }
/** \def e START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
 * \brief Start of loop to process capital_good_delivery messages. */
#define START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP  capital_good_delivery_message = get_first_capital_good_delivery_message(); while(capital_good_delivery_message) {
/** \def FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
 * \brief Finish of loop to process capital_good_delivery messages. */
#define FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP capital_good_delivery_message = get_next_capital_good_delivery_message(capital_good_delivery_message); }
/** \def e START_WAGE_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process wage_payment messages. */
#define START_WAGE_PAYMENT_MESSAGE_LOOP  wage_payment_message = get_first_wage_payment_message(); while(wage_payment_message) {
/** \def FINISH_WAGE_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process wage_payment messages. */
#define FINISH_WAGE_PAYMENT_MESSAGE_LOOP wage_payment_message = get_next_wage_payment_message(wage_payment_message); }
/** \def e START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP
 * \brief Start of loop to process quality_price_info_1 messages. */
#define START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP  quality_price_info_1_message = get_first_quality_price_info_1_message(); while(quality_price_info_1_message) {
/** \def FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP
 * \brief Finish of loop to process quality_price_info_1 messages. */
#define FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP quality_price_info_1_message = get_next_quality_price_info_1_message(quality_price_info_1_message); }
/** \def e START_QUALITY_PRICE_INFO_2_MESSAGE_LOOP
 * \brief Start of loop to process quality_price_info_2 messages. */
#define START_QUALITY_PRICE_INFO_2_MESSAGE_LOOP  quality_price_info_2_message = get_first_quality_price_info_2_message(); while(quality_price_info_2_message) {
/** \def FINISH_QUALITY_PRICE_INFO_2_MESSAGE_LOOP
 * \brief Finish of loop to process quality_price_info_2 messages. */
#define FINISH_QUALITY_PRICE_INFO_2_MESSAGE_LOOP quality_price_info_2_message = get_next_quality_price_info_2_message(quality_price_info_2_message); }
/** \def e START_UPDATE_MALL_STOCK_MESSAGE_LOOP
 * \brief Start of loop to process update_mall_stock messages. */
#define START_UPDATE_MALL_STOCK_MESSAGE_LOOP  update_mall_stock_message = get_first_update_mall_stock_message(); while(update_mall_stock_message) {
/** \def FINISH_UPDATE_MALL_STOCK_MESSAGE_LOOP
 * \brief Finish of loop to process update_mall_stock messages. */
#define FINISH_UPDATE_MALL_STOCK_MESSAGE_LOOP update_mall_stock_message = get_next_update_mall_stock_message(update_mall_stock_message); }
/** \def e START_CONSUMPTION_REQUEST_1_MESSAGE_LOOP
 * \brief Start of loop to process consumption_request_1 messages. */
#define START_CONSUMPTION_REQUEST_1_MESSAGE_LOOP  consumption_request_1_message = get_first_consumption_request_1_message(); while(consumption_request_1_message) {
/** \def FINISH_CONSUMPTION_REQUEST_1_MESSAGE_LOOP
 * \brief Finish of loop to process consumption_request_1 messages. */
#define FINISH_CONSUMPTION_REQUEST_1_MESSAGE_LOOP consumption_request_1_message = get_next_consumption_request_1_message(consumption_request_1_message); }
/** \def e START_CONSUMPTION_REQUEST_2_MESSAGE_LOOP
 * \brief Start of loop to process consumption_request_2 messages. */
#define START_CONSUMPTION_REQUEST_2_MESSAGE_LOOP  consumption_request_2_message = get_first_consumption_request_2_message(); while(consumption_request_2_message) {
/** \def FINISH_CONSUMPTION_REQUEST_2_MESSAGE_LOOP
 * \brief Finish of loop to process consumption_request_2 messages. */
#define FINISH_CONSUMPTION_REQUEST_2_MESSAGE_LOOP consumption_request_2_message = get_next_consumption_request_2_message(consumption_request_2_message); }
/** \def e START_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP
 * \brief Start of loop to process accepted_consumption_1 messages. */
#define START_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP  accepted_consumption_1_message = get_first_accepted_consumption_1_message(); while(accepted_consumption_1_message) {
/** \def FINISH_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP
 * \brief Finish of loop to process accepted_consumption_1 messages. */
#define FINISH_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP accepted_consumption_1_message = get_next_accepted_consumption_1_message(accepted_consumption_1_message); }
/** \def e START_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP
 * \brief Start of loop to process accepted_consumption_2 messages. */
#define START_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP  accepted_consumption_2_message = get_first_accepted_consumption_2_message(); while(accepted_consumption_2_message) {
/** \def FINISH_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP
 * \brief Finish of loop to process accepted_consumption_2 messages. */
#define FINISH_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP accepted_consumption_2_message = get_next_accepted_consumption_2_message(accepted_consumption_2_message); }
/** \def e START_SALES_MESSAGE_LOOP
 * \brief Start of loop to process sales messages. */
#define START_SALES_MESSAGE_LOOP  sales_message = get_first_sales_message(); while(sales_message) {
/** \def FINISH_SALES_MESSAGE_LOOP
 * \brief Finish of loop to process sales messages. */
#define FINISH_SALES_MESSAGE_LOOP sales_message = get_next_sales_message(sales_message); }
/** \def e START_PAY_CAPITAL_GOODS_MESSAGE_LOOP
 * \brief Start of loop to process pay_capital_goods messages. */
#define START_PAY_CAPITAL_GOODS_MESSAGE_LOOP  pay_capital_goods_message = get_first_pay_capital_goods_message(); while(pay_capital_goods_message) {
/** \def FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP
 * \brief Finish of loop to process pay_capital_goods messages. */
#define FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP pay_capital_goods_message = get_next_pay_capital_goods_message(pay_capital_goods_message); }
/** \def e START_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP
 * \brief Start of loop to process current_mall_stock_info messages. */
#define START_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP  current_mall_stock_info_message = get_first_current_mall_stock_info_message(); while(current_mall_stock_info_message) {
/** \def FINISH_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP
 * \brief Finish of loop to process current_mall_stock_info messages. */
#define FINISH_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP current_mall_stock_info_message = get_next_current_mall_stock_info_message(current_mall_stock_info_message); }
/** \def e START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process specific_skill_update messages. */
#define START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP  specific_skill_update_message = get_first_specific_skill_update_message(); while(specific_skill_update_message) {
/** \def FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process specific_skill_update messages. */
#define FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP specific_skill_update_message = get_next_specific_skill_update_message(specific_skill_update_message); }
/** \def e START_FIRM_SEND_DATA_MESSAGE_LOOP
 * \brief Start of loop to process firm_send_data messages. */
#define START_FIRM_SEND_DATA_MESSAGE_LOOP  firm_send_data_message = get_first_firm_send_data_message(); while(firm_send_data_message) {
/** \def FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
 * \brief Finish of loop to process firm_send_data messages. */
#define FINISH_FIRM_SEND_DATA_MESSAGE_LOOP firm_send_data_message = get_next_firm_send_data_message(firm_send_data_message); }
/** \def e START_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP
 * \brief Start of loop to process household_send_data messages. */
#define START_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP  household_send_data_message = get_first_household_send_data_message(); while(household_send_data_message) {
/** \def FINISH_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP
 * \brief Finish of loop to process household_send_data messages. */
#define FINISH_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP household_send_data_message = get_next_household_send_data_message(household_send_data_message); }
/** \def e START_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
 * \brief Start of loop to process market_research_send_specific_skills messages. */
#define START_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP  market_research_send_specific_skills_message = get_first_market_research_send_specific_skills_message(); while(market_research_send_specific_skills_message) {
/** \def FINISH_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
 * \brief Finish of loop to process market_research_send_specific_skills messages. */
#define FINISH_MARKET_RESEARCH_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP market_research_send_specific_skills_message = get_next_market_research_send_specific_skills_message(market_research_send_specific_skills_message); }
/** \def e START_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process tax_payment messages. */
#define START_TAX_PAYMENT_MESSAGE_LOOP  tax_payment_message = get_first_tax_payment_message(); while(tax_payment_message) {
/** \def FINISH_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process tax_payment messages. */
#define FINISH_TAX_PAYMENT_MESSAGE_LOOP tax_payment_message = get_next_tax_payment_message(tax_payment_message); }
/** \def e START_INTEREST_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process interest_payment messages. */
#define START_INTEREST_PAYMENT_MESSAGE_LOOP  interest_payment_message = get_first_interest_payment_message(); while(interest_payment_message) {
/** \def FINISH_INTEREST_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process interest_payment messages. */
#define FINISH_INTEREST_PAYMENT_MESSAGE_LOOP interest_payment_message = get_next_interest_payment_message(interest_payment_message); }
/** \def e START_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process debt_installment_payment messages. */
#define START_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP  debt_installment_payment_message = get_first_debt_installment_payment_message(); while(debt_installment_payment_message) {
/** \def FINISH_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process debt_installment_payment messages. */
#define FINISH_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP debt_installment_payment_message = get_next_debt_installment_payment_message(debt_installment_payment_message); }
/** \def e START_DIVIDEND_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process dividend_payment messages. */
#define START_DIVIDEND_PAYMENT_MESSAGE_LOOP  dividend_payment_message = get_first_dividend_payment_message(); while(dividend_payment_message) {
/** \def FINISH_DIVIDEND_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process dividend_payment messages. */
#define FINISH_DIVIDEND_PAYMENT_MESSAGE_LOOP dividend_payment_message = get_next_dividend_payment_message(dividend_payment_message); }
/** \def e START_LOAN_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process loan_request messages. */
#define START_LOAN_REQUEST_MESSAGE_LOOP  loan_request_message = get_first_loan_request_message(); while(loan_request_message) {
/** \def FINISH_LOAN_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process loan_request messages. */
#define FINISH_LOAN_REQUEST_MESSAGE_LOOP loan_request_message = get_next_loan_request_message(loan_request_message); }
/** \def e START_LOAN_CONDITIONS_MESSAGE_LOOP
 * \brief Start of loop to process loan_conditions messages. */
#define START_LOAN_CONDITIONS_MESSAGE_LOOP  loan_conditions_message = get_first_loan_conditions_message(); while(loan_conditions_message) {
/** \def FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
 * \brief Finish of loop to process loan_conditions messages. */
#define FINISH_LOAN_CONDITIONS_MESSAGE_LOOP loan_conditions_message = get_next_loan_conditions_message(loan_conditions_message); }
/** \def e START_LOAN_ACCEPTANCE_MESSAGE_LOOP
 * \brief Start of loop to process loan_acceptance messages. */
#define START_LOAN_ACCEPTANCE_MESSAGE_LOOP  loan_acceptance_message = get_first_loan_acceptance_message(); while(loan_acceptance_message) {
/** \def FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
 * \brief Finish of loop to process loan_acceptance messages. */
#define FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP loan_acceptance_message = get_next_loan_acceptance_message(loan_acceptance_message); }
/** \def e START_STOCK_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process stock_order messages. */
#define START_STOCK_ORDER_MESSAGE_LOOP  stock_order_message = get_first_stock_order_message(); while(stock_order_message) {
/** \def FINISH_STOCK_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process stock_order messages. */
#define FINISH_STOCK_ORDER_MESSAGE_LOOP stock_order_message = get_next_stock_order_message(stock_order_message); }
/** \def e START_STOCK_TRANSACTION_MESSAGE_LOOP
 * \brief Start of loop to process stock_transaction messages. */
#define START_STOCK_TRANSACTION_MESSAGE_LOOP  stock_transaction_message = get_first_stock_transaction_message(); while(stock_transaction_message) {
/** \def FINISH_STOCK_TRANSACTION_MESSAGE_LOOP
 * \brief Finish of loop to process stock_transaction messages. */
#define FINISH_STOCK_TRANSACTION_MESSAGE_LOOP stock_transaction_message = get_next_stock_transaction_message(stock_transaction_message); }
/** \def e START_BOND_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process bond_order messages. */
#define START_BOND_ORDER_MESSAGE_LOOP  bond_order_message = get_first_bond_order_message(); while(bond_order_message) {
/** \def FINISH_BOND_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process bond_order messages. */
#define FINISH_BOND_ORDER_MESSAGE_LOOP bond_order_message = get_next_bond_order_message(bond_order_message); }
/** \def e START_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Start of loop to process bond_transaction messages. */
#define START_BOND_TRANSACTION_MESSAGE_LOOP  bond_transaction_message = get_first_bond_transaction_message(); while(bond_transaction_message) {
/** \def FINISH_BOND_TRANSACTION_MESSAGE_LOOP
 * \brief Finish of loop to process bond_transaction messages. */
#define FINISH_BOND_TRANSACTION_MESSAGE_LOOP bond_transaction_message = get_next_bond_transaction_message(bond_transaction_message); }
/** \def e START_GOV_BOND_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process gov_bond_order messages. */
#define START_GOV_BOND_ORDER_MESSAGE_LOOP  gov_bond_order_message = get_first_gov_bond_order_message(); while(gov_bond_order_message) {
/** \def FINISH_GOV_BOND_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process gov_bond_order messages. */
#define FINISH_GOV_BOND_ORDER_MESSAGE_LOOP gov_bond_order_message = get_next_gov_bond_order_message(gov_bond_order_message); }
/** \def e START_GOV_BOND_TRANSACTION_MESSAGE_LOOP
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

/** \struct employee
 * \brief Used to hold employee information in firms.
 *
 * Used to hold employee information in firms.
 */
struct employee
{
	int id;	/**< Datatype memory variable id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double wage;	/**< Datatype memory variable wage of type double. */
	int general_skill;	/**< Datatype memory variable general_skill of type int. */
	double specific_skill;	/**< Datatype memory variable specific_skill of type double. */
};

/** \struct employee_array
 * \brief Dynamic array to hold employees
 */
struct employee_array
{
	int size;
	int total_size;
	
	struct employee * array;
};

/** \var typedef employee employee
 * \brief Typedef for employee struct.
 */
typedef struct employee employee;
/** \var typedef employee_array employee_array
 * \brief Typedef for employee_array struct.
 */
typedef struct employee_array employee_array;
/** \struct vacancy
 * \brief Used by households to hold vacancy information.
 *
 * Used by households to hold vacancy information.
 */
struct vacancy
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double wage_offer;	/**< Datatype memory variable wage_offer of type double. */
};

/** \struct vacancy_array
 * \brief Dynamic array to hold vacancys
 */
struct vacancy_array
{
	int size;
	int total_size;
	
	struct vacancy * array;
};

/** \var typedef vacancy vacancy
 * \brief Typedef for vacancy struct.
 */
typedef struct vacancy vacancy;
/** \var typedef vacancy_array vacancy_array
 * \brief Typedef for vacancy_array struct.
 */
typedef struct vacancy_array vacancy_array;
/** \struct job_application
 * \brief Used by firms to hold job applications.
 *
 * Used by firms to hold job applications.
 */
struct job_application
{
	int worker_id;	/**< Datatype memory variable worker_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	int general_skill;	/**< Datatype memory variable general_skill of type int. */
	double specific_skill;	/**< Datatype memory variable specific_skill of type double. */
};

/** \struct job_application_array
 * \brief Dynamic array to hold job_applications
 */
struct job_application_array
{
	int size;
	int total_size;
	
	struct job_application * array;
};

/** \var typedef job_application job_application
 * \brief Typedef for job_application struct.
 */
typedef struct job_application job_application;
/** \var typedef job_application_array job_application_array
 * \brief Typedef for job_application_array struct.
 */
typedef struct job_application_array job_application_array;
/** \struct job_offer
 * \brief Used by households and firms to hold job offers.
 *
 * Used by households and firms to hold job offers.
 */
struct job_offer
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double wage_offer;	/**< Datatype memory variable wage_offer of type double. */
};

/** \struct job_offer_array
 * \brief Dynamic array to hold job_offers
 */
struct job_offer_array
{
	int size;
	int total_size;
	
	struct job_offer * array;
};

/** \var typedef job_offer job_offer
 * \brief Typedef for job_offer struct.
 */
typedef struct job_offer job_offer;
/** \var typedef job_offer_array job_offer_array
 * \brief Typedef for job_offer_array struct.
 */
typedef struct job_offer_array job_offer_array;
/** \struct consumption_goods_offer
 * \brief Used by household and mall to hold consumption goods offers.
 *
 * Used by household and mall to hold consumption goods offers.
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
 * \brief Used by  mall to hold demand.
 *
 * Used by  mall to hold demand.
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
 * \brief Used by firm to hold information about sales in malls.
 *
 * Used by firm to hold information about sales in malls.
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
 * \brief Used by household to hold information about quality and prices of one good offered by mall.
 *
 * Used by household to hold information about quality and prices of one good offered by mall.
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
 * \brief Used by mall to hold information about current stock.
 *
 * Used by mall to hold information about current stock.
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
 * \brief Used by firm to hold information about delivery volume per mall.
 *
 * Used by firm to hold information about delivery volume per mall.
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
 * \brief Used by household to stock logits and corresponding firm IDs.
 *
 * Used by household to stock logits and corresponding firm IDs.
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
 * \brief Used by mall to calculate sales.
 *
 * Used by mall to calculate sales.
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
 * \brief Used by household to stock ordered quantities.
 *
 * Used by household to stock ordered quantities.
 */
struct ordered_quantity
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double quantity;	/**< Datatype memory variable quantity of type double. */
	double price;	/**< Datatype memory variable price of type double. */
};

/** \struct ordered_quantity_array
 * \brief Dynamic array to hold ordered_quantitys
 */
struct ordered_quantity_array
{
	int size;
	int total_size;
	
	struct ordered_quantity * array;
};

/** \var typedef ordered_quantity ordered_quantity
 * \brief Typedef for ordered_quantity struct.
 */
typedef struct ordered_quantity ordered_quantity;
/** \var typedef ordered_quantity_array ordered_quantity_array
 * \brief Typedef for ordered_quantity_array struct.
 */
typedef struct ordered_quantity_array ordered_quantity_array;
/** \struct received_quantities
 * \brief Used by household to stock received quantities.
 *
 * Used by household to stock received quantities.
 */
struct received_quantities
{
	int firm_id;	/**< Datatype memory variable firm_id of type int. */
	double quantity;	/**< Datatype memory variable quantity of type double. */
};

/** \struct received_quantities_array
 * \brief Dynamic array to hold received_quantitiess
 */
struct received_quantities_array
{
	int size;
	int total_size;
	
	struct received_quantities * array;
};

/** \var typedef received_quantities received_quantities
 * \brief Typedef for received_quantities struct.
 */
typedef struct received_quantities received_quantities;
/** \var typedef received_quantities_array received_quantities_array
 * \brief Typedef for received_quantities_array struct.
 */
typedef struct received_quantities_array received_quantities_array;
/** \struct sold_quantities_per_mall
 * \brief Used by firm to hold informations about sales .
 *
 * Used by firm to hold informations about sales .
 */
struct sold_quantities_per_mall
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	double sold_quantity;	/**< Datatype memory variable sold_quantity of type double. */
	int stock_empty;	/**< Datatype memory variable stock_empty of type int. */
	double estimated_demand;	/**< Datatype memory variable estimated_demand of type double. */
};

/** \struct sold_quantities_per_mall_array
 * \brief Dynamic array to hold sold_quantities_per_malls
 */
struct sold_quantities_per_mall_array
{
	int size;
	int total_size;
	
	struct sold_quantities_per_mall * array;
};

/** \var typedef sold_quantities_per_mall sold_quantities_per_mall
 * \brief Typedef for sold_quantities_per_mall struct.
 */
typedef struct sold_quantities_per_mall sold_quantities_per_mall;
/** \var typedef sold_quantities_per_mall_array sold_quantities_per_mall_array
 * \brief Typedef for sold_quantities_per_mall_array struct.
 */
typedef struct sold_quantities_per_mall_array sold_quantities_per_mall_array;
/** \struct sales_statistics
 * \brief Used by firm to store sales in malls of last periods.
 *
 * Used by firm to store sales in malls of last periods.
 */
struct sales_statistics
{
	int mall_id;	/**< Datatype memory variable mall_id of type int. */
	int period;	/**< Datatype memory variable period of type int. */
	double sales;	/**< Datatype memory variable sales of type double. */
};

/** \struct sales_statistics_array
 * \brief Dynamic array to hold sales_statisticss
 */
struct sales_statistics_array
{
	int size;
	int total_size;
	
	struct sales_statistics * array;
};

/** \var typedef sales_statistics sales_statistics
 * \brief Typedef for sales_statistics struct.
 */
typedef struct sales_statistics sales_statistics;
/** \var typedef sales_statistics_array sales_statistics_array
 * \brief Typedef for sales_statistics_array struct.
 */
typedef struct sales_statistics_array sales_statistics_array;
/** \struct debt_item
 * \brief (L.
 *
 * (L.
 */
struct debt_item
{
	int bank_id;	/**< Datatype memory variable bank_id of type int. */
	double loan_value;	/**< Datatype memory variable loan_value of type double. */
	double interest_rate;	/**< Datatype memory variable interest_rate of type double. */
	double interest_payment;	/**< Datatype memory variable interest_payment of type double. */
	double debt_installment_payment;	/**< Datatype memory variable debt_installment_payment of type double. */
	int nr_periods_before_maturity;	/**< Datatype memory variable nr_periods_before_maturity of type int. */
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
 * \brief °=.
 *
 * °=.
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
/** \struct household_data
 * \brief Used by Market Research to store data of the different regions.
 *
 * Used by Market Research to store data of the different regions.
 */
struct household_data
{
	int region_id;	/**< Datatype memory variable region_id of type int. */
	int no_households;	/**< Datatype memory variable no_households of type int. */
	int no_households_skill_1;	/**< Datatype memory variable no_households_skill_1 of type int. */
	int no_households_skill_2;	/**< Datatype memory variable no_households_skill_2 of type int. */
	int no_households_skill_3;	/**< Datatype memory variable no_households_skill_3 of type int. */
	int no_households_skill_4;	/**< Datatype memory variable no_households_skill_4 of type int. */
	int no_households_skill_5;	/**< Datatype memory variable no_households_skill_5 of type int. */
	int employed;	/**< Datatype memory variable employed of type int. */
	int employed_skill_1;	/**< Datatype memory variable employed_skill_1 of type int. */
	int employed_skill_2;	/**< Datatype memory variable employed_skill_2 of type int. */
	int employed_skill_3;	/**< Datatype memory variable employed_skill_3 of type int. */
	int employed_skill_4;	/**< Datatype memory variable employed_skill_4 of type int. */
	int employed_skill_5;	/**< Datatype memory variable employed_skill_5 of type int. */
	int unemployed;	/**< Datatype memory variable unemployed of type int. */
	double unemployment_rate;	/**< Datatype memory variable unemployment_rate of type double. */
	double unemployment_rate_skill_1;	/**< Datatype memory variable unemployment_rate_skill_1 of type double. */
	double unemployment_rate_skill_2;	/**< Datatype memory variable unemployment_rate_skill_2 of type double. */
	double unemployment_rate_skill_3;	/**< Datatype memory variable unemployment_rate_skill_3 of type double. */
	double unemployment_rate_skill_4;	/**< Datatype memory variable unemployment_rate_skill_4 of type double. */
	double unemployment_rate_skill_5;	/**< Datatype memory variable unemployment_rate_skill_5 of type double. */
	double average_wage;	/**< Datatype memory variable average_wage of type double. */
	double average_wage_skill_1;	/**< Datatype memory variable average_wage_skill_1 of type double. */
	double average_wage_skill_2;	/**< Datatype memory variable average_wage_skill_2 of type double. */
	double average_wage_skill_3;	/**< Datatype memory variable average_wage_skill_3 of type double. */
	double average_wage_skill_4;	/**< Datatype memory variable average_wage_skill_4 of type double. */
	double average_wage_skill_5;	/**< Datatype memory variable average_wage_skill_5 of type double. */
	double average_s_skill;	/**< Datatype memory variable average_s_skill of type double. */
	double average_s_skill_1;	/**< Datatype memory variable average_s_skill_1 of type double. */
	double average_s_skill_2;	/**< Datatype memory variable average_s_skill_2 of type double. */
	double average_s_skill_3;	/**< Datatype memory variable average_s_skill_3 of type double. */
	double average_s_skill_4;	/**< Datatype memory variable average_s_skill_4 of type double. */
	double average_s_skill_5;	/**< Datatype memory variable average_s_skill_5 of type double. */
};

/** \struct household_data_array
 * \brief Dynamic array to hold household_datas
 */
struct household_data_array
{
	int size;
	int total_size;
	
	struct household_data * array;
};

/** \var typedef household_data household_data
 * \brief Typedef for household_data struct.
 */
typedef struct household_data household_data;
/** \var typedef household_data_array household_data_array
 * \brief Typedef for household_data_array struct.
 */
typedef struct household_data_array household_data_array;
/** \struct firm_data
 * \brief Used by Market Research to store data of the different regions.
 *
 * Used by Market Research to store data of the different regions.
 */
struct firm_data
{
	int region_id;	/**< Datatype memory variable region_id of type int. */
	int firms;	/**< Datatype memory variable firms of type int. */
	int vacancies;	/**< Datatype memory variable vacancies of type int. */
	int employees;	/**< Datatype memory variable employees of type int. */
	int employees_skill_1;	/**< Datatype memory variable employees_skill_1 of type int. */
	int employees_skill_2;	/**< Datatype memory variable employees_skill_2 of type int. */
	int employees_skill_3;	/**< Datatype memory variable employees_skill_3 of type int. */
	int employees_skill_4;	/**< Datatype memory variable employees_skill_4 of type int. */
	int employees_skill_5;	/**< Datatype memory variable employees_skill_5 of type int. */
	double average_wage;	/**< Datatype memory variable average_wage of type double. */
	double average_wage_skill_1;	/**< Datatype memory variable average_wage_skill_1 of type double. */
	double average_wage_skill_2;	/**< Datatype memory variable average_wage_skill_2 of type double. */
	double average_wage_skill_3;	/**< Datatype memory variable average_wage_skill_3 of type double. */
	double average_wage_skill_4;	/**< Datatype memory variable average_wage_skill_4 of type double. */
	double average_wage_skill_5;	/**< Datatype memory variable average_wage_skill_5 of type double. */
	double average_s_skill;	/**< Datatype memory variable average_s_skill of type double. */
	double average_s_skill_1;	/**< Datatype memory variable average_s_skill_1 of type double. */
	double average_s_skill_2;	/**< Datatype memory variable average_s_skill_2 of type double. */
	double average_s_skill_3;	/**< Datatype memory variable average_s_skill_3 of type double. */
	double average_s_skill_4;	/**< Datatype memory variable average_s_skill_4 of type double. */
	double average_s_skill_5;	/**< Datatype memory variable average_s_skill_5 of type double. */
};

/** \struct firm_data_array
 * \brief Dynamic array to hold firm_datas
 */
struct firm_data_array
{
	int size;
	int total_size;
	
	struct firm_data * array;
};

/** \var typedef firm_data firm_data
 * \brief Typedef for firm_data struct.
 */
typedef struct firm_data firm_data;
/** \var typedef firm_data_array firm_data_array
 * \brief Typedef for firm_data_array struct.
 */
typedef struct firm_data_array firm_data_array;

/** \struct xmachine_memory_Firm
 * \brief Holds memory of xmachine Firm.
 */
struct xmachine_memory_Firm
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	employee_array employees;	/**< X-machine memory variable employees of type employee_array. */
	double wage_offer;	/**< X-machine memory variable wage_offer of type double. */
	double technology;	/**< X-machine memory variable technology of type double. */
	int no_employees;	/**< X-machine memory variable no_employees of type int. */
	int no_employees_skill_1;	/**< X-machine memory variable no_employees_skill_1 of type int. */
	int no_employees_skill_2;	/**< X-machine memory variable no_employees_skill_2 of type int. */
	int no_employees_skill_3;	/**< X-machine memory variable no_employees_skill_3 of type int. */
	int no_employees_skill_4;	/**< X-machine memory variable no_employees_skill_4 of type int. */
	int no_employees_skill_5;	/**< X-machine memory variable no_employees_skill_5 of type int. */
	int vacancies;	/**< X-machine memory variable vacancies of type int. */
	double average_g_skill;	/**< X-machine memory variable average_g_skill of type double. */
	double average_s_skill_of_1;	/**< X-machine memory variable average_s_skill_of_1 of type double. */
	double average_s_skill_of_2;	/**< X-machine memory variable average_s_skill_of_2 of type double. */
	double average_s_skill_of_3;	/**< X-machine memory variable average_s_skill_of_3 of type double. */
	double average_s_skill_of_4;	/**< X-machine memory variable average_s_skill_of_4 of type double. */
	double average_s_skill_of_5;	/**< X-machine memory variable average_s_skill_of_5 of type double. */
	double wage_offer_for_skill_1;	/**< X-machine memory variable wage_offer_for_skill_1 of type double. */
	double wage_offer_for_skill_2;	/**< X-machine memory variable wage_offer_for_skill_2 of type double. */
	double wage_offer_for_skill_3;	/**< X-machine memory variable wage_offer_for_skill_3 of type double. */
	double wage_offer_for_skill_4;	/**< X-machine memory variable wage_offer_for_skill_4 of type double. */
	double wage_offer_for_skill_5;	/**< X-machine memory variable wage_offer_for_skill_5 of type double. */
	int wage_update_was_made;	/**< X-machine memory variable wage_update_was_made of type int. */
	double share_net_investments;	/**< X-machine memory variable share_net_investments of type double. */
	double mean_wage;	/**< X-machine memory variable mean_wage of type double. */
	double needed_capital_stock;	/**< X-machine memory variable needed_capital_stock of type double. */
	double actual_cap_price;	/**< X-machine memory variable actual_cap_price of type double. */
	double mean_specific_skills;	/**< X-machine memory variable mean_specific_skills of type double. */
	double planned_production_quantity;	/**< X-machine memory variable planned_production_quantity of type double. */
	double production_quantity;	/**< X-machine memory variable production_quantity of type double. */
	double unit_costs;	/**< X-machine memory variable unit_costs of type double. */
	double planned_production_costs;	/**< X-machine memory variable planned_production_costs of type double. */
	double production_costs;	/**< X-machine memory variable production_costs of type double. */
	double revenue_per_day;	/**< X-machine memory variable revenue_per_day of type double. */
	double technological_frontier;	/**< X-machine memory variable technological_frontier of type double. */
	double cum_revenue;	/**< X-machine memory variable cum_revenue of type double. */
	double out_of_stock_costs;	/**< X-machine memory variable out_of_stock_costs of type double. */
	sales_statistics_array malls_sales_statistics;	/**< X-machine memory variable malls_sales_statistics of type sales_statistics_array. */
	double quality;	/**< X-machine memory variable quality of type double. */
	double price;	/**< X-machine memory variable price of type double. */
	double price_last_month;	/**< X-machine memory variable price_last_month of type double. */
	capital_stock_item_array capital_stock;	/**< X-machine memory variable capital_stock of type capital_stock_item_array. */
	double total_units_capital_stock;	/**< X-machine memory variable total_units_capital_stock of type double. */
	double total_value_capital_stock;	/**< X-machine memory variable total_value_capital_stock of type double. */
	double total_capital_depreciation_value;	/**< X-machine memory variable total_capital_depreciation_value of type double. */
	double total_capital_depreciation_units;	/**< X-machine memory variable total_capital_depreciation_units of type double. */
	int employees_needed;	/**< X-machine memory variable employees_needed of type int. */
	sold_quantities_per_mall_array sold_quantities;	/**< X-machine memory variable sold_quantities of type sold_quantities_per_mall_array. */
	double total_sold_quantity;	/**< X-machine memory variable total_sold_quantity of type double. */
	double cum_total_sold_quantity;	/**< X-machine memory variable cum_total_sold_quantity of type double. */
	delivery_volume_per_mall_array delivery_volume;	/**< X-machine memory variable delivery_volume of type delivery_volume_per_mall_array. */
	delivery_volume_per_mall_array planned_delivery_volume;	/**< X-machine memory variable planned_delivery_volume of type delivery_volume_per_mall_array. */
	mall_info_array current_mall_stocks;	/**< X-machine memory variable current_mall_stocks of type mall_info_array. */
	double demand_capital_stock;	/**< X-machine memory variable demand_capital_stock of type double. */
	double_array last_planned_production_quantities;	/**< X-machine memory variable last_planned_production_quantities of type double_array. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	double ebit;	/**< X-machine memory variable ebit of type double. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	double earnings;	/**< X-machine memory variable earnings of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	double tax_payment;	/**< X-machine memory variable tax_payment of type double. */
	double net_earnings;	/**< X-machine memory variable net_earnings of type double. */
	double previous_net_earnings;	/**< X-machine memory variable previous_net_earnings of type double. */
	debt_item_array loans;	/**< X-machine memory variable loans of type debt_item_array. */
	double total_interest_payment;	/**< X-machine memory variable total_interest_payment of type double. */
	double total_debt_installment_payment;	/**< X-machine memory variable total_debt_installment_payment of type double. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double total_dividend_payment;	/**< X-machine memory variable total_dividend_payment of type double. */
	double total_value_local_inventory;	/**< X-machine memory variable total_value_local_inventory of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double planned_cum_revenue;	/**< X-machine memory variable planned_cum_revenue of type double. */
	double planned_total_interest_payment;	/**< X-machine memory variable planned_total_interest_payment of type double. */
	double planned_total_debt_installment_payment;	/**< X-machine memory variable planned_total_debt_installment_payment of type double. */
	double planned_total_dividend_payment;	/**< X-machine memory variable planned_total_dividend_payment of type double. */
	double direct_financial_needs;	/**< X-machine memory variable direct_financial_needs of type double. */
	double delayed_financial_needs;	/**< X-machine memory variable delayed_financial_needs of type double. */
	double total_financial_needs;	/**< X-machine memory variable total_financial_needs of type double. */
	double internal_financial_needs;	/**< X-machine memory variable internal_financial_needs of type double. */
	double external_financial_needs;	/**< X-machine memory variable external_financial_needs of type double. */
	double total_external_financing_obtained;	/**< X-machine memory variable total_external_financing_obtained of type double. */
	int direct_financial_needs_require_external_financing;	/**< X-machine memory variable direct_financial_needs_require_external_financing of type int. */
	int delayed_financial_needs_require_external_financing;	/**< X-machine memory variable delayed_financial_needs_require_external_financing of type int. */
	double current_share_price;	/**< X-machine memory variable current_share_price of type double. */
	double current_shares_outstanding;	/**< X-machine memory variable current_shares_outstanding of type double. */
	double previous_dividend_per_share;	/**< X-machine memory variable previous_dividend_per_share of type double. */
	double current_dividend_per_share;	/**< X-machine memory variable current_dividend_per_share of type double. */
	double previous_dividend_per_earnings;	/**< X-machine memory variable previous_dividend_per_earnings of type double. */
	double current_dividend_per_earnings;	/**< X-machine memory variable current_dividend_per_earnings of type double. */
	double earnings_per_share_ratio;	/**< X-machine memory variable earnings_per_share_ratio of type double. */
	double debt_earnings_ratio;	/**< X-machine memory variable debt_earnings_ratio of type double. */
	double price_earnings_ratio;	/**< X-machine memory variable price_earnings_ratio of type double. */
	double retained_earnings_ratio;	/**< X-machine memory variable retained_earnings_ratio of type double. */
	double earnings_per_share_ratio_growth;	/**< X-machine memory variable earnings_per_share_ratio_growth of type double. */
	double critical_price_earnings_ratio;	/**< X-machine memory variable critical_price_earnings_ratio of type double. */
	double critical_earnings_per_share_ratio;	/**< X-machine memory variable critical_earnings_per_share_ratio of type double. */
	double target_loans;	/**< X-machine memory variable target_loans of type double. */
	double target_equity;	/**< X-machine memory variable target_equity of type double. */
	double bonds_issue_target;	/**< X-machine memory variable bonds_issue_target of type double. */
	double stocks_issue_target;	/**< X-machine memory variable stocks_issue_target of type double. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Household
 * \brief Holds memory of xmachine Household.
 */
struct xmachine_memory_Household
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int_array neighboring_region_ids;	/**< X-machine memory variable neighboring_region_ids of type int_array. */
	double wage;	/**< X-machine memory variable wage of type double. */
	double wage_reservation;	/**< X-machine memory variable wage_reservation of type double. */
	int general_skill;	/**< X-machine memory variable general_skill of type int. */
	int on_the_job_search;	/**< X-machine memory variable on_the_job_search of type int. */
	int number_applications;	/**< X-machine memory variable number_applications of type int. */
	double specific_skill;	/**< X-machine memory variable specific_skill of type double. */
	int employee_firm_id;	/**< X-machine memory variable employee_firm_id of type int. */
	int employer_region_id;	/**< X-machine memory variable employer_region_id of type int. */
	double budget;	/**< X-machine memory variable budget of type double. */
	int week_of_month;	/**< X-machine memory variable week_of_month of type int. */
	double weekly_budget;	/**< X-machine memory variable weekly_budget of type double. */
	double expenditures;	/**< X-machine memory variable expenditures of type double. */
	double received_dividend_cap;	/**< X-machine memory variable received_dividend_cap of type double. */
	double received_dividend_cons;	/**< X-machine memory variable received_dividend_cons of type double. */
	double savings;	/**< X-machine memory variable savings of type double. */
	double_array last_income;	/**< X-machine memory variable last_income of type double_array. */
	int rationed;	/**< X-machine memory variable rationed of type int. */
	int mall_completely_sold_out;	/**< X-machine memory variable mall_completely_sold_out of type int. */
	ordered_quantity order_quantity[2];	/**< X-machine memory variable order_quantity of type ordered_quantity. */
	received_quantities received_quantity[2];	/**< X-machine memory variable received_quantity of type received_quantities. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	int day_of_week_to_act;	/**< X-machine memory variable day_of_week_to_act of type int. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Mall
 * \brief Holds memory of xmachine Mall.
 */
struct xmachine_memory_Mall
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	mall_stock_array current_stock;	/**< X-machine memory variable current_stock of type mall_stock_array. */
	sales_in_mall_array firm_revenues;	/**< X-machine memory variable firm_revenues of type sales_in_mall_array. */
	double total_supply;	/**< X-machine memory variable total_supply of type double. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_IGFirm
 * \brief Holds memory of xmachine IGFirm.
 */
struct xmachine_memory_IGFirm
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	double productivity;	/**< X-machine memory variable productivity of type double. */
	int innovation_probability;	/**< X-machine memory variable innovation_probability of type int. */
	double productivity_progress;	/**< X-machine memory variable productivity_progress of type double. */
	double capital_good_price;	/**< X-machine memory variable capital_good_price of type double. */
	double revenue_per_day;	/**< X-machine memory variable revenue_per_day of type double. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Market_Research
 * \brief Holds memory of xmachine Market_Research.
 */
struct xmachine_memory_Market_Research
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int no_regions;	/**< X-machine memory variable no_regions of type int. */
	int num_households;	/**< X-machine memory variable num_households of type int. */
	int no_households_skill_1;	/**< X-machine memory variable no_households_skill_1 of type int. */
	int no_households_skill_2;	/**< X-machine memory variable no_households_skill_2 of type int. */
	int no_households_skill_3;	/**< X-machine memory variable no_households_skill_3 of type int. */
	int no_households_skill_4;	/**< X-machine memory variable no_households_skill_4 of type int. */
	int no_households_skill_5;	/**< X-machine memory variable no_households_skill_5 of type int. */
	int employed;	/**< X-machine memory variable employed of type int. */
	int employed_skill_1;	/**< X-machine memory variable employed_skill_1 of type int. */
	int employed_skill_2;	/**< X-machine memory variable employed_skill_2 of type int. */
	int employed_skill_3;	/**< X-machine memory variable employed_skill_3 of type int. */
	int employed_skill_4;	/**< X-machine memory variable employed_skill_4 of type int. */
	int employed_skill_5;	/**< X-machine memory variable employed_skill_5 of type int. */
	int unemployed;	/**< X-machine memory variable unemployed of type int. */
	double unemployment_rate;	/**< X-machine memory variable unemployment_rate of type double. */
	double unemployment_rate_skill_1;	/**< X-machine memory variable unemployment_rate_skill_1 of type double. */
	double unemployment_rate_skill_2;	/**< X-machine memory variable unemployment_rate_skill_2 of type double. */
	double unemployment_rate_skill_3;	/**< X-machine memory variable unemployment_rate_skill_3 of type double. */
	double unemployment_rate_skill_4;	/**< X-machine memory variable unemployment_rate_skill_4 of type double. */
	double unemployment_rate_skill_5;	/**< X-machine memory variable unemployment_rate_skill_5 of type double. */
	double average_wage;	/**< X-machine memory variable average_wage of type double. */
	double average_wage_skill_1;	/**< X-machine memory variable average_wage_skill_1 of type double. */
	double average_wage_skill_2;	/**< X-machine memory variable average_wage_skill_2 of type double. */
	double average_wage_skill_3;	/**< X-machine memory variable average_wage_skill_3 of type double. */
	double average_wage_skill_4;	/**< X-machine memory variable average_wage_skill_4 of type double. */
	double average_wage_skill_5;	/**< X-machine memory variable average_wage_skill_5 of type double. */
	double average_s_skill;	/**< X-machine memory variable average_s_skill of type double. */
	double average_s_skill_1;	/**< X-machine memory variable average_s_skill_1 of type double. */
	double average_s_skill_2;	/**< X-machine memory variable average_s_skill_2 of type double. */
	double average_s_skill_3;	/**< X-machine memory variable average_s_skill_3 of type double. */
	double average_s_skill_4;	/**< X-machine memory variable average_s_skill_4 of type double. */
	double average_s_skill_5;	/**< X-machine memory variable average_s_skill_5 of type double. */
	int no_firms;	/**< X-machine memory variable no_firms of type int. */
	int no_vacancies;	/**< X-machine memory variable no_vacancies of type int. */
	int no_employees;	/**< X-machine memory variable no_employees of type int. */
	int no_employees_skill_1;	/**< X-machine memory variable no_employees_skill_1 of type int. */
	int no_employees_skill_2;	/**< X-machine memory variable no_employees_skill_2 of type int. */
	int no_employees_skill_3;	/**< X-machine memory variable no_employees_skill_3 of type int. */
	int no_employees_skill_4;	/**< X-machine memory variable no_employees_skill_4 of type int. */
	int no_employees_skill_5;	/**< X-machine memory variable no_employees_skill_5 of type int. */
	double firm_average_wage;	/**< X-machine memory variable firm_average_wage of type double. */
	double firm_average_wage_skill_1;	/**< X-machine memory variable firm_average_wage_skill_1 of type double. */
	double firm_average_wage_skill_2;	/**< X-machine memory variable firm_average_wage_skill_2 of type double. */
	double firm_average_wage_skill_3;	/**< X-machine memory variable firm_average_wage_skill_3 of type double. */
	double firm_average_wage_skill_4;	/**< X-machine memory variable firm_average_wage_skill_4 of type double. */
	double firm_average_wage_skill_5;	/**< X-machine memory variable firm_average_wage_skill_5 of type double. */
	double firm_average_s_skill;	/**< X-machine memory variable firm_average_s_skill of type double. */
	double firm_average_s_skill_1;	/**< X-machine memory variable firm_average_s_skill_1 of type double. */
	double firm_average_s_skill_2;	/**< X-machine memory variable firm_average_s_skill_2 of type double. */
	double firm_average_s_skill_3;	/**< X-machine memory variable firm_average_s_skill_3 of type double. */
	double firm_average_s_skill_4;	/**< X-machine memory variable firm_average_s_skill_4 of type double. */
	double firm_average_s_skill_5;	/**< X-machine memory variable firm_average_s_skill_5 of type double. */
	firm_data_array region_firm_data;	/**< X-machine memory variable region_firm_data of type firm_data_array. */
	household_data_array region_household_data;	/**< X-machine memory variable region_household_data of type household_data_array. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Clearinghouse
 * \brief Holds memory of xmachine Clearinghouse.
 */
struct xmachine_memory_Clearinghouse
{
	int id;	/**< X-machine memory variable id of type int. */
	int trader_id;	/**< X-machine memory variable trader_id of type int. */
	int stock_id;	/**< X-machine memory variable stock_id of type int. */
	int bond_id;	/**< X-machine memory variable bond_id of type int. */
	int gov_bond_id;	/**< X-machine memory variable gov_bond_id of type int. */
	double limit_price;	/**< X-machine memory variable limit_price of type double. */
	double limit_quantity;	/**< X-machine memory variable limit_quantity of type double. */
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
	double proposed_interest_rate;	/**< X-machine memory variable proposed_interest_rate of type double. */
	double amount_credit_offer;	/**< X-machine memory variable amount_credit_offer of type double. */
	double range;	/**< X-machine memory variable range of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	struct xmachine_memory_Firm * xmachine_Firm;	/**< Pointer to X-machine memory of type Firm.  */
	struct xmachine_memory_Household * xmachine_Household;	/**< Pointer to X-machine memory of type Household.  */
	struct xmachine_memory_Mall * xmachine_Mall;	/**< Pointer to X-machine memory of type Mall.  */
	struct xmachine_memory_IGFirm * xmachine_IGFirm;	/**< Pointer to X-machine memory of type IGFirm.  */
	struct xmachine_memory_Market_Research * xmachine_Market_Research;	/**< Pointer to X-machine memory of type Market_Research.  */
	struct xmachine_memory_Clearinghouse * xmachine_Clearinghouse;	/**< Pointer to X-machine memory of type Clearinghouse.  */
	struct xmachine_memory_Bank * xmachine_Bank;	/**< Pointer to X-machine memory of type Bank.  */
	
	struct xmachine * next;	/**< Pointer to next X-machine in the list.  */
};

/** \struct xmachine_message_vacancies
 * \brief Holds message of type vacancies_message.
 */
struct xmachine_message_vacancies
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int firm_vacancies;	/**< Message memory variable firm_vacancies of type int. */
	int skill_group;	/**< Message memory variable skill_group of type int. */
	double firm_wage_offer;	/**< Message memory variable firm_wage_offer of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_vacancies * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_vacancies2
 * \brief Holds message of type vacancies2_message.
 */
struct xmachine_message_vacancies2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int firm_vacancies;	/**< Message memory variable firm_vacancies of type int. */
	int skill_group;	/**< Message memory variable skill_group of type int. */
	double firm_wage_offer;	/**< Message memory variable firm_wage_offer of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_vacancies2 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_firing
 * \brief Holds message of type firing_message.
 */
struct xmachine_message_firing
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_firing * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_job_application
 * \brief Holds message of type job_application_message.
 */
struct xmachine_message_job_application
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_job_application * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_job_application2
 * \brief Holds message of type job_application2_message.
 */
struct xmachine_message_job_application2
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_job_application2 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_job_offer
 * \brief Holds message of type job_offer_message.
 */
struct xmachine_message_job_offer
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double wage_offer;	/**< Message memory variable wage_offer of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_job_offer * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_job_offer2
 * \brief Holds message of type job_offer2_message.
 */
struct xmachine_message_job_offer2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double wage_offer;	/**< Message memory variable wage_offer of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_job_offer2 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_job_acceptance
 * \brief Holds message of type job_acceptance_message.
 */
struct xmachine_message_job_acceptance
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_job_acceptance * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_job_acceptance2
 * \brief Holds message of type job_acceptance2_message.
 */
struct xmachine_message_job_acceptance2
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_job_acceptance2 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_application_rejection
 * \brief Holds message of type application_rejection_message.
 */
struct xmachine_message_application_rejection
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_application_rejection * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_application_rejection2
 * \brief Holds message of type application_rejection2_message.
 */
struct xmachine_message_application_rejection2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_application_rejection2 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_quitting
 * \brief Holds message of type quitting_message.
 */
struct xmachine_message_quitting
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_quitting * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_quitting2
 * \brief Holds message of type quitting2_message.
 */
struct xmachine_message_quitting2
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_quitting2 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_productivity
 * \brief Holds message of type productivity_message.
 */
struct xmachine_message_productivity
{
	int IGfirm_id;	/**< Message memory variable IGfirm_id of type int. */
	double cap_productivity;	/**< Message memory variable cap_productivity of type double. */
	double cap_good_price;	/**< Message memory variable cap_good_price of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_productivity * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_capital_good_request
 * \brief Holds message of type capital_good_request_message.
 */
struct xmachine_message_capital_good_request
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double capital_good_demand;	/**< Message memory variable capital_good_demand of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_capital_good_request * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_capital_good_profit_distribution
 * \brief Holds message of type capital_good_profit_distribution_message.
 */
struct xmachine_message_capital_good_profit_distribution
{
	double capital_good_profit_shares;	/**< Message memory variable capital_good_profit_shares of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_capital_good_profit_distribution * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_capital_good_delivery
 * \brief Holds message of type capital_good_delivery_message.
 */
struct xmachine_message_capital_good_delivery
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double capital_good_delivery_volume;	/**< Message memory variable capital_good_delivery_volume of type double. */
	double productivity;	/**< Message memory variable productivity of type double. */
	double capital_good_price;	/**< Message memory variable capital_good_price of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_capital_good_delivery * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_wage_payment
 * \brief Holds message of type wage_payment_message.
 */
struct xmachine_message_wage_payment
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	double payment;	/**< Message memory variable payment of type double. */
	double productivity;	/**< Message memory variable productivity of type double. */
	double average_specific_skills;	/**< Message memory variable average_specific_skills of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_wage_payment * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_quality_price_info_1
 * \brief Holds message of type quality_price_info_1_message.
 */
struct xmachine_message_quality_price_info_1
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int mall_region_id;	/**< Message memory variable mall_region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
	int available;	/**< Message memory variable available of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_quality_price_info_1 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_quality_price_info_2
 * \brief Holds message of type quality_price_info_2_message.
 */
struct xmachine_message_quality_price_info_2
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int mall_region_id;	/**< Message memory variable mall_region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
	int available;	/**< Message memory variable available of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_quality_price_info_2 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_update_mall_stock
 * \brief Holds message of type update_mall_stock_message.
 */
struct xmachine_message_update_mall_stock
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quantity;	/**< Message memory variable quantity of type double. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_update_mall_stock * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_consumption_request_1
 * \brief Holds message of type consumption_request_1_message.
 */
struct xmachine_message_consumption_request_1
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quantity;	/**< Message memory variable quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_consumption_request_1 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_consumption_request_2
 * \brief Holds message of type consumption_request_2_message.
 */
struct xmachine_message_consumption_request_2
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quantity;	/**< Message memory variable quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_consumption_request_2 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_accepted_consumption_1
 * \brief Holds message of type accepted_consumption_1_message.
 */
struct xmachine_message_accepted_consumption_1
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	double offered_consumption_volume;	/**< Message memory variable offered_consumption_volume of type double. */
	int rationed;	/**< Message memory variable rationed of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_accepted_consumption_1 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_accepted_consumption_2
 * \brief Holds message of type accepted_consumption_2_message.
 */
struct xmachine_message_accepted_consumption_2
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	double offered_consumption_volume;	/**< Message memory variable offered_consumption_volume of type double. */
	int rationed;	/**< Message memory variable rationed of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_accepted_consumption_2 * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_sales
 * \brief Holds message of type sales_message.
 */
struct xmachine_message_sales
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double revenue;	/**< Message memory variable revenue of type double. */
	int stock_empty;	/**< Message memory variable stock_empty of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_sales * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_pay_capital_goods
 * \brief Holds message of type pay_capital_goods_message.
 */
struct xmachine_message_pay_capital_goods
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double capital_bill;	/**< Message memory variable capital_bill of type double. */
	double share_net_investments;	/**< Message memory variable share_net_investments of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_pay_capital_goods * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_current_mall_stock_info
 * \brief Holds message of type current_mall_stock_info_message.
 */
struct xmachine_message_current_mall_stock_info
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double stock;	/**< Message memory variable stock of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_current_mall_stock_info * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_specific_skill_update
 * \brief Holds message of type specific_skill_update_message.
 */
struct xmachine_message_specific_skill_update
{
	int id;	/**< Message memory variable id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double specific_skills;	/**< Message memory variable specific_skills of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_specific_skill_update * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_firm_send_data
 * \brief Holds message of type firm_send_data_message.
 */
struct xmachine_message_firm_send_data
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int vacancies;	/**< Message memory variable vacancies of type int. */
	int employees;	/**< Message memory variable employees of type int. */
	int employees_skill_1;	/**< Message memory variable employees_skill_1 of type int. */
	int employees_skill_2;	/**< Message memory variable employees_skill_2 of type int. */
	int employees_skill_3;	/**< Message memory variable employees_skill_3 of type int. */
	int employees_skill_4;	/**< Message memory variable employees_skill_4 of type int. */
	int employees_skill_5;	/**< Message memory variable employees_skill_5 of type int. */
	double average_wage;	/**< Message memory variable average_wage of type double. */
	double average_s_skill;	/**< Message memory variable average_s_skill of type double. */
	double average_s_skill_1;	/**< Message memory variable average_s_skill_1 of type double. */
	double average_s_skill_2;	/**< Message memory variable average_s_skill_2 of type double. */
	double average_s_skill_3;	/**< Message memory variable average_s_skill_3 of type double. */
	double average_s_skill_4;	/**< Message memory variable average_s_skill_4 of type double. */
	double average_s_skill_5;	/**< Message memory variable average_s_skill_5 of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_firm_send_data * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_household_send_data
 * \brief Holds message of type household_send_data_message.
 */
struct xmachine_message_household_send_data
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	int employment_status;	/**< Message memory variable employment_status of type int. */
	double wage;	/**< Message memory variable wage of type double. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_household_send_data * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_market_research_send_specific_skills
 * \brief Holds message of type market_research_send_specific_skills_message.
 */
struct xmachine_message_market_research_send_specific_skills
{
	int region_id;	/**< Message memory variable region_id of type int. */
	double specific_skill_1;	/**< Message memory variable specific_skill_1 of type double. */
	double specific_skill_2;	/**< Message memory variable specific_skill_2 of type double. */
	double specific_skill_3;	/**< Message memory variable specific_skill_3 of type double. */
	double specific_skill_4;	/**< Message memory variable specific_skill_4 of type double. */
	double specific_skill_5;	/**< Message memory variable specific_skill_5 of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_market_research_send_specific_skills * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_tax_payment
 * \brief Holds message of type tax_payment_message.
 */
struct xmachine_message_tax_payment
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double tax_payment;	/**< Message memory variable tax_payment of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_tax_payment * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_interest_payment
 * \brief Holds message of type interest_payment_message.
 */
struct xmachine_message_interest_payment
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double interest_payment;	/**< Message memory variable interest_payment of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_interest_payment * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_debt_installment_payment
 * \brief Holds message of type debt_installment_payment_message.
 */
struct xmachine_message_debt_installment_payment
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double debt_installment_payment;	/**< Message memory variable debt_installment_payment of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_debt_installment_payment * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_dividend_payment
 * \brief Holds message of type dividend_payment_message.
 */
struct xmachine_message_dividend_payment
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double current_dividend_per_share;	/**< Message memory variable current_dividend_per_share of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_dividend_payment * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_loan_request
 * \brief Holds message of type loan_request_message.
 */
struct xmachine_message_loan_request
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double credit_amount;	/**< Message memory variable credit_amount of type double. */
	double total_assets;	/**< Message memory variable total_assets of type double. */
	double total_debt;	/**< Message memory variable total_debt of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_loan_request * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_loan_conditions
 * \brief Holds message of type loan_conditions_message.
 */
struct xmachine_message_loan_conditions
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double proposed_interest_rate;	/**< Message memory variable proposed_interest_rate of type double. */
	double amount_credit_offer;	/**< Message memory variable amount_credit_offer of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_loan_conditions * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_loan_acceptance
 * \brief Holds message of type loan_acceptance_message.
 */
struct xmachine_message_loan_acceptance
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double credit_amount_taken;	/**< Message memory variable credit_amount_taken of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_loan_acceptance * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_stock_order
 * \brief Holds message of type stock_order_message.
 */
struct xmachine_message_stock_order
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	int stock_id;	/**< Message memory variable stock_id of type int. */
	double limit_price;	/**< Message memory variable limit_price of type double. */
	double limit_quantity;	/**< Message memory variable limit_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_stock_order * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_stock_transaction
 * \brief Holds message of type stock_transaction_message.
 */
struct xmachine_message_stock_transaction
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	int stock_id;	/**< Message memory variable stock_id of type int. */
	double transaction_price;	/**< Message memory variable transaction_price of type double. */
	double transaction_quantity;	/**< Message memory variable transaction_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_stock_transaction * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_bond_order
 * \brief Holds message of type bond_order_message.
 */
struct xmachine_message_bond_order
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	int bond_id;	/**< Message memory variable bond_id of type int. */
	double limit_price;	/**< Message memory variable limit_price of type double. */
	double limit_quantity;	/**< Message memory variable limit_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_bond_order * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_bond_transaction
 * \brief Holds message of type bond_transaction_message.
 */
struct xmachine_message_bond_transaction
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	int bond_id;	/**< Message memory variable bond_id of type int. */
	double transaction_price;	/**< Message memory variable transaction_price of type double. */
	double transaction_quantity;	/**< Message memory variable transaction_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_bond_transaction * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_gov_bond_order
 * \brief Holds message of type gov_bond_order_message.
 */
struct xmachine_message_gov_bond_order
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	int gov_bond_id;	/**< Message memory variable gov_bond_id of type int. */
	double limit_price;	/**< Message memory variable limit_price of type double. */
	double limit_quantity;	/**< Message memory variable limit_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_gov_bond_order * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_gov_bond_transaction
 * \brief Holds message of type gov_bond_transaction_message.
 */
struct xmachine_message_gov_bond_transaction
{
	int trader_id;	/**< Message memory variable trader_id of type int. */
	int gov_bond_id;	/**< Message memory variable gov_bond_id of type int. */
	double transaction_price;	/**< Message memory variable transaction_price of type double. */
	double transaction_quantity;	/**< Message memory variable transaction_quantity of type double. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_gov_bond_transaction * next;	/**< Pointer to next message in the list. */
};


/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm xmachine_memory_Firm;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household xmachine_memory_Household;
/** \var typedef xmachine_memory_Mall xmachine_memory_Mall
 * \brief Typedef for xmachine_memory_Mall struct.
 */
typedef struct xmachine_memory_Mall xmachine_memory_Mall;
/** \var typedef xmachine_memory_IGFirm xmachine_memory_IGFirm
 * \brief Typedef for xmachine_memory_IGFirm struct.
 */
typedef struct xmachine_memory_IGFirm xmachine_memory_IGFirm;
/** \var typedef xmachine_memory_Market_Research xmachine_memory_Market_Research
 * \brief Typedef for xmachine_memory_Market_Research struct.
 */
typedef struct xmachine_memory_Market_Research xmachine_memory_Market_Research;
/** \var typedef xmachine_memory_Clearinghouse xmachine_memory_Clearinghouse
 * \brief Typedef for xmachine_memory_Clearinghouse struct.
 */
typedef struct xmachine_memory_Clearinghouse xmachine_memory_Clearinghouse;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank xmachine_memory_Bank;
/** \typedef xmachine_message_vacancies xmachine_message_vacancies
 * \brief Typedef for xmachine_message_vacancies struct.
 */
typedef struct xmachine_message_vacancies xmachine_message_vacancies;

/** \typedef xmachine_message_vacancies2 xmachine_message_vacancies2
 * \brief Typedef for xmachine_message_vacancies2 struct.
 */
typedef struct xmachine_message_vacancies2 xmachine_message_vacancies2;

/** \typedef xmachine_message_firing xmachine_message_firing
 * \brief Typedef for xmachine_message_firing struct.
 */
typedef struct xmachine_message_firing xmachine_message_firing;

/** \typedef xmachine_message_job_application xmachine_message_job_application
 * \brief Typedef for xmachine_message_job_application struct.
 */
typedef struct xmachine_message_job_application xmachine_message_job_application;

/** \typedef xmachine_message_job_application2 xmachine_message_job_application2
 * \brief Typedef for xmachine_message_job_application2 struct.
 */
typedef struct xmachine_message_job_application2 xmachine_message_job_application2;

/** \typedef xmachine_message_job_offer xmachine_message_job_offer
 * \brief Typedef for xmachine_message_job_offer struct.
 */
typedef struct xmachine_message_job_offer xmachine_message_job_offer;

/** \typedef xmachine_message_job_offer2 xmachine_message_job_offer2
 * \brief Typedef for xmachine_message_job_offer2 struct.
 */
typedef struct xmachine_message_job_offer2 xmachine_message_job_offer2;

/** \typedef xmachine_message_job_acceptance xmachine_message_job_acceptance
 * \brief Typedef for xmachine_message_job_acceptance struct.
 */
typedef struct xmachine_message_job_acceptance xmachine_message_job_acceptance;

/** \typedef xmachine_message_job_acceptance2 xmachine_message_job_acceptance2
 * \brief Typedef for xmachine_message_job_acceptance2 struct.
 */
typedef struct xmachine_message_job_acceptance2 xmachine_message_job_acceptance2;

/** \typedef xmachine_message_application_rejection xmachine_message_application_rejection
 * \brief Typedef for xmachine_message_application_rejection struct.
 */
typedef struct xmachine_message_application_rejection xmachine_message_application_rejection;

/** \typedef xmachine_message_application_rejection2 xmachine_message_application_rejection2
 * \brief Typedef for xmachine_message_application_rejection2 struct.
 */
typedef struct xmachine_message_application_rejection2 xmachine_message_application_rejection2;

/** \typedef xmachine_message_quitting xmachine_message_quitting
 * \brief Typedef for xmachine_message_quitting struct.
 */
typedef struct xmachine_message_quitting xmachine_message_quitting;

/** \typedef xmachine_message_quitting2 xmachine_message_quitting2
 * \brief Typedef for xmachine_message_quitting2 struct.
 */
typedef struct xmachine_message_quitting2 xmachine_message_quitting2;

/** \typedef xmachine_message_productivity xmachine_message_productivity
 * \brief Typedef for xmachine_message_productivity struct.
 */
typedef struct xmachine_message_productivity xmachine_message_productivity;

/** \typedef xmachine_message_capital_good_request xmachine_message_capital_good_request
 * \brief Typedef for xmachine_message_capital_good_request struct.
 */
typedef struct xmachine_message_capital_good_request xmachine_message_capital_good_request;

/** \typedef xmachine_message_capital_good_profit_distribution xmachine_message_capital_good_profit_distribution
 * \brief Typedef for xmachine_message_capital_good_profit_distribution struct.
 */
typedef struct xmachine_message_capital_good_profit_distribution xmachine_message_capital_good_profit_distribution;

/** \typedef xmachine_message_capital_good_delivery xmachine_message_capital_good_delivery
 * \brief Typedef for xmachine_message_capital_good_delivery struct.
 */
typedef struct xmachine_message_capital_good_delivery xmachine_message_capital_good_delivery;

/** \typedef xmachine_message_wage_payment xmachine_message_wage_payment
 * \brief Typedef for xmachine_message_wage_payment struct.
 */
typedef struct xmachine_message_wage_payment xmachine_message_wage_payment;

/** \typedef xmachine_message_quality_price_info_1 xmachine_message_quality_price_info_1
 * \brief Typedef for xmachine_message_quality_price_info_1 struct.
 */
typedef struct xmachine_message_quality_price_info_1 xmachine_message_quality_price_info_1;

/** \typedef xmachine_message_quality_price_info_2 xmachine_message_quality_price_info_2
 * \brief Typedef for xmachine_message_quality_price_info_2 struct.
 */
typedef struct xmachine_message_quality_price_info_2 xmachine_message_quality_price_info_2;

/** \typedef xmachine_message_update_mall_stock xmachine_message_update_mall_stock
 * \brief Typedef for xmachine_message_update_mall_stock struct.
 */
typedef struct xmachine_message_update_mall_stock xmachine_message_update_mall_stock;

/** \typedef xmachine_message_consumption_request_1 xmachine_message_consumption_request_1
 * \brief Typedef for xmachine_message_consumption_request_1 struct.
 */
typedef struct xmachine_message_consumption_request_1 xmachine_message_consumption_request_1;

/** \typedef xmachine_message_consumption_request_2 xmachine_message_consumption_request_2
 * \brief Typedef for xmachine_message_consumption_request_2 struct.
 */
typedef struct xmachine_message_consumption_request_2 xmachine_message_consumption_request_2;

/** \typedef xmachine_message_accepted_consumption_1 xmachine_message_accepted_consumption_1
 * \brief Typedef for xmachine_message_accepted_consumption_1 struct.
 */
typedef struct xmachine_message_accepted_consumption_1 xmachine_message_accepted_consumption_1;

/** \typedef xmachine_message_accepted_consumption_2 xmachine_message_accepted_consumption_2
 * \brief Typedef for xmachine_message_accepted_consumption_2 struct.
 */
typedef struct xmachine_message_accepted_consumption_2 xmachine_message_accepted_consumption_2;

/** \typedef xmachine_message_sales xmachine_message_sales
 * \brief Typedef for xmachine_message_sales struct.
 */
typedef struct xmachine_message_sales xmachine_message_sales;

/** \typedef xmachine_message_pay_capital_goods xmachine_message_pay_capital_goods
 * \brief Typedef for xmachine_message_pay_capital_goods struct.
 */
typedef struct xmachine_message_pay_capital_goods xmachine_message_pay_capital_goods;

/** \typedef xmachine_message_current_mall_stock_info xmachine_message_current_mall_stock_info
 * \brief Typedef for xmachine_message_current_mall_stock_info struct.
 */
typedef struct xmachine_message_current_mall_stock_info xmachine_message_current_mall_stock_info;

/** \typedef xmachine_message_specific_skill_update xmachine_message_specific_skill_update
 * \brief Typedef for xmachine_message_specific_skill_update struct.
 */
typedef struct xmachine_message_specific_skill_update xmachine_message_specific_skill_update;

/** \typedef xmachine_message_firm_send_data xmachine_message_firm_send_data
 * \brief Typedef for xmachine_message_firm_send_data struct.
 */
typedef struct xmachine_message_firm_send_data xmachine_message_firm_send_data;

/** \typedef xmachine_message_household_send_data xmachine_message_household_send_data
 * \brief Typedef for xmachine_message_household_send_data struct.
 */
typedef struct xmachine_message_household_send_data xmachine_message_household_send_data;

/** \typedef xmachine_message_market_research_send_specific_skills xmachine_message_market_research_send_specific_skills
 * \brief Typedef for xmachine_message_market_research_send_specific_skills struct.
 */
typedef struct xmachine_message_market_research_send_specific_skills xmachine_message_market_research_send_specific_skills;

/** \typedef xmachine_message_tax_payment xmachine_message_tax_payment
 * \brief Typedef for xmachine_message_tax_payment struct.
 */
typedef struct xmachine_message_tax_payment xmachine_message_tax_payment;

/** \typedef xmachine_message_interest_payment xmachine_message_interest_payment
 * \brief Typedef for xmachine_message_interest_payment struct.
 */
typedef struct xmachine_message_interest_payment xmachine_message_interest_payment;

/** \typedef xmachine_message_debt_installment_payment xmachine_message_debt_installment_payment
 * \brief Typedef for xmachine_message_debt_installment_payment struct.
 */
typedef struct xmachine_message_debt_installment_payment xmachine_message_debt_installment_payment;

/** \typedef xmachine_message_dividend_payment xmachine_message_dividend_payment
 * \brief Typedef for xmachine_message_dividend_payment struct.
 */
typedef struct xmachine_message_dividend_payment xmachine_message_dividend_payment;

/** \typedef xmachine_message_loan_request xmachine_message_loan_request
 * \brief Typedef for xmachine_message_loan_request struct.
 */
typedef struct xmachine_message_loan_request xmachine_message_loan_request;

/** \typedef xmachine_message_loan_conditions xmachine_message_loan_conditions
 * \brief Typedef for xmachine_message_loan_conditions struct.
 */
typedef struct xmachine_message_loan_conditions xmachine_message_loan_conditions;

/** \typedef xmachine_message_loan_acceptance xmachine_message_loan_acceptance
 * \brief Typedef for xmachine_message_loan_acceptance struct.
 */
typedef struct xmachine_message_loan_acceptance xmachine_message_loan_acceptance;

/** \typedef xmachine_message_stock_order xmachine_message_stock_order
 * \brief Typedef for xmachine_message_stock_order struct.
 */
typedef struct xmachine_message_stock_order xmachine_message_stock_order;

/** \typedef xmachine_message_stock_transaction xmachine_message_stock_transaction
 * \brief Typedef for xmachine_message_stock_transaction struct.
 */
typedef struct xmachine_message_stock_transaction xmachine_message_stock_transaction;

/** \typedef xmachine_message_bond_order xmachine_message_bond_order
 * \brief Typedef for xmachine_message_bond_order struct.
 */
typedef struct xmachine_message_bond_order xmachine_message_bond_order;

/** \typedef xmachine_message_bond_transaction xmachine_message_bond_transaction
 * \brief Typedef for xmachine_message_bond_transaction struct.
 */
typedef struct xmachine_message_bond_transaction xmachine_message_bond_transaction;

/** \typedef xmachine_message_gov_bond_order xmachine_message_gov_bond_order
 * \brief Typedef for xmachine_message_gov_bond_order struct.
 */
typedef struct xmachine_message_gov_bond_order xmachine_message_gov_bond_order;

/** \typedef xmachine_message_gov_bond_transaction xmachine_message_gov_bond_transaction
 * \brief Typedef for xmachine_message_gov_bond_transaction struct.
 */
typedef struct xmachine_message_gov_bond_transaction xmachine_message_gov_bond_transaction;


int Firm_calculate_specific_skills_and_wage_offer(void);
int Firm_send_vacancies(void);
int Firm_send_redundancies(void);
int Firm_read_job_applications_send_job_offer_or_rejection(void);
int Firm_read_job_responses(void);
int Firm_update_wage_offer(void);
int Firm_send_vacancies_2(void);
int Firm_read_job_applications_send_job_offer_or_rejection_2(void);
int Firm_read_job_responses_2(void);
int Firm_update_wage_offer_2(void);
int Firm_update_specific_skills_of_workers(void);
int Firm_send_data_to_Market_Research(void);
int Firm_calc_production_quantity(void);
int Firm_calc_input_demands(void);
int Firm_send_capital_demand(void);
int Firm_calc_pay_costs(void);
int Firm_send_goods_to_mall(void);
int Firm_calc_revenue(void);
int Firm_calc_production_quantity_2(void);
int Firm_calc_input_demands_2(void);
int Firm_compute_payout_policy(void);
int Firm_compute_income_statement(void);
int Firm_compute_balance_sheet(void);
int Firm_apply_for_loans(void);
int Firm_read_loan_offers_send_loan_acceptance(void);
int Firm_compute_and_send_bond_orders(void);
int Firm_read_bond_transactions(void);
int Firm_compute_and_send_stock_orders(void);
int Firm_read_stock_transactions(void);
int Firm_compute_and_send_gov_bond_orders(void);
int Firm_read_gov_bond_transactions(void);
int Household_read_firing_messages(void);
int Household_on_the_job_search_Yes_or_No(void);
int Household_read_job_vacancies_and_send_applications(void);
int Household_read_job_offers_send_response(void);
int Household_read_application_rejection_update_wage_reservation(void);
int Household_read_job_vacancies_and_send_applications_2(void);
int Household_read_job_offers_send_response_2(void);
int Household_read_application_rejection_update_wage_reservation_2(void);
int Household_receive_wage(void);
int Household_rank_and_buy_goods_1(void);
int Household_rank_and_buy_goods_2(void);
int Household_read_rationing(void);
int Household_handle_leftover_budget(void);
int Household_send_data_to_Market_Research(void);
int Mall_send_current_stocks(void);
int Mall_update_mall_stock(void);
int Mall_send_quality_price_info_1(void);
int Mall_update_mall_stocks_sales_rationing_1(void);
int Mall_update_mall_stocks_sales_rationing_2(void);
int Mall_pay_firm(void);
int IGFirm_update_productivity_price(void);
int IGFirm_send_capital_good(void);
int IGFirm_receive_payment(void);
int Market_Research_calculate_data(void);
int Market_Research_send_data(void);
int Clearinghouse_read_stock_orders(void);
int Clearinghouse_compute_stock_transactions(void);
int Clearinghouse_send_stock_transactions(void);
int Clearinghouse_read_bond_orders(void);
int Clearinghouse_compute_bond_transactions(void);
int Clearinghouse_send_bond_transactions(void);
int Clearinghouse_read_gov_bond_orders(void);
int Clearinghouse_compute_gov_bond_transactions(void);
int Clearinghouse_send_gov_bond_transactions(void);
int Bank_read_loan_request_send_offers(void);

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
	struct xmachine_message_vacancies * vacancies_messages;	/**< Pointer to vacancies message list. */
	struct xmachine_message_vacancies2 * vacancies2_messages;	/**< Pointer to vacancies2 message list. */
	struct xmachine_message_firing * firing_messages;	/**< Pointer to firing message list. */
	struct xmachine_message_job_application * job_application_messages;	/**< Pointer to job_application message list. */
	struct xmachine_message_job_application2 * job_application2_messages;	/**< Pointer to job_application2 message list. */
	struct xmachine_message_job_offer * job_offer_messages;	/**< Pointer to job_offer message list. */
	struct xmachine_message_job_offer2 * job_offer2_messages;	/**< Pointer to job_offer2 message list. */
	struct xmachine_message_job_acceptance * job_acceptance_messages;	/**< Pointer to job_acceptance message list. */
	struct xmachine_message_job_acceptance2 * job_acceptance2_messages;	/**< Pointer to job_acceptance2 message list. */
	struct xmachine_message_application_rejection * application_rejection_messages;	/**< Pointer to application_rejection message list. */
	struct xmachine_message_application_rejection2 * application_rejection2_messages;	/**< Pointer to application_rejection2 message list. */
	struct xmachine_message_quitting * quitting_messages;	/**< Pointer to quitting message list. */
	struct xmachine_message_quitting2 * quitting2_messages;	/**< Pointer to quitting2 message list. */
	struct xmachine_message_productivity * productivity_messages;	/**< Pointer to productivity message list. */
	struct xmachine_message_capital_good_request * capital_good_request_messages;	/**< Pointer to capital_good_request message list. */
	struct xmachine_message_capital_good_profit_distribution * capital_good_profit_distribution_messages;	/**< Pointer to capital_good_profit_distribution message list. */
	struct xmachine_message_capital_good_delivery * capital_good_delivery_messages;	/**< Pointer to capital_good_delivery message list. */
	struct xmachine_message_wage_payment * wage_payment_messages;	/**< Pointer to wage_payment message list. */
	struct xmachine_message_quality_price_info_1 * quality_price_info_1_messages;	/**< Pointer to quality_price_info_1 message list. */
	struct xmachine_message_quality_price_info_2 * quality_price_info_2_messages;	/**< Pointer to quality_price_info_2 message list. */
	struct xmachine_message_update_mall_stock * update_mall_stock_messages;	/**< Pointer to update_mall_stock message list. */
	struct xmachine_message_consumption_request_1 * consumption_request_1_messages;	/**< Pointer to consumption_request_1 message list. */
	struct xmachine_message_consumption_request_2 * consumption_request_2_messages;	/**< Pointer to consumption_request_2 message list. */
	struct xmachine_message_accepted_consumption_1 * accepted_consumption_1_messages;	/**< Pointer to accepted_consumption_1 message list. */
	struct xmachine_message_accepted_consumption_2 * accepted_consumption_2_messages;	/**< Pointer to accepted_consumption_2 message list. */
	struct xmachine_message_sales * sales_messages;	/**< Pointer to sales message list. */
	struct xmachine_message_pay_capital_goods * pay_capital_goods_messages;	/**< Pointer to pay_capital_goods message list. */
	struct xmachine_message_current_mall_stock_info * current_mall_stock_info_messages;	/**< Pointer to current_mall_stock_info message list. */
	struct xmachine_message_specific_skill_update * specific_skill_update_messages;	/**< Pointer to specific_skill_update message list. */
	struct xmachine_message_firm_send_data * firm_send_data_messages;	/**< Pointer to firm_send_data message list. */
	struct xmachine_message_household_send_data * household_send_data_messages;	/**< Pointer to household_send_data message list. */
	struct xmachine_message_market_research_send_specific_skills * market_research_send_specific_skills_messages;	/**< Pointer to market_research_send_specific_skills message list. */
	struct xmachine_message_tax_payment * tax_payment_messages;	/**< Pointer to tax_payment message list. */
	struct xmachine_message_interest_payment * interest_payment_messages;	/**< Pointer to interest_payment message list. */
	struct xmachine_message_debt_installment_payment * debt_installment_payment_messages;	/**< Pointer to debt_installment_payment message list. */
	struct xmachine_message_dividend_payment * dividend_payment_messages;	/**< Pointer to dividend_payment message list. */
	struct xmachine_message_loan_request * loan_request_messages;	/**< Pointer to loan_request message list. */
	struct xmachine_message_loan_conditions * loan_conditions_messages;	/**< Pointer to loan_conditions message list. */
	struct xmachine_message_loan_acceptance * loan_acceptance_messages;	/**< Pointer to loan_acceptance message list. */
	struct xmachine_message_stock_order * stock_order_messages;	/**< Pointer to stock_order message list. */
	struct xmachine_message_stock_transaction * stock_transaction_messages;	/**< Pointer to stock_transaction message list. */
	struct xmachine_message_bond_order * bond_order_messages;	/**< Pointer to bond_order message list. */
	struct xmachine_message_bond_transaction * bond_transaction_messages;	/**< Pointer to bond_transaction message list. */
	struct xmachine_message_gov_bond_order * gov_bond_order_messages;	/**< Pointer to gov_bond_order message list. */
	struct xmachine_message_gov_bond_transaction * gov_bond_transaction_messages;	/**< Pointer to gov_bond_transaction message list. */
	
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

/** \var xmachine_message_vacancies * temp_vacancies_message
* \brief Pointer to xmachine_message_vacancies to initialise linked list. */
xmachine_message_vacancies * temp_vacancies_message;
/** \var xmachine_message_vacancies2 * temp_vacancies2_message
* \brief Pointer to xmachine_message_vacancies2 to initialise linked list. */
xmachine_message_vacancies2 * temp_vacancies2_message;
/** \var xmachine_message_firing * temp_firing_message
* \brief Pointer to xmachine_message_firing to initialise linked list. */
xmachine_message_firing * temp_firing_message;
/** \var xmachine_message_job_application * temp_job_application_message
* \brief Pointer to xmachine_message_job_application to initialise linked list. */
xmachine_message_job_application * temp_job_application_message;
/** \var xmachine_message_job_application2 * temp_job_application2_message
* \brief Pointer to xmachine_message_job_application2 to initialise linked list. */
xmachine_message_job_application2 * temp_job_application2_message;
/** \var xmachine_message_job_offer * temp_job_offer_message
* \brief Pointer to xmachine_message_job_offer to initialise linked list. */
xmachine_message_job_offer * temp_job_offer_message;
/** \var xmachine_message_job_offer2 * temp_job_offer2_message
* \brief Pointer to xmachine_message_job_offer2 to initialise linked list. */
xmachine_message_job_offer2 * temp_job_offer2_message;
/** \var xmachine_message_job_acceptance * temp_job_acceptance_message
* \brief Pointer to xmachine_message_job_acceptance to initialise linked list. */
xmachine_message_job_acceptance * temp_job_acceptance_message;
/** \var xmachine_message_job_acceptance2 * temp_job_acceptance2_message
* \brief Pointer to xmachine_message_job_acceptance2 to initialise linked list. */
xmachine_message_job_acceptance2 * temp_job_acceptance2_message;
/** \var xmachine_message_application_rejection * temp_application_rejection_message
* \brief Pointer to xmachine_message_application_rejection to initialise linked list. */
xmachine_message_application_rejection * temp_application_rejection_message;
/** \var xmachine_message_application_rejection2 * temp_application_rejection2_message
* \brief Pointer to xmachine_message_application_rejection2 to initialise linked list. */
xmachine_message_application_rejection2 * temp_application_rejection2_message;
/** \var xmachine_message_quitting * temp_quitting_message
* \brief Pointer to xmachine_message_quitting to initialise linked list. */
xmachine_message_quitting * temp_quitting_message;
/** \var xmachine_message_quitting2 * temp_quitting2_message
* \brief Pointer to xmachine_message_quitting2 to initialise linked list. */
xmachine_message_quitting2 * temp_quitting2_message;
/** \var xmachine_message_productivity * temp_productivity_message
* \brief Pointer to xmachine_message_productivity to initialise linked list. */
xmachine_message_productivity * temp_productivity_message;
/** \var xmachine_message_capital_good_request * temp_capital_good_request_message
* \brief Pointer to xmachine_message_capital_good_request to initialise linked list. */
xmachine_message_capital_good_request * temp_capital_good_request_message;
/** \var xmachine_message_capital_good_profit_distribution * temp_capital_good_profit_distribution_message
* \brief Pointer to xmachine_message_capital_good_profit_distribution to initialise linked list. */
xmachine_message_capital_good_profit_distribution * temp_capital_good_profit_distribution_message;
/** \var xmachine_message_capital_good_delivery * temp_capital_good_delivery_message
* \brief Pointer to xmachine_message_capital_good_delivery to initialise linked list. */
xmachine_message_capital_good_delivery * temp_capital_good_delivery_message;
/** \var xmachine_message_wage_payment * temp_wage_payment_message
* \brief Pointer to xmachine_message_wage_payment to initialise linked list. */
xmachine_message_wage_payment * temp_wage_payment_message;
/** \var xmachine_message_quality_price_info_1 * temp_quality_price_info_1_message
* \brief Pointer to xmachine_message_quality_price_info_1 to initialise linked list. */
xmachine_message_quality_price_info_1 * temp_quality_price_info_1_message;
/** \var xmachine_message_quality_price_info_2 * temp_quality_price_info_2_message
* \brief Pointer to xmachine_message_quality_price_info_2 to initialise linked list. */
xmachine_message_quality_price_info_2 * temp_quality_price_info_2_message;
/** \var xmachine_message_update_mall_stock * temp_update_mall_stock_message
* \brief Pointer to xmachine_message_update_mall_stock to initialise linked list. */
xmachine_message_update_mall_stock * temp_update_mall_stock_message;
/** \var xmachine_message_consumption_request_1 * temp_consumption_request_1_message
* \brief Pointer to xmachine_message_consumption_request_1 to initialise linked list. */
xmachine_message_consumption_request_1 * temp_consumption_request_1_message;
/** \var xmachine_message_consumption_request_2 * temp_consumption_request_2_message
* \brief Pointer to xmachine_message_consumption_request_2 to initialise linked list. */
xmachine_message_consumption_request_2 * temp_consumption_request_2_message;
/** \var xmachine_message_accepted_consumption_1 * temp_accepted_consumption_1_message
* \brief Pointer to xmachine_message_accepted_consumption_1 to initialise linked list. */
xmachine_message_accepted_consumption_1 * temp_accepted_consumption_1_message;
/** \var xmachine_message_accepted_consumption_2 * temp_accepted_consumption_2_message
* \brief Pointer to xmachine_message_accepted_consumption_2 to initialise linked list. */
xmachine_message_accepted_consumption_2 * temp_accepted_consumption_2_message;
/** \var xmachine_message_sales * temp_sales_message
* \brief Pointer to xmachine_message_sales to initialise linked list. */
xmachine_message_sales * temp_sales_message;
/** \var xmachine_message_pay_capital_goods * temp_pay_capital_goods_message
* \brief Pointer to xmachine_message_pay_capital_goods to initialise linked list. */
xmachine_message_pay_capital_goods * temp_pay_capital_goods_message;
/** \var xmachine_message_current_mall_stock_info * temp_current_mall_stock_info_message
* \brief Pointer to xmachine_message_current_mall_stock_info to initialise linked list. */
xmachine_message_current_mall_stock_info * temp_current_mall_stock_info_message;
/** \var xmachine_message_specific_skill_update * temp_specific_skill_update_message
* \brief Pointer to xmachine_message_specific_skill_update to initialise linked list. */
xmachine_message_specific_skill_update * temp_specific_skill_update_message;
/** \var xmachine_message_firm_send_data * temp_firm_send_data_message
* \brief Pointer to xmachine_message_firm_send_data to initialise linked list. */
xmachine_message_firm_send_data * temp_firm_send_data_message;
/** \var xmachine_message_household_send_data * temp_household_send_data_message
* \brief Pointer to xmachine_message_household_send_data to initialise linked list. */
xmachine_message_household_send_data * temp_household_send_data_message;
/** \var xmachine_message_market_research_send_specific_skills * temp_market_research_send_specific_skills_message
* \brief Pointer to xmachine_message_market_research_send_specific_skills to initialise linked list. */
xmachine_message_market_research_send_specific_skills * temp_market_research_send_specific_skills_message;
/** \var xmachine_message_tax_payment * temp_tax_payment_message
* \brief Pointer to xmachine_message_tax_payment to initialise linked list. */
xmachine_message_tax_payment * temp_tax_payment_message;
/** \var xmachine_message_interest_payment * temp_interest_payment_message
* \brief Pointer to xmachine_message_interest_payment to initialise linked list. */
xmachine_message_interest_payment * temp_interest_payment_message;
/** \var xmachine_message_debt_installment_payment * temp_debt_installment_payment_message
* \brief Pointer to xmachine_message_debt_installment_payment to initialise linked list. */
xmachine_message_debt_installment_payment * temp_debt_installment_payment_message;
/** \var xmachine_message_dividend_payment * temp_dividend_payment_message
* \brief Pointer to xmachine_message_dividend_payment to initialise linked list. */
xmachine_message_dividend_payment * temp_dividend_payment_message;
/** \var xmachine_message_loan_request * temp_loan_request_message
* \brief Pointer to xmachine_message_loan_request to initialise linked list. */
xmachine_message_loan_request * temp_loan_request_message;
/** \var xmachine_message_loan_conditions * temp_loan_conditions_message
* \brief Pointer to xmachine_message_loan_conditions to initialise linked list. */
xmachine_message_loan_conditions * temp_loan_conditions_message;
/** \var xmachine_message_loan_acceptance * temp_loan_acceptance_message
* \brief Pointer to xmachine_message_loan_acceptance to initialise linked list. */
xmachine_message_loan_acceptance * temp_loan_acceptance_message;
/** \var xmachine_message_stock_order * temp_stock_order_message
* \brief Pointer to xmachine_message_stock_order to initialise linked list. */
xmachine_message_stock_order * temp_stock_order_message;
/** \var xmachine_message_stock_transaction * temp_stock_transaction_message
* \brief Pointer to xmachine_message_stock_transaction to initialise linked list. */
xmachine_message_stock_transaction * temp_stock_transaction_message;
/** \var xmachine_message_bond_order * temp_bond_order_message
* \brief Pointer to xmachine_message_bond_order to initialise linked list. */
xmachine_message_bond_order * temp_bond_order_message;
/** \var xmachine_message_bond_transaction * temp_bond_transaction_message
* \brief Pointer to xmachine_message_bond_transaction to initialise linked list. */
xmachine_message_bond_transaction * temp_bond_transaction_message;
/** \var xmachine_message_gov_bond_order * temp_gov_bond_order_message
* \brief Pointer to xmachine_message_gov_bond_order to initialise linked list. */
xmachine_message_gov_bond_order * temp_gov_bond_order_message;
/** \var xmachine_message_gov_bond_transaction * temp_gov_bond_transaction_message
* \brief Pointer to xmachine_message_gov_bond_transaction to initialise linked list. */
xmachine_message_gov_bond_transaction * temp_gov_bond_transaction_message;
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

/** \var xmachine_message_vacancies ** p_vacancies_message
* \brief Pointer to first pointer of vacancies message list */
xmachine_message_vacancies ** p_vacancies_message;
/** \var xmachine_message_vacancies2 ** p_vacancies2_message
* \brief Pointer to first pointer of vacancies2 message list */
xmachine_message_vacancies2 ** p_vacancies2_message;
/** \var xmachine_message_firing ** p_firing_message
* \brief Pointer to first pointer of firing message list */
xmachine_message_firing ** p_firing_message;
/** \var xmachine_message_job_application ** p_job_application_message
* \brief Pointer to first pointer of job_application message list */
xmachine_message_job_application ** p_job_application_message;
/** \var xmachine_message_job_application2 ** p_job_application2_message
* \brief Pointer to first pointer of job_application2 message list */
xmachine_message_job_application2 ** p_job_application2_message;
/** \var xmachine_message_job_offer ** p_job_offer_message
* \brief Pointer to first pointer of job_offer message list */
xmachine_message_job_offer ** p_job_offer_message;
/** \var xmachine_message_job_offer2 ** p_job_offer2_message
* \brief Pointer to first pointer of job_offer2 message list */
xmachine_message_job_offer2 ** p_job_offer2_message;
/** \var xmachine_message_job_acceptance ** p_job_acceptance_message
* \brief Pointer to first pointer of job_acceptance message list */
xmachine_message_job_acceptance ** p_job_acceptance_message;
/** \var xmachine_message_job_acceptance2 ** p_job_acceptance2_message
* \brief Pointer to first pointer of job_acceptance2 message list */
xmachine_message_job_acceptance2 ** p_job_acceptance2_message;
/** \var xmachine_message_application_rejection ** p_application_rejection_message
* \brief Pointer to first pointer of application_rejection message list */
xmachine_message_application_rejection ** p_application_rejection_message;
/** \var xmachine_message_application_rejection2 ** p_application_rejection2_message
* \brief Pointer to first pointer of application_rejection2 message list */
xmachine_message_application_rejection2 ** p_application_rejection2_message;
/** \var xmachine_message_quitting ** p_quitting_message
* \brief Pointer to first pointer of quitting message list */
xmachine_message_quitting ** p_quitting_message;
/** \var xmachine_message_quitting2 ** p_quitting2_message
* \brief Pointer to first pointer of quitting2 message list */
xmachine_message_quitting2 ** p_quitting2_message;
/** \var xmachine_message_productivity ** p_productivity_message
* \brief Pointer to first pointer of productivity message list */
xmachine_message_productivity ** p_productivity_message;
/** \var xmachine_message_capital_good_request ** p_capital_good_request_message
* \brief Pointer to first pointer of capital_good_request message list */
xmachine_message_capital_good_request ** p_capital_good_request_message;
/** \var xmachine_message_capital_good_profit_distribution ** p_capital_good_profit_distribution_message
* \brief Pointer to first pointer of capital_good_profit_distribution message list */
xmachine_message_capital_good_profit_distribution ** p_capital_good_profit_distribution_message;
/** \var xmachine_message_capital_good_delivery ** p_capital_good_delivery_message
* \brief Pointer to first pointer of capital_good_delivery message list */
xmachine_message_capital_good_delivery ** p_capital_good_delivery_message;
/** \var xmachine_message_wage_payment ** p_wage_payment_message
* \brief Pointer to first pointer of wage_payment message list */
xmachine_message_wage_payment ** p_wage_payment_message;
/** \var xmachine_message_quality_price_info_1 ** p_quality_price_info_1_message
* \brief Pointer to first pointer of quality_price_info_1 message list */
xmachine_message_quality_price_info_1 ** p_quality_price_info_1_message;
/** \var xmachine_message_quality_price_info_2 ** p_quality_price_info_2_message
* \brief Pointer to first pointer of quality_price_info_2 message list */
xmachine_message_quality_price_info_2 ** p_quality_price_info_2_message;
/** \var xmachine_message_update_mall_stock ** p_update_mall_stock_message
* \brief Pointer to first pointer of update_mall_stock message list */
xmachine_message_update_mall_stock ** p_update_mall_stock_message;
/** \var xmachine_message_consumption_request_1 ** p_consumption_request_1_message
* \brief Pointer to first pointer of consumption_request_1 message list */
xmachine_message_consumption_request_1 ** p_consumption_request_1_message;
/** \var xmachine_message_consumption_request_2 ** p_consumption_request_2_message
* \brief Pointer to first pointer of consumption_request_2 message list */
xmachine_message_consumption_request_2 ** p_consumption_request_2_message;
/** \var xmachine_message_accepted_consumption_1 ** p_accepted_consumption_1_message
* \brief Pointer to first pointer of accepted_consumption_1 message list */
xmachine_message_accepted_consumption_1 ** p_accepted_consumption_1_message;
/** \var xmachine_message_accepted_consumption_2 ** p_accepted_consumption_2_message
* \brief Pointer to first pointer of accepted_consumption_2 message list */
xmachine_message_accepted_consumption_2 ** p_accepted_consumption_2_message;
/** \var xmachine_message_sales ** p_sales_message
* \brief Pointer to first pointer of sales message list */
xmachine_message_sales ** p_sales_message;
/** \var xmachine_message_pay_capital_goods ** p_pay_capital_goods_message
* \brief Pointer to first pointer of pay_capital_goods message list */
xmachine_message_pay_capital_goods ** p_pay_capital_goods_message;
/** \var xmachine_message_current_mall_stock_info ** p_current_mall_stock_info_message
* \brief Pointer to first pointer of current_mall_stock_info message list */
xmachine_message_current_mall_stock_info ** p_current_mall_stock_info_message;
/** \var xmachine_message_specific_skill_update ** p_specific_skill_update_message
* \brief Pointer to first pointer of specific_skill_update message list */
xmachine_message_specific_skill_update ** p_specific_skill_update_message;
/** \var xmachine_message_firm_send_data ** p_firm_send_data_message
* \brief Pointer to first pointer of firm_send_data message list */
xmachine_message_firm_send_data ** p_firm_send_data_message;
/** \var xmachine_message_household_send_data ** p_household_send_data_message
* \brief Pointer to first pointer of household_send_data message list */
xmachine_message_household_send_data ** p_household_send_data_message;
/** \var xmachine_message_market_research_send_specific_skills ** p_market_research_send_specific_skills_message
* \brief Pointer to first pointer of market_research_send_specific_skills message list */
xmachine_message_market_research_send_specific_skills ** p_market_research_send_specific_skills_message;
/** \var xmachine_message_tax_payment ** p_tax_payment_message
* \brief Pointer to first pointer of tax_payment message list */
xmachine_message_tax_payment ** p_tax_payment_message;
/** \var xmachine_message_interest_payment ** p_interest_payment_message
* \brief Pointer to first pointer of interest_payment message list */
xmachine_message_interest_payment ** p_interest_payment_message;
/** \var xmachine_message_debt_installment_payment ** p_debt_installment_payment_message
* \brief Pointer to first pointer of debt_installment_payment message list */
xmachine_message_debt_installment_payment ** p_debt_installment_payment_message;
/** \var xmachine_message_dividend_payment ** p_dividend_payment_message
* \brief Pointer to first pointer of dividend_payment message list */
xmachine_message_dividend_payment ** p_dividend_payment_message;
/** \var xmachine_message_loan_request ** p_loan_request_message
* \brief Pointer to first pointer of loan_request message list */
xmachine_message_loan_request ** p_loan_request_message;
/** \var xmachine_message_loan_conditions ** p_loan_conditions_message
* \brief Pointer to first pointer of loan_conditions message list */
xmachine_message_loan_conditions ** p_loan_conditions_message;
/** \var xmachine_message_loan_acceptance ** p_loan_acceptance_message
* \brief Pointer to first pointer of loan_acceptance message list */
xmachine_message_loan_acceptance ** p_loan_acceptance_message;
/** \var xmachine_message_stock_order ** p_stock_order_message
* \brief Pointer to first pointer of stock_order message list */
xmachine_message_stock_order ** p_stock_order_message;
/** \var xmachine_message_stock_transaction ** p_stock_transaction_message
* \brief Pointer to first pointer of stock_transaction message list */
xmachine_message_stock_transaction ** p_stock_transaction_message;
/** \var xmachine_message_bond_order ** p_bond_order_message
* \brief Pointer to first pointer of bond_order message list */
xmachine_message_bond_order ** p_bond_order_message;
/** \var xmachine_message_bond_transaction ** p_bond_transaction_message
* \brief Pointer to first pointer of bond_transaction message list */
xmachine_message_bond_transaction ** p_bond_transaction_message;
/** \var xmachine_message_gov_bond_order ** p_gov_bond_order_message
* \brief Pointer to first pointer of gov_bond_order message list */
xmachine_message_gov_bond_order ** p_gov_bond_order_message;
/** \var xmachine_message_gov_bond_transaction ** p_gov_bond_transaction_message
* \brief Pointer to first pointer of gov_bond_transaction message list */
xmachine_message_gov_bond_transaction ** p_gov_bond_transaction_message;

/** \var xmachine_message_vacancies * vacancies_message
* \brief Pointer to message struct for looping through vacancies message list */
xmachine_message_vacancies * vacancies_message;
/** \var xmachine_message_vacancies2 * vacancies2_message
* \brief Pointer to message struct for looping through vacancies2 message list */
xmachine_message_vacancies2 * vacancies2_message;
/** \var xmachine_message_firing * firing_message
* \brief Pointer to message struct for looping through firing message list */
xmachine_message_firing * firing_message;
/** \var xmachine_message_job_application * job_application_message
* \brief Pointer to message struct for looping through job_application message list */
xmachine_message_job_application * job_application_message;
/** \var xmachine_message_job_application2 * job_application2_message
* \brief Pointer to message struct for looping through job_application2 message list */
xmachine_message_job_application2 * job_application2_message;
/** \var xmachine_message_job_offer * job_offer_message
* \brief Pointer to message struct for looping through job_offer message list */
xmachine_message_job_offer * job_offer_message;
/** \var xmachine_message_job_offer2 * job_offer2_message
* \brief Pointer to message struct for looping through job_offer2 message list */
xmachine_message_job_offer2 * job_offer2_message;
/** \var xmachine_message_job_acceptance * job_acceptance_message
* \brief Pointer to message struct for looping through job_acceptance message list */
xmachine_message_job_acceptance * job_acceptance_message;
/** \var xmachine_message_job_acceptance2 * job_acceptance2_message
* \brief Pointer to message struct for looping through job_acceptance2 message list */
xmachine_message_job_acceptance2 * job_acceptance2_message;
/** \var xmachine_message_application_rejection * application_rejection_message
* \brief Pointer to message struct for looping through application_rejection message list */
xmachine_message_application_rejection * application_rejection_message;
/** \var xmachine_message_application_rejection2 * application_rejection2_message
* \brief Pointer to message struct for looping through application_rejection2 message list */
xmachine_message_application_rejection2 * application_rejection2_message;
/** \var xmachine_message_quitting * quitting_message
* \brief Pointer to message struct for looping through quitting message list */
xmachine_message_quitting * quitting_message;
/** \var xmachine_message_quitting2 * quitting2_message
* \brief Pointer to message struct for looping through quitting2 message list */
xmachine_message_quitting2 * quitting2_message;
/** \var xmachine_message_productivity * productivity_message
* \brief Pointer to message struct for looping through productivity message list */
xmachine_message_productivity * productivity_message;
/** \var xmachine_message_capital_good_request * capital_good_request_message
* \brief Pointer to message struct for looping through capital_good_request message list */
xmachine_message_capital_good_request * capital_good_request_message;
/** \var xmachine_message_capital_good_profit_distribution * capital_good_profit_distribution_message
* \brief Pointer to message struct for looping through capital_good_profit_distribution message list */
xmachine_message_capital_good_profit_distribution * capital_good_profit_distribution_message;
/** \var xmachine_message_capital_good_delivery * capital_good_delivery_message
* \brief Pointer to message struct for looping through capital_good_delivery message list */
xmachine_message_capital_good_delivery * capital_good_delivery_message;
/** \var xmachine_message_wage_payment * wage_payment_message
* \brief Pointer to message struct for looping through wage_payment message list */
xmachine_message_wage_payment * wage_payment_message;
/** \var xmachine_message_quality_price_info_1 * quality_price_info_1_message
* \brief Pointer to message struct for looping through quality_price_info_1 message list */
xmachine_message_quality_price_info_1 * quality_price_info_1_message;
/** \var xmachine_message_quality_price_info_2 * quality_price_info_2_message
* \brief Pointer to message struct for looping through quality_price_info_2 message list */
xmachine_message_quality_price_info_2 * quality_price_info_2_message;
/** \var xmachine_message_update_mall_stock * update_mall_stock_message
* \brief Pointer to message struct for looping through update_mall_stock message list */
xmachine_message_update_mall_stock * update_mall_stock_message;
/** \var xmachine_message_consumption_request_1 * consumption_request_1_message
* \brief Pointer to message struct for looping through consumption_request_1 message list */
xmachine_message_consumption_request_1 * consumption_request_1_message;
/** \var xmachine_message_consumption_request_2 * consumption_request_2_message
* \brief Pointer to message struct for looping through consumption_request_2 message list */
xmachine_message_consumption_request_2 * consumption_request_2_message;
/** \var xmachine_message_accepted_consumption_1 * accepted_consumption_1_message
* \brief Pointer to message struct for looping through accepted_consumption_1 message list */
xmachine_message_accepted_consumption_1 * accepted_consumption_1_message;
/** \var xmachine_message_accepted_consumption_2 * accepted_consumption_2_message
* \brief Pointer to message struct for looping through accepted_consumption_2 message list */
xmachine_message_accepted_consumption_2 * accepted_consumption_2_message;
/** \var xmachine_message_sales * sales_message
* \brief Pointer to message struct for looping through sales message list */
xmachine_message_sales * sales_message;
/** \var xmachine_message_pay_capital_goods * pay_capital_goods_message
* \brief Pointer to message struct for looping through pay_capital_goods message list */
xmachine_message_pay_capital_goods * pay_capital_goods_message;
/** \var xmachine_message_current_mall_stock_info * current_mall_stock_info_message
* \brief Pointer to message struct for looping through current_mall_stock_info message list */
xmachine_message_current_mall_stock_info * current_mall_stock_info_message;
/** \var xmachine_message_specific_skill_update * specific_skill_update_message
* \brief Pointer to message struct for looping through specific_skill_update message list */
xmachine_message_specific_skill_update * specific_skill_update_message;
/** \var xmachine_message_firm_send_data * firm_send_data_message
* \brief Pointer to message struct for looping through firm_send_data message list */
xmachine_message_firm_send_data * firm_send_data_message;
/** \var xmachine_message_household_send_data * household_send_data_message
* \brief Pointer to message struct for looping through household_send_data message list */
xmachine_message_household_send_data * household_send_data_message;
/** \var xmachine_message_market_research_send_specific_skills * market_research_send_specific_skills_message
* \brief Pointer to message struct for looping through market_research_send_specific_skills message list */
xmachine_message_market_research_send_specific_skills * market_research_send_specific_skills_message;
/** \var xmachine_message_tax_payment * tax_payment_message
* \brief Pointer to message struct for looping through tax_payment message list */
xmachine_message_tax_payment * tax_payment_message;
/** \var xmachine_message_interest_payment * interest_payment_message
* \brief Pointer to message struct for looping through interest_payment message list */
xmachine_message_interest_payment * interest_payment_message;
/** \var xmachine_message_debt_installment_payment * debt_installment_payment_message
* \brief Pointer to message struct for looping through debt_installment_payment message list */
xmachine_message_debt_installment_payment * debt_installment_payment_message;
/** \var xmachine_message_dividend_payment * dividend_payment_message
* \brief Pointer to message struct for looping through dividend_payment message list */
xmachine_message_dividend_payment * dividend_payment_message;
/** \var xmachine_message_loan_request * loan_request_message
* \brief Pointer to message struct for looping through loan_request message list */
xmachine_message_loan_request * loan_request_message;
/** \var xmachine_message_loan_conditions * loan_conditions_message
* \brief Pointer to message struct for looping through loan_conditions message list */
xmachine_message_loan_conditions * loan_conditions_message;
/** \var xmachine_message_loan_acceptance * loan_acceptance_message
* \brief Pointer to message struct for looping through loan_acceptance message list */
xmachine_message_loan_acceptance * loan_acceptance_message;
/** \var xmachine_message_stock_order * stock_order_message
* \brief Pointer to message struct for looping through stock_order message list */
xmachine_message_stock_order * stock_order_message;
/** \var xmachine_message_stock_transaction * stock_transaction_message
* \brief Pointer to message struct for looping through stock_transaction message list */
xmachine_message_stock_transaction * stock_transaction_message;
/** \var xmachine_message_bond_order * bond_order_message
* \brief Pointer to message struct for looping through bond_order message list */
xmachine_message_bond_order * bond_order_message;
/** \var xmachine_message_bond_transaction * bond_transaction_message
* \brief Pointer to message struct for looping through bond_transaction message list */
xmachine_message_bond_transaction * bond_transaction_message;
/** \var xmachine_message_gov_bond_order * gov_bond_order_message
* \brief Pointer to message struct for looping through gov_bond_order message list */
xmachine_message_gov_bond_order * gov_bond_order_message;
/** \var xmachine_message_gov_bond_transaction * gov_bond_transaction_message
* \brief Pointer to message struct for looping through gov_bond_transaction message list */
xmachine_message_gov_bond_transaction * gov_bond_transaction_message;
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
void randomisexagent(void);
void free_agent(void);
void freexmachines(void);
/* model datatypes */

void init_employee_array(employee_array * array);
void reset_employee_array(employee_array * array);
void free_employee_array(employee_array * array);
void copy_employee_array(employee_array * from, employee_array * to);
void add_employee(employee_array * array, int id, int region_id, double wage, int general_skill, double specific_skill);
void remove_employee(employee_array * array, int index);

void init_vacancy_array(vacancy_array * array);
void reset_vacancy_array(vacancy_array * array);
void free_vacancy_array(vacancy_array * array);
void copy_vacancy_array(vacancy_array * from, vacancy_array * to);
void add_vacancy(vacancy_array * array, int firm_id, int region_id, double wage_offer);
void remove_vacancy(vacancy_array * array, int index);

void init_job_application_array(job_application_array * array);
void reset_job_application_array(job_application_array * array);
void free_job_application_array(job_application_array * array);
void copy_job_application_array(job_application_array * from, job_application_array * to);
void add_job_application(job_application_array * array, int worker_id, int region_id, int general_skill, double specific_skill);
void remove_job_application(job_application_array * array, int index);

void init_job_offer_array(job_offer_array * array);
void reset_job_offer_array(job_offer_array * array);
void free_job_offer_array(job_offer_array * array);
void copy_job_offer_array(job_offer_array * from, job_offer_array * to);
void add_job_offer(job_offer_array * array, int firm_id, int region_id, double wage_offer);
void remove_job_offer(job_offer_array * array, int index);

void init_consumption_goods_offer_array(consumption_goods_offer_array * array);
void reset_consumption_goods_offer_array(consumption_goods_offer_array * array);
void free_consumption_goods_offer_array(consumption_goods_offer_array * array);
void copy_consumption_goods_offer_array(consumption_goods_offer_array * from, consumption_goods_offer_array * to);
void add_consumption_goods_offer(consumption_goods_offer_array * array, int id, double quality, double price);
void remove_consumption_goods_offer(consumption_goods_offer_array * array, int index);

void init_consumption_request_array(consumption_request_array * array);
void reset_consumption_request_array(consumption_request_array * array);
void free_consumption_request_array(consumption_request_array * array);
void copy_consumption_request_array(consumption_request_array * from, consumption_request_array * to);
void add_consumption_request(consumption_request_array * array, int worker_id, int firm_id, double quantity);
void remove_consumption_request(consumption_request_array * array, int index);

void init_mall_info_array(mall_info_array * array);
void reset_mall_info_array(mall_info_array * array);
void free_mall_info_array(mall_info_array * array);
void copy_mall_info_array(mall_info_array * from, mall_info_array * to);
void add_mall_info(mall_info_array * array, int mall_id, double critical_stock, double current_stock);
void remove_mall_info(mall_info_array * array, int index);

void init_mall_quality_price_info_array(mall_quality_price_info_array * array);
void reset_mall_quality_price_info_array(mall_quality_price_info_array * array);
void free_mall_quality_price_info_array(mall_quality_price_info_array * array);
void copy_mall_quality_price_info_array(mall_quality_price_info_array * from, mall_quality_price_info_array * to);
void add_mall_quality_price_info(mall_quality_price_info_array * array, int mall_id, int firm_id, int mall_region_id, double quality, double price, int available);
void remove_mall_quality_price_info(mall_quality_price_info_array * array, int index);

void init_mall_stock_array(mall_stock_array * array);
void reset_mall_stock_array(mall_stock_array * array);
void free_mall_stock_array(mall_stock_array * array);
void copy_mall_stock_array(mall_stock_array * from, mall_stock_array * to);
void add_mall_stock(mall_stock_array * array, int firm_id, double stock, double price, double quality);
void remove_mall_stock(mall_stock_array * array, int index);

void init_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array);
void reset_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array);
void free_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array);
void copy_delivery_volume_per_mall_array(delivery_volume_per_mall_array * from, delivery_volume_per_mall_array * to);
void add_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int mall_id, double quantity, double price, double quality);
void remove_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int index);

void init_logit_firm_id_array(logit_firm_id_array * array);
void reset_logit_firm_id_array(logit_firm_id_array * array);
void free_logit_firm_id_array(logit_firm_id_array * array);
void copy_logit_firm_id_array(logit_firm_id_array * from, logit_firm_id_array * to);
void add_logit_firm_id(logit_firm_id_array * array, double logit, int firm_id);
void remove_logit_firm_id(logit_firm_id_array * array, int index);

void init_sales_in_mall_array(sales_in_mall_array * array);
void reset_sales_in_mall_array(sales_in_mall_array * array);
void free_sales_in_mall_array(sales_in_mall_array * array);
void copy_sales_in_mall_array(sales_in_mall_array * from, sales_in_mall_array * to);
void add_sales_in_mall(sales_in_mall_array * array, int firm_id, double sales);
void remove_sales_in_mall(sales_in_mall_array * array, int index);

void init_ordered_quantity_array(ordered_quantity_array * array);
void reset_ordered_quantity_array(ordered_quantity_array * array);
void free_ordered_quantity_array(ordered_quantity_array * array);
void copy_ordered_quantity_array(ordered_quantity_array * from, ordered_quantity_array * to);
void add_ordered_quantity(ordered_quantity_array * array, int firm_id, double quantity, double price);
void remove_ordered_quantity(ordered_quantity_array * array, int index);

void init_received_quantities_array(received_quantities_array * array);
void reset_received_quantities_array(received_quantities_array * array);
void free_received_quantities_array(received_quantities_array * array);
void copy_received_quantities_array(received_quantities_array * from, received_quantities_array * to);
void add_received_quantities(received_quantities_array * array, int firm_id, double quantity);
void remove_received_quantities(received_quantities_array * array, int index);

void init_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array);
void reset_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array);
void free_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array);
void copy_sold_quantities_per_mall_array(sold_quantities_per_mall_array * from, sold_quantities_per_mall_array * to);
void add_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int mall_id, double sold_quantity, int stock_empty, double estimated_demand);
void remove_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int index);

void init_sales_statistics_array(sales_statistics_array * array);
void reset_sales_statistics_array(sales_statistics_array * array);
void free_sales_statistics_array(sales_statistics_array * array);
void copy_sales_statistics_array(sales_statistics_array * from, sales_statistics_array * to);
void add_sales_statistics(sales_statistics_array * array, int mall_id, int period, double sales);
void remove_sales_statistics(sales_statistics_array * array, int index);

void init_debt_item_array(debt_item_array * array);
void reset_debt_item_array(debt_item_array * array);
void free_debt_item_array(debt_item_array * array);
void copy_debt_item_array(debt_item_array * from, debt_item_array * to);
void add_debt_item(debt_item_array * array, int bank_id, double loan_value, double interest_rate, double interest_payment, double debt_installment_payment, int nr_periods_before_maturity);
void remove_debt_item(debt_item_array * array, int index);

void init_capital_stock_item_array(capital_stock_item_array * array);
void reset_capital_stock_item_array(capital_stock_item_array * array);
void free_capital_stock_item_array(capital_stock_item_array * array);
void copy_capital_stock_item_array(capital_stock_item_array * from, capital_stock_item_array * to);
void add_capital_stock_item(capital_stock_item_array * array, double units, double purchase_price, double productivity, double depreciation_units_per_period);
void remove_capital_stock_item(capital_stock_item_array * array, int index);

void init_household_data_array(household_data_array * array);
void reset_household_data_array(household_data_array * array);
void free_household_data_array(household_data_array * array);
void copy_household_data_array(household_data_array * from, household_data_array * to);
void add_household_data(household_data_array * array, int region_id, int no_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5);
void remove_household_data(household_data_array * array, int index);

void init_firm_data_array(firm_data_array * array);
void reset_firm_data_array(firm_data_array * array);
void free_firm_data_array(firm_data_array * array);
void copy_firm_data_array(firm_data_array * from, firm_data_array * to);
void add_firm_data(firm_data_array * array, int region_id, int firms, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5);
void remove_firm_data(firm_data_array * array, int index);


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
/* xml.c */
void read_int_static_array(char * buffer, int * j, int * int_static_array, int size);
void read_float_static_array(char * buffer, int * j, float * float_static_array, int size);
void read_double_static_array(char * buffer, int * j, double * double_static_array, int size);
void read_char_static_array(char * buffer, int * j, char * char_static_array, int size);
void read_int_dynamic_array(char * buffer, int * j, int_array * int_dynamic_array);
void read_float_dynamic_array(char * buffer, int * j, float_array * float_dynamic_array);
void read_double_dynamic_array(char * buffer, int * j, double_array * double_dynamic_array);
void read_char_dynamic_array(char * buffer, int * j, char_array * char_dynamic_array);

void init_employee(employee * temp);
void init_employee_static_array(employee * array, int size);
void read_employee(char * buffer, int * j, employee * temp_datatype);
void read_employee_dynamic_array(char * buffer, int * j, employee_array * temp_datatype_array);
void read_employee_static_array(char * buffer, int * j, employee * temp_datatype_array, int size);
void write_employee(FILE *file, employee * temp_datatype);
void write_employee_static_array(FILE *file, employee * temp_datatype, int size);
void write_employee_dynamic_array(FILE *file, employee_array * temp_datatype);
void init_vacancy(vacancy * temp);
void init_vacancy_static_array(vacancy * array, int size);
void read_vacancy(char * buffer, int * j, vacancy * temp_datatype);
void read_vacancy_dynamic_array(char * buffer, int * j, vacancy_array * temp_datatype_array);
void read_vacancy_static_array(char * buffer, int * j, vacancy * temp_datatype_array, int size);
void write_vacancy(FILE *file, vacancy * temp_datatype);
void write_vacancy_static_array(FILE *file, vacancy * temp_datatype, int size);
void write_vacancy_dynamic_array(FILE *file, vacancy_array * temp_datatype);
void init_job_application(job_application * temp);
void init_job_application_static_array(job_application * array, int size);
void read_job_application(char * buffer, int * j, job_application * temp_datatype);
void read_job_application_dynamic_array(char * buffer, int * j, job_application_array * temp_datatype_array);
void read_job_application_static_array(char * buffer, int * j, job_application * temp_datatype_array, int size);
void write_job_application(FILE *file, job_application * temp_datatype);
void write_job_application_static_array(FILE *file, job_application * temp_datatype, int size);
void write_job_application_dynamic_array(FILE *file, job_application_array * temp_datatype);
void init_job_offer(job_offer * temp);
void init_job_offer_static_array(job_offer * array, int size);
void read_job_offer(char * buffer, int * j, job_offer * temp_datatype);
void read_job_offer_dynamic_array(char * buffer, int * j, job_offer_array * temp_datatype_array);
void read_job_offer_static_array(char * buffer, int * j, job_offer * temp_datatype_array, int size);
void write_job_offer(FILE *file, job_offer * temp_datatype);
void write_job_offer_static_array(FILE *file, job_offer * temp_datatype, int size);
void write_job_offer_dynamic_array(FILE *file, job_offer_array * temp_datatype);
void init_consumption_goods_offer(consumption_goods_offer * temp);
void init_consumption_goods_offer_static_array(consumption_goods_offer * array, int size);
void read_consumption_goods_offer(char * buffer, int * j, consumption_goods_offer * temp_datatype);
void read_consumption_goods_offer_dynamic_array(char * buffer, int * j, consumption_goods_offer_array * temp_datatype_array);
void read_consumption_goods_offer_static_array(char * buffer, int * j, consumption_goods_offer * temp_datatype_array, int size);
void write_consumption_goods_offer(FILE *file, consumption_goods_offer * temp_datatype);
void write_consumption_goods_offer_static_array(FILE *file, consumption_goods_offer * temp_datatype, int size);
void write_consumption_goods_offer_dynamic_array(FILE *file, consumption_goods_offer_array * temp_datatype);
void init_consumption_request(consumption_request * temp);
void init_consumption_request_static_array(consumption_request * array, int size);
void read_consumption_request(char * buffer, int * j, consumption_request * temp_datatype);
void read_consumption_request_dynamic_array(char * buffer, int * j, consumption_request_array * temp_datatype_array);
void read_consumption_request_static_array(char * buffer, int * j, consumption_request * temp_datatype_array, int size);
void write_consumption_request(FILE *file, consumption_request * temp_datatype);
void write_consumption_request_static_array(FILE *file, consumption_request * temp_datatype, int size);
void write_consumption_request_dynamic_array(FILE *file, consumption_request_array * temp_datatype);
void init_mall_info(mall_info * temp);
void init_mall_info_static_array(mall_info * array, int size);
void read_mall_info(char * buffer, int * j, mall_info * temp_datatype);
void read_mall_info_dynamic_array(char * buffer, int * j, mall_info_array * temp_datatype_array);
void read_mall_info_static_array(char * buffer, int * j, mall_info * temp_datatype_array, int size);
void write_mall_info(FILE *file, mall_info * temp_datatype);
void write_mall_info_static_array(FILE *file, mall_info * temp_datatype, int size);
void write_mall_info_dynamic_array(FILE *file, mall_info_array * temp_datatype);
void init_mall_quality_price_info(mall_quality_price_info * temp);
void init_mall_quality_price_info_static_array(mall_quality_price_info * array, int size);
void read_mall_quality_price_info(char * buffer, int * j, mall_quality_price_info * temp_datatype);
void read_mall_quality_price_info_dynamic_array(char * buffer, int * j, mall_quality_price_info_array * temp_datatype_array);
void read_mall_quality_price_info_static_array(char * buffer, int * j, mall_quality_price_info * temp_datatype_array, int size);
void write_mall_quality_price_info(FILE *file, mall_quality_price_info * temp_datatype);
void write_mall_quality_price_info_static_array(FILE *file, mall_quality_price_info * temp_datatype, int size);
void write_mall_quality_price_info_dynamic_array(FILE *file, mall_quality_price_info_array * temp_datatype);
void init_mall_stock(mall_stock * temp);
void init_mall_stock_static_array(mall_stock * array, int size);
void read_mall_stock(char * buffer, int * j, mall_stock * temp_datatype);
void read_mall_stock_dynamic_array(char * buffer, int * j, mall_stock_array * temp_datatype_array);
void read_mall_stock_static_array(char * buffer, int * j, mall_stock * temp_datatype_array, int size);
void write_mall_stock(FILE *file, mall_stock * temp_datatype);
void write_mall_stock_static_array(FILE *file, mall_stock * temp_datatype, int size);
void write_mall_stock_dynamic_array(FILE *file, mall_stock_array * temp_datatype);
void init_delivery_volume_per_mall(delivery_volume_per_mall * temp);
void init_delivery_volume_per_mall_static_array(delivery_volume_per_mall * array, int size);
void read_delivery_volume_per_mall(char * buffer, int * j, delivery_volume_per_mall * temp_datatype);
void read_delivery_volume_per_mall_dynamic_array(char * buffer, int * j, delivery_volume_per_mall_array * temp_datatype_array);
void read_delivery_volume_per_mall_static_array(char * buffer, int * j, delivery_volume_per_mall * temp_datatype_array, int size);
void write_delivery_volume_per_mall(FILE *file, delivery_volume_per_mall * temp_datatype);
void write_delivery_volume_per_mall_static_array(FILE *file, delivery_volume_per_mall * temp_datatype, int size);
void write_delivery_volume_per_mall_dynamic_array(FILE *file, delivery_volume_per_mall_array * temp_datatype);
void init_logit_firm_id(logit_firm_id * temp);
void init_logit_firm_id_static_array(logit_firm_id * array, int size);
void read_logit_firm_id(char * buffer, int * j, logit_firm_id * temp_datatype);
void read_logit_firm_id_dynamic_array(char * buffer, int * j, logit_firm_id_array * temp_datatype_array);
void read_logit_firm_id_static_array(char * buffer, int * j, logit_firm_id * temp_datatype_array, int size);
void write_logit_firm_id(FILE *file, logit_firm_id * temp_datatype);
void write_logit_firm_id_static_array(FILE *file, logit_firm_id * temp_datatype, int size);
void write_logit_firm_id_dynamic_array(FILE *file, logit_firm_id_array * temp_datatype);
void init_sales_in_mall(sales_in_mall * temp);
void init_sales_in_mall_static_array(sales_in_mall * array, int size);
void read_sales_in_mall(char * buffer, int * j, sales_in_mall * temp_datatype);
void read_sales_in_mall_dynamic_array(char * buffer, int * j, sales_in_mall_array * temp_datatype_array);
void read_sales_in_mall_static_array(char * buffer, int * j, sales_in_mall * temp_datatype_array, int size);
void write_sales_in_mall(FILE *file, sales_in_mall * temp_datatype);
void write_sales_in_mall_static_array(FILE *file, sales_in_mall * temp_datatype, int size);
void write_sales_in_mall_dynamic_array(FILE *file, sales_in_mall_array * temp_datatype);
void init_ordered_quantity(ordered_quantity * temp);
void init_ordered_quantity_static_array(ordered_quantity * array, int size);
void read_ordered_quantity(char * buffer, int * j, ordered_quantity * temp_datatype);
void read_ordered_quantity_dynamic_array(char * buffer, int * j, ordered_quantity_array * temp_datatype_array);
void read_ordered_quantity_static_array(char * buffer, int * j, ordered_quantity * temp_datatype_array, int size);
void write_ordered_quantity(FILE *file, ordered_quantity * temp_datatype);
void write_ordered_quantity_static_array(FILE *file, ordered_quantity * temp_datatype, int size);
void write_ordered_quantity_dynamic_array(FILE *file, ordered_quantity_array * temp_datatype);
void init_received_quantities(received_quantities * temp);
void init_received_quantities_static_array(received_quantities * array, int size);
void read_received_quantities(char * buffer, int * j, received_quantities * temp_datatype);
void read_received_quantities_dynamic_array(char * buffer, int * j, received_quantities_array * temp_datatype_array);
void read_received_quantities_static_array(char * buffer, int * j, received_quantities * temp_datatype_array, int size);
void write_received_quantities(FILE *file, received_quantities * temp_datatype);
void write_received_quantities_static_array(FILE *file, received_quantities * temp_datatype, int size);
void write_received_quantities_dynamic_array(FILE *file, received_quantities_array * temp_datatype);
void init_sold_quantities_per_mall(sold_quantities_per_mall * temp);
void init_sold_quantities_per_mall_static_array(sold_quantities_per_mall * array, int size);
void read_sold_quantities_per_mall(char * buffer, int * j, sold_quantities_per_mall * temp_datatype);
void read_sold_quantities_per_mall_dynamic_array(char * buffer, int * j, sold_quantities_per_mall_array * temp_datatype_array);
void read_sold_quantities_per_mall_static_array(char * buffer, int * j, sold_quantities_per_mall * temp_datatype_array, int size);
void write_sold_quantities_per_mall(FILE *file, sold_quantities_per_mall * temp_datatype);
void write_sold_quantities_per_mall_static_array(FILE *file, sold_quantities_per_mall * temp_datatype, int size);
void write_sold_quantities_per_mall_dynamic_array(FILE *file, sold_quantities_per_mall_array * temp_datatype);
void init_sales_statistics(sales_statistics * temp);
void init_sales_statistics_static_array(sales_statistics * array, int size);
void read_sales_statistics(char * buffer, int * j, sales_statistics * temp_datatype);
void read_sales_statistics_dynamic_array(char * buffer, int * j, sales_statistics_array * temp_datatype_array);
void read_sales_statistics_static_array(char * buffer, int * j, sales_statistics * temp_datatype_array, int size);
void write_sales_statistics(FILE *file, sales_statistics * temp_datatype);
void write_sales_statistics_static_array(FILE *file, sales_statistics * temp_datatype, int size);
void write_sales_statistics_dynamic_array(FILE *file, sales_statistics_array * temp_datatype);
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
void init_household_data(household_data * temp);
void init_household_data_static_array(household_data * array, int size);
void read_household_data(char * buffer, int * j, household_data * temp_datatype);
void read_household_data_dynamic_array(char * buffer, int * j, household_data_array * temp_datatype_array);
void read_household_data_static_array(char * buffer, int * j, household_data * temp_datatype_array, int size);
void write_household_data(FILE *file, household_data * temp_datatype);
void write_household_data_static_array(FILE *file, household_data * temp_datatype, int size);
void write_household_data_dynamic_array(FILE *file, household_data_array * temp_datatype);
void init_firm_data(firm_data * temp);
void init_firm_data_static_array(firm_data * array, int size);
void read_firm_data(char * buffer, int * j, firm_data * temp_datatype);
void read_firm_data_dynamic_array(char * buffer, int * j, firm_data_array * temp_datatype_array);
void read_firm_data_static_array(char * buffer, int * j, firm_data * temp_datatype_array, int size);
void write_firm_data(FILE *file, firm_data * temp_datatype);
void write_firm_data_static_array(FILE *file, firm_data * temp_datatype, int size);
void write_firm_data_dynamic_array(FILE *file, firm_data_array * temp_datatype);
void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], 
                       int partition_method, int flag);
void saveiterationdata_binary(int iteration_number);
void saveiterationdata(int iteration_number);

void free_employee(employee * temp);
void free_employee_static_array(employee * array, int size);
void copy_employee(employee * from, employee * to);
void copy_employee_static_array(employee * from, employee * to, int size);
void free_vacancy(vacancy * temp);
void free_vacancy_static_array(vacancy * array, int size);
void copy_vacancy(vacancy * from, vacancy * to);
void copy_vacancy_static_array(vacancy * from, vacancy * to, int size);
void free_job_application(job_application * temp);
void free_job_application_static_array(job_application * array, int size);
void copy_job_application(job_application * from, job_application * to);
void copy_job_application_static_array(job_application * from, job_application * to, int size);
void free_job_offer(job_offer * temp);
void free_job_offer_static_array(job_offer * array, int size);
void copy_job_offer(job_offer * from, job_offer * to);
void copy_job_offer_static_array(job_offer * from, job_offer * to, int size);
void free_consumption_goods_offer(consumption_goods_offer * temp);
void free_consumption_goods_offer_static_array(consumption_goods_offer * array, int size);
void copy_consumption_goods_offer(consumption_goods_offer * from, consumption_goods_offer * to);
void copy_consumption_goods_offer_static_array(consumption_goods_offer * from, consumption_goods_offer * to, int size);
void free_consumption_request(consumption_request * temp);
void free_consumption_request_static_array(consumption_request * array, int size);
void copy_consumption_request(consumption_request * from, consumption_request * to);
void copy_consumption_request_static_array(consumption_request * from, consumption_request * to, int size);
void free_mall_info(mall_info * temp);
void free_mall_info_static_array(mall_info * array, int size);
void copy_mall_info(mall_info * from, mall_info * to);
void copy_mall_info_static_array(mall_info * from, mall_info * to, int size);
void free_mall_quality_price_info(mall_quality_price_info * temp);
void free_mall_quality_price_info_static_array(mall_quality_price_info * array, int size);
void copy_mall_quality_price_info(mall_quality_price_info * from, mall_quality_price_info * to);
void copy_mall_quality_price_info_static_array(mall_quality_price_info * from, mall_quality_price_info * to, int size);
void free_mall_stock(mall_stock * temp);
void free_mall_stock_static_array(mall_stock * array, int size);
void copy_mall_stock(mall_stock * from, mall_stock * to);
void copy_mall_stock_static_array(mall_stock * from, mall_stock * to, int size);
void free_delivery_volume_per_mall(delivery_volume_per_mall * temp);
void free_delivery_volume_per_mall_static_array(delivery_volume_per_mall * array, int size);
void copy_delivery_volume_per_mall(delivery_volume_per_mall * from, delivery_volume_per_mall * to);
void copy_delivery_volume_per_mall_static_array(delivery_volume_per_mall * from, delivery_volume_per_mall * to, int size);
void free_logit_firm_id(logit_firm_id * temp);
void free_logit_firm_id_static_array(logit_firm_id * array, int size);
void copy_logit_firm_id(logit_firm_id * from, logit_firm_id * to);
void copy_logit_firm_id_static_array(logit_firm_id * from, logit_firm_id * to, int size);
void free_sales_in_mall(sales_in_mall * temp);
void free_sales_in_mall_static_array(sales_in_mall * array, int size);
void copy_sales_in_mall(sales_in_mall * from, sales_in_mall * to);
void copy_sales_in_mall_static_array(sales_in_mall * from, sales_in_mall * to, int size);
void free_ordered_quantity(ordered_quantity * temp);
void free_ordered_quantity_static_array(ordered_quantity * array, int size);
void copy_ordered_quantity(ordered_quantity * from, ordered_quantity * to);
void copy_ordered_quantity_static_array(ordered_quantity * from, ordered_quantity * to, int size);
void free_received_quantities(received_quantities * temp);
void free_received_quantities_static_array(received_quantities * array, int size);
void copy_received_quantities(received_quantities * from, received_quantities * to);
void copy_received_quantities_static_array(received_quantities * from, received_quantities * to, int size);
void free_sold_quantities_per_mall(sold_quantities_per_mall * temp);
void free_sold_quantities_per_mall_static_array(sold_quantities_per_mall * array, int size);
void copy_sold_quantities_per_mall(sold_quantities_per_mall * from, sold_quantities_per_mall * to);
void copy_sold_quantities_per_mall_static_array(sold_quantities_per_mall * from, sold_quantities_per_mall * to, int size);
void free_sales_statistics(sales_statistics * temp);
void free_sales_statistics_static_array(sales_statistics * array, int size);
void copy_sales_statistics(sales_statistics * from, sales_statistics * to);
void copy_sales_statistics_static_array(sales_statistics * from, sales_statistics * to, int size);
void free_debt_item(debt_item * temp);
void free_debt_item_static_array(debt_item * array, int size);
void copy_debt_item(debt_item * from, debt_item * to);
void copy_debt_item_static_array(debt_item * from, debt_item * to, int size);
void free_capital_stock_item(capital_stock_item * temp);
void free_capital_stock_item_static_array(capital_stock_item * array, int size);
void copy_capital_stock_item(capital_stock_item * from, capital_stock_item * to);
void copy_capital_stock_item_static_array(capital_stock_item * from, capital_stock_item * to, int size);
void free_household_data(household_data * temp);
void free_household_data_static_array(household_data * array, int size);
void copy_household_data(household_data * from, household_data * to);
void copy_household_data_static_array(household_data * from, household_data * to, int size);
void free_firm_data(firm_data * temp);
void free_firm_data_static_array(firm_data * array, int size);
void copy_firm_data(firm_data * from, firm_data * to);
void copy_firm_data_static_array(firm_data * from, firm_data * to, int size);

xmachine_memory_Firm * init_Firm_agent();
void add_Firm_agent_internal(xmachine_memory_Firm * current);
void add_Firm_agent(int id, int region_id, employee_array * employees, double wage_offer, double technology, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, int vacancies, double average_g_skill, double average_s_skill_of_1, double average_s_skill_of_2, double average_s_skill_of_3, double average_s_skill_of_4, double average_s_skill_of_5, double wage_offer_for_skill_1, double wage_offer_for_skill_2, double wage_offer_for_skill_3, double wage_offer_for_skill_4, double wage_offer_for_skill_5, int wage_update_was_made, double share_net_investments, double mean_wage, double needed_capital_stock, double actual_cap_price, double mean_specific_skills, double planned_production_quantity, double production_quantity, double unit_costs, double planned_production_costs, double production_costs, double revenue_per_day, double technological_frontier, double cum_revenue, double out_of_stock_costs, sales_statistics_array * malls_sales_statistics, double quality, double price, double price_last_month, capital_stock_item_array * capital_stock, double total_units_capital_stock, double total_value_capital_stock, double total_capital_depreciation_value, double total_capital_depreciation_units, int employees_needed, sold_quantities_per_mall_array * sold_quantities, double total_sold_quantity, double cum_total_sold_quantity, delivery_volume_per_mall_array * delivery_volume, delivery_volume_per_mall_array * planned_delivery_volume, mall_info_array * current_mall_stocks, double demand_capital_stock, double_array * last_planned_production_quantities, int day_of_month_to_act, int gov_id, int bank_id, double ebit, double payment_account, double earnings, double tax_rate_corporate, double tax_payment, double net_earnings, double previous_net_earnings, debt_item_array * loans, double total_interest_payment, double total_debt_installment_payment, double total_debt, double total_dividend_payment, double total_value_local_inventory, double total_assets, double planned_cum_revenue, double planned_total_interest_payment, double planned_total_debt_installment_payment, double planned_total_dividend_payment, double direct_financial_needs, double delayed_financial_needs, double total_financial_needs, double internal_financial_needs, double external_financial_needs, double total_external_financing_obtained, int direct_financial_needs_require_external_financing, int delayed_financial_needs_require_external_financing, double current_share_price, double current_shares_outstanding, double previous_dividend_per_share, double current_dividend_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double earnings_per_share_ratio, double debt_earnings_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, double target_loans, double target_equity, double bonds_issue_target, double stocks_issue_target, double range, double posx, double posy);
xmachine_memory_Household * init_Household_agent();
void add_Household_agent_internal(xmachine_memory_Household * current);
void add_Household_agent(int id, int region_id, int_array * neighboring_region_ids, double wage, double wage_reservation, int general_skill, int on_the_job_search, int number_applications, double specific_skill, int employee_firm_id, int employer_region_id, double budget, int week_of_month, double weekly_budget, double expenditures, double received_dividend_cap, double received_dividend_cons, double savings, double_array * last_income, int rationed, int mall_completely_sold_out, ordered_quantity order_quantity[], received_quantities received_quantity[], int day_of_month_to_act, int day_of_week_to_act, double range, double posx, double posy);
xmachine_memory_Mall * init_Mall_agent();
void add_Mall_agent_internal(xmachine_memory_Mall * current);
void add_Mall_agent(int id, int region_id, mall_stock_array * current_stock, sales_in_mall_array * firm_revenues, double total_supply, double range, double posx, double posy);
xmachine_memory_IGFirm * init_IGFirm_agent();
void add_IGFirm_agent_internal(xmachine_memory_IGFirm * current);
void add_IGFirm_agent(int id, int region_id, double productivity, int innovation_probability, double productivity_progress, double capital_good_price, double revenue_per_day, int day_of_month_to_act, double range, double posx, double posy);
xmachine_memory_Market_Research * init_Market_Research_agent();
void add_Market_Research_agent_internal(xmachine_memory_Market_Research * current);
void add_Market_Research_agent(int id, int region_id, int no_regions, int num_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, int no_firms, int no_vacancies, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, double firm_average_wage, double firm_average_wage_skill_1, double firm_average_wage_skill_2, double firm_average_wage_skill_3, double firm_average_wage_skill_4, double firm_average_wage_skill_5, double firm_average_s_skill, double firm_average_s_skill_1, double firm_average_s_skill_2, double firm_average_s_skill_3, double firm_average_s_skill_4, double firm_average_s_skill_5, firm_data_array * region_firm_data, household_data_array * region_household_data, int day_of_month_to_act, double range, double posx, double posy);
xmachine_memory_Clearinghouse * init_Clearinghouse_agent();
void add_Clearinghouse_agent_internal(xmachine_memory_Clearinghouse * current);
void add_Clearinghouse_agent(int id, int trader_id, int stock_id, int bond_id, int gov_bond_id, double limit_price, double limit_quantity, double range, double posx, double posy);
xmachine_memory_Bank * init_Bank_agent();
void add_Bank_agent_internal(xmachine_memory_Bank * current);
void add_Bank_agent(int id, double proposed_interest_rate, double amount_credit_offer, double range, double posx, double posy);

void add_vacancies_message(int firm_id, int region_id, int firm_vacancies, int skill_group, double firm_wage_offer, double range, double x, double y, double z);
xmachine_message_vacancies * add_vacancies_message_internal(void);
xmachine_message_vacancies * get_first_vacancies_message(void);
xmachine_message_vacancies * get_next_vacancies_message(xmachine_message_vacancies * current);
void freevacanciesmessages(void);
void add_vacancies2_message(int firm_id, int region_id, int firm_vacancies, int skill_group, double firm_wage_offer, double range, double x, double y, double z);
xmachine_message_vacancies2 * add_vacancies2_message_internal(void);
xmachine_message_vacancies2 * get_first_vacancies2_message(void);
xmachine_message_vacancies2 * get_next_vacancies2_message(xmachine_message_vacancies2 * current);
void freevacancies2messages(void);
void add_firing_message(int firm_id, int worker_id, double range, double x, double y, double z);
xmachine_message_firing * add_firing_message_internal(void);
xmachine_message_firing * get_first_firing_message(void);
xmachine_message_firing * get_next_firing_message(xmachine_message_firing * current);
void freefiringmessages(void);
void add_job_application_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z);
xmachine_message_job_application * add_job_application_message_internal(void);
xmachine_message_job_application * get_first_job_application_message(void);
xmachine_message_job_application * get_next_job_application_message(xmachine_message_job_application * current);
void freejob_applicationmessages(void);
void add_job_application2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z);
xmachine_message_job_application2 * add_job_application2_message_internal(void);
xmachine_message_job_application2 * get_first_job_application2_message(void);
xmachine_message_job_application2 * get_next_job_application2_message(xmachine_message_job_application2 * current);
void freejob_application2messages(void);
void add_job_offer_message(int firm_id, int worker_id, int region_id, double wage_offer, double range, double x, double y, double z);
xmachine_message_job_offer * add_job_offer_message_internal(void);
xmachine_message_job_offer * get_first_job_offer_message(void);
xmachine_message_job_offer * get_next_job_offer_message(xmachine_message_job_offer * current);
void freejob_offermessages(void);
void add_job_offer2_message(int firm_id, int worker_id, int region_id, double wage_offer, double range, double x, double y, double z);
xmachine_message_job_offer2 * add_job_offer2_message_internal(void);
xmachine_message_job_offer2 * get_first_job_offer2_message(void);
xmachine_message_job_offer2 * get_next_job_offer2_message(xmachine_message_job_offer2 * current);
void freejob_offer2messages(void);
void add_job_acceptance_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z);
xmachine_message_job_acceptance * add_job_acceptance_message_internal(void);
xmachine_message_job_acceptance * get_first_job_acceptance_message(void);
xmachine_message_job_acceptance * get_next_job_acceptance_message(xmachine_message_job_acceptance * current);
void freejob_acceptancemessages(void);
void add_job_acceptance2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill, double range, double x, double y, double z);
xmachine_message_job_acceptance2 * add_job_acceptance2_message_internal(void);
xmachine_message_job_acceptance2 * get_first_job_acceptance2_message(void);
xmachine_message_job_acceptance2 * get_next_job_acceptance2_message(xmachine_message_job_acceptance2 * current);
void freejob_acceptance2messages(void);
void add_application_rejection_message(int firm_id, int worker_id, double range, double x, double y, double z);
xmachine_message_application_rejection * add_application_rejection_message_internal(void);
xmachine_message_application_rejection * get_first_application_rejection_message(void);
xmachine_message_application_rejection * get_next_application_rejection_message(xmachine_message_application_rejection * current);
void freeapplication_rejectionmessages(void);
void add_application_rejection2_message(int firm_id, int worker_id, double range, double x, double y, double z);
xmachine_message_application_rejection2 * add_application_rejection2_message_internal(void);
xmachine_message_application_rejection2 * get_first_application_rejection2_message(void);
xmachine_message_application_rejection2 * get_next_application_rejection2_message(xmachine_message_application_rejection2 * current);
void freeapplication_rejection2messages(void);
void add_quitting_message(int worker_id, int firm_id, double range, double x, double y, double z);
xmachine_message_quitting * add_quitting_message_internal(void);
xmachine_message_quitting * get_first_quitting_message(void);
xmachine_message_quitting * get_next_quitting_message(xmachine_message_quitting * current);
void freequittingmessages(void);
void add_quitting2_message(int worker_id, int firm_id, double range, double x, double y, double z);
xmachine_message_quitting2 * add_quitting2_message_internal(void);
xmachine_message_quitting2 * get_first_quitting2_message(void);
xmachine_message_quitting2 * get_next_quitting2_message(xmachine_message_quitting2 * current);
void freequitting2messages(void);
void add_productivity_message(int IGfirm_id, double cap_productivity, double cap_good_price, double range, double x, double y, double z);
xmachine_message_productivity * add_productivity_message_internal(void);
xmachine_message_productivity * get_first_productivity_message(void);
xmachine_message_productivity * get_next_productivity_message(xmachine_message_productivity * current);
void freeproductivitymessages(void);
void add_capital_good_request_message(int firm_id, double capital_good_demand, double range, double x, double y, double z);
xmachine_message_capital_good_request * add_capital_good_request_message_internal(void);
xmachine_message_capital_good_request * get_first_capital_good_request_message(void);
xmachine_message_capital_good_request * get_next_capital_good_request_message(xmachine_message_capital_good_request * current);
void freecapital_good_requestmessages(void);
void add_capital_good_profit_distribution_message(double capital_good_profit_shares, double range, double x, double y, double z);
xmachine_message_capital_good_profit_distribution * add_capital_good_profit_distribution_message_internal(void);
xmachine_message_capital_good_profit_distribution * get_first_capital_good_profit_distribution_message(void);
xmachine_message_capital_good_profit_distribution * get_next_capital_good_profit_distribution_message(xmachine_message_capital_good_profit_distribution * current);
void freecapital_good_profit_distributionmessages(void);
void add_capital_good_delivery_message(int firm_id, double capital_good_delivery_volume, double productivity, double capital_good_price, double range, double x, double y, double z);
xmachine_message_capital_good_delivery * add_capital_good_delivery_message_internal(void);
xmachine_message_capital_good_delivery * get_first_capital_good_delivery_message(void);
xmachine_message_capital_good_delivery * get_next_capital_good_delivery_message(xmachine_message_capital_good_delivery * current);
void freecapital_good_deliverymessages(void);
void add_wage_payment_message(int firm_id, int worker_id, double payment, double productivity, double average_specific_skills, double range, double x, double y, double z);
xmachine_message_wage_payment * add_wage_payment_message_internal(void);
xmachine_message_wage_payment * get_first_wage_payment_message(void);
xmachine_message_wage_payment * get_next_wage_payment_message(xmachine_message_wage_payment * current);
void freewage_paymentmessages(void);
void add_quality_price_info_1_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available, double range, double x, double y, double z);
xmachine_message_quality_price_info_1 * add_quality_price_info_1_message_internal(void);
xmachine_message_quality_price_info_1 * get_first_quality_price_info_1_message(void);
xmachine_message_quality_price_info_1 * get_next_quality_price_info_1_message(xmachine_message_quality_price_info_1 * current);
void freequality_price_info_1messages(void);
void add_quality_price_info_2_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available, double range, double x, double y, double z);
xmachine_message_quality_price_info_2 * add_quality_price_info_2_message_internal(void);
xmachine_message_quality_price_info_2 * get_first_quality_price_info_2_message(void);
xmachine_message_quality_price_info_2 * get_next_quality_price_info_2_message(xmachine_message_quality_price_info_2 * current);
void freequality_price_info_2messages(void);
void add_update_mall_stock_message(int mall_id, int firm_id, double quantity, double quality, double price, double range, double x, double y, double z);
xmachine_message_update_mall_stock * add_update_mall_stock_message_internal(void);
xmachine_message_update_mall_stock * get_first_update_mall_stock_message(void);
xmachine_message_update_mall_stock * get_next_update_mall_stock_message(xmachine_message_update_mall_stock * current);
void freeupdate_mall_stockmessages(void);
void add_consumption_request_1_message(int mall_id, int worker_id, int firm_id, double quantity, double range, double x, double y, double z);
xmachine_message_consumption_request_1 * add_consumption_request_1_message_internal(void);
xmachine_message_consumption_request_1 * get_first_consumption_request_1_message(void);
xmachine_message_consumption_request_1 * get_next_consumption_request_1_message(xmachine_message_consumption_request_1 * current);
void freeconsumption_request_1messages(void);
void add_consumption_request_2_message(int mall_id, int worker_id, int firm_id, double quantity, double range, double x, double y, double z);
xmachine_message_consumption_request_2 * add_consumption_request_2_message_internal(void);
xmachine_message_consumption_request_2 * get_first_consumption_request_2_message(void);
xmachine_message_consumption_request_2 * get_next_consumption_request_2_message(xmachine_message_consumption_request_2 * current);
void freeconsumption_request_2messages(void);
void add_accepted_consumption_1_message(int mall_id, int worker_id, double offered_consumption_volume, int rationed, double range, double x, double y, double z);
xmachine_message_accepted_consumption_1 * add_accepted_consumption_1_message_internal(void);
xmachine_message_accepted_consumption_1 * get_first_accepted_consumption_1_message(void);
xmachine_message_accepted_consumption_1 * get_next_accepted_consumption_1_message(xmachine_message_accepted_consumption_1 * current);
void freeaccepted_consumption_1messages(void);
void add_accepted_consumption_2_message(int mall_id, int worker_id, double offered_consumption_volume, int rationed, double range, double x, double y, double z);
xmachine_message_accepted_consumption_2 * add_accepted_consumption_2_message_internal(void);
xmachine_message_accepted_consumption_2 * get_first_accepted_consumption_2_message(void);
xmachine_message_accepted_consumption_2 * get_next_accepted_consumption_2_message(xmachine_message_accepted_consumption_2 * current);
void freeaccepted_consumption_2messages(void);
void add_sales_message(int mall_id, int firm_id, double revenue, int stock_empty, double range, double x, double y, double z);
xmachine_message_sales * add_sales_message_internal(void);
xmachine_message_sales * get_first_sales_message(void);
xmachine_message_sales * get_next_sales_message(xmachine_message_sales * current);
void freesalesmessages(void);
void add_pay_capital_goods_message(int firm_id, double capital_bill, double share_net_investments, double range, double x, double y, double z);
xmachine_message_pay_capital_goods * add_pay_capital_goods_message_internal(void);
xmachine_message_pay_capital_goods * get_first_pay_capital_goods_message(void);
xmachine_message_pay_capital_goods * get_next_pay_capital_goods_message(xmachine_message_pay_capital_goods * current);
void freepay_capital_goodsmessages(void);
void add_current_mall_stock_info_message(int mall_id, int firm_id, double stock, double range, double x, double y, double z);
xmachine_message_current_mall_stock_info * add_current_mall_stock_info_message_internal(void);
xmachine_message_current_mall_stock_info * get_first_current_mall_stock_info_message(void);
xmachine_message_current_mall_stock_info * get_next_current_mall_stock_info_message(xmachine_message_current_mall_stock_info * current);
void freecurrent_mall_stock_infomessages(void);
void add_specific_skill_update_message(int id, int firm_id, double specific_skills, double range, double x, double y, double z);
xmachine_message_specific_skill_update * add_specific_skill_update_message_internal(void);
xmachine_message_specific_skill_update * get_first_specific_skill_update_message(void);
xmachine_message_specific_skill_update * get_next_specific_skill_update_message(xmachine_message_specific_skill_update * current);
void freespecific_skill_updatemessages(void);
void add_firm_send_data_message(int firm_id, int region_id, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double range, double x, double y, double z);
xmachine_message_firm_send_data * add_firm_send_data_message_internal(void);
xmachine_message_firm_send_data * get_first_firm_send_data_message(void);
xmachine_message_firm_send_data * get_next_firm_send_data_message(xmachine_message_firm_send_data * current);
void freefirm_send_datamessages(void);
void add_household_send_data_message(int household_id, int region_id, int general_skill, int employment_status, double wage, double specific_skill, double range, double x, double y, double z);
xmachine_message_household_send_data * add_household_send_data_message_internal(void);
xmachine_message_household_send_data * get_first_household_send_data_message(void);
xmachine_message_household_send_data * get_next_household_send_data_message(xmachine_message_household_send_data * current);
void freehousehold_send_datamessages(void);
void add_market_research_send_specific_skills_message(int region_id, double specific_skill_1, double specific_skill_2, double specific_skill_3, double specific_skill_4, double specific_skill_5, double range, double x, double y, double z);
xmachine_message_market_research_send_specific_skills * add_market_research_send_specific_skills_message_internal(void);
xmachine_message_market_research_send_specific_skills * get_first_market_research_send_specific_skills_message(void);
xmachine_message_market_research_send_specific_skills * get_next_market_research_send_specific_skills_message(xmachine_message_market_research_send_specific_skills * current);
void freemarket_research_send_specific_skillsmessages(void);
void add_tax_payment_message(int firm_id, int gov_id, double tax_payment, double range, double x, double y, double z);
xmachine_message_tax_payment * add_tax_payment_message_internal(void);
xmachine_message_tax_payment * get_first_tax_payment_message(void);
xmachine_message_tax_payment * get_next_tax_payment_message(xmachine_message_tax_payment * current);
void freetax_paymentmessages(void);
void add_interest_payment_message(int firm_id, int bank_id, double interest_payment, double range, double x, double y, double z);
xmachine_message_interest_payment * add_interest_payment_message_internal(void);
xmachine_message_interest_payment * get_first_interest_payment_message(void);
xmachine_message_interest_payment * get_next_interest_payment_message(xmachine_message_interest_payment * current);
void freeinterest_paymentmessages(void);
void add_debt_installment_payment_message(int firm_id, int bank_id, double debt_installment_payment, double range, double x, double y, double z);
xmachine_message_debt_installment_payment * add_debt_installment_payment_message_internal(void);
xmachine_message_debt_installment_payment * get_first_debt_installment_payment_message(void);
xmachine_message_debt_installment_payment * get_next_debt_installment_payment_message(xmachine_message_debt_installment_payment * current);
void freedebt_installment_paymentmessages(void);
void add_dividend_payment_message(int firm_id, double current_dividend_per_share, double range, double x, double y, double z);
xmachine_message_dividend_payment * add_dividend_payment_message_internal(void);
xmachine_message_dividend_payment * get_first_dividend_payment_message(void);
xmachine_message_dividend_payment * get_next_dividend_payment_message(xmachine_message_dividend_payment * current);
void freedividend_paymentmessages(void);
void add_loan_request_message(int firm_id, int bank_id, double credit_amount, double total_assets, double total_debt, double range, double x, double y, double z);
xmachine_message_loan_request * add_loan_request_message_internal(void);
xmachine_message_loan_request * get_first_loan_request_message(void);
xmachine_message_loan_request * get_next_loan_request_message(xmachine_message_loan_request * current);
void freeloan_requestmessages(void);
void add_loan_conditions_message(int bank_id, int firm_id, double proposed_interest_rate, double amount_credit_offer, double range, double x, double y, double z);
xmachine_message_loan_conditions * add_loan_conditions_message_internal(void);
xmachine_message_loan_conditions * get_first_loan_conditions_message(void);
xmachine_message_loan_conditions * get_next_loan_conditions_message(xmachine_message_loan_conditions * current);
void freeloan_conditionsmessages(void);
void add_loan_acceptance_message(int firm_id, int bank_id, double credit_amount_taken, double range, double x, double y, double z);
xmachine_message_loan_acceptance * add_loan_acceptance_message_internal(void);
xmachine_message_loan_acceptance * get_first_loan_acceptance_message(void);
xmachine_message_loan_acceptance * get_next_loan_acceptance_message(xmachine_message_loan_acceptance * current);
void freeloan_acceptancemessages(void);
void add_stock_order_message(int trader_id, int stock_id, double limit_price, double limit_quantity, double range, double x, double y, double z);
xmachine_message_stock_order * add_stock_order_message_internal(void);
xmachine_message_stock_order * get_first_stock_order_message(void);
xmachine_message_stock_order * get_next_stock_order_message(xmachine_message_stock_order * current);
void freestock_ordermessages(void);
void add_stock_transaction_message(int trader_id, int stock_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z);
xmachine_message_stock_transaction * add_stock_transaction_message_internal(void);
xmachine_message_stock_transaction * get_first_stock_transaction_message(void);
xmachine_message_stock_transaction * get_next_stock_transaction_message(xmachine_message_stock_transaction * current);
void freestock_transactionmessages(void);
void add_bond_order_message(int trader_id, int bond_id, double limit_price, double limit_quantity, double range, double x, double y, double z);
xmachine_message_bond_order * add_bond_order_message_internal(void);
xmachine_message_bond_order * get_first_bond_order_message(void);
xmachine_message_bond_order * get_next_bond_order_message(xmachine_message_bond_order * current);
void freebond_ordermessages(void);
void add_bond_transaction_message(int trader_id, int bond_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z);
xmachine_message_bond_transaction * add_bond_transaction_message_internal(void);
xmachine_message_bond_transaction * get_first_bond_transaction_message(void);
xmachine_message_bond_transaction * get_next_bond_transaction_message(xmachine_message_bond_transaction * current);
void freebond_transactionmessages(void);
void add_gov_bond_order_message(int trader_id, int gov_bond_id, double limit_price, double limit_quantity, double range, double x, double y, double z);
xmachine_message_gov_bond_order * add_gov_bond_order_message_internal(void);
xmachine_message_gov_bond_order * get_first_gov_bond_order_message(void);
xmachine_message_gov_bond_order * get_next_gov_bond_order_message(xmachine_message_gov_bond_order * current);
void freegov_bond_ordermessages(void);
void add_gov_bond_transaction_message(int trader_id, int gov_bond_id, double transaction_price, double transaction_quantity, double range, double x, double y, double z);
xmachine_message_gov_bond_transaction * add_gov_bond_transaction_message_internal(void);
xmachine_message_gov_bond_transaction * get_first_gov_bond_transaction_message(void);
xmachine_message_gov_bond_transaction * get_next_gov_bond_transaction_message(xmachine_message_gov_bond_transaction * current);
void freegov_bond_transactionmessages(void);

void set_id(int id);
int get_id();
void set_region_id(int region_id);
int get_region_id();
employee_array * get_employees();
void set_wage_offer(double wage_offer);
double get_wage_offer();
void set_technology(double technology);
double get_technology();
void set_no_employees(int no_employees);
int get_no_employees();
void set_no_employees_skill_1(int no_employees_skill_1);
int get_no_employees_skill_1();
void set_no_employees_skill_2(int no_employees_skill_2);
int get_no_employees_skill_2();
void set_no_employees_skill_3(int no_employees_skill_3);
int get_no_employees_skill_3();
void set_no_employees_skill_4(int no_employees_skill_4);
int get_no_employees_skill_4();
void set_no_employees_skill_5(int no_employees_skill_5);
int get_no_employees_skill_5();
void set_vacancies(int vacancies);
int get_vacancies();
void set_average_g_skill(double average_g_skill);
double get_average_g_skill();
void set_average_s_skill_of_1(double average_s_skill_of_1);
double get_average_s_skill_of_1();
void set_average_s_skill_of_2(double average_s_skill_of_2);
double get_average_s_skill_of_2();
void set_average_s_skill_of_3(double average_s_skill_of_3);
double get_average_s_skill_of_3();
void set_average_s_skill_of_4(double average_s_skill_of_4);
double get_average_s_skill_of_4();
void set_average_s_skill_of_5(double average_s_skill_of_5);
double get_average_s_skill_of_5();
void set_wage_offer_for_skill_1(double wage_offer_for_skill_1);
double get_wage_offer_for_skill_1();
void set_wage_offer_for_skill_2(double wage_offer_for_skill_2);
double get_wage_offer_for_skill_2();
void set_wage_offer_for_skill_3(double wage_offer_for_skill_3);
double get_wage_offer_for_skill_3();
void set_wage_offer_for_skill_4(double wage_offer_for_skill_4);
double get_wage_offer_for_skill_4();
void set_wage_offer_for_skill_5(double wage_offer_for_skill_5);
double get_wage_offer_for_skill_5();
void set_wage_update_was_made(int wage_update_was_made);
int get_wage_update_was_made();
void set_share_net_investments(double share_net_investments);
double get_share_net_investments();
void set_mean_wage(double mean_wage);
double get_mean_wage();
void set_needed_capital_stock(double needed_capital_stock);
double get_needed_capital_stock();
void set_actual_cap_price(double actual_cap_price);
double get_actual_cap_price();
void set_mean_specific_skills(double mean_specific_skills);
double get_mean_specific_skills();
void set_planned_production_quantity(double planned_production_quantity);
double get_planned_production_quantity();
void set_production_quantity(double production_quantity);
double get_production_quantity();
void set_unit_costs(double unit_costs);
double get_unit_costs();
void set_planned_production_costs(double planned_production_costs);
double get_planned_production_costs();
void set_production_costs(double production_costs);
double get_production_costs();
void set_revenue_per_day(double revenue_per_day);
double get_revenue_per_day();
void set_technological_frontier(double technological_frontier);
double get_technological_frontier();
void set_cum_revenue(double cum_revenue);
double get_cum_revenue();
void set_out_of_stock_costs(double out_of_stock_costs);
double get_out_of_stock_costs();
sales_statistics_array * get_malls_sales_statistics();
void set_quality(double quality);
double get_quality();
void set_price(double price);
double get_price();
void set_price_last_month(double price_last_month);
double get_price_last_month();
capital_stock_item_array * get_capital_stock();
void set_total_units_capital_stock(double total_units_capital_stock);
double get_total_units_capital_stock();
void set_total_value_capital_stock(double total_value_capital_stock);
double get_total_value_capital_stock();
void set_total_capital_depreciation_value(double total_capital_depreciation_value);
double get_total_capital_depreciation_value();
void set_total_capital_depreciation_units(double total_capital_depreciation_units);
double get_total_capital_depreciation_units();
void set_employees_needed(int employees_needed);
int get_employees_needed();
sold_quantities_per_mall_array * get_sold_quantities();
void set_total_sold_quantity(double total_sold_quantity);
double get_total_sold_quantity();
void set_cum_total_sold_quantity(double cum_total_sold_quantity);
double get_cum_total_sold_quantity();
delivery_volume_per_mall_array * get_delivery_volume();
delivery_volume_per_mall_array * get_planned_delivery_volume();
mall_info_array * get_current_mall_stocks();
void set_demand_capital_stock(double demand_capital_stock);
double get_demand_capital_stock();
double_array * get_last_planned_production_quantities();
void set_day_of_month_to_act(int day_of_month_to_act);
int get_day_of_month_to_act();
void set_gov_id(int gov_id);
int get_gov_id();
void set_bank_id(int bank_id);
int get_bank_id();
void set_ebit(double ebit);
double get_ebit();
void set_payment_account(double payment_account);
double get_payment_account();
void set_earnings(double earnings);
double get_earnings();
void set_tax_rate_corporate(double tax_rate_corporate);
double get_tax_rate_corporate();
void set_tax_payment(double tax_payment);
double get_tax_payment();
void set_net_earnings(double net_earnings);
double get_net_earnings();
void set_previous_net_earnings(double previous_net_earnings);
double get_previous_net_earnings();
debt_item_array * get_loans();
void set_total_interest_payment(double total_interest_payment);
double get_total_interest_payment();
void set_total_debt_installment_payment(double total_debt_installment_payment);
double get_total_debt_installment_payment();
void set_total_debt(double total_debt);
double get_total_debt();
void set_total_dividend_payment(double total_dividend_payment);
double get_total_dividend_payment();
void set_total_value_local_inventory(double total_value_local_inventory);
double get_total_value_local_inventory();
void set_total_assets(double total_assets);
double get_total_assets();
void set_planned_cum_revenue(double planned_cum_revenue);
double get_planned_cum_revenue();
void set_planned_total_interest_payment(double planned_total_interest_payment);
double get_planned_total_interest_payment();
void set_planned_total_debt_installment_payment(double planned_total_debt_installment_payment);
double get_planned_total_debt_installment_payment();
void set_planned_total_dividend_payment(double planned_total_dividend_payment);
double get_planned_total_dividend_payment();
void set_direct_financial_needs(double direct_financial_needs);
double get_direct_financial_needs();
void set_delayed_financial_needs(double delayed_financial_needs);
double get_delayed_financial_needs();
void set_total_financial_needs(double total_financial_needs);
double get_total_financial_needs();
void set_internal_financial_needs(double internal_financial_needs);
double get_internal_financial_needs();
void set_external_financial_needs(double external_financial_needs);
double get_external_financial_needs();
void set_total_external_financing_obtained(double total_external_financing_obtained);
double get_total_external_financing_obtained();
void set_direct_financial_needs_require_external_financing(int direct_financial_needs_require_external_financing);
int get_direct_financial_needs_require_external_financing();
void set_delayed_financial_needs_require_external_financing(int delayed_financial_needs_require_external_financing);
int get_delayed_financial_needs_require_external_financing();
void set_current_share_price(double current_share_price);
double get_current_share_price();
void set_current_shares_outstanding(double current_shares_outstanding);
double get_current_shares_outstanding();
void set_previous_dividend_per_share(double previous_dividend_per_share);
double get_previous_dividend_per_share();
void set_current_dividend_per_share(double current_dividend_per_share);
double get_current_dividend_per_share();
void set_previous_dividend_per_earnings(double previous_dividend_per_earnings);
double get_previous_dividend_per_earnings();
void set_current_dividend_per_earnings(double current_dividend_per_earnings);
double get_current_dividend_per_earnings();
void set_earnings_per_share_ratio(double earnings_per_share_ratio);
double get_earnings_per_share_ratio();
void set_debt_earnings_ratio(double debt_earnings_ratio);
double get_debt_earnings_ratio();
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
void set_target_loans(double target_loans);
double get_target_loans();
void set_target_equity(double target_equity);
double get_target_equity();
void set_bonds_issue_target(double bonds_issue_target);
double get_bonds_issue_target();
void set_stocks_issue_target(double stocks_issue_target);
double get_stocks_issue_target();
void set_range(double range);
double get_range();
void set_posx(double posx);
double get_posx();
void set_posy(double posy);
double get_posy();
int_array * get_neighboring_region_ids();
void set_wage(double wage);
double get_wage();
void set_wage_reservation(double wage_reservation);
double get_wage_reservation();
void set_general_skill(int general_skill);
int get_general_skill();
void set_on_the_job_search(int on_the_job_search);
int get_on_the_job_search();
void set_number_applications(int number_applications);
int get_number_applications();
void set_specific_skill(double specific_skill);
double get_specific_skill();
void set_employee_firm_id(int employee_firm_id);
int get_employee_firm_id();
void set_employer_region_id(int employer_region_id);
int get_employer_region_id();
void set_budget(double budget);
double get_budget();
void set_week_of_month(int week_of_month);
int get_week_of_month();
void set_weekly_budget(double weekly_budget);
double get_weekly_budget();
void set_expenditures(double expenditures);
double get_expenditures();
void set_received_dividend_cap(double received_dividend_cap);
double get_received_dividend_cap();
void set_received_dividend_cons(double received_dividend_cons);
double get_received_dividend_cons();
void set_savings(double savings);
double get_savings();
double_array * get_last_income();
void set_rationed(int rationed);
int get_rationed();
void set_mall_completely_sold_out(int mall_completely_sold_out);
int get_mall_completely_sold_out();
ordered_quantity * get_order_quantity();
received_quantities * get_received_quantity();
void set_day_of_week_to_act(int day_of_week_to_act);
int get_day_of_week_to_act();
mall_stock_array * get_current_stock();
sales_in_mall_array * get_firm_revenues();
void set_total_supply(double total_supply);
double get_total_supply();
void set_productivity(double productivity);
double get_productivity();
void set_innovation_probability(int innovation_probability);
int get_innovation_probability();
void set_productivity_progress(double productivity_progress);
double get_productivity_progress();
void set_capital_good_price(double capital_good_price);
double get_capital_good_price();
void set_no_regions(int no_regions);
int get_no_regions();
void set_num_households(int num_households);
int get_num_households();
void set_no_households_skill_1(int no_households_skill_1);
int get_no_households_skill_1();
void set_no_households_skill_2(int no_households_skill_2);
int get_no_households_skill_2();
void set_no_households_skill_3(int no_households_skill_3);
int get_no_households_skill_3();
void set_no_households_skill_4(int no_households_skill_4);
int get_no_households_skill_4();
void set_no_households_skill_5(int no_households_skill_5);
int get_no_households_skill_5();
void set_employed(int employed);
int get_employed();
void set_employed_skill_1(int employed_skill_1);
int get_employed_skill_1();
void set_employed_skill_2(int employed_skill_2);
int get_employed_skill_2();
void set_employed_skill_3(int employed_skill_3);
int get_employed_skill_3();
void set_employed_skill_4(int employed_skill_4);
int get_employed_skill_4();
void set_employed_skill_5(int employed_skill_5);
int get_employed_skill_5();
void set_unemployed(int unemployed);
int get_unemployed();
void set_unemployment_rate(double unemployment_rate);
double get_unemployment_rate();
void set_unemployment_rate_skill_1(double unemployment_rate_skill_1);
double get_unemployment_rate_skill_1();
void set_unemployment_rate_skill_2(double unemployment_rate_skill_2);
double get_unemployment_rate_skill_2();
void set_unemployment_rate_skill_3(double unemployment_rate_skill_3);
double get_unemployment_rate_skill_3();
void set_unemployment_rate_skill_4(double unemployment_rate_skill_4);
double get_unemployment_rate_skill_4();
void set_unemployment_rate_skill_5(double unemployment_rate_skill_5);
double get_unemployment_rate_skill_5();
void set_average_wage(double average_wage);
double get_average_wage();
void set_average_wage_skill_1(double average_wage_skill_1);
double get_average_wage_skill_1();
void set_average_wage_skill_2(double average_wage_skill_2);
double get_average_wage_skill_2();
void set_average_wage_skill_3(double average_wage_skill_3);
double get_average_wage_skill_3();
void set_average_wage_skill_4(double average_wage_skill_4);
double get_average_wage_skill_4();
void set_average_wage_skill_5(double average_wage_skill_5);
double get_average_wage_skill_5();
void set_average_s_skill(double average_s_skill);
double get_average_s_skill();
void set_average_s_skill_1(double average_s_skill_1);
double get_average_s_skill_1();
void set_average_s_skill_2(double average_s_skill_2);
double get_average_s_skill_2();
void set_average_s_skill_3(double average_s_skill_3);
double get_average_s_skill_3();
void set_average_s_skill_4(double average_s_skill_4);
double get_average_s_skill_4();
void set_average_s_skill_5(double average_s_skill_5);
double get_average_s_skill_5();
void set_no_firms(int no_firms);
int get_no_firms();
void set_no_vacancies(int no_vacancies);
int get_no_vacancies();
void set_firm_average_wage(double firm_average_wage);
double get_firm_average_wage();
void set_firm_average_wage_skill_1(double firm_average_wage_skill_1);
double get_firm_average_wage_skill_1();
void set_firm_average_wage_skill_2(double firm_average_wage_skill_2);
double get_firm_average_wage_skill_2();
void set_firm_average_wage_skill_3(double firm_average_wage_skill_3);
double get_firm_average_wage_skill_3();
void set_firm_average_wage_skill_4(double firm_average_wage_skill_4);
double get_firm_average_wage_skill_4();
void set_firm_average_wage_skill_5(double firm_average_wage_skill_5);
double get_firm_average_wage_skill_5();
void set_firm_average_s_skill(double firm_average_s_skill);
double get_firm_average_s_skill();
void set_firm_average_s_skill_1(double firm_average_s_skill_1);
double get_firm_average_s_skill_1();
void set_firm_average_s_skill_2(double firm_average_s_skill_2);
double get_firm_average_s_skill_2();
void set_firm_average_s_skill_3(double firm_average_s_skill_3);
double get_firm_average_s_skill_3();
void set_firm_average_s_skill_4(double firm_average_s_skill_4);
double get_firm_average_s_skill_4();
void set_firm_average_s_skill_5(double firm_average_s_skill_5);
double get_firm_average_s_skill_5();
firm_data_array * get_region_firm_data();
household_data_array * get_region_household_data();
void set_trader_id(int trader_id);
int get_trader_id();
void set_stock_id(int stock_id);
int get_stock_id();
void set_bond_id(int bond_id);
int get_bond_id();
void set_gov_bond_id(int gov_bond_id);
int get_gov_bond_id();
void set_limit_price(double limit_price);
double get_limit_price();
void set_limit_quantity(double limit_quantity);
double get_limit_quantity();
void set_proposed_interest_rate(double proposed_interest_rate);
double get_proposed_interest_rate();
void set_amount_credit_offer(double amount_credit_offer);
double get_amount_credit_offer();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[6], int partitions, int partition_method);

/* messageboard.c */
xmachine_message_vacancies * get_next_message_vacancies_in_range(xmachine_message_vacancies * current);
xmachine_message_vacancies2 * get_next_message_vacancies2_in_range(xmachine_message_vacancies2 * current);
xmachine_message_firing * get_next_message_firing_in_range(xmachine_message_firing * current);
xmachine_message_job_application * get_next_message_job_application_in_range(xmachine_message_job_application * current);
xmachine_message_job_application2 * get_next_message_job_application2_in_range(xmachine_message_job_application2 * current);
xmachine_message_job_offer * get_next_message_job_offer_in_range(xmachine_message_job_offer * current);
xmachine_message_job_offer2 * get_next_message_job_offer2_in_range(xmachine_message_job_offer2 * current);
xmachine_message_job_acceptance * get_next_message_job_acceptance_in_range(xmachine_message_job_acceptance * current);
xmachine_message_job_acceptance2 * get_next_message_job_acceptance2_in_range(xmachine_message_job_acceptance2 * current);
xmachine_message_application_rejection * get_next_message_application_rejection_in_range(xmachine_message_application_rejection * current);
xmachine_message_application_rejection2 * get_next_message_application_rejection2_in_range(xmachine_message_application_rejection2 * current);
xmachine_message_quitting * get_next_message_quitting_in_range(xmachine_message_quitting * current);
xmachine_message_quitting2 * get_next_message_quitting2_in_range(xmachine_message_quitting2 * current);
xmachine_message_productivity * get_next_message_productivity_in_range(xmachine_message_productivity * current);
xmachine_message_capital_good_request * get_next_message_capital_good_request_in_range(xmachine_message_capital_good_request * current);
xmachine_message_capital_good_profit_distribution * get_next_message_capital_good_profit_distribution_in_range(xmachine_message_capital_good_profit_distribution * current);
xmachine_message_capital_good_delivery * get_next_message_capital_good_delivery_in_range(xmachine_message_capital_good_delivery * current);
xmachine_message_wage_payment * get_next_message_wage_payment_in_range(xmachine_message_wage_payment * current);
xmachine_message_quality_price_info_1 * get_next_message_quality_price_info_1_in_range(xmachine_message_quality_price_info_1 * current);
xmachine_message_quality_price_info_2 * get_next_message_quality_price_info_2_in_range(xmachine_message_quality_price_info_2 * current);
xmachine_message_update_mall_stock * get_next_message_update_mall_stock_in_range(xmachine_message_update_mall_stock * current);
xmachine_message_consumption_request_1 * get_next_message_consumption_request_1_in_range(xmachine_message_consumption_request_1 * current);
xmachine_message_consumption_request_2 * get_next_message_consumption_request_2_in_range(xmachine_message_consumption_request_2 * current);
xmachine_message_accepted_consumption_1 * get_next_message_accepted_consumption_1_in_range(xmachine_message_accepted_consumption_1 * current);
xmachine_message_accepted_consumption_2 * get_next_message_accepted_consumption_2_in_range(xmachine_message_accepted_consumption_2 * current);
xmachine_message_sales * get_next_message_sales_in_range(xmachine_message_sales * current);
xmachine_message_pay_capital_goods * get_next_message_pay_capital_goods_in_range(xmachine_message_pay_capital_goods * current);
xmachine_message_current_mall_stock_info * get_next_message_current_mall_stock_info_in_range(xmachine_message_current_mall_stock_info * current);
xmachine_message_specific_skill_update * get_next_message_specific_skill_update_in_range(xmachine_message_specific_skill_update * current);
xmachine_message_firm_send_data * get_next_message_firm_send_data_in_range(xmachine_message_firm_send_data * current);
xmachine_message_household_send_data * get_next_message_household_send_data_in_range(xmachine_message_household_send_data * current);
xmachine_message_market_research_send_specific_skills * get_next_message_market_research_send_specific_skills_in_range(xmachine_message_market_research_send_specific_skills * current);
xmachine_message_tax_payment * get_next_message_tax_payment_in_range(xmachine_message_tax_payment * current);
xmachine_message_interest_payment * get_next_message_interest_payment_in_range(xmachine_message_interest_payment * current);
xmachine_message_debt_installment_payment * get_next_message_debt_installment_payment_in_range(xmachine_message_debt_installment_payment * current);
xmachine_message_dividend_payment * get_next_message_dividend_payment_in_range(xmachine_message_dividend_payment * current);
xmachine_message_loan_request * get_next_message_loan_request_in_range(xmachine_message_loan_request * current);
xmachine_message_loan_conditions * get_next_message_loan_conditions_in_range(xmachine_message_loan_conditions * current);
xmachine_message_loan_acceptance * get_next_message_loan_acceptance_in_range(xmachine_message_loan_acceptance * current);
xmachine_message_stock_order * get_next_message_stock_order_in_range(xmachine_message_stock_order * current);
xmachine_message_stock_transaction * get_next_message_stock_transaction_in_range(xmachine_message_stock_transaction * current);
xmachine_message_bond_order * get_next_message_bond_order_in_range(xmachine_message_bond_order * current);
xmachine_message_bond_transaction * get_next_message_bond_transaction_in_range(xmachine_message_bond_transaction * current);
xmachine_message_gov_bond_order * get_next_message_gov_bond_order_in_range(xmachine_message_gov_bond_order * current);
xmachine_message_gov_bond_transaction * get_next_message_gov_bond_transaction_in_range(xmachine_message_gov_bond_transaction * current);

/* memory.c */
xmachine * add_xmachine(void);
