//#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//理解:
//1.
//指针、数组反复横跳的理解:
//函数:                   int Add (int x,int y)
//函数指针:               int (*p) (int ,int)
//函数指针数组:           int (*p_arr[]) (int ,int )
//指向函数指针数组的指针: int (*(*p_p_arr)[]) (int ,int)   =   &(p_arr)
//一个指针去掉指针名得到指针的类型
//一个指针去掉(*指针名)得到这个指针指向的东西的类型
//一个数组去掉数组名得到数组的类型
//一个数组去掉(数组[])名得到这个数组成员的类型


//2.
//理解:1.arr[j]<==>*(arr+j):这里的arr理解为&arr[0]
//理解:2.(*p)<==>arr<==>&arr[0];(*p)+j<==>&arr[j];*( (*p)+j )<==>*( &arr[j] );*( (*(p+i))+j )<==>*( &arr[i][j] )<==>arr[i][j]






//一:
//int main()
//{
//	//char arr[] = "abcdef";
//	//char* p = arr;
//	//printf("%s\n", p);
//	//printf("%s\n",arr);
//	////printf("%c\n",p);//行不通
//	//printf("%c\n", p[0]);//可以------>*(p+0)<==>p[0]
//	//                     //与给函数传arr,用char*p接收的意思相近
//
//
//	//const char* m = "abc";//加const保护字符常量
//	//printf("%s\n", m);
//	//printf("%c\n", *m);
//
//	return 0;
//}
//总结:无论1.char*p------->arr------->"abcdef"  2.har*p------->"abc"
//     都不能直接用p来打印首字母，即使p=&arr[0],因为要解引用




//二:
//指针数组
//int main()
//{
//	int arr1[] = { 1,2,3,4 };
//	int arr2[] = { 5,6,7,8 };
//	int arr3[] = { 9,10,11,12 };
//	int* p[3] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%2d ", *(p[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}
	




//三:
//数组指针
//一维数组用数组指针太啰嗦，不如直接用指针指向数组
//int main()
//{
//	int	arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*p)[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{                            // p<==>&arr
//		printf("%d ", *((*p)+i));//*p<==>arr<==>arr[0]
//	}
//	return 0;
//}
//指针指向数组
//int main()
//{
//	int	arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);//p[i]<==>*(p+i)
//	}
//	return 0;
//}





//二维数组普通打印:
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void printf2(int(*p)[5], int x, int y)//p<==>&arr[5],即arr第一排的数组总地址
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", p[i][j]);//写成*((*(p+1))+j) or (*(p+1))[j] or p[i][j]都行
//		}  
//               //理解:1.arr[j]<==>*(arr+j):这里的arr理解为&arr[0]
//               //理解:2.(*p)<==>arr<==>&arr[0];(*p)+j<==>&arr[j];*( (*p)+j )<==>*( &arr[j] );*( (*(p+i))+j )<==>*( &arr[i][j] )<==>arr[i][j]
// 
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr,3,5);
//	printf("\n");
//	printf2(arr, 3, 5);
//	return 0;
//}








//四:
//函数指针
//       void(*   signal(int ,void(*)(int))     )(int);
//signal是一个函数,返回值1:int 返回值2:一个函数指针，而这个函数指针指向的函数的返回值为int
//signal函数的返回值是一个函数指针，其指向的函数的返回值为int

//简化: (重定义函数指针)typedef      void(*)(int)        pfun_c---------------可以这样想但不能这样写
//可行:                 typedef    void(* pfun_c)(int)
//                      pfun_F  signal(int ,pfun_c)




//函数指针的*可以去掉:
//原因printf("%p",add)<==>printf("%p",&add),add<==>(*p)<==>&add<==>p
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 4;
//	int b = 2;
//	int (*p)(int x, int y) = Add;
//	printf("%d\n", (*p)(a, b));//()的结合性比*大:   *p(a,b)   (X错误)
//	printf("%d\n", (p)(a, b));//p(a, b)也可以
//	return 0;
//}






//五:
//函数指针数组:
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int (*p[4]) (int, int) = { Add,Minu,Mul,Dev };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n",(*p[i])(6, 3));//or:p[i](6,3)
//	}
//	return 0;
//}





//例子:
//char * my_strcpy(char * dest,const char * sour)
//my_strcpy的函数指针:char *(*pf)(char * dest,const char * sour)//简写:char *(*pf)(char * ,const char * )
//存放my_strcpy类型的函数的函数指针的函数指针数组;
//char *(*pf_Arr[4])(char * dest,const char * sour)简写:char *(*pf_Arr[4])(char * ,const char * )




//version 1.计算器:
//缺点:代码比较庞杂，而且难于添加新功能函数
//void menu()
//{
//	printf("#############################\n");
//	printf("###    1.plus    2.sub    ###\n");
//	printf("###    3.mul     4div     ###\n");
//	printf("###        0.exit         ###\n");
//	printf("#############################\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择算法!\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1:
//			{
//				printf("请你输入两个操作数！\n");
//				scanf("%d%d", &x, &y);
//				printf("%d\n", Add(x,y));
//				break;
//			}
//			case 2:
//			{
//				printf("请你输入两个操作数！\n");
//				scanf("%d%d", &x, &y);
//				printf("%d\n", Sub(x,y));
//				break;
//			}
//			case 3:
//			{
//				printf("请你输入两个操作数！\n");
//				scanf("%d%d", &x, &y);
//				printf("%d\n", Mul(x,y));
//				break;
//			}
//			case 4:
//			{
//				printf("请你输入两个操作数！\n");
//				scanf("%d%d", &x, &y);
//				printf("%d\n", Div(x,y));
//				break;
//			}
//			case 0:
//			{
//				printf("退出计算器\n");
//				break;
//			}
//			default:
//			{
//				printf("输入错误，请重新输入\n");
//				break;
//			}
//		}
//	} while (input);
//}








//version 2.计算器
//
//回调函数:
//Calc()------相当于中转站，参数是函数(Add)地址，内容中有回调这个函数(Add)
// 
//仍用switch case语句，但运用函数Calc(含回调函数（Add）)并结合函数指针减少了case语句中大量冗杂的部分(重复部分)
//void menu()
//{
//	printf("#############################\n");
//	printf("###    1.plus    2.sub    ###\n");
//	printf("###    3.mul     4div     ###\n");
//	printf("###        0.exit         ###\n");
//	printf("#############################\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void Calc(int (*pf)(int, int))//虽然pf代表函数地址，pf代表函数，但用pf引用函数式可以省略’* ’
//{
//	int x = 0;
//	int y = 0;
//	printf("请你输入两个操作数！\n");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", (*pf)(x,y));//虽然pf代表函数地址，pf代表函数，但用pf引用函数式可以省略’* ’
//}
//
//int main()
//{
//	
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择算法!\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1:
//			{
//				Calc(Add);
//				//printf("请你输入两个操作数！\n");
//				//scanf("%d%d", &x, &y);
//				//printf("%d\n", Add(x,y));
//				break;
//			}
//			case 2:
//			{
//				Calc(Sub);
//				//printf("请你输入两个操作数！\n");
//				//scanf("%d%d", &x, &y);
//				//printf("%d\n", Sub(x,y));
//				break;
//			}
//			case 3:
//			{
//				Calc(Mul);
//				//printf("请你输入两个操作数！\n");
//		        //scanf("%d%d", &x, &y);
//				//printf("%d\n", Mul(x,y));
//				break;
//			}
//			case 4:
//			{
//				Calc(Div);
//				//printf("请你输入两个操作数！\n");
//				//scanf("%d%d", &x, &y);
//				//printf("%d\n", Div(x,y));
//				break;
//			}
//			case 0:
//			{
//				printf("退出计算器\n");
//				break;
//			}
//			default:
//			{
//				printf("输入错误，请重新输入\n");
//				break;
//			}
//		}
//	} while (input);
//}







//version 3.计算器:
//函数指针数组:转移表
//优点:应用函数指针数组当转移表,代码简洁，易于添加新的功能函数
//void menu()
//{
//	printf("#############################\n");
//	printf("###    1.Add    2.Sub     ###\n");
//	printf("###    3.Mul    4.Div     ###\n");
//	printf("###    5.Xor    0.Exit    ###\n");
//	printf("#############################\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int Xor(int x, int y)
//{
//	return x ^ y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int (*p[])(int, int) = { 0, Add,Sub,Mul,Div,Xor };
//	do 
//	{
//		menu();
//		printf("请选择算法:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("请输入两个参数:>");
//			scanf("%d%d", &x, &y);
//			int ret = (*p[input])(x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出计算器\n");
//		}
//		else
//		{
//			printf("输入错误");
//		}
//    } while (input);
//}








//指针、数组反复横跳的理解:
//函数:                   int Add (int x,int y)
//函数指针:               int (*p) (int ,int)
//函数指针数组:           int (*p_arr[]) (int ,int )
//指向函数指针数组的指针: int (*(*p_p_arr)[]) (int ,int)   =   &(p_arr)
//一个指针去掉指针名得到指针的类型
//一个指针去掉(*指针名)得到这个指针指向的东西的类型
//一个数组去掉数组名得到数组的类型
//一个数组去掉(数组[])名得到这个数组成员的类型








//六:
//回调函数: 主函数传出函数地址----->外部函数用函数指针接收----->通过函数指针调用其他函数(不是函数的实现方直接调用)



//qsort中回调函数的理解:
//1:程序员写出自己的数组元素元素比较函数---comparison function。
//2:qsort中以参数形式定义了comparison function类型的函数指针，并在qsort函数体中通过函数指针引用了comparison function


//1.
//version 1.冒泡排序:
//缺点:功能单一，只能排序整形数组
//void bubble_sort(int *arr,int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)//每趟冒泡排序
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//
//}




#include<stdlib.h>
//version 2.qsort排序
//void* 类型的指针可以接收任意类型的地址,但因为不知道void*可以访问几个字节所以不能出现  void*p=&a;1.(*p) 2.(p++)
//qsort()---库函数----头文件#include<stdlib.h>
//void qsort(void* base,
//           size_t num,
//           size_t width, 
//           int(__cdecl* compare)(const void* elem1, const void* elem2)------>comparion function
//           );
// 
// 参数:1.待排序数组的首元素地址
//      2.待排序数组的元素个数
//      3.待排序数组中每个元素的大小---单位:字节
//	    4.函数指针--->比较数组中两个元素所用的函数地址---使用者自己实现
//		 (函数指针的两个参数是待排序的两个元素的地址)
// 
// return value of the comparion function:
//    Return Value Description
//     < 0    elem1 less than elem2
//     	 0    elem1 equivalent to elem2
//     > 0    elem1 greater than elem2

//1.整形比较
//int cmp_int(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);//void*类型的指针不能直接解引用
//}
//void test1()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//2.浮点型比较
//int cmp_float(const void* f1, const void* f2)
//{
//	return ( (int) (*(float*)f1 - *(float*)f2) );//void*类型的指针不能直接解引用
//}
//void test2()
//{
//	float arr[10] = { 10.0,9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_float);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f ", arr[i]);
//	}
//}


//3.1结构体成员比较:名字
//#include<string.h>
//struct Stu 
//{
//	char name[20];
//	int age;
//};
//int cmp_Stu_by_name(const void* s1, const void* s2)//首字母升序:由小到大
//{
//	return strcmp(((struct Stu*)s1)->name, ((struct Stu*)s2)->name);//------------->strcmp(#include<string.h>)和comparion function的返回值规则相同
//}
//void test3()
//{
//	struct Stu arr[3] = { {"Zhang san",18},{"Li si",19},{"Wang wu",20} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_Stu_by_name);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("name:%s   ", arr[i].name);
//		printf("age:%d", arr[i].age);
//		printf("\n");
//	}
//}

 

//3.2结构体成员比较:年龄
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_Stu_by_age(const void* s1, const void* s2)//年龄升序:由小到大
//{
//	return (((struct Stu*)s1)->age-((struct Stu*)s2)->age);
//}
//void test4()
//{
//	struct Stu arr[3] = { {"Zhang san",18},{"Li si",19},{"Wang wu",20} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_Stu_by_age);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("name:%s   ", arr[i].name);
//		printf("age:%d", arr[i].age);
//		printf("\n");
//	}
//}
//int main()
//{
//	test1();//整形比较
//	test2();//浮点型比较
//	test3();//结构体成员比较:名字
//	test4();//结构体成员比较:年龄
//	return 0;
//}













//2:
//实现自己的qsort:
// 
// 
// 
//类比:
//void qsort(void* base,
//           size_t num,
//           size_t width, 
//           int(__cdecl* compare)(const void* elem1, const void* elem2)------>comparion function
//           );

//
//void swap(char* buf1, char* buf2, int width)//用指针接收等同于接收地址
//{
//	int i = 0;
//	for (i = 0; i < width; i++)                      //地址1 <-----间隔width个字节-----> 地址2 <-----间隔width个字节-----> 地址3<-----间隔n*width个字节------>地址n
//	{                                     //值:   0_0_0_00000                          0_0_0_00000                          00000000                           00000000
//		char temp = *buf1;          //            |_|_|________________________________| | |
//		*buf1 = *buf2;          //                  |_|__________________________________| |
//		*buf2 = temp;          //                     |____________________________________|   每一位一次进行交换
//		buf1++;
//		buf2++;
//	}
//}
//
////自定义的comparion function
//int cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);//void*类型的指针不能直接解引用
//}
//
//
//void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* p1, const void* p2))
////width用处:因为void*不知到一次可以访问几个字节，而类型有不能传参所以用字节宽度代替类型
////实现bubble_sort的程序员不知到bubble_sort将会用于比较什么类型的元素，所以函数指针的参数用void*
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)//趟数
//	{
//		for (j = 0; j < sz - 1 - i; j++)//每一趟进行两个元素的比较
//		{
//			//需要一个定义数组元素比较的函数，不然不知道比什么数据类型
//			if (cmp((char*)base + width * j, (char*)base + width * (j + 1)) > 0)//1趟 : 第一个元素base，第二个元素(char*)base+wideth   (j==0)
//				                                                                //2趟 : 第二个元素(char*)base+width，第三个元素(char*)base+width*2     (j==1)
//				                                                                //3趟 : 第三个元素(char*)base+width*2，第四个元素(char*)base+width*3    (j==2)
//			{
//				//交换
//				swap((char*)base + width * j, (char*)base + width * (j + 1),width);//传的是指针等同于地址
//			}
//				                                                  
//		}
//	}
//}
//
//
//void test()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//使用bubble的程序员一定知道自己排序的是什么数据
//	//应该知道如何比较数组中的元素
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	test();
//	return 0;
//}






//3.
//用自己的bubble_sort实现结构体变量的排序:
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//void swap(char* buf1, char* buf2, int width)//用指针接收等同于接收地址
//{
//	int i = 0;
//	for (i = 0; i < width; i++)                      //地址1 <-----间隔width个字节-----> 地址2 <-----间隔width个字节-----> 地址3<-----间隔n*width个字节------>地址n
//	{                                     //值:   0_0_0_00000                          0_0_0_00000                          00000000                           00000000
//		char temp = *buf1;          //            |_|_|________________________________| | |
//		*buf1 = *buf2;          //                  |_|__________________________________| |
//		*buf2 = temp;          //                     |____________________________________|   每一位一次进行交换
//		buf1++;
//		buf2++;
//	}
//}
//
//int cmp(const void* s1, const void* s2)//年龄升序:由小到大
//{
//	return (((struct Stu*)s1)->age-((struct Stu*)s2)->age);
//}
//
//void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* p1, const void* p2))
////width用处:因为void*不知到一次可以访问几个字节，而类型有不能传参所以用字节宽度代替类型
////实现bubble_sort的程序员不知到bubble_sort将会用于比较什么类型的元素，所以函数指针的参数用void*
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)//趟数
//	{
//		for (j = 0; j < sz - 1 - i; j++)//每一趟进行两个元素的比较
//		{
//			//需要一个定义数组元素比较的函数，不然不知道比什么数据类型
//			if (cmp((char*)base + width * j, (char*)base + width * (j + 1)) > 0)//1趟 : 第一个元素base，第二个元素(char*)base+wideth   (j==0)
//				//2趟 : 第二个元素(char*)base+width，第三个元素(char*)base+width*2     (j==1)
//				//3趟 : 第三个元素(char*)base+width*2，第四个元素(char*)base+width*3    (j==2)
//			{
//				//交换
//				swap((char*)base + width * j, (char*)base + width * (j + 1), width);//传的是指针等同于地址
//			}
//
//		}
//	}
//}
//
//void test4()
//{
//	struct Stu arr[3] = { {"Zhang san",18},{"Li si",19},{"Wang wu",20} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("name:%s   ", arr[i].name);
//		printf("age:%d", arr[i].age);
//		printf("\n");
//	}
//}
//
//int main()
//{
//	test4();
//	return 0;
//}


