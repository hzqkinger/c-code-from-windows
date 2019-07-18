#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
//1-15.ʵ��1+2+3+...+n,Ҫ����ʹ�ó˳�����ѭ���������жϣ�ѡ����صĹؼ��֡�
int Add(int n)
{
	return n > 0 ? n + Add(n - 1) : 0;
}
void test1_15()
{
	int sum1, sum2,n;
	printf("������n:\n");
	scanf("%d", &n);
	sum1 = (int)(pow(n, 2) + n) >> 1;//����һ��û���ó˳���
	printf("%d\n", sum1);
	sum2 = Add(n);             //���������ݹ�+��Ŀ��������
	printf("%d\n", sum2);
}

//1-16.ʵ��һ��Add()������������������ӣ�������ʹ��+��-��*��/�������������Ҳ������++��--��
void test1_16()
{
	int tmp, i, j, a = 7, b = 9;
	printf("please enter two number:\n");
	scanf("%d%d", &a, &b);
	tmp = a | b,b = a & b,a = tmp;
	for (i = 0; i < 8 * sizeof(a); ++i)//���ǵ�������short,int,long long,������sizeof()�����ֽ���
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
//���õ�����
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
//���ҵ������е�����k�����
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
//1-22.���ַ����еĿո���滻Ϊ$$$��(Ҫ��ʱ�临�Ӷ�ΪO(N))
string test1_22(string &str)//�ö���������
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
//1-22.���ַ����еĿո���滻Ϊ$$$��(Ҫ��ʱ�临�Ӷ�ΪO(N))
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
			//str.replace(it,it + 1, 3, '$');//������Ϊ������ʧЧ(ע�⣬�����õ���������ѭ����һ����Ҫ��replace(),˭��˭֪�� )
		}
	}

	return str;
}
//4. �ҳ��ַ����г��������ַ��ʹ�����(Ҫ��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1) )
//4.1�ҳ��ַ����е�һ�����ظ����ַ�
//4.2ͳ���ַ�������ĸ�ĸ���           //˼·��1-23������ͬ
//1-23.����һ���ַ����е�һ��ֻ�������ε��ַ���eg."abcdefabcdefabc"����'d'.(Ҫ��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(N))
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
//5. �ҳ�������ֻ����һ�ε����֡�(Ҫ��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1) )//˼·��1.������ͬ
//1. ����ж�һ�������������Ƿ����ظ�Ԫ�أ�(Ҫ��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1) )
bool Is_repeatedNum(int *arr,size_t n)
{
	vector<int> v1,v2;//v1����洢�������ļ�����v2�洢��Ȼ���ļ���
	int i, min = 0, max = 0;
	for (i = 1; i < n; ++i)//Ѱ��������������С�������������Կ��ٺ���ĸ����ռ�
	{
		if (arr[i] < min)min = arr[i];
		if (arr[i] > max)max = arr[i];
	}
	if (max < 0){ v1.resize(-min + 1); }//min��max���Ǹ����������
	if (min >= 0){ v2.resize(max + 1); }//min��max������Ȼ�������
	if (min < 0 && max >= 0)//min�Ǹ���������max����Ȼ�������
	{
		v1.resize(-min + 1);
		v2.resize(max + 1);
	}
	for (i = 0; i < n; ++i)//ɨ��arr���飬Ȼ���ø����������
	{
		if (arr[i] < 0)v1[-arr[i]]++;
		else v2[arr[i]]++;
	}
	for (i = 0; i < n; ++i)//ͨ��arr�����ֵ��Ϊ�±�ȥɨ��v1��v2����ļ���
	{
		if (arr[i] < 0 && v1[-arr[i]] > 1)return true;
		if (arr[i] >= 0 && v2[arr[i]] > 1)return true;
	}
	return false;
}
//3.1 һ�����������������һ������֮��ֻ������һ�Σ����������ֶ����������Σ����ҳ���һ������(Ҫ��Ҫ��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1) )
int Find_One_SingleNum(int *arr, size_t n)
{
	int tmp = arr[0];
	for (size_t i = 1; i < n; ++i)
		tmp ^= arr[i];
	return tmp;
}
//3.2 һ�������������������������֮��ֻ������һ�Σ����������ֶ����������Σ����ҳ�����������(Ҫ��Ҫ��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1) )
////////int Find_Two_SingleNum(int *arr, size_t n)
////////{
////////	//˼·2�������������е���������򣬵õ��Ľ������������ֻ����һ�ε������Ľ����Ȼ���ҳ�������Ķ�����
////////	      //���������ұߵ�"1"(�������ұߵ�"1"�ڵ�interλ)��Ȼ���ҳ�������ÿ��Ԫ�صĵ�interλ��"1"����"0"��
////////	      //��"1"��Ϊһ�飬��"0"��Ϊһ�飬���ÿ�����е����������õ�������
////////}
//////////3.3 һ�������������������������֮��ֻ������һ�Σ����������ֶ����������Σ����ҳ�����������(Ҫ��Ҫ��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1) )
////////int Find_Three_SingleNum(int *arr, size_t n)
////////{
////////	//(������������������Ϊx1,x2,x3����x1^x2^x3!=0)
////////	//˼·3��˼·2+���õ�����������ԭ������бȽϣ������ҳ���һ������+˼·2(ע�����ʹ��˼·2����ʱ���Ըղ��ҵ�����)
////////
////////}
//6. �ҳ������г��ִ����������鳤��һ����Ǹ����֡�(Ҫ��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1) )

//2. O(1)���Ӷȵ��ַ��������㷨���
//7. ��ȡһ���ַ�������һ���ַ����г��ֵĴ�����eg.��"kk"��"abkkcdkkefkkskk"���ֵĴ���
//8. ����һ���ַ����г��������ַ���(�ѵ�������ַ�������ȷ��)��eg."51298126712671234578123457812"�г��������ַ�����"12"
//9. ���ַ�����������ַ��ĳ���

//����һ������������λ��1�ĸ�����Ҫ�������͸���������ȷ����
void test1_24()
{
	unsigned int n = -155; //(***��n�óɷǷ��������ܺõĽ�����������λ��ʱ�Ჹ'1'�����ξ���)
	unsigned int count = 0;
	unsigned int tmp = n;
	while (tmp > 0)//�ٿ��Լ�����������"1"�ĸ�����ѭ����
	{
		count++;
		tmp &= tmp - 1;
	}
	cout << count << endl;
	count = 0;
	for (size_t i = 0; i < 8 * sizeof(n); ++i)//�ڿ��Լ�����������"1"�ĸ�����ѭ����
	{
		if (n & 1 << i)
			count++;
	}
	cout << count << endl;

	//����Ȼ�����ڸ�λ������λ�����������mask�Ὣ���ڸǣ��������Ӱ��
	count = (n & 010101010101) + (n >> 1 & 010101010101) + (n >> 2 & 010101010101) +
		(n >> 3 & 010101010101) + (n >> 4 & 010101010101) + (n >> 5 & 010101010101);
	cout << count % 63 << endl;

	//�����������ڸ�λ������λ�����Ե�n�Ǹ���ʱ���ܻ�����һ��"1"�����е�ȱ�ݣ�
	count = (n & 011111111111) + (n >> 1 & 011111111111) + (n >> 2 & 011111111111);
	count = count + (count >> 3) & 030707070707;
	cout << count % 63 << endl;
	//�����������ڸ�λ������λ�����Ե�n�Ǹ���ʱ���ܻ�����һ��"1"����ȱ�ݣ�
	//һ��3λ����������4a+2b+c,������Ҫ����a+b+c,n>>1�Ľ����2a+b,n>>2�Ľ����a,����(4a+2b+c)-(2a+b)-a = a+b+c
	count = n - (n >> 1 & 033333333333) - (n >> 2 & 011111111111);
	count = count + (count >> 3) & 030707070707;
	cout << count % 63 << endl;

	//cout << (4 >> 1) << endl;//�����ڸ�λ������λ
	//cout << (-1 >> 1) << endl;
	//cout << (-1 << 1) << endl;//�����ڵ�λ����
	////10 011001 110101 110011 110010 011001
	printf("%d\n", 010101010101);//1090785345
}
//1.����һ��Ӣ���ַ���,��дһ�δ����ҳ�����ַ��������ȳ������ε��Ǹ�Ӣ���ַ�
//2.����һ��Ӣ���ַ���,��дһ�δ����ҳ�����ַ����е�һ��ֻ�������ε��Ǹ�Ӣ���ַ�
#include<string>
#include<ctype.h>
void Find_ch1()
{
	//string str;
	//int hash[256] = { 0 };
	//getline(cin, str);//�õ�һ���ַ��������ո�  ����һ
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
	//while ((ch = getchar())!='\n')//������
	//{
	//	hash[ch]++;
	//	if (hash[ch] == 3 && isalpha(ch))
	//	{
	//		cout << ch;
	//		break;
	//	}
	//}

	//string s;//�������n���ַ���(�����ո�)
	//int n;
	//cin >> n;
	////cin.ignore();//���������Ǹɵ��������������еĻ��з�
	//getchar();//���������ǰѻ��з����������ж���
	//for (size_t i = 0; i < n; ++i)
	//{
	//	getline(cin, s);
	//	cout << s << endl;
	//}

	char arr[256];
	scanf("%[^\n]]]]]]", arr);
	cout << arr << endl;
}
//����һ��ʮ���Ƶ�������number��ѡ�������ȥ��һ�������֣�ϣ������������������ɵ����������
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
	int arr[M][N] = { 0 };//�����ֶ�����һ�����Ͼ���
	int i = 0, j = 0;

	while (j < N && arr[i][j] < num)++j;//�Ⱥ�����
	while (i < M && j >= 0)
	{
		if (arr[i][j] == num)return true;

		while (i < M && arr[i++][j] < num);//�����ұ�num���
		while (j >= 0 && arr[i][j--] > num);//�����ұ�numС��
	}
	return false;
}

//��ǰ���������������ؽ���������eg.ǰ������:1 2 3 4 5 6  ��������:3 2 4 1 6 5��
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
		while (arr1[i] != arr2[j])//����Եĸ����һֱ��������ѹջ��ע�����������߼�����ѹ���һ���ǿ���������
		{
			node = new TreeNode(arr1[++i]);
			root->_left = node;
			sta.push(root);
			root = root->_left;
		}
		++i;
		sta.push(root);//�����һ���ǿ�������ѹջ
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

	Prevorder(_root);//��ӡ��ǰ������
}
//����������ͺ�������ؽ�������(eg.��������:3 2 4 1 6 5    ��������: 3 4 2 6 5 1)
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
	//it = str.insert(it, str2.begin(), str2.end() - 1);//������ʧЧ����
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

	//string str = "talk is cheap show me the code";//string������ʽ����ת��
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