#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cxe_logger.h"
#include "shuffleWordList.h"
#include "makeCringeWord.h"
#include "parseUserInput.h"

#define BYTE_FOR_NEWLINE 1

void printCringeWord(char *cringeWord)
{
  printf("\nWhat is the correct form of '%s'?\n", cringeWord);
}

void printUserGuess(char *userGuess)
{
  printf("\nYour corrected word is %s\n", userGuess);
}

void checkForCorrectGuess(char *userGuess, char *orginalWord)
{
  if(strcmp(orginalWord, userGuess) == 0) 
  {
    printf("Nice! you correct the word \n");
   } else {
      printf("Oops you loose\n");
      printf("Answer is %s\n", orginalWord);
      printf("Ok lets play again\n");
    }
}

void presentWords(char **wordList, int totalStoredWords) 
{
  int currentIndex = 0;
  while(currentIndex != totalStoredWords) 
  {
    char *p_CringeWord = makeCringeWord(wordList[currentIndex]);
    printCringeWord(p_CringeWord);
    
    int allowedWordLength = strlen(wordList[currentIndex]) + 3;
    
    char userGuessBuffer[allowedWordLength + BYTE_FOR_NEWLINE];
    char *userGuess = parseUserInput("Your gussed word?", userGuessBuffer, sizeof(userGuessBuffer));
    
    if(strcmp(userGuess, "quit") == 0)
    {
      printf("Quitting game...\n");
      break;
    }
    
    printUserGuess(userGuess);
    checkForCorrectGuess(&userGuess, wordList[currentIndex]);
    
    
    free(userGuess);
    userGuess = NULL;
    
    currentIndex++;
  }
}

void displayInstructions()
{
  printf("\t\tHOW TO PLAY:\n");
  printf("A random word will be given to you with shuffled letters and you have to correct the word by guessing.\n");
    
  printf ("\n[NOTE]: You can quit game anytime by typing 'quit'\n");
    
  printf("\n\t\tBEST OF LUCK\n");
}

void startGame() {
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
};