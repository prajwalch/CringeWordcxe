#pragma once
#include <stdbool.h>

#define FAKE_BYTE 1
#define BYTE_OF_NEWLINE 1

void displayPrompt(char *prompt);
bool isNullInput(char **p_Input);
bool isBufferOverflow(char *inputBuffer, int bufferLastIndex);
void flushInputBuffer(void);
void setInputToNull(char **p_Input);