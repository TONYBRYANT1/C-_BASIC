#define _CRT_SECURE_NO_WARNINGS 
////�ṹ���strcpy�÷�
// 1.
	//#include<stdio.h>
	//#include<string.h> 
	//
	//struct book
	//{
	//	int price;
	//	char name[20];
	//};
	//int main()
	//{
	//	struct book b1 = {50,"�������"};
	//	strcpy(b1.name, "�������++");
	//	printf("%s\n", b1.name);
	//}
//2.
//#include<stdio.h>
//#include<string.h>
//struct book 
//{
//	int price;
//	char name[20];
//};
//int main()
//{
//	struct book b1 = {
//		20,"�������"
//	};
//	struct book* p = &b1;
//	strcpy((*p).name, "����");
//	printf("%s", p->name);
//	printf("%d", b1.price);
//}









//typedef
//#include<stdio.h>
//int main()
//{
//	extern int a;
//	typedef int i;
//	i x = 60;
//	printf("%d", x);
//	printf("%d", a);
//	return 0;
//}



//�׳�
//#include<stdio.h>
//int main()
//{
//	int rat = 1;
//	int i = 0;
//	for (i = 1; i < 4; i++)
//	{
//		
//		rat *= i;
//	}
//	printf("%d", rat);
//	return 0;
//}





// �׳����
//#include<stdio.h>
//int main()
//{
//	int i = 1;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i < 5; i++)
//	{
//		ret = ret * i;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}//1+2+6+24=33





//���ֲ��ҷ�
//#include<stdio.h>
//int main()
//{
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("������������Ҫ���ҵ�����>:  ");
//	int k;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		int mid = (right + left) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ����±�Ϊ<<%d>>", mid);
//			break;
//		}
//	}
//	if (left >= right)
//	{
//		printf("�Ҳ���!!!");
//	}
//	return 0;
//}



//strlen �� sizeof ����
//#include<stdio.h>
//#include<windows.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "YOU HAVE ALREADY BITED UP MORE THAN YOU CAN CHEW";
//	char arr2[] = "************************************************";
//	int left = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int	right = sz - 2;//sizeof��ȡ'\0',Ҳ������strlen
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		left++;
//		right--;
//		Sleep(100);
//		system("cls");
//	}
//	printf("%s", arr1);
// return 0;
//}



//������������
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0;
//	int n = 3;
//	char password[20];
//	for (n=3,i = 0; i < 3; i++)
//	{
//		printf("�������������>:\n");
//		scanf("%s", password);
//		if (0 == strcmp(password, "123abc"))
//		{
//			printf("������ȷ");
//			break;
//		}
//		else
//		{
//			n -= 1;
//		}
//			printf("�㻹��%d�λ���\n", n);
//	}
//}


//��������
//#include<stdio.h>
//int main()
//{
//	int ret = 0;
//	int rat = 0;
//	char password[20] = { 0 };
//	printf("����������>:");
//	scanf("%s", password);
//	while (ret = getchar() != '\n');
//	{
//		;
//	}
	/*printf("��ȷ��(y/n)");
	rat = getchar();
	printf("����ɹ�");
	return 0;
}*/




//������˳�����
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", & a, &b, &c);
//	if (a < b)
//	{
//		int temp = 0;
//		temp = b;
//		b = a;
//		a = temp;
//	}
//	if (a < c)
//	{
//		int temp;
//		temp = a;
//		a = c;
//		c = temp;
//	}
//	if (b < c)
//	{
//		int temp;
//		temp = b;
//		b = c;
//		c = temp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}





//���ı���
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		if (0 == i % 3)
//		{
//			printf("%d\t", i);
//
//		}
//	}
//	return 0;
//}





//շת��������������Լ��
//#include<stdio.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int r = 0; 
//	scanf("%d%d", &m, &n);
//	while(m%n)//while(r=m%n)��
//	{
//		r = m % n;
//		n = r;
//		m = n;
//	}
//	printf("%d",n);
//	return 0;
//}




//����
//������4���Ҳ�������100 ||  ������400
//plan A:
	/*#include<stdio.h>
	int main()
	{
		int i = 0;
		int count = 0;
		for (i = 1000;i <= 2050; i++)
		{
			if ((0 == i % 4) && (0 != i % 100))
			{
				printf("%d ",i);
				count++;
			}
			else if (0 == i % 400)
			{
				printf("%d ", i);
				count++;
			}
		}
		printf("\n����%d������", count);
		return 0;
	}*/
//plan B:
//#include<stdio.h>
//	int main()
//	{
//		int i = 0;
//		int count = 0;
//		for (i = 1000; i <= 2050; i++)
//		{
//			if ((0 == i % 4) && (0 != i % 100)||(0 == i % 400))
//			{
//				printf("%d ", i);
//				count++;
//			}
//		}
//		printf("\n����%d������", count);
//		return 0;
//	}




//���� //����:����������n�־��硷
//plan A:�Գ���
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 2;
//		for (j = 2; j < i; j++)
//		{
//			if (0 == i % j)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n����%d������", count);
//	return 0;
//}



//plan A plus:
//ԭ��:����������ż��--->��i�ķ�Χ
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	int count = 0;
	//	for (i = 101; i <= 200; i+=2)
	//	{
	//		int j = 2;
	//		for (j = 2; j < i; j++)
	//		{
	//			if (0 == i % j)
	//			{
	//				break;
	//			}
	//		}
	//		if (j == i)
	//		{
	//			printf("%d ", i);
	//			count++;
	//		}
	//	}
	//	printf("\n����%d������", count);
	//	return 0;
	//}


//plan A plus++:
//ԭ��:����i  ,i---->sqrt(i)��С��Χ
	/*#include<stdio.h>
	#include<math.h>
	int main()
	{
		int i = 0;
		int count = 0;
		for (i = 101; i <= 200; i += 2)
		{
			int j = 2;
			for (j = 2; j <=sqrt(i); j++)
			{
				if (0 == i % j)
				{
					break;
				}
			}
			if (j>sqrt(i))
			{
				printf("%d ", i);
				count++;
			}
		}
		printf("\n����%d������", count);
		return 0;
	}*/





	// 1--100�ж���9
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 0;
	//	int count = 0;
	//	for (i = 1; i < 101; i++)
	//	{
	//		if (9 == i % 10)
	//		{
	//			count++;
	//		}
	//		 if (9 == i / 10)    //else if(X)----->����99Ҫ������
	//		{
	//			count++;
	//		}
	//	}
	//	printf("��%d��9", count);
	//	return 0;
	//}




	//��a=(1/1-1/2+1/3-1/4.....+1/99-1/100)
	//#include<stdio.h>
	//int main()
	//{
	//	int i = 1;
	//	double sum = 0.0;
	//	int plus=1;
	//	for (i = 1; i <= 100; i++)
	//	{
	//		sum += plus * (1.0 / i);//��Ϊsum��ʵ�� so (1/i)--->(1.0/i)
	//		plus = (-plus);         //1/n=0����0��1)<--------->1.0/n=0.xxxxx (double)
	//	}
	//	printf("%lf", sum);
	//	return 0;
	//}
	//






	//��10�����е����ֵ
	//#include<stdio.h>
	//int main()
	//{
	//	int arr[] = { 1,2,3,4,5,6,9,8,10,12 };
	//	int i = 0;
	//	int sz = sizeof(arr)/(arr[0]);
	//	int max = arr[0];
	//	for (i = 1; i <= 9; i++)
	//	{
	//		if (arr[i] > max)
	//		{
	//			max = arr[i];
	//		}
	//	}
	//	printf("���ֵΪ%d\n", max);
	//	return 0;
	//}






// 	�žų˷���:
//				1*1=1
//				2*1=2 2*2=4
//				i*1=i .................i*j=i*j
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)//��ӡÿһ��
//	{
//		for(j = 1; j <= i; j++)//��ӡÿһ��
//		{
//			printf("%d*%d=%-2d  ", i, j, i * j);//%2d---��ӡ��λ��(�����Ҷ���)
//			                                   //%-2d---��ӡ��λ��(��������룩
//		}
//		printf("\n");//ÿ�д�ӡ��ͻ���
//	}
//}








//��������Ϸ
//#include<stdio.h>
//#include<stdlib.h>//for srand��rand function
//#include<time.h>//for time function
////
//void game(void)      
//{
//	int ret = 0;
//	//1.���������rand()-----��MSDN�ϲ���   rand�ķ�Χ---range 0 to RAND_MAX(32767)
//	//��rand����Ҫ�ȵ���srand��������srandҪtime�������������
//	// void srand( unsigned int seed ); srand��Ҫ����������Ϊ�޷����������԰�time��������ȥ
//	//time_t time( time_t *timer );   time_t *timer��NULL��ָ�����
//	//time����Ҫʹ�õ�����----time_t = typedef __time64_t   ��  __time32_t = typedef long
//	//time�������õ�������Ϊlong
//	//srand((unsigned)time(NULL));��srand��������dowhile�����б�����һ����������һ��
//	ret =( rand())%100;//��֤ret����1��100
//	//printf("%d\n", ret);   
//	//2.������
//	int counter = 0;//����������������ÿ�ض����0
//	while (1)
//	{
//		int guess = 0;
//	  //int counter = 0;����������������ÿ�ض����0
//		printf("��������µ�����>: ");
//		scanf("%d", &guess);
//		if (guess < ret)
//		{
//			printf("���С�ˣ�����\n");
//			counter++;
//		}
//		else if (guess > ret)
//		{
//			printf("��´��ˣ�����\n");
//			counter++;
//		}
//		else
//		{
//			printf("��¶��ˣ������������𰸾���%d\n", ret);
//			counter++;
//			printf("��һ������%d��\n", counter);
//			printf("��������һ����?\n");
//			break;
//		}
//	}
//}
//void menu(void)
//{
//	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//	printf("******1.play      0.exit******\n");
//	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
//	printf("����ѡ��>: 1or0\n");
//}
//int main()
//{
//	srand((unsigned)time(NULL));
//	int input = 0;
//	//��Ҫ����Щ��������do while֮ǰ:�ᵼ����ѭ����
//	//menu();
//	//printf("���ѡ��>: ");
//	//scanf("%d", &input);
//	do(input)
//	{
//		menu();
//		printf("���ѡ��>: ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("����Ϸ\n");
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("�������,��ѡһ��\n");
//			break;
//	}; while (input)
//	return 0;
//}



//��������Ϸ
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu(void)
//{
//	printf("**********************************\n");
//	printf("*********1.play    0.exit*********\n");
//	printf("**********************************\n");
//}
//void game(void)
//{
//	int count = 0;
//	int ret = 0;
//	ret = rand() % 100;
//	int guess = 0;
//
//	while (1)
//	{
//		printf("����������µ�����>: ");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���!!\n");
//			count++;
//		}
//		else if (guess < ret)
//		{
//			printf("��С��!!\n");
//			count++;
//		}
//		else
//		{
//			printf("�¶���\n");
//			printf("�𰸾���%d\n", ret);
//			count++;
//			printf("��һ������%d��\n", count);
//			break;
//		}
//	}
//
//}
//int main()
//{
//	srand((unsigned)time(NULL));
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("��Ҫ����Ϸ��? \n");
//		printf("��������>: ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("������Ϸ\n");
//			break;
//		case 1:
//			printf("����Ϸ\n");
//			game();
//			break;
//		default:
//			printf("�������,������������!!!");
//			break;
//		}
//	} while (input);
//	return 0;
//}





//goto���
//#include<stdio.h>
//int main()
//{
//again:
//	printf("��");
//	goto again;
//}
//
//
//��goto���д�ػ�����
//����cmd��command�����У�����shutdown -s -t(�ػ�����)   shutdown -a(�Ӵ��ػ�����)
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//	char input[20] = {0};
//again:
//	printf("ע�⣡������ĵ��Խ���6�����ڹػ�������:wsz����ȡ��QaQ��ʶʱ����Ϊ����Ŷ!!!\n");
//	system("shutdown -s -t 360");
//	printf("�����>: ");
//	scanf("%s", input);//�ؼ�����scanf���ܽ��ո�ǰ���ַ�¼�뻺�����������õĲ��ܳ���"well down"���Ƶ����
//	if (0 == strcmp(input,"wsz"))
//	{
//		printf("����ʶ��");
//		system("shutdown -a");
//	}
//	else
//	{
//		printf("��ܲ���ʵ������");
//		goto again;
//	} 
//	return 0;
//}
//
//
