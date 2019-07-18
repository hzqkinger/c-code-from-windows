#pragma once

template<class T>
class Scoped_ptr
{
public:
	//RAII的思想
	Scoped_ptr(T*ptr)
		:_ptr(ptr)
	{}
	~Scoped_ptr()
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
	//（思想二：防拷贝，赋值）定义删除函数
	Scoped_ptr(const Scoped_ptr<T>&ap) = delete;
	Scoped_ptr<T>&operator=(const Scoped_ptr<T>&ap) = delete;
private:
	////（思想二：防拷贝，赋值）在私有下，只声明不定义
	//Scoped_ptr(const Scoped_ptr<T>&ap);
	//Scoped_ptr<T>&operator=(const Scoped_ptr<T>&ap);

private:
	T* _ptr;
};