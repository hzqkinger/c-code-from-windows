#include<stdio.h>
int main()
{
	int  a = 11;
	int b = 22;
    a = a ^ b;
	b = a ^ b;
	a = a ^b;
	printf("%d\n%d\n", a, b);
	system("pause");
	return 0;
 }