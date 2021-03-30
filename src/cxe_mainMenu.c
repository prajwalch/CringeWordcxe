#include "cxe_logger.h"
#include "cxe_menuStruct.h"

void displayMainMenu(struct Menu *menus, int totalMenus)
{
  Log("--------------------\n");
  Log("     MAIN MENU      \n");
  Log("--------------------\n");
  
  int index = 0;
  for (index; index < totalMenus; index++)
  {
    printf("%i. %s\n", menus[index].optionNunber, menus[index].name);
  }
  Log("--------------------\n");
}

void handleMenuTrigger(struct Menu *menus, int totalMenus, long userChoosenMenu)
{
  int index = 0;
  for (index; index < totalMenus; index++)
  {
    if(userChoosenMenu == menus[index].optionNunber)
    {
      menus[index].func();
      return;
    }
  }
  printf("\nWrong input\n\n");
}