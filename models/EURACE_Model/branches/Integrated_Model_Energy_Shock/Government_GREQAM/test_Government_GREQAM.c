#include "../Suites.h"
#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"

void test_Government_read_tax_payments(void) {

	/*Local variables declaration*/	
	int rc;
	
	unittest_init_Government_agent();

	/*Variables initialization*/
	set_id(1);

	/* Messages */
	add_tax_payment_message(ID, 100);
	rc = MB_Iterator_Create(b_tax_payment, &i_tax_payment);

	Government_read_tax_payments();

	CU_ASSERT_DOUBLE_EQUAL(get_monthly_tax_revenues(), 100.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(get_payment_account(), 100.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(get_yearly_tax_revenues(), 100.0, 1e-3);
}

