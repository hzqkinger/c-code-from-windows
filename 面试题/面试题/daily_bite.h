#pragma once
#include"DefineNode.h"


//day10.1 �ϲ��������������һ����Ȼ����ĵ�����
//day10.2 ����һ������������ͷָ�롣

//struct Node{struct Node *_next;int _i;};
//���ж�һ���������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿
//���ж������������Ƿ��ཻ�����ཻ���󽻵㣿
//day11:����������ĵ�һ���������
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
};

//day12:��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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

//day13:����һ��A[0 1 2 3...n-1]�����飬����һ��B[0 1 2 3...n-1]�����飬����B[i] = A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
#include<vector>
vector<int> multiply(const vector<int>& A)//��ͨ����������
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

//day14:����һ���������ͷ�����head������ĳ���ΪN�����N��ż������ǰN/2�������ǰ�벿�֣���N/2���������벿�֣�
//      ���N����������ǰN/2�������ǰ�벿�֣���N/2+1���������벿�֡�
//ps:�ٿ������N==1��N==2��N==3�����ǵ������������������Ķ�������ĿҪ��
void relocateList(FlistNode* head)//��ͨ����������
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
FlistNode *rotateRight(FlistNode *head, int k) //��ͨ����������
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
TreeNode *sortedListToBST(FlistNode *head)//��ͨ����������
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
	while (n--)//�����ж�n�Ƿ��������ĸ����࣬��Ϊ��Ŀ˵n��valid
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
	if (!l2)return l1;//��֤������Ĵ����У�����������Ϊ��

	FlistNode *cur1 = l1, *cur2 = l2;
	while (cur1 && cur2)//��֤cur1����ָ���������
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

	int flag = 0;//��λ��־
	FlistNode *prev = NULL;
	while (cur1 && cur2)//�����������ӷ�
	{
		prev = cur1;//��¼cur1��ǰһ��
		cur1->val = cur1->val + cur2->val + flag;
		if (cur1->val >= 10)
		{
			cur1->val -= 10;
			flag = 1;
		}
		else flag = 0;
		cur1 = cur1->next; cur2 = cur2->next;
	}

	while (flag == 1 && cur1)//�����cur2һ��ָ���
	{
		prev = cur1;//��¼cur1��ǰһ��
		cur1->val = cur1->val + /*cur2->val + */flag;//��Ҫ���⸴�ƴ��룬Ѫ�Ľ�ѵ�������涼�����װ�˵cur2һ���ǿ���
		if (cur1->val >= 10)
		{
			cur1->val -= 10;
			flag = 1;
		}
		else flag = 0;
		cur1 = cur1->next;
	}

	if (flag == 1)//�ߵ�����,ҪôflagΪ1��cur1Ϊ�գ�ҪôflagΪ0��cur1��Ϊ�գ�����flagΪ0��cur1Ϊ��
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
	if (!head->next)return head;//��֤����Ĳ���һ������һ��Ԫ��

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

	if (head->val > slow->val)//��֤headһ��ָ��ͷ��С��Ԫ��
		swap(head, slow);
	//��ʼ��headָ��ĵ�������slowָ��ĵ�����鲢
	FlistNode *cur = head;
	prev = NULL; fast = NULL;//�����濪ʼ��prevָ��cur��ǰһ����fastָ��slow�ĺ�һ��
	while (cur && slow)
	{
		while (cur && cur->val <= slow->val)
		{
			prev = cur;
			cur = cur->next;
		}
		fast = slow->next;

		prev->next = slow;//3.��Ϊ1��֤�� �տ�ʼʱhead->val <= slow->val,��������prevһ������Ϊ��
		slow->next = cur;
		prev = prev->next;

		slow = fast;
	}
	if (!cur)prev->next = slow;

	return head;
}
FlistNode *LinkedListSort(FlistNode *head)
{
	if (!head || !head->next)return head;//������Ԫ�ظ���С��2����ֱ�ӷ���head

	return MergeSort(head);//��֤head��Ԫ�ظ������ڵ���2��
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
	//big==head    ���м�.....big==NULL
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

//day18.1: ʵ��һ��Stack�����ݽṹ��ʹ���ܹ�����Min������
//day18.2: ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
//day19.1: ������ջʵ��һ������

//day20.1: ��ʵ��һ�����ݽṹSetOfStacks���ɶ��ջ��ɣ�����ÿ��վ�Ĵ�СΪsize����ǰһ��ջ����ʱ���Ƚ�һ��ջ��
//         �����ݽṹӦ��֧������ͨջ��ͬ��push��pop.
//���ڸ���һ����������int[][2]ope��c++��vector<vector<int>>ope����ÿ�������ĵ�һ��������һ�����Ĳ������ͣ���Ϊ
//1����Ϊpush��������һ����ΪӦpush�����֣���Ϊ����������Ϊpop��������һ���������塣
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
//day20.2: ��дһ�����򣬰������ջ�������򣨼����Ԫ��λ��ջ������Ҫ�����ֻ��ʹ��һ�������ջ�����ʱ���ݣ�
//         �����ý�Ԫ�ظ�ֵ��������ݽṹ��ע�⣬���Ƶ�һ�������ж����У�
//���ڸ���һ��int[]numbers��c++��Ϊvector<int>��,eg.�������У�{1,2,3,4,5}�����أ�{5,4,3,2,1}
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

//day21:ֻ�õݹ�����һ��ջ
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


//���ĳ���ַ���������ظ��Ӵ��ĳ���
void Maxlen(const char *str)
{

}
void test_daily_bite()
{
	//day11 ���ܹ���������
	//test_deleteDuplication();//day12  û�ܹ���������
	//day13   �ܹ�
	//day14   �ܹ�
	//test_day15();  //�ܹ�
	//day15.2
	//day16.1      �Ѿ��ܹ���������
	//test_addTwoNumbers();//�ܹ�
	test_LinkedListSort(); //�Ѳ�
	//day17.2   �ܹ�
	//day18.1.2  ���ܹ�
	//day19.1 �ܹ�
	//test_SetOfStacks();//�ܹ�
	//test_TwoStacks();//�ܹ�
	//test_day21();//         û�ܹ���������
}