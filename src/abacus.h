#ifndef ABACUS_H
#define ABACUS_H

typedef struct Abacus Abacus;
#define MAX_SYMBOLS 7
#define MAX_RESULT_LENGTH 25

Abacus *abacus_create(void);
void abacus_free(Abacus *abacus);

void abacus_init_value(Abacus *abacus, char *romannumeral);
void abacus_add_value(Abacus *abacus, char *romannumeral);
int abacus_get_count(Abacus *abacus, int index);
char *abacus_get_result(Abacus *abacus);

#endif /* ABACUS_H */
