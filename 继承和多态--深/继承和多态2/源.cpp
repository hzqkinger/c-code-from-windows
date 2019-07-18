#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
////单继承下，父类和子类的对象模型
//class base
//{
//public:
//	virtual void func1()
//	{
//		cout << "base::func1" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "base::func2" << endl;
//	}
//public:
//	int _a;
//};
//class deprive:public base
//{
//public:
//	virtual void func1()
//	{
//		cout << "deprive::func1" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "deprive::func3" << endl;
//	}
//	virtual void func4()
//	{
//		cout << "deprive::func4" << endl;
//	}
//public:
//	int _b;
//};
//
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
//
//int main()
//{
//	base b1;
//	b1._a = 1;
//	deprive d1;
//	d1._b = 2;
//	int *vtable1 = (int*)(*(int*)&b1);
//	int *vtable2 = (int*)(*(int*)&d1);
//	PrintVTable(vtable1);
//	PrintVTable(vtable2);
//
//
//	system("pause");
//	return 0;
//}

//多继承下，子类的对象模型
class base1
{
public:
	virtual void func1()
	{
		cout << "base1::func1" << endl;
	}
	virtual void func2()
	{
		cout << "base1::func2" << endl;
	}
public:
	int _b1;
};
class base2
{
public:
	virtual void func1()
	{
		cout << "base2::func1" << endl;
	}
	virtual void func2()
	{
		cout << "base2::func2" << endl;
	}
public:
	int _b2;
};
class deprive :public base1,public base2
{
public:
	virtual void func1()
	{
		cout << "deprive::func1" << endl;
	}
	virtual void func3()
	{
		cout << "deprive::func3" << endl;
	}
	void func4()
	{
		cout << "deprive::func4" << endl;
	}
public:
	int _d;
};

typedef void(*v_fun)();
void PrintVTable(int *vtable)
{
	printf("虚函数表：%p\n", vtable);
	for (size_t i = 0; vtable[i] != 0; ++i)
	{
		printf("vfun[%d]:%p->", i, vtable[i]);
		v_fun f = (v_fun)vtable[i];
		f();
	}
}

int main()
{
	deprive d1;
	//int *vtable1 = (int*)(*(int*)&d1);
	//PrintVTable(vtable1);
	//int *vtable2 = (int*)(*(int*)((char*)&d1+sizeof(base1)));
	//PrintVTable(vtable2);

	//判断p1,p2,p3值的情况（p1等于p3， 不等于p2）
	base1 *p1 = &d1;
	base2 *p2 = &d1;
	deprive*p3 = &d1;

	system("pause");
	return 0;
}