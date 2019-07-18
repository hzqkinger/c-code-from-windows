#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

class String{
public:
	//���캯��
	String(char *str = "")
		:_str(new char[strlen(str) + 1])
		, _refcount(new int(1))
	{
		strcpy(_str, str);
	}
	//��������String s1 = s2
	String(const String &s)//ǳ����
	{
		_str = s._str;
		_refcount = s._refcount;
		++(*_refcount);
	}
	//��ֵ����������� s1 = s2
	String& operator=(const String &s)
	{
		if (_str != s._str)//ȷ����������ûָ��ͬһ���ռ䣬�Ž�ȥִ���������
		{
			if (--(*_refcount) == 0)//���thisָ��Ŀռ�û����������ָ���ˣ����ͷſռ�
			{                       //����������if���
				delete[]_str;
				delete _refcount;
			}
			_str = s._str;
			_refcount = s._refcount;
			++(*_refcount);
		}
		return *this;
	}
	//copy on write,дʱ�����������ú������ڿ����޸Ķ����ָ��Ŀռ�ĺ�����
	void Copyonwrite()//��֤thisָ��Ķ�����޸Ĳ���Ӱ����������
	{
		if (*_refcount > 1)//���thisָ��Ķ���ָ��Ŀռ仹����������ָ����Ҫ��*this���¿��ռ�
		{                  //����������if���
			char *tmp = new char[strlen(_str) + 1];
			strcpy(tmp, _str);
			--(*_refcount);
			_str = tmp;
			_refcount = new int(1);
		}
	}
	//��������
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
		Copyonwrite();//����һ��Ҫ���������������Ϊ���ܻ��޸�this->_strָ����ַ���
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