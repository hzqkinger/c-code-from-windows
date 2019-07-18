#define _CRT_SECURE_NO_WARNINGS
#include<CoreWindow.h>
#include<iostream>
using namespace std;

#include"threadbintree.h"

void test()
{
	int arr[20] = { 1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0 };
	Bintree* b1 = NULL;
	b1 = CreateBinaryTree(arr, 20, 0);//ππ‘Ï“ªø√ ˜
	Inorder(b1);
	cout << endl;
	Bintree* b2 = Inorderthreading(b1);
	Inorderthread(b2);
	//Bintree *b = CreaThread(b1);
	//ThInOrder(b1);

}

int main()
{
	test();

	system("pause");
	return 0;
}