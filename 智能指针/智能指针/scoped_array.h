#pragma once

template<class T>
class Scoped_array
{
public:
	//RAII��˼��
	Scoped_array(T *ptr)
		:_ptr(ptr)
	{}
	~Scoped_array()
	{
		if (_ptr)
			delete[] _ptr;//�������ָ������ָ��new�����Ŀռ�

	}
	//����ָͨ��һ��
	T&operator[](size_t size)
	{
		return _ptr[size];
	}

private:
	//��˼���������������ֵ����˽���£�ֻ����������
	Scoped_array(const Scoped_array<T>&ap);
	Scoped_array<T>&operator=(const Scoped_array<T>&ap);

private:
	T* _ptr;
};