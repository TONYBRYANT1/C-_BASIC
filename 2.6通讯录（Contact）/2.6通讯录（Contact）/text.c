#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//功能:
//1.存放1000个好友的信息:
//名字，年龄，性别，电话，住址
//2.增加 3.删除 4.改动 5.查询 6.打印 7.排序 好友信息
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
	//创建通讯录:
	struct Contact con;//con就是一个通讯录，其中包含:1000人信息(data)and已存信息的个数(size)
	//初始化通讯录:
	InitContact(&con);
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		//枚举可以提高代码的可读性:
		switch (input)
		{
		case EXIT:
			printf("退出\n");
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
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}