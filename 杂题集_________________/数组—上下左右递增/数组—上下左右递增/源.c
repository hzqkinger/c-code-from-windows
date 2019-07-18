#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<CoreWindow.h>
#define ROW 4
#define COL 4
int main()
{
	int arr[ROW][COL] = { 1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 15, 16, 17
	};
	int i = 0, j = 0;
	int num;
	puts("please enter a number>");
	scanf("%d", &num);
	while (1)
	{
		if (num > arr[i][j])
		{
			if (j < COL - 1)j++;
			else i++;
			if (i == ROW)
			{
				printf("no exist");
				break;
			}
		}
		else if (num == arr[i][j])
		{
			printf("%d %d\n", i, j);
			break;
		}
		else
		{
			j--;
			if (j < 0 || num > arr[i][j])
			{
				printf("no exist\n");
				break;
			}
		}
	}
	system("pause");
	return EXIT_SUCCESS;//头文件中包含了#define EXIT_SUCCESS 0和#define EXIT_FAILURE 1
}