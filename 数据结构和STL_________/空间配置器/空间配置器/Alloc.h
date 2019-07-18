#pragma once

/////////////////////////////下面五个函数只做调用构造函数来初始化的工作////////////////////////////////////
#include<new.h> //欲使用placement new,需先包含此文件
//5个全局函数（construct(),destroy(),uninitialized_copy(),uninitialized_fill(),uninitialized_fill_n()）
template<class T1,class T2>
inline void Construct(T1 *p, const T2& value)
{
	new(p)T1(value);//placement new  调用构造函数
}
template<class T>inline void Destory(T *pointer)//第一个版本，接受一个指针
{
	pointer->~T();//  调用析构函数
}
template<class ForwardIterator>
inline void Destory(ForwardIterator first, ForwardIterator last)//第二个版本，接受两个迭代器
{
	for (; first < last; ++first)
		Destory(&*first);//  调用析构函数
}

template<class InputIterator,class ForwardIterator>
ForwardIterator Uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator result)
{
	ForwardIterator cur = result;
	for (; first != last; ++first, ++cur)
		Construct(&*cur, *first);//调用构造函数
	return cur;
}
template<class ForwardIterator,class T>
void Uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& x)
{
	for (ForwardIterator cur = first; cur != last; ++cur)
		Construct(&*cur, x);//调用构造函数
}
template<class ForwardIterator,class Size,class T>
ForwardIterator Uninitialized_fill_n(ForwardIterator first, Size n, T& x)
{
	ForwardIterator cur = first;
	for (; n > 0; --n, ++cur)
		Construct(&*cur, x);//调用构造函数
	return cur;
}

////////////////////////////下面两个空间配置器只做分配空间的工作///////////////////////////////////////////
//（1）当需要申请的空间大于128时，则视为需申请足够大的空间，直接调用一级空间配置器
//一级空间配置器：①其实就是：Allocate()对malloc()的封装，Deallocate()对free()的封装
//                ②模拟C++的set_new_handler()以处理内存不足的状况
typedef void(*HANDLE_FUNC) ();
template <int inst> // instance
class __MallocAllocTemplate
{
	static HANDLE_FUNC __malloc_alloc_oom_handler;//句柄函数指针通常都是NULL,除非你自己设置(不建议自己设置非空，因为功力不够)
	static void* OOM_Malloc(size_t n)//由于句柄函数指针通常都是NULL，所以进到该函数基本会抛异常
	{
		while (1)
		{
			if (__malloc_alloc_oom_handler == NULL)
			{
				throw bad_alloc();
			}
			//能执行到下面的语句，说明句柄函数指针被重新设置了
			__malloc_alloc_oom_handler(); // 释放内存

			void* ret = malloc(n);
			if (ret)
				return ret;
		}
	}
public:
	static void* Allocate(size_t n)//包装malloc()
	{
		void *result = malloc(n);//malloc returns a void pointer to the allocated space, or NULL if there is insufficient memory available.
	
		if (NULL == result)//如果内存不足，则调用OOM_Malloc函数来尝试分配空间
			result = OOM_Malloc(n);

		return result;
	}
	static void Deallocate(void *p, size_t /* n */)//包装free()
	{
		free(p);
	}
	static HANDLE_FUNC SetMallocHandler(HANDLE_FUNC f)//设置句柄函数指针
	{
		HANDLE_FUNC old = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return old;
	}
};
template<int inst>
HANDLE_FUNC __MallocAllocTemplate<inst>::__malloc_alloc_oom_handler = NULL;//句柄函数指针的初始化

//（2）当需要申请的空间小于等于128时，则视为需申请足够小的空间，调用二级空间配置器
// 二级空间配置器：管理内存池和一个自由链表
template <bool threads, int inst>
class __DefaultAllocTemplate
{
private:
	// 内存池
	static char* _startfree;
	static char* _endfree;
	static size_t _heapsize;//反馈因子
	union Obj
	{
		Obj* _freeListLink;
		char client_data[1];    /* The client sees this.*/
	};
	enum { __ALIGN = 8 };
	enum { __MAX_BYTES = 128 };
	enum { __NFREELISTS = __MAX_BYTES / __ALIGN };
	// 自由链表
	static Obj* _freelist[__NFREELISTS];

	static size_t Round_up(size_t bytes)//将bytes上调到8的倍数
	{
		return (bytes + __ALIGN - 1) & ~(__ALIGN - 1);
	}
	static size_t FreeList_Index(size_t bytes)//求bytes在自由链表的下标
	{
		return (bytes + __ALIGN - 1) / __ALIGN - 1;
	}
	static void *Refill(size_t n)//将空间挂到_freelist的合适的位置下面
	{                      //注意:这里的参数n已经是8的倍数了
		int nobjs = 20;
		char *chunk = Chunk_alloc(n, nobjs);

		Obj **my_free_list;
		Obj *result, *cur_obj, *next_obj;

		if (nobjs == 1)return chunk;//只向内存池申请到一块小内存的情况

		my_free_list = _freelist + FreeList_Index(n);//寻找到_freelist中适当的一个
		result = (Obj*)chunk;//申请到的第一块空间返回给上层函数

		*my_free_list = cur_obj = (Obj*)(chunk + n);
		for (size_t i = 1; i < nobjs - 1; ++i)//然后将剩下的空间块挂到_freelist中合适位置的下面
		{
			next_obj = (Obj*)((char*)cur_obj + n);
			cur_obj->_freeListLink = next_obj;
			cur_obj = next_obj;
		}cur_obj->_freeListLink = NULL;

		return result;
	}
	static char *Chunk_alloc(size_t size, int &nobjs)//从内存池中申请空间
	{
		char *result;
		size_t total_bytes = size * nobjs;
		size_t left_bytes = _endfree - _startfree;

		if (left_bytes >= total_bytes)//内存池拥有足够大的空间
		{
			result = _startfree;
			_startfree += total_bytes;
			return result;
		}
		else if (left_bytes >= size)//内存池没有足够大的空间去分配，但有至少一个所需空间的大小
		{
			nobjs = left_bytes / size;
			total_bytes = size * nobjs;
			result = _startfree;
			_startfree += total_bytes;
			return result;
		}
		else//内存池连一个所需空间都拿不出来
		{
			//1.让内存池中的剩余的小空间挂到_freelist的合适的位置下
			if (left_bytes > 0)
			{
				Obj **my_free_list = _freelist + FreeList_Index(left_bytes);
				((Obj*)_startfree)->_freeListLink = *my_free_list;
				*my_free_list = (Obj*)_startfree;
			}
			//2.向内存申请更多的内存空间
			size_t bytes_to_get = 2 * total_bytes + Round_up(_heapsize >> 4);
			_startfree = (char*)malloc(bytes_to_get);
			if (_startfree == 0)//用malloc申请空间失败时，我们不尝试开辟比bytes_to_get小一点的空间，
			{
				// 1）试着看看自由链表_freelist的是否挂有空间更大点的空间
				Obj **my_free_list, *p;
				int i = FreeList_Index(size);//求到size大小的空间所对应的_freelist的下标位置
				for (; i <= __NFREELISTS; ++i)
				{
					my_free_list = _freelist + i;
					p = *my_free_list;

					if (p != NULL)
					{
						*my_free_list = p->_freeListLink;
						_startfree = (char*)p;
						_endfree = _startfree + __ALIGN * i + __ALIGN;

						return Chunk_alloc(size, nobjs);//重新调用自己，重新分配空间
					}
				}
				// 2）假如_freelist中实在没有可用空间了，那么就只能求助一级空间配置器了
				_endfree = NULL;//防抛异常之后继续执行该程序（因为:假如抛异常了，_startfree=0,_endfree不知道指向内存的哪个位置，那么就会造成访问不属于自己的空间的情况）
				_startfree = (char*)__MallocAllocTemplate<0>::Allocate(bytes_to_get);//通常情况下，执行到这句代码会抛异常
			}
			_heapsize += bytes_to_get;//能走到这，说明用malloc申请空间成功了，此时内存池有很多空间了
			_endfree = _startfree + bytes_to_get;

			return Chunk_alloc(size, nobjs);//重新调用自己，重新分配空间
		}
	}
public:
	static void *Allocate(size_t n)//申请空间
	{
		if (n > __MAX_BYTES)
		{//当申请的空间大于128,直接去调用一级空间配置器
			return __MallocAllocTemplate<0>::Allocate(n);
		}

		Obj **my_free_list = _freelist;
		Obj *result;
		my_free_list = _freelist + FreeList_Index(n);//寻找到_freelist中适当的一个
		result = *my_free_list;

		if (result == 0)//_freelist下面没挂空间的情况
		{
			void *r = Refill(Round_up(n));//能够让Refill的参数是8的倍数
			return r;
		}

		*my_free_list = result->_freeListLink;//_freelist下面挂了空间的情况
		return result;
	}
	static void Deallocate(void *p, size_t n)
	{
		if (n > __MAX_BYTES)
		{
			__MallocAllocTemplate<0>::Deallocate(p, n);
			return;
		}

		//否则，寻找对应的_freelist的下标位置，将该块空间挂起来
		size_t index = FreeList_Index(n);

		Obj* obj = (Obj*)p;
		obj->_freeListLink = _freelist[index];
		_freelist[index] = obj;
	}
};
//静态成员变量必须在类外初始化
template <bool threads, int inst> 
char* __DefaultAllocTemplate<threads,inst>::_startfree = NULL;
template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::_endfree = NULL;
template <bool threads, int inst>
size_t __DefaultAllocTemplate<threads, inst>::_heapsize = 0;
template <bool threads, int inst>
typename __DefaultAllocTemplate<threads, inst>::Obj* __DefaultAllocTemplate<threads, inst>::_freelist[__NFREELISTS] = { 0 };
 
//条件编译
#ifdef __USE_MALLOC
typedef __MallocAllocTemplate<0> alloc5;
#else
typedef __DefaultAllocTemplate<0, 0> alloc5;
#endif
//统一空间配置器的接口，然后暴露给外面
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
	//string *p = new string[5];                     //不支持,
	////string p[5];
	//p[0] = "abc";
	//cout << p->c_str() << endl;    //只能访问到第一个空间，后面四个访问不到，很奇怪
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
