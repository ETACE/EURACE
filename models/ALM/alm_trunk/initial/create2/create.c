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
	
	int num;  /*used as an index to cycle through each agent*/
	int num_start;
	int total_households = 400;
	int households_region_1 = 0.5*total_households;
	int households_region_2 = 0.5*total_households;
	//int num_1 = 0.1*total_households;
	//int num_2 = 0.2*total_households; 
	//int num_3 = 0.4*total_households; 
	//int num_4 = 0.2*total_households; 
	//int num_5 = 0.1*total_households;

	int num_1_region_1 = 0.05*households_region_1;
	int num_2_region_1 = 0.05*households_region_1; 
	int num_3_region_1 = 0.8*households_region_1; 
	int num_4_region_1 = 0.05*households_region_1; 
	int num_5_region_1 = 0.05*households_region_1;

	int num_1_region_2 = 0.05*households_region_2;
	int num_2_region_2 = 0.05*households_region_2; 
	int num_3_region_2 = 0.8*households_region_2; 
	int num_4_region_2 = 0.05*households_region_2; 
	int num_5_region_2 = 0.05*households_region_2;

	int total_IGfirms = 1;
	int total_malls = 2;
	
	int total_firms  = 10;
	

	int num_app =  0.5*total_firms;
	int g_skill;
	
	
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
		if(num%2 == 0)
		{
			region = 1;
		}
		else
		{
			region = 2;
		}
		
		double wage_offer = random_double(1,1);
		fputs("<xagent>\n", file);
		fputs("<name>Firm</name>\n", file);
		sprintf(data, "%d", num);		print_tag("id", data, file);
		sprintf(data, "%d",region);    print_tag("region_id", data, file);
		sprintf(data, "{}");			print_tag("employees", data, file);	
		sprintf(data, "%f",wage_offer);		print_tag("wage_offer", data, file);
		sprintf(data, "%f", 1.0);		print_tag("technology", data, file);
		sprintf(data, "%d", 0);			print_tag("no_employees", data, file);
		sprintf(data, "%d", 0);			print_tag("vacancies", data, file);
		sprintf(data, "%f", 0.0);		print_tag("needed_capital_stock", data, file);
		sprintf(data, "%f", 1.0);		print_tag("out_of_stock_costs", data, file);
		sprintf(data, "%d", 0);			print_tag("employees_needed", data, file);

		int i= total_firms + total_households;
		double estimated_demand = wage_offer*total_households/(total_firms*total_malls);
			

sprintf(data, "{{%d,%f, 0.0}{%d, %f, 0.0}}",i+1,0.5*estimated_demand,i+2,0.5*estimated_demand);
					
		print_tag("current_mall_stocks", data, file);
		
		
		int qual = random_int(1,10);
		double qu = (double) qual;
		sprintf(data, "%f", 1.0);		print_tag("quality", data, file);
		
		
		sprintf(data, "%f", 2.0);		print_tag("price", data, file);
		sprintf(data, "%f", 2.0);		print_tag("price_last_month", data, file);


		double k = 20.0;
		
		sprintf(data, "{{%d,1, %f}{%d,2, %f}{%d,3, %f}{%d,4, %f}{%d,5, %f}{%d,6, %f}{%d,7, %f}{%d,8,%f}{%d,9, %f}{%d,10,%f}{%d,1, %f}{%d,2, %f}{%d,3, %f}{%d,4, %f}{%d,5, %f}{%d,6, %f}{%d,7, %f}{%d,8, %f}{%d,9, %f}{%d,10, %f}}",i+1,k,i+1,k,i+1,k,i+1,k,i+1,k,i+1,k,i+1,k,i+1,k,i+1,k,i+1,k,i+2,k,i+2,k,i+2,k,i+2,k,i+2,k,i+2,k,i+2,k,i+2,k,i+2,k,i+2,k);			 			print_tag("malls_sales_statistics", data, file);
		




		
		sprintf(data, "%f", 0.0);	print_tag("production_quantity", data, file);
		sprintf(data, "%f", 0.0);	print_tag("planned_production_quantity", data, file);	
		sprintf(data, "%f", wage_offer);	print_tag("mean_wage", data, file);
		sprintf(data, "%f", 1.0);	print_tag("mean_specific_skills", data, file);
		sprintf(data, "%f", 0.0);	print_tag("capital_stock", data, file);
		sprintf(data, "%f", 0.0);	print_tag("unit_costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("net_profit", data, file);
		sprintf(data, "%f", 0.0);	print_tag("revenue", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_revenue", data, file);
		sprintf(data, "%f", 0.0);	print_tag("out_of_stock_costs", data, file);
		sprintf(data, "%f", 0.0);	print_tag("earnings", data, file);
		sprintf(data, "%f", 0.0);	print_tag("account", data, file);
		sprintf(data, "{%f,%f,%f,%f,%f}", 2*k,2*k,2*k,2*k,2*k);	print_tag("last_planned_production_quantities", data, file);

		sprintf(data, "{{%d, 0.0 ,0 , 0.0}{%d, 0.0, 0, 0.0}}",i+1,i+2);	
		print_tag("sold_quantities", data, file);

		sprintf(data, "%f", 0.0);	print_tag("total_sold_quantity", data, file);
		sprintf(data, "%f", 0.0);	print_tag("cum_total_sold_quantity", data, file);

		sprintf(data, "{{%d, 0.0, 1.0,1.0}{%d, 0.0,1.0,1.0}}",i+1,i+2);			 			print_tag("delivery_volume", data, file);
		sprintf(data, "{{%d, 0.0, 1.0,1.0}{%d, 0.0,1.0,1.0}}",i+1,i+2);			 			print_tag("planned_delivery_volume", data, file);
		
		//sprintf(data, "%d", 1);	print_tag("day_of_month_to_act", data, file);
		sprintf(data, "%d", 1);	print_tag("day_of_month_to_act", data, file);
		
		sprintf(data, "%f", 0.0);	print_tag("posx", data, file);
		sprintf(data, "%f", 0.0);	print_tag("posy", data, file);
		fputs("</xagent>\n", file);
	}


	num_start = num;
	for(num=num_start; num<total_households+num_start; num++)
	{
	   if(num < households_region_1+num_start)
	   {
			region = 1;

		/*Skill Group 1: general_skill = 1*/
		if(num<num_start+num_1_region_1)
		{
			g_skill = 1;
		}
		/*Skill Group 2: general_skill = 2*/
		if(num_start+num_1_region_1<=num && num<num_start+num_1_region_1+num_2_region_1)
		{
			g_skill =2;
		}
		/*Skill Group 3: general_skill = 3*/
		if(num_start+num_1_region_1+num_2_region_1<=num  && num<num_start+num_1_region_1+num_2_region_1+num_3_region_1)
		{
			g_skill =3;
		}
		/*Skill Group 4: general_skill = 4*/
		if(num_start+num_1_region_1+num_2_region_1+num_3_region_1<=num && num<num_start+num_1_region_1+num_2_region_1+num_3_region_1+num_4_region_1)
		{
			g_skill =4;
		}
		/*Skill Group 5: general_skill = 5*/
		if(num_start+num_1_region_1+num_2_region_1+num_3_region_1+num_4_region_1<=num && num<num_start+num_1_region_1+num_2_region_1+num_3_region_1+num_4_region_1+num_5_region_1)
		{
			g_skill =5;
		}
	   }
	   else
	   {
			region = 2;

		/*Skill Group 1: general_skill = 1*/
		if(num<(num_start+households_region_1+num_1_region_2))
		{
			g_skill =1;
		}
		/*Skill Group 2: general_skill = 2*/
		if(num_start+households_region_1+num_1_region_2<=num && num<num_start+households_region_1+num_1_region_2+num_2_region_2)
		{
			g_skill =2;
		}
		/*Skill Group 3: general_skill = 3*/
		if(num_start+households_region_1+num_1_region_2+num_2_region_2<=num  && num<num_start+households_region_1+num_1_region_2+num_2_region_2+num_3_region_2)
		{
			g_skill =3;
		}
		/*Skill Group 4: general_skill = 4*/
		if(num_start+households_region_1+num_1_region_2+num_2_region_2+num_3_region_2<=num && num<num_start+households_region_1+num_1_region_2+num_2_region_2+num_3_region_2+num_4_region_2)
		{
			g_skill =4;
		}
		/*Skill Group 5: general_skill = 5*/
		if(num_start+households_region_1+num_1_region_2+num_2_region_2+num_3_region_2+num_4_region_2<=num && num<num_start+households_region_1+num_1_region_2+num_2_region_2+num_3_region_2+num_4_region_2+num_5_region_2)
		{
			g_skill =5;
		}
	   }

		
		fputs("<xagent>\n", file);
		fputs("<name>Household</name>\n", file);
		sprintf(data, "%d", num);     	print_tag("id", data, file);
		sprintf(data, "%d",region);     print_tag("region_id", data, file);
		sprintf(data, "%f", 0);     	print_tag("wage", data, file);
		sprintf(data, "%f", 1.0); 	print_tag("wage_reservation", data, file);
		sprintf(data, "%d", -1);       	print_tag("employee_firm_id", data, file);
		sprintf(data, "%d", g_skill);   print_tag("general_skill", data, file);
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
			
	}
	
	
	/* Mall */

	char data2[10000];
	char data1[10000];
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
		//printf("HAlll");
		}
		else 
			{
			
			sprintf(data1, "%s{ %d , %f, %f, %f }",data2,i, 0.0,0.0,0.0);
			sprintf(data2,"%s",data1);
		
	printf("data2: %s\n",data2);
		//printf("data1: %s\n",data1);
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
		sprintf(data, "%d",random_int(1,2));	print_tag("region_id", data, file);
		
		sprintf(data, "%f",1.0);	print_tag("productivity", data, file);
		sprintf(data, "%d",10);		print_tag("innovation_probability", data, file);
		sprintf(data, "%f",0.05);	print_tag("productivity_progress", data, file);
		sprintf(data, "%f", 1.0);	print_tag("capital_good_price", data, file);
		sprintf(data, "%d", 1);		print_tag("day_of_month_to_act", data, file);
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
