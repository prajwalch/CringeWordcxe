#include <stdbool.h>
#include "cxe_mainMenu.h"
#include "cxe_menuStruct.h"
#include "cxe_readLine.h"
#include "cxe_logger.h"

void startGame(void);
void aboutGame(void);
void exitGame(void);


void aboutGame(void) {
  Log("About Game\n");
}

void exitGame(void)
{
  exit(0);
}

#define NUM_OF_MENUS 3

struct Menu menus[NUM_OF_MENUS] = {
  { 1, "Start", startGame},
  { 2, "About", aboutGame},
  { 3, "Exit", exitGame},
};


void startEngine(void) {
  bool shouldShutdown = false;
  
  do {
    displayMainMenu(menus, NUM_OF_MENUS);
    
    char userRawInput[2] = { 0 };
    long userChoosenMenu = readLine("Your choice", userRawInput, sizeof(userRawInput));
    handleMenuTrigger(menus, NUM_OF_MENUS, userChoosenMenu);
    
    /*switch(userChoosenMenu) {
      // start
      case 1:
        startGame();
        break;
      // about
      case 2:
        aboutGame();
        break;
      case 3:
        shouldShutdown = true;
        break;
      // wrong input
      default:
        Log("\nWrong Input\n");
        break;
    }*/
  } while(!shouldShutdown);
}