#pragma once
//一棵AVL树或者是空树，或者是具有以下性质的二叉搜索树：
//               1、它的左右子树都是AVL树
//               2、左子树和右子树高度之差(简称平衡因子)的绝对值不超过1(-1、0、1)
template<typename K,typename V>
struct AVLTreeNode{
	K _key;
	V _value;
	int _bf;//平衡因子 = 右子树高度 - 左子树高度 （注意，在这里实现的时候规定平衡因子就是右子树高度减左子树；其实也可以反过来）
	struct AVLTreeNode<K, V> *_left;
	struct AVLTreeNode<K, V> *_right;
	struct AVLTreeNode<K, V> *_parent;
	AVLTreeNode(const K& key, const V& value)
		:_key(key), _value(value), _bf(0), _left(NULL), _right(NULL), _parent(NULL){}
};

template<typename K,typename V>//AVL树是一棵高度平衡的搜索二叉树
class AVLTree{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree() :_root(NULL){}//默认构造函数

	Node *Find(const K& key)
	{
		Node *cur = _root;
		while (cur)
		{
			if (key > cur->_key)cur = cur->_right;
			else if (key < cur->_key)cur = cur->_left;
			else break;
		}
		return cur;//没找到返回空
	}
	//新节点P的平衡因子为0，但其双亲结点Pr的平衡因子有三种情况：
	//	1、结点Pr的平衡因子为0
	//	   在Pr的较矮的子树上插入新节点，结点Pr平衡，其高度没有增加，此时从Pr到根路径
	//	   上各结点为根的子树的高度不变，即各结点的平衡因子不变，结束平衡化处理。
	//	2、结点Pr的平衡因子的绝对值为1；
	//	   插入前Pr的平衡因子为0，插入后以Pr为根的子树没有失去平衡，但该子树的高度增
	//	   加，需从该结点Pr向根节点方向回溯，继续查看Pr的双亲结点的平衡性。
	//	3、结点Pr的平衡因子的绝对值为2，新节点在较高的子树插入，需要做平衡化处理：
	//	   若Pr = 2，说明右子树高，设Pr的右子树为q
	//	   当q的平衡因子为1，执行左单旋转
	//	   当q的平衡因子为 - 1，执行先右后左双旋转
	//	   若Pr = -2，说明左子树高，设Pr的左子树为q
	//	   当q的平衡因子为 - 1，执行右单旋转
	//	   当q的平衡因子为1，执行先左后右双旋转
	//	   旋转后Pr为根的子树高度降低，无需继续向上层回溯
	bool Insert(const K& key, const V& value)
	{
		if (!_root){ _root = new Node(key, value); return true; }//保证下面的插入操作都存在双亲
		
		Node *parent = NULL, *cur = _root;
		while (cur){//经过该步骤，找到了需要插入的位置
			parent = cur;
			if (key > cur->_key)cur = cur->_right;
			else if (key < cur->_key)cur = cur->_left;
			else return false;
		}

		cur = new Node(key, value);//不管怎么样，先将结点插入到树中
		if (key > parent->_key){
			parent->_right = cur;//2 cur插到parent右，parent.bf++;
			++parent->_bf;
		}
		else{
			parent->_left = cur;//1 cur插到parent左，parent.bf--;
			--parent->_bf;
		}
		cur->_parent = parent;

		//3 当parent.bf == 0,以parent为根的树的高度不变
		//4 当|parent.bf| == 1,高度变了，继续往上更新
		//5 当|parent.bf| == 2,不再往上更新了，开始旋转平衡树
		while (parent){//一直往祖先结点走，直到寻找|parent->_bf|==2的结点
			if (!parent->_bf)return true;//假如走到该语句，说明该树不需要旋转
			else if(parent->_bf ==1 || parent->_bf == -1){
				cur = parent; parent = parent->_parent;
				if (parent){
					if (cur == parent->_left)--parent->_bf;
					else ++parent->_bf;
				}
			}else{
				if (parent->_bf == -2){//假如程序走到这里那么说明该树需要旋转
					if (cur->_bf == -1) RotateR(parent);
					else RotateLR(parent);
				}
				else{
					if (cur->_bf == -1)RotateRL(parent);
					else RotateL(parent);
				}
				break;
			}
		}
		return true;
	}
	bool Remove(const K& key)
	{
		Node *cur = _root;
		while (cur)
		{
			if (key < cur->_key)cur = cur->_left;
			else if (key > cur->_key)cur = cur->_right;
			else break;
		}
		if (!cur)return false;//若cur为空,表示该树中没有该关键字

		//删除结点前：
		//一.parent->_bf == 0;（不用调平衡）
		//二.| parent->_bf | == 1，且删除较高的子树的结点（不用调平衡）
		//三.| parent->_bf | == 1，且删除较矮的子树的结点（需要调平衡）

		Node *parent = cur->_parent, *del = cur;
		//先删除了结点再说，
		//①cur左为空，且判断cur是否为_root ②cur右为空,且判断cur是否为_root③cur左右都不为空
		if (!cur->_left)//①cur左为空
		{
			if (cur != _root)
			{
				if (cur == parent->_left)
				{ parent->_left = cur->_right; if (cur->_right)cur->_right->_parent = parent; parent->_bf++; }
				else 
				{ parent->_right = cur->_right;  if (cur->_right)cur->_right->_parent = parent; parent->_bf--; }
			}
			else _root = cur->_right;
		}
		else if (!cur->_right)//②右为空
		{
			if (cur != _root){
				if (cur == parent->_left){ parent->_left = cur->_left; if (cur->_left)cur->_left->_parent = parent; parent->_bf++; }
				else { parent->_right = cur->_left; if (cur->_left)cur->_left->_parent = parent;  parent->_bf--; }
			}
			else _root = cur->_left;
		}
		else//③左右都不为空
		{
			parent = cur;
			Node *sub = cur->_right;
			while (sub->_left){ parent = sub; sub = sub->_left; }//寻找sub

			if (parent != cur){ parent->_left = sub->_right; if (cur->_right)cur->_right->_parent = parent;  parent->_bf++; }//进入了上面的循环，即sub走动了
			else { parent->_right = sub->_right; if (cur->_right)cur->_right->_parent = parent;  parent->_bf--; }//在上面循环失效时，即sub没有走动

			cur->_key = sub->_key; cur->_value = sub->_value;//将sub里面的kv丢给cur
			del = sub;
		}
		delete del;//释放结点

		//删除结点后：
		//一.parent->_bf <= 1;（不用调平衡）
		//二.| parent->_bf | == 2;（需要调平衡）
		if (parent->_bf == 2)
		{
			cur = parent->_right;
			if (cur->_bf == 0 || cur->_bf == 1)
			{
				int bf = cur->_bf;//提前记录
				RotateL(parent);//单旋要重置平衡因子
				if (bf == 0){ parent->_bf = 1; cur->_bf = -1; }//重新调节平衡因子
				else{ parent->_bf = cur->_bf = 0; }
			}
			else
			{
				RotateRL(parent);//双旋时就已经把平衡因子调节平衡了
			}
		}
		else if (parent->_bf == -2)
		{
			cur = parent->_left;
			if (cur->_bf == 0 || cur->_bf == -1)
			{
				int bf = cur->_bf;//提前记录
				RotateR(parent);//单旋要重置平衡因子
				if (bf == 0){ parent->_bf = -1; cur->_bf = 1; }//重新调节平衡因子
				else{ parent->_bf = cur->_bf = 0; }
			}
			else
			{
				RotateLR(parent);//双旋时就已经把平衡因子调节平衡了
			}
		}

		return true;
	}

	int Height()
	{
		return _Height(_root);
	}
	bool Isbalance()
	{
		//return _Isbalance(_root);
		int height = 0;
		return _IsbalanceOP(_root,height);
	}
private:
	//6 ①右单旋②左单旋③右左双旋④左右双旋
	void RotateR(Node *parent)//右单旋
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		Node *pparent = parent->_parent;

		parent->_left = subLR;
		if (subLR)subLR->_parent = parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent != _root){//判断parent是不是根结点
			if (pparent->_left == parent)pparent->_left = subL;
			else pparent->_right = subL;//假如parent不是根结点，判断parent是双亲的左还是右
		}else _root = subL;
		subL->_parent = pparent;

		parent->_bf = subL->_bf = 0;//将平衡因子暴力置零，这步只会让插入受益（实际上，该语句放到插入更佳）
	}
	void RotateL(Node *parent)//左单旋
	{
		Node *subR = parent->_right;//其实就是处理这三个结点之间的链接关系
		Node *subRL = subR->_left;
		Node *pparent = parent->_parent;

		parent->_right = subRL;//处理parent与subRL之间的关系
		if (subRL)subRL->_parent = parent;

		subR->_left = parent;//处理parent与subR之间的关系
		parent->_parent = subR;

		if (parent != _root){//处理subR与pparent之间的关系
			if (pparent->_left == parent)pparent->_left = subR;
			else pparent->_right = subR;
		}else _root = subR;//注意点:假如parent是根结点，那么必须更新根结点
		subR->_parent = pparent;

		parent->_bf = subR->_bf = 0;//平衡因子暴力置零，这步只会让插入受益（实际上，该语句放到插入更佳）
	}
	//单旋时，平衡因子不会出问题，但是在双旋时会出问题,所以需要特殊处理一下
	void RotateRL(Node *parent)//右左双旋
	{
		Node *subR = parent->_right;
		Node *subRL = subR->_left;
		int bf = subRL->_bf;//记录subRL还没旋转时候的平衡因子
		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)parent->_bf = -1;
		else if (bf == -1)subR->_bf = 1;
	}
	void RotateLR(Node *parent)//左右双旋
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		int bf = subLR->_bf;//记录subLR还没旋转时候的平衡因子
		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)subL->_bf = -1;
		else if (bf == -1)parent->_bf = 1;
	}

	int _Height(Node *root)//该函数的含义是:求解以root为根的子树高度
	{
		if (!root)return 0;//如果根为空，那么返回高度0

		int LeftHeight = _Height(root->_left);//求左子树的高度
		int RightHeight = _Height(root->_right);//求右子树的高度

		return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
	}
	bool _Isbalance(Node *root)//该函数的含义:判断以root为根结点的树是否平衡
	{//判断方法:左子树的高度与右子树的高度差不能超过1
		if (!root)return true;//如果该子树为空树，那么该树就认定为该子树是平衡的

		int LeftHeight = _Height(root->_left);//拿到左子树的高度
		int RightHeight = _Height(root->_right);//拿到右子树的高度

		//如果该树不是平衡的，那么结束递归且返回false;
		//要是该树是平衡的，那么会递归进去子过程，继续判断它的左右子树是否平衡
		return abs(LeftHeight - RightHeight) < 2//①判断自己是不是平衡的
			&& _Isbalance(root->_left)//②判断左子树是不是平衡的
			&& _Isbalance(root->_right);//③判断右子树是不是平衡的

		//这个return真的好用，如果条件满足可以提前结束掉递归
	}
	//树的优化时，大多数情况可以由前序改成后序,
	//   (注意，如果用return，那么可能提前结束该函数，所以后序判断左右子树时不要随便用return，想清楚再用)
	bool _IsbalanceOP(Node *root,int& height)
	{
		if (!root){ height = 0; return true; }//如果为空树，那么该树的高度置零且该树是平衡的

		int LeftHeight = 0;//局部变量
		int RightHeight = 0;//局部变量

		if (_IsbalanceOP(root->_left, LeftHeight) == false)//①判断左子树是不是平衡的
			return false;                //局部变量的引用
		if (_IsbalanceOP(root->_right, RightHeight) == false)//②判断右子树是不是平衡的
			return false;                 //局部变量的引用

		height = LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
		//通过上面这种机制，可以实现在这层递归函数中更新上一层递归函数的局部变量

		return abs(LeftHeight - RightHeight) < 2;//③判断自己是不是平衡的
	}
	Node *_root;
};

void test_AVLTree()
{
	AVLTree<int, int> tree;
	int a[10] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		tree.Insert(a[i], 1);
	}
	tree.Remove(3);
	tree.Remove(3);
	tree.Remove(2);
	tree.Remove(8);
	tree.Remove(9);
	tree.Remove(4);
	tree.Remove(6);
	tree.Remove(10);


	//cout << tree.Height() << endl;
	//tree.Insert(8, 1);
	//cout << tree.Height() << endl;
	cout << tree.Isbalance() << endl;

	cout << "hah" << endl;
}