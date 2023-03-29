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
	int a = 0;
	int input = 0;
	//创建通讯录:
	struct Contact con;//con就是一个通讯录，其中包含:1000人信息(data)and已存信息的个数(size)
	struct PeoInFo* pd =(con.data);//pd的值为&(con.data)
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
			printf("你想按什么排序?\n");
			printf("1.NAME		2.AGE		3.SEX		4.TELE		5.ADDR\n");
			printf("请输入序号:");
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
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}
//contact--1.size
		 //2.1000个成员信息