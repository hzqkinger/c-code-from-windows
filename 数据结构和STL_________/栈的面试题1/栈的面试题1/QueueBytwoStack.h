#pragma once

#include<stack>

template<class T>
class QueueBytwoStack
{
public:

	bool Empty()
	{
		return st1.empty() || st2.empty();
	}
	size_t Size()
	{
		return st1.size() + st2.size();
	}
	T& Front()
	{
		if (!st2.empty())
			return st2.top();
		else if (!st1.empty())
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
		return st2.top();
	}
	T& Back()
	{
		if (!st1.empty())
			return st1.top();
		else if (!st2.empty())
		{
			while (!st2.empty())
			{
				st1.push(st2.top());
				st2.pop();
			}
		}
		return st1.top();
	}
	void Push_back(const T& x)
	{
		st1.push(x);
	}
	void pop_front()//这里也不需要自己判空，底层会自动判空
	{
		if (st2.empty())
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
		st2.pop();
	}
private:
	stack<T> st1;
	stack<T> st2;
};

void testQueueBytwoStack()
{
	QueueBytwoStack<int> q;

	q.Push_back(1);
	q.Push_back(2);
	q.Push_back(3);
	cout << q.Back() << endl;

	//cout << q.Front() << endl;
	q.pop_front();
	cout << q.Back() << endl;

	cout << q.Front() << endl;
	q.pop_front();
	cout << q.Front() << endl;

	q.Push_back(4);
	q.Push_back(5);


	q.pop_front();
	cout << q.Front() << endl;
	q.pop_front();
	cout << q.Front() << endl;
	q.pop_front();
}