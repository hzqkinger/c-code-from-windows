#pragma once
#include"DefineNode.h"

//struct Node{struct Node *_next;int _i/*0<=_i<+9*/;}��
//�ж�һ���������д洢���������������һ���ǲ���һ��������
#include<stack>
bool test1(FlistNode*head)//�����head��û�п�
{
	std::stack<int> s;//����һ:��Ҫ����n���ռ�
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
	std::stack<int> s2;//������:��Ҫ����n/2���ռ�
	FlistNode *slow = head, *fast = head;
	while (fast->next){
		slow = slow->next;//��ָ����һ��
		fast = fast->next; if (fast->next)fast = fast->next;//��ָ��������
	}
	while (slow->next){//����ָ��ָ��Ԫ�صĺ�һ����㿪ʼһֱѹջ
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
	FlistNode *slow2 = head, *fast2 = head; bool flag = false;//������,ֻ��Ҫ����ָ�����
	while (fast2->next){
		slow2 = slow2->next;//��ָ����һ��
		fast2 = fast2->next; if (fast2->next)fast2 = fast2->next;//��ָ��������
	}
	FlistNode *prev = nullptr, *cur = slow2, *next = cur->next;//��ָ�����
	while (cur){
		cur->next = prev; prev = cur; cur = next;
		if (next)next = next->next;
	}
	prev = head, next = fast2;
	while (prev && next){//�ж��ǲ��ǻ���
		if (prev->val == next->val){ prev = prev->next; next = next->next; }
		else break;
	}
	if (!(prev && next))flag = true;
	prev = nullptr; cur = fast2; next = cur->next;
	while (cur){//���ָ��Ļ���
		cur->next = prev; prev = cur; cur = next;
		if (next)next = next->next;
	}
	return flag;
}

//struct Node{struct Node *_next;struct Node *_random;int _i;}
//���������ĸ���
RondomListNode* test2(RondomListNode *head)
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

//7.1.1 ��һ�ö���������ת������������
//         ����һ���ö���    ���������õݹ��
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
TreeNode *big(TreeNode *root)//�õݹ�
{
	TreeNode *rights = _big(root);
	TreeNode *head = rights->right;
	rights->right = NULL;

	return head;
}

//7.1.2 ɾ���������е�һ����β�ڵ�
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

//1.���������������������
//ps:�ٸö�����Ϊ����������(�õ�ǰ������������Ƚϣ����ȵ�ǰ���С�������������������������)
//   �ڸö�������ָ���׵�ָ��(����Ŀ˲��ת��Ϊ���������浥�������)
//   �۸ö�����Ϊ��ͨ�Ķ�����(1.�������������飻2.�����õݹ����)
TreeNode* Con_ancestor(TreeNode *root, const TreeNode *x, const TreeNode *y)//�ݹ�д��
{
	if (!root || !x || !y)return NULL;//������㶼����Ϊ��

	if (root == x || root == y)return root;

	TreeNode *left = Con_ancestor(root->left, x, y);
	TreeNode *right = Con_ancestor(root->right, x, y);

	if (left && right)//ֻ�����Ҷ���Ϊ��ʱ��root��Ϊ�������������������
		return root;

	if (left)//��ʹ��������������ϵ��Ҳ���ҵ�����Ĺ�������
		return left;
	else
		return right;

	return NULL;//leetcode�б���������룬��˵�����ܲ�����ö�������
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
	head1->left = head2; head1->right = head3;//��
	head2->left = head4;//������
	head4->right = head7;
	head3->left = head5; head3->right = head6;//������
	head6->left = head8;

	TreeNode *tmp = Con_ancestor(head1, head4, head8);
	cout << tmp->val << endl;
}

//2.��������ľ���
void MirrorTree(TreeNode *root)//�ݹ�д��
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
	head1->left = head2; head1->right = head3;//��
	head2->left = head4;//������
	head4->right = head7;
	head3->left = head5; head3->right = head6;//������
	head6->left = head8;

	MirrorTree(head1);
	cout << "hah" << endl;
}

//3.�����������Զ���������ľ��루���Ҷ��塰���롱Ϊ�����ڵ�֮��ߵĸ�����
//���A: ·������������������ڵ㣬ͨ�����ڵ㣬�ٵ�������������ڵ㡣
//���B : ·�����������ڵ㣬��������������������������·����ȡ�����
//	  �������A��˵��ֻ��Ҫ֪��������������ȣ�Ȼ����������ɡ�
//	  �������B��˵����Ҫ֪������������Զ���룬����������Զ���롣
//������Ҫ��Ķ���������������ʵ�����󣺿϶���ĳ���ڵ��������ĸ߶ȼ����������ĸ߶ȼ�2��
//�������ÿ���ڵ����������������ĸ߶ȣ�ȡ���������߶�֮�ͼ�2�����ֵ���ɣ�����սڵ�ĸ߶�Ϊ - 1
pair<int, int> _Distance_TwoFarNode(TreeNode *root)
{
	if (!root)return make_pair(-1, -1); //<distance,height>

	pair<int, int> left = _Distance_TwoFarNode(root->left);//������������������߶�
	pair<int, int> right = _Distance_TwoFarNode(root->right);//������������������߶�

	int left_dis = left.first, left_hei = left.second;
	int right_dis = right.first, right_hei = right.second;

	int max_dis = left_dis > right_dis ? left_dis : right_dis;//�Ƚ����������ľ����Ǹ�����Щ
	if (max_dis < left_hei + right_hei + 2)
		max_dis = left_hei + right_hei + 2;//�����������������������������бȽ�
	int max_hei = left_hei > right_hei ? left_hei + 1 : right_hei + 1;//������ĸ߶�

	return make_pair(max_dis, max_hei);//����root������������߶�
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
	//��󳤶�ͨ��������
	//head1->_left = head2; head1->_right = head3;//��
	//head2->_left = head4;//������
	//head4->_right = head7;
	//head3->_left = head5; head3->_right = head6;//������
	//head6->_left = head8;
	//�����벻ͨ��������
	head1->left = head2; head1->right = head3;//��
	head2->left = head4; head2->right = head7;
	head4->left = head5;
	head7->right = head8;

	cout << Distance_TwoFarNode(head1) << endl;
}

//4.�ж�һ�����������ȫ������
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
		q.push(cur->left);//����Ҫ�пգ�curΪ�յĻ������ߵ�����
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
	////һ�÷���ȫ��
	//head1->_left = head2; head1->_right = head3;//��
	//head2->_left = head4;//������
	//head4->_right = head7;
	//head3->_left = head5; head3->_right = head6;//������
	//head6->_left = head8;
	//һ����ȫ��
	head1->left = head2; head1->right = head3;//��
	head2->left = head4; head2->right = head5;//������
	head4->left = head8;
	head3->left = head6; head3->right = head7;//������

	cout << IsFullBinaryTree(head1) << endl;
}

//5.��ǰ���������������ؽ�������
//��ָofffer��4������ĳ��������ǰ���������������Ľ�����ؽ��ö�������
//    ˼·һ���ݹ�             ˼·�����ǵݹ飨ûд������
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
	root = ReConstructBinaryTree(pre, vin);//�ݹ鷽��             �ǵݹ鷽��ûд
	cout << "��ǰ��������ؽ�" << endl;
}

//6.�ɺ����������������ؽ�������
TreeNode *ReConstructBinaryTree2(vector<int> vin, vector<int> post)
{
	if (post.empty())return NULL;

	vector<int> leftvin; vector<int> rightvin;
	vector<int> leftpost; vector<int> rightpost;

	int i = post.size() - 1, j = vin.size() - 1;
	TreeNode *root = new TreeNode(post[i--]);
	while (post[post.size() - 1] != vin[j--])
	{
		rightpost.push_back(post[i--]);//�ٽ���������Ӧ����ͷ��
		rightvin.push_back(vin[j + 1]);//��
	}
	int m = 0, n = rightpost.size() - 1;
	while (m < n)//��ѭ���Ԣ٢ڽ��в��ȣ�����rightpost��rightvin����
	{
		swap(rightpost[m], rightpost[n]);
		swap(rightvin[m++], rightvin[n--]);
	}
	while (i >= 0)
	{
		leftpost.push_back(post[i--]);//��
		leftvin.push_back(vin[j--]);//��
	}
	m = 0; n = leftpost.size() - 1;
	while (m < n)//��ѭ���Ԣۢܽ��в��ȣ�����leftpost��leftvin����
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
	root = ReConstructBinaryTree2(vin, post);//�ݹ鷽��             �ǵݹ鷽��ûд
	cout << "������ͺ����ؽ�" << endl;
}

//7.��һ�ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㡣
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

void test_LinkList()
{
	//test_Con_ancestor();//1 �Ѳ�
	//test_MirrorTree();//2  �Ѳ�
	//test_Distance_TwoNode();//3  �Ѳ�
	//test_IsFullBinaryTree();//4  �Ѳ�
	//test_offer4();//5  �Ѳ�
	//test_ReConstructBinaryTree2();//6  �Ѳ�
	//test_TreeToLink();//7  �Ѳ�
}