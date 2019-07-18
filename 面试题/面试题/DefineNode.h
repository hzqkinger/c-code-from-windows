#pragma once

struct FlistNode
{
	int val;
	FlistNode *next;
	FlistNode(const int x) :val(x), next(0){}
};
struct ListNode
{
	int val;
	ListNode *prev;
	ListNode *next;
	ListNode(const int x) :val(x), prev(0), next(0){}
};
struct RondomListNode
{
	int val;
	RondomListNode *next;
	RondomListNode *rand;
	RondomListNode(const int x) :val(x), next(0), rand(0){}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(const int x) :val(x), left(0), right(0){}
};
struct TreeThreeLinkNode
{
	int val;
	TreeThreeLinkNode *left;
	TreeThreeLinkNode *right;
	TreeThreeLinkNode *parent;
	TreeThreeLinkNode(const int x) :val(x), left(0), right(0),parent(0){}
};