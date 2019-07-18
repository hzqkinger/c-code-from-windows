#pragma once

/////////////////////////////�����������ֻ�����ù��캯������ʼ���Ĺ���////////////////////////////////////
#include<new.h> //��ʹ��placement new,���Ȱ������ļ�
//5��ȫ�ֺ�����construct(),destroy(),uninitialized_copy(),uninitialized_fill(),uninitialized_fill_n()��
template<class T1,class T2>
inline void Construct(T1 *p, const T2& value)
{
	new(p)T1(value);//placement new  ���ù��캯��
}
template<class T>inline void Destory(T *pointer)//��һ���汾������һ��ָ��
{
	pointer->~T();//  ������������
}
template<class ForwardIterator>
inline void Destory(ForwardIterator first, ForwardIterator last)//�ڶ����汾����������������
{
	for (; first < last; ++first)
		Destory(&*first);//  ������������
}

template<class InputIterator,class ForwardIterator>
ForwardIterator Uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator result)
{
	ForwardIterator cur = result;
	for (; first != last; ++first, ++cur)
		Construct(&*cur, *first);//���ù��캯��
	return cur;
}
template<class ForwardIterator,class T>
void Uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& x)
{
	for (ForwardIterator cur = first; cur != last; ++cur)
		Construct(&*cur, x);//���ù��캯��
}
template<class ForwardIterator,class Size,class T>
ForwardIterator Uninitialized_fill_n(ForwardIterator first, Size n, T& x)
{
	ForwardIterator cur = first;
	for (; n > 0; --n, ++cur)
		Construct(&*cur, x);//���ù��캯��
	return cur;
}

////////////////////////////���������ռ�������ֻ������ռ�Ĺ���///////////////////////////////////////////
//��1������Ҫ����Ŀռ����128ʱ������Ϊ�������㹻��Ŀռ䣬ֱ�ӵ���һ���ռ�������
//һ���ռ�������������ʵ���ǣ�Allocate()��malloc()�ķ�װ��Deallocate()��free()�ķ�װ
//                ��ģ��C++��set_new_handler()�Դ����ڴ治���״��
typedef void(*HANDLE_FUNC) ();
template <int inst> // instance
class __MallocAllocTemplate
{
	static HANDLE_FUNC __malloc_alloc_oom_handler;//�������ָ��ͨ������NULL,�������Լ�����(�������Լ����÷ǿգ���Ϊ��������)
	static void* OOM_Malloc(size_t n)//���ھ������ָ��ͨ������NULL�����Խ����ú������������쳣
	{
		while (1)
		{
			if (__malloc_alloc_oom_handler == NULL)
			{
				throw bad_alloc();
			}
			//��ִ�е��������䣬˵���������ָ�뱻����������
			__malloc_alloc_oom_handler(); // �ͷ��ڴ�

			void* ret = malloc(n);
			if (ret)
				return ret;
		}
	}
public:
	static void* Allocate(size_t n)//��װmalloc()
	{
		void *result = malloc(n);//malloc returns a void pointer to the allocated space, or NULL if there is insufficient memory available.
	
		if (NULL == result)//����ڴ治�㣬�����OOM_Malloc���������Է���ռ�
			result = OOM_Malloc(n);

		return result;
	}
	static void Deallocate(void *p, size_t /* n */)//��װfree()
	{
		free(p);
	}
	static HANDLE_FUNC SetMallocHandler(HANDLE_FUNC f)//���þ������ָ��
	{
		HANDLE_FUNC old = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return old;
	}
};
template<int inst>
HANDLE_FUNC __MallocAllocTemplate<inst>::__malloc_alloc_oom_handler = NULL;//�������ָ��ĳ�ʼ��

//��2������Ҫ����Ŀռ�С�ڵ���128ʱ������Ϊ�������㹻С�Ŀռ䣬���ö����ռ�������
// �����ռ��������������ڴ�غ�һ����������
template <bool threads, int inst>
class __DefaultAllocTemplate
{
private:
	// �ڴ��
	static char* _startfree;
	static char* _endfree;
	static size_t _heapsize;//��������
	union Obj
	{
		Obj* _freeListLink;
		char client_data[1];    /* The client sees this.*/
	};
	enum { __ALIGN = 8 };
	enum { __MAX_BYTES = 128 };
	enum { __NFREELISTS = __MAX_BYTES / __ALIGN };
	// ��������
	static Obj* _freelist[__NFREELISTS];

	static size_t Round_up(size_t bytes)//��bytes�ϵ���8�ı���
	{
		return (bytes + __ALIGN - 1) & ~(__ALIGN - 1);
	}
	static size_t FreeList_Index(size_t bytes)//��bytes������������±�
	{
		return (bytes + __ALIGN - 1) / __ALIGN - 1;
	}
	static void *Refill(size_t n)//���ռ�ҵ�_freelist�ĺ��ʵ�λ������
	{                      //ע��:����Ĳ���n�Ѿ���8�ı�����
		int nobjs = 20;
		char *chunk = Chunk_alloc(n, nobjs);

		Obj **my_free_list;
		Obj *result, *cur_obj, *next_obj;

		if (nobjs == 1)return chunk;//ֻ���ڴ�����뵽һ��С�ڴ�����

		my_free_list = _freelist + FreeList_Index(n);//Ѱ�ҵ�_freelist���ʵ���һ��
		result = (Obj*)chunk;//���뵽�ĵ�һ��ռ䷵�ظ��ϲ㺯��

		*my_free_list = cur_obj = (Obj*)(chunk + n);
		for (size_t i = 1; i < nobjs - 1; ++i)//Ȼ��ʣ�µĿռ��ҵ�_freelist�к���λ�õ�����
		{
			next_obj = (Obj*)((char*)cur_obj + n);
			cur_obj->_freeListLink = next_obj;
			cur_obj = next_obj;
		}cur_obj->_freeListLink = NULL;

		return result;
	}
	static char *Chunk_alloc(size_t size, int &nobjs)//���ڴ��������ռ�
	{
		char *result;
		size_t total_bytes = size * nobjs;
		size_t left_bytes = _endfree - _startfree;

		if (left_bytes >= total_bytes)//�ڴ��ӵ���㹻��Ŀռ�
		{
			result = _startfree;
			_startfree += total_bytes;
			return result;
		}
		else if (left_bytes >= size)//�ڴ��û���㹻��Ŀռ�ȥ���䣬��������һ������ռ�Ĵ�С
		{
			nobjs = left_bytes / size;
			total_bytes = size * nobjs;
			result = _startfree;
			_startfree += total_bytes;
			return result;
		}
		else//�ڴ����һ������ռ䶼�ò�����
		{
			//1.���ڴ���е�ʣ���С�ռ�ҵ�_freelist�ĺ��ʵ�λ����
			if (left_bytes > 0)
			{
				Obj **my_free_list = _freelist + FreeList_Index(left_bytes);
				((Obj*)_startfree)->_freeListLink = *my_free_list;
				*my_free_list = (Obj*)_startfree;
			}
			//2.���ڴ����������ڴ�ռ�
			size_t bytes_to_get = 2 * total_bytes + Round_up(_heapsize >> 4);
			_startfree = (char*)malloc(bytes_to_get);
			if (_startfree == 0)//��malloc����ռ�ʧ��ʱ�����ǲ����Կ��ٱ�bytes_to_getСһ��Ŀռ䣬
			{
				// 1�����ſ�����������_freelist���Ƿ���пռ�����Ŀռ�
				Obj **my_free_list, *p;
				int i = FreeList_Index(size);//��size��С�Ŀռ�����Ӧ��_freelist���±�λ��
				for (; i <= __NFREELISTS; ++i)
				{
					my_free_list = _freelist + i;
					p = *my_free_list;

					if (p != NULL)
					{
						*my_free_list = p->_freeListLink;
						_startfree = (char*)p;
						_endfree = _startfree + __ALIGN * i + __ALIGN;

						return Chunk_alloc(size, nobjs);//���µ����Լ������·���ռ�
					}
				}
				// 2������_freelist��ʵ��û�п��ÿռ��ˣ���ô��ֻ������һ���ռ���������
				_endfree = NULL;//�����쳣֮�����ִ�иó�����Ϊ:�������쳣�ˣ�_startfree=0,_endfree��֪��ָ���ڴ���ĸ�λ�ã���ô�ͻ���ɷ��ʲ������Լ��Ŀռ�������
				_startfree = (char*)__MallocAllocTemplate<0>::Allocate(bytes_to_get);//ͨ������£�ִ�е�����������쳣
			}
			_heapsize += bytes_to_get;//���ߵ��⣬˵����malloc����ռ�ɹ��ˣ���ʱ�ڴ���кܶ�ռ���
			_endfree = _startfree + bytes_to_get;

			return Chunk_alloc(size, nobjs);//���µ����Լ������·���ռ�
		}
	}
public:
	static void *Allocate(size_t n)//����ռ�
	{
		if (n > __MAX_BYTES)
		{//������Ŀռ����128,ֱ��ȥ����һ���ռ�������
			return __MallocAllocTemplate<0>::Allocate(n);
		}

		Obj **my_free_list = _freelist;
		Obj *result;
		my_free_list = _freelist + FreeList_Index(n);//Ѱ�ҵ�_freelist���ʵ���һ��
		result = *my_free_list;

		if (result == 0)//_freelist����û�ҿռ�����
		{
			void *r = Refill(Round_up(n));//�ܹ���Refill�Ĳ�����8�ı���
			return r;
		}

		*my_free_list = result->_freeListLink;//_freelist������˿ռ�����
		return result;
	}
	static void Deallocate(void *p, size_t n)
	{
		if (n > __MAX_BYTES)
		{
			__MallocAllocTemplate<0>::Deallocate(p, n);
			return;
		}

		//����Ѱ�Ҷ�Ӧ��_freelist���±�λ�ã����ÿ�ռ������
		size_t index = FreeList_Index(n);

		Obj* obj = (Obj*)p;
		obj->_freeListLink = _freelist[index];
		_freelist[index] = obj;
	}
};
//��̬��Ա���������������ʼ��
template <bool threads, int inst> 
char* __DefaultAllocTemplate<threads,inst>::_startfree = NULL;
template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::_endfree = NULL;
template <bool threads, int inst>
size_t __DefaultAllocTemplate<threads, inst>::_heapsize = 0;
template <bool threads, int inst>
typename __DefaultAllocTemplate<threads, inst>::Obj* __DefaultAllocTemplate<threads, inst>::_freelist[__NFREELISTS] = { 0 };
 
//��������
#ifdef __USE_MALLOC
typedef __MallocAllocTemplate<0> alloc5;
#else
typedef __DefaultAllocTemplate<0, 0> alloc5;
#endif
//ͳһ�ռ��������Ľӿڣ�Ȼ��¶������
template<class T, class Alloc = alloc5>
class SimpleAlloc {
public:
	static T* Allocate(size_t n = 1)
	{
		return 0 == n ? 0 : (T*)Alloc::Allocate(n * sizeof (T));
	}
	static void Deallocate(T *p, size_t n = 1)
	{
		if (0 != n)
			Alloc::Deallocate(p, n * sizeof (T));
	}
};

void test_alloc()
{
	////int *p = (int*)__DefaultAllocTemplate<1, 1>::Allocate(4);
	//string *p = SimpleAlloc<string>::Allocate(5);
	////Construct(p, "abc");
	//uninitialized_fill_n(p, 5, "abc");
	//cout << " " << endl;
	//cout << p->c_str() << endl;

	//string p = new char[5];
	//cout << p[0] << endl;
	//string *p = new string[5];                     //��֧��,
	////string p[5];
	//p[0] = "abc";
	//cout << p->c_str() << endl;    //ֻ�ܷ��ʵ���һ���ռ䣬�����ĸ����ʲ����������
	//Uninitialized_fill_n(p, 5, "abc");
	//for (size_t i = 0; i < 5; ++i)
	//	cout << p->at(i) << endl;

	//int *p = new int[5];
	////Uninitialized_fill(p, p + 5, 2);
	//for (size_t i = 0; i < 5; ++i)
	//	cout << p[i] << endl;
}


//void Test_MallocAllocTemplate()//test
//{
//	//int* p1 = (int*)__MallocAllocTemplate<0>::Allocate(0x7fffffff);
//	int* p1 = (int*)__MallocAllocTemplate<0>::Allocate(0x7f);
//	//__MallocAllocTemplate<0>::Deallocate(p1, 4);
//}
//void test_DefaultAllocTemplate()//test
//{
//	__DefaultAllocTemplate<1, 1>::Allocate(4);
//}
