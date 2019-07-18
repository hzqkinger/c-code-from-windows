#pragma once
#include<vector>
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

template<typename K, typename V, typename KorV, typename HashFun = Hasher<K>>
class HashTable;//ǰ������

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
		//�����пգ���Ϊ++�յ�����������Ӧ�ó���
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
class HashTable{               //KorV�������ǽ�k��pair<k,v>ͳһΪk;//HashFun�������ǽ�kת��Ϊһ������
	typedef HashNode<V> Node;
	typedef HashTable<K, V, KorV, HashFun> self;

	friend HashTable_Iterator<K, V, V&, V*, KorV, HashFun>;//ģ����Ԫ����ô����
	friend HashTable_Iterator<K, V, const V&, const V*, KorV, HashFun>;//ģ����Ԫ����ô����
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

	HashTable() :_size(0){}//Ĭ�Ϲ��캯��

	pair<Iterator, bool> Insert(const V& value)
	{
		checkCapacity();//��������Ƿ����Ҫ��
		Iterator tmp; KorV _kv;
		if ((tmp = Find(_kv(value))) != End())
		return make_pair(tmp,false);//���ԭ��ϣ�����Ƿ����key�������򲻲����ҷ���pair<tmp,false>��

		size_t index = HashFunc(_kv(value));//�ҵ���Ҫ���������

		Node *cur = new Node(value);//ͷ��
		cur->_next = _v[index];
		_v[index] = cur;

		++_size;
		return make_pair(Iterator(cur, this), true);
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
	bool Remove(const K& key)
	{
		size_t index = HashFunc(key);//���ҵ��Ǹ�����
		Node *prev = NULL, *cur = _v[index];
		if (!cur)return false;//����һ��ʼcurΪ�վ��˳�

		if (cur->_key == key)//Ͱ���һ������Ҫɾ��������
		{
			_v[index] = cur->_next;
			delete cur;
			--_size;
		}
		else//Ͱ��ǵ�һ��Ҫɾ��������
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
	size_t HashFunc(const K& key)//�����ǽ�keyת��Ϊһ����Ӧ������
	{
		HashFun _hf;
		return _hf(key) % _v.size();
	}

private:
	vector<Node*> _v;
	size_t _size;//�������� = _size / _v.size(); (���������ǿ���ƽ������Ϊ1)
	void checkCapacity()
	{
		//1.��鸺�������Ƿ���� (�������� = _size/_v.size()   �����������ø�������Ϊ1)
		//2.���粻���ʣ����¿ռ䣬�����ƶ�����
		if (_size == _v.size())//(1)����Ϊ���ݿ��ƣ�_size < _v.size(),���Ե��������ʱ˵����Ҫ���¿��ռ�
		{
			size_t newsize = _v.size() * 2;//(2)
			if (!newsize)newsize = 10;

			self newht;
			newht._v.resize(newsize);//���ռ�
			_v.swap(newht._v);
			for (size_t i = 0; i < newht._v.size(); ++i)//�ƶ�����
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