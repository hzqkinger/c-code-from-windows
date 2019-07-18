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

	template<typename Nod>struct Greater{        //�º������ȽϽ�������ֵ��Ĵ�С
		bool operator()(Nod const& l, Nod const& r)
		{
			return l->_w > r->_w;
		}
	};

	Huffman() = default;//Ĭ�Ϲ��캯��
	Huffman(T* w,size_t N,T invalue)//��һ��������������ĳ��Ƚ���
	{
		//priority_queue<Node> pq0;//���ȼ�����Ĭ�ϴ����   less����˼�Ǻ���С��˫��
		priority_queue<Node*, vector<Node*>, Greater<Node*> > pq;//С���ѣ�greater����˼�Ǻ��Ӵ���˫��
		for (size_t i = 0; i < N; ++i){
			if (w[i] != invalue)
				pq.push(new Node(w[i]));//����С����,ѹ��ȥ��Node*
		}
		_root = CreatTree(pq);
	}
	Node* GetRoot()
	{
		return _root;
	}
private:
	Node *_root;
	Huffman(Huffman<T> const&);//������
	Huffman<T>& operator=(Huffman<T> const&);//������
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
	Huffman<int> h(w,sizeof(w) / sizeof(w[0]),0);//������ָ���ת��
}