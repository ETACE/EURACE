#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"


int Firm_send_id_to_malls()
{

//Add the message to malls
add_msg_firm_id_to_malls_message(ID,REGION_ID);

return 0;
}










int Firm_initialize_mall_arrays()
{
int i,k,l;
int num_malls=0;
double production_quantity_per_mall;

//1. Count the number of total malls

START_MSG_MALL_ID_TO_FIRMS_MESSAGE_LOOP

num_malls++;

FINISH_MSG_MALL_ID_TO_FIRMS_MESSAGE_LOOP

//Compute the new production quantities for the malls
production_quantity_per_mall = LAST_PLANNED_PRODUCTION_QUANTITIES.array[3] / num_malls;


// Clean up all arrays

for(i=0;i<SOLD_QUANTITIES.size;i++)
{
remove_estimators_linear_regression(&LINEAR_REGRESSION_ESTIMATORS,i);
remove_sales_statistics(&MALLS_SALES_STATISTICS,i);
remove_sold_quantities_per_mall(&SOLD_QUANTITIES,i);
remove_delivery_volume_per_mall(&DELIVERY_VOLUME,i);
remove_delivery_volume_per_mall(&PLANNED_DELIVERY_VOLUME,i);
remove_mall_info(&CURRENT_MALL_STOCKS,i);
}

//Set up the data arrays

k=0;

START_MSG_MALL_ID_TO_FIRMS_MESSAGE_LOOP

add_estimators_linear_regression(&LINEAR_REGRESSION_ESTIMATORS,msg_mall_id_to_firms_message->mall_id,0.0,0.0,0.0);

add_sales_statistics(&MALLS_SALES_STATISTICS,msg_mall_id_to_firms_message->mall_id,0);
for(l=0;l<FIRM_PLANNING_HORIZON;l++)
{
add_data_type_sales(&MALLS_SALES_STATISTICS.array[k].sales,l+1,production_quantity_per_mall);
}
add_sold_quantities_per_mall(&SOLD_QUANTITIES,msg_mall_id_to_firms_message->mall_id, production_quantity_per_mall, 0,0.0);
add_delivery_volume_per_mall(&DELIVERY_VOLUME,msg_mall_id_to_firms_message->mall_id,0.0,0.0,0.0);
add_delivery_volume_per_mall(&PLANNED_DELIVERY_VOLUME,msg_mall_id_to_firms_message->mall_id,0.0,0.0,0.0);
add_mall_info(&CURRENT_MALL_STOCKS,msg_mall_id_to_firms_message->mall_id, production_quantity_per_mall,0.0);

k++;
FINISH_MSG_MALL_ID_TO_FIRMS_MESSAGE_LOOP


return 0;
}



/** \fn Firm_send_data_to_Eurostat()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Firm_send_data_to_Eurostat()
{
    
    /*Determine the productivity of the firm. Send data to Eurostat in 
     * order to calculate the productivity progress once a year*/
  

        FIRM_PRODUCTIVITY_LAST_YEAR = FIRM_PRODUCTIVITY;
        
        if(MEAN_SPECIFIC_SKILLS >= TECHNOLOGY)
        {
            FIRM_PRODUCTIVITY = TECHNOLOGY;
        }
        else
        {
            FIRM_PRODUCTIVITY = MEAN_SPECIFIC_SKILLS;
        }

        FIRM_PRODUCTIVITY_PROGRESS = FIRM_PRODUCTIVITY/FIRM_PRODUCTIVITY_LAST_YEAR -1;
        
    
    
    //Increase the age of the firm in months
    AGE++;
    
    add_firm_send_data_message(ID, REGION_ID, VACANCIES, NO_EMPLOYEES,
    NO_EMPLOYEES_SKILL_1, NO_EMPLOYEES_SKILL_2, NO_EMPLOYEES_SKILL_3, NO_EMPLOYEES_SKILL_4, NO_EMPLOYEES_SKILL_5, 
    MEAN_WAGE, WAGE_OFFER, MEAN_SPECIFIC_SKILLS,
    AVERAGE_S_SKILL_OF_1, AVERAGE_S_SKILL_OF_2, AVERAGE_S_SKILL_OF_3, AVERAGE_S_SKILL_OF_4, AVERAGE_S_SKILL_OF_5,
    CUM_REVENUE, CAPITAL_COSTS, NET_EARNINGS, TOTAL_DEBT, TOTAL_ASSETS, EQUITY,
    PRICE, PRICE_LAST_MONTH, TOTAL_SUPPLY, SOLD_QUANTITY_IN_CALENDAR_MONTH, OUTPUT, PLANNED_OUTPUT, AGE, FIRM_PRODUCTIVITY, FIRM_PRODUCTIVITY_PROGRESS);

 
    
    //printf("In Firm_send_data: Firm %d OUTPUT: %.2f\n", ID, OUTPUT);
    //printf("In Firm_send_data: Firm %d PLANNED_OUTPUT: %.2f\n", ID, PLANNED_OUTPUT);

    return 0;
}

int Firm_send_payments_to_bank()
{
     FILE *file1;
     char *filename;
     
    add_bank_account_update_message(ID, BANK_ID, PAYMENT_ACCOUNT);
    if(PAYMENT_ACCOUNT<0)
        printf("PAYMENT_ACCOUNT of Firm %d:  %f \n",ID,PAYMENT_ACCOUNT);
               
    //    if (PRINT_DEBUG_FILE_EXP1)
    //{
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firms_balance_sheet.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f %f %f",DAY,ID,TOTAL_UNITS_CAPITAL_STOCK,TOTAL_VALUE_CAPITAL_STOCK,TOTAL_UNITS_LOCAL_INVENTORY,TOTAL_VALUE_LOCAL_INVENTORY);
        fprintf(file1," %f %f %f %f %d",PAYMENT_ACCOUNT,TOTAL_ASSETS,TOTAL_DEBT,EQUITY,REGION_ID);
        fclose(file1);
        free(filename);

    //}    
    
    return 0;
}

/** \fn Firm_read_policy_announcements()
 * \brief Function to read the policy_announcements from Governments.
 */
int Firm_read_policy_announcements()
{

    //Message send by Government:
    START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP          
        //Filter: 
        if(policy_announcement_message->gov_id == GOV_ID)
        {
            TAX_RATE_CORPORATE = policy_announcement_message->tax_rate_corporate;
            TAX_RATE_VAT = policy_announcement_message->tax_rate_vat;
            TRANSFER_PAYMENT = policy_announcement_message->firm_transfer_payment;
            SUBSIDY_PCT = policy_announcement_message->firm_subsidy_pct;
        }
    FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
    
    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG)
    {
        printf("\n Firm_read_policy_announcements ID: %d",ID);
        printf("\n \t TAX_RATE_CORPORATE: %f TAX_RATE_VAT: %f TRANSFER_PAYMENT: %f SUBSIDY_PCT: %f",TAX_RATE_CORPORATE,TAX_RATE_VAT,TRANSFER_PAYMENT,SUBSIDY_PCT);
        getchar();
    }
    #endif        
    
    return 0;
}

/** \fn Firm_send_subsidy_notification()
 * \brief Function to send a subsidy_notification_message to the government. 
 */
int Firm_send_subsidy_notification()
{
    if (POLICY_EXP_STABILIZATION_SUBSIDY==1)
    {    
        SUBSIDY_PAYMENT = SUBSIDY_PCT*CAPITAL_COSTS;
        
        /*Add subsidy message */
        add_firm_subsidy_notification_message(GOV_ID, SUBSIDY_PAYMENT);
        
        PAYMENT_ACCOUNT += SUBSIDY_PAYMENT;
    }        
    return 0;       
}

/** \fn Firm_send_transfer_notification()
 * \brief Function to send a transfer_notification_message to the government. 
 */
int Firm_send_transfer_notification()
{
    /*Add transfer message */
    add_firm_transfer_notification_message(GOV_ID);
    PAYMENT_ACCOUNT += TRANSFER_PAYMENT;
        
    return 0;       
}

/** \fn Firm_receive_data()
 * \brief Firms receive the data messages from the Eurostat.
 */
int Firm_receive_data()
{
    
    START_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
        
        /*Specific skills of the domestic region*/
        //Filter: 
        if(eurostat_send_specific_skills_message->region_id == REGION_ID)
        {
            /*If there is no employee with general skill level 1 resp. 2-5*/
            if(NO_EMPLOYEES_SKILL_1 == 0)
            {
                AVERAGE_S_SKILL_OF_1 =                      eurostat_send_specific_skills_message->
                specific_skill_1;
            }

            if(NO_EMPLOYEES_SKILL_2 == 0)
            {
                AVERAGE_S_SKILL_OF_2 =                      eurostat_send_specific_skills_message->
                specific_skill_2;
            }

            if(NO_EMPLOYEES_SKILL_3 == 0)
            {
                AVERAGE_S_SKILL_OF_3 =                      eurostat_send_specific_skills_message->
                specific_skill_3;
            }

            if(NO_EMPLOYEES_SKILL_4 == 0)
            {
                AVERAGE_S_SKILL_OF_4 =                      eurostat_send_specific_skills_message->
                specific_skill_4;
            }

            if(NO_EMPLOYEES_SKILL_5 == 0)
            {
                AVERAGE_S_SKILL_OF_5 =                      eurostat_send_specific_skills_message->
                specific_skill_5;
            }
            
            /*Increase wage offer regarding the productivity increase*/
            if(DAY%20 == 1)
            {
                //if(ID < 3)
                //printf("FIRM_ID %d \n",ID);
                //if(ID < 3)
                //printf("eurostat_send_specific_skills_message->productivity_progress %f \n",eurostat_send_specific_skills_message->productivity_progress);
                               
                int i;
                for(i = 0; i < EMPLOYEES.size; i++)
                {  
                    EMPLOYEES.array[i].wage = EMPLOYEES.array[i].wage*(1+
                    eurostat_send_specific_skills_message->productivity_progress);    
                }
                CPI = eurostat_send_specific_skills_message->cpi;
                PRICE_INDEX = eurostat_send_specific_skills_message->price_index;
            }
        }
    FINISH_EUROSTAT_SEND_SPECIFIC_SKILLS_MESSAGE_LOOP
        
    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG)
    {
        printf("\n Firm receive data ID: %d",ID);     
    }          
    #endif        

    return 0;
}
