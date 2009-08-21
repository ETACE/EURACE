    #include "../header.h"
    #include "../Bank_agent_header.h"
    #include "../my_library_header.h"
    
    
     int Bank_read_policy_rate()
    {
          START_POLICY_RATE_MESSAGE_LOOP
                ECB_INTEREST_RATE = policy_rate_message->policy_rate_value;      
          FINISH_POLICY_RATE_MESSAGE_LOOP
          
        DEPOSITS_RATE = 0.9 * ECB_INTEREST_RATE;
        
            if (PRINT_DEBUG)
     {
       printf("\n\n Bank_read_policy_rate ID: %d",ID); 
       printf("\n\t policy_rate_value: %f DEPOSITS_RATE: %f",ECB_INTEREST_RATE,DEPOSITS_RATE);
      
        getchar(); 
      }              
        
     return 0;   
    }
    
    int Bank_communicate_identity()
    {
        add_bank_identity_message(ID);
        
        if (PRINT_DEBUG)
        {
                        printf("\n Bank_communicate_identity ID: %d",ID);
                        getchar();
                        }      
        
     return 0;   
    }
        
    
    
    int Bank_decide_credit_conditions()
    {
        double e, c, d, r, i;
        double bankruptcy_prob;
        double credit_allowed;
            
         
        
                
            START_LOAN_REQUEST_MESSAGE_LOOP
                e = loan_request_message->equity;
                d = loan_request_message->total_debt;
                c = loan_request_message->external_financial_needs;
                bankruptcy_prob = 1-exp(-(d+c)/e);
                r = bankruptcy_prob*c/e;
        
                if ( VALUE_AT_RISK+r <= BANK_GAMMA[0]*ALFA*EQUITY )  //Instead of ALFA*EQUITY 
                {
                    credit_allowed = c;
                    if (credit_allowed<0)
                        printf("\n ERROR in function bank_decide_credit_condition: credit_allowed = %2.5f\n ", credit_allowed);
                }
                else 
                {
                    credit_allowed = max(0,(BANK_GAMMA[0]*ALFA*EQUITY - VALUE_AT_RISK)/bankruptcy_prob);  
                    if (credit_allowed<0)
                        printf("\n ERROR in function bank_decide_credit_condition: credit_allowed = %2.5f\n ", credit_allowed);                
                }
                i = ECB_INTEREST_RATE + BANK_GAMMA[0]*r*(((double)rand()/(double)RAND_MAX)*0.01);
                
                    add_loan_conditions_message(loan_request_message->firm_id, ID, i, credit_allowed,  r*(c/credit_allowed));
            FINISH_LOAN_REQUEST_MESSAGE_LOOP
            
            if (PRINT_DEBUG) 
            {
                             printf("\n Bank_decide_credit_conditions ID: %d",ID);
                             printf("\n\t credit_allowed: %f rate: %f",credit_allowed,r*(c/credit_allowed));
                             getchar();
                             }       
        
        return 0;
    }
    
    
    int Bank_account_update_deposits()
    {
          DEPOSITS=0; //reset total deposits        
            
          START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
          if (bank_account_update_message->bank_id==ID)
            {
             DEPOSITS += bank_account_update_message->payment_account; //new deposits as sum of all payments accounts 
            }
          FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
    
    //CASH += bank_account_update_message->payment_account;
    
      //Compute CASH
          CASH=DEPOSITS+ECB_DEBT+EQUITY-TOTAL_CREDIT;
    
       if (CASH<0)
            {
             ECB_DEBT+=-CASH; //Monetary base is increased     
             CASH=0;
             
             }
            
            
            
       // Procedure to reduce ECB debt
          if ( (ECB_DEBT != 0)&& (CASH>0) ) 
            {
                 if(CASH>=ECB_DEBT)
                 {
                     CASH-=ECB_DEBT;
                     ECB_DEBT=0.0;
                 }
     
                 if(CASH<ECB_DEBT)
                 {
                     ECB_DEBT-=CASH;
                     CASH=0.0;
                 }
             }
       //End of procedure
       
       add_bank_to_central_bank_account_update_message(ID, CASH, ECB_DEBT); 
                  
        return 0;
    }
    
    int Bank_receive_installment()
    {
        FIRM_LOAN_INSTALLMENTS=0.0;
        FIRM_INTEREST_PAYMENTS=0.0;
        
        if (PRINT_DEBUG) 
        {
                         printf("\n\n Bank_receive_installment ID: %d",ID);
                         printf("\n\t PROFITS: %f TOTAL_CREDIT: %f",PROFITS[0],TOTAL_CREDIT);
                         }
            
        START_INSTALLMENT_MESSAGE_LOOP
            if(installment_message->bank_id==ID)
            {
        
            //CASH +=installment_message->interest_amount;//installment_amount;   
            PROFITS[0] += installment_message->interest_amount;
            TOTAL_CREDIT-=installment_message->installment_amount;
            EQUITY += installment_message->interest_amount;
            VALUE_AT_RISK -= installment_message->var_per_installment;
            
            if (PRINT_DEBUG)
            {
                            printf("\n\t interest_amount: %f installment_amount: %f",installment_message->interest_amount,installment_message->installment_amount);
                            printf("\n\t PROFITS: %f TOTAL_CREDIT: %f EQUITY: %f",PROFITS[0],TOTAL_CREDIT,EQUITY);
                            getchar();
                            }
          
            //Flow accounting
            FIRM_INTEREST_PAYMENTS+= installment_message->interest_amount;
            FIRM_LOAN_INSTALLMENTS += installment_message->installment_amount;
            
            }
    
        FINISH_INSTALLMENT_MESSAGE_LOOP
    
        START_BANKRUPTCY_MESSAGE_LOOP
            if(bankruptcy_message->bank_id==ID)
            {
        
           //CASH +=bankruptcy_message->credit_refunded;
           EQUITY -= bankruptcy_message->bad_debt;
           TOTAL_CREDIT-=(bankruptcy_message->credit_refunded+bankruptcy_message->bad_debt);
           PROFITS[0] -= bankruptcy_message->bad_debt;
           VALUE_AT_RISK -= bankruptcy_message->residual_var;
           
           
           if (PRINT_DEBUG)
            {
                            printf("\n\t BANKRUPTCY_MESSAGE_LOOP");
                            printf("\n\t bad_debt: %f",bankruptcy_message->bad_debt);
                            printf("\n\t PROFITS: %f TOTAL_CREDIT: %f EQUITY: %f",PROFITS[0],TOTAL_CREDIT,EQUITY);
                            getchar();
                            }

           
            }
    
        FINISH_BANKRUPTCY_MESSAGE_LOOP   
        
          return 0;
    }
    
    int Bank_give_loan()
    {
        FIRM_LOAN_ISSUES=0.0;
        
      if (PRINT_DEBUG)
     {
       printf("\n\n Bank_give_loan ID: %d",ID); 
       printf("\n\t TOTAL_CREDIT: %f",TOTAL_CREDIT);
      }        
        
        
        START_LOAN_ACCEPTANCE_MESSAGE_LOOP
            if(loan_acceptance_message->bank_id==ID)
            {
                VALUE_AT_RISK+=loan_acceptance_message->loan_total_var;
                TOTAL_CREDIT+=loan_acceptance_message->credit_amount_taken;
                
                //Flow accounting 
                FIRM_LOAN_ISSUES+=loan_acceptance_message->credit_amount_taken;    
                if (PRINT_DEBUG) printf("\n\t credit_amount_taken: %f",loan_acceptance_message->credit_amount_taken);     
            }
    
        FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
        
    if (PRINT_DEBUG) printf("\n\t TOTAL_CREDIT: %f",TOTAL_CREDIT);
       
        
        return 0;
    }


    
    int Bank_accounting()
    {
    
         double q, c, gro, int_to_ecb;  // total_dividends, dividend_per_share
         
         ECB_INTEREST_PAYMENT=0.0;
         
         //Pay interests to ecb
         int_to_ecb=ECB_DEBT*ECB_INTEREST_RATE;
         PROFITS[0]-=int_to_ecb; 
         CASH-=int_to_ecb;
         EQUITY-=int_to_ecb;
         add_bank_interest_payment_message(int_to_ecb);
         
         //Flow accounting
         ECB_INTEREST_PAYMENT=int_to_ecb;
         
         if (PROFITS[1]!=0)
         {
            gro=( (PROFITS[0]-PROFITS[1])/PROFITS[1] );
         }
    
         else  
         gro=0;
     
         PROFITS[1]=PROFITS[0]; //update
         q=BANK_GAMMA[0]; 
         c=BANK_GAMMA[1];
         BANK_GAMMA[1]= q;
         BANK_GAMMA[0]=(q+(BANK_LAMBDA*(q-c)*gro)+(((double)rand()/(double)RAND_MAX)*0.01)); //Cambiare formula
     
         if (BANK_GAMMA[0]<0.02)
         {
             BANK_GAMMA[0]=0.02;
         }
    
         // tax and dividends payment
         if (PROFITS[0]>0)
         {
             TAXES = TAX_RATE_CORPORATE*PROFITS[0]; // We do not want bank to accumulate too much money...
             PROFITS[0] -= TAXES;
             EQUITY -= TAXES;  
             CASH -= TAXES; 
             add_tax_payment_message(GOV_ID, TAXES);  
             //total_dividends = BANK_DIVIDEND_RATE*PROFITS[0];     When Mario will...
             //dividend_per_share = total_dividends/NUMBER_OF_SHARES; 
             //EQUITY -= total_dividends;     
             //CASH -= total_dividends;      
             //add_dividend_per_share_message(ID, dividend_per_share);                  
         }
          
         if (EQUITY < 0.0) //... and if is negative (if money is not enough), increase ECB debt
         {
             printf("In function Bank_accounting: Bank %d has EQUITY<0, but we ignore this for now.\n", ID);
            // ECB_DEBT += fabs(EQUITY);
            // EQUITY = 0.0;
         }
        
      
         PROFITS[0]=0;  //update
         
        //at the end of the month, the bank changes its lending strategy, reducing or not its 
        
        
          return 0;
    }
    
    int Bank_idle()
    {
        return 0;
    }
    
    
int Bank_send_accountInterest(void)
{
   add_accountInterest_message(get_id(), DEPOSITS_RATE);
   
   if (PRINT_DEBUG)
   {
      printf("\n Bank_send_accountInterest ID: %d",ID);
      printf("\n\t DEPOSITS_RATE %f",DEPOSITS_RATE);
      getchar();
                   }
   
   return 0;
}
