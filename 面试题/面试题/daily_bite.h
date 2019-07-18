#pragma once
#include"DefineNode.h"


//day10.1 合并两个有序单链表成一个依然有序的单链表。
//day10.2 逆序一个单链表，返回头指针。

//struct Node{struct Node *_next;int _i;};
//①判断一个单链表是否带环？若带环，求环的长度？求环的入口点？
//②判断两个单链表是否相交？若相交，求交点？
//day11:求两个链表的第一个公共结点
class Solution11 {
public:
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
};

//day12:在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
FlistNode* deleteDuplication(FlistNode* pHead)
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
	if (prev)prev->next = NULL;
	return prev ? pHead : NULL;
}
void test_deleteDuplication()
{
	FlistNode *head1 = new FlistNode(1);
	FlistNode *head2 = new FlistNode(1); head1->next = head2;
	FlistNode *head3 = new FlistNode(3); head2->next = head3;
	FlistNode *head4 = new FlistNode(3); head3->next = head4;
	FlistNode *head5 = new FlistNode(3); head4->next = head5;
	FlistNode *head6 = new FlistNode(4); head5->next = head6;
	FlistNode *head7 = new FlistNode(4); head6->next = head7;
	FlistNode *head8 = new FlistNode(5); head7->next = head8;
	FlistNode *head9 = new FlistNode(5); head8->next = head9;

	head1 = deleteDuplication(head1);
	FlistNode *cur = head1;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}cout << endl;
}

//day13:给定一个A[0 1 2 3...n-1]的数组，构建一个B[0 1 2 3...n-1]的数组，其中B[i] = A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
#include<vector>
vector<int> multiply(const vector<int>& A)//已通过测试用例
{
	vector<int> left(A.size()); left[0] = A[0];
	vector<int> right(A.size()); right[right.size() - 1] = A[A.size() - 1];

	for (size_t i = 1; i < left.size(); ++i)
		left[i] = left[i - 1] * A[i];
	for (int i = right.size() - 2; i >= 0; --i)
		right[i] = right[i + 1] * A[i];

	vector<int> dst(A.size());
	for (size_t i = 0; i < dst.size(); ++i)
	{
		if (i == 0){ dst[i] = right[i + 1]; continue; }
		if (i == dst.size() - 1){ dst[i] = left[i - 1]; continue; }

		dst[i] = left[i - 1] * right[i + 1];
	}
	return dst;
}

//day14:给定一个单链表的头部结点head，链表的长度为N。如果N是偶数，则前N/2个结点做前半部分，后N/2个结点做后半部分；
//      如果N是奇数，则前N/2个结点做前半部分，后N/2+1个结点做后半部分。
//ps:①空链表②N==1③N==2④N==3，考虑到了这四种情况，其余的都符合题目要求
void relocateList(FlistNode* head)//已通过测试用例
{
	if (!head)return;

	FlistNode *left = NULL, *right = NULL;
	FlistNode *fast = head, *slow = head;

	while (fast && fast->next)
	{
		left = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (left)left->next = NULL;

	left = head; right = slow;
	fast = left->next; slow = right->next;
	//if(left == right)return;
	while (fast)
	{
		right->next = fast;
		left->next = right;

		left = fast;
		right = slow;

		fast = left->next;
		slow = right->next;
	}
	left->next = left != right ? right : NULL;

}

//day15.1:Given a list,rotate the list to the right by k places,where k is non_negative.
//      eg.  Given:1->2->3->4->5->NULL,k=2; Return 4->5->1->2->3->NULL.
FlistNode *rotateRight(FlistNode *head, int k) //已通过测试用例
{
	FlistNode *fast = head, *slow = head, *prev = NULL;
	int count = 0;
	while (fast){ ++count; fast = fast->next; }
	if (count <= 1)return head;

	k %= count; fast = head;
	while (k-- > 0)fast = fast->next;
	while (fast)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next;
	}
	if (prev)prev->next = NULL;

	fast = slow;
	while (slow && slow->next)
		slow = slow->next;
	if (slow)
	{
		slow->next = head;
		head = fast;
	}

	return head;
}
void test_day15()
{
	FlistNode *head1 = new FlistNode(1);
	FlistNode *head2 = new FlistNode(2); head1->next = head2;
	FlistNode *head3 = new FlistNode(3); head2->next = head3;
	FlistNode *head4 = new FlistNode(4); head3->next = NULL;
	FlistNode *head5 = new FlistNode(5); head4->next = head5;
	FlistNode *head6 = new FlistNode(6); head5->next = head6;
	FlistNode *head7 = new FlistNode(7); head6->next = head7;
	FlistNode *head8 = new FlistNode(8); head7->next = head8;
	FlistNode *head9 = new FlistNode(9); head8->next = head9;

	FlistNode *tmp = rotateRight(head1, 7);
	while (tmp)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}cout << endl;
}
//day15.2:Given a singly linked list where elements are sorted in ascending order,
//        convert it to height balanced BST.
TreeNode *sortedListToBST(FlistNode *head)//已通过测试用例
{
	if (!head)return NULL;
	if (!head->next)return new TreeNode(head->val);

	FlistNode *mid = head, *tail = head, *prev = NULL, *next = NULL;

	while (tail && tail->next)
	{
		prev = mid;
		mid = mid->next;
		tail = tail->next;
		if (tail)
			tail = tail->next;
	}
	if (prev)prev->next = NULL;
	if (mid)next = mid->next;

	TreeNode *root = new TreeNode(mid->val);
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(next);

	return root;
}

//day16.1: Given a linked list. remove the n_th node from the end of list and return its head.
FlistNode *removeNthFromEnd(FlistNode *head, int n) {
	if (!head)return NULL;

	FlistNode *slow = head, *fast = head;
	while (n--)//不用判断n是否比链表结点的个数多，因为题目说n是valid
		fast = fast->next;

	if (!fast)
	{
		head = slow->next;
		delete slow;
		return head;
	}

	while (fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	FlistNode *next = slow->next;
	slow->next = next->next;
	delete next;

	return head;
}
//day16.2: you are given two lists representing two non_negative numbers.the digits are stored in
//       reverse order and each of their nodes contain a single digit.Add the two numbers and return it
//       as a linked list.
FlistNode *addTwoNumbers(FlistNode *l1, FlistNode *l2) {
	if (!l1)return l2;
	if (!l2)return l1;//保证在下面的代码中，两个链表都不为空

	FlistNode *cur1 = l1, *cur2 = l2;
	while (cur1 && cur2)//保证cur1总是指向最长的链表
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	if (!cur1)
	{
		cur1 = l2; cur2 = l1;
		l1 = cur1; l2 = cur2;
	}
	else { cur1 = l1; cur2 = l2; }

	int flag = 0;//进位标志
	FlistNode *prev = NULL;
	while (cur1 && cur2)//两个数正常加法
	{
		prev = cur1;//记录cur1的前一个
		cur1->val = cur1->val + cur2->val + flag;
		if (cur1->val >= 10)
		{
			cur1->val -= 10;
			flag = 1;
		}
		else flag = 0;
		cur1 = cur1->next; cur2 = cur2->next;
	}

	while (flag == 1 && cur1)//到这里，cur2一定指向空
	{
		prev = cur1;//记录cur1的前一个
		cur1->val = cur1->val + /*cur2->val + */flag;//不要随意复制代码，血的教训啊，上面都明明白白说cur2一定是空了
		if (cur1->val >= 10)
		{
			cur1->val -= 10;
			flag = 1;
		}
		else flag = 0;
		cur1 = cur1->next;
	}

	if (flag == 1)//走到这里,要么flag为1且cur1为空；要么flag为0且cur1不为空；或者flag为0且cur1为空
		prev->next = new FlistNode(flag);

	return l1;
}
void test_addTwoNumbers()
{
	FlistNode *head1 = new FlistNode(9);
	FlistNode *head2 = new FlistNode(9); head1->next = head2;
	FlistNode *head3 = new FlistNode(9); head2->next = head3;
	FlistNode *head4 = new FlistNode(9); head3->next = NULL;
	FlistNode *head5 = new FlistNode(9); head4->next = head5;
	FlistNode *head6 = new FlistNode(9); head5->next = head6;

	FlistNode *cur1 = new FlistNode(8);
	FlistNode *cur2 = new FlistNode(8); cur1->next = cur2;
	FlistNode *cur3 = new FlistNode(8); cur2->next = cur3;
	FlistNode *cur4 = new FlistNode(8); cur3->next = cur4;
	FlistNode *cur5 = new FlistNode(8); cur4->next = cur5;
	FlistNode *cur6 = new FlistNode(8); cur5->next = cur6;

	FlistNode * tmp = addTwoNumbers(head1, cur1);
	while (tmp)
	{
		cout << tmp->val;
		tmp = tmp->next;
	}cout << endl;
}

//day17.1: Sort a linked list in O(nlogn)time using constant space complexity.
FlistNode *MergeSort(FlistNode *head)
{
	if (!head->next)return head;//保证下面的操作一定存在一个元素

	FlistNode *prev = NULL, *fast = head, *slow = head;
	while (fast)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next;
		if (fast)fast = fast->next;
	}
	prev->next = NULL;

	head = MergeSort(head);
	slow = MergeSort(slow);

	if (head->val > slow->val)//保证head一定指向开头最小的元素
		swap(head, slow);
	//开始将head指向的单链表与slow指向的单链表归并
	FlistNode *cur = head;
	prev = NULL; fast = NULL;//从下面开始，prev指向cur的前一个；fast指向slow的后一个
	while (cur && slow)
	{
		while (cur && cur->val <= slow->val)
		{
			prev = cur;
			cur = cur->next;
		}
		fast = slow->next;

		prev->next = slow;//3.因为1保证了 刚开始时head->val <= slow->val,所以这里prev一定不会为空
		slow->next = cur;
		prev = prev->next;

		slow = fast;
	}
	if (!cur)prev->next = slow;

	return head;
}
FlistNode *LinkedListSort(FlistNode *head)
{
	if (!head || !head->next)return head;//单链表元素个数小于2个，直接返回head

	return MergeSort(head);//保证head中元素个数大于等于2个
}
void test_LinkedListSort()
{
	FlistNode *head1 = new FlistNode(4);
	FlistNode *head2 = new FlistNode(2); head1->next = head2;
	FlistNode *head3 = new FlistNode(1); head2->next = head3;
	FlistNode *head4 = new FlistNode(3); head3->next = head4;
	//FlistNode *head5 = new FlistNode(2); head4->next = head5;

	FlistNode *tmp = LinkedListSort(head1);
	while (tmp)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}cout << endl;
}
//day17.2: Given a linked list and a value x.partition it such that all nodes less than x come before nodes
//         greater than or equal to x. you should preserve the original relative order of the nodes in each of the two partitions.
//         eg. Given 1->4->3->2->5 and x=3     return 1->2->2->4->3->5.
FlistNode *partition(FlistNode *head, int x) {
	if (!head) return head;

	FlistNode *prev = NULL, *first_big = head;
	while (first_big && first_big->val < x)
	{
		prev = first_big;
		first_big = first_big->next;
	}
	//big==head    在中间.....big==NULL
	if (!first_big)return head;

	FlistNode *prev2 = prev, *cur2 = first_big, *next2 = cur2;
	while (cur2)
	{
		while (cur2 && cur2->val >= x)
		{
			prev2 = cur2;
			cur2 = cur2->next;
		}
		if (!cur2)break;
		next2 = cur2->next;
		if (!prev)
		{
			cur2->next = head;
			head = prev = cur2;
		}
		else
		{
			cur2->next = prev->next;
			prev->next = cur2;
			prev = prev->next;
		}
		prev2->next = next2;
		cur2 = next2;
	}
	return head;
}

//day18.1: 实现一个Stack的数据结构，使它能够具有Min函数。
//day18.2: 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序
//day19.1: 用两个栈实现一个队列

//day20.1: 请实现一个数据结构SetOfStacks，由多个栈组成，其中每个站的大小为size，当前一个栈填满时，先建一个栈。
//         该数据结构应该支持与普通栈相同的push和pop.
//现在给定一个操作序列int[][2]ope（c++中vector<vector<int>>ope），每个操作的第一个数代表一个数的操作类型，若为
//1，则为push操作，后一个数为应push的数字，若为其他数字则为pop操作，后一个数无意义。
class SetOfStacks {
public:
	vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
		if (ope.empty() || size <= 0)return sta;

		size_t count = 0;
		for (size_t i = 0; i < ope.size(); ++i)
		{
			if (ope[i][0] == 1)//push
			{
				if (!sta.empty() && sta[count].size() == size)
					count++;
				sta.resize(count + 1);
				sta[count].push_back(ope[i][1]);
			}
			else//pop
			{
				if (sta[count].empty())
					--count;
				sta[count].pop_back();
			}
		}
		return sta;
	}
private:
	vector<vector<int>> sta;
};
void test_SetOfStacks()
{
	vector<vector<int>> v = { { 1, 2 }, { 1, 3 }, { 1, 8 }, { 2, 5 } };
	SetOfStacks sta;
	sta.setOfStacks(v, 2);
}
//day20.2: 请写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，
//         但不得将元素赋值到别的数据结构（注意，复制到一个变量中都不行）
//现在给定一个int[]numbers（c++中为vector<int>）,eg.输入序列：{1,2,3,4,5}；返回：{5,4,3,2,1}
class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers) {
		vector<int> sta;
		while (!numbers.empty())
		{
			while (!sta.empty() && sta[sta.size() - 1] > numbers[numbers.size() - 1])
			{
				numbers.insert(numbers.end() - 1, sta[sta.size() - 1]);
				sta.pop_back();
			}
			sta.push_back(numbers[numbers.size() - 1]);
			numbers.pop_back();
		}
		while (!sta.empty())
		{
			numbers.push_back(sta[sta.size() - 1]);
			sta.pop_back();
		}
		return numbers;
	}
};
void test_TwoStacks()
{
	vector<int> numbers = { 1, 2, 3, 4, 5 };
	TwoStacks sta;
	vector<int> num = sta.twoStacksSort(numbers);
	cout << endl;
}

//day21:只用递归逆序一个栈
int GetAndRemoveButtomElement(vector<int> &stack,int top)
{
	int cur = stack[top - 1];
	stack.pop_back();
	if (stack.empty())
		return cur;

	int buttom = GetAndRemoveButtomElement(stack, top - 1);
	stack.push_back(cur);
	return buttom;
}
vector<int> reverseStackRecursively(vector<int> &stack, int top) {
	if (top != 0)
	{
		int GetButtom = GetAndRemoveButtomElement(stack, top);
		reverseStackRecursively(stack, top - 1);
		stack.push_back(GetButtom);
	}
	return stack;
}
void test_day21()
{
	vector<int> arr = { 1, 2, 3, 4, 5 };
	vector<int> num = reverseStackRecursively(arr, arr.size());
	for (auto &r : num)cout << r << " "; cout << endl;
}


//求出某个字符串中最长不重复子串的长度
void Maxlen(const char *str)
{

}
void test_daily_bite()
{
	//day11 已跑过测试用例
	//test_deleteDuplication();//day12  没跑过测试用例
	//day13   跑过
	//day14   跑过
	//test_day15();  //跑过
	//day15.2
	//day16.1      已经跑过测试用例
	//test_addTwoNumbers();//跑过
	test_LinkedListSort(); //已测
	//day17.2   跑过
	//day18.1.2  都跑过
	//day19.1 跑过
	//test_SetOfStacks();//跑过
	//test_TwoStacks();//跑过
	//test_day21();//         没跑过测试用例
}