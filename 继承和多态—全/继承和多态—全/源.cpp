#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
/*单一继承（虚函数覆盖+无覆盖）*/
//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A::func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "A::func2()" << endl;
//	}
//	virtual void af()
//	{
//		cout << "af()" << endl;
//	}
//
//};
//class B:public A
//{
//public:
//	virtual void func1()
//	{
//		cout << "B::func1()" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "B::func3()" << endl;
//	}
//	virtual void bf()
//	{
//		cout << "bf()" << endl;
//	}
//};
//class C :public B
//{
//public:
//	virtual void func1()
//	{
//		cout << "C::func1()" << endl;
//	}
//	virtual void func4()
//	{
//		cout << "C::func4()" << endl;
//	}
//	virtual void cf()
//	{
//		cout << "cf()" << endl;
//	}
//};
//
//
//typedef void(WINAPI*vt_fun)();
//void PrintVTable(int *vtable)
//{
//	printf("虚函数表：%p\n", vtable);
//	cout << "--------------------------------------" << endl;
//	for (size_t i = 0; vtable[i] != 0; ++i)
//	{
//		printf("vfun[%d]:%p->", i, vtable[i]);
//		vt_fun fun = (vt_fun)vtable[i];
//		fun();
//	}
//	cout << "--------------------------------------" << endl;
//	cout << endl;
//
//}
//int main()
//{
//	A a; B b; C c;
//	int *vtable1 = (int*)(*(int*)&a);
//	PrintVTable(vtable1);
//	int *vtable2 = (int*)(*(int*)&b);
//	PrintVTable(vtable2);
//	int *vtable3 = (int*)(*(int*)&c);
//	PrintVTable(vtable3);
//
//	system("pause");
//	return 0;
//}

/*多继承（虚函数覆盖+无覆盖）*/
//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A::func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "A::func2()" << endl;
//	}
//	virtual void af()
//	{
//		cout << "af()" << endl;
//	}
//
//};
//class B
//{
//public:
//	virtual void func1()
//	{
//		cout << "B::func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "B::func2()" << endl;
//	}
//	virtual void bf()
//	{
//		cout << "bf()" << endl;
//	}
//};
//class C :public A,public B
//{
//public:
//	virtual void func1()
//	{
//		cout << "C::func1()" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "C::func3()" << endl;
//	}
//	virtual void cf()
//	{
//		cout << "cf()" << endl;
//	}
//};
//
//
//typedef void(WINAPI*vt_fun)();
//void PrintVTable(int *vtable)
//{
//	printf("虚函数表：%p\n", vtable);
//	cout << "--------------------------------------" << endl;
//	for (size_t i = 0; vtable[i] != 0; ++i)
//	{
//		printf("vfun[%d]:%p->", i, vtable[i]);
//		vt_fun fun = (vt_fun)vtable[i];
//		fun();
//	}
//	cout << "--------------------------------------" << endl;
//	cout << endl;
//
//}
//int main()
//{
//	A a; B b; C c;
//	int *vtable1 = (int*)(*(int*)&a);
//	PrintVTable(vtable1);
//	int *vtable2 = (int*)(*(int*)&b);
//	PrintVTable(vtable2);
//
//	int *vtable3 = (int*)(*(int*)&c);
//	PrintVTable(vtable3);
//	int *vtable4 = (int*)(*(int*)((char*)&c+sizeof(a)));
//	PrintVTable(vtable4);
//
//	system("pause");
//	return 0;
//}

/*虚继承（仅仅含有数据成员）*/
//class A
//{
//public:
//	int _a1;
//	int _a2;
//};
//class B :virtual public A
//{
//public:
//	int _b;
//};
//class C :virtual public A
//{
//public:
//	int _c;
//};
//class D :public B, public C
//{
//public:
//	int _d;
//};
//int main()
//{
//	A a; B b; C c;
//	D d;
//	a._a1 = 1; a._a1 = 1;
//
//	b._a1 = 10;	b._a1 = 10;
//	b._b = 2;
//	c._a1 = 11;	c._a1 = 11;
//	c._c = 3;
//
//	d._a1 = 12; d._a1 = 12;
//	d._b = 13;
//	d._c = 14;
//	d._d = 15;
//
//	printf("%d\n", sizeof(a));//8
//	printf("%d\n", sizeof(b));//16
//	printf("%d\n", sizeof(c));//16
//	printf("%d\n", sizeof(d));//28
//
//	system("pause");
//	return 0;
//}

/*钻石多重虚拟继承（虚函数覆盖+无覆盖）*/
class A
{
public:
	virtual void func1()
	{
		cout << "A::func1()" << endl;
	}
	virtual void func2()
	{
		cout << "A::func2()" << endl;
	}
	virtual void af()
	{
		cout << "af()" << endl;
	}

};
class B :virtual public A
{
public:
	virtual void func1()
	{
		cout << "B::func1()" << endl;
	}
	virtual void func3()
	{
		cout << "B::func3()" << endl;
	}
	virtual void func4()
	{
		cout << "B::func4()" << endl;
	}
	virtual void bf()
	{
		cout << "bf()" << endl;
	}
};
class C :virtual public A
{
public:
	virtual void func1()
	{
		cout << "C::func1()" << endl;
	}
	virtual void func3()
	{
		cout << "C::func3()" << endl;
	}
	virtual void func4()
	{
		cout << "C::func4()" << endl;
	}
	virtual void cf()
	{
		cout << "cf()" << endl;
	}
};
class D :public B, public C
{
public:
	virtual void func1()
	{
		cout << "D::func1()" << endl;
	}
	virtual void func3()
	{
		cout << "D::func3()" << endl;
	}
	virtual void func5()
	{
		cout << "D::func5()" << endl;
	}
	virtual void df()
	{
		cout << "df()" << endl;
	}
};

typedef void(WINAPI*vt_fun)();
void PrintVTable(int *vtable)
{
	printf("虚函数表：%p\n", vtable);
	cout << "--------------------------------------" << endl;
	for (size_t i = 0; vtable[i] != 0; ++i)
	{
		printf("vfun[%d]:%p->", i, vtable[i]);
		vt_fun fun = (vt_fun)vtable[i];
		fun();
	}
	cout << "--------------------------------------" << endl;
	cout << endl;

}
int main()
{
	A a; B b; C c; D d;
	//cout << "打印A对象的虚函数表" << endl;
	//int *vtable1 = (int*)(*(int*)&a);
	//PrintVTable(vtable1);
	//cout << "打印B对象的虚函数表" << endl;
	//int *vtable2 = (int*)(*(int*)&b);
	//PrintVTable(vtable2);
	//int *vtable21 = (int*)(*(int*)((char*)&b+sizeof(b)-sizeof(a)));
	//PrintVTable(vtable21);
	//cout << "打印C对象的虚函数表" << endl;
	//int *vtable3 = (int*)(*(int*)&c);
	//PrintVTable(vtable3);
	//int *vtable31 = (int*)(*(int*)((char*)&c + sizeof(c)-sizeof(a)));
	//PrintVTable(vtable31);

	cout << "打印D对象的虚函数表" << endl;
	int *vtable4 = (int*)(*(int*)&d);
	PrintVTable(vtable4);
	int *vtable41 = (int*)(*(int*)((char*)&d + sizeof(b)-sizeof(a)));
	PrintVTable(vtable41);
	int *vtable42 = (int*)(*(int*)((char*)&d + sizeof(d)-sizeof(a)));
	PrintVTable(vtable42);
	//printf("%d\n", sizeof(a));//4
	//printf("%d\n", sizeof(b));//12
	//printf("%d\n", sizeof(c));//12
	//printf("%d\n", sizeof(d));//20

	system("pause");
	return 0;
}