#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//Ԥ�������:
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	FILE* pf = fopen("log.txt", "w");
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		fprintf(pf, "file:%s line:%d data:%s time:%s i=%d\n",
//			__FILE__, __LINE__, __DATE__, __TIME__, i);
//		printf("%s\n", __FUNCTION__);//��ӡ��������
//	}
//	fclose(pf);
//	pf == NULL;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#define������ź��治Ҫ�ӷֺ�

//#define����ĺ�
//#define SQUARE(X) X*X   //SQUAREҪ��()��������
//int main()
//{
//	//int ret = SQUARE(5);
//	//printf("ret=%d", ret);
//
//	int ret = SQUARE(5+1);//������ȫ�滻�����Ǵ��ε�,(5+1)��������������ֱ�Ӵ���X�� �ó�5+1*5+1=11
//	printf("ret=%d", ret);
//	return 0;
//}

//#define SQUARE(X) (X)*(X)//�����Ͳ������---��Ҫ��ϧ()
//int main()
//{
//	int ret = SQUARE(5 + 1);//��X�������������Ͳ�����11 ����5+1����õ�36��
//	printf("ret=%d", ret);
//	return 0;
//}




//#define DOUBLE(X) X+X
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(a);
//	//int ret=10*a+a=55
//	printf("%d\n", ret);
//}
//
//#define DOUBLE(X) (X)+(X)
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(a);
//	//int ret=10*(a)+(a)=55
//	printf("%d\n", ret);
//}

//#define DOUBLE(X) ((X)+(X))
//int main()
//{
//	int a = 5;
//	int ret = 10 * DOUBLE(a);
//	//int ret=10*((a)+(a))=100
//	printf("%d\n", ret);
//}

//�겻���Եݹ�



//#
//�ַ����еĺ�ͨ�������滻:
//#define MAX 10
//int main()
//{
//	printf("MAX=%d", MAX);//MAX=10
//	return  0;
//}

//��ʲô�취����Ĳ������뵽�ַ����У�
//int main()
//{
//	printf("hallo world\n");
//	printf("hallo ""world\n");
//	printf("hal""lo ""world");
//	//���ߵȼ�
//}


//#define PRINT(X) printf("the value of "#X" is %d\n",X)//����#X���滻��"X" �ڱ��"a" or "b"��ǰ������һ��
//int main()
//{
//	int a = 0;
//	int b = 2;
//	PRINT(a);
//	PRINT(b);
//	return 0;
//}


//##
//����ֱ����:
//int main()
//{
//	int a8 = 8;
//	printf("%d", a##8);
//	return 0;
//}
//#define CAT(X,Y) X##Y
//int main()
//{
//	int a8 = 10;
//	printf("%d", CAT(a, 8));
//	//printf("%d",a##8); <==> printf("%d",a8); <==>10
//	return 0;
//}



//������:
//int main()
//{
//	int a = 0;
//	//int b = a + 1;
//	int b = a++;//����ʽ�Ӷ���b��������ͬ������ʽ��a�и�����
//	return 0;
//}


//���и����õĺ����:
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 10;
//	int b = 11;
//	printf("%d\n", MAX(a++, b++));//()�в����������ֱ���滻
//	// ((a++)>(b++)?(a++):(b++))
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}




//���뺯��:
//1.��������רһ:�����ͻ���float��,����Ҫ��дһ������
// ���겻�������ͣ�ֱ���滻
//2.�����ڵ��õ�ʱ����к������úͷ��صĿ���(�����鿴)
//3.�궨����Ԥ����׶ξ�������滻Ч�ʸ���:
//MAX(a,b)==>((a)>(b)?(a):(b))
//4.����ܻ��������ӳ���ĳ���
//5.���Ե�ʱ������Ѵ�test.c--->test.exe ,��ʱ�궨���Ѿ����滻��,�޷��Ժ궨����е���
//6.��Ĳ����������޹�--->�����Ͻ�
//7.��Ĳ�������и�����ʱ���ܻ����Ӱ��,����������(�����Ὣ���Ĳ�����������,����������滻)
//8.��ķ��ź�ʽ�ӵķ��ż������Ϊ���ȼ�����,���³�����ܳ���
//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int MaX(int x, int y)
//{
//	return(x > y ? x : y);
//}
//int main()
//{
//	int a = 10;
//	int b = 11;
//	printf("%d\n", MAX(a, b));//()�в����������ֱ���滻
//	printf("%d\n", MaX(a, b));
//	return 0;
//}

//���������������������(������)
//#define SIZEOF(type) sizeof(type)
//int main()
//{
//	int ret = SIZEOF(int);
//	printf("%d", ret);
//	return 0;
//}


//#include<stdlib.h>
//�궨���Ƶ�malloc��ʹ�ø��ӷ���
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);
//	//�滻:int* p = (int*)malloc(10*sizeof(int))
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		p[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	return 0;
//}


//inline---��������
//#undef---�����Ƴ�һ���궨��