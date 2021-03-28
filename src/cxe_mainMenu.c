#include "cxe_logger.h"
void menu();

void displayMainMenu() {
  menu();
}

void menu() {
  Log("--------------------\n");
  Log("|    MAIN MENU     |\n");
  Log("--------------------\n");
  Log("| 1. Start         |\n");
  Log("| 2. About         |\n");
  Log("| 3. Exit          |\n");
  Log("|__________________|\n");
}