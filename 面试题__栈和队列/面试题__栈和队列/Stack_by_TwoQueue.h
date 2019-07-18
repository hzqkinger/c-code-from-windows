#pragma once

#include<queue>

template<class T>
class StackBytwoQueue
{
public:
	bool Empty()
	{
		return q1.empty() || q2.empty();
	}
	size_t Size()
	{
		return q1.size() + q2.size();
	}
	T& Top()
	{
		if (!q1.empty())
			return q1.back();
		else
			return q2.back();
	}
	void Push(const T& x)//按照逻辑，两个队列中至少有一个队列是空队列
	{
		if (!q1.empty())
			q1.push(x);
		else
			q2.push(x);
	}
	void Pop()
	{
		queue<T> *emptyque = &q1;
		queue<T> *nonemptyque = &q2;
		if (!emptyque->empty())
		{
			swap(emptyque, nonemptyque);
		}
		while (nonemptyque->size() > 1)
		{
			emptyque->push(nonemptyque->front());
			nonemptyque->pop();
		}
		nonemptyque->pop();
	}
private:
	queue<T> q1;
	queue<T> q2;
};

void testStackBytwoQueue()
{
	StackBytwoQueue<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);

	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
	cout << s.Top() << endl;
	s.Pop();
}