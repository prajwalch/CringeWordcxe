#include <stdlib.h>

char *storeWordForShuffle(char *p_OrginalWord, int lengthOfWord)
{
  char *p_WordToShuffle = malloc(strlen(p_OrginalWord) + 1);
  strcpy(p_WordToShuffle, p_OrginalWord);
  return p_WordToShuffle;
}