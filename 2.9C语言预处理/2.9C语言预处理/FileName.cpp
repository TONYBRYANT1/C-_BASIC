#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//Ԥ�������:
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	FILE* pf = fopen("log.txt", "w");
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		fprintf(pf, "file:%s line:%d data:%s time:%s i=%d\n",
//			__FILE__, __LINE__, __DATE__, __TIME__, i);
//		printf("%s\n", __FUNCTION__);//��ӡ��������
//	}
//	fclose(pf);
//	pf == NULL;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#define������ź��治Ҫ�ӷֺ�

//#define����ĺ�
//#define SQUARE(X) X*X   //SQUAREҪ��()��������
//int main()
//{
//	//int ret = SQUARE(5);
//	//printf("ret=%d", ret);
//
//	int ret = SQUARE(5+1);//������ȫ�滻�����Ǵ��ε�,(5+1)��������������ֱ�Ӵ���X�� �ó�5+1*5+1=11
//	printf("ret=%d", ret);
//	return 0;
//}

//#define SQUARE(X) (X)*(X)//�����Ͳ������---��Ҫ��ϧ()
//int main()
//{
//	int ret = SQUARE(5 + 1);//��X�������������Ͳ�����11 ����5+1����õ�36��
//	printf("ret=%d", ret);
//	return 0;
//}




//#define DOUBLE(X) X+X
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(a);
//	//int ret=10*a+a=55
//	printf("%d\n", ret);
//}
//
//#define DOUBLE(X) (X)+(X)
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(a);
//	//int ret=10*(a)+(a)=55
//	printf("%d\n", ret);
//}

//#define DOUBLE(X) ((X)+(X))
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(a);
//	//int ret=10*((a)+(a))=100
//	printf("%d\n", ret);
//}

//�겻���Եݹ�



//#
//�ַ����еĺ�ͨ�������滻:
//#define MAX 10
//int main()
//{
//	printf("MAX=%d", MAX);//MAX=10
//	return  0;
//}

//��ʲô�취����Ĳ������뵽�ַ����У�
//int main()
//{
//	printf("hallo world\n");
//	printf("hallo ""world\n");
//	printf("hal""lo ""world");
//	//���ߵȼ�
//}


//#define PRINT(X) printf("the value of "#X" is %d\n",X)//����#X���滻��"X" �ڱ��"a" or "b"��ǰ������һ��
//int main()
//{
//	int a = 0;
//	int b = 2;
//	PRINT(a);
//	PRINT(b);
//	return 0;
//}


//##
//����ֱ����:
//int main()
//{
//	int a8 = 8;
//	printf("%d", a##8);
//	return 0;
//}
//#define CAT(X,Y) X##Y
//int main()
//{
//	int a8 = 10;
//	printf("%d", CAT(a, 8));
//	//printf("%d",a##8); <==> printf("%d",a8); <==>10
//	return 0;
//}



//������:
//int main()
//{
//	int a = 0;
//	//int b = a + 1;
//	int b = a++;//����ʽ�Ӷ���b��������ͬ������ʽ��a�и�����
//	return 0;
//}


//���и����õĺ����:
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 11;
//	printf("%d\n", MAX(a++, b++));//()�в����������ֱ���滻
//	// ((a++)>(b++)?(a++):(b++))
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}




//���뺯��:
//1.��������רһ:�����ͻ���float��,����Ҫ��дһ������
// ���겻�������ͣ�ֱ���滻
//2.�����ڵ��õ�ʱ����к������úͷ��صĿ���(�����鿴)
//3.�궨����Ԥ����׶ξ�������滻Ч�ʸ���:
//MAX(a,b)==>((a)>(b)?(a):(b))
//4.����ܻ��������ӳ���ĳ���
//5.���Ե�ʱ������Ѵ�test.c--->test.exe ,��ʱ�궨���Ѿ����滻��,�޷��Ժ궨����е���
//6.��Ĳ����������޹�--->�����Ͻ�
//7.��Ĳ�������и�����ʱ���ܻ����Ӱ��,����������(�����Ὣ���Ĳ�����������,����������滻)
//8.��ķ��ź�ʽ�ӵķ��ż������Ϊ���ȼ�����,���³�����ܳ���
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int MaX(int x, int y)
//{
//	return(x > y ? x : y);
//}
//int main()
//{
//	int a = 10;
//	int b = 11;
//	printf("%d\n", MAX(a, b));//()�в����������ֱ���滻
//	printf("%d\n", MaX(a, b));
//	return 0;
//}

//���������������������(������)
//#define SIZEOF(type) sizeof(type)
//int main()
//{
//	int ret = SIZEOF(int);
//	printf("%d", ret);
//	return 0;
//}


//#include<stdlib.h>
//�궨���Ƶ�malloc��ʹ�ø��ӷ���
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);
//	//�滻:int* p = (int*)malloc(10*sizeof(int))
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		p[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	return 0;
//}


//inline---��������
//#undef---�����Ƴ�һ���궨��




//�����ж���:
//int main()
//{
//	int arr[SZ] = { 0 };
//	int i = 0;
//	for (i = 0; i < SZ; i++)
//	{
//		arr[i] = i;
//	}
//	for (i = 0; i < SZ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//����δ����SZ�Ĵ�С,VS���������벻�ˣ�����gcc��:
//����ʹ�������ж���:
//gcc test.c -D SZ=20



//��������:
//���ڵ����ԵĴ��룬ɾ����ϧ���������£��������ǿ���ѡ���Եı���
//1.�ж��Ƿ񱻱���:
/*#ifdef ...
#endif*/

//2.�ж��Ƿ񱻱���:��һ�ȼ�
//#if defined(DEBUG)
//#endif

//3.�ж��Ƿ񱻱���:��һ.������
//#if !defined(DEBUG)
//#endif

//4.�ж��Ƿ񱻱���:����ͬ��
//#ifndef DEBUG
//#endif

//5.
//#if �������ʽ
// 
//#endif

//6.���֧����������:
//#if �������ʽ
// 
//#elif �������ʽ
// 
//#end if �������ʽ
// 

//7.Ƕ��ָ��:



//#define DEBUG
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		//�����ԵĴ���:
//#ifdef DEBUG//<==>#if defined(DEBUG)
//		printf("%d ", arr[i]);
//#endif
//	}
//	return 0;
//}



//ͷ�ļ�����:
//1.����ͷ�ļ�:���Ҳ��ԣ�����Դ�ļ�����Ŀ¼�²��ң������ͷ�ļ�δ�ҵ���������������ҿ⺯��ͷ�ļ�һ���ڱ�׼λ�ò���ͷ�ļ�������Ҳ�������ʾ�������
//#include "..."
//2.���ļ�:����ͷ�ļ�ֱ��ȥ��׼·����ȥ���ң�����Ҳ�������ʾ�������
//#include <>
//�����ǲ��ǿ���˵�����ڿ��ļ�Ҳ����ʹ�� ���� ����ʽ������
//���ǿ϶��ģ����ԡ�
//�������������ҵ�Ч�ʾ͵�Щ����Ȼ����Ҳ�����������ǿ��ļ����Ǳ����ļ��ˡ�




//ͷ�ļ����ظ�����:
//���һ��.c�����ΰ�����.h�ļ�,��Ԥ����Ĺ����п��ܵ���ͷ�ļ����������,���´�������,�����ٶ���
//�������������������������:
//1.
//ĳ.h�ļ�:(����һ���ٴΰ���ͷ�ļ�ʱ��Ϊ�ѽ�__TEST_H__�������#ifndef����Ϊ��)
//	    #ifndef __TEST_H__
//  	#define __TEST_H__
//	    //ͷ�ļ�����:
//	    #endif

//2.
//ĳ.h�ļ�:()
//		#pragma once
//		//ͷ�ļ�����:





//���д�꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��:
//1.�Դ�����ʵ��:
//#include<stddef.h>
//struct S
//{
//	char c1;//0-1
//	int a;//4-8
//	char c2;//9
//	//9!=4������������������������>��ռ12�ֽ�
//};
//int main()
//{
//	struct S s;
//	printf("%d", (int)offsetof(struct S, c1));
//	printf("%d", (int)offsetof(struct S, a));
//	printf("%d", (int)offsetof(struct S, c2));
//	return 0;
//}



//2.�궨��ʵ��:
//#define OFFSETOF(struct_name,struct_member) (size_t)&(((struct_name*)0)->struct_member)
//struct S
//{
//	char c1;//0-1
//	int a;//4-8
//	char c2;//9
//	//9!=4������������������������>��ռ12�ֽ�
//};
//int main()
//{
//	struct S s;
//	printf("%d ", (int)OFFSETOF(struct S, c1));
//	printf("%d ", (int)OFFSETOF(struct S, a));
//	printf("%d ", (int)OFFSETOF(struct S, c2));
//	return 0; 
//}



////���:
////�нṹ��:
//struct S
//{
//	char c1;
//	int a;
//	char c2;
//};
//struct S s;
////�д˽ṹ����Ե�ָ��:
//struct S* p = &s;
////˵��p��ֵΪs�ĵ�ַ��p��s�Ľṹ��ָ��
//p->c1
////ͨ���ṹ��ָ�� �ҵ� ָ���Ӧ�Ľṹ�� �Ľṹ���Ա
//
////ͬ��:
////����((struct S*)0)Ҳͬ����������һ���ṹ��ָ��,ָ������Ӧ�Ľṹ����׵�ַ����0��
////��ô�ø�ָ��ָ��ṹ���Ա:((struct S*)0)->c1
////��ȡ���ַ:&( ((struct S*)0)->c1 )�͵õ������׵�ַΪ0�Ľṹ�� �ĳ�Ա �ĵ�ַ(��Ϊƫ����)




























































































































