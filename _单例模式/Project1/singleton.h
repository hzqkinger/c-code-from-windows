#pragma once

//#define barrier() __asm__ volatile ("lwsync")
//在很早以前，CPU就发展处动态调度，在执行程序的时候为了提高效率有可能交换指令的顺序



//一.设计一个类，使它的对象只能在堆上。
//    ①将构造函数置为私有,拷贝构造函数置为delete的；
//    ②再提供一个静态方法，该方法在堆上创建对象
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly() {}
	//~HeapOnly() {}
	// 防拷贝
	HeapOnly(const HeapOnly&);
};

//二.设计一个类，使它的对象只能在栈上
// ①构造函数设置为公有
// ②屏蔽掉new/delete的功能
class StackOnly
{
public:
	StackOnly() {}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

//三.一个类只能创建一个对象，即单例模式，该模式可以保证系统中该类只有一个实例，并提供一个访问它的全
//    局访问点，该实例被所有程序模块共享。（单例模式分为饿汉模式和懒汉模式）

//a.饿汉模式：就是说不管你将来用不用，程序启动时就创建一个唯一的实例对象
//缺点：如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊， 初始化网络连接啊，读取文件啊等
//      等，而有可能该对象程序运行时不会用到，那么也要在程序一开始就进行初始化，就会导致程序启动时
//      非常的缓慢。 所以这种情况使用懒汉模式（延迟加载）更好
class Singleton1
{
public:
	static Singleton1* GetInstance()//再提供一个静态成员函数
	{
		return &m_instance;
	}
private:
	// 构造函数私有
	Singleton1(){};
	// 防拷贝
	Singleton1(Singleton1 const&);
	Singleton1& operator=(Singleton1 const&);

	static Singleton1 m_instance;//提供一个静态数据成员，
	//定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
};
Singleton1 Singleton1::m_instance; // 在程序入口之前就完成单例对象的初始化

//b.懒汉模式:只有当程序用到该类对象时，才去创建一个唯一的实例对象
#include<mutex>
class Singleton
{
public:
	//Singleton(){};
	/*Singleton(const Singleton& ss)
	{
		m_pInstance = new Singleton(ss);
	}*/
	static volatile Singleton* GetInstance() {
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
		if (nullptr == m_pInstance) {
			m_mtx.lock();
			if (nullptr == m_pInstance) {
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// 实现一个内嵌垃圾回收类
	class CGarbo {
	public:
		~CGarbo(){
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	//Singleton(){};
	~Singleton(){};
	// 防拷贝
	//Singleton(Singleton const&);
	//Singleton& operator=(Singleton const&);

	static volatile Singleton* m_pInstance; // 单例对象指针
	//volatile关键字的作用是防止编译器优化
	static mutex m_mtx; //互斥锁
};
volatile Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void test()
{
	//HeapOnly *s = HeapOnly::CreateObject();
	//StackOnly so;

	//Singleton::GetInstance();
	//volatile Singleton *ss = Singleton::GetInstance();
	//volatile Singleton s = *ss;
}