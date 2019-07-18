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
		:_a(NULL)//��ð�_a��ʼ����NULL����Ϊ��new[]��delete[]�ܸ��õ�ƥ������ʹ��
		, _size(0)
		, _capacity(0)
	{}
	//��������
	seqlist(const seqlist<T> &seq)
		:_a(new T[seq._size])
		, _size(seq._size)
		, _capacity(_size)
	{
		for (size_t i = 0; i < _size; ++i)
			_a[i] = seq._a[i];
	}
	//��ֵ���������
	seqlist<T>& operator=(seqlist<T> seq)//�����˿������캯��
	{
		if (this != &seq)//����о��е����⣬������ֹ���˸��Լ���ֵ
		{
			swap(_a, seq._a);
			swap(_size, seq._size);
			swap(_capacity, seq._capacity);
		}
		return *this;
	}
	//����
	~seqlist()
	{
		if (_a)
			delete[] _a;
	}
	//��ɾ���
	void PushBack(T x)
	{
		//CheckCapcacity();
		//_a[_size++] = x;//����������������Զ������ͣ�����Զ����ø���ĸ�ֵ��������غ���
		Insert(_size, x);
	}
	void PopBack()
	{
		//if (_size>0)//����˳�����Ԫ�ظ�����0����֤�ٴε��øú�����Ч
		//	_size--;
		Erase(_size-1);
	}
	void PushFront(T x)
	{
		//CheckCapcacity();
		////memcpy(newA, _a, sizeof(T)*_size);//���û����ǳ�������⣬�����������
		//for (size_t i = _size; i > 0; --i)
		//	_a[i] = _a[i - 1];//һ��һ�����ݸ�������������������������Զ������ͣ�����Զ����ø���ĸ�ֵ��������غ���(�Ͳ���Ҫ�����������ǳ������������)
		//_a[0] = x;
		//_size++;
		Insert(0, x);
	}
	void PopFront()
	{
		//if (_size > 0)//����˳�����Ԫ�ظ�����0����֤�ٴε��øú�����Ч
		//{
		//	_size--;
		//	for (size_t i = 0; i < _size; ++i)
		//		_a[i] = _a[i + 1];
		//}
		Erase(0);
	}
	void Insert(size_t pos, T x)//��posλǰ���������x
	{
		CheckCapcacity();
		//memcpy(newA, _a, sizeof(T)*_size);//���û����ǳ�������⣬�����������
		for (size_t i = _size; i > pos; --i)
			_a[i] = _a[i - 1];//һ��һ�����ݸ�������������������������Զ������ͣ�����Զ����ø���ĸ�ֵ��������غ���(�Ͳ���Ҫ�����������ǳ������������)
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
	{               //�漰��������ȡ�����⡣
		if (_size >= _capacity)
		{
			_capacity = _capacity > 0 ? _capacity * 2 : 3;
			T *newA = new T [_capacity];
			if (_a)
			{
				//memcpy(newA, _a, sizeof(T)*_size);//���û����ǳ�������⣬�����������
				for (size_t i = 0; i < _size; ++i)
					newA[i] = _a[i];//һ��һ�����ݸ�������������������������Զ������ͣ�����Զ����ø���ĸ�ֵ��������غ���(�Ͳ���Ҫ�����������ǳ������������)
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