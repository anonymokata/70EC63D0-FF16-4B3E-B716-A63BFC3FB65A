#include <stdlib.h>
#include <check.h>
#include "../src/romancalc.h"

#define MAX_VALUE_LENGTH 25

START_TEST(test_romancalc_create)
{
  RomanCalc *calc=NULL;
  char *value=(char*)malloc(sizeof(char)*MAX_VALUE_LENGTH);
  ck_assert_ptr_ne(value, NULL);
  calc = romancalc_create("III");
  ck_assert_ptr_ne(calc, NULL);
  ck_assert(romancalc_value(calc, value, MAX_VALUE_LENGTH));
  ck_assert_str_eq(value, "III");
  free(value);
  value=NULL;
  romancalc_free(calc);
  calc=NULL;
}
END_TEST

START_TEST(test_romancalc_simple_add)
{
  RomanCalc *calc=NULL;
  char *value=(char*)malloc(sizeof(char)*MAX_VALUE_LENGTH);
  ck_assert_ptr_ne(value, NULL);
  calc = romancalc_create("III");
  ck_assert_ptr_ne(calc, NULL);
  romancalc_add(calc, "III");
  ck_assert(romancalc_value(calc, value, MAX_VALUE_LENGTH));
  ck_assert_str_eq(value, "VI");
  free(value);
  value=NULL;
  romancalc_free(calc);
  calc=NULL;
}
END_TEST
START_TEST(test_romancalc_complex_add)
{
  RomanCalc *calc=NULL;
  char *value=(char*)malloc(sizeof(char)*MAX_VALUE_LENGTH);
  ck_assert_ptr_ne(value, NULL);
  calc = romancalc_create("MCMIII");
  ck_assert_ptr_ne(calc, NULL);
  romancalc_add(calc, "DCXLI");
  ck_assert(romancalc_value(calc, value, MAX_VALUE_LENGTH));
  ck_assert_str_eq(value, "MMDXLIV");
  free(value);
  value=NULL;
  romancalc_free(calc);
  calc=NULL;
}
END_TEST
START_TEST(test_romancalc_simple_subtract)
{
  RomanCalc *calc=NULL;
  char *value=(char*)malloc(sizeof(char)*MAX_VALUE_LENGTH);
  ck_assert_ptr_ne(value, NULL);
  calc = romancalc_create("LXXIII");
  ck_assert_ptr_ne(calc, NULL);
  romancalc_subtract(calc, "XII");
  ck_assert(romancalc_value(calc, value, MAX_VALUE_LENGTH));
  ck_assert_str_eq(value, "LXI");
  free(value);
  value=NULL;
  romancalc_free(calc);
  calc=NULL;
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
  tcase_add_test(tc_add, test_romancalc_simple_subtract);
  suite_add_tcase(s, tc_add);

  return s;
}
