#include <stdlib.h>

char *storeWordForShuffle(char *p_OrginalWord, int lengthOfWord)
{
  char *p_WordToShuffle = malloc(strlen(p_OrginalWord) + 1);
  
  if(p_WordToShuffle == NULL) {
    printf("Error creating storage for cringe word\n");
  }
  
  strcpy(p_WordToShuffle, p_OrginalWord);
  return p_WordToShuffle;
}