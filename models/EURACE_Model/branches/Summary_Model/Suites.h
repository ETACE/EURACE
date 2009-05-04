#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/Console.h>

void test_Firm_ask_loan(void);

void test_Firm_get_loan(void);

void test_Firm_financial_management_dummy(void);

void test_Firm_compute_and_send_stock_orders_dummy(void);

void test_Firm_check_bankruptcy_and_financial_crisis_states_dummy(void);

void test_Firm_execute_financial_payments(void);

void test_Firm_public_sector_dummy(void);

void test_Firm_bankruptcy_procedures_dummy(void);

void test_Firm_bankruptcy(void);

void test_Firm_no_bankruptcy(void);

void test_Firm_compute_total_liquidity_needs(void);

void test_idle(void);

void test_Firm_read_policy_announcements(void);

void test_Firm_receive_data(void);

void test_idle(void);

void test_Firm_send_data_to_Eurostat(void);

void test_idle(void);

void test_Firm_send_payments_to_bank(void);

void test_Firm_planned_production_costs_dummy(void);

void test_Firm_credit_market_dummy(void);

void test_Firm_labour_good_market_dummy(void);

void test_idle(void);

void test_idle(void);

void test_idle(void);

void test_Firm_receive_stock_info_dummy(void);

void test_Firm_send_info_dummy(void);

void test_Household_receive_data(void);

void test_Household_send_data_to_Eurostat(void);

void test_Household_labour_good_market_dummy(void);

void test_Household_financial_market_dummy(void);

void test_IGFirm_read_policy_announcements(void);

void test_Eurostat_Initialization(void);

void test_Eurostat_idle(void);

void test_Eurostat_idle(void);

void test_Eurostat_read_policy_announcements(void);

void test_Eurostat_send_data(void);

void test_Eurostat_idle(void);

void test_Eurostat_idle(void);

void test_Eurostat_calculate_data(void);

void test_Eurostat_compute_data(void);

void test_Eurostat_send_data_to_government(void);

void test_Bank_decide_credit_conditions(void);

void test_Bank_give_loan(void);

void test_Bank_receive_installment(void);

void test_Bank_account_update_deposits(void);

void test_Bank_accounting(void);

void test_Bank_idle(void);

void test_Government_idle(void);

void test_Government_send_policy_announcements(void);

void test_Government_read_tax_payments(void);

void test_Government_read_subsidy_notifications_transfers_and_unemployment_benefits_dummy(void);

void test_Government_monthly_budget_accounting_dummy(void);

void test_Government_read_data_from_Eurostat(void);

void test_Government_set_policy(void);

void test_Government_yearly_resetting(void);

void test_Government_yearly_budget_accounting(void);

void test_Government_bond_market_dummy(void);


int suite_Firm_init(void);
int suite_Firm_clean(void);

int suite_Household_init(void);
int suite_Household_clean(void);

int suite_IGFirm_init(void);
int suite_IGFirm_clean(void);

int suite_Eurostat_init(void);
int suite_Eurostat_clean(void);

int suite_Bank_init(void);
int suite_Bank_clean(void);

int suite_Government_init(void);
int suite_Government_clean(void);

	

static CU_TestInfo tests_Firm[]= {
 { "test for Firm_ask_loan",test_Firm_ask_loan},
 { "test for Firm_get_loan",test_Firm_get_loan},
 { "test for Firm_financial_management_dummy",test_Firm_financial_management_dummy},
 { "test for Firm_compute_and_send_stock_orders_dummy",test_Firm_compute_and_send_stock_orders_dummy},
 { "test for Firm_check_bankruptcy_and_financial_crisis_states_dummy",test_Firm_check_bankruptcy_and_financial_crisis_states_dummy},
 { "test for Firm_execute_financial_payments",test_Firm_execute_financial_payments},
 { "test for Firm_public_sector_dummy",test_Firm_public_sector_dummy},
 { "test for Firm_bankruptcy_procedures_dummy",test_Firm_bankruptcy_procedures_dummy},
 { "test for Firm_bankruptcy",test_Firm_bankruptcy},
 { "test for Firm_no_bankruptcy",test_Firm_no_bankruptcy},
 { "test for Firm_compute_total_liquidity_needs",test_Firm_compute_total_liquidity_needs},
 { "test for idle",test_idle},
 { "test for Firm_read_policy_announcements",test_Firm_read_policy_announcements},
 { "test for Firm_receive_data",test_Firm_receive_data},
 { "test for idle",test_idle},
 { "test for Firm_send_data_to_Eurostat",test_Firm_send_data_to_Eurostat},
 { "test for idle",test_idle},
 { "test for Firm_send_payments_to_bank",test_Firm_send_payments_to_bank},
 { "test for Firm_planned_production_costs_dummy",test_Firm_planned_production_costs_dummy},
 { "test for Firm_credit_market_dummy",test_Firm_credit_market_dummy},
 { "test for Firm_labour_good_market_dummy",test_Firm_labour_good_market_dummy},
 { "test for idle",test_idle},
 { "test for idle",test_idle},
 { "test for idle",test_idle},
 { "test for Firm_receive_stock_info_dummy",test_Firm_receive_stock_info_dummy},
 { "test for Firm_send_info_dummy",test_Firm_send_info_dummy},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Household[]= {
 { "test for Household_receive_data",test_Household_receive_data},
 { "test for Household_send_data_to_Eurostat",test_Household_send_data_to_Eurostat},
 { "test for Household_labour_good_market_dummy",test_Household_labour_good_market_dummy},
 { "test for Household_financial_market_dummy",test_Household_financial_market_dummy},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_IGFirm[]= {
 { "test for IGFirm_read_policy_announcements",test_IGFirm_read_policy_announcements},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Eurostat[]= {
 { "test for Eurostat_Initialization",test_Eurostat_Initialization},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_read_policy_announcements",test_Eurostat_read_policy_announcements},
 { "test for Eurostat_send_data",test_Eurostat_send_data},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_idle",test_Eurostat_idle},
 { "test for Eurostat_calculate_data",test_Eurostat_calculate_data},
 { "test for Eurostat_compute_data",test_Eurostat_compute_data},
 { "test for Eurostat_send_data_to_government",test_Eurostat_send_data_to_government},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Bank[]= {
 { "test for Bank_decide_credit_conditions",test_Bank_decide_credit_conditions},
 { "test for Bank_give_loan",test_Bank_give_loan},
 { "test for Bank_receive_installment",test_Bank_receive_installment},
 { "test for Bank_account_update_deposits",test_Bank_account_update_deposits},
 { "test for Bank_accounting",test_Bank_accounting},
 { "test for Bank_idle",test_Bank_idle},

CU_TEST_INFO_NULL,
};

static CU_TestInfo tests_Government[]= {
 { "test for Government_idle",test_Government_idle},
 { "test for Government_send_policy_announcements",test_Government_send_policy_announcements},
 { "test for Government_read_tax_payments",test_Government_read_tax_payments},
 { "test for Government_read_subsidy_notifications_transfers_and_unemployment_benefits_dummy",test_Government_read_subsidy_notifications_transfers_and_unemployment_benefits_dummy},
 { "test for Government_monthly_budget_accounting_dummy",test_Government_monthly_budget_accounting_dummy},
 { "test for Government_read_data_from_Eurostat",test_Government_read_data_from_Eurostat},
 { "test for Government_set_policy",test_Government_set_policy},
 { "test for Government_yearly_resetting",test_Government_yearly_resetting},
 { "test for Government_yearly_budget_accounting",test_Government_yearly_budget_accounting},
 { "test for Government_bond_market_dummy",test_Government_bond_market_dummy},

CU_TEST_INFO_NULL,
};


 static CU_SuiteInfo suites[] = {
{ "suite_Firm",  suite_Firm_init, suite_Firm_clean, tests_Firm},
{ "suite_Household",  suite_Household_init, suite_Household_clean, tests_Household},
{ "suite_IGFirm",  suite_IGFirm_init, suite_IGFirm_clean, tests_IGFirm},
{ "suite_Eurostat",  suite_Eurostat_init, suite_Eurostat_clean, tests_Eurostat},
{ "suite_Bank",  suite_Bank_init, suite_Bank_clean, tests_Bank},
{ "suite_Government",  suite_Government_init, suite_Government_clean, tests_Government},

CU_SUITE_INFO_NULL,
};

void AddTests();

void print_example_results(void);
 
