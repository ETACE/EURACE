#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"

/** \fn Firm_send_data_to_Eurostat()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Firm_send_data_to_Eurostat()
{
    
    /*Determine the productivity of the firm. Send data to Eurostat in 
     * order to calculate the productivity progress once a year*/
    if(DAY%20 == 0)
    {   
    
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
        
    }
    
    //Increase the age of the firm in months
    AGE++;
    
    add_firm_send_data_message(ID, REGION_ID, VACANCIES, NO_EMPLOYEES,
    NO_EMPLOYEES_SKILL_1, NO_EMPLOYEES_SKILL_2, NO_EMPLOYEES_SKILL_3, NO_EMPLOYEES_SKILL_4, NO_EMPLOYEES_SKILL_5, 
    MEAN_WAGE, MEAN_SPECIFIC_SKILLS,
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
               
        if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firms_balance_sheet.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f %f %f",DAY,ID,TOTAL_UNITS_CAPITAL_STOCK,TOTAL_VALUE_CAPITAL_STOCK,TOTAL_UNITS_LOCAL_INVENTORY,TOTAL_VALUE_LOCAL_INVENTORY);
        fprintf(file1," %f %f %f %f %d",PAYMENT_ACCOUNT,TOTAL_ASSETS,TOTAL_DEBT,EQUITY,REGION_ID);
        fclose(file1);
        free(filename);

    }    
    
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
    if (POLICY_EXP_STABILIZATION==1)
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
