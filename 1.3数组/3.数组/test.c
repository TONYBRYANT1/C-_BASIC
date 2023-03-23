#define _CRT_SECURE_NO_WARNINGS
//基础
//#include<stdio.h>
//#include<string.h>
//int main()
//{
////1.
//	//char arr[] = { 'a',98,'\0' };//98--->'b'
//	//printf("%d", sizeof(arr));//字符总共占用的空间大小
//	//printf("%d", strlen(arr));//字符长度（不包括\0）
//	//strlen--->针对字符串---是库函数----要引用头文件
//	//sizeof--->针对变量，数组，类型所占空间大小----单位是字节byte-----操作符
//
//
////2.
//	//char arr[] = "abcdef";
//	//int i = 0;
//	//for (i = 0; i <(int)strlen(arr); i++)//strlen---返回无符号的整数---加（int）strlen---强制类型转换
//	//{
//	//	printf("%c ", arr[i]);
//	//}
//
//
////3.
//	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };//数组在内存中连续存放
//	//int sz=sizeof(arr) / sizeof(arr[0]);
//	//int i = 0;
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("&arr[%d]=%p\n", i, &arr[i]);
//	//}
//
//
//
////4.
//	//int arr[3][4] = { {1,2,3},{4,5,6} };//行可以省略但列不能省略------>一定要确定一个子数组中有几个元素，但不用确定有几个子数组
//	//int i = 0;							//二维数组在内存中同样连续存放
//	//int j = 0;							//同样可以把二维数组中的a[0](a[0][j])看成数组名---类似于一维数组中的arr(数组名)
//	//for (i = 0; i < 3; i++)
//	//{
//	//	for (j = 0; j < 4; j++)
//	//	{
//	//		printf("&arr[%d][%d] = %p\n",i,j,&arr[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//
//	return 0;
//}







////冒泡排序
//#include<stdio.h>
//void bubble_sort(int* arr, int sz1)//这里写(int arr[])([]不能丢！！！)还是写(int* arr)都是一个意思，反正arr就是一个整形指针
////main函数中arr的传参相当于传了arr[0]的地址(&arr[0])--->一个整形的地址,需要一个整形指针来接收
////而(int arr[])([]不能丢！！！)<==>(int* arr)---->这里的arr相当于一个整形指针
//{
//	int i = 0;
//    //int sz = sizeof(arr) / sizeof(arr[0]);  
////计算数组的大小不能在这里:第一个sizeof(arr)表示整形指针的大小  第二个sizeof(arr[0])代表第一个元素的大小元素的大小
////但为什么及时是用了(int sz = sizeof(arr) / sizeof(arr[0]);  )他的值是二而不是一呢？？？
////因为此电脑是64位机有64根地址线有2^64中排列方式来表达地址,其中arr[0]的地址由64个0/1排列而成共64位<==>8字节
//	for (i = 0; i < (sz1 - 1); i++)//冒泡排序的<<趟数>>
//	{
//		int flag = 1;//假设这一趟已经有序了---------------------------------------算法优化
//		int j = 0;
//		for (j = 0; j < (sz1 - 1 - i); j++)//转换一趟的总对数
//		{
//			if (arr[j] > arr[j + 1])//转换一对
//			{
//				int temp = 0;
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				flag = 0;//本次需要排列的数列无序---------------------------------算法优化
//			}
//		}
//		if (flag == 1)//已经有序了，不用再排了！！！------------------------------算法优化
//		{
//			break;//注:如果只是单层的if,不能用break，但是此处的if用在for循环中就可以用
//				  //break----仅仅用于1.循环  2.Switch语句中
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//arr数组中的元素个数
//	bubble_sort(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}






//数组名是首元素的地址
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	printf("%p \n", arr);
//	printf("%p \n", &arr[0]);
//	printf("%d \n", *arr);
//	printf("%d \n", *(&arr[0]));
//	return 0;
//}
//两个例外
//1.sizeof(数组名)===表示整个数组所占的空间大小
//例:int sz =sizeof(arr)/sizeof(arr[0]);====数组所占空间总大小/一个元素所占的空间大小===表示元素个数
//2.&arr表示整个数组的地址(虽然在值上和&arr[0]相同，但后者表示首元素地址)
//例:
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	////1.
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//printf("%d", sz);//结果为:10---->10个元素
	//2.
	//printf("%p\n", &arr[0]);//结果:000000D825CFFB78
	//printf("%p\n", arr);//结果:000000D825CFFB78
	//printf("%p\n", &arr);//结果:000000D825CFFB78
	//但:
//	printf("%p\n", &arr[0]);   //0000002674B6F618
//	printf("%p\n", &arr[0]+1); //0000002674B6F61C    变化4(10进制)
//
//	printf("%p\n", arr);  //0000002674B6F618
//	printf("%p\n", arr+1);//0000002674B6F61C         变化4(10进制)
//	
//	printf("%p\n", &arr);  //0000002674B6F618
//	printf("%p\n", &arr+1);//0000002674B6F640        变化40(10进制)
//	printf("%d",sizeof(arr[0]));
//	return 0;
//}