#pragma once

template<class T>
class My_vector
{
	T *_start;
	T *_finish;
	T *_end;
public:
	typedef T* Iterator;
	typedef const T* const_Iterator;

	My_vector()
		:_start(0), _finish(0), _end(0)
	{}
	//拷贝构造函数+赋值运算符重载函数

	//My_vector的迭代器的begin和end
	Iterator Begin()
	{
		return _start;
	}
	const_Iterator Begin()const
	{
		return _start;
	}
	Iterator End()
	{
		return _finish;
	}
	const_Iterator End()const
	{
		return _finish;
	}

	T&operator[](size_t size)//让My_vector的对象像数组一样
	{
		return _start[size];
	}

	T&operator[](size_t size)const//让My_vector的对象像数组一样
	{
		return _start[size];
	}

	size_t Size()const
	{
		return _finish - _start;
	}
	size_t Capacity()const
	{
		return _end - _start;
	}

	void Resize(size_t n,const T& x = T())//Change size 
	{
		Reserve(n);//这步保证了n一定小于Capacity()
		if (n<_finish - _start)
		{
			_finish = _start + n;
		}
		else
		{
			while (_finish < _start + n)
			{
				*_finish++ = x;
			}
		}
	}
	void Reserve(size_t n)//空间只会增大不会缩小,Request a change in capacity
	{
		if (n>Capacity())
		{
			Expand(n);
		}
	}

	void Expand(size_t n)//直接开n个空间
	{
		T *newstart = new T[n];
		size_t size = Size();//这里最好用size记录一下之前存数据个数，因为Size()是一直在变化的
		for (size_t i = 0; i < size; ++i)//保证拷贝一定正确（深浅拷贝问题）
		{
			newstart[i] = _start[i];
		}
		delete[] _start;
		_start = newstart;
		_finish = _start + size;
		_end = _start + n;
	}

	void Expand()
	{
		size_t size = Size();
		size_t capacity = Capacity();
		if (_finish == _end)
		{
			capacity = capacity > 0 ? capacity * 2 : 3;
			T *newstart = new T[capacity];
			for (size_t i = 0; i < size; ++i)
			{
				newstart[i] = _start[i];
			}
			_start = newstart;
			_finish = _start + size;
			_end = _start + capacity;
		}
	}
	//增删查改
	void PushBack(const T& x)
	{
		//if (_finish == _end)
		//{
		//	size_t capacity = Capacity();
		//	capacity = capacity > 0 ? capacity * 2 : 3;
		//	Expand(capacity);
		//}
		//*_finish = x;
		//++_finish;
		Insert(_finish, x);
	}
	void PopBack()
	{
		assert(_start == _finish);
		--_finish;
	}

	void Insert(Iterator pos, const T& x)//需要解决迭代器失效的问题
	{
		assert(pos >= _start && pos <= _finish);
		if (_finish == _end)//假如要增容，那么迭代器会失效
		{
			size_t off = pos - _start;//求pos在原来数组中的偏移量
			size_t capacity = Capacity();
			capacity = capacity > 0 ? capacity * 2 : 3;
			Expand(capacity);
			pos = _start + off;//更新迭代器
		}

		Iterator pos1 = _finish++;
		while (pos1 != pos)
		{
			*pos1 = *(pos1 - 1);
			pos1--;
		}
		*pos = x;
	}
	Iterator Erase(Iterator pos)//返回一个指向下一个元素的迭代器指针
	{
		assert(pos >= _start && pos < _finish);
		--_finish;
		Iterator pos1 = pos;
		while (pos1 != _finish)
		{
			*pos1 = *(pos1 + 1);
			pos1++;
		}
		return pos;
	}
};


template<class T>
void Printlist(const My_vector<T>& v)
{
	My_vector<T>::const_Iterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void testlist()
{
	//My_vector<int> v;
	//v.PushBack(1);
	//v.PushBack(2);
	//v.PushBack(6);
	//v.PushBack(4);
	//v.PushBack(5);
	//Printlist(v);

	//My_vector<int>::Iterator it = v.Begin();
	//v.Erase(it);

	//Printlist(v);
	//cout << *it <<endl;

	My_vector<string> v2;
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	Printlist(v2);


}