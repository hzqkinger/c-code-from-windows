#pragma once

//1. ��������
//1.1 ֱ�Ӳ�������
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
//1.2 ϣ������
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

//2. ѡ������
//2.1 ֱ��ѡ������
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

			if (max == left)max = min;//��������Ľ���������max��λ�ÿ��ܸı�
			swap(a[right], a[max]);
		}
		++left; --right;
	}
}
//2.2 ������
void AdjustDown(int*a, size_t n,size_t i)
{
	size_t parent = i;
	while (parent * 2 + 1 < n)
	{
		size_t child = parent * 2 + 1;//����
		if (child + 1 < n && a[child + 1] > a[child])++child;//����Һ��Ӵ����ұ����Ӵ�

		if (a[parent] < a[child])//�����
			swap(a[parent], a[child]);

		parent = child;
	}

}
void Head_Sort(int *a, size_t n)
{
	//�����򻹿��Կ��Խ��topK����

	for (int i = (n - 1) / 2; i >= 0; --i)
		AdjustDown(a, n, i);//����ѵ����µ����㷨

	int end = n - 1;
	while (end > 0)//��ֻʣ�����һ��Ԫ��ʱ���ý�������end==0ʱ.
	{
		swap(a[0], a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

}

//3. ��������
//3.1 ð������
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
//3.2 ��������
int PartSort1(int *a, int begin, int end)//[begin,end]
{//�ú����������ǣ���������ѡȡһ���ؼ�ֵ����С�ڹؼ�ֵ�ķ�������ߣ�����������ұ�
	int key = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= a[key])//�ҵ�����key��ֵ
			++begin;
		while (begin < end && a[end] >= a[key])//�ҵ�С��key��ֵ
			--end;

		swap(a[begin], a[end]);
	}
	swap(a[begin], a[key]);
	return begin;
}
int PartSort2(int *a, int begin, int end)
{
	int key = a[end];//�ȼٶ�������ĩβ
	while (begin < end)//��ʼ����begin��end��λ��
	{
		while (begin < end && a[begin] <= key)//�ҵ�����key��ֵ
			++begin;
		a[end] = a[begin];//�ӵ�begin��λ����
		while (begin < end && a[end] >= key)//�ҵ�С��key��ֵ
			--end;
		a[begin] = a[end];//�ӵ�end��λ����
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
	//���˿�����������ַ�����
	//int mid = PartSort1(a, left, right);//1.����ָ�뷨
	//int mid = PartSort2(a, left, right);//2.�ڿӷ�
	int mid = PartSort3(a, left, right);//3.ǰ��ָ�뷨

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
		int mid = PartSort1(a, begin, end);//�����Ż�һ��

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
//4. �鲢����
void _MergeSort(int *a, int left, int right,int *tmp)//ps:ע������仹�ǿ�����
{
	if (left >= right)return;

	int mid = left + (right - left >> 1);
	_MergeSort(a, left, mid, tmp);//�鲢��ߣ�ʹ�������
	_MergeSort(a, mid + 1, right, tmp);//�鲢�ұߣ�ʹ�ұ�����
	//�����������ߵ�С���䶼�����ˣ���ʼ�鲢��һ�������������
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

	//Insert_Sort(a, n);//ֱ�Ӳ�������
	//Select_Sort(a, n);//ֱ��ѡ������
	//Head_Sort(a, n);//������
	//Bubble_sort(a, n);//ð������
	//Quick_sort(a, 0, n - 1);//�ݹ鷨��������
	//Quick_sortNonR(a, 0, n - 1);//�ǵݹ鷨��������
	MergeSort(a, 0, n - 1);//�鲢����

	for (size_t i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}