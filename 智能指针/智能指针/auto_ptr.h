#pragma once

template<class T>
class Auto_ptr
{
public:
	//RAII��˼��
	Auto_ptr(T *ptr)
		:_ptr(ptr)
	{}
	~Auto_ptr()
	{
		delete _ptr;//�������ָ������ָ��new�����Ŀռ�
		_ptr = NULL;
	}
	//����ָͨ��һ��
	T&operator*()
	{
		return *_ptr;
	}
	T*operator->()
	{
		return _ptr;
	}
	//��˼��һ������Ȩת�ƣ�������ָ��ָ��ͬһ��ռ�����
	Auto_ptr(Auto_ptr<T>&ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}
	Auto_ptr<T>&operator=(Auto_ptr<T>&ap)
	{
		if (this != &ap)
		{
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
private:
	T* _ptr;
};

