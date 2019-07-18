#pragma once
#include"DefineNode.h"

//struct Node{struct Node *_next;int _i/*0<=_i<+9*/;}。
//判断一个单链表中存储的所有整数组合在一起是不是一个回文数
#include<stack>
bool test1(FlistNode*head)//下面对head都没判空
{
	std::stack<int> s;//方法一:需要申请n个空间
	FlistNode *tmp = head;
	while (tmp){
		s.push(tmp->val); tmp = tmp->next;
	}
	tmp = head;
	while (!s.empty() && s.top() == tmp->val){
		s.pop(); tmp = tmp->next;
	}
	return s.empty() ? true : false;
}
bool test11(FlistNode*head)
{
	std::stack<int> s2;//方法二:需要申请n/2个空间
	FlistNode *slow = head, *fast = head;
	while (fast->next){
		slow = slow->next;//慢指针走一步
		fast = fast->next; if (fast->next)fast = fast->next;//快指针走两步
	}
	while (slow->next){//从慢指针指向元素的后一个结点开始一直压栈
		slow = slow->next;
		s2.push(slow->val);
	}
	slow = head;
	while (!s2.empty() && s2.top() == slow->val){
		s2.pop(); slow = slow->next;
	}
	return s2.empty() ? true : false;
}
bool test12(FlistNode *head)
{
	FlistNode *slow2 = head, *fast2 = head; bool flag = false;//方法三,只需要几个指针变量
	while (fast2->next){
		slow2 = slow2->next;//慢指针走一步
		fast2 = fast2->next; if (fast2->next)fast2 = fast2->next;//快指针走两步
	}
	FlistNode *prev = nullptr, *cur = slow2, *next = cur->next;//改指针操作
	while (cur){
		cur->next = prev; prev = cur; cur = next;
		if (next)next = next->next;
	}
	prev = head, next = fast2;
	while (prev && next){//判断是不是回文
		if (prev->val == next->val){ prev = prev->next; next = next->next; }
		else break;
	}
	if (!(prev && next))flag = true;
	prev = nullptr; cur = fast2; next = cur->next;
	while (cur){//最后将指针改回来
		cur->next = prev; prev = cur; cur = next;
		if (next)next = next->next;
	}
	return flag;
}

//struct Node{struct Node *_next;struct Node *_random;int _i;}
//随机单链表的复制
RondomListNode* test2(RondomListNode *head)
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

//7.1.1 将一棵二叉排序树转换成升序链表
//         方法一：用对列    方法二：用递归解
TreeNode *_big(TreeNode *root)
{
	if (!root)return NULL;

	TreeNode *lefts = _big(root->left);
	TreeNode *rights = _big(root->right);

	TreeNode *lefth = NULL, *righth = NULL;
	if (lefts)lefth = lefts->right;
	if (rights)righth = rights->right;
	else righth = root;

	if (lefts)lefts->right = root;
	root->left = lefts;
	if (righth != root)righth->left = root;
	root->right = righth;

	if (rights)rights->right = lefth;

	return rights ? rights : root;
}
TreeNode *big(TreeNode *root)//用递归
{
	TreeNode *rights = _big(root);
	TreeNode *head = rights->right;
	rights->right = NULL;

	return head;
}

//7.1.2 删除单链表中的一个非尾节点
void Erase(FlistNode *node)
{
	FlistNode *next = node->next;
	node->val = next->val;
	node->next = node->next;
	delete next;
}
void test_linklist()
{
	FlistNode *cur11 = new FlistNode(1);
	FlistNode *cur12 = new FlistNode(2); cur11->next = cur12;
	FlistNode *cur13 = new FlistNode(3); cur12->next = cur13;
	//Node *cur14 = new Node(3); cur13->_next = cur14;
	FlistNode *cur15 = new FlistNode(2); cur13->next = cur15;
	FlistNode *cur16 = new FlistNode(1); cur15->next = cur16;
	cout << test1(cur11) << endl;
	cout << test11(cur11) << endl;
	cout << test12(cur11) << endl;

	RondomListNode *cur21 = new RondomListNode(1);
	RondomListNode *cur22 = new RondomListNode(2); cur21->next = cur22;
	RondomListNode *cur23 = new RondomListNode(3); cur22->next = cur23;
	RondomListNode *cur24 = new RondomListNode(4); cur23->next = cur24;
	cur21->rand = cur23; cur22->rand = cur24;
	cur23->rand = cur22; cur24->rand = nullptr;
	RondomListNode *head2 = test2(cur21);
}

//1.求两个结点的最近公共祖先
//ps:①该二叉树为搜索二叉树(拿当前结点与两个结点比较，都比当前结点小，则最近公共祖先在左子树；)
//   ②该二叉树有指向父亲的指针(该题目瞬间转变为求两个交叉单链表的题)
//   ③该二叉树为普通的二叉树(1.开两个辅助数组；2.如下用递归求解)
TreeNode* Con_ancestor(TreeNode *root, const TreeNode *x, const TreeNode *y)//递归写法
{
	if (!root || !x || !y)return NULL;//三个结点都不能为空

	if (root == x || root == y)return root;

	TreeNode *left = Con_ancestor(root->left, x, y);
	TreeNode *right = Con_ancestor(root->right, x, y);

	if (left && right)//只有左右都不为空时，root即为两个结点的最近公共祖先
		return root;

	if (left)//即使两个结点是祖孙关系，也能找到最近的公共祖先
		return left;
	else
		return right;

	return NULL;//leetcode中必须加这句代码，它说结点可能不在这棵二叉树中
}
void test_Con_ancestor()
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

	TreeNode *tmp = Con_ancestor(head1, head4, head8);
	cout << tmp->val << endl;
}

//2.求二叉树的镜像
void MirrorTree(TreeNode *root)//递归写法
{
	if (!root)return;

	swap(root->left, root->right);

	MirrorTree(root->left);
	MirrorTree(root->right);
}
void test_MirrorTree()
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

	MirrorTree(head1);
	cout << "hah" << endl;
}

//3.求二叉树中最远的两个结点的距离（姑且定义“距离”为两个节点之间边的个数）
//情况A: 路径经过左子树的最深节点，通过根节点，再到右子树的最深节点。
//情况B : 路径不穿过根节点，而是左子树或右子树的最大距离路径，取其大者
//	  对于情况A来说，只需要知道左右子树的深度，然后加起来即可。
//	  对于情况B来说，需要知道左子树的最远距离，右子树的最远距离。
//而我们要求的二叉树的最大距离其实就是求：肯定是某个节点左子树的高度加上右子树的高度加2，
//所以求出每个节点左子树和右子树的高度，取左右子树高度之和加2的最大值即可，假设空节点的高度为 - 1
pair<int, int> _Distance_TwoFarNode(TreeNode *root)
{
	if (!root)return make_pair(-1, -1); //<distance,height>

	pair<int, int> left = _Distance_TwoFarNode(root->left);//左子树的最大距离和最大高度
	pair<int, int> right = _Distance_TwoFarNode(root->right);//右子树的最大距离和最大高度

	int left_dis = left.first, left_hei = left.second;
	int right_dis = right.first, right_hei = right.second;

	int max_dis = left_dis > right_dis ? left_dis : right_dis;//比较左右子树的距离那个更大些
	if (max_dis < left_hei + right_hei + 2)
		max_dis = left_hei + right_hei + 2;//左右子树的最大距离与根的最大距离进行比较
	int max_hei = left_hei > right_hei ? left_hei + 1 : right_hei + 1;//求出根的高度

	return make_pair(max_dis, max_hei);//返回root的最大距离和最大高度
}
int Distance_TwoFarNode(TreeNode *root)
{
	return _Distance_TwoFarNode(root).first;
}
void test_Distance_TwoNode()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	//最大长度通过根的树
	//head1->_left = head2; head1->_right = head3;//根
	//head2->_left = head4;//左子树
	//head4->_right = head7;
	//head3->_left = head5; head3->_right = head6;//右子树
	//head6->_left = head8;
	//最大距离不通过根的树
	head1->left = head2; head1->right = head3;//根
	head2->left = head4; head2->right = head7;
	head4->left = head5;
	head7->right = head8;

	cout << Distance_TwoFarNode(head1) << endl;
}

//4.判断一棵树书否是完全二叉树
#include<queue>
bool IsFullBinaryTree(TreeNode *root)
{
	queue<TreeNode*> q;
	if (root)
		q.push(root);

	TreeNode *cur;
	while (!q.empty())
	{
		cur = q.front(); q.pop();

		if (cur == NULL)break;
		q.push(cur->left);//不需要判空，cur为空的话不会走到这里
		q.push(cur->right);
	}
	while (!q.empty() && q.front() == NULL)
		q.pop();

	return q.empty() ? true : false;
}
void test_IsFullBinaryTree()
{
	TreeNode *head1 = new TreeNode(1);
	TreeNode *head2 = new TreeNode(2);
	TreeNode *head3 = new TreeNode(3);
	TreeNode *head4 = new TreeNode(4);
	TreeNode *head5 = new TreeNode(5);
	TreeNode *head6 = new TreeNode(6);
	TreeNode *head7 = new TreeNode(7);
	TreeNode *head8 = new TreeNode(8);
	////一棵非完全树
	//head1->_left = head2; head1->_right = head3;//根
	//head2->_left = head4;//左子树
	//head4->_right = head7;
	//head3->_left = head5; head3->_right = head6;//右子树
	//head6->_left = head8;
	//一棵完全树
	head1->left = head2; head1->right = head3;//根
	head2->left = head4; head2->right = head5;//左子树
	head4->left = head8;
	head3->left = head6; head3->right = head7;//右子树

	cout << IsFullBinaryTree(head1) << endl;
}

//5.由前序遍历和中序遍历重建二叉树
//剑指offfer题4：输入某二叉树的前序遍历和中序遍历的结果，重建该二叉树。
//    思路一：递归             思路二：非递归（没写出来）
#include<vector>
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

//6.由后序遍历和中序遍历重建二叉树
TreeNode *ReConstructBinaryTree2(vector<int> vin, vector<int> post)
{
	if (post.empty())return NULL;

	vector<int> leftvin; vector<int> rightvin;
	vector<int> leftpost; vector<int> rightpost;

	int i = post.size() - 1, j = vin.size() - 1;
	TreeNode *root = new TreeNode(post[i--]);
	while (post[post.size() - 1] != vin[j--])
	{
		rightpost.push_back(post[i--]);//①讲道理，这里应该用头插
		rightvin.push_back(vin[j + 1]);//②
	}
	int m = 0, n = rightpost.size() - 1;
	while (m < n)//该循环对①②进行补救，即将rightpost和rightvin逆序
	{
		swap(rightpost[m], rightpost[n]);
		swap(rightvin[m++], rightvin[n--]);
	}
	while (i >= 0)
	{
		leftpost.push_back(post[i--]);//③
		leftvin.push_back(vin[j--]);//④
	}
	m = 0; n = leftpost.size() - 1;
	while (m < n)//该循环对③④进行补救，即将leftpost和leftvin逆序
	{
		swap(leftpost[m], leftpost[n]);
		swap(leftvin[m++], leftvin[n--]);
	}
	root->left = ReConstructBinaryTree2(leftvin, leftpost);
	root->right = ReConstructBinaryTree2(rightvin, rightpost);

	return root;
}
void test_ReConstructBinaryTree2()
{
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	vector<int> post = { 7, 4, 2, 5, 8, 6, 3, 1 };
	TreeNode *root;
	root = ReConstructBinaryTree2(vin, post);//递归方法             非递归方法没写
	cout << "由中序和后序重建" << endl;
}

//7.将一棵二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点。
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
void test_TreeToLink()
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

void test_LinkList()
{
	//test_Con_ancestor();//1 已测
	//test_MirrorTree();//2  已测
	//test_Distance_TwoNode();//3  已测
	//test_IsFullBinaryTree();//4  已测
	//test_offer4();//5  已测
	//test_ReConstructBinaryTree2();//6  已测
	//test_TreeToLink();//7  已测
}