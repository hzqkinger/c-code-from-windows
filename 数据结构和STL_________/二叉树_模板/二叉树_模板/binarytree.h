#pragma once
#include<assert.h>
#include<stack>
#include<queue>

template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	T _data;
	BinaryTreeNode(const T&x)
		:_left(NULL), _right(NULL), _data(x)
	{}
};

template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()                 //����һ�ÿ���
		:_root(NULL)
	{}
	BinaryTree(const T* a, size_t size, const T& invalid)//����ǿ���
	{
		size_t index = 0;
		_root = _CreatTree(a, size, invalid, index);
	}
	Node* _CreatTree(const T* a, size_t size, const T& invalid, size_t& index)
	{
		if (a[index] == invalid)
			return NULL;
		Node *node = new Node(a[index]);
		node->_left = _CreatTree(a, size, invalid, ++index);
		node->_right = _CreatTree(a, size, invalid, ++index);
		return node;
	}
	BinaryTree(const BinaryTree& t)
	{
		_root = _CreatTree(t._root);
	}
	Node* _CreatTree(Node*node)
	{
		if (!node)
			return NULL;
		Node *node2 = new Node(node->_data);
		node2->_left = _CreatTree(node->_left);
		node2->_right = _CreatTree(node->_right);
		return node2;
	}
	BinaryTree& operator=(const BinaryTree& t)
	{
		if (_root != t._root)
			_root = _CreatTree(t._root);
		return *this;
	}
	~BinaryTree()//��û���ԶԲ�����
	{
		_Destory(_root);
	}
	void _Destory(Node*node)
	{
		if (!node)return;
		_CreatTree(node->_left);
	    _CreatTree(node->_right);
		delete node;
	}

	void PrevOrder()//ǰ�����
	{
		_PrevOrder(_root);
		cout << endl;
	}
	void _PrevOrder(Node *node)
	{
		if (!node)
			return;
		cout << node->_data << " ";
		_PrevOrder(node->_left);
		_PrevOrder(node->_right);
	}
	void InOrder()//�������
	{
		_InOrder(_root);
		cout << endl;
	}
	void _InOrder(Node *node)
	{
		if (!node)
			return;
		_InOrder(node->_left);
		cout << node->_data << " ";
		_InOrder(node->_right);
	}
	void PostOrder()//�������
	{
		_PostOrder(_root);
		cout << endl;
	}
	void _PostOrder(Node *node)
	{
		if (!node)
			return;
		_PostOrder(node->_left);
		_PostOrder(node->_right);
		cout << node->_data << " ";
	}
	void LevelOrder()//�������
	{
		queue<Node*> q;
		if (_root)
			q.push(_root);
		while (!q.empty())
		{
			Node*front = q.front();
			cout << front->_data << " ";

			if (front->_left)
				q.push(front->_left);
			if (front->_right)
				q.push(front->_right);
			q.pop();

		}
		cout << endl;
	}
	void levelOrderBottom()
	{
		_levelOrderBottom(_root);
	}
	void _levelOrderBottom(Node* root) {
		vector<vector<int>> v;
		queue<Node*> q;
		int count = 0, tmp = 0, i = 0;
		if (root){ q.push(root); ++count; }

		vector<int> tmpv;
		while (!q.empty())
		{
			Node*front = q.front();
			if (!count){
				++i; count = tmp; tmp = 0;
				v.push_back(tmpv);
				tmpv.clear();
			}
			tmpv.push_back(front->_data);
			--count;

			if (front->_left) { q.push(front->_left); ++tmp; }
			if (front->_right){ q.push(front->_right); ++tmp; }
			q.pop();
		}
		v.push_back(tmpv);
		tmp = 0; i = v.size() - 1;
		while (tmp < i)swap(v[tmp++], v[i--]);

		for (size_t i = 0; i < v.size(); ++i)
		{
			for (size_t j = 0; j < v[i].size(); ++j)
			{
				cout << v[i][j] << " ";
			}
		}cout << endl;
	}

	void PrevOrder_NonR()
	{
		_PrevOrder_NonR(_root);
		_PrevOrder_NonR2(_root);
	}
	void _PrevOrder_NonR(Node*node)//�ǵݹ�ǰ����������ﲻ����ջ��ѹNULLָ�룩
	{
		stack<Node*> s;
		Node*p = node;
		while (p || !s.empty())
		{
			if (p)//��ָ���ջ�����ʸ��ڵ㣬����������
			{
				s.push(p);
				cout << p->_data << " ";
				p = p->_left;
			}
			else//��ָ����ջ������������
			{
				p = s.top();
				s.pop();
				p = p->_right;
			}
		}
		cout << endl;
	}
	void _PrevOrder_NonR2(Node*node)
	{
		stack<Node*> sta;
		Node*p = node;
		while (p || !sta.empty())//��ÿһ����㶼���������������
		{
			while (p)//�������ѹջֱ����Ϊֹ����ý��ⲽѭ����ᵽ��ѭ�����棩
			{
				sta.push(p);
				cout << p->_data << " ";
				p = p->_left;
			}
			p = sta.top();
			sta.pop();
			p = p->_right;
		}
		cout << endl;
	}

	void InOrder_NonR()
	{
		_InOrder_NonR(_root);
		_InOrder_NonR2(_root);

	}
	void _InOrder_NonR(Node*node)
	{
		stack<Node*> s;
		Node*p = node;
		while (p || !s.empty())
		{
			if (p)//��ָ���ջ�����ʸ��ڵ㣬����������
			{
				s.push(p);
				p = p->_left;
			}
			else//��ָ����ջ������������
			{
				p = s.top();
				cout << p->_data << " ";
				s.pop();
				p = p->_right;
			}
		}
		cout << endl;
	}
	void _InOrder_NonR2(Node*node)
	{
		stack<Node*> sta;
		Node*p = node;
		while (p || !sta.empty())
		{
			while (p)
			{
				sta.push(p);
				p = p->_left;
			}
			p = sta.top();
			sta.pop();
			cout << p->_data << " ";
			p = p->_right;
		}
		cout << endl;
	}

	//����1��
	//���ڽڵ�p���Է��������
	//1. p�����Ҷ�ӽڵ㣬ֱ�����
	//2. p����к��ӣ��Һ���û�б����ʹ��������Һ��ӣ����ӵ�˳��������ջ
	//3. p����к��ӣ����Һ��Ӷ��Ѿ����ʹ��������p�ڵ�
	//���ǿ��Ա������һ�����ʵĽڵ�last���������(p->right == NULL && last == p->left) || last = p->right��
	//  ��ô��Ȼp�ĺ��Ӷ����ʹ��ˣ����������Է���p
	//����2��
	//��ʵ����ϣ��ջ�б���ĴӶ���������root->left, root->right, root�������������ᵽ������ʱ��
	//  �ͽ��г�ջ��������һ������ķ����������������ϴ���
	//����ÿ���ڵ㣬��ѹ�����飬��ѭ�����У�ÿ�ε���һ���ڵ㸳��p�����p��Ȼ����ջ��ͷ��㣬
	//  ˵��p�ĺ����ǻ�û�б���������Ӧ�ð����ĺ����Ǽ���ջ�У����򣬷���p��
	//    Ҳ����˵����һ�ε�������p�ĺ���ѹ��ջ�У��ڶ��ε���������p��
	//����3��(�Լ�������ģ����������ˣ���Ϊ����ֻ�����Լ���ѽ)
	void PostOrder_NonR()
	{
		_PostOrder_NonR1(_root);
		_PostOrder_NonR2(_root);
		_PostOrder_NonR3(_root);
	}
	void _PostOrder_NonR1(Node*node)
	{
		stack<Node*> s;
		if (node)s.push(node);
		Node*p = node,*last = node;
		while (!s.empty())
		{
			p = s.top();
			if ((!p->_left&&!p->_right) || (!p->_right&&p->_left == last) || (p->_right == last))
			{ //���ж�p�Ƿ�ΪҶ�ӽ����ж�p�ĺ����Ƿ񶼱����ʹ�
				cout << p->_data << " ";
				last = p;
				s.pop();
			}
			else              //�����Һ��ӣ����ӵ�˳��������ջ
			{
				if (p->_right)
					s.push(p->_right);
				if (p->_left)
					s.push(p->_left);
			}
		}
		cout << endl;
	}
	void _PostOrder_NonR2(Node*node)
	{
		stack<Node*> s;
		Node *p = node;
		if (p)
			s.push(p),s.push(p);
		while (!s.empty())
		{
			p = s.top(); s.pop();
			if (!s.empty() && p == s.top())
			{
				if (p->_right) s.push(p->_right), s.push(p->_right);
				if (p->_left) s.push(p->_left), s.push(p->_left);
			}
			else
				cout << p->_data << " ";
		}
		cout << endl;
	}
	void _PostOrder_NonR3(Node*node)
	{
		stack<Node*> sta;
		Node*cur = node, *last = NULL;
		while (cur || !sta.empty())//��ÿһ����㶼���������
		{
			while (cur)
			{
				sta.push(cur);
				cur = cur->_left;
			}
			cur = sta.top();
			if ((!cur->_left&&!cur->_right) || (cur->_left == last &&!cur->_right) || cur->_right == last)
			{
				last = cur;
				cout << cur->_data << " ";//ע�⣬�ܷ���ĳ����㣬��ô˵���������������������ʹ�
				sta.pop();
				cur = NULL;//������������ÿգ�
			}
			else
				cur = cur->_right;
		}
		cout << endl;
	}

	size_t Size()//������˼��
	{
		return NodeSize(_root);
	}
	size_t NodeSize(Node*node)
	{
		if (!node)
			return 0;
		if (!node->_left&&!node->_right)
			return 1;
		return NodeSize(node->_left) + NodeSize(node->_right) + 1;
	}
	size_t Size2()//����˼��
	{
		size_t size = 0;
		NodeSize2(_root,size);
		return size;
	}
	void NodeSize2(Node*node,size_t& size)
	{
		if (!node)return;
		++size;
		NodeSize2(node->_left,size);
		NodeSize2(node->_right,size);

	}

	size_t LeafSize()//������˼��
	{
		return _LeafSize(_root);
	}
	size_t _LeafSize(Node*node)//�ص㣺��������˼�룬һ�㶼Ҫ�з���ֵ
	{
		if (!node)//�ս��ķ�������
			return 0;
		if (node&&!node->_left&&!node->_right)//Ҷ�ӽ��ķ�������
			return 1;
		return _LeafSize(node->_left) + _LeafSize(node->_right);//����������Ҷ�ӽ�����+��������
	}
	size_t LeafSize2()//����˼��
	{
		size_t size = 0;
		_LeafSize2(_root,size);
		return size;
	}
	void _LeafSize2(Node*node, size_t& size)//ע�⣺����˼��һ����Բ���Ҫ����ֵ��������Ҫһ��������
	{
		if (!node)return;
		if (!node->_left&&!node->_right)
			++size;
		_LeafSize2(node->_left, size);
		_LeafSize2(node->_right, size);
	}

	size_t Depth()
	{
		return _Depth(_root);
	}
	size_t _Depth(Node*node)//������˼�룬����������ȽϺ�
	{
		if (!node)
			return 0;
		size_t lefthigh = _Depth(node->_left);
		size_t righthigh = _Depth(node->_right);

		return lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
	}

	size_t GetKLevel(size_t k)//���k��ڵ���������������˼�룩
	{
		assert(k > 0 && k <= Depth());
		queue<Node*> q;
		size_t size = 0;
		if (_root)
			q.push(_root),size++;

		while (--k&&!q.empty())
		{
			size_t size2 = size;
			while (size2--)
			{
				Node*front = q.front();
				if (front->_left)
					q.push(front->_left), ++size;
				if (front->_right)
					q.push(front->_right), ++size;
				q.pop(), --size;
			}
		}
		return size;
	}
	size_t GetKLevel2(size_t k)//�ݹ�������˼��
	{
		return _GetKLevel2(_root, 2 * k - 2);
	}
	size_t _GetKLevel2(Node* node,size_t k)
	{
		if (!node)return 0;//����÷�֧û�ﵽk�㣬����0��
		if (k == 0)return 1;//ע�⣬������ִ�иþ���룬��ô�÷�֧�ĵ�k��һ����һ�����
		return _GetKLevel2(node->_left, --k) + _GetKLevel2(node->_right, --k);//ע�⣬ִ�������䣬k = k-2;
	}

	bool IsCompleteTree()
	{
		cout<< _IsCompleteTree(_root)<<" ";
		return _IsCompleteTree2(_root);
	}
	bool _IsCompleteTree(Node*node)//�жϸ����ǲ���һ����ȫ������
	{
		queue<Node*> q;
		bool flag = true;
		q.push(node);
		while (!q.empty())//���������˼�룬�������flag���Ͳ���Ҫѹ�ս�������
		{
			Node *front = q.front();
			q.pop();
			
			if (front->_left)
			{
				if (flag == false)return false;
				q.push(front->_left);
			}
			else
				flag = false;//�ٲ��������ǰ���û����������������������ôʣ�µĽ��ض���û�к���
			                 //�ڵ�ǰ���������������ôҲ�ض�Ҫ��������
			if (front->_right)
			{
				if (flag == false)return false;
				q.push(front->_right);
			}
			else
				flag = false;
		}
		return true;
	}
	bool _IsCompleteTree2(Node*node)//���������˼�룬���ѹ�ս������У���ô�Ͳ���Ҫflag
	{
		queue<Node*> q;
		q.push(node);
		Node*front;
		while (front = q.front())
		{
			q.pop();
			if (front)
				q.push(front->_left), q.push(front->_right);
		}
		while (!q.empty())
		{
			front = q.front();
			q.pop();
			if (front)return false;
		}
		return true;
	}

	Node* Find(const T& x)//������˼��
	{
		return _Find(_root, x);
	}
	Node* _Find(Node*node, const T& x)//�ڶ�������Ѱ�ҳ�x���ڵ�λ�ã��ҵ�����ָ���Ǹ�����ָ�룬���򷵻�NULL
	{
		if (!node)return NULL;
		if (node->_data == x)return node;

		return _Find(node->_left, x) || _Find(node->_right, x);
		//Node* ret1 = _Find(node->_left, x);
		//if (ret1)return ret1;
		//Node* ret2 = _Find(node->_right, x);
		//if (ret2)return ret2;
	}

protected:
	Node* _root;
};

void Test1()
{
	int a1[] = { 1, 2, 3, '#', '#', 4, 40, '#', '#', '#', 5, 6, '#', '#', '#' };
	//int a2[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	BinaryTree<int> t1(a1, 10, '#');

	//t1.PrevOrder_NonR();//�ǵݹ����
	//t1.InOrder_NonR();
	//t1.PostOrder_NonR();
	//cout << endl;
	//t1.PrevOrder();//�ݹ����
	//t1.InOrder();
	//t1.PostOrder();
	//t1.LevelOrder();//��α���
	t1.levelOrderBottom();


	//cout << "t1 Size:"<<t1.Size()<<endl;
	//cout << "t1 Size:" << t1.Size2() << endl;
	//cout << "t1 LeafSize:" << t1.LeafSize() << endl;
	//cout << "t1 LeafSize:" << t1.LeafSize2() << endl;
	//cout << "t1 Depth:" << t1.Depth() << endl;
	//cout << " t1 GetKLevel:" << t1.GetKLevel(4) << endl;
	//cout << " t1 GetKLevel2:" << t1.GetKLevel2(4) << endl;
	//cout << t1.Find(4) << endl;
	//cout << t1.IsCompleteTree() << endl;


	//BinaryTree<int> t2(t1);
	//t2.PrevOrder();
	//t2.InOrder();
	//t2.PostOrder();
	//t2.LevelOrder();
	//cout << endl;
	//BinaryTree<int> t3;
	//t3 = t2;
	//t3.PrevOrder();
	//t3.InOrder();
	//t3.PostOrder();
	//t3.LevelOrder();
}