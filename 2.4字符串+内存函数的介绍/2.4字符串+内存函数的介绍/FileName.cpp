#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<assert.h>
//0.���ַ�������:strlen()------size_t strlen( const char *string );
//0.0.0:paremeter�ǵ�ַ��strlen�ù���ַ��ʼ������'\0',������\0
//0.0.1:����ֵΪ size_t==unsigned int 
// 
// 
// 
//0.1:Ӧ��:
//int main()
//{
//	int i = strlen("abcdef");
//	printf("%d", i);
//	return 0;
//}
// 
//  
// 
//0.2:�Զ���ʵ��strlen
//0.2.0:����������
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
//0.2.1:�ݹ鷽��
// 
//0.2.2:ָ��-ָ��
// 
// 
// 
//0.3:��
//strlen�ķ���ֵΪ size_t==unsigned int 
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





//1.���Ȳ�������(��̫��ȫ)���ַ�������:strcpy()--------char *strcpy( char *strDestination, const char *strSource );
//1.0.0:paremeters��Ŀ���ַ�������Դ�ַ����ĵ�ַ
//1.0.1:return value:Each of these functions returns the destination string. No return value is reserved to indicate an error
//1.0.2:Destination:abcdefg\0    source:abc\0   after strcpy(Destination,source)   Destination:abc\0efg\0 
//1.0.3:ԭ�ַ���Ҫ��\0 (Warning!!!)
//1.0.4:Ŀ��ռ�Ҫ�㹻�� (Warning!!!)-----С��Խ�����
//1.0.5:Ŀ��ռ��������޸� (Warning!!!)------ eg:char *Destination="abcdefg"(error)
// 
//
//
//1.1:Ӧ��:
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
//1.2:�Զ���ʵ��strcpy
//char* my_strcpy(char* des, const char* sou)
//{
//  //����:
//	assert(des!=NULL);
//	assert(sou!=NULL);
//  //��������ֵ��ַ:&arr1
//	char *storage = des;
//	while (*sou != '\0')
//	{
//		*des = *sou;
//		*des++;
//	    *sou++;
//	}
//  //��souָ���\0����desָ����ַ���:
//	*des = *sou;
//	return storage;
//}
////�Ż���:
////char* my_strcpy(char* des, const char* sou)
////{
//      //����:
////	assert(des != NULL);
////	assert(sou != NULL);
//      //��������ֵ��ַ:&arr1
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





//2.���Ȳ�������(��̫��ȫ)���ַ�������:strcat---------char *strcat( char *strDestination, const char *strSource );
//2.0.0:paremeters:1.Ŀ���ַ�����ַ 2.׷���ַ�����ַ
//2.0.1:return value:Each of these functions returns the destination string (strDestination). No return value is reserved to indicate an error.
//2.0.2:��Ŀ���ַ�����\0ȥ��,����׷�ӵ��ַ�������\0
//2.0.3:Ŀ���ַ�����׷���ַ�ת��Ҫ��\0
//2.0.4:Ŀ���ַ����Ŀռ�����޸����㹻��
//2.0.5:�Լ�׷���Լ������ -----(\0��׷û��)
// 
// 
// 
//2.1:Ӧ��
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
//2.2:�Զ���ʵ��strcat
//char* my_strcat(char* des, char* sou)
//{
//	assert(des != NULL);//�����ɸ�Ϊ:assert(des); or assert(sou);
//	assert(sou != NULL);//����ɸ�Ϊ:assert(des && sou);
//	char* storage = des;
//	while (*des != '\0')
//	{
//		des++;
//	}
//	//����:desָ��\0��һλ
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





//3.���Ȳ�������(��̫��ȫ)���ַ�������:strcmp------int strcmp( const char *string1, const char *string2 );
//3.0.0:parametersΪ�����ַ�����ַ
//3.0.1:return value:�ڲ�ͬ�ı��������� arr1>arr2 �� arr1<arr2 ����ֵ��һ����ͬ(vs2022 or gcc or ...)
// The return value for each of these functions indicates the lexicographic relation of string1 to string2.
//Value           Relationship of string1 to string
//< 0	        	string1 less than string2
//= 0				string1 identical to string2
//> 0				string1 greater than string2

//3.0.2:���ַ�����ͷ�ַ���ʼ�ȽϿ��Ǹ���ASCIIֵ���������Ƚ���һ��
// 
// 
// 
//3.1:Ӧ��
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
//3.2:�Զ���ʵ��strcmp
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
////	if (*arr1 > *arr2)//vs�淵��ֵ
////	{
////		return 1;
////	}
////	else
////	{
////		return -1;
////	}
//  return(*arr1-*arr2);//linux-gcc��ķ���ֵ-----���ӽ��붨��
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "qcdefg";
//	printf("%d", my_strcmp(arr1, arr2));
//	return 0;
//}





//4.����������(��԰�ȫ)���ַ�������:strncpy-----char *strncpy( char *strDest, const char *strSource, size_t count );
//4.0.0:conut�޶��˿�������,���ܲ���/0
//4.0.1:��string2���ַ�����С��countʱ����Ӷ����\0ȥ����count��serSource�Ĳ�ֵ
// 
// 
// 
//4.1:Ӧ��:
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
//4.2:�Զ���ʵ��strncpy

 



//5.����������(��԰�ȫ)���ַ�������:strncat-----char *strncat( char *strDest, const char *strSource, size_t count );
//5.0.0:��Destination��\0����ʼ׷��
//5.0.1:���Զ�����\0
//5.0.2:Return Value:Each of these functions returns a pointer to the destination string.No return value is reserved to indicate an error.
//5.0.3:��count>strSource strncat��׷��strSource���ַ�������\0,������Ӷ����\0ȥ����count��serSource�Ĳ�ֵ
//5.0.4:��count<strSoutce strncat��׷����Ӧ�������ַ�Ȼ�����\0
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
//֤������׷��׷��\0�������Զ���\0:
//int main()
//{
//	char d1[30] = "abcdefgh";
//	char s1[] = "abc";
//	char d2[30] = "abcdefgh";
//	int ret=strcmp(strncat(d1, s1, 3), strncat(d1, s1, 4));
//	printf("%d", ret);
//	return 0;
//}





//6.����������(��԰�ȫ)���ַ�������:strncmp-----int strncmp( const char *string1, const char *string2, size_t count );
//6.0.0:return value
//Return Value     Description 
//< 0                string1 substring less than string2 substring
//= 0                string1 substring identical to string2 substring
//> 0                string1 substring greater than string2 substring
// 
// 
// 
//6.1:Ӧ��
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdeg";
//	printf("%d", strncmp(p1, p2, 6));
//	return 0;
//}






//7.�ַ�������:strstr-----char *strstr( const char *string, const char *strCharSet );
//7.0.0:Parameters:
//string
//Null - terminated string to search----------------NULL(��ָ��)
//strCharSet
//Null - terminated string to search for------------Null or null(\0)
//7.0.1:Return Value
//Each of these functions returns a pointer to the first occurrence of strCharSet in string, or NULL if strCharSet does not appear in string.If strCharSet points to a string of zero length, the function returns string.
//7.0.2:���ĸ���ظ������Ӵ��򷵻�ĸ���е�һ�κ��Ӵ��غϵ����ַ���ַ(ĸ���ĵ�ַ)
// 
// 
// 
//7.1:Ӧ��
//int main()
//{
//	 const char* p1 = "abcdef";
//	 const char* p2 = "abcd";
//	const char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�Ҳ���!");
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
//		printf("�Ҳ���!");
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
//7.2�Զ���ʵ��strstr
//attach:KMP�㷨
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
//		if (*s1 == '\0')//�Ӵ���ĸ����
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
//		printf("�Ҳ���!");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}





//7.�ַ�������:strtok-----char *strtok( char *strToken, const char *strDelimit );
//7.0.0:sep�����Ǹ��ַ����������������ָ������ַ�����
//7.0.1:��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı�ǡ�
//7.0.2:strtok�����ҵ�str�е���һ����ǣ��������� \0 ��β������һ��ָ�������ǵ�ָ�롣��ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ġ���
//7.0.3:strtok�����ĵ�һ��������Ϊ NULL ���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�
//7.0.4:�����ĵ�һ������Ϊ NULL ����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
//7.0.5:����ַ����в����ڸ���ı�ǣ��򷵻� NULL ָ�롣
// 
// 
// 
//7.1:Ӧ��
//int main()
//{
//	//const char* p1 = "3241382693@qq.com";
//	//const char* p2 = "@.";
//	//char arr[30] = { 0 };
//	//strcpy(arr, p1);
//	//char* ret = NULL;
//
//	const char* p1 = "198.161.131.162";//���ʮ���Ƶı�ʾ��ʽ
//	const char* p2 = ".";
//	char arr[30] = { 0 };
//	strcpy(arr, p1);
//	char* ret = NULL;
//
//	//����Ӧ��:
//	//ret=strtok(arr, p2);
//	//printf("%s\n", ret);
//	//ret = strtok(NULL, p2);
//	//printf("%s\n", ret);
//	//ret = strtok(NULL, p2);
//	//printf("%s\n", ret);
//	//ret = strtok(NULL, p2);
//	//printf("%s\n", ret);
//
//	//�������:
//	for (ret = strtok(arr, p2);ret!=NULL;ret=strtok(NULL,p2))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}





//7.�ַ�������:strerror-----char *strerror( int errnum );�Ѵ�����ת��Ϊ������ϢȻ�󷵻ش�����Ϣ�ĵ�ַ(��Ԫ��)
//7.0.0:parameter-----errnumError number strErrMsg User - supplied message
//7.0.1:return value-----strerror and _strerror return a pointer to the error-message string. Subsequent calls to strerror or _strerror can overwrite the string.
// 
// 
// 
//7.1:Ӧ��
//������      ������Ϣ
//0 -         No error
//1 -         Operation not permitted
//2 -		  No such file or directory
//errno ��һ��ȫ�ֵĴ�����ı���
//��C���ԵĿ⺯����ִ�й�����,�����������,�ͻ�Ѷ�Ӧ�Ĵ����븳ֵ��errno��
#include<errno.h>
//int main()
//{
//  //char* ret = strerror(2);�Ѵ�����ת��Ϊ������ϢȻ�󷵻ش�����Ϣ�ĵ�ַ(��Ԫ��)
//	char* ret = strerror(errno);//��ͷ�ļ�#include<errno.h>
//	printf("%p", ret);
//	printf("%s", ret);
//	return 0;
//}
// 
// 
//ʵ��Ӧ��:
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");//���ļ�(test.txt),���ļ�(r)-----FILE *fopen( const char *filename, const char *mode );
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));//No such file or directory--------�򲻿��ļ���ԭ��
//	}
//	else
//	{
//		printf("open file successfully");//open file successfully--------�ɹ����ļ�
//	}
//	return 0;
//}





//����:
#include<ctype.h>
//1.�ַ����ຯ��:eg:isdigit
//int isdigit( int c );
//isdigit returns a non-zero value if c is a decimal digit (0 �C 9). iswdigit returns a non-zero value if c is a wide character corresponding to a decimal-digit character. Each of these routines returns 0 if c does not satisfy the test condition.
//eg:

//int main()
//{
//	char a = '3';
//	int ret = isdigit(a);//ͷ�ļ�#include<ctype.h>  //�ַ����ຯ��
//	printf("%d", ret);
//	return 0;
//}
// 
//2.�ַ�ת������:tolower toupper
int main()
{
	//char ch = toupper('w');//ͷ�ļ�#include<ctype.h>
	//printf("%c\n", ch);
	//char sh = tolower('W');//ͷ�ļ�#include<ctype.h>
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

