#pragma once

#define MAX_VERTEX_NUM 20
#define Max INT_MAX

//typedef char InfoType;
typedef int VertexType;//顶点类型

typedef struct ArcNode
{
	int adjvex;                 //该弧所指向的顶点的下标位置
	struct ArcNode *nextarc;    //指向下一条弧的指针
	//InfoType *info;             //该弧相关信息的指针（这里可以填写该弧的长度，即权值）
	int weight;
}ArcNode;//弧结点

typedef struct VNode
{
	VertexType data;         //顶点信息
	ArcNode *firstarc;       //指向第一条依附于该顶点的弧的指针
}VNnode, AdjList[MAX_VERTEX_NUM];
//一个顶点结点；存储顶点结点的一维数组

typedef struct
{
	AdjList vertices;  //顶点向量
	int vexnum, arcnum;//图的当前顶点数和弧数
}ALGraph;


void CreatDG2(ALGraph &G)//构造无向图
{
	size_t i, j;
	printf("输入顶点个数和弧的条数\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("请依次输入%d顶点的值\n", G.vexnum);//先将顶点向量的data赋值，指针firstarc = NULL
	for (i = 0; i < G.vexnum; ++i)
	{
		scanf("%d", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
		G.vertices[i].flag = false;
	}

	for (i = 0; i < G.vexnum; ++i)//给vertices数组的每一个顶点建立一个链表
	{
		ArcNode *prev = NULL;
		printf("请输入第%d个顶点有几条弧：\n", i + 1);
		scanf("%d", &j);
		while (j--)
		{
			ArcNode* arc = (ArcNode*)malloc(sizeof(ArcNode));
			arc->nextarc = NULL;
			if (!G.vertices[i].firstarc)
			{
				G.vertices[i].firstarc = arc;
				prev = arc;
			}
			else
			{
				prev->nextarc = arc;
				prev = prev->nextarc;
			}
			printf("请输入第%d条弧指向的结点在顶点向量的下标位置及其权值：\n", j + 1);
			scanf("%d%d", &arc->adjvex,&arc->weight);//弧结点里adjvex存储该弧所指向的顶点结点在顶点向量中的下标
		}
		printf("\n");
	}
}
void print(const ALGraph &G)
{
	int i;
	printf("打印数据：\n");
	for (i = 0; i < G.vexnum; ++i)
	{
		printf("[%d]", G.vertices[i].data);
		ArcNode *prev = G.vertices[i].firstarc;
		while (prev)
		{
			printf("-%d->[%d]", prev->weight,G.vertices[prev->adjvex].data);
			prev = prev->nextarc;
		}
		printf("\n");
	}
}
//MST（Minimum Spanning Tree，最小生成树）问题有两种通用的解法，
//Prim算法就是其中之一，它是从点的方面考虑构建一颗MST，大致思想是：
//   设图G顶点集合为U，首先任意选择图G中的一点作为起始点a，将该点加入集合V，再从集合U - V中找到
//   另一点b使得点b到V中任意一点的权值最小，此时将b点也加入集合V；以此类推，现在的集合V = { a，b }，
//   再从集合U - V中找到另一点c使得点c到V中任意一点的权值最小，此时将c点加入集合V，直至所有顶点全部
//   被加入V，此时就构建出了一颗MST。因为有N个顶点，所以该MST就有N - 1条边，每一次向集合V中加入一个点，
//   就意味着找到一条MST的边


void MinSpanTree_Prim(ALGraph &G,size_t k)
{
	typedef struct
	{
		//VertexType vnode;
		//ArcNode arcnode;
		int adjvex;
		int lowcost;
	}close[MAX_VERTEX_NUM];
	close closedge;
	int i,min;
	ArcNode *cur = G.vertices[k].firstarc;
	for (i = 0; i < G.vexnum; ++i)//初始化辅助数组
	{
		closedge[cur->adjvex].lowcost = Max;
		closedge[cur->adjvex].adjvex = k;
	}
	closedge[k].lowcost = 0;//自己到自己的距离为0
	while (cur)
		closedge[cur->adjvex].lowcost = cur->weight;

	min = closedge[k].lowcost;
	for (i = 0; i < G.vexnum; ++i)//寻找最小的弧
	{
		if (min != 0)
		{
			if (min>closedge[i].lowcost)
				min = closedge[i].lowcost, k = i;
		}
		else
		{
			min = closedge[i].lowcost;
			k = i;
		}
	}

}

void testprimMinimumTree()
{
	ALGraph G;
	CreatDG2(G);
	print(G);
}