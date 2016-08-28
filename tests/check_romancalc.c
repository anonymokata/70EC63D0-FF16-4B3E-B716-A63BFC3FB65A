#include <stdlib.h>
#include <check.h>
#include "../src/romancalc.h"

START_TEST(test_romancalc_create)
{
  RomanCalc *calc;
  calc = romancalc_create("III");
  ck_assert_str_eq(romancalc_value(calc), "III");
  romancalc_free(calc);  
}
END_TEST

START_TEST(test_romancalc_simple_add)
{
  RomanCalc *calc;
}
END_TEST

Suite * make_romancalc_suite(void)
{
  Suite *s;
  TCase *tc_core;
  TCase *tc_add;

  s = suite_create("RomanCalc");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_romancalc_create);
  suite_add_tcase(s, tc_core);

  tc_add = tcase_create("Addition");
  tcase_add_test(tc_add, test_romancalc_simple_add);
  suite_add_tcase(s, tc_add);

  return s;
}
