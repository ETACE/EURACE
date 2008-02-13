#include "Suites.h"



void print_example_results(void)
{
  fprintf(stdout, "\n\nExpected Test Results:"
                  "\n\n  Error Handling  Type      # Run   # Pass   # Fail"
                  "\n\n  ignore errors   suites%9u%9u%9u"
                    "\n                  tests %9u%9u%9u"
                    "\n                  asserts%8u%9u%9u"
                  "\n\n  stop on error   suites%9u%9u%9u"
                    "\n                  tests %9u%9u%9u"
                    "\n                  asserts%8u%9u%9u\n\n",
                  14, 14, 3,
                  31, 10, 21,
                  89, 47, 42,
                  4, 4, 1,
                  12, 9, 3,
                  12, 9, 3);
}

void AddTests()
{
  assert(NULL != CU_get_registry());
  assert(!CU_is_test_running());

	/* Register suites. */
	if (CU_register_suites(suites) != CUE_SUCCESS) {
		fprintf(stderr, "suite registration failed - %s\n",
			CU_get_error_msg());
		exit(EXIT_FAILURE);
	}

}
