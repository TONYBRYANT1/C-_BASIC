#define _CRT_SECURE_NO_WARNINGS
//三字棋游戏测试
#include"game.h"
void menu()
{
	printf("*************************************\n");
	printf("*****1.play               0.exit*****\n");
	printf("*************************************\n");
}
//游戏的整个算法实现
void game()
{
	//数组---走出的棋盘信息
	char board[ROW][COL] = {0};//----头文件game.h中的定义  要引头文件
	//初始化棋盘
	Initboard(board,ROW,COL);
	//打印棋盘
	Displayboard(board,ROW,COL);
	//下棋
	char ret = '*';//要把ret变成game()函数里的全局变量，才能判断玩家赢，电脑赢，还是平局
	while (1)
	{
		//char ret = '*';
		PlayerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//判断玩家是否赢
		ret=IsWin(board, ROW, COL);
		if (ret!='C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//判断电脑是否赢 
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
	}
	if (ret == '*')
		{
			printf("玩家赢\n");
		}
		else if (ret == '#')
		{
			printf("电脑赢\n");
		}
		else if(ret=='Q')
		{
			printf("平局\n");
		}
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	//不要将这些东西放在do while之前:会导致死循环:
	//menu();
	//printf("请选择>:");
	//scanf("%d", &input);
	do {
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			printf("玩游戏\n");
			game();
			break;
		default:
			printf("输入错误,请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}