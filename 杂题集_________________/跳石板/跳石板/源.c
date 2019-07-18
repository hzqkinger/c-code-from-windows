#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#define N 100000//确保N的值大于下面输入的数字n
int main()
{
	int m, n, i, j, count = 0;
	printf("please enter two numbers:\n");
	scanf("%d%d", &m, &n);
	int mark[N] = { 0 };
	for (i = 0; i < N; i++)
	{
		mark[i] = N;
	}
	for (i = m; i < n + 1; i++)
	{
		mark[m] = 0;
		if (mark[i] == N)
			continue;
		else
		{
			for (j = 2; j <= i / 2; j++)
			{
				if (i%j == 0&&mark[i+j]>mark[i]+1)
				{
					mark[i + j] = mark[i] + 1;
				}
			}
		}
	}
	if (mark[n] == N)
		printf("-1\n");
	else
		printf("%d\n", mark[n]);
	system("pause");
	return 0;
}



//int main()       //（）
//{                        //从台阶m走到n,走台阶序号k的约数步（不走1或k步），输出最少走几步。
//	int m, n,i,j,count = 0;
//	printf("please enter two numbers:\n");
//	scanf("%d%d", &m,&n);
//	//判断m不为质数；下面的while循环里如果n是质数就成了死循环（瑕疵，不知道把这步写了能过不）
//	while (1)
//	{
//		for (j = n / 2; j > 1; j--)
//		{
//			if (n%j == 0&&n>2*j)
//			{
//				count++;
//				n -= j;
//				//printf("%d  ", n);
//				break;
//			}
//		}
//		if (n <= m)
//		{
//			//printf("\n");
//			break;
//		}
//	}
//	if (m == n)
//		printf("%d\n", count);
//	else
//		printf("-1");
//	system("pause");
//	return 0;
//}