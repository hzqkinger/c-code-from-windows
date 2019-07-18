#include<stdio.h>
#pragma warning (disable:4996)
int main()
{
	int a = 11;
	int b = 22;
	int c = 33;
	int temp = 0;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a < c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if (b < c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	printf("%d\n%d\n%d\n", a, b, c);
	system("pause");
	return 0;
}