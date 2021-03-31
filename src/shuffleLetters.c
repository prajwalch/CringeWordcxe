#include "generateRandomIndex.h"

// one extra byte inorder to count from 0
#define NULLBYTE_AND_EXTRABYTE 2

void shuffleLetters(char *word, int lengthOfWord)
{
  int index = 0;
  for(index = lengthOfWord - NULLBYTE_AND_EXTRABYTE; index > 0; index--) {
    int randomIndex = generateRandomIndex(index + 1);
    if (randomIndex == index)
    {
      randomIndex = (randomIndex + 1) % lengthOfWord;
    }
    
    char tempOfLast = word[index];
    word[index] = word[randomIndex];
    word[randomIndex] = tempOfLast;
  }
}
