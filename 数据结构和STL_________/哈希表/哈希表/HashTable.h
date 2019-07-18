#pragma once
#include<vector>

namespace one{
	//�ٱ�ɢ�з�������̽��

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

	template<typename K, typename V, typename HashFunction = Hasher<K>>
	class Hash{
		typedef HashNode<K, V> Node;
	public:
		Hash() :_size(0){}

		bool Insert(const K& key, const V& value)
		{
			CheckCapacity();//��������Ƿ����Ҫ��

			if (Find(key))return false;//���ԭ��ϣ�����Ƿ����key�������򲻲��룻

			HashFunction _k;//Ϊ�˵õ�һ��������
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
		//��ϣ��Ĳ���Ч�������ĳ����޹�, ֻ��conflicts�йء�����˵����ͬһ��key��˵��
		//  ���conflictsԽ�࣬����Ч�ʾ�Խ����worst case ��O��n��������������������ټ���
		//  ���������Ĳ���Ч�ʽӽ�O��1��.����conflicts�Ͳ��ұ�ĳ����޹ء�
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
	//�ڱ�ɢ�з��Ķ���̽��

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


	template<typename K, typename V, typename HashFunction = Hasher<K>>
	class Hash{
		typedef HashNode<K, V> Node;
	public:
		Hash() :_size(0){}

		bool Insert(const K& key, const V& value)
		{
			CheckCapacity();//��������Ƿ����Ҫ��

			if (Find(key))return false;//���ԭ��ϣ�����Ƿ����key�������򲻲��룻

			HashFunction _k;//Ϊ�˵õ�һ��������
			int index = _k(key) % _v.size();

			size_t i = 1, start = index;               //�޸ĵĵط���
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
		//��ϣ��Ĳ���Ч�������ĳ����޹�, ֻ��conflicts�йء�����˵����ͬһ��key��˵��
		//  ���conflictsԽ�࣬����Ч�ʾ�Խ����worst case ��O��n��������������������ټ���
		//  ���������Ĳ���Ч�ʽӽ�O��1��.����conflicts�Ͳ��ұ�ĳ����޹ء�
		Node* Find(const K& key)//O(1)
		{
			HashFunction _k;
			int index = _k(key) % _v.size();
			size_t i = 1, start = index;         //�޸ĵĵط���
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
	//�ۿ�����/��ϣͰ

	template<typename K,typename V>
	struct HashNode{
		K _key;
		V _value;
		HashNode *_next;
		HashNode(const K& k,const V& v) :_key(k),_value(v), _next(NULL){}
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

	template<typename K,typename V,typename HashFun = Hasher<K>>
	class HashTable{
		typedef HashNode<K,V> Node;
	public:
		HashTable() :_size(0){}

		bool Insert(const K& key,const V& value)
		{
			checkCapacity();//��������Ƿ����Ҫ��
			if (Find(key))return false;//���ԭ��ϣ�����Ƿ����key�������򲻲��룻

			size_t index = HashFunc(key);//�ҵ���Ҫ���������

			Node *cur = new Node(key, value);
			cur->_next = _v[index];
			_v[index] = cur;

			++_size;
			return true;
		}
		Node *Find(const K& key)
		{
			size_t index = HashFunc(key);//���ҵ��Ǹ�����

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
			size_t index = HashFunc(key);//���ҵ��Ǹ�����
			Node *prev = NULL, *cur = _v[index];
			for (; cur;cur = cur->_next )
			{
				if (cur == _v[index] && cur->_key == key)         //Ͱ���һ������Ҫɾ��������
				{
					_v[index] = cur->_next;
					break;
				}
				else if (cur->_key != key)//������Ҫɾ��������
					prev = cur;
				else                                   //Ͱ��ǵ�һ��Ҫɾ��������
				{
					prev->_next = cur->_next;
					break;
				}
			}
			if (cur){delete cur;--_size;return true;}
			return false;

			//if (!cur)return false;//����һ��ʼcurΪ�վ��˳�
			//if (cur->_key == key)//Ͱ���һ������Ҫɾ��������
			//{
			//	_v[index] = cur->_next;
			//	delete cur;
			//	--_size;
			//	return true;
			//}
			//else//Ͱ��ǵ�һ��Ҫɾ��������
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
		size_t HashFunc(const K& key)//Ϊ�˵õ�һ������
		{
			HashFun _hf;
			return _hf(key) % _v.size();
		}

	private:
		vector<Node*> _v;
		size_t _size;
		void checkCapacity()
		{
			//1.��鸺�������Ƿ���� (�������� = _size/_v.size()   �����������ø�������Ϊ1)
			//2.���粻���ʣ����¿ռ䣬�����ƶ�����
			if (_size == _v.size())//(1)
			{
				size_t newsize = _v.size() * 2;//(2)
				if (!newsize)newsize = 10;

				HashTable<K, V, HashFun> newht;
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

							size_t index = HashFunc(newht._v[i]->_key);//������Ҫ���������
							cur->_next = _v[index];//����ͷ��
							_v[index] = cur;

							cur = prev->_next;//����ѭ��
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