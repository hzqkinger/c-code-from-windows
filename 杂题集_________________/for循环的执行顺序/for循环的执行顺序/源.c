#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<Windows.h>
int main()
{
	int i = 0;
	for (printf("①%d\n", i), i = 0; printf("②%d\n", i), i < 5; printf("③%d\n", i), i++)
		printf("④%d\n", i);           //验证for循环的执行顺序
	system("pause");
	return 0;
}