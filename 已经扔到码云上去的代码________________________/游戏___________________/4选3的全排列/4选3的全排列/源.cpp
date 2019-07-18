#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//х╚ееап
{
	int i = 0,j = 0,k = 0;
	int count = 0;
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 5; j++)
		{
			if (j == i)
				continue;
			for (k = 1; k < 5; k++)
			{
				if ((k == i) || (k == j))
					continue;
				printf("%3d\n", 100 * i + 10 * j + k);
				count++;
			}
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}