#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<assert.h>
#include<CoreWindow.h>

#define eletype int
typedef struct qnode{
	eletype _data;
	struct qnode *_next;
}Qnode;

typedef struct{
	Qnode *front;
	Qnode *rear;
}Qlink;

void InitQueue(Qlink &q)
{
	q.front = q.rear = NULL;
}
void DestroyQueue(Qlink &q)
{
	while (q.front)
	{
		q.rear = q.front->_next;
		delete q.front;
		q.front = q.rear;
	}
}
bool Is_EmptyQueue(const Qlink &q)
{
	if (q.front - q.rear)
		return true;
	return false;
}

int QueueLength(const Qlink &q)
{
	return q.front - q.rear;
}
eletype GetHead(const Qlink &q, eletype &e)//直接得到头部的数据。
{
	assert(q.front);
	e = q.front->_data;
	return e;
}

void EnQueue(Qlink &q, eletype e)
{
	Qnode *p = new Qnode;
	p->_next = NULL;
	p->_data = e;
	if (!q.rear)
		q.front = q.rear = p;
	else
		q.rear->_next = p;
	q.rear = p;
}
eletype DeQueue(Qlink &q, eletype &e)//先得到头部的数据，然后再头删。
{
	assert(q.front);
	Qnode *tmp = q.front->_next;
	e = q.front->_data;
	delete q.front;
	q.front = tmp;
	return e;
}

void ShowQueue(Qlink &q)
{
	Qnode *tmp = q.front;
	while (tmp)
	{
		cout << tmp->_data << "->";
		tmp = tmp->_next;
	}
	cout << endl;
}
int main()
{
	Qlink q;
	eletype e;
	InitQueue(q);
	EnQueue(q,1);
	EnQueue(q, 2);
	EnQueue(q, 3);
	EnQueue(q, 4);
	ShowQueue(q);

	DeQueue(q, e);
	ShowQueue(q);

	DeQueue(q, e);
	ShowQueue(q);
	GetHead(q, e);

	system("pause");
	return 0;
}