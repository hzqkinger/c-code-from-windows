#pragma once

#include "Iterator.h"

template<class T>
struct __ListNode
{
	__ListNode<T>* _next;
	__ListNode<T>* _prev;

	T _data;

	__ListNode(const T& x)
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};

template<class T, class Ref, class Ptr>
struct __ListIterator
{
	typedef __ListIterator<T, Ref, Ptr> Self;
	typedef __ListNode<T> Node;

	typedef Ref Reference;
	typedef Ptr Pointer;

	Node* _node;

	__ListIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;

		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;

		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;

		return tmp;
	}

	bool operator != (const Self& s)
	{
		return _node != s._node;
	}

	bool operator == (const Self& s)
	{
		return _node == s._node;
	}
};

template<class T>
class List
{
	typedef __ListNode<T> Node;
public:
	typedef __ListIterator<T, T&, T*> Iterator;
	typedef __ListIterator<T, const T&, const T*> ConstIterator;

	typedef __ReverseIterator<Iterator> ReverseIterator;
	typedef __ReverseIterator<ConstIterator> ConstReverseIterator;

	ReverseIterator RBegin()
	{
		return End();
	}

	ReverseIterator REnd()
	{
		return Begin();
	}

	Iterator Begin()
	{
		return Iterator(_head->_next);
	}

	ConstIterator Begin() const
	{
		return ConstIterator(_head->_next);
	}

	Iterator End()
	{
		return Iterator(_head);
	}

	ConstIterator End() const
	{
		return ConstIterator(_head);
	}

	List()
		:_head(new Node(T()))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}

	//void PushBack(const T& x)
	//{
	//	// tail newNode _head
	//	Node* newNode = new Node(x);
	//	Node* tail = _head->_prev;

	//	tail->_next = newNode;
	//	newNode->_prev = tail;

	//	newNode->_next = _head;
	//	_head->_prev = newNode;
	//}

	void PushBack(const T& x)
	{
		Insert(End(), x);
	}

	void PopBack()
	{
		Erase(--End());
	}

	void PushFront(const T& x)
	{
		Insert(Begin(), x);
	}

	void PopFront()
	{
		Erase(Begin());
	}

	void Insert(Iterator pos, const T& x)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;

		// prev tmp cur
		Node* tmp = new Node(x);
		prev->_next = tmp;
		tmp->_prev = prev;
		tmp->_next = cur;
		cur->_prev = tmp;
	}

	Iterator Erase(Iterator& pos)
	{
		assert(pos != End());

		Node* prev = (pos._node)->_prev;
		Node* next = (pos._node)->_next;

		prev->_next = next;
		next->_prev = prev;

		delete pos._node;

		pos = prev;

		//return Iterator(next);
		return next;
	}

protected:
	Node* _head;
};

void PrintList(const List<int>& l)
{
	List<int>::ConstIterator it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestList()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);

	//List<int>::Iterator it = l.Begin();
	//__ListNode<int>* pNode = it._node;
	//List<int>::ReverseIterator rIt(it);

	//cout<<sizeof(it)<<endl;
	//cout<<sizeof(pNode)<<endl;
	//cout<<sizeof(rIt)<<endl;

	//++it;
	//++pNode;
	//++rIt;

	/*List<int>::Iterator it = l.Begin();
	while (it != l.End())
	{
	if (*it % 2 == 0)
	{
	l.Erase(it);
	}

	++it;
	}*/

	List<int>::ReverseIterator rIt = l.RBegin();
	while (rIt != l.REnd())
	{
		cout<<*rIt<<" ";
		++rIt;
	}
	cout<<endl;

	//PrintList(l);
}


struct AA
{
	int _a1;
	int _a2;
};

//void TestList()
//{
//	List<int> l;
//	l.PushBack(1);
//	l.PushBack(2);
//	l.PushBack(3);
//	l.PushBack(4);
//
//	List<int>::Iterator it = l.Begin();
//	while (it != l.End())
//	{
//		cout<<*it<<" ";
//		++it;
//	}
//	cout<<endl;
//
//	List<AA> la;
//	la.PushBack(AA());
//	la.PushBack(AA());
//	List<AA>::Iterator lIt = la.Begin();
//	while (lIt != la.End())
//	{
//		cout<<(*lIt)._a1<<" ";
//		cout<<lIt->_a2<<" ";
//		++lIt;
//	}
//	cout<<endl;
//}