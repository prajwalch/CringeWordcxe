#include <stdlib.h>
#include <time.h>
#include "cxe_logger.h"
#include "cx_engine.h"

void startGame();
void aboutGame();

int main(void) {
  srand((unsigned)time(0));
  startEngine(&startGame, &aboutGame);
  return 0;
}

void aboutGame() {
  Log("About Game\n");
}
