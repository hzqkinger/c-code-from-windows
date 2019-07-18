#pragma once
#include<assert.h>
#include"Alloc.h"
#include"ReverseIterator.h"

//template<class T, class ref, class ptr>
//struct VectorIterator         //迭代器就是为了方便访问容器里面的数据（迭代器有点像智能指针）
//{//vector的迭代器  (随机迭代器)
//
//	typedef VectorIterator<T, ref, ptr> self;
//	//typedef T Node;
//
//	typedef ref Refence;//使Refence为ref的别名，如果外面要用Refence，就必须通过VectorIterator<T,ref,ptr>或者它的别名来访问
//	typedef ptr Pointer;
//
//	T * _node;       //其实就是迭代器的数据成员_node在指向结点
//
//	VectorIterator(T *node)//构造函数
//		:_node(node)
//	{}
//	//不用写默认的拷贝构造函数+赋值运算符重载函数，因为迭代器的对象要像普通指针一样，默认的就已经满足要求了。
//
//	//要能像普通指针一样能访问链（重载++ -- * -> + += - -= != == > >= < <=）
//	ref operator*()//_data是个普通类型（像指向内置类型的普通指针一样解引用就得到它指向的数据）
//	{
//		return *_node;
//	}
//	ptr operator->()//假如_data是个自定义类型(eg.是个结构体)（像指向自定义类型的普通指针一样）
//	{
//		return &(*_node);//必须返回对象的指针（即该对象的指针）****或返回自定义了箭头运算符的某个类的对象
//	}
//
//	self& operator++()//像普通指针一样前置自增
//	{
//		_node += 1;
//		return *this;
//	}
//	self operator++(int)//像普通指针一样后置自增
//	{
//		self tmp(*this);
//		_node += 1;
//		return tmp;
//	}
//	self& operator--()//像普通指针一样前置自减
//	{
//		_node -= 1;
//		return *this;
//	}
//	self operator--(int)//像普通指针一样后置自减
//	{
//		self tmp(*this);
//		_node -= 1;
//		return tmp;
//	}
//
//	self operator+(int n)
//	{
//		if (n < 0)
//			return _node - (-n);
//
//		return _node + n;
//	}
//	self operator+=(int n)
//	{
//		if (n < 0)
//			return _node -= (-n);
//
//		return _node += n;
//	}
//	self operator-(int n)
//	{
//		if (n < 0)
//			return _node + (-n);
//
//		return _node - n;
//	}
//	int operator-(const self& s)
//	{
//		return _node - s._node;
//	}
//	self operator-=(int n)
//	{
//		if (n < 0)
//			return _node += (-n);
//
//		return _node -= n;
//	}
//
//	bool operator >(const self& s)
//	{
//		return _node > s._node;
//	}
//	bool operator >=(const self& s)
//	{
//		return _node >= s._node;
//	}
//	bool operator <(const self& s)
//	{
//		return _node < s._node;
//	}
//	bool operator <=(const self& s)
//	{
//		return _node <= s._node;
//	}
//
//	bool operator != (const self& s)
//	{
//		return _node != s._node;
//	}
//	bool operator == (const self& s)
//	{
//		return _node == s._node;
//	}
//};

template<class T,class Alloc = alloc5>
class My_vector
{
public:
	//定义内嵌类型
	typedef T ValueType;
	//typedef ptrdiff_t  DifferenceType;
	typedef ValueType* Pointer;
	typedef ValueType& Reference;


	typedef ValueType* Iterator;
	typedef const ValueType* Const_Iterator;
	typedef ReverseIterator6<Iterator> Reverse_Iterator;
	typedef ReverseIterator6<Const_Iterator> Const_Reverse_Iterator;
	////typedef T* Reverse_Iterator;
	////typedef const T* Const_Reverse_Iterator;

	//typedef VectorIterator<T, T&, T*> Iterator;
	//typedef VectorIterator<T, const T&, const T*>  const_Iterator;
	//typedef ReverseIterator5<Iterator> ReverseIterator;//反向迭代器
	//typedef ReverseIterator5<const_Iterator> const_ReverseIterator;

	//一.四个默认成员函数
	//default (1)
	//	explicit vector(const allocator_type& alloc = allocator_type());
	//fill(2)
	//	explicit vector(size_type n, const value_type& val = value_type(),
	//	const allocator_type& alloc = allocator_type());
	//range(3)
	//	template <class InputIterator>
	//vector(InputIterator first, InputIterator last,
	//	const allocator_type& alloc = allocator_type());
	My_vector()//跑过 //（1）
		:_start(0), _finish(0), _end(0)
	{}
	My_vector(size_t n, const T& x = T())//(2)
		:_start(VectorAlloctor::Allocate(n))
		, _finish(_start + n)
		, _end(finish)
	{
		Uninitialized_fill_n(_start, n, x);//向_start指向的空间中填充n个x
	}
	My_vector(Iterator first, Iterator last)//(2)
		:_start(VectorAlloctor::Allocate(last - first))
		, _finish(_start+(last-first))
		, _end(_finish)
	{
		Uninitialized_copy(first, last, _start);//拷贝一段空间内容到另一个空间
	}
	//	vector(const vector& x);拷贝构造函数
	//My_vector(const My_vector<T>& v)//出错 
	//	:_start(VectorAlloctor::Allocate(v.Capacity()))
	//	, _finish(_start + (v._finish - v._start))
	//	, _end(_start + (v._end - v._start))
	//{
	//	Uninitialized_copy(v.Begin(), v.End(), _start);
	//}

	//	vector& operator= (const vector& x);赋值运算符重载函数
	//拷贝构造函数+赋值运算符重载函数
	~My_vector()//跑过 
	{
		Destory(_start, _finish);//调用数组的每个元素的析构函数
		VectorAlloctor::Deallocate(_start,_end - _start);
	}

	//二.My_vector的迭代器的begin和end (该迭代器自动支持随机加减n)
	Iterator Begin()//跑过 
	{
		return _start;
	}
	Iterator End()//跑过 
	{
		return _finish;
	}
	Const_Iterator CBegin()const
	{
		return _start;
	}
	Const_Iterator CEnd()const
	{
		return _finish;
	}

	Reverse_Iterator RBegin()//跑过 
	{
		return End();
	}
	Reverse_Iterator REnd()//跑过 
	{
		return Begin();
	}
	Const_Reverse_Iterator RCBegin()const
	{
		return CEnd();
	}
	Const_Reverse_Iterator RCEnd()const
	{
		return  CBegin();
	}

	//三.(size(); capacity(); empty(); clear(); max_size();)
	size_t Size()const//跑过
	{
		return _finish - _start;
	}
	size_t Capacity()const//跑过
	{
		return _end - _start;
	}
	bool Empty()const//跑过
	{
		return _finish - _start == 0;
	}
	void Clear()//感觉有点问题
	{
		Destory(_start, _finish);//调用数组的每个元素的析构函数
		_finish = _start;
	}

	//四.(resize(); reserve(); )
	void Resize(size_t n, const T& x = T())//Change size 
	{
		//理论上有三种情况：①n<=Size();②Size()<n<=Capacity();③n>Capacity();
		Reserve(n);//这步保证了n一定小于等于Capacity(),就解决了情况③
		if (n <= _finish - _start)
		{
			Destory(_start + n, _finish);//调用析构函数
			_finish = _start + n;
		}
		else
		{
			Uninitialized_fill(_finish, _start + n, x);
			_finish = _start + n;
			//while (_finish < _start + n)
			//{
			//	//*_finish++ = x;
			//	Construct(&*_finish++, x);//调用构造函数
			//}
		}
	}
	void Reserve(size_t n)//空间只会增大不会缩小,Request a change in capacity
	{
		if (n > Capacity())
		{
			Expand(n);
		}
	}

	//五.能像数组一样访问数据
	T& operator[](size_t size)//跑过 //让My_vector的对象像数组一样
	{
		return _start[size];
	}
	const T& operator[](size_t size)const//让My_vector的对象像数组一样
	{
		return _start[size];
	}
	T& At(size_t size)//跑过 //让My_vector的对象像数组一样
	{
		return _start[size];
	}
	const T& At(size_t size)const//让My_vector的对象像数组一样
	{
		return _start[size];
	}
	//reference front();    //const_reference front()const;
	//reference back();     //const_reference back()const;
	T& Front()//跑过
	{
		return _start[0];
	}
	const T& Front()const
	{
		return _start[0];
	}
	T& Back()//跑过
	{
		return _start[Size() - 1];
	}
	const T& Back()const
	{
		return _start[Size() - 1];
	}

	T *Data()//跑过 //返回一个指向数组首元素的指针(c++11及其以后)
	{
		return _start;
	}
	const T *Data()const
	{
		return _start;
	}
	//六.增删   查改

	//range(1)
	//	template <class InputIterator>
	//void assign(InputIterator first, InputIterator last);
	//fill(2)
	//	void assign(size_type n, const value_type& val);
	////////template <class InputIterator>void Assign(InputIterator first, InputIterator last)//[first,last)
	////////{
	////////	size_t n = last - first;
	////////	Reserve(n);//保证空间是足够的
	////////	_finish = _start;
	////////	while (first != last)//重新赋值进去
	////////	{
	////////		//*_finish = *first; //非法间接寻址
	////////		_finish++; first++;
	////////	}
	////////}//出错了
	void Assign(size_t n, const T& x)//跑过 //（2）
	{
		Destory(_start, _finish);//先调用析构函数
		_finish = _start;//再把Size()变为零，注意，Capacity()没变
		Reserve(n);//保证空间是足够的

		Uninitialized_fill_n(_start, n, x);
		_finish = _start + n;
		//while (n--)//重新赋值进去
		//	Construct(&*_finish++, x);
		//	//*_finish++ = x;
	}

	void PushBack(const T& x)//跑过 
	{
		Insert(_finish, x);
	}
	void PopBack()//跑过
	{
		assert(_start != _finish);
		--_finish;
		Destory(_finish);//先调用析构函数
	}
	//single element(1)
	//	iterator insert(iterator position, const value_type& val);
	//fill(2)
	//	void insert(iterator position, size_type n, const value_type& val);
	//range(3)
	//	template <class InputIterator>
	//void insert(iterator position, InputIterator first, InputIterator last);
	Iterator Insert(Iterator pos, const T& x)//跑过 // (1) //需要解决迭代器失效的问题
	{
		assert(pos >= _start && pos <= _finish);
		if (_finish == _end)//假如要增容，那么迭代器会失效
		{
			size_t off = pos - _start;//求pos在原来数组中的偏移量
			size_t capacity = Capacity();
			capacity = capacity > 0 ? capacity * 2 : 3;
			Expand(capacity);
			pos = _start + off;//更新迭代器
		}

		Iterator pos1 = _finish++;
		while (pos1 != pos)
		{
			//*pos1 = *(pos1 - 1);//也要换成全局构造函数
			Construct(&*pos1, *(pos1 - 1));
			pos1--;
		}
		//*pos = x;
		Construct(&*pos, x);//不能用上面的赋值语句给pos指向的那个位置赋值
		return pos;//返回指向新插入的那个元素的迭代器
	}
	void Insert(Iterator pos, size_t n, const T& x)//跑过 //（2）
	{
		assert(pos >= _start && pos <= _finish);
		while (_end - _finish < n)//if需要扩容，需要解决迭代器失效的问题
		{
			size_t off = pos - _start;//求pos在原来数组中的偏移量
			size_t capacity = Capacity();
			capacity = capacity > 0 ? capacity * 2 : 3;
			Expand(capacity);
			pos = _start + off;//更新迭代器
		}

		_finish += n;//调整边界，移动原来的元素
		Iterator pos1 = _finish - 1;
		while (pos1 >= pos + n)
		{
			//*pos1 = *(pos1 - n);
			Construct(&*pos1, *(pos1 - n));
			--pos1;
		}
		while (n--)//插入新数据
			Construct(&*pos++, x);//先立flag，可能会出错
			//*pos++ = x;
	}
	void Insert(Iterator pos, Iterator first, Iterator last)//跑过 //[first,last)
	{
		assert(pos >= _start && pos <= _finish);
		size_t n = last - first;
		while (_end - _finish < n)//if需要扩容，需要解决迭代器失效的问题
		{
			size_t off = pos - _start;//求pos在原来数组中的偏移量
			size_t capacity = Capacity();
			capacity = capacity > 0 ? capacity * 2 : 3;
			Expand(capacity);
			pos = _start + off;//更新迭代器
		}
		_finish += n;//调整边界，移动原来的元素
		Iterator pos1 = _finish - 1;
		while (pos1 >= pos + n)
		{
			//*pos1 = *(pos1 - n);
			Construct(&*pos1, *(pos1 - n));
			--pos1;
		}

		My_vector<T> tmpv(first, last);//必须开辟新空间，因为可能有重叠区域
		Uninitialized_copy(tmpv.Begin(), tmpv.End(), pos);//调用拷贝构造函数
		//My_vector<T>::Iterator it = tmpv.Begin();
		//while (it != tmpv.End())//插入新数据
		//	Construct(&*pos++, *it++);
		//	//*pos++ = *it++;
	}
	//(1)iterator erase(iterator position);
	//(2)iterator erase(iterator first, iterator last);
	Iterator Erase(Iterator pos)//跑过 //(1) //返回一个指向下一个元素的迭代器指针
	{
		assert(pos >= _start && pos < _finish);
		Destory(pos, pos + 1);//先调用析构函数，因为将那个空间可能指向别的空间，比如数组元素是string
		//--_finish;
		//Iterator pos1 = pos;
		//while (pos1 != _finish)
		//{
		//	//*pos1 = *(pos1 + 1);
		//	Construct(&*pos1, *(pos1 + 1));
		//	pos1++;
		//}
		Uninitialized_copy(pos + 1, _finish, pos);//调用拷贝构造函数
		--_finish;
		return pos;
	}
	Iterator Erase(Iterator first, Iterator last)//跑过 //[first,last)
	{
		assert(first >= _start && last <= _finish);
		Destory(first,last);//先调用析构函数，因为将那个空间可能指向别的空间，比如数组元素是string
		size_t n = last - first;
		Uninitialized_copy(last, _finish, first);//调用拷贝构造函数
		//Iterator tmp_first = first;
		//while (last != _finish)
		//	Construct(&*tmp_first++, *last++);
		//	//*tmp_first++ = *last++;
		_finish -= n;

		return first;//返回该删除区域的下一个元素
	}

	//void swap(vector& x);
	void Swap(My_vector<T, Alloc>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_end, v._end);
	}
private:
	T *_start;   //有元素时，指向第一个元素
	T *_finish;  //有元素时，指向最后一个元素的下一个位置
	T *_end;     //有空间大小时，指向空间末尾的下一个位置（即不属于自己的空间）
	typedef SimpleAlloc<T, alloc5> VectorAlloctor;

	void Expand(size_t n)//跑过 //直接开n个空间
	{
		T *newstart =/* new T[n]*/VectorAlloctor::Allocate(n);//使用空间配置器开辟新空间
		Uninitialized_copy(_start, _finish, newstart);//调用构造函数初始化     （讲道理，这里也有类型萃取的问题）
		//size_t size = Size();//这里最好用size记录一下之前存数据个数，因为Size()是一直在变化的
		//for (size_t i = 0; i < size; ++i)//保证拷贝一定正确（深浅拷贝+类型萃取问题）
		//{
		//	//newstart[i] = _start[i];//初始化新空间的数据
		//	Construct(newstart + i, _start[i]);
		//}
		size_t off = _finish - _start;
		Destory(_start, _finish);//调用析构函数
		/*delete[] _start*/VectorAlloctor::Deallocate(_start,_end - _start);//使用空间配置器释放旧空间
		_start = newstart;
		_finish = _start + off;
		_end = _start + n;
	}
	void Expand()//跑过 //空间不够时开辟新空间
	{
		size_t capacity = Capacity();
		if (_finish == _end)
		{
			capacity = capacity > 0 ? capacity * 2 : 3;
			Expand(capacity);
		}
	}
};

template<class T>
void Printvector(const My_vector<T>& v)
{
	typename My_vector<T>::Const_Iterator it = v.CBegin();//注意，在这里必须加typename
	while (it != v.CEnd())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

#include<string>
void test_vector2()
{
	My_vector<string> v;
	v.PushBack("aa1");
	v.PushBack("aa2");
	v.PushBack("aa3");

	v.PushBack("aa4");
	v.PushBack("aa5");
	v.PushBack("aa6");
	v.PushBack("aa7");
	v.PushBack("aa8");

	string s[5] = { "ss1", "ss2", "ss3", "ss4","ss5" };
	My_vector<string>::Iterator it = v.Begin();
	//My_vector<string>::Iterator it2 = v.Begin();

	v.Insert(it + 2, s, s+5);
	//it = v.Begin();                        //原生指针除了支持* -> ++ -- == !=
	//it += 2;                               //           还支持+ += [] > >= < <=
	//cout << (it > it2) << endl;
	//cout << *it << " " << *(it + 5) << " " << it[5] << endl;
	it = v.Begin();
	for (; it != v.End(); ++it)cout << *it << endl;
	cout << endl;
	My_vector<string>::Reverse_Iterator rit = v.RBegin();//反向迭代器
	rit += 2;                      //成功重载+=
	while (rit + 1 != v.REnd())    //成功重载+ 
	{
		cout << *rit << " ";
		++rit;
	}cout << endl << endl;


	v.Assign(3, "aa3");
	it = v.Begin();
	for (; it != v.End(); ++it)
		cout << (*it) << endl;

	//auto ptr = v.Data();
	//for (size_t i = 0; i < v.Size(); ++i)
	//	cout << ptr[i] << " ";
	//cout << endl;

	//cout << v.Empty() <<" "<< v.Size() <<" "<< v.Capacity()<< endl;
	//cout << v[5] << " " << v.At(5) << endl;
	//cout << v.Front() << " "<< v.Back() << endl;

	//it = v.Insert(it, "aa9");
	//v.Erase(it + 3,it + 6);

	//it = v.Begin();


	//My_vector<string> v2 = v;
	//it = v2.Begin();
	//for (; it != v2.End(); ++it)
	//	cout << (*it) << endl;

	//cout << sizeof(string) << endl;
	//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	cout << "haha ";
}
void test_vector()
{
	My_vector<int> v2;
	v2.PushBack(1);
	v2.PushBack(2);
	v2.PushBack(6);
	v2.PushBack(4);
	v2.PushBack(5);
	My_vector<int> v;
	v.Swap(v2);

	cout << endl << endl;
	My_vector<int>::Reverse_Iterator rit = v.RBegin();//反向迭代器
	while (rit != v.REnd())    //vector的反向迭代器没有+ += - -=运算符
	{                          //但是重载了* -> ++ -- > >= < <= == !=
		cout << *rit << " ";
		++rit;
	}cout << endl;

	cout << v.Size() << " " << v.Capacity() << endl;

	Printvector(v);

	My_vector<int>::Iterator it = v.Begin();
	v.Erase(it);
	Printvector(v);
	cout << *it << endl;

	v.Clear();
	v.PushBack(5);
	v.PushBack(5);
	v.PushBack(5);
	v.PushBack(5);
	cout << "size of v0:" << v.Size() << endl;//4
	cout << "capacity of v0:" << v.Capacity() << endl;//6
	cout << "v0 Is empty:" << v.Empty() << endl;

	//四.(resize(); reserve(); )
	//void resize(size_type n,value_type val = value_type());
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	v.Resize(4, 6);//如果n<=size(),这句代码等价于v0.resize(4);
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	v.Resize(11/*,6*/);//如果n>=size()或>=capacity(),
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	//void reserve(size_type n);
	v.Reserve(10);//如果n<=capacity(),那么该句代码无效
	cout << v.Size() << " " << v.Capacity() << endl;

	v.Reserve(18);//如果n>capacity(),那么就会扩容
	cout << v.Size() << " " << v.Capacity() << endl;

	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	//五.能像数组一样访问数据
	//reference operator[](size_type n);//(注意，n一定要小于size() )
	//const_reference operator[](size_type n)const;
	v[10] = 6;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	//reference at(size_type n); //(注意，n一定要小于size() )
	//const_reference at(size_type n)const;
	v.At(9) = 6;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "front:" << v.Front() << " " << "back:" << v.Back() << endl;
	int *p = v.Data();
	*(p + 5) = 6;
	p[6] = 7;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	//六.对数组的修改
	//void assign(size_type n,const value_type& val)//重新赋n个valw
	v.Assign(3, 100);
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	//////////void assign(InputIterator first,InputIterator last)//既可以是迭代器又可以是指针
	////////int arr0[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	////////v.Assign(arr0 + 1, arr0 + 8);//②指针
	////////for (size_t i = 0; i < v.Size(); ++i)
	////////	cout << v[i] << " ";
	////////cout << endl;
	////////cout << v.Size() << " " << v.Capacity() << endl;

	//void push_back(const value_type& val);//尾插
	v.PushBack(11);
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	//void pop_back();//尾删
	v.PopBack();
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	//iterator insert(iterator pos,const value_type& val);//返回的迭代器就指向pos位置
	it = v.Insert(v.Begin() + 2, 100);
	cout << *it << endl;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	//iterator insert(iterator pos,size_type n,const value_type& val);//返回的迭代器就指向pos位置
	v.Insert(v.Begin(), 3, 20);
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	//iterator insert(iterator pos,InputIterator first,InputIterator last);//返回的迭代器就指向pos位置
	v.Insert(v.Begin() + 1, v.Begin() + 1, v.End() - 1);//①迭代器
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	int arr2[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	v.Insert(v.Begin(), arr2 + 1, arr2 + 8);//②指针(指针是天然的迭代器)
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	cout << endl;
	//iterator erase(iterator pos);//删除迭代器pos指向的那一个数据(返回值是相对向后移了一位的迭代器)
	it = v.Erase(v.Begin() + 2);
	cout << *it << " " << *(it + 5) << endl;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	//iterator erase(InputIterator first,InputIterator last);//删除[first,last)区间里的数据
	it = v.Erase(v.Begin() + 2, v.Begin() + 5);
	cout << *it << " " << *(it + 5) << endl;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
}