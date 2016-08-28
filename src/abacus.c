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

void abacus_init_value(Abacus *abacus, char *romannumeral)
{
  int current = 0;
  int previous = 0;
  int next = current+1;
  int length = strlen(romannumeral);
  int validlen = strspn(romannumeral, "MDCLXVI");
  if (validlen == length)
  {
    printf("This is a Roman Number.");
  } else {
    printf("This is NOT a roman number");
  }
}

int abacus_get_count(Abacus *abacus, int index)
{
  if (index < 6 && index>=0){
    return abacus->count[index];
  }
  return 0;
}
