#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()//注意数组下标的变化
{
	int i, k = 0, s[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (i = 0; i < 10;i++)
	if (i % 2)
		k += s[i];
	for (i = i -1; i >= 0; i--)
	if (i % 5 == 0)
		printf("%d\t", s[i]);
	printf("%d\n", k);

	system("pause");
	return 0;
}