#pragma once

template<class T,class con = Mylist<T>>
class Queue{
	con li;
public:
	//1.构造函数和拷贝构造函数
	//2.(empty(),size(),front(),back(),push(),pop(),swap())
	bool Empty()const
	{
		return li.Empty();
	}
	size_t Size()const
	{
		return li.Size();
	}
	T& Front()
	{
		return li.Front();
	}
	const T& Front()const
	{
		return li.Front();
	}
	T& Back()
	{
		return li.Back();
	}
	const T& Back()const
	{
		return li.Back();
	}

	void Push(const T& x)
	{
		li.Pushback(x);
	}
	void Pop()
	{
		li.Popfront();
	}

	void Swap(Queue<T>& q)
	{
		li.Swap(q.li);
	}
};

void test_queue()
{
	Queue<int> q;
	cout << q.Size() << " " << q.Empty() << endl;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	cout << q.Front() << " " << q.Back() << endl;
	q.Pop();
	cout << q.Front() << " " << q.Back() << endl;
	q.Pop();
	cout << q.Front() << " " << q.Back() << endl;
}
void test_queue2()
{
	Queue<string> q;
	cout << q.Size() << " " << q.Empty() << endl;
	q.Push("111");
	q.Push("222");
	q.Push("333");
	q.Push("444");
	q.Push("555");
	cout << q.Front() << " " << q.Back() << endl;
	q.Pop();
	cout << q.Front() << " " << q.Back() << endl;
	q.Pop();
	cout << q.Front() << " " << q.Back() << endl;
}