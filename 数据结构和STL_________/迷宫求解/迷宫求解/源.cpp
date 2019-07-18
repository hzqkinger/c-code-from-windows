#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdio.h>
#include<assert.h>
#include<Corewindow.h>

#define Stack_init_size 100
#define Stack_increment 10

#define DateType int
typedef struct{
	DateType *base;
	DateType *top;
	int stacksize;
}Stack1;

void Initstack(Stack1& s)//¢Ù
{
	s.base = (DateType*)malloc(Stack_init_size*sizeof(DateType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.stacksize = Stack_init_size;
}
void Push(Stack1& s, DateType e)//¢Þ
{
	if (s.top - s.base >= s.stacksize)
	{
		s.base = (DateType*)realloc(s.base, (s.stacksize + Stack_increment)*sizeof(DateType));
		if (!s.base)
			exit(-1);
		s.top = s.base + s.stacksize;
		s.stacksize += Stack_increment;
	}
	*s.top++ = e;
}
void Pop(Stack1& s)//¢ß
{
	if (s.top == s.base)
		exit(-1);
	--s.top;
}

void setmap(char(*arr)[10],char(*arr2)[10])
{

	char arr2[10][10] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
		1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
		1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};
	char arr[10][10] = {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 1, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
		1, 0, 1, 1, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
		1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};

}
void Showarr(char (*arr)[10])
{
	int i, j;
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

int Is_push_pop(char(*arr)[10], int x, int y)
{
	if (arr[x][y - 1] + arr[x][y + 1] + arr[x - 1][y] + arr[x + 1][y] - 4 * '0' == 4)
		return 0;
	else
		return 1;
}

void Escape(char(*arr)[10], int x, int y)
{

}
int main()
{
	Stack1 sta;
	int x = 1, y = 1;
	//ÉèÖÃÃÔ¹¬µØÍ¼

	Showarr(arr);
	Initstack(sta);

	while (1)
	{
		if (Is_push_pop(arr, x, y))
		{
			arr[x][y] = '1';
			Push(sta, x);
			Push(sta, y);

		}
		else
		{
			arr[x][y] = '0';
			Pop(sta);
			Pop(sta);
		}
	}

	system("pause");
	return 0;
}