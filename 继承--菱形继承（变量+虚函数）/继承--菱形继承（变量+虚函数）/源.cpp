#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

class A
{
public:
	virtual void func1()
	{
		cout << "A::func1" << endl;
	}
	virtual void func2()
	{
		cout << "A::func2" << endl;
	}
public:
	int _a;
};
class B :virtual public A
{
public:
	virtual void func1()
	{
		cout << "B::func1" << endl;
	}
	virtual void func2()
	{
		cout << "B::func2" << endl;
	}
public:
	int _b;
};
class C :virtual public A
{
public:
	virtual void func1()
	{
		cout << "C::func1" << endl;
	}
	virtual void func2()
	{
		cout << "C::func2" << endl;
	}
public:
	int _c;
};
class D :public B, public C
{
public:
	//virtual void func1()   //不重写func1和func2,编译都通不过（①void A::func1()的不明确继承②虚拟函数 函数A::func1的重写不明确）
	//{
	//	cout << "D::func1" << endl;
	//}
	//virtual void func2()
	//{
	//	cout << "D::func2" << endl;
	//}
	virtual void func3()
	{
		cout << "D::func3" << endl;
	}
	void func4()
	{
		cout << "D::func4" << endl;
	}
public:
	int _d;
};

//typedef void(*v_fun)();
//void PrintVTable(int *vtable)
//{
//	printf("虚函数表：%p\n", vtable);
//	for (size_t i = 0; vtable[i] != 0; ++i)
//	{
//		printf("vfun[%d]:%p->", i, vtable[i]);
//		v_fun f = (v_fun)vtable[i];
//		f();
//	}
//}
int main()
{
	//B b;
	//A *pa = &b;
	//int *vtable1 = (int*)(*(int*)&b);
	//PrintVTable(vtable1);


	A a; B b; C c; D d;
	d._a = 1;
	d._b = 2;
	d._c = 3;
	d._d = 4;

	printf("%d\n", sizeof(a));//8
	printf("%d\n", sizeof(b));//16
	printf("%d\n", sizeof(c));//16
	printf("%d\n", sizeof(d));//32


	system("pause");
	return 0;
}