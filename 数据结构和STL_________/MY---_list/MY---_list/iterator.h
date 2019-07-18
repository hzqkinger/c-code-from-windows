#pragma once

// 复用和效率

// 适配器模式 --> 复用
// List->__ListIterator
// Vector->T*
template<class Iterator>
struct __ReverseIterator
{
	Iterator _it;

	__ReverseIterator(Iterator it)
		:_it(it)
	{}

	typename Iterator::Reference operator*()
	{
		Iterator it = _it;
		return *(--it);
	}

	typename Iterator::Pointer operator->()
	{
		return &(operator*());
	}

	__ReverseIterator operator++()
	{
		--_it;
		return *this;
	}

	__ReverseIterator operator--()
	{
		++_it;

		return *this;
	}

	bool operator != (__ReverseIterator<Iterator>& s)
	{
		return _it != s._it;
	}

	bool operator == (__ReverseIterator<Iterator>& s)
	{
		return _it == s._it;
	}
};