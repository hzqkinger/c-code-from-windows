#pragma once

#include <functional>
void test1(int left,int right)
{
	//很多高级语言里引入了lambda表达式的概念，即匿名函数。以往C++需要传入一个函数的时候，必须事先进行声明，
	//视情况可以声明为一个普通函数然后传入函数指针，或者声明一个funtor，然后传入一个对象。
    //但这种传统方法太过复杂，一个简单的遍历输出就需要声明一个类或者函数，本来用于简化语法的东西却使语法大大复杂化。

	//C++ 11中的Lambda表达式用于定义并创建匿名的函数对象
	// [](){ printf("%d\n", x + y); }
	function<void(int,int)> fun = [](int x,int y){ printf("hello lamda\n");
	printf("x + y = %d\n",x + y); };
	fun(1,2);

	//外部变量的捕获规则:
	//①默认情况下，即捕获字段为[] 时，lambda表达式是不能访问任何外部变量的，即表达式的函数体内无法访问当前作用域下的变量。
	//②如果要设定表达式能够访问外部变量，可以在[] 内写入 & 或者 = 加上变量名，其中 & 表示按引用访问， = 表示按值访问，变量之间用逗号分隔，比如[=factor, &total] 表示按值访问变量 factor，而按引用访问 total。
	//③不加变量名时表示设置默认捕获字段，外部变量将按照默认字段获取，后面在书写变量名时不加符号表示按默认字段设置，比如下面三条字段都是同一含义：
	//	[&total, factor]
	//	[&, factor]
	//	[=, &total]
	int lef = 10;
	auto fun2 = [&](){
		lef = 6;//不能在非可变lamda中修改按值捕获，即[=]时，不能改变捕获的值；当[&]时，可以修改捕获到的值
		cout << lef + right << endl;
		cout << lef << endl; };
	fun2();
	cout << lef << endl;


	auto fun3 = [=]()mutable throw(){
		left = 100;//设置了mutable就可以改变按值捕获的值，但是只是在lamda表达式中生效
		cout << left << endl;

		//int *ptr = NULL;
		//*(ptr + 100) = 100;
	};
	fun3();
	cout << left << endl;
}

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
using namespace std;
void test2()
{
	const int SIZE = 20;
	int array[SIZE];
	generate_n(array, SIZE,
		[]() { return rand() % 30 + 1; });

	for_each(array, array + SIZE,
		[](int a){ cout << a << " "; });
}

void test3()
{
	int a, b;
	a = 333;
	b = 0;
	try
	{
		if (b == 0)
		{
			//错误处理
			throw "出错，除数为0了";
			// throw 111.0;
		}
		printf("%d", a / b);
	}
	catch (char *s)
	{
		//错误处理
		printf("%s",s);
	}
	catch (int i)
	{
		//整型错误代码 处理
	}
	catch (...)
	{
		//所有异常类型
	}
}


void test_draft4()
{
	test1(1,2);//lamda表达式
	//test2();
	//test3();//抛异常的简单使用
}