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
	printf("������m,n��ֵ��");
	scanf("%d%d", &m, &n);
	xor = m^n;
	for (; xor != 0;)
	{
		xor &= (xor - 1);
		count++;
	}
	printf("m,n�Ķ�������%d����ͬ\n", count);
	system("pause");
	return 0;
}