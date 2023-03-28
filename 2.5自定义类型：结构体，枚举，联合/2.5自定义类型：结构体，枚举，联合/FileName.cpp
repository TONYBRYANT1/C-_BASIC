#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//char int short float...-----c语言内置类型
//复杂类型:结构体，枚举，联合体
//1.声明一个学生类型，是想通过学生类型创建学生变量(对象)
//结构体类型:
//struct stu
//{
//	//结构体的成员变量:
//	char name[20];
//	int age;
//}s1,s2,s3;//全局变量:
////全局变量:
//struct stu stu3;
//int main()
//{
//	//局部变量:
//	struct stu stu1;
//	struct stu stu2;
//	return 0;
//}



//结构体自引用:
//链表概念:
//struct node
//{
//	int data;//数据域
//	struct node* next;//指针域
//};




//typedef:
//typedef struct stu
//{
//	//结构体的成员变量:
//	char name[20];
//	int age;
//}stu;
//or
//typedef struct stu stu;





//设置默认对齐数为4:
//#pragma pack(1)
//结构体内存对齐:
//1. 第一个成员在与结构体变量偏移量为0的地址处。
//2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
//对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
//VS中默认的值为8
//3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
//4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整
//体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。
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
////取消设置的默认对齐数
////#pragma pack ()
//
////写一个宏，计算结构体中某变量开头地址相对于首地址的偏移
////size_t offsetof(structName, memberName);
//#include<stddef.h>
//int main()
//{
//	printf("%d\n", (int)offsetof(stu, a));
//	printf("%d\n", (int)offsetof(stu, b));
//	printf("%d\n", (int)offsetof(stu, c));
//	return 0;
//}






//结构体传参:
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
////p2比较好，函数传参的时候，参数是需要压栈的，会有时间和空间上的系统开销，若选择传值，系统开销过大，导致性能下降。
//int main()
//{
//	struct stu s1 = { 0 };
//	init(&s1);
//	printf1(s1);
//	printf2(&s1);
//	printf("%c", s1.a);
//	return  0;
//}





//位段:(二进制位)
//目的:节省空间
//struct S
//{
//	//一个int---4byte---32bit
//	//一个int可以表达2^32种状态，而a用不了那么多(仅仅表达:0,1,2,3),于是用2(2个二进制位)来限制
//	int a : 2;//2个二进制位---bit位
//	int b : 5;//5个二进制位
//	int c : 10;//10个二进制位
//	int d : 30;//30个二进制位
//};
////47bit---6byte就够了(有浪费)
//int main()
//{
//	struct S s;
//	printf("%d", (int)sizeof(s));//8 byte
//	return 0;
//}



//枚举:
//enum color
//{
//	RED=10,//枚举常量赋初值
//	GREEN=20,
//	BLUE=30
//};
//int main()
//{
//	enum color c = RED;
//	printf("%d\n", c);
//	printf("%d\n", (int)sizeof(c));//类型大小为4byte
//	return 0;
//}






//联合---联合体---共用体
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




//判断大小端 && 巧妙运用联合体来判断大小端
//int check_sys1()
//{
//	int a = 1;
//	return *(char*)&a;
//	//反1:小端
//	//反0:大端
//}
//int check_sys2()//巧妙运用联合体来判断大小端
//{
//	union U//类型------------因为仅仅使用一次所以可以不写U
//	{
//		char i;//01 00 00 00
//		int n;// |        |
//	}u;//名称    |--------|
//	u.n = 1;//   i   |
//	return u.i;//    |
//	//反1:小端       n
//	//反0:大端
//}
//int main()
//{
//	//int a = 1;//00 00 00 01
//	////小端字节序存储模式:(低->高):01 00 00 00 
//	////大端字节序存储模式:(低->高):00 00 00 01
//	//char* p = (char*)&a;
//	//printf("%d\n",(int)*p);
//	////or
//	//printf("%d\n", *(char*)&a);
//	////or
//	//int ret = check_sys1();
//	//if (1 == ret)
//	//{
//	//	printf("小端\n");
//	//}
//	//else
//	//{
//	//	printf("大端\n");
//	//}
//	////or
//	int ret = check_sys2();
//	if (1 == ret)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}





//联合体的大小:
//联合的大小至少是最大成员的大小。
//当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。
//对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
//union Un
//{
//	int a;//该成员大小的较小值:4  默认对齐数:8  对齐数:4
//	char arr[5];//相当于写了5个char //该成员大小的较小值:1  默认对齐数:8  对齐数:1  
//	//最大对齐数:4  最大成员大小:5  对齐:8
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
//	//最大对齐数:4  最大成员大小:5  联合体所占空间大小:4*2=8>5
//};
//int main()
//{
//	union U u;
//	printf("%d", (int)sizeof(u));
//}