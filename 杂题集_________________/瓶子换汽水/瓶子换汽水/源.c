#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()
{
	int money = 20;
	int bott = money / 2;
	int count = bott;
	while (bott>1)
	{
		count += bott/2;
		bott = bott / 2 + bott % 2;
		
	}
	count++;
	printf("%d\n", count);

	system("pause");
	return 0;
}