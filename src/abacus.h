#ifndef ABACUS_H
#define ABACUS_H

typedef struct Abacus Abacus;

Abacus *abacus_create(void);
void abacus_free(Abacus *abacus);

#endif /* ABACUS_H */
