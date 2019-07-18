#pragma once

template<class T>
class My_vector
{
	T *_start;
	T *_finish;
	T *_end;
public:
	typedef T* Iterator;
	typedef const T* const_Iterator;

	My_vector()
		:_start(0), _finish(0), _end(0)
	{}
	//�������캯��+��ֵ��������غ���

	//My_vector�ĵ�������begin��end
	Iterator Begin()
	{
		return _start;
	}
	const_Iterator Begin()const
	{
		return _start;
	}
	Iterator End()
	{
		return _finish;
	}
	const_Iterator End()const
	{
		return _finish;
	}

	T&operator[](size_t size)//��My_vector�Ķ���������һ��
	{
		return _start[size];
	}

	T&operator[](size_t size)const//��My_vector�Ķ���������һ��
	{
		return _start[size];
	}

	size_t Size()const
	{
		return _finish - _start;
	}
	size_t Capacity()const
	{
		return _end - _start;
	}

	void Resize(size_t n,const T& x = T())//Change size 
	{
		Reserve(n);//�ⲽ��֤��nһ��С��Capacity()
		if (n<_finish - _start)
		{
			_finish = _start + n;
		}
		else
		{
			while (_finish < _start + n)
			{
				*_finish++ = x;
			}
		}
	}
	void Reserve(size_t n)//�ռ�ֻ�����󲻻���С,Request a change in capacity
	{
		if (n>Capacity())
		{
			Expand(n);
		}
	}

	void Expand(size_t n)//ֱ�ӿ�n���ռ�
	{
		T *newstart = new T[n];
		size_t size = Size();//���������size��¼һ��֮ǰ�����ݸ�������ΪSize()��һֱ�ڱ仯��
		for (size_t i = 0; i < size; ++i)//��֤����һ����ȷ����ǳ�������⣩
		{
			newstart[i] = _start[i];
		}
		delete[] _start;
		_start = newstart;
		_finish = _start + size;
		_end = _start + n;
	}

	void Expand()
	{
		size_t size = Size();
		size_t capacity = Capacity();
		if (_finish == _end)
		{
			capacity = capacity > 0 ? capacity * 2 : 3;
			T *newstart = new T[capacity];
			for (size_t i = 0; i < size; ++i)
			{
				newstart[i] = _start[i];
			}
			_start = newstart;
			_finish = _start + size;
			_end = _start + capacity;
		}
	}
	//��ɾ���
	void PushBack(const T& x)
	{
		//if (_finish == _end)
		//{
		//	size_t capacity = Capacity();
		//	capacity = capacity > 0 ? capacity * 2 : 3;
		//	Expand(capacity);
		//}
		//*_finish = x;
		//++_finish;
		Insert(_finish, x);
	}
	void PopBack()
	{
		assert(_start == _finish);
		--_finish;
	}

	void Insert(Iterator pos, const T& x)//��Ҫ���������ʧЧ������
	{
		assert(pos >= _start && pos <= _finish);
		if (_finish == _end)//����Ҫ���ݣ���ô��������ʧЧ
		{
			size_t off = pos - _start;//��pos��ԭ�������е�ƫ����
			size_t capacity = Capacity();
			capacity = capacity > 0 ? capacity * 2 : 3;
			Expand(capacity);
			pos = _start + off;//���µ�����
		}

		Iterator pos1 = _finish++;
		while (pos1 != pos)
		{
			*pos1 = *(pos1 - 1);
			pos1--;
		}
		*pos = x;
	}
	Iterator Erase(Iterator pos)//����һ��ָ����һ��Ԫ�صĵ�����ָ��
	{
		assert(pos >= _start && pos < _finish);
		--_finish;
		Iterator pos1 = pos;
		while (pos1 != _finish)
		{
			*pos1 = *(pos1 + 1);
			pos1++;
		}
		return pos;
	}
};


template<class T>
void Printlist(const My_vector<T>& v)
{
	My_vector<T>::const_Iterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void testlist()
{
	//My_vector<int> v;
	//v.PushBack(1);
	//v.PushBack(2);
	//v.PushBack(6);
	//v.PushBack(4);
	//v.PushBack(5);
	//Printlist(v);

	//My_vector<int>::Iterator it = v.Begin();
	//v.Erase(it);

	//Printlist(v);
	//cout << *it <<endl;

	My_vector<string> v2;
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	v2.PushBack("aaaaaaaaaa");
	Printlist(v2);


}