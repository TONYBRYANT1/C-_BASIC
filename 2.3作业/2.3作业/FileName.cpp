#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//1.
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = a;
//	*(p+2) += 2;//p[2]=p[2]+2  改变了a[2]的值
//	int i = 0;
//	for (i = 0; i < 9; i++)
//	{
//		printf("%d", a[i]);
//	}
//	return 0;
//}


//2.逆序字符串
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
//	char a[256] = {0};//当初始化为{0};时，记得初始化字符数组的大小
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

//4.0-100000之间的自幂数:
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//1.判断位数:
//		int temp = i;
//		int n = 0;
//		while (temp)
//		{
//			temp /= 10;
//			n++;
//		}
//		//2.每一位的n次方之和:
//		temp = i;
//		int sum = 0;
//		while (temp)
//		{
//			sum +=(int)pow(temp % 10,n);
//			temp /= 10;
//		}
//		//3.判断sum和i是否相等:
//		if (i == sum)
//		{
//			printf("%d  ", i);
//		}
//	}
//	
//}


//尚未完成:
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
//	//上半部分:
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
//	//下半部分:
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
//*p.a(错)-----(*p).a(对)



//7.喝汽水问题:一瓶汽水一元，两个空瓶换一瓶汽水，总共可以喝多少瓶汽水？
//1.逻辑
//int main()
//{
//	买回来的汽水
//	int money = 0;
//	scanf("%d", &money);
//	int total = 0;
//	int empty = 0;
//	total = money;
//	empty = money;
//	那空瓶子换的汽水:
//	while (empty >= 2)
//	{
//		total += empty / 2;//换汽水
//		empty = empty / 2 + empty % 2;//喝换的汽水剩下空瓶总数
//	}
//	printf("%d", total);
//	return 0;
//}
//2.数学规律
//int main()
//{
//	//买回来的汽水
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




//8.用move函数把一个数组的奇数放在左边偶数放在右边:
//void move(int* arr, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		//从左找偶数:
//		while ((left <= right) && arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		//从右找奇数
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



//9.左旋:
#include<assert.h>
#include<string.h>
//1.暴力求解法:
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
//2.三部反转法:
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


//9.2.0:判断一个字符数组是否由另一个字符数组旋转而成
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


//测试strstr的返回值是母串与子串想用字符的第一个字符的地址(母串中的地址)
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "bc";
//	printf("%p\n", arr1);
//	printf("%p\n", arr2);
//	printf("%p",strstr(arr1, arr2));
//}


//9.2.1:判断一个字符数组是否由另一个字符数组旋转而成
//precondition(前提):
//strcat只能连接两个不同的字符串
//strncar可以连接相同或不同的字符串
//母串:
//strncat(arr1,arr1,len)
//abcdefabcdef\0
//子串:
//bcdefa\0
// 
// 
// 
//int is_move(char* arr1, char* arr2)
//{
//	//判断两个字符串长度是否相等:
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	//断言:
//	assert(arr1);
//	assert(arr2);
//	//母串形成:
//	
//	strncat(arr1, arr1, len1);
//	//子串适配母串:
//	if (strstr(arr1, arr2) == NULL)//return 字符e的地址
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




//9.3:在杨氏矩阵中找数字
//杨氏矩阵:
//      如:1 2 3   每行从左到右依次增加 
//         4 5 6   每列从上到下依次增加
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
//		printf("找到了!");
//	}
//	else
//	{
//		printf("未找到!");
//	}
//}

//version 2:返回型参数
//如果想打印k所在的坐标1.在函数中直接打印(函数不简洁，比较low) 2.返回x,y的值(但已经有了返回值1，不好添加)
//设置返回型参数:把row和col设置为传值操作(1.带入矩阵的行和列于函数)(2.返回坐标x,y和判断标准1or无)
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
//	int ret = Find(arr, k, &x, &y);//设置返回型参数----“一箭双雕”
//	if (ret == 1)
//	{
//		printf("找到了!\n");
//		printf("地址为(%d,%d)", x, y);
//	}
//	else
//	{
//		printf("未找到!");
//	}
//}
