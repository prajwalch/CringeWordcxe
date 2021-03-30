#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cxe_logger.h"
#include "shuffleWordList.h"
#include "makeCringeWord.h"
#include "parseUserInput.h"

#define EXTRA_ALLOWED_BYTE 3
#define BYTE_FOR_NEWLINE 1

void displayInstructions(void);
void presentWords(char **wordList, int totalStoredWords);
void printCringeWord(char *cringeWord);
char *takeUserInput(int orginalWordLength);
void printUserGuess(char **userGuess);
void checkForCorrectGuess(char **p_OrginalWord, char **p_UserGuess);


void startGame(void) {
  const char *wordList[] = { 
    "internet", 
    "generate",
    "mechanical",
    "giraffe",
    "kangaroo",
    "smartphone",
    "national",
    "anthem",
    "ocean",
    "car", 
    "bus", 
    "battle", 
    "apple", 
    "mango", 
    "elephant", 
    "electronic", 
    "paper", 
    "house", 
    "people", 
    "soccer", 
    "keyboard",
    "programming",
    "program", 
    "code", 
    "project",
    "manager",
    "management",
    "bill",
    "scissors",
    "anterior",
    "nest",
    "happy",
    "disgusting",
    "paranormal",
    "disappointed",
    "leopard",
    "fuel",
    "kitchen",
    "mars",
    "bathroom",
    "neighbor",
    "family",
    "knife",
    "dictionary",
    "travel",
    "multimedia",
    "multilingual",
    "restricted",
    "restrictions",
    "rotation",
    "triangle",
    "pythagorean",
    "location",
    "vibrate",
    "helpful",
    "reality",
    "realistic",
    "oxygen"
  };
  displayInstructions();
  
  int totalStoredWords = sizeof(wordList) / sizeof(wordList[0]);
  shuffleWordList(wordList, totalStoredWords);
  presentWords(wordList, totalStoredWords - 1);
}

void displayInstructions(void)
{
  printf("\t\tHOW TO PLAY:\n");
  printf("A random word will be given to you with shuffled letters and you have to correct the word by guessing.\n");
  printf ("\n[NOTE]: You can quit game anytime by typing 'quit'\n");
  printf("\n\t\tBEST OF LUCK\n");
}

void presentWords(char **wordList, int totalStoredWords) 
{
  int currentIndex = 0;
  while(currentIndex != totalStoredWords) 
  {
    const *p_OrginalWord = wordList[currentIndex];
    char *p_CringeWord = makeCringeWord(p_OrginalWord);
    printCringeWord(p_CringeWord);
    
    char *p_UserGuess = takeUserInput(strlen(p_OrginalWord));
    
    if(strcmp(p_UserGuess, "quit") == 0)
    {
      printf("\n[cw]: Resetting all game data...\n");
      free(p_UserGuess);
      p_UserGuess = NULL;
      printf("[cw]: Resetting done...\n");
      printf("[cw]: Quitting game...\n\n");
      break;
    }
    
    printUserGuess(&p_UserGuess);
    checkForCorrectGuess(&p_OrginalWord, &p_UserGuess);
    
    
    free(p_UserGuess);
    p_UserGuess = NULL;
    
    currentIndex++;
  }
}

void printCringeWord(char *cringeWord)
{
  printf("\nWhat is the correct form of '%s'?\n", cringeWord);
}

char *takeUserInput(int orginalWordLength)
{
  int allowedWordLength = orginalWordLength + EXTRA_ALLOWED_BYTE;
    
  char userInputBuffer[allowedWordLength + BYTE_FOR_NEWLINE];
  return parseUserInput(NULL, userInputBuffer, sizeof(userInputBuffer));
}

void printUserGuess(char **userGuess)
{
  printf("\nYour corrected word is %s\n", *userGuess);
}

void checkForCorrectGuess(char **p_OrginalWord, char **p_UserGuess)
{
  if(strcmp(*p_OrginalWord, *p_UserGuess) == 0) 
  {
    printf("Nice! you corrected the word \n");
  }
  else 
  {
    printf("Oops you loose\n");
    printf("Answer is %s\n", *p_OrginalWord);
    printf("Ok lets play again\n");
  }
}