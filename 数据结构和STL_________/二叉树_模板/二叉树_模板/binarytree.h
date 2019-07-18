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
	BinaryTree()                 //构造一棵空树
		:_root(NULL)
	{}
	BinaryTree(const T* a, size_t size, const T& invalid)//构造非空树
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
	~BinaryTree()//还没测试对不对呢
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

	void PrevOrder()//前序遍历
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
	void InOrder()//中序遍历
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
	void PostOrder()//后序遍历
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
	void LevelOrder()//层序遍历
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
	void _PrevOrder_NonR(Node*node)//非递归前序遍历（这里不会向栈里压NULL指针）
	{
		stack<Node*> s;
		Node*p = node;
		while (p || !s.empty())
		{
			if (p)//根指针进栈，访问根节点，遍历左子树
			{
				s.push(p);
				cout << p->_data << " ";
				p = p->_left;
			}
			else//根指针退栈，遍历右子树
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
		while (p || !sta.empty())//将每一个结点都当做根结点来处理
		{
			while (p)//先往左边压栈直到空为止（最好将这步循环归结到大循环里面）
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
			if (p)//根指针进栈，访问根节点，遍历左子树
			{
				s.push(p);
				p = p->_left;
			}
			else//根指针退栈，遍历右子树
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

	//方法1：
	//对于节点p可以分情况讨论
	//1. p如果是叶子节点，直接输出
	//2. p如果有孩子，且孩子没有被访问过，则按照右孩子，左孩子的顺序依次入栈
	//3. p如果有孩子，而且孩子都已经访问过，则访问p节点
	//我们可以保存最后一个访问的节点last，如果满足(p->right == NULL && last == p->left) || last = p->right，
	//  那么显然p的孩子都访问过了，接下来可以访问p
	//方法2：
	//其实我们希望栈中保存的从顶部依次是root->left, root->right, root，当符合上面提到的条件时，
	//  就进行出栈操作。有一种巧妙的方法可以做到，先上代码
	//对于每个节点，都压入两遍，在循环体中，每次弹出一个节点赋给p，如果p仍然等于栈的头结点，
	//  说明p的孩子们还没有被操作过，应该把它的孩子们加入栈中，否则，访问p。
	//    也就是说，第一次弹出，将p的孩子压入栈中，第二次弹出，访问p。
	//方法3：(自己想出来的，不做介绍了，因为代码只给我自己看呀)
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
			{ //①判断p是否为叶子结点②判断p的孩子是否都被访问过
				cout << p->_data << " ";
				last = p;
				s.pop();
			}
			else              //按照右孩子，左孩子的顺序依次入栈
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
		while (cur || !sta.empty())//把每一个结点都当做根结点
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
				cout << cur->_data << " ";//注意，能访问某个结点，那么说明它的左右子树都被访问过
				sta.pop();
				cur = NULL;//所以这里必须置空，
			}
			else
				cur = cur->_right;
		}
		cout << endl;
	}

	size_t Size()//子问题思想
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
	size_t Size2()//遍历思想
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

	size_t LeafSize()//子问题思想
	{
		return _LeafSize(_root);
	}
	size_t _LeafSize(Node*node)//重点：用子问题思想，一般都要有返回值
	{
		if (!node)//空结点的返回条件
			return 0;
		if (node&&!node->_left&&!node->_right)//叶子结点的返回条件
			return 1;
		return _LeafSize(node->_left) + _LeafSize(node->_right);//返回左子树叶子结点个数+右子树的
	}
	size_t LeafSize2()//遍历思想
	{
		size_t size = 0;
		_LeafSize2(_root,size);
		return size;
	}
	void _LeafSize2(Node*node, size_t& size)//注意：遍历思想一般可以不需要返回值，而是需要一个计数器
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
	size_t _Depth(Node*node)//子问题思想，倒着想问题比较好
	{
		if (!node)
			return 0;
		size_t lefthigh = _Depth(node->_left);
		size_t righthigh = _Depth(node->_right);

		return lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
	}

	size_t GetKLevel(size_t k)//求第k层节点个数（层序遍历的思想）
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
	size_t GetKLevel2(size_t k)//递归子问题思想
	{
		return _GetKLevel2(_root, 2 * k - 2);
	}
	size_t _GetKLevel2(Node* node,size_t k)
	{
		if (!node)return 0;//假如该分支没达到k层，返回0。
		if (k == 0)return 1;//注意，假如能执行该句代码，那么该分支的第k层一定有一个结点
		return _GetKLevel2(node->_left, --k) + _GetKLevel2(node->_right, --k);//注意，执行完该语句，k = k-2;
	}

	bool IsCompleteTree()
	{
		cout<< _IsCompleteTree(_root)<<" ";
		return _IsCompleteTree2(_root);
	}
	bool _IsCompleteTree(Node*node)//判断该树是不是一棵完全二叉树
	{
		queue<Node*> q;
		bool flag = true;
		q.push(node);
		while (!q.empty())//层序遍历的思想，如果用了flag，就不需要压空结点入队列
		{
			Node *front = q.front();
			q.pop();
			
			if (front->_left)
			{
				if (flag == false)return false;
				q.push(front->_left);
			}
			else
				flag = false;//①层序，如果当前结点没有左子树或者右子树，那么剩下的结点必定都没有孩子
			                 //②当前结点有右子树，那么也必定要有左子树
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
	bool _IsCompleteTree2(Node*node)//层序遍历的思想，如果压空结点入队列，那么就不需要flag
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

	Node* Find(const T& x)//子问题思想
	{
		return _Find(_root, x);
	}
	Node* _Find(Node*node, const T& x)//在二叉树中寻找出x所在的位置，找到返回指向那个结点的指针，否则返回NULL
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

	//t1.PrevOrder_NonR();//非递归遍历
	//t1.InOrder_NonR();
	//t1.PostOrder_NonR();
	//cout << endl;
	//t1.PrevOrder();//递归遍历
	//t1.InOrder();
	//t1.PostOrder();
	//t1.LevelOrder();//层次遍历
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