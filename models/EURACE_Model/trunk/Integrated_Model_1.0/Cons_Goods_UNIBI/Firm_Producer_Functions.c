#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
#include "Mall_aux_header.h"

/* Library functions */

/** \fn Firm_calc_input_demands_2(), auxiliary function
 * \brief Firms recalculate the labor demand and the demand for capital goods
 * such that these can be financed with the external finances obtained.
 * This function is iterated multiple times by the function Firm_calc_production_quantity_2
 * in order to find the maximal possible production_quantity that can be financed.
 */


/************************************ Firm agent functions ************************************/


int Firm_calc_input_demands_2()
{
 
    double temp_labour_demand;
    double temp_capital_demand;
    double max_cap_increase;
    
    max_cap_increase = 0.05;
    
        
        /*Calculate labor demand and needed capital goods.
        Complementarity between specific skills and productivity*/
        
        /*Specific skills are limiting factor*/
     
             if(MEAN_SPECIFIC_SKILLS < TECHNOLOGY)
        {
    
            temp_capital_demand = PLANNED_PRODUCTION_QUANTITY * 
            (pow((BETA*MEAN_WAGE)/((ACTUAL_CAP_PRICE*AVG_LOAN_RATE/12)*ALPHA),ALPHA)/
            MEAN_SPECIFIC_SKILLS);
            
            /*Smoothing of capital good demand*/
            
            if (temp_capital_demand < TOTAL_UNITS_CAPITAL_STOCK * (1 - DEPRECIATION_RATE))
               { NEEDED_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK * (1 - DEPRECIATION_RATE);}
               /* This is the minimum capital that can be used without investments and should be used because its cost is always paid*/
               else if (temp_capital_demand > (1 + max_cap_increase)*TOTAL_UNITS_CAPITAL_STOCK)
               {NEEDED_CAPITAL_STOCK = (1 + max_cap_increase)*TOTAL_UNITS_CAPITAL_STOCK;}
               /*Rule setting the maximum capital increase, given the supposed technological constraint*/
               else
               {NEEDED_CAPITAL_STOCK = temp_capital_demand;}
            
                
        temp_labour_demand = pow(PLANNED_PRODUCTION_QUANTITY /
        (pow(NEEDED_CAPITAL_STOCK,BETA)*MEAN_SPECIFIC_SKILLS),1/ALPHA);
 
        }
        /*Technological productivity is limiting factor*/
        else
        {
            temp_capital_demand = PLANNED_PRODUCTION_QUANTITY * 
            (pow((BETA*MEAN_WAGE)/((ACTUAL_CAP_PRICE*AVG_LOAN_RATE/12)*ALPHA),ALPHA)/
            TECHNOLOGY);
            
                /*Smoothing of capital good demand*/
            if (temp_capital_demand < TOTAL_UNITS_CAPITAL_STOCK * (1 - DEPRECIATION_RATE))
               { NEEDED_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK * (1 - DEPRECIATION_RATE);}
               /* This is the minimum capital that can be used without investments and should be used because its cost is always paid*/
               else if (temp_capital_demand > (1 + max_cap_increase)*TOTAL_UNITS_CAPITAL_STOCK)
               {NEEDED_CAPITAL_STOCK = (1 + max_cap_increase)*TOTAL_UNITS_CAPITAL_STOCK;}
               /*Rule setting the maximum capital increase, given the supposed technological constraint*/
               else
               {NEEDED_CAPITAL_STOCK = temp_capital_demand;}            
            
        temp_labour_demand = pow(PLANNED_PRODUCTION_QUANTITY /
        (pow(NEEDED_CAPITAL_STOCK,BETA)*TECHNOLOGY),1/ALPHA);
        }
        
        
         if(NEEDED_CAPITAL_STOCK > TOTAL_UNITS_CAPITAL_STOCK)
        {       
            if(temp_labour_demand < 1 && temp_labour_demand > 0)
            {
                EMPLOYEES_NEEDED = 1;
            }else
            {
                EMPLOYEES_NEEDED = (int) ceil(temp_labour_demand);
            }
        }
        else/*... if capital stock is higher than the needed one..*/
        {
            /*Recalculation of the labor demand*/
            if(MEAN_SPECIFIC_SKILLS > TECHNOLOGY)
            {
                EMPLOYEES_NEEDED = (int) ceil((pow(PLANNED_PRODUCTION_QUANTITY/
                (TECHNOLOGY*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA)),1/ALPHA)));
            }
            else
            {
                EMPLOYEES_NEEDED = (int) ceil((pow(PLANNED_PRODUCTION_QUANTITY/
                (MEAN_SPECIFIC_SKILLS*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA)),1/ALPHA)));
            }
        }
        /*This calculates the needed capital investments*/
    
        DEMAND_CAPITAL_STOCK = NEEDED_CAPITAL_STOCK - TOTAL_UNITS_CAPITAL_STOCK;
        if(DEMAND_CAPITAL_STOCK<0)
        {//printf("\n Firm_calc_input_demands ID: %d DEMAND_CAPITAL_STOCK = %f",ID, DEMAND_CAPITAL_STOCK);
            DEMAND_CAPITAL_STOCK=0;} 
        
        /*This computes the financial needings for production*/
        PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*MEAN_WAGE + DEMAND_CAPITAL_STOCK*ACTUAL_CAP_PRICE;
    
    #ifdef _DEBUG_MODE    
  
    #endif
    
    return 0;
}   



int Firm_set_quantities_zero()
{

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG)
    {
        printf("\n Firm_set_quantities_zero ID: %d",ID);
        printf("\n\t DAY_OF_MONTH_TO_ACT: %d",DAY_OF_MONTH_TO_ACT);
        getchar();
    }
    #endif
                        
    PLANNED_PRODUCTION_QUANTITY = 0;
    PRODUCTION_QUANTITY = 0;

    TOTAL_INTEREST_PAYMENT=0.0;
    TOTAL_DEBT_INSTALLMENT_PAYMENT=0.0;

    return 0;
}


/********************************Firm Role Consumption Goods marke*******************************/


/** \fn Firm_calc_production_quantity()
 * \brief Firm calculate the intended production volume depending on the current stocks in the malls*/
int Firm_calc_production_quantity()
{

    double production_volume = 0;
    double prod_vol;
    int i,j,k;
    FILE *file1;
     char *filename;    
    double  mall_sales_total = 0.0;
    double stock_crit_tot = 0.0;
    double stock_corrent_tot = 0.0;
    
    double regressor, intercept, variance;
    
    double sum_1, sum_2;

    //Reset the counters at the start of month
    CUM_TOTAL_SOLD_QUANTITY = 0.0;
    CUM_REVENUE = 0.0;  
   
    //Delete the LINEAR_REGRESSION_ESTIMATORS array
    
    
    //New forcasting rule added on August, 24th
   

    
    //Compute the estimatores for each mall
    
    for(i=0; i< MALLS_SALES_STATISTICS.size; i++)
    {
    	sum_1=0;
    	sum_2=0;
    	
    	for (j=0;j<FIRM_PLANNING_HORIZON; j++)
    	    	{
    	    	sum_1+= (FIRM_PLANNING_HORIZON + 1 - MALLS_SALES_STATISTICS.array[i].sales.array[j].period)* MALLS_SALES_STATISTICS.array[i].sales.array[j].sales;

    	    	sum_2+=  MALLS_SALES_STATISTICS.array[i].sales.array[j].sales;
                         
    	    	}
    	    	
  		mall_sales_total += MALLS_SALES_STATISTICS.array[i].sales.array[FIRM_PLANNING_HORIZON-1].sales;;    	
    
    	regressor = (FIRM_PLANNING_HORIZON * sum_1 - 0.5*FIRM_PLANNING_HORIZON*(FIRM_PLANNING_HORIZON+1)*sum_2)/
        		(1/6.0*pow(FIRM_PLANNING_HORIZON,2)*(FIRM_PLANNING_HORIZON+1)*
        		(2*FIRM_PLANNING_HORIZON+1)-1/4.0*(pow(FIRM_PLANNING_HORIZON,2)*pow((FIRM_PLANNING_HORIZON+1),2)));

    	intercept =  1/(1.0*FIRM_PLANNING_HORIZON)*sum_2 - 0.5*regressor*(FIRM_PLANNING_HORIZON+1);
    	
    	variance = 0;
    	
    	  for(j=0; j< FIRM_PLANNING_HORIZON; j++)
    	    {
    		  variance+= pow(MALLS_SALES_STATISTICS.array[i].sales.array[j].sales-(intercept+ 
    				 (FIRM_PLANNING_HORIZON + 1 - MALLS_SALES_STATISTICS.array[i].sales.array[j].period)* regressor),2)
    				  /(FIRM_PLANNING_HORIZON-1);
    	    }


    		
    	  for(k=0; k< LINEAR_REGRESSION_ESTIMATORS.size ;k++)
    		   {

	
    		  if(MALLS_SALES_STATISTICS.array[i].mall_id==LINEAR_REGRESSION_ESTIMATORS.array[k].mall_id)
    		  {

				
    			  LINEAR_REGRESSION_ESTIMATORS.array[k].intercept=intercept;
    			  LINEAR_REGRESSION_ESTIMATORS.array[k].regressor=regressor;
    			  LINEAR_REGRESSION_ESTIMATORS.array[k].variance=variance;
    		  }
    	  }
     
    }
         /*Setting the critical values*/
    
    for(int i = 0; i < CURRENT_MALL_STOCKS.size;i++)
        {
        
            for(int j = 0; j < LINEAR_REGRESSION_ESTIMATORS.size;j++)
            {
                if(CURRENT_MALL_STOCKS.array[i].mall_id==
                	LINEAR_REGRESSION_ESTIMATORS.array[j].mall_id)
                {
                	 CURRENT_MALL_STOCKS.array[i].critical_stock = 
                		 LINEAR_REGRESSION_ESTIMATORS.array[j].intercept + (1+FIRM_PLANNING_HORIZON)*LINEAR_REGRESSION_ESTIMATORS.array[j].regressor + QUANTIL_NORMAL_DISTRIBUTION*pow(LINEAR_REGRESSION_ESTIMATORS.array[j].variance,0.5)  ;
                     stock_crit_tot += CURRENT_MALL_STOCKS.array[i].critical_stock;
    
                }
                  
            }
            
        }

        /*checking whether or not the current mall stocks are below the critical values         
         * (sS-Rule) If this is the case refill the stock up to the max stock */
        for(int i = 0; i < CURRENT_MALL_STOCKS.size; i++)
        {
           
            stock_corrent_tot += CURRENT_MALL_STOCKS.array[i].current_stock; 
            if(CURRENT_MALL_STOCKS.array[i].current_stock <= 
            CURRENT_MALL_STOCKS.array[i].critical_stock)    
            {
                /*If stocks are left at the beginning of a new production cycle 
                 * then firms produce the difference between these stocks and the 
                 * critical stock for this mall*/
              
                    prod_vol = CURRENT_MALL_STOCKS.array[i].critical_stock - CURRENT_MALL_STOCKS.array[i].current_stock;
    
                    PLANNED_DELIVERY_VOLUME.array[i].mall_id = 
                    CURRENT_MALL_STOCKS.array[i].mall_id;

                    PLANNED_DELIVERY_VOLUME.array[i].quantity  = prod_vol;
                                
                production_volume = production_volume + prod_vol;
                
            }
            else/*If  stocks are higher than the critical value no production takes place for this mall*/
            {
                PLANNED_DELIVERY_VOLUME.array[i].mall_id= 
                CURRENT_MALL_STOCKS.array[i].mall_id;

                PLANNED_DELIVERY_VOLUME.array[i].quantity= 0.0;
            }

        }

        /*Smoothing of production quantity in order to avoid high fluctuations*/
        double mean_production_quantity=0;
        for(int i = 0; i < LAST_PLANNED_PRODUCTION_QUANTITIES.size; i++)
        {
            mean_production_quantity += LAST_PLANNED_PRODUCTION_QUANTITIES.array[i];
         }

        mean_production_quantity = mean_production_quantity/
        LAST_PLANNED_PRODUCTION_QUANTITIES.size;
    
        PLANNED_PRODUCTION_QUANTITY = LAMBDA*production_volume + (1-LAMBDA)*mean_production_quantity;
        
        //Set planned production value that is retained in memory during the month:
        PLANNED_OUTPUT = PLANNED_PRODUCTION_QUANTITY; 
        
        #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
        {
            printf("\n Firm_calc_production_quantity ID: %d",ID);
            printf("\n\t PLANNED_PRODUCTION_QUANTITY: %f",PLANNED_PRODUCTION_QUANTITY);
            getchar();
        }
        #endif
        
        if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Firm_calc_production_quantity.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f %f",DAY,ID,mall_sales_total,stock_corrent_tot,stock_crit_tot);
            fprintf(file1," %f %f",production_volume,mean_production_quantity);
            fprintf(file1," %f %d",PLANNED_PRODUCTION_QUANTITY,REGION_ID);
            fclose(file1);
            free(filename);
        }  
        
        //printf("In calculate production: Firm %d PLANNED_PRODUCTION_QUANTITY %f\n", ID, PLANNED_PRODUCTION_QUANTITY);
        //printf("In calculate production: Firm %d PLANNED_OUTPUT %f\n", ID, PLANNED_OUTPUT);
        
    return 0;

}

int Firm_calc_avg_loan_rate()
{
         FILE *file1;
         char *filename;  
     
 int i;
 double weighted_loan_value;
 double loan_values_sum;
 /*double tmp_total_debt;*/
 
 weighted_loan_value = 0.0;
 loan_values_sum = 0.0;
 
 for (i=LOANS.size-1; i>-1; i--)
 {
 weighted_loan_value += LOANS.array[i].loan_value*LOANS.array[i].interest_rate;
 loan_values_sum += LOANS.array[i].loan_value; 
 /*tmp_total_debt += LOANS.array[i].loan_value*/;
 } 

 AVG_LOAN_RATE = weighted_loan_value/TOTAL_DEBT;
 
         if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Firm_calc_avg_loan_rate.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f %f",DAY,ID, AVG_LOAN_RATE,TOTAL_DEBT,loan_values_sum);
            fclose(file1);
            free(filename);
        } 
        
 return 0;
}   
/** \fn Firm_calc_input_demands()
 * \brief Firms calculate the labor demand and the demand for capital goods*/
int Firm_calc_input_demands()
{
 
     FILE *file1;
     char *filename;    
     
    double temp_labour_demand;
    double temp_capital_demand;
    double total_units_capital_stock_old, max_cap_increase;
    
    
    if(DAY >= TRANSITION_PHASE)
        {
    
        START_PRODUCTIVITY_MESSAGE_LOOP
            /*Update of the actual capital good information*/
            TECHNOLOGICAL_FRONTIER = productivity_message->cap_productivity;
            ACTUAL_CAP_PRICE = productivity_message->cap_good_price;
        
        FINISH_PRODUCTIVITY_MESSAGE_LOOP
        
        /*Calculate labor demand and needed capital goods. 
         * Complementarity between specific skills and productivity*/
        
        }
        Firm_calc_avg_loan_rate();
        max_cap_increase = 0.05;
        
        /*Specific skills are limiting factor*/
        if(MEAN_SPECIFIC_SKILLS < TECHNOLOGY)
        {
    
            temp_capital_demand = PLANNED_PRODUCTION_QUANTITY * 
            (pow((BETA*MEAN_WAGE)/((ACTUAL_CAP_PRICE*AVG_LOAN_RATE/12)*ALPHA),ALPHA)/
            MEAN_SPECIFIC_SKILLS);
            
            /*Smoothing of capital good demand*/
            
            if (temp_capital_demand < TOTAL_UNITS_CAPITAL_STOCK * (1 - DEPRECIATION_RATE))
               { NEEDED_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK * (1 - DEPRECIATION_RATE);}
               /* This is the minimum capital that can be used without investments and should be used because its cost is always paid*/
               else if (temp_capital_demand > (1 + max_cap_increase)*TOTAL_UNITS_CAPITAL_STOCK)
               {NEEDED_CAPITAL_STOCK = (1 + max_cap_increase)*TOTAL_UNITS_CAPITAL_STOCK;}
               /*Rule setting the maximum capital increase, given the supposed technological constraint*/
               else
               {NEEDED_CAPITAL_STOCK = temp_capital_demand;}
            
                
        temp_labour_demand = pow(PLANNED_PRODUCTION_QUANTITY /
        (pow(NEEDED_CAPITAL_STOCK,BETA)*MEAN_SPECIFIC_SKILLS),1/ALPHA);
 
        }
        /*Technological productivity is limiting factor*/
        else
        {
            temp_capital_demand = PLANNED_PRODUCTION_QUANTITY * 
            (pow((BETA*MEAN_WAGE)/((ACTUAL_CAP_PRICE*AVG_LOAN_RATE/12)*ALPHA),ALPHA)/
            TECHNOLOGY);
            
                /*Smoothing of capital good demand*/
            if (temp_capital_demand < TOTAL_UNITS_CAPITAL_STOCK * (1 - DEPRECIATION_RATE))
               { NEEDED_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK * (1 - DEPRECIATION_RATE);}
               /* This is the minimum capital that can be used without investments and should be used because its cost is always paid*/
               else if (temp_capital_demand > (1 + max_cap_increase)*TOTAL_UNITS_CAPITAL_STOCK)
               {NEEDED_CAPITAL_STOCK = (1 + max_cap_increase)*TOTAL_UNITS_CAPITAL_STOCK;}
               /*Rule setting the maximum capital increase, given the supposed technological constraint*/
               else
               {NEEDED_CAPITAL_STOCK = temp_capital_demand;}            
            
        temp_labour_demand = pow(PLANNED_PRODUCTION_QUANTITY /
        (pow(NEEDED_CAPITAL_STOCK,BETA)*TECHNOLOGY),1/ALPHA);
        }
        
        
        /*Compute new capital stock, in units and in value*/
        
        
        /*Depriciation of the old capital stock.
        If additional capital goods are needed...*/
                   
        total_units_capital_stock_old = TOTAL_UNITS_CAPITAL_STOCK;   
        TOTAL_CAPITAL_DEPRECIATION_UNITS = TOTAL_UNITS_CAPITAL_STOCK*DEPRECIATION_RATE;
        TOTAL_CAPITAL_DEPRECIATION_VALUE= TOTAL_VALUE_CAPITAL_STOCK*DEPRECIATION_RATE;
        TOTAL_VALUE_CAPITAL_STOCK *=(1-DEPRECIATION_RATE);
        TOTAL_UNITS_CAPITAL_STOCK -= TOTAL_CAPITAL_DEPRECIATION_UNITS;
    

        if(NEEDED_CAPITAL_STOCK > TOTAL_UNITS_CAPITAL_STOCK)
        {       
            if(temp_labour_demand < 1 && temp_labour_demand > 0)
            {
                EMPLOYEES_NEEDED = 1;
            }else
            {
                EMPLOYEES_NEEDED = (int) ceil(temp_labour_demand);
            }
        }
        else/*... if capital stock is higher than the needed one..*/
        {
            /*Recalculation of the labor demand*/
            if(MEAN_SPECIFIC_SKILLS > TECHNOLOGY)
            {
                EMPLOYEES_NEEDED = (int) ceil((pow(PLANNED_PRODUCTION_QUANTITY/
                (TECHNOLOGY*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA)),1/ALPHA)));
            }
            else
            {
                EMPLOYEES_NEEDED = (int) ceil((pow(PLANNED_PRODUCTION_QUANTITY/
                (MEAN_SPECIFIC_SKILLS*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA)),1/ALPHA)));
            }
        }
        /*This calculates the needed capital investments*/
    
        DEMAND_CAPITAL_STOCK = NEEDED_CAPITAL_STOCK - TOTAL_UNITS_CAPITAL_STOCK;
        if(DEMAND_CAPITAL_STOCK<0)
        {//printf("\n Firm_calc_input_demands ID: %d DEMAND_CAPITAL_STOCK = %f",ID, DEMAND_CAPITAL_STOCK);
            DEMAND_CAPITAL_STOCK=0;} 
        /*This computes the financial needings for production*/

        
        PLANNED_VALUE_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK /max(NEEDED_CAPITAL_STOCK,TOTAL_UNITS_CAPITAL_STOCK)*TOTAL_VALUE_CAPITAL_STOCK + DEMAND_CAPITAL_STOCK/max(NEEDED_CAPITAL_STOCK,TOTAL_UNITS_CAPITAL_STOCK)*ACTUAL_CAP_PRICE;
        
        PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*MEAN_WAGE + DEMAND_CAPITAL_STOCK*ACTUAL_CAP_PRICE;

        #ifdef _DEBUG_MODE
        if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
        { 
            printf("\n Firm_calc_input_demands ID: %d",ID);
            printf("\n\t EMPLOYEES_NEEDED: %d NEEDED_CAPITAL_STOCK: %f",EMPLOYEES_NEEDED,NEEDED_CAPITAL_STOCK);
            printf("\n\t TOTAL_UNITS_CAPITAL_STOCK: %f DEMAND_CAPITAL_STOCK: %f",TOTAL_UNITS_CAPITAL_STOCK,DEMAND_CAPITAL_STOCK);
            printf("\n\t PLANNED_VALUE_CAPITAL_STOCK: %f PLANNED_PRODUCTION_COSTS: %f",PLANNED_VALUE_CAPITAL_STOCK,PLANNED_PRODUCTION_COSTS);
            getchar();
        }
        #endif
        
          if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Firm_calc_input_demands.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %d %f %f %f %f %f %f",DAY,ID,EMPLOYEES_NEEDED,temp_labour_demand,NEEDED_CAPITAL_STOCK,temp_capital_demand,DEMAND_CAPITAL_STOCK,total_units_capital_stock_old,TOTAL_UNITS_CAPITAL_STOCK);
            fclose(file1);
            free(filename);
        }  

        //printf("Firm: %d  Labour: %d  Capital: %f  PLANNED_PROD_COSTS: %f\n", ID,EMPLOYEES_NEEDED,NEEDED_CAPITAL_STOCK,PLANNED_PRODUCTION_COSTS);
    
    return 0;
}


/* GENUA NOTE: This needs to be updated with the new style of checking FINANCIAL_NEEDS
 * See file: Firm_Financial_Management
 */

/** \fn Firm_calc_production_quantity_2()
 * \brief Firms iterate over the planned production quantity decreasing it incrementally,
 * such that the corresponding labor demand and capital demand can be financed by the actually obtained financial resources.
 * If PLANNED_PRODUCTION_COSTS <= PAYMENT_ACCOUNT this function does nothing.
 */
int Firm_calc_production_quantity_2()
{
    //printf("Firm_calc_production_quantity_2() ID: %d\n",ID);

    double decrement;
    double diff;
    diff = PLANNED_PRODUCTION_QUANTITY;
    FILE *file1;
     char *filename;    

    //Here we set a fraction of the planned production quantity
    decrement = ADAPTION_PRODUCTION_VOLUME_DUE_TO_INSUFFICIENT_FINANCES*PLANNED_PRODUCTION_QUANTITY;
    
        
        //if( FINANCIAL_RESOURCES_FOR_PRODUCTION>0.0)
        if( PAYMENT_ACCOUNT>0.0)
        {
            //while (PLANNED_PRODUCTION_COSTS > FINANCIAL_RESOURCES_FOR_PRODUCTION)
            while (PLANNED_PRODUCTION_COSTS > PAYMENT_ACCOUNT)
            {
                PLANNED_PRODUCTION_QUANTITY -= decrement;
                Firm_calc_input_demands_2();
            }
        }else
        {
            PLANNED_PRODUCTION_QUANTITY=0.0;
            Firm_calc_input_demands_2();
        }
    
    //printf("Labour: %d  Capital: %f  PLANNED_PROD_COSTS: %f\n", EMPLOYEES_NEEDED,NEEDED_CAPITAL_STOCK,PLANNED_PRODUCTION_COSTS);
    
        //Compute the diff
        diff -= PLANNED_PRODUCTION_QUANTITY;
        
        //Set planned production value that is retained in memory during the month:
        PLANNED_OUTPUT = PLANNED_PRODUCTION_QUANTITY;

        //printf("In calculate production 2: Firm %d PLANNED_PRODUCTION_QUANTITY %.2f (-%.2f)\n", ID, PLANNED_PRODUCTION_QUANTITY, diff);
        //printf("In calculate production 2: Firm %d PLANNED_OUTPUT %.2f (-%.2f)\n", ID, PLANNED_OUTPUT, diff);
        
        if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Firm_calc_production_quantity_2.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %d",DAY,ID,PLANNED_PRODUCTION_QUANTITY,REGION_ID);
            fclose(file1);
            free(filename);
        }  
        
    return 0;
}

/** \fn Firm_send_capital_demand()
 * \brief Firm sends demand for capital to the capital goods market. */
int Firm_send_capital_demand()
{
    
    if ( (NEEDED_CAPITAL_STOCK > 0) && (NEEDED_CAPITAL_STOCK > TOTAL_UNITS_CAPITAL_STOCK))
        {                   
            
            add_capital_good_request_message(ID,DEMAND_CAPITAL_STOCK);      
        }
    
    return 0;
}


int Firm_receive_capital_goods()
{
        FILE *file1;
        char *filename;
        double capital_good_price = 0.0;
        double capital_good_delivery_volume = 0.0;
        
        CAPITAL_COSTS = 0.0;
        
        START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
        
        /*Determine the weighted average productivity of the total capital stock*/
    
        /*Update of productivity*/
               TECHNOLOGY = TOTAL_UNITS_CAPITAL_STOCK /    (TOTAL_UNITS_CAPITAL_STOCK +capital_good_delivery_message->capital_good_delivery_volume)
                *TECHNOLOGY + 
                capital_good_delivery_message->capital_good_delivery_volume/
                (TOTAL_UNITS_CAPITAL_STOCK + 
                capital_good_delivery_message->capital_good_delivery_volume)
                *TECHNOLOGICAL_FRONTIER;
        /*Update of current value of capital stock*/
 
                TOTAL_VALUE_CAPITAL_STOCK =
                TOTAL_VALUE_CAPITAL_STOCK + capital_good_delivery_message->capital_good_delivery_volume
                *ACTUAL_CAP_PRICE;              

                /*Adding the new capital*/
                TOTAL_UNITS_CAPITAL_STOCK += capital_good_delivery_message
                ->capital_good_delivery_volume;

        /*Computing the capital bill*/
        CAPITAL_COSTS += capital_good_delivery_message
        ->capital_good_delivery_volume* ACTUAL_CAP_PRICE;

        
        capital_good_price = capital_good_delivery_message->capital_good_price;
        capital_good_delivery_volume = capital_good_delivery_message->capital_good_delivery_volume;
        
    FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP

        if(CAPITAL_COSTS>0.0)
        {
        add_financing_capital(&CAPITAL_FINANCING,CAPITAL_COSTS/CONST_INSTALLMENT_PERIODS,CONST_INSTALLMENT_PERIODS);
        }

          if (PRINT_DEBUG_FILE_EXP1)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/firms_capital_goods.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f %f",DAY,ID,TOTAL_UNITS_CAPITAL_STOCK,capital_good_delivery_volume,capital_good_price);
            fclose(file1);
            free(filename);
        }

return 0;
}





int Firm_execute_production()
{
    double diff;
    FILE *file1;
     char *filename;    
    
    /* This determines the realized production volume*/
    if(PLANNED_PRODUCTION_QUANTITY != 0)
    {
    
        if(MEAN_SPECIFIC_SKILLS < TECHNOLOGY)
        {   
        
            PRODUCTION_QUANTITY = MEAN_SPECIFIC_SKILLS * 
            pow(NO_EMPLOYEES,ALPHA)*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA); 
        }
        else 
        {
            PRODUCTION_QUANTITY = TECHNOLOGY * 
            pow(NO_EMPLOYEES,ALPHA)*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA); 
        }

    }
    else
    {
        PRODUCTION_QUANTITY=0.0;
    }
    
    //compute diff between actual and planned
    diff = PRODUCTION_QUANTITY - PLANNED_PRODUCTION_QUANTITY;
    
    //Set actual production value that is retained  in memory during the month:
    OUTPUT = PRODUCTION_QUANTITY;

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_EXP1 || PRINT_DEBUG)
    {
        printf("\n\n Firm_execute_production ID: %d",ID);
        printf("\n\t PLANNED_PRODUCTION_QUANTITY: %f OUTPUT: %f",PLANNED_PRODUCTION_QUANTITY,OUTPUT);
        getchar();                         
    }
    #endif
        
    TOTAL_SUPPLY = TOTAL_UNITS_LOCAL_INVENTORY + OUTPUT;
    
    //printf("In Execute production: Firm %d PRODUCTION_QUANTITY: %.2f (%.2f) \n", ID, PRODUCTION_QUANTITY, diff);
    //printf("In Execute production: Firm %d OUTPUT: %.2f (%.2f)\n", ID, OUTPUT, diff);
    
    if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Firm_execute_production.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %d %f %f %f %d",DAY,ID,NO_EMPLOYEES,OUTPUT,TOTAL_UNITS_LOCAL_INVENTORY,TOTAL_SUPPLY,REGION_ID);
            fclose(file1);
            free(filename);
        }  

return 0;
}



/** \fn Firm_calc_pay_costs()
 * \brief In this function the firm receives the purchased investment goods and pays the goods and  the wage bill. Additionally, the new mean wage and tthe new average specific skill level is     computed. */
int Firm_calc_pay_costs()
{
     FILE *file1;
     char *filename;    
   // int i;
    
        /*Pay capital costs*/

        add_pay_capital_goods_message(ID,CAPITAL_COSTS);

        LABOUR_COSTS=0.0;

        for(int i=0; i<EMPLOYEES.size;i++)
        {
            LABOUR_COSTS += EMPLOYEES.array[i].wage;

            add_wage_payment_message(ID,
            EMPLOYEES.array[i].id,EMPLOYEES.array[i].wage,
            TECHNOLOGY,MEAN_SPECIFIC_SKILLS);

            
        }
    /*Calculate the unit costs and total costs*/
        if(PRODUCTION_QUANTITY!=0 )
        {
            
        /*    CALC_CAPITAL_COSTS = 0;
        for( i = 0; i<CAPITAL_FINANCING.size;i++) 
            {
                if(CAPITAL_FINANCING.array[i].nr_periods_before_repayment==0)
                {
                    remove_financing_capital(&CAPITAL_FINANCING,i);
                    i--;
                }else
                {
                CAPITAL_FINANCING.array[i].nr_periods_before_repayment--;
                CALC_CAPITAL_COSTS+= CAPITAL_FINANCING.array[i].financing_per_month;
                }
                

            } */

            CALC_CAPITAL_COSTS = DEPRECIATION_RATE*ACTUAL_CAP_PRICE*TOTAL_UNITS_CAPITAL_STOCK;
        
            UNIT_COSTS=(LABOUR_COSTS + CALC_CAPITAL_COSTS + TOTAL_INTEREST_PAYMENT) / PRODUCTION_QUANTITY;
    
            
            PRICE_LAST_MONTH = PRICE;
            PRICE = UNIT_COSTS*(1 + MARK_UP);
            
            if (PRINT_DEBUG_FILE_EXP1)
             {
             filename = malloc(40*sizeof(char));
             filename[0]=0;
             strcpy(filename, "its/firms_pricing.txt");      
             file1 = fopen(filename,"a");
             fprintf(file1,"\n %d %d %f %f %f",DAY,ID,LABOUR_COSTS,CALC_CAPITAL_COSTS,TOTAL_INTEREST_PAYMENT);
             fprintf(file1," %f %f %f",PRODUCTION_QUANTITY,UNIT_COSTS,PRICE);
             fclose(file1);
             free(filename);

              }    

            
            
        }

        PRODUCTION_COSTS = CAPITAL_COSTS + LABOUR_COSTS;
        CALC_PRODUCTION_COSTS= LABOUR_COSTS + CALC_CAPITAL_COSTS;
        PAYMENT_ACCOUNT -= PRODUCTION_COSTS;

    //if(PLANNED_PRODUCTION_COSTS<PRODUCTION_COSTS)
        //printf("XXXX PLANNED_PRODUCTION_COSTS: %f  PRODUCTION_COSTS %f XXXXX\n",PLANNED_PRODUCTION_COSTS,PRODUCTION_COSTS);

    remove_double(&LAST_PLANNED_PRODUCTION_QUANTITIES,0);
    add_double(&LAST_PLANNED_PRODUCTION_QUANTITIES,PLANNED_PRODUCTION_QUANTITY); 

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG || PRINT_DEBUG_EXP1)
    {
        printf("\n\n Firm_calc_pay_costs ID: %d",ID);
        printf("\n\t CAPITAL_COSTS: %f LABOUR_COSTS: %f",CAPITAL_COSTS,LABOUR_COSTS);
        printf("\n\t UNIT_COSTS: %f PRICE_LAST_MONTH: %f PRICE: %f",UNIT_COSTS,PRICE_LAST_MONTH,PRICE);
        getchar();
    }   
    #endif
        
    return 0;
}


/** \fn Firm_send_goods_to_mall()
 * \brief Here the firms send the produced goods to the malls. If the realized output is less than  the intended one, then the malls are only delivered with a proportional share of their      plannded delivery volumes. */

int Firm_send_goods_to_mall()
{   
    
        double delivery_volume=0;

        for(int i=0; i<PLANNED_DELIVERY_VOLUME.size; i++)
        {
            delivery_volume+=PLANNED_DELIVERY_VOLUME.array[i].quantity;

        }


        for(int i = 0; i < PLANNED_DELIVERY_VOLUME.size; i++)
        {

            for(int j = 0; j < DELIVERY_VOLUME.size; j++)
            {
                if(DELIVERY_VOLUME.array[j].mall_id == 
                PLANNED_DELIVERY_VOLUME.array[i].mall_id)
                {
                    /*If planned prod vol > realized prod vol -> curtain the delivery vol*/
                    if(delivery_volume>PRODUCTION_QUANTITY)
                    {
                        DELIVERY_VOLUME.array[j].quantity =
                        PRODUCTION_QUANTITY / delivery_volume * PLANNED_DELIVERY_VOLUME.array[i].quantity;
                    
                    }else /*otherwise planned = realized del vol*/
                    
                    if(PRODUCTION_QUANTITY > delivery_volume &&
                    delivery_volume !=0)
                    {
                        DELIVERY_VOLUME.array[j].quantity = PRODUCTION_QUANTITY / delivery_volume*PLANNED_DELIVERY_VOLUME.array[i].quantity;

                    }else 
                    if(PRODUCTION_QUANTITY > delivery_volume &&
                    delivery_volume ==0)
                    {   

                        DELIVERY_VOLUME.array[j].quantity = 
                        PRODUCTION_QUANTITY/(DELIVERY_VOLUME.size);
                    }
                    else
                    {
                        DELIVERY_VOLUME.array[j].quantity = 
                        PLANNED_DELIVERY_VOLUME.array[i].quantity;
                    }
        
                    DELIVERY_VOLUME.array[j].quality=
                    PLANNED_DELIVERY_VOLUME.array[j].quality;

                    DELIVERY_VOLUME.array[j].price=
                    PLANNED_DELIVERY_VOLUME.array[j].price;
            
            
                    add_update_mall_stock_message(
                    DELIVERY_VOLUME.array[j].mall_id,ID,
                    DELIVERY_VOLUME.array[j].quantity,QUALITY,PRICE,PRICE_LAST_MONTH);
            
                }
            }
        }
    
    
    return 0;
}

/** \fn Firm_calc_revenue()
 * \brief Here the firms calc the revenues and profits and then distribute the dividends to households 
 */
int Firm_calc_revenue()
{
    FILE *file1;
     char *filename;
    REVENUE_PER_DAY=0.0;
    TOTAL_SOLD_QUANTITY=0.0;

    /*calc the daily revenue and sum up the monthly revenue*/
    START_SALES_MESSAGE_LOOP
    
        for(int i=0; i< SOLD_QUANTITIES.size; i++)
        {
            if(sales_message->mall_id ==  SOLD_QUANTITIES.array[i].mall_id)
            {
                
                
                SOLD_QUANTITIES.array[i].stock_empty = 
                               sales_message->stock_empty;
                
          
                SOLD_QUANTITIES.array[i].sold_quantity += 
                sales_message->revenue/PRICE;
            
                REVENUE_PER_DAY += sales_message->revenue;
        
                CUM_REVENUE += sales_message->revenue;
    
                TOTAL_SOLD_QUANTITY+=sales_message->revenue/PRICE;
            }   
        }
        

        //Update mall stocks
        for(int i=0; i< CURRENT_MALL_STOCKS.size; i++)
        {
            if(sales_message->mall_id ==  CURRENT_MALL_STOCKS.array[i].mall_id)
            {
                CURRENT_MALL_STOCKS.array[i].current_stock= sales_message->current_stock;
            }
        }
    
    FINISH_SALES_MESSAGE_LOOP
    
        if (PRINT_DEBUG_FILE_EXP1)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/firms_goods_market.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f %f",DAY,ID,TOTAL_SOLD_QUANTITY,PRICE);
        fclose(file1);
        free(filename);
    }    
    /*GENUA*/
    /*add_bank_account_update_message(BANK_ID, PAYMENT_ACCOUNT);*/
    //Not needed here: there is a function after this called Firm_send_payments_to_bank
    
    PAYMENT_ACCOUNT += REVENUE_PER_DAY;
    
    
	//Resetting the calendar month counter
	if(DAY%MONTH == 1)
	{
		 SOLD_QUANTITY_IN_CALENDAR_MONTH = 0;
	}
	/*The monthly sales statistics*/
    CUM_TOTAL_SOLD_QUANTITY += TOTAL_SOLD_QUANTITY; 
    SOLD_QUANTITY_IN_CALENDAR_MONTH+= TOTAL_SOLD_QUANTITY;
        
    /*On a monthly base the earnings are computed and dividends distributed*/
    //See the functions for financial management
    return 0;       
    
}
int Firm_compute_sales_statistics()
{


    /*The sales per mall must be stored for the inventory rule*/
            
        int remove_index;
                
        for(int j=0; j < MALLS_SALES_STATISTICS.size;j++)
        {
            for(int k = 0; k < MALLS_SALES_STATISTICS.array[j].sales.size; k++)
            {
                if(MALLS_SALES_STATISTICS.array[j].sales.array[k].period== FIRM_PLANNING_HORIZON)
                {       
                remove_index = k;
                remove_data_type_sales(&(MALLS_SALES_STATISTICS.array[j].sales), remove_index);
                k--;
                }else
                {
                    MALLS_SALES_STATISTICS.array[j].sales.array[k].period++;
                    
                }
            }
        }
                                         
                
        for(int i=0; i< SOLD_QUANTITIES.size;i++)
               {
                   for(int j=0; j<MALLS_SALES_STATISTICS.size; j++)
                   {
                   if(MALLS_SALES_STATISTICS.array[j].mall_id == SOLD_QUANTITIES.array[i].mall_id)
                       {
                    
                    if(SOLD_QUANTITIES.array[i].stock_empty==0)
                    {
                       add_data_type_sales(&(MALLS_SALES_STATISTICS.array[j].sales), 1 , 
                           SOLD_QUANTITIES.array[i].sold_quantity);
                        //printf("ID %d   stock empty, = 0  SOLD_QUANTITIES.array[i].sold_quantity %f\n",ID,SOLD_QUANTITIES.array[i].sold_quantity);
                       
                    }
                       else
                       {
                        add_data_type_sales(&(MALLS_SALES_STATISTICS.array[j].sales), 1 , 
                                            SOLD_QUANTITIES.array[i].sold_quantity*(1 + ADAPTION_DELIVERY_VOLUME));
                        //printf("ID %d   stock empty, = 1   sold_quantity*(1 + ADAPTION_DELIVERY_VOLUME)  %f\n",ID,SOLD_QUANTITIES.array[i].sold_quantity*(1 + ADAPTION_DELIVERY_VOLUME));
                       }
                       SOLD_QUANTITIES.array[i].sold_quantity=0;
                       SOLD_QUANTITIES.array[i].stock_empty=0;
                       }
                   }
               }
           
         
    
    return 0;
}


/** \fn Firm_update_specific_skills_of_workers()()
 * \brief   Because the specific skills of workers have changed the firms update the specific skill levels of the workers.
 */
int Firm_update_specific_skills_of_workers()
{

    START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
        
        for(int i=0; i<EMPLOYEES.size;i++)
        {
            if(specific_skill_update_message->id==EMPLOYEES.array[i].id)
            {
                EMPLOYEES.array[i].specific_skill=
                specific_skill_update_message->specific_skills;
                
            }
        }
        
    FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
    
    return 0;
}


