#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#define N 100000//ȷ��N��ֵ�����������������n
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



//int main()       //����
//{                        //��̨��m�ߵ�n,��̨�����k��Լ����������1��k��������������߼�����
//	int m, n,i,j,count = 0;
//	printf("please enter two numbers:\n");
//	scanf("%d%d", &m,&n);
//	//�ж�m��Ϊ�����������whileѭ�������n�������ͳ�����ѭ����覴ã���֪�����ⲽд���ܹ�����
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