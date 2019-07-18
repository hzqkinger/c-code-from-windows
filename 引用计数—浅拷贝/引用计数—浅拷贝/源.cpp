#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

class String{
public:
	//构造函数
	String(char *str = "")
		:_str(new char[strlen(str) + 1])
		, _refcount(new int(1))
	{
		strcpy(_str, str);
	}
	//拷贝构造String s1 = s2
	String(const String &s)//浅拷贝
	{
		_str = s._str;
		_refcount = s._refcount;
		++(*_refcount);
	}
	//赋值运算符重载是 s1 = s2
	String& operator=(const String &s)
	{
		if (_str != s._str)//确保两个对象没指向同一个空间，才进去执行下面语句
		{
			if (--(*_refcount) == 0)//如果this指向的空间没有其他对象指向了，就释放空间
			{                       //否则跳过该if语句
				delete[]_str;
				delete _refcount;
			}
			_str = s._str;
			_refcount = s._refcount;
			++(*_refcount);
		}
		return *this;
	}
	//copy on write,写时拷贝函数，该函数用在可能修改多对象指向的空间的函数中
	void Copyonwrite()//保证this指向的对象的修改不会影响其他对象
	{
		if (*_refcount > 1)//如果this指向的对象指向的空间还有其他对象指向，则要给*this重新开空间
		{                  //否则跳过该if语句
			char *tmp = new char[strlen(_str) + 1];
			strcpy(tmp, _str);
			--(*_refcount);
			_str = tmp;
			_refcount = new int(1);
		}
	}
	//析构函数
	~String()
	{
		if (--(*_refcount) == 0)
		{
			delete[]_str;
			delete _refcount;
		}
	}
	char& operator[](size_t index)
	{
		Copyonwrite();//这里一定要调用这个函数，因为可能会修改this->_str指向的字符串
		return _str[index];
	}
	char *Getc_str()
	{
		return _str;
	}
private:
	char* _str;
	int* _refcount;
};

int main()
{
	String s1("hello");
	String s2 = s1;
	String s3 = s2;
	s3[2] = 'x';
	puts(s1.Getc_str());
	puts(s2.Getc_str());
	puts(s3.Getc_str());

	system("pause");
	return 0;
}