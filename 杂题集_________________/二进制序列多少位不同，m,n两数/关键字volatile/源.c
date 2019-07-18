#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main(){
	int m = 0;
	int n = 0;
	int xor = 0;
	int count = 0;
	printf("请输入m,n的值：");
	scanf("%d%d", &m, &n);
	xor = m^n;
	for (; xor != 0;)
	{
		xor &= (xor - 1);
		count++;
	}
	printf("m,n的二进制有%d个不同\n", count);
	system("pause");
	return 0;
}