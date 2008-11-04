/*********************************
 * Mall_aux_functions.c 
 * Mall auxiliary functions.
 * *********************************
 * History:
 * 29/10/08 Sander 
 *********************************/
#include "../header.h"
#include "../Mall_agent_header.h"
#include "Mall_aux_header.h"

#define NO_REGIONS 1 //number of regions (hard-coded here)


/* \fn: void Mall_add_export_data()
 * \brief: Function to add data to the export matrix (during every transaction).
 */
void Mall_add_export_data(int firm_region, int household_region, double transaction_value)
{
	int index;
	
	//add value to export matrix
	index=(firm_region-1)*NO_REGIONS+(household_region-1);
	EXPORT_MATRIX[index] = transaction_value;
}
