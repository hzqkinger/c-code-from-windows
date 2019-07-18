#pragma once
#include"HashTable.h"

//undered_set<k>    HashTable<k,k,KorV,HashFun>
template<typename K,typename HashFun = Hasher<K>>
class Unordered_Set{
	struct KorV{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	typedef HashTable<K, K, KorV, HashFun> HashTable;
public:
	typedef typename HashTable::Iterator Iterator;
	typedef typename HashTable::Const_Iterator Const_Iterator;
	Iterator Begin()
	{
		return _ht.Begin();
	}
	Iterator End()
	{
		return _ht.End();
	}
	Const_Iterator CBegin()const
	{
		return _ht.CBegin();
	}
	Const_Iterator CEnd()const
	{
		return _ht.CEnd();
	}

	bool Insert(const K& key)
	{
		return _ht.Insert(key).second;
	}
	Iterator Find(const K& key)
	{
		return _ht.Find(key);
	}
	bool Remove(const K& key)
	{
		return _ht.Remove(key);
	}
	size_t HashFunc(const K& value)
	{
		return _ht.HashFunc(value);
	}
private:
	HashTable _ht;
};

void test_set()
{
	Unordered_Set<int> us;
	us.Insert(2);
	us.Insert(13);
	us.Insert(22);
	us.Insert(23);
	us.Insert(2);
	us.Insert(15);

	auto it = us.Begin();
	for (; it != us.End(); ++it)
	{
	  cout << *it << " ";
	}cout << endl;

	Unordered_Set<string> us2;
	us2.Insert("insert");
	us2.Insert("map");
	us2.Insert("left");
	us2.Insert("right");
	us2.Insert("insert");
	us2.Insert("fork");

	auto it2 = us2.Begin();
	for (; it2 != us2.End(); ++it2)
	{
	  cout << *it2 << " ";
	}cout << endl;
}