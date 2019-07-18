#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

#include"Graph_arr.h"//邻接矩阵（有向图，无向图，有向网，无向网）
#include"adjacency_li.h"//邻接表：邻接表是图的一种链式存储结构（有向图，无向图）

//下面两个还未完成
#include"OrthogonalList.h"//十字链表：是有向图的一种链式存储结构
#include"AdjacencyMultilist.h"//邻接多重表：是无向图的一种链式存储结构

int main()
{
	//test();//测试邻接矩阵
	test2();//测试邻接表
	system("pause");
	return 0;
}