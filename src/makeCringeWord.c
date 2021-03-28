#include <string.h>
#include "storeWordForShuffle.h"
#include "shuffleLetters.h"

char *makeCringeWord(char *orginalWord)
{
  int lengthOfWord = strlen(orginalWord);
  
  char *p_WordToShuffle = storeWordForShuffle(orginalWord, lengthOfWord);
  shuffleLetters(p_WordToShuffle, lengthOfWord);
 return p_WordToShuffle;
}
