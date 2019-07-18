#pragma once
#include<assert.h>
#include"Alloc.h"
#include"ReverseIterator.h"

//template<class T, class ref, class ptr>
//struct VectorIterator         //����������Ϊ�˷������������������ݣ��������е�������ָ�룩
//{//vector�ĵ�����  (���������)
//
//	typedef VectorIterator<T, ref, ptr> self;
//	//typedef T Node;
//
//	typedef ref Refence;//ʹRefenceΪref�ı������������Ҫ��Refence���ͱ���ͨ��VectorIterator<T,ref,ptr>�������ı���������
//	typedef ptr Pointer;
//
//	T * _node;       //��ʵ���ǵ����������ݳ�Ա_node��ָ����
//
//	VectorIterator(T *node)//���캯��
//		:_node(node)
//	{}
//	//����дĬ�ϵĿ������캯��+��ֵ��������غ�������Ϊ�������Ķ���Ҫ����ָͨ��һ����Ĭ�ϵľ��Ѿ�����Ҫ���ˡ�
//
//	//Ҫ������ָͨ��һ���ܷ�����������++ -- * -> + += - -= != == > >= < <=��
//	ref operator*()//_data�Ǹ���ͨ���ͣ���ָ���������͵���ָͨ��һ�������þ͵õ���ָ������ݣ�
//	{
//		return *_node;
//	}
//	ptr operator->()//����_data�Ǹ��Զ�������(eg.�Ǹ��ṹ��)����ָ���Զ������͵���ָͨ��һ����
//	{
//		return &(*_node);//���뷵�ض����ָ�루���ö����ָ�룩****�򷵻��Զ����˼�ͷ�������ĳ����Ķ���
//	}
//
//	self& operator++()//����ָͨ��һ��ǰ������
//	{
//		_node += 1;
//		return *this;
//	}
//	self operator++(int)//����ָͨ��һ����������
//	{
//		self tmp(*this);
//		_node += 1;
//		return tmp;
//	}
//	self& operator--()//����ָͨ��һ��ǰ���Լ�
//	{
//		_node -= 1;
//		return *this;
//	}
//	self operator--(int)//����ָͨ��һ�������Լ�
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
	//������Ƕ����
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
	//typedef ReverseIterator5<Iterator> ReverseIterator;//���������
	//typedef ReverseIterator5<const_Iterator> const_ReverseIterator;

	//һ.�ĸ�Ĭ�ϳ�Ա����
	//default (1)
	//	explicit vector(const allocator_type& alloc = allocator_type());
	//fill(2)
	//	explicit vector(size_type n, const value_type& val = value_type(),
	//	const allocator_type& alloc = allocator_type());
	//range(3)
	//	template <class InputIterator>
	//vector(InputIterator first, InputIterator last,
	//	const allocator_type& alloc = allocator_type());
	My_vector()//�ܹ� //��1��
		:_start(0), _finish(0), _end(0)
	{}
	My_vector(size_t n, const T& x = T())//(2)
		:_start(VectorAlloctor::Allocate(n))
		, _finish(_start + n)
		, _end(finish)
	{
		Uninitialized_fill_n(_start, n, x);//��_startָ��Ŀռ������n��x
	}
	My_vector(Iterator first, Iterator last)//(2)
		:_start(VectorAlloctor::Allocate(last - first))
		, _finish(_start+(last-first))
		, _end(_finish)
	{
		Uninitialized_copy(first, last, _start);//����һ�οռ����ݵ���һ���ռ�
	}
	//	vector(const vector& x);�������캯��
	//My_vector(const My_vector<T>& v)//���� 
	//	:_start(VectorAlloctor::Allocate(v.Capacity()))
	//	, _finish(_start + (v._finish - v._start))
	//	, _end(_start + (v._end - v._start))
	//{
	//	Uninitialized_copy(v.Begin(), v.End(), _start);
	//}

	//	vector& operator= (const vector& x);��ֵ��������غ���
	//�������캯��+��ֵ��������غ���
	~My_vector()//�ܹ� 
	{
		Destory(_start, _finish);//���������ÿ��Ԫ�ص���������
		VectorAlloctor::Deallocate(_start,_end - _start);
	}

	//��.My_vector�ĵ�������begin��end (�õ������Զ�֧������Ӽ�n)
	Iterator Begin()//�ܹ� 
	{
		return _start;
	}
	Iterator End()//�ܹ� 
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

	Reverse_Iterator RBegin()//�ܹ� 
	{
		return End();
	}
	Reverse_Iterator REnd()//�ܹ� 
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

	//��.(size(); capacity(); empty(); clear(); max_size();)
	size_t Size()const//�ܹ�
	{
		return _finish - _start;
	}
	size_t Capacity()const//�ܹ�
	{
		return _end - _start;
	}
	bool Empty()const//�ܹ�
	{
		return _finish - _start == 0;
	}
	void Clear()//�о��е�����
	{
		Destory(_start, _finish);//���������ÿ��Ԫ�ص���������
		_finish = _start;
	}

	//��.(resize(); reserve(); )
	void Resize(size_t n, const T& x = T())//Change size 
	{
		//�������������������n<=Size();��Size()<n<=Capacity();��n>Capacity();
		Reserve(n);//�ⲽ��֤��nһ��С�ڵ���Capacity(),�ͽ���������
		if (n <= _finish - _start)
		{
			Destory(_start + n, _finish);//������������
			_finish = _start + n;
		}
		else
		{
			Uninitialized_fill(_finish, _start + n, x);
			_finish = _start + n;
			//while (_finish < _start + n)
			//{
			//	//*_finish++ = x;
			//	Construct(&*_finish++, x);//���ù��캯��
			//}
		}
	}
	void Reserve(size_t n)//�ռ�ֻ�����󲻻���С,Request a change in capacity
	{
		if (n > Capacity())
		{
			Expand(n);
		}
	}

	//��.��������һ����������
	T& operator[](size_t size)//�ܹ� //��My_vector�Ķ���������һ��
	{
		return _start[size];
	}
	const T& operator[](size_t size)const//��My_vector�Ķ���������һ��
	{
		return _start[size];
	}
	T& At(size_t size)//�ܹ� //��My_vector�Ķ���������һ��
	{
		return _start[size];
	}
	const T& At(size_t size)const//��My_vector�Ķ���������һ��
	{
		return _start[size];
	}
	//reference front();    //const_reference front()const;
	//reference back();     //const_reference back()const;
	T& Front()//�ܹ�
	{
		return _start[0];
	}
	const T& Front()const
	{
		return _start[0];
	}
	T& Back()//�ܹ�
	{
		return _start[Size() - 1];
	}
	const T& Back()const
	{
		return _start[Size() - 1];
	}

	T *Data()//�ܹ� //����һ��ָ��������Ԫ�ص�ָ��(c++11�����Ժ�)
	{
		return _start;
	}
	const T *Data()const
	{
		return _start;
	}
	//��.��ɾ   ���

	//range(1)
	//	template <class InputIterator>
	//void assign(InputIterator first, InputIterator last);
	//fill(2)
	//	void assign(size_type n, const value_type& val);
	////////template <class InputIterator>void Assign(InputIterator first, InputIterator last)//[first,last)
	////////{
	////////	size_t n = last - first;
	////////	Reserve(n);//��֤�ռ����㹻��
	////////	_finish = _start;
	////////	while (first != last)//���¸�ֵ��ȥ
	////////	{
	////////		//*_finish = *first; //�Ƿ����Ѱַ
	////////		_finish++; first++;
	////////	}
	////////}//������
	void Assign(size_t n, const T& x)//�ܹ� //��2��
	{
		Destory(_start, _finish);//�ȵ�����������
		_finish = _start;//�ٰ�Size()��Ϊ�㣬ע�⣬Capacity()û��
		Reserve(n);//��֤�ռ����㹻��

		Uninitialized_fill_n(_start, n, x);
		_finish = _start + n;
		//while (n--)//���¸�ֵ��ȥ
		//	Construct(&*_finish++, x);
		//	//*_finish++ = x;
	}

	void PushBack(const T& x)//�ܹ� 
	{
		Insert(_finish, x);
	}
	void PopBack()//�ܹ�
	{
		assert(_start != _finish);
		--_finish;
		Destory(_finish);//�ȵ�����������
	}
	//single element(1)
	//	iterator insert(iterator position, const value_type& val);
	//fill(2)
	//	void insert(iterator position, size_type n, const value_type& val);
	//range(3)
	//	template <class InputIterator>
	//void insert(iterator position, InputIterator first, InputIterator last);
	Iterator Insert(Iterator pos, const T& x)//�ܹ� // (1) //��Ҫ���������ʧЧ������
	{
		assert(pos >= _start && pos <= _finish);
		if (_finish == _end)//����Ҫ���ݣ���ô��������ʧЧ
		{
			size_t off = pos - _start;//��pos��ԭ�������е�ƫ����
			size_t capacity = Capacity();
			capacity = capacity > 0 ? capacity * 2 : 3;
			Expand(capacity);
			pos = _start + off;//���µ�����
		}

		Iterator pos1 = _finish++;
		while (pos1 != pos)
		{
			//*pos1 = *(pos1 - 1);//ҲҪ����ȫ�ֹ��캯��
			Construct(&*pos1, *(pos1 - 1));
			pos1--;
		}
		//*pos = x;
		Construct(&*pos, x);//����������ĸ�ֵ����posָ����Ǹ�λ�ø�ֵ
		return pos;//����ָ���²�����Ǹ�Ԫ�صĵ�����
	}
	void Insert(Iterator pos, size_t n, const T& x)//�ܹ� //��2��
	{
		assert(pos >= _start && pos <= _finish);
		while (_end - _finish < n)//if��Ҫ���ݣ���Ҫ���������ʧЧ������
		{
			size_t off = pos - _start;//��pos��ԭ�������е�ƫ����
			size_t capacity = Capacity();
			capacity = capacity > 0 ? capacity * 2 : 3;
			Expand(capacity);
			pos = _start + off;//���µ�����
		}

		_finish += n;//�����߽磬�ƶ�ԭ����Ԫ��
		Iterator pos1 = _finish - 1;
		while (pos1 >= pos + n)
		{
			//*pos1 = *(pos1 - n);
			Construct(&*pos1, *(pos1 - n));
			--pos1;
		}
		while (n--)//����������
			Construct(&*pos++, x);//����flag�����ܻ����
			//*pos++ = x;
	}
	void Insert(Iterator pos, Iterator first, Iterator last)//�ܹ� //[first,last)
	{
		assert(pos >= _start && pos <= _finish);
		size_t n = last - first;
		while (_end - _finish < n)//if��Ҫ���ݣ���Ҫ���������ʧЧ������
		{
			size_t off = pos - _start;//��pos��ԭ�������е�ƫ����
			size_t capacity = Capacity();
			capacity = capacity > 0 ? capacity * 2 : 3;
			Expand(capacity);
			pos = _start + off;//���µ�����
		}
		_finish += n;//�����߽磬�ƶ�ԭ����Ԫ��
		Iterator pos1 = _finish - 1;
		while (pos1 >= pos + n)
		{
			//*pos1 = *(pos1 - n);
			Construct(&*pos1, *(pos1 - n));
			--pos1;
		}

		My_vector<T> tmpv(first, last);//���뿪���¿ռ䣬��Ϊ�������ص�����
		Uninitialized_copy(tmpv.Begin(), tmpv.End(), pos);//���ÿ������캯��
		//My_vector<T>::Iterator it = tmpv.Begin();
		//while (it != tmpv.End())//����������
		//	Construct(&*pos++, *it++);
		//	//*pos++ = *it++;
	}
	//(1)iterator erase(iterator position);
	//(2)iterator erase(iterator first, iterator last);
	Iterator Erase(Iterator pos)//�ܹ� //(1) //����һ��ָ����һ��Ԫ�صĵ�����ָ��
	{
		assert(pos >= _start && pos < _finish);
		Destory(pos, pos + 1);//�ȵ���������������Ϊ���Ǹ��ռ����ָ���Ŀռ䣬��������Ԫ����string
		//--_finish;
		//Iterator pos1 = pos;
		//while (pos1 != _finish)
		//{
		//	//*pos1 = *(pos1 + 1);
		//	Construct(&*pos1, *(pos1 + 1));
		//	pos1++;
		//}
		Uninitialized_copy(pos + 1, _finish, pos);//���ÿ������캯��
		--_finish;
		return pos;
	}
	Iterator Erase(Iterator first, Iterator last)//�ܹ� //[first,last)
	{
		assert(first >= _start && last <= _finish);
		Destory(first,last);//�ȵ���������������Ϊ���Ǹ��ռ����ָ���Ŀռ䣬��������Ԫ����string
		size_t n = last - first;
		Uninitialized_copy(last, _finish, first);//���ÿ������캯��
		//Iterator tmp_first = first;
		//while (last != _finish)
		//	Construct(&*tmp_first++, *last++);
		//	//*tmp_first++ = *last++;
		_finish -= n;

		return first;//���ظ�ɾ���������һ��Ԫ��
	}

	//void swap(vector& x);
	void Swap(My_vector<T, Alloc>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_end, v._end);
	}
private:
	T *_start;   //��Ԫ��ʱ��ָ���һ��Ԫ��
	T *_finish;  //��Ԫ��ʱ��ָ�����һ��Ԫ�ص���һ��λ��
	T *_end;     //�пռ��Сʱ��ָ��ռ�ĩβ����һ��λ�ã����������Լ��Ŀռ䣩
	typedef SimpleAlloc<T, alloc5> VectorAlloctor;

	void Expand(size_t n)//�ܹ� //ֱ�ӿ�n���ռ�
	{
		T *newstart =/* new T[n]*/VectorAlloctor::Allocate(n);//ʹ�ÿռ������������¿ռ�
		Uninitialized_copy(_start, _finish, newstart);//���ù��캯����ʼ��     ������������Ҳ��������ȡ�����⣩
		//size_t size = Size();//���������size��¼һ��֮ǰ�����ݸ�������ΪSize()��һֱ�ڱ仯��
		//for (size_t i = 0; i < size; ++i)//��֤����һ����ȷ����ǳ����+������ȡ���⣩
		//{
		//	//newstart[i] = _start[i];//��ʼ���¿ռ������
		//	Construct(newstart + i, _start[i]);
		//}
		size_t off = _finish - _start;
		Destory(_start, _finish);//������������
		/*delete[] _start*/VectorAlloctor::Deallocate(_start,_end - _start);//ʹ�ÿռ��������ͷžɿռ�
		_start = newstart;
		_finish = _start + off;
		_end = _start + n;
	}
	void Expand()//�ܹ� //�ռ䲻��ʱ�����¿ռ�
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
	typename My_vector<T>::Const_Iterator it = v.CBegin();//ע�⣬����������typename
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
	//it = v.Begin();                        //ԭ��ָ�����֧��* -> ++ -- == !=
	//it += 2;                               //           ��֧��+ += [] > >= < <=
	//cout << (it > it2) << endl;
	//cout << *it << " " << *(it + 5) << " " << it[5] << endl;
	it = v.Begin();
	for (; it != v.End(); ++it)cout << *it << endl;
	cout << endl;
	My_vector<string>::Reverse_Iterator rit = v.RBegin();//���������
	rit += 2;                      //�ɹ�����+=
	while (rit + 1 != v.REnd())    //�ɹ�����+ 
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
	My_vector<int>::Reverse_Iterator rit = v.RBegin();//���������
	while (rit != v.REnd())    //vector�ķ��������û��+ += - -=�����
	{                          //����������* -> ++ -- > >= < <= == !=
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

	//��.(resize(); reserve(); )
	//void resize(size_type n,value_type val = value_type());
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	v.Resize(4, 6);//���n<=size(),������ȼ���v0.resize(4);
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	v.Resize(11/*,6*/);//���n>=size()��>=capacity(),
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	//void reserve(size_type n);
	v.Reserve(10);//���n<=capacity(),��ô�þ������Ч
	cout << v.Size() << " " << v.Capacity() << endl;

	v.Reserve(18);//���n>capacity(),��ô�ͻ�����
	cout << v.Size() << " " << v.Capacity() << endl;

	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	//��.��������һ����������
	//reference operator[](size_type n);//(ע�⣬nһ��ҪС��size() )
	//const_reference operator[](size_type n)const;
	v[10] = 6;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	//reference at(size_type n); //(ע�⣬nһ��ҪС��size() )
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

	//��.��������޸�
	//void assign(size_type n,const value_type& val)//���¸�n��valw
	v.Assign(3, 100);
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	//////////void assign(InputIterator first,InputIterator last)//�ȿ����ǵ������ֿ�����ָ��
	////////int arr0[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	////////v.Assign(arr0 + 1, arr0 + 8);//��ָ��
	////////for (size_t i = 0; i < v.Size(); ++i)
	////////	cout << v[i] << " ";
	////////cout << endl;
	////////cout << v.Size() << " " << v.Capacity() << endl;

	//void push_back(const value_type& val);//β��
	v.PushBack(11);
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	//void pop_back();//βɾ
	v.PopBack();
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	//iterator insert(iterator pos,const value_type& val);//���صĵ�������ָ��posλ��
	it = v.Insert(v.Begin() + 2, 100);
	cout << *it << endl;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	//iterator insert(iterator pos,size_type n,const value_type& val);//���صĵ�������ָ��posλ��
	v.Insert(v.Begin(), 3, 20);
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	//iterator insert(iterator pos,InputIterator first,InputIterator last);//���صĵ�������ָ��posλ��
	v.Insert(v.Begin() + 1, v.Begin() + 1, v.End() - 1);//�ٵ�����
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	int arr2[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	v.Insert(v.Begin(), arr2 + 1, arr2 + 8);//��ָ��(ָ������Ȼ�ĵ�����)
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;

	cout << endl;
	//iterator erase(iterator pos);//ɾ��������posָ�����һ������(����ֵ������������һλ�ĵ�����)
	it = v.Erase(v.Begin() + 2);
	cout << *it << " " << *(it + 5) << endl;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
	//iterator erase(InputIterator first,InputIterator last);//ɾ��[first,last)�����������
	it = v.Erase(v.Begin() + 2, v.Begin() + 5);
	cout << *it << " " << *(it + 5) << endl;
	for (size_t i = 0; i < v.Size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << v.Size() << " " << v.Capacity() << endl;
}