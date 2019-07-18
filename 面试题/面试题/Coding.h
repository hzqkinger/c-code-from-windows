//做笔试题的心得
//0.最基本的代码能力
//1.熟练使用map/set
//2.熟练使用string
//3.熟练使用sort这个算法 template <class RandomAccessIterator, class Compare>
//              void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

#pragma once
#include"DefineNode.h"

//4.1字符串匹配
//【题目】牛牛有两个字符串A和B，其中A串是01串，B串中除了可能0和1，还可能有'?'，且B中的问号可以确定为0或者1。寻找一个字符串T
//        是否在字符串S中出现的过程称为字符串匹配。现在考虑所有可能的字符串B，有多少中可以在字符串A中完成匹配。
//eg. 输入 A = "00010001", B = "??"
// 字符串B的可能字符串是"00","01","10","11",所有可能的字符串B，有三种可以在字符串A中完成匹配
#include<set>
#include<string>
void test41()
{
	string A, B;
	cin >> A >> B;
	B = "??";//            我的键盘问号键坏了
	int cnt = 0;
	set<string> s;
	for (int i = 0; i < A.size(); ++i)
	{
		string cur = A.substr(i, B.size());
		if (s.count(cur) != 0)//看看有没有重复的
			continue;
		s.insert(cur);

		int k = 0;
		for (; cur.size() == B.size() && k < B.size(); ++k)//把从A中切下来的字符串跟字符串B进行比较
		{
			if (cur[k] == B[k] || B[k] == '?')
				continue;
			else
				break;
		}
		if (k == B.size())
			++cnt;
	}
	cout << cnt;
}

//4.2完成括号的匹配
//【题目】牛牛现在给出一个方括号匹配序列s，牛牛允许你执行的操作是：在s的开始和结尾处添加一定数量的左括号或者在
//        右括号，使其变成一个合法的括号匹配序列。牛牛希望你能求出添加最少的括号之后的合法的括号匹配序列是什么？
//eg.输入序列 ][    输出序列[][]
void test42()
{
	string s;
	cin >> s;
	int cnt = 0;
	string prev_str;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '[')
			++cnt;
		else
			--cnt;

		if (cnt < 0)
		{
			cnt = 0;
			prev_str += '[';
		}
	}
	s.append(cnt, ']');
	s.insert(0, prev_str);
	cout << s << endl;
}
//4.2.1完成括号的匹配
//【题目】牛牛现在给出一个括号匹配序列s，包含三种括号，'()'，'[]'，'{}'，判断括号序列是否正确。
//eg. "[]{[][[()]]}"是正确的序列；"[)]"是错误的
bool right(string& s,int index)
{
	if (index == 0)
		return false;

	if ((s[index] == ')'&&s[index-1] == '(') || (s[index] == ']'&&s[index-1] == '[') || (s[index] == '}'&&s[index-1] == '{'))
	{
		s.erase(index);
		s.erase(index - 1);
		return true;
	}
	return false;
}
void test42_1()
{
	//思路：从左往右一直找，直到找到一个右括号，那么它的前一个一定是它对应的左括号。
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); )
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')//这个判断保证右括号不会进行right()函数
		{
			++i;
			continue;
		}
			

		if (right(s, i))
			--i;
		else
			break;
	}
	if (s.empty())
		cout << true << endl;
	else
		cout << false << endl;
}

//4.3字符覆盖
//【题目】有两个只包含小写字母的字符串s和t，小度可以选择字符串t中任意一个字符，然后覆盖在字符串s的一个字符上。
//        小度向知道在选取一些卡片覆盖s的一些字符之后，可以得到的字典序最大的字符串是什么？
//eg.  输入示例 fedcba ee   输出示例 feeeba
#include<algorithm>
bool comp(char left, char right)
{
	return left > right;
}
void test43()
{
	string s, t;
	cin >> s >> t;
	sort(t.begin(), t.end(), comp);//sort函数默认是排升序的，所以想要降序需要自己传入仿函数

	for (int si = 0,ti = 0; si < s.size() && ti < t.size();)
	{
		if (s[si] >= t[ti])
		{
			++si;
			continue;
		}
		s[si++] = t[ti++];
	}
	cout << s << endl;
}

//4.4最大子序列
//【题目】对于字符串x和y，如果擦除x中的0个或多个字符能得到y，我们就称y是x的子序列。现在对于一个给定的字符串，请计算出
//        字典序最大的s的子序列。
//eg.   输入示例 test   输出示例 tt
void test44()
{
	string s;cin >> s;

	string tmp;
	for (int i = 0; i < s.size();)
	{
		while (i + 1 < s.size() && s[i] < s[i + 1])//上升
			++i;
		//开始删除一些元素
		for (int k = tmp.size() - 1; k >= 0; --k)
		{
			if (s[i] > tmp[k])
				tmp.pop_back();
		}
		while (i + 1 < s.size() && s[i] >= s[i + 1])//下降
			tmp += s[i++];

		if (i == s.size() - 1)
			tmp += s[i++];
	}
	cout << tmp;
}

//5.1字符串碎片
//【题目】一个由小写字母组成的字符串可以看成一些统一字母的最大碎片组成的。例如，"aaabbaaac"是由下面的随片组成的
//        "aaa"，"bb"，"c"。牛牛现在给你一个字符串，请你帮助计算这个字符串的所有碎片的平均长度。
//eg.  输入描述：输入一个字符串s，如s = "aaabbaaac"。  则输出一个数：2.25   （即平均长度=(3+2+3+1)/4=2.25）
void  test51()
{
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		int next = i + 1;
		if (next < s.size() && s[i] == s[next])
			continue;

		++cnt;
	}
	double av = (double)s.size() / cnt;
	printf("%.2f\n", av);
}

//5.2游历魔法王国

//5.3重排数列
//【题目】小易有一个长度为N的正整数数列 A = {A[1],A[2],A[3]...A[N]}。牛博士给小易出了一个难题：对数列A进行重排，
//        使数列A满足所有的A[i]*A[i+1]都是4的整数倍。现在需要判断一个数列是否可以重排之后满足牛博士的要求。
//输入描述：输入的第一行为数列的个数t(1<=t<=10)
//          接下来的每两行描述一个数列A，第一行为数列长度n，第二行为n个正整数A[i]
//输出描述：对每一个数列输出一行表示是否可以满足牛博士要求，如果可以输出Yes，否则输出No
//eg. 2
//    3
//    1 10 100
//    4
//    1 2 3 4
#include<vector>
void test53()
{
	int t; cin >> t;
	vector<vector<int> > arr(t);
	for (int i = 0; i < t; ++i)
	{
		int n; cin >> n;
		arr[i].resize(n);
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];
	}

	
	for (int i = 0; i < arr.size(); ++i)
	{
		int odd = 0, even = 0, tmp = 0;
		for (int j = 0; j < arr[i].size(); ++j)
		{
			int tt = arr[i][j] % 4;
			if (tt == 1 || tt == 3)
				++odd;
			if (tt == 2)
				tmp = 1;
			if (tt == 0)
				++even;
		}
		if (odd + tmp - 1 <= even)
			printf("Yes\n");
		else
			printf("No\n");
	}
}

void test_coding()
{
	//test41();
	//test42();
	//test42_1();
	//test43();
	//test44();
	//test51();
	test53();
}