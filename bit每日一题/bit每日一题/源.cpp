#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
//1-15.实现1+2+3+...+n,要求不能使用乘除法，循环，条件判断，选择相关的关键字。
int Add(int n)
{
	return n > 0 ? n + Add(n - 1) : 0;
}
void test1_15()
{
	int sum1, sum2,n;
	printf("请输入n:\n");
	scanf("%d", &n);
	sum1 = (int)(pow(n, 2) + n) >> 1;//方法一（没有用乘除）
	printf("%d\n", sum1);
	sum2 = Add(n);             //方法二（递归+三目操作符）
	printf("%d\n", sum2);
}

//1-16.实现一个Add()函数，让两个整数相加，但不能使用+，-，*，/等四则运算符，也不能用++，--。
void test1_16()
{
	int tmp, i, j, a = 7, b = 9;
	printf("please enter two number:\n");
	scanf("%d%d", &a, &b);
	tmp = a | b,b = a & b,a = tmp;
	for (i = 0; i < 8 * sizeof(a); ++i)//考虑到整数有short,int,long long,所以用sizeof()计算字节数
	{
		if (b & 1 << i)
		{
			j = i;
			while (a & 1 << j)
			{
				a = a & ~(1 << j);
				++j;
			}
			a = a | 1 << j;
		}
	}
	printf("a+b = %d\n", a);
}
//逆置单链表
typedef struct node{
	struct node *_next;
	int _data;
	node(int data) :_data(data), _next(nullptr){}
}Node;
void test1_161(){
	Node *cur5 = new Node(5);
	Node *cur4 = new Node(4); cur4->_next = cur5;
	Node *cur3 = new Node(3); cur3->_next = cur4;
	Node *cur2 = new Node(2); cur2->_next = cur3;
	Node *cur1 = new Node(1); cur1->_next = cur2;

	Node *prev = nullptr, *cur = cur1, *next = nullptr;
	if (cur)next = cur->_next;

	while (cur){
		cur->_next = prev;
		prev = cur; cur = next;
		if (next)next = next->_next;
		if (cur)cur->_next = prev;
	}

	while (prev){
		cout << prev->_data << " ";
		prev = prev->_next;
	}
}
//查找单链表中倒数第k个结点
void test1_162(size_t k){
	Node *cur5 = new Node(5);
	Node *cur4 = new Node(4); cur4->_next = cur5;
	Node *cur3 = new Node(3); cur3->_next = cur4;
	Node *cur2 = new Node(2); cur2->_next = cur3;
	Node *cur1 = new Node(1); cur1->_next = cur2;
	
	Node *fast = cur1, *slow = cur1;
	while (fast && --k){fast = fast->_next;}
	if (k > 0)return;

	while (fast->_next){
		fast = fast->_next;
		slow = slow->_next;
	}

	cout << slow->_data;
}

#include<string>
#include<queue>
//1-22.把字符串中的空格符替换为$$$，(要求时间复杂度为O(N))
string test1_22(string &str)//用队列来做的
{
	queue<char> q;
	int i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			q.push(str[i]);
		else
		{
			q.push('$');
			q.push('$');
			q.push('$');

		}
		++i;
	}
	q.push('\0');
	str.clear();
	while (!q.empty())
	{
		str.push_back(q.front());
		q.pop();
	}
	return str;
}
//1-22.把字符串中的空格符替换为$$$，(要求时间复杂度为O(N))
string test1_221(string &str)
{
	//int i = 0;
	//while (str[i])
	//{
	//	if (str[i] == ' ')
	//	{
	//		str.erase(i, 1);
	//		str.insert(i, 3,'$');
	//	}
	//	++i;
	//}

	string::iterator it = str.begin();
	for (; it != str.end(); ++it)
	{
		if (*it == ' ')
		{
			str.erase(it);
			--it;
			it = str.insert(it, 3, '$');
			it += 2;
			//str.replace(it,it + 1, 3, '$');//出错，因为迭代器失效(注意，假如用迭代器在走循环，一定不要用replace(),谁用谁知道 )
		}
	}

	return str;
}
//4. 找出字符串中出现最多的字符和次数。(要求时间复杂度为O(N),空间复杂度为O(1) )
//4.1找出字符串中第一个无重复的字符
//4.2统计字符串中字母的个数           //思路与1-23大致相同
//1-23.查找一个字符串中第一个只出现两次的字符。eg."abcdefabcdefabc"中是'd'.(要求时间复杂度为O(N),空间复杂度为O(N))
bool test1_23(char *str)
{
	int len = strlen(str);
	int hashtables[256] = { 0 };
	for (int i = 0; i < len; ++i)
		hashtables[str[i]]++;
	for (int i = 0; i < len; ++i)
	{
		if (hashtables[str[i]] == 2)
		{
			cout << str[i] << endl;
			return true;
		}
	}
	return false;
}
//5. 找出数组中只出现一次的数字。(要求时间复杂度为O(N),空间复杂度为O(1) )//思路与1.大致相同
//1. 如何判断一个整数数组中是否有重复元素？(要求时间复杂度为O(N),空间复杂度为O(1) )
bool Is_repeatedNum(int *arr,size_t n)
{
	vector<int> v1,v2;//v1数组存储负整数的计数；v2存储自然数的计数
	int i, min = 0, max = 0;
	for (i = 1; i < n; ++i)//寻找数组中最大和最小的两个数，可以开辟合理的辅助空间
	{
		if (arr[i] < min)min = arr[i];
		if (arr[i] > max)max = arr[i];
	}
	if (max < 0){ v1.resize(-min + 1); }//min和max都是负整数的情况
	if (min >= 0){ v2.resize(max + 1); }//min和max都是自然数的情况
	if (min < 0 && max >= 0)//min是负整数，且max是自然数的情况
	{
		v1.resize(-min + 1);
		v2.resize(max + 1);
	}
	for (i = 0; i < n; ++i)//扫描arr数组，然后用辅助数组计数
	{
		if (arr[i] < 0)v1[-arr[i]]++;
		else v2[arr[i]]++;
	}
	for (i = 0; i < n; ++i)//通过arr数组的值作为下标去扫描v1或v2里面的计数
	{
		if (arr[i] < 0 && v1[-arr[i]] > 1)return true;
		if (arr[i] >= 0 && v2[arr[i]] > 1)return true;
	}
	return false;
}
//3.1 一个整型数组里面除了一个数字之外只出现了一次，其他的数字都出现了两次，请找出这一个数。(要求要求时间复杂度为O(N),空间复杂度为O(1) )
int Find_One_SingleNum(int *arr, size_t n)
{
	int tmp = arr[0];
	for (size_t i = 1; i < n; ++i)
		tmp ^= arr[i];
	return tmp;
}
//3.2 一个整型数组里面除了两个数字之外只出现了一次，其他的数字都出现了两次，请找出这两个数。(要求要求时间复杂度为O(N),空间复杂度为O(1) )
////////int Find_Two_SingleNum(int *arr, size_t n)
////////{
////////	//思路2：将数组中所有的数进行异或，得到的结果就是那两个只出现一次的数异或的结果，然后找出这个数的二进制
////////	      //序列中最右边的"1"(假设最右边的"1"在第inter位)，然后找出数组中每个元素的第inter位是"1"还是"0"，
////////	      //是"1"的为一组，是"0"的为一组，最后将每组所有的数进行异或得到两个数
////////}
//////////3.3 一个整型数组里面除了三个数字之外只出现了一次，其他的数字都出现了两次，请找出这三个数。(要求要求时间复杂度为O(N),空间复杂度为O(1) )
////////int Find_Three_SingleNum(int *arr, size_t n)
////////{
////////	//(附加条件：设三个数为x1,x2,x3，且x1^x2^x3!=0)
////////	//思路3：思路2+将得到的两个数与原数组进行比较，就能找出第一个数，+思路2(注意这次使用思路2分组时忽略刚才找到的数)
////////
////////}
//6. 找出数组中出现次数超过数组长度一半的那个数字。(要求时间复杂度为O(N),空间复杂度为O(1) )

//2. O(1)复杂度的字符串查找算法设计
//7. 获取一个字符串在另一个字符串中出现的次数。eg.求"kk"在"abkkcdkkefkkskk"出现的次数
//8. 查找一个字符串中出现最大的字符串(难点是求得字符串还不确定)。eg."51298126712671234578123457812"中出现最多的字符串是"12"
//9. 求字符串中最长连续字符的长度

//计算一个整数二进制位中1的个数，要求正数和负数都能正确计算
void test1_24()
{
	unsigned int n = -155; //(***将n置成非符号数，很好的解决了右移最高位有时会补'1'的尴尬局面)
	unsigned int count = 0;
	unsigned int tmp = n;
	while (tmp > 0)//①可以计算所有整数"1"的个数（循环）
	{
		count++;
		tmp &= tmp - 1;
	}
	cout << count << endl;
	count = 0;
	for (size_t i = 0; i < 8 * sizeof(n); ++i)//②可以计算所有整数"1"的个数（循环）
	{
		if (n & 1 << i)
			count++;
	}
	cout << count << endl;

	//③虽然右移在高位补符号位，但是这里的mask会将其掩盖，不会造成影响
	count = (n & 010101010101) + (n >> 1 & 010101010101) + (n >> 2 & 010101010101) +
		(n >> 3 & 010101010101) + (n >> 4 & 010101010101) + (n >> 5 & 010101010101);
	cout << count % 63 << endl;

	//④由于右移在高位补符号位，所以当n是负数时，总会多计算一个"1"；（有点缺陷）
	count = (n & 011111111111) + (n >> 1 & 011111111111) + (n >> 2 & 011111111111);
	count = count + (count >> 3) & 030707070707;
	cout << count % 63 << endl;
	//⑤由于右移在高位补符号位，所以当n是负数时，总会多计算一个"1"；（缺陷）
	//一个3位二进制数是4a+2b+c,我们想要的是a+b+c,n>>1的结果是2a+b,n>>2的结果是a,于是(4a+2b+c)-(2a+b)-a = a+b+c
	count = n - (n >> 1 & 033333333333) - (n >> 2 & 011111111111);
	count = count + (count >> 3) & 030707070707;
	cout << count % 63 << endl;

	//cout << (4 >> 1) << endl;//右移在高位补符号位
	//cout << (-1 >> 1) << endl;
	//cout << (-1 << 1) << endl;//左移在低位补零
	////10 011001 110101 110011 110010 011001
	printf("%d\n", 010101010101);//1090785345
}
//1.给定一个英文字符串,请写一段代码找出这个字符串中首先出现三次的那个英文字符
//2.给定一个英文字符串,请写一段代码找出这个字符串中第一个只出现三次的那个英文字符
#include<string>
#include<ctype.h>
void Find_ch1()
{
	//string str;
	//int hash[256] = { 0 };
	//getline(cin, str);//得到一行字符，包括空格  方法一
	//for (size_t i = 0; i < str.size(); ++i)
	//{
	//	hash[str[i]]++;
	//	if (hash[str[i]] == 3 && isalpha(str[i]))
	//	{
	//		cout << str[i] << endl;
	//		break;
	//	}
	//}
	
	//char ch;
	//while ((ch = getchar())!='\n')//方法二
	//{
	//	hash[ch]++;
	//	if (hash[ch] == 3 && isalpha(ch))
	//	{
	//		cout << ch;
	//		break;
	//	}
	//}

	//string s;//如何输入n行字符串(包括空格)
	//int n;
	//cin >> n;
	////cin.ignore();//它的作用是干掉滞留在输入流中的换行符
	//getchar();//它的作用是把换行符从输入流中读走
	//for (size_t i = 0; i < n; ++i)
	//{
	//	getline(cin, s);
	//	cout << s << endl;
	//}

	char arr[256];
	scanf("%[^\n]]]]]]", arr);
	cout << arr << endl;
}
//给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
void test_num_big()
{
	string num;
	size_t n, min;
	cin >> n;
	cin >> num;

	while (n > 0)
	{
		min = 0;
		for (size_t i = 0; i < num.size(); ++i)
		{
			if (num[min]>num[i])min = i;
		}
		num.erase(min, 1);
		--n;
	}
	cout << num << endl;
}

bool test1_30(int num)
{
	const int M = 10; const int N = 8;
	int arr[M][N] = { 0 };//待会手动输入一个杨氏矩阵
	int i = 0, j = 0;

	while (j < N && arr[i][j] < num)++j;//先横着找
	while (i < M && j >= 0)
	{
		if (arr[i][j] == num)return true;

		while (i < M && arr[i++][j] < num);//竖着找比num大的
		while (j >= 0 && arr[i][j--] > num);//横着找比num小的
	}
	return false;
}

//由前序遍历和中序遍历重建二叉树（eg.前序序列:1 2 3 4 5 6  后序序列:3 2 4 1 6 5）
#include<stack>
struct TreeNode
{
	int _data;
	TreeNode * _left;
	TreeNode * _right;
	TreeNode(int data)
		:_data(data), _left(NULL), _right(NULL)
	{}
};
void Prevorder(TreeNode *node)
{
	if (!node)return;

	printf("%3d", node->_data);
	Prevorder(node->_left);
	Prevorder(node->_right);
}
void test2_5()
{
	int arr1[] = { 1, 2, 3, 30, 4, 40, 50, 60, 5, 6 }, arr2[] = { 3, 30, 2, 50, 40, 60, 4, 1, 6, 5 };
	const int N = sizeof(arr1) / sizeof(arr1[0]);
	int i = 0, j = 0;
	stack<TreeNode *> sta; 
	TreeNode *_root = new TreeNode(arr1[i]), *node;
	TreeNode *root = _root;

	while (i < N || !sta.empty())
	{
		while (arr1[i] != arr2[j])//从相对的根结点一直往左子树压栈（注，这里这种逻辑不会压最后一个非空左子树）
		{
			node = new TreeNode(arr1[++i]);
			root->_left = node;
			sta.push(root);
			root = root->_left;
		}
		++i;
		sta.push(root);//把最后一个非空左子树压栈
		while (root->_data == arr2[j])
		{
			sta.pop();
			if (!sta.empty() && sta.top()->_data == arr2[++j]){ root = sta.top(); }
			if (sta.empty())++j;
		}
		if (i < N)
		{
			node = new TreeNode(arr1[i]);
			root->_right = node; root = root->_right;
		}
	}

	Prevorder(_root);//打印出前序序列
}
//由中序遍历和后序遍历重建二叉树(eg.中序序列:3 2 4 1 6 5    后序序列: 3 4 2 6 5 1)
void test2_51()
{

}
void test()
{
	vector<int> v;
	v.resize(10);
	cout << v[5] << endl;

	//string str("it is string");
	//string str2("123456");
	//string::iterator it = str.begin() + 2;
	//str.erase(it);
	//cout << *it << endl;
	//--it;
	//it = str.insert(it, str2.begin(), str2.end() - 1);//迭代器失效问题
	//cout << str << "  " << *it << endl;
	////it = str.insert(it, 3, '$');
	////cout << *(it - 1) << *it << *(it + 1) << *(it + 2) << *(it + 3) << endl;
}

int main()
{
	//test();

	//test1_15();

	//test1_16();
	//test1_161();
	//test1_162(6);

	//string str = "talk is cheap show me the code";//string接受隐式类型转换
	//string str1;
	//str = test1_22(str);
	//cout << str << endl;
	//str1 = test1_221(str);
	//cout << str1 << endl;

	//char *str = "abcdefabcdefabc";
	//test1_23(str);

	//test1_24();

	//Find_ch1();

	//test_num_big();

	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,-1};
	//cout << Is_repeatedNum(arr, sizeof(arr) / sizeof(arr[0])) << endl;

	//int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 8 };
	//cout << Find_One_SingleNum(arr, sizeof(arr) / sizeof(arr[0])) << endl;

	//test2_5();

	system("pause");
	return 0;
}