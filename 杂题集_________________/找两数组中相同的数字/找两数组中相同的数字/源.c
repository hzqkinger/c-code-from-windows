#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
#define M 100//题十九
#define N 100
int main()
{
	int m, n, i, j;
	printf("请分别输入两个数组的大小：\n");
	scanf("%d%d", &m, &n);
	int arr1[M] = { 0 };
	int arr2[N] = { 0 };
	printf("请输入第一个数组的元素：\n");
	for (i = 0; i < m; i++)
		scanf("%d", &arr1[i]);
	printf("请输入第二个数组的元素：\n");
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

//C指针作业2
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