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
void CreatDG2(ALGraph &G)//构造有向图
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
			printf("请输入第%d条弧指向的结点在顶点向量的下标位置：\n", j + 1);
			scanf("%d", &arc->adjvex);//弧结点里adjvex存储该弧所指向的顶点结点在顶点向量中的下标
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
		printf("[%d]--->", G.vertices[i].data);
		ArcNode *prev = G.vertices[i].firstarc;
		while (prev)
		{
			printf("[%d]", G.vertices[prev->adjvex].data);
			prev = prev->nextarc;
		}
		printf("\n");
	}
}
void FindIndegree(const ALGraph &G, int arr[])//寻找图的所有结点的入度
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		ArcNode *prev = G.vertices[i].firstarc;
		while (prev)
		{
			arr[prev->adjvex] += 1;
			prev = prev->nextarc;
		}
	}
}
void TopologicalSort(const ALGraph &G, int arr[])
{
	FindIndegree(G, arr);
	int i, j = G.vexnum;
	printf("拓扑排序序列为：\n");
	while (j--)
	{
		for (i = 0; i < G.vexnum; ++i)
		{
			if (!arr[i])
			{
				printf("%3d", G.vertices[i].data);//输出顶点结点信息，
	    		arr[i] = -1;//然后将该顶点结点的入度置为-1
				ArcNode *prev = G.vertices[i].firstarc;
				while (prev)//将G.vertices[i]的弧指向的顶点结点的度减1
				{
					arr[prev->adjvex] -= 1;
					prev = prev->nextarc;
				}
				break;
			}
		}
	}
	printf("\n");
}
void test()
{
	int arr[MAX_VERTEX_NUM] = { 0 };//先将所有顶点结点的入度置为0
	ALGraph G;
	CreatDG2(G);
	print(G);

	TopologicalSort(G, arr);
}