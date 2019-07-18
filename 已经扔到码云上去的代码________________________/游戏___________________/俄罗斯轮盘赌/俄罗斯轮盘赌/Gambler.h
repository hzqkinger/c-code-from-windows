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
		cout << endl << _head->_i;//输出最后剩下的那个人的编号
	}

private:
	Node *_head;
	void Insert(int n)//用单循环链表把所有数据链接起来
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
	void Erase()//该函数的作用是删除数据，直到只剩下一个数据
	{
		if (_head == nullptr)return;

		srand(time(NULL));

		Node *_cur = _head, *_prev = _head;
		while (_prev->_next != _head)_prev = _prev->_next;
		while (_cur != _prev)//整个循环走完，只会剩下一个数据
		{
			int times = rand() % 7;//0~6
			while (times == 0)times = rand() % 7;//1~6
			while (--times)//模拟第几次开枪会是实弹
			{
				_prev = _prev->_next;
				_cur = _cur->_next;
			}
			_prev->_next = _cur->_next;

			cout << _cur->_i << " ";//会依次输出出局者的编号(该语句可以不要)

			delete _cur;//删除出局者
			_cur = _prev->_next;//让_cur指向出局者的下一个位置
		}
		_head = _prev;
	}
};

void test()
{
	List li(5);
	li.Victor();
}