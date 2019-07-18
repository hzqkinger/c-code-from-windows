#pragma once
#include<assert.h>
#include"Alloc.h"
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

//void test_list3()
//{
//	struct listnode<string> *next = new listnode<string>("abc");
//	printf("%s\n", *next);
//}

//假如没有迭代器，而你又没有提供print函数(即使提供也不一定能满足用户的打印需求)
//             如果用户想打印链表里面的数据，就必须知道链表的内部结构(即结点的每个域的名字及作用)
//              这就①增加了使用成本②破坏了封装性
//所以就产生了迭代器这个东西。
template<class T, class ref, class ptr>
struct ListIterator         //迭代器就是为了方便访问容器里面的数据（迭代器有点像智能指针）
{//链表的迭代器
	typedef T   ValueType;
	typedef ref Reference;//使Refence为ref的别名，如果外面要用Refence，就必须通过ListIterator<T,ref,ptr>或者它的别名来访问
	typedef ptr Pointer;

	typedef ListIterator<ValueType, Reference, Pointer> self;
	typedef listnode<ValueType> Node;


	Node * _node;       //其实就是迭代器的数据成员_node在指向结点

	ListIterator(Node *node)//构造函数
		:_node(node)
	{}
	//不用写默认的拷贝构造函数+赋值运算符重载函数，因为迭代器的对象要像普通指针一样，默认的就已经满足要求了。

	//要能像普通指针一样能访问链（重载++ -- * -> != ==）
	Reference operator*()//_data是个普通类型（像指向内置类型的普通指针一样解引用就得到它指向的数据）
	{
		return _node->_data;
	}
	Pointer operator->()//假如_data是个自定义类型(eg.是个结构体)（像指向自定义类型的普通指针一样）
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
template<class T,class Alloc = alloc5>
class Mylist
{
	typedef listnode<T> node;
	typedef SimpleAlloc<node, Alloc> ListNodeAllocator;
public:
	typedef ListIterator<T, T&, T*> Iterator;   //这个typedef还必须放在公有下，跟static相同
	typedef ListIterator<T, const T&, const T*> Const_Iterator;

	typedef ReverseIterator5<Iterator> Reverse_Iterator;//反向迭代器
	typedef ReverseIterator5<Const_Iterator> Const_Reverse_Iterator;
	//一.四个默认成员函数
	//default (1)
	//	explicit list(const allocator_type& alloc = allocator_type());
	//fill(2)
	//	explicit list(size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type());
	//range(3)
	//	template <class InputIterator>list(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type());
	//Mylist()//默认构造函数，(1)
	//	:_head(/*new node(T())*/BuyNode())//使用空间配置器开辟空间
	//{
	//	_head->_next = _head;
	//	_head->_prev = _head;
	//}
	Mylist(size_t n = 0, const T& x = T())//（2）
		:_head(/*new node(T())*/BuyNode())//使用空间配置器开辟空间
	{
		_head->_next = _head;
		_head->_prev = _head;
		node *cur = _head;
		while (n--)
		{
			node *next = BuyNode(x);

			cur->_next = next;
			next->_prev = cur;
			if (n == 0){_head->_prev = next;next->_next = _head;}
			cur = next;
		}
	}
	//////template<class InputIterator>Mylist(InputIterator first, InputIterator last)
	//////	:_head(/*new node(T())*/ListNodeAllocator::Allocate())//使用空间配置器开辟空间
	//////{
	//////	_head->_next = _head;
	//////	_head->_prev = _head;
	//////	node *cur = _head;
	//////	while (first != last)
	//////	{
	//////		node *next = ListNodeAllocator::Allocate();
	//////		next->_data = *first;//非法的间接寻址
	//////		first++;
	//////		cur->_next = next;
	//////		next->_prev = cur;
	//////		_head->_prev = next;
	//////		next->_next = _head;
	//////		cur = next;
	//////	}
	//////}//出错了

	//	list(const list& x);
	//list& operator= (const list& x);
	//深拷贝构造+赋值运算符重载（要写，深浅拷贝问题）
	~Mylist()
	{
		Clear();
		/*delete _head;*/
		//Destory(&*(Iterator(_head)));//调用全局的析构函数,注意在这里没必要做这步，因为头结点的_data是无意义的
		ListNodeAllocator::Deallocate(_head);//使用空间配置器来释放空间
	}

	//二.Mylist的迭代器的begin和end
	Iterator Begin()//迭代器就是让它的对象封装了一个结点指针
	{
		return Iterator(_head->_next);
	}
	Iterator End()
	{
		return Iterator(_head);
	}
	Const_Iterator Begin()const//常成员函数：关键是编译器不允许它修改调用它的对象的数据成员。
	{
		return Const_Iterator(_head->_next);
	}
	Const_Iterator End()const//然后常对象只能调用常成员函数。
	{
		return Const_Iterator(_head);
	}

	Reverse_Iterator RBegin()//反向迭代器指向的第一个元素
	{
		return End();
	}
	Reverse_Iterator REnd()//反向迭代器指向的最后一个元素
	{
		return Begin();
	}
	Const_Reverse_Iterator RBegin()const//反向迭代器指向的第一个元素
	{
		return CEnd();
	}
	Const_Reverse_Iterator REnd()const//反向迭代器指向的最后一个元素
	{
		return CBegin();
	}

	//三.(empty(),size(),front(),back(),,swap(),resize(),clear())
	//bool empty() const;
	//size_type size() const;
	//reference front();   const_reference front() const;
	//reference back();     const_reference back() const;
	bool Empty()const
	{
		return _head->_next == _head;
	}
	size_t Size()const
	{
		size_t count = 0;
		node *cur = _head->_next;
		while (cur != _head)
		{
			++count;
			cur = cur->_next;
		}
		return count;
	}
	T& Front()
	{
		assert(!Empty());
		return _head->_next->_data;
	}
	const T& Front()const
	{
		assert(!Empty());
		return _head->_next->_data;
	}
	T& Back()
	{
		assert(!Empty());
		return _head->_prev->_data;
	}
	const T& Back()const
	{
		assert(!Empty());
		return _head->_prev->_data;
	}
	//void swap(list& x);
	//void resize(size_type n, value_type val = value_type());
	//void clear();
	void Swap(Mylist<T>& li)
	{
		swap(_head, li._head);
	}
	void Resize(size_t n, T x = T())//if n<size(),截断到n;if n>size(),那么在后面添加x
	{
		node *cur = _head;
		while (n--)
		{
			node *next = cur->_next;
			if (next == _head)
			{
				next = BuyNode(x);

				cur->_next = next;
				next->_prev = cur;
				next->_next = _head;
				_head->_prev = next;
			}
			cur = next;
		}
		while (cur->_next != _head)
		{
			node *next = cur->_next;
			cur->_next = next->_next;
			FreeNode(next);
			//Destory(&*(Iterator(next)));//调用全局的析构函数
			//ListNodeAllocator::Deallocate(next);//使用空间配置器释放空间
		}
		_head->_prev = cur;
	}
	void Clear()
	{
		node *cur = _head->_next, *next = NULL;
		while (cur != _head)
		{
			next = cur->_next;
			/*delete cur;*/
			FreeNode(cur);
			//Destory(&*(Iterator(cur)));//调用全局的析构函数
			//ListNodeAllocator::Deallocate(cur);//使用空间配置器来释放空间
			cur = next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

	//四.增删    查改
	//range(1)
	//	template <class InputIterator>void assign(InputIterator first, InputIterator last);
	//fill(2)
	//	void assign(size_type n, const value_type& val);

	//////template <class InputIterator>void Assign(InputIterator first, InputIterator last)
	//////{
	//////	clear();
	//////	while (first != last)
	//////		Pushback(*first++);
	//////}
	void Assign(size_t n, const T& x)
	{
		Clear();
		while (n--)
			Pushback(x);
	}

	//void push_front(const value_type& val); //insert at the begining
	//void pop_front();                       //delete first element
	//void push_back(const value_type& val);  //insert at the begining
	//void pop_back();                        //delete last element
	void Pushback(const T& x)
	{
		node *tmp = BuyNode(x);
		_head->_prev->_next = tmp;
		tmp->_prev = _head->_prev;
		tmp->_next = _head;
		_head->_prev = tmp;
	}
	void Pushfront(const T& x)
	{
		node *tmp = BuyNode(x);
		_head->_next->_prev = tmp;
		tmp->_next = _head->_next;
		tmp->_prev = _head;
		_head->_next = tmp;
	}
	void Popback()
	{
		assert(!Empty());
		node *tmp = _head->_prev;
		_head->_prev = tmp->_prev;
		tmp->_prev->_next = _head;
		//delete tmp;
		FreeNode(tmp);
	}
	void Popfront()
	{
		assert(!Empty());
		node *tmp = _head->_next;
		_head->_next = tmp->_next;
		tmp->_next->_prev = _head;
		//delete tmp;
		FreeNode(tmp);
	}

	//single element(1)
	//	iterator insert(iterator position, const value_type& val);
	//fill(2)
	//	void insert(iterator position, size_type n, const value_type& val);
	//range(3)
	//	template <class InputIterator>void insert(iterator position, InputIterator first, InputIterator last);
	Iterator Insert(Iterator pos, const T& x)//(1) //pos就是一个迭代器的对象，它里面有一个结点指针
	{
		node *cur = pos._node;
		node *tmp =/* new node(x)*/BuyNode(x);//使用空间配置器分配空间

		cur->_prev->_next = tmp;
		tmp->_prev = cur->_prev;
		tmp->_next = cur;
		cur->_prev = tmp;

		return tmp;//隐式类型转换
	}
	void Insert(Iterator pos, size_t n, const T& x)//(2)
	{
		node *cur = pos._node;
		while (n--)
		{
			node *tmp =/* new node(x)*/BuyNode(x);//使用空间配置器分配空间

			cur->_prev->_next = tmp;
			tmp->_prev = cur->_prev;
			tmp->_next = cur;
			cur->_prev = tmp;
		}
	}
	////////template <class InputIterator>void Insert(Iterator pos, InputIterator first, InputIterator last)
	////////{
	////////	node *cur = pos._node;
	////////	while (first != last)
	////////	{
	////////		node *tmp =/* new node(x)*/ListNodeAllocator::Allocate();//使用空间配置器分配空间
	////////		tmp->_data = *first++;
	////////		cur->_prev->_next = tmp;
	////////		tmp->_prev = cur->_prev;
	////////		tmp->_next = cur;
	////////		cur->_prev = tmp;
	////////	}
	////////}

	//(1)iterator erase(iterator position);
	//(2)iterator erase(iterator first, iterator last);
	Iterator Erase(Iterator pos)//(1)
	{
		assert(pos != End());
		node *prev = (pos._node)->_prev;
		node *next = (pos._node)->_next;
		prev->_next = next;
		next->_prev = prev;
		//delete pos._node;
		FreeNode(pos._node);//使用空间配置器来释放空间
		return Iterator(next);
		//return next;//隐式类型转换
	}
	Iterator Erase(Iterator first, Iterator last)
	{
		assert(IteratorIsIncrement(first, last));//判别迭代器是递增的
		while (first != last)
			first = Erase(first);
		return first;
	}
	Iterator EraseOP(Iterator& pos)//改进：解决了迭代器失效的问题
	{
		assert(pos != End());
		node *prev = (pos._node)->_prev;
		node *next = (pos._node)->_next;
		prev->_next = next;
		next->_prev = prev;
		//delete pos._node;
		FreeNode(pos._node);//使用空间配置器来释放空间
		pos = prev;//感觉有点问题。
		return Iterator(next);
		//return next;//隐式类型转换
	}

	////others (splice(),remove(),remove_if(),unique(),merge(),sort(),reverse())
	//entire list(1)            void splice(iterator position, list& x);
 //   single element(2)         void splice(iterator position, list& x, iterator i);
	//element range(3)          void splice(iterator position, list& x, iterator first, iterator last);
	//                          void remove(const value_type& val);
	//template <class Predicate>void remove_if(Predicate pred);
	//(1)                       void unique();
	//2)template <class BinaryPredicate>void unique(BinaryPredicate binary_pred);
	//(1)                       void merge(list& x);
	//(2)template <class Compare>void merge(list& x, Compare comp);
	//(1)void sort();
	//(2)template <class Compare>void sort(Compare comp);
	//                           void reverse();
private:
	node* _head;  //头结点指针
	bool IteratorIsIncrement(Iterator first, Iterator last)
	{             //如果迭代器是递增关系，那么first一定不可能是End()
		while (first != last)
		{
			if (first._node == _head)
				return false;
			++first;
		}
		return true;
	}
	node *BuyNode(const T& val = T())//该函数是在模拟new T(value)的功能
	{
		node * newnode = ListNodeAllocator::Allocate();//1.开空间
		Construct(&*(Iterator(newnode)), val);//调用构造函数
		return newnode;
	}
	void FreeNode(node *nod)
	{
		Destory(&*(Iterator(nod)));//调用全局的析构函数
		ListNodeAllocator::Deallocate(nod);//使用空间配置器释放空间
	}
};
void test_list2()
{
	Mylist<string> first;
	Mylist<string>::Iterator it = first.Begin();
	first.Insert(it,"aa1");
	first.Pushback("aa2");
	first.Pushback("aa3");
	first.Pushback("aa4");
	first.Pushfront("aa0");
	//first.Popback();
	//first.Popfront();
	for (it = first.Begin(); it != first.End(); ++it)
		cout << *it << endl;

	cout <<"--------------我是对称线---------------------------------------"<<endl;
	Mylist<string>::Reverse_Iterator rit = first.RBegin();
	for (; rit != first.REnd(); ++rit)
		cout << *rit << endl;

}

void test_list()
{
	Mylist<int> first;//(1)
	Mylist<int> second(3, 55);//(2)
	////////Mylist<int> third(second.Begin(), second.End());//(3)
	////////int arr[] = { 1, 2, 3, 4, 5 };
	////////Mylist<int> fifth(arr, arr + sizeof(arr) / sizeof(arr[0]));//(3)

	Mylist<int>::Iterator it = second.Begin();
	for (; it != second.End(); ++it){
		cout << *it << " ";
	}cout << endl;

	cout << second.Empty() << endl;
	cout << second.Size() << endl;
	cout << second.Front() << " " << second.Back() << endl;
	second.Clear(); cout << second.Empty() << endl;
	//void resize(size_type n, value_type val = value_type());
	second.Resize(7);//if n<size(),截断到n;if n>size(),那么在后面添加val
	it = second.Begin();
	for (; it != second.End(); ++it){
		cout << *it << " ";
	}cout << endl;

	second.Assign(4, 11);
	it = second.Begin();
	for (; it != second.End(); ++it){
		cout << *it << " ";
	}cout << endl;

	second.Pushback(2);
	second.Pushback(5);
	it = second.Begin();
	for (; it != second.End(); ++it){
		cout << *it << " ";
	}cout << endl;
	second.Popfront();
	it = second.Begin();
	for (; it != second.End(); ++it){
		cout << *it << " ";
	}cout << endl;

	Mylist<int>::Iterator it2 = second.Begin();
	it2++; it2++;
	it = second.Insert(it2, 3);
	cout << *it << " "<<*it2 << endl;
	it = second.Begin();
	for (; it != second.End(); ++it){
		cout << *it << " ";
	}cout << endl;

	second.Insert(it2, 4, 5);
	cout << *it2 << endl;
	it = second.Begin();
	for (; it != second.End(); ++it){
		cout << *it << " ";
	}cout << endl;

	it2 = second.Erase(it2);
	cout << *it2 << endl;
	it = second.Begin();
	for (; it != second.End(); ++it){
		cout << *it << " ";
	}cout << endl;
	it = second.Begin();
	it = second.Erase(it, it2);
	cout << *it << " " << *it2 << endl;
	it = second.Begin();
	for (; it != second.End(); ++it){
		cout << *it << " ";
	}cout << endl;

	Mylist<int>::Reverse_Iterator rit = second.RBegin();
	for (; rit != second.REnd(); ++rit){
		cout << *rit << " ";
	}cout << endl;
}