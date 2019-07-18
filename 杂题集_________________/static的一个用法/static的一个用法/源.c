#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
//static int j;
void fun2()
{
	static int j;
	j = 0;
	j++;
}
int main()
{
	int k = 0;
	for (k = 0; k < 10; k++)
	{
		fun2();
	}

	system("pause");
	return 0;
}