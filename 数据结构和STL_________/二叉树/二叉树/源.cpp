#include"bintree.h"

void test1()
{
	int arr[20] = { 1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0 };
	Bintree* b1 = NULL;
	b1 = CreateBinaryTree(arr, 20, 0);//构造一棵树
	Preorder(b1);//1245367  //前序遍历并且打印
	cout << endl;
	Inorder(b1);//4251637  //中序遍历并且打印
	cout << endl;
	////Postorder(b1);//4526731  //后序遍历并且打印
	////cout << endl;
	int child_arr[10] = { 1, 2, 0, 0, 3, 0, 0 };
	Bintree* child = NULL;
	child = CreateBinaryTree(child_arr, 10, 0);//构造一棵子树
	Preorder(child);
	cout << endl;

	//Bintree *pos = NULL;
	//pos = Find(b1,3);//寻找树中是否存在值为3的节点，若存在返回指向该节点的指针，否则返回NULL
	//printf("%d\n", pos->_data);
	////Assign(b1, pos, 10);//给树中pos指向的节点赋值
	////Preorder(b1);//1245367
	////cout << endl;
	////pos = Root(b1);//若树存在，返回指向该树跟的指针，否则返回NULL
	////printf("%p\n%p\n", pos,b1);
	////Destroy_tree(b1);//销毁一棵树
	////printf("%d\n", Isempty(b1));
	////Deletechild(b1, pos, 'r');//删除pos指向的节点的左或右子树
	////Preorder(b1);

	//Insertchild(b1, child, pos, 'r');
	//Preorder(b1);

}

void test2()
{
	int arr[20] = { 1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0 };
	Bintree* b1 = NULL;
	b1 = CreateBinaryTree(arr, 20, 0);//构造一棵树
	//Inorder(b1);//4251637  //中序遍历并且打印
	//cout << endl;
	Preorder3(b1);//非递归前序遍历
	Preorder_count(b1, 3);//求先序序列中第k个位置的结点的值
	Pre_leaves_cnt(b1);//计算二叉树中叶子结点的数目

	//Pre_lr_change(b1);//将二叉树中所有结点的左右子树相互交换
	//Preorder3(b1);//非递归前序遍历
	//Pre_deletex_child(b1,3);
	
	Bintree* t = NULL;Bintree* t2 = NULL;
	Pre_copy_trees(t, b1);//递归算法复制一棵二叉树
	Preorder(t);//递归前序遍历
	Pre_copy_trees2(t2,b1);//非递归算法复制一棵二叉树
	Preorder(t2);//递归前序遍历

}

int main()
{
	test2();
	system("pause");
	return 0;
}

//Bintree b1 = BuyNode(1);//嘿嘿，纯手工制造一棵树
//Bintree b2 = BuyNode(2);
//Bintree b3 = BuyNode(3);
//Bintree b4 = BuyNode(4);
//Bintree b5 = BuyNode(5);
//Bintree b6 = BuyNode(6);
//Bintree b7 = BuyNode(7);
//b1->lchild = b2; b1->rchild = b3;
//b2->lchild = b4; b2->rchild = b5;
//b3->lchild = b6; b3->rchild = b7;
//Preorder(b1);