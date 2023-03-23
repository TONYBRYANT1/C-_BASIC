#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//��ʼ������:
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
//��ӡ����:
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Set_Count;
	while (count)
	{
		int x = (rand() % row) + 1;//rand()%9-----0~8
		int y = (rand() % col) + 1;//rand()%9-----0~8
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}



//'3'-'0'=3
int Get_Mine_Count(char mine[ROWS][COLS],int x,int y)
{
	return (mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1]-8*'0');
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- Set_Count)
	{
			printf("���������Ų��׵�����:>");
			scanf("%d%d", &x, &y);
			//�ж�����Ϸ���:
			if ((x >= 1 && x <= row) && (y >= 1 && y <= col))//�Ϸ�����
			{
				if (mine[x][y] =='1')//����һ����=��������
				{
					printf("�����ˣ����ˣ�����\n");
					DisplayBoard(mine, row, col);
					break;
				}
				else//������
				{
					//�ж���Χ�м�����
					int count = Get_Mine_Count(mine, x, y);
					show[x][y] = count + '0';
					DisplayBoard(show, row, col);
					win++;
				}
			}
			else
			{
				printf("���겻�Ϸ������������룡\n");
			}
	}
	if (win == row * col - Set_Count)
	{
		printf("���׳ɹ�������\n");
	}
	       
}

//չ������---�ݹ�
//1.��λ��û����
//2.��λ�õĸ���ͬ��û����
//2--->1--->2....

