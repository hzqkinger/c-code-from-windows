#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main()
{
	int key1 = 0;
	int num = 0;
	printf("��������Ҫ��֤�����֣�\n");
	scanf("%d", &num);
	int key = num;
	while (key)
	{
		key1 = key1 * 10 + key % 10;
		key /= 10;
	}
	if (key1 == num)
		printf("�����ǻ�������\n");
	else
		printf("not\n");
	system("pause");
	return 0;
}