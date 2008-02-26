#include <CUnit/Basic.h>

#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"

/************Firm Role: Financial Management Role ********************************/

/************ Unit tests ********************************/

/*
 * \fn: void unittest_Firm_compute_payout_policy()
 * \brief: Unit tests for: Firm_compute_payout_policy
 */
void unittest_Firm_compute_payout_policy()
{
    /***** Variables: Memory pre-conditions *****/
    
    CURRENT_SHARE_PRICE=1.0;
    PRODUCTION_COSTS=100.0;

    NET_EARNINGS=100.0;
    PREVIOUS_NET_EARNINGS=90.0;

    LOANS[0].bank_id =1;
    LOANS[0].loan_value=100.0;
    LOANS[0].interest_rate=0.01;
    LOANS[0].interest_payment=0.0;
    LOANS[0].debt_installment_payment=20.0;
    LOANS[0].nr_periods_before_maturity=5;

    LOANS[1].bank_id=2;
    LOANS[1].loan_value=200.0;
    LOANS[1].interest_rate=0.02;
    LOANS[1].interest_payment=0.0;
    LOANS[1].debt_installment_payment=50.0;
    LOANS[1].nr_periods_before_maturity=4;

    PLANNED_TOTAL_INTEREST_PAYMENT=0.0;
    PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
    PLANNED_TOTAL_DIVIDEND_PAYMENT=0.0;

    CURRENT_SHARES_OUTSTANDING=5;
    PREVIOUS_DIVIDEND_PER_SHARE=1.0;
    CURRENT_DIVIDEND_PER_SHARE=0.0;
    PREVIOUS_DIVIDEND_PER_EARNINGS=0.045;
    CURRENT_DIVIDEND_PER_EARNINGS=0.0;

    EARNINGS_PER_SHARE_RATIO=0.0;
    DEBT_EARNINGS_RATIO=0.0;
    PRICE_EARNINGS_RATIO=0.0;
    RETAINED_EARNINGS_RATIO=0.0;
    EARNINGS_PER_SHARE_RATIO_GROWTH=0.0;
    CRITICAL_PRICE_EARNINGS_RATIO=0.0;
    CRITICAL_EARNINGS_PER_SHARE_RATIO=0.0;

    TOTAL_FINANCIAL_NEEDS=0.0;
    INTERNAL_FINANCIAL_NEEDS=0.0;
    EXTERNAL_FINANCIAL_NEEDS=0.0;


     /***** Function evaluation *****/
     Firm_compute_payout_policy();


    /***** Variables: Memory post-conditions *****/
    
    CU_ASSERT_EQUAL(CURRENT_SHARE_PRICE, 1.0);
    CU_ASSERT_EQUAL(PRODUCTION_COSTS, 100.0);

    CU_ASSERT_EQUAL(NET_EARNINGS, 100.0);
    CU_ASSERT_EQUAL(PREVIOUS_NET_EARNINGS, 90.0);

    CU_ASSERT_EQUAL(LOANS[0].bank_id , 1);
    CU_ASSERT_EQUAL(LOANS[0].loan_value, 100.0);
    CU_ASSERT_EQUAL(LOANS[0].interest_rate, 0.01);
    CU_ASSERT_EQUAL(LOANS[0].interest_payment, 0.0);
    CU_ASSERT_EQUAL(LOANS[0].debt_installment_payment, 20.0);
    CU_ASSERT_EQUAL(LOANS[0].nr_periods_before_maturity, 5);

    CU_ASSERT_EQUAL(LOANS[1].bank_id, 2);
    CU_ASSERT_EQUAL(LOANS[1].loan_value, 200.0);
    CU_ASSERT_EQUAL(LOANS[1].interest_rate, 0.02);
    CU_ASSERT_EQUAL(LOANS[1].interest_payment, 0.0);
    CU_ASSERT_EQUAL(LOANS[1].debt_installment_payment, 50.0);
    CU_ASSERT_EQUAL(LOANS[1].nr_periods_before_maturity, 4);

    CU_ASSERT_EQUAL(PLANNED_TOTAL_INTEREST_PAYMENT, 5.0);
    CU_ASSERT_EQUAL(PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT, 70.0);
    CU_ASSERT_EQUAL(PLANNED_TOTAL_DIVIDEND_PAYMENT, 5.0);

    CU_ASSERT_EQUAL(CURRENT_SHARES_OUTSTANDING, 5);
    CU_ASSERT_EQUAL(PREVIOUS_DIVIDEND_PER_SHARE, 1.0);
    CU_ASSERT_EQUAL(CURRENT_DIVIDEND_PER_SHARE, 1.0);
    CU_ASSERT_EQUAL(PREVIOUS_DIVIDEND_PER_EARNINGS, 0.045);
    CU_ASSERT_EQUAL(CURRENT_DIVIDEND_PER_EARNINGS, 0.050);

    CU_ASSERT_EQUAL(EARNINGS_PER_SHARE_RATIO, 20.0);
    CU_ASSERT_EQUAL(DEBT_EARNINGS_RATIO, 2.3);
    CU_ASSERT_EQUAL(PRICE_EARNINGS_RATIO, 0.01);
    CU_ASSERT_EQUAL(RETAINED_EARNINGS_RATIO, PRODUCTION_COSTS/NET_EARNINGS);
    CU_ASSERT_EQUAL(EARNINGS_PER_SHARE_RATIO_GROWTH, 1.11);
    CU_ASSERT_EQUAL(CRITICAL_PRICE_EARNINGS_RATIO, 0.0);
    CU_ASSERT_EQUAL(CRITICAL_EARNINGS_PER_SHARE_RATIO, 0.0);

    CU_ASSERT_EQUAL(TOTAL_FINANCIAL_NEEDS, 177.0);
    CU_ASSERT_EQUAL(INTERNAL_FINANCIAL_NEEDS, 100.0);
    CU_ASSERT_EQUAL(EXTERNAL_FINANCIAL_NEEDS, 77.0);  
}

/*
 * \fn: void unittest_Firm_compute_income_statement()
 * \brief: Unit tests for: Firm_compute_income_statement
 */
void unittest_Firm_compute_income_statement()
{
    /***** Variables: Memory pre-conditions *****/
    CUM_REVENUE=100;
    EBIT=0;
    PAYMENT_ACCOUNT=0;
    
    /***** Function evaluation *****/
    Firm_compute_income_statement();
    
    /***** Variables: Memory out *****/
    CU_ASSERT_EQUAL(CUM_REVENUE, 100);
    CU_ASSERT_EQUAL(EBIT, 100);
    CU_ASSERT_EQUAL(PAYMENT_ACCOUNT, 100);
}

/*
 * \fn: void unittest_Firm_compute_balance_sheet()
 * \brief: Unit tests for: Firm_compute_balance_sheet
 */
void unittest_Firm_compute_balance_sheet()
{
    /***** Variables: Memory pre-conditions *****/
    
    CURRENT_SHARES_OUTSTANDING=5;
    PREVIOUS_DIVIDEND_PER_SHARE=1.0;
    CURRENT_DIVIDEND_PER_SHARE=0.0;

    EBIT=100.0;
    PAYMENT_ACCOUNT=100.0;
    EARNINGS=0.0;
    TAX_PAYMENT=0.0;
    TAX_RATE_CORPORATE=0.10;
    NET_EARNINGS=0.0;
    PREVIOUS_NET_EARNINGS=90.0;

    LOANS[0].bank_id =1;
    LOANS[0].loan_value=100.0;
    LOANS[0].interest_rate=0.01;
    LOANS[0].interest_payment=0.0;
    LOANS[0].debt_installment_payment=20.0;
    LOANS[0].nr_periods_before_maturity=5;

    LOANS[1].bank_id=2;
    LOANS[1].loan_value=200.0;
    LOANS[1].interest_rate=0.02;
    LOANS[1].interest_payment=0.0;
    LOANS[1].debt_installment_payment=50.0;
    LOANS[1].nr_periods_before_maturity=4;

    TOTAL_INTEREST_PAYMENT=0.0;
    TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
    TOTAL_DIVIDEND_PAYMENT=0.0;

    VALUE_CAPITAL_STOCK[0].current_value=1000.0;
    VALUE_CAPITAL_STOCK[0].depreciation_value_per_period=100.0;
    VALUE_CAPITAL_STOCK[0].nr_periods_before_total_depreciation=10;

    VALUE_CAPITAL_STOCK[1].current_value=2000.0;
    VALUE_CAPITAL_STOCK[1].depreciation_value_per_period=100.0;
    VALUE_CAPITAL_STOCK[1].nr_periods_before_total_depreciation=20;

    TOTAL_VALUE_CAPITAL_STOCK=0.0;
    TOTAL_VALUE_LOCAL_INVENTORY=1000;
    EQUITY=0.0;


    /***** Function evaluation *****/
    Firm_compute_balance_sheet();


    /***** Variables: Memory post-conditions *****/
    
    CU_ASSERT_EQUAL(EBIT, 100.0);
    CU_ASSERT_EQUAL(EARNINGS, 100.0);
    CU_ASSERT_EQUAL(TAX_PAYMENT, 10.0);
    CU_ASSERT_EQUAL(TAX_RATE_CORPORATE, 0.10);
    CU_ASSERT_EQUAL(NET_EARNINGS, 90.0);
    CU_ASSERT_EQUAL(PREVIOUS_NET_EARNINGS, 90.0);

    /*
    loans[0]
    {
        int bank_id=1;
        double loan_value=80.0;
        double interest_rate=0.01;
        double interest_payment=1.0; //this value is updated the next time, at start of function to: interest_payment=0.8;
        double debt_installment_payment=20.0;
        int nr_periods_before_maturity=4;
    }*/

    CU_ASSERT_EQUAL(LOANS[0].bank_id, 1);
    CU_ASSERT_EQUAL(LOANS[0].loan_value, 80.0);
    CU_ASSERT_EQUAL(LOANS[0].interest_rate, 0.01);
    CU_ASSERT_EQUAL(LOANS[0].interest_payment, 1.0);
    CU_ASSERT_EQUAL(LOANS[0].debt_installment_payment, 20.0);
    CU_ASSERT_EQUAL(LOANS[0].nr_periods_before_maturity, 4);

    /*
    loans[1]
    {
        int bank_id=2;
        double loan_value=150.0;
        double interest_rate=0.02;
        double interest_payment=4.0; //this value is updated the next time, at start of function to: interest_payment=0.75;
        double debt_installment_payment=50.0;
        int nr_periods_before_maturity=3;
    }*/

    CU_ASSERT_EQUAL(LOANS[1].bank_id, 2);
    CU_ASSERT_EQUAL(LOANS[1].loan_value, 150.0);
    CU_ASSERT_EQUAL(LOANS[1].interest_rate, 0.02);
    CU_ASSERT_EQUAL(LOANS[1].interest_payment, 4.0);
    CU_ASSERT_EQUAL(LOANS[1].debt_installment_payment, 50);
    CU_ASSERT_EQUAL(LOANS[1].nr_periods_before_maturity, 3.0);

    CU_ASSERT_EQUAL(TOTAL_INTEREST_PAYMENT, 5.0);
    CU_ASSERT_EQUAL(TOTAL_DEBT_INSTALLMENT_PAYMENT, 70.0);
    CU_ASSERT_EQUAL(TOTAL_DIVIDEND_PAYMENT, 5.0);

    CU_ASSERT_EQUAL(CURRENT_SHARES_OUTSTANDING, 5);
    CU_ASSERT_EQUAL(PREVIOUS_DIVIDEND_PER_SHARE, 1.0);
    CU_ASSERT_EQUAL(CURRENT_DIVIDEND_PER_SHARE, 1.0);

    /*
    value_capital_stock[0]
    {
        double current_value=900;
        double depreciation_value_per_period=100;
        int nr_periods_before_total_depreciation=9;
    }*/

    CU_ASSERT_EQUAL(VALUE_CAPITAL_STOCK[0].current_value, 900.0);
    CU_ASSERT_EQUAL(VALUE_CAPITAL_STOCK[0].depreciation_value_per_period, 100.0);
    CU_ASSERT_EQUAL(VALUE_CAPITAL_STOCK[0].nr_periods_before_total_depreciation, 9);

    /*
    value_capital_stock[1]
    {
        double current_value=1900;
        double depreciation_value_per_period=100.0;
        int nr_periods_before_total_depreciation=19;
    }*/

    CU_ASSERT_EQUAL(VALUE_CAPITAL_STOCK[1].current_value, 1900.0);
    CU_ASSERT_EQUAL(VALUE_CAPITAL_STOCK[1].depreciation_value_per_period, 100.0);
    CU_ASSERT_EQUAL(VALUE_CAPITAL_STOCK[1].nr_periods_before_total_depreciation, 19);

    CU_ASSERT_EQUAL(TOTAL_VALUE_CAPITAL_STOCK, 3000.0);

    /*
    current_mall_stocks[0]
    {
        price=1.0;
        current_stock=1000;
    }*/

    CU_ASSERT_EQUAL(CURRENT_MALL_STOCKS[0].price, 1.0);
    CU_ASSERT_EQUAL(CURRENT_MALL_STOCKS[0].current_stock, 1000);

    CU_ASSERT_EQUAL(TOTAL_VALUE_LOCAL_INVENTORY, 1000.0);

    CU_ASSERT_EQUAL(PAYMENT_ACCOUNT, 10.0); //payment_account=100-10-5-70-5=10;
    CU_ASSERT_EQUAL(EQUITY, 4010.0);

    /***** Messages send *****/

    /*
    tax_payment_message(firm_id, gov_id, tax_payment, MSGDATA)
    interest_payment_message(firm_id, bank_id, interest_payment, MSGDATA)
    debt_installment_payment_message(firm_id, bank_id, debt_installment_payment, MSGDATA)
    dividend_payment_message(firm_id, current_dividend_per_share, MSGDATA)
    */

    CU_ASSERT_EQUAL(tax_payment_message->tax_payment, 10.0);
    CU_ASSERT_EQUAL(interest_payment_message->interest_payment, 5.0);
    CU_ASSERT_EQUAL(debt_installment_payment_message->debt_installment_payment, 70.0);
    CU_ASSERT_EQUAL(dividend_payment_message->current_dividend_per_share, 1.0);
    
}

void unittest_Firm_apply_for_credit(){};
void unittest_Firm_issue_equity(){};
void unittest_Firm_read_loan_offers_send_loan_acceptance(){};
void unittest_Firm_update_outstanding_shares(){};
void unittest_Firm_compute_bond_orders(){};
void unittest_Firm_compute_stock_orders(){};
