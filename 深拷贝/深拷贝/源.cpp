#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<Corewindow.h>
//1.传统写法完成String深拷贝。
//class String
//{
//public:
//	String(char *str = "")//构造函数
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//	//String s1 = s2
//	String(const String &s)//拷贝构造函数
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//	//s1 = s2
//	String operator=(const String &s)//赋值运算符重载
//	{
//		if (this != &s)
//		{
//			delete _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//			return *this;
//	}
//	~String()//析构函数
//	{
//		if (_str)
//			delete[]_str;
//	}
//
//	char* Getstring()
//	{
//		return _str;
//	}
//private:
//	char* _str;
//};

//2.现代写法完成String深拷贝。
class String
{
public:
	String(char *str = "")//构造函数
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	//String s1 = s2
	String(const String &s)//拷贝构造函数
	{
		String tmp(s._str);
		swap(_str, tmp._str);//这个swap()函数的定义在头文件中包含。
	}
	//s1 = s2
	String& operator=(const String &s)//①赋值运算符重载
	{
		if (this != &s)//执行下面s3 = s1时，会正常调用这个重载函数
		{
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		return *this;
	}

	//s1 = s2  为什么这个有问题
	//String& operator=(String s)//②执行下面s3 = s1时根本不会调用这个函数，而是去调用拷贝构造函数。
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}

	~String()//析构函数
	{
		if (_str)
			delete[]_str;
	}

	char* Getstring()//有点像c_str()函数
	{
		return _str;
	}
private:
	char* _str;
};
int main()
{
	String s1("abc");
	//String s2 = s1;
	String s3;
	s3 = s1;
	puts(s1.Getstring());
	//puts(s2.Getstring());
	puts(s3.Getstring());

	system("pause");
	return 0;
}
