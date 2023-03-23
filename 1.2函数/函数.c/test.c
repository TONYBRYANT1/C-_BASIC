#define _CRT_SECURE_NO_WARNINGS
//strcpy
//#include<string.h>
//#include<stdio.h>
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abc";
//	strcpy(arr1,arr2);
//	printf("%s", arr1);//arr1:abc\0ef\0 而printf读到\0就停止了
//	return 0;
//}





//memset----memory set
//#include<stdio.h>
//#include<memory.h>
//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, '&', 5);//void *memset( void *dest, int c//可以用ASCII值来理解, size_t count );
//	printf("%s", arr);
//	return 0;
//}




//get_max
//#include<stdio.h>
//int get_max(int x, int y)//传值调用
//{
//	int z = (x > y ? x : y);
//	return z;
//}
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d%d", &a, &b);
//	int ret=get_max(a, b);
//	printf("max=%d", ret);
//	return 0;
//}



//swap---用指针方解决
//#include<stdio.h>
//void swap(int* x, int* y)//传地址调用
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d%d", &a, &b);
//	swap(&a, &b);
//	printf("a=%d,b=%d",a, b);
//	return 0;
//}





//prime(素数)函数
//#include<stdio.h>
//#include<math.h>
//int prime(int x,int* ct)
//{
//	int j = 0, k = sqrt(x);
//	for (j = 2; j <= k; j++)
//	{
//		if (0 == x % j)
//		{
//			return 0;
//		}//千万不要写成不能整除某一个数的数就是素数(8不能整除3,8也不是素数)(而是要把所有的数都试一遍,都不能整除的数才是素数)
//	}
//	(*ct)++;
//	return 1;
//	//(*ct)++;return直接结束循环所以该指令不被理睬
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (1 == prime(i,&count))
//		{
//			printf("%d  ", i);
//		}
//	}
//	printf("\n共有%d个素数",count);
//	return 0;
//}






//闰年
//#include<stdio.h>
//int run(int x, int* ct)//函数的复用性高,要干净,简洁  切记:不要在函数里加什么printf("是闰年...的");会影响复用性
//{
//	if ((x % 400 == 0) || ((x % 4 == 0) && (x % 100 != 0)))
//	{
//		(*ct)++;
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int i = 0, count = 0;
//	for (i = 1000; i <=2000; i++)
//	{
//		if (1 == run(i,&count))
//		{
//			printf("%d  ", i);
//		}
//	}
//	printf("\n共有%d个闰年", count);
//	return 0;
//}








//函数实现二分查找
//#include<stdio.h>
//int binary_search(int arr[],int k,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
// //int mid = (left + right) / 2;千万不能丢到外面去
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;//千万不能丢到外面去
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//			return mid;
//	}
//	return (-1);
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	printf("请你输入你要找的数>: ");
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到");
//	}
//	else
//	{
//		printf("找到了,下标是%d", ret);
//	}
//		
//}





//每使用一次函数sum加一
//#include<stdio.h>
//void add(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int sum = 0;
//	add(&sum);
//	printf("%d\n", sum);
//	add(&sum);
//	printf("%d\n", sum);
//	add(&sum);
//	printf("%d\n", sum); 
//	add(&sum);
//	printf("%d\n", sum);
//	return 0;
//}





//函数嵌套
//#include<stdio.h>
//void one_line(void)
//{
//	printf("哈哈\n");
//}
//void three_line(void)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)   //1.若函数参数为void,那么写函数时参数直接空着/不写                   
//	{                         //2.函数在被使用时要加'()'表示他是函数
//		one_line();
//	}
//}
//int main()
//{
//	three_line();
//	return 0;
//}





//链式访问----一个函数的结果作为另一个函数的条件
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int len = 0;
//	//1.
//	len = strlen("abc");
//	printf("%d\n", len);
//	//2.
//	printf("%d\n", strlen("abc"));
//	return 0;
//}


//printf的返回值 int printf( const char *format [, argument]... );
//Return Value:
//Each of these functions returns the number of characters printed, or a negative value if an error occurs.
//#include<stdio.h>
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//}





////函数声明预定义---用于小组作业
////A.c---函数定义    B.c---运用函数     C.h---函数声明        (A.c与C.h构成加法模块)
//#include<stdio.h>
//#include "abdd.h";//这是自定义函数的头文件包含(而头文件用来声明函数,.c文件用来写函数的定义)
//int main()
//{
//	int a = 2;
//	int b = 0;
//	int k=add(a, b);
//	printf("%d", k);
//	return 0;
//}






//函数递归---recursion   需要限制条件并且每次递归越来越接近限制的值
//steak overflow----栈溢出
//#include<stdio.h>
//void print(int k)//函数没有返回值写void
//{
//	if (k > 9)
//	{
//		print(k / 10);
//	}
//	printf("%d ", k % 10);
//}
//int main()
//{
//	int k = 1234;
//	scanf("%d", &k);
//	print(k);
//	return 0;
//}






////模拟实现strlen函数//strlen不算\0
//非递归版:
//#include<stdio.h>
//int  my_strlen(char* p);
//{
//	int counter = 0;
//	while((*p) != '\0')
//	{
//		counter++;
//		p++;	
//	}
//	return counter;
//}
//int main()
//{
//	char arr[] = "bit";
//	int r =  my_strlen(arr);//arr是字符数组，当其传参时相当于第一的元素的首地址
//	printf("%d", r);
//}
//递归版(无创建临时变量):
//#include<stdio.h>
//int my_strlen(char* p)//"bit"
//{ 
//	if ((*p) != '\0')//限制条件   
//  {                 //实现原理:bit0--->b(1)it0--->b(1)i(1)t0--->b(1)i(1)t(1)0--->1+1+1+0=3
//	
//		return (1 + my_strlen(++p));//向限制条件逼近
//	}
//	else return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	int r = my_strlen(arr);//arr是字符数组，当其传参时相当于第一的元素的首地址
//	printf("%d", r);
//}






//n的阶乘
//非递归:
//#include<stdio.h>
//int Fac1(int x)
//{
//	int n = 0;
//	int ret = 1;
//	for (n = 1; n <= x; n++)
//	{
//		ret *= n;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac1(n);
//	printf("%d", ret);
//}
//递归版:
//#include<stdio.h>
//int Fac2(int x)
//{
//	if (x <= 1)
//		return 1;
//	else
//		return (x * Fac2(x - 1));
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = Fac2(n);
//	printf("%d", ret);
//}







//斐波那契数列 1 1 2 3 5 8 13 21 34 55...
//TDD---测试驱动开发(写函数时先写函数怎么用，再写函数怎么实现的方法)
//#include<stdio.h>
//int counter = 0;
//int Fei1(int n)//(劣)
//{
//	if (n == 3)//计算第三个斐波那契数计算的次数
//	{
//		counter++;
//	}
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//		return (Fei1(n - 1)+ Fei1(n - 2));
//}
//该函数效率太低！！！
//原因:分支重复太多
//			   50----------------------------2^0
//	    49          48-----------------------2^1
//	  48    47    47    46-------------------2^2
//	47 46 46 45 46 45 45 44------------------2^3
//  ............................------------- -2^49
//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 -----------2^49
// 测试：
//40
//ret = 102334155
//counter = 39088169
//D:\code\函数.c\x64\Debug\函数.c.exe(进程 22564)已退出，代码为 0。
//按任意键关闭此窗口. . .
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 0;
//	ret = Fei1(n);
//	printf("ret = %d", ret);
//	printf("\ncounter = %d",counter);
//}
//非递归(优)
//#include<stdio.h>
//int Fei2(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 0;
//	ret = Fei2(n);
//	printf("ret = %d", ret);
//}







//不合适的条件导致stack overflow
//#include<stdio.h>
//void test(int n)
//{
//	if (n < 1000000)
//	{
//		test(n+1);
//	}
//}
//int main()
//{
//	test(1);
//	return 0;
//}


//1.汉诺塔
//2.青蛙跳台阶







