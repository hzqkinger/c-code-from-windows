#pragma once

// 迭代器的型别


// Traits就像一台“特性萃取机”，榨取各个迭代器的特性（对应的型别）
template <class Iterator>struct IteratorTraits
{
	//typedef typename Iterator::IteratorCategory  IteratorCategory;
	typedef typename Iterator::ValueType         ValueType;
	//typedef typename Iterator::DifferenceType    DifferenceType;
	typedef typename Iterator::Pointer           Pointer;
	typedef typename Iterator::Reference         Reference;
};
// 偏特化原生指针类型
template <class T>struct IteratorTraits<T*>
{
	//typedef RandomAccessIteratorTag    IteratorCategory;
	typedef T                          ValueType;
	//typedef ptrdiff_t                  DifferenceType;
	typedef T*                         Pointer;
	typedef T&                         Reference;
};
// 偏特化const原生指针类型
template <class T>struct IteratorTraits<const T*>
{
	//typedef RandomAccessIteratorTag IteratorCategory;
	typedef T                          ValueType;
	//typedef ptrdiff_t                  DifferenceType;
	typedef const T*                   Pointer;
	typedef const T&                   Reference;
};


//反向迭代器是通过正向迭代器适配出来的
template<class Iterator>//模板参数（Iterator是一个类型）
struct ReverseIterator5  //（ReverseIterator5<Iterator>是一个类型）
{
	//定义内嵌类型
	//typedef typename IteratorTraits<Iterator>::IteratorCategory  IteratorCategory;
	typedef typename IteratorTraits<Iterator>::ValueType         ValueType;
	//typedef typename IteratorTraits<Iterator>::DifferenceType    Difference_type;
	typedef typename IteratorTraits<Iterator>::Pointer           Pointer;
	typedef typename IteratorTraits<Iterator>::Reference         Reference;

	//typedef Iterator IteratorType;
	typedef ReverseIterator5<Iterator> Self;

	///////////////////////////////////////////////////////////////////////////////
	Iterator _it;
	ReverseIterator5(Iterator it = Iterator())
		:_it(it)
	{}

	Reference operator*()//类型里面的类型Refence  Pointer
	{
		Iterator it = _it;
		return *(--it);
	}
	Pointer operator->()
	{
		return &(operator*());
	}

	Self& operator++()//前置++
	{
		--_it;
		return *this;
	}
	Self operator++(int)//后置++
	{
		_it--;
		return *this;
	}
	Self& operator--()//前置--
	{
		++_it;
		return *this;
	}
	Self operator--(int)//后置--
	{
		_it++;
		return *this;
	}

	bool operator != (Self& s)
	{
		return _it != s._it;
	}
	bool operator == (Self& s)
	{
		return _it == s._it;
	}
};


template<class Iterator>
struct ReverseIterator6 :public ReverseIterator5<Iterator>{
	//重载+= -= [] 这三个运算符就好了

	//定义内嵌类型
	typedef typename IteratorTraits<Iterator>::ValueType         ValueType;
	typedef typename IteratorTraits<Iterator>::Pointer           Pointer;
	typedef typename IteratorTraits<Iterator>::Reference         Reference;

	typedef ReverseIterator6<Iterator> Self;
	ReverseIterator6(Iterator it)//必须显式写构造函数
		:ReverseIterator5(it)
	{}

	Self& operator+=(int size)
	{
		if (size < 0)
			_it += size;
		else
			_it -= size;
		return *this;
	}
	Self& operator-=(int size)
	{
		if (size < 0)
			_it -= size;
		else
			_it += size;
		return *this;
	}
	Self operator+(int size)
	{
		Self tmp(*this);
		if (size < 0)
			tmp._it += size;
		else
			tmp._it -= size;
		return tmp;
	}
	Self operator-(int size)
	{
		Self tmp(*this);
		if (size < 0)
			tmp._it -= size;
		else
			tmp._it += size;
		return tmp;
	}
	//ValueType& operator[]()//有待考虑需不需要重载
	//{
	//}
};