#pragma once

template<class T>
class Scoped_ptr
{
public:
	//RAII��˼��
	Scoped_ptr(T*ptr)
		:_ptr(ptr)
	{}
	~Scoped_ptr()
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
	//��˼���������������ֵ������ɾ������
	Scoped_ptr(const Scoped_ptr<T>&ap) = delete;
	Scoped_ptr<T>&operator=(const Scoped_ptr<T>&ap) = delete;
private:
	////��˼���������������ֵ����˽���£�ֻ����������
	//Scoped_ptr(const Scoped_ptr<T>&ap);
	//Scoped_ptr<T>&operator=(const Scoped_ptr<T>&ap);

private:
	T* _ptr;
};