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

//�����ͷ�ļ�Ҫ����һ��һ�����������������Ų�����
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
		bool flag = true;//�ȱ��iΪ������flag = true

		for (size_t j = 2; j <= sqrt(i); ++j)//����ж�i��������,flag = false
		{
			if (i % j == 0){ flag = false; break; }
		}

		if (flag == true)++count;//ͳ�������ĸ���
	}


	return count;
}

int main()
{


	//test_draft1();//��Ҫ�Ƕ�c�﷨�Ĳ���
	//test_draft2();//��Ҫ�Ƕ�c++�﷨�Ĳ���
	//test_draft3();//��Ҫ�Ƕ�c++�﷨�Ĳ���
	//test_draft5();//��Ҫ�Ƕ�ģ���﷨�Ĳ���
	//test_draft6();//��Ҫ�������̽��c++����ģ��
	//test_draft7();
	//countPrimes(0);

	//char ch[] = "writes";
	//printf(ch,"before:");
	system("pause");

	return 0;
}