#pragma once

#include "TraceLog.h"

typedef void(*HANDLE_FUNC) ();

template <int inst> // instance
class __MallocAllocTemplate
{
	static HANDLE_FUNC __malloc_alloc_oom_handler;

public:
	static void* OOM_Malloc(size_t n)
	{
		while (1)
		{
			if (__malloc_alloc_oom_handler == NULL)
			{
				throw bad_alloc();
			}

			__malloc_alloc_oom_handler(); // 释放内存

			void* ret = malloc(n);
			if (ret)
			{
				return ret;
			}
		}
	}

	static void* Allocate(size_t n)
	{
		void *result = malloc(n);
		if (0 == result)
			result = OOM_Malloc(n);

		return result;
	}

	static void Deallocate(void *p, size_t /* n */)
	{
		free(p);
	}

	static HANDLE_FUNC SetMallocHandler(HANDLE_FUNC f)
	{
		HANDLE_FUNC old = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return old;
	}
};

template<int inst>
HANDLE_FUNC __MallocAllocTemplate<inst>::__malloc_alloc_oom_handler = NULL;

void TestMallocAllocTemplate()
{
	int* p1 = (int*)__MallocAllocTemplate<0>::Allocate(0x7fffffff);
	//__MallocAllocTemplate<0>::Deallocate(p1, 4);
}

//////////////////////////////////////////////////////////
// 二级空间配置器
template <bool threads, int inst>
class __DefaultAllocTemplate
{
private:
	union Obj
	{
		Obj* _freeListLink;
		char client_data[1];    /* The client sees this.        */
	};

	enum { __ALIGN = 8 };
	enum { __MAX_BYTES = 128 };
	enum { __NFREELISTS = __MAX_BYTES / __ALIGN };


	// 内存池
	static char* _startFree;
	static char* _endFree;
	static size_t _heapsize;

	// 自由链表
	static Obj* _freeList[__NFREELISTS];
public:
	// 65-72->8
	static size_t FREELIST_INDEX(size_t n)
	{
		return (((n)+__ALIGN - 1) / __ALIGN - 1);
	}

	// 65-72-> 72-79
	static size_t ROUND_UP(size_t n)
	{
		return ((n + __ALIGN - 1) & ~(__ALIGN - 1));
	}

	static char* ChunkAlloc(size_t bytes, size_t& nobjs)
	{
		size_t totalBytes = bytes*nobjs;
		size_t leftBytes = _endFree - _startFree;
		__TRACE_DEBUG("内存缓冲池剩余%ubytes, 需要%ubytes\n", leftBytes, totalBytes);


		if (totalBytes <= leftBytes)
		{
			char* chunk = _startFree;
			_startFree += totalBytes;

			return chunk;
		}
		else if (leftBytes >= bytes)
		{
			nobjs = leftBytes / bytes;
			totalBytes = nobjs*bytes;

			char* chunk = _startFree;
			_startFree += totalBytes;
			return chunk;
		}
		else
		{
			// 1.尝试挂起剩余的小片内存
			if (leftBytes > 0)
			{
				size_t index = FREELIST_INDEX(leftBytes);

				__TRACE_DEBUG("将剩余的%ubytes内存块对象挂到freelist[%u]下面\n", leftBytes, index);

				((Obj*)_startFree)->_freeListLink = _freeList[index];
				_freeList[index] = (Obj*)_startFree;
			}

			// 2.找系统申请空间
			size_t bytesToGet = totalBytes * 2 + (ROUND_UP(_heapsize >> 4));
			_startFree = (char*)malloc(bytesToGet);
			if (_startFree == NULL)
			{
				__TRACE_DEBUG("向系统申请%ubyets内存失败\n", bytesToGet);


				// 到更大的自由链表中找内存块
				for (size_t i = FREELIST_INDEX(bytes); i < __NFREELISTS; ++i)
				{
					if (_freeList[i])
					{
						_startFree = (char*)_freeList[i];
						_freeList[i] = ((Obj*)_startFree)->_freeListLink;
						_endFree = _startFree + (i + 1)*__ALIGN;

						return ChunkAlloc(bytes, nobjs);
					}
				}

				// 最后一根救命稻草
				_endFree = 0;
				_startFree = (char*)__MallocAllocTemplate<0>::Allocate(bytesToGet);
			}

			__TRACE_DEBUG("向系统申请%ubyets成功，再次ChunkAlloc\n", bytesToGet);

			_heapsize += bytesToGet;
			_endFree = _startFree + bytesToGet;
			return ChunkAlloc(bytes, nobjs);
		}
	}

	static void* Refill(size_t bytes)
	{
		size_t nobjs = 20;
		char* chunk = ChunkAlloc(bytes, nobjs);

		size_t index = FREELIST_INDEX(bytes);
		__TRACE_DEBUG("从内存缓冲池获取到%u个%ubytes内存对象, 返回1个，挂起%u个到freelist[%u]\n", nobjs, bytes, nobjs - 1, index);

		if (nobjs == 1)
		{
			return chunk;
		}

		// 返回1块，挂nobjs-1块
		Obj* cur = (Obj*)(chunk + bytes);
		//size_t index = FREELIST_INDEX(bytes);
		_freeList[index] = cur;
		for (size_t i = 1; i < nobjs - 1; ++i)
		{
			Obj* next = (Obj*)((char*)cur + bytes);
			cur->_freeListLink = next;
			cur = next;
		}

		cur->_freeListLink = NULL;

		return chunk;
	}

	static void* Allocate(size_t n)
	{
		__TRACE_DEBUG("二级空间配置器申请:%u bytes\n", n);

		if (n > __MAX_BYTES)
		{
			return __MallocAllocTemplate<0>::Allocate(n);
		}

		size_t index = FREELIST_INDEX(n);
		if (_freeList[index])
		{
			__TRACE_DEBUG("到freelist[%u]取了一个%ubytes内存块\n", index, (index + 1)*__ALIGN);

			Obj* ret = _freeList[index];
			_freeList[index] = ret->_freeListLink;
			return ret;
		}
		else
		{
			__TRACE_DEBUG("自由freelist[%u]下面没有内存块，到内存缓冲池去获取\n", index);
			return Refill(ROUND_UP(n));
		}
	}

	static void Deallocate(void* p, size_t n)
	{
		if (n > __MAX_BYTES)
		{
			__MallocAllocTemplate<0>::Deallocate(p, n);
			return;
		}

		size_t index = FREELIST_INDEX(n);
		__TRACE_DEBUG("释放内存块对象0x%p，挂到freelist[%u]下面\n", p, index);

		Obj* obj = (Obj*)p;
		obj->_freeListLink = _freeList[index];
		_freeList[index] = obj;
	}
};


// 内存池
template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::_startFree = 0;

template <bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::_endFree = 0;

template <bool threads, int inst>
size_t __DefaultAllocTemplate<threads, inst>::_heapsize = 0;

// 自由链表
template <bool threads, int inst>
typename __DefaultAllocTemplate<threads, inst>::Obj*
__DefaultAllocTemplate<threads, inst>::_freeList[__NFREELISTS] = { 0 };

#include <Windows.h>

#include <vector>

void TestAlloc()
{
	vector<void*> v;
	v.reserve(20);
	const size_t N = 1000000;
	int begin = GetTickCount();
	for (size_t k = 0; k < N; ++k)
	{
		for (size_t i = 0; i < 20; ++i)
		{
			//v.push_back(__DefaultAllocTemplate<0, 0>::Allocate(30));
			__DefaultAllocTemplate<0, 0>::Allocate(30);
		}

		/*	for (size_t i = 0; i < 20; ++i)
		{
		__DefaultAllocTemplate<0,0>::Deallocate(v[i], 30);
		}	*/
		//v.clear();
	}

	int end = GetTickCount();
	cout << end - begin << endl;

	begin = GetTickCount();
	for (size_t k = 0; k < N; ++k)
	{
		for (size_t i = 0; i < 20; ++i)
		{
			//v.push_back(malloc(30));
			malloc(30);
		}

		/*for (size_t i = 0; i < 20; ++i)
		{
		free(v[i]);
		}	*/
		//v.clear();
	}

	end = GetTickCount();
	cout << end - begin << endl;
}

void TestAllocOP()
{
	__DefaultAllocTemplate<0, 0>::Allocate(1024 * 1024 * 1024);

	for (size_t i = 0; i < 1024 * 1024 * 10; ++i)
	{
		__DefaultAllocTemplate<0, 0>::Allocate(80);
	}
}

#ifdef __USE_MALLOC
typedef __MallocAllocTemplate<0> alloc;
#else
typedef __DefaultAllocTemplate<0, 0> alloc;
#endif


template<class T, class Alloc>
class SimpleAlloc {
public:
	static T* Allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::Allocate(n * sizeof (T));
	}

	static T* Allocate(void)
	{
		return (T*)Alloc::Allocate(sizeof (T));
	}

	static void Deallocate(T *p, size_t n)
	{
		if (0 != n)
			Alloc::Deallocate(p, n * sizeof (T));
	}

	static void Deallocate(T *p)
	{
		Alloc::Deallocate(p, sizeof (T));
	}
};


//#include <Windows.h>
//
//void FreeMemory()
//{
//	cout<<"尝试释放内存"<<endl;
//
//	Sleep(1000);
//}
//
//int main()
//{
//	try
//	{
//		__MallocAllocTemplate<0>::SetMallocHandler(FreeMemory);
//
//		TestMallocAllocTemplate();
//	}
//	catch(exception& e)
//	{
//		cout<<e.what()<<endl;
//	}
//
//	return 0;
//}