#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#define EASY 10

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char stick);
void PrintBoard(char arr[ROWS][COLS], int rows, int cols);
void SetBoomb(char arr[ROWS][COLS], int rows, int cols, int count);
void FindBoomb(char arr1[ROWS][COLS],char arr2[ROWS][COLS], int rows, int cols);
