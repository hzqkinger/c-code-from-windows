#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<CoreWindow.h>
#include<iostream>
using namespace std;
#include<assert.h>

typedef int datatype;
typedef struct Bintree_Node{
	datatype _data;
	struct Bintree_Node *lchild;
	struct Bintree_Node *rchild;
	Bintree_Node() :_data(-1), lchild(NULL), rchild(NULL)
	{}
}Bintree;

#define Stack_init_size 100
#define Stack_increment 10

#define DateType Bintree*
typedef struct{
	DateType *base;
	DateType *top;
	int stacksize;
}Stack1;

void Initstack1(Stack1& s)//①
{
	s.base = (DateType*)malloc(Stack_init_size*sizeof(DateType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.stacksize = Stack_init_size;
}
int StackIsempty1(Stack1 s)//④
{
	assert(s.base);
	if (s.top - s.base)
		return 0;
	else
		return 1;
}
DateType Gettop1(Stack1 s, DateType& e)//⑤
{
	if (!StackIsempty1(s))
	{
		e = *(s.top - 1);
		return e;
	}
	else
		exit(-1);
}
void Push1(Stack1& s, DateType e)
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (DateType*)realloc(s.base, (s.stacksize + Stack_increment)*sizeof(DateType));
		if (!s.base)
			exit(-1);
		s.top = s.base + s.stacksize;
		s.stacksize += Stack_increment;
	}
	*s.top++ = e;
}
void Pop1(Stack1& s, DateType& e)
{
	if (s.top == s.base)
		exit(-1);
	e = *--s.top;
}


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
bool Isempty(Bintree*t)//树为空返回true，否则返回false
{
	if (!t)
		return true;
	else
		return false;
}
Bintree *Root(Bintree*t)//若果树不为空，返回指向树的根的指针，否则返回空
{
	if (!Isempty(t))
		return t;
	else
		return NULL;
}

Bintree* Find(Bintree*t, datatype e)//有点像从众多叶子节点汇聚到根部的意思
{
	if (t == NULL)
		return NULL;
	if (t->_data == e)
		return t;
	Bintree* pCur = NULL;
	if (pCur = Find(t->lchild, e))
		return pCur;
	return Find(t->rchild, e);
}
void Assign(Bintree*t, Bintree *pos, datatype x)//pos节点都找到了，直接赋值就可以了
{
	pos->_data = x;
}

void Destroy_tree(Bintree*&t)//或者用引用接收传过来的一级指针
{
	if (t)
	{
		Destroy_tree(t->lchild);
		Destroy_tree(t->rchild);
		free(t);
		t = NULL;
	}
}
void Destroy_tree2(Bintree**t)//想要改变一级指针，就要用二级指针接收一级指针的地址
{
	if (*t)
	{
		Destroy_tree2(&(*t)->lchild);
		Destroy_tree2(&(*t)->rchild);
		free(*t);
		*t = NULL;
	}
}
void Deletechild(Bintree*&t, Bintree *&pos, char lr)//删除子树
{
	if (lr == 'l')
		Destroy_tree(pos->lchild);
	else if (lr == 'r')
		Destroy_tree(pos->rchild);
}
void Insertchild(Bintree*&t, Bintree*child, Bintree *&pos, char lr)//插入子树
{
	if (lr == 'l')
	{
		Destroy_tree(pos->lchild);
		pos->lchild = child;
	}
	else if (lr == 'r')
	{
		Destroy_tree(pos->rchild);
		pos->rchild = child;
	}
}


void Pre_cnt(Bintree* t,const size_t &k,size_t &i)
{
	if (!t)
		--i;//每次调用函数，i的值都会增加1，假如t为空就让i值回退一位
	if (t)
	{
		if (i == k)
			printf("%d ", t->_data);
		Pre_cnt(t->lchild, k, ++i);
		Pre_cnt(t->rchild, k, ++i);
	}
}
void Preorder_count(Bintree* t, const size_t &k)//求先序序列中第k个位置的结点的值
{
	size_t i = 1;
	Pre_cnt(t, k, i);
	cout << endl;
}
void Pre_leaves_cnt0(Bintree* t,size_t &count)
{
	if (t)
	{
		if (!t->lchild && !t->rchild)
			count++;
		Pre_leaves_cnt0(t->lchild, count);
		Pre_leaves_cnt0(t->rchild, count);
	}
}
void Pre_leaves_cnt(Bintree* t)//计算二叉树中叶子结点的数目
{
	size_t count = 0;
	Pre_leaves_cnt0(t, count);
	cout << count << endl;
}
void Pre_lr_change(Bintree* t)//将二叉树中所有结点的左右子树相互交换
{
	if (t)
	{
		Bintree* tmp;
		tmp = t->lchild;
		t->lchild = t->rchild;
		t->rchild = tmp;
		Pre_lr_change(t->lchild);
		Pre_lr_change(t->rchild);
	}
}
void Pre_deletex_child(Bintree* t, datatype value)//对于二叉树中每一个元素值为value的结点，删去以它为根的子树
{
	if (t)
	{
		if (t->_data == value)
		{
			Destroy_tree(t->lchild);
			Destroy_tree(t->rchild);
		}
		Pre_deletex_child(t->lchild, value);
		Pre_deletex_child(t->rchild, value);
	}
}

void Pre_copy_trees(Bintree* &t, const Bintree* soutree)//递归算法复制一棵二叉树
{
	if (soutree)
	{
		t = (Bintree*)malloc(sizeof(Bintree));
		t->_data = soutree->_data;
		t->lchild = t->rchild = NULL;
		Pre_copy_trees(t->lchild,soutree->lchild);
		Pre_copy_trees(t->rchild,soutree->rchild);
	}
}
//待处理
void Pre_copy_trees2(Bintree* &dstree, Bintree* soutree)//非递归算法复制一棵二叉树
{
	Stack1 s; Stack1 s2;  Bintree* t = dstree; Bintree* p = soutree;
	Initstack1(s);Initstack1(s2);
	while (p || !StackIsempty1(s))
	{
		if (p)//根指针进栈，访问根节点，遍历左子树
		{
			Push1(s, p);
			if (!dstree)
			{
				dstree = t = (Bintree*)malloc(sizeof(Bintree));

			}
			else
				t = (Bintree*)malloc(sizeof(Bintree));
			Push1(s2, t);
			t->_data = p->_data;
			t->lchild = t->rchild = NULL;
			p = p->lchild;
			t = t->lchild;
		}
		else//根指针退栈，遍历右子树
		{
			Pop1(s, p);
			Pop1(s2, t);
			p = p->rchild;
			t = t->rchild;
		}
	}
	cout << endl;
}



void Preorder(Bintree* t)//递归先序遍历并且打印(根左右——NLR)
{
	if (t)
	{
		printf("%d ", t->_data);
		Preorder(t->lchild);
		Preorder(t->rchild);
	}
}
void Preorder3(Bintree* t)//非递归前序遍历（这里不会向栈里压NULL指针，高效）
{
	Stack1 s; Bintree* p = t;
	Initstack1(s);
	while (p || !StackIsempty1(s))
	{
		if (p)//根指针进栈，访问根节点，遍历左子树
		{
			Push1(s, p);
			if (p)cout << p->_data << " ";
			p = p->lchild;
		}
		else//根指针退栈，遍历右子树
		{
			Pop1(s, p);
			p = p->rchild;
		}
	}
	cout << endl;
}
void Inorder(Bintree* t)//递归中序遍历并且打印（左根右——LNR）
{
	if (t)
	{
		Inorder(t->lchild);
		printf("%d ", t->_data);
		Inorder(t->rchild);
	}
}
void Inorder2(Bintree* t)//非递归中序遍历（会向栈里压NULL指针）
{
	Stack1 s; Bintree* p;
	Initstack1(s); Push1(s, t);
	while (!StackIsempty1(s))
	{
		while (Gettop1(s, p))Push1(s, p->lchild);
		Pop1(s, p);
		if (!StackIsempty1(s))
		{
			Pop1(s, p);
			cout << p->_data << " ";
			Push1(s, p->rchild);
		}
	}
	cout << endl;
}
void Inorder3(Bintree* t)//非递归中序遍历（这里不会向栈里压NULL指针，高效）
{
	Stack1 s; Bintree* p = t;
	Initstack1(s);
	while (p || !StackIsempty1(s))
	{
		if (p)//根指针进栈，遍历左子树
		{
			Push1(s, p);
			p = p->lchild;
		}
		else//根指针退栈，访问根节点，遍历右子树
		{
			Pop1(s, p);
			if (p)cout << p->_data << " ";
			p = p->rchild;
		}
	}
	cout << endl;
}
void Postorder(Bintree* t)//递归后序遍历并且打印（左右根——LRN）
{
	if (t)
	{
		Postorder(t->lchild);
		Postorder(t->rchild);
		printf("%d ", t->_data);
	}
}