#include<stdio.h>
#include<Windows.h>
#include<string.h>
#pragma warning (disable:4996)
int main()
{
	float sum = 0;
	float sign = 1;
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		sum = sum + (sign / i);
		sign = -sign;
	}
	printf("%f\n", sum);
	system("pause");
	return 0;
}