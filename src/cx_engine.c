#include <stdbool.h>
#include "cxe_mainMenu.h"
#include "cxe_readLine.h"
#include "cxe_logger.h"



void startEngine(void (*startGame)(), void (*aboutGame)()) {
  bool shouldShutdown = false;
  
  do {
    displayMainMenu();
    
    char userRawInput[2] = { 0 };
    long userChoosenMenu = readLine("Your choice", userRawInput, sizeof(userRawInput));
    
    switch(userChoosenMenu) {
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
    }
  } while(!shouldShutdown);
}