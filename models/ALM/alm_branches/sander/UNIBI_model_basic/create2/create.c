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
	char data[10000000];
	char data2[10000];
	char data1[10000];
	int num;  /*used as an index to cycle through each agent*/
	int num_start;
	/*Defining the geographical space as a rectangular grid  */	
	
	int num_regions_X=2;/*spalten*/
	int num_regions_Y=1;/*zeile*/
	int num_regions = num_regions_X*num_regions_Y; /*number of regions*/
	
	/*defining skill distributions in regions*/

	double skilldistribution_1[5]={0.6,0.1,0.1,0.1,0.1};
	double skilldistribution_2[5]={0.1,0.1,0.6,0.1,0.1};
	double skilldistribution_3[5]={0.1,0.1,0.1,0.1,0.6};
	double skilldistribution_4[5]={0.2,0.2,0.2,0.2,0.2};

	

	/*This determines the local skill distribution. Use numbers 1 .. 4 (see above, skill distribution_X) to give a region a skill distribution. */
	int skills_in_regions[2][1]=

		
		{4,4};
	

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


		
	


	
	int total_households = 400;/*number of households in the economy*/
	int households_per_region = total_households/num_regions; /*should be 100 or 200 or 300..*/

	int total_firms  = 10; /*total_firms modulo num_regions should be 0*/
	int total_IGfirms = 1;
	int total_market_research = 1;
	int total_malls = num_regions;  /*one mall per region*/
	int num_app =  0.5*total_firms; /*number of applications per agent*/


	int years_statistics = 10;/*number of years used to smooth the production*/
	
	
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
		
		
		double wage_offer = random_double(1,1);
		fputs("<xagent>\n", file);
		fputs("<name>Firm</name>\n", file);
		sprintf(data, "%d", num);		print_tag("id", data, file);
		sprintf(data, "%d",region);    print_tag("region_id", data, file);
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

		sprintf(data, "%f", 1.0);		print_tag("technology", data, file);
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
		for( m=1; m<=total_malls;m++)
		{
			m_id = total_firms + total_households + m;
			if(m==1)
			{
			sprintf(data2, "{%d,%f,0.0}",m_id, 0.5*estimated_demand);
			}
			
			else 
			{
			sprintf(data1, "%s{%d,%f,0.0}",data2,m_id, 0.5*estimated_demand);
			sprintf(data2,"%s",data1);
			}
		}
		
		sprintf(data, "{%s}",data1);	print_tag("current_mall_stocks", data, file);	
		
		
		int qual = random_int(1,10);
		double qu = (double) qual;
		sprintf(data, "%f", 1.0);		print_tag("quality", data, file);
		
		
		sprintf(data, "%f", 2.0);		print_tag("price", data, file);
		sprintf(data, "%f", 2.0);		print_tag("price_last_month", data, file);


		double k = 8.0;
		int d;
		char data3[10000];
		char data4[10000];
		

		for( m=1; m<=total_malls;m++)
		{
			m_id = total_firms + total_households + m;

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

		sprintf(data, "{%s}",data1);	print_tag("malls_sales_statistics", data, file);
		
		
		sprintf(data, "%f", 0.0);	print_tag("production_quantity", data, file);
		sprintf(data, "%f", 0.0);	print_tag("planned_production_quantity", data, file);	
		sprintf(data, "%f", wage_offer);	print_tag("mean_wage", data, file);
		sprintf(data, "%f", 1.0);	print_tag("mean_specific_skills", data, file);
		sprintf(data, "%f", 10.0);	print_tag("capital_stock", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unit_costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("net_profit", data, file);
		sprintf(data, "%f", 0.0);	print_tag("revenue", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_revenue", data, file);
		sprintf(data, "%f", 0.0);	print_tag("out_of_stock_costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("earnings", data, file);
		sprintf(data, "%f", 0.0);	print_tag("account", data, file);
		
		sprintf(data, "{%f,%f,%f,%f,%f}", num_regions*k,num_regions*k,num_regions*k,num_regions*k,num_regions*k);	
		print_tag("last_planned_production_quantities", data, file);

		


		for( m=1; m<=total_malls;m++)
		{
			m_id = total_firms + total_households + m;
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
			m_id = total_firms + total_households + m;
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

		sprintf(data, "{%s}",data1);	print_tag("delivery_volume", data, file);


		for( m=1; m<=total_malls;m++)
		{
			m_id = total_firms + total_households + m;
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

		sprintf(data, "{%s}",data1);	print_tag("planned_delivery_volume", data, file);

		
		sprintf(data, "%d", 1);	print_tag("day_of_month_to_act", data, file);
		
		sprintf(data, "%f", 0.0);	print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);	print_tag("posy", data, file);
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
		sprintf(data, "%f", 1.0);       print_tag("specific_skill", data, file);
		sprintf(data, "%d", 0);     	print_tag("on_the_job_search", data, file);
		sprintf(data, "%d", num_app);   print_tag("number_applications", data, file);
		sprintf(data, "%d", 0);       	print_tag("rationed", data, file);
		sprintf(data, "%f", 0.0);       print_tag("budget", data, file);
		sprintf(data, "%f", 0.0);       print_tag("weekly_budget", data, file);
		sprintf(data, "%f", 0.0);	print_tag("savings", data, file);

		sprintf(data, "{%f,%f,%f,%f}", 2.0,2.0,2.0,2.0);	
		print_tag("last_income", data, file);
		
		sprintf(data, "{{%d, %f, %f}{%d, %f, %f}}", 0, 0.0, 0.0,0,0.0,0.0);       
		print_tag("order_quantity", data, file);
		
		sprintf(data, "{{%d, %f}{%d, %f}}", 0, 0.0,0,0.0);       
		print_tag("received_quantity", data, file);

		sprintf(data, "%d", random_int(0,4));	
		print_tag("day_of_week_to_act", data, file);

		sprintf(data, "%d", 4);		print_tag("week_of_month", data, file);
		sprintf(data, "%d", 1);		print_tag("day_of_month_to_act", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
		fputs("</xagent>\n", file);
		a_id++;	
		}
		
		r_id++;
		
		

	}


	num+=total_households;
	
	
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
		sprintf(data2, "{%d , %f, %f, %f}",i, 0.0,0.0,0.0);
		}
		else 
			{
			sprintf(data1, "%s{ %d , %f, %f, %f }",data2,i, 0.0,0.0,0.0);
			sprintf(data2,"%s",data1);
			}
		}
		
		sprintf(data, "{%s}",data1);	print_tag("current_stock", data, file);
		

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
		sprintf(data, "{%s}",data1);	print_tag("firm_revenues", data, file);
		
		sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
	
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
		
		sprintf(data, "%f",1.0);	print_tag("productivity", data, file);
		sprintf(data, "%d",10);		print_tag("innovation_probability", data, file);
		sprintf(data, "%f",0.05);	print_tag("productivity_progress", data, file);
		sprintf(data, "%f", 100.0);	print_tag("capital_good_price", data, file);
		sprintf(data, "%d", 1);		print_tag("day_of_month_to_act", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);       print_tag("posy", data, file);
	
		fputs("</xagent>\n", file);
	}




/* Market Research */
	num_start = num;
	for(num=num_start; num<total_market_research+num_start; num++)
	{
		fputs("<xagent>\n", file);
		fputs("<name>Market_Research</name>\n", file);
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
