#include "../header.h"
#include "../Government_agent_header.h"

int Government_bond_market_dummy()
{
	//Dummy model short-cut:
	//Assume that all gov debt is bond financed, and the bond market is infinitely liquid
	
	PAYMENT_ACCOUNT += TOTAL_BOND_FINANCING;
	
	//Msg to Central Bank: monetary amount
	add_gov_bond_message(TOTAL_BOND_FINANCING);
	
	return 0;
}

