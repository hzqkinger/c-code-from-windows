#pragma once

//Weak_ptr只能与shared_ptr一起配套使用，解决循环引用问题
template<class T>
class Weak_ptr
{
public:
	//RAII的思想
	Weak_ptr(const Shared<T>&sp = Shared<T>())
		:_ptr(sp._ptr)
	{}
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

	Weak_ptr<T>&operator=(Shared<T>&ap)
	{
		_ptr = ap._ptr;
		return *this;
	}
private:
	T *_ptr;
};