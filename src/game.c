#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "cxe_logger.h"
#include "shuffleWordList.h"
#include "makeCringeWord.h"
#include "parseUserInput.h"
#include "gamePoint.h"

#define BYTE_FOR_NULL 1
#define LENGTHOF(list) (sizeof(list)/sizeof(list[0]))

void displayInstructions(void);
void startGameLoop(char **wordList, int totalStoredWords);
void printCringeWord(const char *cringeWord);
void copyWordToCWBuf(char *cwBuffer, const char *orginalWord, size_t buff_size);
void printUserGuess(const char *userGuess);
void checkUserStatus(char *p_OrginalWord, char *userGuess);
bool hasUserWon(char *orginalWord, char *userGuess);


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
  
  int totalStoredWords = LENGTHOF(wordList) - 1; // subtract 1 inorder to start loop from index 0
  shuffleWordList(&wordList, totalStoredWords);
  startGameLoop(&wordList, totalStoredWords);
}

void displayInstructions(void)
{
  printf("\t\tHOW TO PLAY:\n");
  printf("A random word will be given to you with shuffled letters and you have to correct the word by guessing.\n");
  printf ("\n[NOTE]: You can quit game anytime by typing 'quit'\n");
  printf("\n\t\tBEST OF LUCK\n");
}

void startGameLoop(char **wordList, int totalStoredWords) 
{
  int currentIndex = 0;
  while(currentIndex != totalStoredWords)
  {
    if((currentGPoint()) <= 0)
    {
      printf("\nOops!! no more game point that means game over\n");
      break;
    }
    
    displayGPoint();
    
    const char *p_OrginalWord = wordList[currentIndex];
    int wordLengthWNull = strlen(p_OrginalWord) + BYTE_FOR_NULL;
    
    char cringeWord[wordLengthWNull];
    size_t cwBufferSize = sizeof(cringeWord);
    copyWordToCWBuf(cringeWord, p_OrginalWord, cwBufferSize);
    makeCringeWord(cringeWord, cwBufferSize);
    printCringeWord(cringeWord);
    
    char userGuess[wordLengthWNull];
    parseUserInput(NULL, userGuess, sizeof(userGuess));
    
    // check if input is quit command
    if(strcmp(userGuess, "quit") == 0)
    {
      printf("Exiting game...\n");
      break;
    }
    
    printUserGuess(userGuess);
    // check whether user has won or lose
    checkUserStatus(p_OrginalWord, userGuess);
    
    currentIndex++;
  }
}

void printCringeWord(const char *cringeWord)
{
  printf("What is the correct form of '%s'?\n", cringeWord);
}

void copyWordToCWBuf(char *cwBuffer, const char *orginalWord, size_t buff_size)
{
  strncpy(cwBuffer, orginalWord, buff_size);
}

void printUserGuess(const char *userGuess)
{
  printf("\nYour corrected word is %s\n", userGuess);
}

void checkUserStatus(char *p_OrginalWord, char *userGuess)
{
  bool userHasWon = hasUserWon(p_OrginalWord, userGuess);
  
  if(!userHasWon)
  {
    // flag r is remove point
    updateGPoint('r');
    printf("Oops!! you loose\n");
    printf("Correct answer is '%s'\n", p_OrginalWord);
    printf("Let's try to play again\n");
    return;
  }
  
  // flag a is add point
  updateGPoint('a');
  printf("Great, you found the correct word\n");
  printf("Let's try to find another word\n");
  return;
}

bool hasUserWon(char *orginalWord, char *userGuess)
{
  return (strcmp(orginalWord, userGuess)) == 0 ? true : false;
}