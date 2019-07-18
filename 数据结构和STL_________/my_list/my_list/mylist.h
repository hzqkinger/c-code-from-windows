#pragma once

#include"ReverseIterator.h"

template<class T>
struct listnode   //����Ľڵ�
{
	T _data;
	listnode<T> *_next;
	listnode<T> *_prev;
	listnode(const T& data)
		:_data(data), _next(0), _prev(0)
	{}
};


//����û�е�������������û���ṩprint����(��ʹ�ṩҲ��һ���������û��Ĵ�ӡ����)
//             ����û����ӡ������������ݣ��ͱ���֪��������ڲ��ṹ(������ÿ��������ּ�����)
//              ��͢�������ʹ�óɱ����ƻ��˷�װ��
//���ԾͲ����˵��������������
template<class T,class ref,class ptr>
struct ListIterator         //����������Ϊ�˷������������������ݣ��������е�������ָ�룩
{//����ĵ�����

	typedef ListIterator<T, ref, ptr> self;
	typedef listnode<T> Node;

	typedef ref Refence;//ʹRefenceΪref�ı������������Ҫ��Refence���ͱ���ͨ��ListIterator<T,ref,ptr>�������ı���������
	typedef ptr Pointer;

	Node * _node;       //��ʵ���ǵ����������ݳ�Ա_node��ָ����

	ListIterator(Node *node)//���캯��
		:_node(node)
	{}
	//����дĬ�ϵĿ������캯��+��ֵ��������غ�������Ϊ�������Ķ���Ҫ����ָͨ��һ����Ĭ�ϵľ��Ѿ�����Ҫ���ˡ�

	//Ҫ������ָͨ��һ���ܷ�����������++ -- * -> != ==��
	ref operator*()//_data�Ǹ���ͨ���ͣ���ָ���������͵���ָͨ��һ�������þ͵õ���ָ������ݣ�
	{
		return _node->_data;
	}
	ptr operator->()//����_data�Ǹ��Զ�������(eg.�Ǹ��ṹ��)����ָ���Զ������͵���ָͨ��һ����
	{
		return &(_node->_data);//���뷵�ض����ָ�루���ö����ָ�룩****�򷵻��Զ����˼�ͷ�������ĳ����Ķ���
	}

	self& operator++()//����ָͨ��һ��ǰ������
	{
		_node = _node->_next;
		return *this;
	}
	self operator++(int)//����ָͨ��һ����������
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	self& operator--()//����ָͨ��һ��ǰ���Լ�
	{
		_node = _node->_prev;
		return *this;
	}
	self operator--(int)//����ָͨ��һ�������Լ�
	{
		self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	bool operator != (const self& s)
	{
		return _node != s._node;
	}
	bool operator == (const self& s)
	{
		return _node == s._node;
	}
};


//�������Ǵ�ͷ˫��ѭ������
template<class T>
class Mylist
{
	typedef listnode<T> node;
	node* _head;  //ͷ���ָ��

public:
	typedef ListIterator<T, T&, T*> Iterator;   //���typedef��������ڹ����£���static��ͬ
	typedef ListIterator<T, const T&, const T*> ConstIterator;

	typedef ReverseIterator5<Iterator> ReverseIterator;//���������
	typedef ReverseIterator5<ConstIterator> Const_ReverseIterator;

	Mylist()//Ĭ�Ϲ��캯����
		:_head(new node(T()))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
	//�������+��ֵ��������أ�Ҫд����ǳ�������⣩

	//Mylist�ĵ�������begin��end
	Iterator Begin()//���������������Ķ����װ��һ�����ָ��
	{
		return Iterator(_head->_next);
	}
	ConstIterator Begin()const//����Ա�������ؼ��Ǳ��������������޸ĵ������Ķ�������ݳ�Ա��
	{
		return ConstIterator(_head->_next);
	}
	ReverseIterator RBegin()//���������ָ��ĵ�һ��Ԫ��
	{
		return End();
	}
	//Const_ReverseIterator RBegin()const//���������ָ��ĵ�һ��Ԫ��
	//{
	//	return End();
	//}

	Iterator End()
	{
		return Iterator(_head);
	}
	ConstIterator End()const//Ȼ�󳣶���ֻ�ܵ��ó���Ա������
	{
		return ConstIterator(_head);
	}
	ReverseIterator REnd()//���������ָ������һ��Ԫ��
	{
		return Begin();
	}
	//Const_ReverseIterator REnd()const//���������ָ������һ��Ԫ��
	//{
	//	return Begin();
	//}

	//��ɾ ���
	void Pushback(const T& x)
	{
		node *tmp = new node(x);
		_head->_prev->_next = tmp;
		tmp->_prev = _head->_prev;
		tmp->_next = _head;
		_head->_prev = tmp;
	}
	void Pushfront(const T& x)
	{
		node *tmp = new node(x);
		_head->_next->_prev = tmp;
		tmp->_next = _head->_next;
		tmp->_prev = _head;
		_head->_next = tmp;
	}
	void Popback()
	{
		node *tmp = _head->_prev;
		_head->_prev = tmp->_prev;
		tmp->_prev->_next = _head;
		delete tmp;
	}
	void Popfront()
	{
		node *tmp = _head->_next;
		_head->_next = tmp->_next;
		tmp->_next->_prev = _head;
	}

	void Insert(Iterator pos,const T& x)//pos����һ���������Ķ�����������һ�����ָ��
	{
		node *cur = pos._node;
		node *tmp = new node(x);
		cur->_prev->_next = tmp;
		tmp->_prev = cur->_prev;
		tmp->_next = cur;
		cur->_prev = tmp;
	}
	Iterator Erase(Iterator pos)
	{
		assert(pos != End());
		node *prev = (pos._node)->_prev;
		node *next = (pos._node)->_next;
		prev->_next = next;
		next->_prev = prev;
		delete pos._node;
		return Iterator(next);
		//return next;//��ʽ����ת��
	}
	Iterator Erase2(Iterator& pos)//�Ľ�������˵�����ʧЧ������
	{
		assert(pos != End());
		node *prev = (pos._node)->_prev;
		node *next = (pos._node)->_next;
		prev->_next = next;
		next->_prev = prev;
		delete pos._node;
		pos = prev;//�о��е����⡣
		return Iterator(next);
		//return next;//��ʽ����ת��
	}
};