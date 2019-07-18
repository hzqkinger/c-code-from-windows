#pragma once

#include<string>
#include<vector>
#include<algorithm>
#include<queue>

struct rr_pro
{
	string _name;//程序名
	int _intime;//提交时间
	int _server;//服务时间

	//（因为时间片轮转调度会改变_intime，为了好打印原本数据，在这添加_intimetmp）
	int _intimetmp;//提交时间的副本
	int _servertmp;//服务时间的副本，同理

	int _finish;//完成时间
	int _zztime;//周转时间
};

bool rr_comp(const rr_pro& left, const rr_pro& right)//定义仿函数，使所有程序按照提交时间排序
{
	return left._intime < right._intime;
}

void rr_print(const vector<rr_pro> &v)//打印结果
{
	printf("程序名 进入时间 服务时间 完成时间 周转时间\n");
	auto it = v.begin();
	while (it != v.end())
	{
		cout << it->_name << "	" << it->_intimetmp << "	 " << it->_servertmp << "	 " \
			<< it->_finish << "	 " << it->_zztime << "	  " << endl;
		++it;
	}
}

void test_rr()
{
	printf("请分别输入一共几个程序，程序运行的时间片\n");
	int N = 0,Q = 0;
	cin >> N >> Q;

	vector<rr_pro> arr(N);//题目会告诉我们有哪些程序，然后我们先装入数组
	for (int i = 0; i < N; ++i)
	{
		printf("请分别输入程序名，程提交时间，服务时间\n");
		cin >> arr[i]._name >> arr[i]._intime >> arr[i]._server;

		arr[i]._intimetmp = arr[i]._intime;
		arr[i]._servertmp = arr[i]._server;
	}
	auto begin = arr.begin();
	auto end = arr.end();
	sort(begin, end, rr_comp);//按照程序提交时间排序

	int times = 0;
	while (begin != arr.end())
	{
		if (begin->_server <= Q)//程序在时间片中就执行完了
		{
			if (times < begin->_intime)
				times = begin->_intime + begin->_server;
			else
				times += begin->_server;

			begin->_finish = times;
			begin->_zztime = begin->_finish - begin->_intimetmp;

			++begin;
		}
		else
		{
			begin->_server -= Q;
			times += Q;
			begin->_intime = times;

		}

		auto eend = begin;//这个while循环的作用：当处理begin指向的程序时，计算有哪些程序也已经提交进来
		while (eend != end && eend->_intime <= times)++eend;

		if (eend != begin)
		{
			--eend;
			swap(*begin, *eend);
			++eend;
		}

		if (begin != arr.end())
			sort(begin, eend, rr_comp);//把已经提交进来的程序按照 提交时间时间排序
	}

	rr_print(arr);
}