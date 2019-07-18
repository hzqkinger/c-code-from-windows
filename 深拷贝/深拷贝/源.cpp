#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<Corewindow.h>
//1.��ͳд�����String�����
//class String
//{
//public:
//	String(char *str = "")//���캯��
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//	//String s1 = s2
//	String(const String &s)//�������캯��
//		:_str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//	//s1 = s2
//	String operator=(const String &s)//��ֵ���������
//	{
//		if (this != &s)
//		{
//			delete _str;
//			_str = new char[strlen(s._str) + 1];
//			strcpy(_str, s._str);
//		}
//			return *this;
//	}
//	~String()//��������
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

//2.�ִ�д�����String�����
class String
{
public:
	String(char *str = "")//���캯��
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	//String s1 = s2
	String(const String &s)//�������캯��
	{
		String tmp(s._str);
		swap(_str, tmp._str);//���swap()�����Ķ�����ͷ�ļ��а�����
	}
	//s1 = s2
	String& operator=(const String &s)//�ٸ�ֵ���������
	{
		if (this != &s)//ִ������s3 = s1ʱ������������������غ���
		{
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		return *this;
	}

	//s1 = s2  Ϊʲô���������
	//String& operator=(String s)//��ִ������s3 = s1ʱ������������������������ȥ���ÿ������캯����
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}

	~String()//��������
	{
		if (_str)
			delete[]_str;
	}

	char* Getstring()//�е���c_str()����
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
