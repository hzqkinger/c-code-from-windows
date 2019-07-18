#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//½«"student a am i"±ä³É"i am a student"
{
	int i = 0;
	char tmp;
	char arr[] = "student a am i";
	char*p = arr, *q = arr;
	for (i = 0; i <= (strlen(arr) - 1) / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[strlen(arr) - 1 - i];
		arr[strlen(arr) - 1 - i] = tmp;
	}
	while (*p)
	{
		while (*q != ' '&& *q != 0)
			q++;
		char *tmp1 = q-1;
		while (p < tmp1)
		{
			tmp = *p;
			*p = *tmp1;
			*tmp1 = tmp;
			p++, tmp1--;
		}
		while (*q == ' ')
			q++;
		p = q;
	}
	printf("%s\n", arr);
	system("pause");
	return 0;
}

//#include<stdio.h>
//
//int main()
//{
//	int m, n;
//	int i = 0, j = 0;
//	scanf("%d%d", &m, &n);
//	int tmp1 = m;
//	while (m <= n)
//	{
//		i = 0;
//		tmp1 = m;
//		while (tmp1)
//		{
//			i += (tmp1 % 10)*(tmp1 % 10)*(tmp1 % 10);
//			tmp1 /= 10;
//		}
//		if (i == m)
//		{
//			printf("%d ", m);
//			j = 1;
//		}
//		m++;
//	}
//	if (j == 0)
//		printf("no");
//	system("pause");
//	return 0;
//}