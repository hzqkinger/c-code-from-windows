#pragma once
//B树定义：
//1970年，R.Bayer和E.mccreight提出了一种适合外查找的树，它是一种平衡的多叉树，称为B树（有些地方写的是B-树，注意不要误读成"B减树"）

//一棵M阶(M>2)的B树，是一棵平衡的M路平衡搜索树，可以是空树或者满足一下性质：
//     1. 根节点至少有两个孩子
//     2. 每个非根节点至少有M / 2(上取整)个孩子, 至多有M个孩子
//     3. 每个非根节点至少有M / 2 - 1(上取整)个关键字, 至多有M - 1个关键字，并且以升序排列
//     4. key[i]和key[i + 1]之间的孩子节点的值介于key[i]、key[i + 1]之间
//     5. 所有的叶子节点都在同一层


//M阶B树表示该树最多有M个孩子，最多有M-1个关键字
template<typename K,typename V,size_t M>
struct BTreeNode{
	pair<K, V> _kv[M];//关键字最多有M-1个，这里多开一个是为了插入时方便
	BTreeNode<K, V, M> *_parent;
	BTreeNode<K, V, M> *_subs[M + 1];//孩子最多有M个，同样是为了插入时方便
	size_t _size;//表示该节点中关键字的数量
	BTreeNode() :_parent(NULL),_size(0)
	{
		for (size_t i = 0; i < M + 1; ++i)
		{
			_subs[i] = NULL;
		}
	}
};

template<typename K,typename V,size_t M = 3>
class BTree{
	typedef BTreeNode<K, V, M> Node;
public:
	BTree() :_root(NULL)
	{}

	pair<Node*, int> Find(const K& key)
	{
		Node *cur = _root, *parent = NULL;
		while (cur)
		{
			parent = cur;

			size_t i = 0;
			for (; i < cur->_size; ++i)
			{
				if (cur->_kv[i].first > key)break;//找到第一个大于key的关键字
				else if (cur->_kv[i].first == key)
					return make_pair(cur, i);//要插入的关键字存在
			}
			cur = cur->_subs[i];
		}

		return make_pair(parent, -1);//要插入的关键字不存在，
	}

	bool Insert(const pair<K, V>& p,Node *psub = NULL,Node *cur = NULL)
	{
		if (!_root)//如果根结点为空(ps:当且仅当B树为空的时候才会走该语句)
			_root = new Node();

		if (!cur)//如果cur为空，重新给它赋值(ps:当且仅当插入结点进入该函数时才会走该语句，循环进入函数时不会走该语句)
		{
			pair<Node*, int> tmp = Find(p.first);
			if (tmp.second >= 0)//B树中存在欲插入的关键字
				return false;
			cur = tmp.first;
		}

		int end = cur->_size - 1;//注意，这里end的类型要用int,不能用size_t
		for (; end >= 0; --end)
		{
			if (cur->_kv[end].first < p.first)break;//找到第一个小于欲插入关键字的位置

			cur->_kv[end + 1] = cur->_kv[end];//移动关键字
			cur->_subs[end + 2] = cur->_subs[end + 1];//移动孩子
		}
		cur->_kv[end + 1] = p;//插入关键字
		cur->_subs[end + 2] = psub;//插入孩子
		
		if (++cur->_size < M)return true;//在叶子结点插入时，关键字数量符合要求

		//分裂(ps:往下面走，说明cur指向的结点里面的关键字满了)
		Node *parent = cur->_parent;
		size_t mid = cur->_size / 2;

		Node *newNode = new Node();
		size_t j = 0, i = mid + 1;
		for (; i < cur->_size; ++i)
		{
			newNode->_kv[j] = cur->_kv[i];//往newNode中拷贝关键字
			newNode->_subs[j] = cur->_subs[i];//往newNode中拷贝孩子

			if (newNode->_subs[j])//更新转移的关键字的孩子的父亲
				newNode->_subs[j]->_parent = newNode;

			++j;
		}newNode->_subs[j] = cur->_subs[i];
		if (newNode->_subs[j])
			newNode->_subs[j]->_parent = newNode;

		newNode->_size = cur->_size - mid - 1;//更新newNode的大小
		cur->_size = mid;//更新cur的大小
		newNode->_parent = parent;//更新newNode的父亲

		if (!parent)//如果cur的父亲为空，说明cur就是根结点(ps:当且仅当cur为根结点且根结点满了时才会走该语句)
		{
			_root = parent = new Node();//重置根
			cur->_parent = parent;//重置孩子的父亲
			newNode->_parent = parent;//重置孩子的父亲

			_root->_kv[0] = cur->_kv[mid];//拷贝关键字
			_root->_subs[0] = cur;//重置孩子
			_root->_subs[1] = newNode;//重置孩子
			_root->_size++;//重置大小

			return true;
		}

		return Insert(cur->_kv[mid],newNode, parent);//往parent这个结点插入一个关键字和一个孩子
	}

	bool Erase(const K& key)
	{

	}
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
private:
	Node *_root;
	void _Inorder(Node *root)//左根左根左根...右
	{
		if (!root)return;
		size_t i = 0;
		for (; i < root->_size; ++i)
		{
			_Inorder(root->_subs[i]);//左
			cout << root->_kv[i].first << " ";//根
		}
		_Inorder(root->_subs[i]);//右
	}
};

void test_BTree()
{
	BTree<int, int> bt;
	int arr[] = { 53, 75, 139, 49, 145, 36, 101 };
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		bt.Insert(make_pair(arr[i], 1));
	}

	bt.Inorder();
}