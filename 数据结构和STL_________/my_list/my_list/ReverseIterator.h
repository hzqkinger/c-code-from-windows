#pragma once

//�����������ͨ��������������������

template<class Iterator>//ģ�������Iterator��һ�����ͣ�
struct ReverseIterator5  //��ReverseIterator5<Iterator>��һ�����ͣ�
{
	Iterator _it;

	ReverseIterator5(Iterator it)
		:_it(it)
	{}

	typename Iterator::Refence operator*()//�������������Refence  Pointer
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