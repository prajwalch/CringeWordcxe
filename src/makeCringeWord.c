#include <string.
#include "shuffleLetters.h"

void makeCringeWord(char *cwBuffer, char *orginalWord, size_t buffer_size)
{
  strncpy(cwBuffer, orginalWord, buffer_size);
  printf("test %s\n", cwBuffer);
  
  shuffleLetters(cwBuffer, strlen(cwBuffer));
}
