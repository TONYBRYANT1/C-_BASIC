//��������ļ�������game.h,�Ͳ��������������ļ���
//#define����ĳ�������������ͷ�ļ����
#define ROW 3
#define COL 3
//ͷ�ļ��ܶ���
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//����
void Initboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
// '*��-----���Ӯ
// '#' -----����Ӯ
// 'Q' -----ƽ��
// 'C' -----����
char IsWin(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);