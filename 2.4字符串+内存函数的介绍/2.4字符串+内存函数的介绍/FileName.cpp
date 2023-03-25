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
// The return value for each of these functions indicates the lexicographic relation of string1 to string2.
//Value           Relationship of string1 to string
//< 0	        	string1 less than string2
//= 0				string1 identical to string2
//> 0				string1 greater than string2

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
//	printf("%s", strncat(Destination, Source, 4));
// 	return 0;
//}
// 
//证明不管追不追加\0，都会自动补\0:
//int main()
//{
//	char d1[30] = "abcdefgh";
//	char s1[] = "abc";
//	char d2[30] = "abcdefgh";
//	int ret=strcmp(strncat(d1, s1, 3), strncat(d1, s1, 4));
//	printf("%d", ret);
//	return 0;
//}





//6.长度受限制(相对安全)的字符串函数:strncmp-----int strncmp( const char *string1, const char *string2, size_t count );
//6.0.0:return value
//Return Value     Description 
//< 0                string1 substring less than string2 substring
//= 0                string1 substring identical to string2 substring
//> 0                string1 substring greater than string2 substring
// 
// 
// 
//6.1:应用
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdeg";
//	printf("%d", strncmp(p1, p2, 6));
//	return 0;
//}






//7.字符串查找:strstr-----char *strstr( const char *string, const char *strCharSet );
//7.0.0:Parameters:
//string
//Null - terminated string to search----------------NULL(空指针)
//strCharSet
//Null - terminated string to search for------------Null or null(\0)
//7.0.1:Return Value
//Each of these functions returns a pointer to the first occurrence of strCharSet in string, or NULL if strCharSet does not appear in string.If strCharSet points to a string of zero length, the function returns string.
//7.0.2:如果母串重复出现子串则返回母串中第一次和子串重合的首字符地址(母串的地址)
// 
// 
// 
//7.1:应用
//int main()
//{
//	 const char* p1 = "abcdef";
//	 const char* p2 = "abcd";
//	const char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("找不到!");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}
// 
// 
//if strCharSet does not appear in string.If strCharSet points to a string of zero length, the function returns string.
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "";
//	const char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("找不到!");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}
// 
// 
// 
//7.2自定义实现strstr
//attach:KMP算法
//char* my_strstr(const char * p1, const char * p2)
//{
//	assert(p1 && p2);
//	char * s1 = (char*)p1;
//	char * s2 = (char*)p2;
//	char * cur = (char*)p1;
//	if (*p2=='\0')
//	{
//		return (char * )p1;
//	}
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char * )p2;
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cur;
//		}
//		if (*s1 == '\0')//子串比母串长
//		{
//			return NULL;
//		}
//		cur++;
//	}
//	return NULL;
//}
//int main()
//{
//	//const char * p1 = "abbbcdef";
//	//const char * p2 = "bbc";
//	const char* p1 = "abb";
//	const char* p2 = "abbc";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("找不到!");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}





//7.字符串查找:strtok-----char *strtok( char *strToken, const char *strDelimit );
//7.0.0:sep参数是个字符串，定义了用作分隔符的字符集合
//7.0.1:第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
//7.0.2:strtok函数找到str中的下一个标记，并将其用 \0 结尾，返回一个指向这个标记的指针。（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
//7.0.3:strtok函数的第一个参数不为 NULL ，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
//7.0.4:函数的第一个参数为 NULL ，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
//7.0.5:如果字符串中不存在更多的标记，则返回 NULL 指针。
// 
// 
// 
//7.1:应用
//int main()
//{
//	//const char* p1 = "3241382693@qq.com";
//	//const char* p2 = "@.";
//	//char arr[30] = { 0 };
//	//strcpy(arr, p1);
//	//char* ret = NULL;
//
//	const char* p1 = "198.161.131.162";//点分十进制的表示方式
//	const char* p2 = ".";
//	char arr[30] = { 0 };
//	strcpy(arr, p1);
//	char* ret = NULL;
//
//	//冗余应用:
//	//ret=strtok(arr, p2);
//	//printf("%s\n", ret);
//	//ret = strtok(NULL, p2);
//	//printf("%s\n", ret);
//	//ret = strtok(NULL, p2);
//	//printf("%s\n", ret);
//	//ret = strtok(NULL, p2);
//	//printf("%s\n", ret);
//
//	//便捷运用:
//	for (ret = strtok(arr, p2);ret!=NULL;ret=strtok(NULL,p2))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}





//7.字符串查找:strerror-----char *strerror( int errnum );把错误码转换为错误信息然后返回错误信息的地址(首元素)
//7.0.0:parameter-----errnumError number strErrMsg User - supplied message
//7.0.1:return value-----strerror and _strerror return a pointer to the error-message string. Subsequent calls to strerror or _strerror can overwrite the string.
// 
// 
// 
//7.1:应用
//错误码      错误信息
//0 -         No error
//1 -         Operation not permitted
//2 -		  No such file or directory
//errno 是一个全局的错误码的变量
//当C语言的库函数在执行过程中,如果发生错误,就会把对应的错误码赋值到errno中
#include<errno.h>
//int main()
//{
//  //char* ret = strerror(2);把错误码转换为错误信息然后返回错误信息的地址(首元素)
//	char* ret = strerror(errno);//引头文件#include<errno.h>
//	printf("%p", ret);
//	printf("%s", ret);
//	return 0;
//}
// 
// 
//实际应用:
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");//打开文件(test.txt),读文件(r)-----FILE *fopen( const char *filename, const char *mode );
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));//No such file or directory--------打不开文件的原因
//	}
//	else
//	{
//		printf("open file successfully");//open file successfully--------成功打开文件
//	}
//	return 0;
//}





//插曲:
#include<ctype.h>
//1.字符分类函数:eg:isdigit
//int isdigit( int c );
//isdigit returns a non-zero value if c is a decimal digit (0 – 9). iswdigit returns a non-zero value if c is a wide character corresponding to a decimal-digit character. Each of these routines returns 0 if c does not satisfy the test condition.
//eg:

//int main()
//{
//	char a = '3';
//	int ret = isdigit(a);//头文件#include<ctype.h>  //字符分类函数
//	printf("%d", ret);
//	return 0;
//}
// 
//2.字符转换函数:tolower toupper
int main()
{
	//char ch = toupper('w');//头文件#include<ctype.h>
	//printf("%c\n", ch);
	//char sh = tolower('W');//头文件#include<ctype.h>
	//printf("%c\n", sh);
	char arr[] = "I Have Come Here TO Chew Bubblegum And Kick Ass , And I`m All Out Of Bubblegum";
	int i = 0;
	while (arr[i])
	{
		if (isupper(arr[i]))
		{
			arr[i] = tolower(arr[i]);
		}
		i++;
	}
	printf("%s", arr);
	return 0;
}

