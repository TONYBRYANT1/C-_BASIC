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
//                    The return value for each of these functions indicates the lexicographic relation of string1 to string2.
//                    Value Relationship of string1 to string2
//                    < 0 string1 less than string2
//                    = 0 string1 identical to string2
//                    > 0 string1 greater than string2
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
//	printf("%s", strncat(Destination, Source, 6));
//	return 0;
//}
