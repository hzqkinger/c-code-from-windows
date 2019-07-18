#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<CoreWindow.h>
#define N 100
typedef int DataType;

typedef struct SeqList
{
	DataType array[N]; // 数组
	size_t size;       // 有效数据的个数
}SeqList;

void InitSeqList(SeqList* s);
void print(SeqList* s);

void PushBack(SeqList* s, DataType x);
void PopBack(SeqList* s);
void PushFront(SeqList* s, DataType x);
void PopFront(SeqList* s);

void Insert(SeqList* s, size_t pos, DataType x);
void Erase(SeqList* s, size_t pos);

int Find(SeqList* s, DataType x);
void Modify(SeqList* s, size_t pos, DataType x);
int Remove(SeqList* s, DataType x);
int RemoveAll(SeqList* s, DataType x);

void BubbleSort(SeqList* s);
void SelectSort(SeqList* s);
void SelectSort_OP(SeqList* s);
int BinarySearch(SeqList* s, DataType x);



void print(SeqList* s)
{
	int i = 0;
	for (i = 0; i < s->size; i++)
	{
		printf("%3d", s->array[i]);
	}
	printf("\n");
}
void InitSeqList(SeqList* s)
{
	memset(s->array, 0, N*sizeof(DataType));
	s->size = 0;
}
void PushBack(SeqList* s, DataType x)
{
	assert(s->size <= N);
	s->array[s->size] = x;
	s->size++;
}
void PopBack(SeqList* s)
{
	assert(s);
	s->size--;
}
void PushFront(SeqList* s, DataType x)
{
	int tmp = s->size;
	assert(s->size <= N);
	while (tmp)
	{
		s->array[tmp] = s->array[tmp - 1];
		tmp--;
	}
	s->array[tmp] = x;
	s->size++;
}
void PopFront(SeqList* s)
{
	int i = 0;
	assert(s);
	for (i = 0; i < s->size - 1; i++)
		s->array[i] = s->array[i + 1];
	s->size--;
}
void Insert(SeqList* s, size_t pos, DataType x)
{
	int tmp = s->size;
	assert(s->size <= N);
	while (tmp>=pos)
	{
		s->array[tmp] = s->array[tmp - 1];
		tmp--;
	}
	s->array[tmp] = x;
	s->size++;
}
void Erase(SeqList* s, size_t pos)
{
	int i = 0;
	assert(s);
	for (i = pos-1; i < s->size - 1; i++)
		s->array[i] = s->array[i + 1];
	s->size--;
}
int Find(SeqList* s, DataType x)
{
	int i = 0;
	for (; i < s->size; i++)
	{
		if (s->array[i] == x)
			return i;
	}
	if (i == s->size)
		return -1;
}
void Modify(SeqList* s, size_t pos, DataType x)
{
	assert(pos < s->size);
	s->array[pos-1] = x;
}
int Remove(SeqList* s, DataType x)
{
	int i = 0;
	assert(s);
	for (; i < s->size; i++)
	{
		if (s->array[i] == x)
			break;
	}
	while (i < s->size-1)
	{
		s->array[i] = s->array[i + 1];
		i++;
	}
	s->size--;
}
int RemoveAll(SeqList* s, DataType x)
{
	int i = 0, j = 0;
	for (; j < s->size; j++)
	{
		if (s->array[j] != x)
			s->array[i++] = s->array[j];
	}
	s->size = i;
}
void BubbleSort(SeqList* s)
{
	int i = 0, j = 0,k = 0;
	DataType tmp;
	for (; i < s->size - 1; i++)
	{
		k = 0;
		for (; j < s->size - i - 1; j++)
		{
			if (s->array[j]>s->array[j + 1])
			{
				tmp = s->array[j];
				s->array[j] = s->array[j + 1];
				s->array[j + 1] = tmp;
				k = 1;
			}
		}
		if (k == 0)
			break;
	}
}
void SelectSort(SeqList* s)
{
	int i = 0, j = 0,min = 0;
	DataType tmp;
	for (; i < s->size-1; i++)
	{
		min = i;
		for (j = i + 1; j < s->size; j++)
		{
			if (s->array[min] > s->array[j])
				min = j;
		}
		tmp = s->array[i];
		s->array[i] = s->array[min];
		s->array[min] = tmp;
	}
}
void SelectSort_OP(SeqList* s)
{
	int i = 0, j = 0, min = 0,max=0;
	int tmp1 = s->size;
	DataType tmp;
	for (; i < tmp1 - 1; i++)
	{
		min = i,max =i;
		for (j = i + 1; j < tmp1; j++)
		{
			if (s->array[min] > s->array[j])
				min = j;
			if (s->array[max] < s->array[j])
				max = j;
		}
		tmp = s->array[i],s->array[i] = s->array[min],s->array[min] = tmp;
		if (max == i)max = min;
		tmp = s->array[tmp1-1], s->array[tmp1-1] = s->array[max], s->array[max] = tmp;
		tmp1--;
	}
}
int BinarySearch(SeqList* s, DataType x)
{
	int begin = 0, end = s->size,mid = 0;
	assert(s);
	while (begin < end)
	{
		mid = begin + (end - begin) / 2;
		if (s->array[mid] < x)
			begin = mid + 1;
		else if (s->array[mid] > x)
			end = mid;
		else
			return mid;
	}
	if (begin >= end)
		return -1;
}
int main()
{
	SeqList s;
	int ret;
	InitSeqList(&s);
	print(&s);
	PushBack(&s, 1);
	PushBack(&s, 3);
	PushBack(&s, 2);
	PushBack(&s, 4);
	print(&s);
	PushFront(&s, 4);
	PushFront(&s, 4);
	PushFront(&s, 5);
	PopFront(&s);
	PopFront(&s);

	//PopBack(&s);
	print(&s);

	Insert(&s, 2, 7);
	print(&s);
	Erase(&s, 2);
	print(&s);

	Modify(&s, 3, 7);
	print(&s);

	Remove(&s, 4);
	print(&s);

	ret = Find(&s, 3);
	printf("所找的数是顺序表第%d个元素\n", ret);
	PushBack(&s, 5);
	RemoveAll(&s, 4);
	print(&s);
	//BubbleSort(&s);
	SelectSort_OP(&s);
	print(&s);
	printf("%d\n",BinarySearch(&s, 3));


	system("pause");
	return 0;
}
