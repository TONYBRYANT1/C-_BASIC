#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int a = -1;
//	int b = a >> 100;//���Է���Ϊ��׼������
//	printf("%d", b);
//}
//����>>1   (��һ���Զ�)
//����>>1   (���Զ�)




//�������±�������������
//#include<stdio.h>
//int main()
//{
	//1.�Ӽ���:ȱ��:a,b����ֵ����̫��
	//int a = 3;
	//int b = 5;
	//scanf("%d%d", &a, &b);
	//printf("%d %d \n", a, b);
	//a = a + b;//(8)
	//b = a - b;//(3)
	//a = a - b;//(5)
	//printf("%d %d \n", a, b);
	//2.��λ���:�ô��ǰ�λ��򲻻ᵼ��int���
	//           ������1.ִ��Ч�ʲ���temp2.�ɶ��Բ�
	//int a = 3;//0011
	//int b = 5;//0101
	//scanf("%d%d", &a, &b);
	//printf("%d %d \n", a, b);
	//a = a ^ b;//(0110)------->����
	//b = a ^ b;//����^3=5
	//a = b ^ a;//����^5=3
	//printf("%d %d \n", a, b);
//}




//��һ�����Զ����ƴ洢�Ĺ����л��м���һ:   &
//#include<stdio.h>
//int main()
//{
	//1.ȱ��:��������ȡ
	//int num = 0;
	//scanf("%d", &num);
	//int count = 0;
	//while (num != 0)//while(num)
	//{
	//	if ((num % 2) == 1)
	//		count++;
	//	num = num / 2;
	//}
	//printf("%d", count);
	//2.�Ż�:
	/*int num = 1;
	scanf("%d", &num);
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 == ((num >> i) & 1))
			count++;
	}
	printf("%d", count);*/
//}







//3.��Ŀ������
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int  [10]��arr������
//	int ret=sizeof(int[10]);
//	printf("%d", ret);
//	pirntf("%d", sizeof(a));
//	pirntf("%d", sizeof a);
//	pirntf("%d", sizeof(int));
//	//pirntf("%d", sizeof int );(X)   ��ʾsizeof���Ǻ��������ǲ�����
//}






//sizeof()�����ڵ�ʽ�Ӳ���������
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	short s = 0;
//	printf("%d\n", sizeof(s=a+5));
//	printf("%d\n", s);
//  return 0; 
//}





//��λȡ��  ' ~ '
#include<stdio.h>
int main()
{
	//int a = 0;
	////00000000000000000000000000000000
	////11111111111111111111111111111111----����
	////11111111111111111111111111111110----����
	////10000000000000000000000000000001----ԭ��
	//printf("%d", (~a));



	int a = 11;
	a = a | (1 << 2);//------------|
	printf("%d", a);//-------------| --->������
    a = a & (~(1 << 2));//---------|
	printf("%d", a);
	return 0;
}