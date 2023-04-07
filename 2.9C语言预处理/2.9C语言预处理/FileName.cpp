#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//预定义符号:
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
//		printf("%s\n", __FUNCTION__);//打印函数名字
//	}
//	fclose(pf);
//	pf == NULL;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#define定义符号后面不要加分号

//#define定义的宏
//#define SQUARE(X) X*X   //SQUARE要和()紧紧相连
//int main()
//{
//	//int ret = SQUARE(5);
//	//printf("ret=%d", ret);
//
//	int ret = SQUARE(5+1);//宏是完全替换而不是传参的,(5+1)不会进行运算而是直接带入X中 得出5+1*5+1=11
//	printf("ret=%d", ret);
//	return 0;
//}

//#define SQUARE(X) (X)*(X)//这样就不会出错---不要吝惜()
//int main()
//{
//	int ret = SQUARE(5 + 1);//将X用括号括起来就不会是11 而是5+1先算得到36了
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

//宏不可以递归



//#
//字符串中的宏通常不被替换:
//#define MAX 10
//int main()
//{
//	printf("MAX=%d", MAX);//MAX=10
//	return  0;
//}

//有什么办法将宏的参数插入到字符串中？
//int main()
//{
//	printf("hallo world\n");
//	printf("hallo ""world\n");
//	printf("hal""lo ""world");
//	//三者等价
//}


//#define PRINT(X) printf("the value of "#X" is %d\n",X)//其中#X会替换成"X" 在变成"a" or "b"与前后连在一起
//int main()
//{
//	int a = 0;
//	int b = 2;
//	PRINT(a);
//	PRINT(b);
//	return 0;
//}


//##
//不能直接用:
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



//副作用:
//int main()
//{
//	int a = 0;
//	//int b = a + 1;
//	int b = a++;//两个式子对于b的意义相同，但二式子a有副作用
//	return 0;
//}


//带有副作用的宏参数:
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 11;
//	printf("%d\n", MAX(a++, b++));//()中不会运算而是直接替换
//	// ((a++)>(b++)?(a++):(b++))
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}




//宏与函数:
//1.函数功能专一:若类型换成float型,则需要另写一个函数
// 而宏不关心类型，直接替换
//2.函数在调用的时候会有函数调用和返回的开销(反汇编查看)
//3.宏定义在预处理阶段就完成了替换效率更高:
//MAX(a,b)==>((a)>(b)?(a):(b))
//4.宏可能会大幅度增加程序的长度
//5.调试的时候程序已从test.c--->test.exe ,此时宏定义已经被替换了,无法对宏定义进行调试
//6.宏的参数与类型无关--->不够严谨
//7.宏的参数如果有副作用时可能会产生影响,而函数不会(函数会将传的参数进行运算,而宏仅仅是替换)
//8.宏的符号和式子的符号间可能因为优先级问题,导致程序可能出错
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int MaX(int x, int y)
//{
//	return(x > y ? x : y);
//}
//int main()
//{
//	int a = 10;
//	int b = 11;
//	printf("%d\n", MAX(a, b));//()中不会运算而是直接替换
//	printf("%d\n", MaX(a, b));
//	return 0;
//}

//宏可以做函数不能做的事(传类型)
//#define SIZEOF(type) sizeof(type)
//int main()
//{
//	int ret = SIZEOF(int);
//	printf("%d", ret);
//	return 0;
//}


//#include<stdlib.h>
//宏定义似的malloc的使用更加方便
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);
//	//替换:int* p = (int*)malloc(10*sizeof(int))
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


//inline---内联函数
//#undef---用于移除一个宏定义




//命令行定义:
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
//这里未声明SZ的大小,VS编译器编译不了，但在gcc中:
//可以使用命令行定义:
//gcc test.c -D SZ=20



//条件编译:
//对于调试性的代码，删除可惜，保留碍事，所以我们可以选择性的编译
//1.判断是否被编译:
/*#ifdef ...
#endif*/

//2.判断是否被编译:与一等价
//#if defined(DEBUG)
//#endif

//3.判断是否被编译:与一.二反义
//#if !defined(DEBUG)
//#endif

//4.判断是否被编译:与三同义
//#ifndef DEBUG
//#endif

//5.
//#if 常量表达式
// 
//#endif

//6.多分支的条件编译:
//#if 常量表达式
// 
//#elif 常量表达式
// 
//#end if 常量表达式
// 

//7.嵌套指令:



//#define DEBUG
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		//调试性的代码:
//#ifdef DEBUG//<==>#if defined(DEBUG)
//		printf("%d ", arr[i]);
//#endif
//	}
//	return 0;
//}



//头文件包含:
//1.本地头文件:查找策略：先在源文件所在目录下查找，如果该头文件未找到，编译器就像查找库函数头文件一样在标准位置查找头文件。如果找不到就提示编译错误。
//#include "..."
//2.库文件:查找头文件直接去标准路径下去查找，如果找不到就提示编译错误。
//#include <>
//这样是不是可以说，对于库文件也可以使用 “” 的形式包含？
//答案是肯定的，可以。
//但是这样做查找的效率就低些，当然这样也不容易区分是库文件还是本地文件了。




//头文件被重复包含:
//如果一个.c程序多次包含了.h文件,在预编译的过程中可能导致头文件被包含多次,导致代码冗余,运行速度慢
//两种条件编译来解决这类问题:
//1.
//某.h文件:(等下一次再次包含头文件时因为已将__TEST_H__定义过则#ifndef条件为假)
//	    #ifndef __TEST_H__
//  	#define __TEST_H__
//	    //头文件内容:
//	    #endif

//2.
//某.h文件:()
//		#pragma once
//		//头文件内容:





//请编写宏，计算结构体中某变量相对于首地址的偏移，并给出说明:
//1.自带函数实现:
//#include<stddef.h>
//struct S
//{
//	char c1;//0-1
//	int a;//4-8
//	char c2;//9
//	//9!=4的整数倍————————>共占12字节
//};
//int main()
//{
//	struct S s;
//	printf("%d", (int)offsetof(struct S, c1));
//	printf("%d", (int)offsetof(struct S, a));
//	printf("%d", (int)offsetof(struct S, c2));
//	return 0;
//}



//2.宏定义实现:
//#define OFFSETOF(struct_name,struct_member) (size_t)&(((struct_name*)0)->struct_member)
//struct S
//{
//	char c1;//0-1
//	int a;//4-8
//	char c2;//9
//	//9!=4的整数倍————————>共占12字节
//};
//int main()
//{
//	struct S s;
//	printf("%d ", (int)OFFSETOF(struct S, c1));
//	printf("%d ", (int)OFFSETOF(struct S, a));
//	printf("%d ", (int)OFFSETOF(struct S, c2));
//	return 0; 
//}



////理解:
////有结构体:
//struct S
//{
//	char c1;
//	int a;
//	char c2;
//};
//struct S s;
////有此结构体相对的指针:
//struct S* p = &s;
////说明p的值为s的地址而p是s的结构体指针
//p->c1
////通过结构体指针 找到 指针对应的结构体 的结构体成员
//
////同理:
////对于((struct S*)0)也同样可以理解成一个结构体指针,指针所对应的结构体的首地址就是0，
////那么用该指针指向结构体成员:((struct S*)0)->c1
////再取其地址:&( ((struct S*)0)->c1 )就得到了以首地址为0的结构体 的成员 的地址(即为偏移量)




























































































































