#pragma once
#include"rbtree.h"

//template<K,K>
template<typename K>
class Set{
	struct KorV{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	typedef RBTree<K, K,KorV> Tree;
public:
	typedef typename Tree::Iterator Iterator;
	typedef typename Tree::Const_Iterator Const_Iterator;
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
	bool Insert(const K& key)
	{
		return _t.Insert(key).second;
	}
private:
	Tree _t;
};