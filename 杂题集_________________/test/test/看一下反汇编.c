#include<stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main()
{
	int a = 10;
	int b = 11;
	int ret = 0;
	int ret = Add(a, b);
	printf("ret = %d\n", ret);
	return 0;
}