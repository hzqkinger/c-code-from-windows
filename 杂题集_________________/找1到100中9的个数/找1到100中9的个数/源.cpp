#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()
{
	int i = 0,tmp = 0;
	int count = 0;
	for (i = 1; i < 100; i++)
	{
		tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 9)
				count++;
				tmp /= 10;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}