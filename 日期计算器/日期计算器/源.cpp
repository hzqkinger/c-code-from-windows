#include<iostream>
#include<CoreWindow.h>
using namespace std;
class date{
public:
	date(int month = 1, int day = 1, int year = 2017)
	{
		cout << "���˹��캯��" << endl;
		_year = year;
		_month = month;
		_day = day;
		int days = GetMonthDays(year,month,day);
		if (days != 1)
		{
			cout << "���ڲ��Ϸ�";
			exit(-1);
		}
	}
	date(const date &d)
	{
		cout << "���˿������캯��" << endl;
		//����٣��������һ������ȥ ��ʼ�� �������һ������
		//����ڣ����������β�����Ķ��󣬵��ú������� �βκ�ʵ�ν�� ʱ��
		//����ۣ��������� ����ֵ�Ƕ��� ������ִ����ɷ��ص���ʱ��
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Setime()
	{
		cout << "����ʱ��" << endl;
		cin >> _year;
		cin >> _month;
		cin >> _day;
	}
	void Display_date()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	int Month_sort(int month,int year)
	{
		if (month % 2 == 0)
		{
			if (month == 2)
				return 28 + Isleap(year);
			else if (month < 8)
				return 30;
			else
				return 31;
		}
		else
		{
			if (month < 8)
				return 31;
			else
				return 30;
		}
	}
	int Isleap(int year)
	{
		int flag = 0;
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
			flag = 1;
		return flag;
	}
	int GetMonthDays(int year, int month,int day)
	{
		if (month>=1 && month<=12 && day <= Month_sort(month, year) && day >= 1)
			return 1;
		else
			return 0;
	}

	int operator>(const date& d)
	{
		if (_year > d._year)
			return 1;
		else if (_year == d._year)
		{
			if (_month > d._month)
				return 1;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	int operator>=(const date& d)
	{
		if (_year > d._year)
			return 1;
		else if (_year == d._year)
		{
			if (_month > d._month)
				return 1;
			else if (_month == d._month)
			{
				if (_day >= d._day)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	int operator< (const date& d)
	{
		if (_year < d._year)
			return 1;
		else if (_year == d._year)
		{
			if (_month < d._month)
				return 1;
			else if (_month == d._month)
			{
				if (_day < d._day)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	int operator<= (const date& d)
	{
		if (_year < d._year)
			return 1;
		else if (_year == d._year)
		{
			if (_month < d._month)
				return 1;
			else if (_month == d._month)
			{
				if (_day <= d._day)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	int operator== (const date& d)
	{
		if (_year != d._year)
			return 0;
		else 
		{
			if (_month != d._month)
				return 0;
			else
			{
				if (_day != d._day)
					return 0;
				else
					return 1;
			}
		}
	}
	int operator!= (const date& d)
	{
		if (_year == d._year)
			return 0;
		else
		{
			if (_month == d._month)
				return 0;
			else
			{
				if (_day == d._day)
					return 0;
				else
					return 1;
			}
		}
	}

	date operator+=(int num)
	{
		if (num<0)
			return -1;
		while (num > 365 + Isleap(_year))
		{
			num -= 365 + Isleap(_year);
			_year++;
		}
		while (num > Month_sort(_month, _year))
		{
			num -= Month_sort(_month, _year);
			if (_month == 12)
			{
				_month = 1;
				_year++;
			}
			else
				_month++;
		}
		if (num + _day > Month_sort(_month, _year))
		{
			if (_month == 12)
			{
				_month = 1, _year++;
				_day += num - Month_sort(_month, _year);
			}
			else
			{
				_day += num - Month_sort(_month, _year);
				_month++;
			}
		}
		else
			_day += num;
		return *this;
	}
	date operator-=(int num)
	{
		//���ֻ�ܼ�������Ϊ���������
		if (num<0)
			return *this;
		int tmp_num = 0;
		while (_month-->1)//�����Ƶ�_month =1
			tmp_num += Month_sort(_month, _year);
		tmp_num += _day;

		while (num > 365 + Isleap(_year - 1))
		{
			num -= 365 + Isleap(_year - 1);
			_year--;
		}

		if (tmp_num > num)
		{
			tmp_num -= num;
			while (tmp_num>Month_sort(_month, _year))
			{
				tmp_num -= Month_sort(_month, _year);
				_month++;
			}
			_day = tmp_num;
		}
		else
		{
			_month = 12, _year--;
			num -= tmp_num;
			while (num > Month_sort(_month, _year))
			{
				num -= Month_sort(_month, _year);
				_month--;
			}
			_day = Month_sort(_month, _year) - num;
		}
		return *this;
	}
	int operator-(date& d)
	{
		int cnt = 0, tmp_cnt = 0;
		while (d._month <= 12)
		{
			cnt += d.Month_sort(d._month, d._year);
			d._month++;
		}
		cnt -= d._day;
		d._year++;
		while (_month-->1)
			cnt += Month_sort(_month, _year);
		cnt += _day;
		cnt+=(_year - d._year) * 365;
		if (_year > d._year)
		{
			while (_year > d._year)
			{
				tmp_cnt += Isleap(d._year);
				d._year++;
			}
		}
		else
		{
			while (_year <= d._year)
			{
				tmp_cnt -= Isleap(_year);
				_year++;
			}
		}
		return cnt + tmp_cnt;
	}
	date operator+(int num)
	{ 
		//���ֻ�ܼ�������Ϊ���������
		if (num<0)
			return *this;
		while (num > 365 + Isleap(_year))
		{
			num -= 365 + Isleap(_year);
			_year++;
		}
		while (num > Month_sort(_month, _year))
		{
			num -= Month_sort(_month, _year);
			if (_month == 12)
			{
				_month = 1;
				_year++;
			}
			else
				_month++;
		}
		if (num + _day > Month_sort(_month, _year))
		{
			if (_month == 12)
			{
				_month = 1, _year++;
				_day += num - Month_sort(_month, _year);
			}
			else
			{
				_day += num - Month_sort(_month, _year);
				_month++;
			}
		}
		else
			_day += num;
		return *this;
	}
	date operator-(int num)
	{
		//���ֻ�ܼ�������Ϊ���������
		if (num<0)
			return *this;
		int tmp_num = 0;
		while (_month-->1)//�����Ƶ�_month =1
			tmp_num += Month_sort(_month, _year);
		tmp_num += _day;

		while (num > 365 + Isleap(_year-1))
		{
			num -= 365 + Isleap(_year-1);
			_year--;
		}

		if (tmp_num > num)
		{
			tmp_num -= num;
			while (tmp_num>Month_sort(_month,_year))
			{
				tmp_num -= Month_sort(_month, _year);
				_month++;
			}
			_day = tmp_num;
		}
		else
		{
			_month = 12,_year--;
			num -= tmp_num;
			while (num > Month_sort(_month, _year))
			{
				num -= Month_sort(_month, _year);
				_month--;
			}
			_day = Month_sort(_month, _year) - num;
		}
		return *this;
	}
	date operator++()
	{
		++_year;
		++_month;
		++_day;
		if (_month > 12)
		{
			_month -= 12;
			_year += 1;
		}
		if (_day > Month_sort(_month, _year))
		{
			_day -= Month_sort(_month, _year);
			_month += 1;
		}
		return *this;
	}
	date operator++(int)
	{
		date temp(*this);
		++_year;
		++_month;
		++_day;
		if (_month > 12)
		{
			_month -= 12;
			_year += 1;
		}
		if (_day > Month_sort(_month, _year))
		{
			_day -= Month_sort(_month, _year);
			_month += 1;
		}
		return temp;
	}
	date operator=(date&d)
	{
		cout << "���˸�ֵ���������" << endl;
		//��һ���Ѿ��������˵Ķ���ֵʱ�����õľ��Ǹ�ֵ�������
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	
	friend ostream& operator<<(ostream&out, date& d)
	{
		out << d._year << "-" << d._month << "-" << d._day << "\n";
		return out;
	}
	friend istream& operator>>(istream&input, date& d)
	{
		cout << "����ʱ��" << endl;
		input >> d._year;
		input >> d._month;
		input >> d._day;
		return input;
	}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	//int m;
	//date d1(5, 2, 2015);
	//date d2(5, 6, 2015);
	//if (d1 != d2)
	//	cout << "hah" << endl;
	//else
	//	cout << "hehe" << endl;

	date d1(1,29,2015);
	date d2;
	d2 = d1 - 999;
	cout << d2;


	system("pause");
	return 0;
}