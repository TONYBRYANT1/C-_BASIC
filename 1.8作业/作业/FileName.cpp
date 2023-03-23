#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//   作业1:
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
//	if (i > sizeof(i))//sizeof返回一个无符号数（unsigned int），当有符号数和无符号数比较时，有符号数转成无符号数再去比较
//		              //而-1转化成无符号数
//		              //10000000000000000000000000000001
//		              //11111111111111111111111111111110
//		              //11111111111111111111111111111111-------把前面的符号位看成数字位-1就变成了一个很大的数，就大于4
//	{
//		printf("<\n");
//	}
//	else
//	{
//		printf(">");
//	}
//	return 0;
//}



//  作业二:
//一个数的补码有几个1
//#include<stdio.h>
//1.
//思路一:用%2 /2的思想
//int bin(unsigned int a)//如果遇到负数，将负数转成无符号数，再来运算
//{
//	int count = 0;
//	int i = 0;
//	while (a)//还可以写成(a!=0)
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
//思路二:通过按位与依次得到最后一个数，然后判断这个数是否为1
//100000000000000000000000000000001
//111111111111111111111111111111110
//111111111111111111111111111111111
//按位与1
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
//3.n=n&(n-1)运行一次n的二进制补码中的一少一位
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
//system("pause")------放在结尾的暂停标志




//打印出M与N二进制不同位的总个数
//int print(int n, int m)
//{
//	int count = 0;
//	int ret = n ^ m;//100011110011010110
//                  //异或
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





////打印二进制位的奇数位和偶数位
//// 与一得本身
////100110101001101010011010100110101001101010011010
//// 与1
////000000000000000000000000000000000000000000000001
//void print(int a)
//{
//	int i = 0;
//	//打印奇数:
//	for (i = 30; i >=0; i -= 2)
//	{
//		printf(" %d", ((a >> i) & 1));
//	}
//	printf("\n");
//	//打印偶数:
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





//输入9得99乘法表，输入12的12*12乘法表
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




//将数组逆置--reverse_string()
// 1.创建中间变量进行颠倒操作
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




//2.用递归进行颠倒
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
//	//int str = my_strlen(arr);------测试my_strlen
//	//printf("%d", str);
//	
//	return 0;
//}





//digit_sum:输入一个非负数，输出组成这个数的(十进制)每位加起来的数字合
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





//输出n的k次方-----递归
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