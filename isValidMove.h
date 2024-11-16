#ifndef isValidMove_h
#define isValidMove_h

#include <stdio.h>
#include <stdbool.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

bool isWithinBoard(int x, int y);

int isSingleStep(const int board[], int startX, int startY, int endX, int endY);

int isJump(const int board[], int startX, int startY, int endX, int endY, int visited[9][9]);

void makeMove(int board[], int startX, int startY, int endX, int endY);

int isValidMove(const int board[], int move, int player, int visited[9][9]);

#endif /* isValidMove_h */
