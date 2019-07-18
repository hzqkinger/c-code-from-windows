#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>


//仿函数定制             
struct __TrueType
{
	bool Get()
	{
		return true;
	}
};                     //__IsPodtType就是 类__TrueType 或 类__FalseType 的别名
struct __FalseType
{
	bool Get()
	{
		return false;
	}
};

//类模板             //typedef的作用是给类__TrueType 或 类__FalseType取别名__IsPodtType，然后这个别名成为类TypeTraits的成员
template<class _Tp>  //然后只有类TypeTraits可以用它的成员__IsPodtType（将类__TrueType 或 类__FalseType雪藏了，即用户无需知道）
struct TypeTraits
{
	//typedef false __IsPodtType;//①typedef真正的意思是给类型取别名（注意：仅仅是类型）

	typedef __FalseType __IsPodtType;//②
};

//Copy(s1, s2, 10, TypeTraits<string>().__IsPodtType);//①编译不通过

//Copy(s1, s2, 10, TypeTraits<string>::__IsPodtType());//②编译通过


//类模板的全特化
template<>//①
struct TypeTraits<bool>
{
	typedef __TrueType __IsPodtType;
};
template<>//②
struct TypeTraits<char>
{
	typedef __TrueType __IsPodtType;
};
template<>//③
struct TypeTraits<unsigned char>
{
	typedef __TrueType __IsPodtType;
};
template<>//④
struct TypeTraits<short>
{
	typedef __TrueType __IsPodtType;
};
template<>//⑤
struct TypeTraits<unsigned short>
{
	typedef __TrueType __IsPodtType;
};
template<>//⑥
struct TypeTraits<int>
{
	typedef __TrueType __IsPodtType;
};
template<>//⑦
struct TypeTraits<unsigned int>
{
	typedef __TrueType __IsPodtType;
};
template<>//⑧
struct TypeTraits<long>
{
	typedef __TrueType __IsPodtType;
};
template<>//⑨
struct TypeTraits<unsigned long>
{
	typedef __TrueType __IsPodtType;
};
template<>//10
struct TypeTraits<long long>
{
	typedef __TrueType __IsPodtType;
};
template<>//11
struct TypeTraits<unsigned long long>
{
	typedef __TrueType __IsPodtType;
};
template<>//12
struct TypeTraits<float>
{
	typedef __TrueType __IsPodtType;
};
template<>//13
struct TypeTraits<double>
{
	typedef __TrueType __IsPodtType;
};
template<>//14
struct TypeTraits<long double>
{
	typedef __TrueType __IsPodtType;
};

//传第四个参数仅仅仅是为了构成重载（跟前置后置++的思想一样）
template<class T>//①
void Copy(T*dst, const T*src, size_t size, __FalseType/* fa = __FalseType()*/)
{                                     //设置一个默认参数（注意：这两个对应的函数只能有一个设置默认参数）
	//cout << "__FalseType:" << typeid(T).name() << endl;
	cout << "__FalseType" << endl;//非普通类型
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}
template<class T>//②
void Copy(T*dst, const T*src, size_t size, __TrueType)
{
	//cout << "__TrueType" << typeid(T).name() << endl;
	cout << "__TrueType" << endl;//普通类型

	memcpy(dst, src, size*sizeof(T));
}

//将上面两个函数整合成一个函数，且少了一个参数,是因为定制了仿函数。
template<class T>//③
void Copy(T*dst, const T*src, size_t size)
{
	if (TypeTraits<T>::__IsPodtType().Get())  //定制的仿函数是要用在这里。
	{
		cout << "__TrueType" << endl;//普通类型
		memcpy(dst, src, size*sizeof(T));
	}
	else
	{
		cout << "__FalseType" << endl;//非普通类型
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}
void test()
{
	//还是定制了仿函数好，在这里实际调用的时候可以少传参，增强用户的使用性。
	string s1[10] = { "1", "2", "3", "4444444444444444444444444444" };
	string s2[10] = { "11", "22", "33" };
	//Copy(s1, s2, 10, TypeTraits<string>::__IsPodtType());
	Copy(s1, s2, 10);//假如在特定位置设置了默认参数，上面的与这等价。

	//int a1[10] = { 1, 2, 3 };
	//int a2[10] = { 0 };
	//Copy(a1, a2, 10, TypeTraits<int>::__IsPodtType());
	////Copy(a1, a2, 10);

}

int main()
{
	test();

	system("pause");
	return 0;
}