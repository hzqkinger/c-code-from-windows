#pragma once

//1. 插入排序
//1.1 直接插入排序
void Insert_Sort(int *a, size_t n)
{
	for (size_t i = 1; i < n; ++i)
	{
		int tmp = a[i],end = i - 1;

		while (end >= 0 && a[end] > tmp)
			a[end + 1] = a[end--];
		a[end + 1] = tmp;
	}
}
//1.2 希尔排序
void ShellSort(int* array, int size)
{
	// size=2
	int gap = size;  //gap=9  2
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t idx = gap; idx < size; ++idx)
		{
			int end = idx - gap;
			int key = array[idx];

			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}

			array[end + gap] = key;
		}
	}
}

//2. 选择排序
//2.1 直接选择排序
void Select_Sort(int *a, size_t n)
{
	size_t left = 0, right = n - 1;

	while (left < right)
	{
		size_t min = left, max = right;
		for (size_t i = left; i <= right; ++i)//[left,right]
		{
			if (a[min] > a[i])min = i;
			if (a[max] < a[i])max = i;

			swap(a[left], a[min]);

			if (max == left)max = min;//由于上面的交换操作，max的位置可能改变
			swap(a[right], a[max]);
		}
		++left; --right;
	}
}
//2.2 堆排序
void AdjustDown(int*a, size_t n,size_t i)
{
	size_t parent = i;
	while (parent * 2 + 1 < n)
	{
		size_t child = parent * 2 + 1;//左孩子
		if (child + 1 < n && a[child + 1] > a[child])++child;//如果右孩子存在且比左孩子大

		if (a[parent] < a[child])//大根堆
			swap(a[parent], a[child]);

		parent = child;
	}

}
void Head_Sort(int *a, size_t n)
{
	//堆排序还可以可以解决topK问题

	for (int i = (n - 1) / 2; i >= 0; --i)
		AdjustDown(a, n, i);//大根堆的向下调整算法

	int end = n - 1;
	while (end > 0)//当只剩下最后一个元素时不用交换，即end==0时.
	{
		swap(a[0], a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

}

//3. 交换排序
//3.1 冒泡排序
void Bubble_sort(int *a, size_t n)
{
	int end = n;
	while (end > 0)
	{
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
				swap(a[i - 1], a[i]);
		}
		--end;
	}

}
//3.2 快速排序
int PartSort1(int *a, int begin, int end)//[begin,end]
{//该函数的意义是：在数组中选取一个关键值，将小于关键值的放在它左边，否则放在它右边
	int key = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= a[key])//找到大于key的值
			++begin;
		while (begin < end && a[end] >= a[key])//找到小于key的值
			--end;

		swap(a[begin], a[end]);
	}
	swap(a[begin], a[key]);
	return begin;
}
int PartSort2(int *a, int begin, int end)
{
	int key = a[end];//先假定坑在最末尾
	while (begin < end)//坑始终在begin或end的位置
	{
		while (begin < end && a[begin] <= key)//找到大于key的值
			++begin;
		a[end] = a[begin];//坑到begin的位置上
		while (begin < end && a[end] >= key)//找到小于key的值
			--end;
		a[begin] = a[end];//坑到end的位置上
	}
	a[begin] = key;
	return begin;
}
int PartSort3(int *a, int begin, int end)
{
	int prev = begin - 1, cur = begin;
	int key = a[end];
	while (cur < end)
	{
		if (a[cur] < key && ++prev != cur)
			swap(a[prev], a[cur]);

			++cur;
	}
	swap(a[++prev], a[end]);
	return prev;
}
void Quick_sort(int *a, int left, int right)//[left,right]
{
	if (!a || left >= right)return;
	//单趟快速排序的三种方法：
	//int mid = PartSort1(a, left, right);//1.左右指针法
	//int mid = PartSort2(a, left, right);//2.挖坑法
	int mid = PartSort3(a, left, right);//3.前后指针法

	Quick_sort(a, left, mid - 1);
	Quick_sort(a, mid + 1, right);
}
#include<stack>
void Quick_sortNonR(int *a, int left, int right)//[left,right]
{
	stack<int> sta;
	if (left < right)
	{
		sta.push(left); sta.push(right);
	}
	while (!sta.empty())
	{
		int end = sta.top(); sta.pop();
		int begin = sta.top(); sta.pop();
		int mid = PartSort1(a, begin, end);//可以优化一下

		if (begin < mid - 1)
		{
			sta.push(begin); sta.push(mid - 1);
		}
		if (mid + 1 < end)
		{
			sta.push(mid + 1); sta.push(end);
		}
	}
}
//4. 归并排序
void _MergeSort(int *a, int left, int right,int *tmp)//ps:注意闭区间还是开区间
{
	if (left >= right)return;

	int mid = left + (right - left >> 1);
	_MergeSort(a, left, mid, tmp);//归并左边，使左边有序
	_MergeSort(a, mid + 1, right, tmp);//归并右边，使右边有序
	//现在左右两边的小区间都有序了，开始归并成一个大的有序区间
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;

	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)//[begin1,end1]
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)//[begin2,end2]
		tmp[index++] = a[begin2++];

	index = left;
	while (index <= right)//[left,right]
	{
		a[index] = tmp[index];
		++index;
	}
}
void MergeSort(int *a, int left, int right)
{
	int *tmp = new int[right - left + 1];
	_MergeSort(a, left, right, tmp);
	delete[] tmp;
}


void test_Sort()
{
	int a[] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 5 };
	size_t n = sizeof(a) / sizeof(a[0]);

	//Insert_Sort(a, n);//直接插入排序
	//Select_Sort(a, n);//直接选择排序
	//Head_Sort(a, n);//堆排序
	//Bubble_sort(a, n);//冒泡排序
	//Quick_sort(a, 0, n - 1);//递归法快速排序
	//Quick_sortNonR(a, 0, n - 1);//非递归法快速排序
	MergeSort(a, 0, n - 1);//归并排序

	for (size_t i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}