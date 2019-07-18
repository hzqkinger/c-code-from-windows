#pragma once

enum en{ RED, BLACK };

template<typename v>
struct RBTreeNode{
	v _value;
	RBTreeNode<v> *_left;
	RBTreeNode<v> *_right;
	RBTreeNode<v> *_parent;
	en _col;
	RBTreeNode(const v& value)
		:_value(value), _left(NULL), _right(NULL), _parent(NULL), _col(RED){}
};

template<typename V, typename ref, typename ptr>
class RBTree_Iterator
{
	typedef RBTree_Iterator<V, ref, ptr> self;
	typedef RBTreeNode<V> node;

	node *_node;
public:
	RBTree_Iterator() = default;
	RBTree_Iterator(node *node) :_node(node){}

	//  *  ->      ++  --       !=  ==
	ref operator*()//_data是个普通类型（像指向内置类型的普通指针一样解引用就得到它指向的数据）
	{
		return _node->_value;
	}
	ptr operator->()//假如_data是个自定义类型(eg.是个结构体)（像指向自定义类型的普通指针一样）
	{
		return &(_node->_value);//必须返回对象的指针（即该对象的指针）****或返回自定义了箭头运算符的某个类的对象
	}

	self& operator++()//像普通指针一样前置自增
	{
		if (_node->_right)
		{
			_node = _node->_right;
			while (_node->_left)_node = _node->_left;
		}
		else
		{
			node *parent = _node->_parent;
			while (parent && _node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}

		return *this;
	}
	self operator++(int)//像普通指针一样后置自增
	{
		self tmp(*this);
		if (_node->_right)
		{
			_node = _node->_right;
			while (_node->_left)_node = _node->_left;
		}
		else
		{
			node *parent = _node->_parent;
			while (parent && _node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return tmp;
	}
	self& operator--()//像普通指针一样前置自减
	{
		if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)_node = _node->_right;
		}
		else
		{
			node *parent = _node->_parent;
			while (parent && _node == parent->_left)
			{
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	self operator--(int)//像普通指针一样后置自减
	{
		self tmp(*this);
		if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)_node = _node->_right;
		}
		else
		{
			node *parent = _node->_parent;
			while (parent && _node == parent->_left)
			{
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return tmp;
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


//set<k>    RBTree<k,k,KorV>
//map<k,v>  RBTree<k,pair<k,v>,KorV>
template<typename k, typename v,typename KorV>
class RBTree{
	typedef RBTreeNode<v> Node;
public:

	typedef RBTree_Iterator<v, v&, v*> Iterator;
	typedef RBTree_Iterator<v, const v&, const v*> Const_Iterator;
	Iterator Begin()
	{
		Node *cur = _root;
		while (cur->_left)//注意，这里不用判断cur是否为空，因为如果_root为空本来就应该报错的
			cur = cur->_left;
		return Iterator(cur);
	}
	Iterator End()
	{
		return Iterator(NULL);
	}
	Const_Iterator CBegin()const
	{
		Node *cur = _root;
		while (cur->_left)//注意，这里不用判断cur是否为空，因为如果_root为空本来就应该报错的
			cur = cur->_left;
		return Const_Iterator(cur);
	}
	Const_Iterator CEnd()const
	{
		return Const_Iterator(NULL);
	}

	RBTree() :_root(NULL){}

	pair<Iterator, bool> Insert(const v& value)
	{
		if (!_root){//保证了下面的操作都是有双亲结点的
			_root = new Node(value);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		KorV _kv;
		Node *parent = NULL, *cur = _root;
		while (cur){//寻找到合适的插入位置
			parent = cur;
			if (_kv(value) > _kv(cur->_value))cur = cur->_right;
			else if (_kv(value) < _kv(cur->_value))cur = cur->_left;
			else return make_pair(cur, false);
		}
		cur = new Node(value);//先按照搜索树的规则插入结点，然后留给后序处理
		if (_kv(value) > _kv(parent->_value))parent->_right = cur;
		else parent->_left = cur;
		cur->_parent = parent;
		Node *subcur = cur;
		//当parent为黑色时，不需要做任何事情了；只有parent为红色时才需要更新甚至旋转
		while (parent && parent->_col == RED){
			Node *grandfather = parent->_parent;
			if (parent == grandfather->_left){
				Node *uncle = grandfather->_right;//一。判定叔叔在右边

				if (uncle && uncle->_col == RED){//①叔叔存在且为红
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;//继续往上更新
					parent = cur->_parent;
				}
				else{//②叔叔不存在或存在且为黑色
					if (cur == parent->_right){
						RotateL(parent);//左旋
						swap(cur, parent);//注意点
					}
					RotateR(grandfather);//右旋
					parent->_col = BLACK;//旋转完成后校正结点的颜色
					grandfather->_col = RED;
				}
				_root->_col = BLACK;//暴力更新根结点的颜色
			}
			else{
				Node *uncle = grandfather->_left;//二。判定叔叔在左边

				if (uncle && uncle->_col == RED){//①叔叔存在且为红
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;//继续往上更新
					parent = cur->_parent;
				}
				else{//②叔叔不存在或存在且为黑色
					if (cur == parent->_left){
						RotateR(parent);//右旋
						swap(cur, parent);//注意点
					}
					RotateL(grandfather);//左旋
					parent->_col = BLACK;//旋转完成后校正结点的颜色
					grandfather->_col = RED;
				}
				_root->_col = BLACK;//暴力更新根结点的颜色
			}
		}
		return make_pair(subcur, true);
	}
	bool Erase(const k& key)
	{
		Node *cur = _root;
		while (cur)
		{
			if (key < cur->_key)cur = cur->_left;
			else if (key > cur->_key)cur = cur->_right;
			else break;
		}
		if (!cur)return false;//若cur为空,表示该树中没有该关键字

		//一.先删除了应该删除的结点再说
		// ①需要删除的结点左为空
		// ②需要删除的结点右为空
		// ③需要删除的结点左右都不为为空
		Node *x, *del = cur;//ps:  经过删除步骤,del结点是真正需要删除的结点;以x为分支的红黑树的性质可能被破坏
		bool del_original_color = del->_col;//红色是0，黑色是1

		if (!del->_left)//左为空
		{
			x = del->_right;
			//RB_transplant(del, x);
			if (del->_parent == NULL)//如果del的_parent为空，即del是根
				_root = x;
			else if (del->_parent->_left == del)//del为父亲的左孩子
				del->_parent->_left = x;
			else del->_parent->_right = x;

			if (x)x->_parent = del->_parent;
		}
		else if (!del->_right)//右为空
		{
			x = del->_left;
			//RB_transplant(del, x);
			if (del->_parent == NULL)//如果del的_parent为空，即del是根
				_root = x;
			else if (del->_parent->_left == del)//del为父亲的左孩子
				del->_parent->_left = x;
			else del->_parent->_right = x;

			if (x)x->_parent = del->_parent;
		}
		else//左右都不为空
		{
			del = cur->_right;
			while (del->_left)del = del->_left;//找到替代结点，让它替代需要删除的点，然后其实真正要删除的结点时del

			del_original_color = del->_col;//红色是0，黑色是1
			x = del->_right;

			if (del->_parent == cur)//判断上面的循环是否执行过
				cur->_right = x;
			else
				del->_parent->_left = x;

			//cur->_col = del->_col;//ps,这句话一定不能写
			cur->_key = del->_key;//将del结点的一些内容拷贝到cur结点
			cur->_value = del->_value;
			if (x)x->_parent = del->_parent;
		}
		Node *x_parent = del->_parent;
		delete del;

		//二.删完之后开始调整红黑树的颜色(以x为分支的红黑树的性质可能被破坏,所以需要调整)
		if (del_original_color == BLACK)//只有当del结点的颜色为黑色的时候才会破坏红黑树的性质
			RB_delete_fixup(x_parent, x);
	}
	bool Isbalance()
	{
		if (!_root)return true;
		if (_root->_col == RED)return false;//①判断根颜色是否为黑色（注意，假如根为黑，该树也不一定正确，所以判红让它继续向下走）

		//②判断是否出现连续的红色
		//③判断每条路径上黑色数量是否相等
		Node *cur = _root; int k = 0, Nodnum = 0;
		while (cur){//因为红黑树每条路径上的黑结点数量是一样的，所以先算出一个值
			if (cur->_col == BLACK)++k;
			cur = cur->_left;
		}

		_Isbalance(_root, k, Nodnum);
	}

protected:
	void RotateL(Node *parent)
	{
		Node *subR = parent->_right;
		Node *subRL = subR->_left;
		Node *pparent = parent->_parent;

		parent->_right = subRL;
		if (subRL)subRL->_parent = parent;

		if (pparent){
			if (pparent->_left == parent)pparent->_left = subR;
			else pparent->_right = subR;
		}
		else _root = subR;
		subR->_parent = pparent;

		subR->_left = parent;
		parent->_parent = subR;
	}
	void RotateR(Node *parent)
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		Node *pparent = parent->_parent;

		parent->_left = subLR;
		if (subLR)subLR->_parent = parent;

		if (pparent){
			if (pparent->_left == parent)pparent->_left = subL;
			else pparent->_right = subL;
		}
		else _root = subL;
		subL->_parent = pparent;

		subL->_right = parent;
		parent->_parent = subL;
	}
	bool _Isbalance(Node *cur, const int k, int Nodnum)
	{
		if (!cur){//每条路径遍历到空时，查看Nodnum的数量是否与k一样
			if (k != Nodnum)return false;
			return true;
		}
		if (cur->_col == RED && cur->_parent->_col == RED)//注意，这里不需要为cur->_parent判空，因为_root的颜色是黑色的
			return false;//遍历到每个结点时查看它及它的父亲是不是红色的

		if (cur->_col == BLACK)++Nodnum;

		return _Isbalance(cur->_left, k, Nodnum)
			&& _Isbalance(cur->_right, k, Nodnum);
	}
	void RB_delete_fixup(Node *parent, Node *x)
	{
		//①x的兄弟结点w是红色的
		//②x的兄弟结点w是黑色的，且w的两个子结点都是黑色的
		//③x的兄弟结点w是黑色的，且w的左孩子是红色的，右孩子是黑色的
		//④x的兄弟结点w是黑色的，且w的右孩子是红色的
		while (!x || (x != _root && x->_col == BLACK))
		{
			if (x)parent = x->_parent;

			if (x == parent->_left)//x既可以不为空，也可以为空
			{
				Node *brother = parent->_right;
				if (brother->_col == RED)//①
				{
					brother->_col = BLACK;
					parent->_col = RED;
					RotateL(parent);

					brother = parent->_right;//必须重新赋值
				}

				if (x && brother->_left->_col == BLACK && brother->_right->_col == BLACK)//②x一定不会为空
				{
					brother->_col = RED;
					x = x->_parent;
					continue;//执行②之后，不知道x是他新父亲的左孩子还是右孩子，所以跳到循环开始
				}

				if (x && brother->_left->_col == RED && brother->_right->_col == BLACK)//③x一定不会为空
				{
					brother->_left->_col = BLACK;
					brother->_col = RED;
					RotateR(brother);

					brother = x->_parent->_right;//必须重新赋值
				}

				if (brother->_right == NULL)
				{
					brother->_col = RED;
					x = parent;
					//continue;
				}
				else if (brother->_right->_col == RED)//④x既可以为空，也可以不为空
				{
					brother->_col = parent->_col;
					parent->_col = BLACK;
					brother->_right->_col = BLACK;
					RotateL(parent);
					x = _root;//执行④只有，一定会结束循环
				}
			}
			else
			{
				Node *brother = parent->_left;
				if (brother->_col == RED)//①
				{
					brother->_col = BLACK;
					parent->_col = RED;
					RotateR(parent);

					brother = parent->_left;//必须重新赋值
				}

				if (x && brother->_left->_col == BLACK && brother->_right->_col == BLACK)//②
				{
					brother->_col = RED;
					x = x->_parent;
					continue;//执行②之后，不知道x是他新父亲的左孩子还是右孩子，所以跳到循环开始
				}

				if (x && brother->_left->_col == BLACK && brother->_right->_col == RED)//③
				{
					brother->_left->_col = BLACK;
					brother->_col = RED;
					RotateL(brother);

					brother = x->_parent->_left;//必须重新赋值
				}

				if (brother->_left == NULL)
				{
					brother->_col = RED;
					x = parent;
					//continue;
				}
				else if (brother->_left->_col == RED)//④
				{
					brother->_col = x->_parent->_col;
					parent->_col = BLACK;
					brother->_right->_col = BLACK;
					RotateR(parent);
					x = _root;//执行④只有，一定会结束循环
				}
			}
		}
		if (x)x->_col = BLACK;
	}

	Node *_root;
};