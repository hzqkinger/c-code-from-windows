#pragma once
//��ν��õݹ麯����ջ��������һ��ջ
#include<stack>
template<class T>T GetNum(stack<T> &s)//ÿ�εõ�һ��ջ�е���ײ�Ԫ�ز��ҽ����Ƴ�
{
	T result = s.top();
	s.pop();
	if (s.empty()){ return result; }
	else
	{
		T last = GetNum(s);//�ݹ��еķ���ֵ����Ҫ������Ҫ
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