#pragma once
#include "cxe_menuStruct.h"



void displayMainMenu(struct Menu *menus, int numOfMenus);
void handleMenuTrigger(struct Menu *menus, int totalMenus, long userChoosenMenu);