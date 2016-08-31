#include <stdlib.h>
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
  Abacus *abacus=NULL;
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
  if (validlen != length)
  {
    printf("This is NOT a roman number");
    return;
  }

  while (curSymIndex < MAX_SYMBOLS)
  {
    if (numIndex > length) break;
    if (romannumeral[numIndex] == abacus->symbols[curSymIndex])
    {
      ++abacus->count[curSymIndex];
      ++numIndex;
      continue;
    }
    if (romannumeral[numIndex+1] == abacus->symbols[curSymIndex]) {
      if (romannumeral[numIndex] == abacus->symbols[nextSymIndex])
      {
          if (abacus->multi[curSymIndex]) {
            ++abacus->count[nextSymIndex];
          } else {
            abacus->count[nextSymIndex]=abacus->count[nextSymIndex]+4;
          }
          curSymIndex=nextSymIndex+1;
      } else if (romannumeral[numIndex] == abacus->symbols[nextNextSymIndex]) {
        if (abacus->multi[curSymIndex]) {
          ++abacus->count[nextSymIndex];
          abacus->count[nextNextSymIndex]=abacus->count[nextNextSymIndex]+4;
          curSymIndex=nextNextSymIndex+1;
        }
      }
      numIndex=numIndex+2;
    } else {
      ++curSymIndex;
    }
    nextSymIndex=curSymIndex+1;
    nextNextSymIndex=curSymIndex+2;
    if (nextSymIndex>MAX_SYMBOLS) nextSymIndex=MAX_SYMBOLS;
    if (nextNextSymIndex>MAX_SYMBOLS) nextNextSymIndex=MAX_SYMBOLS;
  }
}

int abacus_get_count(Abacus *abacus, int index)
{
  if (index < MAX_SYMBOLS && index>=0){
    return abacus->count[index];
  }
  return 0;
}

// Caller must free the char* pointer.
char *abacus_get_result(Abacus *abacus)
{
  int curSymIndex = 0;
  int nextSymIndex = curSymIndex+1;
  int prevSymIndex=0;
  int resultIndex=0;
  int countIndex=0;
  // the resultString will be less than MAX_RESULT_LENGTH
  char *resultString=malloc(sizeof(char)*MAX_RESULT_LENGTH);
  // set the contents to zeros so we always have a null terminated string.
  memset(resultString, '\0', sizeof(resultString));

  while (curSymIndex < MAX_SYMBOLS)
  {
    if (abacus->count[curSymIndex] == 0)
    {
      curSymIndex++;
      prevSymIndex=curSymIndex-1;
      nextSymIndex=curSymIndex+1;
      if (nextSymIndex>MAX_SYMBOLS) nextSymIndex=MAX_SYMBOLS;
      continue;
    }
    if (curSymIndex == 0)
    {
      for (countIndex=0;countIndex<abacus->count[curSymIndex];++countIndex)
      {
        resultString[resultIndex]=abacus->symbols[curSymIndex];
        resultIndex++;
      }
      curSymIndex++;
      prevSymIndex=curSymIndex-1;
      nextSymIndex=curSymIndex+1;
      if (nextSymIndex>MAX_SYMBOLS) nextSymIndex=MAX_SYMBOLS;
      continue;
    }
    if (abacus->multi[curSymIndex])
    {
      if (abacus->count[curSymIndex] == 4)
      {
        resultString[resultIndex]=abacus->symbols[curSymIndex];
        resultIndex++;
        resultString[resultIndex]=abacus->symbols[prevSymIndex];
        resultIndex++;
      } else {
        for (countIndex=0;countIndex<abacus->count[curSymIndex];++countIndex)
        {
          resultString[resultIndex]=abacus->symbols[curSymIndex];
          resultIndex++;
        }
      }
      curSymIndex++;
      prevSymIndex=curSymIndex-1;
      nextSymIndex=curSymIndex+1;
      if (nextSymIndex>MAX_SYMBOLS) nextSymIndex=MAX_SYMBOLS;
      continue;
    }
    if (!abacus->multi[curSymIndex])
    {
      if (abacus->count[nextSymIndex] == 4)
      {
        resultString[resultIndex]=abacus->symbols[nextSymIndex];
        resultIndex++;
        resultString[resultIndex]=abacus->symbols[prevSymIndex];
        resultIndex++;
        curSymIndex=curSymIndex+2;
      } else {
        resultString[resultIndex]=abacus->symbols[curSymIndex];
        resultIndex++;
        curSymIndex++;
      }
      prevSymIndex=curSymIndex-1;
      nextSymIndex=curSymIndex+1;
      if (nextSymIndex>MAX_SYMBOLS) nextSymIndex=MAX_SYMBOLS;
      continue;
    }
  }
  return resultString;
}

void abacus_add_value(Abacus *abacus, char *romannumeral)
{
  int index;
  int carry;
  Abacus *tmpAbacus=NULL;
  tmpAbacus = abacus_create();
  abacus_init_value(tmpAbacus,romannumeral);
  for (index=0;index<MAX_SYMBOLS;++index)
  {
    abacus->count[index]+=tmpAbacus->count[index];
  }

  abacus_free(tmpAbacus);
}
