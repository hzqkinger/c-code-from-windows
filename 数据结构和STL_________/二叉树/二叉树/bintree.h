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

void Initstack1(Stack1& s)//��
{
	s.base = (DateType*)malloc(Stack_init_size*sizeof(DateType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.stacksize = Stack_init_size;
}
int StackIsempty1(Stack1 s)//��
{
	assert(s.base);
	if (s.top - s.base)
		return 0;
	else
		return 1;
}
DateType Gettop1(Stack1 s, DateType& e)//��
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
bool Isempty(Bintree*t)//��Ϊ�շ���true�����򷵻�false
{
	if (!t)
		return true;
	else
		return false;
}
Bintree *Root(Bintree*t)//��������Ϊ�գ�����ָ�����ĸ���ָ�룬���򷵻ؿ�
{
	if (!Isempty(t))
		return t;
	else
		return NULL;
}

Bintree* Find(Bintree*t, datatype e)//�е�����ڶ�Ҷ�ӽڵ��۵���������˼
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
void Assign(Bintree*t, Bintree *pos, datatype x)//pos�ڵ㶼�ҵ��ˣ�ֱ�Ӹ�ֵ�Ϳ�����
{
	pos->_data = x;
}

void Destroy_tree(Bintree*&t)//���������ý��մ�������һ��ָ��
{
	if (t)
	{
		Destroy_tree(t->lchild);
		Destroy_tree(t->rchild);
		free(t);
		t = NULL;
	}
}
void Destroy_tree2(Bintree**t)//��Ҫ�ı�һ��ָ�룬��Ҫ�ö���ָ�����һ��ָ��ĵ�ַ
{
	if (*t)
	{
		Destroy_tree2(&(*t)->lchild);
		Destroy_tree2(&(*t)->rchild);
		free(*t);
		*t = NULL;
	}
}
void Deletechild(Bintree*&t, Bintree *&pos, char lr)//ɾ������
{
	if (lr == 'l')
		Destroy_tree(pos->lchild);
	else if (lr == 'r')
		Destroy_tree(pos->rchild);
}
void Insertchild(Bintree*&t, Bintree*child, Bintree *&pos, char lr)//��������
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
		--i;//ÿ�ε��ú�����i��ֵ��������1������tΪ�վ���iֵ����һλ
	if (t)
	{
		if (i == k)
			printf("%d ", t->_data);
		Pre_cnt(t->lchild, k, ++i);
		Pre_cnt(t->rchild, k, ++i);
	}
}
void Preorder_count(Bintree* t, const size_t &k)//�����������е�k��λ�õĽ���ֵ
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
void Pre_leaves_cnt(Bintree* t)//�����������Ҷ�ӽ�����Ŀ
{
	size_t count = 0;
	Pre_leaves_cnt0(t, count);
	cout << count << endl;
}
void Pre_lr_change(Bintree* t)//�������������н������������໥����
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
void Pre_deletex_child(Bintree* t, datatype value)//���ڶ�������ÿһ��Ԫ��ֵΪvalue�Ľ�㣬ɾȥ����Ϊ��������
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

void Pre_copy_trees(Bintree* &t, const Bintree* soutree)//�ݹ��㷨����һ�ö�����
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
//������
void Pre_copy_trees2(Bintree* &dstree, Bintree* soutree)//�ǵݹ��㷨����һ�ö�����
{
	Stack1 s; Stack1 s2;  Bintree* t = dstree; Bintree* p = soutree;
	Initstack1(s);Initstack1(s2);
	while (p || !StackIsempty1(s))
	{
		if (p)//��ָ���ջ�����ʸ��ڵ㣬����������
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
		else//��ָ����ջ������������
		{
			Pop1(s, p);
			Pop1(s2, t);
			p = p->rchild;
			t = t->rchild;
		}
	}
	cout << endl;
}



void Preorder(Bintree* t)//�ݹ�����������Ҵ�ӡ(�����ҡ���NLR)
{
	if (t)
	{
		printf("%d ", t->_data);
		Preorder(t->lchild);
		Preorder(t->rchild);
	}
}
void Preorder3(Bintree* t)//�ǵݹ�ǰ����������ﲻ����ջ��ѹNULLָ�룬��Ч��
{
	Stack1 s; Bintree* p = t;
	Initstack1(s);
	while (p || !StackIsempty1(s))
	{
		if (p)//��ָ���ջ�����ʸ��ڵ㣬����������
		{
			Push1(s, p);
			if (p)cout << p->_data << " ";
			p = p->lchild;
		}
		else//��ָ����ջ������������
		{
			Pop1(s, p);
			p = p->rchild;
		}
	}
	cout << endl;
}
void Inorder(Bintree* t)//�ݹ�����������Ҵ�ӡ������ҡ���LNR��
{
	if (t)
	{
		Inorder(t->lchild);
		printf("%d ", t->_data);
		Inorder(t->rchild);
	}
}
void Inorder2(Bintree* t)//�ǵݹ��������������ջ��ѹNULLָ�룩
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
void Inorder3(Bintree* t)//�ǵݹ�������������ﲻ����ջ��ѹNULLָ�룬��Ч��
{
	Stack1 s; Bintree* p = t;
	Initstack1(s);
	while (p || !StackIsempty1(s))
	{
		if (p)//��ָ���ջ������������
		{
			Push1(s, p);
			p = p->lchild;
		}
		else//��ָ����ջ�����ʸ��ڵ㣬����������
		{
			Pop1(s, p);
			if (p)cout << p->_data << " ";
			p = p->rchild;
		}
	}
	cout << endl;
}
void Postorder(Bintree* t)//�ݹ����������Ҵ�ӡ�����Ҹ�����LRN��
{
	if (t)
	{
		Postorder(t->lchild);
		Postorder(t->rchild);
		printf("%d ", t->_data);
	}
}