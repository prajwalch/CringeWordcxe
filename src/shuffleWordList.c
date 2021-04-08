#include "generateRandomIndex.h"

void shuffleWordList(char **wordList, int totalStoredWords) {
  int index = totalStoredWords;
  for(; index > 0; index--) {
    int randomIndex = generateRandomIndex(index + 1);
    
    if(index == randomIndex)
      randomIndex = (randomIndex + 1) % totalStoredWords;
    
    char *tempOfLast = wordList[index];
    wordList[index] = wordList[randomIndex];
    wordList[randomIndex] = tempOfLast;
  }
}
