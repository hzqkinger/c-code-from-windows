#pragma once

template<class T>
class Shared_array
{
public:
	//RAII的思想
	Shared_array()//默认构造函数
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
	//像普通指针一样
	T&operator[](size_t size)
	{
		return _ptr[size];
	}
	//（思想一：管理权转移）处理多个指针指向同一块空间问题
	Shared_array(Shared_array<T>&ap)
		:_ptr(ap._ptr)
		, _refcount(ap._refcount)
	{
		++(*_refcount);
	}
	Shared_array<T>&operator=(Shared_array<T>&ap)
	{
		if (_ptr != ap._ptr)//判断两个对象是否指向同一块空间（防止给自己赋值）
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