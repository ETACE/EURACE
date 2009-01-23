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


/** \def PRINT_LOG
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_LOG print_log
/** \def PRINT_DEBUG
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG print_debug
/** \def DAY
 * \brief Provide access to environment variables in uppercase. */
#define DAY day
/** \def WEEK
 * \brief Provide access to environment variables in uppercase. */
#define WEEK week
/** \def MONTH
 * \brief Provide access to environment variables in uppercase. */
#define MONTH month
/** \def QUARTER
 * \brief Provide access to environment variables in uppercase. */
#define QUARTER quarter
/** \def YEAR
 * \brief Provide access to environment variables in uppercase. */
#define YEAR year
/** \def NUMBER_OF_BANKS_TO_APPLY
 * \brief Provide access to environment variables in uppercase. */
#define NUMBER_OF_BANKS_TO_APPLY number_of_banks_to_apply
/** \def GAMMA_CONST
 * \brief Provide access to environment variables in uppercase. */
#define GAMMA_CONST gamma_const
/** \def ALPHA
 * \brief Provide access to environment variables in uppercase. */
#define ALPHA alpha
/** \def BETA
 * \brief Provide access to environment variables in uppercase. */
#define BETA beta
/** \def DEPRECIATION_RATE
 * \brief Provide access to environment variables in uppercase. */
#define DEPRECIATION_RATE depreciation_rate
/** \def DISCOUNT_RATE
 * \brief Provide access to environment variables in uppercase. */
#define DISCOUNT_RATE discount_rate
/** \def TETA
 * \brief Provide access to environment variables in uppercase. */
#define TETA teta
/** \def MARK_UP
 * \brief Provide access to environment variables in uppercase. */
#define MARK_UP mark_up
/** \def LAMBDA
 * \brief Provide access to environment variables in uppercase. */
#define LAMBDA lambda
/** \def WAGE_UPDATE
 * \brief Provide access to environment variables in uppercase. */
#define WAGE_UPDATE wage_update
/** \def MIN_VACANCY
 * \brief Provide access to environment variables in uppercase. */
#define MIN_VACANCY min_vacancy
/** \def WAGE_RESERVATION_UPDATE
 * \brief Provide access to environment variables in uppercase. */
#define WAGE_RESERVATION_UPDATE wage_reservation_update
/** \def REGION_COST
 * \brief Provide access to environment variables in uppercase. */
#define REGION_COST region_cost
/** \def INVENTORY_COSTS_PER_UNIT
 * \brief Provide access to environment variables in uppercase. */
#define INVENTORY_COSTS_PER_UNIT inventory_costs_per_unit
/** \def ON_THE_JOB_SEARCH_RATE
 * \brief Provide access to environment variables in uppercase. */
#define ON_THE_JOB_SEARCH_RATE on_the_job_search_rate
/** \def INITIAL_CONSUMPTION_PROPENSITY
 * \brief Provide access to environment variables in uppercase. */
#define INITIAL_CONSUMPTION_PROPENSITY initial_consumption_propensity
/** \def CONSUMPTION_PROPENSITY
 * \brief Provide access to environment variables in uppercase. */
#define CONSUMPTION_PROPENSITY consumption_propensity
/** \def FIRM_PLANNING_HORIZON
 * \brief Provide access to environment variables in uppercase. */
#define FIRM_PLANNING_HORIZON firm_planning_horizon
/** \def INV_INERTIA
 * \brief Provide access to environment variables in uppercase. */
#define INV_INERTIA inv_inertia
/** \def ADAPTION_DELIVERY_VOLUME
 * \brief Provide access to environment variables in uppercase. */
#define ADAPTION_DELIVERY_VOLUME adaption_delivery_volume
/** \def PERIODS_TO_REPAY_LOANS
 * \brief Provide access to environment variables in uppercase. */
#define PERIODS_TO_REPAY_LOANS periods_to_repay_loans
/** \def DELIVERY_PROB_IF_CRITICAL_STOCK_0
 * \brief Provide access to environment variables in uppercase. */
#define DELIVERY_PROB_IF_CRITICAL_STOCK_0 delivery_prob_if_critical_stock_0
/** \def INNOVATION_PROBABILITY
 * \brief Provide access to environment variables in uppercase. */
#define INNOVATION_PROBABILITY innovation_probability
/** \def PRODUCTIVITY_PROGRESS
 * \brief Provide access to environment variables in uppercase. */
#define PRODUCTIVITY_PROGRESS productivity_progress
/** \def CONST_BANKRUPTCY_IDLE_PERIOD
 * \brief Provide access to environment variables in uppercase. */
#define CONST_BANKRUPTCY_IDLE_PERIOD const_bankruptcy_idle_period
/** \def DEBT_RESCALING_FACTOR
 * \brief Provide access to environment variables in uppercase. */
#define DEBT_RESCALING_FACTOR debt_rescaling_factor
/** \def TARGET_LEVERAGE_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define TARGET_LEVERAGE_RATIO target_leverage_ratio
/** \def TARGET_LIQUIDITY_RATIO
 * \brief Provide access to environment variables in uppercase. */
#define TARGET_LIQUIDITY_RATIO target_liquidity_ratio
/** \def TRADING_ACTIVITY
 * \brief Provide access to environment variables in uppercase. */
#define TRADING_ACTIVITY trading_activity
/** \def BONDS_NEWISSUE_DISCOUNT
 * \brief Provide access to environment variables in uppercase. */
#define BONDS_NEWISSUE_DISCOUNT BONDS_NEWISSUE_DISCOUNT
/** \def GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT gov_policy_unemployment_benefit_pct
/** \def GOV_POLICY_MONEY_FINANCING_FRACTION
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_MONEY_FINANCING_FRACTION gov_policy_money_financing_fraction
/** \def GOV_POLICY_GDP_FRACTION_CONSUMPTION
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_GDP_FRACTION_CONSUMPTION gov_policy_gdp_fraction_consumption
/** \def GOV_POLICY_GDP_FRACTION_INVESTMENT
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_GDP_FRACTION_INVESTMENT gov_policy_gdp_fraction_investment
/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5
/** \def START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process bank_account_update messages. */
#define START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP  bank_account_update_message = get_first_bank_account_update_message(); while(bank_account_update_message) {
/** \def FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process bank_account_update messages. */
#define FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP bank_account_update_message = get_next_bank_account_update_message(bank_account_update_message); }
/** \def START_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process central_bank_account_update messages. */
#define START_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP  central_bank_account_update_message = get_first_central_bank_account_update_message(); while(central_bank_account_update_message) {
/** \def FINISH_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process central_bank_account_update messages. */
#define FINISH_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP central_bank_account_update_message = get_next_central_bank_account_update_message(central_bank_account_update_message); }
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
/** \def START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process specific_skill_update messages. */
#define START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP  specific_skill_update_message = get_first_specific_skill_update_message(); while(specific_skill_update_message) {
/** \def FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process specific_skill_update messages. */
#define FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP specific_skill_update_message = get_next_specific_skill_update_message(specific_skill_update_message); }
/** \def START_DAILY_REVENUE_TO_BANK_MESSAGE_LOOP
 * \brief Start of loop to process daily_revenue_to_bank messages. */
#define START_DAILY_REVENUE_TO_BANK_MESSAGE_LOOP  daily_revenue_to_bank_message = get_first_daily_revenue_to_bank_message(); while(daily_revenue_to_bank_message) {
/** \def FINISH_DAILY_REVENUE_TO_BANK_MESSAGE_LOOP
 * \brief Finish of loop to process daily_revenue_to_bank messages. */
#define FINISH_DAILY_REVENUE_TO_BANK_MESSAGE_LOOP daily_revenue_to_bank_message = get_next_daily_revenue_to_bank_message(daily_revenue_to_bank_message); }
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
/** \def START_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP
 * \brief Start of loop to process current_mall_stock_info messages. */
#define START_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP  current_mall_stock_info_message = get_first_current_mall_stock_info_message(); while(current_mall_stock_info_message) {
/** \def FINISH_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP
 * \brief Finish of loop to process current_mall_stock_info messages. */
#define FINISH_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP current_mall_stock_info_message = get_next_current_mall_stock_info_message(current_mall_stock_info_message); }
/** \def START_DIVIDEND_PER_SHARE_MESSAGE_LOOP
 * \brief Start of loop to process dividend_per_share messages. */
#define START_DIVIDEND_PER_SHARE_MESSAGE_LOOP  dividend_per_share_message = get_first_dividend_per_share_message(); while(dividend_per_share_message) {
/** \def FINISH_DIVIDEND_PER_SHARE_MESSAGE_LOOP
 * \brief Finish of loop to process dividend_per_share messages. */
#define FINISH_DIVIDEND_PER_SHARE_MESSAGE_LOOP dividend_per_share_message = get_next_dividend_per_share_message(dividend_per_share_message); }
/** \def START_BANKRUPTCY_ILLIQUIDITY_MESSAGE_LOOP
 * \brief Start of loop to process bankruptcy_illiquidity messages. */
#define START_BANKRUPTCY_ILLIQUIDITY_MESSAGE_LOOP  bankruptcy_illiquidity_message = get_first_bankruptcy_illiquidity_message(); while(bankruptcy_illiquidity_message) {
/** \def FINISH_BANKRUPTCY_ILLIQUIDITY_MESSAGE_LOOP
 * \brief Finish of loop to process bankruptcy_illiquidity messages. */
#define FINISH_BANKRUPTCY_ILLIQUIDITY_MESSAGE_LOOP bankruptcy_illiquidity_message = get_next_bankruptcy_illiquidity_message(bankruptcy_illiquidity_message); }
/** \def START_BANKRUPTCY_INSOLVENCY_MESSAGE_LOOP
 * \brief Start of loop to process bankruptcy_insolvency messages. */
#define START_BANKRUPTCY_INSOLVENCY_MESSAGE_LOOP  bankruptcy_insolvency_message = get_first_bankruptcy_insolvency_message(); while(bankruptcy_insolvency_message) {
/** \def FINISH_BANKRUPTCY_INSOLVENCY_MESSAGE_LOOP
 * \brief Finish of loop to process bankruptcy_insolvency messages. */
#define FINISH_BANKRUPTCY_INSOLVENCY_MESSAGE_LOOP bankruptcy_insolvency_message = get_next_bankruptcy_insolvency_message(bankruptcy_insolvency_message); }
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
/** \def START_INFOASSETCH_MESSAGE_LOOP
 * \brief Start of loop to process infoAssetCH messages. */
#define START_INFOASSETCH_MESSAGE_LOOP  infoAssetCH_message = get_first_infoAssetCH_message(); while(infoAssetCH_message) {
/** \def FINISH_INFOASSETCH_MESSAGE_LOOP
 * \brief Finish of loop to process infoAssetCH messages. */
#define FINISH_INFOASSETCH_MESSAGE_LOOP infoAssetCH_message = get_next_infoAssetCH_message(infoAssetCH_message); }
/** \def START_INFO_FIRM_MESSAGE_LOOP
 * \brief Start of loop to process info_firm messages. */
#define START_INFO_FIRM_MESSAGE_LOOP  info_firm_message = get_first_info_firm_message(); while(info_firm_message) {
/** \def FINISH_INFO_FIRM_MESSAGE_LOOP
 * \brief Finish of loop to process info_firm messages. */
#define FINISH_INFO_FIRM_MESSAGE_LOOP info_firm_message = get_next_info_firm_message(info_firm_message); }
/** \def START_ACCOUNTINTEREST_MESSAGE_LOOP
 * \brief Start of loop to process accountInterest messages. */
#define START_ACCOUNTINTEREST_MESSAGE_LOOP  accountInterest_message = get_first_accountInterest_message(); while(accountInterest_message) {
/** \def FINISH_ACCOUNTINTEREST_MESSAGE_LOOP
 * \brief Finish of loop to process accountInterest messages. */
#define FINISH_ACCOUNTINTEREST_MESSAGE_LOOP accountInterest_message = get_next_accountInterest_message(accountInterest_message); }
/** \def START_BANKACCOUNTUPDATE_MESSAGE_LOOP
 * \brief Start of loop to process bankAccountUpdate messages. */
#define START_BANKACCOUNTUPDATE_MESSAGE_LOOP  bankAccountUpdate_message = get_first_bankAccountUpdate_message(); while(bankAccountUpdate_message) {
/** \def FINISH_BANKACCOUNTUPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process bankAccountUpdate messages. */
#define FINISH_BANKACCOUNTUPDATE_MESSAGE_LOOP bankAccountUpdate_message = get_next_bankAccountUpdate_message(bankAccountUpdate_message); }
/** \def START_INFO_BOND_MESSAGE_LOOP
 * \brief Start of loop to process info_bond messages. */
#define START_INFO_BOND_MESSAGE_LOOP  info_bond_message = get_first_info_bond_message(); while(info_bond_message) {
/** \def FINISH_INFO_BOND_MESSAGE_LOOP
 * \brief Finish of loop to process info_bond messages. */
#define FINISH_INFO_BOND_MESSAGE_LOOP info_bond_message = get_next_info_bond_message(info_bond_message); }
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
/** \def START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process unemployment_notification messages. */
#define START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP  unemployment_notification_message = get_first_unemployment_notification_message(); while(unemployment_notification_message) {
/** \def FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process unemployment_notification messages. */
#define FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP unemployment_notification_message = get_next_unemployment_notification_message(unemployment_notification_message); }
/** \def START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
 * \brief Start of loop to process policy_announcement messages. */
#define START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP  policy_announcement_message = get_first_policy_announcement_message(); while(policy_announcement_message) {
/** \def FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
 * \brief Finish of loop to process policy_announcement messages. */
#define FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP policy_announcement_message = get_next_policy_announcement_message(policy_announcement_message); }
/** \def START_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process tax_payment messages. */
#define START_TAX_PAYMENT_MESSAGE_LOOP  tax_payment_message = get_first_tax_payment_message(); while(tax_payment_message) {
/** \def FINISH_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process tax_payment messages. */
#define FINISH_TAX_PAYMENT_MESSAGE_LOOP tax_payment_message = get_next_tax_payment_message(tax_payment_message); }
/** \def START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process hh_transfer_notification messages. */
#define START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP  hh_transfer_notification_message = get_first_hh_transfer_notification_message(); while(hh_transfer_notification_message) {
/** \def FINISH_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process hh_transfer_notification messages. */
#define FINISH_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP hh_transfer_notification_message = get_next_hh_transfer_notification_message(hh_transfer_notification_message); }
/** \def START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process hh_subsidy_notification messages. */
#define START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP  hh_subsidy_notification_message = get_first_hh_subsidy_notification_message(); while(hh_subsidy_notification_message) {
/** \def FINISH_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process hh_subsidy_notification messages. */
#define FINISH_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP hh_subsidy_notification_message = get_next_hh_subsidy_notification_message(hh_subsidy_notification_message); }
/** \def START_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process firm_transfer_notification messages. */
#define START_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP  firm_transfer_notification_message = get_first_firm_transfer_notification_message(); while(firm_transfer_notification_message) {
/** \def FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process firm_transfer_notification messages. */
#define FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP firm_transfer_notification_message = get_next_firm_transfer_notification_message(firm_transfer_notification_message); }
/** \def START_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process firm_subsidy_notification messages. */
#define START_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP  firm_subsidy_notification_message = get_first_firm_subsidy_notification_message(); while(firm_subsidy_notification_message) {
/** \def FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process firm_subsidy_notification messages. */
#define FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP firm_subsidy_notification_message = get_next_firm_subsidy_notification_message(firm_subsidy_notification_message); }
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
/** \def START_MALL_DATA_MESSAGE_LOOP
 * \brief Start of loop to process mall_data messages. */
#define START_MALL_DATA_MESSAGE_LOOP  mall_data_message = get_first_mall_data_message(); while(mall_data_message) {
/** \def FINISH_MALL_DATA_MESSAGE_LOOP
 * \brief Finish of loop to process mall_data messages. */
#define FINISH_MALL_DATA_MESSAGE_LOOP mall_data_message = get_next_mall_data_message(mall_data_message); }
/** \def START_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
 * \brief Start of loop to process eurostat_send_specific_skills messages. */
#define START_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP  eurostat_send_specific_skills_message = get_first_eurostat_send_specific_skills_message(); while(eurostat_send_specific_skills_message) {
/** \def FINISH_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
 * \brief Finish of loop to process eurostat_send_specific_skills messages. */
#define FINISH_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP eurostat_send_specific_skills_message = get_next_eurostat_send_specific_skills_message(eurostat_send_specific_skills_message); }
/** \def START_MEAN_WAGE_FOR_GOVERNMENT_MESSAGE_LOOP
 * \brief Start of loop to process mean_wage_for_government messages. */
#define START_MEAN_WAGE_FOR_GOVERNMENT_MESSAGE_LOOP  mean_wage_for_government_message = get_first_mean_wage_for_government_message(); while(mean_wage_for_government_message) {
/** \def FINISH_MEAN_WAGE_FOR_GOVERNMENT_MESSAGE_LOOP
 * \brief Finish of loop to process mean_wage_for_government messages. */
#define FINISH_MEAN_WAGE_FOR_GOVERNMENT_MESSAGE_LOOP mean_wage_for_government_message = get_next_mean_wage_for_government_message(mean_wage_for_government_message); }
/** \def START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
 * \brief Start of loop to process data_for_government messages. */
#define START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP  data_for_government_message = get_first_data_for_government_message(); while(data_for_government_message) {
/** \def FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
 * \brief Finish of loop to process data_for_government messages. */
#define FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP data_for_government_message = get_next_data_for_government_message(data_for_government_message); }

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
	int consumer_region_id;	/**< Datatype memory variable consumer_region_id of type int. */
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
	int region_id;	/**< Datatype memory variable region_id of type int. */
	double stock;	/**< Datatype memory variable stock of type double. */
	double price;	/**< Datatype memory variable price of type double. */
	double quality;	/**< Datatype memory variable quality of type double. */
	double previous_price;	/**< Datatype memory variable previous_price of type double. */
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
 * \brief .
 *
 * .
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
 * \brief .
 *
 * .
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
 * \brief .
 *
 * .
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
/** \struct financing_capital
 * \brief .
 *
 * .
 */
struct financing_capital
{
	double financing_per_month;	/**< Datatype memory variable financing_per_month of type double. */
	int nr_periods_before_repayment;	/**< Datatype memory variable nr_periods_before_repayment of type int. */
};

/** \struct financing_capital_array
 * \brief Dynamic array to hold financing_capitals
 */
struct financing_capital_array
{
	int size;
	int total_size;
	
	struct financing_capital * array;
};

/** \var typedef financing_capital financing_capital
 * \brief Typedef for financing_capital struct.
 */
typedef struct financing_capital financing_capital;
/** \var typedef financing_capital_array financing_capital_array
 * \brief Typedef for financing_capital_array struct.
 */
typedef struct financing_capital_array financing_capital_array;
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
/** \struct account_item
 * \brief .
 *
 * .
 */
struct account_item
{
	int id;	/**< Datatype memory variable id of type int. */
	double payment_account;	/**< Datatype memory variable payment_account of type double. */
};

/** \struct account_item_array
 * \brief Dynamic array to hold account_items
 */
struct account_item_array
{
	int size;
	int total_size;
	
	struct account_item * array;
};

/** \var typedef account_item account_item
 * \brief Typedef for account_item struct.
 */
typedef struct account_item account_item;
/** \var typedef account_item_array account_item_array
 * \brief Typedef for account_item_array struct.
 */
typedef struct account_item_array account_item_array;
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
/** \struct Order
 * \brief .
 *
 * .
 */
struct Order
{
	int issuer;	/**< Datatype memory variable issuer of type int. */
	int quantity;	/**< Datatype memory variable quantity of type int. */
	double price;	/**< Datatype memory variable price of type double. */
	int assetId;	/**< Datatype memory variable assetId of type int. */
};

/** \struct Order_array
 * \brief Dynamic array to hold Orders
 */
struct Order_array
{
	int size;
	int total_size;
	
	struct Order * array;
};

/** \var typedef Order Order
 * \brief Typedef for Order struct.
 */
typedef struct Order Order;
/** \var typedef Order_array Order_array
 * \brief Typedef for Order_array struct.
 */
typedef struct Order_array Order_array;
/** \struct Belief
 * \brief .
 *
 * .
 */
struct Belief
{
	int asset_id;	/**< Datatype memory variable asset_id of type int. */
	double expectedPriceReturns;	/**< Datatype memory variable expectedPriceReturns of type double. */
	double expectedTotalReturns;	/**< Datatype memory variable expectedTotalReturns of type double. */
	double expectedCashFlowYield;	/**< Datatype memory variable expectedCashFlowYield of type double. */
	double volatility;	/**< Datatype memory variable volatility of type double. */
	double expectedEarning;	/**< Datatype memory variable expectedEarning of type double. */
	double expectedEarningPayout;	/**< Datatype memory variable expectedEarningPayout of type double. */
	double last_price;	/**< Datatype memory variable last_price of type double. */
	double utility;	/**< Datatype memory variable utility of type double. */
};

/** \struct Belief_array
 * \brief Dynamic array to hold Beliefs
 */
struct Belief_array
{
	int size;
	int total_size;
	
	struct Belief * array;
};

/** \var typedef Belief Belief
 * \brief Typedef for Belief struct.
 */
typedef struct Belief Belief;
/** \var typedef Belief_array Belief_array
 * \brief Typedef for Belief_array struct.
 */
typedef struct Belief_array Belief_array;
/** \struct Stock
 * \brief .
 *
 * .
 */
struct Stock
{
	int id;	/**< Datatype memory variable id of type int. */
	int nrOutStandingShares;	/**< Datatype memory variable nrOutStandingShares of type int. */
	int index;	/**< Datatype memory variable index of type int. */
	double prices[100];	/**< Datatype memory variable prices of type double. */
	double returns[100];	/**< Datatype memory variable returns of type double. */
};

/** \struct Stock_array
 * \brief Dynamic array to hold Stocks
 */
struct Stock_array
{
	int size;
	int total_size;
	
	struct Stock * array;
};

/** \var typedef Stock Stock
 * \brief Typedef for Stock struct.
 */
typedef struct Stock Stock;
/** \var typedef Stock_array Stock_array
 * \brief Typedef for Stock_array struct.
 */
typedef struct Stock_array Stock_array;
/** \struct Bond
 * \brief .
 *
 * .
 */
struct Bond
{
	int id;	/**< Datatype memory variable id of type int. */
	int nr_outstanding;	/**< Datatype memory variable nr_outstanding of type int. */
	int quantity;	/**< Datatype memory variable quantity of type int. */
	double face_value;	/**< Datatype memory variable face_value of type double. */
	double nominal_yield;	/**< Datatype memory variable nominal_yield of type double. */
	int maturity_day;	/**< Datatype memory variable maturity_day of type int. */
	int issue_day;	/**< Datatype memory variable issue_day of type int. */
	double yield2maturity;	/**< Datatype memory variable yield2maturity of type double. */
	double prices[100];	/**< Datatype memory variable prices of type double. */
	int index;	/**< Datatype memory variable index of type int. */
	double returns[100];	/**< Datatype memory variable returns of type double. */
};

/** \struct Bond_array
 * \brief Dynamic array to hold Bonds
 */
struct Bond_array
{
	int size;
	int total_size;
	
	struct Bond * array;
};

/** \var typedef Bond Bond
 * \brief Typedef for Bond struct.
 */
typedef struct Bond Bond;
/** \var typedef Bond_array Bond_array
 * \brief Typedef for Bond_array struct.
 */
typedef struct Bond_array Bond_array;
/** \struct Asset
 * \brief .
 *
 * .
 */
struct Asset
{
	int id;	/**< Datatype memory variable id of type int. */
	int quantity;	/**< Datatype memory variable quantity of type int. */
	double lastPrice;	/**< Datatype memory variable lastPrice of type double. */
};

/** \struct Asset_array
 * \brief Dynamic array to hold Assets
 */
struct Asset_array
{
	int size;
	int total_size;
	
	struct Asset * array;
};

/** \var typedef Asset Asset
 * \brief Typedef for Asset struct.
 */
typedef struct Asset Asset;
/** \var typedef Asset_array Asset_array
 * \brief Typedef for Asset_array struct.
 */
typedef struct Asset_array Asset_array;
/** \struct ClearingMechanism
 * \brief .
 *
 * .
 */
struct ClearingMechanism
{
	double lastPrice;	/**< Datatype memory variable lastPrice of type double. */
	int quantity;	/**< Datatype memory variable quantity of type int. */
	Order_array sellOrders;	/**< Datatype memory variable sellOrders of type Order_array. */
	Order_array buyOrders;	/**< Datatype memory variable buyOrders of type Order_array. */
	double_array prices;	/**< Datatype memory variable prices of type double_array. */
};

/** \struct ClearingMechanism_array
 * \brief Dynamic array to hold ClearingMechanisms
 */
struct ClearingMechanism_array
{
	int size;
	int total_size;
	
	struct ClearingMechanism * array;
};

/** \var typedef ClearingMechanism ClearingMechanism
 * \brief Typedef for ClearingMechanism struct.
 */
typedef struct ClearingMechanism ClearingMechanism;
/** \var typedef ClearingMechanism_array ClearingMechanism_array
 * \brief Typedef for ClearingMechanism_array struct.
 */
typedef struct ClearingMechanism_array ClearingMechanism_array;
/** \struct employee
 * \brief .
 *
 * .
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
 * \brief .
 *
 * .
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
 * \brief .
 *
 * .
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
 * \brief .
 *
 * .
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
/** \struct logit
 * \brief .
 *
 * .
 */
struct logit
{
	double logit_value;	/**< Datatype memory variable logit_value of type double. */
	int worker_id;	/**< Datatype memory variable worker_id of type int. */
	int general_skill;	/**< Datatype memory variable general_skill of type int. */
};

/** \struct logit_array
 * \brief Dynamic array to hold logits
 */
struct logit_array
{
	int size;
	int total_size;
	
	struct logit * array;
};

/** \var typedef logit logit
 * \brief Typedef for logit struct.
 */
typedef struct logit logit;
/** \var typedef logit_array logit_array
 * \brief Typedef for logit_array struct.
 */
typedef struct logit_array logit_array;
/** \struct household_data
 * \brief .
 *
 * .
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
 * \brief .
 *
 * .
 */
struct firm_data
{
	int region_id;	/**< Datatype memory variable region_id of type int. */
	int no_firms;	/**< Datatype memory variable no_firms of type int. */
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
	double total_earnings;	/**< Datatype memory variable total_earnings of type double. */
	double total_debt;	/**< Datatype memory variable total_debt of type double. */
	double total_assets;	/**< Datatype memory variable total_assets of type double. */
	double total_equity;	/**< Datatype memory variable total_equity of type double. */
	double average_debt_earnings_ratio;	/**< Datatype memory variable average_debt_earnings_ratio of type double. */
	double average_debt_equity_ratio;	/**< Datatype memory variable average_debt_equity_ratio of type double. */
	double labour_share_ratio;	/**< Datatype memory variable labour_share_ratio of type double. */
	double monthly_sold_quantity;	/**< Datatype memory variable monthly_sold_quantity of type double. */
	double monthly_output;	/**< Datatype memory variable monthly_output of type double. */
	double monthly_revenue;	/**< Datatype memory variable monthly_revenue of type double. */
	double monthly_planned_output;	/**< Datatype memory variable monthly_planned_output of type double. */
	double gdp;	/**< Datatype memory variable gdp of type double. */
	double cpi;	/**< Datatype memory variable cpi of type double. */
	double cpi_last_month;	/**< Datatype memory variable cpi_last_month of type double. */
	int no_firm_births;	/**< Datatype memory variable no_firm_births of type int. */
	int no_firm_deaths;	/**< Datatype memory variable no_firm_deaths of type int. */
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
/** \struct region_data_item
 * \brief .
 *
 * .
 */
struct region_data_item
{
	double cpi;	/**< Datatype memory variable cpi of type double. */
	double cpi_last_month;	/**< Datatype memory variable cpi_last_month of type double. */
	double gdp;	/**< Datatype memory variable gdp of type double. */
	double output;	/**< Datatype memory variable output of type double. */
	int employment;	/**< Datatype memory variable employment of type int. */
	double unemployment_rate;	/**< Datatype memory variable unemployment_rate of type double. */
	double unemployment_rate_skill_1;	/**< Datatype memory variable unemployment_rate_skill_1 of type double. */
	double unemployment_rate_skill_2;	/**< Datatype memory variable unemployment_rate_skill_2 of type double. */
	double unemployment_rate_skill_3;	/**< Datatype memory variable unemployment_rate_skill_3 of type double. */
	double unemployment_rate_skill_4;	/**< Datatype memory variable unemployment_rate_skill_4 of type double. */
	double unemployment_rate_skill_5;	/**< Datatype memory variable unemployment_rate_skill_5 of type double. */
	double average_wage;	/**< Datatype memory variable average_wage of type double. */
	int no_firms;	/**< Datatype memory variable no_firms of type int. */
	int no_firm_births;	/**< Datatype memory variable no_firm_births of type int. */
	int no_firm_deaths;	/**< Datatype memory variable no_firm_deaths of type int. */
};

/** \struct region_data_item_array
 * \brief Dynamic array to hold region_data_items
 */
struct region_data_item_array
{
	int size;
	int total_size;
	
	struct region_data_item * array;
};

/** \var typedef region_data_item region_data_item
 * \brief Typedef for region_data_item struct.
 */
typedef struct region_data_item region_data_item;
/** \var typedef region_data_item_array region_data_item_array
 * \brief Typedef for region_data_item_array struct.
 */
typedef struct region_data_item_array region_data_item_array;
/** \struct tax_rates_item
 * \brief .
 *
 * .
 */
struct tax_rates_item
{
	int gov_id;	/**< Datatype memory variable gov_id of type int. */
	double tax_rate_corporate;	/**< Datatype memory variable tax_rate_corporate of type double. */
	double tax_rate_hh_labour;	/**< Datatype memory variable tax_rate_hh_labour of type double. */
	double tax_rate_hh_capital;	/**< Datatype memory variable tax_rate_hh_capital of type double. */
	double tax_rate_vat;	/**< Datatype memory variable tax_rate_vat of type double. */
};

/** \struct tax_rates_item_array
 * \brief Dynamic array to hold tax_rates_items
 */
struct tax_rates_item_array
{
	int size;
	int total_size;
	
	struct tax_rates_item * array;
};

/** \var typedef tax_rates_item tax_rates_item
 * \brief Typedef for tax_rates_item struct.
 */
typedef struct tax_rates_item tax_rates_item;
/** \var typedef tax_rates_item_array tax_rates_item_array
 * \brief Typedef for tax_rates_item_array struct.
 */
typedef struct tax_rates_item_array tax_rates_item_array;
/** \struct history_item
 * \brief .
 *
 * .
 */
struct history_item
{
	double cpi;	/**< Datatype memory variable cpi of type double. */
	double gdp;	/**< Datatype memory variable gdp of type double. */
	double output;	/**< Datatype memory variable output of type double. */
	int employment;	/**< Datatype memory variable employment of type int. */
	double unemployment_rate;	/**< Datatype memory variable unemployment_rate of type double. */
	double unemployment_rate_skill_1;	/**< Datatype memory variable unemployment_rate_skill_1 of type double. */
	double unemployment_rate_skill_2;	/**< Datatype memory variable unemployment_rate_skill_2 of type double. */
	double unemployment_rate_skill_3;	/**< Datatype memory variable unemployment_rate_skill_3 of type double. */
	double unemployment_rate_skill_4;	/**< Datatype memory variable unemployment_rate_skill_4 of type double. */
	double unemployment_rate_skill_5;	/**< Datatype memory variable unemployment_rate_skill_5 of type double. */
	double average_wage;	/**< Datatype memory variable average_wage of type double. */
	int no_firms;	/**< Datatype memory variable no_firms of type int. */
	int no_firm_births;	/**< Datatype memory variable no_firm_births of type int. */
	int no_firm_deaths;	/**< Datatype memory variable no_firm_deaths of type int. */
	region_data_item_array region_data;	/**< Datatype memory variable region_data of type region_data_item_array. */
};

/** \struct history_item_array
 * \brief Dynamic array to hold history_items
 */
struct history_item_array
{
	int size;
	int total_size;
	
	struct history_item * array;
};

/** \var typedef history_item history_item
 * \brief Typedef for history_item struct.
 */
typedef struct history_item history_item;
/** \var typedef history_item_array history_item_array
 * \brief Typedef for history_item_array struct.
 */
typedef struct history_item_array history_item_array;

/** \struct xmachine_memory_Firm
 * \brief Holds memory of xmachine Firm.
 */
struct xmachine_memory_Firm
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	int last_day_of_month_to_act;	/**< X-machine memory variable last_day_of_month_to_act of type int. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	double mean_wage;	/**< X-machine memory variable mean_wage of type double. */
	double needed_capital_stock;	/**< X-machine memory variable needed_capital_stock of type double. */
	double actual_cap_price;	/**< X-machine memory variable actual_cap_price of type double. */
	double mean_specific_skills;	/**< X-machine memory variable mean_specific_skills of type double. */
	double planned_production_quantity;	/**< X-machine memory variable planned_production_quantity of type double. */
	double production_quantity;	/**< X-machine memory variable production_quantity of type double. */
	double planned_output;	/**< X-machine memory variable planned_output of type double. */
	double output;	/**< X-machine memory variable output of type double. */
	double unit_costs;	/**< X-machine memory variable unit_costs of type double. */
	double total_supply;	/**< X-machine memory variable total_supply of type double. */
	double production_costs;	/**< X-machine memory variable production_costs of type double. */
	double revenue_per_day;	/**< X-machine memory variable revenue_per_day of type double. */
	double technological_frontier;	/**< X-machine memory variable technological_frontier of type double. */
	double cum_revenue;	/**< X-machine memory variable cum_revenue of type double. */
	double out_of_stock_costs;	/**< X-machine memory variable out_of_stock_costs of type double. */
	sales_statistics_array malls_sales_statistics;	/**< X-machine memory variable malls_sales_statistics of type sales_statistics_array. */
	double quality;	/**< X-machine memory variable quality of type double. */
	double price;	/**< X-machine memory variable price of type double. */
	double price_last_month;	/**< X-machine memory variable price_last_month of type double. */
	double demand_capital_stock;	/**< X-machine memory variable demand_capital_stock of type double. */
	double planned_production_costs;	/**< X-machine memory variable planned_production_costs of type double. */
	double adaption_production_volume_due_to_insufficient_finances;	/**< X-machine memory variable adaption_production_volume_due_to_insufficient_finances of type double. */
	double fraction_reserved_for_delayed_payments;	/**< X-machine memory variable fraction_reserved_for_delayed_payments of type double. */
	sold_quantities_per_mall_array sold_quantities;	/**< X-machine memory variable sold_quantities of type sold_quantities_per_mall_array. */
	double total_sold_quantity;	/**< X-machine memory variable total_sold_quantity of type double. */
	double cum_total_sold_quantity;	/**< X-machine memory variable cum_total_sold_quantity of type double. */
	delivery_volume_per_mall_array delivery_volume;	/**< X-machine memory variable delivery_volume of type delivery_volume_per_mall_array. */
	delivery_volume_per_mall_array planned_delivery_volume;	/**< X-machine memory variable planned_delivery_volume of type delivery_volume_per_mall_array. */
	mall_info_array current_mall_stocks;	/**< X-machine memory variable current_mall_stocks of type mall_info_array. */
	double_array last_planned_production_quantities;	/**< X-machine memory variable last_planned_production_quantities of type double_array. */
	double total_external_financing_obtained;	/**< X-machine memory variable total_external_financing_obtained of type double. */
	double capital_costs;	/**< X-machine memory variable capital_costs of type double. */
	double labour_costs;	/**< X-machine memory variable labour_costs of type double. */
	financing_capital_array capital_financing;	/**< X-machine memory variable capital_financing of type financing_capital_array. */
	double financial_resources_for_production;	/**< X-machine memory variable financial_resources_for_production of type double. */
	double planned_value_capital_stock;	/**< X-machine memory variable planned_value_capital_stock of type double. */
	double total_units_local_inventory;	/**< X-machine memory variable total_units_local_inventory of type double. */
	int dmarketmatrix[10];	/**< X-machine memory variable dmarketmatrix of type int. */
	residual_var_datatype residual_var[10];	/**< X-machine memory variable residual_var of type residual_var_datatype. */
	double ebit;	/**< X-machine memory variable ebit of type double. */
	double earnings;	/**< X-machine memory variable earnings of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	double tax_rate_vat;	/**< X-machine memory variable tax_rate_vat of type double. */
	double tax_payment;	/**< X-machine memory variable tax_payment of type double. */
	double net_earnings;	/**< X-machine memory variable net_earnings of type double. */
	double previous_net_earnings;	/**< X-machine memory variable previous_net_earnings of type double. */
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
	double earnings_per_share;	/**< X-machine memory variable earnings_per_share of type double. */
	double total_payments;	/**< X-machine memory variable total_payments of type double. */
	double total_interest_payments;	/**< X-machine memory variable total_interest_payments of type double. */
	double previous_shares_outstanding;	/**< X-machine memory variable previous_shares_outstanding of type double. */
	double earnings_payout;	/**< X-machine memory variable earnings_payout of type double. */
	double current_shares_outstanding;	/**< X-machine memory variable current_shares_outstanding of type double. */
	Stock stock;	/**< X-machine memory variable stock of type Stock. */
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
	int employees_needed;	/**< X-machine memory variable employees_needed of type int. */
	int age;	/**< X-machine memory variable age of type int. */
	double transfer_payment;	/**< X-machine memory variable transfer_payment of type double. */
	double subsidy_payment;	/**< X-machine memory variable subsidy_payment of type double. */
	int active;	/**< X-machine memory variable active of type int. */
	int bankruptcy_idle_counter;	/**< X-machine memory variable bankruptcy_idle_counter of type int. */
	int bankruptcy_state;	/**< X-machine memory variable bankruptcy_state of type int. */
	int bankruptcy_insolvency_state;	/**< X-machine memory variable bankruptcy_insolvency_state of type int. */
	int bankruptcy_illiquidity_state;	/**< X-machine memory variable bankruptcy_illiquidity_state of type int. */
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

/** \struct xmachine_memory_Household
 * \brief Holds memory of xmachine Household.
 */
struct xmachine_memory_Household
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int_array neighboring_region_ids;	/**< X-machine memory variable neighboring_region_ids of type int_array. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	double consumption_budget;	/**< X-machine memory variable consumption_budget of type double. */
	double mean_income;	/**< X-machine memory variable mean_income of type double. */
	int week_of_month;	/**< X-machine memory variable week_of_month of type int. */
	double weekly_budget;	/**< X-machine memory variable weekly_budget of type double. */
	int rationed;	/**< X-machine memory variable rationed of type int. */
	int mall_completely_sold_out;	/**< X-machine memory variable mall_completely_sold_out of type int. */
	ordered_quantity order_quantity[2];	/**< X-machine memory variable order_quantity of type ordered_quantity. */
	received_quantities received_quantity[2];	/**< X-machine memory variable received_quantity of type received_quantities. */
	int day_of_week_to_act;	/**< X-machine memory variable day_of_week_to_act of type int. */
	int day_of_month_receive_income;	/**< X-machine memory variable day_of_month_receive_income of type int. */
	double current_productivity_employer;	/**< X-machine memory variable current_productivity_employer of type double. */
	double current_mean_specific_skills_employer;	/**< X-machine memory variable current_mean_specific_skills_employer of type double. */
	double total_taxes;	/**< X-machine memory variable total_taxes of type double. */
	double cum_total_dividends;	/**< X-machine memory variable cum_total_dividends of type double. */
	double tax_rate_hh_capital;	/**< X-machine memory variable tax_rate_hh_capital of type double. */
	double tax_rate_hh_labour;	/**< X-machine memory variable tax_rate_hh_labour of type double. */
	double price_index;	/**< X-machine memory variable price_index of type double. */
	double price_index_base_period;	/**< X-machine memory variable price_index_base_period of type double. */
	double commuting_costs_price_level_weight;	/**< X-machine memory variable commuting_costs_price_level_weight of type double. */
	double_array last_income;	/**< X-machine memory variable last_income of type double_array. */
	double expenditures;	/**< X-machine memory variable expenditures of type double. */
	double received_dividend;	/**< X-machine memory variable received_dividend of type double. */
	double wealth;	/**< X-machine memory variable wealth of type double. */
	Belief_array beliefs;	/**< X-machine memory variable beliefs of type Belief_array. */
	Order_array pendingOrders;	/**< X-machine memory variable pendingOrders of type Order_array. */
	Asset_array assetsowned;	/**< X-machine memory variable assetsowned of type Asset_array. */
	double_array assetWeights;	/**< X-machine memory variable assetWeights of type double_array. */
	double_array assetUtilities;	/**< X-machine memory variable assetUtilities of type double_array. */
	double cash_on_hand;	/**< X-machine memory variable cash_on_hand of type double. */
	int forwardWindow;	/**< X-machine memory variable forwardWindow of type int. */
	int backwardWindow;	/**< X-machine memory variable backwardWindow of type int. */
	int bins;	/**< X-machine memory variable bins of type int. */
	double randomWeight;	/**< X-machine memory variable randomWeight of type double. */
	double fundamentalWeight;	/**< X-machine memory variable fundamentalWeight of type double. */
	double chartistWeight;	/**< X-machine memory variable chartistWeight of type double. */
	int holdingPeriodToForwardW;	/**< X-machine memory variable holdingPeriodToForwardW of type int. */
	double lossaversion;	/**< X-machine memory variable lossaversion of type double. */
	double strategy;	/**< X-machine memory variable strategy of type double. */
	double wage;	/**< X-machine memory variable wage of type double. */
	double wage_reservation;	/**< X-machine memory variable wage_reservation of type double. */
	int general_skill;	/**< X-machine memory variable general_skill of type int. */
	int on_the_job_search;	/**< X-machine memory variable on_the_job_search of type int. */
	int number_applications;	/**< X-machine memory variable number_applications of type int. */
	double last_labour_income;	/**< X-machine memory variable last_labour_income of type double. */
	double specific_skill;	/**< X-machine memory variable specific_skill of type double. */
	int employee_firm_id;	/**< X-machine memory variable employee_firm_id of type int. */
	int employer_region_id;	/**< X-machine memory variable employer_region_id of type int. */
	int day_of_month_receive_benefit;	/**< X-machine memory variable day_of_month_receive_benefit of type int. */
	double unemployment_benefit_pct;	/**< X-machine memory variable unemployment_benefit_pct of type double. */
	double transfer_payment;	/**< X-machine memory variable transfer_payment of type double. */
	double subsidy_payment;	/**< X-machine memory variable subsidy_payment of type double. */
};

/** \struct xmachine_memory_Household_holder
 * \brief Holds struct of memory of xmachine Household.
 */
struct xmachine_memory_Household_holder
{
	struct xmachine_memory_Household * agent;	/**< Pointer to X-machine memory Household. */

	struct xmachine_memory_Household_holder * prev;	/**< Pointer to previous Household agent in the list.  */
	struct xmachine_memory_Household_holder * next;	/**< Pointer to next Household agent in the list.  */
};

/** \struct xmachine_memory_Household_holder
 * \brief Holds struct of memory of xmachine Household.
 */
struct xmachine_memory_Household_state
{
	struct xmachine_memory_Household_holder * agents;	/**< Pointer to X-machine memory Household. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Mall
 * \brief Holds memory of xmachine Mall.
 */
struct xmachine_memory_Mall
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int no_regions;	/**< X-machine memory variable no_regions of type int. */
	mall_stock_array current_stock;	/**< X-machine memory variable current_stock of type mall_stock_array. */
	sales_in_mall_array firm_revenues;	/**< X-machine memory variable firm_revenues of type sales_in_mall_array. */
	double total_supply;	/**< X-machine memory variable total_supply of type double. */
	double export_volume_matrix[900];	/**< X-machine memory variable export_volume_matrix of type double. */
	double export_value_matrix[900];	/**< X-machine memory variable export_value_matrix of type double. */
	double export_previous_value_matrix[900];	/**< X-machine memory variable export_previous_value_matrix of type double. */
};

/** \struct xmachine_memory_Mall_holder
 * \brief Holds struct of memory of xmachine Mall.
 */
struct xmachine_memory_Mall_holder
{
	struct xmachine_memory_Mall * agent;	/**< Pointer to X-machine memory Mall. */

	struct xmachine_memory_Mall_holder * prev;	/**< Pointer to previous Mall agent in the list.  */
	struct xmachine_memory_Mall_holder * next;	/**< Pointer to next Mall agent in the list.  */
};

/** \struct xmachine_memory_Mall_holder
 * \brief Holds struct of memory of xmachine Mall.
 */
struct xmachine_memory_Mall_state
{
	struct xmachine_memory_Mall_holder * agents;	/**< Pointer to X-machine memory Mall. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_IGFirm
 * \brief Holds memory of xmachine IGFirm.
 */
struct xmachine_memory_IGFirm
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int gov_id;	/**< X-machine memory variable gov_id of type int. */
	int bank_id;	/**< X-machine memory variable bank_id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	double productivity;	/**< X-machine memory variable productivity of type double. */
	double capital_good_price;	/**< X-machine memory variable capital_good_price of type double. */
	double revenue_per_day;	/**< X-machine memory variable revenue_per_day of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	double tax_rate_vat;	/**< X-machine memory variable tax_rate_vat of type double. */
	double tax_payment;	/**< X-machine memory variable tax_payment of type double. */
	double net_profit;	/**< X-machine memory variable net_profit of type double. */
	int outstanding_shares;	/**< X-machine memory variable outstanding_shares of type int. */
	double current_dividend_per_share;	/**< X-machine memory variable current_dividend_per_share of type double. */
	double cum_revenues;	/**< X-machine memory variable cum_revenues of type double. */
	int age;	/**< X-machine memory variable age of type int. */
	double transfer_payment;	/**< X-machine memory variable transfer_payment of type double. */
	double subsidy_payment;	/**< X-machine memory variable subsidy_payment of type double. */
};

/** \struct xmachine_memory_IGFirm_holder
 * \brief Holds struct of memory of xmachine IGFirm.
 */
struct xmachine_memory_IGFirm_holder
{
	struct xmachine_memory_IGFirm * agent;	/**< Pointer to X-machine memory IGFirm. */

	struct xmachine_memory_IGFirm_holder * prev;	/**< Pointer to previous IGFirm agent in the list.  */
	struct xmachine_memory_IGFirm_holder * next;	/**< Pointer to next IGFirm agent in the list.  */
};

/** \struct xmachine_memory_IGFirm_holder
 * \brief Holds struct of memory of xmachine IGFirm.
 */
struct xmachine_memory_IGFirm_state
{
	struct xmachine_memory_IGFirm_holder * agents;	/**< Pointer to X-machine memory IGFirm. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Eurostat
 * \brief Holds memory of xmachine Eurostat.
 */
struct xmachine_memory_Eurostat
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	int no_regions;	/**< X-machine memory variable no_regions of type int. */
	int switch_datastorage;	/**< X-machine memory variable switch_datastorage of type int. */
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
	tax_rates_item government_tax_rates[27];	/**< X-machine memory variable government_tax_rates of type tax_rates_item. */
	double total_earnings;	/**< X-machine memory variable total_earnings of type double. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double total_assets;	/**< X-machine memory variable total_assets of type double. */
	double total_equity;	/**< X-machine memory variable total_equity of type double. */
	double average_debt_earnings_ratio;	/**< X-machine memory variable average_debt_earnings_ratio of type double. */
	double average_debt_equity_ratio;	/**< X-machine memory variable average_debt_equity_ratio of type double. */
	double labour_share_ratio;	/**< X-machine memory variable labour_share_ratio of type double. */
	double cpi;	/**< X-machine memory variable cpi of type double. */
	double gdp;	/**< X-machine memory variable gdp of type double. */
	double monthly_sold_quantity;	/**< X-machine memory variable monthly_sold_quantity of type double. */
	double monthly_output;	/**< X-machine memory variable monthly_output of type double. */
	double monthly_revenue;	/**< X-machine memory variable monthly_revenue of type double. */
	double monthly_planned_output;	/**< X-machine memory variable monthly_planned_output of type double. */
	double price_index;	/**< X-machine memory variable price_index of type double. */
	history_item history_monthly[13];	/**< X-machine memory variable history_monthly of type history_item. */
	history_item history_quarterly[5];	/**< X-machine memory variable history_quarterly of type history_item. */
	history_item monthly_growth_rates;	/**< X-machine memory variable monthly_growth_rates of type history_item. */
	history_item quarterly_growth_rates;	/**< X-machine memory variable quarterly_growth_rates of type history_item. */
	history_item annual_growth_rates_monthly;	/**< X-machine memory variable annual_growth_rates_monthly of type history_item. */
	history_item annual_growth_rates_quarterly;	/**< X-machine memory variable annual_growth_rates_quarterly of type history_item. */
	int no_firm_births;	/**< X-machine memory variable no_firm_births of type int. */
	int no_firm_deaths;	/**< X-machine memory variable no_firm_deaths of type int. */
	int firm_age_distribution[60];	/**< X-machine memory variable firm_age_distribution of type int. */
	int firm_age_distribution_multiperiod[720];	/**< X-machine memory variable firm_age_distribution_multiperiod of type int. */
	int firm_age_distribution_1_period_lag[60];	/**< X-machine memory variable firm_age_distribution_1_period_lag of type int. */
	int firm_age_distribution_2_period_lag[60];	/**< X-machine memory variable firm_age_distribution_2_period_lag of type int. */
	double firm_birth_rate;	/**< X-machine memory variable firm_birth_rate of type double. */
	double firm_death_rate;	/**< X-machine memory variable firm_death_rate of type double. */
	double survival_rate[60];	/**< X-machine memory variable survival_rate of type double. */
	double survival_rate_multiperiod_1[60];	/**< X-machine memory variable survival_rate_multiperiod_1 of type double. */
	double survival_rate_multiperiod_2[60];	/**< X-machine memory variable survival_rate_multiperiod_2 of type double. */
	double survival_rate_multiperiod[720];	/**< X-machine memory variable survival_rate_multiperiod of type double. */
	int max_firm_creation;	/**< X-machine memory variable max_firm_creation of type int. */
	int recession_started;	/**< X-machine memory variable recession_started of type int. */
	int recession_duration;	/**< X-machine memory variable recession_duration of type int. */
	double export_volume_matrix[900];	/**< X-machine memory variable export_volume_matrix of type double. */
	double export_value_matrix[900];	/**< X-machine memory variable export_value_matrix of type double. */
	double export_previous_value_matrix[900];	/**< X-machine memory variable export_previous_value_matrix of type double. */
	double region_export_volume[30];	/**< X-machine memory variable region_export_volume of type double. */
	double region_import_volume[30];	/**< X-machine memory variable region_import_volume of type double. */
	double region_export_value[30];	/**< X-machine memory variable region_export_value of type double. */
	double region_import_value[30];	/**< X-machine memory variable region_import_value of type double. */
	double region_import_previous_value[30];	/**< X-machine memory variable region_import_previous_value of type double. */
};

/** \struct xmachine_memory_Eurostat_holder
 * \brief Holds struct of memory of xmachine Eurostat.
 */
struct xmachine_memory_Eurostat_holder
{
	struct xmachine_memory_Eurostat * agent;	/**< Pointer to X-machine memory Eurostat. */

	struct xmachine_memory_Eurostat_holder * prev;	/**< Pointer to previous Eurostat agent in the list.  */
	struct xmachine_memory_Eurostat_holder * next;	/**< Pointer to next Eurostat agent in the list.  */
};

/** \struct xmachine_memory_Eurostat_holder
 * \brief Holds struct of memory of xmachine Eurostat.
 */
struct xmachine_memory_Eurostat_state
{
	struct xmachine_memory_Eurostat_holder * agents;	/**< Pointer to X-machine memory Eurostat. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Clearinghouse
 * \brief Holds memory of xmachine Clearinghouse.
 */
struct xmachine_memory_Clearinghouse
{
	int id;	/**< X-machine memory variable id of type int. */
	int region_id;	/**< X-machine memory variable region_id of type int. */
	Asset_array assets;	/**< X-machine memory variable assets of type Asset_array. */
	ClearingMechanism clearingmechanism;	/**< X-machine memory variable clearingmechanism of type ClearingMechanism. */
};

/** \struct xmachine_memory_Clearinghouse_holder
 * \brief Holds struct of memory of xmachine Clearinghouse.
 */
struct xmachine_memory_Clearinghouse_holder
{
	struct xmachine_memory_Clearinghouse * agent;	/**< Pointer to X-machine memory Clearinghouse. */

	struct xmachine_memory_Clearinghouse_holder * prev;	/**< Pointer to previous Clearinghouse agent in the list.  */
	struct xmachine_memory_Clearinghouse_holder * next;	/**< Pointer to next Clearinghouse agent in the list.  */
};

/** \struct xmachine_memory_Clearinghouse_holder
 * \brief Holds struct of memory of xmachine Clearinghouse.
 */
struct xmachine_memory_Clearinghouse_state
{
	struct xmachine_memory_Clearinghouse_holder * agents;	/**< Pointer to X-machine memory Clearinghouse. */

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

/** \struct xmachine_memory_Government
 * \brief Holds memory of xmachine Government.
 */
struct xmachine_memory_Government
{
	int id;	/**< X-machine memory variable id of type int. */
	int list_of_regions[1];	/**< X-machine memory variable list_of_regions of type int. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	Bond bond;	/**< X-machine memory variable bond of type Bond. */
	Order pending_order;	/**< X-machine memory variable pending_order of type Order. */
	double deficit;	/**< X-machine memory variable deficit of type double. */
	double unemployment_benefit_pct;	/**< X-machine memory variable unemployment_benefit_pct of type double. */
	double money_financing_fraction;	/**< X-machine memory variable money_financing_fraction of type double. */
	double gdp_fraction_consumption;	/**< X-machine memory variable gdp_fraction_consumption of type double. */
	double gdp_fraction_investment;	/**< X-machine memory variable gdp_fraction_investment of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	double tax_rate_hh_labour;	/**< X-machine memory variable tax_rate_hh_labour of type double. */
	double tax_rate_hh_capital;	/**< X-machine memory variable tax_rate_hh_capital of type double. */
	double tax_rate_vat;	/**< X-machine memory variable tax_rate_vat of type double. */
	double monthly_tax_revenues;	/**< X-machine memory variable monthly_tax_revenues of type double. */
	double yearly_tax_revenues;	/**< X-machine memory variable yearly_tax_revenues of type double. */
	double monthly_unemployment_benefit_payment;	/**< X-machine memory variable monthly_unemployment_benefit_payment of type double. */
	double yearly_unemployment_benefit_payment;	/**< X-machine memory variable yearly_unemployment_benefit_payment of type double. */
	double hh_transfer_payment;	/**< X-machine memory variable hh_transfer_payment of type double. */
	double firm_transfer_payment;	/**< X-machine memory variable firm_transfer_payment of type double. */
	double monthly_transfer_payment;	/**< X-machine memory variable monthly_transfer_payment of type double. */
	double yearly_transfer_payment;	/**< X-machine memory variable yearly_transfer_payment of type double. */
	double hh_subsidy_payment;	/**< X-machine memory variable hh_subsidy_payment of type double. */
	double firm_subsidy_payment;	/**< X-machine memory variable firm_subsidy_payment of type double. */
	double monthly_subsidy_payment;	/**< X-machine memory variable monthly_subsidy_payment of type double. */
	double yearly_subsidy_payment;	/**< X-machine memory variable yearly_subsidy_payment of type double. */
	double monthly_bond_coupon_payment;	/**< X-machine memory variable monthly_bond_coupon_payment of type double. */
	double yearly_bond_coupon_payment;	/**< X-machine memory variable yearly_bond_coupon_payment of type double. */
	double gov_interest_rate;	/**< X-machine memory variable gov_interest_rate of type double. */
	double yearly_investment_expenditure;	/**< X-machine memory variable yearly_investment_expenditure of type double. */
	double yearly_consumption_expenditure;	/**< X-machine memory variable yearly_consumption_expenditure of type double. */
	double yearly_income;	/**< X-machine memory variable yearly_income of type double. */
	double yearly_expenditure;	/**< X-machine memory variable yearly_expenditure of type double. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double yearly_budget_balance;	/**< X-machine memory variable yearly_budget_balance of type double. */
	double total_money_financing;	/**< X-machine memory variable total_money_financing of type double. */
	double total_bond_financing;	/**< X-machine memory variable total_bond_financing of type double. */
	double country_wide_mean_wage;	/**< X-machine memory variable country_wide_mean_wage of type double. */
	int num_unemployed;	/**< X-machine memory variable num_unemployed of type int. */
	double gdp;	/**< X-machine memory variable gdp of type double. */
	double gdp_growth;	/**< X-machine memory variable gdp_growth of type double. */
	double gdp_forecast;	/**< X-machine memory variable gdp_forecast of type double. */
	double yearly_income_forecast;	/**< X-machine memory variable yearly_income_forecast of type double. */
	double yearly_expenditure_budget;	/**< X-machine memory variable yearly_expenditure_budget of type double. */
	double budget_balance_forecast;	/**< X-machine memory variable budget_balance_forecast of type double. */
	double monthly_consumption_expenditure;	/**< X-machine memory variable monthly_consumption_expenditure of type double. */
	double monthly_investment_expenditure;	/**< X-machine memory variable monthly_investment_expenditure of type double. */
	double monthly_budget_balance;	/**< X-machine memory variable monthly_budget_balance of type double. */
	double monthly_consumption_budget;	/**< X-machine memory variable monthly_consumption_budget of type double. */
	double monthly_investment_budget;	/**< X-machine memory variable monthly_investment_budget of type double. */
	double monthly_income;	/**< X-machine memory variable monthly_income of type double. */
	double monthly_expenditure;	/**< X-machine memory variable monthly_expenditure of type double. */
	double yearly_consumption_budget;	/**< X-machine memory variable yearly_consumption_budget of type double. */
	double yearly_investment_budget;	/**< X-machine memory variable yearly_investment_budget of type double. */
};

/** \struct xmachine_memory_Government_holder
 * \brief Holds struct of memory of xmachine Government.
 */
struct xmachine_memory_Government_holder
{
	struct xmachine_memory_Government * agent;	/**< Pointer to X-machine memory Government. */

	struct xmachine_memory_Government_holder * prev;	/**< Pointer to previous Government agent in the list.  */
	struct xmachine_memory_Government_holder * next;	/**< Pointer to next Government agent in the list.  */
};

/** \struct xmachine_memory_Government_holder
 * \brief Holds struct of memory of xmachine Government.
 */
struct xmachine_memory_Government_state
{
	struct xmachine_memory_Government_holder * agents;	/**< Pointer to X-machine memory Government. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Central_Bank
 * \brief Holds memory of xmachine Central_Bank.
 */
struct xmachine_memory_Central_Bank
{
	int id;	/**< X-machine memory variable id of type int. */
	account_item_array accounts;	/**< X-machine memory variable accounts of type account_item_array. */
};

/** \struct xmachine_memory_Central_Bank_holder
 * \brief Holds struct of memory of xmachine Central_Bank.
 */
struct xmachine_memory_Central_Bank_holder
{
	struct xmachine_memory_Central_Bank * agent;	/**< Pointer to X-machine memory Central_Bank. */

	struct xmachine_memory_Central_Bank_holder * prev;	/**< Pointer to previous Central_Bank agent in the list.  */
	struct xmachine_memory_Central_Bank_holder * next;	/**< Pointer to next Central_Bank agent in the list.  */
};

/** \struct xmachine_memory_Central_Bank_holder
 * \brief Holds struct of memory of xmachine Central_Bank.
 */
struct xmachine_memory_Central_Bank_state
{
	struct xmachine_memory_Central_Bank_holder * agents;	/**< Pointer to X-machine memory Central_Bank. */

	int count;	/**< Number of agents that were in this state.  */
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
	struct xmachine_memory_Eurostat * xmachine_Eurostat;	/**< Pointer to X-machine memory of type Eurostat.  */
	struct xmachine_memory_Clearinghouse * xmachine_Clearinghouse;	/**< Pointer to X-machine memory of type Clearinghouse.  */
	struct xmachine_memory_Bank * xmachine_Bank;	/**< Pointer to X-machine memory of type Bank.  */
	struct xmachine_memory_Government * xmachine_Government;	/**< Pointer to X-machine memory of type Government.  */
	struct xmachine_memory_Central_Bank * xmachine_Central_Bank;	/**< Pointer to X-machine memory of type Central_Bank.  */
	
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

/** \struct m_central_bank_account_update
 * \brief Holds message of type central_bank_account_update_message.
 */
struct m_central_bank_account_update
{
	int id;	/**< Message memory variable id of type int. */
	double payment_account;	/**< Message memory variable payment_account of type double. */
};

/** \struct m_wage_payment
 * \brief Holds message of type wage_payment_message.
 */
struct m_wage_payment
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	double payment;	/**< Message memory variable payment of type double. */
	double productivity;	/**< Message memory variable productivity of type double. */
	double average_specific_skills;	/**< Message memory variable average_specific_skills of type double. */
};

/** \struct m_quality_price_info_1
 * \brief Holds message of type quality_price_info_1_message.
 */
struct m_quality_price_info_1
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int mall_region_id;	/**< Message memory variable mall_region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
	int available;	/**< Message memory variable available of type int. */
};

/** \struct m_quality_price_info_2
 * \brief Holds message of type quality_price_info_2_message.
 */
struct m_quality_price_info_2
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int mall_region_id;	/**< Message memory variable mall_region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
	int available;	/**< Message memory variable available of type int. */
};

/** \struct m_update_mall_stock
 * \brief Holds message of type update_mall_stock_message.
 */
struct m_update_mall_stock
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quantity;	/**< Message memory variable quantity of type double. */
	double quality;	/**< Message memory variable quality of type double. */
	double price;	/**< Message memory variable price of type double. */
	double previous_price;	/**< Message memory variable previous_price of type double. */
};

/** \struct m_consumption_request_1
 * \brief Holds message of type consumption_request_1_message.
 */
struct m_consumption_request_1
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quantity;	/**< Message memory variable quantity of type double. */
};

/** \struct m_consumption_request_2
 * \brief Holds message of type consumption_request_2_message.
 */
struct m_consumption_request_2
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double quantity;	/**< Message memory variable quantity of type double. */
};

/** \struct m_accepted_consumption_1
 * \brief Holds message of type accepted_consumption_1_message.
 */
struct m_accepted_consumption_1
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int household_id;	/**< Message memory variable household_id of type int. */
	double offered_consumption_volume;	/**< Message memory variable offered_consumption_volume of type double. */
	int rationed;	/**< Message memory variable rationed of type int. */
};

/** \struct m_accepted_consumption_2
 * \brief Holds message of type accepted_consumption_2_message.
 */
struct m_accepted_consumption_2
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int household_id;	/**< Message memory variable household_id of type int. */
	double offered_consumption_volume;	/**< Message memory variable offered_consumption_volume of type double. */
	int rationed;	/**< Message memory variable rationed of type int. */
};

/** \struct m_sales
 * \brief Holds message of type sales_message.
 */
struct m_sales
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double revenue;	/**< Message memory variable revenue of type double. */
	int stock_empty;	/**< Message memory variable stock_empty of type int. */
	double current_stock;	/**< Message memory variable current_stock of type double. */
};

/** \struct m_specific_skill_update
 * \brief Holds message of type specific_skill_update_message.
 */
struct m_specific_skill_update
{
	int id;	/**< Message memory variable id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double specific_skills;	/**< Message memory variable specific_skills of type double. */
};

/** \struct m_daily_revenue_to_bank
 * \brief Holds message of type daily_revenue_to_bank_message.
 */
struct m_daily_revenue_to_bank
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

/** \struct m_current_mall_stock_info
 * \brief Holds message of type current_mall_stock_info_message.
 */
struct m_current_mall_stock_info
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

/** \struct m_bankruptcy_illiquidity
 * \brief Holds message of type bankruptcy_illiquidity_message.
 */
struct m_bankruptcy_illiquidity
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \struct m_bankruptcy_insolvency
 * \brief Holds message of type bankruptcy_insolvency_message.
 */
struct m_bankruptcy_insolvency
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
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

/** \struct m_infoAssetCH
 * \brief Holds message of type infoAssetCH_message.
 */
struct m_infoAssetCH
{
	int asset_id;	/**< Message memory variable asset_id of type int. */
	double price;	/**< Message memory variable price of type double. */
	int quantity;	/**< Message memory variable quantity of type int. */
};

/** \struct m_info_firm
 * \brief Holds message of type info_firm_message.
 */
struct m_info_firm
{
	int id;	/**< Message memory variable id of type int. */
	double earnings;	/**< Message memory variable earnings of type double. */
	double dividend;	/**< Message memory variable dividend of type double. */
	double earnings_payout;	/**< Message memory variable earnings_payout of type double. */
	double equity;	/**< Message memory variable equity of type double. */
	Stock stock;	/**< Message memory variable stock of type Stock. */
};

/** \struct m_accountInterest
 * \brief Holds message of type accountInterest_message.
 */
struct m_accountInterest
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double interest;	/**< Message memory variable interest of type double. */
};

/** \struct m_bankAccountUpdate
 * \brief Holds message of type bankAccountUpdate_message.
 */
struct m_bankAccountUpdate
{
	double account;	/**< Message memory variable account of type double. */
};

/** \struct m_info_bond
 * \brief Holds message of type info_bond_message.
 */
struct m_info_bond
{
	Bond bond;	/**< Message memory variable bond of type Bond. */
};

/** \struct m_productivity
 * \brief Holds message of type productivity_message.
 */
struct m_productivity
{
	int IGfirm_id;	/**< Message memory variable IGfirm_id of type int. */
	double cap_productivity;	/**< Message memory variable cap_productivity of type double. */
	double cap_good_price;	/**< Message memory variable cap_good_price of type double. */
};

/** \struct m_capital_good_request
 * \brief Holds message of type capital_good_request_message.
 */
struct m_capital_good_request
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double capital_good_demand;	/**< Message memory variable capital_good_demand of type double. */
};

/** \struct m_capital_good_profit_distribution
 * \brief Holds message of type capital_good_profit_distribution_message.
 */
struct m_capital_good_profit_distribution
{
	double capital_good_profit_shares;	/**< Message memory variable capital_good_profit_shares of type double. */
};

/** \struct m_capital_good_delivery
 * \brief Holds message of type capital_good_delivery_message.
 */
struct m_capital_good_delivery
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double capital_good_delivery_volume;	/**< Message memory variable capital_good_delivery_volume of type double. */
	double productivity;	/**< Message memory variable productivity of type double. */
	double capital_good_price;	/**< Message memory variable capital_good_price of type double. */
};

/** \struct m_dividend
 * \brief Holds message of type dividend_message.
 */
struct m_dividend
{
	double dividend;	/**< Message memory variable dividend of type double. */
};

/** \struct m_pay_capital_goods
 * \brief Holds message of type pay_capital_goods_message.
 */
struct m_pay_capital_goods
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	double capital_bill;	/**< Message memory variable capital_bill of type double. */
};

/** \struct m_vacancies
 * \brief Holds message of type vacancies_message.
 */
struct m_vacancies
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int firm_vacancies;	/**< Message memory variable firm_vacancies of type int. */
	int skill_group;	/**< Message memory variable skill_group of type int. */
	double firm_wage_offer;	/**< Message memory variable firm_wage_offer of type double. */
};

/** \struct m_vacancies2
 * \brief Holds message of type vacancies2_message.
 */
struct m_vacancies2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int firm_vacancies;	/**< Message memory variable firm_vacancies of type int. */
	int skill_group;	/**< Message memory variable skill_group of type int. */
	double firm_wage_offer;	/**< Message memory variable firm_wage_offer of type double. */
};

/** \struct m_firing
 * \brief Holds message of type firing_message.
 */
struct m_firing
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
};

/** \struct m_job_application
 * \brief Holds message of type job_application_message.
 */
struct m_job_application
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
};

/** \struct m_job_application2
 * \brief Holds message of type job_application2_message.
 */
struct m_job_application2
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
};

/** \struct m_job_offer
 * \brief Holds message of type job_offer_message.
 */
struct m_job_offer
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double wage_offer;	/**< Message memory variable wage_offer of type double. */
};

/** \struct m_job_offer2
 * \brief Holds message of type job_offer2_message.
 */
struct m_job_offer2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	double wage_offer;	/**< Message memory variable wage_offer of type double. */
};

/** \struct m_job_acceptance
 * \brief Holds message of type job_acceptance_message.
 */
struct m_job_acceptance
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
};

/** \struct m_job_acceptance2
 * \brief Holds message of type job_acceptance2_message.
 */
struct m_job_acceptance2
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
};

/** \struct m_application_rejection
 * \brief Holds message of type application_rejection_message.
 */
struct m_application_rejection
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
};

/** \struct m_application_rejection2
 * \brief Holds message of type application_rejection2_message.
 */
struct m_application_rejection2
{
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int worker_id;	/**< Message memory variable worker_id of type int. */
};

/** \struct m_quitting
 * \brief Holds message of type quitting_message.
 */
struct m_quitting
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \struct m_quitting2
 * \brief Holds message of type quitting2_message.
 */
struct m_quitting2
{
	int worker_id;	/**< Message memory variable worker_id of type int. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
};

/** \struct m_unemployment_notification
 * \brief Holds message of type unemployment_notification_message.
 */
struct m_unemployment_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double last_labour_income;	/**< Message memory variable last_labour_income of type double. */
};

/** \struct m_policy_announcement
 * \brief Holds message of type policy_announcement_message.
 */
struct m_policy_announcement
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double tax_rate_corporate;	/**< Message memory variable tax_rate_corporate of type double. */
	double tax_rate_hh_labour;	/**< Message memory variable tax_rate_hh_labour of type double. */
	double tax_rate_hh_capital;	/**< Message memory variable tax_rate_hh_capital of type double. */
	double tax_rate_vat;	/**< Message memory variable tax_rate_vat of type double. */
	double unemployment_benefit_pct;	/**< Message memory variable unemployment_benefit_pct of type double. */
	double hh_subsidy_payment;	/**< Message memory variable hh_subsidy_payment of type double. */
	double firm_subsidy_payment;	/**< Message memory variable firm_subsidy_payment of type double. */
	double hh_transfer_payment;	/**< Message memory variable hh_transfer_payment of type double. */
	double firm_transfer_payment;	/**< Message memory variable firm_transfer_payment of type double. */
};

/** \struct m_tax_payment
 * \brief Holds message of type tax_payment_message.
 */
struct m_tax_payment
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double tax_payment;	/**< Message memory variable tax_payment of type double. */
};

/** \struct m_hh_transfer_notification
 * \brief Holds message of type hh_transfer_notification_message.
 */
struct m_hh_transfer_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
};

/** \struct m_hh_subsidy_notification
 * \brief Holds message of type hh_subsidy_notification_message.
 */
struct m_hh_subsidy_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
};

/** \struct m_firm_transfer_notification
 * \brief Holds message of type firm_transfer_notification_message.
 */
struct m_firm_transfer_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
};

/** \struct m_firm_subsidy_notification
 * \brief Holds message of type firm_subsidy_notification_message.
 */
struct m_firm_subsidy_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
};

/** \struct m_firm_send_data
 * \brief Holds message of type firm_send_data_message.
 */
struct m_firm_send_data
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
	double cum_revenue;	/**< Message memory variable cum_revenue of type double. */
	double capital_costs;	/**< Message memory variable capital_costs of type double. */
	double net_earnings;	/**< Message memory variable net_earnings of type double. */
	double total_debt;	/**< Message memory variable total_debt of type double. */
	double total_assets;	/**< Message memory variable total_assets of type double. */
	double equity;	/**< Message memory variable equity of type double. */
	double price;	/**< Message memory variable price of type double. */
	double price_last_month;	/**< Message memory variable price_last_month of type double. */
	double total_supply;	/**< Message memory variable total_supply of type double. */
	double cum_total_sold_quantity;	/**< Message memory variable cum_total_sold_quantity of type double. */
	double output;	/**< Message memory variable output of type double. */
	double planned_output;	/**< Message memory variable planned_output of type double. */
	int age;	/**< Message memory variable age of type int. */
};

/** \struct m_household_send_data
 * \brief Holds message of type household_send_data_message.
 */
struct m_household_send_data
{
	int household_id;	/**< Message memory variable household_id of type int. */
	int region_id;	/**< Message memory variable region_id of type int. */
	int general_skill;	/**< Message memory variable general_skill of type int. */
	int employment_status;	/**< Message memory variable employment_status of type int. */
	double wage;	/**< Message memory variable wage of type double. */
	double specific_skill;	/**< Message memory variable specific_skill of type double. */
};

/** \struct m_mall_data
 * \brief Holds message of type mall_data_message.
 */
struct m_mall_data
{
	int mall_id;	/**< Message memory variable mall_id of type int. */
	int firm_region;	/**< Message memory variable firm_region of type int. */
	int household_region;	/**< Message memory variable household_region of type int. */
	double export_volume;	/**< Message memory variable export_volume of type double. */
	double export_value;	/**< Message memory variable export_value of type double. */
	double export_previous_value;	/**< Message memory variable export_previous_value of type double. */
};

/** \struct m_eurostat_send_specific_skills
 * \brief Holds message of type eurostat_send_specific_skills_message.
 */
struct m_eurostat_send_specific_skills
{
	int region_id;	/**< Message memory variable region_id of type int. */
	double specific_skill_1;	/**< Message memory variable specific_skill_1 of type double. */
	double specific_skill_2;	/**< Message memory variable specific_skill_2 of type double. */
	double specific_skill_3;	/**< Message memory variable specific_skill_3 of type double. */
	double specific_skill_4;	/**< Message memory variable specific_skill_4 of type double. */
	double specific_skill_5;	/**< Message memory variable specific_skill_5 of type double. */
};

/** \struct m_mean_wage_for_government
 * \brief Holds message of type mean_wage_for_government_message.
 */
struct m_mean_wage_for_government
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double mean_wage;	/**< Message memory variable mean_wage of type double. */
};

/** \struct m_data_for_government
 * \brief Holds message of type data_for_government_message.
 */
struct m_data_for_government
{
	int region_id;	/**< Message memory variable region_id of type int. */
	double gdp;	/**< Message memory variable gdp of type double. */
	double mean_wage;	/**< Message memory variable mean_wage of type double. */
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
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household xmachine_memory_Household;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household_holder xmachine_memory_Household_holder;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household_state xmachine_memory_Household_state;
/** \var typedef xmachine_memory_Mall xmachine_memory_Mall
 * \brief Typedef for xmachine_memory_Mall struct.
 */
typedef struct xmachine_memory_Mall xmachine_memory_Mall;
/** \var typedef xmachine_memory_Mall xmachine_memory_Mall
 * \brief Typedef for xmachine_memory_Mall struct.
 */
typedef struct xmachine_memory_Mall_holder xmachine_memory_Mall_holder;
/** \var typedef xmachine_memory_Mall xmachine_memory_Mall
 * \brief Typedef for xmachine_memory_Mall struct.
 */
typedef struct xmachine_memory_Mall_state xmachine_memory_Mall_state;
/** \var typedef xmachine_memory_IGFirm xmachine_memory_IGFirm
 * \brief Typedef for xmachine_memory_IGFirm struct.
 */
typedef struct xmachine_memory_IGFirm xmachine_memory_IGFirm;
/** \var typedef xmachine_memory_IGFirm xmachine_memory_IGFirm
 * \brief Typedef for xmachine_memory_IGFirm struct.
 */
typedef struct xmachine_memory_IGFirm_holder xmachine_memory_IGFirm_holder;
/** \var typedef xmachine_memory_IGFirm xmachine_memory_IGFirm
 * \brief Typedef for xmachine_memory_IGFirm struct.
 */
typedef struct xmachine_memory_IGFirm_state xmachine_memory_IGFirm_state;
/** \var typedef xmachine_memory_Eurostat xmachine_memory_Eurostat
 * \brief Typedef for xmachine_memory_Eurostat struct.
 */
typedef struct xmachine_memory_Eurostat xmachine_memory_Eurostat;
/** \var typedef xmachine_memory_Eurostat xmachine_memory_Eurostat
 * \brief Typedef for xmachine_memory_Eurostat struct.
 */
typedef struct xmachine_memory_Eurostat_holder xmachine_memory_Eurostat_holder;
/** \var typedef xmachine_memory_Eurostat xmachine_memory_Eurostat
 * \brief Typedef for xmachine_memory_Eurostat struct.
 */
typedef struct xmachine_memory_Eurostat_state xmachine_memory_Eurostat_state;
/** \var typedef xmachine_memory_Clearinghouse xmachine_memory_Clearinghouse
 * \brief Typedef for xmachine_memory_Clearinghouse struct.
 */
typedef struct xmachine_memory_Clearinghouse xmachine_memory_Clearinghouse;
/** \var typedef xmachine_memory_Clearinghouse xmachine_memory_Clearinghouse
 * \brief Typedef for xmachine_memory_Clearinghouse struct.
 */
typedef struct xmachine_memory_Clearinghouse_holder xmachine_memory_Clearinghouse_holder;
/** \var typedef xmachine_memory_Clearinghouse xmachine_memory_Clearinghouse
 * \brief Typedef for xmachine_memory_Clearinghouse struct.
 */
typedef struct xmachine_memory_Clearinghouse_state xmachine_memory_Clearinghouse_state;
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
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government xmachine_memory_Government;
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government_holder xmachine_memory_Government_holder;
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government_state xmachine_memory_Government_state;
/** \var typedef xmachine_memory_Central_Bank xmachine_memory_Central_Bank
 * \brief Typedef for xmachine_memory_Central_Bank struct.
 */
typedef struct xmachine_memory_Central_Bank xmachine_memory_Central_Bank;
/** \var typedef xmachine_memory_Central_Bank xmachine_memory_Central_Bank
 * \brief Typedef for xmachine_memory_Central_Bank struct.
 */
typedef struct xmachine_memory_Central_Bank_holder xmachine_memory_Central_Bank_holder;
/** \var typedef xmachine_memory_Central_Bank xmachine_memory_Central_Bank
 * \brief Typedef for xmachine_memory_Central_Bank struct.
 */
typedef struct xmachine_memory_Central_Bank_state xmachine_memory_Central_Bank_state;
/** \typedef m_bank_account_update m_bank_account_update
 * \brief Typedef for m_bank_account_update struct.
 */
typedef struct m_bank_account_update m_bank_account_update;

/** \typedef m_central_bank_account_update m_central_bank_account_update
 * \brief Typedef for m_central_bank_account_update struct.
 */
typedef struct m_central_bank_account_update m_central_bank_account_update;

/** \typedef m_wage_payment m_wage_payment
 * \brief Typedef for m_wage_payment struct.
 */
typedef struct m_wage_payment m_wage_payment;

/** \typedef m_quality_price_info_1 m_quality_price_info_1
 * \brief Typedef for m_quality_price_info_1 struct.
 */
typedef struct m_quality_price_info_1 m_quality_price_info_1;

/** \typedef m_quality_price_info_2 m_quality_price_info_2
 * \brief Typedef for m_quality_price_info_2 struct.
 */
typedef struct m_quality_price_info_2 m_quality_price_info_2;

/** \typedef m_update_mall_stock m_update_mall_stock
 * \brief Typedef for m_update_mall_stock struct.
 */
typedef struct m_update_mall_stock m_update_mall_stock;

/** \typedef m_consumption_request_1 m_consumption_request_1
 * \brief Typedef for m_consumption_request_1 struct.
 */
typedef struct m_consumption_request_1 m_consumption_request_1;

/** \typedef m_consumption_request_2 m_consumption_request_2
 * \brief Typedef for m_consumption_request_2 struct.
 */
typedef struct m_consumption_request_2 m_consumption_request_2;

/** \typedef m_accepted_consumption_1 m_accepted_consumption_1
 * \brief Typedef for m_accepted_consumption_1 struct.
 */
typedef struct m_accepted_consumption_1 m_accepted_consumption_1;

/** \typedef m_accepted_consumption_2 m_accepted_consumption_2
 * \brief Typedef for m_accepted_consumption_2 struct.
 */
typedef struct m_accepted_consumption_2 m_accepted_consumption_2;

/** \typedef m_sales m_sales
 * \brief Typedef for m_sales struct.
 */
typedef struct m_sales m_sales;

/** \typedef m_specific_skill_update m_specific_skill_update
 * \brief Typedef for m_specific_skill_update struct.
 */
typedef struct m_specific_skill_update m_specific_skill_update;

/** \typedef m_daily_revenue_to_bank m_daily_revenue_to_bank
 * \brief Typedef for m_daily_revenue_to_bank struct.
 */
typedef struct m_daily_revenue_to_bank m_daily_revenue_to_bank;

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

/** \typedef m_current_mall_stock_info m_current_mall_stock_info
 * \brief Typedef for m_current_mall_stock_info struct.
 */
typedef struct m_current_mall_stock_info m_current_mall_stock_info;

/** \typedef m_dividend_per_share m_dividend_per_share
 * \brief Typedef for m_dividend_per_share struct.
 */
typedef struct m_dividend_per_share m_dividend_per_share;

/** \typedef m_bankruptcy_illiquidity m_bankruptcy_illiquidity
 * \brief Typedef for m_bankruptcy_illiquidity struct.
 */
typedef struct m_bankruptcy_illiquidity m_bankruptcy_illiquidity;

/** \typedef m_bankruptcy_insolvency m_bankruptcy_insolvency
 * \brief Typedef for m_bankruptcy_insolvency struct.
 */
typedef struct m_bankruptcy_insolvency m_bankruptcy_insolvency;

/** \typedef m_order m_order
 * \brief Typedef for m_order struct.
 */
typedef struct m_order m_order;

/** \typedef m_order_status m_order_status
 * \brief Typedef for m_order_status struct.
 */
typedef struct m_order_status m_order_status;

/** \typedef m_infoAssetCH m_infoAssetCH
 * \brief Typedef for m_infoAssetCH struct.
 */
typedef struct m_infoAssetCH m_infoAssetCH;

/** \typedef m_info_firm m_info_firm
 * \brief Typedef for m_info_firm struct.
 */
typedef struct m_info_firm m_info_firm;

/** \typedef m_accountInterest m_accountInterest
 * \brief Typedef for m_accountInterest struct.
 */
typedef struct m_accountInterest m_accountInterest;

/** \typedef m_bankAccountUpdate m_bankAccountUpdate
 * \brief Typedef for m_bankAccountUpdate struct.
 */
typedef struct m_bankAccountUpdate m_bankAccountUpdate;

/** \typedef m_info_bond m_info_bond
 * \brief Typedef for m_info_bond struct.
 */
typedef struct m_info_bond m_info_bond;

/** \typedef m_productivity m_productivity
 * \brief Typedef for m_productivity struct.
 */
typedef struct m_productivity m_productivity;

/** \typedef m_capital_good_request m_capital_good_request
 * \brief Typedef for m_capital_good_request struct.
 */
typedef struct m_capital_good_request m_capital_good_request;

/** \typedef m_capital_good_profit_distribution m_capital_good_profit_distribution
 * \brief Typedef for m_capital_good_profit_distribution struct.
 */
typedef struct m_capital_good_profit_distribution m_capital_good_profit_distribution;

/** \typedef m_capital_good_delivery m_capital_good_delivery
 * \brief Typedef for m_capital_good_delivery struct.
 */
typedef struct m_capital_good_delivery m_capital_good_delivery;

/** \typedef m_dividend m_dividend
 * \brief Typedef for m_dividend struct.
 */
typedef struct m_dividend m_dividend;

/** \typedef m_pay_capital_goods m_pay_capital_goods
 * \brief Typedef for m_pay_capital_goods struct.
 */
typedef struct m_pay_capital_goods m_pay_capital_goods;

/** \typedef m_vacancies m_vacancies
 * \brief Typedef for m_vacancies struct.
 */
typedef struct m_vacancies m_vacancies;

/** \typedef m_vacancies2 m_vacancies2
 * \brief Typedef for m_vacancies2 struct.
 */
typedef struct m_vacancies2 m_vacancies2;

/** \typedef m_firing m_firing
 * \brief Typedef for m_firing struct.
 */
typedef struct m_firing m_firing;

/** \typedef m_job_application m_job_application
 * \brief Typedef for m_job_application struct.
 */
typedef struct m_job_application m_job_application;

/** \typedef m_job_application2 m_job_application2
 * \brief Typedef for m_job_application2 struct.
 */
typedef struct m_job_application2 m_job_application2;

/** \typedef m_job_offer m_job_offer
 * \brief Typedef for m_job_offer struct.
 */
typedef struct m_job_offer m_job_offer;

/** \typedef m_job_offer2 m_job_offer2
 * \brief Typedef for m_job_offer2 struct.
 */
typedef struct m_job_offer2 m_job_offer2;

/** \typedef m_job_acceptance m_job_acceptance
 * \brief Typedef for m_job_acceptance struct.
 */
typedef struct m_job_acceptance m_job_acceptance;

/** \typedef m_job_acceptance2 m_job_acceptance2
 * \brief Typedef for m_job_acceptance2 struct.
 */
typedef struct m_job_acceptance2 m_job_acceptance2;

/** \typedef m_application_rejection m_application_rejection
 * \brief Typedef for m_application_rejection struct.
 */
typedef struct m_application_rejection m_application_rejection;

/** \typedef m_application_rejection2 m_application_rejection2
 * \brief Typedef for m_application_rejection2 struct.
 */
typedef struct m_application_rejection2 m_application_rejection2;

/** \typedef m_quitting m_quitting
 * \brief Typedef for m_quitting struct.
 */
typedef struct m_quitting m_quitting;

/** \typedef m_quitting2 m_quitting2
 * \brief Typedef for m_quitting2 struct.
 */
typedef struct m_quitting2 m_quitting2;

/** \typedef m_unemployment_notification m_unemployment_notification
 * \brief Typedef for m_unemployment_notification struct.
 */
typedef struct m_unemployment_notification m_unemployment_notification;

/** \typedef m_policy_announcement m_policy_announcement
 * \brief Typedef for m_policy_announcement struct.
 */
typedef struct m_policy_announcement m_policy_announcement;

/** \typedef m_tax_payment m_tax_payment
 * \brief Typedef for m_tax_payment struct.
 */
typedef struct m_tax_payment m_tax_payment;

/** \typedef m_hh_transfer_notification m_hh_transfer_notification
 * \brief Typedef for m_hh_transfer_notification struct.
 */
typedef struct m_hh_transfer_notification m_hh_transfer_notification;

/** \typedef m_hh_subsidy_notification m_hh_subsidy_notification
 * \brief Typedef for m_hh_subsidy_notification struct.
 */
typedef struct m_hh_subsidy_notification m_hh_subsidy_notification;

/** \typedef m_firm_transfer_notification m_firm_transfer_notification
 * \brief Typedef for m_firm_transfer_notification struct.
 */
typedef struct m_firm_transfer_notification m_firm_transfer_notification;

/** \typedef m_firm_subsidy_notification m_firm_subsidy_notification
 * \brief Typedef for m_firm_subsidy_notification struct.
 */
typedef struct m_firm_subsidy_notification m_firm_subsidy_notification;

/** \typedef m_firm_send_data m_firm_send_data
 * \brief Typedef for m_firm_send_data struct.
 */
typedef struct m_firm_send_data m_firm_send_data;

/** \typedef m_household_send_data m_household_send_data
 * \brief Typedef for m_household_send_data struct.
 */
typedef struct m_household_send_data m_household_send_data;

/** \typedef m_mall_data m_mall_data
 * \brief Typedef for m_mall_data struct.
 */
typedef struct m_mall_data m_mall_data;

/** \typedef m_eurostat_send_specific_skills m_eurostat_send_specific_skills
 * \brief Typedef for m_eurostat_send_specific_skills struct.
 */
typedef struct m_eurostat_send_specific_skills m_eurostat_send_specific_skills;

/** \typedef m_mean_wage_for_government m_mean_wage_for_government
 * \brief Typedef for m_mean_wage_for_government struct.
 */
typedef struct m_mean_wage_for_government m_mean_wage_for_government;

/** \typedef m_data_for_government m_data_for_government
 * \brief Typedef for m_data_for_government struct.
 */
typedef struct m_data_for_government m_data_for_government;


int Firm_calc_production_quantity(void);
int Firm_Firm_calc_production_quantity_Firm_Start_Producer_Role_01_condition(xmachine_memory_Firm *a);
int Firm_set_quantities_zero(void);
int Firm_Firm_set_quantities_zero_Firm_Start_Producer_Role_00b_condition(xmachine_memory_Firm *a);
int Firm_calc_input_demands(void);
int Firm_calc_production_quantity_2(void);
int Firm_send_capital_demand(void);
int Firm_receive_capital_goods(void);
int Firm_Firm_receive_capital_goods_capital_good_delivery_filter(const void *msg, const void *params);
int Firm_execute_production(void);
int Firm_calc_pay_costs(void);
int Firm_send_goods_to_mall(void);
int Firm_calc_revenue(void);
int Firm_Firm_calc_revenue_sales_filter(const void *msg, const void *params);
int idle(void);
int Firm_idle_14_Firm_End_Financial_Management_Role_condition(xmachine_memory_Firm *a);
int Firm_compute_sales_statistics(void);
int Firm_Firm_compute_sales_statistics_14_Firm_Start_Financial_Management_Role_condition(xmachine_memory_Firm *a);
int Firm_update_specific_skills_of_workers(void);
int Firm_Firm_update_specific_skills_of_workers_Firm_End_Seller_Role_14_condition(xmachine_memory_Firm *a);
int Firm_Firm_update_specific_skills_of_workers_specific_skill_update_filter(const void *msg, const void *params);
int idle(void);
int Firm_idle_Firm_End_Seller_Role_14_condition(xmachine_memory_Firm *a);
int Firm_ask_loan(void);
int Firm_Firm_ask_loan_Firm_Start_Credit_Role_Firm_Credit_02_condition(xmachine_memory_Firm *a);
int Firm_get_loan(void);
int Firm_Firm_get_loan_loan_conditions_filter(const void *msg, const void *params);
int Firm_compute_financial_payments(void);
int Firm_compute_income_statement(void);
int Firm_compute_dividends(void);
int Firm_compute_total_financial_payments(void);
int Firm_compute_balance_sheet(void);
int Firm_set_bankruptcy_insolvency(void);
int Firm_Firm_set_bankruptcy_insolvency_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role_condition(xmachine_memory_Firm *a);
int idle(void);
int Firm_idle_Firm_Bankruptcy_check_Firm_End_Financial_Management_Role_condition(xmachine_memory_Firm *a);
int Firm_compute_total_liquidity_needs(void);
int Firm_compute_and_send_stock_orders(void);
int Firm_Firm_compute_and_send_stock_orders_Firm_End_Credit_Role_0003_condition(xmachine_memory_Firm *a);
int Firm_read_stock_transactions(void);
int Firm_Firm_read_stock_transactions_order_status_filter(const void *msg, const void *params);
int Firm_check_financial_and_bankruptcy_state(void);
int Firm_set_bankruptcy_illiquidity(void);
int Firm_Firm_set_bankruptcy_illiquidity_Firm_bankruptcy_checked_Firm_End_Financial_Management_Role_condition(xmachine_memory_Firm *a);
int Firm_in_financial_crisis(void);
int Firm_Firm_in_financial_crisis_Firm_checks_financial_crisis_Firm_End_External_Financing_condition(xmachine_memory_Firm *a);
int Firm_not_in_bankruptcy(void);
int Firm_Firm_not_in_bankruptcy_Firm_bankruptcy_checked_Firm_checks_financial_crisis_condition(xmachine_memory_Firm *a);
int idle(void);
int Firm_idle_Firm_checks_financial_crisis_Firm_End_External_Financing_condition(xmachine_memory_Firm *a);
int idle(void);
int Firm_idle_Firm_Start_Credit_Role_Firm_End_External_Financing_condition(xmachine_memory_Firm *a);
int idle(void);
int Firm_idle_Firm_End_Credit_Role_Firm_End_External_Financing_condition(xmachine_memory_Firm *a);
int Firm_execute_financial_payments(void);
int Firm_send_subsidy_notification(void);
int Firm_send_transfer_notification(void);
int Firm_bankruptcy_insolvency_procedure(void);
int Firm_Firm_bankruptcy_insolvency_procedure_Firm_not_active_Firm_bankrupty_state_1_condition(xmachine_memory_Firm *a);
int Firm_bankruptcy_illiquidity_procedure(void);
int Firm_Firm_bankruptcy_illiquidity_procedure_Firm_not_active_Firm_bankrupty_state_1_condition(xmachine_memory_Firm *a);
int Firm_bankruptcy_idle_counter(void);
int Firm_Firm_bankruptcy_idle_counter_start_Firm_Firm_not_active_condition(xmachine_memory_Firm *a);
int idle(void);
int Firm_idle_start_Firm_Firm_is_active_condition(xmachine_memory_Firm *a);
int Firm_compute_and_send_stock_orders(void);
int Firm_Firm_compute_and_send_stock_orders_Firm_bankrupty_state_1_Firm_bankrupty_state_2_condition(xmachine_memory_Firm *a);
int Firm_read_stock_transactions(void);
int Firm_reset_bankruptcy_flags(void);
int idle(void);
int Firm_idle_Firm_bankrupty_state_1_Firm_bankrupty_state_3_condition(xmachine_memory_Firm *a);
int Firm_send_info(void);
int Firm_receive_stock_info(void);
int Firm_Firm_receive_stock_info_infoAssetCH_filter(const void *msg, const void *params);
int Firm_calculate_specific_skills_and_wage_offer(void);
int Firm_send_vacancies(void);
int Firm_Firm_send_vacancies_011_03_condition(xmachine_memory_Firm *a);
int Firm_send_redundancies(void);
int Firm_Firm_send_redundancies_011_03c_condition(xmachine_memory_Firm *a);
int Firm_idle(void);
int Firm_Firm_idle_011_03c_condition(xmachine_memory_Firm *a);
int Firm_read_job_applications_send_job_offer_or_rejection(void);
int Firm_read_job_responses(void);
int Firm_read_job_quitting(void);
int Firm_read_job_quitting(void);
int Firm_read_job_quitting(void);
int Firm_start_labour_market(void);
int Firm_Firm_start_labour_market_03d_06_condition(xmachine_memory_Firm *a);
int Firm_finish_labour_market_first_round(void);
int Firm_Firm_finish_labour_market_first_round_03d_09a_condition(xmachine_memory_Firm *a);
int Firm_finish_labour_market_first_round(void);
int Firm_Firm_finish_labour_market_first_round_05b_09a_condition(xmachine_memory_Firm *a);
int Firm_update_wage_offer(void);
int Firm_Firm_update_wage_offer_05b_06_condition(xmachine_memory_Firm *a);
int Firm_send_vacancies_2(void);
int Firm_read_job_applications_send_job_offer_or_rejection_2(void);
int Firm_read_job_responses_2(void);
int Firm_read_job_quitting_2(void);
int Firm_read_job_quitting_2(void);
int Firm_update_wage_offer_2(void);
int Firm_Firm_update_wage_offer_2_09b_10_condition(xmachine_memory_Firm *a);
int Firm_idle(void);
int Firm_Firm_idle_09b_10_condition(xmachine_memory_Firm *a);
int Firm_compute_mean_wage_specific_skills(void);
int idle(void);
int Firm_idle_Firm_is_active_Firm_Start_Macro_Data_condition(xmachine_memory_Firm *a);
int Firm_read_policy_announcements(void);
int Firm_Firm_read_policy_announcements_Firm_is_active_Firm_Start_Macro_Data_condition(xmachine_memory_Firm *a);
int Firm_Firm_read_policy_announcements_policy_announcement_filter(const void *msg, const void *params);
int Firm_receive_data(void);
int Firm_Firm_receive_data_Firm_Start_Macro_Data_Firm_End_Macro_Data_condition(xmachine_memory_Firm *a);
int Firm_Firm_receive_data_eurostat_send_specific_skills_filter(const void *msg, const void *params);
int idle(void);
int Firm_idle_Firm_Start_Macro_Data_Firm_End_Macro_Data_condition(xmachine_memory_Firm *a);
int Firm_send_data_to_Eurostat(void);
int Firm_Firm_send_data_to_Eurostat_Firm_End_Financial_Management_Role_15_condition(xmachine_memory_Firm *a);
int idle(void);
int Firm_idle_Firm_End_Financial_Management_Role_15_condition(xmachine_memory_Firm *a);
int Firm_send_payments_to_bank(void);
int Household_idle(void);
int Household_Household_idle_09_15_condition(xmachine_memory_Household *a);
int Household_rank_and_buy_goods_1(void);
int Household_Household_rank_and_buy_goods_1_09_10_condition(xmachine_memory_Household *a);
int Household_Household_rank_and_buy_goods_1_quality_price_info_1_filter(const void *msg, const void *params);
int Household_receive_goods_read_rationing(void);
int Household_Household_receive_goods_read_rationing_accepted_consumption_1_filter(const void *msg, const void *params);
int Household_set_values_zero(void);
int Household_Household_set_values_zero_11_14_condition(xmachine_memory_Household *a);
int Household_rank_and_buy_goods_2(void);
int Household_Household_rank_and_buy_goods_2_11_12_condition(xmachine_memory_Household *a);
int Household_Household_rank_and_buy_goods_2_quality_price_info_2_filter(const void *msg, const void *params);
int Household_receive_goods_read_rationing_2(void);
int Household_Household_receive_goods_read_rationing_2_accepted_consumption_2_filter(const void *msg, const void *params);
int Household_handle_leftover_budget(void);
int Household_receive_info_interest_from_bank(void);
int Household_select_strategy(void);
int Household_stock_beliefs_formation(void);
int Household_Household_stock_beliefs_formation_CHOOSE_TO_TRADE_OR_NOT_BOND_BELIEF_FORMATION_condition(xmachine_memory_Household *a);
int Household_bond_beliefs_formation(void);
int Household_Household_bond_beliefs_formation_BOND_BELIEF_FORMATION_SEND_ORDERS_condition(xmachine_memory_Household *a);
int Household_does_not_trading(void);
int Household_Household_does_not_trading_CHOOSE_TO_TRADE_OR_NOT_Household_Start_Labour_Role_condition(xmachine_memory_Household *a);
int Household_send_orders(void);
int Household_update_its_portfolio(void);
int Household_Household_update_its_portfolio_order_status_filter(const void *msg, const void *params);
int Household_read_firing_messages(void);
int Household_Household_read_firing_messages_Household_Start_Labour_Role_01d_condition(xmachine_memory_Household *a);
int Household_idle(void);
int Household_Household_idle_01d_01a_condition(xmachine_memory_Household *a);
int Household_idle(void);
int Household_Household_idle_Household_Start_Labour_Role_01a_condition(xmachine_memory_Household *a);
int Household_UNEMPLOYED_read_job_vacancies_and_send_applications(void);
int Household_on_the_job_search_decision(void);
int Household_Household_on_the_job_search_decision_01d_01b_condition(xmachine_memory_Household *a);
int Household_OTJS_read_job_vacancies_and_send_applications(void);
int Household_Household_OTJS_read_job_vacancies_and_send_applications_01b_01_condition(xmachine_memory_Household *a);
int Household_idle(void);
int Household_Household_idle_01b_06_condition(xmachine_memory_Household *a);
int Household_read_job_offers_send_response(void);
int Household_finish_labour_market(void);
int Household_Household_finish_labour_market_02_06_condition(xmachine_memory_Household *a);
int Household_read_application_rejection_update_wage_reservation(void);
int Household_Household_read_application_rejection_update_wage_reservation_02_03_condition(xmachine_memory_Household *a);
int Household_OTJS_read_job_vacancies_and_send_applications_2(void);
int Household_Household_OTJS_read_job_vacancies_and_send_applications_2_02_04_condition(xmachine_memory_Household *a);
int Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2(void);
int Household_read_job_offers_send_response_2(void);
int Household_read_application_rejection_update_wage_reservation_2(void);
int Household_Household_read_application_rejection_update_wage_reservation_2_05_06_condition(xmachine_memory_Household *a);
int Household_idle(void);
int Household_Household_idle_05_06_condition(xmachine_memory_Household *a);
int Household_receive_dividends(void);
int Household_idle(void);
int Household_Household_idle_06b_09_condition(xmachine_memory_Household *a);
int Household_idle(void);
int Household_Household_idle_06b_06c_condition(xmachine_memory_Household *a);
int Household_send_subsidy_notification(void);
int Household_send_transfer_notification(void);
int Household_receive_wage(void);
int Household_Household_receive_wage_06e_07_condition(xmachine_memory_Household *a);
int Household_Household_receive_wage_wage_payment_filter(const void *msg, const void *params);
int Household_update_specific_skills(void);
int Household_send_unemployment_benefit_notification(void);
int Household_Household_send_unemployment_benefit_notification_06e_08_condition(xmachine_memory_Household *a);
int Household_send_tax_payment(void);
int Household_determine_consumption_budget(void);
int Household_idle(void);
int Household_Household_idle_start_Household_Household_Start_Policy_Data_condition(xmachine_memory_Household *a);
int Household_read_policy_announcements(void);
int Household_Household_read_policy_announcements_start_Household_Household_Start_Policy_Data_condition(xmachine_memory_Household *a);
int Household_Household_read_policy_announcements_policy_announcement_filter(const void *msg, const void *params);
int Household_receive_data(void);
int Household_Household_receive_data_Household_Start_Policy_Data_Household_Start_Financial_Market_Role_condition(xmachine_memory_Household *a);
int Household_idle(void);
int Household_Household_idle_Household_Start_Policy_Data_Household_Start_Financial_Market_Role_condition(xmachine_memory_Household *a);
int Household_send_data_to_Eurostat(void);
int Household_Household_send_data_to_Eurostat_15_end_Household_condition(xmachine_memory_Household *a);
int Household_idle(void);
int Household_Household_idle_15_end_Household_condition(xmachine_memory_Household *a);
int Mall_reset_export_data(void);
int Mall_Mall_reset_export_data_start_Mall_01_condition(xmachine_memory_Mall *a);
int idle(void);
int Mall_idle_start_Mall_01_condition(xmachine_memory_Mall *a);
int Mall_update_mall_stock(void);
int Mall_send_quality_price_info_1(void);
int Mall_update_mall_stocks_sales_rationing_1(void);
int Mall_Mall_update_mall_stocks_sales_rationing_1_consumption_request_1_filter(const void *msg, const void *params);
int Mall_update_mall_stocks_sales_rationing_2(void);
int Mall_Mall_update_mall_stocks_sales_rationing_2_consumption_request_2_filter(const void *msg, const void *params);
int Mall_pay_firm(void);
int Mall_send_export_data(void);
int Mall_Mall_send_export_data_06_end_Mall_condition(xmachine_memory_Mall *a);
int idle(void);
int Mall_idle_06_end_Mall_condition(xmachine_memory_Mall *a);
int Mall_read_insolvency_bankruptcy(void);
int IGFirm_update_productivity_price(void);
int IGFirm_IGFirm_update_productivity_price_Start_IGFirm_Productivity_01_condition(xmachine_memory_IGFirm *a);
int IGFirm_idle(void);
int IGFirm_IGFirm_idle_Start_IGFirm_Productivity_01_condition(xmachine_memory_IGFirm *a);
int IGFirm_send_quality_price_info(void);
int IGFirm_send_capital_good(void);
int IGFirm_receive_payment(void);
int IGFirm_pay_taxes(void);
int IGFirm_IGFirm_pay_taxes_04_04b_condition(xmachine_memory_IGFirm *a);
int IGFirm_dividend_payment(void);
int IGFirm_IGFirm_dividend_payment_04b_end_IGFirm_condition(xmachine_memory_IGFirm *a);
int IGFirm_idle(void);
int IGFirm_IGFirm_idle_04_end_IGFirm_condition(xmachine_memory_IGFirm *a);
int IGFirm_idle(void);
int IGFirm_IGFirm_idle_start_IGFirm_Start_IGFirm_Productivity_condition(xmachine_memory_IGFirm *a);
int IGFirm_read_policy_announcements(void);
int IGFirm_IGFirm_read_policy_announcements_start_IGFirm_Start_IGFirm_Productivity_condition(xmachine_memory_IGFirm *a);
int IGFirm_IGFirm_read_policy_announcements_policy_announcement_filter(const void *msg, const void *params);
int Eurostat_Initialization(void);
int Eurostat_Eurostat_Initialization_start_Eurostat_Eurostat_Start_Policy_Data_condition(xmachine_memory_Eurostat *a);
int Eurostat_idle(void);
int Eurostat_Eurostat_idle_start_Eurostat_Eurostat_Start_Policy_Data_condition(xmachine_memory_Eurostat *a);
int Eurostat_idle(void);
int Eurostat_Eurostat_idle_Eurostat_Start_Policy_Data_Eurostat_Start_Firm_Data_condition(xmachine_memory_Eurostat *a);
int Eurostat_read_policy_announcements(void);
int Eurostat_Eurostat_read_policy_announcements_Eurostat_Start_Policy_Data_Eurostat_Start_Firm_Data_condition(xmachine_memory_Eurostat *a);
int Eurostat_send_data(void);
int Eurostat_Eurostat_send_data_Eurostat_Start_Firm_Data_01_condition(xmachine_memory_Eurostat *a);
int Eurostat_idle(void);
int Eurostat_Eurostat_idle_Eurostat_Start_Firm_Data_01_condition(xmachine_memory_Eurostat *a);
int Eurostat_idle(void);
int Eurostat_Eurostat_idle_01_Eurostat_Start_Monthly_Loop_condition(xmachine_memory_Eurostat *a);
int Eurostat_calculate_data(void);
int Eurostat_Eurostat_calculate_data_01_Eurostat_Start_Monthly_Loop_condition(xmachine_memory_Eurostat *a);
int Eurostat_store_history_monthly(void);
int Eurostat_Eurostat_store_history_monthly_Eurostat_Start_Monthly_Loop_02_condition(xmachine_memory_Eurostat *a);
int Eurostat_compute_growth_rates_monthly(void);
int Eurostat_idle(void);
int Eurostat_Eurostat_idle_Eurostat_Start_Monthly_Loop_Eurostat_Start_Quarterly_Loop_condition(xmachine_memory_Eurostat *a);
int Eurostat_store_history_quarterly(void);
int Eurostat_Eurostat_store_history_quarterly_Eurostat_Start_Quarterly_Loop_04_condition(xmachine_memory_Eurostat *a);
int Eurostat_compute_growth_rates_quarterly(void);
int Eurostat_measure_recession(void);
int Eurostat_idle(void);
int Eurostat_Eurostat_idle_Eurostat_Start_Quarterly_Loop_Eurostat_Start_EndOfYear_Loop_condition(xmachine_memory_Eurostat *a);
int Eurostat_idle(void);
int Eurostat_Eurostat_idle_Eurostat_Start_EndOfYear_Loop_end_Eurostat_condition(xmachine_memory_Eurostat *a);
int Eurostat_send_data_to_government(void);
int Eurostat_Eurostat_send_data_to_government_Eurostat_Start_EndOfYear_Loop_end_Eurostat_condition(xmachine_memory_Eurostat *a);
int ClearingHouse_receive_info(void);
int ClearingHouse_receive_orders_and_run(void);
int ClearingHouse_send_asset_information(void);
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
int Bank_send_accountInterest(void);
int Government_send_info_bond(void);
int Government_generate_pending_orders(void);
int Government_orders_issuing(void);
int Government_update_its_portfolio(void);
int Government_Government_update_its_portfolio_order_status_filter(const void *msg, const void *params);
int Government_receive_info_bond(void);
int Government_Government_receive_info_bond_infoAssetCH_filter(const void *msg, const void *params);
int Government_idle(void);
int Government_Government_idle_start_Government_Gov_Start_Bond_Market_condition(xmachine_memory_Government *a);
int Government_send_policy_announcements(void);
int Government_Government_send_policy_announcements_start_Government_Gov_Start_Bond_Market_condition(xmachine_memory_Government *a);
int Government_read_tax_payments(void);
int Government_Government_read_tax_payments_tax_payment_filter(const void *msg, const void *params);
int Government_read_subsidy_notifications(void);
int Government_Government_read_subsidy_notifications_hh_subsidy_notification_filter(const void *msg, const void *params);
int Government_Government_read_subsidy_notifications_firm_subsidy_notification_filter(const void *msg, const void *params);
int Government_read_transfer_notifications(void);
int Government_Government_read_transfer_notifications_hh_transfer_notification_filter(const void *msg, const void *params);
int Government_Government_read_transfer_notifications_firm_transfer_notification_filter(const void *msg, const void *params);
int Government_read_unemployment_benefit_notifications(void);
int Government_Government_read_unemployment_benefit_notifications_unemployment_notification_filter(const void *msg, const void *params);
int Government_idle(void);
int Government_Government_idle_Gov_Start_Monthly_Loop_Gov_Start_Yearly_Loop_condition(xmachine_memory_Government *a);
int Government_monthly_budget_accounting(void);
int Government_Government_monthly_budget_accounting_Gov_Start_Monthly_Loop_05_condition(xmachine_memory_Government *a);
int Government_send_account_update(void);
int Government_read_data_from_Eurostat(void);
int Government_set_policy(void);
int Government_yearly_resetting(void);
int idle(void);
int Government_idle_Gov_Start_Yearly_Loop_end_Government_condition(xmachine_memory_Government *a);
int Government_yearly_budget_accounting(void);
int Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_07_condition(xmachine_memory_Government *a);
int Government_monthly_resetting(void);
int Central_Bank_read_account_update(void);

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
	struct m_central_bank_account_update * central_bank_account_update_messages;	/**< Pointer to central_bank_account_update message list. */
	struct m_wage_payment * wage_payment_messages;	/**< Pointer to wage_payment message list. */
	struct m_quality_price_info_1 * quality_price_info_1_messages;	/**< Pointer to quality_price_info_1 message list. */
	struct m_quality_price_info_2 * quality_price_info_2_messages;	/**< Pointer to quality_price_info_2 message list. */
	struct m_update_mall_stock * update_mall_stock_messages;	/**< Pointer to update_mall_stock message list. */
	struct m_consumption_request_1 * consumption_request_1_messages;	/**< Pointer to consumption_request_1 message list. */
	struct m_consumption_request_2 * consumption_request_2_messages;	/**< Pointer to consumption_request_2 message list. */
	struct m_accepted_consumption_1 * accepted_consumption_1_messages;	/**< Pointer to accepted_consumption_1 message list. */
	struct m_accepted_consumption_2 * accepted_consumption_2_messages;	/**< Pointer to accepted_consumption_2 message list. */
	struct m_sales * sales_messages;	/**< Pointer to sales message list. */
	struct m_specific_skill_update * specific_skill_update_messages;	/**< Pointer to specific_skill_update message list. */
	struct m_daily_revenue_to_bank * daily_revenue_to_bank_messages;	/**< Pointer to daily_revenue_to_bank message list. */
	struct m_loan_request * loan_request_messages;	/**< Pointer to loan_request message list. */
	struct m_loan_conditions * loan_conditions_messages;	/**< Pointer to loan_conditions message list. */
	struct m_loan_acceptance * loan_acceptance_messages;	/**< Pointer to loan_acceptance message list. */
	struct m_installment * installment_messages;	/**< Pointer to installment message list. */
	struct m_bankruptcy * bankruptcy_messages;	/**< Pointer to bankruptcy message list. */
	struct m_BCE_return * BCE_return_messages;	/**< Pointer to BCE_return message list. */
	struct m_current_mall_stock_info * current_mall_stock_info_messages;	/**< Pointer to current_mall_stock_info message list. */
	struct m_dividend_per_share * dividend_per_share_messages;	/**< Pointer to dividend_per_share message list. */
	struct m_bankruptcy_illiquidity * bankruptcy_illiquidity_messages;	/**< Pointer to bankruptcy_illiquidity message list. */
	struct m_bankruptcy_insolvency * bankruptcy_insolvency_messages;	/**< Pointer to bankruptcy_insolvency message list. */
	struct m_order * order_messages;	/**< Pointer to order message list. */
	struct m_order_status * order_status_messages;	/**< Pointer to order_status message list. */
	struct m_infoAssetCH * infoAssetCH_messages;	/**< Pointer to infoAssetCH message list. */
	struct m_info_firm * info_firm_messages;	/**< Pointer to info_firm message list. */
	struct m_accountInterest * accountInterest_messages;	/**< Pointer to accountInterest message list. */
	struct m_bankAccountUpdate * bankAccountUpdate_messages;	/**< Pointer to bankAccountUpdate message list. */
	struct m_info_bond * info_bond_messages;	/**< Pointer to info_bond message list. */
	struct m_productivity * productivity_messages;	/**< Pointer to productivity message list. */
	struct m_capital_good_request * capital_good_request_messages;	/**< Pointer to capital_good_request message list. */
	struct m_capital_good_profit_distribution * capital_good_profit_distribution_messages;	/**< Pointer to capital_good_profit_distribution message list. */
	struct m_capital_good_delivery * capital_good_delivery_messages;	/**< Pointer to capital_good_delivery message list. */
	struct m_dividend * dividend_messages;	/**< Pointer to dividend message list. */
	struct m_pay_capital_goods * pay_capital_goods_messages;	/**< Pointer to pay_capital_goods message list. */
	struct m_vacancies * vacancies_messages;	/**< Pointer to vacancies message list. */
	struct m_vacancies2 * vacancies2_messages;	/**< Pointer to vacancies2 message list. */
	struct m_firing * firing_messages;	/**< Pointer to firing message list. */
	struct m_job_application * job_application_messages;	/**< Pointer to job_application message list. */
	struct m_job_application2 * job_application2_messages;	/**< Pointer to job_application2 message list. */
	struct m_job_offer * job_offer_messages;	/**< Pointer to job_offer message list. */
	struct m_job_offer2 * job_offer2_messages;	/**< Pointer to job_offer2 message list. */
	struct m_job_acceptance * job_acceptance_messages;	/**< Pointer to job_acceptance message list. */
	struct m_job_acceptance2 * job_acceptance2_messages;	/**< Pointer to job_acceptance2 message list. */
	struct m_application_rejection * application_rejection_messages;	/**< Pointer to application_rejection message list. */
	struct m_application_rejection2 * application_rejection2_messages;	/**< Pointer to application_rejection2 message list. */
	struct m_quitting * quitting_messages;	/**< Pointer to quitting message list. */
	struct m_quitting2 * quitting2_messages;	/**< Pointer to quitting2 message list. */
	struct m_unemployment_notification * unemployment_notification_messages;	/**< Pointer to unemployment_notification message list. */
	struct m_policy_announcement * policy_announcement_messages;	/**< Pointer to policy_announcement message list. */
	struct m_tax_payment * tax_payment_messages;	/**< Pointer to tax_payment message list. */
	struct m_hh_transfer_notification * hh_transfer_notification_messages;	/**< Pointer to hh_transfer_notification message list. */
	struct m_hh_subsidy_notification * hh_subsidy_notification_messages;	/**< Pointer to hh_subsidy_notification message list. */
	struct m_firm_transfer_notification * firm_transfer_notification_messages;	/**< Pointer to firm_transfer_notification message list. */
	struct m_firm_subsidy_notification * firm_subsidy_notification_messages;	/**< Pointer to firm_subsidy_notification message list. */
	struct m_firm_send_data * firm_send_data_messages;	/**< Pointer to firm_send_data message list. */
	struct m_household_send_data * household_send_data_messages;	/**< Pointer to household_send_data message list. */
	struct m_mall_data * mall_data_messages;	/**< Pointer to mall_data message list. */
	struct m_eurostat_send_specific_skills * eurostat_send_specific_skills_messages;	/**< Pointer to eurostat_send_specific_skills message list. */
	struct m_mean_wage_for_government * mean_wage_for_government_messages;	/**< Pointer to mean_wage_for_government message list. */
	struct m_data_for_government * data_for_government_messages;	/**< Pointer to data_for_government message list. */
	
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

/** \var int print_log
* \brief A constant variable from the environment. */
int print_log;
/** \var int print_debug
* \brief A constant variable from the environment. */
int print_debug;
/** \var int day
* \brief A constant variable from the environment. */
int day;
/** \var int week
* \brief A constant variable from the environment. */
int week;
/** \var int month
* \brief A constant variable from the environment. */
int month;
/** \var int quarter
* \brief A constant variable from the environment. */
int quarter;
/** \var int year
* \brief A constant variable from the environment. */
int year;
/** \var int number_of_banks_to_apply
* \brief A constant variable from the environment. */
int number_of_banks_to_apply;
/** \var int gamma_const
* \brief A constant variable from the environment. */
int gamma_const;
/** \var double alpha
* \brief A constant variable from the environment. */
double alpha;
/** \var double beta
* \brief A constant variable from the environment. */
double beta;
/** \var double depreciation_rate
* \brief A constant variable from the environment. */
double depreciation_rate;
/** \var double discount_rate
* \brief A constant variable from the environment. */
double discount_rate;
/** \var double teta
* \brief A constant variable from the environment. */
double teta;
/** \var double mark_up
* \brief A constant variable from the environment. */
double mark_up;
/** \var double lambda
* \brief A constant variable from the environment. */
double lambda;
/** \var double wage_update
* \brief A constant variable from the environment. */
double wage_update;
/** \var int min_vacancy
* \brief A constant variable from the environment. */
int min_vacancy;
/** \var double wage_reservation_update
* \brief A constant variable from the environment. */
double wage_reservation_update;
/** \var double region_cost
* \brief A constant variable from the environment. */
double region_cost;
/** \var int inventory_costs_per_unit
* \brief A constant variable from the environment. */
int inventory_costs_per_unit;
/** \var double on_the_job_search_rate
* \brief A constant variable from the environment. */
double on_the_job_search_rate;
/** \var double initial_consumption_propensity
* \brief A constant variable from the environment. */
double initial_consumption_propensity;
/** \var double consumption_propensity
* \brief A constant variable from the environment. */
double consumption_propensity;
/** \var int firm_planning_horizon
* \brief A constant variable from the environment. */
int firm_planning_horizon;
/** \var int inv_inertia
* \brief A constant variable from the environment. */
int inv_inertia;
/** \var double adaption_delivery_volume
* \brief A constant variable from the environment. */
double adaption_delivery_volume;
/** \var int periods_to_repay_loans
* \brief A constant variable from the environment. */
int periods_to_repay_loans;
/** \var int delivery_prob_if_critical_stock_0
* \brief A constant variable from the environment. */
int delivery_prob_if_critical_stock_0;
/** \var int innovation_probability
* \brief A constant variable from the environment. */
int innovation_probability;
/** \var double productivity_progress
* \brief A constant variable from the environment. */
double productivity_progress;
/** \var int const_bankruptcy_idle_period
* \brief A constant variable from the environment. */
int const_bankruptcy_idle_period;
/** \var double debt_rescaling_factor
* \brief A constant variable from the environment. */
double debt_rescaling_factor;
/** \var double target_leverage_ratio
* \brief A constant variable from the environment. */
double target_leverage_ratio;
/** \var double target_liquidity_ratio
* \brief A constant variable from the environment. */
double target_liquidity_ratio;
/** \var double trading_activity
* \brief A constant variable from the environment. */
double trading_activity;
/** \var double BONDS_NEWISSUE_DISCOUNT
* \brief A constant variable from the environment. */
double BONDS_NEWISSUE_DISCOUNT;
/** \var double gov_policy_unemployment_benefit_pct
* \brief A constant variable from the environment. */
double gov_policy_unemployment_benefit_pct;
/** \var double gov_policy_money_financing_fraction
* \brief A constant variable from the environment. */
double gov_policy_money_financing_fraction;
/** \var double gov_policy_gdp_fraction_consumption
* \brief A constant variable from the environment. */
double gov_policy_gdp_fraction_consumption;
/** \var double gov_policy_gdp_fraction_investment
* \brief A constant variable from the environment. */
double gov_policy_gdp_fraction_investment;
/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var m_bank_account_update * temp_bank_account_update_message
* \brief Pointer to m_bank_account_update to initialise linked list. */
m_bank_account_update * temp_bank_account_update_message;
/** \var m_central_bank_account_update * temp_central_bank_account_update_message
* \brief Pointer to m_central_bank_account_update to initialise linked list. */
m_central_bank_account_update * temp_central_bank_account_update_message;
/** \var m_wage_payment * temp_wage_payment_message
* \brief Pointer to m_wage_payment to initialise linked list. */
m_wage_payment * temp_wage_payment_message;
/** \var m_quality_price_info_1 * temp_quality_price_info_1_message
* \brief Pointer to m_quality_price_info_1 to initialise linked list. */
m_quality_price_info_1 * temp_quality_price_info_1_message;
/** \var m_quality_price_info_2 * temp_quality_price_info_2_message
* \brief Pointer to m_quality_price_info_2 to initialise linked list. */
m_quality_price_info_2 * temp_quality_price_info_2_message;
/** \var m_update_mall_stock * temp_update_mall_stock_message
* \brief Pointer to m_update_mall_stock to initialise linked list. */
m_update_mall_stock * temp_update_mall_stock_message;
/** \var m_consumption_request_1 * temp_consumption_request_1_message
* \brief Pointer to m_consumption_request_1 to initialise linked list. */
m_consumption_request_1 * temp_consumption_request_1_message;
/** \var m_consumption_request_2 * temp_consumption_request_2_message
* \brief Pointer to m_consumption_request_2 to initialise linked list. */
m_consumption_request_2 * temp_consumption_request_2_message;
/** \var m_accepted_consumption_1 * temp_accepted_consumption_1_message
* \brief Pointer to m_accepted_consumption_1 to initialise linked list. */
m_accepted_consumption_1 * temp_accepted_consumption_1_message;
/** \var m_accepted_consumption_2 * temp_accepted_consumption_2_message
* \brief Pointer to m_accepted_consumption_2 to initialise linked list. */
m_accepted_consumption_2 * temp_accepted_consumption_2_message;
/** \var m_sales * temp_sales_message
* \brief Pointer to m_sales to initialise linked list. */
m_sales * temp_sales_message;
/** \var m_specific_skill_update * temp_specific_skill_update_message
* \brief Pointer to m_specific_skill_update to initialise linked list. */
m_specific_skill_update * temp_specific_skill_update_message;
/** \var m_daily_revenue_to_bank * temp_daily_revenue_to_bank_message
* \brief Pointer to m_daily_revenue_to_bank to initialise linked list. */
m_daily_revenue_to_bank * temp_daily_revenue_to_bank_message;
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
/** \var m_current_mall_stock_info * temp_current_mall_stock_info_message
* \brief Pointer to m_current_mall_stock_info to initialise linked list. */
m_current_mall_stock_info * temp_current_mall_stock_info_message;
/** \var m_dividend_per_share * temp_dividend_per_share_message
* \brief Pointer to m_dividend_per_share to initialise linked list. */
m_dividend_per_share * temp_dividend_per_share_message;
/** \var m_bankruptcy_illiquidity * temp_bankruptcy_illiquidity_message
* \brief Pointer to m_bankruptcy_illiquidity to initialise linked list. */
m_bankruptcy_illiquidity * temp_bankruptcy_illiquidity_message;
/** \var m_bankruptcy_insolvency * temp_bankruptcy_insolvency_message
* \brief Pointer to m_bankruptcy_insolvency to initialise linked list. */
m_bankruptcy_insolvency * temp_bankruptcy_insolvency_message;
/** \var m_order * temp_order_message
* \brief Pointer to m_order to initialise linked list. */
m_order * temp_order_message;
/** \var m_order_status * temp_order_status_message
* \brief Pointer to m_order_status to initialise linked list. */
m_order_status * temp_order_status_message;
/** \var m_infoAssetCH * temp_infoAssetCH_message
* \brief Pointer to m_infoAssetCH to initialise linked list. */
m_infoAssetCH * temp_infoAssetCH_message;
/** \var m_info_firm * temp_info_firm_message
* \brief Pointer to m_info_firm to initialise linked list. */
m_info_firm * temp_info_firm_message;
/** \var m_accountInterest * temp_accountInterest_message
* \brief Pointer to m_accountInterest to initialise linked list. */
m_accountInterest * temp_accountInterest_message;
/** \var m_bankAccountUpdate * temp_bankAccountUpdate_message
* \brief Pointer to m_bankAccountUpdate to initialise linked list. */
m_bankAccountUpdate * temp_bankAccountUpdate_message;
/** \var m_info_bond * temp_info_bond_message
* \brief Pointer to m_info_bond to initialise linked list. */
m_info_bond * temp_info_bond_message;
/** \var m_productivity * temp_productivity_message
* \brief Pointer to m_productivity to initialise linked list. */
m_productivity * temp_productivity_message;
/** \var m_capital_good_request * temp_capital_good_request_message
* \brief Pointer to m_capital_good_request to initialise linked list. */
m_capital_good_request * temp_capital_good_request_message;
/** \var m_capital_good_profit_distribution * temp_capital_good_profit_distribution_message
* \brief Pointer to m_capital_good_profit_distribution to initialise linked list. */
m_capital_good_profit_distribution * temp_capital_good_profit_distribution_message;
/** \var m_capital_good_delivery * temp_capital_good_delivery_message
* \brief Pointer to m_capital_good_delivery to initialise linked list. */
m_capital_good_delivery * temp_capital_good_delivery_message;
/** \var m_dividend * temp_dividend_message
* \brief Pointer to m_dividend to initialise linked list. */
m_dividend * temp_dividend_message;
/** \var m_pay_capital_goods * temp_pay_capital_goods_message
* \brief Pointer to m_pay_capital_goods to initialise linked list. */
m_pay_capital_goods * temp_pay_capital_goods_message;
/** \var m_vacancies * temp_vacancies_message
* \brief Pointer to m_vacancies to initialise linked list. */
m_vacancies * temp_vacancies_message;
/** \var m_vacancies2 * temp_vacancies2_message
* \brief Pointer to m_vacancies2 to initialise linked list. */
m_vacancies2 * temp_vacancies2_message;
/** \var m_firing * temp_firing_message
* \brief Pointer to m_firing to initialise linked list. */
m_firing * temp_firing_message;
/** \var m_job_application * temp_job_application_message
* \brief Pointer to m_job_application to initialise linked list. */
m_job_application * temp_job_application_message;
/** \var m_job_application2 * temp_job_application2_message
* \brief Pointer to m_job_application2 to initialise linked list. */
m_job_application2 * temp_job_application2_message;
/** \var m_job_offer * temp_job_offer_message
* \brief Pointer to m_job_offer to initialise linked list. */
m_job_offer * temp_job_offer_message;
/** \var m_job_offer2 * temp_job_offer2_message
* \brief Pointer to m_job_offer2 to initialise linked list. */
m_job_offer2 * temp_job_offer2_message;
/** \var m_job_acceptance * temp_job_acceptance_message
* \brief Pointer to m_job_acceptance to initialise linked list. */
m_job_acceptance * temp_job_acceptance_message;
/** \var m_job_acceptance2 * temp_job_acceptance2_message
* \brief Pointer to m_job_acceptance2 to initialise linked list. */
m_job_acceptance2 * temp_job_acceptance2_message;
/** \var m_application_rejection * temp_application_rejection_message
* \brief Pointer to m_application_rejection to initialise linked list. */
m_application_rejection * temp_application_rejection_message;
/** \var m_application_rejection2 * temp_application_rejection2_message
* \brief Pointer to m_application_rejection2 to initialise linked list. */
m_application_rejection2 * temp_application_rejection2_message;
/** \var m_quitting * temp_quitting_message
* \brief Pointer to m_quitting to initialise linked list. */
m_quitting * temp_quitting_message;
/** \var m_quitting2 * temp_quitting2_message
* \brief Pointer to m_quitting2 to initialise linked list. */
m_quitting2 * temp_quitting2_message;
/** \var m_unemployment_notification * temp_unemployment_notification_message
* \brief Pointer to m_unemployment_notification to initialise linked list. */
m_unemployment_notification * temp_unemployment_notification_message;
/** \var m_policy_announcement * temp_policy_announcement_message
* \brief Pointer to m_policy_announcement to initialise linked list. */
m_policy_announcement * temp_policy_announcement_message;
/** \var m_tax_payment * temp_tax_payment_message
* \brief Pointer to m_tax_payment to initialise linked list. */
m_tax_payment * temp_tax_payment_message;
/** \var m_hh_transfer_notification * temp_hh_transfer_notification_message
* \brief Pointer to m_hh_transfer_notification to initialise linked list. */
m_hh_transfer_notification * temp_hh_transfer_notification_message;
/** \var m_hh_subsidy_notification * temp_hh_subsidy_notification_message
* \brief Pointer to m_hh_subsidy_notification to initialise linked list. */
m_hh_subsidy_notification * temp_hh_subsidy_notification_message;
/** \var m_firm_transfer_notification * temp_firm_transfer_notification_message
* \brief Pointer to m_firm_transfer_notification to initialise linked list. */
m_firm_transfer_notification * temp_firm_transfer_notification_message;
/** \var m_firm_subsidy_notification * temp_firm_subsidy_notification_message
* \brief Pointer to m_firm_subsidy_notification to initialise linked list. */
m_firm_subsidy_notification * temp_firm_subsidy_notification_message;
/** \var m_firm_send_data * temp_firm_send_data_message
* \brief Pointer to m_firm_send_data to initialise linked list. */
m_firm_send_data * temp_firm_send_data_message;
/** \var m_household_send_data * temp_household_send_data_message
* \brief Pointer to m_household_send_data to initialise linked list. */
m_household_send_data * temp_household_send_data_message;
/** \var m_mall_data * temp_mall_data_message
* \brief Pointer to m_mall_data to initialise linked list. */
m_mall_data * temp_mall_data_message;
/** \var m_eurostat_send_specific_skills * temp_eurostat_send_specific_skills_message
* \brief Pointer to m_eurostat_send_specific_skills to initialise linked list. */
m_eurostat_send_specific_skills * temp_eurostat_send_specific_skills_message;
/** \var m_mean_wage_for_government * temp_mean_wage_for_government_message
* \brief Pointer to m_mean_wage_for_government to initialise linked list. */
m_mean_wage_for_government * temp_mean_wage_for_government_message;
/** \var m_data_for_government * temp_data_for_government_message
* \brief Pointer to m_data_for_government to initialise linked list. */
m_data_for_government * temp_data_for_government_message;
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
/* Pointer to list of Firm agents in state Firm_Start_Macro_Data state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Macro_Data;
xmachine_memory_Firm_state * Firm_Firm_Start_Macro_Data_state;
/* Pointer to list of Firm agents in state 10 state */
//xmachine_memory_Firm * temp_xmachine_Firm_10;
xmachine_memory_Firm_state * Firm_10_state;
/* Pointer to list of Firm agents in state 09b state */
//xmachine_memory_Firm * temp_xmachine_Firm_09b;
xmachine_memory_Firm_state * Firm_09b_state;
/* Pointer to list of Firm agents in state 08 state */
//xmachine_memory_Firm * temp_xmachine_Firm_08;
xmachine_memory_Firm_state * Firm_08_state;
/* Pointer to list of Firm agents in state 07 state */
//xmachine_memory_Firm * temp_xmachine_Firm_07;
xmachine_memory_Firm_state * Firm_07_state;
/* Pointer to list of Firm agents in state 09a state */
//xmachine_memory_Firm * temp_xmachine_Firm_09a;
xmachine_memory_Firm_state * Firm_09a_state;
/* Pointer to list of Firm agents in state 06 state */
//xmachine_memory_Firm * temp_xmachine_Firm_06;
xmachine_memory_Firm_state * Firm_06_state;
/* Pointer to list of Firm agents in state 03d state */
//xmachine_memory_Firm * temp_xmachine_Firm_03d;
xmachine_memory_Firm_state * Firm_03d_state;
/* Pointer to list of Firm agents in state 09c state */
//xmachine_memory_Firm * temp_xmachine_Firm_09c;
xmachine_memory_Firm_state * Firm_09c_state;
/* Pointer to list of Firm agents in state 05b state */
//xmachine_memory_Firm * temp_xmachine_Firm_05b;
xmachine_memory_Firm_state * Firm_05b_state;
/* Pointer to list of Firm agents in state 05a state */
//xmachine_memory_Firm * temp_xmachine_Firm_05a;
xmachine_memory_Firm_state * Firm_05a_state;
/* Pointer to list of Firm agents in state 04 state */
//xmachine_memory_Firm * temp_xmachine_Firm_04;
xmachine_memory_Firm_state * Firm_04_state;
/* Pointer to list of Firm agents in state 03c state */
//xmachine_memory_Firm * temp_xmachine_Firm_03c;
xmachine_memory_Firm_state * Firm_03c_state;
/* Pointer to list of Firm agents in state 03 state */
//xmachine_memory_Firm * temp_xmachine_Firm_03;
xmachine_memory_Firm_state * Firm_03_state;
/* Pointer to list of Firm agents in state 011 state */
//xmachine_memory_Firm * temp_xmachine_Firm_011;
xmachine_memory_Firm_state * Firm_011_state;
/* Pointer to list of Firm agents in state 16 state */
//xmachine_memory_Firm * temp_xmachine_Firm_16;
xmachine_memory_Firm_state * Firm_16_state;
/* Pointer to list of Firm agents in state 15 state */
//xmachine_memory_Firm * temp_xmachine_Firm_15;
xmachine_memory_Firm_state * Firm_15_state;
/* Pointer to list of Firm agents in state Firm_End_Macro_Data state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Macro_Data;
xmachine_memory_Firm_state * Firm_Firm_End_Macro_Data_state;
/* Pointer to list of Firm agents in state end_Firm state */
//xmachine_memory_Firm * temp_xmachine_Firm_end_Firm;
xmachine_memory_Firm_state * Firm_end_Firm_state;
/* Pointer to list of Firm agents in state Firm_bankrupty_state_3 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankrupty_state_3;
xmachine_memory_Firm_state * Firm_Firm_bankrupty_state_3_state;
/* Pointer to list of Firm agents in state Firm_bankrupty_state_2 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankrupty_state_2;
xmachine_memory_Firm_state * Firm_Firm_bankrupty_state_2_state;
/* Pointer to list of Firm agents in state Firm_is_active state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_is_active;
xmachine_memory_Firm_state * Firm_Firm_is_active_state;
/* Pointer to list of Firm agents in state start_Firm state */
//xmachine_memory_Firm * temp_xmachine_Firm_start_Firm;
xmachine_memory_Firm_state * Firm_start_Firm_state;
/* Pointer to list of Firm agents in state Firm_bankrupty_state_1 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankrupty_state_1;
xmachine_memory_Firm_state * Firm_Firm_bankrupty_state_1_state;
/* Pointer to list of Firm agents in state Firm_not_active state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_not_active;
xmachine_memory_Firm_state * Firm_Firm_not_active_state;
/* Pointer to list of Firm agents in state 005 state */
//xmachine_memory_Firm * temp_xmachine_Firm_005;
xmachine_memory_Firm_state * Firm_005_state;
/* Pointer to list of Firm agents in state Firm_Start_Public_Sector_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Public_Sector_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Public_Sector_Role_state;
/* Pointer to list of Firm agents in state Firm_End_External_Financing state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_External_Financing;
xmachine_memory_Firm_state * Firm_Firm_End_External_Financing_state;
/* Pointer to list of Firm agents in state Firm_checks_financial_crisis state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_checks_financial_crisis;
xmachine_memory_Firm_state * Firm_Firm_checks_financial_crisis_state;
/* Pointer to list of Firm agents in state Firm_bankruptcy_checked state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_bankruptcy_checked;
xmachine_memory_Firm_state * Firm_Firm_bankruptcy_checked_state;
/* Pointer to list of Firm agents in state End_Firm_Financial_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_End_Firm_Financial_Role;
xmachine_memory_Firm_state * Firm_End_Firm_Financial_Role_state;
/* Pointer to list of Firm agents in state 0003 state */
//xmachine_memory_Firm * temp_xmachine_Firm_0003;
xmachine_memory_Firm_state * Firm_0003_state;
/* Pointer to list of Firm agents in state Firm_Bankruptcy_check state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Bankruptcy_check;
xmachine_memory_Firm_state * Firm_Firm_Bankruptcy_check_state;
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
/* Pointer to list of Firm agents in state Firm_End_Credit_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Credit_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Credit_Role_state;
/* Pointer to list of Firm agents in state Firm_Credit_02 state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Credit_02;
xmachine_memory_Firm_state * Firm_Firm_Credit_02_state;
/* Pointer to list of Firm agents in state Firm_Start_Credit_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Credit_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Credit_Role_state;
/* Pointer to list of Firm agents in state Firm_Start_Financial_Management_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Financial_Management_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Financial_Management_Role_state;
/* Pointer to list of Firm agents in state Firm_End_Financial_Management_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Financial_Management_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Financial_Management_Role_state;
/* Pointer to list of Firm agents in state 14 state */
//xmachine_memory_Firm * temp_xmachine_Firm_14;
xmachine_memory_Firm_state * Firm_14_state;
/* Pointer to list of Firm agents in state Firm_End_Seller_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Seller_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Seller_Role_state;
/* Pointer to list of Firm agents in state Firm_Start_Seller_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Seller_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Seller_Role_state;
/* Pointer to list of Firm agents in state 12 state */
//xmachine_memory_Firm * temp_xmachine_Firm_12;
xmachine_memory_Firm_state * Firm_12_state;
/* Pointer to list of Firm agents in state 11 state */
//xmachine_memory_Firm * temp_xmachine_Firm_11;
xmachine_memory_Firm_state * Firm_11_state;
/* Pointer to list of Firm agents in state 11b state */
//xmachine_memory_Firm * temp_xmachine_Firm_11b;
xmachine_memory_Firm_state * Firm_11b_state;
/* Pointer to list of Firm agents in state 11a state */
//xmachine_memory_Firm * temp_xmachine_Firm_11a;
xmachine_memory_Firm_state * Firm_11a_state;
/* Pointer to list of Firm agents in state Firm_End_Labour_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Labour_Role;
xmachine_memory_Firm_state * Firm_Firm_End_Labour_Role_state;
/* Pointer to list of Firm agents in state Firm_Start_Labour_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Labour_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Labour_Role_state;
/* Pointer to list of Firm agents in state Firm_End_Financial_Management state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_End_Financial_Management;
xmachine_memory_Firm_state * Firm_Firm_End_Financial_Management_state;
/* Pointer to list of Firm agents in state 02 state */
//xmachine_memory_Firm * temp_xmachine_Firm_02;
xmachine_memory_Firm_state * Firm_02_state;
/* Pointer to list of Firm agents in state 00b state */
//xmachine_memory_Firm * temp_xmachine_Firm_00b;
xmachine_memory_Firm_state * Firm_00b_state;
/* Pointer to list of Firm agents in state 01 state */
//xmachine_memory_Firm * temp_xmachine_Firm_01;
xmachine_memory_Firm_state * Firm_01_state;
/* Pointer to list of Firm agents in state Firm_Start_Producer_Role state */
//xmachine_memory_Firm * temp_xmachine_Firm_Firm_Start_Producer_Role;
xmachine_memory_Firm_state * Firm_Firm_Start_Producer_Role_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Household * current_xmachine_Household;
xmachine_memory_Household_holder * temp_xmachine_Household_holder;
xmachine_memory_Household_holder * current_xmachine_Household_holder;
xmachine_memory_Household_state * current_xmachine_Household_next_state; /* New agents added to this state */
/* Pointer to list of Household agents in state end_Household state */
//xmachine_memory_Household * temp_xmachine_Household_end_Household;
xmachine_memory_Household_state * Household_end_Household_state;
/* Pointer to list of Household agents in state Household_Start_Policy_Data state */
//xmachine_memory_Household * temp_xmachine_Household_Household_Start_Policy_Data;
xmachine_memory_Household_state * Household_Household_Start_Policy_Data_state;
/* Pointer to list of Household agents in state start_Household state */
//xmachine_memory_Household * temp_xmachine_Household_start_Household;
xmachine_memory_Household_state * Household_start_Household_state;
/* Pointer to list of Household agents in state 08b state */
//xmachine_memory_Household * temp_xmachine_Household_08b;
xmachine_memory_Household_state * Household_08b_state;
/* Pointer to list of Household agents in state 08 state */
//xmachine_memory_Household * temp_xmachine_Household_08;
xmachine_memory_Household_state * Household_08_state;
/* Pointer to list of Household agents in state 07 state */
//xmachine_memory_Household * temp_xmachine_Household_07;
xmachine_memory_Household_state * Household_07_state;
/* Pointer to list of Household agents in state 06e state */
//xmachine_memory_Household * temp_xmachine_Household_06e;
xmachine_memory_Household_state * Household_06e_state;
/* Pointer to list of Household agents in state 06d state */
//xmachine_memory_Household * temp_xmachine_Household_06d;
xmachine_memory_Household_state * Household_06d_state;
/* Pointer to list of Household agents in state 06c state */
//xmachine_memory_Household * temp_xmachine_Household_06c;
xmachine_memory_Household_state * Household_06c_state;
/* Pointer to list of Household agents in state 06b state */
//xmachine_memory_Household * temp_xmachine_Household_06b;
xmachine_memory_Household_state * Household_06b_state;
/* Pointer to list of Household agents in state 05 state */
//xmachine_memory_Household * temp_xmachine_Household_05;
xmachine_memory_Household_state * Household_05_state;
/* Pointer to list of Household agents in state 04 state */
//xmachine_memory_Household * temp_xmachine_Household_04;
xmachine_memory_Household_state * Household_04_state;
/* Pointer to list of Household agents in state 03 state */
//xmachine_memory_Household * temp_xmachine_Household_03;
xmachine_memory_Household_state * Household_03_state;
/* Pointer to list of Household agents in state 02 state */
//xmachine_memory_Household * temp_xmachine_Household_02;
xmachine_memory_Household_state * Household_02_state;
/* Pointer to list of Household agents in state 06 state */
//xmachine_memory_Household * temp_xmachine_Household_06;
xmachine_memory_Household_state * Household_06_state;
/* Pointer to list of Household agents in state 01b state */
//xmachine_memory_Household * temp_xmachine_Household_01b;
xmachine_memory_Household_state * Household_01b_state;
/* Pointer to list of Household agents in state 01 state */
//xmachine_memory_Household * temp_xmachine_Household_01;
xmachine_memory_Household_state * Household_01_state;
/* Pointer to list of Household agents in state 01a state */
//xmachine_memory_Household * temp_xmachine_Household_01a;
xmachine_memory_Household_state * Household_01a_state;
/* Pointer to list of Household agents in state 01d state */
//xmachine_memory_Household * temp_xmachine_Household_01d;
xmachine_memory_Household_state * Household_01d_state;
/* Pointer to list of Household agents in state WAITORDERSTATUS state */
//xmachine_memory_Household * temp_xmachine_Household_WAITORDERSTATUS;
xmachine_memory_Household_state * Household_WAITORDERSTATUS_state;
/* Pointer to list of Household agents in state Household_Start_Labour_Role state */
//xmachine_memory_Household * temp_xmachine_Household_Household_Start_Labour_Role;
xmachine_memory_Household_state * Household_Household_Start_Labour_Role_state;
/* Pointer to list of Household agents in state SEND_ORDERS state */
//xmachine_memory_Household * temp_xmachine_Household_SEND_ORDERS;
xmachine_memory_Household_state * Household_SEND_ORDERS_state;
/* Pointer to list of Household agents in state BOND_BELIEF_FORMATION state */
//xmachine_memory_Household * temp_xmachine_Household_BOND_BELIEF_FORMATION;
xmachine_memory_Household_state * Household_BOND_BELIEF_FORMATION_state;
/* Pointer to list of Household agents in state CHOOSE_TO_TRADE_OR_NOT state */
//xmachine_memory_Household * temp_xmachine_Household_CHOOSE_TO_TRADE_OR_NOT;
xmachine_memory_Household_state * Household_CHOOSE_TO_TRADE_OR_NOT_state;
/* Pointer to list of Household agents in state SELECTSTRATEGY state */
//xmachine_memory_Household * temp_xmachine_Household_SELECTSTRATEGY;
xmachine_memory_Household_state * Household_SELECTSTRATEGY_state;
/* Pointer to list of Household agents in state Household_Start_Financial_Market_Role state */
//xmachine_memory_Household * temp_xmachine_Household_Household_Start_Financial_Market_Role;
xmachine_memory_Household_state * Household_Household_Start_Financial_Market_Role_state;
/* Pointer to list of Household agents in state 12 state */
//xmachine_memory_Household * temp_xmachine_Household_12;
xmachine_memory_Household_state * Household_12_state;
/* Pointer to list of Household agents in state 14 state */
//xmachine_memory_Household * temp_xmachine_Household_14;
xmachine_memory_Household_state * Household_14_state;
/* Pointer to list of Household agents in state 11 state */
//xmachine_memory_Household * temp_xmachine_Household_11;
xmachine_memory_Household_state * Household_11_state;
/* Pointer to list of Household agents in state 10 state */
//xmachine_memory_Household * temp_xmachine_Household_10;
xmachine_memory_Household_state * Household_10_state;
/* Pointer to list of Household agents in state 15 state */
//xmachine_memory_Household * temp_xmachine_Household_15;
xmachine_memory_Household_state * Household_15_state;
/* Pointer to list of Household agents in state 09 state */
//xmachine_memory_Household * temp_xmachine_Household_09;
xmachine_memory_Household_state * Household_09_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Mall * current_xmachine_Mall;
xmachine_memory_Mall_holder * temp_xmachine_Mall_holder;
xmachine_memory_Mall_holder * current_xmachine_Mall_holder;
xmachine_memory_Mall_state * current_xmachine_Mall_next_state; /* New agents added to this state */
/* Pointer to list of Mall agents in state end_Mall state */
//xmachine_memory_Mall * temp_xmachine_Mall_end_Mall;
xmachine_memory_Mall_state * Mall_end_Mall_state;
/* Pointer to list of Mall agents in state 06 state */
//xmachine_memory_Mall * temp_xmachine_Mall_06;
xmachine_memory_Mall_state * Mall_06_state;
/* Pointer to list of Mall agents in state 05a state */
//xmachine_memory_Mall * temp_xmachine_Mall_05a;
xmachine_memory_Mall_state * Mall_05a_state;
/* Pointer to list of Mall agents in state 05 state */
//xmachine_memory_Mall * temp_xmachine_Mall_05;
xmachine_memory_Mall_state * Mall_05_state;
/* Pointer to list of Mall agents in state 04 state */
//xmachine_memory_Mall * temp_xmachine_Mall_04;
xmachine_memory_Mall_state * Mall_04_state;
/* Pointer to list of Mall agents in state 03 state */
//xmachine_memory_Mall * temp_xmachine_Mall_03;
xmachine_memory_Mall_state * Mall_03_state;
/* Pointer to list of Mall agents in state 02 state */
//xmachine_memory_Mall * temp_xmachine_Mall_02;
xmachine_memory_Mall_state * Mall_02_state;
/* Pointer to list of Mall agents in state 01 state */
//xmachine_memory_Mall * temp_xmachine_Mall_01;
xmachine_memory_Mall_state * Mall_01_state;
/* Pointer to list of Mall agents in state start_Mall state */
//xmachine_memory_Mall * temp_xmachine_Mall_start_Mall;
xmachine_memory_Mall_state * Mall_start_Mall_state;
/* Pointer to current $agent_name agent */
xmachine_memory_IGFirm * current_xmachine_IGFirm;
xmachine_memory_IGFirm_holder * temp_xmachine_IGFirm_holder;
xmachine_memory_IGFirm_holder * current_xmachine_IGFirm_holder;
xmachine_memory_IGFirm_state * current_xmachine_IGFirm_next_state; /* New agents added to this state */
/* Pointer to list of IGFirm agents in state start_IGFirm state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_start_IGFirm;
xmachine_memory_IGFirm_state * IGFirm_start_IGFirm_state;
/* Pointer to list of IGFirm agents in state end_IGFirm state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_end_IGFirm;
xmachine_memory_IGFirm_state * IGFirm_end_IGFirm_state;
/* Pointer to list of IGFirm agents in state 04b state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_04b;
xmachine_memory_IGFirm_state * IGFirm_04b_state;
/* Pointer to list of IGFirm agents in state 04 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_04;
xmachine_memory_IGFirm_state * IGFirm_04_state;
/* Pointer to list of IGFirm agents in state 03 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_03;
xmachine_memory_IGFirm_state * IGFirm_03_state;
/* Pointer to list of IGFirm agents in state 02 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_02;
xmachine_memory_IGFirm_state * IGFirm_02_state;
/* Pointer to list of IGFirm agents in state 01 state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_01;
xmachine_memory_IGFirm_state * IGFirm_01_state;
/* Pointer to list of IGFirm agents in state Start_IGFirm_Productivity state */
//xmachine_memory_IGFirm * temp_xmachine_IGFirm_Start_IGFirm_Productivity;
xmachine_memory_IGFirm_state * IGFirm_Start_IGFirm_Productivity_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Eurostat * current_xmachine_Eurostat;
xmachine_memory_Eurostat_holder * temp_xmachine_Eurostat_holder;
xmachine_memory_Eurostat_holder * current_xmachine_Eurostat_holder;
xmachine_memory_Eurostat_state * current_xmachine_Eurostat_next_state; /* New agents added to this state */
/* Pointer to list of Eurostat agents in state end_Eurostat state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_end_Eurostat;
xmachine_memory_Eurostat_state * Eurostat_end_Eurostat_state;
/* Pointer to list of Eurostat agents in state Eurostat_Start_EndOfYear_Loop state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_Eurostat_Start_EndOfYear_Loop;
xmachine_memory_Eurostat_state * Eurostat_Eurostat_Start_EndOfYear_Loop_state;
/* Pointer to list of Eurostat agents in state 05 state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_05;
xmachine_memory_Eurostat_state * Eurostat_05_state;
/* Pointer to list of Eurostat agents in state 04 state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_04;
xmachine_memory_Eurostat_state * Eurostat_04_state;
/* Pointer to list of Eurostat agents in state Eurostat_Start_Quarterly_Loop state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_Eurostat_Start_Quarterly_Loop;
xmachine_memory_Eurostat_state * Eurostat_Eurostat_Start_Quarterly_Loop_state;
/* Pointer to list of Eurostat agents in state 02 state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_02;
xmachine_memory_Eurostat_state * Eurostat_02_state;
/* Pointer to list of Eurostat agents in state Eurostat_Start_Monthly_Loop state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_Eurostat_Start_Monthly_Loop;
xmachine_memory_Eurostat_state * Eurostat_Eurostat_Start_Monthly_Loop_state;
/* Pointer to list of Eurostat agents in state 01 state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_01;
xmachine_memory_Eurostat_state * Eurostat_01_state;
/* Pointer to list of Eurostat agents in state Eurostat_Start_Firm_Data state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_Eurostat_Start_Firm_Data;
xmachine_memory_Eurostat_state * Eurostat_Eurostat_Start_Firm_Data_state;
/* Pointer to list of Eurostat agents in state Eurostat_Start_Policy_Data state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_Eurostat_Start_Policy_Data;
xmachine_memory_Eurostat_state * Eurostat_Eurostat_Start_Policy_Data_state;
/* Pointer to list of Eurostat agents in state start_Eurostat state */
//xmachine_memory_Eurostat * temp_xmachine_Eurostat_start_Eurostat;
xmachine_memory_Eurostat_state * Eurostat_start_Eurostat_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Clearinghouse * current_xmachine_Clearinghouse;
xmachine_memory_Clearinghouse_holder * temp_xmachine_Clearinghouse_holder;
xmachine_memory_Clearinghouse_holder * current_xmachine_Clearinghouse_holder;
xmachine_memory_Clearinghouse_state * current_xmachine_Clearinghouse_next_state; /* New agents added to this state */
/* Pointer to list of Clearinghouse agents in state end_Clearinghouse state */
//xmachine_memory_Clearinghouse * temp_xmachine_Clearinghouse_end_Clearinghouse;
xmachine_memory_Clearinghouse_state * Clearinghouse_end_Clearinghouse_state;
/* Pointer to list of Clearinghouse agents in state COMPUTEDPRICES state */
//xmachine_memory_Clearinghouse * temp_xmachine_Clearinghouse_COMPUTEDPRICES;
xmachine_memory_Clearinghouse_state * Clearinghouse_COMPUTEDPRICES_state;
/* Pointer to list of Clearinghouse agents in state RECEIVEDINFOSTOCK state */
//xmachine_memory_Clearinghouse * temp_xmachine_Clearinghouse_RECEIVEDINFOSTOCK;
xmachine_memory_Clearinghouse_state * Clearinghouse_RECEIVEDINFOSTOCK_state;
/* Pointer to list of Clearinghouse agents in state start_Clearinghouse state */
//xmachine_memory_Clearinghouse * temp_xmachine_Clearinghouse_start_Clearinghouse;
xmachine_memory_Clearinghouse_state * Clearinghouse_start_Clearinghouse_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Bank * current_xmachine_Bank;
xmachine_memory_Bank_holder * temp_xmachine_Bank_holder;
xmachine_memory_Bank_holder * current_xmachine_Bank_holder;
xmachine_memory_Bank_state * current_xmachine_Bank_next_state; /* New agents added to this state */
/* Pointer to list of Bank agents in state start_Bank state */
//xmachine_memory_Bank * temp_xmachine_Bank_start_Bank;
xmachine_memory_Bank_state * Bank_start_Bank_state;
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
xmachine_memory_Government * current_xmachine_Government;
xmachine_memory_Government_holder * temp_xmachine_Government_holder;
xmachine_memory_Government_holder * current_xmachine_Government_holder;
xmachine_memory_Government_state * current_xmachine_Government_next_state; /* New agents added to this state */
/* Pointer to list of Government agents in state end_Government state */
//xmachine_memory_Government * temp_xmachine_Government_end_Government;
xmachine_memory_Government_state * Government_end_Government_state;
/* Pointer to list of Government agents in state 09 state */
//xmachine_memory_Government * temp_xmachine_Government_09;
xmachine_memory_Government_state * Government_09_state;
/* Pointer to list of Government agents in state 08 state */
//xmachine_memory_Government * temp_xmachine_Government_08;
xmachine_memory_Government_state * Government_08_state;
/* Pointer to list of Government agents in state 07 state */
//xmachine_memory_Government * temp_xmachine_Government_07;
xmachine_memory_Government_state * Government_07_state;
/* Pointer to list of Government agents in state 06 state */
//xmachine_memory_Government * temp_xmachine_Government_06;
xmachine_memory_Government_state * Government_06_state;
/* Pointer to list of Government agents in state 05 state */
//xmachine_memory_Government * temp_xmachine_Government_05;
xmachine_memory_Government_state * Government_05_state;
/* Pointer to list of Government agents in state Gov_Start_Yearly_Loop state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Start_Yearly_Loop;
xmachine_memory_Government_state * Government_Gov_Start_Yearly_Loop_state;
/* Pointer to list of Government agents in state Gov_Start_Monthly_Loop state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Start_Monthly_Loop;
xmachine_memory_Government_state * Government_Gov_Start_Monthly_Loop_state;
/* Pointer to list of Government agents in state 04 state */
//xmachine_memory_Government * temp_xmachine_Government_04;
xmachine_memory_Government_state * Government_04_state;
/* Pointer to list of Government agents in state 03 state */
//xmachine_memory_Government * temp_xmachine_Government_03;
xmachine_memory_Government_state * Government_03_state;
/* Pointer to list of Government agents in state 02 state */
//xmachine_memory_Government * temp_xmachine_Government_02;
xmachine_memory_Government_state * Government_02_state;
/* Pointer to list of Government agents in state start_Government state */
//xmachine_memory_Government * temp_xmachine_Government_start_Government;
xmachine_memory_Government_state * Government_start_Government_state;
/* Pointer to list of Government agents in state 01 state */
//xmachine_memory_Government * temp_xmachine_Government_01;
xmachine_memory_Government_state * Government_01_state;
/* Pointer to list of Government agents in state GOVERNMENT_PORTFOLIO_UPDATED state */
//xmachine_memory_Government * temp_xmachine_Government_GOVERNMENT_PORTFOLIO_UPDATED;
xmachine_memory_Government_state * Government_GOVERNMENT_PORTFOLIO_UPDATED_state;
/* Pointer to list of Government agents in state GOVERNMENT_SENT_ORDER state */
//xmachine_memory_Government * temp_xmachine_Government_GOVERNMENT_SENT_ORDER;
xmachine_memory_Government_state * Government_GOVERNMENT_SENT_ORDER_state;
/* Pointer to list of Government agents in state GOVERNMENT_IN_DEFICIT state */
//xmachine_memory_Government * temp_xmachine_Government_GOVERNMENT_IN_DEFICIT;
xmachine_memory_Government_state * Government_GOVERNMENT_IN_DEFICIT_state;
/* Pointer to list of Government agents in state GOVERNMENT_SENT_info_bond state */
//xmachine_memory_Government * temp_xmachine_Government_GOVERNMENT_SENT_info_bond;
xmachine_memory_Government_state * Government_GOVERNMENT_SENT_info_bond_state;
/* Pointer to list of Government agents in state Gov_Start_Bond_Market state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Start_Bond_Market;
xmachine_memory_Government_state * Government_Gov_Start_Bond_Market_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Central_Bank * current_xmachine_Central_Bank;
xmachine_memory_Central_Bank_holder * temp_xmachine_Central_Bank_holder;
xmachine_memory_Central_Bank_holder * current_xmachine_Central_Bank_holder;
xmachine_memory_Central_Bank_state * current_xmachine_Central_Bank_next_state; /* New agents added to this state */
/* Pointer to list of Central_Bank agents in state end_Central_Bank state */
//xmachine_memory_Central_Bank * temp_xmachine_Central_Bank_end_Central_Bank;
xmachine_memory_Central_Bank_state * Central_Bank_end_Central_Bank_state;
/* Pointer to list of Central_Bank agents in state start_Central_Bank state */
//xmachine_memory_Central_Bank * temp_xmachine_Central_Bank_start_Central_Bank;
xmachine_memory_Central_Bank_state * Central_Bank_start_Central_Bank_state;


MBt_Board b_bank_account_update;
MBt_Iterator i_bank_account_update;

MBt_Board b_central_bank_account_update;
MBt_Iterator i_central_bank_account_update;

MBt_Board b_wage_payment;
MBt_Iterator i_wage_payment;

MBt_Board b_quality_price_info_1;
MBt_Iterator i_quality_price_info_1;

MBt_Board b_quality_price_info_2;
MBt_Iterator i_quality_price_info_2;

MBt_Board b_update_mall_stock;
MBt_Iterator i_update_mall_stock;

MBt_Board b_consumption_request_1;
MBt_Iterator i_consumption_request_1;

MBt_Board b_consumption_request_2;
MBt_Iterator i_consumption_request_2;

MBt_Board b_accepted_consumption_1;
MBt_Iterator i_accepted_consumption_1;

MBt_Board b_accepted_consumption_2;
MBt_Iterator i_accepted_consumption_2;

MBt_Board b_sales;
MBt_Iterator i_sales;

MBt_Board b_specific_skill_update;
MBt_Iterator i_specific_skill_update;

MBt_Board b_daily_revenue_to_bank;
MBt_Iterator i_daily_revenue_to_bank;

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

MBt_Board b_current_mall_stock_info;
MBt_Iterator i_current_mall_stock_info;

MBt_Board b_dividend_per_share;
MBt_Iterator i_dividend_per_share;

MBt_Board b_bankruptcy_illiquidity;
MBt_Iterator i_bankruptcy_illiquidity;

MBt_Board b_bankruptcy_insolvency;
MBt_Iterator i_bankruptcy_insolvency;

MBt_Board b_order;
MBt_Iterator i_order;

MBt_Board b_order_status;
MBt_Iterator i_order_status;

MBt_Board b_infoAssetCH;
MBt_Iterator i_infoAssetCH;

MBt_Board b_info_firm;
MBt_Iterator i_info_firm;

MBt_Board b_accountInterest;
MBt_Iterator i_accountInterest;

MBt_Board b_bankAccountUpdate;
MBt_Iterator i_bankAccountUpdate;

MBt_Board b_info_bond;
MBt_Iterator i_info_bond;

MBt_Board b_productivity;
MBt_Iterator i_productivity;

MBt_Board b_capital_good_request;
MBt_Iterator i_capital_good_request;

MBt_Board b_capital_good_profit_distribution;
MBt_Iterator i_capital_good_profit_distribution;

MBt_Board b_capital_good_delivery;
MBt_Iterator i_capital_good_delivery;

MBt_Board b_dividend;
MBt_Iterator i_dividend;

MBt_Board b_pay_capital_goods;
MBt_Iterator i_pay_capital_goods;

MBt_Board b_vacancies;
MBt_Iterator i_vacancies;

MBt_Board b_vacancies2;
MBt_Iterator i_vacancies2;

MBt_Board b_firing;
MBt_Iterator i_firing;

MBt_Board b_job_application;
MBt_Iterator i_job_application;

MBt_Board b_job_application2;
MBt_Iterator i_job_application2;

MBt_Board b_job_offer;
MBt_Iterator i_job_offer;

MBt_Board b_job_offer2;
MBt_Iterator i_job_offer2;

MBt_Board b_job_acceptance;
MBt_Iterator i_job_acceptance;

MBt_Board b_job_acceptance2;
MBt_Iterator i_job_acceptance2;

MBt_Board b_application_rejection;
MBt_Iterator i_application_rejection;

MBt_Board b_application_rejection2;
MBt_Iterator i_application_rejection2;

MBt_Board b_quitting;
MBt_Iterator i_quitting;

MBt_Board b_quitting2;
MBt_Iterator i_quitting2;

MBt_Board b_unemployment_notification;
MBt_Iterator i_unemployment_notification;

MBt_Board b_policy_announcement;
MBt_Iterator i_policy_announcement;

MBt_Board b_tax_payment;
MBt_Iterator i_tax_payment;

MBt_Board b_hh_transfer_notification;
MBt_Iterator i_hh_transfer_notification;

MBt_Board b_hh_subsidy_notification;
MBt_Iterator i_hh_subsidy_notification;

MBt_Board b_firm_transfer_notification;
MBt_Iterator i_firm_transfer_notification;

MBt_Board b_firm_subsidy_notification;
MBt_Iterator i_firm_subsidy_notification;

MBt_Board b_firm_send_data;
MBt_Iterator i_firm_send_data;

MBt_Board b_household_send_data;
MBt_Iterator i_household_send_data;

MBt_Board b_mall_data;
MBt_Iterator i_mall_data;

MBt_Board b_eurostat_send_specific_skills;
MBt_Iterator i_eurostat_send_specific_skills;

MBt_Board b_mean_wage_for_government;
MBt_Iterator i_mean_wage_for_government;

MBt_Board b_data_for_government;
MBt_Iterator i_data_for_government;


/** \var m_bank_account_update * bank_account_update_message
* \brief Pointer to message struct for looping through bank_account_update message list */
m_bank_account_update * bank_account_update_message;
/** \var m_central_bank_account_update * central_bank_account_update_message
* \brief Pointer to message struct for looping through central_bank_account_update message list */
m_central_bank_account_update * central_bank_account_update_message;
/** \var m_wage_payment * wage_payment_message
* \brief Pointer to message struct for looping through wage_payment message list */
m_wage_payment * wage_payment_message;
/** \var m_quality_price_info_1 * quality_price_info_1_message
* \brief Pointer to message struct for looping through quality_price_info_1 message list */
m_quality_price_info_1 * quality_price_info_1_message;
/** \var m_quality_price_info_2 * quality_price_info_2_message
* \brief Pointer to message struct for looping through quality_price_info_2 message list */
m_quality_price_info_2 * quality_price_info_2_message;
/** \var m_update_mall_stock * update_mall_stock_message
* \brief Pointer to message struct for looping through update_mall_stock message list */
m_update_mall_stock * update_mall_stock_message;
/** \var m_consumption_request_1 * consumption_request_1_message
* \brief Pointer to message struct for looping through consumption_request_1 message list */
m_consumption_request_1 * consumption_request_1_message;
/** \var m_consumption_request_2 * consumption_request_2_message
* \brief Pointer to message struct for looping through consumption_request_2 message list */
m_consumption_request_2 * consumption_request_2_message;
/** \var m_accepted_consumption_1 * accepted_consumption_1_message
* \brief Pointer to message struct for looping through accepted_consumption_1 message list */
m_accepted_consumption_1 * accepted_consumption_1_message;
/** \var m_accepted_consumption_2 * accepted_consumption_2_message
* \brief Pointer to message struct for looping through accepted_consumption_2 message list */
m_accepted_consumption_2 * accepted_consumption_2_message;
/** \var m_sales * sales_message
* \brief Pointer to message struct for looping through sales message list */
m_sales * sales_message;
/** \var m_specific_skill_update * specific_skill_update_message
* \brief Pointer to message struct for looping through specific_skill_update message list */
m_specific_skill_update * specific_skill_update_message;
/** \var m_daily_revenue_to_bank * daily_revenue_to_bank_message
* \brief Pointer to message struct for looping through daily_revenue_to_bank message list */
m_daily_revenue_to_bank * daily_revenue_to_bank_message;
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
/** \var m_current_mall_stock_info * current_mall_stock_info_message
* \brief Pointer to message struct for looping through current_mall_stock_info message list */
m_current_mall_stock_info * current_mall_stock_info_message;
/** \var m_dividend_per_share * dividend_per_share_message
* \brief Pointer to message struct for looping through dividend_per_share message list */
m_dividend_per_share * dividend_per_share_message;
/** \var m_bankruptcy_illiquidity * bankruptcy_illiquidity_message
* \brief Pointer to message struct for looping through bankruptcy_illiquidity message list */
m_bankruptcy_illiquidity * bankruptcy_illiquidity_message;
/** \var m_bankruptcy_insolvency * bankruptcy_insolvency_message
* \brief Pointer to message struct for looping through bankruptcy_insolvency message list */
m_bankruptcy_insolvency * bankruptcy_insolvency_message;
/** \var m_order * order_message
* \brief Pointer to message struct for looping through order message list */
m_order * order_message;
/** \var m_order_status * order_status_message
* \brief Pointer to message struct for looping through order_status message list */
m_order_status * order_status_message;
/** \var m_infoAssetCH * infoAssetCH_message
* \brief Pointer to message struct for looping through infoAssetCH message list */
m_infoAssetCH * infoAssetCH_message;
/** \var m_info_firm * info_firm_message
* \brief Pointer to message struct for looping through info_firm message list */
m_info_firm * info_firm_message;
/** \var m_accountInterest * accountInterest_message
* \brief Pointer to message struct for looping through accountInterest message list */
m_accountInterest * accountInterest_message;
/** \var m_bankAccountUpdate * bankAccountUpdate_message
* \brief Pointer to message struct for looping through bankAccountUpdate message list */
m_bankAccountUpdate * bankAccountUpdate_message;
/** \var m_info_bond * info_bond_message
* \brief Pointer to message struct for looping through info_bond message list */
m_info_bond * info_bond_message;
/** \var m_productivity * productivity_message
* \brief Pointer to message struct for looping through productivity message list */
m_productivity * productivity_message;
/** \var m_capital_good_request * capital_good_request_message
* \brief Pointer to message struct for looping through capital_good_request message list */
m_capital_good_request * capital_good_request_message;
/** \var m_capital_good_profit_distribution * capital_good_profit_distribution_message
* \brief Pointer to message struct for looping through capital_good_profit_distribution message list */
m_capital_good_profit_distribution * capital_good_profit_distribution_message;
/** \var m_capital_good_delivery * capital_good_delivery_message
* \brief Pointer to message struct for looping through capital_good_delivery message list */
m_capital_good_delivery * capital_good_delivery_message;
/** \var m_dividend * dividend_message
* \brief Pointer to message struct for looping through dividend message list */
m_dividend * dividend_message;
/** \var m_pay_capital_goods * pay_capital_goods_message
* \brief Pointer to message struct for looping through pay_capital_goods message list */
m_pay_capital_goods * pay_capital_goods_message;
/** \var m_vacancies * vacancies_message
* \brief Pointer to message struct for looping through vacancies message list */
m_vacancies * vacancies_message;
/** \var m_vacancies2 * vacancies2_message
* \brief Pointer to message struct for looping through vacancies2 message list */
m_vacancies2 * vacancies2_message;
/** \var m_firing * firing_message
* \brief Pointer to message struct for looping through firing message list */
m_firing * firing_message;
/** \var m_job_application * job_application_message
* \brief Pointer to message struct for looping through job_application message list */
m_job_application * job_application_message;
/** \var m_job_application2 * job_application2_message
* \brief Pointer to message struct for looping through job_application2 message list */
m_job_application2 * job_application2_message;
/** \var m_job_offer * job_offer_message
* \brief Pointer to message struct for looping through job_offer message list */
m_job_offer * job_offer_message;
/** \var m_job_offer2 * job_offer2_message
* \brief Pointer to message struct for looping through job_offer2 message list */
m_job_offer2 * job_offer2_message;
/** \var m_job_acceptance * job_acceptance_message
* \brief Pointer to message struct for looping through job_acceptance message list */
m_job_acceptance * job_acceptance_message;
/** \var m_job_acceptance2 * job_acceptance2_message
* \brief Pointer to message struct for looping through job_acceptance2 message list */
m_job_acceptance2 * job_acceptance2_message;
/** \var m_application_rejection * application_rejection_message
* \brief Pointer to message struct for looping through application_rejection message list */
m_application_rejection * application_rejection_message;
/** \var m_application_rejection2 * application_rejection2_message
* \brief Pointer to message struct for looping through application_rejection2 message list */
m_application_rejection2 * application_rejection2_message;
/** \var m_quitting * quitting_message
* \brief Pointer to message struct for looping through quitting message list */
m_quitting * quitting_message;
/** \var m_quitting2 * quitting2_message
* \brief Pointer to message struct for looping through quitting2 message list */
m_quitting2 * quitting2_message;
/** \var m_unemployment_notification * unemployment_notification_message
* \brief Pointer to message struct for looping through unemployment_notification message list */
m_unemployment_notification * unemployment_notification_message;
/** \var m_policy_announcement * policy_announcement_message
* \brief Pointer to message struct for looping through policy_announcement message list */
m_policy_announcement * policy_announcement_message;
/** \var m_tax_payment * tax_payment_message
* \brief Pointer to message struct for looping through tax_payment message list */
m_tax_payment * tax_payment_message;
/** \var m_hh_transfer_notification * hh_transfer_notification_message
* \brief Pointer to message struct for looping through hh_transfer_notification message list */
m_hh_transfer_notification * hh_transfer_notification_message;
/** \var m_hh_subsidy_notification * hh_subsidy_notification_message
* \brief Pointer to message struct for looping through hh_subsidy_notification message list */
m_hh_subsidy_notification * hh_subsidy_notification_message;
/** \var m_firm_transfer_notification * firm_transfer_notification_message
* \brief Pointer to message struct for looping through firm_transfer_notification message list */
m_firm_transfer_notification * firm_transfer_notification_message;
/** \var m_firm_subsidy_notification * firm_subsidy_notification_message
* \brief Pointer to message struct for looping through firm_subsidy_notification message list */
m_firm_subsidy_notification * firm_subsidy_notification_message;
/** \var m_firm_send_data * firm_send_data_message
* \brief Pointer to message struct for looping through firm_send_data message list */
m_firm_send_data * firm_send_data_message;
/** \var m_household_send_data * household_send_data_message
* \brief Pointer to message struct for looping through household_send_data message list */
m_household_send_data * household_send_data_message;
/** \var m_mall_data * mall_data_message
* \brief Pointer to message struct for looping through mall_data message list */
m_mall_data * mall_data_message;
/** \var m_eurostat_send_specific_skills * eurostat_send_specific_skills_message
* \brief Pointer to message struct for looping through eurostat_send_specific_skills message list */
m_eurostat_send_specific_skills * eurostat_send_specific_skills_message;
/** \var m_mean_wage_for_government * mean_wage_for_government_message
* \brief Pointer to message struct for looping through mean_wage_for_government message list */
m_mean_wage_for_government * mean_wage_for_government_message;
/** \var m_data_for_government * data_for_government_message
* \brief Pointer to message struct for looping through data_for_government message list */
m_data_for_government * data_for_government_message;
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
void add_consumption_request(consumption_request_array * array, int worker_id, int consumer_region_id, int firm_id, double quantity);
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
void add_mall_stock(mall_stock_array * array, int firm_id, int region_id, double stock, double price, double quality, double previous_price);
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

void init_financing_capital_array(financing_capital_array * array);
void reset_financing_capital_array(financing_capital_array * array);
void free_financing_capital_array(financing_capital_array * array);
void copy_financing_capital_array(financing_capital_array * from, financing_capital_array * to);
void add_financing_capital(financing_capital_array * array, double financing_per_month, int nr_periods_before_repayment);
void remove_financing_capital(financing_capital_array * array, int index);

void init_residual_var_datatype_array(residual_var_datatype_array * array);
void reset_residual_var_datatype_array(residual_var_datatype_array * array);
void free_residual_var_datatype_array(residual_var_datatype_array * array);
void copy_residual_var_datatype_array(residual_var_datatype_array * from, residual_var_datatype_array * to);
void add_residual_var_datatype(residual_var_datatype_array * array, double * value);
void remove_residual_var_datatype(residual_var_datatype_array * array, int index);

void init_account_item_array(account_item_array * array);
void reset_account_item_array(account_item_array * array);
void free_account_item_array(account_item_array * array);
void copy_account_item_array(account_item_array * from, account_item_array * to);
void add_account_item(account_item_array * array, int id, double payment_account);
void remove_account_item(account_item_array * array, int index);

void init_debt_item_array(debt_item_array * array);
void reset_debt_item_array(debt_item_array * array);
void free_debt_item_array(debt_item_array * array);
void copy_debt_item_array(debt_item_array * from, debt_item_array * to);
void add_debt_item(debt_item_array * array, int bank_id, double loan_value, double interest_rate, double installment_amount, double var_per_installment, double residual_var, double bad_debt, int nr_periods_before_repayment);
void remove_debt_item(debt_item_array * array, int index);

void init_Order_array(Order_array * array);
void reset_Order_array(Order_array * array);
void free_Order_array(Order_array * array);
void copy_Order_array(Order_array * from, Order_array * to);
void add_Order(Order_array * array, int issuer, int quantity, double price, int assetId);
void remove_Order(Order_array * array, int index);

void init_Belief_array(Belief_array * array);
void reset_Belief_array(Belief_array * array);
void free_Belief_array(Belief_array * array);
void copy_Belief_array(Belief_array * from, Belief_array * to);
void add_Belief(Belief_array * array, int asset_id, double expectedPriceReturns, double expectedTotalReturns, double expectedCashFlowYield, double volatility, double expectedEarning, double expectedEarningPayout, double last_price, double utility);
void remove_Belief(Belief_array * array, int index);

void init_Stock_array(Stock_array * array);
void reset_Stock_array(Stock_array * array);
void free_Stock_array(Stock_array * array);
void copy_Stock_array(Stock_array * from, Stock_array * to);
void add_Stock(Stock_array * array, int id, int nrOutStandingShares, int index, double * prices, double * returns);
void remove_Stock(Stock_array * array, int index);

void init_Bond_array(Bond_array * array);
void reset_Bond_array(Bond_array * array);
void free_Bond_array(Bond_array * array);
void copy_Bond_array(Bond_array * from, Bond_array * to);
void add_Bond(Bond_array * array, int id, int nr_outstanding, int quantity, double face_value, double nominal_yield, int maturity_day, int issue_day, double yield2maturity, double * prices, int index, double * returns);
void remove_Bond(Bond_array * array, int index);

void init_Asset_array(Asset_array * array);
void reset_Asset_array(Asset_array * array);
void free_Asset_array(Asset_array * array);
void copy_Asset_array(Asset_array * from, Asset_array * to);
void add_Asset(Asset_array * array, int id, int quantity, double lastPrice);
void remove_Asset(Asset_array * array, int index);

void init_ClearingMechanism_array(ClearingMechanism_array * array);
void reset_ClearingMechanism_array(ClearingMechanism_array * array);
void free_ClearingMechanism_array(ClearingMechanism_array * array);
void copy_ClearingMechanism_array(ClearingMechanism_array * from, ClearingMechanism_array * to);
void add_ClearingMechanism(ClearingMechanism_array * array, double lastPrice, int quantity, Order_array * sellOrders, Order_array * buyOrders, double_array * prices);
void remove_ClearingMechanism(ClearingMechanism_array * array, int index);

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

void init_logit_array(logit_array * array);
void reset_logit_array(logit_array * array);
void free_logit_array(logit_array * array);
void copy_logit_array(logit_array * from, logit_array * to);
void add_logit(logit_array * array, double logit_value, int worker_id, int general_skill);
void remove_logit(logit_array * array, int index);

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
void add_firm_data(firm_data_array * array, int region_id, int no_firms, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double total_earnings, double total_debt, double total_assets, double total_equity, double average_debt_earnings_ratio, double average_debt_equity_ratio, double labour_share_ratio, double monthly_sold_quantity, double monthly_output, double monthly_revenue, double monthly_planned_output, double gdp, double cpi, double cpi_last_month, int no_firm_births, int no_firm_deaths);
void remove_firm_data(firm_data_array * array, int index);

void init_region_data_item_array(region_data_item_array * array);
void reset_region_data_item_array(region_data_item_array * array);
void free_region_data_item_array(region_data_item_array * array);
void copy_region_data_item_array(region_data_item_array * from, region_data_item_array * to);
void add_region_data_item(region_data_item_array * array, double cpi, double cpi_last_month, double gdp, double output, int employment, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, int no_firms, int no_firm_births, int no_firm_deaths);
void remove_region_data_item(region_data_item_array * array, int index);

void init_tax_rates_item_array(tax_rates_item_array * array);
void reset_tax_rates_item_array(tax_rates_item_array * array);
void free_tax_rates_item_array(tax_rates_item_array * array);
void copy_tax_rates_item_array(tax_rates_item_array * from, tax_rates_item_array * to);
void add_tax_rates_item(tax_rates_item_array * array, int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat);
void remove_tax_rates_item(tax_rates_item_array * array, int index);

void init_history_item_array(history_item_array * array);
void reset_history_item_array(history_item_array * array);
void free_history_item_array(history_item_array * array);
void copy_history_item_array(history_item_array * from, history_item_array * to);
void add_history_item(history_item_array * array, double cpi, double gdp, double output, int employment, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, int no_firms, int no_firm_births, int no_firm_deaths, region_data_item_array * region_data);
void remove_history_item(history_item_array * array, int index);


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
void init_financing_capital(financing_capital * temp);
void init_financing_capital_static_array(financing_capital * array, int size);
void read_financing_capital(char * buffer, int * j, financing_capital * temp_datatype);
void read_financing_capital_dynamic_array(char * buffer, int * j, financing_capital_array * temp_datatype_array);
void read_financing_capital_static_array(char * buffer, int * j, financing_capital * temp_datatype_array, int size);
void write_financing_capital(FILE *file, financing_capital * temp_datatype);
void write_financing_capital_static_array(FILE *file, financing_capital * temp_datatype, int size);
void write_financing_capital_dynamic_array(FILE *file, financing_capital_array * temp_datatype);
void init_residual_var_datatype(residual_var_datatype * temp);
void init_residual_var_datatype_static_array(residual_var_datatype * array, int size);
void read_residual_var_datatype(char * buffer, int * j, residual_var_datatype * temp_datatype);
void read_residual_var_datatype_dynamic_array(char * buffer, int * j, residual_var_datatype_array * temp_datatype_array);
void read_residual_var_datatype_static_array(char * buffer, int * j, residual_var_datatype * temp_datatype_array, int size);
void write_residual_var_datatype(FILE *file, residual_var_datatype * temp_datatype);
void write_residual_var_datatype_static_array(FILE *file, residual_var_datatype * temp_datatype, int size);
void write_residual_var_datatype_dynamic_array(FILE *file, residual_var_datatype_array * temp_datatype);
void init_account_item(account_item * temp);
void init_account_item_static_array(account_item * array, int size);
void read_account_item(char * buffer, int * j, account_item * temp_datatype);
void read_account_item_dynamic_array(char * buffer, int * j, account_item_array * temp_datatype_array);
void read_account_item_static_array(char * buffer, int * j, account_item * temp_datatype_array, int size);
void write_account_item(FILE *file, account_item * temp_datatype);
void write_account_item_static_array(FILE *file, account_item * temp_datatype, int size);
void write_account_item_dynamic_array(FILE *file, account_item_array * temp_datatype);
void init_debt_item(debt_item * temp);
void init_debt_item_static_array(debt_item * array, int size);
void read_debt_item(char * buffer, int * j, debt_item * temp_datatype);
void read_debt_item_dynamic_array(char * buffer, int * j, debt_item_array * temp_datatype_array);
void read_debt_item_static_array(char * buffer, int * j, debt_item * temp_datatype_array, int size);
void write_debt_item(FILE *file, debt_item * temp_datatype);
void write_debt_item_static_array(FILE *file, debt_item * temp_datatype, int size);
void write_debt_item_dynamic_array(FILE *file, debt_item_array * temp_datatype);
void init_Order(Order * temp);
void init_Order_static_array(Order * array, int size);
void read_Order(char * buffer, int * j, Order * temp_datatype);
void read_Order_dynamic_array(char * buffer, int * j, Order_array * temp_datatype_array);
void read_Order_static_array(char * buffer, int * j, Order * temp_datatype_array, int size);
void write_Order(FILE *file, Order * temp_datatype);
void write_Order_static_array(FILE *file, Order * temp_datatype, int size);
void write_Order_dynamic_array(FILE *file, Order_array * temp_datatype);
void init_Belief(Belief * temp);
void init_Belief_static_array(Belief * array, int size);
void read_Belief(char * buffer, int * j, Belief * temp_datatype);
void read_Belief_dynamic_array(char * buffer, int * j, Belief_array * temp_datatype_array);
void read_Belief_static_array(char * buffer, int * j, Belief * temp_datatype_array, int size);
void write_Belief(FILE *file, Belief * temp_datatype);
void write_Belief_static_array(FILE *file, Belief * temp_datatype, int size);
void write_Belief_dynamic_array(FILE *file, Belief_array * temp_datatype);
void init_Stock(Stock * temp);
void init_Stock_static_array(Stock * array, int size);
void read_Stock(char * buffer, int * j, Stock * temp_datatype);
void read_Stock_dynamic_array(char * buffer, int * j, Stock_array * temp_datatype_array);
void read_Stock_static_array(char * buffer, int * j, Stock * temp_datatype_array, int size);
void write_Stock(FILE *file, Stock * temp_datatype);
void write_Stock_static_array(FILE *file, Stock * temp_datatype, int size);
void write_Stock_dynamic_array(FILE *file, Stock_array * temp_datatype);
void init_Bond(Bond * temp);
void init_Bond_static_array(Bond * array, int size);
void read_Bond(char * buffer, int * j, Bond * temp_datatype);
void read_Bond_dynamic_array(char * buffer, int * j, Bond_array * temp_datatype_array);
void read_Bond_static_array(char * buffer, int * j, Bond * temp_datatype_array, int size);
void write_Bond(FILE *file, Bond * temp_datatype);
void write_Bond_static_array(FILE *file, Bond * temp_datatype, int size);
void write_Bond_dynamic_array(FILE *file, Bond_array * temp_datatype);
void init_Asset(Asset * temp);
void init_Asset_static_array(Asset * array, int size);
void read_Asset(char * buffer, int * j, Asset * temp_datatype);
void read_Asset_dynamic_array(char * buffer, int * j, Asset_array * temp_datatype_array);
void read_Asset_static_array(char * buffer, int * j, Asset * temp_datatype_array, int size);
void write_Asset(FILE *file, Asset * temp_datatype);
void write_Asset_static_array(FILE *file, Asset * temp_datatype, int size);
void write_Asset_dynamic_array(FILE *file, Asset_array * temp_datatype);
void init_ClearingMechanism(ClearingMechanism * temp);
void init_ClearingMechanism_static_array(ClearingMechanism * array, int size);
void read_ClearingMechanism(char * buffer, int * j, ClearingMechanism * temp_datatype);
void read_ClearingMechanism_dynamic_array(char * buffer, int * j, ClearingMechanism_array * temp_datatype_array);
void read_ClearingMechanism_static_array(char * buffer, int * j, ClearingMechanism * temp_datatype_array, int size);
void write_ClearingMechanism(FILE *file, ClearingMechanism * temp_datatype);
void write_ClearingMechanism_static_array(FILE *file, ClearingMechanism * temp_datatype, int size);
void write_ClearingMechanism_dynamic_array(FILE *file, ClearingMechanism_array * temp_datatype);
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
void init_logit(logit * temp);
void init_logit_static_array(logit * array, int size);
void read_logit(char * buffer, int * j, logit * temp_datatype);
void read_logit_dynamic_array(char * buffer, int * j, logit_array * temp_datatype_array);
void read_logit_static_array(char * buffer, int * j, logit * temp_datatype_array, int size);
void write_logit(FILE *file, logit * temp_datatype);
void write_logit_static_array(FILE *file, logit * temp_datatype, int size);
void write_logit_dynamic_array(FILE *file, logit_array * temp_datatype);
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
void init_region_data_item(region_data_item * temp);
void init_region_data_item_static_array(region_data_item * array, int size);
void read_region_data_item(char * buffer, int * j, region_data_item * temp_datatype);
void read_region_data_item_dynamic_array(char * buffer, int * j, region_data_item_array * temp_datatype_array);
void read_region_data_item_static_array(char * buffer, int * j, region_data_item * temp_datatype_array, int size);
void write_region_data_item(FILE *file, region_data_item * temp_datatype);
void write_region_data_item_static_array(FILE *file, region_data_item * temp_datatype, int size);
void write_region_data_item_dynamic_array(FILE *file, region_data_item_array * temp_datatype);
void init_tax_rates_item(tax_rates_item * temp);
void init_tax_rates_item_static_array(tax_rates_item * array, int size);
void read_tax_rates_item(char * buffer, int * j, tax_rates_item * temp_datatype);
void read_tax_rates_item_dynamic_array(char * buffer, int * j, tax_rates_item_array * temp_datatype_array);
void read_tax_rates_item_static_array(char * buffer, int * j, tax_rates_item * temp_datatype_array, int size);
void write_tax_rates_item(FILE *file, tax_rates_item * temp_datatype);
void write_tax_rates_item_static_array(FILE *file, tax_rates_item * temp_datatype, int size);
void write_tax_rates_item_dynamic_array(FILE *file, tax_rates_item_array * temp_datatype);
void init_history_item(history_item * temp);
void init_history_item_static_array(history_item * array, int size);
void read_history_item(char * buffer, int * j, history_item * temp_datatype);
void read_history_item_dynamic_array(char * buffer, int * j, history_item_array * temp_datatype_array);
void read_history_item_static_array(char * buffer, int * j, history_item * temp_datatype_array, int size);
void write_history_item(FILE *file, history_item * temp_datatype);
void write_history_item_static_array(FILE *file, history_item * temp_datatype, int size);
void write_history_item_dynamic_array(FILE *file, history_item_array * temp_datatype);
void readinitialstates(char * filename, int * itno, double cloud_data[6], 
                       int partition_method, int flag);
void saveiterationdata(int iteration_number);

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
void free_financing_capital(financing_capital * temp);
void free_financing_capital_static_array(financing_capital * array, int size);
void copy_financing_capital(financing_capital * from, financing_capital * to);
void copy_financing_capital_static_array(financing_capital * from, financing_capital * to, int size);
void free_residual_var_datatype(residual_var_datatype * temp);
void free_residual_var_datatype_static_array(residual_var_datatype * array, int size);
void copy_residual_var_datatype(residual_var_datatype * from, residual_var_datatype * to);
void copy_residual_var_datatype_static_array(residual_var_datatype * from, residual_var_datatype * to, int size);
void free_account_item(account_item * temp);
void free_account_item_static_array(account_item * array, int size);
void copy_account_item(account_item * from, account_item * to);
void copy_account_item_static_array(account_item * from, account_item * to, int size);
void free_debt_item(debt_item * temp);
void free_debt_item_static_array(debt_item * array, int size);
void copy_debt_item(debt_item * from, debt_item * to);
void copy_debt_item_static_array(debt_item * from, debt_item * to, int size);
void free_Order(Order * temp);
void free_Order_static_array(Order * array, int size);
void copy_Order(Order * from, Order * to);
void copy_Order_static_array(Order * from, Order * to, int size);
void free_Belief(Belief * temp);
void free_Belief_static_array(Belief * array, int size);
void copy_Belief(Belief * from, Belief * to);
void copy_Belief_static_array(Belief * from, Belief * to, int size);
void free_Stock(Stock * temp);
void free_Stock_static_array(Stock * array, int size);
void copy_Stock(Stock * from, Stock * to);
void copy_Stock_static_array(Stock * from, Stock * to, int size);
void free_Bond(Bond * temp);
void free_Bond_static_array(Bond * array, int size);
void copy_Bond(Bond * from, Bond * to);
void copy_Bond_static_array(Bond * from, Bond * to, int size);
void free_Asset(Asset * temp);
void free_Asset_static_array(Asset * array, int size);
void copy_Asset(Asset * from, Asset * to);
void copy_Asset_static_array(Asset * from, Asset * to, int size);
void free_ClearingMechanism(ClearingMechanism * temp);
void free_ClearingMechanism_static_array(ClearingMechanism * array, int size);
void copy_ClearingMechanism(ClearingMechanism * from, ClearingMechanism * to);
void copy_ClearingMechanism_static_array(ClearingMechanism * from, ClearingMechanism * to, int size);
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
void free_logit(logit * temp);
void free_logit_static_array(logit * array, int size);
void copy_logit(logit * from, logit * to);
void copy_logit_static_array(logit * from, logit * to, int size);
void free_household_data(household_data * temp);
void free_household_data_static_array(household_data * array, int size);
void copy_household_data(household_data * from, household_data * to);
void copy_household_data_static_array(household_data * from, household_data * to, int size);
void free_firm_data(firm_data * temp);
void free_firm_data_static_array(firm_data * array, int size);
void copy_firm_data(firm_data * from, firm_data * to);
void copy_firm_data_static_array(firm_data * from, firm_data * to, int size);
void free_region_data_item(region_data_item * temp);
void free_region_data_item_static_array(region_data_item * array, int size);
void copy_region_data_item(region_data_item * from, region_data_item * to);
void copy_region_data_item_static_array(region_data_item * from, region_data_item * to, int size);
void free_tax_rates_item(tax_rates_item * temp);
void free_tax_rates_item_static_array(tax_rates_item * array, int size);
void copy_tax_rates_item(tax_rates_item * from, tax_rates_item * to);
void copy_tax_rates_item_static_array(tax_rates_item * from, tax_rates_item * to, int size);
void free_history_item(history_item * temp);
void free_history_item_static_array(history_item * array, int size);
void copy_history_item(history_item * from, history_item * to);
void copy_history_item_static_array(history_item * from, history_item * to, int size);

xmachine_memory_Firm_state * init_Firm_state();
xmachine_memory_Firm * init_Firm_agent();
void free_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * state);
void transition_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * from_state, xmachine_memory_Firm_state * to_state);
void add_Firm_agent_internal(xmachine_memory_Firm * agent, xmachine_memory_Firm_state * state);
void add_Firm_agent(int id, int region_id, int gov_id, int day_of_month_to_act, int last_day_of_month_to_act, double payment_account, int bank_id, double mean_wage, double needed_capital_stock, double actual_cap_price, double mean_specific_skills, double planned_production_quantity, double production_quantity, double planned_output, double output, double unit_costs, double total_supply, double production_costs, double revenue_per_day, double technological_frontier, double cum_revenue, double out_of_stock_costs, sales_statistics_array * malls_sales_statistics, double quality, double price, double price_last_month, double demand_capital_stock, double planned_production_costs, double adaption_production_volume_due_to_insufficient_finances, double fraction_reserved_for_delayed_payments, sold_quantities_per_mall_array * sold_quantities, double total_sold_quantity, double cum_total_sold_quantity, delivery_volume_per_mall_array * delivery_volume, delivery_volume_per_mall_array * planned_delivery_volume, mall_info_array * current_mall_stocks, double_array * last_planned_production_quantities, double total_external_financing_obtained, double capital_costs, double labour_costs, financing_capital_array * capital_financing, double financial_resources_for_production, double planned_value_capital_stock, double total_units_local_inventory, int dmarketmatrix[], residual_var_datatype residual_var[], double ebit, double earnings, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double net_earnings, double previous_net_earnings, double total_interest_payment, double total_debt_installment_payment, double total_dividend_payment, double current_share_price, double previous_dividend_per_share, double current_dividend_per_share, double previous_earnings_per_share, double current_earnings_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double debt_earnings_ratio, double debt_equity_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, debt_item_array * loans, double total_debt, double total_value_local_inventory, double total_units_capital_stock, double total_value_capital_stock, double total_capital_depreciation_value, double total_capital_depreciation_units, double total_assets, double equity, double production_liquidity_needs, double financial_liquidity_needs, double total_financial_needs, double external_financial_needs, double earnings_per_share, double total_payments, double total_interest_payments, double previous_shares_outstanding, double earnings_payout, double current_shares_outstanding, Stock stock, employee_array * employees, double wage_offer, double technology, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, int vacancies, double average_g_skill, double average_s_skill_of_1, double average_s_skill_of_2, double average_s_skill_of_3, double average_s_skill_of_4, double average_s_skill_of_5, double wage_offer_for_skill_1, double wage_offer_for_skill_2, double wage_offer_for_skill_3, double wage_offer_for_skill_4, double wage_offer_for_skill_5, int employees_needed, int age, double transfer_payment, double subsidy_payment, int active, int bankruptcy_idle_counter, int bankruptcy_state, int bankruptcy_insolvency_state, int bankruptcy_illiquidity_state, int financial_crisis_state);
void unittest_init_Firm_agent();
void unittest_free_Firm_agent();
xmachine_memory_Household_state * init_Household_state();
xmachine_memory_Household * init_Household_agent();
void free_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * state);
void transition_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * from_state, xmachine_memory_Household_state * to_state);
void add_Household_agent_internal(xmachine_memory_Household * agent, xmachine_memory_Household_state * state);
void add_Household_agent(int id, int region_id, int_array * neighboring_region_ids, int gov_id, int day_of_month_to_act, double payment_account, int bank_id, double consumption_budget, double mean_income, int week_of_month, double weekly_budget, int rationed, int mall_completely_sold_out, ordered_quantity order_quantity[], received_quantities received_quantity[], int day_of_week_to_act, int day_of_month_receive_income, double current_productivity_employer, double current_mean_specific_skills_employer, double total_taxes, double cum_total_dividends, double tax_rate_hh_capital, double tax_rate_hh_labour, double price_index, double price_index_base_period, double commuting_costs_price_level_weight, double_array * last_income, double expenditures, double received_dividend, double wealth, Belief_array * beliefs, Order_array * pendingOrders, Asset_array * assetsowned, double_array * assetWeights, double_array * assetUtilities, double cash_on_hand, int forwardWindow, int backwardWindow, int bins, double randomWeight, double fundamentalWeight, double chartistWeight, int holdingPeriodToForwardW, double lossaversion, double strategy, double wage, double wage_reservation, int general_skill, int on_the_job_search, int number_applications, double last_labour_income, double specific_skill, int employee_firm_id, int employer_region_id, int day_of_month_receive_benefit, double unemployment_benefit_pct, double transfer_payment, double subsidy_payment);
void unittest_init_Household_agent();
void unittest_free_Household_agent();
xmachine_memory_Mall_state * init_Mall_state();
xmachine_memory_Mall * init_Mall_agent();
void free_Mall_agent(xmachine_memory_Mall_holder * tmp, xmachine_memory_Mall_state * state);
void transition_Mall_agent(xmachine_memory_Mall_holder * tmp, xmachine_memory_Mall_state * from_state, xmachine_memory_Mall_state * to_state);
void add_Mall_agent_internal(xmachine_memory_Mall * agent, xmachine_memory_Mall_state * state);
void add_Mall_agent(int id, int region_id, int gov_id, int no_regions, mall_stock_array * current_stock, sales_in_mall_array * firm_revenues, double total_supply, double export_volume_matrix[], double export_value_matrix[], double export_previous_value_matrix[]);
void unittest_init_Mall_agent();
void unittest_free_Mall_agent();
xmachine_memory_IGFirm_state * init_IGFirm_state();
xmachine_memory_IGFirm * init_IGFirm_agent();
void free_IGFirm_agent(xmachine_memory_IGFirm_holder * tmp, xmachine_memory_IGFirm_state * state);
void transition_IGFirm_agent(xmachine_memory_IGFirm_holder * tmp, xmachine_memory_IGFirm_state * from_state, xmachine_memory_IGFirm_state * to_state);
void add_IGFirm_agent_internal(xmachine_memory_IGFirm * agent, xmachine_memory_IGFirm_state * state);
void add_IGFirm_agent(int id, int region_id, int gov_id, int bank_id, int day_of_month_to_act, double payment_account, double productivity, double capital_good_price, double revenue_per_day, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double net_profit, int outstanding_shares, double current_dividend_per_share, double cum_revenues, int age, double transfer_payment, double subsidy_payment);
void unittest_init_IGFirm_agent();
void unittest_free_IGFirm_agent();
xmachine_memory_Eurostat_state * init_Eurostat_state();
xmachine_memory_Eurostat * init_Eurostat_agent();
void free_Eurostat_agent(xmachine_memory_Eurostat_holder * tmp, xmachine_memory_Eurostat_state * state);
void transition_Eurostat_agent(xmachine_memory_Eurostat_holder * tmp, xmachine_memory_Eurostat_state * from_state, xmachine_memory_Eurostat_state * to_state);
void add_Eurostat_agent_internal(xmachine_memory_Eurostat * agent, xmachine_memory_Eurostat_state * state);
void add_Eurostat_agent(int id, int region_id, int no_regions, int switch_datastorage, int num_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, int no_firms, int no_vacancies, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, double firm_average_wage, double firm_average_wage_skill_1, double firm_average_wage_skill_2, double firm_average_wage_skill_3, double firm_average_wage_skill_4, double firm_average_wage_skill_5, double firm_average_s_skill, double firm_average_s_skill_1, double firm_average_s_skill_2, double firm_average_s_skill_3, double firm_average_s_skill_4, double firm_average_s_skill_5, firm_data_array * region_firm_data, household_data_array * region_household_data, tax_rates_item government_tax_rates[], double total_earnings, double total_debt, double total_assets, double total_equity, double average_debt_earnings_ratio, double average_debt_equity_ratio, double labour_share_ratio, double cpi, double gdp, double monthly_sold_quantity, double monthly_output, double monthly_revenue, double monthly_planned_output, double price_index, history_item history_monthly[], history_item history_quarterly[], history_item monthly_growth_rates, history_item quarterly_growth_rates, history_item annual_growth_rates_monthly, history_item annual_growth_rates_quarterly, int no_firm_births, int no_firm_deaths, int firm_age_distribution[], int firm_age_distribution_multiperiod[], int firm_age_distribution_1_period_lag[], int firm_age_distribution_2_period_lag[], double firm_birth_rate, double firm_death_rate, double survival_rate[], double survival_rate_multiperiod_1[], double survival_rate_multiperiod_2[], double survival_rate_multiperiod[], int max_firm_creation, int recession_started, int recession_duration, double export_volume_matrix[], double export_value_matrix[], double export_previous_value_matrix[], double region_export_volume[], double region_import_volume[], double region_export_value[], double region_import_value[], double region_import_previous_value[]);
void unittest_init_Eurostat_agent();
void unittest_free_Eurostat_agent();
xmachine_memory_Clearinghouse_state * init_Clearinghouse_state();
xmachine_memory_Clearinghouse * init_Clearinghouse_agent();
void free_Clearinghouse_agent(xmachine_memory_Clearinghouse_holder * tmp, xmachine_memory_Clearinghouse_state * state);
void transition_Clearinghouse_agent(xmachine_memory_Clearinghouse_holder * tmp, xmachine_memory_Clearinghouse_state * from_state, xmachine_memory_Clearinghouse_state * to_state);
void add_Clearinghouse_agent_internal(xmachine_memory_Clearinghouse * agent, xmachine_memory_Clearinghouse_state * state);
void add_Clearinghouse_agent(int id, int region_id, Asset_array * assets, ClearingMechanism clearingmechanism);
void unittest_init_Clearinghouse_agent();
void unittest_free_Clearinghouse_agent();
xmachine_memory_Bank_state * init_Bank_state();
xmachine_memory_Bank * init_Bank_agent();
void free_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * state);
void transition_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * from_state, xmachine_memory_Bank_state * to_state);
void add_Bank_agent_internal(xmachine_memory_Bank * agent, xmachine_memory_Bank_state * state);
void add_Bank_agent(int id, int region_id, int gov_id, double cash, double total_credit, double equity, double bce_debt, double alfa, double value_at_risk, double min_interest, double bank_gamma[], double profits[], double bank_lambda, double bce_interest, double bank_dividend_rate, double tax_rate_corporate, int number_of_shares, double debt_period, int loan_request_message_found, int day_of_month_to_act);
void unittest_init_Bank_agent();
void unittest_free_Bank_agent();
xmachine_memory_Government_state * init_Government_state();
xmachine_memory_Government * init_Government_agent();
void free_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * state);
void transition_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * from_state, xmachine_memory_Government_state * to_state);
void add_Government_agent_internal(xmachine_memory_Government * agent, xmachine_memory_Government_state * state);
void add_Government_agent(int id, int list_of_regions[], double payment_account, int day_of_month_to_act, Bond bond, Order pending_order, double deficit, double unemployment_benefit_pct, double money_financing_fraction, double gdp_fraction_consumption, double gdp_fraction_investment, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double monthly_tax_revenues, double yearly_tax_revenues, double monthly_unemployment_benefit_payment, double yearly_unemployment_benefit_payment, double hh_transfer_payment, double firm_transfer_payment, double monthly_transfer_payment, double yearly_transfer_payment, double hh_subsidy_payment, double firm_subsidy_payment, double monthly_subsidy_payment, double yearly_subsidy_payment, double monthly_bond_coupon_payment, double yearly_bond_coupon_payment, double gov_interest_rate, double yearly_investment_expenditure, double yearly_consumption_expenditure, double yearly_income, double yearly_expenditure, double total_debt, double yearly_budget_balance, double total_money_financing, double total_bond_financing, double country_wide_mean_wage, int num_unemployed, double gdp, double gdp_growth, double gdp_forecast, double yearly_income_forecast, double yearly_expenditure_budget, double budget_balance_forecast, double monthly_consumption_expenditure, double monthly_investment_expenditure, double monthly_budget_balance, double monthly_consumption_budget, double monthly_investment_budget, double monthly_income, double monthly_expenditure, double yearly_consumption_budget, double yearly_investment_budget);
void unittest_init_Government_agent();
void unittest_free_Government_agent();
xmachine_memory_Central_Bank_state * init_Central_Bank_state();
xmachine_memory_Central_Bank * init_Central_Bank_agent();
void free_Central_Bank_agent(xmachine_memory_Central_Bank_holder * tmp, xmachine_memory_Central_Bank_state * state);
void transition_Central_Bank_agent(xmachine_memory_Central_Bank_holder * tmp, xmachine_memory_Central_Bank_state * from_state, xmachine_memory_Central_Bank_state * to_state);
void add_Central_Bank_agent_internal(xmachine_memory_Central_Bank * agent, xmachine_memory_Central_Bank_state * state);
void add_Central_Bank_agent(int id, account_item_array * accounts);
void unittest_init_Central_Bank_agent();
void unittest_free_Central_Bank_agent();

void add_bank_account_update_message(int id, int bank_id, double payment_account);
m_bank_account_update * add_bank_account_update_message_internal(void);
m_bank_account_update * get_first_bank_account_update_message(void);
m_bank_account_update * get_next_bank_account_update_message(m_bank_account_update * current);
void freebank_account_updatemessages(void);
void add_central_bank_account_update_message(int id, double payment_account);
m_central_bank_account_update * add_central_bank_account_update_message_internal(void);
m_central_bank_account_update * get_first_central_bank_account_update_message(void);
m_central_bank_account_update * get_next_central_bank_account_update_message(m_central_bank_account_update * current);
void freecentral_bank_account_updatemessages(void);
void add_wage_payment_message(int firm_id, int worker_id, double payment, double productivity, double average_specific_skills);
m_wage_payment * add_wage_payment_message_internal(void);
m_wage_payment * get_first_wage_payment_message(void);
m_wage_payment * get_next_wage_payment_message(m_wage_payment * current);
void freewage_paymentmessages(void);
void add_quality_price_info_1_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available);
m_quality_price_info_1 * add_quality_price_info_1_message_internal(void);
m_quality_price_info_1 * get_first_quality_price_info_1_message(void);
m_quality_price_info_1 * get_next_quality_price_info_1_message(m_quality_price_info_1 * current);
void freequality_price_info_1messages(void);
void add_quality_price_info_2_message(int mall_id, int mall_region_id, int firm_id, double quality, double price, int available);
m_quality_price_info_2 * add_quality_price_info_2_message_internal(void);
m_quality_price_info_2 * get_first_quality_price_info_2_message(void);
m_quality_price_info_2 * get_next_quality_price_info_2_message(m_quality_price_info_2 * current);
void freequality_price_info_2messages(void);
void add_update_mall_stock_message(int mall_id, int firm_id, double quantity, double quality, double price, double previous_price);
m_update_mall_stock * add_update_mall_stock_message_internal(void);
m_update_mall_stock * get_first_update_mall_stock_message(void);
m_update_mall_stock * get_next_update_mall_stock_message(m_update_mall_stock * current);
void freeupdate_mall_stockmessages(void);
void add_consumption_request_1_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity);
m_consumption_request_1 * add_consumption_request_1_message_internal(void);
m_consumption_request_1 * get_first_consumption_request_1_message(void);
m_consumption_request_1 * get_next_consumption_request_1_message(m_consumption_request_1 * current);
void freeconsumption_request_1messages(void);
void add_consumption_request_2_message(int mall_id, int worker_id, int region_id, int firm_id, double quantity);
m_consumption_request_2 * add_consumption_request_2_message_internal(void);
m_consumption_request_2 * get_first_consumption_request_2_message(void);
m_consumption_request_2 * get_next_consumption_request_2_message(m_consumption_request_2 * current);
void freeconsumption_request_2messages(void);
void add_accepted_consumption_1_message(int mall_id, int household_id, double offered_consumption_volume, int rationed);
m_accepted_consumption_1 * add_accepted_consumption_1_message_internal(void);
m_accepted_consumption_1 * get_first_accepted_consumption_1_message(void);
m_accepted_consumption_1 * get_next_accepted_consumption_1_message(m_accepted_consumption_1 * current);
void freeaccepted_consumption_1messages(void);
void add_accepted_consumption_2_message(int mall_id, int household_id, double offered_consumption_volume, int rationed);
m_accepted_consumption_2 * add_accepted_consumption_2_message_internal(void);
m_accepted_consumption_2 * get_first_accepted_consumption_2_message(void);
m_accepted_consumption_2 * get_next_accepted_consumption_2_message(m_accepted_consumption_2 * current);
void freeaccepted_consumption_2messages(void);
void add_sales_message(int mall_id, int firm_id, double revenue, int stock_empty, double current_stock);
m_sales * add_sales_message_internal(void);
m_sales * get_first_sales_message(void);
m_sales * get_next_sales_message(m_sales * current);
void freesalesmessages(void);
void add_specific_skill_update_message(int id, int firm_id, double specific_skills);
m_specific_skill_update * add_specific_skill_update_message_internal(void);
m_specific_skill_update * get_first_specific_skill_update_message(void);
m_specific_skill_update * get_next_specific_skill_update_message(m_specific_skill_update * current);
void freespecific_skill_updatemessages(void);
void add_daily_revenue_to_bank_message(int id, int bank_id, double payment_account);
m_daily_revenue_to_bank * add_daily_revenue_to_bank_message_internal(void);
m_daily_revenue_to_bank * get_first_daily_revenue_to_bank_message(void);
m_daily_revenue_to_bank * get_next_daily_revenue_to_bank_message(m_daily_revenue_to_bank * current);
void freedaily_revenue_to_bankmessages(void);
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
void add_current_mall_stock_info_message(int firm_id, int gov_id, double tax_payment);
m_current_mall_stock_info * add_current_mall_stock_info_message_internal(void);
m_current_mall_stock_info * get_first_current_mall_stock_info_message(void);
m_current_mall_stock_info * get_next_current_mall_stock_info_message(m_current_mall_stock_info * current);
void freecurrent_mall_stock_infomessages(void);
void add_dividend_per_share_message(int firm_id, double current_dividend_per_share);
m_dividend_per_share * add_dividend_per_share_message_internal(void);
m_dividend_per_share * get_first_dividend_per_share_message(void);
m_dividend_per_share * get_next_dividend_per_share_message(m_dividend_per_share * current);
void freedividend_per_sharemessages(void);
void add_bankruptcy_illiquidity_message(int firm_id);
m_bankruptcy_illiquidity * add_bankruptcy_illiquidity_message_internal(void);
m_bankruptcy_illiquidity * get_first_bankruptcy_illiquidity_message(void);
m_bankruptcy_illiquidity * get_next_bankruptcy_illiquidity_message(m_bankruptcy_illiquidity * current);
void freebankruptcy_illiquiditymessages(void);
void add_bankruptcy_insolvency_message(int firm_id);
m_bankruptcy_insolvency * add_bankruptcy_insolvency_message_internal(void);
m_bankruptcy_insolvency * get_first_bankruptcy_insolvency_message(void);
m_bankruptcy_insolvency * get_next_bankruptcy_insolvency_message(m_bankruptcy_insolvency * current);
void freebankruptcy_insolvencymessages(void);
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
void add_infoAssetCH_message(int asset_id, double price, int quantity);
m_infoAssetCH * add_infoAssetCH_message_internal(void);
m_infoAssetCH * get_first_infoAssetCH_message(void);
m_infoAssetCH * get_next_infoAssetCH_message(m_infoAssetCH * current);
void freeinfoAssetCHmessages(void);
void add_info_firm_message(int id, double earnings, double dividend, double earnings_payout, double equity, Stock stock);
m_info_firm * add_info_firm_message_internal(void);
m_info_firm * get_first_info_firm_message(void);
m_info_firm * get_next_info_firm_message(m_info_firm * current);
void freeinfo_firmmessages(void);
void add_accountInterest_message(int bank_id, double interest);
m_accountInterest * add_accountInterest_message_internal(void);
m_accountInterest * get_first_accountInterest_message(void);
m_accountInterest * get_next_accountInterest_message(m_accountInterest * current);
void freeaccountInterestmessages(void);
void add_bankAccountUpdate_message(double account);
m_bankAccountUpdate * add_bankAccountUpdate_message_internal(void);
m_bankAccountUpdate * get_first_bankAccountUpdate_message(void);
m_bankAccountUpdate * get_next_bankAccountUpdate_message(m_bankAccountUpdate * current);
void freebankAccountUpdatemessages(void);
void add_info_bond_message(Bond bond);
m_info_bond * add_info_bond_message_internal(void);
m_info_bond * get_first_info_bond_message(void);
m_info_bond * get_next_info_bond_message(m_info_bond * current);
void freeinfo_bondmessages(void);
void add_productivity_message(int IGfirm_id, double cap_productivity, double cap_good_price);
m_productivity * add_productivity_message_internal(void);
m_productivity * get_first_productivity_message(void);
m_productivity * get_next_productivity_message(m_productivity * current);
void freeproductivitymessages(void);
void add_capital_good_request_message(int firm_id, double capital_good_demand);
m_capital_good_request * add_capital_good_request_message_internal(void);
m_capital_good_request * get_first_capital_good_request_message(void);
m_capital_good_request * get_next_capital_good_request_message(m_capital_good_request * current);
void freecapital_good_requestmessages(void);
void add_capital_good_profit_distribution_message(double capital_good_profit_shares);
m_capital_good_profit_distribution * add_capital_good_profit_distribution_message_internal(void);
m_capital_good_profit_distribution * get_first_capital_good_profit_distribution_message(void);
m_capital_good_profit_distribution * get_next_capital_good_profit_distribution_message(m_capital_good_profit_distribution * current);
void freecapital_good_profit_distributionmessages(void);
void add_capital_good_delivery_message(int firm_id, double capital_good_delivery_volume, double productivity, double capital_good_price);
m_capital_good_delivery * add_capital_good_delivery_message_internal(void);
m_capital_good_delivery * get_first_capital_good_delivery_message(void);
m_capital_good_delivery * get_next_capital_good_delivery_message(m_capital_good_delivery * current);
void freecapital_good_deliverymessages(void);
void add_dividend_message(double dividend);
m_dividend * add_dividend_message_internal(void);
m_dividend * get_first_dividend_message(void);
m_dividend * get_next_dividend_message(m_dividend * current);
void freedividendmessages(void);
void add_pay_capital_goods_message(int firm_id, double capital_bill);
m_pay_capital_goods * add_pay_capital_goods_message_internal(void);
m_pay_capital_goods * get_first_pay_capital_goods_message(void);
m_pay_capital_goods * get_next_pay_capital_goods_message(m_pay_capital_goods * current);
void freepay_capital_goodsmessages(void);
void add_vacancies_message(int firm_id, int region_id, int firm_vacancies, int skill_group, double firm_wage_offer);
m_vacancies * add_vacancies_message_internal(void);
m_vacancies * get_first_vacancies_message(void);
m_vacancies * get_next_vacancies_message(m_vacancies * current);
void freevacanciesmessages(void);
void add_vacancies2_message(int firm_id, int region_id, int firm_vacancies, int skill_group, double firm_wage_offer);
m_vacancies2 * add_vacancies2_message_internal(void);
m_vacancies2 * get_first_vacancies2_message(void);
m_vacancies2 * get_next_vacancies2_message(m_vacancies2 * current);
void freevacancies2messages(void);
void add_firing_message(int firm_id, int worker_id);
m_firing * add_firing_message_internal(void);
m_firing * get_first_firing_message(void);
m_firing * get_next_firing_message(m_firing * current);
void freefiringmessages(void);
void add_job_application_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill);
m_job_application * add_job_application_message_internal(void);
m_job_application * get_first_job_application_message(void);
m_job_application * get_next_job_application_message(m_job_application * current);
void freejob_applicationmessages(void);
void add_job_application2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill);
m_job_application2 * add_job_application2_message_internal(void);
m_job_application2 * get_first_job_application2_message(void);
m_job_application2 * get_next_job_application2_message(m_job_application2 * current);
void freejob_application2messages(void);
void add_job_offer_message(int firm_id, int worker_id, int region_id, double wage_offer);
m_job_offer * add_job_offer_message_internal(void);
m_job_offer * get_first_job_offer_message(void);
m_job_offer * get_next_job_offer_message(m_job_offer * current);
void freejob_offermessages(void);
void add_job_offer2_message(int firm_id, int worker_id, int region_id, double wage_offer);
m_job_offer2 * add_job_offer2_message_internal(void);
m_job_offer2 * get_first_job_offer2_message(void);
m_job_offer2 * get_next_job_offer2_message(m_job_offer2 * current);
void freejob_offer2messages(void);
void add_job_acceptance_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill);
m_job_acceptance * add_job_acceptance_message_internal(void);
m_job_acceptance * get_first_job_acceptance_message(void);
m_job_acceptance * get_next_job_acceptance_message(m_job_acceptance * current);
void freejob_acceptancemessages(void);
void add_job_acceptance2_message(int worker_id, int firm_id, int region_id, int general_skill, double specific_skill);
m_job_acceptance2 * add_job_acceptance2_message_internal(void);
m_job_acceptance2 * get_first_job_acceptance2_message(void);
m_job_acceptance2 * get_next_job_acceptance2_message(m_job_acceptance2 * current);
void freejob_acceptance2messages(void);
void add_application_rejection_message(int firm_id, int worker_id);
m_application_rejection * add_application_rejection_message_internal(void);
m_application_rejection * get_first_application_rejection_message(void);
m_application_rejection * get_next_application_rejection_message(m_application_rejection * current);
void freeapplication_rejectionmessages(void);
void add_application_rejection2_message(int firm_id, int worker_id);
m_application_rejection2 * add_application_rejection2_message_internal(void);
m_application_rejection2 * get_first_application_rejection2_message(void);
m_application_rejection2 * get_next_application_rejection2_message(m_application_rejection2 * current);
void freeapplication_rejection2messages(void);
void add_quitting_message(int worker_id, int firm_id);
m_quitting * add_quitting_message_internal(void);
m_quitting * get_first_quitting_message(void);
m_quitting * get_next_quitting_message(m_quitting * current);
void freequittingmessages(void);
void add_quitting2_message(int worker_id, int firm_id);
m_quitting2 * add_quitting2_message_internal(void);
m_quitting2 * get_first_quitting2_message(void);
m_quitting2 * get_next_quitting2_message(m_quitting2 * current);
void freequitting2messages(void);
void add_unemployment_notification_message(int gov_id, double last_labour_income);
m_unemployment_notification * add_unemployment_notification_message_internal(void);
m_unemployment_notification * get_first_unemployment_notification_message(void);
m_unemployment_notification * get_next_unemployment_notification_message(m_unemployment_notification * current);
void freeunemployment_notificationmessages(void);
void add_policy_announcement_message(int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double unemployment_benefit_pct, double hh_subsidy_payment, double firm_subsidy_payment, double hh_transfer_payment, double firm_transfer_payment);
m_policy_announcement * add_policy_announcement_message_internal(void);
m_policy_announcement * get_first_policy_announcement_message(void);
m_policy_announcement * get_next_policy_announcement_message(m_policy_announcement * current);
void freepolicy_announcementmessages(void);
void add_tax_payment_message(int gov_id, double tax_payment);
m_tax_payment * add_tax_payment_message_internal(void);
m_tax_payment * get_first_tax_payment_message(void);
m_tax_payment * get_next_tax_payment_message(m_tax_payment * current);
void freetax_paymentmessages(void);
void add_hh_transfer_notification_message(int gov_id);
m_hh_transfer_notification * add_hh_transfer_notification_message_internal(void);
m_hh_transfer_notification * get_first_hh_transfer_notification_message(void);
m_hh_transfer_notification * get_next_hh_transfer_notification_message(m_hh_transfer_notification * current);
void freehh_transfer_notificationmessages(void);
void add_hh_subsidy_notification_message(int gov_id);
m_hh_subsidy_notification * add_hh_subsidy_notification_message_internal(void);
m_hh_subsidy_notification * get_first_hh_subsidy_notification_message(void);
m_hh_subsidy_notification * get_next_hh_subsidy_notification_message(m_hh_subsidy_notification * current);
void freehh_subsidy_notificationmessages(void);
void add_firm_transfer_notification_message(int gov_id);
m_firm_transfer_notification * add_firm_transfer_notification_message_internal(void);
m_firm_transfer_notification * get_first_firm_transfer_notification_message(void);
m_firm_transfer_notification * get_next_firm_transfer_notification_message(m_firm_transfer_notification * current);
void freefirm_transfer_notificationmessages(void);
void add_firm_subsidy_notification_message(int gov_id);
m_firm_subsidy_notification * add_firm_subsidy_notification_message_internal(void);
m_firm_subsidy_notification * get_first_firm_subsidy_notification_message(void);
m_firm_subsidy_notification * get_next_firm_subsidy_notification_message(m_firm_subsidy_notification * current);
void freefirm_subsidy_notificationmessages(void);
void add_firm_send_data_message(int firm_id, int region_id, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double cum_revenue, double capital_costs, double net_earnings, double total_debt, double total_assets, double equity, double price, double price_last_month, double total_supply, double cum_total_sold_quantity, double output, double planned_output, int age);
m_firm_send_data * add_firm_send_data_message_internal(void);
m_firm_send_data * get_first_firm_send_data_message(void);
m_firm_send_data * get_next_firm_send_data_message(m_firm_send_data * current);
void freefirm_send_datamessages(void);
void add_household_send_data_message(int household_id, int region_id, int general_skill, int employment_status, double wage, double specific_skill);
m_household_send_data * add_household_send_data_message_internal(void);
m_household_send_data * get_first_household_send_data_message(void);
m_household_send_data * get_next_household_send_data_message(m_household_send_data * current);
void freehousehold_send_datamessages(void);
void add_mall_data_message(int mall_id, int firm_region, int household_region, double export_volume, double export_value, double export_previous_value);
m_mall_data * add_mall_data_message_internal(void);
m_mall_data * get_first_mall_data_message(void);
m_mall_data * get_next_mall_data_message(m_mall_data * current);
void freemall_datamessages(void);
void add_eurostat_send_specific_skills_message(int region_id, double specific_skill_1, double specific_skill_2, double specific_skill_3, double specific_skill_4, double specific_skill_5);
m_eurostat_send_specific_skills * add_eurostat_send_specific_skills_message_internal(void);
m_eurostat_send_specific_skills * get_first_eurostat_send_specific_skills_message(void);
m_eurostat_send_specific_skills * get_next_eurostat_send_specific_skills_message(m_eurostat_send_specific_skills * current);
void freeeurostat_send_specific_skillsmessages(void);
void add_mean_wage_for_government_message(int gov_id, double mean_wage);
m_mean_wage_for_government * add_mean_wage_for_government_message_internal(void);
m_mean_wage_for_government * get_first_mean_wage_for_government_message(void);
m_mean_wage_for_government * get_next_mean_wage_for_government_message(m_mean_wage_for_government * current);
void freemean_wage_for_governmentmessages(void);
void add_data_for_government_message(int region_id, double gdp, double mean_wage);
m_data_for_government * add_data_for_government_message_internal(void);
m_data_for_government * get_first_data_for_government_message(void);
m_data_for_government * get_next_data_for_government_message(m_data_for_government * current);
void freedata_for_governmentmessages(void);

void set_id(int id);
int get_id();
void set_region_id(int region_id);
int get_region_id();
void set_gov_id(int gov_id);
int get_gov_id();
void set_day_of_month_to_act(int day_of_month_to_act);
int get_day_of_month_to_act();
void set_last_day_of_month_to_act(int last_day_of_month_to_act);
int get_last_day_of_month_to_act();
void set_payment_account(double payment_account);
double get_payment_account();
void set_bank_id(int bank_id);
int get_bank_id();
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
void set_planned_output(double planned_output);
double get_planned_output();
void set_output(double output);
double get_output();
void set_unit_costs(double unit_costs);
double get_unit_costs();
void set_total_supply(double total_supply);
double get_total_supply();
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
void set_demand_capital_stock(double demand_capital_stock);
double get_demand_capital_stock();
void set_planned_production_costs(double planned_production_costs);
double get_planned_production_costs();
void set_adaption_production_volume_due_to_insufficient_finances(double adaption_production_volume_due_to_insufficient_finances);
double get_adaption_production_volume_due_to_insufficient_finances();
void set_fraction_reserved_for_delayed_payments(double fraction_reserved_for_delayed_payments);
double get_fraction_reserved_for_delayed_payments();
sold_quantities_per_mall_array * get_sold_quantities();
void set_total_sold_quantity(double total_sold_quantity);
double get_total_sold_quantity();
void set_cum_total_sold_quantity(double cum_total_sold_quantity);
double get_cum_total_sold_quantity();
delivery_volume_per_mall_array * get_delivery_volume();
delivery_volume_per_mall_array * get_planned_delivery_volume();
mall_info_array * get_current_mall_stocks();
double_array * get_last_planned_production_quantities();
void set_total_external_financing_obtained(double total_external_financing_obtained);
double get_total_external_financing_obtained();
void set_capital_costs(double capital_costs);
double get_capital_costs();
void set_labour_costs(double labour_costs);
double get_labour_costs();
financing_capital_array * get_capital_financing();
void set_financial_resources_for_production(double financial_resources_for_production);
double get_financial_resources_for_production();
void set_planned_value_capital_stock(double planned_value_capital_stock);
double get_planned_value_capital_stock();
void set_total_units_local_inventory(double total_units_local_inventory);
double get_total_units_local_inventory();
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
void set_earnings_per_share(double earnings_per_share);
double get_earnings_per_share();
void set_total_payments(double total_payments);
double get_total_payments();
void set_total_interest_payments(double total_interest_payments);
double get_total_interest_payments();
void set_previous_shares_outstanding(double previous_shares_outstanding);
double get_previous_shares_outstanding();
void set_earnings_payout(double earnings_payout);
double get_earnings_payout();
void set_current_shares_outstanding(double current_shares_outstanding);
double get_current_shares_outstanding();
Stock * get_stock();
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
void set_employees_needed(int employees_needed);
int get_employees_needed();
void set_age(int age);
int get_age();
void set_transfer_payment(double transfer_payment);
double get_transfer_payment();
void set_subsidy_payment(double subsidy_payment);
double get_subsidy_payment();
void set_active(int active);
int get_active();
void set_bankruptcy_idle_counter(int bankruptcy_idle_counter);
int get_bankruptcy_idle_counter();
void set_bankruptcy_state(int bankruptcy_state);
int get_bankruptcy_state();
void set_bankruptcy_insolvency_state(int bankruptcy_insolvency_state);
int get_bankruptcy_insolvency_state();
void set_bankruptcy_illiquidity_state(int bankruptcy_illiquidity_state);
int get_bankruptcy_illiquidity_state();
void set_financial_crisis_state(int financial_crisis_state);
int get_financial_crisis_state();
int_array * get_neighboring_region_ids();
void set_consumption_budget(double consumption_budget);
double get_consumption_budget();
void set_mean_income(double mean_income);
double get_mean_income();
void set_week_of_month(int week_of_month);
int get_week_of_month();
void set_weekly_budget(double weekly_budget);
double get_weekly_budget();
void set_rationed(int rationed);
int get_rationed();
void set_mall_completely_sold_out(int mall_completely_sold_out);
int get_mall_completely_sold_out();
ordered_quantity * get_order_quantity();
received_quantities * get_received_quantity();
void set_day_of_week_to_act(int day_of_week_to_act);
int get_day_of_week_to_act();
void set_day_of_month_receive_income(int day_of_month_receive_income);
int get_day_of_month_receive_income();
void set_current_productivity_employer(double current_productivity_employer);
double get_current_productivity_employer();
void set_current_mean_specific_skills_employer(double current_mean_specific_skills_employer);
double get_current_mean_specific_skills_employer();
void set_total_taxes(double total_taxes);
double get_total_taxes();
void set_cum_total_dividends(double cum_total_dividends);
double get_cum_total_dividends();
void set_tax_rate_hh_capital(double tax_rate_hh_capital);
double get_tax_rate_hh_capital();
void set_tax_rate_hh_labour(double tax_rate_hh_labour);
double get_tax_rate_hh_labour();
void set_price_index(double price_index);
double get_price_index();
void set_price_index_base_period(double price_index_base_period);
double get_price_index_base_period();
void set_commuting_costs_price_level_weight(double commuting_costs_price_level_weight);
double get_commuting_costs_price_level_weight();
double_array * get_last_income();
void set_expenditures(double expenditures);
double get_expenditures();
void set_received_dividend(double received_dividend);
double get_received_dividend();
void set_wealth(double wealth);
double get_wealth();
Belief_array * get_beliefs();
Order_array * get_pendingOrders();
Asset_array * get_assetsowned();
double_array * get_assetWeights();
double_array * get_assetUtilities();
void set_cash_on_hand(double cash_on_hand);
double get_cash_on_hand();
void set_forwardWindow(int forwardWindow);
int get_forwardWindow();
void set_backwardWindow(int backwardWindow);
int get_backwardWindow();
void set_bins(int bins);
int get_bins();
void set_randomWeight(double randomWeight);
double get_randomWeight();
void set_fundamentalWeight(double fundamentalWeight);
double get_fundamentalWeight();
void set_chartistWeight(double chartistWeight);
double get_chartistWeight();
void set_holdingPeriodToForwardW(int holdingPeriodToForwardW);
int get_holdingPeriodToForwardW();
void set_lossaversion(double lossaversion);
double get_lossaversion();
void set_strategy(double strategy);
double get_strategy();
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
void set_last_labour_income(double last_labour_income);
double get_last_labour_income();
void set_specific_skill(double specific_skill);
double get_specific_skill();
void set_employee_firm_id(int employee_firm_id);
int get_employee_firm_id();
void set_employer_region_id(int employer_region_id);
int get_employer_region_id();
void set_day_of_month_receive_benefit(int day_of_month_receive_benefit);
int get_day_of_month_receive_benefit();
void set_unemployment_benefit_pct(double unemployment_benefit_pct);
double get_unemployment_benefit_pct();
void set_no_regions(int no_regions);
int get_no_regions();
mall_stock_array * get_current_stock();
sales_in_mall_array * get_firm_revenues();
double * get_export_volume_matrix();
double * get_export_value_matrix();
double * get_export_previous_value_matrix();
void set_productivity(double productivity);
double get_productivity();
void set_capital_good_price(double capital_good_price);
double get_capital_good_price();
void set_net_profit(double net_profit);
double get_net_profit();
void set_outstanding_shares(int outstanding_shares);
int get_outstanding_shares();
void set_cum_revenues(double cum_revenues);
double get_cum_revenues();
void set_switch_datastorage(int switch_datastorage);
int get_switch_datastorage();
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
tax_rates_item * get_government_tax_rates();
void set_total_earnings(double total_earnings);
double get_total_earnings();
void set_total_equity(double total_equity);
double get_total_equity();
void set_average_debt_earnings_ratio(double average_debt_earnings_ratio);
double get_average_debt_earnings_ratio();
void set_average_debt_equity_ratio(double average_debt_equity_ratio);
double get_average_debt_equity_ratio();
void set_labour_share_ratio(double labour_share_ratio);
double get_labour_share_ratio();
void set_cpi(double cpi);
double get_cpi();
void set_gdp(double gdp);
double get_gdp();
void set_monthly_sold_quantity(double monthly_sold_quantity);
double get_monthly_sold_quantity();
void set_monthly_output(double monthly_output);
double get_monthly_output();
void set_monthly_revenue(double monthly_revenue);
double get_monthly_revenue();
void set_monthly_planned_output(double monthly_planned_output);
double get_monthly_planned_output();
history_item * get_history_monthly();
history_item * get_history_quarterly();
history_item * get_monthly_growth_rates();
history_item * get_quarterly_growth_rates();
history_item * get_annual_growth_rates_monthly();
history_item * get_annual_growth_rates_quarterly();
void set_no_firm_births(int no_firm_births);
int get_no_firm_births();
void set_no_firm_deaths(int no_firm_deaths);
int get_no_firm_deaths();
int * get_firm_age_distribution();
int * get_firm_age_distribution_multiperiod();
int * get_firm_age_distribution_1_period_lag();
int * get_firm_age_distribution_2_period_lag();
void set_firm_birth_rate(double firm_birth_rate);
double get_firm_birth_rate();
void set_firm_death_rate(double firm_death_rate);
double get_firm_death_rate();
double * get_survival_rate();
double * get_survival_rate_multiperiod_1();
double * get_survival_rate_multiperiod_2();
double * get_survival_rate_multiperiod();
void set_max_firm_creation(int max_firm_creation);
int get_max_firm_creation();
void set_recession_started(int recession_started);
int get_recession_started();
void set_recession_duration(int recession_duration);
int get_recession_duration();
double * get_region_export_volume();
double * get_region_import_volume();
double * get_region_export_value();
double * get_region_import_value();
double * get_region_import_previous_value();
Asset_array * get_assets();
ClearingMechanism * get_clearingmechanism();
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
int * get_list_of_regions();
Bond * get_bond();
Order * get_pending_order();
void set_deficit(double deficit);
double get_deficit();
void set_money_financing_fraction(double money_financing_fraction);
double get_money_financing_fraction();
void set_gdp_fraction_consumption(double gdp_fraction_consumption);
double get_gdp_fraction_consumption();
void set_gdp_fraction_investment(double gdp_fraction_investment);
double get_gdp_fraction_investment();
void set_monthly_tax_revenues(double monthly_tax_revenues);
double get_monthly_tax_revenues();
void set_yearly_tax_revenues(double yearly_tax_revenues);
double get_yearly_tax_revenues();
void set_monthly_unemployment_benefit_payment(double monthly_unemployment_benefit_payment);
double get_monthly_unemployment_benefit_payment();
void set_yearly_unemployment_benefit_payment(double yearly_unemployment_benefit_payment);
double get_yearly_unemployment_benefit_payment();
void set_hh_transfer_payment(double hh_transfer_payment);
double get_hh_transfer_payment();
void set_firm_transfer_payment(double firm_transfer_payment);
double get_firm_transfer_payment();
void set_monthly_transfer_payment(double monthly_transfer_payment);
double get_monthly_transfer_payment();
void set_yearly_transfer_payment(double yearly_transfer_payment);
double get_yearly_transfer_payment();
void set_hh_subsidy_payment(double hh_subsidy_payment);
double get_hh_subsidy_payment();
void set_firm_subsidy_payment(double firm_subsidy_payment);
double get_firm_subsidy_payment();
void set_monthly_subsidy_payment(double monthly_subsidy_payment);
double get_monthly_subsidy_payment();
void set_yearly_subsidy_payment(double yearly_subsidy_payment);
double get_yearly_subsidy_payment();
void set_monthly_bond_coupon_payment(double monthly_bond_coupon_payment);
double get_monthly_bond_coupon_payment();
void set_yearly_bond_coupon_payment(double yearly_bond_coupon_payment);
double get_yearly_bond_coupon_payment();
void set_gov_interest_rate(double gov_interest_rate);
double get_gov_interest_rate();
void set_yearly_investment_expenditure(double yearly_investment_expenditure);
double get_yearly_investment_expenditure();
void set_yearly_consumption_expenditure(double yearly_consumption_expenditure);
double get_yearly_consumption_expenditure();
void set_yearly_income(double yearly_income);
double get_yearly_income();
void set_yearly_expenditure(double yearly_expenditure);
double get_yearly_expenditure();
void set_yearly_budget_balance(double yearly_budget_balance);
double get_yearly_budget_balance();
void set_total_money_financing(double total_money_financing);
double get_total_money_financing();
void set_total_bond_financing(double total_bond_financing);
double get_total_bond_financing();
void set_country_wide_mean_wage(double country_wide_mean_wage);
double get_country_wide_mean_wage();
void set_num_unemployed(int num_unemployed);
int get_num_unemployed();
void set_gdp_growth(double gdp_growth);
double get_gdp_growth();
void set_gdp_forecast(double gdp_forecast);
double get_gdp_forecast();
void set_yearly_income_forecast(double yearly_income_forecast);
double get_yearly_income_forecast();
void set_yearly_expenditure_budget(double yearly_expenditure_budget);
double get_yearly_expenditure_budget();
void set_budget_balance_forecast(double budget_balance_forecast);
double get_budget_balance_forecast();
void set_monthly_consumption_expenditure(double monthly_consumption_expenditure);
double get_monthly_consumption_expenditure();
void set_monthly_investment_expenditure(double monthly_investment_expenditure);
double get_monthly_investment_expenditure();
void set_monthly_budget_balance(double monthly_budget_balance);
double get_monthly_budget_balance();
void set_monthly_consumption_budget(double monthly_consumption_budget);
double get_monthly_consumption_budget();
void set_monthly_investment_budget(double monthly_investment_budget);
double get_monthly_investment_budget();
void set_monthly_income(double monthly_income);
double get_monthly_income();
void set_monthly_expenditure(double monthly_expenditure);
double get_monthly_expenditure();
void set_yearly_consumption_budget(double yearly_consumption_budget);
double get_yearly_consumption_budget();
void set_yearly_investment_budget(double yearly_investment_budget);
double get_yearly_investment_budget();
account_item_array * get_accounts();
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
m_central_bank_account_update * get_next_message_central_bank_account_update_in_range(m_central_bank_account_update * current);
m_wage_payment * get_next_message_wage_payment_in_range(m_wage_payment * current);
m_quality_price_info_1 * get_next_message_quality_price_info_1_in_range(m_quality_price_info_1 * current);
m_quality_price_info_2 * get_next_message_quality_price_info_2_in_range(m_quality_price_info_2 * current);
m_update_mall_stock * get_next_message_update_mall_stock_in_range(m_update_mall_stock * current);
m_consumption_request_1 * get_next_message_consumption_request_1_in_range(m_consumption_request_1 * current);
m_consumption_request_2 * get_next_message_consumption_request_2_in_range(m_consumption_request_2 * current);
m_accepted_consumption_1 * get_next_message_accepted_consumption_1_in_range(m_accepted_consumption_1 * current);
m_accepted_consumption_2 * get_next_message_accepted_consumption_2_in_range(m_accepted_consumption_2 * current);
m_sales * get_next_message_sales_in_range(m_sales * current);
m_specific_skill_update * get_next_message_specific_skill_update_in_range(m_specific_skill_update * current);
m_daily_revenue_to_bank * get_next_message_daily_revenue_to_bank_in_range(m_daily_revenue_to_bank * current);
m_loan_request * get_next_message_loan_request_in_range(m_loan_request * current);
m_loan_conditions * get_next_message_loan_conditions_in_range(m_loan_conditions * current);
m_loan_acceptance * get_next_message_loan_acceptance_in_range(m_loan_acceptance * current);
m_installment * get_next_message_installment_in_range(m_installment * current);
m_bankruptcy * get_next_message_bankruptcy_in_range(m_bankruptcy * current);
m_BCE_return * get_next_message_BCE_return_in_range(m_BCE_return * current);
m_current_mall_stock_info * get_next_message_current_mall_stock_info_in_range(m_current_mall_stock_info * current);
m_dividend_per_share * get_next_message_dividend_per_share_in_range(m_dividend_per_share * current);
m_bankruptcy_illiquidity * get_next_message_bankruptcy_illiquidity_in_range(m_bankruptcy_illiquidity * current);
m_bankruptcy_insolvency * get_next_message_bankruptcy_insolvency_in_range(m_bankruptcy_insolvency * current);
m_order * get_next_message_order_in_range(m_order * current);
m_order_status * get_next_message_order_status_in_range(m_order_status * current);
m_infoAssetCH * get_next_message_infoAssetCH_in_range(m_infoAssetCH * current);
m_info_firm * get_next_message_info_firm_in_range(m_info_firm * current);
m_accountInterest * get_next_message_accountInterest_in_range(m_accountInterest * current);
m_bankAccountUpdate * get_next_message_bankAccountUpdate_in_range(m_bankAccountUpdate * current);
m_info_bond * get_next_message_info_bond_in_range(m_info_bond * current);
m_productivity * get_next_message_productivity_in_range(m_productivity * current);
m_capital_good_request * get_next_message_capital_good_request_in_range(m_capital_good_request * current);
m_capital_good_profit_distribution * get_next_message_capital_good_profit_distribution_in_range(m_capital_good_profit_distribution * current);
m_capital_good_delivery * get_next_message_capital_good_delivery_in_range(m_capital_good_delivery * current);
m_dividend * get_next_message_dividend_in_range(m_dividend * current);
m_pay_capital_goods * get_next_message_pay_capital_goods_in_range(m_pay_capital_goods * current);
m_vacancies * get_next_message_vacancies_in_range(m_vacancies * current);
m_vacancies2 * get_next_message_vacancies2_in_range(m_vacancies2 * current);
m_firing * get_next_message_firing_in_range(m_firing * current);
m_job_application * get_next_message_job_application_in_range(m_job_application * current);
m_job_application2 * get_next_message_job_application2_in_range(m_job_application2 * current);
m_job_offer * get_next_message_job_offer_in_range(m_job_offer * current);
m_job_offer2 * get_next_message_job_offer2_in_range(m_job_offer2 * current);
m_job_acceptance * get_next_message_job_acceptance_in_range(m_job_acceptance * current);
m_job_acceptance2 * get_next_message_job_acceptance2_in_range(m_job_acceptance2 * current);
m_application_rejection * get_next_message_application_rejection_in_range(m_application_rejection * current);
m_application_rejection2 * get_next_message_application_rejection2_in_range(m_application_rejection2 * current);
m_quitting * get_next_message_quitting_in_range(m_quitting * current);
m_quitting2 * get_next_message_quitting2_in_range(m_quitting2 * current);
m_unemployment_notification * get_next_message_unemployment_notification_in_range(m_unemployment_notification * current);
m_policy_announcement * get_next_message_policy_announcement_in_range(m_policy_announcement * current);
m_tax_payment * get_next_message_tax_payment_in_range(m_tax_payment * current);
m_hh_transfer_notification * get_next_message_hh_transfer_notification_in_range(m_hh_transfer_notification * current);
m_hh_subsidy_notification * get_next_message_hh_subsidy_notification_in_range(m_hh_subsidy_notification * current);
m_firm_transfer_notification * get_next_message_firm_transfer_notification_in_range(m_firm_transfer_notification * current);
m_firm_subsidy_notification * get_next_message_firm_subsidy_notification_in_range(m_firm_subsidy_notification * current);
m_firm_send_data * get_next_message_firm_send_data_in_range(m_firm_send_data * current);
m_household_send_data * get_next_message_household_send_data_in_range(m_household_send_data * current);
m_mall_data * get_next_message_mall_data_in_range(m_mall_data * current);
m_eurostat_send_specific_skills * get_next_message_eurostat_send_specific_skills_in_range(m_eurostat_send_specific_skills * current);
m_mean_wage_for_government * get_next_message_mean_wage_for_government_in_range(m_mean_wage_for_government * current);
m_data_for_government * get_next_message_data_for_government_in_range(m_data_for_government * current);

/* memory.c */
xmachine * add_xmachine(void);
/* timing.c */
double get_time(void);
