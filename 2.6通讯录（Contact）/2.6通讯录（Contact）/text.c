#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//����:
//1.���1000�����ѵ���Ϣ:
//���֣����䣬�Ա𣬵绰��סַ
//2.���� 3.ɾ�� 4.�Ķ� 5.��ѯ 6.��ӡ 7.���� ������Ϣ
void menu()
{
	printf("##################################################\n");
	printf("######        1.add           2.delete      ######\n");
	printf("######        3.modify        4.search      ######\n");
	printf("######        5.show          6.sort        ######\n");
	printf("######        0.exit                        ######\n");
	printf("##################################################\n");
}
int main()
{
	int a = 0;
	int input = 0;
	//����ͨѶ¼:
	struct Contact con;//con����һ��ͨѶ¼�����а���:1000����Ϣ(data)and�Ѵ���Ϣ�ĸ���(size)
	struct PeoInFo* pd =(con.data);//pd��ֵΪ&(con.data)
	//��ʼ��ͨѶ¼:
	InitContact(&con);
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		//ö�ٿ�����ߴ���Ŀɶ���:
		switch (input)
		{
		case EXIT:
			printf("�˳�\n");
			break;
		case ADD:
			AddContact(&con);
			break;
		case DELETE:
			DeleteContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SEARCH:
			SesrchContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			printf("���밴ʲô����?\n");
			printf("1.NAME		2.AGE		3.SEX		4.TELE		5.ADDR\n");
			printf("���������:");
			scanf("%d", &a);
			switch (a-1)
			{
			case NAME:
				ContactSort(pd, con.size, sizeof(con.data[0]), cmp1);
				break;
			case AGE:
				ContactSort(pd, con.size, sizeof(con.data[0]), cmp2);
				break;
			case SEX:
				ContactSort(pd, con.size, sizeof(con.data[0]), cmp3);
				break;
			case TELE:
				ContactSort(pd, con.size, sizeof(con.data[0]), cmp4);
				break;
			case ADDR:
				ContactSort(pd, con.size, sizeof(con.data[0]), cmp5);
				break;
			}
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}
//contact--1.size
		 //2.1000����Ա��Ϣ