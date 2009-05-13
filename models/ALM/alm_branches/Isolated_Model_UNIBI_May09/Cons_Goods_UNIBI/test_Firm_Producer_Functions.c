#include "../Suites.h"
#include "../header.h"
#include "../my_library_header.h"


void test_Firm_execute_production(void) {

	/*Local variables declaration*/	

	/*Variables inizialization*/
	set_planned_production_quantity(100);
	set_mean_specific_skills(1.3);
	set_technology(1.5);
	set_no_employees(50);
	set_total_units_capital_stock(50);
	//set_alpha(0.5);
	//set_beta(0.5);
	set_total_units_local_inventory(0);

	ALPHA=0.5;
	BETA=0.5;

	Firm_execute_production();

	CU_ASSERT_EQUAL(get_production_quantity(), 65);
	CU_ASSERT_EQUAL(get_output(), 65);
	CU_ASSERT_EQUAL(get_total_supply(), 65);
}

