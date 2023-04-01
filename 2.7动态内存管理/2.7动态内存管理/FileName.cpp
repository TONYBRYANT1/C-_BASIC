#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//vs�Ƿ���Դ����䳤���飿

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n]; //[]�б��ʽ���뺬�г���ֵ
//	return 0;
//}
//visual studio 2022����ʱ����ʵ��

//malloc and free
//malloc:
//��̬���ٵĿռ��ʼֵΪ���ֵ(�����calloc��Ч�ʸߵ���û�г�ʼ��)
//Allocates(����) memory blocks.
//void* malloc(size_t size);
//parameter:size_t size
//return value:malloc returns a void pointer to the allocated space, or NULL if there is insufficient memory available. 
//free:
//void free(void* memblock);
//Parameter:memblock
//ReturnValue:None
//remarks:If memblock is NULL, the pointer is ignored and free immediately returns.





#include<stdlib.h>
#include<string.h>
#include<errno.h>
//int main()
//{
//	//���������10�����͵Ŀռ�:
//	int *p=(int*)malloc(INT_MAX);//����ռ䵥λ���ֽ�,������̬���ٵĿռ佻��pȥ����
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
//	free(p);//�����ͷŶ�̬���ٵ��ڴ�//parameterΪ��̬���ٿռ�ʱ�Ĺ�����(��int*p)
//	p = NULL;//��̬������ڴ汻free�ͷ�֮��p�ĵ�ַ��Ȼ���䣬Ϊ��̬�����ڴ���׵�ַ��Ϊ�˷�ֹ�Ƿ�����δ���ٵĿռ䣬��pָ��NULL
//	return 0;
//}



//calloc
//Allocates an array in memory with elements initialized to 0.
//��̬���ٵĿռ�ĳ�ʼֵΪ��(�����malloc��Ч�ʵ͵���ʼ��)
//void* calloc(size_t num, size_t size);
//parameter:
//num---Number of elements   size---Length in bytes of each element
//Return Value:
//calloc returns a pointer to the allocated space.The storage space pointed to by the return value is guaranteed to be suitably aligned for storage of any type of object.
//To get a pointer to a type other than void, use a type cast on the return value.
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
//	free(p);//�����ͷŶ�̬���ٵ��ڴ�//parameterΪ��̬���ٿռ�ʱ�Ĺ�����(��int*p)
//	p = NULL;//��̬������ڴ汻free�ͷ�֮��p�ĵ�ַ��Ȼ���䣬Ϊ��̬�����ڴ���׵�ַ��Ϊ�˷�ֹ�Ƿ�����δ���ٵĿռ䣬��pָ��NULL
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
//	//���������10�����εĿռ�:
//	int *p=(int*)malloc(40);//����ռ䵥λ���ֽ�,������̬���ٵĿռ佻��pȥ����
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
//	//������ʹ��malloc���ٵ�10�����Ϳռ�
//	//����������10�����Ϳռ䲻������ʹ��
//	//ϣ���ٶ��10�����Ϳռ�
//	//ʹ��realloc������̬���ٵ��ڴ�
//	
//	//reallocʹ�õ�ע������:
//	//0.realloc�����еĴ�СΪ���·���֮����ܴ�С����������׷�ӵĴ�С
//	//1.���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷�ӣ���׷�ӣ�Ȼ�󷵻�p
//	//2.���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷�ӣ���realloc������������һ���µ��ڴ�����
//	//����һ����������Ŀռ䣬����ԭ���ڴ��е����ݿ����������ͷžɵ��ڴ�ռ�
//	//��󷵻��¿����ڴ�ռ�ĵ�ַ
//	//3.�����������Ŀռ�̫�󣬳�����realloc�ɿ��ٿռ�ķ�Χ���򷴻�NULL
//	//����ֱ�ӽ�realloc�ķ���ֵ����p������һ���ķ��գ���ҪӦ����һ��ָ��ptrȥ����realloc�ķ���ֵ��Ȼ���ж�ptr�Ƿ�ΪNULL����������
//	
//	
//
//	int* ptr = (int *)realloc(p,20 * sizeof(int));
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
//	free(p);//�����ͷŶ�̬���ٵ��ڴ�//parameterΪ��̬���ٿռ�ʱ�Ĺ�����(��int*p)
//	p = NULL;//��̬������ڴ汻free�ͷ�֮��p�ĵ�ַ��Ȼ���䣬Ϊ��̬�����ڴ���׵�ַ��Ϊ�˷�ֹ�Ƿ�����δ���ٵĿռ䣬��pָ��NULL
//	return 0;
//}

//realloc���Ե���malloc��ʹ��
//��������mallocһ�������ֵ
//int main()
//{
//	int* p = (int*)realloc(NULL, 10 * sizeof(int));
//	printf("%d", *p);
//	free(p);
//	p = NULL;
//	return 0;
//}








//������һЩ����:
//int main()
//{
	//1.�Կ�ָ����н����ò���:
	//int* p = (int*)malloc(40);
	//*p = 1;
	//�˲������ڷ��գ���һmallocʧ�ܣ�p��ָ��NULL,����NULL���������ڷǷ�����
	//��˽�����֮ǰӦ�����ж�p�Ƿ�Ϊ��ָ��

	//2.�Զ�̬�����ڴ��Խ�����:
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
	//Խ����ʣ�vs��鲻�Ͻ�����Ȼû�б���


	//3.�ԷǶ�̬�ڴ濪�ٵĿռ����free
	//int a = 0;
	//int* p = &a;//a��ջ��-----���ܽ���free!!!
	//*p = 10;
	//free(p);
	//p = NULL;
	//����


	//4.ʹ��free�ͷŶ�̬���ٵ��ڴ��һ����
	//p���ı���---�Ѿ�����ָ��̬�����ڴ�������׵�ַ(��ʼ��ַ)��
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*p++ = i;//�����Ϊ*(p+i)=i;�Ͳ����������������
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//	//����
	//5.��ͬһ�鶯̬�ڴ����ͷ�:
	//int* p = (int*)malloc(10 * sizeof(int));
	//if (p == NULL)
	//{
	//	return 0;
	//}
	//else
	//{
	//	//ʹ��
	//}
	//free(p);
	//p = NULL;
	//free(p);//1.�������freeһ��p,p��ֵ��Ϊ��һ�ζ�̬�����ڴ�ĵ�ַ
	        //�ٴ�ʹ��freeʱ���ִ���
	        //2.���free��һ��p,���ҽ�p��ֵΪNULL��
	        //����һ�����ý�p free�ڶ���ʱ������p=NULL,free(NULL)��Ϊ��Ч


	//6.�Զ�̬���ٵ��ڴ������ͷ�(�ڴ�й©)
	/*while (1)
	{
		malloc(1);
	}*/
	//����ֱ�ӿ�����
//}






//���������Ա:
//struct S
//{
//	int a;
//	int b[];//���������Աǰ��������һ����Ա
//};
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));
//	struct S* p = (struct S*)malloc(sizeof(s) + 5 * sizeof(int));//4+20---��������b��5��Ԫ��
//	5 * sizeof(int);//---��������b��Ԫ�ظ���
//	p->a = 100;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		(p->b)[i]= i;
//	}
//	struct S* pt = (struct S*)realloc(p, sizeof(s) + 10 * sizeof(int));
//	if (pt != NULL)
//	{
//		p = pt;
//	}
//	for (i = 5; i < 10; i++)
//	{
//		(p->b)[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (p->b)[i]);
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//�������:
//struct S
//{
//	int a;
//	int* b;
//};
//int main()
//{
//	struct S* p = (struct S*)malloc(sizeof(struct S));
//	p->b = (int*)malloc(5 * sizeof(int));
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		(p->b)[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d",( p->b)[i]);
//	}
//	//����b��Ԫ�ظ���
//	int* bb = (int*)realloc(p->b, 10* sizeof(int));
//	if (bb != NULL)
//	{
//		p->b = bb;
//	}
//	for (i = 5; i <10 ; i++)
//	{
//		(p->b)[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", (p->b)[i]);
//	}
//	free(p->b);
//	p->b = NULL;
//	free(p);
//	p = NULL;
//	return 0;
// }
