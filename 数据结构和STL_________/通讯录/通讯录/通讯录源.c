//①普通版本
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
typedef struct contact//定义结构体数组
{
	stu data[MAX];
	int sz;
}conta,*pcon;
enum optin//枚举类型
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
	printf("******   1增加通讯录人数      2删除通讯录人数         *******\n");
	printf("******   3查找通讯录          4修改通讯录             *******\n");
	printf("******   5显示通讯录          6清空通讯录             *******\n");
	printf("******   7按名字进行排序      0退出通讯录             *******\n");
	printf("*************************************************************\n");
}
void Initpeople(pcon p)
{
	memset(p->data, 0, sizeof(p->data));
	p->sz = 0;
}
void Add(pcon p)
{
	printf("请输入姓名：\n");
	scanf("%s",p->data[p->sz].name );
	printf("请输入性别：\n");
	scanf("%s", p->data[p->sz].sex);
	printf("请输入地址：\n");
	scanf("%s", p->data[p->sz].addr);
	printf("请输入电话：\n");
	scanf("%s", p->data[p->sz].num);
	printf("请输入年龄：\n");
	scanf("%d", &p->data[p->sz].age);
	p->sz++;
}
void Del(pcon p)
{
	int i = 0;
	char tmp[MAXN] = { 0 };
	printf("请输入你要删除的名字：\n");
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
		printf("查无此人\n");
}
void Search(pcon p)
{
	char tmp[MAXN] = { 0 };
	int i = 0;
	printf("请输入你要查找的人：\n");
	scanf("%s", tmp);
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(tmp, p->data[i].name) == 0)
		{
			printf("姓名  年龄   性别   地址   电话\n");
			printf("%5s %5d %5s %5s %5s", p->data[i].name, p->data[i].age, p->data[i].sex, p->data[i].addr, p->data[i].num);
			printf("\n");
			break;
		}
	}
	if (i == p->sz)
		printf("查无此人\n");
}
void Modify(pcon p)
{
	int i = 0;
	char tmp[MAXN] = { 0 };
	printf("请输入你要修改的人名；\n");
	scanf("%s", tmp);
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(tmp, p->data[i].name) == 0)
		{
			printf("请输入姓名：\n");
			scanf("%s", p->data[i].name);
			printf("请输入性别：\n");
			scanf("%s", p->data[i].sex);
			printf("请输入地址：\n");
			scanf("%s", p->data[i].addr);
			printf("请输入电话：\n");
			scanf("%s", p->data[i].num);
			printf("请输入年龄：\n");
			scanf("%d", &p->data[i].age);
		}
	}
	if (i == p->sz)
		printf("查无此人\n");

}
void Show(pcon p)
{
	int i = 0;
	printf("姓名  年龄   性别   地址   电话\n");
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
		printf("请输入选项>");
		scanf("%d", &input);
		//while (1)
		//{

		//	if (input >= 0 && input < 8)
		//		break;
		//	else
		//		printf("选择有误！");
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
//②动态分配内存版本
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
enum optin//枚举类型
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
	printf("******   1增加通讯录人数      2删除通讯录人数         *******\n");
	printf("******   3查找通讯录          4修改通讯录             *******\n");
	printf("******   5显示通讯录          6清空通讯录             *******\n");
	printf("******   0退出通讯录                                  *******\n");
	printf("*************************************************************\n");
}
void Add(stu* p)
{
	if (count > peocnt)
	{
		stu *p1 = realloc(p,count*sizeof(stu));
		if (p1 != NULL)
			p = p1;
		printf("增容成功！\n");
	}
	printf("请输入姓名：\n");
	scanf("%s", p[count-1].name);
	printf("请输入性别：\n");
	scanf("%s", p[count - 1].sex);
	printf("请输入地址：\n");
	scanf("%s", p[count - 1].addr);
	printf("请输入电话：\n");
	scanf("%s", p[count - 1].num);
	printf("请输入年龄：\n");
	scanf("%d", &p[count - 1].age);
	count++;
}
void Del(stu* p)
{
	int i = 0;
	char tmp[MAXN] = { 0 };
	printf("请输入你要删除的名字：\n");
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
		printf("查无此人\n");
}
void Search(stu* p)
{
	char tmp[MAXN] = { 0 };
	int i = 0;
	printf("请输入你要查找的人：\n");
	scanf("%s", tmp);
	for (i = 0; i < count-1; i++)
	{
		if (strcmp(tmp, p[i].name) == 0)
		{
			printf("姓名  年龄   性别   地址   电话\n");
			printf("%5s %5d %5s %5s %5s", p[i].name, p[i].age, p[i].sex, p[i].addr, p[i].num);
			printf("\n");
			break;
		}
	}
	if (i == count-1)
		printf("查无此人\n");
}
void Modify(stu* p)
{
	int i = 0;
	char tmp[MAXN] = { 0 };
	printf("请输入你要修改的人名；\n");
	scanf("%s", tmp);
	for (i = 0; i < count-1; i++)
	{
		if (strcmp(tmp, p[i].name) == 0)
		{
			printf("请输入姓名：\n");
			scanf("%s", p[i].name);
			printf("请输入性别：\n");
			scanf("%s", p[i].sex);
			printf("请输入地址：\n");
			scanf("%s", p[i].addr);
			printf("请输入电话：\n");
			scanf("%s", p[i].num);
			printf("请输入年龄：\n");
			scanf("%d", &p[i].age);
		}
	}
	if (i == count-1)
		printf("查无此人\n");
}
void Show(stu* p)
{
	int i = 0;
	printf("姓名  年龄   性别   地址   电话\n");
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
		printf("请输入选项>");
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
			printf("选择有误！\n");
			break;
		}
	}
	system("pause");
	return 0;
}
//#endif

////③文件版本（待修改）
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
//typedef struct contact//定义结构体数组
//{
//	stu data[MAX];
//	int sz;
//}conta, *pcon;
//enum optin//枚举类型
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
//	printf("******   1增加通讯录人数      2删除通讯录人数         *******\n");
//	printf("******   3查找通讯录          4修改通讯录             *******\n");
//	printf("******   5显示通讯录          6清空通讯录             *******\n");
//	printf("******   7按名字进行排序      0退出通讯录             *******\n");
//	printf("*************************************************************\n");
//}
//void Initpeople(pcon p)
//{
//	memset(p->data, 0, sizeof(p->data));
//	p->sz = 0;
//}
//void Add(pcon p)
//{
//	printf("请输入姓名：\n");
//	scanf("%s", p->data[p->sz].name);
//	printf("请输入性别：\n");
//	scanf("%s", p->data[p->sz].sex);
//	printf("请输入地址：\n");
//	scanf("%s", p->data[p->sz].addr);
//	printf("请输入电话：\n");
//	scanf("%s", p->data[p->sz].num);
//	printf("请输入年龄：\n");
//	scanf("%d", &p->data[p->sz].age);
//	p->sz++;
//}
//void Del(pcon p)
//{
//	int i = 0;
//	char tmp[MAXN] = { 0 };
//	printf("请输入你要删除的名字：\n");
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
//		printf("查无此人\n");
//}
//void Search(pcon p)
//{
//	char tmp[MAXN] = { 0 };
//	int i = 0;
//	printf("请输入你要查找的人：\n");
//	scanf("%s", tmp);
//	for (i = 0; i < p->sz; i++)
//	{
//		if (strcmp(tmp, p->data[i].name) == 0)
//		{
//			printf("姓名  年龄   性别   地址   电话\n");
//			printf("%5s %5d %5s %5s %5s", p->data[i].name, p->data[i].age, p->data[i].sex, p->data[i].addr, p->data[i].num);
//			printf("\n");
//			break;
//		}
//	}
//	if (i == p->sz)
//		printf("查无此人\n");
//}
//void Modify(pcon p)
//{
//	int i = 0;
//	char tmp[MAXN] = { 0 };
//	printf("请输入你要修改的人名；\n");
//	scanf("%s", tmp);
//	for (i = 0; i < p->sz; i++)
//	{
//		if (strcmp(tmp, p->data[i].name) == 0)
//		{
//			printf("请输入姓名：\n");
//			scanf("%s", p->data[i].name);
//			printf("请输入性别：\n");
//			scanf("%s", p->data[i].sex);
//			printf("请输入地址：\n");
//			scanf("%s", p->data[i].addr);
//			printf("请输入电话：\n");
//			scanf("%s", p->data[i].num);
//			printf("请输入年龄：\n");
//			scanf("%d", &p->data[i].age);
//		}
//	}
//	if (i == p->sz)
//		printf("查无此人\n");
//
//}
//void Show(pcon p)
//{
//	int i = 0;
//	printf("姓名  年龄   性别   地址   电话\n");
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
//		printf("请输入选项>");
//		scanf("%d", &input);
//		//while (1)
//		//{
//
//		//	if (input >= 0 && input < 8)
//		//		break;
//		//	else
//		//		printf("选择有误！");
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