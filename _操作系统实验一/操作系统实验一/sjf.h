#pragma once


#include<string>
#include<vector>
#include<algorithm>

struct pro
{
	string _name;//程序名
	int _intime;//提交时间
	int _server;//服务时间

	int _finish;//完成时间
	int _zztime;//周转时间
};

bool comp(const pro& left, const pro& right)//定义仿函数，使所有程序按照提交时间排序
{
	return left._intime < right._intime;
}
bool comp2(const pro& left, const pro& right)//定义仿函数，使所有程序按照服务时间排序
{
	return left._server < right._server;
}

void print(const vector<pro> &v)//打印结果
{
	printf("程序名 进入时间 服务时间 完成时间 周转时间\n");
	auto it = v.begin();
	while (it != v.end())
	{
		cout << it->_name << "	" << it->_intime << "	 " << it->_server << "	 " \
			<< it->_finish << "	 " << it->_zztime << "	  " << endl;
		++it;
	}
}
void test_sjf()
{
	cout << "请输入一共几个程序：" << endl;
	int N = 0;
	cin >> N;

	vector<pro> arr(N);//题目会告诉我们有哪些程序，然后我们先装入数组
	for (int i = 0; i < N; ++i)
	{
		printf("请分别输入程序名，程提交时间，服务时间\n");
		cin >> arr[i]._name;
		cin >> arr[i]._intime;
		cin >> arr[i]._server;

		arr[i]._finish = 0;
		arr[i]._zztime = 0;
	}
	auto begin = arr.begin();
	auto end = arr.end();
	sort(begin, end, comp);//先按照程序的提交时间排序


	int times = 0;//定义且初始化时间轴
	while (begin != arr.end())
	{
		if (times < begin->_intime)//更新时间轴
			times = begin->_intime + begin->_server;
		else
			times += begin->_server;

		begin->_finish += times;//处理begin迭代器所指向的那个程序
		begin->_zztime = begin->_finish - begin->_intime;

		auto eend = ++begin;//这个while循环的作用：当处理begin指向的程序时，计算有哪些程序也已经提交进来
		while (eend != end && eend->_intime < times)++eend;

		if (begin != arr.end())
			sort(begin, eend, comp2);//把已经提交进来的程序按照 服务时间排序
	}

	print(arr);//调用打印结果函数，打印出arr数组
}

