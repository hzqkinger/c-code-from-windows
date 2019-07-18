#pragma once
//һ��AVL�������ǿ����������Ǿ����������ʵĶ�����������
//               1������������������AVL��
//               2�����������������߶�֮��(���ƽ������)�ľ���ֵ������1(-1��0��1)
template<typename K,typename V>
struct AVLTreeNode{
	K _key;
	V _value;
	int _bf;//ƽ������ = �������߶� - �������߶� ��ע�⣬������ʵ�ֵ�ʱ��涨ƽ�����Ӿ����������߶ȼ�����������ʵҲ���Է�������
	struct AVLTreeNode<K, V> *_left;
	struct AVLTreeNode<K, V> *_right;
	struct AVLTreeNode<K, V> *_parent;
	AVLTreeNode(const K& key, const V& value)
		:_key(key), _value(value), _bf(0), _left(NULL), _right(NULL), _parent(NULL){}
};

template<typename K,typename V>//AVL����һ�ø߶�ƽ�������������
class AVLTree{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree() :_root(NULL){}//Ĭ�Ϲ��캯��

	Node *Find(const K& key)
	{
		Node *cur = _root;
		while (cur)
		{
			if (key > cur->_key)cur = cur->_right;
			else if (key < cur->_key)cur = cur->_left;
			else break;
		}
		return cur;//û�ҵ����ؿ�
	}
	//�½ڵ�P��ƽ������Ϊ0������˫�׽��Pr��ƽ�����������������
	//	1�����Pr��ƽ������Ϊ0
	//	   ��Pr�Ľϰ��������ϲ����½ڵ㣬���Prƽ�⣬��߶�û�����ӣ���ʱ��Pr����·��
	//	   �ϸ����Ϊ���������ĸ߶Ȳ��䣬��������ƽ�����Ӳ��䣬����ƽ�⻯����
	//	2�����Pr��ƽ�����ӵľ���ֵΪ1��
	//	   ����ǰPr��ƽ������Ϊ0���������PrΪ��������û��ʧȥƽ�⣬���������ĸ߶���
	//	   �ӣ���Ӹý��Pr����ڵ㷽����ݣ������鿴Pr��˫�׽���ƽ���ԡ�
	//	3�����Pr��ƽ�����ӵľ���ֵΪ2���½ڵ��ڽϸߵ��������룬��Ҫ��ƽ�⻯����
	//	   ��Pr = 2��˵���������ߣ���Pr��������Ϊq
	//	   ��q��ƽ������Ϊ1��ִ������ת
	//	   ��q��ƽ������Ϊ - 1��ִ�����Һ���˫��ת
	//	   ��Pr = -2��˵���������ߣ���Pr��������Ϊq
	//	   ��q��ƽ������Ϊ - 1��ִ���ҵ���ת
	//	   ��q��ƽ������Ϊ1��ִ���������˫��ת
	//	   ��ת��PrΪ���������߶Ƚ��ͣ�����������ϲ����
	bool Insert(const K& key, const V& value)
	{
		if (!_root){ _root = new Node(key, value); return true; }//��֤����Ĳ������������˫��
		
		Node *parent = NULL, *cur = _root;
		while (cur){//�����ò��裬�ҵ�����Ҫ�����λ��
			parent = cur;
			if (key > cur->_key)cur = cur->_right;
			else if (key < cur->_key)cur = cur->_left;
			else return false;
		}

		cur = new Node(key, value);//������ô�����Ƚ������뵽����
		if (key > parent->_key){
			parent->_right = cur;//2 cur�嵽parent�ң�parent.bf++;
			++parent->_bf;
		}
		else{
			parent->_left = cur;//1 cur�嵽parent��parent.bf--;
			--parent->_bf;
		}
		cur->_parent = parent;

		//3 ��parent.bf == 0,��parentΪ�������ĸ߶Ȳ���
		//4 ��|parent.bf| == 1,�߶ȱ��ˣ��������ϸ���
		//5 ��|parent.bf| == 2,�������ϸ����ˣ���ʼ��תƽ����
		while (parent){//һֱ�����Ƚ���ߣ�ֱ��Ѱ��|parent->_bf|==2�Ľ��
			if (!parent->_bf)return true;//�����ߵ�����䣬˵����������Ҫ��ת
			else if(parent->_bf ==1 || parent->_bf == -1){
				cur = parent; parent = parent->_parent;
				if (parent){
					if (cur == parent->_left)--parent->_bf;
					else ++parent->_bf;
				}
			}else{
				if (parent->_bf == -2){//��������ߵ�������ô˵��������Ҫ��ת
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
		if (!cur)return false;//��curΪ��,��ʾ������û�иùؼ���

		//ɾ�����ǰ��
		//һ.parent->_bf == 0;�����õ�ƽ�⣩
		//��.| parent->_bf | == 1����ɾ���ϸߵ������Ľ�㣨���õ�ƽ�⣩
		//��.| parent->_bf | == 1����ɾ���ϰ��������Ľ�㣨��Ҫ��ƽ�⣩

		Node *parent = cur->_parent, *del = cur;
		//��ɾ���˽����˵��
		//��cur��Ϊ�գ����ж�cur�Ƿ�Ϊ_root ��cur��Ϊ��,���ж�cur�Ƿ�Ϊ_root��cur���Ҷ���Ϊ��
		if (!cur->_left)//��cur��Ϊ��
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
		else if (!cur->_right)//����Ϊ��
		{
			if (cur != _root){
				if (cur == parent->_left){ parent->_left = cur->_left; if (cur->_left)cur->_left->_parent = parent; parent->_bf++; }
				else { parent->_right = cur->_left; if (cur->_left)cur->_left->_parent = parent;  parent->_bf--; }
			}
			else _root = cur->_left;
		}
		else//�����Ҷ���Ϊ��
		{
			parent = cur;
			Node *sub = cur->_right;
			while (sub->_left){ parent = sub; sub = sub->_left; }//Ѱ��sub

			if (parent != cur){ parent->_left = sub->_right; if (cur->_right)cur->_right->_parent = parent;  parent->_bf++; }//�����������ѭ������sub�߶���
			else { parent->_right = sub->_right; if (cur->_right)cur->_right->_parent = parent;  parent->_bf--; }//������ѭ��ʧЧʱ����subû���߶�

			cur->_key = sub->_key; cur->_value = sub->_value;//��sub�����kv����cur
			del = sub;
		}
		delete del;//�ͷŽ��

		//ɾ������
		//һ.parent->_bf <= 1;�����õ�ƽ�⣩
		//��.| parent->_bf | == 2;����Ҫ��ƽ�⣩
		if (parent->_bf == 2)
		{
			cur = parent->_right;
			if (cur->_bf == 0 || cur->_bf == 1)
			{
				int bf = cur->_bf;//��ǰ��¼
				RotateL(parent);//����Ҫ����ƽ������
				if (bf == 0){ parent->_bf = 1; cur->_bf = -1; }//���µ���ƽ������
				else{ parent->_bf = cur->_bf = 0; }
			}
			else
			{
				RotateRL(parent);//˫��ʱ���Ѿ���ƽ�����ӵ���ƽ����
			}
		}
		else if (parent->_bf == -2)
		{
			cur = parent->_left;
			if (cur->_bf == 0 || cur->_bf == -1)
			{
				int bf = cur->_bf;//��ǰ��¼
				RotateR(parent);//����Ҫ����ƽ������
				if (bf == 0){ parent->_bf = -1; cur->_bf = 1; }//���µ���ƽ������
				else{ parent->_bf = cur->_bf = 0; }
			}
			else
			{
				RotateLR(parent);//˫��ʱ���Ѿ���ƽ�����ӵ���ƽ����
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
	//6 ���ҵ���������������˫��������˫��
	void RotateR(Node *parent)//�ҵ���
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		Node *pparent = parent->_parent;

		parent->_left = subLR;
		if (subLR)subLR->_parent = parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent != _root){//�ж�parent�ǲ��Ǹ����
			if (pparent->_left == parent)pparent->_left = subL;
			else pparent->_right = subL;//����parent���Ǹ���㣬�ж�parent��˫�׵�������
		}else _root = subL;
		subL->_parent = pparent;

		parent->_bf = subL->_bf = 0;//��ƽ�����ӱ������㣬�ⲽֻ���ò������棨ʵ���ϣ������ŵ�������ѣ�
	}
	void RotateL(Node *parent)//����
	{
		Node *subR = parent->_right;//��ʵ���Ǵ������������֮������ӹ�ϵ
		Node *subRL = subR->_left;
		Node *pparent = parent->_parent;

		parent->_right = subRL;//����parent��subRL֮��Ĺ�ϵ
		if (subRL)subRL->_parent = parent;

		subR->_left = parent;//����parent��subR֮��Ĺ�ϵ
		parent->_parent = subR;

		if (parent != _root){//����subR��pparent֮��Ĺ�ϵ
			if (pparent->_left == parent)pparent->_left = subR;
			else pparent->_right = subR;
		}else _root = subR;//ע���:����parent�Ǹ���㣬��ô������¸����
		subR->_parent = pparent;

		parent->_bf = subR->_bf = 0;//ƽ�����ӱ������㣬�ⲽֻ���ò������棨ʵ���ϣ������ŵ�������ѣ�
	}
	//����ʱ��ƽ�����Ӳ�������⣬������˫��ʱ�������,������Ҫ���⴦��һ��
	void RotateRL(Node *parent)//����˫��
	{
		Node *subR = parent->_right;
		Node *subRL = subR->_left;
		int bf = subRL->_bf;//��¼subRL��û��תʱ���ƽ������
		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)parent->_bf = -1;
		else if (bf == -1)subR->_bf = 1;
	}
	void RotateLR(Node *parent)//����˫��
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		int bf = subLR->_bf;//��¼subLR��û��תʱ���ƽ������
		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)subL->_bf = -1;
		else if (bf == -1)parent->_bf = 1;
	}

	int _Height(Node *root)//�ú����ĺ�����:�����rootΪ���������߶�
	{
		if (!root)return 0;//�����Ϊ�գ���ô���ظ߶�0

		int LeftHeight = _Height(root->_left);//���������ĸ߶�
		int RightHeight = _Height(root->_right);//���������ĸ߶�

		return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
	}
	bool _Isbalance(Node *root)//�ú����ĺ���:�ж���rootΪ���������Ƿ�ƽ��
	{//�жϷ���:�������ĸ߶����������ĸ߶Ȳ�ܳ���1
		if (!root)return true;//���������Ϊ��������ô�������϶�Ϊ��������ƽ���

		int LeftHeight = _Height(root->_left);//�õ��������ĸ߶�
		int RightHeight = _Height(root->_right);//�õ��������ĸ߶�

		//�����������ƽ��ģ���ô�����ݹ��ҷ���false;
		//Ҫ�Ǹ�����ƽ��ģ���ô��ݹ��ȥ�ӹ��̣������ж��������������Ƿ�ƽ��
		return abs(LeftHeight - RightHeight) < 2//���ж��Լ��ǲ���ƽ���
			&& _Isbalance(root->_left)//���ж��������ǲ���ƽ���
			&& _Isbalance(root->_right);//���ж��������ǲ���ƽ���

		//���return��ĺ��ã�����������������ǰ�������ݹ�
	}
	//�����Ż�ʱ����������������ǰ��ĳɺ���,
	//   (ע�⣬�����return����ô������ǰ�����ú��������Ժ����ж���������ʱ��Ҫ�����return�����������)
	bool _IsbalanceOP(Node *root,int& height)
	{
		if (!root){ height = 0; return true; }//���Ϊ��������ô�����ĸ߶������Ҹ�����ƽ���

		int LeftHeight = 0;//�ֲ�����
		int RightHeight = 0;//�ֲ�����

		if (_IsbalanceOP(root->_left, LeftHeight) == false)//���ж��������ǲ���ƽ���
			return false;                //�ֲ�����������
		if (_IsbalanceOP(root->_right, RightHeight) == false)//���ж��������ǲ���ƽ���
			return false;                 //�ֲ�����������

		height = LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
		//ͨ���������ֻ��ƣ�����ʵ�������ݹ麯���и�����һ��ݹ麯���ľֲ�����

		return abs(LeftHeight - RightHeight) < 2;//���ж��Լ��ǲ���ƽ���
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