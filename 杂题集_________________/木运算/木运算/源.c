#include<stdio.h>
#include<string.h>
#include<Windows.h>

#pragma warning (disable:4996)
//int main()
//{
	//1丶逆序输出一个整数的各位
//	int num = 0;
//	int r= 0;
//	printf("请输入一个数字：");
//	scanf_s("%d", &num);
//	do
//	{
//		r = num % 10;
//		num = num / 10;
//		printf("%d ", r);
//	}
//	while (num != 0);

	//2丶正序输出一个整数的各位
	//int len = 0;
	//int i = 0;
	//char num[100];
	//printf("请输入一个整数：");
	//scanf("%s", num);
	//len = strlen(num);
	//for (i = 0; i < len; i++)
	//{
	//	printf("%c\n", num[i]);

	//}
//	system("pause");
//	return 0;
//}

//3丶递归调用正序输出整数各位

void print(int num)
{
	if (num / 10 != 0)
	{
		print(num / 10);
	}
	printf("%d\n", num % 10);

}
int main()
{
	int num = 0;
	void print(int);
	printf("请输入一个整数：");
	scanf("%d", &num);
	print(num);
	system("pause");
	return 0;
}