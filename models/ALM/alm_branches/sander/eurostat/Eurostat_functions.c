#include "header.h"
#include "Eurostat_agent_header.h"
#include "my_library_header.h"
#include "math.h"

/************Eurostat Role: Statistical Office********************************/

/************Data collection********************************/
/* \fn: int Eurostat_collect_data()
 * \brief: At the end of every quarter
 */
int Eurostat_collect_data()
{	
	//reset current value in memory
	GDP=0;
	TOTAL_NR_EMPLOYED =0;
	TOTAL_NR_UNEMPLOYED=0;
	
	/* Read GDP messages */
	START_FIRM_STATISTICS_MESSAGE_LOOP
		GDP += firm_statistics_to_eurostat_message->net_revenue;
	FINISH_FIRM_STATISTICS_MESSAGE_LOOP
	
	/* Read EMPLOYED messages */
	START_FIRM_STATISTICS_MESSAGE_LOOP
		TOTAL_NR_EMPLOYED += firm_statistics_to_eurostat_message->no_employees; //change this to nr_employees?
	FINISH_FIRM_STATISTICS_MESSAGE_LOOP
	
	/* Read regional UNEMPLOYED messages */
	START_REGIONAL_EUROSTAT_MESSAGE_LOOP
		TOTAL_NR_UNEMPLOYED += statistics_from_regional_eurostat_message->nr_unemployed; //change this to nr_employees?
		TOTAL_POPULATION_HOUSEHOLDS += statistics_from_regional_eurostat_message->population_households;
	FINISH_REGIONAL_EUROSTAT_MESSAGE_LOOP
	
    return 0;
}

/************ Computation ********************************/
/* \fn: int Eurostat_compute_statistics()
 * \brief: Computes statistics at the end of every quarter
 */
int Eurostat_compute_statistics()
{
	//compute annual GDP growth rate over the previous 4 quarters
	GDP_GROWTH_RATE = GDP / history[3]->GDP;
	
	//compute employment rate
	EMPLOYMENT_RATE = TOTAL_NR_EMPLOYED / TOTAL_POPULATION_HOUSEHOLDS;

	//compute employment rate
	UNEMPLOYMENT_RATE = TOTAL_NR_UNEMPLOYED / TOTAL_POPULATION_HOUSEHOLDS;
	
return 0;
}

/******* Storing data to history ***************/
/* \fn: int Eurostat_store_history()
 * \brief: Central_Eurostat agent stores statistics to history structure. 
 */
int Eurostat_store_history()
{
	
	/* Datatype:
	 * struct history_item
	 * {
	 * 		double GDP;
	 * 		double GDP_growth_rate;
	 * 		double employment_rate;
	 * 		double unemployment_rate;
	 * 		double interest_rate;
	 * }
	
	//Static array of history items:
	 history_item[4] history;
	
	//Shift history backwards
	/*
	 * history[3]->GDP = history[2]->GDP; 	//t-4 gets filled with value from t-3
	 * history[2]->GDP = history[1]->GDP; 	//t-3 gets filled with value from t-2
	 * history[1]->GDP = history[0]->GDP; 	//t-2 gets filled with value from t-1
	 * history[0]->GDP = GDP;         		//t-1 gets filled with value from t
	 */
	for (i=3; i>0; i--)
	{
	  history[i]->GDP = history[i-1]->GDP; 	//t-i-1 gets filled with value from t-i
	  history[i]->GDP = history[i-1]->GDP_growth_rate;
	  history[i]->GDP = history[i-1]->employment_rate;
	  history[i]->GDP = history[i-1]->unemployment_rate;
	  history[i]->GDP = history[i-1]->interest_rate;
	}
	
	//Store first value of history
	history[0]->GDP = GDP; 					//t-1 gets filled with value from t
	history[0]->GDP = GDP_growth_rate;
	history[0]->GDP = employment_rate;
	history[0]->GDP = unemployment_rate;
	history[0]->GDP = interest_rate;

return 0;
}


/************ Communication ********************************/
/* \fn: int Eurostat_communicate_statistics()
 * \brief: Regional Eurostat agent communicates statistics to the Central_Eurostat agent.
 */
int Eurostat_communicate_statistics()
{
	//GDP: GDP in the region
	//GDP_GROWTH_RATE: growth rate of regional GDP
	//nr_unemployed: unemployed households in the region
	//population_households: current population of households in the region
	
	add_regional_eurostat_message(ID, GDP, GDP_GROWTH_RATE, NR_UNEMPLOYED, POPULATION_HOUSEHOLDS, MSGDATA);	

	return 0;
}

