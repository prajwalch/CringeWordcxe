#include <stdlib.h>
#include <time.h>
#include "cx_engine.h"

int main(int argc, char *argv[]) {
  srand((unsigned)time(0));
  startEngine();
  return 0;
}
