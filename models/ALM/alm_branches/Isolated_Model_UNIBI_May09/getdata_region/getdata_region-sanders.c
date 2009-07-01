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
    double payment_account_firm;
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
    double payment_account;

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



/*Defining structs to store regional data*/
struct Household_data
{
    double region_id;
    double no_households;
    double no_households_skill_1;
    double no_households_skill_2;
    double no_households_skill_3;
    double no_households_skill_4;
    double no_households_skill_5;
    double employed;
    double employed_skill_1;
    double employed_skill_2;
    double employed_skill_3;
    double employed_skill_4;
    double employed_skill_5;
    double average_specific_skill;
    double average_wage;
    double average_wage_skill_1;
    double average_wage_skill_2;
    double average_wage_skill_3;
    double average_wage_skill_4;
    double average_wage_skill_5;
    double commuter;
    double foreign_commuter;
    double average_payment_account;
    
        
};
typedef struct Household_data Household_data;


struct Mall_data
{
    double region_id;
    double supply;
};
typedef struct Mall_data Mall_data;

struct Firm_data
{
    double region_id;
    double no_firms;
    double no_employees;
    double vacancies;
    double average_wage;
    double average_technology;
    double average_specific_skill;
    double average_general_skill;
    double production_quantity;
    double sold_quantity;
    double average_payment_account;
    double average_price;
    double capital_stock;
    double earnings;
    double revenues;
    double planned_production_quantity;
    double production_quantity_last_month;
    double average_technology_last_month;
    
};
typedef struct Firm_data Firm_data;




typedef struct firm firm;
typedef struct household household;

typedef struct mall mall;
typedef struct IGfirm IGfirm;

double last_production[10];
double last_technology[10];



    
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
int getiteration(char * filepath, int itno, firm ** pointer_to_firms, household ** pointer_to_households,IGfirm ** pointer_to_IGfirms,mall ** pointer_to_malls)
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
    int intotal_sold_quantity, inplanned_production_quantity, inpayment_account_firm, inprice_last_month, inmean_specific_skills, inmean_wage;
    /*Household*/
    int  inwage, inwage_reservation, ingeneral_skill, inspecific_skill, inemployee_firm_id;
    int inemployer_region_id, inpayment_account;

    /*Mall*/
    int intotal_supply;

    /*IGFirm*/
    int inproductivity, inrevenue_per_day;

    /* Variables for model data */
    int state, id, region_id;

    /*Firm*/
    int  no_employees, vacancies; 
    double wage_offer, technology, average_g_skill, production_quantity, capital_stock;
    double revenue, earnings, price, total_sold_quantity, planned_production_quantity;
    double payment_account_firm,  price_last_month, mean_specific_skills,  mean_wage;

    /*Household*/
    int  general_skill, employee_firm_id, employer_region_id;
    double a, wage, wage_reservation, specific_skill, payment_account;

    /*Mall*/
    double total_supply;

    /*IGFirm*/
    double productivity, revenue_per_day;
    
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
    
    /* Open config file to read-only */
    char data[200];
    sprintf(data, "%s%i%s", filepath, itno, ".xml");
    printf("%s", data);
    if((file = fopen(data, "r"))==NULL)
    {
        printf(" nent\n");
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
    inpayment_account_firm  = 0;
    inprice_last_month=0;
    inmean_specific_skills=0;
    /*Household*/
    inwage = 0;
    inwage_reservation = 0;
    ingeneral_skill = 0;
    inspecific_skill =0;
    inemployee_firm_id = 0;
    inemployer_region_id = 0;
    inpayment_account = 0.0;
    /*Mall*/
    intotal_supply =0;
    /*IGFirm*/
    inproductivity=0;
    inrevenue_per_day=0;

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
    payment_account_firm = 0.0;
    price_last_month=0.0;
    mean_specific_skills=0.0;
    mean_wage=0;
    
    wage = 0.0;
    wage_reservation = 0.0;
    general_skill = 0;
    specific_skill = 0.0;
    employee_firm_id = 0;
    employer_region_id = 0;
    payment_account = 0.0;
        
    total_supply =0;
        
    inproductivity=0;
    revenue_per_day=0;
        
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
                    current_firm->payment_account_firm = payment_account;
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
                    current_household->payment_account = payment_account;
                    
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
            if(strcmp(buffer, "total_units_capital_stock") == 0) { incapital_stock = 1; }
            if(strcmp(buffer, "/total_units_capital_stock") == 0) { incapital_stock = 0; }
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
            if(strcmp(buffer, "payment_account") == 0) { inpayment_account_firm = 1; }
            if(strcmp(buffer, "/payment_account") == 0) { inpayment_account_firm = 0; }

        

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
            if(strcmp(buffer, "payment_account") == 0) { inpayment_account = 1; }
            if(strcmp(buffer, "/payment_account") == 0) { inpayment_account = 0; }


            if(strcmp(buffer, "total_supply") == 0) { intotal_supply = 1; }
               if(strcmp(buffer, "/total_supply") == 0) { intotal_supply = 0; }
            if(strcmp(buffer, "productivity") == 0) { inproductivity = 1; }
               if(strcmp(buffer, "/productivity") == 0) { inproductivity= 0; }  
            if(strcmp(buffer, "revenue_per_day") == 0) { inrevenue_per_day = 1; }
               if(strcmp(buffer, "/revenue_per_day") == 0) { inrevenue_per_day= 0; }    
            
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
            if(inagent && inpayment_account_firm)  { payment_account_firm  = atof(buffer); }
            if(inagent && inprice_last_month)  { price_last_month  = atof(buffer); }
            if(inagent && inmean_specific_skills)  { mean_specific_skills  = atof(buffer); }
            
            if(inagent && inwage)  { wage  = atof(buffer); }
            if(inagent && inwage_reservation)  { wage_reservation  = atof(buffer); }
            if(inagent && ingeneral_skill)  { general_skill  = atoi(buffer); }
            if(inagent && inspecific_skill)  { specific_skill  = atof(buffer); }
            if(inagent && inemployee_firm_id)  { employee_firm_id = atoi(buffer); }
            if(inagent && inemployer_region_id)  { employer_region_id = atoi(buffer); }
            if(inagent && inpayment_account)  { payment_account  = atof(buffer); }
            
            if(inagent && inrevenue_per_day)  {revenue_per_day  = atof(buffer); }
            if(inagent && inproductivity)  { productivity  = atof(buffer); }
            if(inagent && intotal_supply)  { total_supply  = atof(buffer); }
                
            
            
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
        else// if(inname || inid || ina || inproductivity || inprice || insold || inproduction || inwage || inpayment_account || infirmid || inworkers)
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
    
    /* Close the file */
    fclose(file);
    
    /*printagentdata(pointer_to_cells);*/
    
    return 1;
    }
}

void savedatatofile(int itno, firm ** pointer_to_firms, household ** pointer_to_households,IGfirm ** pointer_to_IGfirms,mall ** pointer_to_malls)
{
    FILE *file;
    char data[100];
    firm * current_firm;
    household * current_household;
    IGfirm * current_IGfirm;
    mall* current_mall;
    current_firm = *pointer_to_firms;
    current_household = *pointer_to_households;
    current_mall = *pointer_to_malls;
    current_IGfirm = *pointer_to_IGfirms;


    
    /*Count the number of regions*/
    int no_regions;
    if(itno == 0)
    {
        int regions[300];
        int i = 0;
        int n = 0;

        current_household = *pointer_to_households;
        while(current_household)
        {
            regions[i] = current_household->region_id;
            i++;
            if(i > 1)
            {
                for(n = 0; n < i-1; n++)
                {
                    if(current_household->region_id == regions[n])
                    {
                        
                        i--;
                    }
                }
            }

            
            current_household = current_household->next;
        }
        
        no_regions = i;
        
        
    }

    
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------HOUSEHOLDS------DAILY DATA---------------------------------------*/

/*Initialization of the STRUCT Household_data*/
    Household_data Data_Household[no_regions+1];
    
    /*  1:skill level 2:lives in region 3: works in region
    commuters[0][n][o] is the sum over all skill groups. commuters[1][n][o] is for skill group      1 and so on...*/
    int commuters[5+1][no_regions+1][no_regions+1];
        int m,n,o;
        for(m = 0; m <= 5; m++)
        {
            for(n = 1; n <= no_regions; n++)
            {
                for(o = 1; o <= no_regions; o++)
                {
                    commuters[m][n][o] = 0.0;
                }
            }
        }
    
    int i;
    for(i = 0; i <= no_regions; i++)
    {
        Data_Household[i].region_id = i;
        Data_Household[i].no_households = 0.0;
        Data_Household[i].no_households_skill_1 = 0.0;
        Data_Household[i].no_households_skill_2 = 0.0;
        Data_Household[i].no_households_skill_3 = 0.0;
        Data_Household[i].no_households_skill_4 = 0.0;
        Data_Household[i].no_households_skill_5 = 0.0;
        
        Data_Household[i].employed = 0.0;
        Data_Household[i].employed_skill_1 = 0.0;
        Data_Household[i].employed_skill_2 = 0.0;
        Data_Household[i].employed_skill_3 = 0.0;
        Data_Household[i].employed_skill_4 = 0.0;
        Data_Household[i].employed_skill_5 = 0.0;

        Data_Household[i].average_specific_skill = 0.0;

        Data_Household[i].average_wage = 0.0;
        Data_Household[i].average_wage_skill_1 = 0.0;
        Data_Household[i].average_wage_skill_2 = 0.0;
        Data_Household[i].average_wage_skill_3 = 0.0;
        Data_Household[i].average_wage_skill_4 = 0.0;
        Data_Household[i].average_wage_skill_5 = 0.0;

        Data_Household[i].commuter = 0.0;
        Data_Household[i].foreign_commuter = 0.0;
        Data_Household[i].average_payment_account = 0.0;
    }


    
    current_household = *pointer_to_households;
    while(current_household)
    {
        
    /*GLOBAL DATA: Is stored in Data_Household[0]*/
        Data_Household[0].no_households++;
        Data_Household[0].average_specific_skill += current_household->specific_skill;
        Data_Household[0].average_payment_account += current_household->payment_account;
        
        /*If employed*/
        if(current_household->employee_firm_id > -1)
        {
            Data_Household[0].employed++;
            Data_Household[0].average_wage += current_household->wage;
                    
            if(current_household->region_id != current_household->employer_region_id)
            {
                Data_Household[0].commuter++;   
            }
        }
        
        /*Get seperated data for different general skill groups*/
        switch(current_household->general_skill)
        {
            /*If general skill is 1*/
            case 1:
            Data_Household[0].no_households_skill_1++;
            /*If employed*/
            if(current_household->employee_firm_id > -1)
            {
                Data_Household[0].employed_skill_1++;
                Data_Household[0].average_wage_skill_1 +=
                current_household->wage;    
            }
            break;

            case 2:
            Data_Household[0].no_households_skill_2++;
            if(current_household->employee_firm_id > -1)
            {
                Data_Household[0].employed_skill_2++;
                Data_Household[0].average_wage_skill_2 +=
                current_household->wage;    
            }
            break;

            case 3:
            Data_Household[0].no_households_skill_3++;
            if(current_household->employee_firm_id > -1)
            {
                Data_Household[0].employed_skill_3++;
                Data_Household[0].average_wage_skill_3 +=
                current_household->wage;    
            }
            break;

            case 4:
            Data_Household[0].no_households_skill_4++;
            if(current_household->employee_firm_id > -1)
            {
                Data_Household[0].employed_skill_4++;
                Data_Household[0].average_wage_skill_4 +=
                current_household->wage;    
            }
            break;

            case 5:
            Data_Household[0].no_households_skill_5++;
            if(current_household->employee_firm_id > -1)
            {
                Data_Household[0].employed_skill_5++;
                Data_Household[0].average_wage_skill_5 +=
                current_household->wage;    
            }
            break;
                    
        }
        
    /*REGIONAL DATA is stored in Data_Household[i] (i > 0). i is the region id*/

    
        int i;
        for(i = 1; i <= no_regions; i++)
        {
            /*If household belongs to the i'th region*/
            if(current_household->region_id == Data_Household[i].region_id)
            {
                Data_Household[i].no_households++;
                Data_Household[i].average_specific_skill +=
                    current_household->specific_skill;
                Data_Household[i].average_payment_account += 
                    current_household->payment_account;
                
                /*If employed*/
                if(current_household->employee_firm_id > -1)
                {
                    Data_Household[i].employed++;
                    Data_Household[i].average_wage +=
                        current_household->wage;
                    
                    if(current_household->region_id != 
                       current_household->employer_region_id)
                    {
                        Data_Household[i].commuter++;   
                    }
                }
                
                /*Get seperated data for different general skill groups*/
                switch(current_household->general_skill)
                {
                    /*If general skill is 1*/
                    case 1:
                    Data_Household[i].no_households_skill_1++;
                    if(current_household->employee_firm_id > -1)
                    {
                        Data_Household[i].employed_skill_1++;
                        Data_Household[i].average_wage_skill_1 +=
                        current_household->wage;
                        
                        
                        int l = 0;
                        int r = 0;
                        l = current_household->region_id;
                        r = current_household->employer_region_id;
                        commuters[1][l][r] += 1;
                        commuters[0][l][r] += 1;
                            
                    }
                    break;

                    case 2:
                    Data_Household[i].no_households_skill_2++;
                    if(current_household->employee_firm_id > -1)
                    {
                        Data_Household[i].employed_skill_2++;
                        Data_Household[i].average_wage_skill_2 +=
                        current_household->wage;

                        int l = 0;
                        int r = 0;
                        l = current_household->region_id;
                        r = current_household->employer_region_id;
                        commuters[2][l][r] += 1;
                        commuters[0][l][r] += 1;    
                    }
                    break;

                    case 3:
                    Data_Household[i].no_households_skill_3++;
                    if(current_household->employee_firm_id > -1)
                    {
                        Data_Household[i].employed_skill_3++;
                        Data_Household[i].average_wage_skill_3 +=
                        current_household->wage;

                        int l = 0;
                        int r = 0;
                        l = current_household->region_id;
                        r = current_household->employer_region_id;
                        commuters[3][l][r] += 1;
                        commuters[0][l][r] += 1;    
                    }
                    break;

                    case 4:
                    Data_Household[i].no_households_skill_4++;
                    if(current_household->employee_firm_id > -1)
                    {
                        Data_Household[i].employed_skill_4++;
                        Data_Household[i].average_wage_skill_4 +=
                        current_household->wage;

                        int l = 0;
                        int r = 0;
                        l = current_household->region_id;
                        r = current_household->employer_region_id;
                        commuters[4][l][r] += 1;
                        commuters[0][l][r] += 1;    
                    }
                    break;

                    case 5:
                    Data_Household[i].no_households_skill_5++;
                    if(current_household->employee_firm_id > -1)
                    {
                        Data_Household[i].employed_skill_5++;
                        Data_Household[i].average_wage_skill_5 +=
                        current_household->wage;

                        int l = 0;
                        int r = 0;
                        l = current_household->region_id;
                        r = current_household->employer_region_id;
                        commuters[5][l][r] += 1;
                        commuters[0][l][r] += 1;    
                    }
                    break;
                    
                }

                
            }
            else
            {
                /*If working but not living in this region*/
                if(current_household->employer_region_id == 
                   Data_Household[i].region_id & 
                   current_household->employee_firm_id > -1)
                {
                    Data_Household[i].foreign_commuter++;
                }
            }
        }

        current_household = current_household->next;
    }

    

    
    
/*Regions: unemployment rates*/
    file = fopen("data-unemployment-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    
    //int i;
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", (Data_Household[i].no_households - 
        Data_Household[i].employed)/Data_Household[i].no_households);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", (Data_Household[i].no_households_skill_1 - 
        Data_Household[i].employed_skill_1)/Data_Household[i].no_households_skill_1);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", (Data_Household[i].no_households_skill_2 - 
        Data_Household[i].employed_skill_2)/Data_Household[i].no_households_skill_2);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", (Data_Household[i].no_households_skill_3 - 
        Data_Household[i].employed_skill_3)/Data_Household[i].no_households_skill_3);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", (Data_Household[i].no_households_skill_4 - 
        Data_Household[i].employed_skill_4)/Data_Household[i].no_households_skill_4);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", (Data_Household[i].no_households_skill_5 - 
        Data_Household[i].employed_skill_5)/Data_Household[i].no_households_skill_5);
        fputs(data, file);
        fputs("\t", file);
        
    }

    fputs("\n", file);

    fclose(file);


/*Regions: wages*/
    file = fopen("data-wage-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    
    //int i;
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Household[i].average_wage 
        /Data_Household[i].employed);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", Data_Household[i].average_wage_skill_1 
        /Data_Household[i].employed_skill_1);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", Data_Household[i].average_wage_skill_2 
        /Data_Household[i].employed_skill_2);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", Data_Household[i].average_wage_skill_3 
        /Data_Household[i].employed_skill_3);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", Data_Household[i].average_wage_skill_4 
        /Data_Household[i].employed_skill_4);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", Data_Household[i].average_wage_skill_5 
        /Data_Household[i].employed_skill_5);
        fputs(data, file);
        fputs("\t", file);
    }

    fputs("\n", file);

    fclose(file);


/*Regions: commuter*/
    file = fopen("data-commuter-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Household[i].commuter 
        /Data_Household[i].employed);
        fputs(data, file);
        fputs("\t", file);
        
        if(i > 0)
        {
         sprintf(data, "%f", (Data_Household[i].employed - Data_Household[i].commuter)/
         (Data_Household[i].employed - Data_Household[i].commuter + 
         Data_Household[i].foreign_commuter));
         fputs(data, file);
         fputs("\t", file);
         sprintf(data, "%f", Data_Household[i].foreign_commuter/(Data_Household[i].employed
         - Data_Household[i].commuter + Data_Household[i].foreign_commuter));
         fputs(data, file);
         fputs("\t", file);
        }
    }

    fputs("\n", file);

    fclose(file);


/*Regions: specific_skills*/
    file = fopen("data-specific-skill-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    
    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Household[i].average_specific_skill 
        /Data_Household[i].no_households);
        fputs(data, file);
        fputs("\t", file);
    }

    fputs("\n", file);

    fclose(file);


/*Regions: payment account*/
    file = fopen("data-payment-account-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    
    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Household[i].average_payment_account 
        /Data_Household[i].no_households);
        fputs(data, file);
        fputs("\t", file);
        
    }

    fputs("\n", file);

    fclose(file);




    if(itno%20 == 0)
    {int sum = 0;
    for(m = 0; m <= 5; m++)
    {

        printf("SKILL: %d\n", m);
        for(n = 1; n <= no_regions; n++)
        {
            int sum_region =0;
            
            for(o = 1; o <= no_regions; o++)
            {   
                printf("%d",commuters[m][n][o]);
                printf("  ");
                sum_region += commuters[m][n][o];
                sum += commuters[m][n][o];
            }
            printf("|%d|", sum_region);
            printf("\n");
            printf("_________________________________\n");
            
        }
        printf("\n");
        printf("/////////////////////////////\n");
    }
    
    }



/*Regions: commuter region 1 */
    file = fopen("data-commuter-region-1.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    
    for(m = 0; m <= 5; m++)
    {   
        /*"emigrants"*/
        for(o = 1; o <= no_regions; o++)
        {
            sprintf(data, "%i", commuters[m][1][o]);
            fputs(data, file);
            fputs("\t", file);
        }

        /*"immigrants"*/
        for(n = 1; n <= no_regions; n++)
        {
            sprintf(data, "%i", commuters[m][n][1]);
            fputs(data, file);
            fputs("\t", file);
        }   
    }

    fputs("\n", file);

    fclose(file);


/*Regions: commuter region 2 */
    file = fopen("data-commuter-region-2.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    
    for(m = 0; m <= 5; m++)
    {   
        /*"emigrants"*/
        for(o = 1; o <= no_regions; o++)
        {
            sprintf(data, "%i", commuters[m][2][o]);
            fputs(data, file);
            fputs("\t", file);
        }

        /*"immigrants"*/
        for(n = 1; n <= no_regions; n++)
        {
            sprintf(data, "%i", commuters[m][n][2]);
            fputs(data, file);
            fputs("\t", file);
        }   
    }

    fputs("\n", file);

    fclose(file);


/*Regions: commuter region 5 */
    file = fopen("data-commuter-region-5.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);
    
    for(m = 0; m <= 5; m++)
    {   
        /*"emigrants"*/
        for(o = 1; o <= no_regions; o++)
        {
            sprintf(data, "%i", commuters[m][5][o]);
            fputs(data, file);
            fputs("\t", file);
        }

        /*"immigrants"*/
        for(n = 1; n <= no_regions; n++)
        {
            sprintf(data, "%i", commuters[m][n][5]);
            fputs(data, file);
            fputs("\t", file);
        }   
    }

    fputs("\n", file);

    fclose(file);


    
    

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------MALLS-------------- DATA---------------------------------------*/

/*Initialization of the STRUCT Mall_data*/
    Mall_data Data_Mall[no_regions+1];
    
    for(i = 0; i <= no_regions; i++)
    {
        Data_Mall[i].region_id = i;
        Data_Mall[i].supply = 0.0;  
    }


    current_mall = *pointer_to_malls;
    while(current_mall)
    {
        Data_Mall[0].supply += current_mall->total_supply;
        
        int i;
        for(i = 1; i <= no_regions; i++)
        {
            if(current_mall->region_id == Data_Mall[i].region_id)
            {
                Data_Mall[i].supply = current_mall->total_supply;
            }
        }
        
        current_mall = current_mall->next;
        
    }

    if(itno%20 == 0)
    {
        file = fopen("data-supply-region.csv", "a");

        sprintf(data, "%i", itno);
        fputs(data, file);
        fputs("\t", file);

        for(i = 0; i <= no_regions; i++)
        {
            sprintf(data, "%f", Data_Mall[i].supply );
            fputs(data, file);
            fputs("\t", file);
        }

        fputs("\n", file);

        fclose(file);
    }

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------IGFirm-------------- DATA---------------------------------------*/
    
    current_IGfirm = *pointer_to_IGfirms;

    double technological_frontier =  current_IGfirm->productivity ;

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
    
/*Initialization of the STRUCT Firm_data*/
    
    
    Firm_data Data_Firm[no_regions+1];
    
    
    for(i = 0; i <= no_regions; i++)
    {
        Data_Firm[i].region_id = i;
        Data_Firm[i].no_firms = 0.0;
        Data_Firm[i].no_employees = 0.0;        
        Data_Firm[i].vacancies = 0.0;
        Data_Firm[i].average_wage = 0.0;
        Data_Firm[i].average_specific_skill = 0.0;
        Data_Firm[i].average_general_skill = 0.0;
        Data_Firm[i].sold_quantity = 0.0;
        Data_Firm[i].average_payment_account = 0.0;
        Data_Firm[i].average_price = 0.0;
        Data_Firm[i].capital_stock = 0.0;
        Data_Firm[i].earnings = 0.0;
        Data_Firm[i].revenues = 0.0;
        Data_Firm[i].planned_production_quantity = 0.0;
        Data_Firm[i].production_quantity = 0.0;
        Data_Firm[i].average_technology = 0.0;
        
    }


    current_firm = *pointer_to_firms;

    while(current_firm)
    {
        if(current_firm->no_employees > 0)
        {
            Data_Firm[0].no_firms++;
            Data_Firm[0].no_employees += current_firm->no_employees;
            Data_Firm[0].vacancies += current_firm->vacancies;
            Data_Firm[0].average_wage += (current_firm->mean_wage*
                              current_firm->no_employees);
            Data_Firm[0].average_technology += (current_firm->technology*
                                current_firm->production_quantity);
            Data_Firm[0].average_specific_skill += (current_firm->mean_specific_skills*
                                    current_firm->no_employees);
            Data_Firm[0].average_general_skill += (current_firm->average_g_skill*
                                       current_firm->no_employees);
            Data_Firm[0].production_quantity += current_firm->production_quantity;
            Data_Firm[0].sold_quantity += current_firm->total_sold_quantity;
            Data_Firm[0].average_payment_account += current_firm->payment_account_firm;
            Data_Firm[0].average_price += (current_firm->price*
                               current_firm->total_sold_quantity);
            Data_Firm[0].capital_stock += current_firm->capital_stock;
            Data_Firm[0].earnings = current_firm->earnings;
            Data_Firm[0].revenues = current_firm->revenue;
            Data_Firm[0].planned_production_quantity = 
                              current_firm->planned_production_quantity;

        }
        

        int i;
        for(i = 1; i <= no_regions; i++)
        {
            if(current_firm->region_id == Data_Firm[i].region_id 
            & current_firm->no_employees > 0)
            {
                Data_Firm[i].no_firms++;
                Data_Firm[i].no_employees += current_firm->no_employees;
                Data_Firm[i].vacancies += current_firm->vacancies;
                Data_Firm[i].average_wage += 
                  (current_firm->mean_wage*current_firm->no_employees);
                Data_Firm[i].average_technology += 
                  (current_firm->technology*current_firm->production_quantity);
                Data_Firm[i].average_specific_skill += 
                  (current_firm->mean_specific_skills*current_firm->no_employees);
                Data_Firm[i].average_general_skill += 
                  (current_firm->average_g_skill*current_firm->no_employees);
                Data_Firm[i].production_quantity += 
                   current_firm->production_quantity;
                Data_Firm[i].sold_quantity += 
                   current_firm->total_sold_quantity;
                Data_Firm[i].average_payment_account += 
                   current_firm->payment_account_firm;
                Data_Firm[i].average_price += 
                  (current_firm->price*current_firm->total_sold_quantity);
                Data_Firm[i].capital_stock += current_firm->capital_stock;
                Data_Firm[i].earnings = current_firm->earnings;
                Data_Firm[i].revenues = current_firm->revenue;
                Data_Firm[i].planned_production_quantity = 
                   current_firm->planned_production_quantity;
            }
        }
        
        
        
        
        
        
        current_firm = current_firm->next;
        
    }


/*Regions: average number of employees and vacancies*/
    file = fopen("data-employees-vacancies-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);

    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Firm[i].no_employees/Data_Firm[i].no_firms);
        fputs(data, file);
        fputs("\t", file);
        sprintf(data, "%f", Data_Firm[i].vacancies/Data_Firm[i].no_firms);
        fputs(data, file);
        fputs("\t", file);
    }
        
    fputs("\n", file);

    fclose(file);

/*Regions: wage*/
    file = fopen("data-wage-firm-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);

    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Firm[i].average_wage/Data_Firm[i].no_employees);
        fputs(data, file);
        fputs("\t", file);
        
    }
        
    fputs("\n", file);

    fclose(file);

/*Regions: average specific skills and technology*/

    if(itno%20 == 0)
    {
        file = fopen("data-specific-skill-firm-region.csv", "a");

        sprintf(data, "%i", itno);
        fputs(data, file);
        fputs("\t", file);

        for(i = 0; i <= no_regions; i++)
        {
            sprintf(data, "%f", Data_Firm[i].average_specific_skill/
            Data_Firm[i].no_employees);
            fputs(data, file);
            fputs("\t", file);
            sprintf(data, "%f", Data_Firm[i].average_technology/
            Data_Firm[i].production_quantity);
            fputs(data, file);
            fputs("\t", file);
        }
        
        fputs("\n", file);

        fclose(file);
    }

/*Regions: average general skills*/
    file = fopen("data-general-skill-firm-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);

    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Firm[i].average_general_skill/
        Data_Firm[i].no_employees);
        fputs(data, file);
        fputs("\t", file);  
    }
        
    fputs("\n", file);

    fclose(file);


/*Regions: production quantity*/

    if(itno%20 == 0)
    {
        file = fopen("data-output-region.csv", "a");

        sprintf(data, "%i", itno);
        fputs(data, file);
        fputs("\t", file);

        for(i = 0; i <= no_regions; i++)
        {
            sprintf(data, "%f", Data_Firm[i].production_quantity);
            fputs(data, file);
            fputs("\t", file);  
        }
        
        fputs("\n", file);

        fclose(file);
    }


/*Regions: sold quantity*/

    if(itno%20 == 0)
    {
        file = fopen("data-sold-quantity-region.csv", "a");

        sprintf(data, "%i", itno);
        fputs(data, file);
        fputs("\t", file);

    
        for(i = 0; i <= no_regions; i++)
        {
            sprintf(data, "%f", Data_Firm[i].sold_quantity);
            fputs(data, file);
            fputs("\t", file);  
        }
        
        fputs("\n", file);

        fclose(file);
    }


/*Regions: payment account firm*/
    file = fopen("data-payment-account-firm-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);

    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Firm[i].average_payment_account/Data_Firm[i].no_firms);
        fputs(data, file);
        fputs("\t", file);  
    }
        
    fputs("\n", file);

    fclose(file);


/*Regions: price*/

    if(itno%20 == 0)
    {
        file = fopen("data-price-region.csv", "a");

        sprintf(data, "%i", itno);
        fputs(data, file);
        fputs("\t", file);

    
        for(i = 0; i <= no_regions; i++)
        {
            sprintf(data, "%f", Data_Firm[i].average_price/Data_Firm[i].sold_quantity);
            fputs(data, file);
            fputs("\t", file);  
        }
        
        fputs("\n", file);

        fclose(file);
    }


/*Regions: capital_stock*/
    file = fopen("data-capital-stock-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);

    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Firm[i].capital_stock);
        fputs(data, file);
        fputs("\t", file);  
    }
        
    fputs("\n", file);

    fclose(file);



/*Regions: earnings*/
    file = fopen("data-earnings-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);

    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Firm[i].earnings);
        fputs(data, file);
        fputs("\t", file);  
    }
        
    fputs("\n", file);

    fclose(file);

/*Regions: revenues*/
    file = fopen("data-revenues-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);

    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Firm[i].revenues);
        fputs(data, file);
        fputs("\t", file);  
    }
        
    fputs("\n", file);

    fclose(file);


/*Regions: planned production quantity*/
    file = fopen("data-planned-production-quantity-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);

    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Firm[i].planned_production_quantity);
        fputs(data, file);
        fputs("\t", file);  
    }
        
    fputs("\n", file);

    fclose(file);


/*Regions: technology*/
    file = fopen("data-technology-region.csv", "a");

    sprintf(data, "%i", itno);
    fputs(data, file);
    fputs("\t", file);

    
    for(i = 0; i <= no_regions; i++)
    {
        sprintf(data, "%f", Data_Firm[i].average_technology/
        Data_Firm[i].production_quantity);
        fputs(data, file);
        fputs("\t", file);  
    }
        
    fputs("\n", file);

    fclose(file);


/*Regions: growthrate output*/

    if(itno%20 == 0 & itno > 20)
    {
        file = fopen("data-growthrate-output-region.csv", "a");

        sprintf(data, "%i", itno);
        fputs(data, file);
        fputs("\t", file);

        for(i = 0; i <= no_regions; i++)
        {
            sprintf(data, "%f", (Data_Firm[i].production_quantity -
            last_production[i])/last_production[i]);
            fputs(data, file);
            fputs("\t", file);      
        }
        
        fputs("\n", file);

        fclose(file);
    }


    if(itno%20 == 0)
    {
        for(i = 0; i <= no_regions; i++)
        {
            last_production[i] = Data_Firm[i].production_quantity;
            
        }
    }
    

/*Regions: growthrate technology*/

    if(itno%20 == 0 & itno > 20)
    {

        file = fopen("data-growthrate-technology-region.csv", "a");

        sprintf(data, "%i", itno);
        fputs(data, file);
        fputs("\t", file);

        for(i = 0; i <= no_regions; i++)
        {
            sprintf(data, "%f", (Data_Firm[i].average_technology - 
            last_technology[i])/last_technology[i]);
            fputs(data, file);
            fputs("\t", file);      
        }
        
        fputs("\n", file);

        fclose(file);
    }

    if(itno%20 == 0)
    {
        for(i = 0; i <= no_regions; i++)
        {
            last_technology[i] = Data_Firm[i].average_technology;
            
        }
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
    firm ** p_firms;
    household ** p_households;
    IGfirm ** p_IGfirms;
    mall ** p_malls;
    int iteration_number = 0;
    int stilldata = 1;
    int lastread = 0;
    



    FILE *file;

/*HOUSEHOLD FILES*/
    
    file = fopen("data-unemployment-region.csv", "w");
    fclose(file);

    file = fopen("data-wage-region.csv", "w");
    fclose(file);

    file = fopen("data-commuter-region.csv", "w");
    fclose(file);

    file = fopen("data-specific-skill-region.csv", "w");
    fclose(file);

    file = fopen("data-payment-account-region.csv", "w");
    fclose(file);

    file = fopen("data-commuter-region-1.csv", "w");
    fclose(file);

    file = fopen("data-commuter-region-2.csv", "w");
    fclose(file);

    file = fopen("data-commuter-region-5.csv", "w");
    fclose(file);


/*MALL FILES*/

    file = fopen("data-supply-region.csv", "w");
    fclose(file);
    
/*FIRM FILES*/
    
    file = fopen("data-employees-vacancies-region.csv", "w");
    fclose(file);

    file = fopen("data-wage-firm-region.csv", "w");
    fclose(file);

    file = fopen("data-specific-skill-firm-region.csv", "w");
    fclose(file);

    file = fopen("data-general-skill-firm-region.csv", "w");
    fclose(file);

    file = fopen("data-output-region.csv", "w");
    fclose(file);

    file = fopen("data-sold-quantity-region.csv", "w");
    fclose(file);

    file = fopen("data-payment-account-firm-region.csv", "w");
    fclose(file);

    file = fopen("data-price-region.csv", "w");
    fclose(file);

    file = fopen("data-capital-stock-region.csv", "w");
    fclose(file);

    file = fopen("data-earnings-region.csv", "w");
    fclose(file);

    file = fopen("data-revenues-region.csv", "w");
    fclose(file);

    file = fopen("data-technology-region.csv", "w");
    fclose(file);

    file = fopen("data-planned-production-quantity-region.csv", "w");
    fclose(file);

    file = fopen("data-growthrate-output-region.csv", "w");
    fclose(file);


    file = fopen("data-growthrate-technology-region.csv", "w");
    fclose(file);

    

    
    
    file = fopen("data-technological-frontier.csv", "w");
    fclose(file);
    
    file = fopen("data-IGfirm-revenues.csv", "w");
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
    
    
    while(iteration_number - lastread < 61) //frequency+1
    {
        stilldata = getiteration(filepath, iteration_number, p_firms, p_households, p_IGfirms, p_malls);
        
        if(stilldata)
        {
         savedatatofile(iteration_number, p_firms, p_households, p_IGfirms, p_malls);
         lastread = iteration_number;
        }
        iteration_number++;
        
        /*current = *p_agents;
        
        printf("Cell Data\n");
        while(current)
        {
            printf("cell:%d\ts:%d\tt:%d\n", current->id, current->state, current->type);
            current = current->next;
        }
        
        printf("\n");*/
    }
    
    /* Should never get here */
    return( 0 );
}
