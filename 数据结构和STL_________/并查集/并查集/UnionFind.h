#pragma once
//朋友圈题：
// 假如已知有n个人和m对好友关系(存于数组r)，如果有两个人是直接或者间接的好友(好友的好友的好友...),
//则认为他们属于同一个朋友圈。请写程序求出这n个人里一共有多少个朋友圈。
// 例如：n = 5,m = 3,r = {{1,2},{2,3},{4,5}},1和2是好友，2和3是好友，4和5是好友，则1，2，3属于一个朋友圈，
//4，5属于一个朋友圈。结果为2个朋友圈。

#include<vector>
class UnionFindSet{    //并查集
public:
	UnionFindSet(const int& n)
	{
		_a.resize(n, -1);//把数组元素都初始化为-1
	}

	void Union(const int& x1, const int& x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 != root2)
		{
			_a[root1] += _a[root2];
			_a[root2] = root1;
		}

	}

	int FindRoot(const int& x)
	{
		int root = x;
		while (_a[root] >= 0)
		{
			root = _a[root];
		}

		return root;
	}

	bool IsUnionSet(const int& x1, const int& x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}

	int GetSetCount()
	{
		int n = 0;
		for (size_t i = 0; i < _a.size(); ++i)
		{
			if (_a[i] < 0)
			{
				++n;
			}
		}

		return n;
	}
private:
	vector<int> _a;
};

int Friends(int n, int m, int r[][2])
{
	UnionFindSet ufs(n + 1);//多开一个空间，因为题目中没有第0个人
	for (int i = 0; i < m; ++i)
		ufs.Union(r[i][0], r[i][1]);

	return ufs.GetSetCount() - 1;
}
void test_UnionFindSet()
{
	const int n = 5;
	const int m = 4;
	int r[m][2] = { { 1, 2 }, { 2, 3 }, { 4, 5 }, { 1, 3 }/*, { 1, 5 }*/ };
	cout << Friends(n, m, r) << endl;
}