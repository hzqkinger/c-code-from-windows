#pragma once


//��Ŀ����
//����n�������������������ӳ�һ�ţ����һ�����Ķ�λ������
//�� : n = 3ʱ��3������13, 312, 343, ���ɵ��������Ϊ34331213��
//�� : n = 4ʱ, 4������7, 13, 4, 246���ӳɵ��������Ϊ7424613��
//�������� :
//�ж������������ÿ����������������У���һ��Ϊһ������N��N <= 100����
//�ڶ��а���N����(ÿ����������1000���ո�ֿ�)��
//������� :
//ÿ���������һ����ʾ����������
//ʾ��1
//����
//4
//7 13 4 246
//���
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
	//cout << (s2 + s > s + s2) << endl;//1 //��ʵ����Ǹ��ַ�����ð����������ַ���A+B>B+A��ô��ΪA>B
	//cout << (s3 + s > s + s3) << endl;//0


	//cout << strcmp("776", "77") << endl;//1
	//cout << strcmp("778", "77") << endl;//1

	//cout << ("ba" > "b") << endl;//0
	//cout << ("bc" > "b") << endl;//1

}

//���಻��ô��ص�����calss
class Foo{
public:
	int val;//һ�����ݳ�Ա(ps:�������ֻ����һ�����ݳ�Ա��ʵ���ϱ�������û�кϳ�default constructor)
	char *p = "123";                          // ����c++��׼˵�ϳ��ˣ�ֻ������û��ʲô�ô���Ĭ�Ϲ��캯��
	double d;
	string s;
	//Foo(){}
	//Foo() = default;
	//Foo(const Foo& f) = default;
	//Foo(const Foo& f):val(f.val)/*,p(new char[strlen(f.p)+1])*/{}
	//string s;//�������ݳ���Ա��ֻ�к��ж������ݳ�Ա�����default constructor�������õģ�

	//ע�⣺һ�����ݳ�Ա�ĳ�ʼ���ǳ���Ա�����Σ����������ݳ�Ա�ĳ�ʼ��ʱ������������
};
class Bar{
public:
	Foo f;//��Ϊf�Ƕ������ݳ�Ա������Bar��default constructor�����õģ����ǲ�����ʾFoo��Ĭ�Ϲ��캯�������õ�
	//string s;
	char *p;
};
//һ��̳���ϵ������class
class base2{
public:
	int _a;
	//virtual void f1()//����һ��virtual function��class��default constructor�����õ�
	//{      //(virtual function��������)    //����default copy constructorҲ�����õ�
	//	cout << "base2::f1()" << endl;
	//}
	base2() = default;
	base2(const base2& b){}
};
class derived2 :public base2{
public://�����û���κι��캯����class�����Դ���default constructor��base class����ô���
	   // derived class��default constructor�ᱻ��Ϊ���õ�
	   //�������derived class���ṩ�˶�����캯������ô�������й��캯�����ᱻ���ţ����ǲ���ϳ�һ��
	   // �µ�default constructor
	//derived2(int b){}
	int _b;
};
//���μ̳���ϵ
class X{ public:int i = 1; };
class A :public virtual X{ public:int j = 2; };
class B :public virtual X{ public:int m = 3; };
class C :public A, public B{ public:int k = 4; };

void test2()//���Թ��캯��������ѧ
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
void test21()//���Կ������캯��������ѧ
{
	Foo f;
	if (f.val){ cout << "hhh" << endl; }

	Bar b1;
	Bar b2 = b1;//ֻ�е�Foo�Ŀ������캯������������ʽ�����Ҷ���������Ǳ��������ϳ�һ�����õ�copy constructorʱ

	//derived2 d;
	//derived2 d2 = d;
	cout << "hah" << endl;
}

//class X2{ public:int i; virtual ~X2(){} };
//class X3{ public:int i = 3; };
//void test3()
//{ //�������ϳɵ�Ĭ�Ϲ��캯��ͨ��ֻ�ǶԱ�������Ч����ʹ�ϳ��ˣ�������Ҳ������������Ҫ��
//	//����д����ʱ�����Լ�д��Ĭ�Ϲ��캯��
//
//	//��Ȼ����class���ϳ���һ��û���õ�Ĭ�Ϲ��캯����������X3�����i��Ĭ��ֵ
//	X2 x2;
//	//if (x2.i){ cout << "haha"; }//����
//	cout << sizeof(x2) << endl;//���Ǳ�Ҫ������Ҫ�����㽫��������д���麯��
//	X3 x3;
//	if (x3.i){ cout << "hehe"; }//��
//}

class X4{
public:
	X4() :_i(0){ cout << "���캯��" << endl; }//�Լ���Ĭ�Ϲ��캯��
	X4(const X4& xx) :_i(xx._i){ cout << "�������캯��" << endl; }//�������캯��
private:
	int _i;
};
X4 foo4(X4 x0)
{
	X4 x1(x0);//����ʽ��ʼ��
	X4 x2 = x0;
	X4 x3 = X4(x0);
	return x1;//�۷���ֵ�ĳ�ʼ��
}
//1.���ܽ�C++�Դ��κϴ�����ֵʱ������Ż�����
//2.������������Ŀ��
//Test1�е�����___��AA�Ŀ������캯��, ___��AA�ĸ�ֵ��������������ء�
//Test2�е�����___��AA�Ŀ������캯��, ___��AA�ĸ�ֵ��������������ء�
//Test3�е�����___��AA�Ŀ������캯��, ___��AA�ĸ�ֵ��������������ء�
class AA{
public:
	AA() :_i(0){ cout << "���캯��" << endl; }
	AA(const AA& a) :_i(a._i){ cout << "�������캯��" << endl; }
	AA &operator=(const AA& a){ cout << "��ֵ��������غ���" << endl; return AA(); }
private:
	int _i;
};
AA f(AA a)//���������ο������캯��
{
	return a;
}
void test41()
{
	AA a1;//������һ��Ĭ�Ϲ��캯��
	a1 = f(a1);//��ֵ��������غ����Ϳ������캯��
}
void test42()
{
	AA a1;//������һ��Ĭ�Ϲ��캯��
	AA a2 = f(a1);//���������ο������캯����ԭ������Ҫ�������εģ����Ǳ������Ż�����һ�Σ�
}
void test43()
{
	AA a1;//������һ��Ĭ�Ϲ��캯��
	AA a2 = f(f(a1));
}
void test4()
{
	//X4 xx;
	//cout << endl;
	//foo4(xx);//�ڲ����ĳ�ʼ��
	//cout << endl;
	//X4 xx2 = foo4(xx);//�����ض�����������ʼ�����������ʱ�򣬱������ᷢ���Ż�(���⼴�ٵ���һ���������캯��)
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
public://��ʼ����˳������class�ĳ�Ա����˳��һ�µģ��������Գ�ʼ���б������˳��Ϊ׼��
	X5(int val) :_j(val), _i(_j){}//ps:�������
};
class X51{
	int _i; int _j; double d; string s;
public://��ʼ���б�Ĵ���ᰲ�����κ�explicit user code֮ǰ
	X51(int val) :_j(val){ _i = _j; }//ps:��ȷ����
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
int X7::xxxx;//��̬��Ա������ע�⣬��������������������û�������ҵ�����Ȼ�����Ҳ��������������Ĵ��ڣ�
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
	static int xxx;//��̬�ֲ�����
	cout << xxx << " ";
}
int xxl;//ȫ�ֱ���
int xxll = 11;//ȫ�ֱ���
static int xxl5/* = 5*/;//��̬ȫ�ֱ���

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
	cout << ("&Point3d::x = ") << (&Point3d::x) << endl;//���������ƺ��е�����
	cout << ("&Point3d::y = ") << (&Point3d::y) << endl;
	cout << ("&Point3d::z = ") << (&Point3d::z) << endl;
	float Point3d::*p1 = 0;//û��ָ���κ�data member��ָ��
	float Point3d::*p2 = &Point3d::x;//ָ���һ��data member��ָ��
	float Point3d::*p3 = &Point3d::y;
	printf("ָ�� = %p\n&Point3d::x = %p\n&Point3d::y = %p\n", p1, p2, p3);
	cout << ("&Point3d::x = ") << p1 << endl;//������������
	cout << ("&Point3d::y = ") << p2 << endl;
	cout << ("&Point3d::z = ") <<p3 << endl;

	//printf("%p\n", &Point3d::_i);//���������ﲻӦ�ó����
	printf("%p\n", &_i);//���Ȼ����ֱ�ӵõ���̬��Ա�ĵ�ַ

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

class x10{//û���麯��
	int _i = 1;
};
class x101{//���麯��
	int _i = 2;
public:
	virtual void f(){}
};
class x103{//���麯��
	int _i = 5;
//public:
//	virtual void f(){}
};
class x102 :public x10, public x101,public x103{//����һ������ȼ̳�x10,�ټ̳�x101
	int _i = 3;//��������������£������������������̳�˳��
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
		f3();//�Ǿ�̬��Ա�����������þ�̬��Ա����
	}
	virtual void f2()
	{
		int n = 10000000;
		while (n--)
			x11::f1();//���������ڣ��ƺ��е㲻��
	}
	static void f3()
	{
		//f1();//��//��̬��Ա�������������÷Ǿ�̬��Ա����
		//x11::f1();//��

		//��c++�����е�nonstatic member function�����뾭�ɸ�class��object�����á�---c++����ģ��p149ԭ��
		//�ھ�̬��Ա�ڵ��÷Ǿ�̬��Ա֮���Ի������ʵ��ԭ���ǲ�����ƥ��(�ٴ���һ��thisָ��)
		//��thisָ���"��member function�д�ȡ��nonstatic class members"����"object�ڶ�Ӧ��members"֮��
		//  ���û���κ�һ��members��ֱ�Ӵ�ȡ����ʵ�ϲ���Ҫthisָ�룬������ʱ��thisָ��Ϊ����ȥ���ó�Ա����
		//  �������
		x11::f4();
	}
private:
	static void f4(){}
};
#include<time.h>
void test11()
{
	//((x11*)0)->f1();//��ͨ������ȥ���ó�Ա�����㣬(ע�⣬ֻҪ�����ʸ÷Ƿ���ַ�����ܳɹ�����)
	x11 x;
	x11 *px = &x;
	//clock_t t;
	//t = clock();
	//x.f2();
	//t = clock() - t;
	//cout << t << endl;
	x.f3();//�ٿ���ͨ��������ȥ���þ�̬��Ա������ע�⣬��Ȼ�����������ã���������ʾ�ú��������������
	px->f3();
	x11::f3();//�ڿ���ͨ������ֱ�ӵ��þ�̬��Ա����

	cout << &x11::f3 << endl;//�ԣ���ȡ��̬��Ա�����ĵ�ַ
	//cout << &x.f1 << endl;//����ȡnonstatic member function�ĵ�ַ
	//cout << &x.f2 << endl;//����ȡvirtual function�ĵ�ַ

	//x11::f2();//�ٷǾ�̬��Ա�����ñ������ض��Ķ������
	//x::f2();//��������::ǰ�������һ�����������������ռ�
	//x11::f4();//��̬��Ա����Ҳ��Ȩ����Լ(˽�о�̬��Ա����ֻ��ͨ����ĳ�Ա����������Ԫ��������)
}

class x12{
public:
	virtual void f1(){ cout << "f1" << endl; }
	virtual void f2(){ cout << "f2" << endl; }
	virtual void f3(){ cout << "f3" << endl; }
	virtual void f4(){ int i = 9; while (i--); cout << "f4" << endl; }

};
//ע�⣬��̬��ֻ��ͨ��ָ������õ����麯��ʱ�Żᷢ�������һ����ͨ��������麯����
//         ��ô�������ڱ���ʱ�ͻὫ���õİ汾ȷ������
void test12()
{
	typedef void(*v_fun)();//������ָ������ȡ����
	x12 x;
	int *vtable = (int*)(*(int*)&x);//��ַ����Ҫ�����Ͳ���Ҫ
	printf("�麯����%p\n", vtable);
	for (size_t i = 0; vtable[i] != 0; ++i)
	{
		printf("vfun[%d]:%p->", i, vtable[i]);
		v_fun f = (v_fun)vtable[i];//f�Ǻ���ָ�������������洢�ź����ĵ�ֵַ(�����Խ��еĲ���:& () *)
		//f();//��������                //�о����е�ָ����������Խ���ȡ��ַ&�ͽ�����*�Ļ�������
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
	int _i = 3;//ÿһ��classֻ��һ��������virtual table(���ཫ�������virtual table����һ��ע�ⲻ�Ǽ򵥵�����һ���)
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
	//p2->f2();//�ڶ���base��ָ�����derived���麯������������Ҫ����ָ�룩
	//p0->f2();//derived��ָ����õڶ���base���麯������������Ҫ����ָ�룩

	typedef void(*v_fun)();//������ָ������ȡ����
	int *vtable = (int*)(*(int*)p0);//��ַ����Ҫ�����Ͳ���Ҫ
	printf("�麯����%p\n", vtable);
	for (size_t i = 0; vtable[i] != 0; ++i)
	{
		if (i == 1)continue;
		printf("vfun[%d]:%p->", i, vtable[i]);
		v_fun f = (v_fun)vtable[i];//f�Ǻ���ָ�������������洢�ź����ĵ�ֵַ(�����Խ��еĲ���:& () *)
		f();//��������                //�о����е�ָ����������Խ���ȡ��ַ&�ͽ�����*�Ļ�������
		//cout << *f << endl;
	}
	cout << "hah";
}

class Abstract_base{//���麯������ӵ�о���ʵ���������ܶ������
public:
	virtual ~Abstract_base() {}/*= 0;*/ //�ڼ̳���ϵ����ð�������������Ϊ�麯�������ǲ����Ǵ��麯��
	virtual void f1()/*const */= 0;   //��ò�Ҫ���const����
	/*virtual */const char* mumber()const{ return _mumber; }//ԭ���Ͳ���Ҫ��Ϊ�麯������ò�Ҫvirtual��������ر������ĸ���
	void f2(){ cout << "it is ok!"; }
protected:
	Abstract_base(char *pc = NULL) :_mumber(pc){}//����һ����Ψһ������constructor
	char *_mumber;
};
void test14()
{
	//Abstract_base::mumber();//���Ǿ�̬��Ա�������ض��Ķ������
	Abstract_base *p = NULL;
	p->f2();//ֻҪ���漰��������󣬸õ��þͻ�ɹ�
}

class AA15{
	int i;
};
typedef struct{
	float x, y, z;
	AA15 a;
}point;
point global;                 //global�ڴ�����
void test15()
{
	point local;                  //local �ڴ�����
	point *heap = new point;     //heap�ڴ�����
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
	//x161 x2;//��һ�̳���
	//cout << endl;
	//x162 x3;
	//x164 x4;//����̳���
	x16 x;//�����ڹ��캯���е��ø�class�����⺯����ע�⣬���캯��һ������Ϊ���⺯����
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
		//�����Ȳ���virtual base class constructors
		//�ڴ����Ȳ���base class constructors
		//��Ȼ�����Ϊvirtual table pointer��ʼ���Ĵ���
		//����Ȼ�������ݳ�Ա����˳�������룬�����������Ա����ô�������Ķ�Ӧ���캯�����ɣ�
		cout << "x17()" << endl;//��ִ�иù��캯���ĺ�����
		f1();
		//������ʼ��thisָ��(���ں������������һ�������Ĵ��룺return this)
	}
	//�����Ϸ��֣���Ȼ���캯���������麯�������ǿ����ڹ��캯����������麯����ע�⣬�ڹ��캯����������麯��
	//�Ǹ����õĲ�������Ϊ��������ݳ�Ա�����ں��������¸�ֵ�����麯���ڸ�ֵ���֮ǰ�Ҹ��麯�����õ����ݳ�Ա��
	//�ڼ���Ҫ�ڹ��캯����������麯�����������Ҹ����ݳ�Ա��ֵ�ɹ����ٵ����麯����û�в���
	virtual void f1()
	{
		cout << x2._i2 << endl;
	}
	x17(const x17& x) : x2(x.x2), x171(x), x172(x)
	{ 
		//�����Ȳ���virtual base class constructors(ע�⣬�����ʼ���б���ÿ������캯������ô����Ͳ���virtual base class copy constructors)
		//�ڴ����Ȳ���base class constructors(ע�⣬�����ʼ���б���ÿ������캯������ô����Ͳ���base class copy constructors)
		//��Ȼ�����Ϊvirtual table pointer��ʼ���Ĵ���
		cout << "x17(const x17& x)" << endl; //��ִ�иÿ������캯���ĺ�����

		//����󷵻س�ʼ����thisָ��(���ں������������һ�������Ĵ��룺return this)
	}
	~x17(){cout << "~x17()" << endl;}//������Ҫ��������
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
	//x18 x;//��������麯������̬����
	x181 *p = new x18;
	p->f1(); cout << endl;    p->f2();
}


void test_draft6()
{
	//test1();
	//test2();//default constructorʲôʱ����nontrivial (�����о�����Ĭ�Ϲ��캯�������õ��������)
	//�����һ����û���κ�constructor,�����ں�һ����Ա���󣬶��ó�Ա������default constructor
	//�����һ��û���κ�consstructor����������һ������default constructor��base class
	//�۴���һ��virtual function����
	//�ܴ���һ��virtual base class����
	//�ݸ����һ�����ݳ�Ա����Ĭ�ϳ�ʼֵ��c++11�����Ժ�
	//test21();//default copy constructorʲôʱ����nontrivial(�������о�����Ĭ�Ͽ������캯�����õ��������)
	//test3();
	//test4();//�ڵ��ÿ������캯��ʱ��������������Ż���
	//test5();//��ʼ���б���������ڽ��г�ʼ��
	//test6();//��class�Ĵ�С
	//test7();//argument list�е����ƾ������
	////��̬��Ա��������̬ȫ�ֱ�������̬�ֲ�������ȫ�ֱ�������������û�г�ʼ������ôĬ�ϳ�ʼ��Ϊ��
	//cout << xxl << " " << xxll << " " << xxl5 << endl;
	//test8();//ָ��data members��ָ�루���кܶ��Ի�ĵط���
	//test9();
	//test10(); //�����������������̳�˳��
	//test11();//��̬��Ա����
	//test12();//��ӡ�麯����
	//test13();//���ؼ̳��£�derived�����������ݳ�Ա�ķֲ�
	//test14();//��ι淶�����һ�����麯��
	//test15();//c++������ȫ�ֶ��󶼱���"��ʼ����������"���Դ�
	//test16();//��Ϊ�ײ���࣬���Լ������ν������ʼ�������������Լ���һ�׻��ƣ�
	//test17();//���캯���в�������ش���
	test18();//�麯��������÷��麯�����������ڹ��캯����������麯���Ǿ�̬������𣿣���
}