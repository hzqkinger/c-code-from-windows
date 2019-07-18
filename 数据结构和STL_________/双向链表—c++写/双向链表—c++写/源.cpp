#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<assert.h>

typedef int DataType;
struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	DataType _data;

	ListNode(const DataType &x)
		:_next(NULL)
		, _prev(NULL)
		, _data(x)
	{};
};

class List
{
	typedef ListNode Node;
public:
	List()
		:_head(NULL), _tail(NULL)
	{}
	List(const List& li)
	{
		Node *tmp = li._head;
		while (tmp)
		{
			if (!_head)
				_head = _tail = new Node(tmp->_data);
			else
			{
				_tail->_next = new Node(tmp->_data);
				_tail->_next->_prev = _tail;
				_tail = _tail->_next;
				_tail->_next = NULL;
			}
			tmp = tmp->_next;
		}
	}
	List& operator=(const List& li)
	{
		if (this != &li)
		{
			_tail = _head;
			while (_tail)
			{
				_tail = _tail->_next;
				delete _head;
				_head = _tail;
			}

			Node *tmp = li._head;
			while (tmp)
			{
				if (!_head)
					_head = _tail = new Node(tmp->_data);
				else
				{
					_tail->_next = new Node(tmp->_data);
					_tail->_next->_prev = _tail;
					_tail = _tail->_next;
					_tail->_next = NULL;
				}
				tmp = tmp->_next;
			}
		}
		return *this;
	}
	~List()
	{
		_tail = _head;
		while (_tail)
		{
			_tail = _tail->_next;
			delete _head;
			_head = _tail;
		}
	}
	void PushBack(DataType x)
	{
		//if (!_head)
		//	_head = _tail = new Node(x);
		//else
		//{
		//	Node *tmp = new Node(x);
		//	_tail->_next = tmp;
		//	tmp->_prev = _tail;
		//	_tail = _tail->_next;
		//}
		if (!_head)
			Insert(_tail, x);
		else
			Insert(_tail->_next, x);
	}
	void PopBack()
	{
		//assert(_head);//不能删除空链表里的节点
		//if (_head == _tail)//只有一个节点的情况
		//{
		//	delete _tail;
		//	_head = _tail = NULL;
		//}
		//else
		//{
		//	_tail = _tail->_prev;
		//	delete _tail->_next;
		//	_tail->_next = NULL;
		//}
		Erase(_tail);
	}
	void PushFront(DataType x)
	{
		Insert(_head, x);
	}
	void PopFront()
	{
		Erase(_head);
	}
	void Insert(Node* pos, DataType x)//在pos的前面插入一个
	{
		if (!_head)//空链表的情况
			_head = _tail = new Node(x);
		else if (pos == _tail->_next)
		{
			Node *tmp = new Node(x);
			_tail->_next = tmp;
			tmp->_prev = _tail;
			_tail = tmp;//尾插更新_tail
		}
		else
		{
			Node *tmp = new Node(x);
			if (pos == _head)
			{
				tmp->_next = pos;
				pos->_prev = tmp;
				_head = tmp;//头插更新_head
			}
			else
			{
				pos->_prev->_next = tmp;
				tmp->_prev = pos->_next;
				tmp->_next = pos;
				pos->_prev = tmp;
			}
		}
	}
	void Erase(Node* pos)
	{
		assert(_head);
		if (pos == _head)
		{
			_head = _head->_next;//头删更新_head
			if (_head)
			_head->_prev = NULL;
		}
		else if (pos == _tail)
		{
			_tail = _tail->_prev;
			_tail->_next = NULL;
		}
		else
		{
			pos->_prev->_next = pos->_next;
			pos->_next->_prev = pos->_prev;
		}
		delete pos;
	}
	Node* Find(DataType x)
	{
		Node *tmp = _head;
		while (tmp)
		{
			if (tmp->_data == x)
				break;
			tmp = tmp->_next;
		}
		return tmp;
	}
	void Reverse()//双向链表的逆置_优
	{
		Node *tmp = _head;
		while(tmp)
		{
			swap(tmp->_prev, tmp->_next);
			tmp = tmp->_prev;
		}
		swap(_head, _tail);
	}
	void Print()
	{
		Node *tmp = _head;
		while (tmp)
		{
			cout << tmp->_data << " ";
			tmp = tmp->_next;
		}
		cout << endl;
	}
private:
	Node* _head;
	Node* _tail;
};

//不带头结点的双向链表
int main()
{
	List li;
	li.PushBack(1);
	li.PushBack(2);
	li.PushBack(3);
	li.PushBack(4);
	li.Print();

	List li2;
	li2 = li;
	li2.Print();


	system("pause");
	return 0;
}