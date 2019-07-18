#pragma once

//class CC//判断两个继承关系的类那个是父类（捕异常的方法貌似不行）
//{
//public:
//	int c;
//};
//class DD :public CC
//{
//public:
//	int d;
//};
//void test11()
//{
//	CC *pc = new CC;
//	DD *pd = new DD;
//	try
//	{
//		pd = pc;
//		pc = pd;
//
//	}
//}

//class point
//{
//public:
//
//	point(int xx, int yy);
//	point();
//
//private:
//	int x, y;
//};
//point::point(int xx = 0, int yy = 0)//这里带有默认参数，造成有多个默认构造函数。
//{
//	x = xx;
//	y = yy;
//}
//point::point()
//{
//	x = 0;
//	y = 0;
//}

#include<stack>
void Test20()
{
	////int **p = NULL;
	////char c[5 + 3];
	//char ch;
	//ch = -127 - 128;
	//printf("%d\n", ch);
	int i = 0;
	(++++++++i)++;
	cout << i << endl;
	//i++ = 15;

	stack<int> s;
	s.push(1);
	s.top() = 10;
	//while (cin >> i)
	//{
	//	cout << "输入非i类型的值时，循环结束" << endl;//但是最后输入的字符还在缓冲区5
	//}
	////string name;
	////while (cin >> name)
	////{
	////	cout << "按键ctrl z结束输入" << endl;//但是结束循环后，ctrl z还在缓冲区里
	////}
	printf("%.2f\n", 2.6666);//这里居然会四舍五入
	cout << sizeof(double) << endl;
	cout << sizeof(long double) << endl;
	cout << sizeof(3ll) << endl;
	cout << sizeof(L"aa") << endl;
	cout << sizeof(10.) << endl;
	cout << sizeof(10e-2) << endl;

	int page_39 = 0;
	int page2_39 = { 0 };
	int page3_39(0);
	int page4_39{ 0 };

	//cin >> int intput;//错
	//double salary = wage = 9.7;//错
	int __un = 1;
	int _Un = 2;
	int i3;//声明且定义变量i3
	int &r3 = i3;//r3是i3的引用
	int &r4 = r3;
	&r4;

	int i4 = 0, &r5 = i4;
	double d = 0, &r6 = d;
	r5 = 3.1415;
	r6 = r5;
	i4 = r6;
	r5 = d;

	int *p = nullptr;
}
int _uuu = 2;

extern const int buffer;
extern int buffer2;
void teSt0()
{
	cout << buffer << endl;
	cout << buffer2 << endl;
}

struct ss
{
	enum uu
	{
		a,
		b,
		c,
	};
	int aa;
};
void teSt1()
{
	cout << sizeof(enum uu) << endl;
	cout << sizeof(ss) << endl;
}

class S2
{
public:
	int aa = 2;  //c++11新标准规定，可以为数据成员提供一个类内初始值
	int bb = { 3 };
	int cc{ 4 };
	//int dd(5);错
};
#include<string>
void teSt2()
{
	string s1 = "123";
	string s2 ="456"+ s1;
	//string s3 = "12" + "34"+ s1;//切记，不能把字面值直接相加
	string s3 = s1 + "12" + "34";
	for (auto c : s3)//c++11新标准提供的范围for语句
	{
		cout << c << " ";
	}
	cout << endl;
	string s4 = "some s tr   ing";
	for (size_t i = 0; i < s4.size(); ++i)//将每个单词的首字母改成大写
	{
		if (i == 0 || (s4[i - 1] == ' ' && s4[i] != ' '))
		{
			s4[i] = toupper(s4[i]);
		}
	}
	cout << s4 << endl;
	//double d = 3.1415;
	//const int *p = d;
	//typedef int* pint;
	//const pint p2 = d;
	int const i = 10;
}

#include<string>
#include<cctype>
//输入秒数，输出一个sting对象，(注意，不计闰年，不计大小月)eg.输入：10，输出：1910 01 01 00:00:10
string Second()
{
	string str("01970 01 01 00:00:00");
	long long int second;//只要输入的second不超出long long的范围，都能正确输出日期
	cin >> second;
	int year = second / (60 * 60 * 24 * 365); second %= 60 * 60 * 365;
	int month = second / (60 * 60 * 24 * 30);second %= 60 * 60 * 30;
	int day = second / (60 * 60 * 24); second %= 60 * 60 * 24;
	int hour = second / (60 * 60);second %= 60 * 60;
	int min = second / 60;second %= 60;
	int arr[6] = { year, month, day, hour, min, second };
	size_t i = 4, tmpi = i,j = 1;
	while (i > 0 || year)//处理年份
	{
		if (i == 0)
		{
			str.insert(0, 1, year % 10 + '0');//如果初始year<=99999-1970,那么这步不会执行。
			year /= 10; tmpi++;
		}
		else
		{
			str[i] += year % 10;
			if (!isdigit(str[i])){str[i] -= 10;str[i - 1] += 1;}
			year /= 10;--i;
		}
	}
	i = tmpi + 3;
	while (j < 6)//处理月日时分秒
	{
		tmpi = i - 2;
		while (i > tmpi || arr[j])
		{
			str[i] += arr[j] % 10;
			if (!isdigit(str[i])){str[i] -= 10;str[i - 1] += 1;}
			arr[j] /= 10;--i;
		}
		i += 5; j++;
	}
	return str[0] == '0' ? string(str.c_str()+1, str.c_str() + str.size()) : str;
}

#include<vector>
int nnn(){ return 5; }
void teSt3()
{
	vector<int> v(10);//初始化
	v.reserve(15);//这只能说明v的capacity的大小是15，
	size_t j = 0;
	for (auto &c : v) //范围for语句
	{
		c = j++;
	}
	for (size_t i = 0; i < v.size(); ++i){ cout << v[i] << " "; }cout << endl;

	vector<int>::iterator it = v.begin();
	for (; it != v.end(); ++it){ cout << *it << " "; }cout << endl;


	//auto it2 = v.begin();
	//for (; it2 != v.end(); ++it2){ cout << *it2 << " "; }cout << endl;
	//vector<int>::reverse_iterator it3 = v.rbegin();

	int *p = (int*)malloc(100);
	//int arr[nnn()];
}

void teSt4(int n, ...)
{
	va_list arg;
	va_start(arg, n);
	int sum = 0;
	for (size_t i = 0; i < n; ++i)
	{
		sum += va_arg(arg, int);
	}
	cout << sum << endl;
	va_end(arg);
}

#include<initializer_list>
void teSt5(initializer_list<int> il)
{
	initializer_list<int>::iterator it = il.begin();
	int sum = 0;
	for (; it != il.end(); ++it){sum += *it;}
	cout << sum << endl;
}
class Mycls5{
public:
	Mycls5(int, int){ cout << "normal constructor" << endl; }
	Mycls5(initializer_list<int>){ cout << "special constructor" << endl; }
};

void teSt6(int a = 1, int b = 2)
{
	int c = 3, d;
}

class AA7;
class BB7{
public:
	void clear(AA7 a);//BB7的成员函数
};
class AA7{
	int a = 1;//私有
public:
	friend void BB7::clear(AA7 a);//AA7的友元函数
	int b = 2;//公有
};
void BB7::clear(AA7 a)
{
	a.a = 10; a.b = 11;//可以访问私有成员，但是这里的红虚线是什么意思没搞懂
}
class ABA7{
	int a = 1;
public:
	friend void get(ABA7 a){a.a = 10;}//这里的友元函数能够访问ABA7的私有成员
};
void teSt7()
{
	AA7 a;
	BB7 b;
	b.clear(a);

	ABA7 a2;
	get(a2);
}

class A8{
public:
	A8(int i) :_i(i){}//①
	explicit A8(char ch) :_i(ch){}//②这个构造函数只能用于直接初始化
private:
	int _i;
};
void teSt8()
{
	A8 a = 1.1;//①拷贝初始化，先执行了隐式类类型转换
	A8 a3 = 5;//①拷贝初始化
	A8 a4 = 'a';//①拷贝初始化
	A8 a5(6);//①直接初始化
	//A8 a2(2.2);//假如同时存在上面两个构造函数，这里会调用不明确。//直接初始化，先执行了隐式类类型转换
	A8 a6('a');//②调用抑制构造函数
	short b = 2; char ch = 'a';
	A8 a7(b);//①
	A8 a9(ch);//②

	static int i;//局部静态变量初始化为0，(注意，还没调用该函数时候就已经初始化了)
	cout << i << endl;
}

class AA9{
	char *_str;
public:
	AA9(char *str) :_str(str){ cout << "构造函数" << endl; }
	AA9(const AA9 &a) :_str(a._str){ cout << "拷贝构造函数" << endl; }

};
int& foo9(int _b)//返回一个引用，那么就说明该函数返回一个左值
{
	_b += 1;
	//return b+5;//引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起
	return _b;//这虽然能貌似正常运行，但引用绑定到了一个函数的局部变量去了，
}
void teSt9()
{
	//AA9 a("9999999999");//直接初始化，调用构造函数
	//AA9 a2 = "555555555";//拷贝初始化，调用构造函数
	//AA9 a3(a);//直接初始化，调用拷贝构造函数
	//AA9 a4 = a;//拷贝初始化，调用拷贝构造函数
	int a = 10;
	int &c = foo9(a);//一定不要返回局部变量的引用或指针，否则结果是未定义的
	cout << c << endl;
}

//讲道理，这里有很严重的问题
class AA10{
	int a;
	int b;
	int c;
	double d;
public:
	void f1(){}
};
void teSt10()
{
	int *p1 = new int;//①讲道理，这里是内置类型，第三个不会崩
	/*free(p1);*/    /*delete p1;*/   delete[] p1;

	int *p2 = new int[10];//②
	/*free(p2); */    /*delete p2; */  delete[]p2;

	AA10 *p3 = new AA10;//③讲道理，这里第三个应该崩呀
	/*free(p3); */    /*delete p3;*/   delete[]p3;

	AA10 *p4 = new AA10[10];//④
	/*free(p4);*/    /*delete p4; */   delete[] p4;

	int *p5 = (int*)malloc(sizeof(int));//⑤讲道理，这里的第三个也应该崩
	/*free(p5);*/   /*delete p5;*/     delete[]p5;

	int *p6 = (int*)malloc(sizeof(int)* 10);//⑥讲道理，这里的第三个也应该崩
	/*free(p6);*/   /*delete p6;*/     delete[]p6;

	AA10 *p7 = (AA10*)malloc(sizeof(AA10));//⑦讲道理，这里的第三个也应该崩
    /*free(p7);*/   /* delete p7;*/     delete[]p7;

	AA10 *p8 = (AA10*)malloc(sizeof(AA10)* 10);//⑧讲道理，这里的第三个也应该崩
	/*free(p8);*/  /*delete p8;*/      delete[] p8;
}

//#define _CRT_SECURE_NO_WARNIGS
//#include<stdio.h>
//void intf(int *p)
//{
//	printf("%d\n", *p);
//	printf("%p\n", p);
//}
//int main()
//{
//	//int val = 5;
//	//intf(&val);
//	intf((int[]){ 5 });//复合字面量  （在.c文件下可以这样将字面值强转；.cpp就不行了）
//	system("pause");
//	return 0;//头文件中包含了#define EXIT_SUCCESS 0和#define EXIT_FAILURE 1
//}

void f11(int i){ cout << i << endl; }
void f11(/*float*/double d){ cout << d << endl; }
class AA11{
public:
	AA11(int i){}
	AA11(float d){}
};
void teSt11()
{
	//string s("abc");
	//string s2 = "hi" + s;
	long long lg1 = 10;
	short lg2 = 8;
	f11(lg2);//实参是lg1时有二义性；lg2时没有
	//AA11 a(lg);
}

class A12{
	int _a;
public:
	A12(int a) :_a(a){ cout << "基类构造函数" << endl; }
	A12(const A12 &a) :_a(a._a){ cout << "基类拷贝构造函数" << endl; }
	void f1(A12 a){ cout << "基类f1函数" << endl; }
	virtual void f2(int a = 10){ cout << a << endl; }
	virtual A12 f3(){ return *this; }
	virtual A12 *f4(){ return this; }
	virtual void f5()final{}
	virtual void f6(){}
	virtual void f7(){ cout << "基类f7()" << endl; }
};
class B12 :public A12{
	int _b;
public:
	B12(int a, int b) :A12(a), _b(b){ cout << "派生类构造函数" << endl; }
	B12(const B12 &b) :A12(b), _b(b._b){ cout << "派生类拷贝构造函数" << endl; }
	void f2(int a = 5){ cout << a << endl; }//①一个派生类如果要覆盖某个继承而来的虚函数，则它的形参类型必须与基类函数完全一致
	//B12 f3(){ return *this; }//②同时返回类型也要完全一致
	B12 *f4(){ return this; }//③当类的虚函数返回类型是类本身的指针或引用时，②规则失效
	//void f5(){}//错误，无法重写final函数
	//void f6(int a)override{}//假如后面有override的关键字，那么说明这个函数必须重写基类的虚函数,否则报错
	void f6(int a){}//如果没有，那么这个函数隐藏了基类的f6()函数，但他不是虚函数
	void f7(){ cout << "派生类f7()" << endl; A12::f7(); }
};
void teSt12()
{
	//B12 b(5, 6);
	//B12 b2(b);
	//cout << endl;
	//A12 a(b);//注意：当我们初始化或者赋值一个类类型的对象时，实际上是在调用某个函数
	//a.f1(b);
	////A12 a1(5);
	////A12 a2(a1);

	B12 b(5, 6);
	A12 *pa = &b;
	pa->f2();//当虚函数有默认实参的时候，那么该实参值由本次调用的静态类型决定
	//pa->f3();
	pa->f4();
	pa->f7();//使用作用域运算符可以回避虚函数的机制
}

class A13
{
public:
	static A13 GetObj(int a){ return A13(a); }//静态成员函数，在栈上创建对象①
	static A13 *GetObj2(int a){ return new A13(a); }//静态成员函数，在堆上创建对象②
	friend A13 GetObj3(int a){ return A13(a); }//友元函数，在栈上创建对象③
	friend A13 *GetObj4(int a){ return new A13(a); }//友元函数，在对上创建对象④
	void f1(){ cout << "hha" << endl; }

	A13(const A13 &a){}
private:
	int _a;
	A13(int a) :_a(a){}//将构造函数私有化,那么该类不能被继承
	~A13(){}//将析构函数私有化，那么该类对象只能在堆上new出来
};
A13 GetObj3(int a);//就算在类内定义该友元函数，也必须在类外提供声明从而使得函数可见
A13 *GetObj4(int a);
class AA13{
public:
	void ff1(){ cout << "hhhhhhhh" << endl; }
private:
	int _a;
	void *operator new(size_t i){}//重载new运算符，并且将其私有化，那么该类只能在栈上创建对象
};
void teSt13()
{
	//A13 a1(A13::GetObj(5));//调用静态方法得到一个对象，然后用拷贝构造函数初始化a1。
	//a1.f1();
	//A13 a2 = a1;
	//a2.f1();

	A13 *pa = A13::GetObj2(6);
	pa->f1();
	A13 *pa2 = pa;//这步只是简单的指针赋值语句
	pa2->f1();

	AA13 aa;
	aa.ff1();
	//AA13 *pa = new AA13;//错

}

class A14{
public:
	A14(int a, int b) :_a(a), _a2(b){}
	//友元函数必须通过该类对象，才能引用该类的所有成员（注意是必须）
	//friend void f144(){ cout << _a2 << endl; cout << _a << endl; }//错
	int _a2;
private:
	int _a;
};
//void f144();
void teSt14()
{
	A14 a(5, 6);
	//f144();
}

template<typename T> T Fobj(T a, T b)
{
	cout << "hhhhhhhhhhhhhhh";
	return T();
}
template<typename T> T Fref(const T &a, const T &b)
{
	cout << "5555555" << endl;
	return T();
}
//模板实参推断类型时，除了下面三种类型转换外，传递给这些形参的实参必须具有相同的类型
void teSt15()
{
	int a = 10;const int b = 5;
	Fobj(a, b);//①忽略顶层const：与往常一样，顶层const无论在形参还是实参中，都会被忽略
	Fref(a, b);//②const转换：可以将一个非const得对象(或指针)传递给const的引用(或指针)形参
	int c[10], d[5];
	Fobj(c, d);//调用f(int*,int*)    //③数组或者函数指针的转换
	//Fref(c, d);//错误，数组类型不匹配

	Fobj("hi", "world");//对，数组向指针的转换
	//Fref("hi", "world");//错误
}

template<typename T> void FFF(int a, T b)
{
	cout << a << " " << b;//函数模板可以有用普通类型定义的参数
}
template<typename T>auto FCN(T a, T b)->decltype(*a)
{
	return *a;//这里表示FCN的返回类型与解引用a参数的结果类型相同
}
void teSt16()
{
	string s("abc");
	FFF(5, s);
	cout << endl;
	FFF(6, 7.7);

	FCN(s.begin(), s.end());//此例返回类型是char&（因为string的迭代器解引用类型是char）
	vector<int> v = { 1, 2, 3, 4, 5 };
	FCN(v.begin(), v.end());//此例返回类型是int&
}

class A17{
};

void teSt18()
{
	const unsigned N = 10;
	int arr[N+1];//定义数组时，方括号里面必须是整型常量或者整型常量表达式
}

template<typename T>string debug_rep(const T &t)//①
{
	//ostringstream ret;
	//ret << t;
	//return ret.str();
	cout << "555555555555";
	return string();
}
template<typename T> string debug_rep(T *p)//②
{
	//ostringstream ret;
	//ret << "pointer:" << p;
	//if (p)
	//	ret << " " << debug_rep(*p);
	//else
	//	ret << "nullptr";
	//return ret.str();
	cout << "66666666666";
	return string();
}
string debug_rep(const string &s)//③
{
	cout << "7777777777777";
	return string();
}
template<typename T>void debug_rep2(const T &a, const T &b)//④
{
	cout << "1111111111" << endl;
}
template<typename T1, typename T2>void debug_rep2(const T1 &a, const T2 &b)//⑤
{
	cout << "22222222222" << endl;
}
void debug_rep2(const int &a, const char &b)//⑥
{
	cout << "333333333" << endl;
}
void teSt19()
{
	//先考虑这些重载函数可不可以匹配，再考虑哪些函数可以精确匹配，最后考虑哪些函数更特例化。
	debug_rep2(2, 5);//④⑤⑥都可以匹配，只有④⑤是精确匹配，但是④更特例化，所以会调用④
	debug_rep2(2, 'a');//④不能匹配，⑤⑥都是精确匹配，但是⑥是非模板函数(最最特例化)，所以会调用⑥
	debug_rep2('a', 2);//④不能匹配，⑤⑥都能匹配，但⑤是精确匹配，所以会调用⑤

	//cout << debug_rep("hi") << endl;
	//debug_rep(const T&),T被绑定到char[3]，精确匹配
	//debug_rep(T*),T被绑定到const char，精确匹配，但是此版本更加特例化，因此会调用它
	//debug_rep(const string&)，要求从const char*到string的类类型转换，非精确匹配，所以①②③同时存在时会调用②

	string s("hi");
	////当一个非函数模板与一个函数模板提供同样好的匹配，则选择非模板(下面的分析是在没有③的基础上的)
	//cout << debug_rep(s) << endl;//只能用①来实例化
	//cout << debug_rep(&s) << endl;//虽然用①②都可以实例化，但是②是精确匹配，所以会调用②来实例化

	//const string *sp = &s;
	//cout << debug_rep(sp) << endl;//虽然①②都是精确匹配，但是②更特例化，所以会调用②来实例化
	////debug_rep(const T&)本质上可以接受任何类型，包括指针类型
	////debug_rep(T*)只能用于指针类型，没有上面的通用
}

template<typename T,typename... args>void foo(const T &t, const args& ... ret)
{//对于一个参数包，除了获取它的大小，我们唯一能做的是对它进行扩展。
	cout << sizeof...(args) << " ";//模板参数包的类型参数的数目
	cout << sizeof...(ret) << endl;//函数参数包的函数参数的数目
}
template<typename T>ostream &Print20(ostream &os, const T &t)
{
	return os << t;
}
template<typename T,typename...args>ostream &Print20(ostream &os, const T &t, const args&...ret)
{
	os << t << " ";
	return Print20(os, ret...);
}
void teSt20()
{
	int i = 0; double d = 3.14; string s = "hi";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
	Print20(cout,i, s, 42, d);//好神奇的可变参打印函数
}

class cat{};
template<typename T>class AA21{

};
//模板实参必须是一个可以在编译期确定的模板实体或值；
//因为对于模板参数本身而言，由于最终可以被编译期的值所替换，它们就可以被用于合成编译期的表达式
void teSt21()
{
	AA21<cat> a;
}

typedef char* pea;//                                   (在编译期的时候处理)
#define app int*  //只是做了个简单的替换，无类型检查   (在预编译的时候处理)
void teSt22()
{
	char ch = 'a';
	const pea Pa = &ch;//常量指针
	pea const Pb = &ch;//常量指针
	pea Pc, Pd;//Pc和Pd都是char*型指针变量
	//unsigned pea Pe;//错，新类型别名不能用类型说明符进行扩展

	int i = 5;
	const app pa = &i;//指向常量的指针
	app const pb = &i;//常量指针
	app pc, pd;//pc是char*型指针变量，pd是char型变量
	unsigned app pe;//对，可以用类型说明符进行扩展
}

//模板参数：位于函数模板名称的前面，在一对尖括号内部进行声明  ps:T1,T2和T3都是模板参数
//调用参数：位于函数模板名称的后面，在一对圆括号内部进行声明  ps:a和b都是调用参数
template<typename T1,typename T2,typename T3>
T3 teSt23(T1 const& a,T2 const& b)//模板实参演绎并不适合返回类型，所以用户必须显式地指定模板实参列表
{
	//当模板参数和调用参数没有发生关联，或者不能有调用参数来决定模板参数的时候，你在调用时就必须显式
	//指定模板实参
}
template<typename T3,typename T1,typename T2>
T3 teSt231(T1 const& a, T2 const& b){}
template<typename T1,typename T2>
void teSt232(T1 const& a, T2 const& b){}
template<typename T>
void teSt233(T const& a, T const &b){}//注意;这里不允许自动类型转换，每个T都必须正确匹配

void teSt24()
{
	stack < int, std::vector<int, std::allocator<int>>> s1;
	stack < int, std::vector<char, std::allocator<char>>> s2;//STL库中没有使用没有使用模板的模板参数，而是使用的类型
	stack<int> s3;
	stack<int, std::deque<int, std::allocator<int>>>s4;

	s3 = s4;//对。栈之间只有类型完全相同时才能互相赋值，否则即使这两种(元素的)类型之间存在隐式类型转换也不行
	//s3 = s2;//错。缺省运算符两边不具有相同的类型
	//s3 = s1;//错。缺省运算符两边不具有相同的类型
	//ps:当然，可以通过代码来实现大多数不完全类型之间的相互赋值
}

template<typename T,template<typename /*ELE*/,typename/* ALLOC = std::allocator<ELE>*/>class con = std::vector>
class Cat25{//第二个模板参数这样写的目的是为了表明该参数是个模板而不是类型
};
template<>class Cat25<int, deque>{};//类模板的特化(ps:函数模板不能特化，必须是基本模板)
template<typename T, template<typename ELE, typename ALLOC = std::allocator<ELE>>class con = vector>
void teSt25()
{
	con<T> v;
}

#include<string>
void teSt26()
{
	string s("12a5");
	cout << stoi(s) << endl;
	int i = 12;
	char arr[10];
	cout << _itoa(i, arr, 10) << endl;//在c++中用_itoa；在c中用itoa。
}

void teSt27(char ch = 'a', int i = 0)
{//对于任何一个参数，只有在之后的参数都提供了缺省实参的前提下，它才能具有缺省实参
	int i2 = 1, i3;//注意:局部变量与参数不一样
}

class Cat280{//普通类
public:
	void f00(){ cout << "普通成员函数" << endl; }
	template<typename T>void f01(const T& a){ cout << "成员函数模板" << endl; }
	template<typename T8>class Cat2801{};//位于类内部的成员类模板，且在类外部定义
private:
	int _i;
};
void teSt28()
{
	Cat280 cc0;
	cc0.f01(5);
	Cat280::Cat2801<char> cc01;
}
template<typename T>class Cat28{//类模板
public:
	template<typename T2> Cat28(T2 const& c = T2()) :_c(c){ cout << "11" << endl; }//成员函数模板
	template<typename T6> void f(const T6& a);//成员函数模板的声明
	void f2(T const& a){ cout << "77" }//普通成员函数
	template<typename T, typename T3>class Cat281{//位于类内部的成员类模板,且在类内部定义了
	public:
		Cat281(T const& a, T3 const& b) :_cc(a), _cc2(b){ cout << "22" << endl; }
	private:
		T _cc;
		T3 _cc2;
	};
	template<typename T4,typename T5>class Cat282;//位于类内部的成员类模板，且在类外部定义
private:
	T _c;
};
template<typename T>/*外围类的类型参数*/template<typename T6>/*成员函数模板的类型参数*/
void Cat28<T>::f(const T6& a)
{
	cout << "666" << endl;
}
template<typename T>/*外围类的类型参数*/template<typename T4, typename T5>/*嵌套类的类型参数*/
class Cat28<T>::Cat282{
public:
	Cat282(T const& a, T4 const& b,T5 const& c) :_ccc1(a), _ccc2(b),_ccc3(c){cout<<"33";}                                     
	T _ccc1;T4 _ccc2;T5 _ccc3;
};

extern "C++"template<typename T>//模板名字是具有链接的，但他们不能具有C链接
void tsSt29(T const& a)
{//模板通常具有外部链接。但是有例外情况
	cout << "aaaa" << endl;
}
template<typename T>
static void teSt291(T const& a){}//该模板不具有外部链接

//例子2：  
template<class T, int MAXSIZE> class List30{
private:
	T elems[MAXSIZE];
public:
	void Print(){ cout << "The maxsize of list is " << MAXSIZE; }
};
const int num1 = 9;//全局变量  常量
static int num2 = 9;//全局变量  非常量
const static int num4 = 9;//全局变量  静态常量
//例子3：  //再看一个关于指针和字符串比较特别的例子  
template<char const* name>
class pointerT30{
};
char a[] = "saaa";;//全局变量  a是常量表达式
char *b = "saaa";//全局变量     b不是常量表达式
char *const c = "saaa";//全局变量，顶层指针，指针常量  
void teSt30()
{
	//下面解释一下非类型实参的局限
	//  0.通常而言，非类型实参可以是①常整数，或者②指向外部链接对象的指针与引用，而且绑定到该形参的实参必须
	//    是常量表达式，即在编译期就可以确定其结果(ps:注意弄清楚各种对象是内部链接还是外部链接)
	//	1.实参必须是编译时常量表达式
	//	2.非Const的全局指针，全局对象，全局变量（下面可能有个特例）都不是常量表达式。
	//	3.由于形参的已经做了限定，字符串，浮点型即使是常量表达式也不可以作为非类型实参
	//	备注：常量表达式基本上是字面值以及const修饰的变量
	const int num3 = 9;;//局部变量 常量
	List30<int, num1> L1; //正确  
	//List<int, num2> l2; //错误  
	List30<int, num3> L3; //正确  
	List30<int, num4> L4; //正确 


	char a2[] = "saaa";;//局部变量，虽然a2是常量表达式，但是它不是指向外部链接对象的指针

	//pointerT30<"testVarChar">  p1;//错误  规定字符串和浮点数都不能用作非类型参数 
	pointerT30<a>  p2;//正确  
	//pointerT30<a2>  p22;//错误，局部变量不能用作非类型参数  
	//pointerT30<b>  p3;//错误，error C2975:“pointerT”的模板参数无效，应为编译时常量表达式  
	//pointerT30<c>  p4;//错误，error C2970: “c”: 涉及带有内部链接的对象的表达式不能用作非类型参数 
}


//1）必须在类的说明中说明友元函数，说明时以关键字friend开头，后跟友元函数的函数原型，友元函数的说明可以出现在类的任何地方，包括在private和public部分；
//2）注意友元函数不是类的成员函数，所以友元函数的实现和普通函数一样，在实现时不用"::"指示属于哪个类，只有成员函数才使用"::"作用域符号；
//3）友元函数不能直接访问类的成员，只能访问对象成员，
//4）友元函数可以访问对象的私有成员，但普通函数不行；
//5）调用友元函数时，在实际参数中需要指出要访问的对象，
//6）类与类之间的友元关系不能继承。
//7）一个类的成员函数也可以作为另一个类的友元，但必须先定义这个类。
template<typename T>class Cat31{//类模板
public:
	//友元函数访问类对象时，可以只在类内声明且定义，即使这样外界也可以找到该友元函数；
	//但是当友元函数没有访问类对象时，如果不在类外额外声明或定义，那么外界无法找到该友元函数
	template<typename T2> friend void f2(Cat31<T> const& a)
	{
		cout << "1111" << endl;//友元函数模板与类模板是多对多的关系
	}
private:
	friend void f(Cat31<T> const& a)//狭义上讲普通友元与类模板是一对一的关系
	{    //该友元函数可以访问该类模板的所有实例，而实际上每个实例都有这个友元函数的重载函数
		cout << a._a << endl;
	}
	T _a;
	//friend void _f33(){}//假如f3()不在类外声明，那么外面找不到f3;
	////而且每次使用Cat31<T>都会构造_f33()函数主体，所以类模板里不会有这样的友元函数
};
//void f(Cat31<T> const& a);
class Cat311{//普通类
public:
	friend void ff(Cat311 const& a)//普通友元
	{
		cout << a._i << endl;
	}
	template<typename T> friend void ff2(Cat311 const& a)//友元函数模板
	{
		cout << "555555" << endl;
	}
private:
	int _i;
};
void teSt31()
{
	//f是普通友元函数；f2是友元函数模板（ps:_ff3是没有访问类对象的普通友元，类模板中一般不会出现这样的友元，原因如上）
	Cat31<int> c;
	f(c);//会实例化出void f(Cat31<int> const& a){}
	f2<char>(c); /*f2(c);*///会实例化出template<char>void f2(Cat31<int> const& a){}
	f2<float>(c);//会实例化出template<float>void f2(Cat31<int> const& a){}

	Cat31<char> ch;
	f(ch); //会实例化出void f(Cat31<char> const& a){}
	f2<int>(c);//会实例化出template<char>void f2(Cat31<char> const& a){}
	f2<float>(ch);//会实例化出template<float>void f2(Cat31<char> const& a){}
	//_f33();

	Cat311 cc;
	ff(cc);//普通类的普通友函数
	ff2<int>(cc);//普通类的友元函数模板
}

template<typename T>class Cat32
{
public:
	typedef vector<T> intv;//类模板的类型成员
	static std::size_t Count(){ cout << "222" << endl; return Ctr; }
private:
	static std::size_t Ctr;//静态数据成员的声明
};
template<typename T>size_t Cat32<T>::Ctr = 0;//静态数据成员的定义（ps:静态成员的初始化必须在类外）
void teSt32()
{
	Cat32<int>::Count;//哇，这样居然没有报错
	Cat32<int>::Count();//通过实例化的类直接访问静态成员
	//Cat::Count();错。如果想通过类直接访问静态成员，那么必须用实例化的类去访问

	//  1.静态成员函数中不能调用非静态成员。
	//	2.非静态成员函数中可以调用静态成员。因为静态成员属于类本身，在类的对象产生之前就已经存在了，所以在非静态成员函数中是可以调用静态成员的。
	//	3.静态成员变量使用前必须先初始化(如int MyClass::m_nNumber = 0;)，否则会在linker时出错。
	//	4.在类的非静态成员函数中使用类的静态成员
	Cat32<char> fi;
	fi.Count();//通过对象访问静态成员
}

class Cat33{//普通类
public:
	typedef vector<int> intv;
	static int intv2;
};
int Cat33::intv2 = 0;
Cat33::intv ff3(){ cout << "5555555" << endl; return Cat33::intv(); }
////在普通类中，编译器掌握类的定义，所以能够分清哪个是类的类型成员，哪个是类的静态成员
template<typename T> class Cat333{//类模板
public:
	typedef vector<T> intv3;
	typename Cat32<T>::intv ff31{ cout << "6666" << endl; }//在类模板中使用了Cat32<T>的类型成员
	//如果我们希望使用一个模板类型参数的类型成员，就必须用关键字typename告诉编译器这是一个类型
	static T intv23;
};
//template<typename T> T Cat333<T>::intv23 = 0;//这intv23怎么就不是Cat333<T>的成员呢？？？？

template<typename T>int compare34(const T& a, const T& b)//①比较任意类型
{
	cout << "11111111111" << endl;
	return a > b ? 1 : a == b ? 0 : -1;
}
template<size_t N, size_t M>int compare34(const char(&a)[N], const char(&b)[M])//②处理字符串字面常量
{
	cout << "2222222222222" << endl;
	return strcmp(a, b);
}
template<>int compare34(const char* const &p1, const char* const &p2)//③处理字符数组的指针
{//一个特例化版本本质上是一个实例
	cout << "333333333333" << endl;
	return strcmp(p1, p2);
}
//当我们不能或者不希望使用模板版本时，可以定义类或函数模板的一个特例化版本。
void teSt34()
{
	const char *p1 = "hi1", *p2 = "mom1";
	char a1[] = "hi3"; char a2[] = "mom3";
	compare34(p1, p2);
	compare34("hi2", "mom2");
	compare34(a1, a2);
	compare34(5, 7);
}

void test_draft5()
{
	//Test20();
	//teSt0();//extern
	//teSt1();//sizeof(enum)与sizeof(struct)
	//teSt2();//测试string
	//string time;
	//time = Second();
	//cout << time << endl;
	//teSt3();a
	//teSt4(4,4,5,6,7);//c语言可变参求和
	//teSt5({ 1, 2, 3, 4, 5, 'a' });//c++初始化列表，接受花括号内的元素列表作为参数
	////                         （缺点：元素列表里的元素必须是相同类型或者说可以转化为可接受类型）
	//Mycls5 M51(5, 6);//调用普通的构造函数
	//Mycls5 M52{ 5, 6 };//调用具有初始化列表的构造函数
	//Mycls5 M53 = { 5, 6 };//调用具有初始化列表的构造函数
	//teSt7();//友元函数再探
	//teSt8();
	//teSt9();//不要返回局部变量的引用
	//teSt10();//delete与free等不匹配问题（貌似出现了很严重的问题）
	//teSt11();//函数调用是否有二义性
	//teSt12();//继承与虚函数
	//teSt13();//①构造函数私有化②析构函数私有化③重载new运算符
	//teSt14();//友元函数必须通过该类对象，才能引用该类的所有成员（注意是必须）


	//teSt15();//模板参数类型推断，const转换和数组或函数向指针的转换
	//teSt16();//函数模板可以有用普通类型定义的参数+尾置返回类型
	//cout<<sizeof(A17);//强烈建议看懂《深度探索C++对象模型》
	//teSt18();//定义数组时，方括号里面必须是整型常量或者整型常量表达式
	//teSt19();//重载与模板，从实参类型推断调用那个函数
	//teSt20();//可变参模板
	//teSt21();
	//teSt22();//#define和typedef的一些区别
	//函数模板的实参演绎
	//teSt23<int,char,double>(2,'a');//显式地指定所有函数模板实参
	//teSt231<double>(2, 'a');//只显式指定第一个函数模板实参，而让演绎过程推导出其余的函数模板实参
	//teSt232(2, 'a');//不显式地指定任何函数模板实参，
	////teSt233(2, 'a');//错。（ps:要想这里可以这样调用，除下面方法还可以改变原模板函数，指定两个模板参数）
	//teSt233(2, 5);//对。如果不做任何措施，模板实参只能是同一种类型
	//teSt233(static_cast<char>(2), 'a');//对
	//teSt233<int>(2, 'a');//对
	//teSt24();
	//teSt25<int>();//模板的模板参数(ps:在vs2013上函数模板支持模板的模板参数)
	//Cat25<int> c;//第二个参数是身为模板的模板参数，该模板的前面尖括号里的类型必须要与默认实参的相匹配
	//teSt26();//stoi和itoa
	//teSt27('a',0);//对于任何一个参数，只有在之后的参数都提供了缺省实参的前提下，它才能具有缺省实参
	//teSt28();//一个类(无论是普通类还是类模板)可以包含本身是模板的成员函数或类
	//Cat28<int> c('a');//使用其他类型给c的元素赋值
	//Cat28<int>::Cat281<int, char> c2(2, 'a');//位于类内部的成员类模板，且在类内部定义
	//c.f(5);//成员函数模板
	//Cat28<int>::Cat282<float,char> c3(2,2.0,'a');//位于类内部的成员类模板，且在类外部定义
	//tsSt29('a');//模板通常具有外部链接。但是有例外情况
	//teSt30();//非类型模板参数的限制
	//teSt31();//类模板的普通友元和友元函数模板（ps:这里没有探究类模板的普通友元类和友元类模板的关系）
	//teSt32();//类模板的static成员（ps;这里存在一个严重的问题）
	teSt34();//模板的特例化
}