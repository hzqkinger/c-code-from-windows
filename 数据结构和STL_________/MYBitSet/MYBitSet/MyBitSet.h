#pragma once

template<size_t M>//M表示bitset的位数
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
	size_t _v[M / 32 + 1];//直接开一个数组就好了
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

//1.给定100亿个整数，设计算法找到只出现一次的整数
//3.1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
#include<time.h>
void test1()
{
	mybitset<UINT_MAX> bs1;
	mybitset<UINT_MAX> bs2;

	srand(time(NULL));

	for (size_t i = 0; i < 100000; ++i)
	{
		int tmp = rand();                                              //  bs2  bs1    插入前

		if (bs1.Test(tmp) == false && bs2.Test(tmp) == false)         //   0    0     (要插入的数没存在)
		{
			bs1.Set(tmp);
		}
		else if (bs1.Test(tmp) == true && bs2.Test(tmp) == false)     //   0    1     （要插入的数只存在一次）
		{
			bs1.ReSet(tmp); bs2.Set(tmp);
		}
		else if (bs1.Test(tmp) == false && bs2.Test(tmp) == true)     //   1    0      （要插入的数存在两次）
		{
			bs1.Set(tmp);
		}
		                                                              //    1    1      （要插入的数存在至少三次）
	}

	for (size_t i = 0; i < bs1.Size(); ++i)//从头到尾一次遍历
	{
		if (bs1.Test(i) == true && bs2.Test(i) == false)//打印出只出现一次的数
			cout << i << " ";
	}
}

//2.给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集