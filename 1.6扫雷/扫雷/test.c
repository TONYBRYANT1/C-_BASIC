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
	printf("ɨ��\n");
	//�׵���Ϣ����
	//1.���úõ��׵���Ϣ:
	char mine[ROWS][COLS] = { '0' };//11*11
	//2.�Ų�����׵���Ϣ:
	char show[ROWS][COLS] = { '0' };//11*11-------ͬ�����ó�11*11����>��mine��show���õĶ�Ӧ
	//��ʼ������:
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ���̣�
	//DisplayBoard(mine, ROW, COL); 
	DisplayBoard(show, ROW, COL);
	//������:
	SetMine(mine, ROW, COL);//----------------������������ʱ���������9*9
	//DisplayBoard(mine, ROW, COL);//������ʱ����
	//ɨ��:
	FindMine(mine, show, ROW, COL);
}
void test() 
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룡");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}