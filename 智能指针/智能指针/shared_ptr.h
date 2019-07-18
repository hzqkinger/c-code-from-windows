#pragma once

template<class T>
class Weak_ptr;

template<class T>
class Shared
{
public:
	friend Weak_ptr<T>;
	//RAII的思想
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
	Shared(Shared<T>& ap)
		:_ptr(ap._ptr)
		, _refcount(ap._refcount)
	{
		++(*_refcount);
	}
	Shared<T>&operator=(Shared<T>&ap)
	{
		if (_ptr != ap._ptr)//判断两个对象是否指向同一块空间（防止给自己赋值）
		{
			if (--(*_refcount) == 0)
			{            //①判断现在只想的空间是否还有其它指针指向②顺便把引用计数减一
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