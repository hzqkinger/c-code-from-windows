#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//һ���ַ������ҵ�һ��ֻ����һ�ε��ַ�
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