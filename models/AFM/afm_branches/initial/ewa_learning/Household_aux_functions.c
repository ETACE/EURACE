/*********************************
 * Household_aux_functions.c 
 * Household auxiliary functions.
 * *********************************
 * History:
 * 29/07/08 Sander  
 *********************************/
#include "header.h"
#include "Household_agent_header.h"

/* \fn void Household_portfolio_strategy_interface
 * \brief Interface between the GA/EWA functions and the AFM_UG code.
 */

void Household_portfolio_strategy_interface()
{
	int j;
	
	j=PRIVATE_CLASSIFIERSYSTEM.current_rule;
	
	FORWARDWINDOW               = PRIVATE_CLASSIFIERSYSTEM.ruletable[j].parameters[0];
	BACKWARDWINDOW              = PRIVATE_CLASSIFIERSYSTEM.ruletable[j].parameters[1];
	BINS                        = PRIVATE_CLASSIFIERSYSTEM.ruletable[j].parameters[2];
	RANDOMWEIGHT                = PRIVATE_CLASSIFIERSYSTEM.ruletable[j].parameters[3];
	FUNDAMENTALWEIGHT           = PRIVATE_CLASSIFIERSYSTEM.ruletable[j].parameters[4];
	CHARTISTWEIGHT              = PRIVATE_CLASSIFIERSYSTEM.ruletable[j].parameters[5];
	HOLDINGPERIODTOFORWARDW     = PRIVATE_CLASSIFIERSYSTEM.ruletable[j].parameters[6];
	LOSSAVERSION                = PRIVATE_CLASSIFIERSYSTEM.ruletable[j].parameters[7];
}
