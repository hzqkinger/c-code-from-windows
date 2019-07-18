#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<CoreWindow.h>
typedef struct complex{
	int data;
	struct complex *next;
	struct complex *random;
}ComNode;
ComNode* Buynode(int data)
{
	ComNode *tmp = (ComNode*)malloc(sizeof(ComNode));
	tmp->data = data;
	tmp->next = NULL;
	tmp->random = NULL;
	return tmp;
}
ComNode* complex_list_list(ComNode *phead)
{
	assert(phead);
	ComNode *tmp = NULL, *plist = phead;
	ComNode *copylist = NULL, *copyhead = copylist;
	ComNode *last = NULL;
	//插入
	while (plist)
	{
		tmp = Buynode(plist->data);
		tmp->next = plist->next;
		plist->next = tmp;
		plist = tmp->next;
	}
	//random的赋值
	plist = phead;
	tmp = plist->next;

	while (tmp->next)
	{
		tmp = plist->next;
		if (plist->random)
			tmp->random = plist->random->next;
		plist = tmp->next;

	}
	plist = phead;
	tmp = plist->next;

	//拆除
	while (tmp->next)
	{
		tmp = plist->next;
		last = tmp->next;
		plist->next = last;
		plist = last;
		if (!copylist)
		{
			copylist = tmp;
			copyhead = tmp;
		}
		else
		{
			copylist->next = tmp;
			copylist = tmp;
		}
	}
	return copyhead;
}
void print(ComNode *plist)
{
	while (plist)
	{
		if (plist->random)
			printf("%d ", plist->random->data);
		else
			printf("NULL ");
		plist = plist->next;
	}
	printf("\n");
}
int main()
{
	ComNode *head;

	ComNode *n1 = Buynode(1);
	ComNode *n2 = Buynode(2);
	ComNode *n3 = Buynode(3);
	ComNode *n4 = Buynode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	n1->random = n3;
	n2->random = n2;
	n3->random = NULL;
	n4->random = n1;
	print(n1);

	head = complex_list_list(n1);
	print(head);

	system("pause");
	return EXIT_SUCCESS;//头文件中包含了#define EXIT_SUCCESS 0和#define EXIT_FAILURE 1
}