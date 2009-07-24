#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void test_Firm_calc_production_quantity(void);

void test_Firm_set_quantities_zero(void);

void test_Firm_calc_input_demands(void);

void test_Firm_calc_production_quantity_2(void);

void test_Firm_send_capital_demand(void);

void test_Firm_receive_capital_goods(void);

void test_Firm_execute_production(void);

void test_Firm_calc_pay_costs(void);

void test_Firm_send_goods_to_mall(void);

void test_Firm_calc_revenue(void);

void test_idle(void);

void test_Firm_compute_sales_statistics(void);

void test_Firm_update_specific_skills_of_workers(void);

void test_Firm_ask_loan(void);

void test_Firm_get_loan(void);

void test_Firm_compute_financial_payments(void);

void test_Firm_compute_income_statement(void);

void test_Firm_compute_dividends(void);

void test_Firm_compute_total_financial_payments(void);

void test_Firm_compute_balance_sheet(void);

void test_Firm_in_bankruptcy(void);

void test_idle(void);

void test_Firm_compute_total_liquidity_needs(void);

void test_Firm_compute_and_send_stock_orders(void);

void test_Firm_read_stock_transactions(void);

void test_Firm_check_financial_and_bankruptcy_state(void);

void test_Firm_in_bankruptcy(void);

void test_Firm_in_financial_crisis(void);

void test_Firm_not_in_bankruptcy(void);

void test_idle(void);

void test_idle(void);

void test_idle(void);

void test_Firm_execute_financial_payments(void);

void test_Firm_calculate_specific_skills_and_wage_offer(void);

void test_Firm_send_vacancies(void);

void test_Firm_send_redundancies(void);

void test_Firm_idle(void);

void test_Firm_read_job_applications_send_job_offer_or_rejection(void);

void test_Firm_read_job_responses(void);

void test_Firm_read_job_quitting(void);

void test_Firm_read_job_quitting(void);

void test_Firm_read_job_quitting(void);

void test_Firm_start_labour_market(void);

void test_Firm_finish_labour_market_first_round(void);

void test_Firm_finish_labour_market_first_round(void);

void test_Firm_update_wage_offer(void);

void test_Firm_send_vacancies_2(void);

void test_Firm_read_job_applications_send_job_offer_or_rejection_2(void);

void test_Firm_read_job_responses_2(void);

void test_Firm_read_job_quitting_2(void);

void test_Firm_read_job_quitting_2(void);

void test_Firm_update_wage_offer_2(void);

void test_Firm_idle(void);

void test_Firm_compute_mean_wage_specific_skills(void);

void test_idle(void);

void test_Firm_read_tax_rates(void);

void test_Firm_receive_data(void);

void test_idle(void);

void test_Firm_send_data_to_Eurostat(void);

void test_idle(void);

void test_Firm_send_payments_to_bank(void);

void test_Firm_send_info(void);

void test_Firm_receive_stock_info(void);

void test_Household_idle(void);

void test_Household_rank_and_buy_goods_1(void);

void test_Household_receive_goods_read_rationing(void);

void test_Household_set_values_zero(void);

void test_Household_rank_and_buy_goods_2(void);

void test_Household_receive_goods_read_rationing_2(void);

void test_Household_handle_leftover_budget(void);

void test_Household_read_firing_messages(void);

void test_Household_idle(void);

void test_Household_idle(void);

void test_Household_UNEMPLOYED_read_job_vacancies_and_send_applications(void);

void test_Household_on_the_job_search_decision(void);

void test_Household_OTJS_read_job_vacancies_and_send_applications(void);

void test_Household_idle(void);

void test_Household_read_job_offers_send_response(void);

void test_Household_finish_labour_market(void);

void test_Household_read_application_rejection_update_wage_reservation(void);

void test_Household_OTJS_read_job_vacancies_and_send_applications_2(void);

void test_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2(void);

void test_Household_read_job_offers_send_response_2(void);

void test_Household_read_application_rejection_update_wage_reservation_2(void);

void test_Household_idle(void);

void test_Household_receive_dividends(void);

void test_Household_idle(void);

void test_Household_idle(void);

void test_Household_send_subsidy_notification(void);

void test_Household_send_transfer_notification(void);

void test_Household_receive_wage(void);

void test_Household_update_specific_skills(void);

void test_Household_send_unemployment_benefit_notification(void);

void test_Household_send_tax_payment(void);

void test_Household_determine_consumption_budget(void);

void test_Household_idle(void);

void test_Household_read_tax_rates(void);

void test_Household_receive_data(void);

void test_Household_idle(void);

void test_Household_send_data_to_Eurostat(void);

void test_Household_idle(void);

void test_Household_receive_info_interest_from_bank(void);

void test_Household_select_strategy(void);

void test_Household_stock_beliefs_formation(void);

void test_Household_bond_beliefs_formation(void);

void test_Household_does_not_trading(void);

void test_Household_send_orders(void);

void test_Household_update_its_portfolio(void);

void test_Mall_reset_export_data(void);

void test_idle(void);

void test_Mall_update_mall_stock(void);

void test_Mall_send_quality_price_info_1(void);

void test_Mall_update_mall_stocks_sales_rationing_1(void);

void test_Mall_update_mall_stocks_sales_rationing_2(void);

void test_Mall_pay_firm(void);

void test_Mall_send_export_data(void);

void test_idle(void);

void test_IGFirm_update_productivity_price(void);

void test_IGFirm_idle(void);

void test_IGFirm_send_quality_price_info(void);

void test_IGFirm_send_capital_good(void);

void test_IGFirm_receive_payment(void);

void test_IGFirm_pay_taxes(void);

void test_IGFirm_dividend_payment(void);

void test_IGFirm_idle(void);

void test_IGFirm_idle(void);

void test_IGFirm_read_tax_rates(void);

void test_Eurostat_Initialization(void);

void test_Eurostat_idle(void);

void test_Eurostat_idle(void);

void test_Eurostat_read_tax_rates(void);

void test_Eurostat_send_data(void);

void test_Eurostat_idle(void);

void test_Eurostat_idle(void);

void test_Eurostat_calculate_data(void);

void test_Eurostat_store_history_monthly(void);

void test_Eurostat_compute_growth_rates_monthly(void);

void test_Eurostat_idle(void);

void test_Eurostat_store_history_quarterly(void);

void test_Eurostat_compute_growth_rates_quarterly(void);

void test_Eurostat_measure_recession(void);

void test_Eurostat_idle(void);

void test_Eurostat_idle(void);

void test_Eurostat_send_data_to_government(void);

void test_ClearingHouse_receive_info_stock(void);

void test_ClearingHouse_receive_orders_and_run(void);

void test_ClearingHouse_send_asset_information(void);

void test_Bank_decide_credit_conditions(void);

void test_Bank_give_loan(void);

void test_Bank_receive_installment(void);

void test_Bank_account_update_deposits(void);

void test_Bank_accounting(void);

void test_Bank_idle(void);

void test_Bank_send_accountInterest(void);

void test_Government_send_info_bond(void);

void test_Government_generate_pending_orders(void);

void test_Government_orders_issuing(void);

void test_Government_update_its_portfolio(void);

void test_Government_receive_info_bond(void);

void test_Government_idle(void);

void test_Government_send_policy_announcements(void);

void test_Government_read_tax_payments(void);

void test_Government_read_subsidy_notifications(void);

void test_Government_read_transfer_notifications(void);

void test_Government_read_unemployment_benefit_notifications(void);

void test_Government_idle(void);

void test_Government_budget_accounting(void);

void test_Government_send_account_update(void);

void test_Government_read_data_from_Eurostat(void);

void test_Government_set_policy(void);

void test_Government_yearly_resetting(void);

void test_Central_Bank_read_account_update(void);


int suite_Firm_init(void);
int suite_Firm_clean(void);

int suite_Household_init(void);
int suite_Household_clean(void);

int suite_Mall_init(void);
int suite_Mall_clean(void);

int suite_IGFirm_init(void);
int suite_IGFirm_clean(void);

int suite_Eurostat_init(void);
int suite_Eurostat_clean(void);

int suite_Clearinghouse_init(void);
int suite_Clearinghouse_clean(void);

int suite_Bank_init(void);
int suite_Bank_clean(void);

int suite_Government_init(void);
int suite_Government_clean(void);

int suite_Central_Bank_init(void);
int suite_Central_Bank_clean(void);

	

static CU_TestInfo tests_Firm[]= {
 { "test for Firm_calc_production_quantity",test_Firm_calc_production_quantity},
 { "test for Firm_set_quantities_zero",test_Firm_set_quantities_zero},
 { "test for Firm_calc_input_demands",test_Firm_calc_input_demands},
 { "test for Firm_calc_production_quantity_2",test_Firm_calc_production_quantity_2},
 { "test for Firm_send_capital_demand",test_Firm_send_capital_demand},
 { "test for Firm_receive_capital_goods",test_Firm_receive_capital_goods},
 { "test for Firm_execute_production",test_Firm_execute_production},
 { "test for Firm_calc_pay_costs",test_Firm_calc_pay_costs},
 { "test for Firm_send_goods_to_mall",test_Firm_send_goods_to_mall},
 { "test for Firm_calc_revenue",test_Firm_calc_revenue},
 { "test for idle",test_idle},
 { "test for Firm_compute_sales_statistics",test_Firm_compute_sales_statistics},
 { "test for Firm_update_specific_skills_of_workers",test_Firm_update_specific_skills_of_workers},
 { "test for Firm_ask_loan",test_Firm_ask_loan},
 { "test for Firm_get_loan",test_Firm_get_loan},
 { "test for Firm_compute_financial_payments",test_Firm_compute_financial_payments},
 { "test for Firm_compute_income_statement",test_Firm_compute_income_statement},
 { "test for Firm_compute_dividends",test_Firm_compute_dividends},
 { "test for Firm_compute_total_financial_payments",test_Firm_compute_total_financial_payments},
 { "test for Firm_compute_balance_sheet",test_Firm_compute_balance_sheet},
 { "test for Firm_in_bankruptcy",test_Firm_in_bankruptcy},
 { "test for idle",test_idle},
 { "test for Firm_compute_total_liquidity_needs",test_Firm_compute_total_liquidity_needs},
 { "test for Firm_compute_and_send_stock_orders",test_Firm_compute_and_send_stock_orders},
 { "test for Firm_read_stock_transactions",test_Firm_read_stock_transactions},
 { "test for Firm_check_financial_and_bankruptcy_state",test_Firm_check_financial_and_bankruptcy_state},
 { "test for Firm_in_bankruptcy",test_Firm_in_bankruptcy},
 { "test for Firm_in_financial_crisis",test_Firm_in_financial_crisis},
 { "test for Firm_not_in_bankruptcy",test_Firm_not_in_bankruptcy},
 { "test for idle",test_idle},
 { "test for idle",test_idle},
 { "test for idle",test_idle},
 { "test for Firm_execute_financial_payments",test_Firm_execute_financial_payments},
 { "test for Firm_calculate_specific_skills_and_wage_offer",test_Firm_calculate_specific_skills_and_wage_offer},
 { "test for Firm_send_vacancies",test_Firm_send_vacancies},
 { "test for Firm_send_redundancies",test_Firm_send_redundancies},
 { "test for Firm_idle",test_Firm_idle},
 { "test for Firm_read_job_applications_send_job_offer_or_rejection",test_Firm_read_job_applications_send_job_offer_or_rejection},
 { "test for Firm_read_job_responses",test_Firm_read_job_responses},
 { "test for Firm_read_job_quitting",test_Firm_read_job_quitting},
 { "test for Firm_read_job_quitting",test_Firm_read_job_quitting},
 { "test for Firm_read_job_quitting",test_Firm_read_job_quitting},
 { "test for Firm_start_labour_market",test_Firm_start_labour_market},
 { "test for Firm_finish_labour_market_first_round",test_Firm_finish_labour_market_first_round},
 { "test for Firm_finish_labour_market_first_round",test_Firm_finish_labour_market_first_round},
 { "test for Firm_update_wage_offer",test_Firm_update_wage_offer},
 { "test for Firm_send_vacancies_2",test_Firm_send_vacancies_2},
 { "test for Firm_read_job_applications_send_job_offer_or_rejection_2",test_Firm_read_job_applications_send_job_offer_or_rejection_2},
 { "test for Firm_read_job_responses_2",test_Firm_read_job_responses_2},
 { "test for Firm_read_job_quitting_2",test_Firm_read_job_quitting_2},
 { "test for Firm_read_job_quitting_2",test_Firm_read_job_quitting_2},
 { "test for Firm_update_wage_offer_2",test_Firm_update_wage_offer_2},
 { "test for Firm_idle",test_Firm_idle},
 { "test for Firm_compute_mean_wage_specific_skills",test_Firm_compute_mean_wage_specific_skills},
 { "test for idle",test_idle},
 { "test for Firm_read_tax_rates",test_Firm_read_tax_rates},
 { "test for Firm_receive_data",test_Firm_receive_data},
 { "test for idle",test_idle},
 { "test for Firm_send_data_to_Eurostat",test_Firm_send_data_to_Eurostat},
 { "test for idle",test_idle},
 { "test for Firm_send_payments_to_bank",test_Firm_send_payments_to_bank},
 { "test for Firm_send_info",test_Firm_send_info},
 { "test for Firm_receive_stock_info",test_Firm_receive_stock_info},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Household[]= {
 { "test for Household_idle",test_Household_idle},
 { "test for Household_rank_and_buy_goods_1",test_Household_rank_and_buy_goods_1},
 { "test for Household_receive_goods_read_rationing",test_Household_receive_goods_read_rationing},
 { "test for Household_set_values_zero",test_Household_set_values_zero},
 { "test for Household_rank_and_buy_goods_2",test_Household_rank_and_buy_goods_2},
 { "test for Household_receive_goods_read_rationing_2",test_Household_receive_goods_read_rationing_2},
 { "test for Household_handle_leftover_budget",test_Household_handle_leftover_budget},
 { "test for Household_read_firing_messages",test_Household_read_firing_messages},
 { "test for Household_idle",test_Household_idle},
 { "test for Household_idle",test_Household_idle},
 { "test for Household_UNEMPLOYED_read_job_vacancies_and_send_applications",test_Household_UNEMPLOYED_read_job_vacancies_and_send_applications},
 { "test for Household_on_the_job_search_decision",test_Household_on_the_job_search_decision},
 { "test for Household_OTJS_read_job_vacancies_and_send_applications",test_Household_OTJS_read_job_vacancies_and_send_applications},
 { "test for Household_idle",test_Household_idle},
 { "test for Household_read_job_offers_send_response",test_Household_read_job_offers_send_response},
 { "test for Household_finish_labour_market",test_Household_finish_labour_market},
 { "test for Household_read_application_rejection_update_wage_reservation",test_Household_read_application_rejection_update_wage_reservation},
 { "test for Household_OTJS_read_job_vacancies_and_send_applications_2",test_Household_OTJS_read_job_vacancies_and_send_applications_2},
 { "test for Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2",test_Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2},
 { "test for Household_read_job_offers_send_response_2",test_Household_read_job_offers_send_response_2},
 { "test for Household_read_application_rejection_update_wage_reservation_2",test_Household_read_application_rejection_update_wage_reservation_2},
 { "test for Household_idle",test_Household_idle},
 { "test for Household_receive_dividends",test_Household_receive_dividends},
 { "test for Household_idle",test_Household_idle},
 { "test for Household_idle",test_Household_idle},
 { "test for Household_send_subsidy_notification",test_Household_send_subsidy_notification},
 { "test for Household_send_transfer_notification",test_Household_send_transfer_notification},
 { "test for Household_receive_wage",test_Household_receive_wage},
 { "test for Household_update_specific_skills",test_Household_update_specific_skills},
 { "test for Household_send_unemployment_benefit_notification",test_Household_send_unemployment_benefit_notification},
 { "test for Household_send_tax_payment",test_Household_send_tax_payment},
 { "test for Household_determine_consumption_budget",test_Household_determine_consumption_budget},
 { "test for Household_idle",test_Household_idle},
 { "test for Household_read_tax_rates",test_Household_read_tax_rates},
 { "test for Household_receive_data",test_Household_receive_data},
 { "test for Household_idle",test_Household_idle},
 { "test for Household_send_data_to_Eurostat",test_Household_send_data_to_Eurostat},
 { "test for Household_idle",test_Household_idle},
 { "test for Household_receive_info_interest_from_bank",test_Household_receive_info_interest_from_bank},
 { "test for Household_select_strategy",test_Household_select_strategy},
 { "test for Household_stock_beliefs_formation",test_Household_stock_beliefs_formation},
 { "test for Household_bond_beliefs_formation",test_Household_bond_beliefs_formation},
 { "test for Household_does_not_trading",test_Household_does_not_trading},
 { "test for Household_send_orders",test_Household_send_orders},
 { "test for Household_update_its_portfolio",test_Household_update_its_portfolio},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Mall[]= {
 { "test for Mall_reset_export_data",test_Mall_reset_export_data},
 { "test for idle",test_idle},
 { "test for Mall_update_mall_stock",test_Mall_update_mall_stock},
 { "test for Mall_send_quality_price_info_1",test_Mall_send_quality_price_info_1},
 { "test for Mall_update_mall_stocks_sales_rationing_1",test_Mall_update_mall_stocks_sales_rationing_1},
 { "test for Mall_update_mall_stocks_sales_rationing_2",test_Mall_update_mall_stocks_sales_rationing_2},
 { "test for Mall_pay_firm",test_Mall_pay_firm},
 { "test for Mall_send_export_data",test_Mall_send_export_data},
 { "test for idle",test_idle},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_IGFirm[]= {
 { "test for IGFirm_update_productivity_price",test_IGFirm_update_productivity_price},
 { "test for IGFirm_idle",test_IGFirm_idle},
 { "test for IGFirm_send_quality_price_info",test_IGFirm_send_quality_price_info},
 { "test for IGFirm_send_capital_good",test_IGFirm_send_capital_good},
 { "test for IGFirm_receive_payment",test_IGFirm_receive_payment},
 { "test for IGFirm_pay_taxes",test_IGFirm_pay_taxes},
 { "test for IGFirm_dividend_payment",test_IGFirm_dividend_payment},
 { "test for IGFirm_idle",test_IGFirm_idle},
 { "test for IGFirm_idle",test_IGFirm_idle},
 { "test for IGFirm_read_tax_rates",test_IGFirm_read_tax_rates},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Eurostat[]= {
 { "test for Eurostat_Initialization",test_Eurostat_Initialization},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_read_tax_rates",test_Eurostat_read_tax_rates},
 { "test for Eurostat_send_data",test_Eurostat_send_data},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_calculate_data",test_Eurostat_calculate_data},
 { "test for Eurostat_store_history_monthly",test_Eurostat_store_history_monthly},
 { "test for Eurostat_compute_growth_rates_monthly",test_Eurostat_compute_growth_rates_monthly},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_store_history_quarterly",test_Eurostat_store_history_quarterly},
 { "test for Eurostat_compute_growth_rates_quarterly",test_Eurostat_compute_growth_rates_quarterly},
 { "test for Eurostat_measure_recession",test_Eurostat_measure_recession},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_send_data_to_government",test_Eurostat_send_data_to_government},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Clearinghouse[]= {
 { "test for ClearingHouse_receive_info_stock",test_ClearingHouse_receive_info_stock},
 { "test for ClearingHouse_receive_orders_and_run",test_ClearingHouse_receive_orders_and_run},
 { "test for ClearingHouse_send_asset_information",test_ClearingHouse_send_asset_information},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Bank[]= {
 { "test for Bank_decide_credit_conditions",test_Bank_decide_credit_conditions},
 { "test for Bank_give_loan",test_Bank_give_loan},
 { "test for Bank_receive_installment",test_Bank_receive_installment},
 { "test for Bank_account_update_deposits",test_Bank_account_update_deposits},
 { "test for Bank_accounting",test_Bank_accounting},
 { "test for Bank_idle",test_Bank_idle},
 { "test for Bank_send_accountInterest",test_Bank_send_accountInterest},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Government[]= {
 { "test for Government_send_info_bond",test_Government_send_info_bond},
 { "test for Government_generate_pending_orders",test_Government_generate_pending_orders},
 { "test for Government_orders_issuing",test_Government_orders_issuing},
 { "test for Government_update_its_portfolio",test_Government_update_its_portfolio},
 { "test for Government_receive_info_bond",test_Government_receive_info_bond},
 { "test for Government_idle",test_Government_idle},
 { "test for Government_send_policy_announcements",test_Government_send_policy_announcements},
 { "test for Government_read_tax_payments",test_Government_read_tax_payments},
 { "test for Government_read_subsidy_notifications",test_Government_read_subsidy_notifications},
 { "test for Government_read_transfer_notifications",test_Government_read_transfer_notifications},
 { "test for Government_read_unemployment_benefit_notifications",test_Government_read_unemployment_benefit_notifications},
 { "test for Government_idle",test_Government_idle},
 { "test for Government_budget_accounting",test_Government_budget_accounting},
 { "test for Government_send_account_update",test_Government_send_account_update},
 { "test for Government_read_data_from_Eurostat",test_Government_read_data_from_Eurostat},
 { "test for Government_set_policy",test_Government_set_policy},
 { "test for Government_yearly_resetting",test_Government_yearly_resetting},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Central_Bank[]= {
 { "test for Central_Bank_read_account_update",test_Central_Bank_read_account_update},

CU_TEST_INFO_NULL,
};


 static CU_SuiteInfo suites[] = {
{ "suite_Firm",  suite_Firm_init, suite_Firm_clean, tests_Firm},
{ "suite_Household",  suite_Household_init, suite_Household_clean, tests_Household},
{ "suite_Mall",  suite_Mall_init, suite_Mall_clean, tests_Mall},
{ "suite_IGFirm",  suite_IGFirm_init, suite_IGFirm_clean, tests_IGFirm},
{ "suite_Eurostat",  suite_Eurostat_init, suite_Eurostat_clean, tests_Eurostat},
{ "suite_Clearinghouse",  suite_Clearinghouse_init, suite_Clearinghouse_clean, tests_Clearinghouse},
{ "suite_Bank",  suite_Bank_init, suite_Bank_clean, tests_Bank},
{ "suite_Government",  suite_Government_init, suite_Government_clean, tests_Government},
{ "suite_Central_Bank",  suite_Central_Bank_init, suite_Central_Bank_clean, tests_Central_Bank},

CU_SUITE_INFO_NULL,
};

void AddTests();

void print_example_results(void);
 
