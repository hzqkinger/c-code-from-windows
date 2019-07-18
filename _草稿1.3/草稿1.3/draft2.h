#pragma once

#include <map>
void test1()  //  [下界，上界)
{
	map<char, int> mymap;
	pair<map<char, int>::iterator, map<char, int>::iterator> ret;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	//ret = mymap.equal_range('c');

	//cout << "lower bound points to: ";
	//cout << ret.first->first << " => " << ret.first->second << endl;

	//cout << "upper bound points to: ";
	//cout << ret.second->first << " => " << ret.second->second << endl;

	map<char,int>::iterator it = mymap.find('a');
	cout << it->first << "=>" << it->second << endl;

	size_t cnt = mymap.count('a');
	cout << cnt << endl;
	cnt = mymap.count('x');
	cout << cnt << endl;
}

#include<string>
void test2()
{
	string s = "sss";
	cout << s.size() << endl;

	string str = "We think in generalities, but we live in details.";
	// quoting Alfred N. Whitehead
	string str2, str3;
	size_t pos;

	str2 = str.substr(12, 1); // "generalities"

	pos = str.find("live");    // position of "live" in str
	str3 = str.substr(pos);   // get from "live" to the end

	cout << str2 << endl;
	cout << str3 << endl;
}
#include <iostream>
#include <map>
using namespace std;

void test3()
{
	map<char, int> mymap;
	map<char, int>::iterator it;

	// insert some values:
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	it = mymap.find('b');
	mymap.erase(it);                   // erasing by iterator

	mymap.erase('c');                  // erasing by key

	it = mymap.find('e');
	mymap.erase(it, mymap.end());    // erasing by range

	// show content:
	for (it = mymap.begin(); it != mymap.end(); it++)
		cout << (*it).first << " => " << (*it).second << endl;
}

void test4()
{
	int a = 1;
	//int &ra = a, &&ref = ra;//错 （无法将右值引用绑定到左值）
	//int *&refp = &a;//错 （非常量的初始化必须用左值）
	//int &*refp2 = &a;//错 （不允许指向引用的指针）
	int *pf, *&pref = pf;
}

void func5(char p[10])
{
	printf("%d\n",sizeof(p)); // 4
}
void func5_1(char(&p)[10])
{
	printf("%d\n",sizeof(p)); // 10
}
void func5_2(char(*p)[10])
{
	printf("%d\n", sizeof(p)); // 4
}
void test5()
{
	char array[] = "abcdefg";
	printf("%d\n",sizeof(array)); // 8
	char *p = "abcdefg";
	printf("%d\n",sizeof(p)); // 4

	char arr1[10];
	func5(arr1);//4
	char(&ap)[10] = arr1;
	func5_1(ap);//10
	char(*ap2)[10] = &arr1;
	func5_2(ap2);//4

	printf("%d\n",sizeof(char[2])); // 2
	printf("%d\n",sizeof(char&)); // 1
}

class classA
{
public:
	classA()
	{
		clear();
	}
	virtual ~classA()
	{
	}
	void clear()
	{
		memset(this , 0 , sizeof(*this));
	}
	virtual void func()
	{
		printf("func\n");
	}
};
class classB : public classA
{
};
void test6(void)
{
	classA oa;
	classB ob;
	classA * pa0 = &oa;
	classA * pa1 = &ob;
	classB * pb = &ob;
	oa.func(); // 1
	ob.func(); // 2
	//pa0->func(); // 3  只有3是错的
	pa1->func(); // 4
	pb->func(); // 5
}

class CBase
{
public:
	void func()
	{
		Print();
	}
	virtual void Print()
	{
		cout << "CBase::Print" << endl;
	}
};
class CDerived : public CBase
{
public:
	virtual void Print()
	{
		cout << "CDerived::Print" << endl;
	}
};
void test7(void)
{
	CDerived c;
	CBase *p = &c;
	cout << sizeof(*p) << endl;//4
	p->Print();
	c.func();//CDerived::Print CDerived::Print
}
/*
struct Thing
{
	int valueA;
	const int valueB;//如果把这句屏蔽掉，①可以跑过；②在跑时，会说使用了未初始化的局部变量
};
Thing t;//①在这里，运行通不过
void test8()
{
	//Thing t;//②在这里，编译都通不过
	cout << t.valueA << endl;
	cout << t.valueB << endl;
}
《C++ Primer》中提到在以下三种情况下需要使用初始化成员列表：
情况一、需要初始化的数据成员是对象的情况(这里包含了继承情况下，通过显示调用父类的构造函数对父类数据成员进行初始化)； 
情况二、需要初始化const修饰的类成员或初始化引用成员数据；
情况三、子类初始化父类的私有成员；
*/

struct st
{
	char ch ,*ptr;
	union /* u */
	{
		short a , b;
		unsigned int c : 2 , d : 1;
	};
	bool f;
	struct st *next;
};
struct st2
{
	class s{};class s2{};class s3{};
};
struct st3
{
	class {};class {};class {};
};
struct st4
{
	typedef class {}s; typedef class {}s2; typedef class {}s3;
};
void test9()
{
	//for (int x = 0 ,y = 0; !x && y <= 5; y++)
	//	cout << y << endl;
	//cout << sizeof(st::u) << endl;
	cout << sizeof(st) << endl;
	cout << sizeof(st2) << endl;
	cout << sizeof(st3) << endl;
	cout << sizeof(st4) << endl;
}

int global;
static int s_global;
void test10()
{
	static int s_local;
	cout << global << endl;
	cout << s_global << endl;
	cout << s_local << endl;
	//①变量分为：1.全局变量；2.全局静态变量；3.局部静态变量；4.局部变量
	//②1,2,3的存储方式都是静态存储方式；4则存放在内存的栈区
	//③1,2,3在没有被程序员初始化的时候，则由编译器初始化为0
}
#include<vector>
void test11()
{
	int n; std::cin >> n;
	std::vector<int> arr1(2*n+1); arr1[0] = 1;
	std::vector<int> arr2(2*n+1);

	for (int i = 1; i < n; ++i)
	{
		for (int k = 0; k < 2 * i + 1; ++k)
		{
			if (k - 1 < 0)arr2[k] = arr1[k];
			else if (k - 2 < 0)arr2[k] = arr1[k] + arr1[k - 1];
			else arr2[k] = arr1[k] + arr1[k - 1] + arr1[k - 2];
		}
		swap(arr1, arr2);
	}

	int i = 0;
	for (; i < n; ++i)
	{
		if (!(arr1[i] % 2))
		{
			std::cout << i + 1;
			break;
		}
	}
	if (i == n)
		std::cout << -1;
}
#include<iostream>
using namespace std;
#include<string>
#include<algorithm>


void test12()
{
	string addend; string augend;
	cin >> addend >> augend;
	int flag = 0;
	if (addend.size() < augend.size())
		swap(addend, augend);
	reverse(addend.begin(), addend.end());
	reverse(augend.begin(), augend.end());

	int i = 0;
	for (; i < addend.size() && i < augend.size(); ++i)
	{
		addend[i] += augend[i] - '0' + flag;
		if (addend[i] > '9')
		{
			addend[i] -= 10;
			flag = 1;
		}
		else flag = 0;
	}

	for (; i < addend.size() && flag == 1; ++i)
	{
		addend[i] += flag;
		if (addend[i] > '9')
		{
			addend[i] -= 10;
			flag = 1;
		}
		else flag = 0;
	}

	if (flag == 1)
		addend += '1';
	reverse(addend.begin(), addend.end());
	cout << addend;
}

void test13()
{
	int N; cin >> N;
	int first = 1, second = 1;
	for (int i = 3; i <= N; ++i)
	{
		first += second;
		swap(first, second);
	}
	cout << second;
}

void test14()
{
	static char *s[] = { "", "", "pink", "" };
	char **ptr[] = { s + 3, s + 2, s + 1, s },***p;
	p = ptr;
	++p;
	printf("%s\n", **p + 1);
}


void test15()
{
	char *p = "abcd";
	//p[1] = 'a';
	p = "ssss";
}
//给定两个长度相等且升序的整型数组，要求把所有数字较小的元素放在一个数组，其余的放在另一个数组。
// 要求：空间复杂度为O(1)，不能使用stl容器，元素之间的相对位置不能改变。
void test16(int left[],int right[],int n)
{
	//假设left，right数组以及n都是合法的，不需要判断检验
	if (left[0] > right[0])swap(left, right);//小元素都在left数组；大元素都在right数组
	int right_index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (left[i] < right[right_index])
			continue;
		int tmp = right[right_index];

		bool flag = true;int j = right_index;int *sp = right;
		for (; j > i || flag ; --j)
		{
			if (j == 0)
			{
				right[j] = left[n - 1];
				sp = left;
				j = n;
				flag = false;
			}
			else
				sp[j] = sp[j - 1];
		}
		left[i] = tmp;
		++right_index;
	}
	while (right_index < n)//这个循环的目的是把right数组调整为有序的
	{                      //如果没有要求right数组有序的话，这个循环可以不要
		int j = right_index - 1;
		int tmp = right[right_index];
		while (right[j] > tmp)
		{
			right[j + 1] = right[j];
			--j;
		}
		right[j + 1] = tmp;

		++right_index;
	}
}

#include<iostream>
using namespace std;
#include<string>

void adjust(const char &ch, const int &N, int &left, int &index, int &right)
{
	if (N <= 4)//当N <= 4 时，只需要调整index即可
	{
		if (ch == 'D')
			index = (index + 1) % N;
		else
			index = (index + N - 1) % N;
	}
	else //否则需要调整left,index,right
	{
		if (index == 0 && ch == 'U')//特殊向上翻页
		{
			index = (index + N - 1) % N;
			right = N - 1;
			left = N - 4;
		}
		else if (index == N - 1 && ch == 'D')//特殊向下翻页
		{
			index = (index + 1) % N;
			left = 0;
			right = 3;
		}
		else if (ch == 'U')//一般向上翻页
		{
			index = (index + N - 1) % N;
			if (index < left)
			{
				--left; --right;
			}
		}
		else//一般向下翻页
		{
			index = (index + 1) % N;
			if (index > right)
			{
				++left; ++right;
			}
		}
	}
}
void test17()
{
	int N; string str;
	while (cin >> N >> str)
	{
		//getline(cin, str);//得到输入的命令
		int left = 0, right = 3;//这里表示划动窗口   
		if (N < 4)right = N - 1;
		int index = 0;//表示光标所指向的位置
		for (int i = 0; i < str.size(); ++i)
		{
			adjust(str[i], N, left, index, right);
		}

		for (; left <= right; ++left)
		{
			if (left == right)
				cout << left + 1 << endl;
			else
				cout << left + 1 << " ";
		}
		cout << index + 1 << endl;
	}

}
void test_draft2()
{
	//test1();//map::   pair<iterator,iterator> equal_range(const key_type& x);    [下界，上界)
	//                map<key_type, value_type>::iterator find(const key_type& x);
	//                size_t count(const key_type& x);

	//test2();// string::   string substr(size_t pos = 0,size_t n = npos);
	//                    size_t find ( const string& str, size_t pos = 0 ) const;
	//					  size_t find(const char* s, size_t pos, size_t n) const;
	//					  size_t find(const char* s, size_t pos = 0) const;
	//					  size_t find(char c, size_t pos = 0) const;

	//test3();//map::   void erase ( iterator position );
	//           size_type erase(const key_type& x);
	//                void erase(iterator first, iterator last);  //[first,last)

	//test4();//引用
	//test5();//sizeof(各种数组和指针)
	//test6();//虚函数的调用
	//test7();//虚函数的相关
	//test8();//结构体成员变量的初始值。（未赋值时的初始值）
	//test9();//类内声明类型，类内定义类型
	//test10();
	//test12();
	//test13();
	//test15();

	//int left[] = { 1, 7, 9, 13 };
	//int right[] = { 2, 3, 5, 8 };
	//test16(left, right, sizeof(left) / sizeof(left[0]));
	//for (auto &r : left)cout << r << " "; cout << endl;
	//for (auto &r : right)cout << r << " "; cout << endl;

	test17();
}

int aa = 9;

