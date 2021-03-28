#include "generateRandomIndex.h"

void useFYShuffle(char **dataToShuffle, int lengthOfData) {
  
  // int lengthOfData = sizeof(dataToShuffle) / sizeof(dataToShuffle[0]);
  
  int index = 0;
  for(index = lengthOfData - 1; index > 0; index--) {
    int randomIndex = generateRandomIndex(index + 1);
    
    if(index == randomIndex)
      randomIndex = (randomIndex + 1) % lengthOfData;
    
    char *tempOfLast = dataToShuffle[index];
    dataToShuffle[index] = dataToShuffle[randomIndex];
    dataToShuffle[randomIndex] = tempOfLast;
  }
}
