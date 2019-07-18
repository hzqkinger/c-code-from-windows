#pragma once

#include<assert.h>
#include <stdarg.h>

//template<class charT,class traits = char_traits<charT>,class Alloc = allocator<charT>> class basic_string;
//typedef basic_string<char> string
#include<string>//字符串:它是一个可以动态的字符串（char*_str,size_t _size = 0,size_t _capacity = 16）
//或者说它是一个动态增长的字符数组//初始：_size=0，_capacity = 16//if需要增容：_capacity+=16(在这个编译器上)
void test_string()
{
	string str("it is string");//构造函数

	//一.字符对象输出系列
	cout << str << endl;                //1.可以直接输出（因为重载了operator<<运算符）
	string::iterator it = str.begin();  //2.正向迭代器输出字符
	for (; it != str.end(); ++it)
		cout << *it;
	cout << endl;

	for (size_t i = 0; i < str.size(); ++i)//像数组一样输出字符串（因为重载了operator[]运算符）
		cout << str[i];
	cout << endl;

	string::reverse_iterator rit = str.rbegin();  //3.反向迭代器输出字符
	for (; rit != str.rend(); ++rit)
		cout << *rit;
	cout << endl;
	//const char* c_str()const;
	cout << str.c_str() << endl;              //8.返回指向该字符串的指针
	//const char* data()const;
	cout << str.data() << endl;

	//二. size();length();capacity();clear();empty();max_size()
	cout << "size:" << str.size() << endl;//4.size()和length()都是返回字符串的长度
	cout << "length:" << str.length() << endl;
	cout << "capacity:" << str.capacity() << endl;      //5.返回该字符数组的总容量
	//cout << str.max_size() << endl;      //返回一个字符串最大能有多长的长度（很少用，因为没多大意义）

	cout << str.empty() << endl;         //6.判断该字符串是否为空
	//str.clear();                         //7.将该字符串清空
	//cout << str.empty() << endl;
	//cout << str.c_str() << endl;
	//cout << "size:" << str.size() << endl;
	//cout << "capacity:" << str.capacity() << endl;

	//三.改变字符串长度_size的大小resize()//原字符串 str.size() = 12;str.capacity() = 15;
	//void resize(size_t n);
	//void resize(size_t n,char ch)
	//str.resize(9,'+');//把字符串的长度变为9，（if原来的长度大于9，那么等同于str.resize(9)）
	//str.resize(13, '+');//把字符串的长度变为13（if原来的长度小于13，那么在原来字符后面补上字符‘+’直到字符串长度为13止）
	//str.resize(13);//把字符串的长度变为13（if原来的长度小于13，那么在原来字符后面补上空格字符）
	//str.resize(16, '+');//效果等同于增容为13的情况
	//cout << str << endl;
	//cout << "size:" << str.size() << endl;
	//cout << "capacity:" << str.capacity() << endl;
	//四.改变字符串容量_capacity的大小reserve()
	//void reserve(size_t n);
	//str.reserve(9);//如果字符串的原来的容量大于9，则这句代码什么都不会做
	//str.reserve(18);//If n is greater than the current string capacity, the function causes the container to increase its capacity to n characters(or greater).
	//cout << "size:" << str.size() << endl;
	//cout << "capacity:" << str.capacity() << endl;

	////五.能向普通字符串一样支持随机访问
	////char& operator[] (size_t pos);
	////const char& operator[] (size_t pos) const;
	//cout << str[6] << endl;//11.重载[],像字符数组一个支持随机访问 (注意，string没有重载*)
	//str[6] = 'S';
	//for (size_t i = 0; i < str.size(); ++i)
	//	cout << str[i];
	//cout << endl;
	////char& at(size_t pos);
	////const char& at(size_t pos) const;//12.随机访问
	//cout << str.at(6) << endl;
	//str.at(6) = 'W';
	//for (size_t i = 0; i < str.size(); ++i)
	//	cout << str.at(i);
	//cout << endl;

	//cout << str.front();       //(c++11以后支持)13.返回字符串的第一个字符或者最后一个字符
	//cout << str.back() << endl;

	////六.下面三个是在字符串末尾的追加系列
	//string str2("progma");
	//string::iterator it2 = str2.begin();
	////string& operator+=(char ch);
	////string& operator+=(const char *s);
	////string& operator+=(const string& str);
	//str += '1';
	//str += "23";        //14.Append to string 
	//str += str2;
	//cout << str << endl;
	////string& append(size_t n,char ch);//（注意不能光append(char ch),因为string中没有这个接口）
	////string& append(const char *s);
	////string& append(const char *s,size_t n);
	////string& append(const string& str);
	////string& append(const string& str,size_t subpos,size_t sublen);
	////string& append(InputIterator first,InputIterator last);//(注意,first一定要先于或等于last,否则会出错)
	//str.append(1, '4');
	//str.append("56");     //15.在字符串后面追加上字符串  Append to string 
	//str.append("789101112131415", 2);
	//str.append(str2);
	//str.append(str2, 0, 3);
	//str.append(it2 + 3, it2 + 5);//(注意，追加区间是[first,last) )
	//cout << str << "      " << *(it2 + 5) << endl;
	//str.push_back('W');   //16.Append character to string
	//cout << str << endl;
	//str.assign("it is string");
	//char *p2 = "123456789";
	//str.append(p2, p2 + 3);//(注意，不一定要是迭代器，也可以是字符指针，追加区间[p2,p2+3) )
	//cout << str << endl;

	////七.重新赋值系列
	////string& assign(size_t n,char ch);
	//str.assign(6, 'w');
	//cout << str << endl;
	////string& assign(const char* s);
	////string& assign(const char* s, size_t n);//(注意，重新赋值区间[0,n)或0到结尾 ）
	//str.assign("12345678");//给字符串对象str重新赋值
	//cout << str << endl;
	//str.assign("12345678", 6);//(注意，重新赋值区间[0,6) ）
	//cout << str << endl;
	////string& assign(const string& str);
	////string& assign(const string& str, size_t subpos, size_t sublen);//(注意，重新赋值区间[subpos,+=sublen)或subpos到结尾 ）
	//string str3("progma");
	//string::iterator it3 = str3.begin();
	//str.assign(str3);//类似于拷贝字符串（感觉这步不会常用，因为拷贝构造函数就可以完成）
	//cout << str << endl;
	//str.assign(str3, 4, 1);//从原字符串对象str选连续的片段给str2赋值
	//cout << str << 'w' << endl;
	//str.assign(str3, 4, 10);//从原字符串对象str选连续的片段给str2赋值
	//cout << str << 'w' << endl;
	////string& assign(InputItertor first,InputItertor last);
	//str.assign(it3 + 1, it3 + 6);
	//cout << str << endl;
	//char *p = "12345678";
	//str.assign(p + 1, p + 5);//（注意，字符指针也可以玩，并不一定需要迭代器指针）
	//cout << str << endl;
	//str.assign(str3.begin() + 1, str3.end() - 1);//必须是字符对象的相对开始位置和相对结束位置
	//cout << str << endl;

	//str.assign("it is string");
	//str2.assign("not");
	////八.下面是插入系列：
	////string& insert(size_t pos, const string& str);
	////string& insert(size_t pos, const string& str, size_t subpos, size_t sublen);
	//str.insert(6, str2);//从pos的下标位置开始插入str2，
	//cout << str << endl;
	//str.insert(3, str2, 0, 2); //从dstpos位置处插入从subpos开始插入sublen位
	//cout << str << endl;
	////string& insert(size_t pos, const char* s);
	////string& insert(size_t pos, const char* s, size_t n);
	//str.insert(6, "12345");//从下标为pos的位置插入字符串
	//cout << str << endl;
	//str.insert(6, "12345", 2);//从下标为pos的位置字符串的n位
	//cout << str << endl;
	////string& insert(size_t pos, size_t n, char c);
	////iterator insert(iterator p, size_t n, char c);
	////iterator insert(iterator p, char c);//（注意，迭代器p后面插入字符时的返回值是一个迭代器,且指向下一个字符）
	////iterator insert(iterator p, InputIterator first, InputIterator last);
	//str.insert(6, 10, 'w');//在pos的下标位置插入n个字符
	//cout << str << endl;
	//str.assign("it is string");
	//str2.assign("123456789");
	//it = str.begin() + 1;//t
	//cout << *it << endl;
	//it--;//（注意，string的迭代器还重载了"--"运算符）
	//cout << *it << endl;//i
	//it = str.insert(it + 1, 'w');//这里返回值是一个迭代器
	//cout << str << " " << *it << endl;
	//str.insert(it, 's');
	//cout << str << " " << *it << endl;
	//cout << endl << endl << endl;
	//str.insert(it + 2, str2.begin(), str2.begin() + 3);
	//cout << str << endl;

	////九.删除系列
	////string&erase(size_t pos = 0, size_t len = npos);//从pos下标位置起删除len个字符(注意，①删除区间[pos,+=len) ②len + pos < size()③形参带有默认值)
	////iterator erase(iterator p);//删除迭代器p所指向的那个字符
	////iterator erase(iterator first, iterator last);
	////void pop_back();//删除最后一个字符（c++11及其以后）
	//str.assign("it is string");
	////str.erase(2, 9);//删除区间[2,11)，这就导致最后一个字符不会被删除
	////str.erase(2);//删除从下标为pos到末尾的所有字符，最后一个字符也会被删除
	////it = str.erase(str.begin()+2);//删除一个字符后，迭代器会自动指向字符对象的下一个字符
	//it = str.erase(str.begin() + 1, str.end() - 1);//删除一个字符串序列后，迭代器会自动指向修改了的字符对象后一位字符
	//cout << str << " " << *it << endl;

	////十.替换系列
	//str.assign("it is string");
	//str2.assign("example");
	////string& replace(size_t pos,size_t len,const string&str);
	////string& replace(size_t pos,size_t len,const string&str,size_t subpos,size_t sublen);
	////(注意：①0<=pos<=str.size() ②len>=0 ③需要被替换掉的区间[pos,+=len)或pos到结尾④需要替换上来的区间[subpos,+=sublen)或subpos到结尾 )
	//str.replace(3, 2, str2);
	//cout << str << endl;
	//str.replace(3, 100, str2, 2, 21); //(注意，如果len=0,就相当于在pos前面插入)
	//cout << str << endl;
	////string& replace(size_t pos,size_t len,const char *s);
	////string& replace(size_t pos,size_t len,const char *s,size_t n);
	//str.replace(3, 2, "a");
	//cout << str << endl;
	//str.replace(3, 2, "123456789", 5);
	//cout << str << endl;
	////string& replace(size_t pos,size_t len,size_t n,char ch);
	//str.replace(3, 2, 5, 'w');
	//cout << str << endl;

	//str.assign("it is string");//(注意，替换区间是[it1,it2) )
	//str2.assign("example");
	//it = str.begin();
	////string& replace(iterator it1,iterator it2,InputIterator first,InputIterator last);
	////string& replace(iterator it1,iterator it2,const string&str);
	////string& replace(iterator it1,iterator it2,const char *s);
	////string& replace(iterator it1,iterator it2,const char *s,size_t n);
	////string& replace(iterator it1,iterator it2,size_t n,char ch);
	//str.replace(it + 3, it + 5, str2.begin() + 2, str2.begin() + 4);
	//cout << str << endl;
	//str.replace(it + 3, it + 4, str2);
	//cout << str << endl;
	//str.replace(it + 3, it + 11, "12345");
	//cout << str << endl;
	//str.replace(it + 3, it + 8, "123456789", 5);
	//cout << str << endl;
	//str.replace(it + 3, it + 8, 5, 'w');
	//cout << str << endl;

	////十一.查找系列(find(),rfind(),find_first_of(),find_last_of(),find_first_not_of(),find_last_not_of(),substr() )
	//str.assign("it is string");


	////十二.void swap(string& str);
	////十三.Non-member function overload (operator+(),swap(),operator>>(),operator<<(),比较函数， )
	////
}

//////template <class Alloc> class vector<bool, Alloc>;               // bool specialization
#include<vector>//向量:它是一个可以动态增长的数组(T*_a,size_t _size = 0,size_t _capacity = 0)
//template < class T, class Alloc = allocator<T> > class vector; // generic template
void test_vector()
{
	//一.默认成员函数
	vector<int> v0;//调用默认构造函数（可以无参数）
	vector<int> v1(10);//调用构造函数（可以只有一个容量参数）
	for (size_t i = 0; i < v1.size(); ++i)
		v1[i] = i;
	for (size_t i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	vector<int> v4(3, 100);//调用构造函数（可以有一个容量参数和值）
	for (size_t i = 0; i < v4.size(); ++i)
		cout << v4[i] << " ";
	cout << endl;
	vector<int> v2(v1.begin() + 1, v1.end() - 1);//调用构造函数（可以是两个迭代器做参数）
	for (size_t i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
	int arr[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	vector<int> v5(arr + 1, arr + 8);//调用构造函数（可以是两个指针做参数）
	for (size_t i = 0; i < v5.size(); ++i)
		cout << v5[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	vector<int> v3(v2);//调用拷贝构造函数（一个vector对象做参数）
	v0 = v1;//调用赋值运算符的重载


	//二.迭代器的使用
	vector<int>::iterator it = v0.begin();//正向迭代器
	for (; it != v0.end(); ++it)
		cout << *it << " ";
	cout << endl;
	vector<int>::reverse_iterator rit = v0.rbegin();//反向迭代器
	for (; rit != v0.rend(); ++rit)
		cout << *rit << " ";
	cout << endl;
	//三.(size(); capacity(); empty(); resize(); reserve(); clear(); max_size();)
	v0.clear();
	v0.push_back(5);
	v0.push_back(5);
	v0.push_back(5);
	v0.push_back(5);
	cout << "size of v0:" << v0.size() << endl;//4
	cout << "capacity of v0:" << v0.capacity() << endl;//10
	cout << "v0 Is empty:" << v0.empty() << endl;
	cout << v0.max_size() << endl;

	//四.(resize(); reserve(); )
	//void resize(size_type n,value_type val = value_type());
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	v0.resize(4, 6);//如果n<=size(),这句代码等价于v0.resize(4);
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	v0.resize(11/*,6*/);//如果n>=size()或>=capacity(),
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//void reserve(size_type n);
	v0.reserve(12);//如果n<=capacity(),那么该句代码无效
	cout << v0.size() << " " << v0.capacity() << endl;

	v0.reserve(18);//如果n>capacity(),那么就会扩容
	cout << v0.size() << " " << v0.capacity() << endl;

	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;

	//五.能像数组一样访问数据
	//reference operator[](size_type n);//(注意，n一定要小于size() )
	//const_reference operator[](size_type n)const;
	v0[10] = 6;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	//reference at(size_type n); //(注意，n一定要小于size() )
	//const_reference at(size_type n)const;
	v0[9] = 6;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	//value_type*data()noexcept; //返回一个指向数组首元素的指针(c++11及其以后)
	//const value_type*data()const noexcept;
	int *p = v0.data();
	*(p + 5) = 6;
	p[6] = 7;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;

	//reference front();
	//const_reference front()const;
	//reference back();
	//const_reference back()const;
	cout << v0.front() << endl;//获取数组的第一个数据
	cout << v0.back() << endl;//获取数据的最后一个数据
	//六.对数组的修改
	//void assign(size_type n,const value_type& val)//重新赋n个valw
	v0.assign(3, 100);
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//void assign(InputIterator first,InputIterator last)//既可以是迭代器又可以是指针
	v0.assign(v1.begin() + 1, v1.end() - 1);//①迭代器
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	int arr0[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	v0.assign(arr0 + 1, arr0 + 8);//②指针
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//void push_back(const value_type& val);//尾插
	v0.push_back(11);
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//void pop_back();//尾删
	v0.pop_back();
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//iterator insert(iterator pos,const value_type& val);//返回的迭代器就指向pos位置
	it = v0.insert(v0.begin() + 2, 100);
	cout << *it << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//iterator insert(iterator pos,size_type n,const value_type& val);//返回的迭代器就指向pos位置
	it = v0.insert(v0.begin(), 3, 20);
	cout << *it << " " << *(it + 3) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//iterator insert(iterator pos,InputIterator first,InputIterator last);//返回的迭代器就指向pos位置
	it = v0.insert(v0.begin() + 1, v0.begin() + 1, v0.end() - 1);//①迭代器
	cout << *it << " " << *(it + 11) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	int arr2[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	it = v0.insert(v0.begin(), arr2 + 1, arr2 + 8);//②指针(指针是天然的迭代器)
	cout << *it << " " << *(it + 11) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//iterator erase(iterator pos);//删除迭代器pos指向的那一个数据(返回值是相对向后移了一位的迭代器)
	it = v0.erase(v0.begin() + 2);
	cout << *it << " " << *(it + 5) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//iterator erase(InputIterator first,InputIterator last);//删除[first,last)区间里的数据
	it = v0.erase(v0.begin() + 2, v0.begin() + 5);
	cout << *it << " " << *(it + 5) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//void swap(vector& v);

	//七.Non-member function overload (swap(); 整个数组的比较大小函数)

	////vector<int> v(5);
	////vector<int>::iterator it = v.begin();
	////vector<int>::iterator it2 = v.begin();
	////cout << *(it + 2) << endl;
	////it += 2;
	////cout << *it << endl;
	////cout << it - it2 << endl;
	////cout << it2 - it << endl;
	////int arr[10];
	////int *p1 = arr + 1, *p2 = arr + 5;
	////cout << p1 - p2 << endl;
	////cout << p2 - p1 << endl;
	////vector<int>::reverse_iterator rit = v.rbegin();
	////vector<int>::reverse_iterator rit2 = v.rbegin();
	////if (rit > rit2);//可以
	//////rit - 3;//错
}

#include<stack>//适配栈，后进先出(没有迭代器)
//template <class T, class Container = deque<T> > class stack
void test_stack()
{
	stack<int> s;//调用构造函数
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	stack<int> s2(s);//调用拷贝构造函数
	while (!s2.empty())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << endl;
	stack<int> s3;
	s3 = s;//调用赋值运算符重载函数
	while (!s3.empty())
	{
		cout << s3.top() << " ";
		s3.pop();
	}
	cout << endl;
	//bool empty()const;//判断栈是否为空
	//size_t size()const;//反回栈中存在元素个数
	//value_type top();//返回栈顶的元素
	//const value_type top()const;
	//void push(const value_type& val);//向栈顶插入元素
	//void pop();//移除栈顶元素
}

#include<queue>//适配队列(没有迭代器)
//template <class T, class Container = deque<T> > class queue
void test_queue()//①一般队列，先进先出 ②优先级队列优先级最高的先出(顶层用来堆的思想)
{
	queue<int> q;//调用构造函数
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	queue<int> q2(q);//调用拷贝构造函数
	while (!q2.empty())
	{
		cout << q2.front() << " ";
		q2.pop();
	}
	cout << endl;
	queue<int> q3;
	q3 = q;//调用赋值运算符重载函数
	while (!q3.empty())
	{
		cout << q3.front() << " ";
		q3.pop();
	}
	cout << endl;
	//bool empty()const;//判断d队列是否为空
	//size_t size()const;//返回栈中存在元素个数
	// /*const*/ value_type& front()/*const*/; // 获取队头的元素
	// /*const*/ value_type& back()/*const*/; // 获取队尾的元素
	//void push(const value_type& val);//向队尾插入元素
	//void pop();//移除队头元素

	priority_queue<int> pq;

	//bool empty()const;//判断d队列是否为空
	//size_t size()const;//返回栈中存在元素个数
	// /*const*/ value_type top&()/*const*/; // 获取队列里优先级最高的元素
	//void push(const value_type& val);//向队列中插入一个元素，使得该队列还是优先级队列
	//void pop();//移除队列里优先级最高的元素

}
//template <class T, class Container = vector<T>,class Compare = less<typename Container::value_type> > class priority_queue
void test_priority_queue()
{
	priority_queue<int> pq;
	pq.push(5);
	pq.push(7);
	pq.push(4);
	pq.push(3);
	pq.push(8);
	pq.push(1);
	cout << pq.top() << endl;
}

#include<array>//数组
//template < class T, size_t N > class array

#include<deque>//双端队列
//template < class T, class Alloc = allocator<T> > class deque

#include<forward_list>//（我感觉forward_list是个带头不循环单链表）(c++11及其以后)
//template < class T, class Alloc = allocator<T> > class forward_list
void test_forward_list()
{
	//default (1)
	//	explicit forward_list(const allocator_type& alloc = allocator_type());
	//fill(2)
	//	explicit forward_list(size_type n);
	//  explicit forward_list(size_type n, const value_type& val,const allocator_type& alloc = allocator_type());
	//range(3)
	//	template <class InputIterator>
	//  forward_list(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type());
	//copy(4)
	//	forward_list(const forward_list& fwdlst);
	//  forward_list(const forward_list& fwdlst, const allocator_type& alloc);
	//move(5) 右值引用
	//	forward_list(forward_list&& fwdlst);
	//  forward_list(forward_list&& fwdlst, const allocator_type& alloc);
	//initializer list(6)
	//	forward_list(initializer_list<value_type> il,const allocator_type& alloc = allocator_type());
	forward_list<int> first;//(1)默认构造函数
	forward_list<int> second(3, 77);//(2)链表中有3个77
	forward_list<int> third(second.begin(), second.end());//(3)
	forward_list<int> forth(third);//(4)拷贝构造函数
	forward_list<int> six = { 6, 2, 3, 4, 5 };//(6)初始化列表
	//没有重载前置后置--;
	forward_list<int>::iterator it = six.begin();//使用迭代器(*it it->mem ++it it++ it1==it2 it1!=it2)
	for (; it != six.end(); ++it){
		cout << *it << " ";             //注意:forward_list没有反向迭代器
	}cout << endl;
	forward_list<int>::const_iterator it2 = six.begin();//使用const迭代器
	for (; it2 != six.end(); ++it2){
		cout << *it2 << " ";
	}cout << endl;
	for (int/*auto*/ &r : six){//使用范围for语句 (这个r绑定six容器里装着的值的类型)
		cout << r << " ";
	}cout << endl;

	cout << first.empty() << " " << six.empty() << endl;//判空（注意:forward_list不提供size()接口）
	cout << six.front() << endl;//Access first element （注意:不提供back()接口）
	six.clear();//将表清空
	cout << six.empty() << endl;
	//void resize(size_type n);//如果n小于表长，那么切掉后面部分；n>表长，那么一直插入最后一个结点
	//void resize(size_type n, const value_type& val);//如果小于同上；n>表长，那么插入以第二个参数为值的结点


	//range(1)
	//	template <class InputIterator>void assign(InputIterator first, InputIterator last);
	//fill(2)
	//	void assign(size_type n, const value_type& val);
	//initializer list(3)
	//	void assign(initializer_list<value_type> il);
	six.assign(forth.begin(), forth.end());//(1)
	for (auto&r : six){ cout << r << " "; }cout << endl;
	six.assign(5, 66);//(2)
	for (auto&r : six){ cout << r << " "; }cout << endl;
	six.assign({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });//(3)
	for (auto&r : six){ cout << r << " "; }cout << endl;

	six.push_front(11);//在表的开头插入一个元素   （注意:不提供push_back()接口）
	for (auto&r : six){ cout << r << " "; }cout << endl;
	six.pop_front();//删除表头的一个元素      （注意:不提供pop_back()接口）
	for (auto&r : six){ cout << r << " "; }cout << endl;

	//(1)
	//	iterator insert_after(const_iterator position, const value_type& val);
	//(2)
	//	iterator insert_after(const_iterator position, value_type&& val);
	//(3)
	//	iterator insert_after(const_iterator position, size_type n, const value_type& val);
	//(4)
	//	template <class InputIterator>
	//iterator insert_after(const_iterator position, InputIterator first, InputIterator last);
	//(5)
	//	iterator insert_after(const_iterator position, initializer_list<value_type> il);
	it = six.begin(); ++it; ++it;
	six.insert_after(it, 10);//(1)
	for (auto&r : six){ cout << r << " "; }cout << endl;
	six.insert_after(it, 3, 11);//(3)
	for (auto&r : six){ cout << r << " "; }cout << endl;
	six.insert_after(it, second.begin(), second.end());//(4)
	for (auto&r : six){ cout << r << " "; }cout << endl;
	six.insert_after(it, 15);//(1)
	for (auto&r : six){ cout << r << " "; }cout << endl;
	six.insert_after(it, { 21, 22, 23, 24, 25 });//(5)
	for (auto&r : six){ cout << r << " "; }cout << endl;


	//(1)iterator erase_after(const_iterator position);
	//(2)iterator erase_after(const_iterator position, const_iterator last);
	six.erase_after(it);//(1)
	for (auto&r : six){ cout << r << " "; }cout << endl;
	six.erase_after(it, six.end());//(2)
	for (auto&r : six){ cout << r << " "; }cout << endl;

	//void swap(forward_list& fwdlst);
	six.swap(second);
	for (auto&r : six){ cout << r << " "; }cout << endl;

}

#include<list>//双向带头循环链表
//template < class T, class Alloc = allocator<T> > class list
void test_list()
{
	//default (1)
	//	explicit list(const allocator_type& alloc = allocator_type());
	//fill(2)
	//	explicit list(size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type());
	//range(3)
	//	template <class InputIterator>list(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type());
	//copy(4)
	//	list(const list& x);
	list<int> first;//(1)默认构造函数
	list<int> second(3, 55);//(2)
	list<int> third(second.begin(), second.end());//(3)
	list<int> fourth(third);//(4)拷贝构造函数
	int arr[] = { 1, 2, 3, 4, 5 };
	list<int> fifth(arr, arr + sizeof(arr) / sizeof(arr[0]));//(3)

	for (auto &r : fifth){ cout << r << " "; }cout << endl;//范围for语句
	list<int>::iterator it = fifth.begin();//正向迭代器输出
	for (; it != fifth.end(); ++it){
		cout << *it << " ";
	}cout << endl;
	list<int>::reverse_iterator it2 = fifth.rbegin();//反向迭代器输出
	for (; it2 != fifth.rend(); ++it2){
		cout << *it2 << " ";
	}cout << endl;

	cout << fifth.empty() << endl;
	cout << fifth.size() << endl;
	cout << fifth.front() << " " << fifth.back() << endl;
	fifth.clear(); cout << fifth.empty() << endl;
	//void resize(size_type n, value_type val = value_type());
	fifth.resize(7);//if n<size(),截断到n;if n>size(),那么在后面添加val
	for (auto &r : fifth){ cout << r << " "; }cout << endl;

	//range(1)
	//	template <class InputIterator>void assign(InputIterator first, InputIterator last);
	//fill(2)
	//	void assign(size_type n, const value_type& val);
	fifth.assign(3, 55);//(2)
	for (auto &r : fifth){ cout << r << " "; }cout << endl;
	fifth.assign(arr, arr + 4);//(1)  [arr,arr+4)
	for (auto &r : fifth){ cout << r << " "; }cout << endl;

	//void push_front(const value_type& val); //insert at the begining
	//void pop_front();                       //delete first element
	//void push_back(const value_type& val);  //insert at the begining
	//void pop_back();                        //delete last element
	fifth.push_front(66); fifth.push_back(77);
	for (auto &r : fifth){ cout << r << " "; }cout << endl;
	fifth.pop_front(); fifth.pop_back();
	for (auto &r : fifth){ cout << r << " "; }cout << endl;

	//single element(1)
	//	iterator insert(iterator position, const value_type& val);
	//fill(2)
	//	void insert(iterator position, size_type n, const value_type& val);
	//range(3)
	//	template <class InputIterator>void insert(iterator position, InputIterator first, InputIterator last);
	it = fifth.begin(); ++it; ++it;
	fifth.insert(it, 8);//(1)
	for (auto &r : fifth){ cout << r << " "; }cout << endl;
	fifth.insert(it, 3, 7);//(2)
	for (auto &r : fifth){ cout << r << " "; }cout << endl;
	fifth.insert(it, arr, arr + 5);//(3)  [arr,arr+5)
	for (auto &r : fifth){ cout << r << " "; }cout << endl;

	//(1)iterator erase(iterator position);
	//(2)iterator erase(iterator first, iterator last);
	it = fifth.erase(it); //(1)
	for (auto &r : fifth){ cout << r << " "; }cout << endl;
	it = fifth.erase(it); //(1)
	for (auto &r : fifth){ cout << r << " "; }cout << endl;
	//--it; cout << *it << endl;//假如迭代器it指向尾，就不能向后++了；同理指向begin()
	it = fifth.end(); --it; cout << *it << endl;
	--it;
	list<int>::iterator it3 = fifth.begin(); ++it3; ++it3;
	it3 = fifth.erase(it3, it); //(2)   [it3,it)
	for (auto &r : fifth){ cout << r << " "; }cout << endl;
	cout << *it3 << endl;
}


#include<set>    //K模型
//template < class T,class Compare = less<T>,class Alloc = allocator<T>> class set;
void test_set()//去重k模型
{
	//empty(1)
	//	explicit set(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
	//range(2)
	//	template <class InputIterator>
	//set(InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
	//copy(3)
	//	set(const set& x);
	set<int> s1;//(1)
	int arr[] = { 1, 2, 3, 4, 5 };
	set<int> s2(arr, arr + 5);//(2)
	set<int> s3(s2.begin(), s2.end());//(2)
	set<int> s4(s3);//(3)

	for (const int &r : s4){ cout << r << " "; }cout << endl;//范围for语句
	set<int>::iterator it = s4.begin();//正向迭代器输出
	for (; it != s4.end(); ++it){
		cout << *it << " ";
	}cout << endl;
	set<int>::reverse_iterator it2 = s4.rbegin();//反向迭代器输出
	for (; it2 != s4.rend(); ++it2){
		cout << *it2 << " ";
	}cout << endl;

	//bool empty() const;
	//size_type size() const;
	cout << s1.empty() << " " << s4.empty() << endl;
	cout << s1.size() << " " << s4.size() << endl;

	//single element(1)
	//	pair<iterator, bool> insert(const value_type& val);//既返回插入值的位置，又返回bool值
	//with hint(2)
	//	iterator insert(iterator position, const value_type& val);//返回值是插入值的位置
	//range(3)
	//	template <class InputIterator>
	//void insert(InputIterator first, InputIterator last);
	cout << s4.insert(6).second << endl;//(1)
	it = s4.begin(); ++it, ++it;
	s4.insert(it, s4.end());//(3)额，实际上插入不进去，因为这是去重插入
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	int arr2[] = { 3, 7, 9, 10 };
	s4.insert(arr2, arr2 + 4);//(3)
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	auto it4 = s4.insert(it, 8);//(2)
	cout << "it4:" << *it4 << endl;
	it4 = s4.insert(it, 8);//(2)
	cout << "it4:" << *it4 << endl;
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	cout << *it << endl;

	//(1)
	//	void erase(iterator position);
	//(2)
	//	size_type erase(const value_type& val);//返回的是bool值
	//(3)
	//	void erase(iterator first, iterator last);
	s4.erase(it);//(1)
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	//s4.erase(it);迭代器失效了
	it = s4.begin(); ++it; ++it; ++it; ++it;
	set<int>::iterator it3 = s4.end(); --it3; --it3;
	s4.erase(it,it3);//(3)
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	cout << "size_type" << s4.erase(5) << endl;//(2)
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	cout << "size_type" << s4.erase(5) << endl; //(2)
	for (auto &r : s4){ cout << r << " "; }cout << endl;

	//void swap(set& x);
	//void clear();
	s4.swap(s3);
	for (auto &r : s3){ cout << r << " "; }cout << endl;
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	s4.clear();
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	s4.swap(s3);

	//iterator find(const value_type& val) const;//找到返回一个指向那位置的迭代器；否则返回end()。
	it4 = s4.find(4); cout << *it4 << endl;
	it4 = s4.find(5); 
	if (it4 == s4.end()){ cout << "hah" << endl; }
	//size_type count(const value_type& val) const;//找到返回1；否则返回0
	cout << s4.count(4) << endl;
	cout << s4.count(5) << endl;
	//iterator lower_bound(const value_type& val) const;//返回值是迭代器
	//iterator upper_bound(const value_type& val) const;//返回值是迭代器
	//pair<iterator, iterator> equal_range(const value_type& val) const;//返回值是迭代器
	cout << "s4:  ";
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	it = s4.lower_bound(4); cout << "4的下界： " << *it << endl;
	it = s4.upper_bound(4); cout << "4的上界： " << *it << endl;
	it = s4.lower_bound(3); cout << "3的下界： " << *it << endl;
	it = s4.upper_bound(3); cout << "3的上界： " << *it << endl;
	cout << endl;
	it = s4.equal_range(4).first; cout << "4的下界： " << *it << endl;
	it = s4.equal_range(4).second; cout << "4的上界： " << *it << endl;
	it = s4.equal_range(3).first; cout << "3的下界： " << *it << endl;
	it = s4.equal_range(3).second; cout << "3的上界： " << *it << endl;

	s4.erase(s4.lower_bound(3), s4.upper_bound(9));
	for (auto &r : s4){ cout << r << " "; }cout << endl;
}
//template < class T,class Compare = less<T>,class Alloc = allocator<T> >> class multiset
void test_multiset()//不去重k模型
{
	//empty(1)
	//	explicit multiset(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
	//range(2)
	//	template <class InputIterator>
	//multiset(InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
	//copy(3)
	//	multiset(const multiset& x);
	multiset<int> ms1;//(1)
	int arr[] = { 1, 3, 5, 7, 9 };
	multiset<int> ms2(arr, arr + 5);//(2)
	multiset<int> ms3(ms2);//(3)
	for (const int &r : ms3){ cout << r << " "; }cout << endl;
	multiset<int>::iterator it = ms3.begin();
	while (it != ms3.end()){ cout << *it << " "; ++it; }cout << endl;
	auto it2 = ms3.rbegin();
	for (; it2 != ms3.rend();++it2){ cout << *it2 << " "; }cout << endl;

	//bool empty() const;
	cout << ms1.empty() << " " << ms3.empty() << endl;
	//size_type size() const;
	cout << ms1.size() << " " << ms3.size() << endl;

	//single element(1)
	//	iterator insert(const value_type& val);
	//with hint(2)
	//	iterator insert(iterator position, const value_type& val);
	//range(3)
	//	template <class InputIterator>void insert(InputIterator first, InputIterator last);
	cout << *(ms3.insert(3)) << " ";//(1)
	cout << *(ms3.insert(4)) << endl;//(1)
	for (const int &r : ms3){ cout << r << " "; }cout << endl;
	int arr1[] = { 1, 2, 3, 4 };
	ms3.insert(arr1, arr1 + 4);//(3)
	for (const int &r : ms3){ cout << r << " "; }cout << endl;
	it = ms3.begin(); ++it; ++it; ++it; ++it;
	auto it3 = ms3.insert(it, 6); cout << *it3 << endl;//(2)
	for (const int &r : ms3){ cout << r << " "; }cout << endl;

	//(1)void erase(iterator position);//删除迭代器指向的位置
	//(2)size_type erase(const value_type& val);//删除容器中全部的val （ps:注意）
	//(3)void erase(iterator first, iterator last);
	ms3.erase(it);
	//ms3.erase(it);//迭代器失效问题
	for (const int &r : ms3){ cout << r << " "; }cout << endl;
	ms3.erase(4);
	for (const int &r : ms3){ cout << r << " "; }cout << endl;
	it = ms3.begin(); ++it; ++it; ++it;
	it3 = ms3.end(); --it3; --it3; --it3;
	ms3.erase(it, it3);
	for (const int &r : ms3){ cout << r << " "; }cout << endl;

	//void swap(multiset& x);
	ms3.swap(ms2);
	for (const int &r : ms2){ cout << r << " "; }cout << endl;
	for (const int &r : ms3){ cout << r << " "; }cout << endl;
	//void clear();
	ms3.clear();
	for (const int &r : ms3){ cout << r << " "; }cout << endl;
	ms3.swap(ms2);

	//iterator find(const value_type& val) const;
	cout << *ms3.find(1) << endl;
	//size_type count(const value_type& val) const;
	cout << ms3.count(1) << endl;
	//iterator lower_bound(const value_type& val) const;
	//iterator upper_bound(const value_type& val) const;
	//pair<iterator, iterator> equal_range(const value_type& val) const;
	cout << "ms3:  ";
	for (auto &r : ms3){ cout << r << " "; }cout << endl;
	it = ms3.lower_bound(4); cout << "4的下界： " << *it << endl;
	it = ms3.upper_bound(4); cout << "4的上界： " << *it << endl;
	it = ms3.lower_bound(6); cout << "6的下界： " << *it << endl;
	it = ms3.upper_bound(6); cout << "6的上界： " << *it << endl;
	cout << endl;
	it = ms3.equal_range(4).first; cout << "4的下界： " << *it << endl;
	it = ms3.equal_range(4).second; cout << "4的上界： " << *it << endl;
	it = ms3.equal_range(6).first; cout << "6的下界： " << *it << endl;
	it = ms3.equal_range(6).second; cout << "6的上界： " << *it << endl;

	ms3.erase(ms3.lower_bound(3), ms3.upper_bound(9));
	for (auto &r : ms3){ cout << r << " "; }cout << endl;
}
#include<map>    //K,V模型
//template < class Key,class T,class Compare = less<Key>,class Alloc = allocator<pair<const Key, T> >> class map;
void test_map()//去重k,v模型
{
	//empty(1)
	//	explicit map(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
	//range(2)
	//	template <class InputIterator>
	//map(InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
	//copy(3)
	//	map(const map& x);
	map<int, int> m1;//(1)
	pair<const int, int> arr[] = { make_pair(1, 1), make_pair(3, 1), make_pair(5, 1), make_pair(7, 1), make_pair(9, 1) };
	map<int, int> m2(arr, arr + 5);//(2)
	map<int, int> m3(m2);// (3)

	for (pair<const int, int>&r : m3){ cout << r.first << " "; }cout << endl;
	auto it = m3.begin();
	for (; it != m3.end(); ++it){ cout << it->first << " "; }cout << endl;
	map<int, int>::reverse_iterator it2 = m3.rbegin();
	for (; it2 != m3.rend(); ++it2){ cout << it2->first << " "; }cout << endl;

	//bool empty() const;
	cout << m1.empty() << " " << m3.empty() << endl;
	//size_type size() const;
	cout << m1.size() << " " << m3.size() << endl;

	//single element(1)
	//	pair<iterator, bool> insert(const value_type& val);//返回的pair<iterator,bool>,前面的迭代器指向刚插入的位置；后面的bool值表明是否插入成功
	//with hint(2)
	//	iterator insert(iterator position, const value_type& val);//返回的迭代器指向刚插入的位置
	//range(3)
	//	template <class InputIterator>void insert(InputIterator first, InputIterator last);
	cout << m3.insert(make_pair(5, 1)).second << endl;//(1)
	cout << m3.insert(make_pair(11, 1)).second << endl;//(1)
	it = m3.begin(); ++it; ++it;
	map<int ,int>::iterator it3 = m3.insert(it, make_pair(3, 1));//(2)
	cout << it->first << " " << it3->first << endl;
	pair<const int, int> arr1[] = { make_pair(11, 1), make_pair(13, 1), make_pair(15, 1), make_pair(17, 1), make_pair(19, 1) };
	m3.insert(arr1, arr1 + 5);//(3)
	for (pair<const int, int> &r : m3){ cout << r.first << " "; }cout << endl;

	//(1)void erase(iterator position);
	//(2)size_type erase(const key_type& k);//返回值表示成功删除元素
	//(3)void erase(iterator first, iterator last);
	m3.erase(it);//(1)
	for (pair<const int, int> &r : m3){ cout << r.first << " "; }cout << endl;
	cout << m3.erase(3) << " ";//(2)
	cout << m3.erase(3) << endl;//(2)
	for (pair<const int, int> &r : m3){ cout << r.first << " "; }cout << endl;
	it = m3.begin(); ++it; ++it; ++it;
	it3 = m3.end(); --it3; --it3; --it3;
	m3.erase(it, it3);
	for (pair<const int, int> &r : m3){ cout << r.first << " "; }cout << endl;

	//iterator find(const key_type& k);//如果能找到返回该位置，否则返回end().
	//const_iterator find(const key_type& k) const;
	it = m3.find(7);cout << it->first << endl;
	it = m3.find(3);
	if (it == m3.end()){ cout << "hah" << endl; }
	//size_type count(const key_type& k) const;//如果能找到返回1，否则返回0
	cout << m3.count(7)<<" ";
	cout << m3.count(3) << endl;
	//①iterator lower_bound(const key_type& k);
	//②const_iterator lower_bound(const key_type& k) const;
	//①iterator upper_bound(const key_type& k);
	//②const_iterator upper_bound(const key_type& k) const;
	//①pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
	//②pair<iterator, iterator>             equal_range(const key_type& k);
	cout << "m3:  ";
	for (pair<const int, int> &r : m3){ cout << r.first << " "; }cout << endl;
	it = m3.lower_bound(9); cout << "9的下界： " << it->first << endl;
	it = m3.upper_bound(9); cout << "9的上界： " << it->first << endl;
	it = m3.lower_bound(13); cout << "13的下界： " << it->first << endl;
	it = m3.upper_bound(13); cout << "13的上界： " << it->first << endl;
	cout << endl;
	it = m3.equal_range(9).first; cout << "9的下界： " << it->first << endl;
	it = m3.equal_range(9).second; cout << "9的上界： " << it->first << endl;
	it = m3.equal_range(13).first; cout << "13的下界： " << it->first << endl;
	it = m3.equal_range(13).second; cout << "13的上界： " << it->first << endl;

	m3.erase(m3.lower_bound(3), m3.upper_bound(9));
	for (pair<const int, int> &r : m3){ cout << r.first << " "; }cout << endl;

	//mapped_type& operator[] (const key_type& k);
	//(*((this->insert(make_pair(k, mapped_type()))).first)).second
	m3[1]++;
	int i = int();
	cout << "i->" << i << endl;
}
//template < class Key,class T,class Compare = less<Key>,class Alloc = allocator<pair<const Key, T> >> class multimap;
void test_multimap()//不去重k,v模型
{
	//empty(1)
	//	explicit multimap(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
	//range(2)
	//	template <class InputIterator>multimap(InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
	//copy(3)
	//	multimap(const multimap& x);
	multimap<int, int> mm1;//(1)
	pair<const int, int> arr[] = { make_pair(1, 1), make_pair(3, 1), make_pair(5, 1), make_pair(7, 1), make_pair(9, 1), };
	multimap<int, int> mm2(arr, arr + 5);
	multimap<int, int> mm3(mm2);
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
	map<int, int>::iterator it = mm3.begin();
	for (; it != mm3.end(); ++it){ cout << it->first << " "; }cout << endl;
	auto it2 = mm3.rbegin();
	for (; it2 != mm3.rend(); ++it2){ cout << it2->first << " "; }cout << endl;

	//bool empty() const;
	cout << mm1.empty() << " " << mm3.empty() << endl;
	//size_type size() const;
	cout << mm1.size() << " " << mm3.size() << endl;

	//single element(1)
	//	iterator insert(const value_type& val);
	//with hint(2)
	//	iterator insert(iterator position, const value_type& val);
	//range(3)
	//	template <class InputIterator>void insert(InputIterator first, InputIterator last);
	mm3.insert(make_pair(2, 1));//(1)
	mm3.insert(make_pair(3, 1));//(1)
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
	mm3.insert(mm2.begin(), mm2.end());//(3)
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
	it = mm3.begin(); ++it; ++it; ++it; ++it;
	multimap<int,int>::iterator it3 = mm3.insert(it, make_pair(4, 1));//(2)
	cout << it3->first << endl;
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;

	//(1)void erase(iterator position);
	//(2)size_type erase(const key_type& k);//注意：删除所有的k
	//(3)void erase(iterator first, iterator last);
	mm3.erase(it);//(1)
	mm3.erase(it3);//(1)
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
	mm3.erase(5);//(2)
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
	it = mm3.begin(); ++it; ++it; ++it;
	it3 = mm3.end(); --it3; --it3; --it3;
	mm3.erase(it, it3);
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;

	//void swap(multimap& x);
	mm3.swap(mm2);
	for (pair<const int, int> &r : mm2){ cout << r.first << " "; }cout << endl;
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
	//void clear();
	mm3.clear();
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
	mm3.swap(mm2);

	//①iterator find(const key_type& k);
	//②const_iterator find(const key_type& k) const;
	it = mm3.find(1); cout << it->first << endl;
	//size_type count(const key_type& k) const
	cout << mm3.count(1) << endl;

	//①iterator lower_bound(const key_type& k);
	//②const_iterator lower_bound(const key_type& k) const;
	//①iterator upper_bound(const key_type& k);
	//②const_iterator upper_bound(const key_type& k) const;
    //①pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
    //②pair<iterator, iterator>             equal_range(const key_type& k);
	cout << "mm3:  ";
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
	it = mm3.lower_bound(5); cout << "5的下界： " << it->first << endl;
	it = mm3.upper_bound(5); cout << "5的上界： " << it->first << endl;
	it = mm3.lower_bound(7); cout << "7的下界： " << it->first << endl;
	it = mm3.upper_bound(7); cout << "7的上界： " << it->first << endl;
	cout << endl;
	it = mm3.equal_range(5).first; cout << "5的下界： " << it->first << endl;
	it = mm3.equal_range(5).second; cout << "5的上界： " << it->first << endl;
	it = mm3.equal_range(7).first; cout << "7的下界： " << it->first << endl;
	it = mm3.equal_range(7).second; cout << "7的上界： " << it->first << endl;

	mm3.erase(mm3.lower_bound(3), mm3.upper_bound(9));
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
}

#include<unordered_set>
//template < class Key,class Hash = hash<Key>,class Pred = equal_to<Key>,class Alloc = allocator<Key> 
void test_unorder_set()
{
	//empty(1)
	//	explicit unordered_set(size_type n = 0,const hasher& hf = hasher(),const key_equal& eql = key_equal(),const allocator_type& alloc = allocator_type());
	//    explicit unordered_set(const allocator_type& alloc);
	//range(2)
	//	template <class InputIterator>
	//unordered_set(InputIterator first, InputIterator last,
	//	size_type n = /* see below */,
	//	const hasher& hf = hasher(),
	//	const key_equal& eql = key_equal(),
	//	const allocator_type& alloc = allocator_type());
	//copy(3)
	//	unordered_set(const unordered_set& ust);
	//unordered_set(const unordered_set& ust, const allocator_type& alloc);
	//////////////////////move(4)
	//////////////////////	unordered_set(unordered_set&& ust);
	//////////////////////unordered_set(unordered_set&& ust, const allocator_type& alloc);
	//initializer list(5)
	//	unordered_set(initializer_list<value_type> il,
	//	size_type n = /* see below */,
	//	const hasher& hf = hasher(),
	//	const key_equal& eql = key_equal(),
	//	const allocator_type& alloc = allocator_type());
	unordered_set<int> first;//(1)
	unordered_set<int> second({ 1, 2, 3, 4, 5 ,11,5,33,12});//(5)
	unordered_set<int> third(++++second.begin(), ----second.end());//(2)
	unordered_set<int> fourth(second);//(3)
	for (const int &r : second){ cout << r << " "; }cout << endl;
	unordered_set<int>::iterator it = second.begin();
	for (; it != second.end(); ++it){ cout << *it << " "; }cout << endl;
	for (const int &r : third){ cout << r << " "; }cout << endl;

	//bool empty() const noexcept;
	cout << first.empty() << " " << fourth.empty() << endl;
	//size_type size() const noexcept;
	cout << first.size() << " " << fourth.size() << endl;

	//iterator find(const key_type& k);
	//const_iterator find(const key_type& k) const;
	it = fourth.find(5);
	if (it != fourth.end())cout << "it exists" << endl;
	else cout << "it isn't here" << endl;
	//size_type count(const key_type& k) const;
	if (fourth.count(3))cout << "it exists" << endl;
	else cout << "it isn't here" << endl;
	//pair<iterator, iterator>equal_range(const key_type& k);
	//pair<const_iterator, const_iterator>equal_range(const key_type& k) const;
	auto it2 = fourth.equal_range(3).first;
	auto it3 = fourth.equal_range(3).second;
	cout << *it2 << " " << *it3 << endl;
	//it2 = fourth.equal_range(6).first;
	//it3 = fourth.equal_range(6).second;
	//cout << *it2 << " " << *it3 << endl;//这两个指针都指向end()？？？

	//size_type bucket(const key_type& k) const;//得到关键值k在第几个桶子里
	//size_type bucket_size(size_type n) const//得到第n个桶的值的个数
	//size_type bucket_count() const noexcept;//得到桶的数量
	for (size_t i = 0; i <=20 /*fourth.bucket_count()*/; ++i)
	{
		cout << i << "is in bucket" << ":" << fourth.bucket(i) << " ";
		cout << "bucket_size" << i << ":" << fourth.bucket_size(i) << endl;
	}

	//float load_factor() const noexcept;//得到负载因子
	//void rehash(size_type n);//Set number of buckets
	//void reserve(size_type n);//Request a capacity change

	//hasher hash_function() const;//Returns the hash function object used by the unordered_set container
	//key_equal key_eq() const;//Returns the key equivalence comparison predicate used by the unordered_set container.
	//allocator_type get_allocator() const noexcept;
}
//void test_unorder_multiset()
//{
//
//}
#include<unordered_map>
void test_unorder_map()
{

}
void test_unorder_multimap()
{
	unordered_multimap<char, pair<string,int>> ump;
	ump.insert({ 'b', make_pair("aaa",1)});
	ump.insert({ 'b', make_pair("aaa", 2) });
	ump.insert({ 'b', make_pair("bbb", 3) });
	ump.insert({ 'c', make_pair("bbb", 4) });
	
	for (auto& x : ump)
		std::cout << x.first << ": " << x.second.first << x.second.second << std::endl;
}


#include<algorithm>
void test_algorithm()
{

}
void test_draft4()
{
	//string name;
	//while (cin >> name)//这里可以一直输入，
	//	cout << "wwwww" << endl;
	//                                        ①string class
	//test_string();
	//string str("12345565789");
	//str.erase(str.rfind('5'));
	//cout << str << endl;

	//                                        ②Sequence containers:
	//test_vector();
	//test_array();     //还没写
	//test_deque();     //还没写
	//test_forward_list();//还没写
	//test_list();

	//                                        ③Container adaptors:
	//test_stack();
	//test_queue();
	//test_priority_queue();

	//                                        ④Associative containers:
	//test_set();
	//test_multiset();
	//test_map();
	//test_multimap();

	//                                        ⑤Unordered associative containers:
	//test_unorder_set();
	//test_unorder_multiset();//还没写
	//test_unorder_map();
	test_unorder_multimap();//还没写
}