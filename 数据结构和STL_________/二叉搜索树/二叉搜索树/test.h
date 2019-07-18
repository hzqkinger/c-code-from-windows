#pragma once
#include<stdlib.h>

typedef struct Node
{
	int _key;
	struct Node* _left;
	struct Node* _right;
	Node(int key)
		:_key(key), _left(NULL), _right(NULL)
	{}
}Node;

bool _Insert_Recursive2(Node **root, int key)
{
	if (!(*root)){
		*root = new Node(key);
		return true;
	}
	if (key == (*root)->_key)return false;//相等的情况，直接返回

	if (key < (*root)->_key)
		return _Insert_Recursive2(&(*root)->_left, key);//注意:这里的return起到了很重要的作用
	if (key >(*root)->_key){
		//Node *right = (*root)->_right;           //这两句代码错误，
		//return _Insert_Recursive2(&right, key);
		return _Insert_Recursive2(&(*root)->_right, key);
	}
}

void test()
{
	Node *root = NULL;
	_Insert_Recursive2(&root, 5);
	_Insert_Recursive2(&root, 3);
	_Insert_Recursive2(&root, 4);
	_Insert_Recursive2(&root, 4);
	_Insert_Recursive2(&root, 1);
	_Insert_Recursive2(&root, 0);
	_Insert_Recursive2(&root, 2);
	_Insert_Recursive2(&root, 7);
	_Insert_Recursive2(&root, 6);
	_Insert_Recursive2(&root, 8);
	_Insert_Recursive2(&root, 9);
}