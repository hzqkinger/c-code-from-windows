#pragma once



typedef enum pointertag{link,thread};
typedef int datatype;
typedef struct Bintree_Node{
	datatype _data;
	struct Bintree_Node *lchild;
	struct Bintree_Node *rchild;
	int ltag,rtag;
	Bintree_Node() :_data(-1), lchild(NULL), rchild(NULL), ltag(0), rtag(0)
	{}
}Bintree;

Bintree* Tree0(int *arr, int len, int invalue, int &index)
{                       //��invalue��Ϊ����ֵ
	Bintree *p = NULL;
	if (index < len && arr[index] != invalue)
	{
		p = (Bintree*)malloc(sizeof(Bintree));
		p->_data = arr[index];
		p->lchild = Tree0(arr, len, invalue, ++index);  //�ݹ鴴��������
		p->rchild = Tree0(arr, len, invalue, ++index);  //�ݹ鴴��������
	}
	return p;
}
Bintree* CreateBinaryTree(int *arr, int len, int invalue)
{
	int index = 0;
	return Tree0(arr, len, invalue, index);
}

//Bintree *pre;                       //ȫ�ֱ���
//void thred1(Bintree *p)
//{
//	if (p != NULL)
//	{
//		thred1(p->lchild);          //������������
//		if (p->lchild == NULL)        //ǰ������
//		{
//			p->lchild = pre;          //������ǰ����ǰ������
//			p->ltag = 1;
//		}
//		else p->ltag = 0;
//		if (pre->rchild == NULL)      //�������
//		{
//			pre->rchild = p;          //����ǰ�����ĺ������
//			pre->rtag = 1;
//		}
//		else pre->rtag = 0;
//		pre = p;
//		thred1(p->rchild);          //������������
//	}
//}
Bintree* prev1;                 //ȫ�ֱ���
void Inthreading(Bintree *&p)//������������������
{
	if (p)
	{
		Inthreading(p->lchild);//��������������ֻ��ĳ���ڵ����������������ɲ���ִ���������䣩
		if (!p->lchild)                   //ǰ������
		{
			p->lchild = prev1;          //������ǰ����ǰ������
			p->ltag = 1;
		}
		else p->ltag = 0;

		if (!prev1->rchild)             //�������
		{
			prev1->rtag = thread;            
			prev1->rchild = p;         //����ǰ�����ĺ������
		}
		else prev1->rtag = 0;

		prev1 = p;
		Inthreading(p->rchild);         //������������
	}
}

//Bintree *CreaThread(Bintree *b)     //����������������
//{
//	Bintree *root;
//	root = (Bintree *)malloc(sizeof(Bintree));  //���������
//	root->ltag = 0;
//	root->rtag = 1;
//	root->rchild = b;
//	if (b == NULL)                //�ն�����
//		root->lchild = root;
//	else
//	{
//		root->lchild = b;
//		pre = root;               //pre��*p��ǰ�����,����������
//		thred1(b);              //�������������������
//		pre->rchild = root;       //�����,����ָ�����������
//		pre->rtag = 1;
//		root->rchild = pre;       //�������������
//	}
//	return root;
//}
Bintree* Inorderthreading(Bintree *t)//����������������
{
	Bintree* thrt;
	if (!(thrt = (Bintree*)malloc(sizeof(Bintree))))exit(OVERFLOW);//���������
	thrt->ltag = link; thrt->rtag = thread; thrt->rchild = t;
	if (!t)thrt->lchild = thrt;
	else
	{
		thrt->lchild = t; prev1 = thrt;
		Inthreading(t);//�������������������
		prev1->rchild = thrt; prev1->rtag = thread; thrt->rchild = prev1;
	}
	return thrt;
}




//void ThInOrder(Bintree *tb)
//{
//	Bintree *p = tb->lchild;      //ָ������
//	while (p != tb)
//	{
//		while (p->ltag == 0) p = p->lchild;
//		printf("%d ", p->_data);
//		while (p->rtag == 1 && p->rchild != tb)
//		{
//			p = p->rchild;
//			printf("%d ", p->_data);
//		}
//		p = p->rchild;
//	}
//}
void Inorderthread(Bintree *t)//�ǵݹ������������������
{
	Bintree *p = t->lchild;
	while (p != t)                  //���ǻ��ɵ���ѭ����������˴���ú���������Ч��
	{
		while (p->ltag == link)p = p->lchild;
		cout << p->_data << " ";
		while (p->rtag == thread &&p->rchild != t)
		{
			p = p->rchild;
			cout << p->_data << " ";
		}
		p = p->rchild;
	}
	cout << endl;
}
//
//
//
//void Preorder(Bintree* t)//�ݹ�����������Ҵ�ӡ(�����ҡ���NLR)
//{
//	if (t)
//	{
//		printf("%d ", t->_data);
//		Preorder(t->lchild);
//		Preorder(t->rchild);
//	}
//}
void Inorder(Bintree* t)//�ݹ�����������Ҵ�ӡ������ҡ���LNR��
{
	if (t)
	{
		Inorder(t->lchild);
		printf("%d ", t->_data);
		Inorder(t->rchild);
	}
}
//void Postorder(Bintree* t)//�ݹ����������Ҵ�ӡ�����Ҹ�����LRN��
//{
//	if (t)
//	{
//		Postorder(t->lchild);
//		Postorder(t->rchild);
//		printf("%d ", t->_data);
//	}
//}