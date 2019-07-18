#pragma once
#include"RBTree.h"
//template<K,pair<K,V> >
template<typename K, typename V>
class Map{
	struct KorV{
		const K& operator()(const pair<K, V>& p)//·Âº¯Êý
		{
			return p.first;
		}
	};
	typedef RBTree<K, pair<K, V>, KorV> Tree;
public:
	typedef typename Tree::Iterator Iterator;
	typedef typename Tree::Const_Iterator Const_Iterator;
	//typedef typename Tree::ReverseIterator ReverseIterator;
	//typedef typename Tree::Const_ReverseIterator Const_ReverseIterator;

	//begin() end()  cbegin()  cend()
	Iterator Begin()
	{
		return _t.Begin();
	}
	Iterator End()
	{
		return _t.End();
	}
	Const_Iterator CBegin()const
	{
		return _t.CBegin();
	}
	Const_Iterator CEnd()const
	{
		return _t.CEnd();
	}
	//rbegin() rend() rcbegin() rcend()
	//ReverseIterator RBegin()
	//{
	//	return _t.RBegin();
	//}
	//ReverseIterator REnd()
	//{
	//	return _t.REnd();
	//}
	//Const_ReverseIterator CRBegin()const
	//{
	//	return _t.CRBegin();
	//}
	//Const_ReverseIterator CREnd()const
	//{
	//	return _t.CREnd();
	//}

	Map(){}

	bool Empty()const
	{
		return _t.Empty();
	}
	size_t Size()const
	{
		return _t.Size();
	}

	pair<Iterator, bool> Insert(const pair<K, V>& p)
	{
		return _t.Insert(p);
	}
	bool Erase(const K& key)
	{
		return _t.Erase(key);
	}

	//(*((this->insert(make_pair(k, mapped_type()))).first)).second
	V& operator[](const K& key)
	{
		return (Insert(make_pair(key, V())).first)->second;
	}

	void Swap(Map<K, V>& mp)
	{
		_t.Swap(mp._t);
	}
	void Clear()
	{
		_t.Clear();
	}
private:
	Tree _t;
};

void test_map()
{
	Map<char, int> mp;
	cout << mp.Empty() << " " << mp.Size() << endl;
	mp.Insert(make_pair('a', 1));
	mp.Insert(make_pair('a', 6));
	mp.Insert(make_pair('b', 2));
	mp.Insert(make_pair('c', 3));
	mp.Insert(make_pair('d', 4));
	mp['e'] = 5;

	mp.Erase('a');
	mp.Erase('a');

	Map<char, int> mp2;
	mp.Swap(mp2);
	cout << mp.Empty() << " " << mp.Size() << endl;
	Map<char, int>::Iterator it = mp.Begin();
	for (; it != mp.End(); ++it)
		cout << it->first << " " << it->second << endl;

	cout << endl;
	cout << mp2.Empty() << " " << mp2.Size() << endl;
	Map<char, int>::Iterator it2 = mp2.Begin();
	for (; it2 != mp2.End(); ++it2)
		cout << it2->first << " " << it2->second << endl;
}