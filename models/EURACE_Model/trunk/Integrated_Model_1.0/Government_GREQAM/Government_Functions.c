//For trunk model
#include <math.h>
#include "../header.h"
#include "../Government_agent_header.h"
#include "../my_library_header.h"
//For Isolated model
//#include <math.h>
//#include "header.h"
//#include "Government_agent_header.h"
//#include "../my_library_header.h"

//#define NO_REGIONS_PER_GOV 2 //number of regions per gov

/************Government Role: Finance********************************/
int Government_idle()
{
    return 0;
}


/* \fn: int Government_initialization()
 * \brief Function to initialize.
 */
int Government_initialization()
{   
    //add only the region_id of the government to its list_of_regions
    reset_int_array(&LIST_OF_REGIONS);
    add_int(&LIST_OF_REGIONS, REGION_ID);

    //Set tax rate to global constant
    TAX_RATE_HH_LABOUR = CONST_INCOME_TAX_RATE;
    TAX_RATE_CORPORATE = CONST_INCOME_TAX_RATE;

    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG_GOV)
        { 
                    printf("\n Government_initialization ID: %d",ID);
                    getchar();
        }
    #endif
    
    return 0;   
}

/* \fn: int Government_send_policy_announcements()
 * \brief Function to send yearly policy announcement message.
 */
int Government_send_policy_announcements()
{   
    FILE *file1=NULL;
    char *filename=NULL;
         
    HH_SUBSIDY_PCT=0.0;
    FIRM_SUBSIDY_PCT=0.0;
    UNEMPLOYMENT_BENEFIT_PCT=GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT;


    if(POLICY_EXP_STABILIZATION_SUBSIDY)
    {
        //Set trigger function:
        if ((SUBSIDY_FLAG==0)&&(GDP_GROWTH<SUBSIDY_TRIGGER_ON))
        {
            SUBSIDY_FLAG=1;
            HH_SUBSIDY_PCT = -tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
        }

        //Release trigger function:
        if ((SUBSIDY_FLAG==1)&&(GDP_GROWTH>SUBSIDY_TRIGGER_OFF))
        {
            SUBSIDY_FLAG=0;
            HH_SUBSIDY_PCT = 0.0;
        }

        //Subsidy regime
        if ((SUBSIDY_FLAG==1)&&(GDP_GROWTH<SUBSIDY_TRIGGER_OFF))
        {
            HH_SUBSIDY_PCT = -tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
        }
       
        // #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_FILE_EXP2)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "Government.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"%f\n",HH_SUBSIDY_PCT);
            fclose(file1);
            free(filename);
        }
        // #endif 

	    #ifdef _DEBUG_MODE
	    if ((PRINT_DEBUG_GOV)&&(SUBSIDY_FLAG==1))
	    { 
              printf("\n Stabilization: Government_send_policy_announcements ID: %d",ID);
              printf("\n SUBSIDY_FLAG: %d",SUBSIDY_FLAG);
              printf("\n CONST_INCOME_TAX_RATE: %f", CONST_INCOME_TAX_RATE);
              printf("\n GDP_GROWTH: %f", GDP_GROWTH);
              printf("\n fabs(GDP_GROWTH): %f", fabs(GDP_GROWTH));
              printf("\n SUBSIDY_TRIGGER_ON %f", SUBSIDY_TRIGGER_ON);
              printf("\n SUBSIDY_TRIGGER_OFF: %f", SUBSIDY_TRIGGER_OFF);
              printf("\n tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF): %f", tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF));
              printf("\n HH_SUBSIDY_PCT: %f*%f= %f", -tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF), fabs(GDP_GROWTH), HH_SUBSIDY_PCT);
              printf("\n \t TAX_RATE_HH_LABOUR: %f TAX_RATE_CORPORATE: %f TAX_RATE_HH_CAPITAL: %f TAX_RATE_VAT: %f",
				 TAX_RATE_HH_LABOUR, TAX_RATE_CORPORATE, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT);
              printf("\n \t UNEMPLOYMENT_BENEFIT_PCT: %f HH_SUBSIDY_PCT: %f FIRM_SUBSIDY_PCT: %f HH_TRANSFER_PAYMENT: %f FIRM_TRANSFER_PAYMENT; %f",
				 UNEMPLOYMENT_BENEFIT_PCT, HH_SUBSIDY_PCT, FIRM_SUBSIDY_PCT, HH_TRANSFER_PAYMENT, FIRM_TRANSFER_PAYMENT);
              getchar();
	    }
   	    #endif
    }

    if(POLICY_EXP_STABILIZATION_TAX)
    {
        //Set trigger function:
        if ((SUBSIDY_FLAG==0)&&(GDP_GROWTH<SUBSIDY_TRIGGER_ON))
        {
            SUBSIDY_FLAG=1;

            //Lower the income tax 
	    TAX_RATE_HH_LABOUR = CONST_INCOME_TAX_RATE + tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
	    TAX_RATE_CORPORATE = CONST_INCOME_TAX_RATE + tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
        }

        //Release trigger function:
        if ((SUBSIDY_FLAG==1)&&(GDP_GROWTH>SUBSIDY_TRIGGER_OFF))
        {
            SUBSIDY_FLAG=0;

            //Reset the income tax to its normal value
            TAX_RATE_HH_LABOUR = CONST_INCOME_TAX_RATE;
	    TAX_RATE_CORPORATE = CONST_INCOME_TAX_RATE;
        }

        //Subsidy regime
        if ((SUBSIDY_FLAG==1)&&(GDP_GROWTH<SUBSIDY_TRIGGER_OFF))
        {
            //Lower the income tax 
	    TAX_RATE_HH_LABOUR = CONST_INCOME_TAX_RATE + tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
	    TAX_RATE_CORPORATE = CONST_INCOME_TAX_RATE + tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH);
        }

	    #ifdef _DEBUG_MODE
	    if ((PRINT_DEBUG_GOV)&&(SUBSIDY_FLAG==1))
	    { 
              printf("\n Stabilization: Government_send_policy_announcements ID: %d",ID);
              printf("\n SUBSIDY_FLAG: %d",SUBSIDY_FLAG);
              printf("\n CONST_INCOME_TAX_RATE: %f", CONST_INCOME_TAX_RATE);
              printf("\n GDP_GROWTH: %f", GDP_GROWTH);
              printf("\n fabs(GDP_GROWTH): %f", fabs(GDP_GROWTH));
              printf("\n SUBSIDY_TRIGGER_ON %f", SUBSIDY_TRIGGER_ON);
              printf("\n SUBSIDY_TRIGGER_OFF: %f", SUBSIDY_TRIGGER_OFF);
              printf("\n tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF): %f", tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF));
              printf("\n tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH): %f", tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH));
              printf("\n New Tax: %f %f = %f", CONST_INCOME_TAX_RATE, tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH), CONST_INCOME_TAX_RATE + tanh(GDP_GROWTH - SUBSIDY_TRIGGER_OFF)*fabs(GDP_GROWTH));
              printf("\n HH_SUBSIDY_PCT: %f", HH_SUBSIDY_PCT);
              printf("\n \t TAX_RATE_HH_LABOUR: %f TAX_RATE_CORPORATE: %f TAX_RATE_HH_CAPITAL: %f TAX_RATE_VAT: %f",
				 TAX_RATE_HH_LABOUR, TAX_RATE_CORPORATE, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT);
              printf("\n \t UNEMPLOYMENT_BENEFIT_PCT: %f HH_SUBSIDY_PCT: %f FIRM_SUBSIDY_PCT: %f HH_TRANSFER_PAYMENT: %f FIRM_TRANSFER_PAYMENT; %f",
				 UNEMPLOYMENT_BENEFIT_PCT, HH_SUBSIDY_PCT, FIRM_SUBSIDY_PCT, HH_TRANSFER_PAYMENT, FIRM_TRANSFER_PAYMENT);
              getchar();
	    }
   	    #endif
     }

/*
    #ifdef _DEBUG_MODE
     if (PRINT_DEBUG_FILE_EXP1)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Government_policies.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f %f %d",DAY,ID,TAX_RATE_HH_LABOUR,TAX_RATE_CORPORATE,TAX_RATE_HH_CAPITAL,REGION_ID);
            fclose(file1);
            free(filename);
        }
    #endif
    
    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG_GOV)
    { 
	printf("\n Government_send_policy_announcements ID: %d",ID);
	printf("\n \t TAX_RATE_HH_LABOUR: %f TAX_RATE_CORPORATE: %f TAX_RATE_HH_CAPITAL: %f TAX_RATE_VAT: %f",
		 TAX_RATE_HH_LABOUR, TAX_RATE_CORPORATE, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT);
       printf("\n \t UNEMPLOYMENT_BENEFIT_PCT: %f HH_SUBSIDY_PCT: %f FIRM_SUBSIDY_PCT: %f HH_TRANSFER_PAYMENT: %f FIRM_TRANSFER_PAYMENT: %f",
		 UNEMPLOYMENT_BENEFIT_PCT, HH_SUBSIDY_PCT, FIRM_SUBSIDY_PCT, HH_TRANSFER_PAYMENT, FIRM_TRANSFER_PAYMENT);
     	getchar();
    }
    #endif
*/
       
    //add announcement
    add_policy_announcement_message(ID, TAX_RATE_HH_LABOUR, TAX_RATE_CORPORATE, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT, UNEMPLOYMENT_BENEFIT_PCT, HH_SUBSIDY_PCT, FIRM_SUBSIDY_PCT, HH_TRANSFER_PAYMENT, FIRM_TRANSFER_PAYMENT);

    return 0;   
}

/* \fn: int Government_read_tax_payments()
 * \brief Function to read the tax revenues and store the monthly and yearly totals.
 */
int Government_read_tax_payments()
{   
    double sum =0.0;

    START_TAX_PAYMENT_MESSAGE_LOOP
        MONTHLY_TAX_REVENUES += tax_payment_message->tax_payment;
        sum+= tax_payment_message->tax_payment;
    FINISH_TAX_PAYMENT_MESSAGE_LOOP 

    START_UNEMPLOYMENT_BENEFIT_RESTITUTION_MESSAGE_LOOP
        MONTHLY_BENEFIT_PAYMENT -= unemployment_benefit_restitution_message->restitution_payment;
        sum -= unemployment_benefit_restitution_message->restitution_payment;
    FINISH_UNEMPLOYMENT_BENEFIT_RESTITUTION_MESSAGE_LOOP 

   PAYMENT_ACCOUNT += sum;
   
   #ifdef _DEBUG_MODE
   if (PRINT_DEBUG)
   {
                   printf("\n\n Government_read_tax_payments ID: %d",ID);
                   printf("\n\n MONTHLY_TAX_REVENUES: %f sum: %f",MONTHLY_TAX_REVENUES,sum);
                   printf("\n\n PAYMENT_ACCOUNT: %f",PAYMENT_ACCOUNT);
                   getchar();
   }
   #endif 
    
    return 0;
}

/* \fn: int Government_read_unemployment_benefit_notifications()
 * \brief Counter of the unemployment benefit messages, monthly and yearly totals of the unemployment benefit payments.
 */
int Government_read_unemployment_benefit_notifications()
{
    double sum;
    NUM_UNEMPLOYED = 0;
    
    //Start message loop
    sum=0.0;
    START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
        
        NUM_UNEMPLOYED++;
        sum += unemployment_notification_message->unemployment_payment;
        
    FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP

    MONTHLY_BENEFIT_PAYMENT += sum;    
    YEARLY_BENEFIT_PAYMENT += sum;     

    // Update the payment account
    
    PAYMENT_ACCOUNT -= sum;
    
    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG)
    {
                   printf("\n\n Government_read_unemployment_benefit_notifications ID: %d",ID);
                   printf("\n\n MONTHLY_BENEFIT_PAYMENT: %f sum: %f",MONTHLY_BENEFIT_PAYMENT,sum);
                   printf("\n\n YEARLY_BENEFIT_PAYMENT: %f PAYMENT_ACCOUNT: %f",YEARLY_BENEFIT_PAYMENT,PAYMENT_ACCOUNT);
                   getchar();
    }
    #endif

    return 0;
}

/* \fn: int Government_read_transfer_notifications()
 * \brief Counter of the transfer notification messages, monthly and yearly totals of the transfer payments.
 */
int Government_read_transfer_notifications()
{
    int sum;
        
    //Start message loop 
    sum=0;
    START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(hh_transfer_notification_message->gov_id==ID)
            sum++;
    FINISH_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_TRANSFER_PAYMENT += sum*HH_TRANSFER_PAYMENT;
    YEARLY_TRANSFER_PAYMENT += sum*HH_TRANSFER_PAYMENT;     

    // Update the payment account
    PAYMENT_ACCOUNT -= sum*HH_TRANSFER_PAYMENT;

    //Start message loop 
    sum=0;
    START_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(firm_transfer_notification_message->gov_id==ID)
            sum++;
    FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_TRANSFER_PAYMENT += sum*FIRM_TRANSFER_PAYMENT;
    YEARLY_TRANSFER_PAYMENT += sum*FIRM_TRANSFER_PAYMENT;   

    // Update the payment account
    PAYMENT_ACCOUNT -= sum*FIRM_TRANSFER_PAYMENT;
    

    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG)
    {
                   printf("\n\n Government_read_transfer_notifications ID: %d",ID);
                   printf("\n\n MONTHLY_TRANSFER_PAYMENT: %f YEARLY_TRANSFER_PAYMENT: %f",MONTHLY_TRANSFER_PAYMENT,YEARLY_TRANSFER_PAYMENT);
                   getchar();
    }
    #endif
    
    return 0;
}
    
/* \fn: int Government_read_subsidy_notifications()
 * \brief Counter of the subsidy notification messages, monthly and yearly totals of the subsidy payments.
 */
int Government_read_subsidy_notifications()
{
    double sum;
        
    //Start message loop 
    sum=0.0;
    START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(hh_subsidy_notification_message->gov_id==ID)
            sum += hh_subsidy_notification_message->subsidy_payment;
    FINISH_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_SUBSIDY_PAYMENT += sum;
    YEARLY_SUBSIDY_PAYMENT += sum;   

    // Update the payment account
    PAYMENT_ACCOUNT -= sum;

    //Start message loop 
    sum=0.0;
    START_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(firm_subsidy_notification_message->gov_id==ID)
            sum += firm_subsidy_notification_message->subsidy_payment;
    FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_SUBSIDY_PAYMENT += sum;
    YEARLY_SUBSIDY_PAYMENT += sum;     

    // Update the payment account
    PAYMENT_ACCOUNT -= sum;
    
    #ifdef _DEBUG_MODE
    if (PRINT_DEBUG)
    {
                   printf("\n\n Government_read_subsidy_notifications ID: %d",ID);
                   printf("\n\n MONTHLY_SUBSIDY_PAYMENT: %f YEARLY_SUBSIDY_PAYMENT: %f",MONTHLY_SUBSIDY_PAYMENT,YEARLY_SUBSIDY_PAYMENT);
                   getchar();
    }
    #endif

    return 0;
}


/* \fn: int Government_send_account_update()
 * \brief Function to send the payment_account value to the Central Bank.
 */
int Government_send_account_update()
{
     FILE *file1;
     char *filename;
        // At the very end of agent government: update the bank account
        add_gov_to_central_bank_account_update_message(ID, PAYMENT_ACCOUNT);

        #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
        {
                        printf("\n\n Government_send_account_update ID: %d",ID);
                        printf("\n\t PAYMENT_ACCOUNT: %f",PAYMENT_ACCOUNT);
                        getchar();
        }
        #endif
        
        if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Governments_daily_balance_sheet.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f",DAY,ID,PAYMENT_ACCOUNT);
            fprintf(file1," %d %d %f",BOND.nr_outstanding,BOND.quantity,BOND.prices[BOND.index]);
            fprintf(file1," %d",REGION_ID);
            fclose(file1);
            free(filename);
        }              
        
    return 0;
}

/* \fn: int Government_resolve_unsold_bonds()
 * \brief Function to resolve the bonds that are left unsold at the end of each month.
 */
int Government_resolve_unsold_bonds()
{   
    double last_market_price;
    
    //At the end of the month: check if the nr of bonds in the gov's own portfolio is positive
    if (BOND.quantity>0)
    {
        //Government sends a new type of message to ECB with the nr of bonds, and the value:
        
        //if (GOV_POLICY_SWITCH_QUANTITATIVE_EASING)
//        {   
//            last_market_price = BOND.prices[BOND.index];
//            
//            if(last_market_price*BOND.quantity<0.0)
//                printf("\n In Government_resolve_unsold_bonds: Government nominal value %f \n", last_market_price*BOND.quantity);
//
//            add_issue_bonds_to_ecb_message(last_market_price*BOND.quantity, BOND.quantity);
//
//            #ifdef _DEBUG_MODE            
//            if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
//            {
//                printf("\n\n Government_resolve_unsold_bonds.QUANTITATIVE_EASING ID: %d",ID);
//                printf("\n\t Payment account before easing: %f \n", PAYMENT_ACCOUNT);
//            }
//            #endif
//            
//            //Assume that the ECB is FULLY accommodating the government's demand for fiat money:
//            PAYMENT_ACCOUNT += last_market_price*BOND.quantity;
//
//            #ifdef _DEBUG_MODE
//            if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
//            {
//                printf("\n\t Payment account after easing: %f", PAYMENT_ACCOUNT);
//                printf("n\t last_market_price %f BOND.quantity %d \n", last_market_price,BOND.quantity );
//                getchar();
//            }
//            #endif       
//        }   
             
        
        BOND.quantity = 0;
    }
    return 0;
}

/* \fn: int Government_monthly_budget_accounting()
 * \brief Function to perform accounting at the end of each month.
 */
int Government_monthly_budget_accounting()
{
    double in, out;
    FILE *file1;
    char *filename;

    //Compute the following: the interest rate is the base rate of the Central Bank
    //GOV_INTEREST_RATE = (double) 0.05/12.0;
    //GOV_INTEREST_RATE = CB_BASE_RATE/12.0;
    
    YEARLY_TAX_REVENUES += MONTHLY_TAX_REVENUES;
    
    //Items that have already been added to the payment_account
        in = MONTHLY_TAX_REVENUES;
        MONTHLY_INCOME = in;
        
    //Items that have already been subtracted from the payment_account
        out = MONTHLY_BENEFIT_PAYMENT +
        MONTHLY_TRANSFER_PAYMENT +
        MONTHLY_BOND_INTEREST_PAYMENT +
        MONTHLY_INVESTMENT_EXPENDITURE +
        MONTHLY_CONSUMPTION_EXPENDITURE;
        
        MONTHLY_EXPENDITURE = out;
        
    //Compute budget deficit
        MONTHLY_BUDGET_BALANCE = in - out;
        
    //Debt accounting: if the balance>0 debt decreases, if balance<0, debt increases.
        //Debt>0 means a debt, Debt<0 means a surplus.
        CUMULATED_DEFICIT -= MONTHLY_BUDGET_BALANCE;
        TOTAL_DEBT = BOND.nr_outstanding*BOND.face_value;
        
        //Check: value of payment account should be equal to total_debt:

        #ifdef _DEBUG_MODE
        if (PRINT_DEBUG && ((TOTAL_DEBT + PAYMENT_ACCOUNT) != 0.0))
            fprintf(stdout,"\n ERROR in Government: Total debt %2.5f is not equal to payment account %2.5f\n\n", TOTAL_DEBT, PAYMENT_ACCOUNT);
        #endif 
                
    //Monetary policy rule: decide on fraction of deficit to be financed by bonds/fiar money
        TOTAL_MONEY_FINANCING=0;
        TOTAL_BOND_FINANCING=0;
        
/* Sander, 17.06.09: Old style code: refers to the monthly budget deficit        
        if (MONTHLY_BUDGET_BALANCE<0.0)
        {
            TOTAL_MONEY_FINANCING = GOV_POLICY_MONEY_FINANCING_FRACTION*fabs(MONTHLY_BUDGET_BALANCE);
            TOTAL_BOND_FINANCING = (1-GOV_POLICY_MONEY_FINANCING_FRACTION)*fabs(MONTHLY_BUDGET_BALANCE);
        }
*/        
/* Sander, 17.06.09: Marco proposed code: refers to a negative payment_account*/
        if (PAYMENT_ACCOUNT<0.0)
        {
            TOTAL_MONEY_FINANCING = GOV_POLICY_MONEY_FINANCING_FRACTION*fabs(PAYMENT_ACCOUNT);
            TOTAL_BOND_FINANCING = (1-GOV_POLICY_MONEY_FINANCING_FRACTION)*fabs(PAYMENT_ACCOUNT);
        }
        
        //Government sends a message to ECB with the value of fiat money requested
        //Assume that the ECB is FULLY accommodating the government's demand for fiat money
        //add_request_fiat_money_message(nominal_value);
        add_request_fiat_money_message(TOTAL_MONEY_FINANCING);

        PAYMENT_ACCOUNT += TOTAL_MONEY_FINANCING;

        #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
        {
            printf("\n\n Government_monthly_budget_accounting ID: %d",ID);
            printf("\n\t MONTHLY_TAX_REVENUES: %f MONTHLY_BENEFIT_PAYMENT: %f",MONTHLY_TAX_REVENUES, MONTHLY_BENEFIT_PAYMENT);
            printf("\n\t MONTHLY_BOND_INTEREST_PAYMENT: %f out: %f",MONTHLY_BOND_INTEREST_PAYMENT, out);
            printf("\n\t out: %f MONTHLY_BUDGET_BALANCE: %f",out, MONTHLY_BUDGET_BALANCE);
            printf("\n\t PAYMENT_ACCOUNT: %f CUMULATED_DEFICIT: %f TOTAL_DEBT: %f",PAYMENT_ACCOUNT,CUMULATED_DEFICIT, TOTAL_DEBT);
            
            getchar();
        }
        #endif 
        
        // #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_FILE_EXP1)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/government_monthly_accounting.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f ",DAY,ID,MONTHLY_TAX_REVENUES,MONTHLY_BENEFIT_PAYMENT);
            fprintf(file1,"%f %f ",MONTHLY_BOND_INTEREST_PAYMENT,out);
            fprintf(file1,"%f %f ",MONTHLY_BUDGET_BALANCE,PAYMENT_ACCOUNT);
            fprintf(file1,"%f %f %d",CUMULATED_DEFICIT,TOTAL_DEBT,REGION_ID);
            fclose(file1);
            free(filename);
        }
        // #endif 

    return 0;
}

/* \fn: int Government_bonds_issuing_decision()
 * \brief Monthly bond issuing decision. Transforms the nominal amount to units of bonds.
 */

int Government_bonds_issuing_decision()
{
    int new_bonds_amount;
    double last_market_price, limit_price; 
    
    //last_market_price = bond->prices[bond->index];
    last_market_price = BOND.prices[BOND.index];
    
    //Set the bond issue price a bit lower than the last_market_price
    limit_price = (1-BONDS_NEWISSUE_DISCOUNT)*last_market_price;
    new_bonds_amount = ceil(TOTAL_BOND_FINANCING/limit_price);
    
    add_info_new_bonds_amount_message(new_bonds_amount);

    //bond->quantity = bond->quantity + new_bonds_amount;
    BOND.quantity = BOND.quantity + new_bonds_amount;

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\n Government_bonds_issuing_decision ID: %d",ID);
        printf("\n\t last_market_price: %f limit_price: %f", last_market_price, limit_price);
        printf("\n\t new_bonds_amount: %d BOND.quantity: %d", new_bonds_amount, BOND.quantity);
    }
    #endif 

    return 0;
}

/* \fn: int Government_monthly_resetting()
 * \brief Monthly resetting of counters.
 */
int Government_monthly_resetting()
{
    //Reset the monthly counters:
    MONTHLY_TAX_REVENUES =0.0;
    MONTHLY_BENEFIT_PAYMENT =0.0;
    MONTHLY_TRANSFER_PAYMENT =0.0;
    MONTHLY_SUBSIDY_PAYMENT =0.0;
    MONTHLY_BOND_INTEREST_PAYMENT =0.0;
    MONTHLY_INVESTMENT_EXPENDITURE =0.0;
    MONTHLY_CONSUMPTION_EXPENDITURE =0.0;

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_GOV)
    { 
             printf("\n Government_monthly_resetting");
                
    }
    #endif 
        
    return 0;
}

/* \fn: int Government_yearly_budget_accounting()
 * \brief Function to perform accounting at the end of each year.
 */
int Government_yearly_budget_accounting()
{
    double in, out;

    //Compute the following:
   // GOV_INTEREST_RATE = 0.05;
    //GOV_INTEREST_RATE = CB_BASE_RATE;

    //Items that have already been added to the payment_account
        in = YEARLY_TAX_REVENUES;
        YEARLY_INCOME = in;
        
    //Items that have already been subtracted from the payment_account
        out = YEARLY_BENEFIT_PAYMENT +
        YEARLY_TRANSFER_PAYMENT +
        YEARLY_BOND_INTEREST_PAYMENT +
        YEARLY_INVESTMENT_EXPENDITURE +
        YEARLY_CONSUMPTION_EXPENDITURE;
        
        YEARLY_EXPENDITURE = out;
        
    //Compute budget deficit
        YEARLY_BUDGET_BALANCE = in - out;
                
    return 0;
}

/* \fn: int Government_yearly_resetting()
 * \brief Yearly resetting of counters.
 */
int Government_yearly_resetting()
{
    //Reset the yearly counters:
    YEARLY_TAX_REVENUES =0.0;
    YEARLY_BENEFIT_PAYMENT =0.0;
    YEARLY_TRANSFER_PAYMENT =0.0;
    YEARLY_SUBSIDY_PAYMENT =0.0;
    YEARLY_BOND_INTEREST_PAYMENT =0.0;
    YEARLY_INVESTMENT_EXPENDITURE =0.0;
    YEARLY_CONSUMPTION_EXPENDITURE =0.0;
    
    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_GOV)
    { 
        printf("\n Government_yearly_resetting");       
    }
    #endif 
    
    return 0;
}

/* \fn: int Government_read_data_from_Eurostat()
 * \brief Function to read data from Eurostat.
 */
int Government_read_data_from_Eurostat()
{
    int i;
    double old_gdp;
    
    old_gdp=GDP;
    GDP=0.0;
    COUNTRY_WIDE_MEAN_WAGE=0.0;
    
    START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
        for (i=0; i<NO_REGIONS_PER_GOV; i++)
        {
            if(data_for_government_message->region_id==LIST_OF_REGIONS.array[i])
            {
                //Read region mean wage
                COUNTRY_WIDE_MEAN_WAGE += data_for_government_message->mean_wage;
                //Read region GDP
                GDP += data_for_government_message->gdp;
            }
        }
    FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
    
    //Set country-wide mean wage as avg of region's mean wages
    if(NO_REGIONS_PER_GOV>0)
        COUNTRY_WIDE_MEAN_WAGE = COUNTRY_WIDE_MEAN_WAGE/NO_REGIONS_PER_GOV;
    else
        printf("\n Please set constant NO_REGIONS_PER_GOV>0, now NO_REGIONS_PER_GOV = %d\n", NO_REGIONS_PER_GOV);
        
        
    //Set GDP growth rate
    if (old_gdp > 0.0)
        GDP_GROWTH = (GDP/old_gdp) -1;
    else GDP_GROWTH = 0.0; 

    #ifdef _DEBUG_MODE        
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\n Government_read_data_from_Eurostat ID: %d",ID);
        printf("\n\t GDP: %f old GDP: %f",GDP,old_gdp);
        getchar();
    }
    #endif 
        
    
    //Now read the global economic data to retrieve the economy-wide inflation and unemployment rates:    
    START_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP    
        INFLATION_RATE = eurostat_send_macrodata_message->inflation;
        UNEMPLOYMENT_RATE = eurostat_send_macrodata_message->unemployment_rate;
    FINISH_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP
    
    return 0;   
}

/* \fn: int Government_set_policy()
 * \brief Function to set policy rules: income forecast and expenditure budget.
 */
int Government_set_policy()
{   

//    double yearly_tax_revenues_target; 
/*     
    //Fiscal policy rule 1

        //increase tax rates when in debt
        if(PAYMENT_ACCOUNT<0)
        {
            TAX_RATE_CORPORATE  += 0.01;
            TAX_RATE_HH_LABOUR  += 0.01; 
            TAX_RATE_HH_CAPITAL += 0.01;
        }
        else if(PAYMENT_ACCOUNT>1000)
        {
            //decrease tax rates when in surplus
            TAX_RATE_CORPORATE  -= 0.01;
            TAX_RATE_HH_LABOUR  -= 0.01; 
            TAX_RATE_HH_CAPITAL -= 0.01;
        }
*/
        //Fiscal policy rule 2
/*
        //increase tax rates when GDP growth > 0.05
        if(GDP_GROWTH>0.05)
        {
            TAX_RATE_CORPORATE  += 0.01;
            TAX_RATE_HH_LABOUR  += 0.01; 
            TAX_RATE_HH_CAPITAL += 0.01;
        }
        else if(GDP_GROWTH<0.01)
        {
            //decrease tax rates when GDP growth < 0.01
            TAX_RATE_CORPORATE  -= 0.01;
            TAX_RATE_HH_LABOUR  -= 0.01; 
            TAX_RATE_HH_CAPITAL -= 0.01;
        }
*/
    
    //Set GDP forecast equal to extrapolation of previous growth rate*GDP
    GDP_FORECAST = (1+GDP_GROWTH)*GDP;
    
    //Set income forecast
    YEARLY_INCOME_FORECAST = (1+GDP_GROWTH)*YEARLY_INCOME;

    //Set expenditure forecast: counter-cyclical to gdp growth
    YEARLY_EXPENDITURE_BUDGET = (1+GDP_GROWTH)*YEARLY_EXPENDITURE;
    
    BUDGET_BALANCE_FORECAST = YEARLY_INCOME_FORECAST - YEARLY_EXPENDITURE_BUDGET;
    
    //Set the following policies:

    //Determine new government consumption
     YEARLY_CONSUMPTION_BUDGET = GOV_POLICY_GDP_FRACTION_CONSUMPTION * GDP_FORECAST;    
     MONTHLY_CONSUMPTION_BUDGET = YEARLY_CONSUMPTION_BUDGET/12;
     
    //Determine new government investment
     YEARLY_INVESTMENT_BUDGET = GOV_POLICY_GDP_FRACTION_INVESTMENT * GDP_FORECAST;
     MONTHLY_INVESTMENT_BUDGET = YEARLY_INVESTMENT_BUDGET/12;

    if ((POLICY_EXP1)&&(GOV_POLICY_SWITCH_QUANTITATIVE_EASING==0))
    {                   
                
        if ( (YEARLY_BUDGET_BALANCE+PAYMENT_ACCOUNT)>0)
        {
             TAX_RATE_HH_LABOUR = TAX_RATE_HH_LABOUR - 0.05;
             TAX_RATE_CORPORATE = TAX_RATE_CORPORATE - 0.05;
             }
             else
        {
             TAX_RATE_HH_LABOUR = TAX_RATE_HH_LABOUR + 0.05;
             TAX_RATE_CORPORATE = TAX_RATE_CORPORATE + 0.05;
             }
        if (TAX_RATE_HH_LABOUR<0.05) TAX_RATE_HH_LABOUR = 0.05;
        if (TAX_RATE_CORPORATE<0.05) TAX_RATE_CORPORATE = 0.05;
      }
         
    return 0;
}
