#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int fun( int n)//猴子吃桃的递归问题
{
	if (n == 1)
		return 1;
	else
		return 2 * fun(n - 1) + 1;
}
int main()
{
	int day = 10;
	printf("%d\n",fun(day));
	system("pause");
	return 0;
}
