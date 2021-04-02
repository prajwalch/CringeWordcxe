#include <string.h>
#include "shuffleLetters.h"

void makeCringeWord(char *cwBuffer, char *orginalWord, size_t buffer_size)
{
  strncpy(cwBuffer, orginalWord, buffer_size);
  
  shuffleLetters(cwBuffer, buffer_size);
}
