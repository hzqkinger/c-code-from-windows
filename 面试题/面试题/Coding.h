//����������ĵ�
//0.������Ĵ�������
//1.����ʹ��map/set
//2.����ʹ��string
//3.����ʹ��sort����㷨 template <class RandomAccessIterator, class Compare>
//              void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

#pragma once
#include"DefineNode.h"

//4.1�ַ���ƥ��
//����Ŀ��ţţ�������ַ���A��B������A����01����B���г��˿���0��1����������'?'����B�е��ʺſ���ȷ��Ϊ0����1��Ѱ��һ���ַ���T
//        �Ƿ����ַ���S�г��ֵĹ��̳�Ϊ�ַ���ƥ�䡣���ڿ������п��ܵ��ַ���B���ж����п������ַ���A�����ƥ�䡣
//eg. ���� A = "00010001", B = "??"
// �ַ���B�Ŀ����ַ�����"00","01","10","11",���п��ܵ��ַ���B�������ֿ������ַ���A�����ƥ��
#include<set>
#include<string>
void test41()
{
	string A, B;
	cin >> A >> B;
	B = "??";//            �ҵļ����ʺż�����
	int cnt = 0;
	set<string> s;
	for (int i = 0; i < A.size(); ++i)
	{
		string cur = A.substr(i, B.size());
		if (s.count(cur) != 0)//������û���ظ���
			continue;
		s.insert(cur);

		int k = 0;
		for (; cur.size() == B.size() && k < B.size(); ++k)//�Ѵ�A�����������ַ������ַ���B���бȽ�
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

//4.2������ŵ�ƥ��
//����Ŀ��ţţ���ڸ���һ��������ƥ������s��ţţ������ִ�еĲ����ǣ���s�Ŀ�ʼ�ͽ�β�����һ�������������Ż�����
//        �����ţ�ʹ����һ���Ϸ�������ƥ�����С�ţţϣ���������������ٵ�����֮��ĺϷ�������ƥ��������ʲô��
//eg.�������� ][    �������[][]
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
//4.2.1������ŵ�ƥ��
//����Ŀ��ţţ���ڸ���һ������ƥ������s�������������ţ�'()'��'[]'��'{}'���ж����������Ƿ���ȷ��
//eg. "[]{[][[()]]}"����ȷ�����У�"[)]"�Ǵ����
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
	//˼·����������һֱ�ң�ֱ���ҵ�һ�������ţ���ô����ǰһ��һ��������Ӧ�������š�
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); )
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')//����жϱ�֤�����Ų������right()����
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

//4.3�ַ�����
//����Ŀ��������ֻ����Сд��ĸ���ַ���s��t��С�ȿ���ѡ���ַ���t������һ���ַ���Ȼ�󸲸����ַ���s��һ���ַ��ϡ�
//        С����֪����ѡȡһЩ��Ƭ����s��һЩ�ַ�֮�󣬿��Եõ����ֵ��������ַ�����ʲô��
//eg.  ����ʾ�� fedcba ee   ���ʾ�� feeeba
#include<algorithm>
bool comp(char left, char right)
{
	return left > right;
}
void test43()
{
	string s, t;
	cin >> s >> t;
	sort(t.begin(), t.end(), comp);//sort����Ĭ����������ģ�������Ҫ������Ҫ�Լ�����º���

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

//4.4���������
//����Ŀ�������ַ���x��y���������x�е�0�������ַ��ܵõ�y�����Ǿͳ�y��x�������С����ڶ���һ���������ַ�����������
//        �ֵ�������s�������С�
//eg.   ����ʾ�� test   ���ʾ�� tt
void test44()
{
	string s;cin >> s;

	string tmp;
	for (int i = 0; i < s.size();)
	{
		while (i + 1 < s.size() && s[i] < s[i + 1])//����
			++i;
		//��ʼɾ��һЩԪ��
		for (int k = tmp.size() - 1; k >= 0; --k)
		{
			if (s[i] > tmp[k])
				tmp.pop_back();
		}
		while (i + 1 < s.size() && s[i] >= s[i + 1])//�½�
			tmp += s[i++];

		if (i == s.size() - 1)
			tmp += s[i++];
	}
	cout << tmp;
}

//5.1�ַ�����Ƭ
//����Ŀ��һ����Сд��ĸ��ɵ��ַ������Կ���һЩͳһ��ĸ�������Ƭ��ɵġ����磬"aaabbaaac"�����������Ƭ��ɵ�
//        "aaa"��"bb"��"c"��ţţ���ڸ���һ���ַ��������������������ַ�����������Ƭ��ƽ�����ȡ�
//eg.  ��������������һ���ַ���s����s = "aaabbaaac"��  �����һ������2.25   ����ƽ������=(3+2+3+1)/4=2.25��
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

//5.2����ħ������

//5.3��������
//����Ŀ��С����һ������ΪN������������ A = {A[1],A[2],A[3]...A[N]}��ţ��ʿ��С�׳���һ�����⣺������A�������ţ�
//        ʹ����A�������е�A[i]*A[i+1]����4����������������Ҫ�ж�һ�������Ƿ��������֮������ţ��ʿ��Ҫ��
//��������������ĵ�һ��Ϊ���еĸ���t(1<=t<=10)
//          ��������ÿ��������һ������A����һ��Ϊ���г���n���ڶ���Ϊn��������A[i]
//�����������ÿһ���������һ�б�ʾ�Ƿ��������ţ��ʿҪ������������Yes���������No
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