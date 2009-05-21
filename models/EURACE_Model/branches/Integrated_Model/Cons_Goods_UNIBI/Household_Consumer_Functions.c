#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"


/********************************* Household agent functions *************************************/



/**********************************Household Role: Consumption Goods Market*********************/


/*\fn Household_determine_consumption_budget()
 * brief: If a household is unemployed then it receives an unemployment benefit payment
 * 
 * */

int Household_determine_consumption_budget()
{
    char temp[10];
    char * filename;
    FILE * file1,*file2;
    
    if (PRINT_DEBUG)
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
            
            /*Based on Carrol-Rule: Determination of the consumption budget*/
            CONSUMPTION_BUDGET = MEAN_INCOME + 
            CONSUMPTION_PROPENSITY*(WEALTH - WEALTH_INCOME_RATIO*MEAN_INCOME);
            if(PAYMENT_ACCOUNT < 0)
            {
               if (PRINT_DEBUG)
                    fprintf(file1, "IT %d ID %d PAYMENT_ACCOUNT %f \n", DAY, ID, PAYMENT_ACCOUNT);
            }
            
            if(CONSUMPTION_BUDGET < 0.5*LAST_INCOME.array[3])
            {
                if(CONSUMPTION_BUDGET < 0)
                {
                    printf("___________In file Household_Consumer_Functions.c, function Household_determine_consumption_budget, line 65:\n"
                    "Household payment_account<0\n");
                    
                    if (PRINT_DEBUG)
                        fprintf(file2,"IT %d ID %d CONSUMPTION_BUDGET %f\n",DAY,ID,CONSUMPTION_BUDGET);
                }
                CONSUMPTION_BUDGET = 0.5*LAST_INCOME.array[3];
            }

            //PORTFOLIO_BUDGET=PAYMENT_ACCOUNT-CONSUMPTION_BUDGET;
            WEEKLY_BUDGET = CONSUMPTION_BUDGET/4;
            WEEK_OF_MONTH = 4;
            
        EXCESS_WEEKLY_BUDGET = WEEKLY_BUDGET - PAYMENT_ACCOUNT;

        if (PRINT_DEBUG)
        {
            //close the file pointer: FILE * file
            fclose(file1);
            fclose(file2);
            free(filename);
        }

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
    Depending on these infos the household sends its good request       
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

            /*This computes and stores the order quantity of the selected good and              saves the price in memory */
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
 * \brief The household gets information about the accepted amount of goods and, if the mall is completly sold out then the households set the order and delivery volumes forn the second step equal 0
            
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
                /*if randum number <= logit then select the corresponding                       good  */ 
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
                        logit_firm_id_list.array[j+1].logit =                               logit_firm_id_list.array[j+1].logit+ 
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

/** \fn Household_read_rationing()
 * \brief This function stores in memory the realized consumption if HH was rationed in first round. 
            
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

        FINISH_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP
        
        

    }
    else
    {
        RECEIVED_QUANTITY[1].quantity=0.0;
        RECEIVED_QUANTITY[1].firm_id =0; 
    }

    WEEKLY_BUDGET = WEEKLY_BUDGET - RECEIVED_QUANTITY[1].quantity 
    *ORDER_QUANTITY[1].price ;

    
    
    EXPENDITURES += RECEIVED_QUANTITY[1].quantity * ORDER_QUANTITY[1].price ;
    
    ;
    return 0;
}



/** \fn Household_receicve_dividens()
 * \brief Here the households get their dividends payments
            
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
            CUM_TOTAL_DIVIDENDS +=dividend ;
            PAYMENT_ACCOUNT += dividend;
            break;
        }
        
    }
    
    FINISH_DIVIDEND_PER_SHARE_MESSAGE_LOOP
    
    return 0;   
}


/** \fn Household_handle_leftover_budget()
 * \brief This function convert the remaining budget, that is not spent in both consumtion steps, into the PAYMENT_ACCOUNT 
            
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
    
        /*GENUA*/
        add_bank_account_update_message(ID, BANK_ID, PAYMENT_ACCOUNT);
    
        /*AIX*/
        if (SWITCH_FLOW_CONSISTENCY_CHECK)
        {
            //Set these to correct expressions:
            GOV_BOND_HOLDINGS=0.0;
            NR_GOV_BONDS=0;
            NR_FIRM_SHARES=0;
            GOV_INTEREST=0.0;
            STOCK_SALES=0.0;
            MONTHLY_CONSUMPTION_EXPENDITURE=0.0;
            STOCK_PURCHASES=0.0;
            TOTAL_ASSETS=0.0;
            TOTAL_LIABILITIES=0.0;
            TOTAL_INCOME=0.0;
            TOTAL_EXPENSES=0.0;

            //printf("\n Household %d: my WAGE=%2.2f.\n", ID, WAGE);
            add_household_balance_sheet_message(PAYMENT_ACCOUNT, GOV_BOND_HOLDINGS, NR_GOV_BONDS, NR_FIRM_SHARES, 
                    WAGE, GOV_INTEREST, STOCK_SALES,
                    CUM_TOTAL_DIVIDENDS, MONTHLY_CONSUMPTION_EXPENDITURE, TAX_PAYMENT, STOCK_PURCHASES, 
                    TOTAL_ASSETS, TOTAL_LIABILITIES, TOTAL_INCOME, TOTAL_EXPENSES);
        }

    return 0;
}




