#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#pragma warning (disable:4996)
//int main()
//{
//	int arr[] = {11,22,33,44,55,66,77,88,99};
//	int key = 0;
//	int left = 0;
//	int right = sizeof(arr)/sizeof(arr[0]);
//	int mid = 0;
//	printf("请输入数字：");
//	scanf("%d", &key);
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (key < arr[mid])
//		{
//			right = mid-1;
//		}
//		else if (key == arr[mid])
//		{
//			printf("输入的数在数组中第%d位\n", (mid + 1));
//			break;
//		}
//		else
//		{
//			left = mid+1;
//		}
//	}
//	if (left > right)
//	{
//		printf("数组中不存在这样的数!\n");
//	}
//	system("pause");
//	return 0;
//}

//欢迎Play猜数字游戏!
void Binary()
{
	srand(time(NULL));
	int dest = rand() % 100;
	int key = 0;
	int left = 0;
	int right = 100;
	int mid = 0;
	//printf("%d\n", dest);
	while (left <= right)
	{
		printf("请输入1~100数字\n");
		scanf("%d", &key);
		mid = (left + right) / 2;
		if (key < dest)
		{
			right = mid - 1;
			printf("你猜小了");
		}
		else if (key == dest)
		{
			printf("恭喜猜对了\n");
			break;
		}
		else
		{
			left = mid + 1;
			printf("你猜大了");

		}
	}

}

//在有序数组中随便找到一个等于tag的数
int Binary2(int *arr, int left, int right, int tag)//①[left,right)
{
	while (left < right){//注意这里是<，而不是<=
		int mid = (left + right) >> 1;//注意这里mid是取整(ps:只要区间是左闭的，mid取整)
		if (arr[mid] == tag)return mid;
		else arr[mid] < tag ? left = mid + 1 : (right = mid);//注意这里right的取值
	}
	return -1;
}
int Binary3(int *arr, int left, int right, int tag)//②[left,right]
{
	while (left <= right){//注意这里是<=，而不是<
		int mid = (left + right) >> 1;//注意这里mid是取整(ps:只要区间是左闭的，mid取整)
		if (arr[mid] == tag)return mid;
		else arr[mid] < tag ? left = mid + 1 : (right = mid - 1);//注意这里right的取值
	}
	return -1;
}
int Binary4(int *arr, int left, int right, int tag)//③(left,right]
{
	while (left < right){//注意这里是<，而不是<=
		int mid = (left + right + 1) >> 1;//注意这里mid是进一(ps:只要区间是左开的，mid进一)
		if (arr[mid] == tag)return mid;
		else arr[mid] < tag ? left = mid: (right = mid - 1);//注意这里left的取值
	}
	return -1;
}
int Binary5(int *arr, int left, int right, int tag)//④(left,right）
{
	while (left < right - 1){//注意这里是< 且<right-1，而不是<=
		int mid = (left + right + 1) >> 1;//注意这里mid是进一(ps:只要区间是左开的，mid进一)
		if (arr[mid] == tag)return mid;
		else arr[mid] < tag ? left = mid : (right = mid);//注意这里left和right的取值
	}
	return -1;
}

//在有序升序数组中找到第一个大于等于tag的数(ps:不用找最后一个>=tag的数，大家都懂的)
int Binary6(int *arr, int left, int right, int tag)//[left, right)
{
	while (left < right){
		int mid = (left + right) >> 1;
		arr[mid] < tag ? left = mid + 1 : (right = mid);
	}
	return right;//返回第一个大于等于tag的数的下标

	//while (left < right){
	//	int mid = (left + right) >> 1;
	//	arr[mid] <= tag ? left = mid + 1 : (right = mid);//注意这是<=，不是<
	//}
	//return right;//返回第一个大于tag的数的下标
}
//在有序升序数组中找到最后一个小于等于tag的数(ps:不用找第一个<=tag的数，大家都懂的)
int Binary7(int *arr, int left, int right, int tag)//(left, right]
{
	while (left < right){
		int mid = (left + right + 1) >> 1;
		arr[mid] < tag ? left = mid : (right = mid - 1);
	}
	return left;//返回最后一个小于tag的数的下标

	//while (left < right){
	//	int mid = (left + right + 1) >> 1;
	//	arr[mid] <= tag ? left = mid : (right = mid - 1);
	//}
	//return left;//返回最后一个小于等于tag的数的下标
}

int main()
{
	//printf("欢迎Play猜数字游戏!\n");
	//Binary();

	int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };
	int flag = Binary2(arr, 0, sizeof(arr) / sizeof(arr[0]), 55);//[left,right)强烈推荐写法
	printf("%d\n", flag);
	flag = Binary3(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 44);//[left,right]推荐写法
	printf("%d\n", flag);
	flag = Binary4(arr, -1, sizeof(arr) / sizeof(arr[0]) - 1, 44);//(left,right]不推荐写法
	printf("%d\n", flag);
	flag = Binary5(arr, -1, sizeof(arr) / sizeof(arr[0]), 45);//(left,right)非常不推荐写法
	printf("%d\n", flag);

	printf("--------------我是分割线-------------\n");
	int arr2[] = { 11, 22, 22, 23, 33,33, 33, 35, 44, 45, 55,55, 56};
	flag = Binary6(arr2, 0, sizeof(arr2) / sizeof(arr2[0]), 33);// [left, right)
	printf("%d\n", flag);
	//第一个>=tag的数，它前面的一个数就是最后一个<tag的数(边界情况自行考虑)
	//第一个>tag的数，它前面的一个数就是最后一个<=tag的数(边界情况自行考虑)
	flag = Binary7(arr2, -1, sizeof(arr2) / sizeof(arr2[0]) - 1, 33);// (left, right]
	printf("%d\n", flag);

	system("pause");
	return 0;
}