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
{                       //让invalue作为特殊值
	Bintree *p = NULL;
	if (index < len && arr[index] != invalue)
	{
		p = (Bintree*)malloc(sizeof(Bintree));
		p->_data = arr[index];
		p->lchild = Tree0(arr, len, invalue, ++index);  //递归创建左子树
		p->rchild = Tree0(arr, len, invalue, ++index);  //递归创建右子树
	}
	return p;
}
Bintree* CreateBinaryTree(int *arr, int len, int invalue)
{
	int index = 0;
	return Tree0(arr, len, invalue, index);
}

//Bintree *pre;                       //全局变量
//void thred1(Bintree *p)
//{
//	if (p != NULL)
//	{
//		thred1(p->lchild);          //左子树线索化
//		if (p->lchild == NULL)        //前驱线索
//		{
//			p->lchild = pre;          //建立当前结点的前驱线索
//			p->ltag = 1;
//		}
//		else p->ltag = 0;
//		if (pre->rchild == NULL)      //后继线索
//		{
//			pre->rchild = p;          //建立前驱结点的后继线索
//			pre->rtag = 1;
//		}
//		else pre->rtag = 0;
//		pre = p;
//		thred1(p->rchild);          //右子树线索化
//	}
//}
Bintree* prev1;                 //全局变量
void Inthreading(Bintree *&p)//真正在线索化二叉树
{
	if (p)
	{
		Inthreading(p->lchild);//左子树线索化（只有某个节点的左子树线索化完成才能执行下面的语句）
		if (!p->lchild)                   //前驱线索
		{
			p->lchild = prev1;          //建立当前结点的前驱线索
			p->ltag = 1;
		}
		else p->ltag = 0;

		if (!prev1->rchild)             //后继线索
		{
			prev1->rtag = thread;            
			prev1->rchild = p;         //建立前驱结点的后继线索
		}
		else prev1->rtag = 0;

		prev1 = p;
		Inthreading(p->rchild);         //右子树线索化
	}
}

//Bintree *CreaThread(Bintree *b)     //中序线索化二叉树
//{
//	Bintree *root;
//	root = (Bintree *)malloc(sizeof(Bintree));  //创建根结点
//	root->ltag = 0;
//	root->rtag = 1;
//	root->rchild = b;
//	if (b == NULL)                //空二叉树
//		root->lchild = root;
//	else
//	{
//		root->lchild = b;
//		pre = root;               //pre是*p的前驱结点,供加线索用
//		thred1(b);              //中序遍历线索化二叉树
//		pre->rchild = root;       //最后处理,加入指向根结点的线索
//		pre->rtag = 1;
//		root->rchild = pre;       //根结点右线索化
//	}
//	return root;
//}
Bintree* Inorderthreading(Bintree *t)//中序线索化二叉树
{
	Bintree* thrt;
	if (!(thrt = (Bintree*)malloc(sizeof(Bintree))))exit(OVERFLOW);//创建根结点
	thrt->ltag = link; thrt->rtag = thread; thrt->rchild = t;
	if (!t)thrt->lchild = thrt;
	else
	{
		thrt->lchild = t; prev1 = thrt;
		Inthreading(t);//中序遍历线索化二叉树
		prev1->rchild = thrt; prev1->rtag = thread; thrt->rchild = prev1;
	}
	return thrt;
}




//void ThInOrder(Bintree *tb)
//{
//	Bintree *p = tb->lchild;      //指向根结点
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
void Inorderthread(Bintree *t)//非递归中序遍历线索二叉树
{
	Bintree *p = t->lchild;
	while (p != t)                  //考虑换成当型循环（否则改了代码该函数不会生效）
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
//void Preorder(Bintree* t)//递归先序遍历并且打印(根左右——NLR)
//{
//	if (t)
//	{
//		printf("%d ", t->_data);
//		Preorder(t->lchild);
//		Preorder(t->rchild);
//	}
//}
void Inorder(Bintree* t)//递归中序遍历并且打印（左根右——LNR）
{
	if (t)
	{
		Inorder(t->lchild);
		printf("%d ", t->_data);
		Inorder(t->rchild);
	}
}
//void Postorder(Bintree* t)//递归后序遍历并且打印（左右根——LRN）
//{
//	if (t)
//	{
//		Postorder(t->lchild);
//		Postorder(t->rchild);
//		printf("%d ", t->_data);
//	}
//}