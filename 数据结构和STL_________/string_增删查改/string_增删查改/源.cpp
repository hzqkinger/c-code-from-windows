#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>
#include<assert.h>
class String
{
public:
	String(char* str = "", size_t size = 0, size_t capacity = 0)
		:_size(strlen(str)),_capacity(_size+100),_str(new char[_capacity + 1])
	{
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);//调用了上面的构造函数
		Swap(tmp);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String tmp(s._str);//调用了上面的构造函数
			Swap(tmp);
		}
		return *this;
	}
	void Swap(String& s)
	{
		char *tmp = NULL;
		tmp = _str;
		_str = s._str;
		s._str = tmp;
		_size = s._size;
		_capacity = s._capacity;
	}
	~String()
	{
		if (_str != NULL)
		{
			delete[] _str;
		}
	}

	char* GetStr()
	{
		return _str;
	}
	size_t Size();
	size_t Capacity();

		// 增删查改 
	void PushBack(char ch)
	{
		if (_size >= _capacity)
			_capacity *= 2;
		_str[_size++] = ch;
		_str[_size] = '\0';
	}
	void PushBack(const char* str)
	{
		if (_size+strlen(str) >= _capacity)
			_capacity += strlen(str);
		while (_str[_size++] = *str++);
		_size--;
	}
	void PopBack()
	{
		assert(_str);
		_str[--_size] = '\0';
	}
	void Insert(size_t pos, char ch)//如果不从零算起，那么就是在第pos位后面插入字符ch
	{
		assert(pos <= _size);
		if (_size >= _capacity)
			_capacity *= 2;
		int tmp = _size;
		while (tmp >= (int)pos)
		{
			_str[tmp+1] = _str[tmp];
			tmp--;
		}
		_size++;
		_str[pos] = ch;
	}
	void Insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t n = strlen(str);
		if (_size + n >= _capacity)
			_capacity += n;
		int tmp = _size;
		while (tmp >= (int)pos)
		{
			_str[tmp + n] = _str[tmp];
			tmp--;
		}
		while (*str)
		{
			_str[pos++] = *str++;
		}
		_size += n;
	}
	void Erase(size_t pos, size_t count)
	{
		assert(pos <= _size);
		if (pos + count >= _size)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			while (pos + count <= _size)
			{
				_str[pos] = _str[pos + count];
				pos++;
			}
			_size -= count;
		}
	}
	size_t Find(char ch) const
	{
		char *tmp = _str;
		while (*tmp && *tmp++ != ch);
		if (!*tmp)return -1;
		return tmp - _str - 1;
	}
	size_t Find(const char* str) const
	{
		const char *source = _str, *tmp = _str;
		const char *groud = str;
		while (*source)
		{
			tmp = source;
			groud = str;
			while (*tmp++ == *groud++)
			{
				if (!*groud)
					return source - _str;
			}
			source++;
		}
		return -1;
	}
	char& operator[](size_t pos)//s[2]
	{
		assert(pos <= _size);
		return _str[pos];
	}
	bool operator<(const String& s) const
	{
		const char *s1 = _str;
		const char *s2 = s._str;
		for (; *s1 == *s2; s1++, s2++)
		{
			if (!*s1)
				return false;
		}
		return *s1<*s2 ? true : false;
	}
	bool operator==(const String& s) const
	{
		const char *s1 = _str;
		const char *s2 = s._str;
		for (; *s1 == *s2; s1++, s2++)
		{
			if (!*s1)
				return true;
		}
		return false;
	}

	bool operator<=(const String& s) const
	{
		return *this<s || *this == s;
	}
	bool operator>(const String& s) const
	{
		return !(*this <= s);
	}
	bool operator>=(const String& s) const
	{
		return !(*this < s);
	}
	bool operator!=(const String& s)const
	{
		return !(*this == s);
	}

	String& operator+=(const String &s)
	{
		PushBack(s._str);
		return *this;
	}

	//friend ostream& operator<<(ostream& _cout, const String &str)
	//{
	//	return _cout << str;
	//}
	//friend istream& operator>>(istream& _cin,String &str)
	//{
	//	_cin >> str;
	//	return _cin;
	//}
private:
	size_t _size; // 字符个数 
	size_t _capacity; // 容量空间 
	char* _str;
};

#include<string>
int main()
{
	//String s1("abc");
	//String s2 = s1;
	//String s3;
	//s3 = s1;
	//puts(s2.GetStr());
	//puts(s3.GetStr());
	//puts(s1.GetStr());

	//String s4("hello world");
	////s4.Insert(1, "my world");
	////puts(s4.GetStr());
	////s4.Erase(5, 100);
	//puts(s4.GetStr());
	//printf("%c\n", s4[6]);

	//String s5("hello worl");
	//String s6("hello world");
	//if (s5 >= s6)
	//	puts("haha");
	//else
	//	puts("not");

	//String s7("hello");
	//String s8(" world");
	//s7 += s8;
	//puts(s7.GetStr());
	//puts(s8.GetStr());

	system("pause");
	return 0;
}