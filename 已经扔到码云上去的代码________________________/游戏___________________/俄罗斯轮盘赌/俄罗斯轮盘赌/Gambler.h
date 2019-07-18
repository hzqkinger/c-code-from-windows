#pragma once
#include<stdlib.h>
#include<time.h>

typedef struct nod{
	int _i;
	struct nod *_next;
	nod(int i) :_i(i), _next(nullptr){}
}Node;

class List{
public:
	List(int num) :_head(nullptr)
	{
		Insert(num);
	}
	void Victor()
	{
		Erase();
		cout << endl << _head->_i;//������ʣ�µ��Ǹ��˵ı��
	}

private:
	Node *_head;
	void Insert(int n)//�õ�ѭ�����������������������
	{
		if (n <= 0)return;

		Node *cur = _head;
		for (int i = 1; i <= n; ++i)
		{
			if (_head == nullptr)
			{
				cur = _head = new Node(i);
			}
			else
			{
				cur->_next = new Node(i);
				cur = cur->_next;
			}
		}
		cur->_next = _head;
	}
	void Erase()//�ú�����������ɾ�����ݣ�ֱ��ֻʣ��һ������
	{
		if (_head == nullptr)return;

		srand(time(NULL));

		Node *_cur = _head, *_prev = _head;
		while (_prev->_next != _head)_prev = _prev->_next;
		while (_cur != _prev)//����ѭ�����ֻ꣬��ʣ��һ������
		{
			int times = rand() % 7;//0~6
			while (times == 0)times = rand() % 7;//1~6
			while (--times)//ģ��ڼ��ο�ǹ����ʵ��
			{
				_prev = _prev->_next;
				_cur = _cur->_next;
			}
			_prev->_next = _cur->_next;

			cout << _cur->_i << " ";//��������������ߵı��(�������Բ�Ҫ)

			delete _cur;//ɾ��������
			_cur = _prev->_next;//��_curָ������ߵ���һ��λ��
		}
		_head = _prev;
	}
};

void test()
{
	List li(5);
	li.Victor();
}