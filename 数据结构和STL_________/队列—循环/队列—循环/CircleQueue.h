#pragma once
#include<cassert>

//为了处理队列是满还是空问题，这少用了一个空间
template<typename T,unsigned N>
class CircleQueue{
public:
	CircleQueue() :_front(0), _rear(0){}//初始化空队列时，大多数都约定_front = _rear = 0;

	void Push(const T &x)//插入元素时，_front不变，_rear向后移动一位
	{
		assert((_rear + 1) % (N + 1) != _front);
		_a[_rear] = x;
		_rear = (_rear + 1) % (N + 1);
	}
	void Pop()
	{
		assert(_rear != _front);
		_front = (_front + 1) % N;
	}
	const T &Front()
	{
		assert(_rear != _front);
		return _a[_front];
	}
	const T &Back()
	{
		assert(_rear != _front);
		return _a[(_rear + N) % (N + 1)];
	}
	size_t size()
	{
		return (_rear + N + 1 - _front) % (N + 1);
	}
private:
	T _a[N + 1];//实际上在底层多开了一个空间
	unsigned _front;//指向第一个元素
	unsigned _rear;//指向最后一个元素的下一个
};

void test()
{
	CircleQueue<int, 5> cq;
	//cout << cq.Front() << " " << cq.Back() << endl;
	cq.Push(1);
	cq.Push(2);
	cout << cq.Front() << " " << cq.Back() << endl;
	cq.Pop();
	cout << cq.Front() << " " << cq.Back() << endl;
	cq.Push(3);
	cq.Pop();
	cout << cq.Front() << " " << cq.Back() << endl;
	cq.Push(4);
	cq.Push(5);
	cq.Pop();
	cout << cq.Front() << " " << cq.Back() << endl;
	cq.Push(6);
	cq.Push(7);
	cq.Pop();
	cout << cq.Front() << " " << cq.Back() << endl;
	cq.Push(8);
	cout << cq.Front() << " " << cq.Back() << endl;

	cq.Push(9);
	cout << cq.Front() << " " << cq.Back() << endl;
	//cq.Push(9);


}