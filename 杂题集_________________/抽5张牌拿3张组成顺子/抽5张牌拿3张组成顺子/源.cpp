#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
//扑克牌抽5张牌拿3张组成顺子，，，抽牌阶段有问题，可能抽到>3的王和5张一样的牌如5个k。
#define LEN 54
int* Initarr(int *arr)
{
	int i = 0;
	for (i = 0; i < LEN; i += 4)
		arr[i] = arr[i + 1] = arr[i + 2] = arr[i + 3] = i / 4 + 1;
	arr[52] = 0;
	arr[53] = 0;
	return arr;
}
int main()
{
	int arr[LEN] = { 0 };
	int arr2[5] = { 15,16,17,18,19 };
	int i = 5,j = 0;
	srand(time(NULL));
	Initarr(arr);
	for (i = 0; i < LEN; i++)
		printf("%d\n", arr[i]);
	while (i)
	{
		int x;
		//int cnt1 = 0, cnt2 = 0;
		//if (cnt1 < 3 && cnt2 < 5)
		//{
			x = rand() % LEN;

		//}
		if (arr[x]==1)
			arr2[5 - i] = arr[x] + 13;
		else
			arr2[5 - i] = arr[x];
		i--;
		//if (arr2[i] == 0)
		//	cnt1++;
		//else
		//{
		//	for (i = 0; i < 5; i++)
		//	{
		//		cnt2 = 0;
		//		for (j = i + 1; j < 5; j++)
		//	/	{
		//			if (arr2[i] == arr2[j])
		//				cnt2++;
		//		}
		//	}
		//}
	}
	for (i = 0; i < 5; i++)
		printf("%d\n", arr2[i]);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4 - i; j++)
		{
			if (arr2[j]>arr2[j + 1])
			{
				int tmp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < 5; i++)
		printf("%d\n", arr2[i]);
	if (arr2[0] == 0)
	{
		if (arr2[1] > 0)
		{
			for (i = 1; i < 4; i++)
			{
				if (arr2[i] - arr2[i + 1] == -1)
					printf("能组成顺子！\n");
				else
					printf("不能！\n");
			}
		}
		else
			printf("能组成顺子！\n");
	}
	else
	{
		for (i = 0; i < 3; i++)
		{
			if (arr2[i] - arr2[i + 1] == -1 && arr2[i + 1] - arr2[i + 2] == -1)
				printf("能组成顺子！\n");
		}
		if (i == 3)
			printf("不能！\n");
	}
	//for (i = 0; i < LEN; i++)
	//	printf("%d\n", arr[i]);
	system("pause");
	return 0;
}