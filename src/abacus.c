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
  int i;
  Abacus *abacus;
  abacus = malloc(sizeof(Abacus));
  strcpy(abacus->symbols, "MDCLXVI");
  abacus->multi[0]=true;
  abacus->multi[1]=false;
  abacus->multi[2]=true;
  abacus->multi[3]=false;
  abacus->multi[4]=true;
  abacus->multi[5]=false;
  for (i=0;i<6;++i)
  {
    abacus->count[i]=0;
  }
  return abacus;
}

void abacus_free(Abacus *abacus)
{
  free(abacus);
}
