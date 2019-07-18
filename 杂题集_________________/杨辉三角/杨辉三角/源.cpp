#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
//#define N 10//Ñî»ÔÈý½Ç
#define N 10
int main()
{
	int arr[N][N] = { 0 };
	int i = 0, j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j || j == 0)
				arr[i][j] = 1;
			else if (i < j)
				arr[i][j] = 0;
			else if (i > j)
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
				break;
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}