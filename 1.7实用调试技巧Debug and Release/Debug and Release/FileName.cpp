#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		printf("%d ", i);
//	}
//	for (i = 0; i < 100; i++)
//	{
//		printf("%d ", 100-i);
//	}
//}
////F5




//int Add(int x, int y)
//{
//	return x + y;
//	printf("haha");
//	printf("haha");
//	printf("haha");
//	printf("haha");
//	printf("haha");
//	printf("haha");
//	printf("haha"); printf("haha");
//
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int ret = Add(a, b);
//	printf("%d", ret);
//	return 0;
//}




//int main()
//{
//	int arr[10] = { 0 };
//	if (arr[3] == 0)
//		printf("1");
//	else if (arr[1] == '\0')
//		printf("2");
//	else
//		printf("3");
//	return 0;
//}



//���ö�ջ
//void test2()
//{
//	printf("haha");
//}
//void test1()
//{
//	test2();
//}
//void test()
//{
//	test1();
//}
//int main()
//{
//	test();
//	return 0;
//}






//�����ϵ�
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		if (i < 5)
//			printf("haha   ");
//	}
//	return 0;
//}












//my_strcpy �����Ż�
//strcpy:char *strcpy( char *strDestination, const char *strSource );
//1.    5��
//void my_strcpy(char* dest, char* sour)
//{
//	while (*sour != '\0')
//	{
//		*dest = *sour;//��++' or '--'�����ȼ����ڡ�*��
//		dest++;
//		sour++;
//	}
//	*dest = *sour;
//}




//2.      6��
//void my_strcpy(char* dest, char* sour)
//{
//	while (*dest++ = *sour++)  //   '#'='\0'��ֵΪ0---��
//	{
//		;
//	}
//}



//3.       8��
// �����������Ԫ�ص�ַ(arr)ʱ���������,������NULL,��ô��������ʱ��δ������ִ����?
//��assert����-----ͷ�ļ�#include<assert.h>
//assert:���()�����Ϊ�����޶���,���()�����Ϊ����ֹͣ��ָ�������λ��
//  Assertion failed: sour != NULL, file D:\code\Debug and Release\Debug and Release\FileName.cpp, line 129
//#include<assert.h>
//void my_strcpy(char* dest, char* sour)
//{
//	assert(dest != NULL);
//	assert(sour != NULL);
//	while (*dest++ = *sour++)  //   '#'='\0'��ֵΪ0---��
//	{
//		;
//	}
//}



//4.  10��
//#include<assert.h>
//����strcpy:strcpy:char* strcpy(char* strDestination, const char* strSource);
//4.1:const���εı���
//4.1.1:(const����p)int num=10; int * const p=&num;����ͨ��pȥָ��������ַ�������Ըı�num�е�ֵ
//4.1.2:(const����*p)int n=10; const int *p=&n;����ͨ��pȥ�ı�n��ֵ�����ǿ���ȥָ��������ַ
//4.1.3:(const����p����const����*p)int ret=10; const int * const p=&num;��Ȳ���ͨ��pȥ�ı�ret��ֵ,Ҳ����ͨ��pȥָ��������ַ
//4.2:return value
//strcpy��Return Value
//Each of these functions returns the destination string.No return value is reserved to indicate an error.
//char* my_strcpy(char* dest, const char* sour)//���ܸı�arr2��ֵ
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(sour != NULL);
//	while (*dest++ = *sour++)  //   '#'='\0'��ֵΪ0---��
//	{
//		;
//	}
//	return ret;
//}



//#include<assert.h>
//char* my_strcpy(char* dest, const char* sour)//���ܸı�arr2��ֵ
//{
//	char* ret = dest;
//	assert(dest != NULL);//���Ա���
//	assert(sour != NULL);//���Ա���
//	//��strָ����ַ���������destָ��Ŀռ䣬������'\0'
//	while (*dest++ = *sour++)  //   '#'='\0'��ֵΪ0---��
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "#############";
//	char arr2[] = "bit";
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcpy(arr1, arr2));
//}




//my_strlen
//10�ִ���:1.const  2.assert  3.��Ҫ���
//#include<assert.h>
//#include<stdio.h>
//int my_strlen(const char* arr)
//{
//	int counst = 0;
//	assert(arr != NULL);//���Ա���
//	while (*arr != '\0')
//	{
//		counst++;
//		arr++;
//	}
//	return counst;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret=my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}