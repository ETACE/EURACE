#include "header.h"
#include "Eurostat_agent_header.h"
#include "my_library_header.h"
#include "math.h"

/************Eurostat Role: Statistical Office********************************/

/******************************* STORING MONTHLY DATA **************************************/
/* Datatype:

	  struct history_item
	  {
	  		double gdp;
	  		double output;
	  		double employment;
	  		double unemployment_rate;
	  		double wages;	 
	   }

	//Static array of history items:
	 history_item history_monthly[13];
	 history_item history_quarterly[5];
	
	//Single history_items for growth rates: 
	history_item MONTHLY_GROWTH_RATES
	history_item QUARTERLY_GROWTH_RATES
	history_item ANNUAL_GROWTH_RATES_MONTHLY
	history_item ANNUAL_GROWTH_RATES_QUARTERLY
*/

/* \fn: int Eurostat_store_history_monthly()
 * \brief: Central_Eurostat agent stores statistics to monthly history structure. 
 */
int Eurostat_store_history_monthly()
{	
	//Shift history backwards
	/*
	 * history_monthly[4].GDP = history_monthly[3].GDP; 	//t-4 gets filled with value from t-3
	 * history_monthly[3].GDP = history_monthly[2].GDP; 	//t-3 gets filled with value from t-3
	 * history_monthly[2].GDP = history_monthly[1].GDP; 	//t-2 gets filled with value from t-2
	 * history_monthly[1].GDP = history_monthly[0].GDP; 	//t-1 gets filled with value from t-1
	 * history_monthly[0].GDP = GDP;         				//t gets filled with value from t
	 */
	for (i=12; i>0; i--)
	{
	  HISTORY_MONTHLY[i].gdp = HISTORY_MONTHLY[i-1].gdp; 	//t-i-1 gets filled with value from t-i
	  HISTORY_MONTHLY[i].output = HISTORY_MONTHLY[i-1].output;
	  HISTORY_MONTHLY[i].employment = HISTORY_MONTHLY[i-1].employment;
	  HISTORY_MONTHLY[i].unemployment_rate = HISTORY_MONTHLY[i-1].unemployment_rate;
	  HISTORY_MONTHLY[i].wages = HISTORY_MONTHLY[i-1].wages;
	}
	
	//Store first value of history: [0] gets filled with value from t
	HISTORY_MONTHLY[0].gdp = GDP;
	HISTORY_MONTHLY[0].output = MONTHLY_OUTPUT;
	HISTORY_MONTHLY[0].employment = EMPLOYED;
	HISTORY_MONTHLY[0].unemployment_rate = UNEMPLOYMENT_RATE;
	HISTORY_MONTHLY[0].wages = AVERAGE_WAGE;

	return 0;
}

/******************************* STORING QUARTERLY DATA **************************************/
/* \fn: int Eurostat_store_history_quarterly()
 * \brief: Central_Eurostat agent stores statistics to quarterly history structure. 
 */
int Eurostat_store_history_quarterly()
{
	
	//Shift history backwards
	for (i=4; i>0; i--)
	{
	  HISTORY_QUARTERLY[i].gdp = HISTORY_QUARTERLY[i-1].gdp; 	//t-i-1 gets filled with value from t-i
	  HISTORY_QUARTERLY[i].output = HISTORY_QUARTERLY[i-1].output;
	  HISTORY_QUARTERLY[i].employment = HISTORY_QUARTERLY[i-1].employment;
	  HISTORY_QUARTERLY[i].unemployment_rate = HISTORY_QUARTERLY[i-1].unemployment_rate;
	  HISTORY_QUARTERLY[i].wages = HISTORY_QUARTERLY[i-1].wages;
	}
	
	//Reset first elements for sum
	HISTORY_QUARTERLY[0].gdp=0.0;
	HISTORY_QUARTERLY[0].output=0.0;
	HISTORY_QUARTERLY[0].employment=0.0;
	HISTORY_QUARTERLY[0].unemployment_rate=0.0;
	HISTORY_QUARTERLY[0].wages=0.0;
	
	//Store first value: construct quarterly sums from monthly history
	for (i=0; i<4; i++)
	{
		HISTORY_QUARTERLY[0].gdp 				+= HISTORY_MONTHLY[i].gdp;	
		HISTORY_QUARTERLY[0].output 			+= HISTORY_MONTHLY[i].output;
		HISTORY_QUARTERLY[0].employment 		+= HISTORY_MONTHLY[i].employment;
		HISTORY_QUARTERLY[0].unemployment_rate  += HISTORY_MONTHLY[i].unemployment_rate;
		HISTORY_QUARTERLY[0].wages 				+= HISTORY_MONTHLY[i].wages;
	}

	return 0;
}


/************ Computation ********************************/
/* \fn: int Eurostat_compute_growth_rates_monthly()
 * \brief: Computes growth rates from the current history at the end of every month
 */
int Eurostat_compute_growth_rates_monthly()
{
	//compute monthly growth rates: change over the previous month
	MONTHLY_GROWTH_RATES.gdp 				= HISTORY_MONTHLY[0].gdp / HISTORY_MONTHLY[1].gdp;
	MONTHLY_GROWTH_RATES.output 			= HISTORY_MONTHLY[0].output / HISTORY_MONTHLY[1].output;
	MONTHLY_GROWTH_RATES.employment  		= HISTORY_MONTHLY[0].employment / HISTORY_MONTHLY[1].employment;
	MONTHLY_GROWTH_RATES.unemployment_rate  = HISTORY_MONTHLY[0].unemployment_rate / HISTORY_MONTHLY[1].unemployment_rate;
	MONTHLY_GROWTH_RATES.wages 				= HISTORY_MONTHLY[0].wages / HISTORY_MONTHLY[1].wages;
	
	//compute annual growth rates over the previous 12 months
	ANNUAL_GROWTH_RATES_MONTHLY.gdp 		= HISTORY_MONTHLY[0].gdp / HISTORY_MONTHLY[12].gdp;
	ANNUAL_GROWTH_RATES_MONTHLY.output 		= HISTORY_MONTHLY[0].output / HISTORY_MONTHLY[12].output;
	ANNUAL_GROWTH_RATES_MONTHLY.employment  = HISTORY_MONTHLY[0].employment / HISTORY_MONTHLY[12].employment;
	ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate = HISTORY_MONTHLY[0].unemployment_rate / HISTORY_MONTHLY[12].unemployment_rate;
	ANNUAL_GROWTH_RATES_MONTHLY.wages 		= HISTORY_MONTHLY[0].wages / HISTORY_MONTHLY[12].wages;

return 0;
}

/* \fn: int Eurostat_compute_growth_rates_quarterly()
 * \brief: Computes growth rates from the current history at the end of every quarterly
 */
int Eurostat_compute_growth_rates_quarterly()
{

	//compute quarterly growth rates: change over the previous quarter
	QUARTERLY_GROWTH_RATES.gdp 				= HISTORY_QUARTERLY[0].gdp / HISTORY_QUARTERLY[1].gdp;
	QUARTERLY_GROWTH_RATES.output 			= HISTORY_QUARTERLY[0].output / HISTORY_QUARTERLY[1].output;
	QUARTERLY_GROWTH_RATES.employment  		= HISTORY_QUARTERLY[0].employment / HISTORY_QUARTERLY[1].employment;
	QUARTERLY_GROWTH_RATES.unemployment_rate= HISTORY_QUARTERLY[0].unemployment_rate / HISTORY_QUARTERLY[1].unemployment_rate;
	QUARTERLY_GROWTH_RATES.wages 			= HISTORY_QUARTERLY[0].wages / HISTORY_QUARTERLY[1].wages;

	//compute annual growth rates over the previous 4 quarters
	ANNUAL_GROWTH_RATES_QUARTERLY.gdp 		= HISTORY_QUARTERLY[0].gdp / HISTORY_QUARTERLY[4].gdp;
	ANNUAL_GROWTH_RATES_QUARTERLY.output 	= HISTORY_QUARTERLY[0].output / HISTORY_QUARTERLY[4].output;
	ANNUAL_GROWTH_RATES_QUARTERLY.employment= HISTORY_QUARTERLY[0].employment / HISTORY_QUARTERLY[4].employment;
	ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate = HISTORY_QUARTERLY[0].unemployment_rate / HISTORY_QUARTERLY[4].unemployment_rate;
	ANNUAL_GROWTH_RATES_QUARTERLY.wages 	= HISTORY_QUARTERLY[0].wages / HISTORY_QUARTERLY[4].wages;

	return 0;
}

