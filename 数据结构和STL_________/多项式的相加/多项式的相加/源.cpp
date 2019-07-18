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

void creat(nu* &head, char *p1)//��������
{
	head = new nu;
	nu *tail = head;
	char *p = p1;
	while (*p)
	{
		int m = 0, n = 0;
		char ch2 = *(p-1);//��һ���ַ�ch2���ÿ��ķ���
		//if (p == p1)ch2 = *p;
		//else ch2 = *(p - 1);

		nu *node = new nu;//�������
		while (isdigit(*p))
		{
			if (isdigit(*p))
				m = 10 * m + *p - '0';//����ϵ��m

			++p;
		}
		char ch = *p;//��ch�����δ֪��x�Ƿ����
		if (*p == 'x')++p;
		if (*p == '^')++p;

		while (isdigit(*p))
		{
			if (isdigit(*p))
				n = 10 * n + *p - '0';//����ָ��n
			++p;
		}
		++p;

		if (ch == 'x'&&!n)//����x��ָ��Ϊ1�������
			n = 1;
		if (ch2 == '-')//����x��ϵ��Ϊ���������
			m = -m;

		node->_num = m;
		node->_exe = n;

		tail->_next = node;
		tail = tail->_next;
	}

}

void merge(nu * &head1, nu *head2)//������head2ָ�������û��
{
	nu *cur1 = head1->_next;
	nu *cur2 = head2->_next;

	if (cur1->_exe > cur2->_exe)//��֤cur1ָ��ָ����С���Ǹ�����ʽ
	{
		nu *tmp = cur1;
		cur1 = cur2;
		cur2 = tmp;
	}
	head1->_next = cur1;//����ͷ���ָ��

	while (cur2)
	{
		nu *next = cur1->_next;

		if (cur2->_exe == next->_exe)//����ָ����ȣ�Ҫɾ�����
		{
			nu *tmp = cur2;
			next->_num += cur2->_num;
			cur2 = cur2->_next;
			delete tmp;
			if (!next->_num)//ϵ��Ϊ������
			{
				cur1->_next = next->_next;
				delete next;
			}
		}
		else if (cur2->_exe < next->_exe)    //�����Ǹ���������������cur1����
		{
			nu *tmp = cur2;
			cur2 = cur2->_next;
			
			tmp->_next = cur1->_next;
			cur1->_next = tmp;

			cur1 = cur1->_next;
		}
		else                      //��cur1��next�������һλ
		{
			cur1 = next;
			next = next->_next;
		}
	}
}

void print(const nu *head)//��ӡ����
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
	//���ǵĶ���ʽ��ָ�����Ǵ��ڵ����������������ָ��ֵС����ǰ��
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