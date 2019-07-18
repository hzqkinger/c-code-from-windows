#pragma once
#include<vector>
#include<string>
//③开链法/哈希桶

template<typename V>//哈希结点
struct HashNode{
	V _value;
	HashNode *_next;
	HashNode(const V& v) :_value(v), _next(NULL){}
};

//其实一个哈希函数才是重点中的重点
template<typename K>//哈希仿函数，为了得到整型数
class Hasher{
public:
	const int& operator()(const K& key)
	{
		return key;
	}
};
template<>//模板的特化
class Hasher<string>{
public:
	int operator()(const string& str)
	{
		return str[0];
	}
};

template<typename K, typename V, typename KorV, typename HashFun = Hasher<K>>
class HashTable;//前置声明

template<typename K, typename V, typename ref, typename ptr, typename KorV, typename HashFun = Hasher<V>>
class HashTable_Iterator{
	typedef HashNode<V> Node;
	typedef HashTable<K, V, KorV, HashFun> HashTable;
	typedef HashTable_Iterator<K, V, ref, ptr, KorV, HashFun> self;
public:
	HashTable_Iterator() = default;
	HashTable_Iterator(Node *node, HashTable *ht) :_node(node), _ht(ht){}

	ref operator*()
	{
		return _node->_value;
	}
	ptr operator->()
	{
		return &(_node->_value);
	}
	self& operator++()
	{
		//不用判空，因为++空迭代器本来就应该出错
		if (_node->_next)
			_node = _node->_next;
		else
		{
			KorV _kv;
			size_t i = _ht->HashFunc(_kv(_node->_value));
			for (i += 1; i < _ht->_v.size(); ++i)
			{
				if (_ht->_v[i])break;
			}
			if (i == _ht->_v.size())
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
template<typename K, typename V, typename KorV, typename HashFun = Hasher<K>>
class HashTable{               //KorV的作用是将k或pair<k,v>统一为k;//HashFun的作用是将k转化为一个整型
	typedef HashNode<V> Node;
	typedef HashTable<K, V, KorV, HashFun> self;

	friend HashTable_Iterator<K, V, V&, V*, KorV, HashFun>;//模板友元该怎么声明
	friend HashTable_Iterator<K, V, const V&, const V*, KorV, HashFun>;//模板友元该怎么声明
public:
	typedef HashTable_Iterator<K, V, V&, V*, KorV, HashFun> Iterator;
	typedef HashTable_Iterator<K, V, const V&, const V*, KorV, HashFun> Const_Iterator;
	Iterator Begin()
	{
		for (size_t i = 0; i < _v.size(); ++i)
		if (_v[i])return Iterator(_v[i], this);
	}
	Iterator End()
	{
		return Iterator(NULL, this);
	}
	Const_Iterator CBegin()const
	{
		for (size_t i = 0; i < _v.size(); ++i)
		if (_v[i])return Const_Iterator(_v[i], this);
	}
	Const_Iterator CEnd()const
	{
		return Const_Iterator(NULL, this);
	}

	HashTable() :_size(0){}//默认构造函数

	pair<Iterator, bool> Insert(const V& value)
	{
		checkCapacity();//检查容量是否符合要求
		Iterator tmp; KorV _kv;
		if ((tmp = Find(_kv(value))) != End())
		return make_pair(tmp,false);//检查原哈希表中是否存在key，存在则不插入且返回pair<tmp,false>；

		size_t index = HashFunc(_kv(value));//找到需要插入的索引

		Node *cur = new Node(value);//头插
		cur->_next = _v[index];
		_v[index] = cur;

		++_size;
		return make_pair(Iterator(cur, this), true);
	}
	Iterator Find(const K& key)
	{
		size_t index = HashFunc(key);//先找到那个索引

		Node *cur = _v[index];
		while (cur)
		{
			KorV _kv;
			if (_kv(cur->_value) == key)return Iterator(cur, this);
			else cur = cur->_next;
		}
		return Iterator(NULL, this);
	}
	bool Remove(const K& key)
	{
		size_t index = HashFunc(key);//先找到那个索引
		Node *prev = NULL, *cur = _v[index];
		if (!cur)return false;//假如一开始cur为空就退出

		if (cur->_key == key)//桶里第一个就是要删除的数据
		{
			_v[index] = cur->_next;
			delete cur;
			--_size;
		}
		else//桶里非第一个要删除的数据
		{
			while (cur)
			{
				prev = cur;
				if (cur->_key == key)
				{
					prev->_next = cur->_next;
					delete cur;
					--_size;
					return true;
				}
				cur = cur->_next;
			}
		}

		return false;
	}
	size_t HashFunc(const K& key)//仅仅是将key转化为一个对应的整数
	{
		HashFun _hf;
		return _hf(key) % _v.size();
	}

private:
	vector<Node*> _v;
	size_t _size;//负载因子 = _size / _v.size(); (在这里我们控制平衡因子为1)
	void checkCapacity()
	{
		//1.检查负载因子是否合适 (负载因子 = _size/_v.size()   这里我们设置负载因子为1)
		//2.假如不合适，开新空间，并且移动数据
		if (_size == _v.size())//(1)，因为根据控制，_size < _v.size(),所以当它们相等时说明需要重新开空间
		{
			size_t newsize = _v.size() * 2;//(2)
			if (!newsize)newsize = 10;

			self newht;
			newht._v.resize(newsize);//开空间
			_v.swap(newht._v);
			for (size_t i = 0; i < newht._v.size(); ++i)//移动数据
			{
				if (newht._v[i])//桶子下面挂有数据
				{
					Node *prev = NULL, *cur = newht._v[i];
					while (cur)
					{
						prev = cur;
						KorV _kv;
						size_t index = HashFunc(_kv(newht._v[i]->_value));//计算需要插入的索引
						cur->_next = _v[index];//进行头插
						_v[index] = cur;

						cur = prev->_next;//继续循环
					}
				}
			}

		}
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
	hash.Insert(2);
	hash.Insert(13);
	hash.Insert(22);
	hash.Insert(23);
	hash.Insert(2);
	hash.Insert(15);

	auto it = hash.Begin();
	for (; it != hash.End(); ++it)
	{
		cout << *it << " ";
	}cout << endl;
}