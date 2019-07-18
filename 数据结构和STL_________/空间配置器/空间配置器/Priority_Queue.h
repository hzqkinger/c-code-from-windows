#pragma once

//大堆：每个双亲结点逗比子结点大；   小堆：每个双亲结点都比子结点小
template<class T>struct Less //仿函数
{
	bool operator()(const T&l, const T&r)
	{
		return l < r;
	}
};
template<class T>struct Great //仿函数
{
	bool operator()(const T&l, const T&r)
	{
		return l > r;
	}
};

template<class T, class con = My_vector<T>,class compare = Less<T>>//传一个compare的自定义类型
class Heap
{
public:
	//1.构造函数和拷贝构造函数
	//2.(empty(),size(),top(),push(),pop(),swap())
	Heap(){}
	Heap(T *arr, size_t size)//传数组及它的大小
	{
		int i;
		for (i = 0; i < size; ++i)
			_a.push_back(arr[i]);

		for (i = (size - 1) / 2; i >= 0; --i)
			Adjustdown(i);
	}

	bool Empty()
	{
		return _a.Empty();
	}
	T&Top()
	{
		return _a.Front();
	}
	size_t Size()
	{
		return _a.Size();
	}
	void Push(const T&x)
	{
		_a.PushBack(x);
		Adjustup(_a.Size() - 1);
	}

	void Pop()//这里是删除优先级最高的数（即删除堆顶的数）
	{
		swap(_a[0], _a[_a.Size() - 1]);
		_a.PopBack();
		Adjustdown(0);
	}

	void Heap_Sort()
	{
		My_vector<T> tmp;
		while (!_a.Empty())
		{
			tmp.PushBack(_a[0]);
			Pop();
		}
		for (size_t i = 0; i < tmp.Size(); ++i)
			_a.PushBack(tmp[i]);
	}
	void Print()
	{
		for (size_t i = 0; i < _a.Size(); ++i)
			cout << _a[i] << " ";
		cout << endl;
	}
protected:
	void Adjustdown(int parent)
	{
		compare com;
		int child = parent * 2 + 1;

		while (child < _a.Size())
		{
			if (child + 1 < _a.Size() && com(_a[child], _a[child + 1])/*_a[child + 1] > _a[child]*/)//建大堆的比较
				++child;
			if (com(_a[child], _a[parent])==false/*_a[child] > _a[parent]*/)//建大堆的比较
			{
				swap(_a[parent], _a[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}
	void Adjustup(int child)
	{
		compare com;
		int parent = (child - 1) / 2;
		while (child != 0)
		{
			if (com(_a[child], _a[parent])==false/*_a[child] > _a[parent]*/)//建大堆的比较
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
private:
	con _a;
};
void test_priority_queue()
{
	Heap<int> pq;
	cout << pq.Empty() << " " << pq.Size() << " " << endl;
	pq.Push(5);
	pq.Push(7);
	pq.Push(4);
	pq.Push(3);
	pq.Push(8);
	pq.Push(1);
	pq.Print();
	cout << pq.Top() << endl;
	pq.Pop();
	cout << pq.Top() << endl;
	pq.Pop();
	cout << pq.Top() << endl;
	pq.Pop();
}
void test_priority_queue2()
{
	Heap<string> pq;
	cout << pq.Empty() << " " << pq.Size() << " " << endl;
	pq.Push("55");
	pq.Push("77");
	pq.Push("44");
	pq.Push("33");
	pq.Push("44");
	pq.Push("11");
	pq.Print();
	cout << pq.Top() << endl;
	pq.Pop();
	cout << pq.Top() << endl;
	pq.Pop();
	cout << pq.Top() << endl;
	pq.Pop();
}
