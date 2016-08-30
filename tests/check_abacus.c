#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include "../src/abacus.h"

START_TEST(test_abacus_create)
{
  Abacus *abacus;
  abacus = abacus_create();
  // verify that abacus is not null
  ck_assert_ptr_ne(abacus, NULL);
  abacus_free(abacus);
}
END_TEST

START_TEST(test_abacus_init_simple_value)
{
    int index;
    int count;
    Abacus *abacus=NULL;
    abacus = abacus_create();
    ck_assert_ptr_ne(abacus, NULL);
    abacus_init_value(abacus, "XXII");
    for (index=0;index<MAX_SYMBOLS;++index)
    {
      count=abacus_get_count(abacus,index);
      switch (index) {
        case 0:
          ck_assert_int_eq(count, 0);
          break;
        case 1:
          ck_assert_int_eq(count, 0);
          break;
        case 2:
          ck_assert_int_eq(count, 0);
          break;
        case 3:
          ck_assert_int_eq(count, 0);
          break;
        case 4:
          ck_assert_int_eq(count, 2);
          break;
        case 5:
          ck_assert_int_eq(count, 0);
          break;
        case 6:
          ck_assert_int_eq(count, 2);
          break;
      }
    }
    char *result=abacus_get_result(abacus);
    ck_assert_str_eq(result, "XXII");
    abacus_free(abacus);
    free(result);
}
END_TEST
START_TEST(test_abacus_init_complex_value)
{
    int index;
    int count;
    Abacus *abacus=NULL;
    abacus = abacus_create();
    ck_assert_ptr_ne(abacus, NULL);
    abacus_init_value(abacus, "MCMXLIV");
    for (index=0;index<MAX_SYMBOLS;++index)
    {
      count=abacus_get_count(abacus,index);
      switch (index) {
        case 0:
          ck_assert_int_eq(count, 1);
          break;
        case 1:
          ck_assert_int_eq(count, 1);
          break;
        case 2:
          ck_assert_int_eq(count, 4);
          break;
        case 3:
          ck_assert_int_eq(count, 0);
          break;
        case 4:
          ck_assert_int_eq(count, 4);
          break;
        case 5:
          ck_assert_int_eq(count, 0);
          break;
        case 6:
          ck_assert_int_eq(count, 4);
          break;
      }
    }
    char *result=abacus_get_result(abacus);
    ck_assert_str_eq(result, "MCMXLIV");
    abacus_free(abacus);
    free(result);
}
END_TEST

Suite * make_abacus_suite(void)
{
  Suite *s=NULL;
  TCase *tc_core=NULL;
  TCase *tc_add=NULL;

  s = suite_create("Abacus");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_abacus_create);
  tcase_add_test(tc_core, test_abacus_init_simple_value);
  tcase_add_test(tc_core, test_abacus_init_complex_value);
  suite_add_tcase(s, tc_core);

  return s;
}
