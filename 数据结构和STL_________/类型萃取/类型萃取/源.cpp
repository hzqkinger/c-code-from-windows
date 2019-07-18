#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>


//�º�������             
struct __TrueType
{
	bool Get()
	{
		return true;
	}
};                     //__IsPodtType���� ��__TrueType �� ��__FalseType �ı���
struct __FalseType
{
	bool Get()
	{
		return false;
	}
};

//��ģ��             //typedef�������Ǹ���__TrueType �� ��__FalseTypeȡ����__IsPodtType��Ȼ�����������Ϊ��TypeTraits�ĳ�Ա
template<class _Tp>  //Ȼ��ֻ����TypeTraits���������ĳ�Ա__IsPodtType������__TrueType �� ��__FalseTypeѩ���ˣ����û�����֪����
struct TypeTraits
{
	//typedef false __IsPodtType;//��typedef��������˼�Ǹ�����ȡ������ע�⣺���������ͣ�

	typedef __FalseType __IsPodtType;//��
};

//Copy(s1, s2, 10, TypeTraits<string>().__IsPodtType);//�ٱ��벻ͨ��

//Copy(s1, s2, 10, TypeTraits<string>::__IsPodtType());//�ڱ���ͨ��


//��ģ���ȫ�ػ�
template<>//��
struct TypeTraits<bool>
{
	typedef __TrueType __IsPodtType;
};
template<>//��
struct TypeTraits<char>
{
	typedef __TrueType __IsPodtType;
};
template<>//��
struct TypeTraits<unsigned char>
{
	typedef __TrueType __IsPodtType;
};
template<>//��
struct TypeTraits<short>
{
	typedef __TrueType __IsPodtType;
};
template<>//��
struct TypeTraits<unsigned short>
{
	typedef __TrueType __IsPodtType;
};
template<>//��
struct TypeTraits<int>
{
	typedef __TrueType __IsPodtType;
};
template<>//��
struct TypeTraits<unsigned int>
{
	typedef __TrueType __IsPodtType;
};
template<>//��
struct TypeTraits<long>
{
	typedef __TrueType __IsPodtType;
};
template<>//��
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

//�����ĸ�������������Ϊ�˹������أ���ǰ�ú���++��˼��һ����
template<class T>//��
void Copy(T*dst, const T*src, size_t size, __FalseType/* fa = __FalseType()*/)
{                                     //����һ��Ĭ�ϲ�����ע�⣺��������Ӧ�ĺ���ֻ����һ������Ĭ�ϲ�����
	//cout << "__FalseType:" << typeid(T).name() << endl;
	cout << "__FalseType" << endl;//����ͨ����
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}
template<class T>//��
void Copy(T*dst, const T*src, size_t size, __TrueType)
{
	//cout << "__TrueType" << typeid(T).name() << endl;
	cout << "__TrueType" << endl;//��ͨ����

	memcpy(dst, src, size*sizeof(T));
}

//�����������������ϳ�һ��������������һ������,����Ϊ�����˷º�����
template<class T>//��
void Copy(T*dst, const T*src, size_t size)
{
	if (TypeTraits<T>::__IsPodtType().Get())  //���Ƶķº�����Ҫ�������
	{
		cout << "__TrueType" << endl;//��ͨ����
		memcpy(dst, src, size*sizeof(T));
	}
	else
	{
		cout << "__FalseType" << endl;//����ͨ����
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}
void test()
{
	//���Ƕ����˷º����ã�������ʵ�ʵ��õ�ʱ������ٴ��Σ���ǿ�û���ʹ���ԡ�
	string s1[10] = { "1", "2", "3", "4444444444444444444444444444" };
	string s2[10] = { "11", "22", "33" };
	//Copy(s1, s2, 10, TypeTraits<string>::__IsPodtType());
	Copy(s1, s2, 10);//�������ض�λ��������Ĭ�ϲ��������������ȼۡ�

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