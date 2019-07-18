#pragma once

#include<assert.h>
#include <stdarg.h>

//template<class charT,class traits = char_traits<charT>,class Alloc = allocator<charT>> class basic_string;
//typedef basic_string<char> string
#include<string>//�ַ���:����һ�����Զ�̬���ַ�����char*_str,size_t _size = 0,size_t _capacity = 16��
//����˵����һ����̬�������ַ�����//��ʼ��_size=0��_capacity = 16//if��Ҫ���ݣ�_capacity+=16(�������������)
void test_string()
{
	string str("it is string");//���캯��

	//һ.�ַ��������ϵ��
	cout << str << endl;                //1.����ֱ���������Ϊ������operator<<�������
	string::iterator it = str.begin();  //2.�������������ַ�
	for (; it != str.end(); ++it)
		cout << *it;
	cout << endl;

	for (size_t i = 0; i < str.size(); ++i)//������һ������ַ�������Ϊ������operator[]�������
		cout << str[i];
	cout << endl;

	string::reverse_iterator rit = str.rbegin();  //3.�������������ַ�
	for (; rit != str.rend(); ++rit)
		cout << *rit;
	cout << endl;
	//const char* c_str()const;
	cout << str.c_str() << endl;              //8.����ָ����ַ�����ָ��
	//const char* data()const;
	cout << str.data() << endl;

	//��. size();length();capacity();clear();empty();max_size()
	cout << "size:" << str.size() << endl;//4.size()��length()���Ƿ����ַ����ĳ���
	cout << "length:" << str.length() << endl;
	cout << "capacity:" << str.capacity() << endl;      //5.���ظ��ַ������������
	//cout << str.max_size() << endl;      //����һ���ַ���������ж೤�ĳ��ȣ������ã���Ϊû������壩

	cout << str.empty() << endl;         //6.�жϸ��ַ����Ƿ�Ϊ��
	//str.clear();                         //7.�����ַ������
	//cout << str.empty() << endl;
	//cout << str.c_str() << endl;
	//cout << "size:" << str.size() << endl;
	//cout << "capacity:" << str.capacity() << endl;

	//��.�ı��ַ�������_size�Ĵ�Сresize()//ԭ�ַ��� str.size() = 12;str.capacity() = 15;
	//void resize(size_t n);
	//void resize(size_t n,char ch)
	//str.resize(9,'+');//���ַ����ĳ��ȱ�Ϊ9����ifԭ���ĳ��ȴ���9����ô��ͬ��str.resize(9)��
	//str.resize(13, '+');//���ַ����ĳ��ȱ�Ϊ13��ifԭ���ĳ���С��13����ô��ԭ���ַ����油���ַ���+��ֱ���ַ�������Ϊ13ֹ��
	//str.resize(13);//���ַ����ĳ��ȱ�Ϊ13��ifԭ���ĳ���С��13����ô��ԭ���ַ����油�Ͽո��ַ���
	//str.resize(16, '+');//Ч����ͬ������Ϊ13�����
	//cout << str << endl;
	//cout << "size:" << str.size() << endl;
	//cout << "capacity:" << str.capacity() << endl;
	//��.�ı��ַ�������_capacity�Ĵ�Сreserve()
	//void reserve(size_t n);
	//str.reserve(9);//����ַ�����ԭ������������9����������ʲô��������
	//str.reserve(18);//If n is greater than the current string capacity, the function causes the container to increase its capacity to n characters(or greater).
	//cout << "size:" << str.size() << endl;
	//cout << "capacity:" << str.capacity() << endl;

	////��.������ͨ�ַ���һ��֧���������
	////char& operator[] (size_t pos);
	////const char& operator[] (size_t pos) const;
	//cout << str[6] << endl;//11.����[],���ַ�����һ��֧��������� (ע�⣬stringû������*)
	//str[6] = 'S';
	//for (size_t i = 0; i < str.size(); ++i)
	//	cout << str[i];
	//cout << endl;
	////char& at(size_t pos);
	////const char& at(size_t pos) const;//12.�������
	//cout << str.at(6) << endl;
	//str.at(6) = 'W';
	//for (size_t i = 0; i < str.size(); ++i)
	//	cout << str.at(i);
	//cout << endl;

	//cout << str.front();       //(c++11�Ժ�֧��)13.�����ַ����ĵ�һ���ַ��������һ���ַ�
	//cout << str.back() << endl;

	////��.�������������ַ���ĩβ��׷��ϵ��
	//string str2("progma");
	//string::iterator it2 = str2.begin();
	////string& operator+=(char ch);
	////string& operator+=(const char *s);
	////string& operator+=(const string& str);
	//str += '1';
	//str += "23";        //14.Append to string 
	//str += str2;
	//cout << str << endl;
	////string& append(size_t n,char ch);//��ע�ⲻ�ܹ�append(char ch),��Ϊstring��û������ӿڣ�
	////string& append(const char *s);
	////string& append(const char *s,size_t n);
	////string& append(const string& str);
	////string& append(const string& str,size_t subpos,size_t sublen);
	////string& append(InputIterator first,InputIterator last);//(ע��,firstһ��Ҫ���ڻ����last,��������)
	//str.append(1, '4');
	//str.append("56");     //15.���ַ�������׷�����ַ���  Append to string 
	//str.append("789101112131415", 2);
	//str.append(str2);
	//str.append(str2, 0, 3);
	//str.append(it2 + 3, it2 + 5);//(ע�⣬׷��������[first,last) )
	//cout << str << "      " << *(it2 + 5) << endl;
	//str.push_back('W');   //16.Append character to string
	//cout << str << endl;
	//str.assign("it is string");
	//char *p2 = "123456789";
	//str.append(p2, p2 + 3);//(ע�⣬��һ��Ҫ�ǵ�������Ҳ�������ַ�ָ�룬׷������[p2,p2+3) )
	//cout << str << endl;

	////��.���¸�ֵϵ��
	////string& assign(size_t n,char ch);
	//str.assign(6, 'w');
	//cout << str << endl;
	////string& assign(const char* s);
	////string& assign(const char* s, size_t n);//(ע�⣬���¸�ֵ����[0,n)��0����β ��
	//str.assign("12345678");//���ַ�������str���¸�ֵ
	//cout << str << endl;
	//str.assign("12345678", 6);//(ע�⣬���¸�ֵ����[0,6) ��
	//cout << str << endl;
	////string& assign(const string& str);
	////string& assign(const string& str, size_t subpos, size_t sublen);//(ע�⣬���¸�ֵ����[subpos,+=sublen)��subpos����β ��
	//string str3("progma");
	//string::iterator it3 = str3.begin();
	//str.assign(str3);//�����ڿ����ַ������о��ⲽ���᳣�ã���Ϊ�������캯���Ϳ�����ɣ�
	//cout << str << endl;
	//str.assign(str3, 4, 1);//��ԭ�ַ�������strѡ������Ƭ�θ�str2��ֵ
	//cout << str << 'w' << endl;
	//str.assign(str3, 4, 10);//��ԭ�ַ�������strѡ������Ƭ�θ�str2��ֵ
	//cout << str << 'w' << endl;
	////string& assign(InputItertor first,InputItertor last);
	//str.assign(it3 + 1, it3 + 6);
	//cout << str << endl;
	//char *p = "12345678";
	//str.assign(p + 1, p + 5);//��ע�⣬�ַ�ָ��Ҳ�����棬����һ����Ҫ������ָ�룩
	//cout << str << endl;
	//str.assign(str3.begin() + 1, str3.end() - 1);//�������ַ��������Կ�ʼλ�ú���Խ���λ��
	//cout << str << endl;

	//str.assign("it is string");
	//str2.assign("not");
	////��.�����ǲ���ϵ�У�
	////string& insert(size_t pos, const string& str);
	////string& insert(size_t pos, const string& str, size_t subpos, size_t sublen);
	//str.insert(6, str2);//��pos���±�λ�ÿ�ʼ����str2��
	//cout << str << endl;
	//str.insert(3, str2, 0, 2); //��dstposλ�ô������subpos��ʼ����sublenλ
	//cout << str << endl;
	////string& insert(size_t pos, const char* s);
	////string& insert(size_t pos, const char* s, size_t n);
	//str.insert(6, "12345");//���±�Ϊpos��λ�ò����ַ���
	//cout << str << endl;
	//str.insert(6, "12345", 2);//���±�Ϊpos��λ���ַ�����nλ
	//cout << str << endl;
	////string& insert(size_t pos, size_t n, char c);
	////iterator insert(iterator p, size_t n, char c);
	////iterator insert(iterator p, char c);//��ע�⣬������p��������ַ�ʱ�ķ���ֵ��һ��������,��ָ����һ���ַ���
	////iterator insert(iterator p, InputIterator first, InputIterator last);
	//str.insert(6, 10, 'w');//��pos���±�λ�ò���n���ַ�
	//cout << str << endl;
	//str.assign("it is string");
	//str2.assign("123456789");
	//it = str.begin() + 1;//t
	//cout << *it << endl;
	//it--;//��ע�⣬string�ĵ�������������"--"�������
	//cout << *it << endl;//i
	//it = str.insert(it + 1, 'w');//���ﷵ��ֵ��һ��������
	//cout << str << " " << *it << endl;
	//str.insert(it, 's');
	//cout << str << " " << *it << endl;
	//cout << endl << endl << endl;
	//str.insert(it + 2, str2.begin(), str2.begin() + 3);
	//cout << str << endl;

	////��.ɾ��ϵ��
	////string&erase(size_t pos = 0, size_t len = npos);//��pos�±�λ����ɾ��len���ַ�(ע�⣬��ɾ������[pos,+=len) ��len + pos < size()���βδ���Ĭ��ֵ)
	////iterator erase(iterator p);//ɾ��������p��ָ����Ǹ��ַ�
	////iterator erase(iterator first, iterator last);
	////void pop_back();//ɾ�����һ���ַ���c++11�����Ժ�
	//str.assign("it is string");
	////str.erase(2, 9);//ɾ������[2,11)����͵������һ���ַ����ᱻɾ��
	////str.erase(2);//ɾ�����±�Ϊpos��ĩβ�������ַ������һ���ַ�Ҳ�ᱻɾ��
	////it = str.erase(str.begin()+2);//ɾ��һ���ַ��󣬵��������Զ�ָ���ַ��������һ���ַ�
	//it = str.erase(str.begin() + 1, str.end() - 1);//ɾ��һ���ַ������к󣬵��������Զ�ָ���޸��˵��ַ������һλ�ַ�
	//cout << str << " " << *it << endl;

	////ʮ.�滻ϵ��
	//str.assign("it is string");
	//str2.assign("example");
	////string& replace(size_t pos,size_t len,const string&str);
	////string& replace(size_t pos,size_t len,const string&str,size_t subpos,size_t sublen);
	////(ע�⣺��0<=pos<=str.size() ��len>=0 ����Ҫ���滻��������[pos,+=len)��pos����β����Ҫ�滻����������[subpos,+=sublen)��subpos����β )
	//str.replace(3, 2, str2);
	//cout << str << endl;
	//str.replace(3, 100, str2, 2, 21); //(ע�⣬���len=0,���൱����posǰ�����)
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

	//str.assign("it is string");//(ע�⣬�滻������[it1,it2) )
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

	////ʮһ.����ϵ��(find(),rfind(),find_first_of(),find_last_of(),find_first_not_of(),find_last_not_of(),substr() )
	//str.assign("it is string");


	////ʮ��.void swap(string& str);
	////ʮ��.Non-member function overload (operator+(),swap(),operator>>(),operator<<(),�ȽϺ����� )
	////
}

//////template <class Alloc> class vector<bool, Alloc>;               // bool specialization
#include<vector>//����:����һ�����Զ�̬����������(T*_a,size_t _size = 0,size_t _capacity = 0)
//template < class T, class Alloc = allocator<T> > class vector; // generic template
void test_vector()
{
	//һ.Ĭ�ϳ�Ա����
	vector<int> v0;//����Ĭ�Ϲ��캯���������޲�����
	vector<int> v1(10);//���ù��캯��������ֻ��һ������������
	for (size_t i = 0; i < v1.size(); ++i)
		v1[i] = i;
	for (size_t i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	vector<int> v4(3, 100);//���ù��캯����������һ������������ֵ��
	for (size_t i = 0; i < v4.size(); ++i)
		cout << v4[i] << " ";
	cout << endl;
	vector<int> v2(v1.begin() + 1, v1.end() - 1);//���ù��캯����������������������������
	for (size_t i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
	int arr[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	vector<int> v5(arr + 1, arr + 8);//���ù��캯��������������ָ����������
	for (size_t i = 0; i < v5.size(); ++i)
		cout << v5[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	vector<int> v3(v2);//���ÿ������캯����һ��vector������������
	v0 = v1;//���ø�ֵ�����������


	//��.��������ʹ��
	vector<int>::iterator it = v0.begin();//���������
	for (; it != v0.end(); ++it)
		cout << *it << " ";
	cout << endl;
	vector<int>::reverse_iterator rit = v0.rbegin();//���������
	for (; rit != v0.rend(); ++rit)
		cout << *rit << " ";
	cout << endl;
	//��.(size(); capacity(); empty(); resize(); reserve(); clear(); max_size();)
	v0.clear();
	v0.push_back(5);
	v0.push_back(5);
	v0.push_back(5);
	v0.push_back(5);
	cout << "size of v0:" << v0.size() << endl;//4
	cout << "capacity of v0:" << v0.capacity() << endl;//10
	cout << "v0 Is empty:" << v0.empty() << endl;
	cout << v0.max_size() << endl;

	//��.(resize(); reserve(); )
	//void resize(size_type n,value_type val = value_type());
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	v0.resize(4, 6);//���n<=size(),������ȼ���v0.resize(4);
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	v0.resize(11/*,6*/);//���n>=size()��>=capacity(),
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//void reserve(size_type n);
	v0.reserve(12);//���n<=capacity(),��ô�þ������Ч
	cout << v0.size() << " " << v0.capacity() << endl;

	v0.reserve(18);//���n>capacity(),��ô�ͻ�����
	cout << v0.size() << " " << v0.capacity() << endl;

	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;

	//��.��������һ����������
	//reference operator[](size_type n);//(ע�⣬nһ��ҪС��size() )
	//const_reference operator[](size_type n)const;
	v0[10] = 6;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	//reference at(size_type n); //(ע�⣬nһ��ҪС��size() )
	//const_reference at(size_type n)const;
	v0[9] = 6;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	//value_type*data()noexcept; //����һ��ָ��������Ԫ�ص�ָ��(c++11�����Ժ�)
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
	cout << v0.front() << endl;//��ȡ����ĵ�һ������
	cout << v0.back() << endl;//��ȡ���ݵ����һ������
	//��.��������޸�
	//void assign(size_type n,const value_type& val)//���¸�n��valw
	v0.assign(3, 100);
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//void assign(InputIterator first,InputIterator last)//�ȿ����ǵ������ֿ�����ָ��
	v0.assign(v1.begin() + 1, v1.end() - 1);//�ٵ�����
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	int arr0[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	v0.assign(arr0 + 1, arr0 + 8);//��ָ��
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//void push_back(const value_type& val);//β��
	v0.push_back(11);
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//void pop_back();//βɾ
	v0.pop_back();
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//iterator insert(iterator pos,const value_type& val);//���صĵ�������ָ��posλ��
	it = v0.insert(v0.begin() + 2, 100);
	cout << *it << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//iterator insert(iterator pos,size_type n,const value_type& val);//���صĵ�������ָ��posλ��
	it = v0.insert(v0.begin(), 3, 20);
	cout << *it << " " << *(it + 3) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//iterator insert(iterator pos,InputIterator first,InputIterator last);//���صĵ�������ָ��posλ��
	it = v0.insert(v0.begin() + 1, v0.begin() + 1, v0.end() - 1);//�ٵ�����
	cout << *it << " " << *(it + 11) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	int arr2[] = { 4, 5, 6, 1, 2, 3, 7, 8, 9, 0 };
	it = v0.insert(v0.begin(), arr2 + 1, arr2 + 8);//��ָ��(ָ������Ȼ�ĵ�����)
	cout << *it << " " << *(it + 11) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//iterator erase(iterator pos);//ɾ��������posָ�����һ������(����ֵ������������һλ�ĵ�����)
	it = v0.erase(v0.begin() + 2);
	cout << *it << " " << *(it + 5) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;
	//iterator erase(InputIterator first,InputIterator last);//ɾ��[first,last)�����������
	it = v0.erase(v0.begin() + 2, v0.begin() + 5);
	cout << *it << " " << *(it + 5) << endl;
	for (size_t i = 0; i < v0.size(); ++i)
		cout << v0[i] << " ";
	cout << endl;
	cout << v0.size() << " " << v0.capacity() << endl;

	//void swap(vector& v);

	//��.Non-member function overload (swap(); ��������ıȽϴ�С����)

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
	////if (rit > rit2);//����
	//////rit - 3;//��
}

#include<stack>//����ջ������ȳ�(û�е�����)
//template <class T, class Container = deque<T> > class stack
void test_stack()
{
	stack<int> s;//���ù��캯��
	s.push(1);
	s.push(1);
	s.push(1);
	s.push(1);
	stack<int> s2(s);//���ÿ������캯��
	while (!s2.empty())
	{
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << endl;
	stack<int> s3;
	s3 = s;//���ø�ֵ��������غ���
	while (!s3.empty())
	{
		cout << s3.top() << " ";
		s3.pop();
	}
	cout << endl;
	//bool empty()const;//�ж�ջ�Ƿ�Ϊ��
	//size_t size()const;//����ջ�д���Ԫ�ظ���
	//value_type top();//����ջ����Ԫ��
	//const value_type top()const;
	//void push(const value_type& val);//��ջ������Ԫ��
	//void pop();//�Ƴ�ջ��Ԫ��
}

#include<queue>//�������(û�е�����)
//template <class T, class Container = deque<T> > class queue
void test_queue()//��һ����У��Ƚ��ȳ� �����ȼ��������ȼ���ߵ��ȳ�(���������ѵ�˼��)
{
	queue<int> q;//���ù��캯��
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	queue<int> q2(q);//���ÿ������캯��
	while (!q2.empty())
	{
		cout << q2.front() << " ";
		q2.pop();
	}
	cout << endl;
	queue<int> q3;
	q3 = q;//���ø�ֵ��������غ���
	while (!q3.empty())
	{
		cout << q3.front() << " ";
		q3.pop();
	}
	cout << endl;
	//bool empty()const;//�ж�d�����Ƿ�Ϊ��
	//size_t size()const;//����ջ�д���Ԫ�ظ���
	// /*const*/ value_type& front()/*const*/; // ��ȡ��ͷ��Ԫ��
	// /*const*/ value_type& back()/*const*/; // ��ȡ��β��Ԫ��
	//void push(const value_type& val);//���β����Ԫ��
	//void pop();//�Ƴ���ͷԪ��

	priority_queue<int> pq;

	//bool empty()const;//�ж�d�����Ƿ�Ϊ��
	//size_t size()const;//����ջ�д���Ԫ�ظ���
	// /*const*/ value_type top&()/*const*/; // ��ȡ���������ȼ���ߵ�Ԫ��
	//void push(const value_type& val);//������в���һ��Ԫ�أ�ʹ�øö��л������ȼ�����
	//void pop();//�Ƴ����������ȼ���ߵ�Ԫ��

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

#include<array>//����
//template < class T, size_t N > class array

#include<deque>//˫�˶���
//template < class T, class Alloc = allocator<T> > class deque

#include<forward_list>//���Ҹо�forward_list�Ǹ���ͷ��ѭ��������(c++11�����Ժ�)
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
	//move(5) ��ֵ����
	//	forward_list(forward_list&& fwdlst);
	//  forward_list(forward_list&& fwdlst, const allocator_type& alloc);
	//initializer list(6)
	//	forward_list(initializer_list<value_type> il,const allocator_type& alloc = allocator_type());
	forward_list<int> first;//(1)Ĭ�Ϲ��캯��
	forward_list<int> second(3, 77);//(2)��������3��77
	forward_list<int> third(second.begin(), second.end());//(3)
	forward_list<int> forth(third);//(4)�������캯��
	forward_list<int> six = { 6, 2, 3, 4, 5 };//(6)��ʼ���б�
	//û������ǰ�ú���--;
	forward_list<int>::iterator it = six.begin();//ʹ�õ�����(*it it->mem ++it it++ it1==it2 it1!=it2)
	for (; it != six.end(); ++it){
		cout << *it << " ";             //ע��:forward_listû�з��������
	}cout << endl;
	forward_list<int>::const_iterator it2 = six.begin();//ʹ��const������
	for (; it2 != six.end(); ++it2){
		cout << *it2 << " ";
	}cout << endl;
	for (int/*auto*/ &r : six){//ʹ�÷�Χfor��� (���r��six������װ�ŵ�ֵ������)
		cout << r << " ";
	}cout << endl;

	cout << first.empty() << " " << six.empty() << endl;//�пգ�ע��:forward_list���ṩsize()�ӿڣ�
	cout << six.front() << endl;//Access first element ��ע��:���ṩback()�ӿڣ�
	six.clear();//�������
	cout << six.empty() << endl;
	//void resize(size_type n);//���nС�ڱ�����ô�е����沿�֣�n>������ôһֱ�������һ�����
	//void resize(size_type n, const value_type& val);//���С��ͬ�ϣ�n>������ô�����Եڶ�������Ϊֵ�Ľ��


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

	six.push_front(11);//�ڱ�Ŀ�ͷ����һ��Ԫ��   ��ע��:���ṩpush_back()�ӿڣ�
	for (auto&r : six){ cout << r << " "; }cout << endl;
	six.pop_front();//ɾ����ͷ��һ��Ԫ��      ��ע��:���ṩpop_back()�ӿڣ�
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

#include<list>//˫���ͷѭ������
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
	list<int> first;//(1)Ĭ�Ϲ��캯��
	list<int> second(3, 55);//(2)
	list<int> third(second.begin(), second.end());//(3)
	list<int> fourth(third);//(4)�������캯��
	int arr[] = { 1, 2, 3, 4, 5 };
	list<int> fifth(arr, arr + sizeof(arr) / sizeof(arr[0]));//(3)

	for (auto &r : fifth){ cout << r << " "; }cout << endl;//��Χfor���
	list<int>::iterator it = fifth.begin();//������������
	for (; it != fifth.end(); ++it){
		cout << *it << " ";
	}cout << endl;
	list<int>::reverse_iterator it2 = fifth.rbegin();//������������
	for (; it2 != fifth.rend(); ++it2){
		cout << *it2 << " ";
	}cout << endl;

	cout << fifth.empty() << endl;
	cout << fifth.size() << endl;
	cout << fifth.front() << " " << fifth.back() << endl;
	fifth.clear(); cout << fifth.empty() << endl;
	//void resize(size_type n, value_type val = value_type());
	fifth.resize(7);//if n<size(),�ضϵ�n;if n>size(),��ô�ں������val
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
	//--it; cout << *it << endl;//���������itָ��β���Ͳ������++�ˣ�ͬ��ָ��begin()
	it = fifth.end(); --it; cout << *it << endl;
	--it;
	list<int>::iterator it3 = fifth.begin(); ++it3; ++it3;
	it3 = fifth.erase(it3, it); //(2)   [it3,it)
	for (auto &r : fifth){ cout << r << " "; }cout << endl;
	cout << *it3 << endl;
}


#include<set>    //Kģ��
//template < class T,class Compare = less<T>,class Alloc = allocator<T>> class set;
void test_set()//ȥ��kģ��
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

	for (const int &r : s4){ cout << r << " "; }cout << endl;//��Χfor���
	set<int>::iterator it = s4.begin();//������������
	for (; it != s4.end(); ++it){
		cout << *it << " ";
	}cout << endl;
	set<int>::reverse_iterator it2 = s4.rbegin();//������������
	for (; it2 != s4.rend(); ++it2){
		cout << *it2 << " ";
	}cout << endl;

	//bool empty() const;
	//size_type size() const;
	cout << s1.empty() << " " << s4.empty() << endl;
	cout << s1.size() << " " << s4.size() << endl;

	//single element(1)
	//	pair<iterator, bool> insert(const value_type& val);//�ȷ��ز���ֵ��λ�ã��ַ���boolֵ
	//with hint(2)
	//	iterator insert(iterator position, const value_type& val);//����ֵ�ǲ���ֵ��λ��
	//range(3)
	//	template <class InputIterator>
	//void insert(InputIterator first, InputIterator last);
	cout << s4.insert(6).second << endl;//(1)
	it = s4.begin(); ++it, ++it;
	s4.insert(it, s4.end());//(3)�ʵ���ϲ��벻��ȥ����Ϊ����ȥ�ز���
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
	//	size_type erase(const value_type& val);//���ص���boolֵ
	//(3)
	//	void erase(iterator first, iterator last);
	s4.erase(it);//(1)
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	//s4.erase(it);������ʧЧ��
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

	//iterator find(const value_type& val) const;//�ҵ�����һ��ָ����λ�õĵ����������򷵻�end()��
	it4 = s4.find(4); cout << *it4 << endl;
	it4 = s4.find(5); 
	if (it4 == s4.end()){ cout << "hah" << endl; }
	//size_type count(const value_type& val) const;//�ҵ�����1�����򷵻�0
	cout << s4.count(4) << endl;
	cout << s4.count(5) << endl;
	//iterator lower_bound(const value_type& val) const;//����ֵ�ǵ�����
	//iterator upper_bound(const value_type& val) const;//����ֵ�ǵ�����
	//pair<iterator, iterator> equal_range(const value_type& val) const;//����ֵ�ǵ�����
	cout << "s4:  ";
	for (auto &r : s4){ cout << r << " "; }cout << endl;
	it = s4.lower_bound(4); cout << "4���½磺 " << *it << endl;
	it = s4.upper_bound(4); cout << "4���Ͻ磺 " << *it << endl;
	it = s4.lower_bound(3); cout << "3���½磺 " << *it << endl;
	it = s4.upper_bound(3); cout << "3���Ͻ磺 " << *it << endl;
	cout << endl;
	it = s4.equal_range(4).first; cout << "4���½磺 " << *it << endl;
	it = s4.equal_range(4).second; cout << "4���Ͻ磺 " << *it << endl;
	it = s4.equal_range(3).first; cout << "3���½磺 " << *it << endl;
	it = s4.equal_range(3).second; cout << "3���Ͻ磺 " << *it << endl;

	s4.erase(s4.lower_bound(3), s4.upper_bound(9));
	for (auto &r : s4){ cout << r << " "; }cout << endl;
}
//template < class T,class Compare = less<T>,class Alloc = allocator<T> >> class multiset
void test_multiset()//��ȥ��kģ��
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

	//(1)void erase(iterator position);//ɾ��������ָ���λ��
	//(2)size_type erase(const value_type& val);//ɾ��������ȫ����val ��ps:ע�⣩
	//(3)void erase(iterator first, iterator last);
	ms3.erase(it);
	//ms3.erase(it);//������ʧЧ����
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
	it = ms3.lower_bound(4); cout << "4���½磺 " << *it << endl;
	it = ms3.upper_bound(4); cout << "4���Ͻ磺 " << *it << endl;
	it = ms3.lower_bound(6); cout << "6���½磺 " << *it << endl;
	it = ms3.upper_bound(6); cout << "6���Ͻ磺 " << *it << endl;
	cout << endl;
	it = ms3.equal_range(4).first; cout << "4���½磺 " << *it << endl;
	it = ms3.equal_range(4).second; cout << "4���Ͻ磺 " << *it << endl;
	it = ms3.equal_range(6).first; cout << "6���½磺 " << *it << endl;
	it = ms3.equal_range(6).second; cout << "6���Ͻ磺 " << *it << endl;

	ms3.erase(ms3.lower_bound(3), ms3.upper_bound(9));
	for (auto &r : ms3){ cout << r << " "; }cout << endl;
}
#include<map>    //K,Vģ��
//template < class Key,class T,class Compare = less<Key>,class Alloc = allocator<pair<const Key, T> >> class map;
void test_map()//ȥ��k,vģ��
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
	//	pair<iterator, bool> insert(const value_type& val);//���ص�pair<iterator,bool>,ǰ��ĵ�����ָ��ղ����λ�ã������boolֵ�����Ƿ����ɹ�
	//with hint(2)
	//	iterator insert(iterator position, const value_type& val);//���صĵ�����ָ��ղ����λ��
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
	//(2)size_type erase(const key_type& k);//����ֵ��ʾ�ɹ�ɾ��Ԫ��
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

	//iterator find(const key_type& k);//������ҵ����ظ�λ�ã����򷵻�end().
	//const_iterator find(const key_type& k) const;
	it = m3.find(7);cout << it->first << endl;
	it = m3.find(3);
	if (it == m3.end()){ cout << "hah" << endl; }
	//size_type count(const key_type& k) const;//������ҵ�����1�����򷵻�0
	cout << m3.count(7)<<" ";
	cout << m3.count(3) << endl;
	//��iterator lower_bound(const key_type& k);
	//��const_iterator lower_bound(const key_type& k) const;
	//��iterator upper_bound(const key_type& k);
	//��const_iterator upper_bound(const key_type& k) const;
	//��pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
	//��pair<iterator, iterator>             equal_range(const key_type& k);
	cout << "m3:  ";
	for (pair<const int, int> &r : m3){ cout << r.first << " "; }cout << endl;
	it = m3.lower_bound(9); cout << "9���½磺 " << it->first << endl;
	it = m3.upper_bound(9); cout << "9���Ͻ磺 " << it->first << endl;
	it = m3.lower_bound(13); cout << "13���½磺 " << it->first << endl;
	it = m3.upper_bound(13); cout << "13���Ͻ磺 " << it->first << endl;
	cout << endl;
	it = m3.equal_range(9).first; cout << "9���½磺 " << it->first << endl;
	it = m3.equal_range(9).second; cout << "9���Ͻ磺 " << it->first << endl;
	it = m3.equal_range(13).first; cout << "13���½磺 " << it->first << endl;
	it = m3.equal_range(13).second; cout << "13���Ͻ磺 " << it->first << endl;

	m3.erase(m3.lower_bound(3), m3.upper_bound(9));
	for (pair<const int, int> &r : m3){ cout << r.first << " "; }cout << endl;

	//mapped_type& operator[] (const key_type& k);
	//(*((this->insert(make_pair(k, mapped_type()))).first)).second
	m3[1]++;
	int i = int();
	cout << "i->" << i << endl;
}
//template < class Key,class T,class Compare = less<Key>,class Alloc = allocator<pair<const Key, T> >> class multimap;
void test_multimap()//��ȥ��k,vģ��
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
	//(2)size_type erase(const key_type& k);//ע�⣺ɾ�����е�k
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

	//��iterator find(const key_type& k);
	//��const_iterator find(const key_type& k) const;
	it = mm3.find(1); cout << it->first << endl;
	//size_type count(const key_type& k) const
	cout << mm3.count(1) << endl;

	//��iterator lower_bound(const key_type& k);
	//��const_iterator lower_bound(const key_type& k) const;
	//��iterator upper_bound(const key_type& k);
	//��const_iterator upper_bound(const key_type& k) const;
    //��pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
    //��pair<iterator, iterator>             equal_range(const key_type& k);
	cout << "mm3:  ";
	for (pair<const int, int> &r : mm3){ cout << r.first << " "; }cout << endl;
	it = mm3.lower_bound(5); cout << "5���½磺 " << it->first << endl;
	it = mm3.upper_bound(5); cout << "5���Ͻ磺 " << it->first << endl;
	it = mm3.lower_bound(7); cout << "7���½磺 " << it->first << endl;
	it = mm3.upper_bound(7); cout << "7���Ͻ磺 " << it->first << endl;
	cout << endl;
	it = mm3.equal_range(5).first; cout << "5���½磺 " << it->first << endl;
	it = mm3.equal_range(5).second; cout << "5���Ͻ磺 " << it->first << endl;
	it = mm3.equal_range(7).first; cout << "7���½磺 " << it->first << endl;
	it = mm3.equal_range(7).second; cout << "7���Ͻ磺 " << it->first << endl;

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
	//cout << *it2 << " " << *it3 << endl;//������ָ�붼ָ��end()������

	//size_type bucket(const key_type& k) const;//�õ��ؼ�ֵk�ڵڼ���Ͱ����
	//size_type bucket_size(size_type n) const//�õ���n��Ͱ��ֵ�ĸ���
	//size_type bucket_count() const noexcept;//�õ�Ͱ������
	for (size_t i = 0; i <=20 /*fourth.bucket_count()*/; ++i)
	{
		cout << i << "is in bucket" << ":" << fourth.bucket(i) << " ";
		cout << "bucket_size" << i << ":" << fourth.bucket_size(i) << endl;
	}

	//float load_factor() const noexcept;//�õ���������
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
	//while (cin >> name)//�������һֱ���룬
	//	cout << "wwwww" << endl;
	//                                        ��string class
	//test_string();
	//string str("12345565789");
	//str.erase(str.rfind('5'));
	//cout << str << endl;

	//                                        ��Sequence containers:
	//test_vector();
	//test_array();     //��ûд
	//test_deque();     //��ûд
	//test_forward_list();//��ûд
	//test_list();

	//                                        ��Container adaptors:
	//test_stack();
	//test_queue();
	//test_priority_queue();

	//                                        ��Associative containers:
	//test_set();
	//test_multiset();
	//test_map();
	//test_multimap();

	//                                        ��Unordered associative containers:
	//test_unorder_set();
	//test_unorder_multiset();//��ûд
	//test_unorder_map();
	test_unorder_multimap();//��ûд
}