    #include "../header.h"
    #include "../Firm_agent_header.h"
    #include "../my_library_header.h"
    
    
    int Firm_ask_loan()
    {
        if (EXTERNAL_FINANCIAL_NEEDS>0.0)
        {
          int connected, j;
         
         //Delete the old set of lenders
         for(j=NUMBER_OF_BANKS_ASKED-1;j>-1;j--)
         {
           remove_potential_lender(&SET_OF_LENDERS,j);         
         }
    
         NUMBER_OF_BANKS_ASKED=0;
         
        //Search for active banks' name
         START_BANK_IDENTITY_MESSAGE_LOOP
         
                 add_potential_lender(&SET_OF_LENDERS,bank_identity_message->bank_id,0);
                 NUMBER_OF_BANKS_ASKED++;
         
         FINISH_BANK_IDENTITY_MESSAGE_LOOP
    
         
          
         connected=0; 
        
        
        //Create bank network for this firm
          while(connected<NUMBER_OF_BANKS_TO_APPLY)
          {
                j= rand() % NUMBER_OF_BANKS_ASKED ;// choose banks
                add_loan_request_message(ID, SET_OF_LENDERS.array[j].bank_name, EQUITY, TOTAL_DEBT, EXTERNAL_FINANCIAL_NEEDS);
                SET_OF_LENDERS.array[j].contacted=1;
                connected++;         
          }
          
          //delete from the list not contacted banks
          for(j=NUMBER_OF_BANKS_ASKED-1;j>-1;j--)
         {
           if (SET_OF_LENDERS.array[j].contacted==0)
           {
             remove_potential_lender(&SET_OF_LENDERS,j);    
           }     
         }
        }
                
        NUMBER_OF_BANKS_ASKED=SET_OF_LENDERS.size;  //provvisorio
       
        return 0;
    }
    
    
    int Firm_get_loan()
    {
        int n, n1, k, i, primo;
        int bk = -1;
    
        int rate_order_array[NUMBER_OF_BANKS_ASKED]; //constant size dynamic array: name of banks
        double interest_array[NUMBER_OF_BANKS_ASKED]; //constant size dynamic array
        double credit_offer_array[NUMBER_OF_BANKS_ASKED]; //constant size dynamic array
        double value_at_risk_array[NUMBER_OF_BANKS_ASKED]; //constant size dynamic array
        
        
        double aux;
        double credit_demand;
        double credit_accepted;
        double total_credit_taken=0;
    
        int bank_id;
        double loan_value;
        double interest_rate;
        double interest_amount;
        double installment_amount;
        double var_per_installment;
        double residual_var;
        double bad_debt;
        int nr_periods_before_repayment;
        
         
        for (i=0; i<NUMBER_OF_BANKS_ASKED;i++)
        {
            rate_order_array[i]=-1;   //vettore lunghezza number_of_banks
            interest_array[i]=0.0;
            credit_offer_array[i]=0.0; //constant size static array
            value_at_risk_array[i]=0.0; 
        } 
    
        //Read messages from banks
        n=0;
    
        START_LOAN_CONDITIONS_MESSAGE_LOOP
          if (loan_conditions_message->firm_id==ID)
          {
                    
            interest_array[n] = loan_conditions_message->proposed_interest_rate;   
            credit_offer_array[n] = loan_conditions_message->amount_offered_credit;
            rate_order_array[n] = loan_conditions_message->bank_id;
            value_at_risk_array[n] = loan_conditions_message->value_at_risk;
        
            n += 1;
        
          }
                 
        FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
        
           
        //Sorting of the rate_order_array
        n1=0;
        
        //SORTING the set of  lenders according to their interest rates
        for(i=0;i<NUMBER_OF_BANKS_ASKED-1;i++)
        {
                for(k=i+1; k<NUMBER_OF_BANKS_ASKED; k++)
                {       
                    if (interest_array[i]>interest_array[k]) 
                    {
                     aux=interest_array[i];
                     interest_array[i]=interest_array[k];
                     interest_array[k]=aux;
                     
                     aux=credit_offer_array[i];
                     credit_offer_array[i]=credit_offer_array[k];
                     credit_offer_array[k]=aux;
                     
                     aux=value_at_risk_array[i];
                     value_at_risk_array[i]=value_at_risk_array[k];
                     value_at_risk_array[k]=aux;
                     
                     n1=rate_order_array[i];
                     rate_order_array[i]=rate_order_array[k];
                     rate_order_array[k]=n1;
                     
                    }
                    
                }
        }
        
        //Travers the banks according to the order in the rate_order_array,
        //obtain a loan if credit_demand >= credit_offer
        
                
        for(primo=0; primo<NUMBER_OF_BANKS_ASKED; primo++)
        {
                  
            if (rate_order_array[primo]!=-1)// && interest_array[primo]!=0.0)
             {
             
                credit_demand = EXTERNAL_FINANCIAL_NEEDS - total_credit_taken;
    
                if (credit_demand < 0.0)
                    printf("\n ERROR in function Firm_get_loan, line 132: credit_demand is NEGATIVE.\n ");
        
                if (credit_demand >= credit_offer_array[primo])
                {
                   credit_accepted = credit_offer_array[primo];
                }
                else
                {
                   credit_accepted=credit_demand;
                }
                
                
                total_credit_taken += credit_accepted;                  
                bank_id = rate_order_array[primo];
                loan_value = credit_accepted;
                interest_rate = interest_array[primo];
                installment_amount = credit_accepted/CONST_INSTALLMENT_PERIODS;
                interest_amount=interest_rate*installment_amount;
                    
                if (credit_accepted>0.0)
                {
                    var_per_installment = value_at_risk_array[primo]*
                        (credit_offer_array[primo]/credit_accepted); //RESIDUAL_VAR[rate_order_array[primo]].value[CONST_INSTALLMENT_PERIODS-1]/CONST_INSTALLMENT_PERIODS; //rate_order_array[primo]][CONST_INSTALLMENT_PERIODS-1]/CONST_INSTALLMENT_PERIODS;
                }
                else var_per_installment=0.0;
                
                residual_var = var_per_installment*CONST_INSTALLMENT_PERIODS;// value_at_risk_array[rate_order_array[primo]]*(credit_offer_array[rate_order_array[primo]]/credit_accepted);
                bad_debt = 0.0;
                nr_periods_before_repayment=CONST_INSTALLMENT_PERIODS+1;
                
                //ADD LOAN
                if(loan_value < 0.0)
                    printf("\n ERROR in function Firm_get_loan: loan_value is NEGATIVE.\n ");
    
             
             if (credit_accepted>0.0)
             {
                add_debt_item(&LOANS, bank_id, loan_value, interest_rate, installment_amount, var_per_installment, residual_var, bad_debt, nr_periods_before_repayment);         
                add_loan_acceptance_message(bank_id, credit_accepted, residual_var);     
             }
                //update the payment_account with the amount of credit obtained
                PAYMENT_ACCOUNT += credit_accepted;
        
          }
        }
        
        if (PAYMENT_ACCOUNT >= TOTAL_FINANCIAL_NEEDS)
            {           
                //printf("Firm_financial_needs, External financing: case 1.");
                EXTERNAL_FINANCIAL_NEEDS = 0.0;                   
            }
            else
            {
                //external financing needed
                EXTERNAL_FINANCIAL_NEEDS = TOTAL_FINANCIAL_NEEDS - PAYMENT_ACCOUNT;
            }
        
        
        return 0;
    }
    
    int Firm_idle()
    {
        return 0;
    }
    
