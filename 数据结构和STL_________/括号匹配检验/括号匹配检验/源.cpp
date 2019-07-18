#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<ctype.h>
#include<assert.h>
#include<Corewindow.h>

#define Stack_init_size 100
#define Stack_increment 10

#define DateType char
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
void Pop(Stack1& s, DateType& e)//¢ß
{
	if (s.top == s.base)
		exit(-1);
	e = *--s.top;
}
void Stackshow(Stack1 s)
{
	while (s.base < s.top)
	{
		cout << *s.base++ << endl;
	}
}

int IsParenthese(char c)
{
	if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
		return 1;
	else
		return 0;
}
int Isleft(char c)
{
	assert(IsParenthese(c));
	if (c == '(' || c == '[' || c == '{')
		return 1;
	else
		return 0;
}
int Punct_srt(char c)
{
	assert(IsParenthese(c));
	if (c == '[' || c == ']')
		return 0;
	else if (c == '(' || c == ')')
		return -1;
	else
		return 1;
}


int main()
{
	Stack1 sta;
	char e = '0';
	Initstack(sta);

	DateType*p1 = sta.base;
	int cnt = 10;
	while (1)
	{
		cin >> e;
		if (IsParenthese(e))
			break;
		else
			cout << "please enter parenthese" << endl;
	}
	Push(sta, e);
	while (cnt--)
	{
		cin >> e;
		
		if (sta.top > sta.base)
			p1 = sta.top - 1;
		if (Isleft(*p1) == Isleft(e) && IsParenthese(e))
			Push(sta, e);
		else if (Punct_srt(*p1) == Punct_srt(e))
			Pop(sta, e);
	}
	printf("\n");
	Stackshow(sta);
	system("pause");
	return 0;
}