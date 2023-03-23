#include<stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Set_Count 10
//初始化雷盘:
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//声明的时候要省略只能省略ROWS
//打印雷盘:
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//布置雷:
void SetMine(char board[ROWS][COLS], int row, int col);
//扫雷:
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

