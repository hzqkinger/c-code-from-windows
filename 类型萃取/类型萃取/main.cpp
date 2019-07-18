#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

struct TrueType{};//用来标记内置类型
struct FalseType{};//用来标记自定义类型
template<class T>struct TypeTraits  //这个类用来处理所有的类型
{
	typedef FalseType PodType;
};
template<>struct TypeTraits<char>  //特化处理char类型
{
	typedef TrueType PodType;
};
template<>struct TypeTraits<int>  //特化处理int类型
{
	typedef TrueType PodType;
};

template<class T>void _Copy(T* dst, T* src, size_t size, TrueType)//用来处理内置类型
{
	memcpy(dst, src, size*sizeof(T));
}
template<class T>void _Copy(T* dst, T* src, size_t size, FalseType)//用来出路自定义类型
{
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}
template<class T>void Copy(T* dst, T* src, size_t size)//用来处理所有类型
{
	_Copy(dst, src, size, TypeTraits<T>::PodType());
}
//在编译期间就确定了Copy函数要调用那个_copy函数，效率极其高。

int main()
{
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[4];
	Copy(arr2, arr1, sizeof(arr1) / sizeof(arr1[0]));

	string str1[] = { "111", "222", "333", "444" };
	string str2[4];
	Copy(str2, str1, sizeof(str1) / sizeof(str1[0]));

	system("pause");
	return 0;
}