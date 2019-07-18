#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h> 
#include<assert.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<CoreWindow.h>
typedef int DataType;
typedef struct List
{
	DataType data;
	struct List* next;
}ListNode;
ListNode *BuyNode(DataType x);
void PrintList(ListNode* pList);
void PushBack(ListNode** ppList, DataType x);
void PopBack(ListNode** ppList);
void PushFront(ListNode** ppList, DataType x);
void PopFront(ListNode** ppList);
ListNode* Find(ListNode* pList, DataType x);
// 在pos的前面插入一个节点x 
void Insert(ListNode** ppList, ListNode* pos, DataType x);
void Erase(ListNode** ppList, ListNode* pos);

ListNode*BuyNode(DataType x)
{
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	return node;
}
void PrintList(ListNode* pList)
{
	while (pList)
	{
		//sleep(1);
		printf("%3d", pList->data);
		pList = pList->next;
	}
	printf("\n");
}
void PushBack(ListNode** ppList, DataType x)
{
	ListNode *cur = *ppList;
	ListNode* node = BuyNode(x);
	if (*ppList == NULL)
		*ppList = node;//让头指针指向第一个节点
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = node;
	}
	node->next = NULL;
}
void PopBack(ListNode** ppList)
{
	ListNode *prev = *ppList;
	ListNode *cur = NULL;
	if (*ppList == 0)
		return;
	cur = prev->next;
	while (cur->next)
	{
		prev = cur;
		cur = prev->next;
	}
	prev->next = NULL;
	free(cur);
	cur = NULL;
}
void PushFront(ListNode** ppList, DataType x)
{
	ListNode* node = BuyNode(x);
	node->next = *ppList;
	*ppList = node;
}
void PopFront(ListNode** ppList)
{
	ListNode *cur = *ppList;
	if (*ppList == 0)
		return;
	*ppList = cur->next;
	free(cur);
	cur = NULL;
}
ListNode* Find(ListNode* pList, DataType x)
{
	while (pList && pList->data != x)
		pList = pList->next;
	return pList;
}
// 在pos的前面插入一个节点x 
void Insert(ListNode** ppList, ListNode* pos, DataType x)
{
	ListNode *cur = *ppList,*node = NULL;
	if (*ppList == NULL)
		return;
	while (cur->next != pos)
		cur = cur->next;
	node = BuyNode(x);
	node->next = cur->next;
	cur->next = node;
}
void Insret1(ListNode** ppList, int i, DataType x)
{//这里我们假定i是合法的
	ListNode*tmp = BuyNode(x);
	if (!*ppList)
	{
		*ppList = tmp;
		return;
	}
	ListNode*pos = *ppList;
	while (i-- > 2)
		pos = pos->next;
	tmp->next = pos->next;
	pos->next = tmp;
}
void Erase(ListNode** ppList, ListNode* pos)
{
	ListNode *cur = *ppList;
	if (pos == NULL || *ppList == NULL)
		return;
	while (cur->next != pos)
		cur = cur->next;
	cur->next = pos->next;
	free(pos);
	pos = NULL;
}
void Erase1(ListNode** ppList, int i)
{//这里我们假定i是合法的
	assert(*ppList);
	ListNode*prev = *ppList,*cur = prev->next;
	while (i-- > 2)
	{
		prev = prev->next;
		cur = cur->next;
	}
	prev->next = cur->next;
	free(cur);
}
//1.比较顺序表和链表的优缺点，说说它们分别在什么场景下使用？
//2.从尾到头打印单链表
void PrintBack_toFront(ListNode* pList)
{
	if (!pList)
		return;
	PrintBack_toFront(pList->next);
	printf("%3d", pList->data);
}
//3.删除一个无头单链表的非尾节点
void Erase_noHeadList(ListNode* node)
{
	ListNode *tmp = node->next;
	assert(node&&node->next);
	node->next = tmp->next;
	node->data = tmp->data;
	free(tmp);
	tmp = NULL;
}
//4.在无头单链表的一个节点前插入一个节点
void Insert_noHeadList(ListNode* node,DataType x)
{
	ListNode *tmp;
	DataType temp;
	tmp = BuyNode(x);
	tmp->next = node->next;
	node->next = tmp;
	temp = node->data, node->data = tmp->data, tmp->data = temp;
}
//5.单链表实现约瑟夫环
ListNode* joseph(ListNode* plist, int m)
{
	int tmp1;
	ListNode *tmp = NULL,*node = plist->next;
	assert(plist);
	while (node != node->next)
	{
		tmp1 = m;
		while (--tmp1)
			node = node->next;
		tmp = node->next;
		node->next = tmp->next;
		node->data = tmp->data;
		free(tmp);
	}
	return node;
}
//6.逆置 / 反转单链表
void Invert(ListNode** ppList)
{
	ListNode *n0 ,*n1, *n2;
	if (!*ppList)
		return;
	n1 = *ppList, n0 = NULL, n2 = n1->next;
	while (n1)
	{
		n1->next = n0;
		n0 = n1;
		n1 = n2;
		if (n2)
			n2 = n2->next;
	}
	*ppList = n0;
}
//7.单链表排序（冒泡排序&快速排序）
void BubbleSort(ListNode*ppList)
{
	ListNode*cur, *last, *tail = NULL;
	if (!ppList&&!ppList->next)
		return;
	cur = ppList, last = cur->next;
	while (cur->next != tail)
	{
		while (cur->next != tail)
		{
			if (cur->data > last->data)
			{
				DataType tmp;
				tmp = cur->data;
				cur->data = last->data;
				last->data = tmp;
			}
			cur = cur->next;
			last = last->next;
		}
		tail = cur;
		cur = ppList, last = cur->next;
	}



}
//8.合并两个有序链表, 合并后依然有序
ListNode* MergeList(ListNode*pList1, ListNode*pList2)
{
	ListNode*newhead = NULL,*tmp = NULL;
	if (!pList1)
		return pList2;
	if (!pList2)
		return pList1;
	while (pList1&&pList2)
	{
		if (pList1->data < pList2->data)
		{
			PushBack(&newhead, pList1->data);
			pList1 = pList1->next;
		}
		else
		{
			PushBack(&newhead, pList2->data);
			pList2 = pList2->next;
		}
	}
	tmp = newhead;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (pList1 == NULL)
		tmp->next = pList2;
	else
		tmp->next = pList1;
	return newhead;

}
//9.查找单链表的中间节点，要求只能遍历一次链表
ListNode*FindMid_node(ListNode*ppList)
{
	ListNode*slow = ppList, *fast = ppList;
	if (!ppList&&!ppList->next&&!ppList->next->next)
		return ppList;
	while (fast->next&&fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//10.查找单链表的倒数第k个节点，要求只能遍历一次链表
ListNode*Find_kback_node(ListNode*ppList,int k)
{
	ListNode*slow = ppList, *fast = ppList;
	while (k--&&fast)
		fast = fast->next;
	if (fast == NULL)
		return NULL;
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}


//1.判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。
ListNode* IsCircle(ListNode*ppList)
{
	assert(ppList);
	ListNode*fast = ppList, *slow = ppList;
	if (!ppList->next&&!ppList->next->next)
		return NULL;
	slow = ppList->next;
	fast = ppList->next->next;
	while (fast&&fast != slow)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (!fast)
		return NULL;
	else
		return slow;
}
void CircleLength(ListNode*pos)
{
	ListNode*tmp = pos->next;
	int length = 1;
	while (tmp != pos)
	{
		tmp = tmp->next;
		length++;
	}
	printf("%3d\n", length);
}
ListNode*CircleEnter(ListNode*ppList,ListNode*pos)
{
	ListNode*head = ppList,*node = pos;
	while (head != node)
	{
		head = head->next;
		node = node->next;
	}
	return head;
}
//2.判断两个链表是否相交，若相交，求交点。（假设链表不带环）
ListNode* IsCrossline(ListNode*head1,ListNode*head2)
{
	ListNode*longlist = head1, *shortlist = head2;
	int count1 = 0, count2 = 0,cnt = 0;
	while (longlist)
	{
		count1++;
		longlist = longlist->next;
	}
	while (shortlist)
	{
		count2++;
		shortlist = shortlist->next;
	}
	longlist = head1, shortlist = head2;
	if (count1 < count2)
	{
		ListNode*tmp = longlist;
		longlist = shortlist;
		shortlist = tmp;
	}
	cnt = abs(count1 - count2);
	while (cnt--)
		longlist = longlist->next;
	while (longlist != shortlist)
	{
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return shortlist;
}
//3.判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】
//ListNode* IsCirl_WihCir(ListNode*head1, ListNode*head2,ListNode*enter1,ListNode*enter2)
//{
//	ListNode*longlist = head1, *shortlist = head2;
//	int count1 = 0, count2 = 0, cnt = 0;
//	while (longlist != enter1 )
//	{
//		count1++;
//		longlist = longlist->next;
//	}
//	while (shortlist != enter2)
//	{
//		count2++;
//		shortlist = shortlist->next;
//	}
//	longlist = head1, shortlist = head2;
//	if (count1 < count2)
//	{
//		ListNode*tmp = longlist;
//		longlist = shortlist;
//		shortlist = tmp;
//	}
//	cnt = abs(count1 - count2);
//	while (cnt--)
//		longlist = longlist->next;
//	while (longlist != shortlist)
//	{
//		longlist = longlist->next;
//		shortlist = shortlist->next;
//	}
//	return shortlist;
//}
//ListNode*IsCrossline_WithCircle(ListNode*head1, ListNode*head2)
//{
//	ListNode*tailenter1, *tailenter2;
//	ListNode*incircle1, *incircle2;
//	if (!(incircle1 = IsCircle(head1)) && !(incircle2 = IsCircle(head2)))
//		return NULL;
//	tailenter1 = CircleEnter(head1, incircle1);
//	tailenter2 = CircleEnter(head2, incircle2);
//	if (tailenter1 == incircle2)
//		return tailenter1;//或者返回tailenter2
//	if (tailenter1 == tailenter2)
//		return IsCirl_WihCir(head1, head2, tailenter1, tailenter2);
//	
//}

//4.复杂链表的复制。一个链表的每个节点，有一个指向next指针指向下一个节点，
//还有一个random指针指向这个链表中的一个随机节点或者NULL，现在要求实现复制这个链表，
//返回复制后的新链表。
////ps: 复杂链表的结构 
//struct ComplexNode
//{
//	int _data; // 数据 
//	struct ComplexNode * _next; // 指向下一个节点的指针 
//	struct ComplexNode * _random; // 指向随机节点（可以是链表中的任意节点 or 空） 
//};

//求两个单链表的交集和差集

//2.16从表la中删除自第i1个元素，将它们插入到表lb中第j1个元素之前。
void LinkList(ListNode**la, ListNode**lb, int i1, int j1)
{//先考虑i和j都是合法的
	assert(la);
	assert(lb);
	ListNode*prev1 = *la, *cur1 = prev1->next;
	ListNode*prev2 = *lb, *cur2 = prev2->next;
	while (i1-- > 2)
	{
		prev1 = prev1->next;
		cur1 = cur1->next;
	}
	while (j1-- > 2)
	{
		prev2 = prev2->next;
		cur2 = cur2->next;
	}
	prev1->next = NULL;
	prev2->next = cur1;
	while (cur1->next)
		cur1 = cur1->next;
	cur1->next = cur2;
}

int main()
{
	ListNode  *node = NULL,*pos = NULL;
	ListNode*node2 = NULL,*pos2 = NULL;
	ListNode *head1 = NULL, *head2 = NULL, *tail = NULL;
	PushBack(&head1, 1);
	PushBack(&head1, 2);
	PushBack(&head1, 3);
	PushBack(&head1, 4);
	PushBack(&head1, 5);
	PushBack(&head1, 6);
	PrintList(head1);



	//PushBack(&head2, 3);
	//PushBack(&head2, 7);
	//node2 = Find(head2, 7);
	//node = Find(head1, 4);
	//node2->next = node;
	//pos = IsCrossline(head1, head2);
	//if (pos)
	//	printf("%3d\n", pos->data);
	//else
	//	printf("not cross!\n");

	//node = Find(head1, 4);
	//tail = Find(head1, 6);
	//tail->next = node;
	//pos = IsCircle(head1);
	///*printf("%3d\n", pos->data);
	//CircleLength(pos);*/
	//pos2 = CircleEnter(head1, pos);
	//printf("%3d\n", pos2->data);

	/*node = Find_kback_node(head1, 3);
	printf("%3d\n", node->data);*/
	//PushBack(&head2, 2);
	//PushBack(&head2, 4);
	//PushBack(&head2, 7);
	//PrintList(head2);

	//tail = Find(head, 5);
	//tail->next = head;
	//node = joseph(head,4);
	//printf("%3d\n", node->data);

	//node = MergeList(head1,head2);
	//PrintList(node);

	system("pause");
	return;
}