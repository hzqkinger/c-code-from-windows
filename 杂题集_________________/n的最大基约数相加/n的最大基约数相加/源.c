//#define CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<Windows.h>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<Windows.h>
int main()
{                      //����n����������1~n�������������Լ��֮��
	int n,sum = 0;
	printf("please enter the number of n:\n");
	scanf("%d", &n);
	while (n)
	{
		sum += ((n + 1) / 2 )*((n + 1) / 2);
		n /= 2;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}