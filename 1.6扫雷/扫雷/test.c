#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("*********************************\n");
	printf("*******1.play       0.exit*******\n");
	printf("*********************************\n");
}
void game()
{
	printf("扫雷\n");
	//雷的信息储存
	//1.布置好的雷的信息:
	char mine[ROWS][COLS] = { '0' };//11*11
	//2.排查出的雷的信息:
	char show[ROWS][COLS] = { '0' };//11*11-------同样设置成11*11——>让mine和show更好的对应
	//初始化雷盘:
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印雷盘：
	//DisplayBoard(mine, ROW, COL); 
	DisplayBoard(show, ROW, COL);
	//布置雷:
	SetMine(mine, ROW, COL);//----------------而真正操作的时候仅仅操作9*9
	//DisplayBoard(mine, ROW, COL);//仅测试时开放
	//扫雷:
	FindMine(mine, show, ROW, COL);
}
void test() 
{
	int input = 0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入！");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}