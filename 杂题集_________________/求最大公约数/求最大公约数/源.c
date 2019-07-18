#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()
{
	//int i, x, y, m, n;//③列举法求最大公约数
	//printf("请输入两个数：\n");
	//scanf("%d%d", &x, &y);
	//m = x;
	//n = y;
	//for (i = x; i > 0; i--)
	//{
	//	if (x%i == 0 && y%i == 0)
	//		break;
	//}
	//printf("%d\n", i);

	int x, y, m, n;               //②辗转相减法
	printf("请输入两个数：\n");
	scanf("%d%d", &x, &y);
	m = x;
	n = y;
	while (x != y)
	{
		if (x > y)
			x = x - y;
		else
			y = y - x;
	}
	printf("%d\n", x);
	printf("%d\n", m*n / x);

	//int x, y, z, m, n;               //①辗转相除法
	//printf("请输入两个数：\n");
	//scanf("%d%d", &x, &y);
	//m = x;
	//n = y;
	//while (y != 0)
	//{
	//	z = x%y;
	//	x = y;
	//	y = z;
	//}
	//printf("%d\n", x);
	//printf("%d\n", m*n / x);
	system("pause");
	return 0;
}