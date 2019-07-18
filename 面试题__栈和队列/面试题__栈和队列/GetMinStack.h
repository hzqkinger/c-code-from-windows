#pragma once

//问题：在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。
#include<stack>

template<class T>
class GetMinStack{
public:
	void Push(const T &x)
	{
		s1.push(x);
		if (!s2.empty() && s2.top() < x){ s2.push(s2.top()); }
		else{s2.push(x);}
	}
	void Pop()
	{
		s1.pop();
		s2.pop();
	}
	void Push2(const T &x)
	{
		s1.push(x);
		if (s2.empty())s2.push(x);
		else if (x <= s2.top())s2.push(x);
	}
	void Pop2()
	{
		if (s2.top() == s1.top())s2.pop();
		s1.pop();
	}

	const T &Top()
	{
		return s1.top();
	}
	const T &GetMin()
	{
		return s2.top();
	}
private:
	stack<T> s1;
	stack<T> s2;
};

void test_GetMinStack()
{
	GetMinStack<int> s;
	s.Push2(5);
	s.Push2(3);
	s.Push2(7);
	s.Push2(3);
	s.Push2(2);
	s.Push2(5);
	s.Push2(3);

	cout << s.GetMin() << endl;//2
	s.Pop2();
	cout << s.GetMin() << endl;//2
	s.Pop2();
	cout << s.GetMin() << endl;//2
	s.Pop2();
	cout << s.GetMin() << endl;//3
	s.Pop2();
	cout << s.GetMin() << endl;//3
	s.Pop2();
	cout << s.GetMin() << endl;//3
	s.Pop2();
	cout << s.GetMin() << endl;//5
}