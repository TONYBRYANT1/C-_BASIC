#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//char int short float...-----c������������
//��������:�ṹ�壬ö�٣�������
//1.����һ��ѧ�����ͣ�����ͨ��ѧ�����ʹ���ѧ������(����)
//�ṹ������:
//struct stu
//{
//	//�ṹ��ĳ�Ա����:
//	char name[20];
//	int age;
//}s1,s2,s3;//ȫ�ֱ���:
////ȫ�ֱ���:
//struct stu stu3;
//int main()
//{
//	//�ֲ�����:
//	struct stu stu1;
//	struct stu stu2;
//	return 0;
//}



//�ṹ��������:
//�������:
//struct node
//{
//	int data;//������
//	struct node* next;//ָ����
//};




//typedef:
//typedef struct stu
//{
//	//�ṹ��ĳ�Ա����:
//	char name[20];
//	int age;
//}stu;
//or
//typedef struct stu stu;





//����Ĭ�϶�����Ϊ4:
//#pragma pack(1)
//�ṹ���ڴ����:
//1. ��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ����
//2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
//������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
//VS��Ĭ�ϵ�ֵΪ8
//3. �ṹ���ܴ�СΪ����������ÿ����Ա��������һ��������������������
//4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ�����
//���С��������������������Ƕ�׽ṹ��Ķ�����������������
//struct stu
//{
//	char a;
//	char b;
//	int c;
//};
//struct st
//{
//	char a;
//	int b;
//	char c;
//};
////int main()
////{
////	struct st s1 ={ 0 };
////	struct stu s2 = { 0 };
////	printf("%d\n",(int)sizeof(s2));//8
////	printf("%d\n",(int)sizeof(s1));//12
////	return 0;
////}
////ȡ�����õ�Ĭ�϶�����
////#pragma pack ()
//
////дһ���꣬����ṹ����ĳ������ͷ��ַ������׵�ַ��ƫ��
////size_t offsetof(structName, memberName);
//#include<stddef.h>
//int main()
//{
//	printf("%d\n", (int)offsetof(stu, a));
//	printf("%d\n", (int)offsetof(stu, b));
//	printf("%d\n", (int)offsetof(stu, c));
//	return 0;
//}






//�ṹ�崫��:
//struct stu
//{
//	char a;
//	char b;
//	int c;
//};
//void init(struct stu* p)
//{
//	p->a = 'w';
//	p->b = 's';
//	p->c = 4;
//}
//void printf1(struct stu temp)
//{
//	printf("%c", temp.a);
//}
//void printf2(const struct stu *temp)
//{
//	printf("%c", temp->a);
//}
////p2�ȽϺã��������ε�ʱ�򣬲�������Ҫѹջ�ģ�����ʱ��Ϳռ��ϵ�ϵͳ��������ѡ��ֵ��ϵͳ�������󣬵��������½���
//int main()
//{
//	struct stu s1 = { 0 };
//	init(&s1);
//	printf1(s1);
//	printf2(&s1);
//	printf("%c", s1.a);
//	return  0;
//}





//λ��:(������λ)
//Ŀ��:��ʡ�ռ�
//struct S
//{
//	//һ��int---4byte---32bit
//	//һ��int���Ա��2^32��״̬����a�ò�����ô��(�������:0,1,2,3),������2(2��������λ)������
//	int a : 2;//2��������λ---bitλ
//	int b : 5;//5��������λ
//	int c : 10;//10��������λ
//	int d : 30;//30��������λ
//};
////47bit---6byte�͹���(���˷�)
//int main()
//{
//	struct S s;
//	printf("%d", (int)sizeof(s));//8 byte
//	return 0;
//}



//ö��:
//enum color
//{
//	RED=10,//ö�ٳ�������ֵ
//	GREEN=20,
//	BLUE=30
//};
//int main()
//{
//	enum color c = RED;
//	printf("%d\n", c);
//	printf("%d\n", (int)sizeof(c));//���ʹ�СΪ4byte
//	return 0;
//}






//����---������---������
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	union Un u = { 0 };
//	printf("%d\n", (int)sizeof(u));//4
//	printf("%p\n", &u);//000000BA2D11F844
//	printf("%p\n", &(u.c));//000000BA2D11F844
//	printf("%p\n", &(u.i));//000000BA2D11F844
//	return 0;
//}




//�жϴ�С�� && �����������������жϴ�С��
//int check_sys1()
//{
//	int a = 1;
//	return *(char*)&a;
//	//��1:С��
//	//��0:���
//}
//int check_sys2()//�����������������жϴ�С��
//{
//	union U//����------------��Ϊ����ʹ��һ�����Կ��Բ�дU
//	{
//		char i;//01 00 00 00
//		int n;// |        |
//	}u;//����    |--------|
//	u.n = 1;//   i   |
//	return u.i;//    |
//	//��1:С��       n
//	//��0:���
//}
//int main()
//{
//	//int a = 1;//00 00 00 01
//	////С���ֽ���洢ģʽ:(��->��):01 00 00 00 
//	////����ֽ���洢ģʽ:(��->��):00 00 00 01
//	//char* p = (char*)&a;
//	//printf("%d\n",(int)*p);
//	////or
//	//printf("%d\n", *(char*)&a);
//	////or
//	//int ret = check_sys1();
//	//if (1 == ret)
//	//{
//	//	printf("С��\n");
//	//}
//	//else
//	//{
//	//	printf("���\n");
//	//}
//	////or
//	int ret = check_sys2();
//	if (1 == ret)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}





//������Ĵ�С:
//���ϵĴ�С����������Ա�Ĵ�С��
//������Ա��С����������������������ʱ�򣬾�Ҫ���뵽������������������
//������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
//union Un
//{
//	int a;//�ó�Ա��С�Ľ�Сֵ:4  Ĭ�϶�����:8  ������:4
//	char arr[5];//�൱��д��5��char //�ó�Ա��С�Ľ�Сֵ:1  Ĭ�϶�����:8  ������:1  
//	//��������:4  ����Ա��С:5  ����:8
//};
//int main()
//{
//	union Un u = {0};
//	printf("%d\n",(int)sizeof(u));
//	return 0;
//}
//union Un
//{
//	int a;
//	char b;
//	char c;
//	char d;
//	char e;
//	char f;
//};
//int main()
//{
//	union Un n ;
//	n.a = 1;
//	n.b = 1;
//	n.c = 1;
//	n.d = 1;
//	n.e = 1;
//	n.f = 1;
//	printf("%d", (int)sizeof(n));
//	return 0;
//}

//union U
//{
//	int a;//4 8 4
//	char b[5];//1 8 1
//	//��������:4  ����Ա��С:5  ��������ռ�ռ��С:4*2=8>5
//};
//int main()
//{
//	union U u;
//	printf("%d", (int)sizeof(u));
//}