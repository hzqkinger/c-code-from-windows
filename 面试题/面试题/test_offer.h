#pragma once
#include"DefineNode.h"

//剑指offer题1：在一个二维数组中，每一行都按照从左往右递增的顺序排序，每一列都按照从上往下递增的顺序排序。
//完成一个函数，输入一个数，判断该数是否在数组中。（ps:可以从四个角开始查起，其中从左下角和右上角查起思路比较清晰）
//      思路一：从左下角来看，向上数字递减，向右数字递增，
//            因此，从左下角开始，当要查的数字比左下角数字大时，右移；否则上移
#include<vector>
bool Find(vector<vector<int>> arr, int target)
{
	int rowcount = arr.size();
	int colcount = arr[0].size();

	int i, j;
	for (i = rowcount - 1, j = 0; i >= 0 && j < colcount;)
	{
		if (target == arr[i][j])return true;

		if (target < arr[i][j])--i;//target小于array[i][j],上移
		else ++j;//否则右移
	}
	return false;
}
//     思路二：从左上角开始查找，先在第一行找到大于target的数，
//             然后，target比array[i][j]大时，下移；否则左移
bool Find2(vector < vector<int>> arr, int target)
{
	int rowcount = arr.size();
	int colcount = arr[0].size();

	int i = 0, j = 0;
	while (j < colcount - 1 && arr[i][j] <= target)++j;//第一行，从左往右，找到第一个大于target的数

	while (i < rowcount && j >= 0)
	{
		if (arr[i][j] == target)return true;

		if (arr[i][j] < target)//array[i][j]小于target，下移
			++i;
		else --j;//否则左移
	}
	return false;
}
void test_offer1()
{
	vector<vector<int>> _v = { { 1, 5, 9, 13 }, { 2, 7, 10, 14 }, { 3, 8, 13, 16 }, { 5, 10, 14, 17 }, { 19, 23, 26, 29 } };
	cout << Find(_v, 26) << endl;
	cout << Find2(_v, 26) << endl;
}

//剑指offer题2：实现一个函数，将一个字符串中的空格替换成"%20"。例如，当字符串We Are Happy经过变换之后变成We%20Are%20Happy
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
		if (str[i] == ' ')count++;//先计算出有多少空格
	}
	int size2 = size + 2 * count + 1;
	char *tmp = (char*)malloc(size2);//算出替换后的空间大小
	count = 0;//从下面开始，count做str的index.
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
{                                 //length表示str指向的空间的长度
	if (str == NULL && length <= 0)
		return;
	int increblankspace = 0;//记录空格的个数
	int orilen = 0;//记录原始字符串的个数
	for (int i = 0; str[i] != '\0'; i++) {
		++orilen;
		if (str[i] == ' ')
			++increblankspace;
	}
	int len = increblankspace * 2 + orilen;//记录替换后字符串的长度
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

//剑指offer题3：输入一个链表，从尾到头打印链表每个结点的值
//      思路一：递归       思路二：顺序遍历链表存入vector数组，
void PrintListFromTailtoHead(FlistNode *root)//递归
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

//剑指offfer题4：输入某二叉树的前序遍历和中序遍历的结果，重建该二叉树。
//    思路一：递归             思路二：非递归
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
	root = ReConstructBinaryTree(pre, vin);//递归方法             非递归方法没写
	cout << "由前序和中序重建" << endl;
}

//剑指offer题5：用两个栈来实现一个队列，完成队列的Pop和Push操作。注，元素为int类型
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

//剑指offer题6：把一个数组最开始的若干元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个
//              旋转，输出旋转数组的最小元素。eg.数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1.
//              (注，数组给出的所有元素都大于0，若数组大小为0，则返回0)
//     思路：从头开始遍历，若发现下一个数比当前要小，那么下一个数一定是最小的数
#include<vector>
int MinNumberInRotateArray(vector<int> arr)
{
	if (arr.empty())return 0;//数组大小为0时

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

//剑指offer题7：现在要求输入一个整数n，请求出斐波那契数列的第n项。（通项公式: f(n) = f(n-1) + f(n-2)）注意，f(0) = 0
//    思路一：迭代循环法      思路二：公式法       思路三：尾递归法(当递归调用是整个函数体中最后执行的语句，且它的返回值不属于表达式的一部分时，这个递归就是为递归)
int Fibonacci(size_t n)//循环迭代法  //0 1 1 2 3 5 8 13 21...
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
int Fibonacci2(size_t n)//公式法
{
	double x = pow((1 + sqrt(5)) / 2, n);
	double y = pow((1 - sqrt(5)) / 2, n);

	return 1 / sqrt(5) * (x - y);
}
int Fibonacci3(int n, int acc1 = 0, int acc2 = 1)//尾递归法
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

//剑指offer题8：一只青蛙一次可以跳上1级台阶，也可以跳上2阶台阶。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//         分析:如果想跳一次就跳上第n级台阶，那么青蛙上一次一定在第n-1或n-2级台阶上；f(n) = f(n-1) + f(n-2)  注意f(0) = 1
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

//剑指offer题9：一只青蛙一次可以跳上1级台阶，也可以跳上2阶台阶...也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//    如上分析得：f(n) = f(n-1)+f(n-2)+...+f(1);  注意f(0) = 1
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

//剑指offer题10：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
//               请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法
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

//剑指offer题11：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
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

//剑指offer题12：给定一个double类型的浮点数base和int类型的整数exponent，求base的exponent次方。
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

//剑指offer题13：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，是所有的奇数位于数组的前半部分，
//             所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//   方法一：用辅助数组         方法二：两个奇数指针包夹着偶数，然后把这些偶数向后推一步，再把后面的一个奇数放到前面；重复步骤直到结束
#include<vector>
void ReSortArray(vector<int> &v)
{
	vector<int> even_store;
	even_store.reserve(v.size());

	int oddp = 0, evenp = 0;
	while (evenp < v.size())
	{
		if (v[evenp] & 0x01)//是奇数就往源数组的前面挪
			v[oddp++] = v[evenp];
		else
			even_store.push_back(v[evenp]);//否则先存起来

		++evenp;
	}
	for (size_t i = 0; i < even_store.size(); ++i)//把存在辅助数组的偶数挪回来
		v[oddp++] = even_store[i];
}
void test_offer13()
{
	vector<int> v = { 0, 0, 0, 1, 2, 3, 4, 4, 4, 5, 6, 6, 7, 8, 9, 1 };
	ReSortArray(v);
	for (auto &r : v)cout << r << " ";
}

//剑指offer题14：输入一个链表，输出该链表中倒数第k个结点。
FlistNode *SingLinkList(FlistNode * head, size_t k)
{
	FlistNode *slow = head, *fast = head;

	int count = 0;//用来计算链表中到底有多少个结点
	while (fast){ ++count; fast = fast->next; }
	k %= count + 1;//ps，如果k的值大于count时，修正k的值是十分有必要的，

	fast = head;
	while (k--)fast = fast->next;//这里不用判断fast是否为空,因为前面修正了k的值

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

//剑指offer题15：输入一个单链表，反转链表后，输出链表的所有元素。
void ReverseSinglyLinkList(FlistNode *head)
{
	FlistNode *prev = NULL, *cur = head, *next = NULL;
	if (cur)next = cur->next;

	while (cur)//逆置单链表
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

//剑指offer题16：输入两个单调递增的单链表，输出合并后的链表，使之满足单调不减规则。
FlistNode *MergeTwoSinglyList(FlistNode *head1, FlistNode *head2)
{
	if (!head1)return head2;//head1为空，直接返回head2
	if (!head2)return head1;//同理

	FlistNode *sma = head1, *big = head2;
	if (sma->val > big->val){ swap(sma, big); head1 = sma; }

	while (sma && big)//由于上面的操作，small->_val一定小于big->_val；
	{
		FlistNode *next;

		while (sma->next && sma->next->val <= big->val)
			sma = sma->next;//找到合适的位置

		next = big->next;

		big->next = sma->next;
		sma->next = big;

		sma = sma->next;//且在循环中一直保证small->_val小于big->_val.
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

//剑指offer题17：输入两棵二叉树A,B,判断B是不是A的子结构(ps:约定空树不是任意一棵树的子结构)
bool HasSubtree(TreeNode *rootA,TreeNode *rootB)
{
	//刚进来的时候,rootA->_val一定等于rootB->_val
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
	head1->left = head2; head1->right = head3;//根
	head2->left = head4;//左子树
	head4->right = head7;
	head3->left = head5; head3->right = head6;//右子树
	head6->left = head8;

	TreeNode *cur1 = new TreeNode(2);
	TreeNode *cur2 = new TreeNode(5);
	TreeNode *cur3 = new TreeNode(6);
	cur1->left = cur2; cur1->right = cur3;

	cout << HasSubtree(head3, cur1) << endl;
	cout << IsSubtree(head1, cur1) << endl;
}

//剑指offer题18：操作给定的二叉树，将其变换为源二叉树的镜像
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
	head1->left = head2; head1->right = head3;//根
	head2->left = head4;//左子树
	head4->right = head7;
	head3->left = head5; head3->right = head6;//右子树
	head6->left = head8;

	MirrorBinaryTree(head1);
	cout << "hah" << endl;
}

//剑指offer题19：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，eg. 1  2  3  4
//                                                                                 5  6  7  8
//                                                                                 9  10 11 12
//                                                                                 13 14 15 16
//                                                       则依次打印出1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
#include<vector>
vector<int> PrintMaterix(vector<vector<int>> matrix)
{
	vector<int> v;

	int up = 0, down = matrix.size();
	int left = 0, right = matrix[0].size();

	while (up < down && left < right)//顺时针打印
	{
		int i = up, j = left - 1;
		while (++j < right)
			v.push_back(matrix[i][j]);//上横
		--j; if (up + 1 == down){ ++up; continue; }

		while (++i < down)
			v.push_back(matrix[i][j]);//右竖
		--i; if (right - 1 == left){ --right; continue; }

		while (--j >= left)
			v.push_back(matrix[i][j]);//下横
		++j;

		while (--i > up)
			v.push_back(matrix[i][j]);//左竖
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

//剑指offer题20：定义一个栈，使它实现一个min函数，min函数能再O(1)取出栈中最小的数据
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

//剑指offer题21：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序
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

//剑指offer题22：层序遍历一棵二叉树
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
	head1->left = head2; head1->right = head3;//根
	head2->left = head4;//左子树
	head4->right = head7;
	head3->left = head5; head3->right = head6;//右子树
	head6->left = head8;

	vector<int> tmp = PrintFromTopToBottom(head1);
	for (auto&r : tmp)cout << r << " "; cout << endl;
}

//剑指offer题23：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。(数组中任意两个数都不相同)
//  方法一：递归，对于二叉搜索树的后序遍历结果，去掉该数组中的最后一个数据（也就是根），那么数组分成两部分，
//                 前部分是左子树，后部分是右子树
//  方法二：非递归，基于递归思想写成非递归，O(n^2)
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

//剑指offer题24：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//              路径定义为数的根结点开始往下一直到叶节点所经过的结点形成一条路径
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

//剑指offer题25：复制一个随机链表
RondomListNode* RandomLinkCopy(RondomListNode *head)
{
	if (!head)return NULL;//头结点是空直接返回

	RondomListNode *cur = head, *next = head->next;//由①②③变成①①②②③③，但复制出来的结点的随机指针都指向空
	while (cur){
		RondomListNode *tmp = new RondomListNode(cur->val);
		cur->next = tmp; tmp->next = next;
		cur = next; if (next)next = next->next;
	}
	cur = head; next = cur->next;//将随机指针指向正确的位置
	while (cur){
		next->rand = cur->rand ? cur->rand->next : NULL;
		cur = next->next; if (cur)next = cur->next;
	}
	cur = head; next = cur->next;//将新旧链表分离开
	RondomListNode *tmp = next;
	while (cur){
		cur->next = next->next; cur = next->next;
		if (cur){ next->next = cur->next; next = cur->next; }
		else next->next = NULL;
	}
	return tmp;//返回复制出来的新链表的头结点
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

//剑指offer题26：输入一棵二叉搜索树，将该二叉树转换成一个排序的双向链表。要求不能创建新的结点，只能调整树中结点的指针
TreeNode *_TreeToLink(TreeNode *root)
{
	if (!root)return NULL;//递归返回条件

	TreeNode *left = _TreeToLink(root->left);//left是左边单链表的最左结点
	TreeNode *right = _TreeToLink(root->right);//right是右边单链表的最左结点

	TreeNode *left_to_right;//左边单链表的最右结点
	left_to_right = left ? left->left : NULL;
	TreeNode *right_to_right;//右边单链表的最右结点
	right_to_right = right ? right->left : NULL;

	root->left = left_to_right;//根的左孩子
	if (left_to_right)left_to_right->right = root;
	root->right = right;//根的右孩子
	if (right)right->left = root;

	if (!left)left = root;
	left->left = right ? right_to_right : root;

	return left;
}
TreeNode *TreeToLink(TreeNode *root)//递归思路
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
	head4->left = head3; head4->right = head6;//根
	head3->left = head1;//左子树
	head1->right = head2;
	head6->left = head5; head6->right = head8;//右子树
	head8->left = head7;

	TreeNode *head = TreeToLink(head4);
	TreeNode *cur = head;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->right;
	}cout << endl;
}

//剑指offer题27：输入一个字符串，按字典序打印出该字符串中字符的所有排列。

//剑指offer题28：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字,ps:如果不存在返回0.
//  方法一:排序    方法二:map<K,V>    方法三:阵地攻守思想，先让第一个元素作为第一个士兵来守阵地，count=1；
//                                       遇到相同的元素++count,否则--count;当count=0时，又以新的i值作为守阵地的士兵，
// 方法四：用堆找出一般元素,返回堆顶     直到最后的士兵，那即是所求元素
int MoreThanHalfNum(vector<int> arr)//方法三
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

//剑指offer题29：输入n个整数，找出其中最小的k个数
#include<queue>
vector<int> GetLeastNumbers(vector<int> input, int k)
{
	if (input.size() < k || k <= 0)return vector<int>();//特别注意k的取值

	priority_queue<int/*,less<int>*/> pq;//找最小的前k个数，建大根堆 (孩子 less 双亲)
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

//剑指offer题30：输入一个数组，求该数组的最大子数组和是多少。ps,该数组长度最少为1.
int FindGreatestSumOfSubArray(vector<int> arr)
{
	int max = arr[0], val = arr[0];
	for (size_t i = 1; i < arr.size(); ++i)
	{
		val = val < 0 ? 0 : val;//确定val是保留原值还是置零
		val += arr[i];
		if (val > max)max = val;//max代表原数组[0,i]范围内的最大子数组加和
	}
	return max;
}
void test_offer30()
{
	vector<int> arr = { 6, -3, -2, 7, -15, 1, 2, 2 };
	cout << FindGreatestSumOfSubArray(arr) << endl;
}

//剑指offer题31：求出1和任意非负整数区间中1出现的次数。eg.[1,13]出现了5次；[1,15]出现了8次
// 方法：从个位起，依次求解每一位出现1的个数
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
		before = n / (i * 10);//高位数字
		current = (n / i) % 10;//当前数字
		after = n - n / i * i;//低位数字

		if (current == 0)//如果为0，出现1的次数由高位决定，等于高位数字*当前位数
			count += before * i;
		else if (current == 1)//如果为1，出现1的次数由高位和低位决定，等于高位数字*当前位数+低位数字+1
			count += before * i + after + 1;
		else//如果大于1，出现1的次数由高位决定，等于(高位数字+1)*当前位数
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

//剑指offer题32：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
//                eg.{3,31,322},拼接出来的最小的数为313223
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
		return (i + j < j + i);//if i+j<j+i,那么i比j小
	}
} myobject;
string PrintMinNumber(vector<size_t> numbers)
{
	if (numbers.empty())return string();
	//先将整型转换为string类型
	vector<string> ArrStr(numbers.size());
	for (size_t i = 0; i < numbers.size(); ++i)
		ArrStr[i] = Myitoa(numbers[i]);
	//定制仿函数，用sort进行排序
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

//剑指offer题33：把只包含因子2,3和5的数称作丑数。例如6,8都是丑数，但14不是，因为它包含了因子7.我们把1当做是
//               第一个丑数。求按从小到大的顺序的第N个丑数
// 方法：将第一个至N个丑数都存起来，（铺马路式的寻找）
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

//剑指offer题34：在一个只包含字母的字符串中找到第一个只出现一次的字符，并返回它的位置
#include<map>
int FirstNotRepeatingChar(string str)
{
	map<char, int> mp;
	for (size_t i = 0; i < str.size(); ++i)
		++mp[str[i]];//统计次数

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

//剑指offer题35：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，
//               求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
//方法一：暴力求解法     方法二：把[start,end]数组分成两个小数组①[start,mid]和②[mid+1,end],假设这两个小数组都是
//                               升序的，设两个指针i,j分别指向两个数组的末尾，从后面开始往前面比较，如果i指向的
//                               ①数组元素大于j指向的②数组元素，那么i指向的元素跟[mid+1,j]都构成逆序对；
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

	vector<int> copy(data.size());//辅助数组
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

//剑指offer题36：输入两个链表，找到它们的第一个公共点。
//   假如题目提到这两个链表都不带环，看到一个很牛逼的代码
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
// 下面的代码能处理所有的情况
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
	FlistNode *cur1 = pHead1, *cur2 = pHead2;//在这里cur1总是指向长的链表，先假设pHead1比较长
	while (cur1 != end){ count1++; cur1 = cur1->next; }
	while (cur2 != end){ count2++; cur2 = cur2->next; }

	if (count1 < count2){ cur1 = pHead2; cur2 = pHead1; }
	else{ cur1 = pHead1; cur2 = pHead2; }

	for (int i = 0; i < abs(count1 - count2); ++i)//让cur1先走几步
		cur1 = cur1->next;

	while (cur1 != end){
		if (cur1 == cur2)return cur1;

		cur1 = cur1->next; cur2 = cur2->next;
	}
	return NULL;
}
FlistNode* FindFirstCommonNode(FlistNode* pHead1, FlistNode* pHead2) {
	if (!pHead1 || !pHead2)return NULL;//判空

	bool flag1 = IsCycle(pHead1);
	bool flag2 = IsCycle(pHead2);

	if ((flag1 == true && flag2 == false) || (flag1 == false && flag2 == true))//其中一个带环，另外一个不带环
		return NULL;
	else if (flag1 == false && flag2 == false)//两个都不带环
	{
		return FindCommonNode(pHead1, pHead2, NULL);
	}
	else//两个都带环
	{
		//1.两个环不相交  2.两个环在环外相交  3.两个环在环内相交
		FlistNode *enter1 = FindEnterNode(pHead1);
		FlistNode *enter2 = FindEnterNode(pHead2);

		if (enter1 == enter2)//情况2
		{
			return FindCommonNode(pHead1, pHead2, enter1->next);
		}
		else//情况1或情况3
		{
			FlistNode *tmp = enter1->next;
			while (tmp != enter2)//探测是不是情况3
			{
				if (tmp == enter1)return NULL;//说明是情况1
				tmp = tmp->next;
			}
			//能走到这里，说明就是情况3
			return enter1;//或者return enter2;
		}
	}
}

//剑指offer题37：统计一个数字在排序数组中出现的次数
int GetNumberOfK(vector<int> data, int k)
{
	int begin = 0, end = data.size() - 1;
	while (begin < end)//找到最左边的4
	{
		int mid = begin + (end - begin) / 2;
		if (data[mid] < k)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	int left = (end < 0 || data[end] < k) ? end + 1 : end;

	begin = 0, end = data.size() - 1;
	while (begin < end)//找到最右边的4
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

//剑指offer题38：输入一棵树，求该树的深度
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
	head4->left = head3; head4->right = head6;//根
	head3->left = head1;//左子树
	head1->right = head2;
	head6->left = head5; head6->right = head8;//右子树
	head8->left = head7;

	cout << TreeDepth(head6) << endl;
}

//剑指offer题39：输入一棵树，判断该二叉树是否是平衡树 (注意，平衡树不是平衡搜索树)
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
	head4->left = head3; head4->right = head6;//根
	head3->left = head1;//左子树
	head1->right = head2;
	head6->left = head5; head6->right = head8;//右子树
	head8->left = head7;

	cout << IsBalancedTree(head6) << endl;
}

//剑指offer题40：一个整型数组除了两个数字之外，其他的都出现了两次。请找出这两个只出现一次的数
void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
{
	if (data.size() < 2){ num1 = num2 = NULL; return; }

	int tmp = data[0];
	for (size_t i = 1; i < data.size(); ++i)
		tmp ^= data[i];

	//设那两个只出现一次的数字为X和Y,循环结束后，tmp = X ^ Y，接下来根据tmp，把数组分成两类
	int tmp_index = 1;
	while ((tmp & tmp_index) == 0)
		tmp_index <<= 1;//循环结束后，探测到X与Y不同的那个二进制位

	vector<int> help(data.size());
	int begin = 0, end = help.size() - 1;
	for (size_t i = 0; i < data.size(); ++i)//开始进行分类
	{
		if (data[i] & tmp_index)//等于1的放在后面
			help[end--] = data[i];
		else
			help[begin++] = data[i];//不等于1的放在前面
	}

	*num1 = 0; *num2 = 0;//注意，这里必须初始化为零
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

//剑指offer题41：快速找出所有和为S的连续正数序列。eg.S=100；9~16，18~22...
//       方法一：双指针问题，当总和小于sum，大指针++，否则小指针++。
//       方法二：(start+end)*(end-start+1)/2=sum，start<sqrt(2*sum),通过解二元一次方程求出一个整数的end
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

//剑指offer题42：输入一个递增排序的数组和一个数字S,在数组中查找两个数，它们的和正好是S,如果有多对数字的和等于
//               S，输出两个数的乘积最小的那对数字
//     方法：设头尾两个指针i和j,if a[i]+a[j]==sum,就是答案；if a[i]+a[j]>sum,--j;if a[i]+a[j]<sum,++i;
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

//剑指offer题43：对于一个给定的字符序列S，请把它循环左移K位后的序列输出
string LeftRotateString(string str, int n)
{
	if (str.empty() || n <= 0)return str;

	n %= str.size();//将n变成适当大小
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

//剑指offer题44：把一个字符串翻转，eg. "student. a am i"，翻转之后变成"i am a student."
string ReverseSentence(string str)
{
	int flag = 0,start = 0, end = str.size() - 1;
	while (start < end)//先整体翻转
		swap(str[start++], str[end--]);

	while (flag < str.size())
	{
		while (str[flag] == ' ')++flag;//防止第一个字符就是空格
		start = flag;
		while (flag < str.size() && str[flag] != ' ')++flag;
		end = flag - 1;

		while (start < end)swap(str[start++], str[end--]);//交换一个单词的顺序
	}
	return str;
}
void test_offer44()
{
	string str = " student. a am   i ";
	cout << ReverseSentence(str) << endl;
}

//剑指offer题45：从扑克牌中随机抽出了五张牌，判断是不是顺子，即这五张牌是不是连续的。(注意,2-10为数字本身，A为1，J为11，Q为12，K为13，大小王可以看成任意数字)
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

//剑指offer题46：0，1，2，3，...n-1这n个数字围成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求最后剩下的一个数字
// 牛皮方法：详见《剑指offer》第二版page302
int LastRemaining(int n, int m)
{
	if (n <= 0 || m <= 0)return -1;

	int s = 0;
	for (int i = 2; i <= n; ++i)
		s = (s + m) % i;
	return s;
}

//剑指offer题47：求1+2+3...+n,要求不能用乘除法，for,while,if,else,swith,case等关键字及判断语句(A?B:C)
//      方法：递归
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

//剑指offer题48：写一个函数 ，求两数之和，要求在函数体内不得使用+,-,*,/四则运算。
//方法一：略    方法二：详见《剑指offer》第二版page311
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
			//sum |= 1 << sum_index;错误
		}
	}
	return sum;
}
int Add2(int num1, int num2)
{
	while (num2 != 0)
	{
		int tmp = num1 ^ num2;//两数相加
		num2 = (num1 & num2) << 1;//求进位值
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

//剑指offer题49：将一个字符串转换成一个整数，要求不能用库函数。数值为0或者字符串不是一个合法的数值则返回0
int StrToInt(string str)
{
	int sum = 0, flag = 1, index = 0;
	while (index < str.size() && str[index] == ' ')++index;//去除无意义的空格
	if (index < str.size() && (str[index] == '-' || str[index] == '+'))//判断该整数的符号
	{
		flag = (str[index] == '-') ? -1 : 1;
		++index;
	}
	while (index < str.size())
	{
		if (!isdigit(str[index])){ sum = 0; break; }//处理不合法字符

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

//剑指offer题50：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字时重复的，但不知道有几个
//               数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字
//方法一：map<k,v>或hashtable  方法二：利用现有数组设置标志，当一个数字访问过后，可以设置对应位上的数字+n,之后在遇到相同的数，会发现对应位上的数大于n，直接返回该数即可
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

//剑指offer题51：给定一个数组A[0,1,2,...,n-1],请构建一个B[0,1,2,...,n-1],其中B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
//               注意不能用除法
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

//剑指offer题52：请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它
//               前面的字符可以出现任意次(包含0次)
// 算法思想：当模式中的第二个字符不是"*"时:如果字符串和模式中的第一个字符相匹配，那么它们都向后移1个字符，
//                                           然后匹配剩余的；否则直接返回false
//           当模式中的第二个字符是"*"时:如果字符串和模式中的第一个字符不匹配，则模式向后移2个字符；否则有三种
//                                       匹配方式①模式后移2个字符，相当于忽略"X*"
//                                               ②字符串后移1个字符，模式后移2个字符
//                                               ③字符串后移1个字符，模式不变，因为"*"前面那个字符可以匹配多次
bool _match(char str[], int s_index, char pattern[], int p_index)
{
	int s_len = strlen(str), p_len = strlen(pattern);

	//if (s_index == s_len && p_index == p_len)return true;//两个字符串都为空时，返回true（最下面的语句包含该语句逻辑，删）
	if (s_index < s_len && p_index == p_len)return false;//str不为空且pattern为空时，返回false
	if (s_index == s_len && p_index < p_len)//str为空且pattern不为空时
	{
		while (p_index + 1 < p_len && pattern[p_index + 1] == '*')p_index += 2;
		if (pattern[p_index] == '*')++p_index;
	}

	while (s_index < s_len && p_index < p_len)//两个字符串都不为空时
	{
		if (str[s_index] != '.' && pattern[p_index] != '.' && str[s_index] != pattern[p_index])//不匹配
		{
			if (p_index + 1 < p_len && pattern[p_index + 1] != '*')
				return false;
			else
				p_index += 2;
		}
		else//匹配
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
				//①模式后移2个字符，相当于X*被忽略
				//②字符串后移1个字符，模式后移2个字符
				//③字符串后移1个字符，模式不后移
				return _match(str, s_index, pattern, p_index + 2)
					|| _match(str, s_index + 1, pattern, p_index + 2)
					|| _match(str, s_index + 1, pattern, p_index);
			}
		}
	}
	//两个字符串一起到达\0时，才算匹配成功
	return (p_index != p_len || s_index != s_len) ? false : true;
}
bool match(char str[],char pattern[])
{
	return _match(str, 0, pattern, 0);//用下标控制边界比较好一些
}
void test_offer52()
{//""和"."  ""和"*"  "a"和"*" "a"和".*"  "a"和"."  "aa"和"aa"  "a"和"a." "a"和"ab*"  "aa"和"."
	char str[] = "aa";
	char pattern[] = ".";
	cout << match(str, pattern) << endl;
}

//剑指offer题53：请实现一个函数用来判断字符串是否表示数值
bool IsNumberic(char *str)//"  +/ /-xxx.xxxE/exxx"
{
	if (!str)return false;

	int index = 0, len = strlen(str),dot_cnt = 0;
	while (index < len && str[index] == ' ')++index;// 跳过空格
	if (index == len)return false;
	if (str[index] == '+' || str[index] == '-')++index;// 跳过符号位,由于上一句，所以这不需要判空
	if (index == len)return false;

	for (; index < len && str[index] != 'e' && str[index] != 'E'; ++index)// 处理E/e前面的字符
	{
		if (str[index] == '.')
		{ 
			++dot_cnt; 
			if (dot_cnt == 2)return false;
			continue; 
		}
		if (!isdigit(str[index]))return false;
	}
	//能走到这，要么str[index]=='e/E'，要么index==len
	bool flag = false;
	if (index < len && (str[index] == 'e' || str[index] == 'E'))// 处理e/E后面的字符（注意，e/E后面只能是正整数或负整数）
	{
		++index;//跳过e/E
		if (str[index] == '+' || str[index] == '-')++index;// 跳过符号位
		for (; index < len; ++index)// 真正开始处理e/E后面的字符
			if (!isdigit(str[index]))return false;
		return flag;
	}
	return true;//能平安走到这，说明该字符串就能表示一个数值
}
void test_offer53()
{
	cout << IsNumberic("  +.2e2") << endl;
}

//剑指offer题54：请实现一个函数用来找出字符流中第一个只出现一次的字符。eg.当从字符流中只读出前两个字符"go"时，
//               第一个只出现一次的字符是'g'；当从该字符六种读出前六个字符"google"时，第一个只出现一次的字符是'l'
// 方法一：arr[256]或哈希表  方法二：map<K,V>
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

//剑指offer题55：一个单链表中包含环，请找出该链表的环的入口结点（测试用例给了不带环的单链表）
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

//剑指offer题56：在一个排序的链表中，存在重复的结点，请删除该链表中的重复结点，重复的结点不保留，返回链表头指针
//                eg.输入:1->2->3->3->4->4->5   输出:1->2->5
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
	if(prev)prev->next = NULL;//反正走完循环prev是最后一个元素，暴力置prev->next=NULL
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

//剑指offer题57：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点是三叉链
TreeThreeLinkNode *GetNextNode(TreeThreeLinkNode* pNode)
{
	if (!pNode)return NULL;
	//如果自己是父亲的左孩子，①右为空找父亲，②右不为空就找右子树最左结点
	//如果自己是父亲的右孩子，①右为空找爷爷，②右不为空就找右子树最左结点
	if (pNode->right)//右不为空
	{
		TreeThreeLinkNode *pNode_right = pNode->right;
		while (pNode_right->left)pNode_right = pNode_right->left;
		return pNode_right;
	}
	else//右为空
	{
		TreeThreeLinkNode *parent = pNode->parent;
		//if (parent && parent->left == pNode)//如果自己是父亲的左孩子，
		//	return parent;
		while (parent && pNode == parent->right)//如果自己是父亲的右孩子，
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

//剑指offer题58：请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是相同的，定义其为对称的
bool _IsSymmetrical(TreeNode *pRoot1, TreeNode *pRoot2)
{
	if (!pRoot1 && !pRoot2)return true;//两个都为空时成立
	if (!pRoot1 || !pRoot2)return false;//两个中其中一个为空时成立
	//下面就是两个都不为空的情况
	return pRoot1->val == pRoot2->val
		&& _IsSymmetrical(pRoot1->left, pRoot2->right)
		&& _IsSymmetrical(pRoot1->right, pRoot2->left);
}
bool IsSymmetrical(TreeNode *pRoot)
{
	return  _IsSymmetrical(pRoot, pRoot);
}

//剑指offer题59：请实现一个函数按照之字形打印二叉树，即第一行从左往右的顺序打印，第二行从右往左打印，第三行从左往右...以此类推
vector<vector<int>> Print(TreeNode *pRoot)
{
	vector<vector<int>> dst;

	stack<TreeNode*> odd;//奇数层栈pop结点且向偶数层栈带孩子时，先带左孩子后右孩子
	stack<TreeNode*> even;//偶数层栈pop结点且向奇数层栈带孩子时，先带右孩子后左孩子
	if(pRoot)odd.push(pRoot);
	while (!odd.empty())
	{
		TreeNode *cur;

		vector<int> odd_res;
		while (!odd.empty())
		{
			cur = odd.top(); odd.pop();
			odd_res.push_back(cur->val);
			if (cur->left)even.push(cur->left);//先带左孩子后右孩子
			if (cur->right)even.push(cur->right);
		}
		dst.push_back(odd_res);

		vector<int> even_res;
		while (!even.empty())
		{
			cur = even.top(); even.pop();
			even_res.push_back(cur->val);
			if (cur->right)odd.push(cur->right);//先带右孩子后左孩子
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

//剑指offer题60：从上到下按层打印二叉树，同一层结点从左往右输出。每一层输出一行。
vector<vector<int>> Print2(TreeNode *pRoot)
{
	vector<vector<int>> dst;
	queue<TreeNode*> odd;//这两个队列pop元素时，都是先带左孩子后右孩子
	queue<TreeNode*> even;//（那么弄两个队列就是为了分清楚到底在哪一层）
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

//剑指offer题61：请实现两个函数，分别用来序列化和反序列化二叉树
// 序列化:使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点不为空时，在转化val所得的字符
//            之后添加一个逗号作为分割。对于空结点则'#'代替
// 反序列化:按照前序顺序，递归的使用字符串中的字符创建一个二叉树
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

//剑指offer题62：给定一个二叉搜索树，请找出其中的第k小的结点。eg. 5 /\ 3 7 /\ /\ 2 4 6 8中，第3小的数是4
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

//剑指offer题63：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于
//               中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值
//  方法：使用大堆+小堆的容器，两个堆中的数据个数只差不超过1。
#include<queue>
#include<functional>
class GetMedianNum
{ 
public:
	void Insert(int num)
	{
		//始终保持大根堆的元素>=小根堆的，且差<=1.
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
		++cnt;//记录总共插入的元素个数
	}
	double GetMedian()
	{
		if (cnt % 2 == 1)
			return maxHeap.top();
		else
			return (double)(maxHeap.top() + minHeap.top()) / 2;
	}
private:
	int cnt = 0;//记录总共插入的元素个数
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>,greater<int>> minHeap;//用来打辅助
};
void test_offer63()
{
	GetMedianNum mid;
	int num[] = { 1, 2, 3, 4, 5, 6 ,-5,-7,0,10,52,43,7};
	for (size_t i = 0; i < sizeof(num) / sizeof(num[0]); ++i)
		mid.Insert(num[i]);
	cout << mid.GetMedian() << endl;
}

//剑指offer题64：给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值
// 方法：用一个双端队列，队列第一个位置保存当前窗口的最大值，当窗口滑动一次，①判断当前最大值是否过期②新增的值从队尾开始比较，把比他小的值丢弃
#include<deque>
vector<int> MaxInWindows(const vector<int> &num, size_t size)
{
	vector<int> dst(num.size()); size_t dst_index = 0;
	deque<size_t> deq;
	for (size_t i = 0; i < num.size(); ++i)
	{
		if (!deq.empty() && i - deq.front() >= size)//①判断当前最大值是否过期
			deq.pop_front();
		while (!deq.empty() && num[i] >= num[deq.back()])//②新增的值从队尾开始比较，把比他小的值丢弃
			deq.pop_back();

		deq.push_back(i);
		dst[dst_index++] = num[deq.front()];
	}
	return dst;
}
vector<int> MaxInWindows2(const vector<int>& num, unsigned int size)
{
	if (num.empty() || size == 0)return vector<int>();//去除不合法参数的情况

	vector<int> dst(num.size() - size + 1); size_t dst_index = 0;
	deque<size_t> deq; size_t i = 0;
	for (; i < size - 1 && i < num.size(); ++i)//处理前size个数
	{
		if (!deq.empty() && i - deq.front() >= size)//①判断当前最大值是否过期
			deq.pop_front();
		while (!deq.empty() && num[i] >= num[deq.back()])//②新增的值从队尾开始比较，把比他小的值丢弃
			deq.pop_back();

		deq.push_back(i);
	}

	for (; i < num.size(); ++i)//处理下标为size及其后面的元素
	{
		if (!deq.empty() && i - deq.front() >= size)//①判断当前最大值是否过期
			deq.pop_front();
		while (!deq.empty() && num[i] >= num[deq.back()])//②新增的值从队尾开始比较，把比他小的值丢弃
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
	vector<int> dst2 = MaxInWindows2(num, 3);// 4 4 6 6 6 5       OJ中是这种做法
	for (auto &r : dst2)cout << r << " "; cout << endl;
}

//剑指offer题65：设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中
//               的任意一个格子开始，每一步可以在矩阵中向左向右向上向下移动一个格子。如果一条路径经过了矩阵中
//               的某一个格子，则该路径不能在进入该格子。
bool _HasPath(char *matrix, int row, int cols, int index, char *str)
{
	if (*str == '\0')return true;
	if (index >= row*cols || matrix[index] != *str)return false;

	matrix[index] -= 32;
	bool flag = false;
	if (flag == false && (index + 1) % cols != 0)
		flag = _HasPath(matrix, row, cols, index + 1, str + 1);//右
	if (flag == false)
		flag = _HasPath(matrix, row, cols, index + cols, str + 1);//下
	if (flag == false && index%cols != 0)
		flag = _HasPath(matrix, row, cols, index - 1, str + 1);//左
	if (flag == false)
		flag = _HasPath(matrix, row, cols, index - cols, str + 1);//上
	matrix[index] += 32;
	return flag;
}
bool HasPath(char *matrix, int row, int cols, char *str)
{
	if (!matrix || row < 1 || cols < 1 || !str)
		return false;//保证下面的操作数据都是合法值

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

//剑指offer题66：地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左右上下四个方向移动
//               一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。问机器人能够达到多少个格子
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
	//27                                没写//排列组合
	//test_offer28();//
	//test_offer29();//topK问题
	//test_offer30();//动态规划，

	//test_offer31();//十进制1的个数
	//test_offer32();//A+B<B+A的字符串比较
	//test_offer33();//铺马路式寻找
	//test_offer34();//map<k,v>模型
	//test_offer35();//归并分治思想
	//test36*****

	//test_offer37();
	//test_offer38();
	//test_offer39();
	//test_offer40();
	//test_offer41();//双指针问题
	//test_offer42();//双指针问题

	//test_offer43();
	//test_offer44();
	//test_offer45();
	//test46约瑟夫环问题
	//test_offer47();
	//test_offer48();

	//test_offer49();
	//test_offer50();
	//test_offer51();//同day13,已通过测试用例
	//test_offer52();//正则匹配，已通过测试用例 **
	//test_offer53();
	//test_offer54();                                     //--------------------------------------

	//test55   跑过测试用例
	//test_offer56();//同day12 跑过
	//test_offer57();//跑过
	//test58   ****  跑过
	//test_offer59(); //跑过
	//test_offer60(); //跑过

	//test_offer61();
	//test_offer62();
	//test_offer63();
	//test_offer64();
	test_offer65();
}