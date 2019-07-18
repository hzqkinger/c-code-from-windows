#pragma once
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;

template<class T>
struct Less
{
	bool operator()(const T& left, const T& right) const
	{
		return left < right;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T& left, const T& right) const
	{
		return left > right;
	}
};


template<class T, class Compare = Less<T>>
class Heap
{
public:
	Heap()//�޲εĹ��캯����ϵͳ������޲ι��캯��������ʼ���ǿյĲ���Ҫ��ʲô��
	{}
	Heap(T* a, size_t n)
	{
		_a.reserve(n);//���ռ�
		for (size_t i = 0; i < n; ++i)
		{
			_a.push_back(a[i]);

		}
		//����,�����һ����Ҷ�ӽڵ�
		for (int i = (_a.size() - 2) / 2; i >= 0; --i)//����size_t����Ϊi������ܵ���0����size_t����ѭ��
		{
			AdjustDown(i);
		}
	}
	//���µ���
	void AdjustDown(int root)
	{
		Compare com;
		int parent = root;
		size_t child = parent * 2 + 1;//Ĭ��Ϊ����
		while (child < _a.size())
		{
			//ѡ��С����
			//if (child+1 > _a.size() && _a[child + 1]< _a[child])
			if (child + 1 < _a.size() && com(_a[child + 1], _a[child]))
			{
				++child;
			}

			//if (_a[child] < _a[parent])
			if (com(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);//����ֵ
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
	//���ϵ���
	void AdjustUp(int child)
	{
		Compare com;
		int parent = (child - 1) / 2;
		while (parent >= 0)
		{
			//if (_a[child] < _a[parent])
			if (com(_a[child], _a[parent]))
			{
				swap(_a[parent], _a[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}

	}
	//������
	void Push(const T&x)
	{
		_a.push_back(x);
		AdjustUp(_a.size() - 1);
	}
	//ɾ�������
	void Pop()
	{
		assert(!_a.empty());
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		AdjustDown(0);

	}
	//ȡ��Ԫ��
	T& Top()
	{
		assert(!_a.empty());
		return _a[0];
	}
	size_t Size()
	{
		return _a.size();
	}

	bool Empty()
	{
		return _a.empty();
	}


private:
	vector<T> _a;
};