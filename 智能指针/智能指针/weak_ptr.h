#pragma once

//Weak_ptrֻ����shared_ptrһ������ʹ�ã����ѭ����������
template<class T>
class Weak_ptr
{
public:
	//RAII��˼��
	Weak_ptr(const Shared<T>&sp = Shared<T>())
		:_ptr(sp._ptr)
	{}
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

	Weak_ptr<T>&operator=(Shared<T>&ap)
	{
		_ptr = ap._ptr;
		return *this;
	}
private:
	T *_ptr;
};