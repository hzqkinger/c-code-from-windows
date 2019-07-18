#pragma once
//���
//     �������һ�ö���������������ÿ�������������һ���洢λ����ʾ������ɫ��������red����black��ͨ�����κ�
//     һ���Ӹ��ڵ㵽Ҷ�ӽ���ϵļ�·����Լ�����������֤�·�����������·�����������������ƽ�⡣
//���ʣ�
//  1. ÿ����㲻�Ǻ�ɫ���Ǻ�ɫ
//  2. ���ڵ��Ǻ�ɫ��
//  3. ���һ�����ڵ��Ǻ�ɫ�ģ�����������Ҷ�ӽ���Ǻ�ɫ��(û�����������ĺ�ɫ���)
//  4. ����ÿ�����,�Ӹý�㵽�����к��Ҷ���ļ�·����,��������ͬ��Ŀ�ĺ�ɫ���(ÿ��·���Ϻ�ɫ�����������)
//  5. ÿ��Ҷ�ӽ�㶼�Ǻ�ɫ��(�˴���Ҷ�ӽ��ָ���ǿս��)

//�ָ��������������Ҫ����(O(log n))����ɫ���(ʵ���Ƿǳ����ٵ�)�Ͳ�������������ת(���ڲ������������)
enum en{RED,BLACK};

template<typename k,typename v>
struct RBTreeNode{
	k _key;
	v _value;
	RBTreeNode<k, v> *_left;
	RBTreeNode<k, v> *_right;
	RBTreeNode<k, v> *_parent;
	en _col;
	RBTreeNode(const k& key, const v& value)
		:_key(key), _value(value), _left(NULL), _right(NULL), _parent(NULL),_col(RED){}
};

template<typename k,typename v>
class RBTree{
	typedef RBTreeNode<k, v> Node;
public:
	RBTree() :_root(NULL){}

	Node* Find(const k& key)
	{
		Node *cur = _root;
		while (cur){
			if (key > cur->_key)cur = cur->_right;
			else if (key < cur->_key)cur = cur->_left;
			else return cur;//�����������д�����Ҫ�ҵ�ֵ����һ���������ﷵ��
		}
		return cur;//����������ﷵ��һ��NULL
	}
	bool Insert(const k& key, const v& value)
	{
		if (!_root){//��֤������Ĳ���������˫�׽���
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}

		Node *parent = NULL, *cur = _root;
		while (cur){//Ѱ�ҵ����ʵĲ���λ��
			parent = cur;
			if (key > cur->_key)cur = cur->_right;
			else if (key < cur->_key)cur = cur->_left;
			else return false;
		}
		cur = new Node(key, value);//�Ȱ����������Ĺ�������㣬Ȼ������������
		if (key>parent->_key)parent->_right = cur;
		else parent->_left = cur;
		cur->_parent = parent;

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
			}else{
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
		return true;
	}
	bool Remove(const k& key)
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
		Node *x,*del = cur;//ps:  ����ɾ������,del�����������Ҫɾ���Ľ��;��xΪ��֧�ĺ���������ʿ��ܱ��ƻ�
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
			RB_delete_fixup(x_parent,x);
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

		_Isbalance(_root, k,Nodnum);
	}

private:
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
		}else _root = subR;
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

	void RB_delete_fixup(Node *parent,Node *x)
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
	bool _Isbalance(Node *cur, const int k,int Nodnum)
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

	//void RB_transplant(Node *u, Node *v)
	//{         //ps:u����Ҫɾ���Ľ�㣬v���������u�Ľ��
	//	if (u->_parent == NULL)//uΪ��
	//		_root = v;
	//	else if (u->_parent->_left == u)//uΪ���׵�������
	//		u->_parent->_left == v;
	//	else//uΪ���׵�������
	//		u->_parent->_right == v;
	//	v->_parent = u->_parent;
	//}
	Node *_root;
};

void test_RBTree()
{
	RBTree<int,int> tree;

	tree.Insert(4, 1);
	tree.Insert(5, 1);
	tree.Insert(7, 1);
	tree.Insert(2, 1);
	tree.Insert(1, 1);
	tree.Insert(3, 1);
	tree.Insert(6, 1);

	tree.Remove(5);
	cout << tree.Isbalance() << endl;
	cout << "hah" << endl;



	//RBTree<int, int> tree;
	//for (size_t i = 1; i <= 100; ++i)
	//	tree.Insert(i, 1);
	//cout << tree.Isbalance() << endl;

	//for (size_t i = 0; i < 50; ++i)
	//{
	//	tree.Remove(2 * i + 1);
	//	cout << tree.Isbalance() << endl;
	//}

	////tree.Remove(32);
	////cout << tree.Isbalance() << endl;
}