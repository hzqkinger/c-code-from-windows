#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

#include"auto_ptr.h"
#include"scoped_array.h"
#include"scped_ptr.h"
#include"shared_array.h"
#include"shared_ptr.h"
#include"weak_ptr.h"
#include"imitation_func.h"
//所谓智能指针就是智能/自动化的管理指针所指向的动态资源的释放
//需要智能指针的目的：防止内存泄漏。

//智能指针的三大要素：①RAII思想(Resource Acquisition Is Initialization)
                       //资源分配即初始化，定义一个类来封装资源的分配和释放，在构造函数完成资源
                       //的分配和初始化，在析构函数完成资源的清理，可以保证资源的正确初始化和释放。
                    //②能像普通指针一样运算
                    //③解决多个智能指针指向同一块空间的问题，防止该空间被释放多次
class AA
{
public:
	int x;
};

void testAuto_ptr()
{
	int a = 5;

	Auto_ptr<int>ap1(new int(2));
	*ap1 = 10;
	Auto_ptr<AA> ap2 = new AA;
	ap2->x = 10;
	Auto_ptr<int>ap3(ap1);
	Auto_ptr<int>ap4(new int(2));
	ap4 = ap3;
	if (1)
	{
		return;
	}
}
void testScoped_ptr()
{
	Scoped_ptr<int>ap1(new int(2));
	*ap1 = 10;
	Scoped_ptr<AA> ap2 = new AA;
	ap2->x = 10;

	if (1)
	{
		return;
	}
}
void testScoped_array()
{
	Scoped_array<int>ap1(new int[2]);
	Scoped_array<AA>ap2(new AA[2]);

	ap1[1] = 10;
	if (1)
	{
		return;
	}
}
void testShared()
{
	Shared<int>ap1(new int(2));
	*ap1 = 10;
	Shared<AA> ap2 = new AA;
	ap2->x = 10;
	Shared<int>ap3(ap1);
	Shared<int>ap4(new int(2));
	ap4 = ap3;
	if (1)
		return;

}
void testSharedarray()
{
	Shared_array<int>ap1(new int[2]);
	ap1[0] = 10;
	Shared_array<AA> ap2 (new AA[2]);
	ap2[0].x= 10;
	Shared_array<int>ap3(ap1);
	Shared_array<int>ap4(new int(2));
	ap4 = ap3;
	if (1)
		return;

}

struct node
{
	int _data;
	Shared<node> _next;
	node()
		:_data(int())
		, _next(Shared<node>())
	{}
	~node()
	{
		cout << "~node()" << endl;
	}
};
void test()
{
	Shared<node> next = new node;
	{
		Shared<node> cur = new node;
		cur->_next = next;
		next->_next = cur;//这句代码造成循环引用问题
	}
	cout << "hah";
}
struct node2
{
	int _data;
	Weak_ptr<node2> _next;
	node2()
		:_data(int())
		, _next(Weak_ptr<node2>())
	{}
	~node2()
	{
		cout << "~node2()" << endl;
	}
};
void test2()
{
	Shared<node2> next = new node2;
	{
		Shared<node2> cur = new node2;
		cur->_next = next;
		next->_next = cur;//这句代码造成循环引用问题
	}
	cout << "hah";
}


#include<memory>
void test_memory()
{
	auto_ptr<int> ap1(new int(2));
	auto_ptr<int> ap2 = ap1;
	cout << " " << endl;
}
int main()
{
	//testAuto_ptr();
	//testScoped_ptr();
	//testShared();
	//testScoped_array();

	test();
	//test2();
	//test_memory();

	//Fclose fc;
	//Shared<FILE>ap1(fopen("data3.txt", "w"),Fclose());

	system("pause");
	return 0;
}