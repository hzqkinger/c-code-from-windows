#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>

struct TrueType{};//���������������
struct FalseType{};//��������Զ�������
template<class T>struct TypeTraits  //����������������е�����
{
	typedef FalseType PodType;
};
template<>struct TypeTraits<char>  //�ػ�����char����
{
	typedef TrueType PodType;
};
template<>struct TypeTraits<int>  //�ػ�����int����
{
	typedef TrueType PodType;
};

template<class T>void _Copy(T* dst, T* src, size_t size, TrueType)//����������������
{
	memcpy(dst, src, size*sizeof(T));
}
template<class T>void _Copy(T* dst, T* src, size_t size, FalseType)//������·�Զ�������
{
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}
template<class T>void Copy(T* dst, T* src, size_t size)//����������������
{
	_Copy(dst, src, size, TypeTraits<T>::PodType());
}
//�ڱ����ڼ��ȷ����Copy����Ҫ�����Ǹ�_copy������Ч�ʼ���ߡ�

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