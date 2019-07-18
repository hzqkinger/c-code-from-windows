#pragma once

#include<queue>

template<typename T>struct Nod{
	T _w;
	struct Nod *_left;
	struct Nod *_right;
	Nod(T const& w) :_w(w), _left(NULL), _right(NULL){}
};

template<typename T> class Huffman{
public:
	typedef Nod<T> Node;

	template<typename Nod>struct Greater{        //仿函数，比较结点里面的值域的大小
		bool operator()(Nod const& l, Nod const& r)
		{
			return l->_w > r->_w;
		}
	};

	Huffman() = default;//默认构造函数
	Huffman(T* w,size_t N,T invalue)//传一个数组名和数组的长度进来
	{
		//priority_queue<Node> pq0;//优先级队列默认大根堆   less的意思是孩子小于双亲
		priority_queue<Node*, vector<Node*>, Greater<Node*> > pq;//小根堆，greater的意思是孩子大于双亲
		for (size_t i = 0; i < N; ++i){
			if (w[i] != invalue)
				pq.push(new Node(w[i]));//建立小根堆,压进去是Node*
		}
		_root = CreatTree(pq);
	}
	Node* GetRoot()
	{
		return _root;
	}
private:
	Node *_root;
	Huffman(Huffman<T> const&);//防拷贝
	Huffman<T>& operator=(Huffman<T> const&);//防复制
	Node* CreatTree(priority_queue<Node*, vector<Node*>, Greater<Node*>> &pq)
	{
		while (pq.size() > 1){
			Node *left = pq.top(); pq.pop();
			Node *right = pq.top(); pq.pop();
			Node *parent = new Node(left->_w + right->_w); pq.push(parent);

			parent->_left = left;parent->_right = right;
		}
		return pq.top();
	}
};


void test()
{
	int w[] = { 2, 1, 6, 4, 5, 2, 7, 4 };
	//	priority_queue<int> pq(w, w + sizeof(w) / sizeof(w[0]));
	Huffman<int> h(w,sizeof(w) / sizeof(w[0]),0);//数组向指针的转化
}