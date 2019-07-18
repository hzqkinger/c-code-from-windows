#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<CoreWindow.h>


//#include"Alloc.h"//1.空间配置器头文件                     1.写好了                
//#include"TraceLog.h"2.
////序列式容器
#include"Vector.h"//3.vector头文件                          3.写好了
//#include"List.h"//4.list头文件                              4.写好了
////////适配器容器
//#include"Stack.h"//5.stack头文件                            5.写好了
//#include"Queue.h"//6.queue头文件                            6.写好了
//#include"Priority_Queue.h"//7.priority_queue头文件          7.写好了
////////关联式容器
//#include"Map.h"//8.map头文件                                8.写好了
//#include"Set.h"//9.set头文件                                9.写好了
//#include"UnorderMap.h"//10.unorder_map头文件
//#include"UnorderSet.h"//11.unorder_set头文件

//问题一：都没写这些容器的①拷贝构造函数和②赋值运算符重载函数（现在不想写）

//问题零：注意，我自己在实现STL时，抛弃了①类型萃取和②99%的抛异常机制（因为有点难，不想写）
//问题二：全部死在string上，只要遇到string类型，就会出错         已经解决了

//问题三：vector反向迭代器的++，--，+=,-=怎么实现，无法适配呀     已经解决了
//问题四：由于我写的红黑树是不带头结点的，所以无法适配出反向迭代器
//问题五：由于HashTable使用了vector做桶子，所以也没办法写反向迭代器


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
	////AA *pa = arr;             //可以直接向后加啊
	////pa += 2;
	////cout << pa->_i << endl;

	//string arr[4] = { string(), string("11"), string("22"), string("33") };
	//string *pa = arr;             //可以直接向后加啊
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
	test_vector2();       //vector已经改好了，可以装所有类型
	//test_list();
	//test_list2();           //list已经改好了，可以装所有类型
	//test_queue2();            //所以下面三个适配器就改好了
	//test_stack2();
	//test_priority_queue2();

	//test_RBTree();       //RBTree已经改好了，可以装所有类型
	//test_map();          //所以map,set也就改好了
	//test_set();

	//test_HashTable();      //HashTable已经改好了，可以装所有类型
	//test_HashTable2();     
	//test_unorder_map();    //所以unorder_map,unorderset也就改好了
	//test_unorder_set();

	system("pause");
	return 0;
}