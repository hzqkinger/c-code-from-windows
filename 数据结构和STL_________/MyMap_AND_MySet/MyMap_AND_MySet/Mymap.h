#pragma once

#include"rbtree.h"
//template<K,pair<K,V> >
template<typename K,typename V>
class Map{
	struct KorV{
		const K& operator()(const pair<K,V>& p)
		{
			return p.first;
		}
	};
	typedef RBTree<K, pair<K,V>, KorV> Tree;
public:
	typedef typename Tree::Iterator Iterator;
	typedef typename Tree::Const_Iterator Const_Iterator;
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

	Map(){}
	pair<Iterator, bool> Insert(const pair<K,V>& p)
	{
		return _t.Insert(p);
	}

	//(*((this->insert(make_pair(k, mapped_type()))).first)).second
	V& operator[](const K& key)
	{
		return (Insert(make_pair(key, V())).first)->second;
	}
private:
	Tree _t;
};