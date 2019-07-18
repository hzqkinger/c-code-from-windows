#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

#include"Myset.h"
#include"Mymap.h"

void test_Set()
{
	Set<int> s;
	cout << s.Insert(3) << endl;
	cout << s.Insert(3) << endl;
	cout << s.Insert(1) << endl;
	cout << s.Insert(5) << endl;
	cout << s.Insert(9) << endl;

	Set<int>::Iterator it = s.Begin();
	for (; it != s.End(); ++it)
	{
		cout << *it << " ";
	}cout << endl;

	Set<int>::Const_Iterator it2 = s.CBegin();
	for (; it2 != s.CEnd(); ++it2)
	{
		cout << *it2 << " ";
	}cout << endl;
}

#include<string>
void test_Map()
{
	Map<string, string> dict;
	dict.Insert(make_pair("dic", "×Öµä"));
	dict.Insert(make_pair("insert", "²åÈë"));
	dict.Insert(make_pair("map", "Í¼"));
	dict.Insert(make_pair("set", "¼¯ºÏ"));
	dict.Insert(make_pair("left", "×ó±ß"));
	dict["left"] = "Ê£Óà";
	//dict["set"] = "ÉèÖÃ";
	Map<string, string>::Iterator it = dict.Begin();
	for (; it != dict.End(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	//Map<int, int> di;
	//di.Insert(make_pair(3, 1));
	//di.Insert(make_pair(1, 1));
	//di.Insert(make_pair(5, 1));
	//di.Insert(make_pair(3, 1));
	//di.Insert(make_pair(7, 1));
	//di.Insert(make_pair(9, 1));
	//di.Insert(make_pair(10, 1));


	//Map<int, int>::Iterator it2 = di.Begin();
	//for (; it2 != di.End(); ++it2)
	//{
	//	cout << it2->first << " " << it2->second << endl;
	//}
}

int main()
{
	test_Map();
	//test_Set();
	system("pause");
	return 0;
}