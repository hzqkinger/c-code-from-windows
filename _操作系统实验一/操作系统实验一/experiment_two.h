#pragma once

#include<list>
#include<algorithm>
struct freelist
{
	int _addr;//地址
	int _size;
	freelist(int addr, int size)
		:_addr(addr), _size(size)
	{}
};

bool Comp(const freelist &left, const freelist &right)
{
	return left._size < right._size;
}
bool Comp2(const freelist &left, const freelist &right)
{
	return left._addr < right._addr;
}
bool Comp3(const freelist &left, const freelist &right)
{
	return left._size > right._size;
}

void test_ff(list<freelist> &li,int pro_size,int Q)
{
	auto it = li.begin();
	while (it != li.end() && it->_size < pro_size)
		++it;
	if (it != li.end())
	{
		if (it->_size - pro_size <= Q)
			it = li.erase(it);
		else
		{
			it->_size -= pro_size;
			it->_addr += pro_size;
		}
	}
}
void test_nf(list<freelist> &li, int pro_size, int Q, list<freelist>::iterator &nf_index)
{
	if (nf_index == li.end())nf_index = li.begin();
	auto it = nf_index;
	while (it != li.end() && it->_size < pro_size)
		++it;
	if (it != li.end())
	{
		if (it->_size - pro_size <= Q)
			nf_index = li.erase(it);
		else
		{
			it->_size -= pro_size;
			it->_addr += pro_size;
			++nf_index;
		}
	}
}
void test_bf(list<freelist> &li, int pro_size, int Q)
{
	li.sort(Comp);
	auto it = li.begin();
	while (it != li.end() && it->_size < pro_size)
		++it;
	if (it != li.end())
	{
		if (it->_size - pro_size <= Q)
			it = li.erase(it);
		else
		{
			it->_size -= pro_size;
			it->_addr += pro_size;
		}
	}
}
void test_wf(list<freelist> &li, int pro_size, int Q)
{
	li.sort(Comp3);
	auto it = li.begin();
	while (it != li.end() && it->_size < pro_size)
		++it;
	if (it != li.end())
	{
		if (it->_size - pro_size <= Q)
			it = li.erase(it);
		else
		{
			it->_size -= pro_size;
			it->_addr += pro_size;
		}
	}
}

void print(list<freelist> &li)
{
	li.sort(Comp2);
	auto it = li.begin();
	while (it != li.end())
	{
		cout << it->_size << " ";
		++it;
	}cout << endl;
}

void test()
{
	int N,addr,size;
	cout << "请输入有几个空白分区:" << endl;
	cin >> N;

	list<freelist> li;
	for (int i = 0; i < N; ++i)
	{
		printf("请输入第%d个空白分区的起始地址和大小\n", i);
		cin >> addr >> size;
		freelist fl(addr,size);
		li.push_back(fl);
	}
	
	int str;
	cout << "请输入你选择哪种算法 1 ff 2 nf 3 bf 4 wf" << endl;
	cin >> str;
	int Q;
	cout << "不能分配空间的数值：" << endl;
	cin >> Q;

	auto nf_index = li.begin();
	while (1)
	{
		cout << endl << "分配之前："; print(li);

		int pro_size;
		cout << "请输入程序大小:" << endl;
		cin >> pro_size;

		if (str == 1)
			test_ff(li, pro_size, Q);

		else if (str == 2)
			test_nf(li, pro_size, Q, nf_index);
		else if (str == 3)
			test_bf(li, pro_size, Q);
		else if (str == 4)
			test_wf(li, pro_size, Q);
		else break;

		cout << "分配之后：";print(li);
	}
}