#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include <stdlib.h>

class date{//声明了一个类便声明了一种类型，它并不接收和存储具体的值，系统不为其分配空间；只有定义了对象后，系统才为对象分配存储空间，以存放对象中的成员。
public:
	date(int, int, int);//重点：牢牢记住构造函数和拷贝构造函数都是 构造函数。
	~date();
	date(const date&d);
	inline void setdate(int, int);
	void showdate()
	{       //直接在类的内部定义的成员函数 是隐式声明的内联函数
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	/*const */int _year;//用const修饰的数据成员
	int _month;
	int _day;
};
inline void date::setdate(/*int year,*/ int month, int day)
{
	/*_year = year;*/
	_month = month;
	_day = day;
}
//带默认参数的构造函数
date::date(int month = 1, int day = 1, int year = 2017) :_year(year), _month(month), _day(day)
{//对于用const修饰的数据成员，或是引用类型的数据成员，是不允许用赋值语句直接赋值的。因此只能成员初始化列表对其进行初始化。
	cout << "use construction" << endl;
	//_year = year;
	//_month = month;
	//_day = day;
}
date::~date()
{//没有参数，没有返回值，而且不能重载；当撤销对象时，编译器会自动调用析构函数。
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
	date d1(2, 2, 2018);//①类名 对象名[(实参表)]
	date d2(d1);//如果对象在声明的同时将另一个已存在的对象赋给它，这时就会调用拷贝构造函数
	d1.showdate();
	d2.showdate();

	date *pdate1;
	pdate1 = &d1;

	date *pdate = new date;//②类名 *指针变量名=new 类名[(实参表)]
	//这里是怎么用delete释放pdate指向的无名对象的？
	d1.showdate();
	d1.setdate(/*2018,*/5, 2);
	d1.showdate();
	pdate1->showdate();
	pdate->showdate();


	system("pause");
	return 0;
}