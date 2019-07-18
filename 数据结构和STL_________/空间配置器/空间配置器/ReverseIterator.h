#pragma once

// ���������ͱ�


// Traits����һ̨��������ȡ������եȡ���������������ԣ���Ӧ���ͱ�
template <class Iterator>struct IteratorTraits
{
	//typedef typename Iterator::IteratorCategory  IteratorCategory;
	typedef typename Iterator::ValueType         ValueType;
	//typedef typename Iterator::DifferenceType    DifferenceType;
	typedef typename Iterator::Pointer           Pointer;
	typedef typename Iterator::Reference         Reference;
};
// ƫ�ػ�ԭ��ָ������
template <class T>struct IteratorTraits<T*>
{
	//typedef RandomAccessIteratorTag    IteratorCategory;
	typedef T                          ValueType;
	//typedef ptrdiff_t                  DifferenceType;
	typedef T*                         Pointer;
	typedef T&                         Reference;
};
// ƫ�ػ�constԭ��ָ������
template <class T>struct IteratorTraits<const T*>
{
	//typedef RandomAccessIteratorTag IteratorCategory;
	typedef T                          ValueType;
	//typedef ptrdiff_t                  DifferenceType;
	typedef const T*                   Pointer;
	typedef const T&                   Reference;
};


//�����������ͨ��������������������
template<class Iterator>//ģ�������Iterator��һ�����ͣ�
struct ReverseIterator5  //��ReverseIterator5<Iterator>��һ�����ͣ�
{
	//������Ƕ����
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

	Reference operator*()//�������������Refence  Pointer
	{
		Iterator it = _it;
		return *(--it);
	}
	Pointer operator->()
	{
		return &(operator*());
	}

	Self& operator++()//ǰ��++
	{
		--_it;
		return *this;
	}
	Self operator++(int)//����++
	{
		_it--;
		return *this;
	}
	Self& operator--()//ǰ��--
	{
		++_it;
		return *this;
	}
	Self operator--(int)//����--
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
	//����+= -= [] ������������ͺ���

	//������Ƕ����
	typedef typename IteratorTraits<Iterator>::ValueType         ValueType;
	typedef typename IteratorTraits<Iterator>::Pointer           Pointer;
	typedef typename IteratorTraits<Iterator>::Reference         Reference;

	typedef ReverseIterator6<Iterator> Self;
	ReverseIterator6(Iterator it)//������ʽд���캯��
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
	//ValueType& operator[]()//�д������費��Ҫ����
	//{
	//}
};