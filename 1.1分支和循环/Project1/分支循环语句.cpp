#define _CRT_SECURE_NO_WARNINGS 
////结构体和strcpy用法
// 1.
	//#include<stdio.h>
	//#include<string.h> 
	//
	//struct book
	//{
	//	int price;
	//	char name[20];
	//};
	//int main()
	//{
	//	struct book b1 = {50,"程序设计"};
	//	strcpy(b1.name, "程序设计++");
	//	printf("%s\n", b1.name);
	//}
//2.
//#include<stdio.h>
//#include<string.h>
//struct book 
//{
//	int price;
//	char name[20];
//};
//int main()
//{
//	struct book b1 = {
//		20,"程序设计"
//	};
//	struct book* p = &b1;
//	strcpy((*p).name, "程序");
//	printf("%s", p->name);
//	printf("%d", b1.price);
//}









//typedef
//#include<stdio.h>
//int main()
//{
//	extern int a;
//	typedef int i;
//	i x = 60;
//	printf("%d", x);
//	printf("%d", a);
//	return 0;
//}



//阶乘
//#include<stdio.h>
//int main()
//{
//	int rat = 1;
//	int i = 0;
//	for (i = 1; i < 4; i++)
//	{
//		
//		rat *= i;
//	}
//	printf("%d", rat);
//	return 0;
//}





// 阶乘相加
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i < 5; i++)
//	{
//		ret = ret * i;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}//1+2+6+24=33





//二分查找法
//#include<stdio.h>
//int main()
//{
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("请你输入你想要查找的数字>:  ");
//	int k;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		int mid = (right + left) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了下标为<<%d>>", mid);
//			break;
//		}
//	}
//	if (left >= right)
//	{
//		printf("找不到!!!");
//	}
//	return 0;
//}



//strlen 与 sizeof 辨析
//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "YOU HAVE ALREADY BITED UP MORE THAN YOU CAN CHEW";
//	char arr2[] = "************************************************";
//	int left = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int	right = sz - 2;//sizeof读取'\0',也可以用strlen
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		left++;
//		right--;
//		Sleep(100);
//		system("cls");
//	}
//	printf("%s", arr1);
// return 0;
//}



//输入三次密码
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0;
//	int n = 3;
//	char password[20];
//	for (n=3,i = 0; i < 3; i++)
//	{
//		printf("请输入你的密码>:\n");
//		scanf("%s", password);
//		if (0 == strcmp(password, "123abc"))
//		{
//			printf("输入正确");
//			break;
//		}
//		else
//		{
//			n -= 1;
//		}
//			printf("你还有%d次机会\n", n);
//	}
//}


//输入密码
//#include<stdio.h>
//int main()
//{
//	int ret = 0;
//	int rat = 0;
//	char password[20] = { 0 };
//	printf("请输入密码>:");
//	scanf("%s", password);
//	while (ret = getchar() != '\n');
//	{
//		;
//	}
	/*printf("请确认(y/n)");
	rat = getchar();
	printf("输入成功");
	return 0;
}*/




//三个数顺序输出
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", & a, &b, &c);
//	if (a < b)
//	{
//		int temp = 0;
//		temp = b;
//		b = a;
//		a = temp;
//	}
//	if (a < c)
//	{
//		int temp;
//		temp = a;
//		a = c;
//		c = temp;
//	}
//	if (b < c)
//	{
//		int temp;
//		temp = b;
//		b = c;
//		c = temp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}





//三的倍数
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		if (0 == i % 3)
//		{
//			printf("%d\t", i);
//
//		}
//	}
//	return 0;
//}





//辗转相除求两数的最大公约数
//#include<stdio.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0; 
//	scanf("%d%d", &m, &n);
//	while(m%n)//while(r=m%n)简化
//	{
//		r = m % n;
//		n = r;
//		m = n;
//	}
//	printf("%d",n);
//	return 0;
//}




//闰年
//能整除4，且不能整除100 ||  能整除400
//plan A:
	/*#include<stdio.h>
	int main()
	{
		int i = 0;
		int count = 0;
		for (i = 1000;i <= 2050; i++)
		{
			if ((0 == i % 4) && (0 != i % 100))
			{
				printf("%d ",i);
				count++;
			}
			else if (0 == i % 400)
			{
				printf("%d ", i);
				count++;
			}
		}
		printf("\n共有%d个闰年", count);
		return 0;
	}*/
//plan B:
//#include<stdio.h>
//	int main()
//	{
//		int i = 0;
//		int count = 0;
//		for (i = 1000; i <= 2050; i++)
//		{
//			if ((0 == i % 4) && (0 != i % 100)||(0 == i % 400))
//			{
//				printf("%d ", i);
//				count++;
//			}
//		}
//		printf("\n共有%d个闰年", count);
//		return 0;
//	}




//素数 //文章:《素数求解的n种境界》
//plan A:试除法
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 2;
//		for (j = 2; j < i; j++)
//		{
//			if (0 == i % j)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n共有%d个素数", count);
//	return 0;
//}



//plan A plus:
//原理:素数不能是偶数--->改i的范围
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	int count = 0;
	//	for (i = 101; i <= 200; i+=2)
	//	{
	//		int j = 2;
	//		for (j = 2; j < i; j++)
	//		{
	//			if (0 == i % j)
	//			{
	//				break;
	//			}
	//		}
	//		if (j == i)
	//		{
	//			printf("%d ", i);
	//			count++;
	//		}
	//	}
	//	printf("\n共有%d个素数", count);
	//	return 0;
	//}


//plan A plus++:
//原理:根号i  ,i---->sqrt(i)减小范围
	/*#include<stdio.h>
	#include<math.h>
	int main()
	{
		int i = 0;
		int count = 0;
		for (i = 101; i <= 200; i += 2)
		{
			int j = 2;
			for (j = 2; j <=sqrt(i); j++)
			{
				if (0 == i % j)
				{
					break;
				}
			}
			if (j>sqrt(i))
			{
				printf("%d ", i);
				count++;
			}
		}
		printf("\n共有%d个素数", count);
		return 0;
	}*/





	// 1--100有多少9
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	int count = 0;
	//	for (i = 1; i < 101; i++)
	//	{
	//		if (9 == i % 10)
	//		{
	//			count++;
	//		}
	//		 if (9 == i / 10)    //else if(X)----->对于99要算两次
	//		{
	//			count++;
	//		}
	//	}
	//	printf("有%d个9", count);
	//	return 0;
	//}




	//求a=(1/1-1/2+1/3-1/4.....+1/99-1/100)
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 1;
	//	double sum = 0.0;
	//	int plus=1;
	//	for (i = 1; i <= 100; i++)
	//	{
	//		sum += plus * (1.0 / i);//因为sum是实数 so (1/i)--->(1.0/i)
	//		plus = (-plus);         //1/n=0（商0于1)<--------->1.0/n=0.xxxxx (double)
	//	}
	//	printf("%lf", sum);
	//	return 0;
	//}
	//






	//求10个数中的最大值
	//#include<stdio.h>
	//int main()
	//{
	//	int arr[] = { 1,2,3,4,5,6,9,8,10,12 };
	//	int i = 0;
	//	int sz = sizeof(arr)/(arr[0]);
	//	int max = arr[0];
	//	for (i = 1; i <= 9; i++)
	//	{
	//		if (arr[i] > max)
	//		{
	//			max = arr[i];
	//		}
	//	}
	//	printf("最大值为%d\n", max);
	//	return 0;
	//}






// 	九九乘法表:
//				1*1=1
//				2*1=2 2*2=4
//				i*1=i .................i*j=i*j
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)//打印每一行
//	{
//		for(j = 1; j <= i; j++)//打印每一列
//		{
//			printf("%d*%d=%-2d  ", i, j, i * j);//%2d---打印两位数(并且右对齐)
//			                                   //%-2d---打印两位数(并且左对齐）
//		}
//		printf("\n");//每列打印完就换行
//	}
//}








//猜数字游戏
//#include<stdio.h>
//#include<stdlib.h>//for srand、rand function
//#include<time.h>//for time function
////
//void game(void)      
//{
//	int ret = 0;
//	//1.生成随机数rand()-----在MSDN上查找   rand的范围---range 0 to RAND_MAX(32767)
//	//用rand函数要先调用srand函数，而srand要time函数生成随机数
//	// void srand( unsigned int seed ); srand需要的输入类型为无符号整形所以把time函数丢进去
//	//time_t time( time_t *timer );   time_t *timer用NULL空指针代替
//	//time函数要使用的类型----time_t = typedef __time64_t   而  __time32_t = typedef long
//	//time函数所用的类型名为long
//	//srand((unsigned)time(NULL));将srand函数放在dowhile函数中避免玩一次重新生成一次
//	ret =( rand())%100;//保证ret属于1到100
//	//printf("%d\n", ret);   
//	//2.猜数字
//	int counter = 0;//计数器放外面以免每回都变成0
//	while (1)
//	{
//		int guess = 0;
//	  //int counter = 0;计数器放外面以免每回都变成0
//		printf("请输入你猜的数字>: ");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("你猜小了！！！\n");
//			counter++;
//		}
//		else if (guess > ret)
//		{
//			printf("你猜大了！！！\n");
//			counter++;
//		}
//		else
//		{
//			printf("你猜对了，嘻嘻！！！答案就是%d\n", ret);
//			counter++;
//			printf("你一共猜了%d次\n", counter);
//			printf("还想再玩一次吗?\n");
//			break;
//		}
//	}
//}
//void menu(void)
//{
//	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//	printf("******1.play      0.exit******\n");
//	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//	printf("请你选择>: 1or0\n");
//}
//int main()
//{
//	srand((unsigned)time(NULL));
//	int input = 0;
//	//不要将这些东西放在do while之前:会导致死循环：
//	//menu();
//	//printf("你的选择>: ");
//	//scanf("%d", &input);
//	do(input)
//	{
//		menu();
//		printf("你的选择>: ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("玩游戏\n");
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误,再选一次\n");
//			break;
//	}; while (input)
//	return 0;
//}



//猜数字游戏
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu(void)
//{
//	printf("**********************************\n");
//	printf("*********1.play    0.exit*********\n");
//	printf("**********************************\n");
//}
//void game(void)
//{
//	int count = 0;
//	int ret = 0;
//	ret = rand() % 100;
//	int guess = 0;
//
//	while (1)
//	{
//		printf("请你输入你猜的数字>: ");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了!!\n");
//			count++;
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了!!\n");
//			count++;
//		}
//		else
//		{
//			printf("猜对了\n");
//			printf("答案就是%d\n", ret);
//			count++;
//			printf("你一共猜了%d次\n", count);
//			break;
//		}
//	}
//
//}
//int main()
//{
//	srand((unsigned)time(NULL));
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("你要玩游戏吗? \n");
//		printf("请你输入>: ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("不玩游戏\n");
//			break;
//		case 1:
//			printf("玩游戏\n");
//			game();
//			break;
//		default:
//			printf("输入错误,请你重新输入!!!");
//			break;
//		}
//	} while (input);
//	return 0;
//}





//goto语句
//#include<stdio.h>
//int main()
//{
//again:
//	printf("鸡");
//	goto again;
//}
//
//
//用goto语句写关机程序
//电脑cmd（command命令行）窗口shutdown -s -t(关机程序)   shutdown -a(接触关机程序)
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//	char input[20] = {0};
//again:
//	printf("注意！！！你的电脑将在6分钟内关机，输入:wsz即可取消QaQ，识时务者为俊杰哦!!!\n");
//	system("shutdown -s -t 360");
//	printf("输入吧>: ");
//	scanf("%s", input);//关键在于scanf自能将空格前的字符录入缓冲区所以设置的不能出现"well down"类似的情况
//	if (0 == strcmp(input,"wsz"))
//	{
//		printf("算你识货");
//		system("shutdown -a");
//	}
//	else
//	{
//		printf("你很不老实！！！");
//		goto again;
//	} 
//	return 0;
//}
//
//
