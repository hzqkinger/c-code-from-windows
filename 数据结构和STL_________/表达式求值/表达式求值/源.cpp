#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<assert.h>
#include<ctype.h>
#include<CoreWindow.h>


#define Stack_init_size 100
#define Stack_increment 10

#define DateType int
typedef struct{
	DateType *base;
	DateType *top;
	int stacksize;
}Stack1;

void Initstack(Stack1& s)//①
{
	s.base = (DateType*)malloc(Stack_init_size*sizeof(DateType));
	if (!s.base)
		exit(-1);
	s.top = s.base;
	s.stacksize = Stack_init_size;
}
void Push(Stack1& s, DateType e)//⑥
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
void Pop(Stack1& s, DateType& e)//⑦
{
	if (s.top == s.base)
		exit(-1);
	e = *--s.top;
}
int StackIsempty(Stack1 s)//④
{
	assert(s.base);
	if (s.top - s.base)
		return 1;
	else
		return 0;
}
DateType Gettop(Stack1 s)//⑤
{
	if (StackIsempty(s))
		return *(s.top - 1);
	else
		exit(-1);
}
void Stackshow(Stack1 s)
{
	while (s.base < s.top)
	{
		cout << *s.base++ << endl;
	}
}

char Precede(char t, char c)
{
	switch (c)
	{
	case '+':
		if (t == '+' || t == '-' || t == '*' || t == '/' || t == ')')
			return '>';
		else
			return'<';
		break;
	case '-':
		if (t == '+' || t == '-' || t == '*' || t == '/' || t == ')')
			return '>';
		else
			return '<';
		break;
	case '*':
		if (t == '*' || t == '/')
			return '>';
		else
			return '<';
		break;
	case '/':
		if (t == '*' || t == '/')
			return '>';
		else
			return '<';
		break;
	case '(':
		return '<';
		break;
	case ')':
		if (t == '(')
			return '=';
		else
			return '>';
		break;
	case '#':
		if (t == '#')
			return '=';
		else
			return '>';
		break;
	}
	return 'h';
}//Precede
int Operate(int a, int theta, int b)
{
	switch ((char)theta)
	{
	case '+':
		return a + b;
		break;
	case'-':
		return a - b;
		break;
	case'*':
		return a * b;
		break;
	case'/':
		return a / b;
		break;
	}
}
int main()
{
	int c, a, d, b;
	Stack1 optr, opnd;
	printf("该计算器只能成功计算十以内的四则运算，注：表达式中用'#'代替'='\n");
	Initstack(optr); Push(optr, '#');
	Initstack(opnd); c = getchar();
	while (c != '#' || Gettop(optr) != '#')
	{
		if (!ispunct(c))
		{
			Push(opnd, c - '0');
			c = getchar();
		}
		else
			switch (Precede(Gettop(optr), c)){
			case'<':
				Push(optr, c);
				c = getchar();
				break;
			case'=':
				Pop(optr, c);
				c = getchar();
				break;
			case'>':
				Pop(optr, d);
				Pop(opnd, b);
				Pop(opnd, a);
				Push(opnd, Operate(a, d, b));
				break;
		}
	}
	printf("%d\n", *opnd.base);
	system("pause");
	return 0;
}