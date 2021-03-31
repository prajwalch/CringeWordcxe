#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cxe_logger.h"
#include "shuffleWordList.h"
#include "makeCringeWord.h"
#include "parseUserInput.h"

#define BYTE_FOR_NEWLINE 1

void displayInstructions(void);
void presentWords(char **wordList, int totalStoredWords);
void printCringeWord(const char *cringeWord);
void printUserGuess(const char *userGuess);
void checkForCorrectGuess(char *p_OrginalWord, char *userGuess);


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
    const char *p_OrginalWord = wordList[currentIndex];
    
    char cringeWord[strlen(p_OrginalWord) + 1];
    makeCringeWord(cringeWord, p_OrginalWord, sizeof(cringeWord));
    printCringeWord(cringeWord);
    
    char userGuess[strlen(p_OrginalWord) + BYTE_FOR_NEWLINE];
    parseUserInput(NULL, userGuess, sizeof(userGuess));
    
    if(strcmp(userGuess, "quit") == 0)
    {
      printf("\n[cw]: Resetting all game data...\n");
      printf("[cw]: Resetting done...\n");
      printf("[cw]: Quitting game...\n\n");
      break;
    }
    
    printUserGuess(userGuess);
    checkForCorrectGuess(p_OrginalWord, userGuess);
    
    currentIndex++;
  }
}

void printCringeWord(const char *cringeWord)
{
  printf("\nWhat is the correct form of '%s'?\n", cringeWord);
}

void printUserGuess(const char *userGuess)
{
  printf("\nYour corrected word is %s\n", userGuess);
}

void checkForCorrectGuess(char *p_OrginalWord, char *userGuess)
{
  if(strcmp(p_OrginalWord, userGuess) == 0) 
  {
    printf("Nice! you corrected the word \n");
  }
  else 
  {
    printf("Oops you loose\n");
    printf("Answer is %s\n", p_OrginalWord);
    printf("Ok lets play again\n");
  }
}