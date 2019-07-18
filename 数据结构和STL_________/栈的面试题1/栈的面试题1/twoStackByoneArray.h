#pragma once

//一个数组实现两个栈
#include<assert.h>

template<class T>
class twostack
{
public:
	twostack()
		:_array(NULL), _capacity(0),_top1(NULL), _top2(NULL)
	{}

	bool empty1()
	{
		if (top1 == _arrray)
			return true;
		else
			return false;
	}
	void push1(const T&x)
	{
		CheckCapacity();
		*_top1++ = x;
	}
	void pop1()
	{
		assert(!empty1());
		_top1--;
	}
	size_t size1()
	{
		return _top1 - _array;
	}
	T &top1()
	{
		return *(_top1 - 1);
	}

	bool empty2()
	{
		if (_top2 == _array + _capacity)
			return true;
		else
			return false;
	}
	void push2(const T&x)
	{
		CheckCapacity();
		*(--_top2) = x;
	}
	void pop2()
	{
		assert(!empty2());
		_top2++;
	}
	size_t size2()
	{
		return _array + _capacity - _top2;
	}
	T &top2()
	{
		return *_top2;
	}


private:
	void CheckCapacity()
	{
		if (_top1 - _top2 >= 0)
		{
			size_t size1 = _top1 - _array;                 //求偏移量
			size_t size2 = _array + _capacity - _top2;
			size_t old_capacity = _capacity;

			_capacity = _capacity > 0 ? _capacity * 2 : 3;  //扩容空间大小
			T* new_array = new int[_capacity];


			for (size_t i = 0; i < size1; ++i)            //数据转移
				new_array[i] = _array[i];
			for (size_t i = 1; i <= size2; ++i)
				new_array[_capacity - i] = _array[old_capacity - i];

			delete[] _array;                          //释放旧空间

			_array = new_array;                       //指向新空间
			_top1 = _array + size1;
			_top2 = _array + _capacity - size2;

		}
	}

private:
	T *_array;
	size_t _capacity;
	T *_top1;
	T *_top2;
};

void testtwostack()
{
	twostack<int> t;

	t.push1(1);
	t.push1(2);
	t.push1(3);
	t.push1(4);
	cout << t.top1() << endl;
	cout << t.size1() << endl;


	t.push2(11);
	t.push2(12);
	t.push2(13);
	t.push2(14);
	cout << t.top2() << endl;
	cout << t.size2() << endl;

}