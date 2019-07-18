#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//一个字符串查找第一个只出现一次的字符
{
	char *p = "aabfb";
	char *tmp = NULL,*tmp1 = p;
	int count = 0;
	while (*p)
	{
		tmp = tmp1;
		while (*tmp)
		{
			if (*p == *tmp)
				count++;
			tmp++;
		}
		if (count == 1)
		{
			printf("%c\n", *p);
			break;
		}
		else
			count = 0;
		p++;
	}
	system("pause");
	return 0;
}