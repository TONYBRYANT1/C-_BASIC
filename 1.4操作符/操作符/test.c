#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int a = -1;
//	int b = a >> 100;//均以反码为基准左有移
//	printf("%d", b);
//}
//负数>>1   (减一除以二)
//整数>>1   (除以二)




//不创建新变量交换两个数
//#include<stdio.h>
//int main()
//{
	//1.加减法:缺点:a,b的数值不能太大
	//int a = 3;
	//int b = 5;
	//scanf("%d%d", &a, &b);
	//printf("%d %d \n", a, b);
	//a = a + b;//(8)
	//b = a - b;//(3)
	//a = a - b;//(5)
	//printf("%d %d \n", a, b);
	//2.按位异或:好处是按位异或不会导致int溢出
	//           坏处是1.执行效率不如temp2.可读性差
	//int a = 3;//0011
	//int b = 5;//0101
	//scanf("%d%d", &a, &b);
	//printf("%d %d \n", a, b);
	//a = a ^ b;//(0110)------->密码
	//b = a ^ b;//密码^3=5
	//a = b ^ a;//密码^5=3
	//printf("%d %d \n", a, b);
//}




//求一个数以二进制存储的过程中会有几个一:   &
//#include<stdio.h>
//int main()
//{
	//1.缺点:负数不可取
	//int num = 0;
	//scanf("%d", &num);
	//int count = 0;
	//while (num != 0)//while(num)
	//{
	//	if ((num % 2) == 1)
	//		count++;
	//	num = num / 2;
	//}
	//printf("%d", count);
	//2.优化:
	/*int num = 1;
	scanf("%d", &num);
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 == ((num >> i) & 1))
			count++;
	}
	printf("%d", count);*/
//}







//3.单目操作符
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int  [10]是arr的类型
//	int ret=sizeof(int[10]);
//	printf("%d", ret);
//	pirntf("%d", sizeof(a));
//	pirntf("%d", sizeof a);
//	pirntf("%d", sizeof(int));
//	//pirntf("%d", sizeof int );(X)   表示sizeof不是函数，而是操作符
//}






//sizeof()括号内的式子不参与运算
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	short s = 0;
//	printf("%d\n", sizeof(s=a+5));
//	printf("%d\n", s);
//  return 0; 
//}





//按位取反  ' ~ '
#include<stdio.h>
int main()
{
	//int a = 0;
	////00000000000000000000000000000000
	////11111111111111111111111111111111----补码
	////11111111111111111111111111111110----反码
	////10000000000000000000000000000001----原码
	//printf("%d", (~a));



	int a = 11;
	a = a | (1 << 2);//------------|
	printf("%d", a);//-------------| --->反操作
    a = a & (~(1 << 2));//---------|
	printf("%d", a);
	return 0;
}