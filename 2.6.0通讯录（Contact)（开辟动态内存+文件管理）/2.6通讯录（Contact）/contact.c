#include "contact.h"
//��ʼ��ͨѶ¼:
void Distory_Contact(struct Contact* p)
{
	free(p->data);
	p->data = NULL;
}
void InitContact(struct Contact* p)//----------------------------------------------�Ķ�
{
	assert(p);
	p->data = (struct PeoInFo*)malloc(CAPACITY * sizeof(struct PeoInFo));
	if (p->data == NULL)
	{
		printf("��ʼ��ʧ�ܣ�");
	}
	p->size = 0;
	p->capacity = CAPACITY;
	//�����ļ���ͨѶ¼��:
	LoadContact(p);
}

//��������:
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
		//fread�ķ���ֵΪһ�ζ��˼�������
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
		//��ʼ����
		struct PeoInFo* str = (struct PeoInFo*)realloc(p->data, (CAPACITY+2)* sizeof(struct PeoInFo));
		if (str != NULL)
		{
			p->data = str;
			p->capacity++;
			printf("���ݳɹ�!\n");
		}
		else
		{
			printf("����ʧ��!\n");
		}
	}
	
}
void AddContact(struct Contact* p)
{
	assert(p);
	Check_Capacity(p);
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
	printf("��ӳɹ���\n");
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
		printf("%s\t%8s\t%8s\t%8s\t%8s\t\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		return;//��Ϊ��void--->return��������ֵ
	}
	else
	{
		int i = 0;
		for (i = 0; i < p->size; i++)
		{
			fwrite(&(p->data[i]), sizeof(p->data[i]), 1, pfWrite);//Դͷ--��С--����--Ŀ��ص�
		}
	}
	fclose(pfWrite);
	pfWrite = NULL;
	printf("����ɹ�!\n");
	return;
}


