#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

//ǳ����������һ�� new[]��˼�룬��_str��ǰ��࿪�ĸ��ֽڵĿռ�������
//ǳ�������������� ��һ�����ݳ�Ա��int *refcount��������
class String{
public:
	//���캯��
	String(char *str = "")
		:_str(new char[strlen(str) + 5])
	{
		*((int*)_str) = 1;
		_str += 4;
		strcpy(_str, str);
	}
	//��������String s1 = s2
	String(const String &s)//ǳ����
	{
		_str = s._str;
		++*((int*)(_str - 4));
	}
	//��ֵ����������� s1 = s2
	String& operator=(const String &s)
	{
		if (_str != s._str)//ȷ����������ûָ��ͬһ���ռ䣬�Ž�ȥִ���������
		{
			if (--(*((int*)(_str - 4))) == 0)//���thisָ��Ŀռ�û����������ָ���ˣ����ͷſռ�
			{                       //����������if���
				delete[] (_str - 4);
			}
			_str = s._str;
			++*((int*)(_str - 4));
		}
		return *this;
	}
	//copy on write дʱ����
	void Copyonwrite()
	{
		if (*((int*)(_str - 4)) > 1)//���thisָ��Ķ���ָ��Ŀռ仹����������ָ����Ҫ��*this���¿��ռ�
		{                  //����������if���
			char *tmp = new char[strlen(_str) + 5];
			tmp += 4;
			strcpy(tmp, _str);
			--(*((int*)(_str - 4)));
			_str = tmp;
			*(int*)(_str - 4) = 1;
		}
	}
	//��������
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