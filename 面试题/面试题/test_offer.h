#pragma once
#include"DefineNode.h"

//��ָoffer��1����һ����ά�����У�ÿһ�ж����մ������ҵ�����˳������ÿһ�ж����մ������µ�����˳������
//���һ������������һ�������жϸ����Ƿ��������С���ps:���Դ��ĸ��ǿ�ʼ�������д����½Ǻ����Ͻǲ���˼·�Ƚ�������
//      ˼·һ�������½��������������ֵݼ����������ֵ�����
//            ��ˣ������½ǿ�ʼ����Ҫ������ֱ����½����ִ�ʱ�����ƣ���������
#include<vector>
bool Find(vector<vector<int>> arr, int target)
{
	int rowcount = arr.size();
	int colcount = arr[0].size();

	int i, j;
	for (i = rowcount - 1, j = 0; i >= 0 && j < colcount;)
	{
		if (target == arr[i][j])return true;

		if (target < arr[i][j])--i;//targetС��array[i][j],����
		else ++j;//��������
	}
	return false;
}
//     ˼·���������Ͻǿ�ʼ���ң����ڵ�һ���ҵ�����target������
//             Ȼ��target��array[i][j]��ʱ�����ƣ���������
bool Find2(vector < vector<int>> arr, int target)
{
	int rowcount = arr.size();
	int colcount = arr[0].size();

	int i = 0, j = 0;
	while (j < colcount - 1 && arr[i][j] <= target)++j;//��һ�У��������ң��ҵ���һ������target����

	while (i < rowcount && j >= 0)
	{
		if (arr[i][j] == target)return true;

		if (arr[i][j] < target)//array[i][j]С��target������
			++i;
		else --j;//��������
	}
	return false;
}
void test_offer1()
{
	vector<vector<int>> _v = { { 1, 5, 9, 13 }, { 2, 7, 10, 14 }, { 3, 8, 13, 16 }, { 5, 10, 14, 17 }, { 19, 23, 26, 29 } };
	cout << Find(_v, 26) << endl;
	cout << Find2(_v, 26) << endl;
}

//��ָoffer��2��ʵ��һ����������һ���ַ����еĿո��滻��"%20"�����磬���ַ���We Are Happy�����任֮����We%20Are%20Happy
#include<string>
string& ReplaceSpace(string& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
			str.replace(i, 1, "%20");
	}
	return str;
}
char *ReplaceSpace2(char *str)
{
	int count = 0, size = strlen(str);
	for (size_t i = 0; i < size; ++i)
	{
		if (str[i] == ' ')count++;//�ȼ�����ж��ٿո�
	}
	int size2 = size + 2 * count + 1;
	char *tmp = (char*)malloc(size2);//����滻��Ŀռ��С
	count = 0;//�����濪ʼ��count��str��index.
	for (size_t i = 0; i <= size2; ++i)
	{
		if (str[count] == ' ')
		{
			tmp[i++] = '%';
			tmp[i++] = '2';
			tmp[i] = '0';
			++count;
			continue;
		}

		tmp[i] = str[count++];
	}
	return tmp;
}
void ReplaceSpace3(char *str, int length)
{                                 //length��ʾstrָ��Ŀռ�ĳ���
	if (str == NULL && length <= 0)
		return;
	int increblankspace = 0;//��¼�ո�ĸ���
	int orilen = 0;//��¼ԭʼ�ַ����ĸ���
	for (int i = 0; str[i] != '\0'; i++) {
		++orilen;
		if (str[i] == ' ')
			++increblankspace;
	}
	int len = increblankspace * 2 + orilen;//��¼�滻���ַ����ĳ���
	for (int j = orilen; j >= 0;) {
		if (str[j] != ' ')
			str[len--] = str[j];
		else {
			str[len--] = '0';
			str[len--] = '2';
			str[len--] = '%';
		}
		--j;
	}
}
void test_offer2()
{
	string str = "We Are Happy";
	cout << ReplaceSpace(str) << endl;
	cout << ReplaceSpace2("We Are Happy") << endl;
}

//��ָoffer��3������һ��������β��ͷ��ӡ����ÿ������ֵ
//      ˼·һ���ݹ�       ˼·����˳������������vector���飬
void PrintListFromTailtoHead(FlistNode *root)//�ݹ�
{
	if (!root)return;

	PrintListFromTailtoHead(root->next);

	printf("%d ", root->val);
}
void test_offer3()
{
	FlistNode *head1 = new FlistNode(1);
	FlistNode *head2 = new FlistNode(2); head1->next = head2;
	FlistNode *head3 = new FlistNode(3); head2->next = head3;
	FlistNode *head4 = new FlistNode(4); head3->next = head4;
	FlistNode *head5 = new FlistNode(5); head4->next = head5;
	PrintListFromTailtoHead(head1);
	cout << endl;
}

//��ָofffer��4������ĳ��������ǰ���������������Ľ�����ؽ��ö�������
//    ˼·һ���ݹ�             ˼·�����ǵݹ�
TreeNode *ReConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (pre.empty())return NULL;

	vector<int> leftpre; vector<int> rightpre;
	vector<int> leftvin; vector<int> rightvin;

	int i = 0, j = 0;
	TreeNode *root = new TreeNode(pre[i++]);

	while (pre[0] != vin[j++])
	{
		leftpre.push_back(pre[i++]);
		leftvin.push_back(vin[j - 1]);
	}
	while (i < pre.size())
	{
		rightpre.push_back(pre[i++]);
		rightvin.push_back(vin[j++]);
	}

	root->left = ReConstructBinaryTree(leftpre, leftvin);
	root->right = ReConstructBinaryTree(rightpre, rightvin);

	return root;
}
void test_offer4()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode *root;
	root = ReConstructBinaryTree(pre, vin);//�ݹ鷽��             �ǵݹ鷽��ûд
	cout << "��ǰ��������ؽ�" << endl;
}

//��ָoffer��5��������ջ��ʵ��һ�����У���ɶ��е�Pop��Push������ע��Ԫ��Ϊint����
#include<stack>
template<class T>
class Queue_By_TwoStack{
public:
	void Push(const T &x)
	{
		s1.push(x);
	}
	void Pop()
	{
		if (s2.empty())
		{
			while (!s1.empty()){ s2.push(s1.top()); s1.pop(); }
		}
		s2.pop();
	}

	const T &Front()
	{
		if (s2.empty())
		{
			while (!s1.empty()){ s2.push(s1.top()); s1.pop(); }
		}
		return s2.top();
	}
	const T &Back()
	{
		if (s1.empty())
		{
			while (!s2.empty()){ s1.push(s2.top()); s1.pop(); }
		}
		return s1.top();
	}
	size_t size()
	{
		return s1.size() + s2.size();
	}
private:
	stack<T> s1;
	stack<T> s2;
};
void test_offer5()
{
	Queue_By_TwoStack<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	cout << q.Front() << endl;//1
	q.Pop();
	cout << q.Front() << endl;//2
	q.Pop();
	q.Push(4);
	cout << q.Front() << endl;//3
	q.Pop();
	q.Push(5);
	cout << q.Front() << endl;//4
	q.Pop();
	q.Push(6);
	cout << q.Front() << endl;//5
	q.Pop();
	cout << q.Front() << endl;//6
	q.Pop();

}

//��ָoffer��6����һ�������ʼ������Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת������һ���ǵݼ�����������һ��
//              ��ת�������ת�������СԪ�ء�eg.����{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1.
//              (ע���������������Ԫ�ض�����0���������СΪ0���򷵻�0)
//     ˼·����ͷ��ʼ��������������һ�����ȵ�ǰҪС����ô��һ����һ������С����
#include<vector>
int MinNumberInRotateArray(vector<int> arr)
{
	if (arr.empty())return 0;//�����СΪ0ʱ

	size_t i = 0;
	for (; i < arr.size() - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
			break;
	}

	return i == arr.size() - 1 ? arr[0] : arr[i + 1];
}
void test_offer6()
{
	vector<int> arr = { 3, 4, 5, 6, 1, 2 };
	cout << MinNumberInRotateArray(arr) << endl;
}

//��ָoffer��7������Ҫ������һ������n�������쳲��������еĵ�n���ͨ�ʽ: f(n) = f(n-1) + f(n-2)��ע�⣬f(0) = 0
//    ˼·һ������ѭ����      ˼·������ʽ��       ˼·����β�ݹ鷨(���ݹ���������������������ִ�е���䣬�����ķ���ֵ�����ڱ��ʽ��һ����ʱ������ݹ����Ϊ�ݹ�)
int Fibonacci(size_t n)//ѭ��������  //0 1 1 2 3 5 8 13 21...
{
	if (n < 1)return n;

	int tmp, acc1 = 0, acc2 = 1;
	while (--n)
	{
		tmp = acc2;
		acc2 += acc1;
		acc1 = tmp;
	}

	return acc2;
}
int Fibonacci2(size_t n)//��ʽ��
{
	double x = pow((1 + sqrt(5)) / 2, n);
	double y = pow((1 - sqrt(5)) / 2, n);

	return 1 / sqrt(5) * (x - y);
}
int Fibonacci3(int n, int acc1 = 0, int acc2 = 1)//β�ݹ鷨
{
	if (n == 0)return 0;

	if (n == 1)
		return acc2;
	else
		return Fibonacci3(n - 1, acc2, acc1 + acc2);
}
void test_offer7()
{
	cout << Fibonacci(5) << endl;
	cout << Fibonacci2(5) << endl;
	cout << Fibonacci3(5) << endl;
}

//��ָoffer��8��һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ס������������һ��n����̨���ܹ��ж�����������
//         ����:�������һ�ξ����ϵ�n��̨�ף���ô������һ��һ���ڵ�n-1��n-2��̨���ϣ�f(n) = f(n-1) + f(n-2)  ע��f(0) = 1
int FlogJumpStep(size_t n)// 0 1 2 3 5 8 13 21...
{
	if (n < 2)return n;

	int acc0 = 0, acc1 = 1;
	int tmp;

	while (--n)
	{
		tmp = acc1;
		acc1 += acc0;
		acc0 = tmp;
	}
	return acc1;
}

//��ָoffer��9��һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨��...Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
//    ���Ϸ����ã�f(n) = f(n-1)+f(n-2)+...+f(1);  ע��f(0) = 1
//                f(n-1) = f(n-2)+f(n-3)+...+f(1);     ----->   f(n) = 2 * f(n-1)
int FlogJumpStep2(size_t n)
{
	if (n < 1)return n;

	int acc2, acc1 = 1;
	while (--n)
	{
		acc2 = acc1 * 2;
		acc1 = acc2;
	}
	return acc1;
}

//��ָoffer��10�����ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
//               ������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ���
int RectanglePave(size_t n)//0 1 2 3 5 8 13 21...
{
	if (n < 2)return n;

	int acc0 = 0, acc1 = 1;
	int tmp;

	while (--n)
	{
		tmp = acc1;
		acc1 += acc0;
		acc0 = tmp;
	}
	return acc1;
}
void test_offer7_8_9_10()
{
	int n = 5;
	cout << "test_offer7   " << Fibonacci(n) << endl;//7
	cout << "test_offer7   " << Fibonacci2(n) << endl;//7
	cout << "test_offer7   " << Fibonacci3(n) << endl;//7
	cout << "test_offer8   " << FlogJumpStep(n) << endl;//8
	cout << "test_offer9   " << FlogJumpStep2(n) << endl;//9
	cout << "test_offer10  " << RectanglePave(n) << endl;//10
}

//��ָoffer��11������һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ
int NumberOf1(size_t n)
{
	int count = 0;
	while (n)
	{
		++count;
		n &= (n - 1);
	}
	return count;
}
void test_offer11()
{
	cout << NumberOf1(-1) << endl;
}

//��ָoffer��12������һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
//            exponent < 0;    exponent = 0;     exponent > 0
double Exponent(double base, int exp)
{
	double sum = 1;
	if (exp < 0)
	{
		exp = -exp;
		while (exp--)
			sum /= base;
	}
	else if (exp > 0)
	{
		while (exp--)
			sum *= base;
	}
	return sum;
}
void test_offer12()
{
	cout << Exponent(4, -2) << endl;
}

//��ָoffer��13������һ���������飬ʵ��һ�����������������������ֵ�˳�������е�����λ�������ǰ�벿�֣�
//             ���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
//   ����һ���ø�������         ����������������ָ�������ż����Ȼ�����Щż�������һ�����ٰѺ����һ�������ŵ�ǰ�棻�ظ�����ֱ������
#include<vector>
void ReSortArray(vector<int> &v)
{
	vector<int> even_store;
	even_store.reserve(v.size());

	int oddp = 0, evenp = 0;
	while (evenp < v.size())
	{
		if (v[evenp] & 0x01)//����������Դ�����ǰ��Ų
			v[oddp++] = v[evenp];
		else
			even_store.push_back(v[evenp]);//�����ȴ�����

		++evenp;
	}
	for (size_t i = 0; i < even_store.size(); ++i)//�Ѵ��ڸ��������ż��Ų����
		v[oddp++] = even_store[i];
}
void test_offer13()
{
	vector<int> v = { 0, 0, 0, 1, 2, 3, 4, 4, 4, 5, 6, 6, 7, 8, 9, 1 };
	ReSortArray(v);
	for (auto &r : v)cout << r << " ";
}

//��ָoffer��14������һ����������������е�����k����㡣
FlistNode *SingLinkList(FlistNode * head, size_t k)
{
	FlistNode *slow = head, *fast = head;

	int count = 0;//�������������е����ж��ٸ����
	while (fast){ ++count; fast = fast->next; }
	k %= count + 1;//ps�����k��ֵ����countʱ������k��ֵ��ʮ���б�Ҫ�ģ�

	fast = head;
	while (k--)fast = fast->next;//���ﲻ���ж�fast�Ƿ�Ϊ��,��Ϊǰ��������k��ֵ

	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
void test_offer14()
{
	FlistNode* head1 = new FlistNode(1);
	FlistNode* head2 = new FlistNode(2); head1->next = head2;
	FlistNode* head3 = new FlistNode(3); head2->next = head3;
	FlistNode* head4 = new FlistNode(4); head3->next = head4;
	FlistNode* head5 = new FlistNode(5); head4->next = head5;
	FlistNode* head6 = new FlistNode(6); head5->next = head6;

	FlistNode* tmp = SingLinkList(head1, 12);
	if (tmp)
		cout << tmp->val << endl;
}

//��ָoffer��15������һ����������ת�����������������Ԫ�ء�
void ReverseSinglyLinkList(FlistNode *head)
{
	FlistNode *prev = NULL, *cur = head, *next = NULL;
	if (cur)next = cur->next;

	while (cur)//���õ�����
	{
		cur->next = prev;

		prev = cur;
		cur = next;
		if (next)next = next->next;
	}

	while (prev)
	{
		cout << prev->val << " ";
		prev = prev->next;
	}cout << endl;
}
void test_offer15()
{
	FlistNode* head1 = new FlistNode(1);
	FlistNode* head2 = new FlistNode(2); head1->next = head2;
	FlistNode* head3 = new FlistNode(3); head2->next = head3;
	FlistNode* head4 = new FlistNode(4); head3->next = head4;
	FlistNode* head5 = new FlistNode(5); head4->next = head5;
	FlistNode* head6 = new FlistNode(6); head5->next = head6;
	ReverseSinglyLinkList(head1);
}

//��ָoffer��16�������������������ĵ���������ϲ��������ʹ֮���㵥����������
FlistNode *MergeTwoSinglyList(FlistNode *head1, FlistNode *head2)
{
	if (!head1)return head2;//head1Ϊ�գ�ֱ�ӷ���head2
	if (!head2)return head1;//ͬ��

	FlistNode *sma = head1, *big = head2;
	if (sma->val > big->val){ swap(sma, big); head1 = sma; }

	while (sma && big)//��������Ĳ�����small->_valһ��С��big->_val��
	{
		FlistNode *next;

		while (sma->next && sma->next->val <= big->val)
			sma = sma->next;//�ҵ����ʵ�λ��

		next = big->next;

		big->next = sma->next;
		sma->next = big;

		sma = sma->next;//����ѭ����һֱ��֤small->_valС��big->_val.
		big = next;
	}
	return head1;
}
void test_offer16()
{
	FlistNode* head1 = new FlistNode(1);
	FlistNode* head2 = new FlistNode(1); head1->next = head2;
	FlistNode* head3 = new FlistNode(1); head2->next = head3;
	FlistNode* head4 = new FlistNode(4); head3->next = head4;
	FlistNode* head5 = new FlistNode(5); head4->next = head5;
	FlistNode* head6 = new FlistNode(6); head5->next = head6;

	FlistNode* cur1 = new FlistNode(1);
	FlistNode* cur2 = new FlistNode(2); cur1->next = cur2;
	FlistNode* cur3 = new FlistNode(3); cur2->next = cur3;
	FlistNode* cur4 = new FlistNode(4); cur3->next = cur4;
	FlistNode* cur5 = new FlistNode(5); cur4->next = cur5;
	FlistNode* cur6 = new FlistNode(6); cur5->next = cur6;

	FlistNode *tmp = MergeTwoSinglyList(head1, cur1);
	while (tmp)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}cout << endl;
}

//��ָoffer��17���������ö�����A,B,�ж�B�ǲ���A���ӽṹ(ps:Լ��������������һ�������ӽṹ)
bool HasSubtree(TreeNode *rootA,TreeNode *rootB)
{
	//�ս�����ʱ��,rootA->_valһ������rootB->_val
	if (!rootB)return true;

	return (rootA && rootA->val == rootB->val)
		&& HasSubtree(rootA->left, rootB->left)
		&& HasSubtree(rootA->right, rootB->right);
}
bool IsSubtree(TreeNode *rootA,TreeNode *rootB)
{
	if (!rootA || !rootB)return false;

	bool flag = false;
	if (rootA->val == rootB->val)
		flag = HasSubtree(rootA, rootB);

	return flag ? true : IsSubtree(rootA->left, rootB) || IsSubtree(rootA->right, rootB);
}
void test_offer17()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	head1->left = head2; head1->right = head3;//��
	head2->left = head4;//������
	head4->right = head7;
	head3->left = head5; head3->right = head6;//������
	head6->left = head8;

	TreeNode *cur1 = new TreeNode(2);
	TreeNode *cur2 = new TreeNode(5);
	TreeNode *cur3 = new TreeNode(6);
	cur1->left = cur2; cur1->right = cur3;

	cout << HasSubtree(head3, cur1) << endl;
	cout << IsSubtree(head1, cur1) << endl;
}

//��ָoffer��18�����������Ķ�����������任ΪԴ�������ľ���
void MirrorBinaryTree(TreeNode *root)
{
	if (!root)return;

	swap(root->left, root->right);
	MirrorBinaryTree(root->left);
	MirrorBinaryTree(root->right);
}
void test_offer18()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	head1->left = head2; head1->right = head3;//��
	head2->left = head4;//������
	head4->right = head7;
	head3->left = head5; head3->right = head6;//������
	head6->left = head8;

	MirrorBinaryTree(head1);
	cout << "hah" << endl;
}

//��ָoffer��19������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�eg. 1  2  3  4
//                                                                                 5  6  7  8
//                                                                                 9  10 11 12
//                                                                                 13 14 15 16
//                                                       �����δ�ӡ��1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
#include<vector>
vector<int> PrintMaterix(vector<vector<int>> matrix)
{
	vector<int> v;

	int up = 0, down = matrix.size();
	int left = 0, right = matrix[0].size();

	while (up < down && left < right)//˳ʱ���ӡ
	{
		int i = up, j = left - 1;
		while (++j < right)
			v.push_back(matrix[i][j]);//�Ϻ�
		--j; if (up + 1 == down){ ++up; continue; }

		while (++i < down)
			v.push_back(matrix[i][j]);//����
		--i; if (right - 1 == left){ --right; continue; }

		while (--j >= left)
			v.push_back(matrix[i][j]);//�º�
		++j;

		while (--i > up)
			v.push_back(matrix[i][j]);//����
		++i;

		up++; right--; down--; left++;
	}
	return v;
}
void test_offer19()
{
	int k = 1;
	const size_t n = 4;
	vector<vector<int>> v(n);
	for (size_t i = 0; i < v.size(); ++i)
	{
		const size_t m = 4;
		vector<int> arr(m);
		for (size_t j = 0; j < arr.size(); ++j)
			arr[j] = k++;

		v[i] = arr;
	}

	vector<int> tmp = PrintMaterix(v);
	for (auto&r : tmp)cout << r << " "; cout << endl;
}

//��ָoffer��20������һ��ջ��ʹ��ʵ��һ��min������min��������O(1)ȡ��ջ����С������
#include<stack>
class Stack
{
public:
	void Push(int x)
	{
		s.push(x);
		if (help.empty())
			help.push(x);
		else
		{
			if (x < help.top())
				help.push(x);
			else
				help.push(help.top());
		}
	}
	void pop()
	{
		s.pop();
		help.pop();
	}
	int Min()
	{
		return help.top();
	}
private:
	stack<int> s;
	stack<int> help;
};

//��ָoffer��21�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
#include<vector>
#include<stack>
bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	if (pushV.size() != popV.size())return false;

	stack<int> sta;
	size_t pop_index = 0;
	for (size_t i = 0; i < pushV.size(); ++i)
	{
		if (pushV[i] != popV[pop_index])
			sta.push(pushV[i]);
		else
			++pop_index;
	}
	while (!sta.empty() && sta.top() == popV[pop_index++])
		sta.pop();

	return sta.empty() ? true : false;
}
void test_offer21()
{
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 4, 5, 1, 2, 3 };
	cout << IsPopOrder(pushV, popV) << endl;
}

//��ָoffer��22���������һ�ö�����
#include<queue>
vector<int> PrintFromTopToBottom(TreeNode* root)
{
	if (!root)return vector<int>();

	vector<int> dst;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode *front = q.front();
		dst.push_back(front->val);
		q.pop();
		if (front->left)q.push(front->left);
		if (front->right)q.push(front->right);
	}
	return dst;
}
void test_offer22()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	head1->left = head2; head1->right = head3;//��
	head2->left = head4;//������
	head4->right = head7;
	head3->left = head5; head3->right = head6;//������
	head6->left = head8;

	vector<int> tmp = PrintFromTopToBottom(head1);
	for (auto&r : tmp)cout << r << " "; cout << endl;
}

//��ָoffer��23������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����(����������������������ͬ)
//  ����һ���ݹ飬���ڶ����������ĺ�����������ȥ���������е����һ�����ݣ�Ҳ���Ǹ�������ô����ֳ������֣�
//                 ǰ���������������󲿷���������
//  ���������ǵݹ飬���ڵݹ�˼��д�ɷǵݹ飬O(n^2)
bool Judge(vector<int>& post, int left, int right)
{
	if (left >= right)return true;

	bool flag = false;
	int li = left, ri = right - 1;
	while (li < right && post[li] < post[right])++li;
	while (ri >= left && post[ri] > post[right])--ri;
	if (li > ri)flag = true;

	return flag
		&& Judge(post, left, ri)
		&& Judge(post, li, right - 1);
}
bool VerifySquenceOfBST(vector<int> post)
{
	if (post.empty())return false;

	return Judge(post, 0, post.size() - 1);
}
bool VerifySquenceOfBST2(vector<int> post)
{
	int size = post.size();
	while (--size)
	{
		int count = size, index = size - 1;
		while (index >= 0 && post[index] > post[size]){ --count; --index; }
		while (index >= 0 && post[index] < post[size]){ --count; --index; }

		if (count != 0)return false;
	}
	return true;
}
void test_offer23()
{
	vector<int> v = { 2, 1, 3, 5, 7, 8, 6, 4 };//true
	vector<int> v2 = { 7, 4, 2, 5, 8, 6, 3, 1 };//false
	cout << VerifySquenceOfBST(v2) << endl;
	cout << VerifySquenceOfBST2(v2) << endl;

}

//��ָoffer��24������һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//              ·������Ϊ���ĸ���㿪ʼ����һֱ��Ҷ�ڵ��������Ľ���γ�һ��·��
void _FindPath(TreeNode *root, vector<int>&res,vector<vector<int>> &dst,int sum, int target)
{
	if (!root)return;

	vector<int> res_tmp = res;
	res_tmp.push_back(root->val);
	if ((sum += root->val) == target && !root->left && !root->right)
		dst.push_back(res_tmp);
	if (sum <= target)
		_FindPath(root->left, res_tmp, dst, sum, target);
	if (sum <= target)
		_FindPath(root->right, res_tmp, dst, sum, target);
}
vector<vector<int>> FindPath(TreeNode* root, int target)
{
	vector<int> res;
	vector<vector<int>>dst;
	int sum = 0;
	_FindPath(root, res, dst, sum, target);
	return dst;
}
void test_offer24()
{
	TreeNode *head10 = new TreeNode(10);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head12 = new TreeNode(12);
	head10->left = head5; head10->right = head12;
	head5->left = head4; head5->right = head7;

	vector<vector<int>> dst = FindPath(head10, 22);
	for (size_t i = 0; i < dst.size(); ++i)
	{
		for (size_t j = 0; j < dst[i].size(); ++j)
			cout << dst[i][j] << " ";
		cout << endl;
	}
}

//��ָoffer��25������һ���������
RondomListNode* RandomLinkCopy(RondomListNode *head)
{
	if (!head)return NULL;//ͷ����ǿ�ֱ�ӷ���

	RondomListNode *cur = head, *next = head->next;//�ɢ٢ڢ۱�ɢ٢٢ڢڢۣۢ������Ƴ����Ľ������ָ�붼ָ���
	while (cur){
		RondomListNode *tmp = new RondomListNode(cur->val);
		cur->next = tmp; tmp->next = next;
		cur = next; if (next)next = next->next;
	}
	cur = head; next = cur->next;//�����ָ��ָ����ȷ��λ��
	while (cur){
		next->rand = cur->rand ? cur->rand->next : NULL;
		cur = next->next; if (cur)next = cur->next;
	}
	cur = head; next = cur->next;//���¾�������뿪
	RondomListNode *tmp = next;
	while (cur){
		cur->next = next->next; cur = next->next;
		if (cur){ next->next = cur->next; next = cur->next; }
		else next->next = NULL;
	}
	return tmp;//���ظ��Ƴ������������ͷ���
}
void test_offer25()
{
	RondomListNode* head1 = new RondomListNode(1);
	RondomListNode* head2 = new RondomListNode(2); head1->next = head2;
	RondomListNode* head3 = new RondomListNode(3); head2->next = head3;
	RondomListNode* head4 = new RondomListNode(4); head3->next = head4;
	RondomListNode* head5 = new RondomListNode(5); head4->next = head5;
	head1->rand = head4;
	head2->rand = head3;
	head3->rand = head3;
	head4->rand = NULL;
	head5->rand = head3;

	RondomListNode *tmp = RandomLinkCopy(head1);
	while (tmp && head1)
	{
		if (tmp->val != head1->val){ cout << "false" << endl; break; }
		if (tmp->rand && head1->rand)
		{
			if (tmp->rand->val != head1->rand->val){ cout << "false" << endl; break; }
		}
		else if (!tmp->rand && !head1->rand)
		{
			;
		}
		else
		{
			cout << "false" << endl; break;
		}
		tmp = tmp->next;
		head1 = head1->next;
	}
	cout << true;
}

//��ָoffer��26������һ�ö��������������ö�����ת����һ�������˫������Ҫ���ܴ����µĽ�㣬ֻ�ܵ������н���ָ��
TreeNode *_TreeToLink(TreeNode *root)
{
	if (!root)return NULL;//�ݹ鷵������

	TreeNode *left = _TreeToLink(root->left);//left����ߵ������������
	TreeNode *right = _TreeToLink(root->right);//right���ұߵ������������

	TreeNode *left_to_right;//��ߵ���������ҽ��
	left_to_right = left ? left->left : NULL;
	TreeNode *right_to_right;//�ұߵ���������ҽ��
	right_to_right = right ? right->left : NULL;

	root->left = left_to_right;//��������
	if (left_to_right)left_to_right->right = root;
	root->right = right;//�����Һ���
	if (right)right->left = root;

	if (!left)left = root;
	left->left = right ? right_to_right : root;

	return left;
}
TreeNode *TreeToLink(TreeNode *root)//�ݹ�˼·
{
	if (!root)return NULL;

	TreeNode *head = _TreeToLink(root);
	head->left = NULL;
	return head;
}
void test_offer26()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	head4->left = head3; head4->right = head6;//��
	head3->left = head1;//������
	head1->right = head2;
	head6->left = head5; head6->right = head8;//������
	head8->left = head7;

	TreeNode *head = TreeToLink(head4);
	TreeNode *cur = head;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->right;
	}cout << endl;
}

//��ָoffer��27������һ���ַ��������ֵ����ӡ�����ַ������ַ����������С�

//��ָoffer��28����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ��������,ps:��������ڷ���0.
//  ����һ:����    ������:map<K,V>    ������:��ع���˼�룬���õ�һ��Ԫ����Ϊ��һ��ʿ��������أ�count=1��
//                                       ������ͬ��Ԫ��++count,����--count;��count=0ʱ�������µ�iֵ��Ϊ����ص�ʿ����
// �����ģ��ö��ҳ�һ��Ԫ��,���ضѶ�     ֱ������ʿ�����Ǽ�������Ԫ��
int MoreThanHalfNum(vector<int> arr)//������
{
	if (arr.empty())return 0;

	int count = 1, soldier = arr[0];
	for (int i = 1; i < arr.size(); ++i)
	{
		arr[i] == soldier ? ++count : --count;

		if (count == 0)
		{
			soldier = arr[i];
			count = 1;
		}
	}

	count = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == soldier)
			++count;
	}

	return count > arr.size() / 2 ? soldier : 0;
}
void test_offer28()
{
	vector<int> arr = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << MoreThanHalfNum(arr) << endl;
}

//��ָoffer��29������n���������ҳ�������С��k����
#include<queue>
vector<int> GetLeastNumbers(vector<int> input, int k)
{
	if (input.size() < k || k <= 0)return vector<int>();//�ر�ע��k��ȡֵ

	priority_queue<int/*,less<int>*/> pq;//����С��ǰk������������� (���� less ˫��)
	for (int i = 0; i < input.size(); ++i)
	{
		if (i < k)
			pq.push(input[i]);
		else if (pq.top() > input[i])
		{
			pq.pop();
			pq.push(input[i]);
		}
	}
	vector<int> arr(k); int index = k - 1;
	while (!pq.empty())
	{
		arr[index--] = pq.top();
		pq.pop();
	}
	return arr;
}
void test_offer29()
{
	vector<int> arr = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int> tmp = GetLeastNumbers(arr, 4);
	for (auto&r : tmp)cout << r << " ";
	cout << endl;
}

//��ָoffer��30������һ�����飬�������������������Ƕ��١�ps,�����鳤������Ϊ1.
int FindGreatestSumOfSubArray(vector<int> arr)
{
	int max = arr[0], val = arr[0];
	for (size_t i = 1; i < arr.size(); ++i)
	{
		val = val < 0 ? 0 : val;//ȷ��val�Ǳ���ԭֵ��������
		val += arr[i];
		if (val > max)max = val;//max����ԭ����[0,i]��Χ�ڵ����������Ӻ�
	}
	return max;
}
void test_offer30()
{
	vector<int> arr = { 6, -3, -2, 7, -15, 1, 2, 2 };
	cout << FindGreatestSumOfSubArray(arr) << endl;
}

//��ָoffer��31�����1������Ǹ�����������1���ֵĴ�����eg.[1,13]������5�Σ�[1,15]������8��
// �������Ӹ�λ���������ÿһλ����1�ĸ���
int NumberOf1Between1AndN_Solution1(size_t n)
{
	int count = 0;
	for (size_t i = 1; i <= n; i *= 10)
	{
		int high = n / i, low = n % i;
		count += (high + 8) / 10 * i + (high % 10 == 1)*(low + 1);
	}
	return count;
}
int NumberOf1Between1AndN_Solution(size_t n)
{
	int count = 0, i = 1;
	int before = 0, current = 0, after = 0;

	while (n / i != 0)
	{
		before = n / (i * 10);//��λ����
		current = (n / i) % 10;//��ǰ����
		after = n - n / i * i;//��λ����

		if (current == 0)//���Ϊ0������1�Ĵ����ɸ�λ���������ڸ�λ����*��ǰλ��
			count += before * i;
		else if (current == 1)//���Ϊ1������1�Ĵ����ɸ�λ�͵�λ���������ڸ�λ����*��ǰλ��+��λ����+1
			count += before * i + after + 1;
		else//�������1������1�Ĵ����ɸ�λ����������(��λ����+1)*��ǰλ��
			count += (before + 1) * i;

		i *= 10;
	}
	return count;
}
void test_offer31()
{
	cout << NumberOf1Between1AndN_Solution1(21305) << endl;
	cout << NumberOf1Between1AndN_Solution(21305) << endl;
}

//��ָoffer��32������һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ��
//                eg.{3,31,322},ƴ�ӳ�������С����Ϊ313223
string Myitoa(size_t n)
{
	string str;
	while (n)
	{
		str += n % 10 + '0';
		n /= 10;
	}
	int begin = 0, end = str.size() - 1;
	while (begin < end)
		swap(str[begin++], str[end--]);
	return str;
}
struct myclass {
	bool operator() (string i, string j)
	{
		return (i + j < j + i);//if i+j<j+i,��ôi��jС
	}
} myobject;
string PrintMinNumber(vector<size_t> numbers)
{
	if (numbers.empty())return string();
	//�Ƚ�����ת��Ϊstring����
	vector<string> ArrStr(numbers.size());
	for (size_t i = 0; i < numbers.size(); ++i)
		ArrStr[i] = Myitoa(numbers[i]);
	//���Ʒº�������sort��������
	sort(ArrStr.begin(), ArrStr.end(), myobject);
	for (size_t i = 1; i < ArrStr.size(); ++i)
		ArrStr[0] += ArrStr[i];
	return ArrStr[0];
}
void test_offer32()
{
	vector<size_t> numbers = { 3, 31, 322 };
	cout << PrintMinNumber(numbers) << endl;
}

//��ָoffer��33����ֻ��������2,3��5������������������6,8���ǳ�������14���ǣ���Ϊ������������7.���ǰ�1������
//               ��һ���������󰴴�С�����˳��ĵ�N������
// ����������һ����N����������������������·ʽ��Ѱ�ң�
int GetUglyNumber(int index)
{//1 2 3 4 5 6 8 9 10 12 15 16 18 20 24 25 27 30...
	if (index < 7)return index;

	vector<int> res(index); res[0] = 1;
	int t2 = 0, t3 = 0, t5 = 0;
	for (int i = 1; i < index; ++i)
	{
		res[i] = min(min(res[t2] * 2, res[t3] * 3), res[t5] * 5);
		if (res[i] == res[t2] * 2)++t2;
		if (res[i] == res[t3] * 3)++t3;
		if (res[i] == res[t5] * 5)++t5;
	}
	return res[index - 1];
}
void test_offer33()
{
	cout << GetUglyNumber(15) << endl;
	//for (size_t i = 1; i < 20; ++i)
	//{
	//	cout << GetUglyNumber(i) << " ";
	//}cout << endl;
}

//��ָoffer��34����һ��ֻ������ĸ���ַ������ҵ���һ��ֻ����һ�ε��ַ�������������λ��
#include<map>
int FirstNotRepeatingChar(string str)
{
	map<char, int> mp;
	for (size_t i = 0; i < str.size(); ++i)
		++mp[str[i]];//ͳ�ƴ���

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (mp[str[i]] == 1)
			return i;
	}
	return -1;
}
void test_offer34()
{
	string str = "";
	cout << FirstNotRepeatingChar(str) << endl;
}

//��ָoffer��35���������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬
//               �����������е�����Ե�����P������P��1000000007ȡģ�Ľ�������
//����һ��������ⷨ     ����������[start,end]����ֳ�����С�����[start,mid]�͢�[mid+1,end],����������С���鶼��
//                               ����ģ�������ָ��i,j�ֱ�ָ�����������ĩβ���Ӻ��濪ʼ��ǰ��Ƚϣ����iָ���
//                               ������Ԫ�ش���jָ��Ģ�����Ԫ�أ���ôiָ���Ԫ�ظ�[mid+1,j]����������ԣ�
int InversePairCore(vector<int> &data, vector<int> &copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}
	int mid = start + (end - start) / 2;
	long long left = InversePairCore(copy,data, start, mid);
	long long right = InversePairCore(copy,data, mid + 1, end);

	int i = mid, j = end, index_copy = end;
	long long count = 0;
	while (i >= start && j >= mid + 1)
	{
		if (data[i] > data[j])
		{
			copy[index_copy--] = data[i--];
			count += j - mid;
		}
		else
			copy[index_copy--] = data[j--];
	}
	for (; i >= start; --i)
		copy[index_copy--] = data[i];
	for (; j >= mid + 1; --j)
		copy[index_copy--] = data[j];

	return (left + right + count) % 1000000007;
}
int InversePairs(vector<int> data)
{
	if (data.size() <= 0)return 0;

	vector<int> copy(data.size());//��������
	for (size_t i = 0; i < data.size(); ++i)
		copy[i] = data[i];

	long long count = InversePairCore(data, copy, 0, data.size() - 1);

	return count % 1000000007;
}
void test_offer35()
{
	vector<int> numbers = { 7, 5, 6, 4 };
	cout << InversePairs(numbers) << endl;
}

//��ָoffer��36���������������ҵ����ǵĵ�һ�������㡣
//   ������Ŀ�ᵽ����������������������һ����ţ�ƵĴ���
FlistNode * FindFirstCommonNode2(FlistNode *head1, FlistNode *head2)
{
	FlistNode *p1 = head1, *p2 = head2;
	while (p1 != p2)
	{
		p1 = p1 == NULL ? head2 : p1->next;
		p2 = p2 == NULL ? head1 : p2->next;
	}
	return p1;
}
// ����Ĵ����ܴ������е����
bool IsCycle(FlistNode *head)
{
	FlistNode *fast = head, *slow = head;
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast)fast = fast->next;

		if (fast == slow)return true;
	}
	return false;
}
FlistNode* FindEnterNode(FlistNode *head)
{
	FlistNode *fast = head, *slow = head;
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast)fast = fast->next;

		if (fast == slow)break;
	}

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
FlistNode *FindCommonNode(FlistNode* pHead1, FlistNode* pHead2, FlistNode *end)
{
	int count1 = 0, count2 = 0;
	FlistNode *cur1 = pHead1, *cur2 = pHead2;//������cur1����ָ�򳤵������ȼ���pHead1�Ƚϳ�
	while (cur1 != end){ count1++; cur1 = cur1->next; }
	while (cur2 != end){ count2++; cur2 = cur2->next; }

	if (count1 < count2){ cur1 = pHead2; cur2 = pHead1; }
	else{ cur1 = pHead1; cur2 = pHead2; }

	for (int i = 0; i < abs(count1 - count2); ++i)//��cur1���߼���
		cur1 = cur1->next;

	while (cur1 != end){
		if (cur1 == cur2)return cur1;

		cur1 = cur1->next; cur2 = cur2->next;
	}
	return NULL;
}
FlistNode* FindFirstCommonNode(FlistNode* pHead1, FlistNode* pHead2) {
	if (!pHead1 || !pHead2)return NULL;//�п�

	bool flag1 = IsCycle(pHead1);
	bool flag2 = IsCycle(pHead2);

	if ((flag1 == true && flag2 == false) || (flag1 == false && flag2 == true))//����һ������������һ��������
		return NULL;
	else if (flag1 == false && flag2 == false)//������������
	{
		return FindCommonNode(pHead1, pHead2, NULL);
	}
	else//����������
	{
		//1.���������ཻ  2.�������ڻ����ཻ  3.�������ڻ����ཻ
		FlistNode *enter1 = FindEnterNode(pHead1);
		FlistNode *enter2 = FindEnterNode(pHead2);

		if (enter1 == enter2)//���2
		{
			return FindCommonNode(pHead1, pHead2, enter1->next);
		}
		else//���1�����3
		{
			FlistNode *tmp = enter1->next;
			while (tmp != enter2)//̽���ǲ������3
			{
				if (tmp == enter1)return NULL;//˵�������1
				tmp = tmp->next;
			}
			//���ߵ����˵���������3
			return enter1;//����return enter2;
		}
	}
}

//��ָoffer��37��ͳ��һ�����������������г��ֵĴ���
int GetNumberOfK(vector<int> data, int k)
{
	int begin = 0, end = data.size() - 1;
	while (begin < end)//�ҵ�����ߵ�4
	{
		int mid = begin + (end - begin) / 2;
		if (data[mid] < k)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	int left = (end < 0 || data[end] < k) ? end + 1 : end;

	begin = 0, end = data.size() - 1;
	while (begin < end)//�ҵ����ұߵ�4
	{
		int mid = begin + (end - begin) / 2;
		if (data[mid] <= k)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	int right = (begin == data.size() || data[begin] > k) ? begin - 1 : begin;

	return right - left + 1;
}
void test_offer37()
{
	vector<int> numbers = { 1, 2, 3, 4, 4, 4, 5, 6, 7 };
	cout << GetNumberOfK(numbers, 4) << endl;
}

//��ָoffer��38������һ����������������
int TreeDepth(TreeNode *root)
{
	if (!root)return 0;

	int LeftDepth = TreeDepth(root->left);
	int RightDepth = TreeDepth(root->right);

	return LeftDepth >= RightDepth ? LeftDepth + 1 : RightDepth + 1;
}
void test_offer38()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	head4->left = head3; head4->right = head6;//��
	head3->left = head1;//������
	head1->right = head2;
	head6->left = head5; head6->right = head8;//������
	head8->left = head7;

	cout << TreeDepth(head6) << endl;
}

//��ָoffer��39������һ�������жϸö������Ƿ���ƽ���� (ע�⣬ƽ��������ƽ��������)
int _IsBalancedTree(TreeNode *root,bool &flag)
{
	if (!root)return 0;
	int left = 0, right = 0;
	if(flag) left = _IsBalancedTree(root->left,flag);
	if(flag) right = _IsBalancedTree(root->right,flag);

	if (abs(left - right) > 1)flag = false;
	return left >= right ? left + 1 : right + 1;
}
bool IsBalancedTree(TreeNode *root)
{
	bool flag = true;
	_IsBalancedTree(root, flag);

	return flag;
}
void test_offer39()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	head4->left = head3; head4->right = head6;//��
	head3->left = head1;//������
	head1->right = head2;
	head6->left = head5; head6->right = head8;//������
	head8->left = head7;

	cout << IsBalancedTree(head6) << endl;
}

//��ָoffer��40��һ���������������������֮�⣬�����Ķ����������Ρ����ҳ�������ֻ����һ�ε���
void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
{
	if (data.size() < 2){ num1 = num2 = NULL; return; }

	int tmp = data[0];
	for (size_t i = 1; i < data.size(); ++i)
		tmp ^= data[i];

	//��������ֻ����һ�ε�����ΪX��Y,ѭ��������tmp = X ^ Y������������tmp��������ֳ�����
	int tmp_index = 1;
	while ((tmp & tmp_index) == 0)
		tmp_index <<= 1;//ѭ��������̽�⵽X��Y��ͬ���Ǹ�������λ

	vector<int> help(data.size());
	int begin = 0, end = help.size() - 1;
	for (size_t i = 0; i < data.size(); ++i)//��ʼ���з���
	{
		if (data[i] & tmp_index)//����1�ķ��ں���
			help[end--] = data[i];
		else
			help[begin++] = data[i];//������1�ķ���ǰ��
	}

	*num1 = 0; *num2 = 0;//ע�⣬��������ʼ��Ϊ��
	for (size_t i = 0; i < begin; ++i)
		*num1 ^= help[i];
	for (size_t i = begin; i < help.size(); ++i)
		*num2 ^= help[i];
}
void test_offer40()
{
	vector<int> nums = { 1, 1, 9, 9, 6, 6, 33, 35, 35, 87, 87, 64, 64, 5, 5, 23, 14, 14 };
	int num1, num2;

	FindNumsAppearOnce(nums, &num1, &num2);
	cout << num1 << " " << num2 << endl;
}

//��ָoffer��41�������ҳ����к�ΪS�������������С�eg.S=100��9~16��18~22...
//       ����һ��˫ָ�����⣬���ܺ�С��sum����ָ��++������Сָ��++��
//       ��������(start+end)*(end-start+1)/2=sum��start<sqrt(2*sum),ͨ�����Ԫһ�η������һ��������end
vector<vector<int>> FindContinuesSequence1(int sum)
{
	vector<vector<int>> AllRes;
	int phigh = 2, plow = 1;
	while (phigh > plow)
	{
		int cur = (phigh + plow)*(phigh - plow + 1) / 2;
		if (cur < sum)phigh++;
		else if (cur > sum)plow++;
		else
		{
			vector<int> res;
			for (int i = plow; i <= phigh; ++i)
				res.push_back(i);
			AllRes.push_back(res);

			plow++;
		}
	}
	return AllRes;
}
vector<vector<int>> FindContinuesSequence2(int sum)
{
	vector<vector<int>> AllRes;
	size_t end, Range = (sum + 1) / 2;
	for (size_t start = 1; start < Range; ++start)
	{
		int c = start - start * start - 2 * sum;
		float endf = (sqrt(1 - 4 * c) - 1) / 2;
		
		end = endf;
		if (end == endf)
		{
			vector<int> res;
			for (size_t i = start; i <= end; ++i)
				res.push_back(i);
			AllRes.push_back(res);
		}
	}
	return AllRes;
}
void test_offer41()
{
	int sum = 99;
	vector<vector<int>> AllRes = FindContinuesSequence1(sum);
	for (size_t i = 0; i < AllRes.size(); ++i)
	{
		for (size_t j = 0; j < AllRes[i].size(); ++j)
			cout << AllRes[i][j] << " ";
		cout << endl;
	}cout << endl;
	AllRes = FindContinuesSequence2(sum);
	for (size_t i = 0; i < AllRes.size(); ++i)
	{
		for (size_t j = 0; j < AllRes[i].size(); ++j)
			cout << AllRes[i][j] << " ";
		cout << endl;
	}
}

//��ָoffer��42������һ����������������һ������S,�������в��������������ǵĺ�������S,����ж�����ֵĺ͵���
//               S������������ĳ˻���С���Ƕ�����
//     ��������ͷβ����ָ��i��j,if a[i]+a[j]==sum,���Ǵ𰸣�if a[i]+a[j]>sum,--j;if a[i]+a[j]<sum,++i;
vector<int> FindNumbersWithSum(const vector<int> &arr, int sum)
{
	int start = 0, end = arr.size() - 1;
	vector<int> res;
	while (start < end)
	{
		if (arr[start] + arr[end] == sum)
		{
			res.push_back(arr[start]);
			res.push_back(arr[end]);
			break;
		}
		else if (arr[start] + arr[end] > sum)
			--end;
		else
			++start;
	}
	return res;
}
void test_offer42()
{
	int n = 100;
	vector<int> num(n);
	for (int i = 0; i < n; ++i)
		num[i] = i;

	vector<int> res = FindNumbersWithSum(num, 190);
	for (auto &r : res)cout << r << " ";
	cout << endl;
}

//��ָoffer��43������һ���������ַ�����S�������ѭ������Kλ����������
string LeftRotateString(string str, int n)
{
	if (str.empty() || n <= 0)return str;

	n %= str.size();//��n����ʵ���С
	//string tmp(str.begin(), str.begin() + n);
	//size_t tmp_index = 0, len = str.size();
	//for (size_t i = 0; i < len; ++i)
	//{
	//	if (i < len - n)
	//		str[i] = str[i + n];
	//	else
	//		str[i] = tmp[tmp_index++];
	//}
	string tmp = str.substr(0, n);
	str.erase(0, n);
	str += tmp;

	return str;
}
void test_offer43()
{
	string str = "abcXYZdef";
	cout << LeftRotateString(str, 3) << endl;
}

//��ָoffer��44����һ���ַ�����ת��eg. "student. a am i"����ת֮����"i am a student."
string ReverseSentence(string str)
{
	int flag = 0,start = 0, end = str.size() - 1;
	while (start < end)//�����巭ת
		swap(str[start++], str[end--]);

	while (flag < str.size())
	{
		while (str[flag] == ' ')++flag;//��ֹ��һ���ַ����ǿո�
		start = flag;
		while (flag < str.size() && str[flag] != ' ')++flag;
		end = flag - 1;

		while (start < end)swap(str[start++], str[end--]);//����һ�����ʵ�˳��
	}
	return str;
}
void test_offer44()
{
	string str = " student. a am   i ";
	cout << ReverseSentence(str) << endl;
}

//��ָoffer��45�����˿������������������ƣ��ж��ǲ���˳�ӣ������������ǲ��������ġ�(ע��,2-10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13����С�����Կ�����������)
bool IsContinuous(vector<int> numbers)
{
	if (numbers.size() != 5)return false;

	sort(numbers.begin(), numbers.end());
	int zero_cnt = 0, gap = 0;
	for (size_t i = 0; i < numbers.size() - 1; ++i)
	{
		if (numbers[i] == 0)
			++zero_cnt;
		else
		{
			gap += numbers[i + 1] - numbers[i] - 1;
			if (numbers[i] == numbers[i + 1])
				return false;
		}

	}

	return zero_cnt >= gap ? true: false;
}
void test_offer45()
{
	vector<int> numbers = { 5, 3, 0, 4, 7 };
	cout << IsContinuous(numbers) << endl;
}

//��ָoffer��46��0��1��2��3��...n-1��n������Χ��һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֡������ʣ�µ�һ������
// ţƤ�������������ָoffer���ڶ���page302
int LastRemaining(int n, int m)
{
	if (n <= 0 || m <= 0)return -1;

	int s = 0;
	for (int i = 2; i <= n; ++i)
		s = (s + m) % i;
	return s;
}

//��ָoffer��47����1+2+3...+n,Ҫ�����ó˳�����for,while,if,else,swith,case�ȹؼ��ּ��ж����(A?B:C)
//      �������ݹ�
int Sum_Solution(int n)
{
	//if (n == 1)return 1;
	//return Sum_Solution(n - 1) + n;
	int sum = pow(n, 2) + n;
	return sum >> 1;
}
void test_offer47()
{
	cout << Sum_Solution(10) << endl;
}

//��ָoffer��48��дһ������ ��������֮�ͣ�Ҫ���ں������ڲ���ʹ��+,-,*,/�������㡣
//����һ����    ���������������ָoffer���ڶ���page311
int Add(int num1, int num2)
{
	int sum_index,sum = num1 | num2;
	num1 &= num2;
	for (size_t i = 0; i < sizeof(num1) * 8; ++i)
	{
		if (num1 & 1 << i)
		{
			sum_index = i;
			while (sum_index < sizeof(num1)* 8 && (sum & 1 << sum_index))
			{
				sum &= ~(1 << sum_index);
				++sum_index;
			}
			sum |= (sum_index < sizeof(num1)* 8) ? 1 << sum_index : 0;
			//sum |= 1 << sum_index;����
		}
	}
	return sum;
}
int Add2(int num1, int num2)
{
	while (num2 != 0)
	{
		int tmp = num1 ^ num2;//�������
		num2 = (num1 & num2) << 1;//���λֵ
		num1 = tmp;
	}
	return num1;
}
void test_offer48()
{
	// -1 2   -2 -8
	int num1 = -1, num2 = 2;
	cout << Add(num1, num2) << endl;
	cout << Add2(num1, num2) << endl;
}

//��ָoffer��49����һ���ַ���ת����һ��������Ҫ�����ÿ⺯������ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
int StrToInt(string str)
{
	int sum = 0, flag = 1, index = 0;
	while (index < str.size() && str[index] == ' ')++index;//ȥ��������Ŀո�
	if (index < str.size() && (str[index] == '-' || str[index] == '+'))//�жϸ������ķ���
	{
		flag = (str[index] == '-') ? -1 : 1;
		++index;
	}
	while (index < str.size())
	{
		if (!isdigit(str[index])){ sum = 0; break; }//�����Ϸ��ַ�

		sum = sum * 10 + str[index] - '0';
		++index;
	}
	return flag*sum;
}
void test_offer49()
{
	string str = "      -456 98";
	cout << StrToInt(str) << endl;
}

//��ָoffer��50����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ����ʱ�ظ��ģ�����֪���м���
//               �������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ�������
//����һ��map<k,v>��hashtable  �����������������������ñ�־����һ�����ַ��ʹ��󣬿������ö�Ӧλ�ϵ�����+n,֮����������ͬ�������ᷢ�ֶ�Ӧλ�ϵ�������n��ֱ�ӷ��ظ�������
int Find_dup(int numbers[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		int index = numbers[i];
		if (index >= length)index -= length;
		if (numbers[index] >= length)return index;
		numbers[index] += length;
	}
	return -1;
}
void test_offer50()
{
	int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
	cout << Find_dup(numbers, sizeof(numbers) / sizeof(numbers[0])) << endl;
}

//��ָoffer��51������һ������A[0,1,2,...,n-1],�빹��һ��B[0,1,2,...,n-1],����B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
//               ע�ⲻ���ó���
vector<int> multiply1(const vector<int> &A)
{
	const int len = A.size();
	vector<int> left(len); left[0] = A[0];
	vector<int> right(len); right[len - 1] = A[len - 1];
	for (int i = 1; i < len; ++i)
		left[i] = left[i - 1] * A[i];
	for (int i = len - 2; i >= 0; --i)
		right[i] = right[i + 1] * A[i];

	vector<int> B(len);
	for (int i = 0; i < len; ++i)
	{
		if (i == 0){ B[i] = right[i + 1]; continue; }
		if (i == len - 1){ B[i] = left[i - 1]; continue; }

		B[i] = left[i - 1] * right[i + 1];
	}
	return B;
}
void test_offer51()
{
	vector<int> A = { 1, 2, 3, 4, 5 };
	vector<int> B = multiply1(A);
	for (auto &r : B)cout << r << " "; cout << endl;
}

//��ָoffer��52����ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��
//               ǰ����ַ����Գ��������(����0��)
// �㷨˼�룺��ģʽ�еĵڶ����ַ�����"*"ʱ:����ַ�����ģʽ�еĵ�һ���ַ���ƥ�䣬��ô���Ƕ������1���ַ���
//                                           Ȼ��ƥ��ʣ��ģ�����ֱ�ӷ���false
//           ��ģʽ�еĵڶ����ַ���"*"ʱ:����ַ�����ģʽ�еĵ�һ���ַ���ƥ�䣬��ģʽ�����2���ַ�������������
//                                       ƥ�䷽ʽ��ģʽ����2���ַ����൱�ں���"X*"
//                                               ���ַ�������1���ַ���ģʽ����2���ַ�
//                                               ���ַ�������1���ַ���ģʽ���䣬��Ϊ"*"ǰ���Ǹ��ַ�����ƥ����
bool _match(char str[], int s_index, char pattern[], int p_index)
{
	int s_len = strlen(str), p_len = strlen(pattern);

	//if (s_index == s_len && p_index == p_len)return true;//�����ַ�����Ϊ��ʱ������true���������������������߼���ɾ��
	if (s_index < s_len && p_index == p_len)return false;//str��Ϊ����patternΪ��ʱ������false
	if (s_index == s_len && p_index < p_len)//strΪ����pattern��Ϊ��ʱ
	{
		while (p_index + 1 < p_len && pattern[p_index + 1] == '*')p_index += 2;
		if (pattern[p_index] == '*')++p_index;
	}

	while (s_index < s_len && p_index < p_len)//�����ַ�������Ϊ��ʱ
	{
		if (str[s_index] != '.' && pattern[p_index] != '.' && str[s_index] != pattern[p_index])//��ƥ��
		{
			if (p_index + 1 < p_len && pattern[p_index + 1] != '*')
				return false;
			else
				p_index += 2;
		}
		else//ƥ��
		{
			if (p_index + 1 < p_len && pattern[p_index + 1] != '*')
			{
				return _match(str, s_index + 1, pattern, p_index + 1);
			}
			else if (p_index + 1 == p_len)
			{
				++s_index; ++p_index;
			}
			else
			{
				//��ģʽ����2���ַ����൱��X*������
				//���ַ�������1���ַ���ģʽ����2���ַ�
				//���ַ�������1���ַ���ģʽ������
				return _match(str, s_index, pattern, p_index + 2)
					|| _match(str, s_index + 1, pattern, p_index + 2)
					|| _match(str, s_index + 1, pattern, p_index);
			}
		}
	}
	//�����ַ���һ�𵽴�\0ʱ������ƥ��ɹ�
	return (p_index != p_len || s_index != s_len) ? false : true;
}
bool match(char str[],char pattern[])
{
	return _match(str, 0, pattern, 0);//���±���Ʊ߽�ȽϺ�һЩ
}
void test_offer52()
{//""��"."  ""��"*"  "a"��"*" "a"��".*"  "a"��"."  "aa"��"aa"  "a"��"a." "a"��"ab*"  "aa"��"."
	char str[] = "aa";
	char pattern[] = ".";
	cout << match(str, pattern) << endl;
}

//��ָoffer��53����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ
bool IsNumberic(char *str)//"  +/ /-xxx.xxxE/exxx"
{
	if (!str)return false;

	int index = 0, len = strlen(str),dot_cnt = 0;
	while (index < len && str[index] == ' ')++index;// �����ո�
	if (index == len)return false;
	if (str[index] == '+' || str[index] == '-')++index;// ��������λ,������һ�䣬�����ⲻ��Ҫ�п�
	if (index == len)return false;

	for (; index < len && str[index] != 'e' && str[index] != 'E'; ++index)// ����E/eǰ����ַ�
	{
		if (str[index] == '.')
		{ 
			++dot_cnt; 
			if (dot_cnt == 2)return false;
			continue; 
		}
		if (!isdigit(str[index]))return false;
	}
	//���ߵ��⣬Ҫôstr[index]=='e/E'��Ҫôindex==len
	bool flag = false;
	if (index < len && (str[index] == 'e' || str[index] == 'E'))// ����e/E������ַ���ע�⣬e/E����ֻ������������������
	{
		++index;//����e/E
		if (str[index] == '+' || str[index] == '-')++index;// ��������λ
		for (; index < len; ++index)// ������ʼ����e/E������ַ�
			if (!isdigit(str[index]))return false;
		return flag;
	}
	return true;//��ƽ���ߵ��⣬˵�����ַ������ܱ�ʾһ����ֵ
}
void test_offer53()
{
	cout << IsNumberic("  +.2e2") << endl;
}

//��ָoffer��54����ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���eg.�����ַ�����ֻ����ǰ�����ַ�"go"ʱ��
//               ��һ��ֻ����һ�ε��ַ���'g'�����Ӹ��ַ����ֶ���ǰ�����ַ�"google"ʱ����һ��ֻ����һ�ε��ַ���'l'
// ����һ��arr[256]���ϣ��  ��������map<K,V>
class FirstAppearingOnceString
{
public:
	void Insert(char ch)//Insert one char from stringstream
	{
		str += ch;
		++mp[ch];
	}
	char FirstAppearingOnce()//return the first appearence once char in current stringstream
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (mp[str[i]] == 1)
				return str[i];
		}
		return '#';
	}
private:
	string str;
	map<char, size_t> mp;
};
void test_offer54()
{
	FirstAppearingOnceString s;
	string ch = "google";
	for (size_t i = 0; i < ch.size(); ++i)
	{
		s.Insert(ch[i]);
		cout << s.FirstAppearingOnce() << " ";
	}cout << endl;
}

//��ָoffer��55��һ���������а����������ҳ�������Ļ�����ڽ�㣨�����������˲������ĵ�����
FlistNode *EntryNodeOfLoop(FlistNode *pHead)
{
	FlistNode *fast = pHead, *slow = pHead;
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast)fast = fast->next;

		if (fast == slow)break;
	}

	slow = pHead;
	while (fast && slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

//��ָoffer��56����һ������������У������ظ��Ľ�㣬��ɾ���������е��ظ���㣬�ظ��Ľ�㲻��������������ͷָ��
//                eg.����:1->2->3->3->4->4->5   ���:1->2->5
FlistNode* _deleteDuplication(FlistNode* pHead)
{
	FlistNode *prev = NULL, *cur = pHead, *next;
	bool flag = false;
	while (cur)
	{
		next = cur->next;
		if (next && cur->val == next->val)
		{
			flag = true;
			delete cur;
		}
		else if (flag == true)
		{
			flag = false;
			delete cur;
		}
		else
		{
			if (!prev)pHead = cur;
			if (prev)prev->next = cur;
			prev = cur;
		}
		cur = next;
	}
	if(prev)prev->next = NULL;//��������ѭ��prev�����һ��Ԫ�أ�������prev->next=NULL
	return prev ? pHead : NULL;
}
void test_offer56()
{
	FlistNode *head1 = new FlistNode(1);
	FlistNode *head2 = new FlistNode(1); head1->next = head2;
	FlistNode *head3 = new FlistNode(2); head2->next = head3;
	FlistNode *head4 = new FlistNode(3); head3->next = head4;
	FlistNode *head5 = new FlistNode(3); head4->next = head5;
	FlistNode *head6 = new FlistNode(4); head5->next = head6;
	FlistNode *head7 = new FlistNode(5); head6->next = head7;
	FlistNode *head8 = new FlistNode(5); head7->next = head8;
	//FlistNode *head9 = new FlistNode(5); head8->next = head9;


	head1 = _deleteDuplication(head1);
	FlistNode *cur = head1;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}cout << endl;
}

//��ָoffer��57������һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ����������
TreeThreeLinkNode *GetNextNode(TreeThreeLinkNode* pNode)
{
	if (!pNode)return NULL;
	//����Լ��Ǹ��׵����ӣ�����Ϊ���Ҹ��ף����Ҳ�Ϊ�վ���������������
	//����Լ��Ǹ��׵��Һ��ӣ�����Ϊ����үү�����Ҳ�Ϊ�վ���������������
	if (pNode->right)//�Ҳ�Ϊ��
	{
		TreeThreeLinkNode *pNode_right = pNode->right;
		while (pNode_right->left)pNode_right = pNode_right->left;
		return pNode_right;
	}
	else//��Ϊ��
	{
		TreeThreeLinkNode *parent = pNode->parent;
		//if (parent && parent->left == pNode)//����Լ��Ǹ��׵����ӣ�
		//	return parent;
		while (parent && pNode == parent->right)//����Լ��Ǹ��׵��Һ��ӣ�
		{
			pNode = parent;
			parent = parent->parent;
		}
		return parent;
	}
}
void test_offer57()
{
	TreeThreeLinkNode *head1 = new TreeThreeLinkNode(1);
	TreeThreeLinkNode *head2 = new TreeThreeLinkNode(2);
	TreeThreeLinkNode *head3 = new TreeThreeLinkNode(3);
	TreeThreeLinkNode *head4 = new TreeThreeLinkNode(4);
	TreeThreeLinkNode *head5 = new TreeThreeLinkNode(5);
	TreeThreeLinkNode *head6 = new TreeThreeLinkNode(6);
	TreeThreeLinkNode *head7 = new TreeThreeLinkNode(7);

	head1->left = head2; head2->parent = head1; head1->right = head3; head3->parent = head1;

	head2->left = head4; head4->parent = head2;
	head4->left = head5; head5->parent = head4; head4->right = head6; head6->parent = head4;

	head3->right = head7; head7->parent = head3;

	TreeThreeLinkNode *tmp = GetNextNode(head6);
	if (tmp)cout << tmp->val << endl;
}

//��ָoffer��58����ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�������ͬ�ģ�������Ϊ�ԳƵ�
bool _IsSymmetrical(TreeNode *pRoot1, TreeNode *pRoot2)
{
	if (!pRoot1 && !pRoot2)return true;//������Ϊ��ʱ����
	if (!pRoot1 || !pRoot2)return false;//����������һ��Ϊ��ʱ����
	//���������������Ϊ�յ����
	return pRoot1->val == pRoot2->val
		&& _IsSymmetrical(pRoot1->left, pRoot2->right)
		&& _IsSymmetrical(pRoot1->right, pRoot2->left);
}
bool IsSymmetrical(TreeNode *pRoot)
{
	return  _IsSymmetrical(pRoot, pRoot);
}

//��ָoffer��59����ʵ��һ����������֮���δ�ӡ������������һ�д������ҵ�˳���ӡ���ڶ��д��������ӡ�������д�������...�Դ�����
vector<vector<int>> Print(TreeNode *pRoot)
{
	vector<vector<int>> dst;

	stack<TreeNode*> odd;//������ջpop�������ż����ջ������ʱ���ȴ����Ӻ��Һ���
	stack<TreeNode*> even;//ż����ջpop�������������ջ������ʱ���ȴ��Һ��Ӻ�����
	if(pRoot)odd.push(pRoot);
	while (!odd.empty())
	{
		TreeNode *cur;

		vector<int> odd_res;
		while (!odd.empty())
		{
			cur = odd.top(); odd.pop();
			odd_res.push_back(cur->val);
			if (cur->left)even.push(cur->left);//�ȴ����Ӻ��Һ���
			if (cur->right)even.push(cur->right);
		}
		dst.push_back(odd_res);

		vector<int> even_res;
		while (!even.empty())
		{
			cur = even.top(); even.pop();
			even_res.push_back(cur->val);
			if (cur->right)odd.push(cur->right);//�ȴ��Һ��Ӻ�����
			if (cur->left)odd.push(cur->left);
		}
		if (!even_res.empty())dst.push_back(even_res);
	}
	return dst;
}
void test_offer59()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	TreeNode *head9 = new TreeNode(9);
	head1->left = head2; head1->right = head3;
	head2->left = head4; head2->right = head5;
	head3->left = head6; head3->right = head7;
	head4->right = head8; head6->right = head9;

	vector<vector<int>> tmp = Print(head1);
	for (size_t i = 0; i < tmp.size(); ++i)
	{
		for (size_t j = 0; j < tmp[i].size(); ++j)
		{
			cout << tmp[i][j] << " ";
		}cout << endl;
	}
}

//��ָoffer��60�����ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
vector<vector<int>> Print2(TreeNode *pRoot)
{
	vector<vector<int>> dst;
	queue<TreeNode*> odd;//����������popԪ��ʱ�������ȴ����Ӻ��Һ���
	queue<TreeNode*> even;//����ôŪ�������о���Ϊ�˷������������һ�㣩
	if (pRoot)odd.push(pRoot);
	while (!odd.empty())
	{
		TreeNode *cur;
		vector<int> odd_res;
		while (!odd.empty())
		{
			cur = odd.front(); odd.pop();
			odd_res.push_back(cur->val);
			if (cur->left)even.push(cur->left);
			if (cur->right)even.push(cur->right);
		}
		dst.push_back(odd_res);
		swap(odd, even);
	}
	return dst;
}
void test_offer60()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	TreeNode *head9 = new TreeNode(9);
	head1->left = head2; head1->right = head3;
	head2->left = head4; head2->right = head5;
	head3->left = head6; head3->right = head7;
	head4->right = head8; head6->right = head9;

	vector<vector<int>> tmp = Print2(head1);
	for (size_t i = 0; i < tmp.size(); ++i)
	{
		for (size_t j = 0; j < tmp[i].size(); ++j)
		{
			cout << tmp[i][j] << " ";
		}cout << endl;
	}
}

//��ָoffer��61����ʵ�������������ֱ��������л��ͷ����л�������
// ���л�:ʹ��ǰ��������ݹ�Ľ���������ֵת��Ϊ�ַ���������ÿ�ζ������Ľ�㲻Ϊ��ʱ����ת��val���õ��ַ�
//            ֮�����һ��������Ϊ�ָ���ڿս����'#'����
// �����л�:����ǰ��˳�򣬵ݹ��ʹ���ַ����е��ַ�����һ��������
void _Serialize(TreeNode *root,string &str)
{
	if (!root){ str += "#,"; return; }
	str += to_string(root->val);
	str += ',';
	_Serialize(root->left,str);
	_Serialize(root->right,str);
}
char *Serialize(TreeNode *root)
{
	string str;
	_Serialize(root, str);
	string* tmp = new string(str);
	return (char*)tmp->c_str();
}
TreeNode *_DeSerialize(char *&str)
{
	string s;
	while (*str != ',' && *str != '\0')s += *str++;
	++str;
	if (s[0] == '#')return NULL;

	TreeNode *root = new TreeNode(stoi(s));
	root->left = _DeSerialize( str);
	root->right = _DeSerialize(str);

	return root;
}
TreeNode *DeSerialize(char *str)
{
	return _DeSerialize(str);
}
void test_offer61()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(22);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(44);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(66);
	head1->left = head2; head1->right = head3;
	head2->left = head4; head4->right = head6;
	head3->left = head5;

	char *tmp = Serialize(head1);
	cout << tmp << endl;
	cout << strlen(tmp) << endl;

	TreeNode *tree = DeSerialize(tmp);
	cout << " " << endl;
}

//��ָoffer��62������һ�����������������ҳ����еĵ�kС�Ľ�㡣eg. 5 /\ 3 7 /\ /\ 2 4 6 8�У���3С������4
TreeNode* InOrder_KthNode(TreeNode *Proot, int &k)
{
	if (!Proot)return NULL;
	TreeNode *left = InOrder_KthNode(Proot->left, k);
	if (left)return left;
	--k;
	TreeNode *ret =  k == 0 ? Proot : NULL;
	if (ret)return ret;
	TreeNode *right = InOrder_KthNode(Proot->right, k);
    return right?right:NULL;
}
TreeNode *KthNode(TreeNode *Proot, int k)
{
	if (!Proot || k <= 0)return NULL;
	return InOrder_KthNode(Proot, k);
}
void test_offer62()
{
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head8 = new TreeNode(8);
	head5->left = head3; head5->right = head7;
	head3->left = head2; head3->right = head4;
	head7->left = head6; head7->right = head8;

	TreeNode *tmp = KthNode(head5, 55);
	if (tmp)
		cout << tmp->val << endl;
}

//��ָoffer��63����εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ��
//               �м����ֵ��������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ
//  ������ʹ�ô��+С�ѵ��������������е����ݸ���ֻ�����1��
#include<queue>
#include<functional>
class GetMedianNum
{ 
public:
	void Insert(int num)
	{
		//ʼ�ձ��ִ���ѵ�Ԫ��>=С���ѵģ��Ҳ�<=1.
		if (maxHeap.empty())
			maxHeap.push(num);
		else if (!maxHeap.empty() && num <= maxHeap.top())
			maxHeap.push(num);
		else
			minHeap.push(num);

		if (minHeap.size() > maxHeap.size())
		{
			int ret = minHeap.top();
			minHeap.pop();
			maxHeap.push(ret);
		}
		if (maxHeap.size() - minHeap.size() > 1)
		{
			int ret = maxHeap.top();
			maxHeap.pop();
			minHeap.push(ret);
		}
		++cnt;//��¼�ܹ������Ԫ�ظ���
	}
	double GetMedian()
	{
		if (cnt % 2 == 1)
			return maxHeap.top();
		else
			return (double)(maxHeap.top() + minHeap.top()) / 2;
	}
private:
	int cnt = 0;//��¼�ܹ������Ԫ�ظ���
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>,greater<int>> minHeap;//��������
};
void test_offer63()
{
	GetMedianNum mid;
	int num[] = { 1, 2, 3, 4, 5, 6 ,-5,-7,0,10,52,43,7};
	for (size_t i = 0; i < sizeof(num) / sizeof(num[0]); ++i)
		mid.Insert(num[i]);
	cout << mid.GetMedian() << endl;
}

//��ָoffer��64������һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ
// ��������һ��˫�˶��У����е�һ��λ�ñ��浱ǰ���ڵ����ֵ�������ڻ���һ�Σ����жϵ�ǰ���ֵ�Ƿ���ڢ�������ֵ�Ӷ�β��ʼ�Ƚϣ��ѱ���С��ֵ����
#include<deque>
vector<int> MaxInWindows(const vector<int> &num, size_t size)
{
	vector<int> dst(num.size()); size_t dst_index = 0;
	deque<size_t> deq;
	for (size_t i = 0; i < num.size(); ++i)
	{
		if (!deq.empty() && i - deq.front() >= size)//���жϵ�ǰ���ֵ�Ƿ����
			deq.pop_front();
		while (!deq.empty() && num[i] >= num[deq.back()])//��������ֵ�Ӷ�β��ʼ�Ƚϣ��ѱ���С��ֵ����
			deq.pop_back();

		deq.push_back(i);
		dst[dst_index++] = num[deq.front()];
	}
	return dst;
}
vector<int> MaxInWindows2(const vector<int>& num, unsigned int size)
{
	if (num.empty() || size == 0)return vector<int>();//ȥ�����Ϸ����������

	vector<int> dst(num.size() - size + 1); size_t dst_index = 0;
	deque<size_t> deq; size_t i = 0;
	for (; i < size - 1 && i < num.size(); ++i)//����ǰsize����
	{
		if (!deq.empty() && i - deq.front() >= size)//���жϵ�ǰ���ֵ�Ƿ����
			deq.pop_front();
		while (!deq.empty() && num[i] >= num[deq.back()])//��������ֵ�Ӷ�β��ʼ�Ƚϣ��ѱ���С��ֵ����
			deq.pop_back();

		deq.push_back(i);
	}

	for (; i < num.size(); ++i)//�����±�Ϊsize��������Ԫ��
	{
		if (!deq.empty() && i - deq.front() >= size)//���жϵ�ǰ���ֵ�Ƿ����
			deq.pop_front();
		while (!deq.empty() && num[i] >= num[deq.back()])//��������ֵ�Ӷ�β��ʼ�Ƚϣ��ѱ���С��ֵ����
			deq.pop_back();

		deq.push_back(i);
		dst[dst_index++] = num[deq.front()];
	}
	return dst;
}
void test_offer64()
{
	vector<int> num = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int> dst1 = MaxInWindows(num, 3);//2 3 4 4 6 6 6 5
	vector<int> dst2 = MaxInWindows2(num, 3);// 4 4 6 6 6 5       OJ������������
	for (auto &r : dst2)cout << r << " "; cout << endl;
}

//��ָoffer��65�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ�����
//               ������һ�����ӿ�ʼ��ÿһ�������ھ����������������������ƶ�һ�����ӡ����һ��·�������˾�����
//               ��ĳһ�����ӣ����·�������ڽ���ø��ӡ�
bool _HasPath(char *matrix, int row, int cols, int index, char *str)
{
	if (*str == '\0')return true;
	if (index >= row*cols || matrix[index] != *str)return false;

	matrix[index] -= 32;
	bool flag = false;
	if (flag == false && (index + 1) % cols != 0)
		flag = _HasPath(matrix, row, cols, index + 1, str + 1);//��
	if (flag == false)
		flag = _HasPath(matrix, row, cols, index + cols, str + 1);//��
	if (flag == false && index%cols != 0)
		flag = _HasPath(matrix, row, cols, index - 1, str + 1);//��
	if (flag == false)
		flag = _HasPath(matrix, row, cols, index - cols, str + 1);//��
	matrix[index] += 32;
	return flag;
}
bool HasPath(char *matrix, int row, int cols, char *str)
{
	if (!matrix || row < 1 || cols < 1 || !str)
		return false;//��֤����Ĳ������ݶ��ǺϷ�ֵ

	bool flag = false;
	for (size_t i = 0; i < row*cols; ++i)
	{
		if (matrix[i] == *str)
			flag = _HasPath(matrix, row, cols, i, str);

		if (flag)break;
	}
	return flag;
}
void test_offer65()
{
	char matrix[] = "abcesfcsadee", *str ="bccseedfs"/* "bcced"*/;
	int row = 3, cols = 4;
	cout << HasPath(matrix, row, cols, str) << endl;
	cout << HasPath(matrix, row, cols, str) << endl;
}

//��ָoffer��66��������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������������ĸ������ƶ�
//               һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ��ʻ������ܹ��ﵽ���ٸ�����
//int NumSum(int i)
//{
//	int sum = 0;
//	while (i)
//	{
//		sum += i % 10;
//		i /= 10;
//	}
//	return sum;
//}
//
//int MovingCount(int threshold, int rows, int cols)
//{
//
//}

void test_offer()
{
	//test_offer1();
	//test_offer2();
	//test_offer3();
	//test_offer4();
	//test_offer5();
	//test_offer6();

	//test_offer7();
	//test_offer7_8_9_10();
	//test_offer11();
	//test_offer12();

	//test_offer13();
	//test_offer14();
	//test_offer15();
	//test_offer16();
	//test_offer17();
	//test_offer18();

	//test_offer19();
	//test20;
	//test_offer21();
	//test_offer22();
	//test_offer23();
	//test_offer24();

	//test_offer25();
	//test_offer26();
	//27                                ûд//�������
	//test_offer28();//
	//test_offer29();//topK����
	//test_offer30();//��̬�滮��

	//test_offer31();//ʮ����1�ĸ���
	//test_offer32();//A+B<B+A���ַ����Ƚ�
	//test_offer33();//����·ʽѰ��
	//test_offer34();//map<k,v>ģ��
	//test_offer35();//�鲢����˼��
	//test36*****

	//test_offer37();
	//test_offer38();
	//test_offer39();
	//test_offer40();
	//test_offer41();//˫ָ������
	//test_offer42();//˫ָ������

	//test_offer43();
	//test_offer44();
	//test_offer45();
	//test46Լɪ������
	//test_offer47();
	//test_offer48();

	//test_offer49();
	//test_offer50();
	//test_offer51();//ͬday13,��ͨ����������
	//test_offer52();//����ƥ�䣬��ͨ���������� **
	//test_offer53();
	//test_offer54();                                     //--------------------------------------

	//test55   �ܹ���������
	//test_offer56();//ͬday12 �ܹ�
	//test_offer57();//�ܹ�
	//test58   ****  �ܹ�
	//test_offer59(); //�ܹ�
	//test_offer60(); //�ܹ�

	//test_offer61();
	//test_offer62();
	//test_offer63();
	//test_offer64();
	test_offer65();
}