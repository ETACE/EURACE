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

	double output;
	double capital_stock;
	double cum_revenue_last_month;
	double earnings;
	double price;
	double price_last_month;
	double mean_specific_skills;
	double total_debt;

	double total_sold_quantity;
	double planned_output;
	double account;
	double mean_wage;
	double nominal_exports;
	double real_exports;
	double capital_costs;
	double calc_capital_costs;
	double actual_cap_price;
	double total_dividend_payment;
	double vacancies_posted;

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
	double just_employed;
	double just_unemployed;
	double monthly_budget_last_month;
	double expenditures_last_month;
	double received_dividend;
	double savings;
	

	struct household * next;
};

struct mall
{
	int id;
	int region_id;
	double total_supply;
	double real_imports;
	double nominal_imports;
	double consumption_real;
	double consumption_nominal;
	double real_change_in_mall_inventory;
	double nominal_change_in_mall_inventory;

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


	double price_index;
	double no_vacancies;

	
	struct Eurostat * next;

};

typedef struct Eurostat Eurostat;


double monthly_output=0.0;
double monthly_output_region_1 = 0.0;
double monthly_output_region_2 = 0.0;
double monthly_sold_quantity = 0.0;
double monthly_sold_quantity_region_1 = 0.0;
double monthly_sold_quantity_region_2 = 0.0;
double monthly_revenue = 0.0;
double monthly_revenue_region_1 = 0.0;
double monthly_revenue_region_2 = 0.0;
double cum_total_stock = 0.0;
double monthly_planned_output = 0.0;
double monthly_planned_output_region_1 = 0.0;
double monthly_planned_output_region_2 = 0.0;
double monthly_technology = 0.0;
double monthly_technology_region_1 = 0.0;
double monthly_technology_region_2 = 0.0;

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
int getiteration(char * filepath, int itno, firm ** pointer_to_firms, household ** pointer_to_households,IGfirm ** pointer_to_IGfirms,mall ** pointer_to_malls,Eurostat ** pointer_to_Eurostats)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = ' ';
	char buffer[10000000];
	/* Variable to keep reading file */
	int reading = 1;

	/* Variables for checking tags */
	int i, instate, intag, initeration, inagent, inid, inregion_id, inname, ina;
	/*Firm*/
	int inwage_offer, intechnology, inno_employees, invacancies, inaverage_g_skill;
	int inoutput, incapital_stock, incum_revenue_last_month, inearnings, inprice;
	int intotal_sold_quantity, inplanned_output, inaccount, inprice_last_month, inmean_specific_skills, inmean_wage, intotal_debt, inreal_exports, innominal_exports, incapital_costs, inactual_cap_price, intotal_dividend_payment, incalc_capital_costs, invacancies_posted;
	/*Household*/
	int  inwage, inwage_reservation, ingeneral_skill, inspecific_skill, inemployee_firm_id;
	int inemployer_region_id,injust_employed, injust_unemployed, inmonthly_budget_last_month;
	int inexpenditures_last_month, inreceived_dividend, insavings;

	/*Mall*/
	int intotal_supply, inreal_imports, innominal_imports, inconsumption_real, inconsumption_nominal, inreal_change_in_mall_inventory, innominal_change_in_mall_inventory;

	/*IGFirm*/
	int inproductivity, inrevenue_per_day;

	/*Eurostat*/
	
    int  inprice_index, inno_vacancies;
    

	/* Variables for model data */
	int state, id, region_id;

	/*Firm*/
	int  no_employees, vacancies, vacancies_posted; 
	double wage_offer, technology, average_g_skill, output, capital_stock;
	double cum_revenue_last_month, earnings, price, total_sold_quantity, planned_output;
	double account,  price_last_month, mean_specific_skills,  mean_wage, total_debt;
	double real_exports, nominal_exports, capital_costs, actual_cap_price; 		  
	double total_dividend_payment, calc_capital_costs;

	/*Household*/
	int  general_skill, employee_firm_id, employer_region_id;
	double a, wage, wage_reservation, specific_skill,just_employed,just_unemployed; 
	double monthly_budget_last_month, expenditures_last_month, received_dividend, savings;

	/*Mall*/
	double total_supply;
	double real_imports;
	double nominal_imports;
	double consumption_real;
	double consumption_nominal;
	double real_change_in_mall_inventory;
	double nominal_change_in_mall_inventory;

	/*IGFirm*/
	double productivity, revenue_per_day;

	double  price_index;
	int no_vacancies;
	
	char name[10000];
	
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
	char data[2000];
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
	inoutput = 0;
	incapital_stock = 0;
	incum_revenue_last_month = 0;
	inearnings = 0;
	inprice = 0;
	inmean_wage=0;
	intotal_sold_quantity = 0;
	inplanned_output = 0;
	inaccount  = 0;
	inprice_last_month=0;
	inmean_specific_skills=0;
	intotal_debt = 0;
	innominal_exports=0;
	inreal_exports=0;
	incapital_costs = 0;
	inactual_cap_price=0;
	intotal_dividend_payment = 0;
	incalc_capital_costs = 0;
	invacancies_posted = 0;

	/*Household*/
	inwage = 0;
	inwage_reservation = 0;
	ingeneral_skill = 0;
	inspecific_skill =0;
	inemployee_firm_id = 0;
	inemployer_region_id = 0;
	injust_employed = 0.0;
	injust_unemployed = 0.0;
	inmonthly_budget_last_month= 0;
	inexpenditures_last_month = 0;
	inreceived_dividend =0;
	insavings = 0;
	
	/*Mall*/
	intotal_supply =0;
	inreal_imports = 0; 
	innominal_imports = 0;
	inconsumption_real =0; 
	inconsumption_nominal = 0; 
	inreal_change_in_mall_inventory = 0;
	innominal_change_in_mall_inventory=0;
	/*IGFirm*/
	inproductivity=0;
	inrevenue_per_day=0;


	
	inprice_index = 0;
	inno_vacancies=0;
    

	state = 0;
	id = 0;
	region_id = 0;
	a = 0.0;
	
	wage_offer = 0.0;
	technology = 0.0;
	no_employees = 0;
	vacancies = 0;
	average_g_skill = 0.0;
	output = 0.0;
	capital_stock = 0.0;
	cum_revenue_last_month = 0;
	earnings = 0;
	price = 0;
	total_sold_quantity = 0.0;
	planned_output = 0.0;
	account = 0.0;
	price_last_month=0.0;
	mean_specific_skills=0.0;
	mean_wage=0.0;
	total_debt = 0.0;
	capital_costs = 0.0;
	nominal_exports=0.0;
	real_exports=0.0;
	actual_cap_price=0.0;
	total_dividend_payment = 0;
	calc_capital_costs =0.0;
	vacancies_posted = 0;
	
	wage = 0.0;
	wage_reservation = 0.0;
	general_skill = 0;
	specific_skill = 0.0;
	employee_firm_id = 0;
	employer_region_id = 0;
	just_employed = 0.0;
	just_unemployed = 0.0;
	monthly_budget_last_month =0.0;
	expenditures_last_month=0.0;
	received_dividend = 0.0;
	savings = 0.0;
		
		
	total_supply =0;
	real_imports = 0; 
	nominal_imports = 0;
	consumption_real =0; 
	consumption_nominal = 0; 
	real_change_in_mall_inventory = 0.0;
	nominal_change_in_mall_inventory=0.0;
		
	inproductivity=0;
	revenue_per_day=0;

	/*Eurostat*/
  

	price_index = 0;
	no_vacancies=0;
		
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
					current_firm->output = output;
					current_firm->capital_stock = capital_stock;
					current_firm->cum_revenue_last_month = cum_revenue_last_month;
					current_firm->earnings = earnings;
					current_firm->mean_wage = mean_wage;
					current_firm->price = price;
					current_firm->total_sold_quantity = total_sold_quantity;
			current_firm->planned_output = planned_output;
					current_firm->account = account;
					current_firm->price_last_month=price_last_month;
					current_firm->mean_specific_skills=mean_specific_skills;
					current_firm->total_debt=total_debt;
					current_firm->real_exports=real_exports;
					current_firm->nominal_exports = nominal_exports;
					current_firm->capital_costs = capital_costs;
					current_firm->calc_capital_costs = calc_capital_costs;
					current_firm->actual_cap_price = actual_cap_price;
					current_firm-> total_dividend_payment=total_dividend_payment;
					current_firm->vacancies_posted  = vacancies_posted;
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
					current_household->just_employed = just_employed;
					current_household->just_unemployed = just_unemployed;
					current_household->savings = savings;
					current_household-> monthly_budget_last_month = monthly_budget_last_month;
					current_household-> expenditures_last_month = 		expenditures_last_month;
					current_household->received_dividend = received_dividend;
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
					
					current_mall->real_imports=real_imports;
					current_mall->nominal_imports=nominal_imports;
					current_mall->consumption_real=consumption_real;
					current_mall->consumption_nominal=consumption_nominal;
					current_mall->real_change_in_mall_inventory=real_change_in_mall_inventory;
					current_mall->nominal_change_in_mall_inventory=nominal_change_in_mall_inventory;
					
					
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
				    

			 current_Eurostat->price_index     = price_index;
			current_Eurostat ->no_vacancies = no_vacancies;
					
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
			if(strcmp(buffer, "output") == 0) { inoutput = 1; }
			if(strcmp(buffer, "/output") == 0) { inoutput = 0; }

			if(strcmp(buffer, "mean_specific_skills") == 0) { inmean_specific_skills = 1; }
			if(strcmp(buffer, "/mean_specific_skills") == 0) { inmean_specific_skills = 0; }
			if(strcmp(buffer, "total_units_capital_stock") == 0) { incapital_stock = 1; }
			if(strcmp(buffer, "/total_units_capital_stock") == 0) { incapital_stock = 0; }
			if(strcmp(buffer, "cum_revenue_last_month") == 0) { incum_revenue_last_month = 1; }
			if(strcmp(buffer, "/cum_revenue_last_month") == 0) { incum_revenue_last_month = 0; }
			if(strcmp(buffer, "earnings") == 0) { inearnings = 1; }
			if(strcmp(buffer, "/earnings") == 0) { inearnings = 0; }
			
			if(strcmp(buffer, "price_last_month") == 0) { inprice_last_month = 1; }
			if(strcmp(buffer, "/price_last_month") == 0) { inprice_last_month = 0; }

			if(strcmp(buffer, "vacancies_posted") == 0) { invacancies_posted = 1; }
			if(strcmp(buffer, "/vacancies_posted") == 0) { invacancies_posted = 0; }

			if(strcmp(buffer, "total_debt") == 0) { intotal_debt = 1; }
			if(strcmp(buffer, "/total_debt") == 0) { intotal_debt = 0; }

			if(strcmp(buffer, "capital_costs") == 0) { incapital_costs = 1; }
			if(strcmp(buffer, "/capital_costs") == 0) { incapital_costs = 0; }
			if(strcmp(buffer, "calc_capital_costs") == 0) { incalc_capital_costs = 1; }
			if(strcmp(buffer, "/calc_capital_costs") == 0) { incalc_capital_costs = 0; }
			if(strcmp(buffer, "actual_cap_price") == 0) { inactual_cap_price = 1; }
			if(strcmp(buffer, "/actual_cap_price") == 0) { inactual_cap_price = 0; }

			if(strcmp(buffer, "nominal_exports") == 0) { innominal_exports = 1; }
			if(strcmp(buffer, "/nominal_exports") == 0) { innominal_exports = 0; }
			if(strcmp(buffer, "real_exports") == 0) { inreal_exports = 1; }
			if(strcmp(buffer, "/real_exports") == 0) { inreal_exports = 0; }

			if(strcmp(buffer, "price") == 0) { inprice = 1; }
			if(strcmp(buffer, "/price") == 0) { inprice = 0; }
		     if(strcmp(buffer, "total_sold_quantity") == 0) { intotal_sold_quantity = 1; }
		     if(strcmp(buffer, "/total_sold_quantity") == 0) { intotal_sold_quantity = 0; }
	if(strcmp(buffer, "planned_output") == 0) { inplanned_output = 1; }
	if(strcmp(buffer, "/planned_output") == 0) { inplanned_output = 0; }
			if(strcmp(buffer, "account") == 0) { inaccount = 1; }
			if(strcmp(buffer, "/account") == 0) { inaccount = 0; }

			
			if(strcmp(buffer, "total_dividend_payment") == 0) { intotal_dividend_payment = 1; }
			if(strcmp(buffer, "/total_dividend_payment") == 0) { intotal_dividend_payment = 0; }

		

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
			if(strcmp(buffer, "just_employed") == 0) { injust_employed = 1; }
			if(strcmp(buffer, "/just_employed") == 0) { injust_employed = 0; }
			if(strcmp(buffer, "just_unemployed") == 0) { injust_unemployed = 1; }
			if(strcmp(buffer, "/just_unemployed") == 0) { injust_unemployed = 0; }
			if(strcmp(buffer, "savings") == 0) { insavings = 1; }
			if(strcmp(buffer, "/savings") == 0) { insavings = 0; }
			if(strcmp(buffer, "monthly_budget_last_month") == 0) { inmonthly_budget_last_month = 1; }
			if(strcmp(buffer, "/monthly_budget_last_month") == 0) { inmonthly_budget_last_month = 0; }
			if(strcmp(buffer, "expenditures_last_month") == 0) { inexpenditures_last_month = 1; }
			if(strcmp(buffer, "/expenditures_last_month") == 0) { inexpenditures_last_month = 0; }
			if(strcmp(buffer, "received_dividend") == 0) { inreceived_dividend = 1; }
			if(strcmp(buffer, "/received_dividend") == 0) { inreceived_dividend = 0; }

			
			if(strcmp(buffer, "total_supply") == 0) { intotal_supply = 1; }
		       if(strcmp(buffer, "/total_supply") == 0) { intotal_supply = 0; }
			if(strcmp(buffer, "real_imports") == 0) { inreal_imports = 1; }
		       if(strcmp(buffer, "/real_imports") == 0) { inreal_imports = 0; }
			if(strcmp(buffer, "nominal_imports") == 0) { innominal_imports = 1; }
		       if(strcmp(buffer, "/nominal_imports") == 0) { innominal_imports = 0; }
			if(strcmp(buffer, "consumption_nominal") == 0) { inconsumption_nominal = 1; }
		       if(strcmp(buffer, "/consumption_nominal") == 0) { inconsumption_nominal= 0; }
			if(strcmp(buffer, "consumption_real") == 0) { inconsumption_real = 1; }
		       if(strcmp(buffer, "/consumption_real") == 0) { inconsumption_real = 0; }
			if(strcmp(buffer, "real_change_in_mall_inventory") == 0) { inreal_change_in_mall_inventory = 1; }
		       if(strcmp(buffer, "/real_change_in_mall_inventory") == 0) { inreal_change_in_mall_inventory = 0; }
			if(strcmp(buffer, "nominal_change_in_mall_inventory") == 0) { innominal_change_in_mall_inventory = 1; }
		       if(strcmp(buffer, "/nominal_change_in_mall_inventory") == 0) { innominal_change_in_mall_inventory = 0; }



		
			if(strcmp(buffer, "productivity") == 0) { inproductivity = 1; }
		       if(strcmp(buffer, "/productivity") == 0) { inproductivity= 0; }	
			if(strcmp(buffer, "revenue_per_day") == 0) { inrevenue_per_day = 1; }
		       if(strcmp(buffer, "/revenue_per_day") == 0) { inrevenue_per_day= 0; }


			
             if(strcmp(buffer, "price_index") == 0) { inprice_index= 1; }
             if(strcmp(buffer, "/price_index") == 0) { inprice_index= 0; }

	
	if(strcmp(buffer, "no_vacancies") == 0) { inno_vacancies= 1; }
             if(strcmp(buffer, "/no_vacancies") == 0) { inno_vacancies= 0; }

			
			
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
			if(inagent && invacancies)  { vacancies  = atoi(buffer); }
			if(inagent && invacancies_posted)  { vacancies_posted  = atoi(buffer); }
			if(inagent && inaverage_g_skill)  { average_g_skill  = atof(buffer); }
			if(inagent && inoutput)  { output  = atof(buffer); }

			if(inagent && inmean_wage)  { mean_wage = atof(buffer); }
			if(inagent && incapital_stock)  { capital_stock  = atof(buffer); }
			if(inagent && incum_revenue_last_month)  { cum_revenue_last_month  = atof(buffer); }
			if(inagent && inearnings)  { earnings  = atof(buffer); }
			if(inagent && inprice)  { price  = atof(buffer); }
			if(inagent && intotal_sold_quantity)  { total_sold_quantity  = atof(buffer); }
if(inagent && inplanned_output)  { planned_output  = atof(buffer); }
			if(inagent && inaccount)  { account  = atof(buffer); }
			if(inagent && inprice_last_month)  { price_last_month  = atof(buffer); }
			if(inagent && inmean_specific_skills)  { mean_specific_skills  = atof(buffer); }
			if(inagent && intotal_dividend_payment)  { total_dividend_payment  = atof(buffer); }


			if(inagent && inreal_exports)  { real_exports = atof(buffer); }
			if(inagent && innominal_exports)  { nominal_exports  = atof(buffer); }
			if(inagent && incapital_costs)  { capital_costs  = atof(buffer); }
			if(inagent && incalc_capital_costs)  { calc_capital_costs  = atof(buffer); }
			if(inagent && inactual_cap_price)  { actual_cap_price  = atof(buffer); }
			if(inagent && inwage)  { wage  = atof(buffer); }
			if(inagent && inwage_reservation)  { wage_reservation  = atof(buffer); }
			if(inagent && ingeneral_skill)  { general_skill  = atoi(buffer); }
			if(inagent && inspecific_skill)  { specific_skill  = atof(buffer); }
			if(inagent && inemployee_firm_id)  { employee_firm_id = atoi(buffer); }
			if(inagent && inemployer_region_id)  { employer_region_id = atoi(buffer); }
			if(inagent && insavings)  { savings = atof(buffer); }
			if(inagent && injust_employed)  { just_employed  = atof(buffer); }
			if(inagent && injust_unemployed)  { just_unemployed  = atof(buffer); }
			if(inagent && inmonthly_budget_last_month)  { monthly_budget_last_month  = atof(buffer); }
			if(inagent && inexpenditures_last_month)  { expenditures_last_month  = atof(buffer); }
			if(inagent && inreceived_dividend)  { received_dividend  = atof(buffer); }

			if(inagent && intotal_debt)  { total_debt  = atof(buffer); }
			
			if(inagent && inrevenue_per_day)  {revenue_per_day  = atof(buffer); }
			if(inagent && inproductivity)  { productivity  = atof(buffer); }
			if(inagent && intotal_supply)  { total_supply  = atof(buffer); }
			
			if(inagent && inreal_imports)  { real_imports  = atof(buffer); }
			if(inagent && innominal_imports)  { nominal_imports  = atof(buffer); }
			if(inagent && inconsumption_real)  { consumption_real  = atof(buffer); }
			if(inagent && inconsumption_nominal)  { consumption_nominal  = atof(buffer); }
			if(inagent && inreal_change_in_mall_inventory)  { real_change_in_mall_inventory = atof(buffer); }
			if(inagent && innominal_change_in_mall_inventory)  { nominal_change_in_mall_inventory  = atof(buffer); }

			
	 if(inagent && inprice_index)  { price_index  = atof(buffer); }	
		
		 if(inagent && inno_vacancies)  {no_vacancies  = atoi(buffer); }
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
		else// if(inname || inid || ina || inproductivity || inprice || insold || inproduction || inwage || inprice_index || infirmid || inworkers)
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

	/* Free memory for unused linked list elements */
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

void savedatatofile(int itno, firm ** pointer_to_firms, household ** pointer_to_households,IGfirm ** pointer_to_IGfirms,mall ** pointer_to_malls, Eurostat ** pointer_to_Eurostats)
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

	Eurostat* current_Eurostat;
	
	current_Eurostat = *pointer_to_Eurostats;
	
	
	double price_index;
	int no_vacancies;
	int sum_vacancies_posted=0;
	double herfindahl_index = 0;

	
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

	double sum_monthly_budget_last_month =0;
	double sum_expenditures_last_month = 0;
	double sum_received_dividend = 0;
	double just_employed_all = 0.0;
	double just_unemployed_all = 0.0;
	double just_employed_region_1 = 0.0;
	double just_unemployed_region_1 = 0.0;
	double just_employed_region_2 = 0.0;
	double just_unemployed_region_2 = 0.0;
	double sum_savings = 0.0;
	
	
	double ave_no_employees = 0;
	double ave_no_employees_region_1 = 0;
	double ave_no_employees_region_2 = 0;
	int ave_vacancies = 0;
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


	
	double total_no_hh_skill_1_region_1 = 0;
	double total_no_hh_skill_2_region_1 = 0;
	double total_no_hh_skill_3_region_1 = 0;
	double total_no_hh_skill_4_region_1 = 0;
	double total_no_hh_skill_5_region_1 = 0;
	double total_no_hh_skill_1_region_2 = 0;
	double total_no_hh_skill_2_region_2 = 0;
	double total_no_hh_skill_3_region_2 = 0;
	double total_no_hh_skill_4_region_2 = 0;
	double total_no_hh_skill_5_region_2 = 0;

	double ave_g_skill = 0;
	double ave_g_skill_region_1 = 0;
	double ave_g_skill_region_2 = 0;
	
	double ave_output = 0.0;
	double ave_output_region_1 = 0.0;
	double ave_output_region_2 = 0.0;


	double sum_nominal_exports_reg1 = 0.0;
	double sum_nominal_exports_reg2 = 0.0;

	double sum_real_exports_reg1 = 0.0;
	double sum_real_exports_reg2 = 0.0;


	double real_investments_reg1 = 0.0;
	double real_investments_reg2 = 0.0;
	double nominal_investments_reg1 = 0.0;
	double nominal_investments_reg2 = 0.0;

	double ave_capital_stock = 0;
	double ave_capital_stock_region_1 = 0;
	double ave_capital_stock_region_2 = 0;
	double ave_cum_revenue_last_month = 0;
	double ave_cum_revenue_last_month_region_1 = 0;
	double ave_cum_revenue_last_month_region_2 = 0;
	double ave_earnings = 0;
	double ave_earnings_region_1 = 0;
	double ave_earnings_region_2 = 0;
	double ave_price = 0;
	double ave_total_sold_quantity = 0;
	double ave_total_sold_quantity_region_1 = 0;
	double ave_total_sold_quantity_region_2 = 0;
	double ave_planned_output = 0.0;
	double ave_planned_output_region_1 = 0.0;
	double ave_planned_output_region_2 = 0.0;
	double ave_account = 0.0;
	double ave_account_region_1 = 0.0;
	double ave_account_region_2 = 0.0;
	double ave_technology = 0.0;
	double ave_technology_region_1 = 0.0;
	double ave_technology_region_2 = 0.0;
	double ave_mean_specific_skills_region_1=0.0;
	double ave_mean_specific_skills_region_2=0.0;
	double ave_mean_specific_skills =0.0;
	double sum_total_dividend_payment = 0;
	double sum_calc_capital_costs = 0;

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

	double economy_wide_total_debt = 0.0;

	double mean_wage_region_1_firm = 0;
	double mean_wage_region_2_firm = 0;
	
	double last_prices[10];
	double prices[10];	
	double market_share[10];
	double employees[10];

	double technology[10];


	double real_imports_reg1 = 0.0;
	double nominal_imports_reg1 = 0.0;
	double consumption_real_reg1 = 0.0;
	double consumption_nominal_reg1 = 0.0;
	double real_change_in_mall_inventory_reg1= 0.0;
	double nominal_change_in_mall_inventory_reg1= 0.0;
	double real_imports_reg2 = 0.0;
	double nominal_imports_reg2 = 0.0;
	double consumption_real_reg2 = 0.0;
	double consumption_nominal_reg2 = 0.0;
	double real_change_in_mall_inventory_reg2= 0.0;
	double nominal_change_in_mall_inventory_reg2= 0.0;

	
	double consumption_real_total = 0.0;
	double consumption_nominal_total = 0.0;
	double real_change_in_mall_inventory_total= 0.0;
	double nominal_change_in_mall_inventory_total= 0.0;
	
	double real_investments_total = 0.0;
	double nominal_investments_total = 0.0;




	double real_gdp_reg1;
	double real_gdp_reg2;
	double real_gdp_total;
	double nominal_gdp_reg1;
	double nominal_gdp_reg2;
	double nominal_gdp_total;
	
	


		current_Eurostat = *pointer_to_Eurostats;

	while(current_Eurostat)
	{
	//Set local variables
	    
	price_index = current_Eurostat->price_index;    
        /*Add history items here*/

	
	no_vacancies = current_Eurostat->no_vacancies;


       
        printf("price_index %f \n",price_index);
        
		//Go to the next in linked list
		current_Eurostat = current_Eurostat->next;
		
	}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/	
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------HOUSEHOLDS------DAILY DATA---------------------------------------*/
	
	current_household = *pointer_to_households;
	while(current_household)
	{
		no_households++;
		
		ave_wage_reservation += current_household->wage_reservation;
		
		ave_mean_specific_skills+=current_household->specific_skill;
		just_employed_all += current_household->just_employed;
		just_unemployed_all += current_household->just_unemployed;
		

		sum_monthly_budget_last_month +=current_household->monthly_budget_last_month; 
		sum_expenditures_last_month += current_household->expenditures_last_month;
		sum_received_dividend += current_household->received_dividend;
		sum_savings += current_household->savings;
		
		if(current_household->region_id == 1)
			{
				no_households_region_1++;
				just_employed_region_1 += current_household->just_employed;
				just_unemployed_region_1 += current_household->just_unemployed;
				
				
			ave_wage_reservation_region_1 += current_household->wage_reservation;

				if(current_household->general_skill == 1) 
				{
				total_no_hh_skill_1_region_1++;

				}
				if(current_household->general_skill == 2) 
				{
				total_no_hh_skill_2_region_1++;

				}
				if(current_household->general_skill == 3) 
				{
				total_no_hh_skill_3_region_1++;

				}
				if(current_household->general_skill == 4) 
				{
				total_no_hh_skill_4_region_1++;

				}
				if(current_household->general_skill == 5) 
				{
				total_no_hh_skill_5_region_1++;

				}
			
			
			}
			else
			{
				no_households_region_2++;
				just_employed_region_2 += current_household->just_employed;
				just_unemployed_region_2 += current_household->just_unemployed;
				
			ave_wage_reservation_region_2 += current_household->wage_reservation;

				if(current_household->general_skill == 1) 
				{
				total_no_hh_skill_1_region_2++;

				}
				if(current_household->general_skill == 2) 
				{
				total_no_hh_skill_2_region_2++;

				}
				if(current_household->general_skill == 3) 
				{
				total_no_hh_skill_3_region_2++;

				}
				if(current_household->general_skill == 4) 
				{
				total_no_hh_skill_4_region_2++;

				}
				if(current_household->general_skill == 5) 
				{
				total_no_hh_skill_5_region_2++;

				}
			
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
		
	
	
	

	if(itno%20 == 0)
	{
		file = fopen("data-price-index.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", price_index);
		fputs(data, file);
		
		fputs("\n", file);

		fclose(file);


		file = fopen("data-general_skills.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", no_households_skill_group_1);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", no_households_skill_group_2);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", no_households_skill_group_3);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", no_households_skill_group_4);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", no_households_skill_group_5);
		fputs(data, file);
		fputs("\n", file);

		fclose(file);
	
		
		
	file = fopen("data-general_skills_regional.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_1_region_1);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_2_region_1);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_3_region_1);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_4_region_1);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_5_region_1);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_1_region_2);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_2_region_2);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_3_region_2);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_4_region_2);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", total_no_hh_skill_5_region_2);
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

}

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


		file = fopen("data-savings.csv", "a");
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", sum_savings);
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


	if(itno%20 == 0)
	{
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
	}


	if(itno%20 == 0)
	{
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
	}

	
	
	file = fopen("data-unemployment-flows.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", just_unemployed_all/((no_households - employed)-just_unemployed_all + just_employed_all));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", just_employed_all/((no_households - employed)-just_unemployed_all + just_employed_all));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", just_unemployed_region_1/((no_households_region_1 - employed_region_1)-just_unemployed_region_1 + just_employed_region_1));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", just_employed_region_1/((no_households_region_1 - employed_region_1)-just_unemployed_region_1 + just_employed_region_1));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", just_unemployed_region_2/((no_households_region_2 - employed_region_2)-just_unemployed_region_2 + just_employed_region_2));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", just_employed_region_2/((no_households_region_2 - employed_region_2)-just_unemployed_region_2 + just_employed_region_2));
		fputs(data, file);
		fputs("\t", file);
		
		fputs("\n", file);

	fclose(file);


	file = fopen("data-consumption-budget-expenditures.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", sum_monthly_budget_last_month);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", sum_expenditures_last_month);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", sum_expenditures_last_month/sum_monthly_budget_last_month);
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

			real_imports_reg1 = current_mall->real_imports;
	nominal_imports_reg1 = current_mall->nominal_imports;
	consumption_real_reg1 = current_mall->consumption_real;
	consumption_nominal_reg1 = current_mall->consumption_nominal;
	real_change_in_mall_inventory_reg1= current_mall->real_change_in_mall_inventory;
	nominal_change_in_mall_inventory_reg1 = current_mall->nominal_change_in_mall_inventory;

	
			
		}
		else
		{
			region_2_total_supply = current_mall->total_supply;

			real_imports_reg2 = current_mall->real_imports;
	nominal_imports_reg2 = current_mall->nominal_imports;
	consumption_real_reg2 = current_mall->consumption_real;
	consumption_nominal_reg2 = current_mall->consumption_nominal;
	real_change_in_mall_inventory_reg2 = current_mall->real_change_in_mall_inventory;
	nominal_change_in_mall_inventory_reg2 = current_mall->nominal_change_in_mall_inventory;
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



		
	double sum_sold_quant = consumption_nominal_reg1+consumption_nominal_reg2;


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/	
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------FIRMS DAILY AND REGIONAL DATA-------------------------------------*/
	current_firm = *pointer_to_firms;

	while(current_firm)
	{
		no_firms++;


		herfindahl_index+=  (current_firm->cum_revenue_last_month/sum_sold_quant)*(current_firm->cum_revenue_last_month/sum_sold_quant);
		
		ave_no_employees += current_firm->no_employees;
		ave_vacancies += current_firm->vacancies;
		sum_vacancies_posted += current_firm->vacancies_posted;
		ave_g_skill += current_firm->average_g_skill;
		ave_output += current_firm->output;
		ave_capital_stock += current_firm->capital_stock;
		ave_cum_revenue_last_month += current_firm->cum_revenue_last_month;
		ave_earnings += current_firm->earnings;
		ave_price += current_firm->price;
		ave_wage_offer += current_firm->wage_offer;
		ave_total_sold_quantity += current_firm->total_sold_quantity;
		ave_planned_output += current_firm->planned_output;
		ave_account += current_firm->account;
		if(current_firm->no_employees >0)
		ave_technology += current_firm->technology*current_firm->output;
		sum_calc_capital_costs +=current_firm->calc_capital_costs;
		sum_total_dividend_payment += current_firm->total_dividend_payment;
		
		
		if(1== current_firm->region_id)
		{
			no_firms_region_1++;

		ave_no_employees_region_1 += current_firm->no_employees;
		ave_vacancies_region_1 += current_firm->vacancies;
		ave_g_skill_region_1 += current_firm->average_g_skill;	
		ave_output_region_1 += current_firm->output;
		ave_capital_stock_region_1 += current_firm->capital_stock;
		ave_cum_revenue_last_month_region_1 += current_firm->cum_revenue_last_month;
		ave_earnings_region_1 += current_firm->earnings;
		ave_wage_offer_region_1 += current_firm->wage_offer;	
		ave_total_sold_quantity_region_1 += current_firm->total_sold_quantity;
		ave_planned_output_region_1 += current_firm->planned_output;
		ave_account_region_1 += current_firm->account;

		mean_wage_region_1_firm +=current_firm->mean_wage*current_firm->output;



		sum_nominal_exports_reg1+=current_firm->nominal_exports; 
		sum_real_exports_reg1+=current_firm->real_exports; 


	real_investments_reg1 += current_firm->capital_costs/current_firm->actual_cap_price;
	
	nominal_investments_reg1 += current_firm->capital_costs;
	


		ave_price_reg1 += current_firm->price*current_firm->output;
		if(current_firm->no_employees >0)
		{
		ave_technology_region_1 += current_firm->technology*current_firm->output;
		ave_mean_specific_skills_region_1 += current_firm->mean_specific_skills*current_firm->output;
		}
		}
		else
		{
			no_firms_region_2++;

		ave_no_employees_region_2 += current_firm->no_employees;
		ave_vacancies_region_2 += current_firm->vacancies;
		ave_g_skill_region_2 += current_firm->average_g_skill;
		ave_output_region_2 += current_firm->output;
		ave_capital_stock_region_2 += current_firm->capital_stock;
		ave_cum_revenue_last_month_region_2 += current_firm->cum_revenue_last_month;
		ave_earnings_region_2 += current_firm->earnings;
		ave_wage_offer_region_2 += current_firm->wage_offer;			
		ave_total_sold_quantity_region_2 += current_firm->total_sold_quantity;


		sum_nominal_exports_reg2+=current_firm->nominal_exports; 
		sum_real_exports_reg2+=current_firm->real_exports;

		real_investments_reg2 += current_firm->capital_costs/current_firm->actual_cap_price;
		nominal_investments_reg2 += current_firm->capital_costs; 


		economy_wide_total_debt += current_firm->total_debt;
		
		ave_planned_output_region_2 += current_firm->planned_output;
		ave_account_region_2 += current_firm->account;
		ave_price_reg2 += current_firm->price*current_firm->output;
		mean_wage_region_2_firm +=current_firm->mean_wage*current_firm->output;

		if(current_firm->no_employees >0)
		{
		ave_technology_region_2 += current_firm->technology*current_firm->output;
		ave_mean_specific_skills_region_2 += current_firm->mean_specific_skills*current_firm->output;
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
		monthly_output += ave_output;
		monthly_output_region_1 += ave_output_region_1;
		monthly_output_region_2 += ave_output_region_2;
		monthly_technology += ave_technology;
		monthly_technology_region_1 += ave_technology_region_1;
		monthly_technology_region_2 += ave_technology_region_2;
		
		
		monthly_planned_output += ave_planned_output;
		monthly_planned_output_region_1 += ave_planned_output_region_1;
		monthly_planned_output_region_2 += ave_planned_output_region_2;
		monthly_account = ave_account;
		monthly_account_region_1 = ave_account_region_1;
		monthly_account_region_2 = ave_account_region_2;

		
		
		consumption_nominal_total = consumption_nominal_reg1+consumption_nominal_reg2;

	nominal_investments_total= nominal_investments_reg1+nominal_investments_reg2;
	
	
	nominal_change_in_mall_inventory_total = nominal_change_in_mall_inventory_reg1+nominal_change_in_mall_inventory_reg2;

	

		nominal_gdp_reg1= consumption_nominal_reg1 + nominal_investments_reg1 + nominal_change_in_mall_inventory_reg1 + sum_nominal_exports_reg1 - nominal_imports_reg1;

		real_gdp_reg1 = nominal_gdp_reg1/price_index;
		

		nominal_gdp_reg2= consumption_nominal_reg2 + nominal_investments_reg2 + nominal_change_in_mall_inventory_reg2 + sum_nominal_exports_reg2 - nominal_imports_reg2;
	
		real_gdp_reg2 = nominal_gdp_reg2/price_index;
		
		




		if(itno%20 == 0)
		{



		//Computing of monthly gdp:

			

			file = fopen("data-monthly-nominal-gdp.csv", "a");

			sprintf(data, "%i", itno);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f",nominal_gdp_reg1+ nominal_gdp_reg2);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", nominal_gdp_reg1);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", nominal_gdp_reg2);
			fputs(data, file);
			fputs("\n", file);

			fclose(file);


			file = fopen("data-monthly-real-gdp.csv", "a");

			sprintf(data, "%i", itno);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f",real_gdp_reg1+ real_gdp_reg2);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", real_gdp_reg1);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", real_gdp_reg2);
			fputs(data, file);
			fputs("\n", file);

			fclose(file);


			file = fopen("data-nominal-macroeconomic-accounting.csv", "a");

			sprintf(data, "%i", itno);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f",consumption_nominal_total);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", consumption_nominal_reg1);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", consumption_nominal_reg2);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f",nominal_investments_total);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", nominal_investments_reg1);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", nominal_investments_reg2);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f",nominal_change_in_mall_inventory_total);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", nominal_change_in_mall_inventory_reg1);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f",nominal_change_in_mall_inventory_reg2);
			fputs(data, file);
			fputs("\t", file);

			sprintf(data, "%f",sum_nominal_exports_reg2+sum_nominal_exports_reg1);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", sum_nominal_exports_reg1 );
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f",sum_nominal_exports_reg2);
			fputs(data, file);
			fputs("\t", file);

			sprintf(data, "%f",nominal_imports_reg1+nominal_imports_reg2);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", nominal_imports_reg1);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f",nominal_imports_reg2);
			fputs(data, file);
			

			fputs("\n", file);

			fclose(file);


			file = fopen("data-monthly-output.csv", "a");

			sprintf(data, "%i", itno);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", monthly_output);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", consumption_real_reg1 + consumption_real_reg2);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", economywide_total_supply);
			fputs(data, file);
			fputs("\n", file);

			fclose(file);

			file = fopen("data-dividends.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", sum_received_dividend);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", sum_total_dividend_payment);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", sum_received_dividend - sum_total_dividend_payment);
		fputs(data, file);
		fputs("\n", file);

		fclose(file);

			file = fopen("data-firm-debts.csv", "a");

			sprintf(data, "%i", itno);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", economy_wide_total_debt);
			fputs(data, file);
			fputs("\n", file);

			fclose(file);


			file = fopen("data-calc-capital-costs.csv", "a");

			sprintf(data, "%i", itno);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", sum_calc_capital_costs);
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
			sprintf(data, "%f", monthly_planned_output);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", monthly_output_region_1);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", monthly_planned_output_region_1);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", monthly_output_region_2);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", monthly_planned_output_region_2);
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

			
			double herfindahl = sum_3;
			double inflation_rate = (sum_1 - sum_2)/sum_2;
			
		
	
			prod_vol=monthly_output;
			prod_vol_reg1=monthly_output_region_1;
			prod_vol_reg2=monthly_output_region_2;
		
			monthly_output = 0.0;
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
	sprintf(data, "%f", monthly_technology/prod_vol);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", monthly_technology_region_1/prod_vol_reg1);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", monthly_technology_region_2/prod_vol_reg2);
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
			monthly_planned_output = 0.0;
			monthly_planned_output_region_1 = 0.0;
			monthly_planned_output_region_2 = 0.0;
			monthly_account = 0.0;
			monthly_account_region_1 = 0.0;
			monthly_account_region_2 = 0.0;
			monthly_technology = 0.0;
			monthly_technology_region_1 = 0.0;
			monthly_technology_region_2 = 0.0;
			
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
	sprintf(data, "%f", ave_output);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", ave_total_sold_quantity);
	fputs(data, file);
	fputs("\n", file);

	fclose(file);

	/*capital*/

	if(itno>20 && itno%20 == 0)
	{
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
	}

	
			file = fopen("data-herfindahl-index.csv", "a");

			sprintf(data, "%i", itno);
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f",herfindahl_index);
			fputs(data, file);
			fputs("\n", file);

			fclose(file);

	/*earnings, revenue*/

	if(itno>20)
	{
	file = fopen("data-revenue.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", ave_earnings);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", ave_earnings_region_1);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", ave_earnings_region_2);
	fputs(data, file);
	fputs("\n", file);

	fclose(file);
	}
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


	file = fopen("data-no-vacancies.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%i", no_vacancies);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%i", sum_vacancies_posted);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f",no_households-employed);
		fputs(data, file);
		fputs("\n", file);

		fclose(file);


	


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
	household ** p_household;
	IGfirm ** p_IGfirms;
	mall ** p_malls;
	Eurostat * Eurostats, * current_Eurostat;
	

	Eurostat ** p_Eurostats;
	int iteration_number = 0;
	int stilldata = 1;
	

	

	FILE *file;
	
	//file = fopen("data-v-u.csv", "w");
	//fclose(file);
;
	
	file = fopen("data-wage.csv", "w");
	fclose(file);

	file = fopen("data-monthly-nominal-gdp.csv", "w");
	fclose(file);
	file = fopen("data-monthly-real-gdp.csv", "w");
	fclose(file);

	file = fopen("data-firm-debts.csv", "w");
	fclose(file);

	file = fopen("data-consumption-budget-expenditures.csv", "w");
	fclose(file);

	
	file = fopen("data-dividends.csv", "w");
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

	file = fopen("data-unemployment-flows.csv", "w");
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


	file = fopen("data-price-index.csv", "w");
	fclose(file);

	file = fopen("data-no-vacancies.csv", "w");
	fclose(file);

	file = fopen("data-regional-price.csv", "w");
	fclose(file);

	file = fopen("data-general_skills_regional.csv", "w");
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

	file = fopen("data-calc-capital-costs.csv", "w");
	fclose(file);

	file = fopen("data-general_skills.csv", "w");
	fclose(file);

	file = fopen("data-nominal-macroeconomic-accounting.csv", "w");
	fclose(file);

	file = fopen("data-savings.csv", "w");
	fclose(file);

	file = fopen("data-herfindahl-index.csv", "w");
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
	p_household = &households;

	IGfirms = NULL;
	p_IGfirms = &IGfirms;
	
	malls = NULL;
	p_malls = &malls;

	Eurostats = NULL;
	p_Eurostats = &Eurostats;

	
	while(stilldata)
	{
		stilldata = getiteration(filepath, iteration_number, p_firms, p_household,p_IGfirms, p_malls, p_Eurostats );
		
		if(stilldata) savedatatofile(iteration_number, p_firms, p_household,p_IGfirms, p_malls,p_Eurostats);
		//iteration_number++;
		iteration_number+=20;
		
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
