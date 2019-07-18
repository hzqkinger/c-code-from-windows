#pragma once


static const char digits[] = { "0123456789abcdefghijklmnopqrstuvwxyz" };
char *my_memchr(const char *buf, char ch, size_t size)
{
	char *tmp = (char*)buf;
	if (*(tmp + size - 1) < ch || ch == '\0')
		return NULL;
	if (ch >= '0' && ch <= '9')
		tmp += ch - '0';
	else if (ch >= 'a'&&ch <= 'z')
		tmp += ch - 'a' + 10;
	return tmp;

}
unsigned long int my_strtoul(const char *s,int base)
{                       //"    000125a45"  "    0x45agrt5h"  "   -2543ag5"   
	const char *sc, *sd;
	char sign;
	unsigned long x, y;
	//���Ƚ��ַ���ǰ��Ŀ��з��������
	for (sc = s; isspace(*sc); ++sc);
	sign = *sc == '-' || *sc == '+' ? *sc++ : '+';//������������������
	if (!*sc)return 0;//���մ�����Ч��

	//�ڿ����ַ����������Ƶ�����Ȼ��ͨͨ��ת����ʮ������
	//��base�Ϸ�������£�base == 0(������8,10,16������)��2<=base<=36(�ɷ�Ϊ16����������)��
	 if (base >= 2 && base <= 36)
	{
		if (base == 16 && *sc == '0'   //2<=base<=36(�ɷ�Ϊ16����������)
			&& (sc[1] == 'x' || sc[1] == 'X'))
			sc += 2;
	}
	 else if (base == 0)//base == 0(������8, 10, 16������)
	 {
	  if (*sc != '0')
		 base = 10;
	 else if (sc[1] == 'x' || sc[1] == 'X')
		 base = 16, sc += 2;
	 else
		 base = 8;
	 }
	//��ȥ���ַ���ǰ��������
	for (; *sc == '0'; ++sc);
	//��������ʼ����Ӧ��Ч���ַ�ת����n������
	x = 0;
	for (; (sd = my_memchr(digits, tolower(*sc), base)) != NULL; ++sc)
	{
		y = x;
		x = x*base + (sd - digits);
		if (y != x / base){ x = y; break; }//�����
	}
	return x;
}
int my_atoi2(const char *s)
{
	return (int)my_strtoul(s, 10);
}
long my_atol2(const char *s)
{
	return (long)my_strtoul(s, 10);
}
long int my_strtol(const char *nptr, int base)
{
	return (long int)my_strtoul(nptr, base);
}
void test1()//        "[       ][+/-/ ] [0x/0/ ] [0000][��Ч�ַ���]\0"�������������Ķ������ܲ����ڣ�
{           //         n���ո�  ����λ  Ĭ�Ͻ��� ��Ч�� ��Ч�ַ���
	const char* str = " -00095";
	cout << my_atoi2(str) << endl;
	cout << atoi(str) << endl;
}

void test2()
{
	cout << atof("   -000025E-001000005 ") << endl;
}

void test3()
{
	int i = 10;
	int i2 = 10;
	int i3 = 10;
	printf("%d %d %d\n", i++, i++, i++);
	printf("%d %d %d\n", ++i2, ++i2, ++i2);
	printf("%d %d %d\n", ++i3, i3++, ++i3);
}

class y123456u{
private:
	static int i;
public:
	static int j;
	void print()
	{
		cout << i << endl;
		cout << j << endl;
	}
};
int y123456u::i = 0;
int y123456u::j = 1;
void test4()
{
	y123456u y;
	y.print();
	//cout << y.i << endl;
	cout << y.j << endl;
}

struct AA
{
	int _a;
	AA(int a = 3) :_a(a){}
	~AA(){ cout << "~AA()" << endl; }
};
void test5()
{
	//������new�������£��ٵ���operator new()����ռ�ڵ��ù��캯��
	AA *p1 = new AA;//�����new��c++�Ĳ�����
	cout << p1->_a << endl;
	//������delete�������£��ٵ������������ڵ���operator delete()�ͷſռ�
	delete p1;//�����delete��c++�Ĳ�����
	cout << endl;

	AA *p2 = (AA*)operator new(sizeof(AA));//operator new(),����ռ�
	cout << p2->_a << endl;
	new(p2)AA;//��λnew,��ʽ���ù��캯��
	cout << p2->_a << endl;
	p2->~AA();//��ʽ������������
	operator delete(p2);//��λdelete,��ʽ������������
}

template<class T>
void Test6(size_t size, T*)
{
	cout << size*sizeof(T) << endl;
}
void test61()
{
	Test6(5, (double*)0);
}

#include<stdlib.h>
int i7;//δ��ʼ����ȫ�ֱ���
int i71 = 10;//��ʼ����ȫ�ֱ���
static int i73;//δ��ʼ����ȫ�־�̬����
static int i74 = 10;///��ʼ����ȫ�־�̬����
void Test7()
{
	int i75 = 10;//�ֲ�����
	static int i76;//δ��ʼ���ľֲ���̬����
	cout << i7 << endl;
	cout << i71 << endl;
	cout << i73 << endl;
	cout << i74 << endl;
	cout << i75 << endl;
	cout << i76 << endl;



	//char *p = (char*)alloca(5);//��ջ�϶�̬����ռ�
	//printf("%p\n", p);

	//char ch = 'a';
	//printf("%p\n", &ch);

	//char *p2 = (char*)malloc(5);
	//printf("%p\n", p2);
}

typedef const int cint;
#include<string>
#include<vector>
void Test8()
{
	string *ps = new string[2];
	cout << *(ps+1) << endl;

	cint i = 10;
	//i = 3;
	vector<int>::const_iterator it;
}


template<class T>
struct AA9
{
	T _val;
	void fun1(){ cout << "first" << endl; }
	T& operator++()
	{
		++_val;
		cout << "first   operator++()" << endl;
		return _val;
	}
};
template<class T2>
struct AA92 :AA9<T2>
{

	void fun2(){ cout << "second" << endl; }
};
void Tset9()
{
	AA9<int> obj;
	obj._val = 9;

	AA92<string> obj2;
	obj2.fun1();
	obj2.fun2();
	
}

enum en
{
	a,
	b,
	c,
	d,
	e
};
struct ss{
	int a;
	int b;
	enum en e;
};
void Test10()
{
	////const volatile int i = 10;//printf��������5
	//const int i = 10;//printf��������10�����´����ԭ����Ǳ������Ż���
	////i = 9;����iֻ��һ��ֻ���������������޸�
	//int *p = (int *)&i;//const���α�����ֻ�Ǹ��߱����������޸������������ǿ��ȡ��i���ڵĵ�ַ��Ȼ���޸����ݣ�
	//*p = 5;
	//printf("%d\n", i);

	en s;
	printf("%d\n%d\n", a, sizeof(s));//0 4
	printf("�ṹ���С%d\n", sizeof(ss));

	int a = 1;
	sizeof(++a);//sizeof�����ڵı��ʽֻ���м��㣬�����ı�ԭʼ��ֵ
	printf("%d\n", a);//1
}

//ǳ̸C�����е�λ��
//λ��(bit - field)����λΪ��λ������ṹ��(��������)�еĳ�Ա������ռ�Ŀռ䡣����λ�εĽṹ��(������)��Ϊλ�νṹ������λ�νṹ���ܹ���ʡ�ռ䣬�ַ����ڲ�����
//λ�εĶ����ʽΪ :
//type[var] : digits
//����typeֻ��Ϊint��unsigned int��signed int��������(int���ܲ��ܱ�ʾ�����ӱ���������������VC��int��Ĭ����signed int���ܹ���ʾ����)��λ������var�ǿ�ѡ������������ʡ�ԡ�digits��ʾ��λ����ռ�Ķ�����λ����
//��ô����һ��λ�νṹ������������δ���ȥ���壺
//struct node
//{
//	unsigned int a : 4;     //λ��a��ռ4λ
//	unsigned int : 0;     //����λ�Σ�ռ0λ
//	unsigned int b : 4;     //λ��b��ռ4λ
//	int c : 32;             //λ��c��ռ32λ
//	int : 6;              //����λ�Σ�ռ6λ
//};
//
//һ.λ�ε�ʹ��
//ʹ��λ����ע��һ�¼��� :
//1)λ�ε�����ֻ����int��unsigned int��signed int�������ͣ�������char�ͻ��߸����ͣ�
//2)λ��ռ�Ķ�����λ�����ܳ����û����������ܱ�ʾ�����λ����������VC��int��ռ4���ֽڣ���ô���ֻ����32λ��
//3)����λ�β��ܱ����ʣ����ǻ�ռ�ݿռ䣻
//4)���ܶ�λ�ν���ȡ��ַ������
//5)��λ��ռ�Ķ�����λ��Ϊ0�������λ�α���������λ�Σ���һ��λ�δ���һ��λ�δ洢��Ԫ(�����λ�δ洢��Ԫ��������VC��������4���ֽ�)��ʼ��ţ�
//6)��λ�γ����ڱ��ʽ�У�����Զ����������������Զ�ת��Ϊint�ͻ���unsigned int��
//7)��λ�θ�ֵʱ����ò�Ҫ����λ�����ܱ�ʾ�����Χ��������ܻ�������벻���Ľ����
//8)λ�β��ܳ����������ʽ��
//
//��.λ�νṹ���ڴ��еĴ洢��ʽ
//����λ�νṹ�����������Զ����д洢�ռ���Ż�����Ҫ���⼸��ԭ�� :
//
//1)���һ��λ�δ洢��Ԫ�ܹ��洢����λ�νṹ�е����г�Ա����ôλ�νṹ�е����г�Աֻ�ܷ���һ��λ�δ洢��Ԫ�У����ܷ�������λ�δ洢��Ԫ�У����һ��λ�δ洢��Ԫ����������λ�νṹ�е����г�Ա����ô��ʣ���λ�δ���һ��λ�δ洢��Ԫ��ʼ��š�(��VC��λ�δ洢��Ԫ�Ĵ�С��4�ֽ�).
//2)���һ��λ�νṹ��ֻ��һ��ռ��0λ������λ�Σ���ֻռ1��0�ֽڵĿռ�(C��������ռ0�ֽڣ���C++��ռ1�ֽ�)�����������κ�����£�һ��λ�νṹ��ռ�Ŀռ�������һ��λ�δ洢��Ԫ�Ĵ�С��
struct my_bit
{
	//unsigned short _a : 4;
	////unsigned int _b : 5;
	//unsigned short _b : 5;

	unsigned short _c : 5;
	unsigned short _d : 13;
};
union un
{
	int i;
	char ch;
};
struct ss11
{
	char ch;
	int a;
};
void Test11()
{
	union un u;u.i = 1;
	if (u.ch == 1)printf("С��\n");//С�ˣ���λ����ڵ͵�ַ����λ����ڸߵ�ַ
	else printf("���\n");         //��ˣ���λ����ڸߵ�ַ����λ����ڵ͵�ַ

	struct my_bit i;
	memset(&i, 0, sizeof(i));
	//i._a = 13; i._b = 1; /*i._c = 1; i._d = 1;*/
	i._c = 13; i._d = 1;
	printf("%d\n", sizeof(i));

	//long long it = *(long long*)(&i);
	//printf("%lld\n", it);

	int it = *(int*)(&i);
	printf("%d\n", it);
}

void Function()
{
	printf("call function\n");
}
void Test12()
{
	void(*p)();
	p = Function;
	p();
	printf("%d\n", sizeof(p));

	char *(*ptr)[4];//ptr����*��ϣ�������һ��ָ�룻����[]��ϣ�˵��ָ��ָ��һ�����飬Ȼ������һ��*��ϣ���˵���������Ԫ����һ��charָ�롣
	char *arr[4];
	arr[0] = "000";
	arr[1] = "111";
	arr[2] = "222";
	arr[3] = "333";
	ptr = &arr;

}
//int p; //����һ����ͨ�����ͱ���
//int *p; //���ȴ�P ����ʼ,����*���,����˵��P ��һ��ָ��,Ȼ������int ���,˵��ָ����ָ������ݵ�����Ϊint ��.
//          ����P��һ�������������ݵ�ָ��
//int p[3]; //���ȴ�P ����ʼ,����[]���,˵��P ��һ������,Ȼ����int ���,˵���������Ԫ�������͵�,
//           ����P ��һ��������������ɵ�����
//int *p[3]; //���ȴ�P ����ʼ,����[]���,��Ϊ�����ȼ���*��,����P ��һ������,Ȼ������*���,
//             ˵���������Ԫ����ָ������,Ȼ������int ���,˵��ָ����ָ������ݵ����������͵�,
//             ����P ��һ���ɷ����������ݵ�ָ������ɵ�����
//int(*p)[3]; //���ȴ�P ����ʼ,����*���,˵��P ��һ��ָ��Ȼ������[]���(��"()"�ⲽ���Ժ���,ֻ��Ϊ�˸ı����ȼ�),
//             ˵��ָ����ָ���������һ������,Ȼ������int ���,˵���������Ԫ�������͵�.
//             ����P��һ��ָ��������������ɵ������ָ��
//int **p; //���ȴ�P ��ʼ,����*���,˵��P ��һ��ָ��,Ȼ������*���,˵��ָ����ָ���Ԫ����ָ��,
//           Ȼ������int ���,˵����ָ����ָ���Ԫ������������.���ڶ���ָ���Լ����߼���ָ�뼫��
//            ���ڸ��ӵ�������,���Ժ�������ӵ��������ǾͲ����Ƕ༶ָ����,���ֻ����һ��ָ��.
//int p(int); //��P ����,����()���,˵��P ��һ������,Ȼ�����()�����,˵���ú�����һ�����ͱ����Ĳ���,
//             Ȼ�����������int ���,˵�������ķ���ֵ��һ����������
//int(*p)(int); //��P ����ʼ,����ָ����,˵��P ��һ��ָ��,Ȼ����()���,˵��ָ��ָ�����һ������,
//               Ȼ������()���int ���,˵��������һ��int �͵Ĳ���,����������int���,
//               ˵�������ķ�������������,����P ��һ��ָ����һ�����Ͳ����ҷ�������Ϊ���͵ĺ�����ָ��
//int *(*p(int))[3]; //����������,�����������,���ڸ��Ӵ�P ��ʼ,����()���,˵��P ��һ������,
//                  Ȼ�����()����,��int ���,˵��������һ�����ͱ�������,Ȼ�����������*���,
//                ˵���������ص���һ��ָ��,Ȼ��������һ��,����[]���,˵�����ص�ָ��ָ�����һ������,
//                Ȼ������*���,˵���������Ԫ����ָ��,Ȼ������int ���,˵��ָ��ָ�����������������.
//               ����P ��һ������Ϊһ���������ҷ���һ��ָ��������ָ�������ɵ������ָ������ĺ���.

void Test13()//ע��㣬++,--���и����õ�
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char **cp[] = { c + 3, c + 2, c + 1, c };
	char ***cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
}

class Test14
{
public:
	Test14()
		:a(2){}

	void func1()const
	{
		cout << "void func1()const" << a << endl;
	}
	static void func2()
	{
		cout << "dtstic void func()" << endl;
	}
	void func3()
	{
		cout << "void func3()" << a << endl;
	}
private:
	int a;
};
void test14()
{
	const Test14 tt;
	tt.func1();
	tt.func2();
	//tt.func3();
}

void Test151(int num)
{
	cout << "void Test15(int num)" << num << endl;
}
typedef void(*p15)(int);
void Test15(p15 fun)
{
	fun = Test151;
	fun(5);
	cout << "++++++++++++++" << endl;
}



/*��ʵ��ʹ�ô������ľ�̬������Ϊ�ѣ���Ҳ��ʹ�ò���ϵͳ���÷���ѡ�
������һ����������Header����ÿ���洢����Ĳ�����Ϣ��
�����˾���Header����Ԫ�صĶ����飬�����Ϳ��Ժ����׵ؽ�������Ϣ�����ڴ洢�����С�
����Header������3����Ϣ��ָ���б����һ�����ָ�룬
��ǰ����ռ�ĳ��ȣ���������ɿռ�ĳ��ȡ����⣬����Header�Ķ��廹ʹ����һ��union������Align�������ͣ�
���ǽ��洢��Ԫ�����ں�����ֽڱ߽��ϣ�����ϵͳ�Ĳ�ͬ������ʱ����Ҫ�ģ���ʱ�ǲ���Ҫ�ġ�

��malloc�����У�������ռ�ʱ������Ҫ��������HeaderԪ�ؽڵ㣬��ʲôԭ����
��Ȼ�У���Ϊÿ���ռ�鶼���������֣��ռ�ͷ�Ϳռ��塣�ռ�ͷ��Ϊά���Ѷ���Ƶģ�
˵���׾���ά�����ÿռ�����Ϊ�������пռ���ͷ����ÿռ���񡣿ռ����ǹ��û���д��
����malloc�������ظ��û�һ��ָ��ʱ���û��Ϳ����趨�Լ��Ĺ�񣬱���ǿ��ת����int��double���ͣ�
�������Ϳ��԰������ֹ����ж�д�ˡ���Ҫע��һ�㣬�ռ�ͷ�ǲ��ܱ��û����ʵģ���������ά���ѵģ�
����Ϊ�û�����ģ�����malloc�������ص�ָ����ָ��ռ���ģ�������ָ��ռ�ͷ�ģ�������Ȼfree�����õ���ָ��Ҳ��ָ��ռ���ġ�
����Ϊ���ͷſռ䣬free������Ҫ�õ��ÿռ�Ŀռ�ͷ��Ϣ������ʵ��ʱ��Ҫ��ָ�����һ�£���Ϊָ��ռ�ͷ���������£�
��һ���ɡ�����һ�㣬�ռ�ͷ�Ϳռ���ͬΪHeader���ͣ���union�����ٺ��ʲ������������malloc������free������ʵ�ִ��룺
*/
#define NULL 0
#define MEMSIZE 8096
typedef double Align;
typedef union header
{
	struct {
		union header* next;
		unsigned usedsize;//�����ǵ�����ʹ�õĿռ��ĸ���
		unsigned freesize;//δʹ�õĸ���
	}s;
	Align a;
}Header;
static Header mem[MEMSIZE];
static Header* memptr = NULL; //memptrʼ��ָ��ϵͳ���·���ռ���׵�ַ�������ͷſռ��ǰһ������ռ���׵�ַ
void* Malloc(unsigned nbytes)
{
	Header *p, *newp;
	unsigned nunits;
	nunits = (nbytes + sizeof(Header)-1) / sizeof(Header)+1;//������Ҫ������ٸ�header
	if (memptr == NULL)
	{
		memptr->s.next = memptr = mem;
		memptr->s.usedsize = 1;
		memptr->s.freesize = MEMSIZE - 1;
	}
	for (p = memptr; (p->s.next != memptr) && (p->s.freesize<nunits); p = p->s.next);
	if (p->s.freesize<nunits) return NULL;
	newp = p + p->s.usedsize;
	newp->s.usedsize = nunits;
	newp->s.freesize = p->s.freesize - nunits;
	newp->s.next = p->s.next;
	p->s.freesize = 0;
	p->s.next = newp;
	memptr = newp;
	return (void*)(newp + 1);
}
void Free(void* ap)
{
	Header *bp, *p, *prev;
	bp = (Header*)ap - 1;//Ҫ�ͷŵ���bpָ��Ŀռ��
	for (prev = memptr, p = memptr->s.next;
		(p != bp) && (p != memptr); prev = p, p = p->s.next);//��prev��pѭ��������Ŀ����ʹ��������ʹ�õĿռ����������
	if (p != bp) return;
	prev->s.freesize += p->s.usedsize + p->s.freesize;
	prev->s.next = p->s.next;
	memptr = prev;
}
void Test16()
{
	printf("%p\n", mem);//��ӡ��̬������׵�ַ
	printf("%d\n", sizeof(Header));
	void *p1 = Malloc(10);
	void *p2 = Malloc(20);
	Free(p2);
}

void test_draft7()
{
	//test1();//atoi
	////        "[       ][+/-/ ] [0x/0/ ] [0000][��Ч�ַ���]\0"�������������Ķ������ܲ����ڣ�
	////         n���ո�  ����λ  Ĭ�Ͻ��� ��Ч�� ��Ч�ַ���
	//test2();//atof
	//test3();
	//test4();//��̬��Ա������private��Ӱ��
	//test5();//operator new()��operator delete()
	//test61();//��ΰ���������������ȥ
	//Test7();
	//Test8();
	//Tset9();
	//Test10();
	//Test11();//λ��
	//Test12();//���ָ��
	//Test13();//�����ָ����

	//test14();
	//p15 pp = NULL;
	//Test15(pp);
	//Test16();//malloc/free�����˼�� *********
}

