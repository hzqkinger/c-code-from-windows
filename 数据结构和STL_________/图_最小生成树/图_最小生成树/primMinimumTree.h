#pragma once

#define MAX_VERTEX_NUM 20
#define Max INT_MAX

//typedef char InfoType;
typedef int VertexType;//��������

typedef struct ArcNode
{
	int adjvex;                 //�û���ָ��Ķ�����±�λ��
	struct ArcNode *nextarc;    //ָ����һ������ָ��
	//InfoType *info;             //�û������Ϣ��ָ�루���������д�û��ĳ��ȣ���Ȩֵ��
	int weight;
}ArcNode;//�����

typedef struct VNode
{
	VertexType data;         //������Ϣ
	ArcNode *firstarc;       //ָ���һ�������ڸö���Ļ���ָ��
}VNnode, AdjList[MAX_VERTEX_NUM];
//һ�������㣻�洢�������һά����

typedef struct
{
	AdjList vertices;  //��������
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
}ALGraph;


void CreatDG2(ALGraph &G)//��������ͼ
{
	size_t i, j;
	printf("���붥������ͻ�������\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("����������%d�����ֵ\n", G.vexnum);//�Ƚ�����������data��ֵ��ָ��firstarc = NULL
	for (i = 0; i < G.vexnum; ++i)
	{
		scanf("%d", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
		G.vertices[i].flag = false;
	}

	for (i = 0; i < G.vexnum; ++i)//��vertices�����ÿһ�����㽨��һ������
	{
		ArcNode *prev = NULL;
		printf("�������%d�������м�������\n", i + 1);
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
			printf("�������%d����ָ��Ľ���ڶ����������±�λ�ü���Ȩֵ��\n", j + 1);
			scanf("%d%d", &arc->adjvex,&arc->weight);//�������adjvex�洢�û���ָ��Ķ������ڶ��������е��±�
		}
		printf("\n");
	}
}
void print(const ALGraph &G)
{
	int i;
	printf("��ӡ���ݣ�\n");
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
//MST��Minimum Spanning Tree����С������������������ͨ�õĽⷨ��
//Prim�㷨��������֮һ�����Ǵӵ�ķ��濼�ǹ���һ��MST������˼���ǣ�
//   ��ͼG���㼯��ΪU����������ѡ��ͼG�е�һ����Ϊ��ʼ��a�����õ���뼯��V���ٴӼ���U - V���ҵ�
//   ��һ��bʹ�õ�b��V������һ���Ȩֵ��С����ʱ��b��Ҳ���뼯��V���Դ����ƣ����ڵļ���V = { a��b }��
//   �ٴӼ���U - V���ҵ���һ��cʹ�õ�c��V������һ���Ȩֵ��С����ʱ��c����뼯��V��ֱ�����ж���ȫ��
//   ������V����ʱ�͹�������һ��MST����Ϊ��N�����㣬���Ը�MST����N - 1���ߣ�ÿһ���򼯺�V�м���һ���㣬
//   ����ζ���ҵ�һ��MST�ı�


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
	for (i = 0; i < G.vexnum; ++i)//��ʼ����������
	{
		closedge[cur->adjvex].lowcost = Max;
		closedge[cur->adjvex].adjvex = k;
	}
	closedge[k].lowcost = 0;//�Լ����Լ��ľ���Ϊ0
	while (cur)
		closedge[cur->adjvex].lowcost = cur->weight;

	min = closedge[k].lowcost;
	for (i = 0; i < G.vexnum; ++i)//Ѱ����С�Ļ�
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