#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<string>

////��ͨ�̳У��ٹ��캯�� �ڿ������캯�� �۸�ֵ��������� ���������� 
//class Person
//{
//public:
//	Person(char *name = "hello")//����
//		:_name(new char[strlen(name)+1])
//	{
//		strcpy(_name, name);
//		cout << "������Person���캯��" << endl;
//	}
//	Person(const Person& p)//��������
//		: _name(new char[strlen(p._name) + 1])
//	{
//		strcpy(_name, p._name);
//		cout << "������Person��������" << endl;
//	}
//	Person& operator=(const Person & p)//��ֵ���������
//	{
//		if (this != &p)
//		{
//			_name = new char[strlen(p._name) + 1];
//			cout << "������Person��ֵ���������" << endl;
//		}
//		return *this;
//	}
//	virtual ~Person()
//	{
//		delete[] _name;
//		cout << "������Person����" << endl;//����system("pause")�����룬���Կ�������ӡ�����Ļ�
//	}
//
//	virtual void Buytickets()
//	{
//		cout << "��Ʊ" << endl;
//	}
//	void Display()
//	{
//		cout<< _name << endl;
//	}
//protected:
//	char* _name; // ����
//};
//class Student : public Person
//{
//public:
//	//��������й��캯�����޲λ��ȫĬ�ϲΣ�������Բ���ʽ���ø��๹�캯�������������ʽ���á�
//	Student(char *name = "world", int a = 10)
//		:/*Person(name),*/ _num(a)//���縸���в�Ĭ�ϵĲ�����ǰ��������һ������ע�͵�
//	{
//		cout << "������Student���캯��" << endl;
//	}
//	Student(const Student &s)
//		:Person(s._name), _num(s._num)
//	{
//		cout << "������Studentk��������" << endl;
//	}
//	Student& operator=(const Student &s)
//	{
//		if (this != &s)
//		{
//			cout << "������Student��ֵ���������" << endl;
//			Person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//	virtual ~Student()
//	{
//		cout << "������Student��������" << endl;
//	}
//
//	virtual void Buytickets()
//	{
//		cout << "����Ʊ" << endl;
//	}
//protected:
//	int _num; // ѧ��
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

//���μ̳С�����̳�,����Ķ���ģ��
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