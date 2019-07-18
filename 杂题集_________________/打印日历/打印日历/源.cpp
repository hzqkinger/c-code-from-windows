#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>


void Print(int year)
{
	static int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		mon[2] = 29;
	for (size_t i = 1; i <= 12; ++i)
	{
		cout << "            " << i << "ÔÂ" << endl;
		for (size_t j = 1; j <= mon[i]; ++j)
		{
			printf("%4d", j);
			if (j % 7 == 0)cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	int year = 2017;
	cout << "please enter year:" << endl;
	cin >> year;
	Print(year);

	system("pause");
	return 0;
}