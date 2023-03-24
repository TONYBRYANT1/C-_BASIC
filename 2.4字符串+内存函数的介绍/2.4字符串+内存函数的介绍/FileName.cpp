#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<assert.h>
//0.求字符串长度:strlen()------size_t strlen( const char *string );
//0.0.0:paremeter是地址，strlen用过地址开始往后找'\0',不包含\0
//0.0.1:返回值为 size_t==unsigned int 
// 
// 
// 
//0.1:应用:
//int main()
//{
//	int i = strlen("abcdef");
//	printf("%d", i);
//	return 0;
//}
// 
//  
// 
//0.2:自定义实现strlen
//0.2.0:计数器方法
//int my_strlen(char* arr)
//{
//	assert(arr);
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int ret=my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}
//
//0.2.1:递归方法
// 
//0.2.2:指针-指针
// 
// 
// 
//0.3:坑
//strlen的返回值为 size_t==unsigned int 
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("haha");
//	}
//	else if (strlen("abcdef") - strlen("abc") < 0)
//	{
//		printf("hehe");
//	}
//	return 0;
//}





//1.长度不受限制(不太安全)的字符串函数:strcpy()--------char *strcpy( char *strDestination, const char *strSource );
//1.0.0:paremeters是目标字符串和来源字符串的地址
//1.0.1:return value:Each of these functions returns the destination string. No return value is reserved to indicate an error
//1.0.2:Destination:abcdefg\0    source:abc\0   after strcpy(Destination,source)   Destination:abc\0efg\0 
//1.0.3:原字符串要含\0 (Warning!!!)
//1.0.4:目标空间要足够大 (Warning!!!)-----小心越界访问
//1.0.5:目标空间必须可以修改 (Warning!!!)------ eg:char *Destination="abcdefg"(error)
// 
//
//
//1.1:应用:
//int main()
//{
//	char Destination[] = "abcdefg";
//	char Source[] = "abc";
//	printf("%s", strcpy(Destination, Source));
//	return 0;
//}
// 
// 
// 
//1.2:自定义实现strcpy
//char* my_strcpy(char* des, const char* sou)
//{
//  //断言:
//	assert(des!=NULL);
//	assert(sou!=NULL);
//  //保留返回值地址:&arr1
//	char *storage = des;
//	while (*sou != '\0')
//	{
//		*des = *sou;
//		*des++;
//	    *sou++;
//	}
//  //把sou指向的\0传入des指向的字符串:
//	*des = *sou;
//	return storage;
//}
////优化版:
////char* my_strcpy(char* des, const char* sou)
////{
//      //断言:
////	assert(des != NULL);
////	assert(sou != NULL);
//      //保留返回值地址:&arr1
////	char* storage = des;
////	while (*des++ = *sou++)
////	{
////		;
////	}
////	return storage;
////}
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "abc";
//	printf("%s\n", arr1);
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//
//}





//2.长度不受限制(不太安全)的字符串函数:strcat---------char *strcat( char *strDestination, const char *strSource );
//2.0.0:paremeters:1.目的字符串地址 2.追加字符串地址
//2.0.1:return value:Each of these functions returns the destination string (strDestination). No return value is reserved to indicate an error.
//2.0.2:把目的字符串的\0去掉,接上追加的字符串包括\0
//2.0.3:目的字符串和追加字符转都要有\0
//2.0.4:目的字符串的空间可以修改且足够大
//2.0.5:自己追加自己会崩溃 -----(\0被追没了)
// 
// 
// 
//2.1:应用
//int main()
//{
//	char arr1[30] = "Hello ";
//	char arr2[] = "Bit";
//	printf("%s", strcat(arr1, arr2));
//	return 0;
//}
// 
// 
// 
//2.2:自定义实现strcat
//char* my_strcat(char* des, char* sou)
//{
//	assert(des != NULL);//单个可改为:assert(des); or assert(sou);
//	assert(sou != NULL);//多个可改为:assert(des && sou);
//	char* storage = des;
//	while (*des != '\0')
//	{
//		des++;
//	}
//	//错误:des指向\0后一位
//	//while (*des++ != '\0')
//	//{
//	//	;
//	//}
//	while (*des++ = *sou++)
//	{
//		;
//	}
//	return storage;
//}
//int main()
//{
//	char arr1[30] = "Hello ";
//	char arr2[] = "Bit";
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcat(arr1, arr2));
//	return 0;
//}





//3.长度不受限制(不太安全)的字符串函数:strcmp------int strcmp( const char *string1, const char *string2 );
//3.0.0:parameters为两个字符串地址
//3.0.1:return value:在不同的编译器下若 arr1>arr2 或 arr1<arr2 返回值不一定相同(vs2022 or gcc or ...)
//                    The return value for each of these functions indicates the lexicographic relation of string1 to string2.
//                    Value Relationship of string1 to string2
//                    < 0 string1 less than string2
//                    = 0 string1 identical to string2
//                    > 0 string1 greater than string2
//3.0.2:从字符串开头字符开始比较看那个的ASCII值大，若相等则比较下一对
// 
// 
// 
//3.1:应用
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "bcdefg";
//	printf("%d", strcmp(arr1, arr2));
//	return 0;
//}
// 
// 
// 
//3.2:自定义实现strcmp
//int my_strcmp(const char* arr1, const char* arr2)
//{
//	assert(arr1 && arr2);
//	while (*arr1 == *arr2)
//	{
//		if (*arr1 == '\0')
//		{
//			return 0;
//		}
//		arr1++;
//		arr2++;
//	}
////	if (*arr1 > *arr2)//vs版返回值
////	{
////		return 1;
////	}
////	else
////	{
////		return -1;
////	}
//  return(*arr1-*arr2);//linux-gcc版的返回值-----更接近与定义
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "qcdefg";
//	printf("%d", my_strcmp(arr1, arr2));
//	return 0;
//}





//4.长度受限制(相对安全)的字符串函数:strncpy-----char *strncpy( char *strDest, const char *strSource, size_t count );
//4.0.0:conut限定了拷贝数量,可能不含/0
//4.0.1:当string2的字符个数小于count时会添加多余的\0去满足count和serSource的差值
// 
// 
// 
//4.1:应用:
//int main()
//{
//	char Destination[] = "abcdefg";
//	char Source[] = "abc";
//	printf("%s", strncpy(Destination, Source,5));
//	return 0;
//}
// 
// 
// 
//4.2:自定义实现strncpy

 



//5.长度受限制(相对安全)的字符串函数:strncat-----char *strncat( char *strDest, const char *strSource, size_t count );
//5.0.0:从Destination的\0处开始追加
//5.0.1:会自动加上\0
//5.0.2:Return Value:Each of these functions returns a pointer to the destination string.No return value is reserved to indicate an error.
//5.0.3:当count>strSource strncat会追加strSource的字符串包含\0,不会添加多余的\0去满足count和serSource的差值
//5.0.4:当count<strSoutce strncat会追加相应个数的字符然后加上\0
// 
// 
// 
//int main()
//{
//	char Destination[30] = "abcdefg";
//	char Source[] = "abc";
//	printf("%s", strncat(Destination, Source, 2));
//	return 0;
//}
//int main()
//{
//	char Destination[30] = "abcdefg\0xxxxxxxxxxxxxxxx";
//	char Source[] = "abc";
//	printf("%s", strncat(Destination, Source, 6));
//	return 0;
//}
