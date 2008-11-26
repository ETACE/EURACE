/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"

void free_messages()
{
	int rc;
	
	
	    rc = MB_Clear(b_bank_account_update);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'bank_account_update' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'bank_account_update' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bank_account_update' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_loan_request);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'loan_request' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'loan_request' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_request' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_loan_conditions);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'loan_conditions' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'loan_conditions' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_conditions' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_loan_acceptance);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'loan_acceptance' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'loan_acceptance' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'loan_acceptance' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_installment);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'installment' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'installment' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'installment' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_bankruptcy);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'bankruptcy' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'bankruptcy' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_BCE_return);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'BCE_return' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'BCE_return' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'BCE_return' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_tax_payment);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'tax_payment' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'tax_payment' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'tax_payment' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_dividend_per_share);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'dividend_per_share' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'dividend_per_share' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'dividend_per_share' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_current_mall_stock_info);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'current_mall_stock_info' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_order);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'order' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'order' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'order' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_order_status);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'order_status' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'order_status' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'order_status' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
}



/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
	int rc;
    //temp_xmachine = NULL;
	//p_xmachine = &temp_xmachine;
	//temp_xmachine_Firm_Start_Firm_Labour_Role = NULL;
	Firm_Start_Firm_Labour_Role_state = init_Firm_state();//&temp_xmachine_Firm_Start_Firm_Labour_Role;
	//temp_xmachine_Firm_Firm_financial_crisis_ok = NULL;
	Firm_Firm_financial_crisis_ok_state = init_Firm_state();//&temp_xmachine_Firm_Firm_financial_crisis_ok;
	//temp_xmachine_Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis = NULL;
	Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state = init_Firm_state();//&temp_xmachine_Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis;
	//temp_xmachine_Firm_end_Firm_cycle = NULL;
	Firm_end_Firm_cycle_state = init_Firm_state();//&temp_xmachine_Firm_end_Firm_cycle;
	//temp_xmachine_Firm_end_Firm_dies = NULL;
	Firm_end_Firm_dies_state = init_Firm_state();//&temp_xmachine_Firm_end_Firm_dies;
	//temp_xmachine_Firm_0003 = NULL;
	Firm_0003_state = init_Firm_state();//&temp_xmachine_Firm_0003;
	//temp_xmachine_Firm_02 = NULL;
	Firm_02_state = init_Firm_state();//&temp_xmachine_Firm_02;
	//temp_xmachine_Firm_Firm_bankruptcy_checked = NULL;
	Firm_Firm_bankruptcy_checked_state = init_Firm_state();//&temp_xmachine_Firm_Firm_bankruptcy_checked;
	//temp_xmachine_Firm_End_Firm_Financial_Role = NULL;
	Firm_End_Firm_Financial_Role_state = init_Firm_state();//&temp_xmachine_Firm_End_Firm_Financial_Role;
	//temp_xmachine_Firm_004 = NULL;
	Firm_004_state = init_Firm_state();//&temp_xmachine_Firm_004;
	//temp_xmachine_Firm_003 = NULL;
	Firm_003_state = init_Firm_state();//&temp_xmachine_Firm_003;
	//temp_xmachine_Firm_002 = NULL;
	Firm_002_state = init_Firm_state();//&temp_xmachine_Firm_002;
	//temp_xmachine_Firm_001 = NULL;
	Firm_001_state = init_Firm_state();//&temp_xmachine_Firm_001;
	//temp_xmachine_Firm_f1 = NULL;
	Firm_f1_state = init_Firm_state();//&temp_xmachine_Firm_f1;
	//temp_xmachine_Firm_Firm_End_Credit_Role = NULL;
	Firm_Firm_End_Credit_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_End_Credit_Role;
	//temp_xmachine_Firm_Firm_Credit_02 = NULL;
	Firm_Firm_Credit_02_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Credit_02;
	//temp_xmachine_Firm_Start_Firm_Credit_Role = NULL;
	Firm_Start_Firm_Credit_Role_state = init_Firm_state();//&temp_xmachine_Firm_Start_Firm_Credit_Role;
	//temp_xmachine_Bank_end_Bank_cycle = NULL;
	Bank_end_Bank_cycle_state = init_Bank_state();//&temp_xmachine_Bank_end_Bank_cycle;
	//temp_xmachine_Bank_Bank_05 = NULL;
	Bank_Bank_05_state = init_Bank_state();//&temp_xmachine_Bank_Bank_05;
	//temp_xmachine_Bank_Bank_04 = NULL;
	Bank_Bank_04_state = init_Bank_state();//&temp_xmachine_Bank_Bank_04;
	//temp_xmachine_Bank_Bank_03 = NULL;
	Bank_Bank_03_state = init_Bank_state();//&temp_xmachine_Bank_Bank_03;
	//temp_xmachine_Bank_Bank_02 = NULL;
	Bank_Bank_02_state = init_Bank_state();//&temp_xmachine_Bank_Bank_02;
	//temp_xmachine_Bank_Bank_start_credit_market_role = NULL;
	Bank_Bank_start_credit_market_role_state = init_Bank_state();//&temp_xmachine_Bank_Bank_start_credit_market_role;
	//temp_xmachine_Dummy_003 = NULL;
	Dummy_003_state = init_Dummy_state();//&temp_xmachine_Dummy_003;
	//temp_xmachine_Dummy_002 = NULL;
	Dummy_002_state = init_Dummy_state();//&temp_xmachine_Dummy_002;
	//temp_xmachine_Dummy_001 = NULL;
	Dummy_001_state = init_Dummy_state();//&temp_xmachine_Dummy_001;


	    rc = MB_Create(&b_bank_account_update, sizeof(m_bank_account_update));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'bank_account_update' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_loan_request, sizeof(m_loan_request));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'loan_request' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_loan_conditions, sizeof(m_loan_conditions));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'loan_conditions' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_loan_acceptance, sizeof(m_loan_acceptance));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'loan_acceptance' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_installment, sizeof(m_installment));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'installment' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_bankruptcy, sizeof(m_bankruptcy));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'bankruptcy' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_BCE_return, sizeof(m_BCE_return));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'BCE_return' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_tax_payment, sizeof(m_tax_payment));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'tax_payment' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_dividend_per_share, sizeof(m_dividend_per_share));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'dividend_per_share' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_current_mall_stock_info, sizeof(m_current_mall_stock_info));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'current_mall_stock_info' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_order, sizeof(m_order));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'order' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Create(&b_order_status, sizeof(m_order_status));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'order_status' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }
	       
	       
       	   exit(rc);
	    }
	    #endif
	
	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/** \fn void initialise_unit_testing()
 * \brief Initialises framework for unit testing.
 */
void initialise_unit_testing()
{
	int rc;
	
	rc = MB_Env_Init();
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Failed to initialise Message Board environment\n");
	   switch(rc) {
	       case MB_ERR_MPI:
	           fprintf(stderr, "\t reason: MPI library not initialised\n");
	           break;
	       case MB_ERR_MEMALLOC:
	           fprintf(stderr, "\t reason: out of memory\n");
	           break;
	       default:
               fprintf(stderr, "\t MB_Env_Init returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
	   
	}
	#endif
	
	initialise_pointers();
}

/* add_location */
/** \fn void add_location(double point, location ** p_location)
 * \brief Adds a location in order into the location list.
 * \param point Position of an agent.
 * \param p_location Pointer Pointer to the location list.
 */
void add_location(double point, location ** p_location)
{
	location * current = *p_location;
	location * tmp = NULL;
	location * newlocation = NULL;
	int found = 0;
	
	while(found == 0)
	{
		if(current == NULL) found = 1;
		else if(point > current->point) found = 1;
		else
		{
			tmp = current;
			current = current->next;
		}
	}
	
	newlocation = (location *)malloc(sizeof(location));
	CHECK_POINTER(newlocation);	
	if(tmp)
	{
		tmp->next = newlocation;
	}
	else
	{
		*p_location = newlocation;
	}
	
	newlocation->next = current;
	newlocation->point = point;
}

/* freelocations */
/** \fn void freelocations(location ** p_location)
 * \brief Free locations from the location list.
 * \param p_location Pointer Pointer to the location list.
 */
void freelocations(location ** p_location)
{
	location * head = *p_location;
	location * tmp = NULL;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_location = NULL;
}

void init_int_static_array(int * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) array[i] = 0;
}

void init_float_static_array(float * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_double_static_array(double* array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_char_static_array(char * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) array[i] = '\0';
}



void init_residual_var_datatype(residual_var_datatype * temp)
{
	init_double_static_array((*temp).value, 10);

}

void init_residual_var_datatype_static_array(residual_var_datatype * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_residual_var_datatype(&array[i]);
}

void free_residual_var_datatype(residual_var_datatype * temp)
{

}

void free_residual_var_datatype_static_array(residual_var_datatype * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_residual_var_datatype(&array[i]);
}

void copy_residual_var_datatype(residual_var_datatype * from, residual_var_datatype * to)
{
	memcpy((*to).value, (*from).value, 10*sizeof(double));
}

void copy_residual_var_datatype_static_array(residual_var_datatype * from, residual_var_datatype * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_residual_var_datatype(&from[i], &to[i]);
	}
}


void init_debt_item(debt_item * temp)
{
	(*temp).bank_id = 0;
	(*temp).loan_value = 0.0;
	(*temp).interest_rate = 0.0;
	(*temp).installment_amount = 0.0;
	(*temp).var_per_installment = 0.0;
	(*temp).residual_var = 0.0;
	(*temp).bad_debt = 0.0;
	(*temp).nr_periods_before_repayment = 0;

}

void init_debt_item_static_array(debt_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_debt_item(&array[i]);
}

void free_debt_item(debt_item * temp)
{

}

void free_debt_item_static_array(debt_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_debt_item(&array[i]);
}

void copy_debt_item(debt_item * from, debt_item * to)
{
	(*to).bank_id = (*from).bank_id;
	(*to).loan_value = (*from).loan_value;
	(*to).interest_rate = (*from).interest_rate;
	(*to).installment_amount = (*from).installment_amount;
	(*to).var_per_installment = (*from).var_per_installment;
	(*to).residual_var = (*from).residual_var;
	(*to).bad_debt = (*from).bad_debt;
	(*to).nr_periods_before_repayment = (*from).nr_periods_before_repayment;
}

void copy_debt_item_static_array(debt_item * from, debt_item * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_debt_item(&from[i], &to[i]);
	}
}


void init_capital_stock_item(capital_stock_item * temp)
{
	(*temp).units = 0.0;
	(*temp).purchase_price = 0.0;
	(*temp).productivity = 0.0;
	(*temp).depreciation_units_per_period = 0.0;

}

void init_capital_stock_item_static_array(capital_stock_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_capital_stock_item(&array[i]);
}

void free_capital_stock_item(capital_stock_item * temp)
{

}

void free_capital_stock_item_static_array(capital_stock_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_capital_stock_item(&array[i]);
}

void copy_capital_stock_item(capital_stock_item * from, capital_stock_item * to)
{
	(*to).units = (*from).units;
	(*to).purchase_price = (*from).purchase_price;
	(*to).productivity = (*from).productivity;
	(*to).depreciation_units_per_period = (*from).depreciation_units_per_period;
}

void copy_capital_stock_item_static_array(capital_stock_item * from, capital_stock_item * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_capital_stock_item(&from[i], &to[i]);
	}
}


void init_mall_info(mall_info * temp)
{
	(*temp).mall_id = 0;
	(*temp).critical_stock = 0.0;
	(*temp).current_stock = 0.0;

}

void init_mall_info_static_array(mall_info * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_mall_info(&array[i]);
}

void free_mall_info(mall_info * temp)
{

}

void free_mall_info_static_array(mall_info * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_mall_info(&array[i]);
}

void copy_mall_info(mall_info * from, mall_info * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).critical_stock = (*from).critical_stock;
	(*to).current_stock = (*from).current_stock;
}

void copy_mall_info_static_array(mall_info * from, mall_info * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_mall_info(&from[i], &to[i]);
	}
}



xmachine_memory_Firm_state * init_Firm_state()
{
	xmachine_memory_Firm_state * current = (xmachine_memory_Firm_state *)malloc(sizeof(xmachine_memory_Firm_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Firm * init_Firm_agent()
{
	xmachine_memory_Firm * current = (xmachine_memory_Firm *)malloc(sizeof(xmachine_memory_Firm));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	current->gov_id = 0;
	current->day_of_month_to_act = 0;
	current->payment_account = 0.0;
	current->bank_id = 0;
	init_int_static_array(current->dmarketmatrix, 10);
	init_residual_var_datatype_static_array(current->residual_var, 10);
	current->ebit = 0.0;
	current->earnings = 0.0;
	current->tax_rate_corporate = 0.0;
	current->tax_rate_vat = 0.0;
	current->tax_payment = 0.0;
	current->net_earnings = 0.0;
	current->previous_net_earnings = 0.0;
	current->earnings_per_share = 0.0;
	current->cum_total_sold_quantity = 0.0;
	current->cum_revenue = 0.0;
	current->production_costs = 0.0;
	current->current_shares_outstanding = 0;
	current->total_payments = 0.0;
	init_mall_info_array(&current->current_mall_stocks);
	current->price = 0.0;
	current->total_interest_payment = 0.0;
	current->total_debt_installment_payment = 0.0;
	current->total_dividend_payment = 0.0;
	current->current_share_price = 0.0;
	current->previous_dividend_per_share = 0.0;
	current->current_dividend_per_share = 0.0;
	current->previous_earnings_per_share = 0.0;
	current->current_earnings_per_share = 0.0;
	current->previous_dividend_per_earnings = 0.0;
	current->current_dividend_per_earnings = 0.0;
	current->debt_earnings_ratio = 0.0;
	current->debt_equity_ratio = 0.0;
	current->price_earnings_ratio = 0.0;
	current->retained_earnings_ratio = 0.0;
	current->earnings_per_share_ratio_growth = 0.0;
	current->critical_price_earnings_ratio = 0.0;
	current->critical_earnings_per_share_ratio = 0.0;
	init_debt_item_array(&current->loans);
	current->total_debt = 0.0;
	current->total_value_local_inventory = 0.0;
	init_capital_stock_item_array(&current->capital_stock);
	current->total_units_capital_stock = 0.0;
	current->total_value_capital_stock = 0.0;
	current->total_capital_depreciation_value = 0.0;
	current->total_capital_depreciation_units = 0.0;
	current->total_assets = 0.0;
	current->equity = 0.0;
	current->production_liquidity_needs = 0.0;
	current->financial_liquidity_needs = 0.0;
	current->total_financial_needs = 0.0;
	current->external_financial_needs = 0.0;
	current->bankruptcy_state = 0;
	current->financial_crisis_state = 0;
	
	return current;
}

void free_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_residual_var_datatype_static_array(tmp->agent->residual_var, 10);
	free_mall_info_array(&tmp->agent->current_mall_stocks);
	free_debt_item_array(&tmp->agent->loans);
	free_capital_stock_item_array(&tmp->agent->capital_stock);
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Firm_agent()
{
	current_xmachine_Firm = (xmachine_memory_Firm *)malloc(sizeof(xmachine_memory_Firm));
	CHECK_POINTER(current);
	
		current_xmachine_Firm->id = 0;
		current_xmachine_Firm->region_id = 0;
		current_xmachine_Firm->gov_id = 0;
		current_xmachine_Firm->day_of_month_to_act = 0;
		current_xmachine_Firm->payment_account = 0.0;
		current_xmachine_Firm->bank_id = 0;
		init_int_static_array(current_xmachine_Firm->dmarketmatrix, 10);
		init_residual_var_datatype_static_array(current_xmachine_Firm->residual_var, 10);
		current_xmachine_Firm->ebit = 0.0;
		current_xmachine_Firm->earnings = 0.0;
		current_xmachine_Firm->tax_rate_corporate = 0.0;
		current_xmachine_Firm->tax_rate_vat = 0.0;
		current_xmachine_Firm->tax_payment = 0.0;
		current_xmachine_Firm->net_earnings = 0.0;
		current_xmachine_Firm->previous_net_earnings = 0.0;
		current_xmachine_Firm->earnings_per_share = 0.0;
		current_xmachine_Firm->cum_total_sold_quantity = 0.0;
		current_xmachine_Firm->cum_revenue = 0.0;
		current_xmachine_Firm->production_costs = 0.0;
		current_xmachine_Firm->current_shares_outstanding = 0;
		current_xmachine_Firm->total_payments = 0.0;
		init_mall_info_array(&current_xmachine_Firm->current_mall_stocks);
		current_xmachine_Firm->price = 0.0;
		current_xmachine_Firm->total_interest_payment = 0.0;
		current_xmachine_Firm->total_debt_installment_payment = 0.0;
		current_xmachine_Firm->total_dividend_payment = 0.0;
		current_xmachine_Firm->current_share_price = 0.0;
		current_xmachine_Firm->previous_dividend_per_share = 0.0;
		current_xmachine_Firm->current_dividend_per_share = 0.0;
		current_xmachine_Firm->previous_earnings_per_share = 0.0;
		current_xmachine_Firm->current_earnings_per_share = 0.0;
		current_xmachine_Firm->previous_dividend_per_earnings = 0.0;
		current_xmachine_Firm->current_dividend_per_earnings = 0.0;
		current_xmachine_Firm->debt_earnings_ratio = 0.0;
		current_xmachine_Firm->debt_equity_ratio = 0.0;
		current_xmachine_Firm->price_earnings_ratio = 0.0;
		current_xmachine_Firm->retained_earnings_ratio = 0.0;
		current_xmachine_Firm->earnings_per_share_ratio_growth = 0.0;
		current_xmachine_Firm->critical_price_earnings_ratio = 0.0;
		current_xmachine_Firm->critical_earnings_per_share_ratio = 0.0;
		init_debt_item_array(&current_xmachine_Firm->loans);
		current_xmachine_Firm->total_debt = 0.0;
		current_xmachine_Firm->total_value_local_inventory = 0.0;
		init_capital_stock_item_array(&current_xmachine_Firm->capital_stock);
		current_xmachine_Firm->total_units_capital_stock = 0.0;
		current_xmachine_Firm->total_value_capital_stock = 0.0;
		current_xmachine_Firm->total_capital_depreciation_value = 0.0;
		current_xmachine_Firm->total_capital_depreciation_units = 0.0;
		current_xmachine_Firm->total_assets = 0.0;
		current_xmachine_Firm->equity = 0.0;
		current_xmachine_Firm->production_liquidity_needs = 0.0;
		current_xmachine_Firm->financial_liquidity_needs = 0.0;
		current_xmachine_Firm->total_financial_needs = 0.0;
		current_xmachine_Firm->external_financial_needs = 0.0;
		current_xmachine_Firm->bankruptcy_state = 0;
		current_xmachine_Firm->financial_crisis_state = 0;
		
}

void unittest_free_Firm_agent()
{
	free_residual_var_datatype_static_array(current_xmachine_Firm->residual_var, 10);
	free_mall_info_array(&current_xmachine_Firm->current_mall_stocks);
	free_debt_item_array(&current_xmachine_Firm->loans);
	free_capital_stock_item_array(&current_xmachine_Firm->capital_stock);
	
	free(current_xmachine_Firm);
}

void free_Firm_agents()
{
	current_xmachine_Firm_holder = Firm_Start_Firm_Labour_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Start_Firm_Labour_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_financial_crisis_ok_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_financial_crisis_ok_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_end_Firm_cycle_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_end_Firm_cycle_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_end_Firm_dies_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_end_Firm_dies_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_0003_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_0003_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_02_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_bankruptcy_checked_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankruptcy_checked_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_End_Firm_Financial_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_End_Firm_Financial_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_004_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_004_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_003_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_003_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_002_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_002_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_001_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_001_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_f1_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_f1_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_End_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Credit_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_Credit_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Credit_02_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Start_Firm_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Start_Firm_Credit_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
}

void free_Firm_states()
{
	free(Firm_Start_Firm_Labour_Role_state);
	free(Firm_Firm_financial_crisis_ok_state);
	free(Firm_Firm_not_in_bankruptcy_state_now_check_financial_crisis_state);
	free(Firm_end_Firm_cycle_state);
	free(Firm_end_Firm_dies_state);
	free(Firm_0003_state);
	free(Firm_02_state);
	free(Firm_Firm_bankruptcy_checked_state);
	free(Firm_End_Firm_Financial_Role_state);
	free(Firm_004_state);
	free(Firm_003_state);
	free(Firm_002_state);
	free(Firm_001_state);
	free(Firm_f1_state);
	free(Firm_Firm_End_Credit_Role_state);
	free(Firm_Firm_Credit_02_state);
	free(Firm_Start_Firm_Credit_Role_state);
}

void transition_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * from_state, xmachine_memory_Firm_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Firm_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Firm_agent_internal(xmachine_memory_Firm * agent, xmachine_memory_Firm_state * state)
{
	xmachine_memory_Firm_holder * current = (xmachine_memory_Firm_holder *)malloc(sizeof(xmachine_memory_Firm_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Firm_agent(int id, int region_id, int gov_id, int day_of_month_to_act, double payment_account, int bank_id, int dmarketmatrix[], residual_var_datatype ** residual_var, double ebit, double earnings, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double net_earnings, double previous_net_earnings, double earnings_per_share, double cum_total_sold_quantity, double cum_revenue, double production_costs, int current_shares_outstanding, double total_payments, mall_info_array * current_mall_stocks, double price, double total_interest_payment, double total_debt_installment_payment, double total_dividend_payment, double current_share_price, double previous_dividend_per_share, double current_dividend_per_share, double previous_earnings_per_share, double current_earnings_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double debt_earnings_ratio, double debt_equity_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, debt_item_array * loans, double total_debt, double total_value_local_inventory, capital_stock_item_array * capital_stock, double total_units_capital_stock, double total_value_capital_stock, double total_capital_depreciation_value, double total_capital_depreciation_units, double total_assets, double equity, double production_liquidity_needs, double financial_liquidity_needs, double total_financial_needs, double external_financial_needs, int bankruptcy_state, int financial_crisis_state)
 * \brief Add Firm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param gov_id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param payment_account Variable for the X-machine memory.
 * \param bank_id Variable for the X-machine memory.
 * \param dmarketmatrix Variable for the X-machine memory.
 * \param residual_var Variable for the X-machine memory.
 * \param ebit Variable for the X-machine memory.
 * \param earnings Variable for the X-machine memory.
 * \param tax_rate_corporate Variable for the X-machine memory.
 * \param tax_rate_vat Variable for the X-machine memory.
 * \param tax_payment Variable for the X-machine memory.
 * \param net_earnings Variable for the X-machine memory.
 * \param previous_net_earnings Variable for the X-machine memory.
 * \param earnings_per_share Variable for the X-machine memory.
 * \param cum_total_sold_quantity Variable for the X-machine memory.
 * \param cum_revenue Variable for the X-machine memory.
 * \param production_costs Variable for the X-machine memory.
 * \param current_shares_outstanding Variable for the X-machine memory.
 * \param total_payments Variable for the X-machine memory.
 * \param current_mall_stocks Variable for the X-machine memory.
 * \param price Variable for the X-machine memory.
 * \param total_interest_payment Variable for the X-machine memory.
 * \param total_debt_installment_payment Variable for the X-machine memory.
 * \param total_dividend_payment Variable for the X-machine memory.
 * \param current_share_price Variable for the X-machine memory.
 * \param previous_dividend_per_share Variable for the X-machine memory.
 * \param current_dividend_per_share Variable for the X-machine memory.
 * \param previous_earnings_per_share Variable for the X-machine memory.
 * \param current_earnings_per_share Variable for the X-machine memory.
 * \param previous_dividend_per_earnings Variable for the X-machine memory.
 * \param current_dividend_per_earnings Variable for the X-machine memory.
 * \param debt_earnings_ratio Variable for the X-machine memory.
 * \param debt_equity_ratio Variable for the X-machine memory.
 * \param price_earnings_ratio Variable for the X-machine memory.
 * \param retained_earnings_ratio Variable for the X-machine memory.
 * \param earnings_per_share_ratio_growth Variable for the X-machine memory.
 * \param critical_price_earnings_ratio Variable for the X-machine memory.
 * \param critical_earnings_per_share_ratio Variable for the X-machine memory.
 * \param loans Variable for the X-machine memory.
 * \param total_debt Variable for the X-machine memory.
 * \param total_value_local_inventory Variable for the X-machine memory.
 * \param capital_stock Variable for the X-machine memory.
 * \param total_units_capital_stock Variable for the X-machine memory.
 * \param total_value_capital_stock Variable for the X-machine memory.
 * \param total_capital_depreciation_value Variable for the X-machine memory.
 * \param total_capital_depreciation_units Variable for the X-machine memory.
 * \param total_assets Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param production_liquidity_needs Variable for the X-machine memory.
 * \param financial_liquidity_needs Variable for the X-machine memory.
 * \param total_financial_needs Variable for the X-machine memory.
 * \param external_financial_needs Variable for the X-machine memory.
 * \param bankruptcy_state Variable for the X-machine memory.
 * \param financial_crisis_state Variable for the X-machine memory.
 */
void add_Firm_agent(int id, int region_id, int gov_id, int day_of_month_to_act, double payment_account, int bank_id, int dmarketmatrix[], residual_var_datatype residual_var[], double ebit, double earnings, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double net_earnings, double previous_net_earnings, double earnings_per_share, double cum_total_sold_quantity, double cum_revenue, double production_costs, int current_shares_outstanding, double total_payments, mall_info_array * current_mall_stocks, double price, double total_interest_payment, double total_debt_installment_payment, double total_dividend_payment, double current_share_price, double previous_dividend_per_share, double current_dividend_per_share, double previous_earnings_per_share, double current_earnings_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double debt_earnings_ratio, double debt_equity_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, debt_item_array * loans, double total_debt, double total_value_local_inventory, capital_stock_item_array * capital_stock, double total_units_capital_stock, double total_value_capital_stock, double total_capital_depreciation_value, double total_capital_depreciation_units, double total_assets, double equity, double production_liquidity_needs, double financial_liquidity_needs, double total_financial_needs, double external_financial_needs, int bankruptcy_state, int financial_crisis_state)
{
	xmachine_memory_Firm * current;
	
	current = init_Firm_agent();
	add_Firm_agent_internal(current, current_xmachine_Firm_next_state);
	
	current->id = id;
	current->region_id = region_id;
	current->gov_id = gov_id;
	current->day_of_month_to_act = day_of_month_to_act;
	current->payment_account = payment_account;
	current->bank_id = bank_id;
	memcpy(current->dmarketmatrix, dmarketmatrix, 10*sizeof(int));
	copy_residual_var_datatype_static_array(residual_var, current->residual_var, 10);
	current->ebit = ebit;
	current->earnings = earnings;
	current->tax_rate_corporate = tax_rate_corporate;
	current->tax_rate_vat = tax_rate_vat;
	current->tax_payment = tax_payment;
	current->net_earnings = net_earnings;
	current->previous_net_earnings = previous_net_earnings;
	current->earnings_per_share = earnings_per_share;
	current->cum_total_sold_quantity = cum_total_sold_quantity;
	current->cum_revenue = cum_revenue;
	current->production_costs = production_costs;
	current->current_shares_outstanding = current_shares_outstanding;
	current->total_payments = total_payments;
	copy_mall_info_array(current_mall_stocks, &current->current_mall_stocks);
	current->price = price;
	current->total_interest_payment = total_interest_payment;
	current->total_debt_installment_payment = total_debt_installment_payment;
	current->total_dividend_payment = total_dividend_payment;
	current->current_share_price = current_share_price;
	current->previous_dividend_per_share = previous_dividend_per_share;
	current->current_dividend_per_share = current_dividend_per_share;
	current->previous_earnings_per_share = previous_earnings_per_share;
	current->current_earnings_per_share = current_earnings_per_share;
	current->previous_dividend_per_earnings = previous_dividend_per_earnings;
	current->current_dividend_per_earnings = current_dividend_per_earnings;
	current->debt_earnings_ratio = debt_earnings_ratio;
	current->debt_equity_ratio = debt_equity_ratio;
	current->price_earnings_ratio = price_earnings_ratio;
	current->retained_earnings_ratio = retained_earnings_ratio;
	current->earnings_per_share_ratio_growth = earnings_per_share_ratio_growth;
	current->critical_price_earnings_ratio = critical_price_earnings_ratio;
	current->critical_earnings_per_share_ratio = critical_earnings_per_share_ratio;
	copy_debt_item_array(loans, &current->loans);
	current->total_debt = total_debt;
	current->total_value_local_inventory = total_value_local_inventory;
	copy_capital_stock_item_array(capital_stock, &current->capital_stock);
	current->total_units_capital_stock = total_units_capital_stock;
	current->total_value_capital_stock = total_value_capital_stock;
	current->total_capital_depreciation_value = total_capital_depreciation_value;
	current->total_capital_depreciation_units = total_capital_depreciation_units;
	current->total_assets = total_assets;
	current->equity = equity;
	current->production_liquidity_needs = production_liquidity_needs;
	current->financial_liquidity_needs = financial_liquidity_needs;
	current->total_financial_needs = total_financial_needs;
	current->external_financial_needs = external_financial_needs;
	current->bankruptcy_state = bankruptcy_state;
	current->financial_crisis_state = financial_crisis_state;
}

xmachine_memory_Bank_state * init_Bank_state()
{
	xmachine_memory_Bank_state * current = (xmachine_memory_Bank_state *)malloc(sizeof(xmachine_memory_Bank_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Bank * init_Bank_agent()
{
	xmachine_memory_Bank * current = (xmachine_memory_Bank *)malloc(sizeof(xmachine_memory_Bank));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	current->gov_id = 0;
	current->cash = 0.0;
	current->total_credit = 0.0;
	current->equity = 0.0;
	current->bce_debt = 0.0;
	current->alfa = 0.0;
	current->value_at_risk = 0.0;
	current->min_interest = 0.0;
	init_double_static_array(current->bank_gamma, 2);
	init_double_static_array(current->profits, 2);
	current->bank_lambda = 0.0;
	current->bce_interest = 0.0;
	current->bank_dividend_rate = 0.0;
	current->tax_rate_corporate = 0.0;
	current->number_of_shares = 0;
	current->debt_period = 0.0;
	current->loan_request_message_found = 0;
	current->day_of_month_to_act = 0;
	
	return current;
}

void free_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Bank_agent()
{
	current_xmachine_Bank = (xmachine_memory_Bank *)malloc(sizeof(xmachine_memory_Bank));
	CHECK_POINTER(current);
	
		current_xmachine_Bank->id = 0;
		current_xmachine_Bank->region_id = 0;
		current_xmachine_Bank->gov_id = 0;
		current_xmachine_Bank->cash = 0.0;
		current_xmachine_Bank->total_credit = 0.0;
		current_xmachine_Bank->equity = 0.0;
		current_xmachine_Bank->bce_debt = 0.0;
		current_xmachine_Bank->alfa = 0.0;
		current_xmachine_Bank->value_at_risk = 0.0;
		current_xmachine_Bank->min_interest = 0.0;
		init_double_static_array(current_xmachine_Bank->bank_gamma, 2);
		init_double_static_array(current_xmachine_Bank->profits, 2);
		current_xmachine_Bank->bank_lambda = 0.0;
		current_xmachine_Bank->bce_interest = 0.0;
		current_xmachine_Bank->bank_dividend_rate = 0.0;
		current_xmachine_Bank->tax_rate_corporate = 0.0;
		current_xmachine_Bank->number_of_shares = 0;
		current_xmachine_Bank->debt_period = 0.0;
		current_xmachine_Bank->loan_request_message_found = 0;
		current_xmachine_Bank->day_of_month_to_act = 0;
		
}

void unittest_free_Bank_agent()
{
	
	free(current_xmachine_Bank);
}

void free_Bank_agents()
{
	current_xmachine_Bank_holder = Bank_end_Bank_cycle_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		free_Bank_agent(current_xmachine_Bank_holder, Bank_end_Bank_cycle_state);
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	current_xmachine_Bank_holder = Bank_Bank_05_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_05_state);
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	current_xmachine_Bank_holder = Bank_Bank_04_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_04_state);
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	current_xmachine_Bank_holder = Bank_Bank_03_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_03_state);
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	current_xmachine_Bank_holder = Bank_Bank_02_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_02_state);
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
	current_xmachine_Bank_holder = Bank_Bank_start_credit_market_role_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		free_Bank_agent(current_xmachine_Bank_holder, Bank_Bank_start_credit_market_role_state);
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
}

void free_Bank_states()
{
	free(Bank_end_Bank_cycle_state);
	free(Bank_Bank_05_state);
	free(Bank_Bank_04_state);
	free(Bank_Bank_03_state);
	free(Bank_Bank_02_state);
	free(Bank_Bank_start_credit_market_role_state);
}

void transition_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * from_state, xmachine_memory_Bank_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Bank_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Bank_agent_internal(xmachine_memory_Bank * agent, xmachine_memory_Bank_state * state)
{
	xmachine_memory_Bank_holder * current = (xmachine_memory_Bank_holder *)malloc(sizeof(xmachine_memory_Bank_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Bank_agent(int id, int region_id, int gov_id, double cash, double total_credit, double equity, double bce_debt, double alfa, double value_at_risk, double min_interest, double bank_gamma[], double profits[], double bank_lambda, double bce_interest, double bank_dividend_rate, double tax_rate_corporate, int number_of_shares, double debt_period, int loan_request_message_found, int day_of_month_to_act)
 * \brief Add Bank X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param gov_id Variable for the X-machine memory.
 * \param cash Variable for the X-machine memory.
 * \param total_credit Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param bce_debt Variable for the X-machine memory.
 * \param alfa Variable for the X-machine memory.
 * \param value_at_risk Variable for the X-machine memory.
 * \param min_interest Variable for the X-machine memory.
 * \param bank_gamma Variable for the X-machine memory.
 * \param profits Variable for the X-machine memory.
 * \param bank_lambda Variable for the X-machine memory.
 * \param bce_interest Variable for the X-machine memory.
 * \param bank_dividend_rate Variable for the X-machine memory.
 * \param tax_rate_corporate Variable for the X-machine memory.
 * \param number_of_shares Variable for the X-machine memory.
 * \param debt_period Variable for the X-machine memory.
 * \param loan_request_message_found Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 */
void add_Bank_agent(int id, int region_id, int gov_id, double cash, double total_credit, double equity, double bce_debt, double alfa, double value_at_risk, double min_interest, double bank_gamma[], double profits[], double bank_lambda, double bce_interest, double bank_dividend_rate, double tax_rate_corporate, int number_of_shares, double debt_period, int loan_request_message_found, int day_of_month_to_act)
{
	xmachine_memory_Bank * current;
	
	current = init_Bank_agent();
	add_Bank_agent_internal(current, current_xmachine_Bank_next_state);
	
	current->id = id;
	current->region_id = region_id;
	current->gov_id = gov_id;
	current->cash = cash;
	current->total_credit = total_credit;
	current->equity = equity;
	current->bce_debt = bce_debt;
	current->alfa = alfa;
	current->value_at_risk = value_at_risk;
	current->min_interest = min_interest;
	memcpy(current->bank_gamma, bank_gamma, 2*sizeof(double));
	memcpy(current->profits, profits, 2*sizeof(double));
	current->bank_lambda = bank_lambda;
	current->bce_interest = bce_interest;
	current->bank_dividend_rate = bank_dividend_rate;
	current->tax_rate_corporate = tax_rate_corporate;
	current->number_of_shares = number_of_shares;
	current->debt_period = debt_period;
	current->loan_request_message_found = loan_request_message_found;
	current->day_of_month_to_act = day_of_month_to_act;
}

xmachine_memory_Dummy_state * init_Dummy_state()
{
	xmachine_memory_Dummy_state * current = (xmachine_memory_Dummy_state *)malloc(sizeof(xmachine_memory_Dummy_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Dummy * init_Dummy_agent()
{
	xmachine_memory_Dummy * current = (xmachine_memory_Dummy *)malloc(sizeof(xmachine_memory_Dummy));
	CHECK_POINTER(current);
	
	current->id = 0;
	
	return current;
}

void free_Dummy_agent(xmachine_memory_Dummy_holder * tmp, xmachine_memory_Dummy_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Dummy_agent()
{
	current_xmachine_Dummy = (xmachine_memory_Dummy *)malloc(sizeof(xmachine_memory_Dummy));
	CHECK_POINTER(current);
	
		current_xmachine_Dummy->id = 0;
		
}

void unittest_free_Dummy_agent()
{
	
	free(current_xmachine_Dummy);
}

void free_Dummy_agents()
{
	current_xmachine_Dummy_holder = Dummy_003_state->agents;
	while(current_xmachine_Dummy_holder)
	{
		temp_xmachine_Dummy_holder = current_xmachine_Dummy_holder->next;
		free_Dummy_agent(current_xmachine_Dummy_holder, Dummy_003_state);
		current_xmachine_Dummy_holder = temp_xmachine_Dummy_holder;
	}
	current_xmachine_Dummy_holder = Dummy_002_state->agents;
	while(current_xmachine_Dummy_holder)
	{
		temp_xmachine_Dummy_holder = current_xmachine_Dummy_holder->next;
		free_Dummy_agent(current_xmachine_Dummy_holder, Dummy_002_state);
		current_xmachine_Dummy_holder = temp_xmachine_Dummy_holder;
	}
	current_xmachine_Dummy_holder = Dummy_001_state->agents;
	while(current_xmachine_Dummy_holder)
	{
		temp_xmachine_Dummy_holder = current_xmachine_Dummy_holder->next;
		free_Dummy_agent(current_xmachine_Dummy_holder, Dummy_001_state);
		current_xmachine_Dummy_holder = temp_xmachine_Dummy_holder;
	}
}

void free_Dummy_states()
{
	free(Dummy_003_state);
	free(Dummy_002_state);
	free(Dummy_001_state);
}

void transition_Dummy_agent(xmachine_memory_Dummy_holder * tmp, xmachine_memory_Dummy_state * from_state, xmachine_memory_Dummy_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Dummy_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Dummy_agent_internal(xmachine_memory_Dummy * agent, xmachine_memory_Dummy_state * state)
{
	xmachine_memory_Dummy_holder * current = (xmachine_memory_Dummy_holder *)malloc(sizeof(xmachine_memory_Dummy_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Dummy_agent(int id)
 * \brief Add Dummy X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 */
void add_Dummy_agent(int id)
{
	xmachine_memory_Dummy * current;
	
	current = init_Dummy_agent();
	add_Dummy_agent_internal(current, current_xmachine_Dummy_next_state);
	
	current->id = id;
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	free_Firm_agents();
	free_Bank_agents();
	free_Dummy_agents();
	
}


/** \fn void set_id(int id) 
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(int id)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).id = id;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).id = id;
	if(current_xmachine->xmachine_Dummy) (*current_xmachine->xmachine_Dummy).id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).id;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).id;
	if(current_xmachine->xmachine_Dummy) return (*current_xmachine->xmachine_Dummy).id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_region_id(int region_id) 
 * \brief Set region_id memory variable for current X-machine.
 * \param region_id New value for variable.
 */
void set_region_id(int region_id)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).region_id = region_id;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).region_id = region_id;
}

/** \fn int get_region_id()
 * \brief Get region_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_region_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).region_id;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).region_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_gov_id(int gov_id) 
 * \brief Set gov_id memory variable for current X-machine.
 * \param gov_id New value for variable.
 */
void set_gov_id(int gov_id)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).gov_id = gov_id;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).gov_id = gov_id;
}

/** \fn int get_gov_id()
 * \brief Get gov_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_gov_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).gov_id;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).gov_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day_of_month_to_act(int day_of_month_to_act) 
 * \brief Set day_of_month_to_act memory variable for current X-machine.
 * \param day_of_month_to_act New value for variable.
 */
void set_day_of_month_to_act(int day_of_month_to_act)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).day_of_month_to_act = day_of_month_to_act;
}

/** \fn int get_day_of_month_to_act()
 * \brief Get day_of_month_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_to_act()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).day_of_month_to_act;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).day_of_month_to_act;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_payment_account(double payment_account) 
 * \brief Set payment_account memory variable for current X-machine.
 * \param payment_account New value for variable.
 */
void set_payment_account(double payment_account)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).payment_account = payment_account;
}

/** \fn double get_payment_account()
 * \brief Get payment_account memory variable from current X-machine.
 * \return Value for variable.
 */
double get_payment_account()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).payment_account;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_bank_id(int bank_id) 
 * \brief Set bank_id memory variable for current X-machine.
 * \param bank_id New value for variable.
 */
void set_bank_id(int bank_id)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).bank_id = bank_id;
}

/** \fn int get_bank_id()
 * \brief Get bank_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bank_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).bank_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn int get_dmarketmatrix()
 * \brief Get dmarketmatrix memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_dmarketmatrix()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).dmarketmatrix;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn residual_var_datatype get_residual_var()
 * \brief Get residual_var memory variable from current X-machine.
 * \return Value for variable.
 */
residual_var_datatype * get_residual_var()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).residual_var;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_ebit(double ebit) 
 * \brief Set ebit memory variable for current X-machine.
 * \param ebit New value for variable.
 */
void set_ebit(double ebit)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).ebit = ebit;
}

/** \fn double get_ebit()
 * \brief Get ebit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_ebit()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).ebit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_earnings(double earnings) 
 * \brief Set earnings memory variable for current X-machine.
 * \param earnings New value for variable.
 */
void set_earnings(double earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).earnings = earnings;
}

/** \fn double get_earnings()
 * \brief Get earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate_corporate(double tax_rate_corporate) 
 * \brief Set tax_rate_corporate memory variable for current X-machine.
 * \param tax_rate_corporate New value for variable.
 */
void set_tax_rate_corporate(double tax_rate_corporate)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).tax_rate_corporate = tax_rate_corporate;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).tax_rate_corporate = tax_rate_corporate;
}

/** \fn double get_tax_rate_corporate()
 * \brief Get tax_rate_corporate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_corporate()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).tax_rate_corporate;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).tax_rate_corporate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate_vat(double tax_rate_vat) 
 * \brief Set tax_rate_vat memory variable for current X-machine.
 * \param tax_rate_vat New value for variable.
 */
void set_tax_rate_vat(double tax_rate_vat)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).tax_rate_vat = tax_rate_vat;
}

/** \fn double get_tax_rate_vat()
 * \brief Get tax_rate_vat memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_vat()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).tax_rate_vat;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_payment(double tax_payment) 
 * \brief Set tax_payment memory variable for current X-machine.
 * \param tax_payment New value for variable.
 */
void set_tax_payment(double tax_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).tax_payment = tax_payment;
}

/** \fn double get_tax_payment()
 * \brief Get tax_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).tax_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_net_earnings(double net_earnings) 
 * \brief Set net_earnings memory variable for current X-machine.
 * \param net_earnings New value for variable.
 */
void set_net_earnings(double net_earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).net_earnings = net_earnings;
}

/** \fn double get_net_earnings()
 * \brief Get net_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_net_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).net_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_previous_net_earnings(double previous_net_earnings) 
 * \brief Set previous_net_earnings memory variable for current X-machine.
 * \param previous_net_earnings New value for variable.
 */
void set_previous_net_earnings(double previous_net_earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).previous_net_earnings = previous_net_earnings;
}

/** \fn double get_previous_net_earnings()
 * \brief Get previous_net_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_previous_net_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).previous_net_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_earnings_per_share(double earnings_per_share) 
 * \brief Set earnings_per_share memory variable for current X-machine.
 * \param earnings_per_share New value for variable.
 */
void set_earnings_per_share(double earnings_per_share)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).earnings_per_share = earnings_per_share;
}

/** \fn double get_earnings_per_share()
 * \brief Get earnings_per_share memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earnings_per_share()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).earnings_per_share;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_cum_total_sold_quantity(double cum_total_sold_quantity) 
 * \brief Set cum_total_sold_quantity memory variable for current X-machine.
 * \param cum_total_sold_quantity New value for variable.
 */
void set_cum_total_sold_quantity(double cum_total_sold_quantity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).cum_total_sold_quantity = cum_total_sold_quantity;
}

/** \fn double get_cum_total_sold_quantity()
 * \brief Get cum_total_sold_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cum_total_sold_quantity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).cum_total_sold_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_cum_revenue(double cum_revenue) 
 * \brief Set cum_revenue memory variable for current X-machine.
 * \param cum_revenue New value for variable.
 */
void set_cum_revenue(double cum_revenue)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).cum_revenue = cum_revenue;
}

/** \fn double get_cum_revenue()
 * \brief Get cum_revenue memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cum_revenue()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).cum_revenue;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_production_costs(double production_costs) 
 * \brief Set production_costs memory variable for current X-machine.
 * \param production_costs New value for variable.
 */
void set_production_costs(double production_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).production_costs = production_costs;
}

/** \fn double get_production_costs()
 * \brief Get production_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_production_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).production_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_shares_outstanding(int current_shares_outstanding) 
 * \brief Set current_shares_outstanding memory variable for current X-machine.
 * \param current_shares_outstanding New value for variable.
 */
void set_current_shares_outstanding(int current_shares_outstanding)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_shares_outstanding = current_shares_outstanding;
}

/** \fn int get_current_shares_outstanding()
 * \brief Get current_shares_outstanding memory variable from current X-machine.
 * \return Value for variable.
 */
int get_current_shares_outstanding()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_shares_outstanding;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_total_payments(double total_payments) 
 * \brief Set total_payments memory variable for current X-machine.
 * \param total_payments New value for variable.
 */
void set_total_payments(double total_payments)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_payments = total_payments;
}

/** \fn double get_total_payments()
 * \brief Get total_payments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_payments()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_payments;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn mall_info_array get_current_mall_stocks()
 * \brief Get current_mall_stocks memory variable from current X-machine.
 * \return Value for variable.
 */
mall_info_array * get_current_mall_stocks()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).current_mall_stocks;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_price(double price) 
 * \brief Set price memory variable for current X-machine.
 * \param price New value for variable.
 */
void set_price(double price)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).price = price;
}

/** \fn double get_price()
 * \brief Get price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_interest_payment(double total_interest_payment) 
 * \brief Set total_interest_payment memory variable for current X-machine.
 * \param total_interest_payment New value for variable.
 */
void set_total_interest_payment(double total_interest_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_interest_payment = total_interest_payment;
}

/** \fn double get_total_interest_payment()
 * \brief Get total_interest_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_interest_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_interest_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_debt_installment_payment(double total_debt_installment_payment) 
 * \brief Set total_debt_installment_payment memory variable for current X-machine.
 * \param total_debt_installment_payment New value for variable.
 */
void set_total_debt_installment_payment(double total_debt_installment_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_debt_installment_payment = total_debt_installment_payment;
}

/** \fn double get_total_debt_installment_payment()
 * \brief Get total_debt_installment_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_debt_installment_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_debt_installment_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_dividend_payment(double total_dividend_payment) 
 * \brief Set total_dividend_payment memory variable for current X-machine.
 * \param total_dividend_payment New value for variable.
 */
void set_total_dividend_payment(double total_dividend_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_dividend_payment = total_dividend_payment;
}

/** \fn double get_total_dividend_payment()
 * \brief Get total_dividend_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_dividend_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_dividend_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_share_price(double current_share_price) 
 * \brief Set current_share_price memory variable for current X-machine.
 * \param current_share_price New value for variable.
 */
void set_current_share_price(double current_share_price)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_share_price = current_share_price;
}

/** \fn double get_current_share_price()
 * \brief Get current_share_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_share_price()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_share_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_previous_dividend_per_share(double previous_dividend_per_share) 
 * \brief Set previous_dividend_per_share memory variable for current X-machine.
 * \param previous_dividend_per_share New value for variable.
 */
void set_previous_dividend_per_share(double previous_dividend_per_share)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).previous_dividend_per_share = previous_dividend_per_share;
}

/** \fn double get_previous_dividend_per_share()
 * \brief Get previous_dividend_per_share memory variable from current X-machine.
 * \return Value for variable.
 */
double get_previous_dividend_per_share()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).previous_dividend_per_share;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_dividend_per_share(double current_dividend_per_share) 
 * \brief Set current_dividend_per_share memory variable for current X-machine.
 * \param current_dividend_per_share New value for variable.
 */
void set_current_dividend_per_share(double current_dividend_per_share)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_dividend_per_share = current_dividend_per_share;
}

/** \fn double get_current_dividend_per_share()
 * \brief Get current_dividend_per_share memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_dividend_per_share()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_dividend_per_share;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_previous_earnings_per_share(double previous_earnings_per_share) 
 * \brief Set previous_earnings_per_share memory variable for current X-machine.
 * \param previous_earnings_per_share New value for variable.
 */
void set_previous_earnings_per_share(double previous_earnings_per_share)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).previous_earnings_per_share = previous_earnings_per_share;
}

/** \fn double get_previous_earnings_per_share()
 * \brief Get previous_earnings_per_share memory variable from current X-machine.
 * \return Value for variable.
 */
double get_previous_earnings_per_share()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).previous_earnings_per_share;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_earnings_per_share(double current_earnings_per_share) 
 * \brief Set current_earnings_per_share memory variable for current X-machine.
 * \param current_earnings_per_share New value for variable.
 */
void set_current_earnings_per_share(double current_earnings_per_share)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_earnings_per_share = current_earnings_per_share;
}

/** \fn double get_current_earnings_per_share()
 * \brief Get current_earnings_per_share memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_earnings_per_share()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_earnings_per_share;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_previous_dividend_per_earnings(double previous_dividend_per_earnings) 
 * \brief Set previous_dividend_per_earnings memory variable for current X-machine.
 * \param previous_dividend_per_earnings New value for variable.
 */
void set_previous_dividend_per_earnings(double previous_dividend_per_earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).previous_dividend_per_earnings = previous_dividend_per_earnings;
}

/** \fn double get_previous_dividend_per_earnings()
 * \brief Get previous_dividend_per_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_previous_dividend_per_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).previous_dividend_per_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_dividend_per_earnings(double current_dividend_per_earnings) 
 * \brief Set current_dividend_per_earnings memory variable for current X-machine.
 * \param current_dividend_per_earnings New value for variable.
 */
void set_current_dividend_per_earnings(double current_dividend_per_earnings)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_dividend_per_earnings = current_dividend_per_earnings;
}

/** \fn double get_current_dividend_per_earnings()
 * \brief Get current_dividend_per_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_dividend_per_earnings()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_dividend_per_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_debt_earnings_ratio(double debt_earnings_ratio) 
 * \brief Set debt_earnings_ratio memory variable for current X-machine.
 * \param debt_earnings_ratio New value for variable.
 */
void set_debt_earnings_ratio(double debt_earnings_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).debt_earnings_ratio = debt_earnings_ratio;
}

/** \fn double get_debt_earnings_ratio()
 * \brief Get debt_earnings_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_debt_earnings_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).debt_earnings_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_debt_equity_ratio(double debt_equity_ratio) 
 * \brief Set debt_equity_ratio memory variable for current X-machine.
 * \param debt_equity_ratio New value for variable.
 */
void set_debt_equity_ratio(double debt_equity_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).debt_equity_ratio = debt_equity_ratio;
}

/** \fn double get_debt_equity_ratio()
 * \brief Get debt_equity_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_debt_equity_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).debt_equity_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_price_earnings_ratio(double price_earnings_ratio) 
 * \brief Set price_earnings_ratio memory variable for current X-machine.
 * \param price_earnings_ratio New value for variable.
 */
void set_price_earnings_ratio(double price_earnings_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).price_earnings_ratio = price_earnings_ratio;
}

/** \fn double get_price_earnings_ratio()
 * \brief Get price_earnings_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price_earnings_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).price_earnings_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_retained_earnings_ratio(double retained_earnings_ratio) 
 * \brief Set retained_earnings_ratio memory variable for current X-machine.
 * \param retained_earnings_ratio New value for variable.
 */
void set_retained_earnings_ratio(double retained_earnings_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).retained_earnings_ratio = retained_earnings_ratio;
}

/** \fn double get_retained_earnings_ratio()
 * \brief Get retained_earnings_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_retained_earnings_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).retained_earnings_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_earnings_per_share_ratio_growth(double earnings_per_share_ratio_growth) 
 * \brief Set earnings_per_share_ratio_growth memory variable for current X-machine.
 * \param earnings_per_share_ratio_growth New value for variable.
 */
void set_earnings_per_share_ratio_growth(double earnings_per_share_ratio_growth)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).earnings_per_share_ratio_growth = earnings_per_share_ratio_growth;
}

/** \fn double get_earnings_per_share_ratio_growth()
 * \brief Get earnings_per_share_ratio_growth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earnings_per_share_ratio_growth()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).earnings_per_share_ratio_growth;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_critical_price_earnings_ratio(double critical_price_earnings_ratio) 
 * \brief Set critical_price_earnings_ratio memory variable for current X-machine.
 * \param critical_price_earnings_ratio New value for variable.
 */
void set_critical_price_earnings_ratio(double critical_price_earnings_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).critical_price_earnings_ratio = critical_price_earnings_ratio;
}

/** \fn double get_critical_price_earnings_ratio()
 * \brief Get critical_price_earnings_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_critical_price_earnings_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).critical_price_earnings_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_critical_earnings_per_share_ratio(double critical_earnings_per_share_ratio) 
 * \brief Set critical_earnings_per_share_ratio memory variable for current X-machine.
 * \param critical_earnings_per_share_ratio New value for variable.
 */
void set_critical_earnings_per_share_ratio(double critical_earnings_per_share_ratio)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).critical_earnings_per_share_ratio = critical_earnings_per_share_ratio;
}

/** \fn double get_critical_earnings_per_share_ratio()
 * \brief Get critical_earnings_per_share_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_critical_earnings_per_share_ratio()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).critical_earnings_per_share_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn debt_item_array get_loans()
 * \brief Get loans memory variable from current X-machine.
 * \return Value for variable.
 */
debt_item_array * get_loans()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).loans;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_debt(double total_debt) 
 * \brief Set total_debt memory variable for current X-machine.
 * \param total_debt New value for variable.
 */
void set_total_debt(double total_debt)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_debt = total_debt;
}

/** \fn double get_total_debt()
 * \brief Get total_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_debt()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_value_local_inventory(double total_value_local_inventory) 
 * \brief Set total_value_local_inventory memory variable for current X-machine.
 * \param total_value_local_inventory New value for variable.
 */
void set_total_value_local_inventory(double total_value_local_inventory)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_value_local_inventory = total_value_local_inventory;
}

/** \fn double get_total_value_local_inventory()
 * \brief Get total_value_local_inventory memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_value_local_inventory()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_value_local_inventory;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn capital_stock_item_array get_capital_stock()
 * \brief Get capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
capital_stock_item_array * get_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_units_capital_stock(double total_units_capital_stock) 
 * \brief Set total_units_capital_stock memory variable for current X-machine.
 * \param total_units_capital_stock New value for variable.
 */
void set_total_units_capital_stock(double total_units_capital_stock)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_units_capital_stock = total_units_capital_stock;
}

/** \fn double get_total_units_capital_stock()
 * \brief Get total_units_capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_units_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_units_capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_value_capital_stock(double total_value_capital_stock) 
 * \brief Set total_value_capital_stock memory variable for current X-machine.
 * \param total_value_capital_stock New value for variable.
 */
void set_total_value_capital_stock(double total_value_capital_stock)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_value_capital_stock = total_value_capital_stock;
}

/** \fn double get_total_value_capital_stock()
 * \brief Get total_value_capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_value_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_value_capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_capital_depreciation_value(double total_capital_depreciation_value) 
 * \brief Set total_capital_depreciation_value memory variable for current X-machine.
 * \param total_capital_depreciation_value New value for variable.
 */
void set_total_capital_depreciation_value(double total_capital_depreciation_value)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_capital_depreciation_value = total_capital_depreciation_value;
}

/** \fn double get_total_capital_depreciation_value()
 * \brief Get total_capital_depreciation_value memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_capital_depreciation_value()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_capital_depreciation_value;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_capital_depreciation_units(double total_capital_depreciation_units) 
 * \brief Set total_capital_depreciation_units memory variable for current X-machine.
 * \param total_capital_depreciation_units New value for variable.
 */
void set_total_capital_depreciation_units(double total_capital_depreciation_units)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_capital_depreciation_units = total_capital_depreciation_units;
}

/** \fn double get_total_capital_depreciation_units()
 * \brief Get total_capital_depreciation_units memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_capital_depreciation_units()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_capital_depreciation_units;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_assets(double total_assets) 
 * \brief Set total_assets memory variable for current X-machine.
 * \param total_assets New value for variable.
 */
void set_total_assets(double total_assets)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_assets = total_assets;
}

/** \fn double get_total_assets()
 * \brief Get total_assets memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_assets()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_assets;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_equity(double equity) 
 * \brief Set equity memory variable for current X-machine.
 * \param equity New value for variable.
 */
void set_equity(double equity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).equity = equity;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).equity = equity;
}

/** \fn double get_equity()
 * \brief Get equity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_equity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).equity;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).equity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_production_liquidity_needs(double production_liquidity_needs) 
 * \brief Set production_liquidity_needs memory variable for current X-machine.
 * \param production_liquidity_needs New value for variable.
 */
void set_production_liquidity_needs(double production_liquidity_needs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).production_liquidity_needs = production_liquidity_needs;
}

/** \fn double get_production_liquidity_needs()
 * \brief Get production_liquidity_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_production_liquidity_needs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).production_liquidity_needs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_financial_liquidity_needs(double financial_liquidity_needs) 
 * \brief Set financial_liquidity_needs memory variable for current X-machine.
 * \param financial_liquidity_needs New value for variable.
 */
void set_financial_liquidity_needs(double financial_liquidity_needs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).financial_liquidity_needs = financial_liquidity_needs;
}

/** \fn double get_financial_liquidity_needs()
 * \brief Get financial_liquidity_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_financial_liquidity_needs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).financial_liquidity_needs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_financial_needs(double total_financial_needs) 
 * \brief Set total_financial_needs memory variable for current X-machine.
 * \param total_financial_needs New value for variable.
 */
void set_total_financial_needs(double total_financial_needs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_financial_needs = total_financial_needs;
}

/** \fn double get_total_financial_needs()
 * \brief Get total_financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_financial_needs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_external_financial_needs(double external_financial_needs) 
 * \brief Set external_financial_needs memory variable for current X-machine.
 * \param external_financial_needs New value for variable.
 */
void set_external_financial_needs(double external_financial_needs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).external_financial_needs = external_financial_needs;
}

/** \fn double get_external_financial_needs()
 * \brief Get external_financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_external_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).external_financial_needs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_bankruptcy_state(int bankruptcy_state) 
 * \brief Set bankruptcy_state memory variable for current X-machine.
 * \param bankruptcy_state New value for variable.
 */
void set_bankruptcy_state(int bankruptcy_state)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).bankruptcy_state = bankruptcy_state;
}

/** \fn int get_bankruptcy_state()
 * \brief Get bankruptcy_state memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bankruptcy_state()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).bankruptcy_state;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_financial_crisis_state(int financial_crisis_state) 
 * \brief Set financial_crisis_state memory variable for current X-machine.
 * \param financial_crisis_state New value for variable.
 */
void set_financial_crisis_state(int financial_crisis_state)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).financial_crisis_state = financial_crisis_state;
}

/** \fn int get_financial_crisis_state()
 * \brief Get financial_crisis_state memory variable from current X-machine.
 * \return Value for variable.
 */
int get_financial_crisis_state()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).financial_crisis_state;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_cash(double cash) 
 * \brief Set cash memory variable for current X-machine.
 * \param cash New value for variable.
 */
void set_cash(double cash)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).cash = cash;
}

/** \fn double get_cash()
 * \brief Get cash memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cash()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).cash;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_credit(double total_credit) 
 * \brief Set total_credit memory variable for current X-machine.
 * \param total_credit New value for variable.
 */
void set_total_credit(double total_credit)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).total_credit = total_credit;
}

/** \fn double get_total_credit()
 * \brief Get total_credit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_credit()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).total_credit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_bce_debt(double bce_debt) 
 * \brief Set bce_debt memory variable for current X-machine.
 * \param bce_debt New value for variable.
 */
void set_bce_debt(double bce_debt)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).bce_debt = bce_debt;
}

/** \fn double get_bce_debt()
 * \brief Get bce_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bce_debt()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).bce_debt;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_alfa(double alfa) 
 * \brief Set alfa memory variable for current X-machine.
 * \param alfa New value for variable.
 */
void set_alfa(double alfa)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).alfa = alfa;
}

/** \fn double get_alfa()
 * \brief Get alfa memory variable from current X-machine.
 * \return Value for variable.
 */
double get_alfa()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).alfa;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_value_at_risk(double value_at_risk) 
 * \brief Set value_at_risk memory variable for current X-machine.
 * \param value_at_risk New value for variable.
 */
void set_value_at_risk(double value_at_risk)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).value_at_risk = value_at_risk;
}

/** \fn double get_value_at_risk()
 * \brief Get value_at_risk memory variable from current X-machine.
 * \return Value for variable.
 */
double get_value_at_risk()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).value_at_risk;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_min_interest(double min_interest) 
 * \brief Set min_interest memory variable for current X-machine.
 * \param min_interest New value for variable.
 */
void set_min_interest(double min_interest)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).min_interest = min_interest;
}

/** \fn double get_min_interest()
 * \brief Get min_interest memory variable from current X-machine.
 * \return Value for variable.
 */
double get_min_interest()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).min_interest;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double get_bank_gamma()
 * \brief Get bank_gamma memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_bank_gamma()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).bank_gamma;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_profits()
 * \brief Get profits memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_profits()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).profits;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_bank_lambda(double bank_lambda) 
 * \brief Set bank_lambda memory variable for current X-machine.
 * \param bank_lambda New value for variable.
 */
void set_bank_lambda(double bank_lambda)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).bank_lambda = bank_lambda;
}

/** \fn double get_bank_lambda()
 * \brief Get bank_lambda memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bank_lambda()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).bank_lambda;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_bce_interest(double bce_interest) 
 * \brief Set bce_interest memory variable for current X-machine.
 * \param bce_interest New value for variable.
 */
void set_bce_interest(double bce_interest)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).bce_interest = bce_interest;
}

/** \fn double get_bce_interest()
 * \brief Get bce_interest memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bce_interest()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).bce_interest;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_bank_dividend_rate(double bank_dividend_rate) 
 * \brief Set bank_dividend_rate memory variable for current X-machine.
 * \param bank_dividend_rate New value for variable.
 */
void set_bank_dividend_rate(double bank_dividend_rate)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).bank_dividend_rate = bank_dividend_rate;
}

/** \fn double get_bank_dividend_rate()
 * \brief Get bank_dividend_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bank_dividend_rate()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).bank_dividend_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_number_of_shares(int number_of_shares) 
 * \brief Set number_of_shares memory variable for current X-machine.
 * \param number_of_shares New value for variable.
 */
void set_number_of_shares(int number_of_shares)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).number_of_shares = number_of_shares;
}

/** \fn int get_number_of_shares()
 * \brief Get number_of_shares memory variable from current X-machine.
 * \return Value for variable.
 */
int get_number_of_shares()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).number_of_shares;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_debt_period(double debt_period) 
 * \brief Set debt_period memory variable for current X-machine.
 * \param debt_period New value for variable.
 */
void set_debt_period(double debt_period)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).debt_period = debt_period;
}

/** \fn double get_debt_period()
 * \brief Get debt_period memory variable from current X-machine.
 * \return Value for variable.
 */
double get_debt_period()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).debt_period;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_loan_request_message_found(int loan_request_message_found) 
 * \brief Set loan_request_message_found memory variable for current X-machine.
 * \param loan_request_message_found New value for variable.
 */
void set_loan_request_message_found(int loan_request_message_found)
{
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).loan_request_message_found = loan_request_message_found;
}

/** \fn int get_loan_request_message_found()
 * \brief Get loan_request_message_found memory variable from current X-machine.
 * \return Value for variable.
 */
int get_loan_request_message_found()
{
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).loan_request_message_found;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->;*/
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->;*/
    /*if (current_xmachine->xmachine_Dummy) value = current_xmachine->xmachine_Dummy->;*/

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->id;*/
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->id;*/
    /*if (current_xmachine->xmachine_Dummy) value = current_xmachine->xmachine_Dummy->id;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->0.0;*/
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->0.0;*/
    /*if (current_xmachine->xmachine_Dummy) value = current_xmachine->xmachine_Dummy->0.0;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->0.0;*/ 
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->0.0;*/ 
    /*if (current_xmachine->xmachine_Dummy) value = current_xmachine->xmachine_Dummy->0.0;*/ 

    return value;
}
/** \fn double agent_get_z()
 * \brief Fixed routine to get the z coordinate from current X-machine
  * \return Value of z coordinate
  */
double agent_get_z()
{
    double value = 0.0;

    return value;
}

/** \fn void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
 * \brief Add a node to the node list.
 * \param node_id The node ID.
 * \param minx The minumum value on the x-axis of the bounding volume.
 * \param maxx The maximum value on the x-axis of the bounding volume.
 * \param miny The minumum value on the y-axis of the bounding volume.
 * \param maxy The maximum value on the y-axis of the bounding volume.
 * \param minz The minumum value on the z-axis of the bounding volume.
 * \param maxz The maximum value on the z-axis of the bounding volume.
 */
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
{
	node_information * current = *p_node_info;
	node_information * tmp = NULL;
	
	while(current)
	{
		tmp = current;
		current = current->next;
	}
	
	current = (node_information *)malloc(sizeof(node_information));
		CHECK_POINTER(current);

	if(tmp)
	{
		tmp->next = current;
	}
	else
	{
		*p_node_info = current;
	}
	
	current->next = NULL;
	current->node_id = node_id;
	current->agents_in_halo = 0;
	current->agent_total = 0;
	current->agents = NULL;
	current->bank_account_update_messages = NULL;
	current->loan_request_messages = NULL;
	current->loan_conditions_messages = NULL;
	current->loan_acceptance_messages = NULL;
	current->installment_messages = NULL;
	current->bankruptcy_messages = NULL;
	current->BCE_return_messages = NULL;
	current->tax_payment_messages = NULL;
	current->dividend_per_share_messages = NULL;
	current->current_mall_stock_info_messages = NULL;
	current->order_messages = NULL;
	current->order_status_messages = NULL;


	current->partition_data[0] = minx;
	current->partition_data[1] = maxx;
	current->partition_data[2] = miny;
	current->partition_data[3] = maxy;
	current->partition_data[4] = minz;
	current->partition_data[5] = maxz;
}

/**\fn void free_node_info()
 * \brief Free the node list.
 */
void free_node_info()
{
	node_information * tmp, * head;
	head = *p_node_info;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_node_info = NULL;
}

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
    int rc;
	FILE *file;
	char data[100];
	
	free(current_xmachine);
	/* Free x-machine memory */
	freexmachines();
	/* Free space partitions linked list */
	free_node_info();
	/* Free agent states */
	free_Firm_states();
	free_Bank_states();
	free_Dummy_states();
	
	
	/* Free message boards */

	rc = MB_Delete(&b_bank_account_update);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bank_account_update' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bank_account_update' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_loan_request);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_request' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_request' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_loan_conditions);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_conditions' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_conditions' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_conditions' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_loan_acceptance);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'loan_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'loan_acceptance' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'loan_acceptance' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_installment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'installment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'installment' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'installment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_bankruptcy);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'bankruptcy' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_BCE_return);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'BCE_return' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'BCE_return' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'BCE_return' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_tax_payment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'tax_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'tax_payment' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'tax_payment' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_dividend_per_share);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'dividend_per_share' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend_per_share' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'dividend_per_share' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_current_mall_stock_info);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'current_mall_stock_info' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'current_mall_stock_info' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_order);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'order' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_order_status);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'order_status' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'order_status' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'order_status' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;   
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif


    rc = MB_Env_Finalise();
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not finalise MB environment\n");
       switch(rc) {
           case MB_ERR_ENV:
               fprintf(stderr, "\t reason: MB environment not yet started?\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Env_Finalise returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif

	

	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<totaltime>", file);
	sprintf(data, "%d", (int)(total_time * 1000.0) % 1000);
	fputs(data, file);
	fputs("</totaltime>\n", file);
	/*fputs("<totalmessages>", file);
	sprintf(data, "%i", total_messages);
	fputs(data, file);
	fputs("</totalmessages>", file);*/
	fputs("</model_run>", file);
	fclose(file);

	
	if(code != 0)
	{
		printf("*** Error: ");
		if(code == 100) printf("cannot handle specified number of space partitions");
		if(code == 101) printf("could not find number of space partitions config in file");
		
		printf(" ***");
		exit(0);
	}
}


/** \fn void propagate_agents()
 * \brief Check agent positions to see if any need to be moved to a another node.
 */
void propagate_agents()
{
/*	node_information * node_info;
	xmachine * before_xmachine, * temp_xmachine;
	xmachine ** p_temp_xmachine;
	double x_xmachine, y_xmachine, z_xmachine;
	current_xmachine = *p_xmachine;
	before_xmachine = NULL;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_Firm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Firm->0.0;
			y_xmachine = current_xmachine->xmachine_Firm->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Bank->0.0;
			y_xmachine = current_xmachine->xmachine_Bank->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Dummy != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Dummy->0.0;
			y_xmachine = current_xmachine->xmachine_Dummy->0.0;
			z_xmachine = 0.0;
		}
		
		if(x_xmachine < current_node->partition_data[0] ||
		   x_xmachine > current_node->partition_data[1] ||
		   y_xmachine < current_node->partition_data[2] ||
		   y_xmachine > current_node->partition_data[3] ||
		   z_xmachine < current_node->partition_data[4] ||
		   z_xmachine > current_node->partition_data[5])
		{
			node_info = *p_node_info;
			while(node_info)
			{
				if(node_info->node_id != current_node->node_id &&
				node_info->partition_data[0] < x_xmachine && node_info->partition_data[1] > x_xmachine &&
				node_info->partition_data[2] < y_xmachine && node_info->partition_data[3] > y_xmachine &&
				node_info->partition_data[4] < z_xmachine && node_info->partition_data[5] > z_xmachine)
				{
                    // Remove agent
                    if(before_xmachine) before_xmachine->next = current_xmachine->next;
                    else *p_xmachine = current_xmachine->next;
                    current_node->agent_total--;
                    // Add agent
                    p_temp_xmachine = &node_info->agents;
                    temp_xmachine = *p_temp_xmachine;
                    current_xmachine->next = temp_xmachine;
                    *p_temp_xmachine = current_xmachine;
                    node_info->agent_total++;
                    node_info = NULL;
				}
				else node_info = node_info->next;
				}
			}
			else before_xmachine = current_xmachine;
			
			if(before_xmachine) current_xmachine = before_xmachine->next;
			else current_xmachine = NULL;
		}*/
}


/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
void init_int_array(int_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (int *)malloc(ARRAY_BLOCK_SIZE * sizeof(int));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_int_array(int_array * array)
{
	(*array).size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_int_array(int_array * array)
{
	free((*array).array);
}

void copy_int_array(int_array * from, int_array * to)
{
	int i;
	//to = init_int_array();
	
	for (i = 0; i < (*from).size; i++)
	{
		add_int(to, (*from).array[i]);
	}
}

/** \fn void sort_int_array(int_array * array)
* \brief Sort the elements of a dynamic integer array with smallest first.
* \param array Pointer to the dynamic integer array.
*/
/*void sort_int_array(int_array * array)
{
	int i, j, temp;
	
	for(i=0; i<((*array).size-1); i++)
	{
		for(j=0; j<((*array).size-1)-i; j++) 
		{
			if(*((*array).array+j+1) < *((*array).array+j))
			{
                temp = *((*array).(*array)+j); 
                *((*array).array+j) = *((*array).array+j+1);
                *((*array).array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_int(int *array, int elements)
 *  \brief Sorts the elements of the integer array in ascending order.
 *  \param Pointer to integer array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_int(int array, int elements)
{
	#define  LEVEL  1000
	int  pivot, begin[LEVEL], end[LEVEL], i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_int(int_array * array, int new_int)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (int *)realloc((*array).array, ((*array).total_size * sizeof(int)));
	}
	(*array).array[(*array).size] = new_int;
	(*array).size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_int(int_array * array, int index)
{
	int i;
	
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_int_array(int_array * array)
 * \brief Print the elements of a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 */
void print_int_array(int_array * array)
{
	int i;
	
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %d", i, (*array).array[i]);
	}
}

/** \fn float_array * init_float_array()
 * \brief Allocate memory for a dynamic float array.
 * \return float_array Pointer to the new dynamic float array.
 */
void init_float_array(float_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (float *)malloc(ARRAY_BLOCK_SIZE * sizeof(float));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_float_array(float_array * array)
* \brief Reset the float array to hold nothing.
* \param array Pointer to the dynamic float array.
*/
void reset_float_array(float_array * array)
{
	(*array).size = 0;
}

/** \fn void free_float_array(float_array * array)
* \brief Free the memory of a dynamic float array.
* \param array Pointer to the dynamic float array.
*/
void free_float_array(float_array * array)
{
	free((*array).array);
}

void copy_float_array(float_array * from, float_array * to)
{
	int i;
	//to = init_float_array();
	
	for (i = 0; i < (*from).size; i++)
	{
		add_float(to, (*from).array[i]);
	}
}

/** \fn void sort_float_array(float_array * array)
* \brief Sort the elements of a dynamic float array with smallest first.
* \param array Pointer to the dynamic float array.
*/
/*void sort_float_array(float_array array)
{
	int i, j;
	float temp;
	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++) 
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j); 
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_float(float *array, int elements)
 *  \brief Sorts the elements of the float array in ascending order.
 *  \param Pointer to float array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_float(float array, int elements)
{
	#define  LEVEL  1000
	int i=0, left, right ;
	float pivot, begin[LEVEL], end[LEVEL];
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_float(float_array * array, float new_float)
* \brief Add an floateger to the dynamic float array.
* \param array Pointer to the dynamic float array.
* \param new_float The float to add
*/
void add_float(float_array * array, float new_float)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (float *)realloc((*array).array, ((*array).total_size * sizeof(float)));
	}
	(*array).array[(*array).size] = new_float;
	(*array).size++;
}

/** \fn void remove_float(float_array * array, int index)
 * \brief Remove an floateger from a dynamic float array.
 * \param array Pointer to the dynamic float array.
 * \param index The index of the float to remove.
 */
void remove_float(float_array * array, int index)
{
	int i;
	
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_float_array(float_array * array)
 * \brief Print the elements of a dynamic float array.
 * \param array Pointer to the dynamic float array.
 */
void print_float_array(float_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prfloats */
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn double_array * init_double_array()
 * \brief Allocate memory for a dynamic double array.
 * \return double_array Pointer to the new dynamic double array.
 */
void init_double_array(double_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (double *)malloc(ARRAY_BLOCK_SIZE * sizeof(double));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_double_array(double_array * array)
* \brief Reset the double array to hold nothing.
* \param array Pointer to the dynamic double array.
*/
void reset_double_array(double_array * array)
{
	(*array).size = 0;
}

/** \fn void free_double_array(double_array * array)
 * \brief Free the memory of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void free_double_array(double_array * array)
{
	free((*array).array);
}

void copy_double_array(double_array * from, double_array * to)
{
	int i;
	//to = init_double_array();
	
	for (i = 0; i < (*from).size; i++)
	{
		add_double(to, (*from).array[i]);
	}
}

/** \fn void sort_double_array(double_array * array)
 * \brief Sort the elements of a dynamic double array with smallest first.
 * \param array Pointer to the dynamic double array.
 */
/*void sort_double_array(double_array array)
{
	int i, j;
	double temp;
	
	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++) 
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j); 
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_double(double *array, int elements)
 *  \brief Sorts the elements of the double array in ascending order.
 *  \param Pointer to double array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_double(double array, int elements)
{
	#define  LEVEL  1000
	double pivot, begin[LEVEL], end[LEVEL];
	int  i=0, left, right ; 
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_double(double_array * array, double new_double)
 * \brief Add an double to the dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param new_double The double to add
 */
void add_double(double_array * array, double new_double)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (double *)realloc((*array).array, ((*array).total_size * sizeof(double)));
	}
	(*array).array[(*array).size] = new_double;
	(*array).size++;
}

/** \fn void remove_double(double_array * array, int index)
 * \brief Remove an double from a dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param index The index of the double to remove.
 */
void remove_double(double_array * array, int index)
{
	int i;
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_double_array(double_array * array)
 * \brief Print the elements of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void print_double_array(double_array * array)
{
	int i;
	
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn char_array * init_char_array()
 * \brief Allocate memory for a dynamic char array.
 * \return char_array Pointer to the new dynamic char array.
 */
void init_char_array(char_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (char *)malloc(ARRAY_BLOCK_SIZE * sizeof(char));
	CHECK_POINTER((*array).array);
	(*array).array[0] = '\0';
}

/** \fn void reset_char_array(char_array * array)
* \brief Reset the char array to hold nothing.
* \param array Pointer to the dynamic char array.
*/
void reset_char_array(char_array * array)
{
	(*array).size = 0;
}

/** \fn void free_char_array(char_array * array)
 * \brief Free the memory of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void free_char_array(char_array * array)
{
	free((*array).array);
}

void copy_char_array(char_array * from, char_array * to)
{
	int i;
	
	for (i = 0; i < (*from).size; i++)
	{
		add_char(to, (*from).array[i]);
	}
}

/** \fn void add_char(char_array * array, char new_char)
 * \brief Add an char to the dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param new_char The char to add
 */
void add_char(char_array * array, char new_char)
{
	if((*array).size + 1 == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (char *)realloc((*array).array, ((*array).total_size * sizeof(char)));
	}
	(*array).array[(*array).size] = new_char;
	(*array).array[(*array).size + 1] = '\0';
	(*array).size++;
}

/** \fn void remove_char(char_array * array, int index)
 * \brief Remove an char from a dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param index The index of the char to remove.
 */
void remove_char(char_array * array, int index)
{
	int i;
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn char * copy_array_to_str(char_array * array)
 * \brief Return pointer to string from a char_array.
 * \param array Pointer to the dynamic integer array.
 * \return char Pointer to the new string.
 */
char * copy_array_to_str(char_array * array)
{
	char * new_string = (char *)malloc( ((*array).size + 1) * sizeof(char));
	CHECK_POINTER(new_string);
	return strcpy(new_string, (*array).array);
}

/** \fn void print_char_array(char_array * array)
 * \brief Print the elements of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void print_char_array(char_array * array)
{
	printf("%s", (*array).array);
}

/* Functions for the residual_var_datatype datatype */
/** \fn residual_var_datatype_array * init_residual_var_datatype_array()
 * \brief Allocate memory for a dynamic residual_var_datatype array.
 * \return residual_var_datatype_array Pointer to the new dynamic residual_var_datatype array.
 */
void init_residual_var_datatype_array(residual_var_datatype_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (residual_var_datatype *)malloc(ARRAY_BLOCK_SIZE * sizeof(residual_var_datatype));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_residual_var_datatype_array(residual_var_datatype_array* array)
* \brief Reset the residual_var_datatype array to hold nothing.
* \param array Pointer to the dynamic residual_var_datatype array.
*/
void reset_residual_var_datatype_array(residual_var_datatype_array * array)
{
	(*array).size = 0;
}

/** \fn void free_residual_var_datatype_array(residual_var_datatype_array * array)
* \brief Free the memory of a dynamic residual_var_datatype array.
* \param array Pointer to the dynamic residual_var_datatype array.
*/
void free_residual_var_datatype_array(residual_var_datatype_array * array)
{
	free((*array).array);
}

void copy_residual_var_datatype_array(residual_var_datatype_array * from, residual_var_datatype_array * to)
{
	int i;
	
	//to = init_residual_var_datatype_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_residual_var_datatype(to, (*from).array[i].value);
	}
}

/** \fn void add_residual_var_datatype(residual_var_datatype_array * array, double value)
* \brief Add an residual_var_datatype to the dynamic residual_var_datatype array.
* \param array Pointer to the dynamic residual_var_datatype array.
* \param new_int The residual_var_datatype to add
*/
void add_residual_var_datatype(residual_var_datatype_array * array, double * value)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (residual_var_datatype *)realloc((*array).array, ((*array).total_size * sizeof(residual_var_datatype)));
	}
	init_residual_var_datatype(&(*array).array[(*array).size]);
	if(value != NULL) memcpy((*array).array[(*array).size].value, value, 10*sizeof(double));

	(*array).size++;
}

/** \fn void remove_residual_var_datatype(residual_var_datatype_array * array, int index)
 * \brief Remove an residual_var_datatype from a dynamic residual_var_datatype array.
 * \param array Pointer to the dynamic residual_var_datatype array.
 * \param index The index of the residual_var_datatype to remove.
 */
void remove_residual_var_datatype(residual_var_datatype_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_residual_var_datatype(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_residual_var_datatype(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the debt_item datatype */
/** \fn debt_item_array * init_debt_item_array()
 * \brief Allocate memory for a dynamic debt_item array.
 * \return debt_item_array Pointer to the new dynamic debt_item array.
 */
void init_debt_item_array(debt_item_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (debt_item *)malloc(ARRAY_BLOCK_SIZE * sizeof(debt_item));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_debt_item_array(debt_item_array* array)
* \brief Reset the debt_item array to hold nothing.
* \param array Pointer to the dynamic debt_item array.
*/
void reset_debt_item_array(debt_item_array * array)
{
	(*array).size = 0;
}

/** \fn void free_debt_item_array(debt_item_array * array)
* \brief Free the memory of a dynamic debt_item array.
* \param array Pointer to the dynamic debt_item array.
*/
void free_debt_item_array(debt_item_array * array)
{
	free((*array).array);
}

void copy_debt_item_array(debt_item_array * from, debt_item_array * to)
{
	int i;
	
	//to = init_debt_item_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_debt_item(to, (*from).array[i].bank_id, (*from).array[i].loan_value, (*from).array[i].interest_rate, (*from).array[i].installment_amount, (*from).array[i].var_per_installment, (*from).array[i].residual_var, (*from).array[i].bad_debt, (*from).array[i].nr_periods_before_repayment);
	}
}

/** \fn void add_debt_item(debt_item_array * array, int bank_id, double loan_value, double interest_rate, double installment_amount, double var_per_installment, double residual_var, double bad_debt, int nr_periods_before_repayment)
* \brief Add an debt_item to the dynamic debt_item array.
* \param array Pointer to the dynamic debt_item array.
* \param new_int The debt_item to add
*/
void add_debt_item(debt_item_array * array, int bank_id, double loan_value, double interest_rate, double installment_amount, double var_per_installment, double residual_var, double bad_debt, int nr_periods_before_repayment)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (debt_item *)realloc((*array).array, ((*array).total_size * sizeof(debt_item)));
	}
	init_debt_item(&(*array).array[(*array).size]);
	(*array).array[(*array).size].bank_id = bank_id;
	(*array).array[(*array).size].loan_value = loan_value;
	(*array).array[(*array).size].interest_rate = interest_rate;
	(*array).array[(*array).size].installment_amount = installment_amount;
	(*array).array[(*array).size].var_per_installment = var_per_installment;
	(*array).array[(*array).size].residual_var = residual_var;
	(*array).array[(*array).size].bad_debt = bad_debt;
	(*array).array[(*array).size].nr_periods_before_repayment = nr_periods_before_repayment;

	(*array).size++;
}

/** \fn void remove_debt_item(debt_item_array * array, int index)
 * \brief Remove an debt_item from a dynamic debt_item array.
 * \param array Pointer to the dynamic debt_item array.
 * \param index The index of the debt_item to remove.
 */
void remove_debt_item(debt_item_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_debt_item(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_debt_item(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the capital_stock_item datatype */
/** \fn capital_stock_item_array * init_capital_stock_item_array()
 * \brief Allocate memory for a dynamic capital_stock_item array.
 * \return capital_stock_item_array Pointer to the new dynamic capital_stock_item array.
 */
void init_capital_stock_item_array(capital_stock_item_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (capital_stock_item *)malloc(ARRAY_BLOCK_SIZE * sizeof(capital_stock_item));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_capital_stock_item_array(capital_stock_item_array* array)
* \brief Reset the capital_stock_item array to hold nothing.
* \param array Pointer to the dynamic capital_stock_item array.
*/
void reset_capital_stock_item_array(capital_stock_item_array * array)
{
	(*array).size = 0;
}

/** \fn void free_capital_stock_item_array(capital_stock_item_array * array)
* \brief Free the memory of a dynamic capital_stock_item array.
* \param array Pointer to the dynamic capital_stock_item array.
*/
void free_capital_stock_item_array(capital_stock_item_array * array)
{
	free((*array).array);
}

void copy_capital_stock_item_array(capital_stock_item_array * from, capital_stock_item_array * to)
{
	int i;
	
	//to = init_capital_stock_item_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_capital_stock_item(to, (*from).array[i].units, (*from).array[i].purchase_price, (*from).array[i].productivity, (*from).array[i].depreciation_units_per_period);
	}
}

/** \fn void add_capital_stock_item(capital_stock_item_array * array, double units, double purchase_price, double productivity, double depreciation_units_per_period)
* \brief Add an capital_stock_item to the dynamic capital_stock_item array.
* \param array Pointer to the dynamic capital_stock_item array.
* \param new_int The capital_stock_item to add
*/
void add_capital_stock_item(capital_stock_item_array * array, double units, double purchase_price, double productivity, double depreciation_units_per_period)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (capital_stock_item *)realloc((*array).array, ((*array).total_size * sizeof(capital_stock_item)));
	}
	init_capital_stock_item(&(*array).array[(*array).size]);
	(*array).array[(*array).size].units = units;
	(*array).array[(*array).size].purchase_price = purchase_price;
	(*array).array[(*array).size].productivity = productivity;
	(*array).array[(*array).size].depreciation_units_per_period = depreciation_units_per_period;

	(*array).size++;
}

/** \fn void remove_capital_stock_item(capital_stock_item_array * array, int index)
 * \brief Remove an capital_stock_item from a dynamic capital_stock_item array.
 * \param array Pointer to the dynamic capital_stock_item array.
 * \param index The index of the capital_stock_item to remove.
 */
void remove_capital_stock_item(capital_stock_item_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_capital_stock_item(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_capital_stock_item(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the mall_info datatype */
/** \fn mall_info_array * init_mall_info_array()
 * \brief Allocate memory for a dynamic mall_info array.
 * \return mall_info_array Pointer to the new dynamic mall_info array.
 */
void init_mall_info_array(mall_info_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (mall_info *)malloc(ARRAY_BLOCK_SIZE * sizeof(mall_info));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_mall_info_array(mall_info_array* array)
* \brief Reset the mall_info array to hold nothing.
* \param array Pointer to the dynamic mall_info array.
*/
void reset_mall_info_array(mall_info_array * array)
{
	(*array).size = 0;
}

/** \fn void free_mall_info_array(mall_info_array * array)
* \brief Free the memory of a dynamic mall_info array.
* \param array Pointer to the dynamic mall_info array.
*/
void free_mall_info_array(mall_info_array * array)
{
	free((*array).array);
}

void copy_mall_info_array(mall_info_array * from, mall_info_array * to)
{
	int i;
	
	//to = init_mall_info_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_mall_info(to, (*from).array[i].mall_id, (*from).array[i].critical_stock, (*from).array[i].current_stock);
	}
}

/** \fn void add_mall_info(mall_info_array * array, int mall_id, double critical_stock, double current_stock)
* \brief Add an mall_info to the dynamic mall_info array.
* \param array Pointer to the dynamic mall_info array.
* \param new_int The mall_info to add
*/
void add_mall_info(mall_info_array * array, int mall_id, double critical_stock, double current_stock)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (mall_info *)realloc((*array).array, ((*array).total_size * sizeof(mall_info)));
	}
	init_mall_info(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].critical_stock = critical_stock;
	(*array).array[(*array).size].current_stock = current_stock;

	(*array).size++;
}

/** \fn void remove_mall_info(mall_info_array * array, int index)
 * \brief Remove an mall_info from a dynamic mall_info array.
 * \param array Pointer to the dynamic mall_info array.
 * \param index The index of the mall_info to remove.
 */
void remove_mall_info(mall_info_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_mall_info(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_mall_info(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}

/** \fn int idle()
 * \brief an idle function for use by agents.
 */
int idle()
{
	return 0;
}
