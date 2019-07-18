#pragma once
#include<string>
#include<vector>

template<class T>
class mytest0
{
public:
	T x;
public:
	mytest0()
		:x()
	{}
};
void Test0()
{
	int i = int();//注意:在c语言中不可以。
	cout << i << endl;
	//mytest0<string> t;//字符串有点不好搞事情
	mytest0<int> t;
	cout << t.x << endl;
}

#include <algorithm>
#include <cstring>
enum//默认情况下，枚举类型的第一个数是零
{
	one,
	two,
	three,
};
void Test1()
{
	//cout << one << endl;
	string N;
	//while (cin >> N)
	//{
	//}
}

void Test2()
{
	//1.插入排序的原理：始终定义第一个元素为有序的，将元素做个插入到有序排列之中，其特点是要不断的移动数据，
	//  空出一个适当的位置，把待插入的元素放到里面去。
	int a[] = { 4, 0, 2, 3, 1 }, i, j, t;
	for (i = 1; i < 5; ++i)     //对数组a进行插入排序（降序）
	{
		t = a[i];
		j = i - 1;
		while (j>0 && t > a[j])
		{
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = t;
	}
	for (i = 0; i < 5; ++i)
		printf("%2d", a[i]);
	printf("\n");

	//2. 选择排序的原理：每次在无序队列中选择最小值，放到有序队列的最后，并从无序队列中除去该值。

}

int FindSubstring(char *pch)//该函数的作用就是找先递增后递减的回文子串（增多少减多少）
{
	int count = 0;
	char *p1 = pch;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] - 1)
		{
			p1++; count++;
		}
		else
		{
			break;
		}
	}
	int count2 = count;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] + 1)
		{
			p1++; count2--;
		}
		else
		{
			break;
		}
	}
	if (count2 == 0)
		return count;
	else
		return 0;
}
void ModifyString(char*ptest)
{
	char *p1 = ptest;
	char *p2 = p1;
	while (*p1 != '\0')
	{
		int count = FindSubstring(p1);
		if (count > 0)
		{
			*p2++ = *p1;
			sprintf(p2, "%i", count);//输出重定向（这里：在p2指向的位置输入数字字符count，并且在p2+1处填'\0'）
			while (*p2 != '\0')
				p2++;
			p1 += count + count + 1;
		}
		else
		{
			*p2++ = *p1++;
		}
	}
}
void Test3()
{
	//char p[] = "abcdefg";
	//char *p2 = p;
	//int count = 3;
	//sprintf(p2 + 2, "%i", count);
	//printf("%s\n", p);
	char test[32] = "XYBCDCBABABA";
	ModifyString(test);
	printf("%s\n", test);
}

class AA4
{
public:
	int _a;
	void func()
	{
		printf("haha\n");
	}
	virtual void func2()
	{
		printf("hehe\n");
	}
	~AA4()//析构函数的作用：当一个对象的生存期结束时，系统会自动调用该对象所属类的析构函数
	{
		delete this;//析构函数中不能调用this指针，否则会形成无限循环，造成栈溢出
	}
};
void fun2();          //这有点像在析构函数中调用this指针的情况
void fun1(){ fun2(); }
void fun2(){ fun1(); }
void Test4()
{
	//AA4 a;//析构函数调用this，this又会调用本对象析构函数，形成无限循环，造成栈溢出

	AA4 *p = NULL;//(注意：这里不会出错，因为，这里根本没有对象，压根不会调用析构函数)
	p->func();//这步不会错，
	//p->func2();//出错（虚函数）
	//p->_a = 5;//这一步会出错，因为这一步对p指针进行了解引用
}

class AA5
{
public:
	AA5()
	{
		cout << "AA5()" << endl;
	}
	AA5(int a)
	{
		cout << "AA5(int a)" << endl;
	}
	~AA5()
	{
		cout << "~AA5()" << endl;
	}
private:
	int aa;
};
class BB5
{
public:
	//BB5()
	//{
	//	cout << "BB5()" << endl;
	//}
	BB5(int a)
		:_b(4), _c(a)
	{
		cout << "BB5(int a)" << endl;
	}
private:

	//构造函数初始化时必须采用初始化列表的一共有三种情况：
	AA5 _a;//①需要初始化的数据成员是对象（即类AA5没有默认构造函数）
	const int _b;//②需要初始化的const修饰的类成员
	int &_c;//③需要初始化的的引用成员数据
};
void Test5()
{
	BB5 b(2);
}

void Test6()
{
	struct T6
	{
		int a;
		char b;
		int arr[0];//只是一个占位符，并不占用结构体的空间大小
	};
	cout << sizeof(struct T6) << endl;

	struct T6 bb;
	cout << sizeof(bb) << endl;

	int ch[] = { 10, 11, 12, 13, 14, 15 };
	struct T6 *p = (struct T6 *)malloc(sizeof(struct T6) + 20);
	memcpy(p + 1, ch, sizeof(ch));
	p->a = 1;
	p->b = 2;
	cout << p->arr[2] << endl;
}

class AA7
{
public:
	int Getvalue()
	{
		vv = 1;
		return vv;
	}
private://在c++中，mutable是为了突破const的限制而设置的
	mutable int vv;//mutable只能修饰非静态数据成员，被mutable修饰的变量将永远处于可变的状态，即使在const函数中
};
void Test7()
{
	AA7 aa;
	int a1 = aa.Getvalue();
	cout << a1 << endl;

	//volatile
	const volatile int a = 10;//volatile的作用是防止编译器优化，每次访问a时都往内存中找数据，而不是在寄存器里找数据
	int *p = (int*)&a;
	*p = 20;
	cout << a << " " << *p << endl;
}

void Test8()
{
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);//①printf()是一个库函数，c/c++中函数的参数是从右往左入栈的；
	printf("%d ", a);             //②栈的生长方向是从高往低的③小端模式是低位存储在低字节
	printf("%d ", b);             //④%d格式输出的是4个字节大小，而long long为8个字节
	printf("%d\n", c);
}

void Test9()
{
	class A
	{
	public:
		A()
		{
			cout << "A()" << endl;
		}
		A(const A&a)
		{
			cout << "A(const A&a)" << endl;
		}
		~A()
		{
			cout << "~A()" << endl;
		}
	};
	class B :public A
	{
	public:
		//B(A &a)//先调用基类的构造函数
		//	:_a(a)//然后再调用基类的拷贝构造函数
		//{
		//	cout << "B()" << endl;//最后调用派生类的构造函数
		//}
		B(A a) //由于这里不是引用参数，所以最先会调用基类的拷贝构造函数（形参实参结合）；然后再调用基类的构造函数
			:_a(a)//然后这才会调用基类的拷贝构造函数来初始化子对象成员变量
		{
			cout << "B()" << endl;//最后才会调用派生类的构造函数
		}
		~B()
		{
			cout << "~B()" << endl;
		}
	private:
		A _a;
	};

	A a;
	B b(a);//形参实参调用完之后会立即调用析构函数（即该语句完成之后立即调用析构函数）
}

class A10
{
public:
	friend void f1(A10 &a);
	//{
	//	cout << a._a << endl;
	//	cout << "456" << endl;
	//}
	void f2();
	//friend void f3()   //该类的友元函数必须通过该类对象引用该类的成员函数
	//{
	//	cout << A10::_a << endl;
	//}
	friend void f4()
	{
		cout << "987" << endl;
	}
private:
	int _a = 1;
};
void A10::f2()//该类的成员函数
{
	cout << "45678" << endl;
}
void f1(A10 &a)//如果含有该类对象做参数，无论在类内类外定义（注意只能定义一次），在类外都可以调用
{
	cout << "258" << endl;
}
void f4();//必须在类外再次声明该友元函数，外面才能调用该函数
void Test10()
{
	A10 a;
	f1(a);
	a.f2();
	f4();//如果是一个不含该类对象做参数的函数在该类内定义了，在类外调用不到
}

void Test11(int n)
{
	//MIT HAKMEN算法：（计算32位整型数中的"1"的个数）
	//对任何自然数n的N次幂，用n-1取模得数为1.（即n^N%(n-1) = 1）
	int tmp;
	tmp = n - (n >> 1 & 033333333333) - (n >> 2 & 011111111111);//MIT HAKMEN算法
	tmp = tmp + (tmp >> 3) & 030707070707;
	//int tmp;
	//tmp = (n & 010101010101)
	//	+ (n >> 1 & 010101010101)
	//	+ (n >> 2 & 010101010101)
	//	+ (n >> 3 & 010101010101)
	//	+ (n >> 4 & 010101010101)
	//	+ (n >> 5 & 010101010101);
	printf("%d\n", tmp % 63);
}

#define IBM_PC//感觉IBM_PC既存在又不存在
void Test12()
{
	char a = IBM_PC + 'a';
	cout << a << endl;//正常输出字符'a'
	//printf("%d\n", IBM_PC);//出错，它说应输入一个表达式
}

void Test13()
{
	//隐式转换->（注意：编译器只会自动执行一步类型转换）
	//c++语言内置类型之间定义的几种自动转换规则：①在大多数表达式中，精度小的变量首先会提升为精度达的类型
	//②在条件中，非bool值转换为bool值③初始化过程中，初始值转换为变量类型
	//④在赋值语句中，右侧运算对象转换为左侧运算对象的类型⑤如果算术运算或关系运算的
	//运算对象有多种类型，需要转换成同一种类型（最终转换成精度最大的类型）⑥函数调用时
	//也会发生类型转换⑦在大多数表达式中，数组退化成指针
	//c++语言类类型的隐式转换规则：如果构造函数只接受一个实参，则它实际上定义了转换为次类类型的隐式转换机制
	//实际上把构造函数的参数类型向类类型转换了。
	//显式转换->
	//①static_cast<type>:相关类型转换②reinterpret_cast<type>:非相关类型转换
	//③const_cast<type>:去const转换④dynamic_cast<type>:动态类型转换⑤(type)expr或type(expr)
	//⑥explicit:只能在类内声明构造函数时使用explicit关键字，在类外定义时不能重复
	//explicit构造函数只能用于直接初始化
	//（注意：①接受一个单参数的const char*的string构造函数不是explicit的②接受一个容量参数的vector构造函数是explicit的）

	int a;
	char ch = 'a';
	a = int(ch);
	a = (int)ch;
	string s = "12345";//既可以直接初始化又可以拷贝初始化
	vector<int> v(10);//只能直接初始化

	class test
	{
	private:
		int _a;
	public:
		test() :_a(0){ cout << "void" << endl; }
		explicit test(int i) :_a(i){ cout << "int" << endl; }
		test(short i) :_a(i){ cout << "short" << endl; }

		test(const test&t) :_a(t._a){ cout << "test(const test&t)" << endl; }
		test&operator=(int n){ _a = n; cout << "operator=" << endl; return *this; }
	};
	int n = 10;
	test a2 = n;//拷贝初始化，即隐式类类型转换
	test a3(n);//直接初始化，即显式类类型转换
}

void Test14()
{
	int *p, k;
	//scanf("%d", &p);//没报错（但逻辑上错了）
	//scanf("%d", p);//出错，使用了未初始化的局部变量p

	p = &k;//正确
	scanf("%d", p);

	//*p = &k;//出错，
	//scanf("%d", p);

	//相关内置类型的转换
	double f = 12.0;
	int a = 0;
	a = f;//12
	cout << a << endl;
	a = *(int*)&f;//0
	cout << a << endl;
	a = (int)f;//12
	cout << a << endl;
	a = (int&)f;//0
	cout << a << endl;
	a = (int)&f;//f的地址值
	cout << a << endl;

	//指针变量是用来指示一个内存地址的变量，因此只能将地址值赋给指针变量（地址值是自然数）
	int*p2 = 0;//①0比较特殊，此时0代表NULL地址
	p2 = (int*)255;//②整数必须通过强制类型转换后才可以赋值给指针变量
	double *p3 = (double*)256;
	//double*p4 = (double*)259.5;//③浮点数通过强制类型转换也无效
}

void Test15(int list[], int k, int m)
{
	if (k == m)
	{
		copy(list, list + m + 1, ostream_iterator<int>(cout, " "));
		cout << endl;
		return;
	}
	for (int i = k; i <= m; ++i)
	{
		swap(list[k], list[i]);
		Test15(list, k + 1, m);
		swap(list[k], list[i]);
	}
}
void Swap(char*a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}
void Test152(char *list, int k, int m)
{
	if (k == m)
	{
		cout << list << endl;
		return;
	}
	for (int i = k; i <= m; ++i)
	{//第i个数分别与他后面的数字交换就能得到新的排列
		Swap(list + k, list + i);
		Test152(list, k + 1, m);
		Swap(list + k, list + i);
	}
}

void Test16()
{
	int n = -155;
	unsigned int count = 0;
	//while (n > 0)//①只能计算正整数的"1"的个数
	//{
	//	count++;
	//	n &= n - 1;
	//}
	//cout << count << endl;
	for (size_t i = 0; i < 8 * sizeof(n); ++i)//②可以计算所有整数"1"的个数（循环）
	{
		if (n & 1 << i)
			count++;
	}
	cout << count << endl;

	//③虽然右移在高位补符号位，但是这里的mask会将其掩盖，不会造成影响
	count = (n & 010101010101) + (n >> 1 & 010101010101) + (n >> 2 & 010101010101) +
		(n >> 3 & 010101010101) + (n >> 4 & 010101010101) + (n >> 5 & 010101010101);
	cout << count % 63 << endl;

	//④由于右移在高位补符号位，所以当n是负数时，总会多计算一个"1"；（有点缺陷）
	count = (n & 011111111111) + (n >> 1 & 011111111111) + (n >> 2 & 011111111111);
	count = count + (count >> 3) & 030707070707;
	cout << count % 63 << endl;
	//⑤由于右移在高位补符号位，所以当n是负数时，总会多计算一个"1"；（缺陷）
	//一个3位二进制数是4a+2b+c,我们想要的是a+b+c,n>>1的结果是2a+b,n>>2的结果是a,于是(4a+2b+c)-(2a+b)-a = a+b+c
	count = n - (n >> 1 & 033333333333) - (n >> 2 & 011111111111);
	count = count + (count >> 3) & 030707070707;
	cout << count % 63 << endl;

	//cout << (4 >> 1) << endl;//右移在高位补符号位
	//cout << (-1 >> 1) << endl;
	//cout << (-1 << 1) << endl;//左移在低位补零
	////10 011001 110101 110011 110010 011001

}

void Test17()
{
	//c/c++不支持数组整体赋值
	int a0[3];//三个随机值
	int a1[3] = { 0 * 3 };//0 0 0
	int a2[3] = { 0 };//0 0 0
	int a3[3] = { 7 };//7 0 0
	int a4[4] = { 3 * 7 };//21 0 0
	a2[2]++;
	a2[2]++;
	a2[2]++;
	a2[2]++;

	string str;
	while (getline(cin, str))
	{
		int hashtables[256] = { 0 };
		for (size_t i = 0; i<str.size(); ++i)
		{
			hashtables[str[i]]++;
		}
		for (size_t i = 0; i<str.size(); ++i)
		{
			if (hashtables[str[i]] == 3)
			{
				cout << str[i];
				break;
			}
		}
		break;
	}
}

void test_draft3()
{
	//Test0();
	//Test1();
	//Test2();//数组的插入排序（降序）
	//Test3();//"XYBCDCBABABA"
	//Test4();//类的空指针调用成员函数和在析构函数中调用this指针
	//Test5();//必须采用初始化列表的三种情况
	//Test6();//柔性数组
	//Test7();//mutable和volatile
	//Test8();//printf()函数压参数
	//Test9();//构造函数的调用顺序
	//Test10();//友元函数再探
	//Test11(10);//MIT HAKMEN算法（没有完全搞懂）
	//Test12();//薛定谔的猫？（完全没搞懂）
	//Test13();//explicit构造函数
	//Test14();//相关内置类型的转换
	//int A[3] = { 1, 2, 3 };//整形数组的全排列——递归
	////Test15(A, 0, 2);
	//char AA[] = "123";//字符数组的全排列——递归（没有完全看懂）
	//Test152(AA, 0, strlen(AA) - 1);
	//cout << AA << endl;
	Test16();//MIT HAKMEN算法(计算32位整型数中"1"的个数)
	//Test17();//从输入流中读取一行赋值给str。
}