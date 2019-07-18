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
			printf("�������%d����ָ��Ľ���ڶ����������±�λ�ã�\n", j + 1);
			scanf("%d", &arc->adjvex);//�������adjvex�洢�û���ָ��Ķ������ڶ��������е��±�
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
void FindIndegree(const ALGraph &G, int arr[])//Ѱ��ͼ�����н������
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
	printf("������������Ϊ��\n");
	while (j--)
	{
		for (i = 0; i < G.vexnum; ++i)
		{
			if (!arr[i])
			{
				printf("%3d", G.vertices[i].data);//�����������Ϣ��
	    		arr[i] = -1;//Ȼ�󽫸ö�����������Ϊ-1
				ArcNode *prev = G.vertices[i].firstarc;
				while (prev)//��G.vertices[i]�Ļ�ָ��Ķ�����Ķȼ�1
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
	int arr[MAX_VERTEX_NUM] = { 0 };//�Ƚ����ж�����������Ϊ0
	ALGraph G;
	CreatDG2(G);
	print(G);

	TopologicalSort(G, arr);
}