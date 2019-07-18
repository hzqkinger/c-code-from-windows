#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<assert.h>


#include"mylist.h"

template<class T>
void Printlist(const Mylist<T>& l)
{
	Mylist<T>::ConstIterator it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

template<class T>
void Printlist2(/*const */Mylist<T>& l)
{
	//Mylist<T>::Iterator it = l.Begin();

	//Mylist<T>::ReverseIterator rit(it);

	Mylist<T>::ReverseIterator rit = l.RBegin();

	while (rit != l.REnd())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void testlist()
{
	Mylist<int> l;
	l.Pushback(1);
	l.Pushback(2);
	l.Pushback(6);
	l.Pushback(4);
	l.Pushback(5);

	Printlist(l);

	Printlist2(l);
}


int main()
{
	testlist();

	system("pause");
	return 0;
}