#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdio.h>
#include<assert.h>
#include<ctype.h>
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
		cout << *s.base++;
	cout << endl;

}

char precede(char t, char e)
{
	switch (t)
	{
	case'+':
		if (e == '+' || e == '-' || e == ')' || e == '#')return '>';
		else return '<';
	case'-':
		if (e == '+' || e == '-' || e == ')' || e == '#')return '>';
		else return '<';
	case'*':
		if (e == '(')return '<';
		else return '>';
	case'/':
		if (e == '(')return '<';
		else return '>';
	case'(':
		if (e == ')')return '=';
		else return '<';
	case'#':
		if (e == '#')return '=';
		else return '<';
	}
}

int main()
{
	char ch,e = '#';
	Stack1 optr, dst;
	Initstack(optr);
	Initstack(dst);
	Push(optr, e); e = getchar();

	while (*(optr.top - 1) != '#' || e != '#')
	{
		if (isalnum(e))
		{
			Push(dst, e);
			e = getchar();
		}
		else
		{
			switch (precede(*(optr.top - 1), e))
			{
			case'<':
				Push(optr, e);
				e = getchar();
				break;
			case'=':
				Pop(optr,ch);
				e = getchar();
				break;
			case'>':
				while (precede(*(optr.top - 1), e)== '>')
				{
					Pop(optr, ch);
					if (ch != '(')
						Push(dst, ch);
				}
				if (e == ')')
					break;
				if (e != '#')
				{
					Push(optr, e);
					e = getchar();
				}
				break;
			}
		}
	}
	Stackshow(dst);
	system("pause");
	return 0;
}