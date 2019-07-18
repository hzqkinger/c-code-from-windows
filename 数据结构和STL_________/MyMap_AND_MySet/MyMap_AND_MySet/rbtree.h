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
	ref operator*()//_data�Ǹ���ͨ���ͣ���ָ���������͵���ָͨ��һ�������þ͵õ���ָ������ݣ�
	{
		return _node->_value;
	}
	ptr operator->()//����_data�Ǹ��Զ�������(eg.�Ǹ��ṹ��)����ָ���Զ������͵���ָͨ��һ����
	{
		return &(_node->_value);//���뷵�ض����ָ�루���ö����ָ�룩****�򷵻��Զ����˼�ͷ�������ĳ����Ķ���
	}

	self& operator++()//����ָͨ��һ��ǰ������
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
	self operator++(int)//����ָͨ��һ����������
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
	self& operator--()//����ָͨ��һ��ǰ���Լ�
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
	self operator--(int)//����ָͨ��һ�������Լ�
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
		while (cur->_left)//ע�⣬���ﲻ���ж�cur�Ƿ�Ϊ�գ���Ϊ���_rootΪ�ձ�����Ӧ�ñ����
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
		while (cur->_left)//ע�⣬���ﲻ���ж�cur�Ƿ�Ϊ�գ���Ϊ���_rootΪ�ձ�����Ӧ�ñ����
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
		if (!_root){//��֤������Ĳ���������˫�׽���
			_root = new Node(value);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		KorV _kv;
		Node *parent = NULL, *cur = _root;
		while (cur){//Ѱ�ҵ����ʵĲ���λ��
			parent = cur;
			if (_kv(value) > _kv(cur->_value))cur = cur->_right;
			else if (_kv(value) < _kv(cur->_value))cur = cur->_left;
			else return make_pair(cur, false);
		}
		cur = new Node(value);//�Ȱ����������Ĺ�������㣬Ȼ������������
		if (_kv(value) > _kv(parent->_value))parent->_right = cur;
		else parent->_left = cur;
		cur->_parent = parent;
		Node *subcur = cur;
		//��parentΪ��ɫʱ������Ҫ���κ������ˣ�ֻ��parentΪ��ɫʱ����Ҫ����������ת
		while (parent && parent->_col == RED){
			Node *grandfather = parent->_parent;
			if (parent == grandfather->_left){
				Node *uncle = grandfather->_right;//һ���ж��������ұ�

				if (uncle && uncle->_col == RED){//�����������Ϊ��
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;//�������ϸ���
					parent = cur->_parent;
				}
				else{//�����岻���ڻ������Ϊ��ɫ
					if (cur == parent->_right){
						RotateL(parent);//����
						swap(cur, parent);//ע���
					}
					RotateR(grandfather);//����
					parent->_col = BLACK;//��ת��ɺ�У��������ɫ
					grandfather->_col = RED;
				}
				_root->_col = BLACK;//�������¸�������ɫ
			}
			else{
				Node *uncle = grandfather->_left;//�����ж����������

				if (uncle && uncle->_col == RED){//�����������Ϊ��
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;//�������ϸ���
					parent = cur->_parent;
				}
				else{//�����岻���ڻ������Ϊ��ɫ
					if (cur == parent->_left){
						RotateR(parent);//����
						swap(cur, parent);//ע���
					}
					RotateL(grandfather);//����
					parent->_col = BLACK;//��ת��ɺ�У��������ɫ
					grandfather->_col = RED;
				}
				_root->_col = BLACK;//�������¸�������ɫ
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
		if (!cur)return false;//��curΪ��,��ʾ������û�иùؼ���

		//һ.��ɾ����Ӧ��ɾ���Ľ����˵
		// ����Ҫɾ���Ľ����Ϊ��
		// ����Ҫɾ���Ľ����Ϊ��
		// ����Ҫɾ���Ľ�����Ҷ���ΪΪ��
		Node *x, *del = cur;//ps:  ����ɾ������,del�����������Ҫɾ���Ľ��;��xΪ��֧�ĺ���������ʿ��ܱ��ƻ�
		bool del_original_color = del->_col;//��ɫ��0����ɫ��1

		if (!del->_left)//��Ϊ��
		{
			x = del->_right;
			//RB_transplant(del, x);
			if (del->_parent == NULL)//���del��_parentΪ�գ���del�Ǹ�
				_root = x;
			else if (del->_parent->_left == del)//delΪ���׵�����
				del->_parent->_left = x;
			else del->_parent->_right = x;

			if (x)x->_parent = del->_parent;
		}
		else if (!del->_right)//��Ϊ��
		{
			x = del->_left;
			//RB_transplant(del, x);
			if (del->_parent == NULL)//���del��_parentΪ�գ���del�Ǹ�
				_root = x;
			else if (del->_parent->_left == del)//delΪ���׵�����
				del->_parent->_left = x;
			else del->_parent->_right = x;

			if (x)x->_parent = del->_parent;
		}
		else//���Ҷ���Ϊ��
		{
			del = cur->_right;
			while (del->_left)del = del->_left;//�ҵ������㣬���������Ҫɾ���ĵ㣬Ȼ����ʵ����Ҫɾ���Ľ��ʱdel

			del_original_color = del->_col;//��ɫ��0����ɫ��1
			x = del->_right;

			if (del->_parent == cur)//�ж������ѭ���Ƿ�ִ�й�
				cur->_right = x;
			else
				del->_parent->_left = x;

			//cur->_col = del->_col;//ps,��仰һ������д
			cur->_key = del->_key;//��del����һЩ���ݿ�����cur���
			cur->_value = del->_value;
			if (x)x->_parent = del->_parent;
		}
		Node *x_parent = del->_parent;
		delete del;

		//��.ɾ��֮��ʼ�������������ɫ(��xΪ��֧�ĺ���������ʿ��ܱ��ƻ�,������Ҫ����)
		if (del_original_color == BLACK)//ֻ�е�del������ɫΪ��ɫ��ʱ��Ż��ƻ������������
			RB_delete_fixup(x_parent, x);
	}
	bool Isbalance()
	{
		if (!_root)return true;
		if (_root->_col == RED)return false;//���жϸ���ɫ�Ƿ�Ϊ��ɫ��ע�⣬�����Ϊ�ڣ�����Ҳ��һ����ȷ�������к��������������ߣ�

		//���ж��Ƿ���������ĺ�ɫ
		//���ж�ÿ��·���Ϻ�ɫ�����Ƿ����
		Node *cur = _root; int k = 0, Nodnum = 0;
		while (cur){//��Ϊ�����ÿ��·���ϵĺڽ��������һ���ģ����������һ��ֵ
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
		if (!cur){//ÿ��·����������ʱ���鿴Nodnum�������Ƿ���kһ��
			if (k != Nodnum)return false;
			return true;
		}
		if (cur->_col == RED && cur->_parent->_col == RED)//ע�⣬���ﲻ��ҪΪcur->_parent�пգ���Ϊ_root����ɫ�Ǻ�ɫ��
			return false;//������ÿ�����ʱ�鿴�������ĸ����ǲ��Ǻ�ɫ��

		if (cur->_col == BLACK)++Nodnum;

		return _Isbalance(cur->_left, k, Nodnum)
			&& _Isbalance(cur->_right, k, Nodnum);
	}
	void RB_delete_fixup(Node *parent, Node *x)
	{
		//��x���ֵܽ��w�Ǻ�ɫ��
		//��x���ֵܽ��w�Ǻ�ɫ�ģ���w�������ӽ�㶼�Ǻ�ɫ��
		//��x���ֵܽ��w�Ǻ�ɫ�ģ���w�������Ǻ�ɫ�ģ��Һ����Ǻ�ɫ��
		//��x���ֵܽ��w�Ǻ�ɫ�ģ���w���Һ����Ǻ�ɫ��
		while (!x || (x != _root && x->_col == BLACK))
		{
			if (x)parent = x->_parent;

			if (x == parent->_left)//x�ȿ��Բ�Ϊ�գ�Ҳ����Ϊ��
			{
				Node *brother = parent->_right;
				if (brother->_col == RED)//��
				{
					brother->_col = BLACK;
					parent->_col = RED;
					RotateL(parent);

					brother = parent->_right;//�������¸�ֵ
				}

				if (x && brother->_left->_col == BLACK && brother->_right->_col == BLACK)//��xһ������Ϊ��
				{
					brother->_col = RED;
					x = x->_parent;
					continue;//ִ�Т�֮�󣬲�֪��x�����¸��׵����ӻ����Һ��ӣ���������ѭ����ʼ
				}

				if (x && brother->_left->_col == RED && brother->_right->_col == BLACK)//��xһ������Ϊ��
				{
					brother->_left->_col = BLACK;
					brother->_col = RED;
					RotateR(brother);

					brother = x->_parent->_right;//�������¸�ֵ
				}

				if (brother->_right == NULL)
				{
					brother->_col = RED;
					x = parent;
					//continue;
				}
				else if (brother->_right->_col == RED)//��x�ȿ���Ϊ�գ�Ҳ���Բ�Ϊ��
				{
					brother->_col = parent->_col;
					parent->_col = BLACK;
					brother->_right->_col = BLACK;
					RotateL(parent);
					x = _root;//ִ�Т�ֻ�У�һ�������ѭ��
				}
			}
			else
			{
				Node *brother = parent->_left;
				if (brother->_col == RED)//��
				{
					brother->_col = BLACK;
					parent->_col = RED;
					RotateR(parent);

					brother = parent->_left;//�������¸�ֵ
				}

				if (x && brother->_left->_col == BLACK && brother->_right->_col == BLACK)//��
				{
					brother->_col = RED;
					x = x->_parent;
					continue;//ִ�Т�֮�󣬲�֪��x�����¸��׵����ӻ����Һ��ӣ���������ѭ����ʼ
				}

				if (x && brother->_left->_col == BLACK && brother->_right->_col == RED)//��
				{
					brother->_left->_col = BLACK;
					brother->_col = RED;
					RotateL(brother);

					brother = x->_parent->_left;//�������¸�ֵ
				}

				if (brother->_left == NULL)
				{
					brother->_col = RED;
					x = parent;
					//continue;
				}
				else if (brother->_left->_col == RED)//��
				{
					brother->_col = x->_parent->_col;
					parent->_col = BLACK;
					brother->_right->_col = BLACK;
					RotateR(parent);
					x = _root;//ִ�Т�ֻ�У�һ�������ѭ��
				}
			}
		}
		if (x)x->_col = BLACK;
	}

	Node *_root;
};