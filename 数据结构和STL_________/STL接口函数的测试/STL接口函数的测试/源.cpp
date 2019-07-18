#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include"Test_STL.h"

//STL的六大组件：容器，迭代器，适配器，算法，仿函数，空间配置器
//                   ①容器通过空间配置器取得数据存储空间；
//                   ②算法利用迭代器向容器存取数据；
//                   ③仿函数协助算法完成不同的策略；
//                   ④适配器可以用来修改容器、迭代器或仿函数的接口；

#include"test.h"
int main()
{
	test_draft4();

	//int *p1 = new int[5];
	//cout << p1[1] << p1[3] << p1[6]<<endl;
	//string *p2 = new string[5];
	//cout << p2[1] << p2[3] << p1[6] << endl;

	//string str("hello");
	//reverse(str.begin(),str.end());
	//cout << str << endl;

	//test();

	system("pause");
	return 0;
}