#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<string>

////普通继承：①构造函数 ②拷贝构造函数 ③赋值运算符重载 ④析构函数 
//class Person
//{
//public:
//	Person(char *name = "hello")//构造
//		:_name(new char[strlen(name)+1])
//	{
//		strcpy(_name, name);
//		cout << "调用了Person构造函数" << endl;
//	}
//	Person(const Person& p)//拷贝构造
//		: _name(new char[strlen(p._name) + 1])
//	{
//		strcpy(_name, p._name);
//		cout << "调用了Person拷贝构造" << endl;
//	}
//	Person& operator=(const Person & p)//赋值运算符重载
//	{
//		if (this != &p)
//		{
//			_name = new char[strlen(p._name) + 1];
//			cout << "调用了Person赋值运算符重载" << endl;
//		}
//		return *this;
//	}
//	virtual ~Person()
//	{
//		delete[] _name;
//		cout << "调用了Person析构" << endl;//由于system("pause")这句代码，所以看不到打印出来的话
//	}
//
//	virtual void Buytickets()
//	{
//		cout << "买票" << endl;
//	}
//	void Display()
//	{
//		cout<< _name << endl;
//	}
//protected:
//	char* _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	//如果父类中构造函数是无参或带全默认参，这里可以不显式调用父类构造函数；否则必须显式调用。
//	Student(char *name = "world", int a = 10)
//		:/*Person(name),*/ _num(a)//假如父类有不默认的参数，前面这句调用一定不能注释掉
//	{
//		cout << "调用了Student构造函数" << endl;
//	}
//	Student(const Student &s)
//		:Person(s._name), _num(s._num)
//	{
//		cout << "调用了Studentk拷贝构造" << endl;
//	}
//	Student& operator=(const Student &s)
//	{
//		if (this != &s)
//		{
//			cout << "调用了Student赋值运算符重载" << endl;
//			Person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	virtual ~Student()
//	{
//		cout << "调用了Student析构函数" << endl;
//	}
//
//	virtual void Buytickets()
//	{
//		cout << "买半价票" << endl;
//	}
//protected:
//	int _num; // 学号
//};
//
//void Fun(Person &p)
//{
//	p.Buytickets();
//}
//int main()
//{
//	//Person p1("hello ");
//	//Person p2 = p1;
//	//Person p3;
//	//p3 = p1;
//	//Student s1;
//	//Student s2 = s1;
//	//Student s3;
//	//s3 = s1;
//
//	Person p;
//	Student s;
//	Fun(p);
//	Fun(s);
//
//	system("pause");
//	return 0;
//}

//菱形继承——虚继承,子类的对象模型
class A
{
public:
	int _a1;
	int _a2;
};
class B :virtual public A
{
public:
	int _b;
};
class C :virtual public A
{
public:
	int _c;
};
class D:public B,public C
{
public:
	int _d;
};
int main()
{
	A a; B b; C c;
	D d;
	a._a1 = 1; a._a1 = 1;

	b._a1 = 10;	b._a1 = 10;
	b._b = 2;
	c._a1 = 11;	c._a1 = 11;
	c._c = 3;

	d._a1 = 12; d._a1 = 12;
	d._b = 13;
	d._c = 14;
	d._d = 15;

	printf("%d\n", sizeof(a));//8
	printf("%d\n", sizeof(b));//16
	printf("%d\n", sizeof(c));//16
	printf("%d\n", sizeof(d));//28

	system("pause");
	return 0;
}