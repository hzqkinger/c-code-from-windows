#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include <stdlib.h>

class date{//������һ�����������һ�����ͣ����������պʹ洢�����ֵ��ϵͳ��Ϊ�����ռ䣻ֻ�ж����˶����ϵͳ��Ϊ�������洢�ռ䣬�Դ�Ŷ����еĳ�Ա��
public:
	date(int, int, int);//�ص㣺���μ�ס���캯���Ϳ������캯������ ���캯����
	~date();
	date(const date&d);
	inline void setdate(int, int);
	void showdate()
	{       //ֱ��������ڲ�����ĳ�Ա���� ����ʽ��������������
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	/*const */int _year;//��const���ε����ݳ�Ա
	int _month;
	int _day;
};
inline void date::setdate(/*int year,*/ int month, int day)
{
	/*_year = year;*/
	_month = month;
	_day = day;
}
//��Ĭ�ϲ����Ĺ��캯��
date::date(int month = 1, int day = 1, int year = 2017) :_year(year), _month(month), _day(day)
{//������const���ε����ݳ�Ա�������������͵����ݳ�Ա���ǲ������ø�ֵ���ֱ�Ӹ�ֵ�ġ����ֻ�ܳ�Ա��ʼ���б������г�ʼ����
	cout << "use construction" << endl;
	//_year = year;
	//_month = month;
	//_day = day;
}
date::~date()
{//û�в�����û�з���ֵ�����Ҳ������أ�����������ʱ�����������Զ���������������
	cout << "use destruction" << endl;
}
date::date(const date&d)
{
	cout << "use copy construction" << endl;
	_year = d._year + 1;
	_month = d._month + 1;
	_day = d._day + 1;
}
int main()
{
	date d1(2, 2, 2018);//������ ������[(ʵ�α�)]
	date d2(d1);//���������������ͬʱ����һ���Ѵ��ڵĶ��󸳸�������ʱ�ͻ���ÿ������캯��
	d1.showdate();
	d2.showdate();

	date *pdate1;
	pdate1 = &d1;

	date *pdate = new date;//������ *ָ�������=new ����[(ʵ�α�)]
	//��������ô��delete�ͷ�pdateָ�����������ģ�
	d1.showdate();
	d1.setdate(/*2018,*/5, 2);
	d1.showdate();
	pdate1->showdate();
	pdate->showdate();


	system("pause");
	return 0;
}