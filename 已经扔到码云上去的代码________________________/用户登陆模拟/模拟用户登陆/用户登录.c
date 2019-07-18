#include<stdio.h>
#pragma warning (disable:4996)
#include<Windows.h>
#include<string.h>
int main()
{
	int i = 0;
	int count = 0;
	char arc[] = "654321";
	char brc[10];
	printf("请输入登陆密码：");
	scanf("%s", brc);
	for (count = 1; count < 3; count++)
	{
		if (strcmp(brc, arc)!= 0)
		{
			printf("请重新输入密码：");
			scanf("%s", brc);
		}
		else
		{
			break;
		}
	}
	if (count == 3)
	{
		printf("三次密码错误，退出系统");
	}
	else
	{
		printf("登陆成功");
	}
	system("pause");
	return 0;
}
//int main()
//{
//	char key[] = "123456";
//	char input[10];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：");
//		scanf("%s", input);
//		if (strcmp(key, input) == 0)
//		{
//			break;
//		}
//		else
//		{
//			printf("error");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次错误，退出系统\n");
//	}
//	else
//	{
//		printf("登陆成功");
//	}
//
//	system("pause");
//	return 0;
//}