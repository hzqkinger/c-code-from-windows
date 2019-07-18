////#include<iostream>
////using namespace std;
//#include<stdio.h>
//#include<stdlib.h>
//
//#pragma warning (disable:4996)
//
//int main()
//{
//	int a = 11;
//	//char str1[256] = {1};
//	//itoa(a, str1, 2);
//	 a = a | ((a&1)<<2);
//	//printf("%s", str1);
//	printf("%d\n", a);
//	system("pause");
//
//	return 0;
//
//}

#include<stdio.h>
#include<Windows.h>
int main()
{	
	int num = 0;
	int count = 0;
	printf("请输入一个十进制数：");
	scanf("%d\n", &num);
	while (num != 0)
	{
		num = num &(num - 1);
		count++;

	}
	//num = num >> 1;
	printf("%d\n", num);
	system("pause");
	return 0;
}