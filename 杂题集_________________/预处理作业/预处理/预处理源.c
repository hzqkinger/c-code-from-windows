#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)
#if 0  // 交换一个数的奇偶位
#define SWAP(m) (((m&0xaaaaaaaa)>>1)|((m&0x55555555)<<1) )
int main()
{
	int a = 0;
	printf("请输入数字：");
	scanf("%d", &a);
	printf("%d\n",SWAP(a));
	system("pause");
	return 0;
}
#endif
#if 0  //求两个数中最大的数
#define MAX(x,y) ((x)>(y)?(x):(y))
int main()
{
	int a = 0, b = 0;
	printf("请输入两个数");
	scanf("%d%d", &a, &b);
	printf("%d\n", MAX(a, b));
	system("pause");
	return 0;
}
#endif
#if 0     //两个数二进制中有多少个不同位
int main()
{
	int m = 0, n = 0;
	int ret = 0, count = 0;
	printf("请输入两个数");
	scanf("%d%d", &m, &n);
	ret = m^n;
	while (ret != 0)
	{
		ret &= (ret - 1);
		count++;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
#endif
#if 0         //将一个数组中的奇数放在数组前面
int main()
{
	int i = 0, j = 0;
	int temp = 0;
	int arr[10];// = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("请输入10正整数：");
	for (i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 0)
		{
			for (j = 9; j >i; j--)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	system("pause");
	return 0;
}
#endif
//#if 0                 //杨氏矩阵中找是否存在输入的数据
#define Row 3
#define Cols 4
int main()
{
	int r = 0;
	int c = Cols - 1;
	int i = 0, key = 0;
	int arr[][4] = { 1, 3, 4, 7, 2, 5, 6, 13, 7, 8, 9, 14 };
	printf("请输入一个数：");
		scanf("%d", &key);
	//printf("请输入数组arr[3][4]的12个初始值：");
	//for (i = 0; i < 12; i++)
	//	scanf("%d", &arr[i]);
	while (r < Row)
	{
		if ((key < arr[r][c]) && (c >= 0))
			c--;
		else if ((key == arr[r][c]) && (c >= 0))
		{
			printf("数组中存在这样的数！");
			break;
		}
		else
		r++;
	}
	if (r == Row)
		printf("数组中不存在这样的数！");
	system("pause");
	return 0;
}
//#endif
