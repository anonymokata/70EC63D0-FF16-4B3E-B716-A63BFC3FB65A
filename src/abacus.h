#ifndef ABACUS_H
#define ABACUS_H

#include <stdbool.h>

#define MAX_SYMBOLS 7

typedef struct Abacus Abacus;

Abacus *abacus_create(void);
void abacus_free(Abacus *abacus);

void abacus_init_value(Abacus *abacus, char *romannumeral);
void abacus_add_value(Abacus *abacus, char *romannumeral);
bool abacus_subtract_value(Abacus *abacus, char *romannumeral);
int abacus_get_count(Abacus *abacus, int index);
bool abacus_get_result(Abacus *abacus, char *resultString, int resultLength);

#endif /* ABACUS_H */
