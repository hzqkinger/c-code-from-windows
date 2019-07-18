#pragma once

#define INFINITY INT_MAX   //��װINT_MAX�������ֵ
#define MAX_VERTEX_NUM 10  //ָ�����Ķ�ά��������ά��

typedef int Vrtype;//Vrtype�Ƕ����ϵ����
typedef char Infotype;
typedef int Vextype;//Vextype�Ƕ�������

typedef enum{DG,DN,UDG,UDN}Grapkind;

typedef struct Arccell   //��������
{
	Vrtype adj;          //Vrtype�Ƕ����ϵ���ͣ�������Ȩͼ����0��1��������Ȩͼ����ΪȨֵ���ͣ�
	Infotype *info;      //�û������Ϣ��ָ�루�������ﲻ֪�����������Ϣ����������ָ�붼ָ��NULL��
}Arccell, Adjmatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
//��һ�����ı������ڻ��Ķ�ά����

typedef struct  //ͼ������
{
	Vextype vexs[MAX_VERTEX_NUM];//��������
	Adjmatrix arcs;              //�ڽӾ���
	int vexnum, arcnum;          //ͼ�ĵ�ǰ�������ͻ���
	Grapkind kind;               //ͼ�������־
}MGraph;

void CreatDG(MGraph &G)//��������ͼ
{
	int i, j, k;
	printf("���붥������ͻ�������\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("����������%d�����ֵ\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		scanf("%d", &G.vexs[i]);

	for (i = 0; i < G.vexnum; ++i)
	for (j = 0; j < G.vexnum; ++j)
		G.arcs[i][j] = { 0, NULL };//ͼ����֮��Ĺ�ϵ��0��1��ʾ����ʼֵΪ0��

	printf("����������%d����������[i][j]\n", G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%d%d", &i, &j);
		G.arcs[i][j].adj = 1;
	}

	printf("������ͼ���ڽӾ���Ϊ��\n");
	for (i = 0; i < G.vexnum; ++i)//��ӡ���ڽӾ���
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			printf("%2d", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}
void CreatDN(MGraph &G)//����������
{
	int i, j, k;
	printf("���붥������ͻ�������\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("����������%d�����ֵ\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		scanf("%d", &G.vexs[i]);

	for (i = 0; i < G.vexnum; ++i)
	for (j = 0; j < G.vexnum; ++j)
		G.arcs[i][j] = { INFINITY, NULL };//���Ǵ�Ȩֵ��ͼ

	printf("����������%d����������[i][j]����Ȩֵweight\n", G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		int w;
		scanf("%d%d%d", &i, &j, &w);
		G.arcs[i][j].adj = w;
	}

	printf("�����������ڽӾ���Ϊ��\n");
	for (i = 0; i < G.vexnum; ++i)//��ӡ���ڽӾ���
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			printf("%2d", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}
void CreatUDG(MGraph &G)//��������ͼ
{
	int i, j, k;
	printf("���붥������ͻ�������\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("����������%d�����ֵ\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		scanf("%d", &G.vexs[i]);

	for (i = 0; i < G.vexnum; ++i)
	for (j = 0; j < G.vexnum; ++j)
		G.arcs[i][j] = { 0, NULL };//ͼ����֮��Ĺ�ϵ��0��1��ʾ����ʼֵΪ0��

	printf("����������%d����������[i][j]\n", G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%d%d", &i, &j);
		G.arcs[i][j].adj = 1;

		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	printf("������ͼ���ڽӾ���Ϊ��\n");
	for (i = 0; i < G.vexnum; ++i)//��ӡ���ڽӾ���
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			printf("%2d", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}
void CreatUDN(MGraph &G)//����������
{
	int i, j, k;
	printf("���붥������ͻ�������\n");
	scanf("%d%d", &G.vexnum, &G.arcnum);

	printf("����������%d�����ֵ\n", G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
		scanf("%d", &G.vexs[i]);

	for (i = 0; i < G.vexnum; ++i)
	for (j = 0; j < G.vexnum; ++j)
		G.arcs[i][j] = { INFINITY, NULL };//���Ǵ�Ȩֵ��ͼ

	printf("����������%d����������[i][j]����Ȩֵweight\n", G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		int w;
		scanf("%d%d%d", &i, &j, &w);
		G.arcs[i][j].adj = w;

		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}

	printf("�����������ڽӾ���Ϊ��\n");
	for (i = 0; i < G.vexnum; ++i)//��ӡ���ڽӾ���
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
	printf("***   0.��������ͼ      1.����������  ***\n");
	printf("***   2.��������ͼ      3.����������  ***\n");
	printf("***   4.�˳�����                      ***\n");
	printf("*****************************************\n");

	while (1)
	{
		printf("������ѡ��0��1��2��3��4\n");
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