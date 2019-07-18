#pragma once

int GetCount(int x, int times)
{
	int up = 1, down = 1;
	for (int i = times; i > 0; --i)
	{
		up *= x - i + 1;
		down *= i;
	}
	return (up / down) % 1000000007;
}
void test1()
{
	int k, a, b, x, y;
	long long count = 0;
	scanf("%d", &k);
	scanf("%d%d%d%d", &a, &x, &b, &y);

	for (int i = 0; i <= x; ++i)
	{
		for (int j = 0; j <= y; ++j)
		{
			if (i * a + j * b == k)
				count += GetCount(x, i) * GetCount(y, j) % 1000000007;
		}
	}
	printf("%lld\n", count);
}

struct node2{
	int x;
	int y;
};
int cmp(node2 a, node2 b)
{
	if (a.x == a.y)return a.y > b.y;
	return a.x > b.x;
}
#include<algorithm>
void test2()
{
	node2 arr[] = { { 1, 2 }, { 1, 4 }, { 3, 4 }, { 2, 6 }, { 2, 3 } };
	sort(arr, arr + 5, cmp);

	cout << endl;
}

void TEST_ALL()
{
	//test1();
	test2();
}