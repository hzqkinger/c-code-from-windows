#pragma once
//问题：用两个栈实现一个队列
#include<stack>

template<class T>
class Queue_By_TwoStack{
public:
	void Push(const T &x)
	{
		s1.push(x);
	}
	void Pop()
	{
		if (s2.empty())
		{
			while (!s1.empty()){ s2.push(s1.top()); s1.pop(); }
		}
		s2.pop();
	}

	const T &Front()
	{
		if (s2.empty())
		{
			while (!s1.empty()){ s2.push(s1.top()); s1.pop(); }
		}
		return s2.top();
	}
	const T &Back()
	{
		if (s1.empty())
		{
			while (!s2.empty()){ s1.push(s2.top()); s1.pop(); }
		}
		return s1.top();
	}
	size_t size()
	{
		return s1.size() + s2.size();
	}
private:
	stack<T> s1;
	stack<T> s2;
};

void test_Queue_By_TwoStack()
{
	Queue_By_TwoStack<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	cout << q.Front() << endl;//1
	q.Pop();
	cout << q.Front() << endl;//2
	q.Pop();
	q.Push(4);
	cout << q.Front() << endl;//3
	q.Pop();
	q.Push(5);
	cout << q.Front() << endl;//4
	q.Pop();
	q.Push(6);
	cout << q.Front() << endl;//5
	q.Pop();
	cout << q.Front() << endl;//6
	q.Pop();

}