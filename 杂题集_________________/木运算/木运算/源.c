#include<stdio.h>
#include<string.h>
#include<Windows.h>

#pragma warning (disable:4996)
//int main()
//{
	//1ؼ�������һ�������ĸ�λ
//	int num = 0;
//	int r= 0;
//	printf("������һ�����֣�");
//	scanf_s("%d", &num);
//	do
//	{
//		r = num % 10;
//		num = num / 10;
//		printf("%d ", r);
//	}
//	while (num != 0);

	//2ؼ�������һ�������ĸ�λ
	//int len = 0;
	//int i = 0;
	//char num[100];
	//printf("������һ��������");
	//scanf("%s", num);
	//len = strlen(num);
	//for (i = 0; i < len; i++)
	//{
	//	printf("%c\n", num[i]);

	//}
//	system("pause");
//	return 0;
//}

//3ؼ�ݹ�����������������λ

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
	printf("������һ��������");
	scanf("%d", &num);
	print(num);
	system("pause");
	return 0;
}