#pragma once

typedef void (*triggerFunc_t)();
struct Menu {
  long optionNunber;
  char name[8];
  triggerFunc_t func;
};