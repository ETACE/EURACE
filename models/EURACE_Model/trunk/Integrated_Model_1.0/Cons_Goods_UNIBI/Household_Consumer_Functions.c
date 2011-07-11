#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"
#include "../FINANCIAL_UG/my_library_header.h"




/********************************* Household agent functions *************************************/



/**********************************Household Role: Consumption Goods Market*********************/


/*\fn Household_determine_consumption_budget()
 * brief: If a household is unemployed then it receives an unemployment benefit payment
 * 
 */
int Household_determine_consumption_budget()
{

  
        char * filename="";
        FILE * file1=NULL;
        FILE * file2=NULL;

    if (PRINT_LOG)
    {
        //Start an empty string for the filename
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        
        //Concatenate
        strcpy(filename, "debug_payment_account.txt");

        //Open a file pointer: FILE * file 
        file1 = fopen(filename,"a");
        
        strcpy(filename, "debug_consumption_budget.txt");
        file2 = fopen(filename,"a");
    }
    //#endif
        
    /*Determining the consumption budget of the month*/
            //Previous rule based Deaton rule: uses PAYMENT_ACCOUNT
            /*if(PAYMENT_ACCOUNT > (INITIAL_CONSUMPTION_PROPENSITY*MEAN_INCOME))
            {
                
                CONSUMPTION_BUDGET=CONSUMPTION_PROPENSITY*PAYMENT_ACCOUNT+(1-CONSUMPTION_PROPENSITY)
                *INITIAL_CONSUMPTION_PROPENSITY*MEAN_INCOME;
            }
            else
            {
                CONSUMPTION_BUDGET = PAYMENT_ACCOUNT;
            }*/

        /*Compute the wealth income ratio*/
        
        /* WEALTH_INCOME_RATIO_ACTUAL = WEALTH/ MEAN_NET_INCOME;
            //Based on Carrol-Rule: Determination of the consumption budget
            CONSUMPTION_BUDGET = MEAN_NET_INCOME + CARROL_CONSUMPTION_PARAMETER*(WEALTH - WEALTH_INCOME_RATIO_TARGET*MEAN_NET_INCOME);
       #ifdef _DEBUG_MODE        
            if(PAYMENT_ACCOUNT < 0)
            {
                if (PRINT_LOG)
                    fprintf(file1, "IT %d ID %d PAYMENT_ACCOUNT %f \n", DAY, ID, PAYMENT_ACCOUNT);
    
                if (PRINT_DEBUG_CONSUMPTION)
                    printf("In Household_determine_consumption_budget, line 57: IT %d ID %d PAYMENT_ACCOUNT %f CONSUMPTION_BUDGET %f\n", DAY, ID, PAYMENT_ACCOUNT, CONSUMPTION_BUDGET);
            }
        #endif            
            if(CONSUMPTION_BUDGET < 0.5*LAST_NET_INCOME.array[3])
            {
                #ifdef _DEBUG_MODE        
                if(CONSUMPTION_BUDGET < 0)
                {
                    //printf("___________In file Household_Consumer_Functions.c, function Household_determine_consumption_budget, line 65:\n"
                    //"Household payment_account<0\n");
                    
                    if (PRINT_LOG)
                        fprintf(file2,"IT %d ID %d CONSUMPTION_BUDGET %f\n",DAY,ID,CONSUMPTION_BUDGET);
                }
                #endif
                
                CONSUMPTION_BUDGET = 0.5*LAST_NET_INCOME.array[3];
            }
            CONSUMPTION_BUDGET = max(0.0,min(WEALTH,CONSUMPTION_BUDGET));             
            */

           if (PAYMENT_ACCOUNT>0.0)
          {      
                 WEALTH_INCOME_RATIO_ACTUAL = PAYMENT_ACCOUNT / MEAN_NET_INCOME;
                 CONSUMPTION_BUDGET = MEAN_NET_INCOME + CARROL_CONSUMPTION_PARAMETER*(PAYMENT_ACCOUNT - WEALTH_INCOME_RATIO_TARGET*MEAN_NET_INCOME);
                 CONSUMPTION_BUDGET = max(CONSUMPTION_BUDGET,0.5*LAST_NET_INCOME.array[0]);
                 }
                 else  {WEALTH_INCOME_RATIO_ACTUAL = 0.0;
                       CONSUMPTION_BUDGET = 0.5*LAST_NET_INCOME.array[0];};                         




            CONSUMPTION_BUDGET_IN_MONTH = CONSUMPTION_BUDGET;
                        
            
            //PORTFOLIO_BUDGET=PAYMENT_ACCOUNT-CONSUMPTION_BUDGET;
            WEEKLY_BUDGET = CONSUMPTION_BUDGET/4;
            WEEK_OF_MONTH = 4;
            
        EXCESS_WEEKLY_BUDGET = -1;

  if ((ID>=101)&&(ID<=120))
   {
   if (PRINT_DEBUG_FILE_EXP2)
    {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/households_consumption_budget.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d",DAY,ID);
        if (EMPLOYEE_FIRM_ID==-1) fprintf(file1," %d %f",EMPLOYEE_FIRM_ID,UNEMPLOYMENT_BENEFIT_PCT * LAST_LABOUR_INCOME);
         else fprintf(file1," %d %f",EMPLOYEE_FIRM_ID,WAGE);
        fprintf(file1," %f %f",PAYMENT_ACCOUNT,WEALTH);
        fprintf(file1," %f %f %f",CUM_TOTAL_DIVIDENDS,MONTHLY_BOND_INTEREST_INCOME,CONSUMPTION_BUDGET);
         fprintf(file1," %f %f",MEAN_NET_INCOME,LAST_NET_INCOME.array[0]);
         fprintf(file1," %f (%f)",WEALTH_INCOME_RATIO_ACTUAL,WEALTH_INCOME_RATIO_TARGET);
        fclose(file1);
        free(filename);
    }                
}
    
    CUM_TOTAL_DIVIDENDS=0.0;
    
    return 0;   
}


/** \fn Household_shifting_consumption_day())
 * \brief If the payment account does not cover the planned consumption expenditures in that week,
 * the day of consumption is shifted by one day.       
 */
int Household_shifting_consumption_day()
{
    
    //if(FLAG_CONSUMPTION_SHIFTING==1)
    //{
        //printf("Error in Function Household_shifting_consumption_day\n\n"
          //      "Household %d wants to shift the consumption day a 2nd time, but had already shifted it; the payment_account is still smaller than the weekly_budget! \n",ID);
        //printf("Payment_account=%2.11f weekly_budget=%2.11f\n\n", PAYMENT_ACCOUNT, WEEKLY_BUDGET);
    //}
    //if(PRINT_DEBUG==0)
        //assert(FLAG_CONSUMPTION_SHIFTING==0);
    
    // FLAG_CONSUMPTION_SHIFTING =1;
    // DAY_OF_WEEK_TO_ACT = (DAY_OF_WEEK_TO_ACT+1)%5;

    
   // printf("Household %d shifts the consumption day \n",ID);
    
    return 0;
}


/** \fn Household_back_shifting_consumption_day()
 * \brief When the consumption has been shifted it has to be set back to the normal value.       
 */
int Household_back_shifting_consumption_day()
{
    /*
    assert(FLAG_CONSUMPTION_SHIFTING==1);
    
    DAY_OF_WEEK_TO_ACT = (DAY_OF_WEEK_TO_ACT-1)%5;
    FLAG_CONSUMPTION_SHIFTING =0;
    
    printf("Household %d shifts the consumption day back.\n",ID);
    */
    return 0;
}




/** \fn Household_rank_and_buy_goods_1()
 * \brief Household receives information about the offered range of goods in the malls.
 *  Depending on these infos the household sends its good request       
 */
int Household_rank_and_buy_goods_1()
{
    
    //Logit model parameter:
    double sum_weighted_qual_pric_ratios = 0; 
    int j=0;
    int i=0;
    double logit;

    logit_firm_id_array  logit_firm_id_list;
    init_logit_firm_id_array(&logit_firm_id_list);

    mall_quality_price_info_array mall_quality_price_info_list;
    init_mall_quality_price_info_array(&mall_quality_price_info_list);

 

        /*Household reads quality price info mesasges sent by malls   */
        START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP

    if( quality_price_info_1_message->available==1)
             {   
        add_mall_quality_price_info(&mall_quality_price_info_list,  quality_price_info_1_message->mall_id, quality_price_info_1_message->firm_id,               quality_price_info_1_message->mall_region_id,                   quality_price_info_1_message->quality,                  quality_price_info_1_message->price, 
        quality_price_info_1_message->available);
    }
             

        FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP

        
        //+++++ Logit Model +++++++++:

        
        /*Sum of weighted exponents of quality price ratios*/
        for(i = 0; i < mall_quality_price_info_list.size;i++) 
        {
            sum_weighted_qual_pric_ratios += (mall_quality_price_info_list.array[i]
            .available) * exp(log(mall_quality_price_info_list.array[i].price)*GAMMA_CONST); 


    
        }

        /* Compute logits and add on temporary logit array   */
        for(i = 0; i < mall_quality_price_info_list.size;i++) 
        {
            logit = (mall_quality_price_info_list.array[i].available) * 
            exp(log(mall_quality_price_info_list.array[i].price)*GAMMA_CONST) / 
            sum_weighted_qual_pric_ratios;
            
            logit = logit * 100;

            if(logit > 0)
            {
                add_logit_firm_id(&logit_firm_id_list, logit, 
                mall_quality_price_info_list.array[i].firm_id);
            }

        }

        if(sum_weighted_qual_pric_ratios > 0)
        {
            MALL_COMPLETELY_SOLD_OUT = 0;
            int random_number = random_int(0,100);
            j=0;
            int x =0, index_selected_good=j;

            for(j = 0; j < logit_firm_id_list.size;j++)
            {
            
                /*if randum number <= logit then select the corresponding good  */ 
                if((random_number < logit_firm_id_list.array[j].logit) && (x != 1))
                {
                    ORDER_QUANTITY[0].firm_id = logit_firm_id_list.
                    array[j].firm_id;
                
                    x = 1;
                    index_selected_good= j;
                }
                /*else sum logits and go to the next iteration step  */
                else
                {
                    if((j < logit_firm_id_list.size-1) )
                    {   
                        logit_firm_id_list.array[j+1].logit =
                        logit_firm_id_list.array[j+1].logit+
                        logit_firm_id_list.array[j].logit;
                    }
                }
            }

            /*This computes and stores the order quantity of the selected good and saves the price in memory */
            ORDER_QUANTITY[0].quantity = WEEKLY_BUDGET/ mall_quality_price_info_list
            .array[index_selected_good].price;
        
            ORDER_QUANTITY[0].price = mall_quality_price_info_list.
            array[index_selected_good].price;

            /*The consumption request message is sent  */ 
            add_consumption_request_1_message(
            mall_quality_price_info_list.array[index_selected_good].mall_id,ID,REGION_ID,
            ORDER_QUANTITY[0].firm_id,
            ORDER_QUANTITY[0].quantity);

        }
        else
        {
            EXPENDITURES=0;
            MALL_COMPLETELY_SOLD_OUT =1;
            ORDER_QUANTITY[0].quantity=0;
            ORDER_QUANTITY[0].price=0;
            ORDER_QUANTITY[0].firm_id=0;
        }

    free_mall_quality_price_info_array(&mall_quality_price_info_list);
    free_logit_firm_id_array(&logit_firm_id_list);

    return 0;

}

/** \fn Household_read_rationing()
 * \brief The household gets information about the accepted amount of goods and,
 * if the mall is completely sold out then the households set the order and delivery volumes
 * from the second step equal 0          
 */
int Household_receive_goods_read_rationing()
{
    if(MALL_COMPLETELY_SOLD_OUT == 0)
    {
        EXPENDITURES = 0;

        /*Household reads messages containing the realized consumption of the first round*/
        START_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP

                RATIONED = accepted_consumption_1_message->rationed;

                /*Update of Budget  */
                WEEKLY_BUDGET = WEEKLY_BUDGET - accepted_consumption_1_message
                ->offered_consumption_volume * ORDER_QUANTITY[0].price;
                
                EXPENDITURES =accepted_consumption_1_message
                ->offered_consumption_volume * ORDER_QUANTITY[0].price;
             
                RECEIVED_QUANTITY[0].quantity = accepted_consumption_1_message
                ->offered_consumption_volume;

                RECEIVED_QUANTITY[0].firm_id = ORDER_QUANTITY[0].firm_id;

        FINISH_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP
    }
    else if(MALL_COMPLETELY_SOLD_OUT == 1)
    {
        EXPENDITURES= 0;
        RECEIVED_QUANTITY[0].quantity = 0;
        RECEIVED_QUANTITY[0].firm_id = 0;
        ORDER_QUANTITY[1].quantity = 0;
        ORDER_QUANTITY[1].firm_id = 0;
        ORDER_QUANTITY[1].price = 0;
        RECEIVED_QUANTITY[1].quantity = 0;
        RECEIVED_QUANTITY[1].firm_id = 0;
        
    }    
    
    //Reset on first day of calendar month
    if (DAY%20==1)
        MONTHLY_CONSUMPTION_EXPENDITURE = 0.0;
    
    MONTHLY_CONSUMPTION_EXPENDITURE += EXPENDITURES;
    
    if ((ID>21)&&(ID<=22))
   { 
    if (PRINT_DEBUG_FILE_EXP2)
    {                       
       char * filename;
       FILE * file1;
       filename = malloc(40*sizeof(char));
       filename[0]=0;
       strcpy(filename, "its/households_receive_goods.txt");      
       file1 = fopen(filename,"a");
       fprintf(file1,"\n %d %d %f %f",DAY,ID,RECEIVED_QUANTITY[0].quantity,ORDER_QUANTITY[0].price);
       fprintf(file1," %f %f %f",WEEKLY_BUDGET,EXPENDITURES,MONTHLY_CONSUMPTION_EXPENDITURE);
       fclose(file1);
       free(filename);
    }              
 } 
    
    

    return 0;
}


int Household_set_values_zero()
{
        ORDER_QUANTITY[1].quantity = 0;
        ORDER_QUANTITY[1].firm_id = 0;
        ORDER_QUANTITY[1].price = 0;
        RECEIVED_QUANTITY[1].quantity = 0;
        RECEIVED_QUANTITY[1].firm_id = 0;

    return 0;
}

/*If rationed repeat ranking and request of goods: */
int Household_rank_and_buy_goods_2()    
{
            int j = 0;
            int i = 0;
            double logit;
            double sum_weighted_qual_pric_ratios = 0; 

            //Temporary arrays
            logit_firm_id_array logit_firm_id_list;
            init_logit_firm_id_array(&logit_firm_id_list);

            mall_quality_price_info_array mall_quality_price_info_list;
            init_mall_quality_price_info_array(&mall_quality_price_info_list);

        /*The updated quality price message is read  */
        START_QUALITY_PRICE_INFO_2_MESSAGE_LOOP

        if( quality_price_info_2_message->available==1)
        {
                add_mall_quality_price_info(&mall_quality_price_info_list,quality_price_info_2_message->mall_id, 
                quality_price_info_2_message->firm_id, 
                quality_price_info_2_message->mall_region_id, 
                quality_price_info_2_message->quality, 
                quality_price_info_2_message->price, 
                quality_price_info_2_message->available);
        }          
        FINISH_QUALITY_PRICE_INFO_2_MESSAGE_LOOP



        //+++++ Logit Model +++++++++:

        /*Sum of weighted exponents of quality price ratios   */
        for(i = 0;i < mall_quality_price_info_list.size; i++) 
        {
            sum_weighted_qual_pric_ratios +=(mall_quality_price_info_list
            .array[i].available) * 
            exp(log(mall_quality_price_info_list.array[i].price)*GAMMA_CONST); 
        }

        /*This computes the logits  */
        for(i = 0; i < mall_quality_price_info_list.size; i++) 
        {
            logit = (mall_quality_price_info_list.array[i].available) * 
            exp(log(mall_quality_price_info_list.array[i].price)*GAMMA_CONST) / 
            sum_weighted_qual_pric_ratios;

            logit = logit*100;

            add_logit_firm_id(&logit_firm_id_list, logit,
            mall_quality_price_info_list.array[i].firm_id);
        }

        if(sum_weighted_qual_pric_ratios>0)
        {
            int random_number = random_int(0,100);
            j = 0;
            int x = 0, index_selected_good=j;

            for(j = 0; j < logit_firm_id_list.size;j++)
            {
                /*if random number <= logit then select the corresponding good  */ 
                if((random_number < logit_firm_id_list.array[j].logit)
                && (x!=1))
                {
                    ORDER_QUANTITY[1].firm_id = logit_firm_id_list
                    .array[j].firm_id; //Seleced Good
                
                    x =1;
                    index_selected_good= j;
                }
                /*else sum logits and go to next iteration step */
                else
                {
                    if((j < logit_firm_id_list.size-1) )
                    {
                        logit_firm_id_list.array[j+1].logit = logit_firm_id_list.array[j+1].logit+ 
                        logit_firm_id_list.array[j].logit;
                    }
                }
            }
        
            /*This computes the order quantity  and store the price */
            ORDER_QUANTITY[1].quantity = WEEKLY_BUDGET/
            mall_quality_price_info_list.array[index_selected_good].price;

            ORDER_QUANTITY[1].price = mall_quality_price_info_list
            .array[index_selected_good].price;

            /*Sending the second consumption request message  */
            add_consumption_request_2_message(
            mall_quality_price_info_list.array[index_selected_good].mall_id,
            ID,REGION_ID,ORDER_QUANTITY[1].firm_id,
            ORDER_QUANTITY[1].quantity);
        }
        else
        {       
            ORDER_QUANTITY[1].quantity = 0;
            ORDER_QUANTITY[1].firm_id= 0;
            ORDER_QUANTITY[1].price= 0;
        }

    free_mall_quality_price_info_array(&mall_quality_price_info_list);
    free_logit_firm_id_array(&logit_firm_id_list);

    return 0;
}

/** \fn Household_receive_goods_read_rationing_2()
 * \brief This function stores in memory the realized consumption if HH was rationed in the first round.
 */
int Household_receive_goods_read_rationing_2()
{

    if(RATIONED ==1)
    {
        /*Read the message about accepted consumption */
        START_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP

                RATIONED = accepted_consumption_2_message->rationed;

                RECEIVED_QUANTITY[1].quantity=
                accepted_consumption_2_message->offered_consumption_volume;
                
                RECEIVED_QUANTITY[1].firm_id = 
                ORDER_QUANTITY[1].firm_id; 
                
                WEEKLY_BUDGET = WEEKLY_BUDGET - RECEIVED_QUANTITY[1].quantity *ORDER_QUANTITY[1].price;
                EXPENDITURES += RECEIVED_QUANTITY[1].quantity * ORDER_QUANTITY[1].price;
                
                MONTHLY_CONSUMPTION_EXPENDITURE += RECEIVED_QUANTITY[1].quantity * ORDER_QUANTITY[1].price;

        FINISH_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP
    }
    else
    {
        RECEIVED_QUANTITY[1].quantity=0.0;
        RECEIVED_QUANTITY[1].firm_id =0; 
    }
   
    
    
   if ((ID>21)&&(ID<=22))
   { 
    if (PRINT_DEBUG_FILE_EXP2)
    {                       
       char * filename;
       FILE * file1;
       filename = malloc(40*sizeof(char));
       filename[0]=0;
       strcpy(filename, "its/households_receive_goods2.txt");      
       file1 = fopen(filename,"a");
       fprintf(file1,"\n %d %d %f %f",DAY,ID,RECEIVED_QUANTITY[1].quantity,ORDER_QUANTITY[1].price);
       fprintf(file1," %f %f %f",WEEKLY_BUDGET,EXPENDITURES,MONTHLY_CONSUMPTION_EXPENDITURE);
      fclose(file1);
       free(filename);
    }              
   } 
    

    return 0;
}

/** \fn Household_receive_dividends()
 * \brief Here the households get their dividend payments            
 */
int Household_receive_dividends()
{
    RECEIVED_DIVIDEND=0;
    
    START_DIVIDEND_PER_SHARE_MESSAGE_LOOP
    int i;
    for(i = 0; i < ASSETSOWNED.size; i++)
    {
        if(ASSETSOWNED.array[i].id == dividend_per_share_message->firm_id)
        {
            double dividend = dividend_per_share_message->current_dividend_per_share*ASSETSOWNED.array[i].quantity;
            
            RECEIVED_DIVIDEND +=dividend;
            CUM_TOTAL_DIVIDENDS +=dividend;
            PAYMENT_ACCOUNT += dividend;           
           
            break;
        }
        
    }
        
    FINISH_DIVIDEND_PER_SHARE_MESSAGE_LOOP
    
    //Here the household sets its monthly consumption counter to zero at the first day of the month
    
    if(DAY%MONTH==1)
    {
        MONTHLY_CONSUMPTION_EXPENDITURE = 0.0;
    }
    
    return 0;   
}


/** \fn Household_handle_leftover_budget()
 * \brief This function converts the remaining budget, that is not spent in both consumption steps, into the PAYMENT_ACCOUNT            
 */
int Household_handle_leftover_budget()
{
        CONSUMPTION_BUDGET -= EXPENDITURES;

       

        if(WEEK_OF_MONTH !=1)
        {               
            PAYMENT_ACCOUNT -= EXPENDITURES;
            WEEK_OF_MONTH--;
            WEEKLY_BUDGET = CONSUMPTION_BUDGET / WEEK_OF_MONTH;
        }
        else
        {
            PAYMENT_ACCOUNT =PAYMENT_ACCOUNT - EXPENDITURES;
            
            WEEK_OF_MONTH--;
        }
        
        //set rationed back to zero:
        RATIONED = 0;
    
    return 0;
}


/** \fn Household_send_account_update()
 * \brief This function sends the PAYMENT_ACCOUNT to the bank            
 */
int Household_send_account_update()
{
     // #ifdef _DEBUG_MODE  

   if ((ID>=101)&&(ID<=120))
   {
    if (PRINT_DEBUG_FILE_EXP2)
    {                       
       char * filename;
       FILE * file1;
       Asset_array *assets;
       Asset *asset;
       int size;
       int i;
       assets =get_assetsowned();
       size = assets->size;                    
       filename = malloc(40*sizeof(char));
       filename[0]=0;
       strcpy(filename, "its/households_portfolio.txt");      
       file1 = fopen(filename,"a");
       fprintf(file1,"\n %d %d",DAY,ID);
       for(i=0;i<size;i++)
        {
         asset=elementAtCAsset(assets,i);
         fprintf(file1," %d %d",asset->id,asset->quantity);
        }
       fclose(file1);
       free(filename);
    }              
   } 


   add_bank_account_update_message(ID, BANK_ID, PAYMENT_ACCOUNT);
 
   EXPENDITURES = 0;
     
//      printf("\n %d %d %d",ID,assets->size,assets->total_size);

    
    return 0;
}
