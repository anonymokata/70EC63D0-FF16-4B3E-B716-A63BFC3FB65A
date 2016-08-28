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

Suite * make_abacus_suite(void)
{
  Suite *s;
  TCase *tc_core;
  TCase *tc_add;

  s = suite_create("Abacus");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_abacus_create);
  suite_add_tcase(s, tc_core);

  return s;
}
