#pragma once
#include<assert.h>
#include"Alloc.h"
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

//void test_list3()
//{
//	struct listnode<string> *next = new listnode<string>("abc");
//	printf("%s\n", *next);
//}

//����û�е�������������û���ṩprint����(��ʹ�ṩҲ��һ���������û��Ĵ�ӡ����)
//             ����û����ӡ������������ݣ��ͱ���֪��������ڲ��ṹ(������ÿ��������ּ�����)
//              ��͢�������ʹ�óɱ����ƻ��˷�װ��
//���ԾͲ����˵��������������
template<class T, class ref, class ptr>
struct ListIterator         //����������Ϊ�˷������������������ݣ��������е�������ָ�룩
{//����ĵ�����
	typedef T   ValueType;
	typedef ref Reference;//ʹRefenceΪref�ı������������Ҫ��Refence���ͱ���ͨ��ListIterator<T,ref,ptr>�������ı���������
	typedef ptr Pointer;

	typedef ListIterator<ValueType, Reference, Pointer> self;
	typedef listnode<ValueType> Node;


	Node * _node;       //��ʵ���ǵ����������ݳ�Ա_node��ָ����

	ListIterator(Node *node)//���캯��
		:_node(node)
	{}
	//����дĬ�ϵĿ������캯��+��ֵ��������غ�������Ϊ�������Ķ���Ҫ����ָͨ��һ����Ĭ�ϵľ��Ѿ�����Ҫ���ˡ�

	//Ҫ������ָͨ��һ���ܷ�����������++ -- * -> != ==��
	Reference operator*()//_data�Ǹ���ͨ���ͣ���ָ���������͵���ָͨ��һ�������þ͵õ���ָ������ݣ�
	{
		return _node->_data;
	}
	Pointer operator->()//����_data�Ǹ��Զ�������(eg.�Ǹ��ṹ��)����ָ���Զ������͵���ָͨ��һ����
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
template<class T,class Alloc = alloc5>
class Mylist
{
	typedef listnode<T> node;
	typedef SimpleAlloc<node, Alloc> ListNodeAllocator;
public:
	typedef ListIterator<T, T&, T*> Iterator;   //���typedef��������ڹ����£���static��ͬ
	typedef ListIterator<T, const T&, const T*> Const_Iterator;

	typedef ReverseIterator5<Iterator> Reverse_Iterator;//���������
	typedef ReverseIterator5<Const_Iterator> Const_Reverse_Iterator;
	//һ.�ĸ�Ĭ�ϳ�Ա����
	//default (1)
	//	explicit list(const allocator_type& alloc = allocator_type());
	//fill(2)
	//	explicit list(size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type());
	//range(3)
	//	template <class InputIterator>list(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type());
	//Mylist()//Ĭ�Ϲ��캯����(1)
	//	:_head(/*new node(T())*/BuyNode())//ʹ�ÿռ����������ٿռ�
	//{
	//	_head->_next = _head;
	//	_head->_prev = _head;
	//}
	Mylist(size_t n = 0, const T& x = T())//��2��
		:_head(/*new node(T())*/BuyNode())//ʹ�ÿռ����������ٿռ�
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
	//////	:_head(/*new node(T())*/ListNodeAllocator::Allocate())//ʹ�ÿռ����������ٿռ�
	//////{
	//////	_head->_next = _head;
	//////	_head->_prev = _head;
	//////	node *cur = _head;
	//////	while (first != last)
	//////	{
	//////		node *next = ListNodeAllocator::Allocate();
	//////		next->_data = *first;//�Ƿ��ļ��Ѱַ
	//////		first++;
	//////		cur->_next = next;
	//////		next->_prev = cur;
	//////		_head->_prev = next;
	//////		next->_next = _head;
	//////		cur = next;
	//////	}
	//////}//������

	//	list(const list& x);
	//list& operator= (const list& x);
	//�������+��ֵ��������أ�Ҫд����ǳ�������⣩
	~Mylist()
	{
		Clear();
		/*delete _head;*/
		//Destory(&*(Iterator(_head)));//����ȫ�ֵ���������,ע��������û��Ҫ���ⲽ����Ϊͷ����_data���������
		ListNodeAllocator::Deallocate(_head);//ʹ�ÿռ����������ͷſռ�
	}

	//��.Mylist�ĵ�������begin��end
	Iterator Begin()//���������������Ķ����װ��һ�����ָ��
	{
		return Iterator(_head->_next);
	}
	Iterator End()
	{
		return Iterator(_head);
	}
	Const_Iterator Begin()const//����Ա�������ؼ��Ǳ��������������޸ĵ������Ķ�������ݳ�Ա��
	{
		return Const_Iterator(_head->_next);
	}
	Const_Iterator End()const//Ȼ�󳣶���ֻ�ܵ��ó���Ա������
	{
		return Const_Iterator(_head);
	}

	Reverse_Iterator RBegin()//���������ָ��ĵ�һ��Ԫ��
	{
		return End();
	}
	Reverse_Iterator REnd()//���������ָ������һ��Ԫ��
	{
		return Begin();
	}
	Const_Reverse_Iterator RBegin()const//���������ָ��ĵ�һ��Ԫ��
	{
		return CEnd();
	}
	Const_Reverse_Iterator REnd()const//���������ָ������һ��Ԫ��
	{
		return CBegin();
	}

	//��.(empty(),size(),front(),back(),,swap(),resize(),clear())
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
	void Resize(size_t n, T x = T())//if n<size(),�ضϵ�n;if n>size(),��ô�ں������x
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
			//Destory(&*(Iterator(next)));//����ȫ�ֵ���������
			//ListNodeAllocator::Deallocate(next);//ʹ�ÿռ��������ͷſռ�
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
			//Destory(&*(Iterator(cur)));//����ȫ�ֵ���������
			//ListNodeAllocator::Deallocate(cur);//ʹ�ÿռ����������ͷſռ�
			cur = next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

	//��.��ɾ    ���
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
	Iterator Insert(Iterator pos, const T& x)//(1) //pos����һ���������Ķ�����������һ�����ָ��
	{
		node *cur = pos._node;
		node *tmp =/* new node(x)*/BuyNode(x);//ʹ�ÿռ�����������ռ�

		cur->_prev->_next = tmp;
		tmp->_prev = cur->_prev;
		tmp->_next = cur;
		cur->_prev = tmp;

		return tmp;//��ʽ����ת��
	}
	void Insert(Iterator pos, size_t n, const T& x)//(2)
	{
		node *cur = pos._node;
		while (n--)
		{
			node *tmp =/* new node(x)*/BuyNode(x);//ʹ�ÿռ�����������ռ�

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
	////////		node *tmp =/* new node(x)*/ListNodeAllocator::Allocate();//ʹ�ÿռ�����������ռ�
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
		FreeNode(pos._node);//ʹ�ÿռ����������ͷſռ�
		return Iterator(next);
		//return next;//��ʽ����ת��
	}
	Iterator Erase(Iterator first, Iterator last)
	{
		assert(IteratorIsIncrement(first, last));//�б�������ǵ�����
		while (first != last)
			first = Erase(first);
		return first;
	}
	Iterator EraseOP(Iterator& pos)//�Ľ�������˵�����ʧЧ������
	{
		assert(pos != End());
		node *prev = (pos._node)->_prev;
		node *next = (pos._node)->_next;
		prev->_next = next;
		next->_prev = prev;
		//delete pos._node;
		FreeNode(pos._node);//ʹ�ÿռ����������ͷſռ�
		pos = prev;//�о��е����⡣
		return Iterator(next);
		//return next;//��ʽ����ת��
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
	node* _head;  //ͷ���ָ��
	bool IteratorIsIncrement(Iterator first, Iterator last)
	{             //����������ǵ�����ϵ����ôfirstһ����������End()
		while (first != last)
		{
			if (first._node == _head)
				return false;
			++first;
		}
		return true;
	}
	node *BuyNode(const T& val = T())//�ú�������ģ��new T(value)�Ĺ���
	{
		node * newnode = ListNodeAllocator::Allocate();//1.���ռ�
		Construct(&*(Iterator(newnode)), val);//���ù��캯��
		return newnode;
	}
	void FreeNode(node *nod)
	{
		Destory(&*(Iterator(nod)));//����ȫ�ֵ���������
		ListNodeAllocator::Deallocate(nod);//ʹ�ÿռ��������ͷſռ�
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

	cout <<"--------------���ǶԳ���---------------------------------------"<<endl;
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
	second.Resize(7);//if n<size(),�ضϵ�n;if n>size(),��ô�ں������val
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