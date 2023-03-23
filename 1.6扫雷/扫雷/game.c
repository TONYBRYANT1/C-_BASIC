#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//初始化雷盘:
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
//打印雷盘:
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
			printf("请你输入排查雷的坐标:>");
			scanf("%d%d", &x, &y);
			//判断坐标合法性:
			if ((x >= 1 && x <= row) && (y >= 1 && y <= col))//合法坐标
			{
				if (mine[x][y] =='1')//少了一个‘=’搞死人
				{
					printf("你无了，寄了！！！\n");
					DisplayBoard(mine, row, col);
					break;
				}
				else//不是雷
				{
					//判断周围有几个雷
					int count = Get_Mine_Count(mine, x, y);
					show[x][y] = count + '0';
					DisplayBoard(show, row, col);
					win++;
				}
			}
			else
			{
				printf("坐标不合法，请重新输入！\n");
			}
	}
	if (win == row * col - Set_Count)
	{
		printf("排雷成功！！！\n");
	}
	       
}

//展开功能---递归
//1.该位置没有雷
//2.该位置的附近同样没有雷
//2--->1--->2....

