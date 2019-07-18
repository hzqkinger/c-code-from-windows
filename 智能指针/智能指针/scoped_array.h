#pragma once

template<class T>
class Scoped_array
{
public:
	//RAII的思想
	Scoped_array(T *ptr)
		:_ptr(ptr)
	{}
	~Scoped_array()
	{
		if (_ptr)
			delete[] _ptr;//这个智能指针智能指向new出来的空间

	}
	//像普通指针一样
	T&operator[](size_t size)
	{
		return _ptr[size];
	}

private:
	//（思想二：防拷贝，赋值）在私有下，只声明不定义
	Scoped_array(const Scoped_array<T>&ap);
	Scoped_array<T>&operator=(const Scoped_array<T>&ap);

private:
	T* _ptr;
};