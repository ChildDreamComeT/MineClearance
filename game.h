#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define EASY_COUNT 5 
#define ROW 5
#define COL 5

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col, int count);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
