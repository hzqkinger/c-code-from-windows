#pragma once
#include<queue>

#define MAX_VERTEX_NUM 20

typedef char InfoType;
typedef int VertexType;//��������

typedef enum{DG2,UDG2}GrapKind; //DG������ͼ��UDG������ͼ
typedef struct ArcNode
{
	int adjvex;                 //�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;    //ָ����һ������ָ��
	InfoType *info;             //�û������Ϣ��ָ�루���ƶ���ָ��NULL����Ϊ��֪����ɶ�����Ϣ��
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
	int kind;          //ͼ�������־
}ALGraph;

bool visited[MAX_VERTEX_NUM];
//������ȱ���(�ݹ鷽��)           //�´���ʵ�ַǵݹ鷽��
void DFS(ALGraph &G, size_t v)
{
	visited[v] = true;
	printf("%3d", G.vertices[v].data);//�����±�Ϊv�Ķ���������Ϣ

	ArcNode *arc = G.vertices[v].firstarc;
	while (arc)//���绡arc��Ϊ�գ�����G.vertices[v]���������Ļ�
	{
		if (!visited[arc->adjvex])DFS(G, arc->adjvex);//����߱���û�б����ʹ�,��ݹ����DFS 

			arc = arc->nextarc;//arc����ֵΪG.vertices[v]����һ����
	}
}
void DFSTraverse(ALGraph &G)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)visited[i] = false;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (!visited[i]) //ѡȡһ��δ���ʹ��Ķ������������ȱ���, �������ͨͼ�������������DFSִֻ��һ��
			DFS(G, i);
	}
	printf("\n");
}
//������ȱ���
void BFSTraverse(ALGraph &G)
{
	int i;
	queue<VNode*> q;
	for (i = 0; i < G.vexnum; ++i)visited[i] = false;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (!visited[i])//ѡȡһ��δ���ʹ��Ķ�����й�����ȱ������������ͨͼ��ֻ������if���һ��
		{
			q.push(G.vertices + i);
			visited[i] = true;

			while (!q.empty())
			{
				ArcNode *arc = q.front()->firstarc;
				printf("%3d", q.front()->data);//���ʽ�Ҫ�����е�VNode��������Ϣ
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


//˵�����ٹ�������ͼ������ͼ�Ĵ���99%����ͬ�ģ�������flag����ͬ���ѣ�
//      �ڻ��о����ڹ�������ͼ������ͼʱ����������ȹ�ȱ�������������һ����������ͼ�ͱ���
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
		printf("�������%d�������м�������\n", i + 1);//flag(��ͬ��)
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

	printf("��ӡ���ݣ�\n");
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

	printf("������ȱ�����\n");
	DFSTraverse(G);//�����������
	printf("������ȱ�����\n");
	BFSTraverse(G);
}
void CreatUDG2(ALGraph &G)//��������ͼ
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
		printf("�������%d������ĳ��ȣ�\n", i + 1);//flag(��ͬ��)
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

	printf("��ӡ���ݣ�\n");
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
	printf("������ȱ�����\n");
	DFSTraverse(G);//�����������
	printf("������ȱ�����\n");
	BFSTraverse(G);
}


void CreatALGraph(ALGraph &G)
{
	printf("*****************************************\n");
	printf("***   0.��������ͼ      1.��������ͼ  ***\n");
	printf("***   2.�˳�����                      ***\n");
	printf("*****************************************\n");

	while (1)
	{
		printf("������ѡ��0��1��2\n");
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