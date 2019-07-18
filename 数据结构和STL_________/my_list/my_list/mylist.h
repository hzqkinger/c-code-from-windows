#pragma once

#include"ReverseIterator.h"

template<class T>
struct listnode   //链表的节点
{
	T _data;
	listnode<T> *_next;
	listnode<T> *_prev;
	listnode(const T& data)
		:_data(data), _next(0), _prev(0)
	{}
};


//假如没有迭代器，而你又没有提供print函数(即使提供也不一定能满足用户的打印需求)
//             如果用户想打印链表里面的数据，就必须知道链表的内部结构(即结点的每个域的名字及作用)
//              这就①增加了使用成本②破坏了封装性
//所以就产生了迭代器这个东西。
template<class T,class ref,class ptr>
struct ListIterator         //迭代器就是为了方便访问容器里面的数据（迭代器有点像智能指针）
{//链表的迭代器

	typedef ListIterator<T, ref, ptr> self;
	typedef listnode<T> Node;

	typedef ref Refence;//使Refence为ref的别名，如果外面要用Refence，就必须通过ListIterator<T,ref,ptr>或者它的别名来访问
	typedef ptr Pointer;

	Node * _node;       //其实就是迭代器的数据成员_node在指向结点

	ListIterator(Node *node)//构造函数
		:_node(node)
	{}
	//不用写默认的拷贝构造函数+赋值运算符重载函数，因为迭代器的对象要像普通指针一样，默认的就已经满足要求了。

	//要能像普通指针一样能访问链（重载++ -- * -> != ==）
	ref operator*()//_data是个普通类型（像指向内置类型的普通指针一样解引用就得到它指向的数据）
	{
		return _node->_data;
	}
	ptr operator->()//假如_data是个自定义类型(eg.是个结构体)（像指向自定义类型的普通指针一样）
	{
		return &(_node->_data);//必须返回对象的指针（即该对象的指针）****或返回自定义了箭头运算符的某个类的对象
	}

	self& operator++()//像普通指针一样前置自增
	{
		_node = _node->_next;
		return *this;
	}
	self operator++(int)//像普通指针一样后置自增
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}
	self& operator--()//像普通指针一样前置自减
	{
		_node = _node->_prev;
		return *this;
	}
	self operator--(int)//像普通指针一样后置自减
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


//该链表是带头双向循环链表
template<class T>
class Mylist
{
	typedef listnode<T> node;
	node* _head;  //头结点指针

public:
	typedef ListIterator<T, T&, T*> Iterator;   //这个typedef还必须放在公有下，跟static不同
	typedef ListIterator<T, const T&, const T*> ConstIterator;

	typedef ReverseIterator5<Iterator> ReverseIterator;//反向迭代器
	typedef ReverseIterator5<ConstIterator> Const_ReverseIterator;

	Mylist()//默认构造函数，
		:_head(new node(T()))
	{
		_head->_next = _head;
		_head->_prev = _head;
	}
	//深拷贝构造+赋值运算符重载（要写，深浅拷贝问题）

	//Mylist的迭代器的begin和end
	Iterator Begin()//迭代器就是让它的对象封装了一个结点指针
	{
		return Iterator(_head->_next);
	}
	ConstIterator Begin()const//常成员函数：关键是编译器不允许它修改调用它的对象的数据成员。
	{
		return ConstIterator(_head->_next);
	}
	ReverseIterator RBegin()//反向迭代器指向的第一个元素
	{
		return End();
	}
	//Const_ReverseIterator RBegin()const//反向迭代器指向的第一个元素
	//{
	//	return End();
	//}

	Iterator End()
	{
		return Iterator(_head);
	}
	ConstIterator End()const//然后常对象只能调用常成员函数。
	{
		return ConstIterator(_head);
	}
	ReverseIterator REnd()//反向迭代器指向的最后一个元素
	{
		return Begin();
	}
	//Const_ReverseIterator REnd()const//反向迭代器指向的最后一个元素
	//{
	//	return Begin();
	//}

	//增删 查改
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

	void Insert(Iterator pos,const T& x)//pos就是一个迭代器的对象，它里面有一个结点指针
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
		//return next;//隐式类型转换
	}
	Iterator Erase2(Iterator& pos)//改进：解决了迭代器失效的问题
	{
		assert(pos != End());
		node *prev = (pos._node)->_prev;
		node *next = (pos._node)->_next;
		prev->_next = next;
		next->_prev = prev;
		delete pos._node;
		pos = prev;//感觉有点问题。
		return Iterator(next);
		//return next;//隐式类型转换
	}
};