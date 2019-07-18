#pragma once
#include<cassert>

//Ϊ�˴�������������ǿ����⣬��������һ���ռ�
template<typename T,unsigned N>
class CircleQueue{
public:
	CircleQueue() :_front(0), _rear(0){}//��ʼ���ն���ʱ���������Լ��_front = _rear = 0;

	void Push(const T &x)//����Ԫ��ʱ��_front���䣬_rear����ƶ�һλ
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
	T _a[N + 1];//ʵ�����ڵײ�࿪��һ���ռ�
	unsigned _front;//ָ���һ��Ԫ��
	unsigned _rear;//ָ�����һ��Ԫ�ص���һ��
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