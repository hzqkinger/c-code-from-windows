#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)
#if 0
int main()
{
	int a, b, c, d, e;
	for (a = 1; a < 6; a++)
	{
		for (b = 1; b < 6; b++)
		{
			for (c = 1; c < 6; c++)
			{
				for (d = 1; d < 6; d++)
				{
					for (e = 1; e < 6; e++)
					{
						if (   ((b == 1) || (a == 3))\
							&& ((b == 2) || (e == 4))\
							&& ((c == 1) || (d == 2))\
							&& ((c == 5) || (d == 3))\
							&& ((e == 4) || (a == 1))\
							&& (a != b) && (a != c)\
							&& (a != d) && (a != e)\
							&& (b != c) && (b != d)\
							&& (b != e) && (c != d)\
							&& (c != e) && (d != e))
						{
							printf("%d %d %d %d %d\n", a, b, c, d, e);
							break;
						}

					}

				}
			}

		}
	}
	system("pause");
	return 0;
}
#endif
//#if 0
int main()
{
	int a, b, c, d ;
	for (a = 0; a < 2; a++)
	{
		for (b = 0; b < 2; b++)
		{
			for (c = 0; c < 2; c++)
			{
				for (d = 0; d < 2; d++)
				{
					if (a + b + c + d == 1)   //1表示是凶手，0表示不是
					{
						if ((a == 1) && (c == 1) && (d == 1) && ((a == 1) || (b == 1) || (c == 1)))
						{
							printf("A=%d B=%d C=%d D=%d\n", a, b, c, d);
						}
						if (((b == 1) || (c == 1) || (d == 1)) && (c == 0) && (d == 1) && ((a == 1) || (b == 1) || (c == 1)))
						{
							printf("A=%d B=%d C=%d D=%d\n", a, b, c, d);
						}
						if (((b == 1) || (c == 1) || (d == 1)) && (c == 1) && (d == 0) && ((a == 1) || (b == 1) || (c == 1)))
						{
							printf("A=%d B=%d C=%d D=%d\n", a, b, c, d);
						}
						if (((b == 1) || (c == 1) || (d == 1)) && (c == 1) && (d == 1) && (d == 0))
						{
							printf("A=%d B=%d C=%d D=%d\n", a, b, c, d);
						}
					}

				}
			}
		}
	}
	printf("输出对应数字为1的是凶手！\n");
	system("pause");
	return 0;
}
//#endif