#pragma once
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
			if (_a[i] < 0)++n;

		return n;
	}
private:
	vector<int> _a;
};