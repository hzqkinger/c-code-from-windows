#pragma once

#define INFINITY INT_MAX   //假装INT_MAX是无穷大值
#define MAX_VERTEX_NUM 10  //指定弧的二维数组的最大维数

typedef int Vrtype;//Vrtype是顶点关系类型
typedef char Infotype;
typedef int Vextype;//Vextype是顶点类型

typedef enum{DG,DN,UDG,UDN}Grapkind;

typedef struct Arccell   //弧的性质
{
	Vrtype adj;          //Vrtype是顶点关系类型（对于无权图，用0或1；对于有权图，则为权值类型）
	Infotype *info;      //该弧相关信息的指针（由于这里不知道弧的相关信息，所以下面指针都指向NULL）
}Arccell, Adjmatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//①一个弧的别名；②弧的二维数组

typedef struct  //图的性质
{
	Vextype vexs[MAX_VERTEX_NUM];//顶点向量
	Adjmatrix arcs;              //邻接矩阵
	int vexnum, arcnum;          //图的当前顶点数和弧数
	Grapkind kind;               //图的种类标志
}MGraph;

void CreatDG(MGraph &G)//构造有向图
{
	int i, j, k;
	printf("输入顶点个数和弧的条数\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("请依次输入%d顶点的值\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		scanf("%d", &G.vexs[i]);

	for (i = 0; i < G.vexnum; ++i)
	for (j = 0; j < G.vexnum; ++j)
		G.arcs[i][j] = { 0, NULL };//图顶点之间的关系用0或1表示（初始值为0）

	printf("请依次输入%d条弧的坐标[i][j]\n", G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%d%d", &i, &j);
		G.arcs[i][j].adj = 1;
	}

	printf("此有向图的邻接矩阵为：\n");
	for (i = 0; i < G.vexnum; ++i)//打印出邻接矩阵
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			printf("%2d", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}
void CreatDN(MGraph &G)//构造有向网
{
	int i, j, k;
	printf("输入顶点个数和弧的条数\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("请依次输入%d顶点的值\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		scanf("%d", &G.vexs[i]);

	for (i = 0; i < G.vexnum; ++i)
	for (j = 0; j < G.vexnum; ++j)
		G.arcs[i][j] = { INFINITY, NULL };//网是带权值的图

	printf("请依次输入%d条弧的坐标[i][j]及其权值weight\n", G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		int w;
		scanf("%d%d%d", &i, &j, &w);
		G.arcs[i][j].adj = w;
	}

	printf("此有向网的邻接矩阵为：\n");
	for (i = 0; i < G.vexnum; ++i)//打印出邻接矩阵
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			printf("%2d", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}
void CreatUDG(MGraph &G)//构造无向图
{
	int i, j, k;
	printf("输入顶点个数和弧的条数\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("请依次输入%d顶点的值\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		scanf("%d", &G.vexs[i]);

	for (i = 0; i < G.vexnum; ++i)
	for (j = 0; j < G.vexnum; ++j)
		G.arcs[i][j] = { 0, NULL };//图顶点之间的关系用0或1表示（初始值为0）

	printf("请依次输入%d条弧的坐标[i][j]\n", G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%d%d", &i, &j);
		G.arcs[i][j].adj = 1;

		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	printf("此无向图的邻接矩阵为：\n");
	for (i = 0; i < G.vexnum; ++i)//打印出邻接矩阵
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			printf("%2d", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}
void CreatUDN(MGraph &G)//构造无向网
{
	int i, j, k;
	printf("输入顶点个数和弧的条数\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("请依次输入%d顶点的值\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		scanf("%d", &G.vexs[i]);

	for (i = 0; i < G.vexnum; ++i)
	for (j = 0; j < G.vexnum; ++j)
		G.arcs[i][j] = { INFINITY, NULL };//网是带权值的图

	printf("请依次输入%d条弧的坐标[i][j]及其权值weight\n", G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		int w;
		scanf("%d%d%d", &i, &j, &w);
		G.arcs[i][j].adj = w;

		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}

	printf("此无向网的邻接矩阵为：\n");
	for (i = 0; i < G.vexnum; ++i)//打印出邻接矩阵
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			printf("%2d", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}
void CreatGraph(MGraph &G)
{
	printf("*****************************************\n");
	printf("***   0.构造有向图      1.构造有向网  ***\n");
	printf("***   2.构造无向图      3.构造无向网  ***\n");
	printf("***   4.退出程序                      ***\n");
	printf("*****************************************\n");

	while (1)
	{
		printf("请输入选项0、1、2、3、4\n");
		scanf("%d", &G.kind);
		if (G.kind == 4)break;
		switch (G.kind)
		{
		case DG:
			CreatDG(G);
			break;
		case DN:
			CreatDN(G);
			break;
		case UDG:
			CreatUDG(G);
			break;
		case UDN:
			CreatUDN(G);
			break;
		default:
			break;
		}
	}
}

void test()
{
	MGraph G;
	CreatGraph(G);
}