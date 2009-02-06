#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"

int Firm_planned_production_costs_dummy() {
	
	printf("\n  ***  FIRM PLANNED PRODUCTION COSTS DUMMY ***\n  - last_day_of_month_to_act: %d  -\n\n", get_last_day_of_month_to_act());
	getchar();
	
	PLANNED_PRODUCTION_COSTS = 100.0;
	
	CUM_REVENUE = 0.0;
	
    return 0;
	
}

/*
 * \fn Firm_compute_income_statement()
 * \brief Function to compute the income statement of the firm.
 */
int Firm_credit_market_dummy() {
    
    printf("\n\n*Firm_credit_market_dummy*\nEXTERNAL FINANCIAL NEEDS: %f\n\n",EXTERNAL_FINANCIAL_NEEDS);
    
	return 0;
}

int Firm_labour_good_market_dummy() {
    

    printf("\n\n**Firm_labour_good_market_dummy**");

    double daily_revenue = 0.0;
    PRODUCTION_COSTS = PLANNED_PRODUCTION_COSTS;
    daily_revenue = 1.1 * (TOTAL_INTEREST_PAYMENT + PRODUCTION_COSTS)/20;
    CUM_REVENUE = CUM_REVENUE + daily_revenue;
    
    PAYMENT_ACCOUNT += daily_revenue - (PRODUCTION_COSTS/20);
    
    printf("\n daily_revenue: %f\t CUM_REVENUE: %f\t PAYMENT_ACCOUNT: %f\t", daily_revenue, CUM_REVENUE, PAYMENT_ACCOUNT);

    return 0;
                                
}


