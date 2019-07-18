#pragma once


//题目描述
//设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
//如 : n = 3时，3个整数13, 312, 343, 连成的最大整数为34331213。
//如 : n = 4时, 4个整数7, 13, 4, 246连接成的最大整数为7424613。
//输入描述 :
//有多组测试样例，每组测试样例包含两行，第一行为一个整数N（N <= 100），
//第二行包含N个数(每个数不超过1000，空格分开)。
//输出描述 :
//每组数据输出一个表示最大的整数。
//示例1
//输入
//4
//7 13 4 246
//输出
//7424613
#include<string>
void test1()
{
	string s("66");
	string s2("668");
	string s3("665");
	cout << (s2 > s) << endl;//1
	cout << (s3 > s) << endl;//1

	cout << ("776" > "77") << endl;//0
	cout << ("778" > "77") << endl;//1
	//cout << (s2 + s > s + s2) << endl;//1 //其实这就是个字符串的冒泡排序，如果字符串A+B>B+A那么认为A>B
	//cout << (s3 + s > s + s3) << endl;//0


	//cout << strcmp("776", "77") << endl;//1
	//cout << strcmp("778", "77") << endl;//1

	//cout << ("ba" > "b") << endl;//0
	//cout << ("bc" > "b") << endl;//1

}

//互相不怎么相关的两个calss
class Foo{
public:
	int val;//一般数据成员(ps:如果该类只含有一般数据成员，实际上编译器并没有合成default constructor)
	char *p = "123";                          // 但是c++标准说合成了，只不过是没有什么用处的默认构造函数
	double d;
	string s;
	//Foo(){}
	//Foo() = default;
	//Foo(const Foo& f) = default;
	//Foo(const Foo& f):val(f.val)/*,p(new char[strlen(f.p)+1])*/{}
	//string s;//对象数据长成员（只有含有对象数据成员的类的default constructor才是有用的）

	//注意：一般数据成员的初始化是程序员的责任；而对象数据成员的初始化时编译器的责任
};
class Bar{
public:
	Foo f;//因为f是对象数据成员，所以Bar的default constructor是有用的；但是并不表示Foo的默认构造函数是有用的
	//string s;
	char *p;
};
//一般继承体系的两个class
class base2{
public:
	int _a;
	//virtual void f1()//带有一个virtual function的class的default constructor是有用的
	//{      //(virtual function机制问题)    //而且default copy constructor也是有用的
	//	cout << "base2::f1()" << endl;
	//}
	base2() = default;
	base2(const base2& b){}
};
class derived2 :public base2{
public://①如果没有任何构造函数的class派生自带有default constructor的base class，那么这个
	   // derived class的default constructor会被视为有用的
	   //②如果在derived class中提供了多个构造函数，那么它的所有构造函数都会被扩张，但是不会合成一个
	   // 新的default constructor
	//derived2(int b){}
	int _b;
};
//菱形继承体系
class X{ public:int i = 1; };
class A :public virtual X{ public:int j = 2; };
class B :public virtual X{ public:int m = 3; };
class C :public A, public B{ public:int k = 4; };

void test2()//测试构造函数的语义学
{
	//Bar b;
	//Foo bar;
	//if (bar.val/* || bar.pnext*/){
	//	cout << "hah" << endl;
	//}

	//base2 b;
	//if (b._a){ cout << "hhhhhhhh" << endl; }
	////derived2 d(5);

	//X x;
	//if (x.i){ cout << "hhhhhhhhh" << endl; }
	A a;
	B b;
	C c;
	cout << "hah" << endl;
}
void test21()//测试拷贝构造函数的语义学
{
	Foo f;
	if (f.val){ cout << "hhh" << endl; }

	Bar b1;
	Bar b2 = b1;//只有当Foo的拷贝构造函数像上面样显式声明且定义或者它是被编译器合成一个有用的copy constructor时

	//derived2 d;
	//derived2 d2 = d;
	cout << "hah" << endl;
}

//class X2{ public:int i; virtual ~X2(){} };
//class X3{ public:int i = 3; };
//void test3()
//{ //编译器合成的默认构造函数通常只是对编译器有效；即使合成了，基本上也不会满足程序的要求，
//	//所以写程序时建议自己写个默认构造函数
//
//	//虽然两个class都合成了一个没有用的默认构造函数，但是类X3里面的i有默认值
//	X2 x2;
//	//if (x2.i){ cout << "haha"; }//出错
//	cout << sizeof(x2) << endl;//除非必要，否则不要随随便便将析构函数写成虚函数
//	X3 x3;
//	if (x3.i){ cout << "hehe"; }//对
//}

class X4{
public:
	X4() :_i(0){ cout << "构造函数" << endl; }//自己的默认构造函数
	X4(const X4& xx) :_i(xx._i){ cout << "拷贝构造函数" << endl; }//拷贝构造函数
private:
	int _i;
};
X4 foo4(X4 x0)
{
	X4 x1(x0);//①显式初始化
	X4 x2 = x0;
	X4 x3 = X4(x0);
	return x1;//③返回值的初始化
}
//1.先总结C++对传参合传返回值时构造的优化处理。
//2.再完成下面的题目。
//Test1中调用了___次AA的拷贝构造函数, ___次AA的赋值运算符函数的重载。
//Test2中调用了___次AA的拷贝构造函数, ___次AA的赋值运算符函数的重载。
//Test3中调用了___次AA的拷贝构造函数, ___次AA的赋值运算符函数的重载。
class AA{
public:
	AA() :_i(0){ cout << "构造函数" << endl; }
	AA(const AA& a) :_i(a._i){ cout << "拷贝构造函数" << endl; }
	AA &operator=(const AA& a){ cout << "赋值运算符重载函数" << endl; return AA(); }
private:
	int _i;
};
AA f(AA a)//调用了两次拷贝构造函数
{
	return a;
}
void test41()
{
	AA a1;//调用了一次默认构造函数
	a1 = f(a1);//赋值运算符重载函数和拷贝构造函数
}
void test42()
{
	AA a1;//调用了一次默认构造函数
	AA a2 = f(a1);//调用了两次拷贝构造函数（原本是需要调用三次的，但是编译器优化掉了一次）
}
void test43()
{
	AA a1;//调用了一次默认构造函数
	AA a2 = f(f(a1));
}
void test4()
{
	//X4 xx;
	//cout << endl;
	//foo4(xx);//②参数的初始化
	//cout << endl;
	//X4 xx2 = foo4(xx);//当返回对象是用来初始化其他对象的时候，编译器会发生优化(在这即少调用一个拷贝构造函数)
	AA a;
	cout << endl;
	f(a);
	cout << endl;
	test41();
	cout << endl;
	test42();
	cout << endl;
	test43();
	cout << endl;
}

class X5{
	int _i; int _j; double d; string s;
public://初始化的顺序是以class的成员声明顺序一致的，而不是以初始化列表的排列顺序为准的
	X5(int val) :_j(val), _i(_j){}//ps:错误代码
};
class X51{
	int _i; int _j; double d; string s;
public://初始化列表的代码会安插在任何explicit user code之前
	X51(int val) :_j(val){ _i = _j; }//ps:正确代码
};
void test5()
{
	X5 x1(5);
	X51 x2(6);
	cout << "hah" << endl;
}

class X6{};
class Y6 :public /*virtual */X6{ static int _y; };
int Y6::_y = 0;
class Z6 :public virtual X6{};
class A6 :public Y6, public Z6{};
void test6()
{
	cout<<sizeof(X6);//1 
	cout<<sizeof(Y6);//4
	cout<<sizeof(Z6);//4
	cout<<sizeof(A6);//8
}

typedef int length7;
class X7{
public:
	void f1(length7 i)
	{
		_i = i;
		cout << _i << endl;
	}
	typedef double length7;

	void f2(length7 i)
	{
		_i = i;
		cout << _i << endl;
	}
	length7 _i;
	static int xxxx;
};
int X7::xxxx;//静态成员变量（注意，必须在类外声明，否则没有人能找到它，然后该类也不承认这个变量的存在）
void f3(length7 i)
{
	cout << i << endl;
}
void test7()
{
	X7 x;
	//x.f1(5.0001);
	//x.f2(6.0001);
	//f3(7.0001);
	//cout << "hahha";
	static int xxx;//静态局部变量
	cout << xxx << " ";
}
int xxl;//全局变量
int xxll = 11;//全局变量
static int xxl5/* = 5*/;//静态全局变量

class Point3d{
public:
	//virtual ~Point3d(){}
	static int _i;
	float x, y, z;
};
int _i = 6;
void test8()
{
	printf("&Point3d::x = %p\n", &Point3d::x);
	printf("&Point3d::y = %p\n", &Point3d::y);
	printf("&Point3d::z = %p\n", &Point3d::z);
	cout << ("&Point3d::x = ") << (&Point3d::x) << endl;//讲道理，这似乎有点问题
	cout << ("&Point3d::y = ") << (&Point3d::y) << endl;
	cout << ("&Point3d::z = ") << (&Point3d::z) << endl;
	float Point3d::*p1 = 0;//没有指向任何data member的指针
	float Point3d::*p2 = &Point3d::x;//指向第一个data member的指针
	float Point3d::*p3 = &Point3d::y;
	printf("指空 = %p\n&Point3d::x = %p\n&Point3d::y = %p\n", p1, p2, p3);
	cout << ("&Point3d::x = ") << p1 << endl;//讲道理，还有这
	cout << ("&Point3d::y = ") << p2 << endl;
	cout << ("&Point3d::z = ") <<p3 << endl;

	//printf("%p\n", &Point3d::_i);//将道理这里不应该出错的
	printf("%p\n", &_i);//额，居然可以直接得到静态成员的地址

	Point3d x;

	cout << "hah";
}
class x90{
	int val;
	char bit1, bit2, bit3;
};
class x91{
	int val;
	char bit1;
};
class x92 :public x91{
	char bit2;
};
class x93 :public x92{
	char bit3;
};
void test9()
{
	cout << sizeof(x90) << endl;
	cout << sizeof(x91) << endl;
	cout << sizeof(x92) << endl;
	cout << sizeof(x93) << endl;

}

class x10{//没有虚函数
	int _i = 1;
};
class x101{//有虚函数
	int _i = 2;
public:
	virtual void f(){}
};
class x103{//有虚函数
	int _i = 5;
//public:
//	virtual void f(){}
};
class x102 :public x10, public x101,public x103{//按照一般规则，先继承x10,再继承x101
	int _i = 3;//但是在这种情况下，大多数编译器会调整继承顺序
};
void test10()
{
	x102 x;
	//cout << sizeof(x101) << endl;
	cout << "hah";
}

class x11{
public:
	/*inline virtual*/ void f1()
	{
		//int n = 100000011;
		//while (n--);
		f3();//非静态成员函数可以引用静态成员函数
	}
	virtual void f2()
	{
		int n = 10000000;
		while (n--)
			x11::f1();//但是在类内，似乎有点不符
	}
	static void f3()
	{
		//f1();//错//静态成员函数不可以引用非静态成员函数
		//x11::f1();//错

		//①c++中所有的nonstatic member function都必须经由该class的object来调用。---c++对象模型p149原话
		//②静态成员内调用非静态成员之所以会出错，其实际原因是参数不匹配(少传了一个this指针)
		//③this指针把"在member function中存取的nonstatic class members"绑定于"object内对应的members"之上
		//  如果没有任何一个members被直接存取，事实上不需要this指针，所以有时候this指针为空且去调用成员函数
		//  不会出错
		x11::f4();
	}
private:
	static void f4(){}
};
#include<time.h>
void test11()
{
	//((x11*)0)->f1();//不通过对象去调用成员函数你，(注意，只要不访问该非法地址，就能成功调用)
	x11 x;
	x11 *px = &x;
	//clock_t t;
	//t = clock();
	//x.f2();
	//t = clock() - t;
	//cout << t << endl;
	x.f3();//①可以通过对象名去调用静态成员函数（注意，虽然可以这样调用，但并不表示该函数属于这个对象）
	px->f3();
	x11::f3();//②可以通过类型直接调用静态成员函数

	cout << &x11::f3 << endl;//对，获取静态成员函数的地址
	//cout << &x.f1 << endl;//错，获取nonstatic member function的地址
	//cout << &x.f2 << endl;//错，获取virtual function的地址

	//x11::f2();//①非静态成员的引用必须与特定的对象相对
	//x::f2();//②作用域::前面的名称一定是类名或者命名空间
	//x11::f4();//静态成员函数也受权限制约(私有静态成员函数只能通过类的成员函数或者友元函数访问)
}

class x12{
public:
	virtual void f1(){ cout << "f1" << endl; }
	virtual void f2(){ cout << "f2" << endl; }
	virtual void f3(){ cout << "f3" << endl; }
	virtual void f4(){ int i = 9; while (i--); cout << "f4" << endl; }

};
//注意，动态绑定只有通过指针或引用调用虚函数时才会发生；如果一个普通对象调用虚函数，
//         那么编译器在编译时就会将调用的版本确定下来
void test12()
{
	typedef void(*v_fun)();//给函数指针类型取别名
	x12 x;
	int *vtable = (int*)(*(int*)&x);//地址不重要，类型才重要
	printf("虚函数表：%p\n", vtable);
	for (size_t i = 0; vtable[i] != 0; ++i)
	{
		printf("vfun[%d]:%p->", i, vtable[i]);
		v_fun f = (v_fun)vtable[i];//f是函数指针变量，它里面存储着函数的地址值(它可以进行的操作:& () *)
		//f();//函数调用                //感觉所有的指针变量都可以进行取地址&和解引用*的基本操作
		cout << *f << endl;
	}
	cout << sizeof(v_fun) << endl;//4
}

class base131{
public:
	int _i = 1;
	virtual void f1(){ cout << "f1()" << endl; }
	//virtual ~base131(){ cout << "~base131()" << endl; }
};
class base132{
public:
	int _i = 2;
	virtual void f2(){ cout << "f2()" << endl; }
	//virtual ~base132(){ cout << "~base13()" << endl; }
};
class derived13 :public base131, public base132{
public:
	int _i = 3;//每一个class只有一个具名的virtual table(子类将各父类的virtual table连在一起，注意不是简单的连在一起的)
	virtual void f1(){ cout << "derived::f1()" << endl; }
	virtual void f2(){ cout << "derived::f2()" << endl; }

	//virtual ~derived13(){ cout << "~derived13()" << endl; }
};
void test13()
{
	derived13 d, *p0 = &d;
	//cout << sizeof(d) << endl;
	base131 *p1 = &d;
	base132 *p2 = &d;
	//printf("%p  %p\n", p1, p2);
	//p1->f1();
	//p2->f2();//第二个base的指针调用derived的虚函数（编译器需要调整指针）
	//p0->f2();//derived的指针调用第二个base的虚函数（编译器需要调整指针）

	typedef void(*v_fun)();//给函数指针类型取别名
	int *vtable = (int*)(*(int*)p0);//地址不重要，类型才重要
	printf("虚函数表：%p\n", vtable);
	for (size_t i = 0; vtable[i] != 0; ++i)
	{
		if (i == 1)continue;
		printf("vfun[%d]:%p->", i, vtable[i]);
		v_fun f = (v_fun)vtable[i];//f是函数指针变量，它里面存储着函数的地址值(它可以进行的操作:& () *)
		f();//函数调用                //感觉所有的指针变量都可以进行取地址&和解引用*的基本操作
		//cout << *f << endl;
	}
	cout << "hah";
}

class Abstract_base{//纯虚函数不能拥有具体实例，即不能定义对象
public:
	virtual ~Abstract_base() {}/*= 0;*/ //在继承体系中最好把析构函数定义为虚函数；但是不能是纯虚函数
	virtual void f1()/*const */= 0;   //最好不要设计const函数
	/*virtual */const char* mumber()const{ return _mumber; }//原本就不需要成为虚函数，最好不要virtual，否则加重编译器的负担
	void f2(){ cout << "it is ok!"; }
protected:
	Abstract_base(char *pc = NULL) :_mumber(pc){}//新增一个带唯一参数的constructor
	char *_mumber;
};
void test14()
{
	//Abstract_base::mumber();//错，非静态成员必须与特定的对象相对
	Abstract_base *p = NULL;
	p->f2();//只要不涉及到具体对象，该调用就会成功
}

class AA15{
	int i;
};
typedef struct{
	float x, y, z;
	AA15 a;
}point;
point global;                 //global内存配置
void test15()
{
	point local;                  //local 内存配置
	point *heap = new point;     //heap内存配置
	*heap = global;
	cout << "HH";
	delete heap;
}

class x16{
public:
	x16() { f1(); cout << "x16()" << endl; }
	virtual void f1(){ cout << "it is ok,but it could be a bug!" << endl; }
};
class x161 :public virtual x16{
public:
	x161() { cout << "x161()" << endl; }
};
class x162:public x161{
public:
	x162() { cout << "x162()" << endl; }
};
class x163 :virtual public x16{
public:
	x163() { cout << "x163()" << endl; }
};
class x164 :public x161, public x163{
public:
	x164(){ cout << "x164()" << endl; }
};
void test16()
{
	//x161 x2;//单一继承下
	//cout << endl;
	//x162 x3;
	//x164 x4;//虚拟继承下
	x16 x;//可以在构造函数中调用该class的虚拟函数（注意，构造函数一定不能为虚拟函数）
}

class x168{
public:
	x168(){ cout << "x168()" << endl; }
	x168(const x168& x){ cout << "x168(const x168& x)" << endl; }
	~x168(){ cout << "~x168()" << endl; }
};
class x169{
public:
	x169(int i):_i2(i){ cout << "x169()" << endl; }
	x169(const x169& x):_i2(x._i2){ cout << "x169(const x169& x)" << endl; }
	int _i2;
	~x169(){ cout << "~x169()" << endl; }
};
class x170{
public:
	x170(){ cout << "x170()" << endl; }
	x170(const x170& x):_i3(x._i3){ cout << "x170(const x170& x)" << endl; }
	int _i3;
	~x170(){ cout << "~x170()" << endl; }
};
class x171{
public:
	x171(){ cout << "x171()" << endl; }
	x171(const x171& x):_i4(x._i4){ cout << "x171(const x171& x)" << endl; }
	int _i4;
	~x171(){ cout << "~x171()" << endl; }
};
class x172:public x170{
public:
	x172(){ cout << "x172()" << endl; }
	x172(const x172& x):_i5(x._i5),x170(x){ cout << "x172(const x172& x)" << endl; }
	int _i5;
	~x172(){ cout << "~x172()" << endl; }
};
class x17:public x171,virtual public x172{
public:
	x17(int i6)
		:x2(i6),x171(), x172()
	{ 
		//①优先插入virtual base class constructors
		//②次优先插入base class constructors
		//③然后插入为virtual table pointer初始化的代码
		//④再然后按照数据成员声明顺序插入代码，（碰到对象成员，那么调用它的对应构造函数即可）
		cout << "x17()" << endl;//⑤执行该构造函数的函数体
		f1();
		//⑥最后初始化this指针(即在函数的最后隐藏一句这样的代码：return this)
	}
	//①由上发现，虽然构造函数不能是虚函数，但是可以在构造函数里面调用虚函数（注意，在构造函数里面调用虚函数
	//是个不好的操作，因为该类的数据成员可能在函数体重新赋值，而虚函数在赋值语句之前且该虚函数会用到数据成员）
	//②假如要在构造函数里面调用虚函数，讲道理我给数据成员赋值成功后再调用虚函数是没有差错的
	virtual void f1()
	{
		cout << x2._i2 << endl;
	}
	x17(const x17& x) : x2(x.x2), x171(x), x172(x)
	{ 
		//①优先插入virtual base class constructors(注意，如果初始化列表调用拷贝构造函数，那么这里就插入virtual base class copy constructors)
		//②次优先插入base class constructors(注意，如果初始化列表调用拷贝构造函数，那么这里就插入base class copy constructors)
		//③然后插入为virtual table pointer初始化的代码
		cout << "x17(const x17& x)" << endl; //④执行该拷贝构造函数的函数体

		//⑤最后返回初始化的this指针(即在函数的最后隐藏一句这样的代码：return this)
	}
	~x17(){cout << "~x17()" << endl;}//假如需要析构函数
private:
	x168 x1;
	x169 x2;
};
void test17()
{
	x17 x(5);
	cout << endl << endl;
	//x17 x1 = x;
}

class x181{
public:
	virtual void f1(){	cout << "x181   " << sizeof(x181) << endl;  f2();}
	/*virtual*/ void f2(){ cout << "x181   " << sizeof(x181) << endl; f3(); }
	virtual void f3(){ cout << "x181   " << sizeof(x181) << endl; }
	int _i1;
};
class x18 :public x181{
public:
	virtual void f1(){	cout << "x18   " << sizeof(x18) << endl;	f2();}
	/*virtual*/ void f2(){ cout << "x18   " << sizeof(x18) << endl; f3(); }
	virtual void f3(){ cout << "x18   " << sizeof(x18) << endl; }
	int _i;
};
void test18(){
	//x181 x;
	//x18 x;//对象调用虚函数，静态决议
	x181 *p = new x18;
	p->f1(); cout << endl;    p->f2();
}


void test_draft6()
{
	//test1();
	//test2();//default constructor什么时候是nontrivial (下面列举了类默认构造函数是有用的所有情况)
	//①如果一个类没有任何constructor,但它内含一个成员对象，而该成员对象有default constructor
	//②如果一个没有任何consstructor的类派生自一个带有default constructor的base class
	//③带有一个virtual function的类
	//④带有一个virtual base class的类
	//⑤该类的一个数据成员含有默认初始值（c++11及其以后）
	//test21();//default copy constructor什么时候是nontrivial(上面面列举了类默认拷贝构造函数有用的所有情况)
	//test3();
	//test4();//在调用拷贝构造函数时，编译器是如何优化的
	//test5();//初始化列表才是真正在进行初始化
	//test6();//空class的大小
	//test7();//argument list中的名称决议规则
	////静态成员变量，静态全局变量，静态局部变量，全局变量，假如它们没有初始化，那么默认初始化为零
	//cout << xxl << " " << xxll << " " << xxl5 << endl;
	//test8();//指向data members的指针（还有很多迷惑的地方）
	//test9();
	//test10(); //大多数编译器会调整继承顺序
	//test11();//静态成员函数
	//test12();//打印虚函数表
	//test13();//多重继承下，derived对象里面数据成员的分布
	//test14();//如何规范的设计一个纯虚函数
	//test15();//c++的所有全局对象都被以"初始化过的数据"来对待
	//test16();//作为底层的类，它自己有责任将父类初始化（编译器有自己的一套机制）
	//test17();//构造函数中插入的隐藏代码
	test18();//虚函数里面调用非虚函数？？？（在构造函数里面调用虚函数是静态决议的吗？？）
}