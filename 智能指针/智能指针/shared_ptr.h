#pragma once

template<class T>
class Weak_ptr;

template<class T>
class Shared
{
public:
	friend Weak_ptr<T>;
	//RAII��˼��
	Shared(T *ptr = NULL)
		:_ptr(ptr)
		, _refcount(new int(1))
	{}
	~Shared()
	{
		if (--(*_refcount) == 0)
		{
			delete _ptr;
			delete _refcount;
		}
		_ptr = NULL;
		_refcount = NULL;
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
	Shared(Shared<T>& ap)
		:_ptr(ap._ptr)
		, _refcount(ap._refcount)
	{
		++(*_refcount);
	}
	Shared<T>&operator=(Shared<T>&ap)
	{
		if (_ptr != ap._ptr)//�ж����������Ƿ�ָ��ͬһ��ռ䣨��ֹ���Լ���ֵ��
		{
			if (--(*_refcount) == 0)
			{            //���ж�����ֻ��Ŀռ��Ƿ�������ָ��ָ���˳������ü�����һ
				delete _ptr;
				delete _refcount;
				_ptr = NULL;
				_refcount = NULL;
			}
			_ptr = ap._ptr;
			_refcount = ap._refcount;
			++(*_refcount);
		}
		return *this;
	}
private:
	T *_ptr;
	int *_refcount;
};