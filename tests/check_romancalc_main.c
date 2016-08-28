#include <stdlib.h>
#include <check.h>
#include "check_romancalc.h"


int main(void)
{
  int number_failed;
  SRunner *sr;

  // Place setup methods here


  sr = srunner_create(make_romancalc_suite());
  // Add other suites with srunner_add_suite(sr, make_suite())

  srunner_run_all(sr, CK_VERBOSE);
  // Add cleanup methods here

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
