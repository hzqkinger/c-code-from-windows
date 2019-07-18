#pragma once
#include"HashTable.h"

//undered_map<k,v>  HashTable<k,pair<k,v>,KorV,HashFun>
template<typename K, typename V,typename HashFun = Hasher<K>>
class Unordered_Map{
	struct KorV{
		const K& operator()(const pair<K, V>& p)
		{
			return p.first;
		}
	};


	typedef HashTable<K, pair<K, V>, KorV, HashFun> HashTable;
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

	pair<Iterator,bool> Insert(const pair<K,V>& value)
	{
		return _ht.Insert(value);
	}
	Iterator Find(const K& key)
	{
		return _ht.Find(key);
	}
	bool Remove(const K& key)
	{
		return _ht.Remove(key);
	}
	size_t HashFunc(const V& value)
	{
		return _ht.HashFunc(value);
	}

	V& operator[](const K& key)
	{
		return Insert(make_pair(key, V())).first->second;
	}
private:
	HashTable _ht;
};

void test_map()
{
	Unordered_Map<int, int> ump;
	ump.Insert(make_pair(2,1));
	ump.Insert(make_pair(13, 1));
	ump.Insert(make_pair(22, 1));
	ump.Insert(make_pair(23, 1));
	ump.Insert(make_pair(2, 1));
	ump.Insert(make_pair(15, 1));

	auto it = ump.Begin();
	for (; it != ump.End(); ++it)
	{
		cout << it->first << " ";
	}cout << endl;

	Unordered_Map<string,string> us2;
	us2.Insert(make_pair("insert","²åÈë"));
	us2.Insert(make_pair("map", "¼¯ºÏ"));
	us2.Insert(make_pair("left", "×ó±ß"));
	us2.Insert(make_pair("right", "ÓÒ±ß"));
	us2.Insert(make_pair("insert", "²åÈë"));
	us2.Insert(make_pair("fork", "·ğ¿Æ"));

	us2["left"] = "Ê£Óà";

	auto it2 = us2.Begin();
	for (; it2 != us2.End(); ++it2)
	{
		cout << it2->first << ":" << it2->second << endl;
	}
}