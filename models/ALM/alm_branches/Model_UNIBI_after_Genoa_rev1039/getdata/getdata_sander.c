#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************************
* Struct Type Definitions            *
*************************************/

struct firm
{
    int id;
    int region_id;
    double wage_offer;
    double technology;
    int no_employees;
    int vacancies;
    double average_g_skill;

    double production_quantity;
    double capital_stock;
    double revenue;
    double earnings;
    double price;
    double price_last_month;
    double mean_specific_skills;

    double total_sold_quantity;
    double planned_production_quantity;
    double account;
    double mean_wage;

    struct firm * next;
};

struct household
{
    int id;
    int region_id;
    int employee_firm_id;
    int employer_region_id;
    int general_skill;
    double specific_skill;
    double wage;
    double wage_reservation;
    double demand;
    double savings;

    struct household * next;
};

struct mall
{
    int id;
    int region_id;
    double total_supply;

    struct mall * next;


};

struct IGfirm
{
    int id;
    int region_id;
    double productivity;
    double revenue_per_day; 

    struct IGfirm * next;

};

struct Eurostat
{
    int id;
    double gdp;
    double total_earnings;
    double total_debt;
    double total_assets;
    double total_equity;
    double average_debt_earnings_ratio;
    double average_debt_equity_ratio;
    double labour_share_ratio;
  
	double monthly_sold_quantity;
    double monthly_output;
	double monthly_revenue;
	double monthly_planned_output;

    struct Eurostat * next;

};

//double monthly_output=0.0;
double monthly_output_region_1 = 0.0;
double monthly_output_region_2 = 0.0;
double monthly_sold_quantity = 0.0;
double monthly_sold_quantity_region_1 = 0.0;
double monthly_sold_quantity_region_2 = 0.0;
double monthly_revenue = 0.0;
double monthly_revenue_region_1 = 0.0;
double monthly_revenue_region_2 = 0.0;
double cum_total_stock = 0.0;
double monthly_planned_production_quantity = 0.0;
double monthly_planned_production_quantity_region_1 = 0.0;
double monthly_planned_production_quantity_region_2 = 0.0;
double monthly_savings = 0.0;
double monthly_savings_region_1 = 0.0;
double monthly_savings_region_2 = 0.0;
double monthly_account = 0.0;
double monthly_account_region_1 = 0.0;
double monthly_account_region_2 = 0.0;
double sold_quantity_firm[10]={0,0,0,0,0,0,0,0,0,0};
double monthly_output_last_month;
double mean_technology_last_month;
double prod_vol_reg1;
double prod_vol_reg2;
double prod_vol;

typedef struct firm firm;
typedef struct household household;

typedef struct mall mall;
typedef struct IGfirm IGfirm;
typedef struct Eurostat Eurostat;

/*****************************************************************
* FUNCTIONS: linked list functions                               *
* PURPOSE: to allocate and free memory in linked lists           *
*****************************************************************/
void freefirms(firm * head)
{
    /* Tempory element needed for loop */
    firm * tmp;

    /* Loop while head is not NULL */
    while(head)
    {
        /* Make next in list tmp */
        tmp = head->next;
        /* Free memory of head */
        free(head);
        /* Make head the next in the list */
        head = tmp;
    }
}

void freehouseholds(household * head)
{
    /* Tempory element needed for loop */
    household * tmp;
    
    /* Loop while head is not NULL */
    while(head)
    {
        /* Make next in list tmp */
        tmp = head->next;
        /* Free memory of head */
        free(head);
        /* Make head the next in the list */
        head = tmp;
    }
}

void freemalls(mall * head)
{
    /* Tempory element needed for loop */
    mall * tmp;

    /* Loop while head is not NULL */
    while(head)
    {
        /* Make next in list tmp */
        tmp = head->next;
        /* Free memory of head */
        free(head);
        /* Make head the next in the list */
        head = tmp;
    }
}

void freeIGfirms(IGfirm * head)
{
    /* Tempory element needed for loop */
    IGfirm * tmp;

    /* Loop while head is not NULL */
    while(head)
    {
        /* Make next in list tmp */
        tmp = head->next;
        /* Free memory of head */
        free(head);
        /* Make head the next in the list */
        head = tmp;
    }
}

void freeEurostats(Eurostat * head)
{
    /* Tempory element needed for loop */
    Eurostat * tmp;

    /* Loop while head is not NULL */
    while(head)
    {
        /* Make next in list tmp */
        tmp = head->next;
        /* Free memory of head */
        free(head);
        /* Make head the next in the list */
        head = tmp;
    }
}

firm * addfirm(firm ** pointer_to_firms, firm * current)
{
    /* The new tail of the linked list */
    firm * tail;

    /* Allocate memory for new neighbour data */

    tail = (firm *)malloc(sizeof(firm));

    /* Check if current is not NULL */
    if(current)
    {
        /* Current exists therefore make its next point to tail */
        current->next = tail;
    }
    else
    {
        /* Current is NULL therefore make the cell neighbour_head point to tail */
        *pointer_to_firms = tail;
    }
    /* Point next to NULL */
    tail->next = NULL;
    /* Return new neighbour data */
    return tail;
}

household * addhousehold(household ** pointer_to_households, household * current)
{
    /* The new tail of the linked list */
    household * tail;

    /* Allocate memory for new neighbour data */

    tail = (household *)malloc(sizeof(household));

    /* Check if current is not NULL */
    if(current)
    {
        /* Current exists therefore make its next point to tail */
        current->next = tail;
    }
    else
    {
        /* Current is NULL therefore make the cell<name>Firm neighbour_head point to tail */
        *pointer_to_households = tail;
    }
    /* Point next to NULL */
    tail->next = NULL;
    /* Return new neighbour data */
    return tail;
}

mall * addmall(mall ** pointer_to_malls, mall * current)
{
    /* The new tail of the linked list */
    mall * tail;

    /* Allocate memory for new neighbour data */

    tail = (mall *)malloc(sizeof(mall));

    /* Check if current is not NULL */
    if(current)
    {
        /* Current exists therefore make its next point to tail */
        current->next = tail;
    }
    else
    {
        /* Current is NULL therefore make the cell neighbour_head point to tail */
        *pointer_to_malls = tail;
    }
    /* Point next to NULL */
    tail->next = NULL;
    /* Return new neighbour data */
    return tail;
}

IGfirm * addIGfirm(IGfirm ** pointer_to_IGfirms, IGfirm * current)
{
    /* The new tail of the linked list */
    IGfirm * tail;

    /* Allocate memory for new neighbour data */

    tail = (IGfirm *)malloc(sizeof(IGfirm));

    /* Check if current is not NULL */
    if(current)
    {
        /* Current exists therefore make its next point to tail */
        current->next = tail;
    }
    else
    {
        /* Current is NULL therefore make the cell neighbour_head point to tail */
        *pointer_to_IGfirms = tail;
    }
    /* Point next to NULL */
    tail->next = NULL;
    /* Return new neighbour data */
    return tail;
}

Eurostat * addEurostat(Eurostat ** pointer_to_Eurostats, Eurostat * current)
{
    /* The new tail of the linked list */
    Eurostat * tail;

    /* Allocate memory for new neighbour data */

    tail = (Eurostat *)malloc(sizeof(Eurostat));

    /* Check if current is not NULL */
    if(current)
    {
        /* Current exists therefore make its next point to tail */
        current->next = tail;
    }
    else
    {
        /* Current is NULL therefore make the cell neighbour_head point to tail */
        *pointer_to_Eurostats = tail;
    }
    /* Point next to NULL */
    tail->next = NULL;
    /* Return new neighbour data */
    return tail;
}

/* Print all cell data */
/*void printagentdata(xmachine ** pointer_to_cells)
{
    xmachine * current;
    
    current = *pointer_to_cells;

    printf("Cell Data\n");
    while(current)
    {
        printf("cell:%d\txp:%f\ty:%f\tz:%f\n", current->id, current->x, current->y, current->z);
        current = current->next;
    }

    printf("\n");
}*/

/*****************************************************************
* FUNCTION: getIteration                                         *
* PURPOSE: read iteration xml file                               *
*****************************************************************/
int getiteration(char * filepath, int itno, firm ** pointer_to_firms, household ** pointer_to_households, IGfirm ** pointer_to_IGfirms, mall ** pointer_to_malls, Eurostat ** pointer_to_Eurostats)
{
    /* Pointer to file */
    FILE *file;
    /* Char and char buffer for reading file to */
    char c = ' ';
    char buffer[100000];
    /* Variable to keep reading file */
    int reading = 1;

    /* Variables for checking tags */
    int i, instate, intag, initeration, inagent, inid, inregion_id, inname, ina;
    /*Firm*/
    int inwage_offer, intechnology, inno_employees, invacancies, inaverage_g_skill;
    int inproduction_quantity, incapital_stock, inrevenue, inearnings, inprice;
    int intotal_sold_quantity, inplanned_production_quantity, inaccount, inprice_last_month, inmean_specific_skills, inmean_wage;
    /*Household*/
    int  inwage, inwage_reservation, ingeneral_skill, inspecific_skill, inemployee_firm_id;
    int inemployer_region_id, insavings;

    /*Mall*/
    int intotal_supply;

    /*IGFirm*/
    int inproductivity, inrevenue_per_day;

    /*Eurostat*/
    int ingdp, intotal_earnings, intotal_debt, intotal_assets, intotal_equity;
    int inaverage_debt_earnings_ratio, inaverage_debt_equity_ratio, inlabour_share_ratio;
    int inmonthly_sold_quantity, inmonthly_output, inmonthly_revenue, inmonthly_planned_output;
    
    /* Variables for model data */
    int state, id, region_id;

    /*Firm*/
    int  no_employees, vacancies; 
    double wage_offer, technology, average_g_skill, production_quantity, capital_stock;
    double revenue, earnings, price, total_sold_quantity, planned_production_quantity;
    double account,  price_last_month, mean_specific_skills,  mean_wage;

    /*Household*/
    int  general_skill, employee_firm_id, employer_region_id;
    double a, wage, wage_reservation, specific_skill, savings;

    /*Mall*/
    double total_supply;

    /*IGFirm*/
    double productivity, revenue_per_day;

    /*Eurostat*/
    double gdp, total_earnings, total_debt, total_assets, total_equity;
    double average_debt_earnings_ratio, average_debt_equity_ratio, labour_share_ratio;
    double monthly_sold_quantity, monthly_output, monthly_revenue, monthly_planned_output;
    
    char name[100];
    
    firm * current_firm, * tail_firm;
    tail_firm = *pointer_to_firms;
    current_firm = NULL;
    
    household * current_household, * tail_household;
    tail_household = *pointer_to_households;
    current_household = NULL;
    
    mall * current_mall, * tail_mall;
    tail_mall = *pointer_to_malls;
    current_mall = NULL;

    IGfirm * current_IGfirm, * tail_IGfirm;
    tail_IGfirm = *pointer_to_IGfirms;
    current_IGfirm = NULL;
    
    Eurostat * current_Eurostat, * tail_Eurostat;
    tail_Eurostat = *pointer_to_Eurostats;
    current_Eurostat = NULL;

    /* Open config file to read-only */
    char data[200];
    sprintf(data, "%s%i%s", filepath, itno, ".xml");
    printf("%s", data);
    if((file = fopen(data, "r"))==NULL)
    {
        printf(" Getdata.c reached last xml file in sequence \n");
        return 0;
        /*exit(0);*/
    }
    else
    {

    printf("\n");
    /* Initialise variables */
    i = 0;
    instate = 0;
    intag = 0;
    initeration = 0;
    inagent = 0;
    inname = 0;
    inid = 0;
    inregion_id = 0;
    ina = 0;
    /*Firm*/
    inwage_offer = 0;
    intechnology = 0;
    inno_employees = 0;
    invacancies = 0;
    inaverage_g_skill = 0;
    inproduction_quantity = 0;
    incapital_stock = 0;
    inrevenue = 0;
    inearnings = 0;
    inprice = 0;
    inmean_wage=0;
    intotal_sold_quantity = 0;
    inplanned_production_quantity = 0;
    inaccount  = 0;
    inprice_last_month=0;
    inmean_specific_skills=0;
    /*Household*/
    inwage = 0;
    inwage_reservation = 0;
    ingeneral_skill = 0;
    inspecific_skill =0;
    inemployee_firm_id = 0;
    inemployer_region_id = 0;
    insavings = 0.0;
    /*Mall*/
    intotal_supply =0;
    /*IGFirm*/
    inproductivity=0;
    inrevenue_per_day=0;
    /*Eurostat*/
    ingdp =0;
    intotal_earnings =0;
    intotal_debt =0;
    intotal_assets =0;
    intotal_equity =0;
    inaverage_debt_earnings_ratio =0;
    inaverage_debt_equity_ratio =0;
    inlabour_share_ratio =0;
    
    inmonthly_sold_quantity =0;
    inmonthly_output =0;
    inmonthly_revenue =0;
    inmonthly_planned_output =0;

    state = 0;
    id = 0;
    region_id = 0;
    a = 0.0;
    
    wage_offer = 0.0;
    technology = 0.0;
    no_employees = 0;
    vacancies = 0;
    average_g_skill = 0.0;
    production_quantity = 0.0;
    capital_stock = 0.0;
    revenue = 0;
    earnings = 0;
    price = 0;
    total_sold_quantity = 0.0;
    planned_production_quantity = 0.0;
    account = 0.0;
    price_last_month=0.0;
    mean_specific_skills=0.0;
    mean_wage=0;
    
    wage = 0.0;
    wage_reservation = 0.0;
    general_skill = 0;
    specific_skill = 0.0;
    employee_firm_id = 0;
    employer_region_id = 0;
    savings = 0.0;
        
    total_supply =0;
        
    inproductivity=0;
    revenue_per_day=0;
        
    /*Eurostat*/
    gdp =0.0;
    total_earnings =0.0;
    total_debt =0.0;
    total_assets =0.0;
    total_equity =0.0;
    average_debt_earnings_ratio =0.0;
    average_debt_equity_ratio =0.0;
    labour_share_ratio =0.0;    
    
    monthly_sold_quantity =0.0;
    monthly_output =0.0;
    monthly_revenue =0.0;
    monthly_planned_output =0.0;

    /* Read characters until the end of the file */
    /*while(c != EOF)*/
    /* Read characters until end of xml found */
    while(reading == 1)
    {
        /* Get the next char from the file */
        c = fgetc(file);
        
        //printf("%c", c);
        
        /* If the end of a tag */
        if(c == '>')
        {
            /* Place 0 at end of buffer to make chars a string */
            buffer[i] = 0;
            if(strcmp(buffer, "states") == 0) { initeration = 1; }
            if(strcmp(buffer, "/states") == 0) { initeration = 0; reading = 0; }
            if(strcmp(buffer, "xagent") == 0) { inagent = 1; }
            if(strcmp(buffer, "/xagent") == 0)
            {
                inagent = 0;
                
                //printf("Found agent ... ");
                
                if(strcmp(name, "Firm") == 0)
                {
                    //printf("Adding agent\n");
                    
                    /* check if tail is NULL */
                    if(tail_firm == NULL)
                    {
                        //printf("tail is null allocate more memory\n");
                        /* Allocate memory */
                        tail_firm = addfirm(pointer_to_firms, current_firm);
                    }
                    //else printf("tail exisits\n");
                    
                    /* Make tail the current element to add to */
                    current_firm = tail_firm;
                    
                    current_firm->id = id;
                    current_firm->region_id = region_id;
                    current_firm->wage_offer = wage_offer;
                    current_firm->technology = technology;
                    current_firm->no_employees = no_employees;
                    current_firm->vacancies = vacancies;
                    current_firm->average_g_skill = average_g_skill;
                    current_firm->production_quantity = production_quantity;
                    current_firm->capital_stock = capital_stock;
                    current_firm->revenue = revenue;
                    current_firm->earnings = earnings;
                    current_firm->mean_wage = mean_wage;
                    current_firm->price = price;
                    current_firm->total_sold_quantity = total_sold_quantity;
                    current_firm->planned_production_quantity = planned_production_quantity;
                    current_firm->account = account;
                    current_firm->price_last_month=price_last_month;
                    current_firm->mean_specific_skills=mean_specific_skills;
                    
                    
                    
                    
                    //printf("Firm %d, ", id);
                    
                    /* Make tail the next element in the linked list */
                    tail_firm = current_firm->next;
                }
                
                if(strcmp(name, "Household") == 0)
                {
                    //printf("Adding agent\n");
                    
                    /* check if tail is NULL */
                    if(tail_household == NULL)
                    {
                        //printf("tail is null allocate more memory\n");
                        /* Allocate memory */
                        tail_household = addhousehold(pointer_to_households, current_household);
                    }
                    //else printf("tail exisits\n");
                    
                    /* Make tail the current element to add to */
                    current_household = tail_household;
                    
                    current_household->id = id;
                    current_household->region_id = region_id;
                    current_household->wage = wage;
                    current_household->wage_reservation = wage_reservation;
                    current_household->general_skill = general_skill;
                    current_household->specific_skill = specific_skill;
                    current_household->employee_firm_id = employee_firm_id;
                    current_household->employer_region_id = employer_region_id;
                    current_household->savings = savings;
                    
                    //printf("Household %d, ", id);
                    
                    /* Make tail the next element in the linked list */
                    tail_household = current_household->next;
                }
                
            
            if(strcmp(name, "Mall") == 0)
                {
                    //printf("Adding agent\n");
                    
                    /* check if tail is NULL */
                    if(tail_mall == NULL)
                    {
                        //printf("tail is null allocate more memory\n");
                        /* Allocate memory */
                        tail_mall = addmall(pointer_to_malls, current_mall);
                    }
                    //else printf("tail exisits\n");
                    
                    /* Make tail the current element to add to */
                    current_mall = tail_mall;
                    
                    current_mall->id = id;
                    current_mall->region_id = region_id;
                    current_mall->total_supply =total_supply;
                    
                    
                    
                    
                    
                    //printf("mall %d, ", id);
                    
                    /* Make tail the next element in the linked list */
                    tail_mall = current_mall->next;
                }
            


            if(strcmp(name, "IGFirm") == 0)
                {
                    //printf("Adding agent\n");
                    
                    /* check if tail is NULL */
                    if(tail_IGfirm == NULL)
                    {
                        //printf("tail is null allocate more memory\n");
                        /* Allocate memory */
                        tail_IGfirm = addIGfirm(pointer_to_IGfirms, current_IGfirm);
                    }
                    //else printf("tail exisits\n");
                    
                    /* Make tail the current element to add to */
                    current_IGfirm = tail_IGfirm;
                    
                    current_IGfirm->id = id;
                    current_IGfirm->region_id = region_id;
                    current_IGfirm->productivity = productivity;
                    current_IGfirm->revenue_per_day = revenue_per_day;
                    
                    
                    
                    
                    
                    //printf("IGfirm %d, ", id);
                    
                    /* Make tail the next element in the linked list */
                    tail_IGfirm = current_IGfirm->next;
                }
            if(strcmp(name, "Eurostat") == 0)
                {
                    //printf("Adding agent\n");
                    
                    /* check if tail is NULL */
                    if(tail_Eurostat == NULL)
                    {
                        //printf("tail is null allocate more memory\n");
                        /* Allocate memory */
                        tail_Eurostat = addEurostat(pointer_to_Eurostats, current_Eurostat);
                    }
                    //else printf("tail exisits\n");
                    
                    /* Make tail the current element to add to */
                    current_Eurostat = tail_Eurostat;
                    
                    current_Eurostat->id                         = id;
                    current_Eurostat->gdp                        = gdp;
                    current_Eurostat->total_earnings             = total_earnings;
                    current_Eurostat->total_debt                 = total_debt;
                    current_Eurostat->total_assets               = total_assets;
                    current_Eurostat->total_equity               = total_equity;
                    current_Eurostat->average_debt_earnings_ratio= average_debt_earnings_ratio;
                    current_Eurostat->average_debt_equity_ratio  = average_debt_equity_ratio;
                    current_Eurostat->labour_share_ratio         = labour_share_ratio;

                    current_Eurostat->monthly_sold_quantity      = monthly_sold_quantity;
                    current_Eurostat->monthly_output             = monthly_output;
                    current_Eurostat->monthly_revenue            = monthly_revenue;
                    current_Eurostat->monthly_planned_output     = monthly_planned_output;

                    //printf("Eurostat %d, ", id);
                    
                    /* Make tail the next element in the linked list */
                    tail_Eurostat = current_Eurostat->next;
                }

            
            
            //else printf("Not adding agent\n");
            }
            if(strcmp(buffer, "name") == 0) { inname = 1; }
            if(strcmp(buffer, "/name") == 0) { inname = 0; }
            if(strcmp(buffer, "id") == 0) { inid = 1; }
            if(strcmp(buffer, "/id") == 0) { inid = 0; }
            if(strcmp(buffer, "region_id") == 0) { inregion_id = 1; }
            if(strcmp(buffer, "/region_id") == 0) { inregion_id = 0; }
            
            if(strcmp(buffer, "wage_offer") == 0) { inwage_offer = 1; }
            if(strcmp(buffer, "/wage_offer") == 0) { inwage_offer = 0; }
            if(strcmp(buffer, "technology") == 0) { intechnology = 1; }
            if(strcmp(buffer, "/technology") == 0) { intechnology = 0; }
            if(strcmp(buffer, "mean_wage") == 0) { inmean_wage = 1; }
            if(strcmp(buffer, "/mean_wage") == 0) { inmean_wage = 0; }
            if(strcmp(buffer, "no_employees") == 0) { inno_employees = 1; }
            if(strcmp(buffer, "/no_employees") == 0) { inno_employees = 0; }
            if(strcmp(buffer, "vacancies") == 0) { invacancies = 1; }
            if(strcmp(buffer, "/vacancies") == 0) { invacancies = 0; }
            if(strcmp(buffer, "average_g_skill") == 0) { inaverage_g_skill = 1; }
            if(strcmp(buffer, "/average_g_skill") == 0) { inaverage_g_skill = 0; }
            if(strcmp(buffer, "production_quantity") == 0) { inproduction_quantity = 1; }
            if(strcmp(buffer, "/production_quantity") == 0) { inproduction_quantity = 0; }

            if(strcmp(buffer, "mean_specific_skills") == 0) { inmean_specific_skills = 1; }
            if(strcmp(buffer, "/mean_specific_skills") == 0) { inmean_specific_skills = 0; }
            if(strcmp(buffer, "capital_stock") == 0) { incapital_stock = 1; }
            if(strcmp(buffer, "/capital_stock") == 0) { incapital_stock = 0; }
            if(strcmp(buffer, "revenue") == 0) { inrevenue = 1; }
            if(strcmp(buffer, "/revenue") == 0) { inrevenue = 0; }
            if(strcmp(buffer, "earnings") == 0) { inearnings = 1; }
            if(strcmp(buffer, "/earnings") == 0) { inearnings = 0; }
            
            if(strcmp(buffer, "price_last_month") == 0) { inprice_last_month = 1; }
            if(strcmp(buffer, "/price_last_month") == 0) { inprice_last_month = 0; }

            if(strcmp(buffer, "price") == 0) { inprice = 1; }
            if(strcmp(buffer, "/price") == 0) { inprice = 0; }
             if(strcmp(buffer, "total_sold_quantity") == 0) { intotal_sold_quantity = 1; }
             if(strcmp(buffer, "/total_sold_quantity") == 0) { intotal_sold_quantity = 0; }
             if(strcmp(buffer, "planned_production_quantity") == 0) { inplanned_production_quantity = 1; }
             if(strcmp(buffer, "/planned_production_quantity") == 0) { inplanned_production_quantity = 0; }
            if(strcmp(buffer, "account") == 0) { inaccount = 1; }
            if(strcmp(buffer, "/account") == 0) { inaccount = 0; }

        

            if(strcmp(buffer, "wage") == 0) { inwage = 1; }
            if(strcmp(buffer, "/wage") == 0) { inwage = 0; }
            if(strcmp(buffer, "wage_reservation") == 0) { inwage_reservation = 1; }
            if(strcmp(buffer, "/wage_reservation") == 0) { inwage_reservation = 0; }
            if(strcmp(buffer, "general_skill") == 0) { ingeneral_skill = 1; }
            if(strcmp(buffer, "/general_skill") == 0) { ingeneral_skill = 0; }
            if(strcmp(buffer, "specific_skill") == 0) { inspecific_skill = 1; }
            if(strcmp(buffer, "/specific_skill") == 0) { inspecific_skill = 0; }
            if(strcmp(buffer, "employee_firm_id") == 0) { inemployee_firm_id = 1; }
            if(strcmp(buffer, "/employee_firm_id") == 0) { inemployee_firm_id = 0; }
                if(strcmp(buffer, "employer_region_id") == 0) { inemployer_region_id = 1; }
               if(strcmp(buffer, "/employer_region_id") == 0) { inemployer_region_id = 0; }
            if(strcmp(buffer, "savings") == 0) { insavings = 1; }
            if(strcmp(buffer, "/savings") == 0) { insavings = 0; }


            if(strcmp(buffer, "total_supply") == 0) { intotal_supply = 1; }
               if(strcmp(buffer, "/total_supply") == 0) { intotal_supply = 0; }
            if(strcmp(buffer, "productivity") == 0) { inproductivity = 1; }
               if(strcmp(buffer, "/productivity") == 0) { inproductivity= 0; }  
            if(strcmp(buffer, "revenue_per_day") == 0) { inrevenue_per_day = 1; }
               if(strcmp(buffer, "/revenue_per_day") == 0) { inrevenue_per_day= 0; }    
            
            if(strcmp(buffer, "gdp") == 0) { ingdp = 1; }
               if(strcmp(buffer, "/gdp") == 0) { ingdp= 0; }    
            if(strcmp(buffer, "total_earnings") == 0) { intotal_earnings = 1; }
               if(strcmp(buffer, "/total_earnings") == 0) { intotal_earnings= 0; }  
            if(strcmp(buffer, "total_debt") == 0) { intotal_debt = 1; }
               if(strcmp(buffer, "/total_debt") == 0) { intotal_debt= 0; }  
            if(strcmp(buffer, "total_assets") == 0) { intotal_assets = 1; }
               if(strcmp(buffer, "/total_assets") == 0) { intotal_assets= 0; }  
            if(strcmp(buffer, "total_equity") == 0) { intotal_equity = 1; }
               if(strcmp(buffer, "/total_equity") == 0) { intotal_equity= 0; }  
            if(strcmp(buffer, "average_debt_earnings_ratio") == 0) { inaverage_debt_earnings_ratio = 1; }
               if(strcmp(buffer, "/average_debt_earnings_ratio") == 0) { inaverage_debt_earnings_ratio= 0; }    
            if(strcmp(buffer, "average_debt_equity_ratio") == 0) { inaverage_debt_equity_ratio = 1; }
               if(strcmp(buffer, "/average_debt_equity_ratio") == 0) { inaverage_debt_equity_ratio= 0; }    
            if(strcmp(buffer, "labour_share_ratio") == 0) { inlabour_share_ratio = 1; }
               if(strcmp(buffer, "/labour_share_ratio") == 0) { inlabour_share_ratio= 0; }  
               
           if(strcmp(buffer, "monthly_sold_quantity") == 0) { inmonthly_sold_quantity = 1; }
              if(strcmp(buffer, "/monthly_sold_quantity") == 0) { inmonthly_sold_quantity= 0; }  
           if(strcmp(buffer, "monthly_output") == 0) { inmonthly_output = 1; }
              if(strcmp(buffer, "/monthly_output") == 0) { inmonthly_output= 0; }    
           if(strcmp(buffer, "monthly_revenue") == 0) { inmonthly_revenue = 1; }
              if(strcmp(buffer, "/monthly_revenue") == 0) { inmonthly_revenue= 0; }    
           if(strcmp(buffer, "monthly_planned_output") == 0) { inmonthly_planned_output = 1; }
              if(strcmp(buffer, "/monthly_planned_output") == 0) { inmonthly_planned_output= 0; }  
                             
            /* End of tag and reset buffer */
            intag = 0;
            i = 0;
        }
        /* If start of tag */
        else if(c == '<')
        {
            /* Place /0 at end of buffer to end numbers */
            buffer[i] = 0;
            /* Flag in tag */
            intag = 1;
            /* If just read data into buffer retrieve it */
            if(inagent && inname)  { strcpy(name, buffer); }
            if(inagent && inid) { id = atoi(buffer); }
            if(inagent && inregion_id) { region_id = atoi(buffer); }
            

            if(inagent && inwage_offer)  { wage_offer  = atof(buffer); }
            if(inagent && intechnology)  { technology  = atof(buffer); }
            if(inagent && inno_employees)  { no_employees  = atoi(buffer); }
            if(inagent && invacancies)  { vacancies  = atof(buffer); }
            if(inagent && inaverage_g_skill)  { average_g_skill  = atof(buffer); }
            if(inagent && inproduction_quantity)  { production_quantity  = atof(buffer); }

            if(inagent && inmean_wage)  { mean_wage = atof(buffer); }
            if(inagent && incapital_stock)  { capital_stock  = atof(buffer); }
            if(inagent && inrevenue)  { revenue  = atof(buffer); }
            if(inagent && inearnings)  { earnings  = atof(buffer); }
            if(inagent && inprice)  { price  = atof(buffer); }
            if(inagent && intotal_sold_quantity)  { total_sold_quantity  = atof(buffer); }
            if(inagent && inplanned_production_quantity)  { planned_production_quantity  = atof(buffer); }
            if(inagent && inaccount)  { account  = atof(buffer); }
            if(inagent && inprice_last_month)  { price_last_month  = atof(buffer); }
            if(inagent && inmean_specific_skills)  { mean_specific_skills  = atof(buffer); }
            
            if(inagent && inwage)  { wage  = atof(buffer); }
            if(inagent && inwage_reservation)  { wage_reservation  = atof(buffer); }
            if(inagent && ingeneral_skill)  { general_skill  = atoi(buffer); }
            if(inagent && inspecific_skill)  { specific_skill  = atof(buffer); }
            if(inagent && inemployee_firm_id)  { employee_firm_id = atoi(buffer); }
            if(inagent && inemployer_region_id)  { employer_region_id = atoi(buffer); }
            if(inagent && insavings)  { savings  = atof(buffer); }
            
            if(inagent && inrevenue_per_day)  {revenue_per_day  = atof(buffer); }
            if(inagent && inproductivity)  { productivity  = atof(buffer); }
            if(inagent && intotal_supply)  { total_supply  = atof(buffer); }
                
            if(inagent && ingdp)  { gdp  = atof(buffer); }
            if(inagent && intotal_earnings)  { total_earnings  = atof(buffer); }
            if(inagent && intotal_debt)  { total_debt  = atof(buffer); }
            if(inagent && intotal_assets)  { total_assets  = atof(buffer); }
            if(inagent && intotal_equity)  { total_equity  = atof(buffer); }
            if(inagent && inaverage_debt_earnings_ratio)  { average_debt_earnings_ratio  = atof(buffer); }
            if(inagent && inaverage_debt_equity_ratio)  { average_debt_equity_ratio  = atof(buffer); }
            if(inagent && inlabour_share_ratio)  { labour_share_ratio  = atof(buffer); }
            
            if(inagent && inmonthly_sold_quantity)  { monthly_sold_quantity  = atof(buffer); }
            if(inagent && inmonthly_output)  { monthly_output  = atof(buffer); }
            if(inagent && inmonthly_revenue)  { monthly_revenue  = atof(buffer); }
            if(inagent && inmonthly_planned_output)  { monthly_planned_output  = atof(buffer); }
                        
            /* Reset buffer */
            i = 0;
        }
        /* If in tag put read char into buffer */
        else if(intag)
        {
            buffer[i] = c;
            i++;
        }
        /* If in data read char into buffer */
        else// if(inname || inid || ina || inproductivity || inprice || insold || inproduction || inwage || insavings || infirmid || inworkers)
        {
            buffer[i] = c;
            i++;
        }
    }
    
    /* Free memory for unused linked list elements */
    if(tail_firm)
    {
        freefirms(tail_firm);
        /* Make pointer to tail equal NULL */
        if(current_firm) { current_firm->next = NULL; }
    }
    
    /* Free memory for unused linked list elements */
    if(tail_household)
    {
        freehouseholds(tail_household);
        /* Make pointer to tail equal NULL */
        if(current_household) { current_household->next = NULL; }
    }

    if(tail_mall)
    {
        freemalls(tail_mall);
        /* Make pointer to tail equal NULL */
        if(current_mall) { current_mall->next = NULL; }
    }

    if(tail_IGfirm)
    {
        freeIGfirms(tail_IGfirm);
        /* Make pointer to tail equal NULL */
        if(current_IGfirm) { current_IGfirm->next = NULL; }
    }

    if(tail_Eurostat)
    {
        freeEurostats(tail_Eurostat);
        /* Make pointer to tail equal NULL */
        if(current_Eurostat) { current_Eurostat->next = NULL; }
    }

    /* Close the file */
    fclose(file);
    
    /*printagentdata(pointer_to_cells);*/
    
    return 1;
    }
}

void savedatatofile(int itno, firm ** pointer_to_firms, household ** pointer_to_households,IGfirm ** pointer_to_IGfirms, mall ** pointer_to_malls, Eurostat ** pointer_to_Eurostats)
{
    FILE *file;
    char data[100];
    firm * current_firm;
    household * current_household;
    IGfirm * current_IGfirm;
    mall* current_mall;
    Eurostat* current_Eurostat;
    
    current_firm = *pointer_to_firms;
    current_household = *pointer_to_households;
    current_mall = *pointer_to_malls;
    current_IGfirm = *pointer_to_IGfirms;
    current_Eurostat = *pointer_to_Eurostats;

    double ave_wage = 0.0;
    double ave_wage_region_1 = 0.0;
    double ave_wage_region_2 = 0.0;
    double ave_wage_skill_group_1 = 0.0;
    double ave_wage_skill_group_2 = 0.0;
    double ave_wage_skill_group_3 = 0.0;
    double ave_wage_skill_group_4 = 0.0;
    double ave_wage_skill_group_5 = 0.0;
    double ave_wage_reservation = 0;
    double ave_wage_reservation_region_1 = 0;
    double ave_wage_reservation_region_2 = 0;
    double ave_wage_reservation_1 = 0;
    double ave_wage_reservation_2 = 0;
    double ave_wage_reservation_3 = 0;
    double ave_wage_reservation_4 = 0;
    double ave_wage_reservation_5 = 0;

    double ave_wage_skill_1_region_1 =0;
    double ave_wage_skill_2_region_1 =0;
    double ave_wage_skill_3_region_1 =0;
    double ave_wage_skill_4_region_1 =0;
    double ave_wage_skill_5_region_1 =0;
    double ave_wage_skill_1_region_2 =0;
    double ave_wage_skill_2_region_2 =0;
    double ave_wage_skill_3_region_2 =0;
    double ave_wage_skill_4_region_2 =0;
    double ave_wage_skill_5_region_2 =0;
    
    

    double employed = 0;
    double employed_same_region = 0;
    double employed_different_region = 0;
    double employed_region_1 = 0;
    double employed_region_2 = 0;
    double employed_region_1_live_region_1 = 0;
    double employed_region_1_live_region_2 = 0;
    double employed_region_2_live_region_1 = 0;
    double employed_region_2_live_region_2 = 0;
    double employed_skill_group_1 = 0;
    double employed_skill_group_2 = 0;
    double employed_skill_group_3 = 0;
    double employed_skill_group_4 = 0;
    double employed_skill_group_5 = 0;

    double unemployed = 0;
    double unemployed_skill_group_1 = 0;
    double unemployed_skill_group_2 = 0;
    double unemployed_skill_group_3 = 0;
    double unemployed_skill_group_4 = 0;
    double unemployed_skill_group_5 = 0;

    double ave_savings = 0.0;
    double ave_savings_region_1 = 0.0;
    double ave_savings_region_2 = 0.0;
    
    double ave_no_employees = 0;
    double ave_no_employees_region_1 = 0;
    double ave_no_employees_region_2 = 0;
    double ave_vacancies = 0;
    double ave_vacancies_region_1 = 0;
    double ave_vacancies_region_2 = 0;
    double vacancies = 0;
    double v_u_ratio = 0;
    
    double no_firms = 0;
    double no_firms_region_1 = 0.0;
    double no_firms_region_2 = 0.0;
    double no_households = 0;
    double no_households_skill_group_1 = 0;
    double no_households_skill_group_2 = 0;
    double no_households_skill_group_3 = 0;
    double no_households_skill_group_4 = 0;
    double no_households_skill_group_5 = 0;
    double no_households_region_1 = 0;
    double no_households_region_2 = 0;
    double no_hh_skill_1_region_1 = 0;
    double no_hh_skill_2_region_1 = 0;
    double no_hh_skill_3_region_1 = 0;
    double no_hh_skill_4_region_1 = 0;
    double no_hh_skill_5_region_1 = 0;
    double no_hh_skill_1_region_2 = 0;
    double no_hh_skill_2_region_2 = 0;
    double no_hh_skill_3_region_2 = 0;
    double no_hh_skill_4_region_2 = 0;
    double no_hh_skill_5_region_2 = 0;

    double ave_g_skill = 0;
    double ave_g_skill_region_1 = 0;
    double ave_g_skill_region_2 = 0;
    
    double ave_production_quantity = 0.0;
    double ave_production_quantity_region_1 = 0.0;
    double ave_production_quantity_region_2 = 0.0;
    double ave_capital_stock = 0;
    double ave_capital_stock_region_1 = 0;
    double ave_capital_stock_region_2 = 0;
    double ave_revenue = 0;
    double ave_revenue_region_1 = 0;
    double ave_revenue_region_2 = 0;
    double ave_earnings = 0;
    double ave_earnings_region_1 = 0;
    double ave_earnings_region_2 = 0;
    double ave_price = 0;
    double ave_total_sold_quantity = 0;
    double ave_total_sold_quantity_region_1 = 0;
    double ave_total_sold_quantity_region_2 = 0;
    double ave_planned_production_quantity = 0.0;
    double ave_planned_production_quantity_region_1 = 0.0;
    double ave_planned_production_quantity_region_2 = 0.0;
    double ave_account = 0.0;
    double ave_account_region_1 = 0.0;
    double ave_account_region_2 = 0.0;
    double ave_technology = 0.0;
    double ave_technology_region_1 = 0.0;
    double ave_technology_region_2 = 0.0;
    double ave_mean_specific_skills_region_1=0.0;
    double ave_mean_specific_skills_region_2=0.0;
    double ave_mean_specific_skills =0.0;

    double ave_price_reg1 =0.0;
    double ave_price_reg2 =0.0;

    double ave_wage_offer = 0.0;
    double ave_wage_offer_region_1 = 0.0;
    double ave_wage_offer_region_2 = 0.0;
    double no_employer = 0.0;
    double no_employer_region_1 = 0.0;
    double no_employer_region_2 = 0.0;

    double economywide_total_supply=0;
    double region_1_total_supply = 0.0;
    double region_2_total_supply = 0.0;
    double technological_frontier = 0.0;

    double mean_wage_region_1_firm = 0;
    double mean_wage_region_2_firm = 0;
    
    double last_prices[10];
    double prices[10];  
    double market_share[10];
    double employees[10];

    double technology[10];
    
    //Eurostat:
    double gdp;
    double total_earnings;
    double total_debt;
    double total_assets;
    double total_equity;
    double average_debt_earnings_ratio;
    double average_debt_equity_ratio;
    double labour_share_ratio;

    double monthly_sold_quantity;
    double monthly_output;
    double monthly_revenue;
    double monthly_planned_output;

    
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------HOUSEHOLDS------DAILY DATA---------------------------------------*/
    
    current_household = *pointer_to_households;
    while(current_household)
    {
        no_households++;
        
        ave_wage_reservation += current_household->wage_reservation;
        ave_savings += current_household->savings;
        ave_mean_specific_skills+=current_household->specific_skill;
        

        if(current_household->region_id == 1)
            {
                no_households_region_1++;
                
                ave_savings_region_1 += current_household->savings;
            ave_wage_reservation_region_1 += current_household->wage_reservation;
            }
            else
            {
                no_households_region_2++;
                
                ave_savings_region_2 += current_household->savings;
            ave_wage_reservation_region_2 += current_household->wage_reservation;
            }
        
        if(current_household->employee_firm_id != -1) 
        {
            employed++;
            ave_wage += current_household->wage;

            if(1 == current_household->region_id)
            {
                ave_wage_region_1 += current_household->wage;
            }
            else
            {
                ave_wage_region_2 += current_household->wage;
            }

            if(current_household->employer_region_id == 1)
            {
                employed_region_1++;
                
            }
            else
            {
                employed_region_2++;
                
            }           

            if(current_household->region_id == current_household->employer_region_id)
            {
                employed_same_region++;

                if(current_household->employer_region_id == 1)
                {
                    employed_region_1_live_region_1++;
                }
                else
                {
                    employed_region_2_live_region_2++;
                }
            }
            else
            {
                employed_different_region++;

                if(current_household->employer_region_id == 1)
                {
                    employed_region_1_live_region_2++;
                }

                else
                {
                    employed_region_2_live_region_1++;
                }
            }

        }

        if(current_household->general_skill == 1) 
        {
            no_households_skill_group_1++;
            if(current_household->employee_firm_id != -1)
            {   
                employed_skill_group_1++;
                ave_wage_skill_group_1 += current_household->wage;
            }

            ave_wage_reservation_1 += current_household->wage_reservation;      
        }

        if(current_household->general_skill == 2) 
        {
            no_households_skill_group_2++;
            if(current_household->employee_firm_id != -1)
            {   
                employed_skill_group_2++;
                ave_wage_skill_group_2 += current_household->wage;
            }

        ave_wage_reservation_2 += current_household->wage_reservation;      
        }

        if(current_household->general_skill == 3) 
        {
            no_households_skill_group_3++;
            if(current_household->employee_firm_id != -1)
            {   
                employed_skill_group_3++;
                ave_wage_skill_group_3 += current_household->wage;
            }

            ave_wage_reservation_3 += current_household->wage_reservation;      
        }

        if(current_household->general_skill == 4) 
        {
            no_households_skill_group_4++;
            if(current_household->employee_firm_id != -1)
            {   
                employed_skill_group_4++;
                ave_wage_skill_group_4 += current_household->wage;
            }
    
            ave_wage_reservation_4 += current_household->wage_reservation;      
        }

        if(current_household->general_skill == 5) 
        {
            no_households_skill_group_5++;
            if(current_household->employee_firm_id != -1)
            {   
                employed_skill_group_5++;
                ave_wage_skill_group_5 += current_household->wage;
            }

            ave_wage_reservation_5 += current_household->wage_reservation;      
        }


        if(current_household->region_id==1 && current_household->employee_firm_id!=-1)
        {
        if(current_household->general_skill == 1)
        {
            no_hh_skill_1_region_1++;
            ave_wage_skill_1_region_1+= current_household->wage;
        
        }
        if(current_household->general_skill == 2)
        {
            no_hh_skill_2_region_1++;
            ave_wage_skill_2_region_1+= current_household->wage;
        
        }
        if(current_household->general_skill == 3)
        {
            no_hh_skill_3_region_1++;
            ave_wage_skill_3_region_1+= current_household->wage;
        
        }
        if(current_household->general_skill == 4)
        {
            no_hh_skill_4_region_1++;
            ave_wage_skill_4_region_1+= current_household->wage;
        
        }
        if(current_household->general_skill == 5)
        {
            no_hh_skill_5_region_1++;
            ave_wage_skill_5_region_1+= current_household->wage;
        
        }

    }
    
    if(current_household->region_id==2 && current_household->employee_firm_id!=-1)
    {
        if(current_household->general_skill == 1)
        {
            no_hh_skill_1_region_2++;
            ave_wage_skill_1_region_2+= current_household->wage;
        
        }
        if(current_household->general_skill == 2)
        {
            no_hh_skill_2_region_2++;
            ave_wage_skill_2_region_2+= current_household->wage;
        
        }
        if(current_household->general_skill == 3)
        {
            no_hh_skill_3_region_2++;
            ave_wage_skill_3_region_2+= current_household->wage;
        
        }
        if(current_household->general_skill == 4)
        {
            no_hh_skill_4_region_2++;
            ave_wage_skill_4_region_2+= current_household->wage;
        
        }
        if(current_household->general_skill == 5)
        {
            no_hh_skill_5_region_2++;
            ave_wage_skill_5_region_2+= current_household->wage;
        
        }

    }



        current_household = current_household->next;
    }

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------HOUSEHOLDS------MONTHLY DATA---------------------------------------*/
        
    monthly_savings = ave_savings;
    monthly_savings_region_1 = ave_savings_region_1;
    monthly_savings_region_2 = ave_savings_region_2;
    
    

    if(itno%20 == 0)
    {
        file = fopen("data-monthly-savings.csv", "a");

        sprintf(data, "%i", itno);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", monthly_savings);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", monthly_savings_region_1);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", monthly_savings_region_2);
        fputs(data, file);
        fputs("\n", file);

        fclose(file);


        file = fopen("data-specific-skills-hh.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_mean_specific_skills/no_households);
    fputs(data, file);
    
    fputs("\n", file);

    fclose(file);

        
        
    }

    
    
    file = fopen("data-wage.csv", "a");
    
    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage/employed);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_group_1/employed_skill_group_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_group_2/employed_skill_group_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_group_3/employed_skill_group_3);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_group_4/employed_skill_group_4);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_group_5/employed_skill_group_5);
    fputs(data, file);
    fputs("\n", file);
    
    fclose(file);



    file = fopen("data-region-wage.csv", "a");
    
    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage/employed);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_region_1/(employed_region_1_live_region_1+employed_region_2_live_region_1));
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_region_2/(employed_region_2_live_region_2+employed_region_1_live_region_2));
    fputs(data, file);
    fputs("\n", file);
    
    fclose(file);

    file = fopen("data-wage-reg1.csv", "a");
    
    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_region_1/(employed_region_1_live_region_1+employed_region_2_live_region_1));
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_1_region_1/no_hh_skill_1_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_2_region_1/no_hh_skill_2_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_3_region_1/no_hh_skill_3_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_4_region_1/no_hh_skill_4_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_5_region_1/no_hh_skill_5_region_1);
    fputs(data, file);
    fputs("\n", file);
    
    fclose(file);

    file = fopen("data-wage-reg2.csv", "a");
    
    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_region_2/(employed_region_1_live_region_2+employed_region_2_live_region_2));
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_1_region_2/no_hh_skill_1_region_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_2_region_2/no_hh_skill_2_region_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_3_region_2/no_hh_skill_3_region_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_4_region_2/no_hh_skill_4_region_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_skill_5_region_2/no_hh_skill_5_region_2);
    fputs(data, file);
    fputs("\n", file);
    
    fclose(file);

    /*wage reservation*/
    file = fopen("data-r-wage.csv", "a");
    
    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_reservation/no_households);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_reservation_1/no_households_skill_group_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_reservation_2/no_households_skill_group_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_reservation_3/no_households_skill_group_3);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_reservation_4/no_households_skill_group_4);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_reservation_5/no_households_skill_group_5);
    fputs(data, file);
    fputs("\n", file);
    
    fclose(file);



    /*Employment region data*/
    file = fopen("data-region.csv", "a");
    
    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", employed);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", employed_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", employed_region_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", employed_region_1_live_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", employed_region_1_live_region_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", employed_region_2_live_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", employed_region_2_live_region_2);
    fputs(data, file);
    fputs("\n", file);
    
    fclose(file);



    /*Unemployment Data*/
    file = fopen("data-unemployment.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", (1-employed/no_households));
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", (1-employed_skill_group_1/no_households_skill_group_1));
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", (1-employed_skill_group_2/no_households_skill_group_2));
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", (1-employed_skill_group_3/no_households_skill_group_3));
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", (1-employed_skill_group_4/no_households_skill_group_4));
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", (1-employed_skill_group_5/no_households_skill_group_5));
    fputs(data, file);
    fputs("\n", file);

    fclose(file);


    /*Unemployment Data*/
    file = fopen("data-region-unemployment.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", (1-employed/no_households));
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", 1-(employed_region_1_live_region_1+employed_region_2_live_region_1)/no_households_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", 1-(employed_region_2_live_region_2+employed_region_1_live_region_2)/no_households_region_2);
    fputs(data, file);
    fputs("\n", file);

    fclose(file);

    
    


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------MALLS-------------- DATA---------------------------------------*/

    current_mall = *pointer_to_malls;
    while(current_mall)
    {
        
        
        economywide_total_supply += current_mall->total_supply;

        if(1== current_mall->region_id)
        {
            region_1_total_supply = current_mall->total_supply;
        }
        else
        {
            region_2_total_supply = current_mall->total_supply;
        }
        current_mall = current_mall->next;
        //printf("Ew TS: %f \n",economywide_total_supply);
        
    }

    
    file = fopen("data-daily_supply.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", economywide_total_supply );
    fputs(data, file);

    fputs("\n", file);

    fclose(file);


    
    current_IGfirm = *pointer_to_IGfirms;

    technological_frontier =  current_IGfirm->productivity ;

    file = fopen("data-technological-frontier.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", current_IGfirm->productivity );
    fputs(data, file);

    fputs("\n", file);

    fclose(file);

    file = fopen("data-IGfirm-revenues.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", current_IGfirm->revenue_per_day );
    fputs(data, file);

    fputs("\n", file);

    fclose(file);


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------FIRMS DAILY AND REGIONAL DATA-------------------------------------*/
    current_firm = *pointer_to_firms;
    while(current_firm)
    {
        no_firms++;
        
        ave_no_employees += current_firm->no_employees;
        ave_vacancies += current_firm->vacancies;
        ave_g_skill += current_firm->average_g_skill;
        ave_production_quantity += current_firm->production_quantity;
        ave_capital_stock += current_firm->capital_stock;
        ave_revenue += current_firm->revenue;
        ave_earnings += current_firm->earnings;
        ave_price += current_firm->price;
        ave_wage_offer += current_firm->wage_offer;
        ave_total_sold_quantity += current_firm->total_sold_quantity;
        ave_planned_production_quantity += current_firm->planned_production_quantity;
        ave_account += current_firm->account;
        if(current_firm->no_employees >0)
        ave_technology += current_firm->technology*current_firm->production_quantity;
        

        if(1== current_firm->region_id)
        {
            no_firms_region_1++;

        ave_no_employees_region_1 += current_firm->no_employees;
        ave_vacancies_region_1 += current_firm->vacancies;
        ave_g_skill_region_1 += current_firm->average_g_skill;  
        ave_production_quantity_region_1 += current_firm->production_quantity;
        ave_capital_stock_region_1 += current_firm->capital_stock;
        ave_revenue_region_1 += current_firm->revenue;
        ave_earnings_region_1 += current_firm->earnings;
        ave_wage_offer_region_1 += current_firm->wage_offer;    
        ave_total_sold_quantity_region_1 += current_firm->total_sold_quantity;
        ave_planned_production_quantity_region_1 += current_firm->planned_production_quantity;
        ave_account_region_1 += current_firm->account;

        mean_wage_region_1_firm +=current_firm->mean_wage*current_firm->production_quantity;

        ave_price_reg1 += current_firm->price*current_firm->production_quantity;
        if(current_firm->no_employees >0)
        {
        ave_technology_region_1 += current_firm->technology*current_firm->production_quantity;
        ave_mean_specific_skills_region_1 += current_firm->mean_specific_skills*current_firm->production_quantity;
        }
        }
        else
        {
            no_firms_region_2++;

        ave_no_employees_region_2 += current_firm->no_employees;
        ave_vacancies_region_2 += current_firm->vacancies;
        ave_g_skill_region_2 += current_firm->average_g_skill;
        ave_production_quantity_region_2 += current_firm->production_quantity;
        ave_capital_stock_region_2 += current_firm->capital_stock;
        ave_revenue_region_2 += current_firm->revenue;
        ave_earnings_region_2 += current_firm->earnings;
        ave_wage_offer_region_2 += current_firm->wage_offer;            
        ave_total_sold_quantity_region_2 += current_firm->total_sold_quantity;
        ave_planned_production_quantity_region_2 += current_firm->planned_production_quantity;
        ave_account_region_2 += current_firm->account;
        ave_price_reg2 += current_firm->price*current_firm->production_quantity;
        mean_wage_region_2_firm +=current_firm->mean_wage*current_firm->production_quantity;

        if(current_firm->no_employees >0)
        {
        ave_technology_region_2 += current_firm->technology*current_firm->production_quantity;
        ave_mean_specific_skills_region_2 += current_firm->mean_specific_skills*current_firm->production_quantity;
        }
        }
        
        if(current_firm->no_employees > 0)
        {
            no_employer +=1;
            
            if(current_firm->region_id == 1)
            {
                no_employer_region_1 +=1;
            }
            else
            {
                no_employer_region_2 +=1;
            }
        }


        int i;
        for(i=0; i<10;i++)
        {
        if(i+1 == current_firm->id)
        {
        last_prices[i] = current_firm->price_last_month;
        sold_quantity_firm[i]+=current_firm->total_sold_quantity;
        prices[i]=current_firm->price;
        technology[i]=current_firm->technology;
        employees[i] = current_firm->no_employees;
        }
        }
        
        current_firm = current_firm->next;
    }

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------FIRM MONTHLY AND REGIONAL DATA---------------------------------------*/
        monthly_sold_quantity += ave_total_sold_quantity;
        monthly_sold_quantity_region_1 += ave_total_sold_quantity_region_1;
        monthly_sold_quantity_region_2 += ave_total_sold_quantity_region_2;
//        monthly_output += ave_production_quantity;
        monthly_output_region_1 += ave_production_quantity_region_1;
        monthly_output_region_2 += ave_production_quantity_region_2;
        monthly_revenue += ave_revenue;
        monthly_revenue_region_1 += ave_revenue_region_1;
        monthly_revenue_region_2 += ave_revenue_region_2;
        monthly_planned_production_quantity += ave_planned_production_quantity;
        monthly_planned_production_quantity_region_1 += ave_planned_production_quantity_region_1;
        monthly_planned_production_quantity_region_2 += ave_planned_production_quantity_region_2;
        monthly_account = ave_account;
        monthly_account_region_1 = ave_account_region_1;
        monthly_account_region_2 = ave_account_region_2;
        
        //printf("A = %f \n", monthly_account);
        
        //Changed from 1 into 0: monthly data is now send at end of month, on days 20, 40, etc.
        if(itno%20 == 0)
        {
            file = fopen("data-monthly-output.csv", "a");

            sprintf(data, "%i", itno);
            fputs(data, file);
//            fputs("\t", file);
//            sprintf(data, "%f", monthly_output);
//            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_sold_quantity);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", economywide_total_supply);
            fputs(data, file);
            fputs("\n", file);

            fclose(file);

            if(itno>20)
            {
            file = fopen("data-growthrate-output.csv", "a");
            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", (monthly_output - monthly_output_last_month)/monthly_output_last_month);
            fputs(data, file);
            fputs("\n", file);
            fclose(file);
            
            file = fopen("data-regional-price.csv", "a");
            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", ave_price_reg1/monthly_output_region_1);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", ave_price_reg2/monthly_output_region_2);
            fputs(data, file);
            fputs("\n", file);
            fclose(file);

            file = fopen("data-regional-wage-firm.csv", "a");
            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", mean_wage_region_1_firm/monthly_output_region_1);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", mean_wage_region_2_firm/monthly_output_region_2);
            fputs(data, file);
            fputs("\n", file);
            fclose(file);

            file = fopen("data-growthrate-technology.csv", "a");
            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", (ave_technology -  mean_technology_last_month)/mean_technology_last_month);
            fputs(data, file);
            fputs("\n", file);
            fclose(file);
            
            }
            
            mean_technology_last_month = ave_technology;
            monthly_output_last_month=monthly_output;
            file = fopen("data-region-monthly-output.csv", "a");

            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_output);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_sold_quantity);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", economywide_total_supply);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_output_region_1);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_sold_quantity_region_1);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", region_1_total_supply);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_output_region_2);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_sold_quantity_region_2);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", region_2_total_supply);
            fputs(data, file);
            
            fputs("\n", file);

            fclose(file);



            file = fopen("data-planned-output.csv", "a");

            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_output);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_planned_production_quantity);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_output_region_1);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_planned_production_quantity_region_1);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_output_region_2);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_planned_production_quantity_region_2);
            fputs(data, file);
            fputs("\n", file);

            fclose(file);



            file = fopen("data-monthly-account.csv", "a");

            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_account);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_account_region_1);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", monthly_account_region_2);
            fputs(data, file);
            fputs("\n", file);

            fclose(file);

            file = fopen("data-firm-technology.csv", "a");

            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[0]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[1]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[2]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[3]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[4]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[5]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[6]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[7]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[8]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technology[9]);
            fputs(data, file);
            fputs("\n", file);

            fclose(file);


            file = fopen("data-firm-employees.csv", "a");

            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[0]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[1]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[2]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[3]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[4]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[5]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[6]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[7]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[8]);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", employees[9]);
            fputs(data, file);
            fputs("\n", file);

            fclose(file);


            


            current_firm = *pointer_to_firms;
    
            int i;
            for(i=0; i<10;i++)
            {
                market_share[i]=sold_quantity_firm[i]/monthly_sold_quantity;
            }

            double sum_1=0.0;
            double sum_2=0.0;
            double sum_3=0.0;
        
            for( i=0;i<10; i++)
            {
                sum_1+= (prices[i]*market_share[i]); 
                sum_2+=last_prices[i]*market_share[i];
                sold_quantity_firm[i]=0;
                sum_3 += (market_share[i]*market_share[i]);
            }

            double price_index = sum_1/sum_2;
            double herfindahl = sum_3;
            double inflation_rate = (sum_1 - sum_2)/sum_2;
            
        
            file = fopen("data-price-index.csv", "a");

            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", price_index);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", herfindahl);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", inflation_rate*100);
            fputs(data, file);
            fputs("\n", file);

            fclose(file);
    
            prod_vol=monthly_output;
            prod_vol_reg1=monthly_output_region_1;
            prod_vol_reg2=monthly_output_region_2;
        
//            monthly_output = 0.0;
            monthly_output_region_1 = 0.0;
            monthly_output_region_2 = 0.0;


            file = fopen("mean_specific_skills_region.csv", "a");

            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", ave_mean_specific_skills_region_1/prod_vol_reg1);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f",ave_mean_specific_skills_region_2/prod_vol_reg2);
            fputs(data, file);
            fputs("\n", file);
        
            fclose(file);
        
                    
            file = fopen("data-technology.csv", "a");
        
            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", ave_technology/prod_vol);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", ave_technology_region_1/prod_vol_reg1);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", ave_technology_region_2/prod_vol_reg2);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", technological_frontier);
            fputs(data, file);
            fputs("\n", file);
        
            fclose(file);
            monthly_sold_quantity = 0.0;
            monthly_sold_quantity_region_1 = 0.0;
            monthly_sold_quantity_region_2 = 0.0;
            monthly_revenue = 0.0;
            monthly_revenue_region_1 = 0.0;
            monthly_revenue_region_2 = 0.0;
            monthly_planned_production_quantity = 0.0;
            monthly_planned_production_quantity_region_1 = 0.0;
            monthly_planned_production_quantity_region_2 = 0.0;
            monthly_account = 0.0;
            monthly_account_region_1 = 0.0;
            monthly_account_region_2 = 0.0;
            
        }
        

        
    /*Output*/
    
    

    file = fopen("data-employees.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_vacancies/no_employer);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_no_employees/no_employer);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_vacancies_region_1/no_employer_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_no_employees_region_1/no_employer_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_vacancies_region_2/no_employer_region_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_no_employees_region_2/no_employer_region_2);
    fputs(data, file);
    fputs("\n", file);

    fclose(file);

    /*Output*/
    file = fopen("data-output.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_production_quantity);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_total_sold_quantity);
    fputs(data, file);
    fputs("\n", file);

    fclose(file);

    /*capital*/
    file = fopen("data-capital.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_capital_stock);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_capital_stock_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_capital_stock_region_2);
    fputs(data, file);
    fputs("\n", file);

    fclose(file);

    /*earnings, revenue*/
    file = fopen("data-revenue.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_revenue);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_earnings);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_revenue_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_earnings_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_revenue_region_2);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_earnings_region_2);
    fputs(data, file);
    fputs("\t", file);
    fputs("\n", file);

    fclose(file);

    /*price*/
    file = fopen("data-price.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_price/no_employer);
    fputs(data, file);  
    fputs("\n", file);

    fclose(file);


    file = fopen("data-wage-offer.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_offer/no_firms);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_offer_region_1/no_firms_region_1);
    fputs(data, file);
    fputs("\t", file);
    sprintf(data, "%f", ave_wage_offer_region_2/no_firms_region_2);
    fputs(data, file);
    fputs("\n", file);

    fclose(file);


    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
    /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    /*----------------------------EUROSTAT MONTHLY AND REGIONAL DATA---------------------------------------*/

    current_Eurostat = *pointer_to_Eurostats;

    while(current_Eurostat)
    {
        //Set local variables
        gdp = current_Eurostat->gdp;
        total_earnings = current_Eurostat->total_earnings;
        total_debt =  current_Eurostat->total_debt;
        total_assets = current_Eurostat->total_assets;
        total_equity = current_Eurostat->total_equity;
        average_debt_earnings_ratio = current_Eurostat->average_debt_earnings_ratio;
        average_debt_equity_ratio = current_Eurostat->average_debt_equity_ratio;
        labour_share_ratio = current_Eurostat->labour_share_ratio;
        
        monthly_sold_quantity = current_Eurostat->monthly_sold_quantity;
        monthly_output = current_Eurostat->monthly_output;
        monthly_revenue = current_Eurostat->monthly_revenue;
        monthly_planned_output = current_Eurostat->monthly_planned_output;

        //Go to the next in linked list
        current_Eurostat = current_Eurostat->next;
        
    }
    //Write data to file
    //1: in case firms determine their new balance sheet on day 21 
    //01: in case firms determine their new balance sheet on day 20
    if(itno%20 == 0)
        {

            file = fopen("data-eurostat.csv", "a");

            sprintf(data, "%i", itno);
            fputs(data, file);
            fputs("\t", file);
            
            sprintf(data, "%f", gdp);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", total_earnings);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", total_debt);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", total_assets);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", total_equity);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", average_debt_earnings_ratio);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", average_debt_equity_ratio);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", labour_share_ratio);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", monthly_sold_quantity);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", monthly_output);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", monthly_revenue);
            fputs(data, file);

            fputs("\t", file);
            sprintf(data, "%f", monthly_planned_output);
            fputs(data, file);

            fputs("\n", file);
            fclose(file);
        }
            
}

int main( int argc, char **argv )
{
    int position = 0;
    int lastd = 0;
    int i;
    char * filepath;
    firm * firms, * current_firm;
    household * households, * current_household;
    IGfirm * IGfirms, * current_IGfirm;
    mall * malls, * current_mall;
    Eurostat * Eurostats, * current_Eurostat;
    
    firm ** p_firms;
    household ** p_households;
    IGfirm ** p_IGfirms;
    mall ** p_malls;
    Eurostat ** p_Eurostats;
    
    int iteration_number = 0;
    int stilldata = 1;
    int lastread = 0;



    FILE *file;
    
    //file = fopen("data-v-u.csv", "w");
    //fclose(file);
    
    file = fopen("data-wage.csv", "w");
    fclose(file);

    file = fopen("data-r-wage.csv", "w");
    fclose(file);

    file = fopen("data-wage-offer.csv", "w");
    fclose(file);
    
    file = fopen("data-output.csv", "w");
    fclose(file);
    
    file = fopen("mean_specific_skills_region.csv", "w");
    fclose(file);   

    file = fopen("data-unemployment.csv", "w");
    fclose(file);

    file = fopen("data-employees.csv", "w");
    fclose(file);

    file = fopen("data-revenue.csv", "w");
    fclose(file);

    file = fopen("data-capital.csv", "w");
    fclose(file);

    file = fopen("data-price.csv", "w");
    fclose(file);

    file = fopen("data-wage-reg1.csv", "w");
    fclose(file);

    file = fopen("data-wage-reg2.csv", "w");
    fclose(file);

    file = fopen("data-regional-wage-firm.csv", "w");
    fclose(file);

    file = fopen("data-growthrate-technology.csv", "w");
    fclose(file);

    file = fopen("data-growthrate-output.csv", "w");
    fclose(file);

    file = fopen("data-region.csv", "w");
    fclose(file);

    file = fopen("data-monthly-output.csv", "w");
    fclose(file);
    
    file = fopen("data-technological-frontier.csv", "w");
    fclose(file);
    
    file = fopen("data-IGfirm-revenues.csv", "w");
    fclose(file);

    file = fopen("data-daily_supply.csv", "w");
    fclose(file);

    file = fopen("data-planned-output.csv", "w");
    fclose(file);

    file = fopen("data-specific-skills-hh.csv", "w");
    fclose(file);

    file = fopen("data-monthly-account.csv", "w");
    fclose(file);

    file = fopen("data-region-monthly-output.csv", "w");
    fclose(file);

    file = fopen("data-monthly-savings.csv", "w");
    fclose(file);

    file = fopen("data-price-index.csv", "w");
    fclose(file);

    file = fopen("data-regional-price.csv", "w");
    fclose(file);

    file = fopen("data-region-unemployment.csv", "w");
    fclose(file);

    file = fopen("data-technology.csv", "w");
    fclose(file);

    file = fopen("data-region-wage.csv", "w");
    fclose(file);

    file = fopen("data-firm-technology.csv", "w");
    fclose(file);

    file = fopen("data-firm-employees.csv", "w");
    fclose(file);
    
    file = fopen("data-eurostat.csv", "w");
    fclose(file);

    /* Read initial states of x-machines */
    /* advance argument pointer to next argument */
    *argv++;
    if(*argv == NULL)
    {
        printf("No intial states defined\n");
        exit(0);
    }
    printf("Initial states: %s\n", *argv);
    /*readinitialstates(*argv, p_iteration_number, p_xmemory);*/
    while(**argv != 0)
    {
        /* For windows directories */
        if(**argv == '\\') lastd=position;
        /* For windows directories */
        if(**argv == '/') lastd=position;
        (*argv)++;
        position++;
    }
    for(i=position; i>0; i--)
    {
        if(i==lastd+1) **argv = 0;
        (*argv)--;
    }
    filepath = *argv;
    printf("Ouput dir: %s\n", filepath);
    
    /* Initialise pointers */
    firms = NULL;
    p_firms = &firms;
    
    households = NULL;
    p_households = &households;

    IGfirms = NULL;
    p_IGfirms = &IGfirms;
    
    malls = NULL;
    p_malls = &malls;
    
    Eurostats = NULL;
    p_Eurostats = &Eurostats;

    while(iteration_number - lastread < 241) //frequency+1
    {
        stilldata = getiteration(filepath, iteration_number, p_firms, p_households, p_IGfirms, p_malls, p_Eurostats);
        
        if(stilldata)
        {
         savedatatofile(iteration_number, p_firms, p_households, p_IGfirms, p_malls, p_Eurostats);
         lastread = iteration_number;
        }
        iteration_number++;
        
        /*
        current = *p_agents;
        
        printf("Cell Data\n");
        while(current)
        {
            printf("cell:%d\ts:%d\tt:%d\n", current->id, current->state, current->type);
            current = current->next;
        }
        
        printf("\n");
        */
    }
    
    /* Should never get here */
    return( 0 );
}
