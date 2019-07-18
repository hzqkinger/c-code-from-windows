#pragma once
#include<queue>

#define MAX_VERTEX_NUM 20

typedef char InfoType;
typedef int VertexType;//顶点类型

typedef enum{DG2,UDG2}GrapKind; //DG是有向图，UDG是无向图
typedef struct ArcNode
{
	int adjvex;                 //该弧所指向的顶点的位置
	struct ArcNode *nextarc;    //指向下一条弧的指针
	InfoType *info;             //该弧相关信息的指针（估计都会指向NULL，因为不知道有啥相关信息）
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
	int kind;          //图的种类标志
}ALGraph;

bool visited[MAX_VERTEX_NUM];
//深度优先遍历(递归方法)           //下次再实现非递归方法
void DFS(ALGraph &G, size_t v)
{
	visited[v] = true;
	printf("%3d", G.vertices[v].data);//访问下标为v的顶点数据信息

	ArcNode *arc = G.vertices[v].firstarc;
	while (arc)//假如弧arc不为空，表明G.vertices[v]还有其他的弧
	{
		if (!visited[arc->adjvex])DFS(G, arc->adjvex);//如果边表结点没有被访问过,则递归调用DFS 

			arc = arc->nextarc;//arc被赋值为G.vertices[v]的下一条弧
	}
}
void DFSTraverse(ALGraph &G)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)visited[i] = false;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (!visited[i]) //选取一个未访问过的顶点进行深度优先遍历, 如果是连通图，在这个函数里DFS只执行一次
			DFS(G, i);
	}
	printf("\n");
}
//广度优先遍历
void BFSTraverse(ALGraph &G)
{
	int i;
	queue<VNode*> q;
	for (i = 0; i < G.vexnum; ++i)visited[i] = false;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (!visited[i])//选取一个未访问过的顶点进行广度优先遍历，如果是连通图，只会进入该if语句一次
		{
			q.push(G.vertices + i);
			visited[i] = true;

			while (!q.empty())
			{
				ArcNode *arc = q.front()->firstarc;
				printf("%3d", q.front()->data);//访问将要出队列的VNode的数据信息
				q.pop();

				while (arc)
				{
					if (!visited[arc->adjvex])
					{
						q.push(G.vertices + arc->adjvex);
						visited[arc->adjvex] = true;
					}
					arc = arc->nextarc;
				}
			}
		}
	}
	printf("\n");
}


//说明：①构造无向图和有向图的代码99%是相同的（仅仅在flag处不同而已）
//      ②还有就是在构造有向图和无向图时，调用了深度广度遍历，方便让我一构造出来这个图就遍历
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
	}

	for (i = 0; i < G.vexnum; ++i)//给vertices数组的每一个顶点建立一个链表
	{
		ArcNode *prev = NULL;
		printf("请输入第%d个顶点有几条弧：\n", i + 1);//flag(不同处)
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
			printf("请输入第%d条弧指向的结点在顶点向量的下标位置：\n", j + 1);
			scanf("%d", &arc->adjvex);//弧结点里adjvex存储该弧所指向的顶点结点在顶点向量中的下标
		}
		printf("\n");
	}

	printf("打印数据：\n");
	for (i = 0; i < G.vexnum; ++i)
	{
		printf("%3d", G.vertices[i].data);
		ArcNode *prev = G.vertices[i].firstarc;
		while (prev)
		{
			printf("%3d", G.vertices[prev->adjvex].data);
			prev = prev->nextarc;
		}
		printf("\n");
	}

	printf("深度优先遍历：\n");
	DFSTraverse(G);//深度优先搜索
	printf("广度优先遍历：\n");
	BFSTraverse(G);
}
void CreatUDG2(ALGraph &G)//构造有向图
{
	size_t i, j;
	printf("输入顶点个数和弧的条数\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("请依次输入%d顶点的值\n", G.vexnum);//先将顶点向量的data赋值，指针firstarc = NULL
	for (i = 0; i < G.vexnum; ++i)
	{
		scanf("%d", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}

	for (i = 0; i < G.vexnum; ++i)//给vertices数组的每一个顶点建立一个链表
	{
		ArcNode *prev = NULL;
		printf("请输入第%d个顶点的出度：\n", i + 1);//flag(不同处)
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
			printf("请输入第%d条弧指向的结点在顶点向量的下标位置：\n", j + 1);
			scanf("%d", &arc->adjvex);//弧结点里adjvex存储该弧所指向的顶点结点在顶点向量中的下标
		}
		printf("\n");
	}

	printf("打印数据：\n");
	for (i = 0; i < G.vexnum; ++i)
	{
		printf("%3d", G.vertices[i].data);
		ArcNode *prev = G.vertices[i].firstarc;
		while (prev)
		{
			printf("%3d", G.vertices[prev->adjvex].data);
			prev = prev->nextarc;
		}
		printf("\n");
	}
	printf("深度优先遍历：\n");
	DFSTraverse(G);//深度优先搜索
	printf("广度优先遍历：\n");
	BFSTraverse(G);
}


void CreatALGraph(ALGraph &G)
{
	printf("*****************************************\n");
	printf("***   0.构造无向图      1.构造有向图  ***\n");
	printf("***   2.退出程序                      ***\n");
	printf("*****************************************\n");

	while (1)
	{
		printf("请输入选项0、1、2\n");
		scanf("%d", &G.kind);
		if (G.kind == 2)break;
		switch (G.kind)
		{
		case DG2:
			CreatDG2(G);
			break;
		case UDG2:
			CreatUDG2(G);
			break;
		default:
			break;
		}
	}
}

void test2()
{
	ALGraph G;
	CreatALGraph(G);

}