#pragma once
#include <stdbool.h>

void displayPrompt(char *prompt);
bool isNullInput(char **p_Input);
bool isBufferOverflow(char *inputBuffer);
void flushInputBuffer(void);
void setInputToNull(char **p_Input);