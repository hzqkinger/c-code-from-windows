#pragma once

template<size_t M>//M��ʾbitset��λ��
class mybitset{
public:
	mybitset()
	{
		for (size_t i = 0; i < sizeof(_v) / sizeof(_v[0]); ++i)
			_v[i] = 0;
	}
	void Set(const size_t& x)
	{
		size_t pos = x / 32;
		size_t index = x % 32;

		_v[pos] |= 1 << index;
	}
	void ReSet(const size_t& x)
	{
		size_t pos = x / 32;
		size_t index = x % 32;

		_v[pos] &= ~(1 << index);
	}
	bool Test(const size_t& x)
	{
		size_t pos = x / 32;
		size_t index = x % 32;

		return _v[pos] & 1 << index;
	}

	size_t Size()
	{
		return M / 32 + 1;
	}
private:
	size_t _v[M / 32 + 1];//ֱ�ӿ�һ������ͺ���
};

void test_MyBitSet()
{
	mybitset<55> bs;

	bs.Set(55);
	bs.Set(25); 
	bs.Set(15); 
	bs.Set(45);
	bs.Set(32);

	cout << bs.Test(15) << endl;
	cout << bs.Test(16) << endl;
	cout << bs.Test(25) << endl;
	cout << bs.Test(26) << endl;
	cout << bs.Test(55) << endl;
	cout << bs.Test(1) << endl;
	cout << bs.Test(32) << endl;
}

//1.����100�ڸ�����������㷨�ҵ�ֻ����һ�ε�����
//3.1���ļ���100�ڸ�int��1G�ڴ棬����㷨�ҵ����ִ���������2�ε���������
#include<time.h>
void test1()
{
	mybitset<UINT_MAX> bs1;
	mybitset<UINT_MAX> bs2;

	srand(time(NULL));

	for (size_t i = 0; i < 100000; ++i)
	{
		int tmp = rand();                                              //  bs2  bs1    ����ǰ

		if (bs1.Test(tmp) == false && bs2.Test(tmp) == false)         //   0    0     (Ҫ�������û����)
		{
			bs1.Set(tmp);
		}
		else if (bs1.Test(tmp) == true && bs2.Test(tmp) == false)     //   0    1     ��Ҫ�������ֻ����һ�Σ�
		{
			bs1.ReSet(tmp); bs2.Set(tmp);
		}
		else if (bs1.Test(tmp) == false && bs2.Test(tmp) == true)     //   1    0      ��Ҫ��������������Σ�
		{
			bs1.Set(tmp);
		}
		                                                              //    1    1      ��Ҫ������������������Σ�
	}

	for (size_t i = 0; i < bs1.Size(); ++i)//��ͷ��βһ�α���
	{
		if (bs1.Test(i) == true && bs2.Test(i) == false)//��ӡ��ֻ����һ�ε���
			cout << i << " ";
	}
}

//2.�������ļ����ֱ���100�ڸ�����������ֻ��1G�ڴ棬����ҵ������ļ�����