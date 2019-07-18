#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<assert.h>
typedef int DataType;

class SeqList
{
public:
	SeqList()
		:_a(NULL), _size(0), _capacity(0)
	{}
	SeqList(const SeqList& s)
		:_a(new DataType[s._capacity])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		memcpy(_a, s._a, sizeof(DataType)*_size);
		//for (size_t i = 0; i < _size; ++i)
		//	_a[i] = s._a[i];
	}
	SeqList& operator=(SeqList s)
	{
		if (this != &s)
		{
			Swap(s);
		}
		return *this;
	}
	~SeqList()
	{
		delete[]_a;
		_size = _capacity = 0;
	}

	void Swap(SeqList& s)
	{
		DataType* tmp = NULL;
		tmp = _a;
		_a = s._a;
		s._a = tmp;
		_size = s._size;
		_capacity = s._capacity;
	}
	void PushBack(DataType x)
	{
	/*	if (_size >= _capacity)
		{
			DataType *tmp = _a;
			_capacity = 2 * _capacity + 3;
			_a = new DataType[_capacity];
			memcpy(_a, tmp, sizeof(DataType)*_size);
			_a[_size++] = x;
			delete[]tmp;
		}
		else
		{
			_a[_size++] = x;
		}*/
		Insert(_size, x);
	}
	void PopBack()
	{
		//_size--;
		Erase(_size);
	}
	void PushFront(DataType x)
	{
		Insert(0, x);
	}
	void PopFront()
	{
		Erase(0);
	}
	void Insert(size_t pos, DataType x)//在pos位前面插入数据x
	{
		assert(pos <= _size);
		if (_size >= _capacity)
		{
			_capacity = 2 * _capacity + 3;
			_size++;
			DataType *tmp = new DataType[_capacity];//扩容开空间
			for (size_t i = 0; i < pos; ++i)//将数据复制到新空间
				tmp[i] = _a[i];
			tmp[pos] = x;
			for (size_t i = pos + 1; i < _size; ++i)
				tmp[i] = _a[i - 1];

			delete[]_a;
			_a = tmp;
		}
		else
		{
			_size++;
			for (size_t i = _size - 1; i > pos; --i)
			{
				_a[i] = _a[i - 1];
			}
			_a[pos] = x;
		}
	}
	void Erase(size_t pos)
	{
		assert(_size&&pos <= _size);
		--_size;
		for (size_t i = pos; i < _size; ++i)
			_a[i] = _a[i + 1];
	}
	DataType& operator[](size_t pos)
	{
		assert(pos < _size);
		return _a[pos];
	}
	void CheckCapcacity();
	void Print()
	{
		for (size_t i = 0; i < _size; ++i)
			cout << _a[i] << " ";
		cout << endl;
	}
private:
	DataType* _a;
	size_t _size;
	size_t _capacity;
};
int main()
{
	SeqList s1;
	s1.PushFront(1);
	s1.PushFront(2);
	s1.PushFront(3);
	s1.PushFront(4);
	s1.Print();
	s1.Insert(1, 10);
	s1.Print();

	system("pause");
	return 0;
}