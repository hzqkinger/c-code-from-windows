#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
void fun(char *s, char *p1, char *p2)//一个字符串有两个字符串组成
{
	int count = 0;
	char*tmp1 = s;
	char*tmp2 = p1;
	char*tmp3 = p2;
	while (*tmp1)
		count++, tmp1++;
	while (*tmp2)
		count--, tmp2++;
	while (*tmp3)
		count--, tmp3++;
	if (count != 0)
	{
		printf("not\n");
		return;
	}
	else
	{
		while (*p1 != 0 && *p2 != 0)
		{
			if (*p1 == *s && *p2 == *(s + 1))
				p1++, p2++, s += 2;
			else
			{
				printf("not\n");
				return;
			}
		}
		if (*p1 == 0)
		{
			while (*p2 != 0)
			{
				if (*p2 == *s)
					p2++, s++;
				else
				{
					printf("not\n");
					return;
				}
			}
		}
		else
		{
			while (*p1 != 0)
			{
				if (*p1 == *s)
					p1++, s++;
				else
				{
					printf("not\n");
					return;
				}
			}
		}
		if (*p1 == 0 && *p2 == 0)
		{
			printf("yes\n");
			return;
		}
	}

}
int main()
{
    char *str = "codewars";
    char *part1 = "cdw";
    char *part2 = "oeas";
	fun(str, part1, part2);
	system("pause");
	return 0;
}