#pragma once
//如何仅用递归函数和栈操作逆序一个栈
#include<stack>
template<class T>T GetNum(stack<T> &s)//每次得到一个栈中的最底层元素并且将其移除
{
	T result = s.top();
	s.pop();
	if (s.empty()){ return result; }
	else
	{
		T last = GetNum(s);//递归中的返回值很重要，很重要
		s.push(result);
		return last;
	}
}
template<class T>void Reverse5(stack<T> &s)
{
	if (s.empty())return;

	T result = GetNum(s);

	Reverse5(s);

	s.push(result);
}
void test_ReverseStack()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s.top() << endl;
	Reverse5(s);
	cout << s.top() << endl;

}