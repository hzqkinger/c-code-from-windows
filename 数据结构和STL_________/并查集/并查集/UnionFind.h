#pragma once
//����Ȧ�⣺
// ������֪��n���˺�m�Ժ��ѹ�ϵ(��������r)���������������ֱ�ӻ��߼�ӵĺ���(���ѵĺ��ѵĺ���...),
//����Ϊ��������ͬһ������Ȧ����д���������n������һ���ж��ٸ�����Ȧ��
// ���磺n = 5,m = 3,r = {{1,2},{2,3},{4,5}},1��2�Ǻ��ѣ�2��3�Ǻ��ѣ�4��5�Ǻ��ѣ���1��2��3����һ������Ȧ��
//4��5����һ������Ȧ�����Ϊ2������Ȧ��

#include<vector>
class UnionFindSet{    //���鼯
public:
	UnionFindSet(const int& n)
	{
		_a.resize(n, -1);//������Ԫ�ض���ʼ��Ϊ-1
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
	UnionFindSet ufs(n + 1);//�࿪һ���ռ䣬��Ϊ��Ŀ��û�е�0����
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