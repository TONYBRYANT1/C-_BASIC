#define _CRT_SECURE_NO_WARNINGS
//��������Ϸ����
#include"game.h"
void menu()
{
	printf("*************************************\n");
	printf("*****1.play               0.exit*****\n");
	printf("*************************************\n");
}
//��Ϸ�������㷨ʵ��
void game()
{
	//����---�߳���������Ϣ
	char board[ROW][COL] = {0};//----ͷ�ļ�game.h�еĶ���  Ҫ��ͷ�ļ�
	//��ʼ������
	Initboard(board,ROW,COL);
	//��ӡ����
	Displayboard(board,ROW,COL);
	//����
	char ret = '*';//Ҫ��ret���game()�������ȫ�ֱ����������ж����Ӯ������Ӯ������ƽ��
	while (1)
	{
		//char ret = '*';
		PlayerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret=IsWin(board, ROW, COL);
		if (ret!='C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ 
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
	}
	if (ret == '*')
		{
			printf("���Ӯ\n");
		}
		else if (ret == '#')
		{
			printf("����Ӯ\n");
		}
		else if(ret=='Q')
		{
			printf("ƽ��\n");
		}
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	//��Ҫ����Щ��������do while֮ǰ:�ᵼ����ѭ��:
	//menu();
	//printf("��ѡ��>:");
	//scanf("%d", &input);
	do {
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			printf("����Ϸ\n");
			game();
			break;
		default:
			printf("�������,������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}