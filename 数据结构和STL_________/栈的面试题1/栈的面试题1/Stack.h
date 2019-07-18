#pragma once
#include<stack>

//ʵ��һ��ջ�������ӿڣ�Ҫ��push(), pop(), Min()��ʱ�临�Ӷȶ�ΪO(1)

template<class T>
class Minstack
{
public:
	void Push(const T &x)
	{
		if (st1.empty() || x <= st1.top())
			st2.push(x);
		st1.push(x);
	}
	void Pop()
	{
		if (st1.top() == st2.top())
			st2.pop();
		st1.pop();
	}
	T Min()//����Ҫ�Լ��пգ��ײ���Զ��п�
	{
		return st2.top();
	}

private:
	stack<T> st1;
	stack<T> st2;
};

void testMinstack()
{
	Minstack<int> s;

	s.Push(5);
	s.Push(3);
	s.Push(5);
	s.Push(6);
	s.Push(7);
	s.Push(3);
	s.Push(8);
	s.Push(0);

	cout << s.Min() << endl;//0
	s.Pop();
	cout << s.Min() << endl;//3
	s.Pop();
	cout << s.Min() << endl;//3
	s.Pop();
	cout << s.Min() << endl;//3
	s.Pop();
	cout << s.Min() << endl;//3
	s.Pop();
	cout << s.Min() << endl;//3
	s.Pop();
	cout << s.Min() << endl;//3
	s.Pop();
	cout << s.Min() << endl;//5
	s.Pop();
}