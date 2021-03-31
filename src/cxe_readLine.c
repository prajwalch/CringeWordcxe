#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cxe_logger.h"
#include "cxe_readLineUtils.h"

#define FAKE_BYTE 1
#define BYTE_OF_NEWLINE 1

long parseInputAsInt(char *input);

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
    if(isBufferOverflow(inputBuffer)) 
    {
      flushInputBuffer();
      setInputToNull(&p_Input);
      printf("Its not allowed to enter more then %i input\n", (strlen(inputBuffer) - BYTE_OF_NEWLINE));
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
    
    return parseInputAsInt(p_Input);
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

bool isBufferOverflow(char *inputBuffer) 
{
  if(inputBuffer[strlen(inputBuffer) - BYTE_OF_NEWLINE] != '\n')
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

long parseInputAsInt(char *input) 
{
  char *p_End = NULL;
  long convertedBuffer = strtol(input, &p_End, 0);
    
  if(input == p_End) 
  {
    input[strlen(input) - BYTE_OF_NEWLINE] = '\0';
    printf("Error converting inputBuffer\n");
  }
  return convertedBuffer;
}