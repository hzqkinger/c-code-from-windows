#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#if 0
void rev(int x)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%2d*%2d=%2d", i, j, i*j);
		printf("\n");
	}
}
int main()
{
	int num = 0;
	printf("���������֣�");
	scanf("%d", &num);
	rev(num);
	system("pause");
	return 0;
}
#endif
#if 0
void exchange(int* x, int* y)
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	printf("����������������\n");
	scanf("%d%d", &a, &b);
	exchange(&a, &b);
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}
#endif
void leap(int year1)
{
	if (year1 % 4 == 0 && year1 % 100 != 0 || year1 % 400 == 0)
		printf("����������Ϊ���꣡\n");
	else
		printf("���������ݲ������꣡\n");
}
int main()
{
	int year = 0;
	printf("��������ݣ�");
	scanf("%d", &year);
	leap(year);
	system("pause");
	return 0;
}
	
#if 0
void check(int*arr1,int key,int len1)
{
	int left = 0;
	int right = len1;
	int mid = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (key < arr1[mid])
		{
			right = mid - 1;
		}
		else if (key == arr1[mid])
		{
			printf("��������������е�%dλ\n", (mid + 1));
			break;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (left > right)
	{
		printf("�����в�������������!\n");
	}
}
int main()
{
	int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int key = 0;
	printf("���������֣�");
    scanf("%d", &key);
	check(arr,key,len);
	system("pause");
	return 0;
}
#endif