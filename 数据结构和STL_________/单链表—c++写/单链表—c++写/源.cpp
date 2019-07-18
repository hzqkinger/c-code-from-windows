#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<assert.h>

typedef int DataType;
struct SListNode
{
	SListNode* _next;
	DataType _data;

	SListNode(DataType x)
		:_data(x)
		, _next(NULL)
	{}
};

class SList
{
	typedef SListNode Node;
public:
	SList()
		:_head(NULL), _tail(NULL)
	{}
	SList(const SList& s)
	{
		Node *tmp = s._head;
		while (tmp)
		{
			//if (!_head)
			//	_head = _tail = new Node(tmp->_data);
			//else
			//{
			//	_tail->_next = new Node(tmp->_data);
			//	_tail = _tail->_next;
			//}
			PushBack(tmp->_data);
			tmp = tmp->_next;
		}
	}
	SList& operator=(const SList& s)
	{
		if (this != &s)
		{
			//_tail = _head;//��thisָ����������
			//while (_tail)
			//{
			//	_head = _tail->_next;
			//	delete _tail;
			//	_tail = _head;
			//}
			Clearlist();

			Node *tmp = s._head;//���θ�ֵ
			while (tmp)
			{
				//if (!_head)
				//	_head = _tail = new Node(tmp->_data);
				//else
				//{
				//	_tail->_next = new Node(tmp->_data);
				//	_tail = _tail->_next;
				//}
				PushBack(tmp->_data);
				tmp = tmp->_next;
			}
		}
		return *this;
	}
	void Clearlist()
	{
		_tail = _head;
		while (_tail)
		{
			_head = _tail->_next;
			delete _tail;
			_tail = _head;
		}
	}
	~SList()
	{
		//_tail = _head;
		//while (_tail)
		//{
		//	_head = _tail->_next;
		//	delete _tail;
		//	_tail = _head;
		//}
		Clearlist();
	}

	void PushBack(DataType x)
	{
		//if (_head == NULL)
		//	_head = _tail = new Node(x);
		//else
		//{
		//	_tail->_next = new Node(x);
		//	_tail = _tail->_next;
		//	_tail->_next = NULL;
		//}

		if (!_head)//�������������
			Insert(_tail, x);
		else
			Insert(_tail->_next, x);
	}
	void PopBack()
	{
		//assert(_head);
		//if (_head == _tail)
		//{
		//	delete _tail;
		//	_head = _tail = NULL;
		//}
		//else
		//{
		//	Node *tmp = _head;
		//	while (tmp->_next != _tail)
		//		tmp = tmp->_next;
		//	delete _tail;
		//	_tail = tmp;
		//	_tail->_next = NULL;
		//}
		Erase(_tail);
	}
	void PushFront(DataType x)
	{
		Insert(_head, x);
	}
	void PopFront();

	void Insert(Node* pos, DataType x)//����һ���ڵ���pos��ǰ��
	{
		Node *tmp = NULL;
		if (!_head)
			_head = _tail = new Node(x);//��������Ϊ�յ����
		else if (pos == _head)//����ֻ��һ���ڵ�����
		{
			tmp = new Node(x);
			tmp->_next = _head;
			_head = tmp;
		}
		else
		{
			tmp = _head;
			while (tmp->_next != pos)
				tmp = tmp->_next;
			tmp->_next = new Node(x);
			tmp = tmp->_next;
			tmp->_next = pos;
			if (!pos)//������_tail->_next��ǰ�����һ�����ݣ�Ҫ����_tail
				_tail = tmp;
		}

	}
	void Erase(Node* pos)
	{
		assert(_head&&pos);//����ɾ������������ɾ��β�ڵ����Ŀա�
		if (pos == _head)
		{
			_head = _head->_next;
		}
		else
		{
			Node *tmp = _head;
			while (tmp->_next != pos)
				tmp = tmp->_next;
			tmp->_next = pos->_next;
			if (pos == _tail)//����posָ��_tail��Ҫ����_tail��ֵ��
				_tail = tmp;
		}
		delete pos;
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
	Node* Getpos(size_t index)
	{
		Node *tmp = _head;
		while (tmp&&--index)
		{
			tmp = tmp->_next;
		}
		return tmp;
	}

private:
	Node* _head;
	Node* _tail;
};
int main()
{
	SList s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.Print();
	//s1.Erase(s1.Getpos(1));
	//s1.Insert(s1.Getpos(4), 10);
	//s1.PopBack();
	//s1.PopBack();
	//s1.PopBack();
	SList s2;
	s2= s1;
	s2.Print();
	system("pause");
	return 0;
}