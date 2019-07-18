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
	//①先将字符串前面的空行符都处理掉
	for (sc = s; isspace(*sc); ++sc);
	sign = *sc == '-' || *sc == '+' ? *sc++ : '+';//处理有无正负号问题
	if (!*sc)return 0;//防空串和无效串

	//②考虑字符串代表几进制的数，然后通通都转换成十进制数
	//（base合法的情况下：base == 0(可以是8,10,16进制数)；2<=base<=36(可分为16和其他进制)）
	 if (base >= 2 && base <= 36)
	{
		if (base == 16 && *sc == '0'   //2<=base<=36(可分为16和其他进制)
			&& (sc[1] == 'x' || sc[1] == 'X'))
			sc += 2;
	}
	 else if (base == 0)//base == 0(可以是8, 10, 16进制数)
	 {
	  if (*sc != '0')
		 base = 10;
	 else if (sc[1] == 'x' || sc[1] == 'X')
		 base = 16, sc += 2;
	 else
		 base = 8;
	 }
	//③去除字符串前面多余的零
	for (; *sc == '0'; ++sc);
	//④真正开始将对应有效的字符转换成n进制数
	x = 0;
	for (; (sd = my_memchr(digits, tolower(*sc), base)) != NULL; ++sc)
	{
		y = x;
		x = x*base + (sd - digits);
		if (y != x / base){ x = y; break; }//防溢出
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
void test1()//        "[       ][+/-/ ] [0x/0/ ] [0000][有效字符串]\0"（方框代表里面的东西可能不存在）
{           //         n个空格  符号位  默认进制 无效零 有效字符串
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
	//操作符new做两件事：①调用operator new()分配空间②调用构造函数
	AA *p1 = new AA;//这里的new是c++的操作符
	cout << p1->_a << endl;
	//操作符delete做两件事：①调用析构函数②调用operator delete()释放空间
	delete p1;//这里的delete是c++的操作符
	cout << endl;

	AA *p2 = (AA*)operator new(sizeof(AA));//operator new(),分配空间
	cout << p2->_a << endl;
	new(p2)AA;//定位new,显式调用构造函数
	cout << p2->_a << endl;
	p2->~AA();//显式调用析构函数
	operator delete(p2);//定位delete,显式调用析构函数
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
int i7;//未初始化的全局变量
int i71 = 10;//初始化的全局变量
static int i73;//未初始化的全局静态变量
static int i74 = 10;///初始化的全局静态变量
void Test7()
{
	int i75 = 10;//局部变量
	static int i76;//未初始化的局部静态变量
	cout << i7 << endl;
	cout << i71 << endl;
	cout << i73 << endl;
	cout << i74 << endl;
	cout << i75 << endl;
	cout << i76 << endl;



	//char *p = (char*)alloca(5);//在栈上动态申请空间
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
	////const volatile int i = 10;//printf输出结果是5
	//const int i = 10;//printf输出结果是10（导致错误的原因就是编译器优化）
	////i = 9;出错，i只是一个只读变量，不允许修改
	//int *p = (int *)&i;//const修饰变量，只是告诉编译器不能修改这个变量，（强行取到i所在的地址，然后修改内容）
	//*p = 5;
	//printf("%d\n", i);

	en s;
	printf("%d\n%d\n", a, sizeof(s));//0 4
	printf("结构体大小%d\n", sizeof(ss));

	int a = 1;
	sizeof(++a);//sizeof括号内的表达式只进行计算，并不改变原始的值
	printf("%d\n", a);//1
}

//浅谈C语言中的位段
//位段(bit - field)是以位为单位来定义结构体(或联合体)中的成员变量所占的空间。含有位段的结构体(联合体)称为位段结构。采用位段结构既能够节省空间，又方便于操作。
//位段的定义格式为 :
//type[var] : digits
//其中type只能为int，unsigned int，signed int三种类型(int型能不能表示负数视编译器而定，比如VC中int就默认是signed int，能够表示负数)。位段名称var是可选参数，即可以省略。digits表示该位段所占的二进制位数。
//那么定义一个位段结构可以像下面这段代码去定义：
//struct node
//{
//	unsigned int a : 4;     //位段a，占4位
//	unsigned int : 0;     //无名位段，占0位
//	unsigned int b : 4;     //位段b，占4位
//	int c : 32;             //位段c，占32位
//	int : 6;              //无名位段，占6位
//};
//
//一.位段的使用
//使用位段需注意一下几点 :
//1)位段的类型只能是int，unsigned int，signed int三种类型，不能是char型或者浮点型；
//2)位段占的二进制位数不能超过该基本类型所能表示的最大位数，比如在VC中int是占4个字节，那么最多只能是32位；
//3)无名位段不能被访问，但是会占据空间；
//4)不能对位段进行取地址操作；
//5)若位段占的二进制位数为0，则这个位段必须是无名位段，下一个位段从下一个位段存储单元(这里的位段存储单元经测试在VC环境下是4个字节)开始存放；
//6)若位段出现在表达式中，则会自动进行整型升级，自动转换为int型或者unsigned int。
//7)对位段赋值时，最好不要超过位段所能表示的最大范围，否则可能会造成意想不到的结果。
//8)位段不能出现数组的形式。
//
//二.位段结构在内存中的存储方式
//对于位段结构，编译器会自动进行存储空间的优化，主要有这几条原则 :
//
//1)如果一个位段存储单元能够存储得下位段结构中的所有成员，那么位段结构中的所有成员只能放在一个位段存储单元中，不能放在两个位段存储单元中；如果一个位段存储单元不能容纳下位段结构中的所有成员，那么从剩余的位段从下一个位段存储单元开始存放。(在VC中位段存储单元的大小是4字节).
//2)如果一个位段结构中只有一个占有0位的无名位段，则只占1或0字节的空间(C语言中是占0字节，而C++中占1字节)；否则其他任何情况下，一个位段结构所占的空间至少是一个位段存储单元的大小；
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
	if (u.ch == 1)printf("小端\n");//小端：低位序放在低地址，高位序放在高地址
	else printf("大端\n");         //大端：低位序放在高地址，高位序放在低地址

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

	char *(*ptr)[4];//ptr先与*结合，所以是一个指针；再与[]结合，说明指针指向一个数组，然后又与一个*结合，则说明该数组的元素是一个char指针。
	char *arr[4];
	arr[0] = "000";
	arr[1] = "111";
	arr[2] = "222";
	arr[3] = "333";
	ptr = &arr;

}
//int p; //这是一个普通的整型变量
//int *p; //首先从P 处开始,先与*结合,所以说明P 是一个指针,然后再与int 结合,说明指针所指向的内容的类型为int 型.
//          所以P是一个返回整型数据的指针
//int p[3]; //首先从P 处开始,先与[]结合,说明P 是一个数组,然后与int 结合,说明数组里的元素是整型的,
//           所以P 是一个由整型数据组成的数组
//int *p[3]; //首先从P 处开始,先与[]结合,因为其优先级比*高,所以P 是一个数组,然后再与*结合,
//             说明数组里的元素是指针类型,然后再与int 结合,说明指针所指向的内容的类型是整型的,
//             所以P 是一个由返回整型数据的指针所组成的数组
//int(*p)[3]; //首先从P 处开始,先与*结合,说明P 是一个指针然后再与[]结合(与"()"这步可以忽略,只是为了改变优先级),
//             说明指针所指向的内容是一个数组,然后再与int 结合,说明数组里的元素是整型的.
//             所以P是一个指向由整型数据组成的数组的指针
//int **p; //首先从P 开始,先与*结合,说是P 是一个指针,然后再与*结合,说明指针所指向的元素是指针,
//           然后再与int 结合,说明该指针所指向的元素是整型数据.由于二级指针以及更高级的指针极少
//            用在复杂的类型中,所以后面更复杂的类型我们就不考虑多级指针了,最多只考虑一级指针.
//int p(int); //从P 处起,先与()结合,说明P 是一个函数,然后进入()里分析,说明该函数有一个整型变量的参数,
//             然后再与外面的int 结合,说明函数的返回值是一个整型数据
//int(*p)(int); //从P 处开始,先与指针结合,说明P 是一个指针,然后与()结合,说明指针指向的是一个函数,
//               然后再与()里的int 结合,说明函数有一个int 型的参数,再与最外层的int结合,
//               说明函数的返回类型是整型,所以P 是一个指向有一个整型参数且返回类型为整型的函数的指针
//int *(*p(int))[3]; //可以先跳过,不看这个类型,过于复杂从P 开始,先与()结合,说明P 是一个函数,
//                  然后进入()里面,与int 结合,说明函数有一个整型变量参数,然后再与外面的*结合,
//                说明函数返回的是一个指针,然后到最外面一层,先与[]结合,说明返回的指针指向的是一个数组,
//                然后再与*结合,说明数组里的元素是指针,然后再与int 结合,说明指针指向的内容是整型数据.
//               所以P 是一个参数为一个整数据且返回一个指向由整型指针变量组成的数组的指针变量的函数.

void Test13()//注意点，++,--是有副作用的
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



/*该实现使用大容量的静态数组作为堆，但也可使用操作系统调用分配堆。
定义了一个数据类型Header保存每个存储器块的簿记信息，
定义了具有Header类型元素的堆数组，这样就可以很容易地将簿记信息保存在存储器块中。
类型Header包含了3块信息：指向列表的下一个块的指针，
当前分配空间的长度，后面的自由空间的长度。另外，类型Header的定义还使用了一个union声明和Align数据类型，
这是将存储器元素排在合理的字节边界上，根据系统的不同，这有时是需要的，有时是不需要的。

在malloc函数中，当申请空间时，至少要分配两个Header元素节点，有什么原因吗？
当然有，因为每个空间块都包含两部分：空间头和空间体。空间头是为维护堆而设计的，
说到底就是维护已用空间链表，为搜索空闲空间和释放已用空间服务。空间体是供用户读写的
，当malloc函数返回给用户一个指针时，用户就可以设定自己的规格，比如强制转换成int或double类型，
接下来就可以按照这种规格进行读写了。需要注意一点，空间头是不能被用户访问的，它是用来维护堆的，
不是为用户服务的，所以malloc函数返回的指针是指向空间体的，而不是指向空间头的，理所当然free函数得到的指针也是指向空间体的。
可是为了释放空间，free函数需要得到该空间的空间头信息，所以实现时需要把指针调整一下，改为指向空间头，此情形下，
加一即可。另外一点，空间头和空间体同为Header类型，用union声明再合适不过。下面就是malloc函数和free函数的实现代码：
*/
#define NULL 0
#define MEMSIZE 8096
typedef double Align;
typedef union header
{
	struct {
		union header* next;
		unsigned usedsize;//这里标记的是已使用的空间块的个数
		unsigned freesize;//未使用的个数
	}s;
	Align a;
}Header;
static Header mem[MEMSIZE];
static Header* memptr = NULL; //memptr始终指向系统最新分配空间的首地址或最新释放空间的前一个分配空间的首地址
void* Malloc(unsigned nbytes)
{
	Header *p, *newp;
	unsigned nunits;
	nunits = (nbytes + sizeof(Header)-1) / sizeof(Header)+1;//计算需要分配多少个header
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
	bp = (Header*)ap - 1;//要释放的是bp指向的空间块
	for (prev = memptr, p = memptr->s.next;
		(p != bp) && (p != memptr); prev = p, p = p->s.next);//用prev和p循环遍历的目的是使其他正在使用的空间块能连起来
	if (p != bp) return;
	prev->s.freesize += p->s.usedsize + p->s.freesize;
	prev->s.next = p->s.next;
	memptr = prev;
}
void Test16()
{
	printf("%p\n", mem);//打印静态数组的首地址
	printf("%d\n", sizeof(Header));
	void *p1 = Malloc(10);
	void *p2 = Malloc(20);
	Free(p2);
}

void test_draft7()
{
	//test1();//atoi
	////        "[       ][+/-/ ] [0x/0/ ] [0000][有效字符串]\0"（方框代表里面的东西可能不存在）
	////         n个空格  符号位  默认进制 无效零 有效字符串
	//test2();//atof
	//test3();
	//test4();//静态成员变量受private的影响
	//test5();//operator new()与operator delete()
	//test61();//如何把类型做参数传进去
	//Test7();
	//Test8();
	//Tset9();
	//Test10();
	//Test11();//位段
	//Test12();//辨别指针
	//Test13();//经典的指针题

	//test14();
	//p15 pp = NULL;
	//Test15(pp);
	//Test16();//malloc/free的设计思想 *********
}

