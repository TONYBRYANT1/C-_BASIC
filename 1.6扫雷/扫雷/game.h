#include<stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Set_Count 10
//��ʼ������:
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//������ʱ��Ҫʡ��ֻ��ʡ��ROWS
//��ӡ����:
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//������:
void SetMine(char board[ROWS][COLS], int row, int col);
//ɨ��:
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

