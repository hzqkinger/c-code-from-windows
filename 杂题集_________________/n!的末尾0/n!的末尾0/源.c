#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<Windows.h>
int main()
{                 //输入n，输出结果是n!末尾零的个数。
	int i, n, num,count = 0;
	printf("请输入n的值：\n");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		num = i;
		while (num % 5 == 0)
		{
			count++;
			num /= 5;
		}
	}
	i = printf("%d!末尾零的个数 %d\n",n, count);
	printf("printf的副作用%d\n", i);
	system("pause");
	return 0;
}