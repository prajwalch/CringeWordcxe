#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cxe_logger.h"
#include "cxe_readLineUtils.h"

long parseInputAsInt(char *inputBuffer, int bufferLastIndex);

long readLine(char *prompt, char *inputBuffer , size_t size) 
{
  char *p_Input = NULL;
  
  while(p_Input == NULL) 
  {
    // display prompt
    displayPrompt(prompt);
    
    // take input
    p_Input = fgets(inputBuffer, size + FAKE_BYTE, stdin);
    // check for null
    if(isNullInput(&p_Input)) 
    {
      printf("Invalid input found\n");
      continue;
    }
    
    // check for overflow
    int bufferLastIndex = strlen(inputBuffer) - BYTE_OF_NEWLINE;
    int allowedWordLength = bufferLastIndex;
    if(isBufferOverflow(inputBuffer, bufferLastIndex)) 
    {
      flushInputBuffer();
      setInputToNull(&p_Input);
      printf("Its not allowed to enter more then %i input\n", allowedWordLength);
      continue;
    }
    
    // check for empty/space input
    if(isspace(inputBuffer[0])) 
    {
      setInputToNull(&p_Input);
      printf("Sorry, can't process empty or space input\n");
      continue;
    }
    
    // check for alphabet
    if(isalpha(inputBuffer[0]))
    {
      setInputToNull(&p_Input);
      printf("Alphabets are also not allowed\n");
      continue;
    }
    
    // check for digit 
    if(!isdigit(inputBuffer[0]))
    {
      setInputToNull(&p_Input);
      printf("Sorry, non of the special characters are allowed\n");
      continue;
    }
    
    return parseInputAsInt(inputBuffer, bufferLastIndex);
  }
}

void displayPrompt(char *prompt) 
{
  if(prompt != NULL) 
  {
    printf("%s\n", prompt);
    printf("> ");
  } else {
    printf("> ");
  }
}

bool isNullInput(char **p_Input) 
{
  if(*p_Input == NULL)
    return true;
  return false;
}

bool isBufferOverflow(char *inputBuffer, int lastIndex) 
{
  if(inputBuffer[lastIndex] != '\n')
    return true;

  return false;
}

void flushInputBuffer(void) 
{
  int ch = 0;
  while(((ch = getchar()) != '\n') && (ch != EOF));
}

void setInputToNull(char **p_Input)
{
  *p_Input = NULL;
}

long parseInputAsInt(char *inputBuffer, int lastIndex) 
{
  char *p_End = NULL;
  long convertedBuffer = strtol(input, &p_End, 0);
    
  if(input == p_End) 
  {
    inputBuffer[lastIndex] = '\0';
    printf("Error converting inputBuffer\n");
  }
  return convertedBuffer;
}