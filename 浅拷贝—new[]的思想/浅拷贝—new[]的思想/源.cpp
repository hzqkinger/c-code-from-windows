#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

//浅拷贝：方法一① new[]的思想，在_str的前面多开四个字节的空间来计数
//浅拷贝：方法二② 多一个数据成员，int *refcount用来计数
class String{
public:
	//构造函数
	String(char *str = "")
		:_str(new char[strlen(str) + 5])
	{
		*((int*)_str) = 1;
		_str += 4;
		strcpy(_str, str);
	}
	//拷贝构造String s1 = s2
	String(const String &s)//浅拷贝
	{
		_str = s._str;
		++*((int*)(_str - 4));
	}
	//赋值运算符重载是 s1 = s2
	String& operator=(const String &s)
	{
		if (_str != s._str)//确保两个对象没指向同一个空间，才进去执行下面语句
		{
			if (--(*((int*)(_str - 4))) == 0)//如果this指向的空间没有其他对象指向了，就释放空间
			{                       //否则跳过该if语句
				delete[] (_str - 4);
			}
			_str = s._str;
			++*((int*)(_str - 4));
		}
		return *this;
	}
	//copy on write 写时拷贝
	void Copyonwrite()
	{
		if (*((int*)(_str - 4)) > 1)//如果this指向的对象指向的空间还有其他对象指向，则要给*this重新开空间
		{                  //否则跳过该if语句
			char *tmp = new char[strlen(_str) + 5];
			tmp += 4;
			strcpy(tmp, _str);
			--(*((int*)(_str - 4)));
			_str = tmp;
			*(int*)(_str - 4) = 1;
		}
	}
	//析构函数
	~String()
	{
		if (--(*(int*)(_str - 4)) == 0)
		{
			_str -= 4;
			delete[]_str;
		}
	}
	char& operator[](size_t index)
	{
		Copyonwrite();
		return _str[index];
	}
	char *Getc_str()
	{
		return _str;
	}
private:
	char* _str;
};
int main()
{
	//String s1("hello");
	//String s2 = s1;
	//String s3;
	//s3 = s2;
	//s3[2]= 'x';
	//puts(s1.Getc_str());
	//puts(s2.Getc_str());
	//puts(s3.Getc_str());

	string ss;
	cout << sizeof(ss) << endl;

	system("pause");
	return 0;
}