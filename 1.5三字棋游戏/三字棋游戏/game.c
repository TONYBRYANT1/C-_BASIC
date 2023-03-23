#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//函数的定义
//1.initialization--board初始化棋盘
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//理想棋盘:
//       a | a | a          |-   1   |   |   
//      ---|---|---         |-   2---|---|---
//       a | a | a    ---->      3   |   |      -|
//      ---|---|---              4---|---|---   -|
//       a | a | a               5   |   |  
//      ---|---|---(X)           6---|---|---(X)

//2.展览棋盘
void Displayboard(char board[ROW][COL], int row, int col)
{
//代码理解:
//1.劣代码 ---------- 随ROW,COL的改变board不能正比放大
	//这样写的坏处是行是活的列是死的(当ROW和COL改变的时候列仍然是三列)
	//int i = 0;
	//for (i = 0; i < row; i++)
	//{
		//1.打印一行的数据
		//(劣)printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		//2.打印分割行
		//(劣)if(i<row-1)
		//(劣)printf("---|---|---\n");
	//}
//2.优代码 ---------- 随ROW,COL的改变board能正比放大
	int i = 0;
	for (i = 0; i < row; i++)//---------------------层数
	{
		//1.打印一行的数据(开始列向进行)         “  a | a | a  
	                                             // ---|---|--- ”
		int j = 0;
		for (j = 0; j < col; j++)
		{
			
			printf(" %c ", board[i][j]);

			if (j < col - 1)//------------------------每层的右侧限制
			{
				printf("|");
			}
		}
		printf("\n");
		//打印分割线
		if (i < row - 1)//----------------------------最后一层的下侧的总体限制<<------因为分割线只打两行
		{

			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//--------------------每层的右侧限制
				{
					printf("|");
				}
			}
			printf("\n");
		}
		
	}
//无注释的完整代码
	/*int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col-1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}*/
}

//3.玩家操作
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走>:\n");
	while (1)
	{
		printf("请玩家落子>:");
		scanf("%d%d", &x, &y);
		//判断玩家落子的合法性(x,y)
			if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
			{
				if (board[x - 1][y - 1] == ' ')
				{
					board[x - 1][y - 1] = '*';//错误操作:误把'='写成=='
					break;
				}
				else
				{
					printf("改坐标被占用\n");
				}
			}
			else
			{
				printf("坐标非法,请重新输入;\n");
			}
	}
}




//4.电脑操作
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走>:\n");
	//为什么x,y的随机值不能放在这里???????????????????????????????????????????????
	//int x = rand() % row;
	//int y = rand() % col;
	
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')//同时要加上board[x][y] == '*',以免你下的棋被电脑覆盖----------------------------------------------------------------------------------
		{
			board[x][y] = '#';
			break;
		}
	}
}


int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			//棋盘未满
			if (board[i][j] != ' ')
			{
				return 0;
			}
		}
	}
	//棋盘已满
	return 1;
}
//5.判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断横三行等
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != ' '))
		{
			return board[i][0];
		}
	}
	//判断竖三列等
	int j = 0;
	for (j = 0; j < row; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[0][j] != ' '))
		{
			return board[0][j];
		}
	}
	//对角线
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != ' '))
	{
		return board[0][0];
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' '))
	{
		return board[1][1];
	}
	//平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}