#pragma once
#include<stddef.h>

struct te1
{
	int a;
	double d;
};
void test1()
{
	cout << sizeof(te1) << endl;
	printf("%d\n", offsetof(te1, a));
	printf("%d\n", offsetof(te1, d));
}

#include<vector>
string formatString(string A, int n, vector<char> arg, int m) {
	// write code here
	int i = 0, index = 0;
	for (; i < n && index < m;)
	{
		i = A.find("%s", i);
//		string& replace(size_t pos, size_t len, const char* s)
//		string& replace(size_t pos, size_t len, size_t n, char c);
		A.replace(i, 2, 1,arg[index++]);
	}
	while (index < m)
		A += arg[index++];

	return A;
}

#include<string>
void test2()
{
	//string str;
	//getline(cin, str, 's');
	//cout << str << endl;

//	string();//默认构造函数
//	string(const string& str);//拷贝构造函数
//	string(const string& str, size_t pos, size_t n = npos);//从pos位置开始取n个字符
//	string(const char * s, size_t n);  //从0位置开始取n个字符
//	string(const char * s);            //从0位置开始取s的所有字符
//	string(size_t n, char c);
//	template<class InputIterator> string(InputIterator begin, InputIterator end);

	string str2("abcdefghijklmn"/*, 2*/);
	cout << str2 << endl;
	string str3(str2, 3,5);
	cout << str3 << endl;

}


int lengthOfLongestSubstring(string s) {
	static int buf[256];
	for (int i = 0; i < 256; ++i)
		buf[i] = -1;

	int left = 0,len = 0;
	for (int i = 0; i<s.size(); ++i)
	{
		if (buf[s[i]] != -1)
		{
			while (/*left < i && */s[left] != s[i])
			{
				buf[s[left]] = -1;
				++left;
			}

			/*if (left < i && s[left] == s[i])*/++left;
		}
		buf[s[i]] = i;

		len = i - left > len ? i - left : len;
	}
	return len + 1;

}

#include<sstream>
void test3()
{
	stringstream ss;   //
	string str = "088";
	int number;
	ss << str;
	ss >> number;

	cout << "str:" << str << endl;
	cout << "number" << number << endl;

	number = atoi(str.c_str());
	cout << "number" << number << endl;
}


void Getnum(const string &str, int &index, const int &len, int &num)
{
	num = 0;
	while (index < len && str[index] != '.')
	{
		num = num * 10 + str[index] - '0';
		++index;
	}
}
int compareVersion(string version1, string version2) {
	const int len1 = version1.size();
	const int len2 = version2.size();

	int index1 = 0, index2 = 0;
	int num1 = 0, num2 = 0;
	while (index1 < len1 && index2 < len2)
	{
		Getnum(version1, index1, len1, num1);
		Getnum(version2, index2, len2, num2);
		++index1; ++index2;

		if (num1 == num2)continue;
		return num1 > num2 ? 1 : -1;
	}

	while (index1 < len1)
	{
		Getnum(version1, index1, len1, num1);
		++index1;
		if (num1 == 0)continue;
		return num1 > 0 ? 1 : -1;
	}
	while (index2 < len2)
	{
		Getnum(version2, index2, len2, num2);
		++index2;
		if (num2 == 0)continue;
		return num2 > 0 ? -1 : 1;
	}

	return 0;
}
void test4()
{
	//"1"
	//	"1.0.1"
	string version1 = "1";   //"1" < "1.0.1"
	string version2 = "1.0.1";
	compareVersion(version1, version2);
}

void GetNum(const string & s, int &index, int &num)
{
	num = 0;
	while (index < s.size() && s[index] >= '0' && s[index] <= '9')
	{
		num = num * 10 + s[index++] - '0';
		
	}
}
void GetOp(const string & s, int &index, int &num)
{
	if (s[index] == '+')num = '+';
	else if (s[index] == '-')num = '-';
	else if (s[index] == '*')num = '*';
	else num = '/';
	++index;
}
int calculate(string s) {
	vector<int> sta;
	int index = 0, num = 0;
	while (s[index] == ' ' || s[index] == '+')//跳过对计算不必要的'+'或者空格
		++index;
	int left = 0, right = 0;
	bool flag = false;
	while (index < s.size())//数组中值保留操作数和'+' '-'运算符；  '*' "/"最终不会存在数组中
	{
		while (index < s.size() && s[index] == ' ')++index;//注意，必须在每次取操作数之前跳过空格
		if (index < s.size())
		{
			if (flag)                     //获取操作数
			{
				GetNum(s, index, right);//不能在函数里面处理跳过空格的逻辑
				int op = sta.back(); sta.pop_back();
				left = sta.back(); sta.pop_back();
				if (op == '*')sta.push_back(left*right);
				else sta.push_back(left / right);
			}
			else{
				GetNum(s, index, num);
				sta.push_back(num);
			}
		}
		while (index < s.size() && s[index] == ' ')++index;
		if (index < s.size()){    //获取运算符
			GetOp(s, index, num);
			sta.push_back(num);
			if (num == '+' || num == '-')
				flag = false;
			else flag = true;
		}
	}

	for (index = 0; index < sta.size();)
	{
		left = sta[index++];
		if (index < sta.size()){
			int op = sta[index++];
			right = sta[index];
			if (op == '+')sta[index] = left + right;
			else sta[index] = left - right;
		}
	}
	return sta.back();
}
void test5()
{
	string s = "3 ";//3
	cout << calculate(s) << endl;
}


#include<stack>
#include<string>
void num_to_english(string &tmp, int num, int flag)
{
	const static string str1[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
		"Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	const static string str2[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

	const static string str3[] = { "", "Thousand", "Million", "Billion" };

	if (num >= 100){               //处理百位
		tmp = str1[num / 100];
		tmp += " Hundred";
	}

	if (num %= 100){                //处理十位和个位
		if (num < 20){     //1-19
			if (!tmp.empty())tmp += ' ';
			tmp += str1[num];
		}
		else{              //20-99
			if (!tmp.empty())tmp += ' ';
			tmp += str2[num / 10];

			if (num %= 10){
				tmp += ' ';
				tmp += str1[num];
			}
		}
	}
	if (flag && !tmp.empty()){                    //flag表示该num在哪个段位上
		tmp += ' ';
		tmp += str3[flag];
	}
}
string numberToWords(int num) {
	stack<string> sta;
	int flag = -1;
	while (num){
		int N = num % 1000;
		++flag;
		num /= 1000;

		string ss;
		num_to_english(ss, N, flag);
		if (!ss.empty())sta.push(ss);
	}
	string str;
	while (!sta.empty()){
		if (!str.empty())
			str += ' ';
		str += sta.top();
		sta.pop();
	}

	return str;
}
void test6()
{
	cout << numberToWords(12) << endl;
}


#include<map>
#include<vector>
#include<string>
bool IsPalindrome(const string& str){
	int left = 0, right = str.size() - 1;
	while (left < right){
		if (str[left] != str[right])
			return false;
		++left; --right;
	}
	return true;
}
vector<vector<int>> palindromePairs(vector<string>& words) {
	multimap<char, pair<string, int>> mpR;
	for (int i = 0; i<words.size(); ++i){
		mpR.insert({ words[i][words[i].size() - 1], make_pair(words[i], i) });
	}
	vector<vector<int>> arr;
	string tmp;
	for (int i = 0; i < words.size(); ++i){
		char ch = words[i][0];
		for (auto it = mpR.equal_range(ch).first; it != mpR.equal_range(ch).second; ++it){
			//pair<string, int> x = it->second;
			//cout << x.second << " ";
			//cout << endl;
			if (words[i] != it->second.first){
				tmp = words[i] + it->second.first;
				if (IsPalindrome(tmp)){
					vector<int> v = { i, it->second.second };
					arr.push_back(v);
				}
			}
		}
	}
	cout << " ";
	return arr;
}
void test7()
{
	vector<string> v = { "abcd", "dcba", "lls", "s", "sssll" };
	palindromePairs(v);
}

bool canConstruct(string ransomNote, string magazine) {
	if (ransomNote.empty())
		return true;
	static int count[256] = { 0 };
	for (int i = 0; i<magazine.size(); ++i){
		count[magazine[i]]++;
	}
	for (int i = 0; i<ransomNote.size(); ++i){
		if (--count[ransomNote[i]] < 0){
			return false;
		}

	}
	return true;
}
void test8()
{
	string ransomNote = "aa";
	string magazine = "aab";

	cout << canConstruct(ransomNote,magazine);
}
int compress(vector<char>& chars) {
	int left = 0, right = 0, index = 0;
	while (left < chars.size())
	{
		while (right < chars.size() && chars[left] == chars[right])
			++right;

		int num = right - left;
		chars[index++] = chars[left];

		if (num > 1){
			int begin = index;
			while (num){
				chars[index++] = num % 10 + '0';
				num /= 10;
			}
			int end = index - 1;
			while (begin < end){
				swap(chars[begin++], chars[end--]);
			}
		}
		left = right;
	}
	chars.resize(index);
	return chars.size();
}
void test9()
{
	vector<char> chars = { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
	//{{ "a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b" };
	cout<<compress(chars);
}
#include<algorithm>
void test10()
{
	string str = "abcdef";
	//reverse(str.begin(), str.begin() + 3);
	//cout << str << endl;

	cout << str.find('B') << endl;
}

class base11{
public:
	virtual void fun1()
	{
		cout << "base11" << endl;
	}
};
class derived11:public base11
{
public:
	virtual void fun1()override final
	{
		cout << "derived11" << endl;
	}
};
void test11()
{
	base11 *pb = new base11;
	pb->fun1();

	pb = new derived11;
	pb->fun1();
}


class MyLinkedList {//设计一个带头结点单向不循环链表
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int value = -1) :val(value), next(NULL){}
	};
	ListNode *_head;
	int _size;
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		_head = new ListNode();
		_size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index < 0 || index >= _size)
			return -1;
		ListNode *cur = _head->next;
		while (index--)
			cur = cur->next;

		return cur->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		++_size;

		ListNode *ret = new ListNode(val);
		ListNode *next = _head->next;

		_head->next = ret;
		ret->next = next;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		int cnt = _size;
		ListNode *tail = _head;
		while (cnt--)tail = tail->next;
		ListNode *tmp = new ListNode(val);
		tail->next = tmp;
		++_size;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index > _size)
			return;
		if (index == _size)
		{
			addAtTail(val);
			return;
		}

		ListNode *prev = _head;
		while (index--)
			prev = prev->next;
		ListNode *next = prev->next;
		ListNode *tmp = new ListNode(val);

		prev->next = tmp;
		tmp->next = next;

		++_size;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index >= _size)
			return;

		ListNode *prev = _head, *cur = _head->next;
		while (index--)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		delete cur;
		--_size;
	}
};
void test12()
{
	MyLinkedList linkedList;
	linkedList.addAtHead(1);
	linkedList.addAtTail(3);
	linkedList.addAtIndex(1, 2);   //链表变为1-> 2-> 3
	linkedList.get(1);            //返回2
	linkedList.deleteAtIndex(1);  //现在链表是1-> 3
	linkedList.get(1);            //返回3
}

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int value = -1) :val(value), next(NULL){}
};
ListNode* oddEvenList(ListNode* head) {
	if (!head || !head->next)
		return head;

	//拆出两个链表
	ListNode *odd = head, *even = head->next;
	ListNode *o_cur = odd, *e_cur = even, *next = NULL;
	while (e_cur)
	{
		next = e_cur->next;

		o_cur->next = next;
		if (next)
			e_cur->next = next->next;

		if (next)o_cur = next;  //该语句保证了在最后一次循环时，o_cur指向奇链表的最后一个元素。
		e_cur = next == NULL ? NULL : next->next;
	}
	//将奇偶链表连接起来
	o_cur->next = even;

	return head;
}
void test13()
{
	ListNode *head1 = new ListNode(1);
	ListNode *head2 = new ListNode(2); head1->next = head2;
	ListNode *head3 = new ListNode(3); head2->next = head3;
	ListNode *head4 = new ListNode(4); head3->next = head4;
	ListNode *head5 = new ListNode(5); head4->next = head5;
	ListNode *head6 = new ListNode(6); head5->next = head6;
	ListNode *head7 = new ListNode(7); head6->next = head7;

	oddEvenList(head1);
	cout << endl;
}

void test14()
{
	//int *p = new int;
	////free(p);
	////delete p;
	//delete[] p;
	string *p2 = new string;
	delete[] p2;
	//free(p2);
}
void test_draft1()
{
	//test1();
	//test2();//test string
	//string s = "abcabcbb";
	//cout << lengthOfLongestSubstring(s) << endl;

	//test3();//将string转化为int
	//test4();//版本比较  跑过
	//test5(); //只有正整数，+，-，*，/的表达式计算
	//test6(); //123 ---> One Hundred twenty Three  （将非负数字转化为英文输出）
	//test7();   //没跑过
	//test8();
	//test9(); //原地压缩  跑过
	//test10();

	//test11();//override 和 final 关键字
	//test12();
	//test13();
	test14();
}
