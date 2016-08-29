#include <stdbool.h>

#include "abacus.h"

struct Abacus
{
  char symbols[MAX_SYMBOLS];
  bool multi[MAX_SYMBOLS];
  int count[MAX_SYMBOLS];
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
  abacus->multi[6]=true;
  for (i=0;i<MAX_SYMBOLS;++i)
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
  int curSymIndex = 0;
  int nextSymIndex = curSymIndex+1;
  int nextNextSymIndex=curSymIndex+2;
  int numIndex = 0;
  int length = strlen(romannumeral);
  int validlen = strspn(romannumeral, "MDCLXVI");
  if (validlen == length)
  {
    printf("Enter value: romannumeral=%s\n", romannumeral);
    while (curSymIndex < MAX_SYMBOLS)
    {
      if (numIndex > length) break;
      if (romannumeral[numIndex] == abacus->symbols[curSymIndex])
      {
        ++abacus->count[curSymIndex];
        ++numIndex;
      } else if (romannumeral[numIndex+1] == abacus->symbols[curSymIndex]) {
        if (romannumeral[numIndex] == abacus->symbols[nextSymIndex])
        {
            if (abacus->multi[curSymIndex]) {
              ++abacus->count[nextSymIndex];
            } else {
              abacus->count[nextSymIndex]=abacus->count[nextSymIndex]+4;
            }
        } else if (romannumeral[numIndex] == abacus->symbols[nextNextSymIndex]) {
          if (abacus->multi[curSymIndex]) {
            ++abacus->count[nextSymIndex];
            abacus->count[nextNextSymIndex]=abacus->count[nextNextSymIndex]+4;
            curSymIndex=nextNextSymIndex+1;
            nextSymIndex=curSymIndex+1;
            nextNextSymIndex=curSymIndex+2;
            if (nextSymIndex>MAX_SYMBOLS) nextSymIndex=MAX_SYMBOLS;
            if (nextNextSymIndex>MAX_SYMBOLS) nextNextSymIndex=MAX_SYMBOLS;
          }
        }
        numIndex=numIndex+2;
      } else {
        ++curSymIndex;
        nextSymIndex=curSymIndex+1;
        nextNextSymIndex=curSymIndex+2;
        if (nextSymIndex>MAX_SYMBOLS) nextSymIndex=MAX_SYMBOLS;
        if (nextNextSymIndex>MAX_SYMBOLS) nextNextSymIndex=MAX_SYMBOLS;
      }
    }

  } else {
    printf("This is NOT a roman number");
  }
}

int abacus_get_count(Abacus *abacus, int index)
{
  if (index < MAX_SYMBOLS && index>=0){
    return abacus->count[index];
  }
  return 0;
}
