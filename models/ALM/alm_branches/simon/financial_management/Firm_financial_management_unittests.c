#include <CUnit/Basic.h>

#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"

/************Firm Role: Financial Management Role ********************************/

/************ Unit tests ********************************/
/*
 * \fn: void unittest_Firm_compute_income_statement()
 * \brief: Unit tests for: Firm_compute_income_statement
 */
void unittest_Firm_compute_income_statement()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());
	current_xmachine = *p_xmachine;
	
    /***** Variables: Memory pre-conditions **************************/
	DAY_OF_MONTH_TO_ACT=0;
	CUM_REVENUES=100.0;
    EBIT=0.0;
    PAYMENT_ACCOUNT=0.0;
    
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
    Firm_compute_income_statement();
    
    /***** Variables: Memory post-conditions *****/

    CU_ASSERT_DOUBLE_EQUAL(CUM_REVENUES, 100.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(EBIT, 100.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PAYMENT_ACCOUNT, 100.0, 1e-3);

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Firm_compute_payout_policy()
 * \brief: Unit tests for: Firm_compute_payout_policy
 */
void unittest_Firm_compute_payout_policy()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());
	current_xmachine = *p_xmachine;

    /***** Variables: Memory pre-conditions **************************/
	DAY_OF_MONTH_TO_ACT=0;
    CURRENT_SHARE_PRICE=1.0;
    PRODUCTION_COSTS=100.0;
    PAYMENT_ACCOUNT=0.0;
    
    NET_EARNINGS=100.0;
    PREVIOUS_NET_EARNINGS=90.0;
    EARNINGS_PER_SHARE_RATIO=100.0;
    
/*
    LOANS[0].bank_id=1;
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
*/
    reset_debt_item_array(&LOANS);
    add_debt_item(&LOANS, 1, 100.0, 0.01, 0.0, 20.0, 5);
    add_debt_item(&LOANS, 2, 200.0, 0.02, 0.0, 50.0, 4);
//    printf("\n init loan_value: %f\n", LOANS.array[0].loan_value);
//    printf("\n init loan_value: %f\n", LOANS.array[1].loan_value);
    
    PLANNED_TOTAL_INTEREST_PAYMENT=0.0;
    PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
    PLANNED_TOTAL_DIVIDEND_PAYMENT=100.0;
    CURRENT_SHARES_OUTSTANDING=5;

    TOTAL_FINANCIAL_NEEDS=0.0;
    INTERNAL_FINANCIAL_NEEDS=0.0;
    EXTERNAL_FINANCIAL_NEEDS=0.0;

	/***** Messages: pre-conditions **********************************/

    /***** Function evaluation ***************************************/
     Firm_compute_payout_policy();

    /***** Variables: Memory post-conditions *************************/
    
    CU_ASSERT_DOUBLE_EQUAL(CURRENT_SHARE_PRICE, 1.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PRODUCTION_COSTS, 100.0, 1e-3);

    CU_ASSERT_DOUBLE_EQUAL(NET_EARNINGS, 100.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PREVIOUS_NET_EARNINGS, 90.0, 1e-3);

    /*
        loans[0]
        {
            int bank_id=1;
            double loan_value=80.0;
            double interest_rate=0.01;
            double interest_payment=1.0; //this value is updated the next time, at start of function to: interest_payment=0.8;
            double debt_installment_payment=20.0;
            int nr_periods_before_maturity=4;
        }
    */

        CU_ASSERT_EQUAL(LOANS.array[0].bank_id, 1);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].loan_value, 100.0, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].interest_rate, 0.01, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].interest_payment, 1.0, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].debt_installment_payment, 20.0, 1e-3);
        CU_ASSERT_EQUAL(LOANS.array[0].nr_periods_before_maturity, 5);
       
    /*
        loans[1]
        {
            int bank_id=2;
            double loan_value=150.0;
            double interest_rate=0.02;
            double interest_payment=4.0; //this value is updated the next time, at start of function to: interest_payment=0.75;
            double debt_installment_payment=50.0;
            int nr_periods_before_maturity=3;
        }
    */

        CU_ASSERT_EQUAL(LOANS.array[1].bank_id, 2);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].loan_value, 200.0, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].interest_rate, 0.02, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].interest_payment, 4.0, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].debt_installment_payment, 50.0, 1e-3);
        CU_ASSERT_EQUAL(LOANS.array[1].nr_periods_before_maturity, 4);
        
    CU_ASSERT_DOUBLE_EQUAL(PLANNED_TOTAL_INTEREST_PAYMENT, 5.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT, 70.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PLANNED_TOTAL_DIVIDEND_PAYMENT, 100.0*EARNINGS_PER_SHARE_RATIO, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PAYMENT_ACCOUNT, 0.0, 1e-3);
    
    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
    
}

/*
 * \fn: void unittest_Firm_compute_balance_sheet()
 * \brief: Unit tests for: Firm_compute_balance_sheet
 */
void unittest_Firm_compute_balance_sheet()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());
	current_xmachine = *p_xmachine;
	
    /***** Variables: Memory pre-conditions **************************/
	DAY_OF_MONTH_TO_ACT=0;
    CURRENT_SHARES_OUTSTANDING=100;
    PREVIOUS_DIVIDEND_PER_SHARE=1.0;
    CURRENT_DIVIDEND_PER_SHARE=1.0;
    TOTAL_DIVIDEND_PAYMENT=100.0;
    PLANNED_TOTAL_DIVIDEND_PAYMENT=100*85.5/100;
    
    EBIT=100.0;
    PAYMENT_ACCOUNT=100.0;
    EARNINGS=0.0;
    TAX_PAYMENT=0.0;
    TAX_RATE_CORPORATE=0.10;
    NET_EARNINGS=0.0;
    PREVIOUS_NET_EARNINGS=90.0;

    /*
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
*/
    reset_debt_item_array(&LOANS);
    add_debt_item(&LOANS, 1, 100.0, 0.01, 0.0, 20.0, 5);
    add_debt_item(&LOANS, 2, 200.0, 0.02, 0.0, 50.0, 4);

    TOTAL_INTEREST_PAYMENT=0.0;
    TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;

    PLANNED_TOTAL_INTEREST_PAYMENT=5.0;
    PLANNED_TOTAL_DEBT_INSTALLMENT_PAYMENT=70.0;
    
    /*
    VALUE_CAPITAL_STOCK[0].current_value=1000.0;
    VALUE_CAPITAL_STOCK[0].depreciation_value_per_period=100.0;
    VALUE_CAPITAL_STOCK[0].nr_periods_before_total_depreciation=10;

    VALUE_CAPITAL_STOCK[1].current_value=2000.0;
    VALUE_CAPITAL_STOCK[1].depreciation_value_per_period=100.0;
    VALUE_CAPITAL_STOCK[1].nr_periods_before_total_depreciation=20;
*/
    add_capital_stock_item(&VALUE_CAPITAL_STOCK, 1000.0, 100.0, 10);
    add_capital_stock_item(&VALUE_CAPITAL_STOCK, 2000.0, 100.0, 20);
    TOTAL_VALUE_CAPITAL_STOCK=0.0;

    PRICE=1.0;
    add_mall_info(&CURRENT_MALL_STOCKS, 1, 1.0, 50.0, 1000.0);
    TOTAL_VALUE_LOCAL_INVENTORY=0.0;
    PAYMENT_ACCOUNT=100.0;
    TOTAL_ASSETS=0.0;
    
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
    Firm_compute_balance_sheet();

    /***** Variables: Memory post-conditions *************************/
    CU_ASSERT_DOUBLE_EQUAL(EBIT, 100.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(EARNINGS, 95.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(TAX_PAYMENT, 9.5, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(TAX_RATE_CORPORATE, 0.10, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(NET_EARNINGS, 85.5, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PREVIOUS_NET_EARNINGS, 0.0, 1e-3);

/*
    loans[0]
    {
        int bank_id=1;
        double loan_value=80.0;
        double interest_rate=0.01;
        double interest_payment=1.0; //this value is updated the next time, at start of function to: interest_payment=0.8;
        double debt_installment_payment=20.0;
        int nr_periods_before_maturity=4;
    }
*/

    CU_ASSERT_EQUAL(LOANS.array[0].bank_id, 1);
    CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].loan_value, 80.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].interest_rate, 0.01, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].interest_payment, 1.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].debt_installment_payment, 20.0, 1e-3);
    CU_ASSERT_EQUAL(LOANS.array[0].nr_periods_before_maturity, 4);
   
/*
    loans[1]
    {
        int bank_id=2;
        double loan_value=150.0;
        double interest_rate=0.02;
        double interest_payment=4.0; //this value is updated the next time, at start of function to: interest_payment=0.75;
        double debt_installment_payment=50.0;
        int nr_periods_before_maturity=3;
    }
*/

    CU_ASSERT_EQUAL(LOANS.array[1].bank_id, 2);
    CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].loan_value, 150.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].interest_rate, 0.02, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].interest_payment, 4.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].debt_installment_payment, 50.0, 1e-3);
    CU_ASSERT_EQUAL(LOANS.array[1].nr_periods_before_maturity, 3);
    
    CU_ASSERT_DOUBLE_EQUAL(TOTAL_INTEREST_PAYMENT, 5.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(TOTAL_DEBT_INSTALLMENT_PAYMENT, 70.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(TOTAL_DIVIDEND_PAYMENT, 100*85.5/100, 1e-3);
    CU_ASSERT_EQUAL(CURRENT_SHARES_OUTSTANDING, 100);
    CU_ASSERT_DOUBLE_EQUAL(PREVIOUS_DIVIDEND_PER_SHARE, 1.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(CURRENT_DIVIDEND_PER_SHARE, TOTAL_DIVIDEND_PAYMENT/CURRENT_SHARES_OUTSTANDING, 1e-3);

    /*
    value_capital_stock[0]
    {
        double current_value=900;
        double depreciation_value_per_period=100;
        int nr_periods_before_total_depreciation=9;
    }*/

    CU_ASSERT_DOUBLE_EQUAL(VALUE_CAPITAL_STOCK.array[0].current_value, 900.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(VALUE_CAPITAL_STOCK.array[0].depreciation_value_per_period, 100.0, 1e-3);
    CU_ASSERT_EQUAL(VALUE_CAPITAL_STOCK.array[0].nr_periods_before_total_depreciation, 9);

    /*
    value_capital_stock[1]
    {
        double current_value=1900;
        double depreciation_value_per_period=100.0;
        int nr_periods_before_total_depreciation=19;
    }*/

    CU_ASSERT_DOUBLE_EQUAL(VALUE_CAPITAL_STOCK.array[1].current_value, 1900.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(VALUE_CAPITAL_STOCK.array[1].depreciation_value_per_period, 100.0, 1e-3);
    CU_ASSERT_EQUAL(VALUE_CAPITAL_STOCK.array[1].nr_periods_before_total_depreciation, 19);
    CU_ASSERT_DOUBLE_EQUAL(TOTAL_VALUE_CAPITAL_STOCK, 2800.0, 1e-3);

    /*
    current_mall_stocks[0]
    {
    	mall_id=1;
        price=1.0;
        critical_stock=50;
        current_stock=1000;
    }*/

    CU_ASSERT_DOUBLE_EQUAL(CURRENT_MALL_STOCKS.array[0].price, 1.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(CURRENT_MALL_STOCKS.array[0].current_stock, 1000.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(TOTAL_VALUE_LOCAL_INVENTORY, 1000.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PAYMENT_ACCOUNT, -60.5, 1e-3); //payment_account=100+100-10-5-70-5=110;
    CU_ASSERT_DOUBLE_EQUAL(TOTAL_ASSETS, 3739.5, 1e-3);

    /***** Messages: post-conditions **********************************/
    /*
    tax_payment_message(firm_id, gov_id, tax_payment, MSGDATA)
    interest_payment_message(firm_id, bank_id, interest_payment, MSGDATA)
    debt_installment_payment_message(firm_id, bank_id, debt_installment_payment, MSGDATA)
    dividend_payment_message(firm_id, current_dividend_per_share, MSGDATA)
    */

 	START_TAX_PAYMENT_MESSAGE_LOOP 
    	CU_ASSERT_DOUBLE_EQUAL(tax_payment_message->tax_payment, 10.0, 1e-3);
	FINISH_TAX_PAYMENT_MESSAGE_LOOP
 	START_INTEREST_PAYMENT_MESSAGE_LOOP
    	CU_ASSERT_DOUBLE_EQUAL(interest_payment_message->interest_payment, 5.0, 1e-3);
    FINISH_INTEREST_PAYMENT_MESSAGE_LOOP
    START_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
    	CU_ASSERT_DOUBLE_EQUAL(debt_installment_payment_message->debt_installment_payment, 70.0, 1e-3);
    FINISH_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
    START_DIVIDEND_PAYMENT_MESSAGE_LOOP
    	CU_ASSERT_DOUBLE_EQUAL(dividend_payment_message->current_dividend_per_share, 1.0, 1e-3);
    FINISH_DIVIDEND_PAYMENT_MESSAGE_LOOP
    
    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Firm_apply_for_loans()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());
	current_xmachine = *p_xmachine;
	
    /***** Variables: Memory pre-conditions **************************/
	ID=1;
	BANK_ID=2;
	EXTERNAL_FINANCIAL_NEEDS=100.0;
	TOTAL_ASSETS=0.0;
	TOTAL_DEBT=0.0;
    
	/***** Messages: pre-conditions **********************************/
	
    /***** Function evaluation ***************************************/
    Firm_apply_for_loans();
    
    /***** Variables: Memory post-conditions *************************/

    /***** Messages: post-conditions **********************************/
    //add_loan_request_message(firm_id, bank_id, external_financial_needs, total_assets, total_debt, MSGDATA);
 	START_LOAN_REQUEST_MESSAGE_LOOP 
    	CU_ASSERT_EQUAL(loan_request_message->firm_id, 1);
 		CU_ASSERT_EQUAL(loan_request_message->bank_id, 2);
 		CU_ASSERT_DOUBLE_EQUAL(loan_request_message->credit_amount, 100.0, 1e-3);
 		CU_ASSERT_DOUBLE_EQUAL(loan_request_message->total_assets, 0.0, 1e-3);
 		CU_ASSERT_DOUBLE_EQUAL(loan_request_message->total_debt, 0.0, 1e-3);
	FINISH_LOAN_REQUEST_MESSAGE_LOOP

	/************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Firm_read_loan_offers_send_loan_acceptance()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());
	current_xmachine = *p_xmachine;
	
    /***** Variables: Memory pre-conditions **************************/
	ID=1;
	BANK_ID=2;
    
	/***** Messages: pre-conditions **********************************/
    //add_loan_conditions_message(bank_id, firm_id, proposed_interest_rate, amount_credit_offer, MSGDATA);
	add_loan_conditions_message(2, 1, 0.01, 100.0, MSGDATA);
	
    /***** Function evaluation ***************************************/
	Firm_read_loan_offers_send_loan_acceptance();
    
    /***** Variables: Memory post-conditions *************************/

    /***** Messages: post-conditions **********************************/
    //add_loan_acceptance_message(ID, loan_conditions_message->bank_id, loan_conditions_message->amount_credit_offer);
 	START_LOAN_ACCEPTANCE_MESSAGE_LOOP 
    	CU_ASSERT_EQUAL(loan_acceptance_message->firm_id, 1);
 		CU_ASSERT_EQUAL(loan_acceptance_message->bank_id, 2);
 		CU_ASSERT_DOUBLE_EQUAL(loan_acceptance_message->credit_amount_taken, 100.0, 1e-3); 	
	FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP

	/************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Firm_compute_and_send_bond_orders()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());
	current_xmachine = *p_xmachine;
	
	/***** Variables: Memory pre-conditions **************************/
	ID=1;
    
	/***** Messages: pre-conditions **********************************/

    /***** Function evaluation ***************************************/
	Firm_compute_and_send_bond_orders();
    
    /***** Variables: Memory post-conditions *************************/

    /***** Messages: post-conditions *********************************/
 	START_BOND_ORDER_MESSAGE_LOOP 
 		//add_bond_message(ID, bond_id, limit_price, limit_quantity, MSGDATA);
 		CU_ASSERT_EQUAL(bond_order_message->trader_id, 1);
 		CU_ASSERT_EQUAL(bond_order_message->bond_id, 2);
 		CU_ASSERT_DOUBLE_EQUAL(bond_order_message->limit_price, 1.0, 1e-3);
 		CU_ASSERT_DOUBLE_EQUAL(bond_order_message->limit_quantity, 1.0, 1e-3);
	FINISH_BOND_ORDER_MESSAGE_LOOP

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Firm_read_bond_transactions()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());
	current_xmachine = *p_xmachine;
	
	/***** Variables: Memory pre-conditions **************************/
    
	/***** Messages: pre-conditions **********************************/
		
    /***** Function evaluation ***************************************/
	Firm_read_bond_transactions();
    
    /***** Variables: Memory post-conditions *************************/

    /***** Messages: post-conditions *********************************/

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Firm_compute_and_send_stock_orders()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());

	/***** Variables: Memory pre-conditions **************************/
	ID=1;
    
	/***** Messages: pre-conditions **********************************/
	
    /***** Function evaluation ***************************************/
	Firm_compute_and_send_stock_orders();
    
    /***** Variables: Memory post-conditions *************************/

    /***** Messages: post-conditions *********************************/
 	START_STOCK_ORDER_MESSAGE_LOOP 
 		//add_stock_message(ID, stock_id, limit_price, limit_quantity, MSGDATA);
 		CU_ASSERT_EQUAL(stock_order_message->trader_id, 1);
 		CU_ASSERT_EQUAL(stock_order_message->stock_id, 2);
 		CU_ASSERT_DOUBLE_EQUAL(stock_order_message->limit_price, 1.0, 1e-3);
 		CU_ASSERT_DOUBLE_EQUAL(stock_order_message->limit_quantity, 1.0, 1e-3);
	FINISH_STOCK_ORDER_MESSAGE_LOOP

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

void unittest_Firm_read_stock_transactions()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());
	current_xmachine = *p_xmachine;
	
	/***** Variables: Memory pre-conditions **************************/
    
	/***** Messages: pre-conditions **********************************/
	
    /***** Function evaluation ***************************************/
	Firm_read_stock_transactions();
    
    /***** Variables: Memory post-conditions *************************/

	/***** Messages: post-conditions *********************************/
	
    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}


//	void unittest_<function_name>()
//	{
//	    /************* At start of unit test, add one agent **************/
//		add_<Agent_name>_agent_internal(init_<Agent_name>_agent());
//		current_xmachine = *p_xmachine;
//
//		/***** Variables: Memory pre-conditions **************************/
//		<var_name1>=0.0;
//		<var_name2>=0;
//
//      /***** Messages: pre-conditions **********************************/
//		add_<message_name>_message(<msg_var>, MSGDATA);
//
//	    /***** Function evaluation ***************************************/
//		<functionname>();
//	    
//	    /***** Variables: Memory post-conditions *************************/
//		CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//		CU_ASSERT_EQUAL(<var_name2>, <value>);
//		
//     /***** Messages: post-conditions **********************************/
//	 	START_<MSG_NAME>_MESSAGE_LOOP 
//	    	CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
//	 		CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
//		FINISH_<MSG_NAME>_MESSAGE_LOOP
//	
//	    /************* At end of unit test, free the agent **************/
//	    free_agent();
//     /************* At end of unit tests, free all Messages **********/
//	    free_messages();
//	}
