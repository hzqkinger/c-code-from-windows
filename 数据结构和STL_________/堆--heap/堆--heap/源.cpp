#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<time.h>

#include"HEAP.h"
#include"test_priority_queue.h"

void Adjdown(int *arr,int i,int size)//建小堆
{
	int parent = i;
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] < arr[child])//建小堆的比较
			++child;
		if (arr[child] < arr[parent])//建小堆的比较
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void Adjdown2(int *arr, int i, int size)
{
	int parent = i;
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])//建大堆的比较
			++child;
		if (arr[child] > arr[parent])//建大堆的比较
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void Find_k_num(int *arr, int k, int size)//k和size都代表数据的个数
{
	int i;
	for (i = (k - 2) / 2; i >= 0; --i)//先将前k个数据建成大堆或者小堆（找最大的k个数建小堆；找最小的k个数建大堆）
		Adjdown(arr, i, k);

	for (i = k; i < size; ++i)
	{
		if (arr[i]>arr[0])
		{
			swap(arr[i], arr[0]);
			Adjdown(arr, 0, k);//每次都是第0个位置需要调整
		}
	}
	for (i = 0; i < k; ++i)//打印找出来的k个数
		printf("%-5d", arr[i]);
	printf("\n");
}
void HeapSort_Descend(int *arr, int size)//建小堆
{                            //size表示size个数
	int i, tmp = size;
	for (i = (size - 2) / 2; i >= 0; --i)
		Adjdown(arr, i, size);
	while (size--)
	{
		swap(arr[0], arr[size]);
		Adjdown(arr, 0, size);
	}

	for (i = 0; i < tmp; ++i)
		printf("%5d", arr[i]);
	printf("\n");
}
void HeapSort_Ascend(int *arr, int size)//建大堆
{                            //n表示n个数
	int i, tmp = size;
	for (i = (size - 2) / 2; i >= 0; --i)
		Adjdown2(arr, i, size);
	while (size--)
	{
		swap(arr[0], arr[size]);
		Adjdown2(arr, 0, size);
	}
	for (i = 0; i < tmp; ++i)
		printf("%5d", arr[i]);
	printf("\n");

}

void test_Heap()
{
	//面向对象
	int arr[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	Heap<int, Less<int>> hp(arr, sizeof(arr) / sizeof(arr[0]));
	hp.Push(20);
	hp.Pop();

	//面向过程
	int i;
	srand(time(NULL));
	//1.在n个数里面找最大的k个数（n远大于k）(nlogk)//建小堆
	int arr2[100];
	for (i = 0; i < 100; ++i)
		arr2[i] = rand() % 1000;
	arr2[11] = 1001; arr2[26] = 1002; arr2[34] = 1003; arr2[45] = 1004; arr2[51] = 1005;
	arr2[69] = 1006; arr2[77] = 1007; arr2[87] = 1008; arr2[91] = 1009;
	Find_k_num(arr2, 10, 100);

	//2.用堆排序排升序（建大堆nlogn）数据从小到大
	int arr3[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	HeapSort_Ascend(arr3, 10);

	//3.用堆排序排降序（建小堆nlogn）数据从大到小
	int arr4[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	HeapSort_Descend(arr4, 10);
}



void test_Heap2()
{
	int arr[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	Heap<int, Less<int>> hp1(arr, sizeof(arr) / sizeof(arr[0]));
	hp1.Print();
	hp1.Heap_Sort();
	hp1.Print();

	cout << endl;
	//int arr[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	Heap<int, Great<int>> hp;
	hp.Push(10);
	hp.Push(16);
	hp.Push(18);
	hp.Push(12);
	hp.Push(11);
	hp.Push(13);
	hp.Push(15);
	hp.Push(17);
	hp.Push(14);
	hp.Push(19);
	hp.Print();

	hp.Heap_Sort();
	hp.Print();
}

int main()
{
	//test_Heap();
	//test_Heap2();
	test_prio_queue();
	system("pause");
	return 0;
}