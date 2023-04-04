#define _CRT_SECURE_NO_WARNINGS
//�ļ���������������:
//ʼ��վ���ڴ�ĽǶȿ���:
//д���ݵ��ļ���ʱ:����ֱ��д���ļ�������ͨ��������������д���ڴ棬�ٴ��ڴ��е��������뵽�ļ��У���Ϊ�����
//�����ݵ��ڴ���ʱ:�����ļ�Ϊ���������ڴ��е��ļ���Ϣ���п���ռ䣬�����ļ������֣�״̬��λ�ã���Ϊ������
//           �Ĵ���
//			���ٻ���
//			  �ڴ�
//			  Ӳ��
//�Ӽ�������
//�������Ļ
//����&��Ļ---�ⲿ�豸
//
//����-��׼�����豸-stdin
//��Ļ-��׼����豸-stdout
//��һ������Ĭ�ϴ򿪵��������豸
// ��:      ����:
//stdin     FILE*
//stdout    FILE*
//stderr    FILE*
//
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<errno.h>
//fopen:
//FILE *fopen( const char *filename, const char *mode );
//mode:�ļ��Ĵ�ģʽ
//Parameters:filename---Filename,mode---Type of access permitted(������ɵ�����)
//Return Value:Each of these functions returns a pointer to the open file.A null pointer value indicates an error.
// 
//fputc:
//int fputc(int c, FILE* stream);//character ��������int(ASCII)
//Return Value:
//Each of these functions returns the character written.
//For fputc and _fputchar,a return value of EOF indicates an error.
//For fputwc and _fputwchar, a return value of WEOF indicates an error.
//
//NULL is a null pointer constant. NUL is a null character.
// 
// 
//1.���ļ�:
//int main()
//{
//	FILE* pf = fopen("D:\\����\\test.txt", "r");//No such file or directory(�ļ���)      //�ļ������·��:"test.txt"     �ļ��ľ���·��:"D:\����\test.txt"
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 1;
//	} 
//	else
//	{
//		
//	}
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//д�ļ�2.0:
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

//д�ļ�2.1:
//fputs---Write a string to a stream(д�ļ�Ҫ�Լ���\n)
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
//		fputs("hallo\n", pf);
//		fputs("world\n", pf);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//3.0���ļ�:
//fgetc---Read a character from a stream (fgetc, fgetwc) or stdin (_fgetchar, _fgetwchar).
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		printf("%c", fgetc(pf));
//		printf("%c", fgetc(pf));
//		printf("%c", fgetc(pf));
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//3.1���ļ�:���ļ����������뵽�ڴ���
//fgets---Get a string from a stream
//int main()
//{
//	char buf[1024];
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		//ԭ�ı��ļ�����:
//		//bit
//		//haha
//		fgets(buf, 1024, pf);
//		//printf("%s", buf);//buf�Դ�\n---���ı��ļ���bit���\nҲȡ������
//		
//		//����ʹ��puts();---Write a string to stdout.//puts();---�Դ�\n
//		puts(buf);
//		fgets(buf, 1024, pf);
//		//printf("%s", buf);//buf����\n---haha����û��\n
//		
//		//����ʹ��puts();---Write a string to stdout.//puts();---�Դ�\n
//		puts(buf);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//fgetc & fputc
//�Ӽ��̱�׼���룬����Ļ��׼���
//
//int main()
//{
//	int ch = fgetc(stdin);//�ӱ�׼��������ȡ,������ch��
//	fputc(ch,stdout);//���:д���׼�������
//	return 0;
//}
//



//���������Ե����ڴ�Ϊ����:  ����(��׼������)--->�ڴ��buf����--->��Ļ(��׼�����)
//fgets & fputs
//�Ӽ��̱�׼���룬����Ļ��׼���
//int main()
//{
//	char buf[1024];
//	fgets(buf, 1024, stdin);//�ӱ�׼��������ȡ,������ch��
//	fputs(buf, stdout);//д���׼�������
//	return 0;
//}
//�ȼ���:
//gets_s & puts --->Ĭ�ϴӱ�׼��������ȡ��д���׼�������
//int main()
//{
//	char buf[1024];
//	gets_s(buf);
//	puts(buf);
//	return 0;
//}

//��ʽ���������:���ڴ��е�����д���ļ� or ���ڴ��е�����д����Ļ��ȥ
//printf---�ǽ��ڴ��е������������׼�����(��Ļ��)
//fprintf---�ǽ��ڴ��е�����������ļ���
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct S s = { "zhangsanfeng",99 };
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		fprintf(pf, "%s %d", s.name, s.age);
//		//printf---Ĭ�ϵ������뵽��׼�������ȥ(Ҳ������Ļ��)
//		//fprinrf---���Ըı����λ�ã����Բ����Ǳ�׼������У�����������ļ���
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//scanf---��ͨ����׼������(����)�����ڴ���
//fscanf---�ǰ��ļ��������뵽�ڴ�Ľṹ����
//��ʽ�����뺯��:
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct S s = { 0 };
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		//���ļ��е��������뵽�ڴ�Ľṹ��������
//		fscanf(pf, "%s %d", &(s.name), &(s.age));
//		//��֤;
//		printf("%s %d", s.name, s.age);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//�ӱ�׼������(����)���뵽�ڴ�(�ڴ��еĽṹ��)------->���ڴ�(�ڴ��еĽṹ��)�������׼�����(��Ļ)
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct S s = { 0 };
//	fscanf(stdin, "%s %d", (s.name), &(s.age));//equivalent to scanf
//	fprintf(stdout, "%s %d", s.name, s.age);//equivalent to printf
//	return 0;
//}




//sscanf & sprintf
// 
//sprintf---��ĳ�ָ�ʽ������д��string��  
// 
//Ҳ������Ϊ��ĳ������� 
// 
//Write formatted data(��ʽ��������) to a string
// 
//sscanf---��string�и�ʽ�����ݶ����ڴ���
// 
//Ҳ������Ϊ��ĳ��������
//  
//Read formatted data(��ʽ��������) from a string.  
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct S s = { "zhangsanfeng",999 };
//	char buf[30] = {0};
//	sprintf(buf, "%s %d", (s.name), (s.age));//�Ը�ʽ�����ݵĽǶ������string��
//    //����:
//	//printf("%s", buf);
//	struct S temp = { 0 };
//	sscanf(buf, "%s %d",&(temp.name),&(temp.age));//[]scanf�����һ��parameterΪĿ��ص�
//	//�����Ը�ʽ�����ݵĽǶ�,��string�е��������뵽��ʽ��������(�Խṹ�����ʽ)
//	//����:
//	printf("%s %d", temp.name, temp.age);
//	return 0;
//}



//�ܽ�:
//(վ���ڴ�Ƕ�,���ڴ�Ϊ����)scanf/printf---����Ա�׼������/��׼������� ��ʽ������/������
//(վ���ڴ�Ƕ�,���ڴ�Ϊ����)fscanf/fprintf---���������������/����������� ��ʽ������/������
//(վ�ڸ�ʽ�����ݽǶ�,�Ը�ʽ������Ϊ����)sscanf/sprintf---վ�ڸ�ʽ�����ݽǶȽ��ַ�����ȡ����ʽ����������(eg:�ṹ������)/����ʽ������(eg:�ṹ������)������ַ�����
//int main()
//{

	//printf("haha");//��׼�����(��Ļ)   �ڴ�--->��Ļ



	//int a = 0;
	//scanf("%d", &a);//��׼������(����)  ����--->�ڴ�


	//�ַ��������:�ڴ�--->�ļ�(���ڴ�Ϊ�������)
	/*FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	else
	{
		fputc('a', pf);
	}
	fclose(pf);
	pf = NULL;
	return 0;*/


	//�ַ��������:�ļ�--->�ڴ�(���ڴ�Ϊ��������)
	/*FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	else
	{
		int t=fgetc(pf);
		printf("%c", t);
		 t = fgetc(pf);
		printf("%c", t);
		 t = fgetc(pf);
		printf("%c", t);
	}
	fclose(pf);
	pf = NULL;
	return 0;*/


	//�ı����������:(���ڴ�Ϊ�������)
	//char buf[1024] = "haha";
	//FILE* pf = fopen("test.txt", "w");
	//if (pf == NULL)
	//{
	//	printf("%s", strerror(errno));
	//	return 0;
	//}
	//else
	//{
	//	fputs(buf, pf);
	//	fputs("hehe", pf);
	//	//д��"hahahehe"
	//}
	//fclose(pf);
	//pf = NULL;
	//return 0;


	//�ı������뺯��:(���ڴ�Ϊ��������)�ļ�--->�ڴ�
	/*char buf[1024] = "";
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	else
	{
		fgets(buf, 1024, pf);
		printf("%s", buf);
	}
	fclose(pf);
	pf = NULL;
	return 0;*/


	//��ʽ���������:(���ڴ�Ϊ�������)
	/*struct S
	{
		char name[20];
		int age;
	};
	struct S s = {"zhangsanfeng",999};
	char buf[1024] = "";
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	else
	{
		fprintf(pf, "%s %d", s.name, s.age);
	}
	fclose(pf);
	pf = NULL;
	return 0;*/


	//��ʽ�����뺯��:(���ڴ�Ϊ��������)
	/*struct S
		{
			char name[20];
			int age;
		};
	struct S s = {0};
	char buf[1024] = "";
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	else
	{
		fscanf(pf, "%s %d", &(s.name), &(s.age));
		printf("%s %d", s.name, s.age);
	}
	fclose(pf);
	pf = NULL;
	return 0;*/

	
	//sscanf(�ַ���--->��ʽ������)
	//�Ը�ʽ�����ݵĽǶ�----������
	/*struct S
	{
		char name[20];
		int age;
	};
	char buf[20] = "zhangsanfeng  999";
	struct S s = { 0 };
	sscanf(buf, "%s %d", &(s.name), &(s.age));
	printf("%s %d", s.name, s.age);
	return 0;*/

	//sprintf(��ʽ������--->�ַ���)
	//�Ը�ʽ�����ݵĽǶ�---�����
	/*struct S
	{
		char name[20];
		int age;
	};
	struct S s = { "zhangsanfeng",999 };
	char bffadfdsfuf[20] = "";
	sprintf(buf, "%s %d", s.name, s.age);
	printf("%s", buf);
	return 0;*/
//}



//��������ʽ���(Ҳ�����۶�����):
//int main()
//{
//	struct S
//	{
//		char name[20];
//		int age;
//	};
//	struct S s = { "zhangsanfeng",999 };
//	FILE* pf = fopen("test.txt", "wb");//wb---Ϊ���������(�ڴ�--->�ļ�)����һ���������ļ�
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		//�Զ�������ʽд�ļ�(Ҳ�����۶�����):
//		fwrite(&s, sizeof(struct S), 1, pf);//��һ���ṹ��(�ڴ���)д��(�����)�ļ���(�Զ�������ʽ)
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//��������ʽ����(Ҳ�����۶�����):
//int main()
//{
//	struct S
//	{
//		char name[20];
//		int age;
//	};
//	struct S temp = {0};
//	FILE* pf = fopen("test.txt", "rb");//rb---Ϊ����������(�ļ�--->�ڴ�)����һ���������ļ�
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		//�Զ�������ʽд�ļ�(Ҳ�����۶�����):
//		fread(&temp, sizeof(struct S), 1, pf);//���ļ��������뵽�ṹ�������(�ڴ�)(�Զ�������ʽ)
//		printf("%s %d", temp.name, temp.age);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}






//�ļ��������ȡ:
//fseek:Moves the file pointer to a specified location.
//int fseek(FILE* stream, long offset, int origin);
//Return Value:
//If successful, fseek returns 0. Otherwise, it returns a nonzero value.On devices incapable of seeking, the return value is undefined.

//Parameters:
//
//stream
//
//Pointer to FILE structure
//
//offset(ƫ����)
//
//Number of bytes from origin
//
//origin
//
//Initial position-------------------SEEK_CUR

                                     /*Current position of file pointer(eg:abcdef,��ָ��a,���ƫ��1�õ�b)

									 SEEK_END

								     End of file(eg:abcdef,��ָ��f����,��ǰƫ��1�ŵõ�f)

									 SEEK_SET

									 Beginning of file*/


//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		//�ļ�:abcdefg
//		//fseek:��λ�ļ�ָ��:
//		fseek(pf, 2, SEEK_CUR);
//		//��ӡ�ַ�:
//		int ch=fgetc(pf);
//		printf("%c\n", ch);
//		//ftell:�ļ�ָ��ָ���λ���������ʼλ�õ�ƫ����
//		int pos = ftell(pf);
//		printf("%d\n", pos);
//		//rewind:��ʼ��ָ��λ��--->ʹָ��ָ���һ��λ��
//		rewind(pf);
//		ch = fgetc(pf);
//		printf("%c", ch);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}




//ֱ�۴�ӡ����:
//1.strerror(errno)
//2.perror

//int main()
//{
//	FILE* pf = fopen("test2.txt", "r");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));//----strerror(���ش���ʾ���ĵ�ַ)
//		perror("open test2.txt");
//		return 0;
//	}
//	else
//	{
//		;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
// 
// 
// 
//�ļ������ж�:
//1.�ı��ļ���ȡ�Ƿ����:
//�жϷ���ֵ:
//EOF---fgetc
//NULL---fgets
//2.�������ļ���ȡ�Ƿ����:
//fread�ķ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���
//feof:
//0.����ֱ����feof�ķ���ֵ�ж��ļ��Ƿ����,����Ӧ���ڵ��ļ�����ʱ,�ж��ļ�����ԭ��(�ļ���ȡʧ�� or �ļ�β��EOF������)
//1.EOF --- -1
//���ļ�û�����ݣ�����ȡ�ļ�����ʱ���ͻ��ȡ-1
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("test.txt");
//		return 0;
//	}
//	else
//	{
//		int ch = 0;
//		while ((ch = fgetc(pf)) != EOF)
//		{
//			//printf("%c\n", ch);
//			putchar(ch);
//			printf("\n");
//		}
//		if (ferror(pf))//If no error has occurred on stream, ferror returns 0. Otherwise, it returns a nonzero value.
//		{
//			printf("error\n");
//		}
//		else if (feof(pf))//The feof function returns a nonzero value after the first read operation that attempts to read past the end of the file.
//			              //It returns 0 if the current position is not end of file. There is no error return.
//		{
//			printf("end of file\n");
//		}
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

























