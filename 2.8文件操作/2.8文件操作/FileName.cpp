#define _CRT_SECURE_NO_WARNINGS
//文件输入输出流的理解:
//始终站在内存的角度考虑:
//写数据到文件中时:不是直接写进文件，而是通过编译器将数据写入内存，再从内存中的数据输入到文件中，则为输出流
//读数据到内存中时:是以文件为基础，在内存中的文件信息区中开设空间，储存文件的名字，状态，位置，则为输入流
//           寄存器
//			高速缓存
//			  内存
//			  硬盘
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
//int main()
//{

	//printf("haha");//标准输出流(屏幕)   内存--->屏幕



	//int a = 0;
	//scanf("%d", &a);//标准输入流(键盘)  键盘--->内存


	//字符输出函数:内存--->文件(以内存为中心输出)
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


	//字符输出函数:文件--->内存(以内存为中心输入)
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


	//文本行输出函数:(以内存为中心输出)
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
	//	//写入"hahahehe"
	//}
	//fclose(pf);
	//pf = NULL;
	//return 0;


	//文本行输入函数:(以内存为中心输入)文件--->内存
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


	//格式化输出函数:(以内存为中心输出)
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


	//格式化输入函数:(以内存为中心输入)
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

	
	//sscanf(字符串--->格式化数据)
	//以格式化数据的角度----输入流
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

	//sprintf(格式化数据--->字符串)
	//以格式化数据的角度---输出流
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



//二进制形式输出(也许肉眼读不懂):
//int main()
//{
//	struct S
//	{
//		char name[20];
//		int age;
//	};
//	struct S s = { "zhangsanfeng",999 };
//	FILE* pf = fopen("test.txt", "wb");//wb---为了输出数据(内存--->文件)，打开一个二进制文件
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		//以二进制形式写文件(也许肉眼读不懂):
//		fwrite(&s, sizeof(struct S), 1, pf);//将一个结构体(内存中)写入(输出到)文件中(以二进制形式)
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//二进制形式输入(也许肉眼读不懂):
//int main()
//{
//	struct S
//	{
//		char name[20];
//		int age;
//	};
//	struct S temp = {0};
//	FILE* pf = fopen("test.txt", "rb");//rb---为了输入数据(文件--->内存)，打开一个二进制文件
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		//以二进制形式写文件(也许肉眼读不懂):
//		fread(&temp, sizeof(struct S), 1, pf);//将文件数据输入到结构体变量中(内存)(以二进制形式)
//		printf("%s %d", temp.name, temp.age);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}






//文件的随机读取:
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
//offset(偏移量)
//
//Number of bytes from origin
//
//origin
//
//Initial position-------------------SEEK_CUR

                                     /*Current position of file pointer(eg:abcdef,则指向a,向后偏移1得到b)

									 SEEK_END

								     End of file(eg:abcdef,则指向f后面,向前偏移1才得到f)

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
//		//文件:abcdefg
//		//fseek:定位文件指针:
//		fseek(pf, 2, SEEK_CUR);
//		//打印字符:
//		int ch=fgetc(pf);
//		printf("%c\n", ch);
//		//ftell:文件指针指向的位置相对于起始位置的偏移量
//		int pos = ftell(pf);
//		printf("%d\n", pos);
//		//rewind:初始化指针位置--->使指针指向第一个位置
//		rewind(pf);
//		ch = fgetc(pf);
//		printf("%c", ch);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}




//直观打印错误:
//1.strerror(errno)
//2.perror

//int main()
//{
//	FILE* pf = fopen("test2.txt", "r");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));//----strerror(返回错误警示语句的地址)
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
//文件结束判定:
//1.文本文件读取是否结束:
//判断返回值:
//EOF---fgetc
//NULL---fgets
//2.二进制文件读取是否结束:
//fread的返回值是否小于实际要读的个数
//feof:
//0.不能直接用feof的返回值判断文件是否结束,而是应用于当文件结束时,判断文件结束原因(文件读取失败 or 文件尾部EOF而结束)
//1.EOF --- -1
//若文件没有内容，当读取文件数据时，就会读取-1
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

























