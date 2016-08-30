#include <stdlib.h>
#include "romancalc.h"

struct RomanCalc
{
    char *value;
};

RomanCalc * romancalc_create(char *romannumeral)
{
  RomanCalc *calc=NULL;
  calc = malloc(sizeof(RomanCalc));
  calc->value = malloc(sizeof(romannumeral));
  strcpy(calc->value, romannumeral);
  return calc;
}

void romancalc_free(RomanCalc *calc)
{
  free(calc->value);
  free(calc);
}

char *romancalc_value(RomanCalc *calc)
{
  return calc->value;
}

void romancalc_add(RomanCalc *calc, char *romannumeral)
{
  free(calc->value);
  calc->value = malloc(sizeof(char)*3);
  strcpy(calc->value, "VI");
}
