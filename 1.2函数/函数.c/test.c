#define _CRT_SECURE_NO_WARNINGS
//strcpy
//#include<string.h>
//#include<stdio.h>
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abc";
//	strcpy(arr1,arr2);
//	printf("%s", arr1);//arr1:abc\0ef\0 ��printf����\0��ֹͣ��
//	return 0;
//}





//memset----memory set
//#include<stdio.h>
//#include<memory.h>
//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, '&', 5);//void *memset( void *dest, int c//������ASCIIֵ�����, size_t count );
//	printf("%s", arr);
//	return 0;
//}




//get_max
//#include<stdio.h>
//int get_max(int x, int y)//��ֵ����
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



//swap---��ָ�뷽���
//#include<stdio.h>
//void swap(int* x, int* y)//����ַ����
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





//prime(����)����
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
//		}//ǧ��Ҫд�ɲ�������ĳһ����������������(8��������3,8Ҳ��������)(����Ҫ�����е�������һ��,����������������������)
//	}
//	(*ct)++;
//	return 1;
//	//(*ct)++;returnֱ�ӽ���ѭ�����Ը�ָ������
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
//	printf("\n����%d������",count);
//	return 0;
//}






//����
//#include<stdio.h>
//int run(int x, int* ct)//�����ĸ����Ը�,Ҫ�ɾ�,���  �м�:��Ҫ�ں������ʲôprintf("������...��");��Ӱ�츴����
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
//	printf("\n����%d������", count);
//	return 0;
//}








//����ʵ�ֶ��ֲ���
//#include<stdio.h>
//int binary_search(int arr[],int k,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
// //int mid = (left + right) / 2;ǧ���ܶ�������ȥ
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;//ǧ���ܶ�������ȥ
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
//	printf("����������Ҫ�ҵ���>: ");
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("�Ҳ���");
//	}
//	else
//	{
//		printf("�ҵ���,�±���%d", ret);
//	}
//		
//}





//ÿʹ��һ�κ���sum��һ
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





//����Ƕ��
//#include<stdio.h>
//void one_line(void)
//{
//	printf("����\n");
//}
//void three_line(void)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)   //1.����������Ϊvoid,��ôд����ʱ����ֱ�ӿ���/��д                   
//	{                         //2.�����ڱ�ʹ��ʱҪ��'()'��ʾ���Ǻ���
//		one_line();
//	}
//}
//int main()
//{
//	three_line();
//	return 0;
//}





//��ʽ����----һ�������Ľ����Ϊ��һ������������
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


//printf�ķ���ֵ int printf( const char *format [, argument]... );
//Return Value:
//Each of these functions returns the number of characters printed, or a negative value if an error occurs.
//#include<stdio.h>
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//}





////��������Ԥ����---����С����ҵ
////A.c---��������    B.c---���ú���     C.h---��������        (A.c��C.h���ɼӷ�ģ��)
//#include<stdio.h>
//#include "abdd.h";//�����Զ��庯����ͷ�ļ�����(��ͷ�ļ�������������,.c�ļ�����д�����Ķ���)
//int main()
//{
//	int a = 2;
//	int b = 0;
//	int k=add(a, b);
//	printf("%d", k);
//	return 0;
//}






//�����ݹ�---recursion   ��Ҫ������������ÿ�εݹ�Խ��Խ�ӽ����Ƶ�ֵ
//steak overflow----ջ���
//#include<stdio.h>
//void print(int k)//����û�з���ֵдvoid
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






////ģ��ʵ��strlen����//strlen����\0
//�ǵݹ��:
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
//	int r =  my_strlen(arr);//arr���ַ����飬���䴫��ʱ�൱�ڵ�һ��Ԫ�ص��׵�ַ
//	printf("%d", r);
//}
//�ݹ��(�޴�����ʱ����):
//#include<stdio.h>
//int my_strlen(char* p)//"bit"
//{ 
//	if ((*p) != '\0')//��������   
//  {                 //ʵ��ԭ��:bit0--->b(1)it0--->b(1)i(1)t0--->b(1)i(1)t(1)0--->1+1+1+0=3
//	
//		return (1 + my_strlen(++p));//�����������ƽ�
//	}
//	else return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	int r = my_strlen(arr);//arr���ַ����飬���䴫��ʱ�൱�ڵ�һ��Ԫ�ص��׵�ַ
//	printf("%d", r);
//}






//n�Ľ׳�
//�ǵݹ�:
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
//�ݹ��:
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







//쳲��������� 1 1 2 3 5 8 13 21 34 55...
//TDD---������������(д����ʱ��д������ô�ã���д������ôʵ�ֵķ���)
//#include<stdio.h>
//int counter = 0;
//int Fei1(int n)//(��)
//{
//	if (n == 3)//���������쳲�����������Ĵ���
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
//�ú���Ч��̫�ͣ�����
//ԭ��:��֧�ظ�̫��
//			   50----------------------------2^0
//	    49          48-----------------------2^1
//	  48    47    47    46-------------------2^2
//	47 46 46 45 46 45 45 44------------------2^3
//  ............................------------- -2^49
//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 -----------2^49
// ���ԣ�
//40
//ret = 102334155
//counter = 39088169
//D:\code\����.c\x64\Debug\����.c.exe(���� 22564)���˳�������Ϊ 0��
//��������رմ˴���. . .
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 0;
//	ret = Fei1(n);
//	printf("ret = %d", ret);
//	printf("\ncounter = %d",counter);
//}
//�ǵݹ�(��)
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







//�����ʵ���������stack overflow
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


//1.��ŵ��
//2.������̨��







