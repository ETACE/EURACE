#include "../header.h"
#include "../Bank_agent_header.h"
#include "../my_library_header.h"

int Bank_read_policy_rate()
{
      START_POLICY_RATE_MESSAGE_LOOP
            ECB_INTEREST_RATE = policy_rate_message->policy_rate_value;      
      FINISH_POLICY_RATE_MESSAGE_LOOP
      
    DEPOSITS_RATE = 0.9 * ECB_INTEREST_RATE;

    #ifdef _DEBUG_MODE        
        if (PRINT_DEBUG)
        {
            printf("\n\n Bank_read_policy_rate ID: %d",ID); 
            printf("\n\t policy_rate_value: %f DEPOSITS_RATE: %f",ECB_INTEREST_RATE,DEPOSITS_RATE);
            
            getchar(); 
        }              
    #endif
        
     return 0;   
}

int Bank_communicate_identity()
{
    add_bank_identity_message(ID);

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG)
    {
        printf("\n Bank_communicate_identity ID: %d",ID);
        getchar();
    }      
    #endif
        
 return 0;   
}
    


int Bank_decide_credit_conditions()
{

    FILE *file1=NULL;
    char * filename="";
    double e, c, d, r, i;
    double bankruptcy_prob=0.0;
    double credit_allowed=0.0;
    e=0.0;
    c=0.0;
    d=0.0;
    r=0.0;
    i=0.0;
            
        START_LOAN_REQUEST_MESSAGE_LOOP
            e = loan_request_message->equity;
            d = loan_request_message->total_debt;
            c = loan_request_message->external_financial_needs;
            bankruptcy_prob = 1-exp(-(d+c)/e);
            r = bankruptcy_prob*c;
            
           if ( VALUE_AT_RISK+r <= ALFA*EQUITY )  //Instead of ALFA*EQUITY 
            {
                //printf("\n %f %f %f %f %f",VALUE_AT_RISK,r,BANK_GAMMA[0],ALFA,EQUITY);
                //getchar();
                CREDIT_RATIONING = max(0,CREDIT_RATIONING-1);
                credit_allowed = c;
                if (credit_allowed<0)
                    printf("\n ERROR in function bank_decide_credit_condition: credit_allowed = %2.5f\n ", credit_allowed);
            }
            else 
            {
                CREDIT_RATIONING = CREDIT_RATIONING+1; 
                credit_allowed = max(0,(ALFA*EQUITY - VALUE_AT_RISK)/bankruptcy_prob);  
                if (credit_allowed<0)
                    printf("\n ERROR in function bank_decide_credit_condition: credit_allowed = %2.5f\n ", credit_allowed);                
            }
            
            
          if (e<0)
          printf("\n Error ! The equity of the firm is negative: %f",e); 
           
          i = ECB_INTEREST_RATE + BANK_GAMMA[0]*bankruptcy_prob*(double)rand()/RAND_MAX;
            
        //    if (PRINT_DEBUG_FILE_EXP1)
        //{                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/bank_decide_credit_conditions.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %d",DAY,ID,loan_request_message->firm_id);
            fprintf(file1," %f %f %f %f %f %f %f %f",d,c,e,bankruptcy_prob,r,i,VALUE_AT_RISK,EQUITY);
            fprintf(file1," %f %d",credit_allowed,CREDIT_RATIONING);
            fclose(file1);
            free(filename); 
                    //}  
            
        
            add_loan_conditions_message(loan_request_message->firm_id, ID, i, credit_allowed,  r*(credit_allowed/c));
            
        
        #ifdef _DEBUG_MODE
            if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
            {
                printf("\n Bank_decide_credit_conditions bank_id: %d firm_id: %d",ID,loan_request_message->firm_id);
                printf("\n\t credit_allowed: %f credit_requested: %f",credit_allowed,c);
                printf("\n\t ECB_INTEREST_RATE: %f i: %f r*(c/credit_allowed): %f",ECB_INTEREST_RATE,i,r*(c/credit_allowed));
                getchar();
            }  
        #endif              
         
            
        FINISH_LOAN_REQUEST_MESSAGE_LOOP
    
    return 0;
}


int Bank_account_update_deposits()
{
  
      DEPOSITS=0.0; //reset total deposits        
        
      START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP 
      if (bank_account_update_message->bank_id==ID)
        {
         DEPOSITS += bank_account_update_message->payment_account; //new deposits as sum of all payments accounts 
        }
      FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP



  //Compute CASH
      CASH = EQUITY+DEPOSITS+ECB_DEBT-TOTAL_CREDIT;

   if (CASH<0)
        {
         ECB_DEBT+=-CASH; //Monetary base is increased     
         CASH=0.0;
         
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
         
    ECB_DEBT_CUM_MONTHLY  =  ECB_DEBT_CUM_MONTHLY  +  ECB_DEBT;       
   //End of procedure

    #ifdef _DEBUG_MODE   
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\n Bank_account_update_deposits ID: %d",ID);
        printf("\n\t ECB_DEBT: %f DEPOSITS: %f EQUITY: %f",ECB_DEBT,DEPOSITS,EQUITY);
        printf("\n\t TOTAL_CREDIT: %f CASH: %f",TOTAL_CREDIT,CASH);
        getchar();
    }
    #endif   
             
    return 0;
}


int Bank_receive_installment()
{
    FIRM_LOAN_INSTALLMENTS=0.0;

    #ifdef _DEBUG_MODE     
    if (PRINT_DEBUG) 
    {
        printf("\n\n Bank_receive_installment ID: %d",ID);
        printf("\n\t PROFITS: %f TOTAL_CREDIT: %f",PROFITS[0],TOTAL_CREDIT);
    }
    #endif
        
    START_INSTALLMENT_MESSAGE_LOOP
        if(installment_message->bank_id==ID)
        {
            TOTAL_CREDIT-=installment_message->installment_amount;
            EQUITY += installment_message->interest_amount;
            PROFITS[0] += installment_message->interest_amount;
            VALUE_AT_RISK -= installment_message->var_per_installment;

            //Flow accounting
            FIRM_INTEREST_PAYMENTS += installment_message->interest_amount;
            FIRM_LOAN_INSTALLMENTS += installment_message->installment_amount;
        }
    FINISH_INSTALLMENT_MESSAGE_LOOP

    START_BANKRUPTCY_MESSAGE_LOOP
    if(bankruptcy_message->bank_id==ID)
    {
    
       TOTAL_CREDIT-= bankruptcy_message->bad_debt;
       EQUITY-= bankruptcy_message->bad_debt;
       VALUE_AT_RISK -= bankruptcy_message->residual_var;
       
    }
    FINISH_BANKRUPTCY_MESSAGE_LOOP   
    
      return 0;
}


int Bank_give_loan()
{
    FILE *file1=NULL;
    char * filename="";

    FIRM_LOAN_ISSUES=0.0;

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\n Bank_give_loan ID: %d",ID); 
        printf("\n\t TOTAL_CREDIT before: %f",TOTAL_CREDIT);
    }        
    #endif
            
    START_LOAN_ACCEPTANCE_MESSAGE_LOOP
        if(loan_acceptance_message->bank_id==ID)
        {
            VALUE_AT_RISK+=loan_acceptance_message->loan_total_var;
            TOTAL_CREDIT+=loan_acceptance_message->credit_amount_taken;
            
            //Flow accounting 
            FIRM_LOAN_ISSUES+=loan_acceptance_message->credit_amount_taken;    

            #ifdef _DEBUG_MODE
                if (PRINT_DEBUG) printf("\n\t credit_amount_taken: %f",loan_acceptance_message->credit_amount_taken);     
            #endif
            
            //  #ifdef _DEBUG_MODE        
     
      //  #endif
      
              //    if (PRINT_DEBUG_FILE_EXP1)
        //{                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/bank_give_loan.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f",DAY,ID,loan_acceptance_message->credit_amount_taken);
            fprintf(file1," %f %f %f",TOTAL_CREDIT,loan_acceptance_message->loan_total_var,VALUE_AT_RISK);
            fclose(file1);
            free(filename); 
        //}  

            
        }

    FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP

    #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_EXP1 || PRINT_DEBUG) printf("\n\t TOTAL_CREDIT after: %f",TOTAL_CREDIT);
    #endif
    
    return 0;
}



int Bank_accounting()
{
   // The function is activated according to a monthly periodicity at the end of the state_graph 

        FILE *file1=NULL;
        char *filename="";
         
     //double q, c
     double gro, int_to_ecb;  // total_dividends, dividend_per_share
     
     ECB_INTEREST_PAYMENT=0.0;
     
     //Pay interests to ecb
     int_to_ecb=ECB_DEBT_CUM_MONTHLY*ECB_INTEREST_RATE/(12*DAYS_PER_MONTH);
     ECB_DEBT_CUM_MONTHLY  = 0.0;
     PROFITS[0]-=int_to_ecb; 
     add_bank_interest_payment_message(int_to_ecb);
     CASH-=int_to_ecb;
     EQUITY-=int_to_ecb;
     
     //Flow accounting
     ECB_INTEREST_PAYMENT=int_to_ecb;
     
     if (PROFITS[1]!=0)
     {
        gro=( (PROFITS[0]-PROFITS[1])/PROFITS[1] );
     }

     else  
     gro=0;
 
     PROFITS[1]=PROFITS[0]; //update
     
     /* q=BANK_GAMMA[0]; 
     c=BANK_GAMMA[1];
     BANK_GAMMA[1]= q;
     BANK_GAMMA[0]=(q+(BANK_LAMBDA*(q-c)*gro)+(((double)rand()/(double)RAND_MAX)*0.01)); //Cambiare formula
 
     if (BANK_GAMMA[0]<0.02)
     {
         BANK_GAMMA[0]=0.02;
     }
     */
     BANK_GAMMA[0] = 0.05;
     if (((EQUITY*ALFA)<(1.1*VALUE_AT_RISK))||(CREDIT_RATIONING>0))
     BANK_DIVIDEND_RATE = 0.0;
     else
     BANK_DIVIDEND_RATE = 1.0;
     
     CREDIT_RATIONING = 0;

     // tax and dividends payment
     if (PROFITS[0]>0)
     {
         TAXES = TAX_RATE_CORPORATE*PROFITS[0]; // We do not want bank to accumulate too much money...
         PROFITS[0] -= TAXES;
         add_tax_payment_message(GOV_ID, TAXES); 
         CASH -= TAXES; 
         EQUITY-=TAXES;
     
         TOTAL_DIVIDENDS = BANK_DIVIDEND_RATE*PROFITS[0];
         DIVIDEND_PER_SHARE = TOTAL_DIVIDENDS/CURRENT_SHARES_OUTSTANDING; 
         
          if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/banks_tax_payments.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f %f",DAY,ID,PROFITS[0],TAX_RATE_CORPORATE,TAXES);
            fclose(file1);
            free(filename);
        }  
         
         //The dividend msg is send in the function Bank_send_dividend_payment (see below)      
         //add_dividend_per_share_message(ID, DIVIDEND_PER_SHARE);                  
     }
      
    #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
        {
            printf("\n\n Bank_accounting ID: %d",ID);
            printf("\n\t ECB_DEBT: %f int_to_ecb: %f",ECB_DEBT,int_to_ecb);
            printf("\n\t PROFITS[0]: %f EQUITY: %f",PROFITS[0],EQUITY);
            printf("\n\t CASH: %f TOTAL_DIVIDENDS: %f",CASH,TOTAL_DIVIDENDS);
        } 
    #endif
    
   // #ifdef _DEBUG_MODE                         
   // if (PRINT_DEBUG_FILE_EXP1)
   // {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/banks_monthly_income_statement.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d",DAY,ID);
        fprintf(file1," %f %f %f %f %f %d",ECB_INTEREST_PAYMENT,FIRM_INTEREST_PAYMENTS,TAXES,PROFITS[0],TOTAL_DIVIDENDS,REGION_ID);
        fclose(file1);
        free(filename);
    //}                
   // #endif

    // #ifdef _DEBUG_MODE                         
    if (PRINT_DEBUG_FILE_EXP1)
    {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/banks_monthly_balance_sheet.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f %f %f %d",DAY,ID,DEPOSITS,ECB_DEBT,CASH,TOTAL_CREDIT,REGION_ID);
        fclose(file1);
        free(filename);
    }                
   // #endif

          
     if (EQUITY < 0.0) //... and if is negative (if money is not enough), increase ECB debt
     {
         printf("In function Bank_accounting: Bank %d has EQUITY<0, but we ignore this for now.\n", ID);
        // ECB_DEBT += fabs(EQUITY);
        // EQUITY = 0.0;
     }
    
  
     PROFITS[0]=0.0;  //update
     FIRM_INTEREST_PAYMENTS = 0.0;
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

    #ifdef _DEBUG_MODE   
    if (PRINT_DEBUG)
    {
        printf("\n Bank_send_accountInterest ID: %d",ID);
        printf("\n\t DEPOSITS_RATE %f",DEPOSITS_RATE);
        getchar();
    }
    #endif
    
   return 0;
}

int Bank_send_dividend_payment()
{
    // The function is activated according to a monthly periodicity at the beginning of the state_graph
    add_dividend_per_share_message(ID, DIVIDEND_PER_SHARE);
    EQUITY -=  TOTAL_DIVIDENDS;     
    CASH -=  TOTAL_DIVIDENDS;

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG)
    {
      printf("\n Bank_send_dividend_payment ID: %d",ID);
      printf("\n\t DIVIDEND_PER_SHARE %f",DIVIDEND_PER_SHARE);
      getchar();
    }
    #endif
    
   return 0;
}

int Bank_set_quantities_zero()
{
    DIVIDEND_PER_SHARE=0.0;
    TOTAL_DIVIDENDS=0.0;
    TAXES=0.0;

    return 0;
}

int Bank_update_ecb_account()
{   
     //  #ifdef _DEBUG_MODE  
        FILE *file1=NULL;
        char * filename="";
  //  #endif

   add_bank_to_central_bank_account_update_message(ID, CASH, ECB_DEBT); 
   
      // #ifdef _DEBUG_MODE                         
   // if (PRINT_DEBUG_FILE_EXP1)
   // {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/banks_daily_balance_sheet.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f",DAY,ID,FIRM_LOAN_ISSUES,FIRM_LOAN_INSTALLMENTS);
        fprintf(file1," %f %f %f %f %f %d",TOTAL_CREDIT,CASH,DEPOSITS,ECB_DEBT,EQUITY,REGION_ID);
        fclose(file1);
        free(filename);
        
    //}    
    
   // if (PRINT_DEBUG_FILE_EXP1)
   // {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/banks_value_at_risk.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %d",DAY,ID,VALUE_AT_RISK,REGION_ID);
        fclose(file1);
        free(filename);
        
    //}                 
   // #endif

    return 0;
}
