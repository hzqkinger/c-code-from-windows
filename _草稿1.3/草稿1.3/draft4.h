#pragma once

#include <functional>
void test1(int left,int right)
{
	//�ܶ�߼�������������lambda���ʽ�ĸ������������������C++��Ҫ����һ��������ʱ�򣬱������Ƚ���������
	//�������������Ϊһ����ͨ����Ȼ���뺯��ָ�룬��������һ��funtor��Ȼ����һ������
    //�����ִ�ͳ����̫�����ӣ�һ���򵥵ı����������Ҫ����һ������ߺ������������ڼ��﷨�Ķ���ȴʹ�﷨����ӻ���

	//C++ 11�е�Lambda���ʽ���ڶ��岢���������ĺ�������
	// [](){ printf("%d\n", x + y); }
	function<void(int,int)> fun = [](int x,int y){ printf("hello lamda\n");
	printf("x + y = %d\n",x + y); };
	fun(1,2);

	//�ⲿ�����Ĳ������:
	//��Ĭ������£��������ֶ�Ϊ[] ʱ��lambda���ʽ�ǲ��ܷ����κ��ⲿ�����ģ������ʽ�ĺ��������޷����ʵ�ǰ�������µı�����
	//�����Ҫ�趨���ʽ�ܹ������ⲿ������������[] ��д�� & ���� = ���ϱ����������� & ��ʾ�����÷��ʣ� = ��ʾ��ֵ���ʣ�����֮���ö��ŷָ�������[=factor, &total] ��ʾ��ֵ���ʱ��� factor���������÷��� total��
	//�۲��ӱ�����ʱ��ʾ����Ĭ�ϲ����ֶΣ��ⲿ����������Ĭ���ֶλ�ȡ����������д������ʱ���ӷ��ű�ʾ��Ĭ���ֶ����ã��������������ֶζ���ͬһ���壺
	//	[&total, factor]
	//	[&, factor]
	//	[=, &total]
	int lef = 10;
	auto fun2 = [&](){
		lef = 6;//�����ڷǿɱ�lamda���޸İ�ֵ���񣬼�[=]ʱ�����ܸı䲶���ֵ����[&]ʱ�������޸Ĳ��񵽵�ֵ
		cout << lef + right << endl;
		cout << lef << endl; };
	fun2();
	cout << lef << endl;


	auto fun3 = [=]()mutable throw(){
		left = 100;//������mutable�Ϳ��Ըı䰴ֵ�����ֵ������ֻ����lamda���ʽ����Ч
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
			//������
			throw "��������Ϊ0��";
			// throw 111.0;
		}
		printf("%d", a / b);
	}
	catch (char *s)
	{
		//������
		printf("%s",s);
	}
	catch (int i)
	{
		//���ʹ������ ����
	}
	catch (...)
	{
		//�����쳣����
	}
}


void test_draft4()
{
	test1(1,2);//lamda���ʽ
	//test2();
	//test3();//���쳣�ļ�ʹ��
}