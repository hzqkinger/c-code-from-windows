#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<Windows.h>
int main()
{                 //����n����������n!ĩβ��ĸ�����
	int i, n, num,count = 0;
	printf("������n��ֵ��\n");
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
	i = printf("%d!ĩβ��ĸ��� %d\n",n, count);
	printf("printf�ĸ�����%d\n", i);
	system("pause");
	return 0;
}