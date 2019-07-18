#pragma once

//#define barrier() __asm__ volatile ("lwsync")
//�ں�����ǰ��CPU�ͷ�չ����̬���ȣ���ִ�г����ʱ��Ϊ�����Ч���п��ܽ���ָ���˳��



//һ.���һ���࣬ʹ���Ķ���ֻ���ڶ��ϡ�
//    �ٽ����캯����Ϊ˽��,�������캯����Ϊdelete�ģ�
//    �����ṩһ����̬�������÷����ڶ��ϴ�������
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
	// ������
	HeapOnly(const HeapOnly&);
};

//��.���һ���࣬ʹ���Ķ���ֻ����ջ��
// �ٹ��캯������Ϊ����
// �����ε�new/delete�Ĺ���
class StackOnly
{
public:
	StackOnly() {}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};

//��.һ����ֻ�ܴ���һ�����󣬼�����ģʽ����ģʽ���Ա�֤ϵͳ�и���ֻ��һ��ʵ�������ṩһ����������ȫ
//    �ַ��ʵ㣬��ʵ�������г���ģ�鹲��������ģʽ��Ϊ����ģʽ������ģʽ��

//a.����ģʽ������˵�����㽫���ò��ã���������ʱ�ʹ���һ��Ψһ��ʵ������
//ȱ�㣺�������������ʮ�ֺ�ʱ����ռ�úܶ���Դ��������ز������ ��ʼ���������Ӱ�����ȡ�ļ�����
//      �ȣ����п��ܸö����������ʱ�����õ�����ôҲҪ�ڳ���һ��ʼ�ͽ��г�ʼ�����ͻᵼ�³�������ʱ
//      �ǳ��Ļ����� �����������ʹ������ģʽ���ӳټ��أ�����
class Singleton1
{
public:
	static Singleton1* GetInstance()//���ṩһ����̬��Ա����
	{
		return &m_instance;
	}
private:
	// ���캯��˽��
	Singleton1(){};
	// ������
	Singleton1(Singleton1 const&);
	Singleton1& operator=(Singleton1 const&);

	static Singleton1 m_instance;//�ṩһ����̬���ݳ�Ա��
	//����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
};
Singleton1 Singleton1::m_instance; // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��

//b.����ģʽ:ֻ�е������õ��������ʱ����ȥ����һ��Ψһ��ʵ������
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
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == m_pInstance) {
			m_mtx.lock();
			if (nullptr == m_pInstance) {
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// ʵ��һ����Ƕ����������
	class CGarbo {
	public:
		~CGarbo(){
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:
	// ���캯��˽��
	//Singleton(){};
	~Singleton(){};
	// ������
	//Singleton(Singleton const&);
	//Singleton& operator=(Singleton const&);

	static volatile Singleton* m_pInstance; // ��������ָ��
	//volatile�ؼ��ֵ������Ƿ�ֹ�������Ż�
	static mutex m_mtx; //������
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