#pragma once

void test6()
{
	//char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
	//char *ss = strcat(p1 + 2, p2 + 1);
	//printf("%s\n", ss);
	//printf("%s\n", p1);
	//printf("%s\n", p2);
	//strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	//printf("%s\n", str);

	//从键盘输入9876543210
	int a; float b, c;
	scanf("%2d%3f%4f", &a, &b, &c);
	printf("\na=%d,b=%d,c=%f\n", a, b, c);
	printf("\na=%d,b=%f,c=%f\n", a, b, c);

}

class Test{
public:
	int a; int b; 
	virtual void fun() {}//艹，这里还有一个虚函数。
	Test(int temp1 = 0, int temp2 = 0){ a = temp1; b = temp2; }
	int getA(){ return a; }
	int getB(){ return b; } 
}; 
void func9(char **m){
	++m;
	cout << *m << endl;
}
void test9()
{
	//static char *a[] = { "morning", "afternoon", "evening" };
	//cout << "sizeof(a) = " << sizeof(a) << endl;
	//char **p;
	//p = a;
	//func9(p);

	Test obj(5, 10);
	// Changing a and b
	int* pInt = (int*)&obj;
	*(pInt + 0) = 100; 
	*(pInt + 1) = 200;
	cout << "a = " << obj.getA() << endl;
	cout << "b = " << obj.getB() << endl;
}

class A11{
public:
	virtual void func(int val = 1){std::cout << "A->" << val << std::endl;}
	virtual void test(){func();}
};
class B11 : public A11
{
public:
	void func(int val = 0){std::cout << "B->" << val << std::endl;}
	virtual void test(){ 	func(); }//注释掉这句代码结果是B->1 ；不注释 B->0
};
void func12(const int& v1, const int& v2)
{
	std::cout << v1 << ' ';
	std::cout << v2 << ' ';
}
class A12{ public:A12(){ cout << "A12" << endl; } };
void test12()
{
	//int i = 0;
	//func12(++i, i++);
	
	//typedef A12(*ad)[2];//只是定义了一个指向长度为2的数组指针，该指针为野指针
	////cout << ad << endl;
	//A12 *p1;
	//A12 a;
	//A12 a2[2];

	B11*p = new B11;
	p->test();
}

class B13
{
public:
	B13(){cout << "default constructor" << " ";}
	~B13(){cout << "destructed" << " ";}
	B13(int i) : data(i){cout << "constructed by parameter" << data << " ";}
	B13(const B13 &bb){cout << "copy constructed" << data << " "; }
private: 
	int data;
};
B13 Play(B13 b){return b;}
#include<vector>
void test13()
{
	//B13 temp = Play(5);

	vector<int> arr(5);
	for (int &var : arr)cout << "var = "<< var << endl;
}

//k表示当前选取到第几个数,m表示共有多少数. 
void AllRange(char *Str, int k, int m)
{
	if (k == m)
		printf("%s\n", Str);
	else
	{
		for (int i = k; i <= m; i++)
			//第i个数分别与它后面的数字交换就能得到新的排列
		{
			swap(Str[k], Str[i]);
			AllRange(Str, k + 1, m);
			swap(Str[k], Str[i]);
		}
	}
}
class A14 {
public:
	int GetValue() const {
		vv = 1;
			return vv;
	}
private:
	mutable int vv;//有mutable关键字，则可以在const成员函数里面修改数据成员
};
class Base14 {
public:
	Base14(int j) : i(j) {}
	virtual~Base14() {}
	void func1() { i *= 10; func2(); }
	int getValue() { return i; }
protected:
	virtual void func2() { i++; }
protected:
	int i; 
}; 
class Child14 : public Base14 { 
public:
	Child14(int j) : Base14(j) {}
	void func1() { i *= 100; func2(); }
	//int getValue() { return i; }
protected:
	void func2() { i += 2; } 
	//int i;
}; 	
void test14()
{
	//char Str[] = "123";
	//AllRange(Str, 0, strlen(Str) - 1);//全排列

	Base14 * pb = new Child14(1);//只要符合父类指针+虚函数，就是运行时多态
	Child14 *pc = dynamic_cast<Child14*>(pb);
	pb->func1();//***在子类中，继承下来的东西(变量，函数)，如果子类未重写或重定义，则跟随父类。
	cout << pb->getValue() << endl; 
	cout << pc->Child14::getValue() << endl;
	pc->func1();
	cout << pb->getValue() << endl;
	cout << pc->Child14::getValue() << endl;
	delete pb;
}

void test15_5(void)
{
	//5.
	char text[32] = "XYBCDCBABABA";
	int count = 123;
	sprintf(text + 11, "%d", count);//把整型转换为字符串，从给定位置开始插入，最后再添一个'\0'

	strcpy(text, "NO");
	cout << text << endl;
}
class A15{
public:
	void func(){ delete this; }//在其他函数中delete this 则不会立即出错
	//~A15(){ delete this; }//析构函数delte this 会导致循环递归，造成程序奔溃
};
void test15_8()
{
	A15 a;
	//a.func();
}
void test15()
{
	//堆的大小受操作系统限制。
	//在堆上频繁的new/delete容易产生内存碎片；栈就没有这个问题
	//堆和栈都可以动态分配

	test15_5();
	//test15_8();//delete this指针
}

//class A18
//{
//public:
//	void print(){cout << "A:print()";}
//};
//class B18 : private A18
//{
//public:
//	void print(){cout << "B:print()";}
//};
//class C18 : public B18
//{
//public:
//	void print(){A18::print();}//不允许对不可访问的基类
//};
class A18 {
public:
	~A18() {cout << "~A()";}
};
class B18{
public:
	virtual ~B18() {cout << "~B()";}
};
class C18 : public A18, public B18 {
public:
	~C18() {cout << "~C()";}
};
void test18_10(){
	C18 * c = new C18;
	B18 * b1 = dynamic_cast<B18 *>(c);
	A18 * a2 = dynamic_cast<A18 *>(b1);
	//delete a2;
	delete c;
}
void test18()
{
	//1.
	double d = 3.15555555555555555555486;
	printf("%-30.4f\n", d);
	//2.malloc函数进行内存分配是在 执行阶段

	//vector的插入操作不会导致迭代器失效     错误
	//map的插入操作不会导致迭代器失效
	//vector的删除操作只会导致指向被删除元素及后面的迭代器失效
	//map的删除操作只会导致指向被删除元素的迭代器失效

	test18_10();//虚析构函数
}

void test19()
{
	//2.编程题： 查找两个字符串a, b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
	//	输入描述：
	//	输入两个字符串
	//	输出描述：
	//	返回重复出现的字符
	//示例1 :
	//输入
	//	abcdefghijklmnop
	//	abcsafjklmnopqrstuvw
	//	输出
	//	jklmnop
}

int fun20(int *p[4]){ return 0; }
class A20
{
public:
	int _a;
	A20(){_a = 1;}
	void print(){printf("%d", _a);}
};
class B20 : public A20
{
public:
	int _a;
	B20(){_a = 2;}
	//void print(){ printf("%d", _a); }
	//假如子类中没有重写，则b.print()等价于b.A20::print()
};
void test20_9()
{
	B20 b;
	A20 *p = &b;
	//b.A20::print();
	p->print();
	printf("%d", b._a);
}
void test20()
{
	//3. int a[4][4]; int **a; int **a[4]int(*a)[4]
	//int **a; fun20(a);
	//9.
	test20_9();//假如子类中没有重写，则b.print()等价于b.A20::print()

	//2.编程题： 任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指
	//           定偶数的两个素数差值最小的素数对
	//eg. 输入20    输出7  13
}


void test21()
{
//    洗牌问题   https://www.nowcoder.com/practice/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0?tpId
//    MP3歌曲翻页     https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15?tpId
}

class A22{ public: A22(){ cout << "A" << endl; } ~A22(){ cout << "~A" << endl; } };
class B22{ public: B22(){ cout << "B" << endl; } ~B22(){ cout << "~B" << endl; } };
class C22{ public: C22(){ cout << "C" << endl; } ~C22(){ cout << "~C" << endl; } };
class D22{ public: D22(){ cout << "D" << endl; } ~D22(){ cout << "~D" << endl; } };
C22 c;
void test22_8()//~A ~B ~D ~C
{
	A22*pa = new A22();
	B22 b;
	static D22 d;
	delete pa;
}
//默认构造函数在什么时候才会被编译器产生出来？答：在需要的时候，即下面五种情况下编译器会产生默认构造函数。
//①带有"default construct"的一个或多个"member class object"。（注意，如果对象成员没有默认构造函数，则必须自己构造）
//②带有"default construct"的derived class。（即一个没有任何构造函数的子类派生自一个带有默认构造函数的父类）
//③带有"virtual function"的类。
//④带有"virtual base class"的类。（即菱形继承情况下）
//⑤C++11及其以后，类中只要有一个数据成员含有默认初始值
class base
{
public:
	base(int a, int b){}
	virtual void ff(){}
};
class derived : public base
{
public:
	derived(int a = 2) :base(2,2),b(1, 1), r(a), c(2)//必须在初始化列表初始的数据成员
	{
		//b.base::base(1, 1);//这句代码是错的
	}
	base b;//①无默认构造函数的对象成员（注意，如果对象成员没有默认构造函数，则必须自己构造）
	int &r;//②引用变量
	const int c;//③const变量
	//④如果一个子类继承自无默认构造函数的父类，那么该子类不能自动产生默认构造函数，必须自己写。
};
void test22_81()
{
	derived d;
}
//什么时候会调用一个类的拷贝构造函数？
//①显式地以一个object的内容作为另一个class object的初值（X xx = x;）
//②object被当做参数交给某个函数
//③当函数返回一个class object时
class X{
	int a;
public:
	X(int a_ = 0){}
	X(const X &x){ cout << "const X &x" << endl; }
};
X test22_82(X x)
{
	return x;
}
void test22()
{
	//5.被除数 / 除数 = 商 ... 余数  （余数的正负和被除数保持一致）
	//int a = 6, b = -4, c = a / b;
	//cout << c << endl;
	//c = a % b;
	//cout << c << endl;

	//8.构造函数的调用顺序；析构函数的调用顺序
	//test22_8();
	//test22_81();//编译器在什么情况下会产生默认构造函数；什么情况下必须在初始化列表初始化
	//X x;
	//test22_82(test22_82(test22_82(x)));//什么情况下会调用拷贝构造函数，以及编译器的优化

	//1.编程题：求两个数的最大公约数。（求两个数的最小公倍数）
	//方法一：求差法，用较大的数减去较小的数，然后拿差与较小的数相比，若是相等，则这个数就是最大公约数。否则，对于差和较小的数再次重复上述的过程。
	//方法二：求模法，用较大的数来对较小的数求模，要是模为零，则较大的数则为最大公约数。若是模不为零，则对于较小的数和模继续上述的过程。
	//int gcd(int a, int b){
	//	int tmp;
	//	while (b){
	//		tmp = b; b = a % b; a = tmp;
	//	}
	//	return a;
	//}
	//2.找出字符串中第一个只出现一次的字符
}

int f23_5(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;//这里是逗号分隔符。
	return (a);
}
void test23_5()
{
	int a = 2, i, k;
	for (int i = 0; i < 2; ++i)
		k = f23_5(a++);
	printf("%d\n", k);
}
class A23{
public:
	long a = 1;
};
class B23 :public A23{
public:
	long b = 2;
	void print()//此时，B23中的数据成员a有一个别名A23::a  
	{
		a = 3;
		A23::a = 4;//这两个，其实是一个变量
		cout << "A23::a = " << A23::a << endl;//（注意，只有在继承时，才可以在子类中通过类名访问父类的数据和方法）
		cout << "B23::a = " << a << endl;
		cout << "B23::b = " << b << endl;
	}
};
void seta_23(A23 *data ,int idx)
{
	data[idx].a = 2;
}
void test23_10()
{
	//B23 data[4];
	//for (int i = 0; i < 4; ++i){
	//	data[i].a = 1; data[i].b = 1;

	//	seta_23(data, i);
	//}
	//for (int i = 0; i < 4; ++i){
	//	cout << data[i].a << data[i].b;
	//}cout << endl;

	B23 b;
	b.print();
}
#include<vector>
int Test23_1()
{
	vector<int> arr; int money,cnt = 0;
	while (cin >> money)//自测的时候，直到输入NULL才结束输入
		arr.push_back(money);

	//方法一：时间复杂度是O(n)，空间复杂度为O(1)
	money = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (cnt == 0)
		{
			money = arr[i];
			cnt = 1;
		}
		else
			money == arr[i] ? ++cnt:--cnt;
	}
	//方法二：时间复杂度是O(n)，空间复杂度为O(logn)~O(n)
	//先排序sort(arr.begin(),arr.end())；然后arr[arr.size()/2]就是需要找的数
	//方法三：时间复杂度是O(n)，空间复杂度为O(n)
	//用map<int,int> mp;来统计数组中所有数字的次数；然后再循环一遍就可以找到出现次数最多的数字

	//如果一定有出现次数超过一半的红包，则上面的逻辑就可以找到；否则跑一跑下面的循环
	cnt = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (money == arr[i])
			++cnt;
	}
	return cnt > arr.size() / 2 ? money : -1;//在这里，我假设没找到就返回-1。
}
void test23()
{
	//5.必须搞清楚 逗号表达式 和 逗号分隔符 的区别
	//int arr[] = { 3, 4, 5 };
	//int a;
	//a = arr[0], arr[1], arr[2];
	//cout << a << endl;
	////test23_5();
	////int sum = 7, num = 4;
	////sum = num++, sum++, ++num;//逗号分隔符
	//int sum = 7, num = 4;
	//sum = (num++, sum++, ++num);//逗号表达式（一般情况下，有括号）

	//8.关于C++线程安全的说法：
	//线程安全问题都是由全局变量及静态变量引起的
	//c++标准库里面的string保证是线程安全的         错
	//POSIX线程标准要求C标准库中的大多数函数具备线程安全

	//10. （注意，类型不一样，所以看到的东西也不一样）
	test23_10();

	//1.编程题：在一个整型数组中，某个数出现的次数超过一半，请找出这个数。
	//cout << Test23_1() << endl;
	//2.编程题：编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑次数。
	//         许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
	//eg."abcd"-->"abc"通过增加或删除'd'的方式达到目的，这两种方案都需要一次操作。把这个操作次数称为两个字符串的距离。

}

void test_daily_bite2()
{
	test6();//strcat函数
	//test9();//二级指针模型；

	//test12();//子类重写时的传参情况，不重写时的传参情况。（搞不懂）
	//test13();//隐式类型转换；
	//test14();//全排列；mutable关键字；**虚函数
	//test15();//sprintf；strcpy；delete this

	//int i = 3; printf("%d %d", ++i, ++i);

	//test18();//不允许子类访问父类受保护的成员；printf打印浮点格式；虚析构与普通析构
	//test20();//***在子类中，继承下来的东西(变量，函数)，如果子类未重写或重定义，则跟随父类。
	//test21();
	//test22();//变量的作用域与析构函数的调用时间；什么时候默认构造函数是有效的；什么时候拷贝构造函数是有效的
	//test23();  //逗号表达式 和 逗号分隔符；类型不一样，所以看到的东西也不一样；有一个编程没做
}