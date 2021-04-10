#include <stdio.h>

#define DEFUALT_POINT 110
#define ADDPOINT_FLAG 'a'
#define REMOVEPOINT_FLAG 'r'
#define POINT_TO_ADD 3
#define POINT_TO_REMOVE 6

static int gamePoint = DEFUALT_POINT;

int currentGPoint(void)
{
  return gamePoint;
}

void displayGPoint(void)
{
  printf("\nGame Point: %i\n", gamePoint);
}

void updateGPoint(char flag, int pointValue)
{
  if(flag == ADDPOINT_FLAG) {
    gamePoint += pointValue;
    return;
  }
  
  if(flag == REMOVEPOINT_FLAG) {
    gamePoint -= pointValue;
    return;
  }
}