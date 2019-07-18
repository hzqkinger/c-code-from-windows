#pragma once
//B�����壺
//1970�꣬R.Bayer��E.mccreight�����һ���ʺ�����ҵ���������һ��ƽ��Ķ��������ΪB������Щ�ط�д����B-����ע�ⲻҪ�����"B����"��

//һ��M��(M>2)��B������һ��ƽ���M·ƽ���������������ǿ�����������һ�����ʣ�
//     1. ���ڵ���������������
//     2. ÿ���Ǹ��ڵ�������M / 2(��ȡ��)������, ������M������
//     3. ÿ���Ǹ��ڵ�������M / 2 - 1(��ȡ��)���ؼ���, ������M - 1���ؼ��֣���������������
//     4. key[i]��key[i + 1]֮��ĺ��ӽڵ��ֵ����key[i]��key[i + 1]֮��
//     5. ���е�Ҷ�ӽڵ㶼��ͬһ��


//M��B����ʾ���������M�����ӣ������M-1���ؼ���
template<typename K,typename V,size_t M>
struct BTreeNode{
	pair<K, V> _kv[M];//�ؼ��������M-1��������࿪һ����Ϊ�˲���ʱ����
	BTreeNode<K, V, M> *_parent;
	BTreeNode<K, V, M> *_subs[M + 1];//���������M����ͬ����Ϊ�˲���ʱ����
	size_t _size;//��ʾ�ýڵ��йؼ��ֵ�����
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
				if (cur->_kv[i].first > key)break;//�ҵ���һ������key�Ĺؼ���
				else if (cur->_kv[i].first == key)
					return make_pair(cur, i);//Ҫ����Ĺؼ��ִ���
			}
			cur = cur->_subs[i];
		}

		return make_pair(parent, -1);//Ҫ����Ĺؼ��ֲ����ڣ�
	}

	bool Insert(const pair<K, V>& p,Node *psub = NULL,Node *cur = NULL)
	{
		if (!_root)//��������Ϊ��(ps:���ҽ���B��Ϊ�յ�ʱ��Ż��߸����)
			_root = new Node();

		if (!cur)//���curΪ�գ����¸�����ֵ(ps:���ҽ������������ú���ʱ�Ż��߸���䣬ѭ�����뺯��ʱ�����߸����)
		{
			pair<Node*, int> tmp = Find(p.first);
			if (tmp.second >= 0)//B���д���������Ĺؼ���
				return false;
			cur = tmp.first;
		}

		int end = cur->_size - 1;//ע�⣬����end������Ҫ��int,������size_t
		for (; end >= 0; --end)
		{
			if (cur->_kv[end].first < p.first)break;//�ҵ���һ��С��������ؼ��ֵ�λ��

			cur->_kv[end + 1] = cur->_kv[end];//�ƶ��ؼ���
			cur->_subs[end + 2] = cur->_subs[end + 1];//�ƶ�����
		}
		cur->_kv[end + 1] = p;//����ؼ���
		cur->_subs[end + 2] = psub;//���뺢��
		
		if (++cur->_size < M)return true;//��Ҷ�ӽ�����ʱ���ؼ�����������Ҫ��

		//����(ps:�������ߣ�˵��curָ��Ľ������Ĺؼ�������)
		Node *parent = cur->_parent;
		size_t mid = cur->_size / 2;

		Node *newNode = new Node();
		size_t j = 0, i = mid + 1;
		for (; i < cur->_size; ++i)
		{
			newNode->_kv[j] = cur->_kv[i];//��newNode�п����ؼ���
			newNode->_subs[j] = cur->_subs[i];//��newNode�п�������

			if (newNode->_subs[j])//����ת�ƵĹؼ��ֵĺ��ӵĸ���
				newNode->_subs[j]->_parent = newNode;

			++j;
		}newNode->_subs[j] = cur->_subs[i];
		if (newNode->_subs[j])
			newNode->_subs[j]->_parent = newNode;

		newNode->_size = cur->_size - mid - 1;//����newNode�Ĵ�С
		cur->_size = mid;//����cur�Ĵ�С
		newNode->_parent = parent;//����newNode�ĸ���

		if (!parent)//���cur�ĸ���Ϊ�գ�˵��cur���Ǹ����(ps:���ҽ���curΪ������Ҹ��������ʱ�Ż��߸����)
		{
			_root = parent = new Node();//���ø�
			cur->_parent = parent;//���ú��ӵĸ���
			newNode->_parent = parent;//���ú��ӵĸ���

			_root->_kv[0] = cur->_kv[mid];//�����ؼ���
			_root->_subs[0] = cur;//���ú���
			_root->_subs[1] = newNode;//���ú���
			_root->_size++;//���ô�С

			return true;
		}

		return Insert(cur->_kv[mid],newNode, parent);//��parent���������һ���ؼ��ֺ�һ������
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
	void _Inorder(Node *root)//���������...��
	{
		if (!root)return;
		size_t i = 0;
		for (; i < root->_size; ++i)
		{
			_Inorder(root->_subs[i]);//��
			cout << root->_kv[i].first << " ";//��
		}
		_Inorder(root->_subs[i]);//��
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