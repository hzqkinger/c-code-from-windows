#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//题四
{
	int i,m, n, x, y, sum = 0, count = 0;
	printf("请输入两个数：\n");
	scanf("%d%d", &m, &n);
	for (i = m; i <= n;m++)
	{
		x = i;
		y = 0;
		sum = 0;
		while (i)
		{
			y = i % 10;
			i = i / 10;
			sum += y*y*y;
		}
		if (sum == m)
		{
			printf("%d ", m);
			count++;
		}
		i = m+1;
	}
	if (count == 0)
		printf("no\n");
	system("pause");
	return 0;
}