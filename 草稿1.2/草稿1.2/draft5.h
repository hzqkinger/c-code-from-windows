#pragma once

//class CC//�ж������̳й�ϵ�����Ǹ��Ǹ��ࣨ���쳣�ķ���ò�Ʋ��У�
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
//point::point(int xx = 0, int yy = 0)//�������Ĭ�ϲ���������ж��Ĭ�Ϲ��캯����
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
	//	cout << "�����i���͵�ֵʱ��ѭ������" << endl;//�������������ַ����ڻ�����5
	//}
	////string name;
	////while (cin >> name)
	////{
	////	cout << "����ctrl z��������" << endl;//���ǽ���ѭ����ctrl z���ڻ�������
	////}
	printf("%.2f\n", 2.6666);//�����Ȼ����������
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

	//cin >> int intput;//��
	//double salary = wage = 9.7;//��
	int __un = 1;
	int _Un = 2;
	int i3;//�����Ҷ������i3
	int &r3 = i3;//r3��i3������
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
	int aa = 2;  //c++11�±�׼�涨������Ϊ���ݳ�Ա�ṩһ�����ڳ�ʼֵ
	int bb = { 3 };
	int cc{ 4 };
	//int dd(5);��
};
#include<string>
void teSt2()
{
	string s1 = "123";
	string s2 ="456"+ s1;
	//string s3 = "12" + "34"+ s1;//�мǣ����ܰ�����ֱֵ�����
	string s3 = s1 + "12" + "34";
	for (auto c : s3)//c++11�±�׼�ṩ�ķ�Χfor���
	{
		cout << c << " ";
	}
	cout << endl;
	string s4 = "some s tr   ing";
	for (size_t i = 0; i < s4.size(); ++i)//��ÿ�����ʵ�����ĸ�ĳɴ�д
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
//�������������һ��sting����(ע�⣬�������꣬���ƴ�С��)eg.���룺10�������1910 01 01 00:00:10
string Second()
{
	string str("01970 01 01 00:00:00");
	long long int second;//ֻҪ�����second������long long�ķ�Χ��������ȷ�������
	cin >> second;
	int year = second / (60 * 60 * 24 * 365); second %= 60 * 60 * 365;
	int month = second / (60 * 60 * 24 * 30);second %= 60 * 60 * 30;
	int day = second / (60 * 60 * 24); second %= 60 * 60 * 24;
	int hour = second / (60 * 60);second %= 60 * 60;
	int min = second / 60;second %= 60;
	int arr[6] = { year, month, day, hour, min, second };
	size_t i = 4, tmpi = i,j = 1;
	while (i > 0 || year)//�������
	{
		if (i == 0)
		{
			str.insert(0, 1, year % 10 + '0');//�����ʼyear<=99999-1970,��ô�ⲽ����ִ�С�
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
	while (j < 6)//��������ʱ����
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
	vector<int> v(10);//��ʼ��
	v.reserve(15);//��ֻ��˵��v��capacity�Ĵ�С��15��
	size_t j = 0;
	for (auto &c : v) //��Χfor���
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
	void clear(AA7 a);//BB7�ĳ�Ա����
};
class AA7{
	int a = 1;//˽��
public:
	friend void BB7::clear(AA7 a);//AA7����Ԫ����
	int b = 2;//����
};
void BB7::clear(AA7 a)
{
	a.a = 10; a.b = 11;//���Է���˽�г�Ա����������ĺ�������ʲô��˼û�㶮
}
class ABA7{
	int a = 1;
public:
	friend void get(ABA7 a){a.a = 10;}//�������Ԫ�����ܹ�����ABA7��˽�г�Ա
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
	A8(int i) :_i(i){}//��
	explicit A8(char ch) :_i(ch){}//��������캯��ֻ������ֱ�ӳ�ʼ��
private:
	int _i;
};
void teSt8()
{
	A8 a = 1.1;//�ٿ�����ʼ������ִ������ʽ������ת��
	A8 a3 = 5;//�ٿ�����ʼ��
	A8 a4 = 'a';//�ٿ�����ʼ��
	A8 a5(6);//��ֱ�ӳ�ʼ��
	//A8 a2(2.2);//����ͬʱ���������������캯�����������ò���ȷ��//ֱ�ӳ�ʼ������ִ������ʽ������ת��
	A8 a6('a');//�ڵ������ƹ��캯��
	short b = 2; char ch = 'a';
	A8 a7(b);//��
	A8 a9(ch);//��

	static int i;//�ֲ���̬������ʼ��Ϊ0��(ע�⣬��û���øú���ʱ����Ѿ���ʼ����)
	cout << i << endl;
}

class AA9{
	char *_str;
public:
	AA9(char *str) :_str(str){ cout << "���캯��" << endl; }
	AA9(const AA9 &a) :_str(a._str){ cout << "�������캯��" << endl; }

};
int& foo9(int _b)//����һ�����ã���ô��˵���ú�������һ����ֵ
{
	_b += 1;
	//return b+5;//����ֻ�ܰ��ڶ����ϣ�������������ֵ��ĳ�����ʽ�ļ���������һ��
	return _b;//����Ȼ��ò���������У������ð󶨵���һ�������ľֲ�����ȥ�ˣ�
}
void teSt9()
{
	//AA9 a("9999999999");//ֱ�ӳ�ʼ�������ù��캯��
	//AA9 a2 = "555555555";//������ʼ�������ù��캯��
	//AA9 a3(a);//ֱ�ӳ�ʼ�������ÿ������캯��
	//AA9 a4 = a;//������ʼ�������ÿ������캯��
	int a = 10;
	int &c = foo9(a);//һ����Ҫ���ؾֲ����������û�ָ�룬��������δ�����
	cout << c << endl;
}

//�����������к����ص�����
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
	int *p1 = new int;//�ٽ������������������ͣ������������
	/*free(p1);*/    /*delete p1;*/   delete[] p1;

	int *p2 = new int[10];//��
	/*free(p2); */    /*delete p2; */  delete[]p2;

	AA10 *p3 = new AA10;//�۽��������������Ӧ�ñ�ѽ
	/*free(p3); */    /*delete p3;*/   delete[]p3;

	AA10 *p4 = new AA10[10];//��
	/*free(p4);*/    /*delete p4; */   delete[] p4;

	int *p5 = (int*)malloc(sizeof(int));//�ݽ���������ĵ�����ҲӦ�ñ�
	/*free(p5);*/   /*delete p5;*/     delete[]p5;

	int *p6 = (int*)malloc(sizeof(int)* 10);//�޽���������ĵ�����ҲӦ�ñ�
	/*free(p6);*/   /*delete p6;*/     delete[]p6;

	AA10 *p7 = (AA10*)malloc(sizeof(AA10));//�߽���������ĵ�����ҲӦ�ñ�
    /*free(p7);*/   /* delete p7;*/     delete[]p7;

	AA10 *p8 = (AA10*)malloc(sizeof(AA10)* 10);//�ི��������ĵ�����ҲӦ�ñ�
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
//	intf((int[]){ 5 });//����������  ����.c�ļ��¿�������������ֵǿת��.cpp�Ͳ����ˣ�
//	system("pause");
//	return 0;//ͷ�ļ��а�����#define EXIT_SUCCESS 0��#define EXIT_FAILURE 1
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
	f11(lg2);//ʵ����lg1ʱ�ж����ԣ�lg2ʱû��
	//AA11 a(lg);
}

class A12{
	int _a;
public:
	A12(int a) :_a(a){ cout << "���๹�캯��" << endl; }
	A12(const A12 &a) :_a(a._a){ cout << "���࿽�����캯��" << endl; }
	void f1(A12 a){ cout << "����f1����" << endl; }
	virtual void f2(int a = 10){ cout << a << endl; }
	virtual A12 f3(){ return *this; }
	virtual A12 *f4(){ return this; }
	virtual void f5()final{}
	virtual void f6(){}
	virtual void f7(){ cout << "����f7()" << endl; }
};
class B12 :public A12{
	int _b;
public:
	B12(int a, int b) :A12(a), _b(b){ cout << "�����๹�캯��" << endl; }
	B12(const B12 &b) :A12(b), _b(b._b){ cout << "�����࿽�����캯��" << endl; }
	void f2(int a = 5){ cout << a << endl; }//��һ�����������Ҫ����ĳ���̳ж������麯�����������β����ͱ�������ຯ����ȫһ��
	//B12 f3(){ return *this; }//��ͬʱ��������ҲҪ��ȫһ��
	B12 *f4(){ return this; }//�۵�����麯�������������౾���ָ�������ʱ���ڹ���ʧЧ
	//void f5(){}//�����޷���дfinal����
	//void f6(int a)override{}//���������override�Ĺؼ��֣���ô˵���������������д������麯��,���򱨴�
	void f6(int a){}//���û�У���ô������������˻����f6()���������������麯��
	void f7(){ cout << "������f7()" << endl; A12::f7(); }
};
void teSt12()
{
	//B12 b(5, 6);
	//B12 b2(b);
	//cout << endl;
	//A12 a(b);//ע�⣺�����ǳ�ʼ�����߸�ֵһ�������͵Ķ���ʱ��ʵ�������ڵ���ĳ������
	//a.f1(b);
	////A12 a1(5);
	////A12 a2(a1);

	B12 b(5, 6);
	A12 *pa = &b;
	pa->f2();//���麯����Ĭ��ʵ�ε�ʱ����ô��ʵ��ֵ�ɱ��ε��õľ�̬���;���
	//pa->f3();
	pa->f4();
	pa->f7();//ʹ����������������Իر��麯���Ļ���
}

class A13
{
public:
	static A13 GetObj(int a){ return A13(a); }//��̬��Ա��������ջ�ϴ��������
	static A13 *GetObj2(int a){ return new A13(a); }//��̬��Ա�������ڶ��ϴ��������
	friend A13 GetObj3(int a){ return A13(a); }//��Ԫ��������ջ�ϴ��������
	friend A13 *GetObj4(int a){ return new A13(a); }//��Ԫ�������ڶ��ϴ��������
	void f1(){ cout << "hha" << endl; }

	A13(const A13 &a){}
private:
	int _a;
	A13(int a) :_a(a){}//�����캯��˽�л�,��ô���಻�ܱ��̳�
	~A13(){}//����������˽�л�����ô�������ֻ���ڶ���new����
};
A13 GetObj3(int a);//���������ڶ������Ԫ������Ҳ�����������ṩ�����Ӷ�ʹ�ú����ɼ�
A13 *GetObj4(int a);
class AA13{
public:
	void ff1(){ cout << "hhhhhhhh" << endl; }
private:
	int _a;
	void *operator new(size_t i){}//����new����������ҽ���˽�л�����ô����ֻ����ջ�ϴ�������
};
void teSt13()
{
	//A13 a1(A13::GetObj(5));//���þ�̬�����õ�һ������Ȼ���ÿ������캯����ʼ��a1��
	//a1.f1();
	//A13 a2 = a1;
	//a2.f1();

	A13 *pa = A13::GetObj2(6);
	pa->f1();
	A13 *pa2 = pa;//�ⲽֻ�Ǽ򵥵�ָ�븳ֵ���
	pa2->f1();

	AA13 aa;
	aa.ff1();
	//AA13 *pa = new AA13;//��

}

class A14{
public:
	A14(int a, int b) :_a(a), _a2(b){}
	//��Ԫ��������ͨ��������󣬲������ø�������г�Ա��ע���Ǳ��룩
	//friend void f144(){ cout << _a2 << endl; cout << _a << endl; }//��
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
//ģ��ʵ���ƶ�����ʱ������������������ת���⣬���ݸ���Щ�βε�ʵ�α��������ͬ������
void teSt15()
{
	int a = 10;const int b = 5;
	Fobj(a, b);//�ٺ��Զ���const��������һ��������const�������βλ���ʵ���У����ᱻ����
	Fref(a, b);//��constת�������Խ�һ����const�ö���(��ָ��)���ݸ�const������(��ָ��)�β�
	int c[10], d[5];
	Fobj(c, d);//����f(int*,int*)    //��������ߺ���ָ���ת��
	//Fref(c, d);//�����������Ͳ�ƥ��

	Fobj("hi", "world");//�ԣ�������ָ���ת��
	//Fref("hi", "world");//����
}

template<typename T> void FFF(int a, T b)
{
	cout << a << " " << b;//����ģ�����������ͨ���Ͷ���Ĳ���
}
template<typename T>auto FCN(T a, T b)->decltype(*a)
{
	return *a;//�����ʾFCN�ķ��������������a�����Ľ��������ͬ
}
void teSt16()
{
	string s("abc");
	FFF(5, s);
	cout << endl;
	FFF(6, 7.7);

	FCN(s.begin(), s.end());//��������������char&����Ϊstring�ĵ�����������������char��
	vector<int> v = { 1, 2, 3, 4, 5 };
	FCN(v.begin(), v.end());//��������������int&
}

class A17{
};

void teSt18()
{
	const unsigned N = 10;
	int arr[N+1];//��������ʱ��������������������ͳ����������ͳ������ʽ
}

template<typename T>string debug_rep(const T &t)//��
{
	//ostringstream ret;
	//ret << t;
	//return ret.str();
	cout << "555555555555";
	return string();
}
template<typename T> string debug_rep(T *p)//��
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
string debug_rep(const string &s)//��
{
	cout << "7777777777777";
	return string();
}
template<typename T>void debug_rep2(const T &a, const T &b)//��
{
	cout << "1111111111" << endl;
}
template<typename T1, typename T2>void debug_rep2(const T1 &a, const T2 &b)//��
{
	cout << "22222222222" << endl;
}
void debug_rep2(const int &a, const char &b)//��
{
	cout << "333333333" << endl;
}
void teSt19()
{
	//�ȿ�����Щ���غ����ɲ�����ƥ�䣬�ٿ�����Щ�������Ծ�ȷƥ�䣬�������Щ��������������
	debug_rep2(2, 5);//�ܢݢ޶�����ƥ�䣬ֻ�Тܢ��Ǿ�ȷƥ�䣬���Ǣܸ������������Ի���â�
	debug_rep2(2, 'a');//�ܲ���ƥ�䣬�ݢ޶��Ǿ�ȷƥ�䣬���Ǣ��Ƿ�ģ�庯��(����������)�����Ի���â�
	debug_rep2('a', 2);//�ܲ���ƥ�䣬�ݢ޶���ƥ�䣬�����Ǿ�ȷƥ�䣬���Ի���â�

	//cout << debug_rep("hi") << endl;
	//debug_rep(const T&),T���󶨵�char[3]����ȷƥ��
	//debug_rep(T*),T���󶨵�const char����ȷƥ�䣬���Ǵ˰汾��������������˻������
	//debug_rep(const string&)��Ҫ���const char*��string��������ת�����Ǿ�ȷƥ�䣬���Ԣ٢ڢ�ͬʱ����ʱ����â�

	string s("hi");
	////��һ���Ǻ���ģ����һ������ģ���ṩͬ���õ�ƥ�䣬��ѡ���ģ��(����ķ�������û�Т۵Ļ����ϵ�)
	//cout << debug_rep(s) << endl;//ֻ���â���ʵ����
	//cout << debug_rep(&s) << endl;//��Ȼ�â٢ڶ�����ʵ���������Ǣ��Ǿ�ȷƥ�䣬���Ի���â���ʵ����

	//const string *sp = &s;
	//cout << debug_rep(sp) << endl;//��Ȼ�٢ڶ��Ǿ�ȷƥ�䣬���Ǣڸ������������Ի���â���ʵ����
	////debug_rep(const T&)�����Ͽ��Խ����κ����ͣ�����ָ������
	////debug_rep(T*)ֻ������ָ�����ͣ�û�������ͨ��
}

template<typename T,typename... args>void foo(const T &t, const args& ... ret)
{//����һ�������������˻�ȡ���Ĵ�С������Ψһ�������Ƕ���������չ��
	cout << sizeof...(args) << " ";//ģ������������Ͳ�������Ŀ
	cout << sizeof...(ret) << endl;//�����������ĺ�����������Ŀ
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
	Print20(cout,i, s, 42, d);//������Ŀɱ�δ�ӡ����
}

class cat{};
template<typename T>class AA21{

};
//ģ��ʵ�α�����һ�������ڱ�����ȷ����ģ��ʵ���ֵ��
//��Ϊ����ģ�����������ԣ��������տ��Ա������ڵ�ֵ���滻�����ǾͿ��Ա����ںϳɱ����ڵı��ʽ
void teSt21()
{
	AA21<cat> a;
}

typedef char* pea;//                                   (�ڱ����ڵ�ʱ����)
#define app int*  //ֻ�����˸��򵥵��滻�������ͼ��   (��Ԥ�����ʱ����)
void teSt22()
{
	char ch = 'a';
	const pea Pa = &ch;//����ָ��
	pea const Pb = &ch;//����ָ��
	pea Pc, Pd;//Pc��Pd����char*��ָ�����
	//unsigned pea Pe;//�������ͱ�������������˵����������չ

	int i = 5;
	const app pa = &i;//ָ������ָ��
	app const pb = &i;//����ָ��
	app pc, pd;//pc��char*��ָ�������pd��char�ͱ���
	unsigned app pe;//�ԣ�����������˵����������չ
}

//ģ�������λ�ں���ģ�����Ƶ�ǰ�棬��һ�Լ������ڲ���������  ps:T1,T2��T3����ģ�����
//���ò�����λ�ں���ģ�����Ƶĺ��棬��һ��Բ�����ڲ���������  ps:a��b���ǵ��ò���
template<typename T1,typename T2,typename T3>
T3 teSt23(T1 const& a,T2 const& b)//ģ��ʵ�����ﲢ���ʺϷ������ͣ������û�������ʽ��ָ��ģ��ʵ���б�
{
	//��ģ������͵��ò���û�з������������߲����е��ò���������ģ�������ʱ�����ڵ���ʱ�ͱ�����ʽ
	//ָ��ģ��ʵ��
}
template<typename T3,typename T1,typename T2>
T3 teSt231(T1 const& a, T2 const& b){}
template<typename T1,typename T2>
void teSt232(T1 const& a, T2 const& b){}
template<typename T>
void teSt233(T const& a, T const &b){}//ע��;���ﲻ�����Զ�����ת����ÿ��T��������ȷƥ��

void teSt24()
{
	stack < int, std::vector<int, std::allocator<int>>> s1;
	stack < int, std::vector<char, std::allocator<char>>> s2;//STL����û��ʹ��û��ʹ��ģ���ģ�����������ʹ�õ�����
	stack<int> s3;
	stack<int, std::deque<int, std::allocator<int>>>s4;

	s3 = s4;//�ԡ�ջ֮��ֻ��������ȫ��ͬʱ���ܻ��ำֵ������ʹ������(Ԫ�ص�)����֮�������ʽ����ת��Ҳ����
	//s3 = s2;//��ȱʡ��������߲�������ͬ������
	//s3 = s1;//��ȱʡ��������߲�������ͬ������
	//ps:��Ȼ������ͨ��������ʵ�ִ��������ȫ����֮����໥��ֵ
}

template<typename T,template<typename /*ELE*/,typename/* ALLOC = std::allocator<ELE>*/>class con = std::vector>
class Cat25{//�ڶ���ģ���������д��Ŀ����Ϊ�˱����ò����Ǹ�ģ�����������
};
template<>class Cat25<int, deque>{};//��ģ����ػ�(ps:����ģ�岻���ػ��������ǻ���ģ��)
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
	cout << _itoa(i, arr, 10) << endl;//��c++����_itoa����c����itoa��
}

void teSt27(char ch = 'a', int i = 0)
{//�����κ�һ��������ֻ����֮��Ĳ������ṩ��ȱʡʵ�ε�ǰ���£������ܾ���ȱʡʵ��
	int i2 = 1, i3;//ע��:�ֲ������������һ��
}

class Cat280{//��ͨ��
public:
	void f00(){ cout << "��ͨ��Ա����" << endl; }
	template<typename T>void f01(const T& a){ cout << "��Ա����ģ��" << endl; }
	template<typename T8>class Cat2801{};//λ�����ڲ��ĳ�Ա��ģ�壬�������ⲿ����
private:
	int _i;
};
void teSt28()
{
	Cat280 cc0;
	cc0.f01(5);
	Cat280::Cat2801<char> cc01;
}
template<typename T>class Cat28{//��ģ��
public:
	template<typename T2> Cat28(T2 const& c = T2()) :_c(c){ cout << "11" << endl; }//��Ա����ģ��
	template<typename T6> void f(const T6& a);//��Ա����ģ�������
	void f2(T const& a){ cout << "77" }//��ͨ��Ա����
	template<typename T, typename T3>class Cat281{//λ�����ڲ��ĳ�Ա��ģ��,�������ڲ�������
	public:
		Cat281(T const& a, T3 const& b) :_cc(a), _cc2(b){ cout << "22" << endl; }
	private:
		T _cc;
		T3 _cc2;
	};
	template<typename T4,typename T5>class Cat282;//λ�����ڲ��ĳ�Ա��ģ�壬�������ⲿ����
private:
	T _c;
};
template<typename T>/*��Χ������Ͳ���*/template<typename T6>/*��Ա����ģ������Ͳ���*/
void Cat28<T>::f(const T6& a)
{
	cout << "666" << endl;
}
template<typename T>/*��Χ������Ͳ���*/template<typename T4, typename T5>/*Ƕ��������Ͳ���*/
class Cat28<T>::Cat282{
public:
	Cat282(T const& a, T4 const& b,T5 const& c) :_ccc1(a), _ccc2(b),_ccc3(c){cout<<"33";}                                     
	T _ccc1;T4 _ccc2;T5 _ccc3;
};

extern "C++"template<typename T>//ģ�������Ǿ������ӵģ������ǲ��ܾ���C����
void tsSt29(T const& a)
{//ģ��ͨ�������ⲿ���ӡ��������������
	cout << "aaaa" << endl;
}
template<typename T>
static void teSt291(T const& a){}//��ģ�岻�����ⲿ����

//����2��  
template<class T, int MAXSIZE> class List30{
private:
	T elems[MAXSIZE];
public:
	void Print(){ cout << "The maxsize of list is " << MAXSIZE; }
};
const int num1 = 9;//ȫ�ֱ���  ����
static int num2 = 9;//ȫ�ֱ���  �ǳ���
const static int num4 = 9;//ȫ�ֱ���  ��̬����
//����3��  //�ٿ�һ������ָ����ַ����Ƚ��ر������  
template<char const* name>
class pointerT30{
};
char a[] = "saaa";;//ȫ�ֱ���  a�ǳ������ʽ
char *b = "saaa";//ȫ�ֱ���     b���ǳ������ʽ
char *const c = "saaa";//ȫ�ֱ���������ָ�룬ָ�볣��  
void teSt30()
{
	//�������һ�·�����ʵ�εľ���
	//  0.ͨ�����ԣ�������ʵ�ο����Ǣٳ����������ߢ�ָ���ⲿ���Ӷ����ָ�������ã����Ұ󶨵����βε�ʵ�α���
	//    �ǳ������ʽ�����ڱ����ھͿ���ȷ������(ps:ע��Ū������ֶ������ڲ����ӻ����ⲿ����)
	//	1.ʵ�α����Ǳ���ʱ�������ʽ
	//	2.��Const��ȫ��ָ�룬ȫ�ֶ���ȫ�ֱ�������������и������������ǳ������ʽ��
	//	3.�����βε��Ѿ������޶����ַ����������ͼ�ʹ�ǳ������ʽҲ��������Ϊ������ʵ��
	//	��ע���������ʽ������������ֵ�Լ�const���εı���
	const int num3 = 9;;//�ֲ����� ����
	List30<int, num1> L1; //��ȷ  
	//List<int, num2> l2; //����  
	List30<int, num3> L3; //��ȷ  
	List30<int, num4> L4; //��ȷ 


	char a2[] = "saaa";;//�ֲ���������Ȼa2�ǳ������ʽ������������ָ���ⲿ���Ӷ����ָ��

	//pointerT30<"testVarChar">  p1;//����  �涨�ַ����͸��������������������Ͳ��� 
	pointerT30<a>  p2;//��ȷ  
	//pointerT30<a2>  p22;//���󣬾ֲ������������������Ͳ���  
	//pointerT30<b>  p3;//����error C2975:��pointerT����ģ�������Ч��ӦΪ����ʱ�������ʽ  
	//pointerT30<c>  p4;//����error C2970: ��c��: �漰�����ڲ����ӵĶ���ı��ʽ�������������Ͳ��� 
}


//1�����������˵����˵����Ԫ������˵��ʱ�Թؼ���friend��ͷ�������Ԫ�����ĺ���ԭ�ͣ���Ԫ������˵�����Գ���������κεط���������private��public���֣�
//2��ע����Ԫ����������ĳ�Ա������������Ԫ������ʵ�ֺ���ͨ����һ������ʵ��ʱ����"::"ָʾ�����ĸ��ֻ࣬�г�Ա������ʹ��"::"��������ţ�
//3����Ԫ��������ֱ�ӷ�����ĳ�Ա��ֻ�ܷ��ʶ����Ա��
//4����Ԫ�������Է��ʶ����˽�г�Ա������ͨ�������У�
//5��������Ԫ����ʱ����ʵ�ʲ�������Ҫָ��Ҫ���ʵĶ���
//6��������֮�����Ԫ��ϵ���ܼ̳С�
//7��һ����ĳ�Ա����Ҳ������Ϊ��һ�������Ԫ���������ȶ�������ࡣ
template<typename T>class Cat31{//��ģ��
public:
	//��Ԫ�������������ʱ������ֻ�����������Ҷ��壬��ʹ�������Ҳ�����ҵ�����Ԫ������
	//���ǵ���Ԫ����û�з��������ʱ�����������������������壬��ô����޷��ҵ�����Ԫ����
	template<typename T2> friend void f2(Cat31<T> const& a)
	{
		cout << "1111" << endl;//��Ԫ����ģ������ģ���Ƕ�Զ�Ĺ�ϵ
	}
private:
	friend void f(Cat31<T> const& a)//�����Ͻ���ͨ��Ԫ����ģ����һ��һ�Ĺ�ϵ
	{    //����Ԫ�������Է��ʸ���ģ�������ʵ������ʵ����ÿ��ʵ�����������Ԫ���������غ���
		cout << a._a << endl;
	}
	T _a;
	//friend void _f33(){}//����f3()����������������ô�����Ҳ���f3;
	////����ÿ��ʹ��Cat31<T>���ṹ��_f33()�������壬������ģ���ﲻ������������Ԫ����
};
//void f(Cat31<T> const& a);
class Cat311{//��ͨ��
public:
	friend void ff(Cat311 const& a)//��ͨ��Ԫ
	{
		cout << a._i << endl;
	}
	template<typename T> friend void ff2(Cat311 const& a)//��Ԫ����ģ��
	{
		cout << "555555" << endl;
	}
private:
	int _i;
};
void teSt31()
{
	//f����ͨ��Ԫ������f2����Ԫ����ģ�壨ps:_ff3��û�з�����������ͨ��Ԫ����ģ����һ�㲻�������������Ԫ��ԭ�����ϣ�
	Cat31<int> c;
	f(c);//��ʵ������void f(Cat31<int> const& a){}
	f2<char>(c); /*f2(c);*///��ʵ������template<char>void f2(Cat31<int> const& a){}
	f2<float>(c);//��ʵ������template<float>void f2(Cat31<int> const& a){}

	Cat31<char> ch;
	f(ch); //��ʵ������void f(Cat31<char> const& a){}
	f2<int>(c);//��ʵ������template<char>void f2(Cat31<char> const& a){}
	f2<float>(ch);//��ʵ������template<float>void f2(Cat31<char> const& a){}
	//_f33();

	Cat311 cc;
	ff(cc);//��ͨ�����ͨ�Ѻ���
	ff2<int>(cc);//��ͨ�����Ԫ����ģ��
}

template<typename T>class Cat32
{
public:
	typedef vector<T> intv;//��ģ������ͳ�Ա
	static std::size_t Count(){ cout << "222" << endl; return Ctr; }
private:
	static std::size_t Ctr;//��̬���ݳ�Ա������
};
template<typename T>size_t Cat32<T>::Ctr = 0;//��̬���ݳ�Ա�Ķ��壨ps:��̬��Ա�ĳ�ʼ�����������⣩
void teSt32()
{
	Cat32<int>::Count;//�ۣ�������Ȼû�б���
	Cat32<int>::Count();//ͨ��ʵ��������ֱ�ӷ��ʾ�̬��Ա
	//Cat::Count();�������ͨ����ֱ�ӷ��ʾ�̬��Ա����ô������ʵ��������ȥ����

	//  1.��̬��Ա�����в��ܵ��÷Ǿ�̬��Ա��
	//	2.�Ǿ�̬��Ա�����п��Ե��þ�̬��Ա����Ϊ��̬��Ա�����౾������Ķ������֮ǰ���Ѿ������ˣ������ڷǾ�̬��Ա�������ǿ��Ե��þ�̬��Ա�ġ�
	//	3.��̬��Ա����ʹ��ǰ�����ȳ�ʼ��(��int MyClass::m_nNumber = 0;)���������linkerʱ����
	//	4.����ķǾ�̬��Ա������ʹ����ľ�̬��Ա
	Cat32<char> fi;
	fi.Count();//ͨ��������ʾ�̬��Ա
}

class Cat33{//��ͨ��
public:
	typedef vector<int> intv;
	static int intv2;
};
int Cat33::intv2 = 0;
Cat33::intv ff3(){ cout << "5555555" << endl; return Cat33::intv(); }
////����ͨ���У�������������Ķ��壬�����ܹ������ĸ���������ͳ�Ա���ĸ�����ľ�̬��Ա
template<typename T> class Cat333{//��ģ��
public:
	typedef vector<T> intv3;
	typename Cat32<T>::intv ff31{ cout << "6666" << endl; }//����ģ����ʹ����Cat32<T>�����ͳ�Ա
	//�������ϣ��ʹ��һ��ģ�����Ͳ��������ͳ�Ա���ͱ����ùؼ���typename���߱���������һ������
	static T intv23;
};
//template<typename T> T Cat333<T>::intv23 = 0;//��intv23��ô�Ͳ���Cat333<T>�ĳ�Ա�أ�������

template<typename T>int compare34(const T& a, const T& b)//�ٱȽ���������
{
	cout << "11111111111" << endl;
	return a > b ? 1 : a == b ? 0 : -1;
}
template<size_t N, size_t M>int compare34(const char(&a)[N], const char(&b)[M])//�ڴ����ַ������泣��
{
	cout << "2222222222222" << endl;
	return strcmp(a, b);
}
template<>int compare34(const char* const &p1, const char* const &p2)//�۴����ַ������ָ��
{//һ���������汾��������һ��ʵ��
	cout << "333333333333" << endl;
	return strcmp(p1, p2);
}
//�����ǲ��ܻ��߲�ϣ��ʹ��ģ��汾ʱ�����Զ��������ģ���һ���������汾��
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
	//teSt1();//sizeof(enum)��sizeof(struct)
	//teSt2();//����string
	//string time;
	//time = Second();
	//cout << time << endl;
	//teSt3();a
	//teSt4(4,4,5,6,7);//c���Կɱ�����
	//teSt5({ 1, 2, 3, 4, 5, 'a' });//c++��ʼ���б����ܻ������ڵ�Ԫ���б���Ϊ����
	////                         ��ȱ�㣺Ԫ���б����Ԫ�ر�������ͬ���ͻ���˵����ת��Ϊ�ɽ������ͣ�
	//Mycls5 M51(5, 6);//������ͨ�Ĺ��캯��
	//Mycls5 M52{ 5, 6 };//���þ��г�ʼ���б�Ĺ��캯��
	//Mycls5 M53 = { 5, 6 };//���þ��г�ʼ���б�Ĺ��캯��
	//teSt7();//��Ԫ������̽
	//teSt8();
	//teSt9();//��Ҫ���ؾֲ�����������
	//teSt10();//delete��free�Ȳ�ƥ�����⣨ò�Ƴ����˺����ص����⣩
	//teSt11();//���������Ƿ��ж�����
	//teSt12();//�̳����麯��
	//teSt13();//�ٹ��캯��˽�л�����������˽�л�������new�����
	//teSt14();//��Ԫ��������ͨ��������󣬲������ø�������г�Ա��ע���Ǳ��룩


	//teSt15();//ģ����������ƶϣ�constת�������������ָ���ת��
	//teSt16();//����ģ�����������ͨ���Ͷ���Ĳ���+β�÷�������
	//cout<<sizeof(A17);//ǿ�ҽ��鿴�������̽��C++����ģ�͡�
	//teSt18();//��������ʱ��������������������ͳ����������ͳ������ʽ
	//teSt19();//������ģ�壬��ʵ�������ƶϵ����Ǹ�����
	//teSt20();//�ɱ��ģ��
	//teSt21();
	//teSt22();//#define��typedef��һЩ����
	//����ģ���ʵ������
	//teSt23<int,char,double>(2,'a');//��ʽ��ָ�����к���ģ��ʵ��
	//teSt231<double>(2, 'a');//ֻ��ʽָ����һ������ģ��ʵ�Σ�������������Ƶ�������ĺ���ģ��ʵ��
	//teSt232(2, 'a');//����ʽ��ָ���κκ���ģ��ʵ�Σ�
	////teSt233(2, 'a');//����ps:Ҫ����������������ã������淽�������Ըı�ԭģ�庯����ָ������ģ�������
	//teSt233(2, 5);//�ԡ���������κδ�ʩ��ģ��ʵ��ֻ����ͬһ������
	//teSt233(static_cast<char>(2), 'a');//��
	//teSt233<int>(2, 'a');//��
	//teSt24();
	//teSt25<int>();//ģ���ģ�����(ps:��vs2013�Ϻ���ģ��֧��ģ���ģ�����)
	//Cat25<int> c;//�ڶ�����������Ϊģ���ģ���������ģ���ǰ�������������ͱ���Ҫ��Ĭ��ʵ�ε���ƥ��
	//teSt26();//stoi��itoa
	//teSt27('a',0);//�����κ�һ��������ֻ����֮��Ĳ������ṩ��ȱʡʵ�ε�ǰ���£������ܾ���ȱʡʵ��
	//teSt28();//һ����(��������ͨ�໹����ģ��)���԰���������ģ��ĳ�Ա��������
	//Cat28<int> c('a');//ʹ���������͸�c��Ԫ�ظ�ֵ
	//Cat28<int>::Cat281<int, char> c2(2, 'a');//λ�����ڲ��ĳ�Ա��ģ�壬�������ڲ�����
	//c.f(5);//��Ա����ģ��
	//Cat28<int>::Cat282<float,char> c3(2,2.0,'a');//λ�����ڲ��ĳ�Ա��ģ�壬�������ⲿ����
	//tsSt29('a');//ģ��ͨ�������ⲿ���ӡ��������������
	//teSt30();//������ģ�����������
	//teSt31();//��ģ�����ͨ��Ԫ����Ԫ����ģ�壨ps:����û��̽����ģ�����ͨ��Ԫ�����Ԫ��ģ��Ĺ�ϵ��
	//teSt32();//��ģ���static��Ա��ps;�������һ�����ص����⣩
	teSt34();//ģ���������
}