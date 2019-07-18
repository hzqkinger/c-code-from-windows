#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<time.h>

#include"HEAP.h"
#include"test_priority_queue.h"

void Adjdown(int *arr,int i,int size)//��С��
{
	int parent = i;
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] < arr[child])//��С�ѵıȽ�
			++child;
		if (arr[child] < arr[parent])//��С�ѵıȽ�
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
		if (child + 1 < size && arr[child + 1] > arr[child])//����ѵıȽ�
			++child;
		if (arr[child] > arr[parent])//����ѵıȽ�
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void Find_k_num(int *arr, int k, int size)//k��size���������ݵĸ���
{
	int i;
	for (i = (k - 2) / 2; i >= 0; --i)//�Ƚ�ǰk�����ݽ��ɴ�ѻ���С�ѣ�������k������С�ѣ�����С��k��������ѣ�
		Adjdown(arr, i, k);

	for (i = k; i < size; ++i)
	{
		if (arr[i]>arr[0])
		{
			swap(arr[i], arr[0]);
			Adjdown(arr, 0, k);//ÿ�ζ��ǵ�0��λ����Ҫ����
		}
	}
	for (i = 0; i < k; ++i)//��ӡ�ҳ�����k����
		printf("%-5d", arr[i]);
	printf("\n");
}
void HeapSort_Descend(int *arr, int size)//��С��
{                            //size��ʾsize����
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
void HeapSort_Ascend(int *arr, int size)//�����
{                            //n��ʾn����
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
	//�������
	int arr[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	Heap<int, Less<int>> hp(arr, sizeof(arr) / sizeof(arr[0]));
	hp.Push(20);
	hp.Pop();

	//�������
	int i;
	srand(time(NULL));
	//1.��n��������������k������nԶ����k��(nlogk)//��С��
	int arr2[100];
	for (i = 0; i < 100; ++i)
		arr2[i] = rand() % 1000;
	arr2[11] = 1001; arr2[26] = 1002; arr2[34] = 1003; arr2[45] = 1004; arr2[51] = 1005;
	arr2[69] = 1006; arr2[77] = 1007; arr2[87] = 1008; arr2[91] = 1009;
	Find_k_num(arr2, 10, 100);

	//2.�ö����������򣨽����nlogn�����ݴ�С����
	int arr3[] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	HeapSort_Ascend(arr3, 10);

	//3.�ö������Ž��򣨽�С��nlogn�����ݴӴ�С
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