#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<Windows.h>
int main()
{
	int i = 0;
	for (printf("��%d\n", i), i = 0; printf("��%d\n", i), i < 5; printf("��%d\n", i), i++)
		printf("��%d\n", i);           //��֤forѭ����ִ��˳��
	system("pause");
	return 0;
}