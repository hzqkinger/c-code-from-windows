#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
#define M 100//��ʮ��
#define N 100
int main()
{
	int m, n, i, j;
	printf("��ֱ�������������Ĵ�С��\n");
	scanf("%d%d", &m, &n);
	int arr1[M] = { 0 };
	int arr2[N] = { 0 };
	printf("�������һ�������Ԫ�أ�\n");
	for (i = 0; i < m; i++)
		scanf("%d", &arr1[i]);
	printf("������ڶ��������Ԫ�أ�\n");
	for (i = 0; i < n; i++)
		scanf("%d", &arr2[i]);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr1[i] == arr2[j])
				printf("%d ", arr1[i]);
		}
	}
	system("pause");
	return 0;
}

//Cָ����ҵ2
//int main()
//{
//	int i = 0,j = 0;
//	int count = 0;
//	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6 };
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		count = 0;
//		for (j = 0 ; j < sizeof(arr) / sizeof(arr[0]); j++)
//		{
//			if (arr[i] == arr[j])
//				count++;
//		}
//		if (count == 1)
//			printf("%d\n", arr[i]);
//	}
//	system("pause");
//	return 0;
//}