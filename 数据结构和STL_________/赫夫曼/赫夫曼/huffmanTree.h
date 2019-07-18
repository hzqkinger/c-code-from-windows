#pragma once
#include<iostream>
#include<assert.h>
#include"Head.h"
using namespace std;

template<class W>
struct HuffmanTreeNode
{
	HuffmanTreeNode<W>* _left;
	HuffmanTreeNode<W>* _right;
	HuffmanTreeNode<W>* _parent;

	W _w;
	HuffmanTreeNode(const W& w)
		:_w(w)
		, _parent(NULL)
		, _left(NULL)
		, _right(NULL)
	{}

};

template <class W>
class HuffmanTree
{
	typedef HuffmanTreeNode<W> Node;
public:
	HuffmanTree()
		:_root(NULL)
	{}

	HuffmanTree(W* a, size_t n, const W& invalid)
	{
		assert(a);
		struct NodeCompare
		{
			bool operator()(Node *l, Node *r) //仿函数
			{
				return l->_w < r->_w;
			}
		};
		Heap<Node*, NodeCompare> minHeap;//构造结点但是比较的是权值
		for (size_t i = 0; i < n; ++i)
		{
			if (a[i] != invalid)
			{
				minHeap.Push(new Node(a[i]));
			}
		}

		while (minHeap.Size()>1)
		{
			Node* left = minHeap.Top();
			minHeap.Pop();
			Node* right = minHeap.Top();
			minHeap.Pop();
			Node* parent = new Node(left->_w + right->_w);
			parent->_left = left;
			parent->_right = right;

			left->_parent = parent;
			right->_parent = parent;

			minHeap.Push(parent);
		}
		_root = minHeap.Top();
	}
	size_t Size()
	{
		return minHeap.size();
	}

	Node* GetRoot()
	{
		return _root;
	}
private:
	Node* _root;
};