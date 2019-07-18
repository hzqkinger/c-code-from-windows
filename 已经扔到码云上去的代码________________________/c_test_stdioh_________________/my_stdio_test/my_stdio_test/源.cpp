#define _CRT_SECURE_NO_WARNINGS
#include"test.h"
#include<CoreWindow.h>
#include<iostream>
#include<fstream>

union bsd
{
	int i;
	char ch;
};
void test_bsd()
{
	union bsd d;
	d.i = 1;
	if (d.ch)
		printf("it is big\n");//
	else
		printf("it is small\n");
}


void test_c11()
{
	std::ifstream ifs;

	ifs.open("test111.txt", std::ios::out | std::ios::trunc);
	if (ifs.fail())
		std::cout << "zhahzhzhhz" << std::endl;
}

int main()
{
	//test_bsd();

	//test1();
	//test_fflush();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();

	test_c11();

	system("pause");
	return 0;
}
