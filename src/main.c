#include <stdlib.h>
#include <time.h>
#include "cxe_logger.h"
#include "cx_engine.h"

int main(void) {
  srand((unsigned)time(0));
  startEngine();
  return 0;
}
