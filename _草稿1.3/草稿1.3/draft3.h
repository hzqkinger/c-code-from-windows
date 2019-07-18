#pragma once
//#include<stdio.h>
//static修饰的函数可以被include进其它文件，然后在其它文件中使用
//void func();

//#include<vector>
//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		// write code here
//		if (gifts.empty())
//			return 0;
//
//		int cnt = 1, money = gifts[0];
//		for (int i = 1; i < gifts.size(); ++i)
//		{
//			if (money == gifts[i])
//				++cnt;
//			else
//			{
//				--cnt;
//				if (cnt == 0 && i + 1 < gifts.size())
//					money = gifts[i + 1];
//			}
//		}
//		//如果一定有出现次数超过一半的红包，则上面的逻辑就可以找到；否则跑一跑下面的循环
//		cnt = 0;
//		for (int i = 0; i < gifts.size(); ++i)
//		{
//			if (gifts[i] == money)
//				++cnt;
//		}
//		if (cnt > gifts.size() / 2)
//			return money;
//		else
//			return 0;
//	}
//};
//void test1()
//{
//	Gift g;
//	vector<int> arr = { 1, 2, 3, 2, 2, 2, 4 };
//	cout << g.getValue(arr, arr.size()) << endl;
//}
//
//#include<string>
//int calStringDistance(string charA, string charB)
//{
//	int dis = 0;
//	int indexA = 0, indexB = 0;
//	for (; indexA < charA.size() && indexB < charB.size(); ++indexA, ++indexB)
//	{
//		if (charA[indexA] != charB[indexB])
//		{
//			charA.insert(indexA, 1, charB[indexB]);
//			++dis;
//		}
//	}
//	dis += charA.size() - indexA + charB.size() - indexB;
//	cout << dis << endl;
//	return 0;
//}
//
//void test2()
//{
//	string charA, charB;
//	while (cin >> charA >> charB)
//	{
//		calStringDistance(charA, charB);
//	}
//}
//
//void test3()
//{
//	int N, M;
//	while (cin >> N >> M)
//	{
//		vector<int> arr(M + 1);
//		for (int i = N; i <= M; ++i)
//		{
//			if (arr[i] == 0 && i != N)
//				continue;
//			const int size = i / 2;
//			for (int j = 2; j <= size; ++j)
//			{
//				int tmp = i % j;
//				if (!tmp && i + j <= M && (arr[i + j] == 0 || arr[i + j] > arr[i] + 1))
//					arr[i + j] = arr[i] + 1;
//			}
//		}
//		if (arr[M])
//			cout << arr[M] << endl;
//		else
//			cout << -1 << endl;
//	}
//}
//
//void test4(int a, int b)
//{
//	while (b)
//	{
//		int tmp = a;
//		a |= b;
//		b &= tmp;
//	}
//	cout << a << endl;
//}
//
void getnext(char *p ,int *next,const int len)
{
	if (len == 1){ next[0] = -1; return; }
	next[0] = -1;next[1] = 0;

	for (int i = 2; i < len; ++i)
	{
		if (p[next[i - 1]] == p[i - 1])
			next[i] = next[i - 1] + 1;
		else{
			int pos = next[i - 1];
			while (pos > 0 && p[pos] != p[i - 1]){
				pos = next[pos];
			}
			next[i] = next[pos] + 1;
		}
	}
}
int KMP(char *str, char *pattern)
{
	if (!str && !pattern)return -1;
	const int N = strlen(str), PN = strlen(pattern);
	int *next = new int[PN];
	getnext(pattern, next, PN);

	int is = 0, ip = 0;
	for (; is < N && ip < PN;)
	{
		if (str[is] == pattern[ip]){
			++is; ++ip;
		}
		else{
			while (ip > -1 && str[is] != pattern[ip]){
				ip = next[ip];
			}
			if (ip == -1)++is,++ip;
		}
	}
	delete next;

	return ip == PN ? is - ip : -1;
}
//
//
//void oddInOddEvenInEven(vector<int>& arr, int len) {
//	int even = 0, odd = 1;
//	for (int i = 0, j = 0; i < len && j < len; even += 2, odd += 2)
//	{
//		while (i < len && arr[i] % 2 != 0)++i;//找到下一个偶数
//		if (i < len && even != i)swap(arr[even], arr[i]);
//		else ++i;
//
//		while (j < len && arr[j] % 2 == 0)++j;//找到下一个奇数
//		if (j < len && odd != j)swap(arr[odd], arr[j]);
//		else ++j;
//	}
//}
//
//void test5()
//{
//	int N;
//	while (cin >> N)
//	{
//		long long int a = 1, b = 0;
//		for (int i = 0; i < N; ++i)
//			a *= 5;
//		a -= 4;
//
//		b = a;
//		for (int i = 0; i < N; ++i)
//			b = b * 4 / 5;
//		b += N;
//
//		cout << a << " " << b << endl;
//	}
//}
//
//#include<algorithm>
//#include<map>
//#include<vector>
//int getFirstUnFormedNum(vector<int> arr, int len) {
//	if (arr.empty())return 0;
//	//寻找区间
//	sort(arr.begin(), arr.end());
//	int left = arr[0], right = 0;
//	for (int i = 0; i < arr.size(); ++i)right += arr[i];
//
//	//求出所有子集
//	vector<vector<int> > res;
//	res.push_back({});
//	for (int i = 0; i < arr.size(); ++i)
//	{
//		int n = res.size();
//		for (int j = 0; j < n; ++j)
//		{
//			res.push_back(res[j]);
//			res.back().push_back(arr[i]);
//		}
//	}
//
//	//统计所有出现的子集的和
//	map<int, int> mp;
//	for (int i = 1; i < res.size(); ++i)
//	{
//		int sum = 0;
//		for (int k = 0; k < res[i].size(); ++k)
//			sum += res[i][k];
//		mp[sum]++;
//	}
//
//	//遍历map，得到最小不可组成和
//	auto prev = mp.begin();
//	auto it = prev;
//	for (++it; it != mp.end(); ++it)
//	{
//		if (prev->first + 1 != it->first)
//			break;
//
//		prev = it;
//	}
//	return prev->first + 1;
//}

#include<iostream>
using namespace std;
#include<string>
void test6()
{
	const char passwd[] = { 'V', 'W', 'X', 'T', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U' };
	string str;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' ')
				continue;
			str[i] = passwd[str[i] - 'A'];
		}
		cout << str << endl;
	}
}

void test_draft3()
{
	//test1();
	//test2();//错了
	//test3();
	//cout << -1 << endl;
	//test4(5, -8);//不用加减法计算两个数的和

	//cout << KMP("abcbbaabcabaabc", "abaabc") << endl;

	//vector<int> arr = { 1, 2, 3, 4, 5, 5, 7, 9, 11, 4 ,8,10,12,14,16,18,20};
	//oddInOddEvenInEven(arr, arr.size());
	//for (auto &r : arr)cout << r << " "; cout << endl;

	//test5();
	//vector<int> arr = { 3, 2, 1 };
	//cout << getFirstUnFormedNum(arr, sizeof(arr) / sizeof(arr[0])) << endl;

	//test6();
	/*int a = -20;
	unsigned int b = 10;
	printf("%d", a + b);*/

}

