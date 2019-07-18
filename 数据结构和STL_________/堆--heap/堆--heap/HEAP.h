#pragma once
#include<vector>
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
template<class T,class compare>//传一个compare的自定义类型
class Heap
{
public:
	Heap(){}
	Heap(T *arr, size_t size)//传数组及它的大小
	{
		int i;
		for (i = 0; i < size; ++i)
			_a.push_back(arr[i]);

		for (i = (size - 1) / 2; i >= 0; --i)
			Adjustdown(i);
	}
	void Push(const T&x)
	{
		_a.push_back(x);
		Adjustup(_a.size() - 1);
	}
	void Pop()//这里是删除优先级最高的数（即删除堆顶的数）
	{
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		Adjustdown(0);
	}

	void Heap_Sort()
	{
		vector<T> tmp;
		while (!_a.empty())
		{
			tmp.push_back(_a[0]);
			Pop();
		}
		for (size_t i = 0; i < tmp.size(); ++i)
			_a.push_back(tmp[i]);
	}

	bool Empty()
	{
		return _a.empty();
	}
	T&Top()
	{
		return _a.top();
	}
	size_t Size()
	{
		reeturn _a.size();
	}

	void Print()
	{
		for (size_t i = 0; i < _a.size(); ++i)
			cout << _a[i] << " ";
		cout << endl;
	}
protected:
	void Adjustdown(int parent)
	{
		compare com;
		int child = parent * 2 + 1;

		while (child < _a.size())
		{
			if (child + 1 < _a.size() && com(_a[child + 1],_a[child])/*_a[child + 1] > _a[child]*/)//建大堆的比较
				++child;
			if (com(_a[child] , _a[parent])/*_a[child] > _a[parent]*/)//建大堆的比较
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
			if (com(_a[child] , _a[parent])/*_a[child] > _a[parent]*/)//建大堆的比较
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
	vector<T> _a;
};


//template<class T ,class container = Heap<T,Great<T> >//出错
//class my_prio_queue
//{
//public:
//	void Push()
//	{
//		_con.Heap_Sort();
//	}
//	void Pop()
//	{
//
//	}
//	void Print()
//	{
//		_con.Print();
//	}
//
//	bool Empty()
//	{
//		return _con.Empty();
//	}
//	T&Top()
//	{
//		return _con.Top();
//	}
//	size_t Size()
//	{
//		return _con.Size();
//	}
//private:
//	container _con;
//};
//
//void test_my_prio_queue()
//{
//	//my_prio_queue<int>//不能包含模板的参数列表
//}