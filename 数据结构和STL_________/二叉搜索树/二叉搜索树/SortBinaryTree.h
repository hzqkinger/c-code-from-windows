#pragma once
//�������������ֳƶ�������������������һ�ÿ����������Ǿ����������ʵĶ�����
//            1����������������Ϊ�գ��������������нڵ��ֵ��С�ڸ��ڵ��ֵ
//            2����������������Ϊ�գ��������������нڵ��ֵ�����ڸ��ڵ��ֵ
//            3��������������Ҳ�ֱ�Ϊ����������
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
	SortTree() :_root(NULL){}//Ĭ�Ϲ��캯��
	//�����������캯���͸�ֵ��������غ�����Ҫд��
	void Inorder()//�������
	{
		_Inorder(_root);
		cout << endl;
	}

	bool Insert(const K& key, const V& value)//�ǵݹ��д��
	{
		if (!_root){//ȷ���ڽ�������Ĳ���ʱ������㲻Ϊ��
			_root = new Node(key, value);
			return true;
		}

		Node *parent = NULL, *cur = _root;
		while (cur){
			parent = cur;
			if (key > cur->_key) cur = cur->_right;//��Ҫ�������key��cur->_key��������
			else if (key < cur->_key)cur = cur->_left;//��Ҫ�������key��cur->_keyС��������
			else return false;//���д��ڸùؼ���
		}

		cur = new Node(key, value);
		if (key > parent->_key)parent->_right = cur;
		else parent->_left = cur;

		return true;
	}
	Node* Find(const K& key)//�ǵݹ�д��
	{
		Node *cur = _root;
		while (cur){
			if (key > cur->_key)cur = cur->_right;
			else if (key < cur->_key)cur = cur->_left;
			else return cur;//�����������д�����Ҫ�ҵ�ֵ����һ���������ﷵ��
		}
		return cur;//����������ﷵ��һ��NULL
	}
	bool Remove(const K& key)
	{
		//���һ����Ҫɾ���Ľ����Ϊ��,���ж�Ҫɾ�Ľ���ǲ���_root
		//���������Ҫɾ���Ľ����Ϊ��,���ж�Ҫɾ�Ľ���ǲ���_root
		//���������Ҫɾ���Ľ�����Ҷ���Ϊ��,
		Node *parent = NULL, *cur = _root;
		while (cur && key != cur->_key){//�����ѭ����Ҫô�ҵ�����Ҫɾ���Ľ�㣬Ҫôcur����NULL
			parent = cur;
			if (key > cur->_key)cur = cur->_right;
			else cur = cur->_left;
		}
		Node *del = cur;
		if (!cur)return false;		//���в�������Ҫɾ���Ľ�㣬��ɾ��ʧ��
		else{

			if (!cur->_left){//����Ϊ��
				if (cur != _root){
					if (cur == parent->_left)parent->_left = cur->_right;
					else parent->_right = cur->_right;
				}
				else _root = cur->_right;
			}else if (!cur->_right){//����Ϊ��
				if (cur != _root){
					if (cur == parent->_left)parent->_left = cur->_left;
					else parent->_right = cur->_left;
				}
				else _root = cur->_left;
			}else{//�����Ҷ���Ϊ�գ�ע���������ǲ��ÿ���cur�ǲ���_root,ԭ����Ϳ�ʵ�ִ��룩
				Node *paren = cur, *sub = cur->_right;
				while (sub->_left){ paren = sub; sub = sub->_left; }//Ѱ��sub

				if (paren != cur)paren->_left = sub->_right;//�����������ѭ������sub�߶���
				else paren->_right = sub->_right;//������ѭ��ʧЧʱ����subû���߶�

				cur->_key = sub->_key; cur->_value = sub->_value;//��sub�����kv����cur
				del = sub;
			}
		}
		delete del;//����ͷŽ��
		return true;
	}

	bool Insert_Recursive(const K& key, const V& value)//�ݹ�д��
	{
		return _Insert_Recursive(_root, key, value);
	}
	Node* Find_Recursive(const K& key)//�ݹ�д��
	{
		return _Find_Recursive(_root, key);
	}
	bool Remove_Recursive(const K& key)//�ݹ�д��
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
	{//�ú�����������:��һ��ֵkey��root->_key���бȽϣ�����С�Ͳ��뵽root����������������Ͳ��뵽������
		if (!root){
			root = new Node(key, value);
			return true;
		}
		if (key == root->_key)return false;//��ȵ������ֱ�ӷ���

		if (key < root->_key)
			return _Insert_Recursive(root->_left, key, value);//ע��:�����return���˺���Ҫ������
		if (key > root->_key)
			return _Insert_Recursive(root->_right, key, value);
	}
	Node* _Find_Recursive(Node *&root, const K& key)
	{//�ú�����������:��һ��ֵkey��root->_key���бȽϣ�����С��Ѱ��root�����������������Ѱ��������
		if (!root)return NULL;//û�ҵ�
		if (key == root->_key)return root;//�ҵ��˵����

		if (key < root->_key)
			return _Find_Recursive(root->_left, key, value);//ע��:�����return���˺���Ҫ������
		if (key > root->_right)
			return _Find_Recursive(root->_right, key, value);
	}
	bool _Remove_Recursive(Node *&root, const K& key)
	{//�ú�����������:��һ��ֵkey��root->_key���бȽϣ�����С����root��������Ѱ�Ҳ�ɾ�����������Ѱ��������
		if (!root)return false;//ɾ��ʧ�����
		if (key == root->_key){//ɾ���ɹ����

			//����Ϊ�գ����ж�Ҫɾ�Ľ���ǲ���_root
			//����Ϊ�գ����ж�Ҫɾ�Ľ���ǲ���_root
			//�����Ҷ���Ϊ�գ�����Ҫ�ж�
			Node *del = root;
			if (!root->_left){//��
				if (root == _root)_root = root->_right;
				else root = root->_right;//��Ϊ�ǵݹ������ģ�����������Ȼ��֪��root����˫�׵�������
			}
			else if (!root->_right){//��
				if (root == _root)_root = root->_left;
				else root = root->_left;//��Ϊ�ǵݹ������ģ�����������Ȼ��֪��root����˫�׵�������
			}
			else{//��
				Node *parent = root, *sub = root->_right;
				while (sub->_left){ parent = sub; sub = sub->_left; }
				if (parent == root)parent->_right = sub->_right;
				else parent->_left = sub->_right;//����������������ô˵��sub��û�����ӵģ�������
				root->_key = sub->_key; root->_value = sub->_value;
				del = sub;//��
				//�˾������������߼��ȼ�
				//return _Remove_Recursive(root->_right, sub->_key);//��
			}
			delete del;
			return true;
		}

		if (key < root->_key)
			return _Remove_Recursive(root->_left, key);//ע��:�����return���˺���Ҫ������
		if (key > root->_key)
			return _Remove_Recursive(root->_right, key);
	}
};

//��ͨ��������Ӧ�ã�
//           1.�ڵ��ʿ��в���һ�������Ƿ����


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