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
	int input = 0;
	//����ͨѶ¼:
	struct Contact con;//con����һ��ͨѶ¼�����а���:1000����Ϣ(data)and�Ѵ���Ϣ�ĸ���(size)
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
			SortContact(&con,sizeof(con)/sizeof(con[0]), sizeof(con[0]));
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}