#define _CRT_SECURE_NO_WARNINGS
//文件输入输出流的理解:
//始终站在内存的角度考虑:
//写数据到文件中时:不是直接写进文件，而是通过编译器将数据写入内存，再从内存中的数据输入到文件中，则为输出流
//读数据到内存中时:是在内存中的文件信息区中开设空间，储存文件的名字，状态，位置，则为输入流
//
//从键盘输入
//输出到屏幕
//键盘&屏幕---外部设备
//
//键盘-标准输入设备-stdin
//屏幕-标准输出设备-stdout
//是一个程序默认打开的两个流设备
// 流:      类型:
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
//mode:文件的打开模式
//Parameters:filename---Filename,mode---Type of access permitted(进入许可的类型)
//Return Value:Each of these functions returns a pointer to the open file.A null pointer value indicates an error.
// 
//fputc:
//int fputc(int c, FILE* stream);//character 的类型是int(ASCII)
//Return Value:
//Each of these functions returns the character written.
//For fputc and _fputchar,a return value of EOF indicates an error.
//For fputwc and _fputwchar, a return value of WEOF indicates an error.
//
//NULL is a null pointer constant. NUL is a null character.
// 
// 
//1.打开文件:
//int main()
//{
//	FILE* pf = fopen("D:\\桌面\\test.txt", "r");//No such file or directory(文件夹)      //文件的相对路径:"test.txt"     文件的绝对路径:"D:\桌面\test.txt"
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


//写文件2.0:
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

//写文件2.1:
//fputs---Write a string to a stream(写文件要自己加\n)
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


//3.0读文件:
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

//3.1读文件:将文件的内容输入到内存中
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
//		//原文本文件数据:
//		//bit
//		//haha
//		fgets(buf, 1024, pf);
//		//printf("%s", buf);//buf自带\n---将文本文件中bit后的\n也取出来了
//		
//		//或者使用puts();---Write a string to stdout.//puts();---自带\n
//		puts(buf);
//		fgets(buf, 1024, pf);
//		//printf("%s", buf);//buf中无\n---haha后面没有\n
//		
//		//或者使用puts();---Write a string to stdout.//puts();---自带\n
//		puts(buf);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//fgetc & fputc
//从键盘标准输入，从屏幕标准输出
//
//int main()
//{
//	int ch = fgetc(stdin);//从标准输入流读取,并放入ch中
//	fputc(ch,stdout);//输出:写入标准输出流中
//	return 0;
//}
//



//整个过程以电脑内存为中心:  键盘(标准输入流)--->内存的buf数组--->屏幕(标准输出流)
//fgets & fputs
//从键盘标准输入，从屏幕标准输出
//int main()
//{
//	char buf[1024];
//	fgets(buf, 1024, stdin);//从标准输入流读取,并放入ch中
//	fputs(buf, stdout);//写入标准输出流中
//	return 0;
//}
//等价于:
//gets_s & puts --->默认从标准输入流读取，写入标准输出流中
//int main()
//{
//	char buf[1024];
//	gets_s(buf);
//	puts(buf);
//	return 0;
//}

//格式化输出函数:将内存中的数据写入文件 or 将内存中的数据写到屏幕中去
//printf---是将内存中的数据输出到标准输出流(屏幕中)
//fprintf---是将内存中的数据输出到文件中
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
//		//printf---默认的是输入到标准输出流中去(也就是屏幕中)
//		//fprinrf---可以改变输出位置，可以不再是标准输出流中，可以输出到文件中
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//scanf---是通过标准输入流(键盘)输入内存中
//fscanf---是把文件数据输入到内存的结构体中
//格式化输入函数:
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
//		//将文件中的数据输入到内存的结构体数组中
//		fscanf(pf, "%s %d", &(s.name), &(s.age));
//		//验证;
//		printf("%s %d", s.name, s.age);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//从标准输入流(键盘)输入到内存(内存中的结构体)------->从内存(内存中的结构体)输出到标准输出流(屏幕)
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
//sprintf---将某种格式化数据写入string中  
// 
//也可以认为是某种输出流 
// 
//Write formatted data(格式化的数据) to a string
// 
//sscanf---将string中格式化数据读到内存中
// 
//也可以认为是某种输入流
//  
//Read formatted data(格式化的数据) from a string.  
//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct S s = { "zhangsanfeng",999 };
//	char buf[30] = {0};
//	sprintf(buf, "%s %d", (s.name), (s.age));//以格式化数据的角度输出到string中
//    //检验:
//	//printf("%s", buf);
//	struct S temp = { 0 };
//	sscanf(buf, "%s %d",&(temp.name),&(temp.age));//[]scanf的最后一个parameter为目标地点
//	//可以以格式化数据的角度,将string中的数据输入到格式化数据中(以结构体的形式)
//	//检验:
//	printf("%s %d", temp.name, temp.age);
//	return 0;
//}



//总结:
//(站在内存角度,以内存为中心)scanf/printf---是针对标准输入流/标准输出流的 格式化输入/输出语句
//(站在内存角度,以内存为中心)fscanf/fprintf---是针对所有输入流/所有输出流的 格式化输入/输出语句
//(站在格式化数据角度,以格式化数据为中心)sscanf/sprintf---站在格式化数据角度将字符串读取到格式化的数据中(eg:结构体数据)/将格式化数据(eg:结构体数据)输出到字符串中