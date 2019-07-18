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

template<typename T, typename ref, typename ptr>//��������Ƕ����  ǰ��������������
struct PreBinTh_Iterator
{
	typedef BinaryTreeNode<T> Node;
	typedef  PreBinTh_Iterator<T, ref, ptr> self;

	typedef ref Reference;
	typedef ptr Pointer;

	Node *_node;
	PreBinTh_Iterator(Node *node)//���캯��
		:_node(node)
	{}
	//Ҫ������ָͨ��һ���ܷ�����������++ * -> != ==��

	ref operator*()
	{
		return _node->_data;
	}
	ptr operator->()
	{
		return &(_node->_data);
	}
	self& operator++()//ǰ��++
	{
		if (_node->_leftag == 0){ _node = _node->_left; }
		else{ _node = _node->_right; }

		return *this;
	}
	self operator++(int)//����++
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

template<class T,class ref,class ptr>//��������Ƕ����  ����������������
struct InBinTh_Iterator :public PreBinTh_Iterator<T,ref,ptr>
{
	InBinTh_Iterator(Node *node)//���캯��
	:PreBinTh_Iterator(node)
	{}
	typedef BinaryTreeNode<T> Node;
	typedef InBinTh_Iterator<T, ref, ptr> self;

	self& operator++()//ǰ��++
	{
		if (!_node->_leftag && !_node->_rightag)
		{
			_node = _node->_right;
			while (!_node->_leftag){ _node = _node->_left; }
		}
		else{ _node = _node->_right; }
		return *this;
	}
	self operator++(int)//����++
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

//template<class T, class ref, class ptr>//��������Ƕ����  ����������������
//struct PostBinTh_Iterator :public PreBinTh_Iterator<T, ref, ptr>
//{
//	PostBinTh_Iterator(Node *node)//���캯��
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
	typedef PreBinTh_Iterator<T, T&, T*> PreIterator;                  //ǰ�������
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

	typedef InBinTh_Iterator<T, T&, T*> InIterator;                  //���������
	typedef InBinTh_Iterator<T, const T&, const T*> Const_InIterator;
	InIterator InBegin()
	{
		Node *node = _root;
		while (!node->_leftag)node = node->_left;//һֱ��������������
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

	//typedef PostBinTh_Iterator<T, T&, T*> PostIterator;                  //���������
	//typedef PostBinTh_Iterator<T, const T&, const T*> Const_PostIterator;
	//PostIterator PostBegin(){}
	//PostIterator PostEnd(){}
	//Const_PostIterator PostCBegin()const{}
	//Const_PostIterator PostCEnd()const{}

	BinaryThreading()//Ĭ�Ϲ��캯��          //����һ�ÿ���
		:_root(NULL)
	{}
	BinaryThreading(const T* a,const T& invalid)//����ǿ���
	{
		size_t index = 0;
		_root = _CreatTree(a,invalid, index);
	}
	Node* _CreatTree(const T* a,const T& invalid, size_t&index)
	{
		if (a[index] == invalid)//�ݹ鷽������һ�ö�����
			return NULL;
		Node *node = new Node(a[index]);
		node->_left = _CreatTree(a,invalid, ++index);//�ݹ�������˼��
		node->_right = _CreatTree(a,invalid, ++index);
		return node;
	}

	void PrevOrder_Thr()//ǰ��ݹ�������������
	{
		Node*prev = NULL;
		_PrevOrder_Thr(_root, prev);
		if (prev)//��������һ�ÿ�������ôprev��ֵΪ�գ�����������Ҫ�ж�һ��
			prev->_right = NULL, prev->_rightag = 1;

	}
	void _PrevOrder_Thr(Node* node,Node* &prev)
	{
		if (!node)return;//ע��ǰ���������� ����������ݹ��

		if (!node->_left){ node->_leftag = 1; node->_left = prev; }
		if (prev && !prev->_right){ prev->_rightag = 1; prev->_right = node; }
		prev = node;

		if (!node->_leftag)//ע��ǰ���������� ����������ݹ��,����Ҫ��������ж�����
			_PrevOrder_Thr(node->_left, prev);
		if (!node->_rightag)
			_PrevOrder_Thr(node->_right, prev);
	}
	void PrevOrder_Thr_NonR()//ǰ��ǵݹ�������������
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

				sta.push(cur);//������Ҳ���Է�����ǰ�������棬

				if (cur->_leftag)
					cur = cur->_right;
				else
					cur = cur->_left;
			}
			else
			{
				cur = sta.top();//��һ��һ��Ҫ������ǰ��

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

	void InOrder_Thr()//����ݹ�������������
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
	void InOrder_Thr_NonR()//����ǵݹ�������������
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
			while (!node->_leftag)node = node->_left;//һֱ��������������
			cout << node->_data << " ";
			while (node->_rightag)//һֱ��������������·��(ע���,�øý��ĺ��һֱ����ȥ)
			{
				node = node->_right;
				if (!node){ cout << endl; return; }
				cout << node->_data << " ";
			}
			node = node->_right;//��һ��ѭ���Ŀ�ʼ
		}
		cout << endl;
	}

	void PostOrder_Thr()//����ݹ�������������
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
		while (cur || !sta.empty())//��ÿһ����㶼���������
		{
			while (cur)
			{
				sta.push(cur);
				cur = cur->_left;
			}
			cur = sta.top();
			if ((!cur->_left&&!cur->_right) || (cur->_left == prev &&!cur->_right) || cur->_right == prev)
			{//��Ҷ�ӽ��������ڸ����������������ʹ�

				//cout << cur->_data << " ";//ע�⣬�ܷ���ĳ����㣬��ô˵���������������������ʹ�
				if (!cur->_left){ cur->_left = prev; cur->_leftag = 1; }
				if (prev&&!prev->_right){ prev->_right = cur; prev->_rightag = 1; }
				prev = cur;

				sta.pop();
				cur = NULL;//������������ÿգ�
			}
			else
				cur = cur->_right;
		}
	}
	void Print_postOrder()//�����������������������ǰ������෴��
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

template<class T>//ģ�庯�����õ�������ӡǰ��������������
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

template<class T>//ģ�庯�����õ�������ӡ����������������
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

//�ٶ�����(n�����)��2n��ָ����n-1����֧������n+1����ָ����
void test()
{
	int a1[] = { 1, 2, 3, '#', '#', 4, 40, '#', '#', '#', 5, 6, '#', '#', '#' };
	//int a2[15] = {1,2,'#',3,'#','#',4,5,'#',6,'#',7,'#','#',8};
	BinaryThreading<int> t1(a1, '#');

	//t1.PrevOrder_Thr();//�ݹ�ǰ��������
	//t1.PrevOrder_Thr_NonR();//�ǵݹ�ǰ��������
	//t1.Print_prevOrder();//��ͨǰ������������
	//BinaryThreading<int>::PreIterator it = t1.PreBegin();//������ǰ������������
	//for (; it != t1.PreEnd(); ++it){ cout << *it << " "; }cout << endl;
	//Pre_print(t1);

	t1.InOrder_Thr();//�ݹ�����������
	//t1.InOrder_Thr_NonR();//�ǵݹ�����������
	t1.Print_inOrder();//��ͨ��������������
	BinaryThreading<int>::InIterator it = t1.InBegin();//��������������������
	for (; it != t1.InEnd(); ++it){ cout << *it << " "; }cout << endl;
	In_print(t1);

	//t1.PostOrder_Thr();//�ݹ����������
	//t1._PostOrder_Thr_NonR();//�ǵݹ����������
	//t1.Print_postOrder();
}