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
	
	    rc = MB_Clear(b_central_bank_account_update);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'central_bank_account_update' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'central_bank_account_update' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'central_bank_account_update' board is locked\n");
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
	
	    rc = MB_Clear(b_wage_payment);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'wage_payment' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'wage_payment' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'wage_payment' board is locked\n");
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
	
	    rc = MB_Clear(b_quality_price_info_1);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'quality_price_info_1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'quality_price_info_1' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quality_price_info_1' board is locked\n");
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
	
	    rc = MB_Clear(b_quality_price_info_2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'quality_price_info_2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'quality_price_info_2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quality_price_info_2' board is locked\n");
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
	
	    rc = MB_Clear(b_update_mall_stock);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'update_mall_stock' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'update_mall_stock' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'update_mall_stock' board is locked\n");
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
	
	    rc = MB_Clear(b_consumption_request_1);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'consumption_request_1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'consumption_request_1' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'consumption_request_1' board is locked\n");
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
	
	    rc = MB_Clear(b_consumption_request_2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'consumption_request_2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'consumption_request_2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'consumption_request_2' board is locked\n");
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
	
	    rc = MB_Clear(b_accepted_consumption_1);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'accepted_consumption_1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is locked\n");
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
	
	    rc = MB_Clear(b_accepted_consumption_2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'accepted_consumption_2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is locked\n");
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
	
	    rc = MB_Clear(b_sales);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'sales' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'sales' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'sales' board is locked\n");
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
	
	    rc = MB_Clear(b_specific_skill_update);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'specific_skill_update' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'specific_skill_update' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'specific_skill_update' board is locked\n");
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
	
	    rc = MB_Clear(b_daily_revenue_to_bank);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'daily_revenue_to_bank' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'daily_revenue_to_bank' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'daily_revenue_to_bank' board is locked\n");
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
	
	    rc = MB_Clear(b_bankruptcy_illiquidity);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'bankruptcy_illiquidity' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is locked\n");
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
	
	    rc = MB_Clear(b_bankruptcy_insolvency);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'bankruptcy_insolvency' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is locked\n");
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
	
	    rc = MB_Clear(b_infoAssetCH);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'infoAssetCH' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'infoAssetCH' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'infoAssetCH' board is locked\n");
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
	
	    rc = MB_Clear(b_info_firm);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'info_firm' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'info_firm' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'info_firm' board is locked\n");
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
	
	    rc = MB_Clear(b_accountInterest);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'accountInterest' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'accountInterest' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'accountInterest' board is locked\n");
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
	
	    rc = MB_Clear(b_bankAccountUpdate);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'bankAccountUpdate' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'bankAccountUpdate' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'bankAccountUpdate' board is locked\n");
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
	
	    rc = MB_Clear(b_info_bond);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'info_bond' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'info_bond' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'info_bond' board is locked\n");
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
	
	    rc = MB_Clear(b_productivity);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'productivity' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'productivity' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'productivity' board is locked\n");
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
	
	    rc = MB_Clear(b_capital_good_request);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'capital_good_request' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'capital_good_request' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'capital_good_request' board is locked\n");
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
	
	    rc = MB_Clear(b_capital_good_profit_distribution);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'capital_good_profit_distribution' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is locked\n");
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
	
	    rc = MB_Clear(b_capital_good_delivery);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'capital_good_delivery' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'capital_good_delivery' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'capital_good_delivery' board is locked\n");
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
	
	    rc = MB_Clear(b_dividend);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'dividend' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'dividend' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'dividend' board is locked\n");
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
	
	    rc = MB_Clear(b_pay_capital_goods);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'pay_capital_goods' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'pay_capital_goods' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'pay_capital_goods' board is locked\n");
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
	
	    rc = MB_Clear(b_vacancies);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'vacancies' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'vacancies' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'vacancies' board is locked\n");
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
	
	    rc = MB_Clear(b_vacancies2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'vacancies2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'vacancies2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'vacancies2' board is locked\n");
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
	
	    rc = MB_Clear(b_firing);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'firing' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'firing' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firing' board is locked\n");
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
	
	    rc = MB_Clear(b_job_application);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'job_application' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'job_application' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_application' board is locked\n");
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
	
	    rc = MB_Clear(b_job_application2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'job_application2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'job_application2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_application2' board is locked\n");
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
	
	    rc = MB_Clear(b_job_offer);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'job_offer' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'job_offer' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_offer' board is locked\n");
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
	
	    rc = MB_Clear(b_job_offer2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'job_offer2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'job_offer2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_offer2' board is locked\n");
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
	
	    rc = MB_Clear(b_job_acceptance);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'job_acceptance' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'job_acceptance' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_acceptance' board is locked\n");
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
	
	    rc = MB_Clear(b_job_acceptance2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'job_acceptance2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'job_acceptance2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'job_acceptance2' board is locked\n");
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
	
	    rc = MB_Clear(b_application_rejection);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'application_rejection' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'application_rejection' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'application_rejection' board is locked\n");
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
	
	    rc = MB_Clear(b_application_rejection2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'application_rejection2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'application_rejection2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'application_rejection2' board is locked\n");
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
	
	    rc = MB_Clear(b_quitting);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'quitting' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'quitting' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
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
	
	    rc = MB_Clear(b_quitting2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'quitting2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'quitting2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'quitting2' board is locked\n");
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
	
	    rc = MB_Clear(b_unemployment_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'unemployment_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'unemployment_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'unemployment_notification' board is locked\n");
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
	
	    rc = MB_Clear(b_policy_announcement);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'policy_announcement' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'policy_announcement' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
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
	
	    rc = MB_Clear(b_hh_transfer_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'hh_transfer_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is locked\n");
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
	
	    rc = MB_Clear(b_hh_subsidy_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'hh_subsidy_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is locked\n");
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
	
	    rc = MB_Clear(b_firm_transfer_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'firm_transfer_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is locked\n");
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
	
	    rc = MB_Clear(b_firm_subsidy_notification);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'firm_subsidy_notification' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is locked\n");
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
	
	    rc = MB_Clear(b_firm_send_data);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'firm_send_data' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'firm_send_data' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'firm_send_data' board is locked\n");
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
	
	    rc = MB_Clear(b_household_send_data);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'household_send_data' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'household_send_data' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'household_send_data' board is locked\n");
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
	
	    rc = MB_Clear(b_mall_data);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'mall_data' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'mall_data' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'mall_data' board is locked\n");
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
	
	    rc = MB_Clear(b_eurostat_send_specific_skills);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'eurostat_send_specific_skills' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is locked\n");
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
	
	    rc = MB_Clear(b_mean_wage_for_government);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'mean_wage_for_government' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'mean_wage_for_government' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'mean_wage_for_government' board is locked\n");
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
	
	    rc = MB_Clear(b_data_for_government);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'data_for_government' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'data_for_government' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'data_for_government' board is locked\n");
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
	//temp_xmachine_Firm_Firm_Start_Macro_Data = NULL;
	Firm_Firm_Start_Macro_Data_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Start_Macro_Data;
	//temp_xmachine_Firm_10 = NULL;
	Firm_10_state = init_Firm_state();//&temp_xmachine_Firm_10;
	//temp_xmachine_Firm_09b = NULL;
	Firm_09b_state = init_Firm_state();//&temp_xmachine_Firm_09b;
	//temp_xmachine_Firm_08 = NULL;
	Firm_08_state = init_Firm_state();//&temp_xmachine_Firm_08;
	//temp_xmachine_Firm_07 = NULL;
	Firm_07_state = init_Firm_state();//&temp_xmachine_Firm_07;
	//temp_xmachine_Firm_09a = NULL;
	Firm_09a_state = init_Firm_state();//&temp_xmachine_Firm_09a;
	//temp_xmachine_Firm_06 = NULL;
	Firm_06_state = init_Firm_state();//&temp_xmachine_Firm_06;
	//temp_xmachine_Firm_03d = NULL;
	Firm_03d_state = init_Firm_state();//&temp_xmachine_Firm_03d;
	//temp_xmachine_Firm_09c = NULL;
	Firm_09c_state = init_Firm_state();//&temp_xmachine_Firm_09c;
	//temp_xmachine_Firm_05b = NULL;
	Firm_05b_state = init_Firm_state();//&temp_xmachine_Firm_05b;
	//temp_xmachine_Firm_05a = NULL;
	Firm_05a_state = init_Firm_state();//&temp_xmachine_Firm_05a;
	//temp_xmachine_Firm_04 = NULL;
	Firm_04_state = init_Firm_state();//&temp_xmachine_Firm_04;
	//temp_xmachine_Firm_03c = NULL;
	Firm_03c_state = init_Firm_state();//&temp_xmachine_Firm_03c;
	//temp_xmachine_Firm_03 = NULL;
	Firm_03_state = init_Firm_state();//&temp_xmachine_Firm_03;
	//temp_xmachine_Firm_011 = NULL;
	Firm_011_state = init_Firm_state();//&temp_xmachine_Firm_011;
	//temp_xmachine_Firm_16 = NULL;
	Firm_16_state = init_Firm_state();//&temp_xmachine_Firm_16;
	//temp_xmachine_Firm_15 = NULL;
	Firm_15_state = init_Firm_state();//&temp_xmachine_Firm_15;
	//temp_xmachine_Firm_Firm_End_Macro_Data = NULL;
	Firm_Firm_End_Macro_Data_state = init_Firm_state();//&temp_xmachine_Firm_Firm_End_Macro_Data;
	//temp_xmachine_Firm_end_Firm = NULL;
	Firm_end_Firm_state = init_Firm_state();//&temp_xmachine_Firm_end_Firm;
	//temp_xmachine_Firm_Firm_bankrupty_state_3 = NULL;
	Firm_Firm_bankrupty_state_3_state = init_Firm_state();//&temp_xmachine_Firm_Firm_bankrupty_state_3;
	//temp_xmachine_Firm_Firm_bankrupty_state_2 = NULL;
	Firm_Firm_bankrupty_state_2_state = init_Firm_state();//&temp_xmachine_Firm_Firm_bankrupty_state_2;
	//temp_xmachine_Firm_Firm_is_active = NULL;
	Firm_Firm_is_active_state = init_Firm_state();//&temp_xmachine_Firm_Firm_is_active;
	//temp_xmachine_Firm_start_Firm = NULL;
	Firm_start_Firm_state = init_Firm_state();//&temp_xmachine_Firm_start_Firm;
	//temp_xmachine_Firm_Firm_bankrupty_state_1 = NULL;
	Firm_Firm_bankrupty_state_1_state = init_Firm_state();//&temp_xmachine_Firm_Firm_bankrupty_state_1;
	//temp_xmachine_Firm_Firm_not_active = NULL;
	Firm_Firm_not_active_state = init_Firm_state();//&temp_xmachine_Firm_Firm_not_active;
	//temp_xmachine_Firm_005 = NULL;
	Firm_005_state = init_Firm_state();//&temp_xmachine_Firm_005;
	//temp_xmachine_Firm_Firm_Start_Public_Sector_Role = NULL;
	Firm_Firm_Start_Public_Sector_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Start_Public_Sector_Role;
	//temp_xmachine_Firm_Firm_End_External_Financing = NULL;
	Firm_Firm_End_External_Financing_state = init_Firm_state();//&temp_xmachine_Firm_Firm_End_External_Financing;
	//temp_xmachine_Firm_Firm_checks_financial_crisis = NULL;
	Firm_Firm_checks_financial_crisis_state = init_Firm_state();//&temp_xmachine_Firm_Firm_checks_financial_crisis;
	//temp_xmachine_Firm_Firm_bankruptcy_checked = NULL;
	Firm_Firm_bankruptcy_checked_state = init_Firm_state();//&temp_xmachine_Firm_Firm_bankruptcy_checked;
	//temp_xmachine_Firm_End_Firm_Financial_Role = NULL;
	Firm_End_Firm_Financial_Role_state = init_Firm_state();//&temp_xmachine_Firm_End_Firm_Financial_Role;
	//temp_xmachine_Firm_0003 = NULL;
	Firm_0003_state = init_Firm_state();//&temp_xmachine_Firm_0003;
	//temp_xmachine_Firm_Firm_Bankruptcy_check = NULL;
	Firm_Firm_Bankruptcy_check_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Bankruptcy_check;
	//temp_xmachine_Firm_004 = NULL;
	Firm_004_state = init_Firm_state();//&temp_xmachine_Firm_004;
	//temp_xmachine_Firm_003 = NULL;
	Firm_003_state = init_Firm_state();//&temp_xmachine_Firm_003;
	//temp_xmachine_Firm_002 = NULL;
	Firm_002_state = init_Firm_state();//&temp_xmachine_Firm_002;
	//temp_xmachine_Firm_001 = NULL;
	Firm_001_state = init_Firm_state();//&temp_xmachine_Firm_001;
	//temp_xmachine_Firm_Firm_End_Credit_Role = NULL;
	Firm_Firm_End_Credit_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_End_Credit_Role;
	//temp_xmachine_Firm_Firm_Credit_02 = NULL;
	Firm_Firm_Credit_02_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Credit_02;
	//temp_xmachine_Firm_Firm_Start_Credit_Role = NULL;
	Firm_Firm_Start_Credit_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Start_Credit_Role;
	//temp_xmachine_Firm_Firm_Start_Financial_Management_Role = NULL;
	Firm_Firm_Start_Financial_Management_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Start_Financial_Management_Role;
	//temp_xmachine_Firm_Firm_End_Financial_Management_Role = NULL;
	Firm_Firm_End_Financial_Management_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_End_Financial_Management_Role;
	//temp_xmachine_Firm_14 = NULL;
	Firm_14_state = init_Firm_state();//&temp_xmachine_Firm_14;
	//temp_xmachine_Firm_Firm_End_Seller_Role = NULL;
	Firm_Firm_End_Seller_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_End_Seller_Role;
	//temp_xmachine_Firm_Firm_Start_Seller_Role = NULL;
	Firm_Firm_Start_Seller_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Start_Seller_Role;
	//temp_xmachine_Firm_12 = NULL;
	Firm_12_state = init_Firm_state();//&temp_xmachine_Firm_12;
	//temp_xmachine_Firm_11 = NULL;
	Firm_11_state = init_Firm_state();//&temp_xmachine_Firm_11;
	//temp_xmachine_Firm_11b = NULL;
	Firm_11b_state = init_Firm_state();//&temp_xmachine_Firm_11b;
	//temp_xmachine_Firm_11a = NULL;
	Firm_11a_state = init_Firm_state();//&temp_xmachine_Firm_11a;
	//temp_xmachine_Firm_Firm_End_Labour_Role = NULL;
	Firm_Firm_End_Labour_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_End_Labour_Role;
	//temp_xmachine_Firm_Firm_Start_Labour_Role = NULL;
	Firm_Firm_Start_Labour_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Start_Labour_Role;
	//temp_xmachine_Firm_Firm_End_Financial_Management = NULL;
	Firm_Firm_End_Financial_Management_state = init_Firm_state();//&temp_xmachine_Firm_Firm_End_Financial_Management;
	//temp_xmachine_Firm_02 = NULL;
	Firm_02_state = init_Firm_state();//&temp_xmachine_Firm_02;
	//temp_xmachine_Firm_00b = NULL;
	Firm_00b_state = init_Firm_state();//&temp_xmachine_Firm_00b;
	//temp_xmachine_Firm_01 = NULL;
	Firm_01_state = init_Firm_state();//&temp_xmachine_Firm_01;
	//temp_xmachine_Firm_Firm_Start_Producer_Role = NULL;
	Firm_Firm_Start_Producer_Role_state = init_Firm_state();//&temp_xmachine_Firm_Firm_Start_Producer_Role;
	//temp_xmachine_Household_end_Household = NULL;
	Household_end_Household_state = init_Household_state();//&temp_xmachine_Household_end_Household;
	//temp_xmachine_Household_Household_Start_Policy_Data = NULL;
	Household_Household_Start_Policy_Data_state = init_Household_state();//&temp_xmachine_Household_Household_Start_Policy_Data;
	//temp_xmachine_Household_start_Household = NULL;
	Household_start_Household_state = init_Household_state();//&temp_xmachine_Household_start_Household;
	//temp_xmachine_Household_08b = NULL;
	Household_08b_state = init_Household_state();//&temp_xmachine_Household_08b;
	//temp_xmachine_Household_08 = NULL;
	Household_08_state = init_Household_state();//&temp_xmachine_Household_08;
	//temp_xmachine_Household_07 = NULL;
	Household_07_state = init_Household_state();//&temp_xmachine_Household_07;
	//temp_xmachine_Household_06e = NULL;
	Household_06e_state = init_Household_state();//&temp_xmachine_Household_06e;
	//temp_xmachine_Household_06d = NULL;
	Household_06d_state = init_Household_state();//&temp_xmachine_Household_06d;
	//temp_xmachine_Household_06c = NULL;
	Household_06c_state = init_Household_state();//&temp_xmachine_Household_06c;
	//temp_xmachine_Household_06b = NULL;
	Household_06b_state = init_Household_state();//&temp_xmachine_Household_06b;
	//temp_xmachine_Household_05 = NULL;
	Household_05_state = init_Household_state();//&temp_xmachine_Household_05;
	//temp_xmachine_Household_04 = NULL;
	Household_04_state = init_Household_state();//&temp_xmachine_Household_04;
	//temp_xmachine_Household_03 = NULL;
	Household_03_state = init_Household_state();//&temp_xmachine_Household_03;
	//temp_xmachine_Household_02 = NULL;
	Household_02_state = init_Household_state();//&temp_xmachine_Household_02;
	//temp_xmachine_Household_06 = NULL;
	Household_06_state = init_Household_state();//&temp_xmachine_Household_06;
	//temp_xmachine_Household_01b = NULL;
	Household_01b_state = init_Household_state();//&temp_xmachine_Household_01b;
	//temp_xmachine_Household_01 = NULL;
	Household_01_state = init_Household_state();//&temp_xmachine_Household_01;
	//temp_xmachine_Household_01a = NULL;
	Household_01a_state = init_Household_state();//&temp_xmachine_Household_01a;
	//temp_xmachine_Household_01d = NULL;
	Household_01d_state = init_Household_state();//&temp_xmachine_Household_01d;
	//temp_xmachine_Household_WAITORDERSTATUS = NULL;
	Household_WAITORDERSTATUS_state = init_Household_state();//&temp_xmachine_Household_WAITORDERSTATUS;
	//temp_xmachine_Household_Household_Start_Labour_Role = NULL;
	Household_Household_Start_Labour_Role_state = init_Household_state();//&temp_xmachine_Household_Household_Start_Labour_Role;
	//temp_xmachine_Household_SEND_ORDERS = NULL;
	Household_SEND_ORDERS_state = init_Household_state();//&temp_xmachine_Household_SEND_ORDERS;
	//temp_xmachine_Household_BOND_BELIEF_FORMATION = NULL;
	Household_BOND_BELIEF_FORMATION_state = init_Household_state();//&temp_xmachine_Household_BOND_BELIEF_FORMATION;
	//temp_xmachine_Household_CHOOSE_TO_TRADE_OR_NOT = NULL;
	Household_CHOOSE_TO_TRADE_OR_NOT_state = init_Household_state();//&temp_xmachine_Household_CHOOSE_TO_TRADE_OR_NOT;
	//temp_xmachine_Household_SELECTSTRATEGY = NULL;
	Household_SELECTSTRATEGY_state = init_Household_state();//&temp_xmachine_Household_SELECTSTRATEGY;
	//temp_xmachine_Household_Household_Start_Financial_Market_Role = NULL;
	Household_Household_Start_Financial_Market_Role_state = init_Household_state();//&temp_xmachine_Household_Household_Start_Financial_Market_Role;
	//temp_xmachine_Household_12 = NULL;
	Household_12_state = init_Household_state();//&temp_xmachine_Household_12;
	//temp_xmachine_Household_14 = NULL;
	Household_14_state = init_Household_state();//&temp_xmachine_Household_14;
	//temp_xmachine_Household_11 = NULL;
	Household_11_state = init_Household_state();//&temp_xmachine_Household_11;
	//temp_xmachine_Household_10 = NULL;
	Household_10_state = init_Household_state();//&temp_xmachine_Household_10;
	//temp_xmachine_Household_15 = NULL;
	Household_15_state = init_Household_state();//&temp_xmachine_Household_15;
	//temp_xmachine_Household_09 = NULL;
	Household_09_state = init_Household_state();//&temp_xmachine_Household_09;
	//temp_xmachine_Mall_end_Mall = NULL;
	Mall_end_Mall_state = init_Mall_state();//&temp_xmachine_Mall_end_Mall;
	//temp_xmachine_Mall_06 = NULL;
	Mall_06_state = init_Mall_state();//&temp_xmachine_Mall_06;
	//temp_xmachine_Mall_05a = NULL;
	Mall_05a_state = init_Mall_state();//&temp_xmachine_Mall_05a;
	//temp_xmachine_Mall_05 = NULL;
	Mall_05_state = init_Mall_state();//&temp_xmachine_Mall_05;
	//temp_xmachine_Mall_04 = NULL;
	Mall_04_state = init_Mall_state();//&temp_xmachine_Mall_04;
	//temp_xmachine_Mall_03 = NULL;
	Mall_03_state = init_Mall_state();//&temp_xmachine_Mall_03;
	//temp_xmachine_Mall_02 = NULL;
	Mall_02_state = init_Mall_state();//&temp_xmachine_Mall_02;
	//temp_xmachine_Mall_01 = NULL;
	Mall_01_state = init_Mall_state();//&temp_xmachine_Mall_01;
	//temp_xmachine_Mall_start_Mall = NULL;
	Mall_start_Mall_state = init_Mall_state();//&temp_xmachine_Mall_start_Mall;
	//temp_xmachine_IGFirm_start_IGFirm = NULL;
	IGFirm_start_IGFirm_state = init_IGFirm_state();//&temp_xmachine_IGFirm_start_IGFirm;
	//temp_xmachine_IGFirm_end_IGFirm = NULL;
	IGFirm_end_IGFirm_state = init_IGFirm_state();//&temp_xmachine_IGFirm_end_IGFirm;
	//temp_xmachine_IGFirm_04b = NULL;
	IGFirm_04b_state = init_IGFirm_state();//&temp_xmachine_IGFirm_04b;
	//temp_xmachine_IGFirm_04 = NULL;
	IGFirm_04_state = init_IGFirm_state();//&temp_xmachine_IGFirm_04;
	//temp_xmachine_IGFirm_03 = NULL;
	IGFirm_03_state = init_IGFirm_state();//&temp_xmachine_IGFirm_03;
	//temp_xmachine_IGFirm_02 = NULL;
	IGFirm_02_state = init_IGFirm_state();//&temp_xmachine_IGFirm_02;
	//temp_xmachine_IGFirm_01 = NULL;
	IGFirm_01_state = init_IGFirm_state();//&temp_xmachine_IGFirm_01;
	//temp_xmachine_IGFirm_Start_IGFirm_Productivity = NULL;
	IGFirm_Start_IGFirm_Productivity_state = init_IGFirm_state();//&temp_xmachine_IGFirm_Start_IGFirm_Productivity;
	//temp_xmachine_Eurostat_end_Eurostat = NULL;
	Eurostat_end_Eurostat_state = init_Eurostat_state();//&temp_xmachine_Eurostat_end_Eurostat;
	//temp_xmachine_Eurostat_Eurostat_Start_EndOfYear_Loop = NULL;
	Eurostat_Eurostat_Start_EndOfYear_Loop_state = init_Eurostat_state();//&temp_xmachine_Eurostat_Eurostat_Start_EndOfYear_Loop;
	//temp_xmachine_Eurostat_05 = NULL;
	Eurostat_05_state = init_Eurostat_state();//&temp_xmachine_Eurostat_05;
	//temp_xmachine_Eurostat_04 = NULL;
	Eurostat_04_state = init_Eurostat_state();//&temp_xmachine_Eurostat_04;
	//temp_xmachine_Eurostat_Eurostat_Start_Quarterly_Loop = NULL;
	Eurostat_Eurostat_Start_Quarterly_Loop_state = init_Eurostat_state();//&temp_xmachine_Eurostat_Eurostat_Start_Quarterly_Loop;
	//temp_xmachine_Eurostat_02 = NULL;
	Eurostat_02_state = init_Eurostat_state();//&temp_xmachine_Eurostat_02;
	//temp_xmachine_Eurostat_Eurostat_Start_Monthly_Loop = NULL;
	Eurostat_Eurostat_Start_Monthly_Loop_state = init_Eurostat_state();//&temp_xmachine_Eurostat_Eurostat_Start_Monthly_Loop;
	//temp_xmachine_Eurostat_01 = NULL;
	Eurostat_01_state = init_Eurostat_state();//&temp_xmachine_Eurostat_01;
	//temp_xmachine_Eurostat_Eurostat_Start_Firm_Data = NULL;
	Eurostat_Eurostat_Start_Firm_Data_state = init_Eurostat_state();//&temp_xmachine_Eurostat_Eurostat_Start_Firm_Data;
	//temp_xmachine_Eurostat_Eurostat_Start_Policy_Data = NULL;
	Eurostat_Eurostat_Start_Policy_Data_state = init_Eurostat_state();//&temp_xmachine_Eurostat_Eurostat_Start_Policy_Data;
	//temp_xmachine_Eurostat_start_Eurostat = NULL;
	Eurostat_start_Eurostat_state = init_Eurostat_state();//&temp_xmachine_Eurostat_start_Eurostat;
	//temp_xmachine_Clearinghouse_end_Clearinghouse = NULL;
	Clearinghouse_end_Clearinghouse_state = init_Clearinghouse_state();//&temp_xmachine_Clearinghouse_end_Clearinghouse;
	//temp_xmachine_Clearinghouse_COMPUTEDPRICES = NULL;
	Clearinghouse_COMPUTEDPRICES_state = init_Clearinghouse_state();//&temp_xmachine_Clearinghouse_COMPUTEDPRICES;
	//temp_xmachine_Clearinghouse_RECEIVEDINFOSTOCK = NULL;
	Clearinghouse_RECEIVEDINFOSTOCK_state = init_Clearinghouse_state();//&temp_xmachine_Clearinghouse_RECEIVEDINFOSTOCK;
	//temp_xmachine_Clearinghouse_start_Clearinghouse = NULL;
	Clearinghouse_start_Clearinghouse_state = init_Clearinghouse_state();//&temp_xmachine_Clearinghouse_start_Clearinghouse;
	//temp_xmachine_Bank_start_Bank = NULL;
	Bank_start_Bank_state = init_Bank_state();//&temp_xmachine_Bank_start_Bank;
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
	//temp_xmachine_Government_end_Government = NULL;
	Government_end_Government_state = init_Government_state();//&temp_xmachine_Government_end_Government;
	//temp_xmachine_Government_09 = NULL;
	Government_09_state = init_Government_state();//&temp_xmachine_Government_09;
	//temp_xmachine_Government_08 = NULL;
	Government_08_state = init_Government_state();//&temp_xmachine_Government_08;
	//temp_xmachine_Government_07 = NULL;
	Government_07_state = init_Government_state();//&temp_xmachine_Government_07;
	//temp_xmachine_Government_06 = NULL;
	Government_06_state = init_Government_state();//&temp_xmachine_Government_06;
	//temp_xmachine_Government_05 = NULL;
	Government_05_state = init_Government_state();//&temp_xmachine_Government_05;
	//temp_xmachine_Government_Gov_Start_Yearly_Loop = NULL;
	Government_Gov_Start_Yearly_Loop_state = init_Government_state();//&temp_xmachine_Government_Gov_Start_Yearly_Loop;
	//temp_xmachine_Government_Gov_Start_Monthly_Loop = NULL;
	Government_Gov_Start_Monthly_Loop_state = init_Government_state();//&temp_xmachine_Government_Gov_Start_Monthly_Loop;
	//temp_xmachine_Government_04 = NULL;
	Government_04_state = init_Government_state();//&temp_xmachine_Government_04;
	//temp_xmachine_Government_03 = NULL;
	Government_03_state = init_Government_state();//&temp_xmachine_Government_03;
	//temp_xmachine_Government_02 = NULL;
	Government_02_state = init_Government_state();//&temp_xmachine_Government_02;
	//temp_xmachine_Government_start_Government = NULL;
	Government_start_Government_state = init_Government_state();//&temp_xmachine_Government_start_Government;
	//temp_xmachine_Government_01 = NULL;
	Government_01_state = init_Government_state();//&temp_xmachine_Government_01;
	//temp_xmachine_Government_GOVERNMENT_PORTFOLIO_UPDATED = NULL;
	Government_GOVERNMENT_PORTFOLIO_UPDATED_state = init_Government_state();//&temp_xmachine_Government_GOVERNMENT_PORTFOLIO_UPDATED;
	//temp_xmachine_Government_GOVERNMENT_SENT_ORDER = NULL;
	Government_GOVERNMENT_SENT_ORDER_state = init_Government_state();//&temp_xmachine_Government_GOVERNMENT_SENT_ORDER;
	//temp_xmachine_Government_GOVERNMENT_IN_DEFICIT = NULL;
	Government_GOVERNMENT_IN_DEFICIT_state = init_Government_state();//&temp_xmachine_Government_GOVERNMENT_IN_DEFICIT;
	//temp_xmachine_Government_GOVERNMENT_SENT_info_bond = NULL;
	Government_GOVERNMENT_SENT_info_bond_state = init_Government_state();//&temp_xmachine_Government_GOVERNMENT_SENT_info_bond;
	//temp_xmachine_Government_Gov_Start_Bond_Market = NULL;
	Government_Gov_Start_Bond_Market_state = init_Government_state();//&temp_xmachine_Government_Gov_Start_Bond_Market;
	//temp_xmachine_Central_Bank_end_Central_Bank = NULL;
	Central_Bank_end_Central_Bank_state = init_Central_Bank_state();//&temp_xmachine_Central_Bank_end_Central_Bank;
	//temp_xmachine_Central_Bank_start_Central_Bank = NULL;
	Central_Bank_start_Central_Bank_state = init_Central_Bank_state();//&temp_xmachine_Central_Bank_start_Central_Bank;


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
	
	    rc = MB_Create(&b_central_bank_account_update, sizeof(m_central_bank_account_update));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'central_bank_account_update' board\n");
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
	
	    rc = MB_Create(&b_wage_payment, sizeof(m_wage_payment));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'wage_payment' board\n");
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
	
	    rc = MB_Create(&b_quality_price_info_1, sizeof(m_quality_price_info_1));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'quality_price_info_1' board\n");
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
	
	    rc = MB_Create(&b_quality_price_info_2, sizeof(m_quality_price_info_2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'quality_price_info_2' board\n");
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
	
	    rc = MB_Create(&b_update_mall_stock, sizeof(m_update_mall_stock));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'update_mall_stock' board\n");
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
	
	    rc = MB_Create(&b_consumption_request_1, sizeof(m_consumption_request_1));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'consumption_request_1' board\n");
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
	
	    rc = MB_Create(&b_consumption_request_2, sizeof(m_consumption_request_2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'consumption_request_2' board\n");
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
	
	    rc = MB_Create(&b_accepted_consumption_1, sizeof(m_accepted_consumption_1));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'accepted_consumption_1' board\n");
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
	
	    rc = MB_Create(&b_accepted_consumption_2, sizeof(m_accepted_consumption_2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'accepted_consumption_2' board\n");
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
	
	    rc = MB_Create(&b_sales, sizeof(m_sales));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'sales' board\n");
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
	
	    rc = MB_Create(&b_specific_skill_update, sizeof(m_specific_skill_update));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'specific_skill_update' board\n");
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
	
	    rc = MB_Create(&b_daily_revenue_to_bank, sizeof(m_daily_revenue_to_bank));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'daily_revenue_to_bank' board\n");
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
	
	    rc = MB_Create(&b_bankruptcy_illiquidity, sizeof(m_bankruptcy_illiquidity));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'bankruptcy_illiquidity' board\n");
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
	
	    rc = MB_Create(&b_bankruptcy_insolvency, sizeof(m_bankruptcy_insolvency));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'bankruptcy_insolvency' board\n");
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
	
	    rc = MB_Create(&b_infoAssetCH, sizeof(m_infoAssetCH));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'infoAssetCH' board\n");
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
	
	    rc = MB_Create(&b_info_firm, sizeof(m_info_firm));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'info_firm' board\n");
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
	
	    rc = MB_Create(&b_accountInterest, sizeof(m_accountInterest));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'accountInterest' board\n");
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
	
	    rc = MB_Create(&b_bankAccountUpdate, sizeof(m_bankAccountUpdate));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'bankAccountUpdate' board\n");
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
	
	    rc = MB_Create(&b_info_bond, sizeof(m_info_bond));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'info_bond' board\n");
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
	
	    rc = MB_Create(&b_productivity, sizeof(m_productivity));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'productivity' board\n");
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
	
	    rc = MB_Create(&b_capital_good_request, sizeof(m_capital_good_request));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'capital_good_request' board\n");
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
	
	    rc = MB_Create(&b_capital_good_profit_distribution, sizeof(m_capital_good_profit_distribution));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'capital_good_profit_distribution' board\n");
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
	
	    rc = MB_Create(&b_capital_good_delivery, sizeof(m_capital_good_delivery));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'capital_good_delivery' board\n");
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
	
	    rc = MB_Create(&b_dividend, sizeof(m_dividend));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'dividend' board\n");
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
	
	    rc = MB_Create(&b_pay_capital_goods, sizeof(m_pay_capital_goods));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'pay_capital_goods' board\n");
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
	
	    rc = MB_Create(&b_vacancies, sizeof(m_vacancies));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'vacancies' board\n");
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
	
	    rc = MB_Create(&b_vacancies2, sizeof(m_vacancies2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'vacancies2' board\n");
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
	
	    rc = MB_Create(&b_firing, sizeof(m_firing));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'firing' board\n");
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
	
	    rc = MB_Create(&b_job_application, sizeof(m_job_application));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_application' board\n");
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
	
	    rc = MB_Create(&b_job_application2, sizeof(m_job_application2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_application2' board\n");
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
	
	    rc = MB_Create(&b_job_offer, sizeof(m_job_offer));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_offer' board\n");
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
	
	    rc = MB_Create(&b_job_offer2, sizeof(m_job_offer2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_offer2' board\n");
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
	
	    rc = MB_Create(&b_job_acceptance, sizeof(m_job_acceptance));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_acceptance' board\n");
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
	
	    rc = MB_Create(&b_job_acceptance2, sizeof(m_job_acceptance2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'job_acceptance2' board\n");
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
	
	    rc = MB_Create(&b_application_rejection, sizeof(m_application_rejection));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'application_rejection' board\n");
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
	
	    rc = MB_Create(&b_application_rejection2, sizeof(m_application_rejection2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'application_rejection2' board\n");
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
	
	    rc = MB_Create(&b_quitting, sizeof(m_quitting));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'quitting' board\n");
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
	
	    rc = MB_Create(&b_quitting2, sizeof(m_quitting2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'quitting2' board\n");
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
	
	    rc = MB_Create(&b_unemployment_notification, sizeof(m_unemployment_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'unemployment_notification' board\n");
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
	
	    rc = MB_Create(&b_policy_announcement, sizeof(m_policy_announcement));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'policy_announcement' board\n");
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
	
	    rc = MB_Create(&b_hh_transfer_notification, sizeof(m_hh_transfer_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'hh_transfer_notification' board\n");
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
	
	    rc = MB_Create(&b_hh_subsidy_notification, sizeof(m_hh_subsidy_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'hh_subsidy_notification' board\n");
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
	
	    rc = MB_Create(&b_firm_transfer_notification, sizeof(m_firm_transfer_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'firm_transfer_notification' board\n");
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
	
	    rc = MB_Create(&b_firm_subsidy_notification, sizeof(m_firm_subsidy_notification));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'firm_subsidy_notification' board\n");
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
	
	    rc = MB_Create(&b_firm_send_data, sizeof(m_firm_send_data));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'firm_send_data' board\n");
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
	
	    rc = MB_Create(&b_household_send_data, sizeof(m_household_send_data));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'household_send_data' board\n");
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
	
	    rc = MB_Create(&b_mall_data, sizeof(m_mall_data));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'mall_data' board\n");
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
	
	    rc = MB_Create(&b_eurostat_send_specific_skills, sizeof(m_eurostat_send_specific_skills));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'eurostat_send_specific_skills' board\n");
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
	
	    rc = MB_Create(&b_mean_wage_for_government, sizeof(m_mean_wage_for_government));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'mean_wage_for_government' board\n");
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
	
	    rc = MB_Create(&b_data_for_government, sizeof(m_data_for_government));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'data_for_government' board\n");
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



void init_consumption_goods_offer(consumption_goods_offer * temp)
{
	(*temp).id = 0;
	(*temp).quality = 0.0;
	(*temp).price = 0.0;

}

void init_consumption_goods_offer_static_array(consumption_goods_offer * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_consumption_goods_offer(&array[i]);
}

void free_consumption_goods_offer(consumption_goods_offer * temp)
{

}

void free_consumption_goods_offer_static_array(consumption_goods_offer * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_consumption_goods_offer(&array[i]);
}

void copy_consumption_goods_offer(consumption_goods_offer * from, consumption_goods_offer * to)
{
	(*to).id = (*from).id;
	(*to).quality = (*from).quality;
	(*to).price = (*from).price;
}

void copy_consumption_goods_offer_static_array(consumption_goods_offer * from, consumption_goods_offer * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_consumption_goods_offer(&from[i], &to[i]);
	}
}


void init_consumption_request(consumption_request * temp)
{
	(*temp).worker_id = 0;
	(*temp).consumer_region_id = 0;
	(*temp).firm_id = 0;
	(*temp).quantity = 0.0;

}

void init_consumption_request_static_array(consumption_request * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_consumption_request(&array[i]);
}

void free_consumption_request(consumption_request * temp)
{

}

void free_consumption_request_static_array(consumption_request * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_consumption_request(&array[i]);
}

void copy_consumption_request(consumption_request * from, consumption_request * to)
{
	(*to).worker_id = (*from).worker_id;
	(*to).consumer_region_id = (*from).consumer_region_id;
	(*to).firm_id = (*from).firm_id;
	(*to).quantity = (*from).quantity;
}

void copy_consumption_request_static_array(consumption_request * from, consumption_request * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_consumption_request(&from[i], &to[i]);
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


void init_mall_quality_price_info(mall_quality_price_info * temp)
{
	(*temp).mall_id = 0;
	(*temp).firm_id = 0;
	(*temp).mall_region_id = 0;
	(*temp).quality = 0.0;
	(*temp).price = 0.0;
	(*temp).available = 0;

}

void init_mall_quality_price_info_static_array(mall_quality_price_info * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_mall_quality_price_info(&array[i]);
}

void free_mall_quality_price_info(mall_quality_price_info * temp)
{

}

void free_mall_quality_price_info_static_array(mall_quality_price_info * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_mall_quality_price_info(&array[i]);
}

void copy_mall_quality_price_info(mall_quality_price_info * from, mall_quality_price_info * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).firm_id = (*from).firm_id;
	(*to).mall_region_id = (*from).mall_region_id;
	(*to).quality = (*from).quality;
	(*to).price = (*from).price;
	(*to).available = (*from).available;
}

void copy_mall_quality_price_info_static_array(mall_quality_price_info * from, mall_quality_price_info * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_mall_quality_price_info(&from[i], &to[i]);
	}
}


void init_mall_stock(mall_stock * temp)
{
	(*temp).firm_id = 0;
	(*temp).region_id = 0;
	(*temp).stock = 0.0;
	(*temp).price = 0.0;
	(*temp).quality = 0.0;
	(*temp).previous_price = 0.0;

}

void init_mall_stock_static_array(mall_stock * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_mall_stock(&array[i]);
}

void free_mall_stock(mall_stock * temp)
{

}

void free_mall_stock_static_array(mall_stock * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_mall_stock(&array[i]);
}

void copy_mall_stock(mall_stock * from, mall_stock * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).region_id = (*from).region_id;
	(*to).stock = (*from).stock;
	(*to).price = (*from).price;
	(*to).quality = (*from).quality;
	(*to).previous_price = (*from).previous_price;
}

void copy_mall_stock_static_array(mall_stock * from, mall_stock * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_mall_stock(&from[i], &to[i]);
	}
}


void init_delivery_volume_per_mall(delivery_volume_per_mall * temp)
{
	(*temp).mall_id = 0;
	(*temp).quantity = 0.0;
	(*temp).price = 0.0;
	(*temp).quality = 0.0;

}

void init_delivery_volume_per_mall_static_array(delivery_volume_per_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_delivery_volume_per_mall(&array[i]);
}

void free_delivery_volume_per_mall(delivery_volume_per_mall * temp)
{

}

void free_delivery_volume_per_mall_static_array(delivery_volume_per_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_delivery_volume_per_mall(&array[i]);
}

void copy_delivery_volume_per_mall(delivery_volume_per_mall * from, delivery_volume_per_mall * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).quantity = (*from).quantity;
	(*to).price = (*from).price;
	(*to).quality = (*from).quality;
}

void copy_delivery_volume_per_mall_static_array(delivery_volume_per_mall * from, delivery_volume_per_mall * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_delivery_volume_per_mall(&from[i], &to[i]);
	}
}


void init_logit_firm_id(logit_firm_id * temp)
{
	(*temp).logit = 0.0;
	(*temp).firm_id = 0;

}

void init_logit_firm_id_static_array(logit_firm_id * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_logit_firm_id(&array[i]);
}

void free_logit_firm_id(logit_firm_id * temp)
{

}

void free_logit_firm_id_static_array(logit_firm_id * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_logit_firm_id(&array[i]);
}

void copy_logit_firm_id(logit_firm_id * from, logit_firm_id * to)
{
	(*to).logit = (*from).logit;
	(*to).firm_id = (*from).firm_id;
}

void copy_logit_firm_id_static_array(logit_firm_id * from, logit_firm_id * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_logit_firm_id(&from[i], &to[i]);
	}
}


void init_sales_in_mall(sales_in_mall * temp)
{
	(*temp).firm_id = 0;
	(*temp).sales = 0.0;

}

void init_sales_in_mall_static_array(sales_in_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_sales_in_mall(&array[i]);
}

void free_sales_in_mall(sales_in_mall * temp)
{

}

void free_sales_in_mall_static_array(sales_in_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_sales_in_mall(&array[i]);
}

void copy_sales_in_mall(sales_in_mall * from, sales_in_mall * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).sales = (*from).sales;
}

void copy_sales_in_mall_static_array(sales_in_mall * from, sales_in_mall * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_sales_in_mall(&from[i], &to[i]);
	}
}


void init_ordered_quantity(ordered_quantity * temp)
{
	(*temp).firm_id = 0;
	(*temp).quantity = 0.0;
	(*temp).price = 0.0;

}

void init_ordered_quantity_static_array(ordered_quantity * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_ordered_quantity(&array[i]);
}

void free_ordered_quantity(ordered_quantity * temp)
{

}

void free_ordered_quantity_static_array(ordered_quantity * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_ordered_quantity(&array[i]);
}

void copy_ordered_quantity(ordered_quantity * from, ordered_quantity * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).quantity = (*from).quantity;
	(*to).price = (*from).price;
}

void copy_ordered_quantity_static_array(ordered_quantity * from, ordered_quantity * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_ordered_quantity(&from[i], &to[i]);
	}
}


void init_received_quantities(received_quantities * temp)
{
	(*temp).firm_id = 0;
	(*temp).quantity = 0.0;

}

void init_received_quantities_static_array(received_quantities * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_received_quantities(&array[i]);
}

void free_received_quantities(received_quantities * temp)
{

}

void free_received_quantities_static_array(received_quantities * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_received_quantities(&array[i]);
}

void copy_received_quantities(received_quantities * from, received_quantities * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).quantity = (*from).quantity;
}

void copy_received_quantities_static_array(received_quantities * from, received_quantities * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_received_quantities(&from[i], &to[i]);
	}
}


void init_sold_quantities_per_mall(sold_quantities_per_mall * temp)
{
	(*temp).mall_id = 0;
	(*temp).sold_quantity = 0.0;
	(*temp).stock_empty = 0;
	(*temp).estimated_demand = 0.0;

}

void init_sold_quantities_per_mall_static_array(sold_quantities_per_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_sold_quantities_per_mall(&array[i]);
}

void free_sold_quantities_per_mall(sold_quantities_per_mall * temp)
{

}

void free_sold_quantities_per_mall_static_array(sold_quantities_per_mall * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_sold_quantities_per_mall(&array[i]);
}

void copy_sold_quantities_per_mall(sold_quantities_per_mall * from, sold_quantities_per_mall * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).sold_quantity = (*from).sold_quantity;
	(*to).stock_empty = (*from).stock_empty;
	(*to).estimated_demand = (*from).estimated_demand;
}

void copy_sold_quantities_per_mall_static_array(sold_quantities_per_mall * from, sold_quantities_per_mall * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_sold_quantities_per_mall(&from[i], &to[i]);
	}
}


void init_sales_statistics(sales_statistics * temp)
{
	(*temp).mall_id = 0;
	(*temp).period = 0;
	(*temp).sales = 0.0;

}

void init_sales_statistics_static_array(sales_statistics * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_sales_statistics(&array[i]);
}

void free_sales_statistics(sales_statistics * temp)
{

}

void free_sales_statistics_static_array(sales_statistics * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_sales_statistics(&array[i]);
}

void copy_sales_statistics(sales_statistics * from, sales_statistics * to)
{
	(*to).mall_id = (*from).mall_id;
	(*to).period = (*from).period;
	(*to).sales = (*from).sales;
}

void copy_sales_statistics_static_array(sales_statistics * from, sales_statistics * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_sales_statistics(&from[i], &to[i]);
	}
}


void init_financing_capital(financing_capital * temp)
{
	(*temp).financing_per_month = 0.0;
	(*temp).nr_periods_before_repayment = 0;

}

void init_financing_capital_static_array(financing_capital * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_financing_capital(&array[i]);
}

void free_financing_capital(financing_capital * temp)
{

}

void free_financing_capital_static_array(financing_capital * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_financing_capital(&array[i]);
}

void copy_financing_capital(financing_capital * from, financing_capital * to)
{
	(*to).financing_per_month = (*from).financing_per_month;
	(*to).nr_periods_before_repayment = (*from).nr_periods_before_repayment;
}

void copy_financing_capital_static_array(financing_capital * from, financing_capital * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_financing_capital(&from[i], &to[i]);
	}
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


void init_account_item(account_item * temp)
{
	(*temp).id = 0;
	(*temp).payment_account = 0.0;

}

void init_account_item_static_array(account_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_account_item(&array[i]);
}

void free_account_item(account_item * temp)
{

}

void free_account_item_static_array(account_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_account_item(&array[i]);
}

void copy_account_item(account_item * from, account_item * to)
{
	(*to).id = (*from).id;
	(*to).payment_account = (*from).payment_account;
}

void copy_account_item_static_array(account_item * from, account_item * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_account_item(&from[i], &to[i]);
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


void init_Order(Order * temp)
{
	(*temp).issuer = 0;
	(*temp).quantity = 0;
	(*temp).price = 0.0;
	(*temp).assetId = 0;

}

void init_Order_static_array(Order * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_Order(&array[i]);
}

void free_Order(Order * temp)
{

}

void free_Order_static_array(Order * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_Order(&array[i]);
}

void copy_Order(Order * from, Order * to)
{
	(*to).issuer = (*from).issuer;
	(*to).quantity = (*from).quantity;
	(*to).price = (*from).price;
	(*to).assetId = (*from).assetId;
}

void copy_Order_static_array(Order * from, Order * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_Order(&from[i], &to[i]);
	}
}


void init_Belief(Belief * temp)
{
	(*temp).asset_id = 0;
	(*temp).expectedPriceReturns = 0.0;
	(*temp).expectedTotalReturns = 0.0;
	(*temp).expectedCashFlowYield = 0.0;
	(*temp).volatility = 0.0;
	(*temp).expectedEarning = 0.0;
	(*temp).expectedEarningPayout = 0.0;
	(*temp).last_price = 0.0;
	(*temp).utility = 0.0;

}

void init_Belief_static_array(Belief * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_Belief(&array[i]);
}

void free_Belief(Belief * temp)
{

}

void free_Belief_static_array(Belief * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_Belief(&array[i]);
}

void copy_Belief(Belief * from, Belief * to)
{
	(*to).asset_id = (*from).asset_id;
	(*to).expectedPriceReturns = (*from).expectedPriceReturns;
	(*to).expectedTotalReturns = (*from).expectedTotalReturns;
	(*to).expectedCashFlowYield = (*from).expectedCashFlowYield;
	(*to).volatility = (*from).volatility;
	(*to).expectedEarning = (*from).expectedEarning;
	(*to).expectedEarningPayout = (*from).expectedEarningPayout;
	(*to).last_price = (*from).last_price;
	(*to).utility = (*from).utility;
}

void copy_Belief_static_array(Belief * from, Belief * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_Belief(&from[i], &to[i]);
	}
}


void init_Stock(Stock * temp)
{
	(*temp).id = 0;
	(*temp).nrOutStandingShares = 0;
	(*temp).index = 0;
	init_double_static_array((*temp).prices, 100);
	init_double_static_array((*temp).returns, 100);

}

void init_Stock_static_array(Stock * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_Stock(&array[i]);
}

void free_Stock(Stock * temp)
{

}

void free_Stock_static_array(Stock * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_Stock(&array[i]);
}

void copy_Stock(Stock * from, Stock * to)
{
	(*to).id = (*from).id;
	(*to).nrOutStandingShares = (*from).nrOutStandingShares;
	(*to).index = (*from).index;
	memcpy((*to).prices, (*from).prices, 100*sizeof(double));
	memcpy((*to).returns, (*from).returns, 100*sizeof(double));
}

void copy_Stock_static_array(Stock * from, Stock * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_Stock(&from[i], &to[i]);
	}
}


void init_Bond(Bond * temp)
{
	(*temp).id = 0;
	(*temp).nr_outstanding = 0;
	(*temp).quantity = 0;
	(*temp).face_value = 0.0;
	(*temp).nominal_yield = 0.0;
	(*temp).maturity_day = 0;
	(*temp).issue_day = 0;
	(*temp).yield2maturity = 0.0;
	init_double_static_array((*temp).prices, 100);
	(*temp).index = 0;
	init_double_static_array((*temp).returns, 100);

}

void init_Bond_static_array(Bond * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_Bond(&array[i]);
}

void free_Bond(Bond * temp)
{

}

void free_Bond_static_array(Bond * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_Bond(&array[i]);
}

void copy_Bond(Bond * from, Bond * to)
{
	(*to).id = (*from).id;
	(*to).nr_outstanding = (*from).nr_outstanding;
	(*to).quantity = (*from).quantity;
	(*to).face_value = (*from).face_value;
	(*to).nominal_yield = (*from).nominal_yield;
	(*to).maturity_day = (*from).maturity_day;
	(*to).issue_day = (*from).issue_day;
	(*to).yield2maturity = (*from).yield2maturity;
	memcpy((*to).prices, (*from).prices, 100*sizeof(double));
	(*to).index = (*from).index;
	memcpy((*to).returns, (*from).returns, 100*sizeof(double));
}

void copy_Bond_static_array(Bond * from, Bond * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_Bond(&from[i], &to[i]);
	}
}


void init_Asset(Asset * temp)
{
	(*temp).id = 0;
	(*temp).quantity = 0;
	(*temp).lastPrice = 0.0;

}

void init_Asset_static_array(Asset * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_Asset(&array[i]);
}

void free_Asset(Asset * temp)
{

}

void free_Asset_static_array(Asset * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_Asset(&array[i]);
}

void copy_Asset(Asset * from, Asset * to)
{
	(*to).id = (*from).id;
	(*to).quantity = (*from).quantity;
	(*to).lastPrice = (*from).lastPrice;
}

void copy_Asset_static_array(Asset * from, Asset * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_Asset(&from[i], &to[i]);
	}
}


void init_ClearingMechanism(ClearingMechanism * temp)
{
	(*temp).lastPrice = 0.0;
	(*temp).quantity = 0;
	init_Order_array(&(*temp).sellOrders);
	init_Order_array(&(*temp).buyOrders);
	init_double_array(&(*temp).prices);

}

void init_ClearingMechanism_static_array(ClearingMechanism * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_ClearingMechanism(&array[i]);
}

void free_ClearingMechanism(ClearingMechanism * temp)
{
	free_Order_array(&(*temp).sellOrders);
	free_Order_array(&(*temp).buyOrders);
	free_double_array(&(*temp).prices);

}

void free_ClearingMechanism_static_array(ClearingMechanism * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_ClearingMechanism(&array[i]);
}

void copy_ClearingMechanism(ClearingMechanism * from, ClearingMechanism * to)
{
	(*to).lastPrice = (*from).lastPrice;
	(*to).quantity = (*from).quantity;
	copy_Order_array(&(*from).sellOrders, &(*to).sellOrders);
	copy_Order_array(&(*from).buyOrders, &(*to).buyOrders);
	copy_double_array(&(*from).prices, &(*to).prices);
}

void copy_ClearingMechanism_static_array(ClearingMechanism * from, ClearingMechanism * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_ClearingMechanism(&from[i], &to[i]);
	}
}


void init_employee(employee * temp)
{
	(*temp).id = 0;
	(*temp).region_id = 0;
	(*temp).wage = 0.0;
	(*temp).general_skill = 0;
	(*temp).specific_skill = 0.0;

}

void init_employee_static_array(employee * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_employee(&array[i]);
}

void free_employee(employee * temp)
{

}

void free_employee_static_array(employee * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_employee(&array[i]);
}

void copy_employee(employee * from, employee * to)
{
	(*to).id = (*from).id;
	(*to).region_id = (*from).region_id;
	(*to).wage = (*from).wage;
	(*to).general_skill = (*from).general_skill;
	(*to).specific_skill = (*from).specific_skill;
}

void copy_employee_static_array(employee * from, employee * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_employee(&from[i], &to[i]);
	}
}


void init_vacancy(vacancy * temp)
{
	(*temp).firm_id = 0;
	(*temp).region_id = 0;
	(*temp).wage_offer = 0.0;

}

void init_vacancy_static_array(vacancy * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_vacancy(&array[i]);
}

void free_vacancy(vacancy * temp)
{

}

void free_vacancy_static_array(vacancy * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_vacancy(&array[i]);
}

void copy_vacancy(vacancy * from, vacancy * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).region_id = (*from).region_id;
	(*to).wage_offer = (*from).wage_offer;
}

void copy_vacancy_static_array(vacancy * from, vacancy * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_vacancy(&from[i], &to[i]);
	}
}


void init_job_application(job_application * temp)
{
	(*temp).worker_id = 0;
	(*temp).region_id = 0;
	(*temp).general_skill = 0;
	(*temp).specific_skill = 0.0;

}

void init_job_application_static_array(job_application * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_job_application(&array[i]);
}

void free_job_application(job_application * temp)
{

}

void free_job_application_static_array(job_application * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_job_application(&array[i]);
}

void copy_job_application(job_application * from, job_application * to)
{
	(*to).worker_id = (*from).worker_id;
	(*to).region_id = (*from).region_id;
	(*to).general_skill = (*from).general_skill;
	(*to).specific_skill = (*from).specific_skill;
}

void copy_job_application_static_array(job_application * from, job_application * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_job_application(&from[i], &to[i]);
	}
}


void init_job_offer(job_offer * temp)
{
	(*temp).firm_id = 0;
	(*temp).region_id = 0;
	(*temp).wage_offer = 0.0;

}

void init_job_offer_static_array(job_offer * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_job_offer(&array[i]);
}

void free_job_offer(job_offer * temp)
{

}

void free_job_offer_static_array(job_offer * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_job_offer(&array[i]);
}

void copy_job_offer(job_offer * from, job_offer * to)
{
	(*to).firm_id = (*from).firm_id;
	(*to).region_id = (*from).region_id;
	(*to).wage_offer = (*from).wage_offer;
}

void copy_job_offer_static_array(job_offer * from, job_offer * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_job_offer(&from[i], &to[i]);
	}
}


void init_logit(logit * temp)
{
	(*temp).logit_value = 0.0;
	(*temp).worker_id = 0;
	(*temp).general_skill = 0;

}

void init_logit_static_array(logit * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_logit(&array[i]);
}

void free_logit(logit * temp)
{

}

void free_logit_static_array(logit * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_logit(&array[i]);
}

void copy_logit(logit * from, logit * to)
{
	(*to).logit_value = (*from).logit_value;
	(*to).worker_id = (*from).worker_id;
	(*to).general_skill = (*from).general_skill;
}

void copy_logit_static_array(logit * from, logit * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_logit(&from[i], &to[i]);
	}
}


void init_household_data(household_data * temp)
{
	(*temp).region_id = 0;
	(*temp).no_households = 0;
	(*temp).no_households_skill_1 = 0;
	(*temp).no_households_skill_2 = 0;
	(*temp).no_households_skill_3 = 0;
	(*temp).no_households_skill_4 = 0;
	(*temp).no_households_skill_5 = 0;
	(*temp).employed = 0;
	(*temp).employed_skill_1 = 0;
	(*temp).employed_skill_2 = 0;
	(*temp).employed_skill_3 = 0;
	(*temp).employed_skill_4 = 0;
	(*temp).employed_skill_5 = 0;
	(*temp).unemployed = 0;
	(*temp).unemployment_rate = 0.0;
	(*temp).unemployment_rate_skill_1 = 0.0;
	(*temp).unemployment_rate_skill_2 = 0.0;
	(*temp).unemployment_rate_skill_3 = 0.0;
	(*temp).unemployment_rate_skill_4 = 0.0;
	(*temp).unemployment_rate_skill_5 = 0.0;
	(*temp).average_wage = 0.0;
	(*temp).average_wage_skill_1 = 0.0;
	(*temp).average_wage_skill_2 = 0.0;
	(*temp).average_wage_skill_3 = 0.0;
	(*temp).average_wage_skill_4 = 0.0;
	(*temp).average_wage_skill_5 = 0.0;
	(*temp).average_s_skill = 0.0;
	(*temp).average_s_skill_1 = 0.0;
	(*temp).average_s_skill_2 = 0.0;
	(*temp).average_s_skill_3 = 0.0;
	(*temp).average_s_skill_4 = 0.0;
	(*temp).average_s_skill_5 = 0.0;

}

void init_household_data_static_array(household_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_household_data(&array[i]);
}

void free_household_data(household_data * temp)
{

}

void free_household_data_static_array(household_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_household_data(&array[i]);
}

void copy_household_data(household_data * from, household_data * to)
{
	(*to).region_id = (*from).region_id;
	(*to).no_households = (*from).no_households;
	(*to).no_households_skill_1 = (*from).no_households_skill_1;
	(*to).no_households_skill_2 = (*from).no_households_skill_2;
	(*to).no_households_skill_3 = (*from).no_households_skill_3;
	(*to).no_households_skill_4 = (*from).no_households_skill_4;
	(*to).no_households_skill_5 = (*from).no_households_skill_5;
	(*to).employed = (*from).employed;
	(*to).employed_skill_1 = (*from).employed_skill_1;
	(*to).employed_skill_2 = (*from).employed_skill_2;
	(*to).employed_skill_3 = (*from).employed_skill_3;
	(*to).employed_skill_4 = (*from).employed_skill_4;
	(*to).employed_skill_5 = (*from).employed_skill_5;
	(*to).unemployed = (*from).unemployed;
	(*to).unemployment_rate = (*from).unemployment_rate;
	(*to).unemployment_rate_skill_1 = (*from).unemployment_rate_skill_1;
	(*to).unemployment_rate_skill_2 = (*from).unemployment_rate_skill_2;
	(*to).unemployment_rate_skill_3 = (*from).unemployment_rate_skill_3;
	(*to).unemployment_rate_skill_4 = (*from).unemployment_rate_skill_4;
	(*to).unemployment_rate_skill_5 = (*from).unemployment_rate_skill_5;
	(*to).average_wage = (*from).average_wage;
	(*to).average_wage_skill_1 = (*from).average_wage_skill_1;
	(*to).average_wage_skill_2 = (*from).average_wage_skill_2;
	(*to).average_wage_skill_3 = (*from).average_wage_skill_3;
	(*to).average_wage_skill_4 = (*from).average_wage_skill_4;
	(*to).average_wage_skill_5 = (*from).average_wage_skill_5;
	(*to).average_s_skill = (*from).average_s_skill;
	(*to).average_s_skill_1 = (*from).average_s_skill_1;
	(*to).average_s_skill_2 = (*from).average_s_skill_2;
	(*to).average_s_skill_3 = (*from).average_s_skill_3;
	(*to).average_s_skill_4 = (*from).average_s_skill_4;
	(*to).average_s_skill_5 = (*from).average_s_skill_5;
}

void copy_household_data_static_array(household_data * from, household_data * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_household_data(&from[i], &to[i]);
	}
}


void init_firm_data(firm_data * temp)
{
	(*temp).region_id = 0;
	(*temp).no_firms = 0;
	(*temp).vacancies = 0;
	(*temp).employees = 0;
	(*temp).employees_skill_1 = 0;
	(*temp).employees_skill_2 = 0;
	(*temp).employees_skill_3 = 0;
	(*temp).employees_skill_4 = 0;
	(*temp).employees_skill_5 = 0;
	(*temp).average_wage = 0.0;
	(*temp).average_wage_skill_1 = 0.0;
	(*temp).average_wage_skill_2 = 0.0;
	(*temp).average_wage_skill_3 = 0.0;
	(*temp).average_wage_skill_4 = 0.0;
	(*temp).average_wage_skill_5 = 0.0;
	(*temp).average_s_skill = 0.0;
	(*temp).average_s_skill_1 = 0.0;
	(*temp).average_s_skill_2 = 0.0;
	(*temp).average_s_skill_3 = 0.0;
	(*temp).average_s_skill_4 = 0.0;
	(*temp).average_s_skill_5 = 0.0;
	(*temp).total_earnings = 0.0;
	(*temp).total_debt = 0.0;
	(*temp).total_assets = 0.0;
	(*temp).total_equity = 0.0;
	(*temp).average_debt_earnings_ratio = 0.0;
	(*temp).average_debt_equity_ratio = 0.0;
	(*temp).labour_share_ratio = 0.0;
	(*temp).monthly_sold_quantity = 0.0;
	(*temp).monthly_output = 0.0;
	(*temp).monthly_revenue = 0.0;
	(*temp).monthly_planned_output = 0.0;
	(*temp).gdp = 0.0;
	(*temp).cpi = 0.0;
	(*temp).cpi_last_month = 0.0;
	(*temp).no_firm_births = 0;
	(*temp).no_firm_deaths = 0;

}

void init_firm_data_static_array(firm_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_firm_data(&array[i]);
}

void free_firm_data(firm_data * temp)
{

}

void free_firm_data_static_array(firm_data * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_firm_data(&array[i]);
}

void copy_firm_data(firm_data * from, firm_data * to)
{
	(*to).region_id = (*from).region_id;
	(*to).no_firms = (*from).no_firms;
	(*to).vacancies = (*from).vacancies;
	(*to).employees = (*from).employees;
	(*to).employees_skill_1 = (*from).employees_skill_1;
	(*to).employees_skill_2 = (*from).employees_skill_2;
	(*to).employees_skill_3 = (*from).employees_skill_3;
	(*to).employees_skill_4 = (*from).employees_skill_4;
	(*to).employees_skill_5 = (*from).employees_skill_5;
	(*to).average_wage = (*from).average_wage;
	(*to).average_wage_skill_1 = (*from).average_wage_skill_1;
	(*to).average_wage_skill_2 = (*from).average_wage_skill_2;
	(*to).average_wage_skill_3 = (*from).average_wage_skill_3;
	(*to).average_wage_skill_4 = (*from).average_wage_skill_4;
	(*to).average_wage_skill_5 = (*from).average_wage_skill_5;
	(*to).average_s_skill = (*from).average_s_skill;
	(*to).average_s_skill_1 = (*from).average_s_skill_1;
	(*to).average_s_skill_2 = (*from).average_s_skill_2;
	(*to).average_s_skill_3 = (*from).average_s_skill_3;
	(*to).average_s_skill_4 = (*from).average_s_skill_4;
	(*to).average_s_skill_5 = (*from).average_s_skill_5;
	(*to).total_earnings = (*from).total_earnings;
	(*to).total_debt = (*from).total_debt;
	(*to).total_assets = (*from).total_assets;
	(*to).total_equity = (*from).total_equity;
	(*to).average_debt_earnings_ratio = (*from).average_debt_earnings_ratio;
	(*to).average_debt_equity_ratio = (*from).average_debt_equity_ratio;
	(*to).labour_share_ratio = (*from).labour_share_ratio;
	(*to).monthly_sold_quantity = (*from).monthly_sold_quantity;
	(*to).monthly_output = (*from).monthly_output;
	(*to).monthly_revenue = (*from).monthly_revenue;
	(*to).monthly_planned_output = (*from).monthly_planned_output;
	(*to).gdp = (*from).gdp;
	(*to).cpi = (*from).cpi;
	(*to).cpi_last_month = (*from).cpi_last_month;
	(*to).no_firm_births = (*from).no_firm_births;
	(*to).no_firm_deaths = (*from).no_firm_deaths;
}

void copy_firm_data_static_array(firm_data * from, firm_data * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_firm_data(&from[i], &to[i]);
	}
}


void init_region_data_item(region_data_item * temp)
{
	(*temp).cpi = 0.0;
	(*temp).cpi_last_month = 0.0;
	(*temp).gdp = 0.0;
	(*temp).output = 0.0;
	(*temp).employment = 0;
	(*temp).unemployment_rate = 0.0;
	(*temp).unemployment_rate_skill_1 = 0.0;
	(*temp).unemployment_rate_skill_2 = 0.0;
	(*temp).unemployment_rate_skill_3 = 0.0;
	(*temp).unemployment_rate_skill_4 = 0.0;
	(*temp).unemployment_rate_skill_5 = 0.0;
	(*temp).average_wage = 0.0;
	(*temp).no_firms = 0;
	(*temp).no_firm_births = 0;
	(*temp).no_firm_deaths = 0;

}

void init_region_data_item_static_array(region_data_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_region_data_item(&array[i]);
}

void free_region_data_item(region_data_item * temp)
{

}

void free_region_data_item_static_array(region_data_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_region_data_item(&array[i]);
}

void copy_region_data_item(region_data_item * from, region_data_item * to)
{
	(*to).cpi = (*from).cpi;
	(*to).cpi_last_month = (*from).cpi_last_month;
	(*to).gdp = (*from).gdp;
	(*to).output = (*from).output;
	(*to).employment = (*from).employment;
	(*to).unemployment_rate = (*from).unemployment_rate;
	(*to).unemployment_rate_skill_1 = (*from).unemployment_rate_skill_1;
	(*to).unemployment_rate_skill_2 = (*from).unemployment_rate_skill_2;
	(*to).unemployment_rate_skill_3 = (*from).unemployment_rate_skill_3;
	(*to).unemployment_rate_skill_4 = (*from).unemployment_rate_skill_4;
	(*to).unemployment_rate_skill_5 = (*from).unemployment_rate_skill_5;
	(*to).average_wage = (*from).average_wage;
	(*to).no_firms = (*from).no_firms;
	(*to).no_firm_births = (*from).no_firm_births;
	(*to).no_firm_deaths = (*from).no_firm_deaths;
}

void copy_region_data_item_static_array(region_data_item * from, region_data_item * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_region_data_item(&from[i], &to[i]);
	}
}


void init_tax_rates_item(tax_rates_item * temp)
{
	(*temp).gov_id = 0;
	(*temp).tax_rate_corporate = 0.0;
	(*temp).tax_rate_hh_labour = 0.0;
	(*temp).tax_rate_hh_capital = 0.0;
	(*temp).tax_rate_vat = 0.0;

}

void init_tax_rates_item_static_array(tax_rates_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_tax_rates_item(&array[i]);
}

void free_tax_rates_item(tax_rates_item * temp)
{

}

void free_tax_rates_item_static_array(tax_rates_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_tax_rates_item(&array[i]);
}

void copy_tax_rates_item(tax_rates_item * from, tax_rates_item * to)
{
	(*to).gov_id = (*from).gov_id;
	(*to).tax_rate_corporate = (*from).tax_rate_corporate;
	(*to).tax_rate_hh_labour = (*from).tax_rate_hh_labour;
	(*to).tax_rate_hh_capital = (*from).tax_rate_hh_capital;
	(*to).tax_rate_vat = (*from).tax_rate_vat;
}

void copy_tax_rates_item_static_array(tax_rates_item * from, tax_rates_item * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_tax_rates_item(&from[i], &to[i]);
	}
}


void init_history_item(history_item * temp)
{
	(*temp).cpi = 0.0;
	(*temp).gdp = 0.0;
	(*temp).output = 0.0;
	(*temp).employment = 0;
	(*temp).unemployment_rate = 0.0;
	(*temp).unemployment_rate_skill_1 = 0.0;
	(*temp).unemployment_rate_skill_2 = 0.0;
	(*temp).unemployment_rate_skill_3 = 0.0;
	(*temp).unemployment_rate_skill_4 = 0.0;
	(*temp).unemployment_rate_skill_5 = 0.0;
	(*temp).average_wage = 0.0;
	(*temp).no_firms = 0;
	(*temp).no_firm_births = 0;
	(*temp).no_firm_deaths = 0;
	init_region_data_item_array(&(*temp).region_data);

}

void init_history_item_static_array(history_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) init_history_item(&array[i]);
}

void free_history_item(history_item * temp)
{
	free_region_data_item_array(&(*temp).region_data);

}

void free_history_item_static_array(history_item * array, int size)
{
	int i;
	
	for(i = 0; i < size; i++) free_history_item(&array[i]);
}

void copy_history_item(history_item * from, history_item * to)
{
	(*to).cpi = (*from).cpi;
	(*to).gdp = (*from).gdp;
	(*to).output = (*from).output;
	(*to).employment = (*from).employment;
	(*to).unemployment_rate = (*from).unemployment_rate;
	(*to).unemployment_rate_skill_1 = (*from).unemployment_rate_skill_1;
	(*to).unemployment_rate_skill_2 = (*from).unemployment_rate_skill_2;
	(*to).unemployment_rate_skill_3 = (*from).unemployment_rate_skill_3;
	(*to).unemployment_rate_skill_4 = (*from).unemployment_rate_skill_4;
	(*to).unemployment_rate_skill_5 = (*from).unemployment_rate_skill_5;
	(*to).average_wage = (*from).average_wage;
	(*to).no_firms = (*from).no_firms;
	(*to).no_firm_births = (*from).no_firm_births;
	(*to).no_firm_deaths = (*from).no_firm_deaths;
	copy_region_data_item_array(&(*from).region_data, &(*to).region_data);
}

void copy_history_item_static_array(history_item * from, history_item * to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_history_item(&from[i], &to[i]);
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
	current->last_day_of_month_to_act = 0;
	current->payment_account = 0.0;
	current->bank_id = 0;
	current->mean_wage = 0.0;
	current->needed_capital_stock = 0.0;
	current->actual_cap_price = 0.0;
	current->mean_specific_skills = 0.0;
	current->planned_production_quantity = 0.0;
	current->production_quantity = 0.0;
	current->planned_output = 0.0;
	current->output = 0.0;
	current->unit_costs = 0.0;
	current->total_supply = 0.0;
	current->production_costs = 0.0;
	current->revenue_per_day = 0.0;
	current->technological_frontier = 0.0;
	current->cum_revenue = 0.0;
	current->out_of_stock_costs = 0.0;
	init_sales_statistics_array(&current->malls_sales_statistics);
	current->quality = 0.0;
	current->price = 0.0;
	current->price_last_month = 0.0;
	current->demand_capital_stock = 0.0;
	current->planned_production_costs = 0.0;
	current->adaption_production_volume_due_to_insufficient_finances = 0.0;
	current->fraction_reserved_for_delayed_payments = 0.0;
	init_sold_quantities_per_mall_array(&current->sold_quantities);
	current->total_sold_quantity = 0.0;
	current->cum_total_sold_quantity = 0.0;
	init_delivery_volume_per_mall_array(&current->delivery_volume);
	init_delivery_volume_per_mall_array(&current->planned_delivery_volume);
	init_mall_info_array(&current->current_mall_stocks);
	init_double_array(&current->last_planned_production_quantities);
	current->total_external_financing_obtained = 0.0;
	current->capital_costs = 0.0;
	current->labour_costs = 0.0;
	init_financing_capital_array(&current->capital_financing);
	current->financial_resources_for_production = 0.0;
	current->planned_value_capital_stock = 0.0;
	current->total_units_local_inventory = 0.0;
	init_int_static_array(current->dmarketmatrix, 10);
	init_residual_var_datatype_static_array(current->residual_var, 10);
	current->ebit = 0.0;
	current->earnings = 0.0;
	current->tax_rate_corporate = 0.0;
	current->tax_rate_vat = 0.0;
	current->tax_payment = 0.0;
	current->net_earnings = 0.0;
	current->previous_net_earnings = 0.0;
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
	current->earnings_per_share = 0.0;
	current->total_payments = 0.0;
	current->total_interest_payments = 0.0;
	current->previous_shares_outstanding = 0.0;
	current->earnings_payout = 0.0;
	current->current_shares_outstanding = 0.0;
	init_Stock(&current->stock);
	init_employee_array(&current->employees);
	current->wage_offer = 0.0;
	current->technology = 0.0;
	current->no_employees = 0;
	current->no_employees_skill_1 = 0;
	current->no_employees_skill_2 = 0;
	current->no_employees_skill_3 = 0;
	current->no_employees_skill_4 = 0;
	current->no_employees_skill_5 = 0;
	current->vacancies = 0;
	current->average_g_skill = 0.0;
	current->average_s_skill_of_1 = 0.0;
	current->average_s_skill_of_2 = 0.0;
	current->average_s_skill_of_3 = 0.0;
	current->average_s_skill_of_4 = 0.0;
	current->average_s_skill_of_5 = 0.0;
	current->wage_offer_for_skill_1 = 0.0;
	current->wage_offer_for_skill_2 = 0.0;
	current->wage_offer_for_skill_3 = 0.0;
	current->wage_offer_for_skill_4 = 0.0;
	current->wage_offer_for_skill_5 = 0.0;
	current->employees_needed = 0;
	current->age = 0;
	current->transfer_payment = 0.0;
	current->subsidy_payment = 0.0;
	current->active = 0;
	current->bankruptcy_idle_counter = 0;
	current->bankruptcy_state = 0;
	current->bankruptcy_insolvency_state = 0;
	current->bankruptcy_illiquidity_state = 0;
	current->financial_crisis_state = 0;
	
	return current;
}

void free_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_sales_statistics_array(&tmp->agent->malls_sales_statistics);
	free_sold_quantities_per_mall_array(&tmp->agent->sold_quantities);
	free_delivery_volume_per_mall_array(&tmp->agent->delivery_volume);
	free_delivery_volume_per_mall_array(&tmp->agent->planned_delivery_volume);
	free_mall_info_array(&tmp->agent->current_mall_stocks);
	free_double_array(&tmp->agent->last_planned_production_quantities);
	free_financing_capital_array(&tmp->agent->capital_financing);
	free_residual_var_datatype_static_array(tmp->agent->residual_var, 10);
	free_debt_item_array(&tmp->agent->loans);
	free_Stock(&tmp->agent->stock);
	free_employee_array(&tmp->agent->employees);
	
	
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
		current_xmachine_Firm->last_day_of_month_to_act = 0;
		current_xmachine_Firm->payment_account = 0.0;
		current_xmachine_Firm->bank_id = 0;
		current_xmachine_Firm->mean_wage = 0.0;
		current_xmachine_Firm->needed_capital_stock = 0.0;
		current_xmachine_Firm->actual_cap_price = 0.0;
		current_xmachine_Firm->mean_specific_skills = 0.0;
		current_xmachine_Firm->planned_production_quantity = 0.0;
		current_xmachine_Firm->production_quantity = 0.0;
		current_xmachine_Firm->planned_output = 0.0;
		current_xmachine_Firm->output = 0.0;
		current_xmachine_Firm->unit_costs = 0.0;
		current_xmachine_Firm->total_supply = 0.0;
		current_xmachine_Firm->production_costs = 0.0;
		current_xmachine_Firm->revenue_per_day = 0.0;
		current_xmachine_Firm->technological_frontier = 0.0;
		current_xmachine_Firm->cum_revenue = 0.0;
		current_xmachine_Firm->out_of_stock_costs = 0.0;
		init_sales_statistics_array(&current_xmachine_Firm->malls_sales_statistics);
		current_xmachine_Firm->quality = 0.0;
		current_xmachine_Firm->price = 0.0;
		current_xmachine_Firm->price_last_month = 0.0;
		current_xmachine_Firm->demand_capital_stock = 0.0;
		current_xmachine_Firm->planned_production_costs = 0.0;
		current_xmachine_Firm->adaption_production_volume_due_to_insufficient_finances = 0.0;
		current_xmachine_Firm->fraction_reserved_for_delayed_payments = 0.0;
		init_sold_quantities_per_mall_array(&current_xmachine_Firm->sold_quantities);
		current_xmachine_Firm->total_sold_quantity = 0.0;
		current_xmachine_Firm->cum_total_sold_quantity = 0.0;
		init_delivery_volume_per_mall_array(&current_xmachine_Firm->delivery_volume);
		init_delivery_volume_per_mall_array(&current_xmachine_Firm->planned_delivery_volume);
		init_mall_info_array(&current_xmachine_Firm->current_mall_stocks);
		init_double_array(&current_xmachine_Firm->last_planned_production_quantities);
		current_xmachine_Firm->total_external_financing_obtained = 0.0;
		current_xmachine_Firm->capital_costs = 0.0;
		current_xmachine_Firm->labour_costs = 0.0;
		init_financing_capital_array(&current_xmachine_Firm->capital_financing);
		current_xmachine_Firm->financial_resources_for_production = 0.0;
		current_xmachine_Firm->planned_value_capital_stock = 0.0;
		current_xmachine_Firm->total_units_local_inventory = 0.0;
		init_int_static_array(current_xmachine_Firm->dmarketmatrix, 10);
		init_residual_var_datatype_static_array(current_xmachine_Firm->residual_var, 10);
		current_xmachine_Firm->ebit = 0.0;
		current_xmachine_Firm->earnings = 0.0;
		current_xmachine_Firm->tax_rate_corporate = 0.0;
		current_xmachine_Firm->tax_rate_vat = 0.0;
		current_xmachine_Firm->tax_payment = 0.0;
		current_xmachine_Firm->net_earnings = 0.0;
		current_xmachine_Firm->previous_net_earnings = 0.0;
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
		current_xmachine_Firm->earnings_per_share = 0.0;
		current_xmachine_Firm->total_payments = 0.0;
		current_xmachine_Firm->total_interest_payments = 0.0;
		current_xmachine_Firm->previous_shares_outstanding = 0.0;
		current_xmachine_Firm->earnings_payout = 0.0;
		current_xmachine_Firm->current_shares_outstanding = 0.0;
		init_Stock(&current_xmachine_Firm->stock);
		init_employee_array(&current_xmachine_Firm->employees);
		current_xmachine_Firm->wage_offer = 0.0;
		current_xmachine_Firm->technology = 0.0;
		current_xmachine_Firm->no_employees = 0;
		current_xmachine_Firm->no_employees_skill_1 = 0;
		current_xmachine_Firm->no_employees_skill_2 = 0;
		current_xmachine_Firm->no_employees_skill_3 = 0;
		current_xmachine_Firm->no_employees_skill_4 = 0;
		current_xmachine_Firm->no_employees_skill_5 = 0;
		current_xmachine_Firm->vacancies = 0;
		current_xmachine_Firm->average_g_skill = 0.0;
		current_xmachine_Firm->average_s_skill_of_1 = 0.0;
		current_xmachine_Firm->average_s_skill_of_2 = 0.0;
		current_xmachine_Firm->average_s_skill_of_3 = 0.0;
		current_xmachine_Firm->average_s_skill_of_4 = 0.0;
		current_xmachine_Firm->average_s_skill_of_5 = 0.0;
		current_xmachine_Firm->wage_offer_for_skill_1 = 0.0;
		current_xmachine_Firm->wage_offer_for_skill_2 = 0.0;
		current_xmachine_Firm->wage_offer_for_skill_3 = 0.0;
		current_xmachine_Firm->wage_offer_for_skill_4 = 0.0;
		current_xmachine_Firm->wage_offer_for_skill_5 = 0.0;
		current_xmachine_Firm->employees_needed = 0;
		current_xmachine_Firm->age = 0;
		current_xmachine_Firm->transfer_payment = 0.0;
		current_xmachine_Firm->subsidy_payment = 0.0;
		current_xmachine_Firm->active = 0;
		current_xmachine_Firm->bankruptcy_idle_counter = 0;
		current_xmachine_Firm->bankruptcy_state = 0;
		current_xmachine_Firm->bankruptcy_insolvency_state = 0;
		current_xmachine_Firm->bankruptcy_illiquidity_state = 0;
		current_xmachine_Firm->financial_crisis_state = 0;
		
}

void unittest_free_Firm_agent()
{
	free_sales_statistics_array(&current_xmachine_Firm->malls_sales_statistics);
	free_sold_quantities_per_mall_array(&current_xmachine_Firm->sold_quantities);
	free_delivery_volume_per_mall_array(&current_xmachine_Firm->delivery_volume);
	free_delivery_volume_per_mall_array(&current_xmachine_Firm->planned_delivery_volume);
	free_mall_info_array(&current_xmachine_Firm->current_mall_stocks);
	free_double_array(&current_xmachine_Firm->last_planned_production_quantities);
	free_financing_capital_array(&current_xmachine_Firm->capital_financing);
	free_residual_var_datatype_static_array(current_xmachine_Firm->residual_var, 10);
	free_debt_item_array(&current_xmachine_Firm->loans);
	free_Stock(&current_xmachine_Firm->stock);
	free_employee_array(&current_xmachine_Firm->employees);
	
	free(current_xmachine_Firm);
}

void free_Firm_agents()
{
	current_xmachine_Firm_holder = Firm_Firm_Start_Macro_Data_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Macro_Data_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_10_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_10_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_09b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_09b_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_08_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_08_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_07_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_07_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_09a_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_09a_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_06_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_06_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_03d_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_03d_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_09c_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_09c_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_05b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_05b_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_05a_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_05a_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_04_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_04_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_03c_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_03c_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_03_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_03_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_011_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_011_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_16_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_16_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_15_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_15_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_End_Macro_Data_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Macro_Data_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_end_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_end_Firm_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_bankrupty_state_3_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_3_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_bankrupty_state_2_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_2_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_is_active_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_is_active_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_start_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_start_Firm_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_bankrupty_state_1_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_bankrupty_state_1_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_not_active_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_not_active_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_005_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_005_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_Start_Public_Sector_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Public_Sector_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_End_External_Financing_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_External_Financing_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_checks_financial_crisis_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_checks_financial_crisis_state);
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
	current_xmachine_Firm_holder = Firm_0003_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_0003_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_Bankruptcy_check_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Bankruptcy_check_state);
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
	current_xmachine_Firm_holder = Firm_Firm_Start_Credit_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Credit_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_Start_Financial_Management_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Financial_Management_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_End_Financial_Management_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Financial_Management_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_14_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_14_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_End_Seller_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Seller_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_Start_Seller_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Seller_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_12_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_12_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_11_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_11_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_11b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_11b_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_11a_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_11a_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_End_Labour_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Labour_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_Start_Labour_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Labour_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_End_Financial_Management_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_End_Financial_Management_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_02_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_02_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_00b_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_00b_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_01_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_01_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
	current_xmachine_Firm_holder = Firm_Firm_Start_Producer_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		temp_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
		free_Firm_agent(current_xmachine_Firm_holder, Firm_Firm_Start_Producer_Role_state);
		current_xmachine_Firm_holder = temp_xmachine_Firm_holder;
	}
}

void free_Firm_states()
{
	free(Firm_Firm_Start_Macro_Data_state);
	free(Firm_10_state);
	free(Firm_09b_state);
	free(Firm_08_state);
	free(Firm_07_state);
	free(Firm_09a_state);
	free(Firm_06_state);
	free(Firm_03d_state);
	free(Firm_09c_state);
	free(Firm_05b_state);
	free(Firm_05a_state);
	free(Firm_04_state);
	free(Firm_03c_state);
	free(Firm_03_state);
	free(Firm_011_state);
	free(Firm_16_state);
	free(Firm_15_state);
	free(Firm_Firm_End_Macro_Data_state);
	free(Firm_end_Firm_state);
	free(Firm_Firm_bankrupty_state_3_state);
	free(Firm_Firm_bankrupty_state_2_state);
	free(Firm_Firm_is_active_state);
	free(Firm_start_Firm_state);
	free(Firm_Firm_bankrupty_state_1_state);
	free(Firm_Firm_not_active_state);
	free(Firm_005_state);
	free(Firm_Firm_Start_Public_Sector_Role_state);
	free(Firm_Firm_End_External_Financing_state);
	free(Firm_Firm_checks_financial_crisis_state);
	free(Firm_Firm_bankruptcy_checked_state);
	free(Firm_End_Firm_Financial_Role_state);
	free(Firm_0003_state);
	free(Firm_Firm_Bankruptcy_check_state);
	free(Firm_004_state);
	free(Firm_003_state);
	free(Firm_002_state);
	free(Firm_001_state);
	free(Firm_Firm_End_Credit_Role_state);
	free(Firm_Firm_Credit_02_state);
	free(Firm_Firm_Start_Credit_Role_state);
	free(Firm_Firm_Start_Financial_Management_Role_state);
	free(Firm_Firm_End_Financial_Management_Role_state);
	free(Firm_14_state);
	free(Firm_Firm_End_Seller_Role_state);
	free(Firm_Firm_Start_Seller_Role_state);
	free(Firm_12_state);
	free(Firm_11_state);
	free(Firm_11b_state);
	free(Firm_11a_state);
	free(Firm_Firm_End_Labour_Role_state);
	free(Firm_Firm_Start_Labour_Role_state);
	free(Firm_Firm_End_Financial_Management_state);
	free(Firm_02_state);
	free(Firm_00b_state);
	free(Firm_01_state);
	free(Firm_Firm_Start_Producer_Role_state);
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

/** \fn void add_Firm_agent(int id, int region_id, int gov_id, int day_of_month_to_act, int last_day_of_month_to_act, double payment_account, int bank_id, double mean_wage, double needed_capital_stock, double actual_cap_price, double mean_specific_skills, double planned_production_quantity, double production_quantity, double planned_output, double output, double unit_costs, double total_supply, double production_costs, double revenue_per_day, double technological_frontier, double cum_revenue, double out_of_stock_costs, sales_statistics_array * malls_sales_statistics, double quality, double price, double price_last_month, double demand_capital_stock, double planned_production_costs, double adaption_production_volume_due_to_insufficient_finances, double fraction_reserved_for_delayed_payments, sold_quantities_per_mall_array * sold_quantities, double total_sold_quantity, double cum_total_sold_quantity, delivery_volume_per_mall_array * delivery_volume, delivery_volume_per_mall_array * planned_delivery_volume, mall_info_array * current_mall_stocks, double_array * last_planned_production_quantities, double total_external_financing_obtained, double capital_costs, double labour_costs, financing_capital_array * capital_financing, double financial_resources_for_production, double planned_value_capital_stock, double total_units_local_inventory, int dmarketmatrix[], residual_var_datatype ** residual_var, double ebit, double earnings, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double net_earnings, double previous_net_earnings, double total_interest_payment, double total_debt_installment_payment, double total_dividend_payment, double current_share_price, double previous_dividend_per_share, double current_dividend_per_share, double previous_earnings_per_share, double current_earnings_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double debt_earnings_ratio, double debt_equity_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, debt_item_array * loans, double total_debt, double total_value_local_inventory, double total_units_capital_stock, double total_value_capital_stock, double total_capital_depreciation_value, double total_capital_depreciation_units, double total_assets, double equity, double production_liquidity_needs, double financial_liquidity_needs, double total_financial_needs, double external_financial_needs, double earnings_per_share, double total_payments, double total_interest_payments, double previous_shares_outstanding, double earnings_payout, double current_shares_outstanding, Stock * stock, employee_array * employees, double wage_offer, double technology, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, int vacancies, double average_g_skill, double average_s_skill_of_1, double average_s_skill_of_2, double average_s_skill_of_3, double average_s_skill_of_4, double average_s_skill_of_5, double wage_offer_for_skill_1, double wage_offer_for_skill_2, double wage_offer_for_skill_3, double wage_offer_for_skill_4, double wage_offer_for_skill_5, int employees_needed, int age, double transfer_payment, double subsidy_payment, int active, int bankruptcy_idle_counter, int bankruptcy_state, int bankruptcy_insolvency_state, int bankruptcy_illiquidity_state, int financial_crisis_state)
 * \brief Add Firm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param gov_id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param last_day_of_month_to_act Variable for the X-machine memory.
 * \param payment_account Variable for the X-machine memory.
 * \param bank_id Variable for the X-machine memory.
 * \param mean_wage Variable for the X-machine memory.
 * \param needed_capital_stock Variable for the X-machine memory.
 * \param actual_cap_price Variable for the X-machine memory.
 * \param mean_specific_skills Variable for the X-machine memory.
 * \param planned_production_quantity Variable for the X-machine memory.
 * \param production_quantity Variable for the X-machine memory.
 * \param planned_output Variable for the X-machine memory.
 * \param output Variable for the X-machine memory.
 * \param unit_costs Variable for the X-machine memory.
 * \param total_supply Variable for the X-machine memory.
 * \param production_costs Variable for the X-machine memory.
 * \param revenue_per_day Variable for the X-machine memory.
 * \param technological_frontier Variable for the X-machine memory.
 * \param cum_revenue Variable for the X-machine memory.
 * \param out_of_stock_costs Variable for the X-machine memory.
 * \param malls_sales_statistics Variable for the X-machine memory.
 * \param quality Variable for the X-machine memory.
 * \param price Variable for the X-machine memory.
 * \param price_last_month Variable for the X-machine memory.
 * \param demand_capital_stock Variable for the X-machine memory.
 * \param planned_production_costs Variable for the X-machine memory.
 * \param adaption_production_volume_due_to_insufficient_finances Variable for the X-machine memory.
 * \param fraction_reserved_for_delayed_payments Variable for the X-machine memory.
 * \param sold_quantities Variable for the X-machine memory.
 * \param total_sold_quantity Variable for the X-machine memory.
 * \param cum_total_sold_quantity Variable for the X-machine memory.
 * \param delivery_volume Variable for the X-machine memory.
 * \param planned_delivery_volume Variable for the X-machine memory.
 * \param current_mall_stocks Variable for the X-machine memory.
 * \param last_planned_production_quantities Variable for the X-machine memory.
 * \param total_external_financing_obtained Variable for the X-machine memory.
 * \param capital_costs Variable for the X-machine memory.
 * \param labour_costs Variable for the X-machine memory.
 * \param capital_financing Variable for the X-machine memory.
 * \param financial_resources_for_production Variable for the X-machine memory.
 * \param planned_value_capital_stock Variable for the X-machine memory.
 * \param total_units_local_inventory Variable for the X-machine memory.
 * \param dmarketmatrix Variable for the X-machine memory.
 * \param residual_var Variable for the X-machine memory.
 * \param ebit Variable for the X-machine memory.
 * \param earnings Variable for the X-machine memory.
 * \param tax_rate_corporate Variable for the X-machine memory.
 * \param tax_rate_vat Variable for the X-machine memory.
 * \param tax_payment Variable for the X-machine memory.
 * \param net_earnings Variable for the X-machine memory.
 * \param previous_net_earnings Variable for the X-machine memory.
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
 * \param earnings_per_share Variable for the X-machine memory.
 * \param total_payments Variable for the X-machine memory.
 * \param total_interest_payments Variable for the X-machine memory.
 * \param previous_shares_outstanding Variable for the X-machine memory.
 * \param earnings_payout Variable for the X-machine memory.
 * \param current_shares_outstanding Variable for the X-machine memory.
 * \param stock Variable for the X-machine memory.
 * \param employees Variable for the X-machine memory.
 * \param wage_offer Variable for the X-machine memory.
 * \param technology Variable for the X-machine memory.
 * \param no_employees Variable for the X-machine memory.
 * \param no_employees_skill_1 Variable for the X-machine memory.
 * \param no_employees_skill_2 Variable for the X-machine memory.
 * \param no_employees_skill_3 Variable for the X-machine memory.
 * \param no_employees_skill_4 Variable for the X-machine memory.
 * \param no_employees_skill_5 Variable for the X-machine memory.
 * \param vacancies Variable for the X-machine memory.
 * \param average_g_skill Variable for the X-machine memory.
 * \param average_s_skill_of_1 Variable for the X-machine memory.
 * \param average_s_skill_of_2 Variable for the X-machine memory.
 * \param average_s_skill_of_3 Variable for the X-machine memory.
 * \param average_s_skill_of_4 Variable for the X-machine memory.
 * \param average_s_skill_of_5 Variable for the X-machine memory.
 * \param wage_offer_for_skill_1 Variable for the X-machine memory.
 * \param wage_offer_for_skill_2 Variable for the X-machine memory.
 * \param wage_offer_for_skill_3 Variable for the X-machine memory.
 * \param wage_offer_for_skill_4 Variable for the X-machine memory.
 * \param wage_offer_for_skill_5 Variable for the X-machine memory.
 * \param employees_needed Variable for the X-machine memory.
 * \param age Variable for the X-machine memory.
 * \param transfer_payment Variable for the X-machine memory.
 * \param subsidy_payment Variable for the X-machine memory.
 * \param active Variable for the X-machine memory.
 * \param bankruptcy_idle_counter Variable for the X-machine memory.
 * \param bankruptcy_state Variable for the X-machine memory.
 * \param bankruptcy_insolvency_state Variable for the X-machine memory.
 * \param bankruptcy_illiquidity_state Variable for the X-machine memory.
 * \param financial_crisis_state Variable for the X-machine memory.
 */
void add_Firm_agent(int id, int region_id, int gov_id, int day_of_month_to_act, int last_day_of_month_to_act, double payment_account, int bank_id, double mean_wage, double needed_capital_stock, double actual_cap_price, double mean_specific_skills, double planned_production_quantity, double production_quantity, double planned_output, double output, double unit_costs, double total_supply, double production_costs, double revenue_per_day, double technological_frontier, double cum_revenue, double out_of_stock_costs, sales_statistics_array * malls_sales_statistics, double quality, double price, double price_last_month, double demand_capital_stock, double planned_production_costs, double adaption_production_volume_due_to_insufficient_finances, double fraction_reserved_for_delayed_payments, sold_quantities_per_mall_array * sold_quantities, double total_sold_quantity, double cum_total_sold_quantity, delivery_volume_per_mall_array * delivery_volume, delivery_volume_per_mall_array * planned_delivery_volume, mall_info_array * current_mall_stocks, double_array * last_planned_production_quantities, double total_external_financing_obtained, double capital_costs, double labour_costs, financing_capital_array * capital_financing, double financial_resources_for_production, double planned_value_capital_stock, double total_units_local_inventory, int dmarketmatrix[], residual_var_datatype residual_var[], double ebit, double earnings, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double net_earnings, double previous_net_earnings, double total_interest_payment, double total_debt_installment_payment, double total_dividend_payment, double current_share_price, double previous_dividend_per_share, double current_dividend_per_share, double previous_earnings_per_share, double current_earnings_per_share, double previous_dividend_per_earnings, double current_dividend_per_earnings, double debt_earnings_ratio, double debt_equity_ratio, double price_earnings_ratio, double retained_earnings_ratio, double earnings_per_share_ratio_growth, double critical_price_earnings_ratio, double critical_earnings_per_share_ratio, debt_item_array * loans, double total_debt, double total_value_local_inventory, double total_units_capital_stock, double total_value_capital_stock, double total_capital_depreciation_value, double total_capital_depreciation_units, double total_assets, double equity, double production_liquidity_needs, double financial_liquidity_needs, double total_financial_needs, double external_financial_needs, double earnings_per_share, double total_payments, double total_interest_payments, double previous_shares_outstanding, double earnings_payout, double current_shares_outstanding, Stock stock, employee_array * employees, double wage_offer, double technology, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, int vacancies, double average_g_skill, double average_s_skill_of_1, double average_s_skill_of_2, double average_s_skill_of_3, double average_s_skill_of_4, double average_s_skill_of_5, double wage_offer_for_skill_1, double wage_offer_for_skill_2, double wage_offer_for_skill_3, double wage_offer_for_skill_4, double wage_offer_for_skill_5, int employees_needed, int age, double transfer_payment, double subsidy_payment, int active, int bankruptcy_idle_counter, int bankruptcy_state, int bankruptcy_insolvency_state, int bankruptcy_illiquidity_state, int financial_crisis_state)
{
	xmachine_memory_Firm * current;
	
	current = init_Firm_agent();
	add_Firm_agent_internal(current, current_xmachine_Firm_next_state);
	
	current->id = id;
	current->region_id = region_id;
	current->gov_id = gov_id;
	current->day_of_month_to_act = day_of_month_to_act;
	current->last_day_of_month_to_act = last_day_of_month_to_act;
	current->payment_account = payment_account;
	current->bank_id = bank_id;
	current->mean_wage = mean_wage;
	current->needed_capital_stock = needed_capital_stock;
	current->actual_cap_price = actual_cap_price;
	current->mean_specific_skills = mean_specific_skills;
	current->planned_production_quantity = planned_production_quantity;
	current->production_quantity = production_quantity;
	current->planned_output = planned_output;
	current->output = output;
	current->unit_costs = unit_costs;
	current->total_supply = total_supply;
	current->production_costs = production_costs;
	current->revenue_per_day = revenue_per_day;
	current->technological_frontier = technological_frontier;
	current->cum_revenue = cum_revenue;
	current->out_of_stock_costs = out_of_stock_costs;
	copy_sales_statistics_array(malls_sales_statistics, &current->malls_sales_statistics);
	current->quality = quality;
	current->price = price;
	current->price_last_month = price_last_month;
	current->demand_capital_stock = demand_capital_stock;
	current->planned_production_costs = planned_production_costs;
	current->adaption_production_volume_due_to_insufficient_finances = adaption_production_volume_due_to_insufficient_finances;
	current->fraction_reserved_for_delayed_payments = fraction_reserved_for_delayed_payments;
	copy_sold_quantities_per_mall_array(sold_quantities, &current->sold_quantities);
	current->total_sold_quantity = total_sold_quantity;
	current->cum_total_sold_quantity = cum_total_sold_quantity;
	copy_delivery_volume_per_mall_array(delivery_volume, &current->delivery_volume);
	copy_delivery_volume_per_mall_array(planned_delivery_volume, &current->planned_delivery_volume);
	copy_mall_info_array(current_mall_stocks, &current->current_mall_stocks);
	copy_double_array(last_planned_production_quantities, &current->last_planned_production_quantities);
	current->total_external_financing_obtained = total_external_financing_obtained;
	current->capital_costs = capital_costs;
	current->labour_costs = labour_costs;
	copy_financing_capital_array(capital_financing, &current->capital_financing);
	current->financial_resources_for_production = financial_resources_for_production;
	current->planned_value_capital_stock = planned_value_capital_stock;
	current->total_units_local_inventory = total_units_local_inventory;
	memcpy(current->dmarketmatrix, dmarketmatrix, 10*sizeof(int));
	copy_residual_var_datatype_static_array(residual_var, current->residual_var, 10);
	current->ebit = ebit;
	current->earnings = earnings;
	current->tax_rate_corporate = tax_rate_corporate;
	current->tax_rate_vat = tax_rate_vat;
	current->tax_payment = tax_payment;
	current->net_earnings = net_earnings;
	current->previous_net_earnings = previous_net_earnings;
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
	current->earnings_per_share = earnings_per_share;
	current->total_payments = total_payments;
	current->total_interest_payments = total_interest_payments;
	current->previous_shares_outstanding = previous_shares_outstanding;
	current->earnings_payout = earnings_payout;
	current->current_shares_outstanding = current_shares_outstanding;
	copy_Stock(&stock, &current->stock);
	copy_employee_array(employees, &current->employees);
	current->wage_offer = wage_offer;
	current->technology = technology;
	current->no_employees = no_employees;
	current->no_employees_skill_1 = no_employees_skill_1;
	current->no_employees_skill_2 = no_employees_skill_2;
	current->no_employees_skill_3 = no_employees_skill_3;
	current->no_employees_skill_4 = no_employees_skill_4;
	current->no_employees_skill_5 = no_employees_skill_5;
	current->vacancies = vacancies;
	current->average_g_skill = average_g_skill;
	current->average_s_skill_of_1 = average_s_skill_of_1;
	current->average_s_skill_of_2 = average_s_skill_of_2;
	current->average_s_skill_of_3 = average_s_skill_of_3;
	current->average_s_skill_of_4 = average_s_skill_of_4;
	current->average_s_skill_of_5 = average_s_skill_of_5;
	current->wage_offer_for_skill_1 = wage_offer_for_skill_1;
	current->wage_offer_for_skill_2 = wage_offer_for_skill_2;
	current->wage_offer_for_skill_3 = wage_offer_for_skill_3;
	current->wage_offer_for_skill_4 = wage_offer_for_skill_4;
	current->wage_offer_for_skill_5 = wage_offer_for_skill_5;
	current->employees_needed = employees_needed;
	current->age = age;
	current->transfer_payment = transfer_payment;
	current->subsidy_payment = subsidy_payment;
	current->active = active;
	current->bankruptcy_idle_counter = bankruptcy_idle_counter;
	current->bankruptcy_state = bankruptcy_state;
	current->bankruptcy_insolvency_state = bankruptcy_insolvency_state;
	current->bankruptcy_illiquidity_state = bankruptcy_illiquidity_state;
	current->financial_crisis_state = financial_crisis_state;
}

xmachine_memory_Household_state * init_Household_state()
{
	xmachine_memory_Household_state * current = (xmachine_memory_Household_state *)malloc(sizeof(xmachine_memory_Household_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Household * init_Household_agent()
{
	xmachine_memory_Household * current = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	init_int_array(&current->neighboring_region_ids);
	current->gov_id = 0;
	current->day_of_month_to_act = 0;
	current->payment_account = 0.0;
	current->bank_id = 0;
	current->consumption_budget = 0.0;
	current->mean_income = 0.0;
	current->week_of_month = 0;
	current->weekly_budget = 0.0;
	current->rationed = 0;
	current->mall_completely_sold_out = 0;
	init_ordered_quantity_static_array(current->order_quantity, 2);
	init_received_quantities_static_array(current->received_quantity, 2);
	current->day_of_week_to_act = 0;
	current->day_of_month_receive_income = 0;
	current->current_productivity_employer = 0.0;
	current->current_mean_specific_skills_employer = 0.0;
	current->total_taxes = 0.0;
	current->cum_total_dividends = 0.0;
	current->tax_rate_hh_capital = 0.0;
	current->tax_rate_hh_labour = 0.0;
	current->price_index = 0.0;
	current->price_index_base_period = 0.0;
	current->commuting_costs_price_level_weight = 0.0;
	init_double_array(&current->last_income);
	current->expenditures = 0.0;
	current->received_dividend = 0.0;
	current->wealth = 0.0;
	init_Belief_array(&current->beliefs);
	init_Order_array(&current->pendingOrders);
	init_Asset_array(&current->assetsowned);
	init_double_array(&current->assetWeights);
	init_double_array(&current->assetUtilities);
	current->cash_on_hand = 0.0;
	current->forwardWindow = 0;
	current->backwardWindow = 0;
	current->bins = 0;
	current->randomWeight = 0.0;
	current->fundamentalWeight = 0.0;
	current->chartistWeight = 0.0;
	current->holdingPeriodToForwardW = 0;
	current->lossaversion = 0.0;
	current->strategy = 0.0;
	current->wage = 0.0;
	current->wage_reservation = 0.0;
	current->general_skill = 0;
	current->on_the_job_search = 0;
	current->number_applications = 0;
	current->last_labour_income = 0.0;
	current->specific_skill = 0.0;
	current->employee_firm_id = 0;
	current->employer_region_id = 0;
	current->day_of_month_receive_benefit = 0;
	current->unemployment_benefit_pct = 0.0;
	current->transfer_payment = 0.0;
	current->subsidy_payment = 0.0;
	
	return current;
}

void free_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_int_array(&tmp->agent->neighboring_region_ids);
	free_ordered_quantity_static_array(tmp->agent->order_quantity, 2);
	free_received_quantities_static_array(tmp->agent->received_quantity, 2);
	free_double_array(&tmp->agent->last_income);
	free_Belief_array(&tmp->agent->beliefs);
	free_Order_array(&tmp->agent->pendingOrders);
	free_Asset_array(&tmp->agent->assetsowned);
	free_double_array(&tmp->agent->assetWeights);
	free_double_array(&tmp->agent->assetUtilities);
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Household_agent()
{
	current_xmachine_Household = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
	CHECK_POINTER(current);
	
		current_xmachine_Household->id = 0;
		current_xmachine_Household->region_id = 0;
		init_int_array(&current_xmachine_Household->neighboring_region_ids);
		current_xmachine_Household->gov_id = 0;
		current_xmachine_Household->day_of_month_to_act = 0;
		current_xmachine_Household->payment_account = 0.0;
		current_xmachine_Household->bank_id = 0;
		current_xmachine_Household->consumption_budget = 0.0;
		current_xmachine_Household->mean_income = 0.0;
		current_xmachine_Household->week_of_month = 0;
		current_xmachine_Household->weekly_budget = 0.0;
		current_xmachine_Household->rationed = 0;
		current_xmachine_Household->mall_completely_sold_out = 0;
		init_ordered_quantity_static_array(current_xmachine_Household->order_quantity, 2);
		init_received_quantities_static_array(current_xmachine_Household->received_quantity, 2);
		current_xmachine_Household->day_of_week_to_act = 0;
		current_xmachine_Household->day_of_month_receive_income = 0;
		current_xmachine_Household->current_productivity_employer = 0.0;
		current_xmachine_Household->current_mean_specific_skills_employer = 0.0;
		current_xmachine_Household->total_taxes = 0.0;
		current_xmachine_Household->cum_total_dividends = 0.0;
		current_xmachine_Household->tax_rate_hh_capital = 0.0;
		current_xmachine_Household->tax_rate_hh_labour = 0.0;
		current_xmachine_Household->price_index = 0.0;
		current_xmachine_Household->price_index_base_period = 0.0;
		current_xmachine_Household->commuting_costs_price_level_weight = 0.0;
		init_double_array(&current_xmachine_Household->last_income);
		current_xmachine_Household->expenditures = 0.0;
		current_xmachine_Household->received_dividend = 0.0;
		current_xmachine_Household->wealth = 0.0;
		init_Belief_array(&current_xmachine_Household->beliefs);
		init_Order_array(&current_xmachine_Household->pendingOrders);
		init_Asset_array(&current_xmachine_Household->assetsowned);
		init_double_array(&current_xmachine_Household->assetWeights);
		init_double_array(&current_xmachine_Household->assetUtilities);
		current_xmachine_Household->cash_on_hand = 0.0;
		current_xmachine_Household->forwardWindow = 0;
		current_xmachine_Household->backwardWindow = 0;
		current_xmachine_Household->bins = 0;
		current_xmachine_Household->randomWeight = 0.0;
		current_xmachine_Household->fundamentalWeight = 0.0;
		current_xmachine_Household->chartistWeight = 0.0;
		current_xmachine_Household->holdingPeriodToForwardW = 0;
		current_xmachine_Household->lossaversion = 0.0;
		current_xmachine_Household->strategy = 0.0;
		current_xmachine_Household->wage = 0.0;
		current_xmachine_Household->wage_reservation = 0.0;
		current_xmachine_Household->general_skill = 0;
		current_xmachine_Household->on_the_job_search = 0;
		current_xmachine_Household->number_applications = 0;
		current_xmachine_Household->last_labour_income = 0.0;
		current_xmachine_Household->specific_skill = 0.0;
		current_xmachine_Household->employee_firm_id = 0;
		current_xmachine_Household->employer_region_id = 0;
		current_xmachine_Household->day_of_month_receive_benefit = 0;
		current_xmachine_Household->unemployment_benefit_pct = 0.0;
		current_xmachine_Household->transfer_payment = 0.0;
		current_xmachine_Household->subsidy_payment = 0.0;
		
}

void unittest_free_Household_agent()
{
	free_int_array(&current_xmachine_Household->neighboring_region_ids);
	free_ordered_quantity_static_array(current_xmachine_Household->order_quantity, 2);
	free_received_quantities_static_array(current_xmachine_Household->received_quantity, 2);
	free_double_array(&current_xmachine_Household->last_income);
	free_Belief_array(&current_xmachine_Household->beliefs);
	free_Order_array(&current_xmachine_Household->pendingOrders);
	free_Asset_array(&current_xmachine_Household->assetsowned);
	free_double_array(&current_xmachine_Household->assetWeights);
	free_double_array(&current_xmachine_Household->assetUtilities);
	
	free(current_xmachine_Household);
}

void free_Household_agents()
{
	current_xmachine_Household_holder = Household_end_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_end_Household_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_Household_Start_Policy_Data_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Policy_Data_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_start_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_start_Household_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_08b_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_08b_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_08_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_08_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_07_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_07_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_06e_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_06e_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_06d_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_06d_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_06c_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_06c_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_06b_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_06b_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_05_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_05_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_04_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_04_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_03_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_03_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_02_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_02_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_06_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_06_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_01b_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_01b_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_01_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_01_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_01a_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_01a_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_01d_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_01d_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_WAITORDERSTATUS_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_WAITORDERSTATUS_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_Household_Start_Labour_Role_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Labour_Role_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_SEND_ORDERS_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_SEND_ORDERS_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_BOND_BELIEF_FORMATION_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_BOND_BELIEF_FORMATION_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_CHOOSE_TO_TRADE_OR_NOT_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_CHOOSE_TO_TRADE_OR_NOT_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_SELECTSTRATEGY_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_SELECTSTRATEGY_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_Household_Start_Financial_Market_Role_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_Household_Start_Financial_Market_Role_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_12_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_12_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_14_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_14_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_11_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_11_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_10_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_10_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_15_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_15_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
	current_xmachine_Household_holder = Household_09_state->agents;
	while(current_xmachine_Household_holder)
	{
		temp_xmachine_Household_holder = current_xmachine_Household_holder->next;
		free_Household_agent(current_xmachine_Household_holder, Household_09_state);
		current_xmachine_Household_holder = temp_xmachine_Household_holder;
	}
}

void free_Household_states()
{
	free(Household_end_Household_state);
	free(Household_Household_Start_Policy_Data_state);
	free(Household_start_Household_state);
	free(Household_08b_state);
	free(Household_08_state);
	free(Household_07_state);
	free(Household_06e_state);
	free(Household_06d_state);
	free(Household_06c_state);
	free(Household_06b_state);
	free(Household_05_state);
	free(Household_04_state);
	free(Household_03_state);
	free(Household_02_state);
	free(Household_06_state);
	free(Household_01b_state);
	free(Household_01_state);
	free(Household_01a_state);
	free(Household_01d_state);
	free(Household_WAITORDERSTATUS_state);
	free(Household_Household_Start_Labour_Role_state);
	free(Household_SEND_ORDERS_state);
	free(Household_BOND_BELIEF_FORMATION_state);
	free(Household_CHOOSE_TO_TRADE_OR_NOT_state);
	free(Household_SELECTSTRATEGY_state);
	free(Household_Household_Start_Financial_Market_Role_state);
	free(Household_12_state);
	free(Household_14_state);
	free(Household_11_state);
	free(Household_10_state);
	free(Household_15_state);
	free(Household_09_state);
}

void transition_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * from_state, xmachine_memory_Household_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Household_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Household_agent_internal(xmachine_memory_Household * agent, xmachine_memory_Household_state * state)
{
	xmachine_memory_Household_holder * current = (xmachine_memory_Household_holder *)malloc(sizeof(xmachine_memory_Household_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Household_agent(int id, int region_id, int_array * neighboring_region_ids, int gov_id, int day_of_month_to_act, double payment_account, int bank_id, double consumption_budget, double mean_income, int week_of_month, double weekly_budget, int rationed, int mall_completely_sold_out, ordered_quantity ** order_quantity, received_quantities ** received_quantity, int day_of_week_to_act, int day_of_month_receive_income, double current_productivity_employer, double current_mean_specific_skills_employer, double total_taxes, double cum_total_dividends, double tax_rate_hh_capital, double tax_rate_hh_labour, double price_index, double price_index_base_period, double commuting_costs_price_level_weight, double_array * last_income, double expenditures, double received_dividend, double wealth, Belief_array * beliefs, Order_array * pendingOrders, Asset_array * assetsowned, double_array * assetWeights, double_array * assetUtilities, double cash_on_hand, int forwardWindow, int backwardWindow, int bins, double randomWeight, double fundamentalWeight, double chartistWeight, int holdingPeriodToForwardW, double lossaversion, double strategy, double wage, double wage_reservation, int general_skill, int on_the_job_search, int number_applications, double last_labour_income, double specific_skill, int employee_firm_id, int employer_region_id, int day_of_month_receive_benefit, double unemployment_benefit_pct, double transfer_payment, double subsidy_payment)
 * \brief Add Household X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param neighboring_region_ids Variable for the X-machine memory.
 * \param gov_id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param payment_account Variable for the X-machine memory.
 * \param bank_id Variable for the X-machine memory.
 * \param consumption_budget Variable for the X-machine memory.
 * \param mean_income Variable for the X-machine memory.
 * \param week_of_month Variable for the X-machine memory.
 * \param weekly_budget Variable for the X-machine memory.
 * \param rationed Variable for the X-machine memory.
 * \param mall_completely_sold_out Variable for the X-machine memory.
 * \param order_quantity Variable for the X-machine memory.
 * \param received_quantity Variable for the X-machine memory.
 * \param day_of_week_to_act Variable for the X-machine memory.
 * \param day_of_month_receive_income Variable for the X-machine memory.
 * \param current_productivity_employer Variable for the X-machine memory.
 * \param current_mean_specific_skills_employer Variable for the X-machine memory.
 * \param total_taxes Variable for the X-machine memory.
 * \param cum_total_dividends Variable for the X-machine memory.
 * \param tax_rate_hh_capital Variable for the X-machine memory.
 * \param tax_rate_hh_labour Variable for the X-machine memory.
 * \param price_index Variable for the X-machine memory.
 * \param price_index_base_period Variable for the X-machine memory.
 * \param commuting_costs_price_level_weight Variable for the X-machine memory.
 * \param last_income Variable for the X-machine memory.
 * \param expenditures Variable for the X-machine memory.
 * \param received_dividend Variable for the X-machine memory.
 * \param wealth Variable for the X-machine memory.
 * \param beliefs Variable for the X-machine memory.
 * \param pendingOrders Variable for the X-machine memory.
 * \param assetsowned Variable for the X-machine memory.
 * \param assetWeights Variable for the X-machine memory.
 * \param assetUtilities Variable for the X-machine memory.
 * \param cash_on_hand Variable for the X-machine memory.
 * \param forwardWindow Variable for the X-machine memory.
 * \param backwardWindow Variable for the X-machine memory.
 * \param bins Variable for the X-machine memory.
 * \param randomWeight Variable for the X-machine memory.
 * \param fundamentalWeight Variable for the X-machine memory.
 * \param chartistWeight Variable for the X-machine memory.
 * \param holdingPeriodToForwardW Variable for the X-machine memory.
 * \param lossaversion Variable for the X-machine memory.
 * \param strategy Variable for the X-machine memory.
 * \param wage Variable for the X-machine memory.
 * \param wage_reservation Variable for the X-machine memory.
 * \param general_skill Variable for the X-machine memory.
 * \param on_the_job_search Variable for the X-machine memory.
 * \param number_applications Variable for the X-machine memory.
 * \param last_labour_income Variable for the X-machine memory.
 * \param specific_skill Variable for the X-machine memory.
 * \param employee_firm_id Variable for the X-machine memory.
 * \param employer_region_id Variable for the X-machine memory.
 * \param day_of_month_receive_benefit Variable for the X-machine memory.
 * \param unemployment_benefit_pct Variable for the X-machine memory.
 * \param transfer_payment Variable for the X-machine memory.
 * \param subsidy_payment Variable for the X-machine memory.
 */
void add_Household_agent(int id, int region_id, int_array * neighboring_region_ids, int gov_id, int day_of_month_to_act, double payment_account, int bank_id, double consumption_budget, double mean_income, int week_of_month, double weekly_budget, int rationed, int mall_completely_sold_out, ordered_quantity order_quantity[], received_quantities received_quantity[], int day_of_week_to_act, int day_of_month_receive_income, double current_productivity_employer, double current_mean_specific_skills_employer, double total_taxes, double cum_total_dividends, double tax_rate_hh_capital, double tax_rate_hh_labour, double price_index, double price_index_base_period, double commuting_costs_price_level_weight, double_array * last_income, double expenditures, double received_dividend, double wealth, Belief_array * beliefs, Order_array * pendingOrders, Asset_array * assetsowned, double_array * assetWeights, double_array * assetUtilities, double cash_on_hand, int forwardWindow, int backwardWindow, int bins, double randomWeight, double fundamentalWeight, double chartistWeight, int holdingPeriodToForwardW, double lossaversion, double strategy, double wage, double wage_reservation, int general_skill, int on_the_job_search, int number_applications, double last_labour_income, double specific_skill, int employee_firm_id, int employer_region_id, int day_of_month_receive_benefit, double unemployment_benefit_pct, double transfer_payment, double subsidy_payment)
{
	xmachine_memory_Household * current;
	
	current = init_Household_agent();
	add_Household_agent_internal(current, current_xmachine_Household_next_state);
	
	current->id = id;
	current->region_id = region_id;
	copy_int_array(neighboring_region_ids, &current->neighboring_region_ids);
	current->gov_id = gov_id;
	current->day_of_month_to_act = day_of_month_to_act;
	current->payment_account = payment_account;
	current->bank_id = bank_id;
	current->consumption_budget = consumption_budget;
	current->mean_income = mean_income;
	current->week_of_month = week_of_month;
	current->weekly_budget = weekly_budget;
	current->rationed = rationed;
	current->mall_completely_sold_out = mall_completely_sold_out;
	copy_ordered_quantity_static_array(order_quantity, current->order_quantity, 2);
	copy_received_quantities_static_array(received_quantity, current->received_quantity, 2);
	current->day_of_week_to_act = day_of_week_to_act;
	current->day_of_month_receive_income = day_of_month_receive_income;
	current->current_productivity_employer = current_productivity_employer;
	current->current_mean_specific_skills_employer = current_mean_specific_skills_employer;
	current->total_taxes = total_taxes;
	current->cum_total_dividends = cum_total_dividends;
	current->tax_rate_hh_capital = tax_rate_hh_capital;
	current->tax_rate_hh_labour = tax_rate_hh_labour;
	current->price_index = price_index;
	current->price_index_base_period = price_index_base_period;
	current->commuting_costs_price_level_weight = commuting_costs_price_level_weight;
	copy_double_array(last_income, &current->last_income);
	current->expenditures = expenditures;
	current->received_dividend = received_dividend;
	current->wealth = wealth;
	copy_Belief_array(beliefs, &current->beliefs);
	copy_Order_array(pendingOrders, &current->pendingOrders);
	copy_Asset_array(assetsowned, &current->assetsowned);
	copy_double_array(assetWeights, &current->assetWeights);
	copy_double_array(assetUtilities, &current->assetUtilities);
	current->cash_on_hand = cash_on_hand;
	current->forwardWindow = forwardWindow;
	current->backwardWindow = backwardWindow;
	current->bins = bins;
	current->randomWeight = randomWeight;
	current->fundamentalWeight = fundamentalWeight;
	current->chartistWeight = chartistWeight;
	current->holdingPeriodToForwardW = holdingPeriodToForwardW;
	current->lossaversion = lossaversion;
	current->strategy = strategy;
	current->wage = wage;
	current->wage_reservation = wage_reservation;
	current->general_skill = general_skill;
	current->on_the_job_search = on_the_job_search;
	current->number_applications = number_applications;
	current->last_labour_income = last_labour_income;
	current->specific_skill = specific_skill;
	current->employee_firm_id = employee_firm_id;
	current->employer_region_id = employer_region_id;
	current->day_of_month_receive_benefit = day_of_month_receive_benefit;
	current->unemployment_benefit_pct = unemployment_benefit_pct;
	current->transfer_payment = transfer_payment;
	current->subsidy_payment = subsidy_payment;
}

xmachine_memory_Mall_state * init_Mall_state()
{
	xmachine_memory_Mall_state * current = (xmachine_memory_Mall_state *)malloc(sizeof(xmachine_memory_Mall_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Mall * init_Mall_agent()
{
	xmachine_memory_Mall * current = (xmachine_memory_Mall *)malloc(sizeof(xmachine_memory_Mall));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	current->gov_id = 0;
	current->no_regions = 0;
	init_mall_stock_array(&current->current_stock);
	init_sales_in_mall_array(&current->firm_revenues);
	current->total_supply = 0.0;
	init_double_static_array(current->export_volume_matrix, 900);
	init_double_static_array(current->export_value_matrix, 900);
	init_double_static_array(current->export_previous_value_matrix, 900);
	
	return current;
}

void free_Mall_agent(xmachine_memory_Mall_holder * tmp, xmachine_memory_Mall_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_mall_stock_array(&tmp->agent->current_stock);
	free_sales_in_mall_array(&tmp->agent->firm_revenues);
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Mall_agent()
{
	current_xmachine_Mall = (xmachine_memory_Mall *)malloc(sizeof(xmachine_memory_Mall));
	CHECK_POINTER(current);
	
		current_xmachine_Mall->id = 0;
		current_xmachine_Mall->region_id = 0;
		current_xmachine_Mall->gov_id = 0;
		current_xmachine_Mall->no_regions = 0;
		init_mall_stock_array(&current_xmachine_Mall->current_stock);
		init_sales_in_mall_array(&current_xmachine_Mall->firm_revenues);
		current_xmachine_Mall->total_supply = 0.0;
		init_double_static_array(current_xmachine_Mall->export_volume_matrix, 900);
		init_double_static_array(current_xmachine_Mall->export_value_matrix, 900);
		init_double_static_array(current_xmachine_Mall->export_previous_value_matrix, 900);
		
}

void unittest_free_Mall_agent()
{
	free_mall_stock_array(&current_xmachine_Mall->current_stock);
	free_sales_in_mall_array(&current_xmachine_Mall->firm_revenues);
	
	free(current_xmachine_Mall);
}

void free_Mall_agents()
{
	current_xmachine_Mall_holder = Mall_end_Mall_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		free_Mall_agent(current_xmachine_Mall_holder, Mall_end_Mall_state);
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	current_xmachine_Mall_holder = Mall_06_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		free_Mall_agent(current_xmachine_Mall_holder, Mall_06_state);
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	current_xmachine_Mall_holder = Mall_05a_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		free_Mall_agent(current_xmachine_Mall_holder, Mall_05a_state);
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	current_xmachine_Mall_holder = Mall_05_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		free_Mall_agent(current_xmachine_Mall_holder, Mall_05_state);
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	current_xmachine_Mall_holder = Mall_04_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		free_Mall_agent(current_xmachine_Mall_holder, Mall_04_state);
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	current_xmachine_Mall_holder = Mall_03_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		free_Mall_agent(current_xmachine_Mall_holder, Mall_03_state);
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	current_xmachine_Mall_holder = Mall_02_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		free_Mall_agent(current_xmachine_Mall_holder, Mall_02_state);
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	current_xmachine_Mall_holder = Mall_01_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		free_Mall_agent(current_xmachine_Mall_holder, Mall_01_state);
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
	current_xmachine_Mall_holder = Mall_start_Mall_state->agents;
	while(current_xmachine_Mall_holder)
	{
		temp_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
		free_Mall_agent(current_xmachine_Mall_holder, Mall_start_Mall_state);
		current_xmachine_Mall_holder = temp_xmachine_Mall_holder;
	}
}

void free_Mall_states()
{
	free(Mall_end_Mall_state);
	free(Mall_06_state);
	free(Mall_05a_state);
	free(Mall_05_state);
	free(Mall_04_state);
	free(Mall_03_state);
	free(Mall_02_state);
	free(Mall_01_state);
	free(Mall_start_Mall_state);
}

void transition_Mall_agent(xmachine_memory_Mall_holder * tmp, xmachine_memory_Mall_state * from_state, xmachine_memory_Mall_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Mall_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Mall_agent_internal(xmachine_memory_Mall * agent, xmachine_memory_Mall_state * state)
{
	xmachine_memory_Mall_holder * current = (xmachine_memory_Mall_holder *)malloc(sizeof(xmachine_memory_Mall_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Mall_agent(int id, int region_id, int gov_id, int no_regions, mall_stock_array * current_stock, sales_in_mall_array * firm_revenues, double total_supply, double export_volume_matrix[], double export_value_matrix[], double export_previous_value_matrix[])
 * \brief Add Mall X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param gov_id Variable for the X-machine memory.
 * \param no_regions Variable for the X-machine memory.
 * \param current_stock Variable for the X-machine memory.
 * \param firm_revenues Variable for the X-machine memory.
 * \param total_supply Variable for the X-machine memory.
 * \param export_volume_matrix Variable for the X-machine memory.
 * \param export_value_matrix Variable for the X-machine memory.
 * \param export_previous_value_matrix Variable for the X-machine memory.
 */
void add_Mall_agent(int id, int region_id, int gov_id, int no_regions, mall_stock_array * current_stock, sales_in_mall_array * firm_revenues, double total_supply, double export_volume_matrix[], double export_value_matrix[], double export_previous_value_matrix[])
{
	xmachine_memory_Mall * current;
	
	current = init_Mall_agent();
	add_Mall_agent_internal(current, current_xmachine_Mall_next_state);
	
	current->id = id;
	current->region_id = region_id;
	current->gov_id = gov_id;
	current->no_regions = no_regions;
	copy_mall_stock_array(current_stock, &current->current_stock);
	copy_sales_in_mall_array(firm_revenues, &current->firm_revenues);
	current->total_supply = total_supply;
	memcpy(current->export_volume_matrix, export_volume_matrix, 900*sizeof(double));
	memcpy(current->export_value_matrix, export_value_matrix, 900*sizeof(double));
	memcpy(current->export_previous_value_matrix, export_previous_value_matrix, 900*sizeof(double));
}

xmachine_memory_IGFirm_state * init_IGFirm_state()
{
	xmachine_memory_IGFirm_state * current = (xmachine_memory_IGFirm_state *)malloc(sizeof(xmachine_memory_IGFirm_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_IGFirm * init_IGFirm_agent()
{
	xmachine_memory_IGFirm * current = (xmachine_memory_IGFirm *)malloc(sizeof(xmachine_memory_IGFirm));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	current->gov_id = 0;
	current->bank_id = 0;
	current->day_of_month_to_act = 0;
	current->payment_account = 0.0;
	current->productivity = 0.0;
	current->capital_good_price = 0.0;
	current->revenue_per_day = 0.0;
	current->tax_rate_corporate = 0.0;
	current->tax_rate_vat = 0.0;
	current->tax_payment = 0.0;
	current->net_profit = 0.0;
	current->outstanding_shares = 0;
	current->current_dividend_per_share = 0.0;
	current->cum_revenues = 0.0;
	current->age = 0;
	current->transfer_payment = 0.0;
	current->subsidy_payment = 0.0;
	
	return current;
}

void free_IGFirm_agent(xmachine_memory_IGFirm_holder * tmp, xmachine_memory_IGFirm_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_IGFirm_agent()
{
	current_xmachine_IGFirm = (xmachine_memory_IGFirm *)malloc(sizeof(xmachine_memory_IGFirm));
	CHECK_POINTER(current);
	
		current_xmachine_IGFirm->id = 0;
		current_xmachine_IGFirm->region_id = 0;
		current_xmachine_IGFirm->gov_id = 0;
		current_xmachine_IGFirm->bank_id = 0;
		current_xmachine_IGFirm->day_of_month_to_act = 0;
		current_xmachine_IGFirm->payment_account = 0.0;
		current_xmachine_IGFirm->productivity = 0.0;
		current_xmachine_IGFirm->capital_good_price = 0.0;
		current_xmachine_IGFirm->revenue_per_day = 0.0;
		current_xmachine_IGFirm->tax_rate_corporate = 0.0;
		current_xmachine_IGFirm->tax_rate_vat = 0.0;
		current_xmachine_IGFirm->tax_payment = 0.0;
		current_xmachine_IGFirm->net_profit = 0.0;
		current_xmachine_IGFirm->outstanding_shares = 0;
		current_xmachine_IGFirm->current_dividend_per_share = 0.0;
		current_xmachine_IGFirm->cum_revenues = 0.0;
		current_xmachine_IGFirm->age = 0;
		current_xmachine_IGFirm->transfer_payment = 0.0;
		current_xmachine_IGFirm->subsidy_payment = 0.0;
		
}

void unittest_free_IGFirm_agent()
{
	
	free(current_xmachine_IGFirm);
}

void free_IGFirm_agents()
{
	current_xmachine_IGFirm_holder = IGFirm_start_IGFirm_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_start_IGFirm_state);
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	current_xmachine_IGFirm_holder = IGFirm_end_IGFirm_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_end_IGFirm_state);
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	current_xmachine_IGFirm_holder = IGFirm_04b_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_04b_state);
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	current_xmachine_IGFirm_holder = IGFirm_04_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_04_state);
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	current_xmachine_IGFirm_holder = IGFirm_03_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_03_state);
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	current_xmachine_IGFirm_holder = IGFirm_02_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_02_state);
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	current_xmachine_IGFirm_holder = IGFirm_01_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_01_state);
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
	current_xmachine_IGFirm_holder = IGFirm_Start_IGFirm_Productivity_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		temp_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
		free_IGFirm_agent(current_xmachine_IGFirm_holder, IGFirm_Start_IGFirm_Productivity_state);
		current_xmachine_IGFirm_holder = temp_xmachine_IGFirm_holder;
	}
}

void free_IGFirm_states()
{
	free(IGFirm_start_IGFirm_state);
	free(IGFirm_end_IGFirm_state);
	free(IGFirm_04b_state);
	free(IGFirm_04_state);
	free(IGFirm_03_state);
	free(IGFirm_02_state);
	free(IGFirm_01_state);
	free(IGFirm_Start_IGFirm_Productivity_state);
}

void transition_IGFirm_agent(xmachine_memory_IGFirm_holder * tmp, xmachine_memory_IGFirm_state * from_state, xmachine_memory_IGFirm_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_IGFirm_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_IGFirm_agent_internal(xmachine_memory_IGFirm * agent, xmachine_memory_IGFirm_state * state)
{
	xmachine_memory_IGFirm_holder * current = (xmachine_memory_IGFirm_holder *)malloc(sizeof(xmachine_memory_IGFirm_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_IGFirm_agent(int id, int region_id, int gov_id, int bank_id, int day_of_month_to_act, double payment_account, double productivity, double capital_good_price, double revenue_per_day, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double net_profit, int outstanding_shares, double current_dividend_per_share, double cum_revenues, int age, double transfer_payment, double subsidy_payment)
 * \brief Add IGFirm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param gov_id Variable for the X-machine memory.
 * \param bank_id Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param payment_account Variable for the X-machine memory.
 * \param productivity Variable for the X-machine memory.
 * \param capital_good_price Variable for the X-machine memory.
 * \param revenue_per_day Variable for the X-machine memory.
 * \param tax_rate_corporate Variable for the X-machine memory.
 * \param tax_rate_vat Variable for the X-machine memory.
 * \param tax_payment Variable for the X-machine memory.
 * \param net_profit Variable for the X-machine memory.
 * \param outstanding_shares Variable for the X-machine memory.
 * \param current_dividend_per_share Variable for the X-machine memory.
 * \param cum_revenues Variable for the X-machine memory.
 * \param age Variable for the X-machine memory.
 * \param transfer_payment Variable for the X-machine memory.
 * \param subsidy_payment Variable for the X-machine memory.
 */
void add_IGFirm_agent(int id, int region_id, int gov_id, int bank_id, int day_of_month_to_act, double payment_account, double productivity, double capital_good_price, double revenue_per_day, double tax_rate_corporate, double tax_rate_vat, double tax_payment, double net_profit, int outstanding_shares, double current_dividend_per_share, double cum_revenues, int age, double transfer_payment, double subsidy_payment)
{
	xmachine_memory_IGFirm * current;
	
	current = init_IGFirm_agent();
	add_IGFirm_agent_internal(current, current_xmachine_IGFirm_next_state);
	
	current->id = id;
	current->region_id = region_id;
	current->gov_id = gov_id;
	current->bank_id = bank_id;
	current->day_of_month_to_act = day_of_month_to_act;
	current->payment_account = payment_account;
	current->productivity = productivity;
	current->capital_good_price = capital_good_price;
	current->revenue_per_day = revenue_per_day;
	current->tax_rate_corporate = tax_rate_corporate;
	current->tax_rate_vat = tax_rate_vat;
	current->tax_payment = tax_payment;
	current->net_profit = net_profit;
	current->outstanding_shares = outstanding_shares;
	current->current_dividend_per_share = current_dividend_per_share;
	current->cum_revenues = cum_revenues;
	current->age = age;
	current->transfer_payment = transfer_payment;
	current->subsidy_payment = subsidy_payment;
}

xmachine_memory_Eurostat_state * init_Eurostat_state()
{
	xmachine_memory_Eurostat_state * current = (xmachine_memory_Eurostat_state *)malloc(sizeof(xmachine_memory_Eurostat_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Eurostat * init_Eurostat_agent()
{
	xmachine_memory_Eurostat * current = (xmachine_memory_Eurostat *)malloc(sizeof(xmachine_memory_Eurostat));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	current->no_regions = 0;
	current->switch_datastorage = 0;
	current->num_households = 0;
	current->no_households_skill_1 = 0;
	current->no_households_skill_2 = 0;
	current->no_households_skill_3 = 0;
	current->no_households_skill_4 = 0;
	current->no_households_skill_5 = 0;
	current->employed = 0;
	current->employed_skill_1 = 0;
	current->employed_skill_2 = 0;
	current->employed_skill_3 = 0;
	current->employed_skill_4 = 0;
	current->employed_skill_5 = 0;
	current->unemployed = 0;
	current->unemployment_rate = 0.0;
	current->unemployment_rate_skill_1 = 0.0;
	current->unemployment_rate_skill_2 = 0.0;
	current->unemployment_rate_skill_3 = 0.0;
	current->unemployment_rate_skill_4 = 0.0;
	current->unemployment_rate_skill_5 = 0.0;
	current->average_wage = 0.0;
	current->average_wage_skill_1 = 0.0;
	current->average_wage_skill_2 = 0.0;
	current->average_wage_skill_3 = 0.0;
	current->average_wage_skill_4 = 0.0;
	current->average_wage_skill_5 = 0.0;
	current->average_s_skill = 0.0;
	current->average_s_skill_1 = 0.0;
	current->average_s_skill_2 = 0.0;
	current->average_s_skill_3 = 0.0;
	current->average_s_skill_4 = 0.0;
	current->average_s_skill_5 = 0.0;
	current->no_firms = 0;
	current->no_vacancies = 0;
	current->no_employees = 0;
	current->no_employees_skill_1 = 0;
	current->no_employees_skill_2 = 0;
	current->no_employees_skill_3 = 0;
	current->no_employees_skill_4 = 0;
	current->no_employees_skill_5 = 0;
	current->firm_average_wage = 0.0;
	current->firm_average_wage_skill_1 = 0.0;
	current->firm_average_wage_skill_2 = 0.0;
	current->firm_average_wage_skill_3 = 0.0;
	current->firm_average_wage_skill_4 = 0.0;
	current->firm_average_wage_skill_5 = 0.0;
	current->firm_average_s_skill = 0.0;
	current->firm_average_s_skill_1 = 0.0;
	current->firm_average_s_skill_2 = 0.0;
	current->firm_average_s_skill_3 = 0.0;
	current->firm_average_s_skill_4 = 0.0;
	current->firm_average_s_skill_5 = 0.0;
	init_firm_data_array(&current->region_firm_data);
	init_household_data_array(&current->region_household_data);
	init_tax_rates_item_static_array(current->government_tax_rates, 27);
	current->total_earnings = 0.0;
	current->total_debt = 0.0;
	current->total_assets = 0.0;
	current->total_equity = 0.0;
	current->average_debt_earnings_ratio = 0.0;
	current->average_debt_equity_ratio = 0.0;
	current->labour_share_ratio = 0.0;
	current->cpi = 0.0;
	current->gdp = 0.0;
	current->monthly_sold_quantity = 0.0;
	current->monthly_output = 0.0;
	current->monthly_revenue = 0.0;
	current->monthly_planned_output = 0.0;
	current->price_index = 0.0;
	init_history_item_static_array(current->history_monthly, 13);
	init_history_item_static_array(current->history_quarterly, 5);
	init_history_item(&current->monthly_growth_rates);
	init_history_item(&current->quarterly_growth_rates);
	init_history_item(&current->annual_growth_rates_monthly);
	init_history_item(&current->annual_growth_rates_quarterly);
	current->no_firm_births = 0;
	current->no_firm_deaths = 0;
	init_int_static_array(current->firm_age_distribution, 60);
	init_int_static_array(current->firm_age_distribution_multiperiod, 720);
	init_int_static_array(current->firm_age_distribution_1_period_lag, 60);
	init_int_static_array(current->firm_age_distribution_2_period_lag, 60);
	current->firm_birth_rate = 0.0;
	current->firm_death_rate = 0.0;
	init_double_static_array(current->survival_rate, 60);
	init_double_static_array(current->survival_rate_multiperiod_1, 60);
	init_double_static_array(current->survival_rate_multiperiod_2, 60);
	init_double_static_array(current->survival_rate_multiperiod, 720);
	current->max_firm_creation = 0;
	current->recession_started = 0;
	current->recession_duration = 0;
	init_double_static_array(current->export_volume_matrix, 900);
	init_double_static_array(current->export_value_matrix, 900);
	init_double_static_array(current->export_previous_value_matrix, 900);
	init_double_static_array(current->region_export_volume, 30);
	init_double_static_array(current->region_import_volume, 30);
	init_double_static_array(current->region_export_value, 30);
	init_double_static_array(current->region_import_value, 30);
	init_double_static_array(current->region_import_previous_value, 30);
	
	return current;
}

void free_Eurostat_agent(xmachine_memory_Eurostat_holder * tmp, xmachine_memory_Eurostat_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_firm_data_array(&tmp->agent->region_firm_data);
	free_household_data_array(&tmp->agent->region_household_data);
	free_tax_rates_item_static_array(tmp->agent->government_tax_rates, 27);
	free_history_item_static_array(tmp->agent->history_monthly, 13);
	free_history_item_static_array(tmp->agent->history_quarterly, 5);
	free_history_item(&tmp->agent->monthly_growth_rates);
	free_history_item(&tmp->agent->quarterly_growth_rates);
	free_history_item(&tmp->agent->annual_growth_rates_monthly);
	free_history_item(&tmp->agent->annual_growth_rates_quarterly);
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Eurostat_agent()
{
	current_xmachine_Eurostat = (xmachine_memory_Eurostat *)malloc(sizeof(xmachine_memory_Eurostat));
	CHECK_POINTER(current);
	
		current_xmachine_Eurostat->id = 0;
		current_xmachine_Eurostat->region_id = 0;
		current_xmachine_Eurostat->no_regions = 0;
		current_xmachine_Eurostat->switch_datastorage = 0;
		current_xmachine_Eurostat->num_households = 0;
		current_xmachine_Eurostat->no_households_skill_1 = 0;
		current_xmachine_Eurostat->no_households_skill_2 = 0;
		current_xmachine_Eurostat->no_households_skill_3 = 0;
		current_xmachine_Eurostat->no_households_skill_4 = 0;
		current_xmachine_Eurostat->no_households_skill_5 = 0;
		current_xmachine_Eurostat->employed = 0;
		current_xmachine_Eurostat->employed_skill_1 = 0;
		current_xmachine_Eurostat->employed_skill_2 = 0;
		current_xmachine_Eurostat->employed_skill_3 = 0;
		current_xmachine_Eurostat->employed_skill_4 = 0;
		current_xmachine_Eurostat->employed_skill_5 = 0;
		current_xmachine_Eurostat->unemployed = 0;
		current_xmachine_Eurostat->unemployment_rate = 0.0;
		current_xmachine_Eurostat->unemployment_rate_skill_1 = 0.0;
		current_xmachine_Eurostat->unemployment_rate_skill_2 = 0.0;
		current_xmachine_Eurostat->unemployment_rate_skill_3 = 0.0;
		current_xmachine_Eurostat->unemployment_rate_skill_4 = 0.0;
		current_xmachine_Eurostat->unemployment_rate_skill_5 = 0.0;
		current_xmachine_Eurostat->average_wage = 0.0;
		current_xmachine_Eurostat->average_wage_skill_1 = 0.0;
		current_xmachine_Eurostat->average_wage_skill_2 = 0.0;
		current_xmachine_Eurostat->average_wage_skill_3 = 0.0;
		current_xmachine_Eurostat->average_wage_skill_4 = 0.0;
		current_xmachine_Eurostat->average_wage_skill_5 = 0.0;
		current_xmachine_Eurostat->average_s_skill = 0.0;
		current_xmachine_Eurostat->average_s_skill_1 = 0.0;
		current_xmachine_Eurostat->average_s_skill_2 = 0.0;
		current_xmachine_Eurostat->average_s_skill_3 = 0.0;
		current_xmachine_Eurostat->average_s_skill_4 = 0.0;
		current_xmachine_Eurostat->average_s_skill_5 = 0.0;
		current_xmachine_Eurostat->no_firms = 0;
		current_xmachine_Eurostat->no_vacancies = 0;
		current_xmachine_Eurostat->no_employees = 0;
		current_xmachine_Eurostat->no_employees_skill_1 = 0;
		current_xmachine_Eurostat->no_employees_skill_2 = 0;
		current_xmachine_Eurostat->no_employees_skill_3 = 0;
		current_xmachine_Eurostat->no_employees_skill_4 = 0;
		current_xmachine_Eurostat->no_employees_skill_5 = 0;
		current_xmachine_Eurostat->firm_average_wage = 0.0;
		current_xmachine_Eurostat->firm_average_wage_skill_1 = 0.0;
		current_xmachine_Eurostat->firm_average_wage_skill_2 = 0.0;
		current_xmachine_Eurostat->firm_average_wage_skill_3 = 0.0;
		current_xmachine_Eurostat->firm_average_wage_skill_4 = 0.0;
		current_xmachine_Eurostat->firm_average_wage_skill_5 = 0.0;
		current_xmachine_Eurostat->firm_average_s_skill = 0.0;
		current_xmachine_Eurostat->firm_average_s_skill_1 = 0.0;
		current_xmachine_Eurostat->firm_average_s_skill_2 = 0.0;
		current_xmachine_Eurostat->firm_average_s_skill_3 = 0.0;
		current_xmachine_Eurostat->firm_average_s_skill_4 = 0.0;
		current_xmachine_Eurostat->firm_average_s_skill_5 = 0.0;
		init_firm_data_array(&current_xmachine_Eurostat->region_firm_data);
		init_household_data_array(&current_xmachine_Eurostat->region_household_data);
		init_tax_rates_item_static_array(current_xmachine_Eurostat->government_tax_rates, 27);
		current_xmachine_Eurostat->total_earnings = 0.0;
		current_xmachine_Eurostat->total_debt = 0.0;
		current_xmachine_Eurostat->total_assets = 0.0;
		current_xmachine_Eurostat->total_equity = 0.0;
		current_xmachine_Eurostat->average_debt_earnings_ratio = 0.0;
		current_xmachine_Eurostat->average_debt_equity_ratio = 0.0;
		current_xmachine_Eurostat->labour_share_ratio = 0.0;
		current_xmachine_Eurostat->cpi = 0.0;
		current_xmachine_Eurostat->gdp = 0.0;
		current_xmachine_Eurostat->monthly_sold_quantity = 0.0;
		current_xmachine_Eurostat->monthly_output = 0.0;
		current_xmachine_Eurostat->monthly_revenue = 0.0;
		current_xmachine_Eurostat->monthly_planned_output = 0.0;
		current_xmachine_Eurostat->price_index = 0.0;
		init_history_item_static_array(current_xmachine_Eurostat->history_monthly, 13);
		init_history_item_static_array(current_xmachine_Eurostat->history_quarterly, 5);
		init_history_item(&current_xmachine_Eurostat->monthly_growth_rates);
		init_history_item(&current_xmachine_Eurostat->quarterly_growth_rates);
		init_history_item(&current_xmachine_Eurostat->annual_growth_rates_monthly);
		init_history_item(&current_xmachine_Eurostat->annual_growth_rates_quarterly);
		current_xmachine_Eurostat->no_firm_births = 0;
		current_xmachine_Eurostat->no_firm_deaths = 0;
		init_int_static_array(current_xmachine_Eurostat->firm_age_distribution, 60);
		init_int_static_array(current_xmachine_Eurostat->firm_age_distribution_multiperiod, 720);
		init_int_static_array(current_xmachine_Eurostat->firm_age_distribution_1_period_lag, 60);
		init_int_static_array(current_xmachine_Eurostat->firm_age_distribution_2_period_lag, 60);
		current_xmachine_Eurostat->firm_birth_rate = 0.0;
		current_xmachine_Eurostat->firm_death_rate = 0.0;
		init_double_static_array(current_xmachine_Eurostat->survival_rate, 60);
		init_double_static_array(current_xmachine_Eurostat->survival_rate_multiperiod_1, 60);
		init_double_static_array(current_xmachine_Eurostat->survival_rate_multiperiod_2, 60);
		init_double_static_array(current_xmachine_Eurostat->survival_rate_multiperiod, 720);
		current_xmachine_Eurostat->max_firm_creation = 0;
		current_xmachine_Eurostat->recession_started = 0;
		current_xmachine_Eurostat->recession_duration = 0;
		init_double_static_array(current_xmachine_Eurostat->export_volume_matrix, 900);
		init_double_static_array(current_xmachine_Eurostat->export_value_matrix, 900);
		init_double_static_array(current_xmachine_Eurostat->export_previous_value_matrix, 900);
		init_double_static_array(current_xmachine_Eurostat->region_export_volume, 30);
		init_double_static_array(current_xmachine_Eurostat->region_import_volume, 30);
		init_double_static_array(current_xmachine_Eurostat->region_export_value, 30);
		init_double_static_array(current_xmachine_Eurostat->region_import_value, 30);
		init_double_static_array(current_xmachine_Eurostat->region_import_previous_value, 30);
		
}

void unittest_free_Eurostat_agent()
{
	free_firm_data_array(&current_xmachine_Eurostat->region_firm_data);
	free_household_data_array(&current_xmachine_Eurostat->region_household_data);
	free_tax_rates_item_static_array(current_xmachine_Eurostat->government_tax_rates, 27);
	free_history_item_static_array(current_xmachine_Eurostat->history_monthly, 13);
	free_history_item_static_array(current_xmachine_Eurostat->history_quarterly, 5);
	free_history_item(&current_xmachine_Eurostat->monthly_growth_rates);
	free_history_item(&current_xmachine_Eurostat->quarterly_growth_rates);
	free_history_item(&current_xmachine_Eurostat->annual_growth_rates_monthly);
	free_history_item(&current_xmachine_Eurostat->annual_growth_rates_quarterly);
	
	free(current_xmachine_Eurostat);
}

void free_Eurostat_agents()
{
	current_xmachine_Eurostat_holder = Eurostat_end_Eurostat_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_end_Eurostat_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_EndOfYear_Loop_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_EndOfYear_Loop_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_05_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_05_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_04_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_04_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_Quarterly_Loop_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Quarterly_Loop_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_02_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_02_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_Monthly_Loop_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Monthly_Loop_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_01_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_01_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_Firm_Data_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Firm_Data_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_Eurostat_Start_Policy_Data_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_Eurostat_Start_Policy_Data_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
	current_xmachine_Eurostat_holder = Eurostat_start_Eurostat_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		temp_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
		free_Eurostat_agent(current_xmachine_Eurostat_holder, Eurostat_start_Eurostat_state);
		current_xmachine_Eurostat_holder = temp_xmachine_Eurostat_holder;
	}
}

void free_Eurostat_states()
{
	free(Eurostat_end_Eurostat_state);
	free(Eurostat_Eurostat_Start_EndOfYear_Loop_state);
	free(Eurostat_05_state);
	free(Eurostat_04_state);
	free(Eurostat_Eurostat_Start_Quarterly_Loop_state);
	free(Eurostat_02_state);
	free(Eurostat_Eurostat_Start_Monthly_Loop_state);
	free(Eurostat_01_state);
	free(Eurostat_Eurostat_Start_Firm_Data_state);
	free(Eurostat_Eurostat_Start_Policy_Data_state);
	free(Eurostat_start_Eurostat_state);
}

void transition_Eurostat_agent(xmachine_memory_Eurostat_holder * tmp, xmachine_memory_Eurostat_state * from_state, xmachine_memory_Eurostat_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Eurostat_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Eurostat_agent_internal(xmachine_memory_Eurostat * agent, xmachine_memory_Eurostat_state * state)
{
	xmachine_memory_Eurostat_holder * current = (xmachine_memory_Eurostat_holder *)malloc(sizeof(xmachine_memory_Eurostat_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Eurostat_agent(int id, int region_id, int no_regions, int switch_datastorage, int num_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, int no_firms, int no_vacancies, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, double firm_average_wage, double firm_average_wage_skill_1, double firm_average_wage_skill_2, double firm_average_wage_skill_3, double firm_average_wage_skill_4, double firm_average_wage_skill_5, double firm_average_s_skill, double firm_average_s_skill_1, double firm_average_s_skill_2, double firm_average_s_skill_3, double firm_average_s_skill_4, double firm_average_s_skill_5, firm_data_array * region_firm_data, household_data_array * region_household_data, tax_rates_item ** government_tax_rates, double total_earnings, double total_debt, double total_assets, double total_equity, double average_debt_earnings_ratio, double average_debt_equity_ratio, double labour_share_ratio, double cpi, double gdp, double monthly_sold_quantity, double monthly_output, double monthly_revenue, double monthly_planned_output, double price_index, history_item ** history_monthly, history_item ** history_quarterly, history_item * monthly_growth_rates, history_item * quarterly_growth_rates, history_item * annual_growth_rates_monthly, history_item * annual_growth_rates_quarterly, int no_firm_births, int no_firm_deaths, int firm_age_distribution[], int firm_age_distribution_multiperiod[], int firm_age_distribution_1_period_lag[], int firm_age_distribution_2_period_lag[], double firm_birth_rate, double firm_death_rate, double survival_rate[], double survival_rate_multiperiod_1[], double survival_rate_multiperiod_2[], double survival_rate_multiperiod[], int max_firm_creation, int recession_started, int recession_duration, double export_volume_matrix[], double export_value_matrix[], double export_previous_value_matrix[], double region_export_volume[], double region_import_volume[], double region_export_value[], double region_import_value[], double region_import_previous_value[])
 * \brief Add Eurostat X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param no_regions Variable for the X-machine memory.
 * \param switch_datastorage Variable for the X-machine memory.
 * \param num_households Variable for the X-machine memory.
 * \param no_households_skill_1 Variable for the X-machine memory.
 * \param no_households_skill_2 Variable for the X-machine memory.
 * \param no_households_skill_3 Variable for the X-machine memory.
 * \param no_households_skill_4 Variable for the X-machine memory.
 * \param no_households_skill_5 Variable for the X-machine memory.
 * \param employed Variable for the X-machine memory.
 * \param employed_skill_1 Variable for the X-machine memory.
 * \param employed_skill_2 Variable for the X-machine memory.
 * \param employed_skill_3 Variable for the X-machine memory.
 * \param employed_skill_4 Variable for the X-machine memory.
 * \param employed_skill_5 Variable for the X-machine memory.
 * \param unemployed Variable for the X-machine memory.
 * \param unemployment_rate Variable for the X-machine memory.
 * \param unemployment_rate_skill_1 Variable for the X-machine memory.
 * \param unemployment_rate_skill_2 Variable for the X-machine memory.
 * \param unemployment_rate_skill_3 Variable for the X-machine memory.
 * \param unemployment_rate_skill_4 Variable for the X-machine memory.
 * \param unemployment_rate_skill_5 Variable for the X-machine memory.
 * \param average_wage Variable for the X-machine memory.
 * \param average_wage_skill_1 Variable for the X-machine memory.
 * \param average_wage_skill_2 Variable for the X-machine memory.
 * \param average_wage_skill_3 Variable for the X-machine memory.
 * \param average_wage_skill_4 Variable for the X-machine memory.
 * \param average_wage_skill_5 Variable for the X-machine memory.
 * \param average_s_skill Variable for the X-machine memory.
 * \param average_s_skill_1 Variable for the X-machine memory.
 * \param average_s_skill_2 Variable for the X-machine memory.
 * \param average_s_skill_3 Variable for the X-machine memory.
 * \param average_s_skill_4 Variable for the X-machine memory.
 * \param average_s_skill_5 Variable for the X-machine memory.
 * \param no_firms Variable for the X-machine memory.
 * \param no_vacancies Variable for the X-machine memory.
 * \param no_employees Variable for the X-machine memory.
 * \param no_employees_skill_1 Variable for the X-machine memory.
 * \param no_employees_skill_2 Variable for the X-machine memory.
 * \param no_employees_skill_3 Variable for the X-machine memory.
 * \param no_employees_skill_4 Variable for the X-machine memory.
 * \param no_employees_skill_5 Variable for the X-machine memory.
 * \param firm_average_wage Variable for the X-machine memory.
 * \param firm_average_wage_skill_1 Variable for the X-machine memory.
 * \param firm_average_wage_skill_2 Variable for the X-machine memory.
 * \param firm_average_wage_skill_3 Variable for the X-machine memory.
 * \param firm_average_wage_skill_4 Variable for the X-machine memory.
 * \param firm_average_wage_skill_5 Variable for the X-machine memory.
 * \param firm_average_s_skill Variable for the X-machine memory.
 * \param firm_average_s_skill_1 Variable for the X-machine memory.
 * \param firm_average_s_skill_2 Variable for the X-machine memory.
 * \param firm_average_s_skill_3 Variable for the X-machine memory.
 * \param firm_average_s_skill_4 Variable for the X-machine memory.
 * \param firm_average_s_skill_5 Variable for the X-machine memory.
 * \param region_firm_data Variable for the X-machine memory.
 * \param region_household_data Variable for the X-machine memory.
 * \param government_tax_rates Variable for the X-machine memory.
 * \param total_earnings Variable for the X-machine memory.
 * \param total_debt Variable for the X-machine memory.
 * \param total_assets Variable for the X-machine memory.
 * \param total_equity Variable for the X-machine memory.
 * \param average_debt_earnings_ratio Variable for the X-machine memory.
 * \param average_debt_equity_ratio Variable for the X-machine memory.
 * \param labour_share_ratio Variable for the X-machine memory.
 * \param cpi Variable for the X-machine memory.
 * \param gdp Variable for the X-machine memory.
 * \param monthly_sold_quantity Variable for the X-machine memory.
 * \param monthly_output Variable for the X-machine memory.
 * \param monthly_revenue Variable for the X-machine memory.
 * \param monthly_planned_output Variable for the X-machine memory.
 * \param price_index Variable for the X-machine memory.
 * \param history_monthly Variable for the X-machine memory.
 * \param history_quarterly Variable for the X-machine memory.
 * \param monthly_growth_rates Variable for the X-machine memory.
 * \param quarterly_growth_rates Variable for the X-machine memory.
 * \param annual_growth_rates_monthly Variable for the X-machine memory.
 * \param annual_growth_rates_quarterly Variable for the X-machine memory.
 * \param no_firm_births Variable for the X-machine memory.
 * \param no_firm_deaths Variable for the X-machine memory.
 * \param firm_age_distribution Variable for the X-machine memory.
 * \param firm_age_distribution_multiperiod Variable for the X-machine memory.
 * \param firm_age_distribution_1_period_lag Variable for the X-machine memory.
 * \param firm_age_distribution_2_period_lag Variable for the X-machine memory.
 * \param firm_birth_rate Variable for the X-machine memory.
 * \param firm_death_rate Variable for the X-machine memory.
 * \param survival_rate Variable for the X-machine memory.
 * \param survival_rate_multiperiod_1 Variable for the X-machine memory.
 * \param survival_rate_multiperiod_2 Variable for the X-machine memory.
 * \param survival_rate_multiperiod Variable for the X-machine memory.
 * \param max_firm_creation Variable for the X-machine memory.
 * \param recession_started Variable for the X-machine memory.
 * \param recession_duration Variable for the X-machine memory.
 * \param export_volume_matrix Variable for the X-machine memory.
 * \param export_value_matrix Variable for the X-machine memory.
 * \param export_previous_value_matrix Variable for the X-machine memory.
 * \param region_export_volume Variable for the X-machine memory.
 * \param region_import_volume Variable for the X-machine memory.
 * \param region_export_value Variable for the X-machine memory.
 * \param region_import_value Variable for the X-machine memory.
 * \param region_import_previous_value Variable for the X-machine memory.
 */
void add_Eurostat_agent(int id, int region_id, int no_regions, int switch_datastorage, int num_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, int no_firms, int no_vacancies, int no_employees, int no_employees_skill_1, int no_employees_skill_2, int no_employees_skill_3, int no_employees_skill_4, int no_employees_skill_5, double firm_average_wage, double firm_average_wage_skill_1, double firm_average_wage_skill_2, double firm_average_wage_skill_3, double firm_average_wage_skill_4, double firm_average_wage_skill_5, double firm_average_s_skill, double firm_average_s_skill_1, double firm_average_s_skill_2, double firm_average_s_skill_3, double firm_average_s_skill_4, double firm_average_s_skill_5, firm_data_array * region_firm_data, household_data_array * region_household_data, tax_rates_item government_tax_rates[], double total_earnings, double total_debt, double total_assets, double total_equity, double average_debt_earnings_ratio, double average_debt_equity_ratio, double labour_share_ratio, double cpi, double gdp, double monthly_sold_quantity, double monthly_output, double monthly_revenue, double monthly_planned_output, double price_index, history_item history_monthly[], history_item history_quarterly[], history_item monthly_growth_rates, history_item quarterly_growth_rates, history_item annual_growth_rates_monthly, history_item annual_growth_rates_quarterly, int no_firm_births, int no_firm_deaths, int firm_age_distribution[], int firm_age_distribution_multiperiod[], int firm_age_distribution_1_period_lag[], int firm_age_distribution_2_period_lag[], double firm_birth_rate, double firm_death_rate, double survival_rate[], double survival_rate_multiperiod_1[], double survival_rate_multiperiod_2[], double survival_rate_multiperiod[], int max_firm_creation, int recession_started, int recession_duration, double export_volume_matrix[], double export_value_matrix[], double export_previous_value_matrix[], double region_export_volume[], double region_import_volume[], double region_export_value[], double region_import_value[], double region_import_previous_value[])
{
	xmachine_memory_Eurostat * current;
	
	current = init_Eurostat_agent();
	add_Eurostat_agent_internal(current, current_xmachine_Eurostat_next_state);
	
	current->id = id;
	current->region_id = region_id;
	current->no_regions = no_regions;
	current->switch_datastorage = switch_datastorage;
	current->num_households = num_households;
	current->no_households_skill_1 = no_households_skill_1;
	current->no_households_skill_2 = no_households_skill_2;
	current->no_households_skill_3 = no_households_skill_3;
	current->no_households_skill_4 = no_households_skill_4;
	current->no_households_skill_5 = no_households_skill_5;
	current->employed = employed;
	current->employed_skill_1 = employed_skill_1;
	current->employed_skill_2 = employed_skill_2;
	current->employed_skill_3 = employed_skill_3;
	current->employed_skill_4 = employed_skill_4;
	current->employed_skill_5 = employed_skill_5;
	current->unemployed = unemployed;
	current->unemployment_rate = unemployment_rate;
	current->unemployment_rate_skill_1 = unemployment_rate_skill_1;
	current->unemployment_rate_skill_2 = unemployment_rate_skill_2;
	current->unemployment_rate_skill_3 = unemployment_rate_skill_3;
	current->unemployment_rate_skill_4 = unemployment_rate_skill_4;
	current->unemployment_rate_skill_5 = unemployment_rate_skill_5;
	current->average_wage = average_wage;
	current->average_wage_skill_1 = average_wage_skill_1;
	current->average_wage_skill_2 = average_wage_skill_2;
	current->average_wage_skill_3 = average_wage_skill_3;
	current->average_wage_skill_4 = average_wage_skill_4;
	current->average_wage_skill_5 = average_wage_skill_5;
	current->average_s_skill = average_s_skill;
	current->average_s_skill_1 = average_s_skill_1;
	current->average_s_skill_2 = average_s_skill_2;
	current->average_s_skill_3 = average_s_skill_3;
	current->average_s_skill_4 = average_s_skill_4;
	current->average_s_skill_5 = average_s_skill_5;
	current->no_firms = no_firms;
	current->no_vacancies = no_vacancies;
	current->no_employees = no_employees;
	current->no_employees_skill_1 = no_employees_skill_1;
	current->no_employees_skill_2 = no_employees_skill_2;
	current->no_employees_skill_3 = no_employees_skill_3;
	current->no_employees_skill_4 = no_employees_skill_4;
	current->no_employees_skill_5 = no_employees_skill_5;
	current->firm_average_wage = firm_average_wage;
	current->firm_average_wage_skill_1 = firm_average_wage_skill_1;
	current->firm_average_wage_skill_2 = firm_average_wage_skill_2;
	current->firm_average_wage_skill_3 = firm_average_wage_skill_3;
	current->firm_average_wage_skill_4 = firm_average_wage_skill_4;
	current->firm_average_wage_skill_5 = firm_average_wage_skill_5;
	current->firm_average_s_skill = firm_average_s_skill;
	current->firm_average_s_skill_1 = firm_average_s_skill_1;
	current->firm_average_s_skill_2 = firm_average_s_skill_2;
	current->firm_average_s_skill_3 = firm_average_s_skill_3;
	current->firm_average_s_skill_4 = firm_average_s_skill_4;
	current->firm_average_s_skill_5 = firm_average_s_skill_5;
	copy_firm_data_array(region_firm_data, &current->region_firm_data);
	copy_household_data_array(region_household_data, &current->region_household_data);
	copy_tax_rates_item_static_array(government_tax_rates, current->government_tax_rates, 27);
	current->total_earnings = total_earnings;
	current->total_debt = total_debt;
	current->total_assets = total_assets;
	current->total_equity = total_equity;
	current->average_debt_earnings_ratio = average_debt_earnings_ratio;
	current->average_debt_equity_ratio = average_debt_equity_ratio;
	current->labour_share_ratio = labour_share_ratio;
	current->cpi = cpi;
	current->gdp = gdp;
	current->monthly_sold_quantity = monthly_sold_quantity;
	current->monthly_output = monthly_output;
	current->monthly_revenue = monthly_revenue;
	current->monthly_planned_output = monthly_planned_output;
	current->price_index = price_index;
	copy_history_item_static_array(history_monthly, current->history_monthly, 13);
	copy_history_item_static_array(history_quarterly, current->history_quarterly, 5);
	copy_history_item(&monthly_growth_rates, &current->monthly_growth_rates);
	copy_history_item(&quarterly_growth_rates, &current->quarterly_growth_rates);
	copy_history_item(&annual_growth_rates_monthly, &current->annual_growth_rates_monthly);
	copy_history_item(&annual_growth_rates_quarterly, &current->annual_growth_rates_quarterly);
	current->no_firm_births = no_firm_births;
	current->no_firm_deaths = no_firm_deaths;
	memcpy(current->firm_age_distribution, firm_age_distribution, 60*sizeof(int));
	memcpy(current->firm_age_distribution_multiperiod, firm_age_distribution_multiperiod, 720*sizeof(int));
	memcpy(current->firm_age_distribution_1_period_lag, firm_age_distribution_1_period_lag, 60*sizeof(int));
	memcpy(current->firm_age_distribution_2_period_lag, firm_age_distribution_2_period_lag, 60*sizeof(int));
	current->firm_birth_rate = firm_birth_rate;
	current->firm_death_rate = firm_death_rate;
	memcpy(current->survival_rate, survival_rate, 60*sizeof(double));
	memcpy(current->survival_rate_multiperiod_1, survival_rate_multiperiod_1, 60*sizeof(double));
	memcpy(current->survival_rate_multiperiod_2, survival_rate_multiperiod_2, 60*sizeof(double));
	memcpy(current->survival_rate_multiperiod, survival_rate_multiperiod, 720*sizeof(double));
	current->max_firm_creation = max_firm_creation;
	current->recession_started = recession_started;
	current->recession_duration = recession_duration;
	memcpy(current->export_volume_matrix, export_volume_matrix, 900*sizeof(double));
	memcpy(current->export_value_matrix, export_value_matrix, 900*sizeof(double));
	memcpy(current->export_previous_value_matrix, export_previous_value_matrix, 900*sizeof(double));
	memcpy(current->region_export_volume, region_export_volume, 30*sizeof(double));
	memcpy(current->region_import_volume, region_import_volume, 30*sizeof(double));
	memcpy(current->region_export_value, region_export_value, 30*sizeof(double));
	memcpy(current->region_import_value, region_import_value, 30*sizeof(double));
	memcpy(current->region_import_previous_value, region_import_previous_value, 30*sizeof(double));
}

xmachine_memory_Clearinghouse_state * init_Clearinghouse_state()
{
	xmachine_memory_Clearinghouse_state * current = (xmachine_memory_Clearinghouse_state *)malloc(sizeof(xmachine_memory_Clearinghouse_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Clearinghouse * init_Clearinghouse_agent()
{
	xmachine_memory_Clearinghouse * current = (xmachine_memory_Clearinghouse *)malloc(sizeof(xmachine_memory_Clearinghouse));
	CHECK_POINTER(current);
	
	current->id = 0;
	current->region_id = 0;
	init_Asset_array(&current->assets);
	init_ClearingMechanism(&current->clearingmechanism);
	
	return current;
}

void free_Clearinghouse_agent(xmachine_memory_Clearinghouse_holder * tmp, xmachine_memory_Clearinghouse_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_Asset_array(&tmp->agent->assets);
	free_ClearingMechanism(&tmp->agent->clearingmechanism);
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Clearinghouse_agent()
{
	current_xmachine_Clearinghouse = (xmachine_memory_Clearinghouse *)malloc(sizeof(xmachine_memory_Clearinghouse));
	CHECK_POINTER(current);
	
		current_xmachine_Clearinghouse->id = 0;
		current_xmachine_Clearinghouse->region_id = 0;
		init_Asset_array(&current_xmachine_Clearinghouse->assets);
		init_ClearingMechanism(&current_xmachine_Clearinghouse->clearingmechanism);
		
}

void unittest_free_Clearinghouse_agent()
{
	free_Asset_array(&current_xmachine_Clearinghouse->assets);
	free_ClearingMechanism(&current_xmachine_Clearinghouse->clearingmechanism);
	
	free(current_xmachine_Clearinghouse);
}

void free_Clearinghouse_agents()
{
	current_xmachine_Clearinghouse_holder = Clearinghouse_end_Clearinghouse_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_end_Clearinghouse_state);
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}
	current_xmachine_Clearinghouse_holder = Clearinghouse_COMPUTEDPRICES_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_COMPUTEDPRICES_state);
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}
	current_xmachine_Clearinghouse_holder = Clearinghouse_RECEIVEDINFOSTOCK_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_RECEIVEDINFOSTOCK_state);
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}
	current_xmachine_Clearinghouse_holder = Clearinghouse_start_Clearinghouse_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		temp_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
		free_Clearinghouse_agent(current_xmachine_Clearinghouse_holder, Clearinghouse_start_Clearinghouse_state);
		current_xmachine_Clearinghouse_holder = temp_xmachine_Clearinghouse_holder;
	}
}

void free_Clearinghouse_states()
{
	free(Clearinghouse_end_Clearinghouse_state);
	free(Clearinghouse_COMPUTEDPRICES_state);
	free(Clearinghouse_RECEIVEDINFOSTOCK_state);
	free(Clearinghouse_start_Clearinghouse_state);
}

void transition_Clearinghouse_agent(xmachine_memory_Clearinghouse_holder * tmp, xmachine_memory_Clearinghouse_state * from_state, xmachine_memory_Clearinghouse_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Clearinghouse_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Clearinghouse_agent_internal(xmachine_memory_Clearinghouse * agent, xmachine_memory_Clearinghouse_state * state)
{
	xmachine_memory_Clearinghouse_holder * current = (xmachine_memory_Clearinghouse_holder *)malloc(sizeof(xmachine_memory_Clearinghouse_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Clearinghouse_agent(int id, int region_id, Asset_array * assets, ClearingMechanism * clearingmechanism)
 * \brief Add Clearinghouse X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param region_id Variable for the X-machine memory.
 * \param assets Variable for the X-machine memory.
 * \param clearingmechanism Variable for the X-machine memory.
 */
void add_Clearinghouse_agent(int id, int region_id, Asset_array * assets, ClearingMechanism clearingmechanism)
{
	xmachine_memory_Clearinghouse * current;
	
	current = init_Clearinghouse_agent();
	add_Clearinghouse_agent_internal(current, current_xmachine_Clearinghouse_next_state);
	
	current->id = id;
	current->region_id = region_id;
	copy_Asset_array(assets, &current->assets);
	copy_ClearingMechanism(&clearingmechanism, &current->clearingmechanism);
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
	current_xmachine_Bank_holder = Bank_start_Bank_state->agents;
	while(current_xmachine_Bank_holder)
	{
		temp_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
		free_Bank_agent(current_xmachine_Bank_holder, Bank_start_Bank_state);
		current_xmachine_Bank_holder = temp_xmachine_Bank_holder;
	}
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
	free(Bank_start_Bank_state);
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

xmachine_memory_Government_state * init_Government_state()
{
	xmachine_memory_Government_state * current = (xmachine_memory_Government_state *)malloc(sizeof(xmachine_memory_Government_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Government * init_Government_agent()
{
	xmachine_memory_Government * current = (xmachine_memory_Government *)malloc(sizeof(xmachine_memory_Government));
	CHECK_POINTER(current);
	
	current->id = 0;
	init_int_static_array(current->list_of_regions, 1);
	current->payment_account = 0.0;
	current->day_of_month_to_act = 0;
	init_Bond(&current->bond);
	init_Order(&current->pending_order);
	current->deficit = 0.0;
	current->unemployment_benefit_pct = 0.0;
	current->money_financing_fraction = 0.0;
	current->gdp_fraction_consumption = 0.0;
	current->gdp_fraction_investment = 0.0;
	current->tax_rate_corporate = 0.0;
	current->tax_rate_hh_labour = 0.0;
	current->tax_rate_hh_capital = 0.0;
	current->tax_rate_vat = 0.0;
	current->monthly_tax_revenues = 0.0;
	current->yearly_tax_revenues = 0.0;
	current->monthly_unemployment_benefit_payment = 0.0;
	current->yearly_unemployment_benefit_payment = 0.0;
	current->hh_transfer_payment = 0.0;
	current->firm_transfer_payment = 0.0;
	current->monthly_transfer_payment = 0.0;
	current->yearly_transfer_payment = 0.0;
	current->hh_subsidy_payment = 0.0;
	current->firm_subsidy_payment = 0.0;
	current->monthly_subsidy_payment = 0.0;
	current->yearly_subsidy_payment = 0.0;
	current->monthly_bond_coupon_payment = 0.0;
	current->yearly_bond_coupon_payment = 0.0;
	current->gov_interest_rate = 0.0;
	current->yearly_investment_expenditure = 0.0;
	current->yearly_consumption_expenditure = 0.0;
	current->yearly_income = 0.0;
	current->yearly_expenditure = 0.0;
	current->total_debt = 0.0;
	current->yearly_budget_balance = 0.0;
	current->total_money_financing = 0.0;
	current->total_bond_financing = 0.0;
	current->country_wide_mean_wage = 0.0;
	current->num_unemployed = 0;
	current->gdp = 0.0;
	current->gdp_growth = 0.0;
	current->gdp_forecast = 0.0;
	current->yearly_income_forecast = 0.0;
	current->yearly_expenditure_budget = 0.0;
	current->budget_balance_forecast = 0.0;
	current->monthly_consumption_expenditure = 0.0;
	current->monthly_investment_expenditure = 0.0;
	current->monthly_budget_balance = 0.0;
	current->monthly_consumption_budget = 0.0;
	current->monthly_investment_budget = 0.0;
	current->monthly_income = 0.0;
	current->monthly_expenditure = 0.0;
	current->yearly_consumption_budget = 0.0;
	current->yearly_investment_budget = 0.0;
	
	return current;
}

void free_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_Bond(&tmp->agent->bond);
	free_Order(&tmp->agent->pending_order);
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Government_agent()
{
	current_xmachine_Government = (xmachine_memory_Government *)malloc(sizeof(xmachine_memory_Government));
	CHECK_POINTER(current);
	
		current_xmachine_Government->id = 0;
		init_int_static_array(current_xmachine_Government->list_of_regions, 1);
		current_xmachine_Government->payment_account = 0.0;
		current_xmachine_Government->day_of_month_to_act = 0;
		init_Bond(&current_xmachine_Government->bond);
		init_Order(&current_xmachine_Government->pending_order);
		current_xmachine_Government->deficit = 0.0;
		current_xmachine_Government->unemployment_benefit_pct = 0.0;
		current_xmachine_Government->money_financing_fraction = 0.0;
		current_xmachine_Government->gdp_fraction_consumption = 0.0;
		current_xmachine_Government->gdp_fraction_investment = 0.0;
		current_xmachine_Government->tax_rate_corporate = 0.0;
		current_xmachine_Government->tax_rate_hh_labour = 0.0;
		current_xmachine_Government->tax_rate_hh_capital = 0.0;
		current_xmachine_Government->tax_rate_vat = 0.0;
		current_xmachine_Government->monthly_tax_revenues = 0.0;
		current_xmachine_Government->yearly_tax_revenues = 0.0;
		current_xmachine_Government->monthly_unemployment_benefit_payment = 0.0;
		current_xmachine_Government->yearly_unemployment_benefit_payment = 0.0;
		current_xmachine_Government->hh_transfer_payment = 0.0;
		current_xmachine_Government->firm_transfer_payment = 0.0;
		current_xmachine_Government->monthly_transfer_payment = 0.0;
		current_xmachine_Government->yearly_transfer_payment = 0.0;
		current_xmachine_Government->hh_subsidy_payment = 0.0;
		current_xmachine_Government->firm_subsidy_payment = 0.0;
		current_xmachine_Government->monthly_subsidy_payment = 0.0;
		current_xmachine_Government->yearly_subsidy_payment = 0.0;
		current_xmachine_Government->monthly_bond_coupon_payment = 0.0;
		current_xmachine_Government->yearly_bond_coupon_payment = 0.0;
		current_xmachine_Government->gov_interest_rate = 0.0;
		current_xmachine_Government->yearly_investment_expenditure = 0.0;
		current_xmachine_Government->yearly_consumption_expenditure = 0.0;
		current_xmachine_Government->yearly_income = 0.0;
		current_xmachine_Government->yearly_expenditure = 0.0;
		current_xmachine_Government->total_debt = 0.0;
		current_xmachine_Government->yearly_budget_balance = 0.0;
		current_xmachine_Government->total_money_financing = 0.0;
		current_xmachine_Government->total_bond_financing = 0.0;
		current_xmachine_Government->country_wide_mean_wage = 0.0;
		current_xmachine_Government->num_unemployed = 0;
		current_xmachine_Government->gdp = 0.0;
		current_xmachine_Government->gdp_growth = 0.0;
		current_xmachine_Government->gdp_forecast = 0.0;
		current_xmachine_Government->yearly_income_forecast = 0.0;
		current_xmachine_Government->yearly_expenditure_budget = 0.0;
		current_xmachine_Government->budget_balance_forecast = 0.0;
		current_xmachine_Government->monthly_consumption_expenditure = 0.0;
		current_xmachine_Government->monthly_investment_expenditure = 0.0;
		current_xmachine_Government->monthly_budget_balance = 0.0;
		current_xmachine_Government->monthly_consumption_budget = 0.0;
		current_xmachine_Government->monthly_investment_budget = 0.0;
		current_xmachine_Government->monthly_income = 0.0;
		current_xmachine_Government->monthly_expenditure = 0.0;
		current_xmachine_Government->yearly_consumption_budget = 0.0;
		current_xmachine_Government->yearly_investment_budget = 0.0;
		
}

void unittest_free_Government_agent()
{
	free_Bond(&current_xmachine_Government->bond);
	free_Order(&current_xmachine_Government->pending_order);
	
	free(current_xmachine_Government);
}

void free_Government_agents()
{
	current_xmachine_Government_holder = Government_end_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_end_Government_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_09_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_09_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_08_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_08_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_07_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_07_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_06_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_06_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_05_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_05_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_Gov_Start_Yearly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Yearly_Loop_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_Gov_Start_Monthly_Loop_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Monthly_Loop_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_04_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_04_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_03_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_03_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_02_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_02_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_start_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_start_Government_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_01_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_01_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_GOVERNMENT_PORTFOLIO_UPDATED_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_GOVERNMENT_PORTFOLIO_UPDATED_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_GOVERNMENT_SENT_ORDER_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_GOVERNMENT_SENT_ORDER_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_GOVERNMENT_IN_DEFICIT_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_GOVERNMENT_IN_DEFICIT_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_GOVERNMENT_SENT_info_bond_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_GOVERNMENT_SENT_info_bond_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
	current_xmachine_Government_holder = Government_Gov_Start_Bond_Market_state->agents;
	while(current_xmachine_Government_holder)
	{
		temp_xmachine_Government_holder = current_xmachine_Government_holder->next;
		free_Government_agent(current_xmachine_Government_holder, Government_Gov_Start_Bond_Market_state);
		current_xmachine_Government_holder = temp_xmachine_Government_holder;
	}
}

void free_Government_states()
{
	free(Government_end_Government_state);
	free(Government_09_state);
	free(Government_08_state);
	free(Government_07_state);
	free(Government_06_state);
	free(Government_05_state);
	free(Government_Gov_Start_Yearly_Loop_state);
	free(Government_Gov_Start_Monthly_Loop_state);
	free(Government_04_state);
	free(Government_03_state);
	free(Government_02_state);
	free(Government_start_Government_state);
	free(Government_01_state);
	free(Government_GOVERNMENT_PORTFOLIO_UPDATED_state);
	free(Government_GOVERNMENT_SENT_ORDER_state);
	free(Government_GOVERNMENT_IN_DEFICIT_state);
	free(Government_GOVERNMENT_SENT_info_bond_state);
	free(Government_Gov_Start_Bond_Market_state);
}

void transition_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * from_state, xmachine_memory_Government_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Government_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Government_agent_internal(xmachine_memory_Government * agent, xmachine_memory_Government_state * state)
{
	xmachine_memory_Government_holder * current = (xmachine_memory_Government_holder *)malloc(sizeof(xmachine_memory_Government_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Government_agent(int id, int list_of_regions[], double payment_account, int day_of_month_to_act, Bond * bond, Order * pending_order, double deficit, double unemployment_benefit_pct, double money_financing_fraction, double gdp_fraction_consumption, double gdp_fraction_investment, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double monthly_tax_revenues, double yearly_tax_revenues, double monthly_unemployment_benefit_payment, double yearly_unemployment_benefit_payment, double hh_transfer_payment, double firm_transfer_payment, double monthly_transfer_payment, double yearly_transfer_payment, double hh_subsidy_payment, double firm_subsidy_payment, double monthly_subsidy_payment, double yearly_subsidy_payment, double monthly_bond_coupon_payment, double yearly_bond_coupon_payment, double gov_interest_rate, double yearly_investment_expenditure, double yearly_consumption_expenditure, double yearly_income, double yearly_expenditure, double total_debt, double yearly_budget_balance, double total_money_financing, double total_bond_financing, double country_wide_mean_wage, int num_unemployed, double gdp, double gdp_growth, double gdp_forecast, double yearly_income_forecast, double yearly_expenditure_budget, double budget_balance_forecast, double monthly_consumption_expenditure, double monthly_investment_expenditure, double monthly_budget_balance, double monthly_consumption_budget, double monthly_investment_budget, double monthly_income, double monthly_expenditure, double yearly_consumption_budget, double yearly_investment_budget)
 * \brief Add Government X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param list_of_regions Variable for the X-machine memory.
 * \param payment_account Variable for the X-machine memory.
 * \param day_of_month_to_act Variable for the X-machine memory.
 * \param bond Variable for the X-machine memory.
 * \param pending_order Variable for the X-machine memory.
 * \param deficit Variable for the X-machine memory.
 * \param unemployment_benefit_pct Variable for the X-machine memory.
 * \param money_financing_fraction Variable for the X-machine memory.
 * \param gdp_fraction_consumption Variable for the X-machine memory.
 * \param gdp_fraction_investment Variable for the X-machine memory.
 * \param tax_rate_corporate Variable for the X-machine memory.
 * \param tax_rate_hh_labour Variable for the X-machine memory.
 * \param tax_rate_hh_capital Variable for the X-machine memory.
 * \param tax_rate_vat Variable for the X-machine memory.
 * \param monthly_tax_revenues Variable for the X-machine memory.
 * \param yearly_tax_revenues Variable for the X-machine memory.
 * \param monthly_unemployment_benefit_payment Variable for the X-machine memory.
 * \param yearly_unemployment_benefit_payment Variable for the X-machine memory.
 * \param hh_transfer_payment Variable for the X-machine memory.
 * \param firm_transfer_payment Variable for the X-machine memory.
 * \param monthly_transfer_payment Variable for the X-machine memory.
 * \param yearly_transfer_payment Variable for the X-machine memory.
 * \param hh_subsidy_payment Variable for the X-machine memory.
 * \param firm_subsidy_payment Variable for the X-machine memory.
 * \param monthly_subsidy_payment Variable for the X-machine memory.
 * \param yearly_subsidy_payment Variable for the X-machine memory.
 * \param monthly_bond_coupon_payment Variable for the X-machine memory.
 * \param yearly_bond_coupon_payment Variable for the X-machine memory.
 * \param gov_interest_rate Variable for the X-machine memory.
 * \param yearly_investment_expenditure Variable for the X-machine memory.
 * \param yearly_consumption_expenditure Variable for the X-machine memory.
 * \param yearly_income Variable for the X-machine memory.
 * \param yearly_expenditure Variable for the X-machine memory.
 * \param total_debt Variable for the X-machine memory.
 * \param yearly_budget_balance Variable for the X-machine memory.
 * \param total_money_financing Variable for the X-machine memory.
 * \param total_bond_financing Variable for the X-machine memory.
 * \param country_wide_mean_wage Variable for the X-machine memory.
 * \param num_unemployed Variable for the X-machine memory.
 * \param gdp Variable for the X-machine memory.
 * \param gdp_growth Variable for the X-machine memory.
 * \param gdp_forecast Variable for the X-machine memory.
 * \param yearly_income_forecast Variable for the X-machine memory.
 * \param yearly_expenditure_budget Variable for the X-machine memory.
 * \param budget_balance_forecast Variable for the X-machine memory.
 * \param monthly_consumption_expenditure Variable for the X-machine memory.
 * \param monthly_investment_expenditure Variable for the X-machine memory.
 * \param monthly_budget_balance Variable for the X-machine memory.
 * \param monthly_consumption_budget Variable for the X-machine memory.
 * \param monthly_investment_budget Variable for the X-machine memory.
 * \param monthly_income Variable for the X-machine memory.
 * \param monthly_expenditure Variable for the X-machine memory.
 * \param yearly_consumption_budget Variable for the X-machine memory.
 * \param yearly_investment_budget Variable for the X-machine memory.
 */
void add_Government_agent(int id, int list_of_regions[], double payment_account, int day_of_month_to_act, Bond bond, Order pending_order, double deficit, double unemployment_benefit_pct, double money_financing_fraction, double gdp_fraction_consumption, double gdp_fraction_investment, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double monthly_tax_revenues, double yearly_tax_revenues, double monthly_unemployment_benefit_payment, double yearly_unemployment_benefit_payment, double hh_transfer_payment, double firm_transfer_payment, double monthly_transfer_payment, double yearly_transfer_payment, double hh_subsidy_payment, double firm_subsidy_payment, double monthly_subsidy_payment, double yearly_subsidy_payment, double monthly_bond_coupon_payment, double yearly_bond_coupon_payment, double gov_interest_rate, double yearly_investment_expenditure, double yearly_consumption_expenditure, double yearly_income, double yearly_expenditure, double total_debt, double yearly_budget_balance, double total_money_financing, double total_bond_financing, double country_wide_mean_wage, int num_unemployed, double gdp, double gdp_growth, double gdp_forecast, double yearly_income_forecast, double yearly_expenditure_budget, double budget_balance_forecast, double monthly_consumption_expenditure, double monthly_investment_expenditure, double monthly_budget_balance, double monthly_consumption_budget, double monthly_investment_budget, double monthly_income, double monthly_expenditure, double yearly_consumption_budget, double yearly_investment_budget)
{
	xmachine_memory_Government * current;
	
	current = init_Government_agent();
	add_Government_agent_internal(current, current_xmachine_Government_next_state);
	
	current->id = id;
	memcpy(current->list_of_regions, list_of_regions, 1*sizeof(int));
	current->payment_account = payment_account;
	current->day_of_month_to_act = day_of_month_to_act;
	copy_Bond(&bond, &current->bond);
	copy_Order(&pending_order, &current->pending_order);
	current->deficit = deficit;
	current->unemployment_benefit_pct = unemployment_benefit_pct;
	current->money_financing_fraction = money_financing_fraction;
	current->gdp_fraction_consumption = gdp_fraction_consumption;
	current->gdp_fraction_investment = gdp_fraction_investment;
	current->tax_rate_corporate = tax_rate_corporate;
	current->tax_rate_hh_labour = tax_rate_hh_labour;
	current->tax_rate_hh_capital = tax_rate_hh_capital;
	current->tax_rate_vat = tax_rate_vat;
	current->monthly_tax_revenues = monthly_tax_revenues;
	current->yearly_tax_revenues = yearly_tax_revenues;
	current->monthly_unemployment_benefit_payment = monthly_unemployment_benefit_payment;
	current->yearly_unemployment_benefit_payment = yearly_unemployment_benefit_payment;
	current->hh_transfer_payment = hh_transfer_payment;
	current->firm_transfer_payment = firm_transfer_payment;
	current->monthly_transfer_payment = monthly_transfer_payment;
	current->yearly_transfer_payment = yearly_transfer_payment;
	current->hh_subsidy_payment = hh_subsidy_payment;
	current->firm_subsidy_payment = firm_subsidy_payment;
	current->monthly_subsidy_payment = monthly_subsidy_payment;
	current->yearly_subsidy_payment = yearly_subsidy_payment;
	current->monthly_bond_coupon_payment = monthly_bond_coupon_payment;
	current->yearly_bond_coupon_payment = yearly_bond_coupon_payment;
	current->gov_interest_rate = gov_interest_rate;
	current->yearly_investment_expenditure = yearly_investment_expenditure;
	current->yearly_consumption_expenditure = yearly_consumption_expenditure;
	current->yearly_income = yearly_income;
	current->yearly_expenditure = yearly_expenditure;
	current->total_debt = total_debt;
	current->yearly_budget_balance = yearly_budget_balance;
	current->total_money_financing = total_money_financing;
	current->total_bond_financing = total_bond_financing;
	current->country_wide_mean_wage = country_wide_mean_wage;
	current->num_unemployed = num_unemployed;
	current->gdp = gdp;
	current->gdp_growth = gdp_growth;
	current->gdp_forecast = gdp_forecast;
	current->yearly_income_forecast = yearly_income_forecast;
	current->yearly_expenditure_budget = yearly_expenditure_budget;
	current->budget_balance_forecast = budget_balance_forecast;
	current->monthly_consumption_expenditure = monthly_consumption_expenditure;
	current->monthly_investment_expenditure = monthly_investment_expenditure;
	current->monthly_budget_balance = monthly_budget_balance;
	current->monthly_consumption_budget = monthly_consumption_budget;
	current->monthly_investment_budget = monthly_investment_budget;
	current->monthly_income = monthly_income;
	current->monthly_expenditure = monthly_expenditure;
	current->yearly_consumption_budget = yearly_consumption_budget;
	current->yearly_investment_budget = yearly_investment_budget;
}

xmachine_memory_Central_Bank_state * init_Central_Bank_state()
{
	xmachine_memory_Central_Bank_state * current = (xmachine_memory_Central_Bank_state *)malloc(sizeof(xmachine_memory_Central_Bank_state));
	CHECK_POINTER(current);
	
	current->agents = NULL;
	current->count = 0;
	
	return current;
}

xmachine_memory_Central_Bank * init_Central_Bank_agent()
{
	xmachine_memory_Central_Bank * current = (xmachine_memory_Central_Bank *)malloc(sizeof(xmachine_memory_Central_Bank));
	CHECK_POINTER(current);
	
	current->id = 0;
	init_account_item_array(&current->accounts);
	
	return current;
}

void free_Central_Bank_agent(xmachine_memory_Central_Bank_holder * tmp, xmachine_memory_Central_Bank_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;
	
	free_account_item_array(&tmp->agent->accounts);
	
	
	free(tmp->agent);
	free(tmp);
}

void unittest_init_Central_Bank_agent()
{
	current_xmachine_Central_Bank = (xmachine_memory_Central_Bank *)malloc(sizeof(xmachine_memory_Central_Bank));
	CHECK_POINTER(current);
	
		current_xmachine_Central_Bank->id = 0;
		init_account_item_array(&current_xmachine_Central_Bank->accounts);
		
}

void unittest_free_Central_Bank_agent()
{
	free_account_item_array(&current_xmachine_Central_Bank->accounts);
	
	free(current_xmachine_Central_Bank);
}

void free_Central_Bank_agents()
{
	current_xmachine_Central_Bank_holder = Central_Bank_end_Central_Bank_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		free_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_end_Central_Bank_state);
		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
	}
	current_xmachine_Central_Bank_holder = Central_Bank_start_Central_Bank_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		temp_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
		free_Central_Bank_agent(current_xmachine_Central_Bank_holder, Central_Bank_start_Central_Bank_state);
		current_xmachine_Central_Bank_holder = temp_xmachine_Central_Bank_holder;
	}
}

void free_Central_Bank_states()
{
	free(Central_Bank_end_Central_Bank_state);
	free(Central_Bank_start_Central_Bank_state);
}

void transition_Central_Bank_agent(xmachine_memory_Central_Bank_holder * tmp, xmachine_memory_Central_Bank_state * from_state, xmachine_memory_Central_Bank_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;	
	
	add_Central_Bank_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Central_Bank_agent_internal(xmachine_memory_Central_Bank * agent, xmachine_memory_Central_Bank_state * state)
{
	xmachine_memory_Central_Bank_holder * current = (xmachine_memory_Central_Bank_holder *)malloc(sizeof(xmachine_memory_Central_Bank_holder));
	CHECK_POINTER(current);
	
	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;
	
	state->count++;

}

/** \fn void add_Central_Bank_agent(int id, account_item_array * accounts)
 * \brief Add Central_Bank X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param accounts Variable for the X-machine memory.
 */
void add_Central_Bank_agent(int id, account_item_array * accounts)
{
	xmachine_memory_Central_Bank * current;
	
	current = init_Central_Bank_agent();
	add_Central_Bank_agent_internal(current, current_xmachine_Central_Bank_next_state);
	
	current->id = id;
	copy_account_item_array(accounts, &current->accounts);
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	free_Firm_agents();
	free_Household_agents();
	free_Mall_agents();
	free_IGFirm_agents();
	free_Eurostat_agents();
	free_Clearinghouse_agents();
	free_Bank_agents();
	free_Government_agents();
	free_Central_Bank_agents();
	
}


/** \fn void set_id(int id) 
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(int id)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).id = id;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).id = id;
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).id = id;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).id = id;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).id = id;
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).id = id;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).id = id;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).id = id;
	if(current_xmachine->xmachine_Central_Bank) (*current_xmachine->xmachine_Central_Bank).id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).id;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).id;
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).id;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).id;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).id;
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).id;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).id;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).id;
	if(current_xmachine->xmachine_Central_Bank) return (*current_xmachine->xmachine_Central_Bank).id;

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
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).region_id = region_id;
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).region_id = region_id;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).region_id = region_id;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).region_id = region_id;
	if(current_xmachine->xmachine_Clearinghouse) (*current_xmachine->xmachine_Clearinghouse).region_id = region_id;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).region_id = region_id;
}

/** \fn int get_region_id()
 * \brief Get region_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_region_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).region_id;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).region_id;
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).region_id;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).region_id;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).region_id;
	if(current_xmachine->xmachine_Clearinghouse) return (*current_xmachine->xmachine_Clearinghouse).region_id;
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
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).gov_id = gov_id;
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).gov_id = gov_id;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).gov_id = gov_id;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).gov_id = gov_id;
}

/** \fn int get_gov_id()
 * \brief Get gov_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_gov_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).gov_id;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).gov_id;
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).gov_id;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).gov_id;
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
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).day_of_month_to_act = day_of_month_to_act;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).day_of_month_to_act = day_of_month_to_act;
}

/** \fn int get_day_of_month_to_act()
 * \brief Get day_of_month_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_to_act()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).day_of_month_to_act;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).day_of_month_to_act;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).day_of_month_to_act;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).day_of_month_to_act;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).day_of_month_to_act;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_last_day_of_month_to_act(int last_day_of_month_to_act) 
 * \brief Set last_day_of_month_to_act memory variable for current X-machine.
 * \param last_day_of_month_to_act New value for variable.
 */
void set_last_day_of_month_to_act(int last_day_of_month_to_act)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).last_day_of_month_to_act = last_day_of_month_to_act;
}

/** \fn int get_last_day_of_month_to_act()
 * \brief Get last_day_of_month_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_last_day_of_month_to_act()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).last_day_of_month_to_act;

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
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).payment_account = payment_account;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).payment_account = payment_account;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).payment_account = payment_account;
}

/** \fn double get_payment_account()
 * \brief Get payment_account memory variable from current X-machine.
 * \return Value for variable.
 */
double get_payment_account()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).payment_account;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).payment_account;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).payment_account;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).payment_account;

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
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).bank_id = bank_id;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).bank_id = bank_id;
}

/** \fn int get_bank_id()
 * \brief Get bank_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bank_id()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).bank_id;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).bank_id;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).bank_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_mean_wage(double mean_wage) 
 * \brief Set mean_wage memory variable for current X-machine.
 * \param mean_wage New value for variable.
 */
void set_mean_wage(double mean_wage)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).mean_wage = mean_wage;
}

/** \fn double get_mean_wage()
 * \brief Get mean_wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_mean_wage()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).mean_wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_needed_capital_stock(double needed_capital_stock) 
 * \brief Set needed_capital_stock memory variable for current X-machine.
 * \param needed_capital_stock New value for variable.
 */
void set_needed_capital_stock(double needed_capital_stock)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).needed_capital_stock = needed_capital_stock;
}

/** \fn double get_needed_capital_stock()
 * \brief Get needed_capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
double get_needed_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).needed_capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_actual_cap_price(double actual_cap_price) 
 * \brief Set actual_cap_price memory variable for current X-machine.
 * \param actual_cap_price New value for variable.
 */
void set_actual_cap_price(double actual_cap_price)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).actual_cap_price = actual_cap_price;
}

/** \fn double get_actual_cap_price()
 * \brief Get actual_cap_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_actual_cap_price()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).actual_cap_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_mean_specific_skills(double mean_specific_skills) 
 * \brief Set mean_specific_skills memory variable for current X-machine.
 * \param mean_specific_skills New value for variable.
 */
void set_mean_specific_skills(double mean_specific_skills)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).mean_specific_skills = mean_specific_skills;
}

/** \fn double get_mean_specific_skills()
 * \brief Get mean_specific_skills memory variable from current X-machine.
 * \return Value for variable.
 */
double get_mean_specific_skills()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).mean_specific_skills;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_production_quantity(double planned_production_quantity) 
 * \brief Set planned_production_quantity memory variable for current X-machine.
 * \param planned_production_quantity New value for variable.
 */
void set_planned_production_quantity(double planned_production_quantity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_production_quantity = planned_production_quantity;
}

/** \fn double get_planned_production_quantity()
 * \brief Get planned_production_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_production_quantity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_production_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_production_quantity(double production_quantity) 
 * \brief Set production_quantity memory variable for current X-machine.
 * \param production_quantity New value for variable.
 */
void set_production_quantity(double production_quantity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).production_quantity = production_quantity;
}

/** \fn double get_production_quantity()
 * \brief Get production_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_production_quantity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).production_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_output(double planned_output) 
 * \brief Set planned_output memory variable for current X-machine.
 * \param planned_output New value for variable.
 */
void set_planned_output(double planned_output)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_output = planned_output;
}

/** \fn double get_planned_output()
 * \brief Get planned_output memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_output()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_output;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_output(double output) 
 * \brief Set output memory variable for current X-machine.
 * \param output New value for variable.
 */
void set_output(double output)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).output = output;
}

/** \fn double get_output()
 * \brief Get output memory variable from current X-machine.
 * \return Value for variable.
 */
double get_output()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).output;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unit_costs(double unit_costs) 
 * \brief Set unit_costs memory variable for current X-machine.
 * \param unit_costs New value for variable.
 */
void set_unit_costs(double unit_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).unit_costs = unit_costs;
}

/** \fn double get_unit_costs()
 * \brief Get unit_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unit_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).unit_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_supply(double total_supply) 
 * \brief Set total_supply memory variable for current X-machine.
 * \param total_supply New value for variable.
 */
void set_total_supply(double total_supply)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_supply = total_supply;
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).total_supply = total_supply;
}

/** \fn double get_total_supply()
 * \brief Get total_supply memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_supply()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_supply;
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).total_supply;

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

/** \fn void set_revenue_per_day(double revenue_per_day) 
 * \brief Set revenue_per_day memory variable for current X-machine.
 * \param revenue_per_day New value for variable.
 */
void set_revenue_per_day(double revenue_per_day)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).revenue_per_day = revenue_per_day;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).revenue_per_day = revenue_per_day;
}

/** \fn double get_revenue_per_day()
 * \brief Get revenue_per_day memory variable from current X-machine.
 * \return Value for variable.
 */
double get_revenue_per_day()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).revenue_per_day;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).revenue_per_day;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_technological_frontier(double technological_frontier) 
 * \brief Set technological_frontier memory variable for current X-machine.
 * \param technological_frontier New value for variable.
 */
void set_technological_frontier(double technological_frontier)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).technological_frontier = technological_frontier;
}

/** \fn double get_technological_frontier()
 * \brief Get technological_frontier memory variable from current X-machine.
 * \return Value for variable.
 */
double get_technological_frontier()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).technological_frontier;

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

/** \fn void set_out_of_stock_costs(double out_of_stock_costs) 
 * \brief Set out_of_stock_costs memory variable for current X-machine.
 * \param out_of_stock_costs New value for variable.
 */
void set_out_of_stock_costs(double out_of_stock_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).out_of_stock_costs = out_of_stock_costs;
}

/** \fn double get_out_of_stock_costs()
 * \brief Get out_of_stock_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_out_of_stock_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).out_of_stock_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn sales_statistics_array get_malls_sales_statistics()
 * \brief Get malls_sales_statistics memory variable from current X-machine.
 * \return Value for variable.
 */
sales_statistics_array * get_malls_sales_statistics()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).malls_sales_statistics;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_quality(double quality) 
 * \brief Set quality memory variable for current X-machine.
 * \param quality New value for variable.
 */
void set_quality(double quality)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).quality = quality;
}

/** \fn double get_quality()
 * \brief Get quality memory variable from current X-machine.
 * \return Value for variable.
 */
double get_quality()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).quality;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
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

/** \fn void set_price_last_month(double price_last_month) 
 * \brief Set price_last_month memory variable for current X-machine.
 * \param price_last_month New value for variable.
 */
void set_price_last_month(double price_last_month)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).price_last_month = price_last_month;
}

/** \fn double get_price_last_month()
 * \brief Get price_last_month memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price_last_month()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).price_last_month;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_demand_capital_stock(double demand_capital_stock) 
 * \brief Set demand_capital_stock memory variable for current X-machine.
 * \param demand_capital_stock New value for variable.
 */
void set_demand_capital_stock(double demand_capital_stock)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).demand_capital_stock = demand_capital_stock;
}

/** \fn double get_demand_capital_stock()
 * \brief Get demand_capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
double get_demand_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).demand_capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_production_costs(double planned_production_costs) 
 * \brief Set planned_production_costs memory variable for current X-machine.
 * \param planned_production_costs New value for variable.
 */
void set_planned_production_costs(double planned_production_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_production_costs = planned_production_costs;
}

/** \fn double get_planned_production_costs()
 * \brief Get planned_production_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_production_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_production_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_adaption_production_volume_due_to_insufficient_finances(double adaption_production_volume_due_to_insufficient_finances) 
 * \brief Set adaption_production_volume_due_to_insufficient_finances memory variable for current X-machine.
 * \param adaption_production_volume_due_to_insufficient_finances New value for variable.
 */
void set_adaption_production_volume_due_to_insufficient_finances(double adaption_production_volume_due_to_insufficient_finances)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).adaption_production_volume_due_to_insufficient_finances = adaption_production_volume_due_to_insufficient_finances;
}

/** \fn double get_adaption_production_volume_due_to_insufficient_finances()
 * \brief Get adaption_production_volume_due_to_insufficient_finances memory variable from current X-machine.
 * \return Value for variable.
 */
double get_adaption_production_volume_due_to_insufficient_finances()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).adaption_production_volume_due_to_insufficient_finances;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_fraction_reserved_for_delayed_payments(double fraction_reserved_for_delayed_payments) 
 * \brief Set fraction_reserved_for_delayed_payments memory variable for current X-machine.
 * \param fraction_reserved_for_delayed_payments New value for variable.
 */
void set_fraction_reserved_for_delayed_payments(double fraction_reserved_for_delayed_payments)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).fraction_reserved_for_delayed_payments = fraction_reserved_for_delayed_payments;
}

/** \fn double get_fraction_reserved_for_delayed_payments()
 * \brief Get fraction_reserved_for_delayed_payments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_fraction_reserved_for_delayed_payments()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).fraction_reserved_for_delayed_payments;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn sold_quantities_per_mall_array get_sold_quantities()
 * \brief Get sold_quantities memory variable from current X-machine.
 * \return Value for variable.
 */
sold_quantities_per_mall_array * get_sold_quantities()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).sold_quantities;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_sold_quantity(double total_sold_quantity) 
 * \brief Set total_sold_quantity memory variable for current X-machine.
 * \param total_sold_quantity New value for variable.
 */
void set_total_sold_quantity(double total_sold_quantity)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_sold_quantity = total_sold_quantity;
}

/** \fn double get_total_sold_quantity()
 * \brief Get total_sold_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_sold_quantity()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_sold_quantity;

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

/** \fn delivery_volume_per_mall_array get_delivery_volume()
 * \brief Get delivery_volume memory variable from current X-machine.
 * \return Value for variable.
 */
delivery_volume_per_mall_array * get_delivery_volume()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).delivery_volume;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn delivery_volume_per_mall_array get_planned_delivery_volume()
 * \brief Get planned_delivery_volume memory variable from current X-machine.
 * \return Value for variable.
 */
delivery_volume_per_mall_array * get_planned_delivery_volume()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).planned_delivery_volume;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
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

/** \fn double_array get_last_planned_production_quantities()
 * \brief Get last_planned_production_quantities memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_last_planned_production_quantities()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).last_planned_production_quantities;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_external_financing_obtained(double total_external_financing_obtained) 
 * \brief Set total_external_financing_obtained memory variable for current X-machine.
 * \param total_external_financing_obtained New value for variable.
 */
void set_total_external_financing_obtained(double total_external_financing_obtained)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_external_financing_obtained = total_external_financing_obtained;
}

/** \fn double get_total_external_financing_obtained()
 * \brief Get total_external_financing_obtained memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_external_financing_obtained()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_external_financing_obtained;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_capital_costs(double capital_costs) 
 * \brief Set capital_costs memory variable for current X-machine.
 * \param capital_costs New value for variable.
 */
void set_capital_costs(double capital_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).capital_costs = capital_costs;
}

/** \fn double get_capital_costs()
 * \brief Get capital_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_capital_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).capital_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_labour_costs(double labour_costs) 
 * \brief Set labour_costs memory variable for current X-machine.
 * \param labour_costs New value for variable.
 */
void set_labour_costs(double labour_costs)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).labour_costs = labour_costs;
}

/** \fn double get_labour_costs()
 * \brief Get labour_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_labour_costs()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).labour_costs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn financing_capital_array get_capital_financing()
 * \brief Get capital_financing memory variable from current X-machine.
 * \return Value for variable.
 */
financing_capital_array * get_capital_financing()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).capital_financing;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_financial_resources_for_production(double financial_resources_for_production) 
 * \brief Set financial_resources_for_production memory variable for current X-machine.
 * \param financial_resources_for_production New value for variable.
 */
void set_financial_resources_for_production(double financial_resources_for_production)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).financial_resources_for_production = financial_resources_for_production;
}

/** \fn double get_financial_resources_for_production()
 * \brief Get financial_resources_for_production memory variable from current X-machine.
 * \return Value for variable.
 */
double get_financial_resources_for_production()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).financial_resources_for_production;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_planned_value_capital_stock(double planned_value_capital_stock) 
 * \brief Set planned_value_capital_stock memory variable for current X-machine.
 * \param planned_value_capital_stock New value for variable.
 */
void set_planned_value_capital_stock(double planned_value_capital_stock)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).planned_value_capital_stock = planned_value_capital_stock;
}

/** \fn double get_planned_value_capital_stock()
 * \brief Get planned_value_capital_stock memory variable from current X-machine.
 * \return Value for variable.
 */
double get_planned_value_capital_stock()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).planned_value_capital_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_units_local_inventory(double total_units_local_inventory) 
 * \brief Set total_units_local_inventory memory variable for current X-machine.
 * \param total_units_local_inventory New value for variable.
 */
void set_total_units_local_inventory(double total_units_local_inventory)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_units_local_inventory = total_units_local_inventory;
}

/** \fn double get_total_units_local_inventory()
 * \brief Get total_units_local_inventory memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_units_local_inventory()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_units_local_inventory;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
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
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).tax_rate_corporate = tax_rate_corporate;
	if(current_xmachine->xmachine_Bank) (*current_xmachine->xmachine_Bank).tax_rate_corporate = tax_rate_corporate;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).tax_rate_corporate = tax_rate_corporate;
}

/** \fn double get_tax_rate_corporate()
 * \brief Get tax_rate_corporate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_corporate()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).tax_rate_corporate;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).tax_rate_corporate;
	if(current_xmachine->xmachine_Bank) return (*current_xmachine->xmachine_Bank).tax_rate_corporate;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).tax_rate_corporate;

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
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).tax_rate_vat = tax_rate_vat;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).tax_rate_vat = tax_rate_vat;
}

/** \fn double get_tax_rate_vat()
 * \brief Get tax_rate_vat memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_vat()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).tax_rate_vat;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).tax_rate_vat;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).tax_rate_vat;

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
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).tax_payment = tax_payment;
}

/** \fn double get_tax_payment()
 * \brief Get tax_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).tax_payment;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).tax_payment;

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
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).current_dividend_per_share = current_dividend_per_share;
}

/** \fn double get_current_dividend_per_share()
 * \brief Get current_dividend_per_share memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_dividend_per_share()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_dividend_per_share;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).current_dividend_per_share;

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
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).total_debt = total_debt;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_debt = total_debt;
}

/** \fn double get_total_debt()
 * \brief Get total_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_debt()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_debt;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).total_debt;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_debt;

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
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).total_assets = total_assets;
}

/** \fn double get_total_assets()
 * \brief Get total_assets memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_assets()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_assets;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).total_assets;

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

/** \fn void set_total_interest_payments(double total_interest_payments) 
 * \brief Set total_interest_payments memory variable for current X-machine.
 * \param total_interest_payments New value for variable.
 */
void set_total_interest_payments(double total_interest_payments)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).total_interest_payments = total_interest_payments;
}

/** \fn double get_total_interest_payments()
 * \brief Get total_interest_payments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_interest_payments()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).total_interest_payments;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_previous_shares_outstanding(double previous_shares_outstanding) 
 * \brief Set previous_shares_outstanding memory variable for current X-machine.
 * \param previous_shares_outstanding New value for variable.
 */
void set_previous_shares_outstanding(double previous_shares_outstanding)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).previous_shares_outstanding = previous_shares_outstanding;
}

/** \fn double get_previous_shares_outstanding()
 * \brief Get previous_shares_outstanding memory variable from current X-machine.
 * \return Value for variable.
 */
double get_previous_shares_outstanding()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).previous_shares_outstanding;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_earnings_payout(double earnings_payout) 
 * \brief Set earnings_payout memory variable for current X-machine.
 * \param earnings_payout New value for variable.
 */
void set_earnings_payout(double earnings_payout)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).earnings_payout = earnings_payout;
}

/** \fn double get_earnings_payout()
 * \brief Get earnings_payout memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earnings_payout()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).earnings_payout;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_shares_outstanding(double current_shares_outstanding) 
 * \brief Set current_shares_outstanding memory variable for current X-machine.
 * \param current_shares_outstanding New value for variable.
 */
void set_current_shares_outstanding(double current_shares_outstanding)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).current_shares_outstanding = current_shares_outstanding;
}

/** \fn double get_current_shares_outstanding()
 * \brief Get current_shares_outstanding memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_shares_outstanding()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).current_shares_outstanding;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn Stock get_stock()
 * \brief Get stock memory variable from current X-machine.
 * \return Value for variable.
 */
Stock * get_stock()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn employee_array get_employees()
 * \brief Get employees memory variable from current X-machine.
 * \return Value for variable.
 */
employee_array * get_employees()
{
	if(current_xmachine->xmachine_Firm) return &(*current_xmachine->xmachine_Firm).employees;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_wage_offer(double wage_offer) 
 * \brief Set wage_offer memory variable for current X-machine.
 * \param wage_offer New value for variable.
 */
void set_wage_offer(double wage_offer)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer = wage_offer;
}

/** \fn double get_wage_offer()
 * \brief Get wage_offer memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_technology(double technology) 
 * \brief Set technology memory variable for current X-machine.
 * \param technology New value for variable.
 */
void set_technology(double technology)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).technology = technology;
}

/** \fn double get_technology()
 * \brief Get technology memory variable from current X-machine.
 * \return Value for variable.
 */
double get_technology()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).technology;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_no_employees(int no_employees) 
 * \brief Set no_employees memory variable for current X-machine.
 * \param no_employees New value for variable.
 */
void set_no_employees(int no_employees)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees = no_employees;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_employees = no_employees;
}

/** \fn int get_no_employees()
 * \brief Get no_employees memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_employees;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_1(int no_employees_skill_1) 
 * \brief Set no_employees_skill_1 memory variable for current X-machine.
 * \param no_employees_skill_1 New value for variable.
 */
void set_no_employees_skill_1(int no_employees_skill_1)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_1 = no_employees_skill_1;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_employees_skill_1 = no_employees_skill_1;
}

/** \fn int get_no_employees_skill_1()
 * \brief Get no_employees_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_1()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_1;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_employees_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_2(int no_employees_skill_2) 
 * \brief Set no_employees_skill_2 memory variable for current X-machine.
 * \param no_employees_skill_2 New value for variable.
 */
void set_no_employees_skill_2(int no_employees_skill_2)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_2 = no_employees_skill_2;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_employees_skill_2 = no_employees_skill_2;
}

/** \fn int get_no_employees_skill_2()
 * \brief Get no_employees_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_2()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_2;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_employees_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_3(int no_employees_skill_3) 
 * \brief Set no_employees_skill_3 memory variable for current X-machine.
 * \param no_employees_skill_3 New value for variable.
 */
void set_no_employees_skill_3(int no_employees_skill_3)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_3 = no_employees_skill_3;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_employees_skill_3 = no_employees_skill_3;
}

/** \fn int get_no_employees_skill_3()
 * \brief Get no_employees_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_3()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_3;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_employees_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_4(int no_employees_skill_4) 
 * \brief Set no_employees_skill_4 memory variable for current X-machine.
 * \param no_employees_skill_4 New value for variable.
 */
void set_no_employees_skill_4(int no_employees_skill_4)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_4 = no_employees_skill_4;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_employees_skill_4 = no_employees_skill_4;
}

/** \fn int get_no_employees_skill_4()
 * \brief Get no_employees_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_4()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_4;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_employees_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_employees_skill_5(int no_employees_skill_5) 
 * \brief Set no_employees_skill_5 memory variable for current X-machine.
 * \param no_employees_skill_5 New value for variable.
 */
void set_no_employees_skill_5(int no_employees_skill_5)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).no_employees_skill_5 = no_employees_skill_5;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_employees_skill_5 = no_employees_skill_5;
}

/** \fn int get_no_employees_skill_5()
 * \brief Get no_employees_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_employees_skill_5()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).no_employees_skill_5;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_employees_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_vacancies(int vacancies) 
 * \brief Set vacancies memory variable for current X-machine.
 * \param vacancies New value for variable.
 */
void set_vacancies(int vacancies)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).vacancies = vacancies;
}

/** \fn int get_vacancies()
 * \brief Get vacancies memory variable from current X-machine.
 * \return Value for variable.
 */
int get_vacancies()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).vacancies;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_average_g_skill(double average_g_skill) 
 * \brief Set average_g_skill memory variable for current X-machine.
 * \param average_g_skill New value for variable.
 */
void set_average_g_skill(double average_g_skill)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_g_skill = average_g_skill;
}

/** \fn double get_average_g_skill()
 * \brief Get average_g_skill memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_g_skill()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_g_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_1(double average_s_skill_of_1) 
 * \brief Set average_s_skill_of_1 memory variable for current X-machine.
 * \param average_s_skill_of_1 New value for variable.
 */
void set_average_s_skill_of_1(double average_s_skill_of_1)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_1 = average_s_skill_of_1;
}

/** \fn double get_average_s_skill_of_1()
 * \brief Get average_s_skill_of_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_1()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_2(double average_s_skill_of_2) 
 * \brief Set average_s_skill_of_2 memory variable for current X-machine.
 * \param average_s_skill_of_2 New value for variable.
 */
void set_average_s_skill_of_2(double average_s_skill_of_2)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_2 = average_s_skill_of_2;
}

/** \fn double get_average_s_skill_of_2()
 * \brief Get average_s_skill_of_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_2()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_3(double average_s_skill_of_3) 
 * \brief Set average_s_skill_of_3 memory variable for current X-machine.
 * \param average_s_skill_of_3 New value for variable.
 */
void set_average_s_skill_of_3(double average_s_skill_of_3)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_3 = average_s_skill_of_3;
}

/** \fn double get_average_s_skill_of_3()
 * \brief Get average_s_skill_of_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_3()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_4(double average_s_skill_of_4) 
 * \brief Set average_s_skill_of_4 memory variable for current X-machine.
 * \param average_s_skill_of_4 New value for variable.
 */
void set_average_s_skill_of_4(double average_s_skill_of_4)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_4 = average_s_skill_of_4;
}

/** \fn double get_average_s_skill_of_4()
 * \brief Get average_s_skill_of_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_4()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_of_5(double average_s_skill_of_5) 
 * \brief Set average_s_skill_of_5 memory variable for current X-machine.
 * \param average_s_skill_of_5 New value for variable.
 */
void set_average_s_skill_of_5(double average_s_skill_of_5)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).average_s_skill_of_5 = average_s_skill_of_5;
}

/** \fn double get_average_s_skill_of_5()
 * \brief Get average_s_skill_of_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_of_5()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).average_s_skill_of_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_1(double wage_offer_for_skill_1) 
 * \brief Set wage_offer_for_skill_1 memory variable for current X-machine.
 * \param wage_offer_for_skill_1 New value for variable.
 */
void set_wage_offer_for_skill_1(double wage_offer_for_skill_1)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_1 = wage_offer_for_skill_1;
}

/** \fn double get_wage_offer_for_skill_1()
 * \brief Get wage_offer_for_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_1()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_2(double wage_offer_for_skill_2) 
 * \brief Set wage_offer_for_skill_2 memory variable for current X-machine.
 * \param wage_offer_for_skill_2 New value for variable.
 */
void set_wage_offer_for_skill_2(double wage_offer_for_skill_2)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_2 = wage_offer_for_skill_2;
}

/** \fn double get_wage_offer_for_skill_2()
 * \brief Get wage_offer_for_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_2()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_3(double wage_offer_for_skill_3) 
 * \brief Set wage_offer_for_skill_3 memory variable for current X-machine.
 * \param wage_offer_for_skill_3 New value for variable.
 */
void set_wage_offer_for_skill_3(double wage_offer_for_skill_3)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_3 = wage_offer_for_skill_3;
}

/** \fn double get_wage_offer_for_skill_3()
 * \brief Get wage_offer_for_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_3()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_4(double wage_offer_for_skill_4) 
 * \brief Set wage_offer_for_skill_4 memory variable for current X-machine.
 * \param wage_offer_for_skill_4 New value for variable.
 */
void set_wage_offer_for_skill_4(double wage_offer_for_skill_4)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_4 = wage_offer_for_skill_4;
}

/** \fn double get_wage_offer_for_skill_4()
 * \brief Get wage_offer_for_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_4()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_offer_for_skill_5(double wage_offer_for_skill_5) 
 * \brief Set wage_offer_for_skill_5 memory variable for current X-machine.
 * \param wage_offer_for_skill_5 New value for variable.
 */
void set_wage_offer_for_skill_5(double wage_offer_for_skill_5)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).wage_offer_for_skill_5 = wage_offer_for_skill_5;
}

/** \fn double get_wage_offer_for_skill_5()
 * \brief Get wage_offer_for_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_offer_for_skill_5()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).wage_offer_for_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_employees_needed(int employees_needed) 
 * \brief Set employees_needed memory variable for current X-machine.
 * \param employees_needed New value for variable.
 */
void set_employees_needed(int employees_needed)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).employees_needed = employees_needed;
}

/** \fn int get_employees_needed()
 * \brief Get employees_needed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employees_needed()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).employees_needed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_age(int age) 
 * \brief Set age memory variable for current X-machine.
 * \param age New value for variable.
 */
void set_age(int age)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).age = age;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).age = age;
}

/** \fn int get_age()
 * \brief Get age memory variable from current X-machine.
 * \return Value for variable.
 */
int get_age()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).age;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).age;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_transfer_payment(double transfer_payment) 
 * \brief Set transfer_payment memory variable for current X-machine.
 * \param transfer_payment New value for variable.
 */
void set_transfer_payment(double transfer_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).transfer_payment = transfer_payment;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).transfer_payment = transfer_payment;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).transfer_payment = transfer_payment;
}

/** \fn double get_transfer_payment()
 * \brief Get transfer_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_transfer_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).transfer_payment;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).transfer_payment;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).transfer_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_subsidy_payment(double subsidy_payment) 
 * \brief Set subsidy_payment memory variable for current X-machine.
 * \param subsidy_payment New value for variable.
 */
void set_subsidy_payment(double subsidy_payment)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).subsidy_payment = subsidy_payment;
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).subsidy_payment = subsidy_payment;
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).subsidy_payment = subsidy_payment;
}

/** \fn double get_subsidy_payment()
 * \brief Get subsidy_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_subsidy_payment()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).subsidy_payment;
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).subsidy_payment;
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).subsidy_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_active(int active) 
 * \brief Set active memory variable for current X-machine.
 * \param active New value for variable.
 */
void set_active(int active)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).active = active;
}

/** \fn int get_active()
 * \brief Get active memory variable from current X-machine.
 * \return Value for variable.
 */
int get_active()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).active;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_bankruptcy_idle_counter(int bankruptcy_idle_counter) 
 * \brief Set bankruptcy_idle_counter memory variable for current X-machine.
 * \param bankruptcy_idle_counter New value for variable.
 */
void set_bankruptcy_idle_counter(int bankruptcy_idle_counter)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).bankruptcy_idle_counter = bankruptcy_idle_counter;
}

/** \fn int get_bankruptcy_idle_counter()
 * \brief Get bankruptcy_idle_counter memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bankruptcy_idle_counter()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).bankruptcy_idle_counter;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
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

/** \fn void set_bankruptcy_insolvency_state(int bankruptcy_insolvency_state) 
 * \brief Set bankruptcy_insolvency_state memory variable for current X-machine.
 * \param bankruptcy_insolvency_state New value for variable.
 */
void set_bankruptcy_insolvency_state(int bankruptcy_insolvency_state)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).bankruptcy_insolvency_state = bankruptcy_insolvency_state;
}

/** \fn int get_bankruptcy_insolvency_state()
 * \brief Get bankruptcy_insolvency_state memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bankruptcy_insolvency_state()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).bankruptcy_insolvency_state;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_bankruptcy_illiquidity_state(int bankruptcy_illiquidity_state) 
 * \brief Set bankruptcy_illiquidity_state memory variable for current X-machine.
 * \param bankruptcy_illiquidity_state New value for variable.
 */
void set_bankruptcy_illiquidity_state(int bankruptcy_illiquidity_state)
{
	if(current_xmachine->xmachine_Firm) (*current_xmachine->xmachine_Firm).bankruptcy_illiquidity_state = bankruptcy_illiquidity_state;
}

/** \fn int get_bankruptcy_illiquidity_state()
 * \brief Get bankruptcy_illiquidity_state memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bankruptcy_illiquidity_state()
{
	if(current_xmachine->xmachine_Firm) return (*current_xmachine->xmachine_Firm).bankruptcy_illiquidity_state;

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

/** \fn int_array get_neighboring_region_ids()
 * \brief Get neighboring_region_ids memory variable from current X-machine.
 * \return Value for variable.
 */
int_array * get_neighboring_region_ids()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).neighboring_region_ids;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_consumption_budget(double consumption_budget) 
 * \brief Set consumption_budget memory variable for current X-machine.
 * \param consumption_budget New value for variable.
 */
void set_consumption_budget(double consumption_budget)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).consumption_budget = consumption_budget;
}

/** \fn double get_consumption_budget()
 * \brief Get consumption_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_consumption_budget()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).consumption_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_mean_income(double mean_income) 
 * \brief Set mean_income memory variable for current X-machine.
 * \param mean_income New value for variable.
 */
void set_mean_income(double mean_income)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).mean_income = mean_income;
}

/** \fn double get_mean_income()
 * \brief Get mean_income memory variable from current X-machine.
 * \return Value for variable.
 */
double get_mean_income()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).mean_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_week_of_month(int week_of_month) 
 * \brief Set week_of_month memory variable for current X-machine.
 * \param week_of_month New value for variable.
 */
void set_week_of_month(int week_of_month)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).week_of_month = week_of_month;
}

/** \fn int get_week_of_month()
 * \brief Get week_of_month memory variable from current X-machine.
 * \return Value for variable.
 */
int get_week_of_month()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).week_of_month;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_weekly_budget(double weekly_budget) 
 * \brief Set weekly_budget memory variable for current X-machine.
 * \param weekly_budget New value for variable.
 */
void set_weekly_budget(double weekly_budget)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).weekly_budget = weekly_budget;
}

/** \fn double get_weekly_budget()
 * \brief Get weekly_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_weekly_budget()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).weekly_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_rationed(int rationed) 
 * \brief Set rationed memory variable for current X-machine.
 * \param rationed New value for variable.
 */
void set_rationed(int rationed)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).rationed = rationed;
}

/** \fn int get_rationed()
 * \brief Get rationed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_rationed()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).rationed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_mall_completely_sold_out(int mall_completely_sold_out) 
 * \brief Set mall_completely_sold_out memory variable for current X-machine.
 * \param mall_completely_sold_out New value for variable.
 */
void set_mall_completely_sold_out(int mall_completely_sold_out)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).mall_completely_sold_out = mall_completely_sold_out;
}

/** \fn int get_mall_completely_sold_out()
 * \brief Get mall_completely_sold_out memory variable from current X-machine.
 * \return Value for variable.
 */
int get_mall_completely_sold_out()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).mall_completely_sold_out;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn ordered_quantity get_order_quantity()
 * \brief Get order_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
ordered_quantity * get_order_quantity()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).order_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn received_quantities get_received_quantity()
 * \brief Get received_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
received_quantities * get_received_quantity()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).received_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_day_of_week_to_act(int day_of_week_to_act) 
 * \brief Set day_of_week_to_act memory variable for current X-machine.
 * \param day_of_week_to_act New value for variable.
 */
void set_day_of_week_to_act(int day_of_week_to_act)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).day_of_week_to_act = day_of_week_to_act;
}

/** \fn int get_day_of_week_to_act()
 * \brief Get day_of_week_to_act memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_week_to_act()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).day_of_week_to_act;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day_of_month_receive_income(int day_of_month_receive_income) 
 * \brief Set day_of_month_receive_income memory variable for current X-machine.
 * \param day_of_month_receive_income New value for variable.
 */
void set_day_of_month_receive_income(int day_of_month_receive_income)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).day_of_month_receive_income = day_of_month_receive_income;
}

/** \fn int get_day_of_month_receive_income()
 * \brief Get day_of_month_receive_income memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_receive_income()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).day_of_month_receive_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_current_productivity_employer(double current_productivity_employer) 
 * \brief Set current_productivity_employer memory variable for current X-machine.
 * \param current_productivity_employer New value for variable.
 */
void set_current_productivity_employer(double current_productivity_employer)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).current_productivity_employer = current_productivity_employer;
}

/** \fn double get_current_productivity_employer()
 * \brief Get current_productivity_employer memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_productivity_employer()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).current_productivity_employer;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_current_mean_specific_skills_employer(double current_mean_specific_skills_employer) 
 * \brief Set current_mean_specific_skills_employer memory variable for current X-machine.
 * \param current_mean_specific_skills_employer New value for variable.
 */
void set_current_mean_specific_skills_employer(double current_mean_specific_skills_employer)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).current_mean_specific_skills_employer = current_mean_specific_skills_employer;
}

/** \fn double get_current_mean_specific_skills_employer()
 * \brief Get current_mean_specific_skills_employer memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_mean_specific_skills_employer()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).current_mean_specific_skills_employer;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_taxes(double total_taxes) 
 * \brief Set total_taxes memory variable for current X-machine.
 * \param total_taxes New value for variable.
 */
void set_total_taxes(double total_taxes)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).total_taxes = total_taxes;
}

/** \fn double get_total_taxes()
 * \brief Get total_taxes memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_taxes()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).total_taxes;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_cum_total_dividends(double cum_total_dividends) 
 * \brief Set cum_total_dividends memory variable for current X-machine.
 * \param cum_total_dividends New value for variable.
 */
void set_cum_total_dividends(double cum_total_dividends)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).cum_total_dividends = cum_total_dividends;
}

/** \fn double get_cum_total_dividends()
 * \brief Get cum_total_dividends memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cum_total_dividends()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).cum_total_dividends;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate_hh_capital(double tax_rate_hh_capital) 
 * \brief Set tax_rate_hh_capital memory variable for current X-machine.
 * \param tax_rate_hh_capital New value for variable.
 */
void set_tax_rate_hh_capital(double tax_rate_hh_capital)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).tax_rate_hh_capital = tax_rate_hh_capital;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).tax_rate_hh_capital = tax_rate_hh_capital;
}

/** \fn double get_tax_rate_hh_capital()
 * \brief Get tax_rate_hh_capital memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_hh_capital()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).tax_rate_hh_capital;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).tax_rate_hh_capital;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_tax_rate_hh_labour(double tax_rate_hh_labour) 
 * \brief Set tax_rate_hh_labour memory variable for current X-machine.
 * \param tax_rate_hh_labour New value for variable.
 */
void set_tax_rate_hh_labour(double tax_rate_hh_labour)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).tax_rate_hh_labour = tax_rate_hh_labour;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).tax_rate_hh_labour = tax_rate_hh_labour;
}

/** \fn double get_tax_rate_hh_labour()
 * \brief Get tax_rate_hh_labour memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_hh_labour()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).tax_rate_hh_labour;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).tax_rate_hh_labour;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_price_index(double price_index) 
 * \brief Set price_index memory variable for current X-machine.
 * \param price_index New value for variable.
 */
void set_price_index(double price_index)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).price_index = price_index;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).price_index = price_index;
}

/** \fn double get_price_index()
 * \brief Get price_index memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price_index()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).price_index;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).price_index;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_price_index_base_period(double price_index_base_period) 
 * \brief Set price_index_base_period memory variable for current X-machine.
 * \param price_index_base_period New value for variable.
 */
void set_price_index_base_period(double price_index_base_period)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).price_index_base_period = price_index_base_period;
}

/** \fn double get_price_index_base_period()
 * \brief Get price_index_base_period memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price_index_base_period()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).price_index_base_period;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_commuting_costs_price_level_weight(double commuting_costs_price_level_weight) 
 * \brief Set commuting_costs_price_level_weight memory variable for current X-machine.
 * \param commuting_costs_price_level_weight New value for variable.
 */
void set_commuting_costs_price_level_weight(double commuting_costs_price_level_weight)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).commuting_costs_price_level_weight = commuting_costs_price_level_weight;
}

/** \fn double get_commuting_costs_price_level_weight()
 * \brief Get commuting_costs_price_level_weight memory variable from current X-machine.
 * \return Value for variable.
 */
double get_commuting_costs_price_level_weight()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).commuting_costs_price_level_weight;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double_array get_last_income()
 * \brief Get last_income memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_last_income()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).last_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_expenditures(double expenditures) 
 * \brief Set expenditures memory variable for current X-machine.
 * \param expenditures New value for variable.
 */
void set_expenditures(double expenditures)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).expenditures = expenditures;
}

/** \fn double get_expenditures()
 * \brief Get expenditures memory variable from current X-machine.
 * \return Value for variable.
 */
double get_expenditures()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).expenditures;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_received_dividend(double received_dividend) 
 * \brief Set received_dividend memory variable for current X-machine.
 * \param received_dividend New value for variable.
 */
void set_received_dividend(double received_dividend)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).received_dividend = received_dividend;
}

/** \fn double get_received_dividend()
 * \brief Get received_dividend memory variable from current X-machine.
 * \return Value for variable.
 */
double get_received_dividend()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).received_dividend;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wealth(double wealth) 
 * \brief Set wealth memory variable for current X-machine.
 * \param wealth New value for variable.
 */
void set_wealth(double wealth)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).wealth = wealth;
}

/** \fn double get_wealth()
 * \brief Get wealth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wealth()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).wealth;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn Belief_array get_beliefs()
 * \brief Get beliefs memory variable from current X-machine.
 * \return Value for variable.
 */
Belief_array * get_beliefs()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).beliefs;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn Order_array get_pendingOrders()
 * \brief Get pendingOrders memory variable from current X-machine.
 * \return Value for variable.
 */
Order_array * get_pendingOrders()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).pendingOrders;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn Asset_array get_assetsowned()
 * \brief Get assetsowned memory variable from current X-machine.
 * \return Value for variable.
 */
Asset_array * get_assetsowned()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).assetsowned;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double_array get_assetWeights()
 * \brief Get assetWeights memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_assetWeights()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).assetWeights;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double_array get_assetUtilities()
 * \brief Get assetUtilities memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_assetUtilities()
{
	if(current_xmachine->xmachine_Household) return &(*current_xmachine->xmachine_Household).assetUtilities;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_cash_on_hand(double cash_on_hand) 
 * \brief Set cash_on_hand memory variable for current X-machine.
 * \param cash_on_hand New value for variable.
 */
void set_cash_on_hand(double cash_on_hand)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).cash_on_hand = cash_on_hand;
}

/** \fn double get_cash_on_hand()
 * \brief Get cash_on_hand memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cash_on_hand()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).cash_on_hand;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_forwardWindow(int forwardWindow) 
 * \brief Set forwardWindow memory variable for current X-machine.
 * \param forwardWindow New value for variable.
 */
void set_forwardWindow(int forwardWindow)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).forwardWindow = forwardWindow;
}

/** \fn int get_forwardWindow()
 * \brief Get forwardWindow memory variable from current X-machine.
 * \return Value for variable.
 */
int get_forwardWindow()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).forwardWindow;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_backwardWindow(int backwardWindow) 
 * \brief Set backwardWindow memory variable for current X-machine.
 * \param backwardWindow New value for variable.
 */
void set_backwardWindow(int backwardWindow)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).backwardWindow = backwardWindow;
}

/** \fn int get_backwardWindow()
 * \brief Get backwardWindow memory variable from current X-machine.
 * \return Value for variable.
 */
int get_backwardWindow()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).backwardWindow;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_bins(int bins) 
 * \brief Set bins memory variable for current X-machine.
 * \param bins New value for variable.
 */
void set_bins(int bins)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).bins = bins;
}

/** \fn int get_bins()
 * \brief Get bins memory variable from current X-machine.
 * \return Value for variable.
 */
int get_bins()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).bins;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_randomWeight(double randomWeight) 
 * \brief Set randomWeight memory variable for current X-machine.
 * \param randomWeight New value for variable.
 */
void set_randomWeight(double randomWeight)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).randomWeight = randomWeight;
}

/** \fn double get_randomWeight()
 * \brief Get randomWeight memory variable from current X-machine.
 * \return Value for variable.
 */
double get_randomWeight()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).randomWeight;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_fundamentalWeight(double fundamentalWeight) 
 * \brief Set fundamentalWeight memory variable for current X-machine.
 * \param fundamentalWeight New value for variable.
 */
void set_fundamentalWeight(double fundamentalWeight)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).fundamentalWeight = fundamentalWeight;
}

/** \fn double get_fundamentalWeight()
 * \brief Get fundamentalWeight memory variable from current X-machine.
 * \return Value for variable.
 */
double get_fundamentalWeight()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).fundamentalWeight;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_chartistWeight(double chartistWeight) 
 * \brief Set chartistWeight memory variable for current X-machine.
 * \param chartistWeight New value for variable.
 */
void set_chartistWeight(double chartistWeight)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).chartistWeight = chartistWeight;
}

/** \fn double get_chartistWeight()
 * \brief Get chartistWeight memory variable from current X-machine.
 * \return Value for variable.
 */
double get_chartistWeight()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).chartistWeight;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_holdingPeriodToForwardW(int holdingPeriodToForwardW) 
 * \brief Set holdingPeriodToForwardW memory variable for current X-machine.
 * \param holdingPeriodToForwardW New value for variable.
 */
void set_holdingPeriodToForwardW(int holdingPeriodToForwardW)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).holdingPeriodToForwardW = holdingPeriodToForwardW;
}

/** \fn int get_holdingPeriodToForwardW()
 * \brief Get holdingPeriodToForwardW memory variable from current X-machine.
 * \return Value for variable.
 */
int get_holdingPeriodToForwardW()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).holdingPeriodToForwardW;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_lossaversion(double lossaversion) 
 * \brief Set lossaversion memory variable for current X-machine.
 * \param lossaversion New value for variable.
 */
void set_lossaversion(double lossaversion)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).lossaversion = lossaversion;
}

/** \fn double get_lossaversion()
 * \brief Get lossaversion memory variable from current X-machine.
 * \return Value for variable.
 */
double get_lossaversion()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).lossaversion;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_strategy(double strategy) 
 * \brief Set strategy memory variable for current X-machine.
 * \param strategy New value for variable.
 */
void set_strategy(double strategy)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).strategy = strategy;
}

/** \fn double get_strategy()
 * \brief Get strategy memory variable from current X-machine.
 * \return Value for variable.
 */
double get_strategy()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).strategy;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage(double wage) 
 * \brief Set wage memory variable for current X-machine.
 * \param wage New value for variable.
 */
void set_wage(double wage)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).wage = wage;
}

/** \fn double get_wage()
 * \brief Get wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_wage_reservation(double wage_reservation) 
 * \brief Set wage_reservation memory variable for current X-machine.
 * \param wage_reservation New value for variable.
 */
void set_wage_reservation(double wage_reservation)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).wage_reservation = wage_reservation;
}

/** \fn double get_wage_reservation()
 * \brief Get wage_reservation memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wage_reservation()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).wage_reservation;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_general_skill(int general_skill) 
 * \brief Set general_skill memory variable for current X-machine.
 * \param general_skill New value for variable.
 */
void set_general_skill(int general_skill)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).general_skill = general_skill;
}

/** \fn int get_general_skill()
 * \brief Get general_skill memory variable from current X-machine.
 * \return Value for variable.
 */
int get_general_skill()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).general_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_on_the_job_search(int on_the_job_search) 
 * \brief Set on_the_job_search memory variable for current X-machine.
 * \param on_the_job_search New value for variable.
 */
void set_on_the_job_search(int on_the_job_search)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).on_the_job_search = on_the_job_search;
}

/** \fn int get_on_the_job_search()
 * \brief Get on_the_job_search memory variable from current X-machine.
 * \return Value for variable.
 */
int get_on_the_job_search()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).on_the_job_search;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_number_applications(int number_applications) 
 * \brief Set number_applications memory variable for current X-machine.
 * \param number_applications New value for variable.
 */
void set_number_applications(int number_applications)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).number_applications = number_applications;
}

/** \fn int get_number_applications()
 * \brief Get number_applications memory variable from current X-machine.
 * \return Value for variable.
 */
int get_number_applications()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).number_applications;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_last_labour_income(double last_labour_income) 
 * \brief Set last_labour_income memory variable for current X-machine.
 * \param last_labour_income New value for variable.
 */
void set_last_labour_income(double last_labour_income)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).last_labour_income = last_labour_income;
}

/** \fn double get_last_labour_income()
 * \brief Get last_labour_income memory variable from current X-machine.
 * \return Value for variable.
 */
double get_last_labour_income()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).last_labour_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_specific_skill(double specific_skill) 
 * \brief Set specific_skill memory variable for current X-machine.
 * \param specific_skill New value for variable.
 */
void set_specific_skill(double specific_skill)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).specific_skill = specific_skill;
}

/** \fn double get_specific_skill()
 * \brief Get specific_skill memory variable from current X-machine.
 * \return Value for variable.
 */
double get_specific_skill()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).specific_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_employee_firm_id(int employee_firm_id) 
 * \brief Set employee_firm_id memory variable for current X-machine.
 * \param employee_firm_id New value for variable.
 */
void set_employee_firm_id(int employee_firm_id)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).employee_firm_id = employee_firm_id;
}

/** \fn int get_employee_firm_id()
 * \brief Get employee_firm_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employee_firm_id()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).employee_firm_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employer_region_id(int employer_region_id) 
 * \brief Set employer_region_id memory variable for current X-machine.
 * \param employer_region_id New value for variable.
 */
void set_employer_region_id(int employer_region_id)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).employer_region_id = employer_region_id;
}

/** \fn int get_employer_region_id()
 * \brief Get employer_region_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employer_region_id()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).employer_region_id;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_day_of_month_receive_benefit(int day_of_month_receive_benefit) 
 * \brief Set day_of_month_receive_benefit memory variable for current X-machine.
 * \param day_of_month_receive_benefit New value for variable.
 */
void set_day_of_month_receive_benefit(int day_of_month_receive_benefit)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).day_of_month_receive_benefit = day_of_month_receive_benefit;
}

/** \fn int get_day_of_month_receive_benefit()
 * \brief Get day_of_month_receive_benefit memory variable from current X-machine.
 * \return Value for variable.
 */
int get_day_of_month_receive_benefit()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).day_of_month_receive_benefit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_unemployment_benefit_pct(double unemployment_benefit_pct) 
 * \brief Set unemployment_benefit_pct memory variable for current X-machine.
 * \param unemployment_benefit_pct New value for variable.
 */
void set_unemployment_benefit_pct(double unemployment_benefit_pct)
{
	if(current_xmachine->xmachine_Household) (*current_xmachine->xmachine_Household).unemployment_benefit_pct = unemployment_benefit_pct;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).unemployment_benefit_pct = unemployment_benefit_pct;
}

/** \fn double get_unemployment_benefit_pct()
 * \brief Get unemployment_benefit_pct memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_benefit_pct()
{
	if(current_xmachine->xmachine_Household) return (*current_xmachine->xmachine_Household).unemployment_benefit_pct;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).unemployment_benefit_pct;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_no_regions(int no_regions) 
 * \brief Set no_regions memory variable for current X-machine.
 * \param no_regions New value for variable.
 */
void set_no_regions(int no_regions)
{
	if(current_xmachine->xmachine_Mall) (*current_xmachine->xmachine_Mall).no_regions = no_regions;
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_regions = no_regions;
}

/** \fn int get_no_regions()
 * \brief Get no_regions memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_regions()
{
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).no_regions;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_regions;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn mall_stock_array get_current_stock()
 * \brief Get current_stock memory variable from current X-machine.
 * \return Value for variable.
 */
mall_stock_array * get_current_stock()
{
	if(current_xmachine->xmachine_Mall) return &(*current_xmachine->xmachine_Mall).current_stock;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn sales_in_mall_array get_firm_revenues()
 * \brief Get firm_revenues memory variable from current X-machine.
 * \return Value for variable.
 */
sales_in_mall_array * get_firm_revenues()
{
	if(current_xmachine->xmachine_Mall) return &(*current_xmachine->xmachine_Mall).firm_revenues;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_export_volume_matrix()
 * \brief Get export_volume_matrix memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_export_volume_matrix()
{
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).export_volume_matrix;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).export_volume_matrix;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_export_value_matrix()
 * \brief Get export_value_matrix memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_export_value_matrix()
{
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).export_value_matrix;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).export_value_matrix;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_export_previous_value_matrix()
 * \brief Get export_previous_value_matrix memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_export_previous_value_matrix()
{
	if(current_xmachine->xmachine_Mall) return (*current_xmachine->xmachine_Mall).export_previous_value_matrix;
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).export_previous_value_matrix;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_productivity(double productivity) 
 * \brief Set productivity memory variable for current X-machine.
 * \param productivity New value for variable.
 */
void set_productivity(double productivity)
{
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).productivity = productivity;
}

/** \fn double get_productivity()
 * \brief Get productivity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_productivity()
{
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).productivity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_capital_good_price(double capital_good_price) 
 * \brief Set capital_good_price memory variable for current X-machine.
 * \param capital_good_price New value for variable.
 */
void set_capital_good_price(double capital_good_price)
{
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).capital_good_price = capital_good_price;
}

/** \fn double get_capital_good_price()
 * \brief Get capital_good_price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_capital_good_price()
{
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).capital_good_price;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_net_profit(double net_profit) 
 * \brief Set net_profit memory variable for current X-machine.
 * \param net_profit New value for variable.
 */
void set_net_profit(double net_profit)
{
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).net_profit = net_profit;
}

/** \fn double get_net_profit()
 * \brief Get net_profit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_net_profit()
{
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).net_profit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_outstanding_shares(int outstanding_shares) 
 * \brief Set outstanding_shares memory variable for current X-machine.
 * \param outstanding_shares New value for variable.
 */
void set_outstanding_shares(int outstanding_shares)
{
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).outstanding_shares = outstanding_shares;
}

/** \fn int get_outstanding_shares()
 * \brief Get outstanding_shares memory variable from current X-machine.
 * \return Value for variable.
 */
int get_outstanding_shares()
{
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).outstanding_shares;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_cum_revenues(double cum_revenues) 
 * \brief Set cum_revenues memory variable for current X-machine.
 * \param cum_revenues New value for variable.
 */
void set_cum_revenues(double cum_revenues)
{
	if(current_xmachine->xmachine_IGFirm) (*current_xmachine->xmachine_IGFirm).cum_revenues = cum_revenues;
}

/** \fn double get_cum_revenues()
 * \brief Get cum_revenues memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cum_revenues()
{
	if(current_xmachine->xmachine_IGFirm) return (*current_xmachine->xmachine_IGFirm).cum_revenues;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_switch_datastorage(int switch_datastorage) 
 * \brief Set switch_datastorage memory variable for current X-machine.
 * \param switch_datastorage New value for variable.
 */
void set_switch_datastorage(int switch_datastorage)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).switch_datastorage = switch_datastorage;
}

/** \fn int get_switch_datastorage()
 * \brief Get switch_datastorage memory variable from current X-machine.
 * \return Value for variable.
 */
int get_switch_datastorage()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).switch_datastorage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_num_households(int num_households) 
 * \brief Set num_households memory variable for current X-machine.
 * \param num_households New value for variable.
 */
void set_num_households(int num_households)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).num_households = num_households;
}

/** \fn int get_num_households()
 * \brief Get num_households memory variable from current X-machine.
 * \return Value for variable.
 */
int get_num_households()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).num_households;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_1(int no_households_skill_1) 
 * \brief Set no_households_skill_1 memory variable for current X-machine.
 * \param no_households_skill_1 New value for variable.
 */
void set_no_households_skill_1(int no_households_skill_1)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_households_skill_1 = no_households_skill_1;
}

/** \fn int get_no_households_skill_1()
 * \brief Get no_households_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_1()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_households_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_2(int no_households_skill_2) 
 * \brief Set no_households_skill_2 memory variable for current X-machine.
 * \param no_households_skill_2 New value for variable.
 */
void set_no_households_skill_2(int no_households_skill_2)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_households_skill_2 = no_households_skill_2;
}

/** \fn int get_no_households_skill_2()
 * \brief Get no_households_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_2()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_households_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_3(int no_households_skill_3) 
 * \brief Set no_households_skill_3 memory variable for current X-machine.
 * \param no_households_skill_3 New value for variable.
 */
void set_no_households_skill_3(int no_households_skill_3)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_households_skill_3 = no_households_skill_3;
}

/** \fn int get_no_households_skill_3()
 * \brief Get no_households_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_3()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_households_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_4(int no_households_skill_4) 
 * \brief Set no_households_skill_4 memory variable for current X-machine.
 * \param no_households_skill_4 New value for variable.
 */
void set_no_households_skill_4(int no_households_skill_4)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_households_skill_4 = no_households_skill_4;
}

/** \fn int get_no_households_skill_4()
 * \brief Get no_households_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_4()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_households_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_households_skill_5(int no_households_skill_5) 
 * \brief Set no_households_skill_5 memory variable for current X-machine.
 * \param no_households_skill_5 New value for variable.
 */
void set_no_households_skill_5(int no_households_skill_5)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_households_skill_5 = no_households_skill_5;
}

/** \fn int get_no_households_skill_5()
 * \brief Get no_households_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_households_skill_5()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_households_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed(int employed) 
 * \brief Set employed memory variable for current X-machine.
 * \param employed New value for variable.
 */
void set_employed(int employed)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).employed = employed;
}

/** \fn int get_employed()
 * \brief Get employed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).employed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_1(int employed_skill_1) 
 * \brief Set employed_skill_1 memory variable for current X-machine.
 * \param employed_skill_1 New value for variable.
 */
void set_employed_skill_1(int employed_skill_1)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).employed_skill_1 = employed_skill_1;
}

/** \fn int get_employed_skill_1()
 * \brief Get employed_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_1()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).employed_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_2(int employed_skill_2) 
 * \brief Set employed_skill_2 memory variable for current X-machine.
 * \param employed_skill_2 New value for variable.
 */
void set_employed_skill_2(int employed_skill_2)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).employed_skill_2 = employed_skill_2;
}

/** \fn int get_employed_skill_2()
 * \brief Get employed_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_2()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).employed_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_3(int employed_skill_3) 
 * \brief Set employed_skill_3 memory variable for current X-machine.
 * \param employed_skill_3 New value for variable.
 */
void set_employed_skill_3(int employed_skill_3)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).employed_skill_3 = employed_skill_3;
}

/** \fn int get_employed_skill_3()
 * \brief Get employed_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_3()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).employed_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_4(int employed_skill_4) 
 * \brief Set employed_skill_4 memory variable for current X-machine.
 * \param employed_skill_4 New value for variable.
 */
void set_employed_skill_4(int employed_skill_4)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).employed_skill_4 = employed_skill_4;
}

/** \fn int get_employed_skill_4()
 * \brief Get employed_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_4()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).employed_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_employed_skill_5(int employed_skill_5) 
 * \brief Set employed_skill_5 memory variable for current X-machine.
 * \param employed_skill_5 New value for variable.
 */
void set_employed_skill_5(int employed_skill_5)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).employed_skill_5 = employed_skill_5;
}

/** \fn int get_employed_skill_5()
 * \brief Get employed_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_employed_skill_5()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).employed_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_unemployed(int unemployed) 
 * \brief Set unemployed memory variable for current X-machine.
 * \param unemployed New value for variable.
 */
void set_unemployed(int unemployed)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).unemployed = unemployed;
}

/** \fn int get_unemployed()
 * \brief Get unemployed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_unemployed()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).unemployed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_unemployment_rate(double unemployment_rate) 
 * \brief Set unemployment_rate memory variable for current X-machine.
 * \param unemployment_rate New value for variable.
 */
void set_unemployment_rate(double unemployment_rate)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).unemployment_rate = unemployment_rate;
}

/** \fn double get_unemployment_rate()
 * \brief Get unemployment_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).unemployment_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_1(double unemployment_rate_skill_1) 
 * \brief Set unemployment_rate_skill_1 memory variable for current X-machine.
 * \param unemployment_rate_skill_1 New value for variable.
 */
void set_unemployment_rate_skill_1(double unemployment_rate_skill_1)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_1 = unemployment_rate_skill_1;
}

/** \fn double get_unemployment_rate_skill_1()
 * \brief Get unemployment_rate_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_1()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_2(double unemployment_rate_skill_2) 
 * \brief Set unemployment_rate_skill_2 memory variable for current X-machine.
 * \param unemployment_rate_skill_2 New value for variable.
 */
void set_unemployment_rate_skill_2(double unemployment_rate_skill_2)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_2 = unemployment_rate_skill_2;
}

/** \fn double get_unemployment_rate_skill_2()
 * \brief Get unemployment_rate_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_2()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_3(double unemployment_rate_skill_3) 
 * \brief Set unemployment_rate_skill_3 memory variable for current X-machine.
 * \param unemployment_rate_skill_3 New value for variable.
 */
void set_unemployment_rate_skill_3(double unemployment_rate_skill_3)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_3 = unemployment_rate_skill_3;
}

/** \fn double get_unemployment_rate_skill_3()
 * \brief Get unemployment_rate_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_3()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_4(double unemployment_rate_skill_4) 
 * \brief Set unemployment_rate_skill_4 memory variable for current X-machine.
 * \param unemployment_rate_skill_4 New value for variable.
 */
void set_unemployment_rate_skill_4(double unemployment_rate_skill_4)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_4 = unemployment_rate_skill_4;
}

/** \fn double get_unemployment_rate_skill_4()
 * \brief Get unemployment_rate_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_4()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_unemployment_rate_skill_5(double unemployment_rate_skill_5) 
 * \brief Set unemployment_rate_skill_5 memory variable for current X-machine.
 * \param unemployment_rate_skill_5 New value for variable.
 */
void set_unemployment_rate_skill_5(double unemployment_rate_skill_5)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_5 = unemployment_rate_skill_5;
}

/** \fn double get_unemployment_rate_skill_5()
 * \brief Get unemployment_rate_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_unemployment_rate_skill_5()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).unemployment_rate_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage(double average_wage) 
 * \brief Set average_wage memory variable for current X-machine.
 * \param average_wage New value for variable.
 */
void set_average_wage(double average_wage)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_wage = average_wage;
}

/** \fn double get_average_wage()
 * \brief Get average_wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_1(double average_wage_skill_1) 
 * \brief Set average_wage_skill_1 memory variable for current X-machine.
 * \param average_wage_skill_1 New value for variable.
 */
void set_average_wage_skill_1(double average_wage_skill_1)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_wage_skill_1 = average_wage_skill_1;
}

/** \fn double get_average_wage_skill_1()
 * \brief Get average_wage_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_1()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_wage_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_2(double average_wage_skill_2) 
 * \brief Set average_wage_skill_2 memory variable for current X-machine.
 * \param average_wage_skill_2 New value for variable.
 */
void set_average_wage_skill_2(double average_wage_skill_2)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_wage_skill_2 = average_wage_skill_2;
}

/** \fn double get_average_wage_skill_2()
 * \brief Get average_wage_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_2()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_wage_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_3(double average_wage_skill_3) 
 * \brief Set average_wage_skill_3 memory variable for current X-machine.
 * \param average_wage_skill_3 New value for variable.
 */
void set_average_wage_skill_3(double average_wage_skill_3)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_wage_skill_3 = average_wage_skill_3;
}

/** \fn double get_average_wage_skill_3()
 * \brief Get average_wage_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_3()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_wage_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_4(double average_wage_skill_4) 
 * \brief Set average_wage_skill_4 memory variable for current X-machine.
 * \param average_wage_skill_4 New value for variable.
 */
void set_average_wage_skill_4(double average_wage_skill_4)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_wage_skill_4 = average_wage_skill_4;
}

/** \fn double get_average_wage_skill_4()
 * \brief Get average_wage_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_4()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_wage_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_wage_skill_5(double average_wage_skill_5) 
 * \brief Set average_wage_skill_5 memory variable for current X-machine.
 * \param average_wage_skill_5 New value for variable.
 */
void set_average_wage_skill_5(double average_wage_skill_5)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_wage_skill_5 = average_wage_skill_5;
}

/** \fn double get_average_wage_skill_5()
 * \brief Get average_wage_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_wage_skill_5()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_wage_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill(double average_s_skill) 
 * \brief Set average_s_skill memory variable for current X-machine.
 * \param average_s_skill New value for variable.
 */
void set_average_s_skill(double average_s_skill)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_s_skill = average_s_skill;
}

/** \fn double get_average_s_skill()
 * \brief Get average_s_skill memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_s_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_1(double average_s_skill_1) 
 * \brief Set average_s_skill_1 memory variable for current X-machine.
 * \param average_s_skill_1 New value for variable.
 */
void set_average_s_skill_1(double average_s_skill_1)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_s_skill_1 = average_s_skill_1;
}

/** \fn double get_average_s_skill_1()
 * \brief Get average_s_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_1()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_s_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_2(double average_s_skill_2) 
 * \brief Set average_s_skill_2 memory variable for current X-machine.
 * \param average_s_skill_2 New value for variable.
 */
void set_average_s_skill_2(double average_s_skill_2)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_s_skill_2 = average_s_skill_2;
}

/** \fn double get_average_s_skill_2()
 * \brief Get average_s_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_2()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_s_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_3(double average_s_skill_3) 
 * \brief Set average_s_skill_3 memory variable for current X-machine.
 * \param average_s_skill_3 New value for variable.
 */
void set_average_s_skill_3(double average_s_skill_3)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_s_skill_3 = average_s_skill_3;
}

/** \fn double get_average_s_skill_3()
 * \brief Get average_s_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_3()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_s_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_4(double average_s_skill_4) 
 * \brief Set average_s_skill_4 memory variable for current X-machine.
 * \param average_s_skill_4 New value for variable.
 */
void set_average_s_skill_4(double average_s_skill_4)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_s_skill_4 = average_s_skill_4;
}

/** \fn double get_average_s_skill_4()
 * \brief Get average_s_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_4()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_s_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_s_skill_5(double average_s_skill_5) 
 * \brief Set average_s_skill_5 memory variable for current X-machine.
 * \param average_s_skill_5 New value for variable.
 */
void set_average_s_skill_5(double average_s_skill_5)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_s_skill_5 = average_s_skill_5;
}

/** \fn double get_average_s_skill_5()
 * \brief Get average_s_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_s_skill_5()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_s_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_no_firms(int no_firms) 
 * \brief Set no_firms memory variable for current X-machine.
 * \param no_firms New value for variable.
 */
void set_no_firms(int no_firms)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_firms = no_firms;
}

/** \fn int get_no_firms()
 * \brief Get no_firms memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_firms()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_firms;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_vacancies(int no_vacancies) 
 * \brief Set no_vacancies memory variable for current X-machine.
 * \param no_vacancies New value for variable.
 */
void set_no_vacancies(int no_vacancies)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_vacancies = no_vacancies;
}

/** \fn int get_no_vacancies()
 * \brief Get no_vacancies memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_vacancies()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_vacancies;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_firm_average_wage(double firm_average_wage) 
 * \brief Set firm_average_wage memory variable for current X-machine.
 * \param firm_average_wage New value for variable.
 */
void set_firm_average_wage(double firm_average_wage)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_wage = firm_average_wage;
}

/** \fn double get_firm_average_wage()
 * \brief Get firm_average_wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_1(double firm_average_wage_skill_1) 
 * \brief Set firm_average_wage_skill_1 memory variable for current X-machine.
 * \param firm_average_wage_skill_1 New value for variable.
 */
void set_firm_average_wage_skill_1(double firm_average_wage_skill_1)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_1 = firm_average_wage_skill_1;
}

/** \fn double get_firm_average_wage_skill_1()
 * \brief Get firm_average_wage_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_1()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_2(double firm_average_wage_skill_2) 
 * \brief Set firm_average_wage_skill_2 memory variable for current X-machine.
 * \param firm_average_wage_skill_2 New value for variable.
 */
void set_firm_average_wage_skill_2(double firm_average_wage_skill_2)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_2 = firm_average_wage_skill_2;
}

/** \fn double get_firm_average_wage_skill_2()
 * \brief Get firm_average_wage_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_2()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_3(double firm_average_wage_skill_3) 
 * \brief Set firm_average_wage_skill_3 memory variable for current X-machine.
 * \param firm_average_wage_skill_3 New value for variable.
 */
void set_firm_average_wage_skill_3(double firm_average_wage_skill_3)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_3 = firm_average_wage_skill_3;
}

/** \fn double get_firm_average_wage_skill_3()
 * \brief Get firm_average_wage_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_3()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_4(double firm_average_wage_skill_4) 
 * \brief Set firm_average_wage_skill_4 memory variable for current X-machine.
 * \param firm_average_wage_skill_4 New value for variable.
 */
void set_firm_average_wage_skill_4(double firm_average_wage_skill_4)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_4 = firm_average_wage_skill_4;
}

/** \fn double get_firm_average_wage_skill_4()
 * \brief Get firm_average_wage_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_4()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_wage_skill_5(double firm_average_wage_skill_5) 
 * \brief Set firm_average_wage_skill_5 memory variable for current X-machine.
 * \param firm_average_wage_skill_5 New value for variable.
 */
void set_firm_average_wage_skill_5(double firm_average_wage_skill_5)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_5 = firm_average_wage_skill_5;
}

/** \fn double get_firm_average_wage_skill_5()
 * \brief Get firm_average_wage_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_wage_skill_5()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_wage_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill(double firm_average_s_skill) 
 * \brief Set firm_average_s_skill memory variable for current X-machine.
 * \param firm_average_s_skill New value for variable.
 */
void set_firm_average_s_skill(double firm_average_s_skill)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_s_skill = firm_average_s_skill;
}

/** \fn double get_firm_average_s_skill()
 * \brief Get firm_average_s_skill memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_s_skill;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_1(double firm_average_s_skill_1) 
 * \brief Set firm_average_s_skill_1 memory variable for current X-machine.
 * \param firm_average_s_skill_1 New value for variable.
 */
void set_firm_average_s_skill_1(double firm_average_s_skill_1)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_1 = firm_average_s_skill_1;
}

/** \fn double get_firm_average_s_skill_1()
 * \brief Get firm_average_s_skill_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_1()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_2(double firm_average_s_skill_2) 
 * \brief Set firm_average_s_skill_2 memory variable for current X-machine.
 * \param firm_average_s_skill_2 New value for variable.
 */
void set_firm_average_s_skill_2(double firm_average_s_skill_2)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_2 = firm_average_s_skill_2;
}

/** \fn double get_firm_average_s_skill_2()
 * \brief Get firm_average_s_skill_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_2()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_3(double firm_average_s_skill_3) 
 * \brief Set firm_average_s_skill_3 memory variable for current X-machine.
 * \param firm_average_s_skill_3 New value for variable.
 */
void set_firm_average_s_skill_3(double firm_average_s_skill_3)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_3 = firm_average_s_skill_3;
}

/** \fn double get_firm_average_s_skill_3()
 * \brief Get firm_average_s_skill_3 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_3()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_3;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_4(double firm_average_s_skill_4) 
 * \brief Set firm_average_s_skill_4 memory variable for current X-machine.
 * \param firm_average_s_skill_4 New value for variable.
 */
void set_firm_average_s_skill_4(double firm_average_s_skill_4)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_4 = firm_average_s_skill_4;
}

/** \fn double get_firm_average_s_skill_4()
 * \brief Get firm_average_s_skill_4 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_4()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_4;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_average_s_skill_5(double firm_average_s_skill_5) 
 * \brief Set firm_average_s_skill_5 memory variable for current X-machine.
 * \param firm_average_s_skill_5 New value for variable.
 */
void set_firm_average_s_skill_5(double firm_average_s_skill_5)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_5 = firm_average_s_skill_5;
}

/** \fn double get_firm_average_s_skill_5()
 * \brief Get firm_average_s_skill_5 memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_average_s_skill_5()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_average_s_skill_5;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn firm_data_array get_region_firm_data()
 * \brief Get region_firm_data memory variable from current X-machine.
 * \return Value for variable.
 */
firm_data_array * get_region_firm_data()
{
	if(current_xmachine->xmachine_Eurostat) return &(*current_xmachine->xmachine_Eurostat).region_firm_data;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn household_data_array get_region_household_data()
 * \brief Get region_household_data memory variable from current X-machine.
 * \return Value for variable.
 */
household_data_array * get_region_household_data()
{
	if(current_xmachine->xmachine_Eurostat) return &(*current_xmachine->xmachine_Eurostat).region_household_data;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn tax_rates_item get_government_tax_rates()
 * \brief Get government_tax_rates memory variable from current X-machine.
 * \return Value for variable.
 */
tax_rates_item * get_government_tax_rates()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).government_tax_rates;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_total_earnings(double total_earnings) 
 * \brief Set total_earnings memory variable for current X-machine.
 * \param total_earnings New value for variable.
 */
void set_total_earnings(double total_earnings)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).total_earnings = total_earnings;
}

/** \fn double get_total_earnings()
 * \brief Get total_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_earnings()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).total_earnings;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_equity(double total_equity) 
 * \brief Set total_equity memory variable for current X-machine.
 * \param total_equity New value for variable.
 */
void set_total_equity(double total_equity)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).total_equity = total_equity;
}

/** \fn double get_total_equity()
 * \brief Get total_equity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_equity()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).total_equity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_debt_earnings_ratio(double average_debt_earnings_ratio) 
 * \brief Set average_debt_earnings_ratio memory variable for current X-machine.
 * \param average_debt_earnings_ratio New value for variable.
 */
void set_average_debt_earnings_ratio(double average_debt_earnings_ratio)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_debt_earnings_ratio = average_debt_earnings_ratio;
}

/** \fn double get_average_debt_earnings_ratio()
 * \brief Get average_debt_earnings_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_debt_earnings_ratio()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_debt_earnings_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_average_debt_equity_ratio(double average_debt_equity_ratio) 
 * \brief Set average_debt_equity_ratio memory variable for current X-machine.
 * \param average_debt_equity_ratio New value for variable.
 */
void set_average_debt_equity_ratio(double average_debt_equity_ratio)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).average_debt_equity_ratio = average_debt_equity_ratio;
}

/** \fn double get_average_debt_equity_ratio()
 * \brief Get average_debt_equity_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_average_debt_equity_ratio()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).average_debt_equity_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_labour_share_ratio(double labour_share_ratio) 
 * \brief Set labour_share_ratio memory variable for current X-machine.
 * \param labour_share_ratio New value for variable.
 */
void set_labour_share_ratio(double labour_share_ratio)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).labour_share_ratio = labour_share_ratio;
}

/** \fn double get_labour_share_ratio()
 * \brief Get labour_share_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_labour_share_ratio()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).labour_share_ratio;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_cpi(double cpi) 
 * \brief Set cpi memory variable for current X-machine.
 * \param cpi New value for variable.
 */
void set_cpi(double cpi)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).cpi = cpi;
}

/** \fn double get_cpi()
 * \brief Get cpi memory variable from current X-machine.
 * \return Value for variable.
 */
double get_cpi()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).cpi;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gdp(double gdp) 
 * \brief Set gdp memory variable for current X-machine.
 * \param gdp New value for variable.
 */
void set_gdp(double gdp)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).gdp = gdp;
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gdp = gdp;
}

/** \fn double get_gdp()
 * \brief Get gdp memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gdp()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).gdp;
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gdp;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_sold_quantity(double monthly_sold_quantity) 
 * \brief Set monthly_sold_quantity memory variable for current X-machine.
 * \param monthly_sold_quantity New value for variable.
 */
void set_monthly_sold_quantity(double monthly_sold_quantity)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).monthly_sold_quantity = monthly_sold_quantity;
}

/** \fn double get_monthly_sold_quantity()
 * \brief Get monthly_sold_quantity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_sold_quantity()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).monthly_sold_quantity;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_output(double monthly_output) 
 * \brief Set monthly_output memory variable for current X-machine.
 * \param monthly_output New value for variable.
 */
void set_monthly_output(double monthly_output)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).monthly_output = monthly_output;
}

/** \fn double get_monthly_output()
 * \brief Get monthly_output memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_output()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).monthly_output;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_revenue(double monthly_revenue) 
 * \brief Set monthly_revenue memory variable for current X-machine.
 * \param monthly_revenue New value for variable.
 */
void set_monthly_revenue(double monthly_revenue)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).monthly_revenue = monthly_revenue;
}

/** \fn double get_monthly_revenue()
 * \brief Get monthly_revenue memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_revenue()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).monthly_revenue;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_planned_output(double monthly_planned_output) 
 * \brief Set monthly_planned_output memory variable for current X-machine.
 * \param monthly_planned_output New value for variable.
 */
void set_monthly_planned_output(double monthly_planned_output)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).monthly_planned_output = monthly_planned_output;
}

/** \fn double get_monthly_planned_output()
 * \brief Get monthly_planned_output memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_planned_output()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).monthly_planned_output;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn history_item get_history_monthly()
 * \brief Get history_monthly memory variable from current X-machine.
 * \return Value for variable.
 */
history_item * get_history_monthly()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).history_monthly;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn history_item get_history_quarterly()
 * \brief Get history_quarterly memory variable from current X-machine.
 * \return Value for variable.
 */
history_item * get_history_quarterly()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).history_quarterly;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn history_item get_monthly_growth_rates()
 * \brief Get monthly_growth_rates memory variable from current X-machine.
 * \return Value for variable.
 */
history_item * get_monthly_growth_rates()
{
	if(current_xmachine->xmachine_Eurostat) return &(*current_xmachine->xmachine_Eurostat).monthly_growth_rates;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn history_item get_quarterly_growth_rates()
 * \brief Get quarterly_growth_rates memory variable from current X-machine.
 * \return Value for variable.
 */
history_item * get_quarterly_growth_rates()
{
	if(current_xmachine->xmachine_Eurostat) return &(*current_xmachine->xmachine_Eurostat).quarterly_growth_rates;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn history_item get_annual_growth_rates_monthly()
 * \brief Get annual_growth_rates_monthly memory variable from current X-machine.
 * \return Value for variable.
 */
history_item * get_annual_growth_rates_monthly()
{
	if(current_xmachine->xmachine_Eurostat) return &(*current_xmachine->xmachine_Eurostat).annual_growth_rates_monthly;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn history_item get_annual_growth_rates_quarterly()
 * \brief Get annual_growth_rates_quarterly memory variable from current X-machine.
 * \return Value for variable.
 */
history_item * get_annual_growth_rates_quarterly()
{
	if(current_xmachine->xmachine_Eurostat) return &(*current_xmachine->xmachine_Eurostat).annual_growth_rates_quarterly;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_no_firm_births(int no_firm_births) 
 * \brief Set no_firm_births memory variable for current X-machine.
 * \param no_firm_births New value for variable.
 */
void set_no_firm_births(int no_firm_births)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_firm_births = no_firm_births;
}

/** \fn int get_no_firm_births()
 * \brief Get no_firm_births memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_firm_births()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_firm_births;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_no_firm_deaths(int no_firm_deaths) 
 * \brief Set no_firm_deaths memory variable for current X-machine.
 * \param no_firm_deaths New value for variable.
 */
void set_no_firm_deaths(int no_firm_deaths)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).no_firm_deaths = no_firm_deaths;
}

/** \fn int get_no_firm_deaths()
 * \brief Get no_firm_deaths memory variable from current X-machine.
 * \return Value for variable.
 */
int get_no_firm_deaths()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).no_firm_deaths;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn int get_firm_age_distribution()
 * \brief Get firm_age_distribution memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_firm_age_distribution()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_age_distribution;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn int get_firm_age_distribution_multiperiod()
 * \brief Get firm_age_distribution_multiperiod memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_firm_age_distribution_multiperiod()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_age_distribution_multiperiod;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn int get_firm_age_distribution_1_period_lag()
 * \brief Get firm_age_distribution_1_period_lag memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_firm_age_distribution_1_period_lag()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_age_distribution_1_period_lag;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn int get_firm_age_distribution_2_period_lag()
 * \brief Get firm_age_distribution_2_period_lag memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_firm_age_distribution_2_period_lag()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_age_distribution_2_period_lag;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_firm_birth_rate(double firm_birth_rate) 
 * \brief Set firm_birth_rate memory variable for current X-machine.
 * \param firm_birth_rate New value for variable.
 */
void set_firm_birth_rate(double firm_birth_rate)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_birth_rate = firm_birth_rate;
}

/** \fn double get_firm_birth_rate()
 * \brief Get firm_birth_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_birth_rate()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_birth_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_death_rate(double firm_death_rate) 
 * \brief Set firm_death_rate memory variable for current X-machine.
 * \param firm_death_rate New value for variable.
 */
void set_firm_death_rate(double firm_death_rate)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).firm_death_rate = firm_death_rate;
}

/** \fn double get_firm_death_rate()
 * \brief Get firm_death_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_death_rate()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).firm_death_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn double get_survival_rate()
 * \brief Get survival_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_survival_rate()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).survival_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_survival_rate_multiperiod_1()
 * \brief Get survival_rate_multiperiod_1 memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_survival_rate_multiperiod_1()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).survival_rate_multiperiod_1;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_survival_rate_multiperiod_2()
 * \brief Get survival_rate_multiperiod_2 memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_survival_rate_multiperiod_2()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).survival_rate_multiperiod_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_survival_rate_multiperiod()
 * \brief Get survival_rate_multiperiod memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_survival_rate_multiperiod()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).survival_rate_multiperiod;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_max_firm_creation(int max_firm_creation) 
 * \brief Set max_firm_creation memory variable for current X-machine.
 * \param max_firm_creation New value for variable.
 */
void set_max_firm_creation(int max_firm_creation)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).max_firm_creation = max_firm_creation;
}

/** \fn int get_max_firm_creation()
 * \brief Get max_firm_creation memory variable from current X-machine.
 * \return Value for variable.
 */
int get_max_firm_creation()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).max_firm_creation;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_recession_started(int recession_started) 
 * \brief Set recession_started memory variable for current X-machine.
 * \param recession_started New value for variable.
 */
void set_recession_started(int recession_started)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).recession_started = recession_started;
}

/** \fn int get_recession_started()
 * \brief Get recession_started memory variable from current X-machine.
 * \return Value for variable.
 */
int get_recession_started()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).recession_started;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_recession_duration(int recession_duration) 
 * \brief Set recession_duration memory variable for current X-machine.
 * \param recession_duration New value for variable.
 */
void set_recession_duration(int recession_duration)
{
	if(current_xmachine->xmachine_Eurostat) (*current_xmachine->xmachine_Eurostat).recession_duration = recession_duration;
}

/** \fn int get_recession_duration()
 * \brief Get recession_duration memory variable from current X-machine.
 * \return Value for variable.
 */
int get_recession_duration()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).recession_duration;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn double get_region_export_volume()
 * \brief Get region_export_volume memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_region_export_volume()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).region_export_volume;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_region_import_volume()
 * \brief Get region_import_volume memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_region_import_volume()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).region_import_volume;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_region_export_value()
 * \brief Get region_export_value memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_region_export_value()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).region_export_value;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_region_import_value()
 * \brief Get region_import_value memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_region_import_value()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).region_import_value;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_region_import_previous_value()
 * \brief Get region_import_previous_value memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_region_import_previous_value()
{
	if(current_xmachine->xmachine_Eurostat) return (*current_xmachine->xmachine_Eurostat).region_import_previous_value;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn Asset_array get_assets()
 * \brief Get assets memory variable from current X-machine.
 * \return Value for variable.
 */
Asset_array * get_assets()
{
	if(current_xmachine->xmachine_Clearinghouse) return &(*current_xmachine->xmachine_Clearinghouse).assets;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn ClearingMechanism get_clearingmechanism()
 * \brief Get clearingmechanism memory variable from current X-machine.
 * \return Value for variable.
 */
ClearingMechanism * get_clearingmechanism()
{
	if(current_xmachine->xmachine_Clearinghouse) return &(*current_xmachine->xmachine_Clearinghouse).clearingmechanism;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
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

/** \fn int get_list_of_regions()
 * \brief Get list_of_regions memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_list_of_regions()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).list_of_regions;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn Bond get_bond()
 * \brief Get bond memory variable from current X-machine.
 * \return Value for variable.
 */
Bond * get_bond()
{
	if(current_xmachine->xmachine_Government) return &(*current_xmachine->xmachine_Government).bond;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn Order get_pending_order()
 * \brief Get pending_order memory variable from current X-machine.
 * \return Value for variable.
 */
Order * get_pending_order()
{
	if(current_xmachine->xmachine_Government) return &(*current_xmachine->xmachine_Government).pending_order;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn void set_deficit(double deficit) 
 * \brief Set deficit memory variable for current X-machine.
 * \param deficit New value for variable.
 */
void set_deficit(double deficit)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).deficit = deficit;
}

/** \fn double get_deficit()
 * \brief Get deficit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_deficit()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).deficit;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_money_financing_fraction(double money_financing_fraction) 
 * \brief Set money_financing_fraction memory variable for current X-machine.
 * \param money_financing_fraction New value for variable.
 */
void set_money_financing_fraction(double money_financing_fraction)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).money_financing_fraction = money_financing_fraction;
}

/** \fn double get_money_financing_fraction()
 * \brief Get money_financing_fraction memory variable from current X-machine.
 * \return Value for variable.
 */
double get_money_financing_fraction()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).money_financing_fraction;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gdp_fraction_consumption(double gdp_fraction_consumption) 
 * \brief Set gdp_fraction_consumption memory variable for current X-machine.
 * \param gdp_fraction_consumption New value for variable.
 */
void set_gdp_fraction_consumption(double gdp_fraction_consumption)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gdp_fraction_consumption = gdp_fraction_consumption;
}

/** \fn double get_gdp_fraction_consumption()
 * \brief Get gdp_fraction_consumption memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gdp_fraction_consumption()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gdp_fraction_consumption;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gdp_fraction_investment(double gdp_fraction_investment) 
 * \brief Set gdp_fraction_investment memory variable for current X-machine.
 * \param gdp_fraction_investment New value for variable.
 */
void set_gdp_fraction_investment(double gdp_fraction_investment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gdp_fraction_investment = gdp_fraction_investment;
}

/** \fn double get_gdp_fraction_investment()
 * \brief Get gdp_fraction_investment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gdp_fraction_investment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gdp_fraction_investment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_tax_revenues(double monthly_tax_revenues) 
 * \brief Set monthly_tax_revenues memory variable for current X-machine.
 * \param monthly_tax_revenues New value for variable.
 */
void set_monthly_tax_revenues(double monthly_tax_revenues)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_tax_revenues = monthly_tax_revenues;
}

/** \fn double get_monthly_tax_revenues()
 * \brief Get monthly_tax_revenues memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_tax_revenues()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_tax_revenues;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_tax_revenues(double yearly_tax_revenues) 
 * \brief Set yearly_tax_revenues memory variable for current X-machine.
 * \param yearly_tax_revenues New value for variable.
 */
void set_yearly_tax_revenues(double yearly_tax_revenues)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_tax_revenues = yearly_tax_revenues;
}

/** \fn double get_yearly_tax_revenues()
 * \brief Get yearly_tax_revenues memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_tax_revenues()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_tax_revenues;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_unemployment_benefit_payment(double monthly_unemployment_benefit_payment) 
 * \brief Set monthly_unemployment_benefit_payment memory variable for current X-machine.
 * \param monthly_unemployment_benefit_payment New value for variable.
 */
void set_monthly_unemployment_benefit_payment(double monthly_unemployment_benefit_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_unemployment_benefit_payment = monthly_unemployment_benefit_payment;
}

/** \fn double get_monthly_unemployment_benefit_payment()
 * \brief Get monthly_unemployment_benefit_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_unemployment_benefit_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_unemployment_benefit_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_unemployment_benefit_payment(double yearly_unemployment_benefit_payment) 
 * \brief Set yearly_unemployment_benefit_payment memory variable for current X-machine.
 * \param yearly_unemployment_benefit_payment New value for variable.
 */
void set_yearly_unemployment_benefit_payment(double yearly_unemployment_benefit_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_unemployment_benefit_payment = yearly_unemployment_benefit_payment;
}

/** \fn double get_yearly_unemployment_benefit_payment()
 * \brief Get yearly_unemployment_benefit_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_unemployment_benefit_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_unemployment_benefit_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_hh_transfer_payment(double hh_transfer_payment) 
 * \brief Set hh_transfer_payment memory variable for current X-machine.
 * \param hh_transfer_payment New value for variable.
 */
void set_hh_transfer_payment(double hh_transfer_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).hh_transfer_payment = hh_transfer_payment;
}

/** \fn double get_hh_transfer_payment()
 * \brief Get hh_transfer_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_hh_transfer_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).hh_transfer_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_transfer_payment(double firm_transfer_payment) 
 * \brief Set firm_transfer_payment memory variable for current X-machine.
 * \param firm_transfer_payment New value for variable.
 */
void set_firm_transfer_payment(double firm_transfer_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).firm_transfer_payment = firm_transfer_payment;
}

/** \fn double get_firm_transfer_payment()
 * \brief Get firm_transfer_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_transfer_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).firm_transfer_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_transfer_payment(double monthly_transfer_payment) 
 * \brief Set monthly_transfer_payment memory variable for current X-machine.
 * \param monthly_transfer_payment New value for variable.
 */
void set_monthly_transfer_payment(double monthly_transfer_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_transfer_payment = monthly_transfer_payment;
}

/** \fn double get_monthly_transfer_payment()
 * \brief Get monthly_transfer_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_transfer_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_transfer_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_transfer_payment(double yearly_transfer_payment) 
 * \brief Set yearly_transfer_payment memory variable for current X-machine.
 * \param yearly_transfer_payment New value for variable.
 */
void set_yearly_transfer_payment(double yearly_transfer_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_transfer_payment = yearly_transfer_payment;
}

/** \fn double get_yearly_transfer_payment()
 * \brief Get yearly_transfer_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_transfer_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_transfer_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_hh_subsidy_payment(double hh_subsidy_payment) 
 * \brief Set hh_subsidy_payment memory variable for current X-machine.
 * \param hh_subsidy_payment New value for variable.
 */
void set_hh_subsidy_payment(double hh_subsidy_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).hh_subsidy_payment = hh_subsidy_payment;
}

/** \fn double get_hh_subsidy_payment()
 * \brief Get hh_subsidy_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_hh_subsidy_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).hh_subsidy_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_firm_subsidy_payment(double firm_subsidy_payment) 
 * \brief Set firm_subsidy_payment memory variable for current X-machine.
 * \param firm_subsidy_payment New value for variable.
 */
void set_firm_subsidy_payment(double firm_subsidy_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).firm_subsidy_payment = firm_subsidy_payment;
}

/** \fn double get_firm_subsidy_payment()
 * \brief Get firm_subsidy_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_firm_subsidy_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).firm_subsidy_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_subsidy_payment(double monthly_subsidy_payment) 
 * \brief Set monthly_subsidy_payment memory variable for current X-machine.
 * \param monthly_subsidy_payment New value for variable.
 */
void set_monthly_subsidy_payment(double monthly_subsidy_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_subsidy_payment = monthly_subsidy_payment;
}

/** \fn double get_monthly_subsidy_payment()
 * \brief Get monthly_subsidy_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_subsidy_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_subsidy_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_subsidy_payment(double yearly_subsidy_payment) 
 * \brief Set yearly_subsidy_payment memory variable for current X-machine.
 * \param yearly_subsidy_payment New value for variable.
 */
void set_yearly_subsidy_payment(double yearly_subsidy_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_subsidy_payment = yearly_subsidy_payment;
}

/** \fn double get_yearly_subsidy_payment()
 * \brief Get yearly_subsidy_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_subsidy_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_subsidy_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_bond_coupon_payment(double monthly_bond_coupon_payment) 
 * \brief Set monthly_bond_coupon_payment memory variable for current X-machine.
 * \param monthly_bond_coupon_payment New value for variable.
 */
void set_monthly_bond_coupon_payment(double monthly_bond_coupon_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_bond_coupon_payment = monthly_bond_coupon_payment;
}

/** \fn double get_monthly_bond_coupon_payment()
 * \brief Get monthly_bond_coupon_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_bond_coupon_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_bond_coupon_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_bond_coupon_payment(double yearly_bond_coupon_payment) 
 * \brief Set yearly_bond_coupon_payment memory variable for current X-machine.
 * \param yearly_bond_coupon_payment New value for variable.
 */
void set_yearly_bond_coupon_payment(double yearly_bond_coupon_payment)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_bond_coupon_payment = yearly_bond_coupon_payment;
}

/** \fn double get_yearly_bond_coupon_payment()
 * \brief Get yearly_bond_coupon_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_bond_coupon_payment()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_bond_coupon_payment;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gov_interest_rate(double gov_interest_rate) 
 * \brief Set gov_interest_rate memory variable for current X-machine.
 * \param gov_interest_rate New value for variable.
 */
void set_gov_interest_rate(double gov_interest_rate)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gov_interest_rate = gov_interest_rate;
}

/** \fn double get_gov_interest_rate()
 * \brief Get gov_interest_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gov_interest_rate()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gov_interest_rate;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_investment_expenditure(double yearly_investment_expenditure) 
 * \brief Set yearly_investment_expenditure memory variable for current X-machine.
 * \param yearly_investment_expenditure New value for variable.
 */
void set_yearly_investment_expenditure(double yearly_investment_expenditure)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_investment_expenditure = yearly_investment_expenditure;
}

/** \fn double get_yearly_investment_expenditure()
 * \brief Get yearly_investment_expenditure memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_investment_expenditure()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_investment_expenditure;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_consumption_expenditure(double yearly_consumption_expenditure) 
 * \brief Set yearly_consumption_expenditure memory variable for current X-machine.
 * \param yearly_consumption_expenditure New value for variable.
 */
void set_yearly_consumption_expenditure(double yearly_consumption_expenditure)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_consumption_expenditure = yearly_consumption_expenditure;
}

/** \fn double get_yearly_consumption_expenditure()
 * \brief Get yearly_consumption_expenditure memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_consumption_expenditure()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_consumption_expenditure;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_income(double yearly_income) 
 * \brief Set yearly_income memory variable for current X-machine.
 * \param yearly_income New value for variable.
 */
void set_yearly_income(double yearly_income)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_income = yearly_income;
}

/** \fn double get_yearly_income()
 * \brief Get yearly_income memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_income()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_expenditure(double yearly_expenditure) 
 * \brief Set yearly_expenditure memory variable for current X-machine.
 * \param yearly_expenditure New value for variable.
 */
void set_yearly_expenditure(double yearly_expenditure)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_expenditure = yearly_expenditure;
}

/** \fn double get_yearly_expenditure()
 * \brief Get yearly_expenditure memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_expenditure()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_expenditure;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_budget_balance(double yearly_budget_balance) 
 * \brief Set yearly_budget_balance memory variable for current X-machine.
 * \param yearly_budget_balance New value for variable.
 */
void set_yearly_budget_balance(double yearly_budget_balance)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_budget_balance = yearly_budget_balance;
}

/** \fn double get_yearly_budget_balance()
 * \brief Get yearly_budget_balance memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_budget_balance()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_budget_balance;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_money_financing(double total_money_financing) 
 * \brief Set total_money_financing memory variable for current X-machine.
 * \param total_money_financing New value for variable.
 */
void set_total_money_financing(double total_money_financing)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_money_financing = total_money_financing;
}

/** \fn double get_total_money_financing()
 * \brief Get total_money_financing memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_money_financing()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_money_financing;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_total_bond_financing(double total_bond_financing) 
 * \brief Set total_bond_financing memory variable for current X-machine.
 * \param total_bond_financing New value for variable.
 */
void set_total_bond_financing(double total_bond_financing)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).total_bond_financing = total_bond_financing;
}

/** \fn double get_total_bond_financing()
 * \brief Get total_bond_financing memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_bond_financing()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).total_bond_financing;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_country_wide_mean_wage(double country_wide_mean_wage) 
 * \brief Set country_wide_mean_wage memory variable for current X-machine.
 * \param country_wide_mean_wage New value for variable.
 */
void set_country_wide_mean_wage(double country_wide_mean_wage)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).country_wide_mean_wage = country_wide_mean_wage;
}

/** \fn double get_country_wide_mean_wage()
 * \brief Get country_wide_mean_wage memory variable from current X-machine.
 * \return Value for variable.
 */
double get_country_wide_mean_wage()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).country_wide_mean_wage;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_num_unemployed(int num_unemployed) 
 * \brief Set num_unemployed memory variable for current X-machine.
 * \param num_unemployed New value for variable.
 */
void set_num_unemployed(int num_unemployed)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).num_unemployed = num_unemployed;
}

/** \fn int get_num_unemployed()
 * \brief Get num_unemployed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_num_unemployed()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).num_unemployed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_gdp_growth(double gdp_growth) 
 * \brief Set gdp_growth memory variable for current X-machine.
 * \param gdp_growth New value for variable.
 */
void set_gdp_growth(double gdp_growth)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gdp_growth = gdp_growth;
}

/** \fn double get_gdp_growth()
 * \brief Get gdp_growth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gdp_growth()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gdp_growth;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_gdp_forecast(double gdp_forecast) 
 * \brief Set gdp_forecast memory variable for current X-machine.
 * \param gdp_forecast New value for variable.
 */
void set_gdp_forecast(double gdp_forecast)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).gdp_forecast = gdp_forecast;
}

/** \fn double get_gdp_forecast()
 * \brief Get gdp_forecast memory variable from current X-machine.
 * \return Value for variable.
 */
double get_gdp_forecast()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).gdp_forecast;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_income_forecast(double yearly_income_forecast) 
 * \brief Set yearly_income_forecast memory variable for current X-machine.
 * \param yearly_income_forecast New value for variable.
 */
void set_yearly_income_forecast(double yearly_income_forecast)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_income_forecast = yearly_income_forecast;
}

/** \fn double get_yearly_income_forecast()
 * \brief Get yearly_income_forecast memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_income_forecast()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_income_forecast;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_expenditure_budget(double yearly_expenditure_budget) 
 * \brief Set yearly_expenditure_budget memory variable for current X-machine.
 * \param yearly_expenditure_budget New value for variable.
 */
void set_yearly_expenditure_budget(double yearly_expenditure_budget)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_expenditure_budget = yearly_expenditure_budget;
}

/** \fn double get_yearly_expenditure_budget()
 * \brief Get yearly_expenditure_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_expenditure_budget()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_expenditure_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_budget_balance_forecast(double budget_balance_forecast) 
 * \brief Set budget_balance_forecast memory variable for current X-machine.
 * \param budget_balance_forecast New value for variable.
 */
void set_budget_balance_forecast(double budget_balance_forecast)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).budget_balance_forecast = budget_balance_forecast;
}

/** \fn double get_budget_balance_forecast()
 * \brief Get budget_balance_forecast memory variable from current X-machine.
 * \return Value for variable.
 */
double get_budget_balance_forecast()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).budget_balance_forecast;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_consumption_expenditure(double monthly_consumption_expenditure) 
 * \brief Set monthly_consumption_expenditure memory variable for current X-machine.
 * \param monthly_consumption_expenditure New value for variable.
 */
void set_monthly_consumption_expenditure(double monthly_consumption_expenditure)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_consumption_expenditure = monthly_consumption_expenditure;
}

/** \fn double get_monthly_consumption_expenditure()
 * \brief Get monthly_consumption_expenditure memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_consumption_expenditure()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_consumption_expenditure;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_investment_expenditure(double monthly_investment_expenditure) 
 * \brief Set monthly_investment_expenditure memory variable for current X-machine.
 * \param monthly_investment_expenditure New value for variable.
 */
void set_monthly_investment_expenditure(double monthly_investment_expenditure)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_investment_expenditure = monthly_investment_expenditure;
}

/** \fn double get_monthly_investment_expenditure()
 * \brief Get monthly_investment_expenditure memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_investment_expenditure()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_investment_expenditure;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_budget_balance(double monthly_budget_balance) 
 * \brief Set monthly_budget_balance memory variable for current X-machine.
 * \param monthly_budget_balance New value for variable.
 */
void set_monthly_budget_balance(double monthly_budget_balance)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_budget_balance = monthly_budget_balance;
}

/** \fn double get_monthly_budget_balance()
 * \brief Get monthly_budget_balance memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_budget_balance()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_budget_balance;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_consumption_budget(double monthly_consumption_budget) 
 * \brief Set monthly_consumption_budget memory variable for current X-machine.
 * \param monthly_consumption_budget New value for variable.
 */
void set_monthly_consumption_budget(double monthly_consumption_budget)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_consumption_budget = monthly_consumption_budget;
}

/** \fn double get_monthly_consumption_budget()
 * \brief Get monthly_consumption_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_consumption_budget()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_consumption_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_investment_budget(double monthly_investment_budget) 
 * \brief Set monthly_investment_budget memory variable for current X-machine.
 * \param monthly_investment_budget New value for variable.
 */
void set_monthly_investment_budget(double monthly_investment_budget)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_investment_budget = monthly_investment_budget;
}

/** \fn double get_monthly_investment_budget()
 * \brief Get monthly_investment_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_investment_budget()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_investment_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_income(double monthly_income) 
 * \brief Set monthly_income memory variable for current X-machine.
 * \param monthly_income New value for variable.
 */
void set_monthly_income(double monthly_income)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_income = monthly_income;
}

/** \fn double get_monthly_income()
 * \brief Get monthly_income memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_income()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_income;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_monthly_expenditure(double monthly_expenditure) 
 * \brief Set monthly_expenditure memory variable for current X-machine.
 * \param monthly_expenditure New value for variable.
 */
void set_monthly_expenditure(double monthly_expenditure)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).monthly_expenditure = monthly_expenditure;
}

/** \fn double get_monthly_expenditure()
 * \brief Get monthly_expenditure memory variable from current X-machine.
 * \return Value for variable.
 */
double get_monthly_expenditure()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).monthly_expenditure;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_consumption_budget(double yearly_consumption_budget) 
 * \brief Set yearly_consumption_budget memory variable for current X-machine.
 * \param yearly_consumption_budget New value for variable.
 */
void set_yearly_consumption_budget(double yearly_consumption_budget)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_consumption_budget = yearly_consumption_budget;
}

/** \fn double get_yearly_consumption_budget()
 * \brief Get yearly_consumption_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_consumption_budget()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_consumption_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_yearly_investment_budget(double yearly_investment_budget) 
 * \brief Set yearly_investment_budget memory variable for current X-machine.
 * \param yearly_investment_budget New value for variable.
 */
void set_yearly_investment_budget(double yearly_investment_budget)
{
	if(current_xmachine->xmachine_Government) (*current_xmachine->xmachine_Government).yearly_investment_budget = yearly_investment_budget;
}

/** \fn double get_yearly_investment_budget()
 * \brief Get yearly_investment_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_yearly_investment_budget()
{
	if(current_xmachine->xmachine_Government) return (*current_xmachine->xmachine_Government).yearly_investment_budget;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn account_item_array get_accounts()
 * \brief Get accounts memory variable from current X-machine.
 * \return Value for variable.
 */
account_item_array * get_accounts()
{
	if(current_xmachine->xmachine_Central_Bank) return &(*current_xmachine->xmachine_Central_Bank).accounts;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->;*/
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;*/
    /*if (current_xmachine->xmachine_Mall) value = current_xmachine->xmachine_Mall->;*/
    /*if (current_xmachine->xmachine_IGFirm) value = current_xmachine->xmachine_IGFirm->;*/
    /*if (current_xmachine->xmachine_Eurostat) value = current_xmachine->xmachine_Eurostat->;*/
    /*if (current_xmachine->xmachine_Clearinghouse) value = current_xmachine->xmachine_Clearinghouse->;*/
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->;*/
    /*if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->;*/
    /*if (current_xmachine->xmachine_Central_Bank) value = current_xmachine->xmachine_Central_Bank->;*/

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
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->id;*/
    /*if (current_xmachine->xmachine_Mall) value = current_xmachine->xmachine_Mall->id;*/
    /*if (current_xmachine->xmachine_IGFirm) value = current_xmachine->xmachine_IGFirm->id;*/
    /*if (current_xmachine->xmachine_Eurostat) value = current_xmachine->xmachine_Eurostat->id;*/
    /*if (current_xmachine->xmachine_Clearinghouse) value = current_xmachine->xmachine_Clearinghouse->id;*/
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->id;*/
    /*if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->id;*/
    /*if (current_xmachine->xmachine_Central_Bank) value = current_xmachine->xmachine_Central_Bank->id;*/

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
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->0.0;*/
    /*if (current_xmachine->xmachine_Mall) value = current_xmachine->xmachine_Mall->0.0;*/
    /*if (current_xmachine->xmachine_IGFirm) value = current_xmachine->xmachine_IGFirm->0.0;*/
    /*if (current_xmachine->xmachine_Eurostat) value = current_xmachine->xmachine_Eurostat->0.0;*/
    /*if (current_xmachine->xmachine_Clearinghouse) value = current_xmachine->xmachine_Clearinghouse->0.0;*/
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->0.0;*/
    /*if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->0.0;*/
    /*if (current_xmachine->xmachine_Central_Bank) value = current_xmachine->xmachine_Central_Bank->0.0;*/

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
    /*if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->0.0;*/ 
    /*if (current_xmachine->xmachine_Mall) value = current_xmachine->xmachine_Mall->0.0;*/ 
    /*if (current_xmachine->xmachine_IGFirm) value = current_xmachine->xmachine_IGFirm->0.0;*/ 
    /*if (current_xmachine->xmachine_Eurostat) value = current_xmachine->xmachine_Eurostat->0.0;*/ 
    /*if (current_xmachine->xmachine_Clearinghouse) value = current_xmachine->xmachine_Clearinghouse->0.0;*/ 
    /*if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->0.0;*/ 
    /*if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->0.0;*/ 
    /*if (current_xmachine->xmachine_Central_Bank) value = current_xmachine->xmachine_Central_Bank->0.0;*/ 

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
	current->central_bank_account_update_messages = NULL;
	current->wage_payment_messages = NULL;
	current->quality_price_info_1_messages = NULL;
	current->quality_price_info_2_messages = NULL;
	current->update_mall_stock_messages = NULL;
	current->consumption_request_1_messages = NULL;
	current->consumption_request_2_messages = NULL;
	current->accepted_consumption_1_messages = NULL;
	current->accepted_consumption_2_messages = NULL;
	current->sales_messages = NULL;
	current->specific_skill_update_messages = NULL;
	current->daily_revenue_to_bank_messages = NULL;
	current->loan_request_messages = NULL;
	current->loan_conditions_messages = NULL;
	current->loan_acceptance_messages = NULL;
	current->installment_messages = NULL;
	current->bankruptcy_messages = NULL;
	current->BCE_return_messages = NULL;
	current->current_mall_stock_info_messages = NULL;
	current->dividend_per_share_messages = NULL;
	current->bankruptcy_illiquidity_messages = NULL;
	current->bankruptcy_insolvency_messages = NULL;
	current->order_messages = NULL;
	current->order_status_messages = NULL;
	current->infoAssetCH_messages = NULL;
	current->info_firm_messages = NULL;
	current->accountInterest_messages = NULL;
	current->bankAccountUpdate_messages = NULL;
	current->info_bond_messages = NULL;
	current->productivity_messages = NULL;
	current->capital_good_request_messages = NULL;
	current->capital_good_profit_distribution_messages = NULL;
	current->capital_good_delivery_messages = NULL;
	current->dividend_messages = NULL;
	current->pay_capital_goods_messages = NULL;
	current->vacancies_messages = NULL;
	current->vacancies2_messages = NULL;
	current->firing_messages = NULL;
	current->job_application_messages = NULL;
	current->job_application2_messages = NULL;
	current->job_offer_messages = NULL;
	current->job_offer2_messages = NULL;
	current->job_acceptance_messages = NULL;
	current->job_acceptance2_messages = NULL;
	current->application_rejection_messages = NULL;
	current->application_rejection2_messages = NULL;
	current->quitting_messages = NULL;
	current->quitting2_messages = NULL;
	current->unemployment_notification_messages = NULL;
	current->policy_announcement_messages = NULL;
	current->tax_payment_messages = NULL;
	current->hh_transfer_notification_messages = NULL;
	current->hh_subsidy_notification_messages = NULL;
	current->firm_transfer_notification_messages = NULL;
	current->firm_subsidy_notification_messages = NULL;
	current->firm_send_data_messages = NULL;
	current->household_send_data_messages = NULL;
	current->mall_data_messages = NULL;
	current->eurostat_send_specific_skills_messages = NULL;
	current->mean_wage_for_government_messages = NULL;
	current->data_for_government_messages = NULL;


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
	free_Household_states();
	free_Mall_states();
	free_IGFirm_states();
	free_Eurostat_states();
	free_Clearinghouse_states();
	free_Bank_states();
	free_Government_states();
	free_Central_Bank_states();
	
	
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

	rc = MB_Delete(&b_central_bank_account_update);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'central_bank_account_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'central_bank_account_update' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'central_bank_account_update' board is locked\n");
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

	rc = MB_Delete(&b_wage_payment);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'wage_payment' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'wage_payment' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'wage_payment' board is locked\n");
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

	rc = MB_Delete(&b_quality_price_info_1);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'quality_price_info_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_1' board is locked\n");
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

	rc = MB_Delete(&b_quality_price_info_2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'quality_price_info_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quality_price_info_2' board is locked\n");
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

	rc = MB_Delete(&b_update_mall_stock);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'update_mall_stock' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'update_mall_stock' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'update_mall_stock' board is locked\n");
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

	rc = MB_Delete(&b_consumption_request_1);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'consumption_request_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_1' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_1' board is locked\n");
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

	rc = MB_Delete(&b_consumption_request_2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'consumption_request_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'consumption_request_2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'consumption_request_2' board is locked\n");
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

	rc = MB_Delete(&b_accepted_consumption_1);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'accepted_consumption_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_1' board is locked\n");
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

	rc = MB_Delete(&b_accepted_consumption_2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'accepted_consumption_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accepted_consumption_2' board is locked\n");
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

	rc = MB_Delete(&b_sales);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'sales' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'sales' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'sales' board is locked\n");
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

	rc = MB_Delete(&b_specific_skill_update);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'specific_skill_update' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'specific_skill_update' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'specific_skill_update' board is locked\n");
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

	rc = MB_Delete(&b_daily_revenue_to_bank);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'daily_revenue_to_bank' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'daily_revenue_to_bank' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'daily_revenue_to_bank' board is locked\n");
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

	rc = MB_Delete(&b_bankruptcy_illiquidity);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'bankruptcy_illiquidity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_illiquidity' board is locked\n");
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

	rc = MB_Delete(&b_bankruptcy_insolvency);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'bankruptcy_insolvency' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankruptcy_insolvency' board is locked\n");
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

	rc = MB_Delete(&b_infoAssetCH);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'infoAssetCH' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'infoAssetCH' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'infoAssetCH' board is locked\n");
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

	rc = MB_Delete(&b_info_firm);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'info_firm' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'info_firm' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'info_firm' board is locked\n");
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

	rc = MB_Delete(&b_accountInterest);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'accountInterest' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'accountInterest' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'accountInterest' board is locked\n");
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

	rc = MB_Delete(&b_bankAccountUpdate);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'bankAccountUpdate' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'bankAccountUpdate' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'bankAccountUpdate' board is locked\n");
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

	rc = MB_Delete(&b_info_bond);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'info_bond' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'info_bond' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'info_bond' board is locked\n");
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

	rc = MB_Delete(&b_productivity);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'productivity' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'productivity' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'productivity' board is locked\n");
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

	rc = MB_Delete(&b_capital_good_request);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'capital_good_request' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_request' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_request' board is locked\n");
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

	rc = MB_Delete(&b_capital_good_profit_distribution);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'capital_good_profit_distribution' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_profit_distribution' board is locked\n");
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

	rc = MB_Delete(&b_capital_good_delivery);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'capital_good_delivery' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'capital_good_delivery' board is locked\n");
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

	rc = MB_Delete(&b_dividend);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'dividend' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'dividend' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'dividend' board is locked\n");
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

	rc = MB_Delete(&b_pay_capital_goods);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'pay_capital_goods' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pay_capital_goods' board is locked\n");
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

	rc = MB_Delete(&b_vacancies);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'vacancies' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies' board is locked\n");
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

	rc = MB_Delete(&b_vacancies2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'vacancies2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'vacancies2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'vacancies2' board is locked\n");
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

	rc = MB_Delete(&b_firing);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'firing' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firing' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firing' board is locked\n");
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

	rc = MB_Delete(&b_job_application);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_application' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application' board is locked\n");
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

	rc = MB_Delete(&b_job_application2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_application2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_application2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_application2' board is locked\n");
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

	rc = MB_Delete(&b_job_offer);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_offer' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer' board is locked\n");
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

	rc = MB_Delete(&b_job_offer2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_offer2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_offer2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_offer2' board is locked\n");
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

	rc = MB_Delete(&b_job_acceptance);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_acceptance' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance' board is locked\n");
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

	rc = MB_Delete(&b_job_acceptance2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'job_acceptance2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'job_acceptance2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'job_acceptance2' board is locked\n");
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

	rc = MB_Delete(&b_application_rejection);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'application_rejection' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'application_rejection' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'application_rejection' board is locked\n");
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

	rc = MB_Delete(&b_application_rejection2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'application_rejection2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'application_rejection2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'application_rejection2' board is locked\n");
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

	rc = MB_Delete(&b_quitting);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'quitting' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting' board is locked\n");
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

	rc = MB_Delete(&b_quitting2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'quitting2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'quitting2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'quitting2' board is locked\n");
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

	rc = MB_Delete(&b_unemployment_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'unemployment_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'unemployment_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'unemployment_notification' board is locked\n");
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

	rc = MB_Delete(&b_policy_announcement);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'policy_announcement' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'policy_announcement' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'policy_announcement' board is locked\n");
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

	rc = MB_Delete(&b_hh_transfer_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'hh_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_transfer_notification' board is locked\n");
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

	rc = MB_Delete(&b_hh_subsidy_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'hh_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'hh_subsidy_notification' board is locked\n");
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

	rc = MB_Delete(&b_firm_transfer_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'firm_transfer_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_transfer_notification' board is locked\n");
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

	rc = MB_Delete(&b_firm_subsidy_notification);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'firm_subsidy_notification' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_subsidy_notification' board is locked\n");
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

	rc = MB_Delete(&b_firm_send_data);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'firm_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'firm_send_data' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'firm_send_data' board is locked\n");
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

	rc = MB_Delete(&b_household_send_data);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'household_send_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'household_send_data' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'household_send_data' board is locked\n");
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

	rc = MB_Delete(&b_mall_data);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'mall_data' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mall_data' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mall_data' board is locked\n");
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

	rc = MB_Delete(&b_eurostat_send_specific_skills);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'eurostat_send_specific_skills' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'eurostat_send_specific_skills' board is locked\n");
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

	rc = MB_Delete(&b_mean_wage_for_government);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'mean_wage_for_government' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'mean_wage_for_government' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'mean_wage_for_government' board is locked\n");
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

	rc = MB_Delete(&b_data_for_government);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'data_for_government' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'data_for_government' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'data_for_government' board is locked\n");
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
		else if(current_xmachine->xmachine_Household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Household->0.0;
			y_xmachine = current_xmachine->xmachine_Household->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Mall != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Mall->0.0;
			y_xmachine = current_xmachine->xmachine_Mall->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_IGFirm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_IGFirm->0.0;
			y_xmachine = current_xmachine->xmachine_IGFirm->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Eurostat != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Eurostat->0.0;
			y_xmachine = current_xmachine->xmachine_Eurostat->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Clearinghouse != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Clearinghouse->0.0;
			y_xmachine = current_xmachine->xmachine_Clearinghouse->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Bank->0.0;
			y_xmachine = current_xmachine->xmachine_Bank->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Government != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Government->0.0;
			y_xmachine = current_xmachine->xmachine_Government->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Central_Bank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Central_Bank->0.0;
			y_xmachine = current_xmachine->xmachine_Central_Bank->0.0;
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

/* Functions for the consumption_goods_offer datatype */
/** \fn consumption_goods_offer_array * init_consumption_goods_offer_array()
 * \brief Allocate memory for a dynamic consumption_goods_offer array.
 * \return consumption_goods_offer_array Pointer to the new dynamic consumption_goods_offer array.
 */
void init_consumption_goods_offer_array(consumption_goods_offer_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (consumption_goods_offer *)malloc(ARRAY_BLOCK_SIZE * sizeof(consumption_goods_offer));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_consumption_goods_offer_array(consumption_goods_offer_array* array)
* \brief Reset the consumption_goods_offer array to hold nothing.
* \param array Pointer to the dynamic consumption_goods_offer array.
*/
void reset_consumption_goods_offer_array(consumption_goods_offer_array * array)
{
	(*array).size = 0;
}

/** \fn void free_consumption_goods_offer_array(consumption_goods_offer_array * array)
* \brief Free the memory of a dynamic consumption_goods_offer array.
* \param array Pointer to the dynamic consumption_goods_offer array.
*/
void free_consumption_goods_offer_array(consumption_goods_offer_array * array)
{
	free((*array).array);
}

void copy_consumption_goods_offer_array(consumption_goods_offer_array * from, consumption_goods_offer_array * to)
{
	int i;
	
	//to = init_consumption_goods_offer_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_consumption_goods_offer(to, (*from).array[i].id, (*from).array[i].quality, (*from).array[i].price);
	}
}

/** \fn void add_consumption_goods_offer(consumption_goods_offer_array * array, int id, double quality, double price)
* \brief Add an consumption_goods_offer to the dynamic consumption_goods_offer array.
* \param array Pointer to the dynamic consumption_goods_offer array.
* \param new_int The consumption_goods_offer to add
*/
void add_consumption_goods_offer(consumption_goods_offer_array * array, int id, double quality, double price)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (consumption_goods_offer *)realloc((*array).array, ((*array).total_size * sizeof(consumption_goods_offer)));
	}
	init_consumption_goods_offer(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].quality = quality;
	(*array).array[(*array).size].price = price;

	(*array).size++;
}

/** \fn void remove_consumption_goods_offer(consumption_goods_offer_array * array, int index)
 * \brief Remove an consumption_goods_offer from a dynamic consumption_goods_offer array.
 * \param array Pointer to the dynamic consumption_goods_offer array.
 * \param index The index of the consumption_goods_offer to remove.
 */
void remove_consumption_goods_offer(consumption_goods_offer_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_consumption_goods_offer(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_consumption_goods_offer(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the consumption_request datatype */
/** \fn consumption_request_array * init_consumption_request_array()
 * \brief Allocate memory for a dynamic consumption_request array.
 * \return consumption_request_array Pointer to the new dynamic consumption_request array.
 */
void init_consumption_request_array(consumption_request_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (consumption_request *)malloc(ARRAY_BLOCK_SIZE * sizeof(consumption_request));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_consumption_request_array(consumption_request_array* array)
* \brief Reset the consumption_request array to hold nothing.
* \param array Pointer to the dynamic consumption_request array.
*/
void reset_consumption_request_array(consumption_request_array * array)
{
	(*array).size = 0;
}

/** \fn void free_consumption_request_array(consumption_request_array * array)
* \brief Free the memory of a dynamic consumption_request array.
* \param array Pointer to the dynamic consumption_request array.
*/
void free_consumption_request_array(consumption_request_array * array)
{
	free((*array).array);
}

void copy_consumption_request_array(consumption_request_array * from, consumption_request_array * to)
{
	int i;
	
	//to = init_consumption_request_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_consumption_request(to, (*from).array[i].worker_id, (*from).array[i].consumer_region_id, (*from).array[i].firm_id, (*from).array[i].quantity);
	}
}

/** \fn void add_consumption_request(consumption_request_array * array, int worker_id, int consumer_region_id, int firm_id, double quantity)
* \brief Add an consumption_request to the dynamic consumption_request array.
* \param array Pointer to the dynamic consumption_request array.
* \param new_int The consumption_request to add
*/
void add_consumption_request(consumption_request_array * array, int worker_id, int consumer_region_id, int firm_id, double quantity)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (consumption_request *)realloc((*array).array, ((*array).total_size * sizeof(consumption_request)));
	}
	init_consumption_request(&(*array).array[(*array).size]);
	(*array).array[(*array).size].worker_id = worker_id;
	(*array).array[(*array).size].consumer_region_id = consumer_region_id;
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].quantity = quantity;

	(*array).size++;
}

/** \fn void remove_consumption_request(consumption_request_array * array, int index)
 * \brief Remove an consumption_request from a dynamic consumption_request array.
 * \param array Pointer to the dynamic consumption_request array.
 * \param index The index of the consumption_request to remove.
 */
void remove_consumption_request(consumption_request_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_consumption_request(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_consumption_request(&(*array).array[i+1], &(*array).array[i]);
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
/* Functions for the mall_quality_price_info datatype */
/** \fn mall_quality_price_info_array * init_mall_quality_price_info_array()
 * \brief Allocate memory for a dynamic mall_quality_price_info array.
 * \return mall_quality_price_info_array Pointer to the new dynamic mall_quality_price_info array.
 */
void init_mall_quality_price_info_array(mall_quality_price_info_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (mall_quality_price_info *)malloc(ARRAY_BLOCK_SIZE * sizeof(mall_quality_price_info));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_mall_quality_price_info_array(mall_quality_price_info_array* array)
* \brief Reset the mall_quality_price_info array to hold nothing.
* \param array Pointer to the dynamic mall_quality_price_info array.
*/
void reset_mall_quality_price_info_array(mall_quality_price_info_array * array)
{
	(*array).size = 0;
}

/** \fn void free_mall_quality_price_info_array(mall_quality_price_info_array * array)
* \brief Free the memory of a dynamic mall_quality_price_info array.
* \param array Pointer to the dynamic mall_quality_price_info array.
*/
void free_mall_quality_price_info_array(mall_quality_price_info_array * array)
{
	free((*array).array);
}

void copy_mall_quality_price_info_array(mall_quality_price_info_array * from, mall_quality_price_info_array * to)
{
	int i;
	
	//to = init_mall_quality_price_info_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_mall_quality_price_info(to, (*from).array[i].mall_id, (*from).array[i].firm_id, (*from).array[i].mall_region_id, (*from).array[i].quality, (*from).array[i].price, (*from).array[i].available);
	}
}

/** \fn void add_mall_quality_price_info(mall_quality_price_info_array * array, int mall_id, int firm_id, int mall_region_id, double quality, double price, int available)
* \brief Add an mall_quality_price_info to the dynamic mall_quality_price_info array.
* \param array Pointer to the dynamic mall_quality_price_info array.
* \param new_int The mall_quality_price_info to add
*/
void add_mall_quality_price_info(mall_quality_price_info_array * array, int mall_id, int firm_id, int mall_region_id, double quality, double price, int available)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (mall_quality_price_info *)realloc((*array).array, ((*array).total_size * sizeof(mall_quality_price_info)));
	}
	init_mall_quality_price_info(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].mall_region_id = mall_region_id;
	(*array).array[(*array).size].quality = quality;
	(*array).array[(*array).size].price = price;
	(*array).array[(*array).size].available = available;

	(*array).size++;
}

/** \fn void remove_mall_quality_price_info(mall_quality_price_info_array * array, int index)
 * \brief Remove an mall_quality_price_info from a dynamic mall_quality_price_info array.
 * \param array Pointer to the dynamic mall_quality_price_info array.
 * \param index The index of the mall_quality_price_info to remove.
 */
void remove_mall_quality_price_info(mall_quality_price_info_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_mall_quality_price_info(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_mall_quality_price_info(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the mall_stock datatype */
/** \fn mall_stock_array * init_mall_stock_array()
 * \brief Allocate memory for a dynamic mall_stock array.
 * \return mall_stock_array Pointer to the new dynamic mall_stock array.
 */
void init_mall_stock_array(mall_stock_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (mall_stock *)malloc(ARRAY_BLOCK_SIZE * sizeof(mall_stock));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_mall_stock_array(mall_stock_array* array)
* \brief Reset the mall_stock array to hold nothing.
* \param array Pointer to the dynamic mall_stock array.
*/
void reset_mall_stock_array(mall_stock_array * array)
{
	(*array).size = 0;
}

/** \fn void free_mall_stock_array(mall_stock_array * array)
* \brief Free the memory of a dynamic mall_stock array.
* \param array Pointer to the dynamic mall_stock array.
*/
void free_mall_stock_array(mall_stock_array * array)
{
	free((*array).array);
}

void copy_mall_stock_array(mall_stock_array * from, mall_stock_array * to)
{
	int i;
	
	//to = init_mall_stock_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_mall_stock(to, (*from).array[i].firm_id, (*from).array[i].region_id, (*from).array[i].stock, (*from).array[i].price, (*from).array[i].quality, (*from).array[i].previous_price);
	}
}

/** \fn void add_mall_stock(mall_stock_array * array, int firm_id, int region_id, double stock, double price, double quality, double previous_price)
* \brief Add an mall_stock to the dynamic mall_stock array.
* \param array Pointer to the dynamic mall_stock array.
* \param new_int The mall_stock to add
*/
void add_mall_stock(mall_stock_array * array, int firm_id, int region_id, double stock, double price, double quality, double previous_price)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (mall_stock *)realloc((*array).array, ((*array).total_size * sizeof(mall_stock)));
	}
	init_mall_stock(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].stock = stock;
	(*array).array[(*array).size].price = price;
	(*array).array[(*array).size].quality = quality;
	(*array).array[(*array).size].previous_price = previous_price;

	(*array).size++;
}

/** \fn void remove_mall_stock(mall_stock_array * array, int index)
 * \brief Remove an mall_stock from a dynamic mall_stock array.
 * \param array Pointer to the dynamic mall_stock array.
 * \param index The index of the mall_stock to remove.
 */
void remove_mall_stock(mall_stock_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_mall_stock(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_mall_stock(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the delivery_volume_per_mall datatype */
/** \fn delivery_volume_per_mall_array * init_delivery_volume_per_mall_array()
 * \brief Allocate memory for a dynamic delivery_volume_per_mall array.
 * \return delivery_volume_per_mall_array Pointer to the new dynamic delivery_volume_per_mall array.
 */
void init_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (delivery_volume_per_mall *)malloc(ARRAY_BLOCK_SIZE * sizeof(delivery_volume_per_mall));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_delivery_volume_per_mall_array(delivery_volume_per_mall_array* array)
* \brief Reset the delivery_volume_per_mall array to hold nothing.
* \param array Pointer to the dynamic delivery_volume_per_mall array.
*/
void reset_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array)
{
	(*array).size = 0;
}

/** \fn void free_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array)
* \brief Free the memory of a dynamic delivery_volume_per_mall array.
* \param array Pointer to the dynamic delivery_volume_per_mall array.
*/
void free_delivery_volume_per_mall_array(delivery_volume_per_mall_array * array)
{
	free((*array).array);
}

void copy_delivery_volume_per_mall_array(delivery_volume_per_mall_array * from, delivery_volume_per_mall_array * to)
{
	int i;
	
	//to = init_delivery_volume_per_mall_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_delivery_volume_per_mall(to, (*from).array[i].mall_id, (*from).array[i].quantity, (*from).array[i].price, (*from).array[i].quality);
	}
}

/** \fn void add_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int mall_id, double quantity, double price, double quality)
* \brief Add an delivery_volume_per_mall to the dynamic delivery_volume_per_mall array.
* \param array Pointer to the dynamic delivery_volume_per_mall array.
* \param new_int The delivery_volume_per_mall to add
*/
void add_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int mall_id, double quantity, double price, double quality)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (delivery_volume_per_mall *)realloc((*array).array, ((*array).total_size * sizeof(delivery_volume_per_mall)));
	}
	init_delivery_volume_per_mall(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].quantity = quantity;
	(*array).array[(*array).size].price = price;
	(*array).array[(*array).size].quality = quality;

	(*array).size++;
}

/** \fn void remove_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int index)
 * \brief Remove an delivery_volume_per_mall from a dynamic delivery_volume_per_mall array.
 * \param array Pointer to the dynamic delivery_volume_per_mall array.
 * \param index The index of the delivery_volume_per_mall to remove.
 */
void remove_delivery_volume_per_mall(delivery_volume_per_mall_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_delivery_volume_per_mall(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_delivery_volume_per_mall(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the logit_firm_id datatype */
/** \fn logit_firm_id_array * init_logit_firm_id_array()
 * \brief Allocate memory for a dynamic logit_firm_id array.
 * \return logit_firm_id_array Pointer to the new dynamic logit_firm_id array.
 */
void init_logit_firm_id_array(logit_firm_id_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (logit_firm_id *)malloc(ARRAY_BLOCK_SIZE * sizeof(logit_firm_id));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_logit_firm_id_array(logit_firm_id_array* array)
* \brief Reset the logit_firm_id array to hold nothing.
* \param array Pointer to the dynamic logit_firm_id array.
*/
void reset_logit_firm_id_array(logit_firm_id_array * array)
{
	(*array).size = 0;
}

/** \fn void free_logit_firm_id_array(logit_firm_id_array * array)
* \brief Free the memory of a dynamic logit_firm_id array.
* \param array Pointer to the dynamic logit_firm_id array.
*/
void free_logit_firm_id_array(logit_firm_id_array * array)
{
	free((*array).array);
}

void copy_logit_firm_id_array(logit_firm_id_array * from, logit_firm_id_array * to)
{
	int i;
	
	//to = init_logit_firm_id_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_logit_firm_id(to, (*from).array[i].logit, (*from).array[i].firm_id);
	}
}

/** \fn void add_logit_firm_id(logit_firm_id_array * array, double logit, int firm_id)
* \brief Add an logit_firm_id to the dynamic logit_firm_id array.
* \param array Pointer to the dynamic logit_firm_id array.
* \param new_int The logit_firm_id to add
*/
void add_logit_firm_id(logit_firm_id_array * array, double logit, int firm_id)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (logit_firm_id *)realloc((*array).array, ((*array).total_size * sizeof(logit_firm_id)));
	}
	init_logit_firm_id(&(*array).array[(*array).size]);
	(*array).array[(*array).size].logit = logit;
	(*array).array[(*array).size].firm_id = firm_id;

	(*array).size++;
}

/** \fn void remove_logit_firm_id(logit_firm_id_array * array, int index)
 * \brief Remove an logit_firm_id from a dynamic logit_firm_id array.
 * \param array Pointer to the dynamic logit_firm_id array.
 * \param index The index of the logit_firm_id to remove.
 */
void remove_logit_firm_id(logit_firm_id_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_logit_firm_id(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_logit_firm_id(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the sales_in_mall datatype */
/** \fn sales_in_mall_array * init_sales_in_mall_array()
 * \brief Allocate memory for a dynamic sales_in_mall array.
 * \return sales_in_mall_array Pointer to the new dynamic sales_in_mall array.
 */
void init_sales_in_mall_array(sales_in_mall_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (sales_in_mall *)malloc(ARRAY_BLOCK_SIZE * sizeof(sales_in_mall));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_sales_in_mall_array(sales_in_mall_array* array)
* \brief Reset the sales_in_mall array to hold nothing.
* \param array Pointer to the dynamic sales_in_mall array.
*/
void reset_sales_in_mall_array(sales_in_mall_array * array)
{
	(*array).size = 0;
}

/** \fn void free_sales_in_mall_array(sales_in_mall_array * array)
* \brief Free the memory of a dynamic sales_in_mall array.
* \param array Pointer to the dynamic sales_in_mall array.
*/
void free_sales_in_mall_array(sales_in_mall_array * array)
{
	free((*array).array);
}

void copy_sales_in_mall_array(sales_in_mall_array * from, sales_in_mall_array * to)
{
	int i;
	
	//to = init_sales_in_mall_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_sales_in_mall(to, (*from).array[i].firm_id, (*from).array[i].sales);
	}
}

/** \fn void add_sales_in_mall(sales_in_mall_array * array, int firm_id, double sales)
* \brief Add an sales_in_mall to the dynamic sales_in_mall array.
* \param array Pointer to the dynamic sales_in_mall array.
* \param new_int The sales_in_mall to add
*/
void add_sales_in_mall(sales_in_mall_array * array, int firm_id, double sales)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (sales_in_mall *)realloc((*array).array, ((*array).total_size * sizeof(sales_in_mall)));
	}
	init_sales_in_mall(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].sales = sales;

	(*array).size++;
}

/** \fn void remove_sales_in_mall(sales_in_mall_array * array, int index)
 * \brief Remove an sales_in_mall from a dynamic sales_in_mall array.
 * \param array Pointer to the dynamic sales_in_mall array.
 * \param index The index of the sales_in_mall to remove.
 */
void remove_sales_in_mall(sales_in_mall_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_sales_in_mall(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_sales_in_mall(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the ordered_quantity datatype */
/** \fn ordered_quantity_array * init_ordered_quantity_array()
 * \brief Allocate memory for a dynamic ordered_quantity array.
 * \return ordered_quantity_array Pointer to the new dynamic ordered_quantity array.
 */
void init_ordered_quantity_array(ordered_quantity_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (ordered_quantity *)malloc(ARRAY_BLOCK_SIZE * sizeof(ordered_quantity));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_ordered_quantity_array(ordered_quantity_array* array)
* \brief Reset the ordered_quantity array to hold nothing.
* \param array Pointer to the dynamic ordered_quantity array.
*/
void reset_ordered_quantity_array(ordered_quantity_array * array)
{
	(*array).size = 0;
}

/** \fn void free_ordered_quantity_array(ordered_quantity_array * array)
* \brief Free the memory of a dynamic ordered_quantity array.
* \param array Pointer to the dynamic ordered_quantity array.
*/
void free_ordered_quantity_array(ordered_quantity_array * array)
{
	free((*array).array);
}

void copy_ordered_quantity_array(ordered_quantity_array * from, ordered_quantity_array * to)
{
	int i;
	
	//to = init_ordered_quantity_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_ordered_quantity(to, (*from).array[i].firm_id, (*from).array[i].quantity, (*from).array[i].price);
	}
}

/** \fn void add_ordered_quantity(ordered_quantity_array * array, int firm_id, double quantity, double price)
* \brief Add an ordered_quantity to the dynamic ordered_quantity array.
* \param array Pointer to the dynamic ordered_quantity array.
* \param new_int The ordered_quantity to add
*/
void add_ordered_quantity(ordered_quantity_array * array, int firm_id, double quantity, double price)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (ordered_quantity *)realloc((*array).array, ((*array).total_size * sizeof(ordered_quantity)));
	}
	init_ordered_quantity(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].quantity = quantity;
	(*array).array[(*array).size].price = price;

	(*array).size++;
}

/** \fn void remove_ordered_quantity(ordered_quantity_array * array, int index)
 * \brief Remove an ordered_quantity from a dynamic ordered_quantity array.
 * \param array Pointer to the dynamic ordered_quantity array.
 * \param index The index of the ordered_quantity to remove.
 */
void remove_ordered_quantity(ordered_quantity_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_ordered_quantity(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_ordered_quantity(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the received_quantities datatype */
/** \fn received_quantities_array * init_received_quantities_array()
 * \brief Allocate memory for a dynamic received_quantities array.
 * \return received_quantities_array Pointer to the new dynamic received_quantities array.
 */
void init_received_quantities_array(received_quantities_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (received_quantities *)malloc(ARRAY_BLOCK_SIZE * sizeof(received_quantities));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_received_quantities_array(received_quantities_array* array)
* \brief Reset the received_quantities array to hold nothing.
* \param array Pointer to the dynamic received_quantities array.
*/
void reset_received_quantities_array(received_quantities_array * array)
{
	(*array).size = 0;
}

/** \fn void free_received_quantities_array(received_quantities_array * array)
* \brief Free the memory of a dynamic received_quantities array.
* \param array Pointer to the dynamic received_quantities array.
*/
void free_received_quantities_array(received_quantities_array * array)
{
	free((*array).array);
}

void copy_received_quantities_array(received_quantities_array * from, received_quantities_array * to)
{
	int i;
	
	//to = init_received_quantities_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_received_quantities(to, (*from).array[i].firm_id, (*from).array[i].quantity);
	}
}

/** \fn void add_received_quantities(received_quantities_array * array, int firm_id, double quantity)
* \brief Add an received_quantities to the dynamic received_quantities array.
* \param array Pointer to the dynamic received_quantities array.
* \param new_int The received_quantities to add
*/
void add_received_quantities(received_quantities_array * array, int firm_id, double quantity)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (received_quantities *)realloc((*array).array, ((*array).total_size * sizeof(received_quantities)));
	}
	init_received_quantities(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].quantity = quantity;

	(*array).size++;
}

/** \fn void remove_received_quantities(received_quantities_array * array, int index)
 * \brief Remove an received_quantities from a dynamic received_quantities array.
 * \param array Pointer to the dynamic received_quantities array.
 * \param index The index of the received_quantities to remove.
 */
void remove_received_quantities(received_quantities_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_received_quantities(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_received_quantities(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the sold_quantities_per_mall datatype */
/** \fn sold_quantities_per_mall_array * init_sold_quantities_per_mall_array()
 * \brief Allocate memory for a dynamic sold_quantities_per_mall array.
 * \return sold_quantities_per_mall_array Pointer to the new dynamic sold_quantities_per_mall array.
 */
void init_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (sold_quantities_per_mall *)malloc(ARRAY_BLOCK_SIZE * sizeof(sold_quantities_per_mall));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_sold_quantities_per_mall_array(sold_quantities_per_mall_array* array)
* \brief Reset the sold_quantities_per_mall array to hold nothing.
* \param array Pointer to the dynamic sold_quantities_per_mall array.
*/
void reset_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array)
{
	(*array).size = 0;
}

/** \fn void free_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array)
* \brief Free the memory of a dynamic sold_quantities_per_mall array.
* \param array Pointer to the dynamic sold_quantities_per_mall array.
*/
void free_sold_quantities_per_mall_array(sold_quantities_per_mall_array * array)
{
	free((*array).array);
}

void copy_sold_quantities_per_mall_array(sold_quantities_per_mall_array * from, sold_quantities_per_mall_array * to)
{
	int i;
	
	//to = init_sold_quantities_per_mall_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_sold_quantities_per_mall(to, (*from).array[i].mall_id, (*from).array[i].sold_quantity, (*from).array[i].stock_empty, (*from).array[i].estimated_demand);
	}
}

/** \fn void add_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int mall_id, double sold_quantity, int stock_empty, double estimated_demand)
* \brief Add an sold_quantities_per_mall to the dynamic sold_quantities_per_mall array.
* \param array Pointer to the dynamic sold_quantities_per_mall array.
* \param new_int The sold_quantities_per_mall to add
*/
void add_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int mall_id, double sold_quantity, int stock_empty, double estimated_demand)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (sold_quantities_per_mall *)realloc((*array).array, ((*array).total_size * sizeof(sold_quantities_per_mall)));
	}
	init_sold_quantities_per_mall(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].sold_quantity = sold_quantity;
	(*array).array[(*array).size].stock_empty = stock_empty;
	(*array).array[(*array).size].estimated_demand = estimated_demand;

	(*array).size++;
}

/** \fn void remove_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int index)
 * \brief Remove an sold_quantities_per_mall from a dynamic sold_quantities_per_mall array.
 * \param array Pointer to the dynamic sold_quantities_per_mall array.
 * \param index The index of the sold_quantities_per_mall to remove.
 */
void remove_sold_quantities_per_mall(sold_quantities_per_mall_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_sold_quantities_per_mall(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_sold_quantities_per_mall(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the sales_statistics datatype */
/** \fn sales_statistics_array * init_sales_statistics_array()
 * \brief Allocate memory for a dynamic sales_statistics array.
 * \return sales_statistics_array Pointer to the new dynamic sales_statistics array.
 */
void init_sales_statistics_array(sales_statistics_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (sales_statistics *)malloc(ARRAY_BLOCK_SIZE * sizeof(sales_statistics));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_sales_statistics_array(sales_statistics_array* array)
* \brief Reset the sales_statistics array to hold nothing.
* \param array Pointer to the dynamic sales_statistics array.
*/
void reset_sales_statistics_array(sales_statistics_array * array)
{
	(*array).size = 0;
}

/** \fn void free_sales_statistics_array(sales_statistics_array * array)
* \brief Free the memory of a dynamic sales_statistics array.
* \param array Pointer to the dynamic sales_statistics array.
*/
void free_sales_statistics_array(sales_statistics_array * array)
{
	free((*array).array);
}

void copy_sales_statistics_array(sales_statistics_array * from, sales_statistics_array * to)
{
	int i;
	
	//to = init_sales_statistics_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_sales_statistics(to, (*from).array[i].mall_id, (*from).array[i].period, (*from).array[i].sales);
	}
}

/** \fn void add_sales_statistics(sales_statistics_array * array, int mall_id, int period, double sales)
* \brief Add an sales_statistics to the dynamic sales_statistics array.
* \param array Pointer to the dynamic sales_statistics array.
* \param new_int The sales_statistics to add
*/
void add_sales_statistics(sales_statistics_array * array, int mall_id, int period, double sales)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (sales_statistics *)realloc((*array).array, ((*array).total_size * sizeof(sales_statistics)));
	}
	init_sales_statistics(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	(*array).array[(*array).size].period = period;
	(*array).array[(*array).size].sales = sales;

	(*array).size++;
}

/** \fn void remove_sales_statistics(sales_statistics_array * array, int index)
 * \brief Remove an sales_statistics from a dynamic sales_statistics array.
 * \param array Pointer to the dynamic sales_statistics array.
 * \param index The index of the sales_statistics to remove.
 */
void remove_sales_statistics(sales_statistics_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_sales_statistics(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_sales_statistics(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the financing_capital datatype */
/** \fn financing_capital_array * init_financing_capital_array()
 * \brief Allocate memory for a dynamic financing_capital array.
 * \return financing_capital_array Pointer to the new dynamic financing_capital array.
 */
void init_financing_capital_array(financing_capital_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (financing_capital *)malloc(ARRAY_BLOCK_SIZE * sizeof(financing_capital));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_financing_capital_array(financing_capital_array* array)
* \brief Reset the financing_capital array to hold nothing.
* \param array Pointer to the dynamic financing_capital array.
*/
void reset_financing_capital_array(financing_capital_array * array)
{
	(*array).size = 0;
}

/** \fn void free_financing_capital_array(financing_capital_array * array)
* \brief Free the memory of a dynamic financing_capital array.
* \param array Pointer to the dynamic financing_capital array.
*/
void free_financing_capital_array(financing_capital_array * array)
{
	free((*array).array);
}

void copy_financing_capital_array(financing_capital_array * from, financing_capital_array * to)
{
	int i;
	
	//to = init_financing_capital_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_financing_capital(to, (*from).array[i].financing_per_month, (*from).array[i].nr_periods_before_repayment);
	}
}

/** \fn void add_financing_capital(financing_capital_array * array, double financing_per_month, int nr_periods_before_repayment)
* \brief Add an financing_capital to the dynamic financing_capital array.
* \param array Pointer to the dynamic financing_capital array.
* \param new_int The financing_capital to add
*/
void add_financing_capital(financing_capital_array * array, double financing_per_month, int nr_periods_before_repayment)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (financing_capital *)realloc((*array).array, ((*array).total_size * sizeof(financing_capital)));
	}
	init_financing_capital(&(*array).array[(*array).size]);
	(*array).array[(*array).size].financing_per_month = financing_per_month;
	(*array).array[(*array).size].nr_periods_before_repayment = nr_periods_before_repayment;

	(*array).size++;
}

/** \fn void remove_financing_capital(financing_capital_array * array, int index)
 * \brief Remove an financing_capital from a dynamic financing_capital array.
 * \param array Pointer to the dynamic financing_capital array.
 * \param index The index of the financing_capital to remove.
 */
void remove_financing_capital(financing_capital_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_financing_capital(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_financing_capital(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
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
/* Functions for the account_item datatype */
/** \fn account_item_array * init_account_item_array()
 * \brief Allocate memory for a dynamic account_item array.
 * \return account_item_array Pointer to the new dynamic account_item array.
 */
void init_account_item_array(account_item_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (account_item *)malloc(ARRAY_BLOCK_SIZE * sizeof(account_item));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_account_item_array(account_item_array* array)
* \brief Reset the account_item array to hold nothing.
* \param array Pointer to the dynamic account_item array.
*/
void reset_account_item_array(account_item_array * array)
{
	(*array).size = 0;
}

/** \fn void free_account_item_array(account_item_array * array)
* \brief Free the memory of a dynamic account_item array.
* \param array Pointer to the dynamic account_item array.
*/
void free_account_item_array(account_item_array * array)
{
	free((*array).array);
}

void copy_account_item_array(account_item_array * from, account_item_array * to)
{
	int i;
	
	//to = init_account_item_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_account_item(to, (*from).array[i].id, (*from).array[i].payment_account);
	}
}

/** \fn void add_account_item(account_item_array * array, int id, double payment_account)
* \brief Add an account_item to the dynamic account_item array.
* \param array Pointer to the dynamic account_item array.
* \param new_int The account_item to add
*/
void add_account_item(account_item_array * array, int id, double payment_account)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (account_item *)realloc((*array).array, ((*array).total_size * sizeof(account_item)));
	}
	init_account_item(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].payment_account = payment_account;

	(*array).size++;
}

/** \fn void remove_account_item(account_item_array * array, int index)
 * \brief Remove an account_item from a dynamic account_item array.
 * \param array Pointer to the dynamic account_item array.
 * \param index The index of the account_item to remove.
 */
void remove_account_item(account_item_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_account_item(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_account_item(&(*array).array[i+1], &(*array).array[i]);
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
/* Functions for the Order datatype */
/** \fn Order_array * init_Order_array()
 * \brief Allocate memory for a dynamic Order array.
 * \return Order_array Pointer to the new dynamic Order array.
 */
void init_Order_array(Order_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (Order *)malloc(ARRAY_BLOCK_SIZE * sizeof(Order));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_Order_array(Order_array* array)
* \brief Reset the Order array to hold nothing.
* \param array Pointer to the dynamic Order array.
*/
void reset_Order_array(Order_array * array)
{
	(*array).size = 0;
}

/** \fn void free_Order_array(Order_array * array)
* \brief Free the memory of a dynamic Order array.
* \param array Pointer to the dynamic Order array.
*/
void free_Order_array(Order_array * array)
{
	free((*array).array);
}

void copy_Order_array(Order_array * from, Order_array * to)
{
	int i;
	
	//to = init_Order_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_Order(to, (*from).array[i].issuer, (*from).array[i].quantity, (*from).array[i].price, (*from).array[i].assetId);
	}
}

/** \fn void add_Order(Order_array * array, int issuer, int quantity, double price, int assetId)
* \brief Add an Order to the dynamic Order array.
* \param array Pointer to the dynamic Order array.
* \param new_int The Order to add
*/
void add_Order(Order_array * array, int issuer, int quantity, double price, int assetId)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (Order *)realloc((*array).array, ((*array).total_size * sizeof(Order)));
	}
	init_Order(&(*array).array[(*array).size]);
	(*array).array[(*array).size].issuer = issuer;
	(*array).array[(*array).size].quantity = quantity;
	(*array).array[(*array).size].price = price;
	(*array).array[(*array).size].assetId = assetId;

	(*array).size++;
}

/** \fn void remove_Order(Order_array * array, int index)
 * \brief Remove an Order from a dynamic Order array.
 * \param array Pointer to the dynamic Order array.
 * \param index The index of the Order to remove.
 */
void remove_Order(Order_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_Order(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_Order(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the Belief datatype */
/** \fn Belief_array * init_Belief_array()
 * \brief Allocate memory for a dynamic Belief array.
 * \return Belief_array Pointer to the new dynamic Belief array.
 */
void init_Belief_array(Belief_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (Belief *)malloc(ARRAY_BLOCK_SIZE * sizeof(Belief));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_Belief_array(Belief_array* array)
* \brief Reset the Belief array to hold nothing.
* \param array Pointer to the dynamic Belief array.
*/
void reset_Belief_array(Belief_array * array)
{
	(*array).size = 0;
}

/** \fn void free_Belief_array(Belief_array * array)
* \brief Free the memory of a dynamic Belief array.
* \param array Pointer to the dynamic Belief array.
*/
void free_Belief_array(Belief_array * array)
{
	free((*array).array);
}

void copy_Belief_array(Belief_array * from, Belief_array * to)
{
	int i;
	
	//to = init_Belief_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_Belief(to, (*from).array[i].asset_id, (*from).array[i].expectedPriceReturns, (*from).array[i].expectedTotalReturns, (*from).array[i].expectedCashFlowYield, (*from).array[i].volatility, (*from).array[i].expectedEarning, (*from).array[i].expectedEarningPayout, (*from).array[i].last_price, (*from).array[i].utility);
	}
}

/** \fn void add_Belief(Belief_array * array, int asset_id, double expectedPriceReturns, double expectedTotalReturns, double expectedCashFlowYield, double volatility, double expectedEarning, double expectedEarningPayout, double last_price, double utility)
* \brief Add an Belief to the dynamic Belief array.
* \param array Pointer to the dynamic Belief array.
* \param new_int The Belief to add
*/
void add_Belief(Belief_array * array, int asset_id, double expectedPriceReturns, double expectedTotalReturns, double expectedCashFlowYield, double volatility, double expectedEarning, double expectedEarningPayout, double last_price, double utility)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (Belief *)realloc((*array).array, ((*array).total_size * sizeof(Belief)));
	}
	init_Belief(&(*array).array[(*array).size]);
	(*array).array[(*array).size].asset_id = asset_id;
	(*array).array[(*array).size].expectedPriceReturns = expectedPriceReturns;
	(*array).array[(*array).size].expectedTotalReturns = expectedTotalReturns;
	(*array).array[(*array).size].expectedCashFlowYield = expectedCashFlowYield;
	(*array).array[(*array).size].volatility = volatility;
	(*array).array[(*array).size].expectedEarning = expectedEarning;
	(*array).array[(*array).size].expectedEarningPayout = expectedEarningPayout;
	(*array).array[(*array).size].last_price = last_price;
	(*array).array[(*array).size].utility = utility;

	(*array).size++;
}

/** \fn void remove_Belief(Belief_array * array, int index)
 * \brief Remove an Belief from a dynamic Belief array.
 * \param array Pointer to the dynamic Belief array.
 * \param index The index of the Belief to remove.
 */
void remove_Belief(Belief_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_Belief(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_Belief(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the Stock datatype */
/** \fn Stock_array * init_Stock_array()
 * \brief Allocate memory for a dynamic Stock array.
 * \return Stock_array Pointer to the new dynamic Stock array.
 */
void init_Stock_array(Stock_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (Stock *)malloc(ARRAY_BLOCK_SIZE * sizeof(Stock));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_Stock_array(Stock_array* array)
* \brief Reset the Stock array to hold nothing.
* \param array Pointer to the dynamic Stock array.
*/
void reset_Stock_array(Stock_array * array)
{
	(*array).size = 0;
}

/** \fn void free_Stock_array(Stock_array * array)
* \brief Free the memory of a dynamic Stock array.
* \param array Pointer to the dynamic Stock array.
*/
void free_Stock_array(Stock_array * array)
{
	free((*array).array);
}

void copy_Stock_array(Stock_array * from, Stock_array * to)
{
	int i;
	
	//to = init_Stock_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_Stock(to, (*from).array[i].id, (*from).array[i].nrOutStandingShares, (*from).array[i].index, (*from).array[i].prices, (*from).array[i].returns);
	}
}

/** \fn void add_Stock(Stock_array * array, int id, int nrOutStandingShares, int index, double prices, double returns)
* \brief Add an Stock to the dynamic Stock array.
* \param array Pointer to the dynamic Stock array.
* \param new_int The Stock to add
*/
void add_Stock(Stock_array * array, int id, int nrOutStandingShares, int index, double * prices, double * returns)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (Stock *)realloc((*array).array, ((*array).total_size * sizeof(Stock)));
	}
	init_Stock(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].nrOutStandingShares = nrOutStandingShares;
	(*array).array[(*array).size].index = index;
	if(prices != NULL) memcpy((*array).array[(*array).size].prices, prices, 100*sizeof(double));
	if(returns != NULL) memcpy((*array).array[(*array).size].returns, returns, 100*sizeof(double));

	(*array).size++;
}

/** \fn void remove_Stock(Stock_array * array, int index)
 * \brief Remove an Stock from a dynamic Stock array.
 * \param array Pointer to the dynamic Stock array.
 * \param index The index of the Stock to remove.
 */
void remove_Stock(Stock_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_Stock(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_Stock(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the Bond datatype */
/** \fn Bond_array * init_Bond_array()
 * \brief Allocate memory for a dynamic Bond array.
 * \return Bond_array Pointer to the new dynamic Bond array.
 */
void init_Bond_array(Bond_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (Bond *)malloc(ARRAY_BLOCK_SIZE * sizeof(Bond));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_Bond_array(Bond_array* array)
* \brief Reset the Bond array to hold nothing.
* \param array Pointer to the dynamic Bond array.
*/
void reset_Bond_array(Bond_array * array)
{
	(*array).size = 0;
}

/** \fn void free_Bond_array(Bond_array * array)
* \brief Free the memory of a dynamic Bond array.
* \param array Pointer to the dynamic Bond array.
*/
void free_Bond_array(Bond_array * array)
{
	free((*array).array);
}

void copy_Bond_array(Bond_array * from, Bond_array * to)
{
	int i;
	
	//to = init_Bond_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_Bond(to, (*from).array[i].id, (*from).array[i].nr_outstanding, (*from).array[i].quantity, (*from).array[i].face_value, (*from).array[i].nominal_yield, (*from).array[i].maturity_day, (*from).array[i].issue_day, (*from).array[i].yield2maturity, (*from).array[i].prices, (*from).array[i].index, (*from).array[i].returns);
	}
}

/** \fn void add_Bond(Bond_array * array, int id, int nr_outstanding, int quantity, double face_value, double nominal_yield, int maturity_day, int issue_day, double yield2maturity, double prices, int index, double returns)
* \brief Add an Bond to the dynamic Bond array.
* \param array Pointer to the dynamic Bond array.
* \param new_int The Bond to add
*/
void add_Bond(Bond_array * array, int id, int nr_outstanding, int quantity, double face_value, double nominal_yield, int maturity_day, int issue_day, double yield2maturity, double * prices, int index, double * returns)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (Bond *)realloc((*array).array, ((*array).total_size * sizeof(Bond)));
	}
	init_Bond(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].nr_outstanding = nr_outstanding;
	(*array).array[(*array).size].quantity = quantity;
	(*array).array[(*array).size].face_value = face_value;
	(*array).array[(*array).size].nominal_yield = nominal_yield;
	(*array).array[(*array).size].maturity_day = maturity_day;
	(*array).array[(*array).size].issue_day = issue_day;
	(*array).array[(*array).size].yield2maturity = yield2maturity;
	if(prices != NULL) memcpy((*array).array[(*array).size].prices, prices, 100*sizeof(double));
	(*array).array[(*array).size].index = index;
	if(returns != NULL) memcpy((*array).array[(*array).size].returns, returns, 100*sizeof(double));

	(*array).size++;
}

/** \fn void remove_Bond(Bond_array * array, int index)
 * \brief Remove an Bond from a dynamic Bond array.
 * \param array Pointer to the dynamic Bond array.
 * \param index The index of the Bond to remove.
 */
void remove_Bond(Bond_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_Bond(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_Bond(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the Asset datatype */
/** \fn Asset_array * init_Asset_array()
 * \brief Allocate memory for a dynamic Asset array.
 * \return Asset_array Pointer to the new dynamic Asset array.
 */
void init_Asset_array(Asset_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (Asset *)malloc(ARRAY_BLOCK_SIZE * sizeof(Asset));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_Asset_array(Asset_array* array)
* \brief Reset the Asset array to hold nothing.
* \param array Pointer to the dynamic Asset array.
*/
void reset_Asset_array(Asset_array * array)
{
	(*array).size = 0;
}

/** \fn void free_Asset_array(Asset_array * array)
* \brief Free the memory of a dynamic Asset array.
* \param array Pointer to the dynamic Asset array.
*/
void free_Asset_array(Asset_array * array)
{
	free((*array).array);
}

void copy_Asset_array(Asset_array * from, Asset_array * to)
{
	int i;
	
	//to = init_Asset_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_Asset(to, (*from).array[i].id, (*from).array[i].quantity, (*from).array[i].lastPrice);
	}
}

/** \fn void add_Asset(Asset_array * array, int id, int quantity, double lastPrice)
* \brief Add an Asset to the dynamic Asset array.
* \param array Pointer to the dynamic Asset array.
* \param new_int The Asset to add
*/
void add_Asset(Asset_array * array, int id, int quantity, double lastPrice)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (Asset *)realloc((*array).array, ((*array).total_size * sizeof(Asset)));
	}
	init_Asset(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].quantity = quantity;
	(*array).array[(*array).size].lastPrice = lastPrice;

	(*array).size++;
}

/** \fn void remove_Asset(Asset_array * array, int index)
 * \brief Remove an Asset from a dynamic Asset array.
 * \param array Pointer to the dynamic Asset array.
 * \param index The index of the Asset to remove.
 */
void remove_Asset(Asset_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_Asset(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_Asset(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the ClearingMechanism datatype */
/** \fn ClearingMechanism_array * init_ClearingMechanism_array()
 * \brief Allocate memory for a dynamic ClearingMechanism array.
 * \return ClearingMechanism_array Pointer to the new dynamic ClearingMechanism array.
 */
void init_ClearingMechanism_array(ClearingMechanism_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (ClearingMechanism *)malloc(ARRAY_BLOCK_SIZE * sizeof(ClearingMechanism));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_ClearingMechanism_array(ClearingMechanism_array* array)
* \brief Reset the ClearingMechanism array to hold nothing.
* \param array Pointer to the dynamic ClearingMechanism array.
*/
void reset_ClearingMechanism_array(ClearingMechanism_array * array)
{
	(*array).size = 0;
}

/** \fn void free_ClearingMechanism_array(ClearingMechanism_array * array)
* \brief Free the memory of a dynamic ClearingMechanism array.
* \param array Pointer to the dynamic ClearingMechanism array.
*/
void free_ClearingMechanism_array(ClearingMechanism_array * array)
{
	free((*array).array);
}

void copy_ClearingMechanism_array(ClearingMechanism_array * from, ClearingMechanism_array * to)
{
	int i;
	
	//to = init_ClearingMechanism_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_ClearingMechanism(to, (*from).array[i].lastPrice, (*from).array[i].quantity, &(*from).array[i].sellOrders, &(*from).array[i].buyOrders, &(*from).array[i].prices);
	}
}

/** \fn void add_ClearingMechanism(ClearingMechanism_array * array, double lastPrice, int quantity, Order_array * sellOrders, Order_array * buyOrders, double_array prices)
* \brief Add an ClearingMechanism to the dynamic ClearingMechanism array.
* \param array Pointer to the dynamic ClearingMechanism array.
* \param new_int The ClearingMechanism to add
*/
void add_ClearingMechanism(ClearingMechanism_array * array, double lastPrice, int quantity, Order_array * sellOrders, Order_array * buyOrders, double_array * prices)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (ClearingMechanism *)realloc((*array).array, ((*array).total_size * sizeof(ClearingMechanism)));
	}
	init_ClearingMechanism(&(*array).array[(*array).size]);
	(*array).array[(*array).size].lastPrice = lastPrice;
	(*array).array[(*array).size].quantity = quantity;
	if(sellOrders != NULL) copy_Order_array(sellOrders, &(*array).array[(*array).size].sellOrders);
	if(buyOrders != NULL) copy_Order_array(buyOrders, &(*array).array[(*array).size].buyOrders);
	if(prices != NULL) copy_double_array(prices, &(*array).array[(*array).size].prices);

	(*array).size++;
}

/** \fn void remove_ClearingMechanism(ClearingMechanism_array * array, int index)
 * \brief Remove an ClearingMechanism from a dynamic ClearingMechanism array.
 * \param array Pointer to the dynamic ClearingMechanism array.
 * \param index The index of the ClearingMechanism to remove.
 */
void remove_ClearingMechanism(ClearingMechanism_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_ClearingMechanism(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_ClearingMechanism(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the employee datatype */
/** \fn employee_array * init_employee_array()
 * \brief Allocate memory for a dynamic employee array.
 * \return employee_array Pointer to the new dynamic employee array.
 */
void init_employee_array(employee_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (employee *)malloc(ARRAY_BLOCK_SIZE * sizeof(employee));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_employee_array(employee_array* array)
* \brief Reset the employee array to hold nothing.
* \param array Pointer to the dynamic employee array.
*/
void reset_employee_array(employee_array * array)
{
	(*array).size = 0;
}

/** \fn void free_employee_array(employee_array * array)
* \brief Free the memory of a dynamic employee array.
* \param array Pointer to the dynamic employee array.
*/
void free_employee_array(employee_array * array)
{
	free((*array).array);
}

void copy_employee_array(employee_array * from, employee_array * to)
{
	int i;
	
	//to = init_employee_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_employee(to, (*from).array[i].id, (*from).array[i].region_id, (*from).array[i].wage, (*from).array[i].general_skill, (*from).array[i].specific_skill);
	}
}

/** \fn void add_employee(employee_array * array, int id, int region_id, double wage, int general_skill, double specific_skill)
* \brief Add an employee to the dynamic employee array.
* \param array Pointer to the dynamic employee array.
* \param new_int The employee to add
*/
void add_employee(employee_array * array, int id, int region_id, double wage, int general_skill, double specific_skill)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (employee *)realloc((*array).array, ((*array).total_size * sizeof(employee)));
	}
	init_employee(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].wage = wage;
	(*array).array[(*array).size].general_skill = general_skill;
	(*array).array[(*array).size].specific_skill = specific_skill;

	(*array).size++;
}

/** \fn void remove_employee(employee_array * array, int index)
 * \brief Remove an employee from a dynamic employee array.
 * \param array Pointer to the dynamic employee array.
 * \param index The index of the employee to remove.
 */
void remove_employee(employee_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_employee(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_employee(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the vacancy datatype */
/** \fn vacancy_array * init_vacancy_array()
 * \brief Allocate memory for a dynamic vacancy array.
 * \return vacancy_array Pointer to the new dynamic vacancy array.
 */
void init_vacancy_array(vacancy_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (vacancy *)malloc(ARRAY_BLOCK_SIZE * sizeof(vacancy));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_vacancy_array(vacancy_array* array)
* \brief Reset the vacancy array to hold nothing.
* \param array Pointer to the dynamic vacancy array.
*/
void reset_vacancy_array(vacancy_array * array)
{
	(*array).size = 0;
}

/** \fn void free_vacancy_array(vacancy_array * array)
* \brief Free the memory of a dynamic vacancy array.
* \param array Pointer to the dynamic vacancy array.
*/
void free_vacancy_array(vacancy_array * array)
{
	free((*array).array);
}

void copy_vacancy_array(vacancy_array * from, vacancy_array * to)
{
	int i;
	
	//to = init_vacancy_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_vacancy(to, (*from).array[i].firm_id, (*from).array[i].region_id, (*from).array[i].wage_offer);
	}
}

/** \fn void add_vacancy(vacancy_array * array, int firm_id, int region_id, double wage_offer)
* \brief Add an vacancy to the dynamic vacancy array.
* \param array Pointer to the dynamic vacancy array.
* \param new_int The vacancy to add
*/
void add_vacancy(vacancy_array * array, int firm_id, int region_id, double wage_offer)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (vacancy *)realloc((*array).array, ((*array).total_size * sizeof(vacancy)));
	}
	init_vacancy(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].wage_offer = wage_offer;

	(*array).size++;
}

/** \fn void remove_vacancy(vacancy_array * array, int index)
 * \brief Remove an vacancy from a dynamic vacancy array.
 * \param array Pointer to the dynamic vacancy array.
 * \param index The index of the vacancy to remove.
 */
void remove_vacancy(vacancy_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_vacancy(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_vacancy(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the job_application datatype */
/** \fn job_application_array * init_job_application_array()
 * \brief Allocate memory for a dynamic job_application array.
 * \return job_application_array Pointer to the new dynamic job_application array.
 */
void init_job_application_array(job_application_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (job_application *)malloc(ARRAY_BLOCK_SIZE * sizeof(job_application));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_job_application_array(job_application_array* array)
* \brief Reset the job_application array to hold nothing.
* \param array Pointer to the dynamic job_application array.
*/
void reset_job_application_array(job_application_array * array)
{
	(*array).size = 0;
}

/** \fn void free_job_application_array(job_application_array * array)
* \brief Free the memory of a dynamic job_application array.
* \param array Pointer to the dynamic job_application array.
*/
void free_job_application_array(job_application_array * array)
{
	free((*array).array);
}

void copy_job_application_array(job_application_array * from, job_application_array * to)
{
	int i;
	
	//to = init_job_application_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_job_application(to, (*from).array[i].worker_id, (*from).array[i].region_id, (*from).array[i].general_skill, (*from).array[i].specific_skill);
	}
}

/** \fn void add_job_application(job_application_array * array, int worker_id, int region_id, int general_skill, double specific_skill)
* \brief Add an job_application to the dynamic job_application array.
* \param array Pointer to the dynamic job_application array.
* \param new_int The job_application to add
*/
void add_job_application(job_application_array * array, int worker_id, int region_id, int general_skill, double specific_skill)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (job_application *)realloc((*array).array, ((*array).total_size * sizeof(job_application)));
	}
	init_job_application(&(*array).array[(*array).size]);
	(*array).array[(*array).size].worker_id = worker_id;
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].general_skill = general_skill;
	(*array).array[(*array).size].specific_skill = specific_skill;

	(*array).size++;
}

/** \fn void remove_job_application(job_application_array * array, int index)
 * \brief Remove an job_application from a dynamic job_application array.
 * \param array Pointer to the dynamic job_application array.
 * \param index The index of the job_application to remove.
 */
void remove_job_application(job_application_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_job_application(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_job_application(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the job_offer datatype */
/** \fn job_offer_array * init_job_offer_array()
 * \brief Allocate memory for a dynamic job_offer array.
 * \return job_offer_array Pointer to the new dynamic job_offer array.
 */
void init_job_offer_array(job_offer_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (job_offer *)malloc(ARRAY_BLOCK_SIZE * sizeof(job_offer));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_job_offer_array(job_offer_array* array)
* \brief Reset the job_offer array to hold nothing.
* \param array Pointer to the dynamic job_offer array.
*/
void reset_job_offer_array(job_offer_array * array)
{
	(*array).size = 0;
}

/** \fn void free_job_offer_array(job_offer_array * array)
* \brief Free the memory of a dynamic job_offer array.
* \param array Pointer to the dynamic job_offer array.
*/
void free_job_offer_array(job_offer_array * array)
{
	free((*array).array);
}

void copy_job_offer_array(job_offer_array * from, job_offer_array * to)
{
	int i;
	
	//to = init_job_offer_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_job_offer(to, (*from).array[i].firm_id, (*from).array[i].region_id, (*from).array[i].wage_offer);
	}
}

/** \fn void add_job_offer(job_offer_array * array, int firm_id, int region_id, double wage_offer)
* \brief Add an job_offer to the dynamic job_offer array.
* \param array Pointer to the dynamic job_offer array.
* \param new_int The job_offer to add
*/
void add_job_offer(job_offer_array * array, int firm_id, int region_id, double wage_offer)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (job_offer *)realloc((*array).array, ((*array).total_size * sizeof(job_offer)));
	}
	init_job_offer(&(*array).array[(*array).size]);
	(*array).array[(*array).size].firm_id = firm_id;
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].wage_offer = wage_offer;

	(*array).size++;
}

/** \fn void remove_job_offer(job_offer_array * array, int index)
 * \brief Remove an job_offer from a dynamic job_offer array.
 * \param array Pointer to the dynamic job_offer array.
 * \param index The index of the job_offer to remove.
 */
void remove_job_offer(job_offer_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_job_offer(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_job_offer(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the logit datatype */
/** \fn logit_array * init_logit_array()
 * \brief Allocate memory for a dynamic logit array.
 * \return logit_array Pointer to the new dynamic logit array.
 */
void init_logit_array(logit_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (logit *)malloc(ARRAY_BLOCK_SIZE * sizeof(logit));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_logit_array(logit_array* array)
* \brief Reset the logit array to hold nothing.
* \param array Pointer to the dynamic logit array.
*/
void reset_logit_array(logit_array * array)
{
	(*array).size = 0;
}

/** \fn void free_logit_array(logit_array * array)
* \brief Free the memory of a dynamic logit array.
* \param array Pointer to the dynamic logit array.
*/
void free_logit_array(logit_array * array)
{
	free((*array).array);
}

void copy_logit_array(logit_array * from, logit_array * to)
{
	int i;
	
	//to = init_logit_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_logit(to, (*from).array[i].logit_value, (*from).array[i].worker_id, (*from).array[i].general_skill);
	}
}

/** \fn void add_logit(logit_array * array, double logit_value, int worker_id, int general_skill)
* \brief Add an logit to the dynamic logit array.
* \param array Pointer to the dynamic logit array.
* \param new_int The logit to add
*/
void add_logit(logit_array * array, double logit_value, int worker_id, int general_skill)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (logit *)realloc((*array).array, ((*array).total_size * sizeof(logit)));
	}
	init_logit(&(*array).array[(*array).size]);
	(*array).array[(*array).size].logit_value = logit_value;
	(*array).array[(*array).size].worker_id = worker_id;
	(*array).array[(*array).size].general_skill = general_skill;

	(*array).size++;
}

/** \fn void remove_logit(logit_array * array, int index)
 * \brief Remove an logit from a dynamic logit array.
 * \param array Pointer to the dynamic logit array.
 * \param index The index of the logit to remove.
 */
void remove_logit(logit_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_logit(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_logit(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the household_data datatype */
/** \fn household_data_array * init_household_data_array()
 * \brief Allocate memory for a dynamic household_data array.
 * \return household_data_array Pointer to the new dynamic household_data array.
 */
void init_household_data_array(household_data_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (household_data *)malloc(ARRAY_BLOCK_SIZE * sizeof(household_data));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_household_data_array(household_data_array* array)
* \brief Reset the household_data array to hold nothing.
* \param array Pointer to the dynamic household_data array.
*/
void reset_household_data_array(household_data_array * array)
{
	(*array).size = 0;
}

/** \fn void free_household_data_array(household_data_array * array)
* \brief Free the memory of a dynamic household_data array.
* \param array Pointer to the dynamic household_data array.
*/
void free_household_data_array(household_data_array * array)
{
	free((*array).array);
}

void copy_household_data_array(household_data_array * from, household_data_array * to)
{
	int i;
	
	//to = init_household_data_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_household_data(to, (*from).array[i].region_id, (*from).array[i].no_households, (*from).array[i].no_households_skill_1, (*from).array[i].no_households_skill_2, (*from).array[i].no_households_skill_3, (*from).array[i].no_households_skill_4, (*from).array[i].no_households_skill_5, (*from).array[i].employed, (*from).array[i].employed_skill_1, (*from).array[i].employed_skill_2, (*from).array[i].employed_skill_3, (*from).array[i].employed_skill_4, (*from).array[i].employed_skill_5, (*from).array[i].unemployed, (*from).array[i].unemployment_rate, (*from).array[i].unemployment_rate_skill_1, (*from).array[i].unemployment_rate_skill_2, (*from).array[i].unemployment_rate_skill_3, (*from).array[i].unemployment_rate_skill_4, (*from).array[i].unemployment_rate_skill_5, (*from).array[i].average_wage, (*from).array[i].average_wage_skill_1, (*from).array[i].average_wage_skill_2, (*from).array[i].average_wage_skill_3, (*from).array[i].average_wage_skill_4, (*from).array[i].average_wage_skill_5, (*from).array[i].average_s_skill, (*from).array[i].average_s_skill_1, (*from).array[i].average_s_skill_2, (*from).array[i].average_s_skill_3, (*from).array[i].average_s_skill_4, (*from).array[i].average_s_skill_5);
	}
}

/** \fn void add_household_data(household_data_array * array, int region_id, int no_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5)
* \brief Add an household_data to the dynamic household_data array.
* \param array Pointer to the dynamic household_data array.
* \param new_int The household_data to add
*/
void add_household_data(household_data_array * array, int region_id, int no_households, int no_households_skill_1, int no_households_skill_2, int no_households_skill_3, int no_households_skill_4, int no_households_skill_5, int employed, int employed_skill_1, int employed_skill_2, int employed_skill_3, int employed_skill_4, int employed_skill_5, int unemployed, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (household_data *)realloc((*array).array, ((*array).total_size * sizeof(household_data)));
	}
	init_household_data(&(*array).array[(*array).size]);
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].no_households = no_households;
	(*array).array[(*array).size].no_households_skill_1 = no_households_skill_1;
	(*array).array[(*array).size].no_households_skill_2 = no_households_skill_2;
	(*array).array[(*array).size].no_households_skill_3 = no_households_skill_3;
	(*array).array[(*array).size].no_households_skill_4 = no_households_skill_4;
	(*array).array[(*array).size].no_households_skill_5 = no_households_skill_5;
	(*array).array[(*array).size].employed = employed;
	(*array).array[(*array).size].employed_skill_1 = employed_skill_1;
	(*array).array[(*array).size].employed_skill_2 = employed_skill_2;
	(*array).array[(*array).size].employed_skill_3 = employed_skill_3;
	(*array).array[(*array).size].employed_skill_4 = employed_skill_4;
	(*array).array[(*array).size].employed_skill_5 = employed_skill_5;
	(*array).array[(*array).size].unemployed = unemployed;
	(*array).array[(*array).size].unemployment_rate = unemployment_rate;
	(*array).array[(*array).size].unemployment_rate_skill_1 = unemployment_rate_skill_1;
	(*array).array[(*array).size].unemployment_rate_skill_2 = unemployment_rate_skill_2;
	(*array).array[(*array).size].unemployment_rate_skill_3 = unemployment_rate_skill_3;
	(*array).array[(*array).size].unemployment_rate_skill_4 = unemployment_rate_skill_4;
	(*array).array[(*array).size].unemployment_rate_skill_5 = unemployment_rate_skill_5;
	(*array).array[(*array).size].average_wage = average_wage;
	(*array).array[(*array).size].average_wage_skill_1 = average_wage_skill_1;
	(*array).array[(*array).size].average_wage_skill_2 = average_wage_skill_2;
	(*array).array[(*array).size].average_wage_skill_3 = average_wage_skill_3;
	(*array).array[(*array).size].average_wage_skill_4 = average_wage_skill_4;
	(*array).array[(*array).size].average_wage_skill_5 = average_wage_skill_5;
	(*array).array[(*array).size].average_s_skill = average_s_skill;
	(*array).array[(*array).size].average_s_skill_1 = average_s_skill_1;
	(*array).array[(*array).size].average_s_skill_2 = average_s_skill_2;
	(*array).array[(*array).size].average_s_skill_3 = average_s_skill_3;
	(*array).array[(*array).size].average_s_skill_4 = average_s_skill_4;
	(*array).array[(*array).size].average_s_skill_5 = average_s_skill_5;

	(*array).size++;
}

/** \fn void remove_household_data(household_data_array * array, int index)
 * \brief Remove an household_data from a dynamic household_data array.
 * \param array Pointer to the dynamic household_data array.
 * \param index The index of the household_data to remove.
 */
void remove_household_data(household_data_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_household_data(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_household_data(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the firm_data datatype */
/** \fn firm_data_array * init_firm_data_array()
 * \brief Allocate memory for a dynamic firm_data array.
 * \return firm_data_array Pointer to the new dynamic firm_data array.
 */
void init_firm_data_array(firm_data_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (firm_data *)malloc(ARRAY_BLOCK_SIZE * sizeof(firm_data));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_firm_data_array(firm_data_array* array)
* \brief Reset the firm_data array to hold nothing.
* \param array Pointer to the dynamic firm_data array.
*/
void reset_firm_data_array(firm_data_array * array)
{
	(*array).size = 0;
}

/** \fn void free_firm_data_array(firm_data_array * array)
* \brief Free the memory of a dynamic firm_data array.
* \param array Pointer to the dynamic firm_data array.
*/
void free_firm_data_array(firm_data_array * array)
{
	free((*array).array);
}

void copy_firm_data_array(firm_data_array * from, firm_data_array * to)
{
	int i;
	
	//to = init_firm_data_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_firm_data(to, (*from).array[i].region_id, (*from).array[i].no_firms, (*from).array[i].vacancies, (*from).array[i].employees, (*from).array[i].employees_skill_1, (*from).array[i].employees_skill_2, (*from).array[i].employees_skill_3, (*from).array[i].employees_skill_4, (*from).array[i].employees_skill_5, (*from).array[i].average_wage, (*from).array[i].average_wage_skill_1, (*from).array[i].average_wage_skill_2, (*from).array[i].average_wage_skill_3, (*from).array[i].average_wage_skill_4, (*from).array[i].average_wage_skill_5, (*from).array[i].average_s_skill, (*from).array[i].average_s_skill_1, (*from).array[i].average_s_skill_2, (*from).array[i].average_s_skill_3, (*from).array[i].average_s_skill_4, (*from).array[i].average_s_skill_5, (*from).array[i].total_earnings, (*from).array[i].total_debt, (*from).array[i].total_assets, (*from).array[i].total_equity, (*from).array[i].average_debt_earnings_ratio, (*from).array[i].average_debt_equity_ratio, (*from).array[i].labour_share_ratio, (*from).array[i].monthly_sold_quantity, (*from).array[i].monthly_output, (*from).array[i].monthly_revenue, (*from).array[i].monthly_planned_output, (*from).array[i].gdp, (*from).array[i].cpi, (*from).array[i].cpi_last_month, (*from).array[i].no_firm_births, (*from).array[i].no_firm_deaths);
	}
}

/** \fn void add_firm_data(firm_data_array * array, int region_id, int no_firms, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double total_earnings, double total_debt, double total_assets, double total_equity, double average_debt_earnings_ratio, double average_debt_equity_ratio, double labour_share_ratio, double monthly_sold_quantity, double monthly_output, double monthly_revenue, double monthly_planned_output, double gdp, double cpi, double cpi_last_month, int no_firm_births, int no_firm_deaths)
* \brief Add an firm_data to the dynamic firm_data array.
* \param array Pointer to the dynamic firm_data array.
* \param new_int The firm_data to add
*/
void add_firm_data(firm_data_array * array, int region_id, int no_firms, int vacancies, int employees, int employees_skill_1, int employees_skill_2, int employees_skill_3, int employees_skill_4, int employees_skill_5, double average_wage, double average_wage_skill_1, double average_wage_skill_2, double average_wage_skill_3, double average_wage_skill_4, double average_wage_skill_5, double average_s_skill, double average_s_skill_1, double average_s_skill_2, double average_s_skill_3, double average_s_skill_4, double average_s_skill_5, double total_earnings, double total_debt, double total_assets, double total_equity, double average_debt_earnings_ratio, double average_debt_equity_ratio, double labour_share_ratio, double monthly_sold_quantity, double monthly_output, double monthly_revenue, double monthly_planned_output, double gdp, double cpi, double cpi_last_month, int no_firm_births, int no_firm_deaths)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (firm_data *)realloc((*array).array, ((*array).total_size * sizeof(firm_data)));
	}
	init_firm_data(&(*array).array[(*array).size]);
	(*array).array[(*array).size].region_id = region_id;
	(*array).array[(*array).size].no_firms = no_firms;
	(*array).array[(*array).size].vacancies = vacancies;
	(*array).array[(*array).size].employees = employees;
	(*array).array[(*array).size].employees_skill_1 = employees_skill_1;
	(*array).array[(*array).size].employees_skill_2 = employees_skill_2;
	(*array).array[(*array).size].employees_skill_3 = employees_skill_3;
	(*array).array[(*array).size].employees_skill_4 = employees_skill_4;
	(*array).array[(*array).size].employees_skill_5 = employees_skill_5;
	(*array).array[(*array).size].average_wage = average_wage;
	(*array).array[(*array).size].average_wage_skill_1 = average_wage_skill_1;
	(*array).array[(*array).size].average_wage_skill_2 = average_wage_skill_2;
	(*array).array[(*array).size].average_wage_skill_3 = average_wage_skill_3;
	(*array).array[(*array).size].average_wage_skill_4 = average_wage_skill_4;
	(*array).array[(*array).size].average_wage_skill_5 = average_wage_skill_5;
	(*array).array[(*array).size].average_s_skill = average_s_skill;
	(*array).array[(*array).size].average_s_skill_1 = average_s_skill_1;
	(*array).array[(*array).size].average_s_skill_2 = average_s_skill_2;
	(*array).array[(*array).size].average_s_skill_3 = average_s_skill_3;
	(*array).array[(*array).size].average_s_skill_4 = average_s_skill_4;
	(*array).array[(*array).size].average_s_skill_5 = average_s_skill_5;
	(*array).array[(*array).size].total_earnings = total_earnings;
	(*array).array[(*array).size].total_debt = total_debt;
	(*array).array[(*array).size].total_assets = total_assets;
	(*array).array[(*array).size].total_equity = total_equity;
	(*array).array[(*array).size].average_debt_earnings_ratio = average_debt_earnings_ratio;
	(*array).array[(*array).size].average_debt_equity_ratio = average_debt_equity_ratio;
	(*array).array[(*array).size].labour_share_ratio = labour_share_ratio;
	(*array).array[(*array).size].monthly_sold_quantity = monthly_sold_quantity;
	(*array).array[(*array).size].monthly_output = monthly_output;
	(*array).array[(*array).size].monthly_revenue = monthly_revenue;
	(*array).array[(*array).size].monthly_planned_output = monthly_planned_output;
	(*array).array[(*array).size].gdp = gdp;
	(*array).array[(*array).size].cpi = cpi;
	(*array).array[(*array).size].cpi_last_month = cpi_last_month;
	(*array).array[(*array).size].no_firm_births = no_firm_births;
	(*array).array[(*array).size].no_firm_deaths = no_firm_deaths;

	(*array).size++;
}

/** \fn void remove_firm_data(firm_data_array * array, int index)
 * \brief Remove an firm_data from a dynamic firm_data array.
 * \param array Pointer to the dynamic firm_data array.
 * \param index The index of the firm_data to remove.
 */
void remove_firm_data(firm_data_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_firm_data(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_firm_data(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the region_data_item datatype */
/** \fn region_data_item_array * init_region_data_item_array()
 * \brief Allocate memory for a dynamic region_data_item array.
 * \return region_data_item_array Pointer to the new dynamic region_data_item array.
 */
void init_region_data_item_array(region_data_item_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (region_data_item *)malloc(ARRAY_BLOCK_SIZE * sizeof(region_data_item));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_region_data_item_array(region_data_item_array* array)
* \brief Reset the region_data_item array to hold nothing.
* \param array Pointer to the dynamic region_data_item array.
*/
void reset_region_data_item_array(region_data_item_array * array)
{
	(*array).size = 0;
}

/** \fn void free_region_data_item_array(region_data_item_array * array)
* \brief Free the memory of a dynamic region_data_item array.
* \param array Pointer to the dynamic region_data_item array.
*/
void free_region_data_item_array(region_data_item_array * array)
{
	free((*array).array);
}

void copy_region_data_item_array(region_data_item_array * from, region_data_item_array * to)
{
	int i;
	
	//to = init_region_data_item_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_region_data_item(to, (*from).array[i].cpi, (*from).array[i].cpi_last_month, (*from).array[i].gdp, (*from).array[i].output, (*from).array[i].employment, (*from).array[i].unemployment_rate, (*from).array[i].unemployment_rate_skill_1, (*from).array[i].unemployment_rate_skill_2, (*from).array[i].unemployment_rate_skill_3, (*from).array[i].unemployment_rate_skill_4, (*from).array[i].unemployment_rate_skill_5, (*from).array[i].average_wage, (*from).array[i].no_firms, (*from).array[i].no_firm_births, (*from).array[i].no_firm_deaths);
	}
}

/** \fn void add_region_data_item(region_data_item_array * array, double cpi, double cpi_last_month, double gdp, double output, int employment, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, int no_firms, int no_firm_births, int no_firm_deaths)
* \brief Add an region_data_item to the dynamic region_data_item array.
* \param array Pointer to the dynamic region_data_item array.
* \param new_int The region_data_item to add
*/
void add_region_data_item(region_data_item_array * array, double cpi, double cpi_last_month, double gdp, double output, int employment, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, int no_firms, int no_firm_births, int no_firm_deaths)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (region_data_item *)realloc((*array).array, ((*array).total_size * sizeof(region_data_item)));
	}
	init_region_data_item(&(*array).array[(*array).size]);
	(*array).array[(*array).size].cpi = cpi;
	(*array).array[(*array).size].cpi_last_month = cpi_last_month;
	(*array).array[(*array).size].gdp = gdp;
	(*array).array[(*array).size].output = output;
	(*array).array[(*array).size].employment = employment;
	(*array).array[(*array).size].unemployment_rate = unemployment_rate;
	(*array).array[(*array).size].unemployment_rate_skill_1 = unemployment_rate_skill_1;
	(*array).array[(*array).size].unemployment_rate_skill_2 = unemployment_rate_skill_2;
	(*array).array[(*array).size].unemployment_rate_skill_3 = unemployment_rate_skill_3;
	(*array).array[(*array).size].unemployment_rate_skill_4 = unemployment_rate_skill_4;
	(*array).array[(*array).size].unemployment_rate_skill_5 = unemployment_rate_skill_5;
	(*array).array[(*array).size].average_wage = average_wage;
	(*array).array[(*array).size].no_firms = no_firms;
	(*array).array[(*array).size].no_firm_births = no_firm_births;
	(*array).array[(*array).size].no_firm_deaths = no_firm_deaths;

	(*array).size++;
}

/** \fn void remove_region_data_item(region_data_item_array * array, int index)
 * \brief Remove an region_data_item from a dynamic region_data_item array.
 * \param array Pointer to the dynamic region_data_item array.
 * \param index The index of the region_data_item to remove.
 */
void remove_region_data_item(region_data_item_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_region_data_item(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_region_data_item(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the tax_rates_item datatype */
/** \fn tax_rates_item_array * init_tax_rates_item_array()
 * \brief Allocate memory for a dynamic tax_rates_item array.
 * \return tax_rates_item_array Pointer to the new dynamic tax_rates_item array.
 */
void init_tax_rates_item_array(tax_rates_item_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (tax_rates_item *)malloc(ARRAY_BLOCK_SIZE * sizeof(tax_rates_item));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_tax_rates_item_array(tax_rates_item_array* array)
* \brief Reset the tax_rates_item array to hold nothing.
* \param array Pointer to the dynamic tax_rates_item array.
*/
void reset_tax_rates_item_array(tax_rates_item_array * array)
{
	(*array).size = 0;
}

/** \fn void free_tax_rates_item_array(tax_rates_item_array * array)
* \brief Free the memory of a dynamic tax_rates_item array.
* \param array Pointer to the dynamic tax_rates_item array.
*/
void free_tax_rates_item_array(tax_rates_item_array * array)
{
	free((*array).array);
}

void copy_tax_rates_item_array(tax_rates_item_array * from, tax_rates_item_array * to)
{
	int i;
	
	//to = init_tax_rates_item_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_tax_rates_item(to, (*from).array[i].gov_id, (*from).array[i].tax_rate_corporate, (*from).array[i].tax_rate_hh_labour, (*from).array[i].tax_rate_hh_capital, (*from).array[i].tax_rate_vat);
	}
}

/** \fn void add_tax_rates_item(tax_rates_item_array * array, int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat)
* \brief Add an tax_rates_item to the dynamic tax_rates_item array.
* \param array Pointer to the dynamic tax_rates_item array.
* \param new_int The tax_rates_item to add
*/
void add_tax_rates_item(tax_rates_item_array * array, int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (tax_rates_item *)realloc((*array).array, ((*array).total_size * sizeof(tax_rates_item)));
	}
	init_tax_rates_item(&(*array).array[(*array).size]);
	(*array).array[(*array).size].gov_id = gov_id;
	(*array).array[(*array).size].tax_rate_corporate = tax_rate_corporate;
	(*array).array[(*array).size].tax_rate_hh_labour = tax_rate_hh_labour;
	(*array).array[(*array).size].tax_rate_hh_capital = tax_rate_hh_capital;
	(*array).array[(*array).size].tax_rate_vat = tax_rate_vat;

	(*array).size++;
}

/** \fn void remove_tax_rates_item(tax_rates_item_array * array, int index)
 * \brief Remove an tax_rates_item from a dynamic tax_rates_item array.
 * \param array Pointer to the dynamic tax_rates_item array.
 * \param index The index of the tax_rates_item to remove.
 */
void remove_tax_rates_item(tax_rates_item_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_tax_rates_item(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_tax_rates_item(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the history_item datatype */
/** \fn history_item_array * init_history_item_array()
 * \brief Allocate memory for a dynamic history_item array.
 * \return history_item_array Pointer to the new dynamic history_item array.
 */
void init_history_item_array(history_item_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (history_item *)malloc(ARRAY_BLOCK_SIZE * sizeof(history_item));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_history_item_array(history_item_array* array)
* \brief Reset the history_item array to hold nothing.
* \param array Pointer to the dynamic history_item array.
*/
void reset_history_item_array(history_item_array * array)
{
	(*array).size = 0;
}

/** \fn void free_history_item_array(history_item_array * array)
* \brief Free the memory of a dynamic history_item array.
* \param array Pointer to the dynamic history_item array.
*/
void free_history_item_array(history_item_array * array)
{
	free((*array).array);
}

void copy_history_item_array(history_item_array * from, history_item_array * to)
{
	int i;
	
	//to = init_history_item_array();
	
	for(i = 0; i < (*from).size; i++)
	{
		add_history_item(to, (*from).array[i].cpi, (*from).array[i].gdp, (*from).array[i].output, (*from).array[i].employment, (*from).array[i].unemployment_rate, (*from).array[i].unemployment_rate_skill_1, (*from).array[i].unemployment_rate_skill_2, (*from).array[i].unemployment_rate_skill_3, (*from).array[i].unemployment_rate_skill_4, (*from).array[i].unemployment_rate_skill_5, (*from).array[i].average_wage, (*from).array[i].no_firms, (*from).array[i].no_firm_births, (*from).array[i].no_firm_deaths, &(*from).array[i].region_data);
	}
}

/** \fn void add_history_item(history_item_array * array, double cpi, double gdp, double output, int employment, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, int no_firms, int no_firm_births, int no_firm_deaths, region_data_item_array * region_data)
* \brief Add an history_item to the dynamic history_item array.
* \param array Pointer to the dynamic history_item array.
* \param new_int The history_item to add
*/
void add_history_item(history_item_array * array, double cpi, double gdp, double output, int employment, double unemployment_rate, double unemployment_rate_skill_1, double unemployment_rate_skill_2, double unemployment_rate_skill_3, double unemployment_rate_skill_4, double unemployment_rate_skill_5, double average_wage, int no_firms, int no_firm_births, int no_firm_deaths, region_data_item_array * region_data)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (history_item *)realloc((*array).array, ((*array).total_size * sizeof(history_item)));
	}
	init_history_item(&(*array).array[(*array).size]);
	(*array).array[(*array).size].cpi = cpi;
	(*array).array[(*array).size].gdp = gdp;
	(*array).array[(*array).size].output = output;
	(*array).array[(*array).size].employment = employment;
	(*array).array[(*array).size].unemployment_rate = unemployment_rate;
	(*array).array[(*array).size].unemployment_rate_skill_1 = unemployment_rate_skill_1;
	(*array).array[(*array).size].unemployment_rate_skill_2 = unemployment_rate_skill_2;
	(*array).array[(*array).size].unemployment_rate_skill_3 = unemployment_rate_skill_3;
	(*array).array[(*array).size].unemployment_rate_skill_4 = unemployment_rate_skill_4;
	(*array).array[(*array).size].unemployment_rate_skill_5 = unemployment_rate_skill_5;
	(*array).array[(*array).size].average_wage = average_wage;
	(*array).array[(*array).size].no_firms = no_firms;
	(*array).array[(*array).size].no_firm_births = no_firm_births;
	(*array).array[(*array).size].no_firm_deaths = no_firm_deaths;
	if(region_data != NULL) copy_region_data_item_array(region_data, &(*array).array[(*array).size].region_data);

	(*array).size++;
}

/** \fn void remove_history_item(history_item_array * array, int index)
 * \brief Remove an history_item from a dynamic history_item array.
 * \param array Pointer to the dynamic history_item array.
 * \param index The index of the history_item to remove.
 */
void remove_history_item(history_item_array * array, int index)
{
	int i;
	
	/* Free element at index index */
	free_history_item(&(*array).array[index]);
	
	/* Copy all elements up by one */
	if(index <= (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_history_item(&(*array).array[i+1], &(*array).array[i]);
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
