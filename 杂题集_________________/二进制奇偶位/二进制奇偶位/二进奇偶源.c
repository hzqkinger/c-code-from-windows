#include<stdio.h>
#include<CoreWindow.h>
#pragma warning (disable:4996)
#include<math.h>
int main()
{
	int a = 0;
	int i = 0;
	int count = 0;
	int temp1[16];
	int temp2[16];
	printf("请输入数字：");
	scanf("%d", &a);
	while (count < 32)
	{
		temp1[count / 2] = a % 2;
		count++;
		a /= 2;
		temp2[(count - 1) / 2] = a % 2;
		count++;
		a /= 2;
	}
	printf("奇数列：\n");
	for (i=15; i >= 0; i--)
		printf("%d", temp1[i]);
	printf("\n");
	printf("偶数列：\n");
	for (i=15; i >= 0;i--)
		printf("%d", temp2[i]);
	printf("\n");
	system("pause");
	return 0;
}
