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



//调用堆栈
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






//条件断点
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












//my_strcpy 的逐步优化
//strcpy:char *strcpy( char *strDestination, const char *strSource );
//1.    5分
//void my_strcpy(char* dest, char* sour)
//{
//	while (*sour != '\0')
//	{
//		*dest = *sour;//‘++' or '--'的优先级大于‘*’
//		dest++;
//		sour++;
//	}
//	*dest = *sour;
//}




//2.      6分
//void my_strcpy(char* dest, char* sour)
//{
//	while (*dest++ = *sour++)  //   '#'='\0'的值为0---假
//	{
//		;
//	}
//}



//3.       8分
// 如果传数组首元素地址(arr)时如果传错了,传成了NULL,那么出现问题时如何处理并发现错误点?
//用assert函数-----头文件#include<assert.h>
//assert:如果()中语句为真则无动作,如果()中语句为假则停止并指出错误的位置
//  Assertion failed: sour != NULL, file D:\code\Debug and Release\Debug and Release\FileName.cpp, line 129
//#include<assert.h>
//void my_strcpy(char* dest, char* sour)
//{
//	assert(dest != NULL);
//	assert(sour != NULL);
//	while (*dest++ = *sour++)  //   '#'='\0'的值为0---假
//	{
//		;
//	}
//}



//4.  10分
//#include<assert.h>
//参照strcpy:strcpy:char* strcpy(char* strDestination, const char* strSource);
//4.1:const修饰的变量
//4.1.1:(const修饰p)int num=10; int * const p=&num;则不能通过p去指向其他地址，但可以改变num中的值
//4.1.2:(const修饰*p)int n=10; const int *p=&n;则不能通过p去改变n的值，但是可以去指向其他地址
//4.1.3:(const修饰p并且const修饰*p)int ret=10; const int * const p=&num;则既不能通过p去改变ret的值,也不能通过p去指向其他地址
//4.2:return value
//strcpy的Return Value
//Each of these functions returns the destination string.No return value is reserved to indicate an error.
//char* my_strcpy(char* dest, const char* sour)//不能改变arr2的值
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(sour != NULL);
//	while (*dest++ = *sour++)  //   '#'='\0'的值为0---假
//	{
//		;
//	}
//	return ret;
//}



//#include<assert.h>
//char* my_strcpy(char* dest, const char* sour)//不能改变arr2的值
//{
//	char* ret = dest;
//	assert(dest != NULL);//断言保护
//	assert(sour != NULL);//断言保护
//	//把str指向的字符串拷贝到dest指向的空间，并包含'\0'
//	while (*dest++ = *sour++)  //   '#'='\0'的值为0---假
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
//10分代码:1.const  2.assert  3.主要语句
//#include<assert.h>
//#include<stdio.h>
//int my_strlen(const char* arr)
//{
//	int counst = 0;
//	assert(arr != NULL);//断言保护
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