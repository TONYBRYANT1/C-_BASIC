#define _CRT_SECURE_NO_WARNINGS 
#include "contact.h"
//��ʼ��ͨѶ¼:
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
		printf("ͨѶ¼���������ʧ��\n");
	}
	else
	{
		printf("���������:>");
		scanf("%s", p->data[p->size].name);
		printf("���������:>");
		scanf("%d", &(p->data[p->size].age));
		printf("������Ա�:>");
		scanf("%s", p->data[p->size].sex);
		printf("����ӵ绰:>");
		scanf("%s", p->data[p->size].tele);
		printf("����ӵ�ַ:>");
		scanf("%s", p->data[p->size].addr);

		p->size++;
		printf("��ӳɹ���");
	}
	
}
void ShowContact(const struct Contact* p)
{
	assert(p);
	if (p->size == 0)
	{
		printf("ͨѶ¼������Ա��Ϣ��\n");
	}
	else
	{
		int i = 0;
		printf("%s\t%8s\t%8s\t%8s\t%8s\t\n", "����", "����", "�Ա�", "�绰","��ַ");
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
//ͨ�����ֲ�����Ա��Ϣ:
//�ҵ���������λ��(�±�)(size),�Ҳ�������-1
//static:contact�ڲ�����֧����������ʵ�ֵĺ���������Ҫ������������������
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
	printf("�Ƿ����ɾ����\n");
	printf("Y for yes,N for no");
	char ret = 'w';
	char get = '0';
	while (get = getchar() != '\n')
	{
		;
	}
	printf("������:>\n");
	scanf("%c", &ret);
	if (ret == 'Y')
	{
		char name[MAX_NAME] = "name";
		printf("��������Ҫɾ���˵�����!\n");
		scanf("%s", name);
		int pos = FindByName(p, name);
		if (pos==-1)
		{
			printf("���޴���ϵ��\n");
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
		printf("�������!");
	}
	else
	{
		printf("�������!����һ��\n");
		printf("������Y/N;Y for yes,N for no\n");
		goto again;
	}
}
void SesrchContact(const struct Contact* p)
{
	char name[MAX_NAME];
	printf("��������Ҫ�ҵ�����:>");
	scanf("%s", name);
	int pos = FindByName(p, name);
	if (pos == -1)
	{
		printf("���޴���");
	}
	else
	{
		printf("%s\t%8s\t%8s\t%8s\t%8s\t\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("��������Ҫ�޸ĵ��˵�����!>:");
	char name[MAX_NAME];
	scanf("%s", name);
	int pos=FindByName(p, name);
	if (pos == -1)
	{
		printf("��Ҫ�޸ĵ��˲�����!");
	}
	else
	{
		printf("���������:>");
		scanf("%s", p->data[pos].name);
		printf("���������:>");
		scanf("%d", &(p->data[pos].age));
		printf("������Ա�:>");
		scanf("%s", p->data[pos].sex);
		printf("����ӵ绰:>");
		scanf("%s", p->data[pos].tele);
		printf("����ӵ�ַ:>");
		scanf("%s", p->data[pos].addr);
		printf("�޸ĳɹ�!\n");
	}
}
void SortContact(struct Contact* p,int sz,int width)
{
	bubble_sort(p, sz, width, cmp);
}
