#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
//#include <stdarg.h>
#include<stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//下面的头文件要单独一个一个包含，否则重名概不负责
//#include"draft1.h"
//#include"draft2.h"
//#include"draft3.h"
//#include"draft5.h"
//#include"draft6.h"
#include"draft7.h"

const int buffer = 10;
int buffer2 = 11;

int countPrimes(int n) {
	int count = 0;

	for (size_t i = 1; i < n; ++i)
	{
		bool flag = true;//先标记i为质数，flag = true

		for (size_t j = 2; j <= sqrt(i); ++j)//如果判断i不是质数,flag = false
		{
			if (i % j == 0){ flag = false; break; }
		}

		if (flag == true)++count;//统计质数的个数
	}


	return count;
}

int main()
{


	//test_draft1();//主要是对c语法的测试
	//test_draft2();//主要是对c++语法的测试
	//test_draft3();//主要是对c++语法的测试
	//test_draft5();//主要是对模板语法的测试
	//test_draft6();//主要是在深度探索c++对象模型
	//test_draft7();
	//countPrimes(0);

	//char ch[] = "writes";
	//printf(ch,"before:");
	system("pause");

	return 0;
}