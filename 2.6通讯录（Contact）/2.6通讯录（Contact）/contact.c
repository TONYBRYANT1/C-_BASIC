#define _CRT_SECURE_NO_WARNINGS 
#include "contact.h"
//初始化通讯录:
void InitContact(struct Contact* p)
{
	assert(p);
	memset(p->data, 0, sizeof(p->data));
	p->size = 0;
}
void AddContact(struct Contact* p)
{
	assert(p);
	if (p->size == MAX)
	{
		printf("通讯录已满，添加失败\n");
	}
	else
	{
		printf("请添加姓名:>");
		scanf("%s", p->data[p->size].name);
		printf("请添加年龄:>");
		scanf("%d", &(p->data[p->size].age));
		printf("请添加性别:>");
		scanf("%s", p->data[p->size].sex);
		printf("请添加电话:>");
		scanf("%s", p->data[p->size].tele);
		printf("请添加地址:>");
		scanf("%s", p->data[p->size].addr);

		p->size++;
		printf("添加成功！");
	}
	
}
void ShowContact(const struct Contact* p)
{
	assert(p);
	if (p->size == 0)
	{
		printf("通讯录暂无人员信息！\n");
	}
	else
	{
		int i = 0;
		printf("%s\t%8s\t%8s\t%8s\t%8s\t\n", "姓名", "年龄", "性别", "电话","地址");
		for (i = 0; i < p->size;i++)
		{
			printf("%s\t%8d\t%8s\t%8s\t%8s\t\n",
				p->data[i].name,
				p->data[i].age,
				p->data[i].sex,
				p->data[i].tele,
				p->data[i].addr);
		}
	}
}
//通过名字查找人员信息:
//找到返回所在位置(下标)(size),找不到返回-1
//static:contact内部用来支撑其他函数实现的函数，不需要被其他的需求所看到
static int FindByName(const struct Contact* p, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (strcmp(name, p->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DeleteContact(struct Contact* p)
{
	assert(p);
again:
	printf("是否决定删除？\n");
	printf("Y for yes,N for no");
	char ret = 'w';
	char get = '0';
	while (get = getchar() != '\n')
	{
		;
	}
	printf("请输入:>\n");
	scanf("%c", &ret);
	if (ret == 'Y')
	{
		char name[MAX_NAME] = "name";
		printf("请输入你要删除人的名字!\n");
		scanf("%s", name);
		int pos = FindByName(p, name);
		if (pos==-1)
		{
			printf("暂无此联系人\n");
		}
		else
		{
			int j = 0;
			for (j = pos; j < (p->size) - 1; j++)
			{
				p->data[j] = p->data[j + 1];
			}
			p->size--;
		}
	}
	else if(ret=='N')
	{
		printf("想好再来!");
	}
	else
	{
		printf("输入错误!再输一遍\n");
		printf("请输入Y/N;Y for yes,N for no\n");
		goto again;
	}
}
void SesrchContact(const struct Contact* p)
{
	char name[MAX_NAME];
	printf("请输入你要找的人名:>");
	scanf("%s", name);
	int pos = FindByName(p, name);
	if (pos == -1)
	{
		printf("暂无此人");
	}
	else
	{
		printf("%s\t%8s\t%8s\t%8s\t%8s\t\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%s\t%8d\t%8s\t%8s\t%8s\t\n",
			p->data[pos].name,
			p->data[pos].age,
			p->data[pos].sex,
			p->data[pos].tele,
			p->data[pos].addr);
	}
}
void ModifyContact(struct Contact* p)
{
	printf("请输入你要修改的人的名字!>:");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos=FindByName(p, name);
	if (pos == -1)
	{
		printf("你要修改的人不存在!");
	}
	else
	{
		printf("请添加姓名:>");
		scanf("%s", p->data[pos].name);
		printf("请添加年龄:>");
		scanf("%d", &(p->data[pos].age));
		printf("请添加性别:>");
		scanf("%s", p->data[pos].sex);
		printf("请添加电话:>");
		scanf("%s", p->data[pos].tele);
		printf("请添加地址:>");
		scanf("%s", p->data[pos].addr);
		printf("修改成功!\n");
	}
}
void SortContact(struct Contact* p,int sz,int width)
{
	bubble_sort(p, sz, width, cmp);
}
