#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>


//#include"Alloc.h"//1.�ռ�������ͷ�ļ�                     1.д����                
//#include"TraceLog.h"2.
////����ʽ����
#include"Vector.h"//3.vectorͷ�ļ�                          3.д����
//#include"List.h"//4.listͷ�ļ�                              4.д����
////////����������
//#include"Stack.h"//5.stackͷ�ļ�                            5.д����
//#include"Queue.h"//6.queueͷ�ļ�                            6.д����
//#include"Priority_Queue.h"//7.priority_queueͷ�ļ�          7.д����
////////����ʽ����
//#include"Map.h"//8.mapͷ�ļ�                                8.д����
//#include"Set.h"//9.setͷ�ļ�                                9.д����
//#include"UnorderMap.h"//10.unorder_mapͷ�ļ�
//#include"UnorderSet.h"//11.unorder_setͷ�ļ�

//����һ����ûд��Щ�����Ģٿ������캯���͢ڸ�ֵ��������غ��������ڲ���д��

//�����㣺ע�⣬���Լ���ʵ��STLʱ�������ˢ�������ȡ�͢�99%�����쳣���ƣ���Ϊ�е��ѣ�����д��
//�������ȫ������string�ϣ�ֻҪ����string���ͣ��ͻ����         �Ѿ������

//��������vector�����������++��--��+=,-=��ôʵ�֣��޷�����ѽ     �Ѿ������
//�����ģ�������д�ĺ�����ǲ���ͷ���ģ������޷���������������
//�����壺����HashTableʹ����vector��Ͱ�ӣ�����Ҳû�취д���������


class AA
{
public:
	int _i;
	AA(int i = 0)
		:_i(i)
	{}
};
#include<vector>
void test_Arr()
{
	//vector<AA> vs(4);
	//vector<AA>::iterator it = vs.begin();
	//it += 3;

	vector<string> vs(4);
	vector<string>::iterator it = vs.begin();
	it += 3;

	////AA arr[4] = { AA(), AA(1), AA(2), AA(3) };
	////AA *pa = arr;             //����ֱ�����Ӱ�
	////pa += 2;
	////cout << pa->_i << endl;

	//string arr[4] = { string(), string("11"), string("22"), string("33") };
	//string *pa = arr;             //����ֱ�����Ӱ�
	//pa += 2;
	//cout << pa->c_str() << endl;
}

template <class T>
class base
{
public:
	T _i;
	base(const T& val = T())
		:_i(val)
	{}
};
template<class T2>
class derived :public base<T2>
{

};
void test_base_deri()
{
	derived<int> d;
	d._i = 1;
	cout << d._i <<endl;
}

int main()
{
	//test_Arr();
	//test_base_deri();

	//Test_MallocAllocTemplate();
	//test_DefaultAllocTemplate();
	//test_alloc();

	//test_vector();
	test_vector2();       //vector�Ѿ��ĺ��ˣ�����װ��������
	//test_list();
	//test_list2();           //list�Ѿ��ĺ��ˣ�����װ��������
	//test_queue2();            //�������������������͸ĺ���
	//test_stack2();
	//test_priority_queue2();

	//test_RBTree();       //RBTree�Ѿ��ĺ��ˣ�����װ��������
	//test_map();          //����map,setҲ�͸ĺ���
	//test_set();

	//test_HashTable();      //HashTable�Ѿ��ĺ��ˣ�����װ��������
	//test_HashTable2();     
	//test_unorder_map();    //����unorder_map,unordersetҲ�͸ĺ���
	//test_unorder_set();

	system("pause");
	return 0;
}