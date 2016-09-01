#include <stdlib.h>
#include <check.h>
#include "../src/romancalc.h"

START_TEST(test_romancalc_create)
{
  RomanCalc *calc=NULL;
  calc = romancalc_create("III");
  ck_assert_str_eq(romancalc_value(calc), "III");
  romancalc_free(calc);
}
END_TEST

START_TEST(test_romancalc_simple_add)
{
  RomanCalc *calc=NULL;
  calc = romancalc_create("III");
  ck_assert_str_eq(romancalc_value(calc), "III");
  romancalc_add(calc, "III");
  ck_assert_str_eq(romancalc_value(calc), "VI");
  romancalc_free(calc);
}
END_TEST
START_TEST(test_romancalc_complex_add)
{
  RomanCalc *calc=NULL;
  calc = romancalc_create("MCMIII");
  ck_assert_str_eq(romancalc_value(calc), "MCMIII");
  romancalc_add(calc, "DCXLI");
  ck_assert_str_eq(romancalc_value(calc), "MMDXLIV");
  romancalc_free(calc);
}
END_TEST

Suite * make_romancalc_suite(void)
{
  Suite *s=NULL;
  TCase *tc_core=NULL;
  TCase *tc_add=NULL;

  s = suite_create("RomanCalc");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_romancalc_create);
  suite_add_tcase(s, tc_core);

  tc_add = tcase_create("Addition");
  tcase_add_test(tc_add, test_romancalc_simple_add);
  tcase_add_test(tc_add, test_romancalc_complex_add);
  suite_add_tcase(s, tc_add);

  return s;
}
