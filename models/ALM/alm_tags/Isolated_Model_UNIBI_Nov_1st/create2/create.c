#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int random_int(int min,int max)
{
    return min + rand() % (max - min + 1);
}

double random_double(double min, double max)
{
	int a = (int)min*10;
	int b = (int)max*10;
	int c = a + rand() % (b  - a + 1);
	double d = (double)c/10;
	
	return d;
}

void print_tag(char tag[], char value[], FILE *file)
{
	fputs("<", file);
	fputs(tag, file);
	fputs(">", file);
	fputs(value, file);
	fputs("</", file);
	fputs(tag, file);
	fputs(">\n", file);
}

int main(int argc, char ** argv)
{
	/* Pointer to file */
	FILE *file;
	char data[10000000];
	char data2[1000000];
	char data1[1000000];
	char initial_capi_costs[10000];
	char skill_distribution[10000];
	char innovation_scheme[10000];
	int num;  /*used as an index to cycle through each agent*/
	int num_start;
	
	
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Parameter setting
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/	
	
	

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 
 * Global parameters (formerly found in mylibrary_header.h)
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/	



/*Strenght of logit*/
double GAMMA_CONST = -7.5;

/*brief Paramater for production function. */
double ALPHA = 0.662;

/*brief Paramater for production function. */
double BETA = 0.338;

/*brief Dividend rate of consumption goods producers. */
double DIVIDEND_RATE = 0.8;

/*brief deprication rate. */
double DEPRECIATION_RATE = 0.01;

/*brief Discount rate*/
double DISCOUNT_RATE = 0.05;

/*brief Strenght of adaption of the capital stock if firm is rationed on the labor market*/
double TETA = 0.0;


/*brief Pricing rule: mark up on unit costs. */
double MARK_UP = 0.10;

/*Strenght of the influence of the actual demand on the next production quantity: if LAMBDA = 0 then the planned production quantities of the last periods are recognized. If LAMBDA = 1 then the only the actual demand is recognized*/
double LAMBDA = 0.5;

/*adaption of the wage offer: percent*/
double wage_update = 0.01;//0.01

/*min number of vacancies to trigger vacancy counter*/
int MIN_VACANCY = 2;

double QUANTIL_NORMAL_DISTRIBUTION = 0.842;

int INNOVATION_BY_RANDOM = 0;

		
/*adaption of the reservation wage: prercent*/
double wage_reservation_update = 0.01;//0.01

/*Cost of working in a different region: for example travelling costs*/

double region_cost_1 = 0.0;
double region_cost_2 =0.0;
double region_cost_3 = 0.0;



int day_change_region_costs_1 =10000;
int day_change_region_costs_2 = 20000;

int TRANSITION_PHASE = 1000;


/*calculatory cost of storing one unit over one period*/
double INVENTORY_COSTS_PER_UNIT = 2.0;

/*percent of employees who are searching for a new job*/
int ON_THE_JOB_SEARCH_RATE = 0;

/*INITIAL_CONSUMPTION_PROPENSITY times the mean income is the upper limit of the consumtion during the first five periods: smooth the consumption expenditures because of high dividend payments of the capital goods producer*/
double INITIAL_CONSUMPTION_PROPENSITY  = 0.95;

/*percent of savings which can by used for consumption*/
double CONSUMPTION_PROPENSITY = 0.95;

/*Planning horizon of firms*/
int FIRM_PLANNING_HORIZON = 10;

double DEBT_ASSETS_RATIO_THRESHOLD = 0.8;

double INTEREST_RATE = 0.005;

double INV_INERTIA = 2.5;


double ADAPTION_DELIVERY_VOLUME = 0.10;//0.05

int PERIODS_TO_REPAY_LOANS = 24;

/*Probability for the delivery if the critical stock of one mall was zero for the last periods*/
int DELIVERY_PROB_IF_CRITICAL_STOCK_0 = 25;


int INNOVATION_PROBABILITY = 10; //10

double PRODUCTIVITY_PROGRESS = 0.025;

double LOGIT_PARAMETER_SPECIFIC_SKILLS = 0;

double LOGIT_PARAMETER_GENERAL_SKILLS = 0.5;



int CHANGE_IN_SKILL_DISTRIBUTION = 0;
sprintf(skill_distribution, "{{1,0.2,0.2,0.2,0.2,0.2}{2,0.2,0.2,0.2,0.2,0.2}}");


int LOWER_BOUND_FIRING = 0;
int UPPER_BOUND_FIRING = 10;

int NO_REGIONS_PER_GOV = 1;

/*region ID of the region which will receive subsidies*/
int REGION_SUBSIDY = 0;
/*fraction of cap_good_price which is subsidized*/
double SUBSIDY_FRACTION = 0.0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//     1       
//low tech progress  start value best practice: 1.0:
//sprintf(innovation_scheme,"{{1120,1.012500},{1260,1.025156},{1460,1.037971},{1500,1.050945},{1600,1.064082},{1780,1.077383},{1820,1.090850},{2140,1.104486},{2160,1.118292},{2360,1.132271},{2440,1.146424},{3000,1.160755},{3080,1.175264},{3240,1.189955},{3420,1.204829},{3540,1.219890},{3980,1.235138},{4000,1.250577},{4140,1.266210},{4620,1.282037},{4660,1.298063},{4680,1.314288},{4840,1.330717}}");


//      2
//high tech progress  start value best practice: 1.0
//sprintf(innovation_scheme,"{{1100,1.025000},{1300,1.050625},{1780,1.076891},{1900,1.103813},{2020,1.131408},{2360,1.159693},{2380,1.188686},{2420,1.218403},{2500,1.248863},{2600,1.280085},{2620,1.312087},{2920,1.344889},{2960,1.378511},{3120,1.412974},{3180,1.448298},{3220,1.484506},{3780,1.521618},{3820,1.559659},{4080,1.598650},{4300,1.638616},{4360,1.679582},{4900,1.721571}}");


//    3	
//low tech progress  start value best practice:1.5
sprintf(innovation_scheme,"{{1300,1.518750},{1360,1.537734},{1580,1.556956},{1760,1.576418},{1800,1.596123},{2240,1.616075},{2320,1.636276},{2360,1.656729},{2380,1.656729},{3020,1.677438},{3040,1.677438},{3380,1.698406},{3760,1.719636},{4040,1.741132},{4120,1.762896},{4340,1.784932},{4420,1.807244},{4440,1.829834},{4580,1.852707},{4680,1.875866}}");


//    4
//high tech progress  start value best practice:1.5
//sprintf(innovation_scheme,"{{1060,1.537500},{1120,1.575937},{1180,1.615336},{1460,1.655719},{1600,1.697112},{1860,1.739540},{1980,1.783029},{2120,1.827604},{2180,1.873294},{2480,1.920127},{2780,1.968130},{2800,2.017333},{2840,2.067767},{3560,2.172447},{3640,2.226758},{3660,2.282427},{4020,2.339488},{4380,2.397975},{4640,2.457925},{4760,2.519373},{4800,2.582357},{4940,2.646916}}");


// 5

//exztra high start value 1.0

//sprintf(innovation_scheme,"{{1300,1.092025},{1360,1.141166},{1580,1.192519},{1760,1.246182},{1800,1.30226},{2240,1.360862},{2320,1.422101},{2360,1.486095},{2380,1.552969},{3020, 1.622853},{3040,1.695881},{3380,1.772196},{3760,1.851945},{4040,1.935282},{4120,2.02237},{4340,2.113377},{4420,2.208479},{4440,2.307860},{4580,2.411714},{4680,2.520241}}");


// 6 
//extrqa high start value 1.5
//sprintf(innovation_scheme,"{{1300,1.5675},{1360,1.638037},{1580,1.711749},{1760,1.788778},{1800,1.869273},{2240,1.95339},{2320,2.041293},{2360,2.133151},{2380,2.229143},{3020, 2.434280},{3040,2.543822},{3380,2.658294},{3760,2.777917},{4040,2.902924},{4120,3.033555},{4340,3.170065},{4420,3.312718},{4440,3.461790},{4580,3.617571},{4680,3.617571}}");

	/*Defining the geographical space as a rectangular grid  */	
	
	int num_regions_X=1;/*Number of columns*/
	int num_regions_Y=1;/*Number of regions*/
	int num_regions = num_regions_X*num_regions_Y; /*number of regions*/
	
	
	int total_households = 1600;/*number of households in the economy*/
	int households_per_region = total_households/num_regions; 

	int total_firms  = 80; /*total_firms modulo num_regions should be 0*/
	int total_IGfirms = 1;
	int total_market_research = 1;
	int total_malls = num_regions;  /*one mall per region*/
	//int num_app =  0.5*total_firms; /*number of applications per agent*/
	int num_app =5;
	int total_Governments =1;
	int total_banks = 1;
	

	double 	tax_rate_corporate[2][1] = {0.08,0.08};
	double	tax_rate_hh_labour[2][1]= {0.08,0.08};
	double	tax_rate_hh_capital[2][1] ={0.0,0.0};
	double	unemployment_benefit_payment[2][1] = {0.7,0.7};
	double	payment_account_government =1000.0;
	double 	payment_account_household = 0;

	double   cap_price; // temp variable for printing capital_good_price_region into memory variables of the firm
	double	capital_good_price = 2;
	double	capital_good_price_region[2][1] = {2.0,2.0};
	
	double productivity_best_practice_igfirm = 1.5;  //Productivity of the technology offered by the IG firm
	double productivity_best_practice[2][1]=
					{1.5,1.5};

	//Firm's starting value of productivity of the capital stock
			double technology[2][1]=
							{1.5,1.5};

	int skills_in_regions[2][1]=
					{4,4};
//region specific initial value of households specific skills
		double spec_s_hh_reg1 = 1.5;
		double spec_s_hh_reg2 = 1.5;
		double specific_skills_of_household[2][1]=
							{spec_s_hh_reg1,spec_s_hh_reg2};
		



	int decil_production_rule_upper_bound= 8;	
	int decil_production_rule_lower_bound = 8; 			
	

	int years_statistics = 10;/*number of years used to smooth the production*/

	/*Defining skill distributions in regions: only 1-4*/

	double skilldistribution_1[5]={0.2,0.2,0.2,0.2,0.2};
	double skilldistribution_2[5]={0.8,0.05,0.05,0.05,0.05};
	double skilldistribution_3[5]={0.42,0.33,0.20,0.04,0.01};
	double skilldistribution_4[5]={0.1,0.3,0.4,0.15,0.05};
	
	int id_igfirm ;
	
	
	
	//This determines the local skill distribution. Use numbers 1 .. 4 (see above, skill distribution_X) to give a region a skill distribution. 
		
		//Total production volume for a single firm
			double total_production_quantity[2][1]=
						{50.0,50.0};
			//This defines the initial capital stock of firm depending on the region.
			double total_units_capital[2][1]=
				                            {90.0,90.0};
		
			//This defines the financial resources of firm at the beginning of a simulation
			double payment_account[2][1]= 
			{50.0,50.0};
			
				
			//Base wage offer per unit of specific skills:
			double base_wage_offer[2][1] = {1.5,1.0};



			
			//Initital wage offer of the firms
			double wage_offer_region_1 = base_wage_offer[0][0]*specific_skills_of_household[0][0];
			double wage_offer_region_2 = base_wage_offer[0][1]*specific_skills_of_household[0][1];
			//printf("specific_skills_of_household[1][1] %f \n",specific_skills_of_household[2][1]);
			//printf("specific_skills_of_household[2][1] %f \n",specific_skills_of_household[1][1]);

			double wage_offer[2][1]= 
				{wage_offer_region_1,wage_offer_region_2};
			
			double mall_delivery_fraction_1;
			
			double mall_delivery_fraction_2;
			
			if(num_regions==2)
			{

			mall_delivery_fraction_1 = wage_offer_region_1/(wage_offer_region_1+wage_offer_region_2);
			mall_delivery_fraction_2 = wage_offer_region_2/(wage_offer_region_1+wage_offer_region_2);

			}else
			{
			mall_delivery_fraction_1 = 1.0;
			mall_delivery_fraction_2 = 0.0;

			}

	
	/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	
	




/*sprintf(initial_capi_costs, "{");
		int i;
		for(i=0; i< PERIODS_TO_REPAY_LOANS; i++)
		{

		int rand_1 = random_int(1,3);
		//if(rand_1 < 3 )
			{
				double rand_2 = random_double(0.0,1.2);
				
				//sprintf(data1,"%s { %f , %d}",initial_capi_costs,rand_2, i);	
				sprintf(data1,"%s { %f , %d}",initial_capi_costs,0.20187, i);
				sprintf(initial_capi_costs,"%s",data1);

			}
			

		}*/


	


	//int gov_id  = total_firms+total_households+total_IGfirms+1;
	int bank_id = total_firms+total_households+total_IGfirms+total_Governments+1;

	
	
	
	int count=1;
		int region_grid[num_regions_X][num_regions_Y];
		int i1,j1;
		for ( i1=0;i1<num_regions_Y;i1++)
		{
			for(j1=0;j1<num_regions_X;j1++)
			{
			region_grid[j1][i1] = count;
			count++;
					
		}
		}	
	
	
	
	/* Set changing seed */
	srand(time(NULL));
	
	file = fopen("0.xml", "w");
	
	fputs("<states>\n", file);
	fputs("<itno>0</itno>\n", file);


	fputs("<environment>\n", file);

	sprintf(data, "%d",1);    print_tag("day", data, file);
	sprintf(data, "%d",5);    print_tag("week", data, file);
	sprintf(data, "%d",20);    print_tag("month", data, file);
	sprintf(data, "%d",60);    print_tag("quarter", data, file);
	sprintf(data, "%d",240);    print_tag("year", data, file);
	sprintf(data, "%f",GAMMA_CONST);    print_tag("gamma_const", data, file);
	sprintf(data, "%f",ALPHA);    print_tag("alpha", data, file);
	sprintf(data, "%f",BETA);    print_tag("beta", data, file);
	sprintf(data, "%f",DIVIDEND_RATE);    print_tag("dividend_rate", data, file);
	sprintf(data, "%f",DEPRECIATION_RATE);    print_tag("depreciation_rate", data, file);
	sprintf(data, "%f",DISCOUNT_RATE);    print_tag("discount_rate", data, file);
	
	sprintf(data, "%f",TETA);    print_tag("teta", data, file);
	sprintf(data, "%f",MARK_UP);    print_tag("mark_up", data, file);
	sprintf(data, "%f",LAMBDA);    print_tag("lambda", data, file);
	sprintf(data, "%f",wage_update);    print_tag("wage_update", data, file);
	sprintf(data, "%d",MIN_VACANCY);    print_tag("min_vacancy", data, file);
	sprintf(data, "%f",wage_reservation_update);    print_tag("wage_reservation_update", data, file);

	sprintf(data, "%f",INVENTORY_COSTS_PER_UNIT);    print_tag("inventory_costs_per_unit", data, file);
	sprintf(data, "%d",ON_THE_JOB_SEARCH_RATE);    print_tag("on_the_job_search_rate", data, file);
	sprintf(data, "%f",INITIAL_CONSUMPTION_PROPENSITY);    print_tag("initial_consumption_propensity", data, file);
	sprintf(data, "%f",CONSUMPTION_PROPENSITY);    print_tag("consumption_propensity", data, file);
	sprintf(data, "%d",FIRM_PLANNING_HORIZON);    print_tag("firm_planning_horizon", data, file);
	sprintf(data, "%f",DEBT_ASSETS_RATIO_THRESHOLD);    print_tag("debt_assets_ratio_threshold", data, file);
	sprintf(data, "%f",region_cost_1);    print_tag("region_cost_1", data, file);
sprintf(data, "%f",region_cost_2);    print_tag("region_cost_2", data, file);
sprintf(data, "%f",region_cost_3);    print_tag("region_cost_3", data, file);
sprintf(data, "%d",day_change_region_costs_1);    print_tag("day_change_region_costs_1", data, file);
sprintf(data, "%d",day_change_region_costs_2);    print_tag("day_change_region_costs_2", data, file);

	sprintf(data, "%d",TRANSITION_PHASE);    print_tag("transition_phase", data, file);
	sprintf(data, "%d",INNOVATION_BY_RANDOM); print_tag("innovation_by_random", data, file);



	sprintf(data, "%f",INTEREST_RATE);    print_tag("interest_rate", data, file);
	sprintf(data, "%f",INV_INERTIA);    print_tag("inv_inertia", data, file);
	sprintf(data, "%f",ADAPTION_DELIVERY_VOLUME);    print_tag("adaption_delivery_volume", data, file);
	sprintf(data, "%d",DELIVERY_PROB_IF_CRITICAL_STOCK_0);    print_tag("delivery_prob_if_critical_stock_0", data, file);
	sprintf(data, "%f",QUANTIL_NORMAL_DISTRIBUTION);    print_tag("quantil_normal_distribution", data, file);
	

	sprintf(data, "%d",PERIODS_TO_REPAY_LOANS);    print_tag("periods_to_repay_loans", data, file);
	sprintf(data, "%d",INNOVATION_PROBABILITY);    print_tag("innovation_probability", data, file);
	sprintf(data, "%f",PRODUCTIVITY_PROGRESS);    print_tag("productivity_progress", data, file);
sprintf(data, "%f",LOGIT_PARAMETER_SPECIFIC_SKILLS);    print_tag("logit_parameter_specific_skills", data, file);

sprintf(data, "%f",LOGIT_PARAMETER_GENERAL_SKILLS);    print_tag("logit_parameter_general_skills", data, file);
sprintf(data, "%d",CHANGE_IN_SKILL_DISTRIBUTION);    print_tag("change_in_skill_distribution", data, file);

sprintf(data, "%d",LOWER_BOUND_FIRING);    print_tag("lower_bound_firing", data, file);
sprintf(data, "%d",UPPER_BOUND_FIRING);    print_tag("upper_bound_firing", data, file);

sprintf(data, "%d",REGION_SUBSIDY);    print_tag("region_subsidy", data, file);
sprintf(data, "%f",SUBSIDY_FRACTION);    print_tag("subsidy_fraction", data, file);

sprintf(data, "%f",unemployment_benefit_payment);    print_tag("gov_policy_unemployment_benefit_pct", data, file);

sprintf(data, "%d",NO_REGIONS_PER_GOV);	print_tag("no_regions_per_gov", data, file);
	fputs("</environment>\n", file);

 
	
	/* Firms */
	num_start = 1;
	int region;
	double mss; //mean_specific_skills
	for(num=num_start; num<total_firms+num_start; num++)
	{
		
		region = num % num_regions;
		
		if(region == 0)
			{
				region = num_regions; // because there is no region 0;
			}
		
		int row = (region-1) / num_regions_X;
		int column = (region-1) % num_regions_X; 

		int gov_id  = total_firms+total_households+total_IGfirms+region;
		
		if(region == 1)
		{
			mss = spec_s_hh_reg1;
			
		}
		if(region == 2)
		{
			mss = spec_s_hh_reg2;
			
		}

		cap_price = capital_good_price_region[column][row];
		
			


		fputs("<xagent>\n", file);
		fputs("<name>Firm</name>\n", file);
		sprintf(data, "%d", num);		print_tag("id", data, file);
		sprintf(data, "%d",region);    print_tag("region_id", data, file);
		sprintf(data, "%d",bank_id);    print_tag("bank_id", data, file);
		sprintf(data, "%d",gov_id);    print_tag("gov_id", data, file);
		sprintf(data, "{}");			print_tag("employees", data, file);
	
		int decil_production_rule = random_int(decil_production_rule_lower_bound,decil_production_rule_upper_bound);

		sprintf(data, "%d",decil_production_rule);	print_tag("decil_production_rule", data, file);	
		sprintf(data, "%f",base_wage_offer[column][row]);		print_tag("wage_offer", data, file);

		sprintf(data, "%f",wage_offer[column][row]);	print_tag("wage_offer_for_skill_1", data, file);
		sprintf(data, "%f",wage_offer[column][row]);	print_tag("wage_offer_for_skill_2", data, file);
		sprintf(data, "%f",wage_offer[column][row]);	print_tag("wage_offer_for_skill_3", data, file);
		sprintf(data, "%f",wage_offer[column][row]);	print_tag("wage_offer_for_skill_4", data, file);
		sprintf(data, "%f",wage_offer[column][row]);	print_tag("wage_offer_for_skill_5", data, file);

		sprintf(data, "%d",0);	print_tag("wage_update_was_made", data, file);

		sprintf(data, "%f",mss);	print_tag("average_s_skill_of_1", data, file);
		sprintf(data, "%f",mss);	print_tag("average_s_skill_of_2", data, file);
		sprintf(data, "%f",mss);	print_tag("average_s_skill_of_3", data, file);
		sprintf(data, "%f",mss);	print_tag("average_s_skill_of_4", data, file);
		sprintf(data, "%f",mss);	print_tag("average_s_skill_of_5", data, file);

		sprintf(data, "%f",technology[column][row]);		print_tag("technology", data, file);
		sprintf(data, "%d", 0);			print_tag("no_employees", data, file);

		sprintf(data, "%d", 0);		print_tag("no_employees_skill_1", data, file);
		sprintf(data, "%d", 0);		print_tag("no_employees_skill_2", data, file);
		sprintf(data, "%d", 0);		print_tag("no_employees_skill_3", data, file);
		sprintf(data, "%d", 0);		print_tag("no_employees_skill_4", data, file);
		sprintf(data, "%d", 0);		print_tag("no_employees_skill_5", data, file);

		sprintf(data, "%d", 0);			print_tag("vacancies", data, file);
		sprintf(data, "%f", 0.0);		print_tag("needed_capital_stock", data, file);
		sprintf(data, "%f", 1.0);		print_tag("out_of_stock_costs", data, file);
		sprintf(data, "%d", 0);			print_tag("employees_needed", data, file);

		
		int i = total_firms + total_households;
		int m_id = i;
		
		char data2[10000];
		char data1[10000];
		int m;
		
		
		sprintf(data, "%f", total_units_capital[column][row]);	print_tag("total_units_capital_stock", data, file);
		sprintf(data, "%f", total_units_capital[column][row]*cap_price);	print_tag("total_value_capital_stock", data, file);
		sprintf(data, "%f", total_units_capital[column][row]);	print_tag("planned_value_capital_stock", data, file);
		
		sprintf(data, "%f",  productivity_best_practice[column][row]);	print_tag("technological_frontier", data, file);


		
		

		
		double k = total_production_quantity[column][row];
		
		
		sprintf(data, "%f", payment_account[column][row]);	print_tag("payment_account", data, file);
		//financial resources of firm at the beginning of a simulation
		int first_mall_id = total_firms + total_households +total_Governments+total_IGfirms+total_banks;
			
	
		for( m=1; m<=total_malls;m++)
		{
			m_id = first_mall_id +m;
			if(m==1)
			{
			sprintf(data2, "{%d,%d,%f,%f}",m_id,m,(mall_delivery_fraction_1*k), 0);
			}
			
			else 
			{
			sprintf(data1, "%s,{%d,%d,%f,%f}",data2,m_id, m,(mall_delivery_fraction_2*k),0);
			sprintf(data2,"%s",data1);
			}
		}
		if(m>2)
		{sprintf(data, "{%s}",data1);	print_tag("current_mall_stocks", data, file);}	
		else
		{sprintf(data, "{%s}",data2);	print_tag("current_mall_stocks", data, file);}
		int qual = random_int(1,10);
		double qu = (double) qual;
		sprintf(data, "%f", 1.0);		print_tag("quality", data, file);
		
		sprintf(data, "%f", cap_price);		print_tag("actual_cap_price", data, file);
		sprintf(data, "%f", 0.8);		print_tag("price", data, file);
		sprintf(data, "%f", 0.8);		print_tag("price_last_month", data, file);
		sprintf(data, "%d", first_mall_id +region);			print_tag("home_mall", data, file);


		
		int d;
		char data3[10000];
		char data4[10000];
		

		for( m=1; m<=total_malls;m++)
		{
			m_id = first_mall_id + m;

				if(m==1)
				{
					sprintf(data4,"{{%d,%d,{",m_id,m,d,(mall_delivery_fraction_1*k));
					for (d=1; d<=years_statistics; d++)
					{
						if(d<years_statistics)
						{
							sprintf(data3,"%s{%d, %f},",data4,d,(mall_delivery_fraction_1*k));
							sprintf(data4,"%s",data3);
						}else
						{
					sprintf(data3,"%s{%d, %f}}}",data4,d,(mall_delivery_fraction_1*k));
					sprintf(data4,"%s",data3);
						}
					}

				}else
				{
				sprintf(data3,"%s,{%d,%d,{",data4,m_id,m,d,(mall_delivery_fraction_2*k));
				sprintf(data4,"%s",data3);

					
					
					for (d=1; d<=years_statistics; d++)
					{
						if(d<years_statistics)
						{
					sprintf(data3,"%s{%d, %f},",data4,d,(mall_delivery_fraction_2*k));
					sprintf(data4,"%s",data3);
						}else
						{
					sprintf(data3,"%s{%d, %f}}}",data4,d,(mall_delivery_fraction_2*k));
					sprintf(data4,"%s",data3);
						}
					}


				}
					sprintf(data3,"%s}",data4);
			}		
			
		sprintf(data, "{%s}",data3);	print_tag("malls_sales_statistics", data3, file);
		
		
			
		sprintf(data, "{%f,%f,%f,%f,%f}", k,k,k,k,k);	
								print_tag("last_planned_production_quantities", data, file);
		
		
		sprintf(initial_capi_costs, "{");
		int l;
		for(l=0; l< PERIODS_TO_REPAY_LOANS; l++)
		{

	
			{
				
				
				//sprintf(data1,"%s { %f , %d}",initial_capi_costs,rand_2, i);	
				sprintf(data1,"%s { %f , %d}",initial_capi_costs,total_units_capital[column][row]*cap_price*DEPRECIATION_RATE/PERIODS_TO_REPAY_LOANS, l);
				sprintf(initial_capi_costs,"%s",data1);

			}
			

		}
		
		sprintf(data,"%s }",initial_capi_costs);      print_tag("capital_financing", data, file);
		//sprintf(data,"{}");      print_tag("capital_financing", data, file);
		sprintf(data, "%f", 0.0);	print_tag("production_quantity", data, file);
		sprintf(data, "%f", 0.0);	print_tag("planned_production_quantity", data, file);	
		sprintf(data, "%f", wage_offer[column][row]);	print_tag("mean_wage", data, file);
		sprintf(data, "%f", mss);	print_tag("mean_specific_skills", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unit_costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("accruals", data, file);
		sprintf(data, "%f", 0.0);	print_tag("additional_accruals", data, file);
		sprintf(data, "%f", 0.0);	print_tag("dividend_accruals", data, file);
		sprintf(data, "%f", 0.0);	print_tag("revenue", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_revenue", data, file);
		sprintf(data, "%f", 0.0);	print_tag("out_of_stock_costs", data, file);
		sprintf(data, "{%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f}",0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0);	
	print_tag("last_net_earnings", data, file);
		
		
		

		


		for( m=1; m<=total_malls;m++)
		{
			m_id = first_mall_id + m;
			if(m==1)
			{
			sprintf(data2, "{%d,%d,0.0,0,0.0}",m_id,m);
			sprintf(data1,"%s",data2);
			}
			
			else 
			{
			sprintf(data1, "%s,{%d,%d,0.0,0,0.0}",data2,m_id,m);
			sprintf(data2,"%s",data1);
			}
		}

		sprintf(data, "{%s}",data1);	print_tag("sold_quantities", data, file);
		

		sprintf(data, "%f", 0.0);	print_tag("total_sold_quantity", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_total_sold_quantity", data, file);


		for( m=1; m<=total_malls;m++)
		{
			m_id = first_mall_id + m;
			if(m==1)
			{
			sprintf(data2, "{%d,%d,%f, 1.0,1.0}",m_id,m,(mall_delivery_fraction_1*k));
			}
			
			else 
			{
			sprintf(data1, "%s,{%d,%d,%f, 1.0,1.0}",data2,m_id,m,(mall_delivery_fraction_2*k));
			sprintf(data2,"%s",data1);
			}
		}

		if(m>2)
		{sprintf(data, "{%s}",data1);	print_tag("delivery_volume", data, file);}	
		else
		{sprintf(data, "{%s}",data2);	print_tag("delivery_volume", data, file);}
		

		for( m=1; m<=total_malls;m++)
		{
			m_id = first_mall_id + m;
			if(m==1)
			{
			sprintf(data2, "{%d,%d,0.0, 1.0,1.0}",m_id,m);
			}
			
			else 
			{
			sprintf(data1, "%s,{%d,%d,0.0, 1.0,1.0}",data2,m_id,m);
			sprintf(data2,"%s",data1);
			}
		}

		if(m>2)
		{sprintf(data, "{%s}",data1);	print_tag("planned_delivery_volume", data, file);}	
		else
		{sprintf(data, "{%s}",data2);	print_tag("planned_delivery_volume", data, file);}


		
		
		for( m=1; m<=total_malls;m++)
				{
					m_id = first_mall_id + m;
					if(m==1)
					{
					sprintf(data2, "{%d,0.0, 0.0,0.0}",m_id,m);
					}
					
					else 
					{
					sprintf(data1, "%s,{%d,0.0, 0.0,0.0}",data2,m_id,m);
					sprintf(data2,"%s",data1);
					}
				}
		
				if(m>2)
				{sprintf(data, "{%s}",data1);	print_tag("linear_regression_estimators", data, file);}	
				else
				{sprintf(data, "{%s}",data2);	print_tag("linear_regression_estimators", data, file);}

		
		sprintf(data, "%f", 0.0);	print_tag("ebit", data, file);
		
		sprintf(data, "%f", 0.0);	print_tag("total_external_financing_obtained", data, file);
		sprintf(data, "%f", tax_rate_corporate[column][row]);	print_tag("tax_rate_corporate", data, file);
		sprintf(data, "%f", 0.0);	print_tag("tax_rate_vat", data, file);
		sprintf(data, "%f", 0.0);	print_tag("earnings", data, file);
		sprintf(data, "%f", 0.0);	print_tag("previous_net_earnings", data, file);
		sprintf(data, "%f", 0.0);	print_tag("demand_capital_stock", data, file);
		sprintf(data, "%f", 0.01);	print_tag("adaption_production_volume_due_to_insufficient_finances", data, file);
		sprintf(data, "%f", 0.01);	print_tag("earnings_per_share", data, file);
		sprintf(data, "%d", total_households);	print_tag("current_shares_outstanding", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_interest_payment", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_debt_installment_payment", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_dividend_payment", data, file);
		sprintf(data, "%f", 0.0);	print_tag("previous_dividend_per_share", data, file);
		sprintf(data, "%f", 0.0);	print_tag("current_dividend_per_share", data, file);
		sprintf(data, "%f", 0.0);	print_tag("previous_earnings_per_share", data, file);
		sprintf(data, "%f", 0.0);	print_tag("current_earnings_per_share", data, file);
		sprintf(data, "%f", 0.0);	print_tag("previous_dividend_per_earnings", data, file);
		sprintf(data, "%f", 0.0);	print_tag("current_dividend_per_earnings", data, file);

		sprintf(data, "%f", 45.0);	print_tag("calc_production_costs", data, file);

		sprintf(data, "{}");		print_tag("loans", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_debt", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_value_local_inventory", data, file);
		
		
		sprintf(data, "%f", 0.0);	print_tag("total_capital_depreciation_value", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_capital_depreciation_units", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_assets", data, file);
		sprintf(data, "%f", 0.0);	print_tag("equity", data, file);
		sprintf(data, "%f", 0.0);	print_tag("production_liquidity_needs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("financial_liquidity_needs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_financial_needs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("external_financial_needs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_payments", data, file);
		sprintf(data, "%f", mss);	print_tag("firm_productivity", data, file);
		sprintf(data, "%f", 0.0);	print_tag("firm_productivity_last_year", data, file);
		sprintf(data, "%f", 0.0);	print_tag("firm_productivity_progress", data, file);
		
		int rnd = random_int(0,19);
		sprintf(data, "%d", rnd);	print_tag("day_of_month_to_act", data, file);
		int rnd2 = ((rnd-1)+20)%20;		
		sprintf(data, "%d",rnd2);	print_tag("last_day_of_month_to_act", data, file);
		
	//sprintf(data, "%d", 0);	print_tag("day_of_month_to_act", data, file);
			
		//sprintf(data, "%d",19);	print_tag("last_day_of_month_to_act", data, file);

		sprintf(data, "%f", 0.0);	print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);	print_tag("posy", data, file);
		fputs("</xagent>\n", file);
	}


	/* IGFirm */
	num_start = num;
	for(num=num_start; num<total_IGfirms+num_start; num++)
	{		
			
		int gov_id  = total_firms+total_households+total_IGfirms+1;
		
		fputs("<xagent>\n", file);
		fputs("<name>IGFirm</name>\n", file);
		sprintf(data, "%d", num);     print_tag("id", data, file);
		id_igfirm = num;
		sprintf(data, "%d",1);	print_tag("region_id", data, file);
		sprintf(data, "%d",gov_id);	print_tag("gov_id", data, file);
		sprintf(data, "%d",bank_id);		print_tag("bank_id", data, file);
		sprintf(data, "%f",.0);	print_tag("payment_account", data, file);
		sprintf(data, "%f",productivity_best_practice_igfirm);	print_tag("productivity", data, file);
		sprintf(data, "%f", capital_good_price);	print_tag("capital_good_price", data, file);
		sprintf(data, "%d",0);		print_tag("day_of_month_to_act", data, file);
		sprintf(data, "%f", 0.0);	print_tag("revenue_per_day", data, file);
		sprintf(data, "%f", tax_rate_corporate[0][0]);	print_tag("tax_rate_corporate", data, file);
		sprintf(data, "%f", 0.0);	print_tag("tax_rate_vat", data, file);
		sprintf(data, "%d", total_households);	print_tag("outstanding_shares", data, file);
		sprintf(data, "%f", 0.0);	print_tag("current_dividend_per_share", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_revenues", data, file);
		sprintf(data, "%f", 0.0);	print_tag("net_profit", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_net_profits", data, file);
		sprintf(data, "{%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f}",0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0);		print_tag("last_net_profits", data, file);

print_tag("innovation_scheme", innovation_scheme, file);
		
		sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
	
		fputs("</xagent>\n", file);
	}






	
	num_start = num;
	int counter;
	int r_id = 1;
	int g_skill_level;
	int a_id=num_start;
	int a,l;
	for( a=0; a<num_regions; a++)
	{
		
		for(counter = 1; counter <=  households_per_region; counter++)
		{
		fputs("<xagent>\n", file);
		fputs("<name>Household</name>\n", file);

		region= r_id;
		int row = (region-1) / num_regions_X;
		int column = (region-1) % num_regions_X; 
		double skill_fraction_1;
		double	skill_fraction_2;
		double	skill_fraction_3;
		double	skill_fraction_4;
		double	skill_fraction_5;
		
		int gov_id  = total_firms+total_households+total_IGfirms+region;


		if(skills_in_regions[column][row]==1)
			{
			skill_fraction_1 = skilldistribution_1[0];
			skill_fraction_2 = skilldistribution_1[1];
			skill_fraction_3 = skilldistribution_1[2];
			skill_fraction_4 = skilldistribution_1[3];
			skill_fraction_5 = skilldistribution_1[4];
			}	
		else if(skills_in_regions[column][row]==2)
			{
			skill_fraction_1 = skilldistribution_2[0];
			skill_fraction_2 = skilldistribution_2[1];
			skill_fraction_3 = skilldistribution_2[2];
			skill_fraction_4 = skilldistribution_2[3];
			skill_fraction_5 = skilldistribution_2[4];
			}
		else if(skills_in_regions[column][row]==3)
			{
			skill_fraction_1 = skilldistribution_3[0];
			skill_fraction_2 = skilldistribution_3[1];
			skill_fraction_3 = skilldistribution_3[2];
			skill_fraction_4 = skilldistribution_3[3];
			skill_fraction_5 = skilldistribution_3[4];
			}
		else if(skills_in_regions[column][row]==4)
			{
			skill_fraction_1 = skilldistribution_4[0];
			skill_fraction_2 = skilldistribution_4[1];
			skill_fraction_3 = skilldistribution_4[2];
			skill_fraction_4 = skilldistribution_4[3];
			skill_fraction_5 = skilldistribution_4[4];
			}
		if(counter<=skill_fraction_1* households_per_region)
			g_skill_level =1;
		else if(counter<=(skill_fraction_1+skill_fraction_2)* households_per_region)
			g_skill_level =2;
		else if(counter<=(skill_fraction_1+skill_fraction_2+skill_fraction_3)* households_per_region)
			g_skill_level =3;
		else if(counter<=(skill_fraction_1+skill_fraction_2+skill_fraction_3+skill_fraction_4)* households_per_region)
			g_skill_level =4;
		else
			g_skill_level =5;
		sprintf(data, "%d", a_id);     	print_tag("id", data, file);
		sprintf(data, "%d",region);     print_tag("region_id", data, file);
		sprintf(data, "%d", gov_id);     print_tag("gov_id", data, file);
		sprintf(data, "%d",bank_id);     print_tag("bank_id", data, file);
		
		if(row-1>=0 && row +1< num_regions_Y)
		{
			sprintf(data,"{%d,",region_grid[column][row-1]);
			if(column-1>=0 )
			{
				sprintf(data,"%s%d,%d,%d,",data,region_grid[column-1][row-1],region_grid[column-1][row],region_grid[column-1][row+1]);
			}
			if(column+1<num_regions_X)
			{
			sprintf(data,"%s%d,%d,%d,",data,region_grid[column+1][row-1],region_grid[column+1][row],region_grid[column+1][row+1]);
			}		
			sprintf(data,"%s%d}",data,region_grid[column][row+1]);
			print_tag("neighboring_region_ids", data, file);
		}	

		if(row-1>=0 && row +1>= num_regions_Y)
		{
			sprintf(data,"{");
			if(column-1>=0)	
			{
			sprintf(data,"%s%d,%d,",data,region_grid[column-1][row-1],region_grid[column-1][row]);
			}
			if(column+1<num_regions_X)
			{
			sprintf(data,"%s%d,%d,",data,region_grid[column+1][row-1],region_grid[column+1][row]);
			}
			sprintf(data,"%s%d}",data,region_grid[column][row-1]);
			print_tag("neighboring_region_ids", data, file);
		
		}	

		
		if(row-1<0 && row +1< num_regions_Y)
		{
			sprintf(data,"{");
			if(column-1>=0)	
			{
			sprintf(data,"%s%d,%d,",data,region_grid[column-1][row+1],region_grid[column-1][row]);
			}
			if(column+1<num_regions_X)
			{
			sprintf(data,"%s%d,%d,",data,region_grid[column+1][row+1],region_grid[column+1][row]);
			}
			sprintf(data,"%s%d}",data,region_grid[column][row+1]);
			print_tag("neighboring_region_ids", data, file);
		}	


		if(row-1<0 && row +1>= num_regions_Y)
		{
			if(column-1>=0&& column+1 < num_regions_X)
			{
			sprintf(data,"{%d,%d}",region_grid[column-1][row],region_grid[column+1][row]);
			}
			else if(column-1>=0&& column+1 >=num_regions_X)
			{

			sprintf(data,"{%d}",region_grid[column-1][row]);
			//printf("%s",data);
			}
			else if(column-1<0&& column+1 < num_regions_X)
			{
			
			sprintf(data,"{%d}",region_grid[column+1][row]);
			//printf("%s",data);
			}
			else
			sprintf(data,"{}");
			
			print_tag("neighboring_region_ids", data, file);
	
		}	

		
		sprintf(data, "%f", 0);     	print_tag("wage", data, file);
		sprintf(data, "%f", wage_offer[column][row]); 	print_tag("wage_reservation", data, file);
		sprintf(data, "%f", wage_offer[column][row]); 	print_tag("last_labour_income", data, file);
		sprintf(data, "%d", -1);       	print_tag("employee_firm_id", data, file);
		sprintf(data, "%d", g_skill_level);   print_tag("general_skill", data, file);
		sprintf(data, "%f", specific_skills_of_household[column][row]);       print_tag("specific_skill", data, file);
		sprintf(data, "%d", 0);     	print_tag("on_the_job_search", data, file);
		sprintf(data, "%d", num_app);   print_tag("number_applications", data, file);
		sprintf(data, "%d", 0);       	print_tag("rationed", data, file);
		sprintf(data, "%f", payment_account_household);       print_tag("consumption_budget", data, file);
		sprintf(data, "%f", payment_account_household/4);       print_tag("weekly_budget", data, file);
		sprintf(data, "%f", payment_account_household);	print_tag("payment_account", data, file);
		sprintf(data, "%f", 0.0);	print_tag("mean_income", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_taxes", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_total_dividends", data, file);
		sprintf(data, "%f", tax_rate_hh_capital[column][row]);	print_tag("tax_rate_hh_capital", data, file);
		sprintf(data, "%f", tax_rate_hh_labour[column][row]);	print_tag("tax_rate_hh_labour", data, file);
		sprintf(data, "%f", 0.0);	print_tag("expenditures", data, file);
		sprintf(data, "%f", 0.0);	print_tag("received_dividends", data, file);
		sprintf(data, "%d", 0);		print_tag("just_employed", data, file);
		sprintf(data, "%d", 0);		print_tag("just_unemployed", data, file);
		sprintf(data, "%d", 0);		print_tag("just_employed_OTJS", data, file);
		sprintf(data, "%d", 0);		print_tag("just_unemployed_OTJS", data, file);
		

		for(l=1; l<=total_firms+1;l++)
		{
			
			if(l==1)
			{
			sprintf(data2, "{%d, 1,0.1}",l);
			}
			
			else 
			{
			sprintf(data1, "%s,{%d, 1,0.1}",data2,l);
			sprintf(data2,"%s",data1);
			}
		}

		
		sprintf(data1, "%s,{%d, 1,0.1}",data2,bank_id);
						sprintf(data2,"%s",data1);
		 
		
		sprintf(data, "{%s}",data2);	print_tag("assetsowned", data, file);

		sprintf(data, "{%f,%f,%f,%f}", 1.0,1.0,1.0,1.0);	
		print_tag("last_income", data, file);
		
		sprintf(data, "{{%d, %f, %f},{%d, %f, %f}}", 0, 0.0, 0.0,0,0.0,0.0);       
		print_tag("order_quantity", data, file);
		
		sprintf(data, "{{%d, %f},{%d, %f}}", 0, 0.0,0,0.0);       
		print_tag("received_quantity", data, file);

		sprintf(data, "%d", random_int(0,4));	
		//sprintf(data, "%d", 0);
		print_tag("day_of_week_to_act", data, file);
		sprintf(data, "%d", 4);		print_tag("week_of_month", data, file);
		sprintf(data, "%d", 0);		print_tag("day_of_month_to_act", data, file);
		sprintf(data, "%d", 0);		print_tag("day_of_month_receive_income", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
		fputs("</xagent>\n", file);
		a_id++;	
		}
		
		r_id++;
		
		

	}

	num+=total_households;
	
	





num_start = num;
r_id = 1;
	for(num=num_start; num<total_Governments+num_start; num++)
	{
		region = r_id;
				
		int row = (region-1) / num_regions_X;
		int column = (region-1) % num_regions_X;
						
		fputs("<xagent>\n", file);
		fputs("<name>Government</name>\n", file);
		sprintf(data, "%d", num);     print_tag("id", data, file);
		sprintf(data, "%d",bank_id);	print_tag("bank_id", data, file);
		sprintf(data, "%d",region);	print_tag("region_id", data, file);
		sprintf(data, "%f",payment_account_government);	print_tag("payment_account", data, file);
		sprintf(data, "%f",0.0);	print_tag("tax_revenues", data, file);
		sprintf(data, "%f",unemployment_benefit_payment[column][row]);		print_tag("unemployment_benefit_pct", data, file);
		sprintf(data, "%f",0.0);		print_tag("total_unemployment_benefit_payment", data, file);
		sprintf(data, "%f",0.0);	print_tag("total_interest_payment", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_debt", data, file);
		sprintf(data, "%f", tax_rate_corporate[column][row]);	print_tag("tax_rate_corporate", data, file);
		sprintf(data, "%f",tax_rate_hh_labour[column][row]);	print_tag("tax_rate_hh_labour", data, file);
		sprintf(data, "%f",tax_rate_hh_capital[column][row]);	print_tag("tax_rate_hh_capital", data, file);
		sprintf(data, "%f",0.0);	print_tag("tax_rate_vat", data, file);
		
		sprintf(data, "{%d}",region);       print_tag("list_of_regions", data, file);
	
		fputs("</xagent>\n", file);
		r_id++;
	}


num_start = num;

	
	for(num=num_start; num<total_banks+num_start; num++)
	{
		int gov_id  = total_firms+total_households+total_IGfirms+1;
		
		fputs("<xagent>\n", file);
						fputs("<name>Bank</name>\n", file);
						sprintf(data, "%d", num);     print_tag("id", data, file);
						sprintf(data, "%d",1);	print_tag("region_id", data, file);
						sprintf(data, "%d",gov_id);	print_tag("gov_id", data, file);
						
					
						sprintf(data, "{}");			print_tag("loans_outstanding", data, file);

						sprintf(data, "%f",0.0);	print_tag("total_deposits", data, file);
						sprintf(data, "%f",0.0);	print_tag("amount_credit_offer", data, file);
						sprintf(data, "%f",0.0);	print_tag("total_loan_supply", data, file);
						sprintf(data, "%f",0.0);	print_tag("total_loan_demand", data, file);
						sprintf(data, "%f",0.0);	print_tag("payment_account", data, file);
						sprintf(data, "%d",0);	 print_tag("last_credit_id", data, file);
						sprintf(data, "%f", tax_rate_corporate[0][0]);	print_tag("tax_rate_corporate", data, file);
						sprintf(data, "%d", 0);	print_tag("day_of_month_to_act", data, file);
						printf("total_households %d\n",total_households);
						sprintf(data, "%d", total_households);	print_tag("outstanding_shares", data, file);
						sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
						sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
					
						fputs("</xagent>\n", file);
	}


	/* Mall */

		
		int j=1;
	num_start = num;
	for(num=num_start; num<total_malls+num_start; num++)
	{	
		
		fputs("<xagent>\n", file);
		fputs("<name>Mall</name>\n", file);
		sprintf(data, "%d", num);     print_tag("id", data, file);
		sprintf(data, "%d",j);	print_tag("region_id", data, file);
		j++;
		
		int i;
		for( i=1; i<=total_firms;i++)
		{

		int region = i % num_regions;

				
		if(region == 0)
			{
				region = num_regions; // because there is no region 0;
			}
		
		int row = (region-1) / num_regions_X;
				int column = (region-1) % num_regions_X; 
		
				
		
				

		if(region == 0)
			{
				region = num_regions; // because there is no region 0;
			}
		if(i==1)
		{
		sprintf(data2, "{%d , %d, %f, %f, %f, %f}",i, region, 0.0,1.0,0.0);
		}
		else 
			{
			sprintf(data1, "%s,{%d , %d, %f, %f, %f, %f}",data2,i,region,0.0,1.0,0.0);
			sprintf(data2,"%s",data1);
			}
		}
		
		if(i==2)
		{
		sprintf(data, "{%s}",data2);	print_tag("current_stock", data, file);
		}else
		{
		sprintf(data, "{%s}",data1);	print_tag("current_stock", data, file);
		}
		


	
		for( i=1; i<=total_firms;i++)
		{

		int region = i % num_regions;

				
		if(region == 0)
		{
			region = num_regions; // because there is no region 0;
		}
		
		//int row = (region-1) / num_regions_X;
		//int column = (region-1) % num_regions_X; 
			
		if(i==1)
		{
		sprintf(data2, "{%d ,%d,%f}",i,region,0.0);
		}
		else 
			{
			sprintf(data1, "%s,{%d,%d,%f}",data2,i,region,0.0);
			sprintf(data2,"%s",data1);
			}
		}
		
		if(i==2)
		{
		sprintf(data, "{%s}",data2);	print_tag("firm_revenues", data, file);
		}else
		{
		sprintf(data, "{%s}",data1);	print_tag("firm_revenues", data, file);
		}



		sprintf(data, "%f", 0.0);       print_tag("real_mall_inventory_last_month", data, file);
		sprintf(data, "%f", 0.0);       print_tag("nominal_mall_inventory_last_month", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
	
		fputs("</xagent>\n", file);
	}
	



/* Market Research */
	num_start = num;
	for(num=num_start; num<1+num_start; num++)
	{
		fputs("<xagent>\n", file);
		fputs("<name>Eurostat</name>\n", file);

sprintf(data, "%d", 1);     print_tag("switch_datastorage", data, file);
		sprintf(data, "%d", num);     print_tag("id", data, file);
		sprintf(data, "%d",random_int(1,num_regions));	print_tag("region_id", data, file);
		sprintf(data, "%d", num_regions);     print_tag("no_regions", data, file);
		print_tag("skill_distribution_regional", skill_distribution, file);
		sprintf(data, "%d",0);		print_tag("num_households", data, file);
		sprintf(data, "%d",0);		print_tag("no_households_skill_1", data, file);
		sprintf(data, "%d",0);		print_tag("no_households_skill_2", data, file);
		sprintf(data, "%d",0);		print_tag("no_households_skill_3", data, file);
		sprintf(data, "%d",0);		print_tag("no_households_skill_4", data, file);
		sprintf(data, "%d",0);		print_tag("no_households_skill_5", data, file);
		sprintf(data, "%d",0);		print_tag("employed", data, file);
		sprintf(data, "%d",0);		print_tag("employed_skill_1", data, file);
		sprintf(data, "%d",0);		print_tag("employed_skill_2", data, file);
		sprintf(data, "%d",0);		print_tag("employed_skill_3", data, file);
		sprintf(data, "%d",0);		print_tag("employed_skill_4", data, file);
		sprintf(data, "%d",0);		print_tag("employed_skill_5", data, file);
		sprintf(data, "%d",0);		print_tag("unemployed", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unemployment_rate", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unemployment_rate_skill_1", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unemployment_rate_skill_2", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unemployment_rate_skill_3", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unemployment_rate_skill_4", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unemployment_rate_skill_5", data, file);
		sprintf(data, "%f", 0.0);	print_tag("average_wage", data, file);
		sprintf(data, "%f", 0.0);	print_tag("average_wage_skill_1", data, file);
		sprintf(data, "%f", 0.0);	print_tag("average_wage_skill_2", data, file);
		sprintf(data, "%f", 0.0);	print_tag("average_wage_skill_3", data, file);
		sprintf(data, "%f", 0.0);	print_tag("average_wage_skill_4", data, file);
		sprintf(data, "%f", 0.0);	print_tag("average_wage_skill_5", data, file);
		sprintf(data, "%f", 1.0);	print_tag("average_s_skill", data, file);
		sprintf(data, "%f", 1.0);	print_tag("average_s_skill_1", data, file);
		sprintf(data, "%f", 1.0);	print_tag("average_s_skill_2", data, file);
		sprintf(data, "%f", 1.0);	print_tag("average_s_skill_3", data, file);
		sprintf(data, "%f", 1.0);	print_tag("average_s_skill_4", data, file);
		sprintf(data, "%f", 1.0);	print_tag("average_s_skill_5", data, file);


		sprintf(data, "%d",0);		print_tag("no_firm", data, file);
		sprintf(data, "%d",0);		print_tag("no_vacancies", data, file);
		sprintf(data, "%d",0);		print_tag("no_employees", data, file);
		sprintf(data, "%d",0);		print_tag("no_employees_skill_1", data, file);
		sprintf(data, "%d",0);		print_tag("no_employees_skill_2", data, file);
		sprintf(data, "%d",0);		print_tag("no_employees_skill_3", data, file);
		sprintf(data, "%d",0);		print_tag("no_employees_skill_4", data, file);
		sprintf(data, "%d",0);		print_tag("no_employees_skill_5", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_wage", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_wage_skill_1", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_wage_skill_2", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_wage_skill_3", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_wage_skill_4", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_wage_skill_5", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_s_skill", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_s_skill_1", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_s_skill_2", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_s_skill_3", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_s_skill_4", data, file);
		sprintf(data, "%f", 1.0);	print_tag("firm_average_s_skill_5", data, file);

		sprintf(data, "%d", 0);		print_tag("day_of_month_to_act", data, file);
		sprintf(data, "%f", 1.0);		print_tag("cpi", data, file);
		sprintf(data, "%f", 0.0);		print_tag("firm_average_productivity", data, file);
		sprintf(data, "%f", 0.0);		print_tag("firm_average_productivity_progress", data, file);

		sprintf(data, "{{1,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,1.0,0,0},{2,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,1.0,0,0}}");       print_tag("region_firm_data", data, file);

		sprintf(data, "{{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,%f,%f,%f,%f,%f},{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,%f,%f,%f,%f,%f}}",spec_s_hh_reg1,spec_s_hh_reg1,spec_s_hh_reg1,spec_s_hh_reg1,spec_s_hh_reg1,spec_s_hh_reg2,spec_s_hh_reg2,spec_s_hh_reg2,spec_s_hh_reg2,spec_s_hh_reg2);       print_tag("region_household_data", data, file);


sprintf(data, "{{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0},{0,0.0,0.0,0.0,0.0}}");		print_tag("government_tax_rates", data, file);
sprintf(data, "{{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}}}");		print_tag("history_monthly", data, file);
sprintf(data, "{{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}},{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}}}");		print_tag("history_monthly", data, file);
sprintf(data, "{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}}");		print_tag("monthly_growth_rates", data, file);
sprintf(data, "{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}}");		print_tag("quarterly_growth_rates", data, file);
sprintf(data, "{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}}");		print_tag("annual_growth_rates_monthly", data, file);
sprintf(data, "{1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0,{{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0},{1.0,1.0,0.0,0.0,0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0}}}");		print_tag("annual_growth_rates_quarterly", data, file);
sprintf(data, "{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}");		print_tag("firm_age_distribution", data, file);
sprintf(data, "{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}");		print_tag("firm_age_distribution_multiperiod", data, file);
sprintf(data, "{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}");		print_tag("firm_age_distribution_1_period_lag", data, file);
sprintf(data, "{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}");		print_tag("firm_age_distribution_2_period_lag", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("survival_rate", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("survival_rate_multiperiod_1", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("survival_rate_multiperiod_2", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("export_volume_matrix", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("survival_rate_multiperiod", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("export_value_matrix", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("export_previous_value_matrix", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("region_export_volume", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("region_import_volume", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("region_export_value", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("region_import_value", data, file);
sprintf(data, "{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}");		print_tag("region_import_previous_value", data, file);


		fputs("</xagent>\n", file);
	}





	
	fputs("</states>\n", file);
	
	/* Close the file */
	fclose(file);
	
	/* Exit successfully by returning zero to Operating System */
	return 0;
}
