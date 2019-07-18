#pragma once
//二叉搜索树：又称二叉排序树，它或者是一棵空树，或者是具有以下性质的二叉树
//            1、若它的左子树不为空，则左子树上所有节点的值都小于根节点的值
//            2、若它的右子树不为空，则右子树上所有节点的值都大于根节点的值
//            3、它的左右子树也分别为二叉搜索树
template<typename K,typename V>
struct SortTreeNode{
	K _key;
	V _value;
	struct SortTreeNode<K, V> *_left;
	struct SortTreeNode<K, V> *_right;

	SortTreeNode(const K& key, const V& value)
		:_key(key), _value(value), _left(NULL), _right(NULL){}
};

template<typename K,typename V>
class SortTree{
	typedef SortTreeNode<K, V> Node;
public:
	SortTree() :_root(NULL){}//默认构造函数
	//讲道理拷贝构造函数和赋值运算符重载函数是要写的
	void Inorder()//中序遍历
	{
		_Inorder(_root);
		cout << endl;
	}

	bool Insert(const K& key, const V& value)//非递归的写法
	{
		if (!_root){//确保在进行下面的操作时，根结点不为空
			_root = new Node(key, value);
			return true;
		}

		Node *parent = NULL, *cur = _root;
		while (cur){
			parent = cur;
			if (key > cur->_key) cur = cur->_right;//将要插进来的key比cur->_key大，往右走
			else if (key < cur->_key)cur = cur->_left;//将要插进来的key比cur->_key小，往左走
			else return false;//树中存在该关键字
		}

		cur = new Node(key, value);
		if (key > parent->_key)parent->_right = cur;
		else parent->_left = cur;

		return true;
	}
	Node* Find(const K& key)//非递归写法
	{
		Node *cur = _root;
		while (cur){
			if (key > cur->_key)cur = cur->_right;
			else if (key < cur->_key)cur = cur->_left;
			else return cur;//假如搜索树中存在需要找的值，那一定会在这里返回
		}
		return cur;//否则就在这里返回一个NULL
	}
	bool Remove(const K& key)
	{
		//情况一：需要删除的结点左为空,且判断要删的结点是不是_root
		//情况二：需要删除的结点右为空,且判断要删的结点是不是_root
		//情况三：需要删除的结点左右都不为空,
		Node *parent = NULL, *cur = _root;
		while (cur && key != cur->_key){//走完该循环，要么找到了需要删除的结点，要么cur等于NULL
			parent = cur;
			if (key > cur->_key)cur = cur->_right;
			else cur = cur->_left;
		}
		Node *del = cur;
		if (!cur)return false;		//树中不存在需要删除的结点，即删除失败
		else{

			if (!cur->_left){//①左为空
				if (cur != _root){
					if (cur == parent->_left)parent->_left = cur->_right;
					else parent->_right = cur->_right;
				}
				else _root = cur->_right;
			}else if (!cur->_right){//②右为空
				if (cur != _root){
					if (cur == parent->_left)parent->_left = cur->_left;
					else parent->_right = cur->_left;
				}
				else _root = cur->_left;
			}else{//③左右都不为空（注意在这里是不用考虑cur是不是_root,原因嘛就看实现代码）
				Node *paren = cur, *sub = cur->_right;
				while (sub->_left){ paren = sub; sub = sub->_left; }//寻找sub

				if (paren != cur)paren->_left = sub->_right;//进入了上面的循环，即sub走动了
				else paren->_right = sub->_right;//在上面循环失效时，即sub没有走动

				cur->_key = sub->_key; cur->_value = sub->_value;//将sub里面的kv丢给cur
				del = sub;
			}
		}
		delete del;//最后释放结点
		return true;
	}

	bool Insert_Recursive(const K& key, const V& value)//递归写法
	{
		return _Insert_Recursive(_root, key, value);
	}
	Node* Find_Recursive(const K& key)//递归写法
	{
		return _Find_Recursive(_root, key);
	}
	bool Remove_Recursive(const K& key)//递归写法
	{
		return _Remove_Recursive(_root, key);
	}
private:
	Node *_root;
	void _Inorder(Node *root)
	{
		if (!root)return;

		_Inorder(root->_left);
		cout << root->_key << " ";
		_Inorder(root->_right);
	}

	bool _Insert_Recursive(Node *&root, const K& key, const V& value)
	{//该函数的意义是:拿一个值key与root->_key进行比较，比它小就插入到root的左子树，比它大就插入到右子树
		if (!root){
			root = new Node(key, value);
			return true;
		}
		if (key == root->_key)return false;//相等的情况，直接返回

		if (key < root->_key)
			return _Insert_Recursive(root->_left, key, value);//注意:这里的return起到了很重要的作用
		if (key > root->_key)
			return _Insert_Recursive(root->_right, key, value);
	}
	Node* _Find_Recursive(Node *&root, const K& key)
	{//该函数的意义是:拿一个值key与root->_key进行比较，比它小就寻找root的左子树，比它大就寻找右子树
		if (!root)return NULL;//没找到
		if (key == root->_key)return root;//找到了的情况

		if (key < root->_key)
			return _Find_Recursive(root->_left, key, value);//注意:这里的return起到了很重要的作用
		if (key > root->_right)
			return _Find_Recursive(root->_right, key, value);
	}
	bool _Remove_Recursive(Node *&root, const K& key)
	{//该函数的意义是:拿一个值key与root->_key进行比较，比它小就在root的左子树寻找并删除，比它大就寻找右子树
		if (!root)return false;//删除失败情况
		if (key == root->_key){//删除成功情况

			//①左为空，且判断要删的结点是不是_root
			//②右为空，且判断要删的结点是不是_root
			//③左右都不为空，不需要判断
			Node *del = root;
			if (!root->_left){//①
				if (root == _root)_root = root->_right;
				else root = root->_right;//因为是递归下来的，所以这里天然就知道root是它双亲的左还是右
			}
			else if (!root->_right){//②
				if (root == _root)_root = root->_left;
				else root = root->_left;//因为是递归下来的，所以这里天然就知道root是它双亲的左还是右
			}
			else{//③
				Node *parent = root, *sub = root->_right;
				while (sub->_left){ parent = sub; sub = sub->_left; }
				if (parent == root)parent->_right = sub->_right;
				else parent->_left = sub->_right;//假如条件成立，那么说明sub是没有左孩子的；否则有
				root->_key = sub->_key; root->_value = sub->_value;
				del = sub;//八
				//八九这两个语句的逻辑等价
				//return _Remove_Recursive(root->_right, sub->_key);//九
			}
			delete del;
			return true;
		}

		if (key < root->_key)
			return _Remove_Recursive(root->_left, key);//注意:这里的return起到了很重要的作用
		if (key > root->_key)
			return _Remove_Recursive(root->_right, key);
	}
};

//普通搜索树的应用：
//           1.在单词库中查找一个单词是否存在


void test_SortTree()
{
	SortTree<int, int> tree;
	tree.Insert_Recursive(5, 1);
	tree.Insert_Recursive(3, 1);
	tree.Insert_Recursive(4, 1);
	tree.Insert_Recursive(4, 1);
	tree.Insert_Recursive(1, 1);
	tree.Insert_Recursive(0, 1);
	tree.Insert_Recursive(2, 1);
	tree.Insert_Recursive(7, 1);
	tree.Insert_Recursive(6, 1);
	tree.Insert_Recursive(8, 1);
	tree.Insert_Recursive(9, 1);
	tree.Inorder();
	//SortTreeNode<int, int> *find = tree.Find(21);
	tree.Remove_Recursive(8);
	tree.Remove_Recursive(8);
	tree.Remove_Recursive(2);
	tree.Remove_Recursive(3);
	tree.Remove_Recursive(6);
	tree.Remove_Recursive(5);
	tree.Inorder();
}