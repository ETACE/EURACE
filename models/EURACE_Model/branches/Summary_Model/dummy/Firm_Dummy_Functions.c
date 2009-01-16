#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"

int Firm_planned_production_costs_dummy() {
	
	PLANNED_PRODUCTION_COSTS = 100.0;
	
	CUM_REVENUE = 0.0;
	
    return 0;
	
}

/*
 * \fn Firm_compute_income_statement()
 * \brief Function to compute the income statement of the firm.
 */
int Firm_credit_market_dummy() {
    
	return 0;
}

int Firm_labour_good_market_dummy() {
    
    int daily_revenue;
    
    PRODUCTION_COSTS = PLANNED_PRODUCTION_COSTS;
    
    daily_revenue = 1.1 * (TOTAL_INTEREST_PAYMENT + PRODUCTION_COSTS)/MONTH;
    
    CUM_REVENUE += daily_revenue;
    
    PAYMENT_ACCOUNT += daily_revenue - (PRODUCTION_COSTS/MONTH);
    
    return 0;
                                
}


