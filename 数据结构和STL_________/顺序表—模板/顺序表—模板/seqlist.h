#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<string>

template<class T>
class seqlist
{
public:
	seqlist()
		:_a(NULL)//最好把_a初始化成NULL，是为了new[]和delete[]能更好的匹配起来使用
		, _size(0)
		, _capacity(0)
	{}
	//拷贝构造
	seqlist(const seqlist<T> &seq)
		:_a(new T[seq._size])
		, _size(seq._size)
		, _capacity(_size)
	{
		for (size_t i = 0; i < _size; ++i)
			_a[i] = seq._a[i];
	}
	//赋值运算符重载
	seqlist<T>& operator=(seqlist<T> seq)//复用了拷贝构造函数
	{
		if (this != &seq)//这里感觉有点问题，好像阻止不了给自己赋值
		{
			swap(_a, seq._a);
			swap(_size, seq._size);
			swap(_capacity, seq._capacity);
		}
		return *this;
	}
	//析构
	~seqlist()
	{
		if (_a)
			delete[] _a;
	}
	//增删查改
	void PushBack(T x)
	{
		//CheckCapcacity();
		//_a[_size++] = x;//如果该数据类型是自定义类型，则会自动调用该类的赋值运算符重载函数
		Insert(_size, x);
	}
	void PopBack()
	{
		//if (_size>0)//假如顺序表中元素个数是0，保证再次调用该函数无效
		//	_size--;
		Erase(_size-1);
	}
	void PushFront(T x)
	{
		//CheckCapcacity();
		////memcpy(newA, _a, sizeof(T)*_size);//如果没有深浅拷贝问题，最好用这个语句
		//for (size_t i = _size; i > 0; --i)
		//	_a[i] = _a[i - 1];//一个一个数据复制下来，如果该数据类型是自定义类型，则会自动调用该类的赋值运算符重载函数(就不需要在这里操心深浅拷贝的问题了)
		//_a[0] = x;
		//_size++;
		Insert(0, x);
	}
	void PopFront()
	{
		//if (_size > 0)//假如顺序表中元素个数是0，保证再次调用该函数无效
		//{
		//	_size--;
		//	for (size_t i = 0; i < _size; ++i)
		//		_a[i] = _a[i + 1];
		//}
		Erase(0);
	}
	void Insert(size_t pos, T x)//在pos位前面插入数据x
	{
		CheckCapcacity();
		//memcpy(newA, _a, sizeof(T)*_size);//如果没有深浅拷贝问题，最好用这个语句
		for (size_t i = _size; i > pos; --i)
			_a[i] = _a[i - 1];//一个一个数据复制下来，如果该数据类型是自定义类型，则会自动调用该类的赋值运算符重载函数(就不需要在这里操心深浅拷贝的问题了)
		_a[pos] = x;
		_size++;
	}
	void Erase(size_t pos)
	{
		if (_size > 0)
		{
			_size--;
			for (size_t i = pos; i < _size; ++i)
				_a[i] = _a[i + 1];
		}
	}
	void CheckCapcacity()
	{               //涉及到类型萃取的问题。
		if (_size >= _capacity)
		{
			_capacity = _capacity > 0 ? _capacity * 2 : 3;
			T *newA = new T [_capacity];
			if (_a)
			{
				//memcpy(newA, _a, sizeof(T)*_size);//如果没有深浅拷贝问题，最好用这个语句
				for (size_t i = 0; i < _size; ++i)
					newA[i] = _a[i];//一个一个数据复制下来，如果该数据类型是自定义类型，则会自动调用该类的赋值运算符重载函数(就不需要在这里操心深浅拷贝的问题了)
				delete[] _a;
			}
			_a = newA;
		}

	}
	T & Top()const
	{
		return _a[_size - 1];
	}
	bool Empty()
	{
		if (!_size)
			return true;
		else
			return false;
	}
	void Print()
	{
		for (size_t i = 0; i < _size; ++i)
			cout << _a[i] << " ";
		cout << endl;
	}

private:
	T *_a;
	size_t _size;
	size_t _capacity;
};

void test()
{
	seqlist<string> qlist;
	qlist.PushBack("1111");
	qlist.PushBack("222222222222222222222222222222");
	qlist.PushBack("3333");
	qlist.PushBack("444444444444444444444444444444");
	//qlist.PushFront("555555");
	//qlist.PopFront();
	//qlist.PopBack();
	//qlist.Insert(1, "6666666");
	//qlist.Erase(1);
	qlist.Print();
	cout << endl;
	seqlist<string> qlist2 = qlist;
	qlist2.Print();

	cout << endl;
	seqlist<string> qlist3;
	qlist3 = qlist;
	qlist3.Print();


}