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

	//�Ӽ�������9876543210
	int a; float b, c;
	scanf("%2d%3f%4f", &a, &b, &c);
	printf("\na=%d,b=%d,c=%f\n", a, b, c);
	printf("\na=%d,b=%f,c=%f\n", a, b, c);

}

class Test{
public:
	int a; int b; 
	virtual void fun() {}//ܳ�����ﻹ��һ���麯����
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
	virtual void test(){ 	func(); }//ע�͵�����������B->1 ����ע�� B->0
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
	
	//typedef A12(*ad)[2];//ֻ�Ƕ�����һ��ָ�򳤶�Ϊ2������ָ�룬��ָ��ΪҰָ��
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

//k��ʾ��ǰѡȡ���ڼ�����,m��ʾ���ж�����. 
void AllRange(char *Str, int k, int m)
{
	if (k == m)
		printf("%s\n", Str);
	else
	{
		for (int i = k; i <= m; i++)
			//��i�����ֱ�������������ֽ������ܵõ��µ�����
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
	mutable int vv;//��mutable�ؼ��֣��������const��Ա���������޸����ݳ�Ա
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
	//AllRange(Str, 0, strlen(Str) - 1);//ȫ����

	Base14 * pb = new Child14(1);//ֻҪ���ϸ���ָ��+�麯������������ʱ��̬
	Child14 *pc = dynamic_cast<Child14*>(pb);
	pb->func1();//***�������У��̳������Ķ���(����������)���������δ��д���ض��壬����游�ࡣ
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
	sprintf(text + 11, "%d", count);//������ת��Ϊ�ַ������Ӹ���λ�ÿ�ʼ���룬�������һ��'\0'

	strcpy(text, "NO");
	cout << text << endl;
}
class A15{
public:
	void func(){ delete this; }//������������delete this �򲻻���������
	//~A15(){ delete this; }//��������delte this �ᵼ��ѭ���ݹ飬��ɳ�����
};
void test15_8()
{
	A15 a;
	//a.func();
}
void test15()
{
	//�ѵĴ�С�ܲ���ϵͳ���ơ�
	//�ڶ���Ƶ����new/delete���ײ����ڴ���Ƭ��ջ��û���������
	//�Ѻ�ջ�����Զ�̬����

	test15_5();
	//test15_8();//delete thisָ��
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
//	void print(){A18::print();}//������Բ��ɷ��ʵĻ���
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
	//2.malloc���������ڴ�������� ִ�н׶�

	//vector�Ĳ���������ᵼ�µ�����ʧЧ     ����
	//map�Ĳ���������ᵼ�µ�����ʧЧ
	//vector��ɾ������ֻ�ᵼ��ָ��ɾ��Ԫ�ؼ�����ĵ�����ʧЧ
	//map��ɾ������ֻ�ᵼ��ָ��ɾ��Ԫ�صĵ�����ʧЧ

	test18_10();//����������
}

void test19()
{
	//2.����⣺ ���������ַ���a, b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
	//	����������
	//	���������ַ���
	//	���������
	//	�����ظ����ֵ��ַ�
	//ʾ��1 :
	//����
	//	abcdefghijklmnop
	//	abcsafjklmnopqrstuvw
	//	���
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
	//����������û����д����b.print()�ȼ���b.A20::print()
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
	test20_9();//����������û����д����b.print()�ȼ���b.A20::print()

	//2.����⣺ ����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ
	//           ��ż��������������ֵ��С��������
	//eg. ����20    ���7  13
}


void test21()
{
//    ϴ������   https://www.nowcoder.com/practice/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0?tpId
//    MP3������ҳ     https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15?tpId
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
//Ĭ�Ϲ��캯����ʲôʱ��Żᱻ����������������������Ҫ��ʱ�򣬼�������������±����������Ĭ�Ϲ��캯����
//�ٴ���"default construct"��һ������"member class object"����ע�⣬��������Աû��Ĭ�Ϲ��캯����������Լ����죩
//�ڴ���"default construct"��derived class������һ��û���κι��캯��������������һ������Ĭ�Ϲ��캯���ĸ��ࣩ
//�۴���"virtual function"���ࡣ
//�ܴ���"virtual base class"���ࡣ�������μ̳�����£�
//��C++11�����Ժ�����ֻҪ��һ�����ݳ�Ա����Ĭ�ϳ�ʼֵ
class base
{
public:
	base(int a, int b){}
	virtual void ff(){}
};
class derived : public base
{
public:
	derived(int a = 2) :base(2,2),b(1, 1), r(a), c(2)//�����ڳ�ʼ���б��ʼ�����ݳ�Ա
	{
		//b.base::base(1, 1);//�������Ǵ��
	}
	base b;//����Ĭ�Ϲ��캯���Ķ����Ա��ע�⣬��������Աû��Ĭ�Ϲ��캯����������Լ����죩
	int &r;//�����ñ���
	const int c;//��const����
	//�����һ������̳�����Ĭ�Ϲ��캯���ĸ��࣬��ô�����಻���Զ�����Ĭ�Ϲ��캯���������Լ�д��
};
void test22_81()
{
	derived d;
}
//ʲôʱ������һ����Ŀ������캯����
//����ʽ����һ��object��������Ϊ��һ��class object�ĳ�ֵ��X xx = x;��
//��object��������������ĳ������
//�۵���������һ��class objectʱ
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
	//5.������ / ���� = �� ... ����  �������������ͱ���������һ�£�
	//int a = 6, b = -4, c = a / b;
	//cout << c << endl;
	//c = a % b;
	//cout << c << endl;

	//8.���캯���ĵ���˳�����������ĵ���˳��
	//test22_8();
	//test22_81();//��������ʲô����»����Ĭ�Ϲ��캯����ʲô����±����ڳ�ʼ���б��ʼ��
	//X x;
	//test22_82(test22_82(test22_82(x)));//ʲô����»���ÿ������캯�����Լ����������Ż�

	//1.����⣺�������������Լ������������������С��������
	//����һ�������ýϴ������ȥ��С������Ȼ���ò����С������ȣ�������ȣ���������������Լ�������򣬶��ڲ�ͽ�С�����ٴ��ظ������Ĺ��̡�
	//����������ģ�����ýϴ�������Խ�С������ģ��Ҫ��ģΪ�㣬��ϴ������Ϊ���Լ��������ģ��Ϊ�㣬����ڽ�С������ģ���������Ĺ��̡�
	//int gcd(int a, int b){
	//	int tmp;
	//	while (b){
	//		tmp = b; b = a % b; a = tmp;
	//	}
	//	return a;
	//}
	//2.�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
}

int f23_5(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;//�����Ƕ��ŷָ�����
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
	void print()//��ʱ��B23�е����ݳ�Աa��һ������A23::a  
	{
		a = 3;
		A23::a = 4;//����������ʵ��һ������
		cout << "A23::a = " << A23::a << endl;//��ע�⣬ֻ���ڼ̳�ʱ���ſ�����������ͨ���������ʸ�������ݺͷ�����
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
	while (cin >> money)//�Բ��ʱ��ֱ������NULL�Ž�������
		arr.push_back(money);

	//����һ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ�ΪO(1)
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
	//��������ʱ�临�Ӷ���O(n)���ռ临�Ӷ�ΪO(logn)~O(n)
	//������sort(arr.begin(),arr.end())��Ȼ��arr[arr.size()/2]������Ҫ�ҵ���
	//��������ʱ�临�Ӷ���O(n)���ռ临�Ӷ�ΪO(n)
	//��map<int,int> mp;��ͳ���������������ֵĴ�����Ȼ����ѭ��һ��Ϳ����ҵ����ִ�����������

	//���һ���г��ִ�������һ��ĺ������������߼��Ϳ����ҵ���������һ�������ѭ��
	cnt = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (money == arr[i])
			++cnt;
	}
	return cnt > arr.size() / 2 ? money : -1;//������Ҽ���û�ҵ��ͷ���-1��
}
void test23()
{
	//5.�������� ���ű��ʽ �� ���ŷָ��� ������
	//int arr[] = { 3, 4, 5 };
	//int a;
	//a = arr[0], arr[1], arr[2];
	//cout << a << endl;
	////test23_5();
	////int sum = 7, num = 4;
	////sum = num++, sum++, ++num;//���ŷָ���
	//int sum = 7, num = 4;
	//sum = (num++, sum++, ++num);//���ű��ʽ��һ������£������ţ�

	//8.����C++�̰߳�ȫ��˵����
	//�̰߳�ȫ���ⶼ����ȫ�ֱ�������̬���������
	//c++��׼�������string��֤���̰߳�ȫ��         ��
	//POSIX�̱߳�׼Ҫ��C��׼���еĴ���������߱��̰߳�ȫ

	//10. ��ע�⣬���Ͳ�һ�������Կ����Ķ���Ҳ��һ����
	test23_10();

	//1.����⣺��һ�����������У�ĳ�������ֵĴ�������һ�룬���ҳ��������
	//cout << Test23_1() << endl;
	//2.����⣺�༭���룬ָ���������ַ���֮�䣬��һ��ת������һ����������ٱ༭������
	//         ��ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ��һ���ַ���
	//eg."abcd"-->"abc"ͨ�����ӻ�ɾ��'d'�ķ�ʽ�ﵽĿ�ģ������ַ�������Ҫһ�β��������������������Ϊ�����ַ����ľ��롣

}

void test_daily_bite2()
{
	test6();//strcat����
	//test9();//����ָ��ģ�ͣ�

	//test12();//������дʱ�Ĵ������������дʱ�Ĵ�����������㲻����
	//test13();//��ʽ����ת����
	//test14();//ȫ���У�mutable�ؼ��֣�**�麯��
	//test15();//sprintf��strcpy��delete this

	//int i = 3; printf("%d %d", ++i, ++i);

	//test18();//������������ʸ����ܱ����ĳ�Ա��printf��ӡ�����ʽ������������ͨ����
	//test20();//***�������У��̳������Ķ���(����������)���������δ��д���ض��壬����游�ࡣ
	//test21();
	//test22();//�����������������������ĵ���ʱ�䣻ʲôʱ��Ĭ�Ϲ��캯������Ч�ģ�ʲôʱ�򿽱����캯������Ч��
	//test23();  //���ű��ʽ �� ���ŷָ��������Ͳ�һ�������Կ����Ķ���Ҳ��һ������һ�����û��
}