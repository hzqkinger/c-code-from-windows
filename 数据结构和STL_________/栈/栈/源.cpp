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
void Destroystack(Stack1& s)//¢Ú
{
	free(s.base);
	s.base = s.top = NULL;
	s.stacksize = 0;
}
void Clearstack(Stack1& s)//¢Û
{
	s.top = s.base;
	s.stacksize = 0;
}
int StackIsempty(Stack1 s)//¢Ü
{
	assert(s.base);
	if (s.top - s.base)
		return 1;
	else
		return 0;
}
DateType Gettop(Stack1 s,DateType& e)//¢Ý
{
	if (StackIsempty(s))
	{
		e = *(s.top - 1);
		return e;
	}
	else
		exit(-1);
}
void Push(Stack1& s,DateType e)//¢Þ
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
void Pop(Stack1& s,DateType& e)//¢ß
{
	if (s.top == s.base)
		exit(-1);
	e = *--s.top;
}
int Stacklength(Stack1 s)//¢à
{
	return s.top - s.base;
}
void Stackshow(Stack1 s)
{
	while (s.base < s.top)
	{
		cout << *s.base++ <<endl;
	}
}
int main()
{
	Stack1 sta;
	int e;

	system("pause");
	return 0;
}