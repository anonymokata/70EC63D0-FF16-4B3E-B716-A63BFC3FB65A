#include <stdbool.h>

#include "abacus.h"

struct Abacus
{
  char symbols[6];
  bool multi[6];
  int count[6];
};

Abacus *abacus_create(void)
{
  Abacus *abacus;
  abacus = malloc(sizeof(Abacus));
  strcpy(abacus->symbols, "MDCLXVI");
  return abacus;
}

void abacus_free(Abacus *abacus)
{
  free(abacus);
}
