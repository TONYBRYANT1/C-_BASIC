#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//1.
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = a;
//	*(p+2) += 2;//p[2]=p[2]+2  �ı���a[2]��ֵ
//	int i = 0;
//	for (i = 0; i < 9; i++)
//	{
//		printf("%d", a[i]);
//	}
//	return 0;
//}


//2.�����ַ���
#include<string.h>
#include<assert.h>
//1.
//void Reverse(char* a)
//{
//	char* left = a;
//	int len = strlen(a) - 1;//5
//	char* right = a + len;//123456
//		            //012345
//	char temp = *left;
//	*left = *right;
//	*right = temp;
//	left++;
//	right--;
//}
// 
//2.
//void Reverse(char*a)
//{
//	assert(a);
//	int left = 0;
//	int right = (signed int)strlen(a)-1;
//	while (left < right)
//	{
//		char temp = a[left];
//		a[left] = a[right];
//		a[right] = temp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char a[256] = {0};//����ʼ��Ϊ{0};ʱ���ǵó�ʼ���ַ�����Ĵ�С
//	//scanf("%s", a);
//	gets_s(a);
//	Reverse(a);
//	printf("%s", a);
//	return 0;
//}



//3.2+22+222+2222...
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d%d", &a, &n);
//	int i = 0;
//	int ret = 0;
//	int sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}
//

//4.0-100000֮���������:
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//1.�ж�λ��:
//		int temp = i;
//		int n = 0;
//		while (temp)
//		{
//			temp /= 10;
//			n++;
//		}
//		//2.ÿһλ��n�η�֮��:
//		temp = i;
//		int sum = 0;
//		while (temp)
//		{
//			sum +=(int)pow(temp % 10,n);
//			temp /= 10;
//		}
//		//3.�ж�sum��i�Ƿ����:
//		if (i == sum)
//		{
//			printf("%d  ", i);
//		}
//	}
//	
//}


//��δ���:
//int function(int i)//123
//{
//	if (i > 10)
//	{
//		return ((i % 10) ^ 3 + function(i / 10));//27+8+1
//	}
//}
//int function(int i)//12
//{
//	if (i > 10)
//	{
//		return ((i % 10) ^ 3 + function(i / 10));//8+1
//	}
//}
//int function(int i)//1
//{
//	if (i > 10)
//	{
//		return ((i % 10) ^ 3 + function(i / 10));
//	}
//	else
//	{
//		return i ^ 3;
//	}
//}
//int function(int i)//1
//{
//	if (i > 10)
//	{
//		return ((i % 10) ^ 3 + function(i / 10));
//	}
//	else
//	{
//		return i ^ 3;
//	}
//}
//void zimi(int n)
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i <= n; i++)
//	{
//		
//	}
//}
//int main()
//{
//	int n = 0;
//	zimi(n);
//
//	return 0;
//}






//5.
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********
//  *********
//   *******
//    *****
//     ***
//      *
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int len = 0;
//	scanf("%d", &len);
//	//�ϰ벿��:
//	for (i = 0; i < len; i++)
//	{
//		int j = 0;
//		for (j = 0; j < len - i - 1; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2*i+ 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//�°벿��:
//	for (i = 0; i < len - 1; i++)//0 11 1 9 2 7
//	{
//		int j = 0;
//		for (j = 0; j < i + 1; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < (2*(len-1)-1- 2 * i); j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}






//6.struct stu a;
//struct stu*p=&a;
//*p.a(��)-----(*p).a(��)



//7.����ˮ����:һƿ��ˮһԪ��������ƿ��һƿ��ˮ���ܹ����Ժȶ���ƿ��ˮ��
//1.�߼�
//int main()
//{
//	���������ˮ
//	int money = 0;
//	scanf("%d", &money);
//	int total = 0;
//	int empty = 0;
//	total = money;
//	empty = money;
//	�ǿ�ƿ�ӻ�����ˮ:
//	while (empty >= 2)
//	{
//		total += empty / 2;//����ˮ
//		empty = empty / 2 + empty % 2;//�Ȼ�����ˮʣ�¿�ƿ����
//	}
//	printf("%d", total);
//	return 0;
//}
//2.��ѧ����
//int main()
//{
//	//���������ˮ
//	int money = 0;
//	scanf("%d", &money);
//	int total = 0;
//	if (money == 0)
//	{
//		total = 0;
//	}
//	else
//	{
//		total = (money * 2) - 1;
//	}
//	printf("%d", total);
//	return 0;
//}




//8.��move������һ������������������ż�������ұ�:
//void move(int* arr, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		//������ż��:
//		while ((left <= right) && arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		//����������
//		while ((right >= left) && arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		if (right > left)
//		{
//			int temp = 0;
//			temp = arr[left];
//			arr[left] = arr[right];
//			 arr[right]=temp;
//
//		}
//	}
//}
//void print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr,sz);
//	return 0;
//}



//9.����:
#include<assert.h>
#include<string.h>
//1.������ⷨ:
//void left_move(char* arr,int k)
//{
//	assert(arr != NULL);//or assert(arr)
//	int len = (int)strlen(arr);
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		char temp = arr[0];
//		int j = 0;
//		for (j = 0; j < len-1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = temp;
//	}
//}
//2.������ת��:
//void reverse(char* left, char* right)
//{
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//void left_move(char* arr, int k)
//{
//
//	int len = strlen(arr);
//	assert(arr);
//	assert(k <= len);
//	reverse(&arr[0], &arr[k - 1]);
//	reverse(&arr[k], &arr[len - 1]);
//	reverse(&arr[0], &arr[len - 1]);
//}
//int main()
//{
//	int k = 0;
//	scanf("%d", &k);
//	char arr[20] = "abcdef";
//	left_move(arr,k);
//	printf("%s", arr);
//	return 0;
//}


//9.2.0:�ж�һ���ַ������Ƿ�����һ���ַ�������ת����
//0:abcdef
//1:bcdefa
//2:cdefab
//3:defabc
//4:efabcd
//5:fabcde
//6:abcdef
//void reverse(char* left, char* right)
//{
//	assert(left);
//	assert(right);
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//}
//void move(char* arr, int k)
//{
//
//	int len = strlen(arr);
//	assert(arr);
//	assert(k <= len);
//	reverse(&arr[0], &arr[k - 1]);
//	reverse(&arr[k], &arr[len - 1]);
//	reverse(&arr[0], &arr[len - 1]);
//}
//int is_reverse(char* arr1, char* arr2)
//{
//	int i = 0;
//	int len = strlen(arr1);
//	for (i = 0; i < len; i++)
//	{
//		move(arr1, 1);
//		if (strcmp(arr1, arr2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[20] = "cdefab";
//	int ret=is_reverse(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("YES");
//	}
//	else
//	{
//		printf("NO");
//	}
//}


//����strstr�ķ���ֵ��ĸ�����Ӵ������ַ��ĵ�һ���ַ��ĵ�ַ(ĸ���еĵ�ַ)
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "bc";
//	printf("%p\n", arr1);
//	printf("%p\n", arr2);
//	printf("%p",strstr(arr1, arr2));
//}


//9.2.1:�ж�һ���ַ������Ƿ�����һ���ַ�������ת����
//precondition(ǰ��):
//strcatֻ������������ͬ���ַ���
//strncar����������ͬ��ͬ���ַ���
//ĸ��:
//strncat(arr1,arr1,len)
//abcdefabcdef\0
//�Ӵ�:
//bcdefa\0
// 
// 
// 
//int is_move(char* arr1, char* arr2)
//{
//	//�ж������ַ��������Ƿ����:
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	//����:
//	assert(arr1);
//	assert(arr2);
//	//ĸ���γ�:
//	
//	strncat(arr1, arr1, len1);
//	//�Ӵ�����ĸ��:
//	if (strstr(arr1, arr2) == NULL)//return �ַ�e�ĵ�ַ
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "efabcd";
//	int ret=is_move(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("YES");
//	}
//	else
//	{
//		printf("NO");
//	}
//	return 0;
//}




//9.3:�����Ͼ�����������
//���Ͼ���:
//      ��:1 2 3   ÿ�д������������� 
//         4 5 6   ÿ�д��ϵ�����������
//         7 8 9
// 
// 
//version 1:
// 
//int Find(int (*a)[3], int k, int row,int col )
//{
//	int x = 0;
//	int y = col-1;
//	while (x <=row - 1 && y>=0)
//	{
//		if (a[x][y] < k)
//		{
//			x++;
//		}
//		else if (a[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 0;
//	scanf("%d", &k);
//	int ret = Find(arr, k, 3, 3);
//	if (ret == 1)
//	{
//		printf("�ҵ���!");
//	}
//	else
//	{
//		printf("δ�ҵ�!");
//	}
//}

//version 2:�����Ͳ���
//������ӡk���ڵ�����1.�ں�����ֱ�Ӵ�ӡ(��������࣬�Ƚ�low) 2.����x,y��ֵ(���Ѿ����˷���ֵ1���������)
//���÷����Ͳ���:��row��col����Ϊ��ֵ����(1.���������к����ں���)(2.��������x,y���жϱ�׼1or��)
//int Find(int(*a)[3], int k, int *x, int *y)
//{
//	assert(x);
//	assert(y);
//	int row = *x;
//	int col = *y;
//	*x = 0;
//	*y = col - 1;
//	while (*x <= row - 1 && *y >= 0)
//	{
//		if (a[*x][*y] < k)
//		{
//			(*x)++;
//		}
//		else if (a[*x][*y] > k)
//		{
//			(*y)--;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 0;
//	int x = 3;
//	int y = 3;
//	scanf("%d", &k);
//	int ret = Find(arr, k, &x, &y);//���÷����Ͳ���----��һ��˫��
//	if (ret == 1)
//	{
//		printf("�ҵ���!\n");
//		printf("��ַΪ(%d,%d)", x, y);
//	}
//	else
//	{
//		printf("δ�ҵ�!");
//	}
//}
