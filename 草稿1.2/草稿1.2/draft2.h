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
	typedef AA1 A1;//��AA�ı���A��ΪBB�ĳ�Ա
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
const T& Max2(const T& a, const T& b)//ģ�庯��
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
	//cout << Max(4.1, 8);//�����ﲻ��������Զ�����ת��������ÿ��T��������ȷ��ƥ��
	                      //�������һ��T�����ݳ�double���ڶ���T�����ݳ�int����һ��T��ƥ�䣬���Գ���
	cout << Max2(static_cast<int>(4.1), 8);//�����٣���ʵ�ν���ǿ������ת����ʹ�����໥ƥ��
	cout << Max2<double>(4.1, 8) << endl;//�����ڣ���ʽָ��T������
	                                   //�����ۣ��޸�ģ�����������������ģ�����
	double f = 5.55;
	const int &i1 = 6.11;
	//int &i = static_cast<int>(f);//�ǳ������õĳ�ʼֵ����Ϊ��ֵ
	const int &i = static_cast<int>(f);//�������õĳ�ʼ���ȿ�������ֵҲ��������ֵ
	cout << i << endl;

	func2(4.1, 8);//�ٲ���ʽָ�������κ�ģ��ʵ��
	func2<int, double>(4.1, 8);//����ʽָ�����к���ģ��ʵ��
	func2<int>(4.1, 8);//��ֻ��ʽ��ָ����һ��ģ��ʵ�Σ���������������������ģ��ʵ��
}

void test3()
{
	char str[10];
	//gets(str);//���ն�����ʱ��ֻ������<CRT>����str�Ľ���
	scanf("%s", str);//���ն�����ʱ������ո��<CRT>����str�Ľ���
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
		print4(++s);                 //�����ʱ���βκ�ʵ�ζ�����ƶ���һλ��
		//print4(s++);//��ѭ��
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
		//++s;//��ѭ��
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
	//�٢�����������Ĭ��ֵ�ķ�������C++11֮ǰ�ǲ�֧�ֵģ�ע�⣺���ã�
	int x1 = 1;//������Ǿ���Ĭ��ֵ�ĳ�Ա����
	const int x2 = 2;//��const��һ�㳣����������������Ĭ��ֵ����������ڹ��캯����ʼ���б���г�ʼ����

	static int x3 /*= 3*/;//�۾�̬�������������ڳ�ʼ�������Ҫ��ʼ���������������ʼ����

	const static int x4 /*= 4*/;//�ܳ���̬�������������ڡ������ʼ��������ֻ����һ����ʼ����
public:
	E6()
		:x1(10), x2(20)//���ڢ٢��к��������Ĭ��ֵ����������ʹ�ù��캯���ĳ�ʼ���б��ʼ����
	{
		x3 = 10;//��̬���������ڹ��캯���и�ֵ��ע�⣺���ﲻ�ǳ�ʼ����
	}
};
int E6::x3 = 30;//��̬���������������ʼ��
const int E6::x4 = 40;

void test7()
{
	int i = 0;
	int j = 1;

	const int *p1;//�ײ�ָ�룺������ָ�������ռ䣬�������������޸���ָ��ռ������
	p1 = &i;
	int *p2;
	p2 = &i;
	//int * const p3;//����ָ�룬������ָ�������κοռ䣬�����������޸���ָ��ռ������
	const int * const p4 = &i;
	p1 = &j;
	//*p1 = 20;

}

//va_start(arg,format),��ʼ������ָ��arg������������format�ұߵ�һ��������ַ��ֵ��arg  
//format������һ��������ָ�룬���ԣ��������ͺ�������Ҫ��һ����ͨ�Ĳ���,   
//�Ӷ��ṩ��va_start ,����va_start�����ҵ��ɱ������ջ�ϵ�λ�á�   
//va_arg(arg,char),���argָ�������ֵ��ͬʱʹargָ����һ������,char����ָ����ǰ������  
//va_end ����Щʵ���п��ܻ��arg�ĳ���Чֵ������ǰ�argָ��ָ���� NULL,�������Ұָ��   
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
	friend class pal10;//����pal10Ϊbased����Ԫ��
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
class derived10 :public base10//���м̳��£�������Է��ʸ�������з�˽�г�Ա
{
	friend class pal210;//����pal210Ϊdeprived10����Ԫ��
public:
	int f1()
	{
		return b;
	}
	friend int f2(derived10& d)//����Ԫ�������������ڶ��壨��Ԫ�����Ƿ���������ڶ��壬ȡ�������Ĳ����б��Ƿ��и������
	{
		return d.b;//��Ԫ��������ͨ��������󣬲������ø�������г�Ա��ע���Ǳ��룩
	}
	friend void f22()//����Ļ��е����⣬����Ԫ�������������ڶ��壬����Ҫ���������ã������������ٴ�����
	{
		cout << "789" << endl;
	}
	void func3()
	{
		cout << "base10:b = " << b << endl;
	}
	int d = 2;
	using base10::b;//��base10�ı������ݳ�Աb����Ϊdeprived10�Ĺ��г�Ա
	//using base10::b2;//˽�еĲ���������
protected:
	int d2 = 3;
private:
	int d3 = 4;
};
class pal210//derived����Ԫ��ֻ��ͨ������������derived�����г�Ա/base�Ĺ��г�Ա
{
	int f7(derived10 &d)
	{
		cout << d.b1 << endl;//����ı�����Ա
		cout << d.b << endl;//����Ĺ��г�Ա
		cout << d.d3 << endl;//�����˽�г�Ա
		return d.d2;
	}
	int f8(base10 &b)
	{
		//cout << b.b1 << endl;
		//cout << b.b << endl;
		cout << b.b3 << endl;//����Ĺ��г�Ա
		b.f0(b);
	}
};
class pal10//base����Ԫ��ֻ��ͨ������������base�����г�Ա/derived�Ĺ��г�Ա
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
	//�������Ԫ�������ܷ�����������κγ�Ա�����������Ԫ��������ͨ�����������������.��������ʻ���ķ�˽�г�Ա
	//�������Ԫ����Է��ʻ�������г�Ա��������ķ�˽�г�Ա�����������Ԫ����Է��ʻ���ķ�˽�г�Ա������������г�Ա
	//ע��㣺��Ԫ��������Ԫ�඼�����������Ǹ���ĳ�Ա��
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

void test11()//�����۵������������Ż���
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
		:A12(a)//����Ҫ��ʽ�ĵ���A1�Ŀ������죬������õľ���A1��Ĭ�Ϲ��캯��
	{
		cout << "B12(const B12& a)" << endl;
	}
	B12&operator=(const B12& b)//������ﲻ��ʽ�ĵ���A1�Ŀ�����ֵ��������������������A1�Ŀ�����ֵ����
	{
		A12::operator=(b);
		cout << "B12&operator=(const B12& a)" << endl;
		return *this;
	}
	~B12()//������ʽ���ã������ɱ������Զ�����
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
class A13             //��ģ������ A13��������A13<T>�����͡�
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
	A13& f1(const A13 & a1)//�����б��о�Ȼ����ֱ��������
	{
		_a11 += a1._a11;
		return *this;
	}
	void f2(A13 & a1);
private:
	T _a11;
};
template<class T2>//���涨���Ա�����������T2���Ը���������ֲ�һ��������ʵ����֮��T��T2����һ��
void A13<T2>::f2(A13 &a1)//�����б��о�Ȼ����ֱ��������
{
	cout << a1._a11 << endl;
}
void test13()
{
	A13<> aa(5);
	aa.f2(aa);
	aa.f1(aa);
	A13<int> bb[5];//��A<int>�����������������ͺ��ˣ�bb�������溬��5��A13<int>���͵�����Ԫ��
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
	virtual void f1()//�麯�����÷��麯��
	{cout << "A::F1()" << endl;
	    f2();
	}
	void f2()//���麯�������麯����ע��������������캯����������麯����
	{cout << "A::F2()" << endl;
		//f1();
	}
};
class B15 :public A15
{
public:
	//virtual void f1()//�麯�����÷��麯��
	//{cout << "B::F1()" << endl;
	//	f2();
	//}
	void f2()//���麯�������麯��
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
	friend AA16 *tess(AA16 *a)//��Ԫ�����Ƿ���������ڶ��壬ȡ�������Ĳ����б��Ƿ��и������
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
	~A17()//����������˽�л�����ι���һ��ֻ���ڶ��ϴ���������ࣩ
	{}
	public:
		A17() = default;//Ĭ�Ϲ��캯��
		A17(const A17& a)//�������캯��
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
	void f1()override//����override�����ĳ����������ú���û�и����Ѵ��ڵ��麯��������������
	{}
};
void test17()
{
	//A17 a;//����������˽�л������಻����ջ�ϴ�������ֻ���ڶ��ϴ�������
	A17 *p = new A17;
	A17 a(A17());//a���Ȼ����һ��A��Ķ�������ֻ��������һ��������������е�ģ����

}

class A18
{
	A18(int a = 1)//�����캯��˽�л�����ι���һ�����ᱻ�̳е��ࣩ
	:_a(a)
	{}
	int _a;
public:
	A18* Getobj1(int a)//��
	{
		return new A18(a);
	}
	A18 Getobj(int a)//��
	{
		return A18(a);
	}
	static A18 Getobj2(int a)//�ھ�̬��Ա����
	{
		return A18(a);
	}
	friend A18 func(int a);//����Ԫ
};
A18 func(int a)
{
	return A18(a);
}
void test18()
{
	A18 a1 = A18::Getobj2(5);//��
	A18 a2 = func(6);//��
	//A18 *ptr1 = A18::Getobj1(9);//�Ǿ�̬��Ա���ñ������ض��Ķ������
}

#define IBM_C19//�����Ȼ���ܱ����ȥ

char buffer20[6]/* = { 0 }*/;//����buffer20��ȫ�ֱ�������ʹ����ʽΪÿ��Ԫ�ظ���ʼֵ0���������Ԫ��Ҳ����0.
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
	//test0();//���ű��ʽ�Ͷ��ŷָ�����
	//test1();//typedef�����и��Զ�������ȡ����
	//test2();//����ģ��
	//test3();//scanf��gets�ıȽ�
	//test4();//�ݹ�
	//test5();//�����������
	//E6 e;//��ͨ���ݳ�Ա��const���ݳ�Ա��static���ݳ�Ա��const static���ݳ�Ա
	//test7();//����ָ��͵ײ�ָ��
	//test8();//�ɱ���б�
	//test9();//�ɱ��
	test10();//�̳к���Ԫ��
	//test11();//�����۵�
	//test12();//�̳к��ĸ�Ĭ�����ɺ���
	//test13();//ģ�����ж���ĺ����Ĳ��������;�Ȼ����ֱ������������
	//test14();//����ָ����һ��ָ��֮�䲻�ǵ����ĸ�ֵ�����ǽ��ܹ�����
	//test15();//�̳кͶ�̬
	//test16();//ɾ��thisָ�루��û�и㶮��
	//test17();//��������˽�л�����Щ�ط�ģ����
	//test18();//���캯��˽�л�
	//list<int> l;
	//list<int>::reverse_iterator rit = l.rbegin();
	//test20();//ȫ�ֱ����ĳ�ʼֵ
}