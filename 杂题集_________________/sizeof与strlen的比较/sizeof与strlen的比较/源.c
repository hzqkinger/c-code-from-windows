#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
//sizeof strlen  ����  ָ���ƶ�������Ļ��
int main()
{                                    //ֻ����������£�������������ָ�볣������ʾ�����ǵ�
	//int a[] = { 1, 2, 3, 4 };       //��������������Ϊsizeof�������Ĳ�����     
	//char a[] = { 1, 2, 3, 4,0 };       //   �ڵ�����Ϊ��Ŀ������&�Ĳ����� 
	char a[] = { 'a', 'b', 'c', 'd', 'e','44'};      //���е�ַ��ָ�룩��ռ���ֽڶ���4
	//char *a = "abcdefg";                           //ָ��������ǲ�ͬ�ģ���ͬ��
	printf("%d\n", sizeof(a));       //16 45 5 ��
	printf("%d\n", sizeof(a+0));      //4 44 4 4
	printf("%d\n", sizeof(*a));       //4 11 1 1
	printf("%d\n", sizeof(a+1));      //4 44 4 4
	printf("%d\n", sizeof(a[1]));     //4 11 1 1
	printf("%d\n", sizeof(&a));       //4 44 4 4
	printf("%d\n", sizeof(*&a));     //16 45 5 ��
	printf("%d\n", sizeof(&a+1));     //4 44 4 4
	printf("%d\n", sizeof(&a[0]));    //4 44 4 4
	printf("%d\n", sizeof(&a[0] + 1));//4 44 4 4

	//char *p = "abcdef";    //�ַ�������
	////char p[] = { 'a', 'b', 'c', 'd', 'e', 'f', '0' };
	////char p[] = { 'a', 'b', 'c', 'd', 'e', 'f', 0 };
	////char p[] = { 'a', 'b', 'c', 'd', 'e', 'f', '\0' };
	//char a = *p;
	//printf("%c", *p);
	//printf("%d\n", strlen(p));      //6    6
	//printf("%d\n", strlen(p+1));    //5    5
	////printf("%d\n", strlen(*p));     //1  
	////printf("%d\n", strlen(p[0]));   //6
	//printf("%d\n", strlen(&p));     //x    6
	//printf("%d\n", strlen(&p+1));   //x    x
	//printf("%d\n", strlen(&p[0]+1));//��   5

	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));      //48
	//printf("%d\n", sizeof(a[0][0]));//4
	//printf("%d\n", sizeof(a[0]));   //16
	//printf("%d\n", sizeof(a[0]+1)); //4
	//printf("%d\n", sizeof(a+1));    //��
	//printf("%d\n", sizeof(&a[0]+1));//��
	//printf("%d\n", sizeof(*a));     //16
	//printf("%d\n", sizeof(a[3]));   //16

	//int a[3][4] = { 1, 2, 3, 4, \      //��ά����
	//				5, 6, 7, 8, \
	//					9, 10, 11, 12 };
	//printf("%d\n", *a[2]);
	//printf("%d\n", *(*(a+2)));
	//printf("%d\n", a[2][0]);

	//char a[][4] = { 1, 2, 3, 4,\
	//		           5, 6, 7, 8 };
	//char(*p)[4];
	//p = a;
	//printf("%d\n", sizeof(*a));     //ʮ��    4  
	//printf("%d\n", sizeof(*a+1));   // ��     ��
	//printf("%d\n", sizeof(a));      //0  0 32 8
	//printf("%d\n", sizeof(a + 1));  //4 16 4  4
	//printf("%d\n", sizeof(*p));     //0  0 16 4
	//printf("%d\n", sizeof(*p + 1)); //4  4 4  ��    //*p+1�൱��*(p+0)+1
	//printf("%d\n", sizeof*(p + 1)); //4  4 16 4
	//printf("%d\n", sizeof(&a));     //0  0 4  4
	//printf("%d\n", sizeof(&a + 1));//32 32 4  4
	//printf("%d\n", sizeof(p));      //0  0 4  4
	//printf("%d\n", sizeof(p + 1)); //16 16 4  4

	system("pause");
	return 0;
}
