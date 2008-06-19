#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	char data[100000];
	char data2[100000];
	char data1[100000];
	int num;  /*used as an index to cycle through each agent*/
	int num_start;
	int l;
	
	
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 
 * Parameter setting
 * 
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/	
	
	
	
	
	/*Defining the geographical space as a rectangular grid  */	
	
	int num_regions_X=1;/*Number of columns*/
	int num_regions_Y=2;/*Number of regions*/
	int num_regions = num_regions_X*num_regions_Y; /*number of regions*/
	
	
	int total_households = 1200;/*number of households in the economy*/
	int households_per_region = total_households/num_regions; 

	int total_firms  = 30; /*total_firms modulo num_regions should be 0*/
	int total_IGfirms = 1;
	int total_market_research = 1;
	int total_malls = num_regions;  /*one mall per region*/
	int num_app =  0.5*total_firms; /*number of applications per agent*/
	int total_Governments =1;
	int total_banks = 1;
	

	double 	tax_rate_corporate = 0.25;
	double	tax_rate_hh_labour = 0.25;
	double	tax_rate_hh_capital =0.25;
	double	unemployment_benefit_payment = 0.8;
	double	payment_account_government =100.0;

	double	capital_good_price = 100.0;
	int years_statistics = 10;/*number of years used to smooth the production*/

	/*Defining skill distributions in regions*/

	double skilldistribution_1[5]={0.6,0.1,0.1,0.1,0.1};
	double skilldistribution_2[5]={0.1,0.1,0.6,0.1,0.1};
	double skilldistribution_3[5]={0.1,0.1,0.1,0.1,0.6};
	double skilldistribution_4[5]={0.2,0.2,0.2,0.2,0.2};

	
	
	
	/*++++++++++++++++++++++++++++++++++++++++++++++++++
	 +++Initialization of region depending variables.
	 For the following variables you can assign region specific initial values. The regions are arranged on a rectangular grid (num_regions_X x num_regions_Y), 
	 so use the following template for the initalization( Example for a 3x3 region grid):
	 
	 region 1, 4, 9 ->x
	 region 3, 5, 6, 7, 8 -> y
	
				{{x,y,y},{x,y,y},{y,y,x}};
	 
	 												++ 
	 ++++++++++++++++++++++++++++++++++++++++++++++++/*

	/*This determines the local skill distribution. Use numbers 1 .. 4 (see above, skill distribution_X) to give a region a skill distribution. */

	//Scenario 0: 2 regions, LOW, LOW
	int skills_in_regions[1][2]=
				{{1,1}};
/*
	//Scenario 0: 4 regions, LOW, LOW
	int skills_in_regions[2][2]=
				{{1,1},{1,1}};

	//Scenario 1: core has HIGH, periphery has LOW
	int skills_in_regions[3][3]=
				{{1,1,1},{1,3,1},{1,1,1}};
*/
/*	
	//Scenario 2: core has HIGH, periphery has MEDIUM
	int skills_in_regions[3][3]=
				{{2,2,2},{2,3,2},{2,2,2}};
*/
/*
	//Scenario 3: core has MEDIUM, periphery has LOW
	int skills_in_regions[3][3]=
				{{1,1,1},{1,2,1},{1,1,1}};
*/
/*
	//Scenario 4: core has MEDIUM, periphery has MEDIUM
	int skills_in_regions[3][3]=
				{{2,2,2},{2,2,2},{2,2,2}};
*/
/*	
	//Scenario 5: core has MEDIUM, periphery has HIGH
	int skills_in_regions[3][3]=
				{{3,3,3},{3,2,3},{3,3,3}};
*/
/*	
	//Scenario 6: core has LOW, periphery has MEDIUM
	int skills_in_regions[3][3]=
				{{2,2,2},{2,1,2},{2,2,2}};
*/
/*	
	//Scenario 7: core has LOW, periphery has HIGH
	int skills_in_regions[3][3]=
				{{3,3,3},{3,1,3},{3,3,3}};
*/	
	
	//region specific initial value of households specific skills
	double specific_skills_of_household[3][3]=
					{{0.8,0.8,0.8},{0.8,1.0,0.8},{0.8,0.8,0.8}};
	

	//Total production volume for a single firm
	double total_production_quantity[3][3]=
	{{30.0,30.0,30.0},{30.0,30.0,30.0},{30.0,30.0,30.0}};
	
	
	//This defines the initial capital stock of firm depending on the region.
	double total_units_capital[3][3]=
	                              {{2.0,2.0,2.0}, {2.0,2.0,2.0}, {2.0,2.0,2.0}};
	//Firm's starting value of productivity of the capital stock
	double technology[3][3]=
	{{1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,1.0,1.0}};
	//This defines the financial resources of firm at the beginning of a simulation
	double payment_account[3][3]= 
	{{50.0,50.0,50.0},{50.0,50.0,50.0},{50.0,50.0,50.0}};
	
	
	/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	
	







	


	int gov_id  = total_firms+total_households+total_IGfirms+1;
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
	
	/* Firms */
	num_start = 1;
	int region;
	for(num=num_start; num<total_firms+num_start; num++)
	{
		
		region = num % num_regions;
		
		if(region == 0)
			{
				region = num_regions; // because there is no region 0;
			}
		
		int row = (region-1) / num_regions_X;
				int column = (region-1) % num_regions_X; 
		
				
				
				
		double wage_offer = random_double(1,1);
		fputs("<xagent>\n", file);
		fputs("<name>Firm</name>\n", file);
		sprintf(data, "%d", num);		print_tag("id", data, file);
		sprintf(data, "%d",region);    print_tag("region_id", data, file);
		sprintf(data, "%d",bank_id);    print_tag("bank_id", data, file);
		sprintf(data, "%d",gov_id);    print_tag("gov_id", data, file);
		sprintf(data, "{}");			print_tag("employees", data, file);	
		sprintf(data, "%f",wage_offer);		print_tag("wage_offer", data, file);

		sprintf(data, "%f",wage_offer);	print_tag("wage_offer_for_skill_1", data, file);
		sprintf(data, "%f",wage_offer);	print_tag("wage_offer_for_skill_2", data, file);
		sprintf(data, "%f",wage_offer);	print_tag("wage_offer_for_skill_3", data, file);
		sprintf(data, "%f",wage_offer);	print_tag("wage_offer_for_skill_4", data, file);
		sprintf(data, "%f",wage_offer);	print_tag("wage_offer_for_skill_5", data, file);

		sprintf(data, "%d",0);	print_tag("wage_update_was_made", data, file);

		sprintf(data, "%f",1.0);	print_tag("average_s_skill_of_1", data, file);
		sprintf(data, "%f",1.0);	print_tag("average_s_skill_of_2", data, file);
		sprintf(data, "%f",1.0);	print_tag("average_s_skill_of_3", data, file);
		sprintf(data, "%f",1.0);	print_tag("average_s_skill_of_4", data, file);
		sprintf(data, "%f",1.0);	print_tag("average_s_skill_of_5", data, file);

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
		double estimated_demand = wage_offer*total_households/(total_firms*total_malls);
		char data2[10000];
		char data1[10000];
		int m;
		
		
		sprintf(data, "%f", total_units_capital[column][row]);	print_tag("total_units_capital_stock", data, file);
		sprintf(data, "%f", total_units_capital[column][row]*capital_good_price);	print_tag("total_value_capital_stock", data, file);
		sprintf(data, "%f", total_units_capital[column][row]);	print_tag("planned_value_capital_stock", data, file);
		
		
		
		double k = total_production_quantity[column][row]/total_malls;
		
		
		sprintf(data, "%f", payment_account[column][row]);	print_tag("payment_account", data, file);
		//financial resources of firm at the beginning of a simulation
		int first_mall_id = total_firms + total_households +total_Governments+total_IGfirms+total_banks;
		
		for( m=1; m<=total_malls;m++)
		{
			m_id = first_mall_id +m;
			if(m==1)
			{
			sprintf(data2, "{%d,%f,0.0}",m_id, k);
			}
			
			else 
			{
			sprintf(data1, "%s{%d,%f,0.0}",data2,m_id, k);
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
		
		
		sprintf(data, "%f", 2.0);		print_tag("price", data, file);
		sprintf(data, "%f", 2.0);		print_tag("price_last_month", data, file);


		
		int d;
		char data3[10000];
		char data4[10000];
		

		for( m=1; m<=total_malls;m++)
		{
			m_id = first_mall_id + m;

			for (d=1; d<=years_statistics; d++)
			{
				if(d==1)
				{
					sprintf(data4,"{%d,%d, %f}",m_id,d,k);
				}
				else
				{
					sprintf(data3,"%s{%d,%d, %f}",data4,m_id,d,k);
					sprintf(data4,"%s",data3);
				}
			
		
			}
			if(m==1)
			{
			/*sprintf(data2, "{%d,1,%f}{%d,2,%f}{%d,3,%f}{%d,4,%f}{%d,5,%f}{%d,6,%f}{%d,7,%f}{%d,8,%f}{%d,9,%f}{%d,10,f}",m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k);*/
			sprintf(data2,"%s",data4);
			}
			
			else 
			{
			/*sprintf(data1, "%s{%d,1,%f}{%d,2,%f}{%d,3,%f}{%d,4,%f}{%d,5,%f}{%d,6,%f}{%d,7,%f}{%d,8,%f}{%d,9, %f}{%d,10,%f}",data2,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k,m_id,k);
			sprintf(data2,"%s",data1);*/
			sprintf(data1,"%s%s",data2,data4);
			sprintf(data2,"%s",data1);
			//}
			}
		}
		if(m>2)
		{sprintf(data, "{%s}",data1);	print_tag("malls_sales_statistics", data, file);}	
		else
		{sprintf(data, "{%s}",data2);	print_tag("malls_sales_statistics", data, file);}
		
		
		
		sprintf(data, "%f", 0.0);	print_tag("production_quantity", data, file);
		sprintf(data, "%f", 0.0);	print_tag("planned_production_quantity", data, file);	
		sprintf(data, "%f", wage_offer);	print_tag("mean_wage", data, file);
		sprintf(data, "%f", 0.8);	print_tag("mean_specific_skills", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unit_costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("revenue", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_revenue", data, file);
		sprintf(data, "%f", 0.0);	print_tag("out_of_stock_costs", data, file);
		
		
		sprintf(data, "{%f,%f,%f,%f,%f}", num_regions*k,num_regions*k,num_regions*k,num_regions*k,num_regions*k);	
		print_tag("last_planned_production_quantities", data, file);

		


		for( m=1; m<=total_malls;m++)
		{
			m_id = first_mall_id + m;
			if(m==1)
			{
			sprintf(data2, "{%d, 0.0,0, 0.0}",m_id);
			}
			
			else 
			{
			sprintf(data1, "%s{%d, 0.0,0, 0.0}",data2,m_id);
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
			sprintf(data2, "{%d, %f, 1.0,1.0}",m_id,k);
			}
			
			else 
			{
			sprintf(data1, "%s{%d,%f, 1.0,1.0}",data2,m_id,k);
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
			sprintf(data2, "{%d, 0.0, 1.0,1.0}",m_id);
			}
			
			else 
			{
			sprintf(data1, "%s{%d, 0.0, 1.0,1.0}",data2,m_id);
			sprintf(data2,"%s",data1);
			}
		}

		if(m>2)
		{sprintf(data, "{%s}",data1);	print_tag("planned_delivery_volume", data, file);}	
		else
		{sprintf(data, "{%s}",data2);	print_tag("planned_delivery_volume", data, file);}


		
		sprintf(data, "%f", 0.0);	print_tag("ebit", data, file);
		
		sprintf(data, "%f", 0.0);	print_tag("total_external_financing_obtained", data, file);
		sprintf(data, "%f", tax_rate_corporate);	print_tag("tax_rate_corporate", data, file);
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
		
		sprintf(data, "%d", 0);	print_tag("day_of_month_to_act", data, file);
		
		sprintf(data, "%f", 0.0);	print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);	print_tag("posy", data, file);
		fputs("</xagent>\n", file);
	}


	/* IGFirm */
	num_start = num;
	for(num=num_start; num<total_IGfirms+num_start; num++)
	{
		fputs("<xagent>\n", file);
		fputs("<name>IGFirm</name>\n", file);
		sprintf(data, "%d", num);     print_tag("id", data, file);
		sprintf(data, "%d",random_int(1,num_regions));	print_tag("region_id", data, file);
		sprintf(data, "%d",gov_id);	print_tag("gov_id", data, file);
		sprintf(data, "%d",bank_id);		print_tag("bank_id", data, file);
		sprintf(data, "%f",.0);	print_tag("payment_account", data, file);
		sprintf(data, "%f",1.0);	print_tag("productivity", data, file);
		sprintf(data, "%d",10);		print_tag("innovation_probability", data, file);
		sprintf(data, "%f",0.05);	print_tag("productivity_progress", data, file);
		sprintf(data, "%f", capital_good_price);	print_tag("capital_good_price", data, file);
		sprintf(data, "%d",0);		print_tag("day_of_month_to_act", data, file);
		sprintf(data, "%f", 0.0);	print_tag("revenue_per_day", data, file);
		sprintf(data, "%f", tax_rate_corporate);	print_tag("tax_rate_corporate", data, file);
		sprintf(data, "%f", 0.0);	print_tag("tax_rate_vat", data, file);
		sprintf(data, "%d", total_households);	print_tag("outstanding_shares", data, file);
		sprintf(data, "%f", 0.0);	print_tag("current_dividend_per_share", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_revenues", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
	
		fputs("</xagent>\n", file);
	}






	
	num_start = num;
	int counter;
	int r_id = 1;
	int g_skill_level;
	int a_id=num_start;
	int a;
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
			printf("%s",data);
			}
			else if(column-1<0&& column+1 < num_regions_X)
			{
			
			sprintf(data,"{%d}",region_grid[column+1][row]);
			printf("%s",data);
			}
			else
			sprintf(data,"{}");
			
			print_tag("neighboring_region_ids", data, file);
	
		}	

		
		sprintf(data, "%f", 0);     	print_tag("wage", data, file);
		sprintf(data, "%f", 1.0); 	print_tag("wage_reservation", data, file);
		sprintf(data, "%d", -1);       	print_tag("employee_firm_id", data, file);
		sprintf(data, "%d", g_skill_level);   print_tag("general_skill", data, file);
		sprintf(data, "%f", specific_skills_of_household[column][row]);       print_tag("specific_skill", data, file);
		sprintf(data, "%d", 0);     	print_tag("on_the_job_search", data, file);
		sprintf(data, "%d", num_app);   print_tag("number_applications", data, file);
		sprintf(data, "%d", 0);       	print_tag("rationed", data, file);
		sprintf(data, "%f", 0.0);       print_tag("consumption_budget", data, file);
		sprintf(data, "%f", 0.0);       print_tag("weekly_budget", data, file);
		sprintf(data, "%f", 0.8);	print_tag("payment_account", data, file);
		sprintf(data, "%f", 0.0);	print_tag("mean_income", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_taxes", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_total_dividends", data, file);
		sprintf(data, "%f", tax_rate_hh_capital);	print_tag("tax_rate_hh_capital", data, file);
		sprintf(data, "%f", tax_rate_hh_labour);	print_tag("tax_rate_hh_labour", data, file);
		sprintf(data, "%f", 0.0);	print_tag("expenditures", data, file);
		sprintf(data, "%f", 0.0);	print_tag("received_dividends", data, file);
		

		for(l=1; l<=total_firms+1;l++)
		{
			
			if(l==1)
			{
			sprintf(data2, "{%d, 1}",l);
			}
			
			else 
			{
			sprintf(data1, "%s{%d, 1}",data2,l);
			sprintf(data2,"%s",data1);
			}
		}
		
		sprintf(data, "{%s}",data2);	print_tag("household_portfolio", data, file);

		sprintf(data, "{%f,%f,%f,%f}", 1.0,1.0,1.0,1.0);	
		print_tag("last_income", data, file);
		
		sprintf(data, "{{%d, %f, %f}{%d, %f, %f}}", 0, 0.0, 0.0,0,0.0,0.0);       
		print_tag("order_quantity", data, file);
		
		sprintf(data, "{{%d, %f}{%d, %f}}", 0, 0.0,0,0.0);       
		print_tag("received_quantity", data, file);

		sprintf(data, "%d", random_int(0,4));	
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
	for(num=num_start; num<total_Governments+num_start; num++)
	{
		fputs("<xagent>\n", file);
		fputs("<name>Government</name>\n", file);
		sprintf(data, "%d", num);     print_tag("id", data, file);
		sprintf(data, "%d",bank_id);	print_tag("bank_id", data, file);
		sprintf(data, "%f",payment_account_government);	print_tag("payment_account", data, file);
		sprintf(data, "%f",0.0);	print_tag("tax_revenues", data, file);
		sprintf(data, "%f",unemployment_benefit_payment);		print_tag("unemployment_benefit_payment", data, file);
		sprintf(data, "%f",0.0);		print_tag("total_unemployment_benefit_payment", data, file);
		sprintf(data, "%f",0.0);	print_tag("total_interest_payment", data, file);
		sprintf(data, "%f", 0.0);	print_tag("total_debt", data, file);
		sprintf(data, "%f", tax_rate_corporate);	print_tag("tax_rate_corporate", data, file);
		sprintf(data, "%f",tax_rate_hh_labour);	print_tag("tax_rate_hh_labour", data, file);
		sprintf(data, "%f",tax_rate_hh_capital);	print_tag("tax_rate_hh_capital", data, file);
		sprintf(data, "%f",0.0);	print_tag("tax_rate_vat", data, file);
		
		sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
	
		fputs("</xagent>\n", file);
	}


num_start = num;

	
	for(num=num_start; num<total_banks+num_start; num++)
	{
		fputs("<xagent>\n", file);
		fputs("<name>Bank</name>\n", file);
		sprintf(data, "%d", num);     print_tag("id", data, file);
		sprintf(data, "%d",random_int(1,num_regions));	print_tag("region_id", data, file);
		sprintf(data, "%d",gov_id);	print_tag("gov_id", data, file);
		
		
		for(l=1; l<num_start;l++)
		{
			
			if(l==1)
			{
			sprintf(data2, "{%d, 0.0}",l);
			}
			
			else 
			{
			sprintf(data1, "%s{%d, 0.0}",data2,l);
			sprintf(data2,"%s",data1);
			
			}
		}
		
		
		sprintf(data, "{%s}",data2);	print_tag("accounts", data, file);
		sprintf(data, "{}");			print_tag("loans_outstanding", data, file);

		sprintf(data, "%f",0.0);	print_tag("total_deposits", data, file);
		sprintf(data, "%f",0.0);	print_tag("amount_credit_offer", data, file);
		sprintf(data, "%f",0.0);	print_tag("total_loan_supply", data, file);
		sprintf(data, "%f",0.0);	print_tag("total_loan_demand", data, file);
		sprintf(data, "%f",0.0);	print_tag("payment_account", data, file);
		sprintf(data, "%d",0);	 print_tag("last_credit_id", data, file);
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
		if(i==1)
		{
		sprintf(data2, "{%d , %f, %f, %f}",i, 0.0,0.0,1.0);
		}
		else 
			{
			sprintf(data1, "%s{ %d , %f, %f, %f }",data2,i, 0.0,0.0,1.0);
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
		if(i==1)
		sprintf(data2, "{%d , %f}",i, 0.0);
		
		else 
			{
			
			sprintf(data1, "%s{ %d , %f}",data2,i, 0.0);
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
		sprintf(data, "%d", num);     print_tag("id", data, file);
		sprintf(data, "%d",random_int(1,num_regions));	print_tag("region_id", data, file);
		sprintf(data, "%d", num_regions);     print_tag("no_regions", data, file);
		
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

		sprintf(data, "{}");		print_tag("region_firm_data", data, file);
		sprintf(data, "{}");		print_tag("region_household_data", data, file);

		sprintf(data, "%d", 0);		print_tag("day_of_month_to_act", data, file);

		sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
	
		fputs("</xagent>\n", file);
	}





	
	fputs("</states>\n", file);
	
	/* Close the file */
	fclose(file);
	
	/* Exit successfully by returning zero to Operating System */
	return 0;
}
