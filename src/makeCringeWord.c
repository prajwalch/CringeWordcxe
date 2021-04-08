#include <stdlib.h>
#include "generateRandomIndex.h"

#define NEWLINE_BYTE 1
#define EXTRA_BYTE 1

void makeCringeWord(char *word, size_t buff_size)
{
  int wordLength = buff_size - NEWLINE_BYTE;
  int index = wordLength - EXTRA_BYTE;

  for(; index > 0; index--) {
    int randomIndex = generateRandomIndex(index + EXTRA_BYTE);
    if (randomIndex == index)
    {
      randomIndex = (randomIndex + EXTRA_BYTE) % wordLength;
    }
    
    char tempOfLast = word[index];
    word[index] = word[randomIndex];
    word[randomIndex] = tempOfLast;
  }
}
