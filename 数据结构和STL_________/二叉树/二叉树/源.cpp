#include"bintree.h"

void test1()
{
	int arr[20] = { 1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0 };
	Bintree* b1 = NULL;
	b1 = CreateBinaryTree(arr, 20, 0);//����һ����
	Preorder(b1);//1245367  //ǰ��������Ҵ�ӡ
	cout << endl;
	Inorder(b1);//4251637  //����������Ҵ�ӡ
	cout << endl;
	////Postorder(b1);//4526731  //����������Ҵ�ӡ
	////cout << endl;
	int child_arr[10] = { 1, 2, 0, 0, 3, 0, 0 };
	Bintree* child = NULL;
	child = CreateBinaryTree(child_arr, 10, 0);//����һ������
	Preorder(child);
	cout << endl;

	//Bintree *pos = NULL;
	//pos = Find(b1,3);//Ѱ�������Ƿ����ֵΪ3�Ľڵ㣬�����ڷ���ָ��ýڵ��ָ�룬���򷵻�NULL
	//printf("%d\n", pos->_data);
	////Assign(b1, pos, 10);//������posָ��Ľڵ㸳ֵ
	////Preorder(b1);//1245367
	////cout << endl;
	////pos = Root(b1);//�������ڣ�����ָ���������ָ�룬���򷵻�NULL
	////printf("%p\n%p\n", pos,b1);
	////Destroy_tree(b1);//����һ����
	////printf("%d\n", Isempty(b1));
	////Deletechild(b1, pos, 'r');//ɾ��posָ��Ľڵ�����������
	////Preorder(b1);

	//Insertchild(b1, child, pos, 'r');
	//Preorder(b1);

}

void test2()
{
	int arr[20] = { 1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0 };
	Bintree* b1 = NULL;
	b1 = CreateBinaryTree(arr, 20, 0);//����һ����
	//Inorder(b1);//4251637  //����������Ҵ�ӡ
	//cout << endl;
	Preorder3(b1);//�ǵݹ�ǰ�����
	Preorder_count(b1, 3);//�����������е�k��λ�õĽ���ֵ
	Pre_leaves_cnt(b1);//�����������Ҷ�ӽ�����Ŀ

	//Pre_lr_change(b1);//�������������н������������໥����
	//Preorder3(b1);//�ǵݹ�ǰ�����
	//Pre_deletex_child(b1,3);
	
	Bintree* t = NULL;Bintree* t2 = NULL;
	Pre_copy_trees(t, b1);//�ݹ��㷨����һ�ö�����
	Preorder(t);//�ݹ�ǰ�����
	Pre_copy_trees2(t2,b1);//�ǵݹ��㷨����һ�ö�����
	Preorder(t2);//�ݹ�ǰ�����

}

int main()
{
	test2();
	system("pause");
	return 0;
}

//Bintree b1 = BuyNode(1);//�ٺ٣����ֹ�����һ����
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