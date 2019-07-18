#pragma once

#define _CRT_SECUER_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

template<class T>
struct listNode{
	T _data;
	listNode<T>* _next;
	listNode<T>*_prev;
	listNode(const T data = T())
		:_data(data)
		, _next(NULL)
		, _prev(NULL)
	{}
};

//双向循环链表_带头结点
template<class T>
class list
{
	typedef listNode<T> Node;
public:

	list()
		:_head(new Node)
	{
		_head->_prev = _head;
		_head->_next = _head;
	}
	list(const list<T>& l)
		:_head(new Node)
	{
		_head->_prev = _head;
		_head->_next = _head;

		Node *tmp = l._head->_next;
		while (tmp != l._head)
		{
			PushBack(tmp->_data);
			tmp = tmp->_next;
		}
	}
	list<T>& operator=(list<T> l)
	{
		swap(_head, l._head);
		return *this;
	}
	~list()
	{
		Node *cur = _head->_next;
		Node *next = cur->_next;

		while (cur != _head)
		{
			delete cur;
			cur = next;
			next = next->_next;
		}
		delete _head;
		cur = next = NULL;
	}
	void PushBack(const T& x)
	{
		//Node *tmp = new Node(x);
		//tmp->_prev = _head->_prev;
		//_head->_prev->_next = tmp;
		//_head->_prev = tmp;
		//tmp->_next = _head;
		Insert(_head,x);
	}
	void PopBack()
	{
		//Node *tmp = _head->_prev;
		//_head->_prev = tmp->_prev;
		//tmp->_prev->_next = _head;
		//delete tmp;
		Erase(_head->_prev);
	}
	void PushFront(const T& x)
	{
		//Node *tmp = new Node(x);
		//tmp->_next = _head->_next;
		//_head->_next->_prev = tmp;
		//_head->_next = tmp;
		//tmp->_prev = _head;
		Insert(_head->_next,x);
	}
	void PopFront()
	{
		//Node *tmp = _head->_next;
		//_head->_next = tmp->_next;
		//tmp->_next->_prev = _head;
		//delete tmp;
		Erase(_head->_next);
	}
	//在pos前面插入一个节点
	void Insert(Node* pos, const T& x)
	{
		Node *tmp = new Node(x);
		pos->_prev->_next = tmp;
		tmp->_prev = pos->_prev;
		tmp->_next = pos;
		pos->_prev = tmp;
	}
	void Erase(Node* pos)
	{
		if (pos && pos != _head)
		{
			pos->_prev->_next = pos->_next;
			pos->_next->_prev = pos->_prev;
			delete pos;
		}
	}
	void Print()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
private:
	Node *_head;
};