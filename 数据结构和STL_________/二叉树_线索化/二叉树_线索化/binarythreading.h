#pragma once
#include<stack>

template<class T>
struct BinaryTreeNode
{
	int _leftag, _rightag;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	T _data;
	BinaryTreeNode(const T&x)
		:_left(NULL), _right(NULL),_leftag(0),_rightag(0), _data(x)
	{}
};

template<typename T, typename ref, typename ptr>//这属于内嵌类型  前序线索化迭代器
struct PreBinTh_Iterator
{
	typedef BinaryTreeNode<T> Node;
	typedef  PreBinTh_Iterator<T, ref, ptr> self;

	typedef ref Reference;
	typedef ptr Pointer;

	Node *_node;
	PreBinTh_Iterator(Node *node)//构造函数
		:_node(node)
	{}
	//要能像普通指针一样能访问链（重载++ * -> != ==）

	ref operator*()
	{
		return _node->_data;
	}
	ptr operator->()
	{
		return &(_node->_data);
	}
	self& operator++()//前置++
	{
		if (_node->_leftag == 0){ _node = _node->_left; }
		else{ _node = _node->_right; }

		return *this;
	}
	self operator++(int)//后置++
	{
		self temp(*this);
		if (_node->_leftag == 0){ _node = _node->_left; }
		else{ _node = _node->_right; }

		return temp;
	}
	bool operator != (const self& s)
	{
		return _node != s._node;
	}
	bool operator == (const self& s)
	{
		return _node == s._node;
	}
};

template<class T,class ref,class ptr>//这属于内嵌类型  中序线索化迭代器
struct InBinTh_Iterator :public PreBinTh_Iterator<T,ref,ptr>
{
	InBinTh_Iterator(Node *node)//构造函数
	:PreBinTh_Iterator(node)
	{}
	typedef BinaryTreeNode<T> Node;
	typedef InBinTh_Iterator<T, ref, ptr> self;

	self& operator++()//前置++
	{
		if (!_node->_leftag && !_node->_rightag)
		{
			_node = _node->_right;
			while (!_node->_leftag){ _node = _node->_left; }
		}
		else{ _node = _node->_right; }
		return *this;
	}
	self operator++(int)//后置++
	{
		self temp(*this);
		if (!_node->_leftag && !_node->_rightag)
		{
			_node = _node->_right;
			while (!_node->_leftag){ _node = _node->_left; }
		}
		else{ _node = _node->_right; }
		return temp;
	}
};

//template<class T, class ref, class ptr>//这属于内嵌类型  后序线索化迭代器
//struct PostBinTh_Iterator :public PreBinTh_Iterator<T, ref, ptr>
//{
//	PostBinTh_Iterator(Node *node)//构造函数
//	:PreBinTh_Iterator(node)
//	{}
//	typedef BinaryTreeNode<T> Node;
//	typedef PostBinTh_Iterator<T, ref, ptr> self;
//	self operator++(){}
//	self operator++(int){}
//};

template<class T>
class BinaryThreading
{
	typedef BinaryTreeNode<T> Node;
	Node* _root;
public:
	typedef PreBinTh_Iterator<T, T&, T*> PreIterator;                  //前序迭代器
	typedef PreBinTh_Iterator<T, const T&, const T*> Const_PreIterator;
	PreIterator PreBegin()
	{
		return PreIterator(_root);
	}
	PreIterator PreEnd()
	{
		return PreIterator(NULL);
	}
	Const_PreIterator PreCBegin()const
	{
		return Const_PreIterator(_root);
	}
	Const_PreIterator PreCEnd()const
	{
		return Const_PreIterator(NULL);
	}

	typedef InBinTh_Iterator<T, T&, T*> InIterator;                  //中序迭代器
	typedef InBinTh_Iterator<T, const T&, const T*> Const_InIterator;
	InIterator InBegin()
	{
		Node *node = _root;
		while (!node->_leftag)node = node->_left;//一直往左子树方向走
		return InIterator(node);
	}
	InIterator InEnd()
	{
		return InIterator(nullptr);
	}
	Const_InIterator InCBegin()const
	{
		Node *node = _root;
		while (node && node->_left)node = node->_left;
		return Const_InIterator(node);
	}
	Const_InIterator InCEnd()const
	{
		return Const_InIterator(nullptr);
	}

	//typedef PostBinTh_Iterator<T, T&, T*> PostIterator;                  //后序迭代器
	//typedef PostBinTh_Iterator<T, const T&, const T*> Const_PostIterator;
	//PostIterator PostBegin(){}
	//PostIterator PostEnd(){}
	//Const_PostIterator PostCBegin()const{}
	//Const_PostIterator PostCEnd()const{}

	BinaryThreading()//默认构造函数          //构造一棵空树
		:_root(NULL)
	{}
	BinaryThreading(const T* a,const T& invalid)//构造非空树
	{
		size_t index = 0;
		_root = _CreatTree(a,invalid, index);
	}
	Node* _CreatTree(const T* a,const T& invalid, size_t&index)
	{
		if (a[index] == invalid)//递归方法构造一棵二叉树
			return NULL;
		Node *node = new Node(a[index]);
		node->_left = _CreatTree(a,invalid, ++index);//递归子问题思想
		node->_right = _CreatTree(a,invalid, ++index);
		return node;
	}

	void PrevOrder_Thr()//前序递归线索化二叉树
	{
		Node*prev = NULL;
		_PrevOrder_Thr(_root, prev);
		if (prev)//假如这是一棵空树，那么prev的值为空，所以这里需要判断一下
			prev->_right = NULL, prev->_rightag = 1;

	}
	void _PrevOrder_Thr(Node* node,Node* &prev)
	{
		if (!node)return;//注意前序线索化是 先线索化后递归的

		if (!node->_left){ node->_leftag = 1; node->_left = prev; }
		if (prev && !prev->_right){ prev->_rightag = 1; prev->_right = node; }
		prev = node;

		if (!node->_leftag)//注意前序线索化是 先线索化后递归的,所以要在这里加判断条件
			_PrevOrder_Thr(node->_left, prev);
		if (!node->_rightag)
			_PrevOrder_Thr(node->_right, prev);
	}
	void PrevOrder_Thr_NonR()//前序非递归线索化二叉树
	{
		stack<Node*> sta;
		Node* cur = _root, *prev = NULL;
		while (cur || !sta.empty())
		{
			if (cur)
			{
				if (!cur->_left){ cur->_left = prev; cur->_leftag = 1; }
				if (prev&&!prev->_right){ prev->_right = cur; prev->_rightag = 1; }
				prev = cur;

				sta.push(cur);//这句代码也可以放在最前面或最后面，

				if (cur->_leftag)
					cur = cur->_right;
				else
					cur = cur->_left;
			}
			else
			{
				cur = sta.top();//这一步一定要放在最前面

				sta.pop();
				if (cur->_rightag)
					cur = NULL;
				else
					cur = cur->_right;
			}
		}
	}
	void Print_prevOrder()
	{
		Node*node = _root;
		while (node)
		{
			cout << node->_data << " ";
			if (node->_leftag == 0)node = node->_left;
			else node = node->_right;
		}
		cout << endl;
	}

	void InOrder_Thr()//中序递归线索化二叉树
	{
		Node*prev = NULL;
		_InOrder_Thr(_root, prev);
		if (prev)
			prev->_right = NULL, prev->_rightag = 1;
	}
	void _InOrder_Thr(Node*node, Node*&prev)
	{
		if (!node)return;
		_InOrder_Thr(node->_left, prev);

		if (!node->_left){ node->_leftag = 1; node->_left = prev; }
		if (prev && !prev->_right){ prev->_rightag = 1; prev->_right = node; }
		prev = node;

		_InOrder_Thr(node->_right, prev);
	}
	void InOrder_Thr_NonR()//中序非递归线索化二叉树
	{
		stack<Node*> sta;
		Node* cur = _root, *prev = NULL;
		while (cur || !sta.empty())
		{
			if (cur)
			{
				sta.push(cur);
				cur = cur->_left;
			}
			else
			{
				cur = sta.top();
				sta.pop();

				if (!cur->_left){ cur->_left = prev; cur->_leftag = 1; }
				if (prev&&!prev->_right){ prev->_right = cur; prev->_rightag = 1; }
				prev = cur;

				cur = cur->_right;
			}
		}
	}
	void Print_inOrder()
	{
		Node*node = _root;
		while (node)
		{
			while (!node->_leftag)node = node->_left;//一直往左子树方向走
			cout << node->_data << " ";
			while (node->_rightag)//一直走线索化出来的路线(注意点,让该结点的后继一直走下去)
			{
				node = node->_right;
				if (!node){ cout << endl; return; }
				cout << node->_data << " ";
			}
			node = node->_right;//下一个循环的开始
		}
		cout << endl;
	}

	void PostOrder_Thr()//后序递归线索化二叉树
	{
		Node*prev = NULL;
		_PostOrder_Thr(_root, prev);
	}
	void _PostOrder_Thr(Node*node, Node*&prev)
	{
		if (!node)return;
		_PostOrder_Thr(node->_left, prev);
		_PostOrder_Thr(node->_right, prev);

		if (!node->_left){ node->_leftag = 1; node->_left = prev; }
		if (prev && !prev->_right){ prev->_rightag = 1; prev->_right = node; }
		prev = node;
	}
	void _PostOrder_Thr_NonR()
	{
		stack<Node*> sta;
		Node*cur = _root,*prev = NULL;
		while (cur || !sta.empty())//把每一个结点都当做根结点
		{
			while (cur)
			{
				sta.push(cur);
				cur = cur->_left;
			}
			cur = sta.top();
			if ((!cur->_left&&!cur->_right) || (cur->_left == prev &&!cur->_right) || cur->_right == prev)
			{//①叶子结点输出，②根的左右子树都访问过

				//cout << cur->_data << " ";//注意，能访问某个结点，那么说明它的左右子树都被访问过
				if (!cur->_left){ cur->_left = prev; cur->_leftag = 1; }
				if (prev&&!prev->_right){ prev->_right = cur; prev->_rightag = 1; }
				prev = cur;

				sta.pop();
				cur = NULL;//所以这里必须置空，
			}
			else
				cur = cur->_right;
		}
	}
	void Print_postOrder()//后序遍历线索化二叉树（跟前序遍历相反）
	{
		Node*node = _root;
		stack<Node*> sta;
		while (node)
		{
			//cout << node->_data << " ";
			sta.push(node);
			if (node->_rightag == 0)node = node->_right;
			else node = node->_left;
		}
		while (!sta.empty())
		{
			cout << sta.top()->_data << " ";
			sta.pop();
		}
		cout << endl;

	}
};

template<class T>//模板函数，用迭代器打印前序线索化二叉树
void Pre_print(const BinaryThreading<T> &t)
{
	BinaryThreading<int>::Const_PreIterator it = t.PreCBegin();
	while (it != t.PreCEnd())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

template<class T>//模板函数，用迭代器打印中序线索化二叉树
void In_print(const BinaryThreading<T> &t)
{
	BinaryThreading<int>::Const_InIterator it = t.InCBegin();
	while (it != t.InCEnd())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

//①二叉树(n个结点)有2n个指针域，n-1个分支，故有n+1个空指针域
void test()
{
	int a1[] = { 1, 2, 3, '#', '#', 4, 40, '#', '#', '#', 5, 6, '#', '#', '#' };
	//int a2[15] = {1,2,'#',3,'#','#',4,5,'#',6,'#',7,'#','#',8};
	BinaryThreading<int> t1(a1, '#');

	//t1.PrevOrder_Thr();//递归前序线索化
	//t1.PrevOrder_Thr_NonR();//非递归前序线索化
	//t1.Print_prevOrder();//普通前序线索化遍历
	//BinaryThreading<int>::PreIterator it = t1.PreBegin();//迭代器前序线索化遍历
	//for (; it != t1.PreEnd(); ++it){ cout << *it << " "; }cout << endl;
	//Pre_print(t1);

	t1.InOrder_Thr();//递归中序线索化
	//t1.InOrder_Thr_NonR();//非递归中序线索化
	t1.Print_inOrder();//普通中序线索化遍历
	BinaryThreading<int>::InIterator it = t1.InBegin();//迭代器中序线索化遍历
	for (; it != t1.InEnd(); ++it){ cout << *it << " "; }cout << endl;
	In_print(t1);

	//t1.PostOrder_Thr();//递归后序线索化
	//t1._PostOrder_Thr_NonR();//非递归后序线索化
	//t1.Print_postOrder();
}