//����ͨ�汾
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<Windows.h>
#define MAXN 20
#define MAXS 5
#define MAXA 15
#define MAX 1000
typedef struct 
{
	char name[MAXN];
	char sex[MAXS];
	char addr[MAXA];
	char num[11];
	int age;
}stu;
typedef struct contact//����ṹ������
{
	stu data[MAX];
	int sz;
}conta,*pcon;
enum optin//ö������
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	EMPTY,//6
	SORT_NAME,//7
};
void menu()
{
	printf("*************************************************************\n");
	printf("******   1����ͨѶ¼����      2ɾ��ͨѶ¼����         *******\n");
	printf("******   3����ͨѶ¼          4�޸�ͨѶ¼             *******\n");
	printf("******   5��ʾͨѶ¼          6���ͨѶ¼             *******\n");
	printf("******   7�����ֽ�������      0�˳�ͨѶ¼             *******\n");
	printf("*************************************************************\n");
}
void Initpeople(pcon p)
{
	memset(p->data, 0, sizeof(p->data));
	p->sz = 0;
}
void Add(pcon p)
{
	printf("������������\n");
	scanf("%s",p->data[p->sz].name );
	printf("�������Ա�\n");
	scanf("%s", p->data[p->sz].sex);
	printf("�������ַ��\n");
	scanf("%s", p->data[p->sz].addr);
	printf("������绰��\n");
	scanf("%s", p->data[p->sz].num);
	printf("���������䣺\n");
	scanf("%d", &p->data[p->sz].age);
	p->sz++;
}
void Del(pcon p)
{
	int i = 0;
	char tmp[MAXN] = { 0 };
	printf("��������Ҫɾ�������֣�\n");
	scanf("%s", tmp);
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(tmp, p->data[i].name) == 0)
		{
			strcpy(p->data[i].name, p->data[p->sz - 1].name);
			strcpy(p->data[i].sex, p->data[p->sz - 1].sex);
			strcpy(p->data[i].addr, p->data[p->sz - 1].addr);
			strcpy(p->data[i].num, p->data[p->sz - 1].num);
			p->data[i].age = p->data[p->sz - 1].age;
			p->sz--;
			return;
		}
	}
	if (i == p->sz)
		printf("���޴���\n");
}
void Search(pcon p)
{
	char tmp[MAXN] = { 0 };
	int i = 0;
	printf("��������Ҫ���ҵ��ˣ�\n");
	scanf("%s", tmp);
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(tmp, p->data[i].name) == 0)
		{
			printf("����  ����   �Ա�   ��ַ   �绰\n");
			printf("%5s %5d %5s %5s %5s", p->data[i].name, p->data[i].age, p->data[i].sex, p->data[i].addr, p->data[i].num);
			printf("\n");
			break;
		}
	}
	if (i == p->sz)
		printf("���޴���\n");
}
void Modify(pcon p)
{
	int i = 0;
	char tmp[MAXN] = { 0 };
	printf("��������Ҫ�޸ĵ�������\n");
	scanf("%s", tmp);
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(tmp, p->data[i].name) == 0)
		{
			printf("������������\n");
			scanf("%s", p->data[i].name);
			printf("�������Ա�\n");
			scanf("%s", p->data[i].sex);
			printf("�������ַ��\n");
			scanf("%s", p->data[i].addr);
			printf("������绰��\n");
			scanf("%s", p->data[i].num);
			printf("���������䣺\n");
			scanf("%d", &p->data[i].age);
		}
	}
	if (i == p->sz)
		printf("���޴���\n");

}
void Show(pcon p)
{
	int i = 0;
	printf("����  ����   �Ա�   ��ַ   �绰\n");
	for (i = 0; i < p->sz; i++)
	{
		printf("%5s %5d %5s %5s %5s", p->data[i].name, p->data[i].age, p->data[i].sex, p->data[i].addr, p->data[i].num);
		printf("\n");
	}

}
void Empty(pcon p)
{
	p->sz = 0;
}
void Sort_name(pcon p)
{
	int i = 0, j = 0;
	for (i = 0; i < p->sz-1; i++)
	{
		for (j = 0; j < p->sz - i - 1; j++)
		{
			if (strcmp(p->data[j].name, p->data[j + 1].name)>0)
			{
				p->data[p->sz] = p->data[j];
				p->data[j] = p->data[j + 1];
				p->data[j + 1] = p->data[p->sz];
				//strcpy(tmp,p->data[j].name);
				//strcpy(p->data[j].name, p->data[j + 1].name);
				//strcpy(p->data[j + 1].name, tmp);
			}		
		}
	}
}
int* Exit(int* n)
{
	*n = 0;
	return n;
}
int main()
{
	conta con;
	pcon p = &con;
	int input = 1;
	int n = 1;
	Initpeople(p);
	while (n)
	{
		menu();
		printf("������ѡ��>");
		scanf("%d", &input);
		//while (1)
		//{

		//	if (input >= 0 && input < 8)
		//		break;
		//	else
		//		printf("ѡ������");
		//}
		switch (input)
		{
		case ADD:
			Add(p);
			break;
		case DEL:
			Del(p);
			break;
		case SEARCH:
			Search(p);
			break;
		case MODIFY:
			Modify(p);
			break;
		case SHOW:
			Show(p);
			break;
		case EMPTY:
			Empty(p);
			break;
		case SORT_NAME:
			Sort_name(p);
			break;
		case EXIT:
			Exit(&n);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
#endif
//�ڶ�̬�����ڴ�汾
//#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<Windows.h>
#define MAXN 20
#define MAXS 5
#define MAXA 15
static count = 1;
static int peocnt = 1;
typedef struct
{
	char name[MAXN];
	char sex[MAXS];
	char addr[MAXA];
	char num[11];
	int age;
}stu;
enum optin//ö������
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	EMPTY,//6
};
void menu()
{
	printf("*************************************************************\n");
	printf("******   1����ͨѶ¼����      2ɾ��ͨѶ¼����         *******\n");
	printf("******   3����ͨѶ¼          4�޸�ͨѶ¼             *******\n");
	printf("******   5��ʾͨѶ¼          6���ͨѶ¼             *******\n");
	printf("******   0�˳�ͨѶ¼                                  *******\n");
	printf("*************************************************************\n");
}
void Add(stu* p)
{
	if (count > peocnt)
	{
		stu *p1 = realloc(p,count*sizeof(stu));
		if (p1 != NULL)
			p = p1;
		printf("���ݳɹ���\n");
	}
	printf("������������\n");
	scanf("%s", p[count-1].name);
	printf("�������Ա�\n");
	scanf("%s", p[count - 1].sex);
	printf("�������ַ��\n");
	scanf("%s", p[count - 1].addr);
	printf("������绰��\n");
	scanf("%s", p[count - 1].num);
	printf("���������䣺\n");
	scanf("%d", &p[count - 1].age);
	count++;
}
void Del(stu* p)
{
	int i = 0;
	char tmp[MAXN] = { 0 };
	printf("��������Ҫɾ�������֣�\n");
	scanf("%s", tmp);
	for (i = 0; i < count-1; i++)
	{
		if (strcmp(tmp, p[i].name) == 0)
		{
			strcpy(p[i].name, p[count - 2].name);
			strcpy(p[i].sex, p[count - 2].sex);
			strcpy(p[i].addr, p[count - 2].addr);
			strcpy(p[i].num, p[count - 2].num);
			p[i].age = p[count - 2].age;
			count--;
			return;
		}
	}
	if (i == count-1)
		printf("���޴���\n");
}
void Search(stu* p)
{
	char tmp[MAXN] = { 0 };
	int i = 0;
	printf("��������Ҫ���ҵ��ˣ�\n");
	scanf("%s", tmp);
	for (i = 0; i < count-1; i++)
	{
		if (strcmp(tmp, p[i].name) == 0)
		{
			printf("����  ����   �Ա�   ��ַ   �绰\n");
			printf("%5s %5d %5s %5s %5s", p[i].name, p[i].age, p[i].sex, p[i].addr, p[i].num);
			printf("\n");
			break;
		}
	}
	if (i == count-1)
		printf("���޴���\n");
}
void Modify(stu* p)
{
	int i = 0;
	char tmp[MAXN] = { 0 };
	printf("��������Ҫ�޸ĵ�������\n");
	scanf("%s", tmp);
	for (i = 0; i < count-1; i++)
	{
		if (strcmp(tmp, p[i].name) == 0)
		{
			printf("������������\n");
			scanf("%s", p[i].name);
			printf("�������Ա�\n");
			scanf("%s", p[i].sex);
			printf("�������ַ��\n");
			scanf("%s", p[i].addr);
			printf("������绰��\n");
			scanf("%s", p[i].num);
			printf("���������䣺\n");
			scanf("%d", &p[i].age);
		}
	}
	if (i == count-1)
		printf("���޴���\n");
}
void Show(stu* p)
{
	int i = 0;
	printf("����  ����   �Ա�   ��ַ   �绰\n");
	for (i = 0; i < count-1; i++)
	{
		printf("%5s %5d %5s %5s %5s", p[i].name, p[i].age, p[i].sex, p[i].addr, p[i].num);
		printf("\n");
	}

}
void Empty(stu* p)
{
	count = 0;
}
int main()
{
	int input = 1;
	stu *p = NULL;
	stu *p1 = malloc(peocnt*sizeof(stu));
	if (p1 != NULL)
		p = p1;
	else
		perror("malloc:\n");
	memset(p, 0, peocnt*sizeof(stu));
	while (input)
	{
		menu();
		printf("������ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Add(p);
			break;
		case DEL:
			Del(p);
			break;
		case SEARCH:
			Search(p);
			break;
		case MODIFY:
			Modify(p);
			break;
		case SHOW:
			Show(p);
			break;
		case EMPTY:
			Empty(p);
			break;
		case EXIT:
			break;
		default:
			printf("ѡ������\n");
			break;
		}
	}
	system("pause");
	return 0;
}
//#endif

////���ļ��汾�����޸ģ�
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>     
//#include<string.h>    
//#include<Windows.h>
//#define MAXN 20
//#define MAXS 5
//#define MAXA 15
//#define MAX 1000
//typedef struct
//{
//	char name[MAXN];
//	char sex[MAXS];
//	char addr[MAXA];
//	char num[11];
//	int age;
//}stu;
//typedef struct contact//����ṹ������
//{
//	stu data[MAX];
//	int sz;
//}conta, *pcon;
//enum optin//ö������
//{
//	EXIT,//0
//	ADD,//1
//	DEL,//2
//	SEARCH,//3
//	MODIFY,//4
//	SHOW,//5
//	EMPTY,//6
//	SORT_NAME,//7
//};
//void menu()
//{
//	printf("*************************************************************\n");
//	printf("******   1����ͨѶ¼����      2ɾ��ͨѶ¼����         *******\n");
//	printf("******   3����ͨѶ¼          4�޸�ͨѶ¼             *******\n");
//	printf("******   5��ʾͨѶ¼          6���ͨѶ¼             *******\n");
//	printf("******   7�����ֽ�������      0�˳�ͨѶ¼             *******\n");
//	printf("*************************************************************\n");
//}
//void Initpeople(pcon p)
//{
//	memset(p->data, 0, sizeof(p->data));
//	p->sz = 0;
//}
//void Add(pcon p)
//{
//	printf("������������\n");
//	scanf("%s", p->data[p->sz].name);
//	printf("�������Ա�\n");
//	scanf("%s", p->data[p->sz].sex);
//	printf("�������ַ��\n");
//	scanf("%s", p->data[p->sz].addr);
//	printf("������绰��\n");
//	scanf("%s", p->data[p->sz].num);
//	printf("���������䣺\n");
//	scanf("%d", &p->data[p->sz].age);
//	p->sz++;
//}
//void Del(pcon p)
//{
//	int i = 0;
//	char tmp[MAXN] = { 0 };
//	printf("��������Ҫɾ�������֣�\n");
//	scanf("%s", tmp);
//	for (i = 0; i < p->sz; i++)
//	{
//		if (strcmp(tmp, p->data[i].name) == 0)
//		{
//			strcpy(p->data[i].name, p->data[p->sz - 1].name);
//			strcpy(p->data[i].sex, p->data[p->sz - 1].sex);
//			strcpy(p->data[i].addr, p->data[p->sz - 1].addr);
//			strcpy(p->data[i].num, p->data[p->sz - 1].num);
//			p->data[i].age = p->data[p->sz - 1].age;
//			p->sz--;
//			return;
//		}
//	}
//	if (i == p->sz)
//		printf("���޴���\n");
//}
//void Search(pcon p)
//{
//	char tmp[MAXN] = { 0 };
//	int i = 0;
//	printf("��������Ҫ���ҵ��ˣ�\n");
//	scanf("%s", tmp);
//	for (i = 0; i < p->sz; i++)
//	{
//		if (strcmp(tmp, p->data[i].name) == 0)
//		{
//			printf("����  ����   �Ա�   ��ַ   �绰\n");
//			printf("%5s %5d %5s %5s %5s", p->data[i].name, p->data[i].age, p->data[i].sex, p->data[i].addr, p->data[i].num);
//			printf("\n");
//			break;
//		}
//	}
//	if (i == p->sz)
//		printf("���޴���\n");
//}
//void Modify(pcon p)
//{
//	int i = 0;
//	char tmp[MAXN] = { 0 };
//	printf("��������Ҫ�޸ĵ�������\n");
//	scanf("%s", tmp);
//	for (i = 0; i < p->sz; i++)
//	{
//		if (strcmp(tmp, p->data[i].name) == 0)
//		{
//			printf("������������\n");
//			scanf("%s", p->data[i].name);
//			printf("�������Ա�\n");
//			scanf("%s", p->data[i].sex);
//			printf("�������ַ��\n");
//			scanf("%s", p->data[i].addr);
//			printf("������绰��\n");
//			scanf("%s", p->data[i].num);
//			printf("���������䣺\n");
//			scanf("%d", &p->data[i].age);
//		}
//	}
//	if (i == p->sz)
//		printf("���޴���\n");
//
//}
//void Show(pcon p)
//{
//	int i = 0;
//	printf("����  ����   �Ա�   ��ַ   �绰\n");
//	for (i = 0; i < p->sz; i++)
//	{
//		printf("%5s %5d %5s %5s %5s", p->data[i].name, p->data[i].age, p->data[i].sex, p->data[i].addr, p->data[i].num);
//		printf("\n");
//	}
//
//}
//void Empty(pcon p)
//{
//	p->sz = 0;
//}
//void Sort_name(pcon p)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < p->sz - 1; i++)
//	{
//		for (j = 0; j < p->sz - i - 1; j++)
//		{
//			if (strcmp(p->data[j].name, p->data[j + 1].name)>0)
//			{
//				p->data[p->sz] = p->data[j];
//				p->data[j] = p->data[j + 1];
//				p->data[j + 1] = p->data[p->sz];
//				//strcpy(tmp,p->data[j].name);
//				//strcpy(p->data[j].name, p->data[j + 1].name);
//				//strcpy(p->data[j + 1].name, tmp);
//			}
//		}
//	}
//}
//int* Exit(int* n)
//{
//	*n = 0;
//	return n;
//}
//int main()
//{
//	conta con;
//	pcon p = &con;
//	int input = 1;
//	int n = 1;
//	Initpeople(p);
//	while (n)
//	{
//		menu();
//		printf("������ѡ��>");
//		scanf("%d", &input);
//		//while (1)
//		//{
//
//		//	if (input >= 0 && input < 8)
//		//		break;
//		//	else
//		//		printf("ѡ������");
//		//}
//		switch (input)
//		{
//		case ADD:
//			Add(p);
//			break;
//		case DEL:
//			Del(p);
//			break;
//		case SEARCH:
//			Search(p);
//			break;
//		case MODIFY:
//			Modify(p);
//			break;
//		case SHOW:
//			Show(p);
//			break;
//		case EMPTY:
//			Empty(p);
//			break;
//		case SORT_NAME:
//			Sort_name(p);
//			break;
//		case EXIT:
//			Exit(&n);
//			break;
//		default:
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}