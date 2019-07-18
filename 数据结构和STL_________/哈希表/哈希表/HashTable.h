#pragma once
#include<vector>

namespace one{
	//①闭散列法的线性探测

	enum _state{
		_EMPTY,
		_DELETE,
		_EXIST,
	};
	template<typename K, typename V>
	struct HashNode{
		K _key;
		V _value;
		_state _s;
		HashNode(const K& key = K(), const V& value = V())
			:_key(key), _value(value), _s(_EMPTY)
		{}
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

	template<typename K, typename V, typename HashFunction = Hasher<K>>
	class Hash{
		typedef HashNode<K, V> Node;
	public:
		Hash() :_size(0){}

		bool Insert(const K& key, const V& value)
		{
			CheckCapacity();//检查容量是否符合要求

			if (Find(key))return false;//检查原哈希表中是否存在key，存在则不插入；

			HashFunction _k;//为了得到一个整型数
			int index = _k(key) % _v.size();

			while (_v[index]._s == _EXIST)
			{
				//if (key == _v[index]._key)
				//	return false;
				index = (index + 1) % _v.size();
			}
			_v[index]._key = key;
			_v[index]._value = value;
			_v[index]._s = _EXIST;

			++_size;
			return true;
		}
		bool Erase(const K& key)
		{
			Node *node = Find(key);
			if (node)
			{
				node->_s = _DELETE;
				--_size;
			}
			else return false;
		}
		//哈希表的查找效率与它的长度无关, 只与conflicts有关。就是说对于同一个key来说，
		//  如果conflicts越多，查找效率就越慢。worst case 是O（n），不过这种情况极其少见，
		//  所以正常的查找效率接近O（1）.而且conflicts和查找表的长度无关。
		Node* Find(const K& key)//O(1)
		{
			HashFunction _k;
			int index = _k(key) % _v.size();
			while (_v[index]._s != _EMPTY)
			{
				if (key == _v[index]._key && _v[index]._s == _EXIST)
					return &_v[index];
				index = (index + 1) % _v.size();
			}
			return NULL;
		}

	private:
		vector<Node> _v;
		size_t _size;

		void CheckCapacity()
		{
			if (_v.size() == 0 || _size * 10 / _v.size() >= 7)
			{
				size_t newsize = _v.size() * 2;
				if (!newsize)newsize = 10;

				Hash<K, V> newht;
				newht._v.resize(newsize);
				for (size_t i = 0; i < _v.size(); ++i)
				{
					if (_v[i]._s == _EXIST)
						newht.Insert(_v[i]._key, _v[i]._value);
				}

				_v.swap(newht._v);
			}
		}
	};
}

namespace two{
	//②闭散列法的二次探测

	enum _state{
		_EMPTY,
		_DELETE,
		_EXIST,
	};
	template<typename K, typename V>
	struct HashNode{
		K _key;
		V _value;
		_state _s;
		HashNode(const K& key = K(), const V& value = V())
			:_key(key), _value(value), _s(_EMPTY)
		{}
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


	template<typename K, typename V, typename HashFunction = Hasher<K>>
	class Hash{
		typedef HashNode<K, V> Node;
	public:
		Hash() :_size(0){}

		bool Insert(const K& key, const V& value)
		{
			CheckCapacity();//检查容量是否符合要求

			if (Find(key))return false;//检查原哈希表中是否存在key，存在则不插入；

			HashFunction _k;//为了得到一个整型数
			int index = _k(key) % _v.size();

			size_t i = 1, start = index;               //修改的地方①
			while (_v[index]._s == _EXIST)
			{
				index = (start + i*i) % _v.size();
				++i;
			}
			_v[index]._key = key;
			_v[index]._value = value;
			_v[index]._s = _EXIST;

			++_size;
			return true;
		}
		bool Erase(const K& key)
		{
			Node *node = Find(key);
			if (node)
			{
				node->_s = _DELETE;
				--_size;
			}
			else return false;
		}
		//哈希表的查找效率与它的长度无关, 只与conflicts有关。就是说对于同一个key来说，
		//  如果conflicts越多，查找效率就越慢。worst case 是O（n），不过这种情况极其少见，
		//  所以正常的查找效率接近O（1）.而且conflicts和查找表的长度无关。
		Node* Find(const K& key)//O(1)
		{
			HashFunction _k;
			int index = _k(key) % _v.size();
			size_t i = 1, start = index;         //修改的地方②
			while (_v[index]._s != _EMPTY)
			{
				if (key == _v[index]._key){
					if (_v[index]._s == _EXIST)
						return &_v[index];
					else return NULL;
				}

				index = (start + i*i) % _v.size();
				++i;
			}
			return NULL;
		}

	private:
		vector<Node> _v;
		size_t _size;
		void CheckCapacity()
		{
			if (_v.size() == 0 || _size * 10 / _v.size() >= 7)
			{
				size_t newsize = _v.size() * 2;
				if (!newsize)newsize = 10;

				Hash<K, V> newht;
				newht._v.resize(newsize);
				for (size_t i = 0; i < _v.size(); ++i)
				{
					if (_v[i]._s == _EXIST)
						newht.Insert(_v[i]._key, _v[i]._value);
				}

				_v.swap(newht._v);
			}
		}
	};
}

namespace three{
	//③开链法/哈希桶

	template<typename K,typename V>
	struct HashNode{
		K _key;
		V _value;
		HashNode *_next;
		HashNode(const K& k,const V& v) :_key(k),_value(v), _next(NULL){}
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

	template<typename K,typename V,typename HashFun = Hasher<K>>
	class HashTable{
		typedef HashNode<K,V> Node;
	public:
		HashTable() :_size(0){}

		bool Insert(const K& key,const V& value)
		{
			checkCapacity();//检查容量是否符合要求
			if (Find(key))return false;//检查原哈希表中是否存在key，存在则不插入；

			size_t index = HashFunc(key);//找到需要插入的索引

			Node *cur = new Node(key, value);
			cur->_next = _v[index];
			_v[index] = cur;

			++_size;
			return true;
		}
		Node *Find(const K& key)
		{
			size_t index = HashFunc(key);//先找到那个索引

			Node *cur = _v[index];
			while (cur)
			{
				if (cur->_key == key)return cur;
				else cur = cur->_next;
			}
			return NULL;
		}
		bool Remove(const K& key)
		{
			size_t index = HashFunc(key);//先找到那个索引
			Node *prev = NULL, *cur = _v[index];
			for (; cur;cur = cur->_next )
			{
				if (cur == _v[index] && cur->_key == key)         //桶里第一个就是要删除的数据
				{
					_v[index] = cur->_next;
					break;
				}
				else if (cur->_key != key)//不是需要删除的数据
					prev = cur;
				else                                   //桶里非第一个要删除的数据
				{
					prev->_next = cur->_next;
					break;
				}
			}
			if (cur){delete cur;--_size;return true;}
			return false;

			//if (!cur)return false;//假如一开始cur为空就退出
			//if (cur->_key == key)//桶里第一个就是要删除的数据
			//{
			//	_v[index] = cur->_next;
			//	delete cur;
			//	--_size;
			//	return true;
			//}
			//else//桶里非第一个要删除的数据
			//{
			//	while (cur)
			//	{
			//		prev = cur;
			//		if (cur->_key == key)
			//		{
			//			prev->_next = cur->_next;
			//			delete cur;
			//			--_size;
			//			return true;
			//		}
			//		cur = cur->_next;
			//	}
			//}
			//return false;
		}
		size_t HashFunc(const K& key)//为了得到一个整型
		{
			HashFun _hf;
			return _hf(key) % _v.size();
		}

	private:
		vector<Node*> _v;
		size_t _size;
		void checkCapacity()
		{
			//1.检查负载因子是否合适 (负载因子 = _size/_v.size()   这里我们设置负载因子为1)
			//2.假如不合适，开新空间，并且移动数据
			if (_size == _v.size())//(1)
			{
				size_t newsize = _v.size() * 2;//(2)
				if (!newsize)newsize = 10;

				HashTable<K, V, HashFun> newht;
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

							size_t index = HashFunc(newht._v[i]->_key);//计算需要插入的索引
							cur->_next = _v[index];//进行头插
							_v[index] = cur;

							cur = prev->_next;//继续循环
						}
					}
				}

			}
		}
	};
}


void test_HashTable()
{
	three::HashTable<int, int> h;
	bool flag;
	flag = h.Insert(89, 2);
	flag = h.Insert(18, 2);
	flag = h.Insert(49, 2);
	flag = h.Insert(58, 2);
	flag = h.Insert(9, 2);

	flag = h.Remove(58);
	flag = h.Remove(58);
	flag = h.Remove(9);

	flag = h.Insert(9, 2);
	flag = h.Insert(9, 2);
	flag = h.Insert(58, 2);

	cout << "hah";
}