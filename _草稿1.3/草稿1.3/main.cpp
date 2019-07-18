#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
//#include <stdarg.h>
#include<stdlib.h>

//#include"draft1.h"
//#include"draft2.h"
//#include"draft3.h"
#include"draft4.h"
//#include"test.h"
//extern int aa;
//extern int aa;
//extern int aa;

//extern void func();
//这个不行，估计因为draft3不在/user中，所以链接时找不到func的定义。
//static int a;

//#include<iostream>
//using namespace std;
//
//#include<vector>
//#include<map>
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//
//	vector<vector<int> > arr(N);
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//			cin >> arr[i][j];
//	}
//
//	map<int, int> mp1;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; j += 2)
//		{
//			mp1[arr[i][j]]++;
//		}
//	}
//	auto it = mp1.begin();
//	int cnt = 0;
//	for (; it != mp1.end(); ++it)
//	{
//		if (cnt < it->second)
//			cnt = it->second;
//	}
//
//	map<int, int> mp2;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 1; j < M; j += 2)
//		{
//			mp2[arr[i][j]]++;
//		}
//	}
//	it = mp2.begin();
//	for (; it != mp2.end(); ++it)
//	{
//		if (cnt < it->second)
//			cnt = it->second;
//	}
//
//	cout << M * N - cnt << endl;
//
//	return 0;
//}
//int main()
//{
//	//void func1();
//	//func11111111();
//	//test_draft1();
//	//test_draft2();
//	//test_draft3();
//	////func();
//	////system("pause");
//	////http://www.youjizz.com  linux学习网
//	//return 0;
//}
//class Test{
//public:
//	Test(){ i++; }
//	static int i;
//};
//int Test::i = 0;
//#include<unordered_map>
//int main()
//{
//	int N; cin >> N;
//	unordered_map<int, int> mp;
//	while (N--)
//	{
//		int left; cin >> left;
//		int right; cin >> right;
//		for (int i = left; i < right; ++i)
//			mp[i]++;
//	}
//	auto it = mp.begin();
//	int cur = 0, max = 0;
//	for (; it != mp.end(); ++it)
//	{
//		cur = it->second;
//		if (cur > max)
//			max = cur;
//	}
//	cout << max << endl;
//	//Test a[4], *p[5];
//	//cout << sizeof(a) / sizeof(Test) << endl;
//	//cout << sizeof(p) / sizeof(Test) << endl;
//	//cout << sizeof(*p) / sizeof(Test) << endl;
//	//cout << Test::i << endl;
//	//int i = 1, j = 3, k = 0, sum = 5;
//	//switch (k > -i++)
//	//{
//	//case 2:sum += 1;
//	//case 1:sum += j;
//	//case 0:sum += i; break;
//	//case -1:sum *= -1;
//	//}
//	//cout << sum << endl;
//
//	system("pause");
//	return 0;
//}


#include<stdio.h>

int main()
{
	//int a = 1;
	//int b = 2;
	//int c = 0;

	//__asm {
	//	mov eax, a
	//	mov ebx, b
	//	add eax, ebx
	//	mov c, eax
	//}
	//printf("a + b = %d\n", c);

	test_draft4();
	system("pause");
	return 0;
}