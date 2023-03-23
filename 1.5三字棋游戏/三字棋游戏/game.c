#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
//�����Ķ���
//1.initialization--board��ʼ������
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
//��������:
//       a | a | a          |-   1   |   |   
//      ---|---|---         |-   2---|---|---
//       a | a | a    ---->      3   |   |      -|
//      ---|---|---              4---|---|---   -|
//       a | a | a               5   |   |  
//      ---|---|---(X)           6---|---|---(X)

//2.չ������
void Displayboard(char board[ROW][COL], int row, int col)
{
//�������:
//1.�Ӵ��� ---------- ��ROW,COL�ĸı�board�������ȷŴ�
	//����д�Ļ��������ǻ����������(��ROW��COL�ı��ʱ������Ȼ������)
	//int i = 0;
	//for (i = 0; i < row; i++)
	//{
		//1.��ӡһ�е�����
		//(��)printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		//2.��ӡ�ָ���
		//(��)if(i<row-1)
		//(��)printf("---|---|---\n");
	//}
//2.�Ŵ��� ---------- ��ROW,COL�ĸı�board�����ȷŴ�
	int i = 0;
	for (i = 0; i < row; i++)//---------------------����
	{
		//1.��ӡһ�е�����(��ʼ�������)         ��  a | a | a  
	                                             // ---|---|--- ��
		int j = 0;
		for (j = 0; j < col; j++)
		{
			
			printf(" %c ", board[i][j]);

			if (j < col - 1)//------------------------ÿ����Ҳ�����
			{
				printf("|");
			}
		}
		printf("\n");
		//��ӡ�ָ���
		if (i < row - 1)//----------------------------���һ����²����������<<------��Ϊ�ָ���ֻ������
		{

			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//--------------------ÿ����Ҳ�����
				{
					printf("|");
				}
			}
			printf("\n");
		}
		
	}
//��ע�͵���������
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

//3.��Ҳ���
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����>:\n");
	while (1)
	{
		printf("���������>:");
		scanf("%d%d", &x, &y);
		//�ж�������ӵĺϷ���(x,y)
			if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
			{
				if (board[x - 1][y - 1] == ' ')
				{
					board[x - 1][y - 1] = '*';//�������:���'='д��=='
					break;
				}
				else
				{
					printf("�����걻ռ��\n");
				}
			}
			else
			{
				printf("����Ƿ�,����������;\n");
			}
	}
}




//4.���Բ���
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������>:\n");
	//Ϊʲôx,y�����ֵ���ܷ�������???????????????????????????????????????????????
	//int x = rand() % row;
	//int y = rand() % col;
	
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')//ͬʱҪ����board[x][y] == '*',�������µ��屻���Ը���----------------------------------------------------------------------------------
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
			//����δ��
			if (board[i][j] != ' ')
			{
				return 0;
			}
		}
	}
	//��������
	return 1;
}
//5.�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�жϺ����е�
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != ' '))
		{
			return board[i][0];
		}
	}
	//�ж������е�
	int j = 0;
	for (j = 0; j < row; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[0][j] != ' '))
		{
			return board[0][j];
		}
	}
	//�Խ���
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != ' '))
	{
		return board[0][0];
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' '))
	{
		return board[1][1];
	}
	//ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}