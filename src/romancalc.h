#ifndef ROMANCALC_H
#define ROMANCALC_H

#include <stdbool.h>

typedef struct RomanCalc RomanCalc;

RomanCalc *romancalc_create(char *romannumeral);
void romancalc_free(RomanCalc *calc);

bool romancalc_value(RomanCalc *calc, char *resultString, int resultLength);
bool romancalc_add(RomanCalc *calc, char *romannumeral);
bool romancalc_subtract(RomanCalc *calc, char *romannumeral);

#endif /* ROMANCALC_H */
