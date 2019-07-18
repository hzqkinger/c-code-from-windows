#pragma once
#pragma once
#include <iostream>
using namespace std;
#include <stack>
#include <math.h>


void Print(int* array, int size)
{
	for (size_t idx = 0; idx < size; ++idx)
	{
		cout << array[idx] << " ";
	}

	cout << endl;
}

// ʱ�临�Ӷ�-->O(N)
// �ռ临�Ӷ�-->O(1)
// �ȶ���--> �ȶ���
void InsertSort(int* array, int size)
{
	for (size_t idx = 1; idx < size; ++idx)
	{
		int end = idx - 1;
		int key = array[idx];

		while (end >= 0 && array[end] > key)
		{
			array[end + 1] = array[end];
			end--;
		}

		array[end + 1] = key;
	}
}

void InsertSort_OP(int* array, int size)//Binary_insert_sort
{
	for (size_t idx = 1; idx < size; ++idx)
	{
		int end = idx - 1;
		int key = array[idx];

		int left = 0;
		int right = end;
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (key >= array[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}

		while (end >= left)
		{
			array[end + 1] = array[end];
			end--;
		}

		array[left] = key;
	}
}

// ʱ�临�Ӷ�-->O(N)
// �ռ临�Ӷ�-->O(1) 
// �ȶ���--> �ȶ���---> ��С��������
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

// O
void SelectSort(int* array, size_t size)//һ��ѡһ��Ԫ��
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		size_t maxPos = 0;
		// �����Ԫ��
		for (size_t j = 0; j < size - i; j++)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}

		if (maxPos != size - i - 1)
			std::swap(array[maxPos], array[size - i - 1]);
	}
}

void SelectSort_OP(int* array, size_t size)//һ��ѡ����Ԫ��
{
	size_t begin = 0;
	size_t end = size - 1;
	while (begin < end)
	{
		size_t maxPos = begin;
		size_t minPos = begin;
		// �����Ԫ��
		for (size_t j = begin + 1; j <= end; j++)
		{
			if (array[j] > array[maxPos])
				maxPos = j;

			if (array[j] < array[minPos])
				minPos = j;
		}


		// ˼��--��
		// 		if(minPos != begin)
		// 			std::swap(array[minPos], array[begin]);
		// 
		// 		if(maxPos == begin)
		// 			maxPos = minPos;
		// 
		// 		if(maxPos != end)
		// 			std::swap(array[maxPos], array[end]);

		if (maxPos != end)
			std::swap(array[maxPos], array[end]);

		if (minPos == end)
			minPos = maxPos;

		if (minPos != begin)
			std::swap(array[minPos], array[begin]);

		begin++;
		end--;
	}
}


void HeadAdjust(int* array, int root, int size)//���µ����㷨
{
	int child = root * 2 + 1;
	int parent = root;

	while (child < size)
	{
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		if (array[child] > array[parent])
		{
			std::swap(array[child], array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void HeadSort(int* array, int size)
{
	// ����
	for (int idx = (size - 2) / 2; idx >= 0; idx--)
		HeadAdjust(array, idx, size);

	// ����
	int end = size - 1;
	while (end > 0)
	{
		std::swap(array[0], array[end]);
		HeadAdjust(array, 0, end);
		end--;
	}
}

size_t GetMidIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right])
			return right;
		else
			return mid;
	}
	else
	{
		//  right < left < mid
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right])// mid < right < left
			return right;
		else
			return mid;
	}
}

//Horn
int Partion1(int* array, int left, int right)
{
	// ����ȡ�з�
	size_t mid = GetMidIndex(array, left, right);
	if (mid != right)
		std::swap(array[mid], array[right]);

	int key = array[right];
	int begin = left;
	int end = right;

	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;

		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
			std::swap(array[begin], array[end]);
	}

	if (begin != right)
		std::swap(array[begin], array[right]);

	return begin;
}

// �ڿӷ�
int Partion2(int* array, int left, int right)
{
	size_t mid = GetMidIndex(array, left, right);
	if (mid != right)
		std::swap(array[mid], array[right]);

	int key = array[right];
	int begin = left;
	int end = right;

	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;

		if (begin < end)
			array[end--] = array[begin];

		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
			array[begin++] = array[end];
	}

	array[begin] = key;

	return begin;
}

// ǰ��ָ��
int Partion3(int* array, int left, int right)
{
	size_t mid = GetMidIndex(array, left, right);
	if (mid != right)
		std::swap(array[mid], array[right]);

	int key = array[right];
	int cur = left;
	int prev = cur - 1;

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			std::swap(array[cur], array[prev]);

		cur++;
	}

	std::swap(array[cur], array[++prev]);

	return prev;
}

void QuickSort(int* array, int left, int right)//�ݹ��������
{
	if (right - left < 3)
	{
		InsertSort(array + left, right - left + 1);
	}
	else
	{
		int div = Partion3(array, left, right);
		QuickSort(array, left, div - 1);
		QuickSort(array, div + 1, right);
	}
}

void QuickSort(int *array, int size)//�ǵݹ��������
{
	stack<int> s;
	s.push(0);
	s.push(size - 1);

	while (!s.empty())
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();

		if (left < right)
		{
			int mid = Partion3(array, left, right);

			// �Ұ벿��
			s.push(mid + 1);
			s.push(right);

			// ��벿��
			s.push(left);
			s.push(mid - 1);
		}
	}
}


void Merge(int* array, int left, int mid, int right, int* temp)
{
	int index1 = left;
	int right1 = mid;

	int index2 = mid + 1;
	int right2 = right;
	int index = left;

	while (index1 <= right1 && index2 <= right2)
	{
		if (array[index1] <= array[index2])
			temp[index++] = array[index1++];
		else
			temp[index++] = array[index2++];
	}

	// memcpy-->ǳ����
	while (index1 <= right1)
		temp[index++] = array[index1++];

	while (index2 <= right2)
		temp[index++] = array[index2++];
}

// ѭ��
void _MergeSort(int* array, int left, int right, int* temp)
{
	if (right - left < 16)
	{
		InsertSort(array, right - left + 1);
	}
	else
	{
		int mid = left + ((right - left) >> 1);
		// ��벿��
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid + 1, right, temp);
		Merge(array, left, mid, right, temp);
		memcpy(array + left, temp + left, (right - left + 1)*sizeof(array[0]));
	}
}
void MergeSort(int* array, int size)
{
	int* temp = new int[size];
	_MergeSort(array, 0, size - 1, temp);
	delete[] temp;
}

void MergeSortNor(int *array, int size)
{
	int gap = 1;
	int* temp = new int[size];
	while (gap < size)
	{
		for (size_t idx = 0; idx < size; idx += 2 * gap)
		{
			// ������
			int left = idx;// left = 0
			int mid = left + gap - 1;
			int right = mid + gap;

			if (mid >= size)
				mid = size - 1;

			if (right >= size)
				right = size - 1;

			Merge(array, left, mid, right, temp);
		}

		memcpy(array, temp, size*sizeof(array[0]));
		gap *= 2;
	}

	delete[] temp;
}

// O(N)--->O(M)
// ��������
void CountSort(int* array, int size)
{
	// �����ռ�
	int maxValue = array[0];
	int minValue = array[0];
	for (size_t idx = 0; idx < size; ++idx)
	{
		if (array[idx] > maxValue)
			maxValue = array[idx];

		if (array[idx] < minValue)
			minValue = array[idx];
	}

	int range = maxValue - minValue + 1;
	int* temp = new int[range];
	memset(temp, 0, range*sizeof(array[0]));

	// ���·���
	// 1001  1000
	for (size_t idx = 0; idx < size; ++idx)
	{
		temp[array[idx] - minValue]++;
	}

	// ����
	size_t index = 0;
	for (size_t idx = 0; idx < range; ++idx)
	{
		while (temp[idx])
		{
			array[index++] = minValue + idx;
			--temp[idx];
		}
	}

	delete[] temp;
}

size_t GetMaxBit(int* array, int size)
{
	size_t radix = 10;
	size_t count = 1;
	for (size_t idx = 0; idx < size; ++idx)
	{
		while (array[idx] >= radix)
		{
			count++;
			radix *= 10;
		}
	}

	return count;
}

// ʱ�䣺O(MN)
// �ռ临�Ӷȣ�O(N)
void RadixSortLSD(int* array, int size)
{
	int* temp = new int[size];
	int maxBit = GetMaxBit(array, size);
	int radix = 1;
	for (size_t idx = 1; idx <= maxBit; ++idx)
	{
		// ͳ��ÿ��Ͱ��Ԫ�صĸ���
		int count[10] = { 0 };
		for (size_t idx = 0; idx < size; ++idx)
			count[array[idx] / radix % 10]++;

		// ����ÿ��Ͱ����ʼ��ַ
		int startAddr[10] = { 0 };
		for (size_t idx = 1; idx < 10; ++idx)
			startAddr[idx] = startAddr[idx - 1] + count[idx - 1];

		// ��������
		for (size_t idx = 0; idx < size; ++idx)
		{
			int bucketNo = array[idx] / radix % 10;
			temp[startAddr[bucketNo]] = array[idx];
			startAddr[bucketNo]++;
		}

		memcpy(array, temp, size*sizeof(array[0]));
		radix *= 10;
	}

	delete[] temp;
}

// ʱ�临�Ӷȣ�O(MN)
// �ռ临�Ӷ�: O(M) + O(N)
void _RadixSortMSD(int* array, int left, int right, int maxBit, int* temp)
{
	if (maxBit < 0)
		return;

	size_t size = right - left;
	int radix = (int)pow((double)10, maxBit);

	// ͳ��ÿ��Ͱ��Ԫ�صĸ���
	int count[10] = { 0 };
	for (size_t idx = left; idx < right; ++idx)
		count[array[idx] / radix % 10]++;

	// ����ÿ��Ͱ����ʼ��ַ
	int startAddr[10] = { 0/*left*/ };
	//startAddr[0] = left;
	for (size_t idx = 1; idx < 10; ++idx)
		startAddr[idx] = startAddr[idx - 1] + count[idx - 1];

	// ��������
	for (size_t idx = left; idx < right; ++idx)
	{
		int bucketNo = array[idx] / radix % 10;
		temp[left + startAddr[bucketNo]] = array[idx];
		startAddr[bucketNo]++;
	}

	memcpy(array + left, temp + left, size*sizeof(array[0]));

	// ʮ��Ͱ
	for (size_t idx = 0; idx < 10; ++idx)
	{
		if (count[idx] <= 1)
			continue;

		int begin = left + startAddr[idx] - count[idx];
		int end = begin + count[idx];
		_RadixSortMSD(array, begin, end, maxBit - 1, temp);
	}
}

void RadixSortMSD(int* array, int size)
{
	int* temp = new int[size];
	int maxBit = GetMaxBit(array, size);
	_RadixSortMSD(array, 0, size, maxBit - 1, temp);
	delete[] temp;
}


void TestInsertSort()
{
	//int array[] = {2, 1, 4, 9, 3, 6, 8, 7, 0, 5};
	//int array[] = {2, 1, 4, 9, 6, 2, 3, 6, 8, 5, 7, 0, 5};
	int array[] = { 198, 254, 378, 852, 761, 554, 581, 552, 605, 479, 853, 846, 980, 988, 931, 923 };
	Print(array, sizeof(array) / sizeof(array[0]));
	//InsertSort(array, sizeof(array)/sizeof(array[0]));
	//InsertSort_OP(array, sizeof(array)/sizeof(array[0]));
	//ShellSort(array, sizeof(array)/sizeof(array[0]));
	//SelectSort_OP(array, sizeof(array)/sizeof(array[0]));
	//HeadSort(array, sizeof(array)/sizeof(array[0]));

	//QuickSort(array, 0, sizeof(array)/sizeof(array[0])-1);//�ݹ�д��
	//QuickSort(array,sizeof(array)/sizeof(array[0]));//�ǵݹ�д��

	//MergeSort(array,sizeof(array)/sizeof(array[0]));
	//MergeSortNor(array,sizeof(array)/sizeof(array[0]));
	//CountSort(array,sizeof(array)/sizeof(array[0]));
	//RadixSortLSD(array,sizeof(array)/sizeof(array[0]));
	//RadixSortLSD(array,sizeof(array)/sizeof(array[0]));
	RadixSortMSD(array, sizeof(array) / sizeof(array[0]));
	Print(array, sizeof(array) / sizeof(array[0]));
}