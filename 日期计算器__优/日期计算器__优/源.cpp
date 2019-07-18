#include<iostream>
#include<assert.h>
#include<CoreWindow.h>
using namespace std;
class Date{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		assert(_month > 0 && _month<13 && _day>0 && _day < GetMonth() + 1);
	}
	int GetMonth()
	{
		static int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (_month == 2 && (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0))
			return months[_month]+1;
		return months[_month];
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void Display2()
	{
		cout << _year << endl << endl;
		for (size_t i = 1; i <= 12; ++i)
		{
			cout << _month << endl;
			for (size_t j = 1; j <= GetMonth(); ++j)
			{
				cout << j << " ";
				if (j % 7 == 0)cout << endl;
			}

		}
	}

	int operator>(const Date &d)
	{
		if (_year > d._year)
			return 1;
		else if (_year == d._year)
		{
			if (_month > d._month)
				return 1;
			else if (_month == d._month){
				if(_day > d._day)
					return 1;
			}
		}
		return 0;
	}
	int operator==(const Date &d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
			return 1;
		else
			return 0;
	}
	int operator>=(const Date &d)
	{
		return *this > d || *this == d;
	}
	int operator<(const Date &d)
	{
		return !(*this >= d);
	}
	int operator<=(const Date &d)
	{
		return !(*this>d);
	}
	int operator!=(const Date &d)
	{
		return !(*this == d);
	}

	Date operator++()
	{
		*this = *this + 1;
		return *this;
	}
	Date operator++(int)
	{
		Date tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	Date operator+(int day)
	{
		if (day < 0)
			return *this - (-day);
		Date tmp(*this);
		tmp._day += day;
		while(tmp._day>tmp.GetMonth())
		{
			tmp._day -= tmp.GetMonth();
			tmp._month++;
			if (tmp._month > 12)
			{
				tmp._year++;
				tmp._month = 1;
			}
		}
		return tmp;
	}
	Date operator-(int day)
	{
		if (day < 0)
			return *this + (-day);
		Date tmp(*this);
		tmp._day -= day;
		while (tmp._day <= 0)
		{
			tmp._month--;
			tmp._day += tmp.GetMonth();
			if (tmp._month <= 0)
			{
				tmp._year--;
				tmp._month = 12;
			}
		}
		return tmp;
	}
	int operator-(const Date &d)//*this - d
	{
		int num = 0;
		Date Great(*this);
		Date Small(d);
		if (Great < Small)
		{
			Great = d;
			Small = *this;
		}
		while (Small++ < Great)
			num++;
		return num;
	}
	//形参 = 实参
	//void F1()//F1(Date*this1)形参
	//{
	//	F2();//this1->F2(this1)实参
	//}
	//void F2() const//void F2(Date const *this2)形参
	//{
	//	F1();//this2->F1(this2)实参
	//}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d(2017, 11, 21);
	Date d2(2017, 11, 29);
	//d = d + 1;
	//d.Display();
	//d2.Display();
	(d2 - d);
	system("pause");
	return 0;
}