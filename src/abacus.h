#ifndef ABACUS_H
#define ABACUS_H

typedef struct Abacus Abacus;

Abacus *abacus_create(void);
void abacus_free(Abacus *abacus);

void abacus_init_value(Abacus *abacus, char *romannumeral);
int abacus_get_count(Abacus *abacus, int index);

#endif /* ABACUS_H */
