#include <stdlib.h>
#include "romancalc.h"
#include "abacus.h"

struct RomanCalc
{
    Abacus* abacus;
};

RomanCalc * romancalc_create(char *romannumeral)
{
  RomanCalc *calc=NULL;
  calc = malloc(sizeof(RomanCalc));
  calc->abacus=NULL;
  calc->abacus=abacus_create();
  if (calc->abacus != NULL) abacus_init_value(calc->abacus, romannumeral);
  return calc;
}

void romancalc_free(RomanCalc *calc)
{
  abacus_free(calc->abacus);
  free(calc);
}

bool romancalc_value(RomanCalc *calc, char *resultString, int resultLength)
{
  return abacus_get_result(calc->abacus, resultString, resultLength);
}

bool romancalc_add(RomanCalc *calc, char *romannumeral)
{
  return abacus_add_value(calc->abacus, romannumeral);
}
bool romancalc_subtract(RomanCalc *calc, char *romannumeral)
{
  return abacus_subtract_value(calc->abacus, romannumeral);
}
