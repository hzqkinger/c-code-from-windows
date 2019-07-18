#pragma once

void test0()
{
	//int num1 = 4, sum1 = 7;
	//int num2 = 4, sum2 = 7;
	////sum1 = num1++, sum1++, ++num1;
	////sum2 = num2++, sum2++, num2++;
	//sum1 = ++num1, ++num1,++sum1;
	//sum2 = num2++, ++num2,++sum2;
	////sum1 = ++num1, sum1++, ++num1;
	////sum2 = ++num2, sum2++, num2++;
	//printf("%d %d\n", sum1,sum2);
	////printf("%d %d\n", num1, num2);

	int a = 1, b = 5, c = 9, sum = 0;
	//int sum1 = a, b, c;
	int sum2 = (a, b, c);
	printf("%d %d\n", /*sum1, */sum2);
}

class AA1
{
public:
	int a;
	void Get()
	{
		cout << "AA1" << endl;
	}
};
class BB1
{
public:
	typedef AA1 A1;//让AA的别名A成为BB的成员
};
void test1()
{
	BB1::A1 a;
	a.Get();

	BB1::A1().Get();
	//cout << sizeof(AA) << endl;
	//cout << sizeof(BB) << endl;
}

template<class T>
const T& Max2(const T& a, const T& b)//模板函数
{
	return a > b ? a : b;
}
template<class T1,class T2>
void func2(const T1& a, const T2& b)
{
	cout << "hhhhhhhhhhhh" << endl;
}
void test2()
{
	cout << static_cast<double>(5.066) << endl;
	//cout << Max(4.1, 8);//在这里不允许进行自动类型转换，所以每个T都必须正确的匹配
	                      //在这里，第一个T被推演成double，第二个T被推演成int，有一个T不匹配，所以出错
	cout << Max2(static_cast<int>(4.1), 8);//方法①：对实参进行强制类型转换，使他们相互匹配
	cout << Max2<double>(4.1, 8) << endl;//方法②：显式指定T的类型
	                                   //方法③：修改模板参数，让它有两个模板参数
	double f = 5.55;
	const int &i1 = 6.11;
	//int &i = static_cast<int>(f);//非常量引用的初始值必须为左值
	const int &i = static_cast<int>(f);//常量引用的初始化既可以是左值也可以是右值
	cout << i << endl;

	func2(4.1, 8);//①不显式指定函数任何模板实参
	func2<int, double>(4.1, 8);//②显式指定所有函数模板实参
	func2<int>(4.1, 8);//③只显式的指定第一个模板实参，而让演绎过程推演其余的模板实参
}

void test3()
{
	char str[10];
	//gets(str);//在终端输入时，只有输入<CRT>才算str的结束
	scanf("%s", str);//在终端输入时，输入空格和<CRT>都算str的结束
	cout << str << endl;
	for (size_t i = 0; i < 10; ++i)
		cout << str[i] << endl;

	//	int a; float b, c;
	//	scanf("%2d%3f%4f", &a, &b, &c);
	//	printf("%d %d %f\n", a, b, c);
	//	printf("%d", sizeof(b));
}

void print4(char *s)
{
	if (*s)
	{
		print4(++s);                 //在这个时候，形参和实参都向后移动了一位。
		//print4(s++);//死循环
		//printf("%c", *s);//_suiene
	}
	printf("%c", *s);//__suiene
}
void print41(char *s)
{
	if (*s)
	{
		++s;
		print41(s);
		printf("%c", *s);//_suiene
		//++s;//死循环
	}
}
void test4()
{
	char str[] = "Geneius";
	print4(str);
}

struct item5
{
	char c;
	item5 *_next;
};
item5* reverse5(item5 *x)
{
	item5 *prev = NULL, *cur = x;
	while (cur)
	{
		item5 *next = cur->_next;
		cur->_next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
void print5(item5 *x)
{
	item5 *cur = x;
	while (cur)
	{
		cout << cur->c;
		cur = cur->_next;
	}
}
void test5()
{
	item5 *x, d = { 'd', NULL }, c = { 'c', &d }, b = { 'b', &c }, a = { 'a', &b };
	x = reverse5(&a);
	print5(x);
}

class E6
{
public:
	//①②这两种设置默认值的方法，在C++11之前是不支持的（注意：慎用）
	int x1 = 1;//①这个是具有默认值的成员变量
	const int x2 = 2;//②const的一般常量可以在这里设置默认值，否则必须在构造函数初始化列表进行初始化。

	static int x3 /*= 3*/;//③静态变量不能在类内初始化；如果要初始化，必须在类外初始化。

	const static int x4 /*= 4*/;//④常静态变量可以在类内、类外初始化，但是只能在一处初始化。
public:
	E6()
		:x1(10), x2(20)//由于①②中后面的数是默认值，所以优先使用构造函数的初始化列表初始化。
	{
		x3 = 10;//静态变量可以在构造函数中赋值（注意：这里不是初始化）
	}
};
int E6::x3 = 30;//静态变量必须在类外初始化
const int E6::x4 = 40;

void test7()
{
	int i = 0;
	int j = 1;

	const int *p1;//底层指针：它可以指向其他空间，但是它不可以修改它指向空间的内容
	p1 = &i;
	int *p2;
	p2 = &i;
	//int * const p3;//顶层指针，它不能指向其他任何空间，但是它可以修改它指向空间的内容
	const int * const p4 = &i;
	p1 = &j;
	//*p1 = 20;

}

//va_start(arg,format),初始化参数指针arg，将函数参数format右边第一个参数地址赋值给arg  
//format必须是一个参数的指针，所以，此种类型函数至少要有一个普通的参数,   
//从而提供给va_start ,这样va_start才能找到可变参数在栈上的位置。   
//va_arg(arg,char),获得arg指向参数的值，同时使arg指向下一个参数,char用来指名当前参数型  
//va_end 在有些实现中可能会把arg改成无效值，这里，是把arg指针指向了 NULL,避免出现野指针   
void print8(const char *format, ...)
{
	va_list arg;
	va_start(arg, format);
	while (*format)
	{
		char ret = *format;
		if (ret == '%')
		{
			switch (*++format)
			{
			case 'c':
			{
						char ch = va_arg(arg, char);
						putchar(ch);
						break;
			}
			case 's':
			{
						char *pc = va_arg(arg, char *);
						while (*pc)
						{
							putchar(*pc);
							pc++;
						}
						break;
			}
			default:
				break;
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(arg);
}
void test8()
{
	int a;
	a = (4 + sizeof(int)-1)&~(sizeof(int)-1);
	printf("%d\n", a);
	for (size_t i = 1; i <= 101; ++i)
	{
		a = (i + sizeof(int)-1)&~(sizeof(int)-1);
		printf("%d ", a);
		if (i % 4 == 0 && i != 0)
			printf("\n");
	}
	const char* format = NULL;
	printf("%d\n%d\n", sizeof(format), sizeof(int));
	print8("%s %s %c%c%c%c%c!\n", "welcome", "to", 'C', 'h', 'i', 'n', 'a');
}

int Max9(int n, ...)
{
	//printf("%d\n", *((char*)&n));
	//for (size_t i = 1; i < 24; i++)
	//{
	//	//cout << *((char*)&n + i) << endl;
	//	printf("%d\n", *((char*)&n + i));
	//}
	va_list arg;
	va_list at = (va_list)&n + ((sizeof(n)+sizeof(int)-1)&~(sizeof(int)-1));
	int i = 0, tmp = 0;
	va_start(arg, n);
	int max = va_arg(arg, int);
	for (i = 1; i < n; ++i)
	{
		if (max < (tmp = va_arg(arg, int)))
			max = tmp;
	}
	va_end(arg);
	return max;
}
void test9()
{
	char a = 2, b = 5, c = 3;
	int max1 = Max9(2, b, c);
	int max2 = Max9(3, c, b, a);
	printf("%d %d\n", max1, max2);
}

class base10
{
	friend class pal10;//声明pal10为based的友元类
private:
	int b2 = 5;
protected:
	int b = 1;
	int b1 = 6;
public:
	int b3 = 6;
	int f0(base10 b1)
	{
		return b1.b;
	}
};
class derived10 :public base10//公有继承下，子类可以访问父类的所有非私有成员
{
	friend class pal210;//声明pal210为deprived10的友元类
public:
	int f1()
	{
		return b;
	}
	friend int f2(derived10& d)//该友元函数可以在类内定义（友元函数是否可以在类内定义，取决于它的参数列表是否含有该类对象）
	{
		return d.b;//友元函数必须通过该类对象，才能引用该类的所有成员（注意是必须）
	}
	friend void f22()//上面的话有点问题，该友元函数可以在类内定义，但是要想在外面用，必须在类外再次声明
	{
		cout << "789" << endl;
	}
	void func3()
	{
		cout << "base10:b = " << b << endl;
	}
	int d = 2;
	using base10::b;//将base10的保护数据成员b声明为deprived10的共有成员
	//using base10::b2;//私有的不能这样干
protected:
	int d2 = 3;
private:
	int d3 = 4;
};
class pal210//derived的友元类只能通过对象来访问derived的所有成员/base的公有成员
{
	int f7(derived10 &d)
	{
		cout << d.b1 << endl;//子类的保护成员
		cout << d.b << endl;//子类的公有成员
		cout << d.d3 << endl;//子类的私有成员
		return d.d2;
	}
	int f8(base10 &b)
	{
		//cout << b.b1 << endl;
		//cout << b.b << endl;
		cout << b.b3 << endl;//父类的公有成员
		b.f0(b);
	}
};
class pal10//base的友元类只能通过对象来访问base的所有成员/derived的公有成员
{
public:
	int f3(base10 &b)
	{
		return b.b;
	}
	int f5(base10 &b)
	{
		cout << b.b << endl;
		cout << b.b2 << endl;
		b.f0(b);
	}
	int f4(derived10 &d)
	{
		return d.d;
	}
	int f6(derived10 &d)
	{
		//cout << d.d2 << endl;
	}
};
void f22();
void test10()
{
	//基类的友元函数不能访问派生类的任何成员；派生类的友元函数可以通过派生类对象名加上.运算符访问基类的非私有成员
	//基类的友元类可以访问基类的所有成员和派生类的非私有成员；派生类的友元类可以访问基类的非私有成员和派生类的所有成员
	//注意点：友元函数和友元类都是怎样访问那个类的成员。
	base10 b;
	derived10 d;
	d.b = 10;
	d.func3();
	d.b3 = 9;
	cout << b.f0(base10()) << endl;;
	cout << d.f1() << endl;
	cout << f2(d) << endl;
	pal10 p;
	cout << p.f3(b) << endl;
	cout << p.f4(d) << endl;
	f22();
}

void test11()//常量折叠，编译器的优化。
{
	const int i = 42;
	//int *p = &i;
	int*p = (int*)&i;
	*p = 39;
	printf("%d  %d", *p, i);
	/*cout << *p << " " <<i <<endl;*/
}

class A12
{
public:
	A12()
	{
		cout << "A12()" << endl;
	}
	A12(const A12& a)
	{
		cout << "A12(const A12& a)" << endl;
	}
	A12&operator=(const A12& a)
	{
		cout << "A12&operator=(const A12& a)" << endl;
		return *this;

	}
	~A12()
	{
		cout << "~A12()" << endl;
	}
};
class B12:public A12
{
public:
	B12()
	{
		cout << "B12()" << endl;
	}
	B12(const B12& a)
		:A12(a)//这里要显式的调用A1的拷贝构造，否则调用的就是A1的默认构造函数
	{
		cout << "B12(const B12& a)" << endl;
	}
	B12&operator=(const B12& b)//如果这里不显式的调用A1的拷贝赋值函数，这里根本不会调用A1的拷贝赋值函数
	{
		A12::operator=(b);
		cout << "B12&operator=(const B12& a)" << endl;
		return *this;
	}
	~B12()//不能显式调用，而是由编译器自动调用
	{
		cout << "~B12()" << endl;
	}
};
void test12()
{
	B12 b1;
	B12 b2 = b1;
	B12 b3;
	b3 = b1;
}

template<class T = int>
class A13             //在模板类中 A13是类名；A13<T>是类型。
{
public:
	A13(T e = 0)
		:_a11(e)
	{}
	A13 &operator=(const A13& a1)
	{
		_a11 = a1._a11;
		return *this;
	}
	A13& f1(const A13 & a1)//参数列表中居然可以直接用类名
	{
		_a11 += a1._a11;
		return *this;
	}
	void f2(A13 & a1);
private:
	T _a11;
};
template<class T2>//外面定义成员函数，这里的T2可以跟上面的名字不一样，但是实例化之后T和T2类型一样
void A13<T2>::f2(A13 &a1)//参数列表中居然可以直接用类名
{
	cout << a1._a11 << endl;
}
void test13()
{
	A13<> aa(5);
	aa.f2(aa);
	aa.f1(aa);
	A13<int> bb[5];//将A<int>看做内置类型来理解就好了，bb数组里面含有5个A13<int>类型的数据元素
	bb[0] = aa;
	A13<int> cc;
	cc.f1(aa);
	A13<int>&dd = cc;
}

void test141(char **p)
{
	*p += 2;
}
void test14()
{
	char *a[] = { "123789", "abc", "456" };
	char**p;
	p = a;
	test141(p);
	printf("%s\n%s\n", a[0], *p);
}

class A15
{
public:
	virtual void f1()//虚函数调用非虚函数
	{cout << "A::F1()" << endl;
	    f2();
	}
	void f2()//非虚函数调用虚函数（注意特殊情况：构造函数里面调用虚函数）
	{cout << "A::F2()" << endl;
		//f1();
	}
};
class B15 :public A15
{
public:
	//virtual void f1()//虚函数调用非虚函数
	//{cout << "B::F1()" << endl;
	//	f2();
	//}
	void f2()//非虚函数调用虚函数
	{cout << "B::F2()" << endl;
		//f1();
	}
};
void test15()
{
	A15 *pa = new B15;
	pa->f1();
}

class AA16
{
	char * _p;
	int _a;
	AA16(char *p = NULL,int a = 0)
	:_p(new char[strlen(p)]),_a(a)
	{}
public:
	void foo()
	{
		delete this;
	}
	void f1()
	{
		cout << "hah" << endl;
	}
	static AA16 *Getobj(char *p,int a)
	{
		return new AA16(p,a);
	}
	friend AA16 * tes(char *p,int a);
	friend AA16 *tess(AA16 *a)//友元函数是否可以在类内定义，取决于它的参数列表是否含有该类对象
	{
		cout << a->_a << endl;
		cout << "hhhhh" << endl;
	}
};
AA16 * tes(char *p, int a)
{
	return new AA16(p,a);
}
void test16()
{
	char *str = "abc";
	AA16 *ptr = AA16::Getobj(str,0);
	AA16 *ptr2 = tes(str,1);
	ptr->foo();
	ptr->f1();
}

class A17
{
	~A17()//将析构函数私有化（如何构造一个只能在堆上创建对象的类）
	{}
	public:
		A17() = default;//默认构造函数
		A17(const A17& a)//拷贝构造函数
		{cout << "keyi" << endl;
		}
		virtual void f1()
		{
			cout << "keyi" << endl;
		}
		void f2()
		{
			cout << " buxing" << endl;
		}
		int a;
};
class B17 : public A17
{
	void f1()override//当用override标记了某函数，如果该函数没有覆盖已存在的虚函数，编译器报错
	{}
};
void test17()
{
	//A17 a;//将析构函数私有化，该类不能在栈上创建对象，只能在堆上创建对象。
	A17 *p = new A17;
	A17 a(A17());//a这居然不是一个A类的对象，这里只是声明了一个函数。（这个有点模糊）

}

class A18
{
	A18(int a = 1)//将构造函数私有化（如何构造一个不会被继承的类）
	:_a(a)
	{}
	int _a;
public:
	A18* Getobj1(int a)//①
	{
		return new A18(a);
	}
	A18 Getobj(int a)//①
	{
		return A18(a);
	}
	static A18 Getobj2(int a)//②静态成员函数
	{
		return A18(a);
	}
	friend A18 func(int a);//③友元
};
A18 func(int a)
{
	return A18(a);
}
void test18()
{
	A18 a1 = A18::Getobj2(5);//②
	A18 a2 = func(6);//③
	//A18 *ptr1 = A18::Getobj1(9);//非静态成员引用必须与特定的对象相对
}

#define IBM_C19//这个居然都能编译过去

char buffer20[6]/* = { 0 }*/;//首先buffer20是全局变量，即使不显式为每个元素赋初始值0，它里面的元素也都是0.
char* test201()
{
	char *s = "hello world";
	for (size_t i = 0; i < sizeof(buffer20)-1; ++i)
		buffer20[i] = *(s + i);
	return buffer20;
}
void test20()
{
	printf("%s\n", test201());
}

void test_draft2()
{
	//test0();//逗号表达式和逗号分隔符。
	//test1();//typedef在类中给自定义类型取别名
	//test2();//函数模板
	//test3();//scanf与gets的比较
	//test4();//递归
	//test5();//单链表的逆置
	//E6 e;//普通数据成员，const数据成员，static数据成员，const static数据成员
	//test7();//顶层指针和底层指针
	//test8();//可变参列表
	//test9();//可变参
	test10();//继承和友元类
	//test11();//常量折叠
	//test12();//继承和四个默认生成函数
	//test13();//模板类中定义的函数的参数的类型居然可以直接用类名代替
	//test14();//二级指针与一级指针之间不是单纯的赋值，而是紧密关联的
	//test15();//继承和多态
	//test16();//删除this指针（还没有搞懂）
	//test17();//析构函数私有化（有些地方模糊）
	//test18();//构造函数私有化
	//list<int> l;
	//list<int>::reverse_iterator rit = l.rbegin();
	//test20();//全局变量的初始值
}