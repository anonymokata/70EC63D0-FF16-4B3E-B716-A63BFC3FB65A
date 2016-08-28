#ifndef ROMANCALC_H
#define ROMANCALC_H

typedef struct RomanCalc RomanCalc;

RomanCalc *romancalc_create(char *romannumeral);
void romancalc_free(RomanCalc *calc);

char *romancalc_value(RomanCalc *calc);

#endif /* ROMANCALC_H */
