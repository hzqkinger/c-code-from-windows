#pragma once

template<class T>
class Auto_ptr
{
public:
	//RAII的思想
	Auto_ptr(T *ptr)
		:_ptr(ptr)
	{}
	~Auto_ptr()
	{
		delete _ptr;//这个智能指针智能指向new出来的空间
		_ptr = NULL;
	}
	//像普通指针一样
	T&operator*()
	{
		return *_ptr;
	}
	T*operator->()
	{
		return _ptr;
	}
	//（思想一：管理权转移）处理多个指针指向同一块空间问题
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

