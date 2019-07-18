#pragma once
#include"RBTree.h"

//template<K,K>
template<typename K>
class Set{
	struct KorV{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	typedef RBTree<K, K, KorV> Tree;
public:
	typedef typename Tree::Iterator Iterator;
	typedef typename Tree::Const_Iterator Const_Iterator;
	//typedef typename Tree::ReverseIterator ReverseIterator;
	//typedef typename Tree::Const_ReverseIterator Const_ReverseIterator;

	// begin()  end()  cbegin()  cend()
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

	Set(){}

	bool Empty()const
	{
		return _t.Empty();
	}
	size_t Size()const
	{
		return _t.Size();
	}

	bool Insert(const K& key)
	{
		return _t.Insert(key).second;
	}
	bool Erase(const K& key)
	{
		return _t.Erase(key);
	}

	void Swap(Set<K>& se)
	{
		_t.Swap(se._t);
	}
	void Clear()
	{
		_t.Clear();
	}
private:
	Tree _t;
};

void test_set()
{
	Set<int> se;
	cout << se.Empty() << " " << se.Size() << endl;
	se.Insert(1);
	se.Insert(2);
	se.Insert(2);
	se.Insert(3);
	se.Insert(4);
	se.Erase(2);
	se.Erase(2);

	Set<int> se2;
	se2.Swap(se);

	cout << se.Empty() << " " << se.Size() << endl;
	Set<int>::Iterator it = se.Begin();
	for (; it != se.End(); ++it)
		cout << *it << " ";
	cout << endl << endl;

	cout << se2.Empty() << " " << se2.Size() << endl;
	Set<int>::Iterator it2 = se2.Begin();
	for (; it2 != se2.End(); ++it2)
		cout << *it2 << " ";
}