//如果其他文件引用了game.h,就不用引用其他的文件了
//#define定义的常量，把他当成头文件理解
#define ROW 3
#define COL 3
//头文件总定义
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//声明
void Initboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
// '*’-----玩家赢
// '#' -----电脑赢
// 'Q' -----平局
// 'C' -----继续
char IsWin(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);