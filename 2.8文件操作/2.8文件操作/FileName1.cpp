#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>

//int main()
//{
//
//	printf("haha");//��׼�����(��Ļ)   �ڴ�--->��Ļ
//
//
//
//	int a = 0;
//	scanf("%d", &a);//��׼������(����)  ����--->�ڴ�
//
//
//
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		fputc('a',pf);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//fputc---Writes a character to a stream (fputc, fputwc) or to stdout (_fputchar, _fputwchar).
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		fputc('b', pf);
//		fputc('i', pf);
//		fputc('t', pf);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}