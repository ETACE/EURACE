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
	double revenue;
	double earnings;
	double price;
	double price_last_month;
	double mean_specific_skills;

	double sold_quantity_in_calendar_month;
	double planned_output;
	double payment_account_firm;
	double mean_wage;
	double wage_offer_for_skill_1;
	double wage_offer_for_skill_2;
	double wage_offer_for_skill_3;
	double wage_offer_for_skill_4;
	double wage_offer_for_skill_5;

	double delivery;
	double delivery_to_home_region;
	double delivery_to_foreign_region;

	double stocks;
	double stocks_in_home_region;
	double stocks_in_foreign_region;
	
	double total_debt;
	double assets;
	
	double labour_costs;
	double calc_capital_costs;
	double total_interest_payment;
	double unit_costs;

	int posted_vacancies;
	int no_applications;
	int job_acceptance;
	double no_job_offers;
	int wage_increase;

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
	double consumption_budget_in_month;
	double no_job_offers;
	double employed_this_period;
	double fired_this_period;
	double additional_tax;

	struct household * next;
};

struct mall
{
	int id;
	int region_id;
	double total_supply;
	double sales;
	double sales_of_domestic_firms;
	double sales_of_foreign_firms;

	struct mall * next;


};
 struct IGfirm
{
	int id;
	int region_id;
	double productivity;
	double cum_revenue_last_month;	
	double dividend_payment;
	
	double no_employees;
	double no_research_employees;
	int vacancies;
	int research_vacancies;
	double sales_last_month;
	double capital_good_demand_last_month;
	double capital_good_store_before_production;
	double capital_good_store_after_production;
	double capital_good_price;
	double output;
	double planned_output;
	
	double tax_payment;
	double total_interest_payment;
	double total_debt_installment_payment;
	double total_dividend_payment;
	double earnings;
	double total_debt;
	double external_financial_needs;
	double total_external_financing_obtained;
	double payment_account;
	double production_costs_last_month;

	struct IGfirm * next;

};

 struct government
{
	int id;
	int region_id;
	double monthly_tax_revenues;
	double monthly_benefit_payment;	
	double monthly_budget_balance;
	double total_debt;

	struct government * next;

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
	double reservation_wage_skill_1;
	double reservation_wage_skill_2;
	double reservation_wage_skill_3;
	double reservation_wage_skill_4;
	double reservation_wage_skill_5;
	double consumption_budget_in_month;
	double no_job_offers;
	double just_employed;
	double employed_this_period;
	double fired_this_period;
	double additional_tax;
	double reemployed;
		

};
typedef struct Household_data Household_data;


struct Mall_data
{
	double region_id;
	double supply;
	double sales;
	double sales_of_domestic_firms;
	double sales_of_foreign_firms;
};
typedef struct Mall_data Mall_data;

struct Firm_data
{
	double region_id;
	double no_firms;
	int total_no_firms;
	double no_employees;
	double vacancies;
	double average_wage;
	double average_technology;
	double average_specific_skill;
	double average_general_skill;
	double output;
	double sold_quantity_in_calendar_month;
	double average_payment_account;
	double average_price;
	double capital_stock;
	double earnings;
	double revenues;
	double planned_output;
	double output_last_month;
	double average_technology_last_month;
	double wage_offer;
	double wage_offer_for_skill_1;
	double wage_offer_for_skill_2;
	double wage_offer_for_skill_3;
	double wage_offer_for_skill_4;
	double wage_offer_for_skill_5;
	double delivery;
	double delivery_to_home_region;
	double delivery_to_foreign_region;
	double stocks;
	double stocks_in_home_region;
	double stocks_in_foreign_region;
	double price_index_mall;
	double price_index_home_mall;
	double price_index_foreign_mall;
	double total_debt;
	double debt_active_firms;
	double assets;
	double assets_active_firms;
	double debt_asset_ratio_active_firms;
	double debt_asset_ratio;
	int count_debt_asset_ratio_threshold;
	double price;

	double labour_costs;
	double calc_capital_costs;
	double total_interest_payment;
	double unit_costs;

	int posted_vacancies;
	int no_applications;
	int job_acceptance;
	double no_job_offers;
	int wage_increase;

	
};
typedef struct Firm_data Firm_data;

struct Government_data
{
	int region_id;
	double monthly_tax_revenues;
	double monthly_benefit_payment;	
	double monthly_budget_balance;
	double total_debt;
};
typedef struct Government_data Government_data;

struct IGFirm_data
{
	int region_id;
	int no_igfirms;
	double productivity;
	double cum_revenue_last_month;	
	double dividend_payment;

	double no_employees;
	double no_research_employees;
	int vacancies;
	int research_vacancies;
	double sales_last_month;
	double capital_good_demand_last_month;
	double capital_good_store_before_production;
	double capital_good_store_after_production;
	double capital_good_price;
	double output;
	double planned_output;
	double wage_offer;
	
	double tax_payment;
	double total_interest_payment;
	double total_debt_installment_payment;
	double total_dividend_payment;
	double earnings;
	double total_debt;
	double external_financial_needs;
	double total_external_financing_obtained;
	double payment_account;
	double production_costs_last_month;
	
	
};
typedef struct IGFirm_data IGFirm_data;




typedef struct firm firm;
typedef struct household household;

typedef struct mall mall;
typedef struct IGfirm IGfirm;
typedef struct government government;

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


void freegovernments(government * head)
{
	/* Tempory element needed for loop */
	government * tmp;

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


government * addgovernment(government ** pointer_to_governments, government * current)
{
	/* The new tail of the linked list */
	government * tail;

	/* Allocate memory for new neighbour data */

	tail = (government *)malloc(sizeof(government));

	/* Check if current is not NULL */
	if(current)
	{
		/* Current exists therefore make its next point to tail */
		current->next = tail;
	}
	else
	{
		/* Current is NULL therefore make the cell neighbour_head point to tail */
		*pointer_to_governments = tail;
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
int getiteration(char * filepath, int itno, firm ** pointer_to_firms, household ** pointer_to_households,IGfirm ** pointer_to_IGfirms,mall ** pointer_to_malls,government ** pointer_to_governments)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = ' ';
	char buffer[1000000];
	/* Variable to keep reading file */
	int reading = 1;

	/* Variables for checking tags */
	int i, instate, intag, initeration, inagent, inid, inregion_id, inname, ina;
	/*Firm*/
	int inwage_offer, intechnology, inno_employees, invacancies, inaverage_g_skill;
	int inoutput, incapital_stock, inrevenue, inearnings, inprice;
	int insold_quantity_in_calendar_month, inplanned_output, inpayment_account_firm, inprice_last_month, inmean_specific_skills, inmean_wage;

	int inwage_offer_for_skill_1;
	int inwage_offer_for_skill_2;
	int inwage_offer_for_skill_3;
	int inwage_offer_for_skill_4;
	int inwage_offer_for_skill_5;

	int indelivery;
	int indelivery_to_home_region;
	int indelivery_to_foreign_region;
	int instocks;
	int instocks_in_home_region;
	int instocks_in_foreign_region;
	int intotal_debt;
	int inassets;
	int inlabour_costs;
	int incalc_capital_costs;
	int intotal_interest_payment;
	int inunit_costs;

	int inposted_vacancies;
	int inno_applications;
	int injob_acceptance;
	int inwage_increase;


	/*Household*/
	int  inwage, inwage_reservation, ingeneral_skill, inspecific_skill, inemployee_firm_id;
	int inemployer_region_id, inpayment_account, inconsumption_budget_in_month;
	int inno_job_offers;
	int inemployed_this_period;
	int infired_this_period;
	int inadditional_tax;

	/*Mall*/
	int intotal_supply;
	int insales;
	int insales_of_domestic_firms;
	int insales_of_foreign_firms;

	/*IGFirm*/
	int inproductivity, incum_revenue_last_month;
	int individend_payment;
	
	int inno_research_employees;
	//int invacancies;
	int inresearch_vacancies;
	int insales_last_month;
	int incapital_good_demand_last_month;
	int incapital_good_store_before_production;
	int incapital_good_store_after_production;
	int incapital_good_price;
	int intax_payment; 
	//int intotal_interest_payment;
	int intotal_debt_installment_payment;
	int intotal_dividend_payment;
	//int inearnings;
	//int intotal_debt;
	int inexternal_financial_needs;
	int intotal_external_financing_obtained;
	int inproduction_costs_last_month;

	/*Government*/
	int inmonthly_tax_revenues;
	int inmonthly_benefit_payment;
	int inmonthly_budget_balance;
	//int intotal_debt;
	

	/* Variables for model data */
	int state, id, region_id;

	/*Firm*/
	int  no_employees, vacancies; 
	double wage_offer, technology, average_g_skill, output, capital_stock;
	double revenue, earnings, price, sold_quantity_in_calendar_month, planned_output;
	double payment_account_firm,  price_last_month, mean_specific_skills,  mean_wage;
	double wage_offer_for_skill_1;
	double wage_offer_for_skill_2;
	double wage_offer_for_skill_3;
	double wage_offer_for_skill_4;
	double wage_offer_for_skill_5;
	double delivery;
	double delivery_to_home_region;
	double delivery_to_foreign_region;
	double stocks;
	double stocks_in_home_region;
	double stocks_in_foreign_region;
	double total_debt;
	double assets;
	double labour_costs;
	double calc_capital_costs;
	double total_interest_payment;
	double unit_costs;
	int posted_vacancies;
	int no_applications;
	int job_acceptance;
	int wage_increase;
	

	/*Household*/
	int  general_skill, employee_firm_id, employer_region_id;
	double a, wage, wage_reservation, specific_skill, payment_account, consumption_budget_in_month;
	double no_job_offers;
	double employed_this_period;
	double fired_this_period;
	double additional_tax;
	
	/*Mall*/
	double total_supply;
	double sales;
	double sales_of_domestic_firms;
	double sales_of_foreign_firms;

	/*IGFirm*/
	double productivity, cum_revenue_last_month,dividend_payment;
	
	double no_research_employees;
	//int vacancies;
	int research_vacancies;
	double sales_last_month;
	double capital_good_demand_last_month;
	double capital_good_store_before_production;
	double capital_good_store_after_production;
	double capital_good_price;
	
	double tax_payment;
	//double total_interest_payment;
	double total_debt_installment_payment;
	double total_dividend_payment;
	//double earnings;
	//double total_debt;
	double external_financial_needs;
	double total_external_financing_obtained;
	double production_costs_last_month;
	

	/*Government*/
	double monthly_tax_revenues;
	double monthly_benefit_payment;
	double monthly_budget_balance;
	//double total_debt;
	
	char name[1000];
	
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

	government * current_government, * tail_government;
	tail_government = *pointer_to_governments;
	current_government = NULL;
	
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
	inrevenue = 0;
	inearnings = 0;
	inprice = 0;
	inmean_wage=0;
	insold_quantity_in_calendar_month = 0;
	inplanned_output = 0;
	inpayment_account_firm  = 0;
	inprice_last_month=0;
	inmean_specific_skills=0;
	inwage_offer_for_skill_1=0;
	inwage_offer_for_skill_2=0;
	inwage_offer_for_skill_3=0;
	inwage_offer_for_skill_4=0;
	inwage_offer_for_skill_5=0;
	indelivery=0;
	indelivery_to_home_region=0;
	indelivery_to_foreign_region=0;
	instocks=0;
	instocks_in_home_region=0;
	instocks_in_foreign_region=0;
	intotal_debt = 0;
	inassets=0;
	inconsumption_budget_in_month=0;
	inlabour_costs=0;
	incalc_capital_costs=0;
	intotal_interest_payment=0;
	inunit_costs = 0;
	inposted_vacancies= 0;
	inno_applications= 0;
	injob_acceptance= 0;
	inwage_increase=0;


	/*Household*/
	inwage = 0;
	inwage_reservation = 0;
	ingeneral_skill = 0;
	inspecific_skill =0;
	inemployee_firm_id = 0;
	inemployer_region_id = 0;
	inpayment_account = 0.0;
	inno_job_offers = 0;
	inemployed_this_period =0;
	infired_this_period=0;
	inadditional_tax=0;
	/*Mall*/
	intotal_supply =0;
	insales=0;
	insales_of_domestic_firms=0;
	insales_of_foreign_firms=0;

	/*IGFirm*/
	inproductivity=0;
	incum_revenue_last_month=0;
	individend_payment = 0;

	inno_employees = 0;
	inno_research_employees = 0;
	invacancies = 0;
	inresearch_vacancies = 0;
	insales_last_month = 0;
	incapital_good_demand_last_month = 0;
	incapital_good_store_before_production = 0;
	incapital_good_store_after_production = 0;
	incapital_good_price = 0;
	inoutput = 0;
	inplanned_output = 0;
	
	intax_payment= 0;
	intotal_interest_payment= 0;
	intotal_debt_installment_payment= 0;
	intotal_dividend_payment= 0;
	inearnings= 0;
	intotal_debt= 0;
	inexternal_financial_needs= 0;
	intotal_external_financing_obtained= 0;
	inproduction_costs_last_month =  0;

	/*Government*/
	inmonthly_tax_revenues = 0;
	inmonthly_benefit_payment = 0;
	inmonthly_budget_balance = 0;

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
	revenue = 0;
	earnings = 0;
	price = 0;
	sold_quantity_in_calendar_month = 0.0;
	planned_output = 0.0;
	payment_account_firm = 0.0;
	price_last_month=0.0;
	mean_specific_skills=0.0;
	mean_wage=0;
	total_debt = 0.0;
	assets=0.0;
	unit_costs = 0;

	wage_offer_for_skill_1=0;
	wage_offer_for_skill_2=0;
	wage_offer_for_skill_3=0;
	wage_offer_for_skill_4=0;
	wage_offer_for_skill_5=0;

	delivery=0;
	delivery_to_home_region=0;
	delivery_to_foreign_region=0;
	stocks=0;
	stocks_in_home_region=0;
	stocks_in_foreign_region=0;
	labour_costs=0;
	calc_capital_costs=0;
	total_interest_payment=0;

	posted_vacancies= 0;
	no_applications= 0;
	job_acceptance= 0;
	wage_increase =0;
	
	wage = 0.0;
	wage_reservation = 0.0;
	general_skill = 0;
	specific_skill = 0.0;
	employee_firm_id = 0;
	employer_region_id = 0;
	payment_account = 0.0;
	consumption_budget_in_month=0.0;
	no_job_offers = 0;
	employed_this_period=0;
	fired_this_period=0;
	additional_tax=0;
		
	total_supply =0;
	sales=0;
	sales_of_domestic_firms=0;
	sales_of_foreign_firms=0;
	
	/*IGFIRM*/	
	productivity=0;
	cum_revenue_last_month=0;
	dividend_payment = 0;
	
	no_employees = 0;
	no_research_employees = 0;
	vacancies = 0;
	research_vacancies = 0;
	sales_last_month = 0;
	capital_good_demand_last_month = 0;
	capital_good_store_before_production = 0;
	capital_good_store_after_production = 0;
	capital_good_price = 0;
	output = 0;
	planned_output = 0;
	
	tax_payment= 0;
	total_interest_payment= 0;
	total_debt_installment_payment= 0;
	total_dividend_payment= 0;
	earnings= 0;
	total_debt= 0;
	external_financial_needs= 0;
	total_external_financing_obtained= 0;
	production_costs_last_month = 0;

	/*Government*/
	monthly_tax_revenues = 0;
	monthly_benefit_payment = 0;
	monthly_budget_balance = 0;
	
		
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
					current_firm->revenue = revenue;
					current_firm->earnings = earnings;
					current_firm->mean_wage = mean_wage;
					current_firm->price = price;
					current_firm->sold_quantity_in_calendar_month = sold_quantity_in_calendar_month;
					current_firm->planned_output = planned_output;
					current_firm->payment_account_firm = payment_account;
					current_firm->price_last_month=price_last_month;
					current_firm->mean_specific_skills=mean_specific_skills;
					current_firm->wage_offer_for_skill_1=wage_offer_for_skill_1;
					current_firm->wage_offer_for_skill_2=wage_offer_for_skill_2;
					current_firm->wage_offer_for_skill_3=wage_offer_for_skill_3;
					current_firm->wage_offer_for_skill_4=wage_offer_for_skill_4;
					current_firm->wage_offer_for_skill_5=wage_offer_for_skill_5;
					current_firm->delivery=delivery;
					current_firm->delivery_to_home_region=delivery_to_home_region;
					current_firm->delivery_to_foreign_region=delivery_to_foreign_region;
					current_firm->stocks=stocks;
					current_firm->stocks_in_home_region=stocks_in_home_region;
					current_firm->stocks_in_foreign_region=stocks_in_foreign_region;
					current_firm->total_debt=total_debt;
					current_firm->assets=assets;
					current_firm->labour_costs=labour_costs;
					current_firm->calc_capital_costs=calc_capital_costs;
					current_firm->total_interest_payment=total_interest_payment;		
					current_firm->unit_costs=unit_costs;
					current_firm->posted_vacancies=posted_vacancies;	
					current_firm->no_applications=no_applications;	
					current_firm->job_acceptance=job_acceptance;	
					current_firm->no_job_offers=no_job_offers;
					current_firm->wage_increase=wage_increase;					
					
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
					current_household->consumption_budget_in_month=consumption_budget_in_month;
					current_household->no_job_offers=no_job_offers;
					current_household->employed_this_period=employed_this_period;
					current_household->fired_this_period=fired_this_period;
					current_household->additional_tax=additional_tax;
					//printf("consumption_budget_in_month %f, ",consumption_budget_in_month);
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
					current_mall->sales =sales;
					current_mall->sales_of_domestic_firms =sales_of_domestic_firms;
					current_mall->sales_of_foreign_firms =sales_of_foreign_firms;
					
					
					
					
					
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
					current_IGfirm->cum_revenue_last_month = cum_revenue_last_month;
					current_IGfirm->dividend_payment = dividend_payment;
					current_IGfirm->no_employees = no_employees;
					current_IGfirm->no_research_employees = no_research_employees;
					current_IGfirm->research_vacancies = research_vacancies;
					current_IGfirm->vacancies = vacancies;
					current_IGfirm->sales_last_month = sales_last_month;
					current_IGfirm->capital_good_demand_last_month = capital_good_demand_last_month;
				current_IGfirm->capital_good_store_before_production = capital_good_store_before_production;
				current_IGfirm->capital_good_store_after_production = capital_good_store_after_production;
					current_IGfirm->capital_good_price = capital_good_price;
					current_IGfirm->output = output;
					current_IGfirm->planned_output = planned_output;
					
					current_IGfirm->tax_payment = tax_payment;
					current_IGfirm->total_interest_payment = total_interest_payment;
					current_IGfirm->total_debt_installment_payment = total_debt_installment_payment;
					current_IGfirm->total_dividend_payment = total_dividend_payment;
					current_IGfirm->earnings = earnings;
					current_IGfirm->total_debt = total_debt;
					current_IGfirm->external_financial_needs = external_financial_needs;
					current_IGfirm->total_external_financing_obtained = total_external_financing_obtained;
					current_IGfirm->payment_account = payment_account;
					current_IGfirm->production_costs_last_month = production_costs_last_month;
					
					
					
					
					
					//printf("IGfirm %d, ", id);
					
					/* Make tail the next element in the linked list */
					tail_IGfirm = current_IGfirm->next;
				}

			if(strcmp(name, "Government") == 0)
				{
					//printf("Adding agent\n");
					
					/* check if tail is NULL */
					if(tail_government == NULL)
					{
						//printf("tail is null allocate more memory\n");
						/* Allocate memory */
						tail_government = addgovernment(pointer_to_governments, current_government);
					}
					//else printf("tail exisits\n");
					
					/* Make tail the current element to add to */
					current_government = tail_government;
					
					current_government->id = id;
					current_government->region_id = region_id;
					current_government->monthly_tax_revenues = monthly_tax_revenues;
					current_government->monthly_benefit_payment = monthly_benefit_payment;
					current_government->monthly_budget_balance = monthly_budget_balance;
					current_government->total_debt = total_debt;
					
					
					
					
					
					//printf("IGfirm %d, ", id);
					
					/* Make tail the next element in the linked list */
					tail_government = current_government->next;
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

			if(strcmp(buffer, "wage_offer_for_skill_1") == 0) { inwage_offer_for_skill_1 = 1; }
			if(strcmp(buffer, "/wage_offer_for_skill_1") == 0) { inwage_offer_for_skill_1 = 0; }
			if(strcmp(buffer, "wage_offer_for_skill_2") == 0) { inwage_offer_for_skill_2 = 2; }
			if(strcmp(buffer, "/wage_offer_for_skill_2") == 0) { inwage_offer_for_skill_2 = 0; }
			if(strcmp(buffer, "wage_offer_for_skill_3") == 0) { inwage_offer_for_skill_3 = 1; }
			if(strcmp(buffer, "/wage_offer_for_skill_3") == 0) { inwage_offer_for_skill_3 = 0; }
			if(strcmp(buffer, "wage_offer_for_skill_4") == 0) { inwage_offer_for_skill_4 = 1; }
			if(strcmp(buffer, "/wage_offer_for_skill_4") == 0) { inwage_offer_for_skill_4 = 0; }
			if(strcmp(buffer, "wage_offer_for_skill_5") == 0) { inwage_offer_for_skill_5 = 1; }
			if(strcmp(buffer, "/wage_offer_for_skill_5") == 0) { inwage_offer_for_skill_5 = 0; }
			if(strcmp(buffer, "delivery") == 0) { indelivery = 1; }
			if(strcmp(buffer, "/delivery") == 0) { indelivery = 0; }
			if(strcmp(buffer, "delivery_to_home_region") == 0) { indelivery_to_home_region = 1; }
			if(strcmp(buffer, "/delivery_to_home_region") == 0) { indelivery_to_home_region = 0; }
			if(strcmp(buffer, "delivery_to_foreign_region") == 0) { indelivery_to_foreign_region= 1; }
			if(strcmp(buffer, "/delivery_to_foreign_region") == 0) { indelivery_to_foreign_region = 0; }

			if(strcmp(buffer, "stocks") == 0) { instocks = 1; }
			if(strcmp(buffer, "/stocks") == 0) { instocks = 0; }
			if(strcmp(buffer, "stocks_in_home_region") == 0) { instocks_in_home_region = 1; }
			if(strcmp(buffer, "/stocks_in_home_region") == 0) { instocks_in_home_region = 0; }
			if(strcmp(buffer, "stocks_in_foreign_region") == 0) { instocks_in_foreign_region= 1; }
			if(strcmp(buffer, "/stocks_in_foreign_region") == 0) { instocks_in_foreign_region = 0; }



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
			if(strcmp(buffer, "revenue") == 0) { inrevenue = 1; }
			if(strcmp(buffer, "/revenue") == 0) { inrevenue = 0; }
			if(strcmp(buffer, "earnings") == 0) { inearnings = 1; }
			if(strcmp(buffer, "/earnings") == 0) { inearnings = 0; }
			
			if(strcmp(buffer, "price_last_month") == 0) { inprice_last_month = 1; }
			if(strcmp(buffer, "/price_last_month") == 0) { inprice_last_month = 0; }

			if(strcmp(buffer, "price") == 0) { inprice = 1; }
			if(strcmp(buffer, "/price") == 0) { inprice = 0; }
		     if(strcmp(buffer, "sold_quantity_in_calendar_month") == 0) { insold_quantity_in_calendar_month = 1; }
		     if(strcmp(buffer, "/sold_quantity_in_calendar_month") == 0) { insold_quantity_in_calendar_month = 0; }
						if(strcmp(buffer, "planned_output") == 0) { inplanned_output = 1; }
						if(strcmp(buffer, "/planned_output") == 0) { inplanned_output = 0; }
						if(strcmp(buffer, "payment_account") == 0) { inpayment_account_firm = 1; }
						if(strcmp(buffer, "/payment_account") == 0) { inpayment_account_firm = 0; }
						if(strcmp(buffer, "total_debt") == 0) { intotal_debt = 1; }
						if(strcmp(buffer, "/total_debt") == 0) { intotal_debt= 0; }
						if(strcmp(buffer, "total_assets") == 0) { inassets = 1; }
						if(strcmp(buffer, "/total_assets") == 0) { inassets= 0; }

						if(strcmp(buffer, "labour_costs") == 0) { inlabour_costs = 1; }
						if(strcmp(buffer, "/labour_costs") == 0) { inlabour_costs= 0; }
						if(strcmp(buffer, "calc_capital_costs") == 0) { incalc_capital_costs = 1; }
						if(strcmp(buffer, "/calc_capital_costs") == 0) { incalc_capital_costs= 0; }
						if(strcmp(buffer, "total_interest_payment") == 0) { intotal_interest_payment = 1; }
						if(strcmp(buffer, "/total_interest_payment") == 0) { intotal_interest_payment= 0; }
						if(strcmp(buffer, "unit_costs") == 0) { inunit_costs = 1; }
						if(strcmp(buffer, "/unit_costs") == 0) { inunit_costs= 0; }
						if(strcmp(buffer, "posted_vacancies") == 0) { inposted_vacancies = 1; }
						if(strcmp(buffer, "/posted_vacancies") == 0) { inposted_vacancies= 0; }
						if(strcmp(buffer, "no_applications") == 0) { inno_applications = 1; }
						if(strcmp(buffer, "/no_applications") == 0) { inno_applications= 0; }
						if(strcmp(buffer, "job_acceptance") == 0) { injob_acceptance = 1; }
						if(strcmp(buffer, "/job_acceptance") == 0) { injob_acceptance= 0; }
						if(strcmp(buffer, "wage_increase") == 0) { inwage_increase = 1; }
						if(strcmp(buffer, "/wage_increase") == 0) { inwage_increase= 0; }




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
			if(strcmp(buffer, "consumption_budget_in_month") == 0) { inconsumption_budget_in_month = 1; }
			if(strcmp(buffer, "/consumption_budget_in_month") == 0) { inconsumption_budget_in_month = 0; }
			if(strcmp(buffer, "no_job_offers") == 0) { inno_job_offers = 1; }
			if(strcmp(buffer, "/no_job_offers") == 0) { inno_job_offers = 0; }
			if(strcmp(buffer, "employed_this_period") == 0) { inemployed_this_period = 1; }
			if(strcmp(buffer, "/employed_this_period") == 0) { inemployed_this_period = 0; }
			if(strcmp(buffer, "fired_this_period") == 0) { infired_this_period = 1; }
			if(strcmp(buffer, "/fired_this_period") == 0) { infired_this_period = 0; }
			if(strcmp(buffer, "additional_tax") == 0) { inadditional_tax = 1; }
			if(strcmp(buffer, "/additional_tax") == 0) { inadditional_tax = 0; }

			if(strcmp(buffer, "total_supply") == 0) { intotal_supply = 1; }
		       if(strcmp(buffer, "/total_supply") == 0) { intotal_supply = 0; }
			if(strcmp(buffer, "sales") == 0) { insales = 1; }
		       if(strcmp(buffer, "/sales") == 0) { insales = 0; }
			if(strcmp(buffer, "sales_of_domestic_firms") == 0) { insales_of_domestic_firms = 1; }
		       if(strcmp(buffer, "/sales_of_domestic_firms") == 0) { insales_of_domestic_firms = 0; }
			if(strcmp(buffer, "sales_of_foreign_firms") == 0) { insales_of_foreign_firms = 1; }
		       if(strcmp(buffer, "/sales_of_foreign_firms") == 0) { insales_of_foreign_firms = 0; }


			if(strcmp(buffer, "productivity") == 0) { inproductivity = 1; }
		       if(strcmp(buffer, "/productivity") == 0) { inproductivity= 0; }	
			if(strcmp(buffer, "cum_revenue_last_month") == 0) { incum_revenue_last_month = 1; }
		       if(strcmp(buffer, "/cum_revenue_last_month") == 0) { incum_revenue_last_month= 0; }	

			if(strcmp(buffer, "dividend_payment") == 0) { individend_payment = 1; }
		       if(strcmp(buffer, "/dividend_payment") == 0) { individend_payment= 0; }
		       
		       if(strcmp(buffer, "no_research_employees") == 0) { inno_research_employees = 1; }
		       if(strcmp(buffer, "/no_research_employees") == 0) { inno_research_employees= 0; }
			if(strcmp(buffer, "research_vacancies") == 0) { inresearch_vacancies = 1; }
		       if(strcmp(buffer, "/research_vacancies") == 0) { inresearch_vacancies= 0; }
			if(strcmp(buffer, "sales_last_month") == 0) { insales_last_month = 1; }
		       if(strcmp(buffer, "/sales_last_month") == 0) { insales_last_month= 0; }
			if(strcmp(buffer, "capital_good_demand_last_month") == 0) { incapital_good_demand_last_month = 1; }
		       if(strcmp(buffer, "/capital_good_demand_last_month") == 0) { incapital_good_demand_last_month= 0; }
	if(strcmp(buffer, "capital_good_store_before_production") == 0) { incapital_good_store_before_production = 1; }
	if(strcmp(buffer, "/capital_good_store_before_production") == 0) { incapital_good_store_before_production= 0; }
	if(strcmp(buffer, "capital_good_store_after_production") == 0) { incapital_good_store_after_production = 1; }
	if(strcmp(buffer, "/capital_good_store_after_production") == 0) { incapital_good_store_after_production= 0; }
			if(strcmp(buffer, "capital_good_price") == 0) { incapital_good_price = 1; }
		       if(strcmp(buffer, "/capital_good_price") == 0) { incapital_good_price= 0; }
		       
		       if(strcmp(buffer, "tax_payment") == 0) { intax_payment = 1; }
		       if(strcmp(buffer, "/tax_payment") == 0) { intax_payment= 0; }
			if(strcmp(buffer, "total_interest_payment") == 0) { intotal_interest_payment = 1; }
		       if(strcmp(buffer, "/total_interest_payment") == 0) { intotal_interest_payment= 0; }
			if(strcmp(buffer, "total_debt_installment_payment") == 0) { intotal_debt_installment_payment= 1; }
		       if(strcmp(buffer, "/total_debt_installment_payment") == 0) { intotal_debt_installment_payment= 0; }
			if(strcmp(buffer, "total_dividend_payment") == 0) { intotal_dividend_payment = 1; }
		       if(strcmp(buffer, "/total_dividend_payment") == 0) { intotal_dividend_payment= 0; }
			if(strcmp(buffer, "external_financial_needs") == 0) { inexternal_financial_needs= 1; }
		       if(strcmp(buffer, "/external_financial_needs") == 0) { inexternal_financial_needs= 0; }
			if(strcmp(buffer, "total_external_financing_obtained") == 0) { intotal_external_financing_obtained = 1; }
		       if(strcmp(buffer, "/total_external_financing_obtained") == 0) { intotal_external_financing_obtained= 0; }

			if(strcmp(buffer, "production_costs_last_month") == 0) { inproduction_costs_last_month = 1; }
		       if(strcmp(buffer, "/production_costs_last_month") == 0) { inproduction_costs_last_month = 0; }
		       
		       

			if(strcmp(buffer, "monthly_tax_revenues") == 0) { inmonthly_tax_revenues = 1; }
		       if(strcmp(buffer, "/monthly_tax_revenues") == 0) { inmonthly_tax_revenues= 0; }
			if(strcmp(buffer, "monthly_benefit_payment") == 0) { inmonthly_benefit_payment= 1; }
		       if(strcmp(buffer, "/monthly_benefit_payment") == 0) { inmonthly_benefit_payment= 0; }
			if(strcmp(buffer, "monthly_budget_balance") == 0) { inmonthly_budget_balance = 1; }
		       if(strcmp(buffer, "/monthly_budget_balance") == 0) { inmonthly_budget_balance= 0; }
			if(strcmp(buffer, "total_debt") == 0) { intotal_debt = 1; }
		       if(strcmp(buffer, "/total_debt") == 0) { intotal_debt= 0; }



			
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

			if(inagent && inwage_offer_for_skill_1)  { wage_offer_for_skill_1  = atof(buffer); }
			if(inagent && inwage_offer_for_skill_2)  { wage_offer_for_skill_2  = atof(buffer); }
			if(inagent && inwage_offer_for_skill_3)  { wage_offer_for_skill_3  = atof(buffer); }
			if(inagent && inwage_offer_for_skill_4)  { wage_offer_for_skill_4  = atof(buffer); }
			if(inagent && inwage_offer_for_skill_5)  { wage_offer_for_skill_5  = atof(buffer); }
			if(inagent && indelivery)  { delivery  = atof(buffer); }
			if(inagent && indelivery_to_home_region)  { delivery_to_home_region  = atof(buffer); }
			if(inagent && indelivery_to_foreign_region)  { delivery_to_foreign_region  = atof(buffer); }

			if(inagent && instocks)  {stocks  = atof(buffer); }
			if(inagent && instocks_in_home_region)  { stocks_in_home_region  = atof(buffer); }
			if(inagent && instocks_in_foreign_region)  { stocks_in_foreign_region  = atof(buffer); }

			if(inagent && intechnology)  { technology  = atof(buffer); }
			if(inagent && inno_employees)  { no_employees  = atoi(buffer); }
			if(inagent && invacancies)  { vacancies  = atof(buffer); }
			if(inagent && inaverage_g_skill)  { average_g_skill  = atof(buffer); }
			if(inagent && inoutput)  { output  = atof(buffer); }

			if(inagent && inmean_wage)  { mean_wage = atof(buffer); }
			if(inagent && incapital_stock)  { capital_stock  = atof(buffer); }
			if(inagent && inrevenue)  { revenue  = atof(buffer); }
			if(inagent && inearnings)  { earnings  = atof(buffer); }
			if(inagent && inprice)  { price  = atof(buffer); }
			if(inagent && insold_quantity_in_calendar_month)  { sold_quantity_in_calendar_month  = atof(buffer); }
if(inagent && inplanned_output)  { planned_output  = atof(buffer); }
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
			if(inagent && intotal_debt)  { total_debt  = atof(buffer); }
			if(inagent && inassets)  { assets  = atof(buffer); }
			if(inagent && inconsumption_budget_in_month)  { consumption_budget_in_month  = atof(buffer); }
			if(inagent && inno_job_offers	)  { no_job_offers  = atof(buffer); }
			if(inagent && inemployed_this_period	)  { employed_this_period  = atof(buffer); }
			if(inagent && infired_this_period	)  { fired_this_period  = atof(buffer); }
			if(inagent && inadditional_tax	)  { additional_tax  = atof(buffer); }
			
		
			if(inagent && incum_revenue_last_month)  {cum_revenue_last_month  = atof(buffer); }
			if(inagent && inproductivity)  { productivity  = atof(buffer); }
			if(inagent && intotal_supply)  { total_supply  = atof(buffer); }

			if(inagent && individend_payment)  { dividend_payment  = atof(buffer); }
			
			if(inagent && inno_research_employees)  { no_research_employees  = atof(buffer); }
	if(inagent && inresearch_vacancies)  { research_vacancies  = atof(buffer); }
	if(inagent && insales_last_month)  { sales_last_month  = atof(buffer); }
	if(inagent && incapital_good_demand_last_month)  { capital_good_demand_last_month  = atof(buffer); }
	if(inagent && incapital_good_store_before_production)  { capital_good_store_before_production  = atof(buffer); }
	if(inagent && incapital_good_store_after_production)  { capital_good_store_after_production  = atof(buffer); }
	if(inagent && incapital_good_price)  { capital_good_price  = atof(buffer); }
	
	if(inagent && intax_payment)  {tax_payment = atof(buffer); }
	if(inagent && intotal_interest_payment)  { total_interest_payment  = atof(buffer); }
	if(inagent && intotal_debt_installment_payment)  { total_debt_installment_payment  = atof(buffer); }
	if(inagent && intotal_dividend_payment)  { total_dividend_payment  = atof(buffer); }
	if(inagent && inexternal_financial_needs)  { external_financial_needs  = atof(buffer); }
	if(inagent && intotal_external_financing_obtained)  { total_external_financing_obtained  = atof(buffer); }
	if(inagent && inproduction_costs_last_month)  { production_costs_last_month  = atof(buffer); }
			
			

			if(inagent && insales)  { sales  = atof(buffer); }
			if(inagent && insales_of_domestic_firms)  { sales_of_domestic_firms  = atof(buffer); }
			if(inagent && insales_of_foreign_firms)  { sales_of_foreign_firms  = atof(buffer); }

			if(inagent && inmonthly_tax_revenues)  { monthly_tax_revenues = atof(buffer); }
			if(inagent && inmonthly_benefit_payment)  { monthly_benefit_payment  = atof(buffer); }
			if(inagent && inmonthly_budget_balance)  { monthly_budget_balance  = atof(buffer); }
			if(inagent && intotal_debt)  { total_debt  = atof(buffer); }

			if(inagent && inlabour_costs)  { labour_costs  = atof(buffer); }
			if(inagent && incalc_capital_costs)  { calc_capital_costs  = atof(buffer); }
			if(inagent && intotal_interest_payment)  { total_interest_payment  = atof(buffer); }
			if(inagent && inunit_costs)  {unit_costs  = atof(buffer); }

			if(inagent && inposted_vacancies)  {posted_vacancies  = atof(buffer); }
			if(inagent && inno_applications)  {no_applications  = atof(buffer); }
			if(inagent && injob_acceptance)  {job_acceptance  = atof(buffer); }
			if(inagent && inwage_increase)  {wage_increase  = atof(buffer); }



			
	
			
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

	if(tail_government)
	{
		freegovernments(tail_government);
		/* Make pointer to tail equal NULL */
		if(current_government) { current_government->next = NULL; }
	}


	
	/* Close the file */
	fclose(file);
	
	/*printagentdata(pointer_to_cells);*/
	
	return 1;
	}
}

void savedatatofile(int itno, firm ** pointer_to_firms, household ** pointer_to_households,IGfirm ** pointer_to_IGfirms,mall ** pointer_to_malls,government ** pointer_to_governments)
{
	FILE *file;
	char data[1000];
	firm * current_firm;
	household * current_household;
	IGfirm * current_IGfirm;
	mall* current_mall;
	government* current_government;
	current_firm = *pointer_to_firms;
	current_household = *pointer_to_households;
	current_mall = *pointer_to_malls;
	current_IGfirm = *pointer_to_IGfirms;
	current_government = *pointer_to_governments;


	
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
	commuters[0][n][o] is the sum over all skill groups. commuters[1][n][o] is for skill group 		1 and so on...*/
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
		Data_Household[i].reservation_wage_skill_1 = 0.0;
		Data_Household[i].reservation_wage_skill_2 = 0.0;
		Data_Household[i].reservation_wage_skill_3 = 0.0;
		Data_Household[i].reservation_wage_skill_4 = 0.0;
		Data_Household[i].reservation_wage_skill_5 = 0.0;
		Data_Household[i].consumption_budget_in_month=0.0;
		Data_Household[i].no_job_offers=0.0;
		Data_Household[i].just_employed=0.0;
		Data_Household[i].employed_this_period=0.0;
		Data_Household[i].fired_this_period=0.0;
		Data_Household[i].additional_tax=0.0;
		Data_Household[i].reemployed=0.0;
		
	}


	
	current_household = *pointer_to_households;
	while(current_household)
	{
		
	/*GLOBAL DATA: Is stored in Data_Household[0]*/
		Data_Household[0].no_households++;
		Data_Household[0].average_specific_skill += current_household->specific_skill;
		Data_Household[0].average_payment_account += current_household->payment_account;
		Data_Household[0].consumption_budget_in_month+=current_household->consumption_budget_in_month;
		Data_Household[0].employed_this_period += current_household->employed_this_period;
		Data_Household[0].fired_this_period += current_household->fired_this_period;
		//Data_Household[0].additional_tax += current_household->additional_tax;


		
		/*If employed*/
		if(current_household->employee_firm_id > -1)
		{
			Data_Household[0].employed++;
			Data_Household[0].average_wage += current_household->wage;
			Data_Household[0].no_job_offers += current_household->no_job_offers;	
			Data_Household[0].additional_tax += current_household->additional_tax;
			if(current_household->additional_tax > 0)
			{
				Data_Household[0].reemployed++;
			}
					
			if(current_household->region_id != current_household->employer_region_id)
			{
				Data_Household[0].commuter++;	
			}
			if(current_household->no_job_offers > 0)
			{
				Data_Household[0].just_employed++;	
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
			else
			{
				Data_Household[0].reservation_wage_skill_1 += current_household->wage_reservation;	
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
			else
			{
				Data_Household[0].reservation_wage_skill_2 += current_household->wage_reservation;	
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
			else
			{
				Data_Household[0].reservation_wage_skill_3 += current_household->wage_reservation;	
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
			else
			{
				Data_Household[0].reservation_wage_skill_4 += current_household->wage_reservation;	
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
			else
			{
				Data_Household[0].reservation_wage_skill_5 += current_household->wage_reservation;	
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
				Data_Household[i].consumption_budget_in_month+=current_household->consumption_budget_in_month;
				Data_Household[i].no_job_offers += current_household->no_job_offers;	
				Data_Household[i].employed_this_period += current_household->employed_this_period;
				Data_Household[i].fired_this_period += current_household->fired_this_period;
				//Data_Household[i].additional_tax += current_household->additional_tax;
				
				/*If employed*/
				if(current_household->employee_firm_id > -1)
				{
					Data_Household[i].employed++;
					Data_Household[i].average_wage +=
						current_household->wage;
				Data_Household[i].additional_tax += current_household->additional_tax;
				if(current_household->additional_tax > 0)
				{
					Data_Household[i].reemployed++;
				}
					
					if(current_household->region_id != 
					   current_household->employer_region_id)
					{
						Data_Household[i].commuter++;	
					}
					if(current_household->no_job_offers > 0)
					{
						Data_Household[i].just_employed++;	
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
					else
					{
					Data_Household[i].reservation_wage_skill_1 += current_household->wage_reservation;	
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
					else
					{
					Data_Household[i].reservation_wage_skill_2 += current_household->wage_reservation;	
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
					else
					{
					Data_Household[i].reservation_wage_skill_3 += current_household->wage_reservation;	
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
					else
					{
					Data_Household[i].reservation_wage_skill_4 += current_household->wage_reservation;	
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
					else
					{
					Data_Household[i].reservation_wage_skill_5 += current_household->wage_reservation;	
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


/*Regions: additional-taxes*/
	file = fopen("data-additional-taxes-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	
	//int i;
	for(i = 0; i <= 0; i++)
	{
		sprintf(data, "%f", Data_Household[i].additional_tax );
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].employed_this_period );
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].reemployed );
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].fired_this_period );
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].consumption_budget_in_month );
		fputs(data, file);
		fputs("\t", file);	
	}

	fputs("\n", file);

	fclose(file);

	
/*Regions: employed*/
	file = fopen("data-employed-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	
	//int i;
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_Household[i].employed );
		fputs(data, file);
		fputs("\t", file);	
	}

	fputs("\n", file);

	fclose(file);
	
	
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



/*Regions: reservation_wages*/
	file = fopen("data-reservation-wage-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	
	//int i;
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_Household[i].reservation_wage_skill_1 
		/(Data_Household[i].no_households_skill_1-Data_Household[i].employed_skill_1));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].reservation_wage_skill_2 
		/(Data_Household[i].no_households_skill_2-Data_Household[i].employed_skill_2));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].reservation_wage_skill_3 
		/(Data_Household[i].no_households_skill_3-Data_Household[i].employed_skill_3));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].reservation_wage_skill_4 
		/(Data_Household[i].no_households_skill_4-Data_Household[i].employed_skill_4));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].reservation_wage_skill_5 
		/(Data_Household[i].no_households_skill_5-Data_Household[i].employed_skill_5));
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);




/*Regions: specific_skills*/
	file = fopen("data-specific-skill-household-region.csv", "a");

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

/*Regions: Consumption budget*/
	file = fopen("data-consumption-budget-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	
	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_Household[i].consumption_budget_in_month
		/Data_Household[i].no_households);
		fputs(data, file);
		fputs("\t", file);
		
	}

	fputs("\n", file);

	fclose(file);



	/*if(itno%20 == 0)
	{int sum = 0;
	for(m = 0; m <= 5; m++)
	{

		printf("SKILL: %d\n", m);
		for(n = 1; n <= no_regions; n++)
		{

			for(o = 1; o <= no_regions; o++)
			{	
				printf("%d",commuters[m][n][o]);
				printf("  ");
				sum += commuters[m][n][o];
			}
			printf("\n");
			printf("_________________________________\n");
			
		}
		printf("\n");
		printf("/////////////////////////////\n");
	}
	
	}*/

/*Regions: commuter region  */
	file = fopen("data-commuter-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%i", commuters[0][1][2]+commuters[0][2][1]);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%i", commuters[0][1][2]);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%i", commuters[0][2][1]);
	fputs(data, file);
	fputs("\t", file);
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_Household[i].employed );
		fputs(data, file);
		fputs("\t", file);
	}
			
	fputs("\n", file);

	fclose(file);

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
		Data_Mall[i].sales = 0.0;
		Data_Mall[i].sales_of_domestic_firms = 0.0;
		Data_Mall[i].sales_of_foreign_firms = 0.0;	
	}


	current_mall = *pointer_to_malls;
	while(current_mall)
	{
		Data_Mall[0].supply += current_mall->total_supply;
		Data_Mall[0].sales += current_mall->sales;
		Data_Mall[0].sales_of_domestic_firms += current_mall->sales_of_domestic_firms;
		Data_Mall[0].sales_of_foreign_firms += current_mall->sales_of_foreign_firms;
		
		int i;
		for(i = 1; i <= no_regions; i++)
		{
			if(current_mall->region_id == Data_Mall[i].region_id)
			{
				Data_Mall[i].supply = current_mall->total_supply;
				Data_Mall[i].sales = current_mall->sales;
				Data_Mall[i].sales_of_domestic_firms = current_mall->sales_of_domestic_firms;
				Data_Mall[i].sales_of_foreign_firms = current_mall->sales_of_foreign_firms;
			}
		}
		
		current_mall = current_mall->next;
		
	}

	/*SALES*/
		file = fopen("data-sales-region.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);

		for(i = 0; i <= no_regions; i++)
		{
			sprintf(data, "%f", Data_Mall[i].sales );
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", Data_Mall[i].sales_of_domestic_firms );
			fputs(data, file);
			fputs("\t", file);
			sprintf(data, "%f", Data_Mall[i].sales_of_foreign_firms);
			fputs(data, file);
			fputs("\t", file);
		}

		fputs("\n", file);

		fclose(file);


	
		file = fopen("data-sales-origin.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Mall[0].sales );
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Mall[1].sales_of_domestic_firms+Data_Mall[2].sales_of_foreign_firms );
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Mall[2].sales_of_domestic_firms+Data_Mall[1].sales_of_foreign_firms );
		fputs(data, file);
		fputs("\t", file);

		fputs("\n", file);

		fclose(file);

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
/*----------------------------Government-------------- DATA---------------------------------------*/

/*Initialization of the STRUCT Governent_data*/
	Government_data Data_Government[no_regions+1];
	
	for(i = 0; i <= no_regions; i++)
	{
		Data_Government[i].region_id = i;
		Data_Government[i].monthly_tax_revenues = 0.0;
		Data_Government[i].monthly_benefit_payment = 0.0;
		Data_Government[i].monthly_budget_balance = 0.0;
		Data_Government[i].total_debt = 0.0;	
	}


	current_government = *pointer_to_governments;
	while(current_government)
	{
		Data_Government[0].monthly_tax_revenues += current_government->monthly_tax_revenues;
		Data_Government[0].monthly_benefit_payment += current_government->monthly_benefit_payment;
		Data_Government[0].monthly_budget_balance += current_government->monthly_budget_balance;
		Data_Government[0].total_debt += current_government->total_debt;	
	
		int i;
		for(i = 1; i <= no_regions; i++)
		{
			if(current_government->region_id == Data_Government[i].region_id)
			{
				Data_Government[i].monthly_tax_revenues = current_government->monthly_tax_revenues;
				Data_Government[i].monthly_benefit_payment = current_government->monthly_benefit_payment;
				Data_Government[i].monthly_budget_balance = current_government->monthly_budget_balance;
				Data_Government[i].total_debt = current_government->total_debt;	
			}
		}
		
		current_government= current_government->next;
		
	}

/*Regions: tax revenue*/

	file = fopen("data-government-tax-revenues-region.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);

		for(i = 0; i <= no_regions; i++)
		{
			sprintf(data, "%f", Data_Government[i].monthly_tax_revenues );
			fputs(data, file);
			fputs("\t", file);
		}

		fputs("\n", file);

		fclose(file);

/*Regions: benefit payment*/

	file = fopen("data-government-benefit-payment-region.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);

		for(i = 0; i <= no_regions; i++)
		{
			sprintf(data, "%f", Data_Government[i].monthly_benefit_payment );
			fputs(data, file);
			fputs("\t", file);
		}

		fputs("\n", file);

		fclose(file);

/*Regions: budget balance*/

	file = fopen("data-government-budget-balance-region.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);

		for(i = 0; i <= no_regions; i++)
		{
			sprintf(data, "%f", Data_Government[i].monthly_budget_balance );
			fputs(data, file);
			fputs("\t", file);
		}

		fputs("\n", file);

		fclose(file);

/*Regions: total debt*/

	file = fopen("data-government-total-debt-region.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);

		for(i = 0; i <= no_regions; i++)
		{
			sprintf(data, "%f", Data_Government[i].total_debt );
			fputs(data, file);
			fputs("\t", file);
		}

		fputs("\n", file);

		fclose(file);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/	
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------IGFirm-------------- DATA---------------------------------------*/
	
	/*Initialization of the STRUCT IGFirm_data*/
	IGFirm_data Data_IGFirm[no_regions+1];
	
	for(i = 0; i <= no_regions; i++)
	{
		Data_IGFirm[i].region_id = i;
		Data_IGFirm[i].no_igfirms = 0.0;
		Data_IGFirm[i].productivity = 0;
		Data_IGFirm[i].cum_revenue_last_month = 0;
		Data_IGFirm[i].no_employees = 0;
		Data_IGFirm[i].no_research_employees = 0;
		Data_IGFirm[i].research_vacancies = 0;
		Data_IGFirm[i].vacancies = 0;
		Data_IGFirm[i].sales_last_month = 0;
		Data_IGFirm[i].capital_good_demand_last_month = 0;
		Data_IGFirm[i].capital_good_store_before_production = 0;
		Data_IGFirm[i].capital_good_store_after_production = 0;
		Data_IGFirm[i].capital_good_price = 0;
		Data_IGFirm[i].output = 0;
		Data_IGFirm[i].planned_output = 0;
		/*Data_IGFirm[i].wage_offer = 0;
		Data_IGFirm[i].wage_offer_for_skill_1 = 0;
		Data_IGFirm[i].wage_offer_for_skill_2 = 0;
		Data_IGFirm[i].wage_offer_for_skill_3 = 0;
		Data_IGFirm[i].wage_offer_for_skill_4 = 0;
		Data_IGFirm[i].wage_offer_for_skill_5 = 0;
		Data_IGFirm[i].wage_offer_for_rd = 0;
		Data_IGFirm[i].mean_specific_skills = 0;*/
		Data_IGFirm[i].tax_payment = 0;
		Data_IGFirm[i].total_interest_payment = 0;
		Data_IGFirm[i].total_debt_installment_payment = 0;
		Data_IGFirm[i].total_dividend_payment = 0;
		Data_IGFirm[i].earnings = 0;
		Data_IGFirm[i].total_debt = 0;
		Data_IGFirm[i].external_financial_needs = 0;
		Data_IGFirm[i].total_external_financing_obtained = 0;
		Data_IGFirm[i].payment_account = 0;	
		Data_IGFirm[i].production_costs_last_month = 0;
	}


	current_IGfirm = *pointer_to_IGfirms;
	while(current_IGfirm)
	{
		Data_IGFirm[0].no_igfirms++;
		Data_IGFirm[0].productivity+= current_IGfirm->productivity;
		Data_IGFirm[0].cum_revenue_last_month += current_IGfirm->cum_revenue_last_month;
		Data_IGFirm[0].no_employees+= current_IGfirm->no_employees;
		Data_IGFirm[0].no_research_employees+= current_IGfirm->no_research_employees;
		Data_IGFirm[0].research_vacancies+= current_IGfirm->research_vacancies;
		Data_IGFirm[0].vacancies+= current_IGfirm->vacancies;
		Data_IGFirm[0].sales_last_month+= current_IGfirm->sales_last_month;
		Data_IGFirm[0].capital_good_demand_last_month+= current_IGfirm->capital_good_demand_last_month;
		Data_IGFirm[0].capital_good_store_before_production+= 
		current_IGfirm->capital_good_store_before_production;
		Data_IGFirm[0].capital_good_store_after_production+= current_IGfirm->capital_good_store_after_production;
		Data_IGFirm[0].capital_good_price+= current_IGfirm->capital_good_price;
		Data_IGFirm[0].output+= current_IGfirm->output;
		Data_IGFirm[0].planned_output+= current_IGfirm->planned_output;
		/*Data_IGFirm[0].wage_offer+= current_IGfirm->wage_offer;
		Data_IGFirm[0].wage_offer_for_skill_1+= current_IGfirm->wage_offer_for_skill_1;
		Data_IGFirm[0].wage_offer_for_skill_2+= current_IGfirm->wage_offer_for_skill_2;
		Data_IGFirm[0].wage_offer_for_skill_3+= current_IGfirm->wage_offer_for_skill_3;
		Data_IGFirm[0].wage_offer_for_skill_4+= current_IGfirm->wage_offer_for_skill_4;
		Data_IGFirm[0].wage_offer_for_skill_5+= current_IGfirm->wage_offer_for_skill_5;
		Data_IGFirm[0].wage_offer_for_rd+= current_IGfirm->wage_offer_for_rd;
		Data_IGFirm[0].mean_specific_skills+= current_IGfirm->mean_specific_skills;*/

		Data_IGFirm[0].tax_payment += current_IGfirm->tax_payment;
		Data_IGFirm[0].total_interest_payment += current_IGfirm->total_interest_payment ;
		Data_IGFirm[0].total_debt_installment_payment += current_IGfirm->total_debt_installment_payment;
		Data_IGFirm[0].total_dividend_payment += current_IGfirm->total_dividend_payment;
		Data_IGFirm[0].earnings += current_IGfirm->earnings;
		Data_IGFirm[0].total_debt += current_IGfirm->total_debt;
		Data_IGFirm[0].external_financial_needs += current_IGfirm->external_financial_needs;
		Data_IGFirm[0].total_external_financing_obtained += current_IGfirm->total_external_financing_obtained;
		Data_IGFirm[0].payment_account += current_IGfirm->payment_account;
		Data_IGFirm[0].production_costs_last_month += current_IGfirm->production_costs_last_month;

		
		int i;
		for(i = 1; i <= no_regions; i++)
		{
			if(current_IGfirm->region_id == Data_IGFirm[i].region_id)
			{
				Data_IGFirm[i].no_igfirms++;
				Data_IGFirm[i].productivity+= current_IGfirm->productivity;
				Data_IGFirm[i].cum_revenue_last_month += current_IGfirm->cum_revenue_last_month;
				Data_IGFirm[i].no_employees+= current_IGfirm->no_employees;
				Data_IGFirm[i].no_research_employees+= current_IGfirm->no_research_employees;
				Data_IGFirm[i].research_vacancies+= current_IGfirm->research_vacancies;
				Data_IGFirm[i].vacancies+= current_IGfirm->vacancies;
				Data_IGFirm[i].sales_last_month+= current_IGfirm->sales_last_month;
				Data_IGFirm[i].capital_good_demand_last_month+= 
				current_IGfirm->capital_good_demand_last_month;
				Data_IGFirm[i].capital_good_store_before_production+= 
				current_IGfirm->capital_good_store_before_production;
				Data_IGFirm[i].capital_good_store_after_production+= 
				current_IGfirm->capital_good_store_after_production;
				Data_IGFirm[i].capital_good_price+= current_IGfirm->capital_good_price;
				Data_IGFirm[i].output+= current_IGfirm->output;
				Data_IGFirm[i].planned_output+= current_IGfirm->planned_output;
				/*Data_IGFirm[i].wage_offer+= current_IGfirm->wage_offer;
				Data_IGFirm[i].wage_offer_for_skill_1+= current_IGfirm->wage_offer_for_skill_1;
				Data_IGFirm[i].wage_offer_for_skill_2+= current_IGfirm->wage_offer_for_skill_2;
				Data_IGFirm[i].wage_offer_for_skill_3+= current_IGfirm->wage_offer_for_skill_3;
				Data_IGFirm[i].wage_offer_for_skill_4+= current_IGfirm->wage_offer_for_skill_4;
				Data_IGFirm[i].wage_offer_for_skill_5+= current_IGfirm->wage_offer_for_skill_5;
				Data_IGFirm[i].wage_offer_for_rd+= current_IGfirm->wage_offer_for_rd;
				Data_IGFirm[i].mean_specific_skills+= current_IGfirm->mean_specific_skills;*/

				Data_IGFirm[i].tax_payment += current_IGfirm->tax_payment;
				Data_IGFirm[i].total_interest_payment += current_IGfirm->total_interest_payment ;
				Data_IGFirm[i].total_debt_installment_payment += 
				current_IGfirm->total_debt_installment_payment;
				Data_IGFirm[i].total_dividend_payment += current_IGfirm->total_dividend_payment;
				Data_IGFirm[i].earnings += current_IGfirm->earnings;
				Data_IGFirm[i].total_debt += current_IGfirm->total_debt;
				Data_IGFirm[i].external_financial_needs += current_IGfirm->external_financial_needs;
				Data_IGFirm[i].total_external_financing_obtained +=
				 current_IGfirm->total_external_financing_obtained;
				Data_IGFirm[i].payment_account += current_IGfirm->payment_account;
				Data_IGFirm[i].production_costs_last_month += current_IGfirm->production_costs_last_month;
	
			}
		}
		
		current_IGfirm = current_IGfirm->next;
		
	}


//Regions: tax interest debt installment dividend payments
	file = fopen("data-IGfirm-payments-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].tax_payment);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_IGFirm[i].total_interest_payment);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_IGFirm[i].total_debt_installment_payment);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_IGFirm[i].total_dividend_payment);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_IGFirm[i].production_costs_last_month);
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);

//Regions: financial needs, financing obtaind
	file = fopen("data-IGfirm-external-financing-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].external_financial_needs);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_IGFirm[i].total_external_financing_obtained);
		fputs(data, file);
		fputs("\t", file);
		
	}
		
	fputs("\n", file);

	fclose(file);

//Regions: payment account
	file = fopen("data-IGfirm-payment-account-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].payment_account);
		fputs(data, file);
		fputs("\t", file);
		
		
	}
		
	fputs("\n", file);

	fclose(file);

//Regions: earnings
	file = fopen("data-IGfirm-earnings-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].earnings);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_IGFirm[i].cum_revenue_last_month);
		fputs(data, file);
		fputs("\t", file);
		
		
	}
		
	fputs("\n", file);

	fclose(file);






//Regions: capital_good_demand
	file = fopen("data-IGfirm-capital-good-demand-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].capital_good_demand_last_month);
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);


//Regions: IGFirm production/ planned Production
	file = fopen("data-IGfirm-output-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].output);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_IGFirm[i].planned_output);
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);
	
	
//Region: IGFirm capital good store: before production-> minimum; after production->maximum
	file = fopen("data-IGfirm-capital-good-store-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].capital_good_store_before_production);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_IGFirm[i].capital_good_store_after_production);
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);


//Region: IG firm sales
	file = fopen("data-IGfirm-sales-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].sales_last_month);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);
	fclose(file);



//Region: IGfirm no_employees and no_research_employees
	file = fopen("data-IGfirm-employees-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].no_employees);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_IGFirm[i].no_research_employees);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);
	fclose(file);

	//Region: capital good price
	file = fopen("data-IGfirm-capital-good-price-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].capital_good_price);
		fputs(data, file);
		fputs("\t", file);
		
	}

	fputs("\n", file);
	fclose(file);



	file = fopen("data-technological-frontier.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].productivity );
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);



	file = fopen("data-IGfirm-revenues.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].cum_revenue_last_month );
		fputs(data, file);
		fputs("\t", file);
	}
	
	fputs("\n", file);

	fclose(file);




	file = fopen("data-IGfirm-dividend-payment.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_IGFirm[i].total_dividend_payment );
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/	
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*----------------------------FIRMS DAILY AND REGIONAL DATA-------------------------------------*/

	
	double table[81];
	double table_labour_costs[81];
	double table_capital_costs[81];
	double table_interest_payments[81];
	double table_unit_costs[81];
	double table_unit_costs_difference[81];
	double table_price[81];
	double table_output[81];
	double table_employees[81];

	
/*Initialization of the STRUCT Firm_data*/
	

	
	Firm_data Data_Firm[no_regions+1];
	
	
	for(i = 0; i <= no_regions; i++)
	{
		Data_Firm[i].region_id = i;
		Data_Firm[i].no_firms = 0.0;
		Data_Firm[i].total_no_firms=0;
		Data_Firm[i].no_employees = 0.0;		
		Data_Firm[i].vacancies = 0.0;
		Data_Firm[i].average_wage = 0.0;
		Data_Firm[i].average_specific_skill = 0.0;
		Data_Firm[i].average_general_skill = 0.0;
		Data_Firm[i].sold_quantity_in_calendar_month = 0.0;
		Data_Firm[i].average_payment_account = 0.0;
		Data_Firm[i].average_price = 0.0;
		Data_Firm[i].capital_stock = 0.0;
		Data_Firm[i].earnings = 0.0;
		Data_Firm[i].revenues = 0.0;
		Data_Firm[i].planned_output = 0.0;
		Data_Firm[i].output = 0.0;
		Data_Firm[i].average_technology = 0.0;
		Data_Firm[i].wage_offer = 0.0;
		Data_Firm[i].wage_offer_for_skill_1 = 0.0;
		Data_Firm[i].wage_offer_for_skill_2 = 0.0;
		Data_Firm[i].wage_offer_for_skill_3 = 0.0;
		Data_Firm[i].wage_offer_for_skill_4 = 0.0;
		Data_Firm[i].wage_offer_for_skill_5 = 0.0;
		Data_Firm[i].delivery = 0.0;
		Data_Firm[i].delivery_to_home_region = 0.0;
		Data_Firm[i].delivery_to_foreign_region = 0.0;
		Data_Firm[i].stocks = 0.0;
		Data_Firm[i].stocks_in_home_region = 0.0;
		Data_Firm[i].stocks_in_foreign_region = 0.0;
		Data_Firm[i].price_index_mall = 0.0;
		Data_Firm[i].price_index_home_mall= 0.0;
		Data_Firm[i].price_index_foreign_mall = 0.0;
		Data_Firm[i].total_debt = 0.0;
		Data_Firm[i].assets = 0.0;
		Data_Firm[i].debt_active_firms = 0.0;
		Data_Firm[i].assets_active_firms = 0.0;
		Data_Firm[i].debt_asset_ratio_active_firms=0.0;
		Data_Firm[i].debt_asset_ratio=0.0;
		Data_Firm[i].count_debt_asset_ratio_threshold=0;
		Data_Firm[i].labour_costs = 0.0;
		Data_Firm[i].calc_capital_costs = 0.0;
		Data_Firm[i].total_interest_payment = 0.0;
		Data_Firm[i].unit_costs = 0.0;
		Data_Firm[i].price = 0.0;
		Data_Firm[i].posted_vacancies = 0.0;
		Data_Firm[i].no_applications = 0.0;
		Data_Firm[i].job_acceptance = 0.0;
		Data_Firm[i].no_job_offers = 0.0;
		Data_Firm[i].wage_increase = 0.0;

	
			
	}


	current_firm = *pointer_to_firms;

	while(current_firm)
	{
		
		Data_Firm[0].total_no_firms++;
		
		if(current_firm->no_employees > 0)
		{
			Data_Firm[0].no_firms++;
			Data_Firm[0].no_employees += current_firm->no_employees;
			Data_Firm[0].vacancies += current_firm->vacancies;
			Data_Firm[0].average_wage += (current_firm->mean_wage*current_firm->no_employees);
			Data_Firm[0].average_technology += (current_firm->technology*current_firm->output);
			Data_Firm[0].average_specific_skill += (current_firm->mean_specific_skills*
						      		current_firm->no_employees);
			Data_Firm[0].average_general_skill += (current_firm->average_g_skill*current_firm->no_employees);
			Data_Firm[0].output += current_firm->output;
			Data_Firm[0].sold_quantity_in_calendar_month += current_firm->sold_quantity_in_calendar_month;
			Data_Firm[0].average_payment_account += current_firm->payment_account_firm;
			Data_Firm[0].average_price += (current_firm->price*current_firm->sold_quantity_in_calendar_month);
			Data_Firm[0].capital_stock += (current_firm->capital_stock);
			Data_Firm[0].earnings += current_firm->earnings;
			Data_Firm[0].revenues += current_firm->revenue;
			Data_Firm[0].planned_output += current_firm->planned_output;
			Data_Firm[0].wage_offer +=  current_firm->wage_offer;
			Data_Firm[0].wage_offer_for_skill_1 +=  current_firm->wage_offer_for_skill_1;
			Data_Firm[0].wage_offer_for_skill_2 +=  current_firm->wage_offer_for_skill_2;
			Data_Firm[0].wage_offer_for_skill_3 +=  current_firm->wage_offer_for_skill_3;
			Data_Firm[0].wage_offer_for_skill_4 +=  current_firm->wage_offer_for_skill_4;
			Data_Firm[0].wage_offer_for_skill_5 +=  current_firm->wage_offer_for_skill_5;
			Data_Firm[0].delivery += current_firm->delivery;
			Data_Firm[0].delivery_to_home_region += current_firm->delivery_to_home_region;
			Data_Firm[0].delivery_to_foreign_region += current_firm->delivery_to_foreign_region;
			Data_Firm[0].stocks+= current_firm->stocks;
			Data_Firm[0].stocks_in_home_region += current_firm->stocks_in_home_region;
			Data_Firm[0].stocks_in_foreign_region += current_firm->stocks_in_foreign_region;
			Data_Firm[0].price_index_mall += (current_firm->delivery+current_firm->stocks)*current_firm->price;
			Data_Firm[0].price_index_home_mall+= (current_firm->delivery_to_home_region+
				current_firm->stocks_in_home_region)*current_firm->price;
			Data_Firm[0].price_index_foreign_mall += (current_firm->delivery_to_foreign_region+
				current_firm->stocks_in_foreign_region)*current_firm->price;
			Data_Firm[0].debt_active_firms+= current_firm->total_debt;
			Data_Firm[0].assets_active_firms+= current_firm->assets;
			Data_Firm[0].debt_asset_ratio_active_firms+=current_firm->total_debt/current_firm->assets;
			Data_Firm[0].labour_costs += current_firm->labour_costs;
			Data_Firm[0].calc_capital_costs +=current_firm->calc_capital_costs;
			Data_Firm[0].total_interest_payment += current_firm->total_interest_payment ;	
			Data_Firm[0].unit_costs +=current_firm->unit_costs;	
			Data_Firm[0].price += current_firm->price;
			Data_Firm[0].posted_vacancies += current_firm->posted_vacancies;
			Data_Firm[0].no_applications += current_firm->no_applications;
			Data_Firm[0].job_acceptance += current_firm->job_acceptance;
			Data_Firm[0].no_job_offers += current_firm->no_job_offers;
			Data_Firm[0].wage_increase += current_firm->wage_increase;
			
			}
		Data_Firm[0].total_debt+= current_firm->total_debt;
		Data_Firm[0].assets+= current_firm->assets;
		Data_Firm[0].debt_asset_ratio+=current_firm->total_debt/current_firm->assets;
		if(current_firm->total_debt/current_firm->assets>0.8)
		{
			Data_Firm[0].count_debt_asset_ratio_threshold++;
		}

		int i;
		for(i = 1; i <= no_regions; i++)
		{
			if(current_firm->region_id == Data_Firm[i].region_id )
			{
				Data_Firm[i].total_no_firms++;
				
			if( current_firm->no_employees > 0)
			{
				Data_Firm[i].no_firms++;
				Data_Firm[i].no_employees += current_firm->no_employees;
				Data_Firm[i].vacancies += current_firm->vacancies;
				Data_Firm[i].average_wage += 
				  (current_firm->mean_wage*current_firm->no_employees);
				Data_Firm[i].average_technology += 
				  (current_firm->technology*current_firm->output);
				Data_Firm[i].average_specific_skill += 
				  (current_firm->mean_specific_skills*current_firm->no_employees);
				Data_Firm[i].average_general_skill += 
				 (current_firm->average_g_skill*current_firm->no_employees);
				Data_Firm[i].output += current_firm->output;
				Data_Firm[i].sold_quantity_in_calendar_month += current_firm->sold_quantity_in_calendar_month;
				Data_Firm[i].average_payment_account += current_firm->payment_account_firm;
				Data_Firm[i].average_price += (current_firm->price*current_firm->sold_quantity_in_calendar_month);
				Data_Firm[i].capital_stock += (current_firm->capital_stock);
				Data_Firm[i].earnings += current_firm->earnings;
				Data_Firm[i].revenues += current_firm->revenue;
				Data_Firm[i].planned_output += current_firm->planned_output;
				Data_Firm[i].wage_offer +=  current_firm->wage_offer;
				Data_Firm[i].wage_offer_for_skill_1 +=  current_firm->wage_offer_for_skill_1;
				Data_Firm[i].wage_offer_for_skill_2 +=  current_firm->wage_offer_for_skill_2;
				Data_Firm[i].wage_offer_for_skill_3 +=  current_firm->wage_offer_for_skill_3;
				Data_Firm[i].wage_offer_for_skill_4 +=  current_firm->wage_offer_for_skill_4;
				Data_Firm[i].wage_offer_for_skill_5 +=  current_firm->wage_offer_for_skill_5;
				Data_Firm[i].delivery += current_firm->delivery;
				Data_Firm[i].delivery_to_home_region += current_firm->delivery_to_home_region;
				Data_Firm[i].delivery_to_foreign_region += current_firm->delivery_to_foreign_region;
				Data_Firm[i].stocks+= current_firm->stocks;
				Data_Firm[i].stocks_in_home_region += current_firm->stocks_in_home_region;
				Data_Firm[i].stocks_in_foreign_region += current_firm->stocks_in_foreign_region;
				Data_Firm[i].price_index_mall += 
				(current_firm->delivery+current_firm->stocks)*current_firm->price;
				Data_Firm[i].price_index_home_mall+= (current_firm->delivery_to_home_region+
					current_firm->stocks_in_home_region)*current_firm->price;
				Data_Firm[i].price_index_foreign_mall += (current_firm->delivery_to_foreign_region+
					current_firm->stocks_in_foreign_region)*current_firm->price;
				Data_Firm[i].debt_active_firms+= current_firm->total_debt;
				Data_Firm[i].assets_active_firms+= current_firm->assets;
				Data_Firm[i].debt_asset_ratio_active_firms+=current_firm->total_debt/current_firm->assets;
				Data_Firm[i].labour_costs += current_firm->labour_costs;
				Data_Firm[i].calc_capital_costs +=current_firm->calc_capital_costs;
				Data_Firm[i].total_interest_payment += current_firm->total_interest_payment ;	
				Data_Firm[i].unit_costs +=current_firm->unit_costs;
				Data_Firm[i].price += current_firm->price;
				Data_Firm[i].posted_vacancies += current_firm->posted_vacancies;
				Data_Firm[i].no_applications += current_firm->no_applications;
				Data_Firm[i].job_acceptance += current_firm->job_acceptance;
				Data_Firm[i].no_job_offers += current_firm->no_job_offers;
				Data_Firm[i].wage_increase += current_firm->wage_increase;
							
				}
				Data_Firm[i].total_debt+= current_firm->total_debt;
				Data_Firm[i].assets+= current_firm->assets;
				Data_Firm[i].debt_asset_ratio+=current_firm->total_debt/current_firm->assets;
				if(current_firm->total_debt/current_firm->assets>0.8)
					{
						Data_Firm[i].count_debt_asset_ratio_threshold++;
					}
			}
		}
		
		
	//double table[81];
	table[current_firm->id] =  ((current_firm->labour_costs + current_firm->calc_capital_costs  + 
							current_firm->total_interest_payment)/current_firm->output);
	
	table_labour_costs[current_firm->id] = (current_firm->labour_costs/current_firm->output);
	table_capital_costs[current_firm->id] = (current_firm->calc_capital_costs/current_firm->output);
	table_interest_payments[current_firm->id] = (current_firm->total_interest_payment/current_firm->output);
	table_unit_costs[current_firm->id] = current_firm->unit_costs;
	table_unit_costs_difference[current_firm->id] = current_firm->unit_costs - ((current_firm->labour_costs + 	
	current_firm->calc_capital_costs  + current_firm->total_interest_payment)/current_firm->output);
	table_price[current_firm->id] = current_firm->price;
	table_output[current_firm->id] = current_firm->output;
	table_employees[current_firm->id] = current_firm->no_employees;
	
	
		
		current_firm = current_firm->next;
		
	}

/********************************************************************************************/
	file = fopen("data-table.csv", "a");

	if(itno == 0)
	{
		for(i = 0; i <= 80; i++)
		{
			sprintf(data, "%i", i);
			fputs(data, file);
			fputs("\t", file);
		}
		
		fputs("\n", file);
	}
	
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 1; i <= 80; i++)
	{
		sprintf(data, "%f", table[i]);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);
/********************************************************************************************/
	file = fopen("data-table-labour-costs.csv", "a");

	if(itno == 0)
	{
		for(i = 0; i <= 80; i++)
		{
			sprintf(data, "%i", i);
			fputs(data, file);
			fputs("\t", file);
		}
		
		fputs("\n", file);
	}
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 1; i <= 80; i++)
	{
		sprintf(data, "%f", table_labour_costs[i]);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);

/********************************************************************************************/
	file = fopen("data-table-capital-costs.csv", "a");

	if(itno == 0)
	{
		for(i = 0; i <= 80; i++)
		{
			sprintf(data, "%i", i);
			fputs(data, file);
			fputs("\t", file);
		}
		
		fputs("\n", file);
	}
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 1; i <= 80; i++)
	{
		sprintf(data, "%f", table_capital_costs[i]);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);

/********************************************************************************************/
	file = fopen("data-table-interest-payments.csv", "a");

	if(itno == 0)
	{
		for(i = 0; i <= 80; i++)
		{
			sprintf(data, "%i", i);
			fputs(data, file);
			fputs("\t", file);
		}
		
		fputs("\n", file);
	}
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 1; i <= 80; i++)
	{
		sprintf(data, "%f", table_interest_payments[i]);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);

/********************************************************************************************/
	file = fopen("data-table-unit-costs.csv", "a");

	if(itno == 0)
	{
		for(i = 0; i <= 80; i++)
		{
			sprintf(data, "%i", i);
			fputs(data, file);
			fputs("\t", file);
		}
		
		fputs("\n", file);
	}
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 1; i <= 80; i++)
	{
		sprintf(data, "%f", table_unit_costs[i]);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);

/********************************************************************************************/
	file = fopen("data-table-unit-costs-difference.csv", "a");

	if(itno == 0)
	{
		for(i = 0; i <= 80; i++)
		{
			sprintf(data, "%i", i);
			fputs(data, file);
			fputs("\t", file);
		}
		
		fputs("\n", file);
	}
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 1; i <= 80; i++)
	{
		sprintf(data, "%f", table_unit_costs_difference[i]);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);

/********************************************************************************************/
	file = fopen("data-table-price.csv", "a");

	if(itno == 0)
	{
		for(i = 0; i <= 80; i++)
		{
			sprintf(data, "%i", i);
			fputs(data, file);
			fputs("\t", file);
		}
		
		fputs("\n", file);
	}
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 1; i <= 80; i++)
	{
		sprintf(data, "%f", table_price[i]);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);

/********************************************************************************************/
	file = fopen("data-table-output.csv", "a");

	if(itno == 0)
	{
		for(i = 0; i <= 80; i++)
		{
			sprintf(data, "%i", i);
			fputs(data, file);
			fputs("\t", file);
		}
		
		fputs("\n", file);
	}
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 1; i <= 80; i++)
	{
		sprintf(data, "%f", table_output[i]);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);

/********************************************************************************************/
	file = fopen("data-table-employees.csv", "a");

	if(itno == 0)
	{
		for(i = 0; i <= 80; i++)
		{
			sprintf(data, "%i", i);
			fputs(data, file);
			fputs("\t", file);
		}
		
		fputs("\n", file);
	}
	
	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 1; i <= 80; i++)
	{
		sprintf(data, "%i", table_employees[i]);
		fputs(data, file);
		fputs("\t", file);
	}

	fputs("\n", file);

	fclose(file);
	

/*Regions: wage-offer*/
	file = fopen("data-labor-market-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 0; i <= 0; i++)
	{
		sprintf(data, "%i", Data_Firm[i].posted_vacancies);
		fputs(data, file);
		fputs("\t", file);//unemployed entering the matching process
		sprintf(data, "%f", Data_Household[i].no_households - Data_Household[i].employed + 
						Data_Household[i].just_employed+Data_Household[i].fired_this_period);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", (double) (Data_Firm[i].posted_vacancies/(Data_Household[i].no_households - 
						Data_Household[i].employed + Data_Household[i].just_employed+Data_Household[i].fired_this_period)));
		fputs(data, file);
		fputs("\t", file);		
		sprintf(data, "%f", (Data_Household[i].no_job_offers)/(Data_Household[i].just_employed));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].employed_this_period);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Household[i].fired_this_period);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", (Data_Household[i].no_households-Data_Household[i].employed));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%i", Data_Firm[i].wage_increase);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].vacancies);
		fputs(data, file);
		fputs("\t", file);//unemployment outflow rate
		sprintf(data, "%f", (double) (Data_Household[i].employed_this_period/(Data_Household[i].no_households - 
						Data_Household[i].employed + Data_Household[i].just_employed+Data_Household[i].fired_this_period)));
		fputs(data, file);
		fputs("\t", file);//seperation rate
		sprintf(data, "%f", Data_Household[i].fired_this_period/(Data_Household[i].employed - Data_Household[i].just_employed-Data_Household[i].fired_this_period));
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);


/*Regions: wage-offer*/
	file = fopen("data-base-wage-offer-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_Firm[i].wage_offer/Data_Firm[i].no_firms);
		fputs(data, file);
		fputs("\t", file);	
	}
		
	fputs("\n", file);

	fclose(file);


/*Regions: Costs*/
	file = fopen("data-costs-per-unit-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", 
		(Data_Firm[i].labour_costs+Data_Firm[i].calc_capital_costs+Data_Firm[i].total_interest_payment)
		/Data_Firm[i].output);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", (Data_Firm[i].labour_costs/Data_Firm[i].output));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", (Data_Firm[i].calc_capital_costs/Data_Firm[i].output));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", (Data_Firm[i].total_interest_payment/Data_Firm[i].output));
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);


/*Regions: input-per-output*/
	file = fopen("data-input-per-output-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", (Data_Firm[i].no_employees/Data_Firm[i].output));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", (Data_Firm[i].capital_stock/Data_Firm[i].output));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", (Data_Firm[i].no_employees/Data_Firm[i].capital_stock));
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);




/*Regions: control*/
	file = fopen("data-budget-supply-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", ((Data_Firm[1].delivery_to_home_region+Data_Firm[2].delivery_to_foreign_region)+
		(Data_Firm[1].stocks_in_home_region+Data_Firm[2].stocks_in_foreign_region))/
		((Data_Firm[2].delivery_to_home_region+Data_Firm[1].delivery_to_foreign_region)+
		(Data_Firm[2].stocks_in_home_region+Data_Firm[1].stocks_in_foreign_region)));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Household[1].consumption_budget_in_month
		/Data_Household[2].consumption_budget_in_month);
	fputs(data, file);
	fputs("\t", file);
if(((Data_Firm[1].stocks_in_home_region+Data_Firm[2].stocks_in_foreign_region)/
		(Data_Firm[2].stocks_in_home_region+Data_Firm[1].stocks_in_foreign_region))<5)
{
	sprintf(data, "%f", (Data_Firm[1].stocks_in_home_region+Data_Firm[2].stocks_in_foreign_region)/
		(Data_Firm[2].stocks_in_home_region+Data_Firm[1].stocks_in_foreign_region));
	fputs(data, file);
	fputs("\t", file);
}
else
{double help =5.0;
	sprintf(data, "%f", help);
	fputs(data, file);
	fputs("\t", file);
}
	sprintf(data, "%f", (Data_Firm[1].delivery_to_home_region+Data_Firm[2].delivery_to_foreign_region)/
	(Data_Firm[2].delivery_to_home_region+Data_Firm[1].delivery_to_foreign_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Mall[1].sales/Data_Mall[2].sales );
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[1].average_price/Data_Firm[1].sold_quantity_in_calendar_month)/ (Data_Firm[2].average_price/Data_Firm[2].sold_quantity_in_calendar_month));
	fputs(data, file);
	fputs("\t", file);
		
	fputs("\n", file);

	fclose(file);




/*Regions: active firms*/
	file = fopen("data-active-firms-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_Firm[i].no_firms);
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);



/*Regions: relative stocks*/
	file = fopen("data-relative-stocks-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[1].stocks/Data_Firm[2].stocks);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[1].stocks_in_home_region/Data_Firm[1].stocks_in_foreign_region);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f",Data_Firm[2].stocks_in_foreign_region/Data_Firm[2].stocks_in_home_region);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[1].stocks_in_home_region+Data_Firm[2].stocks_in_foreign_region)/
		(Data_Firm[2].stocks_in_home_region+Data_Firm[1].stocks_in_foreign_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[1].stocks_in_home_region/Data_Firm[2].stocks_in_foreign_region);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f",Data_Firm[1].stocks_in_foreign_region/Data_Firm[2].stocks_in_home_region);
	fputs(data, file);
	fputs("\t", file);
	
	
	
		
	fputs("\n", file);

	fclose(file);




/*Regions: relative delivery */
	file = fopen("data-relative-delivery-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[1].delivery/Data_Firm[2].delivery);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[1].delivery_to_home_region/Data_Firm[1].delivery_to_foreign_region);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f",Data_Firm[2].delivery_to_foreign_region/Data_Firm[2].delivery_to_home_region);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[1].delivery_to_home_region+Data_Firm[2].delivery_to_foreign_region)/
	(Data_Firm[2].delivery_to_home_region+Data_Firm[1].delivery_to_foreign_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[1].delivery_to_home_region/Data_Firm[2].delivery_to_foreign_region);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f",Data_Firm[1].delivery_to_foreign_region/Data_Firm[2].delivery_to_home_region);
	fputs(data, file);
	fputs("\t", file);
	
	
		
	fputs("\n", file);

	fclose(file);


/*Regions: relative supply */
	file = fopen("data-relative-supply-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[1].stocks + Data_Firm[1].delivery)/
		(Data_Firm[2].stocks + Data_Firm[2].delivery));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[1].stocks_in_home_region + Data_Firm[1].delivery_to_home_region)/
		(Data_Firm[1].stocks_in_foreign_region + Data_Firm[1].delivery_to_foreign_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f",(Data_Firm[2].stocks_in_foreign_region + Data_Firm[2].delivery_to_foreign_region)/
		(Data_Firm[2].stocks_in_home_region + Data_Firm[2].delivery_to_home_region));
	fputs(data, file);
	fputs("\t", file);

sprintf(data, "%f", ((Data_Firm[1].delivery_to_home_region+Data_Firm[2].delivery_to_foreign_region)+
		(Data_Firm[1].stocks_in_home_region+Data_Firm[2].stocks_in_foreign_region))/
		((Data_Firm[2].delivery_to_home_region+Data_Firm[1].delivery_to_foreign_region)+
		(Data_Firm[2].stocks_in_home_region+Data_Firm[1].stocks_in_foreign_region)));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[1].stocks_in_home_region + Data_Firm[1].delivery_to_home_region)/
		(Data_Firm[2].stocks_in_foreign_region + Data_Firm[2].delivery_to_foreign_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f",(Data_Firm[1].stocks_in_foreign_region + Data_Firm[1].delivery_to_foreign_region)/
		(Data_Firm[2].stocks_in_home_region + Data_Firm[2].delivery_to_home_region));
	fputs(data, file);
	fputs("\t", file);
	
	
		
	fputs("\n", file);

	fclose(file);

/*Regions: price index mall perspective */
	file = fopen("data-price-index-mall-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[0].price_index_mall/(Data_Firm[0].delivery+Data_Firm[0].stocks));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[1].price_index_home_mall+Data_Firm[2].price_index_foreign_mall)/
				(Data_Firm[1].delivery_to_home_region+Data_Firm[1].stocks_in_home_region +
				Data_Firm[2].delivery_to_foreign_region + Data_Firm[2].stocks_in_foreign_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[2].price_index_home_mall+Data_Firm[1].price_index_foreign_mall)/
				(Data_Firm[2].delivery_to_home_region+Data_Firm[2].stocks_in_home_region +
				Data_Firm[1].delivery_to_foreign_region + Data_Firm[1].stocks_in_foreign_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[1].price_index_home_mall)/
				(Data_Firm[1].delivery_to_home_region+Data_Firm[1].stocks_in_home_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[1].price_index_foreign_mall)/
				(Data_Firm[1].delivery_to_foreign_region+Data_Firm[1].stocks_in_foreign_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[2].price_index_foreign_mall)/
				(Data_Firm[2].delivery_to_foreign_region+Data_Firm[2].stocks_in_foreign_region));
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", (Data_Firm[2].price_index_home_mall)/
				(Data_Firm[2].delivery_to_home_region+Data_Firm[2].stocks_in_home_region));
	fputs(data, file);
	fputs("\t", file);
	
	
		
	fputs("\n", file);

	fclose(file);



/*Regions: Delivery */
	file = fopen("data-delivery-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_Firm[i].delivery);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].delivery_to_home_region);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].delivery_to_foreign_region);
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);


/*Regions: Delivery*/
	file = fopen("data-delivery-receiver.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[1].delivery+Data_Firm[2].delivery);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[1].delivery_to_home_region+Data_Firm[2].delivery_to_foreign_region);
	fputs(data, file);
	fputs("\t", file);
	sprintf(data, "%f", Data_Firm[2].delivery_to_home_region+Data_Firm[1].delivery_to_foreign_region);
	fputs(data, file);
	fputs("\t", file);
	
		
	fputs("\n", file);

	fclose(file);


/*Regions: Stocks*/
	file = fopen("data-stocks-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", Data_Firm[i].stocks);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].stocks_in_home_region);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].stocks_in_foreign_region);
		fputs(data, file);
		fputs("\t", file);
	}
		
	fputs("\n", file);

	fclose(file);



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
			Data_Firm[i].output);
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
			sprintf(data, "%f", Data_Firm[i].output);
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
			sprintf(data, "%f", Data_Firm[i].sold_quantity_in_calendar_month);
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
			sprintf(data, "%f", Data_Firm[i].average_price/Data_Firm[i].sold_quantity_in_calendar_month);
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
		sprintf(data, "%f", Data_Firm[i].planned_output);
		fputs(data, file);
		fputs("\t", file);	
	}
		
	fputs("\n", file);

	fclose(file);
	
	/*Regions: total debt*/
		file = fopen("data-total-debt-region.csv", "a");

		sprintf(data, "%i", itno);
		fputs(data, file);
		fputs("\t", file);

		
		for(i = 0; i <= no_regions; i++)
		{
			sprintf(data, "%f", Data_Firm[i].total_debt);
			fputs(data, file);
			fputs("\t", file);	
		}
			
		fputs("\n", file);

		fclose(file);

		
		/*Regions: total assets*/
				file = fopen("data-assets-region.csv", "a");

				sprintf(data, "%i", itno);
				fputs(data, file);
				fputs("\t", file);

				
				for(i = 0; i <= no_regions; i++)
				{
					sprintf(data, "%f", Data_Firm[i].assets);
					fputs(data, file);
					fputs("\t", file);	
				}
					
				fputs("\n", file);

				fclose(file);
				
				
				
				/*Regions: total assets*/
						file = fopen("data-debt-assets-ratio-region.csv", "a");

						sprintf(data, "%i", itno);
						fputs(data, file);
						fputs("\t", file);

						
						for(i = 0; i <= no_regions; i++)
						{
							sprintf(data, "%f", Data_Firm[i].debt_asset_ratio/Data_Firm[i].total_no_firms);
							fputs(data, file);
							fputs("\t", file);	
						}
							
						fputs("\n", file);

						fclose(file);
						
						
						
						/*Regions: total assets*/
							file = fopen("data-number-debt-asset-ratio-violator-region.csv", "a");

							sprintf(data, "%i", itno);
							fputs(data, file);
							fputs("\t", file);

							
							for(i = 0; i <= no_regions; i++)
							{
								sprintf(data, "%f", Data_Firm[i].count_debt_asset_ratio_threshold);
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

		if(itno == 0)
		{
			sprintf(data, "%f", Data_Firm[i].average_technology);
			fputs(data, file);
			fputs("\t", file);
		}
		if(itno%20 == 0 & itno >0)
		{
			sprintf(data, "%f", Data_Firm[i].average_technology/
			Data_Firm[i].output);
			fputs(data, file);
			fputs("\t", file);
		}	
	}
		
	fputs("\n", file);

	fclose(file);


/*Regions: wage*/
	file = fopen("data-wage-offer-region.csv", "a");

	sprintf(data, "%i", itno);
	fputs(data, file);
	fputs("\t", file);

	
	for(i = 0; i <= no_regions; i++)
	{
		sprintf(data, "%f", (Data_Firm[i].wage_offer_for_skill_1+Data_Firm[i].wage_offer_for_skill_2+
		Data_Firm[i].wage_offer_for_skill_3+Data_Firm[i].wage_offer_for_skill_4+
		Data_Firm[i].wage_offer_for_skill_5)/(Data_Firm[i].no_firms*5));
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].wage_offer_for_skill_1/Data_Firm[i].no_firms);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].wage_offer_for_skill_2/Data_Firm[i].no_firms);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].wage_offer_for_skill_3/Data_Firm[i].no_firms);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].wage_offer_for_skill_4/Data_Firm[i].no_firms);
		fputs(data, file);
		fputs("\t", file);
		sprintf(data, "%f", Data_Firm[i].wage_offer_for_skill_5/Data_Firm[i].no_firms);
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
			sprintf(data, "%f", (Data_Firm[i].output -
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
			last_production[i] = Data_Firm[i].output;
			
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
	government * governments, * current_government;
	firm ** p_firms;
	household ** p_household;
	IGfirm ** p_IGfirms;
	mall ** p_malls;
	government ** p_governments;
	int iteration_number = 0;
	int stilldata = 1;
	



	FILE *file;

/*HOUSEHOLD FILES*/
	file = fopen("data-additional-taxes-region.csv", "w");
	fclose(file);

	file = fopen("data-employed-region.csv", "w");
	fclose(file);
	
	file = fopen("data-unemployment-region.csv", "w");
	fclose(file);

	file = fopen("data-wage-region.csv", "w");
	fclose(file);

	file = fopen("data-reservation-wage-region.csv", "w");
	fclose(file);

	file = fopen("data-commuter-region.csv", "w");
	fclose(file);

	file = fopen("data-specific-skill-household-region.csv", "w");
	fclose(file);

	file = fopen("data-payment-account-region.csv", "w");
	fclose(file);

	file = fopen("data-commuter-region-1.csv", "w");
	fclose(file);

	file = fopen("data-commuter-region-2.csv", "w");
	fclose(file);

	file = fopen("data-commuter-region-5.csv", "w");
	fclose(file);

	file = fopen("data-consumption-budget-region.csv", "w");
	fclose(file);

/*MALL FILES*/

	file = fopen("data-supply-region.csv", "w");
	fclose(file);

	file = fopen("data-sales-region.csv", "w");
	fclose(file);

	file = fopen("data-sales-origin.csv", "w");
	fclose(file);
	
/*FIRM FILES*/

	file = fopen("data-budget-supply-region.csv", "w");
	fclose(file);

	file = fopen("data-active-firms-region.csv", "w");
	fclose(file);

	file = fopen("data-relative-stocks-region.csv", "w");
	fclose(file);

	file = fopen("data-relative-supply-region.csv", "w");
	fclose(file);

	file = fopen("data-relative-delivery-region.csv", "w");
	fclose(file);

	file = fopen("data-price-index-mall-region.csv", "w");
	fclose(file);

	file = fopen("data-delivery-region.csv", "w");
	fclose(file);	

	file = fopen("data-delivery-receiver.csv", "w");
	fclose(file);

	file = fopen("data-stocks-region.csv", "w");
	fclose(file);

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

	file = fopen("data-wage-offer-region.csv", "w");
	fclose(file);

	file = fopen("data-costs-per-unit-region.csv", "w");
	fclose(file);

	file = fopen("data-base-wage-offer-region.csv", "w");
	fclose(file);

	file = fopen("data-input-per-output-region.csv", "w");
	fclose(file);
	
	
	
	file = fopen("data-total-debt-region.csv", "w");
	fclose(file);
	
	file = fopen("data-assets-region.csv", "w");
		fclose(file);
		
		file = fopen("data-debt-assets-ratio-region.csv", "w");
			fclose(file);
			
			file = fopen("data-number-debt-asset-ratio-violator-region.csv", "w");
				fclose(file);

	file = fopen("data-labor-market-region.csv", "w");
	fclose(file);


	file = fopen("data-table.csv", "w");
	fclose(file);

	file = fopen("data-table-labour-costs.csv", "w");
	fclose(file);

	file = fopen("data-table-capital-costs.csv", "w");
	fclose(file);

	file = fopen("data-table-interest-payments.csv", "w");
	fclose(file);

	file = fopen("data-table-unit-costs.csv", "w");
	fclose(file);
	
	file = fopen("data-table-unit-costs-difference.csv", "w");
	fclose(file);

	file = fopen("data-table-price.csv", "w");
	fclose(file);

	file = fopen("data-table-output.csv", "w");
	fclose(file);

	file = fopen("data-table-employees.csv", "w");
	fclose(file);
/*IG firm*/

file = fopen("data-IGfirm-output-region.csv", "w");
	fclose(file);
	
	file = fopen("data-IGfirm-capital-good-demand-region.csv", "w");
	fclose(file);

	file = fopen("data-IGfirm-capital-good-store-region.csv", "w");
	fclose(file);

	file = fopen("data-IGfirm-sales-region.csv", "w");
	fclose(file);

	file = fopen("data-IGfirm-employees-region.csv", "w");
	fclose(file);

	file = fopen("data-IGfirm-capital-good-price-region.csv", "w");
	fclose(file);
	
	file = fopen("data-technological-frontier.csv", "w");
	fclose(file);
	
	file = fopen("data-IGfirm-payments-region.csv", "w");
	fclose(file);
	
	file = fopen("data-IGfirm-earnings-region.csv", "w");
	fclose(file);

	file = fopen("data-IGfirm-external-financing-region.csv", "w");
	fclose(file);

	file = fopen("data-IGfirm-payment-account-region.csv", "w");
	fclose(file);
	
	file = fopen("data-IGfirm-revenues.csv", "w");
	fclose(file);

	file = fopen("data-IGfirm-dividend-payment.csv", "w");
	fclose(file);
	
	


/*Government*/
	
	file = fopen("data-government-tax-revenues-region.csv", "w");
	fclose(file);

	file = fopen("data-government-benefit-payment-region.csv", "w");
	fclose(file);

	file = fopen("data-government-budget-balance-region.csv", "w");
	fclose(file);

	file = fopen("data-government-total-debt-region.csv", "w");
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

	governments = NULL;
	p_governments = &governments;
	
	while(stilldata)
	{
		stilldata = getiteration(filepath, iteration_number, p_firms, p_household,p_IGfirms, p_malls,p_governments );
		
		if(stilldata) savedatatofile(iteration_number, p_firms, p_household,p_IGfirms, p_malls,p_governments);
		
		iteration_number +=20;
		
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
