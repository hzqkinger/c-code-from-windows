#pragma once

template<class T, class con = My_vector<T>>
class Stack
{
	con v;
public:
	//1.构造函数和拷贝构造函数
	//2.(empty(),size(),top(),push(),pop(),swap())
	bool Empty()const
	{
		return v.Empty();
	}
	size_t Size()const
	{
		return v.Size();
	}
	T& Top()
	{
		return v.Back();
	}
	const T& Top()const
	{
		return v.Back();
	}

	void Push(const T& x)
	{
		v.PushBack(x);
	}
	void Pop()
	{
		v.PopBack();
	}

	void Swap(Stack<T>& s)
	{
		v.Swap(s.v);
	}
};

void test_stack()
{
	Stack<int> sta;
	cout << sta.Empty() << " " << sta.Size() << endl;
	sta.Push(1);
	sta.Push(2);
	sta.Push(3);
	sta.Push(4);
	sta.Push(5);
	cout << sta.Empty() << " " << sta.Size() << endl;
	cout << sta.Top() << endl;
	sta.Pop();
	cout << sta.Top() << endl;
	sta.Pop();
	cout << sta.Top() << endl;
	sta.Pop();
	cout << sta.Top() << endl;
	sta.Pop();
	cout << sta.Top() << endl;
	sta.Pop();
	//cout << sta.Top() << endl;
	//sta.Pop();
}
void test_stack2()
{
	Stack<string> sta;
	cout << sta.Empty() << " " << sta.Size() << endl;
	sta.Push("111111");
	sta.Push("222222");
	sta.Push("333333");
	sta.Push("444444");
	sta.Push("555555");
	cout << sta.Empty() << " " << sta.Size() << endl;
	cout << sta.Top() << endl;
	sta.Pop();
	cout << sta.Top() << endl;
	sta.Pop();
	cout << sta.Top() << endl;
	sta.Pop();
	cout << sta.Top() << endl;
	sta.Pop();
	cout << sta.Top() << endl;
	sta.Pop();
	//cout << sta.Top() << endl;
	//sta.Pop();
}