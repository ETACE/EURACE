/**
 * \file  unittest.c
 * \brief Holds main function of the unittest program.
 */

#include "header.h"
#include <CUnit/Basic.h>

void unittest_Household_financial_planning();

void unittest_Household_compute_gross_income();

void unittest_Household_compute_monthly_taxes();

void unittest_Household_compute_net_income();

void unittest_Household_compute_asset_wealth();

void unittest_Household_compute_total_budget();

int init_suite1(void)
{
    initialise_pointers();
    add_node(0, -SPINF, SPINF, -SPINF, SPINF, -SPINF, SPINF);
    current_node = *p_node_info;
    p_xmachine = &current_node->agents;
 p_tax_payment_message = &current_node->tax_payment_messages;
 p_interest_payment_message = &current_node->interest_payment_messages;
 p_debt_installment_payment_message = &current_node->debt_installment_payment_messages;
 p_dividend_payment_message = &current_node->dividend_payment_messages;
 p_credit_request_message = &current_node->credit_request_messages;
 p_credit_offer_message = &current_node->credit_offer_messages;
 p_credit_taken_message = &current_node->credit_taken_messages;
 p_firm_bond_order_message = &current_node->firm_bond_order_messages;
 p_firm_stock_order_message = &current_node->firm_stock_order_messages;
 p_stock_order_message = &current_node->stock_order_messages;
 p_gov_bond_order_message = &current_node->gov_bond_order_messages;
 p_firm_bond_transaction_message = &current_node->firm_bond_transaction_messages;
 p_gov_bond_transaction_message = &current_node->gov_bond_transaction_messages;
 p_firm_stock_transaction_message = &current_node->firm_stock_transaction_messages;
 
    /* Add one agent for each type */
  xmachine_memory_Household * current_Household_agent = init_Household_agent();
  xmachine_memory_Clearinghouse * current_Clearinghouse_agent = init_Clearinghouse_agent();
  xmachine_memory_Firm * current_Firm_agent = init_Firm_agent();
   add_Household_agent_internal(current_Household_agent);
   add_Clearinghouse_agent_internal(current_Clearinghouse_agent);
   add_Firm_agent_internal(current_Firm_agent);
 
    return 0;
}

int clean_suite1(void)
{
    clean_up(0);
    
    return 0;
}

/** \fn int main(int argc, char * argv[])
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char * argv[])
{
    CU_pSuite pSuite = NULL;
    
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    
    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* add the tests to the suite */
    /* add extra tests using || */
    
    if(NULL == CU_add_test(pSuite, "Household_financial_planning", unittest_Household_financial_planning) ||
        NULL == CU_add_test(pSuite, "Household_compute_gross_income", unittest_Household_compute_gross_income) ||
        NULL == CU_add_test(pSuite, "Household_compute_monthly_taxes", unittest_Household_compute_monthly_taxes) ||
        NULL == CU_add_test(pSuite, "Household_compute_net_income", unittest_Household_compute_net_income) ||
        NULL == CU_add_test(pSuite, "Household_compute_total_budget", unittest_Household_compute_total_budget) ||
        NULL == CU_add_test(pSuite, "Household_compute_asset_wealth", unittest_Household_compute_asset_wealth) ||
        NULL == CU_add_test(pSuite, "Household_compute_cash_on_hands", unittest_Household_compute_cash_on_hands) ||
        NULL == CU_add_test(pSuite, "Household_compute_consumption_budget", unittest_Household_compute_consumption_budget) ||
        NULL == CU_add_test(pSuite, "Household_compute_financial_needs_monthly", unittest_Household_compute_financial_needs_monthly) ||
        NULL == CU_add_test(pSuite, "Household_update_asset_portfolio", unittest_Household_update_asset_portfolio) ||
        NULL == CU_add_test(pSuite, "Household_compute_financial_needs_daily", unittest_Household_compute_financial_needs_daily) ||
        NULL == CU_add_test(pSuite, "Household_entry_decision", unittest_Household_entry_decision) ||
        NULL == CU_add_test(pSuite, "Household_compute_asset_budget", unittest_Household_compute_asset_budget) ||
        NULL == CU_add_test(pSuite, "Household_compute_firm_bond_orders", unittest_Household_compute_firm_bond_orders) ||
        NULL == CU_add_test(pSuite, "Household_compute_government_bond_orders", unittest_Household_compute_government_bond_orders) ||
        NULL == CU_add_test(pSuite, "Household_compute_firm_stock_orders", unittest_Household_compute_firm_stock_orders) ||
        NULL == CU_add_test(pSuite, "Household_read_transaction_message", unittest_Household_read_transaction_message) ||
        NULL == CU_add_test(pSuite, "Clearinghouse_read_order_messages", unittest_Clearinghouse_read_order_messages) ||
        NULL == CU_add_test(pSuite, "Clearinghouse_compute_transactions", unittest_Clearinghouse_compute_transactions) ||
        NULL == CU_add_test(pSuite, "Clearinghouse_send_transaction_message", unittest_Clearinghouse_send_transaction_message) ||
        NULL == CU_add_test(pSuite, "Firm_compute_income_statement", unittest_Firm_compute_income_statement) ||
        NULL == CU_add_test(pSuite, "Firm_compute_balance_sheet", unittest_Firm_compute_balance_sheet) ||
        NULL == CU_add_test(pSuite, "Firm_compute_payout_policy", unittest_Firm_compute_payout_policy) ||
        NULL == CU_add_test(pSuite, "Firm_apply_for_credit", unittest_Firm_apply_for_credit) ||
        NULL == CU_add_test(pSuite, "Firm_read_loan_offers_send_loan_acceptance", unittest_Firm_read_loan_offers_send_loan_acceptance) ||
        NULL == CU_add_test(pSuite, "Firm_issue_equity", unittest_Firm_issue_equity) ||
        NULL == CU_add_test(pSuite, "Firm_compute_stock_orders", unittest_Firm_compute_stock_orders) ||
        NULL == CU_add_test(pSuite, "Firm_compute_bond_orders", unittest_Firm_compute_bond_orders) ||
        NULL == CU_add_test(pSuite, "Firm_update_outstanding_shares", unittest_Firm_update_outstanding_shares))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    //if (NULL == CU_add_test(pSuite, "test_next_id", test_next_id) ||
/*  if(NULL == CU_add_test(pSuite, "test_start_new_cycle_postion", test_start_new_cycle_postion) ||
        NULL == CU_add_test(pSuite, "test_g0", test_g0) ||
        NULL == CU_add_test(pSuite, "test_nong0", test_nong0) ||
        NULL == CU_add_test(pSuite, "test_differentiate_stem_z", test_differentiate_stem_z) ||
        NULL == CU_add_test(pSuite, "test_migrate", test_migrate))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }*/
    
    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return CU_get_error();
}
