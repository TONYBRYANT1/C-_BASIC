#include "contact.h"
//初始化通讯录:
void Distory_Contact(struct Contact* p)
{
	free(p->data);
	p->data = NULL;
}
void InitContact(struct Contact* p)//----------------------------------------------改动
{
	assert(p);
	p->data = (struct PeoInFo*)malloc(CAPACITY * sizeof(struct PeoInFo));
	if (p->data == NULL)
	{
		printf("初始化失败！");
	}
	p->size = 0;
	p->capacity = CAPACITY;
	//加载文件到通讯录中:
	LoadContact(p);
}

//声明函数:
void Check_Capacity(struct Contact* p);
void LoadContact(struct Contact* p)
{
	struct PeoInFo temp = { 0 };
	FILE* pfRead = fopen("Contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	else
	{
		//fread的返回值为一次读了几个数据
		while (fread(&temp, sizeof(struct PeoInFo), 1, pfRead))
		{
			Check_Capacity(p);
			p->data[p->size] = temp;
			p->size++;
		}
	}
}

void Check_Capacity(struct Contact* p)
{
	assert(p);
	if (p->capacity == p->size)
	{
		//开始增容
		struct PeoInFo* str = (struct PeoInFo*)realloc(p->data, (CAPACITY+2)* sizeof(struct PeoInFo));
		if (str != NULL)
		{
			p->data = str;
			p->capacity++;
			printf("增容成功!\n");
		}
		else
		{
			printf("扩容失败!\n");
		}
	}
	
}
void AddContact(struct Contact* p)
{
	assert(p);
	Check_Capacity(p);
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
	printf("添加成功！\n");
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
int cmp1(const void* p1, const void* p2)
{
	return(strcmp(((struct PeoInFo*)p1)->name, ((struct PeoInFo*)p2)->name));
}
int cmp2(const void* p1, const void* p2)
{
	return(((struct PeoInFo*)p1)->age-((struct PeoInFo*)p2)->age);
}
int cmp3(const void* p1, const void* p2)
{
	return(strcmp(((struct PeoInFo*)p1)->sex, ((struct PeoInFo*)p2)->sex));
}
int cmp4(const void* p1, const void* p2)
{
	return(strcmp(((struct PeoInFo*)p1)->tele, ((struct PeoInFo*)p2)->tele));
}
int cmp5(const void* p1, const void* p2)
{
	return(strcmp(((struct PeoInFo*)p1)->addr, ((struct PeoInFo*)p2)->addr));
}

static void swap(char* p1, char* p2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *(p1);
		*(p1) = *(p2);
		*(p2) = temp;
		p1++;
		p2++;
	}
}
void ContactSort(void* p, int sz, int width, int(*cmp)(const void* p1, const void* p2))
{
		int i = 0;
		int j = 0;
		for (i = 0; i < sz-1; i++)
		{
			for (j = 0; j < sz - 1 - i; j++)
			{
				if (cmp((char*)p + j * width, (char*)p + (j + 1) * width) > 0)
				{
					swap((char*)p + j * width, (char*)p + (j + 1) * width, width);
				}
			}
		}
		int n = 0;
		printf("%s\t%8s\t%8s\t%8s\t%8s\t\n", "姓名", "年龄", "性别", "电话", "地址");
		for (n = 0; n <sz; n++)
		{
			printf("%s\t%8d\t%8s\t%8s\t%8s\t\n",
				((struct PeoInFo*)p)[n].name,
				((struct PeoInFo*)p)[n].age,
				((struct PeoInFo*)p)[n].sex,
				((struct PeoInFo*)p)[n].tele ,
				((struct PeoInFo*)p)[n].addr);
		}
 }


void SaveContact(struct Contact* p)
{
	FILE* pfWrite = fopen("Contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;//因为是void--->return不给返回值
	}
	else
	{
		int i = 0;
		for (i = 0; i < p->size; i++)
		{
			fwrite(&(p->data[i]), sizeof(p->data[i]), 1, pfWrite);//源头--大小--个数--目标地点
		}
	}
	fclose(pfWrite);
	pfWrite = NULL;
	printf("保存成功!\n");
	return;
}


