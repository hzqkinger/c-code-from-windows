#pragma once
#include"Alloc.h"
#include"Vector.h"
#include<string>
//�ۿ�����/��ϣͰ

template<typename V>//��ϣ���
struct HashNode{
	V _value;
	HashNode *_next;
	HashNode(const V& v) :_value(v), _next(NULL){}
};

//��ʵһ����ϣ���������ص��е��ص�
template<typename K>//��ϣ�º�����Ϊ�˵õ�������
class Hasher{
public:
	const int& operator()(const K& key)
	{
		return key;
	}
};
template<>//ģ����ػ�
class Hasher<string>{
public:
	int operator()(const string& str)
	{
		return str[0];
	}
};

template<typename K, typename V, typename KorV, typename HashFun = Hasher<K>, class Alloc = alloc5>
class HashTable;//ǰ������

template<typename K, typename V, typename ref, typename ptr, typename KorV, typename HashFun = Hasher<V>, class Alloc = alloc5>
class HashTable_Iterator{
	typedef HashNode<V> Node;
	typedef HashTable<K, V, KorV, HashFun,Alloc> HashTable;
	typedef HashTable_Iterator<K, V, ref, ptr, KorV, HashFun, Alloc> self;
public:
	typedef V   ValueType;
	typedef ref Reference;//ʹRefenceΪref�ı������������Ҫ��Refence���ͱ���ͨ��HashTable_Iterator�������ı���������
	typedef ptr Pointer;

	HashTable_Iterator() = default;
	HashTable_Iterator(Node *node, HashTable *ht) :_node(node), _ht(ht){}

	Reference operator*()
	{
		return _node->_value;
	}
	Pointer operator->()
	{
		return &(_node->_value);
	}

	self& operator++()
	{
		//�����пգ���Ϊ++�յ�����������Ӧ�ó���
		if (_node->_next)
			_node = _node->_next;
		else
		{
			KorV _kv;
			size_t i = _ht->HashFunc(_kv(_node->_value));
			for (i += 1; i < _ht->_v.Size(); ++i)
			{
				if (_ht->_v[i])break;
			}
			if (i == _ht->_v.Size())
				_node = NULL;
			else
				_node = _ht->_v[i];
		}
		return *this;
	}
	self operator++(int)
	{
		self tmp(*this);
		++this;
		return tmp;
	}

	bool operator==(const self& se)
	{
		return _node == se._node;
	}
	bool operator!=(const self& se)
	{
		return _node != se._node;
	}
private:
	Node *_node;
	HashTable *_ht;
};

//undered_set<k>    HashTable<k,k,KorV,HashFun>
//undered_map<k,v>  HashTable<k,pair<k,v>,KorV,HashFun>
template<typename K, typename V, typename KorV, typename HashFun = Hasher<K>, class Alloc = alloc5>
class HashTable{               //KorV�������ǽ�k��pair<k,v>ͳһΪk;//HashFun�������ǽ�kת��Ϊһ������
	typedef HashNode<V> Node;
	typedef HashTable<K, V, KorV, HashFun,Alloc> self;
	typedef SimpleAlloc<Node, Alloc> HashTableAllocator;

	friend HashTable_Iterator<K, V, V&, V*, KorV, HashFun, Alloc>;//ģ����Ԫ����ô����
	friend HashTable_Iterator<K, V, const V&, const V*, KorV, HashFun, Alloc>;//ģ����Ԫ����ô����
public:
	typedef HashTable_Iterator<K, V, V&, V*, KorV, HashFun, Alloc> Iterator;//���������
	typedef HashTable_Iterator<K, V, const V&, const V*, KorV, HashFun, Alloc> Const_Iterator;
	//typedef ReverseIterator5<Iterator> ReverseIterator;//���������
	//typedef ReverseIterator5<ConstIterator> Const_ReverseIterator;
	Iterator Begin()
	{
		for (size_t i = 0; i < _v.Size(); ++i)
		if (_v[i])return Iterator(_v[i], this);
	}
	Iterator End()
	{
		return Iterator(NULL, this);
	}
	Const_Iterator CBegin()const
	{
		for (size_t i = 0; i < _v.Size(); ++i)
		if (_v[i])return Const_Iterator(_v[i], this);
	}
	Const_Iterator CEnd()const
	{
		return Const_Iterator(NULL, this);
	}

	HashTable() :_size(0){}//Ĭ�Ϲ��캯��
	//�������캯��+��ֵ��������غ���
	~HashTable()
	{
		//1.�ѹ��ڹ�ϣͰ�ϵĽ���ͷ�
		//2.��Ͱ�ͷ�    //ע�⣬�ͷ�Ͱ���Զ��ģ���Ϊ_v������Լ�����������
		Clear();
	}

	bool Empty()const
	{
		return _size == 0;
	}
	size_t Size()const
	{
		return _size;
	}

	Iterator Find(const K& key)
	{
		size_t index = HashFunc(key);//���ҵ��Ǹ�����

		Node *cur = _v[index];
		while (cur)
		{
			KorV _kv;
			if (_kv(cur->_value) == key)return Iterator(cur, this);
			else cur = cur->_next;
		}
		return Iterator(NULL, this);
	}
	//count(),equal_range()

	pair<Iterator, bool> Insert(const V& value)
	{
		checkCapacity();//��������Ƿ����Ҫ��
		Iterator tmp; KorV _kv;
		if ((tmp = Find(_kv(value))) != End())
			return make_pair(tmp, false);//���ԭ��ϣ�����Ƿ����key�������򲻲����ҷ���pair<tmp,false>��

		size_t index = HashFunc(_kv(value));//�ҵ���Ҫ���������

		//Node *cur = new Node(value);//ͷ��
		Node *cur = BuyNode(value);//ʹ�ÿռ�����������ռ�
		cur->_next = _v[index];
		_v[index] = cur;

		++_size;
		return make_pair(Iterator(cur, this), true);
	}
	bool Remove(const K& key)
	{
		size_t index = HashFunc(key);//���ҵ��Ǹ�����
		Node *prev = NULL, *cur = _v[index];
		if (!cur)return false;//����һ��ʼcurΪ�վ��˳�

		KorV _kv; 
		if (_kv(cur->_value) == key)//Ͱ���һ������Ҫɾ��������
		{
			_v[index] = cur->_next;
			//delete cur;
			FreeNode(cur);//ʹ�ÿռ��������ͷſռ�
			--_size;
		}
		else//Ͱ��ǵ�һ��Ҫɾ��������
		{
			while (cur)
			{
				prev = cur;//�տ�ʼ������ʱ��prevָ���һ��λ�ã���ִ�е��⣬˵����һ��Ԫ�ؾ��Բ�����Ҫɾ���ģ�
				cur = cur->_next;
				if (cur && _kv(cur->_value) == key)
				{
					prev->_next = cur->_next;
					//delete cur;
					FreeNode(cur);//ʹ�ÿռ��������ͷſռ�
					--_size;
					return true;
				}
			}
		}
		return false;
	}

	void Clear()
	{
		//�ѹ��ڹ�ϣͰ�Ľ���ͷ�
		for (size_t i = 0; i < _v.Size(); ++i)
		{
			Node *tmp = _v[i];
			while (tmp)
			{
				Node *next = tmp->_next;
				FreeNode(tmp);//ʹ�ÿռ��������ͷſռ�
				tmp = next;
			}
			_v[i] = NULL;//�����ÿ�
		}
	}
	void Swap(self& s)
	{
		swap(_v, s._v);
		swap(_size, s._size);
	}

	//bucket_count(),bucket_size(),bucket()
	//load_factor(),rehash(),reserve()
	//hash_function(),key_eq(),get_allocator()
private:
	My_vector<Node*> _v;//ʹ���Լ�д��vector
	size_t _size;//�������� = _size / _v.size(); (���������ǿ���ƽ������Ϊ1)
	void checkCapacity()
	{
		//1.��鸺�������Ƿ���� (�������� = _size/_v.size()   �����������ø�������Ϊ1)
		//2.���粻���ʣ����¿ռ䣬�����ƶ�����
		if (_size == _v.Size())//(1)����Ϊ���ݿ��ƣ�_size < _v.size(),���Ե��������ʱ˵����Ҫ���¿��ռ�
		{
			size_t newsize = _v.Size() * 2;//(2)
			if (!newsize)newsize = 10;

			self newht;
			newht._v.Resize(newsize);//���ռ�(�õ����Լ�д��vector����ĺ���)
			_v.Swap(newht._v);
			for (size_t i = 0; i < newht._v.Size(); ++i)//�ƶ�����
			{
				if (newht._v[i])//Ͱ�������������
				{
					Node *prev = NULL, *cur = newht._v[i];
					while (cur)
					{
						prev = cur;
						KorV _kv;
						size_t index = HashFunc(_kv(newht._v[i]->_value));//������Ҫ���������
						cur->_next = _v[index];//����ͷ��
						_v[index] = cur;

						cur = prev->_next;//����ѭ��
					}
				}
			}

		}
	}
	size_t HashFunc(const K& key)//�����ǽ�keyת��Ϊһ����Ӧ������
	{
		HashFun _hf;
		return _hf(key) % _v.Size();
	}
	Node *BuyNode(const V& value)
	{
		Node *nod = HashTableAllocator::Allocate();//1.����ռ�
		nod->_next = NULL;
		Construct(&*(Iterator(nod,this)), value);//2.����nod->_v->_value�Ĺ��캯��
		return nod;
	}
	void FreeNode(Node *nod)
	{
		Destory(&*(Iterator(nod,this)));//1.����nodָ��ռ���������ݵ���������
		HashTableAllocator::Deallocate(nod);//2.�ͷſռ�
	}
};


template<typename K>
struct KorV{
	const K& operator()(const K& key)
	{
		return key;
	}
};
void test_HashTable()
{
	HashTable<int, int, KorV<int> > hash;
	cout << hash.Empty() << " " << hash.Size() << endl;
	hash.Insert(2);
	hash.Insert(13);
	hash.Insert(22);
	hash.Insert(23);
	hash.Insert(2);
	hash.Insert(15);
	cout << hash.Empty() << " " << hash.Size() << endl;

	hash.Remove(2);
	hash.Remove(2);
	cout << hash.Empty() << " " << hash.Size() << endl;

	HashTable<int, int, KorV<int> > hash2;
	hash2.Swap(hash);

	auto it = hash.Begin();
	for (; it != hash.End(); ++it)
	{
		cout << *it << " ";
	}cout << endl;

	auto it2 = hash2.Begin();
	for (; it2 != hash2.End(); ++it2)
	{
		cout << *it2 << " ";
	}cout << endl;
}
void test_HashTable2()
{
	HashTable<string, string, KorV<string> > hash;
	cout << hash.Empty() << " " << hash.Size() << endl;
	hash.Insert("22");
	hash.Insert("1313");
	hash.Insert("2222");
	hash.Insert("2323");
	hash.Insert("22");
	hash.Insert("1515");
	cout << hash.Empty() << " " << hash.Size() << endl;

	hash.Remove("22");
	hash.Remove("22");
	cout << hash.Empty() << " " << hash.Size() << endl;

	HashTable<string, string, KorV<string> > hash2;
	hash2.Swap(hash);

	auto it = hash.Begin();
	for (; it != hash.End(); ++it)
	{
		cout << *it << " ";
	}cout << endl;

	auto it2 = hash2.Begin();
	for (; it2 != hash2.End(); ++it2)
	{
		cout << *it2 << " ";
	}cout << endl;
}