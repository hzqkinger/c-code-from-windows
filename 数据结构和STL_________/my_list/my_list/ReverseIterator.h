#pragma once

//反向迭代器是通过正向迭代器适配出来的

template<class Iterator>//模板参数（Iterator是一个类型）
struct ReverseIterator5  //（ReverseIterator5<Iterator>是一个类型）
{
	Iterator _it;

	ReverseIterator5(Iterator it)
		:_it(it)
	{}

	typename Iterator::Refence operator*()//类型里面的类型Refence  Pointer
	{
		Iterator it = _it;
		return *(--it);
	}
	typename Iterator::Pointer operator->()
	{
		return &(operator*());
	}
	ReverseIterator5 operator++()
	{
		--_it;
		return *this;
	}

	ReverseIterator5 operator--()
	{
		++_it;
		return *this;
	}
	bool operator != (ReverseIterator5<Iterator>& s)
	{
		return _it != s._it;
	}

	bool operator == (ReverseIterator5<Iterator>& s)
	{
		return _it == s._it;
	}
};