//#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���:
//1.
//ָ�롢���鷴�����������:
//����:                   int Add (int x,int y)
//����ָ��:               int (*p) (int ,int)
//����ָ������:           int (*p_arr[]) (int ,int )
//ָ����ָ�������ָ��: int (*(*p_p_arr)[]) (int ,int)   =   &(p_arr)
//һ��ָ��ȥ��ָ�����õ�ָ�������
//һ��ָ��ȥ��(*ָ����)�õ����ָ��ָ��Ķ���������
//һ������ȥ���������õ����������
//һ������ȥ��(����[])���õ���������Ա������


//2.
//���:1.arr[j]<==>*(arr+j):�����arr���Ϊ&arr[0]
//���:2.(*p)<==>arr<==>&arr[0];(*p)+j<==>&arr[j];*( (*p)+j )<==>*( &arr[j] );*( (*(p+i))+j )<==>*( &arr[i][j] )<==>arr[i][j]






//һ:
//int main()
//{
//	//char arr[] = "abcdef";
//	//char* p = arr;
//	//printf("%s\n", p);
//	//printf("%s\n",arr);
//	////printf("%c\n",p);//�в�ͨ
//	//printf("%c\n", p[0]);//����------>*(p+0)<==>p[0]
//	//                     //���������arr,��char*p���յ���˼���
//
//
//	//const char* m = "abc";//��const�����ַ�����
//	//printf("%s\n", m);
//	//printf("%c\n", *m);
//
//	return 0;
//}
//�ܽ�:����1.char*p------->arr------->"abcdef"  2.har*p------->"abc"
//     ������ֱ����p����ӡ����ĸ����ʹp=&arr[0],��ΪҪ������




//��:
//ָ������
//int main()
//{
//	int arr1[] = { 1,2,3,4 };
//	int arr2[] = { 5,6,7,8 };
//	int arr3[] = { 9,10,11,12 };
//	int* p[3] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%2d ", *(p[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}
	




//��:
//����ָ��
//һά����������ָ��̫���£�����ֱ����ָ��ָ������
//int main()
//{
//	int	arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*p)[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{                            // p<==>&arr
//		printf("%d ", *((*p)+i));//*p<==>arr<==>arr[0]
//	}
//	return 0;
//}
//ָ��ָ������
//int main()
//{
//	int	arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);//p[i]<==>*(p+i)
//	}
//	return 0;
//}





//��ά������ͨ��ӡ:
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void printf2(int(*p)[5], int x, int y)//p<==>&arr[5],��arr��һ�ŵ������ܵ�ַ
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", p[i][j]);//д��*((*(p+1))+j) or (*(p+1))[j] or p[i][j]����
//		}  
//               //���:1.arr[j]<==>*(arr+j):�����arr���Ϊ&arr[0]
//               //���:2.(*p)<==>arr<==>&arr[0];(*p)+j<==>&arr[j];*( (*p)+j )<==>*( &arr[j] );*( (*(p+i))+j )<==>*( &arr[i][j] )<==>arr[i][j]
// 
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr,3,5);
//	printf("\n");
//	printf2(arr, 3, 5);
//	return 0;
//}








//��:
//����ָ��
//       void(*   signal(int ,void(*)(int))     )(int);
//signal��һ������,����ֵ1:int ����ֵ2:һ������ָ�룬���������ָ��ָ��ĺ����ķ���ֵΪint
//signal�����ķ���ֵ��һ������ָ�룬��ָ��ĺ����ķ���ֵΪint

//��: (�ض��庯��ָ��)typedef      void(*)(int)        pfun_c---------------���������뵫��������д
//����:                 typedef    void(* pfun_c)(int)
//                      pfun_F  signal(int ,pfun_c)




//����ָ���*����ȥ��:
//ԭ��printf("%p",add)<==>printf("%p",&add),add<==>(*p)<==>&add<==>p
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 4;
//	int b = 2;
//	int (*p)(int x, int y) = Add;
//	printf("%d\n", (*p)(a, b));//()�Ľ���Ա�*��:   *p(a,b)   (X����)
//	printf("%d\n", (p)(a, b));//p(a, b)Ҳ����
//	return 0;
//}






//��:
//����ָ������:
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int (*p[4]) (int, int) = { Add,Minu,Mul,Dev };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n",(*p[i])(6, 3));//or:p[i](6,3)
//	}
//	return 0;
//}





//����:
//char * my_strcpy(char * dest,const char * sour)
//my_strcpy�ĺ���ָ��:char *(*pf)(char * dest,const char * sour)//��д:char *(*pf)(char * ,const char * )
//���my_strcpy���͵ĺ����ĺ���ָ��ĺ���ָ������;
//char *(*pf_Arr[4])(char * dest,const char * sour)��д:char *(*pf_Arr[4])(char * ,const char * )




//version 1.������:
//ȱ��:����Ƚ����ӣ�������������¹��ܺ���
//void menu()
//{
//	printf("#############################\n");
//	printf("###    1.plus    2.sub    ###\n");
//	printf("###    3.mul     4div     ###\n");
//	printf("###        0.exit         ###\n");
//	printf("#############################\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ���㷨!\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1:
//			{
//				printf("��������������������\n");
//				scanf("%d%d", &x, &y);
//				printf("%d\n", Add(x,y));
//				break;
//			}
//			case 2:
//			{
//				printf("��������������������\n");
//				scanf("%d%d", &x, &y);
//				printf("%d\n", Sub(x,y));
//				break;
//			}
//			case 3:
//			{
//				printf("��������������������\n");
//				scanf("%d%d", &x, &y);
//				printf("%d\n", Mul(x,y));
//				break;
//			}
//			case 4:
//			{
//				printf("��������������������\n");
//				scanf("%d%d", &x, &y);
//				printf("%d\n", Div(x,y));
//				break;
//			}
//			case 0:
//			{
//				printf("�˳�������\n");
//				break;
//			}
//			default:
//			{
//				printf("�����������������\n");
//				break;
//			}
//		}
//	} while (input);
//}








//version 2.������
//
//�ص�����:
//Calc()------�൱����תվ�������Ǻ���(Add)��ַ���������лص��������(Add)
// 
//����switch case��䣬�����ú���Calc(���ص�������Add��)����Ϻ���ָ�������case����д������ӵĲ���(�ظ�����)
//void menu()
//{
//	printf("#############################\n");
//	printf("###    1.plus    2.sub    ###\n");
//	printf("###    3.mul     4div     ###\n");
//	printf("###        0.exit         ###\n");
//	printf("#############################\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void Calc(int (*pf)(int, int))//��Ȼpf��������ַ��pf������������pf���ú���ʽ����ʡ�ԡ�* ��
//{
//	int x = 0;
//	int y = 0;
//	printf("��������������������\n");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", (*pf)(x,y));//��Ȼpf��������ַ��pf������������pf���ú���ʽ����ʡ�ԡ�* ��
//}
//
//int main()
//{
//	
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ���㷨!\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1:
//			{
//				Calc(Add);
//				//printf("��������������������\n");
//				//scanf("%d%d", &x, &y);
//				//printf("%d\n", Add(x,y));
//				break;
//			}
//			case 2:
//			{
//				Calc(Sub);
//				//printf("��������������������\n");
//				//scanf("%d%d", &x, &y);
//				//printf("%d\n", Sub(x,y));
//				break;
//			}
//			case 3:
//			{
//				Calc(Mul);
//				//printf("��������������������\n");
//		        //scanf("%d%d", &x, &y);
//				//printf("%d\n", Mul(x,y));
//				break;
//			}
//			case 4:
//			{
//				Calc(Div);
//				//printf("��������������������\n");
//				//scanf("%d%d", &x, &y);
//				//printf("%d\n", Div(x,y));
//				break;
//			}
//			case 0:
//			{
//				printf("�˳�������\n");
//				break;
//			}
//			default:
//			{
//				printf("�����������������\n");
//				break;
//			}
//		}
//	} while (input);
//}







//version 3.������:
//����ָ������:ת�Ʊ�
//�ŵ�:Ӧ�ú���ָ�����鵱ת�Ʊ�,�����࣬��������µĹ��ܺ���
//void menu()
//{
//	printf("#############################\n");
//	printf("###    1.Add    2.Sub     ###\n");
//	printf("###    3.Mul    4.Div     ###\n");
//	printf("###    5.Xor    0.Exit    ###\n");
//	printf("#############################\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int Xor(int x, int y)
//{
//	return x ^ y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int (*p[])(int, int) = { 0, Add,Sub,Mul,Div,Xor };
//	do 
//	{
//		menu();
//		printf("��ѡ���㷨:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("��������������:>");
//			scanf("%d%d", &x, &y);
//			int ret = (*p[input])(x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�������\n");
//		}
//		else
//		{
//			printf("�������");
//		}
//    } while (input);
//}








//ָ�롢���鷴�����������:
//����:                   int Add (int x,int y)
//����ָ��:               int (*p) (int ,int)
//����ָ������:           int (*p_arr[]) (int ,int )
//ָ����ָ�������ָ��: int (*(*p_p_arr)[]) (int ,int)   =   &(p_arr)
//һ��ָ��ȥ��ָ�����õ�ָ�������
//һ��ָ��ȥ��(*ָ����)�õ����ָ��ָ��Ķ���������
//һ������ȥ���������õ����������
//һ������ȥ��(����[])���õ���������Ա������








//��:
//�ص�����: ����������������ַ----->�ⲿ�����ú���ָ�����----->ͨ������ָ�������������(���Ǻ�����ʵ�ַ�ֱ�ӵ���)



//qsort�лص����������:
//1:����Աд���Լ�������Ԫ��Ԫ�رȽϺ���---comparison function��
//2:qsort���Բ�����ʽ������comparison function���͵ĺ���ָ�룬����qsort��������ͨ������ָ��������comparison function


//1.
//version 1.ð������:
//ȱ��:���ܵ�һ��ֻ��������������
//void bubble_sort(int *arr,int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)//ÿ��ð������
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//
//}




#include<stdlib.h>
//version 2.qsort����
//void* ���͵�ָ����Խ����������͵ĵ�ַ,����Ϊ��֪��void*���Է��ʼ����ֽ����Բ��ܳ���  void*p=&a;1.(*p) 2.(p++)
//qsort()---�⺯��----ͷ�ļ�#include<stdlib.h>
//void qsort(void* base,
//           size_t num,
//           size_t width, 
//           int(__cdecl* compare)(const void* elem1, const void* elem2)------>comparion function
//           );
// 
// ����:1.�������������Ԫ�ص�ַ
//      2.�����������Ԫ�ظ���
//      3.������������ÿ��Ԫ�صĴ�С---��λ:�ֽ�
//	    4.����ָ��--->�Ƚ�����������Ԫ�����õĺ�����ַ---ʹ�����Լ�ʵ��
//		 (����ָ������������Ǵ����������Ԫ�صĵ�ַ)
// 
// return value of the comparion function:
//    Return Value Description
//     < 0    elem1 less than elem2
//     	 0    elem1 equivalent to elem2
//     > 0    elem1 greater than elem2

//1.���αȽ�
//int cmp_int(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);//void*���͵�ָ�벻��ֱ�ӽ�����
//}
//void test1()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//2.�����ͱȽ�
//int cmp_float(const void* f1, const void* f2)
//{
//	return ( (int) (*(float*)f1 - *(float*)f2) );//void*���͵�ָ�벻��ֱ�ӽ�����
//}
//void test2()
//{
//	float arr[10] = { 10.0,9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_float);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f ", arr[i]);
//	}
//}


//3.1�ṹ���Ա�Ƚ�:����
//#include<string.h>
//struct Stu 
//{
//	char name[20];
//	int age;
//};
//int cmp_Stu_by_name(const void* s1, const void* s2)//����ĸ����:��С����
//{
//	return strcmp(((struct Stu*)s1)->name, ((struct Stu*)s2)->name);//------------->strcmp(#include<string.h>)��comparion function�ķ���ֵ������ͬ
//}
//void test3()
//{
//	struct Stu arr[3] = { {"Zhang san",18},{"Li si",19},{"Wang wu",20} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_Stu_by_name);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("name:%s   ", arr[i].name);
//		printf("age:%d", arr[i].age);
//		printf("\n");
//	}
//}

 

//3.2�ṹ���Ա�Ƚ�:����
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_Stu_by_age(const void* s1, const void* s2)//��������:��С����
//{
//	return (((struct Stu*)s1)->age-((struct Stu*)s2)->age);
//}
//void test4()
//{
//	struct Stu arr[3] = { {"Zhang san",18},{"Li si",19},{"Wang wu",20} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_Stu_by_age);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("name:%s   ", arr[i].name);
//		printf("age:%d", arr[i].age);
//		printf("\n");
//	}
//}
//int main()
//{
//	test1();//���αȽ�
//	test2();//�����ͱȽ�
//	test3();//�ṹ���Ա�Ƚ�:����
//	test4();//�ṹ���Ա�Ƚ�:����
//	return 0;
//}













//2:
//ʵ���Լ���qsort:
// 
// 
// 
//���:
//void qsort(void* base,
//           size_t num,
//           size_t width, 
//           int(__cdecl* compare)(const void* elem1, const void* elem2)------>comparion function
//           );

//
//void swap(char* buf1, char* buf2, int width)//��ָ����յ�ͬ�ڽ��յ�ַ
//{
//	int i = 0;
//	for (i = 0; i < width; i++)                      //��ַ1 <-----���width���ֽ�-----> ��ַ2 <-----���width���ֽ�-----> ��ַ3<-----���n*width���ֽ�------>��ַn
//	{                                     //ֵ:   0_0_0_00000                          0_0_0_00000                          00000000                           00000000
//		char temp = *buf1;          //            |_|_|________________________________| | |
//		*buf1 = *buf2;          //                  |_|__________________________________| |
//		*buf2 = temp;          //                     |____________________________________|   ÿһλһ�ν��н���
//		buf1++;
//		buf2++;
//	}
//}
//
////�Զ����comparion function
//int cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);//void*���͵�ָ�벻��ֱ�ӽ�����
//}
//
//
//void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* p1, const void* p2))
////width�ô�:��Ϊvoid*��֪��һ�ο��Է��ʼ����ֽڣ��������в��ܴ����������ֽڿ�ȴ�������
////ʵ��bubble_sort�ĳ���Ա��֪��bubble_sort�������ڱȽ�ʲô���͵�Ԫ�أ����Ժ���ָ��Ĳ�����void*
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)//����
//	{
//		for (j = 0; j < sz - 1 - i; j++)//ÿһ�˽�������Ԫ�صıȽ�
//		{
//			//��Ҫһ����������Ԫ�رȽϵĺ�������Ȼ��֪����ʲô��������
//			if (cmp((char*)base + width * j, (char*)base + width * (j + 1)) > 0)//1�� : ��һ��Ԫ��base���ڶ���Ԫ��(char*)base+wideth   (j==0)
//				                                                                //2�� : �ڶ���Ԫ��(char*)base+width��������Ԫ��(char*)base+width*2     (j==1)
//				                                                                //3�� : ������Ԫ��(char*)base+width*2�����ĸ�Ԫ��(char*)base+width*3    (j==2)
//			{
//				//����
//				swap((char*)base + width * j, (char*)base + width * (j + 1),width);//������ָ���ͬ�ڵ�ַ
//			}
//				                                                  
//		}
//	}
//}
//
//
//void test()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//ʹ��bubble�ĳ���Աһ��֪���Լ��������ʲô����
//	//Ӧ��֪����αȽ������е�Ԫ��
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	test();
//	return 0;
//}






//3.
//���Լ���bubble_sortʵ�ֽṹ�����������:
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//void swap(char* buf1, char* buf2, int width)//��ָ����յ�ͬ�ڽ��յ�ַ
//{
//	int i = 0;
//	for (i = 0; i < width; i++)                      //��ַ1 <-----���width���ֽ�-----> ��ַ2 <-----���width���ֽ�-----> ��ַ3<-----���n*width���ֽ�------>��ַn
//	{                                     //ֵ:   0_0_0_00000                          0_0_0_00000                          00000000                           00000000
//		char temp = *buf1;          //            |_|_|________________________________| | |
//		*buf1 = *buf2;          //                  |_|__________________________________| |
//		*buf2 = temp;          //                     |____________________________________|   ÿһλһ�ν��н���
//		buf1++;
//		buf2++;
//	}
//}
//
//int cmp(const void* s1, const void* s2)//��������:��С����
//{
//	return (((struct Stu*)s1)->age-((struct Stu*)s2)->age);
//}
//
//void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* p1, const void* p2))
////width�ô�:��Ϊvoid*��֪��һ�ο��Է��ʼ����ֽڣ��������в��ܴ����������ֽڿ�ȴ�������
////ʵ��bubble_sort�ĳ���Ա��֪��bubble_sort�������ڱȽ�ʲô���͵�Ԫ�أ����Ժ���ָ��Ĳ�����void*
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)//����
//	{
//		for (j = 0; j < sz - 1 - i; j++)//ÿһ�˽�������Ԫ�صıȽ�
//		{
//			//��Ҫһ����������Ԫ�رȽϵĺ�������Ȼ��֪����ʲô��������
//			if (cmp((char*)base + width * j, (char*)base + width * (j + 1)) > 0)//1�� : ��һ��Ԫ��base���ڶ���Ԫ��(char*)base+wideth   (j==0)
//				//2�� : �ڶ���Ԫ��(char*)base+width��������Ԫ��(char*)base+width*2     (j==1)
//				//3�� : ������Ԫ��(char*)base+width*2�����ĸ�Ԫ��(char*)base+width*3    (j==2)
//			{
//				//����
//				swap((char*)base + width * j, (char*)base + width * (j + 1), width);//������ָ���ͬ�ڵ�ַ
//			}
//
//		}
//	}
//}
//
//void test4()
//{
//	struct Stu arr[3] = { {"Zhang san",18},{"Li si",19},{"Wang wu",20} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("name:%s   ", arr[i].name);
//		printf("age:%d", arr[i].age);
//		printf("\n");
//	}
//}
//
//int main()
//{
//	test4();
//	return 0;
//}


