#include <CUnit/Basic.h>

#include "../../header.h"
#include "../../Firm_agent_header.h"
#include "../../my_library_header.h"

/************Firm Role: Financial Management Role ********************************/

/************ Unit tests ********************************/

/*
 * \fn: void unittest_Firm_compute_financial_payments()
 * \brief: Unit test for: Firm_compute_financial_payments.
 * Status: NOT Tested
 */
void unittest_Firm_compute_financial_payments()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Firm_agent();
	
    /***** Variables: Memory pre-conditions **************************/
    /*
    LOANS[0].bank_id =1;
    LOANS[0].loan_value=100.0;
    LOANS[0].interest_rate=0.01;
    LOANS[0].installment_amount=20.0;
    LOANS[0].var_per_installment=0.0;
    LOANS[0].residual_var=0.0;
    LOANS[0].bad_debt=0.0;
    LOANS[0].nr_periods_before_repayment=5;

    LOANS[1].bank_id=2;
    LOANS[1].loan_value=200.0;
    LOANS[1].interest_rate=0.02;
	LOANS[1].installment_amount=50.0;
    LOANS[1].var_per_installment=0.0;
    LOANS[1].residual_var=0.0;
    LOANS[1].bad_debt=0.0;
    LOANS[1].nr_periods_before_repayment=4;
*/
    reset_debt_item_array(&LOANS);
    add_debt_item(&LOANS, 1, 100.0, 0.01, 20.0, 0.0, 0.0, 0.0, 5);
    add_debt_item(&LOANS, 2, 200.0, 0.02, 50.0, 0.0, 0.0, 0.0, 4);

    TOTAL_INTEREST_PAYMENT=0.0;
    TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;
    TOTAL_DEBT=0.0;
    
	/***** Messages: initialize message boards **********************************/

	/***** Messages: pre-conditions **********************************/
    //add_<message>_message();
    	    
    /***** Message: Adding message iterators ***************************************/

    /***** Function evaluation ***************************************/
	Firm_compute_financial_payments();
    
    /***** Variables: Memory post-conditions *****/

        CU_ASSERT_EQUAL(LOANS.array[0].bank_id, 1);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].loan_value, 80.0, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].interest_rate, 0.01, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[0].installment_amount, 20.0, 1e-3);
        CU_ASSERT_EQUAL(LOANS.array[0].nr_periods_before_repayment, 4);

        CU_ASSERT_EQUAL(LOANS.array[1].bank_id, 2);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].loan_value, 150.0, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].interest_rate, 0.02, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(LOANS.array[1].installment_amount, 50.0, 1e-3);
        CU_ASSERT_EQUAL(LOANS.array[1].nr_periods_before_repayment, 3);
        
        CU_ASSERT_DOUBLE_EQUAL(TOTAL_INTEREST_PAYMENT, 5.0, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(TOTAL_DEBT_INSTALLMENT_PAYMENT, 70.0, 1e-3);
        CU_ASSERT_DOUBLE_EQUAL(TOTAL_DEBT, 300.0, 1e-3);

    /***** Messages: Message post-conditions *****/

    /************* At end of unit test, free the agent **************/
	unittest_free_Firm_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}


/*
 * \fn: void unittest1_Firm_bankruptcy_insolvency_procedure()
 * \brief: Unit test for: Firm_bankruptcy_insolvency_procedure.
 * Status: NOT Tested
 */
void unittest1_Firm_bankruptcy_insolvency_procedure()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Firm_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	//constants
	#define DEBT_RESCALING_FACTOR 0.33
	#define TARGET_LEVERAGE_RATIO 1.25
	#define TARGET_LIQUIDITY_RATIO 0.0
		
	//variables
	TOTAL_ASSETS = 120.0;
	TOTAL_DEBT = 150.0;	
	PAYMENT_ACCOUNT = 10.0; //degree of freedom to set this value
	EXTERNAL_FINANCIAL_NEEDS =0.0;
	
	//target_debt: 80
	//write_off_ratio: 70/150
	//target_equity: 40
	//external_needs: 0
	
/*
    LOANS[0].bank_id =1;
    LOANS[0].loan_value=150.0;
    LOANS[0].interest_rate=0.01;
    LOANS[0].installment_amount=50.0;
    LOANS[0].var_per_installment=50.0;
    LOANS[0].residual_var=0.0;
    LOANS[0].bad_debt=0.0;
    LOANS[0].nr_periods_before_repayment=3;
*/
    reset_debt_item_array(&LOANS);
    add_debt_item(&LOANS, 1, 150.0, 0.01, 50.0, 50.0, 150.0, 0.0, 5);
    
	/***** Messages: initialize message boards **********************************/

	/***** Messages: pre-conditions **********************************/
    	    
    /***** Message: Adding message iterators ***************************************/
	//add_bankruptcy_message(bank_id, bad_debt, credit_refunded, residual_var);

	rc = MB_Iterator_Create(b_bankruptcy, &i_bankruptcy);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'bankruptcy'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'bankruptcy' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}

    /***** Function evaluation ***************************************/
	Firm_bankruptcy_insolvency_procedure();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(EXTERNAL_FINANCIAL_NEEDS, 24.0, 1e-3);

    /***** Messages: Message post-conditions *****/

	//Test this:
	//bad_debt = write_off_ratio*LOANS.array[i].loan_value; = (70/150)*150 = 70;
	//credit_refunded = (PAYMENT_ACCOUNT/TOTAL_DEBT)*LOANS.array[i].loan_value; = (10/150)*150=10
	//PAYMENT_ACCOUNT -= credit_refunded;
	//TOTAL_ASSETS -= credit_refunded;

	START_BANKRUPTCY_MESSAGE_LOOP
		CU_ASSERT_EQUAL(bankruptcy_message->bank_id, 1);
		CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->bad_debt, 70.0, 1e-3);     
		CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->credit_refunded, 10.0, 1e-3);
		CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->residual_var, 150.0, 1e-3);
	FINISH_BANKRUPTCY_MESSAGE_LOOP

	CU_ASSERT_DOUBLE_EQUAL(PAYMENT_ACCOUNT, 0.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(TOTAL_ASSETS, 110.0, 1e-3);
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Firm_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest2_Firm_bankruptcy_insolvency_procedure()
 * \brief: Unit test for: Firm_bankruptcy_insolvency_procedure.
 * Status: NOT Tested
 */
void unittest2_Firm_bankruptcy_insolvency_procedure()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Firm_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	//constants
	#define DEBT_RESCALING_FACTOR 0.33
	#define TARGET_LEVERAGE_RATIO 2.0
	#define TARGET_LIQUIDITY_RATIO 0.0
	
	//variables
	TOTAL_ASSETS = 120.0;
	TOTAL_DEBT = 150.0;
	PAYMENT_ACCOUNT = 120.0;
	EXTERNAL_FINANCIAL_NEEDS =0.0;
	
	//target_debt: 80
	//write_off_ratio: 70/150
	//target_equity: 64
	//external_needs: 24
	
/*
    LOANS[0].bank_id =1;
    LOANS[0].loan_value=150.0;
    LOANS[0].interest_rate=0.01;
    LOANS[0].installment_amount=50.0;
    LOANS[0].var_per_installment=50.0;
    LOANS[0].residual_var=0.0;
    LOANS[0].bad_debt=0.0;
    LOANS[0].nr_periods_before_repayment=3;
*/
    reset_debt_item_array(&LOANS);
    add_debt_item(&LOANS, 1, 150.0, 0.01, 50.0, 50.0, 150.0, 0.0, 5);
    
	/***** Messages: initialize message boards **********************************/

	/***** Messages: pre-conditions **********************************/
    	    
    /***** Message: Adding message iterators ***************************************/
	//add_bankruptcy_message(bank_id, bad_debt, credit_refunded, residual_var);

	rc = MB_Iterator_Create(b_bankruptcy, &i_bankruptcy);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'bankruptcy'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'bankruptcy' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}

    /***** Function evaluation ***************************************/
	Firm_bankruptcy_insolvency_procedure();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(EXTERNAL_FINANCIAL_NEEDS, 0.0, 1e-3);

    /***** Messages: Message post-conditions *****/

	//Test this:
	//bad_debt = write_off_ratio*LOANS.array[i].loan_value; = (70/150)*150 = 70;
	//credit_refunded = (PAYMENT_ACCOUNT/TOTAL_DEBT)*LOANS.array[i].loan_value; = (10/150)*150=10
	//PAYMENT_ACCOUNT -= credit_refunded;
	//TOTAL_ASSETS -= credit_refunded;

	START_BANKRUPTCY_MESSAGE_LOOP
		CU_ASSERT_EQUAL(bankruptcy_message->bank_id, 1);
		CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->bad_debt, 70.0, 1e-3);     
		CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->credit_refunded, 10.0, 1e-3);
		CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->residual_var, 150.0, 1e-3);
	FINISH_BANKRUPTCY_MESSAGE_LOOP

	CU_ASSERT_DOUBLE_EQUAL(PAYMENT_ACCOUNT, 0.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(TOTAL_ASSETS, 110.0, 1e-3);

	/************* At end of unit test, free the agent **************/
	unittest_free_Firm_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest3_Firm_bankruptcy_insolvency_procedure()
 * \brief: Unit test for: Firm_bankruptcy_insolvency_procedure.
 * Status: NOT Tested
 */
void unittest3_Firm_bankruptcy_insolvency_procedure()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Firm_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	//constants
	#define DEBT_RESCALING_FACTOR 0.33
	#define TARGET_LEVERAGE_RATIO 4.0
	#define TARGET_LIQUIDITY_RATIO 0.0
	
	//variables
	TOTAL_ASSETS = 120.0;
	TOTAL_DEBT = 150.0;
	PAYMENT_ACCOUNT = 120.0;
	EXTERNAL_FINANCIAL_NEEDS =0.0;
	
	//target_debt: 80
	//write_off_ratio: 70/150
	//target_equity: 40
	//external_needs: 0
	
/*
    LOANS[0].bank_id =1;
    LOANS[0].loan_value=150.0;
    LOANS[0].interest_rate=0.01;
    LOANS[0].installment_amount=50.0;
    LOANS[0].var_per_installment=50.0;
    LOANS[0].residual_var=0.0;
    LOANS[0].bad_debt=0.0;
    LOANS[0].nr_periods_before_repayment=3;
*/
    reset_debt_item_array(&LOANS);
    add_debt_item(&LOANS, 1, 150.0, 0.01, 50.0, 50.0, 150.0, 0.0, 5);
    
	/***** Messages: initialize message boards **********************************/

	/***** Messages: pre-conditions **********************************/
    	    
    /***** Message: Adding message iterators ***************************************/
	//add_bankruptcy_message(bank_id, bad_debt, credit_refunded, residual_var);

	rc = MB_Iterator_Create(b_bankruptcy, &i_bankruptcy);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'bankruptcy'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'bankruptcy' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}

    /***** Function evaluation ***************************************/
	Firm_bankruptcy_insolvency_procedure();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(EXTERNAL_FINANCIAL_NEEDS, 0.0, 1e-3);

    /***** Messages: Message post-conditions *****/

	//Test this:
	//bad_debt = write_off_ratio*LOANS.array[i].loan_value; = (70/150)*150 = 70;
	//credit_refunded = (PAYMENT_ACCOUNT/TOTAL_DEBT)*LOANS.array[i].loan_value; = (10/150)*150=10
	//PAYMENT_ACCOUNT -= credit_refunded;
	//TOTAL_ASSETS -= credit_refunded;

	START_BANKRUPTCY_MESSAGE_LOOP
		CU_ASSERT_EQUAL(bankruptcy_message->bank_id, 1);
		CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->bad_debt, 70.0, 1e-3);     
		CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->credit_refunded, 10.0, 1e-3);
		CU_ASSERT_DOUBLE_EQUAL(bankruptcy_message->residual_var, 150.0, 1e-3);
	FINISH_BANKRUPTCY_MESSAGE_LOOP

	CU_ASSERT_DOUBLE_EQUAL(PAYMENT_ACCOUNT, 0.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(TOTAL_ASSETS, 110.0, 1e-3);

    /************* At end of unit test, free the agent **************/
	unittest_free_Firm_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

