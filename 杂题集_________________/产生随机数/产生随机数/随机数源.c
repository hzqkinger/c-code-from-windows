#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)

int main()
{
	int a = rand() % 25;
	int b = 26 % 9;
	printf("%d\n%d\n", a,b);


	system("pause");
	return 0;
}