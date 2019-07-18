#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<ctype.h>

typedef struct number
{
	int _num;
	int _exe;
	struct number * _next;

	number(int num = 0, int exe = 0, number *next = NULL)
		:_num(num), _exe(exe), _next(NULL)
	{}
}nu;

void creat(nu* &head, char *p1)//创建链表
{
	head = new nu;
	nu *tail = head;
	char *p = p1;
	while (*p)
	{
		int m = 0, n = 0;
		char ch2 = *(p-1);//用一个字符ch2标记每项的符号
		//if (p == p1)ch2 = *p;
		//else ch2 = *(p - 1);

		nu *node = new nu;//建立结点
		while (isdigit(*p))
		{
			if (isdigit(*p))
				m = 10 * m + *p - '0';//计算系数m

			++p;
		}
		char ch = *p;//用ch来标记未知数x是否存在
		if (*p == 'x')++p;
		if (*p == '^')++p;

		while (isdigit(*p))
		{
			if (isdigit(*p))
				n = 10 * n + *p - '0';//计算指数n
			++p;
		}
		++p;

		if (ch == 'x'&&!n)//处理x的指数为1的情况，
			n = 1;
		if (ch2 == '-')//处理x的系数为负数的情况
			m = -m;

		node->_num = m;
		node->_exe = n;

		tail->_next = node;
		tail = tail->_next;
	}

}

void merge(nu * &head1, nu *head2)//结合完后head2指向的链表没了
{
	nu *cur1 = head1->_next;
	nu *cur2 = head2->_next;

	if (cur1->_exe > cur2->_exe)//保证cur1指向指数最小的那个多项式
	{
		nu *tmp = cur1;
		cur1 = cur2;
		cur2 = tmp;
	}
	head1->_next = cur1;//更正头结点指向

	while (cur2)
	{
		nu *next = cur1->_next;

		if (cur2->_exe == next->_exe)//假如指数相等，要删除结点
		{
			nu *tmp = cur2;
			next->_num += cur2->_num;
			cur2 = cur2->_next;
			delete tmp;
			if (!next->_num)//系数为零的情况
			{
				cur1->_next = next->_next;
				delete next;
			}
		}
		else if (cur2->_exe < next->_exe)    //否则将那个结点拆下来，链到cur1后面
		{
			nu *tmp = cur2;
			cur2 = cur2->_next;
			
			tmp->_next = cur1->_next;
			cur1->_next = tmp;

			cur1 = cur1->_next;
		}
		else                      //将cur1和next都向后移一位
		{
			cur1 = next;
			next = next->_next;
		}
	}
}

void print(const nu *head)//打印链表
{
	nu *cur = head->_next;
	while (cur)
	{
		cout << cur->_num << "x^" << cur->_exe << "  ";
		cur = cur->_next;
	}
	cout << endl;
}

int main()
{
	//考虑的多项式的指数都是大于等于零的正整数，且指数值小的在前面
	char *p = "7+3x+9x^8-5x^17";
	char *p2 = "8x+22x^7-9x^8";
	nu *head = NULL;
	nu *head2 = NULL;

	creat(head, p);
	print(head);

	creat(head2, p2);
	print(head2);

	merge(head, head2);
	print(head);

	system("pause");
	return 0;
}