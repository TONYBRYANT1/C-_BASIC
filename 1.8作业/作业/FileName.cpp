#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//   ��ҵ1:
//void trade(int* arr, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//		right--;
//		left++;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	trade(arr, sz);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}


//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	i--;
//	if (i > sizeof(i))//sizeof����һ���޷�������unsigned int�������з��������޷������Ƚ�ʱ���з�����ת���޷�������ȥ�Ƚ�
//		              //��-1ת�����޷�����
//		              //10000000000000000000000000000001
//		              //11111111111111111111111111111110
//		              //11111111111111111111111111111111-------��ǰ��ķ���λ��������λ-1�ͱ����һ���ܴ�������ʹ���4
//	{
//		printf("<\n");
//	}
//	else
//	{
//		printf(">");
//	}
//	return 0;
//}



//  ��ҵ��:
//һ�����Ĳ����м���1
//#include<stdio.h>
//1.
//˼·һ:��%2 /2��˼��
//int bin(unsigned int a)//�������������������ת���޷���������������
//{
//	int count = 0;
//	int i = 0;
//	while (a)//������д��(a!=0)
//	{   
//		if (a % 2 == 1)
//		{
//			count++;
//		}
//		a = a / 2;
//	}
//	return count; 
//	
//}
//2.
//˼·��:ͨ����λ�����εõ����һ������Ȼ���ж�������Ƿ�Ϊ1
//100000000000000000000000000000001
//111111111111111111111111111111110
//111111111111111111111111111111111
//��λ��1
//000000000000000000000000000000001
//int bin(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((n >> i) & 1 == 1)
//		{
//		count++;
//		}
//	}
//	return count;
//}
//3.n=n&(n-1)����һ��n�Ķ����Ʋ����е�һ��һλ
//int bin(int a)
//{
//	int count = 0;
//	while (a)
//	{
//		a = a & (a - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret=bin(a);
//	printf("count=%d", ret);
//	return 0;
//}





//#include<stdlib.h>
//system("pause")------���ڽ�β����ͣ��־




//��ӡ��M��N�����Ʋ�ͬλ���ܸ���
//int print(int n, int m)
//{
//	int count = 0;
//	int ret = n ^ m;//100011110011010110
//                  //���
//                  //100100011101101111
//                  //000111101110111001
//	while (ret)
//	{
//		ret = ret & (ret-1 );
//		count++;
//	}
//	return count;
//	
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	int count=print(n, m);
//	printf("%d", count);
//	return 0;
//}





////��ӡ������λ������λ��ż��λ
//// ��һ�ñ���
////100110101001101010011010100110101001101010011010
//// ��1
////000000000000000000000000000000000000000000000001
//void print(int a)
//{
//	int i = 0;
//	//��ӡ����:
//	for (i = 30; i >=0; i -= 2)
//	{
//		printf(" %d", ((a >> i) & 1));
//	}
//	printf("\n");
//	//��ӡż��:
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", ((a >> i) & 1));
//	}
//	printf("\n");
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	print(a);
//	return 0;
//}





//����9��99�˷�������12��12*12�˷���
//void table(int a)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= a; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%2d*%-2d=%-3d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	table(a);
//	return 0;
//}




//����������--reverse_string()
// 1.�����м�������еߵ�����
//void reverse_string(char* p,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		char temp = p[left];
//		p[left] = p[right];
//		p[right] = temp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "abcdefgh";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i <= sz - 1; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	printf("\n");
//	reverse_string(arr,sz);
//	for (i = 0; i <= sz - 1; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	return 0;
//}




//2.�õݹ���еߵ�
//int my_strlen(char* arr)
//{
//	int i = 0;
//	while (arr[i] != 0)
//	{
//		i++;
//	}
//	return i;
//}
//void reverse_string(char* arr)
//{
//	int len=my_strlen(arr);
//	char tmp = arr[0];
//	arr[0] = arr[len - 1];
//	arr[len - 1] = '\0';
//	if (my_strlen(arr+1)>= 2)
//	{
//		reverse_string(arr + 1);
//	}
//	arr[len - 1] = tmp;
//}
//int main()
//{
//	int i = 0;
//	char arr[] = "abcdefg";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i <= sz - 1; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//		printf("\n");
//	reverse_string(arr);
//	for (i = 0; i <= sz - 1; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	//int str = my_strlen(arr);------����my_strlen
//	//printf("%d", str);
//	
//	return 0;
//}





//digit_sum:����һ���Ǹ������������������(ʮ����)ÿλ�����������ֺ�
//int digit_sum(unsigned int a)
//{
//	if (a > 9)
//	{
//		return digit_sum(a / 10) +(a % 10);
//	}
//	return a;
//}
////digit_sum(1729)
////digit_sum(172)+1729%10
////digit_sum(17)+172%10+1729%10
////digit_sum(1)+17%10+172%10+1729%10
//int main()
//{
//	unsigned int a = 0;
//	scanf("%d", &a);
//	int sum=digit_sum(a);
//	printf("%d", sum);
//}





//���n��k�η�-----�ݹ�
//double Pow(int n, int k)
//{
//	if (k > 0)
//	{
//		return n * Pow(n, k - 1);
//	}
//	else if (k == 0)
//	{
//		return 1.0;
//	}
//	else
//		return(1.0 /  Pow(n, -k));
//}
////n*n(k-1)
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	double pow = Pow(n, k);
//	printf("%lf", pow);
//}