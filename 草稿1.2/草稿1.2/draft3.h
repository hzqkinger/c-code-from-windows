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
	int i = int();//ע��:��c�����в����ԡ�
	cout << i << endl;
	//mytest0<string> t;//�ַ����е㲻�ø�����
	mytest0<int> t;
	cout << t.x << endl;
}

#include <algorithm>
#include <cstring>
enum//Ĭ������£�ö�����͵ĵ�һ��������
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
	//1.���������ԭ��ʼ�ն����һ��Ԫ��Ϊ����ģ���Ԫ���������뵽��������֮�У����ص���Ҫ���ϵ��ƶ����ݣ�
	//  �ճ�һ���ʵ���λ�ã��Ѵ������Ԫ�طŵ�����ȥ��
	int a[] = { 4, 0, 2, 3, 1 }, i, j, t;
	for (i = 1; i < 5; ++i)     //������a���в������򣨽���
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

	//2. ѡ�������ԭ��ÿ�������������ѡ����Сֵ���ŵ�������е���󣬲�����������г�ȥ��ֵ��

}

int FindSubstring(char *pch)//�ú��������þ������ȵ�����ݼ��Ļ����Ӵ��������ټ����٣�
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
			sprintf(p2, "%i", count);//����ض��������p2ָ���λ�����������ַ�count��������p2+1����'\0'��
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
	~AA4()//�������������ã���һ������������ڽ���ʱ��ϵͳ���Զ����øö������������������
	{
		delete this;//���������в��ܵ���thisָ�룬������γ�����ѭ�������ջ���
	}
};
void fun2();          //���е��������������е���thisָ������
void fun1(){ fun2(); }
void fun2(){ fun1(); }
void Test4()
{
	//AA4 a;//������������this��this�ֻ���ñ����������������γ�����ѭ�������ջ���

	AA4 *p = NULL;//(ע�⣺���ﲻ�������Ϊ���������û�ж���ѹ�����������������)
	p->func();//�ⲽ�����
	//p->func2();//�����麯����
	//p->_a = 5;//��һ���������Ϊ��һ����pָ������˽�����
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

	//���캯����ʼ��ʱ������ó�ʼ���б��һ�������������
	AA5 _a;//����Ҫ��ʼ�������ݳ�Ա�Ƕ��󣨼���AA5û��Ĭ�Ϲ��캯����
	const int _b;//����Ҫ��ʼ����const���ε����Ա
	int &_c;//����Ҫ��ʼ���ĵ����ó�Ա����
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
		int arr[0];//ֻ��һ��ռλ��������ռ�ýṹ��Ŀռ��С
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
private://��c++�У�mutable��Ϊ��ͻ��const�����ƶ����õ�
	mutable int vv;//mutableֻ�����ηǾ�̬���ݳ�Ա����mutable���εı�������Զ���ڿɱ��״̬����ʹ��const������
};
void Test7()
{
	AA7 aa;
	int a1 = aa.Getvalue();
	cout << a1 << endl;

	//volatile
	const volatile int a = 10;//volatile�������Ƿ�ֹ�������Ż���ÿ�η���aʱ�����ڴ��������ݣ��������ڼĴ�����������
	int *p = (int*)&a;
	*p = 20;
	cout << a << " " << *p << endl;
}

void Test8()
{
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);//��printf()��һ���⺯����c/c++�к����Ĳ����Ǵ���������ջ�ģ�
	printf("%d ", a);             //��ջ�����������ǴӸ����͵Ģ�С��ģʽ�ǵ�λ�洢�ڵ��ֽ�
	printf("%d ", b);             //��%d��ʽ�������4���ֽڴ�С����long longΪ8���ֽ�
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
		//B(A &a)//�ȵ��û���Ĺ��캯��
		//	:_a(a)//Ȼ���ٵ��û���Ŀ������캯��
		//{
		//	cout << "B()" << endl;//������������Ĺ��캯��
		//}
		B(A a) //�������ﲻ�����ò������������Ȼ���û���Ŀ������캯�����β�ʵ�ν�ϣ���Ȼ���ٵ��û���Ĺ��캯��
			:_a(a)//Ȼ����Ż���û���Ŀ������캯������ʼ���Ӷ����Ա����
		{
			cout << "B()" << endl;//���Ż����������Ĺ��캯��
		}
		~B()
		{
			cout << "~B()" << endl;
		}
	private:
		A _a;
	};

	A a;
	B b(a);//�β�ʵ�ε�����֮�������������������������������֮��������������������
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
	//friend void f3()   //�������Ԫ��������ͨ������������ø���ĳ�Ա����
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
void A10::f2()//����ĳ�Ա����
{
	cout << "45678" << endl;
}
void f1(A10 &a)//������и���������������������������ⶨ�壨ע��ֻ�ܶ���һ�Σ��������ⶼ���Ե���
{
	cout << "258" << endl;
}
void f4();//�����������ٴ���������Ԫ������������ܵ��øú���
void Test10()
{
	A10 a;
	f1(a);
	a.f2();
	f4();//�����һ��������������������ĺ����ڸ����ڶ����ˣ���������ò���
}

void Test11(int n)
{
	//MIT HAKMEN�㷨��������32λ�������е�"1"�ĸ�����
	//���κ���Ȼ��n��N���ݣ���n-1ȡģ����Ϊ1.����n^N%(n-1) = 1��
	int tmp;
	tmp = n - (n >> 1 & 033333333333) - (n >> 2 & 011111111111);//MIT HAKMEN�㷨
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

#define IBM_PC//�о�IBM_PC�ȴ����ֲ�����
void Test12()
{
	char a = IBM_PC + 'a';
	cout << a << endl;//��������ַ�'a'
	//printf("%d\n", IBM_PC);//������˵Ӧ����һ�����ʽ
}

void Test13()
{
	//��ʽת��->��ע�⣺������ֻ���Զ�ִ��һ������ת����
	//c++������������֮�䶨��ļ����Զ�ת�����򣺢��ڴ�������ʽ�У�����С�ı������Ȼ�����Ϊ���ȴ������
	//���������У���boolֵת��Ϊboolֵ�۳�ʼ�������У���ʼֵת��Ϊ��������
	//���ڸ�ֵ����У��Ҳ��������ת��Ϊ��������������͢��������������ϵ�����
	//��������ж������ͣ���Ҫת����ͬһ�����ͣ�����ת���ɾ����������ͣ��޺�������ʱ
	//Ҳ�ᷢ������ת�����ڴ�������ʽ�У������˻���ָ��
	//c++���������͵���ʽת������������캯��ֻ����һ��ʵ�Σ�����ʵ���϶�����ת��Ϊ�������͵���ʽת������
	//ʵ���ϰѹ��캯���Ĳ���������������ת���ˡ�
	//��ʽת��->
	//��static_cast<type>:�������ת����reinterpret_cast<type>:���������ת��
	//��const_cast<type>:ȥconstת����dynamic_cast<type>:��̬����ת����(type)expr��type(expr)
	//��explicit:ֻ���������������캯��ʱʹ��explicit�ؼ��֣������ⶨ��ʱ�����ظ�
	//explicit���캯��ֻ������ֱ�ӳ�ʼ��
	//��ע�⣺�ٽ���һ����������const char*��string���캯������explicit�Ģڽ���һ������������vector���캯����explicit�ģ�

	int a;
	char ch = 'a';
	a = int(ch);
	a = (int)ch;
	string s = "12345";//�ȿ���ֱ�ӳ�ʼ���ֿ��Կ�����ʼ��
	vector<int> v(10);//ֻ��ֱ�ӳ�ʼ��

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
	test a2 = n;//������ʼ��������ʽ������ת��
	test a3(n);//ֱ�ӳ�ʼ��������ʽ������ת��
}

void Test14()
{
	int *p, k;
	//scanf("%d", &p);//û�������߼��ϴ��ˣ�
	//scanf("%d", p);//����ʹ����δ��ʼ���ľֲ�����p

	p = &k;//��ȷ
	scanf("%d", p);

	//*p = &k;//����
	//scanf("%d", p);

	//����������͵�ת��
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
	a = (int)&f;//f�ĵ�ֵַ
	cout << a << endl;

	//ָ�����������ָʾһ���ڴ��ַ�ı��������ֻ�ܽ���ֵַ����ָ���������ֵַ����Ȼ����
	int*p2 = 0;//��0�Ƚ����⣬��ʱ0����NULL��ַ
	p2 = (int*)255;//����������ͨ��ǿ������ת����ſ��Ը�ֵ��ָ�����
	double *p3 = (double*)256;
	//double*p4 = (double*)259.5;//�۸�����ͨ��ǿ������ת��Ҳ��Ч
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
	{//��i�����ֱ�������������ֽ������ܵõ��µ�����
		Swap(list + k, list + i);
		Test152(list, k + 1, m);
		Swap(list + k, list + i);
	}
}

void Test16()
{
	int n = -155;
	unsigned int count = 0;
	//while (n > 0)//��ֻ�ܼ�����������"1"�ĸ���
	//{
	//	count++;
	//	n &= n - 1;
	//}
	//cout << count << endl;
	for (size_t i = 0; i < 8 * sizeof(n); ++i)//�ڿ��Լ�����������"1"�ĸ�����ѭ����
	{
		if (n & 1 << i)
			count++;
	}
	cout << count << endl;

	//����Ȼ�����ڸ�λ������λ�����������mask�Ὣ���ڸǣ��������Ӱ��
	count = (n & 010101010101) + (n >> 1 & 010101010101) + (n >> 2 & 010101010101) +
		(n >> 3 & 010101010101) + (n >> 4 & 010101010101) + (n >> 5 & 010101010101);
	cout << count % 63 << endl;

	//�����������ڸ�λ������λ�����Ե�n�Ǹ���ʱ���ܻ�����һ��"1"�����е�ȱ�ݣ�
	count = (n & 011111111111) + (n >> 1 & 011111111111) + (n >> 2 & 011111111111);
	count = count + (count >> 3) & 030707070707;
	cout << count % 63 << endl;
	//�����������ڸ�λ������λ�����Ե�n�Ǹ���ʱ���ܻ�����һ��"1"����ȱ�ݣ�
	//һ��3λ����������4a+2b+c,������Ҫ����a+b+c,n>>1�Ľ����2a+b,n>>2�Ľ����a,����(4a+2b+c)-(2a+b)-a = a+b+c
	count = n - (n >> 1 & 033333333333) - (n >> 2 & 011111111111);
	count = count + (count >> 3) & 030707070707;
	cout << count % 63 << endl;

	//cout << (4 >> 1) << endl;//�����ڸ�λ������λ
	//cout << (-1 >> 1) << endl;
	//cout << (-1 << 1) << endl;//�����ڵ�λ����
	////10 011001 110101 110011 110010 011001

}

void Test17()
{
	//c/c++��֧���������帳ֵ
	int a0[3];//�������ֵ
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
	//Test2();//����Ĳ������򣨽���
	//Test3();//"XYBCDCBABABA"
	//Test4();//��Ŀ�ָ����ó�Ա�����������������е���thisָ��
	//Test5();//������ó�ʼ���б���������
	//Test6();//��������
	//Test7();//mutable��volatile
	//Test8();//printf()����ѹ����
	//Test9();//���캯���ĵ���˳��
	//Test10();//��Ԫ������̽
	//Test11(10);//MIT HAKMEN�㷨��û����ȫ�㶮��
	//Test12();//Ѧ���̵�è������ȫû�㶮��
	//Test13();//explicit���캯��
	//Test14();//����������͵�ת��
	//int A[3] = { 1, 2, 3 };//���������ȫ���С����ݹ�
	////Test15(A, 0, 2);
	//char AA[] = "123";//�ַ������ȫ���С����ݹ飨û����ȫ������
	//Test152(AA, 0, strlen(AA) - 1);
	//cout << AA << endl;
	Test16();//MIT HAKMEN�㷨(����32λ��������"1"�ĸ���)
	//Test17();//���������ж�ȡһ�и�ֵ��str��
}