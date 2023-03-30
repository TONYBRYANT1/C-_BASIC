#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//vs是否可以创建变长数组？

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n]; //表达式必须含有常量值
//	return 0;
//}
//visual studio 2022中暂时不能实现

//malloc and free
//malloc:
//动态开辟的空间初始值为随机值(相较于calloc的效率高但是没有初始化)
//Allocates(开辟) memory blocks.
//void* malloc(size_t size);
//parameter:size_t size
//return value:malloc returns a void pointer to the allocated space, or NULL if there is insufficient memory available. 
//free:
//void free(void* memblock);
//Parameter:memblock
//ReturnValue:None





#include<stdlib.h>
#include<string.h>
#include<errno.h>
//int main()
//{
//	//向堆区申请10个整型的空间:
//	int *p=(int*)malloc(INT_MAX);//申请空间单位是字节,并将动态开辟的空间交给p去管理
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));//Not enough space
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d\n", *(p + i));
//		}
//	}
//	free(p);//用来释放动态开辟的内存//parameter为动态开辟空间时的管理者(如int*p)
//	p = NULL;//动态申请的内存被free释放之后p的地址仍然不变，为动态开辟内存的首地址，为了防止非法访问未开辟的空间，将p指向NULL
//	return 0;
//}



//calloc
//Allocates an array in memory with elements initialized to 0.
//动态开辟的空间的初始值为零(相较于malloc的效率低但初始化)
//void* calloc(size_t num, size_t size);
//parameter:
//num---Number of elements   size---Length in bytes of each element
//Return Value
//calloc returns a pointer to the allocated space.The storage space pointed to by the return value is guaranteed to be suitably aligned for storage of any type of object.To get a pointer to a type other than void, use a type cast on the return value.
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));//Not enough space
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d\n", *(p + i));
//		}
//		printf(" \n");
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d\n", *(p + i));
//		}
//	}
//	free(p);//用来释放动态开辟的内存//parameter为动态开辟空间时的管理者(如int*p)
//	p = NULL;//动态申请的内存被free释放之后p的地址仍然不变，为动态开辟内存的首地址，为了防止非法访问未开辟的空间，将p指向NULL
//	return 0;
//}



//realloc:
//Reallocate memory blocks.
//void* realloc(void* memblock, size_t size);
//Parameters:
//memblock---Pointer to previously allocated memory blocksizeNew  ,  size--- in bytes
//Return Value
//realloc returns a void pointer to the reallocated(and possibly moved) memory block.
//The return value is NULL if the size is zero and the buffer argument is not NULL,
//or if there is not enough available memory to expand the block to the given size.In the first case,
//the original block is freed.In the second, the original block is unchanged.
//The return value points to a storage space that is guaranteed to be suitably aligned for storage of any type of object.
//To get a pointer to a type other than void, use a type cast on the return value.
//int main()
//{
//	//向堆区申请10个整形的空间:
//	int *p=(int*)malloc(40);//申请空间单位是字节,并将动态开辟的空间交给p去管理
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));//Not enough space
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d\n", *(p + i));
//		}
//	}
//
//
//
//	//这里在使用malloc开辟的10个整型空间
//	//假设在这里10个整型空间不够我们使用
//	//希望再多加10个整型空间
//	//使用realloc调整动态开辟的内存
//	
//	//realloc使用的注意事项:
//	//1.如果p指向的空间之后有足够的内存空间可以追加，则追加，然后返回p
//	//2.如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重新找一个新的内存区域
//	//开辟一块满足需求的空间，并把原来内存中的数据拷贝回来，释放旧的内存空间
//	//最后返回新开辟内存空间的地址
//	//3.如果需求所需的空间太大，超过了realloc可开辟空间的范围，则反回NULL
//	//所以直接将realloc的返回值赋给p，存在一定的风险，需要应用另一个指针ptr去接受realloc的返回值，然后判断ptr是否为NULL，再做定论
//	
//	
//
//	int* ptr = (int *)realloc(p,10 * sizeof(int));
//	if (ptr != NULL)
//	{
//		int i = 0;
//		for (i = 10; i < 20; i++)
//		{
//			*(p + i) = i;
//		}
//		printf(" \n");
//		for (i = 0; i < 20; i++)
//		{
//			printf("%d\n", *(p + i));
//		}
//	}
//	free(p);//用来释放动态开辟的内存//parameter为动态开辟空间时的管理者(如int*p)
//	p = NULL;//动态申请的内存被free释放之后p的地址仍然不变，为动态开辟内存的首地址，为了防止非法访问未开辟的空间，将p指向NULL
//	return 0;
//}






//常见的一些错误:
int main()
{
	//1.对空指针进行解引用操作:
	//int* p = (int*)malloc(40);
	//*p = 1;
	//此操作存在风险，万一malloc失败，p将指向NULL,而对NULL解引用属于非法访问
	//因此解引用之前应该先判断p是否为空指针

	//2.对动态开辟内存的越界访问:
	/*int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		int i = 0;
		for (i = 0; i < 100; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 100; i++)
		{
			printf("%d", *(p + i));
		}
	}
	free(p);
	p = NULL;*/
	//越界访问，vs检查不严谨，居然没有报错


	//3.对非动态内存开辟的空间进行free
	//int a = 0;
	//int* p = &a;//a在栈区-----不能进行free!!!
	//*p = 10;
	//free(p);
	//p = NULL;
	//卡死
}