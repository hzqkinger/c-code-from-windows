#pragma once

template<class T>
class Shared_array
{
public:
	//RAII��˼��
	Shared_array()//Ĭ�Ϲ��캯��
		:_ptr(NULL)
		, _refcount(new int())
	{}
	Shared_array(T*ptr)
		:_ptr(ptr)
		, _refcount(new int(1))
	{}
	~Shared_array()
	{
		if (--(*_refcount) == 0)
		{
			delete[] _ptr;
			delete _refcount;
		}
	}
	//����ָͨ��һ��
	T&operator[](size_t size)
	{
		return _ptr[size];
	}
	//��˼��һ������Ȩת�ƣ�������ָ��ָ��ͬһ��ռ�����
	Shared_array(Shared_array<T>&ap)
		:_ptr(ap._ptr)
		, _refcount(ap._refcount)
	{
		++(*_refcount);
	}
	Shared_array<T>&operator=(Shared_array<T>&ap)
	{
		if (_ptr != ap._ptr)//�ж����������Ƿ�ָ��ͬһ��ռ䣨��ֹ���Լ���ֵ��
		{
			if (--(*_refcount) == 0)
			{
				delete[] _ptr;
				delete _refcount;
			}
			_ptr = ap._ptr;
			_refcount = ap._refcount;
			(*_refcount)++;
		}
		return *this;
	}
private:
	T *_ptr;
	int *_refcount;
};