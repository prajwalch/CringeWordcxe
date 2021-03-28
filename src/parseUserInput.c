#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void displayPrompt();
bool isNullInput(char **input);
bool isBufferOverflow(char *inputBuffer);
void flushInputBuffer();
void setInputToNull(char **input);

bool isMixedInput(char *inputBuffer)
{
  int index = 0;
  for(index; index < strlen(inputBuffer); index++)
  {
    if((isdigit(inputBuffer[index])) || (!isalpha(inputBuffer[index])))
    {
      return true;
    }
  }
  return false;
}

char *allocateStorage(char *inputBuffer)
{
  char *convertedBuffer = malloc(strlen(inputBuffer) + 1);
  sscanf(inputBuffer, "%s", convertedBuffer);
  return convertedBuffer;
}

char *parseUserInput(char *prompt, char *inputBuffer , size_t size)
{
  char *input = NULL;
  while(input == NULL)
  {
    displayPrompt(prompt);
    
    input = fgets(inputBuffer, size + 1, stdin);
    
    if(isNullInput(&input)) 
    {
      printf("[ERROR]: Oops!! no any word detect\n");
      continue;
    }
    
    int allowedWordLength = size - 1;
    if(isBufferOverflow(inputBuffer))
    {
      flushInputBuffer();
      setInputToNull(&input);
      printf("[INFO]: More then %i letters are not allowed\n", allowedWordLength);
      continue;
    }
    
    if(isspace(inputBuffer[0])) 
    {
      setInputToNull(&input);
      printf("[ERROR]: Sorry, can't process empty or space input\n");
      continue;
    }
    
    inputBuffer[strlen(inputBuffer) - 1] = '\0';
    
    if(isMixedInput(inputBuffer))
    {
      setInputToNull(&input);
      printf("[ERROR]: You can't mix letter with numbers or any other special characters.\n");
      printf("\n[INFO]: If your trying to input command type help:command to see all available commands.\n\n");
      continue;
    }
    
    return allocateStorage(inputBuffer);
  }
}