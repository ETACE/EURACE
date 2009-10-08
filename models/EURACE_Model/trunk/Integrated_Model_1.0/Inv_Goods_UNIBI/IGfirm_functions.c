#include <math.h>
#include "../header.h"
#include "../IGFirm_agent_header.h"
#include "../my_library_header.h"


int day_of_month_to_act()
{
    if(DAY%MONTH == DAY_OF_MONTH_TO_ACT) return 1;
    else return 0;
}

int not_day_of_month_to_act()
{
    if(DAY%MONTH == DAY_OF_MONTH_TO_ACT) return 0;
    else return 1;
}


int IGFirm_idle()
{
     FILE *file1;
    char *filename;
    
    if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/IGFirm_daily_balance_sheet.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f",DAY,ID, PAYMENT_ACCOUNT,CUM_ENERGY_COSTS);
            fclose(file1);
            free(filename);
        }      
        
    return 0;
}


/***************************** Investment Goods producer function********************************/
/** \fn IGFirm_update_productivity_price()
 * \brief IGFirm inceases productivity via a stochastic process and the according price */
int IGFirm_update_productivity_price()
{
    
    int i;

    
        i = random_int( 0 ,100);
        
        if(i < INNOVATION_PROBABILITY)
        {
            PRODUCTIVITY = PRODUCTIVITY*(1 + PRODUCTIVITY_PROGRESS);
            CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE*(1 +.5* PRODUCTIVITY_PROGRESS); 
        }


    return 0;
}

/** \fn IGFirm_update_productivity_price()
 * \brief IGFirm send quality and price information */
int IGFirm_send_quality_price_info()
{
    //In case we run the energy shock experiment: determine the CAPITAL_GOOD_PRICE
    if (POLICY_EXP_ENERGY_SHOCK)
    {
        //Case 1: shock occurs multiple times
        if (ENERGY_SHOCK_FREQUENCY!=0)
        {   
            // To simulate a REPEATED energy price shock over a time duration interval:    
            if ((DAY>=ENERGY_SHOCK_START)&&(DAY<ENERGY_SHOCK_END)&&((DAY-ENERGY_SHOCK_START)%ENERGY_SHOCK_FREQUENCY==0))
            {
                ENERGY_PRICE_MARKUP = CONST_ENERGY_SHOCK_INTENSITY;
            }
            else ENERGY_PRICE_MARKUP = 0.0;
            
            //Multiplicative: mark up is defined in percentage terms
            CAPITAL_GOOD_PRICE *= (1+ENERGY_PRICE_MARKUP);
            
            //At the end of the time interval there is a down_shock only if the shock is set to be symmetric:
            if ((DAY==ENERGY_SHOCK_END)&&(SYMMETRIC_SHOCK==1))
            {   
                #ifndef _DEBUG_MODE
                    if(PRINT_DEBUG) printf("\nIn IGFirm_send_quality_price_info: Downward shock due to SYMMETRIC_SHOCK==1\n");
                #endif

                //Multiplicative: mark up defined in percentage terms
                CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE*pow((1+CONST_ENERGY_SHOCK_INTENSITY),-(ENERGY_SHOCK_END-ENERGY_SHOCK_START)/ENERGY_SHOCK_FREQUENCY);
            }        
        }
        
        //Case 2: shock occurs only at start and end
        if (ENERGY_SHOCK_FREQUENCY==0)
        {   
            //Only update the price with the energy markup once at the start
            if (DAY==ENERGY_SHOCK_START)
            {        
                CAPITAL_GOOD_PRICE *= (1+CONST_ENERGY_SHOCK_INTENSITY);
            }
            //Reset price at end of period
            if ((DAY==ENERGY_SHOCK_END)&&(SYMMETRIC_SHOCK==1))
            {        
                CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE/(1+CONST_ENERGY_SHOCK_INTENSITY);
            }
        }
    } 
   
        add_productivity_message(ID,PRODUCTIVITY,CAPITAL_GOOD_PRICE);

    return 0;
}

/** \fn IGFirm_send_capital_good()
 * \brief IGFirm sends capital goods to firms
 */
int IGFirm_send_capital_good()
{
    START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

        add_capital_good_delivery_message(capital_good_request_message->firm_id,
                capital_good_request_message->capital_good_demand, PRODUCTIVITY, CAPITAL_GOOD_PRICE);

    FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

    return 0;
}



/** \fn IGFirm_receive_payment()
 * \brief IGFirm calculates revenues and distributes the revenue to the households
 */

int IGFirm_receive_payment()
{
    
    
    REVENUE_PER_DAY = 0;

    START_PAY_CAPITAL_GOODS_MESSAGE_LOOP

        
        
        REVENUE_PER_DAY += pay_capital_goods_message->capital_bill;
        

    FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP
    
    ENERGY_COSTS_PER_DAY = (ENERGY_PRICE_MARKUP/CAPITAL_GOOD_PRICE)*REVENUE_PER_DAY;
    
    EARNINGS_PER_DAY = REVENUE_PER_DAY - ENERGY_COSTS_PER_DAY;
    

    CUM_ENERGY_COSTS += ENERGY_COSTS_PER_DAY;
    EARNINGS += EARNINGS_PER_DAY; 
    PAYMENT_ACCOUNT += EARNINGS_PER_DAY;
    return 0;
}

/** \fn IGFirm_dividend_payment()
 * \brief IGFirm distributes dividends to the households, and sends total_dividend payment to the bank
 */



int IGFirm_pay_taxes()
{
    
    // Compute the monthly earnings from revenues minus energy 
    
    
    //TAX_PAYMENT = CUM_REVENUES*TAX_RATE_CORPORATE;
    TAX_PAYMENT = EARNINGS *0;  
    
    PAYMENT_ACCOUNT -= TAX_PAYMENT;

    NET_PROFIT = EARNINGS  - TAX_PAYMENT;
    EARNINGS =0.0;
    add_tax_payment_message(GOV_ID,TAX_PAYMENT);
    
    return 0;
}



int IGFirm_dividend_payment()
{
    FILE *file1;
    char *filename;
    
    double total_dividend_payment;
    total_dividend_payment = NET_PROFIT;
    
    CURRENT_DIVIDEND_PER_SHARE = NET_PROFIT / OUTSTANDING_SHARES;

    
    //add dividend_per_share_msg(firm_id, current_dividend_per_share) to shareholders (dividend per share)     
    add_dividend_per_share_message(ID, CURRENT_DIVIDEND_PER_SHARE);
    
    //decrease payment_account with the total_dividend_payment
    PAYMENT_ACCOUNT -= total_dividend_payment;
    
    if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/IGFirm_daily_balance_sheet.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f",DAY,ID, PAYMENT_ACCOUNT,CUM_ENERGY_COSTS);
            fclose(file1);
            free(filename);
        }           
    
    
    return 0;
}



