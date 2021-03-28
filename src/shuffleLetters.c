#include "generateRandomIndex.h"

void shuffleLetters(char *word, int lengthOfWord)
{
  int index = 0;
  for(index = lengthOfWord - 1; index > 0; index--) {
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
